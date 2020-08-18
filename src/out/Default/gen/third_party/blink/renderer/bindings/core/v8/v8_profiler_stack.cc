// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_stack.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ProfilerStackKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "frameId",
    "parentId",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ProfilerStack::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ProfilerStack* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): frameId.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ProfilerStackKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> frame_id_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&frame_id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (frame_id_value.IsEmpty() || frame_id_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member frameId is undefined.");
    return;
  } else {
    uint64_t frame_id_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, frame_id_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setFrameId(frame_id_cpp_value);
  }

  v8::Local<v8::Value> parent_id_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&parent_id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (parent_id_value.IsEmpty() || parent_id_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t parent_id_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, parent_id_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setParentId(parent_id_cpp_value);
  }
}

v8::Local<v8::Value> ProfilerStack::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ProfilerStack(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ProfilerStack(const ProfilerStack* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ProfilerStackKeys(isolate).data();
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

  v8::Local<v8::Value> frame_id_value;
  bool frame_id_has_value_or_default = false;
  if (impl->hasFrameId()) {
    frame_id_value = v8::Number::New(isolate, static_cast<double>(impl->frameId()));
    frame_id_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (frame_id_has_value_or_default &&
      !create_property(0, frame_id_value)) {
    return false;
  }

  v8::Local<v8::Value> parent_id_value;
  bool parent_id_has_value_or_default = false;
  if (impl->hasParentId()) {
    parent_id_value = v8::Number::New(isolate, static_cast<double>(impl->parentId()));
    parent_id_has_value_or_default = true;
  }
  if (parent_id_has_value_or_default &&
      !create_property(1, parent_id_value)) {
    return false;
  }

  return true;
}

ProfilerStack* NativeValueTraits<ProfilerStack>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ProfilerStack* impl = MakeGarbageCollected<ProfilerStack>();
  V8ProfilerStack::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
