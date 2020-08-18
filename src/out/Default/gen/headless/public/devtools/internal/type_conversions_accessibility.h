// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_ACCESSIBILITY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_ACCESSIBILITY_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_accessibility.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<accessibility::AXValueType> {
  static accessibility::AXValueType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return accessibility::AXValueType::BOOLEAN;
    }
    if (value.GetString() == "boolean")
      return accessibility::AXValueType::BOOLEAN;
    if (value.GetString() == "tristate")
      return accessibility::AXValueType::TRISTATE;
    if (value.GetString() == "booleanOrUndefined")
      return accessibility::AXValueType::BOOLEAN_OR_UNDEFINED;
    if (value.GetString() == "idref")
      return accessibility::AXValueType::IDREF;
    if (value.GetString() == "idrefList")
      return accessibility::AXValueType::IDREF_LIST;
    if (value.GetString() == "integer")
      return accessibility::AXValueType::INTEGER;
    if (value.GetString() == "node")
      return accessibility::AXValueType::NODE;
    if (value.GetString() == "nodeList")
      return accessibility::AXValueType::NODE_LIST;
    if (value.GetString() == "number")
      return accessibility::AXValueType::NUMBER;
    if (value.GetString() == "string")
      return accessibility::AXValueType::STRING;
    if (value.GetString() == "computedString")
      return accessibility::AXValueType::COMPUTED_STRING;
    if (value.GetString() == "token")
      return accessibility::AXValueType::TOKEN;
    if (value.GetString() == "tokenList")
      return accessibility::AXValueType::TOKEN_LIST;
    if (value.GetString() == "domRelation")
      return accessibility::AXValueType::DOM_RELATION;
    if (value.GetString() == "role")
      return accessibility::AXValueType::ROLE;
    if (value.GetString() == "internalRole")
      return accessibility::AXValueType::INTERNAL_ROLE;
    if (value.GetString() == "valueUndefined")
      return accessibility::AXValueType::VALUE_UNDEFINED;
    errors->AddError("invalid enum value");
    return accessibility::AXValueType::BOOLEAN;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXValueType& value) {
  switch (value) {
    case accessibility::AXValueType::BOOLEAN:
      return std::make_unique<base::Value>("boolean");
    case accessibility::AXValueType::TRISTATE:
      return std::make_unique<base::Value>("tristate");
    case accessibility::AXValueType::BOOLEAN_OR_UNDEFINED:
      return std::make_unique<base::Value>("booleanOrUndefined");
    case accessibility::AXValueType::IDREF:
      return std::make_unique<base::Value>("idref");
    case accessibility::AXValueType::IDREF_LIST:
      return std::make_unique<base::Value>("idrefList");
    case accessibility::AXValueType::INTEGER:
      return std::make_unique<base::Value>("integer");
    case accessibility::AXValueType::NODE:
      return std::make_unique<base::Value>("node");
    case accessibility::AXValueType::NODE_LIST:
      return std::make_unique<base::Value>("nodeList");
    case accessibility::AXValueType::NUMBER:
      return std::make_unique<base::Value>("number");
    case accessibility::AXValueType::STRING:
      return std::make_unique<base::Value>("string");
    case accessibility::AXValueType::COMPUTED_STRING:
      return std::make_unique<base::Value>("computedString");
    case accessibility::AXValueType::TOKEN:
      return std::make_unique<base::Value>("token");
    case accessibility::AXValueType::TOKEN_LIST:
      return std::make_unique<base::Value>("tokenList");
    case accessibility::AXValueType::DOM_RELATION:
      return std::make_unique<base::Value>("domRelation");
    case accessibility::AXValueType::ROLE:
      return std::make_unique<base::Value>("role");
    case accessibility::AXValueType::INTERNAL_ROLE:
      return std::make_unique<base::Value>("internalRole");
    case accessibility::AXValueType::VALUE_UNDEFINED:
      return std::make_unique<base::Value>("valueUndefined");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<accessibility::AXValueSourceType> {
  static accessibility::AXValueSourceType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return accessibility::AXValueSourceType::ATTRIBUTE;
    }
    if (value.GetString() == "attribute")
      return accessibility::AXValueSourceType::ATTRIBUTE;
    if (value.GetString() == "implicit")
      return accessibility::AXValueSourceType::IMPLICIT;
    if (value.GetString() == "style")
      return accessibility::AXValueSourceType::STYLE;
    if (value.GetString() == "contents")
      return accessibility::AXValueSourceType::CONTENTS;
    if (value.GetString() == "placeholder")
      return accessibility::AXValueSourceType::PLACEHOLDER;
    if (value.GetString() == "relatedElement")
      return accessibility::AXValueSourceType::RELATED_ELEMENT;
    errors->AddError("invalid enum value");
    return accessibility::AXValueSourceType::ATTRIBUTE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXValueSourceType& value) {
  switch (value) {
    case accessibility::AXValueSourceType::ATTRIBUTE:
      return std::make_unique<base::Value>("attribute");
    case accessibility::AXValueSourceType::IMPLICIT:
      return std::make_unique<base::Value>("implicit");
    case accessibility::AXValueSourceType::STYLE:
      return std::make_unique<base::Value>("style");
    case accessibility::AXValueSourceType::CONTENTS:
      return std::make_unique<base::Value>("contents");
    case accessibility::AXValueSourceType::PLACEHOLDER:
      return std::make_unique<base::Value>("placeholder");
    case accessibility::AXValueSourceType::RELATED_ELEMENT:
      return std::make_unique<base::Value>("relatedElement");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<accessibility::AXValueNativeSourceType> {
  static accessibility::AXValueNativeSourceType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return accessibility::AXValueNativeSourceType::FIGCAPTION;
    }
    if (value.GetString() == "figcaption")
      return accessibility::AXValueNativeSourceType::FIGCAPTION;
    if (value.GetString() == "label")
      return accessibility::AXValueNativeSourceType::LABEL;
    if (value.GetString() == "labelfor")
      return accessibility::AXValueNativeSourceType::LABELFOR;
    if (value.GetString() == "labelwrapped")
      return accessibility::AXValueNativeSourceType::LABELWRAPPED;
    if (value.GetString() == "legend")
      return accessibility::AXValueNativeSourceType::LEGEND;
    if (value.GetString() == "tablecaption")
      return accessibility::AXValueNativeSourceType::TABLECAPTION;
    if (value.GetString() == "title")
      return accessibility::AXValueNativeSourceType::TITLE;
    if (value.GetString() == "other")
      return accessibility::AXValueNativeSourceType::OTHER;
    errors->AddError("invalid enum value");
    return accessibility::AXValueNativeSourceType::FIGCAPTION;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXValueNativeSourceType& value) {
  switch (value) {
    case accessibility::AXValueNativeSourceType::FIGCAPTION:
      return std::make_unique<base::Value>("figcaption");
    case accessibility::AXValueNativeSourceType::LABEL:
      return std::make_unique<base::Value>("label");
    case accessibility::AXValueNativeSourceType::LABELFOR:
      return std::make_unique<base::Value>("labelfor");
    case accessibility::AXValueNativeSourceType::LABELWRAPPED:
      return std::make_unique<base::Value>("labelwrapped");
    case accessibility::AXValueNativeSourceType::LEGEND:
      return std::make_unique<base::Value>("legend");
    case accessibility::AXValueNativeSourceType::TABLECAPTION:
      return std::make_unique<base::Value>("tablecaption");
    case accessibility::AXValueNativeSourceType::TITLE:
      return std::make_unique<base::Value>("title");
    case accessibility::AXValueNativeSourceType::OTHER:
      return std::make_unique<base::Value>("other");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<accessibility::AXValueSource> {
  static std::unique_ptr<accessibility::AXValueSource> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::AXValueSource::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXValueSource& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::AXRelatedNode> {
  static std::unique_ptr<accessibility::AXRelatedNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::AXRelatedNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXRelatedNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::AXProperty> {
  static std::unique_ptr<accessibility::AXProperty> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::AXProperty::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXProperty& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::AXValue> {
  static std::unique_ptr<accessibility::AXValue> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::AXValue::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXValue& value) {
  return value.Serialize();
}

template <>
struct FromValue<accessibility::AXPropertyName> {
  static accessibility::AXPropertyName Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return accessibility::AXPropertyName::BUSY;
    }
    if (value.GetString() == "busy")
      return accessibility::AXPropertyName::BUSY;
    if (value.GetString() == "disabled")
      return accessibility::AXPropertyName::DISABLED;
    if (value.GetString() == "editable")
      return accessibility::AXPropertyName::EDITABLE;
    if (value.GetString() == "focusable")
      return accessibility::AXPropertyName::FOCUSABLE;
    if (value.GetString() == "focused")
      return accessibility::AXPropertyName::FOCUSED;
    if (value.GetString() == "hidden")
      return accessibility::AXPropertyName::HIDDEN;
    if (value.GetString() == "hiddenRoot")
      return accessibility::AXPropertyName::HIDDEN_ROOT;
    if (value.GetString() == "invalid")
      return accessibility::AXPropertyName::INVALID;
    if (value.GetString() == "keyshortcuts")
      return accessibility::AXPropertyName::KEYSHORTCUTS;
    if (value.GetString() == "settable")
      return accessibility::AXPropertyName::SETTABLE;
    if (value.GetString() == "roledescription")
      return accessibility::AXPropertyName::ROLEDESCRIPTION;
    if (value.GetString() == "live")
      return accessibility::AXPropertyName::LIVE;
    if (value.GetString() == "atomic")
      return accessibility::AXPropertyName::ATOMIC;
    if (value.GetString() == "relevant")
      return accessibility::AXPropertyName::RELEVANT;
    if (value.GetString() == "root")
      return accessibility::AXPropertyName::ROOT;
    if (value.GetString() == "autocomplete")
      return accessibility::AXPropertyName::AUTOCOMPLETE;
    if (value.GetString() == "hasPopup")
      return accessibility::AXPropertyName::HAS_POPUP;
    if (value.GetString() == "level")
      return accessibility::AXPropertyName::LEVEL;
    if (value.GetString() == "multiselectable")
      return accessibility::AXPropertyName::MULTISELECTABLE;
    if (value.GetString() == "orientation")
      return accessibility::AXPropertyName::ORIENTATION;
    if (value.GetString() == "multiline")
      return accessibility::AXPropertyName::MULTILINE;
    if (value.GetString() == "readonly")
      return accessibility::AXPropertyName::READONLY;
    if (value.GetString() == "required")
      return accessibility::AXPropertyName::REQUIRED;
    if (value.GetString() == "valuemin")
      return accessibility::AXPropertyName::VALUEMIN;
    if (value.GetString() == "valuemax")
      return accessibility::AXPropertyName::VALUEMAX;
    if (value.GetString() == "valuetext")
      return accessibility::AXPropertyName::VALUETEXT;
    if (value.GetString() == "checked")
      return accessibility::AXPropertyName::CHECKED;
    if (value.GetString() == "expanded")
      return accessibility::AXPropertyName::EXPANDED;
    if (value.GetString() == "modal")
      return accessibility::AXPropertyName::MODAL;
    if (value.GetString() == "pressed")
      return accessibility::AXPropertyName::PRESSED;
    if (value.GetString() == "selected")
      return accessibility::AXPropertyName::SELECTED;
    if (value.GetString() == "activedescendant")
      return accessibility::AXPropertyName::ACTIVEDESCENDANT;
    if (value.GetString() == "controls")
      return accessibility::AXPropertyName::CONTROLS;
    if (value.GetString() == "describedby")
      return accessibility::AXPropertyName::DESCRIBEDBY;
    if (value.GetString() == "details")
      return accessibility::AXPropertyName::DETAILS;
    if (value.GetString() == "errormessage")
      return accessibility::AXPropertyName::ERRORMESSAGE;
    if (value.GetString() == "flowto")
      return accessibility::AXPropertyName::FLOWTO;
    if (value.GetString() == "labelledby")
      return accessibility::AXPropertyName::LABELLEDBY;
    if (value.GetString() == "owns")
      return accessibility::AXPropertyName::OWNS;
    errors->AddError("invalid enum value");
    return accessibility::AXPropertyName::BUSY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXPropertyName& value) {
  switch (value) {
    case accessibility::AXPropertyName::BUSY:
      return std::make_unique<base::Value>("busy");
    case accessibility::AXPropertyName::DISABLED:
      return std::make_unique<base::Value>("disabled");
    case accessibility::AXPropertyName::EDITABLE:
      return std::make_unique<base::Value>("editable");
    case accessibility::AXPropertyName::FOCUSABLE:
      return std::make_unique<base::Value>("focusable");
    case accessibility::AXPropertyName::FOCUSED:
      return std::make_unique<base::Value>("focused");
    case accessibility::AXPropertyName::HIDDEN:
      return std::make_unique<base::Value>("hidden");
    case accessibility::AXPropertyName::HIDDEN_ROOT:
      return std::make_unique<base::Value>("hiddenRoot");
    case accessibility::AXPropertyName::INVALID:
      return std::make_unique<base::Value>("invalid");
    case accessibility::AXPropertyName::KEYSHORTCUTS:
      return std::make_unique<base::Value>("keyshortcuts");
    case accessibility::AXPropertyName::SETTABLE:
      return std::make_unique<base::Value>("settable");
    case accessibility::AXPropertyName::ROLEDESCRIPTION:
      return std::make_unique<base::Value>("roledescription");
    case accessibility::AXPropertyName::LIVE:
      return std::make_unique<base::Value>("live");
    case accessibility::AXPropertyName::ATOMIC:
      return std::make_unique<base::Value>("atomic");
    case accessibility::AXPropertyName::RELEVANT:
      return std::make_unique<base::Value>("relevant");
    case accessibility::AXPropertyName::ROOT:
      return std::make_unique<base::Value>("root");
    case accessibility::AXPropertyName::AUTOCOMPLETE:
      return std::make_unique<base::Value>("autocomplete");
    case accessibility::AXPropertyName::HAS_POPUP:
      return std::make_unique<base::Value>("hasPopup");
    case accessibility::AXPropertyName::LEVEL:
      return std::make_unique<base::Value>("level");
    case accessibility::AXPropertyName::MULTISELECTABLE:
      return std::make_unique<base::Value>("multiselectable");
    case accessibility::AXPropertyName::ORIENTATION:
      return std::make_unique<base::Value>("orientation");
    case accessibility::AXPropertyName::MULTILINE:
      return std::make_unique<base::Value>("multiline");
    case accessibility::AXPropertyName::READONLY:
      return std::make_unique<base::Value>("readonly");
    case accessibility::AXPropertyName::REQUIRED:
      return std::make_unique<base::Value>("required");
    case accessibility::AXPropertyName::VALUEMIN:
      return std::make_unique<base::Value>("valuemin");
    case accessibility::AXPropertyName::VALUEMAX:
      return std::make_unique<base::Value>("valuemax");
    case accessibility::AXPropertyName::VALUETEXT:
      return std::make_unique<base::Value>("valuetext");
    case accessibility::AXPropertyName::CHECKED:
      return std::make_unique<base::Value>("checked");
    case accessibility::AXPropertyName::EXPANDED:
      return std::make_unique<base::Value>("expanded");
    case accessibility::AXPropertyName::MODAL:
      return std::make_unique<base::Value>("modal");
    case accessibility::AXPropertyName::PRESSED:
      return std::make_unique<base::Value>("pressed");
    case accessibility::AXPropertyName::SELECTED:
      return std::make_unique<base::Value>("selected");
    case accessibility::AXPropertyName::ACTIVEDESCENDANT:
      return std::make_unique<base::Value>("activedescendant");
    case accessibility::AXPropertyName::CONTROLS:
      return std::make_unique<base::Value>("controls");
    case accessibility::AXPropertyName::DESCRIBEDBY:
      return std::make_unique<base::Value>("describedby");
    case accessibility::AXPropertyName::DETAILS:
      return std::make_unique<base::Value>("details");
    case accessibility::AXPropertyName::ERRORMESSAGE:
      return std::make_unique<base::Value>("errormessage");
    case accessibility::AXPropertyName::FLOWTO:
      return std::make_unique<base::Value>("flowto");
    case accessibility::AXPropertyName::LABELLEDBY:
      return std::make_unique<base::Value>("labelledby");
    case accessibility::AXPropertyName::OWNS:
      return std::make_unique<base::Value>("owns");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<accessibility::AXNode> {
  static std::unique_ptr<accessibility::AXNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::AXNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::AXNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::DisableParams> {
  static std::unique_ptr<accessibility::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::DisableResult> {
  static std::unique_ptr<accessibility::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::EnableParams> {
  static std::unique_ptr<accessibility::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::EnableResult> {
  static std::unique_ptr<accessibility::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::GetPartialAXTreeParams> {
  static std::unique_ptr<accessibility::GetPartialAXTreeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::GetPartialAXTreeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::GetPartialAXTreeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::GetPartialAXTreeResult> {
  static std::unique_ptr<accessibility::GetPartialAXTreeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::GetPartialAXTreeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::GetPartialAXTreeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::GetFullAXTreeParams> {
  static std::unique_ptr<accessibility::GetFullAXTreeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::GetFullAXTreeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::GetFullAXTreeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<accessibility::GetFullAXTreeResult> {
  static std::unique_ptr<accessibility::GetFullAXTreeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return accessibility::GetFullAXTreeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const accessibility::GetFullAXTreeResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_ACCESSIBILITY_H_
