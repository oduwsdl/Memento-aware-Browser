// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_DEVICE_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_DEVICE_DESCRIPTOR_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_object_descriptor_base.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class GPULimits;

class MODULES_EXPORT GPUDeviceDescriptor : public GPUObjectDescriptorBase {
 public:
  static GPUDeviceDescriptor* Create() { return MakeGarbageCollected<GPUDeviceDescriptor>(); }
  static GPUDeviceDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUDeviceDescriptor>();
  }

  GPUDeviceDescriptor();
  virtual ~GPUDeviceDescriptor();

  bool hasExtensions() const { return has_extensions_; }
  const Vector<String>& extensions() const {
    DCHECK(has_extensions_);
    return extensions_;
  }
  void setExtensions(const Vector<String>&);

  bool hasLimits() const { return !!limits_; }
  GPULimits* limits() const {
    return limits_;
  }
  void setLimits(GPULimits*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_extensions_ = false;

  Vector<String> extensions_;
  Member<GPULimits> limits_;

  friend class V8GPUDeviceDescriptor;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_DEVICE_DESCRIPTOR_H_
