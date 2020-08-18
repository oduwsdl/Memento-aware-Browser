// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_MEMORY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_MEMORY_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_memory.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace memory {

// Heap profile sample.
class HEADLESS_EXPORT SamplingProfileNode {
 public:
  static std::unique_ptr<SamplingProfileNode> Parse(const base::Value& value, ErrorReporter* errors);
  ~SamplingProfileNode() { }

  // Size of the sampled allocation.
  double GetSize() const { return size_; }
  void SetSize(double value) { size_ = value; }

  // Total bytes attributed to this sample.
  double GetTotal() const { return total_; }
  void SetTotal(double value) { total_ = value; }

  // Execution stack at the point of allocation.
  const std::vector<std::string>* GetStack() const { return &stack_; }
  void SetStack(std::vector<std::string> value) { stack_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SamplingProfileNode> Clone() const;

  template<int STATE>
  class SamplingProfileNodeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSizeSet = 1 << 1,
    kTotalSet = 1 << 2,
    kStackSet = 1 << 3,
      kAllRequiredFieldsSet = (kSizeSet | kTotalSet | kStackSet | 0)
    };

    SamplingProfileNodeBuilder<STATE | kSizeSet>& SetSize(double value) {
      static_assert(!(STATE & kSizeSet), "property size should not have already been set");
      result_->SetSize(value);
      return CastState<kSizeSet>();
    }

    SamplingProfileNodeBuilder<STATE | kTotalSet>& SetTotal(double value) {
      static_assert(!(STATE & kTotalSet), "property total should not have already been set");
      result_->SetTotal(value);
      return CastState<kTotalSet>();
    }

    SamplingProfileNodeBuilder<STATE | kStackSet>& SetStack(std::vector<std::string> value) {
      static_assert(!(STATE & kStackSet), "property stack should not have already been set");
      result_->SetStack(std::move(value));
      return CastState<kStackSet>();
    }

    std::unique_ptr<SamplingProfileNode> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SamplingProfileNode;
    SamplingProfileNodeBuilder() : result_(new SamplingProfileNode()) { }

    template<int STEP> SamplingProfileNodeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SamplingProfileNodeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SamplingProfileNode> result_;
  };

  static SamplingProfileNodeBuilder<0> Builder() {
    return SamplingProfileNodeBuilder<0>();
  }

 private:
  SamplingProfileNode() { }

  double size_;
  double total_;
  std::vector<std::string> stack_;

  DISALLOW_COPY_AND_ASSIGN(SamplingProfileNode);
};


// Array of heap profile samples.
class HEADLESS_EXPORT SamplingProfile {
 public:
  static std::unique_ptr<SamplingProfile> Parse(const base::Value& value, ErrorReporter* errors);
  ~SamplingProfile() { }

  const std::vector<std::unique_ptr<::headless::memory::SamplingProfileNode>>* GetSamples() const { return &samples_; }
  void SetSamples(std::vector<std::unique_ptr<::headless::memory::SamplingProfileNode>> value) { samples_ = std::move(value); }

  const std::vector<std::unique_ptr<::headless::memory::Module>>* GetModules() const { return &modules_; }
  void SetModules(std::vector<std::unique_ptr<::headless::memory::Module>> value) { modules_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SamplingProfile> Clone() const;

  template<int STATE>
  class SamplingProfileBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSamplesSet = 1 << 1,
    kModulesSet = 1 << 2,
      kAllRequiredFieldsSet = (kSamplesSet | kModulesSet | 0)
    };

    SamplingProfileBuilder<STATE | kSamplesSet>& SetSamples(std::vector<std::unique_ptr<::headless::memory::SamplingProfileNode>> value) {
      static_assert(!(STATE & kSamplesSet), "property samples should not have already been set");
      result_->SetSamples(std::move(value));
      return CastState<kSamplesSet>();
    }

