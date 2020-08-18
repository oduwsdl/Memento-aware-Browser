// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_OVERLAY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_OVERLAY_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_overlay.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<overlay::GridHighlightConfig> {
  static std::unique_ptr<overlay::GridHighlightConfig> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::GridHighlightConfig::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::GridHighlightConfig& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightConfig> {
  static std::unique_ptr<overlay::HighlightConfig> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightConfig::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightConfig& value) {
  return value.Serialize();
}

template <>
struct FromValue<overlay::ColorFormat> {
  static overlay::ColorFormat Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return overlay::ColorFormat::RGB;
    }
    if (value.GetString() == "rgb")
      return overlay::ColorFormat::RGB;
    if (value.GetString() == "hsl")
      return overlay::ColorFormat::HSL;
    if (value.GetString() == "hex")
      return overlay::ColorFormat::HEX;
    errors->AddError("invalid enum value");
    return overlay::ColorFormat::RGB;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::ColorFormat& value) {
  switch (value) {
    case overlay::ColorFormat::RGB:
      return std::make_unique<base::Value>("rgb");
    case overlay::ColorFormat::HSL:
      return std::make_unique<base::Value>("hsl");
    case overlay::ColorFormat::HEX:
      return std::make_unique<base::Value>("hex");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<overlay::HingeConfig> {
  static std::unique_ptr<overlay::HingeConfig> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HingeConfig::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HingeConfig& value) {
  return value.Serialize();
}

template <>
struct FromValue<overlay::InspectMode> {
  static overlay::InspectMode Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return overlay::InspectMode::SEARCH_FOR_NODE;
    }
    if (value.GetString() == "searchForNode")
      return overlay::InspectMode::SEARCH_FOR_NODE;
    if (value.GetString() == "searchForUAShadowDOM")
      return overlay::InspectMode::SEARCH_FORUA_SHADOWDOM;
    if (value.GetString() == "captureAreaScreenshot")
      return overlay::InspectMode::CAPTURE_AREA_SCREENSHOT;
    if (value.GetString() == "showDistances")
      return overlay::InspectMode::SHOW_DISTANCES;
    if (value.GetString() == "none")
      return overlay::InspectMode::NONE;
    errors->AddError("invalid enum value");
    return overlay::InspectMode::SEARCH_FOR_NODE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::InspectMode& value) {
  switch (value) {
    case overlay::InspectMode::SEARCH_FOR_NODE:
      return std::make_unique<base::Value>("searchForNode");
    case overlay::InspectMode::SEARCH_FORUA_SHADOWDOM:
      return std::make_unique<base::Value>("searchForUAShadowDOM");
    case overlay::InspectMode::CAPTURE_AREA_SCREENSHOT:
      return std::make_unique<base::Value>("captureAreaScreenshot");
    case overlay::InspectMode::SHOW_DISTANCES:
      return std::make_unique<base::Value>("showDistances");
    case overlay::InspectMode::NONE:
      return std::make_unique<base::Value>("none");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<overlay::DisableParams> {
  static std::unique_ptr<overlay::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::DisableResult> {
  static std::unique_ptr<overlay::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::EnableParams> {
  static std::unique_ptr<overlay::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::EnableResult> {
  static std::unique_ptr<overlay::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::GetHighlightObjectForTestParams> {
  static std::unique_ptr<overlay::GetHighlightObjectForTestParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::GetHighlightObjectForTestParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::GetHighlightObjectForTestParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::GetHighlightObjectForTestResult> {
  static std::unique_ptr<overlay::GetHighlightObjectForTestResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::GetHighlightObjectForTestResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::GetHighlightObjectForTestResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HideHighlightParams> {
  static std::unique_ptr<overlay::HideHighlightParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HideHighlightParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HideHighlightParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HideHighlightResult> {
  static std::unique_ptr<overlay::HideHighlightResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HideHighlightResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HideHighlightResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightFrameParams> {
  static std::unique_ptr<overlay::HighlightFrameParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightFrameParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightFrameParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightFrameResult> {
  static std::unique_ptr<overlay::HighlightFrameResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightFrameResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightFrameResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightNodeParams> {
  static std::unique_ptr<overlay::HighlightNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightNodeResult> {
  static std::unique_ptr<overlay::HighlightNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightQuadParams> {
  static std::unique_ptr<overlay::HighlightQuadParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightQuadParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightQuadParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightQuadResult> {
  static std::unique_ptr<overlay::HighlightQuadResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightQuadResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightQuadResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightRectParams> {
  static std::unique_ptr<overlay::HighlightRectParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightRectParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightRectParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::HighlightRectResult> {
  static std::unique_ptr<overlay::HighlightRectResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::HighlightRectResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::HighlightRectResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetInspectModeParams> {
  static std::unique_ptr<overlay::SetInspectModeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetInspectModeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetInspectModeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetInspectModeResult> {
  static std::unique_ptr<overlay::SetInspectModeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetInspectModeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetInspectModeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowAdHighlightsParams> {
  static std::unique_ptr<overlay::SetShowAdHighlightsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowAdHighlightsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowAdHighlightsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowAdHighlightsResult> {
  static std::unique_ptr<overlay::SetShowAdHighlightsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowAdHighlightsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowAdHighlightsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetPausedInDebuggerMessageParams> {
  static std::unique_ptr<overlay::SetPausedInDebuggerMessageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetPausedInDebuggerMessageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetPausedInDebuggerMessageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetPausedInDebuggerMessageResult> {
  static std::unique_ptr<overlay::SetPausedInDebuggerMessageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetPausedInDebuggerMessageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetPausedInDebuggerMessageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowDebugBordersParams> {
  static std::unique_ptr<overlay::SetShowDebugBordersParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowDebugBordersParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowDebugBordersParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowDebugBordersResult> {
  static std::unique_ptr<overlay::SetShowDebugBordersResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowDebugBordersResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowDebugBordersResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowFPSCounterParams> {
  static std::unique_ptr<overlay::SetShowFPSCounterParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowFPSCounterParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowFPSCounterParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowFPSCounterResult> {
  static std::unique_ptr<overlay::SetShowFPSCounterResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowFPSCounterResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowFPSCounterResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowPaintRectsParams> {
  static std::unique_ptr<overlay::SetShowPaintRectsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowPaintRectsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowPaintRectsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowPaintRectsResult> {
  static std::unique_ptr<overlay::SetShowPaintRectsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowPaintRectsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowPaintRectsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowLayoutShiftRegionsParams> {
  static std::unique_ptr<overlay::SetShowLayoutShiftRegionsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowLayoutShiftRegionsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowLayoutShiftRegionsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowLayoutShiftRegionsResult> {
  static std::unique_ptr<overlay::SetShowLayoutShiftRegionsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowLayoutShiftRegionsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowLayoutShiftRegionsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowScrollBottleneckRectsParams> {
  static std::unique_ptr<overlay::SetShowScrollBottleneckRectsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowScrollBottleneckRectsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowScrollBottleneckRectsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowScrollBottleneckRectsResult> {
  static std::unique_ptr<overlay::SetShowScrollBottleneckRectsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowScrollBottleneckRectsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowScrollBottleneckRectsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowHitTestBordersParams> {
  static std::unique_ptr<overlay::SetShowHitTestBordersParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowHitTestBordersParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowHitTestBordersParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowHitTestBordersResult> {
  static std::unique_ptr<overlay::SetShowHitTestBordersResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowHitTestBordersResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowHitTestBordersResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowViewportSizeOnResizeParams> {
  static std::unique_ptr<overlay::SetShowViewportSizeOnResizeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowViewportSizeOnResizeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowViewportSizeOnResizeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowViewportSizeOnResizeResult> {
  static std::unique_ptr<overlay::SetShowViewportSizeOnResizeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowViewportSizeOnResizeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowViewportSizeOnResizeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowHingeParams> {
  static std::unique_ptr<overlay::SetShowHingeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowHingeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowHingeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::SetShowHingeResult> {
  static std::unique_ptr<overlay::SetShowHingeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::SetShowHingeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::SetShowHingeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::InspectNodeRequestedParams> {
  static std::unique_ptr<overlay::InspectNodeRequestedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::InspectNodeRequestedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::InspectNodeRequestedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::NodeHighlightRequestedParams> {
  static std::unique_ptr<overlay::NodeHighlightRequestedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::NodeHighlightRequestedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::NodeHighlightRequestedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::ScreenshotRequestedParams> {
  static std::unique_ptr<overlay::ScreenshotRequestedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::ScreenshotRequestedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::ScreenshotRequestedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<overlay::InspectModeCanceledParams> {
  static std::unique_ptr<overlay::InspectModeCanceledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return overlay::InspectModeCanceledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const overlay::InspectModeCanceledParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_OVERLAY_H_
