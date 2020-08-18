// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_hit_test_options_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_ray.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_space.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8XRHitTestOptionsInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "entityTypes",
    "offsetRay",
    "space",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8XRHitTestOptionsInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, XRHitTestOptionsInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): space.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8XRHitTestOptionsInitKeys(isolate).data();
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

  v8::Local<v8::Value> space_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&space_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (space_value.IsEmpty() || space_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member space is undefined.");
    return;
  } else {
    XRSpace* space_cpp_value = V8XRSpace::ToImplWithTypeCheck(isolate, space_value);
    if (!space_cpp_value) {
      exception_state.ThrowTypeError("member space is not of type XRSpace.");
      return;
    }
    impl->setSpace(space_cpp_value);
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

v8::Local<v8::Value> XRHitTestOptionsInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8XRHitTestOptionsInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8XRHitTestOptionsInit(const XRHitTestOptionsInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8XRHitTestOptionsInitKeys(isolate).data();
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

  v8::Local<v8::Value> space_value;
  bool space_has_value_or_default = false;
  if (impl->hasSpace()) {
    space_value = ToV8(impl->space(), creationContext, isolate);
    space_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (space_has_value_or_default &&
      !create_property(2, space_value)) {
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

XRHitTestOptionsInit* NativeValueTraits<XRHitTestOptionsInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  XRHitTestOptionsInit* impl = MakeGarbageCollected<XRHitTestOptionsInit>();
  V8XRHitTestOptionsInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
