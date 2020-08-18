// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_ink_trail_style.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8InkTrailStyleKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "color",
    "diameter",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8InkTrailStyle::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, InkTrailStyle* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8InkTrailStyleKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> color_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&color_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (color_value.IsEmpty() || color_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> color_cpp_value = color_value;
    if (!color_cpp_value.Prepare(exception_state))
      return;
    impl->setColor(color_cpp_value);
  }

  v8::Local<v8::Value> diameter_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&diameter_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (diameter_value.IsEmpty() || diameter_value->IsUndefined()) {
    // Do nothing.
  } else {
    double diameter_cpp_value = NativeValueTraits<IDLUnrestrictedDouble>::NativeValue(isolate, diameter_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDiameter(diameter_cpp_value);
  }
}

v8::Local<v8::Value> InkTrailStyle::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8InkTrailStyle(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8InkTrailStyle(const InkTrailStyle* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8InkTrailStyleKeys(isolate).data();
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

  v8::Local<v8::Value> color_value;
  bool color_has_value_or_default = false;
  if (impl->hasColor()) {
    color_value = V8String(isolate, impl->color());
    color_has_value_or_default = true;
  }
  if (color_has_value_or_default &&
      !create_property(0, color_value)) {
    return false;
  }

  v8::Local<v8::Value> diameter_value;
  bool diameter_has_value_or_default = false;
  if (impl->hasDiameter()) {
    diameter_value = v8::Number::New(isolate, impl->diameter());
    diameter_has_value_or_default = true;
  }
  if (diameter_has_value_or_default &&
      !create_property(1, diameter_value)) {
    return false;
  }

  return true;
}

InkTrailStyle* NativeValueTraits<InkTrailStyle>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  InkTrailStyle* impl = MakeGarbageCollected<InkTrailStyle>();
  V8InkTrailStyle::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
