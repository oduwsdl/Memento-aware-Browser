// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_document_policy_violation_report_body.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/scheduler/public/cooperative_scheduling_manager.h"
#include "third_party/blink/renderer/platform/wtf/get_ptr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo v8_document_policy_violation_report_body_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8DocumentPolicyViolationReportBody::DomTemplate,
    nullptr,
    "DocumentPolicyViolationReportBody",
    V8ReportBody::GetWrapperTypeInfo(),
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DocumentPolicyViolationReportBody.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& DocumentPolicyViolationReportBody::wrapper_type_info_ = v8_document_policy_violation_report_body_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DocumentPolicyViolationReportBody>::value,
    "DocumentPolicyViolationReportBody inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DocumentPolicyViolationReportBody::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "DocumentPolicyViolationReportBody is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace document_policy_violation_report_body_v8_internal {

static void FeatureIdAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DocumentPolicyViolationReportBody* impl = V8DocumentPolicyViolationReportBody::ToImpl(holder);

  V8SetReturnValueString(info, impl->featureId(), info.GetIsolate());
}

static void SourceFileAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DocumentPolicyViolationReportBody* impl = V8DocumentPolicyViolationReportBody::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->sourceFile(), info.GetIsolate());
}

static void LineNumberAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DocumentPolicyViolationReportBody* impl = V8DocumentPolicyViolationReportBody::ToImpl(holder);

  base::Optional<uint32_t> cpp_value(impl->lineNumber());

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, cpp_value.value());
}

static void ColumnNumberAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DocumentPolicyViolationReportBody* impl = V8DocumentPolicyViolationReportBody::ToImpl(holder);

  base::Optional<uint32_t> cpp_value(impl->columnNumber());

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, cpp_value.value());
}

static void DispositionAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DocumentPolicyViolationReportBody* impl = V8DocumentPolicyViolationReportBody::ToImpl(holder);

  V8SetReturnValueString(info, impl->disposition(), info.GetIsolate());
}

static void MessageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DocumentPolicyViolationReportBody* impl = V8DocumentPolicyViolationReportBody::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->message(), info.GetIsolate());
}

static void ToJSONMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DocumentPolicyViolationReportBody* impl = V8DocumentPolicyViolationReportBody::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  ScriptValue result = impl->toJSON(script_state);
  V8SetReturnValue(info, result.V8Value());
}

}  // namespace document_policy_violation_report_body_v8_internal

void V8DocumentPolicyViolationReportBody::FeatureIdAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DocumentPolicyViolationReportBody_featureId_Getter");

  document_policy_violation_report_body_v8_internal::FeatureIdAttributeGetter(info);
}

void V8DocumentPolicyViolationReportBody::SourceFileAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DocumentPolicyViolationReportBody_sourceFile_Getter");

  document_policy_violation_report_body_v8_internal::SourceFileAttributeGetter(info);
}

void V8DocumentPolicyViolationReportBody::LineNumberAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DocumentPolicyViolationReportBody_lineNumber_Getter");

  document_policy_violation_report_body_v8_internal::LineNumberAttributeGetter(info);
}

void V8DocumentPolicyViolationReportBody::ColumnNumberAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DocumentPolicyViolationReportBody_columnNumber_Getter");

  document_policy_violation_report_body_v8_internal::ColumnNumberAttributeGetter(info);
}

void V8DocumentPolicyViolationReportBody::DispositionAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DocumentPolicyViolationReportBody_disposition_Getter");

  document_policy_violation_report_body_v8_internal::DispositionAttributeGetter(info);
}

void V8DocumentPolicyViolationReportBody::MessageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DocumentPolicyViolationReportBody_message_Getter");

  document_policy_violation_report_body_v8_internal::MessageAttributeGetter(info);
}

void V8DocumentPolicyViolationReportBody::ToJSONMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("DocumentPolicyViolationReportBody.toJSON");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_DocumentPolicyViolationReportBody_toJSON");

  document_policy_violation_report_body_v8_internal::ToJSONMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8DocumentPolicyViolationReportBodyMethods[] = {
    {"toJSON", V8DocumentPolicyViolationReportBody::ToJSONMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8DocumentPolicyViolationReportBodyTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8DocumentPolicyViolationReportBody::GetWrapperTypeInfo()->interface_name, V8ReportBody::DomTemplate(isolate, world), V8DocumentPolicyViolationReportBody::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "featureId", V8DocumentPolicyViolationReportBody::FeatureIdAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sourceFile", V8DocumentPolicyViolationReportBody::SourceFileAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "lineNumber", V8DocumentPolicyViolationReportBody::LineNumberAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "columnNumber", V8DocumentPolicyViolationReportBody::ColumnNumberAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "disposition", V8DocumentPolicyViolationReportBody::DispositionAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "message", V8DocumentPolicyViolationReportBody::MessageAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8DocumentPolicyViolationReportBodyMethods, base::size(kV8DocumentPolicyViolationReportBodyMethods));

  // Custom signature

  V8DocumentPolicyViolationReportBody::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8DocumentPolicyViolationReportBody::InstallRuntimeEnabledFeaturesOnTemplate(
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

  // Custom signature
}

v8::Local<v8::FunctionTemplate> V8DocumentPolicyViolationReportBody::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8DocumentPolicyViolationReportBody::GetWrapperTypeInfo()),
      InstallV8DocumentPolicyViolationReportBodyTemplate);
}

bool V8DocumentPolicyViolationReportBody::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8DocumentPolicyViolationReportBody::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8DocumentPolicyViolationReportBody::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8DocumentPolicyViolationReportBody::GetWrapperTypeInfo(), v8_value);
}

DocumentPolicyViolationReportBody* V8DocumentPolicyViolationReportBody::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
