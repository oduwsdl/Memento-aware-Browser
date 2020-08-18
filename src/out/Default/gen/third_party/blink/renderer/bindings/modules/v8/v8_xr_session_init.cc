// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_session_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_dom_overlay_init.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8XRSessionInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "domOverlay",
    "optionalFeatures",
    "requiredFeatures",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8XRSessionInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, XRSessionInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8XRSessionInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> dom_overlay_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&dom_overlay_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (dom_overlay_value.IsEmpty() || dom_overlay_value->IsUndefined()) {
    // Do nothing.
  } else {
    XRDOMOverlayInit* dom_overlay_cpp_value = NativeValueTraits<XRDOMOverlayInit>::NativeValue(isolate, dom_overlay_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDomOverlay(dom_overlay_cpp_value);
  }

  v8::Local<v8::Value> optional_features_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&optional_features_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (optional_features_value.IsEmpty() || optional_features_value->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<ScriptValue> optional_features_cpp_value = NativeValueTraits<IDLSequence<ScriptValue>>::NativeValue(isolate, optional_features_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setOptionalFeatures(optional_features_cpp_value);
  }

  v8::Local<v8::Value> required_features_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&required_features_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (required_features_value.IsEmpty() || required_features_value->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<ScriptValue> required_features_cpp_value = NativeValueTraits<IDLSequence<ScriptValue>>::NativeValue(isolate, required_features_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRequiredFeatures(required_features_cpp_value);
  }
}

v8::Local<v8::Value> XRSessionInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8XRSessionInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8XRSessionInit(const XRSessionInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8XRSessionInitKeys(isolate).data();
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

  v8::Local<v8::Value> dom_overlay_value;
  bool dom_overlay_has_value_or_default = false;
  if (impl->hasDomOverlay()) {
    dom_overlay_value = ToV8(impl->domOverlay(), creationContext, isolate);
    dom_overlay_has_value_or_default = true;
  }
  if (dom_overlay_has_value_or_default &&
      !create_property(0, dom_overlay_value)) {
    return false;
  }

  v8::Local<v8::Value> optional_features_value;
  bool optional_features_has_value_or_default = false;
  if (impl->hasOptionalFeatures()) {
    optional_features_value = ToV8(impl->optionalFeatures(), creationContext, isolate);
    optional_features_has_value_or_default = true;
  }
  if (optional_features_has_value_or_default &&
      !create_property(1, optional_features_value)) {
    return false;
  }

  v8::Local<v8::Value> required_features_value;
  bool required_features_has_value_or_default = false;
  if (impl->hasRequiredFeatures()) {
    required_features_value = ToV8(impl->requiredFeatures(), creationContext, isolate);
    required_features_has_value_or_default = true;
  }
  if (required_features_has_value_or_default &&
      !create_property(2, required_features_value)) {
    return false;
  }

  return true;
}

XRSessionInit* NativeValueTraits<XRSessionInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  XRSessionInit* impl = MakeGarbageCollected<XRSessionInit>();
  V8XRSessionInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
