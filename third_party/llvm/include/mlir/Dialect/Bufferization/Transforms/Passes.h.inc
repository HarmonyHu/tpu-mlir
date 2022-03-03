/* Autogenerated by mlir-tblgen; don't manually edit */
#ifdef GEN_PASS_CLASSES

//===----------------------------------------------------------------------===//
// BufferDeallocation
//===----------------------------------------------------------------------===//

template <typename DerivedT>
class BufferDeallocationBase : public ::mlir::OperationPass<FuncOp> {
public:
  using Base = BufferDeallocationBase;

  BufferDeallocationBase() : ::mlir::OperationPass<FuncOp>(::mlir::TypeID::get<DerivedT>()) {}
  BufferDeallocationBase(const BufferDeallocationBase &other) : ::mlir::OperationPass<FuncOp>(other) {}

  /// Returns the command-line argument attached to this pass.
  static constexpr ::llvm::StringLiteral getArgumentName() {
    return ::llvm::StringLiteral("buffer-deallocation");
  }
  ::llvm::StringRef getArgument() const override { return "buffer-deallocation"; }

  ::llvm::StringRef getDescription() const override { return "Adds all required dealloc operations for all allocations in the input program"; }

  /// Returns the derived pass name.
  static constexpr ::llvm::StringLiteral getPassName() {
    return ::llvm::StringLiteral("BufferDeallocation");
  }
  ::llvm::StringRef getName() const override { return "BufferDeallocation"; }

  /// Support isa/dyn_cast functionality for the derived pass class.
  static bool classof(const ::mlir::Pass *pass) {
    return pass->getTypeID() == ::mlir::TypeID::get<DerivedT>();
  }

  /// A clone method to create a copy of this pass.
  std::unique_ptr<::mlir::Pass> clonePass() const override {
    return std::make_unique<DerivedT>(*static_cast<const DerivedT *>(this));
  }

  /// Return the dialect that must be loaded in the context before this pass.
  void getDependentDialects(::mlir::DialectRegistry &registry) const override {
    
  }

protected:
};

//===----------------------------------------------------------------------===//
// BufferHoisting
//===----------------------------------------------------------------------===//

template <typename DerivedT>
class BufferHoistingBase : public ::mlir::OperationPass<FuncOp> {
public:
  using Base = BufferHoistingBase;

  BufferHoistingBase() : ::mlir::OperationPass<FuncOp>(::mlir::TypeID::get<DerivedT>()) {}
  BufferHoistingBase(const BufferHoistingBase &other) : ::mlir::OperationPass<FuncOp>(other) {}

  /// Returns the command-line argument attached to this pass.
  static constexpr ::llvm::StringLiteral getArgumentName() {
    return ::llvm::StringLiteral("buffer-hoisting");
  }
  ::llvm::StringRef getArgument() const override { return "buffer-hoisting"; }

  ::llvm::StringRef getDescription() const override { return "Optimizes placement of allocation operations by moving them into common dominators and out of nested regions"; }

  /// Returns the derived pass name.
  static constexpr ::llvm::StringLiteral getPassName() {
    return ::llvm::StringLiteral("BufferHoisting");
  }
  ::llvm::StringRef getName() const override { return "BufferHoisting"; }

  /// Support isa/dyn_cast functionality for the derived pass class.
  static bool classof(const ::mlir::Pass *pass) {
    return pass->getTypeID() == ::mlir::TypeID::get<DerivedT>();
  }

  /// A clone method to create a copy of this pass.
  std::unique_ptr<::mlir::Pass> clonePass() const override {
    return std::make_unique<DerivedT>(*static_cast<const DerivedT *>(this));
  }

  /// Return the dialect that must be loaded in the context before this pass.
  void getDependentDialects(::mlir::DialectRegistry &registry) const override {
    
  }

protected:
};

//===----------------------------------------------------------------------===//
// BufferLoopHoisting
//===----------------------------------------------------------------------===//

template <typename DerivedT>
class BufferLoopHoistingBase : public ::mlir::OperationPass<FuncOp> {
public:
  using Base = BufferLoopHoistingBase;

  BufferLoopHoistingBase() : ::mlir::OperationPass<FuncOp>(::mlir::TypeID::get<DerivedT>()) {}
  BufferLoopHoistingBase(const BufferLoopHoistingBase &other) : ::mlir::OperationPass<FuncOp>(other) {}

  /// Returns the command-line argument attached to this pass.
  static constexpr ::llvm::StringLiteral getArgumentName() {
    return ::llvm::StringLiteral("buffer-loop-hoisting");
  }
  ::llvm::StringRef getArgument() const override { return "buffer-loop-hoisting"; }

  ::llvm::StringRef getDescription() const override { return "Optimizes placement of allocation operations by moving them out of loop nests"; }

