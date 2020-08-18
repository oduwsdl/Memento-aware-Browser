// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webcodecs/video_encoder_init.h"

namespace blink {

VideoEncoderInit::VideoEncoderInit() {
}

VideoEncoderInit::~VideoEncoderInit() = default;

void VideoEncoderInit::setError(V8WebCodecsErrorCallback* value) {
  error_ = value;
}

void VideoEncoderInit::setOutput(V8VideoEncoderOutputCallback* value) {
  output_ = value;
}

void VideoEncoderInit::Trace(Visitor* visitor) const {
  visitor->Trace(error_);
  visitor->Trace(output_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
