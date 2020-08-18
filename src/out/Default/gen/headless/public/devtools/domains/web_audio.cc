// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/web_audio.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace web_audio {

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
      "WebAudio.contextCreated",
      base::BindRepeating(&Domain::DispatchContextCreatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.contextWillBeDestroyed",
      base::BindRepeating(&Domain::DispatchContextWillBeDestroyedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.contextChanged",
      base::BindRepeating(&Domain::DispatchContextChangedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.audioListenerCreated",
      base::BindRepeating(&Domain::DispatchAudioListenerCreatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.audioListenerWillBeDestroyed",
      base::BindRepeating(&Domain::DispatchAudioListenerWillBeDestroyedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.audioNodeCreated",
      base::BindRepeating(&Domain::DispatchAudioNodeCreatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.audioNodeWillBeDestroyed",
      base::BindRepeating(&Domain::DispatchAudioNodeWillBeDestroyedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.audioParamCreated",
      base::BindRepeating(&Domain::DispatchAudioParamCreatedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.audioParamWillBeDestroyed",
      base::BindRepeating(&Domain::DispatchAudioParamWillBeDestroyedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.nodesConnected",
      base::BindRepeating(&Domain::DispatchNodesConnectedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.nodesDisconnected",
      base::BindRepeating(&Domain::DispatchNodesDisconnectedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.nodeParamConnected",
      base::BindRepeating(&Domain::DispatchNodeParamConnectedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "WebAudio.nodeParamDisconnected",
      base::BindRepeating(&Domain::DispatchNodeParamDisconnectedEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("WebAudio.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("WebAudio.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}
void ExperimentalDomain::GetRealtimeData(std::unique_ptr<GetRealtimeDataParams> params, base::OnceCallback<void(std::unique_ptr<GetRealtimeDataResult>)> callback) {
  dispatcher_->SendMessage("WebAudio.getRealtimeData", params->Serialize(), base::BindOnce(&Domain::HandleGetRealtimeDataResponse, std::move(callback)));
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
void Domain::HandleGetRealtimeDataResponse(base::OnceCallback<void(std::unique_ptr<GetRealtimeDataResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetRealtimeDataResult> result = GetRealtimeDataResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchContextCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ContextCreatedParams> parsed_params(ContextCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnContextCreated(*parsed_params);
  }
}

void Domain::DispatchContextWillBeDestroyedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ContextWillBeDestroyedParams> parsed_params(ContextWillBeDestroyedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnContextWillBeDestroyed(*parsed_params);
  }
}

void Domain::DispatchContextChangedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ContextChangedParams> parsed_params(ContextChangedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnContextChanged(*parsed_params);
  }
}

void Domain::DispatchAudioListenerCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AudioListenerCreatedParams> parsed_params(AudioListenerCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAudioListenerCreated(*parsed_params);
  }
}

void Domain::DispatchAudioListenerWillBeDestroyedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AudioListenerWillBeDestroyedParams> parsed_params(AudioListenerWillBeDestroyedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAudioListenerWillBeDestroyed(*parsed_params);
  }
}

void Domain::DispatchAudioNodeCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AudioNodeCreatedParams> parsed_params(AudioNodeCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAudioNodeCreated(*parsed_params);
  }
}

void Domain::DispatchAudioNodeWillBeDestroyedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AudioNodeWillBeDestroyedParams> parsed_params(AudioNodeWillBeDestroyedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAudioNodeWillBeDestroyed(*parsed_params);
  }
}

void Domain::DispatchAudioParamCreatedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AudioParamCreatedParams> parsed_params(AudioParamCreatedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAudioParamCreated(*parsed_params);
  }
}

void Domain::DispatchAudioParamWillBeDestroyedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<AudioParamWillBeDestroyedParams> parsed_params(AudioParamWillBeDestroyedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnAudioParamWillBeDestroyed(*parsed_params);
  }
}

void Domain::DispatchNodesConnectedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<NodesConnectedParams> parsed_params(NodesConnectedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnNodesConnected(*parsed_params);
  }
}

void Domain::DispatchNodesDisconnectedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<NodesDisconnectedParams> parsed_params(NodesDisconnectedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnNodesDisconnected(*parsed_params);
  }
}

void Domain::DispatchNodeParamConnectedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<NodeParamConnectedParams> parsed_params(NodeParamConnectedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnNodeParamConnected(*parsed_params);
  }
}

void Domain::DispatchNodeParamDisconnectedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<NodeParamDisconnectedParams> parsed_params(NodeParamDisconnectedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnNodeParamDisconnected(*parsed_params);
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

}  // namespace web_audio

} // namespace headless
