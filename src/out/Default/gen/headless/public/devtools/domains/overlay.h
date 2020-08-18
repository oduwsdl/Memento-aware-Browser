// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_OVERLAY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_OVERLAY_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_overlay.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace overlay {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Fired when the node should be inspected. This happens after call to `setInspectMode` or when
  // user manually inspects an element.
  virtual void OnInspectNodeRequested(const InspectNodeRequestedParams& params) {}
  // Fired when the node should be highlighted. This happens after call to `setInspectMode`.
  virtual void OnNodeHighlightRequested(const NodeHighlightRequestedParams& params) {}
  // Fired when user asks to capture screenshot of some area on the page.
  virtual void OnScreenshotRequested(const ScreenshotRequestedParams& params) {}
  // Fired when user cancels the inspect mode.
  virtual void OnInspectModeCanceled(const InspectModeCanceledParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: Fired when the node should be inspected. This happens after call to `setInspectMode` or when
  // user manually inspects an element.
  virtual void OnInspectNodeRequested(const InspectNodeRequestedParams& params) final {}
  // Experimental: Fired when the node should be highlighted. This happens after call to `setInspectMode`.
  virtual void OnNodeHighlightRequested(const NodeHighlightRequestedParams& params) final {}
  // Experimental: Fired when user asks to capture screenshot of some area on the page.
  virtual void OnScreenshotRequested(const ScreenshotRequestedParams& params) final {}
  // Experimental: Fired when user cancels the inspect mode.
  virtual void OnInspectModeCanceled(const InspectModeCanceledParams& params) final {}
};

