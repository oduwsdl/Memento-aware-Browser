// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_delegated_ink_trail_presenter.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_pointer_event.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_ink_trail_style.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
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
const WrapperTypeInfo v8_delegated_ink_trail_presenter_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8DelegatedInkTrailPresenter::DomTemplate,
    nullptr,
    "DelegatedInkTrailPresenter",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DelegatedInkTrailPresenter.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& DelegatedInkTrailPresenter::wrapper_type_info_ = v8_delegated_ink_trail_presenter_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DelegatedInkTrailPresenter>::value,
    "DelegatedInkTrailPresenter inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DelegatedInkTrailPresenter::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "DelegatedInkTrailPresenter is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace delegated_ink_trail_presenter_v8_internal {

static void PresentationAreaAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DelegatedInkTrailPresenter* impl = V8DelegatedInkTrailPresenter::ToImpl(holder);

  V8SetReturnValueFast(info, WTF::GetPtr(impl->presentationArea()), impl);
}

static void ExpectedImprovementAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DelegatedInkTrailPresenter* impl = V8DelegatedInkTrailPresenter::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->expectedImprovement());
}

static void UpdateInkTrailStartPointMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "DelegatedInkTrailPresenter", "updateInkTrailStartPoint");

  DelegatedInkTrailPresenter* impl = V8DelegatedInkTrailPresenter::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  PointerEvent* evt;
  InkTrailStyle* style;
  evt = V8PointerEvent::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!evt) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "PointerEvent"));
    return;
  }

  if (!info[1]->IsNullOrUndefined() && !info[1]->IsObject()) {
    exception_state.ThrowTypeError("parameter 2 ('style') is not an object.");
    return;
  }
  style = NativeValueTraits<InkTrailStyle>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->updateInkTrailStartPoint(script_state, evt, style);
}

}  // namespace delegated_ink_trail_presenter_v8_internal

void V8DelegatedInkTrailPresenter::PresentationAreaAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DelegatedInkTrailPresenter_presentationArea_Getter");

  delegated_ink_trail_presenter_v8_internal::PresentationAreaAttributeGetter(info);
}

void V8DelegatedInkTrailPresenter::ExpectedImprovementAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DelegatedInkTrailPresenter_expectedImprovement_Getter");

  delegated_ink_trail_presenter_v8_internal::ExpectedImprovementAttributeGetter(info);
}

void V8DelegatedInkTrailPresenter::UpdateInkTrailStartPointMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("DelegatedInkTrailPresenter.updateInkTrailStartPoint");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DelegatedInkTrailPresenter_updateInkTrailStartPoint");

  delegated_ink_trail_presenter_v8_internal::UpdateInkTrailStartPointMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8DelegatedInkTrailPresenterMethods[] = {
    {"updateInkTrailStartPoint", V8DelegatedInkTrailPresenter::UpdateInkTrailStartPointMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8DelegatedInkTrailPresenterTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8DelegatedInkTrailPresenter::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8DelegatedInkTrailPresenter::kInternalFieldCount);

  if (!RuntimeEnabledFeatures::DelegatedInkTrailsEnabled()) {
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
      { "presentationArea", V8DelegatedInkTrailPresenter::PresentationAreaAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "expectedImprovement", V8DelegatedInkTrailPresenter::ExpectedImprovementAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8DelegatedInkTrailPresenterMethods, base::size(kV8DelegatedInkTrailPresenterMethods));

  // Custom signature

  V8DelegatedInkTrailPresenter::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8DelegatedInkTrailPresenter::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  if (!RuntimeEnabledFeatures::DelegatedInkTrailsEnabled()) {
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

v8::Local<v8::FunctionTemplate> V8DelegatedInkTrailPresenter::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8DelegatedInkTrailPresenter::GetWrapperTypeInfo()),
      InstallV8DelegatedInkTrailPresenterTemplate);
}

bool V8DelegatedInkTrailPresenter::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8DelegatedInkTrailPresenter::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8DelegatedInkTrailPresenter::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8DelegatedInkTrailPresenter::GetWrapperTypeInfo(), v8_value);
}

DelegatedInkTrailPresenter* V8DelegatedInkTrailPresenter::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
