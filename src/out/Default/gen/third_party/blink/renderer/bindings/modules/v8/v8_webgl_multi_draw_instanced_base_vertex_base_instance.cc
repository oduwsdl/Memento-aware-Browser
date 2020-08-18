// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_multi_draw_instanced_base_vertex_base_instance.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_int32_array.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
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
const WrapperTypeInfo v8_webgl_multi_draw_instanced_base_vertex_base_instance_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8WebGLMultiDrawInstancedBaseVertexBaseInstance::DomTemplate,
    nullptr,
    "WebGLMultiDrawInstancedBaseVertexBaseInstance",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in WebGLMultiDrawInstancedBaseVertexBaseInstance.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& WebGLMultiDrawInstancedBaseVertexBaseInstance::wrapper_type_info_ = v8_webgl_multi_draw_instanced_base_vertex_base_instance_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, WebGLMultiDrawInstancedBaseVertexBaseInstance>::value,
    "WebGLMultiDrawInstancedBaseVertexBaseInstance inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&WebGLMultiDrawInstancedBaseVertexBaseInstance::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "WebGLMultiDrawInstancedBaseVertexBaseInstance is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace webgl_multi_draw_instanced_base_vertex_base_instance_v8_internal {

static void MultiDrawArraysInstancedBaseInstanceWEBGLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "WebGLMultiDrawInstancedBaseVertexBaseInstance", "multiDrawArraysInstancedBaseInstanceWEBGL");

  WebGLMultiDrawInstancedBaseVertexBaseInstance* impl = V8WebGLMultiDrawInstancedBaseVertexBaseInstance::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 10)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(10, info.Length()));
    return;
  }

  uint32_t mode;
  Int32ArrayOrLongSequence firsts_list;
  uint32_t firsts_offset;
  Int32ArrayOrLongSequence counts_list;
  uint32_t counts_offset;
  Int32ArrayOrLongSequence instance_counts_list;
  uint32_t instance_counts_offset;
  Int32ArrayOrLongSequence base_instances_list;
  uint32_t base_instances_offset;
  int32_t drawcount;
  mode = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[1], firsts_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  firsts_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[3], counts_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  counts_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[5], instance_counts_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  instance_counts_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[6], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[7], base_instances_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  base_instances_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[8], exception_state);
  if (exception_state.HadException())
    return;

  drawcount = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[9], exception_state);
  if (exception_state.HadException())
    return;

  impl->multiDrawArraysInstancedBaseInstanceWEBGL(mode, firsts_list, firsts_offset, counts_list, counts_offset, instance_counts_list, instance_counts_offset, base_instances_list, base_instances_offset, drawcount);
}

static void MultiDrawElementsInstancedBaseVertexBaseInstanceWEBGLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "WebGLMultiDrawInstancedBaseVertexBaseInstance", "multiDrawElementsInstancedBaseVertexBaseInstanceWEBGL");

  WebGLMultiDrawInstancedBaseVertexBaseInstance* impl = V8WebGLMultiDrawInstancedBaseVertexBaseInstance::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 13)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(13, info.Length()));
    return;
  }

  uint32_t mode;
  Int32ArrayOrLongSequence counts_list;
  uint32_t counts_offset;
  uint32_t type;
  Int32ArrayOrLongSequence offsets_list;
  uint32_t offsets_offset;
  Int32ArrayOrLongSequence instance_counts_list;
  uint32_t instance_counts_offset;
  Int32ArrayOrLongSequence base_vertices_list;
  uint32_t base_vertices_offset;
  Int32ArrayOrLongSequence base_instances_list;
  uint32_t base_instances_offset;
  int32_t drawcount;
  mode = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[1], counts_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  counts_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;

  type = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[4], offsets_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  offsets_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[5], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[6], instance_counts_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  instance_counts_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[7], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[8], base_vertices_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  base_vertices_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[9], exception_state);
  if (exception_state.HadException())
    return;

  V8Int32ArrayOrLongSequence::ToImpl(info.GetIsolate(), info[10], base_instances_list, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  base_instances_offset = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[11], exception_state);
  if (exception_state.HadException())
    return;

  drawcount = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[12], exception_state);
  if (exception_state.HadException())
    return;

  impl->multiDrawElementsInstancedBaseVertexBaseInstanceWEBGL(mode, counts_list, counts_offset, type, offsets_list, offsets_offset, instance_counts_list, instance_counts_offset, base_vertices_list, base_vertices_offset, base_instances_list, base_instances_offset, drawcount);
}

}  // namespace webgl_multi_draw_instanced_base_vertex_base_instance_v8_internal

