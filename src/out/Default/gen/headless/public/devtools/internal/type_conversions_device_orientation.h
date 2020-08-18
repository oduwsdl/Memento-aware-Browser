// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DEVICE_ORIENTATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DEVICE_ORIENTATION_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_device_orientation.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<device_orientation::ClearDeviceOrientationOverrideParams> {
  static std::unique_ptr<device_orientation::ClearDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return device_orientation::ClearDeviceOrientationOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const device_orientation::ClearDeviceOrientationOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<device_orientation::ClearDeviceOrientationOverrideResult> {
  static std::unique_ptr<device_orientation::ClearDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return device_orientation::ClearDeviceOrientationOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const device_orientation::ClearDeviceOrientationOverrideResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<device_orientation::SetDeviceOrientationOverrideParams> {
  static std::unique_ptr<device_orientation::SetDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return device_orientation::SetDeviceOrientationOverrideParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const device_orientation::SetDeviceOrientationOverrideParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<device_orientation::SetDeviceOrientationOverrideResult> {
  static std::unique_ptr<device_orientation::SetDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return device_orientation::SetDeviceOrientationOverrideResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const device_orientation::SetDeviceOrientationOverrideResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DEVICE_ORIENTATION_H_