  /// Returns the derived pass name.
  static constexpr ::llvm::StringLiteral getPassName() {
    return ::llvm::StringLiteral("BufferLoopHoisting");
  }
  ::llvm::StringRef getName() const override { return "BufferLoopHoisting"; }

  /// Support isa/dyn_cast functionality for the derived pass class.
  static bool classof(const ::mlir::Pass *pass) {
    return pass->getTypeID() == ::mlir::TypeID::get<DerivedT>();
  }

  /// A clone method to create a copy of this pass.
  std::unique_ptr<::mlir::Pass> clonePass() const override {
    return std::make_unique<DerivedT>(*static_cast<const DerivedT *>(this));
  }

  /// Return the dialect that must be loaded in the context before this pass.
  void getDependentDialects(::mlir::DialectRegistry &registry) const override {
    
  }

protected:
};

//===----------------------------------------------------------------------===//
// BufferResultsToOutParams
//===----------------------------------------------------------------------===//

template <typename DerivedT>
class BufferResultsToOutParamsBase : public ::mlir::OperationPass<ModuleOp> {
public:
  using Base = BufferResultsToOutParamsBase;

  BufferResultsToOutParamsBase() : ::mlir::OperationPass<ModuleOp>(::mlir::TypeID::get<DerivedT>()) {}
  BufferResultsToOutParamsBase(const BufferResultsToOutParamsBase &other) : ::mlir::OperationPass<ModuleOp>(other) {}

  /// Returns the command-line argument attached to this pass.
  static constexpr ::llvm::StringLiteral getArgumentName() {
    return ::llvm::StringLiteral("buffer-results-to-out-params");
  }
  ::llvm::StringRef getArgument() const override { return "buffer-results-to-out-params"; }

  ::llvm::StringRef getDescription() const override { return "Converts memref-typed function results to out-params"; }

  /// Returns the derived pass name.
  static constexpr ::llvm::StringLiteral getPassName() {
    return ::llvm::StringLiteral("BufferResultsToOutParams");
  }
  ::llvm::StringRef getName() const override { return "BufferResultsToOutParams"; }

  /// Support isa/dyn_cast functionality for the derived pass class.
  static bool classof(const ::mlir::Pass *pass) {
    return pass->getTypeID() == ::mlir::TypeID::get<DerivedT>();
  }

  /// A clone method to create a copy of this pass.
  std::unique_ptr<::mlir::Pass> clonePass() const override {
    return std::make_unique<DerivedT>(*static_cast<const DerivedT *>(this));
  }

  /// Return the dialect that must be loaded in the context before this pass.
  void getDependentDialects(::mlir::DialectRegistry &registry) const override {
    
  registry.insert<memref::MemRefDialect>();

  }

protected:
};

//===----------------------------------------------------------------------===//
// FinalizingBufferize
//===----------------------------------------------------------------------===//

template <typename DerivedT>
class FinalizingBufferizeBase : public ::mlir::OperationPass<FuncOp> {
public:
  using Base = FinalizingBufferizeBase;

  FinalizingBufferizeBase() : ::mlir::OperationPass<FuncOp>(::mlir::TypeID::get<DerivedT>()) {}
  FinalizingBufferizeBase(const FinalizingBufferizeBase &other) : ::mlir::OperationPass<FuncOp>(other) {}

  /// Returns the command-line argument attached to this pass.
  static constexpr ::llvm::StringLiteral getArgumentName() {
    return ::llvm::StringLiteral("finalizing-bufferize");
  }
  ::llvm::StringRef getArgument() const override { return "finalizing-bufferize"; }

  ::llvm::StringRef getDescription() const override { return "Finalize a partial bufferization"; }

  /// Returns the derived pass name.
  static constexpr ::llvm::StringLiteral getPassName() {
    return ::llvm::StringLiteral("FinalizingBufferize");
  }
  ::llvm::StringRef getName() const override { return "FinalizingBufferize"; }

  /// Support isa/dyn_cast functionality for the derived pass class.
  static bool classof(const ::mlir::Pass *pass) {
    return pass->getTypeID() == ::mlir::TypeID::get<DerivedT>();
  }

  /// A clone method to create a copy of this pass.
  std::unique_ptr<::mlir::Pass> clonePass() const override {
    return std::make_unique<DerivedT>(*static_cast<const DerivedT *>(this));
  }

  /// Return the dialect that must be loaded in the context before this pass.
  void getDependentDialects(::mlir::DialectRegistry &registry) const override {
    
  }

protected:
};

//===----------------------------------------------------------------------===//
// PromoteBuffersToStack
//===----------------------------------------------------------------------===//

template <typename DerivedT>
class PromoteBuffersToStackBase : public ::mlir::OperationPass<FuncOp> {
public:
  using Base = PromoteBuffersToStackBase;

