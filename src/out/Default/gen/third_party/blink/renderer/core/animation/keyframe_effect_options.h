// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_KEYFRAME_EFFECT_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_KEYFRAME_EFFECT_OPTIONS_H_

#include "third_party/blink/renderer/core/animation/effect_timing.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT KeyframeEffectOptions : public EffectTiming {
 public:
  static KeyframeEffectOptions* Create() { return MakeGarbageCollected<KeyframeEffectOptions>(); }
  static KeyframeEffectOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<KeyframeEffectOptions>();
  }

  KeyframeEffectOptions();
  virtual ~KeyframeEffectOptions();

  bool hasComposite() const { return !composite_.IsNull(); }
  const String& composite() const {
    return composite_;
  }
  inline void setComposite(const String&);

  bool hasPseudoElement() const { return !pseudo_element_.IsNull(); }
  const String& pseudoElement() const {
    return pseudo_element_;
  }
  inline void setPseudoElement(const String&);
  inline void setPseudoElementToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasPseudoElementNonNull() const { return !pseudo_element_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasPseudoElementNonNull| in advance to check the condition.
  const String& pseudoElementNonNull() const {
    DCHECK(hasPseudoElementNonNull());
    return pseudo_element_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String composite_;
  String pseudo_element_;

  friend class V8KeyframeEffectOptions;
};

void KeyframeEffectOptions::setComposite(const String& value) {
  composite_ = value;
}

void KeyframeEffectOptions::setPseudoElement(const String& value) {
  pseudo_element_ = value;
}

void KeyframeEffectOptions::setPseudoElementToNull() {
  pseudo_element_ = String();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_ANIMATION_KEYFRAME_EFFECT_OPTIONS_H_
