// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_render_state_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_webgl_layer.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8XRRenderStateInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "baseLayer",
    "depthFar",
    "depthNear",
    "inlineVerticalFieldOfView",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8XRRenderStateInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, XRRenderStateInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8XRRenderStateInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> base_layer_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&base_layer_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (base_layer_value.IsEmpty() || base_layer_value->IsUndefined()) {
    // Do nothing.
  } else if (base_layer_value->IsNull()) {
    impl->setBaseLayerToNull();
  } else {
    XRWebGLLayer* base_layer_cpp_value = V8XRWebGLLayer::ToImplWithTypeCheck(isolate, base_layer_value);
    if (!base_layer_cpp_value) {
      exception_state.ThrowTypeError("member baseLayer is not of type XRWebGLLayer.");
      return;
    }
    impl->setBaseLayer(base_layer_cpp_value);
  }

  v8::Local<v8::Value> depth_far_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&depth_far_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (depth_far_value.IsEmpty() || depth_far_value->IsUndefined()) {
    // Do nothing.
  } else {
    double depth_far_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, depth_far_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDepthFar(depth_far_cpp_value);
  }

  v8::Local<v8::Value> depth_near_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&depth_near_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (depth_near_value.IsEmpty() || depth_near_value->IsUndefined()) {
    // Do nothing.
  } else {
    double depth_near_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, depth_near_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDepthNear(depth_near_cpp_value);
  }

  v8::Local<v8::Value> inline_vertical_field_of_view_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&inline_vertical_field_of_view_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (inline_vertical_field_of_view_value.IsEmpty() || inline_vertical_field_of_view_value->IsUndefined()) {
    // Do nothing.
  } else {
    double inline_vertical_field_of_view_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, inline_vertical_field_of_view_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setInlineVerticalFieldOfView(inline_vertical_field_of_view_cpp_value);
  }
}

v8::Local<v8::Value> XRRenderStateInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8XRRenderStateInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8XRRenderStateInit(const XRRenderStateInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8XRRenderStateInitKeys(isolate).data();
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

  v8::Local<v8::Value> base_layer_value;
  bool base_layer_has_value_or_default = false;
  if (impl->hasBaseLayer()) {
    base_layer_value = ToV8(impl->baseLayer(), creationContext, isolate);
    base_layer_has_value_or_default = true;
  }
  if (base_layer_has_value_or_default &&
      !create_property(0, base_layer_value)) {
    return false;
  }

  v8::Local<v8::Value> depth_far_value;
  bool depth_far_has_value_or_default = false;
  if (impl->hasDepthFar()) {
    depth_far_value = v8::Number::New(isolate, impl->depthFar());
    depth_far_has_value_or_default = true;
  }
  if (depth_far_has_value_or_default &&
      !create_property(1, depth_far_value)) {
    return false;
  }

  v8::Local<v8::Value> depth_near_value;
  bool depth_near_has_value_or_default = false;
  if (impl->hasDepthNear()) {
    depth_near_value = v8::Number::New(isolate, impl->depthNear());
    depth_near_has_value_or_default = true;
  }
  if (depth_near_has_value_or_default &&
      !create_property(2, depth_near_value)) {
    return false;
  }

  v8::Local<v8::Value> inline_vertical_field_of_view_value;
  bool inline_vertical_field_of_view_has_value_or_default = false;
  if (impl->hasInlineVerticalFieldOfView()) {
    inline_vertical_field_of_view_value = v8::Number::New(isolate, impl->inlineVerticalFieldOfView());
    inline_vertical_field_of_view_has_value_or_default = true;
  }
  if (inline_vertical_field_of_view_has_value_or_default &&
      !create_property(3, inline_vertical_field_of_view_value)) {
    return false;
  }

  return true;
}

XRRenderStateInit* NativeValueTraits<XRRenderStateInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  XRRenderStateInit* impl = MakeGarbageCollected<XRRenderStateInit>();
  V8XRRenderStateInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
