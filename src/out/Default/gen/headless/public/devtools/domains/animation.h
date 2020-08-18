// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_ANIMATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_ANIMATION_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_animation.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace animation {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Event for when an animation has been cancelled.
  virtual void OnAnimationCanceled(const AnimationCanceledParams& params) {}
  // Event for each animation that has been created.
  virtual void OnAnimationCreated(const AnimationCreatedParams& params) {}
  // Event for animation that has been started.
  virtual void OnAnimationStarted(const AnimationStartedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: Event for when an animation has been cancelled.
  virtual void OnAnimationCanceled(const AnimationCanceledParams& params) final {}
  // Experimental: Event for each animation that has been created.
  virtual void OnAnimationCreated(const AnimationCreatedParams& params) final {}
  // Experimental: Event for animation that has been started.
  virtual void OnAnimationStarted(const AnimationStartedParams& params) final {}
};

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

  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleGetCurrentAnimationTimeResponse(base::OnceCallback<void(std::unique_ptr<GetCurrentAnimationTimeResult>)> callback, const base::Value& response);
  static void HandleGetPlaybackRateResponse(base::OnceCallback<void(std::unique_ptr<GetPlaybackRateResult>)> callback, const base::Value& response);
  static void HandleReleaseAnimationsResponse(base::OnceCallback<void(std::unique_ptr<ReleaseAnimationsResult>)> callback, const base::Value& response);
  static void HandleResolveAnimationResponse(base::OnceCallback<void(std::unique_ptr<ResolveAnimationResult>)> callback, const base::Value& response);
  static void HandleSeekAnimationsResponse(base::OnceCallback<void(std::unique_ptr<SeekAnimationsResult>)> callback, const base::Value& response);
  static void HandleSetPausedResponse(base::OnceCallback<void(std::unique_ptr<SetPausedResult>)> callback, const base::Value& response);
  static void HandleSetPlaybackRateResponse(base::OnceCallback<void(std::unique_ptr<SetPlaybackRateResult>)> callback, const base::Value& response);
  static void HandleSetTimingResponse(base::OnceCallback<void(std::unique_ptr<SetTimingResult>)> callback, const base::Value& response);

  void DispatchAnimationCanceledEvent(const base::Value& params);
  void DispatchAnimationCreatedEvent(const base::Value& params);
  void DispatchAnimationStartedEvent(const base::Value& params);

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

  // Disables animation domain notifications.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables animation domain notifications.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Returns the current time of the an animation.
  void GetCurrentAnimationTime(std::unique_ptr<GetCurrentAnimationTimeParams> params, base::OnceCallback<void(std::unique_ptr<GetCurrentAnimationTimeResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCurrentAnimationTimeResult>)>());

  // Gets the playback rate of the document timeline.
  void GetPlaybackRate(std::unique_ptr<GetPlaybackRateParams> params, base::OnceCallback<void(std::unique_ptr<GetPlaybackRateResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetPlaybackRateResult>)>());

  // Releases a set of animations to no longer be manipulated.
  void ReleaseAnimations(std::unique_ptr<ReleaseAnimationsParams> params, base::OnceCallback<void(std::unique_ptr<ReleaseAnimationsResult>)> callback = base::OnceCallback<void(std::unique_ptr<ReleaseAnimationsResult>)>());

  // Gets the remote object of the Animation.
  void ResolveAnimation(std::unique_ptr<ResolveAnimationParams> params, base::OnceCallback<void(std::unique_ptr<ResolveAnimationResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResolveAnimationResult>)>());

  // Seek a set of animations to a particular time within each animation.
  void SeekAnimations(std::unique_ptr<SeekAnimationsParams> params, base::OnceCallback<void(std::unique_ptr<SeekAnimationsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SeekAnimationsResult>)>());

  // Sets the paused state of a set of animations.
  void SetPaused(std::unique_ptr<SetPausedParams> params, base::OnceCallback<void(std::unique_ptr<SetPausedResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetPausedResult>)>());

  // Sets the playback rate of the document timeline.
  void SetPlaybackRate(std::unique_ptr<SetPlaybackRateParams> params, base::OnceCallback<void(std::unique_ptr<SetPlaybackRateResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetPlaybackRateResult>)>());

  // Sets the timing of an animation node.
  void SetTiming(std::unique_ptr<SetTimingParams> params, base::OnceCallback<void(std::unique_ptr<SetTimingResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetTimingResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace animation
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_ANIMATION_H_
