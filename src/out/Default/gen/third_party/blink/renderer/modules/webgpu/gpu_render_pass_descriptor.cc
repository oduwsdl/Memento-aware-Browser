// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_render_pass_descriptor.h"

#include "third_party/blink/renderer/modules/webgpu/gpu_render_pass_color_attachment_descriptor.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_render_pass_depth_stencil_attachment_descriptor.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

GPURenderPassDescriptor::GPURenderPassDescriptor() {
}

GPURenderPassDescriptor::~GPURenderPassDescriptor() = default;

void GPURenderPassDescriptor::setColorAttachments(const HeapVector<Member<GPURenderPassColorAttachmentDescriptor>>& value) {
  color_attachments_ = value;
  has_color_attachments_ = true;
}

void GPURenderPassDescriptor::setDepthStencilAttachment(GPURenderPassDepthStencilAttachmentDescriptor* value) {
  depth_stencil_attachment_ = value;
}

void GPURenderPassDescriptor::Trace(Visitor* visitor) const {
  visitor->Trace(color_attachments_);
  visitor->Trace(depth_stencil_attachment_);
  GPUObjectDescriptorBase::Trace(visitor);
}

}  // namespace blink
