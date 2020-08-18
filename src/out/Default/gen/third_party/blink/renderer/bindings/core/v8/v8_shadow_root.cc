// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_shadow_root.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_animation.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_css_style_sheet.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_selection.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_style_sheet_list.h"
#include "third_party/blink/renderer/core/dom/document_or_shadow_root.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/web_feature.h"
#include "third_party/blink/renderer/core/html/custom/ce_reactions_scope.h"
#include "third_party/blink/renderer/core/html/custom/v0_custom_element_processing_stack.h"
#include "third_party/blink/renderer/core/inspector/console_message.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/heap/heap.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
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
WrapperTypeInfo v8_shadow_root_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8ShadowRoot::DomTemplate,
    nullptr,
    "ShadowRoot",
    V8DocumentFragment::GetWrapperTypeInfo(),
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kNodeClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in ShadowRoot.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& ShadowRoot::wrapper_type_info_ = v8_shadow_root_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, ShadowRoot>::value,
    "ShadowRoot inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&ShadowRoot::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "ShadowRoot is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace shadow_root_v8_internal {

static void ModeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueString(info, impl->mode(), info.GetIsolate());
}

static void HostAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueFast(info, WTF::GetPtr(impl->host()), impl);
}

static void InnerHTMLAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueString(info, impl->innerHTML(), info.GetIsolate());
}

static void InnerHTMLAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ShadowRoot", "innerHTML");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  String cpp_value = NativeValueTraits<IDLStringStringContextTrustedHTMLTreatNullAsEmptyString>::NativeValue(info.GetIsolate(), v8_value, exception_state, bindings::ExecutionContextFromV8Wrappable(impl));
  if (exception_state.HadException())
    return;

  impl->setInnerHTML(cpp_value, exception_state);
}

static void DelegatesFocusAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueBool(info, impl->delegatesFocus());
}

static void SlotAssignmentAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueString(info, impl->slotAssignment(), info.GetIsolate());
}

static void ActiveElementAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueFast(info, DocumentOrShadowRoot::activeElement(*impl), impl);
}

static void StyleSheetsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueFast(info, DocumentOrShadowRoot::styleSheets(*impl), impl);
}

static void PointerLockElementAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueFast(info, DocumentOrShadowRoot::pointerLockElement(*impl), impl);
}

static void FullscreenElementAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValueFast(info, DocumentOrShadowRoot::fullscreenElement(*impl), impl);
}

static void AdoptedStyleSheetsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  V8SetReturnValue(info, FreezeV8Object(ToV8(DocumentOrShadowRoot::adoptedStyleSheets(*impl), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void AdoptedStyleSheetsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ShadowRoot* impl = V8ShadowRoot::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ShadowRoot", "adoptedStyleSheets");

  // Prepare the value to be set.
  HeapVector<Member<CSSStyleSheet>> cpp_value = NativeValueTraits<IDLSequence<CSSStyleSheet>>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  DocumentOrShadowRoot::setAdoptedStyleSheets(*impl, cpp_value, exception_state);
}

static void GetSelectionMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ShadowRoot* impl = V8ShadowRoot::ToImpl(info.Holder());

  V8SetReturnValueFast(info, DocumentOrShadowRoot::getSelection(*impl), impl);
}

static void GetAnimationsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ShadowRoot* impl = V8ShadowRoot::ToImpl(info.Holder());

  V8SetReturnValue(info, ToV8(DocumentOrShadowRoot::getAnimations(*impl), info.Holder(), info.GetIsolate()));
}

static void ElementFromPointMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "ShadowRoot", "elementFromPoint");

  ShadowRoot* impl = V8ShadowRoot::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  double x;
  double y;
  x = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  y = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  V8SetReturnValueFast(info, DocumentOrShadowRoot::elementFromPoint(*impl, x, y), impl);
}

static void ElementsFromPointMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "ShadowRoot", "elementsFromPoint");

  ShadowRoot* impl = V8ShadowRoot::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  double x;
  double y;
  x = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  y = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  V8SetReturnValue(info, ToV8(DocumentOrShadowRoot::elementsFromPoint(*impl, x, y), info.Holder(), info.GetIsolate()));
}

}  // namespace shadow_root_v8_internal

void V8ShadowRoot::ModeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_mode_Getter");

  shadow_root_v8_internal::ModeAttributeGetter(info);
}

void V8ShadowRoot::HostAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_host_Getter");

  shadow_root_v8_internal::HostAttributeGetter(info);
}

void V8ShadowRoot::InnerHTMLAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_innerHTML_Getter");

  shadow_root_v8_internal::InnerHTMLAttributeGetter(info);
}

void V8ShadowRoot::InnerHTMLAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_innerHTML_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  shadow_root_v8_internal::InnerHTMLAttributeSetter(v8_value, info);
}

void V8ShadowRoot::DelegatesFocusAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_delegatesFocus_Getter");

  shadow_root_v8_internal::DelegatesFocusAttributeGetter(info);
}

void V8ShadowRoot::SlotAssignmentAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_slotAssignment_Getter");

  shadow_root_v8_internal::SlotAssignmentAttributeGetter(info);
}

void V8ShadowRoot::ActiveElementAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_activeElement_Getter");

  shadow_root_v8_internal::ActiveElementAttributeGetter(info);
}

void V8ShadowRoot::StyleSheetsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_styleSheets_Getter");

  shadow_root_v8_internal::StyleSheetsAttributeGetter(info);
}

