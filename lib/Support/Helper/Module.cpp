#include "sophgo/Dialect/Top/IR/TopOps.h"
#include "sophgo/Support/Helper/Module.h"
#include "sophgo/Support/Helper/Quant.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/IR/TypeUtilities.h"
#include "mlir/Support/LLVM.h"
#include "float.h"
#include <map>
using namespace llvm;
using namespace mlir;
namespace sophgo {
namespace helper {
constexpr llvm::StringRef Module::Attr::NAME;
constexpr llvm::StringRef Module::Attr::STATE;
constexpr llvm::StringRef Module::Attr::CHIP;
constexpr llvm::StringRef Module::Attr::WEIGHT_FILE;
constexpr llvm::StringRef Module::Attr::COEFF_ADDR;
constexpr llvm::StringRef Module::Attr::COEFF_SIZE;
constexpr llvm::StringRef Module::Attr::NEURON_ADDR;
constexpr llvm::StringRef Module::Attr::NEURON_SIZE;

constexpr llvm::StringRef Module::State::TOP_F32;
constexpr llvm::StringRef Module::State::TOP_CALIBRATED;
constexpr llvm::StringRef Module::State::TOP_QUANTIZED;
constexpr llvm::StringRef Module::State::TPU_QUANTIZED;
constexpr llvm::StringRef Module::State::TPU_REORDERED;
constexpr llvm::StringRef Module::State::TPU_DIVIDED;
constexpr llvm::StringRef Module::State::TPU_ADDRESSED;

constexpr llvm::StringRef Module::Chip::ALL;
constexpr llvm::StringRef Module::Chip::BM1684;
constexpr llvm::StringRef Module::Chip::BM1686;

top::NoneOp Module::getNoneOp(Operation *op) {
  assert(op != nullptr);
  if (auto noneOp = dyn_cast<top::NoneOp>(op)) {
    return noneOp;
  }
  FuncOp funcOp;
  if (isa<mlir::FuncOp>(op)) {
    funcOp = cast<mlir::FuncOp>(op);
  } else {
    funcOp = cast<mlir::FuncOp>(op->getParentOp());
  }
  auto &block = funcOp.front();
  auto &topOp = block.front();
  if (auto noneOp = dyn_cast<top::NoneOp>(topOp)) {
    return noneOp;
  }
  auto ctx = op->getContext();
  auto builder = OpBuilder(ctx);
  builder.setInsertionPointToStart(&block);
  auto NoneOp =
      builder.create<top::NoneOp>(op->getLoc(), builder.getNoneType());
  return NoneOp;
}

ModuleOp Module::getModuleOp(Operation *op) {
  assert(op != nullptr);
  auto moduleOp = op->getParentOp();
  while (moduleOp && !isa<mlir::ModuleOp>(moduleOp)) {
    moduleOp = moduleOp->getParentOp();
  }
  if (!moduleOp) {
    op->dump();
    llvm_unreachable("can't get module op");
  }
  auto mOp = llvm::cast<ModuleOp>(moduleOp);
  return mOp;
}

void Module::updateModuleTypes(ModuleOp module) {
  auto ctx = module.getContext();
  Builder builder(ctx);
  // update callee func's return types
  for (auto func : module.getOps<FuncOp>()) {
    if (func.getName() == "main") {
      continue;
    }
    std::vector<mlir::Type> returns;
    Block &entryBlock = func.front();
    auto returnOp = dyn_cast<func::ReturnOp>(entryBlock.back()).getOperation();
    for (uint32_t i = 0; i < returnOp->getNumOperands(); ++i) {
      returns.push_back(returnOp->getOperand(i).getType());
    }
    auto fnType = builder.getFunctionType(func.getType().getInputs(),
                                          llvm::ArrayRef<mlir::Type>{returns});
    func.setType(fnType);
    auto callee = getCallOp(module, func);
    if (callee) {
      for (auto it : llvm::zip(callee.getResults(), returns)) {
        std::get<0>(it).setType(std::get<1>(it));
      }
    }
  }
  // update callee arg types
  for (auto func : module.getOps<FuncOp>()) {
    if (func.getName() == "main") {
      continue;
    }
    auto callee = getCallOp(module, func);
    if (!callee) {
      continue;
    }
    std::vector<mlir::Type> arguments;
    for (auto it :
         llvm::zip(callee.getOperandTypes(), func.front().getArguments())) {
      arguments.push_back(std::get<0>(it));
      std::get<1>(it).setType(std::get<0>(it));
    }
    auto fnType = builder.getFunctionType(llvm::ArrayRef<mlir::Type>(arguments),
                                          func.getResultTypes());
    func.setType(fnType);
  }
  // update main op return types
  auto mainFunc = getMainFuncOp(module);
  Block &entryBlock = mainFunc.front();
  auto returnOp = dyn_cast<func::ReturnOp>(entryBlock.back()).getOperation();
  std::vector<mlir::Type> returns;
  for (uint32_t i = 0; i < returnOp->getNumOperands(); ++i) {
    returns.push_back(returnOp->getOperand(i).getType());
  }
  auto fnType = builder.getFunctionType(mainFunc.getArgumentTypes(),
                                        llvm::ArrayRef<mlir::Type>{returns});
  mainFunc.setType(fnType);
}

std::string Module::genWeightFileName(ModuleOp module) {
  auto name = getName(module);
  auto state = getState(module);
  auto chip = getChip(module);
  std::string weight_file_name = name.lower() + std::string("_") +
                                 state.lower() + std::string("_") +
                                 chip.lower() + "_weight.npz";
  return weight_file_name;
}

int64_t Module::getAddress(Value v) {
  auto attr = v.getType().cast<RankedTensorType>().getEncoding();
  assert(attr.isa<IntegerAttr>());
  return attr.cast<IntegerAttr>().getInt();
}

void Module::setAddress(Value v, int64_t addr) {
  auto type = v.getType().cast<RankedTensorType>();
  Builder builder(v.getContext());
  auto addrAttr = builder.getI64IntegerAttr(addr);
  auto new_type =
      RankedTensorType::get(type.getShape(), type.getElementType(), addrAttr);
  v.setType(new_type);
}

size_t Module::getBytes(Value v) {
  auto type = v.getType().cast<RankedTensorType>();
  auto elm_count = type.getNumElements();
  auto etype = getStorageType(v);
  int elm_bytes = etype.getIntOrFloatBitWidth() / 8;
  return elm_count * elm_bytes;
}

llvm::ArrayRef<int64_t> Module::getShape(Value v) {
  auto type = v.getType().cast<RankedTensorType>();
  return type.getShape();
}

Type Module::getStorageType(Value v) {
  auto type = v.getType().cast<RankedTensorType>();
  auto etype = type.getElementType();
  if (auto qType = etype.dyn_cast<quant::CalibratedQuantizedType>()) {
    return qType.getExpressedType();
  } else if (auto qType = etype.dyn_cast<quant::UniformQuantizedType>()) {
    return qType.getStorageType();
  }
  return etype;
}

static void getNCHW_align_right(llvm::ArrayRef<int64_t> &shape, int64_t &n,
                                int64_t &c, int64_t &h, int64_t &w) {
  int num_dims = shape.size();
  n = 1, c = 1, h = 1, w = 1;
  if (num_dims > 0) {
    w = shape[num_dims - 1];
  }
  if (num_dims > 1) {
    h = shape[num_dims - 2];
  }
  if (num_dims > 2) {
    c = shape[num_dims - 3];
  }
  if (num_dims > 3) {
    n = shape[num_dims - 4];
  }
  for (int i = 4; i < num_dims; i++) {
    n *= shape[num_dims - i - 1];
  }
}

static void getNCHW_align_left(llvm::ArrayRef<int64_t> shape, int64_t &n,
                               int64_t &c, int64_t &h, int64_t &w) {
  int num_dims = shape.size();
  n = 1, c = 1, h = 1, w = 1;
  if (num_dims >= 4) {
    n = std::accumulate(shape.begin(), shape.begin() + num_dims - 3, 1,
                        std::multiplies<int64_t>());
    c = shape[num_dims - 3];
    h = shape[num_dims - 2];
    w = shape[num_dims - 1];
  } else if (num_dims == 3) {
    n = shape[num_dims - 3];
    c = shape[num_dims - 2];
    h = shape[num_dims - 1];
  } else if (num_dims == 2) {
    n = shape[num_dims - 2];
    c = shape[num_dims - 1];
  } else if (num_dims == 1) {
    n = shape[num_dims - 1];
  } else if (num_dims == 0) {
    // scalar
  } else {
    llvm_unreachable("unsupported shape size");
  }
}

void Module::getNCHW(Value v, int64_t &n, int64_t &c, int64_t &h, int64_t &w,
                     bool align_left) {
  auto shape = v.getType().cast<RankedTensorType>().getShape();
  if (align_left) {
    getNCHW_align_left(shape, n, c, h, w);
  } else {
    getNCHW_align_right(shape, n, c, h, w);
  }
}

FuncOp Module::getFuncOp(ModuleOp module, StringRef func_name) {
  for (auto func : module.getOps<FuncOp>()) {
    if (func.getName() == func_name) {
      return func;
    }
  }
  llvm::errs() << "Can't find FuncOp:" << func_name << "\n";
  llvm_unreachable("Error getFuncOp !!\n");
  return nullptr;
}

func::CallOp Module::getCallOp(ModuleOp module, FuncOp func) {
  auto mainFunc = getMainFuncOp(module);
  func::CallOp call = nullptr;
  mainFunc.walk([&](func::CallOp op) {
    if (!call && op.getCallee() == func.getName()) {
      call = op;
    }
  });
  return call;
}

void Module::getInputsOutputs(ModuleOp module, std::vector<Value> &inputs,
                              std::vector<Value> &outputs) {
  auto main_func = Module::getMainFuncOp(module);
  main_func.walk([&](top::InputOp op) { inputs.push_back(op.output()); });
  main_func.walk([&](func::ReturnOp op) {
    for (auto out : op.getOperands()) {
      auto result = out.cast<OpResult>();
      auto call_op = result.getDefiningOp<func::CallOp>();
      auto func_op = getFuncOp(module, call_op.getCallee());
      auto return_op = dyn_cast<func::ReturnOp>(func_op.front().back());
      assert(return_op);
      outputs.push_back(return_op.getOperand(result.getResultNumber()));
    }
  });
}

void Module::getInputsOutputs(func::CallOp call, std::vector<Value> &inputs,
                              std::vector<Value> &outputs) {
  auto module = getModuleOp(call);
  for (auto opd : call.getOperands()) {
    auto result = opd.cast<OpResult>();
    auto op = result.getDefiningOp();
    if (isa<top::InputOp>(op)) {
      inputs.push_back(opd);
    } else if (auto call_ = dyn_cast<func::CallOp>(op)) {
      auto func_op = getFuncOp(module, call_.getCallee());
      auto return_op = dyn_cast<func::ReturnOp>(func_op.front().back());
      assert(return_op);
      inputs.push_back(return_op.getOperand(result.getResultNumber()));
    } else {
      llvm_unreachable("input is illegal");
    }
  }
  auto func = getFuncOp(module, call.getCallee());
  func.walk([&](func::ReturnOp op) {
    for (auto output : op.getOperands()) {
      outputs.push_back(output);
    }
  });
}

} // namespace helper
} // namespace sophgo
