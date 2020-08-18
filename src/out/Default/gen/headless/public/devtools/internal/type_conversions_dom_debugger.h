// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_DEBUGGER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_DEBUGGER_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_dom_debugger.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {

template <>
struct FromValue<dom_debugger::DOMBreakpointType> {
  static dom_debugger::DOMBreakpointType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return dom_debugger::DOMBreakpointType::SUBTREE_MODIFIED;
    }
    if (value.GetString() == "subtree-modified")
      return dom_debugger::DOMBreakpointType::SUBTREE_MODIFIED;
    if (value.GetString() == "attribute-modified")
      return dom_debugger::DOMBreakpointType::ATTRIBUTE_MODIFIED;
    if (value.GetString() == "node-removed")
      return dom_debugger::DOMBreakpointType::NODE_REMOVED;
    errors->AddError("invalid enum value");
    return dom_debugger::DOMBreakpointType::SUBTREE_MODIFIED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::DOMBreakpointType& value) {
  switch (value) {
    case dom_debugger::DOMBreakpointType::SUBTREE_MODIFIED:
      return std::make_unique<base::Value>("subtree-modified");
    case dom_debugger::DOMBreakpointType::ATTRIBUTE_MODIFIED:
      return std::make_unique<base::Value>("attribute-modified");
    case dom_debugger::DOMBreakpointType::NODE_REMOVED:
      return std::make_unique<base::Value>("node-removed");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<dom_debugger::EventListener> {
  static std::unique_ptr<dom_debugger::EventListener> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::EventListener::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::EventListener& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::GetEventListenersParams> {
  static std::unique_ptr<dom_debugger::GetEventListenersParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::GetEventListenersParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::GetEventListenersParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::GetEventListenersResult> {
  static std::unique_ptr<dom_debugger::GetEventListenersResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::GetEventListenersResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::GetEventListenersResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveDOMBreakpointParams> {
  static std::unique_ptr<dom_debugger::RemoveDOMBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveDOMBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveDOMBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveDOMBreakpointResult> {
  static std::unique_ptr<dom_debugger::RemoveDOMBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveDOMBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveDOMBreakpointResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveEventListenerBreakpointParams> {
  static std::unique_ptr<dom_debugger::RemoveEventListenerBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveEventListenerBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveEventListenerBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveEventListenerBreakpointResult> {
  static std::unique_ptr<dom_debugger::RemoveEventListenerBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveEventListenerBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveEventListenerBreakpointResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveInstrumentationBreakpointParams> {
  static std::unique_ptr<dom_debugger::RemoveInstrumentationBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveInstrumentationBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveInstrumentationBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveInstrumentationBreakpointResult> {
  static std::unique_ptr<dom_debugger::RemoveInstrumentationBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveInstrumentationBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveInstrumentationBreakpointResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveXHRBreakpointParams> {
  static std::unique_ptr<dom_debugger::RemoveXHRBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveXHRBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveXHRBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::RemoveXHRBreakpointResult> {
  static std::unique_ptr<dom_debugger::RemoveXHRBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::RemoveXHRBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::RemoveXHRBreakpointResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetDOMBreakpointParams> {
  static std::unique_ptr<dom_debugger::SetDOMBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetDOMBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetDOMBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetDOMBreakpointResult> {
  static std::unique_ptr<dom_debugger::SetDOMBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetDOMBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetDOMBreakpointResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetEventListenerBreakpointParams> {
  static std::unique_ptr<dom_debugger::SetEventListenerBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetEventListenerBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetEventListenerBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetEventListenerBreakpointResult> {
  static std::unique_ptr<dom_debugger::SetEventListenerBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetEventListenerBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetEventListenerBreakpointResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetInstrumentationBreakpointParams> {
  static std::unique_ptr<dom_debugger::SetInstrumentationBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetInstrumentationBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetInstrumentationBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetInstrumentationBreakpointResult> {
  static std::unique_ptr<dom_debugger::SetInstrumentationBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetInstrumentationBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetInstrumentationBreakpointResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetXHRBreakpointParams> {
  static std::unique_ptr<dom_debugger::SetXHRBreakpointParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetXHRBreakpointParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetXHRBreakpointParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_debugger::SetXHRBreakpointResult> {
  static std::unique_ptr<dom_debugger::SetXHRBreakpointResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_debugger::SetXHRBreakpointResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_debugger::SetXHRBreakpointResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_DEBUGGER_H_
