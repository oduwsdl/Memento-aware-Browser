// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_location.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/binding_security.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_string_list.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_fragment_directive.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/web_feature.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_cross_origin_callback_info.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
#include "third_party/blink/renderer/platform/bindings/v8_private_property.h"
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
const WrapperTypeInfo v8_location_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8Location::DomTemplate,
    nullptr,
    "Location",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in Location.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& Location::wrapper_type_info_ = v8_location_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, Location>::value,
    "Location inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&Location::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "Location is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace location_v8_internal {

static void AncestorOriginsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  DOMStringList* cpp_value(WTF::GetPtr(impl->ancestorOrigins()));

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

static void HrefAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->href(), info.GetIsolate());
}

static void HrefAttributeSetter(
    v8::Local<v8::Value> v8_value, const V8CrossOriginCallbackInfo& info
) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "href");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setHref(info.GetIsolate(), cpp_value, exception_state);
}

static void OriginAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->origin(), info.GetIsolate());
}

static void ProtocolAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->protocol(), info.GetIsolate());
}

static void ProtocolAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "protocol");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setProtocol(info.GetIsolate(), cpp_value, exception_state);
}

static void HostAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->host(), info.GetIsolate());
}

static void HostAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "host");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setHost(info.GetIsolate(), cpp_value, exception_state);
}

static void HostnameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->hostname(), info.GetIsolate());
}

static void HostnameAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "hostname");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setHostname(info.GetIsolate(), cpp_value, exception_state);
}

static void PortAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->port(), info.GetIsolate());
}

static void PortAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "port");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setPort(info.GetIsolate(), cpp_value, exception_state);
}

static void PathnameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->pathname(), info.GetIsolate());
}

static void PathnameAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "pathname");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setPathname(info.GetIsolate(), cpp_value, exception_state);
}

static void SearchAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->search(), info.GetIsolate());
}

static void SearchAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "search");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setSearch(info.GetIsolate(), cpp_value, exception_state);
}

static void HashAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  V8SetReturnValueString(info, impl->hash(), info.GetIsolate());
}

static void HashAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  Location* impl = V8Location::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "Location", "hash");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setHash(info.GetIsolate(), cpp_value, exception_state);
}

static void FragmentDirectiveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  Location* impl = V8Location::ToImpl(holder);

  FragmentDirective* cpp_value(WTF::GetPtr(impl->fragmentDirective()));

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

static void AssignMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "Location", "assign");

  Location* impl = V8Location::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> url;
  url = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->assign(info.GetIsolate(), url, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void ReplaceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "Location", "replace");

  Location* impl = V8Location::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> url;
  url = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->replace(info.GetIsolate(), url, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void ReplaceOriginSafeMethodGetter(const v8::PropertyCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  V8PerIsolateData* data = V8PerIsolateData::From(isolate);
  const DOMWrapperWorld& world =
      DOMWrapperWorld::World(isolate->GetCurrentContext());
  v8::Local<v8::FunctionTemplate> interface_template =
      data->FindInterfaceTemplate(world, V8Location::GetWrapperTypeInfo());
  v8::Local<v8::Signature> signature =
      v8::Signature::New(isolate, interface_template);

  static int dom_template_key; // This address is used for a key to look up the dom template.
  v8::Local<v8::FunctionTemplate> method_template =
      data->FindOrCreateOperationTemplate(
          world,
          &dom_template_key,
          V8Location::ReplaceMethodCallback,
          v8::Local<v8::Value>(),
          signature,
          1);

  V8SetReturnValue(
      info,
      method_template->GetFunction(
          isolate->GetCurrentContext()).ToLocalChecked());
}

static void ReloadMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Location* impl = V8Location::ToImpl(info.Holder());

  impl->reload();
}

static void ToStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Location* impl = V8Location::ToImpl(info.Holder());

  V8SetReturnValueString(info, impl->toString(), info.GetIsolate());
}

static void ValueOfMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  Location* impl = V8Location::ToImpl(info.Holder());

  V8SetReturnValue(info, impl->valueOf(ScriptValue(info.GetIsolate(), info.Holder())).V8Value());
}

