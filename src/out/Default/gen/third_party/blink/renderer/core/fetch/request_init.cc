// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/fetch/request_init.h"

#include "third_party/blink/renderer/core/dom/abort_signal.h"
#include "third_party/blink/renderer/core/fetch/trust_token.h"

namespace blink {

RequestInit::RequestInit() {
}

RequestInit::~RequestInit() = default;

void RequestInit::setBody(ScriptValue value) {
  body_ = value;
}

void RequestInit::setHeaders(const ByteStringSequenceSequenceOrByteStringByteStringRecord& value) {
  headers_ = value;
}

void RequestInit::setTrustToken(TrustToken* value) {
  trust_token_ = value;
}

void RequestInit::Trace(Visitor* visitor) const {
  visitor->Trace(body_);
  visitor->Trace(headers_);
  visitor->Trace(signal_);
  visitor->Trace(trust_token_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
