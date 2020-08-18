// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_trusted_type_policy_factory.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_trusted_html.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_trusted_script.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_trusted_type_policy.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_trusted_type_policy_options.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/bindings/v8_private_property.h"
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
const WrapperTypeInfo v8_trusted_type_policy_factory_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8TrustedTypePolicyFactory::DomTemplate,
    nullptr,
    "TrustedTypePolicyFactory",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in TrustedTypePolicyFactory.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& TrustedTypePolicyFactory::wrapper_type_info_ = v8_trusted_type_policy_factory_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, TrustedTypePolicyFactory>::value,
    "TrustedTypePolicyFactory inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&TrustedTypePolicyFactory::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "TrustedTypePolicyFactory is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace trusted_type_policy_factory_v8_internal {

static void DefaultPolicyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(holder);

  TrustedTypePolicy* cpp_value(WTF::GetPtr(impl->defaultPolicy()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void EmptyHTMLAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(holder);

  TrustedHTML* cpp_value(WTF::GetPtr(impl->emptyHTML()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void EmptyScriptAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(holder);

  TrustedScript* cpp_value(WTF::GetPtr(impl->emptyScript()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void CreatePolicyMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "TrustedTypePolicyFactory", "createPolicy");

  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  V8StringResource<> policy_name;
  TrustedTypePolicyOptions* policy_options;
  policy_name = info[0];
  if (!policy_name.Prepare())
    return;

  if (!info[1]->IsNullOrUndefined() && !info[1]->IsObject()) {
    exception_state.ThrowTypeError("parameter 2 ('policyOptions') is not an object.");
    return;
  }
  policy_options = NativeValueTraits<TrustedTypePolicyOptions>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  TrustedTypePolicy* result = impl->createPolicy(policy_name, policy_options, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result);
}

static void IsHTMLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("isHTML", "TrustedTypePolicyFactory", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  ScriptValue checked_object;
  checked_object = ScriptValue(info.GetIsolate(), info[0]);

  bool result = impl->isHTML(script_state, checked_object);
  V8SetReturnValueBool(info, result);
}

static void IsScriptMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("isScript", "TrustedTypePolicyFactory", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  ScriptValue checked_object;
  checked_object = ScriptValue(info.GetIsolate(), info[0]);

  bool result = impl->isScript(script_state, checked_object);
  V8SetReturnValueBool(info, result);
}

static void IsScriptURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("isScriptURL", "TrustedTypePolicyFactory", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  ScriptValue checked_object;
  checked_object = ScriptValue(info.GetIsolate(), info[0]);

  bool result = impl->isScriptURL(script_state, checked_object);
  V8SetReturnValueBool(info, result);
}

static void GetPropertyTypeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("getPropertyType", "TrustedTypePolicyFactory", ExceptionMessages::NotEnoughArguments(2, info.Length())));
    return;
  }

  V8StringResource<> tag_name;
  V8StringResource<> property;
  V8StringResource<> element_ns;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  tag_name = info[0];
  if (!tag_name.Prepare())
    return;

  property = info[1];
  if (!property.Prepare())
    return;

  if (UNLIKELY(num_args_passed <= 2)) {
    V8SetReturnValueStringOrNull(info, impl->getPropertyType(tag_name, property), info.GetIsolate());
    return;
  }
  element_ns = info[2];
  if (!element_ns.Prepare())
    return;

  V8SetReturnValueStringOrNull(info, impl->getPropertyType(tag_name, property, element_ns), info.GetIsolate());
}

static void GetAttributeTypeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("getAttributeType", "TrustedTypePolicyFactory", ExceptionMessages::NotEnoughArguments(2, info.Length())));
    return;
  }

  V8StringResource<> tag_name;
  V8StringResource<> attribute;
  V8StringResource<> element_ns;
  V8StringResource<> attr_ns;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  tag_name = info[0];
  if (!tag_name.Prepare())
    return;

  attribute = info[1];
  if (!attribute.Prepare())
    return;

  if (UNLIKELY(num_args_passed <= 2)) {
    V8SetReturnValueStringOrNull(info, impl->getAttributeType(tag_name, attribute), info.GetIsolate());
    return;
  }
  element_ns = info[2];
  if (!element_ns.Prepare())
    return;

  if (UNLIKELY(num_args_passed <= 3)) {
    V8SetReturnValueStringOrNull(info, impl->getAttributeType(tag_name, attribute, element_ns), info.GetIsolate());
    return;
  }
  attr_ns = info[3];
  if (!attr_ns.Prepare())
    return;

  V8SetReturnValueStringOrNull(info, impl->getAttributeType(tag_name, attribute, element_ns, attr_ns), info.GetIsolate());
}

