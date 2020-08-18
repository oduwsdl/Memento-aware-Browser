// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_profiler.h"
#include "headless/public/devtools/domains/types_runtime.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_profiler.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"

namespace headless {

namespace profiler {

std::unique_ptr<ProfileNode> ProfileNode::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ProfileNode");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ProfileNode> result(new ProfileNode());
  errors->Push();
  errors->SetName("ProfileNode");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<int>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* call_frame_value = value.FindKey("callFrame");
  if (call_frame_value) {
    errors->SetName("callFrame");
    result->call_frame_ = internal::FromValue<::headless::runtime::CallFrame>::Parse(*call_frame_value, errors);
  } else {
    errors->AddError("required property missing: callFrame");
  }
  const base::Value* hit_count_value = value.FindKey("hitCount");
  if (hit_count_value) {
    errors->SetName("hitCount");
    result->hit_count_ = internal::FromValue<int>::Parse(*hit_count_value, errors);
  }
  const base::Value* children_value = value.FindKey("children");
  if (children_value) {
    errors->SetName("children");
    result->children_ = internal::FromValue<std::vector<int>>::Parse(*children_value, errors);
  }
  const base::Value* deopt_reason_value = value.FindKey("deoptReason");
  if (deopt_reason_value) {
    errors->SetName("deoptReason");
    result->deopt_reason_ = internal::FromValue<std::string>::Parse(*deopt_reason_value, errors);
  }
  const base::Value* position_ticks_value = value.FindKey("positionTicks");
  if (position_ticks_value) {
    errors->SetName("positionTicks");
    result->position_ticks_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::PositionTickInfo>>>::Parse(*position_ticks_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ProfileNode::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  result->Set("callFrame", internal::ToValue(*call_frame_));
  if (hit_count_)
    result->Set("hitCount", internal::ToValue(hit_count_.value()));
  if (children_)
    result->Set("children", internal::ToValue(children_.value()));
  if (deopt_reason_)
    result->Set("deoptReason", internal::ToValue(deopt_reason_.value()));
  if (position_ticks_)
    result->Set("positionTicks", internal::ToValue(position_ticks_.value()));
  return std::move(result);
}

std::unique_ptr<ProfileNode> ProfileNode::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ProfileNode> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Profile> Profile::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Profile");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Profile> result(new Profile());
  errors->Push();
  errors->SetName("Profile");
  const base::Value* nodes_value = value.FindKey("nodes");
  if (nodes_value) {
    errors->SetName("nodes");
    result->nodes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::ProfileNode>>>::Parse(*nodes_value, errors);
  } else {
    errors->AddError("required property missing: nodes");
  }
  const base::Value* start_time_value = value.FindKey("startTime");
  if (start_time_value) {
    errors->SetName("startTime");
    result->start_time_ = internal::FromValue<double>::Parse(*start_time_value, errors);
  } else {
    errors->AddError("required property missing: startTime");
  }
  const base::Value* end_time_value = value.FindKey("endTime");
  if (end_time_value) {
    errors->SetName("endTime");
    result->end_time_ = internal::FromValue<double>::Parse(*end_time_value, errors);
  } else {
    errors->AddError("required property missing: endTime");
  }
  const base::Value* samples_value = value.FindKey("samples");
  if (samples_value) {
    errors->SetName("samples");
    result->samples_ = internal::FromValue<std::vector<int>>::Parse(*samples_value, errors);
  }
  const base::Value* time_deltas_value = value.FindKey("timeDeltas");
  if (time_deltas_value) {
    errors->SetName("timeDeltas");
    result->time_deltas_ = internal::FromValue<std::vector<int>>::Parse(*time_deltas_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Profile::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodes", internal::ToValue(nodes_));
  result->Set("startTime", internal::ToValue(start_time_));
  result->Set("endTime", internal::ToValue(end_time_));
  if (samples_)
    result->Set("samples", internal::ToValue(samples_.value()));
  if (time_deltas_)
    result->Set("timeDeltas", internal::ToValue(time_deltas_.value()));
  return std::move(result);
}

std::unique_ptr<Profile> Profile::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Profile> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PositionTickInfo> PositionTickInfo::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PositionTickInfo");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PositionTickInfo> result(new PositionTickInfo());
  errors->Push();
  errors->SetName("PositionTickInfo");
  const base::Value* line_value = value.FindKey("line");
  if (line_value) {
    errors->SetName("line");
    result->line_ = internal::FromValue<int>::Parse(*line_value, errors);
  } else {
    errors->AddError("required property missing: line");
  }
  const base::Value* ticks_value = value.FindKey("ticks");
  if (ticks_value) {
    errors->SetName("ticks");
    result->ticks_ = internal::FromValue<int>::Parse(*ticks_value, errors);
  } else {
    errors->AddError("required property missing: ticks");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PositionTickInfo::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("line", internal::ToValue(line_));
  result->Set("ticks", internal::ToValue(ticks_));
  return std::move(result);
}

std::unique_ptr<PositionTickInfo> PositionTickInfo::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PositionTickInfo> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CoverageRange> CoverageRange::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CoverageRange");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CoverageRange> result(new CoverageRange());
  errors->Push();
  errors->SetName("CoverageRange");
  const base::Value* start_offset_value = value.FindKey("startOffset");
  if (start_offset_value) {
    errors->SetName("startOffset");
    result->start_offset_ = internal::FromValue<int>::Parse(*start_offset_value, errors);
  } else {
    errors->AddError("required property missing: startOffset");
  }
  const base::Value* end_offset_value = value.FindKey("endOffset");
  if (end_offset_value) {
    errors->SetName("endOffset");
    result->end_offset_ = internal::FromValue<int>::Parse(*end_offset_value, errors);
  } else {
    errors->AddError("required property missing: endOffset");
  }
  const base::Value* count_value = value.FindKey("count");
  if (count_value) {
    errors->SetName("count");
    result->count_ = internal::FromValue<int>::Parse(*count_value, errors);
  } else {
    errors->AddError("required property missing: count");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CoverageRange::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("startOffset", internal::ToValue(start_offset_));
  result->Set("endOffset", internal::ToValue(end_offset_));
  result->Set("count", internal::ToValue(count_));
  return std::move(result);
}

std::unique_ptr<CoverageRange> CoverageRange::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CoverageRange> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FunctionCoverage> FunctionCoverage::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FunctionCoverage");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FunctionCoverage> result(new FunctionCoverage());
  errors->Push();
  errors->SetName("FunctionCoverage");
  const base::Value* function_name_value = value.FindKey("functionName");
  if (function_name_value) {
    errors->SetName("functionName");
    result->function_name_ = internal::FromValue<std::string>::Parse(*function_name_value, errors);
  } else {
    errors->AddError("required property missing: functionName");
  }
  const base::Value* ranges_value = value.FindKey("ranges");
  if (ranges_value) {
    errors->SetName("ranges");
    result->ranges_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::CoverageRange>>>::Parse(*ranges_value, errors);
  } else {
    errors->AddError("required property missing: ranges");
  }
  const base::Value* is_block_coverage_value = value.FindKey("isBlockCoverage");
  if (is_block_coverage_value) {
    errors->SetName("isBlockCoverage");
    result->is_block_coverage_ = internal::FromValue<bool>::Parse(*is_block_coverage_value, errors);
  } else {
    errors->AddError("required property missing: isBlockCoverage");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FunctionCoverage::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("functionName", internal::ToValue(function_name_));
  result->Set("ranges", internal::ToValue(ranges_));
  result->Set("isBlockCoverage", internal::ToValue(is_block_coverage_));
  return std::move(result);
}

std::unique_ptr<FunctionCoverage> FunctionCoverage::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FunctionCoverage> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScriptCoverage> ScriptCoverage::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScriptCoverage");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScriptCoverage> result(new ScriptCoverage());
  errors->Push();
  errors->SetName("ScriptCoverage");
  const base::Value* script_id_value = value.FindKey("scriptId");
  if (script_id_value) {
    errors->SetName("scriptId");
    result->script_id_ = internal::FromValue<std::string>::Parse(*script_id_value, errors);
  } else {
    errors->AddError("required property missing: scriptId");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* functions_value = value.FindKey("functions");
  if (functions_value) {
    errors->SetName("functions");
    result->functions_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::FunctionCoverage>>>::Parse(*functions_value, errors);
  } else {
    errors->AddError("required property missing: functions");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScriptCoverage::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scriptId", internal::ToValue(script_id_));
  result->Set("url", internal::ToValue(url_));
  result->Set("functions", internal::ToValue(functions_));
  return std::move(result);
}

std::unique_ptr<ScriptCoverage> ScriptCoverage::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScriptCoverage> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TypeObject> TypeObject::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TypeObject");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TypeObject> result(new TypeObject());
  errors->Push();
  errors->SetName("TypeObject");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TypeObject::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  return std::move(result);
}

std::unique_ptr<TypeObject> TypeObject::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TypeObject> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TypeProfileEntry> TypeProfileEntry::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TypeProfileEntry");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TypeProfileEntry> result(new TypeProfileEntry());
  errors->Push();
  errors->SetName("TypeProfileEntry");
  const base::Value* offset_value = value.FindKey("offset");
  if (offset_value) {
    errors->SetName("offset");
    result->offset_ = internal::FromValue<int>::Parse(*offset_value, errors);
  } else {
    errors->AddError("required property missing: offset");
  }
  const base::Value* types_value = value.FindKey("types");
  if (types_value) {
    errors->SetName("types");
    result->types_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::TypeObject>>>::Parse(*types_value, errors);
  } else {
    errors->AddError("required property missing: types");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TypeProfileEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("offset", internal::ToValue(offset_));
  result->Set("types", internal::ToValue(types_));
  return std::move(result);
}

std::unique_ptr<TypeProfileEntry> TypeProfileEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TypeProfileEntry> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ScriptTypeProfile> ScriptTypeProfile::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScriptTypeProfile");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScriptTypeProfile> result(new ScriptTypeProfile());
  errors->Push();
  errors->SetName("ScriptTypeProfile");
  const base::Value* script_id_value = value.FindKey("scriptId");
  if (script_id_value) {
    errors->SetName("scriptId");
    result->script_id_ = internal::FromValue<std::string>::Parse(*script_id_value, errors);
  } else {
    errors->AddError("required property missing: scriptId");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* entries_value = value.FindKey("entries");
  if (entries_value) {
    errors->SetName("entries");
    result->entries_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::TypeProfileEntry>>>::Parse(*entries_value, errors);
  } else {
    errors->AddError("required property missing: entries");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScriptTypeProfile::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scriptId", internal::ToValue(script_id_));
  result->Set("url", internal::ToValue(url_));
  result->Set("entries", internal::ToValue(entries_));
  return std::move(result);
}

std::unique_ptr<ScriptTypeProfile> ScriptTypeProfile::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScriptTypeProfile> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CounterInfo> CounterInfo::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CounterInfo");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CounterInfo> result(new CounterInfo());
  errors->Push();
  errors->SetName("CounterInfo");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<int>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CounterInfo::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<CounterInfo> CounterInfo::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CounterInfo> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBestEffortCoverageParams> GetBestEffortCoverageParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBestEffortCoverageParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBestEffortCoverageParams> result(new GetBestEffortCoverageParams());
  errors->Push();
  errors->SetName("GetBestEffortCoverageParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBestEffortCoverageParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetBestEffortCoverageParams> GetBestEffortCoverageParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBestEffortCoverageParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBestEffortCoverageResult> GetBestEffortCoverageResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBestEffortCoverageResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBestEffortCoverageResult> result(new GetBestEffortCoverageResult());
  errors->Push();
  errors->SetName("GetBestEffortCoverageResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBestEffortCoverageResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<GetBestEffortCoverageResult> GetBestEffortCoverageResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBestEffortCoverageResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetSamplingIntervalParams> SetSamplingIntervalParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetSamplingIntervalParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetSamplingIntervalParams> result(new SetSamplingIntervalParams());
  errors->Push();
  errors->SetName("SetSamplingIntervalParams");
  const base::Value* interval_value = value.FindKey("interval");
  if (interval_value) {
    errors->SetName("interval");
    result->interval_ = internal::FromValue<int>::Parse(*interval_value, errors);
  } else {
    errors->AddError("required property missing: interval");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetSamplingIntervalParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("interval", internal::ToValue(interval_));
  return std::move(result);
}

std::unique_ptr<SetSamplingIntervalParams> SetSamplingIntervalParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetSamplingIntervalParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetSamplingIntervalResult> SetSamplingIntervalResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetSamplingIntervalResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetSamplingIntervalResult> result(new SetSamplingIntervalResult());
  errors->Push();
  errors->SetName("SetSamplingIntervalResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetSamplingIntervalResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetSamplingIntervalResult> SetSamplingIntervalResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetSamplingIntervalResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartParams> StartParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartParams> result(new StartParams());
  errors->Push();
  errors->SetName("StartParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartParams> StartParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartResult> StartResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartResult> result(new StartResult());
  errors->Push();
  errors->SetName("StartResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartResult> StartResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartPreciseCoverageParams> StartPreciseCoverageParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartPreciseCoverageParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartPreciseCoverageParams> result(new StartPreciseCoverageParams());
  errors->Push();
  errors->SetName("StartPreciseCoverageParams");
  const base::Value* call_count_value = value.FindKey("callCount");
  if (call_count_value) {
    errors->SetName("callCount");
    result->call_count_ = internal::FromValue<bool>::Parse(*call_count_value, errors);
  }
  const base::Value* detailed_value = value.FindKey("detailed");
  if (detailed_value) {
    errors->SetName("detailed");
    result->detailed_ = internal::FromValue<bool>::Parse(*detailed_value, errors);
  }
  const base::Value* allow_triggered_updates_value = value.FindKey("allowTriggeredUpdates");
  if (allow_triggered_updates_value) {
    errors->SetName("allowTriggeredUpdates");
    result->allow_triggered_updates_ = internal::FromValue<bool>::Parse(*allow_triggered_updates_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartPreciseCoverageParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (call_count_)
    result->Set("callCount", internal::ToValue(call_count_.value()));
  if (detailed_)
    result->Set("detailed", internal::ToValue(detailed_.value()));
  if (allow_triggered_updates_)
    result->Set("allowTriggeredUpdates", internal::ToValue(allow_triggered_updates_.value()));
  return std::move(result);
}

std::unique_ptr<StartPreciseCoverageParams> StartPreciseCoverageParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartPreciseCoverageParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartPreciseCoverageResult> StartPreciseCoverageResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartPreciseCoverageResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartPreciseCoverageResult> result(new StartPreciseCoverageResult());
  errors->Push();
  errors->SetName("StartPreciseCoverageResult");
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartPreciseCoverageResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<StartPreciseCoverageResult> StartPreciseCoverageResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartPreciseCoverageResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartTypeProfileParams> StartTypeProfileParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartTypeProfileParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartTypeProfileParams> result(new StartTypeProfileParams());
  errors->Push();
  errors->SetName("StartTypeProfileParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartTypeProfileParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartTypeProfileParams> StartTypeProfileParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartTypeProfileParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartTypeProfileResult> StartTypeProfileResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartTypeProfileResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartTypeProfileResult> result(new StartTypeProfileResult());
  errors->Push();
  errors->SetName("StartTypeProfileResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartTypeProfileResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartTypeProfileResult> StartTypeProfileResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartTypeProfileResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopParams> StopParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopParams> result(new StopParams());
  errors->Push();
  errors->SetName("StopParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopParams> StopParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopResult> StopResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopResult> result(new StopResult());
  errors->Push();
  errors->SetName("StopResult");
  const base::Value* profile_value = value.FindKey("profile");
  if (profile_value) {
    errors->SetName("profile");
    result->profile_ = internal::FromValue<::headless::profiler::Profile>::Parse(*profile_value, errors);
  } else {
    errors->AddError("required property missing: profile");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("profile", internal::ToValue(*profile_));
  return std::move(result);
}

std::unique_ptr<StopResult> StopResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopPreciseCoverageParams> StopPreciseCoverageParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopPreciseCoverageParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopPreciseCoverageParams> result(new StopPreciseCoverageParams());
  errors->Push();
  errors->SetName("StopPreciseCoverageParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopPreciseCoverageParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopPreciseCoverageParams> StopPreciseCoverageParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopPreciseCoverageParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopPreciseCoverageResult> StopPreciseCoverageResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopPreciseCoverageResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopPreciseCoverageResult> result(new StopPreciseCoverageResult());
  errors->Push();
  errors->SetName("StopPreciseCoverageResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopPreciseCoverageResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopPreciseCoverageResult> StopPreciseCoverageResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopPreciseCoverageResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopTypeProfileParams> StopTypeProfileParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopTypeProfileParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopTypeProfileParams> result(new StopTypeProfileParams());
  errors->Push();
  errors->SetName("StopTypeProfileParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopTypeProfileParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopTypeProfileParams> StopTypeProfileParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopTypeProfileParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopTypeProfileResult> StopTypeProfileResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopTypeProfileResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopTypeProfileResult> result(new StopTypeProfileResult());
  errors->Push();
  errors->SetName("StopTypeProfileResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopTypeProfileResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopTypeProfileResult> StopTypeProfileResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopTypeProfileResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakePreciseCoverageParams> TakePreciseCoverageParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakePreciseCoverageParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakePreciseCoverageParams> result(new TakePreciseCoverageParams());
  errors->Push();
  errors->SetName("TakePreciseCoverageParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakePreciseCoverageParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TakePreciseCoverageParams> TakePreciseCoverageParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakePreciseCoverageParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakePreciseCoverageResult> TakePreciseCoverageResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakePreciseCoverageResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakePreciseCoverageResult> result(new TakePreciseCoverageResult());
  errors->Push();
  errors->SetName("TakePreciseCoverageResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakePreciseCoverageResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<TakePreciseCoverageResult> TakePreciseCoverageResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakePreciseCoverageResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeTypeProfileParams> TakeTypeProfileParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeTypeProfileParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeTypeProfileParams> result(new TakeTypeProfileParams());
  errors->Push();
  errors->SetName("TakeTypeProfileParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeTypeProfileParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TakeTypeProfileParams> TakeTypeProfileParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeTypeProfileParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeTypeProfileResult> TakeTypeProfileResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeTypeProfileResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeTypeProfileResult> result(new TakeTypeProfileResult());
  errors->Push();
  errors->SetName("TakeTypeProfileResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::ScriptTypeProfile>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeTypeProfileResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<TakeTypeProfileResult> TakeTypeProfileResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeTypeProfileResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableRuntimeCallStatsParams> EnableRuntimeCallStatsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableRuntimeCallStatsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableRuntimeCallStatsParams> result(new EnableRuntimeCallStatsParams());
  errors->Push();
  errors->SetName("EnableRuntimeCallStatsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableRuntimeCallStatsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableRuntimeCallStatsParams> EnableRuntimeCallStatsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableRuntimeCallStatsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableRuntimeCallStatsResult> EnableRuntimeCallStatsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableRuntimeCallStatsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableRuntimeCallStatsResult> result(new EnableRuntimeCallStatsResult());
  errors->Push();
  errors->SetName("EnableRuntimeCallStatsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableRuntimeCallStatsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableRuntimeCallStatsResult> EnableRuntimeCallStatsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableRuntimeCallStatsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableRuntimeCallStatsParams> DisableRuntimeCallStatsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableRuntimeCallStatsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableRuntimeCallStatsParams> result(new DisableRuntimeCallStatsParams());
  errors->Push();
  errors->SetName("DisableRuntimeCallStatsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableRuntimeCallStatsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableRuntimeCallStatsParams> DisableRuntimeCallStatsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableRuntimeCallStatsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableRuntimeCallStatsResult> DisableRuntimeCallStatsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableRuntimeCallStatsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableRuntimeCallStatsResult> result(new DisableRuntimeCallStatsResult());
  errors->Push();
  errors->SetName("DisableRuntimeCallStatsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableRuntimeCallStatsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableRuntimeCallStatsResult> DisableRuntimeCallStatsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableRuntimeCallStatsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetRuntimeCallStatsParams> GetRuntimeCallStatsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRuntimeCallStatsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRuntimeCallStatsParams> result(new GetRuntimeCallStatsParams());
  errors->Push();
  errors->SetName("GetRuntimeCallStatsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRuntimeCallStatsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetRuntimeCallStatsParams> GetRuntimeCallStatsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRuntimeCallStatsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetRuntimeCallStatsResult> GetRuntimeCallStatsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRuntimeCallStatsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRuntimeCallStatsResult> result(new GetRuntimeCallStatsResult());
  errors->Push();
  errors->SetName("GetRuntimeCallStatsResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::CounterInfo>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRuntimeCallStatsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<GetRuntimeCallStatsResult> GetRuntimeCallStatsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRuntimeCallStatsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ConsoleProfileFinishedParams> ConsoleProfileFinishedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ConsoleProfileFinishedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ConsoleProfileFinishedParams> result(new ConsoleProfileFinishedParams());
  errors->Push();
  errors->SetName("ConsoleProfileFinishedParams");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* location_value = value.FindKey("location");
  if (location_value) {
    errors->SetName("location");
    result->location_ = internal::FromValue<::headless::debugger::Location>::Parse(*location_value, errors);
  } else {
    errors->AddError("required property missing: location");
  }
  const base::Value* profile_value = value.FindKey("profile");
  if (profile_value) {
    errors->SetName("profile");
    result->profile_ = internal::FromValue<::headless::profiler::Profile>::Parse(*profile_value, errors);
  } else {
    errors->AddError("required property missing: profile");
  }
  const base::Value* title_value = value.FindKey("title");
  if (title_value) {
    errors->SetName("title");
    result->title_ = internal::FromValue<std::string>::Parse(*title_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ConsoleProfileFinishedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  result->Set("location", internal::ToValue(*location_));
  result->Set("profile", internal::ToValue(*profile_));
  if (title_)
    result->Set("title", internal::ToValue(title_.value()));
  return std::move(result);
}

std::unique_ptr<ConsoleProfileFinishedParams> ConsoleProfileFinishedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ConsoleProfileFinishedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ConsoleProfileStartedParams> ConsoleProfileStartedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ConsoleProfileStartedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ConsoleProfileStartedParams> result(new ConsoleProfileStartedParams());
  errors->Push();
  errors->SetName("ConsoleProfileStartedParams");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* location_value = value.FindKey("location");
  if (location_value) {
    errors->SetName("location");
    result->location_ = internal::FromValue<::headless::debugger::Location>::Parse(*location_value, errors);
  } else {
    errors->AddError("required property missing: location");
  }
  const base::Value* title_value = value.FindKey("title");
  if (title_value) {
    errors->SetName("title");
    result->title_ = internal::FromValue<std::string>::Parse(*title_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ConsoleProfileStartedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  result->Set("location", internal::ToValue(*location_));
  if (title_)
    result->Set("title", internal::ToValue(title_.value()));
  return std::move(result);
}

std::unique_ptr<ConsoleProfileStartedParams> ConsoleProfileStartedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ConsoleProfileStartedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PreciseCoverageDeltaUpdateParams> PreciseCoverageDeltaUpdateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PreciseCoverageDeltaUpdateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PreciseCoverageDeltaUpdateParams> result(new PreciseCoverageDeltaUpdateParams());
  errors->Push();
  errors->SetName("PreciseCoverageDeltaUpdateParams");
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* occassion_value = value.FindKey("occassion");
  if (occassion_value) {
    errors->SetName("occassion");
    result->occassion_ = internal::FromValue<std::string>::Parse(*occassion_value, errors);
  } else {
    errors->AddError("required property missing: occassion");
  }
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::profiler::ScriptCoverage>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PreciseCoverageDeltaUpdateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("occassion", internal::ToValue(occassion_));
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<PreciseCoverageDeltaUpdateParams> PreciseCoverageDeltaUpdateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PreciseCoverageDeltaUpdateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace profiler
}  // namespace headless