    SamplingProfileBuilder<STATE | kModulesSet>& SetModules(std::vector<std::unique_ptr<::headless::memory::Module>> value) {
      static_assert(!(STATE & kModulesSet), "property modules should not have already been set");
      result_->SetModules(std::move(value));
      return CastState<kModulesSet>();
    }

    std::unique_ptr<SamplingProfile> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SamplingProfile;
    SamplingProfileBuilder() : result_(new SamplingProfile()) { }

    template<int STEP> SamplingProfileBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SamplingProfileBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SamplingProfile> result_;
  };

  static SamplingProfileBuilder<0> Builder() {
    return SamplingProfileBuilder<0>();
  }

 private:
  SamplingProfile() { }

  std::vector<std::unique_ptr<::headless::memory::SamplingProfileNode>> samples_;
  std::vector<std::unique_ptr<::headless::memory::Module>> modules_;

  DISALLOW_COPY_AND_ASSIGN(SamplingProfile);
};


// Executable module information
class HEADLESS_EXPORT Module {
 public:
  static std::unique_ptr<Module> Parse(const base::Value& value, ErrorReporter* errors);
  ~Module() { }

  // Name of the module.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // UUID of the module.
  std::string GetUuid() const { return uuid_; }
  void SetUuid(const std::string& value) { uuid_ = value; }

  // Base address where the module is loaded into memory. Encoded as a decimal
  // or hexadecimal (0x prefixed) string.
  std::string GetBaseAddress() const { return base_address_; }
  void SetBaseAddress(const std::string& value) { base_address_ = value; }

  // Size of the module in bytes.
  double GetSize() const { return size_; }
  void SetSize(double value) { size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Module> Clone() const;

  template<int STATE>
  class ModuleBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kUuidSet = 1 << 2,
    kBaseAddressSet = 1 << 3,
    kSizeSet = 1 << 4,
      kAllRequiredFieldsSet = (kNameSet | kUuidSet | kBaseAddressSet | kSizeSet | 0)
    };

    ModuleBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    ModuleBuilder<STATE | kUuidSet>& SetUuid(const std::string& value) {
      static_assert(!(STATE & kUuidSet), "property uuid should not have already been set");
      result_->SetUuid(value);
      return CastState<kUuidSet>();
    }

    ModuleBuilder<STATE | kBaseAddressSet>& SetBaseAddress(const std::string& value) {
      static_assert(!(STATE & kBaseAddressSet), "property baseAddress should not have already been set");
      result_->SetBaseAddress(value);
      return CastState<kBaseAddressSet>();
    }

    ModuleBuilder<STATE | kSizeSet>& SetSize(double value) {
      static_assert(!(STATE & kSizeSet), "property size should not have already been set");
      result_->SetSize(value);
      return CastState<kSizeSet>();
    }

    std::unique_ptr<Module> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Module;
    ModuleBuilder() : result_(new Module()) { }

    template<int STEP> ModuleBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ModuleBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Module> result_;
  };

  static ModuleBuilder<0> Builder() {
    return ModuleBuilder<0>();
  }

 private:
  Module() { }

  std::string name_;
  std::string uuid_;
  std::string base_address_;
  double size_;

  DISALLOW_COPY_AND_ASSIGN(Module);
};


// Parameters for the GetDOMCounters command.
class HEADLESS_EXPORT GetDOMCountersParams {
 public:
  static std::unique_ptr<GetDOMCountersParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetDOMCountersParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetDOMCountersParams> Clone() const;

  template<int STATE>
  class GetDOMCountersParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetDOMCountersParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetDOMCountersParams;
    GetDOMCountersParamsBuilder() : result_(new GetDOMCountersParams()) { }

    template<int STEP> GetDOMCountersParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetDOMCountersParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetDOMCountersParams> result_;
  };

  static GetDOMCountersParamsBuilder<0> Builder() {
    return GetDOMCountersParamsBuilder<0>();
  }

 private:
  GetDOMCountersParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetDOMCountersParams);
};


