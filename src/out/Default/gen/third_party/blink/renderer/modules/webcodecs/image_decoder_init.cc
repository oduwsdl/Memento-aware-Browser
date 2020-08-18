// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webcodecs/image_decoder_init.h"

#include "third_party/blink/renderer/core/imagebitmap/image_bitmap_options.h"

namespace blink {

ImageDecoderInit::ImageDecoderInit() {
}

ImageDecoderInit::~ImageDecoderInit() = default;

void ImageDecoderInit::setData(const ArrayBufferOrArrayBufferViewOrReadableStream& value) {
  data_ = value;
}

void ImageDecoderInit::setOptions(ImageBitmapOptions* value) {
  options_ = value;
}

void ImageDecoderInit::Trace(Visitor* visitor) const {
  visitor->Trace(data_);
  visitor->Trace(options_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
