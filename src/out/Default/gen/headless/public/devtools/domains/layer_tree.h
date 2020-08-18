// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_LAYER_TREE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_LAYER_TREE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_layer_tree.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace layer_tree {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnLayerPainted(const LayerPaintedParams& params) {}
  virtual void OnLayerTreeDidChange(const LayerTreeDidChangeParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnLayerPainted(const LayerPaintedParams& params) final {}
  virtual void OnLayerTreeDidChange(const LayerTreeDidChangeParams& params) final {}
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

  static void HandleCompositingReasonsResponse(base::OnceCallback<void(std::unique_ptr<CompositingReasonsResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleLoadSnapshotResponse(base::OnceCallback<void(std::unique_ptr<LoadSnapshotResult>)> callback, const base::Value& response);
  static void HandleMakeSnapshotResponse(base::OnceCallback<void(std::unique_ptr<MakeSnapshotResult>)> callback, const base::Value& response);
  static void HandleProfileSnapshotResponse(base::OnceCallback<void(std::unique_ptr<ProfileSnapshotResult>)> callback, const base::Value& response);
  static void HandleReleaseSnapshotResponse(base::OnceCallback<void(std::unique_ptr<ReleaseSnapshotResult>)> callback, const base::Value& response);
  static void HandleReplaySnapshotResponse(base::OnceCallback<void(std::unique_ptr<ReplaySnapshotResult>)> callback, const base::Value& response);
  static void HandleSnapshotCommandLogResponse(base::OnceCallback<void(std::unique_ptr<SnapshotCommandLogResult>)> callback, const base::Value& response);

  void DispatchLayerPaintedEvent(const base::Value& params);
  void DispatchLayerTreeDidChangeEvent(const base::Value& params);

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

  // Provides the reasons why the given layer was composited.
  void CompositingReasons(std::unique_ptr<CompositingReasonsParams> params, base::OnceCallback<void(std::unique_ptr<CompositingReasonsResult>)> callback = base::OnceCallback<void(std::unique_ptr<CompositingReasonsResult>)>());

  // Disables compositing tree inspection.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables compositing tree inspection.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Returns the snapshot identifier.
  void LoadSnapshot(std::unique_ptr<LoadSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<LoadSnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<LoadSnapshotResult>)>());

  // Returns the layer snapshot identifier.
  void MakeSnapshot(std::unique_ptr<MakeSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<MakeSnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<MakeSnapshotResult>)>());

  void ProfileSnapshot(std::unique_ptr<ProfileSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<ProfileSnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<ProfileSnapshotResult>)>());

  // Releases layer snapshot captured by the back-end.
  void ReleaseSnapshot(std::unique_ptr<ReleaseSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<ReleaseSnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<ReleaseSnapshotResult>)>());

  // Replays the layer snapshot and returns the resulting bitmap.
  void ReplaySnapshot(std::unique_ptr<ReplaySnapshotParams> params, base::OnceCallback<void(std::unique_ptr<ReplaySnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<ReplaySnapshotResult>)>());

  // Replays the layer snapshot and returns canvas log.
  void SnapshotCommandLog(std::unique_ptr<SnapshotCommandLogParams> params, base::OnceCallback<void(std::unique_ptr<SnapshotCommandLogResult>)> callback = base::OnceCallback<void(std::unique_ptr<SnapshotCommandLogResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace layer_tree
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_LAYER_TREE_H_
