// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_measure_memory.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_measure_memory_breakdown.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8MeasureMemoryKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "breakdown",
    "bytes",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8MeasureMemory::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, MeasureMemory* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): breakdown, bytes.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8MeasureMemoryKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> breakdown_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&breakdown_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (breakdown_value.IsEmpty() || breakdown_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member breakdown is undefined.");
    return;
  } else {
    HeapVector<Member<MeasureMemoryBreakdown>> breakdown_cpp_value = NativeValueTraits<IDLSequence<MeasureMemoryBreakdown>>::NativeValue(isolate, breakdown_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setBreakdown(breakdown_cpp_value);
  }

  v8::Local<v8::Value> bytes_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&bytes_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (bytes_value.IsEmpty() || bytes_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member bytes is undefined.");
    return;
  } else {
    uint64_t bytes_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, bytes_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setBytes(bytes_cpp_value);
  }
}

v8::Local<v8::Value> MeasureMemory::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8MeasureMemory(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8MeasureMemory(const MeasureMemory* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8MeasureMemoryKeys(isolate).data();
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

  v8::Local<v8::Value> breakdown_value;
  bool breakdown_has_value_or_default = false;
  if (impl->hasBreakdown()) {
    breakdown_value = ToV8(impl->breakdown(), creationContext, isolate);
    breakdown_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (breakdown_has_value_or_default &&
      !create_property(0, breakdown_value)) {
    return false;
  }

  v8::Local<v8::Value> bytes_value;
  bool bytes_has_value_or_default = false;
  if (impl->hasBytes()) {
    bytes_value = v8::Number::New(isolate, static_cast<double>(impl->bytes()));
    bytes_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (bytes_has_value_or_default &&
      !create_property(1, bytes_value)) {
    return false;
  }

  return true;
}

MeasureMemory* NativeValueTraits<MeasureMemory>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  MeasureMemory* impl = MakeGarbageCollected<MeasureMemory>();
  V8MeasureMemory::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
