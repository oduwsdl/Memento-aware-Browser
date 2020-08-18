// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_compute_pass_encoder.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_uint32_array.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_bind_group.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_compute_pipeline.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
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
const WrapperTypeInfo v8_gpu_compute_pass_encoder_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8GPUComputePassEncoder::DomTemplate,
    nullptr,
    "GPUComputePassEncoder",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in GPUComputePassEncoder.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& GPUComputePassEncoder::wrapper_type_info_ = v8_gpu_compute_pass_encoder_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, GPUComputePassEncoder>::value,
    "GPUComputePassEncoder inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&GPUComputePassEncoder::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "GPUComputePassEncoder is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace gpu_compute_pass_encoder_v8_internal {

static void SetPipelineMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setPipeline", "GPUComputePassEncoder", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  GPUComputePipeline* pipeline;
  pipeline = V8GPUComputePipeline::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!pipeline) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setPipeline", "GPUComputePassEncoder", ExceptionMessages::ArgumentNotOfType(0, "GPUComputePipeline")));
    return;
  }

  impl->setPipeline(pipeline);
}

static void DispatchMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUComputePassEncoder", "dispatch");

  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  uint32_t x;
  uint32_t y;
  uint32_t z;
  x = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  if (!info[1]->IsUndefined()) {
    y = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    y = 1u;
  }
  if (!info[2]->IsUndefined()) {
    z = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    z = 1u;
  }

  impl->dispatch(x, y, z);
}

static void DispatchIndirectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUComputePassEncoder", "dispatchIndirect");

  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  GPUBuffer* indirect_buffer;
  uint64_t indirect_offset;
  indirect_buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!indirect_buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUBuffer"));
    return;
  }

  indirect_offset = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->dispatchIndirect(indirect_buffer, indirect_offset);
}

static void EndPassMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  impl->endPass();
}

static void SetBindGroup1Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUComputePassEncoder", "setBindGroup");

  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  uint32_t index;
  GPUBindGroup* bind_group;
  Vector<uint32_t> dynamic_offsets;
  index = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  bind_group = V8GPUBindGroup::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!bind_group) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "GPUBindGroup"));
    return;
  }

  if (!info[2]->IsUndefined()) {
    dynamic_offsets = NativeValueTraits<IDLSequence<IDLUnsignedLongEnforceRange>>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    /* Nothing to do */;
  }

  impl->setBindGroup(index, bind_group, dynamic_offsets);
}

static void SetBindGroup2Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUComputePassEncoder", "setBindGroup");

  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  uint32_t index;
  GPUBindGroup* bind_group;
  FlexibleUint32Array dynamic_offsets_data;
  uint64_t dynamic_offsets_data_start;
  uint32_t dynamic_offsets_data_length;
  index = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  bind_group = V8GPUBindGroup::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!bind_group) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "GPUBindGroup"));
    return;
  }

  ToFlexibleArrayBufferView(info.GetIsolate(), info[2], dynamic_offsets_data);
  if (!dynamic_offsets_data) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(2, "Uint32Array"));
    return;
  }

  dynamic_offsets_data_start = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[3], exception_state);
  if (exception_state.HadException())
    return;

  dynamic_offsets_data_length = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  impl->setBindGroup(index, bind_group, dynamic_offsets_data, dynamic_offsets_data_start, dynamic_offsets_data_length, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void SetBindGroupMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  scheduler::CooperativeSchedulingManager::Instance()->Safepoint();

  bool is_arity_error = false;

  switch (std::min(5, info.Length())) {
    case 2:
      if (true) {
        SetBindGroup1Method(info);
        return;
      }
      break;
    case 3:
      if (true) {
        SetBindGroup1Method(info);
        return;
      }
      break;
    case 5:
      if (true) {
        SetBindGroup2Method(info);
        return;
      }
      break;
    default:
      is_arity_error = true;
  }

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUComputePassEncoder", "setBindGroup");
  if (is_arity_error) {
    if (info.Length() < 2) {
      exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
      return;
    }
    if (info.Length() >= 2) {
      exception_state.ThrowTypeError(ExceptionMessages::InvalidArity("[2, 3, 5]", info.Length()));
      return;
    }
  }
  exception_state.ThrowTypeError("No function was found that matched the signature provided.");
}

