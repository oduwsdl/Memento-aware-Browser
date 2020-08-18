// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_INTERSECTION_OBSERVER_INTERSECTION_OBSERVER_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_INTERSECTION_OBSERVER_INTERSECTION_OBSERVER_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/double_or_double_sequence.h"
#include "third_party/blink/renderer/bindings/core/v8/element_or_document.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/dom/element.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class CORE_EXPORT IntersectionObserverInit : public IDLDictionaryBase {
 public:
  static IntersectionObserverInit* Create() { return MakeGarbageCollected<IntersectionObserverInit>(); }
  static IntersectionObserverInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<IntersectionObserverInit>();
  }

  IntersectionObserverInit();
  virtual ~IntersectionObserverInit();

  bool hasDelay() const { return has_delay_; }
  double delay() const {
    DCHECK(has_delay_);
    return delay_;
  }
  inline void setDelay(double);

  bool hasRoot() const { return !root_.IsNull(); }
  const ElementOrDocument& root() const {
    return root_;
  }
  void setRoot(const ElementOrDocument&);
  void setRootToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasRootNonNull() const { return !root_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasRootNonNull| in advance to check the condition.
  const ElementOrDocument& rootNonNull() const {
    DCHECK(hasRootNonNull());
    return root_;
  }

  bool hasRootMargin() const { return !root_margin_.IsNull(); }
  const String& rootMargin() const {
    return root_margin_;
  }
  inline void setRootMargin(const String&);

  bool hasThreshold() const { return !threshold_.IsNull(); }
  const DoubleOrDoubleSequence& threshold() const {
    return threshold_;
  }
  void setThreshold(const DoubleOrDoubleSequence&);

  bool hasTrackVisibility() const { return has_track_visibility_; }
  bool trackVisibility() const {
    DCHECK(has_track_visibility_);
    return track_visibility_;
  }
  inline void setTrackVisibility(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_delay_ = false;
  bool has_track_visibility_ = false;

  double delay_;
  ElementOrDocument root_;
  String root_margin_;
  DoubleOrDoubleSequence threshold_;
  bool track_visibility_;

  friend class V8IntersectionObserverInit;
};

void IntersectionObserverInit::setDelay(double value) {
  delay_ = value;
  has_delay_ = true;
}

void IntersectionObserverInit::setRootMargin(const String& value) {
  root_margin_ = value;
}

void IntersectionObserverInit::setTrackVisibility(bool value) {
  track_visibility_ = value;
  has_track_visibility_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_INTERSECTION_OBSERVER_INTERSECTION_OBSERVER_INIT_H_
