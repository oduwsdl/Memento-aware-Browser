// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_android_pay_method_data.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8AndroidPayMethodDataKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "apiVersion",
    "environment",
    "minGooglePlayServicesVersion",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8AndroidPayMethodData::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, AndroidPayMethodData* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8AndroidPayMethodDataKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> api_version_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&api_version_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (api_version_value.IsEmpty() || api_version_value->IsUndefined()) {
    // Do nothing.
  } else {
    int32_t api_version_cpp_value = NativeValueTraits<IDLLong>::NativeValue(isolate, api_version_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setApiVersion(api_version_cpp_value);
  }

  v8::Local<v8::Value> environment_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&environment_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (environment_value.IsEmpty() || environment_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> environment_cpp_value = environment_value;
    if (!environment_cpp_value.Prepare(exception_state))
      return;
    impl->setEnvironment(environment_cpp_value);
  }

  v8::Local<v8::Value> min_google_play_services_version_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&min_google_play_services_version_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (min_google_play_services_version_value.IsEmpty() || min_google_play_services_version_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> min_google_play_services_version_cpp_value = min_google_play_services_version_value;
    if (!min_google_play_services_version_cpp_value.Prepare(exception_state))
      return;
    impl->setMinGooglePlayServicesVersion(min_google_play_services_version_cpp_value);
  }
}

v8::Local<v8::Value> AndroidPayMethodData::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8AndroidPayMethodData(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8AndroidPayMethodData(const AndroidPayMethodData* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8AndroidPayMethodDataKeys(isolate).data();
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

  v8::Local<v8::Value> api_version_value;
  bool api_version_has_value_or_default = false;
  if (impl->hasApiVersion()) {
    api_version_value = v8::Integer::New(isolate, impl->apiVersion());
    api_version_has_value_or_default = true;
  }
  if (api_version_has_value_or_default &&
      !create_property(0, api_version_value)) {
    return false;
  }

  v8::Local<v8::Value> environment_value;
  bool environment_has_value_or_default = false;
  if (impl->hasEnvironment()) {
    environment_value = V8String(isolate, impl->environment());
    environment_has_value_or_default = true;
  }
  if (environment_has_value_or_default &&
      !create_property(1, environment_value)) {
    return false;
  }

  v8::Local<v8::Value> min_google_play_services_version_value;
  bool min_google_play_services_version_has_value_or_default = false;
  if (impl->hasMinGooglePlayServicesVersion()) {
    min_google_play_services_version_value = V8String(isolate, impl->minGooglePlayServicesVersion());
    min_google_play_services_version_has_value_or_default = true;
  }
  if (min_google_play_services_version_has_value_or_default &&
      !create_property(2, min_google_play_services_version_value)) {
    return false;
  }

  return true;
}

AndroidPayMethodData* NativeValueTraits<AndroidPayMethodData>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  AndroidPayMethodData* impl = MakeGarbageCollected<AndroidPayMethodData>();
  V8AndroidPayMethodData::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
