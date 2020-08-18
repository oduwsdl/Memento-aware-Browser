// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_cast.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_cast.h"

namespace headless {

namespace cast {

std::unique_ptr<Sink> Sink::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Sink");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Sink> result(new Sink());
  errors->Push();
  errors->SetName("Sink");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* session_value = value.FindKey("session");
  if (session_value) {
    errors->SetName("session");
    result->session_ = internal::FromValue<std::string>::Parse(*session_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Sink::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("id", internal::ToValue(id_));
  if (session_)
    result->Set("session", internal::ToValue(session_.value()));
  return std::move(result);
}

std::unique_ptr<Sink> Sink::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Sink> result = Parse(*Serialize(), &errors);
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
  const base::Value* presentation_url_value = value.FindKey("presentationUrl");
  if (presentation_url_value) {
    errors->SetName("presentationUrl");
    result->presentation_url_ = internal::FromValue<std::string>::Parse(*presentation_url_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (presentation_url_)
    result->Set("presentationUrl", internal::ToValue(presentation_url_.value()));
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


std::unique_ptr<SetSinkToUseParams> SetSinkToUseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetSinkToUseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetSinkToUseParams> result(new SetSinkToUseParams());
  errors->Push();
  errors->SetName("SetSinkToUseParams");
  const base::Value* sink_name_value = value.FindKey("sinkName");
  if (sink_name_value) {
    errors->SetName("sinkName");
    result->sink_name_ = internal::FromValue<std::string>::Parse(*sink_name_value, errors);
  } else {
    errors->AddError("required property missing: sinkName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetSinkToUseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sinkName", internal::ToValue(sink_name_));
  return std::move(result);
}

std::unique_ptr<SetSinkToUseParams> SetSinkToUseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetSinkToUseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetSinkToUseResult> SetSinkToUseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetSinkToUseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetSinkToUseResult> result(new SetSinkToUseResult());
  errors->Push();
  errors->SetName("SetSinkToUseResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetSinkToUseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetSinkToUseResult> SetSinkToUseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetSinkToUseResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartTabMirroringParams> StartTabMirroringParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartTabMirroringParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartTabMirroringParams> result(new StartTabMirroringParams());
  errors->Push();
  errors->SetName("StartTabMirroringParams");
  const base::Value* sink_name_value = value.FindKey("sinkName");
  if (sink_name_value) {
    errors->SetName("sinkName");
    result->sink_name_ = internal::FromValue<std::string>::Parse(*sink_name_value, errors);
  } else {
    errors->AddError("required property missing: sinkName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartTabMirroringParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sinkName", internal::ToValue(sink_name_));
  return std::move(result);
}

std::unique_ptr<StartTabMirroringParams> StartTabMirroringParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartTabMirroringParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartTabMirroringResult> StartTabMirroringResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartTabMirroringResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartTabMirroringResult> result(new StartTabMirroringResult());
  errors->Push();
  errors->SetName("StartTabMirroringResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartTabMirroringResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartTabMirroringResult> StartTabMirroringResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartTabMirroringResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopCastingParams> StopCastingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopCastingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopCastingParams> result(new StopCastingParams());
  errors->Push();
  errors->SetName("StopCastingParams");
  const base::Value* sink_name_value = value.FindKey("sinkName");
  if (sink_name_value) {
    errors->SetName("sinkName");
    result->sink_name_ = internal::FromValue<std::string>::Parse(*sink_name_value, errors);
  } else {
    errors->AddError("required property missing: sinkName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopCastingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sinkName", internal::ToValue(sink_name_));
  return std::move(result);
}

std::unique_ptr<StopCastingParams> StopCastingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopCastingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopCastingResult> StopCastingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopCastingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopCastingResult> result(new StopCastingResult());
  errors->Push();
  errors->SetName("StopCastingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopCastingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopCastingResult> StopCastingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopCastingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SinksUpdatedParams> SinksUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SinksUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SinksUpdatedParams> result(new SinksUpdatedParams());
  errors->Push();
  errors->SetName("SinksUpdatedParams");
  const base::Value* sinks_value = value.FindKey("sinks");
  if (sinks_value) {
    errors->SetName("sinks");
    result->sinks_ = internal::FromValue<std::vector<std::unique_ptr<::headless::cast::Sink>>>::Parse(*sinks_value, errors);
  } else {
    errors->AddError("required property missing: sinks");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SinksUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("sinks", internal::ToValue(sinks_));
  return std::move(result);
}

std::unique_ptr<SinksUpdatedParams> SinksUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SinksUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<IssueUpdatedParams> IssueUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("IssueUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<IssueUpdatedParams> result(new IssueUpdatedParams());
  errors->Push();
  errors->SetName("IssueUpdatedParams");
  const base::Value* issue_message_value = value.FindKey("issueMessage");
  if (issue_message_value) {
    errors->SetName("issueMessage");
    result->issue_message_ = internal::FromValue<std::string>::Parse(*issue_message_value, errors);
  } else {
    errors->AddError("required property missing: issueMessage");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> IssueUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("issueMessage", internal::ToValue(issue_message_));
  return std::move(result);
}

std::unique_ptr<IssueUpdatedParams> IssueUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<IssueUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace cast
}  // namespace headless
