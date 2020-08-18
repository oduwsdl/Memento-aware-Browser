// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/overlay.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace overlay {

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
      "Overlay.inspectNodeRequested",
      base::BindRepeating(&Domain::DispatchInspectNodeRequestedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Overlay.nodeHighlightRequested",
      base::BindRepeating(&Domain::DispatchNodeHighlightRequestedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Overlay.screenshotRequested",
      base::BindRepeating(&Domain::DispatchScreenshotRequestedEvent,
                          base::Unretained(this)));
  dispatcher_->RegisterEventHandler(
      "Overlay.inspectModeCanceled",
      base::BindRepeating(&Domain::DispatchInspectModeCanceledEvent,
                          base::Unretained(this)));
}

void ExperimentalDomain::Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback) {
  dispatcher_->SendMessage("Overlay.disable", params->Serialize(), base::BindOnce(&Domain::HandleDisableResponse, std::move(callback)));
}
void ExperimentalDomain::Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback) {
  dispatcher_->SendMessage("Overlay.enable", params->Serialize(), base::BindOnce(&Domain::HandleEnableResponse, std::move(callback)));
}
void ExperimentalDomain::GetHighlightObjectForTest(std::unique_ptr<GetHighlightObjectForTestParams> params, base::OnceCallback<void(std::unique_ptr<GetHighlightObjectForTestResult>)> callback) {
  dispatcher_->SendMessage("Overlay.getHighlightObjectForTest", params->Serialize(), base::BindOnce(&Domain::HandleGetHighlightObjectForTestResponse, std::move(callback)));
}
void ExperimentalDomain::HideHighlight(std::unique_ptr<HideHighlightParams> params, base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)> callback) {
  dispatcher_->SendMessage("Overlay.hideHighlight", params->Serialize(), base::BindOnce(&Domain::HandleHideHighlightResponse, std::move(callback)));
}
void ExperimentalDomain::HighlightFrame(std::unique_ptr<HighlightFrameParams> params, base::OnceCallback<void(std::unique_ptr<HighlightFrameResult>)> callback) {
  dispatcher_->SendMessage("Overlay.highlightFrame", params->Serialize(), base::BindOnce(&Domain::HandleHighlightFrameResponse, std::move(callback)));
}
void ExperimentalDomain::HighlightNode(std::unique_ptr<HighlightNodeParams> params, base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)> callback) {
  dispatcher_->SendMessage("Overlay.highlightNode", params->Serialize(), base::BindOnce(&Domain::HandleHighlightNodeResponse, std::move(callback)));
}
void ExperimentalDomain::HighlightQuad(std::unique_ptr<HighlightQuadParams> params, base::OnceCallback<void(std::unique_ptr<HighlightQuadResult>)> callback) {
  dispatcher_->SendMessage("Overlay.highlightQuad", params->Serialize(), base::BindOnce(&Domain::HandleHighlightQuadResponse, std::move(callback)));
}
void ExperimentalDomain::HighlightRect(std::unique_ptr<HighlightRectParams> params, base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)> callback) {
  dispatcher_->SendMessage("Overlay.highlightRect", params->Serialize(), base::BindOnce(&Domain::HandleHighlightRectResponse, std::move(callback)));
}
void ExperimentalDomain::SetInspectMode(std::unique_ptr<SetInspectModeParams> params, base::OnceCallback<void(std::unique_ptr<SetInspectModeResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setInspectMode", params->Serialize(), base::BindOnce(&Domain::HandleSetInspectModeResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowAdHighlights(std::unique_ptr<SetShowAdHighlightsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowAdHighlightsResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowAdHighlights", params->Serialize(), base::BindOnce(&Domain::HandleSetShowAdHighlightsResponse, std::move(callback)));
}
void ExperimentalDomain::SetPausedInDebuggerMessage(std::unique_ptr<SetPausedInDebuggerMessageParams> params, base::OnceCallback<void(std::unique_ptr<SetPausedInDebuggerMessageResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setPausedInDebuggerMessage", params->Serialize(), base::BindOnce(&Domain::HandleSetPausedInDebuggerMessageResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowDebugBorders(std::unique_ptr<SetShowDebugBordersParams> params, base::OnceCallback<void(std::unique_ptr<SetShowDebugBordersResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowDebugBorders", params->Serialize(), base::BindOnce(&Domain::HandleSetShowDebugBordersResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowFPSCounter(std::unique_ptr<SetShowFPSCounterParams> params, base::OnceCallback<void(std::unique_ptr<SetShowFPSCounterResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowFPSCounter", params->Serialize(), base::BindOnce(&Domain::HandleSetShowFPSCounterResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowPaintRects(std::unique_ptr<SetShowPaintRectsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowPaintRectsResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowPaintRects", params->Serialize(), base::BindOnce(&Domain::HandleSetShowPaintRectsResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowLayoutShiftRegions(std::unique_ptr<SetShowLayoutShiftRegionsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowLayoutShiftRegionsResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowLayoutShiftRegions", params->Serialize(), base::BindOnce(&Domain::HandleSetShowLayoutShiftRegionsResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowScrollBottleneckRects(std::unique_ptr<SetShowScrollBottleneckRectsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowScrollBottleneckRectsResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowScrollBottleneckRects", params->Serialize(), base::BindOnce(&Domain::HandleSetShowScrollBottleneckRectsResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowHitTestBorders(std::unique_ptr<SetShowHitTestBordersParams> params, base::OnceCallback<void(std::unique_ptr<SetShowHitTestBordersResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowHitTestBorders", params->Serialize(), base::BindOnce(&Domain::HandleSetShowHitTestBordersResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowViewportSizeOnResize(std::unique_ptr<SetShowViewportSizeOnResizeParams> params, base::OnceCallback<void(std::unique_ptr<SetShowViewportSizeOnResizeResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowViewportSizeOnResize", params->Serialize(), base::BindOnce(&Domain::HandleSetShowViewportSizeOnResizeResponse, std::move(callback)));
}
void ExperimentalDomain::SetShowHinge(std::unique_ptr<SetShowHingeParams> params, base::OnceCallback<void(std::unique_ptr<SetShowHingeResult>)> callback) {
  dispatcher_->SendMessage("Overlay.setShowHinge", params->Serialize(), base::BindOnce(&Domain::HandleSetShowHingeResponse, std::move(callback)));
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
void Domain::HandleGetHighlightObjectForTestResponse(base::OnceCallback<void(std::unique_ptr<GetHighlightObjectForTestResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetHighlightObjectForTestResult> result = GetHighlightObjectForTestResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleHideHighlightResponse(base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<HideHighlightResult> result = HideHighlightResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleHighlightFrameResponse(base::OnceCallback<void(std::unique_ptr<HighlightFrameResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<HighlightFrameResult> result = HighlightFrameResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleHighlightNodeResponse(base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<HighlightNodeResult> result = HighlightNodeResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleHighlightQuadResponse(base::OnceCallback<void(std::unique_ptr<HighlightQuadResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<HighlightQuadResult> result = HighlightQuadResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleHighlightRectResponse(base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<HighlightRectResult> result = HighlightRectResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetInspectModeResponse(base::OnceCallback<void(std::unique_ptr<SetInspectModeResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetInspectModeResult> result = SetInspectModeResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowAdHighlightsResponse(base::OnceCallback<void(std::unique_ptr<SetShowAdHighlightsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowAdHighlightsResult> result = SetShowAdHighlightsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetPausedInDebuggerMessageResponse(base::OnceCallback<void(std::unique_ptr<SetPausedInDebuggerMessageResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetPausedInDebuggerMessageResult> result = SetPausedInDebuggerMessageResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowDebugBordersResponse(base::OnceCallback<void(std::unique_ptr<SetShowDebugBordersResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowDebugBordersResult> result = SetShowDebugBordersResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowFPSCounterResponse(base::OnceCallback<void(std::unique_ptr<SetShowFPSCounterResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowFPSCounterResult> result = SetShowFPSCounterResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowPaintRectsResponse(base::OnceCallback<void(std::unique_ptr<SetShowPaintRectsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowPaintRectsResult> result = SetShowPaintRectsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowLayoutShiftRegionsResponse(base::OnceCallback<void(std::unique_ptr<SetShowLayoutShiftRegionsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowLayoutShiftRegionsResult> result = SetShowLayoutShiftRegionsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowScrollBottleneckRectsResponse(base::OnceCallback<void(std::unique_ptr<SetShowScrollBottleneckRectsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowScrollBottleneckRectsResult> result = SetShowScrollBottleneckRectsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowHitTestBordersResponse(base::OnceCallback<void(std::unique_ptr<SetShowHitTestBordersResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowHitTestBordersResult> result = SetShowHitTestBordersResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowViewportSizeOnResizeResponse(base::OnceCallback<void(std::unique_ptr<SetShowViewportSizeOnResizeResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowViewportSizeOnResizeResult> result = SetShowViewportSizeOnResizeResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleSetShowHingeResponse(base::OnceCallback<void(std::unique_ptr<SetShowHingeResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<SetShowHingeResult> result = SetShowHingeResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

void Domain::DispatchInspectNodeRequestedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<InspectNodeRequestedParams> parsed_params(InspectNodeRequestedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnInspectNodeRequested(*parsed_params);
  }
}

void Domain::DispatchNodeHighlightRequestedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<NodeHighlightRequestedParams> parsed_params(NodeHighlightRequestedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnNodeHighlightRequested(*parsed_params);
  }
}

void Domain::DispatchScreenshotRequestedEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<ScreenshotRequestedParams> parsed_params(ScreenshotRequestedParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnScreenshotRequested(*parsed_params);
  }
}

void Domain::DispatchInspectModeCanceledEvent(const base::Value& params) {
  ErrorReporter errors;
  std::unique_ptr<InspectModeCanceledParams> parsed_params(InspectModeCanceledParams::Parse(params, &errors));
  DCHECK(!errors.HasErrors()) << errors.ToString();
  for (ExperimentalObserver& observer : observers_) {
    observer.OnInspectModeCanceled(*parsed_params);
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

}  // namespace overlay

} // namespace headless
