// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/animation/scroll_timeline_element_based_offset.h"

#include "third_party/blink/renderer/core/dom/element.h"

namespace blink {

ScrollTimelineElementBasedOffset::ScrollTimelineElementBasedOffset() {
  setEdge("start");
  setThreshold(0);
}

ScrollTimelineElementBasedOffset::~ScrollTimelineElementBasedOffset() = default;

void ScrollTimelineElementBasedOffset::Trace(Visitor* visitor) const {
  visitor->Trace(target_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
