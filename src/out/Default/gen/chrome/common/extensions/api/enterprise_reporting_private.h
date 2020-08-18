// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/enterprise_reporting_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_ENTERPRISE_REPORTING_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_ENTERPRISE_REPORTING_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace enterprise_reporting_private {

//
// Types
//

// Possible states a particular device setting can be in.
enum SettingValue {
  SETTING_VALUE_NONE,
  SETTING_VALUE_UNKNOWN,
  SETTING_VALUE_DISABLED,
  SETTING_VALUE_ENABLED,
  SETTING_VALUE_LAST = SETTING_VALUE_ENABLED,
};


const char* ToString(SettingValue as_enum);
SettingValue ParseSettingValue(const std::string& as_string);

struct DeviceInfo {
  DeviceInfo();
  ~DeviceInfo();
  DeviceInfo(DeviceInfo&& rhs);
  DeviceInfo& operator=(DeviceInfo&& rhs);

  // Populates a DeviceInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, DeviceInfo* out);

  // Creates a DeviceInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<DeviceInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string os_name;

  std::string os_version;

  std::string device_host_name;

  std::string device_model;

  std::string serial_number;

  SettingValue screen_lock_secured;

  SettingValue disk_encrypted;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceInfo);
};


//
// Functions
//

namespace UploadChromeDesktopReport {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Report {
    Report();
    ~Report();
    Report(Report&& rhs);
    Report& operator=(Report&& rhs);

    // Populates a Report object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Report* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Report);
  };


  Report report;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UploadChromeDesktopReport

namespace GetDeviceId {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& id);
}  // namespace Results

}  // namespace GetDeviceId

namespace GetPersistentSecret {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<uint8_t>& secret);
}  // namespace Results

}  // namespace GetPersistentSecret

namespace GetDeviceData {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<uint8_t>& data);
}  // namespace Results

}  // namespace GetDeviceData

namespace SetDeviceData {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;

  std::unique_ptr<std::vector<uint8_t>> data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetDeviceData

namespace GetDeviceInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const DeviceInfo& device_info);
}  // namespace Results

}  // namespace GetDeviceInfo

}  // namespace enterprise_reporting_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_ENTERPRISE_REPORTING_PRIVATE_H__
