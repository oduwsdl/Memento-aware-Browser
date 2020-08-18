// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_DELEGATED_INK_INK_TRAIL_STYLE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_DELEGATED_INK_INK_TRAIL_STYLE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT InkTrailStyle : public IDLDictionaryBase {
 public:
  static InkTrailStyle* Create() { return MakeGarbageCollected<InkTrailStyle>(); }
  static InkTrailStyle* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<InkTrailStyle>();
  }

  InkTrailStyle();
  virtual ~InkTrailStyle();

  bool hasColor() const { return !color_.IsNull(); }
  const String& color() const {
    return color_;
  }
  inline void setColor(const String&);

  bool hasDiameter() const { return has_diameter_; }
  double diameter() const {
    DCHECK(has_diameter_);
    return diameter_;
  }
  inline void setDiameter(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_diameter_ = false;

  String color_;
  double diameter_;

  friend class V8InkTrailStyle;
};

void InkTrailStyle::setColor(const String& value) {
  color_ = value;
}

void InkTrailStyle::setDiameter(double value) {
  diameter_ = value;
  has_diameter_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_DELEGATED_INK_INK_TRAIL_STYLE_H_
