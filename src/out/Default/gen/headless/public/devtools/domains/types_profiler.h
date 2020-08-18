// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PROFILER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PROFILER_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_profiler.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace profiler {

// Profile node. Holds callsite information, execution statistics and child nodes.
class HEADLESS_EXPORT ProfileNode {
 public:
  static std::unique_ptr<ProfileNode> Parse(const base::Value& value, ErrorReporter* errors);
  ~ProfileNode() { }

  // Unique id of the node.
  int GetId() const { return id_; }
  void SetId(int value) { id_ = value; }

  // Function location.
  const ::headless::runtime::CallFrame* GetCallFrame() const { return call_frame_.get(); }
  void SetCallFrame(std::unique_ptr<::headless::runtime::CallFrame> value) { call_frame_ = std::move(value); }

  // Number of samples where this node was on top of the call stack.
  bool HasHitCount() const { return !!hit_count_; }
  int GetHitCount() const { DCHECK(HasHitCount()); return hit_count_.value(); }
  void SetHitCount(int value) { hit_count_ = value; }

  // Child node ids.
  bool HasChildren() const { return !!children_; }
  const std::vector<int>* GetChildren() const { DCHECK(HasChildren()); return &children_.value(); }
  void SetChildren(std::vector<int> value) { children_ = std::move(value); }

  // The reason of being not optimized. The function may be deoptimized or marked as don't
  // optimize.
  bool HasDeoptReason() const { return !!deopt_reason_; }
  std::string GetDeoptReason() const { DCHECK(HasDeoptReason()); return deopt_reason_.value(); }
  void SetDeoptReason(const std::string& value) { deopt_reason_ = value; }

  // An array of source position ticks.
  bool HasPositionTicks() const { return !!position_ticks_; }
  const std::vector<std::unique_ptr<::headless::profiler::PositionTickInfo>>* GetPositionTicks() const { DCHECK(HasPositionTicks()); return &position_ticks_.value(); }
  void SetPositionTicks(std::vector<std::unique_ptr<::headless::profiler::PositionTickInfo>> value) { position_ticks_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ProfileNode> Clone() const;

  template<int STATE>
  class ProfileNodeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kCallFrameSet = 1 << 2,
      kAllRequiredFieldsSet = (kIdSet | kCallFrameSet | 0)
    };

    ProfileNodeBuilder<STATE | kIdSet>& SetId(int value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    ProfileNodeBuilder<STATE | kCallFrameSet>& SetCallFrame(std::unique_ptr<::headless::runtime::CallFrame> value) {
      static_assert(!(STATE & kCallFrameSet), "property callFrame should not have already been set");
      result_->SetCallFrame(std::move(value));
      return CastState<kCallFrameSet>();
    }

    ProfileNodeBuilder<STATE>& SetHitCount(int value) {
      result_->SetHitCount(value);
      return *this;
    }

    ProfileNodeBuilder<STATE>& SetChildren(std::vector<int> value) {
      result_->SetChildren(std::move(value));
      return *this;
    }

    ProfileNodeBuilder<STATE>& SetDeoptReason(const std::string& value) {
      result_->SetDeoptReason(value);
      return *this;
    }

    ProfileNodeBuilder<STATE>& SetPositionTicks(std::vector<std::unique_ptr<::headless::profiler::PositionTickInfo>> value) {
      result_->SetPositionTicks(std::move(value));
      return *this;
    }

    std::unique_ptr<ProfileNode> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ProfileNode;
    ProfileNodeBuilder() : result_(new ProfileNode()) { }

    template<int STEP> ProfileNodeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ProfileNodeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ProfileNode> result_;
  };

  static ProfileNodeBuilder<0> Builder() {
    return ProfileNodeBuilder<0>();
  }

 private:
  ProfileNode() { }

  int id_;
  std::unique_ptr<::headless::runtime::CallFrame> call_frame_;
  base::Optional<int> hit_count_;
  base::Optional<std::vector<int>> children_;
  base::Optional<std::string> deopt_reason_;
  base::Optional<std::vector<std::unique_ptr<::headless::profiler::PositionTickInfo>>> position_ticks_;

  DISALLOW_COPY_AND_ASSIGN(ProfileNode);
};


// Profile.
class HEADLESS_EXPORT Profile {
 public:
  static std::unique_ptr<Profile> Parse(const base::Value& value, ErrorReporter* errors);
  ~Profile() { }

  // The list of profile nodes. First item is the root node.
  const std::vector<std::unique_ptr<::headless::profiler::ProfileNode>>* GetNodes() const { return &nodes_; }
  void SetNodes(std::vector<std::unique_ptr<::headless::profiler::ProfileNode>> value) { nodes_ = std::move(value); }

  // Profiling start timestamp in microseconds.
  double GetStartTime() const { return start_time_; }
  void SetStartTime(double value) { start_time_ = value; }

  // Profiling end timestamp in microseconds.
  double GetEndTime() const { return end_time_; }
  void SetEndTime(double value) { end_time_ = value; }

  // Ids of samples top nodes.
  bool HasSamples() const { return !!samples_; }
  const std::vector<int>* GetSamples() const { DCHECK(HasSamples()); return &samples_.value(); }
  void SetSamples(std::vector<int> value) { samples_ = std::move(value); }

  // Time intervals between adjacent samples in microseconds. The first delta is relative to the
  // profile startTime.
  bool HasTimeDeltas() const { return !!time_deltas_; }
  const std::vector<int>* GetTimeDeltas() const { DCHECK(HasTimeDeltas()); return &time_deltas_.value(); }
  void SetTimeDeltas(std::vector<int> value) { time_deltas_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Profile> Clone() const;

  template<int STATE>
  class ProfileBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodesSet = 1 << 1,
    kStartTimeSet = 1 << 2,
    kEndTimeSet = 1 << 3,
      kAllRequiredFieldsSet = (kNodesSet | kStartTimeSet | kEndTimeSet | 0)
    };

    ProfileBuilder<STATE | kNodesSet>& SetNodes(std::vector<std::unique_ptr<::headless::profiler::ProfileNode>> value) {
      static_assert(!(STATE & kNodesSet), "property nodes should not have already been set");
      result_->SetNodes(std::move(value));
      return CastState<kNodesSet>();
    }

    ProfileBuilder<STATE | kStartTimeSet>& SetStartTime(double value) {
      static_assert(!(STATE & kStartTimeSet), "property startTime should not have already been set");
      result_->SetStartTime(value);
      return CastState<kStartTimeSet>();
    }

    ProfileBuilder<STATE | kEndTimeSet>& SetEndTime(double value) {
      static_assert(!(STATE & kEndTimeSet), "property endTime should not have already been set");
      result_->SetEndTime(value);
      return CastState<kEndTimeSet>();
    }

    ProfileBuilder<STATE>& SetSamples(std::vector<int> value) {
      result_->SetSamples(std::move(value));
      return *this;
    }

    ProfileBuilder<STATE>& SetTimeDeltas(std::vector<int> value) {
      result_->SetTimeDeltas(std::move(value));
      return *this;
    }

