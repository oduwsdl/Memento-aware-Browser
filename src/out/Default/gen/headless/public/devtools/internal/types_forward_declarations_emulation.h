// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_EMULATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_EMULATION_H_

#include "base/values.h"

namespace headless {

namespace emulation {
class ScreenOrientation;
class MediaFeature;
class UserAgentBrandVersion;
class UserAgentMetadata;
class CanEmulateParams;
class CanEmulateResult;
class ClearDeviceMetricsOverrideParams;
class ClearDeviceMetricsOverrideResult;
class ClearGeolocationOverrideParams;
class ClearGeolocationOverrideResult;
class ResetPageScaleFactorParams;
class ResetPageScaleFactorResult;
class SetFocusEmulationEnabledParams;
class SetFocusEmulationEnabledResult;
class SetCPUThrottlingRateParams;
class SetCPUThrottlingRateResult;
class SetDefaultBackgroundColorOverrideParams;
class SetDefaultBackgroundColorOverrideResult;
class SetDeviceMetricsOverrideParams;
class SetDeviceMetricsOverrideResult;
class SetScrollbarsHiddenParams;
class SetScrollbarsHiddenResult;
class SetDocumentCookieDisabledParams;
class SetDocumentCookieDisabledResult;
class SetEmitTouchEventsForMouseParams;
class SetEmitTouchEventsForMouseResult;
class SetEmulatedMediaParams;
class SetEmulatedMediaResult;
class SetEmulatedVisionDeficiencyParams;
class SetEmulatedVisionDeficiencyResult;
class SetGeolocationOverrideParams;
class SetGeolocationOverrideResult;
class SetNavigatorOverridesParams;
class SetNavigatorOverridesResult;
class SetPageScaleFactorParams;
class SetPageScaleFactorResult;
class SetScriptExecutionDisabledParams;
class SetScriptExecutionDisabledResult;
class SetTouchEmulationEnabledParams;
class SetTouchEmulationEnabledResult;
class SetVirtualTimePolicyParams;
class SetVirtualTimePolicyResult;
class SetLocaleOverrideParams;
class SetLocaleOverrideResult;
class SetTimezoneOverrideParams;
class SetTimezoneOverrideResult;
class SetVisibleSizeParams;
class SetVisibleSizeResult;
class SetUserAgentOverrideParams;
class SetUserAgentOverrideResult;
class VirtualTimeBudgetExpiredParams;

enum class VirtualTimePolicy {
  ADVANCE,
  PAUSE,
  PAUSE_IF_NETWORK_FETCHES_PENDING
};

enum class ScreenOrientationType {
  PORTRAIT_PRIMARY,
  PORTRAIT_SECONDARY,
  LANDSCAPE_PRIMARY,
  LANDSCAPE_SECONDARY
};

enum class SetEmitTouchEventsForMouseConfiguration {
  MOBILE,
  DESKTOP
};

enum class SetEmulatedVisionDeficiencyType {
  NONE,
  ACHROMATOPSIA,
  BLURRED_VISION,
  DEUTERANOPIA,
  PROTANOPIA,
  TRITANOPIA
};

}  // namespace emulation

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_EMULATION_H_
