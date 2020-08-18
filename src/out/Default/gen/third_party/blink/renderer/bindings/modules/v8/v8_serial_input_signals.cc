// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_serial_input_signals.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8SerialInputSignalsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "cts",
    "dcd",
    "dsr",
    "ri",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8SerialInputSignals::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, SerialInputSignals* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): cts, dcd, dsr, ri.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8SerialInputSignalsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> cts_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&cts_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (cts_value.IsEmpty() || cts_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member cts is undefined.");
    return;
  } else {
    bool cts_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, cts_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setCts(cts_cpp_value);
  }

  v8::Local<v8::Value> dcd_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&dcd_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (dcd_value.IsEmpty() || dcd_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member dcd is undefined.");
    return;
  } else {
    bool dcd_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, dcd_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDcd(dcd_cpp_value);
  }

  v8::Local<v8::Value> dsr_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&dsr_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (dsr_value.IsEmpty() || dsr_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member dsr is undefined.");
    return;
  } else {
    bool dsr_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, dsr_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDsr(dsr_cpp_value);
  }

  v8::Local<v8::Value> ri_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&ri_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (ri_value.IsEmpty() || ri_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member ri is undefined.");
    return;
  } else {
    bool ri_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, ri_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRi(ri_cpp_value);
  }
}

v8::Local<v8::Value> SerialInputSignals::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8SerialInputSignals(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8SerialInputSignals(const SerialInputSignals* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8SerialInputSignalsKeys(isolate).data();
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

  v8::Local<v8::Value> cts_value;
  bool cts_has_value_or_default = false;
  if (impl->hasCts()) {
    cts_value = v8::Boolean::New(isolate, impl->cts());
    cts_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (cts_has_value_or_default &&
      !create_property(0, cts_value)) {
    return false;
  }

  v8::Local<v8::Value> dcd_value;
  bool dcd_has_value_or_default = false;
  if (impl->hasDcd()) {
    dcd_value = v8::Boolean::New(isolate, impl->dcd());
    dcd_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (dcd_has_value_or_default &&
      !create_property(1, dcd_value)) {
    return false;
  }

  v8::Local<v8::Value> dsr_value;
  bool dsr_has_value_or_default = false;
  if (impl->hasDsr()) {
    dsr_value = v8::Boolean::New(isolate, impl->dsr());
    dsr_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (dsr_has_value_or_default &&
      !create_property(2, dsr_value)) {
    return false;
  }

  v8::Local<v8::Value> ri_value;
  bool ri_has_value_or_default = false;
  if (impl->hasRi()) {
    ri_value = v8::Boolean::New(isolate, impl->ri());
    ri_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (ri_has_value_or_default &&
      !create_property(3, ri_value)) {
    return false;
  }

  return true;
}

SerialInputSignals* NativeValueTraits<SerialInputSignals>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  SerialInputSignals* impl = MakeGarbageCollected<SerialInputSignals>();
  V8SerialInputSignals::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