static const struct {
  using GetterCallback = void(*)(const v8::PropertyCallbackInfo<v8::Value>&);
  using SetterCallback = void(*)(v8::Local<v8::Value>, const V8CrossOriginCallbackInfo&);

  const char* const name;
  const GetterCallback getter;
  const SetterCallback setter;
} kCrossOriginAttributeTable[] = {
  {
    "href",
    nullptr,
    &location_v8_internal::HrefAttributeSetter,
  },
};

static const struct {
  using ValueCallback = void(*)(const v8::PropertyCallbackInfo<v8::Value>&);

  const char* const name;
  const ValueCallback value;
} kCrossOriginOperationTable[] = {
  {"replace", &location_v8_internal::ReplaceOriginSafeMethodGetter},
};
}  // namespace location_v8_internal

void V8Location::AncestorOriginsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_ancestorOrigins_Getter");

  location_v8_internal::AncestorOriginsAttributeGetter(info);
}

void V8Location::HrefAttributeGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_href_Getter");

  location_v8_internal::HrefAttributeGetter(info);
}

void V8Location::HrefAttributeSetterCallback(
    v8::Local<v8::Name>, v8::Local<v8::Value> v8_value, const v8::PropertyCallbackInfo<void>& info
) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_href_Setter");

  location_v8_internal::HrefAttributeSetter(
      v8_value, V8CrossOriginCallbackInfo(info));
}

void V8Location::OriginAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_origin_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kLocationOrigin);

  location_v8_internal::OriginAttributeGetter(info);
}

void V8Location::ProtocolAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_protocol_Getter");

  location_v8_internal::ProtocolAttributeGetter(info);
}

void V8Location::ProtocolAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_protocol_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  location_v8_internal::ProtocolAttributeSetter(v8_value, info);
}

void V8Location::HostAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_host_Getter");

  location_v8_internal::HostAttributeGetter(info);
}

void V8Location::HostAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_host_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  location_v8_internal::HostAttributeSetter(v8_value, info);
}

void V8Location::HostnameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_hostname_Getter");

  location_v8_internal::HostnameAttributeGetter(info);
}

void V8Location::HostnameAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_hostname_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  location_v8_internal::HostnameAttributeSetter(v8_value, info);
}

void V8Location::PortAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_port_Getter");

  location_v8_internal::PortAttributeGetter(info);
}

void V8Location::PortAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_port_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  location_v8_internal::PortAttributeSetter(v8_value, info);
}

void V8Location::PathnameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_pathname_Getter");

  location_v8_internal::PathnameAttributeGetter(info);
}

void V8Location::PathnameAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_pathname_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  location_v8_internal::PathnameAttributeSetter(v8_value, info);
}

void V8Location::SearchAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_search_Getter");

  location_v8_internal::SearchAttributeGetter(info);
}

void V8Location::SearchAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_search_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  location_v8_internal::SearchAttributeSetter(v8_value, info);
}

void V8Location::HashAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_hash_Getter");

  location_v8_internal::HashAttributeGetter(info);
}

void V8Location::HashAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_hash_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  location_v8_internal::HashAttributeSetter(v8_value, info);
}

void V8Location::FragmentDirectiveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_fragmentDirective_Getter");

  location_v8_internal::FragmentDirectiveAttributeGetter(info);
}

void V8Location::AssignMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("Location.assign");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_assign");

  location_v8_internal::AssignMethod(info);
}

void V8Location::ReplaceMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("Location.replace");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_replace");

  location_v8_internal::ReplaceMethod(info);
}

void V8Location::ReplaceOriginSafeMethodGetterCallback(v8::Local<v8::Name>, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_replace_OriginSafeMethodGetter");

  location_v8_internal::ReplaceOriginSafeMethodGetter(info);
}

void V8Location::ReloadMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("Location.reload");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_reload");

  location_v8_internal::ReloadMethod(info);
}

void V8Location::ToStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("Location.toString");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_toString");

  location_v8_internal::ToStringMethod(info);
}

