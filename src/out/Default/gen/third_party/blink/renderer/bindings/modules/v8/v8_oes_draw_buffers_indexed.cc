// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_oes_draw_buffers_indexed.h"

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
const WrapperTypeInfo v8_oes_draw_buffers_indexed_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8OESDrawBuffersIndexed::DomTemplate,
    nullptr,
    "OESDrawBuffersIndexed",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in OESDrawBuffersIndexed.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& OESDrawBuffersIndexed::wrapper_type_info_ = v8_oes_draw_buffers_indexed_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, OESDrawBuffersIndexed>::value,
    "OESDrawBuffersIndexed inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&OESDrawBuffersIndexed::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "OESDrawBuffersIndexed is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace oes_draw_buffers_indexed_v8_internal {

static void EnableiOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "enableiOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint32_t target;
  uint32_t index;
  target = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  index = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->enableiOES(target, index);
}

static void DisableiOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "disableiOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint32_t target;
  uint32_t index;
  target = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  index = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->disableiOES(target, index);
}

static void BlendEquationiOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "blendEquationiOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint32_t buf;
  uint32_t mode;
  buf = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  mode = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->blendEquationiOES(buf, mode);
}

static void BlendEquationSeparateiOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "blendEquationSeparateiOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 3)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(3, info.Length()));
    return;
  }

  uint32_t buf;
  uint32_t mode_rgb;
  uint32_t mode_alpha;
  buf = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  mode_rgb = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  mode_alpha = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  impl->blendEquationSeparateiOES(buf, mode_rgb, mode_alpha);
}

static void BlendFunciOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "blendFunciOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 3)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(3, info.Length()));
    return;
  }

  uint32_t buf;
  uint32_t src;
  uint32_t dst;
  buf = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  src = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  dst = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  impl->blendFunciOES(buf, src, dst);
}

static void BlendFuncSeparateiOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "blendFuncSeparateiOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 5)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(5, info.Length()));
    return;
  }

  uint32_t buf;
  uint32_t src_rgb;
  uint32_t dst_rgb;
  uint32_t src_alpha;
  uint32_t dst_alpha;
  buf = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  src_rgb = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  dst_rgb = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  src_alpha = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  dst_alpha = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  impl->blendFuncSeparateiOES(buf, src_rgb, dst_rgb, src_alpha, dst_alpha);
}

static void ColorMaskiOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "colorMaskiOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 5)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(5, info.Length()));
    return;
  }

  uint32_t buf;
  bool r;
  bool g;
  bool b;
  bool a;
  buf = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  r = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  g = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  b = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  a = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  impl->colorMaskiOES(buf, r, g, b, a);
}

static void IsEnablediOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "OESDrawBuffersIndexed", "isEnablediOES");

  OESDrawBuffersIndexed* impl = V8OESDrawBuffersIndexed::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint32_t target;
  uint32_t index;
  target = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  index = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  V8SetReturnValueBool(info, impl->isEnablediOES(target, index));
}

}  // namespace oes_draw_buffers_indexed_v8_internal

void V8OESDrawBuffersIndexed::EnableiOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.enableiOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_enableiOES");

  oes_draw_buffers_indexed_v8_internal::EnableiOESMethod(info);
}

void V8OESDrawBuffersIndexed::DisableiOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.disableiOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_disableiOES");

  oes_draw_buffers_indexed_v8_internal::DisableiOESMethod(info);
}

void V8OESDrawBuffersIndexed::BlendEquationiOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.blendEquationiOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_blendEquationiOES");

  oes_draw_buffers_indexed_v8_internal::BlendEquationiOESMethod(info);
}

void V8OESDrawBuffersIndexed::BlendEquationSeparateiOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.blendEquationSeparateiOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_blendEquationSeparateiOES");

  oes_draw_buffers_indexed_v8_internal::BlendEquationSeparateiOESMethod(info);
}

void V8OESDrawBuffersIndexed::BlendFunciOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.blendFunciOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_blendFunciOES");

  oes_draw_buffers_indexed_v8_internal::BlendFunciOESMethod(info);
}

void V8OESDrawBuffersIndexed::BlendFuncSeparateiOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.blendFuncSeparateiOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_blendFuncSeparateiOES");

  oes_draw_buffers_indexed_v8_internal::BlendFuncSeparateiOESMethod(info);
}

void V8OESDrawBuffersIndexed::ColorMaskiOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.colorMaskiOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_colorMaskiOES");

  oes_draw_buffers_indexed_v8_internal::ColorMaskiOESMethod(info);
}

void V8OESDrawBuffersIndexed::IsEnablediOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("OESDrawBuffersIndexed.isEnablediOES");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_OESDrawBuffersIndexed_isEnablediOES");

  oes_draw_buffers_indexed_v8_internal::IsEnablediOESMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8OESDrawBuffersIndexedMethods[] = {
    {"enableiOES", V8OESDrawBuffersIndexed::EnableiOESMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"disableiOES", V8OESDrawBuffersIndexed::DisableiOESMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"blendEquationiOES", V8OESDrawBuffersIndexed::BlendEquationiOESMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"blendEquationSeparateiOES", V8OESDrawBuffersIndexed::BlendEquationSeparateiOESMethodCallback, 3, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"blendFunciOES", V8OESDrawBuffersIndexed::BlendFunciOESMethodCallback, 3, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"blendFuncSeparateiOES", V8OESDrawBuffersIndexed::BlendFuncSeparateiOESMethodCallback, 5, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"colorMaskiOES", V8OESDrawBuffersIndexed::ColorMaskiOESMethodCallback, 5, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"isEnablediOES", V8OESDrawBuffersIndexed::IsEnablediOESMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8OESDrawBuffersIndexedTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8OESDrawBuffersIndexed::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8OESDrawBuffersIndexed::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  {
    static constexpr V8DOMConfiguration::ConstantConfiguration kConstants[] = {
        {"BLEND_EQUATION_RGB", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x8009)},
        {"BLEND_EQUATION_ALPHA", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x883D)},
        {"BLEND_SRC_RGB", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x80C9)},
        {"BLEND_SRC_ALPHA", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x80CB)},
        {"BLEND_DST_RGB", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x80C8)},
        {"BLEND_DST_ALPHA", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x80CA)},
        {"COLOR_WRITEMASK", V8DOMConfiguration::kConstantTypeUnsignedLong, static_cast<int>(0x0C23)},
    };
    V8DOMConfiguration::InstallConstants(
        isolate, interface_template, prototype_template,
        kConstants, base::size(kConstants));
  }
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8OESDrawBuffersIndexedMethods, base::size(kV8OESDrawBuffersIndexedMethods));

  // Custom signature

  V8OESDrawBuffersIndexed::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8OESDrawBuffersIndexed::InstallRuntimeEnabledFeaturesOnTemplate(
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

v8::Local<v8::FunctionTemplate> V8OESDrawBuffersIndexed::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8OESDrawBuffersIndexed::GetWrapperTypeInfo()),
      InstallV8OESDrawBuffersIndexedTemplate);
}

bool V8OESDrawBuffersIndexed::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8OESDrawBuffersIndexed::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8OESDrawBuffersIndexed::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8OESDrawBuffersIndexed::GetWrapperTypeInfo(), v8_value);
}

OESDrawBuffersIndexed* V8OESDrawBuffersIndexed::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
