// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_FRAME_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_FRAME_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT VideoFrameInit : public IDLDictionaryBase {
 public:
  static VideoFrameInit* Create() { return MakeGarbageCollected<VideoFrameInit>(); }
  static VideoFrameInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<VideoFrameInit>();
  }

  VideoFrameInit();
  virtual ~VideoFrameInit();

  bool hasDuration() const { return has_duration_; }
  uint64_t duration() const {
    DCHECK(has_duration_);
    return duration_;
  }
  inline void setDuration(uint64_t);
  inline void setDurationToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasDurationNonNull() const { return has_duration_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasDurationNonNull| in advance to check the condition.
  uint64_t durationNonNull() const {
    DCHECK(hasDurationNonNull());
    return duration_;
  }

  bool hasTimestamp() const { return has_timestamp_; }
  uint64_t timestamp() const {
    DCHECK(has_timestamp_);
    return timestamp_;
  }
  inline void setTimestamp(uint64_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_duration_ = false;
  bool has_timestamp_ = false;

  uint64_t duration_;
  uint64_t timestamp_;

  friend class V8VideoFrameInit;
};

void VideoFrameInit::setDuration(uint64_t value) {
  duration_ = value;
  has_duration_ = true;
}

void VideoFrameInit::setDurationToNull() {
  has_duration_ = false;
}

void VideoFrameInit::setTimestamp(uint64_t value) {
  timestamp_ = value;
  has_timestamp_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_FRAME_INIT_H_
