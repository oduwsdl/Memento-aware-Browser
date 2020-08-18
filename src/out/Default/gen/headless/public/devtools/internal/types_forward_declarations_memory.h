// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_MEMORY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_MEMORY_H_

#include "base/values.h"

namespace headless {

namespace memory {
class SamplingProfileNode;
class SamplingProfile;
class Module;
class GetDOMCountersParams;
class GetDOMCountersResult;
class PrepareForLeakDetectionParams;
class PrepareForLeakDetectionResult;
class ForciblyPurgeJavaScriptMemoryParams;
class ForciblyPurgeJavaScriptMemoryResult;
class SetPressureNotificationsSuppressedParams;
class SetPressureNotificationsSuppressedResult;
class SimulatePressureNotificationParams;
class SimulatePressureNotificationResult;
class StartSamplingParams;
class StartSamplingResult;
class StopSamplingParams;
class StopSamplingResult;
class GetAllTimeSamplingProfileParams;
class GetAllTimeSamplingProfileResult;
class GetBrowserSamplingProfileParams;
class GetBrowserSamplingProfileResult;
class GetSamplingProfileParams;
class GetSamplingProfileResult;

enum class PressureLevel {
  MODERATE,
  CRITICAL
};

}  // namespace memory

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_MEMORY_H_