    std::unique_ptr<Profile> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Profile;
    ProfileBuilder() : result_(new Profile()) { }

    template<int STEP> ProfileBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ProfileBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Profile> result_;
  };

  static ProfileBuilder<0> Builder() {
    return ProfileBuilder<0>();
  }

 private:
  Profile() { }

  std::vector<std::unique_ptr<::headless::profiler::ProfileNode>> nodes_;
  double start_time_;
  double end_time_;
  base::Optional<std::vector<int>> samples_;
  base::Optional<std::vector<int>> time_deltas_;

  DISALLOW_COPY_AND_ASSIGN(Profile);
};


// Specifies a number of samples attributed to a certain source position.
class HEADLESS_EXPORT PositionTickInfo {
 public:
  static std::unique_ptr<PositionTickInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~PositionTickInfo() { }

  // Source line number (1-based).
  int GetLine() const { return line_; }
  void SetLine(int value) { line_ = value; }

  // Number of samples attributed to the source line.
  int GetTicks() const { return ticks_; }
  void SetTicks(int value) { ticks_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PositionTickInfo> Clone() const;

  template<int STATE>
  class PositionTickInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLineSet = 1 << 1,
    kTicksSet = 1 << 2,
      kAllRequiredFieldsSet = (kLineSet | kTicksSet | 0)
    };

    PositionTickInfoBuilder<STATE | kLineSet>& SetLine(int value) {
      static_assert(!(STATE & kLineSet), "property line should not have already been set");
      result_->SetLine(value);
      return CastState<kLineSet>();
    }

    PositionTickInfoBuilder<STATE | kTicksSet>& SetTicks(int value) {
      static_assert(!(STATE & kTicksSet), "property ticks should not have already been set");
      result_->SetTicks(value);
      return CastState<kTicksSet>();
    }

    std::unique_ptr<PositionTickInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PositionTickInfo;
    PositionTickInfoBuilder() : result_(new PositionTickInfo()) { }

    template<int STEP> PositionTickInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PositionTickInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PositionTickInfo> result_;
  };

  static PositionTickInfoBuilder<0> Builder() {
    return PositionTickInfoBuilder<0>();
  }

 private:
  PositionTickInfo() { }

  int line_;
  int ticks_;

  DISALLOW_COPY_AND_ASSIGN(PositionTickInfo);
};


// Coverage data for a source range.
class HEADLESS_EXPORT CoverageRange {
 public:
  static std::unique_ptr<CoverageRange> Parse(const base::Value& value, ErrorReporter* errors);
  ~CoverageRange() { }

  // JavaScript script source offset for the range start.
  int GetStartOffset() const { return start_offset_; }
  void SetStartOffset(int value) { start_offset_ = value; }

  // JavaScript script source offset for the range end.
  int GetEndOffset() const { return end_offset_; }
  void SetEndOffset(int value) { end_offset_ = value; }

  // Collected execution count of the source range.
  int GetCount() const { return count_; }
  void SetCount(int value) { count_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CoverageRange> Clone() const;

  template<int STATE>
  class CoverageRangeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStartOffsetSet = 1 << 1,
    kEndOffsetSet = 1 << 2,
    kCountSet = 1 << 3,
      kAllRequiredFieldsSet = (kStartOffsetSet | kEndOffsetSet | kCountSet | 0)
    };

    CoverageRangeBuilder<STATE | kStartOffsetSet>& SetStartOffset(int value) {
      static_assert(!(STATE & kStartOffsetSet), "property startOffset should not have already been set");
      result_->SetStartOffset(value);
      return CastState<kStartOffsetSet>();
    }

    CoverageRangeBuilder<STATE | kEndOffsetSet>& SetEndOffset(int value) {
      static_assert(!(STATE & kEndOffsetSet), "property endOffset should not have already been set");
      result_->SetEndOffset(value);
      return CastState<kEndOffsetSet>();
    }

    CoverageRangeBuilder<STATE | kCountSet>& SetCount(int value) {
      static_assert(!(STATE & kCountSet), "property count should not have already been set");
      result_->SetCount(value);
      return CastState<kCountSet>();
    }

    std::unique_ptr<CoverageRange> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CoverageRange;
    CoverageRangeBuilder() : result_(new CoverageRange()) { }

    template<int STEP> CoverageRangeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CoverageRangeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CoverageRange> result_;
  };

  static CoverageRangeBuilder<0> Builder() {
    return CoverageRangeBuilder<0>();
  }

 private:
  CoverageRange() { }

  int start_offset_;
  int end_offset_;
  int count_;

  DISALLOW_COPY_AND_ASSIGN(CoverageRange);
};


// Coverage data for a JavaScript function.
class HEADLESS_EXPORT FunctionCoverage {
 public:
  static std::unique_ptr<FunctionCoverage> Parse(const base::Value& value, ErrorReporter* errors);
  ~FunctionCoverage() { }

  // JavaScript function name.
  std::string GetFunctionName() const { return function_name_; }
  void SetFunctionName(const std::string& value) { function_name_ = value; }

  // Source ranges inside the function with coverage data.
  const std::vector<std::unique_ptr<::headless::profiler::CoverageRange>>* GetRanges() const { return &ranges_; }
  void SetRanges(std::vector<std::unique_ptr<::headless::profiler::CoverageRange>> value) { ranges_ = std::move(value); }

  // Whether coverage data for this function has block granularity.
  bool GetIsBlockCoverage() const { return is_block_coverage_; }
  void SetIsBlockCoverage(bool value) { is_block_coverage_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FunctionCoverage> Clone() const;

  template<int STATE>
  class FunctionCoverageBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFunctionNameSet = 1 << 1,
    kRangesSet = 1 << 2,
    kIsBlockCoverageSet = 1 << 3,
      kAllRequiredFieldsSet = (kFunctionNameSet | kRangesSet | kIsBlockCoverageSet | 0)
    };

    FunctionCoverageBuilder<STATE | kFunctionNameSet>& SetFunctionName(const std::string& value) {
      static_assert(!(STATE & kFunctionNameSet), "property functionName should not have already been set");
      result_->SetFunctionName(value);
      return CastState<kFunctionNameSet>();
    }

    FunctionCoverageBuilder<STATE | kRangesSet>& SetRanges(std::vector<std::unique_ptr<::headless::profiler::CoverageRange>> value) {
      static_assert(!(STATE & kRangesSet), "property ranges should not have already been set");
      result_->SetRanges(std::move(value));
      return CastState<kRangesSet>();
    }

    FunctionCoverageBuilder<STATE | kIsBlockCoverageSet>& SetIsBlockCoverage(bool value) {
      static_assert(!(STATE & kIsBlockCoverageSet), "property isBlockCoverage should not have already been set");
      result_->SetIsBlockCoverage(value);
      return CastState<kIsBlockCoverageSet>();
    }

    std::unique_ptr<FunctionCoverage> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FunctionCoverage;
    FunctionCoverageBuilder() : result_(new FunctionCoverage()) { }

