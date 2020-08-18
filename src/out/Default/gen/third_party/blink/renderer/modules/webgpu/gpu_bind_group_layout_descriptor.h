// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BIND_GROUP_LAYOUT_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BIND_GROUP_LAYOUT_DESCRIPTOR_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_object_descriptor_base.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class GPUBindGroupLayoutEntry;

class MODULES_EXPORT GPUBindGroupLayoutDescriptor : public GPUObjectDescriptorBase {
 public:
  static GPUBindGroupLayoutDescriptor* Create() { return MakeGarbageCollected<GPUBindGroupLayoutDescriptor>(); }
  static GPUBindGroupLayoutDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUBindGroupLayoutDescriptor>();
  }

  GPUBindGroupLayoutDescriptor();
  virtual ~GPUBindGroupLayoutDescriptor();

  bool hasEntries() const { return has_entries_; }
  const HeapVector<Member<GPUBindGroupLayoutEntry>>& entries() const {
    DCHECK(has_entries_);
    return entries_;
  }
  void setEntries(const HeapVector<Member<GPUBindGroupLayoutEntry>>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_entries_ = false;

  HeapVector<Member<GPUBindGroupLayoutEntry>> entries_;

  friend class V8GPUBindGroupLayoutDescriptor;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BIND_GROUP_LAYOUT_DESCRIPTOR_H_