void V8Location::ValueOfMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("Location.valueOf");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_valueOf");

  location_v8_internal::ValueOfMethod(info);
}

bool V8Location::SecurityCheck(v8::Local<v8::Context> accessing_context, v8::Local<v8::Object> accessed_object, v8::Local<v8::Value> data) {
  Location* impl = V8Location::ToImpl(accessed_object);
  return BindingSecurity::ShouldAllowAccessTo(ToLocalDOMWindow(accessing_context), impl, BindingSecurity::ErrorReportOption::kDoNotReport);
}

void V8Location::CrossOriginNamedGetter(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_CrossOriginNamedGetter");

  if (!name->IsString())
    return;
  const AtomicString& property_name = ToCoreAtomicString(name.As<v8::String>());

  for (const auto& attribute : location_v8_internal::kCrossOriginAttributeTable) {
    if (property_name == attribute.name && attribute.getter) {
      attribute.getter(info);
      return;
    }
  }
  for (const auto& operation : location_v8_internal::kCrossOriginOperationTable) {
    if (property_name == operation.name) {
      operation.value(info);
      return;
    }
  }

  // HTML 7.2.3.3 CrossOriginGetOwnPropertyHelper ( O, P )
  // https://html.spec.whatwg.org/C/#crossorigingetownpropertyhelper-(-o,-p-)
  // step 3. If P is "then", @@toStringTag, @@hasInstance, or
  //   @@isConcatSpreadable, then return PropertyDescriptor{ [[Value]]:
  //   undefined, [[Writable]]: false, [[Enumerable]]: false,
  //   [[Configurable]]: true }.
  if (property_name == "then") {
    V8SetReturnValue(info, v8::Undefined(info.GetIsolate()));
    return;
  }

  BindingSecurity::FailedAccessCheckFor(
      info.GetIsolate(),
      V8Location::GetWrapperTypeInfo(),
      info.Holder());
}

void V8Location::CrossOriginNamedSetter(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_Location_CrossOriginNamedSetter");

  if (!name->IsString())
    return;
  const AtomicString& property_name = ToCoreAtomicString(name.As<v8::String>());

  for (const auto& attribute : location_v8_internal::kCrossOriginAttributeTable) {
    if (property_name == attribute.name && attribute.setter) {
      attribute.setter(value, V8CrossOriginCallbackInfo(info));
      return;
    }
  }

  BindingSecurity::FailedAccessCheckFor(
      info.GetIsolate(),
      V8Location::GetWrapperTypeInfo(),
      info.Holder());
}

