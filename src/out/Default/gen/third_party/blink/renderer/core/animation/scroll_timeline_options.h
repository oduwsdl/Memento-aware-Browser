// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_SCROLL_TIMELINE_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_SCROLL_TIMELINE_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/double_or_scroll_timeline_auto_keyword.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/core/v8/string_or_scroll_timeline_element_based_offset.h"
#include "third_party/blink/renderer/core/animation/scroll_timeline_element_based_offset.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class Element;

class CORE_EXPORT ScrollTimelineOptions : public IDLDictionaryBase {
 public:
  static ScrollTimelineOptions* Create() { return MakeGarbageCollected<ScrollTimelineOptions>(); }
  static ScrollTimelineOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ScrollTimelineOptions>();
  }

  ScrollTimelineOptions();
  virtual ~ScrollTimelineOptions();

  bool hasEndScrollOffset() const { return !end_scroll_offset_.IsNull(); }
  const StringOrScrollTimelineElementBasedOffset& endScrollOffset() const {
    return end_scroll_offset_;
  }
  void setEndScrollOffset(const StringOrScrollTimelineElementBasedOffset&);

  bool hasOrientation() const { return !orientation_.IsNull(); }
  const String& orientation() const {
    return orientation_;
  }
  inline void setOrientation(const String&);

  bool hasScrollSource() const { return has_scroll_source_; }
  Element* scrollSource() const {
    return scroll_source_;
  }
  inline void setScrollSource(Element*);
  inline void setScrollSourceToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasScrollSourceNonNull() const { return has_scroll_source_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasScrollSourceNonNull| in advance to check the condition.
  Element* scrollSourceNonNull() const {
    DCHECK(hasScrollSourceNonNull());
    return scroll_source_;
  }

  bool hasStartScrollOffset() const { return !start_scroll_offset_.IsNull(); }
  const StringOrScrollTimelineElementBasedOffset& startScrollOffset() const {
    return start_scroll_offset_;
  }
  void setStartScrollOffset(const StringOrScrollTimelineElementBasedOffset&);

  bool hasTimeRange() const { return !time_range_.IsNull(); }
  const DoubleOrScrollTimelineAutoKeyword& timeRange() const {
    return time_range_;
  }
  void setTimeRange(const DoubleOrScrollTimelineAutoKeyword&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_scroll_source_ = false;

  StringOrScrollTimelineElementBasedOffset end_scroll_offset_;
  String orientation_;
  Member<Element> scroll_source_;
  StringOrScrollTimelineElementBasedOffset start_scroll_offset_;
  DoubleOrScrollTimelineAutoKeyword time_range_;

  friend class V8ScrollTimelineOptions;
};

void ScrollTimelineOptions::setOrientation(const String& value) {
  orientation_ = value;
}

void ScrollTimelineOptions::setScrollSource(Element* value) {
  scroll_source_ = value;
  has_scroll_source_ = true;
}

void ScrollTimelineOptions::setScrollSourceToNull() {
  scroll_source_ = Member<Element>();
  has_scroll_source_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_SCROLL_TIMELINE_OPTIONS_H_
