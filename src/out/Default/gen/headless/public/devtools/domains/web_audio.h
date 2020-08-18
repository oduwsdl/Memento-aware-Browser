// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_WEB_AUDIO_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_WEB_AUDIO_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_web_audio.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace web_audio {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Notifies that a new BaseAudioContext has been created.
  virtual void OnContextCreated(const ContextCreatedParams& params) {}
  // Notifies that an existing BaseAudioContext will be destroyed.
  virtual void OnContextWillBeDestroyed(const ContextWillBeDestroyedParams& params) {}
  // Notifies that existing BaseAudioContext has changed some properties (id stays the same)..
  virtual void OnContextChanged(const ContextChangedParams& params) {}
  // Notifies that the construction of an AudioListener has finished.
  virtual void OnAudioListenerCreated(const AudioListenerCreatedParams& params) {}
  // Notifies that a new AudioListener has been created.
  virtual void OnAudioListenerWillBeDestroyed(const AudioListenerWillBeDestroyedParams& params) {}
  // Notifies that a new AudioNode has been created.
  virtual void OnAudioNodeCreated(const AudioNodeCreatedParams& params) {}
  // Notifies that an existing AudioNode has been destroyed.
  virtual void OnAudioNodeWillBeDestroyed(const AudioNodeWillBeDestroyedParams& params) {}
  // Notifies that a new AudioParam has been created.
  virtual void OnAudioParamCreated(const AudioParamCreatedParams& params) {}
  // Notifies that an existing AudioParam has been destroyed.
  virtual void OnAudioParamWillBeDestroyed(const AudioParamWillBeDestroyedParams& params) {}
  // Notifies that two AudioNodes are connected.
  virtual void OnNodesConnected(const NodesConnectedParams& params) {}
  // Notifies that AudioNodes are disconnected. The destination can be null, and it means all the outgoing connections from the source are disconnected.
  virtual void OnNodesDisconnected(const NodesDisconnectedParams& params) {}
  // Notifies that an AudioNode is connected to an AudioParam.
  virtual void OnNodeParamConnected(const NodeParamConnectedParams& params) {}
  // Notifies that an AudioNode is disconnected to an AudioParam.
  virtual void OnNodeParamDisconnected(const NodeParamDisconnectedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: Notifies that a new BaseAudioContext has been created.
  virtual void OnContextCreated(const ContextCreatedParams& params) final {}
  // Experimental: Notifies that an existing BaseAudioContext will be destroyed.
  virtual void OnContextWillBeDestroyed(const ContextWillBeDestroyedParams& params) final {}
  // Experimental: Notifies that existing BaseAudioContext has changed some properties (id stays the same)..
  virtual void OnContextChanged(const ContextChangedParams& params) final {}
  // Experimental: Notifies that the construction of an AudioListener has finished.
  virtual void OnAudioListenerCreated(const AudioListenerCreatedParams& params) final {}
  // Experimental: Notifies that a new AudioListener has been created.
  virtual void OnAudioListenerWillBeDestroyed(const AudioListenerWillBeDestroyedParams& params) final {}
  // Experimental: Notifies that a new AudioNode has been created.
  virtual void OnAudioNodeCreated(const AudioNodeCreatedParams& params) final {}
  // Experimental: Notifies that an existing AudioNode has been destroyed.
  virtual void OnAudioNodeWillBeDestroyed(const AudioNodeWillBeDestroyedParams& params) final {}
  // Experimental: Notifies that a new AudioParam has been created.
  virtual void OnAudioParamCreated(const AudioParamCreatedParams& params) final {}
  // Experimental: Notifies that an existing AudioParam has been destroyed.
  virtual void OnAudioParamWillBeDestroyed(const AudioParamWillBeDestroyedParams& params) final {}
  // Experimental: Notifies that two AudioNodes are connected.
  virtual void OnNodesConnected(const NodesConnectedParams& params) final {}
  // Experimental: Notifies that AudioNodes are disconnected. The destination can be null, and it means all the outgoing connections from the source are disconnected.
  virtual void OnNodesDisconnected(const NodesDisconnectedParams& params) final {}
  // Experimental: Notifies that an AudioNode is connected to an AudioParam.
  virtual void OnNodeParamConnected(const NodeParamConnectedParams& params) final {}
  // Experimental: Notifies that an AudioNode is disconnected to an AudioParam.
  virtual void OnNodeParamDisconnected(const NodeParamDisconnectedParams& params) final {}
};

// This domain allows inspection of Web Audio API.
// https://webaudio.github.io/web-audio-api/
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleGetRealtimeDataResponse(base::OnceCallback<void(std::unique_ptr<GetRealtimeDataResult>)> callback, const base::Value& response);

  void DispatchContextCreatedEvent(const base::Value& params);
  void DispatchContextWillBeDestroyedEvent(const base::Value& params);
  void DispatchContextChangedEvent(const base::Value& params);
  void DispatchAudioListenerCreatedEvent(const base::Value& params);
  void DispatchAudioListenerWillBeDestroyedEvent(const base::Value& params);
  void DispatchAudioNodeCreatedEvent(const base::Value& params);
  void DispatchAudioNodeWillBeDestroyedEvent(const base::Value& params);
  void DispatchAudioParamCreatedEvent(const base::Value& params);
  void DispatchAudioParamWillBeDestroyedEvent(const base::Value& params);
  void DispatchNodesConnectedEvent(const base::Value& params);
  void DispatchNodesDisconnectedEvent(const base::Value& params);
  void DispatchNodeParamConnectedEvent(const base::Value& params);
  void DispatchNodeParamDisconnectedEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  // Enables the WebAudio domain and starts sending context lifetime events.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Disables the WebAudio domain.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Fetch the realtime data from the registered contexts.
  void GetRealtimeData(std::unique_ptr<GetRealtimeDataParams> params, base::OnceCallback<void(std::unique_ptr<GetRealtimeDataResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetRealtimeDataResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace web_audio
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_WEB_AUDIO_H_
