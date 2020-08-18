// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_BACKGROUND_SERVICE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_BACKGROUND_SERVICE_H_

#include "base/values.h"

namespace headless {

namespace background_service {
class EventMetadata;
class BackgroundServiceEvent;
class StartObservingParams;
class StartObservingResult;
class StopObservingParams;
class StopObservingResult;
class SetRecordingParams;
class SetRecordingResult;
class ClearEventsParams;
class ClearEventsResult;
class RecordingStateChangedParams;
class BackgroundServiceEventReceivedParams;

enum class ServiceName {
  BACKGROUND_FETCH,
  BACKGROUND_SYNC,
  PUSH_MESSAGING,
  NOTIFICATIONS,
  PAYMENT_HANDLER,
  PERIODIC_BACKGROUND_SYNC
};

}  // namespace background_service

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_BACKGROUND_SERVICE_H_
