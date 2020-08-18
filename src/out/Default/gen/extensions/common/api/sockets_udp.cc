// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/sockets_udp.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/sockets_udp.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace sockets_udp {
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


SendInfo::SendInfo()
: result_code(0) {}

SendInfo::~SendInfo() {}
SendInfo::SendInfo(SendInfo&& rhs)
: result_code(rhs.result_code),
bytes_sent(std::move(rhs.bytes_sent)){
}

SendInfo& SendInfo::operator=(SendInfo&& rhs)
{
result_code = rhs.result_code;
bytes_sent = std::move(rhs.bytes_sent);
return *this;
}

// static
bool SendInfo::Populate(
    const base::Value& value, SendInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* result_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("resultCode", &result_code_value)) {
    return false;
  }
  {
    if (!result_code_value->GetAsInteger(&out->result_code)) {
      return false;
    }
  }

  const base::Value* bytes_sent_value = NULL;
  if (dict->GetWithoutPathExpansion("bytesSent", &bytes_sent_value)) {
    {
      int temp;
      if (!bytes_sent_value->GetAsInteger(&temp)) {
        out->bytes_sent.reset();
        return false;
      }
      else
        out->bytes_sent.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<SendInfo> SendInfo::FromValue(const base::Value& value) {
  std::unique_ptr<SendInfo> out(new SendInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SendInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("resultCode", std::make_unique<base::Value>(this->result_code));

  if (this->bytes_sent.get()) {
    to_value_result->SetWithoutPathExpansion("bytesSent", std::make_unique<base::Value>(*this->bytes_sent));

  }

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
buffer_size(std::move(rhs.buffer_size)),
paused(rhs.paused),
local_address(std::move(rhs.local_address)),
local_port(std::move(rhs.local_port)){
}

SocketInfo& SocketInfo::operator=(SocketInfo&& rhs)
{
socket_id = rhs.socket_id;
persistent = rhs.persistent;
name = std::move(rhs.name);
buffer_size = std::move(rhs.buffer_size);
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
  if (this->buffer_size.get()) {
    to_value_result->SetWithoutPathExpansion("bufferSize", std::make_unique<base::Value>(*this->buffer_size));

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


ReceiveInfo::ReceiveInfo()
: socket_id(0),
remote_port(0) {}

ReceiveInfo::~ReceiveInfo() {}
ReceiveInfo::ReceiveInfo(ReceiveInfo&& rhs)
: socket_id(rhs.socket_id),
data(std::move(rhs.data)),
remote_address(std::move(rhs.remote_address)),
remote_port(rhs.remote_port){
}

ReceiveInfo& ReceiveInfo::operator=(ReceiveInfo&& rhs)
{
socket_id = rhs.socket_id;
data = std::move(rhs.data);
remote_address = std::move(rhs.remote_address);
remote_port = rhs.remote_port;
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

  const base::Value* remote_address_value = NULL;
  if (!dict->GetWithoutPathExpansion("remoteAddress", &remote_address_value)) {
    return false;
  }
  {
    if (!remote_address_value->GetAsString(&out->remote_address)) {
      return false;
    }
  }

  const base::Value* remote_port_value = NULL;
  if (!dict->GetWithoutPathExpansion("remotePort", &remote_port_value)) {
    return false;
  }
  {
    if (!remote_port_value->GetAsInteger(&out->remote_port)) {
      return false;
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

  to_value_result->SetWithoutPathExpansion("remoteAddress", std::make_unique<base::Value>(this->remote_address));

  to_value_result->SetWithoutPathExpansion("remotePort", std::make_unique<base::Value>(this->remote_port));


  return to_value_result;
}


ReceiveErrorInfo::ReceiveErrorInfo()
: socket_id(0),
result_code(0) {}

ReceiveErrorInfo::~ReceiveErrorInfo() {}
ReceiveErrorInfo::ReceiveErrorInfo(ReceiveErrorInfo&& rhs)
: socket_id(rhs.socket_id),
result_code(rhs.result_code){
}

ReceiveErrorInfo& ReceiveErrorInfo::operator=(ReceiveErrorInfo&& rhs)
{
socket_id = rhs.socket_id;
result_code = rhs.result_code;
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
std::unique_ptr<ReceiveErrorInfo> ReceiveErrorInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ReceiveErrorInfo> out(new ReceiveErrorInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReceiveErrorInfo::ToValue() const {
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

namespace Bind {

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

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace Bind

namespace Send {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 4) {
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

  const base::Value* address_value = NULL;
  if (args.Get(2, &address_value) &&
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
  if (args.Get(3, &port_value) &&
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

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const SendInfo& send_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((send_info).ToValue());

  return create_results;
}
}  // namespace Send

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

namespace JoinGroup {

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

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace JoinGroup

namespace LeaveGroup {

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

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace LeaveGroup

namespace SetMulticastTimeToLive {

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

  const base::Value* ttl_value = NULL;
  if (args.Get(1, &ttl_value) &&
      !ttl_value->is_none()) {
    {
      if (!ttl_value->GetAsInteger(&params->ttl)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace SetMulticastTimeToLive

namespace SetMulticastLoopbackMode {

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

  const base::Value* enabled_value = NULL;
  if (args.Get(1, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace SetMulticastLoopbackMode

namespace GetJoinedGroups {

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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& groups) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(groups));

  return create_results;
}
}  // namespace GetJoinedGroups

namespace SetBroadcast {

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

  const base::Value* enabled_value = NULL;
  if (args.Get(1, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace SetBroadcast

//
// Events
//

namespace OnReceive {

const char kEventName[] = "sockets.udp.onReceive";

std::unique_ptr<base::ListValue> Create(const ReceiveInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnReceive

namespace OnReceiveError {

const char kEventName[] = "sockets.udp.onReceiveError";

std::unique_ptr<base::ListValue> Create(const ReceiveErrorInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnReceiveError

}  // namespace sockets_udp
}  // namespace api
}  // namespace extensions

