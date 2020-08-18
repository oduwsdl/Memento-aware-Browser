// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_trust_token.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8TrustTokenKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "additionalSignedHeaders",
    "includeTimestampHeader",
    "issuer",
    "refreshPolicy",
    "signRequestData",
    "type",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8TrustToken::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, TrustToken* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): type.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8TrustTokenKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> additional_signed_headers_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&additional_signed_headers_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (additional_signed_headers_value.IsEmpty() || additional_signed_headers_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<String> additional_signed_headers_cpp_value = NativeValueTraits<IDLSequence<IDLUSVString>>::NativeValue(isolate, additional_signed_headers_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setAdditionalSignedHeaders(additional_signed_headers_cpp_value);
  }

  v8::Local<v8::Value> include_timestamp_header_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&include_timestamp_header_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (include_timestamp_header_value.IsEmpty() || include_timestamp_header_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool include_timestamp_header_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, include_timestamp_header_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setIncludeTimestampHeader(include_timestamp_header_cpp_value);
  }

  v8::Local<v8::Value> issuer_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&issuer_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (issuer_value.IsEmpty() || issuer_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> issuer_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, issuer_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setIssuer(issuer_cpp_value);
  }

  v8::Local<v8::Value> refresh_policy_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&refresh_policy_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (refresh_policy_value.IsEmpty() || refresh_policy_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> refresh_policy_cpp_value = refresh_policy_value;
    if (!refresh_policy_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "none",
        "refresh",
    };
    if (!IsValidEnum(refresh_policy_cpp_value, kValidValues, base::size(kValidValues), "RefreshPolicy", exception_state))
      return;
    impl->setRefreshPolicy(refresh_policy_cpp_value);
  }

  v8::Local<v8::Value> sign_request_data_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&sign_request_data_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (sign_request_data_value.IsEmpty() || sign_request_data_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> sign_request_data_cpp_value = sign_request_data_value;
    if (!sign_request_data_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "omit",
        "include",
        "headers-only",
    };
    if (!IsValidEnum(sign_request_data_cpp_value, kValidValues, base::size(kValidValues), "SignRequestData", exception_state))
      return;
    impl->setSignRequestData(sign_request_data_cpp_value);
  }

  v8::Local<v8::Value> type_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&type_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (type_value.IsEmpty() || type_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member type is undefined.");
    return;
  } else {
    V8StringResource<> type_cpp_value = type_value;
    if (!type_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "token-request",
        "send-srr",
        "srr-token-redemption",
    };
    if (!IsValidEnum(type_cpp_value, kValidValues, base::size(kValidValues), "OperationType", exception_state))
      return;
    impl->setType(type_cpp_value);
  }
}

v8::Local<v8::Value> TrustToken::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8TrustToken(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8TrustToken(const TrustToken* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8TrustTokenKeys(isolate).data();
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

  v8::Local<v8::Value> additional_signed_headers_value;
  bool additional_signed_headers_has_value_or_default = false;
  if (impl->hasAdditionalSignedHeaders()) {
    additional_signed_headers_value = ToV8(impl->additionalSignedHeaders(), creationContext, isolate);
    additional_signed_headers_has_value_or_default = true;
  }
  if (additional_signed_headers_has_value_or_default &&
      !create_property(0, additional_signed_headers_value)) {
    return false;
  }

  v8::Local<v8::Value> include_timestamp_header_value;
  bool include_timestamp_header_has_value_or_default = false;
  if (impl->hasIncludeTimestampHeader()) {
    include_timestamp_header_value = v8::Boolean::New(isolate, impl->includeTimestampHeader());
    include_timestamp_header_has_value_or_default = true;
  } else {
    include_timestamp_header_value = v8::Boolean::New(isolate, false);
    include_timestamp_header_has_value_or_default = true;
  }
  if (include_timestamp_header_has_value_or_default &&
      !create_property(1, include_timestamp_header_value)) {
    return false;
  }

  v8::Local<v8::Value> issuer_value;
  bool issuer_has_value_or_default = false;
  if (impl->hasIssuer()) {
    issuer_value = V8String(isolate, impl->issuer());
    issuer_has_value_or_default = true;
  }
  if (issuer_has_value_or_default &&
      !create_property(2, issuer_value)) {
    return false;
  }

  v8::Local<v8::Value> refresh_policy_value;
  bool refresh_policy_has_value_or_default = false;
  if (impl->hasRefreshPolicy()) {
    refresh_policy_value = V8String(isolate, impl->refreshPolicy());
    refresh_policy_has_value_or_default = true;
  } else {
    refresh_policy_value = V8String(isolate, "none");
    refresh_policy_has_value_or_default = true;
  }
  if (refresh_policy_has_value_or_default &&
      !create_property(3, refresh_policy_value)) {
    return false;
  }

  v8::Local<v8::Value> sign_request_data_value;
  bool sign_request_data_has_value_or_default = false;
  if (impl->hasSignRequestData()) {
    sign_request_data_value = V8String(isolate, impl->signRequestData());
    sign_request_data_has_value_or_default = true;
  } else {
    sign_request_data_value = V8String(isolate, "omit");
    sign_request_data_has_value_or_default = true;
  }
  if (sign_request_data_has_value_or_default &&
      !create_property(4, sign_request_data_value)) {
    return false;
  }

  v8::Local<v8::Value> type_value;
  bool type_has_value_or_default = false;
  if (impl->hasType()) {
    type_value = V8String(isolate, impl->type());
    type_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (type_has_value_or_default &&
      !create_property(5, type_value)) {
    return false;
  }

  return true;
}

TrustToken* NativeValueTraits<TrustToken>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  TrustToken* impl = MakeGarbageCollected<TrustToken>();
  V8TrustToken::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
