// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INSPECTOR_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INSPECTOR_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_inspector.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<inspector::DisableParams> {
  static std::unique_ptr<inspector::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return inspector::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const inspector::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<inspector::DisableResult> {
  static std::unique_ptr<inspector::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return inspector::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const inspector::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<inspector::EnableParams> {
  static std::unique_ptr<inspector::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return inspector::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const inspector::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<inspector::EnableResult> {
  static std::unique_ptr<inspector::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return inspector::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const inspector::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<inspector::DetachedParams> {
  static std::unique_ptr<inspector::DetachedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return inspector::DetachedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const inspector::DetachedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<inspector::TargetCrashedParams> {
  static std::unique_ptr<inspector::TargetCrashedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return inspector::TargetCrashedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const inspector::TargetCrashedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<inspector::TargetReloadedAfterCrashParams> {
  static std::unique_ptr<inspector::TargetReloadedAfterCrashParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return inspector::TargetReloadedAfterCrashParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const inspector::TargetReloadedAfterCrashParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INSPECTOR_H_
