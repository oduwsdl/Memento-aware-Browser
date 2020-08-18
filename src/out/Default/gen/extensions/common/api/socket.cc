// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/socket.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/socket.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace socket {
//
// Types
//

const char* ToString(SocketType enum_param) {
  switch (enum_param) {
    case SOCKET_TYPE_TCP:
      return "tcp";
    case SOCKET_TYPE_UDP:
      return "udp";
    case SOCKET_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SocketType ParseSocketType(const std::string& enum_string) {
  if (enum_string == "tcp")
    return SOCKET_TYPE_TCP;
  if (enum_string == "udp")
    return SOCKET_TYPE_UDP;
  return SOCKET_TYPE_NONE;
}


CreateOptions::CreateOptions()
 {}

CreateOptions::~CreateOptions() {}
CreateOptions::CreateOptions(CreateOptions&& rhs)
{
}

CreateOptions& CreateOptions::operator=(CreateOptions&& rhs)
{

return *this;
}

// static
bool CreateOptions::Populate(
    const base::Value& value, CreateOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<CreateOptions> CreateOptions::FromValue(const base::Value& value) {
  std::unique_ptr<CreateOptions> out(new CreateOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CreateOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


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


AcceptInfo::AcceptInfo()
: result_code(0) {}

AcceptInfo::~AcceptInfo() {}
AcceptInfo::AcceptInfo(AcceptInfo&& rhs)
: result_code(rhs.result_code),
socket_id(std::move(rhs.socket_id)){
}

AcceptInfo& AcceptInfo::operator=(AcceptInfo&& rhs)
{
result_code = rhs.result_code;
socket_id = std::move(rhs.socket_id);
return *this;
}

// static
bool AcceptInfo::Populate(
    const base::Value& value, AcceptInfo* out) {
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

  const base::Value* socket_id_value = NULL;
  if (dict->GetWithoutPathExpansion("socketId", &socket_id_value)) {
    {
      int temp;
      if (!socket_id_value->GetAsInteger(&temp)) {
        out->socket_id.reset();
        return false;
      }
      else
        out->socket_id.reset(new int(temp));
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

  to_value_result->SetWithoutPathExpansion("resultCode", std::make_unique<base::Value>(this->result_code));

  if (this->socket_id.get()) {
    to_value_result->SetWithoutPathExpansion("socketId", std::make_unique<base::Value>(*this->socket_id));

  }

  return to_value_result;
}


ReadInfo::ReadInfo()
: result_code(0) {}

ReadInfo::~ReadInfo() {}
ReadInfo::ReadInfo(ReadInfo&& rhs)
: result_code(rhs.result_code),
data(std::move(rhs.data)){
}

ReadInfo& ReadInfo::operator=(ReadInfo&& rhs)
{
result_code = rhs.result_code;
data = std::move(rhs.data);
return *this;
}

// static
bool ReadInfo::Populate(
    const base::Value& value, ReadInfo* out) {
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
std::unique_ptr<ReadInfo> ReadInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ReadInfo> out(new ReadInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReadInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("resultCode", std::make_unique<base::Value>(this->result_code));

  to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(this->data));


  return to_value_result;
}


WriteInfo::WriteInfo()
: bytes_written(0) {}

WriteInfo::~WriteInfo() {}
WriteInfo::WriteInfo(WriteInfo&& rhs)
: bytes_written(rhs.bytes_written){
}

WriteInfo& WriteInfo::operator=(WriteInfo&& rhs)
{
bytes_written = rhs.bytes_written;
return *this;
}

// static
bool WriteInfo::Populate(
    const base::Value& value, WriteInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* bytes_written_value = NULL;
  if (!dict->GetWithoutPathExpansion("bytesWritten", &bytes_written_value)) {
    return false;
  }
  {
    if (!bytes_written_value->GetAsInteger(&out->bytes_written)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<WriteInfo> WriteInfo::FromValue(const base::Value& value) {
  std::unique_ptr<WriteInfo> out(new WriteInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> WriteInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("bytesWritten", std::make_unique<base::Value>(this->bytes_written));


  return to_value_result;
}


RecvFromInfo::RecvFromInfo()
: result_code(0),
port(0) {}

RecvFromInfo::~RecvFromInfo() {}
RecvFromInfo::RecvFromInfo(RecvFromInfo&& rhs)
: result_code(rhs.result_code),
data(std::move(rhs.data)),
address(std::move(rhs.address)),
port(rhs.port){
}

RecvFromInfo& RecvFromInfo::operator=(RecvFromInfo&& rhs)
{
result_code = rhs.result_code;
data = std::move(rhs.data);
address = std::move(rhs.address);
port = rhs.port;
return *this;
}

// static
bool RecvFromInfo::Populate(
    const base::Value& value, RecvFromInfo* out) {
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

  const base::Value* address_value = NULL;
  if (!dict->GetWithoutPathExpansion("address", &address_value)) {
    return false;
  }
  {
    if (!address_value->GetAsString(&out->address)) {
      return false;
    }
  }

  const base::Value* port_value = NULL;
  if (!dict->GetWithoutPathExpansion("port", &port_value)) {
    return false;
  }
  {
    if (!port_value->GetAsInteger(&out->port)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<RecvFromInfo> RecvFromInfo::FromValue(const base::Value& value) {
  std::unique_ptr<RecvFromInfo> out(new RecvFromInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RecvFromInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("resultCode", std::make_unique<base::Value>(this->result_code));

  to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(this->data));

  to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(this->address));

  to_value_result->SetWithoutPathExpansion("port", std::make_unique<base::Value>(this->port));


  return to_value_result;
}


SocketInfo::SocketInfo()
: socket_type(SOCKET_TYPE_NONE),
connected(false) {}

SocketInfo::~SocketInfo() {}
SocketInfo::SocketInfo(SocketInfo&& rhs)
: socket_type(rhs.socket_type),
connected(rhs.connected),
peer_address(std::move(rhs.peer_address)),
peer_port(std::move(rhs.peer_port)),
local_address(std::move(rhs.local_address)),
local_port(std::move(rhs.local_port)){
}

SocketInfo& SocketInfo::operator=(SocketInfo&& rhs)
{
socket_type = rhs.socket_type;
connected = rhs.connected;
peer_address = std::move(rhs.peer_address);
peer_port = std::move(rhs.peer_port);
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
  const base::Value* socket_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("socketType", &socket_type_value)) {
    return false;
  }
  {
    std::string socket_type_as_string;
    if (!socket_type_value->GetAsString(&socket_type_as_string)) {
      return false;
    }
    out->socket_type = ParseSocketType(socket_type_as_string);
    if (out->socket_type == SOCKET_TYPE_NONE) {
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

  const base::Value* peer_address_value = NULL;
  if (dict->GetWithoutPathExpansion("peerAddress", &peer_address_value)) {
    {
      std::string temp;
      if (!peer_address_value->GetAsString(&temp)) {
        out->peer_address.reset();
        return false;
      }
      else
        out->peer_address.reset(new std::string(temp));
    }
  }

  const base::Value* peer_port_value = NULL;
  if (dict->GetWithoutPathExpansion("peerPort", &peer_port_value)) {
    {
      int temp;
      if (!peer_port_value->GetAsInteger(&temp)) {
        out->peer_port.reset();
        return false;
      }
      else
        out->peer_port.reset(new int(temp));
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

  to_value_result->SetWithoutPathExpansion("socketType", std::make_unique<base::Value>(socket::ToString(this->socket_type)));

  to_value_result->SetWithoutPathExpansion("connected", std::make_unique<base::Value>(this->connected));

  if (this->peer_address.get()) {
    to_value_result->SetWithoutPathExpansion("peerAddress", std::make_unique<base::Value>(*this->peer_address));

  }
  if (this->peer_port.get()) {
    to_value_result->SetWithoutPathExpansion("peerPort", std::make_unique<base::Value>(*this->peer_port));

  }
  if (this->local_address.get()) {
    to_value_result->SetWithoutPathExpansion("localAddress", std::make_unique<base::Value>(*this->local_address));

  }
  if (this->local_port.get()) {
    to_value_result->SetWithoutPathExpansion("localPort", std::make_unique<base::Value>(*this->local_port));

  }

  return to_value_result;
}


NetworkInterface::NetworkInterface()
: prefix_length(0) {}

NetworkInterface::~NetworkInterface() {}
NetworkInterface::NetworkInterface(NetworkInterface&& rhs)
: name(std::move(rhs.name)),
address(std::move(rhs.address)),
prefix_length(rhs.prefix_length){
}

NetworkInterface& NetworkInterface::operator=(NetworkInterface&& rhs)
{
name = std::move(rhs.name);
address = std::move(rhs.address);
prefix_length = rhs.prefix_length;
return *this;
}

// static
bool NetworkInterface::Populate(
    const base::Value& value, NetworkInterface* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* address_value = NULL;
  if (!dict->GetWithoutPathExpansion("address", &address_value)) {
    return false;
  }
  {
    if (!address_value->GetAsString(&out->address)) {
      return false;
    }
  }

  const base::Value* prefix_length_value = NULL;
  if (!dict->GetWithoutPathExpansion("prefixLength", &prefix_length_value)) {
    return false;
  }
  {
    if (!prefix_length_value->GetAsInteger(&out->prefix_length)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<NetworkInterface> NetworkInterface::FromValue(const base::Value& value) {
  std::unique_ptr<NetworkInterface> out(new NetworkInterface());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NetworkInterface::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(this->address));

  to_value_result->SetWithoutPathExpansion("prefixLength", std::make_unique<base::Value>(this->prefix_length));


  return to_value_result;
}


TLSVersionConstraints::TLSVersionConstraints()
 {}

TLSVersionConstraints::~TLSVersionConstraints() {}
TLSVersionConstraints::TLSVersionConstraints(TLSVersionConstraints&& rhs)
: min(std::move(rhs.min)),
max(std::move(rhs.max)){
}

TLSVersionConstraints& TLSVersionConstraints::operator=(TLSVersionConstraints&& rhs)
{
min = std::move(rhs.min);
max = std::move(rhs.max);
return *this;
}

// static
bool TLSVersionConstraints::Populate(
    const base::Value& value, TLSVersionConstraints* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* min_value = NULL;
  if (dict->GetWithoutPathExpansion("min", &min_value)) {
    {
      std::string temp;
      if (!min_value->GetAsString(&temp)) {
        out->min.reset();
        return false;
      }
      else
        out->min.reset(new std::string(temp));
    }
  }

  const base::Value* max_value = NULL;
  if (dict->GetWithoutPathExpansion("max", &max_value)) {
    {
      std::string temp;
      if (!max_value->GetAsString(&temp)) {
        out->max.reset();
        return false;
      }
      else
        out->max.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<TLSVersionConstraints> TLSVersionConstraints::FromValue(const base::Value& value) {
  std::unique_ptr<TLSVersionConstraints> out(new TLSVersionConstraints());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TLSVersionConstraints::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->min.get()) {
    to_value_result->SetWithoutPathExpansion("min", std::make_unique<base::Value>(*this->min));

  }
  if (this->max.get()) {
    to_value_result->SetWithoutPathExpansion("max", std::make_unique<base::Value>(*this->max));

  }

  return to_value_result;
}


SecureOptions::SecureOptions()
 {}

SecureOptions::~SecureOptions() {}
SecureOptions::SecureOptions(SecureOptions&& rhs)
: tls_version(std::move(rhs.tls_version)){
}

SecureOptions& SecureOptions::operator=(SecureOptions&& rhs)
{
tls_version = std::move(rhs.tls_version);
return *this;
}

// static
bool SecureOptions::Populate(
    const base::Value& value, SecureOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tls_version_value = NULL;
  if (dict->GetWithoutPathExpansion("tlsVersion", &tls_version_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tls_version_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<TLSVersionConstraints> temp(new TLSVersionConstraints());
        if (!TLSVersionConstraints::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tls_version = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<SecureOptions> SecureOptions::FromValue(const base::Value& value) {
  std::unique_ptr<SecureOptions> out(new SecureOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SecureOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->tls_version.get()) {
    to_value_result->SetWithoutPathExpansion("tlsVersion", (this->tls_version)->ToValue());

  }

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
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* type_value = NULL;
  if (args.Get(0, &type_value) &&
      !type_value->is_none()) {
    {
      std::string socket_type_as_string;
      if (!type_value->GetAsString(&socket_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->type = ParseSocketType(socket_type_as_string);
      if (params->type == SOCKET_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<CreateOptions> temp(new CreateOptions());
        if (!CreateOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
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

namespace Destroy {

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


}  // namespace Destroy

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

  const base::Value* hostname_value = NULL;
  if (args.Get(1, &hostname_value) &&
      !hostname_value->is_none()) {
    {
      if (!hostname_value->GetAsString(&params->hostname)) {
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
}  // namespace Connect

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


}  // namespace Disconnect

namespace Read {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
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

  const base::Value* buffer_size_value = NULL;
  if (args.Get(1, &buffer_size_value) &&
      !buffer_size_value->is_none()) {
    {
      int temp;
      if (!buffer_size_value->GetAsInteger(&temp)) {
        params->buffer_size.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->buffer_size.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ReadInfo& read_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((read_info).ToValue());

  return create_results;
}
}  // namespace Read

namespace Write {

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


std::unique_ptr<base::ListValue> Results::Create(const WriteInfo& write_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((write_info).ToValue());

  return create_results;
}
}  // namespace Write

namespace RecvFrom {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
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

  const base::Value* buffer_size_value = NULL;
  if (args.Get(1, &buffer_size_value) &&
      !buffer_size_value->is_none()) {
    {
      int temp;
      if (!buffer_size_value->GetAsInteger(&temp)) {
        params->buffer_size.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->buffer_size.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const RecvFromInfo& recv_from_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((recv_from_info).ToValue());

  return create_results;
}
}  // namespace RecvFrom

namespace SendTo {

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


std::unique_ptr<base::ListValue> Results::Create(const WriteInfo& write_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((write_info).ToValue());

  return create_results;
}
}  // namespace SendTo

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

namespace Accept {

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


std::unique_ptr<base::ListValue> Results::Create(const AcceptInfo& accept_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((accept_info).ToValue());

  return create_results;
}
}  // namespace Accept

namespace SetKeepAlive {

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

  const base::Value* enable_value = NULL;
  if (args.Get(1, &enable_value) &&
      !enable_value->is_none()) {
    {
      if (!enable_value->GetAsBoolean(&params->enable)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* delay_value = NULL;
  if (args.Get(2, &delay_value) &&
      !delay_value->is_none()) {
    {
      int temp;
      if (!delay_value->GetAsInteger(&temp)) {
        params->delay.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->delay.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace SetKeepAlive

namespace SetNoDelay {

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

  const base::Value* no_delay_value = NULL;
  if (args.Get(1, &no_delay_value) &&
      !no_delay_value->is_none()) {
    {
      if (!no_delay_value->GetAsBoolean(&params->no_delay)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace SetNoDelay

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


std::unique_ptr<base::ListValue> Results::Create(const SocketInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetInfo

namespace GetNetworkList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<NetworkInterface>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetNetworkList

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

namespace Secure {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
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

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<SecureOptions> temp(new SecureOptions());
        if (!SecureOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace Secure

}  // namespace socket
}  // namespace api
}  // namespace extensions

