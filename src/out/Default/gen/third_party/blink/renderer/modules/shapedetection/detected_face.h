// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SHAPEDETECTION_DETECTED_FACE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SHAPEDETECTION_DETECTED_FACE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class Landmark;
class DOMRectReadOnly;

class MODULES_EXPORT DetectedFace : public IDLDictionaryBase {
 public:
  static DetectedFace* Create() { return MakeGarbageCollected<DetectedFace>(); }
  static DetectedFace* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<DetectedFace>();
  }

  DetectedFace();
  virtual ~DetectedFace();

  bool hasBoundingBox() const { return !!bounding_box_; }
  DOMRectReadOnly* boundingBox() const {
    return bounding_box_;
  }
  inline void setBoundingBox(DOMRectReadOnly*);

  bool hasLandmarks() const { return has_landmarks_; }
  const HeapVector<Member<Landmark>>& landmarks() const {
    DCHECK(has_landmarks_);
    return landmarks_;
  }
  void setLandmarks(const HeapVector<Member<Landmark>>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_landmarks_ = false;

  Member<DOMRectReadOnly> bounding_box_;
  HeapVector<Member<Landmark>> landmarks_;

  friend class V8DetectedFace;
};

void DetectedFace::setBoundingBox(DOMRectReadOnly* value) {
  bounding_box_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SHAPEDETECTION_DETECTED_FACE_H_
