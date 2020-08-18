// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_bundle_encoder.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_uint32_array.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_bind_group.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_bundle.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_bundle_descriptor.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_pipeline.h"
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
const WrapperTypeInfo v8_gpu_render_bundle_encoder_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8GPURenderBundleEncoder::DomTemplate,
    nullptr,
    "GPURenderBundleEncoder",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in GPURenderBundleEncoder.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& GPURenderBundleEncoder::wrapper_type_info_ = v8_gpu_render_bundle_encoder_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, GPURenderBundleEncoder>::value,
    "GPURenderBundleEncoder inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&GPURenderBundleEncoder::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "GPURenderBundleEncoder is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace gpu_render_bundle_encoder_v8_internal {

static void FinishMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "finish");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

  GPURenderBundleDescriptor* descriptor;
  if (!info[0]->IsNullOrUndefined() && !info[0]->IsObject()) {
    exception_state.ThrowTypeError("parameter 1 ('descriptor') is not an object.");
    return;
  }
  descriptor = NativeValueTraits<GPURenderBundleDescriptor>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  V8SetReturnValue(info, impl->finish(descriptor));
}

static void SetBindGroup1Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "setBindGroup");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

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
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "setBindGroup");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

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

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "setBindGroup");
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
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "pushDebugGroup");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

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
  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

  impl->popDebugGroup();
}

static void InsertDebugMarkerMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "insertDebugMarker");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

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

static void SetPipelineMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setPipeline", "GPURenderBundleEncoder", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  GPURenderPipeline* pipeline;
  pipeline = V8GPURenderPipeline::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!pipeline) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setPipeline", "GPURenderBundleEncoder", ExceptionMessages::ArgumentNotOfType(0, "GPURenderPipeline")));
    return;
  }

  impl->setPipeline(pipeline);
}

static void SetIndexBufferMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "setIndexBuffer");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  GPUBuffer* buffer;
  uint64_t offset;
  uint64_t size;
  buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUBuffer"));
    return;
  }

  if (!info[1]->IsUndefined()) {
    offset = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    offset = 0;
  }
  if (!info[2]->IsUndefined()) {
    size = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    size = 0;
  }

  impl->setIndexBuffer(buffer, offset, size);
}

static void SetVertexBufferMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "setVertexBuffer");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint32_t slot;
  GPUBuffer* buffer;
  uint64_t offset;
  uint64_t size;
  slot = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "GPUBuffer"));
    return;
  }

  if (!info[2]->IsUndefined()) {
    offset = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    offset = 0;
  }
  if (!info[3]->IsUndefined()) {
    size = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[3], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    size = 0;
  }

  impl->setVertexBuffer(slot, buffer, offset, size);
}

static void DrawMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "draw");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  uint32_t vertex_count;
  uint32_t instance_count;
  uint32_t first_vertex;
  uint32_t first_instance;
  vertex_count = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  if (!info[1]->IsUndefined()) {
    instance_count = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    instance_count = 1u;
  }
  if (!info[2]->IsUndefined()) {
    first_vertex = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    first_vertex = 0u;
  }
  if (!info[3]->IsUndefined()) {
    first_instance = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[3], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    first_instance = 0u;
  }

  impl->draw(vertex_count, instance_count, first_vertex, first_instance);
}

static void DrawIndexedMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "drawIndexed");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  uint32_t index_count;
  uint32_t instance_count;
  uint32_t first_index;
  int32_t base_vertex;
  uint32_t first_instance;
  index_count = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  if (!info[1]->IsUndefined()) {
    instance_count = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    instance_count = 1u;
  }
  if (!info[2]->IsUndefined()) {
    first_index = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[2], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    first_index = 0u;
  }
  if (!info[3]->IsUndefined()) {
    base_vertex = NativeValueTraits<IDLLongEnforceRange>::NativeValue(info.GetIsolate(), info[3], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    base_vertex = 0;
  }
  if (!info[4]->IsUndefined()) {
    first_instance = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(info.GetIsolate(), info[4], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    first_instance = 0u;
  }

  impl->drawIndexed(index_count, instance_count, first_index, base_vertex, first_instance);
}

static void DrawIndirectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "drawIndirect");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

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

  impl->drawIndirect(indirect_buffer, indirect_offset);
}

static void DrawIndexedIndirectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPURenderBundleEncoder", "drawIndexedIndirect");

  GPURenderBundleEncoder* impl = V8GPURenderBundleEncoder::ToImpl(info.Holder());

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

  impl->drawIndexedIndirect(indirect_buffer, indirect_offset);
}

}  // namespace gpu_render_bundle_encoder_v8_internal

