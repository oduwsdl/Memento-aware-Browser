// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_encoded_audio_frame.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_encoded_audio_frame_metadata.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
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
const WrapperTypeInfo v8_rtc_encoded_audio_frame_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8RTCEncodedAudioFrame::DomTemplate,
    nullptr,
    "RTCEncodedAudioFrame",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in RTCEncodedAudioFrame.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& RTCEncodedAudioFrame::wrapper_type_info_ = v8_rtc_encoded_audio_frame_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, RTCEncodedAudioFrame>::value,
    "RTCEncodedAudioFrame inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&RTCEncodedAudioFrame::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "RTCEncodedAudioFrame is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace rtc_encoded_audio_frame_v8_internal {

static void TimestampAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(holder);

  V8SetReturnValue(info, static_cast<double>(impl->timestamp()));
}

static void DataAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(holder);

  V8SetReturnValueFast(info, WTF::GetPtr(impl->data()), impl);
}

static void DataAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "RTCEncodedAudioFrame", "data");

  // Prepare the value to be set.
  DOMArrayBuffer* cpp_value = v8_value->IsArrayBuffer() ? V8ArrayBuffer::ToImpl(v8::Local<v8::ArrayBuffer>::Cast(v8_value)) : 0;

  // Type check per: http://heycam.github.io/webidl/#es-interface
  if (!cpp_value) {
    exception_state.ThrowTypeError("The provided value is not of type 'ArrayBuffer'.");
    return;
  }

  impl->setData(cpp_value);
}

static void AdditionalDataAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(holder);

  V8SetReturnValueFast(info, WTF::GetPtr(impl->additionalData()), impl);
}

static void SynchronizationSourceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->synchronizationSource());
}

static void ContributingSourcesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(holder);

  V8SetReturnValue(info, FreezeV8Object(ToV8(impl->contributingSources(), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void GetMetadataMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(info.Holder());

  RTCEncodedAudioFrameMetadata* result = impl->getMetadata();
  V8SetReturnValue(info, result);
}

static void ToStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RTCEncodedAudioFrame* impl = V8RTCEncodedAudioFrame::ToImpl(info.Holder());

  V8SetReturnValueString(info, impl->toString(), info.GetIsolate());
}

}  // namespace rtc_encoded_audio_frame_v8_internal

void V8RTCEncodedAudioFrame::TimestampAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_timestamp_Getter");

  rtc_encoded_audio_frame_v8_internal::TimestampAttributeGetter(info);
}

void V8RTCEncodedAudioFrame::DataAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_data_Getter");

  rtc_encoded_audio_frame_v8_internal::DataAttributeGetter(info);
}

void V8RTCEncodedAudioFrame::DataAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_data_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  rtc_encoded_audio_frame_v8_internal::DataAttributeSetter(v8_value, info);
}

void V8RTCEncodedAudioFrame::AdditionalDataAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_additionalData_Getter");

  rtc_encoded_audio_frame_v8_internal::AdditionalDataAttributeGetter(info);
}

void V8RTCEncodedAudioFrame::SynchronizationSourceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_synchronizationSource_Getter");

  rtc_encoded_audio_frame_v8_internal::SynchronizationSourceAttributeGetter(info);
}

void V8RTCEncodedAudioFrame::ContributingSourcesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_contributingSources_Getter");

  rtc_encoded_audio_frame_v8_internal::ContributingSourcesAttributeGetter(info);
}

void V8RTCEncodedAudioFrame::GetMetadataMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("RTCEncodedAudioFrame.getMetadata");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_getMetadata");

  rtc_encoded_audio_frame_v8_internal::GetMetadataMethod(info);
}

void V8RTCEncodedAudioFrame::ToStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("RTCEncodedAudioFrame.toString");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_RTCEncodedAudioFrame_toString");

  rtc_encoded_audio_frame_v8_internal::ToStringMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8RTCEncodedAudioFrameMethods[] = {
    {"getMetadata", V8RTCEncodedAudioFrame::GetMetadataMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"toString", V8RTCEncodedAudioFrame::ToStringMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8RTCEncodedAudioFrameTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8RTCEncodedAudioFrame::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8RTCEncodedAudioFrame::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "timestamp", V8RTCEncodedAudioFrame::TimestampAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "data", V8RTCEncodedAudioFrame::DataAttributeGetterCallback, V8RTCEncodedAudioFrame::DataAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "additionalData", V8RTCEncodedAudioFrame::AdditionalDataAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "synchronizationSource", V8RTCEncodedAudioFrame::SynchronizationSourceAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "contributingSources", V8RTCEncodedAudioFrame::ContributingSourcesAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8RTCEncodedAudioFrameMethods, base::size(kV8RTCEncodedAudioFrameMethods));

  // Custom signature

  V8RTCEncodedAudioFrame::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8RTCEncodedAudioFrame::InstallRuntimeEnabledFeaturesOnTemplate(
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

v8::Local<v8::FunctionTemplate> V8RTCEncodedAudioFrame::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8RTCEncodedAudioFrame::GetWrapperTypeInfo()),
      InstallV8RTCEncodedAudioFrameTemplate);
}

bool V8RTCEncodedAudioFrame::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8RTCEncodedAudioFrame::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8RTCEncodedAudioFrame::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8RTCEncodedAudioFrame::GetWrapperTypeInfo(), v8_value);
}

RTCEncodedAudioFrame* V8RTCEncodedAudioFrame::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