    template<int STEP> FunctionCoverageBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FunctionCoverageBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FunctionCoverage> result_;
  };

  static FunctionCoverageBuilder<0> Builder() {
    return FunctionCoverageBuilder<0>();
  }

 private:
  FunctionCoverage() { }

  std::string function_name_;
  std::vector<std::unique_ptr<::headless::profiler::CoverageRange>> ranges_;
  bool is_block_coverage_;

  DISALLOW_COPY_AND_ASSIGN(FunctionCoverage);
};


// Coverage data for a JavaScript script.
class HEADLESS_EXPORT ScriptCoverage {
 public:
  static std::unique_ptr<ScriptCoverage> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScriptCoverage() { }

  // JavaScript script id.
  std::string GetScriptId() const { return script_id_; }
  void SetScriptId(const std::string& value) { script_id_ = value; }

  // JavaScript script name or url.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Functions contained in the script that has coverage data.
  const std::vector<std::unique_ptr<::headless::profiler::FunctionCoverage>>* GetFunctions() const { return &functions_; }
  void SetFunctions(std::vector<std::unique_ptr<::headless::profiler::FunctionCoverage>> value) { functions_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScriptCoverage> Clone() const;

  template<int STATE>
  class ScriptCoverageBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kScriptIdSet = 1 << 1,
    kUrlSet = 1 << 2,
    kFunctionsSet = 1 << 3,
      kAllRequiredFieldsSet = (kScriptIdSet | kUrlSet | kFunctionsSet | 0)
    };

    ScriptCoverageBuilder<STATE | kScriptIdSet>& SetScriptId(const std::string& value) {
      static_assert(!(STATE & kScriptIdSet), "property scriptId should not have already been set");
      result_->SetScriptId(value);
      return CastState<kScriptIdSet>();
    }

    ScriptCoverageBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    ScriptCoverageBuilder<STATE | kFunctionsSet>& SetFunctions(std::vector<std::unique_ptr<::headless::profiler::FunctionCoverage>> value) {
      static_assert(!(STATE & kFunctionsSet), "property functions should not have already been set");
      result_->SetFunctions(std::move(value));
      return CastState<kFunctionsSet>();
    }

    std::unique_ptr<ScriptCoverage> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScriptCoverage;
    ScriptCoverageBuilder() : result_(new ScriptCoverage()) { }

    template<int STEP> ScriptCoverageBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScriptCoverageBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScriptCoverage> result_;
  };

  static ScriptCoverageBuilder<0> Builder() {
    return ScriptCoverageBuilder<0>();
  }

 private:
  ScriptCoverage() { }

  std::string script_id_;
  std::string url_;
  std::vector<std::unique_ptr<::headless::profiler::FunctionCoverage>> functions_;

  DISALLOW_COPY_AND_ASSIGN(ScriptCoverage);
};


// Describes a type collected during runtime.
class HEADLESS_EXPORT TypeObject {
 public:
  static std::unique_ptr<TypeObject> Parse(const base::Value& value, ErrorReporter* errors);
  ~TypeObject() { }

  // Name of a type collected with type profiling.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TypeObject> Clone() const;

  template<int STATE>
  class TypeObjectBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
      kAllRequiredFieldsSet = (kNameSet | 0)
    };

    TypeObjectBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    std::unique_ptr<TypeObject> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TypeObject;
    TypeObjectBuilder() : result_(new TypeObject()) { }

    template<int STEP> TypeObjectBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TypeObjectBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TypeObject> result_;
  };

  static TypeObjectBuilder<0> Builder() {
    return TypeObjectBuilder<0>();
  }

 private:
  TypeObject() { }

  std::string name_;

  DISALLOW_COPY_AND_ASSIGN(TypeObject);
};


// Source offset and types for a parameter or return value.
class HEADLESS_EXPORT TypeProfileEntry {
 public:
  static std::unique_ptr<TypeProfileEntry> Parse(const base::Value& value, ErrorReporter* errors);
  ~TypeProfileEntry() { }

  // Source offset of the parameter or end of function for return values.
  int GetOffset() const { return offset_; }
  void SetOffset(int value) { offset_ = value; }

  // The types for this parameter or return value.
  const std::vector<std::unique_ptr<::headless::profiler::TypeObject>>* GetTypes() const { return &types_; }
  void SetTypes(std::vector<std::unique_ptr<::headless::profiler::TypeObject>> value) { types_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TypeProfileEntry> Clone() const;

  template<int STATE>
  class TypeProfileEntryBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOffsetSet = 1 << 1,
    kTypesSet = 1 << 2,
      kAllRequiredFieldsSet = (kOffsetSet | kTypesSet | 0)
    };

    TypeProfileEntryBuilder<STATE | kOffsetSet>& SetOffset(int value) {
      static_assert(!(STATE & kOffsetSet), "property offset should not have already been set");
      result_->SetOffset(value);
      return CastState<kOffsetSet>();
    }

    TypeProfileEntryBuilder<STATE | kTypesSet>& SetTypes(std::vector<std::unique_ptr<::headless::profiler::TypeObject>> value) {
      static_assert(!(STATE & kTypesSet), "property types should not have already been set");
      result_->SetTypes(std::move(value));
      return CastState<kTypesSet>();
    }

    std::unique_ptr<TypeProfileEntry> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TypeProfileEntry;
    TypeProfileEntryBuilder() : result_(new TypeProfileEntry()) { }

    template<int STEP> TypeProfileEntryBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TypeProfileEntryBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TypeProfileEntry> result_;
  };

  static TypeProfileEntryBuilder<0> Builder() {
    return TypeProfileEntryBuilder<0>();
  }

 private:
  TypeProfileEntry() { }

  int offset_;
  std::vector<std::unique_ptr<::headless::profiler::TypeObject>> types_;

  DISALLOW_COPY_AND_ASSIGN(TypeProfileEntry);
};


// Type profile data collected during runtime for a JavaScript script.
class HEADLESS_EXPORT ScriptTypeProfile {
 public:
  static std::unique_ptr<ScriptTypeProfile> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScriptTypeProfile() { }

  // JavaScript script id.
  std::string GetScriptId() const { return script_id_; }
  void SetScriptId(const std::string& value) { script_id_ = value; }

  // JavaScript script name or url.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Type profile entries for parameters and return values of the functions in the script.
  const std::vector<std::unique_ptr<::headless::profiler::TypeProfileEntry>>* GetEntries() const { return &entries_; }
  void SetEntries(std::vector<std::unique_ptr<::headless::profiler::TypeProfileEntry>> value) { entries_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScriptTypeProfile> Clone() const;

  template<int STATE>
  class ScriptTypeProfileBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kScriptIdSet = 1 << 1,
    kUrlSet = 1 << 2,
    kEntriesSet = 1 << 3,
      kAllRequiredFieldsSet = (kScriptIdSet | kUrlSet | kEntriesSet | 0)
    };

    ScriptTypeProfileBuilder<STATE | kScriptIdSet>& SetScriptId(const std::string& value) {
      static_assert(!(STATE & kScriptIdSet), "property scriptId should not have already been set");
      result_->SetScriptId(value);
      return CastState<kScriptIdSet>();
    }

    ScriptTypeProfileBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    ScriptTypeProfileBuilder<STATE | kEntriesSet>& SetEntries(std::vector<std::unique_ptr<::headless::profiler::TypeProfileEntry>> value) {
      static_assert(!(STATE & kEntriesSet), "property entries should not have already been set");
      result_->SetEntries(std::move(value));
      return CastState<kEntriesSet>();
    }

    std::unique_ptr<ScriptTypeProfile> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScriptTypeProfile;
    ScriptTypeProfileBuilder() : result_(new ScriptTypeProfile()) { }

    template<int STEP> ScriptTypeProfileBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScriptTypeProfileBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScriptTypeProfile> result_;
  };

  static ScriptTypeProfileBuilder<0> Builder() {
    return ScriptTypeProfileBuilder<0>();
  }

 private:
  ScriptTypeProfile() { }

  std::string script_id_;
  std::string url_;
  std::vector<std::unique_ptr<::headless::profiler::TypeProfileEntry>> entries_;

  DISALLOW_COPY_AND_ASSIGN(ScriptTypeProfile);
};


// Collected counter information.
class HEADLESS_EXPORT CounterInfo {
 public:
  static std::unique_ptr<CounterInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~CounterInfo() { }

  // Counter name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Counter value.
  int GetValue() const { return value_; }
  void SetValue(int value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CounterInfo> Clone() const;

  template<int STATE>
  class CounterInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    CounterInfoBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    CounterInfoBuilder<STATE | kValueSet>& SetValue(int value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<CounterInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CounterInfo;
    CounterInfoBuilder() : result_(new CounterInfo()) { }

    template<int STEP> CounterInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CounterInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CounterInfo> result_;
  };

  static CounterInfoBuilder<0> Builder() {
    return CounterInfoBuilder<0>();
  }

 private:
  CounterInfo() { }

  std::string name_;
  int value_;

  DISALLOW_COPY_AND_ASSIGN(CounterInfo);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the GetBestEffortCoverage command.
class HEADLESS_EXPORT GetBestEffortCoverageParams {
 public:
  static std::unique_ptr<GetBestEffortCoverageParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBestEffortCoverageParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBestEffortCoverageParams> Clone() const;

  template<int STATE>
  class GetBestEffortCoverageParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetBestEffortCoverageParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBestEffortCoverageParams;
    GetBestEffortCoverageParamsBuilder() : result_(new GetBestEffortCoverageParams()) { }

    template<int STEP> GetBestEffortCoverageParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBestEffortCoverageParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBestEffortCoverageParams> result_;
  };

  static GetBestEffortCoverageParamsBuilder<0> Builder() {
    return GetBestEffortCoverageParamsBuilder<0>();
  }

 private:
  GetBestEffortCoverageParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetBestEffortCoverageParams);
};


// Result for the GetBestEffortCoverage command.
class HEADLESS_EXPORT GetBestEffortCoverageResult {
 public:
  static std::unique_ptr<GetBestEffortCoverageResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetBestEffortCoverageResult() { }

  // Coverage data for the current isolate.
  const std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> value) { result_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetBestEffortCoverageResult> Clone() const;

  template<int STATE>
  class GetBestEffortCoverageResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    GetBestEffortCoverageResultBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    std::unique_ptr<GetBestEffortCoverageResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetBestEffortCoverageResult;
    GetBestEffortCoverageResultBuilder() : result_(new GetBestEffortCoverageResult()) { }

    template<int STEP> GetBestEffortCoverageResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetBestEffortCoverageResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetBestEffortCoverageResult> result_;
  };

  static GetBestEffortCoverageResultBuilder<0> Builder() {
    return GetBestEffortCoverageResultBuilder<0>();
  }

 private:
  GetBestEffortCoverageResult() { }

  std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> result_;

  DISALLOW_COPY_AND_ASSIGN(GetBestEffortCoverageResult);
};


// Parameters for the SetSamplingInterval command.
class HEADLESS_EXPORT SetSamplingIntervalParams {
 public:
  static std::unique_ptr<SetSamplingIntervalParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetSamplingIntervalParams() { }

  // New sampling interval in microseconds.
  int GetInterval() const { return interval_; }
  void SetInterval(int value) { interval_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetSamplingIntervalParams> Clone() const;

  template<int STATE>
  class SetSamplingIntervalParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIntervalSet = 1 << 1,
      kAllRequiredFieldsSet = (kIntervalSet | 0)
    };

    SetSamplingIntervalParamsBuilder<STATE | kIntervalSet>& SetInterval(int value) {
      static_assert(!(STATE & kIntervalSet), "property interval should not have already been set");
      result_->SetInterval(value);
      return CastState<kIntervalSet>();
    }

    std::unique_ptr<SetSamplingIntervalParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetSamplingIntervalParams;
    SetSamplingIntervalParamsBuilder() : result_(new SetSamplingIntervalParams()) { }

    template<int STEP> SetSamplingIntervalParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetSamplingIntervalParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetSamplingIntervalParams> result_;
  };

  static SetSamplingIntervalParamsBuilder<0> Builder() {
    return SetSamplingIntervalParamsBuilder<0>();
  }

 private:
  SetSamplingIntervalParams() { }

  int interval_;

  DISALLOW_COPY_AND_ASSIGN(SetSamplingIntervalParams);
};


// Result for the SetSamplingInterval command.
class HEADLESS_EXPORT SetSamplingIntervalResult {
 public:
  static std::unique_ptr<SetSamplingIntervalResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetSamplingIntervalResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetSamplingIntervalResult> Clone() const;

  template<int STATE>
  class SetSamplingIntervalResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetSamplingIntervalResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetSamplingIntervalResult;
    SetSamplingIntervalResultBuilder() : result_(new SetSamplingIntervalResult()) { }

    template<int STEP> SetSamplingIntervalResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetSamplingIntervalResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetSamplingIntervalResult> result_;
  };

  static SetSamplingIntervalResultBuilder<0> Builder() {
    return SetSamplingIntervalResultBuilder<0>();
  }

 private:
  SetSamplingIntervalResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetSamplingIntervalResult);
};


// Parameters for the Start command.
class HEADLESS_EXPORT StartParams {
 public:
  static std::unique_ptr<StartParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartParams> Clone() const;

  template<int STATE>
  class StartParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartParams;
    StartParamsBuilder() : result_(new StartParams()) { }

    template<int STEP> StartParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartParams> result_;
  };

  static StartParamsBuilder<0> Builder() {
    return StartParamsBuilder<0>();
  }

 private:
  StartParams() { }


  DISALLOW_COPY_AND_ASSIGN(StartParams);
};


// Result for the Start command.
class HEADLESS_EXPORT StartResult {
 public:
  static std::unique_ptr<StartResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartResult> Clone() const;

  template<int STATE>
  class StartResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartResult;
    StartResultBuilder() : result_(new StartResult()) { }

