// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_log.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_log.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace log {

std::unique_ptr<LogEntry> LogEntry::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LogEntry");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LogEntry> result(new LogEntry());
  errors->Push();
  errors->SetName("LogEntry");
  const base::Value* source_value = value.FindKey("source");
  if (source_value) {
    errors->SetName("source");
    result->source_ = internal::FromValue<::headless::log::LogEntrySource>::Parse(*source_value, errors);
  } else {
    errors->AddError("required property missing: source");
  }
  const base::Value* level_value = value.FindKey("level");
  if (level_value) {
    errors->SetName("level");
    result->level_ = internal::FromValue<::headless::log::LogEntryLevel>::Parse(*level_value, errors);
  } else {
    errors->AddError("required property missing: level");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* line_number_value = value.FindKey("lineNumber");
  if (line_number_value) {
    errors->SetName("lineNumber");
    result->line_number_ = internal::FromValue<int>::Parse(*line_number_value, errors);
  }
  const base::Value* stack_trace_value = value.FindKey("stackTrace");
  if (stack_trace_value) {
    errors->SetName("stackTrace");
    result->stack_trace_ = internal::FromValue<::headless::runtime::StackTrace>::Parse(*stack_trace_value, errors);
  }
  const base::Value* network_request_id_value = value.FindKey("networkRequestId");
  if (network_request_id_value) {
    errors->SetName("networkRequestId");
    result->network_request_id_ = internal::FromValue<std::string>::Parse(*network_request_id_value, errors);
  }
  const base::Value* worker_id_value = value.FindKey("workerId");
  if (worker_id_value) {
    errors->SetName("workerId");
    result->worker_id_ = internal::FromValue<std::string>::Parse(*worker_id_value, errors);
  }
  const base::Value* args_value = value.FindKey("args");
  if (args_value) {
    errors->SetName("args");
    result->args_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::RemoteObject>>>::Parse(*args_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LogEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("source", internal::ToValue(source_));
  result->Set("level", internal::ToValue(level_));
  result->Set("text", internal::ToValue(text_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (line_number_)
    result->Set("lineNumber", internal::ToValue(line_number_.value()));
  if (stack_trace_)
    result->Set("stackTrace", internal::ToValue(*stack_trace_.value()));
  if (network_request_id_)
    result->Set("networkRequestId", internal::ToValue(network_request_id_.value()));
  if (worker_id_)
    result->Set("workerId", internal::ToValue(worker_id_.value()));
  if (args_)
    result->Set("args", internal::ToValue(args_.value()));
  return std::move(result);
}

std::unique_ptr<LogEntry> LogEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LogEntry> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ViolationSetting> ViolationSetting::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ViolationSetting");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ViolationSetting> result(new ViolationSetting());
  errors->Push();
  errors->SetName("ViolationSetting");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<::headless::log::ViolationSettingName>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* threshold_value = value.FindKey("threshold");
  if (threshold_value) {
    errors->SetName("threshold");
    result->threshold_ = internal::FromValue<double>::Parse(*threshold_value, errors);
  } else {
    errors->AddError("required property missing: threshold");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ViolationSetting::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("threshold", internal::ToValue(threshold_));
  return std::move(result);
}

std::unique_ptr<ViolationSetting> ViolationSetting::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ViolationSetting> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearParams> ClearParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearParams> result(new ClearParams());
  errors->Push();
  errors->SetName("ClearParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearParams> ClearParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearResult> ClearResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearResult> result(new ClearResult());
  errors->Push();
  errors->SetName("ClearResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearResult> ClearResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<StartViolationsReportParams> StartViolationsReportParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartViolationsReportParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartViolationsReportParams> result(new StartViolationsReportParams());
  errors->Push();
  errors->SetName("StartViolationsReportParams");
  const base::Value* config_value = value.FindKey("config");
  if (config_value) {
    errors->SetName("config");
    result->config_ = internal::FromValue<std::vector<std::unique_ptr<::headless::log::ViolationSetting>>>::Parse(*config_value, errors);
  } else {
    errors->AddError("required property missing: config");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartViolationsReportParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("config", internal::ToValue(config_));
  return std::move(result);
}

std::unique_ptr<StartViolationsReportParams> StartViolationsReportParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartViolationsReportParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartViolationsReportResult> StartViolationsReportResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartViolationsReportResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartViolationsReportResult> result(new StartViolationsReportResult());
  errors->Push();
  errors->SetName("StartViolationsReportResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartViolationsReportResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartViolationsReportResult> StartViolationsReportResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartViolationsReportResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopViolationsReportParams> StopViolationsReportParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopViolationsReportParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopViolationsReportParams> result(new StopViolationsReportParams());
  errors->Push();
  errors->SetName("StopViolationsReportParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopViolationsReportParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopViolationsReportParams> StopViolationsReportParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopViolationsReportParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopViolationsReportResult> StopViolationsReportResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopViolationsReportResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopViolationsReportResult> result(new StopViolationsReportResult());
  errors->Push();
  errors->SetName("StopViolationsReportResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopViolationsReportResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopViolationsReportResult> StopViolationsReportResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopViolationsReportResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EntryAddedParams> EntryAddedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EntryAddedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EntryAddedParams> result(new EntryAddedParams());
  errors->Push();
  errors->SetName("EntryAddedParams");
  const base::Value* entry_value = value.FindKey("entry");
  if (entry_value) {
    errors->SetName("entry");
    result->entry_ = internal::FromValue<::headless::log::LogEntry>::Parse(*entry_value, errors);
  } else {
    errors->AddError("required property missing: entry");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EntryAddedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("entry", internal::ToValue(*entry_));
  return std::move(result);
}

std::unique_ptr<EntryAddedParams> EntryAddedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EntryAddedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace log
}  // namespace headless