static void PushDebugGroupMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUComputePassEncoder", "pushDebugGroup");

  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> group_label;
  group_label = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->pushDebugGroup(group_label);
}

static void PopDebugGroupMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  impl->popDebugGroup();
}

static void InsertDebugMarkerMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUComputePassEncoder", "insertDebugMarker");

  GPUComputePassEncoder* impl = V8GPUComputePassEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> marker_label;
  marker_label = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->insertDebugMarker(marker_label);
}

}  // namespace gpu_compute_pass_encoder_v8_internal

void V8GPUComputePassEncoder::SetPipelineMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.setPipeline");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_setPipeline");

  gpu_compute_pass_encoder_v8_internal::SetPipelineMethod(info);
}

void V8GPUComputePassEncoder::DispatchMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.dispatch");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_dispatch");

  gpu_compute_pass_encoder_v8_internal::DispatchMethod(info);
}

void V8GPUComputePassEncoder::DispatchIndirectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.dispatchIndirect");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_dispatchIndirect");

  gpu_compute_pass_encoder_v8_internal::DispatchIndirectMethod(info);
}

void V8GPUComputePassEncoder::EndPassMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.endPass");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_endPass");

  gpu_compute_pass_encoder_v8_internal::EndPassMethod(info);
}

void V8GPUComputePassEncoder::SetBindGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.setBindGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_setBindGroup");

  gpu_compute_pass_encoder_v8_internal::SetBindGroupMethod(info);
}

void V8GPUComputePassEncoder::PushDebugGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.pushDebugGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_pushDebugGroup");

  gpu_compute_pass_encoder_v8_internal::PushDebugGroupMethod(info);
}

void V8GPUComputePassEncoder::PopDebugGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.popDebugGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_popDebugGroup");

  gpu_compute_pass_encoder_v8_internal::PopDebugGroupMethod(info);
}

void V8GPUComputePassEncoder::InsertDebugMarkerMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUComputePassEncoder.insertDebugMarker");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUComputePassEncoder_insertDebugMarker");

  gpu_compute_pass_encoder_v8_internal::InsertDebugMarkerMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8GPUComputePassEncoderMethods[] = {
    {"setPipeline", V8GPUComputePassEncoder::SetPipelineMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"dispatch", V8GPUComputePassEncoder::DispatchMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"dispatchIndirect", V8GPUComputePassEncoder::DispatchIndirectMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"endPass", V8GPUComputePassEncoder::EndPassMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8GPUComputePassEncoderTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8GPUComputePassEncoder::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8GPUComputePassEncoder::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8GPUComputePassEncoderMethods, base::size(kV8GPUComputePassEncoderMethods));

  // Custom signature

  V8GPUComputePassEncoder::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8GPUComputePassEncoder::InstallRuntimeEnabledFeaturesOnTemplate(
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
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install setBindGroup configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setBindGroup", V8GPUComputePassEncoder::SetBindGroupMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install pushDebugGroup configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"pushDebugGroup", V8GPUComputePassEncoder::PushDebugGroupMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install popDebugGroup configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"popDebugGroup", V8GPUComputePassEncoder::PopDebugGroupMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    {
      // Install insertDebugMarker configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"insertDebugMarker", V8GPUComputePassEncoder::InsertDebugMarkerMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
}

v8::Local<v8::FunctionTemplate> V8GPUComputePassEncoder::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8GPUComputePassEncoder::GetWrapperTypeInfo()),
      InstallV8GPUComputePassEncoderTemplate);
}

bool V8GPUComputePassEncoder::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8GPUComputePassEncoder::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8GPUComputePassEncoder::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8GPUComputePassEncoder::GetWrapperTypeInfo(), v8_value);
}

GPUComputePassEncoder* V8GPUComputePassEncoder::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
