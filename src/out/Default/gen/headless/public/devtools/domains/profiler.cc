// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/profiler.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace profiler {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}

void Domain::AddObserver(Observer* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void Domain::RemoveObserver(Observer* observer) {
  observers_.RemoveObserver(observer);
}

void Domain::RegisterEventHandlersIfNeeded() {
  if (event_handlers_registered_)
    return;
  event_handlers_registered_ = true;
  dispatcher_->RegisterEventHandler(
      "Profiler.consoleProfileFinished",
      base::BindRepeating(&Domain::DispatchConsoleProfileFinishedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Profiler.consoleProfileStarted",
      base::BindRepeating(&Domain::DispatchConsoleProfileStartedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Profiler.preciseCoverageDeltaUpdate",
      base::BindRepeating(&Domain::DispatchPreciseCoverageDeltaUpdateEvent,
                          base::Unretained(this)));
}

void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Profiler.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}

void Domain::Disable(base::OnceClosure callback) {
  std::unique_ptr<DisableParams> params = DisableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Profiler.disable", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Profiler.disable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Profiler.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}

void Domain::Enable(base::OnceClosure callback) {
  std::unique_ptr<EnableParams> params = EnableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Profiler.enable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Profiler.enable", params->Serialize(), std::move(callback));
}
void Domain::GetBestEffortCoverage(std::unique_ptr<GetBestEffortCoverageParams> params, base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)> callback) {
  dispatcher_->SendMessage("Profiler.getBestEffortCoverage", params->Serialize(), base::BindOnce(&Domain::HandleGetBestEffortCoverageResponse, std::move(callback)));
}

void Domain::GetBestEffortCoverage(base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)> callback) {
  std::unique_ptr<GetBestEffortCoverageParams> params = GetBestEffortCoverageParams::Builder()
      .Build();
dispatcher_->SendMessage("Profiler.getBestEffortCoverage", params->Serialize(), base::BindOnce(&Domain::HandleGetBestEffortCoverageResponse, std::move(callback)));
}
void Domain::SetSamplingInterval(std::unique_ptr<SetSamplingIntervalParams> params, base::OnceCallback<void(std::unique_ptr<SetSamplingIntervalResult>)> callback) {
  dispatcher_->SendMessage("Profiler.setSamplingInterval", params->Serialize(), base::BindOnce(&Domain::HandleSetSamplingIntervalResponse, std::move(callback)));
}

void Domain::SetSamplingInterval(int interval, base::OnceClosure callback) {
  std::unique_ptr<SetSamplingIntervalParams> params = SetSamplingIntervalParams::Builder()
      .SetInterval(std::move(interval))
      .Build();
  dispatcher_->SendMessage("Profiler.setSamplingInterval", params->Serialize(), std::move(callback));
}
void Domain::SetSamplingInterval(std::unique_ptr<SetSamplingIntervalParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Profiler.setSamplingInterval", params->Serialize(), std::move(callback));
}
void Domain::Start(std::unique_ptr<StartParams> params, base::OnceCallback<void(std::unique_ptr<StartResult>)> callback) {
  dispatcher_->SendMessage("Profiler.start", params->Serialize(), base::BindOnce(&Domain::HandleStartResponse, std::move(callback)));
}

void Domain::Start(base::OnceClosure callback) {
  std::unique_ptr<StartParams> params = StartParams::Builder()
      .Build();
  dispatcher_->SendMessage("Profiler.start", params->Serialize(), std::move(callback));
}
void Domain::Start(std::unique_ptr<StartParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Profiler.start", params->Serialize(), std::move(callback));
}
void Domain::StartPreciseCoverage(std::unique_ptr<StartPreciseCoverageParams> params, base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)> callback) {
  dispatcher_->SendMessage("Profiler.startPreciseCoverage", params->Serialize(), base::BindOnce(&Domain::HandleStartPreciseCoverageResponse, std::move(callback)));
}