// Result for the GetDOMCounters command.
class HEADLESS_EXPORT GetDOMCountersResult {
 public:
  static std::unique_ptr<GetDOMCountersResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetDOMCountersResult() { }

  int GetDocuments() const { return documents_; }
  void SetDocuments(int value) { documents_ = value; }

  int GetNodes() const { return nodes_; }
  void SetNodes(int value) { nodes_ = value; }

  int GetJsEventListeners() const { return js_event_listeners_; }
  void SetJsEventListeners(int value) { js_event_listeners_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetDOMCountersResult> Clone() const;

  template<int STATE>
  class GetDOMCountersResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDocumentsSet = 1 << 1,
    kNodesSet = 1 << 2,
    kJsEventListenersSet = 1 << 3,
      kAllRequiredFieldsSet = (kDocumentsSet | kNodesSet | kJsEventListenersSet | 0)
    };

    GetDOMCountersResultBuilder<STATE | kDocumentsSet>& SetDocuments(int value) {
      static_assert(!(STATE & kDocumentsSet), "property documents should not have already been set");
      result_->SetDocuments(value);
      return CastState<kDocumentsSet>();
    }

    GetDOMCountersResultBuilder<STATE | kNodesSet>& SetNodes(int value) {
      static_assert(!(STATE & kNodesSet), "property nodes should not have already been set");
      result_->SetNodes(value);
      return CastState<kNodesSet>();
    }

    GetDOMCountersResultBuilder<STATE | kJsEventListenersSet>& SetJsEventListeners(int value) {
      static_assert(!(STATE & kJsEventListenersSet), "property jsEventListeners should not have already been set");
      result_->SetJsEventListeners(value);
      return CastState<kJsEventListenersSet>();
    }

    std::unique_ptr<GetDOMCountersResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetDOMCountersResult;
    GetDOMCountersResultBuilder() : result_(new GetDOMCountersResult()) { }

    template<int STEP> GetDOMCountersResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetDOMCountersResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetDOMCountersResult> result_;
  };

  static GetDOMCountersResultBuilder<0> Builder() {
    return GetDOMCountersResultBuilder<0>();
  }

 private:
  GetDOMCountersResult() { }

  int documents_;
  int nodes_;
  int js_event_listeners_;

  DISALLOW_COPY_AND_ASSIGN(GetDOMCountersResult);
};


// Parameters for the PrepareForLeakDetection command.
class HEADLESS_EXPORT PrepareForLeakDetectionParams {
 public:
  static std::unique_ptr<PrepareForLeakDetectionParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PrepareForLeakDetectionParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PrepareForLeakDetectionParams> Clone() const;

  template<int STATE>
  class PrepareForLeakDetectionParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<PrepareForLeakDetectionParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PrepareForLeakDetectionParams;
    PrepareForLeakDetectionParamsBuilder() : result_(new PrepareForLeakDetectionParams()) { }

    template<int STEP> PrepareForLeakDetectionParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PrepareForLeakDetectionParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PrepareForLeakDetectionParams> result_;
  };

  static PrepareForLeakDetectionParamsBuilder<0> Builder() {
    return PrepareForLeakDetectionParamsBuilder<0>();
  }

 private:
  PrepareForLeakDetectionParams() { }


  DISALLOW_COPY_AND_ASSIGN(PrepareForLeakDetectionParams);
};


// Result for the PrepareForLeakDetection command.
class HEADLESS_EXPORT PrepareForLeakDetectionResult {
 public:
  static std::unique_ptr<PrepareForLeakDetectionResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~PrepareForLeakDetectionResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PrepareForLeakDetectionResult> Clone() const;

  template<int STATE>
  class PrepareForLeakDetectionResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<PrepareForLeakDetectionResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PrepareForLeakDetectionResult;
    PrepareForLeakDetectionResultBuilder() : result_(new PrepareForLeakDetectionResult()) { }

    template<int STEP> PrepareForLeakDetectionResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PrepareForLeakDetectionResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PrepareForLeakDetectionResult> result_;
  };

  static PrepareForLeakDetectionResultBuilder<0> Builder() {
    return PrepareForLeakDetectionResultBuilder<0>();
  }

 private:
  PrepareForLeakDetectionResult() { }


  DISALLOW_COPY_AND_ASSIGN(PrepareForLeakDetectionResult);
};


// Parameters for the ForciblyPurgeJavaScriptMemory command.
class HEADLESS_EXPORT ForciblyPurgeJavaScriptMemoryParams {
 public:
  static std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ForciblyPurgeJavaScriptMemoryParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> Clone() const;

  template<int STATE>
  class ForciblyPurgeJavaScriptMemoryParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ForciblyPurgeJavaScriptMemoryParams;
    ForciblyPurgeJavaScriptMemoryParamsBuilder() : result_(new ForciblyPurgeJavaScriptMemoryParams()) { }

    template<int STEP> ForciblyPurgeJavaScriptMemoryParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ForciblyPurgeJavaScriptMemoryParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> result_;
  };

  static ForciblyPurgeJavaScriptMemoryParamsBuilder<0> Builder() {
    return ForciblyPurgeJavaScriptMemoryParamsBuilder<0>();
  }

 private:
  ForciblyPurgeJavaScriptMemoryParams() { }


  DISALLOW_COPY_AND_ASSIGN(ForciblyPurgeJavaScriptMemoryParams);
};


// Result for the ForciblyPurgeJavaScriptMemory command.
class HEADLESS_EXPORT ForciblyPurgeJavaScriptMemoryResult {
 public:
  static std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ForciblyPurgeJavaScriptMemoryResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> Clone() const;

  template<int STATE>
  class ForciblyPurgeJavaScriptMemoryResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ForciblyPurgeJavaScriptMemoryResult;
    ForciblyPurgeJavaScriptMemoryResultBuilder() : result_(new ForciblyPurgeJavaScriptMemoryResult()) { }

    template<int STEP> ForciblyPurgeJavaScriptMemoryResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ForciblyPurgeJavaScriptMemoryResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> result_;
  };

  static ForciblyPurgeJavaScriptMemoryResultBuilder<0> Builder() {
    return ForciblyPurgeJavaScriptMemoryResultBuilder<0>();
  }

 private:
  ForciblyPurgeJavaScriptMemoryResult() { }


  DISALLOW_COPY_AND_ASSIGN(ForciblyPurgeJavaScriptMemoryResult);
};


// Parameters for the SetPressureNotificationsSuppressed command.
class HEADLESS_EXPORT SetPressureNotificationsSuppressedParams {
 public:
  static std::unique_ptr<SetPressureNotificationsSuppressedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPressureNotificationsSuppressedParams() { }

  // If true, memory pressure notifications will be suppressed.
  bool GetSuppressed() const { return suppressed_; }
  void SetSuppressed(bool value) { suppressed_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPressureNotificationsSuppressedParams> Clone() const;

  template<int STATE>
  class SetPressureNotificationsSuppressedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSuppressedSet = 1 << 1,
      kAllRequiredFieldsSet = (kSuppressedSet | 0)
    };

    SetPressureNotificationsSuppressedParamsBuilder<STATE | kSuppressedSet>& SetSuppressed(bool value) {
      static_assert(!(STATE & kSuppressedSet), "property suppressed should not have already been set");
      result_->SetSuppressed(value);
      return CastState<kSuppressedSet>();
    }

    std::unique_ptr<SetPressureNotificationsSuppressedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPressureNotificationsSuppressedParams;
    SetPressureNotificationsSuppressedParamsBuilder() : result_(new SetPressureNotificationsSuppressedParams()) { }

