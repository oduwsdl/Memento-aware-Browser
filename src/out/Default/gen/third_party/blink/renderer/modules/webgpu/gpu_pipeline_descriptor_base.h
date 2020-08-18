// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_PIPELINE_DESCRIPTOR_BASE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_PIPELINE_DESCRIPTOR_BASE_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_object_descriptor_base.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class GPUPipelineLayout;

class MODULES_EXPORT GPUPipelineDescriptorBase : public GPUObjectDescriptorBase {
 public:
  static GPUPipelineDescriptorBase* Create() { return MakeGarbageCollected<GPUPipelineDescriptorBase>(); }
  static GPUPipelineDescriptorBase* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUPipelineDescriptorBase>();
  }

  GPUPipelineDescriptorBase();
  virtual ~GPUPipelineDescriptorBase();

  bool hasLayout() const { return !!layout_; }
  GPUPipelineLayout* layout() const {
    return layout_;
  }
  inline void setLayout(GPUPipelineLayout*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<GPUPipelineLayout> layout_;

  friend class V8GPUPipelineDescriptorBase;
};

void GPUPipelineDescriptorBase::setLayout(GPUPipelineLayout* value) {
  layout_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_PIPELINE_DESCRIPTOR_BASE_H_
