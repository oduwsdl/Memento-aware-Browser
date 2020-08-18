// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/tracing.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace tracing {

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
      "Tracing.bufferUsage",
      base::BindRepeating(&Domain::DispatchBufferUsageEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Tracing.dataCollected",
      base::BindRepeating(&Domain::DispatchDataCollectedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Tracing.tracingComplete",
      base::BindRepeating(&Domain::DispatchTracingCompleteEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::End(std::unique_ptr<EndParams> params, base::OnceCallback<void(std::unique_ptr<EndResult>)> callback) {
  dispatcher_->SendMessage("Tracing.end", params->Serialize(), base::BindOnce(&Domain::HandleEndResponse, std::move(callback)));
}
void ExperimentalDomain::GetCategories(std::unique_ptr<GetCategoriesParams> params, base::OnceCallback<void(std::unique_ptr<GetCategoriesResult>)> callback) {
  dispatcher_->SendMessage("Tracing.getCategories", params->Serialize(), base::BindOnce(&Domain::HandleGetCategoriesResponse, std::move(callback)));
}
void ExperimentalDomain::RecordClockSyncMarker(std::unique_ptr<RecordClockSyncMarkerParams> params, base::OnceCallback<void(std::unique_ptr<RecordClockSyncMarkerResult>)> callback) {
  dispatcher_->SendMessage("Tracing.recordClockSyncMarker", params->Serialize(), base::BindOnce(&Domain::HandleRecordClockSyncMarkerResponse, std::move(callback)));
}
void ExperimentalDomain::RequestMemoryDump(std::unique_ptr<RequestMemoryDumpParams> params, base::OnceCallback<void(std::unique_ptr<RequestMemoryDumpResult>)> callback) {
  dispatcher_->SendMessage("Tracing.requestMemoryDump", params->Serialize(), base::BindOnce(&Domain::HandleRequestMemoryDumpResponse, std::move(callback)));
}
void ExperimentalDomain::Start(std::unique_ptr<StartParams> params, base::OnceCallback<void(std::unique_ptr<StartResult>)> callback) {
  dispatcher_->SendMessage("Tracing.start", params->Serialize(), base::BindOnce(&Domain::HandleStartResponse, std::move(callback)));
}


// static
void Domain::HandleEndResponse(base::OnceCallback<void(std::unique_ptr<EndResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<EndResult> result = EndResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetCategoriesResponse(base::OnceCallback<void(std::unique_ptr<GetCategoriesResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetCategoriesResult> result = GetCategoriesResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRecordClockSyncMarkerResponse(base::OnceCallback<void(std::unique_ptr<RecordClockSyncMarkerResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RecordClockSyncMarkerResult> result = RecordClockSyncMarkerResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleRequestMemoryDumpResponse(base::OnceCallback<void(std::unique_ptr<RequestMemoryDumpResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<RequestMemoryDumpResult> result = RequestMemoryDumpResult::Parse(response, &errors);
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

void Domain::DispatchBufferUsageEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<BufferUsageParams> parsed_params(BufferUsageParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnBufferUsage(*parsed_params);
  }
}

void Domain::DispatchDataCollectedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<DataCollectedParams> parsed_params(DataCollectedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnDataCollected(*parsed_params);
  }
}

void Domain::DispatchTracingCompleteEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<TracingCompleteParams> parsed_params(TracingCompleteParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnTracingComplete(*parsed_params);
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

}  // namespace tracing

} // namespace headless
