// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_rsa_other_primes_info.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8RsaOtherPrimesInfoKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "d",
    "r",
    "t",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8RsaOtherPrimesInfo::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, RsaOtherPrimesInfo* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8RsaOtherPrimesInfoKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> d_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&d_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (d_value.IsEmpty() || d_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> d_cpp_value = d_value;
    if (!d_cpp_value.Prepare(exception_state))
      return;
    impl->setD(d_cpp_value);
  }

  v8::Local<v8::Value> r_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&r_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (r_value.IsEmpty() || r_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> r_cpp_value = r_value;
    if (!r_cpp_value.Prepare(exception_state))
      return;
    impl->setR(r_cpp_value);
  }

  v8::Local<v8::Value> t_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&t_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (t_value.IsEmpty() || t_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> t_cpp_value = t_value;
    if (!t_cpp_value.Prepare(exception_state))
      return;
    impl->setT(t_cpp_value);
  }
}

v8::Local<v8::Value> RsaOtherPrimesInfo::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8RsaOtherPrimesInfo(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8RsaOtherPrimesInfo(const RsaOtherPrimesInfo* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8RsaOtherPrimesInfoKeys(isolate).data();
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

  v8::Local<v8::Value> d_value;
  bool d_has_value_or_default = false;
  if (impl->hasD()) {
    d_value = V8String(isolate, impl->d());
    d_has_value_or_default = true;
  }
  if (d_has_value_or_default &&
      !create_property(0, d_value)) {
    return false;
  }

  v8::Local<v8::Value> r_value;
  bool r_has_value_or_default = false;
  if (impl->hasR()) {
    r_value = V8String(isolate, impl->r());
    r_has_value_or_default = true;
  }
  if (r_has_value_or_default &&
      !create_property(1, r_value)) {
    return false;
  }

  v8::Local<v8::Value> t_value;
  bool t_has_value_or_default = false;
  if (impl->hasT()) {
    t_value = V8String(isolate, impl->t());
    t_has_value_or_default = true;
  }
  if (t_has_value_or_default &&
      !create_property(2, t_value)) {
    return false;
  }

  return true;
}

RsaOtherPrimesInfo* NativeValueTraits<RsaOtherPrimesInfo>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  RsaOtherPrimesInfo* impl = MakeGarbageCollected<RsaOtherPrimesInfo>();
  V8RsaOtherPrimesInfo::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