    template<int STEP> StartResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartResult> result_;
  };

  static StartResultBuilder<0> Builder() {
    return StartResultBuilder<0>();
  }

 private:
  StartResult() { }


  DISALLOW_COPY_AND_ASSIGN(StartResult);
};


// Parameters for the StartPreciseCoverage command.
class HEADLESS_EXPORT StartPreciseCoverageParams {
 public:
  static std::unique_ptr<StartPreciseCoverageParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartPreciseCoverageParams() { }

  // Collect accurate call counts beyond simple 'covered' or 'not covered'.
  bool HasCallCount() const { return !!call_count_; }
  bool GetCallCount() const { DCHECK(HasCallCount()); return call_count_.value(); }
  void SetCallCount(bool value) { call_count_ = value; }

  // Collect block-based coverage.
  bool HasDetailed() const { return !!detailed_; }
  bool GetDetailed() const { DCHECK(HasDetailed()); return detailed_.value(); }
  void SetDetailed(bool value) { detailed_ = value; }

  // Allow the backend to send updates on its own initiative
  bool HasAllowTriggeredUpdates() const { return !!allow_triggered_updates_; }
  bool GetAllowTriggeredUpdates() const { DCHECK(HasAllowTriggeredUpdates()); return allow_triggered_updates_.value(); }
  void SetAllowTriggeredUpdates(bool value) { allow_triggered_updates_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartPreciseCoverageParams> Clone() const;

  template<int STATE>
  class StartPreciseCoverageParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    StartPreciseCoverageParamsBuilder<STATE>& SetCallCount(bool value) {
      result_->SetCallCount(value);
      return *this;
    }

    StartPreciseCoverageParamsBuilder<STATE>& SetDetailed(bool value) {
      result_->SetDetailed(value);
      return *this;
    }

    StartPreciseCoverageParamsBuilder<STATE>& SetAllowTriggeredUpdates(bool value) {
      result_->SetAllowTriggeredUpdates(value);
      return *this;
    }

    std::unique_ptr<StartPreciseCoverageParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartPreciseCoverageParams;
    StartPreciseCoverageParamsBuilder() : result_(new StartPreciseCoverageParams()) { }

    template<int STEP> StartPreciseCoverageParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartPreciseCoverageParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartPreciseCoverageParams> result_;
  };

  static StartPreciseCoverageParamsBuilder<0> Builder() {
    return StartPreciseCoverageParamsBuilder<0>();
  }

 private:
  StartPreciseCoverageParams() { }

  base::Optional<bool> call_count_;
  base::Optional<bool> detailed_;
  base::Optional<bool> allow_triggered_updates_;

  DISALLOW_COPY_AND_ASSIGN(StartPreciseCoverageParams);
};


// Result for the StartPreciseCoverage command.
class HEADLESS_EXPORT StartPreciseCoverageResult {
 public:
  static std::unique_ptr<StartPreciseCoverageResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartPreciseCoverageResult() { }

  // Monotonically increasing time (in seconds) when the coverage update was taken in the backend.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartPreciseCoverageResult> Clone() const;

  template<int STATE>
  class StartPreciseCoverageResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimestampSet = 1 << 1,
      kAllRequiredFieldsSet = (kTimestampSet | 0)
    };

    StartPreciseCoverageResultBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    std::unique_ptr<StartPreciseCoverageResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartPreciseCoverageResult;
    StartPreciseCoverageResultBuilder() : result_(new StartPreciseCoverageResult()) { }

    template<int STEP> StartPreciseCoverageResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartPreciseCoverageResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartPreciseCoverageResult> result_;
  };

  static StartPreciseCoverageResultBuilder<0> Builder() {
    return StartPreciseCoverageResultBuilder<0>();
  }

 private:
  StartPreciseCoverageResult() { }

  double timestamp_;

  DISALLOW_COPY_AND_ASSIGN(StartPreciseCoverageResult);
};


// Parameters for the StartTypeProfile command.
class HEADLESS_EXPORT StartTypeProfileParams {
 public:
  static std::unique_ptr<StartTypeProfileParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartTypeProfileParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartTypeProfileParams> Clone() const;

  template<int STATE>
  class StartTypeProfileParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartTypeProfileParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartTypeProfileParams;
    StartTypeProfileParamsBuilder() : result_(new StartTypeProfileParams()) { }

    template<int STEP> StartTypeProfileParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartTypeProfileParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartTypeProfileParams> result_;
  };

  static StartTypeProfileParamsBuilder<0> Builder() {
    return StartTypeProfileParamsBuilder<0>();
  }

 private:
  StartTypeProfileParams() { }


  DISALLOW_COPY_AND_ASSIGN(StartTypeProfileParams);
};


// Result for the StartTypeProfile command.
class HEADLESS_EXPORT StartTypeProfileResult {
 public:
  static std::unique_ptr<StartTypeProfileResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartTypeProfileResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartTypeProfileResult> Clone() const;

  template<int STATE>
  class StartTypeProfileResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartTypeProfileResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartTypeProfileResult;
    StartTypeProfileResultBuilder() : result_(new StartTypeProfileResult()) { }

    template<int STEP> StartTypeProfileResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartTypeProfileResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartTypeProfileResult> result_;
  };

  static StartTypeProfileResultBuilder<0> Builder() {
    return StartTypeProfileResultBuilder<0>();
  }

 private:
  StartTypeProfileResult() { }


  DISALLOW_COPY_AND_ASSIGN(StartTypeProfileResult);
};


// Parameters for the Stop command.
class HEADLESS_EXPORT StopParams {
 public:
  static std::unique_ptr<StopParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopParams> Clone() const;

  template<int STATE>
  class StopParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopParams;
    StopParamsBuilder() : result_(new StopParams()) { }

    template<int STEP> StopParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopParams> result_;
  };

  static StopParamsBuilder<0> Builder() {
    return StopParamsBuilder<0>();
  }

 private:
  StopParams() { }


  DISALLOW_COPY_AND_ASSIGN(StopParams);
};


// Result for the Stop command.
class HEADLESS_EXPORT StopResult {
 public:
  static std::unique_ptr<StopResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopResult() { }

  // Recorded profile.
  const ::headless::profiler::Profile* GetProfile() const { return profile_.get(); }
  void SetProfile(std::unique_ptr<::headless::profiler::Profile> value) { profile_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopResult> Clone() const;

  template<int STATE>
  class StopResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProfileSet = 1 << 1,
      kAllRequiredFieldsSet = (kProfileSet | 0)
    };

    StopResultBuilder<STATE | kProfileSet>& SetProfile(std::unique_ptr<::headless::profiler::Profile> value) {
      static_assert(!(STATE & kProfileSet), "property profile should not have already been set");
      result_->SetProfile(std::move(value));
      return CastState<kProfileSet>();
    }

    std::unique_ptr<StopResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopResult;
    StopResultBuilder() : result_(new StopResult()) { }