  PromoteBuffersToStackBase() : ::mlir::OperationPass<FuncOp>(::mlir::TypeID::get<DerivedT>()) {}
  PromoteBuffersToStackBase(const PromoteBuffersToStackBase &other) : ::mlir::OperationPass<FuncOp>(other) {}

  /// Returns the command-line argument attached to this pass.
  static constexpr ::llvm::StringLiteral getArgumentName() {
    return ::llvm::StringLiteral("promote-buffers-to-stack");
  }
  ::llvm::StringRef getArgument() const override { return "promote-buffers-to-stack"; }

  ::llvm::StringRef getDescription() const override { return "Promotes heap-based allocations to automatically managed stack-based allocations"; }

  /// Returns the derived pass name.
  static constexpr ::llvm::StringLiteral getPassName() {
    return ::llvm::StringLiteral("PromoteBuffersToStack");
  }
  ::llvm::StringRef getName() const override { return "PromoteBuffersToStack"; }

  /// Support isa/dyn_cast functionality for the derived pass class.
  static bool classof(const ::mlir::Pass *pass) {
    return pass->getTypeID() == ::mlir::TypeID::get<DerivedT>();
  }

  /// A clone method to create a copy of this pass.
  std::unique_ptr<::mlir::Pass> clonePass() const override {
    return std::make_unique<DerivedT>(*static_cast<const DerivedT *>(this));
  }

  /// Return the dialect that must be loaded in the context before this pass.
  void getDependentDialects(::mlir::DialectRegistry &registry) const override {
    
  }

protected:
  ::mlir::Pass::Option<unsigned> maxAllocSizeInBytes{*this, "max-alloc-size-in-bytes", ::llvm::cl::desc("Maximal size in bytes to promote allocations to stack."), ::llvm::cl::init(1024)};
  ::mlir::Pass::Option<unsigned> maxRankOfAllocatedMemRef{*this, "max-rank-of-allocated-memref", ::llvm::cl::desc("Maximal memref rank to promote dynamic buffers."), ::llvm::cl::init(1)};
};
#undef GEN_PASS_CLASSES
#endif // GEN_PASS_CLASSES
#ifdef GEN_PASS_REGISTRATION

//===----------------------------------------------------------------------===//
// BufferDeallocation Registration
//===----------------------------------------------------------------------===//

inline void registerBufferDeallocationPass() {
  ::mlir::registerPass([]() -> std::unique_ptr<::mlir::Pass> {
    return mlir::bufferization::createBufferDeallocationPass();
  });
}

//===----------------------------------------------------------------------===//
// BufferHoisting Registration
//===----------------------------------------------------------------------===//

inline void registerBufferHoistingPass() {
  ::mlir::registerPass([]() -> std::unique_ptr<::mlir::Pass> {
    return mlir::bufferization::createBufferHoistingPass();
  });
}

//===----------------------------------------------------------------------===//
// BufferLoopHoisting Registration
//===----------------------------------------------------------------------===//

inline void registerBufferLoopHoistingPass() {
  ::mlir::registerPass([]() -> std::unique_ptr<::mlir::Pass> {
    return mlir::bufferization::createBufferLoopHoistingPass();
  });
}

//===----------------------------------------------------------------------===//
// BufferResultsToOutParams Registration
//===----------------------------------------------------------------------===//

inline void registerBufferResultsToOutParamsPass() {
  ::mlir::registerPass([]() -> std::unique_ptr<::mlir::Pass> {
    return mlir::bufferization::createBufferResultsToOutParamsPass();
  });
}

//===----------------------------------------------------------------------===//
// FinalizingBufferize Registration
//===----------------------------------------------------------------------===//

inline void registerFinalizingBufferizePass() {
  ::mlir::registerPass([]() -> std::unique_ptr<::mlir::Pass> {
    return mlir::bufferization::createFinalizingBufferizePass();
  });
}

//===----------------------------------------------------------------------===//
// PromoteBuffersToStack Registration
//===----------------------------------------------------------------------===//

inline void registerPromoteBuffersToStackPass() {
  ::mlir::registerPass([]() -> std::unique_ptr<::mlir::Pass> {
    return mlir::bufferization::createPromoteBuffersToStackPass();
  });
}

//===----------------------------------------------------------------------===//
// Bufferization Registration
//===----------------------------------------------------------------------===//

inline void registerBufferizationPasses() {
  registerBufferDeallocationPass();
  registerBufferHoistingPass();
  registerBufferLoopHoistingPass();
  registerBufferResultsToOutParamsPass();
  registerFinalizingBufferizePass();
  registerPromoteBuffersToStackPass();
}
#undef GEN_PASS_REGISTRATION
#endif // GEN_PASS_REGISTRATION