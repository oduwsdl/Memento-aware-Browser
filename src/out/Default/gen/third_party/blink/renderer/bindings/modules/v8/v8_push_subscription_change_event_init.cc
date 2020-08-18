// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_push_subscription_change_event_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_extendable_event_init.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_push_subscription.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8PushSubscriptionChangeEventInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "newSubscription",
    "oldSubscription",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8PushSubscriptionChangeEventInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, PushSubscriptionChangeEventInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  V8ExtendableEventInit::ToImpl(isolate, v8_value, impl, exception_state);
  if (exception_state.HadException())
    return;

  const auto* keys = eternalV8PushSubscriptionChangeEventInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> new_subscription_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&new_subscription_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (new_subscription_value.IsEmpty() || new_subscription_value->IsUndefined()) {
    // Do nothing.
  } else {
    PushSubscription* new_subscription_cpp_value = V8PushSubscription::ToImplWithTypeCheck(isolate, new_subscription_value);
    if (!new_subscription_cpp_value) {
      exception_state.ThrowTypeError("member newSubscription is not of type PushSubscription.");
      return;
    }
    impl->setNewSubscription(new_subscription_cpp_value);
  }

  v8::Local<v8::Value> old_subscription_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&old_subscription_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (old_subscription_value.IsEmpty() || old_subscription_value->IsUndefined()) {
    // Do nothing.
  } else {
    PushSubscription* old_subscription_cpp_value = V8PushSubscription::ToImplWithTypeCheck(isolate, old_subscription_value);
    if (!old_subscription_cpp_value) {
      exception_state.ThrowTypeError("member oldSubscription is not of type PushSubscription.");
      return;
    }
    impl->setOldSubscription(old_subscription_cpp_value);
  }
}

v8::Local<v8::Value> PushSubscriptionChangeEventInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8PushSubscriptionChangeEventInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8PushSubscriptionChangeEventInit(const PushSubscriptionChangeEventInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8ExtendableEventInit(impl, dictionary, creationContext, isolate))
    return false;

  const auto* keys = eternalV8PushSubscriptionChangeEventInitKeys(isolate).data();
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

  v8::Local<v8::Value> new_subscription_value;
  bool new_subscription_has_value_or_default = false;
  if (impl->hasNewSubscription()) {
    new_subscription_value = ToV8(impl->newSubscription(), creationContext, isolate);
    new_subscription_has_value_or_default = true;
  }
  if (new_subscription_has_value_or_default &&
      !create_property(0, new_subscription_value)) {
    return false;
  }

  v8::Local<v8::Value> old_subscription_value;
  bool old_subscription_has_value_or_default = false;
  if (impl->hasOldSubscription()) {
    old_subscription_value = ToV8(impl->oldSubscription(), creationContext, isolate);
    old_subscription_has_value_or_default = true;
  }
  if (old_subscription_has_value_or_default &&
      !create_property(1, old_subscription_value)) {
    return false;
  }

  return true;
}

PushSubscriptionChangeEventInit* NativeValueTraits<PushSubscriptionChangeEventInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  PushSubscriptionChangeEventInit* impl = MakeGarbageCollected<PushSubscriptionChangeEventInit>();
  V8PushSubscriptionChangeEventInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