void V8Location::CrossOriginNamedEnumerator(const v8::PropertyCallbackInfo<v8::Array>& info) {
  Vector<String> names;
  for (const auto& attribute : location_v8_internal::kCrossOriginAttributeTable)
    names.push_back(attribute.name);
  for (const auto& operation : location_v8_internal::kCrossOriginOperationTable)
    names.push_back(operation.name);

  // Use the current context as the creation context, as a cross-origin access
  // may involve an object that does not have a creation context.
  V8SetReturnValue(info,
                   ToV8(names, info.GetIsolate()->GetCurrentContext()->Global(),
                        info.GetIsolate()).As<v8::Array>());
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8LocationMethods[] = {
    {"assign", V8Location::AssignMethodCallback, 1, static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"reload", V8Location::ReloadMethodCallback, 0, static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"toString", V8Location::ToStringMethodCallback, 0, static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"valueOf", V8Location::ValueOfMethodCallback, 0, static_cast<v8::PropertyAttribute>(v8::DontEnum | v8::ReadOnly | v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8LocationTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8Location::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8Location::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AttributeConfiguration
  kAttributeConfigurations[] = {
      { "href", V8Location::HrefAttributeGetterCallback, V8Location::HrefAttributeSetterCallback, static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasNoSideEffect, V8DOMConfiguration::kAlwaysCallGetter, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAttributes(
      isolate, world, instance_template, prototype_template,
      kAttributeConfigurations, base::size(kAttributeConfigurations));
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "ancestorOrigins", V8Location::AncestorOriginsAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete | v8::ReadOnly), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "origin", V8Location::OriginAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete | v8::ReadOnly), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "protocol", V8Location::ProtocolAttributeGetterCallback, V8Location::ProtocolAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "host", V8Location::HostAttributeGetterCallback, V8Location::HostAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "hostname", V8Location::HostnameAttributeGetterCallback, V8Location::HostnameAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "port", V8Location::PortAttributeGetterCallback, V8Location::PortAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pathname", V8Location::PathnameAttributeGetterCallback, V8Location::PathnameAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "search", V8Location::SearchAttributeGetterCallback, V8Location::SearchAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "hash", V8Location::HashAttributeGetterCallback, V8Location::HashAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::DontDelete), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8LocationMethods, base::size(kV8LocationMethods));

  // Cross-origin access check
  instance_template->SetAccessCheckCallbackAndHandler(
      V8Location::SecurityCheck,
      v8::NamedPropertyHandlerConfiguration(
          V8Location::CrossOriginNamedGetter,
          V8Location::CrossOriginNamedSetter,
          nullptr,
          nullptr,
          V8Location::CrossOriginNamedEnumerator),
      v8::IndexedPropertyHandlerConfiguration(nullptr),
      v8::External::New(isolate, const_cast<WrapperTypeInfo*>(V8Location::GetWrapperTypeInfo())));

  // Symbol.toPrimitive
  // Prevent author scripts to inject Symbol.toPrimitive property into location
  // objects, also prevent the look-up of Symbol.toPrimitive through the
  // prototype chain.
  instance_template->Set(v8::Symbol::GetToPrimitive(isolate),
                        v8::Undefined(isolate),
                        static_cast<v8::PropertyAttribute>(
                            v8::ReadOnly | v8::DontEnum | v8::DontDelete));

  // Custom signature
  static const V8DOMConfiguration::MethodConfiguration kReplaceOriginSafeMethodConfiguration[] = {
      {
          "replace",
          V8Location::ReplaceMethodCallback,
          1,
          static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontDelete),
          V8DOMConfiguration::kOnInstance,
          V8DOMConfiguration::kCheckHolder,
          V8DOMConfiguration::kCheckAccess,
          V8DOMConfiguration::kHasSideEffect,
          V8DOMConfiguration::kAllWorlds,
      }
  };
  for (const auto& method_config : kReplaceOriginSafeMethodConfiguration)
    V8DOMConfiguration::InstallMethod(isolate, world, instance_template, prototype_template, interface_template, signature, method_config);

  V8Location::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8Location::InstallRuntimeEnabledFeaturesOnTemplate(
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

void V8Location::InstallTextFragmentIdentifiers(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance,
    v8::Local<v8::Object> prototype,
    v8::Local<v8::Function> interface) {
  v8::Local<v8::FunctionTemplate> interface_template =
      V8Location::GetWrapperTypeInfo()->DomTemplate(isolate, world);
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "fragmentDirective", V8Location::FragmentDirectiveAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance, prototype, interface,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
}

void V8Location::InstallTextFragmentIdentifiers(
    ScriptState* script_state, v8::Local<v8::Object> instance) {
  V8PerContextData* per_context_data = script_state->PerContextData();
  v8::Local<v8::Object> prototype = per_context_data->PrototypeForType(
      V8Location::GetWrapperTypeInfo());
  v8::Local<v8::Function> interface = per_context_data->ConstructorForType(
      V8Location::GetWrapperTypeInfo());
  ALLOW_UNUSED_LOCAL(interface);
  InstallTextFragmentIdentifiers(script_state->GetIsolate(), script_state->World(), instance, prototype, interface);
}

void V8Location::InstallTextFragmentIdentifiers(ScriptState* script_state) {
  InstallTextFragmentIdentifiers(script_state, v8::Local<v8::Object>());
}

v8::Local<v8::FunctionTemplate> V8Location::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8Location::GetWrapperTypeInfo()),
      InstallV8LocationTemplate);
}

bool V8Location::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8Location::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8Location::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8Location::GetWrapperTypeInfo(), v8_value);
}

Location* V8Location::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
