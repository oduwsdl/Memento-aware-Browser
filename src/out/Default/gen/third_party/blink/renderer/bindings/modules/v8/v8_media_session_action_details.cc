// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_media_session_action_details.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8MediaSessionActionDetailsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "action",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8MediaSessionActionDetails::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, MediaSessionActionDetails* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): action.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8MediaSessionActionDetailsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> action_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&action_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (action_value.IsEmpty() || action_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member action is undefined.");
    return;
  } else {
    V8StringResource<> action_cpp_value = action_value;
    if (!action_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "play",
        "pause",
        "previoustrack",
        "nexttrack",
        "seekbackward",
        "seekforward",
        "skipad",
        "stop",
        "seekto",
    };
    if (!IsValidEnum(action_cpp_value, kValidValues, base::size(kValidValues), "MediaSessionAction", exception_state))
      return;
    impl->setAction(action_cpp_value);
  }
}

v8::Local<v8::Value> MediaSessionActionDetails::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8MediaSessionActionDetails(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8MediaSessionActionDetails(const MediaSessionActionDetails* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8MediaSessionActionDetailsKeys(isolate).data();
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

  v8::Local<v8::Value> action_value;
  bool action_has_value_or_default = false;
  if (impl->hasAction()) {
    action_value = V8String(isolate, impl->action());
    action_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (action_has_value_or_default &&
      !create_property(0, action_value)) {
    return false;
  }

  return true;
}

MediaSessionActionDetails* NativeValueTraits<MediaSessionActionDetails>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  MediaSessionActionDetails* impl = MakeGarbageCollected<MediaSessionActionDetails>();
  V8MediaSessionActionDetails::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
