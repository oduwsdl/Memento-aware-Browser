// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_trace.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_frame.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_sample.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_stack.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ProfilerTraceKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "frames",
    "resources",
    "samples",
    "stacks",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ProfilerTrace::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ProfilerTrace* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): frames, resources, samples, stacks.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ProfilerTraceKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> frames_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&frames_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (frames_value.IsEmpty() || frames_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member frames is undefined.");
    return;
  } else {
    HeapVector<Member<ProfilerFrame>> frames_cpp_value = NativeValueTraits<IDLSequence<ProfilerFrame>>::NativeValue(isolate, frames_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setFrames(frames_cpp_value);
  }

  v8::Local<v8::Value> resources_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&resources_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (resources_value.IsEmpty() || resources_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member resources is undefined.");
    return;
  } else {
    Vector<String> resources_cpp_value = NativeValueTraits<IDLSequence<IDLString>>::NativeValue(isolate, resources_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setResources(resources_cpp_value);
  }

  v8::Local<v8::Value> samples_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&samples_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (samples_value.IsEmpty() || samples_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member samples is undefined.");
    return;
  } else {
    HeapVector<Member<ProfilerSample>> samples_cpp_value = NativeValueTraits<IDLSequence<ProfilerSample>>::NativeValue(isolate, samples_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSamples(samples_cpp_value);
  }

  v8::Local<v8::Value> stacks_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&stacks_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (stacks_value.IsEmpty() || stacks_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member stacks is undefined.");
    return;
  } else {
    HeapVector<Member<ProfilerStack>> stacks_cpp_value = NativeValueTraits<IDLSequence<ProfilerStack>>::NativeValue(isolate, stacks_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setStacks(stacks_cpp_value);
  }
}

v8::Local<v8::Value> ProfilerTrace::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ProfilerTrace(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ProfilerTrace(const ProfilerTrace* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ProfilerTraceKeys(isolate).data();
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

  v8::Local<v8::Value> frames_value;
  bool frames_has_value_or_default = false;
  if (impl->hasFrames()) {
    frames_value = ToV8(impl->frames(), creationContext, isolate);
    frames_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (frames_has_value_or_default &&
      !create_property(0, frames_value)) {
    return false;
  }

  v8::Local<v8::Value> resources_value;
  bool resources_has_value_or_default = false;
  if (impl->hasResources()) {
    resources_value = ToV8(impl->resources(), creationContext, isolate);
    resources_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (resources_has_value_or_default &&
      !create_property(1, resources_value)) {
    return false;
  }

  v8::Local<v8::Value> samples_value;
  bool samples_has_value_or_default = false;
  if (impl->hasSamples()) {
    samples_value = ToV8(impl->samples(), creationContext, isolate);
    samples_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (samples_has_value_or_default &&
      !create_property(2, samples_value)) {
    return false;
  }

  v8::Local<v8::Value> stacks_value;
  bool stacks_has_value_or_default = false;
  if (impl->hasStacks()) {
    stacks_value = ToV8(impl->stacks(), creationContext, isolate);
    stacks_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (stacks_has_value_or_default &&
      !create_property(3, stacks_value)) {
    return false;
  }

  return true;
}

ProfilerTrace* NativeValueTraits<ProfilerTrace>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ProfilerTrace* impl = MakeGarbageCollected<ProfilerTrace>();
  V8ProfilerTrace::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
