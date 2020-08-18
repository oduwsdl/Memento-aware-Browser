// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_SERVICE_WORKER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_SERVICE_WORKER_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_service_worker.h"
#include "headless/public/devtools/domains/types_target.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace service_worker {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnWorkerErrorReported(const WorkerErrorReportedParams& params) {}
  virtual void OnWorkerRegistrationUpdated(const WorkerRegistrationUpdatedParams& params) {}
  virtual void OnWorkerVersionUpdated(const WorkerVersionUpdatedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnWorkerErrorReported(const WorkerErrorReportedParams& params) final {}
  virtual void OnWorkerRegistrationUpdated(const WorkerRegistrationUpdatedParams& params) final {}
  virtual void OnWorkerVersionUpdated(const WorkerVersionUpdatedParams& params) final {}
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

  static void HandleDeliverPushMessageResponse(base::OnceCallback<void(std::unique_ptr<DeliverPushMessageResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleDispatchSyncEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchSyncEventResult>)> callback, const base::Value& response);
  static void HandleDispatchPeriodicSyncEventResponse(base::OnceCallback<void(std::unique_ptr<DispatchPeriodicSyncEventResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleInspectWorkerResponse(base::OnceCallback<void(std::unique_ptr<InspectWorkerResult>)> callback, const base::Value& response);
  static void HandleSetForceUpdateOnPageLoadResponse(base::OnceCallback<void(std::unique_ptr<SetForceUpdateOnPageLoadResult>)> callback, const base::Value& response);
  static void HandleSkipWaitingResponse(base::OnceCallback<void(std::unique_ptr<SkipWaitingResult>)> callback, const base::Value& response);
  static void HandleStartWorkerResponse(base::OnceCallback<void(std::unique_ptr<StartWorkerResult>)> callback, const base::Value& response);
  static void HandleStopAllWorkersResponse(base::OnceCallback<void(std::unique_ptr<StopAllWorkersResult>)> callback, const base::Value& response);
  static void HandleStopWorkerResponse(base::OnceCallback<void(std::unique_ptr<StopWorkerResult>)> callback, const base::Value& response);
  static void HandleUnregisterResponse(base::OnceCallback<void(std::unique_ptr<UnregisterResult>)> callback, const base::Value& response);
  static void HandleUpdateRegistrationResponse(base::OnceCallback<void(std::unique_ptr<UpdateRegistrationResult>)> callback, const base::Value& response);

  void DispatchWorkerErrorReportedEvent(const base::Value& params);
  void DispatchWorkerRegistrationUpdatedEvent(const base::Value& params);
  void DispatchWorkerVersionUpdatedEvent(const base::Value& params);

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

  void DeliverPushMessage(std::unique_ptr<DeliverPushMessageParams> params, base::OnceCallback<void(std::unique_ptr<DeliverPushMessageResult>)> callback = base::OnceCallback<void(std::unique_ptr<DeliverPushMessageResult>)>());

  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  void DispatchSyncEvent(std::unique_ptr<DispatchSyncEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchSyncEventResult>)> callback = base::OnceCallback<void(std::unique_ptr<DispatchSyncEventResult>)>());

  void DispatchPeriodicSyncEvent(std::unique_ptr<DispatchPeriodicSyncEventParams> params, base::OnceCallback<void(std::unique_ptr<DispatchPeriodicSyncEventResult>)> callback = base::OnceCallback<void(std::unique_ptr<DispatchPeriodicSyncEventResult>)>());

  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  void InspectWorker(std::unique_ptr<InspectWorkerParams> params, base::OnceCallback<void(std::unique_ptr<InspectWorkerResult>)> callback = base::OnceCallback<void(std::unique_ptr<InspectWorkerResult>)>());

  void SetForceUpdateOnPageLoad(std::unique_ptr<SetForceUpdateOnPageLoadParams> params, base::OnceCallback<void(std::unique_ptr<SetForceUpdateOnPageLoadResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetForceUpdateOnPageLoadResult>)>());

  void SkipWaiting(std::unique_ptr<SkipWaitingParams> params, base::OnceCallback<void(std::unique_ptr<SkipWaitingResult>)> callback = base::OnceCallback<void(std::unique_ptr<SkipWaitingResult>)>());

  void StartWorker(std::unique_ptr<StartWorkerParams> params, base::OnceCallback<void(std::unique_ptr<StartWorkerResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartWorkerResult>)>());

  void StopAllWorkers(std::unique_ptr<StopAllWorkersParams> params, base::OnceCallback<void(std::unique_ptr<StopAllWorkersResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopAllWorkersResult>)>());

  void StopWorker(std::unique_ptr<StopWorkerParams> params, base::OnceCallback<void(std::unique_ptr<StopWorkerResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopWorkerResult>)>());

  void Unregister(std::unique_ptr<UnregisterParams> params, base::OnceCallback<void(std::unique_ptr<UnregisterResult>)> callback = base::OnceCallback<void(std::unique_ptr<UnregisterResult>)>());

  void UpdateRegistration(std::unique_ptr<UpdateRegistrationParams> params, base::OnceCallback<void(std::unique_ptr<UpdateRegistrationResult>)> callback = base::OnceCallback<void(std::unique_ptr<UpdateRegistrationResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace service_worker
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_SERVICE_WORKER_H_
