// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_SCROLL_TIMELINE_ELEMENT_BASED_OFFSET_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_SCROLL_TIMELINE_ELEMENT_BASED_OFFSET_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class Element;

class CORE_EXPORT ScrollTimelineElementBasedOffset : public IDLDictionaryBase {
 public:
  static ScrollTimelineElementBasedOffset* Create() { return MakeGarbageCollected<ScrollTimelineElementBasedOffset>(); }
  static ScrollTimelineElementBasedOffset* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ScrollTimelineElementBasedOffset>();
  }

  ScrollTimelineElementBasedOffset();
  virtual ~ScrollTimelineElementBasedOffset();

  bool hasEdge() const { return !edge_.IsNull(); }
  const String& edge() const {
    return edge_;
  }
  inline void setEdge(const String&);

  bool hasTarget() const { return !!target_; }
  Element* target() const {
    return target_;
  }
  inline void setTarget(Element*);

  bool hasThreshold() const { return has_threshold_; }
  double threshold() const {
    DCHECK(has_threshold_);
    return threshold_;
  }
  inline void setThreshold(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_threshold_ = false;

  String edge_;
  Member<Element> target_;
  double threshold_;

  friend class V8ScrollTimelineElementBasedOffset;
};

void ScrollTimelineElementBasedOffset::setEdge(const String& value) {
  edge_ = value;
}

void ScrollTimelineElementBasedOffset::setTarget(Element* value) {
  target_ = value;
}

void ScrollTimelineElementBasedOffset::setThreshold(double value) {
  threshold_ = value;
  has_threshold_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_SCROLL_TIMELINE_ELEMENT_BASED_OFFSET_H_