    template<int STEP> StopResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopResult> result_;
  };

  static StopResultBuilder<0> Builder() {
    return StopResultBuilder<0>();
  }

 private:
  StopResult() { }

  std::unique_ptr<::headless::profiler::Profile> profile_;

  DISALLOW_COPY_AND_ASSIGN(StopResult);
};


// Parameters for the StopPreciseCoverage command.
class HEADLESS_EXPORT StopPreciseCoverageParams {
 public:
  static std::unique_ptr<StopPreciseCoverageParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopPreciseCoverageParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopPreciseCoverageParams> Clone() const;

  template<int STATE>
  class StopPreciseCoverageParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopPreciseCoverageParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopPreciseCoverageParams;
    StopPreciseCoverageParamsBuilder() : result_(new StopPreciseCoverageParams()) { }

    template<int STEP> StopPreciseCoverageParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopPreciseCoverageParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopPreciseCoverageParams> result_;
  };

  static StopPreciseCoverageParamsBuilder<0> Builder() {
    return StopPreciseCoverageParamsBuilder<0>();
  }

 private:
  StopPreciseCoverageParams() { }


  DISALLOW_COPY_AND_ASSIGN(StopPreciseCoverageParams);
};


// Result for the StopPreciseCoverage command.
class HEADLESS_EXPORT StopPreciseCoverageResult {
 public:
  static std::unique_ptr<StopPreciseCoverageResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopPreciseCoverageResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopPreciseCoverageResult> Clone() const;

  template<int STATE>
  class StopPreciseCoverageResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopPreciseCoverageResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopPreciseCoverageResult;
    StopPreciseCoverageResultBuilder() : result_(new StopPreciseCoverageResult()) { }

    template<int STEP> StopPreciseCoverageResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopPreciseCoverageResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopPreciseCoverageResult> result_;
  };

  static StopPreciseCoverageResultBuilder<0> Builder() {
    return StopPreciseCoverageResultBuilder<0>();
  }

 private:
  StopPreciseCoverageResult() { }


  DISALLOW_COPY_AND_ASSIGN(StopPreciseCoverageResult);
};


// Parameters for the StopTypeProfile command.
class HEADLESS_EXPORT StopTypeProfileParams {
 public:
  static std::unique_ptr<StopTypeProfileParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopTypeProfileParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopTypeProfileParams> Clone() const;

  template<int STATE>
  class StopTypeProfileParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopTypeProfileParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopTypeProfileParams;
    StopTypeProfileParamsBuilder() : result_(new StopTypeProfileParams()) { }

    template<int STEP> StopTypeProfileParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopTypeProfileParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopTypeProfileParams> result_;
  };

  static StopTypeProfileParamsBuilder<0> Builder() {
    return StopTypeProfileParamsBuilder<0>();
  }

 private:
  StopTypeProfileParams() { }


  DISALLOW_COPY_AND_ASSIGN(StopTypeProfileParams);
};


// Result for the StopTypeProfile command.
class HEADLESS_EXPORT StopTypeProfileResult {
 public:
  static std::unique_ptr<StopTypeProfileResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopTypeProfileResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopTypeProfileResult> Clone() const;

  template<int STATE>
  class StopTypeProfileResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopTypeProfileResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopTypeProfileResult;
    StopTypeProfileResultBuilder() : result_(new StopTypeProfileResult()) { }

    template<int STEP> StopTypeProfileResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopTypeProfileResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopTypeProfileResult> result_;
  };

  static StopTypeProfileResultBuilder<0> Builder() {
    return StopTypeProfileResultBuilder<0>();
  }

 private:
  StopTypeProfileResult() { }


  DISALLOW_COPY_AND_ASSIGN(StopTypeProfileResult);
};


// Parameters for the TakePreciseCoverage command.
class HEADLESS_EXPORT TakePreciseCoverageParams {
 public:
  static std::unique_ptr<TakePreciseCoverageParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakePreciseCoverageParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakePreciseCoverageParams> Clone() const;

  template<int STATE>
  class TakePreciseCoverageParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<TakePreciseCoverageParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakePreciseCoverageParams;
    TakePreciseCoverageParamsBuilder() : result_(new TakePreciseCoverageParams()) { }

    template<int STEP> TakePreciseCoverageParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakePreciseCoverageParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakePreciseCoverageParams> result_;
  };

  static TakePreciseCoverageParamsBuilder<0> Builder() {
    return TakePreciseCoverageParamsBuilder<0>();
  }

 private:
  TakePreciseCoverageParams() { }


  DISALLOW_COPY_AND_ASSIGN(TakePreciseCoverageParams);
};


// Result for the TakePreciseCoverage command.
class HEADLESS_EXPORT TakePreciseCoverageResult {
 public:
  static std::unique_ptr<TakePreciseCoverageResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakePreciseCoverageResult() { }

  // Coverage data for the current isolate.
  const std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> value) { result_ = std::move(value); }

  // Monotonically increasing time (in seconds) when the coverage update was taken in the backend.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakePreciseCoverageResult> Clone() const;

  template<int STATE>
  class TakePreciseCoverageResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
    kTimestampSet = 1 << 2,
      kAllRequiredFieldsSet = (kResultSet | kTimestampSet | 0)
    };

    TakePreciseCoverageResultBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    TakePreciseCoverageResultBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    std::unique_ptr<TakePreciseCoverageResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakePreciseCoverageResult;
    TakePreciseCoverageResultBuilder() : result_(new TakePreciseCoverageResult()) { }

    template<int STEP> TakePreciseCoverageResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakePreciseCoverageResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakePreciseCoverageResult> result_;
  };

  static TakePreciseCoverageResultBuilder<0> Builder() {
    return TakePreciseCoverageResultBuilder<0>();
  }

 private:
  TakePreciseCoverageResult() { }

  std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> result_;
  double timestamp_;

  DISALLOW_COPY_AND_ASSIGN(TakePreciseCoverageResult);
};


// Parameters for the TakeTypeProfile command.
class HEADLESS_EXPORT TakeTypeProfileParams {
 public:
  static std::unique_ptr<TakeTypeProfileParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakeTypeProfileParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakeTypeProfileParams> Clone() const;

  template<int STATE>
  class TakeTypeProfileParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<TakeTypeProfileParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakeTypeProfileParams;
    TakeTypeProfileParamsBuilder() : result_(new TakeTypeProfileParams()) { }

    template<int STEP> TakeTypeProfileParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakeTypeProfileParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakeTypeProfileParams> result_;
  };

  static TakeTypeProfileParamsBuilder<0> Builder() {
    return TakeTypeProfileParamsBuilder<0>();
  }

 private:
  TakeTypeProfileParams() { }


  DISALLOW_COPY_AND_ASSIGN(TakeTypeProfileParams);
};


// Result for the TakeTypeProfile command.
class HEADLESS_EXPORT TakeTypeProfileResult {
 public:
  static std::unique_ptr<TakeTypeProfileResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakeTypeProfileResult() { }

