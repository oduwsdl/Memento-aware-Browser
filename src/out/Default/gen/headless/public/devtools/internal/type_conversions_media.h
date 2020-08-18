// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_MEDIA_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_MEDIA_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_media.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {




template <>
struct FromValue<media::PlayerMessage> {
  static std::unique_ptr<media::PlayerMessage> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerMessage::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerMessage& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayerProperty> {
  static std::unique_ptr<media::PlayerProperty> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerProperty::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerProperty& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayerEvent> {
  static std::unique_ptr<media::PlayerEvent> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerEvent::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerEvent& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayerError> {
  static std::unique_ptr<media::PlayerError> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerError::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerError& value) {
  return value.Serialize();
}

template <>
struct FromValue<media::PlayerMessageLevel> {
  static media::PlayerMessageLevel Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return media::PlayerMessageLevel::ERR;
    }
    if (value.GetString() == "error")
      return media::PlayerMessageLevel::ERR;
    if (value.GetString() == "warning")
      return media::PlayerMessageLevel::WARNING;
    if (value.GetString() == "info")
      return media::PlayerMessageLevel::INFO;
    if (value.GetString() == "debug")
      return media::PlayerMessageLevel::DEBUG;
    errors->AddError("invalid enum value");
    return media::PlayerMessageLevel::ERR;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerMessageLevel& value) {
  switch (value) {
    case media::PlayerMessageLevel::ERR:
      return std::make_unique<base::Value>("error");
    case media::PlayerMessageLevel::WARNING:
      return std::make_unique<base::Value>("warning");
    case media::PlayerMessageLevel::INFO:
      return std::make_unique<base::Value>("info");
    case media::PlayerMessageLevel::DEBUG:
      return std::make_unique<base::Value>("debug");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<media::PlayerErrorType> {
  static media::PlayerErrorType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return media::PlayerErrorType::PIPELINE_ERROR;
    }
    if (value.GetString() == "pipeline_error")
      return media::PlayerErrorType::PIPELINE_ERROR;
    if (value.GetString() == "media_error")
      return media::PlayerErrorType::MEDIA_ERROR;
    errors->AddError("invalid enum value");
    return media::PlayerErrorType::PIPELINE_ERROR;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerErrorType& value) {
  switch (value) {
    case media::PlayerErrorType::PIPELINE_ERROR:
      return std::make_unique<base::Value>("pipeline_error");
    case media::PlayerErrorType::MEDIA_ERROR:
      return std::make_unique<base::Value>("media_error");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<media::EnableParams> {
  static std::unique_ptr<media::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::EnableResult> {
  static std::unique_ptr<media::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::DisableParams> {
  static std::unique_ptr<media::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::DisableResult> {
  static std::unique_ptr<media::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayerPropertiesChangedParams> {
  static std::unique_ptr<media::PlayerPropertiesChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerPropertiesChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerPropertiesChangedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayerEventsAddedParams> {
  static std::unique_ptr<media::PlayerEventsAddedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerEventsAddedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerEventsAddedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayerMessagesLoggedParams> {
  static std::unique_ptr<media::PlayerMessagesLoggedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerMessagesLoggedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerMessagesLoggedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayerErrorsRaisedParams> {
  static std::unique_ptr<media::PlayerErrorsRaisedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayerErrorsRaisedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayerErrorsRaisedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<media::PlayersCreatedParams> {
  static std::unique_ptr<media::PlayersCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return media::PlayersCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const media::PlayersCreatedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_MEDIA_H_
