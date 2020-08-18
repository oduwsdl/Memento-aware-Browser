// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/media.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace media {

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
      "Media.playerPropertiesChanged",
      base::BindRepeating(&Domain::DispatchPlayerPropertiesChangedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Media.playerEventsAdded",
      base::BindRepeating(&Domain::DispatchPlayerEventsAddedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Media.playerMessagesLogged",
      base::BindRepeating(&Domain::DispatchPlayerMessagesLoggedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Media.playerErrorsRaised",
      base::BindRepeating(&Domain::DispatchPlayerErrorsRaisedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Media.playersCreated",
      base::BindRepeating(&Domain::DispatchPlayersCreatedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Media.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Media.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
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

void Domain::DispatchPlayerPropertiesChangedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<PlayerPropertiesChangedParams> parsed_params(PlayerPropertiesChangedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnPlayerPropertiesChanged(*parsed_params);
  }
}

void Domain::DispatchPlayerEventsAddedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<PlayerEventsAddedParams> parsed_params(PlayerEventsAddedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnPlayerEventsAdded(*parsed_params);
  }
}

void Domain::DispatchPlayerMessagesLoggedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<PlayerMessagesLoggedParams> parsed_params(PlayerMessagesLoggedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnPlayerMessagesLogged(*parsed_params);
  }
}

void Domain::DispatchPlayerErrorsRaisedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<PlayerErrorsRaisedParams> parsed_params(PlayerErrorsRaisedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnPlayerErrorsRaised(*parsed_params);
  }
}

void Domain::DispatchPlayersCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<PlayersCreatedParams> parsed_params(PlayersCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnPlayersCreated(*parsed_params);
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

}  // namespace media

} // namespace headless
