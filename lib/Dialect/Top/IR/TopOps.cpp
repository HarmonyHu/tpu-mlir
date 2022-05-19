#include "sophgo/Dialect/Top/IR/TopOps.h"
#include "sophgo/Support/Helper/Module.h"

#include <numeric>

using namespace mlir;
using namespace sophgo;
using namespace sophgo::top;
using namespace sophgo::helper;

//===----------------------------------------------------------------------===//
// Dialect initialize method.
//===----------------------------------------------------------------------===//
#include "sophgo/Dialect/Top/IR/TopOpsDialect.cpp.inc"

void TopDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "sophgo/Dialect/Top/IR/TopOps.cpp.inc"
      >();
  wFile = nullptr;
}

//===----------------------------------------------------------------------===//
// Top Operator Definitions.
//===----------------------------------------------------------------------===//

#define GET_OP_CLASSES
#include "sophgo/Dialect/Top/IR/TopOps.cpp.inc"