    template<int STEP> SetPressureNotificationsSuppressedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPressureNotificationsSuppressedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPressureNotificationsSuppressedParams> result_;
  };

  static SetPressureNotificationsSuppressedParamsBuilder<0> Builder() {
    return SetPressureNotificationsSuppressedParamsBuilder<0>();
  }

 private:
  SetPressureNotificationsSuppressedParams() { }

  bool suppressed_;

  DISALLOW_COPY_AND_ASSIGN(SetPressureNotificationsSuppressedParams);
};


// Result for the SetPressureNotificationsSuppressed command.
class HEADLESS_EXPORT SetPressureNotificationsSuppressedResult {
 public:
  static std::unique_ptr<SetPressureNotificationsSuppressedResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPressureNotificationsSuppressedResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPressureNotificationsSuppressedResult> Clone() const;

  template<int STATE>
  class SetPressureNotificationsSuppressedResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetPressureNotificationsSuppressedResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPressureNotificationsSuppressedResult;
    SetPressureNotificationsSuppressedResultBuilder() : result_(new SetPressureNotificationsSuppressedResult()) { }

    template<int STEP> SetPressureNotificationsSuppressedResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPressureNotificationsSuppressedResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPressureNotificationsSuppressedResult> result_;
  };

  static SetPressureNotificationsSuppressedResultBuilder<0> Builder() {
    return SetPressureNotificationsSuppressedResultBuilder<0>();
  }

 private:
  SetPressureNotificationsSuppressedResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetPressureNotificationsSuppressedResult);
};


// Parameters for the SimulatePressureNotification command.
class HEADLESS_EXPORT SimulatePressureNotificationParams {
 public:
  static std::unique_ptr<SimulatePressureNotificationParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SimulatePressureNotificationParams() { }

  // Memory pressure level of the notification.
  ::headless::memory::PressureLevel GetLevel() const { return level_; }
  void SetLevel(::headless::memory::PressureLevel value) { level_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SimulatePressureNotificationParams> Clone() const;

  template<int STATE>
  class SimulatePressureNotificationParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLevelSet = 1 << 1,
      kAllRequiredFieldsSet = (kLevelSet | 0)
    };

    SimulatePressureNotificationParamsBuilder<STATE | kLevelSet>& SetLevel(::headless::memory::PressureLevel value) {
      static_assert(!(STATE & kLevelSet), "property level should not have already been set");
      result_->SetLevel(value);
      return CastState<kLevelSet>();
    }

    std::unique_ptr<SimulatePressureNotificationParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SimulatePressureNotificationParams;
    SimulatePressureNotificationParamsBuilder() : result_(new SimulatePressureNotificationParams()) { }

    template<int STEP> SimulatePressureNotificationParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SimulatePressureNotificationParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SimulatePressureNotificationParams> result_;
  };

  static SimulatePressureNotificationParamsBuilder<0> Builder() {
    return SimulatePressureNotificationParamsBuilder<0>();
  }

 private:
  SimulatePressureNotificationParams() { }

  ::headless::memory::PressureLevel level_;

  DISALLOW_COPY_AND_ASSIGN(SimulatePressureNotificationParams);
};


// Result for the SimulatePressureNotification command.
class HEADLESS_EXPORT SimulatePressureNotificationResult {
 public:
  static std::unique_ptr<SimulatePressureNotificationResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SimulatePressureNotificationResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SimulatePressureNotificationResult> Clone() const;

  template<int STATE>
  class SimulatePressureNotificationResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SimulatePressureNotificationResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SimulatePressureNotificationResult;
    SimulatePressureNotificationResultBuilder() : result_(new SimulatePressureNotificationResult()) { }

    template<int STEP> SimulatePressureNotificationResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SimulatePressureNotificationResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SimulatePressureNotificationResult> result_;
  };

  static SimulatePressureNotificationResultBuilder<0> Builder() {
    return SimulatePressureNotificationResultBuilder<0>();
  }

 private:
  SimulatePressureNotificationResult() { }


  DISALLOW_COPY_AND_ASSIGN(SimulatePressureNotificationResult);
};


