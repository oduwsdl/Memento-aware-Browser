// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PASS_DEPTH_STENCIL_ATTACHMENT_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PASS_DEPTH_STENCIL_ATTACHMENT_DESCRIPTOR_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/modules/v8/gpu_load_op_or_float.h"
#include "third_party/blink/renderer/bindings/modules/v8/gpu_load_op_or_unsigned_long_enforce_range.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class GPUTextureView;

class MODULES_EXPORT GPURenderPassDepthStencilAttachmentDescriptor : public IDLDictionaryBase {
 public:
  static GPURenderPassDepthStencilAttachmentDescriptor* Create() { return MakeGarbageCollected<GPURenderPassDepthStencilAttachmentDescriptor>(); }
  static GPURenderPassDepthStencilAttachmentDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPURenderPassDepthStencilAttachmentDescriptor>();
  }

  GPURenderPassDepthStencilAttachmentDescriptor();
  virtual ~GPURenderPassDepthStencilAttachmentDescriptor();

  bool hasAttachment() const { return !!attachment_; }
  GPUTextureView* attachment() const {
    return attachment_;
  }
  inline void setAttachment(GPUTextureView*);

  bool hasDepthLoadValue() const { return !depth_load_value_.IsNull(); }
  const GPULoadOpOrFloat& depthLoadValue() const {
    return depth_load_value_;
  }
  void setDepthLoadValue(const GPULoadOpOrFloat&);

  bool hasDepthStoreOp() const { return !depth_store_op_.IsNull(); }
  const String& depthStoreOp() const {
    return depth_store_op_;
  }
  inline void setDepthStoreOp(const String&);

  bool hasStencilLoadValue() const { return !stencil_load_value_.IsNull(); }
  const GPULoadOpOrUnsignedLongEnforceRange& stencilLoadValue() const {
    return stencil_load_value_;
  }
  void setStencilLoadValue(const GPULoadOpOrUnsignedLongEnforceRange&);

  bool hasStencilStoreOp() const { return !stencil_store_op_.IsNull(); }
  const String& stencilStoreOp() const {
    return stencil_store_op_;
  }
  inline void setStencilStoreOp(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<GPUTextureView> attachment_;
  GPULoadOpOrFloat depth_load_value_;
  String depth_store_op_;
  GPULoadOpOrUnsignedLongEnforceRange stencil_load_value_;
  String stencil_store_op_;

  friend class V8GPURenderPassDepthStencilAttachmentDescriptor;
};

void GPURenderPassDepthStencilAttachmentDescriptor::setAttachment(GPUTextureView* value) {
  attachment_ = value;
}

void GPURenderPassDepthStencilAttachmentDescriptor::setDepthStoreOp(const String& value) {
  depth_store_op_ = value;
}

void GPURenderPassDepthStencilAttachmentDescriptor::setStencilStoreOp(const String& value) {
  stencil_store_op_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_RENDER_PASS_DEPTH_STENCIL_ATTACHMENT_DESCRIPTOR_H_