void V8WebGLMultiDrawInstancedBaseVertexBaseInstance::MultiDrawArraysInstancedBaseInstanceWEBGLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("WebGLMultiDrawInstancedBaseVertexBaseInstance.multiDrawArraysInstancedBaseInstanceWEBGL");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_WebGLMultiDrawInstancedBaseVertexBaseInstance_multiDrawArraysInstancedBaseInstanceWEBGL");

  webgl_multi_draw_instanced_base_vertex_base_instance_v8_internal::MultiDrawArraysInstancedBaseInstanceWEBGLMethod(info);
}

void V8WebGLMultiDrawInstancedBaseVertexBaseInstance::MultiDrawElementsInstancedBaseVertexBaseInstanceWEBGLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("WebGLMultiDrawInstancedBaseVertexBaseInstance.multiDrawElementsInstancedBaseVertexBaseInstanceWEBGL");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_WebGLMultiDrawInstancedBaseVertexBaseInstance_multiDrawElementsInstancedBaseVertexBaseInstanceWEBGL");

  webgl_multi_draw_instanced_base_vertex_base_instance_v8_internal::MultiDrawElementsInstancedBaseVertexBaseInstanceWEBGLMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8WebGLMultiDrawInstancedBaseVertexBaseInstanceMethods[] = {
    {"multiDrawArraysInstancedBaseInstanceWEBGL", V8WebGLMultiDrawInstancedBaseVertexBaseInstance::MultiDrawArraysInstancedBaseInstanceWEBGLMethodCallback, 10, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"multiDrawElementsInstancedBaseVertexBaseInstanceWEBGL", V8WebGLMultiDrawInstancedBaseVertexBaseInstance::MultiDrawElementsInstancedBaseVertexBaseInstanceWEBGLMethodCallback, 13, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8WebGLMultiDrawInstancedBaseVertexBaseInstanceTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8WebGLMultiDrawInstancedBaseVertexBaseInstance::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8WebGLMultiDrawInstancedBaseVertexBaseInstance::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8WebGLMultiDrawInstancedBaseVertexBaseInstanceMethods, base::size(kV8WebGLMultiDrawInstancedBaseVertexBaseInstanceMethods));

  // Custom signature

  V8WebGLMultiDrawInstancedBaseVertexBaseInstance::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8WebGLMultiDrawInstancedBaseVertexBaseInstance::InstallRuntimeEnabledFeaturesOnTemplate(
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

v8::Local<v8::FunctionTemplate> V8WebGLMultiDrawInstancedBaseVertexBaseInstance::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8WebGLMultiDrawInstancedBaseVertexBaseInstance::GetWrapperTypeInfo()),
      InstallV8WebGLMultiDrawInstancedBaseVertexBaseInstanceTemplate);
}

bool V8WebGLMultiDrawInstancedBaseVertexBaseInstance::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8WebGLMultiDrawInstancedBaseVertexBaseInstance::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8WebGLMultiDrawInstancedBaseVertexBaseInstance::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8WebGLMultiDrawInstancedBaseVertexBaseInstance::GetWrapperTypeInfo(), v8_value);
}

WebGLMultiDrawInstancedBaseVertexBaseInstance* V8WebGLMultiDrawInstancedBaseVertexBaseInstance::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
