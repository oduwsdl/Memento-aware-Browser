// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_PROFILER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_PROFILER_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_profiler.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace profiler {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnConsoleProfileFinished(const ConsoleProfileFinishedParams& params) {}
  // Sent when new profile recording is started using console.profile() call.
  virtual void OnConsoleProfileStarted(const ConsoleProfileStartedParams& params) {}
  // Reports coverage delta since the last poll (either from an event like this, or from
  // `takePreciseCoverage` for the current isolate. May only be sent if precise code
  // coverage has been started. This event can be trigged by the embedder to, for example,
  // trigger collection of coverage data immediatelly at a certain point in time.
  virtual void OnPreciseCoverageDeltaUpdate(const PreciseCoverageDeltaUpdateParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnConsoleProfileFinished(const ConsoleProfileFinishedParams& params) {}
  // Sent when new profile recording is started using console.profile() call.
  virtual void OnConsoleProfileStarted(const ConsoleProfileStartedParams& params) {}
  // Experimental: Reports coverage delta since the last poll (either from an event like this, or from
  // `takePreciseCoverage` for the current isolate. May only be sent if precise code
  // coverage has been started. This event can be trigged by the embedder to, for example,
  // trigger collection of coverage data immediatelly at a certain point in time.
  virtual void OnPreciseCoverageDeltaUpdate(const PreciseCoverageDeltaUpdateParams& params) final {}
};

