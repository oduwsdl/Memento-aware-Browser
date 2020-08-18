// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_TRACK_WRITER_PARAMETERS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_TRACK_WRITER_PARAMETERS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT VideoTrackWriterParameters : public IDLDictionaryBase {
 public:
  static VideoTrackWriterParameters* Create() { return MakeGarbageCollected<VideoTrackWriterParameters>(); }
  static VideoTrackWriterParameters* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<VideoTrackWriterParameters>();
  }

  VideoTrackWriterParameters();
  virtual ~VideoTrackWriterParameters();

  bool hasReleaseFrames() const { return has_release_frames_; }
  bool releaseFrames() const {
    DCHECK(has_release_frames_);
    return release_frames_;
  }
  inline void setReleaseFrames(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_release_frames_ = false;

  bool release_frames_;

  friend class V8VideoTrackWriterParameters;
};

void VideoTrackWriterParameters::setReleaseFrames(bool value) {
  release_frames_ = value;
  has_release_frames_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_TRACK_WRITER_PARAMETERS_H_
