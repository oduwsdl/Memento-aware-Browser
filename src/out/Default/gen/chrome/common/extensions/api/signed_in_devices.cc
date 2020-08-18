// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/signed_in_devices.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/signed_in_devices.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace signed_in_devices {
//
// Types
//

const char* ToString(OS enum_param) {
  switch (enum_param) {
    case OS_WIN_:
      return "win";
    case OS_MAC_:
      return "mac";
    case OS_LINUX_:
      return "linux";
    case OS_CHROME_OS_:
      return "chrome_os";
    case OS_ANDROID_:
      return "android";
    case OS_IOS_:
      return "ios";
    case OS_UNKNOWN_:
      return "unknown";
    case OS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OS ParseOS(const std::string& enum_string) {
  if (enum_string == "win")
    return OS_WIN_;
  if (enum_string == "mac")
    return OS_MAC_;
  if (enum_string == "linux")
    return OS_LINUX_;
  if (enum_string == "chrome_os")
    return OS_CHROME_OS_;
  if (enum_string == "android")
    return OS_ANDROID_;
  if (enum_string == "ios")
    return OS_IOS_;
  if (enum_string == "unknown")
    return OS_UNKNOWN_;
  return OS_NONE;
}


const char* ToString(DeviceType enum_param) {
  switch (enum_param) {
    case DEVICE_TYPE_DESKTOP_OR_LAPTOP:
      return "desktop_or_laptop";
    case DEVICE_TYPE_PHONE:
      return "phone";
    case DEVICE_TYPE_TABLET:
      return "tablet";
    case DEVICE_TYPE_UNKNOWN:
      return "unknown";
    case DEVICE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DeviceType ParseDeviceType(const std::string& enum_string) {
  if (enum_string == "desktop_or_laptop")
    return DEVICE_TYPE_DESKTOP_OR_LAPTOP;
  if (enum_string == "phone")
    return DEVICE_TYPE_PHONE;
  if (enum_string == "tablet")
    return DEVICE_TYPE_TABLET;
  if (enum_string == "unknown")
    return DEVICE_TYPE_UNKNOWN;
  return DEVICE_TYPE_NONE;
}


DeviceInfo::DeviceInfo()
: os(OS_NONE),
type(DEVICE_TYPE_NONE) {}

DeviceInfo::~DeviceInfo() {}
DeviceInfo::DeviceInfo(DeviceInfo&& rhs)
: name(std::move(rhs.name)),
id(std::move(rhs.id)),
os(rhs.os),
type(rhs.type),
chrome_version(std::move(rhs.chrome_version)){
}

DeviceInfo& DeviceInfo::operator=(DeviceInfo&& rhs)
{
name = std::move(rhs.name);
id = std::move(rhs.id);
os = rhs.os;
type = rhs.type;
chrome_version = std::move(rhs.chrome_version);
return *this;
}

// static
bool DeviceInfo::Populate(
    const base::Value& value, DeviceInfo* out) {
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

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* os_value = NULL;
  if (!dict->GetWithoutPathExpansion("os", &os_value)) {
    return false;
  }
  {
    std::string os_as_string;
    if (!os_value->GetAsString(&os_as_string)) {
      return false;
    }
    out->os = ParseOS(os_as_string);
    if (out->os == OS_NONE) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
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

  const base::Value* chrome_version_value = NULL;
  if (!dict->GetWithoutPathExpansion("chromeVersion", &chrome_version_value)) {
    return false;
  }
  {
    if (!chrome_version_value->GetAsString(&out->chrome_version)) {
      return false;
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

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("os", std::make_unique<base::Value>(signed_in_devices::ToString(this->os)));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(signed_in_devices::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("chromeVersion", std::make_unique<base::Value>(this->chrome_version));


  return to_value_result;
}



//
// Functions
//

namespace Get {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* is_local_value = NULL;
  if (args.Get(0, &is_local_value) &&
      !is_local_value->is_none()) {
    {
      bool temp;
      if (!is_local_value->GetAsBoolean(&temp)) {
        params->is_local.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->is_local.reset(new bool(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<DeviceInfo>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace Get

//
// Events
//

namespace OnDeviceInfoChange {

const char kEventName[] = "signedInDevices.onDeviceInfoChange";

std::unique_ptr<base::ListValue> Create(const std::vector<DeviceInfo>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}

}  // namespace OnDeviceInfoChange

}  // namespace signed_in_devices
}  // namespace api
}  // namespace extensions

