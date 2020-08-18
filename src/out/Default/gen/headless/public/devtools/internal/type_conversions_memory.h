// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_MEMORY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_MEMORY_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_memory.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {

template <>
struct FromValue<memory::PressureLevel> {
  static memory::PressureLevel Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return memory::PressureLevel::MODERATE;
    }
    if (value.GetString() == "moderate")
      return memory::PressureLevel::MODERATE;
    if (value.GetString() == "critical")
      return memory::PressureLevel::CRITICAL;
    errors->AddError("invalid enum value");
    return memory::PressureLevel::MODERATE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::PressureLevel& value) {
  switch (value) {
    case memory::PressureLevel::MODERATE:
      return std::make_unique<base::Value>("moderate");
    case memory::PressureLevel::CRITICAL:
      return std::make_unique<base::Value>("critical");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<memory::SamplingProfileNode> {
  static std::unique_ptr<memory::SamplingProfileNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::SamplingProfileNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::SamplingProfileNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::SamplingProfile> {
  static std::unique_ptr<memory::SamplingProfile> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::SamplingProfile::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::SamplingProfile& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::Module> {
  static std::unique_ptr<memory::Module> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::Module::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::Module& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetDOMCountersParams> {
  static std::unique_ptr<memory::GetDOMCountersParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetDOMCountersParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetDOMCountersParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetDOMCountersResult> {
  static std::unique_ptr<memory::GetDOMCountersResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetDOMCountersResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetDOMCountersResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::PrepareForLeakDetectionParams> {
  static std::unique_ptr<memory::PrepareForLeakDetectionParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::PrepareForLeakDetectionParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::PrepareForLeakDetectionParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::PrepareForLeakDetectionResult> {
  static std::unique_ptr<memory::PrepareForLeakDetectionResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::PrepareForLeakDetectionResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::PrepareForLeakDetectionResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::ForciblyPurgeJavaScriptMemoryParams> {
  static std::unique_ptr<memory::ForciblyPurgeJavaScriptMemoryParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::ForciblyPurgeJavaScriptMemoryParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::ForciblyPurgeJavaScriptMemoryParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::ForciblyPurgeJavaScriptMemoryResult> {
  static std::unique_ptr<memory::ForciblyPurgeJavaScriptMemoryResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::ForciblyPurgeJavaScriptMemoryResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::ForciblyPurgeJavaScriptMemoryResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::SetPressureNotificationsSuppressedParams> {
  static std::unique_ptr<memory::SetPressureNotificationsSuppressedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::SetPressureNotificationsSuppressedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::SetPressureNotificationsSuppressedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::SetPressureNotificationsSuppressedResult> {
  static std::unique_ptr<memory::SetPressureNotificationsSuppressedResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::SetPressureNotificationsSuppressedResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::SetPressureNotificationsSuppressedResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::SimulatePressureNotificationParams> {
  static std::unique_ptr<memory::SimulatePressureNotificationParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::SimulatePressureNotificationParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::SimulatePressureNotificationParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::SimulatePressureNotificationResult> {
  static std::unique_ptr<memory::SimulatePressureNotificationResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::SimulatePressureNotificationResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::SimulatePressureNotificationResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::StartSamplingParams> {
  static std::unique_ptr<memory::StartSamplingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::StartSamplingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::StartSamplingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::StartSamplingResult> {
  static std::unique_ptr<memory::StartSamplingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::StartSamplingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::StartSamplingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::StopSamplingParams> {
  static std::unique_ptr<memory::StopSamplingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::StopSamplingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::StopSamplingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::StopSamplingResult> {
  static std::unique_ptr<memory::StopSamplingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::StopSamplingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::StopSamplingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetAllTimeSamplingProfileParams> {
  static std::unique_ptr<memory::GetAllTimeSamplingProfileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetAllTimeSamplingProfileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetAllTimeSamplingProfileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetAllTimeSamplingProfileResult> {
  static std::unique_ptr<memory::GetAllTimeSamplingProfileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetAllTimeSamplingProfileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetAllTimeSamplingProfileResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetBrowserSamplingProfileParams> {
  static std::unique_ptr<memory::GetBrowserSamplingProfileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetBrowserSamplingProfileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetBrowserSamplingProfileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetBrowserSamplingProfileResult> {
  static std::unique_ptr<memory::GetBrowserSamplingProfileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetBrowserSamplingProfileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetBrowserSamplingProfileResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetSamplingProfileParams> {
  static std::unique_ptr<memory::GetSamplingProfileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetSamplingProfileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetSamplingProfileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<memory::GetSamplingProfileResult> {
  static std::unique_ptr<memory::GetSamplingProfileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return memory::GetSamplingProfileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const memory::GetSamplingProfileResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_MEMORY_H_
