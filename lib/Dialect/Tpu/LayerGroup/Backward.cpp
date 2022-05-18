#include "sophgo/Dialect/Tpu/IR/TpuOps.h"
#include "sophgo/Support/Dnnl/Dnnl.h"
#include "sophgo/Support/Helper/Quant.h"
#include "sophgo/Support/Helper/Module.h"

using namespace sophgo;
using namespace sophgo::helper;
using namespace mlir;

LogicalResult tpu::ConvOp::BackwardH(int64_t &in_idx, int64_t &in_slice,
                                     int64_t out_idx, int64_t out_slice) {
  int64_t n, ic, ih, iw, oc, oh, ow, g, kh, kw, ins_h, ins_w, sh, sw, pt, pb,
      pl, pr, dh, dw;
  bool is_dw, with_bias, do_relu;
  parseParam(n, ic, ih, iw, oc, oh, ow, g, kh, kw, ins_h, ins_w, sh, sw, pt, pb,
             pl, pr, dh, dw, is_dw, with_bias, do_relu);
  int kh_with_dh = (kh - 1) * dh + 1;
  in_slice = (out_slice - 1) * sh + (kh_with_dh >= sh ? kh_with_dh : sh);
  in_idx = out_idx * sh - pt;
  LayerGroupInterface::fixSlice(in_idx, in_slice, ih);
  return success();
}

LogicalResult tpu::AvgPoolOp::BackwardH(int64_t &in_idx, int64_t &in_slice,
                                        int64_t out_idx, int64_t out_slice) {
  int64_t n, c, ih, iw, oh, ow, kh, kw, sh, sw, pt, pb, pl, pr, pad_value;
  bool relu, is_global, count_include_pad;
  parseParam(n, c, ih, iw, oh, ow, kh, kw, sh, sw, pt, pb, pl, pr, pad_value,
             relu, is_global, count_include_pad);
  in_slice = (out_slice - 1) * sh + kh;
  in_idx = out_idx * sh - pt;
  LayerGroupInterface::fixSlice(in_idx, in_slice, ih);
  return success();
}

LogicalResult tpu::MaxPoolOp::BackwardH(int64_t &in_idx, int64_t &in_slice,
                                        int64_t out_idx, int64_t out_slice) {
  int64_t n, c, ih, iw, oh, ow, kh, kw, sh, sw, pt, pb, pl, pr, pad_value;
  bool relu, is_global, count_include_pad;
  parseParam(n, c, ih, iw, oh, ow, kh, kw, sh, sw, pt, pb, pl, pr, pad_value,
             relu, is_global, count_include_pad);
  in_slice = (out_slice - 1) * sh + kh;
  in_idx = out_idx * sh - pt;
  LayerGroupInterface::fixSlice(in_idx, in_slice, ih);
  return success();
}