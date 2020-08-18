// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_websocket_stream_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_abort_signal.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8WebSocketStreamOptionsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "protocols",
    "signal",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8WebSocketStreamOptions::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, WebSocketStreamOptions* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8WebSocketStreamOptionsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> protocols_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&protocols_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (protocols_value.IsEmpty() || protocols_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<String> protocols_cpp_value = NativeValueTraits<IDLSequence<IDLUSVString>>::NativeValue(isolate, protocols_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setProtocols(protocols_cpp_value);
  }

  v8::Local<v8::Value> signal_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&signal_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (signal_value.IsEmpty() || signal_value->IsUndefined()) {
    // Do nothing.
  } else {
    AbortSignal* signal_cpp_value = V8AbortSignal::ToImplWithTypeCheck(isolate, signal_value);
    if (!signal_cpp_value) {
      exception_state.ThrowTypeError("member signal is not of type AbortSignal.");
      return;
    }
    impl->setSignal(signal_cpp_value);
  }
}

v8::Local<v8::Value> WebSocketStreamOptions::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8WebSocketStreamOptions(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8WebSocketStreamOptions(const WebSocketStreamOptions* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8WebSocketStreamOptionsKeys(isolate).data();
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

  v8::Local<v8::Value> protocols_value;
  bool protocols_has_value_or_default = false;
  if (impl->hasProtocols()) {
    protocols_value = ToV8(impl->protocols(), creationContext, isolate);
    protocols_has_value_or_default = true;
  }
  if (protocols_has_value_or_default &&
      !create_property(0, protocols_value)) {
    return false;
  }

  v8::Local<v8::Value> signal_value;
  bool signal_has_value_or_default = false;
  if (impl->hasSignal()) {
    signal_value = ToV8(impl->signal(), creationContext, isolate);
    signal_has_value_or_default = true;
  }
  if (signal_has_value_or_default &&
      !create_property(1, signal_value)) {
    return false;
  }

  return true;
}

WebSocketStreamOptions* NativeValueTraits<WebSocketStreamOptions>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  WebSocketStreamOptions* impl = MakeGarbageCollected<WebSocketStreamOptions>();
  V8WebSocketStreamOptions::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
