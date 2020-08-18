// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/bluetooth_low_energy.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/bluetooth_low_energy.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace bluetooth_low_energy {
//
// Types
//

const char* ToString(CharacteristicProperty enum_param) {
  switch (enum_param) {
    case CHARACTERISTIC_PROPERTY_BROADCAST:
      return "broadcast";
    case CHARACTERISTIC_PROPERTY_READ:
      return "read";
    case CHARACTERISTIC_PROPERTY_WRITEWITHOUTRESPONSE:
      return "writeWithoutResponse";
    case CHARACTERISTIC_PROPERTY_WRITE:
      return "write";
    case CHARACTERISTIC_PROPERTY_NOTIFY:
      return "notify";
    case CHARACTERISTIC_PROPERTY_INDICATE:
      return "indicate";
    case CHARACTERISTIC_PROPERTY_AUTHENTICATEDSIGNEDWRITES:
      return "authenticatedSignedWrites";
    case CHARACTERISTIC_PROPERTY_EXTENDEDPROPERTIES:
      return "extendedProperties";
    case CHARACTERISTIC_PROPERTY_RELIABLEWRITE:
      return "reliableWrite";
    case CHARACTERISTIC_PROPERTY_WRITABLEAUXILIARIES:
      return "writableAuxiliaries";
    case CHARACTERISTIC_PROPERTY_ENCRYPTREAD:
      return "encryptRead";
    case CHARACTERISTIC_PROPERTY_ENCRYPTWRITE:
      return "encryptWrite";
    case CHARACTERISTIC_PROPERTY_ENCRYPTAUTHENTICATEDREAD:
      return "encryptAuthenticatedRead";
    case CHARACTERISTIC_PROPERTY_ENCRYPTAUTHENTICATEDWRITE:
      return "encryptAuthenticatedWrite";
    case CHARACTERISTIC_PROPERTY_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CharacteristicProperty ParseCharacteristicProperty(const std::string& enum_string) {
  if (enum_string == "broadcast")
    return CHARACTERISTIC_PROPERTY_BROADCAST;
  if (enum_string == "read")
    return CHARACTERISTIC_PROPERTY_READ;
  if (enum_string == "writeWithoutResponse")
    return CHARACTERISTIC_PROPERTY_WRITEWITHOUTRESPONSE;
  if (enum_string == "write")
    return CHARACTERISTIC_PROPERTY_WRITE;
  if (enum_string == "notify")
    return CHARACTERISTIC_PROPERTY_NOTIFY;
  if (enum_string == "indicate")
    return CHARACTERISTIC_PROPERTY_INDICATE;
  if (enum_string == "authenticatedSignedWrites")
    return CHARACTERISTIC_PROPERTY_AUTHENTICATEDSIGNEDWRITES;
  if (enum_string == "extendedProperties")
    return CHARACTERISTIC_PROPERTY_EXTENDEDPROPERTIES;
  if (enum_string == "reliableWrite")
    return CHARACTERISTIC_PROPERTY_RELIABLEWRITE;
  if (enum_string == "writableAuxiliaries")
    return CHARACTERISTIC_PROPERTY_WRITABLEAUXILIARIES;
  if (enum_string == "encryptRead")
    return CHARACTERISTIC_PROPERTY_ENCRYPTREAD;
  if (enum_string == "encryptWrite")
    return CHARACTERISTIC_PROPERTY_ENCRYPTWRITE;
  if (enum_string == "encryptAuthenticatedRead")
    return CHARACTERISTIC_PROPERTY_ENCRYPTAUTHENTICATEDREAD;
  if (enum_string == "encryptAuthenticatedWrite")
    return CHARACTERISTIC_PROPERTY_ENCRYPTAUTHENTICATEDWRITE;
  return CHARACTERISTIC_PROPERTY_NONE;
}


const char* ToString(DescriptorPermission enum_param) {
  switch (enum_param) {
    case DESCRIPTOR_PERMISSION_READ:
      return "read";
    case DESCRIPTOR_PERMISSION_WRITE:
      return "write";
    case DESCRIPTOR_PERMISSION_ENCRYPTEDREAD:
      return "encryptedRead";
    case DESCRIPTOR_PERMISSION_ENCRYPTEDWRITE:
      return "encryptedWrite";
    case DESCRIPTOR_PERMISSION_ENCRYPTEDAUTHENTICATEDREAD:
      return "encryptedAuthenticatedRead";
    case DESCRIPTOR_PERMISSION_ENCRYPTEDAUTHENTICATEDWRITE:
      return "encryptedAuthenticatedWrite";
    case DESCRIPTOR_PERMISSION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DescriptorPermission ParseDescriptorPermission(const std::string& enum_string) {
  if (enum_string == "read")
    return DESCRIPTOR_PERMISSION_READ;
  if (enum_string == "write")
    return DESCRIPTOR_PERMISSION_WRITE;
  if (enum_string == "encryptedRead")
    return DESCRIPTOR_PERMISSION_ENCRYPTEDREAD;
  if (enum_string == "encryptedWrite")
    return DESCRIPTOR_PERMISSION_ENCRYPTEDWRITE;
  if (enum_string == "encryptedAuthenticatedRead")
    return DESCRIPTOR_PERMISSION_ENCRYPTEDAUTHENTICATEDREAD;
  if (enum_string == "encryptedAuthenticatedWrite")
    return DESCRIPTOR_PERMISSION_ENCRYPTEDAUTHENTICATEDWRITE;
  return DESCRIPTOR_PERMISSION_NONE;
}


const char* ToString(AdvertisementType enum_param) {
  switch (enum_param) {
    case ADVERTISEMENT_TYPE_BROADCAST:
      return "broadcast";
    case ADVERTISEMENT_TYPE_PERIPHERAL:
      return "peripheral";
    case ADVERTISEMENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

AdvertisementType ParseAdvertisementType(const std::string& enum_string) {
  if (enum_string == "broadcast")
    return ADVERTISEMENT_TYPE_BROADCAST;
  if (enum_string == "peripheral")
    return ADVERTISEMENT_TYPE_PERIPHERAL;
  return ADVERTISEMENT_TYPE_NONE;
}


Device::Device()
 {}

Device::~Device() {}
Device::Device(Device&& rhs)
: address(std::move(rhs.address)),
name(std::move(rhs.name)),
device_class(std::move(rhs.device_class)){
}

Device& Device::operator=(Device&& rhs)
{
address = std::move(rhs.address);
name = std::move(rhs.name);
device_class = std::move(rhs.device_class);
return *this;
}

// static
bool Device::Populate(
    const base::Value& value, Device* out) {
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

  return to_value_result;
}


Service::Service()
: is_primary(false) {}

Service::~Service() {}
Service::Service(Service&& rhs)
: uuid(std::move(rhs.uuid)),
is_primary(rhs.is_primary),
instance_id(std::move(rhs.instance_id)),
device_address(std::move(rhs.device_address)){
}

Service& Service::operator=(Service&& rhs)
{
uuid = std::move(rhs.uuid);
is_primary = rhs.is_primary;
instance_id = std::move(rhs.instance_id);
device_address = std::move(rhs.device_address);
return *this;
}

// static
bool Service::Populate(
    const base::Value& value, Service* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* uuid_value = NULL;
  if (!dict->GetWithoutPathExpansion("uuid", &uuid_value)) {
    return false;
  }
  {
    if (!uuid_value->GetAsString(&out->uuid)) {
      return false;
    }
  }

  const base::Value* is_primary_value = NULL;
  if (!dict->GetWithoutPathExpansion("isPrimary", &is_primary_value)) {
    return false;
  }
  {
    if (!is_primary_value->GetAsBoolean(&out->is_primary)) {
      return false;
    }
  }

  const base::Value* instance_id_value = NULL;
  if (dict->GetWithoutPathExpansion("instanceId", &instance_id_value)) {
    {
      std::string temp;
      if (!instance_id_value->GetAsString(&temp)) {
        out->instance_id.reset();
        return false;
      }
      else
        out->instance_id.reset(new std::string(temp));
    }
  }

  const base::Value* device_address_value = NULL;
  if (dict->GetWithoutPathExpansion("deviceAddress", &device_address_value)) {
    {
      std::string temp;
      if (!device_address_value->GetAsString(&temp)) {
        out->device_address.reset();
        return false;
      }
      else
        out->device_address.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Service> Service::FromValue(const base::Value& value) {
  std::unique_ptr<Service> out(new Service());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Service::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("uuid", std::make_unique<base::Value>(this->uuid));

  to_value_result->SetWithoutPathExpansion("isPrimary", std::make_unique<base::Value>(this->is_primary));

  if (this->instance_id.get()) {
    to_value_result->SetWithoutPathExpansion("instanceId", std::make_unique<base::Value>(*this->instance_id));

  }
  if (this->device_address.get()) {
    to_value_result->SetWithoutPathExpansion("deviceAddress", std::make_unique<base::Value>(*this->device_address));

  }

  return to_value_result;
}


Characteristic::Characteristic()
 {}

Characteristic::~Characteristic() {}
Characteristic::Characteristic(Characteristic&& rhs)
: uuid(std::move(rhs.uuid)),
service(std::move(rhs.service)),
properties(std::move(rhs.properties)),
instance_id(std::move(rhs.instance_id)),
value(std::move(rhs.value)){
}

Characteristic& Characteristic::operator=(Characteristic&& rhs)
{
uuid = std::move(rhs.uuid);
service = std::move(rhs.service);
properties = std::move(rhs.properties);
instance_id = std::move(rhs.instance_id);
value = std::move(rhs.value);
return *this;
}

// static
bool Characteristic::Populate(
    const base::Value& value, Characteristic* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* uuid_value = NULL;
  if (!dict->GetWithoutPathExpansion("uuid", &uuid_value)) {
    return false;
  }
  {
    if (!uuid_value->GetAsString(&out->uuid)) {
      return false;
    }
  }

  const base::Value* service_value = NULL;
  if (dict->GetWithoutPathExpansion("service", &service_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!service_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Service> temp(new Service());
        if (!Service::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->service = std::move(temp);
      }
    }
  }

  const base::Value* properties_value = NULL;
  if (!dict->GetWithoutPathExpansion("properties", &properties_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!properties_value->GetAsList(&list)) {
      return false;
    }
    else {
      for (const auto& it : *(list)) {
        CharacteristicProperty tmp;
        std::string characteristic_property_as_string;
        if (!(it).GetAsString(&characteristic_property_as_string)) {
          return false;
        }
        tmp = ParseCharacteristicProperty(characteristic_property_as_string);
        if (tmp == CHARACTERISTIC_PROPERTY_NONE) {
          return false;
        }
        out->properties.push_back(tmp);
      }
    }
  }

  const base::Value* instance_id_value = NULL;
  if (dict->GetWithoutPathExpansion("instanceId", &instance_id_value)) {
    {
      std::string temp;
      if (!instance_id_value->GetAsString(&temp)) {
        out->instance_id.reset();
        return false;
      }
      else
        out->instance_id.reset(new std::string(temp));
    }
  }

  const base::Value* value_value = NULL;
  if (dict->GetWithoutPathExpansion("value", &value_value)) {
    {
      if (!value_value->is_blob()) {
        return false;
      }
      else {
        out->value.reset(new std::vector<uint8_t>(value_value->GetBlob()));
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Characteristic> Characteristic::FromValue(const base::Value& value) {
  std::unique_ptr<Characteristic> out(new Characteristic());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Characteristic::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("uuid", std::make_unique<base::Value>(this->uuid));

  if (this->service.get()) {
    to_value_result->SetWithoutPathExpansion("service", (this->service)->ToValue());

  }
  {
    std::vector<std::string> properties_list;
    for (const auto& it : (this->properties)) {
    properties_list.push_back(bluetooth_low_energy::ToString(it));
  }
  to_value_result->SetWithoutPathExpansion("properties", json_schema_compiler::util::CreateValueFromArray(properties_list));
  }

  if (this->instance_id.get()) {
    to_value_result->SetWithoutPathExpansion("instanceId", std::make_unique<base::Value>(*this->instance_id));

  }
  if (this->value.get()) {
    to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(*this->value));

  }

  return to_value_result;
}


Descriptor::Descriptor()
 {}

Descriptor::~Descriptor() {}
Descriptor::Descriptor(Descriptor&& rhs)
: uuid(std::move(rhs.uuid)),
characteristic(std::move(rhs.characteristic)),
permissions(std::move(rhs.permissions)),
instance_id(std::move(rhs.instance_id)),
value(std::move(rhs.value)){
}

Descriptor& Descriptor::operator=(Descriptor&& rhs)
{
uuid = std::move(rhs.uuid);
characteristic = std::move(rhs.characteristic);
permissions = std::move(rhs.permissions);
instance_id = std::move(rhs.instance_id);
value = std::move(rhs.value);
return *this;
}

// static
bool Descriptor::Populate(
    const base::Value& value, Descriptor* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* uuid_value = NULL;
  if (!dict->GetWithoutPathExpansion("uuid", &uuid_value)) {
    return false;
  }
  {
    if (!uuid_value->GetAsString(&out->uuid)) {
      return false;
    }
  }

  const base::Value* characteristic_value = NULL;
  if (dict->GetWithoutPathExpansion("characteristic", &characteristic_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!characteristic_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Characteristic> temp(new Characteristic());
        if (!Characteristic::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->characteristic = std::move(temp);
      }
    }
  }

  const base::Value* permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("permissions", &permissions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!permissions_value->GetAsList(&list)) {
      return false;
    }
    else {
      for (const auto& it : *(list)) {
        DescriptorPermission tmp;
        std::string descriptor_permission_as_string;
        if (!(it).GetAsString(&descriptor_permission_as_string)) {
          return false;
        }
        tmp = ParseDescriptorPermission(descriptor_permission_as_string);
        if (tmp == DESCRIPTOR_PERMISSION_NONE) {
          return false;
        }
        out->permissions.push_back(tmp);
      }
    }
  }

  const base::Value* instance_id_value = NULL;
  if (dict->GetWithoutPathExpansion("instanceId", &instance_id_value)) {
    {
      std::string temp;
      if (!instance_id_value->GetAsString(&temp)) {
        out->instance_id.reset();
        return false;
      }
      else
        out->instance_id.reset(new std::string(temp));
    }
  }

  const base::Value* value_value = NULL;
  if (dict->GetWithoutPathExpansion("value", &value_value)) {
    {
      if (!value_value->is_blob()) {
        return false;
      }
      else {
        out->value.reset(new std::vector<uint8_t>(value_value->GetBlob()));
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Descriptor> Descriptor::FromValue(const base::Value& value) {
  std::unique_ptr<Descriptor> out(new Descriptor());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Descriptor::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("uuid", std::make_unique<base::Value>(this->uuid));

  if (this->characteristic.get()) {
    to_value_result->SetWithoutPathExpansion("characteristic", (this->characteristic)->ToValue());

  }
  {
    std::vector<std::string> permissions_list;
    for (const auto& it : (this->permissions)) {
    permissions_list.push_back(bluetooth_low_energy::ToString(it));
  }
  to_value_result->SetWithoutPathExpansion("permissions", json_schema_compiler::util::CreateValueFromArray(permissions_list));
  }

  if (this->instance_id.get()) {
    to_value_result->SetWithoutPathExpansion("instanceId", std::make_unique<base::Value>(*this->instance_id));

  }
  if (this->value.get()) {
    to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(*this->value));

  }

  return to_value_result;
}


ConnectProperties::ConnectProperties()
: persistent(false) {}

ConnectProperties::~ConnectProperties() {}
ConnectProperties::ConnectProperties(ConnectProperties&& rhs)
: persistent(rhs.persistent){
}

ConnectProperties& ConnectProperties::operator=(ConnectProperties&& rhs)
{
persistent = rhs.persistent;
return *this;
}

// static
bool ConnectProperties::Populate(
    const base::Value& value, ConnectProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* persistent_value = NULL;
  if (!dict->GetWithoutPathExpansion("persistent", &persistent_value)) {
    return false;
  }
  {
    if (!persistent_value->GetAsBoolean(&out->persistent)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ConnectProperties> ConnectProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ConnectProperties> out(new ConnectProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ConnectProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("persistent", std::make_unique<base::Value>(this->persistent));


  return to_value_result;
}


NotificationProperties::NotificationProperties()
: persistent(false) {}

NotificationProperties::~NotificationProperties() {}
NotificationProperties::NotificationProperties(NotificationProperties&& rhs)
: persistent(rhs.persistent){
}

NotificationProperties& NotificationProperties::operator=(NotificationProperties&& rhs)
{
persistent = rhs.persistent;
return *this;
}

// static
bool NotificationProperties::Populate(
    const base::Value& value, NotificationProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* persistent_value = NULL;
  if (!dict->GetWithoutPathExpansion("persistent", &persistent_value)) {
    return false;
  }
  {
    if (!persistent_value->GetAsBoolean(&out->persistent)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<NotificationProperties> NotificationProperties::FromValue(const base::Value& value) {
  std::unique_ptr<NotificationProperties> out(new NotificationProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NotificationProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("persistent", std::make_unique<base::Value>(this->persistent));


  return to_value_result;
}


ManufacturerData::ManufacturerData()
: id(0) {}

ManufacturerData::~ManufacturerData() {}
ManufacturerData::ManufacturerData(ManufacturerData&& rhs)
: id(rhs.id),
data(std::move(rhs.data)){
}

ManufacturerData& ManufacturerData::operator=(ManufacturerData&& rhs)
{
id = rhs.id;
data = std::move(rhs.data);
return *this;
}

// static
bool ManufacturerData::Populate(
    const base::Value& value, ManufacturerData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* data_value = NULL;
  if (!dict->GetWithoutPathExpansion("data", &data_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!data_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->data)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManufacturerData> ManufacturerData::FromValue(const base::Value& value) {
  std::unique_ptr<ManufacturerData> out(new ManufacturerData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManufacturerData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("data", json_schema_compiler::util::CreateValueFromArray(this->data));


  return to_value_result;
}


ServiceData::ServiceData()
 {}

ServiceData::~ServiceData() {}
ServiceData::ServiceData(ServiceData&& rhs)
: uuid(std::move(rhs.uuid)),
data(std::move(rhs.data)){
}

ServiceData& ServiceData::operator=(ServiceData&& rhs)
{
uuid = std::move(rhs.uuid);
data = std::move(rhs.data);
return *this;
}

// static
bool ServiceData::Populate(
    const base::Value& value, ServiceData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* uuid_value = NULL;
  if (!dict->GetWithoutPathExpansion("uuid", &uuid_value)) {
    return false;
  }
  {
    if (!uuid_value->GetAsString(&out->uuid)) {
      return false;
    }
  }

  const base::Value* data_value = NULL;
  if (!dict->GetWithoutPathExpansion("data", &data_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!data_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->data)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ServiceData> ServiceData::FromValue(const base::Value& value) {
  std::unique_ptr<ServiceData> out(new ServiceData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ServiceData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("uuid", std::make_unique<base::Value>(this->uuid));

  to_value_result->SetWithoutPathExpansion("data", json_schema_compiler::util::CreateValueFromArray(this->data));


  return to_value_result;
}


Advertisement::Advertisement()
: type(ADVERTISEMENT_TYPE_NONE) {}

Advertisement::~Advertisement() {}
Advertisement::Advertisement(Advertisement&& rhs)
: type(rhs.type),
service_uuids(std::move(rhs.service_uuids)),
manufacturer_data(std::move(rhs.manufacturer_data)),
solicit_uuids(std::move(rhs.solicit_uuids)),
service_data(std::move(rhs.service_data)){
}

Advertisement& Advertisement::operator=(Advertisement&& rhs)
{
type = rhs.type;
service_uuids = std::move(rhs.service_uuids);
manufacturer_data = std::move(rhs.manufacturer_data);
solicit_uuids = std::move(rhs.solicit_uuids);
service_data = std::move(rhs.service_data);
return *this;
}

// static
bool Advertisement::Populate(
    const base::Value& value, Advertisement* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string advertisement_type_as_string;
    if (!type_value->GetAsString(&advertisement_type_as_string)) {
      return false;
    }
    out->type = ParseAdvertisementType(advertisement_type_as_string);
    if (out->type == ADVERTISEMENT_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* service_uuids_value = NULL;
  if (dict->GetWithoutPathExpansion("serviceUuids", &service_uuids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!service_uuids_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->service_uuids)) {
          return false;
        }
      }
    }
  }

  const base::Value* manufacturer_data_value = NULL;
  if (dict->GetWithoutPathExpansion("manufacturerData", &manufacturer_data_value)) {
    {
      const base::ListValue* list = NULL;
      if (!manufacturer_data_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->manufacturer_data)) {
          return false;
        }
      }
    }
  }

  const base::Value* solicit_uuids_value = NULL;
  if (dict->GetWithoutPathExpansion("solicitUuids", &solicit_uuids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!solicit_uuids_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->solicit_uuids)) {
          return false;
        }
      }
    }
  }

  const base::Value* service_data_value = NULL;
  if (dict->GetWithoutPathExpansion("serviceData", &service_data_value)) {
    {
      const base::ListValue* list = NULL;
      if (!service_data_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->service_data)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Advertisement> Advertisement::FromValue(const base::Value& value) {
  std::unique_ptr<Advertisement> out(new Advertisement());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Advertisement::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(bluetooth_low_energy::ToString(this->type)));

  if (this->service_uuids.get()) {
    to_value_result->SetWithoutPathExpansion("serviceUuids", json_schema_compiler::util::CreateValueFromOptionalArray(this->service_uuids));

  }
  if (this->manufacturer_data.get()) {
    to_value_result->SetWithoutPathExpansion("manufacturerData", json_schema_compiler::util::CreateValueFromOptionalArray(this->manufacturer_data));

  }
  if (this->solicit_uuids.get()) {
    to_value_result->SetWithoutPathExpansion("solicitUuids", json_schema_compiler::util::CreateValueFromOptionalArray(this->solicit_uuids));

  }
  if (this->service_data.get()) {
    to_value_result->SetWithoutPathExpansion("serviceData", json_schema_compiler::util::CreateValueFromOptionalArray(this->service_data));

  }

  return to_value_result;
}


Request::Request()
: request_id(0) {}

Request::~Request() {}
Request::Request(Request&& rhs)
: request_id(rhs.request_id),
device(std::move(rhs.device)),
value(std::move(rhs.value)){
}

Request& Request::operator=(Request&& rhs)
{
request_id = rhs.request_id;
device = std::move(rhs.device);
value = std::move(rhs.value);
return *this;
}

// static
bool Request::Populate(
    const base::Value& value, Request* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* request_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("requestId", &request_id_value)) {
    return false;
  }
  {
    if (!request_id_value->GetAsInteger(&out->request_id)) {
      return false;
    }
  }

  const base::Value* device_value = NULL;
  if (!dict->GetWithoutPathExpansion("device", &device_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!device_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Device::Populate(*dictionary, &out->device)) {
      return false;
    }
  }

  const base::Value* value_value = NULL;
  if (dict->GetWithoutPathExpansion("value", &value_value)) {
    {
      if (!value_value->is_blob()) {
        return false;
      }
      else {
        out->value.reset(new std::vector<uint8_t>(value_value->GetBlob()));
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Request> Request::FromValue(const base::Value& value) {
  std::unique_ptr<Request> out(new Request());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Request::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("requestId", std::make_unique<base::Value>(this->request_id));

  to_value_result->SetWithoutPathExpansion("device", (this->device).ToValue());

  if (this->value.get()) {
    to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(*this->value));

  }

  return to_value_result;
}


Response::Response()
: request_id(0),
is_error(false) {}

Response::~Response() {}
Response::Response(Response&& rhs)
: request_id(rhs.request_id),
is_error(rhs.is_error),
value(std::move(rhs.value)){
}

Response& Response::operator=(Response&& rhs)
{
request_id = rhs.request_id;
is_error = rhs.is_error;
value = std::move(rhs.value);
return *this;
}

// static
bool Response::Populate(
    const base::Value& value, Response* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* request_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("requestId", &request_id_value)) {
    return false;
  }
  {
    if (!request_id_value->GetAsInteger(&out->request_id)) {
      return false;
    }
  }

  const base::Value* is_error_value = NULL;
  if (!dict->GetWithoutPathExpansion("isError", &is_error_value)) {
    return false;
  }
  {
    if (!is_error_value->GetAsBoolean(&out->is_error)) {
      return false;
    }
  }

  const base::Value* value_value = NULL;
  if (dict->GetWithoutPathExpansion("value", &value_value)) {
    {
      if (!value_value->is_blob()) {
        return false;
      }
      else {
        out->value.reset(new std::vector<uint8_t>(value_value->GetBlob()));
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Response> Response::FromValue(const base::Value& value) {
  std::unique_ptr<Response> out(new Response());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Response::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("requestId", std::make_unique<base::Value>(this->request_id));

  to_value_result->SetWithoutPathExpansion("isError", std::make_unique<base::Value>(this->is_error));

  if (this->value.get()) {
    to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(*this->value));

  }

  return to_value_result;
}


Notification::Notification()
 {}

Notification::~Notification() {}
Notification::Notification(Notification&& rhs)
: value(std::move(rhs.value)),
should_indicate(std::move(rhs.should_indicate)){
}

Notification& Notification::operator=(Notification&& rhs)
{
value = std::move(rhs.value);
should_indicate = std::move(rhs.should_indicate);
return *this;
}

// static
bool Notification::Populate(
    const base::Value& value, Notification* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    return false;
  }
  {
    if (!value_value->is_blob()) {
      return false;
    }
    else {
      out->value = value_value->GetBlob();
    }
  }

  const base::Value* should_indicate_value = NULL;
  if (dict->GetWithoutPathExpansion("shouldIndicate", &should_indicate_value)) {
    {
      bool temp;
      if (!should_indicate_value->GetAsBoolean(&temp)) {
        out->should_indicate.reset();
        return false;
      }
      else
        out->should_indicate.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Notification> Notification::FromValue(const base::Value& value) {
  std::unique_ptr<Notification> out(new Notification());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Notification::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));

  if (this->should_indicate.get()) {
    to_value_result->SetWithoutPathExpansion("shouldIndicate", std::make_unique<base::Value>(*this->should_indicate));

  }

  return to_value_result;
}



//
// Functions
//

namespace Connect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
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

  const base::Value* properties_value = NULL;
  if (args.Get(1, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<ConnectProperties> temp(new ConnectProperties());
        if (!ConnectProperties::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->properties = std::move(temp);
      }
    }
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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Disconnect

namespace GetService {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* service_id_value = NULL;
  if (args.Get(0, &service_id_value) &&
      !service_id_value->is_none()) {
    {
      if (!service_id_value->GetAsString(&params->service_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Service& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetService

namespace CreateService {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* service_value = NULL;
  if (args.Get(0, &service_value) &&
      !service_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!service_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Service::Populate(*dictionary, &params->service)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& service_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(service_id));

  return create_results;
}
}  // namespace CreateService

namespace GetServices {

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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Service>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetServices

namespace GetCharacteristic {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(0, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Characteristic& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetCharacteristic

namespace CreateCharacteristic {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_value = NULL;
  if (args.Get(0, &characteristic_value) &&
      !characteristic_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!characteristic_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Characteristic::Populate(*dictionary, &params->characteristic)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* service_id_value = NULL;
  if (args.Get(1, &service_id_value) &&
      !service_id_value->is_none()) {
    {
      if (!service_id_value->GetAsString(&params->service_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& characteristic_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(characteristic_id));

  return create_results;
}
}  // namespace CreateCharacteristic

namespace GetCharacteristics {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* service_id_value = NULL;
  if (args.Get(0, &service_id_value) &&
      !service_id_value->is_none()) {
    {
      if (!service_id_value->GetAsString(&params->service_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Characteristic>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetCharacteristics

namespace GetIncludedServices {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* service_id_value = NULL;
  if (args.Get(0, &service_id_value) &&
      !service_id_value->is_none()) {
    {
      if (!service_id_value->GetAsString(&params->service_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Service>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetIncludedServices

namespace GetDescriptor {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* descriptor_id_value = NULL;
  if (args.Get(0, &descriptor_id_value) &&
      !descriptor_id_value->is_none()) {
    {
      if (!descriptor_id_value->GetAsString(&params->descriptor_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Descriptor& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetDescriptor

namespace CreateDescriptor {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* descriptor_value = NULL;
  if (args.Get(0, &descriptor_value) &&
      !descriptor_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!descriptor_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Descriptor::Populate(*dictionary, &params->descriptor)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(1, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& descriptor_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(descriptor_id));

  return create_results;
}
}  // namespace CreateDescriptor

namespace GetDescriptors {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(0, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Descriptor>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetDescriptors

namespace ReadCharacteristicValue {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(0, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Characteristic& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace ReadCharacteristicValue

namespace WriteCharacteristicValue {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(0, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* value_value = NULL;
  if (args.Get(1, &value_value) &&
      !value_value->is_none()) {
    {
      if (!value_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->value = value_value->GetBlob();
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
}  // namespace WriteCharacteristicValue

namespace StartCharacteristicNotifications {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(0, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
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
      else {
        std::unique_ptr<NotificationProperties> temp(new NotificationProperties());
        if (!NotificationProperties::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->properties = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace StartCharacteristicNotifications

namespace StopCharacteristicNotifications {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(0, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
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
}  // namespace StopCharacteristicNotifications

namespace NotifyCharacteristicValueChanged {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* characteristic_id_value = NULL;
  if (args.Get(0, &characteristic_id_value) &&
      !characteristic_id_value->is_none()) {
    {
      if (!characteristic_id_value->GetAsString(&params->characteristic_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* notification_value = NULL;
  if (args.Get(1, &notification_value) &&
      !notification_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!notification_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Notification::Populate(*dictionary, &params->notification)) {
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
}  // namespace NotifyCharacteristicValueChanged

namespace ReadDescriptorValue {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* descriptor_id_value = NULL;
  if (args.Get(0, &descriptor_id_value) &&
      !descriptor_id_value->is_none()) {
    {
      if (!descriptor_id_value->GetAsString(&params->descriptor_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Descriptor& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace ReadDescriptorValue

namespace WriteDescriptorValue {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* descriptor_id_value = NULL;
  if (args.Get(0, &descriptor_id_value) &&
      !descriptor_id_value->is_none()) {
    {
      if (!descriptor_id_value->GetAsString(&params->descriptor_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* value_value = NULL;
  if (args.Get(1, &value_value) &&
      !value_value->is_none()) {
    {
      if (!value_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->value = value_value->GetBlob();
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
}  // namespace WriteDescriptorValue

namespace RegisterService {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* service_id_value = NULL;
  if (args.Get(0, &service_id_value) &&
      !service_id_value->is_none()) {
    {
      if (!service_id_value->GetAsString(&params->service_id)) {
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
}  // namespace RegisterService

namespace UnregisterService {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* service_id_value = NULL;
  if (args.Get(0, &service_id_value) &&
      !service_id_value->is_none()) {
    {
      if (!service_id_value->GetAsString(&params->service_id)) {
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
}  // namespace UnregisterService

namespace RemoveService {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* service_id_value = NULL;
  if (args.Get(0, &service_id_value) &&
      !service_id_value->is_none()) {
    {
      if (!service_id_value->GetAsString(&params->service_id)) {
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
}  // namespace RemoveService

namespace RegisterAdvertisement {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* advertisement_value = NULL;
  if (args.Get(0, &advertisement_value) &&
      !advertisement_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!advertisement_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Advertisement::Populate(*dictionary, &params->advertisement)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int advertisement_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(advertisement_id));

  return create_results;
}
}  // namespace RegisterAdvertisement

namespace UnregisterAdvertisement {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* advertisement_id_value = NULL;
  if (args.Get(0, &advertisement_id_value) &&
      !advertisement_id_value->is_none()) {
    {
      if (!advertisement_id_value->GetAsInteger(&params->advertisement_id)) {
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
}  // namespace UnregisterAdvertisement

namespace ResetAdvertising {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ResetAdvertising

namespace SetAdvertisingInterval {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* min_interval_value = NULL;
  if (args.Get(0, &min_interval_value) &&
      !min_interval_value->is_none()) {
    {
      if (!min_interval_value->GetAsInteger(&params->min_interval)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* max_interval_value = NULL;
  if (args.Get(1, &max_interval_value) &&
      !max_interval_value->is_none()) {
    {
      if (!max_interval_value->GetAsInteger(&params->max_interval)) {
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
}  // namespace SetAdvertisingInterval

namespace SendRequestResponse {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* response_value = NULL;
  if (args.Get(0, &response_value) &&
      !response_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!response_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Response::Populate(*dictionary, &params->response)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SendRequestResponse

//
// Events
//

namespace OnServiceAdded {

const char kEventName[] = "bluetoothLowEnergy.onServiceAdded";

std::unique_ptr<base::ListValue> Create(const Service& service) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((service).ToValue());

  return create_results;
}

}  // namespace OnServiceAdded

namespace OnServiceChanged {

const char kEventName[] = "bluetoothLowEnergy.onServiceChanged";

std::unique_ptr<base::ListValue> Create(const Service& service) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((service).ToValue());

  return create_results;
}

}  // namespace OnServiceChanged

namespace OnServiceRemoved {

const char kEventName[] = "bluetoothLowEnergy.onServiceRemoved";

std::unique_ptr<base::ListValue> Create(const Service& service) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((service).ToValue());

  return create_results;
}

}  // namespace OnServiceRemoved

namespace OnCharacteristicValueChanged {

const char kEventName[] = "bluetoothLowEnergy.onCharacteristicValueChanged";

std::unique_ptr<base::ListValue> Create(const Characteristic& characteristic) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((characteristic).ToValue());

  return create_results;
}

}  // namespace OnCharacteristicValueChanged

namespace OnDescriptorValueChanged {

const char kEventName[] = "bluetoothLowEnergy.onDescriptorValueChanged";

std::unique_ptr<base::ListValue> Create(const Descriptor& descriptor) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((descriptor).ToValue());

  return create_results;
}

}  // namespace OnDescriptorValueChanged

namespace OnCharacteristicReadRequest {

const char kEventName[] = "bluetoothLowEnergy.onCharacteristicReadRequest";

std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& characteristic_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((request).ToValue());

  create_results->Append(std::make_unique<base::Value>(characteristic_id));

  return create_results;
}

}  // namespace OnCharacteristicReadRequest

namespace OnCharacteristicWriteRequest {

const char kEventName[] = "bluetoothLowEnergy.onCharacteristicWriteRequest";

std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& characteristic_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((request).ToValue());

  create_results->Append(std::make_unique<base::Value>(characteristic_id));

  return create_results;
}

}  // namespace OnCharacteristicWriteRequest

namespace OnDescriptorReadRequest {

const char kEventName[] = "bluetoothLowEnergy.onDescriptorReadRequest";

std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& descriptor_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((request).ToValue());

  create_results->Append(std::make_unique<base::Value>(descriptor_id));

  return create_results;
}

}  // namespace OnDescriptorReadRequest

namespace OnDescriptorWriteRequest {

const char kEventName[] = "bluetoothLowEnergy.onDescriptorWriteRequest";

std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& descriptor_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((request).ToValue());

  create_results->Append(std::make_unique<base::Value>(descriptor_id));

  return create_results;
}

}  // namespace OnDescriptorWriteRequest

}  // namespace bluetooth_low_energy
}  // namespace api
}  // namespace extensions

