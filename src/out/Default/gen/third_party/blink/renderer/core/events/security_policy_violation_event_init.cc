// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/events/security_policy_violation_event_init.h"

namespace blink {

SecurityPolicyViolationEventInit::SecurityPolicyViolationEventInit() {
  setBlockedURI(WTF::g_empty_string);
  setColumnNumber(0);
  setLineNumber(0);
  setReferrer(WTF::g_empty_string);
  setSample(WTF::g_empty_string);
  setSourceFile(WTF::g_empty_string);
}

SecurityPolicyViolationEventInit::~SecurityPolicyViolationEventInit() = default;

void SecurityPolicyViolationEventInit::Trace(Visitor* visitor) const {
  EventInit::Trace(visitor);
}

}  // namespace blink