void V8ShadowRoot::PointerLockElementAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_pointerLockElement_Getter");

  shadow_root_v8_internal::PointerLockElementAttributeGetter(info);
}

void V8ShadowRoot::FullscreenElementAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_fullscreenElement_Getter");

  shadow_root_v8_internal::FullscreenElementAttributeGetter(info);
}

void V8ShadowRoot::FullscreenElementAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  // Setter for fullscreenElement is no-op because [LenientSetter] is specified.
}

void V8ShadowRoot::AdoptedStyleSheetsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_adoptedStyleSheets_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kAdoptedStyleSheets);

  shadow_root_v8_internal::AdoptedStyleSheetsAttributeGetter(info);
}

void V8ShadowRoot::AdoptedStyleSheetsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_adoptedStyleSheets_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  UseCounter::Count(CurrentExecutionContext(info.GetIsolate()), WebFeature::kAdoptedStyleSheets);

  shadow_root_v8_internal::AdoptedStyleSheetsAttributeSetter(v8_value, info);
}

void V8ShadowRoot::GetSelectionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ShadowRoot.getSelection");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_getSelection");

  shadow_root_v8_internal::GetSelectionMethod(info);
}

void V8ShadowRoot::GetAnimationsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ShadowRoot.getAnimations");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_getAnimations");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8ShadowRoot_GetAnimations_Method);
  shadow_root_v8_internal::GetAnimationsMethod(info);
}

void V8ShadowRoot::ElementFromPointMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ShadowRoot.elementFromPoint");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_elementFromPoint");

  shadow_root_v8_internal::ElementFromPointMethod(info);
}

void V8ShadowRoot::ElementsFromPointMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ShadowRoot.elementsFromPoint");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ShadowRoot_elementsFromPoint");

  shadow_root_v8_internal::ElementsFromPointMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8ShadowRootMethods[] = {
    {"getSelection", V8ShadowRoot::GetSelectionMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasNoSideEffect, V8DOMConfiguration::kAllWorlds},
    {"elementFromPoint", V8ShadowRoot::ElementFromPointMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"elementsFromPoint", V8ShadowRoot::ElementsFromPointMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

void V8ShadowRoot::InstallV8ShadowRootTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8ShadowRoot::GetWrapperTypeInfo()->interface_name, V8DocumentFragment::DomTemplate(isolate, world), V8ShadowRoot::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "mode", V8ShadowRoot::ModeAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "host", V8ShadowRoot::HostAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "innerHTML", V8ShadowRoot::InnerHTMLAttributeGetterCallback, V8ShadowRoot::InnerHTMLAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "delegatesFocus", V8ShadowRoot::DelegatesFocusAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "activeElement", V8ShadowRoot::ActiveElementAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasNoSideEffect, V8DOMConfiguration::kAllWorlds },
      { "styleSheets", V8ShadowRoot::StyleSheetsAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pointerLockElement", V8ShadowRoot::PointerLockElementAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "fullscreenElement", V8ShadowRoot::FullscreenElementAttributeGetterCallback, V8ShadowRoot::FullscreenElementAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "adoptedStyleSheets", V8ShadowRoot::AdoptedStyleSheetsAttributeGetterCallback, V8ShadowRoot::AdoptedStyleSheetsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8ShadowRootMethods, base::size(kV8ShadowRootMethods));

  // Custom signature
}

void V8ShadowRoot::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  if (RuntimeEnabledFeatures::ManualSlottingEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "slotAssignment", V8ShadowRoot::SlotAssignmentAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }

  // Custom signature
  if (RuntimeEnabledFeatures::WebAnimationsAPIEnabled()) {
    {
      // Install getAnimations configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"getAnimations", V8ShadowRoot::GetAnimationsMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
}

v8::Local<v8::FunctionTemplate> V8ShadowRoot::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8ShadowRoot::GetWrapperTypeInfo()),
      V8ShadowRoot::install_v8_shadow_root_template_function_);
}

bool V8ShadowRoot::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8ShadowRoot::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8ShadowRoot::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8ShadowRoot::GetWrapperTypeInfo(), v8_value);
}

ShadowRoot* V8ShadowRoot::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

InstallRuntimeEnabledFeaturesOnTemplateFunction
V8ShadowRoot::install_runtime_enabled_features_on_template_function_ =
    &V8ShadowRoot::InstallRuntimeEnabledFeaturesOnTemplate;

InstallTemplateFunction
V8ShadowRoot::install_v8_shadow_root_template_function_ =
    &V8ShadowRoot::InstallV8ShadowRootTemplate;

void V8ShadowRoot::UpdateWrapperTypeInfo(
    InstallTemplateFunction install_template_function,
    InstallRuntimeEnabledFeaturesFunction install_runtime_enabled_features_function,
    InstallRuntimeEnabledFeaturesOnTemplateFunction install_runtime_enabled_features_on_template_function,
    InstallConditionalFeaturesFunction install_conditional_features_function) {
  V8ShadowRoot::install_v8_shadow_root_template_function_ =
      install_template_function;

  CHECK(install_runtime_enabled_features_on_template_function);
  V8ShadowRoot::install_runtime_enabled_features_on_template_function_ =
      install_runtime_enabled_features_on_template_function;

  if (install_conditional_features_function) {
    V8ShadowRoot::GetWrapperTypeInfo()->install_conditional_features_function =
        install_conditional_features_function;
  }
}

}  // namespace blink