  // Type profile for all scripts since startTypeProfile() was turned on.
  const std::vector<std::unique_ptr<::headless::profiler::ScriptTypeProfile>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptTypeProfile>> value) { result_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakeTypeProfileResult> Clone() const;

  template<int STATE>
  class TakeTypeProfileResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    TakeTypeProfileResultBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptTypeProfile>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    std::unique_ptr<TakeTypeProfileResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakeTypeProfileResult;
    TakeTypeProfileResultBuilder() : result_(new TakeTypeProfileResult()) { }

    template<int STEP> TakeTypeProfileResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakeTypeProfileResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakeTypeProfileResult> result_;
  };

  static TakeTypeProfileResultBuilder<0> Builder() {
    return TakeTypeProfileResultBuilder<0>();
  }

 private:
  TakeTypeProfileResult() { }

  std::vector<std::unique_ptr<::headless::profiler::ScriptTypeProfile>> result_;

  DISALLOW_COPY_AND_ASSIGN(TakeTypeProfileResult);
};


// Parameters for the EnableRuntimeCallStats command.
class HEADLESS_EXPORT EnableRuntimeCallStatsParams {
 public:
  static std::unique_ptr<EnableRuntimeCallStatsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableRuntimeCallStatsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableRuntimeCallStatsParams> Clone() const;

  template<int STATE>
  class EnableRuntimeCallStatsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableRuntimeCallStatsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableRuntimeCallStatsParams;
    EnableRuntimeCallStatsParamsBuilder() : result_(new EnableRuntimeCallStatsParams()) { }

    template<int STEP> EnableRuntimeCallStatsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableRuntimeCallStatsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableRuntimeCallStatsParams> result_;
  };

  static EnableRuntimeCallStatsParamsBuilder<0> Builder() {
    return EnableRuntimeCallStatsParamsBuilder<0>();
  }

 private:
  EnableRuntimeCallStatsParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableRuntimeCallStatsParams);
};


// Result for the EnableRuntimeCallStats command.
class HEADLESS_EXPORT EnableRuntimeCallStatsResult {
 public:
  static std::unique_ptr<EnableRuntimeCallStatsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableRuntimeCallStatsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableRuntimeCallStatsResult> Clone() const;

  template<int STATE>
  class EnableRuntimeCallStatsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableRuntimeCallStatsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableRuntimeCallStatsResult;
    EnableRuntimeCallStatsResultBuilder() : result_(new EnableRuntimeCallStatsResult()) { }

    template<int STEP> EnableRuntimeCallStatsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableRuntimeCallStatsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableRuntimeCallStatsResult> result_;
  };

  static EnableRuntimeCallStatsResultBuilder<0> Builder() {
    return EnableRuntimeCallStatsResultBuilder<0>();
  }

 private:
  EnableRuntimeCallStatsResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableRuntimeCallStatsResult);
};


// Parameters for the DisableRuntimeCallStats command.
class HEADLESS_EXPORT DisableRuntimeCallStatsParams {
 public:
  static std::unique_ptr<DisableRuntimeCallStatsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableRuntimeCallStatsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableRuntimeCallStatsParams> Clone() const;

  template<int STATE>
  class DisableRuntimeCallStatsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableRuntimeCallStatsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableRuntimeCallStatsParams;
    DisableRuntimeCallStatsParamsBuilder() : result_(new DisableRuntimeCallStatsParams()) { }

    template<int STEP> DisableRuntimeCallStatsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableRuntimeCallStatsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableRuntimeCallStatsParams> result_;
  };

  static DisableRuntimeCallStatsParamsBuilder<0> Builder() {
    return DisableRuntimeCallStatsParamsBuilder<0>();
  }

 private:
  DisableRuntimeCallStatsParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableRuntimeCallStatsParams);
};


// Result for the DisableRuntimeCallStats command.
class HEADLESS_EXPORT DisableRuntimeCallStatsResult {
 public:
  static std::unique_ptr<DisableRuntimeCallStatsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableRuntimeCallStatsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableRuntimeCallStatsResult> Clone() const;

  template<int STATE>
  class DisableRuntimeCallStatsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableRuntimeCallStatsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableRuntimeCallStatsResult;
    DisableRuntimeCallStatsResultBuilder() : result_(new DisableRuntimeCallStatsResult()) { }

    template<int STEP> DisableRuntimeCallStatsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableRuntimeCallStatsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableRuntimeCallStatsResult> result_;
  };

  static DisableRuntimeCallStatsResultBuilder<0> Builder() {
    return DisableRuntimeCallStatsResultBuilder<0>();
  }

 private:
  DisableRuntimeCallStatsResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableRuntimeCallStatsResult);
};


// Parameters for the GetRuntimeCallStats command.
class HEADLESS_EXPORT GetRuntimeCallStatsParams {
 public:
  static std::unique_ptr<GetRuntimeCallStatsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRuntimeCallStatsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRuntimeCallStatsParams> Clone() const;

  template<int STATE>
  class GetRuntimeCallStatsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetRuntimeCallStatsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRuntimeCallStatsParams;
    GetRuntimeCallStatsParamsBuilder() : result_(new GetRuntimeCallStatsParams()) { }

    template<int STEP> GetRuntimeCallStatsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRuntimeCallStatsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRuntimeCallStatsParams> result_;
  };

  static GetRuntimeCallStatsParamsBuilder<0> Builder() {
    return GetRuntimeCallStatsParamsBuilder<0>();
  }

 private:
  GetRuntimeCallStatsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetRuntimeCallStatsParams);
};


// Result for the GetRuntimeCallStats command.
class HEADLESS_EXPORT GetRuntimeCallStatsResult {
 public:
  static std::unique_ptr<GetRuntimeCallStatsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRuntimeCallStatsResult() { }

  // Collected counter information.
  const std::vector<std::unique_ptr<::headless::profiler::CounterInfo>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::profiler::CounterInfo>> value) { result_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRuntimeCallStatsResult> Clone() const;

  template<int STATE>
  class GetRuntimeCallStatsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    GetRuntimeCallStatsResultBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::profiler::CounterInfo>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    std::unique_ptr<GetRuntimeCallStatsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRuntimeCallStatsResult;
    GetRuntimeCallStatsResultBuilder() : result_(new GetRuntimeCallStatsResult()) { }

    template<int STEP> GetRuntimeCallStatsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRuntimeCallStatsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRuntimeCallStatsResult> result_;
  };

  static GetRuntimeCallStatsResultBuilder<0> Builder() {
    return GetRuntimeCallStatsResultBuilder<0>();
  }

 private:
  GetRuntimeCallStatsResult() { }

  std::vector<std::unique_ptr<::headless::profiler::CounterInfo>> result_;

  DISALLOW_COPY_AND_ASSIGN(GetRuntimeCallStatsResult);
};


