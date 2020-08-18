// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_ENFORCE_RANGE_SEQUENCE_OR_GPU_ORIGIN_3D_DICT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_ENFORCE_RANGE_SEQUENCE_OR_GPU_ORIGIN_3D_DICT_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_origin_3d_dict.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict final {
  DISALLOW_NEW();
 public:
  UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsGPUOrigin3DDict() const { return type_ == SpecificType::kGPUOrigin3DDict; }
  GPUOrigin3DDict* GetAsGPUOrigin3DDict() const;
  void SetGPUOrigin3DDict(GPUOrigin3DDict*);
  static UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict FromGPUOrigin3DDict(GPUOrigin3DDict*);

  bool IsUnsignedLongEnforceRangeSequence() const { return type_ == SpecificType::kUnsignedLongEnforceRangeSequence; }
  const Vector<uint32_t>& GetAsUnsignedLongEnforceRangeSequence() const;
  void SetUnsignedLongEnforceRangeSequence(const Vector<uint32_t>&);
  static UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict FromUnsignedLongEnforceRangeSequence(const Vector<uint32_t>&);

  UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict(const UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict&);
  ~UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict();
  UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict& operator=(const UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kGPUOrigin3DDict,
    kUnsignedLongEnforceRangeSequence,
  };
  SpecificType type_;

  Member<GPUOrigin3DDict> gpu_origin_3d_dict_;
  Vector<uint32_t> unsigned_long_enforce_range_sequence_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict> : public NativeValueTraitsBase<UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict> {
  MODULES_EXPORT static UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict NullValue() { return UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict(); }
};

template <>
struct V8TypeOf<UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict> {
  typedef V8UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_UNSIGNED_LONG_ENFORCE_RANGE_SEQUENCE_OR_GPU_ORIGIN_3D_DICT_H_
