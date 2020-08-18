// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_measure_memory_breakdown.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8MeasureMemoryBreakdownKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "attribution",
    "bytes",
    "userAgentSpecificTypes",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8MeasureMemoryBreakdown::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, MeasureMemoryBreakdown* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8MeasureMemoryBreakdownKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> attribution_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&attribution_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (attribution_value.IsEmpty() || attribution_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<String> attribution_cpp_value = NativeValueTraits<IDLSequence<IDLString>>::NativeValue(isolate, attribution_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setAttribution(attribution_cpp_value);
  }

  v8::Local<v8::Value> bytes_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&bytes_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (bytes_value.IsEmpty() || bytes_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t bytes_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, bytes_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setBytes(bytes_cpp_value);
  }

  v8::Local<v8::Value> user_agent_specific_types_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&user_agent_specific_types_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (user_agent_specific_types_value.IsEmpty() || user_agent_specific_types_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<String> user_agent_specific_types_cpp_value = NativeValueTraits<IDLSequence<IDLString>>::NativeValue(isolate, user_agent_specific_types_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setUserAgentSpecificTypes(user_agent_specific_types_cpp_value);
  }
}

v8::Local<v8::Value> MeasureMemoryBreakdown::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8MeasureMemoryBreakdown(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8MeasureMemoryBreakdown(const MeasureMemoryBreakdown* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8MeasureMemoryBreakdownKeys(isolate).data();
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

  v8::Local<v8::Value> attribution_value;
  bool attribution_has_value_or_default = false;
  if (impl->hasAttribution()) {
    attribution_value = ToV8(impl->attribution(), creationContext, isolate);
    attribution_has_value_or_default = true;
  }
  if (attribution_has_value_or_default &&
      !create_property(0, attribution_value)) {
    return false;
  }

  v8::Local<v8::Value> bytes_value;
  bool bytes_has_value_or_default = false;
  if (impl->hasBytes()) {
    bytes_value = v8::Number::New(isolate, static_cast<double>(impl->bytes()));
    bytes_has_value_or_default = true;
  }
  if (bytes_has_value_or_default &&
      !create_property(1, bytes_value)) {
    return false;
  }

  v8::Local<v8::Value> user_agent_specific_types_value;
  bool user_agent_specific_types_has_value_or_default = false;
  if (impl->hasUserAgentSpecificTypes()) {
    user_agent_specific_types_value = ToV8(impl->userAgentSpecificTypes(), creationContext, isolate);
    user_agent_specific_types_has_value_or_default = true;
  }
  if (user_agent_specific_types_has_value_or_default &&
      !create_property(2, user_agent_specific_types_value)) {
    return false;
  }

  return true;
}

MeasureMemoryBreakdown* NativeValueTraits<MeasureMemoryBreakdown>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  MeasureMemoryBreakdown* impl = MakeGarbageCollected<MeasureMemoryBreakdown>();
  V8MeasureMemoryBreakdown::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
