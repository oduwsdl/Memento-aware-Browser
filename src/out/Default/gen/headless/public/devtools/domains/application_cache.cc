// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/application_cache.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace application_cache {

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
      "ApplicationCache.applicationCacheStatusUpdated",
      base::BindRepeating(&Domain::DispatchApplicationCacheStatusUpdatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "ApplicationCache.networkStateUpdated",
      base::BindRepeating(&Domain::DispatchNetworkStateUpdatedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("ApplicationCache.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::GetApplicationCacheForFrame(std::unique_ptr<GetApplicationCacheForFrameParams> params, base::OnceCallback<void(std::unique_ptr<GetApplicationCacheForFrameResult>)> callback) {
  dispatcher_->SendMessage("ApplicationCache.getApplicationCacheForFrame", params->Serialize(), base::BindOnce(&Domain::HandleGetApplicationCacheForFrameResponse, std::move(callback)));
}
void ExperimentalDomain::GetFramesWithManifests(std::unique_ptr<GetFramesWithManifestsParams> params, base::OnceCallback<void(std::unique_ptr<GetFramesWithManifestsResult>)> callback) {
  dispatcher_->SendMessage("ApplicationCache.getFramesWithManifests", params->Serialize(), base::BindOnce(&Domain::HandleGetFramesWithManifestsResponse, std::move(callback)));
}
void ExperimentalDomain::GetManifestForFrame(std::unique_ptr<GetManifestForFrameParams> params, base::OnceCallback<void(std::unique_ptr<GetManifestForFrameResult>)> callback) {
  dispatcher_->SendMessage("ApplicationCache.getManifestForFrame", params->Serialize(), base::BindOnce(&Domain::HandleGetManifestForFrameResponse, std::move(callback)));
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
void Domain::HandleGetApplicationCacheForFrameResponse(base::OnceCallback<void(std::unique_ptr<GetApplicationCacheForFrameResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetApplicationCacheForFrameResult> result = GetApplicationCacheForFrameResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetFramesWithManifestsResponse(base::OnceCallback<void(std::unique_ptr<GetFramesWithManifestsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetFramesWithManifestsResult> result = GetFramesWithManifestsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleGetManifestForFrameResponse(base::OnceCallback<void(std::unique_ptr<GetManifestForFrameResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetManifestForFrameResult> result = GetManifestForFrameResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchApplicationCacheStatusUpdatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ApplicationCacheStatusUpdatedParams> parsed_params(ApplicationCacheStatusUpdatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnApplicationCacheStatusUpdated(*parsed_params);
  }
}

void Domain::DispatchNetworkStateUpdatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<NetworkStateUpdatedParams> parsed_params(NetworkStateUpdatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnNetworkStateUpdated(*parsed_params);
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

}  // namespace application_cache

} // namespace headless
