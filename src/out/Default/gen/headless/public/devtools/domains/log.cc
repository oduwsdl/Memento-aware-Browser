// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/log.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace log {

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
      "Log.entryAdded",
      base::BindRepeating(&Domain::DispatchEntryAddedEvent,
                          base::Unretained(this)));
}

void Domain::Clear(std::unique_ptr<ClearParams> params, base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback) {
  dispatcher_->SendMessage("Log.clear", params->Serialize(), base::BindOnce(&Domain::HandleClearResponse, std::move(callback)));
}

void Domain::Clear(base::OnceClosure callback) {
  std::unique_ptr<ClearParams> params = ClearParams::Builder()
      .Build();
  dispatcher_->SendMessage("Log.clear", params->Serialize(), std::move(callback));
}
void Domain::Clear(std::unique_ptr<ClearParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Log.clear", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Log.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}

void Domain::Disable(base::OnceClosure callback) {
  std::unique_ptr<DisableParams> params = DisableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Log.disable", params->Serialize(), std::move(callback));
}
void Domain::Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Log.disable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Log.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}

void Domain::Enable(base::OnceClosure callback) {
  std::unique_ptr<EnableParams> params = EnableParams::Builder()
      .Build();
  dispatcher_->SendMessage("Log.enable", params->Serialize(), std::move(callback));
}
void Domain::Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Log.enable", params->Serialize(), std::move(callback));
}
void Domain::StartViolationsReport(std::unique_ptr<StartViolationsReportParams> params, base::OnceCallback<void(std::unique_ptr<StartViolationsReportResult>)> callback) {
  dispatcher_->SendMessage("Log.startViolationsReport", params->Serialize(), base::BindOnce(&Domain::HandleStartViolationsReportResponse, std::move(callback)));
}

void Domain::StartViolationsReport(std::vector<std::unique_ptr<::headless::log::ViolationSetting>> config, base::OnceClosure callback) {
  std::unique_ptr<StartViolationsReportParams> params = StartViolationsReportParams::Builder()
      .SetConfig(std::move(config))
      .Build();
  dispatcher_->SendMessage("Log.startViolationsReport", params->Serialize(), std::move(callback));
}
void Domain::StartViolationsReport(std::unique_ptr<StartViolationsReportParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Log.startViolationsReport", params->Serialize(), std::move(callback));
}
void Domain::StopViolationsReport(std::unique_ptr<StopViolationsReportParams> params, base::OnceCallback<void(std::unique_ptr<StopViolationsReportResult>)> callback) {
  dispatcher_->SendMessage("Log.stopViolationsReport", params->Serialize(), base::BindOnce(&Domain::HandleStopViolationsReportResponse, std::move(callback)));
}

void Domain::StopViolationsReport(base::OnceClosure callback) {
  std::unique_ptr<StopViolationsReportParams> params = StopViolationsReportParams::Builder()
      .Build();
  dispatcher_->SendMessage("Log.stopViolationsReport", params->Serialize(), std::move(callback));
}
void Domain::StopViolationsReport(std::unique_ptr<StopViolationsReportParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("Log.stopViolationsReport", params->Serialize(), std::move(callback));
}


// static
void Domain::HandleClearResponse(base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ClearResult> result = ClearResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
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
void Domain::HandleStartViolationsReportResponse(base::OnceCallback<void(std::unique_ptr<StartViolationsReportResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StartViolationsReportResult> result = StartViolationsReportResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStopViolationsReportResponse(base::OnceCallback<void(std::unique_ptr<StopViolationsReportResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StopViolationsReportResult> result = StopViolationsReportResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchEntryAddedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<EntryAddedParams> parsed_params(EntryAddedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnEntryAdded(*parsed_params);
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

}  // namespace log

} // namespace headless
