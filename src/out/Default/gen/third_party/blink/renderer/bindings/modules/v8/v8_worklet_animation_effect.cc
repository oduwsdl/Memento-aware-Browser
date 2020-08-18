// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_worklet_animation_effect.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_computed_effect_timing.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_effect_timing.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/scheduler/public/cooperative_scheduling_manager.h"
#include "third_party/blink/renderer/platform/wtf/get_ptr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo v8_worklet_animation_effect_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8WorkletAnimationEffect::DomTemplate,
    nullptr,
    "WorkletAnimationEffect",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in WorkletAnimationEffect.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& WorkletAnimationEffect::wrapper_type_info_ = v8_worklet_animation_effect_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, WorkletAnimationEffect>::value,
    "WorkletAnimationEffect inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&WorkletAnimationEffect::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "WorkletAnimationEffect is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace worklet_animation_effect_v8_internal {

static void LocalTimeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  WorkletAnimationEffect* impl = V8WorkletAnimationEffect::ToImpl(holder);

  base::Optional<double> cpp_value(impl->localTime());

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, cpp_value.value());
}

static void LocalTimeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  WorkletAnimationEffect* impl = V8WorkletAnimationEffect::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "WorkletAnimationEffect", "localTime");

  bool is_null = IsUndefinedOrNull(v8_value);

  // Prepare the value to be set.
  base::Optional<double> cpp_value = is_null ? base::nullopt : base::Optional<double>(NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), v8_value, exception_state));
  if (exception_state.HadException())
    return;

  impl->setLocalTime(cpp_value);
}

static void GetTimingMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  WorkletAnimationEffect* impl = V8WorkletAnimationEffect::ToImpl(info.Holder());

  EffectTiming* result = impl->getTiming();
  V8SetReturnValue(info, result);
}

static void GetComputedTimingMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  WorkletAnimationEffect* impl = V8WorkletAnimationEffect::ToImpl(info.Holder());

  ComputedEffectTiming* result = impl->getComputedTiming();
  V8SetReturnValue(info, result);
}

}  // namespace worklet_animation_effect_v8_internal

void V8WorkletAnimationEffect::LocalTimeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_WorkletAnimationEffect_localTime_Getter");

  worklet_animation_effect_v8_internal::LocalTimeAttributeGetter(info);
}

void V8WorkletAnimationEffect::LocalTimeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_WorkletAnimationEffect_localTime_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  worklet_animation_effect_v8_internal::LocalTimeAttributeSetter(v8_value, info);
}

void V8WorkletAnimationEffect::GetTimingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("WorkletAnimationEffect.getTiming");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_WorkletAnimationEffect_getTiming");

  worklet_animation_effect_v8_internal::GetTimingMethod(info);
}

void V8WorkletAnimationEffect::GetComputedTimingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("WorkletAnimationEffect.getComputedTiming");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_WorkletAnimationEffect_getComputedTiming");

  worklet_animation_effect_v8_internal::GetComputedTimingMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8WorkletAnimationEffectMethods[] = {
    {"getTiming", V8WorkletAnimationEffect::GetTimingMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"getComputedTiming", V8WorkletAnimationEffect::GetComputedTimingMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8WorkletAnimationEffectTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8WorkletAnimationEffect::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8WorkletAnimationEffect::kInternalFieldCount);

  if (!RuntimeEnabledFeatures::AnimationWorkletEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "localTime", V8WorkletAnimationEffect::LocalTimeAttributeGetterCallback, V8WorkletAnimationEffect::LocalTimeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8WorkletAnimationEffectMethods, base::size(kV8WorkletAnimationEffectMethods));

  // Custom signature

  V8WorkletAnimationEffect::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8WorkletAnimationEffect::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  if (!RuntimeEnabledFeatures::AnimationWorkletEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  // Custom signature
}

v8::Local<v8::FunctionTemplate> V8WorkletAnimationEffect::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8WorkletAnimationEffect::GetWrapperTypeInfo()),
      InstallV8WorkletAnimationEffectTemplate);
}

bool V8WorkletAnimationEffect::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8WorkletAnimationEffect::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8WorkletAnimationEffect::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8WorkletAnimationEffect::GetWrapperTypeInfo(), v8_value);
}

WorkletAnimationEffect* V8WorkletAnimationEffect::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
