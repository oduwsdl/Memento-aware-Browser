// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/usb.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/usb.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace usb {
//
// Types
//

const char* ToString(Direction enum_param) {
  switch (enum_param) {
    case DIRECTION_IN:
      return "in";
    case DIRECTION_OUT:
      return "out";
    case DIRECTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Direction ParseDirection(const std::string& enum_string) {
  if (enum_string == "in")
    return DIRECTION_IN;
  if (enum_string == "out")
    return DIRECTION_OUT;
  return DIRECTION_NONE;
}


const char* ToString(Recipient enum_param) {
  switch (enum_param) {
    case RECIPIENT_DEVICE:
      return "device";
    case RECIPIENT_INTERFACE:
      return "interface";
    case RECIPIENT_ENDPOINT:
      return "endpoint";
    case RECIPIENT_OTHER:
      return "other";
    case RECIPIENT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Recipient ParseRecipient(const std::string& enum_string) {
  if (enum_string == "device")
    return RECIPIENT_DEVICE;
  if (enum_string == "interface")
    return RECIPIENT_INTERFACE;
  if (enum_string == "endpoint")
    return RECIPIENT_ENDPOINT;
  if (enum_string == "other")
    return RECIPIENT_OTHER;
  return RECIPIENT_NONE;
}


const char* ToString(RequestType enum_param) {
  switch (enum_param) {
    case REQUEST_TYPE_STANDARD:
      return "standard";
    case REQUEST_TYPE_CLASS:
      return "class";
    case REQUEST_TYPE_VENDOR:
      return "vendor";
    case REQUEST_TYPE_RESERVED:
      return "reserved";
    case REQUEST_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

RequestType ParseRequestType(const std::string& enum_string) {
  if (enum_string == "standard")
    return REQUEST_TYPE_STANDARD;
  if (enum_string == "class")
    return REQUEST_TYPE_CLASS;
  if (enum_string == "vendor")
    return REQUEST_TYPE_VENDOR;
  if (enum_string == "reserved")
    return REQUEST_TYPE_RESERVED;
  return REQUEST_TYPE_NONE;
}


const char* ToString(TransferType enum_param) {
  switch (enum_param) {
    case TRANSFER_TYPE_CONTROL:
      return "control";
    case TRANSFER_TYPE_INTERRUPT:
      return "interrupt";
    case TRANSFER_TYPE_ISOCHRONOUS:
      return "isochronous";
    case TRANSFER_TYPE_BULK:
      return "bulk";
    case TRANSFER_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TransferType ParseTransferType(const std::string& enum_string) {
  if (enum_string == "control")
    return TRANSFER_TYPE_CONTROL;
  if (enum_string == "interrupt")
    return TRANSFER_TYPE_INTERRUPT;
  if (enum_string == "isochronous")
    return TRANSFER_TYPE_ISOCHRONOUS;
  if (enum_string == "bulk")
    return TRANSFER_TYPE_BULK;
  return TRANSFER_TYPE_NONE;
}


const char* ToString(SynchronizationType enum_param) {
  switch (enum_param) {
    case SYNCHRONIZATION_TYPE_ASYNCHRONOUS:
      return "asynchronous";
    case SYNCHRONIZATION_TYPE_ADAPTIVE:
      return "adaptive";
    case SYNCHRONIZATION_TYPE_SYNCHRONOUS:
      return "synchronous";
    case SYNCHRONIZATION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SynchronizationType ParseSynchronizationType(const std::string& enum_string) {
  if (enum_string == "asynchronous")
    return SYNCHRONIZATION_TYPE_ASYNCHRONOUS;
  if (enum_string == "adaptive")
    return SYNCHRONIZATION_TYPE_ADAPTIVE;
  if (enum_string == "synchronous")
    return SYNCHRONIZATION_TYPE_SYNCHRONOUS;
  return SYNCHRONIZATION_TYPE_NONE;
}


const char* ToString(UsageType enum_param) {
  switch (enum_param) {
    case USAGE_TYPE_DATA:
      return "data";
    case USAGE_TYPE_FEEDBACK:
      return "feedback";
    case USAGE_TYPE_EXPLICITFEEDBACK:
      return "explicitFeedback";
    case USAGE_TYPE_PERIODIC:
      return "periodic";
    case USAGE_TYPE_NOTIFICATION:
      return "notification";
    case USAGE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

UsageType ParseUsageType(const std::string& enum_string) {
  if (enum_string == "data")
    return USAGE_TYPE_DATA;
  if (enum_string == "feedback")
    return USAGE_TYPE_FEEDBACK;
  if (enum_string == "explicitFeedback")
    return USAGE_TYPE_EXPLICITFEEDBACK;
  if (enum_string == "periodic")
    return USAGE_TYPE_PERIODIC;
  if (enum_string == "notification")
    return USAGE_TYPE_NOTIFICATION;
  return USAGE_TYPE_NONE;
}


Device::Device()
: device(0),
vendor_id(0),
product_id(0),
version(0) {}

Device::~Device() {}
Device::Device(Device&& rhs)
: device(rhs.device),
vendor_id(rhs.vendor_id),
product_id(rhs.product_id),
version(rhs.version),
product_name(std::move(rhs.product_name)),
manufacturer_name(std::move(rhs.manufacturer_name)),
serial_number(std::move(rhs.serial_number)){
}

Device& Device::operator=(Device&& rhs)
{
device = rhs.device;
vendor_id = rhs.vendor_id;
product_id = rhs.product_id;
version = rhs.version;
product_name = std::move(rhs.product_name);
manufacturer_name = std::move(rhs.manufacturer_name);
serial_number = std::move(rhs.serial_number);
return *this;
}

// static
bool Device::Populate(
    const base::Value& value, Device* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* device_value = NULL;
  if (!dict->GetWithoutPathExpansion("device", &device_value)) {
    return false;
  }
  {
    if (!device_value->GetAsInteger(&out->device)) {
      return false;
    }
  }

  const base::Value* vendor_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    return false;
  }
  {
    if (!vendor_id_value->GetAsInteger(&out->vendor_id)) {
      return false;
    }
  }

  const base::Value* product_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    return false;
  }
  {
    if (!product_id_value->GetAsInteger(&out->product_id)) {
      return false;
    }
  }

  const base::Value* version_value = NULL;
  if (!dict->GetWithoutPathExpansion("version", &version_value)) {
    return false;
  }
  {
    if (!version_value->GetAsInteger(&out->version)) {
      return false;
    }
  }

  const base::Value* product_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("productName", &product_name_value)) {
    return false;
  }
  {
    if (!product_name_value->GetAsString(&out->product_name)) {
      return false;
    }
  }

  const base::Value* manufacturer_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("manufacturerName", &manufacturer_name_value)) {
    return false;
  }
  {
    if (!manufacturer_name_value->GetAsString(&out->manufacturer_name)) {
      return false;
    }
  }

  const base::Value* serial_number_value = NULL;
  if (!dict->GetWithoutPathExpansion("serialNumber", &serial_number_value)) {
    return false;
  }
  {
    if (!serial_number_value->GetAsString(&out->serial_number)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Device> Device::FromValue(const base::Value& value) {
  std::unique_ptr<Device> out(new Device());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Device::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("device", std::make_unique<base::Value>(this->device));

  to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(this->vendor_id));

  to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(this->product_id));

  to_value_result->SetWithoutPathExpansion("version", std::make_unique<base::Value>(this->version));

  to_value_result->SetWithoutPathExpansion("productName", std::make_unique<base::Value>(this->product_name));

  to_value_result->SetWithoutPathExpansion("manufacturerName", std::make_unique<base::Value>(this->manufacturer_name));

  to_value_result->SetWithoutPathExpansion("serialNumber", std::make_unique<base::Value>(this->serial_number));


  return to_value_result;
}


ConnectionHandle::ConnectionHandle()
: handle(0),
vendor_id(0),
product_id(0) {}

ConnectionHandle::~ConnectionHandle() {}
ConnectionHandle::ConnectionHandle(ConnectionHandle&& rhs)
: handle(rhs.handle),
vendor_id(rhs.vendor_id),
product_id(rhs.product_id){
}

ConnectionHandle& ConnectionHandle::operator=(ConnectionHandle&& rhs)
{
handle = rhs.handle;
vendor_id = rhs.vendor_id;
product_id = rhs.product_id;
return *this;
}

// static
bool ConnectionHandle::Populate(
    const base::Value& value, ConnectionHandle* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* handle_value = NULL;
  if (!dict->GetWithoutPathExpansion("handle", &handle_value)) {
    return false;
  }
  {
    if (!handle_value->GetAsInteger(&out->handle)) {
      return false;
    }
  }

  const base::Value* vendor_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    return false;
  }
  {
    if (!vendor_id_value->GetAsInteger(&out->vendor_id)) {
      return false;
    }
  }

  const base::Value* product_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    return false;
  }
  {
    if (!product_id_value->GetAsInteger(&out->product_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ConnectionHandle> ConnectionHandle::FromValue(const base::Value& value) {
  std::unique_ptr<ConnectionHandle> out(new ConnectionHandle());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ConnectionHandle::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("handle", std::make_unique<base::Value>(this->handle));

  to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(this->vendor_id));

  to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(this->product_id));


  return to_value_result;
}


EndpointDescriptor::EndpointDescriptor()
: address(0),
type(TRANSFER_TYPE_NONE),
direction(DIRECTION_NONE),
maximum_packet_size(0),
synchronization(SYNCHRONIZATION_TYPE_NONE),
usage(USAGE_TYPE_NONE) {}

EndpointDescriptor::~EndpointDescriptor() {}
EndpointDescriptor::EndpointDescriptor(EndpointDescriptor&& rhs)
: address(rhs.address),
type(rhs.type),
direction(rhs.direction),
maximum_packet_size(rhs.maximum_packet_size),
synchronization(rhs.synchronization),
usage(rhs.usage),
polling_interval(std::move(rhs.polling_interval)),
extra_data(std::move(rhs.extra_data)){
}

EndpointDescriptor& EndpointDescriptor::operator=(EndpointDescriptor&& rhs)
{
address = rhs.address;
type = rhs.type;
direction = rhs.direction;
maximum_packet_size = rhs.maximum_packet_size;
synchronization = rhs.synchronization;
usage = rhs.usage;
polling_interval = std::move(rhs.polling_interval);
extra_data = std::move(rhs.extra_data);
return *this;
}

// static
bool EndpointDescriptor::Populate(
    const base::Value& value, EndpointDescriptor* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->synchronization = SYNCHRONIZATION_TYPE_NONE;
  out->usage = USAGE_TYPE_NONE;
  const base::Value* address_value = NULL;
  if (!dict->GetWithoutPathExpansion("address", &address_value)) {
    return false;
  }
  {
    if (!address_value->GetAsInteger(&out->address)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string transfer_type_as_string;
    if (!type_value->GetAsString(&transfer_type_as_string)) {
      return false;
    }
    out->type = ParseTransferType(transfer_type_as_string);
    if (out->type == TRANSFER_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* direction_value = NULL;
  if (!dict->GetWithoutPathExpansion("direction", &direction_value)) {
    return false;
  }
  {
    std::string direction_as_string;
    if (!direction_value->GetAsString(&direction_as_string)) {
      return false;
    }
    out->direction = ParseDirection(direction_as_string);
    if (out->direction == DIRECTION_NONE) {
      return false;
    }
  }

  const base::Value* maximum_packet_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("maximumPacketSize", &maximum_packet_size_value)) {
    return false;
  }
  {
    if (!maximum_packet_size_value->GetAsInteger(&out->maximum_packet_size)) {
      return false;
    }
  }

  const base::Value* synchronization_value = NULL;
  if (dict->GetWithoutPathExpansion("synchronization", &synchronization_value)) {
    {
      std::string synchronization_type_as_string;
      if (!synchronization_value->GetAsString(&synchronization_type_as_string)) {
        return false;
      }
      out->synchronization = ParseSynchronizationType(synchronization_type_as_string);
      if (out->synchronization == SYNCHRONIZATION_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->synchronization = SYNCHRONIZATION_TYPE_NONE;
  }

  const base::Value* usage_value = NULL;
  if (dict->GetWithoutPathExpansion("usage", &usage_value)) {
    {
      std::string usage_type_as_string;
      if (!usage_value->GetAsString(&usage_type_as_string)) {
        return false;
      }
      out->usage = ParseUsageType(usage_type_as_string);
      if (out->usage == USAGE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->usage = USAGE_TYPE_NONE;
  }

  const base::Value* polling_interval_value = NULL;
  if (dict->GetWithoutPathExpansion("pollingInterval", &polling_interval_value)) {
    {
      int temp;
      if (!polling_interval_value->GetAsInteger(&temp)) {
        out->polling_interval.reset();
        return false;
      }
      else
        out->polling_interval.reset(new int(temp));
    }
  }

  const base::Value* extra_data_value = NULL;
  if (!dict->GetWithoutPathExpansion("extra_data", &extra_data_value)) {
    return false;
  }
  {
    if (!extra_data_value->is_blob()) {
      return false;
    }
    else {
      out->extra_data = extra_data_value->GetBlob();
    }
  }

  return true;
}

// static
std::unique_ptr<EndpointDescriptor> EndpointDescriptor::FromValue(const base::Value& value) {
  std::unique_ptr<EndpointDescriptor> out(new EndpointDescriptor());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EndpointDescriptor::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(this->address));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(usb::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("direction", std::make_unique<base::Value>(usb::ToString(this->direction)));

  to_value_result->SetWithoutPathExpansion("maximumPacketSize", std::make_unique<base::Value>(this->maximum_packet_size));

  if (this->synchronization != SYNCHRONIZATION_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("synchronization", std::make_unique<base::Value>(usb::ToString(this->synchronization)));

  }
  if (this->usage != USAGE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("usage", std::make_unique<base::Value>(usb::ToString(this->usage)));

  }
  if (this->polling_interval.get()) {
    to_value_result->SetWithoutPathExpansion("pollingInterval", std::make_unique<base::Value>(*this->polling_interval));

  }
  to_value_result->SetWithoutPathExpansion("extra_data", std::make_unique<base::Value>(this->extra_data));


  return to_value_result;
}


InterfaceDescriptor::InterfaceDescriptor()
: interface_number(0),
alternate_setting(0),
interface_class(0),
interface_subclass(0),
interface_protocol(0) {}

InterfaceDescriptor::~InterfaceDescriptor() {}
InterfaceDescriptor::InterfaceDescriptor(InterfaceDescriptor&& rhs)
: interface_number(rhs.interface_number),
alternate_setting(rhs.alternate_setting),
interface_class(rhs.interface_class),
interface_subclass(rhs.interface_subclass),
interface_protocol(rhs.interface_protocol),
description(std::move(rhs.description)),
endpoints(std::move(rhs.endpoints)),
extra_data(std::move(rhs.extra_data)){
}

InterfaceDescriptor& InterfaceDescriptor::operator=(InterfaceDescriptor&& rhs)
{
interface_number = rhs.interface_number;
alternate_setting = rhs.alternate_setting;
interface_class = rhs.interface_class;
interface_subclass = rhs.interface_subclass;
interface_protocol = rhs.interface_protocol;
description = std::move(rhs.description);
endpoints = std::move(rhs.endpoints);
extra_data = std::move(rhs.extra_data);
return *this;
}

// static
bool InterfaceDescriptor::Populate(
    const base::Value& value, InterfaceDescriptor* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* interface_number_value = NULL;
  if (!dict->GetWithoutPathExpansion("interfaceNumber", &interface_number_value)) {
    return false;
  }
  {
    if (!interface_number_value->GetAsInteger(&out->interface_number)) {
      return false;
    }
  }

  const base::Value* alternate_setting_value = NULL;
  if (!dict->GetWithoutPathExpansion("alternateSetting", &alternate_setting_value)) {
    return false;
  }
  {
    if (!alternate_setting_value->GetAsInteger(&out->alternate_setting)) {
      return false;
    }
  }

  const base::Value* interface_class_value = NULL;
  if (!dict->GetWithoutPathExpansion("interfaceClass", &interface_class_value)) {
    return false;
  }
  {
    if (!interface_class_value->GetAsInteger(&out->interface_class)) {
      return false;
    }
  }

  const base::Value* interface_subclass_value = NULL;
  if (!dict->GetWithoutPathExpansion("interfaceSubclass", &interface_subclass_value)) {
    return false;
  }
  {
    if (!interface_subclass_value->GetAsInteger(&out->interface_subclass)) {
      return false;
    }
  }

  const base::Value* interface_protocol_value = NULL;
  if (!dict->GetWithoutPathExpansion("interfaceProtocol", &interface_protocol_value)) {
    return false;
  }
  {
    if (!interface_protocol_value->GetAsInteger(&out->interface_protocol)) {
      return false;
    }
  }

  const base::Value* description_value = NULL;
  if (dict->GetWithoutPathExpansion("description", &description_value)) {
    {
      std::string temp;
      if (!description_value->GetAsString(&temp)) {
        out->description.reset();
        return false;
      }
      else
        out->description.reset(new std::string(temp));
    }
  }

  const base::Value* endpoints_value = NULL;
  if (!dict->GetWithoutPathExpansion("endpoints", &endpoints_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!endpoints_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->endpoints)) {
        return false;
      }
    }
  }

  const base::Value* extra_data_value = NULL;
  if (!dict->GetWithoutPathExpansion("extra_data", &extra_data_value)) {
    return false;
  }
  {
    if (!extra_data_value->is_blob()) {
      return false;
    }
    else {
      out->extra_data = extra_data_value->GetBlob();
    }
  }

  return true;
}

// static
std::unique_ptr<InterfaceDescriptor> InterfaceDescriptor::FromValue(const base::Value& value) {
  std::unique_ptr<InterfaceDescriptor> out(new InterfaceDescriptor());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InterfaceDescriptor::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("interfaceNumber", std::make_unique<base::Value>(this->interface_number));

  to_value_result->SetWithoutPathExpansion("alternateSetting", std::make_unique<base::Value>(this->alternate_setting));

  to_value_result->SetWithoutPathExpansion("interfaceClass", std::make_unique<base::Value>(this->interface_class));

  to_value_result->SetWithoutPathExpansion("interfaceSubclass", std::make_unique<base::Value>(this->interface_subclass));

  to_value_result->SetWithoutPathExpansion("interfaceProtocol", std::make_unique<base::Value>(this->interface_protocol));

  if (this->description.get()) {
    to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(*this->description));

  }
  to_value_result->SetWithoutPathExpansion("endpoints", json_schema_compiler::util::CreateValueFromArray(this->endpoints));

  to_value_result->SetWithoutPathExpansion("extra_data", std::make_unique<base::Value>(this->extra_data));


  return to_value_result;
}


ConfigDescriptor::ConfigDescriptor()
: active(false),
configuration_value(0),
self_powered(false),
remote_wakeup(false),
max_power(0) {}

ConfigDescriptor::~ConfigDescriptor() {}
ConfigDescriptor::ConfigDescriptor(ConfigDescriptor&& rhs)
: active(rhs.active),
configuration_value(rhs.configuration_value),
description(std::move(rhs.description)),
self_powered(rhs.self_powered),
remote_wakeup(rhs.remote_wakeup),
max_power(rhs.max_power),
interfaces(std::move(rhs.interfaces)),
extra_data(std::move(rhs.extra_data)){
}

ConfigDescriptor& ConfigDescriptor::operator=(ConfigDescriptor&& rhs)
{
active = rhs.active;
configuration_value = rhs.configuration_value;
description = std::move(rhs.description);
self_powered = rhs.self_powered;
remote_wakeup = rhs.remote_wakeup;
max_power = rhs.max_power;
interfaces = std::move(rhs.interfaces);
extra_data = std::move(rhs.extra_data);
return *this;
}

// static
bool ConfigDescriptor::Populate(
    const base::Value& value, ConfigDescriptor* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* active_value = NULL;
  if (!dict->GetWithoutPathExpansion("active", &active_value)) {
    return false;
  }
  {
    if (!active_value->GetAsBoolean(&out->active)) {
      return false;
    }
  }

  const base::Value* configuration_value_value = NULL;
  if (!dict->GetWithoutPathExpansion("configurationValue", &configuration_value_value)) {
    return false;
  }
  {
    if (!configuration_value_value->GetAsInteger(&out->configuration_value)) {
      return false;
    }
  }

  const base::Value* description_value = NULL;
  if (dict->GetWithoutPathExpansion("description", &description_value)) {
    {
      std::string temp;
      if (!description_value->GetAsString(&temp)) {
        out->description.reset();
        return false;
      }
      else
        out->description.reset(new std::string(temp));
    }
  }

  const base::Value* self_powered_value = NULL;
  if (!dict->GetWithoutPathExpansion("selfPowered", &self_powered_value)) {
    return false;
  }
  {
    if (!self_powered_value->GetAsBoolean(&out->self_powered)) {
      return false;
    }
  }

  const base::Value* remote_wakeup_value = NULL;
  if (!dict->GetWithoutPathExpansion("remoteWakeup", &remote_wakeup_value)) {
    return false;
  }
  {
    if (!remote_wakeup_value->GetAsBoolean(&out->remote_wakeup)) {
      return false;
    }
  }

  const base::Value* max_power_value = NULL;
  if (!dict->GetWithoutPathExpansion("maxPower", &max_power_value)) {
    return false;
  }
  {
    if (!max_power_value->GetAsInteger(&out->max_power)) {
      return false;
    }
  }

  const base::Value* interfaces_value = NULL;
  if (!dict->GetWithoutPathExpansion("interfaces", &interfaces_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!interfaces_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->interfaces)) {
        return false;
      }
    }
  }

  const base::Value* extra_data_value = NULL;
  if (!dict->GetWithoutPathExpansion("extra_data", &extra_data_value)) {
    return false;
  }
  {
    if (!extra_data_value->is_blob()) {
      return false;
    }
    else {
      out->extra_data = extra_data_value->GetBlob();
    }
  }

  return true;
}

// static
std::unique_ptr<ConfigDescriptor> ConfigDescriptor::FromValue(const base::Value& value) {
  std::unique_ptr<ConfigDescriptor> out(new ConfigDescriptor());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ConfigDescriptor::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("active", std::make_unique<base::Value>(this->active));

  to_value_result->SetWithoutPathExpansion("configurationValue", std::make_unique<base::Value>(this->configuration_value));

  if (this->description.get()) {
    to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(*this->description));

  }
  to_value_result->SetWithoutPathExpansion("selfPowered", std::make_unique<base::Value>(this->self_powered));

  to_value_result->SetWithoutPathExpansion("remoteWakeup", std::make_unique<base::Value>(this->remote_wakeup));

  to_value_result->SetWithoutPathExpansion("maxPower", std::make_unique<base::Value>(this->max_power));

  to_value_result->SetWithoutPathExpansion("interfaces", json_schema_compiler::util::CreateValueFromArray(this->interfaces));

  to_value_result->SetWithoutPathExpansion("extra_data", std::make_unique<base::Value>(this->extra_data));


  return to_value_result;
}


ControlTransferInfo::ControlTransferInfo()
: direction(DIRECTION_NONE),
recipient(RECIPIENT_NONE),
request_type(REQUEST_TYPE_NONE),
request(0),
value(0),
index(0) {}

ControlTransferInfo::~ControlTransferInfo() {}
ControlTransferInfo::ControlTransferInfo(ControlTransferInfo&& rhs)
: direction(rhs.direction),
recipient(rhs.recipient),
request_type(rhs.request_type),
request(rhs.request),
value(rhs.value),
index(rhs.index),
length(std::move(rhs.length)),
data(std::move(rhs.data)),
timeout(std::move(rhs.timeout)){
}

ControlTransferInfo& ControlTransferInfo::operator=(ControlTransferInfo&& rhs)
{
direction = rhs.direction;
recipient = rhs.recipient;
request_type = rhs.request_type;
request = rhs.request;
value = rhs.value;
index = rhs.index;
length = std::move(rhs.length);
data = std::move(rhs.data);
timeout = std::move(rhs.timeout);
return *this;
}

// static
bool ControlTransferInfo::Populate(
    const base::Value& value, ControlTransferInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* direction_value = NULL;
  if (!dict->GetWithoutPathExpansion("direction", &direction_value)) {
    return false;
  }
  {
    std::string direction_as_string;
    if (!direction_value->GetAsString(&direction_as_string)) {
      return false;
    }
    out->direction = ParseDirection(direction_as_string);
    if (out->direction == DIRECTION_NONE) {
      return false;
    }
  }

  const base::Value* recipient_value = NULL;
  if (!dict->GetWithoutPathExpansion("recipient", &recipient_value)) {
    return false;
  }
  {
    std::string recipient_as_string;
    if (!recipient_value->GetAsString(&recipient_as_string)) {
      return false;
    }
    out->recipient = ParseRecipient(recipient_as_string);
    if (out->recipient == RECIPIENT_NONE) {
      return false;
    }
  }

  const base::Value* request_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("requestType", &request_type_value)) {
    return false;
  }
  {
    std::string request_type_as_string;
    if (!request_type_value->GetAsString(&request_type_as_string)) {
      return false;
    }
    out->request_type = ParseRequestType(request_type_as_string);
    if (out->request_type == REQUEST_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* request_value = NULL;
  if (!dict->GetWithoutPathExpansion("request", &request_value)) {
    return false;
  }
  {
    if (!request_value->GetAsInteger(&out->request)) {
      return false;
    }
  }

  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    return false;
  }
  {
    if (!value_value->GetAsInteger(&out->value)) {
      return false;
    }
  }

  const base::Value* index_value = NULL;
  if (!dict->GetWithoutPathExpansion("index", &index_value)) {
    return false;
  }
  {
    if (!index_value->GetAsInteger(&out->index)) {
      return false;
    }
  }

  const base::Value* length_value = NULL;
  if (dict->GetWithoutPathExpansion("length", &length_value)) {
    {
      int temp;
      if (!length_value->GetAsInteger(&temp)) {
        out->length.reset();
        return false;
      }
      else
        out->length.reset(new int(temp));
    }
  }

  const base::Value* data_value = NULL;
  if (dict->GetWithoutPathExpansion("data", &data_value)) {
    {
      if (!data_value->is_blob()) {
        return false;
      }
      else {
        out->data.reset(new std::vector<uint8_t>(data_value->GetBlob()));
      }
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

  return true;
}

// static
std::unique_ptr<ControlTransferInfo> ControlTransferInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ControlTransferInfo> out(new ControlTransferInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ControlTransferInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("direction", std::make_unique<base::Value>(usb::ToString(this->direction)));

  to_value_result->SetWithoutPathExpansion("recipient", std::make_unique<base::Value>(usb::ToString(this->recipient)));

  to_value_result->SetWithoutPathExpansion("requestType", std::make_unique<base::Value>(usb::ToString(this->request_type)));

  to_value_result->SetWithoutPathExpansion("request", std::make_unique<base::Value>(this->request));

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));

  to_value_result->SetWithoutPathExpansion("index", std::make_unique<base::Value>(this->index));

  if (this->length.get()) {
    to_value_result->SetWithoutPathExpansion("length", std::make_unique<base::Value>(*this->length));

  }
  if (this->data.get()) {
    to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(*this->data));

  }
  if (this->timeout.get()) {
    to_value_result->SetWithoutPathExpansion("timeout", std::make_unique<base::Value>(*this->timeout));

  }

  return to_value_result;
}


GenericTransferInfo::GenericTransferInfo()
: direction(DIRECTION_NONE),
endpoint(0) {}

GenericTransferInfo::~GenericTransferInfo() {}
GenericTransferInfo::GenericTransferInfo(GenericTransferInfo&& rhs)
: direction(rhs.direction),
endpoint(rhs.endpoint),
length(std::move(rhs.length)),
data(std::move(rhs.data)),
timeout(std::move(rhs.timeout)){
}

GenericTransferInfo& GenericTransferInfo::operator=(GenericTransferInfo&& rhs)
{
direction = rhs.direction;
endpoint = rhs.endpoint;
length = std::move(rhs.length);
data = std::move(rhs.data);
timeout = std::move(rhs.timeout);
return *this;
}

// static
bool GenericTransferInfo::Populate(
    const base::Value& value, GenericTransferInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* direction_value = NULL;
  if (!dict->GetWithoutPathExpansion("direction", &direction_value)) {
    return false;
  }
  {
    std::string direction_as_string;
    if (!direction_value->GetAsString(&direction_as_string)) {
      return false;
    }
    out->direction = ParseDirection(direction_as_string);
    if (out->direction == DIRECTION_NONE) {
      return false;
    }
  }

  const base::Value* endpoint_value = NULL;
  if (!dict->GetWithoutPathExpansion("endpoint", &endpoint_value)) {
    return false;
  }
  {
    if (!endpoint_value->GetAsInteger(&out->endpoint)) {
      return false;
    }
  }

  const base::Value* length_value = NULL;
  if (dict->GetWithoutPathExpansion("length", &length_value)) {
    {
      int temp;
      if (!length_value->GetAsInteger(&temp)) {
        out->length.reset();
        return false;
      }
      else
        out->length.reset(new int(temp));
    }
  }

  const base::Value* data_value = NULL;
  if (dict->GetWithoutPathExpansion("data", &data_value)) {
    {
      if (!data_value->is_blob()) {
        return false;
      }
      else {
        out->data.reset(new std::vector<uint8_t>(data_value->GetBlob()));
      }
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

  return true;
}

// static
std::unique_ptr<GenericTransferInfo> GenericTransferInfo::FromValue(const base::Value& value) {
  std::unique_ptr<GenericTransferInfo> out(new GenericTransferInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GenericTransferInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("direction", std::make_unique<base::Value>(usb::ToString(this->direction)));

  to_value_result->SetWithoutPathExpansion("endpoint", std::make_unique<base::Value>(this->endpoint));

  if (this->length.get()) {
    to_value_result->SetWithoutPathExpansion("length", std::make_unique<base::Value>(*this->length));

  }
  if (this->data.get()) {
    to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(*this->data));

  }
  if (this->timeout.get()) {
    to_value_result->SetWithoutPathExpansion("timeout", std::make_unique<base::Value>(*this->timeout));

  }

  return to_value_result;
}


IsochronousTransferInfo::IsochronousTransferInfo()
: packets(0),
packet_length(0) {}

IsochronousTransferInfo::~IsochronousTransferInfo() {}
IsochronousTransferInfo::IsochronousTransferInfo(IsochronousTransferInfo&& rhs)
: transfer_info(std::move(rhs.transfer_info)),
packets(rhs.packets),
packet_length(rhs.packet_length){
}

IsochronousTransferInfo& IsochronousTransferInfo::operator=(IsochronousTransferInfo&& rhs)
{
transfer_info = std::move(rhs.transfer_info);
packets = rhs.packets;
packet_length = rhs.packet_length;
return *this;
}

// static
bool IsochronousTransferInfo::Populate(
    const base::Value& value, IsochronousTransferInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* transfer_info_value = NULL;
  if (!dict->GetWithoutPathExpansion("transferInfo", &transfer_info_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!transfer_info_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!GenericTransferInfo::Populate(*dictionary, &out->transfer_info)) {
      return false;
    }
  }

  const base::Value* packets_value = NULL;
  if (!dict->GetWithoutPathExpansion("packets", &packets_value)) {
    return false;
  }
  {
    if (!packets_value->GetAsInteger(&out->packets)) {
      return false;
    }
  }

  const base::Value* packet_length_value = NULL;
  if (!dict->GetWithoutPathExpansion("packetLength", &packet_length_value)) {
    return false;
  }
  {
    if (!packet_length_value->GetAsInteger(&out->packet_length)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<IsochronousTransferInfo> IsochronousTransferInfo::FromValue(const base::Value& value) {
  std::unique_ptr<IsochronousTransferInfo> out(new IsochronousTransferInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> IsochronousTransferInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("transferInfo", (this->transfer_info).ToValue());

  to_value_result->SetWithoutPathExpansion("packets", std::make_unique<base::Value>(this->packets));

  to_value_result->SetWithoutPathExpansion("packetLength", std::make_unique<base::Value>(this->packet_length));


  return to_value_result;
}


TransferResultInfo::TransferResultInfo()
 {}

TransferResultInfo::~TransferResultInfo() {}
TransferResultInfo::TransferResultInfo(TransferResultInfo&& rhs)
: result_code(std::move(rhs.result_code)),
data(std::move(rhs.data)){
}

TransferResultInfo& TransferResultInfo::operator=(TransferResultInfo&& rhs)
{
result_code = std::move(rhs.result_code);
data = std::move(rhs.data);
return *this;
}

// static
bool TransferResultInfo::Populate(
    const base::Value& value, TransferResultInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* result_code_value = NULL;
  if (dict->GetWithoutPathExpansion("resultCode", &result_code_value)) {
    {
      int temp;
      if (!result_code_value->GetAsInteger(&temp)) {
        out->result_code.reset();
        return false;
      }
      else
        out->result_code.reset(new int(temp));
    }
  }

  const base::Value* data_value = NULL;
  if (dict->GetWithoutPathExpansion("data", &data_value)) {
    {
      if (!data_value->is_blob()) {
        return false;
      }
      else {
        out->data.reset(new std::vector<uint8_t>(data_value->GetBlob()));
      }
    }
  }

  return true;
}

// static
std::unique_ptr<TransferResultInfo> TransferResultInfo::FromValue(const base::Value& value) {
  std::unique_ptr<TransferResultInfo> out(new TransferResultInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TransferResultInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->result_code.get()) {
    to_value_result->SetWithoutPathExpansion("resultCode", std::make_unique<base::Value>(*this->result_code));

  }
  if (this->data.get()) {
    to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(*this->data));

  }

  return to_value_result;
}


DeviceFilter::DeviceFilter()
 {}

DeviceFilter::~DeviceFilter() {}
DeviceFilter::DeviceFilter(DeviceFilter&& rhs)
: vendor_id(std::move(rhs.vendor_id)),
product_id(std::move(rhs.product_id)),
interface_class(std::move(rhs.interface_class)),
interface_subclass(std::move(rhs.interface_subclass)),
interface_protocol(std::move(rhs.interface_protocol)){
}

DeviceFilter& DeviceFilter::operator=(DeviceFilter&& rhs)
{
vendor_id = std::move(rhs.vendor_id);
product_id = std::move(rhs.product_id);
interface_class = std::move(rhs.interface_class);
interface_subclass = std::move(rhs.interface_subclass);
interface_protocol = std::move(rhs.interface_protocol);
return *this;
}

// static
bool DeviceFilter::Populate(
    const base::Value& value, DeviceFilter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* interface_class_value = NULL;
  if (dict->GetWithoutPathExpansion("interfaceClass", &interface_class_value)) {
    {
      int temp;
      if (!interface_class_value->GetAsInteger(&temp)) {
        out->interface_class.reset();
        return false;
      }
      else
        out->interface_class.reset(new int(temp));
    }
  }

  const base::Value* interface_subclass_value = NULL;
  if (dict->GetWithoutPathExpansion("interfaceSubclass", &interface_subclass_value)) {
    {
      int temp;
      if (!interface_subclass_value->GetAsInteger(&temp)) {
        out->interface_subclass.reset();
        return false;
      }
      else
        out->interface_subclass.reset(new int(temp));
    }
  }

  const base::Value* interface_protocol_value = NULL;
  if (dict->GetWithoutPathExpansion("interfaceProtocol", &interface_protocol_value)) {
    {
      int temp;
      if (!interface_protocol_value->GetAsInteger(&temp)) {
        out->interface_protocol.reset();
        return false;
      }
      else
        out->interface_protocol.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceFilter> DeviceFilter::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceFilter> out(new DeviceFilter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->vendor_id.get()) {
    to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(*this->vendor_id));

  }
  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->interface_class.get()) {
    to_value_result->SetWithoutPathExpansion("interfaceClass", std::make_unique<base::Value>(*this->interface_class));

  }
  if (this->interface_subclass.get()) {
    to_value_result->SetWithoutPathExpansion("interfaceSubclass", std::make_unique<base::Value>(*this->interface_subclass));

  }
  if (this->interface_protocol.get()) {
    to_value_result->SetWithoutPathExpansion("interfaceProtocol", std::make_unique<base::Value>(*this->interface_protocol));

  }

  return to_value_result;
}


EnumerateDevicesOptions::EnumerateDevicesOptions()
 {}

EnumerateDevicesOptions::~EnumerateDevicesOptions() {}
EnumerateDevicesOptions::EnumerateDevicesOptions(EnumerateDevicesOptions&& rhs)
: vendor_id(std::move(rhs.vendor_id)),
product_id(std::move(rhs.product_id)),
filters(std::move(rhs.filters)){
}

EnumerateDevicesOptions& EnumerateDevicesOptions::operator=(EnumerateDevicesOptions&& rhs)
{
vendor_id = std::move(rhs.vendor_id);
product_id = std::move(rhs.product_id);
filters = std::move(rhs.filters);
return *this;
}

// static
bool EnumerateDevicesOptions::Populate(
    const base::Value& value, EnumerateDevicesOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* filters_value = NULL;
  if (dict->GetWithoutPathExpansion("filters", &filters_value)) {
    {
      const base::ListValue* list = NULL;
      if (!filters_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->filters)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<EnumerateDevicesOptions> EnumerateDevicesOptions::FromValue(const base::Value& value) {
  std::unique_ptr<EnumerateDevicesOptions> out(new EnumerateDevicesOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EnumerateDevicesOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->vendor_id.get()) {
    to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(*this->vendor_id));

  }
  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->filters.get()) {
    to_value_result->SetWithoutPathExpansion("filters", json_schema_compiler::util::CreateValueFromOptionalArray(this->filters));

  }

  return to_value_result;
}


EnumerateDevicesAndRequestAccessOptions::EnumerateDevicesAndRequestAccessOptions()
: vendor_id(0),
product_id(0) {}

EnumerateDevicesAndRequestAccessOptions::~EnumerateDevicesAndRequestAccessOptions() {}
EnumerateDevicesAndRequestAccessOptions::EnumerateDevicesAndRequestAccessOptions(EnumerateDevicesAndRequestAccessOptions&& rhs)
: vendor_id(rhs.vendor_id),
product_id(rhs.product_id),
interface_id(std::move(rhs.interface_id)){
}

EnumerateDevicesAndRequestAccessOptions& EnumerateDevicesAndRequestAccessOptions::operator=(EnumerateDevicesAndRequestAccessOptions&& rhs)
{
vendor_id = rhs.vendor_id;
product_id = rhs.product_id;
interface_id = std::move(rhs.interface_id);
return *this;
}

// static
bool EnumerateDevicesAndRequestAccessOptions::Populate(
    const base::Value& value, EnumerateDevicesAndRequestAccessOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* vendor_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    return false;
  }
  {
    if (!vendor_id_value->GetAsInteger(&out->vendor_id)) {
      return false;
    }
  }

  const base::Value* product_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    return false;
  }
  {
    if (!product_id_value->GetAsInteger(&out->product_id)) {
      return false;
    }
  }

  const base::Value* interface_id_value = NULL;
  if (dict->GetWithoutPathExpansion("interfaceId", &interface_id_value)) {
    {
      int temp;
      if (!interface_id_value->GetAsInteger(&temp)) {
        out->interface_id.reset();
        return false;
      }
      else
        out->interface_id.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<EnumerateDevicesAndRequestAccessOptions> EnumerateDevicesAndRequestAccessOptions::FromValue(const base::Value& value) {
  std::unique_ptr<EnumerateDevicesAndRequestAccessOptions> out(new EnumerateDevicesAndRequestAccessOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EnumerateDevicesAndRequestAccessOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(this->vendor_id));

  to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(this->product_id));

  if (this->interface_id.get()) {
    to_value_result->SetWithoutPathExpansion("interfaceId", std::make_unique<base::Value>(*this->interface_id));

  }

  return to_value_result;
}


DevicePromptOptions::DevicePromptOptions()
 {}

DevicePromptOptions::~DevicePromptOptions() {}
DevicePromptOptions::DevicePromptOptions(DevicePromptOptions&& rhs)
: multiple(std::move(rhs.multiple)),
filters(std::move(rhs.filters)){
}

DevicePromptOptions& DevicePromptOptions::operator=(DevicePromptOptions&& rhs)
{
multiple = std::move(rhs.multiple);
filters = std::move(rhs.filters);
return *this;
}

// static
bool DevicePromptOptions::Populate(
    const base::Value& value, DevicePromptOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* multiple_value = NULL;
  if (dict->GetWithoutPathExpansion("multiple", &multiple_value)) {
    {
      bool temp;
      if (!multiple_value->GetAsBoolean(&temp)) {
        out->multiple.reset();
        return false;
      }
      else
        out->multiple.reset(new bool(temp));
    }
  }

  const base::Value* filters_value = NULL;
  if (dict->GetWithoutPathExpansion("filters", &filters_value)) {
    {
      const base::ListValue* list = NULL;
      if (!filters_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->filters)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<DevicePromptOptions> DevicePromptOptions::FromValue(const base::Value& value) {
  std::unique_ptr<DevicePromptOptions> out(new DevicePromptOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DevicePromptOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->multiple.get()) {
    to_value_result->SetWithoutPathExpansion("multiple", std::make_unique<base::Value>(*this->multiple));

  }
  if (this->filters.get()) {
    to_value_result->SetWithoutPathExpansion("filters", json_schema_compiler::util::CreateValueFromOptionalArray(this->filters));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetDevices {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!EnumerateDevicesOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Device>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace GetDevices

namespace GetUserSelectedDevices {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DevicePromptOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Device>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace GetUserSelectedDevices

namespace GetConfigurations {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_value = NULL;
  if (args.Get(0, &device_value) &&
      !device_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!device_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Device::Populate(*dictionary, &params->device)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<ConfigDescriptor>& configs) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(configs));

  return create_results;
}
}  // namespace GetConfigurations

namespace RequestAccess {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_value = NULL;
  if (args.Get(0, &device_value) &&
      !device_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!device_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Device::Populate(*dictionary, &params->device)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* interface_id_value = NULL;
  if (args.Get(1, &interface_id_value) &&
      !interface_id_value->is_none()) {
    {
      if (!interface_id_value->GetAsInteger(&params->interface_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace RequestAccess

namespace OpenDevice {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_value = NULL;
  if (args.Get(0, &device_value) &&
      !device_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!device_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Device::Populate(*dictionary, &params->device)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ConnectionHandle& handle) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((handle).ToValue());

  return create_results;
}
}  // namespace OpenDevice

namespace FindDevices {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!EnumerateDevicesAndRequestAccessOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<ConnectionHandle>& handles) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(handles));

  return create_results;
}
}  // namespace FindDevices

namespace CloseDevice {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
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
}  // namespace CloseDevice

namespace SetConfiguration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* configuration_value_value = NULL;
  if (args.Get(1, &configuration_value_value) &&
      !configuration_value_value->is_none()) {
    {
      if (!configuration_value_value->GetAsInteger(&params->configuration_value)) {
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
}  // namespace SetConfiguration

namespace GetConfiguration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ConfigDescriptor& config) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((config).ToValue());

  return create_results;
}
}  // namespace GetConfiguration

namespace ListInterfaces {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<InterfaceDescriptor>& descriptors) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(descriptors));

  return create_results;
}
}  // namespace ListInterfaces

namespace ClaimInterface {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* interface_number_value = NULL;
  if (args.Get(1, &interface_number_value) &&
      !interface_number_value->is_none()) {
    {
      if (!interface_number_value->GetAsInteger(&params->interface_number)) {
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
}  // namespace ClaimInterface

namespace ReleaseInterface {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* interface_number_value = NULL;
  if (args.Get(1, &interface_number_value) &&
      !interface_number_value->is_none()) {
    {
      if (!interface_number_value->GetAsInteger(&params->interface_number)) {
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
}  // namespace ReleaseInterface

namespace SetInterfaceAlternateSetting {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* interface_number_value = NULL;
  if (args.Get(1, &interface_number_value) &&
      !interface_number_value->is_none()) {
    {
      if (!interface_number_value->GetAsInteger(&params->interface_number)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* alternate_setting_value = NULL;
  if (args.Get(2, &alternate_setting_value) &&
      !alternate_setting_value->is_none()) {
    {
      if (!alternate_setting_value->GetAsInteger(&params->alternate_setting)) {
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
}  // namespace SetInterfaceAlternateSetting

namespace ControlTransfer {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* transfer_info_value = NULL;
  if (args.Get(1, &transfer_info_value) &&
      !transfer_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!transfer_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ControlTransferInfo::Populate(*dictionary, &params->transfer_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const TransferResultInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace ControlTransfer

namespace BulkTransfer {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* transfer_info_value = NULL;
  if (args.Get(1, &transfer_info_value) &&
      !transfer_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!transfer_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!GenericTransferInfo::Populate(*dictionary, &params->transfer_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const TransferResultInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace BulkTransfer

namespace InterruptTransfer {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* transfer_info_value = NULL;
  if (args.Get(1, &transfer_info_value) &&
      !transfer_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!transfer_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!GenericTransferInfo::Populate(*dictionary, &params->transfer_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const TransferResultInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace InterruptTransfer

namespace IsochronousTransfer {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* transfer_info_value = NULL;
  if (args.Get(1, &transfer_info_value) &&
      !transfer_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!transfer_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!IsochronousTransferInfo::Populate(*dictionary, &params->transfer_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const TransferResultInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace IsochronousTransfer

namespace ResetDevice {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* handle_value = NULL;
  if (args.Get(0, &handle_value) &&
      !handle_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!handle_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ConnectionHandle::Populate(*dictionary, &params->handle)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace ResetDevice

//
// Events
//

namespace OnDeviceAdded {

const char kEventName[] = "usb.onDeviceAdded";

std::unique_ptr<base::ListValue> Create(const Device& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceAdded

namespace OnDeviceRemoved {

const char kEventName[] = "usb.onDeviceRemoved";

std::unique_ptr<base::ListValue> Create(const Device& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceRemoved

}  // namespace usb
}  // namespace api
}  // namespace extensions

