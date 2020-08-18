// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_pointer_lock_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8PointerLockOptionsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "unadjustedMovement",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8PointerLockOptions::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, PointerLockOptions* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8PointerLockOptionsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  ExecutionContext* executionContext = ToExecutionContext(context);
  DCHECK(executionContext);
  if (RuntimeEnabledFeatures::PointerLockOptionsEnabled(executionContext)) {
    v8::Local<v8::Value> unadjusted_movement_value;
    if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&unadjusted_movement_value)) {
      exception_state.RethrowV8Exception(block.Exception());
      return;
    }
    if (unadjusted_movement_value.IsEmpty() || unadjusted_movement_value->IsUndefined()) {
      // Do nothing.
    } else {
      bool unadjusted_movement_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, unadjusted_movement_value, exception_state);
      if (exception_state.HadException())
        return;
      impl->setUnadjustedMovement(unadjusted_movement_cpp_value);
    }
  }
}

v8::Local<v8::Value> PointerLockOptions::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8PointerLockOptions(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8PointerLockOptions(const PointerLockOptions* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8PointerLockOptionsKeys(isolate).data();
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

  ExecutionContext* executionContext = ToExecutionContext(context);
  DCHECK(executionContext);
  if (RuntimeEnabledFeatures::PointerLockOptionsEnabled(executionContext)) {
    v8::Local<v8::Value> unadjusted_movement_value;
    bool unadjusted_movement_has_value_or_default = false;
    if (impl->hasUnadjustedMovement()) {
      unadjusted_movement_value = v8::Boolean::New(isolate, impl->unadjustedMovement());
      unadjusted_movement_has_value_or_default = true;
    } else {
      unadjusted_movement_value = v8::Boolean::New(isolate, false);
      unadjusted_movement_has_value_or_default = true;
    }
    if (unadjusted_movement_has_value_or_default &&
        !create_property(0, unadjusted_movement_value)) {
      return false;
    }
  }

  return true;
}

PointerLockOptions* NativeValueTraits<PointerLockOptions>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  PointerLockOptions* impl = MakeGarbageCollected<PointerLockOptions>();
  V8PointerLockOptions::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
