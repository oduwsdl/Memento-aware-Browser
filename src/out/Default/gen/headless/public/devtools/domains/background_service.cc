// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/background_service.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace background_service {

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
      "BackgroundService.recordingStateChanged",
      base::BindRepeating(&Domain::DispatchRecordingStateChangedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "BackgroundService.backgroundServiceEventReceived",
      base::BindRepeating(&Domain::DispatchBackgroundServiceEventReceivedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::StartObserving(std::unique_ptr<StartObservingParams> params, base::OnceCallback<void(std::unique_ptr<StartObservingResult>)> callback) {
  dispatcher_->SendMessage("BackgroundService.startObserving", params->Serialize(), base::BindOnce(&Domain::HandleStartObservingResponse, std::move(callback)));
}
void ExperimentalDomain::StopObserving(std::unique_ptr<StopObservingParams> params, base::OnceCallback<void(std::unique_ptr<StopObservingResult>)> callback) {
  dispatcher_->SendMessage("BackgroundService.stopObserving", params->Serialize(), base::BindOnce(&Domain::HandleStopObservingResponse, std::move(callback)));
}
void ExperimentalDomain::SetRecording(std::unique_ptr<SetRecordingParams> params, base::OnceCallback<void(std::unique_ptr<SetRecordingResult>)> callback) {
  dispatcher_->SendMessage("BackgroundService.setRecording", params->Serialize(), base::BindOnce(&Domain::HandleSetRecordingResponse, std::move(callback)));
}
void ExperimentalDomain::ClearEvents(std::unique_ptr<ClearEventsParams> params, base::OnceCallback<void(std::unique_ptr<ClearEventsResult>)> callback) {
  dispatcher_->SendMessage("BackgroundService.clearEvents", params->Serialize(), base::BindOnce(&Domain::HandleClearEventsResponse, std::move(callback)));
}


// static
void Domain::HandleStartObservingResponse(base::OnceCallback<void(std::unique_ptr<StartObservingResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StartObservingResult> result = StartObservingResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStopObservingResponse(base::OnceCallback<void(std::unique_ptr<StopObservingResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StopObservingResult> result = StopObservingResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetRecordingResponse(base::OnceCallback<void(std::unique_ptr<SetRecordingResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetRecordingResult> result = SetRecordingResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleClearEventsResponse(base::OnceCallback<void(std::unique_ptr<ClearEventsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ClearEventsResult> result = ClearEventsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchRecordingStateChangedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<RecordingStateChangedParams> parsed_params(RecordingStateChangedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnRecordingStateChanged(*parsed_params);
  }
}

void Domain::DispatchBackgroundServiceEventReceivedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<BackgroundServiceEventReceivedParams> parsed_params(BackgroundServiceEventReceivedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnBackgroundServiceEventReceived(*parsed_params);
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

}  // namespace background_service

} // namespace headless