// Parameters for the StartSampling command.
class HEADLESS_EXPORT StartSamplingParams {
 public:
  static std::unique_ptr<StartSamplingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartSamplingParams() { }

  // Average number of bytes between samples.
  bool HasSamplingInterval() const { return !!sampling_interval_; }
  int GetSamplingInterval() const { DCHECK(HasSamplingInterval()); return sampling_interval_.value(); }
  void SetSamplingInterval(int value) { sampling_interval_ = value; }

  // Do not randomize intervals between samples.
  bool HasSuppressRandomness() const { return !!suppress_randomness_; }
  bool GetSuppressRandomness() const { DCHECK(HasSuppressRandomness()); return suppress_randomness_.value(); }
  void SetSuppressRandomness(bool value) { suppress_randomness_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartSamplingParams> Clone() const;

  template<int STATE>
  class StartSamplingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    StartSamplingParamsBuilder<STATE>& SetSamplingInterval(int value) {
      result_->SetSamplingInterval(value);
      return *this;
    }

    StartSamplingParamsBuilder<STATE>& SetSuppressRandomness(bool value) {
      result_->SetSuppressRandomness(value);
      return *this;
    }

    std::unique_ptr<StartSamplingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartSamplingParams;
    StartSamplingParamsBuilder() : result_(new StartSamplingParams()) { }

    template<int STEP> StartSamplingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartSamplingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartSamplingParams> result_;
  };

  static StartSamplingParamsBuilder<0> Builder() {
    return StartSamplingParamsBuilder<0>();
  }

 private:
  StartSamplingParams() { }

  base::Optional<int> sampling_interval_;
  base::Optional<bool> suppress_randomness_;

  DISALLOW_COPY_AND_ASSIGN(StartSamplingParams);
};


// Result for the StartSampling command.
class HEADLESS_EXPORT StartSamplingResult {
 public:
  static std::unique_ptr<StartSamplingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartSamplingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartSamplingResult> Clone() const;

  template<int STATE>
  class StartSamplingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartSamplingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartSamplingResult;
    StartSamplingResultBuilder() : result_(new StartSamplingResult()) { }

    template<int STEP> StartSamplingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartSamplingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartSamplingResult> result_;
  };

  static StartSamplingResultBuilder<0> Builder() {
    return StartSamplingResultBuilder<0>();
  }

 private:
  StartSamplingResult() { }


  DISALLOW_COPY_AND_ASSIGN(StartSamplingResult);
};


// Parameters for the StopSampling command.
class HEADLESS_EXPORT StopSamplingParams {
 public:
  static std::unique_ptr<StopSamplingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopSamplingParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopSamplingParams> Clone() const;

  template<int STATE>
  class StopSamplingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopSamplingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopSamplingParams;
    StopSamplingParamsBuilder() : result_(new StopSamplingParams()) { }

    template<int STEP> StopSamplingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopSamplingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopSamplingParams> result_;
  };

  static StopSamplingParamsBuilder<0> Builder() {
    return StopSamplingParamsBuilder<0>();
  }

 private:
  StopSamplingParams() { }


  DISALLOW_COPY_AND_ASSIGN(StopSamplingParams);
};


// Result for the StopSampling command.
class HEADLESS_EXPORT StopSamplingResult {
 public:
  static std::unique_ptr<StopSamplingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopSamplingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopSamplingResult> Clone() const;

  template<int STATE>
  class StopSamplingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopSamplingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopSamplingResult;
    StopSamplingResultBuilder() : result_(new StopSamplingResult()) { }

    template<int STEP> StopSamplingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopSamplingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopSamplingResult> result_;
  };

  static StopSamplingResultBuilder<0> Builder() {
    return StopSamplingResultBuilder<0>();
  }

 private:
  StopSamplingResult() { }


  DISALLOW_COPY_AND_ASSIGN(StopSamplingResult);
};


