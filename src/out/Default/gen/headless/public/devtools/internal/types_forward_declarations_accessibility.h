// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_ACCESSIBILITY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_ACCESSIBILITY_H_

#include "base/values.h"

namespace headless {

namespace accessibility {
class AXValueSource;
class AXRelatedNode;
class AXProperty;
class AXValue;
class AXNode;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class GetPartialAXTreeParams;
class GetPartialAXTreeResult;
class GetFullAXTreeParams;
class GetFullAXTreeResult;

enum class AXValueType {
  BOOLEAN,
  TRISTATE,
  BOOLEAN_OR_UNDEFINED,
  IDREF,
  IDREF_LIST,
  INTEGER,
  NODE,
  NODE_LIST,
  NUMBER,
  STRING,
  COMPUTED_STRING,
  TOKEN,
  TOKEN_LIST,
  DOM_RELATION,
  ROLE,
  INTERNAL_ROLE,
  VALUE_UNDEFINED
};

enum class AXValueSourceType {
  ATTRIBUTE,
  IMPLICIT,
  STYLE,
  CONTENTS,
  PLACEHOLDER,
  RELATED_ELEMENT
};

enum class AXValueNativeSourceType {
  FIGCAPTION,
  LABEL,
  LABELFOR,
  LABELWRAPPED,
  LEGEND,
  TABLECAPTION,
  TITLE,
  OTHER
};

enum class AXPropertyName {
  BUSY,
  DISABLED,
  EDITABLE,
  FOCUSABLE,
  FOCUSED,
  HIDDEN,
  HIDDEN_ROOT,
  INVALID,
  KEYSHORTCUTS,
  SETTABLE,
  ROLEDESCRIPTION,
  LIVE,
  ATOMIC,
  RELEVANT,
  ROOT,
  AUTOCOMPLETE,
  HAS_POPUP,
  LEVEL,
  MULTISELECTABLE,
  ORIENTATION,
  MULTILINE,
  READONLY,
  REQUIRED,
  VALUEMIN,
  VALUEMAX,
  VALUETEXT,
  CHECKED,
  EXPANDED,
  MODAL,
  PRESSED,
  SELECTED,
  ACTIVEDESCENDANT,
  CONTROLS,
  DESCRIBEDBY,
  DETAILS,
  ERRORMESSAGE,
  FLOWTO,
  LABELLEDBY,
  OWNS
};

}  // namespace accessibility

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_ACCESSIBILITY_H_
