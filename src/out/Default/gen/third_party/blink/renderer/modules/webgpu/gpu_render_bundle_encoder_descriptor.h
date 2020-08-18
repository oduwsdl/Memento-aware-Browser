// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_BUNDLE_ENCODER_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_BUNDLE_ENCODER_DESCRIPTOR_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_object_descriptor_base.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class MODULES_EXPORT GPURenderBundleEncoderDescriptor : public GPUObjectDescriptorBase {
 public:
  static GPURenderBundleEncoderDescriptor* Create() { return MakeGarbageCollected<GPURenderBundleEncoderDescriptor>(); }
  static GPURenderBundleEncoderDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPURenderBundleEncoderDescriptor>();
  }

  GPURenderBundleEncoderDescriptor();
  virtual ~GPURenderBundleEncoderDescriptor();

  bool hasColorFormats() const { return has_color_formats_; }
  const Vector<String>& colorFormats() const {
    DCHECK(has_color_formats_);
    return color_formats_;
  }
  void setColorFormats(const Vector<String>&);

  bool hasDepthStencilFormat() const { return !depth_stencil_format_.IsNull(); }
  const String& depthStencilFormat() const {
    return depth_stencil_format_;
  }
  inline void setDepthStencilFormat(const String&);

  bool hasSampleCount() const { return has_sample_count_; }
  uint32_t sampleCount() const {
    DCHECK(has_sample_count_);
    return sample_count_;
  }
  inline void setSampleCount(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_color_formats_ = false;
  bool has_sample_count_ = false;

  Vector<String> color_formats_;
  String depth_stencil_format_;
  uint32_t sample_count_;

  friend class V8GPURenderBundleEncoderDescriptor;
};

void GPURenderBundleEncoderDescriptor::setDepthStencilFormat(const String& value) {
  depth_stencil_format_ = value;
}

void GPURenderBundleEncoderDescriptor::setSampleCount(uint32_t value) {
  sample_count_ = value;
  has_sample_count_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_BUNDLE_ENCODER_DESCRIPTOR_H_