// Parameters for the GetAllTimeSamplingProfile command.
class HEADLESS_EXPORT GetAllTimeSamplingProfileParams {
 public:
  static std::unique_ptr<GetAllTimeSamplingProfileParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAllTimeSamplingProfileParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAllTimeSamplingProfileParams> Clone() const;

  template<int STATE>
  class GetAllTimeSamplingProfileParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetAllTimeSamplingProfileParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAllTimeSamplingProfileParams;
    GetAllTimeSamplingProfileParamsBuilder() : result_(new GetAllTimeSamplingProfileParams()) { }

    template<int STEP> GetAllTimeSamplingProfileParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAllTimeSamplingProfileParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAllTimeSamplingProfileParams> result_;
  };

  static GetAllTimeSamplingProfileParamsBuilder<0> Builder() {
    return GetAllTimeSamplingProfileParamsBuilder<0>();
  }

 private:
  GetAllTimeSamplingProfileParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetAllTimeSamplingProfileParams);
};


// Result for the GetAllTimeSamplingProfile command.
class HEADLESS_EXPORT GetAllTimeSamplingProfileResult {
 public:
  static std::unique_ptr<GetAllTimeSamplingProfileResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAllTimeSamplingProfileResult() { }

  const ::headless::memory::SamplingProfile* GetProfile() const { return profile_.get(); }
  void SetProfile(std::unique_ptr<::headless::memory::SamplingProfile> value) { profile_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAllTimeSamplingProfileResult> Clone() const;

  template<int STATE>
  class GetAllTimeSamplingProfileResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProfileSet = 1 << 1,
      kAllRequiredFieldsSet = (kProfileSet | 0)
    };

    GetAllTimeSamplingProfileResultBuilder<STATE | kProfileSet>& SetProfile(std::unique_ptr<::headless::memory::SamplingProfile> value) {
      static_assert(!(STATE & kProfileSet), "property profile should not have already been set");
      result_->SetProfile(std::move(value));
      return CastState<kProfileSet>();
    }

    std::unique_ptr<GetAllTimeSamplingProfileResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAllTimeSamplingProfileResult;
    GetAllTimeSamplingProfileResultBuilder() : result_(new GetAllTimeSamplingProfileResult()) { }

    template<int STEP> GetAllTimeSamplingProfileResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAllTimeSamplingProfileResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAllTimeSamplingProfileResult> result_;
  };

  static GetAllTimeSamplingProfileResultBuilder<0> Builder() {
    return GetAllTimeSamplingProfileResultBuilder<0>();
  }

 private:
  GetAllTimeSamplingProfileResult() { }

  std::unique_ptr<::headless::memory::SamplingProfile> profile_;

  DISALLOW_COPY_AND_ASSIGN(GetAllTimeSamplingProfileResult);
};


// Parameters for the GetBrowserSamplingProfile command.
class HEADLESS_EXPORT GetBrowserSamplingProfileParams {
 public:
  static std::unique_ptr<GetBrowserSamplingProfileParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBrowserSamplingProfileParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBrowserSamplingProfileParams> Clone() const;

  template<int STATE>
  class GetBrowserSamplingProfileParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetBrowserSamplingProfileParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBrowserSamplingProfileParams;
    GetBrowserSamplingProfileParamsBuilder() : result_(new GetBrowserSamplingProfileParams()) { }

    template<int STEP> GetBrowserSamplingProfileParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBrowserSamplingProfileParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBrowserSamplingProfileParams> result_;
  };

  static GetBrowserSamplingProfileParamsBuilder<0> Builder() {
    return GetBrowserSamplingProfileParamsBuilder<0>();
  }

 private:
  GetBrowserSamplingProfileParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetBrowserSamplingProfileParams);
};


// Result for the GetBrowserSamplingProfile command.
class HEADLESS_EXPORT GetBrowserSamplingProfileResult {
 public:
  static std::unique_ptr<GetBrowserSamplingProfileResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBrowserSamplingProfileResult() { }

