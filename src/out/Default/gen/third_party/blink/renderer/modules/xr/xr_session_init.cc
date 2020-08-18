// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/xr/xr_session_init.h"

#include "third_party/blink/renderer/modules/xr/xr_dom_overlay_init.h"

namespace blink {

XRSessionInit::XRSessionInit() {
}

XRSessionInit::~XRSessionInit() = default;

void XRSessionInit::setDomOverlay(XRDOMOverlayInit* value) {
  dom_overlay_ = value;
}

void XRSessionInit::setOptionalFeatures(const HeapVector<ScriptValue>& value) {
  optional_features_ = value;
  has_optional_features_ = true;
}

void XRSessionInit::setRequiredFeatures(const HeapVector<ScriptValue>& value) {
  required_features_ = value;
  has_required_features_ = true;
}

void XRSessionInit::Trace(Visitor* visitor) const {
  visitor->Trace(dom_overlay_);
  visitor->Trace(optional_features_);
  visitor->Trace(required_features_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
