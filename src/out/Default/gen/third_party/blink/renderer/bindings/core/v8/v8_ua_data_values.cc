// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_ua_data_values.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8UADataValuesKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "architecture",
    "model",
    "platform",
    "platformVersion",
    "uaFullVersion",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8UADataValues::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, UADataValues* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8UADataValuesKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> architecture_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&architecture_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (architecture_value.IsEmpty() || architecture_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> architecture_cpp_value = architecture_value;
    if (!architecture_cpp_value.Prepare(exception_state))
      return;
    impl->setArchitecture(architecture_cpp_value);
  }

  v8::Local<v8::Value> model_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&model_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (model_value.IsEmpty() || model_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> model_cpp_value = model_value;
    if (!model_cpp_value.Prepare(exception_state))
      return;
    impl->setModel(model_cpp_value);
  }

  v8::Local<v8::Value> platform_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&platform_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (platform_value.IsEmpty() || platform_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> platform_cpp_value = platform_value;
    if (!platform_cpp_value.Prepare(exception_state))
      return;
    impl->setPlatform(platform_cpp_value);
  }

  v8::Local<v8::Value> platform_version_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&platform_version_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (platform_version_value.IsEmpty() || platform_version_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> platform_version_cpp_value = platform_version_value;
    if (!platform_version_cpp_value.Prepare(exception_state))
      return;
    impl->setPlatformVersion(platform_version_cpp_value);
  }

  v8::Local<v8::Value> ua_full_version_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&ua_full_version_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (ua_full_version_value.IsEmpty() || ua_full_version_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> ua_full_version_cpp_value = ua_full_version_value;
    if (!ua_full_version_cpp_value.Prepare(exception_state))
      return;
    impl->setUaFullVersion(ua_full_version_cpp_value);
  }
}

v8::Local<v8::Value> UADataValues::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8UADataValues(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8UADataValues(const UADataValues* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8UADataValuesKeys(isolate).data();
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

  v8::Local<v8::Value> architecture_value;
  bool architecture_has_value_or_default = false;
  if (impl->hasArchitecture()) {
    architecture_value = V8String(isolate, impl->architecture());
    architecture_has_value_or_default = true;
  }
  if (architecture_has_value_or_default &&
      !create_property(0, architecture_value)) {
    return false;
  }

  v8::Local<v8::Value> model_value;
  bool model_has_value_or_default = false;
  if (impl->hasModel()) {
    model_value = V8String(isolate, impl->model());
    model_has_value_or_default = true;
  }
  if (model_has_value_or_default &&
      !create_property(1, model_value)) {
    return false;
  }

  v8::Local<v8::Value> platform_value;
  bool platform_has_value_or_default = false;
  if (impl->hasPlatform()) {
    platform_value = V8String(isolate, impl->platform());
    platform_has_value_or_default = true;
  }
  if (platform_has_value_or_default &&
      !create_property(2, platform_value)) {
    return false;
  }

  v8::Local<v8::Value> platform_version_value;
  bool platform_version_has_value_or_default = false;
  if (impl->hasPlatformVersion()) {
    platform_version_value = V8String(isolate, impl->platformVersion());
    platform_version_has_value_or_default = true;
  }
  if (platform_version_has_value_or_default &&
      !create_property(3, platform_version_value)) {
    return false;
  }

  v8::Local<v8::Value> ua_full_version_value;
  bool ua_full_version_has_value_or_default = false;
  if (impl->hasUaFullVersion()) {
    ua_full_version_value = V8String(isolate, impl->uaFullVersion());
    ua_full_version_has_value_or_default = true;
  }
  if (ua_full_version_has_value_or_default &&
      !create_property(4, ua_full_version_value)) {
    return false;
  }

  return true;
}

UADataValues* NativeValueTraits<UADataValues>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  UADataValues* impl = MakeGarbageCollected<UADataValues>();
  V8UADataValues::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
