// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/credentialmanager/otp_credential_request_options.h"

namespace blink {

OTPCredentialRequestOptions::OTPCredentialRequestOptions() {
  setTransport(Vector<String>());
}

OTPCredentialRequestOptions::~OTPCredentialRequestOptions() = default;

void OTPCredentialRequestOptions::setTransport(const Vector<String>& value) {
  transport_ = value;
  has_transport_ = true;
}

void OTPCredentialRequestOptions::Trace(Visitor* visitor) const {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
