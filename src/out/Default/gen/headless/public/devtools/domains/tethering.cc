// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/tethering.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace tethering {

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
      "Tethering.accepted",
      base::BindRepeating(&Domain::DispatchAcceptedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Bind(std::unique_ptr<BindParams> params, base::OnceCallback<void(std::unique_ptr<BindResult>)> callback) {
  dispatcher_->SendMessage("Tethering.bind", params->Serialize(), base::BindOnce(&Domain::HandleBindResponse, std::move(callback)));
}
void ExperimentalDomain::Unbind(std::unique_ptr<UnbindParams> params, base::OnceCallback<void(std::unique_ptr<UnbindResult>)> callback) {
  dispatcher_->SendMessage("Tethering.unbind", params->Serialize(), base::BindOnce(&Domain::HandleUnbindResponse, std::move(callback)));
}


// static
void Domain::HandleBindResponse(base::OnceCallback<void(std::unique_ptr<BindResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<BindResult> result = BindResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleUnbindResponse(base::OnceCallback<void(std::unique_ptr<UnbindResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<UnbindResult> result = UnbindResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchAcceptedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AcceptedParams> parsed_params(AcceptedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAccepted(*parsed_params);
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

}  // namespace tethering

} // namespace headless
