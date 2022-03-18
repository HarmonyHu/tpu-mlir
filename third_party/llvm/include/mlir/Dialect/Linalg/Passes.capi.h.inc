
/* Autogenerated by mlir-tblgen; don't manually edit. */

#include "mlir-c/Pass.h"

#ifdef __cplusplus
extern "C" {
#endif

// Registration for the entire group
MLIR_CAPI_EXPORTED void mlirRegisterLinalgPasses();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgConvertElementwiseToLinalg();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgConvertElementwiseToLinalg();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgBufferize();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgBufferize();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgComprehensiveModuleBufferize();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgComprehensiveModuleBufferize();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgDetensorize();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgDetensorize();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgElementwiseOpFusion();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgElementwiseOpFusion();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgFoldReshapeOpsByLinearization();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgFoldReshapeOpsByLinearization();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgFoldUnitExtentDims();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgFoldUnitExtentDims();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgGeneralization();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgGeneralization();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgInlineScalarOperands();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgInlineScalarOperands();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgLowerToAffineLoops();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgLowerToAffineLoops();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgLowerToLoops();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgLowerToLoops();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgLowerToParallelLoops();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgLowerToParallelLoops();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgNamedOpConversion();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgNamedOpConversion();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgPromotion();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgPromotion();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyDecomposePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyDecomposePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyEnablePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyEnablePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyGeneralizePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyGeneralizePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyInterchangePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyInterchangePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyLowerVectorsPass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyLowerVectorsPass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyPadPass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyPadPass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyPromotePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyPromotePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyRemoveMarkersPass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyRemoveMarkersPass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyTileAndFusePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyTileAndFusePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyTilePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyTilePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgStrategyVectorizePass();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgStrategyVectorizePass();


/* Create Linalg Pass. */
MLIR_CAPI_EXPORTED MlirPass mlirCreateLinalgLinalgTiling();
MLIR_CAPI_EXPORTED void mlirRegisterLinalgLinalgTiling();



#ifdef __cplusplus
}
#endif