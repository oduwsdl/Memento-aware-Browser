// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_SNAPSHOT_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_SNAPSHOT_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_dom_snapshot.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<dom_snapshot::DOMNode> {
  static std::unique_ptr<dom_snapshot::DOMNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::DOMNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::DOMNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::InlineTextBox> {
  static std::unique_ptr<dom_snapshot::InlineTextBox> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::InlineTextBox::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::InlineTextBox& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::LayoutTreeNode> {
  static std::unique_ptr<dom_snapshot::LayoutTreeNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::LayoutTreeNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::LayoutTreeNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::ComputedStyle> {
  static std::unique_ptr<dom_snapshot::ComputedStyle> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::ComputedStyle::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::ComputedStyle& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::NameValue> {
  static std::unique_ptr<dom_snapshot::NameValue> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::NameValue::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::NameValue& value) {
  return value.Serialize();
}




template <>
struct FromValue<dom_snapshot::RareStringData> {
  static std::unique_ptr<dom_snapshot::RareStringData> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::RareStringData::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::RareStringData& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::RareBooleanData> {
  static std::unique_ptr<dom_snapshot::RareBooleanData> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::RareBooleanData::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::RareBooleanData& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::RareIntegerData> {
  static std::unique_ptr<dom_snapshot::RareIntegerData> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::RareIntegerData::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::RareIntegerData& value) {
  return value.Serialize();
}



template <>
struct FromValue<dom_snapshot::DocumentSnapshot> {
  static std::unique_ptr<dom_snapshot::DocumentSnapshot> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::DocumentSnapshot::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::DocumentSnapshot& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::NodeTreeSnapshot> {
  static std::unique_ptr<dom_snapshot::NodeTreeSnapshot> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::NodeTreeSnapshot::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::NodeTreeSnapshot& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::LayoutTreeSnapshot> {
  static std::unique_ptr<dom_snapshot::LayoutTreeSnapshot> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::LayoutTreeSnapshot::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::LayoutTreeSnapshot& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::TextBoxSnapshot> {
  static std::unique_ptr<dom_snapshot::TextBoxSnapshot> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::TextBoxSnapshot::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::TextBoxSnapshot& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::DisableParams> {
  static std::unique_ptr<dom_snapshot::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::DisableResult> {
  static std::unique_ptr<dom_snapshot::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::EnableParams> {
  static std::unique_ptr<dom_snapshot::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::EnableResult> {
  static std::unique_ptr<dom_snapshot::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::GetSnapshotParams> {
  static std::unique_ptr<dom_snapshot::GetSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::GetSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::GetSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::GetSnapshotResult> {
  static std::unique_ptr<dom_snapshot::GetSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::GetSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::GetSnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::CaptureSnapshotParams> {
  static std::unique_ptr<dom_snapshot::CaptureSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::CaptureSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::CaptureSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_snapshot::CaptureSnapshotResult> {
  static std::unique_ptr<dom_snapshot::CaptureSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_snapshot::CaptureSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_snapshot::CaptureSnapshotResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_SNAPSHOT_H_
