// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/performance.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace performance {

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
      "Performance.metrics",
      base::BindRepeating(&Domain::DispatchMetricsEvent,
                          base::Unretained(this)));
}

void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Performance.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}

void Domain::Disable(base::OnceClosure callback) {
  std::unique_ptr<DisableParams> params = DisableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Performance.disable", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Performance.disable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Performance.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}

void Domain::Enable(base::OnceClosure callback) {
  std::unique_ptr<EnableParams> params = EnableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Performance.enable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Performance.enable", params->Serialize(), std::move(callback));
}
void ExperimentalDomain::SetTimeDomain(std::unique_ptr<SetTimeDomainParams> params, base::OnceCallback<void(std::unique_ptr<SetTimeDomainResult>)> callback) {
  dispatcher_->SendMessage("Performance.setTimeDomain", params->Serialize(), base::BindOnce(&Domain::HandleSetTimeDomainResponse, std::move(callback)));
}
void Domain::GetMetrics(std::unique_ptr<GetMetricsParams> params, base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)> callback) {
  dispatcher_->SendMessage("Performance.getMetrics", params->Serialize(), base::BindOnce(&Domain::HandleGetMetricsResponse, std::move(callback)));
}

void Domain::GetMetrics(base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)> callback) {
  std::unique_ptr<GetMetricsParams> params = GetMetricsParams::Builder()
      .Build();
dispatcher_->SendMessage("Performance.getMetrics", params->Serialize(), base::BindOnce(&Domain::HandleGetMetricsResponse, std::move(callback)));
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
void Domain::HandleSetTimeDomainResponse(base::OnceCallback<void(std::unique_ptr<SetTimeDomainResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetTimeDomainResult> result = SetTimeDomainResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetMetricsResponse(base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetMetricsResult> result = GetMetricsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchMetricsEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<MetricsParams> parsed_params(MetricsParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnMetrics(*parsed_params);
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

}  // namespace performance

} // namespace headless
