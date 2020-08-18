// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SHAPEDETECTION_DETECTED_TEXT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SHAPEDETECTION_DETECTED_TEXT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class DOMRectReadOnly;
class Point2D;

class MODULES_EXPORT DetectedText : public IDLDictionaryBase {
 public:
  static DetectedText* Create() { return MakeGarbageCollected<DetectedText>(); }
  static DetectedText* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<DetectedText>();
  }

  DetectedText();
  virtual ~DetectedText();

  bool hasBoundingBox() const { return !!bounding_box_; }
  DOMRectReadOnly* boundingBox() const {
    return bounding_box_;
  }
  inline void setBoundingBox(DOMRectReadOnly*);

  bool hasCornerPoints() const { return has_corner_points_; }
  const HeapVector<Member<Point2D>>& cornerPoints() const {
    DCHECK(has_corner_points_);
    return corner_points_;
  }
  void setCornerPoints(const HeapVector<Member<Point2D>>&);

  bool hasRawValue() const { return !raw_value_.IsNull(); }
  const String& rawValue() const {
    return raw_value_;
  }
  inline void setRawValue(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_corner_points_ = false;

  Member<DOMRectReadOnly> bounding_box_;
  HeapVector<Member<Point2D>> corner_points_;
  String raw_value_;

  friend class V8DetectedText;
};

void DetectedText::setBoundingBox(DOMRectReadOnly* value) {
  bounding_box_ = value;
}

void DetectedText::setRawValue(const String& value) {
  raw_value_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SHAPEDETECTION_DETECTED_TEXT_H_
