// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/cast.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace cast {

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
      "Cast.sinksUpdated",
      base::BindRepeating(&Domain::DispatchSinksUpdatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Cast.issueUpdated",
      base::BindRepeating(&Domain::DispatchIssueUpdatedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Cast.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Cast.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}
void ExperimentalDomain::SetSinkToUse(std::unique_ptr<SetSinkToUseParams> params, base::OnceCallback<void(std::unique_ptr<SetSinkToUseResult>)> callback) {
  dispatcher_->SendMessage("Cast.setSinkToUse", params->Serialize(), base::BindOnce(&Domain::HandleSetSinkToUseResponse, std::move(callback)));
}
void ExperimentalDomain::StartTabMirroring(std::unique_ptr<StartTabMirroringParams> params, base::OnceCallback<void(std::unique_ptr<StartTabMirroringResult>)> callback) {
  dispatcher_->SendMessage("Cast.startTabMirroring", params->Serialize(), base::BindOnce(&Domain::HandleStartTabMirroringResponse, std::move(callback)));
}
void ExperimentalDomain::StopCasting(std::unique_ptr<StopCastingParams> params, base::OnceCallback<void(std::unique_ptr<StopCastingResult>)> callback) {
  dispatcher_->SendMessage("Cast.stopCasting", params->Serialize(), base::BindOnce(&Domain::HandleStopCastingResponse, std::move(callback)));
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
void Domain::HandleSetSinkToUseResponse(base::OnceCallback<void(std::unique_ptr<SetSinkToUseResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetSinkToUseResult> result = SetSinkToUseResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStartTabMirroringResponse(base::OnceCallback<void(std::unique_ptr<StartTabMirroringResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StartTabMirroringResult> result = StartTabMirroringResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleStopCastingResponse(base::OnceCallback<void(std::unique_ptr<StopCastingResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<StopCastingResult> result = StopCastingResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchSinksUpdatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<SinksUpdatedParams> parsed_params(SinksUpdatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnSinksUpdated(*parsed_params);
  }
}

void Domain::DispatchIssueUpdatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<IssueUpdatedParams> parsed_params(IssueUpdatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnIssueUpdated(*parsed_params);
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

}  // namespace cast

} // namespace headless
