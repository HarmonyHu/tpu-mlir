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

void tpu::ReshapeOp::codegen_int8_bm1684() {
  auto in_addr = Module::getAddress(input());
  auto out_addr = Module::getAddress(output());
  if (in_addr == out_addr) {
    return;
  }
  int64_t in, ic, ih, iw, on, oc, oh, ow;
  Module::getNCHW(input(), in, ic, ih, iw);
  Module::getNCHW(output(), on, oc, oh, ow);
  if (on != in) {
    llvm_unreachable("not support now");
  } else {
    int total_num = ALIGN(on, 4) * oc * oh * ow;
    BM1684::instance().dl_nodechip_global_memcpy_ex(
        in_addr, out_addr, 1, total_num, total_num, DTYPE_FP32, DTYPE_FP32,
        total_num, BM1684::instance().get_cmd_id_node());
  }
}
