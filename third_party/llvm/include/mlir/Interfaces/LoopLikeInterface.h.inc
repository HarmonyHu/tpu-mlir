/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
class LoopLikeOpInterface;
namespace detail {
struct LoopLikeOpInterfaceInterfaceTraits {
  struct Concept {
    bool (*isDefinedOutsideOfLoop)(const Concept *impl, ::mlir::Operation *, ::mlir::Value );
    ::mlir::Region &(*getLoopBody)(const Concept *impl, ::mlir::Operation *);
    ::mlir::LogicalResult (*moveOutOfLoop)(const Concept *impl, ::mlir::Operation *, ::mlir::ArrayRef<::mlir::Operation *>);
    ::mlir::Optional<::mlir::Value> (*getSingleInductionVar)(const Concept *impl, ::mlir::Operation *);
    ::mlir::Optional<::mlir::OpFoldResult> (*getSingleLowerBound)(const Concept *impl, ::mlir::Operation *);
    ::mlir::Optional<::mlir::OpFoldResult> (*getSingleStep)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::LoopLikeOpInterface;
    Model() : Concept{isDefinedOutsideOfLoop, getLoopBody, moveOutOfLoop, getSingleInductionVar, getSingleLowerBound, getSingleStep} {}

    static inline bool isDefinedOutsideOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Value  value);
    static inline ::mlir::Region &getLoopBody(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::LogicalResult moveOutOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::ArrayRef<::mlir::Operation *> ops);
    static inline ::mlir::Optional<::mlir::Value> getSingleInductionVar(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::Optional<::mlir::OpFoldResult> getSingleLowerBound(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::Optional<::mlir::OpFoldResult> getSingleStep(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::LoopLikeOpInterface;
    FallbackModel() : Concept{isDefinedOutsideOfLoop, getLoopBody, moveOutOfLoop, getSingleInductionVar, getSingleLowerBound, getSingleStep} {}

    static inline bool isDefinedOutsideOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Value  value);
    static inline ::mlir::Region &getLoopBody(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::LogicalResult moveOutOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::ArrayRef<::mlir::Operation *> ops);
    static inline ::mlir::Optional<::mlir::Value> getSingleInductionVar(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::Optional<::mlir::OpFoldResult> getSingleLowerBound(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::Optional<::mlir::OpFoldResult> getSingleStep(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    ::mlir::Optional<::mlir::Value> getSingleInductionVar(::mlir::Operation *tablegen_opaque_val) const;
    ::mlir::Optional<::mlir::OpFoldResult> getSingleLowerBound(::mlir::Operation *tablegen_opaque_val) const;
    ::mlir::Optional<::mlir::OpFoldResult> getSingleStep(::mlir::Operation *tablegen_opaque_val) const;
  };
};template <typename ConcreteOp>
struct LoopLikeOpInterfaceTrait;

} // namespace detail
class LoopLikeOpInterface : public ::mlir::OpInterface<LoopLikeOpInterface, detail::LoopLikeOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<LoopLikeOpInterface, detail::LoopLikeOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::LoopLikeOpInterfaceTrait<ConcreteOp> {};
  bool isDefinedOutsideOfLoop(::mlir::Value  value);
  ::mlir::Region &getLoopBody();
  ::mlir::LogicalResult moveOutOfLoop(::mlir::ArrayRef<::mlir::Operation *> ops);
  ::mlir::Optional<::mlir::Value> getSingleInductionVar();
  ::mlir::Optional<::mlir::OpFoldResult> getSingleLowerBound();
  ::mlir::Optional<::mlir::OpFoldResult> getSingleStep();
};
namespace detail {
  template <typename ConcreteOp>
  struct LoopLikeOpInterfaceTrait : public ::mlir::OpInterface<LoopLikeOpInterface, detail::LoopLikeOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    ::mlir::Optional<::mlir::Value> getSingleInductionVar() {
      return llvm::None;
    }
    ::mlir::Optional<::mlir::OpFoldResult> getSingleLowerBound() {
      return llvm::None;
    }
    ::mlir::Optional<::mlir::OpFoldResult> getSingleStep() {
      return llvm::None;
    }
  };
}// namespace detail
template<typename ConcreteOp>
bool detail::LoopLikeOpInterfaceInterfaceTraits::Model<ConcreteOp>::isDefinedOutsideOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Value  value) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).isDefinedOutsideOfLoop(value);
}
template<typename ConcreteOp>
::mlir::Region &detail::LoopLikeOpInterfaceInterfaceTraits::Model<ConcreteOp>::getLoopBody(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getLoopBody();
}
template<typename ConcreteOp>
::mlir::LogicalResult detail::LoopLikeOpInterfaceInterfaceTraits::Model<ConcreteOp>::moveOutOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::ArrayRef<::mlir::Operation *> ops) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).moveOutOfLoop(ops);
}
template<typename ConcreteOp>
::mlir::Optional<::mlir::Value> detail::LoopLikeOpInterfaceInterfaceTraits::Model<ConcreteOp>::getSingleInductionVar(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getSingleInductionVar();
}
template<typename ConcreteOp>
::mlir::Optional<::mlir::OpFoldResult> detail::LoopLikeOpInterfaceInterfaceTraits::Model<ConcreteOp>::getSingleLowerBound(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getSingleLowerBound();
}
template<typename ConcreteOp>
::mlir::Optional<::mlir::OpFoldResult> detail::LoopLikeOpInterfaceInterfaceTraits::Model<ConcreteOp>::getSingleStep(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getSingleStep();
}
template<typename ConcreteOp>
bool detail::LoopLikeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::isDefinedOutsideOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Value  value) {
  return static_cast<const ConcreteOp *>(impl)->isDefinedOutsideOfLoop(tablegen_opaque_val, value);
}
template<typename ConcreteOp>
::mlir::Region &detail::LoopLikeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getLoopBody(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getLoopBody(tablegen_opaque_val);
}
template<typename ConcreteOp>
::mlir::LogicalResult detail::LoopLikeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::moveOutOfLoop(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::ArrayRef<::mlir::Operation *> ops) {
  return static_cast<const ConcreteOp *>(impl)->moveOutOfLoop(tablegen_opaque_val, ops);
}
template<typename ConcreteOp>
::mlir::Optional<::mlir::Value> detail::LoopLikeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getSingleInductionVar(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getSingleInductionVar(tablegen_opaque_val);
}
template<typename ConcreteOp>
::mlir::Optional<::mlir::OpFoldResult> detail::LoopLikeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getSingleLowerBound(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getSingleLowerBound(tablegen_opaque_val);
}
template<typename ConcreteOp>
::mlir::Optional<::mlir::OpFoldResult> detail::LoopLikeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getSingleStep(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getSingleStep(tablegen_opaque_val);
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::Optional<::mlir::Value> detail::LoopLikeOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getSingleInductionVar(::mlir::Operation *tablegen_opaque_val) const {
return llvm::None;
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::Optional<::mlir::OpFoldResult> detail::LoopLikeOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getSingleLowerBound(::mlir::Operation *tablegen_opaque_val) const {
return llvm::None;
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::Optional<::mlir::OpFoldResult> detail::LoopLikeOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getSingleStep(::mlir::Operation *tablegen_opaque_val) const {
return llvm::None;
}
} // namespace mlir