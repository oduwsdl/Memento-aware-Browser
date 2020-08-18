// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/enterprise_reporting_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/enterprise_reporting_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace enterprise_reporting_private {
//
// Types
//

const char* ToString(SettingValue enum_param) {
  switch (enum_param) {
    case SETTING_VALUE_UNKNOWN:
      return "UNKNOWN";
    case SETTING_VALUE_DISABLED:
      return "DISABLED";
    case SETTING_VALUE_ENABLED:
      return "ENABLED";
    case SETTING_VALUE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SettingValue ParseSettingValue(const std::string& enum_string) {
  if (enum_string == "UNKNOWN")
    return SETTING_VALUE_UNKNOWN;
  if (enum_string == "DISABLED")
    return SETTING_VALUE_DISABLED;
  if (enum_string == "ENABLED")
    return SETTING_VALUE_ENABLED;
  return SETTING_VALUE_NONE;
}


DeviceInfo::DeviceInfo()
: screen_lock_secured(SETTING_VALUE_NONE),
disk_encrypted(SETTING_VALUE_NONE) {}

DeviceInfo::~DeviceInfo() {}
DeviceInfo::DeviceInfo(DeviceInfo&& rhs)
: os_name(std::move(rhs.os_name)),
os_version(std::move(rhs.os_version)),
device_host_name(std::move(rhs.device_host_name)),
device_model(std::move(rhs.device_model)),
serial_number(std::move(rhs.serial_number)),
screen_lock_secured(rhs.screen_lock_secured),
disk_encrypted(rhs.disk_encrypted){
}

DeviceInfo& DeviceInfo::operator=(DeviceInfo&& rhs)
{
os_name = std::move(rhs.os_name);
os_version = std::move(rhs.os_version);
device_host_name = std::move(rhs.device_host_name);
device_model = std::move(rhs.device_model);
serial_number = std::move(rhs.serial_number);
screen_lock_secured = rhs.screen_lock_secured;
disk_encrypted = rhs.disk_encrypted;
return *this;
}

// static
bool DeviceInfo::Populate(
    const base::Value& value, DeviceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* os_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("osName", &os_name_value)) {
    return false;
  }
  {
    if (!os_name_value->GetAsString(&out->os_name)) {
      return false;
    }
  }

  const base::Value* os_version_value = NULL;
  if (!dict->GetWithoutPathExpansion("osVersion", &os_version_value)) {
    return false;
  }
  {
    if (!os_version_value->GetAsString(&out->os_version)) {
      return false;
    }
  }

  const base::Value* device_host_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceHostName", &device_host_name_value)) {
    return false;
  }
  {
    if (!device_host_name_value->GetAsString(&out->device_host_name)) {
      return false;
    }
  }

  const base::Value* device_model_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceModel", &device_model_value)) {
    return false;
  }
  {
    if (!device_model_value->GetAsString(&out->device_model)) {
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

  const base::Value* screen_lock_secured_value = NULL;
  if (!dict->GetWithoutPathExpansion("screenLockSecured", &screen_lock_secured_value)) {
    return false;
  }
  {
    std::string setting_value_as_string;
    if (!screen_lock_secured_value->GetAsString(&setting_value_as_string)) {
      return false;
    }
    out->screen_lock_secured = ParseSettingValue(setting_value_as_string);
    if (out->screen_lock_secured == SETTING_VALUE_NONE) {
      return false;
    }
  }

  const base::Value* disk_encrypted_value = NULL;
  if (!dict->GetWithoutPathExpansion("diskEncrypted", &disk_encrypted_value)) {
    return false;
  }
  {
    std::string setting_value_as_string;
    if (!disk_encrypted_value->GetAsString(&setting_value_as_string)) {
      return false;
    }
    out->disk_encrypted = ParseSettingValue(setting_value_as_string);
    if (out->disk_encrypted == SETTING_VALUE_NONE) {
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

  to_value_result->SetWithoutPathExpansion("osName", std::make_unique<base::Value>(this->os_name));

  to_value_result->SetWithoutPathExpansion("osVersion", std::make_unique<base::Value>(this->os_version));

  to_value_result->SetWithoutPathExpansion("deviceHostName", std::make_unique<base::Value>(this->device_host_name));

  to_value_result->SetWithoutPathExpansion("deviceModel", std::make_unique<base::Value>(this->device_model));

  to_value_result->SetWithoutPathExpansion("serialNumber", std::make_unique<base::Value>(this->serial_number));

  to_value_result->SetWithoutPathExpansion("screenLockSecured", std::make_unique<base::Value>(enterprise_reporting_private::ToString(this->screen_lock_secured)));

  to_value_result->SetWithoutPathExpansion("diskEncrypted", std::make_unique<base::Value>(enterprise_reporting_private::ToString(this->disk_encrypted)));


  return to_value_result;
}



//
// Functions
//

namespace UploadChromeDesktopReport {

Params::Report::Report()
 {}

Params::Report::~Report() {}
Params::Report::Report(Report&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::Report& Params::Report::operator=(Report&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::Report::Populate(
    const base::Value& value, Report* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* report_value = NULL;
  if (args.Get(0, &report_value) &&
      !report_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!report_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Report::Populate(*dictionary, &params->report)) {
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
}  // namespace UploadChromeDesktopReport

namespace GetDeviceId {

std::unique_ptr<base::ListValue> Results::Create(const std::string& id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(id));

  return create_results;
}
}  // namespace GetDeviceId

namespace GetPersistentSecret {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<uint8_t>& secret) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(secret));

  return create_results;
}
}  // namespace GetPersistentSecret

namespace GetDeviceData {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<uint8_t>& data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(data));

  return create_results;
}
}  // namespace GetDeviceData

namespace SetDeviceData {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
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
        params->data.reset(new std::vector<uint8_t>(data_value->GetBlob()));
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetDeviceData

namespace GetDeviceInfo {

std::unique_ptr<base::ListValue> Results::Create(const DeviceInfo& device_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device_info).ToValue());

  return create_results;
}
}  // namespace GetDeviceInfo

}  // namespace enterprise_reporting_private
}  // namespace api
}  // namespace extensions

