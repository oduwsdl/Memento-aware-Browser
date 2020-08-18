// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_VERTEX_BUFFER_LAYOUT_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_VERTEX_BUFFER_LAYOUT_DESCRIPTOR_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class GPUVertexAttributeDescriptor;

class MODULES_EXPORT GPUVertexBufferLayoutDescriptor : public IDLDictionaryBase {
 public:
  static GPUVertexBufferLayoutDescriptor* Create() { return MakeGarbageCollected<GPUVertexBufferLayoutDescriptor>(); }
  static GPUVertexBufferLayoutDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUVertexBufferLayoutDescriptor>();
  }

  GPUVertexBufferLayoutDescriptor();
  virtual ~GPUVertexBufferLayoutDescriptor();

  bool hasArrayStride() const { return has_array_stride_; }
  uint64_t arrayStride() const {
    DCHECK(has_array_stride_);
    return array_stride_;
  }
  inline void setArrayStride(uint64_t);

  bool hasAttributes() const { return has_attributes_; }
  const HeapVector<Member<GPUVertexAttributeDescriptor>>& attributes() const {
    DCHECK(has_attributes_);
    return attributes_;
  }
  void setAttributes(const HeapVector<Member<GPUVertexAttributeDescriptor>>&);

  bool hasStepMode() const { return !step_mode_.IsNull(); }
  const String& stepMode() const {
    return step_mode_;
  }
  inline void setStepMode(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_array_stride_ = false;
  bool has_attributes_ = false;

  uint64_t array_stride_;
  HeapVector<Member<GPUVertexAttributeDescriptor>> attributes_;
  String step_mode_;

  friend class V8GPUVertexBufferLayoutDescriptor;
};

void GPUVertexBufferLayoutDescriptor::setArrayStride(uint64_t value) {
  array_stride_ = value;
  has_array_stride_ = true;
}

void GPUVertexBufferLayoutDescriptor::setStepMode(const String& value) {
  step_mode_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_VERTEX_BUFFER_LAYOUT_DESCRIPTOR_H_
