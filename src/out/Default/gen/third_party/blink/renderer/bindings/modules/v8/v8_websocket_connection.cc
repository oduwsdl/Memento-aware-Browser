// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_websocket_connection.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_readable_stream.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_writable_stream.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8WebSocketConnectionKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "extensions",
    "protocol",
    "readable",
    "writable",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8WebSocketConnection::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, WebSocketConnection* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8WebSocketConnectionKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> extensions_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&extensions_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (extensions_value.IsEmpty() || extensions_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> extensions_cpp_value = extensions_value;
    if (!extensions_cpp_value.Prepare(exception_state))
      return;
    impl->setExtensions(extensions_cpp_value);
  }

  v8::Local<v8::Value> protocol_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&protocol_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (protocol_value.IsEmpty() || protocol_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> protocol_cpp_value = protocol_value;
    if (!protocol_cpp_value.Prepare(exception_state))
      return;
    impl->setProtocol(protocol_cpp_value);
  }

  v8::Local<v8::Value> readable_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&readable_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (readable_value.IsEmpty() || readable_value->IsUndefined()) {
    // Do nothing.
  } else {
    ReadableStream* readable_cpp_value = V8ReadableStream::ToImplWithTypeCheck(isolate, readable_value);
    if (!readable_cpp_value) {
      exception_state.ThrowTypeError("member readable is not of type ReadableStream.");
      return;
    }
    impl->setReadable(readable_cpp_value);
  }

  v8::Local<v8::Value> writable_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&writable_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (writable_value.IsEmpty() || writable_value->IsUndefined()) {
    // Do nothing.
  } else {
    WritableStream* writable_cpp_value = V8WritableStream::ToImplWithTypeCheck(isolate, writable_value);
    if (!writable_cpp_value) {
      exception_state.ThrowTypeError("member writable is not of type WritableStream.");
      return;
    }
    impl->setWritable(writable_cpp_value);
  }
}

v8::Local<v8::Value> WebSocketConnection::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8WebSocketConnection(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8WebSocketConnection(const WebSocketConnection* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8WebSocketConnectionKeys(isolate).data();
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

  v8::Local<v8::Value> extensions_value;
  bool extensions_has_value_or_default = false;
  if (impl->hasExtensions()) {
    extensions_value = V8String(isolate, impl->extensions());
    extensions_has_value_or_default = true;
  }
  if (extensions_has_value_or_default &&
      !create_property(0, extensions_value)) {
    return false;
  }

  v8::Local<v8::Value> protocol_value;
  bool protocol_has_value_or_default = false;
  if (impl->hasProtocol()) {
    protocol_value = V8String(isolate, impl->protocol());
    protocol_has_value_or_default = true;
  }
  if (protocol_has_value_or_default &&
      !create_property(1, protocol_value)) {
    return false;
  }

  v8::Local<v8::Value> readable_value;
  bool readable_has_value_or_default = false;
  if (impl->hasReadable()) {
    readable_value = ToV8(impl->readable(), creationContext, isolate);
    readable_has_value_or_default = true;
  }
  if (readable_has_value_or_default &&
      !create_property(2, readable_value)) {
    return false;
  }

  v8::Local<v8::Value> writable_value;
  bool writable_has_value_or_default = false;
  if (impl->hasWritable()) {
    writable_value = ToV8(impl->writable(), creationContext, isolate);
    writable_has_value_or_default = true;
  }
  if (writable_has_value_or_default &&
      !create_property(3, writable_value)) {
    return false;
  }

  return true;
}

WebSocketConnection* NativeValueTraits<WebSocketConnection>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  WebSocketConnection* impl = MakeGarbageCollected<WebSocketConnection>();
  V8WebSocketConnection::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
