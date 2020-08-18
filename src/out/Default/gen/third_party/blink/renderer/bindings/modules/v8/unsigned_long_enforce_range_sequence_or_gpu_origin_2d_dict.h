// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_ENFORCE_RANGE_SEQUENCE_OR_GPU_ORIGIN_2D_DICT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_ENFORCE_RANGE_SEQUENCE_OR_GPU_ORIGIN_2D_DICT_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_origin_2d_dict.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict final {
  DISALLOW_NEW();
 public:
  UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsGPUOrigin2DDict() const { return type_ == SpecificType::kGPUOrigin2DDict; }
  GPUOrigin2DDict* GetAsGPUOrigin2DDict() const;
  void SetGPUOrigin2DDict(GPUOrigin2DDict*);
  static UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict FromGPUOrigin2DDict(GPUOrigin2DDict*);

  bool IsUnsignedLongEnforceRangeSequence() const { return type_ == SpecificType::kUnsignedLongEnforceRangeSequence; }
  const Vector<uint32_t>& GetAsUnsignedLongEnforceRangeSequence() const;
  void SetUnsignedLongEnforceRangeSequence(const Vector<uint32_t>&);
  static UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict FromUnsignedLongEnforceRangeSequence(const Vector<uint32_t>&);

  UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&);
  ~UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict();
  UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& operator=(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kGPUOrigin2DDict,
    kUnsignedLongEnforceRangeSequence,
  };
  SpecificType type_;

  Member<GPUOrigin2DDict> gpu_origin_2d_dict_;
  Vector<uint32_t> unsigned_long_enforce_range_sequence_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict> : public NativeValueTraitsBase<UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict> {
  MODULES_EXPORT static UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict NullValue() { return UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict(); }
};

template <>
struct V8TypeOf<UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict> {
  typedef V8UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_ENFORCE_RANGE_SEQUENCE_OR_GPU_ORIGIN_2D_DICT_H_
