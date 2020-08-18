// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_queue.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_command_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_extent_3d_dict.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_fence.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_fence_descriptor.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_image_bitmap_copy_view.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_texture_copy_view.h"
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
const WrapperTypeInfo v8_gpu_queue_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8GPUQueue::DomTemplate,
    nullptr,
    "GPUQueue",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in GPUQueue.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& GPUQueue::wrapper_type_info_ = v8_gpu_queue_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, GPUQueue>::value,
    "GPUQueue inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&GPUQueue::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "GPUQueue is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace gpu_queue_v8_internal {

static void SubmitMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUQueue", "submit");

  GPUQueue* impl = V8GPUQueue::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  HeapVector<Member<GPUCommandBuffer>> buffers;
  buffers = NativeValueTraits<IDLSequence<GPUCommandBuffer>>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->submit(buffers);
}

static void CreateFenceMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUQueue", "createFence");

  GPUQueue* impl = V8GPUQueue::ToImpl(info.Holder());

  GPUFenceDescriptor* descriptor;
  if (!info[0]->IsNullOrUndefined() && !info[0]->IsObject()) {
    exception_state.ThrowTypeError("parameter 1 ('descriptor') is not an object.");
    return;
  }
  descriptor = NativeValueTraits<GPUFenceDescriptor>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  V8SetReturnValue(info, impl->createFence(descriptor));
}

static void SignalMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUQueue", "signal");

  GPUQueue* impl = V8GPUQueue::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  GPUFence* fence;
  uint64_t signal_value;
  fence = V8GPUFence::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!fence) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUFence"));
    return;
  }

  signal_value = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->signal(fence, signal_value);
}

static void WriteBuffer1Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUQueue", "writeBuffer");

  GPUQueue* impl = V8GPUQueue::ToImpl(info.Holder());

  GPUBuffer* buffer;
  uint64_t buffer_offset;
  MaybeShared<DOMArrayBufferView> data;
  uint64_t data_byte_offset;
  uint64_t byte_size;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUBuffer"));
    return;
  }

  buffer_offset = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  data = ToMaybeShared<MaybeShared<DOMArrayBufferView>>(info.GetIsolate(), info[2], exception_state);
  if (exception_state.HadException())
    return;
  if (!data) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(2, "ArrayBufferView"));
    return;
  }

  if (!info[3]->IsUndefined()) {
    data_byte_offset = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[3], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    data_byte_offset = 0;
  }
  if (UNLIKELY(num_args_passed <= 4)) {
    impl->writeBuffer(buffer, buffer_offset, data, data_byte_offset, exception_state);
    if (exception_state.HadException()) {
      return;
    }
    return;
  }
  byte_size = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  impl->writeBuffer(buffer, buffer_offset, data, data_byte_offset, byte_size, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void WriteBuffer2Method(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUQueue", "writeBuffer");

  GPUQueue* impl = V8GPUQueue::ToImpl(info.Holder());

  GPUBuffer* buffer;
  uint64_t buffer_offset;
  DOMArrayBuffer* data;
  uint64_t data_byte_offset;
  uint64_t byte_size;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  buffer = V8GPUBuffer::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!buffer) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "GPUBuffer"));
    return;
  }

  buffer_offset = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  data = info[2]->IsArrayBuffer() ? V8ArrayBuffer::ToImpl(v8::Local<v8::ArrayBuffer>::Cast(info[2])) : 0;
  if (!data) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(2, "ArrayBuffer"));
    return;
  }

  if (!info[3]->IsUndefined()) {
    data_byte_offset = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[3], exception_state);
    if (exception_state.HadException())
      return;
  } else {
    data_byte_offset = 0;
  }
  if (UNLIKELY(num_args_passed <= 4)) {
    impl->writeBuffer(buffer, buffer_offset, data, data_byte_offset, exception_state);
    if (exception_state.HadException()) {
      return;
    }
    return;
  }
  byte_size = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(info.GetIsolate(), info[4], exception_state);
  if (exception_state.HadException())
    return;

  impl->writeBuffer(buffer, buffer_offset, data, data_byte_offset, byte_size, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void WriteBufferMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  scheduler::CooperativeSchedulingManager::Instance()->Safepoint();

  bool is_arity_error = false;

  switch (std::min(5, info.Length())) {
    case 3:
      if (info[2]->IsArrayBufferView()) {
        WriteBuffer1Method(info);
        return;
      }
      if (info[2]->IsArrayBuffer()) {
        WriteBuffer2Method(info);
        return;
      }
      break;
    case 4:
      if (info[2]->IsArrayBufferView()) {
        WriteBuffer1Method(info);
        return;
      }
      if (info[2]->IsArrayBuffer()) {
        WriteBuffer2Method(info);
        return;
      }
      break;
    case 5:
      if (info[2]->IsArrayBufferView()) {
        WriteBuffer1Method(info);
        return;
      }
      if (info[2]->IsArrayBuffer()) {
        WriteBuffer2Method(info);
        return;
      }
      break;
    default:
      is_arity_error = true;
  }

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUQueue", "writeBuffer");
  if (is_arity_error) {
    if (info.Length() < 3) {
      exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(3, info.Length()));
      return;
    }
  }
  exception_state.ThrowTypeError("No function was found that matched the signature provided.");
}

static void CopyImageBitmapToTextureMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "GPUQueue", "copyImageBitmapToTexture");

  GPUQueue* impl = V8GPUQueue::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 3)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(3, info.Length()));
    return;
  }

  GPUImageBitmapCopyView* source;
  GPUTextureCopyView* destination;
  UnsignedLongEnforceRangeSequenceOrGPUExtent3DDict copy_size;
  if (!info[0]->IsNullOrUndefined() && !info[0]->IsObject()) {
    exception_state.ThrowTypeError("parameter 1 ('source') is not an object.");
    return;
  }
  source = NativeValueTraits<GPUImageBitmapCopyView>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  if (!info[1]->IsNullOrUndefined() && !info[1]->IsObject()) {
    exception_state.ThrowTypeError("parameter 2 ('destination') is not an object.");
    return;
  }
  destination = NativeValueTraits<GPUTextureCopyView>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  V8UnsignedLongEnforceRangeSequenceOrGPUExtent3DDict::ToImpl(info.GetIsolate(), info[2], copy_size, UnionTypeConversionMode::kNotNullable, exception_state);
  if (exception_state.HadException())
    return;

  impl->copyImageBitmapToTexture(source, destination, copy_size, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

}  // namespace gpu_queue_v8_internal

void V8GPUQueue::SubmitMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUQueue.submit");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUQueue_submit");

  gpu_queue_v8_internal::SubmitMethod(info);
}

void V8GPUQueue::CreateFenceMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUQueue.createFence");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUQueue_createFence");

  gpu_queue_v8_internal::CreateFenceMethod(info);
}

void V8GPUQueue::SignalMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUQueue.signal");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUQueue_signal");

  gpu_queue_v8_internal::SignalMethod(info);
}

void V8GPUQueue::WriteBufferMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUQueue.writeBuffer");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUQueue_writeBuffer");

  gpu_queue_v8_internal::WriteBufferMethod(info);
}

void V8GPUQueue::CopyImageBitmapToTextureMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("GPUQueue.copyImageBitmapToTexture");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_GPUQueue_copyImageBitmapToTexture");

  gpu_queue_v8_internal::CopyImageBitmapToTextureMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8GPUQueueMethods[] = {
    {"submit", V8GPUQueue::SubmitMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"createFence", V8GPUQueue::CreateFenceMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"signal", V8GPUQueue::SignalMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"writeBuffer", V8GPUQueue::WriteBufferMethodCallback, 3, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"copyImageBitmapToTexture", V8GPUQueue::CopyImageBitmapToTextureMethodCallback, 3, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8GPUQueueTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8GPUQueue::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8GPUQueue::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8GPUQueueMethods, base::size(kV8GPUQueueMethods));

  // Custom signature

  V8GPUQueue::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8GPUQueue::InstallRuntimeEnabledFeaturesOnTemplate(
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

v8::Local<v8::FunctionTemplate> V8GPUQueue::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8GPUQueue::GetWrapperTypeInfo()),
      InstallV8GPUQueueTemplate);
}

bool V8GPUQueue::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8GPUQueue::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8GPUQueue::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8GPUQueue::GetWrapperTypeInfo(), v8_value);
}

GPUQueue* V8GPUQueue::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
