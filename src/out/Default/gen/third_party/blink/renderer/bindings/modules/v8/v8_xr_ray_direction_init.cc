// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_ray_direction_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8XRRayDirectionInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "w",
    "x",
    "y",
    "z",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8XRRayDirectionInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, XRRayDirectionInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8XRRayDirectionInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> w_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&w_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (w_value.IsEmpty() || w_value->IsUndefined()) {
    // Do nothing.
  } else {
    double w_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, w_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setW(w_cpp_value);
  }

  v8::Local<v8::Value> x_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&x_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (x_value.IsEmpty() || x_value->IsUndefined()) {
    // Do nothing.
  } else {
    double x_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, x_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setX(x_cpp_value);
  }

  v8::Local<v8::Value> y_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&y_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (y_value.IsEmpty() || y_value->IsUndefined()) {
    // Do nothing.
  } else {
    double y_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, y_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setY(y_cpp_value);
  }

  v8::Local<v8::Value> z_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&z_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (z_value.IsEmpty() || z_value->IsUndefined()) {
    // Do nothing.
  } else {
    double z_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, z_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setZ(z_cpp_value);
  }
}

v8::Local<v8::Value> XRRayDirectionInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8XRRayDirectionInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8XRRayDirectionInit(const XRRayDirectionInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8XRRayDirectionInitKeys(isolate).data();
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

  v8::Local<v8::Value> w_value;
  bool w_has_value_or_default = false;
  if (impl->hasW()) {
    w_value = v8::Number::New(isolate, impl->w());
    w_has_value_or_default = true;
  } else {
    w_value = v8::Number::New(isolate, 0);
    w_has_value_or_default = true;
  }
  if (w_has_value_or_default &&
      !create_property(0, w_value)) {
    return false;
  }

  v8::Local<v8::Value> x_value;
  bool x_has_value_or_default = false;
  if (impl->hasX()) {
    x_value = v8::Number::New(isolate, impl->x());
    x_has_value_or_default = true;
  } else {
    x_value = v8::Number::New(isolate, 0);
    x_has_value_or_default = true;
  }
  if (x_has_value_or_default &&
      !create_property(1, x_value)) {
    return false;
  }

  v8::Local<v8::Value> y_value;
  bool y_has_value_or_default = false;
  if (impl->hasY()) {
    y_value = v8::Number::New(isolate, impl->y());
    y_has_value_or_default = true;
  } else {
    y_value = v8::Number::New(isolate, 0);
    y_has_value_or_default = true;
  }
  if (y_has_value_or_default &&
      !create_property(2, y_value)) {
    return false;
  }

  v8::Local<v8::Value> z_value;
  bool z_has_value_or_default = false;
  if (impl->hasZ()) {
    z_value = v8::Number::New(isolate, impl->z());
    z_has_value_or_default = true;
  } else {
    z_value = v8::Number::New(isolate, -1);
    z_has_value_or_default = true;
  }
  if (z_has_value_or_default &&
      !create_property(3, z_value)) {
    return false;
  }

  return true;
}

XRRayDirectionInit* NativeValueTraits<XRRayDirectionInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  XRRayDirectionInit* impl = MakeGarbageCollected<XRRayDirectionInit>();
  V8XRRayDirectionInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
