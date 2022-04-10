#include "sophgo/Dialect/Tpu/IR/TpuOps.h"
#include "sophgo/Backend/BM168x/BM1684.h"
#include "sophgo/Support/Helper/Quant.h"
#include "sophgo/Support/Helper/Module.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Support/LLVM.h"

using namespace mlir;
using namespace sophgo;
using namespace sophgo::helper;
using namespace sophgo::backend;

void tpu::CastOp::codegen_int8_bm1684() {
  bool qInput = Quant::isUniformQuantized(input());
  bool qOutput = Quant::isUniformQuantized(output());
  int64_t n, c, h, w;
  Module::getNCHW(output(), n, c, h, w);
  if (qInput && !qOutput) {
    // int8 => fp32
    auto scale = Quant::getQuantizedType<quant::UniformQuantizedType>(input())
                     .getScale();
    BM1684::instance().dl_nodechip_global_int2float(
        Module::getAddress(input()), Module::getAddress(output()), n, c, h, w,
        1, STORAGE_MODE_4N_INT8, BM1684::instance().get_cmd_id_node());
    BM1684::instance().dl_nodechip_const_binary(
        Module::getAddress(output()), n * c * h * w, scale,
        Module::getAddress(output()), BM_BINARY_MUL, 0, 0, 0,
        BM1684::instance().get_cmd_id_node(), 0);
  } else if (qOutput && !qInput) {
    // fp32 => int8
    auto scale = Quant::getQuantizedType<quant::UniformQuantizedType>(output())
                     .getScale();
    BM1684::instance().dl_nodechip_const_binary(
        Module::getAddress(input()), n * c * h * w, scale,
        Module::getAddress(input()), BM_BINARY_DIV, 0, 0, 0,
        BM1684::instance().get_cmd_id_node(), 0);
    BM1684::instance().dl_nodechip_float2int8_v2(
        Module::getAddress(input()), Module::getAddress(output()), n, c, h, w,
        1, STORAGE_MODE_4N_INT8, ROUND_INF,
        BM1684::instance().get_cmd_id_node());
  } else {
    dump();
    llvm_unreachable("CastOp type error");
  }
}
