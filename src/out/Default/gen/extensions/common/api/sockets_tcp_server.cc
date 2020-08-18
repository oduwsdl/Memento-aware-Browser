// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/sockets_tcp_server.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/sockets_tcp_server.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace sockets_tcp_server {
//
// Types
//

SocketProperties::SocketProperties()
 {}

SocketProperties::~SocketProperties() {}
SocketProperties::SocketProperties(SocketProperties&& rhs)
: persistent(std::move(rhs.persistent)),
name(std::move(rhs.name)){
}

SocketProperties& SocketProperties::operator=(SocketProperties&& rhs)
{
persistent = std::move(rhs.persistent);
name = std::move(rhs.name);
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


SocketInfo::SocketInfo()
: socket_id(0),
persistent(false),
paused(false) {}

SocketInfo::~SocketInfo() {}
SocketInfo::SocketInfo(SocketInfo&& rhs)
: socket_id(rhs.socket_id),
persistent(rhs.persistent),
name(std::move(rhs.name)),
paused(rhs.paused),
local_address(std::move(rhs.local_address)),
local_port(std::move(rhs.local_port)){
}

SocketInfo& SocketInfo::operator=(SocketInfo&& rhs)
{
socket_id = rhs.socket_id;
persistent = rhs.persistent;
name = std::move(rhs.name);
paused = rhs.paused;
local_address = std::move(rhs.local_address);
local_port = std::move(rhs.local_port);
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

  const base::Value* paused_value = NULL;
  if (!dict->GetWithoutPathExpansion("paused", &paused_value)) {
    return false;
  }
  {
    if (!paused_value->GetAsBoolean(&out->paused)) {
      return false;
    }
  }

  const base::Value* local_address_value = NULL;
  if (dict->GetWithoutPathExpansion("localAddress", &local_address_value)) {
    {
      std::string temp;
      if (!local_address_value->GetAsString(&temp)) {
        out->local_address.reset();
        return false;
      }
      else
        out->local_address.reset(new std::string(temp));
    }
  }

  const base::Value* local_port_value = NULL;
  if (dict->GetWithoutPathExpansion("localPort", &local_port_value)) {
    {
      int temp;
      if (!local_port_value->GetAsInteger(&temp)) {
        out->local_port.reset();
        return false;
      }
      else
        out->local_port.reset(new int(temp));
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
  to_value_result->SetWithoutPathExpansion("paused", std::make_unique<base::Value>(this->paused));

  if (this->local_address.get()) {
    to_value_result->SetWithoutPathExpansion("localAddress", std::make_unique<base::Value>(*this->local_address));

  }
  if (this->local_port.get()) {
    to_value_result->SetWithoutPathExpansion("localPort", std::make_unique<base::Value>(*this->local_port));

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


AcceptErrorInfo::AcceptErrorInfo()
: socket_id(0),
result_code(0) {}

AcceptErrorInfo::~AcceptErrorInfo() {}
AcceptErrorInfo::AcceptErrorInfo(AcceptErrorInfo&& rhs)
: socket_id(rhs.socket_id),
result_code(rhs.result_code){
}

AcceptErrorInfo& AcceptErrorInfo::operator=(AcceptErrorInfo&& rhs)
{
socket_id = rhs.socket_id;
result_code = rhs.result_code;
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

  const base::Value* result_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("resultCode", &result_code_value)) {
    return false;
  }
  {
    if (!result_code_value->GetAsInteger(&out->result_code)) {
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

  to_value_result->SetWithoutPathExpansion("resultCode", std::make_unique<base::Value>(this->result_code));


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

namespace Listen {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 3 || args.GetSize() > 4) {
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

  const base::Value* port_value = NULL;
  if (args.Get(2, &port_value) &&
      !port_value->is_none()) {
    {
      if (!port_value->GetAsInteger(&params->port)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* backlog_value = NULL;
  if (args.Get(3, &backlog_value) &&
      !backlog_value->is_none()) {
    {
      int temp;
      if (!backlog_value->GetAsInteger(&temp)) {
        params->backlog.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->backlog.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace Listen

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

std::unique_ptr<base::ListValue> Results::Create(const std::vector<SocketInfo>& socket_infos) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(socket_infos));

  return create_results;
}
}  // namespace GetSockets

//
// Events
//

namespace OnAccept {

const char kEventName[] = "sockets.tcpServer.onAccept";

std::unique_ptr<base::ListValue> Create(const AcceptInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnAccept

namespace OnAcceptError {

const char kEventName[] = "sockets.tcpServer.onAcceptError";

std::unique_ptr<base::ListValue> Create(const AcceptErrorInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnAcceptError

}  // namespace sockets_tcp_server
}  // namespace api
}  // namespace extensions

