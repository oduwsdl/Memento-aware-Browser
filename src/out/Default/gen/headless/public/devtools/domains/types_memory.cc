// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_memory.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_memory.h"

namespace headless {

namespace memory {

std::unique_ptr<SamplingProfileNode> SamplingProfileNode::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SamplingProfileNode");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SamplingProfileNode> result(new SamplingProfileNode());
  errors->Push();
  errors->SetName("SamplingProfileNode");
  const base::Value* size_value = value.FindKey("size");
  if (size_value) {
    errors->SetName("size");
    result->size_ = internal::FromValue<double>::Parse(*size_value, errors);
  } else {
    errors->AddError("required property missing: size");
  }
  const base::Value* total_value = value.FindKey("total");
  if (total_value) {
    errors->SetName("total");
    result->total_ = internal::FromValue<double>::Parse(*total_value, errors);
  } else {
    errors->AddError("required property missing: total");
  }
  const base::Value* stack_value = value.FindKey("stack");
  if (stack_value) {
    errors->SetName("stack");
    result->stack_ = internal::FromValue<std::vector<std::string>>::Parse(*stack_value, errors);
  } else {
    errors->AddError("required property missing: stack");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SamplingProfileNode::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("size", internal::ToValue(size_));
  result->Set("total", internal::ToValue(total_));
  result->Set("stack", internal::ToValue(stack_));
  return std::move(result);
}

std::unique_ptr<SamplingProfileNode> SamplingProfileNode::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SamplingProfileNode> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SamplingProfile> SamplingProfile::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SamplingProfile");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SamplingProfile> result(new SamplingProfile());
  errors->Push();
  errors->SetName("SamplingProfile");
  const base::Value* samples_value = value.FindKey("samples");
  if (samples_value) {
    errors->SetName("samples");
    result->samples_ = internal::FromValue<std::vector<std::unique_ptr<::headless::memory::SamplingProfileNode>>>::Parse(*samples_value, errors);
  } else {
    errors->AddError("required property missing: samples");
  }
  const base::Value* modules_value = value.FindKey("modules");
  if (modules_value) {
    errors->SetName("modules");
    result->modules_ = internal::FromValue<std::vector<std::unique_ptr<::headless::memory::Module>>>::Parse(*modules_value, errors);
  } else {
    errors->AddError("required property missing: modules");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SamplingProfile::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("samples", internal::ToValue(samples_));
  result->Set("modules", internal::ToValue(modules_));
  return std::move(result);
}

std::unique_ptr<SamplingProfile> SamplingProfile::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SamplingProfile> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Module> Module::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Module");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Module> result(new Module());
  errors->Push();
  errors->SetName("Module");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* uuid_value = value.FindKey("uuid");
  if (uuid_value) {
    errors->SetName("uuid");
    result->uuid_ = internal::FromValue<std::string>::Parse(*uuid_value, errors);
  } else {
    errors->AddError("required property missing: uuid");
  }
  const base::Value* base_address_value = value.FindKey("baseAddress");
  if (base_address_value) {
    errors->SetName("baseAddress");
    result->base_address_ = internal::FromValue<std::string>::Parse(*base_address_value, errors);
  } else {
    errors->AddError("required property missing: baseAddress");
  }
  const base::Value* size_value = value.FindKey("size");
  if (size_value) {
    errors->SetName("size");
    result->size_ = internal::FromValue<double>::Parse(*size_value, errors);
  } else {
    errors->AddError("required property missing: size");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Module::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("uuid", internal::ToValue(uuid_));
  result->Set("baseAddress", internal::ToValue(base_address_));
  result->Set("size", internal::ToValue(size_));
  return std::move(result);
}

std::unique_ptr<Module> Module::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Module> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDOMCountersParams> GetDOMCountersParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDOMCountersParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDOMCountersParams> result(new GetDOMCountersParams());
  errors->Push();
  errors->SetName("GetDOMCountersParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDOMCountersParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetDOMCountersParams> GetDOMCountersParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDOMCountersParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDOMCountersResult> GetDOMCountersResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDOMCountersResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDOMCountersResult> result(new GetDOMCountersResult());
  errors->Push();
  errors->SetName("GetDOMCountersResult");
  const base::Value* documents_value = value.FindKey("documents");
  if (documents_value) {
    errors->SetName("documents");
    result->documents_ = internal::FromValue<int>::Parse(*documents_value, errors);
  } else {
    errors->AddError("required property missing: documents");
  }
  const base::Value* nodes_value = value.FindKey("nodes");
  if (nodes_value) {
    errors->SetName("nodes");
    result->nodes_ = internal::FromValue<int>::Parse(*nodes_value, errors);
  } else {
    errors->AddError("required property missing: nodes");
  }
  const base::Value* js_event_listeners_value = value.FindKey("jsEventListeners");
  if (js_event_listeners_value) {
    errors->SetName("jsEventListeners");
    result->js_event_listeners_ = internal::FromValue<int>::Parse(*js_event_listeners_value, errors);
  } else {
    errors->AddError("required property missing: jsEventListeners");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDOMCountersResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("documents", internal::ToValue(documents_));
  result->Set("nodes", internal::ToValue(nodes_));
  result->Set("jsEventListeners", internal::ToValue(js_event_listeners_));
  return std::move(result);
}

std::unique_ptr<GetDOMCountersResult> GetDOMCountersResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDOMCountersResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PrepareForLeakDetectionParams> PrepareForLeakDetectionParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PrepareForLeakDetectionParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PrepareForLeakDetectionParams> result(new PrepareForLeakDetectionParams());
  errors->Push();
  errors->SetName("PrepareForLeakDetectionParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PrepareForLeakDetectionParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<PrepareForLeakDetectionParams> PrepareForLeakDetectionParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PrepareForLeakDetectionParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PrepareForLeakDetectionResult> PrepareForLeakDetectionResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PrepareForLeakDetectionResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PrepareForLeakDetectionResult> result(new PrepareForLeakDetectionResult());
  errors->Push();
  errors->SetName("PrepareForLeakDetectionResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PrepareForLeakDetectionResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<PrepareForLeakDetectionResult> PrepareForLeakDetectionResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PrepareForLeakDetectionResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> ForciblyPurgeJavaScriptMemoryParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ForciblyPurgeJavaScriptMemoryParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> result(new ForciblyPurgeJavaScriptMemoryParams());
  errors->Push();
  errors->SetName("ForciblyPurgeJavaScriptMemoryParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ForciblyPurgeJavaScriptMemoryParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> ForciblyPurgeJavaScriptMemoryParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> ForciblyPurgeJavaScriptMemoryResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ForciblyPurgeJavaScriptMemoryResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> result(new ForciblyPurgeJavaScriptMemoryResult());
  errors->Push();
  errors->SetName("ForciblyPurgeJavaScriptMemoryResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ForciblyPurgeJavaScriptMemoryResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> ForciblyPurgeJavaScriptMemoryResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPressureNotificationsSuppressedParams> SetPressureNotificationsSuppressedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPressureNotificationsSuppressedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPressureNotificationsSuppressedParams> result(new SetPressureNotificationsSuppressedParams());
  errors->Push();
  errors->SetName("SetPressureNotificationsSuppressedParams");
  const base::Value* suppressed_value = value.FindKey("suppressed");
  if (suppressed_value) {
    errors->SetName("suppressed");
    result->suppressed_ = internal::FromValue<bool>::Parse(*suppressed_value, errors);
  } else {
    errors->AddError("required property missing: suppressed");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetPressureNotificationsSuppressedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("suppressed", internal::ToValue(suppressed_));
  return std::move(result);
}

std::unique_ptr<SetPressureNotificationsSuppressedParams> SetPressureNotificationsSuppressedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPressureNotificationsSuppressedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPressureNotificationsSuppressedResult> SetPressureNotificationsSuppressedResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPressureNotificationsSuppressedResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPressureNotificationsSuppressedResult> result(new SetPressureNotificationsSuppressedResult());
  errors->Push();
  errors->SetName("SetPressureNotificationsSuppressedResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetPressureNotificationsSuppressedResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetPressureNotificationsSuppressedResult> SetPressureNotificationsSuppressedResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPressureNotificationsSuppressedResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SimulatePressureNotificationParams> SimulatePressureNotificationParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SimulatePressureNotificationParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SimulatePressureNotificationParams> result(new SimulatePressureNotificationParams());
  errors->Push();
  errors->SetName("SimulatePressureNotificationParams");
  const base::Value* level_value = value.FindKey("level");
  if (level_value) {
    errors->SetName("level");
    result->level_ = internal::FromValue<::headless::memory::PressureLevel>::Parse(*level_value, errors);
  } else {
    errors->AddError("required property missing: level");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SimulatePressureNotificationParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("level", internal::ToValue(level_));
  return std::move(result);
}

std::unique_ptr<SimulatePressureNotificationParams> SimulatePressureNotificationParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SimulatePressureNotificationParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SimulatePressureNotificationResult> SimulatePressureNotificationResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SimulatePressureNotificationResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SimulatePressureNotificationResult> result(new SimulatePressureNotificationResult());
  errors->Push();
  errors->SetName("SimulatePressureNotificationResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SimulatePressureNotificationResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SimulatePressureNotificationResult> SimulatePressureNotificationResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SimulatePressureNotificationResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartSamplingParams> StartSamplingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartSamplingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartSamplingParams> result(new StartSamplingParams());
  errors->Push();
  errors->SetName("StartSamplingParams");
  const base::Value* sampling_interval_value = value.FindKey("samplingInterval");
  if (sampling_interval_value) {
    errors->SetName("samplingInterval");
    result->sampling_interval_ = internal::FromValue<int>::Parse(*sampling_interval_value, errors);
  }
  const base::Value* suppress_randomness_value = value.FindKey("suppressRandomness");
  if (suppress_randomness_value) {
    errors->SetName("suppressRandomness");
    result->suppress_randomness_ = internal::FromValue<bool>::Parse(*suppress_randomness_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartSamplingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (sampling_interval_)
    result->Set("samplingInterval", internal::ToValue(sampling_interval_.value()));
  if (suppress_randomness_)
    result->Set("suppressRandomness", internal::ToValue(suppress_randomness_.value()));
  return std::move(result);
}

std::unique_ptr<StartSamplingParams> StartSamplingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartSamplingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartSamplingResult> StartSamplingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartSamplingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartSamplingResult> result(new StartSamplingResult());
  errors->Push();
  errors->SetName("StartSamplingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartSamplingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartSamplingResult> StartSamplingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartSamplingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopSamplingParams> StopSamplingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopSamplingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopSamplingParams> result(new StopSamplingParams());
  errors->Push();
  errors->SetName("StopSamplingParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopSamplingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopSamplingParams> StopSamplingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopSamplingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopSamplingResult> StopSamplingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopSamplingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopSamplingResult> result(new StopSamplingResult());
  errors->Push();
  errors->SetName("StopSamplingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopSamplingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopSamplingResult> StopSamplingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopSamplingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetAllTimeSamplingProfileParams> GetAllTimeSamplingProfileParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAllTimeSamplingProfileParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAllTimeSamplingProfileParams> result(new GetAllTimeSamplingProfileParams());
  errors->Push();
  errors->SetName("GetAllTimeSamplingProfileParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAllTimeSamplingProfileParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetAllTimeSamplingProfileParams> GetAllTimeSamplingProfileParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAllTimeSamplingProfileParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetAllTimeSamplingProfileResult> GetAllTimeSamplingProfileResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAllTimeSamplingProfileResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAllTimeSamplingProfileResult> result(new GetAllTimeSamplingProfileResult());
  errors->Push();
  errors->SetName("GetAllTimeSamplingProfileResult");
  const base::Value* profile_value = value.FindKey("profile");
  if (profile_value) {
    errors->SetName("profile");
    result->profile_ = internal::FromValue<::headless::memory::SamplingProfile>::Parse(*profile_value, errors);
  } else {
    errors->AddError("required property missing: profile");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAllTimeSamplingProfileResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("profile", internal::ToValue(*profile_));
  return std::move(result);
}

std::unique_ptr<GetAllTimeSamplingProfileResult> GetAllTimeSamplingProfileResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAllTimeSamplingProfileResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBrowserSamplingProfileParams> GetBrowserSamplingProfileParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBrowserSamplingProfileParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBrowserSamplingProfileParams> result(new GetBrowserSamplingProfileParams());
  errors->Push();
  errors->SetName("GetBrowserSamplingProfileParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBrowserSamplingProfileParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetBrowserSamplingProfileParams> GetBrowserSamplingProfileParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBrowserSamplingProfileParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBrowserSamplingProfileResult> GetBrowserSamplingProfileResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBrowserSamplingProfileResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBrowserSamplingProfileResult> result(new GetBrowserSamplingProfileResult());
  errors->Push();
  errors->SetName("GetBrowserSamplingProfileResult");
  const base::Value* profile_value = value.FindKey("profile");
  if (profile_value) {
    errors->SetName("profile");
    result->profile_ = internal::FromValue<::headless::memory::SamplingProfile>::Parse(*profile_value, errors);
  } else {
    errors->AddError("required property missing: profile");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBrowserSamplingProfileResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("profile", internal::ToValue(*profile_));
  return std::move(result);
}

std::unique_ptr<GetBrowserSamplingProfileResult> GetBrowserSamplingProfileResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBrowserSamplingProfileResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetSamplingProfileParams> GetSamplingProfileParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetSamplingProfileParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetSamplingProfileParams> result(new GetSamplingProfileParams());
  errors->Push();
  errors->SetName("GetSamplingProfileParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetSamplingProfileParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetSamplingProfileParams> GetSamplingProfileParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetSamplingProfileParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetSamplingProfileResult> GetSamplingProfileResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetSamplingProfileResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetSamplingProfileResult> result(new GetSamplingProfileResult());
  errors->Push();
  errors->SetName("GetSamplingProfileResult");
  const base::Value* profile_value = value.FindKey("profile");
  if (profile_value) {
    errors->SetName("profile");
    result->profile_ = internal::FromValue<::headless::memory::SamplingProfile>::Parse(*profile_value, errors);
  } else {
    errors->AddError("required property missing: profile");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetSamplingProfileResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("profile", internal::ToValue(*profile_));
  return std::move(result);
}

std::unique_ptr<GetSamplingProfileResult> GetSamplingProfileResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetSamplingProfileResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace memory
}  // namespace headless
