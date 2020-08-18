// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_text_format_update_event_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8TextFormatUpdateEventInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "backgroundColor",
    "formatRangeEnd",
    "formatRangeStart",
    "textDecorationColor",
    "textUnderlineStyle",
    "underlineColor",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8TextFormatUpdateEventInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, TextFormatUpdateEventInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8TextFormatUpdateEventInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> background_color_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&background_color_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (background_color_value.IsEmpty() || background_color_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> background_color_cpp_value = background_color_value;
    if (!background_color_cpp_value.Prepare(exception_state))
      return;
    impl->setBackgroundColor(background_color_cpp_value);
  }

  v8::Local<v8::Value> format_range_end_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&format_range_end_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (format_range_end_value.IsEmpty() || format_range_end_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t format_range_end_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, format_range_end_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setFormatRangeEnd(format_range_end_cpp_value);
  }

  v8::Local<v8::Value> format_range_start_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&format_range_start_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (format_range_start_value.IsEmpty() || format_range_start_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t format_range_start_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, format_range_start_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setFormatRangeStart(format_range_start_cpp_value);
  }

  v8::Local<v8::Value> text_decoration_color_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&text_decoration_color_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (text_decoration_color_value.IsEmpty() || text_decoration_color_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> text_decoration_color_cpp_value = text_decoration_color_value;
    if (!text_decoration_color_cpp_value.Prepare(exception_state))
      return;
    impl->setTextDecorationColor(text_decoration_color_cpp_value);
  }

  v8::Local<v8::Value> text_underline_style_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&text_underline_style_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (text_underline_style_value.IsEmpty() || text_underline_style_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> text_underline_style_cpp_value = text_underline_style_value;
    if (!text_underline_style_cpp_value.Prepare(exception_state))
      return;
    impl->setTextUnderlineStyle(text_underline_style_cpp_value);
  }

  v8::Local<v8::Value> underline_color_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&underline_color_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (underline_color_value.IsEmpty() || underline_color_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> underline_color_cpp_value = underline_color_value;
    if (!underline_color_cpp_value.Prepare(exception_state))
      return;
    impl->setUnderlineColor(underline_color_cpp_value);
  }
}

v8::Local<v8::Value> TextFormatUpdateEventInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8TextFormatUpdateEventInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8TextFormatUpdateEventInit(const TextFormatUpdateEventInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8TextFormatUpdateEventInitKeys(isolate).data();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto create_property = [dictionary, context, keys, isolate](
                             size_t key_index, v8::Local<v8::Value> value) {
    bool added_property;
    v8::Local<v8::Name> key = keys[key_index].Get(isolate);
    if (!dictionary->CreateDataProperty(context, key, value)
             .To(&added_property)) {
      return false;
    }
    return added_property;
  };

  v8::Local<v8::Value> background_color_value;
  bool background_color_has_value_or_default = false;
  if (impl->hasBackgroundColor()) {
    background_color_value = V8String(isolate, impl->backgroundColor());
    background_color_has_value_or_default = true;
  }
  if (background_color_has_value_or_default &&
      !create_property(0, background_color_value)) {
    return false;
  }

  v8::Local<v8::Value> format_range_end_value;
  bool format_range_end_has_value_or_default = false;
  if (impl->hasFormatRangeEnd()) {
    format_range_end_value = v8::Integer::NewFromUnsigned(isolate, impl->formatRangeEnd());
    format_range_end_has_value_or_default = true;
  }
  if (format_range_end_has_value_or_default &&
      !create_property(1, format_range_end_value)) {
    return false;
  }

  v8::Local<v8::Value> format_range_start_value;
  bool format_range_start_has_value_or_default = false;
  if (impl->hasFormatRangeStart()) {
    format_range_start_value = v8::Integer::NewFromUnsigned(isolate, impl->formatRangeStart());
    format_range_start_has_value_or_default = true;
  }
  if (format_range_start_has_value_or_default &&
      !create_property(2, format_range_start_value)) {
    return false;
  }

  v8::Local<v8::Value> text_decoration_color_value;
  bool text_decoration_color_has_value_or_default = false;
  if (impl->hasTextDecorationColor()) {
    text_decoration_color_value = V8String(isolate, impl->textDecorationColor());
    text_decoration_color_has_value_or_default = true;
  }
  if (text_decoration_color_has_value_or_default &&
      !create_property(3, text_decoration_color_value)) {
    return false;
  }

  v8::Local<v8::Value> text_underline_style_value;
  bool text_underline_style_has_value_or_default = false;
  if (impl->hasTextUnderlineStyle()) {
    text_underline_style_value = V8String(isolate, impl->textUnderlineStyle());
    text_underline_style_has_value_or_default = true;
  }
  if (text_underline_style_has_value_or_default &&
      !create_property(4, text_underline_style_value)) {
    return false;
  }

  v8::Local<v8::Value> underline_color_value;
  bool underline_color_has_value_or_default = false;
  if (impl->hasUnderlineColor()) {
    underline_color_value = V8String(isolate, impl->underlineColor());
    underline_color_has_value_or_default = true;
  }
  if (underline_color_has_value_or_default &&
      !create_property(5, underline_color_value)) {
    return false;
  }

  return true;
}

TextFormatUpdateEventInit* NativeValueTraits<TextFormatUpdateEventInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  TextFormatUpdateEventInit* impl = MakeGarbageCollected<TextFormatUpdateEventInit>();
  V8TextFormatUpdateEventInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
