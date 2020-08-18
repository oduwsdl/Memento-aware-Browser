// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/fetch/trust_token.h"

namespace blink {

TrustToken::TrustToken() {
  setIncludeTimestampHeader(false);
  setRefreshPolicy("none");
  setSignRequestData("omit");
}

TrustToken::~TrustToken() = default;

void TrustToken::setAdditionalSignedHeaders(const Vector<String>& value) {
  additional_signed_headers_ = value;
  has_additional_signed_headers_ = true;
}

void TrustToken::Trace(Visitor* visitor) const {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
