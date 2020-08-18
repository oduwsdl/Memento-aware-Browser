// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_transient_input_hit_test_options_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_ray.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8XRTransientInputHitTestOptionsInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "entityTypes",
    "offsetRay",
    "profile",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8XRTransientInputHitTestOptionsInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, XRTransientInputHitTestOptionsInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): profile.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8XRTransientInputHitTestOptionsInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> offset_ray_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&offset_ray_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (offset_ray_value.IsEmpty() || offset_ray_value->IsUndefined()) {
    // Do nothing.
  } else {
    XRRay* offset_ray_cpp_value = V8XRRay::ToImplWithTypeCheck(isolate, offset_ray_value);
    if (!offset_ray_cpp_value) {
      exception_state.ThrowTypeError("member offsetRay is not of type XRRay.");
      return;
    }
    impl->setOffsetRay(offset_ray_cpp_value);
  }

  v8::Local<v8::Value> profile_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&profile_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (profile_value.IsEmpty() || profile_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member profile is undefined.");
    return;
  } else {
    V8StringResource<> profile_cpp_value = profile_value;
    if (!profile_cpp_value.Prepare(exception_state))
      return;
    impl->setProfile(profile_cpp_value);
  }

  if (RuntimeEnabledFeatures::WebXRHitTestEntityTypesEnabled()) {
    v8::Local<v8::Value> entity_types_value;
    if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&entity_types_value)) {
      exception_state.RethrowV8Exception(block.Exception());
      return;
    }
    if (entity_types_value.IsEmpty() || entity_types_value->IsUndefined()) {
      // Do nothing.
    } else {
      Vector<String> entity_types_cpp_value = NativeValueTraits<IDLSequence<IDLString>>::NativeValue(isolate, entity_types_value, exception_state);
      if (exception_state.HadException())
        return;
      const char* const kValidValues[] = {
          "point",
          "plane",
          nullptr,
      };
      if (!IsValidEnum(entity_types_cpp_value, kValidValues, base::size(kValidValues), "XRHitTestTrackableType", exception_state))
        return;
      impl->setEntityTypes(entity_types_cpp_value);
    }
  }
}

v8::Local<v8::Value> XRTransientInputHitTestOptionsInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8XRTransientInputHitTestOptionsInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8XRTransientInputHitTestOptionsInit(const XRTransientInputHitTestOptionsInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8XRTransientInputHitTestOptionsInitKeys(isolate).data();
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

  v8::Local<v8::Value> offset_ray_value;
  bool offset_ray_has_value_or_default = false;
  if (impl->hasOffsetRay()) {
    offset_ray_value = ToV8(impl->offsetRay(), creationContext, isolate);
    offset_ray_has_value_or_default = true;
  }
  if (offset_ray_has_value_or_default &&
      !create_property(1, offset_ray_value)) {
    return false;
  }

  v8::Local<v8::Value> profile_value;
  bool profile_has_value_or_default = false;
  if (impl->hasProfile()) {
    profile_value = V8String(isolate, impl->profile());
    profile_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (profile_has_value_or_default &&
      !create_property(2, profile_value)) {
    return false;
  }

  if (RuntimeEnabledFeatures::WebXRHitTestEntityTypesEnabled()) {
    v8::Local<v8::Value> entity_types_value;
    bool entity_types_has_value_or_default = false;
    if (impl->hasEntityTypes()) {
      entity_types_value = FreezeV8Object(ToV8(impl->entityTypes(), creationContext, isolate), isolate);
      entity_types_has_value_or_default = true;
    }
    if (entity_types_has_value_or_default &&
        !create_property(0, entity_types_value)) {
      return false;
    }
  }

  return true;
}

XRTransientInputHitTestOptionsInit* NativeValueTraits<XRTransientInputHitTestOptionsInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  XRTransientInputHitTestOptionsInit* impl = MakeGarbageCollected<XRTransientInputHitTestOptionsInit>();
  V8XRTransientInputHitTestOptionsInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
