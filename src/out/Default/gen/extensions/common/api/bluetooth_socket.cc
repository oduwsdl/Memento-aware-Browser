// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/bluetooth_socket.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/bluetooth_socket.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace bluetooth_socket {
//
// Types
//

SocketProperties::SocketProperties()
 {}

SocketProperties::~SocketProperties() {}
SocketProperties::SocketProperties(SocketProperties&& rhs)
: persistent(std::move(rhs.persistent)),
name(std::move(rhs.name)),
buffer_size(std::move(rhs.buffer_size)){
}

SocketProperties& SocketProperties::operator=(SocketProperties&& rhs)
{
persistent = std::move(rhs.persistent);
name = std::move(rhs.name);
buffer_size = std::move(rhs.buffer_size);
return *this;
}

// static
bool SocketProperties::Populate(
    const base::Value& value, SocketProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* persistent_value = NULL;
  if (dict->GetWithoutPathExpansion("persistent", &persistent_value)) {
    {
      bool temp;
      if (!persistent_value->GetAsBoolean(&temp)) {
        out->persistent.reset();
        return false;
      }
      else
        out->persistent.reset(new bool(temp));
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* buffer_size_value = NULL;
  if (dict->GetWithoutPathExpansion("bufferSize", &buffer_size_value)) {
    {
      int temp;
      if (!buffer_size_value->GetAsInteger(&temp)) {
        out->buffer_size.reset();
        return false;
      }
      else
        out->buffer_size.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<SocketProperties> SocketProperties::FromValue(const base::Value& value) {
  std::unique_ptr<SocketProperties> out(new SocketProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SocketProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->persistent.get()) {
    to_value_result->SetWithoutPathExpansion("persistent", std::make_unique<base::Value>(*this->persistent));

  }
  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(*this->name));

  }
  if (this->buffer_size.get()) {
    to_value_result->SetWithoutPathExpansion("bufferSize", std::make_unique<base::Value>(*this->buffer_size));

  }

  return to_value_result;
}


CreateInfo::CreateInfo()
: socket_id(0) {}

CreateInfo::~CreateInfo() {}
CreateInfo::CreateInfo(CreateInfo&& rhs)
: socket_id(rhs.socket_id){
}

CreateInfo& CreateInfo::operator=(CreateInfo&& rhs)
{
socket_id = rhs.socket_id;
return *this;
}

// static
bool CreateInfo::Populate(
    const base::Value& value, CreateInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* socket_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("socketId", &socket_id_value)) {
    return false;
  }
  {
    if (!socket_id_value->GetAsInteger(&out->socket_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<CreateInfo> CreateInfo::FromValue(const base::Value& value) {
  std::unique_ptr<CreateInfo> out(new CreateInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CreateInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("socketId", std::make_unique<base::Value>(this->socket_id));


  return to_value_result;
}


ListenOptions::ListenOptions()
 {}

ListenOptions::~ListenOptions() {}
ListenOptions::ListenOptions(ListenOptions&& rhs)
: channel(std::move(rhs.channel)),
psm(std::move(rhs.psm)),
backlog(std::move(rhs.backlog)){
}

ListenOptions& ListenOptions::operator=(ListenOptions&& rhs)
{
channel = std::move(rhs.channel);
psm = std::move(rhs.psm);
backlog = std::move(rhs.backlog);
return *this;
}

// static
bool ListenOptions::Populate(
    const base::Value& value, ListenOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* channel_value = NULL;
  if (dict->GetWithoutPathExpansion("channel", &channel_value)) {
    {
      int temp;
      if (!channel_value->GetAsInteger(&temp)) {
        out->channel.reset();
        return false;
      }
      else
        out->channel.reset(new int(temp));
    }
  }

  const base::Value* psm_value = NULL;
  if (dict->GetWithoutPathExpansion("psm", &psm_value)) {
    {
      int temp;
      if (!psm_value->GetAsInteger(&temp)) {
        out->psm.reset();
        return false;
      }
      else
        out->psm.reset(new int(temp));
    }
  }

  const base::Value* backlog_value = NULL;
  if (dict->GetWithoutPathExpansion("backlog", &backlog_value)) {
    {
      int temp;
      if (!backlog_value->GetAsInteger(&temp)) {
        out->backlog.reset();
        return false;
      }
      else
        out->backlog.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ListenOptions> ListenOptions::FromValue(const base::Value& value) {
  std::unique_ptr<ListenOptions> out(new ListenOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ListenOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->channel.get()) {
    to_value_result->SetWithoutPathExpansion("channel", std::make_unique<base::Value>(*this->channel));

  }
  if (this->psm.get()) {
    to_value_result->SetWithoutPathExpansion("psm", std::make_unique<base::Value>(*this->psm));

  }
  if (this->backlog.get()) {
    to_value_result->SetWithoutPathExpansion("backlog", std::make_unique<base::Value>(*this->backlog));

  }

  return to_value_result;
}


SocketInfo::SocketInfo()
: socket_id(0),
persistent(false),
paused(false),
connected(false) {}

SocketInfo::~SocketInfo() {}
SocketInfo::SocketInfo(SocketInfo&& rhs)
: socket_id(rhs.socket_id),
persistent(rhs.persistent),
name(std::move(rhs.name)),
buffer_size(std::move(rhs.buffer_size)),
paused(rhs.paused),
connected(rhs.connected),
address(std::move(rhs.address)),
uuid(std::move(rhs.uuid)){
}

SocketInfo& SocketInfo::operator=(SocketInfo&& rhs)
{
socket_id = rhs.socket_id;
persistent = rhs.persistent;
name = std::move(rhs.name);
buffer_size = std::move(rhs.buffer_size);
paused = rhs.paused;
connected = rhs.connected;
address = std::move(rhs.address);
uuid = std::move(rhs.uuid);
return *this;
}

// static
bool SocketInfo::Populate(
    const base::Value& value, SocketInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* socket_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("socketId", &socket_id_value)) {
    return false;
  }
  {
    if (!socket_id_value->GetAsInteger(&out->socket_id)) {
      return false;
    }
  }

  const base::Value* persistent_value = NULL;
  if (!dict->GetWithoutPathExpansion("persistent", &persistent_value)) {
    return false;
  }
  {
    if (!persistent_value->GetAsBoolean(&out->persistent)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* buffer_size_value = NULL;
  if (dict->GetWithoutPathExpansion("bufferSize", &buffer_size_value)) {
    {
      int temp;
      if (!buffer_size_value->GetAsInteger(&temp)) {
        out->buffer_size.reset();
        return false;
      }
      else
        out->buffer_size.reset(new int(temp));
    }
  }

  const base::Value* paused_value = NULL;
  if (!dict->GetWithoutPathExpansion("paused", &paused_value)) {
    return false;
  }
  {
    if (!paused_value->GetAsBoolean(&out->paused)) {
      return false;
    }
  }

  const base::Value* connected_value = NULL;
  if (!dict->GetWithoutPathExpansion("connected", &connected_value)) {
    return false;
  }
  {
    if (!connected_value->GetAsBoolean(&out->connected)) {
      return false;
    }
  }

  const base::Value* address_value = NULL;
  if (dict->GetWithoutPathExpansion("address", &address_value)) {
    {
      std::string temp;
      if (!address_value->GetAsString(&temp)) {
        out->address.reset();
        return false;
      }
      else
        out->address.reset(new std::string(temp));
    }
  }

  const base::Value* uuid_value = NULL;
  if (dict->GetWithoutPathExpansion("uuid", &uuid_value)) {
    {
      std::string temp;
      if (!uuid_value->GetAsString(&temp)) {
        out->uuid.reset();
        return false;
      }
      else
        out->uuid.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<SocketInfo> SocketInfo::FromValue(const base::Value& value) {
  std::unique_ptr<SocketInfo> out(new SocketInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SocketInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("socketId", std::make_unique<base::Value>(this->socket_id));

  to_value_result->SetWithoutPathExpansion("persistent", std::make_unique<base::Value>(this->persistent));

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(*this->name));

  }
  if (this->buffer_size.get()) {
    to_value_result->SetWithoutPathExpansion("bufferSize", std::make_unique<base::Value>(*this->buffer_size));

  }
  to_value_result->SetWithoutPathExpansion("paused", std::make_unique<base::Value>(this->paused));

  to_value_result->SetWithoutPathExpansion("connected", std::make_unique<base::Value>(this->connected));

  if (this->address.get()) {
    to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(*this->address));

  }
  if (this->uuid.get()) {
    to_value_result->SetWithoutPathExpansion("uuid", std::make_unique<base::Value>(*this->uuid));

  }

  return to_value_result;
}


AcceptInfo::AcceptInfo()
: socket_id(0),
client_socket_id(0) {}

AcceptInfo::~AcceptInfo() {}
AcceptInfo::AcceptInfo(AcceptInfo&& rhs)
: socket_id(rhs.socket_id),
client_socket_id(rhs.client_socket_id){
}

AcceptInfo& AcceptInfo::operator=(AcceptInfo&& rhs)
{
socket_id = rhs.socket_id;
client_socket_id = rhs.client_socket_id;
return *this;
}

// static
bool AcceptInfo::Populate(
    const base::Value& value, AcceptInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* socket_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("socketId", &socket_id_value)) {
    return false;
  }
  {
    if (!socket_id_value->GetAsInteger(&out->socket_id)) {
      return false;
    }
  }

  const base::Value* client_socket_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("clientSocketId", &client_socket_id_value)) {
    return false;
  }
  {
    if (!client_socket_id_value->GetAsInteger(&out->client_socket_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AcceptInfo> AcceptInfo::FromValue(const base::Value& value) {
  std::unique_ptr<AcceptInfo> out(new AcceptInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AcceptInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("socketId", std::make_unique<base::Value>(this->socket_id));

  to_value_result->SetWithoutPathExpansion("clientSocketId", std::make_unique<base::Value>(this->client_socket_id));


  return to_value_result;
}


const char* ToString(AcceptError enum_param) {
  switch (enum_param) {
    case ACCEPT_ERROR_SYSTEM_ERROR:
      return "system_error";
    case ACCEPT_ERROR_NOT_LISTENING:
      return "not_listening";
    case ACCEPT_ERROR_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

AcceptError ParseAcceptError(const std::string& enum_string) {
  if (enum_string == "system_error")
    return ACCEPT_ERROR_SYSTEM_ERROR;
  if (enum_string == "not_listening")
    return ACCEPT_ERROR_NOT_LISTENING;
  return ACCEPT_ERROR_NONE;
}


AcceptErrorInfo::AcceptErrorInfo()
: socket_id(0),
error(ACCEPT_ERROR_NONE) {}

AcceptErrorInfo::~AcceptErrorInfo() {}
AcceptErrorInfo::AcceptErrorInfo(AcceptErrorInfo&& rhs)
: socket_id(rhs.socket_id),
error_message(std::move(rhs.error_message)),
error(rhs.error){
}

AcceptErrorInfo& AcceptErrorInfo::operator=(AcceptErrorInfo&& rhs)
{
socket_id = rhs.socket_id;
error_message = std::move(rhs.error_message);
error = rhs.error;
return *this;
}

// static
bool AcceptErrorInfo::Populate(
    const base::Value& value, AcceptErrorInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* socket_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("socketId", &socket_id_value)) {
    return false;
  }
  {
    if (!socket_id_value->GetAsInteger(&out->socket_id)) {
      return false;
    }
  }

  const base::Value* error_message_value = NULL;
  if (!dict->GetWithoutPathExpansion("errorMessage", &error_message_value)) {
    return false;
  }
  {
    if (!error_message_value->GetAsString(&out->error_message)) {
      return false;
    }
  }

  const base::Value* error_value = NULL;
  if (!dict->GetWithoutPathExpansion("error", &error_value)) {
    return false;
  }
  {
    std::string accept_error_as_string;
    if (!error_value->GetAsString(&accept_error_as_string)) {
      return false;
    }
    out->error = ParseAcceptError(accept_error_as_string);
    if (out->error == ACCEPT_ERROR_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AcceptErrorInfo> AcceptErrorInfo::FromValue(const base::Value& value) {
  std::unique_ptr<AcceptErrorInfo> out(new AcceptErrorInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AcceptErrorInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("socketId", std::make_unique<base::Value>(this->socket_id));

  to_value_result->SetWithoutPathExpansion("errorMessage", std::make_unique<base::Value>(this->error_message));

  to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(bluetooth_socket::ToString(this->error)));


  return to_value_result;
}


ReceiveInfo::ReceiveInfo()
: socket_id(0) {}

ReceiveInfo::~ReceiveInfo() {}
ReceiveInfo::ReceiveInfo(ReceiveInfo&& rhs)
: socket_id(rhs.socket_id),
data(std::move(rhs.data)){
}

ReceiveInfo& ReceiveInfo::operator=(ReceiveInfo&& rhs)
{
socket_id = rhs.socket_id;
data = std::move(rhs.data);
return *this;
}

// static
bool ReceiveInfo::Populate(
    const base::Value& value, ReceiveInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* socket_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("socketId", &socket_id_value)) {
    return false;
  }
  {
    if (!socket_id_value->GetAsInteger(&out->socket_id)) {
      return false;
    }
  }

  const base::Value* data_value = NULL;
  if (!dict->GetWithoutPathExpansion("data", &data_value)) {
    return false;
  }
  {
    if (!data_value->is_blob()) {
      return false;
    }
    else {
      out->data = data_value->GetBlob();
    }
  }

  return true;
}

// static
std::unique_ptr<ReceiveInfo> ReceiveInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ReceiveInfo> out(new ReceiveInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReceiveInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("socketId", std::make_unique<base::Value>(this->socket_id));

  to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(this->data));


  return to_value_result;
}


const char* ToString(ReceiveError enum_param) {
  switch (enum_param) {
    case RECEIVE_ERROR_DISCONNECTED:
      return "disconnected";
    case RECEIVE_ERROR_SYSTEM_ERROR:
      return "system_error";
    case RECEIVE_ERROR_NOT_CONNECTED:
      return "not_connected";
    case RECEIVE_ERROR_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ReceiveError ParseReceiveError(const std::string& enum_string) {
  if (enum_string == "disconnected")
    return RECEIVE_ERROR_DISCONNECTED;
  if (enum_string == "system_error")
    return RECEIVE_ERROR_SYSTEM_ERROR;
  if (enum_string == "not_connected")
    return RECEIVE_ERROR_NOT_CONNECTED;
  return RECEIVE_ERROR_NONE;
}


ReceiveErrorInfo::ReceiveErrorInfo()
: socket_id(0),
error(RECEIVE_ERROR_NONE) {}

ReceiveErrorInfo::~ReceiveErrorInfo() {}
ReceiveErrorInfo::ReceiveErrorInfo(ReceiveErrorInfo&& rhs)
: socket_id(rhs.socket_id),
error_message(std::move(rhs.error_message)),
error(rhs.error){
}

ReceiveErrorInfo& ReceiveErrorInfo::operator=(ReceiveErrorInfo&& rhs)
{
socket_id = rhs.socket_id;
error_message = std::move(rhs.error_message);
error = rhs.error;
return *this;
}

// static
bool ReceiveErrorInfo::Populate(
    const base::Value& value, ReceiveErrorInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* socket_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("socketId", &socket_id_value)) {
    return false;
  }
  {
    if (!socket_id_value->GetAsInteger(&out->socket_id)) {
      return false;
    }
  }

  const base::Value* error_message_value = NULL;
  if (!dict->GetWithoutPathExpansion("errorMessage", &error_message_value)) {
    return false;
  }
  {
    if (!error_message_value->GetAsString(&out->error_message)) {
      return false;
    }
  }

  const base::Value* error_value = NULL;
  if (!dict->GetWithoutPathExpansion("error", &error_value)) {
    return false;
  }
  {
    std::string receive_error_as_string;
    if (!error_value->GetAsString(&receive_error_as_string)) {
      return false;
    }
    out->error = ParseReceiveError(receive_error_as_string);
    if (out->error == RECEIVE_ERROR_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ReceiveErrorInfo> ReceiveErrorInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ReceiveErrorInfo> out(new ReceiveErrorInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReceiveErrorInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("socketId", std::make_unique<base::Value>(this->socket_id));

  to_value_result->SetWithoutPathExpansion("errorMessage", std::make_unique<base::Value>(this->error_message));

  to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(bluetooth_socket::ToString(this->error)));


  return to_value_result;
}



//
// Functions
//

namespace Create {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* properties_value = NULL;
  if (args.Get(0, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<SocketProperties> temp(new SocketProperties());
        if (!SocketProperties::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->properties = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const CreateInfo& create_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((create_info).ToValue());

  return create_results;
}
}  // namespace Create

namespace Update {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* properties_value = NULL;
  if (args.Get(1, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!SocketProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Update

namespace SetPaused {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* paused_value = NULL;
  if (args.Get(1, &paused_value) &&
      !paused_value->is_none()) {
    {
      if (!paused_value->GetAsBoolean(&params->paused)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetPaused

namespace ListenUsingRfcomm {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* uuid_value = NULL;
  if (args.Get(1, &uuid_value) &&
      !uuid_value->is_none()) {
    {
      if (!uuid_value->GetAsString(&params->uuid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(2, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<ListenOptions> temp(new ListenOptions());
        if (!ListenOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ListenUsingRfcomm

namespace ListenUsingL2cap {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* uuid_value = NULL;
  if (args.Get(1, &uuid_value) &&
      !uuid_value->is_none()) {
    {
      if (!uuid_value->GetAsString(&params->uuid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(2, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<ListenOptions> temp(new ListenOptions());
        if (!ListenOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ListenUsingL2cap

namespace Connect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* address_value = NULL;
  if (args.Get(1, &address_value) &&
      !address_value->is_none()) {
    {
      if (!address_value->GetAsString(&params->address)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* uuid_value = NULL;
  if (args.Get(2, &uuid_value) &&
      !uuid_value->is_none()) {
    {
      if (!uuid_value->GetAsString(&params->uuid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Connect

namespace Disconnect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Disconnect

namespace Close {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Close

namespace Send {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* data_value = NULL;
  if (args.Get(1, &data_value) &&
      !data_value->is_none()) {
    {
      if (!data_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->data = data_value->GetBlob();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int bytes_sent) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(bytes_sent));

  return create_results;
}
}  // namespace Send

namespace GetInfo {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* socket_id_value = NULL;
  if (args.Get(0, &socket_id_value) &&
      !socket_id_value->is_none()) {
    {
      if (!socket_id_value->GetAsInteger(&params->socket_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const SocketInfo& socket_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((socket_info).ToValue());

  return create_results;
}
}  // namespace GetInfo

namespace GetSockets {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<SocketInfo>& sockets) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(sockets));

  return create_results;
}
}  // namespace GetSockets

//
// Events
//

namespace OnAccept {

const char kEventName[] = "bluetoothSocket.onAccept";

std::unique_ptr<base::ListValue> Create(const AcceptInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnAccept

namespace OnAcceptError {

const char kEventName[] = "bluetoothSocket.onAcceptError";

std::unique_ptr<base::ListValue> Create(const AcceptErrorInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnAcceptError

namespace OnReceive {

const char kEventName[] = "bluetoothSocket.onReceive";

std::unique_ptr<base::ListValue> Create(const ReceiveInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnReceive

namespace OnReceiveError {

const char kEventName[] = "bluetoothSocket.onReceiveError";

std::unique_ptr<base::ListValue> Create(const ReceiveErrorInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnReceiveError

}  // namespace bluetooth_socket
}  // namespace api
}  // namespace extensions

