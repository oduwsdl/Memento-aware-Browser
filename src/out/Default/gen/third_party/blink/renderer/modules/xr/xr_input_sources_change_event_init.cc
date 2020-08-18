// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/xr/xr_input_sources_change_event_init.h"

#include "third_party/blink/renderer/modules/xr/xr_input_source.h"
#include "third_party/blink/renderer/modules/xr/xr_session.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

XRInputSourcesChangeEventInit::XRInputSourcesChangeEventInit() {
}

XRInputSourcesChangeEventInit::~XRInputSourcesChangeEventInit() = default;

void XRInputSourcesChangeEventInit::setAdded(const HeapVector<Member<XRInputSource>>& value) {
  added_ = value;
  has_added_ = true;
}

void XRInputSourcesChangeEventInit::setRemoved(const HeapVector<Member<XRInputSource>>& value) {
  removed_ = value;
  has_removed_ = true;
}

void XRInputSourcesChangeEventInit::Trace(Visitor* visitor) const {
  visitor->Trace(added_);
  visitor->Trace(removed_);
  visitor->Trace(session_);
  EventInit::Trace(visitor);
}

}  // namespace blink
