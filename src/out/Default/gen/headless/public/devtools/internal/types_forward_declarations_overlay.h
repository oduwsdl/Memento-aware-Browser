// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_OVERLAY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_OVERLAY_H_

#include "base/values.h"

namespace headless {

namespace overlay {
class GridHighlightConfig;
class HighlightConfig;
class HingeConfig;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class GetHighlightObjectForTestParams;
class GetHighlightObjectForTestResult;
class HideHighlightParams;
class HideHighlightResult;
class HighlightFrameParams;
class HighlightFrameResult;
class HighlightNodeParams;
class HighlightNodeResult;
class HighlightQuadParams;
class HighlightQuadResult;
class HighlightRectParams;
class HighlightRectResult;
class SetInspectModeParams;
class SetInspectModeResult;
class SetShowAdHighlightsParams;
class SetShowAdHighlightsResult;
class SetPausedInDebuggerMessageParams;
class SetPausedInDebuggerMessageResult;
class SetShowDebugBordersParams;
class SetShowDebugBordersResult;
class SetShowFPSCounterParams;
class SetShowFPSCounterResult;
class SetShowPaintRectsParams;
class SetShowPaintRectsResult;
class SetShowLayoutShiftRegionsParams;
class SetShowLayoutShiftRegionsResult;
class SetShowScrollBottleneckRectsParams;
class SetShowScrollBottleneckRectsResult;
class SetShowHitTestBordersParams;
class SetShowHitTestBordersResult;
class SetShowViewportSizeOnResizeParams;
class SetShowViewportSizeOnResizeResult;
class SetShowHingeParams;
class SetShowHingeResult;
class InspectNodeRequestedParams;
class NodeHighlightRequestedParams;
class ScreenshotRequestedParams;
class InspectModeCanceledParams;

enum class ColorFormat {
  RGB,
  HSL,
  HEX
};

enum class InspectMode {
  SEARCH_FOR_NODE,
  SEARCH_FORUA_SHADOWDOM,
  CAPTURE_AREA_SCREENSHOT,
  SHOW_DISTANCES,
  NONE
};

}  // namespace overlay

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_OVERLAY_H_
