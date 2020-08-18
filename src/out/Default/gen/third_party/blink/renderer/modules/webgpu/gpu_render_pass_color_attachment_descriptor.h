// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PASS_COLOR_ATTACHMENT_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PASS_COLOR_ATTACHMENT_DESCRIPTOR_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/modules/v8/gpu_load_op_or_double_sequence_or_gpu_color_dict.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_color_dict.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class GPUTextureView;

class MODULES_EXPORT GPURenderPassColorAttachmentDescriptor : public IDLDictionaryBase {
 public:
  static GPURenderPassColorAttachmentDescriptor* Create() { return MakeGarbageCollected<GPURenderPassColorAttachmentDescriptor>(); }
  static GPURenderPassColorAttachmentDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPURenderPassColorAttachmentDescriptor>();
  }

  GPURenderPassColorAttachmentDescriptor();
  virtual ~GPURenderPassColorAttachmentDescriptor();

  bool hasAttachment() const { return !!attachment_; }
  GPUTextureView* attachment() const {
    return attachment_;
  }
  inline void setAttachment(GPUTextureView*);

  bool hasLoadValue() const { return !load_value_.IsNull(); }
  const GPULoadOpOrDoubleSequenceOrGPUColorDict& loadValue() const {
    return load_value_;
  }
  void setLoadValue(const GPULoadOpOrDoubleSequenceOrGPUColorDict&);

  bool hasResolveTarget() const { return !!resolve_target_; }
  GPUTextureView* resolveTarget() const {
    return resolve_target_;
  }
  inline void setResolveTarget(GPUTextureView*);

  bool hasStoreOp() const { return !store_op_.IsNull(); }
  const String& storeOp() const {
    return store_op_;
  }
  inline void setStoreOp(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<GPUTextureView> attachment_;
  GPULoadOpOrDoubleSequenceOrGPUColorDict load_value_;
  Member<GPUTextureView> resolve_target_;
  String store_op_;

  friend class V8GPURenderPassColorAttachmentDescriptor;
};

void GPURenderPassColorAttachmentDescriptor::setAttachment(GPUTextureView* value) {
  attachment_ = value;
}

void GPURenderPassColorAttachmentDescriptor::setResolveTarget(GPUTextureView* value) {
  resolve_target_ = value;
}

void GPURenderPassColorAttachmentDescriptor::setStoreOp(const String& value) {
  store_op_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PASS_COLOR_ATTACHMENT_DESCRIPTOR_H_
