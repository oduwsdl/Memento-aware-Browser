// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_BACKGROUND_SERVICE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_BACKGROUND_SERVICE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_background_service.h"
#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/devtools/domains/types_service_worker.h"
#include "headless/public/devtools/domains/types_target.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace background_service {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Called when the recording state for the service has been updated.
  virtual void OnRecordingStateChanged(const RecordingStateChangedParams& params) {}
  // Called with all existing backgroundServiceEvents when enabled, and all new
  // events afterwards if enabled and recording.
  virtual void OnBackgroundServiceEventReceived(const BackgroundServiceEventReceivedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: Called when the recording state for the service has been updated.
  virtual void OnRecordingStateChanged(const RecordingStateChangedParams& params) final {}
  // Experimental: Called with all existing backgroundServiceEvents when enabled, and all new
  // events afterwards if enabled and recording.
  virtual void OnBackgroundServiceEventReceived(const BackgroundServiceEventReceivedParams& params) final {}
};

// Defines events for background web platform features.
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

  static void HandleStartObservingResponse(base::OnceCallback<void(std::unique_ptr<StartObservingResult>)> callback, const base::Value& response);
  static void HandleStopObservingResponse(base::OnceCallback<void(std::unique_ptr<StopObservingResult>)> callback, const base::Value& response);
  static void HandleSetRecordingResponse(base::OnceCallback<void(std::unique_ptr<SetRecordingResult>)> callback, const base::Value& response);
  static void HandleClearEventsResponse(base::OnceCallback<void(std::unique_ptr<ClearEventsResult>)> callback, const base::Value& response);

  void DispatchRecordingStateChangedEvent(const base::Value& params);
  void DispatchBackgroundServiceEventReceivedEvent(const base::Value& params);

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

  // Enables event updates for the service.
  void StartObserving(std::unique_ptr<StartObservingParams> params, base::OnceCallback<void(std::unique_ptr<StartObservingResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartObservingResult>)>());

  // Disables event updates for the service.
  void StopObserving(std::unique_ptr<StopObservingParams> params, base::OnceCallback<void(std::unique_ptr<StopObservingResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopObservingResult>)>());

  // Set the recording state for the service.
  void SetRecording(std::unique_ptr<SetRecordingParams> params, base::OnceCallback<void(std::unique_ptr<SetRecordingResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetRecordingResult>)>());

  // Clears all stored data for the service.
  void ClearEvents(std::unique_ptr<ClearEventsParams> params, base::OnceCallback<void(std::unique_ptr<ClearEventsResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearEventsResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace background_service
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_BACKGROUND_SERVICE_H_
