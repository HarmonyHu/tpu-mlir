#include "sophgo/Dialect/Top/IR/TopOps.h"
#include "sophgo/Interfaces/InferenceInterface.h"
#include "sophgo/Support/Dnnl/Dnnl.h"
#include "sophgo/Support/Helper/Module.h"

using namespace sophgo;
using namespace sophgo::helper;
using namespace mlir;

LogicalResult top::AddOp::inference(InferenceParameter &p) {
  auto num_elem = Module::getNumElements(output());
#pragma omp parallel for schedule(static, omp_schedule(num_elem))
  for (int64_t i = 0; i < num_elem; i++) {
    p.outputs[0][i] = 0;
    for (auto in : p.inputs) {
      if (in != nullptr) {
        p.outputs[0][i] += in[i];
      }
    }
  }
  if (do_relu()) {
    relu(p.outputs[0], p.outputs[0], num_elem);
  }
  return success();
}
