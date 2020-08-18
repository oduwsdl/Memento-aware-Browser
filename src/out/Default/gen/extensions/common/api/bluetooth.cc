// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/bluetooth.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/bluetooth.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace bluetooth {
//
// Types
//

const char* ToString(VendorIdSource enum_param) {
  switch (enum_param) {
    case VENDOR_ID_SOURCE_BLUETOOTH:
      return "bluetooth";
    case VENDOR_ID_SOURCE_USB:
      return "usb";
    case VENDOR_ID_SOURCE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

VendorIdSource ParseVendorIdSource(const std::string& enum_string) {
  if (enum_string == "bluetooth")
    return VENDOR_ID_SOURCE_BLUETOOTH;
  if (enum_string == "usb")
    return VENDOR_ID_SOURCE_USB;
  return VENDOR_ID_SOURCE_NONE;
}


const char* ToString(DeviceType enum_param) {
  switch (enum_param) {
    case DEVICE_TYPE_COMPUTER:
      return "computer";
    case DEVICE_TYPE_PHONE:
      return "phone";
    case DEVICE_TYPE_MODEM:
      return "modem";
    case DEVICE_TYPE_AUDIO:
      return "audio";
    case DEVICE_TYPE_CARAUDIO:
      return "carAudio";
    case DEVICE_TYPE_VIDEO:
      return "video";
    case DEVICE_TYPE_PERIPHERAL:
      return "peripheral";
    case DEVICE_TYPE_JOYSTICK:
      return "joystick";
    case DEVICE_TYPE_GAMEPAD:
      return "gamepad";
    case DEVICE_TYPE_KEYBOARD:
      return "keyboard";
    case DEVICE_TYPE_MOUSE:
      return "mouse";
    case DEVICE_TYPE_TABLET:
      return "tablet";
    case DEVICE_TYPE_KEYBOARDMOUSECOMBO:
      return "keyboardMouseCombo";
    case DEVICE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DeviceType ParseDeviceType(const std::string& enum_string) {
  if (enum_string == "computer")
    return DEVICE_TYPE_COMPUTER;
  if (enum_string == "phone")
    return DEVICE_TYPE_PHONE;
  if (enum_string == "modem")
    return DEVICE_TYPE_MODEM;
  if (enum_string == "audio")
    return DEVICE_TYPE_AUDIO;
  if (enum_string == "carAudio")
    return DEVICE_TYPE_CARAUDIO;
  if (enum_string == "video")
    return DEVICE_TYPE_VIDEO;
  if (enum_string == "peripheral")
    return DEVICE_TYPE_PERIPHERAL;
  if (enum_string == "joystick")
    return DEVICE_TYPE_JOYSTICK;
  if (enum_string == "gamepad")
    return DEVICE_TYPE_GAMEPAD;
  if (enum_string == "keyboard")
    return DEVICE_TYPE_KEYBOARD;
  if (enum_string == "mouse")
    return DEVICE_TYPE_MOUSE;
  if (enum_string == "tablet")
    return DEVICE_TYPE_TABLET;
  if (enum_string == "keyboardMouseCombo")
    return DEVICE_TYPE_KEYBOARDMOUSECOMBO;
  return DEVICE_TYPE_NONE;
}


const char* ToString(FilterType enum_param) {
  switch (enum_param) {
    case FILTER_TYPE_ALL:
      return "all";
    case FILTER_TYPE_KNOWN:
      return "known";
    case FILTER_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FilterType ParseFilterType(const std::string& enum_string) {
  if (enum_string == "all")
    return FILTER_TYPE_ALL;
  if (enum_string == "known")
    return FILTER_TYPE_KNOWN;
  return FILTER_TYPE_NONE;
}


const char* ToString(Transport enum_param) {
  switch (enum_param) {
    case TRANSPORT_INVALID:
      return "invalid";
    case TRANSPORT_CLASSIC:
      return "classic";
    case TRANSPORT_LE:
      return "le";
    case TRANSPORT_DUAL:
      return "dual";
    case TRANSPORT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Transport ParseTransport(const std::string& enum_string) {
  if (enum_string == "invalid")
    return TRANSPORT_INVALID;
  if (enum_string == "classic")
    return TRANSPORT_CLASSIC;
  if (enum_string == "le")
    return TRANSPORT_LE;
  if (enum_string == "dual")
    return TRANSPORT_DUAL;
  return TRANSPORT_NONE;
}


AdapterState::AdapterState()
: powered(false),
available(false),
discovering(false) {}

AdapterState::~AdapterState() {}
AdapterState::AdapterState(AdapterState&& rhs)
: address(std::move(rhs.address)),
name(std::move(rhs.name)),
powered(rhs.powered),
available(rhs.available),
discovering(rhs.discovering){
}

AdapterState& AdapterState::operator=(AdapterState&& rhs)
{
address = std::move(rhs.address);
name = std::move(rhs.name);
powered = rhs.powered;
available = rhs.available;
discovering = rhs.discovering;
return *this;
}

// static
bool AdapterState::Populate(
    const base::Value& value, AdapterState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* address_value = NULL;
  if (!dict->GetWithoutPathExpansion("address", &address_value)) {
    return false;
  }
  {
    if (!address_value->GetAsString(&out->address)) {
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

  const base::Value* powered_value = NULL;
  if (!dict->GetWithoutPathExpansion("powered", &powered_value)) {
    return false;
  }
  {
    if (!powered_value->GetAsBoolean(&out->powered)) {
      return false;
    }
  }

  const base::Value* available_value = NULL;
  if (!dict->GetWithoutPathExpansion("available", &available_value)) {
    return false;
  }
  {
    if (!available_value->GetAsBoolean(&out->available)) {
      return false;
    }
  }

  const base::Value* discovering_value = NULL;
  if (!dict->GetWithoutPathExpansion("discovering", &discovering_value)) {
    return false;
  }
  {
    if (!discovering_value->GetAsBoolean(&out->discovering)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AdapterState> AdapterState::FromValue(const base::Value& value) {
  std::unique_ptr<AdapterState> out(new AdapterState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AdapterState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(this->address));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("powered", std::make_unique<base::Value>(this->powered));

  to_value_result->SetWithoutPathExpansion("available", std::make_unique<base::Value>(this->available));

  to_value_result->SetWithoutPathExpansion("discovering", std::make_unique<base::Value>(this->discovering));


  return to_value_result;
}


Device::Device()
: vendor_id_source(VENDOR_ID_SOURCE_NONE),
type(DEVICE_TYPE_NONE),
transport(TRANSPORT_NONE) {}

Device::~Device() {}
Device::Device(Device&& rhs)
: address(std::move(rhs.address)),
name(std::move(rhs.name)),
device_class(std::move(rhs.device_class)),
vendor_id_source(rhs.vendor_id_source),
vendor_id(std::move(rhs.vendor_id)),
product_id(std::move(rhs.product_id)),
device_id(std::move(rhs.device_id)),
type(rhs.type),
paired(std::move(rhs.paired)),
connected(std::move(rhs.connected)),
connecting(std::move(rhs.connecting)),
connectable(std::move(rhs.connectable)),
uuids(std::move(rhs.uuids)),
inquiry_rssi(std::move(rhs.inquiry_rssi)),
inquiry_tx_power(std::move(rhs.inquiry_tx_power)),
transport(rhs.transport),
battery_percentage(std::move(rhs.battery_percentage)){
}

Device& Device::operator=(Device&& rhs)
{
address = std::move(rhs.address);
name = std::move(rhs.name);
device_class = std::move(rhs.device_class);
vendor_id_source = rhs.vendor_id_source;
vendor_id = std::move(rhs.vendor_id);
product_id = std::move(rhs.product_id);
device_id = std::move(rhs.device_id);
type = rhs.type;
paired = std::move(rhs.paired);
connected = std::move(rhs.connected);
connecting = std::move(rhs.connecting);
connectable = std::move(rhs.connectable);
uuids = std::move(rhs.uuids);
inquiry_rssi = std::move(rhs.inquiry_rssi);
inquiry_tx_power = std::move(rhs.inquiry_tx_power);
transport = rhs.transport;
battery_percentage = std::move(rhs.battery_percentage);
return *this;
}

// static
bool Device::Populate(
    const base::Value& value, Device* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->vendor_id_source = VENDOR_ID_SOURCE_NONE;
  out->type = DEVICE_TYPE_NONE;
  out->transport = TRANSPORT_NONE;
  const base::Value* address_value = NULL;
  if (!dict->GetWithoutPathExpansion("address", &address_value)) {
    return false;
  }
  {
    if (!address_value->GetAsString(&out->address)) {
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

  const base::Value* device_class_value = NULL;
  if (dict->GetWithoutPathExpansion("deviceClass", &device_class_value)) {
    {
      int temp;
      if (!device_class_value->GetAsInteger(&temp)) {
        out->device_class.reset();
        return false;
      }
      else
        out->device_class.reset(new int(temp));
    }
  }

  const base::Value* vendor_id_source_value = NULL;
  if (dict->GetWithoutPathExpansion("vendorIdSource", &vendor_id_source_value)) {
    {
      std::string vendor_id_source_as_string;
      if (!vendor_id_source_value->GetAsString(&vendor_id_source_as_string)) {
        return false;
      }
      out->vendor_id_source = ParseVendorIdSource(vendor_id_source_as_string);
      if (out->vendor_id_source == VENDOR_ID_SOURCE_NONE) {
        return false;
      }
    }
    } else {
    out->vendor_id_source = VENDOR_ID_SOURCE_NONE;
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

  const base::Value* device_id_value = NULL;
  if (dict->GetWithoutPathExpansion("deviceId", &device_id_value)) {
    {
      int temp;
      if (!device_id_value->GetAsInteger(&temp)) {
        out->device_id.reset();
        return false;
      }
      else
        out->device_id.reset(new int(temp));
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string device_type_as_string;
      if (!type_value->GetAsString(&device_type_as_string)) {
        return false;
      }
      out->type = ParseDeviceType(device_type_as_string);
      if (out->type == DEVICE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = DEVICE_TYPE_NONE;
  }

  const base::Value* paired_value = NULL;
  if (dict->GetWithoutPathExpansion("paired", &paired_value)) {
    {
      bool temp;
      if (!paired_value->GetAsBoolean(&temp)) {
        out->paired.reset();
        return false;
      }
      else
        out->paired.reset(new bool(temp));
    }
  }

  const base::Value* connected_value = NULL;
  if (dict->GetWithoutPathExpansion("connected", &connected_value)) {
    {
      bool temp;
      if (!connected_value->GetAsBoolean(&temp)) {
        out->connected.reset();
        return false;
      }
      else
        out->connected.reset(new bool(temp));
    }
  }

  const base::Value* connecting_value = NULL;
  if (dict->GetWithoutPathExpansion("connecting", &connecting_value)) {
    {
      bool temp;
      if (!connecting_value->GetAsBoolean(&temp)) {
        out->connecting.reset();
        return false;
      }
      else
        out->connecting.reset(new bool(temp));
    }
  }

  const base::Value* connectable_value = NULL;
  if (dict->GetWithoutPathExpansion("connectable", &connectable_value)) {
    {
      bool temp;
      if (!connectable_value->GetAsBoolean(&temp)) {
        out->connectable.reset();
        return false;
      }
      else
        out->connectable.reset(new bool(temp));
    }
  }

  const base::Value* uuids_value = NULL;
  if (dict->GetWithoutPathExpansion("uuids", &uuids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!uuids_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->uuids)) {
          return false;
        }
      }
    }
  }

  const base::Value* inquiry_rssi_value = NULL;
  if (dict->GetWithoutPathExpansion("inquiryRssi", &inquiry_rssi_value)) {
    {
      int temp;
      if (!inquiry_rssi_value->GetAsInteger(&temp)) {
        out->inquiry_rssi.reset();
        return false;
      }
      else
        out->inquiry_rssi.reset(new int(temp));
    }
  }

  const base::Value* inquiry_tx_power_value = NULL;
  if (dict->GetWithoutPathExpansion("inquiryTxPower", &inquiry_tx_power_value)) {
    {
      int temp;
      if (!inquiry_tx_power_value->GetAsInteger(&temp)) {
        out->inquiry_tx_power.reset();
        return false;
      }
      else
        out->inquiry_tx_power.reset(new int(temp));
    }
  }

  const base::Value* transport_value = NULL;
  if (dict->GetWithoutPathExpansion("transport", &transport_value)) {
    {
      std::string transport_as_string;
      if (!transport_value->GetAsString(&transport_as_string)) {
        return false;
      }
      out->transport = ParseTransport(transport_as_string);
      if (out->transport == TRANSPORT_NONE) {
        return false;
      }
    }
    } else {
    out->transport = TRANSPORT_NONE;
  }

  const base::Value* battery_percentage_value = NULL;
  if (dict->GetWithoutPathExpansion("batteryPercentage", &battery_percentage_value)) {
    {
      int temp;
      if (!battery_percentage_value->GetAsInteger(&temp)) {
        out->battery_percentage.reset();
        return false;
      }
      else
        out->battery_percentage.reset(new int(temp));
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

  to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(this->address));

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(*this->name));

  }
  if (this->device_class.get()) {
    to_value_result->SetWithoutPathExpansion("deviceClass", std::make_unique<base::Value>(*this->device_class));

  }
  if (this->vendor_id_source != VENDOR_ID_SOURCE_NONE) {
    to_value_result->SetWithoutPathExpansion("vendorIdSource", std::make_unique<base::Value>(bluetooth::ToString(this->vendor_id_source)));

  }
  if (this->vendor_id.get()) {
    to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(*this->vendor_id));

  }
  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->device_id.get()) {
    to_value_result->SetWithoutPathExpansion("deviceId", std::make_unique<base::Value>(*this->device_id));

  }
  if (this->type != DEVICE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(bluetooth::ToString(this->type)));

  }
  if (this->paired.get()) {
    to_value_result->SetWithoutPathExpansion("paired", std::make_unique<base::Value>(*this->paired));

  }
  if (this->connected.get()) {
    to_value_result->SetWithoutPathExpansion("connected", std::make_unique<base::Value>(*this->connected));

  }
  if (this->connecting.get()) {
    to_value_result->SetWithoutPathExpansion("connecting", std::make_unique<base::Value>(*this->connecting));

  }
  if (this->connectable.get()) {
    to_value_result->SetWithoutPathExpansion("connectable", std::make_unique<base::Value>(*this->connectable));

  }
  if (this->uuids.get()) {
    to_value_result->SetWithoutPathExpansion("uuids", json_schema_compiler::util::CreateValueFromOptionalArray(this->uuids));

  }
  if (this->inquiry_rssi.get()) {
    to_value_result->SetWithoutPathExpansion("inquiryRssi", std::make_unique<base::Value>(*this->inquiry_rssi));

  }
  if (this->inquiry_tx_power.get()) {
    to_value_result->SetWithoutPathExpansion("inquiryTxPower", std::make_unique<base::Value>(*this->inquiry_tx_power));

  }
  if (this->transport != TRANSPORT_NONE) {
    to_value_result->SetWithoutPathExpansion("transport", std::make_unique<base::Value>(bluetooth::ToString(this->transport)));

  }
  if (this->battery_percentage.get()) {
    to_value_result->SetWithoutPathExpansion("batteryPercentage", std::make_unique<base::Value>(*this->battery_percentage));

  }

  return to_value_result;
}


BluetoothFilter::BluetoothFilter()
: filter_type(FILTER_TYPE_NONE) {}

BluetoothFilter::~BluetoothFilter() {}
BluetoothFilter::BluetoothFilter(BluetoothFilter&& rhs)
: filter_type(rhs.filter_type),
limit(std::move(rhs.limit)){
}

BluetoothFilter& BluetoothFilter::operator=(BluetoothFilter&& rhs)
{
filter_type = rhs.filter_type;
limit = std::move(rhs.limit);
return *this;
}

// static
bool BluetoothFilter::Populate(
    const base::Value& value, BluetoothFilter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->filter_type = FILTER_TYPE_NONE;
  const base::Value* filter_type_value = NULL;
  if (dict->GetWithoutPathExpansion("filterType", &filter_type_value)) {
    {
      std::string filter_type_as_string;
      if (!filter_type_value->GetAsString(&filter_type_as_string)) {
        return false;
      }
      out->filter_type = ParseFilterType(filter_type_as_string);
      if (out->filter_type == FILTER_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->filter_type = FILTER_TYPE_NONE;
  }

  const base::Value* limit_value = NULL;
  if (dict->GetWithoutPathExpansion("limit", &limit_value)) {
    {
      int temp;
      if (!limit_value->GetAsInteger(&temp)) {
        out->limit.reset();
        return false;
      }
      else
        out->limit.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<BluetoothFilter> BluetoothFilter::FromValue(const base::Value& value) {
  std::unique_ptr<BluetoothFilter> out(new BluetoothFilter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> BluetoothFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->filter_type != FILTER_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("filterType", std::make_unique<base::Value>(bluetooth::ToString(this->filter_type)));

  }
  if (this->limit.get()) {
    to_value_result->SetWithoutPathExpansion("limit", std::make_unique<base::Value>(*this->limit));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetAdapterState {

std::unique_ptr<base::ListValue> Results::Create(const AdapterState& adapter_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((adapter_info).ToValue());

  return create_results;
}
}  // namespace GetAdapterState

namespace GetDevice {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_address_value = NULL;
  if (args.Get(0, &device_address_value) &&
      !device_address_value->is_none()) {
    {
      if (!device_address_value->GetAsString(&params->device_address)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Device& device_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device_info).ToValue());

  return create_results;
}
}  // namespace GetDevice

namespace GetDevices {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* filter_value = NULL;
  if (args.Get(0, &filter_value) &&
      !filter_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!filter_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<BluetoothFilter> temp(new BluetoothFilter());
        if (!BluetoothFilter::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->filter = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Device>& device_infos) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(device_infos));

  return create_results;
}
}  // namespace GetDevices

namespace StartDiscovery {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace StartDiscovery

namespace StopDiscovery {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace StopDiscovery

//
// Events
//

namespace OnAdapterStateChanged {

const char kEventName[] = "bluetooth.onAdapterStateChanged";

std::unique_ptr<base::ListValue> Create(const AdapterState& state) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((state).ToValue());

  return create_results;
}

}  // namespace OnAdapterStateChanged

namespace OnDeviceAdded {

const char kEventName[] = "bluetooth.onDeviceAdded";

std::unique_ptr<base::ListValue> Create(const Device& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceAdded

namespace OnDeviceChanged {

const char kEventName[] = "bluetooth.onDeviceChanged";

std::unique_ptr<base::ListValue> Create(const Device& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceChanged

namespace OnDeviceRemoved {

const char kEventName[] = "bluetooth.onDeviceRemoved";

std::unique_ptr<base::ListValue> Create(const Device& device) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  return create_results;
}

}  // namespace OnDeviceRemoved

}  // namespace bluetooth
}  // namespace api
}  // namespace extensions

