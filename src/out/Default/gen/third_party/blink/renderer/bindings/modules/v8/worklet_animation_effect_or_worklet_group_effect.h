// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_WORKLET_ANIMATION_EFFECT_OR_WORKLET_GROUP_EFFECT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_WORKLET_ANIMATION_EFFECT_OR_WORKLET_GROUP_EFFECT_H_

#include "base/optional.h"
#include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_binding_for_core.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class WorkletAnimationEffect;
class WorkletGroupEffect;

class MODULES_EXPORT WorkletAnimationEffectOrWorkletGroupEffect final {
  DISALLOW_NEW();
 public:
  WorkletAnimationEffectOrWorkletGroupEffect();
  bool IsNull() const { return type_ == SpecificType::kNone; }

  bool IsWorkletAnimationEffect() const { return type_ == SpecificType::kWorkletAnimationEffect; }
  WorkletAnimationEffect* GetAsWorkletAnimationEffect() const;
  void SetWorkletAnimationEffect(WorkletAnimationEffect*);
  static WorkletAnimationEffectOrWorkletGroupEffect FromWorkletAnimationEffect(WorkletAnimationEffect*);

  bool IsWorkletGroupEffect() const { return type_ == SpecificType::kWorkletGroupEffect; }
  WorkletGroupEffect* GetAsWorkletGroupEffect() const;
  void SetWorkletGroupEffect(WorkletGroupEffect*);
  static WorkletAnimationEffectOrWorkletGroupEffect FromWorkletGroupEffect(WorkletGroupEffect*);

  WorkletAnimationEffectOrWorkletGroupEffect(const WorkletAnimationEffectOrWorkletGroupEffect&);
  ~WorkletAnimationEffectOrWorkletGroupEffect();
  WorkletAnimationEffectOrWorkletGroupEffect& operator=(const WorkletAnimationEffectOrWorkletGroupEffect&);
  void Trace(Visitor*) const;

 private:
  enum class SpecificType {
    kNone,
    kWorkletAnimationEffect,
    kWorkletGroupEffect,
  };
  SpecificType type_;

  Member<WorkletAnimationEffect> worklet_animation_effect_;
  Member<WorkletGroupEffect> worklet_group_effect_;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const WorkletAnimationEffectOrWorkletGroupEffect&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8WorkletAnimationEffectOrWorkletGroupEffect final {
 public:
  MODULES_EXPORT static void ToImpl(v8::Isolate*, v8::Local<v8::Value>, WorkletAnimationEffectOrWorkletGroupEffect&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const WorkletAnimationEffectOrWorkletGroupEffect&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, WorkletAnimationEffectOrWorkletGroupEffect& impl) {
  V8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <class CallbackInfo>
inline void V8SetReturnValue(const CallbackInfo& callbackInfo, WorkletAnimationEffectOrWorkletGroupEffect& impl, v8::Local<v8::Object> creationContext) {
  V8SetReturnValue(callbackInfo, ToV8(impl, creationContext, callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<WorkletAnimationEffectOrWorkletGroupEffect> : public NativeValueTraitsBase<WorkletAnimationEffectOrWorkletGroupEffect> {
  MODULES_EXPORT static WorkletAnimationEffectOrWorkletGroupEffect NativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
  MODULES_EXPORT static WorkletAnimationEffectOrWorkletGroupEffect NullValue() { return WorkletAnimationEffectOrWorkletGroupEffect(); }
};

template <>
struct V8TypeOf<WorkletAnimationEffectOrWorkletGroupEffect> {
  typedef V8WorkletAnimationEffectOrWorkletGroupEffect Type;
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::WorkletAnimationEffectOrWorkletGroupEffect)

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_WORKLET_ANIMATION_EFFECT_OR_WORKLET_GROUP_EFFECT_H_