class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());
  void Disable(base::OnceClosure callback = base::OnceClosure());
  void Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback);

  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());
  void Enable(base::OnceClosure callback = base::OnceClosure());
  void Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback);

  // Collect coverage data for the current isolate. The coverage data may be incomplete due to
  // garbage collection.
  void GetBestEffortCoverage(std::unique_ptr<GetBestEffortCoverageParams> params, base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)>());
  void GetBestEffortCoverage(base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)>());

  // Changes CPU profiler sampling interval. Must be called before CPU profiles recording started.
  void SetSamplingInterval(std::unique_ptr<SetSamplingIntervalParams> params, base::OnceCallback<void(std::unique_ptr<SetSamplingIntervalResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetSamplingIntervalResult>)>());
  void SetSamplingInterval(int interval, base::OnceClosure callback = base::OnceClosure());
  void SetSamplingInterval(std::unique_ptr<SetSamplingIntervalParams> params, base::OnceClosure callback);

  void Start(std::unique_ptr<StartParams> params, base::OnceCallback<void(std::unique_ptr<StartResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartResult>)>());
  void Start(base::OnceClosure callback = base::OnceClosure());
  void Start(std::unique_ptr<StartParams> params, base::OnceClosure callback);

  // Enable precise code coverage. Coverage data for JavaScript executed before enabling precise code
  // coverage may be incomplete. Enabling prevents running optimized code and resets execution
  // counters.
  void StartPreciseCoverage(std::unique_ptr<StartPreciseCoverageParams> params, base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)>());
  void StartPreciseCoverage(base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)>());

  void Stop(std::unique_ptr<StopParams> params, base::OnceCallback<void(std::unique_ptr<StopResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopResult>)>());
  void Stop(base::OnceCallback<void(std::unique_ptr<StopResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopResult>)>());

  // Disable precise code coverage. Disabling releases unnecessary execution count records and allows
  // executing optimized code.
  void StopPreciseCoverage(std::unique_ptr<StopPreciseCoverageParams> params, base::OnceCallback<void(std::unique_ptr<StopPreciseCoverageResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopPreciseCoverageResult>)>());
  void StopPreciseCoverage(base::OnceClosure callback = base::OnceClosure());
  void StopPreciseCoverage(std::unique_ptr<StopPreciseCoverageParams> params, base::OnceClosure callback);

  // Collect coverage data for the current isolate, and resets execution counters. Precise code
  // coverage needs to have started.
  void TakePreciseCoverage(std::unique_ptr<TakePreciseCoverageParams> params, base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)> callback = base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)>());
  void TakePreciseCoverage(base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)> callback = base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)>());

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleGetBestEffortCoverageResponse(base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)> callback, const base::Value& response);
  static void HandleSetSamplingIntervalResponse(base::OnceCallback<void(std::unique_ptr<SetSamplingIntervalResult>)> callback, const base::Value& response);
  static void HandleStartResponse(base::OnceCallback<void(std::unique_ptr<StartResult>)> callback, const base::Value& response);
  static void HandleStartPreciseCoverageResponse(base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)> callback, const base::Value& response);
  static void HandleStartTypeProfileResponse(base::OnceCallback<void(std::unique_ptr<StartTypeProfileResult>)> callback, const base::Value& response);
  static void HandleStopResponse(base::OnceCallback<void(std::unique_ptr<StopResult>)> callback, const base::Value& response);
  static void HandleStopPreciseCoverageResponse(base::OnceCallback<void(std::unique_ptr<StopPreciseCoverageResult>)> callback, const base::Value& response);
  static void HandleStopTypeProfileResponse(base::OnceCallback<void(std::unique_ptr<StopTypeProfileResult>)> callback, const base::Value& response);
  static void HandleTakePreciseCoverageResponse(base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)> callback, const base::Value& response);
  static void HandleTakeTypeProfileResponse(base::OnceCallback<void(std::unique_ptr<TakeTypeProfileResult>)> callback, const base::Value& response);
  static void HandleEnableRuntimeCallStatsResponse(base::OnceCallback<void(std::unique_ptr<EnableRuntimeCallStatsResult>)> callback, const base::Value& response);
  static void HandleDisableRuntimeCallStatsResponse(base::OnceCallback<void(std::unique_ptr<DisableRuntimeCallStatsResult>)> callback, const base::Value& response);
  static void HandleGetRuntimeCallStatsResponse(base::OnceCallback<void(std::unique_ptr<GetRuntimeCallStatsResult>)> callback, const base::Value& response);

  void DispatchConsoleProfileFinishedEvent(const base::Value& params);
  void DispatchConsoleProfileStartedEvent(const base::Value& params);
  void DispatchPreciseCoverageDeltaUpdateEvent(const base::Value& params);

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

  // Enable type profile.
  void StartTypeProfile(std::unique_ptr<StartTypeProfileParams> params, base::OnceCallback<void(std::unique_ptr<StartTypeProfileResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartTypeProfileResult>)>());

  // Disable type profile. Disabling releases type profile data collected so far.
  void StopTypeProfile(std::unique_ptr<StopTypeProfileParams> params, base::OnceCallback<void(std::unique_ptr<StopTypeProfileResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopTypeProfileResult>)>());

  // Collect type profile.
  void TakeTypeProfile(std::unique_ptr<TakeTypeProfileParams> params, base::OnceCallback<void(std::unique_ptr<TakeTypeProfileResult>)> callback = base::OnceCallback<void(std::unique_ptr<TakeTypeProfileResult>)>());

  // Enable run time call stats collection.
  void EnableRuntimeCallStats(std::unique_ptr<EnableRuntimeCallStatsParams> params, base::OnceCallback<void(std::unique_ptr<EnableRuntimeCallStatsResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableRuntimeCallStatsResult>)>());

  // Disable run time call stats collection.
  void DisableRuntimeCallStats(std::unique_ptr<DisableRuntimeCallStatsParams> params, base::OnceCallback<void(std::unique_ptr<DisableRuntimeCallStatsResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableRuntimeCallStatsResult>)>());

  // Retrieve run time call stats.
  void GetRuntimeCallStats(std::unique_ptr<GetRuntimeCallStatsParams> params, base::OnceCallback<void(std::unique_ptr<GetRuntimeCallStatsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetRuntimeCallStatsResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace profiler
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_PROFILER_H_