static void GetTypeMappingMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  TrustedTypePolicyFactory* impl = V8TrustedTypePolicyFactory::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  V8StringResource<> ns;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  if (UNLIKELY(num_args_passed <= 0)) {
    ScriptValue result = impl->getTypeMapping(script_state);
    V8SetReturnValue(info, result.V8Value());
    return;
  }
  ns = info[0];
  if (!ns.Prepare())
    return;

  ScriptValue result = impl->getTypeMapping(script_state, ns);
  V8SetReturnValue(info, result.V8Value());
}

}  // namespace trusted_type_policy_factory_v8_internal

void V8TrustedTypePolicyFactory::DefaultPolicyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_defaultPolicy_Getter");

  trusted_type_policy_factory_v8_internal::DefaultPolicyAttributeGetter(info);
}

void V8TrustedTypePolicyFactory::EmptyHTMLAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_emptyHTML_Getter");

  trusted_type_policy_factory_v8_internal::EmptyHTMLAttributeGetter(info);
}

void V8TrustedTypePolicyFactory::EmptyScriptAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_emptyScript_Getter");

  trusted_type_policy_factory_v8_internal::EmptyScriptAttributeGetter(info);
}

void V8TrustedTypePolicyFactory::CreatePolicyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("TrustedTypePolicyFactory.createPolicy");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_createPolicy");

  trusted_type_policy_factory_v8_internal::CreatePolicyMethod(info);
}

void V8TrustedTypePolicyFactory::IsHTMLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("TrustedTypePolicyFactory.isHTML");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_isHTML");

  trusted_type_policy_factory_v8_internal::IsHTMLMethod(info);
}

void V8TrustedTypePolicyFactory::IsScriptMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("TrustedTypePolicyFactory.isScript");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_isScript");

  trusted_type_policy_factory_v8_internal::IsScriptMethod(info);
}

void V8TrustedTypePolicyFactory::IsScriptURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("TrustedTypePolicyFactory.isScriptURL");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_isScriptURL");

  trusted_type_policy_factory_v8_internal::IsScriptURLMethod(info);
}

void V8TrustedTypePolicyFactory::GetPropertyTypeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("TrustedTypePolicyFactory.getPropertyType");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_getPropertyType");

  trusted_type_policy_factory_v8_internal::GetPropertyTypeMethod(info);
}

void V8TrustedTypePolicyFactory::GetAttributeTypeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("TrustedTypePolicyFactory.getAttributeType");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_getAttributeType");

  trusted_type_policy_factory_v8_internal::GetAttributeTypeMethod(info);
}

void V8TrustedTypePolicyFactory::GetTypeMappingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("TrustedTypePolicyFactory.getTypeMapping");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_TrustedTypePolicyFactory_getTypeMapping");

  trusted_type_policy_factory_v8_internal::GetTypeMappingMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8TrustedTypePolicyFactoryMethods[] = {
    {"createPolicy", V8TrustedTypePolicyFactory::CreatePolicyMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"isHTML", V8TrustedTypePolicyFactory::IsHTMLMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"isScript", V8TrustedTypePolicyFactory::IsScriptMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"isScriptURL", V8TrustedTypePolicyFactory::IsScriptURLMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"getPropertyType", V8TrustedTypePolicyFactory::GetPropertyTypeMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"getAttributeType", V8TrustedTypePolicyFactory::GetAttributeTypeMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"getTypeMapping", V8TrustedTypePolicyFactory::GetTypeMappingMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8TrustedTypePolicyFactoryTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8TrustedTypePolicyFactory::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8TrustedTypePolicyFactory::kInternalFieldCount);

  if (!RuntimeEnabledFeatures::TrustedDOMTypesEnabled()) {
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
      { "defaultPolicy", V8TrustedTypePolicyFactory::DefaultPolicyAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "emptyHTML", V8TrustedTypePolicyFactory::EmptyHTMLAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "emptyScript", V8TrustedTypePolicyFactory::EmptyScriptAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8TrustedTypePolicyFactoryMethods, base::size(kV8TrustedTypePolicyFactoryMethods));

  // Custom signature

  V8TrustedTypePolicyFactory::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8TrustedTypePolicyFactory::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  if (!RuntimeEnabledFeatures::TrustedDOMTypesEnabled()) {
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

v8::Local<v8::FunctionTemplate> V8TrustedTypePolicyFactory::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8TrustedTypePolicyFactory::GetWrapperTypeInfo()),
      InstallV8TrustedTypePolicyFactoryTemplate);
}

bool V8TrustedTypePolicyFactory::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8TrustedTypePolicyFactory::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8TrustedTypePolicyFactory::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8TrustedTypePolicyFactory::GetWrapperTypeInfo(), v8_value);
}

TrustedTypePolicyFactory* V8TrustedTypePolicyFactory::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
