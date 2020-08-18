// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/crypto/json_web_key.h"

#include "third_party/blink/renderer/modules/crypto/rsa_other_primes_info.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

JsonWebKey::JsonWebKey() {
}

JsonWebKey::~JsonWebKey() = default;

void JsonWebKey::setKeyOps(const Vector<String>& value) {
  key_ops_ = value;
  has_key_ops_ = true;
}

void JsonWebKey::setOth(const HeapVector<Member<RsaOtherPrimesInfo>>& value) {
  oth_ = value;
  has_oth_ = true;
}

void JsonWebKey::Trace(Visitor* visitor) const {
  visitor->Trace(oth_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
