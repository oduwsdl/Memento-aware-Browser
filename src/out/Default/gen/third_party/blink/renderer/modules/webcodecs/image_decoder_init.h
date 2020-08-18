// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_IMAGE_DECODER_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_IMAGE_DECODER_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/modules/v8/array_buffer_or_array_buffer_view_or_readable_stream.h"
#include "third_party/blink/renderer/core/streams/readable_stream.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_typed_array.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class ImageBitmapOptions;

class MODULES_EXPORT ImageDecoderInit : public IDLDictionaryBase {
 public:
  static ImageDecoderInit* Create() { return MakeGarbageCollected<ImageDecoderInit>(); }
  static ImageDecoderInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ImageDecoderInit>();
  }

  ImageDecoderInit();
  virtual ~ImageDecoderInit();

  bool hasData() const { return !data_.IsNull(); }
  const ArrayBufferOrArrayBufferViewOrReadableStream& data() const {
    return data_;
  }
  void setData(const ArrayBufferOrArrayBufferViewOrReadableStream&);

  bool hasOptions() const { return !!options_; }
  ImageBitmapOptions* options() const {
    return options_;
  }
  void setOptions(ImageBitmapOptions*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  ArrayBufferOrArrayBufferViewOrReadableStream data_;
  Member<ImageBitmapOptions> options_;

  friend class V8ImageDecoderInit;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_IMAGE_DECODER_INIT_H_
