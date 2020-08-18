// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/enterprise_hardware_platform.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_ENTERPRISE_HARDWARE_PLATFORM_H__
#define CHROME_COMMON_EXTENSIONS_API_ENTERPRISE_HARDWARE_PLATFORM_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace enterprise_hardware_platform {

//
// Types
//

struct HardwarePlatformInfo {
  HardwarePlatformInfo();
  ~HardwarePlatformInfo();
  HardwarePlatformInfo(HardwarePlatformInfo&& rhs);
  HardwarePlatformInfo& operator=(HardwarePlatformInfo&& rhs);

  // Populates a HardwarePlatformInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, HardwarePlatformInfo* out);

  // Creates a HardwarePlatformInfo object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<HardwarePlatformInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HardwarePlatformInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string model;

  std::string manufacturer;


 private:
  DISALLOW_COPY_AND_ASSIGN(HardwarePlatformInfo);
};


//
// Functions
//

namespace GetHardwarePlatformInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const HardwarePlatformInfo& info);
}  // namespace Results

}  // namespace GetHardwarePlatformInfo

}  // namespace enterprise_hardware_platform
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_ENTERPRISE_HARDWARE_PLATFORM_H__
