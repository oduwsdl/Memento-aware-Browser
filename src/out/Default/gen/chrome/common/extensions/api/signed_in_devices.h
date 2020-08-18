// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/signed_in_devices.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_SIGNED_IN_DEVICES_H__
#define CHROME_COMMON_EXTENSIONS_API_SIGNED_IN_DEVICES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace signed_in_devices {

//
// Types
//

enum OS {
  OS_NONE,
  OS_WIN_,
  OS_MAC_,
  OS_LINUX_,
  OS_CHROME_OS_,
  OS_ANDROID_,
  OS_IOS_,
  OS_UNKNOWN_,
  OS_LAST = OS_UNKNOWN_,
};


const char* ToString(OS as_enum);
OS ParseOS(const std::string& as_string);

enum DeviceType {
  DEVICE_TYPE_NONE,
  DEVICE_TYPE_DESKTOP_OR_LAPTOP,
  DEVICE_TYPE_PHONE,
  DEVICE_TYPE_TABLET,
  DEVICE_TYPE_UNKNOWN,
  DEVICE_TYPE_LAST = DEVICE_TYPE_UNKNOWN,
};


const char* ToString(DeviceType as_enum);
DeviceType ParseDeviceType(const std::string& as_string);

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

  // Name of the device. This name is usually set by the user when setting up a
  // device.
  std::string name;

  // Unique Id for this device. Note: The id is meaningful only in the current
  // device. This id cannot be used to refer to the same device from another
  // device or extension.
  std::string id;

  // The OS of the device.
  OS os;

  // Device Type.
  DeviceType type;

  // Version of chrome running in this device.
  std::string chrome_version;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceInfo);
};


//
// Functions
//

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // If true only return the information for the local device. If false or omitted
  // return the list of all devices including the local device.
  std::unique_ptr<bool> is_local;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<DeviceInfo>& devices);
}  // namespace Results

}  // namespace Get

//
// Events
//

namespace OnDeviceInfoChange {

extern const char kEventName[];  // "signedInDevices.onDeviceInfoChange"

// The array of all signed in devices.
std::unique_ptr<base::ListValue> Create(const std::vector<DeviceInfo>& devices);
}  // namespace OnDeviceInfoChange

}  // namespace signed_in_devices
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_SIGNED_IN_DEVICES_H__
