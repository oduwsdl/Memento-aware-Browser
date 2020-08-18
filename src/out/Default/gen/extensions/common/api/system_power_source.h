// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_power_source.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SYSTEM_POWER_SOURCE_H__
#define EXTENSIONS_COMMON_API_SYSTEM_POWER_SOURCE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace system_power_source {

//
// Types
//

enum PowerSourceType {
  POWER_SOURCE_TYPE_NONE,
  POWER_SOURCE_TYPE_UNKNOWN,
  POWER_SOURCE_TYPE_MAINS,
  POWER_SOURCE_TYPE_USB,
  POWER_SOURCE_TYPE_LAST = POWER_SOURCE_TYPE_USB,
};


const char* ToString(PowerSourceType as_enum);
PowerSourceType ParsePowerSourceType(const std::string& as_string);

struct PowerSourceInfo {
  PowerSourceInfo();
  ~PowerSourceInfo();
  PowerSourceInfo(PowerSourceInfo&& rhs);
  PowerSourceInfo& operator=(PowerSourceInfo&& rhs);

  // Populates a PowerSourceInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, PowerSourceInfo* out);

  // Creates a PowerSourceInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<PowerSourceInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PowerSourceInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Type of power source.
  PowerSourceType type;

  // Maximum power this source is capable of delivering if known. Reported in
  // watts, rounded to two significant digits.
  std::unique_ptr<double> max_power;

  // Whether this power source is connected to the device.
  bool active;


 private:
  DISALLOW_COPY_AND_ASSIGN(PowerSourceInfo);
};


//
// Functions
//

namespace GetPowerSourceInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<PowerSourceInfo>& power_source_info);
}  // namespace Results

}  // namespace GetPowerSourceInfo

namespace RequestStatusUpdate {

}  // namespace RequestStatusUpdate

//
// Events
//

namespace OnPowerChanged {

extern const char kEventName[];  // "system.powerSource.onPowerChanged"

std::unique_ptr<base::ListValue> Create(const std::vector<PowerSourceInfo>& power_source_info);
}  // namespace OnPowerChanged

}  // namespace system_power_source
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SYSTEM_POWER_SOURCE_H__