// This domain provides various functionality related to drawing atop the inspected page.
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
  static void HandleGetHighlightObjectForTestResponse(base::OnceCallback<void(std::unique_ptr<GetHighlightObjectForTestResult>)> callback, const base::Value& response);
  static void HandleHideHighlightResponse(base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)> callback, const base::Value& response);
  static void HandleHighlightFrameResponse(base::OnceCallback<void(std::unique_ptr<HighlightFrameResult>)> callback, const base::Value& response);
  static void HandleHighlightNodeResponse(base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)> callback, const base::Value& response);
  static void HandleHighlightQuadResponse(base::OnceCallback<void(std::unique_ptr<HighlightQuadResult>)> callback, const base::Value& response);
  static void HandleHighlightRectResponse(base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)> callback, const base::Value& response);
  static void HandleSetInspectModeResponse(base::OnceCallback<void(std::unique_ptr<SetInspectModeResult>)> callback, const base::Value& response);
  static void HandleSetShowAdHighlightsResponse(base::OnceCallback<void(std::unique_ptr<SetShowAdHighlightsResult>)> callback, const base::Value& response);
  static void HandleSetPausedInDebuggerMessageResponse(base::OnceCallback<void(std::unique_ptr<SetPausedInDebuggerMessageResult>)> callback, const base::Value& response);
  static void HandleSetShowDebugBordersResponse(base::OnceCallback<void(std::unique_ptr<SetShowDebugBordersResult>)> callback, const base::Value& response);
  static void HandleSetShowFPSCounterResponse(base::OnceCallback<void(std::unique_ptr<SetShowFPSCounterResult>)> callback, const base::Value& response);
  static void HandleSetShowPaintRectsResponse(base::OnceCallback<void(std::unique_ptr<SetShowPaintRectsResult>)> callback, const base::Value& response);
  static void HandleSetShowLayoutShiftRegionsResponse(base::OnceCallback<void(std::unique_ptr<SetShowLayoutShiftRegionsResult>)> callback, const base::Value& response);
  static void HandleSetShowScrollBottleneckRectsResponse(base::OnceCallback<void(std::unique_ptr<SetShowScrollBottleneckRectsResult>)> callback, const base::Value& response);
  static void HandleSetShowHitTestBordersResponse(base::OnceCallback<void(std::unique_ptr<SetShowHitTestBordersResult>)> callback, const base::Value& response);
  static void HandleSetShowViewportSizeOnResizeResponse(base::OnceCallback<void(std::unique_ptr<SetShowViewportSizeOnResizeResult>)> callback, const base::Value& response);
  static void HandleSetShowHingeResponse(base::OnceCallback<void(std::unique_ptr<SetShowHingeResult>)> callback, const base::Value& response);

  void DispatchInspectNodeRequestedEvent(const base::Value& params);
  void DispatchNodeHighlightRequestedEvent(const base::Value& params);
  void DispatchScreenshotRequestedEvent(const base::Value& params);
  void DispatchInspectModeCanceledEvent(const base::Value& params);

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

  // Disables domain notifications.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables domain notifications.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // For testing.
  void GetHighlightObjectForTest(std::unique_ptr<GetHighlightObjectForTestParams> params, base::OnceCallback<void(std::unique_ptr<GetHighlightObjectForTestResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetHighlightObjectForTestResult>)>());

  // Hides any highlight.
  void HideHighlight(std::unique_ptr<HideHighlightParams> params, base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)> callback = base::OnceCallback<void(std::unique_ptr<HideHighlightResult>)>());

  // Highlights owner element of the frame with given id.
  void HighlightFrame(std::unique_ptr<HighlightFrameParams> params, base::OnceCallback<void(std::unique_ptr<HighlightFrameResult>)> callback = base::OnceCallback<void(std::unique_ptr<HighlightFrameResult>)>());

  // Highlights DOM node with given id or with the given JavaScript object wrapper. Either nodeId or
  // objectId must be specified.
  void HighlightNode(std::unique_ptr<HighlightNodeParams> params, base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)> callback = base::OnceCallback<void(std::unique_ptr<HighlightNodeResult>)>());

  // Highlights given quad. Coordinates are absolute with respect to the main frame viewport.
  void HighlightQuad(std::unique_ptr<HighlightQuadParams> params, base::OnceCallback<void(std::unique_ptr<HighlightQuadResult>)> callback = base::OnceCallback<void(std::unique_ptr<HighlightQuadResult>)>());

  // Highlights given rectangle. Coordinates are absolute with respect to the main frame viewport.
  void HighlightRect(std::unique_ptr<HighlightRectParams> params, base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)> callback = base::OnceCallback<void(std::unique_ptr<HighlightRectResult>)>());

  // Enters the 'inspect' mode. In this mode, elements that user is hovering over are highlighted.
  // Backend then generates 'inspectNodeRequested' event upon element selection.
  void SetInspectMode(std::unique_ptr<SetInspectModeParams> params, base::OnceCallback<void(std::unique_ptr<SetInspectModeResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetInspectModeResult>)>());

  // Highlights owner element of all frames detected to be ads.
  void SetShowAdHighlights(std::unique_ptr<SetShowAdHighlightsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowAdHighlightsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowAdHighlightsResult>)>());

  void SetPausedInDebuggerMessage(std::unique_ptr<SetPausedInDebuggerMessageParams> params, base::OnceCallback<void(std::unique_ptr<SetPausedInDebuggerMessageResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetPausedInDebuggerMessageResult>)>());

  // Requests that backend shows debug borders on layers
  void SetShowDebugBorders(std::unique_ptr<SetShowDebugBordersParams> params, base::OnceCallback<void(std::unique_ptr<SetShowDebugBordersResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowDebugBordersResult>)>());

  // Requests that backend shows the FPS counter
  void SetShowFPSCounter(std::unique_ptr<SetShowFPSCounterParams> params, base::OnceCallback<void(std::unique_ptr<SetShowFPSCounterResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowFPSCounterResult>)>());

  // Requests that backend shows paint rectangles
  void SetShowPaintRects(std::unique_ptr<SetShowPaintRectsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowPaintRectsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowPaintRectsResult>)>());

  // Requests that backend shows layout shift regions
  void SetShowLayoutShiftRegions(std::unique_ptr<SetShowLayoutShiftRegionsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowLayoutShiftRegionsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowLayoutShiftRegionsResult>)>());

  // Requests that backend shows scroll bottleneck rects
  void SetShowScrollBottleneckRects(std::unique_ptr<SetShowScrollBottleneckRectsParams> params, base::OnceCallback<void(std::unique_ptr<SetShowScrollBottleneckRectsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowScrollBottleneckRectsResult>)>());

  // Requests that backend shows hit-test borders on layers
  void SetShowHitTestBorders(std::unique_ptr<SetShowHitTestBordersParams> params, base::OnceCallback<void(std::unique_ptr<SetShowHitTestBordersResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowHitTestBordersResult>)>());

  // Paints viewport size upon main frame resize.
  void SetShowViewportSizeOnResize(std::unique_ptr<SetShowViewportSizeOnResizeParams> params, base::OnceCallback<void(std::unique_ptr<SetShowViewportSizeOnResizeResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowViewportSizeOnResizeResult>)>());

  // Add a dual screen device hinge
  void SetShowHinge(std::unique_ptr<SetShowHingeParams> params, base::OnceCallback<void(std::unique_ptr<SetShowHingeResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetShowHingeResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace overlay
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_OVERLAY_H_
