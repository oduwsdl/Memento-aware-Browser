// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_BACKGROUND_SERVICE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_BACKGROUND_SERVICE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_background_service.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {

template <>
struct FromValue<background_service::ServiceName> {
  static background_service::ServiceName Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return background_service::ServiceName::BACKGROUND_FETCH;
    }
    if (value.GetString() == "backgroundFetch")
      return background_service::ServiceName::BACKGROUND_FETCH;
    if (value.GetString() == "backgroundSync")
      return background_service::ServiceName::BACKGROUND_SYNC;
    if (value.GetString() == "pushMessaging")
      return background_service::ServiceName::PUSH_MESSAGING;
    if (value.GetString() == "notifications")
      return background_service::ServiceName::NOTIFICATIONS;
    if (value.GetString() == "paymentHandler")
      return background_service::ServiceName::PAYMENT_HANDLER;
    if (value.GetString() == "periodicBackgroundSync")
      return background_service::ServiceName::PERIODIC_BACKGROUND_SYNC;
    errors->AddError("invalid enum value");
    return background_service::ServiceName::BACKGROUND_FETCH;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::ServiceName& value) {
  switch (value) {
    case background_service::ServiceName::BACKGROUND_FETCH:
      return std::make_unique<base::Value>("backgroundFetch");
    case background_service::ServiceName::BACKGROUND_SYNC:
      return std::make_unique<base::Value>("backgroundSync");
    case background_service::ServiceName::PUSH_MESSAGING:
      return std::make_unique<base::Value>("pushMessaging");
    case background_service::ServiceName::NOTIFICATIONS:
      return std::make_unique<base::Value>("notifications");
    case background_service::ServiceName::PAYMENT_HANDLER:
      return std::make_unique<base::Value>("paymentHandler");
    case background_service::ServiceName::PERIODIC_BACKGROUND_SYNC:
      return std::make_unique<base::Value>("periodicBackgroundSync");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<background_service::EventMetadata> {
  static std::unique_ptr<background_service::EventMetadata> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::EventMetadata::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::EventMetadata& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::BackgroundServiceEvent> {
  static std::unique_ptr<background_service::BackgroundServiceEvent> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::BackgroundServiceEvent::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::BackgroundServiceEvent& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::StartObservingParams> {
  static std::unique_ptr<background_service::StartObservingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::StartObservingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::StartObservingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::StartObservingResult> {
  static std::unique_ptr<background_service::StartObservingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::StartObservingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::StartObservingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::StopObservingParams> {
  static std::unique_ptr<background_service::StopObservingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::StopObservingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::StopObservingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::StopObservingResult> {
  static std::unique_ptr<background_service::StopObservingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::StopObservingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::StopObservingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::SetRecordingParams> {
  static std::unique_ptr<background_service::SetRecordingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::SetRecordingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::SetRecordingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::SetRecordingResult> {
  static std::unique_ptr<background_service::SetRecordingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::SetRecordingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::SetRecordingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::ClearEventsParams> {
  static std::unique_ptr<background_service::ClearEventsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::ClearEventsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::ClearEventsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::ClearEventsResult> {
  static std::unique_ptr<background_service::ClearEventsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::ClearEventsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::ClearEventsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::RecordingStateChangedParams> {
  static std::unique_ptr<background_service::RecordingStateChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::RecordingStateChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::RecordingStateChangedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<background_service::BackgroundServiceEventReceivedParams> {
  static std::unique_ptr<background_service::BackgroundServiceEventReceivedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return background_service::BackgroundServiceEventReceivedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const background_service::BackgroundServiceEventReceivedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_BACKGROUND_SERVICE_H_
