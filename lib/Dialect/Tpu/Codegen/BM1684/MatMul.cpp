#include "sophgo/Dialect/Tpu/IR/TpuOps.h"
#include "sophgo/Backend/BM168x/BM1684.h"
#include "sophgo/Support/Helper/Quant.h"
#include "sophgo/Support/Helper/Module.h"

using namespace mlir;
using namespace sophgo;
using namespace sophgo::helper;
using namespace sophgo::backend;

typedef enum {
  FcPerLayerShift = 0,
  FcPerLayerScale = 1,
  FcPerChannelScale = 2,
} FcQScale;

typedef struct {
  float perlayer_scale;
  int if_asymmetic;
  int weight_offset;
  int output_offset;
  int if_bias_float;
} FcQParams;

void tpu::MatMulOp::codegen_global_int8_bm1684() {
  int64_t batch, M, K, N;
  bool with_bias, relu;
  parseParam(batch, M, K, N, with_bias, relu);
  int using_bias = with_bias ? 1 : 0;
  int if_relu = relu ? 1 : 0;
  int if_right_active = isa<top::WeightOp>(right().getDefiningOp()) ? 0 : 1;
  FcQParams quant_param{0, 0, 0, 0, 0};
  BM1684::instance().dl_nodechip_fc_fix8b_forward_parallel(
      Module::getAddress(input()), Module::getAddress(right()),
      with_bias ? Module::getAddress(bias()) : 0, Module::getAddress(output()),
      0, M, K, N, 0, using_bias, 1, 1, 1, rshift(), 0, if_relu, 1,
      if_right_active, 1, 0, FcPerLayerShift, &quant_param,
      (CMD_ID_NODE *)BM1684::instance().cmdid_node);
}

void tpu::MatMulOp::codegen_local_int8_bm1684(int64_t n_step, int64_t h_step) {
  llvm_unreachable("support later");
}