// Parameters for the ConsoleProfileFinished event.
class HEADLESS_EXPORT ConsoleProfileFinishedParams {
 public:
  static std::unique_ptr<ConsoleProfileFinishedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ConsoleProfileFinishedParams() { }

  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  // Location of console.profileEnd().
  const ::headless::debugger::Location* GetLocation() const { return location_.get(); }
  void SetLocation(std::unique_ptr<::headless::debugger::Location> value) { location_ = std::move(value); }

  const ::headless::profiler::Profile* GetProfile() const { return profile_.get(); }
  void SetProfile(std::unique_ptr<::headless::profiler::Profile> value) { profile_ = std::move(value); }

  // Profile title passed as an argument to console.profile().
  bool HasTitle() const { return !!title_; }
  std::string GetTitle() const { DCHECK(HasTitle()); return title_.value(); }
  void SetTitle(const std::string& value) { title_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ConsoleProfileFinishedParams> Clone() const;

  template<int STATE>
  class ConsoleProfileFinishedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kLocationSet = 1 << 2,
    kProfileSet = 1 << 3,
      kAllRequiredFieldsSet = (kIdSet | kLocationSet | kProfileSet | 0)
    };

    ConsoleProfileFinishedParamsBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    ConsoleProfileFinishedParamsBuilder<STATE | kLocationSet>& SetLocation(std::unique_ptr<::headless::debugger::Location> value) {
      static_assert(!(STATE & kLocationSet), "property location should not have already been set");
      result_->SetLocation(std::move(value));
      return CastState<kLocationSet>();
    }

    ConsoleProfileFinishedParamsBuilder<STATE | kProfileSet>& SetProfile(std::unique_ptr<::headless::profiler::Profile> value) {
      static_assert(!(STATE & kProfileSet), "property profile should not have already been set");
      result_->SetProfile(std::move(value));
      return CastState<kProfileSet>();
    }

    ConsoleProfileFinishedParamsBuilder<STATE>& SetTitle(const std::string& value) {
      result_->SetTitle(value);
      return *this;
    }

    std::unique_ptr<ConsoleProfileFinishedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ConsoleProfileFinishedParams;
    ConsoleProfileFinishedParamsBuilder() : result_(new ConsoleProfileFinishedParams()) { }

    template<int STEP> ConsoleProfileFinishedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ConsoleProfileFinishedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ConsoleProfileFinishedParams> result_;
  };

  static ConsoleProfileFinishedParamsBuilder<0> Builder() {
    return ConsoleProfileFinishedParamsBuilder<0>();
  }

 private:
  ConsoleProfileFinishedParams() { }

  std::string id_;
  std::unique_ptr<::headless::debugger::Location> location_;
  std::unique_ptr<::headless::profiler::Profile> profile_;
  base::Optional<std::string> title_;

  DISALLOW_COPY_AND_ASSIGN(ConsoleProfileFinishedParams);
};


// Parameters for the ConsoleProfileStarted event.
class HEADLESS_EXPORT ConsoleProfileStartedParams {
 public:
  static std::unique_ptr<ConsoleProfileStartedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ConsoleProfileStartedParams() { }

  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  // Location of console.profile().
  const ::headless::debugger::Location* GetLocation() const { return location_.get(); }
  void SetLocation(std::unique_ptr<::headless::debugger::Location> value) { location_ = std::move(value); }

  // Profile title passed as an argument to console.profile().
  bool HasTitle() const { return !!title_; }
  std::string GetTitle() const { DCHECK(HasTitle()); return title_.value(); }
  void SetTitle(const std::string& value) { title_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ConsoleProfileStartedParams> Clone() const;

  template<int STATE>
  class ConsoleProfileStartedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kLocationSet = 1 << 2,
      kAllRequiredFieldsSet = (kIdSet | kLocationSet | 0)
    };

    ConsoleProfileStartedParamsBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    ConsoleProfileStartedParamsBuilder<STATE | kLocationSet>& SetLocation(std::unique_ptr<::headless::debugger::Location> value) {
      static_assert(!(STATE & kLocationSet), "property location should not have already been set");
      result_->SetLocation(std::move(value));
      return CastState<kLocationSet>();
    }

    ConsoleProfileStartedParamsBuilder<STATE>& SetTitle(const std::string& value) {
      result_->SetTitle(value);
      return *this;
    }

    std::unique_ptr<ConsoleProfileStartedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ConsoleProfileStartedParams;
    ConsoleProfileStartedParamsBuilder() : result_(new ConsoleProfileStartedParams()) { }

    template<int STEP> ConsoleProfileStartedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ConsoleProfileStartedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ConsoleProfileStartedParams> result_;
  };

  static ConsoleProfileStartedParamsBuilder<0> Builder() {
    return ConsoleProfileStartedParamsBuilder<0>();
  }

 private:
  ConsoleProfileStartedParams() { }

  std::string id_;
  std::unique_ptr<::headless::debugger::Location> location_;
  base::Optional<std::string> title_;

  DISALLOW_COPY_AND_ASSIGN(ConsoleProfileStartedParams);
};


// Parameters for the PreciseCoverageDeltaUpdate event.
class HEADLESS_EXPORT PreciseCoverageDeltaUpdateParams {
 public:
  static std::unique_ptr<PreciseCoverageDeltaUpdateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PreciseCoverageDeltaUpdateParams() { }

  // Monotonically increasing time (in seconds) when the coverage update was taken in the backend.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Identifier for distinguishing coverage events.
  std::string GetOccassion() const { return occassion_; }
  void SetOccassion(const std::string& value) { occassion_ = value; }

  // Coverage data for the current isolate.
  const std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> value) { result_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PreciseCoverageDeltaUpdateParams> Clone() const;

  template<int STATE>
  class PreciseCoverageDeltaUpdateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimestampSet = 1 << 1,
    kOccassionSet = 1 << 2,
    kResultSet = 1 << 3,
      kAllRequiredFieldsSet = (kTimestampSet | kOccassionSet | kResultSet | 0)
    };

    PreciseCoverageDeltaUpdateParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    PreciseCoverageDeltaUpdateParamsBuilder<STATE | kOccassionSet>& SetOccassion(const std::string& value) {
      static_assert(!(STATE & kOccassionSet), "property occassion should not have already been set");
      result_->SetOccassion(value);
      return CastState<kOccassionSet>();
    }

    PreciseCoverageDeltaUpdateParamsBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    std::unique_ptr<PreciseCoverageDeltaUpdateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PreciseCoverageDeltaUpdateParams;
    PreciseCoverageDeltaUpdateParamsBuilder() : result_(new PreciseCoverageDeltaUpdateParams()) { }

    template<int STEP> PreciseCoverageDeltaUpdateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PreciseCoverageDeltaUpdateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PreciseCoverageDeltaUpdateParams> result_;
  };

  static PreciseCoverageDeltaUpdateParamsBuilder<0> Builder() {
    return PreciseCoverageDeltaUpdateParamsBuilder<0>();
  }

 private:
  PreciseCoverageDeltaUpdateParams() { }

  double timestamp_;
  std::string occassion_;
  std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>> result_;

  DISALLOW_COPY_AND_ASSIGN(PreciseCoverageDeltaUpdateParams);
};


}  // namespace profiler

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PROFILER_H_
