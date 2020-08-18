// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_screen.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/dactyloscoper.h"
#include "third_party/blink/renderer/core/frame/web_feature.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
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
WrapperTypeInfo v8_screen_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8Screen::DomTemplate,
    nullptr,
    "Screen",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in Screen.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& Screen::wrapper_type_info_ = v8_screen_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, Screen>::value,
    "Screen inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&Screen::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "Screen is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace screen_v8_internal {

static void AvailWidthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->availWidth());
}

static void AvailHeightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->availHeight());
}

static void WidthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->width());
}

static void HeightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->height());
}

static void ColorDepthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->colorDepth());
}

static void PixelDepthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->pixelDepth());
}

static void AvailLeftAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->availLeft());
}

static void AvailTopAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->availTop());
}

static void LeftAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->left());
}

static void TopAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueInt(info, impl->top());
}

static void InternalAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueBool(info, impl->internal());
}

static void PrimaryAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueBool(info, impl->primary());
}

static void ScaleFactorAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValue(info, impl->scaleFactor());
}

static void IdAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueString(info, impl->id(), info.GetIsolate());
}

static void TouchSupportAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Screen* impl = V8Screen::ToImpl(holder);

  V8SetReturnValueBool(info, impl->touchSupport());
}

}  // namespace screen_v8_internal

void V8Screen::AvailWidthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_availWidth_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_AvailWidth_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_AvailWidth_AttributeGetter);

  screen_v8_internal::AvailWidthAttributeGetter(info);
}

void V8Screen::AvailHeightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_availHeight_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_AvailHeight_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_AvailHeight_AttributeGetter);

  screen_v8_internal::AvailHeightAttributeGetter(info);
}

void V8Screen::WidthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_width_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_Width_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_Width_AttributeGetter);

  screen_v8_internal::WidthAttributeGetter(info);
}

void V8Screen::HeightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_height_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_Height_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_Height_AttributeGetter);

  screen_v8_internal::HeightAttributeGetter(info);
}

void V8Screen::ColorDepthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_colorDepth_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_ColorDepth_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_ColorDepth_AttributeGetter);

  screen_v8_internal::ColorDepthAttributeGetter(info);
}

void V8Screen::PixelDepthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_pixelDepth_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_PixelDepth_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_PixelDepth_AttributeGetter);

  screen_v8_internal::PixelDepthAttributeGetter(info);
}

void V8Screen::AvailLeftAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_availLeft_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_AvailLeft_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_AvailLeft_AttributeGetter);

  screen_v8_internal::AvailLeftAttributeGetter(info);
}

void V8Screen::AvailTopAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_availTop_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kV8Screen_AvailTop_AttributeGetter);
  Dactyloscoper::Record(execution_context_for_measurement, WebFeature::kV8Screen_AvailTop_AttributeGetter);

  screen_v8_internal::AvailTopAttributeGetter(info);
}

void V8Screen::LeftAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_left_Getter");

  screen_v8_internal::LeftAttributeGetter(info);
}

void V8Screen::TopAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_top_Getter");

  screen_v8_internal::TopAttributeGetter(info);
}

void V8Screen::InternalAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_internal_Getter");

  screen_v8_internal::InternalAttributeGetter(info);
}

void V8Screen::PrimaryAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_primary_Getter");

  screen_v8_internal::PrimaryAttributeGetter(info);
}

void V8Screen::ScaleFactorAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_scaleFactor_Getter");

  screen_v8_internal::ScaleFactorAttributeGetter(info);
}

void V8Screen::IdAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_id_Getter");

  screen_v8_internal::IdAttributeGetter(info);
}

void V8Screen::TouchSupportAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Screen_touchSupport_Getter");

  screen_v8_internal::TouchSupportAttributeGetter(info);
}

void V8Screen::InstallV8ScreenTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8Screen::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8Screen::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "availWidth", V8Screen::AvailWidthAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "availHeight", V8Screen::AvailHeightAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "width", V8Screen::WidthAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "height", V8Screen::HeightAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "colorDepth", V8Screen::ColorDepthAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pixelDepth", V8Screen::PixelDepthAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "availLeft", V8Screen::AvailLeftAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "availTop", V8Screen::AvailTopAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));

  // Custom signature
}

void V8Screen::InstallRuntimeEnabledFeaturesOnTemplate(
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

  if (RuntimeEnabledFeatures::WindowPlacementEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "id", V8Screen::IdAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "internal", V8Screen::InternalAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "left", V8Screen::LeftAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "primary", V8Screen::PrimaryAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "scaleFactor", V8Screen::ScaleFactorAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "top", V8Screen::TopAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "touchSupport", V8Screen::TouchSupportAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }

  // Custom signature
}

v8::Local<v8::FunctionTemplate> V8Screen::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8Screen::GetWrapperTypeInfo()),
      V8Screen::install_v8_screen_template_function_);
}

bool V8Screen::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8Screen::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8Screen::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8Screen::GetWrapperTypeInfo(), v8_value);
}

Screen* V8Screen::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

InstallRuntimeEnabledFeaturesOnTemplateFunction
V8Screen::install_runtime_enabled_features_on_template_function_ =
    &V8Screen::InstallRuntimeEnabledFeaturesOnTemplate;

InstallTemplateFunction
V8Screen::install_v8_screen_template_function_ =
    &V8Screen::InstallV8ScreenTemplate;

void V8Screen::UpdateWrapperTypeInfo(
    InstallTemplateFunction install_template_function,
    InstallRuntimeEnabledFeaturesFunction install_runtime_enabled_features_function,
    InstallRuntimeEnabledFeaturesOnTemplateFunction install_runtime_enabled_features_on_template_function,
    InstallConditionalFeaturesFunction install_conditional_features_function) {
  V8Screen::install_v8_screen_template_function_ =
      install_template_function;

  CHECK(install_runtime_enabled_features_on_template_function);
  V8Screen::install_runtime_enabled_features_on_template_function_ =
      install_runtime_enabled_features_on_template_function;

  if (install_conditional_features_function) {
    V8Screen::GetWrapperTypeInfo()->install_conditional_features_function =
        install_conditional_features_function;
  }
}

}  // namespace blink
