// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BUFFER_COPY_VIEW_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BUFFER_COPY_VIEW_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_texture_data_layout.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class GPUBuffer;

class MODULES_EXPORT GPUBufferCopyView : public GPUTextureDataLayout {
 public:
  static GPUBufferCopyView* Create() { return MakeGarbageCollected<GPUBufferCopyView>(); }
  static GPUBufferCopyView* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUBufferCopyView>();
  }

  GPUBufferCopyView();
  virtual ~GPUBufferCopyView();

  bool hasBuffer() const { return !!buffer_; }
  GPUBuffer* buffer() const {
    return buffer_;
  }
  inline void setBuffer(GPUBuffer*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<GPUBuffer> buffer_;

  friend class V8GPUBufferCopyView;
};

void GPUBufferCopyView::setBuffer(GPUBuffer* value) {
  buffer_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BUFFER_COPY_VIEW_H_
