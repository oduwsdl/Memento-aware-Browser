// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_EMULATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_EMULATION_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace emulation {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Notification sent after the virtual time budget for the current VirtualTimePolicy has run out.
  virtual void OnVirtualTimeBudgetExpired(const VirtualTimeBudgetExpiredParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: Notification sent after the virtual time budget for the current VirtualTimePolicy has run out.
  virtual void OnVirtualTimeBudgetExpired(const VirtualTimeBudgetExpiredParams& params) final {}
};

// This domain emulates different environments for the page.
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Tells whether emulation is supported.
  void CanEmulate(std::unique_ptr<CanEmulateParams> params, base::OnceCallback<void(std::unique_ptr<CanEmulateResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanEmulateResult>)>());
  void CanEmulate(base::OnceCallback<void(std::unique_ptr<CanEmulateResult>)> callback = base::OnceCallback<void(std::unique_ptr<CanEmulateResult>)>());

  // Clears the overriden device metrics.
  void ClearDeviceMetricsOverride(std::unique_ptr<ClearDeviceMetricsOverrideParams> params, base::OnceCallback<void(std::unique_ptr<ClearDeviceMetricsOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearDeviceMetricsOverrideResult>)>());
  void ClearDeviceMetricsOverride(base::OnceClosure callback = base::OnceClosure());
  void ClearDeviceMetricsOverride(std::unique_ptr<ClearDeviceMetricsOverrideParams> params, base::OnceClosure callback);

  // Clears the overriden Geolocation Position and Error.
  void ClearGeolocationOverride(std::unique_ptr<ClearGeolocationOverrideParams> params, base::OnceCallback<void(std::unique_ptr<ClearGeolocationOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearGeolocationOverrideResult>)>());
  void ClearGeolocationOverride(base::OnceClosure callback = base::OnceClosure());
  void ClearGeolocationOverride(std::unique_ptr<ClearGeolocationOverrideParams> params, base::OnceClosure callback);

  // Sets or clears an override of the default background color of the frame. This override is used
  // if the content does not specify one.
  void SetDefaultBackgroundColorOverride(std::unique_ptr<SetDefaultBackgroundColorOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetDefaultBackgroundColorOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDefaultBackgroundColorOverrideResult>)>());
  void SetDefaultBackgroundColorOverride(base::OnceClosure callback = base::OnceClosure());
  void SetDefaultBackgroundColorOverride(std::unique_ptr<SetDefaultBackgroundColorOverrideParams> params, base::OnceClosure callback);

  // Overrides the values of device screen dimensions (window.screen.width, window.screen.height,
  // window.innerWidth, window.innerHeight, and "device-width"/"device-height"-related CSS media
  // query results).
  void SetDeviceMetricsOverride(std::unique_ptr<SetDeviceMetricsOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetDeviceMetricsOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDeviceMetricsOverrideResult>)>());
  void SetDeviceMetricsOverride(int width, int height, double device_scale_factor, bool mobile, base::OnceClosure callback = base::OnceClosure());
  void SetDeviceMetricsOverride(std::unique_ptr<SetDeviceMetricsOverrideParams> params, base::OnceClosure callback);

  // Emulates the given media type or media feature for CSS media queries.
  void SetEmulatedMedia(std::unique_ptr<SetEmulatedMediaParams> params, base::OnceCallback<void(std::unique_ptr<SetEmulatedMediaResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetEmulatedMediaResult>)>());
  void SetEmulatedMedia(base::OnceClosure callback = base::OnceClosure());
  void SetEmulatedMedia(std::unique_ptr<SetEmulatedMediaParams> params, base::OnceClosure callback);

  // Overrides the Geolocation Position or Error. Omitting any of the parameters emulates position
  // unavailable.
  void SetGeolocationOverride(std::unique_ptr<SetGeolocationOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetGeolocationOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetGeolocationOverrideResult>)>());
  void SetGeolocationOverride(base::OnceClosure callback = base::OnceClosure());
  void SetGeolocationOverride(std::unique_ptr<SetGeolocationOverrideParams> params, base::OnceClosure callback);

  // Switches script execution in the page.
  void SetScriptExecutionDisabled(std::unique_ptr<SetScriptExecutionDisabledParams> params, base::OnceCallback<void(std::unique_ptr<SetScriptExecutionDisabledResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetScriptExecutionDisabledResult>)>());
  void SetScriptExecutionDisabled(bool value, base::OnceClosure callback = base::OnceClosure());
  void SetScriptExecutionDisabled(std::unique_ptr<SetScriptExecutionDisabledParams> params, base::OnceClosure callback);

  // Enables touch on platforms which do not support them.
  void SetTouchEmulationEnabled(std::unique_ptr<SetTouchEmulationEnabledParams> params, base::OnceCallback<void(std::unique_ptr<SetTouchEmulationEnabledResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetTouchEmulationEnabledResult>)>());
  void SetTouchEmulationEnabled(bool enabled, base::OnceClosure callback = base::OnceClosure());
  void SetTouchEmulationEnabled(std::unique_ptr<SetTouchEmulationEnabledParams> params, base::OnceClosure callback);

  // Allows overriding user agent with the given string.
  void SetUserAgentOverride(std::unique_ptr<SetUserAgentOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)>());
  void SetUserAgentOverride(const std::string& user_agent, base::OnceClosure callback = base::OnceClosure());
  void SetUserAgentOverride(std::unique_ptr<SetUserAgentOverrideParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleCanEmulateResponse(base::OnceCallback<void(std::unique_ptr<CanEmulateResult>)> callback, const base::Value& response);
  static void HandleClearDeviceMetricsOverrideResponse(base::OnceCallback<void(std::unique_ptr<ClearDeviceMetricsOverrideResult>)> callback, const base::Value& response);
  static void HandleClearGeolocationOverrideResponse(base::OnceCallback<void(std::unique_ptr<ClearGeolocationOverrideResult>)> callback, const base::Value& response);
  static void HandleResetPageScaleFactorResponse(base::OnceCallback<void(std::unique_ptr<ResetPageScaleFactorResult>)> callback, const base::Value& response);
  static void HandleSetFocusEmulationEnabledResponse(base::OnceCallback<void(std::unique_ptr<SetFocusEmulationEnabledResult>)> callback, const base::Value& response);
  static void HandleSetCPUThrottlingRateResponse(base::OnceCallback<void(std::unique_ptr<SetCPUThrottlingRateResult>)> callback, const base::Value& response);
  static void HandleSetDefaultBackgroundColorOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetDefaultBackgroundColorOverrideResult>)> callback, const base::Value& response);
  static void HandleSetDeviceMetricsOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetDeviceMetricsOverrideResult>)> callback, const base::Value& response);
  static void HandleSetScrollbarsHiddenResponse(base::OnceCallback<void(std::unique_ptr<SetScrollbarsHiddenResult>)> callback, const base::Value& response);
  static void HandleSetDocumentCookieDisabledResponse(base::OnceCallback<void(std::unique_ptr<SetDocumentCookieDisabledResult>)> callback, const base::Value& response);
  static void HandleSetEmitTouchEventsForMouseResponse(base::OnceCallback<void(std::unique_ptr<SetEmitTouchEventsForMouseResult>)> callback, const base::Value& response);
  static void HandleSetEmulatedMediaResponse(base::OnceCallback<void(std::unique_ptr<SetEmulatedMediaResult>)> callback, const base::Value& response);
  static void HandleSetEmulatedVisionDeficiencyResponse(base::OnceCallback<void(std::unique_ptr<SetEmulatedVisionDeficiencyResult>)> callback, const base::Value& response);
  static void HandleSetGeolocationOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetGeolocationOverrideResult>)> callback, const base::Value& response);
  static void HandleSetNavigatorOverridesResponse(base::OnceCallback<void(std::unique_ptr<SetNavigatorOverridesResult>)> callback, const base::Value& response);
  static void HandleSetPageScaleFactorResponse(base::OnceCallback<void(std::unique_ptr<SetPageScaleFactorResult>)> callback, const base::Value& response);
  static void HandleSetScriptExecutionDisabledResponse(base::OnceCallback<void(std::unique_ptr<SetScriptExecutionDisabledResult>)> callback, const base::Value& response);
  static void HandleSetTouchEmulationEnabledResponse(base::OnceCallback<void(std::unique_ptr<SetTouchEmulationEnabledResult>)> callback, const base::Value& response);
  static void HandleSetVirtualTimePolicyResponse(base::OnceCallback<void(std::unique_ptr<SetVirtualTimePolicyResult>)> callback, const base::Value& response);
  static void HandleSetLocaleOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetLocaleOverrideResult>)> callback, const base::Value& response);
  static void HandleSetTimezoneOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetTimezoneOverrideResult>)> callback, const base::Value& response);
  static void HandleSetVisibleSizeResponse(base::OnceCallback<void(std::unique_ptr<SetVisibleSizeResult>)> callback, const base::Value& response);
  static void HandleSetUserAgentOverrideResponse(base::OnceCallback<void(std::unique_ptr<SetUserAgentOverrideResult>)> callback, const base::Value& response);

  void DispatchVirtualTimeBudgetExpiredEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  // Requests that page scale factor is reset to initial values.
  void ResetPageScaleFactor(std::unique_ptr<ResetPageScaleFactorParams> params, base::OnceCallback<void(std::unique_ptr<ResetPageScaleFactorResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResetPageScaleFactorResult>)>());

  // Enables or disables simulating a focused and active page.
  void SetFocusEmulationEnabled(std::unique_ptr<SetFocusEmulationEnabledParams> params, base::OnceCallback<void(std::unique_ptr<SetFocusEmulationEnabledResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetFocusEmulationEnabledResult>)>());

  // Enables CPU throttling to emulate slow CPUs.
  void SetCPUThrottlingRate(std::unique_ptr<SetCPUThrottlingRateParams> params, base::OnceCallback<void(std::unique_ptr<SetCPUThrottlingRateResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetCPUThrottlingRateResult>)>());

  void SetScrollbarsHidden(std::unique_ptr<SetScrollbarsHiddenParams> params, base::OnceCallback<void(std::unique_ptr<SetScrollbarsHiddenResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetScrollbarsHiddenResult>)>());

  void SetDocumentCookieDisabled(std::unique_ptr<SetDocumentCookieDisabledParams> params, base::OnceCallback<void(std::unique_ptr<SetDocumentCookieDisabledResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDocumentCookieDisabledResult>)>());

  void SetEmitTouchEventsForMouse(std::unique_ptr<SetEmitTouchEventsForMouseParams> params, base::OnceCallback<void(std::unique_ptr<SetEmitTouchEventsForMouseResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetEmitTouchEventsForMouseResult>)>());

  // Emulates the given vision deficiency.
  void SetEmulatedVisionDeficiency(std::unique_ptr<SetEmulatedVisionDeficiencyParams> params, base::OnceCallback<void(std::unique_ptr<SetEmulatedVisionDeficiencyResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetEmulatedVisionDeficiencyResult>)>());

  // Overrides value returned by the javascript navigator object.
  void SetNavigatorOverrides(std::unique_ptr<SetNavigatorOverridesParams> params, base::OnceCallback<void(std::unique_ptr<SetNavigatorOverridesResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetNavigatorOverridesResult>)>());

  // Sets a specified page scale factor.
  void SetPageScaleFactor(std::unique_ptr<SetPageScaleFactorParams> params, base::OnceCallback<void(std::unique_ptr<SetPageScaleFactorResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetPageScaleFactorResult>)>());

  // Turns on virtual time for all frames (replacing real-time with a synthetic time source) and sets
  // the current virtual time policy.  Note this supersedes any previous time budget.
  void SetVirtualTimePolicy(std::unique_ptr<SetVirtualTimePolicyParams> params, base::OnceCallback<void(std::unique_ptr<SetVirtualTimePolicyResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetVirtualTimePolicyResult>)>());

  // Overrides default host system locale with the specified one.
  void SetLocaleOverride(std::unique_ptr<SetLocaleOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetLocaleOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetLocaleOverrideResult>)>());

  // Overrides default host system timezone with the specified one.
  void SetTimezoneOverride(std::unique_ptr<SetTimezoneOverrideParams> params, base::OnceCallback<void(std::unique_ptr<SetTimezoneOverrideResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetTimezoneOverrideResult>)>());

  // Resizes the frame/viewport of the page. Note that this does not affect the frame's container
  // (e.g. browser window). Can be used to produce screenshots of the specified size. Not supported
  // on Android.
  void SetVisibleSize(std::unique_ptr<SetVisibleSizeParams> params, base::OnceCallback<void(std::unique_ptr<SetVisibleSizeResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetVisibleSizeResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace emulation
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_EMULATION_H_
