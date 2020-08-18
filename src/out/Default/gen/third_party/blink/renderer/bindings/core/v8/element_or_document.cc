// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/element_or_document.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_document.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_element.h"
#include "third_party/blink/renderer/core/animation/document_animation.h"
#include "third_party/blink/renderer/core/css/cssom/element_computed_style_map.h"
#include "third_party/blink/renderer/core/css/font_face_source.h"
#include "third_party/blink/renderer/core/dom/child_node.h"
#include "third_party/blink/renderer/core/dom/document_and_element_event_handlers.h"
#include "third_party/blink/renderer/core/dom/document_or_shadow_root.h"
#include "third_party/blink/renderer/core/dom/global_event_handlers.h"
#include "third_party/blink/renderer/core/dom/non_document_type_child_node.h"
#include "third_party/blink/renderer/core/dom/non_element_parent_node.h"
#include "third_party/blink/renderer/core/dom/parent_node.h"
#include "third_party/blink/renderer/core/fullscreen/document_fullscreen.h"
#include "third_party/blink/renderer/core/fullscreen/element_fullscreen.h"
#include "third_party/blink/renderer/core/svg/svg_document_extensions.h"
#include "third_party/blink/renderer/core/xml/document_xpath_evaluator.h"

namespace blink {

ElementOrDocument::ElementOrDocument() : type_(SpecificType::kNone) {}

Document* ElementOrDocument::GetAsDocument() const {
  DCHECK(IsDocument());
  return document_;
}

void ElementOrDocument::SetDocument(Document* value) {
  DCHECK(IsNull());
  document_ = value;
  type_ = SpecificType::kDocument;
}

ElementOrDocument ElementOrDocument::FromDocument(Document* value) {
  ElementOrDocument container;
  container.SetDocument(value);
  return container;
}

Element* ElementOrDocument::GetAsElement() const {
  DCHECK(IsElement());
  return element_;
}

void ElementOrDocument::SetElement(Element* value) {
  DCHECK(IsNull());
  element_ = value;
  type_ = SpecificType::kElement;
}

ElementOrDocument ElementOrDocument::FromElement(Element* value) {
  ElementOrDocument container;
  container.SetElement(value);
  return container;
}

ElementOrDocument::ElementOrDocument(const ElementOrDocument&) = default;
ElementOrDocument::~ElementOrDocument() = default;
ElementOrDocument& ElementOrDocument::operator=(const ElementOrDocument&) = default;

void ElementOrDocument::Trace(Visitor* visitor) const {
  visitor->Trace(document_);
  visitor->Trace(element_);
}

void V8ElementOrDocument::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    ElementOrDocument& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8Document::HasInstance(v8_value, isolate)) {
    Document* cpp_value = V8Document::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetDocument(cpp_value);
    return;
  }

  if (V8Element::HasInstance(v8_value, isolate)) {
    Element* cpp_value = V8Element::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetElement(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '(Element or Document)'");
}

v8::Local<v8::Value> ToV8(const ElementOrDocument& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case ElementOrDocument::SpecificType::kNone:
      return v8::Null(isolate);
    case ElementOrDocument::SpecificType::kDocument:
      return ToV8(impl.GetAsDocument(), creationContext, isolate);
    case ElementOrDocument::SpecificType::kElement:
      return ToV8(impl.GetAsElement(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

ElementOrDocument NativeValueTraits<ElementOrDocument>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ElementOrDocument impl;
  V8ElementOrDocument::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

