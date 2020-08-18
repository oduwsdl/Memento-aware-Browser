// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_SERVICE_WORKER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_SERVICE_WORKER_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_service_worker.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {



template <>
struct FromValue<service_worker::ServiceWorkerRegistration> {
  static std::unique_ptr<service_worker::ServiceWorkerRegistration> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::ServiceWorkerRegistration::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::ServiceWorkerRegistration& value) {
  return value.Serialize();
}

template <>
struct FromValue<service_worker::ServiceWorkerVersionRunningStatus> {
  static service_worker::ServiceWorkerVersionRunningStatus Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return service_worker::ServiceWorkerVersionRunningStatus::STOPPED;
    }
    if (value.GetString() == "stopped")
      return service_worker::ServiceWorkerVersionRunningStatus::STOPPED;
    if (value.GetString() == "starting")
      return service_worker::ServiceWorkerVersionRunningStatus::STARTING;
    if (value.GetString() == "running")
      return service_worker::ServiceWorkerVersionRunningStatus::RUNNING;
    if (value.GetString() == "stopping")
      return service_worker::ServiceWorkerVersionRunningStatus::STOPPING;
    errors->AddError("invalid enum value");
    return service_worker::ServiceWorkerVersionRunningStatus::STOPPED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::ServiceWorkerVersionRunningStatus& value) {
  switch (value) {
    case service_worker::ServiceWorkerVersionRunningStatus::STOPPED:
      return std::make_unique<base::Value>("stopped");
    case service_worker::ServiceWorkerVersionRunningStatus::STARTING:
      return std::make_unique<base::Value>("starting");
    case service_worker::ServiceWorkerVersionRunningStatus::RUNNING:
      return std::make_unique<base::Value>("running");
    case service_worker::ServiceWorkerVersionRunningStatus::STOPPING:
      return std::make_unique<base::Value>("stopping");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<service_worker::ServiceWorkerVersionStatus> {
  static service_worker::ServiceWorkerVersionStatus Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return service_worker::ServiceWorkerVersionStatus::NEW;
    }
    if (value.GetString() == "new")
      return service_worker::ServiceWorkerVersionStatus::NEW;
    if (value.GetString() == "installing")
      return service_worker::ServiceWorkerVersionStatus::INSTALLING;
    if (value.GetString() == "installed")
      return service_worker::ServiceWorkerVersionStatus::INSTALLED;
    if (value.GetString() == "activating")
      return service_worker::ServiceWorkerVersionStatus::ACTIVATING;
    if (value.GetString() == "activated")
      return service_worker::ServiceWorkerVersionStatus::ACTIVATED;
    if (value.GetString() == "redundant")
      return service_worker::ServiceWorkerVersionStatus::REDUNDANT;
    errors->AddError("invalid enum value");
    return service_worker::ServiceWorkerVersionStatus::NEW;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::ServiceWorkerVersionStatus& value) {
  switch (value) {
    case service_worker::ServiceWorkerVersionStatus::NEW:
      return std::make_unique<base::Value>("new");
    case service_worker::ServiceWorkerVersionStatus::INSTALLING:
      return std::make_unique<base::Value>("installing");
    case service_worker::ServiceWorkerVersionStatus::INSTALLED:
      return std::make_unique<base::Value>("installed");
    case service_worker::ServiceWorkerVersionStatus::ACTIVATING:
      return std::make_unique<base::Value>("activating");
    case service_worker::ServiceWorkerVersionStatus::ACTIVATED:
      return std::make_unique<base::Value>("activated");
    case service_worker::ServiceWorkerVersionStatus::REDUNDANT:
      return std::make_unique<base::Value>("redundant");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<service_worker::ServiceWorkerVersion> {
  static std::unique_ptr<service_worker::ServiceWorkerVersion> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::ServiceWorkerVersion::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::ServiceWorkerVersion& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::ServiceWorkerErrorMessage> {
  static std::unique_ptr<service_worker::ServiceWorkerErrorMessage> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::ServiceWorkerErrorMessage::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::ServiceWorkerErrorMessage& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DeliverPushMessageParams> {
  static std::unique_ptr<service_worker::DeliverPushMessageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DeliverPushMessageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DeliverPushMessageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DeliverPushMessageResult> {
  static std::unique_ptr<service_worker::DeliverPushMessageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DeliverPushMessageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DeliverPushMessageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DisableParams> {
  static std::unique_ptr<service_worker::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DisableResult> {
  static std::unique_ptr<service_worker::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DispatchSyncEventParams> {
  static std::unique_ptr<service_worker::DispatchSyncEventParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DispatchSyncEventParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DispatchSyncEventParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DispatchSyncEventResult> {
  static std::unique_ptr<service_worker::DispatchSyncEventResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DispatchSyncEventResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DispatchSyncEventResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DispatchPeriodicSyncEventParams> {
  static std::unique_ptr<service_worker::DispatchPeriodicSyncEventParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DispatchPeriodicSyncEventParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DispatchPeriodicSyncEventParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::DispatchPeriodicSyncEventResult> {
  static std::unique_ptr<service_worker::DispatchPeriodicSyncEventResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::DispatchPeriodicSyncEventResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::DispatchPeriodicSyncEventResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::EnableParams> {
  static std::unique_ptr<service_worker::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::EnableResult> {
  static std::unique_ptr<service_worker::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::InspectWorkerParams> {
  static std::unique_ptr<service_worker::InspectWorkerParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::InspectWorkerParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::InspectWorkerParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::InspectWorkerResult> {
  static std::unique_ptr<service_worker::InspectWorkerResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::InspectWorkerResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::InspectWorkerResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::SetForceUpdateOnPageLoadParams> {
  static std::unique_ptr<service_worker::SetForceUpdateOnPageLoadParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::SetForceUpdateOnPageLoadParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::SetForceUpdateOnPageLoadParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::SetForceUpdateOnPageLoadResult> {
  static std::unique_ptr<service_worker::SetForceUpdateOnPageLoadResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::SetForceUpdateOnPageLoadResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::SetForceUpdateOnPageLoadResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::SkipWaitingParams> {
  static std::unique_ptr<service_worker::SkipWaitingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::SkipWaitingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::SkipWaitingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::SkipWaitingResult> {
  static std::unique_ptr<service_worker::SkipWaitingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::SkipWaitingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::SkipWaitingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::StartWorkerParams> {
  static std::unique_ptr<service_worker::StartWorkerParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::StartWorkerParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::StartWorkerParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::StartWorkerResult> {
  static std::unique_ptr<service_worker::StartWorkerResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::StartWorkerResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::StartWorkerResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::StopAllWorkersParams> {
  static std::unique_ptr<service_worker::StopAllWorkersParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::StopAllWorkersParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::StopAllWorkersParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::StopAllWorkersResult> {
  static std::unique_ptr<service_worker::StopAllWorkersResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::StopAllWorkersResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::StopAllWorkersResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::StopWorkerParams> {
  static std::unique_ptr<service_worker::StopWorkerParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::StopWorkerParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::StopWorkerParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::StopWorkerResult> {
  static std::unique_ptr<service_worker::StopWorkerResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::StopWorkerResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::StopWorkerResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::UnregisterParams> {
  static std::unique_ptr<service_worker::UnregisterParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::UnregisterParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::UnregisterParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::UnregisterResult> {
  static std::unique_ptr<service_worker::UnregisterResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::UnregisterResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::UnregisterResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::UpdateRegistrationParams> {
  static std::unique_ptr<service_worker::UpdateRegistrationParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::UpdateRegistrationParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::UpdateRegistrationParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::UpdateRegistrationResult> {
  static std::unique_ptr<service_worker::UpdateRegistrationResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::UpdateRegistrationResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::UpdateRegistrationResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::WorkerErrorReportedParams> {
  static std::unique_ptr<service_worker::WorkerErrorReportedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::WorkerErrorReportedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::WorkerErrorReportedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::WorkerRegistrationUpdatedParams> {
  static std::unique_ptr<service_worker::WorkerRegistrationUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::WorkerRegistrationUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::WorkerRegistrationUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<service_worker::WorkerVersionUpdatedParams> {
  static std::unique_ptr<service_worker::WorkerVersionUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return service_worker::WorkerVersionUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const service_worker::WorkerVersionUpdatedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_SERVICE_WORKER_H_
