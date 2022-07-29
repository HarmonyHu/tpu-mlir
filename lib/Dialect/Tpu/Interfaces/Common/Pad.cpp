//===----------------------------------------------------------------------===//
//
// Copyright (c) 2020-2030 by Sophgo Technologies Inc. All rights reserved.
//
// Licensed under the Apache License v2.0.
// See http://www.apache.org/licenses/LICENSE-2.0 for license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "tpu_mlir/Dialect/Tpu/IR/TpuOps.h"
#include "tpu_mlir/Support/Dnnl/Dnnl.h"
#include "tpu_mlir/Support/Helper/Module.h"
#include "tpu_mlir/Support/Helper/Quant.h"
#include "tpu_mlir/Support/MathUtils.h"

using namespace tpu_mlir;
using namespace tpu_mlir::helper;
using namespace mlir;

LogicalResult tpu::PadOp::init(InferenceParameter &p) { return success(); }
void tpu::PadOp::deinit(InferenceParameter &p) {}

LogicalResult tpu::PadOp::inference(InferenceParameter &p) {
  auto in_shape = Module::getShape(input());
  int64_t in = in_shape[0];
  int64_t ic = in_shape[1];
  int64_t ih = in_shape[2];
  int64_t iw = in_shape[3];
  std::shared_ptr<std::vector<int64_t>> pads_ = Module::getI64Array(paddings());
  int num_dims = in_shape.size();
  std::vector<int> pads;
  for (int i = 0; i < num_dims * 2; i++) {
    pads.emplace_back(pads_->at(i));
  }
  int64_t oc = pads[1] + pads[5] + ic;
  int64_t oh = pads[2] + pads[6] + ih;
  int64_t ow = pads[3] + pads[7] + iw;

  int32_t start_in = pads[0] < 0 ? -pads[0] : 0;
  int32_t start_ic = pads[1] < 0 ? -pads[1] : 0;
  int32_t start_ih = pads[2] < 0 ? -pads[2] : 0;
  int32_t start_iw = pads[3] < 0 ? -pads[3] : 0;

  int32_t end_in = pads[4] < 0 ? in + pads[4] : in;
  int32_t end_ic = pads[5] < 0 ? ic + pads[5] : ic;
  int32_t end_ih = pads[6] < 0 ? ih + pads[6] : ih;
  int32_t end_iw = pads[7] < 0 ? iw + pads[7] : iw;

  int32_t pad_n_begin_size = pads[0] < 0 ? 0 : pads[0] * oc * oh * ow;
  int32_t pad_c_begin_size = pads[1] < 0 ? 0 : pads[1] * oh * ow;
  int32_t pad_h_begin_size = pads[2] < 0 ? 0 : pads[2] * ow;
  int32_t pad_w_begin_size = pads[3] < 0 ? 0 : pads[3];

  const float *src = p.inputs[0];
  float *dst = p.outputs[0];

  for (int out_idx = 0, in_idx = start_in; in_idx < end_in;
       in_idx++, out_idx++) {
    auto in_offset = in_idx * ic * ih * iw;
    auto out_offset =
        pad_n_begin_size + pad_c_begin_size + out_idx * oc * oh * ow;
    for (int oc_idx = 0, ic_idx = start_ic; ic_idx < end_ic;
         ic_idx++, oc_idx++) {
      auto in_ic_offset = in_offset + ic_idx * ih * iw;
      auto out_oc_offset = out_offset + pad_h_begin_size + oc_idx * oh * ow;
      for (int oh_idx = 0, ih_idx = start_ih; ih_idx < end_ih;
           ih_idx++, oh_idx++) {
        auto in_ih_offset = in_ic_offset + ih_idx * iw;
        auto out_oh_offset = out_oc_offset + pad_w_begin_size + oh_idx * ow;
        memcpy(dst + out_oh_offset, src + in_ih_offset + start_iw,
               (end_iw - start_iw) * sizeof(float_t));
      }
    }
  }
  return success();
}
