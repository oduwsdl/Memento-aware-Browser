// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_service_worker.h"
#include "headless/public/devtools/domains/types_target.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_browser.h"
#include "headless/public/devtools/internal/type_conversions_service_worker.h"
#include "headless/public/devtools/internal/type_conversions_target.h"

namespace headless {

namespace service_worker {

std::unique_ptr<ServiceWorkerRegistration> ServiceWorkerRegistration::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ServiceWorkerRegistration");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ServiceWorkerRegistration> result(new ServiceWorkerRegistration());
  errors->Push();
  errors->SetName("ServiceWorkerRegistration");
  const base::Value* registration_id_value = value.FindKey("registrationId");
  if (registration_id_value) {
    errors->SetName("registrationId");
    result->registration_id_ = internal::FromValue<std::string>::Parse(*registration_id_value, errors);
  } else {
    errors->AddError("required property missing: registrationId");
  }
  const base::Value* scopeurl_value = value.FindKey("scopeURL");
  if (scopeurl_value) {
    errors->SetName("scopeURL");
    result->scopeurl_ = internal::FromValue<std::string>::Parse(*scopeurl_value, errors);
  } else {
    errors->AddError("required property missing: scopeURL");
  }
  const base::Value* is_deleted_value = value.FindKey("isDeleted");
  if (is_deleted_value) {
    errors->SetName("isDeleted");
    result->is_deleted_ = internal::FromValue<bool>::Parse(*is_deleted_value, errors);
  } else {
    errors->AddError("required property missing: isDeleted");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ServiceWorkerRegistration::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("registrationId", internal::ToValue(registration_id_));
  result->Set("scopeURL", internal::ToValue(scopeurl_));
  result->Set("isDeleted", internal::ToValue(is_deleted_));
  return std::move(result);
}

std::unique_ptr<ServiceWorkerRegistration> ServiceWorkerRegistration::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ServiceWorkerRegistration> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ServiceWorkerVersion> ServiceWorkerVersion::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ServiceWorkerVersion");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ServiceWorkerVersion> result(new ServiceWorkerVersion());
  errors->Push();
  errors->SetName("ServiceWorkerVersion");
  const base::Value* version_id_value = value.FindKey("versionId");
  if (version_id_value) {
    errors->SetName("versionId");
    result->version_id_ = internal::FromValue<std::string>::Parse(*version_id_value, errors);
  } else {
    errors->AddError("required property missing: versionId");
  }
  const base::Value* registration_id_value = value.FindKey("registrationId");
  if (registration_id_value) {
    errors->SetName("registrationId");
    result->registration_id_ = internal::FromValue<std::string>::Parse(*registration_id_value, errors);
  } else {
    errors->AddError("required property missing: registrationId");
  }
  const base::Value* scripturl_value = value.FindKey("scriptURL");
  if (scripturl_value) {
    errors->SetName("scriptURL");
    result->scripturl_ = internal::FromValue<std::string>::Parse(*scripturl_value, errors);
  } else {
    errors->AddError("required property missing: scriptURL");
  }
  const base::Value* running_status_value = value.FindKey("runningStatus");
  if (running_status_value) {
    errors->SetName("runningStatus");
    result->running_status_ = internal::FromValue<::headless::service_worker::ServiceWorkerVersionRunningStatus>::Parse(*running_status_value, errors);
  } else {
    errors->AddError("required property missing: runningStatus");
  }
  const base::Value* status_value = value.FindKey("status");
  if (status_value) {
    errors->SetName("status");
    result->status_ = internal::FromValue<::headless::service_worker::ServiceWorkerVersionStatus>::Parse(*status_value, errors);
  } else {
    errors->AddError("required property missing: status");
  }
  const base::Value* script_last_modified_value = value.FindKey("scriptLastModified");
  if (script_last_modified_value) {
    errors->SetName("scriptLastModified");
    result->script_last_modified_ = internal::FromValue<double>::Parse(*script_last_modified_value, errors);
  }
  const base::Value* script_response_time_value = value.FindKey("scriptResponseTime");
  if (script_response_time_value) {
    errors->SetName("scriptResponseTime");
    result->script_response_time_ = internal::FromValue<double>::Parse(*script_response_time_value, errors);
  }
  const base::Value* controlled_clients_value = value.FindKey("controlledClients");
  if (controlled_clients_value) {
    errors->SetName("controlledClients");
    result->controlled_clients_ = internal::FromValue<std::vector<std::string>>::Parse(*controlled_clients_value, errors);
  }
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ServiceWorkerVersion::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("versionId", internal::ToValue(version_id_));
  result->Set("registrationId", internal::ToValue(registration_id_));
  result->Set("scriptURL", internal::ToValue(scripturl_));
  result->Set("runningStatus", internal::ToValue(running_status_));
  result->Set("status", internal::ToValue(status_));
  if (script_last_modified_)
    result->Set("scriptLastModified", internal::ToValue(script_last_modified_.value()));
  if (script_response_time_)
    result->Set("scriptResponseTime", internal::ToValue(script_response_time_.value()));
  if (controlled_clients_)
    result->Set("controlledClients", internal::ToValue(controlled_clients_.value()));
  if (target_id_)
    result->Set("targetId", internal::ToValue(target_id_.value()));
  return std::move(result);
}

std::unique_ptr<ServiceWorkerVersion> ServiceWorkerVersion::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ServiceWorkerVersion> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ServiceWorkerErrorMessage> ServiceWorkerErrorMessage::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ServiceWorkerErrorMessage");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ServiceWorkerErrorMessage> result(new ServiceWorkerErrorMessage());
  errors->Push();
  errors->SetName("ServiceWorkerErrorMessage");
  const base::Value* error_message_value = value.FindKey("errorMessage");
  if (error_message_value) {
    errors->SetName("errorMessage");
    result->error_message_ = internal::FromValue<std::string>::Parse(*error_message_value, errors);
  } else {
    errors->AddError("required property missing: errorMessage");
  }
  const base::Value* registration_id_value = value.FindKey("registrationId");
  if (registration_id_value) {
    errors->SetName("registrationId");
    result->registration_id_ = internal::FromValue<std::string>::Parse(*registration_id_value, errors);
  } else {
    errors->AddError("required property missing: registrationId");
  }
  const base::Value* version_id_value = value.FindKey("versionId");
  if (version_id_value) {
    errors->SetName("versionId");
    result->version_id_ = internal::FromValue<std::string>::Parse(*version_id_value, errors);
  } else {
    errors->AddError("required property missing: versionId");
  }
  const base::Value* sourceurl_value = value.FindKey("sourceURL");
  if (sourceurl_value) {
    errors->SetName("sourceURL");
    result->sourceurl_ = internal::FromValue<std::string>::Parse(*sourceurl_value, errors);
  } else {
    errors->AddError("required property missing: sourceURL");
  }
  const base::Value* line_number_value = value.FindKey("lineNumber");
  if (line_number_value) {
    errors->SetName("lineNumber");
    result->line_number_ = internal::FromValue<int>::Parse(*line_number_value, errors);
  } else {
    errors->AddError("required property missing: lineNumber");
  }
  const base::Value* column_number_value = value.FindKey("columnNumber");
  if (column_number_value) {
    errors->SetName("columnNumber");
    result->column_number_ = internal::FromValue<int>::Parse(*column_number_value, errors);
  } else {
    errors->AddError("required property missing: columnNumber");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ServiceWorkerErrorMessage::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("errorMessage", internal::ToValue(error_message_));
  result->Set("registrationId", internal::ToValue(registration_id_));
  result->Set("versionId", internal::ToValue(version_id_));
  result->Set("sourceURL", internal::ToValue(sourceurl_));
  result->Set("lineNumber", internal::ToValue(line_number_));
  result->Set("columnNumber", internal::ToValue(column_number_));
  return std::move(result);
}

std::unique_ptr<ServiceWorkerErrorMessage> ServiceWorkerErrorMessage::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ServiceWorkerErrorMessage> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeliverPushMessageParams> DeliverPushMessageParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeliverPushMessageParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeliverPushMessageParams> result(new DeliverPushMessageParams());
  errors->Push();
  errors->SetName("DeliverPushMessageParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* registration_id_value = value.FindKey("registrationId");
  if (registration_id_value) {
    errors->SetName("registrationId");
    result->registration_id_ = internal::FromValue<std::string>::Parse(*registration_id_value, errors);
  } else {
    errors->AddError("required property missing: registrationId");
  }
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<std::string>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeliverPushMessageParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  result->Set("registrationId", internal::ToValue(registration_id_));
  result->Set("data", internal::ToValue(data_));
  return std::move(result);
}

std::unique_ptr<DeliverPushMessageParams> DeliverPushMessageParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeliverPushMessageParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeliverPushMessageResult> DeliverPushMessageResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeliverPushMessageResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeliverPushMessageResult> result(new DeliverPushMessageResult());
  errors->Push();
  errors->SetName("DeliverPushMessageResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeliverPushMessageResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DeliverPushMessageResult> DeliverPushMessageResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeliverPushMessageResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<DispatchSyncEventParams> DispatchSyncEventParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchSyncEventParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchSyncEventParams> result(new DispatchSyncEventParams());
  errors->Push();
  errors->SetName("DispatchSyncEventParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* registration_id_value = value.FindKey("registrationId");
  if (registration_id_value) {
    errors->SetName("registrationId");
    result->registration_id_ = internal::FromValue<std::string>::Parse(*registration_id_value, errors);
  } else {
    errors->AddError("required property missing: registrationId");
  }
  const base::Value* tag_value = value.FindKey("tag");
  if (tag_value) {
    errors->SetName("tag");
    result->tag_ = internal::FromValue<std::string>::Parse(*tag_value, errors);
  } else {
    errors->AddError("required property missing: tag");
  }
  const base::Value* last_chance_value = value.FindKey("lastChance");
  if (last_chance_value) {
    errors->SetName("lastChance");
    result->last_chance_ = internal::FromValue<bool>::Parse(*last_chance_value, errors);
  } else {
    errors->AddError("required property missing: lastChance");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchSyncEventParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  result->Set("registrationId", internal::ToValue(registration_id_));
  result->Set("tag", internal::ToValue(tag_));
  result->Set("lastChance", internal::ToValue(last_chance_));
  return std::move(result);
}

std::unique_ptr<DispatchSyncEventParams> DispatchSyncEventParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchSyncEventParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchSyncEventResult> DispatchSyncEventResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchSyncEventResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchSyncEventResult> result(new DispatchSyncEventResult());
  errors->Push();
  errors->SetName("DispatchSyncEventResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchSyncEventResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DispatchSyncEventResult> DispatchSyncEventResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchSyncEventResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchPeriodicSyncEventParams> DispatchPeriodicSyncEventParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchPeriodicSyncEventParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchPeriodicSyncEventParams> result(new DispatchPeriodicSyncEventParams());
  errors->Push();
  errors->SetName("DispatchPeriodicSyncEventParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* registration_id_value = value.FindKey("registrationId");
  if (registration_id_value) {
    errors->SetName("registrationId");
    result->registration_id_ = internal::FromValue<std::string>::Parse(*registration_id_value, errors);
  } else {
    errors->AddError("required property missing: registrationId");
  }
  const base::Value* tag_value = value.FindKey("tag");
  if (tag_value) {
    errors->SetName("tag");
    result->tag_ = internal::FromValue<std::string>::Parse(*tag_value, errors);
  } else {
    errors->AddError("required property missing: tag");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchPeriodicSyncEventParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  result->Set("registrationId", internal::ToValue(registration_id_));
  result->Set("tag", internal::ToValue(tag_));
  return std::move(result);
}

std::unique_ptr<DispatchPeriodicSyncEventParams> DispatchPeriodicSyncEventParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchPeriodicSyncEventParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DispatchPeriodicSyncEventResult> DispatchPeriodicSyncEventResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DispatchPeriodicSyncEventResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DispatchPeriodicSyncEventResult> result(new DispatchPeriodicSyncEventResult());
  errors->Push();
  errors->SetName("DispatchPeriodicSyncEventResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DispatchPeriodicSyncEventResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DispatchPeriodicSyncEventResult> DispatchPeriodicSyncEventResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DispatchPeriodicSyncEventResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<InspectWorkerParams> InspectWorkerParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InspectWorkerParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InspectWorkerParams> result(new InspectWorkerParams());
  errors->Push();
  errors->SetName("InspectWorkerParams");
  const base::Value* version_id_value = value.FindKey("versionId");
  if (version_id_value) {
    errors->SetName("versionId");
    result->version_id_ = internal::FromValue<std::string>::Parse(*version_id_value, errors);
  } else {
    errors->AddError("required property missing: versionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InspectWorkerParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("versionId", internal::ToValue(version_id_));
  return std::move(result);
}

std::unique_ptr<InspectWorkerParams> InspectWorkerParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InspectWorkerParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InspectWorkerResult> InspectWorkerResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InspectWorkerResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InspectWorkerResult> result(new InspectWorkerResult());
  errors->Push();
  errors->SetName("InspectWorkerResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InspectWorkerResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<InspectWorkerResult> InspectWorkerResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InspectWorkerResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetForceUpdateOnPageLoadParams> SetForceUpdateOnPageLoadParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetForceUpdateOnPageLoadParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetForceUpdateOnPageLoadParams> result(new SetForceUpdateOnPageLoadParams());
  errors->Push();
  errors->SetName("SetForceUpdateOnPageLoadParams");
  const base::Value* force_update_on_page_load_value = value.FindKey("forceUpdateOnPageLoad");
  if (force_update_on_page_load_value) {
    errors->SetName("forceUpdateOnPageLoad");
    result->force_update_on_page_load_ = internal::FromValue<bool>::Parse(*force_update_on_page_load_value, errors);
  } else {
    errors->AddError("required property missing: forceUpdateOnPageLoad");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetForceUpdateOnPageLoadParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("forceUpdateOnPageLoad", internal::ToValue(force_update_on_page_load_));
  return std::move(result);
}

std::unique_ptr<SetForceUpdateOnPageLoadParams> SetForceUpdateOnPageLoadParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetForceUpdateOnPageLoadParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetForceUpdateOnPageLoadResult> SetForceUpdateOnPageLoadResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetForceUpdateOnPageLoadResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetForceUpdateOnPageLoadResult> result(new SetForceUpdateOnPageLoadResult());
  errors->Push();
  errors->SetName("SetForceUpdateOnPageLoadResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetForceUpdateOnPageLoadResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetForceUpdateOnPageLoadResult> SetForceUpdateOnPageLoadResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetForceUpdateOnPageLoadResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SkipWaitingParams> SkipWaitingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SkipWaitingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SkipWaitingParams> result(new SkipWaitingParams());
  errors->Push();
  errors->SetName("SkipWaitingParams");
  const base::Value* scopeurl_value = value.FindKey("scopeURL");
  if (scopeurl_value) {
    errors->SetName("scopeURL");
    result->scopeurl_ = internal::FromValue<std::string>::Parse(*scopeurl_value, errors);
  } else {
    errors->AddError("required property missing: scopeURL");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SkipWaitingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scopeURL", internal::ToValue(scopeurl_));
  return std::move(result);
}

std::unique_ptr<SkipWaitingParams> SkipWaitingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SkipWaitingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SkipWaitingResult> SkipWaitingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SkipWaitingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SkipWaitingResult> result(new SkipWaitingResult());
  errors->Push();
  errors->SetName("SkipWaitingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SkipWaitingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SkipWaitingResult> SkipWaitingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SkipWaitingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartWorkerParams> StartWorkerParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartWorkerParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartWorkerParams> result(new StartWorkerParams());
  errors->Push();
  errors->SetName("StartWorkerParams");
  const base::Value* scopeurl_value = value.FindKey("scopeURL");
  if (scopeurl_value) {
    errors->SetName("scopeURL");
    result->scopeurl_ = internal::FromValue<std::string>::Parse(*scopeurl_value, errors);
  } else {
    errors->AddError("required property missing: scopeURL");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartWorkerParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scopeURL", internal::ToValue(scopeurl_));
  return std::move(result);
}

std::unique_ptr<StartWorkerParams> StartWorkerParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartWorkerParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartWorkerResult> StartWorkerResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartWorkerResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartWorkerResult> result(new StartWorkerResult());
  errors->Push();
  errors->SetName("StartWorkerResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartWorkerResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartWorkerResult> StartWorkerResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartWorkerResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopAllWorkersParams> StopAllWorkersParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopAllWorkersParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopAllWorkersParams> result(new StopAllWorkersParams());
  errors->Push();
  errors->SetName("StopAllWorkersParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopAllWorkersParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopAllWorkersParams> StopAllWorkersParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopAllWorkersParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopAllWorkersResult> StopAllWorkersResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopAllWorkersResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopAllWorkersResult> result(new StopAllWorkersResult());
  errors->Push();
  errors->SetName("StopAllWorkersResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopAllWorkersResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopAllWorkersResult> StopAllWorkersResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopAllWorkersResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopWorkerParams> StopWorkerParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopWorkerParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopWorkerParams> result(new StopWorkerParams());
  errors->Push();
  errors->SetName("StopWorkerParams");
  const base::Value* version_id_value = value.FindKey("versionId");
  if (version_id_value) {
    errors->SetName("versionId");
    result->version_id_ = internal::FromValue<std::string>::Parse(*version_id_value, errors);
  } else {
    errors->AddError("required property missing: versionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopWorkerParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("versionId", internal::ToValue(version_id_));
  return std::move(result);
}

std::unique_ptr<StopWorkerParams> StopWorkerParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopWorkerParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopWorkerResult> StopWorkerResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopWorkerResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopWorkerResult> result(new StopWorkerResult());
  errors->Push();
  errors->SetName("StopWorkerResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopWorkerResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopWorkerResult> StopWorkerResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopWorkerResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UnregisterParams> UnregisterParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UnregisterParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UnregisterParams> result(new UnregisterParams());
  errors->Push();
  errors->SetName("UnregisterParams");
  const base::Value* scopeurl_value = value.FindKey("scopeURL");
  if (scopeurl_value) {
    errors->SetName("scopeURL");
    result->scopeurl_ = internal::FromValue<std::string>::Parse(*scopeurl_value, errors);
  } else {
    errors->AddError("required property missing: scopeURL");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UnregisterParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scopeURL", internal::ToValue(scopeurl_));
  return std::move(result);
}

std::unique_ptr<UnregisterParams> UnregisterParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UnregisterParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UnregisterResult> UnregisterResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UnregisterResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UnregisterResult> result(new UnregisterResult());
  errors->Push();
  errors->SetName("UnregisterResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UnregisterResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<UnregisterResult> UnregisterResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UnregisterResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UpdateRegistrationParams> UpdateRegistrationParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UpdateRegistrationParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UpdateRegistrationParams> result(new UpdateRegistrationParams());
  errors->Push();
  errors->SetName("UpdateRegistrationParams");
  const base::Value* scopeurl_value = value.FindKey("scopeURL");
  if (scopeurl_value) {
    errors->SetName("scopeURL");
    result->scopeurl_ = internal::FromValue<std::string>::Parse(*scopeurl_value, errors);
  } else {
    errors->AddError("required property missing: scopeURL");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UpdateRegistrationParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scopeURL", internal::ToValue(scopeurl_));
  return std::move(result);
}

std::unique_ptr<UpdateRegistrationParams> UpdateRegistrationParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UpdateRegistrationParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UpdateRegistrationResult> UpdateRegistrationResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UpdateRegistrationResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UpdateRegistrationResult> result(new UpdateRegistrationResult());
  errors->Push();
  errors->SetName("UpdateRegistrationResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UpdateRegistrationResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<UpdateRegistrationResult> UpdateRegistrationResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UpdateRegistrationResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WorkerErrorReportedParams> WorkerErrorReportedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WorkerErrorReportedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WorkerErrorReportedParams> result(new WorkerErrorReportedParams());
  errors->Push();
  errors->SetName("WorkerErrorReportedParams");
  const base::Value* error_message_value = value.FindKey("errorMessage");
  if (error_message_value) {
    errors->SetName("errorMessage");
    result->error_message_ = internal::FromValue<::headless::service_worker::ServiceWorkerErrorMessage>::Parse(*error_message_value, errors);
  } else {
    errors->AddError("required property missing: errorMessage");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WorkerErrorReportedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("errorMessage", internal::ToValue(*error_message_));
  return std::move(result);
}

std::unique_ptr<WorkerErrorReportedParams> WorkerErrorReportedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WorkerErrorReportedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WorkerRegistrationUpdatedParams> WorkerRegistrationUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WorkerRegistrationUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WorkerRegistrationUpdatedParams> result(new WorkerRegistrationUpdatedParams());
  errors->Push();
  errors->SetName("WorkerRegistrationUpdatedParams");
  const base::Value* registrations_value = value.FindKey("registrations");
  if (registrations_value) {
    errors->SetName("registrations");
    result->registrations_ = internal::FromValue<std::vector<std::unique_ptr<::headless::service_worker::ServiceWorkerRegistration>>>::Parse(*registrations_value, errors);
  } else {
    errors->AddError("required property missing: registrations");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WorkerRegistrationUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("registrations", internal::ToValue(registrations_));
  return std::move(result);
}

std::unique_ptr<WorkerRegistrationUpdatedParams> WorkerRegistrationUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WorkerRegistrationUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WorkerVersionUpdatedParams> WorkerVersionUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WorkerVersionUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WorkerVersionUpdatedParams> result(new WorkerVersionUpdatedParams());
  errors->Push();
  errors->SetName("WorkerVersionUpdatedParams");
  const base::Value* versions_value = value.FindKey("versions");
  if (versions_value) {
    errors->SetName("versions");
    result->versions_ = internal::FromValue<std::vector<std::unique_ptr<::headless::service_worker::ServiceWorkerVersion>>>::Parse(*versions_value, errors);
  } else {
    errors->AddError("required property missing: versions");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WorkerVersionUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("versions", internal::ToValue(versions_));
  return std::move(result);
}

std::unique_ptr<WorkerVersionUpdatedParams> WorkerVersionUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WorkerVersionUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace service_worker
}  // namespace headless
