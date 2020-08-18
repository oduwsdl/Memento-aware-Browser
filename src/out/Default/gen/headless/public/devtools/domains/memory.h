// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_MEMORY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_MEMORY_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_memory.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace memory {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleGetDOMCountersResponse(base::OnceCallback<void(std::unique_ptr<GetDOMCountersResult>)> callback, const base::Value& response);
  static void HandlePrepareForLeakDetectionResponse(base::OnceCallback<void(std::unique_ptr<PrepareForLeakDetectionResult>)> callback, const base::Value& response);
  static void HandleForciblyPurgeJavaScriptMemoryResponse(base::OnceCallback<void(std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult>)> callback, const base::Value& response);
  static void HandleSetPressureNotificationsSuppressedResponse(base::OnceCallback<void(std::unique_ptr<SetPressureNotificationsSuppressedResult>)> callback, const base::Value& response);
  static void HandleSimulatePressureNotificationResponse(base::OnceCallback<void(std::unique_ptr<SimulatePressureNotificationResult>)> callback, const base::Value& response);
  static void HandleStartSamplingResponse(base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)> callback, const base::Value& response);
  static void HandleStopSamplingResponse(base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)> callback, const base::Value& response);
  static void HandleGetAllTimeSamplingProfileResponse(base::OnceCallback<void(std::unique_ptr<GetAllTimeSamplingProfileResult>)> callback, const base::Value& response);
  static void HandleGetBrowserSamplingProfileResponse(base::OnceCallback<void(std::unique_ptr<GetBrowserSamplingProfileResult>)> callback, const base::Value& response);
  static void HandleGetSamplingProfileResponse(base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  void GetDOMCounters(std::unique_ptr<GetDOMCountersParams> params, base::OnceCallback<void(std::unique_ptr<GetDOMCountersResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetDOMCountersResult>)>());

  void PrepareForLeakDetection(std::unique_ptr<PrepareForLeakDetectionParams> params, base::OnceCallback<void(std::unique_ptr<PrepareForLeakDetectionResult>)> callback = base::OnceCallback<void(std::unique_ptr<PrepareForLeakDetectionResult>)>());

  // Simulate OomIntervention by purging V8 memory.
  void ForciblyPurgeJavaScriptMemory(std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> params, base::OnceCallback<void(std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult>)> callback = base::OnceCallback<void(std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult>)>());

  // Enable/disable suppressing memory pressure notifications in all processes.
  void SetPressureNotificationsSuppressed(std::unique_ptr<SetPressureNotificationsSuppressedParams> params, base::OnceCallback<void(std::unique_ptr<SetPressureNotificationsSuppressedResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetPressureNotificationsSuppressedResult>)>());

  // Simulate a memory pressure notification in all processes.
  void SimulatePressureNotification(std::unique_ptr<SimulatePressureNotificationParams> params, base::OnceCallback<void(std::unique_ptr<SimulatePressureNotificationResult>)> callback = base::OnceCallback<void(std::unique_ptr<SimulatePressureNotificationResult>)>());

  // Start collecting native memory profile.
  void StartSampling(std::unique_ptr<StartSamplingParams> params, base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)>());

  // Stop collecting native memory profile.
  void StopSampling(std::unique_ptr<StopSamplingParams> params, base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)>());

  // Retrieve native memory allocations profile
  // collected since renderer process startup.
  void GetAllTimeSamplingProfile(std::unique_ptr<GetAllTimeSamplingProfileParams> params, base::OnceCallback<void(std::unique_ptr<GetAllTimeSamplingProfileResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetAllTimeSamplingProfileResult>)>());

  // Retrieve native memory allocations profile
  // collected since browser process startup.
  void GetBrowserSamplingProfile(std::unique_ptr<GetBrowserSamplingProfileParams> params, base::OnceCallback<void(std::unique_ptr<GetBrowserSamplingProfileResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetBrowserSamplingProfileResult>)>());

  // Retrieve native memory allocations profile collected since last
  // `startSampling` call.
  void GetSamplingProfile(std::unique_ptr<GetSamplingProfileParams> params, base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace memory
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_MEMORY_H_