void V8GPURenderBundleEncoder::FinishMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.finish");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_finish");

  gpu_render_bundle_encoder_v8_internal::FinishMethod(info);
}

void V8GPURenderBundleEncoder::SetBindGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.setBindGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_setBindGroup");

  gpu_render_bundle_encoder_v8_internal::SetBindGroupMethod(info);
}

void V8GPURenderBundleEncoder::PushDebugGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.pushDebugGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_pushDebugGroup");

  gpu_render_bundle_encoder_v8_internal::PushDebugGroupMethod(info);
}

void V8GPURenderBundleEncoder::PopDebugGroupMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.popDebugGroup");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_popDebugGroup");

  gpu_render_bundle_encoder_v8_internal::PopDebugGroupMethod(info);
}

void V8GPURenderBundleEncoder::InsertDebugMarkerMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.insertDebugMarker");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_insertDebugMarker");

  gpu_render_bundle_encoder_v8_internal::InsertDebugMarkerMethod(info);
}

void V8GPURenderBundleEncoder::SetPipelineMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.setPipeline");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_setPipeline");

  gpu_render_bundle_encoder_v8_internal::SetPipelineMethod(info);
}

void V8GPURenderBundleEncoder::SetIndexBufferMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.setIndexBuffer");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_setIndexBuffer");

  gpu_render_bundle_encoder_v8_internal::SetIndexBufferMethod(info);
}

void V8GPURenderBundleEncoder::SetVertexBufferMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.setVertexBuffer");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_setVertexBuffer");

  gpu_render_bundle_encoder_v8_internal::SetVertexBufferMethod(info);
}

void V8GPURenderBundleEncoder::DrawMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.draw");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_draw");

  gpu_render_bundle_encoder_v8_internal::DrawMethod(info);
}

void V8GPURenderBundleEncoder::DrawIndexedMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.drawIndexed");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_drawIndexed");

  gpu_render_bundle_encoder_v8_internal::DrawIndexedMethod(info);
}

void V8GPURenderBundleEncoder::DrawIndirectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.drawIndirect");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_drawIndirect");

  gpu_render_bundle_encoder_v8_internal::DrawIndirectMethod(info);
}

void V8GPURenderBundleEncoder::DrawIndexedIndirectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPURenderBundleEncoder.drawIndexedIndirect");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPURenderBundleEncoder_drawIndexedIndirect");

  gpu_render_bundle_encoder_v8_internal::DrawIndexedIndirectMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8GPURenderBundleEncoderMethods[] = {
    {"finish", V8GPURenderBundleEncoder::FinishMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8GPURenderBundleEncoderTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8GPURenderBundleEncoder::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8GPURenderBundleEncoder::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8GPURenderBundleEncoderMethods, base::size(kV8GPURenderBundleEncoderMethods));

  // Custom signature

  V8GPURenderBundleEncoder::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8GPURenderBundleEncoder::InstallRuntimeEnabledFeaturesOnTemplate(
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
          {"setBindGroup", V8GPURenderBundleEncoder::SetBindGroupMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
          {"pushDebugGroup", V8GPURenderBundleEncoder::PushDebugGroupMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
          {"popDebugGroup", V8GPURenderBundleEncoder::PopDebugGroupMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
          {"insertDebugMarker", V8GPURenderBundleEncoder::InsertDebugMarkerMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
      // Install setPipeline configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setPipeline", V8GPURenderBundleEncoder::SetPipelineMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
      // Install setIndexBuffer configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setIndexBuffer", V8GPURenderBundleEncoder::SetIndexBufferMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
      // Install setVertexBuffer configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"setVertexBuffer", V8GPURenderBundleEncoder::SetVertexBufferMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
      // Install draw configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"draw", V8GPURenderBundleEncoder::DrawMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
      // Install drawIndexed configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"drawIndexed", V8GPURenderBundleEncoder::DrawIndexedMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
      // Install drawIndirect configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"drawIndirect", V8GPURenderBundleEncoder::DrawIndirectMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
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
      // Install drawIndexedIndirect configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"drawIndexedIndirect", V8GPURenderBundleEncoder::DrawIndexedIndirectMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
}

v8::Local<v8::FunctionTemplate> V8GPURenderBundleEncoder::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8GPURenderBundleEncoder::GetWrapperTypeInfo()),
      InstallV8GPURenderBundleEncoderTemplate);
}

bool V8GPURenderBundleEncoder::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8GPURenderBundleEncoder::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8GPURenderBundleEncoder::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8GPURenderBundleEncoder::GetWrapperTypeInfo(), v8_value);
}

GPURenderBundleEncoder* V8GPURenderBundleEncoder::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
