// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_json_web_key.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_rsa_other_primes_info.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8JsonWebKeyKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "alg",
    "crv",
    "d",
    "dp",
    "dq",
    "e",
    "ext",
    "k",
    "key_ops",
    "kty",
    "n",
    "oth",
    "p",
    "q",
    "qi",
    "use",
    "x",
    "y",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8JsonWebKey::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, JsonWebKey* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8JsonWebKeyKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> alg_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&alg_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (alg_value.IsEmpty() || alg_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> alg_cpp_value = alg_value;
    if (!alg_cpp_value.Prepare(exception_state))
      return;
    impl->setAlg(alg_cpp_value);
  }

  v8::Local<v8::Value> crv_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&crv_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (crv_value.IsEmpty() || crv_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> crv_cpp_value = crv_value;
    if (!crv_cpp_value.Prepare(exception_state))
      return;
    impl->setCrv(crv_cpp_value);
  }

  v8::Local<v8::Value> d_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&d_value)) {
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

  v8::Local<v8::Value> dp_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&dp_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (dp_value.IsEmpty() || dp_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> dp_cpp_value = dp_value;
    if (!dp_cpp_value.Prepare(exception_state))
      return;
    impl->setDp(dp_cpp_value);
  }

  v8::Local<v8::Value> dq_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&dq_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (dq_value.IsEmpty() || dq_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> dq_cpp_value = dq_value;
    if (!dq_cpp_value.Prepare(exception_state))
      return;
    impl->setDq(dq_cpp_value);
  }

  v8::Local<v8::Value> e_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&e_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (e_value.IsEmpty() || e_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> e_cpp_value = e_value;
    if (!e_cpp_value.Prepare(exception_state))
      return;
    impl->setE(e_cpp_value);
  }

  v8::Local<v8::Value> ext_value;
  if (!v8Object->Get(context, keys[6].Get(isolate)).ToLocal(&ext_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (ext_value.IsEmpty() || ext_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool ext_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, ext_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setExt(ext_cpp_value);
  }

  v8::Local<v8::Value> k_value;
  if (!v8Object->Get(context, keys[7].Get(isolate)).ToLocal(&k_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (k_value.IsEmpty() || k_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> k_cpp_value = k_value;
    if (!k_cpp_value.Prepare(exception_state))
      return;
    impl->setK(k_cpp_value);
  }

  v8::Local<v8::Value> key_ops_value;
  if (!v8Object->Get(context, keys[8].Get(isolate)).ToLocal(&key_ops_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (key_ops_value.IsEmpty() || key_ops_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<String> key_ops_cpp_value = NativeValueTraits<IDLSequence<IDLString>>::NativeValue(isolate, key_ops_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setKeyOps(key_ops_cpp_value);
  }

  v8::Local<v8::Value> kty_value;
  if (!v8Object->Get(context, keys[9].Get(isolate)).ToLocal(&kty_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (kty_value.IsEmpty() || kty_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> kty_cpp_value = kty_value;
    if (!kty_cpp_value.Prepare(exception_state))
      return;
    impl->setKty(kty_cpp_value);
  }

  v8::Local<v8::Value> n_value;
  if (!v8Object->Get(context, keys[10].Get(isolate)).ToLocal(&n_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (n_value.IsEmpty() || n_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> n_cpp_value = n_value;
    if (!n_cpp_value.Prepare(exception_state))
      return;
    impl->setN(n_cpp_value);
  }

  v8::Local<v8::Value> oth_value;
  if (!v8Object->Get(context, keys[11].Get(isolate)).ToLocal(&oth_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (oth_value.IsEmpty() || oth_value->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<Member<RsaOtherPrimesInfo>> oth_cpp_value = NativeValueTraits<IDLSequence<RsaOtherPrimesInfo>>::NativeValue(isolate, oth_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setOth(oth_cpp_value);
  }

  v8::Local<v8::Value> p_value;
  if (!v8Object->Get(context, keys[12].Get(isolate)).ToLocal(&p_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (p_value.IsEmpty() || p_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> p_cpp_value = p_value;
    if (!p_cpp_value.Prepare(exception_state))
      return;
    impl->setP(p_cpp_value);
  }

  v8::Local<v8::Value> q_value;
  if (!v8Object->Get(context, keys[13].Get(isolate)).ToLocal(&q_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (q_value.IsEmpty() || q_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> q_cpp_value = q_value;
    if (!q_cpp_value.Prepare(exception_state))
      return;
    impl->setQ(q_cpp_value);
  }

  v8::Local<v8::Value> qi_value;
  if (!v8Object->Get(context, keys[14].Get(isolate)).ToLocal(&qi_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (qi_value.IsEmpty() || qi_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> qi_cpp_value = qi_value;
    if (!qi_cpp_value.Prepare(exception_state))
      return;
    impl->setQi(qi_cpp_value);
  }

  v8::Local<v8::Value> use_value;
  if (!v8Object->Get(context, keys[15].Get(isolate)).ToLocal(&use_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (use_value.IsEmpty() || use_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> use_cpp_value = use_value;
    if (!use_cpp_value.Prepare(exception_state))
      return;
    impl->setUse(use_cpp_value);
  }

  v8::Local<v8::Value> x_value;
  if (!v8Object->Get(context, keys[16].Get(isolate)).ToLocal(&x_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (x_value.IsEmpty() || x_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> x_cpp_value = x_value;
    if (!x_cpp_value.Prepare(exception_state))
      return;
    impl->setX(x_cpp_value);
  }

  v8::Local<v8::Value> y_value;
  if (!v8Object->Get(context, keys[17].Get(isolate)).ToLocal(&y_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (y_value.IsEmpty() || y_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> y_cpp_value = y_value;
    if (!y_cpp_value.Prepare(exception_state))
      return;
    impl->setY(y_cpp_value);
  }
}

v8::Local<v8::Value> JsonWebKey::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8JsonWebKey(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8JsonWebKey(const JsonWebKey* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8JsonWebKeyKeys(isolate).data();
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

  v8::Local<v8::Value> alg_value;
  bool alg_has_value_or_default = false;
  if (impl->hasAlg()) {
    alg_value = V8String(isolate, impl->alg());
    alg_has_value_or_default = true;
  }
  if (alg_has_value_or_default &&
      !create_property(0, alg_value)) {
    return false;
  }

  v8::Local<v8::Value> crv_value;
  bool crv_has_value_or_default = false;
  if (impl->hasCrv()) {
    crv_value = V8String(isolate, impl->crv());
    crv_has_value_or_default = true;
  }
  if (crv_has_value_or_default &&
      !create_property(1, crv_value)) {
    return false;
  }

  v8::Local<v8::Value> d_value;
  bool d_has_value_or_default = false;
  if (impl->hasD()) {
    d_value = V8String(isolate, impl->d());
    d_has_value_or_default = true;
  }
  if (d_has_value_or_default &&
      !create_property(2, d_value)) {
    return false;
  }

  v8::Local<v8::Value> dp_value;
  bool dp_has_value_or_default = false;
  if (impl->hasDp()) {
    dp_value = V8String(isolate, impl->dp());
    dp_has_value_or_default = true;
  }
  if (dp_has_value_or_default &&
      !create_property(3, dp_value)) {
    return false;
  }

  v8::Local<v8::Value> dq_value;
  bool dq_has_value_or_default = false;
  if (impl->hasDq()) {
    dq_value = V8String(isolate, impl->dq());
    dq_has_value_or_default = true;
  }
  if (dq_has_value_or_default &&
      !create_property(4, dq_value)) {
    return false;
  }

  v8::Local<v8::Value> e_value;
  bool e_has_value_or_default = false;
  if (impl->hasE()) {
    e_value = V8String(isolate, impl->e());
    e_has_value_or_default = true;
  }
  if (e_has_value_or_default &&
      !create_property(5, e_value)) {
    return false;
  }

  v8::Local<v8::Value> ext_value;
  bool ext_has_value_or_default = false;
  if (impl->hasExt()) {
    ext_value = v8::Boolean::New(isolate, impl->ext());
    ext_has_value_or_default = true;
  }
  if (ext_has_value_or_default &&
      !create_property(6, ext_value)) {
    return false;
  }

  v8::Local<v8::Value> k_value;
  bool k_has_value_or_default = false;
  if (impl->hasK()) {
    k_value = V8String(isolate, impl->k());
    k_has_value_or_default = true;
  }
  if (k_has_value_or_default &&
      !create_property(7, k_value)) {
    return false;
  }

  v8::Local<v8::Value> key_ops_value;
  bool key_ops_has_value_or_default = false;
  if (impl->hasKeyOps()) {
    key_ops_value = ToV8(impl->keyOps(), creationContext, isolate);
    key_ops_has_value_or_default = true;
  }
  if (key_ops_has_value_or_default &&
      !create_property(8, key_ops_value)) {
    return false;
  }

  v8::Local<v8::Value> kty_value;
  bool kty_has_value_or_default = false;
  if (impl->hasKty()) {
    kty_value = V8String(isolate, impl->kty());
    kty_has_value_or_default = true;
  }
  if (kty_has_value_or_default &&
      !create_property(9, kty_value)) {
    return false;
  }

  v8::Local<v8::Value> n_value;
  bool n_has_value_or_default = false;
  if (impl->hasN()) {
    n_value = V8String(isolate, impl->n());
    n_has_value_or_default = true;
  }
  if (n_has_value_or_default &&
      !create_property(10, n_value)) {
    return false;
  }

  v8::Local<v8::Value> oth_value;
  bool oth_has_value_or_default = false;
  if (impl->hasOth()) {
    oth_value = ToV8(impl->oth(), creationContext, isolate);
    oth_has_value_or_default = true;
  }
  if (oth_has_value_or_default &&
      !create_property(11, oth_value)) {
    return false;
  }

  v8::Local<v8::Value> p_value;
  bool p_has_value_or_default = false;
  if (impl->hasP()) {
    p_value = V8String(isolate, impl->p());
    p_has_value_or_default = true;
  }
  if (p_has_value_or_default &&
      !create_property(12, p_value)) {
    return false;
  }

  v8::Local<v8::Value> q_value;
  bool q_has_value_or_default = false;
  if (impl->hasQ()) {
    q_value = V8String(isolate, impl->q());
    q_has_value_or_default = true;
  }
  if (q_has_value_or_default &&
      !create_property(13, q_value)) {
    return false;
  }

  v8::Local<v8::Value> qi_value;
  bool qi_has_value_or_default = false;
  if (impl->hasQi()) {
    qi_value = V8String(isolate, impl->qi());
    qi_has_value_or_default = true;
  }
  if (qi_has_value_or_default &&
      !create_property(14, qi_value)) {
    return false;
  }

  v8::Local<v8::Value> use_value;
  bool use_has_value_or_default = false;
  if (impl->hasUse()) {
    use_value = V8String(isolate, impl->use());
    use_has_value_or_default = true;
  }
  if (use_has_value_or_default &&
      !create_property(15, use_value)) {
    return false;
  }

  v8::Local<v8::Value> x_value;
  bool x_has_value_or_default = false;
  if (impl->hasX()) {
    x_value = V8String(isolate, impl->x());
    x_has_value_or_default = true;
  }
  if (x_has_value_or_default &&
      !create_property(16, x_value)) {
    return false;
  }

  v8::Local<v8::Value> y_value;
  bool y_has_value_or_default = false;
  if (impl->hasY()) {
    y_value = V8String(isolate, impl->y());
    y_has_value_or_default = true;
  }
  if (y_has_value_or_default &&
      !create_property(17, y_value)) {
    return false;
  }

  return true;
}

JsonWebKey* NativeValueTraits<JsonWebKey>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  JsonWebKey* impl = MakeGarbageCollected<JsonWebKey>();
  V8JsonWebKey::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
