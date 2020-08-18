// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_peer_connection_ice_error_event_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_event_init.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8RTCPeerConnectionIceErrorEventInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "address",
    "errorCode",
    "hostCandidate",
    "port",
    "statusText",
    "url",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8RTCPeerConnectionIceErrorEventInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, RTCPeerConnectionIceErrorEventInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): errorCode.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  V8EventInit::ToImpl(isolate, v8_value, impl, exception_state);
  if (exception_state.HadException())
    return;

  const auto* keys = eternalV8RTCPeerConnectionIceErrorEventInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> address_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&address_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (address_value.IsEmpty() || address_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<kTreatNullAndUndefinedAsNullString> address_cpp_value = address_value;
    if (!address_cpp_value.Prepare(exception_state))
      return;
    impl->setAddress(address_cpp_value);
  }

  v8::Local<v8::Value> error_code_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&error_code_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (error_code_value.IsEmpty() || error_code_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member errorCode is undefined.");
    return;
  } else {
    uint16_t error_code_cpp_value = NativeValueTraits<IDLUnsignedShort>::NativeValue(isolate, error_code_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setErrorCode(error_code_cpp_value);
  }

  v8::Local<v8::Value> host_candidate_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&host_candidate_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (host_candidate_value.IsEmpty() || host_candidate_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> host_candidate_cpp_value = host_candidate_value;
    if (!host_candidate_cpp_value.Prepare(exception_state))
      return;
    impl->setHostCandidate(host_candidate_cpp_value);
  }

  v8::Local<v8::Value> port_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&port_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (port_value.IsEmpty() || port_value->IsUndefined()) {
    // Do nothing.
  } else if (port_value->IsNull()) {
    impl->setPortToNull();
  } else {
    uint16_t port_cpp_value = NativeValueTraits<IDLUnsignedShort>::NativeValue(isolate, port_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setPort(port_cpp_value);
  }

  v8::Local<v8::Value> status_text_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&status_text_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (status_text_value.IsEmpty() || status_text_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> status_text_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, status_text_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setStatusText(status_text_cpp_value);
  }

  v8::Local<v8::Value> url_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&url_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (url_value.IsEmpty() || url_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> url_cpp_value = url_value;
    if (!url_cpp_value.Prepare(exception_state))
      return;
    impl->setUrl(url_cpp_value);
  }
}

v8::Local<v8::Value> RTCPeerConnectionIceErrorEventInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8RTCPeerConnectionIceErrorEventInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8RTCPeerConnectionIceErrorEventInit(const RTCPeerConnectionIceErrorEventInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8EventInit(impl, dictionary, creationContext, isolate))
    return false;

  const auto* keys = eternalV8RTCPeerConnectionIceErrorEventInitKeys(isolate).data();
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

  v8::Local<v8::Value> address_value;
  bool address_has_value_or_default = false;
  if (impl->hasAddress()) {
    address_value = V8String(isolate, impl->address());
    address_has_value_or_default = true;
  } else {
    address_value = v8::Null(isolate);
    address_has_value_or_default = true;
  }
  if (address_has_value_or_default &&
      !create_property(0, address_value)) {
    return false;
  }

  v8::Local<v8::Value> error_code_value;
  bool error_code_has_value_or_default = false;
  if (impl->hasErrorCode()) {
    error_code_value = v8::Integer::NewFromUnsigned(isolate, impl->errorCode());
    error_code_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (error_code_has_value_or_default &&
      !create_property(1, error_code_value)) {
    return false;
  }

  v8::Local<v8::Value> host_candidate_value;
  bool host_candidate_has_value_or_default = false;
  if (impl->hasHostCandidate()) {
    host_candidate_value = V8String(isolate, impl->hostCandidate());
    host_candidate_has_value_or_default = true;
  }
  if (host_candidate_has_value_or_default &&
      !create_property(2, host_candidate_value)) {
    return false;
  }

  v8::Local<v8::Value> port_value;
  bool port_has_value_or_default = false;
  if (impl->hasPort()) {
    port_value = v8::Integer::NewFromUnsigned(isolate, impl->port());
    port_has_value_or_default = true;
  } else {
    port_value = v8::Null(isolate);
    port_has_value_or_default = true;
  }
  if (port_has_value_or_default &&
      !create_property(3, port_value)) {
    return false;
  }

  v8::Local<v8::Value> status_text_value;
  bool status_text_has_value_or_default = false;
  if (impl->hasStatusText()) {
    status_text_value = V8String(isolate, impl->statusText());
    status_text_has_value_or_default = true;
  }
  if (status_text_has_value_or_default &&
      !create_property(4, status_text_value)) {
    return false;
  }

  v8::Local<v8::Value> url_value;
  bool url_has_value_or_default = false;
  if (impl->hasUrl()) {
    url_value = V8String(isolate, impl->url());
    url_has_value_or_default = true;
  }
  if (url_has_value_or_default &&
      !create_property(5, url_value)) {
    return false;
  }

  return true;
}

RTCPeerConnectionIceErrorEventInit* NativeValueTraits<RTCPeerConnectionIceErrorEventInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  RTCPeerConnectionIceErrorEventInit* impl = MakeGarbageCollected<RTCPeerConnectionIceErrorEventInit>();
  V8RTCPeerConnectionIceErrorEventInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
