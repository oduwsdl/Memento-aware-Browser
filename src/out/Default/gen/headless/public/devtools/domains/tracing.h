// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TRACING_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TRACING_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_tracing.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace tracing {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnBufferUsage(const BufferUsageParams& params) {}
  // Contains an bucket of collected trace events. When tracing is stopped collected events will be
  // send as a sequence of dataCollected events followed by tracingComplete event.
  virtual void OnDataCollected(const DataCollectedParams& params) {}
  // Signals that tracing is stopped and there is no trace buffers pending flush, all data were
  // delivered via dataCollected events.
  virtual void OnTracingComplete(const TracingCompleteParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnBufferUsage(const BufferUsageParams& params) final {}
  // Experimental: Contains an bucket of collected trace events. When tracing is stopped collected events will be
  // send as a sequence of dataCollected events followed by tracingComplete event.
  virtual void OnDataCollected(const DataCollectedParams& params) final {}
  // Experimental: Signals that tracing is stopped and there is no trace buffers pending flush, all data were
  // delivered via dataCollected events.
  virtual void OnTracingComplete(const TracingCompleteParams& params) final {}
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

  static void HandleEndResponse(base::OnceCallback<void(std::unique_ptr<EndResult>)> callback, const base::Value& response);
  static void HandleGetCategoriesResponse(base::OnceCallback<void(std::unique_ptr<GetCategoriesResult>)> callback, const base::Value& response);
  static void HandleRecordClockSyncMarkerResponse(base::OnceCallback<void(std::unique_ptr<RecordClockSyncMarkerResult>)> callback, const base::Value& response);
  static void HandleRequestMemoryDumpResponse(base::OnceCallback<void(std::unique_ptr<RequestMemoryDumpResult>)> callback, const base::Value& response);
  static void HandleStartResponse(base::OnceCallback<void(std::unique_ptr<StartResult>)> callback, const base::Value& response);

  void DispatchBufferUsageEvent(const base::Value& params);
  void DispatchDataCollectedEvent(const base::Value& params);
  void DispatchTracingCompleteEvent(const base::Value& params);

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

  // Stop trace events collection.
  void End(std::unique_ptr<EndParams> params, base::OnceCallback<void(std::unique_ptr<EndResult>)> callback = base::OnceCallback<void(std::unique_ptr<EndResult>)>());

  // Gets supported tracing categories.
  void GetCategories(std::unique_ptr<GetCategoriesParams> params, base::OnceCallback<void(std::unique_ptr<GetCategoriesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCategoriesResult>)>());

  // Record a clock sync marker in the trace.
  void RecordClockSyncMarker(std::unique_ptr<RecordClockSyncMarkerParams> params, base::OnceCallback<void(std::unique_ptr<RecordClockSyncMarkerResult>)> callback = base::OnceCallback<void(std::unique_ptr<RecordClockSyncMarkerResult>)>());

  // Request a global memory dump.
  void RequestMemoryDump(std::unique_ptr<RequestMemoryDumpParams> params, base::OnceCallback<void(std::unique_ptr<RequestMemoryDumpResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestMemoryDumpResult>)>());

  // Start trace events collection.
  void Start(std::unique_ptr<StartParams> params, base::OnceCallback<void(std::unique_ptr<StartResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace tracing
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TRACING_H_
