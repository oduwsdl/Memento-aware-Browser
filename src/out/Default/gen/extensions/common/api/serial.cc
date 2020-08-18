// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/serial.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/serial.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace serial {
//
// Types
//

DeviceInfo::DeviceInfo()
 {}

DeviceInfo::~DeviceInfo() {}
DeviceInfo::DeviceInfo(DeviceInfo&& rhs)
: path(std::move(rhs.path)),
vendor_id(std::move(rhs.vendor_id)),
product_id(std::move(rhs.product_id)),
display_name(std::move(rhs.display_name)){
}

DeviceInfo& DeviceInfo::operator=(DeviceInfo&& rhs)
{
path = std::move(rhs.path);
vendor_id = std::move(rhs.vendor_id);
product_id = std::move(rhs.product_id);
display_name = std::move(rhs.display_name);
return *this;
}

// static
bool DeviceInfo::Populate(
    const base::Value& value, DeviceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* path_value = NULL;
  if (!dict->GetWithoutPathExpansion("path", &path_value)) {
    return false;
  }
  {
    if (!path_value->GetAsString(&out->path)) {
      return false;
    }
  }

  const base::Value* vendor_id_value = NULL;
  if (dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    {
      int temp;
      if (!vendor_id_value->GetAsInteger(&temp)) {
        out->vendor_id.reset();
        return false;
      }
      else
        out->vendor_id.reset(new int(temp));
    }
  }

  const base::Value* product_id_value = NULL;
  if (dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    {
      int temp;
      if (!product_id_value->GetAsInteger(&temp)) {
        out->product_id.reset();
        return false;
      }
      else
        out->product_id.reset(new int(temp));
    }
  }

  const base::Value* display_name_value = NULL;
  if (dict->GetWithoutPathExpansion("displayName", &display_name_value)) {
    {
      std::string temp;
      if (!display_name_value->GetAsString(&temp)) {
        out->display_name.reset();
        return false;
      }
      else
        out->display_name.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceInfo> DeviceInfo::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceInfo> out(new DeviceInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(this->path));

  if (this->vendor_id.get()) {
    to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(*this->vendor_id));

  }
  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->display_name.get()) {
    to_value_result->SetWithoutPathExpansion("displayName", std::make_unique<base::Value>(*this->display_name));

  }

  return to_value_result;
}


