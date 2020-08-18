// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/cast_channel.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/cast_channel.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace cast_channel {
//
// Types
//

const char* ToString(ReadyState enum_param) {
  switch (enum_param) {
    case READY_STATE_CONNECTING:
      return "connecting";
    case READY_STATE_OPEN:
      return "open";
    case READY_STATE_CLOSING:
      return "closing";
    case READY_STATE_CLOSED:
      return "closed";
    case READY_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ReadyState ParseReadyState(const std::string& enum_string) {
  if (enum_string == "connecting")
    return READY_STATE_CONNECTING;
  if (enum_string == "open")
    return READY_STATE_OPEN;
  if (enum_string == "closing")
    return READY_STATE_CLOSING;
  if (enum_string == "closed")
    return READY_STATE_CLOSED;
  return READY_STATE_NONE;
}


const char* ToString(ChannelError enum_param) {
  switch (enum_param) {
    case CHANNEL_ERROR_CHANNEL_NOT_OPEN:
      return "channel_not_open";
    case CHANNEL_ERROR_AUTHENTICATION_ERROR:
      return "authentication_error";
    case CHANNEL_ERROR_CONNECT_ERROR:
      return "connect_error";
    case CHANNEL_ERROR_SOCKET_ERROR:
      return "socket_error";
    case CHANNEL_ERROR_TRANSPORT_ERROR:
      return "transport_error";
    case CHANNEL_ERROR_INVALID_MESSAGE:
      return "invalid_message";
    case CHANNEL_ERROR_INVALID_CHANNEL_ID:
      return "invalid_channel_id";
    case CHANNEL_ERROR_CONNECT_TIMEOUT:
      return "connect_timeout";
    case CHANNEL_ERROR_PING_TIMEOUT:
      return "ping_timeout";
    case CHANNEL_ERROR_UNKNOWN:
      return "unknown";
    case CHANNEL_ERROR_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ChannelError ParseChannelError(const std::string& enum_string) {
  if (enum_string == "channel_not_open")
    return CHANNEL_ERROR_CHANNEL_NOT_OPEN;
  if (enum_string == "authentication_error")
    return CHANNEL_ERROR_AUTHENTICATION_ERROR;
  if (enum_string == "connect_error")
    return CHANNEL_ERROR_CONNECT_ERROR;
  if (enum_string == "socket_error")
    return CHANNEL_ERROR_SOCKET_ERROR;
  if (enum_string == "transport_error")
    return CHANNEL_ERROR_TRANSPORT_ERROR;
  if (enum_string == "invalid_message")
    return CHANNEL_ERROR_INVALID_MESSAGE;
  if (enum_string == "invalid_channel_id")
    return CHANNEL_ERROR_INVALID_CHANNEL_ID;
  if (enum_string == "connect_timeout")
    return CHANNEL_ERROR_CONNECT_TIMEOUT;
  if (enum_string == "ping_timeout")
    return CHANNEL_ERROR_PING_TIMEOUT;
  if (enum_string == "unknown")
    return CHANNEL_ERROR_UNKNOWN;
  return CHANNEL_ERROR_NONE;
}


const char* ToString(ChannelAuthType enum_param) {
  switch (enum_param) {
    case CHANNEL_AUTH_TYPE_SSL_VERIFIED:
      return "ssl_verified";
    case CHANNEL_AUTH_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ChannelAuthType ParseChannelAuthType(const std::string& enum_string) {
  if (enum_string == "ssl_verified")
    return CHANNEL_AUTH_TYPE_SSL_VERIFIED;
  return CHANNEL_AUTH_TYPE_NONE;
}


ConnectInfo::ConnectInfo()
: port(0),
auth(CHANNEL_AUTH_TYPE_NONE) {}

ConnectInfo::~ConnectInfo() {}
ConnectInfo::ConnectInfo(ConnectInfo&& rhs)
: ip_address(std::move(rhs.ip_address)),
port(rhs.port),
timeout(std::move(rhs.timeout)),
auth(rhs.auth),
ping_interval(std::move(rhs.ping_interval)),
liveness_timeout(std::move(rhs.liveness_timeout)),
capabilities(std::move(rhs.capabilities)){
}

ConnectInfo& ConnectInfo::operator=(ConnectInfo&& rhs)
{
ip_address = std::move(rhs.ip_address);
port = rhs.port;
timeout = std::move(rhs.timeout);
auth = rhs.auth;
ping_interval = std::move(rhs.ping_interval);
liveness_timeout = std::move(rhs.liveness_timeout);
capabilities = std::move(rhs.capabilities);
return *this;
}

// static
bool ConnectInfo::Populate(
    const base::Value& value, ConnectInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* ip_address_value = NULL;
  if (!dict->GetWithoutPathExpansion("ipAddress", &ip_address_value)) {
    return false;
  }
  {
    if (!ip_address_value->GetAsString(&out->ip_address)) {
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

  const base::Value* timeout_value = NULL;
  if (dict->GetWithoutPathExpansion("timeout", &timeout_value)) {
    {
      int temp;
      if (!timeout_value->GetAsInteger(&temp)) {
        out->timeout.reset();
        return false;
      }
      else
        out->timeout.reset(new int(temp));
    }
  }

  const base::Value* auth_value = NULL;
  if (!dict->GetWithoutPathExpansion("auth", &auth_value)) {
    return false;
  }
  {
    std::string channel_auth_type_as_string;
    if (!auth_value->GetAsString(&channel_auth_type_as_string)) {
      return false;
    }
    out->auth = ParseChannelAuthType(channel_auth_type_as_string);
    if (out->auth == CHANNEL_AUTH_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* ping_interval_value = NULL;
  if (dict->GetWithoutPathExpansion("pingInterval", &ping_interval_value)) {
    {
      int temp;
      if (!ping_interval_value->GetAsInteger(&temp)) {
        out->ping_interval.reset();
        return false;
      }
      else
        out->ping_interval.reset(new int(temp));
    }
  }

  const base::Value* liveness_timeout_value = NULL;
  if (dict->GetWithoutPathExpansion("livenessTimeout", &liveness_timeout_value)) {
    {
      int temp;
      if (!liveness_timeout_value->GetAsInteger(&temp)) {
        out->liveness_timeout.reset();
        return false;
      }
      else
        out->liveness_timeout.reset(new int(temp));
    }
  }

  const base::Value* capabilities_value = NULL;
  if (dict->GetWithoutPathExpansion("capabilities", &capabilities_value)) {
    {
      int temp;
      if (!capabilities_value->GetAsInteger(&temp)) {
        out->capabilities.reset();
        return false;
      }
      else
        out->capabilities.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ConnectInfo> ConnectInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ConnectInfo> out(new ConnectInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ConnectInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("ipAddress", std::make_unique<base::Value>(this->ip_address));

  to_value_result->SetWithoutPathExpansion("port", std::make_unique<base::Value>(this->port));

  if (this->timeout.get()) {
    to_value_result->SetWithoutPathExpansion("timeout", std::make_unique<base::Value>(*this->timeout));

  }
  to_value_result->SetWithoutPathExpansion("auth", std::make_unique<base::Value>(cast_channel::ToString(this->auth)));

  if (this->ping_interval.get()) {
    to_value_result->SetWithoutPathExpansion("pingInterval", std::make_unique<base::Value>(*this->ping_interval));

  }
  if (this->liveness_timeout.get()) {
    to_value_result->SetWithoutPathExpansion("livenessTimeout", std::make_unique<base::Value>(*this->liveness_timeout));

  }
  if (this->capabilities.get()) {
    to_value_result->SetWithoutPathExpansion("capabilities", std::make_unique<base::Value>(*this->capabilities));

  }

  return to_value_result;
}


ChannelInfo::ChannelInfo()
: channel_id(0),
ready_state(READY_STATE_NONE),
error_state(CHANNEL_ERROR_NONE),
keep_alive(false),
audio_only(false) {}

ChannelInfo::~ChannelInfo() {}
ChannelInfo::ChannelInfo(ChannelInfo&& rhs)
: channel_id(rhs.channel_id),
connect_info(std::move(rhs.connect_info)),
ready_state(rhs.ready_state),
error_state(rhs.error_state),
keep_alive(rhs.keep_alive),
audio_only(rhs.audio_only){
}

ChannelInfo& ChannelInfo::operator=(ChannelInfo&& rhs)
{
channel_id = rhs.channel_id;
connect_info = std::move(rhs.connect_info);
ready_state = rhs.ready_state;
error_state = rhs.error_state;
keep_alive = rhs.keep_alive;
audio_only = rhs.audio_only;
return *this;
}

// static
bool ChannelInfo::Populate(
    const base::Value& value, ChannelInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->error_state = CHANNEL_ERROR_NONE;
  const base::Value* channel_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("channelId", &channel_id_value)) {
    return false;
  }
  {
    if (!channel_id_value->GetAsInteger(&out->channel_id)) {
      return false;
    }
  }

  const base::Value* connect_info_value = NULL;
  if (!dict->GetWithoutPathExpansion("connectInfo", &connect_info_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!connect_info_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ConnectInfo::Populate(*dictionary, &out->connect_info)) {
      return false;
    }
  }

  const base::Value* ready_state_value = NULL;
  if (!dict->GetWithoutPathExpansion("readyState", &ready_state_value)) {
    return false;
  }
  {
    std::string ready_state_as_string;
    if (!ready_state_value->GetAsString(&ready_state_as_string)) {
      return false;
    }
    out->ready_state = ParseReadyState(ready_state_as_string);
    if (out->ready_state == READY_STATE_NONE) {
      return false;
    }
  }

  const base::Value* error_state_value = NULL;
  if (dict->GetWithoutPathExpansion("errorState", &error_state_value)) {
    {
      std::string channel_error_as_string;
      if (!error_state_value->GetAsString(&channel_error_as_string)) {
        return false;
      }
      out->error_state = ParseChannelError(channel_error_as_string);
      if (out->error_state == CHANNEL_ERROR_NONE) {
        return false;
      }
    }
    } else {
    out->error_state = CHANNEL_ERROR_NONE;
  }

  const base::Value* keep_alive_value = NULL;
  if (!dict->GetWithoutPathExpansion("keepAlive", &keep_alive_value)) {
    return false;
  }
  {
    if (!keep_alive_value->GetAsBoolean(&out->keep_alive)) {
      return false;
    }
  }

  const base::Value* audio_only_value = NULL;
  if (!dict->GetWithoutPathExpansion("audioOnly", &audio_only_value)) {
    return false;
  }
  {
    if (!audio_only_value->GetAsBoolean(&out->audio_only)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ChannelInfo> ChannelInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ChannelInfo> out(new ChannelInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ChannelInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("channelId", std::make_unique<base::Value>(this->channel_id));

  to_value_result->SetWithoutPathExpansion("connectInfo", (this->connect_info).ToValue());

  to_value_result->SetWithoutPathExpansion("readyState", std::make_unique<base::Value>(cast_channel::ToString(this->ready_state)));

  if (this->error_state != CHANNEL_ERROR_NONE) {
    to_value_result->SetWithoutPathExpansion("errorState", std::make_unique<base::Value>(cast_channel::ToString(this->error_state)));

  }
  to_value_result->SetWithoutPathExpansion("keepAlive", std::make_unique<base::Value>(this->keep_alive));

  to_value_result->SetWithoutPathExpansion("audioOnly", std::make_unique<base::Value>(this->audio_only));


  return to_value_result;
}


MessageInfo::MessageInfo()
 {}

MessageInfo::~MessageInfo() {}
MessageInfo::MessageInfo(MessageInfo&& rhs)
: namespace_(std::move(rhs.namespace_)),
source_id(std::move(rhs.source_id)),
destination_id(std::move(rhs.destination_id)),
data(std::move(rhs.data)){
}

MessageInfo& MessageInfo::operator=(MessageInfo&& rhs)
{
namespace_ = std::move(rhs.namespace_);
source_id = std::move(rhs.source_id);
destination_id = std::move(rhs.destination_id);
data = std::move(rhs.data);
return *this;
}

// static
bool MessageInfo::Populate(
    const base::Value& value, MessageInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* namespace__value = NULL;
  if (!dict->GetWithoutPathExpansion("namespace_", &namespace__value)) {
    return false;
  }
  {
    if (!namespace__value->GetAsString(&out->namespace_)) {
      return false;
    }
  }

  const base::Value* source_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("sourceId", &source_id_value)) {
    return false;
  }
  {
    if (!source_id_value->GetAsString(&out->source_id)) {
      return false;
    }
  }

  const base::Value* destination_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("destinationId", &destination_id_value)) {
    return false;
  }
  {
    if (!destination_id_value->GetAsString(&out->destination_id)) {
      return false;
    }
  }

  const base::Value* data_value = NULL;
  if (!dict->GetWithoutPathExpansion("data", &data_value)) {
    return false;
  }
  {
    out->data = data_value->CreateDeepCopy();
  }

  return true;
}

// static
std::unique_ptr<MessageInfo> MessageInfo::FromValue(const base::Value& value) {
  std::unique_ptr<MessageInfo> out(new MessageInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MessageInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("namespace_", std::make_unique<base::Value>(this->namespace_));

  to_value_result->SetWithoutPathExpansion("sourceId", std::make_unique<base::Value>(this->source_id));

  to_value_result->SetWithoutPathExpansion("destinationId", std::make_unique<base::Value>(this->destination_id));

  to_value_result->SetWithoutPathExpansion("data", (this->data)->CreateDeepCopy());


  return to_value_result;
}


ErrorInfo::ErrorInfo()
: error_state(CHANNEL_ERROR_NONE) {}

ErrorInfo::~ErrorInfo() {}
ErrorInfo::ErrorInfo(ErrorInfo&& rhs)
: error_state(rhs.error_state),
event_type(std::move(rhs.event_type)),
challenge_reply_error_type(std::move(rhs.challenge_reply_error_type)),
net_return_value(std::move(rhs.net_return_value)),
nss_error_code(std::move(rhs.nss_error_code)){
}

ErrorInfo& ErrorInfo::operator=(ErrorInfo&& rhs)
{
error_state = rhs.error_state;
event_type = std::move(rhs.event_type);
challenge_reply_error_type = std::move(rhs.challenge_reply_error_type);
net_return_value = std::move(rhs.net_return_value);
nss_error_code = std::move(rhs.nss_error_code);
return *this;
}

// static
bool ErrorInfo::Populate(
    const base::Value& value, ErrorInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* error_state_value = NULL;
  if (!dict->GetWithoutPathExpansion("errorState", &error_state_value)) {
    return false;
  }
  {
    std::string channel_error_as_string;
    if (!error_state_value->GetAsString(&channel_error_as_string)) {
      return false;
    }
    out->error_state = ParseChannelError(channel_error_as_string);
    if (out->error_state == CHANNEL_ERROR_NONE) {
      return false;
    }
  }

  const base::Value* event_type_value = NULL;
  if (dict->GetWithoutPathExpansion("eventType", &event_type_value)) {
    {
      int temp;
      if (!event_type_value->GetAsInteger(&temp)) {
        out->event_type.reset();
        return false;
      }
      else
        out->event_type.reset(new int(temp));
    }
  }

  const base::Value* challenge_reply_error_type_value = NULL;
  if (dict->GetWithoutPathExpansion("challengeReplyErrorType", &challenge_reply_error_type_value)) {
    {
      int temp;
      if (!challenge_reply_error_type_value->GetAsInteger(&temp)) {
        out->challenge_reply_error_type.reset();
        return false;
      }
      else
        out->challenge_reply_error_type.reset(new int(temp));
    }
  }

  const base::Value* net_return_value_value = NULL;
  if (dict->GetWithoutPathExpansion("netReturnValue", &net_return_value_value)) {
    {
      int temp;
      if (!net_return_value_value->GetAsInteger(&temp)) {
        out->net_return_value.reset();
        return false;
      }
      else
        out->net_return_value.reset(new int(temp));
    }
  }

  const base::Value* nss_error_code_value = NULL;
  if (dict->GetWithoutPathExpansion("nssErrorCode", &nss_error_code_value)) {
    {
      int temp;
      if (!nss_error_code_value->GetAsInteger(&temp)) {
        out->nss_error_code.reset();
        return false;
      }
      else
        out->nss_error_code.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ErrorInfo> ErrorInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ErrorInfo> out(new ErrorInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ErrorInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("errorState", std::make_unique<base::Value>(cast_channel::ToString(this->error_state)));

  if (this->event_type.get()) {
    to_value_result->SetWithoutPathExpansion("eventType", std::make_unique<base::Value>(*this->event_type));

  }
  if (this->challenge_reply_error_type.get()) {
    to_value_result->SetWithoutPathExpansion("challengeReplyErrorType", std::make_unique<base::Value>(*this->challenge_reply_error_type));

  }
  if (this->net_return_value.get()) {
    to_value_result->SetWithoutPathExpansion("netReturnValue", std::make_unique<base::Value>(*this->net_return_value));

  }
  if (this->nss_error_code.get()) {
    to_value_result->SetWithoutPathExpansion("nssErrorCode", std::make_unique<base::Value>(*this->nss_error_code));

  }

  return to_value_result;
}



//
// Functions
//

namespace Open {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connect_info_value = NULL;
  if (args.Get(0, &connect_info_value) &&
      !connect_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!connect_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectInfo::Populate(*dictionary, &params->connect_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ChannelInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace Open

namespace Send {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* channel_value = NULL;
  if (args.Get(0, &channel_value) &&
      !channel_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!channel_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ChannelInfo::Populate(*dictionary, &params->channel)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* message_value = NULL;
  if (args.Get(1, &message_value) &&
      !message_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!message_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!MessageInfo::Populate(*dictionary, &params->message)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ChannelInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

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

  const base::Value* channel_value = NULL;
  if (args.Get(0, &channel_value) &&
      !channel_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!channel_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ChannelInfo::Populate(*dictionary, &params->channel)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ChannelInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace Close

//
// Events
//

namespace OnMessage {

const char kEventName[] = "cast.channel.onMessage";

std::unique_ptr<base::ListValue> Create(const ChannelInfo& channel, const MessageInfo& message) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((channel).ToValue());

  create_results->Append((message).ToValue());

  return create_results;
}

}  // namespace OnMessage

namespace OnError {

const char kEventName[] = "cast.channel.onError";

std::unique_ptr<base::ListValue> Create(const ChannelInfo& channel, const ErrorInfo& error) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((channel).ToValue());

  create_results->Append((error).ToValue());

  return create_results;
}

}  // namespace OnError

}  // namespace cast_channel
}  // namespace api
}  // namespace extensions

