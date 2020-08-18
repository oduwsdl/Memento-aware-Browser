// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_heap_profiler.h"
#include "headless/public/devtools/domains/types_runtime.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_heap_profiler.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"

namespace headless {

namespace heap_profiler {

std::unique_ptr<SamplingHeapProfileNode> SamplingHeapProfileNode::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SamplingHeapProfileNode");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SamplingHeapProfileNode> result(new SamplingHeapProfileNode());
  errors->Push();
  errors->SetName("SamplingHeapProfileNode");
  const base::Value* call_frame_value = value.FindKey("callFrame");
  if (call_frame_value) {
    errors->SetName("callFrame");
    result->call_frame_ = internal::FromValue<::headless::runtime::CallFrame>::Parse(*call_frame_value, errors);
  } else {
    errors->AddError("required property missing: callFrame");
  }
  const base::Value* self_size_value = value.FindKey("selfSize");
  if (self_size_value) {
    errors->SetName("selfSize");
    result->self_size_ = internal::FromValue<double>::Parse(*self_size_value, errors);
  } else {
    errors->AddError("required property missing: selfSize");
  }
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<int>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* children_value = value.FindKey("children");
  if (children_value) {
    errors->SetName("children");
    result->children_ = internal::FromValue<std::vector<std::unique_ptr<::headless::heap_profiler::SamplingHeapProfileNode>>>::Parse(*children_value, errors);
  } else {
    errors->AddError("required property missing: children");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SamplingHeapProfileNode::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("callFrame", internal::ToValue(*call_frame_));
  result->Set("selfSize", internal::ToValue(self_size_));
  result->Set("id", internal::ToValue(id_));
  result->Set("children", internal::ToValue(children_));
  return std::move(result);
}

std::unique_ptr<SamplingHeapProfileNode> SamplingHeapProfileNode::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SamplingHeapProfileNode> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SamplingHeapProfileSample> SamplingHeapProfileSample::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SamplingHeapProfileSample");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SamplingHeapProfileSample> result(new SamplingHeapProfileSample());
  errors->Push();
  errors->SetName("SamplingHeapProfileSample");
  const base::Value* size_value = value.FindKey("size");
  if (size_value) {
    errors->SetName("size");
    result->size_ = internal::FromValue<double>::Parse(*size_value, errors);
  } else {
    errors->AddError("required property missing: size");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* ordinal_value = value.FindKey("ordinal");
  if (ordinal_value) {
    errors->SetName("ordinal");
    result->ordinal_ = internal::FromValue<double>::Parse(*ordinal_value, errors);
  } else {
    errors->AddError("required property missing: ordinal");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SamplingHeapProfileSample::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("size", internal::ToValue(size_));
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("ordinal", internal::ToValue(ordinal_));
  return std::move(result);
}

std::unique_ptr<SamplingHeapProfileSample> SamplingHeapProfileSample::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SamplingHeapProfileSample> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SamplingHeapProfile> SamplingHeapProfile::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SamplingHeapProfile");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SamplingHeapProfile> result(new SamplingHeapProfile());
  errors->Push();
  errors->SetName("SamplingHeapProfile");
  const base::Value* head_value = value.FindKey("head");
  if (head_value) {
    errors->SetName("head");
    result->head_ = internal::FromValue<::headless::heap_profiler::SamplingHeapProfileNode>::Parse(*head_value, errors);
  } else {
    errors->AddError("required property missing: head");
  }
  const base::Value* samples_value = value.FindKey("samples");
  if (samples_value) {
    errors->SetName("samples");
    result->samples_ = internal::FromValue<std::vector<std::unique_ptr<::headless::heap_profiler::SamplingHeapProfileSample>>>::Parse(*samples_value, errors);
  } else {
    errors->AddError("required property missing: samples");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SamplingHeapProfile::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("head", internal::ToValue(*head_));
  result->Set("samples", internal::ToValue(samples_));
  return std::move(result);
}

std::unique_ptr<SamplingHeapProfile> SamplingHeapProfile::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SamplingHeapProfile> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddInspectedHeapObjectParams> AddInspectedHeapObjectParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddInspectedHeapObjectParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddInspectedHeapObjectParams> result(new AddInspectedHeapObjectParams());
  errors->Push();
  errors->SetName("AddInspectedHeapObjectParams");
  const base::Value* heap_object_id_value = value.FindKey("heapObjectId");
  if (heap_object_id_value) {
    errors->SetName("heapObjectId");
    result->heap_object_id_ = internal::FromValue<std::string>::Parse(*heap_object_id_value, errors);
  } else {
    errors->AddError("required property missing: heapObjectId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddInspectedHeapObjectParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("heapObjectId", internal::ToValue(heap_object_id_));
  return std::move(result);
}

std::unique_ptr<AddInspectedHeapObjectParams> AddInspectedHeapObjectParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddInspectedHeapObjectParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddInspectedHeapObjectResult> AddInspectedHeapObjectResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddInspectedHeapObjectResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddInspectedHeapObjectResult> result(new AddInspectedHeapObjectResult());
  errors->Push();
  errors->SetName("AddInspectedHeapObjectResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddInspectedHeapObjectResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<AddInspectedHeapObjectResult> AddInspectedHeapObjectResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddInspectedHeapObjectResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CollectGarbageParams> CollectGarbageParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CollectGarbageParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CollectGarbageParams> result(new CollectGarbageParams());
  errors->Push();
  errors->SetName("CollectGarbageParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CollectGarbageParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CollectGarbageParams> CollectGarbageParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CollectGarbageParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CollectGarbageResult> CollectGarbageResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CollectGarbageResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CollectGarbageResult> result(new CollectGarbageResult());
  errors->Push();
  errors->SetName("CollectGarbageResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CollectGarbageResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CollectGarbageResult> CollectGarbageResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CollectGarbageResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<GetHeapObjectIdParams> GetHeapObjectIdParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHeapObjectIdParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHeapObjectIdParams> result(new GetHeapObjectIdParams());
  errors->Push();
  errors->SetName("GetHeapObjectIdParams");
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  } else {
    errors->AddError("required property missing: objectId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHeapObjectIdParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectId", internal::ToValue(object_id_));
  return std::move(result);
}

std::unique_ptr<GetHeapObjectIdParams> GetHeapObjectIdParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHeapObjectIdParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetHeapObjectIdResult> GetHeapObjectIdResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHeapObjectIdResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHeapObjectIdResult> result(new GetHeapObjectIdResult());
  errors->Push();
  errors->SetName("GetHeapObjectIdResult");
  const base::Value* heap_snapshot_object_id_value = value.FindKey("heapSnapshotObjectId");
  if (heap_snapshot_object_id_value) {
    errors->SetName("heapSnapshotObjectId");
    result->heap_snapshot_object_id_ = internal::FromValue<std::string>::Parse(*heap_snapshot_object_id_value, errors);
  } else {
    errors->AddError("required property missing: heapSnapshotObjectId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHeapObjectIdResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("heapSnapshotObjectId", internal::ToValue(heap_snapshot_object_id_));
  return std::move(result);
}

std::unique_ptr<GetHeapObjectIdResult> GetHeapObjectIdResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHeapObjectIdResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetObjectByHeapObjectIdParams> GetObjectByHeapObjectIdParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetObjectByHeapObjectIdParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetObjectByHeapObjectIdParams> result(new GetObjectByHeapObjectIdParams());
  errors->Push();
  errors->SetName("GetObjectByHeapObjectIdParams");
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  } else {
    errors->AddError("required property missing: objectId");
  }
  const base::Value* object_group_value = value.FindKey("objectGroup");
  if (object_group_value) {
    errors->SetName("objectGroup");
    result->object_group_ = internal::FromValue<std::string>::Parse(*object_group_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetObjectByHeapObjectIdParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectId", internal::ToValue(object_id_));
  if (object_group_)
    result->Set("objectGroup", internal::ToValue(object_group_.value()));
  return std::move(result);
}

std::unique_ptr<GetObjectByHeapObjectIdParams> GetObjectByHeapObjectIdParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetObjectByHeapObjectIdParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetObjectByHeapObjectIdResult> GetObjectByHeapObjectIdResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetObjectByHeapObjectIdResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetObjectByHeapObjectIdResult> result(new GetObjectByHeapObjectIdResult());
  errors->Push();
  errors->SetName("GetObjectByHeapObjectIdResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetObjectByHeapObjectIdResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(*result_));
  return std::move(result);
}

std::unique_ptr<GetObjectByHeapObjectIdResult> GetObjectByHeapObjectIdResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetObjectByHeapObjectIdResult> result = Parse(*Serialize(), &errors);
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
    result->profile_ = internal::FromValue<::headless::heap_profiler::SamplingHeapProfile>::Parse(*profile_value, errors);
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
    result->sampling_interval_ = internal::FromValue<double>::Parse(*sampling_interval_value, errors);
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


std::unique_ptr<StartTrackingHeapObjectsParams> StartTrackingHeapObjectsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartTrackingHeapObjectsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartTrackingHeapObjectsParams> result(new StartTrackingHeapObjectsParams());
  errors->Push();
  errors->SetName("StartTrackingHeapObjectsParams");
  const base::Value* track_allocations_value = value.FindKey("trackAllocations");
  if (track_allocations_value) {
    errors->SetName("trackAllocations");
    result->track_allocations_ = internal::FromValue<bool>::Parse(*track_allocations_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartTrackingHeapObjectsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (track_allocations_)
    result->Set("trackAllocations", internal::ToValue(track_allocations_.value()));
  return std::move(result);
}

std::unique_ptr<StartTrackingHeapObjectsParams> StartTrackingHeapObjectsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartTrackingHeapObjectsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartTrackingHeapObjectsResult> StartTrackingHeapObjectsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartTrackingHeapObjectsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartTrackingHeapObjectsResult> result(new StartTrackingHeapObjectsResult());
  errors->Push();
  errors->SetName("StartTrackingHeapObjectsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartTrackingHeapObjectsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartTrackingHeapObjectsResult> StartTrackingHeapObjectsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartTrackingHeapObjectsResult> result = Parse(*Serialize(), &errors);
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
  const base::Value* profile_value = value.FindKey("profile");
  if (profile_value) {
    errors->SetName("profile");
    result->profile_ = internal::FromValue<::headless::heap_profiler::SamplingHeapProfile>::Parse(*profile_value, errors);
  } else {
    errors->AddError("required property missing: profile");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopSamplingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("profile", internal::ToValue(*profile_));
  return std::move(result);
}

std::unique_ptr<StopSamplingResult> StopSamplingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopSamplingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopTrackingHeapObjectsParams> StopTrackingHeapObjectsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopTrackingHeapObjectsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopTrackingHeapObjectsParams> result(new StopTrackingHeapObjectsParams());
  errors->Push();
  errors->SetName("StopTrackingHeapObjectsParams");
  const base::Value* report_progress_value = value.FindKey("reportProgress");
  if (report_progress_value) {
    errors->SetName("reportProgress");
    result->report_progress_ = internal::FromValue<bool>::Parse(*report_progress_value, errors);
  }
  const base::Value* treat_global_objects_as_roots_value = value.FindKey("treatGlobalObjectsAsRoots");
  if (treat_global_objects_as_roots_value) {
    errors->SetName("treatGlobalObjectsAsRoots");
    result->treat_global_objects_as_roots_ = internal::FromValue<bool>::Parse(*treat_global_objects_as_roots_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopTrackingHeapObjectsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (report_progress_)
    result->Set("reportProgress", internal::ToValue(report_progress_.value()));
  if (treat_global_objects_as_roots_)
    result->Set("treatGlobalObjectsAsRoots", internal::ToValue(treat_global_objects_as_roots_.value()));
  return std::move(result);
}

std::unique_ptr<StopTrackingHeapObjectsParams> StopTrackingHeapObjectsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopTrackingHeapObjectsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopTrackingHeapObjectsResult> StopTrackingHeapObjectsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopTrackingHeapObjectsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopTrackingHeapObjectsResult> result(new StopTrackingHeapObjectsResult());
  errors->Push();
  errors->SetName("StopTrackingHeapObjectsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopTrackingHeapObjectsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopTrackingHeapObjectsResult> StopTrackingHeapObjectsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopTrackingHeapObjectsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeHeapSnapshotParams> TakeHeapSnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeHeapSnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeHeapSnapshotParams> result(new TakeHeapSnapshotParams());
  errors->Push();
  errors->SetName("TakeHeapSnapshotParams");
  const base::Value* report_progress_value = value.FindKey("reportProgress");
  if (report_progress_value) {
    errors->SetName("reportProgress");
    result->report_progress_ = internal::FromValue<bool>::Parse(*report_progress_value, errors);
  }
  const base::Value* treat_global_objects_as_roots_value = value.FindKey("treatGlobalObjectsAsRoots");
  if (treat_global_objects_as_roots_value) {
    errors->SetName("treatGlobalObjectsAsRoots");
    result->treat_global_objects_as_roots_ = internal::FromValue<bool>::Parse(*treat_global_objects_as_roots_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeHeapSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (report_progress_)
    result->Set("reportProgress", internal::ToValue(report_progress_.value()));
  if (treat_global_objects_as_roots_)
    result->Set("treatGlobalObjectsAsRoots", internal::ToValue(treat_global_objects_as_roots_.value()));
  return std::move(result);
}

std::unique_ptr<TakeHeapSnapshotParams> TakeHeapSnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeHeapSnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeHeapSnapshotResult> TakeHeapSnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeHeapSnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeHeapSnapshotResult> result(new TakeHeapSnapshotResult());
  errors->Push();
  errors->SetName("TakeHeapSnapshotResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeHeapSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TakeHeapSnapshotResult> TakeHeapSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeHeapSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddHeapSnapshotChunkParams> AddHeapSnapshotChunkParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddHeapSnapshotChunkParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddHeapSnapshotChunkParams> result(new AddHeapSnapshotChunkParams());
  errors->Push();
  errors->SetName("AddHeapSnapshotChunkParams");
  const base::Value* chunk_value = value.FindKey("chunk");
  if (chunk_value) {
    errors->SetName("chunk");
    result->chunk_ = internal::FromValue<std::string>::Parse(*chunk_value, errors);
  } else {
    errors->AddError("required property missing: chunk");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddHeapSnapshotChunkParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("chunk", internal::ToValue(chunk_));
  return std::move(result);
}

std::unique_ptr<AddHeapSnapshotChunkParams> AddHeapSnapshotChunkParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddHeapSnapshotChunkParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HeapStatsUpdateParams> HeapStatsUpdateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HeapStatsUpdateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HeapStatsUpdateParams> result(new HeapStatsUpdateParams());
  errors->Push();
  errors->SetName("HeapStatsUpdateParams");
  const base::Value* stats_update_value = value.FindKey("statsUpdate");
  if (stats_update_value) {
    errors->SetName("statsUpdate");
    result->stats_update_ = internal::FromValue<std::vector<int>>::Parse(*stats_update_value, errors);
  } else {
    errors->AddError("required property missing: statsUpdate");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HeapStatsUpdateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("statsUpdate", internal::ToValue(stats_update_));
  return std::move(result);
}

std::unique_ptr<HeapStatsUpdateParams> HeapStatsUpdateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HeapStatsUpdateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LastSeenObjectIdParams> LastSeenObjectIdParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LastSeenObjectIdParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LastSeenObjectIdParams> result(new LastSeenObjectIdParams());
  errors->Push();
  errors->SetName("LastSeenObjectIdParams");
  const base::Value* last_seen_object_id_value = value.FindKey("lastSeenObjectId");
  if (last_seen_object_id_value) {
    errors->SetName("lastSeenObjectId");
    result->last_seen_object_id_ = internal::FromValue<int>::Parse(*last_seen_object_id_value, errors);
  } else {
    errors->AddError("required property missing: lastSeenObjectId");
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

std::unique_ptr<base::Value> LastSeenObjectIdParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("lastSeenObjectId", internal::ToValue(last_seen_object_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<LastSeenObjectIdParams> LastSeenObjectIdParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LastSeenObjectIdParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReportHeapSnapshotProgressParams> ReportHeapSnapshotProgressParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReportHeapSnapshotProgressParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReportHeapSnapshotProgressParams> result(new ReportHeapSnapshotProgressParams());
  errors->Push();
  errors->SetName("ReportHeapSnapshotProgressParams");
  const base::Value* done_value = value.FindKey("done");
  if (done_value) {
    errors->SetName("done");
    result->done_ = internal::FromValue<int>::Parse(*done_value, errors);
  } else {
    errors->AddError("required property missing: done");
  }
  const base::Value* total_value = value.FindKey("total");
  if (total_value) {
    errors->SetName("total");
    result->total_ = internal::FromValue<int>::Parse(*total_value, errors);
  } else {
    errors->AddError("required property missing: total");
  }
  const base::Value* finished_value = value.FindKey("finished");
  if (finished_value) {
    errors->SetName("finished");
    result->finished_ = internal::FromValue<bool>::Parse(*finished_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReportHeapSnapshotProgressParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("done", internal::ToValue(done_));
  result->Set("total", internal::ToValue(total_));
  if (finished_)
    result->Set("finished", internal::ToValue(finished_.value()));
  return std::move(result);
}

std::unique_ptr<ReportHeapSnapshotProgressParams> ReportHeapSnapshotProgressParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReportHeapSnapshotProgressParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResetProfilesParams> ResetProfilesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResetProfilesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResetProfilesParams> result(new ResetProfilesParams());
  errors->Push();
  errors->SetName("ResetProfilesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResetProfilesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ResetProfilesParams> ResetProfilesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResetProfilesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace heap_profiler
}  // namespace headless
