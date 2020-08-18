// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/html/portal/portal_activate_options.h"

namespace blink {

PortalActivateOptions::PortalActivateOptions() {
  setTransfer(HeapVector<ScriptValue>());
}

PortalActivateOptions::~PortalActivateOptions() = default;

void PortalActivateOptions::setData(ScriptValue value) {
  data_ = value;
}

void PortalActivateOptions::setTransfer(const HeapVector<ScriptValue>& value) {
  transfer_ = value;
  has_transfer_ = true;
}

void PortalActivateOptions::Trace(Visitor* visitor) const {
  visitor->Trace(data_);
  visitor->Trace(transfer_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
