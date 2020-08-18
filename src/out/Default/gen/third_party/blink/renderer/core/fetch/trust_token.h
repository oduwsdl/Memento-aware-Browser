// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FETCH_TRUST_TOKEN_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FETCH_TRUST_TOKEN_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class CORE_EXPORT TrustToken : public IDLDictionaryBase {
 public:
  static TrustToken* Create() { return MakeGarbageCollected<TrustToken>(); }
  static TrustToken* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<TrustToken>();
  }

  TrustToken();
  virtual ~TrustToken();

  bool hasAdditionalSignedHeaders() const { return has_additional_signed_headers_; }
  const Vector<String>& additionalSignedHeaders() const {
    DCHECK(has_additional_signed_headers_);
    return additional_signed_headers_;
  }
  void setAdditionalSignedHeaders(const Vector<String>&);

  bool hasIncludeTimestampHeader() const { return has_include_timestamp_header_; }
  bool includeTimestampHeader() const {
    DCHECK(has_include_timestamp_header_);
    return include_timestamp_header_;
  }
  inline void setIncludeTimestampHeader(bool);

  bool hasIssuer() const { return !issuer_.IsNull(); }
  const String& issuer() const {
    return issuer_;
  }
  inline void setIssuer(const String&);

  bool hasRefreshPolicy() const { return !refresh_policy_.IsNull(); }
  const String& refreshPolicy() const {
    return refresh_policy_;
  }
  inline void setRefreshPolicy(const String&);

  bool hasSignRequestData() const { return !sign_request_data_.IsNull(); }
  const String& signRequestData() const {
    return sign_request_data_;
  }
  inline void setSignRequestData(const String&);

  bool hasType() const { return !type_.IsNull(); }
  const String& type() const {
    return type_;
  }
  inline void setType(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_additional_signed_headers_ = false;
  bool has_include_timestamp_header_ = false;

  Vector<String> additional_signed_headers_;
  bool include_timestamp_header_;
  String issuer_;
  String refresh_policy_;
  String sign_request_data_;
  String type_;

  friend class V8TrustToken;
};

void TrustToken::setIncludeTimestampHeader(bool value) {
  include_timestamp_header_ = value;
  has_include_timestamp_header_ = true;
}

void TrustToken::setIssuer(const String& value) {
  issuer_ = value;
}

void TrustToken::setRefreshPolicy(const String& value) {
  refresh_policy_ = value;
}

void TrustToken::setSignRequestData(const String& value) {
  sign_request_data_ = value;
}

void TrustToken::setType(const String& value) {
  type_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FETCH_TRUST_TOKEN_H_
