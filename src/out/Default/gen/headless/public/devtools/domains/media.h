// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_MEDIA_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_MEDIA_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_media.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace media {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // This can be called multiple times, and can be used to set / override /
  // remove player properties. A null propValue indicates removal.
  virtual void OnPlayerPropertiesChanged(const PlayerPropertiesChangedParams& params) {}
  // Send events as a list, allowing them to be batched on the browser for less
  // congestion. If batched, events must ALWAYS be in chronological order.
  virtual void OnPlayerEventsAdded(const PlayerEventsAddedParams& params) {}
  // Send a list of any messages that need to be delivered.
  virtual void OnPlayerMessagesLogged(const PlayerMessagesLoggedParams& params) {}
  // Send a list of any errors that need to be delivered.
  virtual void OnPlayerErrorsRaised(const PlayerErrorsRaisedParams& params) {}
  // Called whenever a player is created, or when a new agent joins and recieves
  // a list of active players. If an agent is restored, it will recieve the full
  // list of player ids and all events again.
  virtual void OnPlayersCreated(const PlayersCreatedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: This can be called multiple times, and can be used to set / override /
  // remove player properties. A null propValue indicates removal.
  virtual void OnPlayerPropertiesChanged(const PlayerPropertiesChangedParams& params) final {}
  // Experimental: Send events as a list, allowing them to be batched on the browser for less
  // congestion. If batched, events must ALWAYS be in chronological order.
  virtual void OnPlayerEventsAdded(const PlayerEventsAddedParams& params) final {}
  // Experimental: Send a list of any messages that need to be delivered.
  virtual void OnPlayerMessagesLogged(const PlayerMessagesLoggedParams& params) final {}
  // Experimental: Send a list of any errors that need to be delivered.
  virtual void OnPlayerErrorsRaised(const PlayerErrorsRaisedParams& params) final {}
  // Experimental: Called whenever a player is created, or when a new agent joins and recieves
  // a list of active players. If an agent is restored, it will recieve the full
  // list of player ids and all events again.
  virtual void OnPlayersCreated(const PlayersCreatedParams& params) final {}
};

// This domain allows detailed inspection of media elements
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

  void DispatchPlayerPropertiesChangedEvent(const base::Value& params);
  void DispatchPlayerEventsAddedEvent(const base::Value& params);
  void DispatchPlayerMessagesLoggedEvent(const base::Value& params);
  void DispatchPlayerErrorsRaisedEvent(const base::Value& params);
  void DispatchPlayersCreatedEvent(const base::Value& params);

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

  // Enables the Media domain
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Disables the Media domain.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace media
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_MEDIA_H_
