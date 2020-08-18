// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_serial_output_signals.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8SerialOutputSignalsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "brk",
    "dtr",
    "rts",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8SerialOutputSignals::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, SerialOutputSignals* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8SerialOutputSignalsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> brk_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&brk_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (brk_value.IsEmpty() || brk_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool brk_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, brk_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setBrk(brk_cpp_value);
  }

  v8::Local<v8::Value> dtr_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&dtr_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (dtr_value.IsEmpty() || dtr_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool dtr_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, dtr_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDtr(dtr_cpp_value);
  }

  v8::Local<v8::Value> rts_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&rts_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (rts_value.IsEmpty() || rts_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool rts_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, rts_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRts(rts_cpp_value);
  }
}

v8::Local<v8::Value> SerialOutputSignals::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8SerialOutputSignals(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8SerialOutputSignals(const SerialOutputSignals* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8SerialOutputSignalsKeys(isolate).data();
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

  v8::Local<v8::Value> brk_value;
  bool brk_has_value_or_default = false;
  if (impl->hasBrk()) {
    brk_value = v8::Boolean::New(isolate, impl->brk());
    brk_has_value_or_default = true;
  }
  if (brk_has_value_or_default &&
      !create_property(0, brk_value)) {
    return false;
  }

  v8::Local<v8::Value> dtr_value;
  bool dtr_has_value_or_default = false;
  if (impl->hasDtr()) {
    dtr_value = v8::Boolean::New(isolate, impl->dtr());
    dtr_has_value_or_default = true;
  }
  if (dtr_has_value_or_default &&
      !create_property(1, dtr_value)) {
    return false;
  }

  v8::Local<v8::Value> rts_value;
  bool rts_has_value_or_default = false;
  if (impl->hasRts()) {
    rts_value = v8::Boolean::New(isolate, impl->rts());
    rts_has_value_or_default = true;
  }
  if (rts_has_value_or_default &&
      !create_property(2, rts_value)) {
    return false;
  }

  return true;
}

SerialOutputSignals* NativeValueTraits<SerialOutputSignals>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  SerialOutputSignals* impl = MakeGarbageCollected<SerialOutputSignals>();
  V8SerialOutputSignals::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
