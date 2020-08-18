// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_DECODER_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_DECODER_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_video_frame_output_callback.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_web_codecs_error_callback.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT VideoDecoderInit : public IDLDictionaryBase {
 public:
  static VideoDecoderInit* Create() { return MakeGarbageCollected<VideoDecoderInit>(); }
  static VideoDecoderInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<VideoDecoderInit>();
  }

  VideoDecoderInit();
  virtual ~VideoDecoderInit();

  bool hasError() const { return !!error_; }
  V8WebCodecsErrorCallback* error() const {
    return error_;
  }
  void setError(V8WebCodecsErrorCallback*);

  bool hasOutput() const { return !!output_; }
  V8VideoFrameOutputCallback* output() const {
    return output_;
  }
  void setOutput(V8VideoFrameOutputCallback*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<V8WebCodecsErrorCallback> error_;
  Member<V8VideoFrameOutputCallback> output_;

  friend class V8VideoDecoderInit;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_VIDEO_DECODER_INIT_H_
