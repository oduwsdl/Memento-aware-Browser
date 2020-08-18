// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_compressed_texture_astc.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
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
const WrapperTypeInfo v8_webgl_compressed_texture_astc_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8WebGLCompressedTextureASTC::DomTemplate,
    nullptr,
    "WebGLCompressedTextureASTC",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in WebGLCompressedTextureASTC.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& WebGLCompressedTextureASTC::wrapper_type_info_ = v8_webgl_compressed_texture_astc_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, WebGLCompressedTextureASTC>::value,
    "WebGLCompressedTextureASTC inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&WebGLCompressedTextureASTC::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "WebGLCompressedTextureASTC is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace webgl_compressed_texture_astc_v8_internal {

static void GetSupportedProfilesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  WebGLCompressedTextureASTC* impl = V8WebGLCompressedTextureASTC::ToImpl(info.Holder());

  V8SetReturnValue(info, ToV8(impl->getSupportedProfiles(), info.Holder(), info.GetIsolate()));
}

}  // namespace webgl_compressed_texture_astc_v8_internal

void V8WebGLCompressedTextureASTC::GetSupportedProfilesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("WebGLCompressedTextureASTC.getSupportedProfiles");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_WebGLCompressedTextureASTC_getSupportedProfiles");

  webgl_compressed_texture_astc_v8_internal::GetSupportedProfilesMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8WebGLCompressedTextureASTCMethods[] = {
    {"getSupportedProfiles", V8WebGLCompressedTextureASTC::GetSupportedProfilesMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8WebGLCompressedTextureASTCTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8WebGLCompressedTextureASTC::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8WebGLCompressedTextureASTC::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  {
    static constexpr V8DOMConfiguration::ConstantConfiguration kConstants[] = {
        {"COMPRESSED_RGBA_ASTC_4x4_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B0)},
        {"COMPRESSED_RGBA_ASTC_5x4_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B1)},
        {"COMPRESSED_RGBA_ASTC_5x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B2)},
        {"COMPRESSED_RGBA_ASTC_6x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B3)},
        {"COMPRESSED_RGBA_ASTC_6x6_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B4)},
        {"COMPRESSED_RGBA_ASTC_8x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B5)},
        {"COMPRESSED_RGBA_ASTC_8x6_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B6)},
        {"COMPRESSED_RGBA_ASTC_8x8_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B7)},
        {"COMPRESSED_RGBA_ASTC_10x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B8)},
        {"COMPRESSED_RGBA_ASTC_10x6_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93B9)},
        {"COMPRESSED_RGBA_ASTC_10x8_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93BA)},
        {"COMPRESSED_RGBA_ASTC_10x10_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93BB)},
        {"COMPRESSED_RGBA_ASTC_12x10_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93BC)},
        {"COMPRESSED_RGBA_ASTC_12x12_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93BD)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D0)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D1)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D2)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D3)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D4)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D5)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D6)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D7)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D8)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93D9)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93DA)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93DB)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93DC)},
        {"COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x93DD)},
    };
    V8DOMConfiguration::InstallConstants(
        isolate, interface_template, prototype_template,
        kConstants, base::size(kConstants));
  }
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8WebGLCompressedTextureASTCMethods, base::size(kV8WebGLCompressedTextureASTCMethods));

  // Custom signature

  V8WebGLCompressedTextureASTC::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8WebGLCompressedTextureASTC::InstallRuntimeEnabledFeaturesOnTemplate(
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

v8::Local<v8::FunctionTemplate> V8WebGLCompressedTextureASTC::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8WebGLCompressedTextureASTC::GetWrapperTypeInfo()),
      InstallV8WebGLCompressedTextureASTCTemplate);
}

bool V8WebGLCompressedTextureASTC::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8WebGLCompressedTextureASTC::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8WebGLCompressedTextureASTC::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8WebGLCompressedTextureASTC::GetWrapperTypeInfo(), v8_value);
}

WebGLCompressedTextureASTC* V8WebGLCompressedTextureASTC::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
