// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_HEAP_PROFILER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_HEAP_PROFILER_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_heap_profiler.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace heap_profiler {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnAddHeapSnapshotChunk(const AddHeapSnapshotChunkParams& params) {}
  // If heap objects tracking has been started then backend may send update for one or more fragments
  virtual void OnHeapStatsUpdate(const HeapStatsUpdateParams& params) {}
  // If heap objects tracking has been started then backend regularly sends a current value for last
  // seen object id and corresponding timestamp. If the were changes in the heap since last event
  // then one or more heapStatsUpdate events will be sent before a new lastSeenObjectId event.
  virtual void OnLastSeenObjectId(const LastSeenObjectIdParams& params) {}
  virtual void OnReportHeapSnapshotProgress(const ReportHeapSnapshotProgressParams& params) {}
  virtual void OnResetProfiles(const ResetProfilesParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnAddHeapSnapshotChunk(const AddHeapSnapshotChunkParams& params) final {}
  // Experimental: If heap objects tracking has been started then backend may send update for one or more fragments
  virtual void OnHeapStatsUpdate(const HeapStatsUpdateParams& params) final {}
  // Experimental: If heap objects tracking has been started then backend regularly sends a current value for last
  // seen object id and corresponding timestamp. If the were changes in the heap since last event
  // then one or more heapStatsUpdate events will be sent before a new lastSeenObjectId event.
  virtual void OnLastSeenObjectId(const LastSeenObjectIdParams& params) final {}
  virtual void OnReportHeapSnapshotProgress(const ReportHeapSnapshotProgressParams& params) final {}
  virtual void OnResetProfiles(const ResetProfilesParams& params) final {}
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

  static void HandleAddInspectedHeapObjectResponse(base::OnceCallback<void(std::unique_ptr<AddInspectedHeapObjectResult>)> callback, const base::Value& response);
  static void HandleCollectGarbageResponse(base::OnceCallback<void(std::unique_ptr<CollectGarbageResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleGetHeapObjectIdResponse(base::OnceCallback<void(std::unique_ptr<GetHeapObjectIdResult>)> callback, const base::Value& response);
  static void HandleGetObjectByHeapObjectIdResponse(base::OnceCallback<void(std::unique_ptr<GetObjectByHeapObjectIdResult>)> callback, const base::Value& response);
  static void HandleGetSamplingProfileResponse(base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)> callback, const base::Value& response);
  static void HandleStartSamplingResponse(base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)> callback, const base::Value& response);
  static void HandleStartTrackingHeapObjectsResponse(base::OnceCallback<void(std::unique_ptr<StartTrackingHeapObjectsResult>)> callback, const base::Value& response);
  static void HandleStopSamplingResponse(base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)> callback, const base::Value& response);
  static void HandleStopTrackingHeapObjectsResponse(base::OnceCallback<void(std::unique_ptr<StopTrackingHeapObjectsResult>)> callback, const base::Value& response);
  static void HandleTakeHeapSnapshotResponse(base::OnceCallback<void(std::unique_ptr<TakeHeapSnapshotResult>)> callback, const base::Value& response);

  void DispatchAddHeapSnapshotChunkEvent(const base::Value& params);
  void DispatchHeapStatsUpdateEvent(const base::Value& params);
  void DispatchLastSeenObjectIdEvent(const base::Value& params);
  void DispatchReportHeapSnapshotProgressEvent(const base::Value& params);
  void DispatchResetProfilesEvent(const base::Value& params);

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

  // Enables console to refer to the node with given id via $x (see Command Line API for more details
  // $x functions).
  void AddInspectedHeapObject(std::unique_ptr<AddInspectedHeapObjectParams> params, base::OnceCallback<void(std::unique_ptr<AddInspectedHeapObjectResult>)> callback = base::OnceCallback<void(std::unique_ptr<AddInspectedHeapObjectResult>)>());

  void CollectGarbage(std::unique_ptr<CollectGarbageParams> params, base::OnceCallback<void(std::unique_ptr<CollectGarbageResult>)> callback = base::OnceCallback<void(std::unique_ptr<CollectGarbageResult>)>());

  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  void GetHeapObjectId(std::unique_ptr<GetHeapObjectIdParams> params, base::OnceCallback<void(std::unique_ptr<GetHeapObjectIdResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetHeapObjectIdResult>)>());

  void GetObjectByHeapObjectId(std::unique_ptr<GetObjectByHeapObjectIdParams> params, base::OnceCallback<void(std::unique_ptr<GetObjectByHeapObjectIdResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetObjectByHeapObjectIdResult>)>());

  void GetSamplingProfile(std::unique_ptr<GetSamplingProfileParams> params, base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetSamplingProfileResult>)>());

  void StartSampling(std::unique_ptr<StartSamplingParams> params, base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartSamplingResult>)>());

  void StartTrackingHeapObjects(std::unique_ptr<StartTrackingHeapObjectsParams> params, base::OnceCallback<void(std::unique_ptr<StartTrackingHeapObjectsResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartTrackingHeapObjectsResult>)>());

  void StopSampling(std::unique_ptr<StopSamplingParams> params, base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopSamplingResult>)>());

  void StopTrackingHeapObjects(std::unique_ptr<StopTrackingHeapObjectsParams> params, base::OnceCallback<void(std::unique_ptr<StopTrackingHeapObjectsResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopTrackingHeapObjectsResult>)>());

  void TakeHeapSnapshot(std::unique_ptr<TakeHeapSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<TakeHeapSnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<TakeHeapSnapshotResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace heap_profiler
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_HEAP_PROFILER_H_
