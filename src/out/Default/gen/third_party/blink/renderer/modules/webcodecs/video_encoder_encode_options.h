// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_ENCODER_ENCODE_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_ENCODER_ENCODE_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT VideoEncoderEncodeOptions : public IDLDictionaryBase {
 public:
  static VideoEncoderEncodeOptions* Create() { return MakeGarbageCollected<VideoEncoderEncodeOptions>(); }
  static VideoEncoderEncodeOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<VideoEncoderEncodeOptions>();
  }

  VideoEncoderEncodeOptions();
  virtual ~VideoEncoderEncodeOptions();

  bool hasKeyFrame() const { return has_key_frame_; }
  bool keyFrame() const {
    DCHECK(has_key_frame_);
    return key_frame_;
  }
  inline void setKeyFrame(bool);
  inline void setKeyFrameToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasKeyFrameNonNull() const { return has_key_frame_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasKeyFrameNonNull| in advance to check the condition.
  bool keyFrameNonNull() const {
    DCHECK(hasKeyFrameNonNull());
    return key_frame_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_key_frame_ = false;

  bool key_frame_;

  friend class V8VideoEncoderEncodeOptions;
};

void VideoEncoderEncodeOptions::setKeyFrame(bool value) {
  key_frame_ = value;
  has_key_frame_ = true;
}

void VideoEncoderEncodeOptions::setKeyFrameToNull() {
  has_key_frame_ = false;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_ENCODER_ENCODE_OPTIONS_H_
