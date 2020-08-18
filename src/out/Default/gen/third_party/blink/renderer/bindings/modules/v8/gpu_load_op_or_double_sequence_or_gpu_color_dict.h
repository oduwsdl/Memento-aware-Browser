// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_GPU_LOAD_OP_OR_DOUBLE_SEQUENCE_OR_GPU_COLOR_DICT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_GPU_LOAD_OP_OR_DOUBLE_SEQUENCE_OR_GPU_COLOR_DICT_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_color_dict.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT GPULoadOpOrDoubleSequenceOrGPUColorDict final {
  DISALLOW_NEW();
 public:
  GPULoadOpOrDoubleSequenceOrGPUColorDict();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsDoubleSequence() const { return type_ == SpecificType::kDoubleSequence; }
  const Vector<double>& GetAsDoubleSequence() const;
  void SetDoubleSequence(const Vector<double>&);
  static GPULoadOpOrDoubleSequenceOrGPUColorDict FromDoubleSequence(const Vector<double>&);

  bool IsGPUColorDict() const { return type_ == SpecificType::kGPUColorDict; }
  GPUColorDict* GetAsGPUColorDict() const;
  void SetGPUColorDict(GPUColorDict*);
  static GPULoadOpOrDoubleSequenceOrGPUColorDict FromGPUColorDict(GPUColorDict*);

  bool IsGPULoadOp() const { return type_ == SpecificType::kGPULoadOp; }
  const String& GetAsGPULoadOp() const;
  void SetGPULoadOp(const String&);
  static GPULoadOpOrDoubleSequenceOrGPUColorDict FromGPULoadOp(const String&);

  GPULoadOpOrDoubleSequenceOrGPUColorDict(const GPULoadOpOrDoubleSequenceOrGPUColorDict&);
  ~GPULoadOpOrDoubleSequenceOrGPUColorDict();
  GPULoadOpOrDoubleSequenceOrGPUColorDict& operator=(const GPULoadOpOrDoubleSequenceOrGPUColorDict&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kDoubleSequence,
    kGPUColorDict,
    kGPULoadOp,
  };
  SpecificType type_;

  Vector<double> double_sequence_;
  Member<GPUColorDict> gpu_color_dict_;
  String gpu_load_op_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const GPULoadOpOrDoubleSequenceOrGPUColorDict&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8GPULoadOpOrDoubleSequenceOrGPUColorDict final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, GPULoadOpOrDoubleSequenceOrGPUColorDict&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const GPULoadOpOrDoubleSequenceOrGPUColorDict&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, GPULoadOpOrDoubleSequenceOrGPUColorDict& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, GPULoadOpOrDoubleSequenceOrGPUColorDict& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<GPULoadOpOrDoubleSequenceOrGPUColorDict> : public NativeValueTraitsBase<GPULoadOpOrDoubleSequenceOrGPUColorDict> {
  MODULES_EXPORT static GPULoadOpOrDoubleSequenceOrGPUColorDict NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static GPULoadOpOrDoubleSequenceOrGPUColorDict NullValue() { return GPULoadOpOrDoubleSequenceOrGPUColorDict(); }
};

template <>
struct V8TypeOf<GPULoadOpOrDoubleSequenceOrGPUColorDict> {
  typedef V8GPULoadOpOrDoubleSequenceOrGPUColorDict Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::GPULoadOpOrDoubleSequenceOrGPUColorDict)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_GPU_LOAD_OP_OR_DOUBLE_SEQUENCE_OR_GPU_COLOR_DICT_H_
