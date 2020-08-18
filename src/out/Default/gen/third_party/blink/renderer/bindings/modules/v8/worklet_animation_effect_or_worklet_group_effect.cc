// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/worklet_animation_effect_or_worklet_group_effect.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_worklet_animation_effect.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_worklet_group_effect.h"

namespace blink {

WorkletAnimationEffectOrWorkletGroupEffect::WorkletAnimationEffectOrWorkletGroupEffect() : type_(SpecificType::kNone) {}

WorkletAnimationEffect* WorkletAnimationEffectOrWorkletGroupEffect::GetAsWorkletAnimationEffect() const {
  DCHECK(IsWorkletAnimationEffect());
  return worklet_animation_effect_;
}

void WorkletAnimationEffectOrWorkletGroupEffect::SetWorkletAnimationEffect(WorkletAnimationEffect* value) {
  DCHECK(IsNull());
  worklet_animation_effect_ = value;
  type_ = SpecificType::kWorkletAnimationEffect;
}

WorkletAnimationEffectOrWorkletGroupEffect WorkletAnimationEffectOrWorkletGroupEffect::FromWorkletAnimationEffect(WorkletAnimationEffect* value) {
  WorkletAnimationEffectOrWorkletGroupEffect container;
  container.SetWorkletAnimationEffect(value);
  return container;
}

WorkletGroupEffect* WorkletAnimationEffectOrWorkletGroupEffect::GetAsWorkletGroupEffect() const {
  DCHECK(IsWorkletGroupEffect());
  return worklet_group_effect_;
}

void WorkletAnimationEffectOrWorkletGroupEffect::SetWorkletGroupEffect(WorkletGroupEffect* value) {
  DCHECK(IsNull());
  worklet_group_effect_ = value;
  type_ = SpecificType::kWorkletGroupEffect;
}

WorkletAnimationEffectOrWorkletGroupEffect WorkletAnimationEffectOrWorkletGroupEffect::FromWorkletGroupEffect(WorkletGroupEffect* value) {
  WorkletAnimationEffectOrWorkletGroupEffect container;
  container.SetWorkletGroupEffect(value);
  return container;
}

WorkletAnimationEffectOrWorkletGroupEffect::WorkletAnimationEffectOrWorkletGroupEffect(const WorkletAnimationEffectOrWorkletGroupEffect&) = default;
WorkletAnimationEffectOrWorkletGroupEffect::~WorkletAnimationEffectOrWorkletGroupEffect() = default;
WorkletAnimationEffectOrWorkletGroupEffect& WorkletAnimationEffectOrWorkletGroupEffect::operator=(const WorkletAnimationEffectOrWorkletGroupEffect&) = default;

void WorkletAnimationEffectOrWorkletGroupEffect::Trace(Visitor* visitor) const {
  visitor->Trace(worklet_animation_effect_);
  visitor->Trace(worklet_group_effect_);
}

void V8WorkletAnimationEffectOrWorkletGroupEffect::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    WorkletAnimationEffectOrWorkletGroupEffect& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8WorkletAnimationEffect::HasInstance(v8_value, isolate)) {
    WorkletAnimationEffect* cpp_value = V8WorkletAnimationEffect::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetWorkletAnimationEffect(cpp_value);
    return;
  }

  if (V8WorkletGroupEffect::HasInstance(v8_value, isolate)) {
    WorkletGroupEffect* cpp_value = V8WorkletGroupEffect::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetWorkletGroupEffect(cpp_value);
    return;
  }

  exception_state.ThrowTypeError("The provided value is not of type '(WorkletAnimationEffect or WorkletGroupEffect)'");
}

v8::Local<v8::Value> ToV8(const WorkletAnimationEffectOrWorkletGroupEffect& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case WorkletAnimationEffectOrWorkletGroupEffect::SpecificType::kNone:
      return v8::Null(isolate);
    case WorkletAnimationEffectOrWorkletGroupEffect::SpecificType::kWorkletAnimationEffect:
      return ToV8(impl.GetAsWorkletAnimationEffect(), creationContext, isolate);
    case WorkletAnimationEffectOrWorkletGroupEffect::SpecificType::kWorkletGroupEffect:
      return ToV8(impl.GetAsWorkletGroupEffect(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

WorkletAnimationEffectOrWorkletGroupEffect NativeValueTraits<WorkletAnimationEffectOrWorkletGroupEffect>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  WorkletAnimationEffectOrWorkletGroupEffect impl;
  V8WorkletAnimationEffectOrWorkletGroupEffect::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

