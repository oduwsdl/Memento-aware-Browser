// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/animation.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace animation {

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
      "Animation.animationCanceled",
      base::BindRepeating(&Domain::DispatchAnimationCanceledEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Animation.animationCreated",
      base::BindRepeating(&Domain::DispatchAnimationCreatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Animation.animationStarted",
      base::BindRepeating(&Domain::DispatchAnimationStartedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Animation.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}
void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Animation.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::GetCurrentAnimationTime(std::unique_ptr<GetCurrentAnimationTimeParams> params, base::OnceCallback<void(std::unique_ptr<GetCurrentAnimationTimeResult>)> callback) {
  dispatcher_->SendMessage("Animation.getCurrentTime", params->Serialize(), base::BindOnce(&Domain::HandleGetCurrentAnimationTimeResponse, std::move(callback)));
}
void ExperimentalDomain::GetPlaybackRate(std::unique_ptr<GetPlaybackRateParams> params, base::OnceCallback<void(std::unique_ptr<GetPlaybackRateResult>)> callback) {
  dispatcher_->SendMessage("Animation.getPlaybackRate", params->Serialize(), base::BindOnce(&Domain::HandleGetPlaybackRateResponse, std::move(callback)));
}
void ExperimentalDomain::ReleaseAnimations(std::unique_ptr<ReleaseAnimationsParams> params, base::OnceCallback<void(std::unique_ptr<ReleaseAnimationsResult>)> callback) {
  dispatcher_->SendMessage("Animation.releaseAnimations", params->Serialize(), base::BindOnce(&Domain::HandleReleaseAnimationsResponse, std::move(callback)));
}
void ExperimentalDomain::ResolveAnimation(std::unique_ptr<ResolveAnimationParams> params, base::OnceCallback<void(std::unique_ptr<ResolveAnimationResult>)> callback) {
  dispatcher_->SendMessage("Animation.resolveAnimation", params->Serialize(), base::BindOnce(&Domain::HandleResolveAnimationResponse, std::move(callback)));
}
void ExperimentalDomain::SeekAnimations(std::unique_ptr<SeekAnimationsParams> params, base::OnceCallback<void(std::unique_ptr<SeekAnimationsResult>)> callback) {
  dispatcher_->SendMessage("Animation.seekAnimations", params->Serialize(), base::BindOnce(&Domain::HandleSeekAnimationsResponse, std::move(callback)));
}
void ExperimentalDomain::SetPaused(std::unique_ptr<SetPausedParams> params, base::OnceCallback<void(std::unique_ptr<SetPausedResult>)> callback) {
  dispatcher_->SendMessage("Animation.setPaused", params->Serialize(), base::BindOnce(&Domain::HandleSetPausedResponse, std::move(callback)));
}
void ExperimentalDomain::SetPlaybackRate(std::unique_ptr<SetPlaybackRateParams> params, base::OnceCallback<void(std::unique_ptr<SetPlaybackRateResult>)> callback) {
  dispatcher_->SendMessage("Animation.setPlaybackRate", params->Serialize(), base::BindOnce(&Domain::HandleSetPlaybackRateResponse, std::move(callback)));
}
void ExperimentalDomain::SetTiming(std::unique_ptr<SetTimingParams> params, base::OnceCallback<void(std::unique_ptr<SetTimingResult>)> callback) {
  dispatcher_->SendMessage("Animation.setTiming", params->Serialize(), base::BindOnce(&Domain::HandleSetTimingResponse, std::move(callback)));
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
void Domain::HandleGetCurrentAnimationTimeResponse(base::OnceCallback<void(std::unique_ptr<GetCurrentAnimationTimeResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetCurrentAnimationTimeResult> result = GetCurrentAnimationTimeResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetPlaybackRateResponse(base::OnceCallback<void(std::unique_ptr<GetPlaybackRateResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetPlaybackRateResult> result = GetPlaybackRateResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleReleaseAnimationsResponse(base::OnceCallback<void(std::unique_ptr<ReleaseAnimationsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ReleaseAnimationsResult> result = ReleaseAnimationsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleResolveAnimationResponse(base::OnceCallback<void(std::unique_ptr<ResolveAnimationResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ResolveAnimationResult> result = ResolveAnimationResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSeekAnimationsResponse(base::OnceCallback<void(std::unique_ptr<SeekAnimationsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SeekAnimationsResult> result = SeekAnimationsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetPausedResponse(base::OnceCallback<void(std::unique_ptr<SetPausedResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetPausedResult> result = SetPausedResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetPlaybackRateResponse(base::OnceCallback<void(std::unique_ptr<SetPlaybackRateResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetPlaybackRateResult> result = SetPlaybackRateResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetTimingResponse(base::OnceCallback<void(std::unique_ptr<SetTimingResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetTimingResult> result = SetTimingResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchAnimationCanceledEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AnimationCanceledParams> parsed_params(AnimationCanceledParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAnimationCanceled(*parsed_params);
  }
}

void Domain::DispatchAnimationCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AnimationCreatedParams> parsed_params(AnimationCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAnimationCreated(*parsed_params);
  }
}

void Domain::DispatchAnimationStartedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AnimationStartedParams> parsed_params(AnimationStartedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAnimationStarted(*parsed_params);
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

}  // namespace animation

} // namespace headless
