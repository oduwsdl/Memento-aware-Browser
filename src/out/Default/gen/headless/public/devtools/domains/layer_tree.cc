// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/layer_tree.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace layer_tree {

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
      "LayerTree.layerPainted",
      base::BindRepeating(&Domain::DispatchLayerPaintedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "LayerTree.layerTreeDidChange",
      base::BindRepeating(&Domain::DispatchLayerTreeDidChangeEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::CompositingReasons(std::unique_ptr<CompositingReasonsParams> params, base::OnceCallback<void(std::unique_ptr<CompositingReasonsResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.compositingReasons", params->Serialize(), base::BindOnce(&Domain::HandleCompositingReasonsResponse, std::move(callback)));
}
void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}
void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::LoadSnapshot(std::unique_ptr<LoadSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<LoadSnapshotResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.loadSnapshot", params->Serialize(), base::BindOnce(&Domain::HandleLoadSnapshotResponse, std::move(callback)));
}
void ExperimentalDomain::MakeSnapshot(std::unique_ptr<MakeSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<MakeSnapshotResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.makeSnapshot", params->Serialize(), base::BindOnce(&Domain::HandleMakeSnapshotResponse, std::move(callback)));
}
void ExperimentalDomain::ProfileSnapshot(std::unique_ptr<ProfileSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<ProfileSnapshotResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.profileSnapshot", params->Serialize(), base::BindOnce(&Domain::HandleProfileSnapshotResponse, std::move(callback)));
}
void ExperimentalDomain::ReleaseSnapshot(std::unique_ptr<ReleaseSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<ReleaseSnapshotResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.releaseSnapshot", params->Serialize(), base::BindOnce(&Domain::HandleReleaseSnapshotResponse, std::move(callback)));
}
void ExperimentalDomain::ReplaySnapshot(std::unique_ptr<ReplaySnapshotParams> params, base::OnceCallback<void(std::unique_ptr<ReplaySnapshotResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.replaySnapshot", params->Serialize(), base::BindOnce(&Domain::HandleReplaySnapshotResponse, std::move(callback)));
}
void ExperimentalDomain::SnapshotCommandLog(std::unique_ptr<SnapshotCommandLogParams> params, base::OnceCallback<void(std::unique_ptr<SnapshotCommandLogResult>)> callback) {
  dispatcher_->SendMessage("LayerTree.snapshotCommandLog", params->Serialize(), base::BindOnce(&Domain::HandleSnapshotCommandLogResponse, std::move(callback)));
}


// static
void Domain::HandleCompositingReasonsResponse(base::OnceCallback<void(std::unique_ptr<CompositingReasonsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CompositingReasonsResult> result = CompositingReasonsResult::Parse(response, &errors);
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
void Domain::HandleLoadSnapshotResponse(base::OnceCallback<void(std::unique_ptr<LoadSnapshotResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<LoadSnapshotResult> result = LoadSnapshotResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleMakeSnapshotResponse(base::OnceCallback<void(std::unique_ptr<MakeSnapshotResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<MakeSnapshotResult> result = MakeSnapshotResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleProfileSnapshotResponse(base::OnceCallback<void(std::unique_ptr<ProfileSnapshotResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ProfileSnapshotResult> result = ProfileSnapshotResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleReleaseSnapshotResponse(base::OnceCallback<void(std::unique_ptr<ReleaseSnapshotResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ReleaseSnapshotResult> result = ReleaseSnapshotResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleReplaySnapshotResponse(base::OnceCallback<void(std::unique_ptr<ReplaySnapshotResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ReplaySnapshotResult> result = ReplaySnapshotResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSnapshotCommandLogResponse(base::OnceCallback<void(std::unique_ptr<SnapshotCommandLogResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SnapshotCommandLogResult> result = SnapshotCommandLogResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchLayerPaintedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<LayerPaintedParams> parsed_params(LayerPaintedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnLayerPainted(*parsed_params);
  }
}

void Domain::DispatchLayerTreeDidChangeEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<LayerTreeDidChangeParams> parsed_params(LayerTreeDidChangeParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnLayerTreeDidChange(*parsed_params);
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

}  // namespace layer_tree

} // namespace headless
