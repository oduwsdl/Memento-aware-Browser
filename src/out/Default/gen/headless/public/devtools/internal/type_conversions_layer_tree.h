// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_LAYER_TREE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_LAYER_TREE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_layer_tree.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {




template <>
struct FromValue<layer_tree::ScrollRect> {
  static std::unique_ptr<layer_tree::ScrollRect> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::ScrollRect::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ScrollRect& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::StickyPositionConstraint> {
  static std::unique_ptr<layer_tree::StickyPositionConstraint> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::StickyPositionConstraint::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::StickyPositionConstraint& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::PictureTile> {
  static std::unique_ptr<layer_tree::PictureTile> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::PictureTile::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::PictureTile& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::Layer> {
  static std::unique_ptr<layer_tree::Layer> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::Layer::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::Layer& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::ScrollRectType> {
  static layer_tree::ScrollRectType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return layer_tree::ScrollRectType::REPAINTS_ON_SCROLL;
    }
    if (value.GetString() == "RepaintsOnScroll")
      return layer_tree::ScrollRectType::REPAINTS_ON_SCROLL;
    if (value.GetString() == "TouchEventHandler")
      return layer_tree::ScrollRectType::TOUCH_EVENT_HANDLER;
    if (value.GetString() == "WheelEventHandler")
      return layer_tree::ScrollRectType::WHEEL_EVENT_HANDLER;
    errors->AddError("invalid enum value");
    return layer_tree::ScrollRectType::REPAINTS_ON_SCROLL;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ScrollRectType& value) {
  switch (value) {
    case layer_tree::ScrollRectType::REPAINTS_ON_SCROLL:
      return std::make_unique<base::Value>("RepaintsOnScroll");
    case layer_tree::ScrollRectType::TOUCH_EVENT_HANDLER:
      return std::make_unique<base::Value>("TouchEventHandler");
    case layer_tree::ScrollRectType::WHEEL_EVENT_HANDLER:
      return std::make_unique<base::Value>("WheelEventHandler");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<layer_tree::CompositingReasonsParams> {
  static std::unique_ptr<layer_tree::CompositingReasonsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::CompositingReasonsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::CompositingReasonsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::CompositingReasonsResult> {
  static std::unique_ptr<layer_tree::CompositingReasonsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::CompositingReasonsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::CompositingReasonsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::DisableParams> {
  static std::unique_ptr<layer_tree::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::DisableResult> {
  static std::unique_ptr<layer_tree::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::EnableParams> {
  static std::unique_ptr<layer_tree::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::EnableResult> {
  static std::unique_ptr<layer_tree::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::LoadSnapshotParams> {
  static std::unique_ptr<layer_tree::LoadSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::LoadSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::LoadSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::LoadSnapshotResult> {
  static std::unique_ptr<layer_tree::LoadSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::LoadSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::LoadSnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::MakeSnapshotParams> {
  static std::unique_ptr<layer_tree::MakeSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::MakeSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::MakeSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::MakeSnapshotResult> {
  static std::unique_ptr<layer_tree::MakeSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::MakeSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::MakeSnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::ProfileSnapshotParams> {
  static std::unique_ptr<layer_tree::ProfileSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::ProfileSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ProfileSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::ProfileSnapshotResult> {
  static std::unique_ptr<layer_tree::ProfileSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::ProfileSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ProfileSnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::ReleaseSnapshotParams> {
  static std::unique_ptr<layer_tree::ReleaseSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::ReleaseSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ReleaseSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::ReleaseSnapshotResult> {
  static std::unique_ptr<layer_tree::ReleaseSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::ReleaseSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ReleaseSnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::ReplaySnapshotParams> {
  static std::unique_ptr<layer_tree::ReplaySnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::ReplaySnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ReplaySnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::ReplaySnapshotResult> {
  static std::unique_ptr<layer_tree::ReplaySnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::ReplaySnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::ReplaySnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::SnapshotCommandLogParams> {
  static std::unique_ptr<layer_tree::SnapshotCommandLogParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::SnapshotCommandLogParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::SnapshotCommandLogParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::SnapshotCommandLogResult> {
  static std::unique_ptr<layer_tree::SnapshotCommandLogResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::SnapshotCommandLogResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::SnapshotCommandLogResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::LayerPaintedParams> {
  static std::unique_ptr<layer_tree::LayerPaintedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::LayerPaintedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::LayerPaintedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<layer_tree::LayerTreeDidChangeParams> {
  static std::unique_ptr<layer_tree::LayerTreeDidChangeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return layer_tree::LayerTreeDidChangeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const layer_tree::LayerTreeDidChangeParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_LAYER_TREE_H_
