// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/memory.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace memory {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}


void ExperimentalDomain::GetDOMCounters(std::unique_ptr<GetDOMCountersParams> params, base::OnceCallback<void(std::unique_ptr<GetDOMCountersResult>)> callback) {
  dispatcher_->SendMessage("Memory.getDOMCounters", params->Serialize(), base::BindOnce(&Domain::HandleGetDOMCountersResponse, std::move(callback)));
}
void ExperimentalDomain::PrepareForLeakDetection(std::unique_ptr<PrepareForLeakDetectionParams> params, base::OnceCallback<void(std::unique_ptr<PrepareForLeakDetectionResult>)> callback) {
  dispatcher_->SendMessage("Memory.prepareForLeakDetection", params->Serialize(), base::BindOnce(&Domain::HandlePrepareForLeakDetectionResponse, std::move(callback)));
}
void ExperimentalDomain::ForciblyPurgeJavaScriptMemory(std::unique_ptr<ForciblyPurgeJavaScriptMemoryParams> params, base::OnceCallback<void(std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult>)> callback) {
  dispatcher_->SendMessage("Memory.forciblyPurgeJavaScriptMemory", params->Serialize(), base::BindOnce(&Domain::HandleForciblyPurgeJavaScriptMemoryResponse, std::move(callback)));
}
void ExperimentalDomain::SetPressureNotificationsSuppressed(std::unique_ptr<SetPressureNotificationsSuppressedParams> params, base::OnceCallback<void(std::unique_ptr<SetPressureNotificationsSuppressedResult>)> callback) {
  dispatcher_->SendMessage("Memory.setPressureNotificationsSuppressed", params->Serialize(), base::BindOnce(&Domain::HandleSetPressureNotificationsSuppressedResponse, std::move(callback)));
}
void ExperimentalDomain::SimulatePressureNotification(std::unique_ptr<SimulatePressureNotificationParams> params, base::OnceCallback<void(std::unique_ptr<SimulatePressureNotificationResult>)> callback) {
  dispatcher_->SendMessage("Memory.simulatePressureNotification", params->Serialize(), base::BindOnce(&Domain::HandleSimulatePressureNotificationResponse, std::move(callback)));
}
void ExperimentalDomain::StartSampling(std::unique_ptr<StartSamplingParams> params, base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)> callback) {
  dispatcher_->SendMessage("Memory.startSampling", params->Serialize(), base::BindOnce(&Domain::HandleStartSamplingResponse, std::move(callback)));
}
void ExperimentalDomain::StopSampling(std::unique_ptr<StopSamplingParams> params, base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)> callback) {
  dispatcher_->SendMessage("Memory.stopSampling", params->Serialize(), base::BindOnce(&Domain::HandleStopSamplingResponse, std::move(callback)));
}
void ExperimentalDomain::GetAllTimeSamplingProfile(std::unique_ptr<GetAllTimeSamplingProfileParams> params, base::OnceCallback<void(std::unique_ptr<GetAllTimeSamplingProfileResult>)> callback) {
  dispatcher_->SendMessage("Memory.getAllTimeSamplingProfile", params->Serialize(), base::BindOnce(&Domain::HandleGetAllTimeSamplingProfileResponse, std::move(callback)));
}
void ExperimentalDomain::GetBrowserSamplingProfile(std::unique_ptr<GetBrowserSamplingProfileParams> params, base::OnceCallback<void(std::unique_ptr<GetBrowserSamplingProfileResult>)> callback) {
  dispatcher_->SendMessage("Memory.getBrowserSamplingProfile", params->Serialize(), base::BindOnce(&Domain::HandleGetBrowserSamplingProfileResponse, std::move(callback)));
}
void ExperimentalDomain::GetSamplingProfile(std::unique_ptr<GetSamplingProfileParams> params, base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)> callback) {
  dispatcher_->SendMessage("Memory.getSamplingProfile", params->Serialize(), base::BindOnce(&Domain::HandleGetSamplingProfileResponse, std::move(callback)));
}


// static
void Domain::HandleGetDOMCountersResponse(base::OnceCallback<void(std::unique_ptr<GetDOMCountersResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetDOMCountersResult> result = GetDOMCountersResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandlePrepareForLeakDetectionResponse(base::OnceCallback<void(std::unique_ptr<PrepareForLeakDetectionResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<PrepareForLeakDetectionResult> result = PrepareForLeakDetectionResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleForciblyPurgeJavaScriptMemoryResponse(base::OnceCallback<void(std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ForciblyPurgeJavaScriptMemoryResult> result = ForciblyPurgeJavaScriptMemoryResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetPressureNotificationsSuppressedResponse(base::OnceCallback<void(std::unique_ptr<SetPressureNotificationsSuppressedResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetPressureNotificationsSuppressedResult> result = SetPressureNotificationsSuppressedResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSimulatePressureNotificationResponse(base::OnceCallback<void(std::unique_ptr<SimulatePressureNotificationResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SimulatePressureNotificationResult> result = SimulatePressureNotificationResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStartSamplingResponse(base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StartSamplingResult> result = StartSamplingResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStopSamplingResponse(base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StopSamplingResult> result = StopSamplingResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetAllTimeSamplingProfileResponse(base::OnceCallback<void(std::unique_ptr<GetAllTimeSamplingProfileResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetAllTimeSamplingProfileResult> result = GetAllTimeSamplingProfileResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetBrowserSamplingProfileResponse(base::OnceCallback<void(std::unique_ptr<GetBrowserSamplingProfileResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetBrowserSamplingProfileResult> result = GetBrowserSamplingProfileResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetSamplingProfileResponse(base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetSamplingProfileResult> result = GetSamplingProfileResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}


}  // namespace memory

} // namespace headless
