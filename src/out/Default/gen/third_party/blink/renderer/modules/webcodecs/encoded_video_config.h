// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_ENCODED_VIDEO_CONFIG_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_ENCODED_VIDEO_CONFIG_H_

#include "third_party/blink/renderer/bindings/core/v8/array_buffer_or_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_typed_array.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT EncodedVideoConfig : public IDLDictionaryBase {
 public:
  static EncodedVideoConfig* Create() { return MakeGarbageCollected<EncodedVideoConfig>(); }
  static EncodedVideoConfig* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<EncodedVideoConfig>();
  }

  EncodedVideoConfig();
  virtual ~EncodedVideoConfig();

  bool hasCodec() const { return !codec_.IsNull(); }
  const String& codec() const {
    return codec_;
  }
  inline void setCodec(const String&);

  bool hasDescription() const { return !description_.IsNull(); }
  const ArrayBufferOrArrayBufferView& description() const {
    return description_;
  }
  void setDescription(const ArrayBufferOrArrayBufferView&);

  bool hasSampleAspect() const { return has_sample_aspect_; }
  double sampleAspect() const {
    DCHECK(has_sample_aspect_);
    return sample_aspect_;
  }
  inline void setSampleAspect(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_sample_aspect_ = false;

  String codec_;
  ArrayBufferOrArrayBufferView description_;
  double sample_aspect_;

  friend class V8EncodedVideoConfig;
};

void EncodedVideoConfig::setCodec(const String& value) {
  codec_ = value;
}

void EncodedVideoConfig::setSampleAspect(double value) {
  sample_aspect_ = value;
  has_sample_aspect_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBCODECS_ENCODED_VIDEO_CONFIG_H_
