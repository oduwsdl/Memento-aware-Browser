// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_SERVICE_WORKER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_SERVICE_WORKER_H_

#include "base/values.h"

namespace headless {

namespace service_worker {
class ServiceWorkerRegistration;
class ServiceWorkerVersion;
class ServiceWorkerErrorMessage;
class DeliverPushMessageParams;
class DeliverPushMessageResult;
class DisableParams;
class DisableResult;
class DispatchSyncEventParams;
class DispatchSyncEventResult;
class DispatchPeriodicSyncEventParams;
class DispatchPeriodicSyncEventResult;
class EnableParams;
class EnableResult;
class InspectWorkerParams;
class InspectWorkerResult;
class SetForceUpdateOnPageLoadParams;
class SetForceUpdateOnPageLoadResult;
class SkipWaitingParams;
class SkipWaitingResult;
class StartWorkerParams;
class StartWorkerResult;
class StopAllWorkersParams;
class StopAllWorkersResult;
class StopWorkerParams;
class StopWorkerResult;
class UnregisterParams;
class UnregisterResult;
class UpdateRegistrationParams;
class UpdateRegistrationResult;
class WorkerErrorReportedParams;
class WorkerRegistrationUpdatedParams;
class WorkerVersionUpdatedParams;

enum class ServiceWorkerVersionRunningStatus {
  STOPPED,
  STARTING,
  RUNNING,
  STOPPING
};

enum class ServiceWorkerVersionStatus {
  NEW,
  INSTALLING,
  INSTALLED,
  ACTIVATING,
  ACTIVATED,
  REDUNDANT
};

}  // namespace service_worker

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_SERVICE_WORKER_H_