  const ::headless::memory::SamplingProfile* GetProfile() const { return profile_.get(); }
  void SetProfile(std::unique_ptr<::headless::memory::SamplingProfile> value) { profile_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBrowserSamplingProfileResult> Clone() const;

  template<int STATE>
  class GetBrowserSamplingProfileResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProfileSet = 1 << 1,
      kAllRequiredFieldsSet = (kProfileSet | 0)
    };

    GetBrowserSamplingProfileResultBuilder<STATE | kProfileSet>& SetProfile(std::unique_ptr<::headless::memory::SamplingProfile> value) {
      static_assert(!(STATE & kProfileSet), "property profile should not have already been set");
      result_->SetProfile(std::move(value));
      return CastState<kProfileSet>();
    }

    std::unique_ptr<GetBrowserSamplingProfileResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBrowserSamplingProfileResult;
    GetBrowserSamplingProfileResultBuilder() : result_(new GetBrowserSamplingProfileResult()) { }

    template<int STEP> GetBrowserSamplingProfileResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBrowserSamplingProfileResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBrowserSamplingProfileResult> result_;
  };

  static GetBrowserSamplingProfileResultBuilder<0> Builder() {
    return GetBrowserSamplingProfileResultBuilder<0>();
  }

 private:
  GetBrowserSamplingProfileResult() { }

  std::unique_ptr<::headless::memory::SamplingProfile> profile_;

  DISALLOW_COPY_AND_ASSIGN(GetBrowserSamplingProfileResult);
};


// Parameters for the GetSamplingProfile command.
class HEADLESS_EXPORT GetSamplingProfileParams {
 public:
  static std::unique_ptr<GetSamplingProfileParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetSamplingProfileParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetSamplingProfileParams> Clone() const;

  template<int STATE>
  class GetSamplingProfileParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetSamplingProfileParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetSamplingProfileParams;
    GetSamplingProfileParamsBuilder() : result_(new GetSamplingProfileParams()) { }

    template<int STEP> GetSamplingProfileParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetSamplingProfileParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetSamplingProfileParams> result_;
  };

  static GetSamplingProfileParamsBuilder<0> Builder() {
    return GetSamplingProfileParamsBuilder<0>();
  }

 private:
  GetSamplingProfileParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetSamplingProfileParams);
};


// Result for the GetSamplingProfile command.
class HEADLESS_EXPORT GetSamplingProfileResult {
 public:
  static std::unique_ptr<GetSamplingProfileResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetSamplingProfileResult() { }

  const ::headless::memory::SamplingProfile* GetProfile() const { return profile_.get(); }
  void SetProfile(std::unique_ptr<::headless::memory::SamplingProfile> value) { profile_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetSamplingProfileResult> Clone() const;

  template<int STATE>
  class GetSamplingProfileResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProfileSet = 1 << 1,
      kAllRequiredFieldsSet = (kProfileSet | 0)
    };

    GetSamplingProfileResultBuilder<STATE | kProfileSet>& SetProfile(std::unique_ptr<::headless::memory::SamplingProfile> value) {
      static_assert(!(STATE & kProfileSet), "property profile should not have already been set");
      result_->SetProfile(std::move(value));
      return CastState<kProfileSet>();
    }

    std::unique_ptr<GetSamplingProfileResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetSamplingProfileResult;
    GetSamplingProfileResultBuilder() : result_(new GetSamplingProfileResult()) { }

    template<int STEP> GetSamplingProfileResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetSamplingProfileResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetSamplingProfileResult> result_;
  };

  static GetSamplingProfileResultBuilder<0> Builder() {
    return GetSamplingProfileResultBuilder<0>();
  }

 private:
  GetSamplingProfileResult() { }

  std::unique_ptr<::headless::memory::SamplingProfile> profile_;

  DISALLOW_COPY_AND_ASSIGN(GetSamplingProfileResult);
};


}  // namespace memory

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_MEMORY_H_
