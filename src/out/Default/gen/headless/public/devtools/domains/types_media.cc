// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_media.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_media.h"

namespace headless {

namespace media {

std::unique_ptr<PlayerMessage> PlayerMessage::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerMessage");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerMessage> result(new PlayerMessage());
  errors->Push();
  errors->SetName("PlayerMessage");
  const base::Value* level_value = value.FindKey("level");
  if (level_value) {
    errors->SetName("level");
    result->level_ = internal::FromValue<::headless::media::PlayerMessageLevel>::Parse(*level_value, errors);
  } else {
    errors->AddError("required property missing: level");
  }
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlayerMessage::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("level", internal::ToValue(level_));
  result->Set("message", internal::ToValue(message_));
  return std::move(result);
}

std::unique_ptr<PlayerMessage> PlayerMessage::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerMessage> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlayerProperty> PlayerProperty::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerProperty");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerProperty> result(new PlayerProperty());
  errors->Push();
  errors->SetName("PlayerProperty");
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

std::unique_ptr<base::Value> PlayerProperty::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<PlayerProperty> PlayerProperty::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerProperty> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlayerEvent> PlayerEvent::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerEvent");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerEvent> result(new PlayerEvent());
  errors->Push();
  errors->SetName("PlayerEvent");
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
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

std::unique_ptr<base::Value> PlayerEvent::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<PlayerEvent> PlayerEvent::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerEvent> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlayerError> PlayerError::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerError");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerError> result(new PlayerError());
  errors->Push();
  errors->SetName("PlayerError");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::media::PlayerErrorType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* error_code_value = value.FindKey("errorCode");
  if (error_code_value) {
    errors->SetName("errorCode");
    result->error_code_ = internal::FromValue<std::string>::Parse(*error_code_value, errors);
  } else {
    errors->AddError("required property missing: errorCode");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlayerError::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  result->Set("errorCode", internal::ToValue(error_code_));
  return std::move(result);
}

std::unique_ptr<PlayerError> PlayerError::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerError> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<PlayerPropertiesChangedParams> PlayerPropertiesChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerPropertiesChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerPropertiesChangedParams> result(new PlayerPropertiesChangedParams());
  errors->Push();
  errors->SetName("PlayerPropertiesChangedParams");
  const base::Value* player_id_value = value.FindKey("playerId");
  if (player_id_value) {
    errors->SetName("playerId");
    result->player_id_ = internal::FromValue<std::string>::Parse(*player_id_value, errors);
  } else {
    errors->AddError("required property missing: playerId");
  }
  const base::Value* properties_value = value.FindKey("properties");
  if (properties_value) {
    errors->SetName("properties");
    result->properties_ = internal::FromValue<std::vector<std::unique_ptr<::headless::media::PlayerProperty>>>::Parse(*properties_value, errors);
  } else {
    errors->AddError("required property missing: properties");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlayerPropertiesChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("playerId", internal::ToValue(player_id_));
  result->Set("properties", internal::ToValue(properties_));
  return std::move(result);
}

std::unique_ptr<PlayerPropertiesChangedParams> PlayerPropertiesChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerPropertiesChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlayerEventsAddedParams> PlayerEventsAddedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerEventsAddedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerEventsAddedParams> result(new PlayerEventsAddedParams());
  errors->Push();
  errors->SetName("PlayerEventsAddedParams");
  const base::Value* player_id_value = value.FindKey("playerId");
  if (player_id_value) {
    errors->SetName("playerId");
    result->player_id_ = internal::FromValue<std::string>::Parse(*player_id_value, errors);
  } else {
    errors->AddError("required property missing: playerId");
  }
  const base::Value* events_value = value.FindKey("events");
  if (events_value) {
    errors->SetName("events");
    result->events_ = internal::FromValue<std::vector<std::unique_ptr<::headless::media::PlayerEvent>>>::Parse(*events_value, errors);
  } else {
    errors->AddError("required property missing: events");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlayerEventsAddedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("playerId", internal::ToValue(player_id_));
  result->Set("events", internal::ToValue(events_));
  return std::move(result);
}

std::unique_ptr<PlayerEventsAddedParams> PlayerEventsAddedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerEventsAddedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlayerMessagesLoggedParams> PlayerMessagesLoggedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerMessagesLoggedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerMessagesLoggedParams> result(new PlayerMessagesLoggedParams());
  errors->Push();
  errors->SetName("PlayerMessagesLoggedParams");
  const base::Value* player_id_value = value.FindKey("playerId");
  if (player_id_value) {
    errors->SetName("playerId");
    result->player_id_ = internal::FromValue<std::string>::Parse(*player_id_value, errors);
  } else {
    errors->AddError("required property missing: playerId");
  }
  const base::Value* messages_value = value.FindKey("messages");
  if (messages_value) {
    errors->SetName("messages");
    result->messages_ = internal::FromValue<std::vector<std::unique_ptr<::headless::media::PlayerMessage>>>::Parse(*messages_value, errors);
  } else {
    errors->AddError("required property missing: messages");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlayerMessagesLoggedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("playerId", internal::ToValue(player_id_));
  result->Set("messages", internal::ToValue(messages_));
  return std::move(result);
}

std::unique_ptr<PlayerMessagesLoggedParams> PlayerMessagesLoggedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerMessagesLoggedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlayerErrorsRaisedParams> PlayerErrorsRaisedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayerErrorsRaisedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayerErrorsRaisedParams> result(new PlayerErrorsRaisedParams());
  errors->Push();
  errors->SetName("PlayerErrorsRaisedParams");
  const base::Value* player_id_value = value.FindKey("playerId");
  if (player_id_value) {
    errors->SetName("playerId");
    result->player_id_ = internal::FromValue<std::string>::Parse(*player_id_value, errors);
  } else {
    errors->AddError("required property missing: playerId");
  }
  const base::Value* errors_value = value.FindKey("errors");
  if (errors_value) {
    errors->SetName("errors");
    result->errors_ = internal::FromValue<std::vector<std::unique_ptr<::headless::media::PlayerError>>>::Parse(*errors_value, errors);
  } else {
    errors->AddError("required property missing: errors");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlayerErrorsRaisedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("playerId", internal::ToValue(player_id_));
  result->Set("errors", internal::ToValue(errors_));
  return std::move(result);
}

std::unique_ptr<PlayerErrorsRaisedParams> PlayerErrorsRaisedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayerErrorsRaisedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlayersCreatedParams> PlayersCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlayersCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlayersCreatedParams> result(new PlayersCreatedParams());
  errors->Push();
  errors->SetName("PlayersCreatedParams");
  const base::Value* players_value = value.FindKey("players");
  if (players_value) {
    errors->SetName("players");
    result->players_ = internal::FromValue<std::vector<std::string>>::Parse(*players_value, errors);
  } else {
    errors->AddError("required property missing: players");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlayersCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("players", internal::ToValue(players_));
  return std::move(result);
}

std::unique_ptr<PlayersCreatedParams> PlayersCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlayersCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace media
}  // namespace headless