void Domain::StartPreciseCoverage(base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)> callback) {
  std::unique_ptr<StartPreciseCoverageParams> params = StartPreciseCoverageParams::Builder()
      .Build();
dispatcher_->SendMessage("Profiler.startPreciseCoverage", params->Serialize(), base::BindOnce(&Domain::HandleStartPreciseCoverageResponse, std::move(callback)));
}
void ExperimentalDomain::StartTypeProfile(std::unique_ptr<StartTypeProfileParams> params, base::OnceCallback<void(std::unique_ptr<StartTypeProfileResult>)> callback) {
  dispatcher_->SendMessage("Profiler.startTypeProfile", params->Serialize(), base::BindOnce(&Domain::HandleStartTypeProfileResponse, std::move(callback)));
}
void Domain::Stop(std::unique_ptr<StopParams> params, base::OnceCallback<void(std::unique_ptr<StopResult>)> callback) {
  dispatcher_->SendMessage("Profiler.stop", params->Serialize(), base::BindOnce(&Domain::HandleStopResponse, std::move(callback)));
}

void Domain::Stop(base::OnceCallback<void(std::unique_ptr<StopResult>)> callback) {
  std::unique_ptr<StopParams> params = StopParams::Builder()
      .Build();
dispatcher_->SendMessage("Profiler.stop", params->Serialize(), base::BindOnce(&Domain::HandleStopResponse, std::move(callback)));
}
void Domain::StopPreciseCoverage(std::unique_ptr<StopPreciseCoverageParams> params, base::OnceCallback<void(std::unique_ptr<StopPreciseCoverageResult>)> callback) {
  dispatcher_->SendMessage("Profiler.stopPreciseCoverage", params->Serialize(), base::BindOnce(&Domain::HandleStopPreciseCoverageResponse, std::move(callback)));
}

void Domain::StopPreciseCoverage(base::OnceClosure callback) {
  std::unique_ptr<StopPreciseCoverageParams> params = StopPreciseCoverageParams::Builder()
      .Build();
  dispatcher_->SendMessage("Profiler.stopPreciseCoverage", params->Serialize(), std::move(callback));
}
void Domain::StopPreciseCoverage(std::unique_ptr<StopPreciseCoverageParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Profiler.stopPreciseCoverage", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::StopTypeProfile(std::unique_ptr<StopTypeProfileParams> params, base::OnceCallback<void(std::unique_ptr<StopTypeProfileResult>)> callback) {
  dispatcher_->SendMessage("Profiler.stopTypeProfile", params->Serialize(), base::BindOnce(&Domain::HandleStopTypeProfileResponse, std::move(callback)));
}
void Domain::TakePreciseCoverage(std::unique_ptr<TakePreciseCoverageParams> params, base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)> callback) {
  dispatcher_->SendMessage("Profiler.takePreciseCoverage", params->Serialize(), base::BindOnce(&Domain::HandleTakePreciseCoverageResponse, std::move(callback)));
}

void Domain::TakePreciseCoverage(base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)> callback) {
  std::unique_ptr<TakePreciseCoverageParams> params = TakePreciseCoverageParams::Builder()
      .Build();
dispatcher_->SendMessage("Profiler.takePreciseCoverage", params->Serialize(), base::BindOnce(&Domain::HandleTakePreciseCoverageResponse, std::move(callback)));
}
void ExperimentalDomain::TakeTypeProfile(std::unique_ptr<TakeTypeProfileParams> params, base::OnceCallback<void(std::unique_ptr<TakeTypeProfileResult>)> callback) {
  dispatcher_->SendMessage("Profiler.takeTypeProfile", params->Serialize(), base::BindOnce(&Domain::HandleTakeTypeProfileResponse, std::move(callback)));
}
void ExperimentalDomain::EnableRuntimeCallStats(std::unique_ptr<EnableRuntimeCallStatsParams> params, base::OnceCallback<void(std::unique_ptr<EnableRuntimeCallStatsResult>)> callback) {
  dispatcher_->SendMessage("Profiler.enableRuntimeCallStats", params->Serialize(), base::BindOnce(&Domain::HandleEnableRuntimeCallStatsResponse, std::move(callback)));
}
void ExperimentalDomain::DisableRuntimeCallStats(std::unique_ptr<DisableRuntimeCallStatsParams> params, base::OnceCallback<void(std::unique_ptr<DisableRuntimeCallStatsResult>)> callback) {
  dispatcher_->SendMessage("Profiler.disableRuntimeCallStats", params->Serialize(), base::BindOnce(&Domain::HandleDisableRuntimeCallStatsResponse, std::move(callback)));
}
void ExperimentalDomain::GetRuntimeCallStats(std::unique_ptr<GetRuntimeCallStatsParams> params, base::OnceCallback<void(std::unique_ptr<GetRuntimeCallStatsResult>)> callback) {
  dispatcher_->SendMessage("Profiler.getRuntimeCallStats", params->Serialize(), base::BindOnce(&Domain::HandleGetRuntimeCallStatsResponse, std::move(callback)));
}


