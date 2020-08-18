// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/mathml/mathml_tag_names.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_ELEMENT_TYPE_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_ELEMENT_TYPE_HELPERS_H_

#include "third_party/blink/renderer/core/mathml/mathml_element.h"
#include "third_party/blink/renderer/core/mathml_names.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

class Document;

// Type checking.
class MathMLFractionElement;
template <>
inline bool IsElementOfType<const MathMLFractionElement>(const Node& node) {
  return IsA<MathMLFractionElement>(node);
}
template <>
inline bool IsElementOfType<const MathMLFractionElement>(const MathMLElement& element) {
  return IsA<MathMLFractionElement>(element);
}
template <>
struct DowncastTraits<MathMLFractionElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(mathml_names::kMfracTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsMathMLElement() && IsA<MathMLFractionElement>(To<MathMLElement>(node));
  }
};

class MathMLSpaceElement;
template <>
inline bool IsElementOfType<const MathMLSpaceElement>(const Node& node) {
  return IsA<MathMLSpaceElement>(node);
}
template <>
inline bool IsElementOfType<const MathMLSpaceElement>(const MathMLElement& element) {
  return IsA<MathMLSpaceElement>(element);
}
template <>
struct DowncastTraits<MathMLSpaceElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(mathml_names::kMspaceTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsMathMLElement() && IsA<MathMLSpaceElement>(To<MathMLElement>(node));
  }
};


}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_ELEMENT_TYPE_HELPERS_H_
