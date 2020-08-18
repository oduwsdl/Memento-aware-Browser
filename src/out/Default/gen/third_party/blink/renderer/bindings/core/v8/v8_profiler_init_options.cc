// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_init_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ProfilerInitOptionsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "maxBufferSize",
    "sampleInterval",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ProfilerInitOptions::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ProfilerInitOptions* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): sampleInterval.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ProfilerInitOptionsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> max_buffer_size_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&max_buffer_size_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (max_buffer_size_value.IsEmpty() || max_buffer_size_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t max_buffer_size_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, max_buffer_size_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setMaxBufferSize(max_buffer_size_cpp_value);
  }

  v8::Local<v8::Value> sample_interval_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&sample_interval_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (sample_interval_value.IsEmpty() || sample_interval_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member sampleInterval is undefined.");
    return;
  } else {
    double sample_interval_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, sample_interval_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSampleInterval(sample_interval_cpp_value);
  }
}

v8::Local<v8::Value> ProfilerInitOptions::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ProfilerInitOptions(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ProfilerInitOptions(const ProfilerInitOptions* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ProfilerInitOptionsKeys(isolate).data();
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

  v8::Local<v8::Value> max_buffer_size_value;
  bool max_buffer_size_has_value_or_default = false;
  if (impl->hasMaxBufferSize()) {
    max_buffer_size_value = v8::Integer::NewFromUnsigned(isolate, impl->maxBufferSize());
    max_buffer_size_has_value_or_default = true;
  }
  if (max_buffer_size_has_value_or_default &&
      !create_property(0, max_buffer_size_value)) {
    return false;
  }

  v8::Local<v8::Value> sample_interval_value;
  bool sample_interval_has_value_or_default = false;
  if (impl->hasSampleInterval()) {
    sample_interval_value = v8::Number::New(isolate, impl->sampleInterval());
    sample_interval_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (sample_interval_has_value_or_default &&
      !create_property(1, sample_interval_value)) {
    return false;
  }

  return true;
}

ProfilerInitOptions* NativeValueTraits<ProfilerInitOptions>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ProfilerInitOptions* impl = MakeGarbageCollected<ProfilerInitOptions>();
  V8ProfilerInitOptions::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
