// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_background_service.h"
#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/devtools/domains/types_service_worker.h"
#include "headless/public/devtools/domains/types_target.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_background_service.h"
#include "headless/public/devtools/internal/type_conversions_browser.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"
#include "headless/public/devtools/internal/type_conversions_service_worker.h"
#include "headless/public/devtools/internal/type_conversions_target.h"

namespace headless {

namespace background_service {

std::unique_ptr<EventMetadata> EventMetadata::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EventMetadata");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EventMetadata> result(new EventMetadata());
  errors->Push();
  errors->SetName("EventMetadata");
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<std::string>::Parse(*key_value, errors);
  } else {
    errors->AddError("required property missing: key");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EventMetadata::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("key", internal::ToValue(key_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<EventMetadata> EventMetadata::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EventMetadata> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BackgroundServiceEvent> BackgroundServiceEvent::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BackgroundServiceEvent");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BackgroundServiceEvent> result(new BackgroundServiceEvent());
  errors->Push();
  errors->SetName("BackgroundServiceEvent");
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* service_worker_registration_id_value = value.FindKey("serviceWorkerRegistrationId");
  if (service_worker_registration_id_value) {
    errors->SetName("serviceWorkerRegistrationId");
    result->service_worker_registration_id_ = internal::FromValue<std::string>::Parse(*service_worker_registration_id_value, errors);
  } else {
    errors->AddError("required property missing: serviceWorkerRegistrationId");
  }
  const base::Value* service_value = value.FindKey("service");
  if (service_value) {
    errors->SetName("service");
    result->service_ = internal::FromValue<::headless::background_service::ServiceName>::Parse(*service_value, errors);
  } else {
    errors->AddError("required property missing: service");
  }
  const base::Value* event_name_value = value.FindKey("eventName");
  if (event_name_value) {
    errors->SetName("eventName");
    result->event_name_ = internal::FromValue<std::string>::Parse(*event_name_value, errors);
  } else {
    errors->AddError("required property missing: eventName");
  }
  const base::Value* instance_id_value = value.FindKey("instanceId");
  if (instance_id_value) {
    errors->SetName("instanceId");
    result->instance_id_ = internal::FromValue<std::string>::Parse(*instance_id_value, errors);
  } else {
    errors->AddError("required property missing: instanceId");
  }
  const base::Value* event_metadata_value = value.FindKey("eventMetadata");
  if (event_metadata_value) {
    errors->SetName("eventMetadata");
    result->event_metadata_ = internal::FromValue<std::vector<std::unique_ptr<::headless::background_service::EventMetadata>>>::Parse(*event_metadata_value, errors);
  } else {
    errors->AddError("required property missing: eventMetadata");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BackgroundServiceEvent::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("origin", internal::ToValue(origin_));
  result->Set("serviceWorkerRegistrationId", internal::ToValue(service_worker_registration_id_));
  result->Set("service", internal::ToValue(service_));
  result->Set("eventName", internal::ToValue(event_name_));
  result->Set("instanceId", internal::ToValue(instance_id_));
  result->Set("eventMetadata", internal::ToValue(event_metadata_));
  return std::move(result);
}

std::unique_ptr<BackgroundServiceEvent> BackgroundServiceEvent::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BackgroundServiceEvent> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartObservingParams> StartObservingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartObservingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartObservingParams> result(new StartObservingParams());
  errors->Push();
  errors->SetName("StartObservingParams");
  const base::Value* service_value = value.FindKey("service");
  if (service_value) {
    errors->SetName("service");
    result->service_ = internal::FromValue<::headless::background_service::ServiceName>::Parse(*service_value, errors);
  } else {
    errors->AddError("required property missing: service");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartObservingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("service", internal::ToValue(service_));
  return std::move(result);
}

std::unique_ptr<StartObservingParams> StartObservingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartObservingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartObservingResult> StartObservingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartObservingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartObservingResult> result(new StartObservingResult());
  errors->Push();
  errors->SetName("StartObservingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartObservingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartObservingResult> StartObservingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartObservingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopObservingParams> StopObservingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopObservingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopObservingParams> result(new StopObservingParams());
  errors->Push();
  errors->SetName("StopObservingParams");
  const base::Value* service_value = value.FindKey("service");
  if (service_value) {
    errors->SetName("service");
    result->service_ = internal::FromValue<::headless::background_service::ServiceName>::Parse(*service_value, errors);
  } else {
    errors->AddError("required property missing: service");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopObservingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("service", internal::ToValue(service_));
  return std::move(result);
}

std::unique_ptr<StopObservingParams> StopObservingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopObservingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopObservingResult> StopObservingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopObservingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopObservingResult> result(new StopObservingResult());
  errors->Push();
  errors->SetName("StopObservingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopObservingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopObservingResult> StopObservingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopObservingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRecordingParams> SetRecordingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRecordingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRecordingParams> result(new SetRecordingParams());
  errors->Push();
  errors->SetName("SetRecordingParams");
  const base::Value* should_record_value = value.FindKey("shouldRecord");
  if (should_record_value) {
    errors->SetName("shouldRecord");
    result->should_record_ = internal::FromValue<bool>::Parse(*should_record_value, errors);
  } else {
    errors->AddError("required property missing: shouldRecord");
  }
  const base::Value* service_value = value.FindKey("service");
  if (service_value) {
    errors->SetName("service");
    result->service_ = internal::FromValue<::headless::background_service::ServiceName>::Parse(*service_value, errors);
  } else {
    errors->AddError("required property missing: service");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRecordingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("shouldRecord", internal::ToValue(should_record_));
  result->Set("service", internal::ToValue(service_));
  return std::move(result);
}

std::unique_ptr<SetRecordingParams> SetRecordingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRecordingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRecordingResult> SetRecordingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRecordingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRecordingResult> result(new SetRecordingResult());
  errors->Push();
  errors->SetName("SetRecordingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRecordingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetRecordingResult> SetRecordingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRecordingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearEventsParams> ClearEventsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearEventsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearEventsParams> result(new ClearEventsParams());
  errors->Push();
  errors->SetName("ClearEventsParams");
  const base::Value* service_value = value.FindKey("service");
  if (service_value) {
    errors->SetName("service");
    result->service_ = internal::FromValue<::headless::background_service::ServiceName>::Parse(*service_value, errors);
  } else {
    errors->AddError("required property missing: service");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearEventsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("service", internal::ToValue(service_));
  return std::move(result);
}

std::unique_ptr<ClearEventsParams> ClearEventsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearEventsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearEventsResult> ClearEventsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearEventsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearEventsResult> result(new ClearEventsResult());
  errors->Push();
  errors->SetName("ClearEventsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearEventsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearEventsResult> ClearEventsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearEventsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RecordingStateChangedParams> RecordingStateChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RecordingStateChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RecordingStateChangedParams> result(new RecordingStateChangedParams());
  errors->Push();
  errors->SetName("RecordingStateChangedParams");
  const base::Value* is_recording_value = value.FindKey("isRecording");
  if (is_recording_value) {
    errors->SetName("isRecording");
    result->is_recording_ = internal::FromValue<bool>::Parse(*is_recording_value, errors);
  } else {
    errors->AddError("required property missing: isRecording");
  }
  const base::Value* service_value = value.FindKey("service");
  if (service_value) {
    errors->SetName("service");
    result->service_ = internal::FromValue<::headless::background_service::ServiceName>::Parse(*service_value, errors);
  } else {
    errors->AddError("required property missing: service");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RecordingStateChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("isRecording", internal::ToValue(is_recording_));
  result->Set("service", internal::ToValue(service_));
  return std::move(result);
}

std::unique_ptr<RecordingStateChangedParams> RecordingStateChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RecordingStateChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BackgroundServiceEventReceivedParams> BackgroundServiceEventReceivedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BackgroundServiceEventReceivedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BackgroundServiceEventReceivedParams> result(new BackgroundServiceEventReceivedParams());
  errors->Push();
  errors->SetName("BackgroundServiceEventReceivedParams");
  const base::Value* background_service_event_value = value.FindKey("backgroundServiceEvent");
  if (background_service_event_value) {
    errors->SetName("backgroundServiceEvent");
    result->background_service_event_ = internal::FromValue<::headless::background_service::BackgroundServiceEvent>::Parse(*background_service_event_value, errors);
  } else {
    errors->AddError("required property missing: backgroundServiceEvent");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BackgroundServiceEventReceivedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("backgroundServiceEvent", internal::ToValue(*background_service_event_));
  return std::move(result);
}

std::unique_ptr<BackgroundServiceEventReceivedParams> BackgroundServiceEventReceivedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BackgroundServiceEventReceivedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace background_service
}  // namespace headless