const char* ToString(DataBits enum_param) {
  switch (enum_param) {
    case DATA_BITS_SEVEN:
      return "seven";
    case DATA_BITS_EIGHT:
      return "eight";
    case DATA_BITS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DataBits ParseDataBits(const std::string& enum_string) {
  if (enum_string == "seven")
    return DATA_BITS_SEVEN;
  if (enum_string == "eight")
    return DATA_BITS_EIGHT;
  return DATA_BITS_NONE;
}


const char* ToString(ParityBit enum_param) {
  switch (enum_param) {
    case PARITY_BIT_NO:
      return "no";
    case PARITY_BIT_ODD:
      return "odd";
    case PARITY_BIT_EVEN:
      return "even";
    case PARITY_BIT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ParityBit ParseParityBit(const std::string& enum_string) {
  if (enum_string == "no")
    return PARITY_BIT_NO;
  if (enum_string == "odd")
    return PARITY_BIT_ODD;
  if (enum_string == "even")
    return PARITY_BIT_EVEN;
  return PARITY_BIT_NONE;
}


const char* ToString(StopBits enum_param) {
  switch (enum_param) {
    case STOP_BITS_ONE:
      return "one";
    case STOP_BITS_TWO:
      return "two";
    case STOP_BITS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

StopBits ParseStopBits(const std::string& enum_string) {
  if (enum_string == "one")
    return STOP_BITS_ONE;
  if (enum_string == "two")
    return STOP_BITS_TWO;
  return STOP_BITS_NONE;
}


ConnectionOptions::ConnectionOptions()
: data_bits(DATA_BITS_NONE),
parity_bit(PARITY_BIT_NONE),
stop_bits(STOP_BITS_NONE) {}

ConnectionOptions::~ConnectionOptions() {}
ConnectionOptions::ConnectionOptions(ConnectionOptions&& rhs)
: persistent(std::move(rhs.persistent)),
name(std::move(rhs.name)),
buffer_size(std::move(rhs.buffer_size)),
bitrate(std::move(rhs.bitrate)),
data_bits(rhs.data_bits),
parity_bit(rhs.parity_bit),
stop_bits(rhs.stop_bits),
cts_flow_control(std::move(rhs.cts_flow_control)),
receive_timeout(std::move(rhs.receive_timeout)),
send_timeout(std::move(rhs.send_timeout)){
}

ConnectionOptions& ConnectionOptions::operator=(ConnectionOptions&& rhs)
{
persistent = std::move(rhs.persistent);
name = std::move(rhs.name);
buffer_size = std::move(rhs.buffer_size);
bitrate = std::move(rhs.bitrate);
data_bits = rhs.data_bits;
parity_bit = rhs.parity_bit;
stop_bits = rhs.stop_bits;
cts_flow_control = std::move(rhs.cts_flow_control);
receive_timeout = std::move(rhs.receive_timeout);
send_timeout = std::move(rhs.send_timeout);
return *this;
}

// static
bool ConnectionOptions::Populate(
    const base::Value& value, ConnectionOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->data_bits = DATA_BITS_NONE;
  out->parity_bit = PARITY_BIT_NONE;
  out->stop_bits = STOP_BITS_NONE;
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

  const base::Value* bitrate_value = NULL;
  if (dict->GetWithoutPathExpansion("bitrate", &bitrate_value)) {
    {
      int temp;
      if (!bitrate_value->GetAsInteger(&temp)) {
        out->bitrate.reset();
        return false;
      }
      else
        out->bitrate.reset(new int(temp));
    }
  }

  const base::Value* data_bits_value = NULL;
  if (dict->GetWithoutPathExpansion("dataBits", &data_bits_value)) {
    {
      std::string data_bits_as_string;
      if (!data_bits_value->GetAsString(&data_bits_as_string)) {
        return false;
      }
      out->data_bits = ParseDataBits(data_bits_as_string);
      if (out->data_bits == DATA_BITS_NONE) {
        return false;
      }
    }
    } else {
    out->data_bits = DATA_BITS_NONE;
  }

  const base::Value* parity_bit_value = NULL;
  if (dict->GetWithoutPathExpansion("parityBit", &parity_bit_value)) {
    {
      std::string parity_bit_as_string;
      if (!parity_bit_value->GetAsString(&parity_bit_as_string)) {
        return false;
      }
      out->parity_bit = ParseParityBit(parity_bit_as_string);
      if (out->parity_bit == PARITY_BIT_NONE) {
        return false;
      }
    }
    } else {
    out->parity_bit = PARITY_BIT_NONE;
  }

  const base::Value* stop_bits_value = NULL;
  if (dict->GetWithoutPathExpansion("stopBits", &stop_bits_value)) {
    {
      std::string stop_bits_as_string;
      if (!stop_bits_value->GetAsString(&stop_bits_as_string)) {
        return false;
      }
      out->stop_bits = ParseStopBits(stop_bits_as_string);
      if (out->stop_bits == STOP_BITS_NONE) {
        return false;
      }
    }
    } else {
    out->stop_bits = STOP_BITS_NONE;
  }

  const base::Value* cts_flow_control_value = NULL;
  if (dict->GetWithoutPathExpansion("ctsFlowControl", &cts_flow_control_value)) {
    {
      bool temp;
      if (!cts_flow_control_value->GetAsBoolean(&temp)) {
        out->cts_flow_control.reset();
        return false;
      }
      else
        out->cts_flow_control.reset(new bool(temp));
    }
  }

  const base::Value* receive_timeout_value = NULL;
  if (dict->GetWithoutPathExpansion("receiveTimeout", &receive_timeout_value)) {
    {
      int temp;
      if (!receive_timeout_value->GetAsInteger(&temp)) {
        out->receive_timeout.reset();
        return false;
      }
      else
        out->receive_timeout.reset(new int(temp));
    }
  }

  const base::Value* send_timeout_value = NULL;
  if (dict->GetWithoutPathExpansion("sendTimeout", &send_timeout_value)) {
    {
      int temp;
      if (!send_timeout_value->GetAsInteger(&temp)) {
        out->send_timeout.reset();
        return false;
      }
      else
        out->send_timeout.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ConnectionOptions> ConnectionOptions::FromValue(const base::Value& value) {
  std::unique_ptr<ConnectionOptions> out(new ConnectionOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ConnectionOptions::ToValue() const {
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
  if (this->bitrate.get()) {
    to_value_result->SetWithoutPathExpansion("bitrate", std::make_unique<base::Value>(*this->bitrate));

  }
  if (this->data_bits != DATA_BITS_NONE) {
    to_value_result->SetWithoutPathExpansion("dataBits", std::make_unique<base::Value>(serial::ToString(this->data_bits)));

  }
  if (this->parity_bit != PARITY_BIT_NONE) {
    to_value_result->SetWithoutPathExpansion("parityBit", std::make_unique<base::Value>(serial::ToString(this->parity_bit)));

  }
  if (this->stop_bits != STOP_BITS_NONE) {
    to_value_result->SetWithoutPathExpansion("stopBits", std::make_unique<base::Value>(serial::ToString(this->stop_bits)));

  }
  if (this->cts_flow_control.get()) {
    to_value_result->SetWithoutPathExpansion("ctsFlowControl", std::make_unique<base::Value>(*this->cts_flow_control));

  }
  if (this->receive_timeout.get()) {
    to_value_result->SetWithoutPathExpansion("receiveTimeout", std::make_unique<base::Value>(*this->receive_timeout));

  }
  if (this->send_timeout.get()) {
    to_value_result->SetWithoutPathExpansion("sendTimeout", std::make_unique<base::Value>(*this->send_timeout));

  }

  return to_value_result;
}


ConnectionInfo::ConnectionInfo()
: connection_id(0),
paused(false),
persistent(false),
buffer_size(0),
receive_timeout(0),
send_timeout(0),
data_bits(DATA_BITS_NONE),
parity_bit(PARITY_BIT_NONE),
stop_bits(STOP_BITS_NONE) {}

ConnectionInfo::~ConnectionInfo() {}
ConnectionInfo::ConnectionInfo(ConnectionInfo&& rhs)
: connection_id(rhs.connection_id),
paused(rhs.paused),
persistent(rhs.persistent),
name(std::move(rhs.name)),
buffer_size(rhs.buffer_size),
receive_timeout(rhs.receive_timeout),
send_timeout(rhs.send_timeout),
bitrate(std::move(rhs.bitrate)),
data_bits(rhs.data_bits),
parity_bit(rhs.parity_bit),
stop_bits(rhs.stop_bits),
cts_flow_control(std::move(rhs.cts_flow_control)){
}

ConnectionInfo& ConnectionInfo::operator=(ConnectionInfo&& rhs)
{
connection_id = rhs.connection_id;
paused = rhs.paused;
persistent = rhs.persistent;
name = std::move(rhs.name);
buffer_size = rhs.buffer_size;
receive_timeout = rhs.receive_timeout;
send_timeout = rhs.send_timeout;
bitrate = std::move(rhs.bitrate);
data_bits = rhs.data_bits;
parity_bit = rhs.parity_bit;
stop_bits = rhs.stop_bits;
cts_flow_control = std::move(rhs.cts_flow_control);
return *this;
}

// static
bool ConnectionInfo::Populate(
    const base::Value& value, ConnectionInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->data_bits = DATA_BITS_NONE;
  out->parity_bit = PARITY_BIT_NONE;
  out->stop_bits = STOP_BITS_NONE;
  const base::Value* connection_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("connectionId", &connection_id_value)) {
    return false;
  }
  {
    if (!connection_id_value->GetAsInteger(&out->connection_id)) {
      return false;
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
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* buffer_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("bufferSize", &buffer_size_value)) {
    return false;
  }
  {
    if (!buffer_size_value->GetAsInteger(&out->buffer_size)) {
      return false;
    }
  }

  const base::Value* receive_timeout_value = NULL;
  if (!dict->GetWithoutPathExpansion("receiveTimeout", &receive_timeout_value)) {
    return false;
  }
  {
    if (!receive_timeout_value->GetAsInteger(&out->receive_timeout)) {
      return false;
    }
  }

  const base::Value* send_timeout_value = NULL;
  if (!dict->GetWithoutPathExpansion("sendTimeout", &send_timeout_value)) {
    return false;
  }
  {
    if (!send_timeout_value->GetAsInteger(&out->send_timeout)) {
      return false;
    }
  }

  const base::Value* bitrate_value = NULL;
  if (dict->GetWithoutPathExpansion("bitrate", &bitrate_value)) {
    {
      int temp;
      if (!bitrate_value->GetAsInteger(&temp)) {
        out->bitrate.reset();
        return false;
      }
      else
        out->bitrate.reset(new int(temp));
    }
  }

  const base::Value* data_bits_value = NULL;
  if (dict->GetWithoutPathExpansion("dataBits", &data_bits_value)) {
    {
      std::string data_bits_as_string;
      if (!data_bits_value->GetAsString(&data_bits_as_string)) {
        return false;
      }
      out->data_bits = ParseDataBits(data_bits_as_string);
      if (out->data_bits == DATA_BITS_NONE) {
        return false;
      }
    }
    } else {
    out->data_bits = DATA_BITS_NONE;
  }

  const base::Value* parity_bit_value = NULL;
  if (dict->GetWithoutPathExpansion("parityBit", &parity_bit_value)) {
    {
      std::string parity_bit_as_string;
      if (!parity_bit_value->GetAsString(&parity_bit_as_string)) {
        return false;
      }
      out->parity_bit = ParseParityBit(parity_bit_as_string);
      if (out->parity_bit == PARITY_BIT_NONE) {
        return false;
      }
    }
    } else {
    out->parity_bit = PARITY_BIT_NONE;
  }

  const base::Value* stop_bits_value = NULL;
  if (dict->GetWithoutPathExpansion("stopBits", &stop_bits_value)) {
    {
      std::string stop_bits_as_string;
      if (!stop_bits_value->GetAsString(&stop_bits_as_string)) {
        return false;
      }
      out->stop_bits = ParseStopBits(stop_bits_as_string);
      if (out->stop_bits == STOP_BITS_NONE) {
        return false;
      }
    }
    } else {
    out->stop_bits = STOP_BITS_NONE;
  }

  const base::Value* cts_flow_control_value = NULL;
  if (dict->GetWithoutPathExpansion("ctsFlowControl", &cts_flow_control_value)) {
    {
      bool temp;
      if (!cts_flow_control_value->GetAsBoolean(&temp)) {
        out->cts_flow_control.reset();
        return false;
      }
      else
        out->cts_flow_control.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ConnectionInfo> ConnectionInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ConnectionInfo> out(new ConnectionInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ConnectionInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("connectionId", std::make_unique<base::Value>(this->connection_id));

  to_value_result->SetWithoutPathExpansion("paused", std::make_unique<base::Value>(this->paused));

  to_value_result->SetWithoutPathExpansion("persistent", std::make_unique<base::Value>(this->persistent));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("bufferSize", std::make_unique<base::Value>(this->buffer_size));

  to_value_result->SetWithoutPathExpansion("receiveTimeout", std::make_unique<base::Value>(this->receive_timeout));

  to_value_result->SetWithoutPathExpansion("sendTimeout", std::make_unique<base::Value>(this->send_timeout));

  if (this->bitrate.get()) {
    to_value_result->SetWithoutPathExpansion("bitrate", std::make_unique<base::Value>(*this->bitrate));

  }
  if (this->data_bits != DATA_BITS_NONE) {
    to_value_result->SetWithoutPathExpansion("dataBits", std::make_unique<base::Value>(serial::ToString(this->data_bits)));

  }
  if (this->parity_bit != PARITY_BIT_NONE) {
    to_value_result->SetWithoutPathExpansion("parityBit", std::make_unique<base::Value>(serial::ToString(this->parity_bit)));

  }
  if (this->stop_bits != STOP_BITS_NONE) {
    to_value_result->SetWithoutPathExpansion("stopBits", std::make_unique<base::Value>(serial::ToString(this->stop_bits)));

  }
  if (this->cts_flow_control.get()) {
    to_value_result->SetWithoutPathExpansion("ctsFlowControl", std::make_unique<base::Value>(*this->cts_flow_control));

  }

  return to_value_result;
}


const char* ToString(SendError enum_param) {
  switch (enum_param) {
    case SEND_ERROR_DISCONNECTED:
      return "disconnected";
    case SEND_ERROR_PENDING:
      return "pending";
    case SEND_ERROR_TIMEOUT:
      return "timeout";
    case SEND_ERROR_SYSTEM_ERROR:
      return "system_error";
    case SEND_ERROR_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SendError ParseSendError(const std::string& enum_string) {
  if (enum_string == "disconnected")
    return SEND_ERROR_DISCONNECTED;
  if (enum_string == "pending")
    return SEND_ERROR_PENDING;
  if (enum_string == "timeout")
    return SEND_ERROR_TIMEOUT;
  if (enum_string == "system_error")
    return SEND_ERROR_SYSTEM_ERROR;
  return SEND_ERROR_NONE;
}


SendInfo::SendInfo()
: bytes_sent(0),
error(SEND_ERROR_NONE) {}

SendInfo::~SendInfo() {}
SendInfo::SendInfo(SendInfo&& rhs)
: bytes_sent(rhs.bytes_sent),
error(rhs.error){
}

SendInfo& SendInfo::operator=(SendInfo&& rhs)
{
bytes_sent = rhs.bytes_sent;
error = rhs.error;
return *this;
}

// static
bool SendInfo::Populate(
    const base::Value& value, SendInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->error = SEND_ERROR_NONE;
  const base::Value* bytes_sent_value = NULL;
  if (!dict->GetWithoutPathExpansion("bytesSent", &bytes_sent_value)) {
    return false;
  }
  {
    if (!bytes_sent_value->GetAsInteger(&out->bytes_sent)) {
      return false;
    }
  }

  const base::Value* error_value = NULL;
  if (dict->GetWithoutPathExpansion("error", &error_value)) {
    {
      std::string send_error_as_string;
      if (!error_value->GetAsString(&send_error_as_string)) {
        return false;
      }
      out->error = ParseSendError(send_error_as_string);
      if (out->error == SEND_ERROR_NONE) {
        return false;
      }
    }
    } else {
    out->error = SEND_ERROR_NONE;
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

  to_value_result->SetWithoutPathExpansion("bytesSent", std::make_unique<base::Value>(this->bytes_sent));

  if (this->error != SEND_ERROR_NONE) {
    to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(serial::ToString(this->error)));

  }

  return to_value_result;
}


HostControlSignals::HostControlSignals()
 {}

HostControlSignals::~HostControlSignals() {}
HostControlSignals::HostControlSignals(HostControlSignals&& rhs)
: dtr(std::move(rhs.dtr)),
rts(std::move(rhs.rts)){
}

HostControlSignals& HostControlSignals::operator=(HostControlSignals&& rhs)
{
dtr = std::move(rhs.dtr);
rts = std::move(rhs.rts);
return *this;
}

// static
bool HostControlSignals::Populate(
    const base::Value& value, HostControlSignals* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* dtr_value = NULL;
  if (dict->GetWithoutPathExpansion("dtr", &dtr_value)) {
    {
      bool temp;
      if (!dtr_value->GetAsBoolean(&temp)) {
        out->dtr.reset();
        return false;
      }
      else
        out->dtr.reset(new bool(temp));
    }
  }

  const base::Value* rts_value = NULL;
  if (dict->GetWithoutPathExpansion("rts", &rts_value)) {
    {
      bool temp;
      if (!rts_value->GetAsBoolean(&temp)) {
        out->rts.reset();
        return false;
      }
      else
        out->rts.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<HostControlSignals> HostControlSignals::FromValue(const base::Value& value) {
  std::unique_ptr<HostControlSignals> out(new HostControlSignals());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HostControlSignals::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->dtr.get()) {
    to_value_result->SetWithoutPathExpansion("dtr", std::make_unique<base::Value>(*this->dtr));

  }
  if (this->rts.get()) {
    to_value_result->SetWithoutPathExpansion("rts", std::make_unique<base::Value>(*this->rts));

  }

  return to_value_result;
}


DeviceControlSignals::DeviceControlSignals()
: dcd(false),
cts(false),
ri(false),
dsr(false) {}

DeviceControlSignals::~DeviceControlSignals() {}
DeviceControlSignals::DeviceControlSignals(DeviceControlSignals&& rhs)
: dcd(rhs.dcd),
cts(rhs.cts),
ri(rhs.ri),
dsr(rhs.dsr){
}

DeviceControlSignals& DeviceControlSignals::operator=(DeviceControlSignals&& rhs)
{
dcd = rhs.dcd;
cts = rhs.cts;
ri = rhs.ri;
dsr = rhs.dsr;
return *this;
}

// static
bool DeviceControlSignals::Populate(
    const base::Value& value, DeviceControlSignals* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* dcd_value = NULL;
  if (!dict->GetWithoutPathExpansion("dcd", &dcd_value)) {
    return false;
  }
  {
    if (!dcd_value->GetAsBoolean(&out->dcd)) {
      return false;
    }
  }

  const base::Value* cts_value = NULL;
  if (!dict->GetWithoutPathExpansion("cts", &cts_value)) {
    return false;
  }
  {
    if (!cts_value->GetAsBoolean(&out->cts)) {
      return false;
    }
  }

  const base::Value* ri_value = NULL;
  if (!dict->GetWithoutPathExpansion("ri", &ri_value)) {
    return false;
  }
  {
    if (!ri_value->GetAsBoolean(&out->ri)) {
      return false;
    }
  }

  const base::Value* dsr_value = NULL;
  if (!dict->GetWithoutPathExpansion("dsr", &dsr_value)) {
    return false;
  }
  {
    if (!dsr_value->GetAsBoolean(&out->dsr)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceControlSignals> DeviceControlSignals::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceControlSignals> out(new DeviceControlSignals());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceControlSignals::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("dcd", std::make_unique<base::Value>(this->dcd));

  to_value_result->SetWithoutPathExpansion("cts", std::make_unique<base::Value>(this->cts));

  to_value_result->SetWithoutPathExpansion("ri", std::make_unique<base::Value>(this->ri));

  to_value_result->SetWithoutPathExpansion("dsr", std::make_unique<base::Value>(this->dsr));


  return to_value_result;
}


ReceiveInfo::ReceiveInfo()
: connection_id(0) {}

ReceiveInfo::~ReceiveInfo() {}
ReceiveInfo::ReceiveInfo(ReceiveInfo&& rhs)
: connection_id(rhs.connection_id),
data(std::move(rhs.data)){
}

ReceiveInfo& ReceiveInfo::operator=(ReceiveInfo&& rhs)
{
connection_id = rhs.connection_id;
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
  const base::Value* connection_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("connectionId", &connection_id_value)) {
    return false;
  }
  {
    if (!connection_id_value->GetAsInteger(&out->connection_id)) {
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

  to_value_result->SetWithoutPathExpansion("connectionId", std::make_unique<base::Value>(this->connection_id));

  to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(this->data));


  return to_value_result;
}


const char* ToString(ReceiveError enum_param) {
  switch (enum_param) {
    case RECEIVE_ERROR_DISCONNECTED:
      return "disconnected";
    case RECEIVE_ERROR_TIMEOUT:
      return "timeout";
    case RECEIVE_ERROR_DEVICE_LOST:
      return "device_lost";
    case RECEIVE_ERROR_BREAK:
      return "break";
    case RECEIVE_ERROR_FRAME_ERROR:
      return "frame_error";
    case RECEIVE_ERROR_OVERRUN:
      return "overrun";
    case RECEIVE_ERROR_BUFFER_OVERFLOW:
      return "buffer_overflow";
    case RECEIVE_ERROR_PARITY_ERROR:
      return "parity_error";
    case RECEIVE_ERROR_SYSTEM_ERROR:
      return "system_error";
    case RECEIVE_ERROR_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ReceiveError ParseReceiveError(const std::string& enum_string) {
  if (enum_string == "disconnected")
    return RECEIVE_ERROR_DISCONNECTED;
  if (enum_string == "timeout")
    return RECEIVE_ERROR_TIMEOUT;
  if (enum_string == "device_lost")
    return RECEIVE_ERROR_DEVICE_LOST;
  if (enum_string == "break")
    return RECEIVE_ERROR_BREAK;
  if (enum_string == "frame_error")
    return RECEIVE_ERROR_FRAME_ERROR;
  if (enum_string == "overrun")
    return RECEIVE_ERROR_OVERRUN;
  if (enum_string == "buffer_overflow")
    return RECEIVE_ERROR_BUFFER_OVERFLOW;
  if (enum_string == "parity_error")
    return RECEIVE_ERROR_PARITY_ERROR;
  if (enum_string == "system_error")
    return RECEIVE_ERROR_SYSTEM_ERROR;
  return RECEIVE_ERROR_NONE;
}


ReceiveErrorInfo::ReceiveErrorInfo()
: connection_id(0),
error(RECEIVE_ERROR_NONE) {}

ReceiveErrorInfo::~ReceiveErrorInfo() {}
ReceiveErrorInfo::ReceiveErrorInfo(ReceiveErrorInfo&& rhs)
: connection_id(rhs.connection_id),
error(rhs.error){
}

ReceiveErrorInfo& ReceiveErrorInfo::operator=(ReceiveErrorInfo&& rhs)
{
connection_id = rhs.connection_id;
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
  const base::Value* connection_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("connectionId", &connection_id_value)) {
    return false;
  }
  {
    if (!connection_id_value->GetAsInteger(&out->connection_id)) {
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

  to_value_result->SetWithoutPathExpansion("connectionId", std::make_unique<base::Value>(this->connection_id));

  to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(serial::ToString(this->error)));


  return to_value_result;
}



//
// Functions
//

namespace GetDevices {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<DeviceInfo>& ports) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(ports));

  return create_results;
}
}  // namespace GetDevices

namespace Connect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* path_value = NULL;
  if (args.Get(0, &path_value) &&
      !path_value->is_none()) {
    {
      if (!path_value->GetAsString(&params->path)) {
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
        std::unique_ptr<ConnectionOptions> temp(new ConnectionOptions());
        if (!ConnectionOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ConnectionInfo& connection_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((connection_info).ToValue());

  return create_results;
}
}  // namespace Connect

namespace Update {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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
      if (!ConnectionOptions::Populate(*dictionary, &params->options)) {
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
}  // namespace Update

namespace Disconnect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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
}  // namespace Disconnect

namespace SetPaused {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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

namespace GetInfo {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ConnectionInfo& connection_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((connection_info).ToValue());

  return create_results;
}
}  // namespace GetInfo

namespace GetConnections {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<ConnectionInfo>& connection_infos) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(connection_infos));

  return create_results;
}
}  // namespace GetConnections

namespace Send {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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


std::unique_ptr<base::ListValue> Results::Create(const SendInfo& send_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((send_info).ToValue());

  return create_results;
}
}  // namespace Send

namespace Flush {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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
}  // namespace Flush

namespace GetControlSignals {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const DeviceControlSignals& signals) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((signals).ToValue());

  return create_results;
}
}  // namespace GetControlSignals

namespace SetControlSignals {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* signals_value = NULL;
  if (args.Get(1, &signals_value) &&
      !signals_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!signals_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!HostControlSignals::Populate(*dictionary, &params->signals)) {
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
}  // namespace SetControlSignals

namespace SetBreak {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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
}  // namespace SetBreak

namespace ClearBreak {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* connection_id_value = NULL;
  if (args.Get(0, &connection_id_value) &&
      !connection_id_value->is_none()) {
    {
      if (!connection_id_value->GetAsInteger(&params->connection_id)) {
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
}  // namespace ClearBreak

//
// Events
//

namespace OnReceive {

const char kEventName[] = "serial.onReceive";

std::unique_ptr<base::ListValue> Create(const ReceiveInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnReceive

namespace OnReceiveError {

const char kEventName[] = "serial.onReceiveError";

std::unique_ptr<base::ListValue> Create(const ReceiveErrorInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnReceiveError

}  // namespace serial
}  // namespace api
}  // namespace extensions

