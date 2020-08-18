// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/gcm.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/gcm.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace gcm {
//
// Properties
//

const int MAX_MESSAGE_SIZE = 4096;

//
// Functions
//

namespace Register {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* sender_ids_value = NULL;
  if (args.Get(0, &sender_ids_value) &&
      !sender_ids_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!sender_ids_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->sender_ids)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& registration_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(registration_id));

  return create_results;
}
}  // namespace Register

namespace Unregister {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Unregister

namespace Send {

Params::Message::Data::Data()
 {}

Params::Message::Data::~Data() {}
Params::Message::Data::Data(Data&& rhs)
: additional_properties(std::move(rhs.additional_properties)){
}

Params::Message::Data& Params::Message::Data::operator=(Data&& rhs)
{
additional_properties = std::move(rhs.additional_properties);
return *this;
}

// static
bool Params::Message::Data::Populate(
    const base::Value& value, Data* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  for (base::DictionaryValue::Iterator it(*dict);
       !it.IsAtEnd(); it.Advance()) {
    std::string tmp;
    {
      if (!(&it.value())->GetAsString(&tmp)) {
        return false;
      }
    }
    out->additional_properties[it.key()] = tmp;
  }
  return true;
}



Params::Message::Message()
 {}

Params::Message::~Message() {}
Params::Message::Message(Message&& rhs)
: destination_id(std::move(rhs.destination_id)),
message_id(std::move(rhs.message_id)),
time_to_live(std::move(rhs.time_to_live)),
data(std::move(rhs.data)){
}

Params::Message& Params::Message::operator=(Message&& rhs)
{
destination_id = std::move(rhs.destination_id);
message_id = std::move(rhs.message_id);
time_to_live = std::move(rhs.time_to_live);
data = std::move(rhs.data);
return *this;
}

// static
bool Params::Message::Populate(
    const base::Value& value, Message* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* destination_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("destinationId", &destination_id_value)) {
    return false;
  }
  {
    if (!destination_id_value->GetAsString(&out->destination_id)) {
      return false;
    }
  }

  const base::Value* message_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("messageId", &message_id_value)) {
    return false;
  }
  {
    if (!message_id_value->GetAsString(&out->message_id)) {
      return false;
    }
  }

  const base::Value* time_to_live_value = NULL;
  if (dict->GetWithoutPathExpansion("timeToLive", &time_to_live_value)) {
    {
      int temp;
      if (!time_to_live_value->GetAsInteger(&temp)) {
        out->time_to_live.reset();
        return false;
      }
      else
        out->time_to_live.reset(new int(temp));
    }
  }

  const base::Value* data_value = NULL;
  if (!dict->GetWithoutPathExpansion("data", &data_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!data_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Data::Populate(*dictionary, &out->data)) {
      return false;
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* message_value = NULL;
  if (args.Get(0, &message_value) &&
      !message_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!message_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Message::Populate(*dictionary, &params->message)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& message_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(message_id));

  return create_results;
}
}  // namespace Send

//
// Events
//

namespace OnMessage {

const char kEventName[] = "gcm.onMessage";

Message::Data::Data()
 {}

Message::Data::~Data() {}
Message::Data::Data(Data&& rhs)
: additional_properties(std::move(rhs.additional_properties)){
}

Message::Data& Message::Data::operator=(Data&& rhs)
{
additional_properties = std::move(rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Message::Data::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  for (const auto& it : additional_properties) {
    to_value_result->SetWithoutPathExpansion(it.first, std::make_unique<base::Value>(it.second));

  }

  return to_value_result;
}



Message::Message()
 {}

Message::~Message() {}
Message::Message(Message&& rhs)
: data(std::move(rhs.data)),
from(std::move(rhs.from)),
collapse_key(std::move(rhs.collapse_key)){
}

Message& Message::operator=(Message&& rhs)
{
data = std::move(rhs.data);
from = std::move(rhs.from);
collapse_key = std::move(rhs.collapse_key);
return *this;
}

std::unique_ptr<base::DictionaryValue> Message::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("data", (this->data).ToValue());

  if (this->from.get()) {
    to_value_result->SetWithoutPathExpansion("from", std::make_unique<base::Value>(*this->from));

  }
  if (this->collapse_key.get()) {
    to_value_result->SetWithoutPathExpansion("collapseKey", std::make_unique<base::Value>(*this->collapse_key));

  }

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Message& message) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((message).ToValue());

  return create_results;
}

}  // namespace OnMessage

namespace OnMessagesDeleted {

const char kEventName[] = "gcm.onMessagesDeleted";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnMessagesDeleted

namespace OnSendError {

const char kEventName[] = "gcm.onSendError";

Error::Details::Details()
 {}

Error::Details::~Details() {}
Error::Details::Details(Details&& rhs)
: additional_properties(std::move(rhs.additional_properties)){
}

Error::Details& Error::Details::operator=(Details&& rhs)
{
additional_properties = std::move(rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Error::Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  for (const auto& it : additional_properties) {
    to_value_result->SetWithoutPathExpansion(it.first, std::make_unique<base::Value>(it.second));

  }

  return to_value_result;
}



Error::Error()
 {}

Error::~Error() {}
Error::Error(Error&& rhs)
: error_message(std::move(rhs.error_message)),
message_id(std::move(rhs.message_id)),
details(std::move(rhs.details)){
}

Error& Error::operator=(Error&& rhs)
{
error_message = std::move(rhs.error_message);
message_id = std::move(rhs.message_id);
details = std::move(rhs.details);
return *this;
}

std::unique_ptr<base::DictionaryValue> Error::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("errorMessage", std::make_unique<base::Value>(this->error_message));

  if (this->message_id.get()) {
    to_value_result->SetWithoutPathExpansion("messageId", std::make_unique<base::Value>(*this->message_id));

  }
  to_value_result->SetWithoutPathExpansion("details", (this->details).ToValue());


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Error& error) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((error).ToValue());

  return create_results;
}

}  // namespace OnSendError

}  // namespace gcm
}  // namespace api
}  // namespace extensions

