// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CAST_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CAST_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_cast.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<cast::Sink> {
  static std::unique_ptr<cast::Sink> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::Sink::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::Sink& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::EnableParams> {
  static std::unique_ptr<cast::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::EnableResult> {
  static std::unique_ptr<cast::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::DisableParams> {
  static std::unique_ptr<cast::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::DisableResult> {
  static std::unique_ptr<cast::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::SetSinkToUseParams> {
  static std::unique_ptr<cast::SetSinkToUseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::SetSinkToUseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::SetSinkToUseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::SetSinkToUseResult> {
  static std::unique_ptr<cast::SetSinkToUseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::SetSinkToUseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::SetSinkToUseResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::StartTabMirroringParams> {
  static std::unique_ptr<cast::StartTabMirroringParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::StartTabMirroringParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::StartTabMirroringParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::StartTabMirroringResult> {
  static std::unique_ptr<cast::StartTabMirroringResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::StartTabMirroringResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::StartTabMirroringResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::StopCastingParams> {
  static std::unique_ptr<cast::StopCastingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::StopCastingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::StopCastingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::StopCastingResult> {
  static std::unique_ptr<cast::StopCastingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::StopCastingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::StopCastingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::SinksUpdatedParams> {
  static std::unique_ptr<cast::SinksUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::SinksUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::SinksUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cast::IssueUpdatedParams> {
  static std::unique_ptr<cast::IssueUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cast::IssueUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cast::IssueUpdatedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CAST_H_
