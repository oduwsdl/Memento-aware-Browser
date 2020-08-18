// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_console.h"
#include "headless/public/devtools/domains/types_runtime.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_console.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"

namespace headless {

namespace console {

std::unique_ptr<ConsoleMessage> ConsoleMessage::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ConsoleMessage");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ConsoleMessage> result(new ConsoleMessage());
  errors->Push();
  errors->SetName("ConsoleMessage");
  const base::Value* source_value = value.FindKey("source");
  if (source_value) {
    errors->SetName("source");
    result->source_ = internal::FromValue<::headless::console::ConsoleMessageSource>::Parse(*source_value, errors);
  } else {
    errors->AddError("required property missing: source");
  }
  const base::Value* level_value = value.FindKey("level");
  if (level_value) {
    errors->SetName("level");
    result->level_ = internal::FromValue<::headless::console::ConsoleMessageLevel>::Parse(*level_value, errors);
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
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* line_value = value.FindKey("line");
  if (line_value) {
    errors->SetName("line");
    result->line_ = internal::FromValue<int>::Parse(*line_value, errors);
  }
  const base::Value* column_value = value.FindKey("column");
  if (column_value) {
    errors->SetName("column");
    result->column_ = internal::FromValue<int>::Parse(*column_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ConsoleMessage::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("source", internal::ToValue(source_));
  result->Set("level", internal::ToValue(level_));
  result->Set("text", internal::ToValue(text_));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (line_)
    result->Set("line", internal::ToValue(line_.value()));
  if (column_)
    result->Set("column", internal::ToValue(column_.value()));
  return std::move(result);
}

std::unique_ptr<ConsoleMessage> ConsoleMessage::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ConsoleMessage> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearMessagesParams> ClearMessagesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearMessagesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearMessagesParams> result(new ClearMessagesParams());
  errors->Push();
  errors->SetName("ClearMessagesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearMessagesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearMessagesParams> ClearMessagesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearMessagesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearMessagesResult> ClearMessagesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearMessagesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearMessagesResult> result(new ClearMessagesResult());
  errors->Push();
  errors->SetName("ClearMessagesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearMessagesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearMessagesResult> ClearMessagesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearMessagesResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<MessageAddedParams> MessageAddedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MessageAddedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MessageAddedParams> result(new MessageAddedParams());
  errors->Push();
  errors->SetName("MessageAddedParams");
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<::headless::console::ConsoleMessage>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MessageAddedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("message", internal::ToValue(*message_));
  return std::move(result);
}

std::unique_ptr<MessageAddedParams> MessageAddedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MessageAddedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace console
}  // namespace headless
