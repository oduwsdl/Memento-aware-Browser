// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_IMAGE_FRAME_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_IMAGE_FRAME_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class ImageBitmap;

class MODULES_EXPORT ImageFrameExternal : public IDLDictionaryBase {
 public:
  static ImageFrameExternal* Create() { return MakeGarbageCollected<ImageFrameExternal>(); }
  static ImageFrameExternal* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ImageFrameExternal>();
  }

  ImageFrameExternal();
  virtual ~ImageFrameExternal();

  bool hasComplete() const { return has_complete_; }
  bool complete() const {
    DCHECK(has_complete_);
    return complete_;
  }
  inline void setComplete(bool);

  bool hasDuration() const { return has_duration_; }
  uint64_t duration() const {
    DCHECK(has_duration_);
    return duration_;
  }
  inline void setDuration(uint64_t);

  bool hasImage() const { return !!image_; }
  ImageBitmap* image() const {
    return image_;
  }
  inline void setImage(ImageBitmap*);

  bool hasOrientation() const { return has_orientation_; }
  uint32_t orientation() const {
    DCHECK(has_orientation_);
    return orientation_;
  }
  inline void setOrientation(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_complete_ = false;
  bool has_duration_ = false;
  bool has_orientation_ = false;

  bool complete_;
  uint64_t duration_;
  Member<ImageBitmap> image_;
  uint32_t orientation_;

  friend class V8ImageFrameExternal;
};

void ImageFrameExternal::setComplete(bool value) {
  complete_ = value;
  has_complete_ = true;
}

void ImageFrameExternal::setDuration(uint64_t value) {
  duration_ = value;
  has_duration_ = true;
}

void ImageFrameExternal::setImage(ImageBitmap* value) {
  image_ = value;
}

void ImageFrameExternal::setOrientation(uint32_t value) {
  orientation_ = value;
  has_orientation_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_IMAGE_FRAME_H_