// static
void Domain::HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = DisableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = EnableResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetBestEffortCoverageResponse(base::OnceCallback<void(std::unique_ptr<GetBestEffortCoverageResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetBestEffortCoverageResult> result = GetBestEffortCoverageResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetSamplingIntervalResponse(base::OnceCallback<void(std::unique_ptr<SetSamplingIntervalResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetSamplingIntervalResult> result = SetSamplingIntervalResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStartResponse(base::OnceCallback<void(std::unique_ptr<StartResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StartResult> result = StartResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStartPreciseCoverageResponse(base::OnceCallback<void(std::unique_ptr<StartPreciseCoverageResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StartPreciseCoverageResult> result = StartPreciseCoverageResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStartTypeProfileResponse(base::OnceCallback<void(std::unique_ptr<StartTypeProfileResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StartTypeProfileResult> result = StartTypeProfileResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStopResponse(base::OnceCallback<void(std::unique_ptr<StopResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StopResult> result = StopResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStopPreciseCoverageResponse(base::OnceCallback<void(std::unique_ptr<StopPreciseCoverageResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StopPreciseCoverageResult> result = StopPreciseCoverageResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStopTypeProfileResponse(base::OnceCallback<void(std::unique_ptr<StopTypeProfileResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StopTypeProfileResult> result = StopTypeProfileResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleTakePreciseCoverageResponse(base::OnceCallback<void(std::unique_ptr<TakePreciseCoverageResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<TakePreciseCoverageResult> result = TakePreciseCoverageResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleTakeTypeProfileResponse(base::OnceCallback<void(std::unique_ptr<TakeTypeProfileResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<TakeTypeProfileResult> result = TakeTypeProfileResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleEnableRuntimeCallStatsResponse(base::OnceCallback<void(std::unique_ptr<EnableRuntimeCallStatsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EnableRuntimeCallStatsResult> result = EnableRuntimeCallStatsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleDisableRuntimeCallStatsResponse(base::OnceCallback<void(std::unique_ptr<DisableRuntimeCallStatsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<DisableRuntimeCallStatsResult> result = DisableRuntimeCallStatsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetRuntimeCallStatsResponse(base::OnceCallback<void(std::unique_ptr<GetRuntimeCallStatsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetRuntimeCallStatsResult> result = GetRuntimeCallStatsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchConsoleProfileFinishedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ConsoleProfileFinishedParams> parsed_params(ConsoleProfileFinishedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnConsoleProfileFinished(*parsed_params);
  }
}

void Domain::DispatchConsoleProfileStartedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ConsoleProfileStartedParams> parsed_params(ConsoleProfileStartedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnConsoleProfileStarted(*parsed_params);
  }
}

void Domain::DispatchPreciseCoverageDeltaUpdateEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<PreciseCoverageDeltaUpdateParams> parsed_params(PreciseCoverageDeltaUpdateParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnPreciseCoverageDeltaUpdate(*parsed_params);
  }
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}

void ExperimentalDomain::AddObserver(ExperimentalObserver* observer) {
  RegisterEventHandlersIfNeeded();
  observers_.AddObserver(observer);
}

void ExperimentalDomain::RemoveObserver(ExperimentalObserver* observer) {
  observers_.RemoveObserver(observer);
}

}  // namespace profiler

} // namespace headless
