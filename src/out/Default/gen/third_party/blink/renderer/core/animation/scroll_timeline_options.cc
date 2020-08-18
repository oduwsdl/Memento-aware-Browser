// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/core/animation/scroll_timeline_options.h"

#include "third_party/blink/renderer/core/dom/element.h"

namespace blink {

ScrollTimelineOptions::ScrollTimelineOptions() {
  setEndScrollOffset(StringOrScrollTimelineElementBasedOffset::FromString("auto"));
  setOrientation("block");
  setScrollSource(nullptr);
  setStartScrollOffset(StringOrScrollTimelineElementBasedOffset::FromString("auto"));
  setTimeRange(DoubleOrScrollTimelineAutoKeyword::FromScrollTimelineAutoKeyword("auto"));
}

ScrollTimelineOptions::~ScrollTimelineOptions() = default;

void ScrollTimelineOptions::setEndScrollOffset(const StringOrScrollTimelineElementBasedOffset& value) {
  end_scroll_offset_ = value;
}

void ScrollTimelineOptions::setStartScrollOffset(const StringOrScrollTimelineElementBasedOffset& value) {
  start_scroll_offset_ = value;
}

void ScrollTimelineOptions::setTimeRange(const DoubleOrScrollTimelineAutoKeyword& value) {
  time_range_ = value;
}

void ScrollTimelineOptions::Trace(Visitor* visitor) const {
  visitor->Trace(end_scroll_offset_);
  visitor->Trace(scroll_source_);
  visitor->Trace(start_scroll_offset_);
  visitor->Trace(time_range_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
