// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_GPU_BUFFER_OR_ARRAY_BUFFER_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_GPU_BUFFER_OR_ARRAY_BUFFER_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class DOMArrayBuffer;
class GPUBuffer;

class MODULES_EXPORT GPUBufferOrArrayBuffer final {
  DISALLOW_NEW();
 public:
  GPUBufferOrArrayBuffer();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsArrayBuffer() const { return type_ == SpecificType::kArrayBuffer; }
  DOMArrayBuffer* GetAsArrayBuffer() const;
  void SetArrayBuffer(DOMArrayBuffer*);
  static GPUBufferOrArrayBuffer FromArrayBuffer(DOMArrayBuffer*);

  bool IsGPUBuffer() const { return type_ == SpecificType::kGPUBuffer; }
  GPUBuffer* GetAsGPUBuffer() const;
  void SetGPUBuffer(GPUBuffer*);
  static GPUBufferOrArrayBuffer FromGPUBuffer(GPUBuffer*);

  GPUBufferOrArrayBuffer(const GPUBufferOrArrayBuffer&);
  ~GPUBufferOrArrayBuffer();
  GPUBufferOrArrayBuffer& operator=(const GPUBufferOrArrayBuffer&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kArrayBuffer,
    kGPUBuffer,
  };
  SpecificType type_;

  Member<DOMArrayBuffer> array_buffer_;
  Member<GPUBuffer> gpu_buffer_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const GPUBufferOrArrayBuffer&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8GPUBufferOrArrayBuffer final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, GPUBufferOrArrayBuffer&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const GPUBufferOrArrayBuffer&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, GPUBufferOrArrayBuffer& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, GPUBufferOrArrayBuffer& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<GPUBufferOrArrayBuffer> : public NativeValueTraitsBase<GPUBufferOrArrayBuffer> {
  MODULES_EXPORT static GPUBufferOrArrayBuffer NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static GPUBufferOrArrayBuffer NullValue() { return GPUBufferOrArrayBuffer(); }
};

template <>
struct V8TypeOf<GPUBufferOrArrayBuffer> {
  typedef V8GPUBufferOrArrayBuffer Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::GPUBufferOrArrayBuffer)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_GPU_BUFFER_OR_ARRAY_BUFFER_H_
