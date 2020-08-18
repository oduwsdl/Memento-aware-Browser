// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/string_or_scroll_timeline_element_based_offset.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

StringOrScrollTimelineElementBasedOffset::StringOrScrollTimelineElementBasedOffset() : type_(SpecificType::kNone) {}

ScrollTimelineElementBasedOffset* StringOrScrollTimelineElementBasedOffset::GetAsScrollTimelineElementBasedOffset() const {
  DCHECK(IsScrollTimelineElementBasedOffset());
  return scroll_timeline_element_based_offset_;
}

void StringOrScrollTimelineElementBasedOffset::SetScrollTimelineElementBasedOffset(ScrollTimelineElementBasedOffset* value) {
  DCHECK(IsNull());
  scroll_timeline_element_based_offset_ = value;
  type_ = SpecificType::kScrollTimelineElementBasedOffset;
}

StringOrScrollTimelineElementBasedOffset StringOrScrollTimelineElementBasedOffset::FromScrollTimelineElementBasedOffset(ScrollTimelineElementBasedOffset* value) {
  StringOrScrollTimelineElementBasedOffset container;
  container.SetScrollTimelineElementBasedOffset(value);
  return container;
}

const String& StringOrScrollTimelineElementBasedOffset::GetAsString() const {
  DCHECK(IsString());
  return string_;
}

void StringOrScrollTimelineElementBasedOffset::SetString(const String& value) {
  DCHECK(IsNull());
  string_ = value;
  type_ = SpecificType::kString;
}

StringOrScrollTimelineElementBasedOffset StringOrScrollTimelineElementBasedOffset::FromString(const String& value) {
  StringOrScrollTimelineElementBasedOffset container;
  container.SetString(value);
  return container;
}

StringOrScrollTimelineElementBasedOffset::StringOrScrollTimelineElementBasedOffset(const StringOrScrollTimelineElementBasedOffset&) = default;
StringOrScrollTimelineElementBasedOffset::~StringOrScrollTimelineElementBasedOffset() = default;
StringOrScrollTimelineElementBasedOffset& StringOrScrollTimelineElementBasedOffset::operator=(const StringOrScrollTimelineElementBasedOffset&) = default;

void StringOrScrollTimelineElementBasedOffset::Trace(Visitor* visitor) const {
  visitor->Trace(scroll_timeline_element_based_offset_);
}

void V8StringOrScrollTimelineElementBasedOffset::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    StringOrScrollTimelineElementBasedOffset& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    ScrollTimelineElementBasedOffset* cpp_value = NativeValueTraits<ScrollTimelineElementBasedOffset>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetScrollTimelineElementBasedOffset(cpp_value);
    return;
  }

  if (v8_value->IsObject()) {
    ScrollTimelineElementBasedOffset* cpp_value = NativeValueTraits<ScrollTimelineElementBasedOffset>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetScrollTimelineElementBasedOffset(cpp_value);
    return;
  }

  {
    V8StringResource<> cpp_value = v8_value;
    if (!cpp_value.Prepare(exception_state))
      return;
    impl.SetString(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const StringOrScrollTimelineElementBasedOffset& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case StringOrScrollTimelineElementBasedOffset::SpecificType::kNone:
      return v8::Null(isolate);
    case StringOrScrollTimelineElementBasedOffset::SpecificType::kScrollTimelineElementBasedOffset:
      return ToV8(impl.GetAsScrollTimelineElementBasedOffset(), creationContext, isolate);
    case StringOrScrollTimelineElementBasedOffset::SpecificType::kString:
      return V8String(isolate, impl.GetAsString());
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

StringOrScrollTimelineElementBasedOffset NativeValueTraits<StringOrScrollTimelineElementBasedOffset>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  StringOrScrollTimelineElementBasedOffset impl;
  V8StringOrScrollTimelineElementBasedOffset::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

