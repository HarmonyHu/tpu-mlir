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
#include "tpu_mlir/Support/Helper/Quant.h"
#include "tpu_mlir/Support/Helper/Module.h"

using namespace tpu_mlir;
using namespace tpu_mlir::helper;
using namespace mlir;

LogicalResult tpu::ReluOp::init(InferenceParameter &p) { return success(); }
void tpu::ReluOp::deinit(InferenceParameter &p) {}

LogicalResult tpu::ReluOp::inference(InferenceParameter &p) {
  relu(p.inputs[0], p.outputs[0], Module::getNumElements(output()),
       Module::getStorageType(output()));
  return success();
}
