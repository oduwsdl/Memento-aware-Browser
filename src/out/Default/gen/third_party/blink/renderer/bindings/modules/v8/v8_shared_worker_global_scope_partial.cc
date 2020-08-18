// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/partial_interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_shared_worker_global_scope_partial.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_shared_worker_global_scope.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_background_fetch_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_background_fetch_record.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_background_fetch_registration.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_barcode_detector.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_bidirectional_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_broadcast_channel.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_cache.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_cache_storage.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_canvas_gradient.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_canvas_pattern.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_close_event.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_compression_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_content_index.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_crypto.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_crypto_key.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_decompression_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_dom_file_system_sync.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_entry_callback.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_entry_sync.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_error_callback.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_event_source.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_face_detector.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_file_system_callback.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_file_system_directory_handle.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_file_system_file_handle.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_file_system_handle.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_file_system_writable_file_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_font_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_adapter.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_bind_group.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_bind_group_layout.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_buffer_usage.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_canvas_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_color_write.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_command_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_command_encoder.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_compute_pass_encoder.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_compute_pipeline.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_device.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_fence.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_out_of_memory_error.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_pipeline_layout.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_queue.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_bundle.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_bundle_encoder.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_pass_encoder.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_render_pipeline.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_sampler.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_shader_module.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_shader_stage.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_swap_chain.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_texture.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_texture_usage.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_texture_view.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_uncaptured_error_event.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_validation_error.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_cursor.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_cursor_with_value.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_database.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_factory.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_index.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_key_range.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_object_store.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_observation.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_observer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_observer_changes.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_open_db_request.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_request.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_transaction.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_idb_version_change_event.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_image_bitmap_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_image_decoder.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_lock.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_lock_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_media_capabilities.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_native_io_file.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_native_io_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_navigation_preload_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_network_information.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_notification.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_offscreen_canvas_rendering_context_2d.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_path_2d.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_payment_instruments.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_periodic_sync_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_permission_status.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_permissions.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_push_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_push_subscription.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_push_subscription_options.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_quic_transport.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_receive_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_send_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_service_worker_registration.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_storage_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_subtle_crypto.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_sync_manager.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_text_decoder.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_text_decoder_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_text_detector.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_text_encoder.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_text_encoder_stream.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_timestamp_trigger.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl2_compute_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl2_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_active_info.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_buffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_framebuffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_program.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_query.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_renderbuffer.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_rendering_context.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_sampler.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_shader.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_shader_precision_format.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_sync.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_texture.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_transform_feedback.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_uniform_location.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_webgl_vertex_array_object.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_websocket.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_websocket_stream.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/web_feature.h"
#include "third_party/blink/renderer/modules/cache_storage/global_cache_storage.h"
#include "third_party/blink/renderer/modules/crypto/worker_global_scope_crypto.h"
#include "third_party/blink/renderer/modules/filesystem/worker_global_scope_file_system.h"
#include "third_party/blink/renderer/modules/indexeddb/global_indexed_db.h"
#include "third_party/blink/renderer/modules/native_file_system/global_native_file_system.h"
#include "third_party/blink/renderer/modules/native_io/global_native_io.h"
#include "third_party/blink/renderer/modules/shared_worker_global_scope_modules_constructors.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/scheduler/public/cooperative_scheduling_manager.h"
#include "third_party/blink/renderer/platform/wtf/get_ptr.h"

namespace blink {

namespace shared_worker_global_scope_partial_v8_internal {

static void WebkitRequestFileSystemMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "SharedWorkerGlobalScope", "webkitRequestFileSystem");

  SharedWorkerGlobalScope* impl = V8SharedWorkerGlobalScope::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint16_t type;
  int64_t size;
  V8FileSystemCallback* success_callback;
  V8ErrorCallback* error_callback;
  type = NativeValueTraits<IDLUnsignedShort>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  size = NativeValueTraits<IDLLongLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  if (!info[2]->IsUndefined()) {
    if (info[2]->IsObject()) {
      success_callback = V8FileSystemCallback::Create(info[2].As<v8::Object>());
    } else if (info[2]->IsNullOrUndefined()) {
      success_callback = nullptr;
    } else {
      exception_state.ThrowTypeError("The callback provided as parameter 3 is not an object.");
      return;
    }
  } else {
    success_callback = nullptr;
  }
  if (!info[3]->IsUndefined()) {
    if (info[3]->IsObject()) {
      error_callback = V8ErrorCallback::Create(info[3].As<v8::Object>());
    } else if (info[3]->IsNullOrUndefined()) {
      error_callback = nullptr;
    } else {
      exception_state.ThrowTypeError("The callback provided as parameter 4 is not an object.");
      return;
    }
  } else {
    error_callback = nullptr;
  }

  WorkerGlobalScopeFileSystem::webkitRequestFileSystem(*impl, type, size, success_callback, error_callback);
}

static void WebkitRequestFileSystemSyncMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "SharedWorkerGlobalScope", "webkitRequestFileSystemSync");

  SharedWorkerGlobalScope* impl = V8SharedWorkerGlobalScope::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint16_t type;
  int64_t size;
  type = NativeValueTraits<IDLUnsignedShort>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  size = NativeValueTraits<IDLLongLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  DOMFileSystemSync* result = WorkerGlobalScopeFileSystem::webkitRequestFileSystemSync(*impl, type, size, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result);
}

static void WebkitResolveLocalFileSystemURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  SharedWorkerGlobalScope* impl = V8SharedWorkerGlobalScope::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("webkitResolveLocalFileSystemURL", "SharedWorkerGlobalScope", ExceptionMessages::NotEnoughArguments(2, info.Length())));
    return;
  }

  V8StringResource<> url;
  V8EntryCallback* success_callback;
  V8ErrorCallback* error_callback;
  url = info[0];
  if (!url.Prepare())
    return;

  if (info[1]->IsObject()) {
    success_callback = V8EntryCallback::Create(info[1].As<v8::Object>());
  } else {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("webkitResolveLocalFileSystemURL", "SharedWorkerGlobalScope", "The callback provided as parameter 2 is not an object."));
    return;
  }

  if (!info[2]->IsUndefined()) {
    if (info[2]->IsObject()) {
      error_callback = V8ErrorCallback::Create(info[2].As<v8::Object>());
    } else if (info[2]->IsNullOrUndefined()) {
      error_callback = nullptr;
    } else {
      V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("webkitResolveLocalFileSystemURL", "SharedWorkerGlobalScope", "The callback provided as parameter 3 is not an object."));
      return;
    }
  } else {
    error_callback = nullptr;
  }

  WorkerGlobalScopeFileSystem::webkitResolveLocalFileSystemURL(*impl, url, success_callback, error_callback);
}

static void WebkitResolveLocalFileSystemSyncURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "SharedWorkerGlobalScope", "webkitResolveLocalFileSystemSyncURL");

  SharedWorkerGlobalScope* impl = V8SharedWorkerGlobalScope::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  V8StringResource<> url;
  url = info[0];
  if (!url.Prepare())
    return;

  EntrySync* result = WorkerGlobalScopeFileSystem::webkitResolveLocalFileSystemSyncURL(*impl, url, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result);
}

}  // namespace shared_worker_global_scope_partial_v8_internal

void V8SharedWorkerGlobalScopePartial::BackgroundFetchManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_BackgroundFetchManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8BackgroundFetchManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::BackgroundFetchRecordConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_BackgroundFetchRecord_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8BackgroundFetchRecord::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::BackgroundFetchRegistrationConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_BackgroundFetchRegistration_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8BackgroundFetchRegistration::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::BarcodeDetectorConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_BarcodeDetector_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8BarcodeDetector::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::ContentIndexConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_ContentIndex_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8ContentIndex::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::FaceDetectorConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_FaceDetector_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8FaceDetector::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::FontManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_FontManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8FontManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBObservationConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBObservation_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBObservation::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBObserverChangesConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBObserverChanges_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBObserverChanges::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBObserverConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBObserver_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBObserver::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::FileSystemDirectoryHandleConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_FileSystemDirectoryHandle_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8FileSystemDirectoryHandle::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::FileSystemFileHandleConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_FileSystemFileHandle_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8FileSystemFileHandle::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::FileSystemHandleConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_FileSystemHandle_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8FileSystemHandle::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::FileSystemWritableFileStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_FileSystemWritableFileStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8FileSystemWritableFileStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::NativeIOFileConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_NativeIOFile_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8NativeIOFile::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::NativeIOManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_NativeIOManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8NativeIOManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::TimestampTriggerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_TimestampTrigger_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8TimestampTrigger::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::NotificationConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_Notification_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8Notification::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::PaymentInstrumentsConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_PaymentInstruments_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8PaymentInstruments::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::PeriodicSyncManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_PeriodicSyncManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8PeriodicSyncManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::PermissionStatusConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_PermissionStatus_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8PermissionStatus::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::PermissionsConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_Permissions_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8Permissions::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::PushManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_PushManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8PushManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::PushSubscriptionConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_PushSubscription_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8PushSubscription::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::PushSubscriptionOptionsConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_PushSubscriptionOptions_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8PushSubscriptionOptions::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::BidirectionalStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_BidirectionalStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8BidirectionalStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::QuicTransportConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_QuicTransport_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8QuicTransport::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::ReceiveStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_ReceiveStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8ReceiveStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::SendStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_SendStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8SendStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::OffscreenCanvasRenderingContext2DConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_OffscreenCanvasRenderingContext2D_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8OffscreenCanvasRenderingContext2D::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::TextDetectorConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_TextDetector_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8TextDetector::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::ImageDecoderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_ImageDecoder_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8ImageDecoder::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGL2ComputeRenderingContextConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGL2ComputeRenderingContext_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGL2ComputeRenderingContext::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUAdapterConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUAdapter_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUAdapter::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUBindGroupConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUBindGroup_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUBindGroup::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUBindGroupLayoutConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUBindGroupLayout_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUBindGroupLayout::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUBufferConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUBuffer_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUBuffer::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUBufferUsageConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUBufferUsage_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUBufferUsage::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUCanvasContextConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUCanvasContext_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUCanvasContext::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUColorWriteConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUColorWrite_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUColorWrite::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUCommandBufferConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUCommandBuffer_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUCommandBuffer::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUCommandEncoderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUCommandEncoder_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUCommandEncoder::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUComputePassEncoderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUComputePassEncoder_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUComputePassEncoder::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUComputePipelineConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUComputePipeline_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUComputePipeline::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPU_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPU::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUDeviceConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUDevice_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUDevice::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUFenceConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUFence_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUFence::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUOutOfMemoryErrorConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUOutOfMemoryError_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUOutOfMemoryError::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUPipelineLayoutConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUPipelineLayout_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUPipelineLayout::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUQueueConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUQueue_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUQueue::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPURenderBundleConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPURenderBundle_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPURenderBundle::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPURenderBundleEncoderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPURenderBundleEncoder_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPURenderBundleEncoder::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPURenderPassEncoderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPURenderPassEncoder_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPURenderPassEncoder::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPURenderPipelineConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPURenderPipeline_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPURenderPipeline::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUSamplerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUSampler_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUSampler::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUShaderModuleConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUShaderModule_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUShaderModule::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUShaderStageConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUShaderStage_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUShaderStage::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUSwapChainConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUSwapChain_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUSwapChain::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUTextureConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUTexture_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUTexture::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUTextureUsageConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUTextureUsage_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUTextureUsage::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUTextureViewConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUTextureView_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUTextureView::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUUncapturedErrorEventConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUUncapturedErrorEvent_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUUncapturedErrorEvent::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::GPUValidationErrorConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_GPUValidationError_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8GPUValidationError::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebSocketStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebSocketStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebSocketStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CacheConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_Cache_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8Cache::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CacheStorageConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_CacheStorage_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8CacheStorage::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CryptoKeyConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_CryptoKey_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8CryptoKey::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::LockConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_Lock_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8Lock::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::LockManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_LockManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8LockManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::NavigationPreloadManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_NavigationPreloadManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8NavigationPreloadManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::ServiceWorkerRegistrationConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_ServiceWorkerRegistration_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8ServiceWorkerRegistration::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::StorageManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_StorageManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8StorageManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::SubtleCryptoConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_SubtleCrypto_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8SubtleCrypto::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::BroadcastChannelConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_BroadcastChannel_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8BroadcastChannel::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CanvasGradientConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_CanvasGradient_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8CanvasGradient::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CanvasPatternConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_CanvasPattern_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8CanvasPattern::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CloseEventConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_CloseEvent_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8CloseEvent::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CompressionStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_CompressionStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8CompressionStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::CryptoConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_Crypto_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8Crypto::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::DecompressionStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_DecompressionStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8DecompressionStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::EventSourceConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_EventSource_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8EventSource::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBCursorConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBCursor_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBCursor::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBCursorWithValueConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBCursorWithValue_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBCursorWithValue::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBDatabaseConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBDatabase_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBDatabase::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBFactoryConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBFactory_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBFactory::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBIndexConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBIndex_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBIndex::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBKeyRangeConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBKeyRange_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBKeyRange::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBObjectStoreConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBObjectStore_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBObjectStore::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBOpenDBRequestConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBOpenDBRequest_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBOpenDBRequest::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBRequestConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBRequest_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBRequest::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBTransactionConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBTransaction_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBTransaction::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::IDBVersionChangeEventConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_IDBVersionChangeEvent_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8IDBVersionChangeEvent::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::ImageBitmapRenderingContextConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_ImageBitmapRenderingContext_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8ImageBitmapRenderingContext::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::MediaCapabilitiesConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_MediaCapabilities_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8MediaCapabilities::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::NetworkInformationConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_NetworkInformation_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8NetworkInformation::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::Path2DConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_Path2D_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8Path2D::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::SyncManagerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_SyncManager_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8SyncManager::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::TextDecoderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_TextDecoder_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8TextDecoder::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::TextDecoderStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_TextDecoderStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8TextDecoderStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::TextEncoderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_TextEncoder_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8TextEncoder::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::TextEncoderStreamConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_TextEncoderStream_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8TextEncoderStream::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGL2RenderingContextConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGL2RenderingContext_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGL2RenderingContext::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLActiveInfoConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLActiveInfo_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLActiveInfo::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLBufferConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLBuffer_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLBuffer::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLFramebufferConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLFramebuffer_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLFramebuffer::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLProgramConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLProgram_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLProgram::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLQueryConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLQuery_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLQuery::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLRenderbufferConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLRenderbuffer_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLRenderbuffer::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLRenderingContextConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLRenderingContext_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLRenderingContext::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLSamplerConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLSampler_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLSampler::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLShaderConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLShader_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLShader::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLShaderPrecisionFormatConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLShaderPrecisionFormat_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLShaderPrecisionFormat::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLSyncConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLSync_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLSync::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLTextureConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLTexture_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLTexture::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLTransformFeedbackConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLTransformFeedback_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLTransformFeedback::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLUniformLocationConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLUniformLocation_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLUniformLocation::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebGLVertexArrayObjectConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebGLVertexArrayObject_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebGLVertexArrayObject::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebSocketConstructorGetterCallback(
    v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_WebSocket_ConstructorGetterCallback");

  V8ConstructorAttributeGetter(property, info, V8WebSocket::GetWrapperTypeInfo());
}

void V8SharedWorkerGlobalScopePartial::WebkitRequestFileSystemMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("SharedWorkerGlobalScope.webkitRequestFileSystem");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_webkitRequestFileSystem");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kRequestFileSystemWorker);
  shared_worker_global_scope_partial_v8_internal::WebkitRequestFileSystemMethod(info);
}

void V8SharedWorkerGlobalScopePartial::WebkitRequestFileSystemSyncMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("SharedWorkerGlobalScope.webkitRequestFileSystemSync");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_webkitRequestFileSystemSync");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kRequestFileSystemSyncWorker);
  shared_worker_global_scope_partial_v8_internal::WebkitRequestFileSystemSyncMethod(info);
}

void V8SharedWorkerGlobalScopePartial::WebkitResolveLocalFileSystemURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("SharedWorkerGlobalScope.webkitResolveLocalFileSystemURL");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_webkitResolveLocalFileSystemURL");

  shared_worker_global_scope_partial_v8_internal::WebkitResolveLocalFileSystemURLMethod(info);
}

void V8SharedWorkerGlobalScopePartial::WebkitResolveLocalFileSystemSyncURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("SharedWorkerGlobalScope.webkitResolveLocalFileSystemSyncURL");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_SharedWorkerGlobalScope_webkitResolveLocalFileSystemSyncURL");

  shared_worker_global_scope_partial_v8_internal::WebkitResolveLocalFileSystemSyncURLMethod(info);
}

void V8SharedWorkerGlobalScopePartial::InstallV8SharedWorkerGlobalScopeTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8SharedWorkerGlobalScope::InstallV8SharedWorkerGlobalScopeTemplate(isolate, world, interface_template);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Global object prototype chain consists of Immutable Prototype Exotic Objects
  prototype_template->SetImmutableProto();

  // Global objects are Immutable Prototype Exotic Objects
  instance_template->SetImmutableProto();

  // Register IDL constants, attributes and operations.
  {
    static constexpr V8DOMConfiguration::ConstantConfiguration kConstants[] = {
        {"TEMPORARY", V8DOMConfiguration::kConstantTypeUnsignedShort, static_cast<int>(0)},
        {"PERSISTENT", V8DOMConfiguration::kConstantTypeUnsignedShort, static_cast<int>(1)},
    };
    V8DOMConfiguration::InstallConstants(
        isolate, interface_template, prototype_template,
        kConstants, base::size(kConstants));
  }
  static_assert(0 == WorkerGlobalScopeFileSystem::kTemporary, "the value of SharedWorkerGlobalScope_kTemporary does not match with implementation");
  static_assert(1 == WorkerGlobalScopeFileSystem::kPersistent, "the value of SharedWorkerGlobalScope_kPersistent does not match with implementation");
  static constexpr V8DOMConfiguration::AttributeConfiguration
  kAttributeConfigurations[] = {
      { "BroadcastChannel", V8SharedWorkerGlobalScopePartial::BroadcastChannelConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "CanvasGradient", V8SharedWorkerGlobalScopePartial::CanvasGradientConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "CanvasPattern", V8SharedWorkerGlobalScopePartial::CanvasPatternConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "CloseEvent", V8SharedWorkerGlobalScopePartial::CloseEventConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "CompressionStream", V8SharedWorkerGlobalScopePartial::CompressionStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "Crypto", V8SharedWorkerGlobalScopePartial::CryptoConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "DecompressionStream", V8SharedWorkerGlobalScopePartial::DecompressionStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "EventSource", V8SharedWorkerGlobalScopePartial::EventSourceConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBCursor", V8SharedWorkerGlobalScopePartial::IDBCursorConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBCursorWithValue", V8SharedWorkerGlobalScopePartial::IDBCursorWithValueConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBDatabase", V8SharedWorkerGlobalScopePartial::IDBDatabaseConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBFactory", V8SharedWorkerGlobalScopePartial::IDBFactoryConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBIndex", V8SharedWorkerGlobalScopePartial::IDBIndexConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBKeyRange", V8SharedWorkerGlobalScopePartial::IDBKeyRangeConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBObjectStore", V8SharedWorkerGlobalScopePartial::IDBObjectStoreConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBOpenDBRequest", V8SharedWorkerGlobalScopePartial::IDBOpenDBRequestConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBRequest", V8SharedWorkerGlobalScopePartial::IDBRequestConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBTransaction", V8SharedWorkerGlobalScopePartial::IDBTransactionConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "IDBVersionChangeEvent", V8SharedWorkerGlobalScopePartial::IDBVersionChangeEventConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "ImageBitmapRenderingContext", V8SharedWorkerGlobalScopePartial::ImageBitmapRenderingContextConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "MediaCapabilities", V8SharedWorkerGlobalScopePartial::MediaCapabilitiesConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "NetworkInformation", V8SharedWorkerGlobalScopePartial::NetworkInformationConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "Path2D", V8SharedWorkerGlobalScopePartial::Path2DConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "SyncManager", V8SharedWorkerGlobalScopePartial::SyncManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "TextDecoder", V8SharedWorkerGlobalScopePartial::TextDecoderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "TextDecoderStream", V8SharedWorkerGlobalScopePartial::TextDecoderStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "TextEncoder", V8SharedWorkerGlobalScopePartial::TextEncoderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "TextEncoderStream", V8SharedWorkerGlobalScopePartial::TextEncoderStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGL2RenderingContext", V8SharedWorkerGlobalScopePartial::WebGL2RenderingContextConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLActiveInfo", V8SharedWorkerGlobalScopePartial::WebGLActiveInfoConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLBuffer", V8SharedWorkerGlobalScopePartial::WebGLBufferConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLFramebuffer", V8SharedWorkerGlobalScopePartial::WebGLFramebufferConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLProgram", V8SharedWorkerGlobalScopePartial::WebGLProgramConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLQuery", V8SharedWorkerGlobalScopePartial::WebGLQueryConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLRenderbuffer", V8SharedWorkerGlobalScopePartial::WebGLRenderbufferConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLRenderingContext", V8SharedWorkerGlobalScopePartial::WebGLRenderingContextConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLSampler", V8SharedWorkerGlobalScopePartial::WebGLSamplerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLShader", V8SharedWorkerGlobalScopePartial::WebGLShaderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLShaderPrecisionFormat", V8SharedWorkerGlobalScopePartial::WebGLShaderPrecisionFormatConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLSync", V8SharedWorkerGlobalScopePartial::WebGLSyncConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLTexture", V8SharedWorkerGlobalScopePartial::WebGLTextureConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLTransformFeedback", V8SharedWorkerGlobalScopePartial::WebGLTransformFeedbackConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLUniformLocation", V8SharedWorkerGlobalScopePartial::WebGLUniformLocationConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebGLVertexArrayObject", V8SharedWorkerGlobalScopePartial::WebGLVertexArrayObjectConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "WebSocket", V8SharedWorkerGlobalScopePartial::WebSocketConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAttributes(
      isolate, world, instance_template, prototype_template,
      kAttributeConfigurations, base::size(kAttributeConfigurations));

  // Custom signature

  V8SharedWorkerGlobalScopePartial::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8SharedWorkerGlobalScopePartial::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  V8SharedWorkerGlobalScope::InstallRuntimeEnabledFeaturesOnTemplate(isolate, world, interface_template);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  if (RuntimeEnabledFeatures::BackgroundFetchEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "BackgroundFetchManager", V8SharedWorkerGlobalScopePartial::BackgroundFetchManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "BackgroundFetchRecord", V8SharedWorkerGlobalScopePartial::BackgroundFetchRecordConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "BackgroundFetchRegistration", V8SharedWorkerGlobalScopePartial::BackgroundFetchRegistrationConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::ContentIndexEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "ContentIndex", V8SharedWorkerGlobalScopePartial::ContentIndexConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::IDBObserverEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "IDBObservation", V8SharedWorkerGlobalScopePartial::IDBObservationConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "IDBObserver", V8SharedWorkerGlobalScopePartial::IDBObserverConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "IDBObserverChanges", V8SharedWorkerGlobalScopePartial::IDBObserverChangesConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::NotificationsEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "Notification", V8SharedWorkerGlobalScopePartial::NotificationConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::PaymentAppEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "PaymentInstruments", V8SharedWorkerGlobalScopePartial::PaymentInstrumentsConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::PeriodicBackgroundSyncEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "PeriodicSyncManager", V8SharedWorkerGlobalScopePartial::PeriodicSyncManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::PermissionsEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "Permissions", V8SharedWorkerGlobalScopePartial::PermissionsConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "PermissionStatus", V8SharedWorkerGlobalScopePartial::PermissionStatusConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::PushMessagingEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "PushManager", V8SharedWorkerGlobalScopePartial::PushManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "PushSubscription", V8SharedWorkerGlobalScopePartial::PushSubscriptionConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "PushSubscriptionOptions", V8SharedWorkerGlobalScopePartial::PushSubscriptionOptionsConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::SurfaceEmbeddingFeaturesEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "OffscreenCanvasRenderingContext2D", V8SharedWorkerGlobalScopePartial::OffscreenCanvasRenderingContext2DConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::WebCodecsEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "ImageDecoder", V8SharedWorkerGlobalScopePartial::ImageDecoderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::WebGL2ComputeContextEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "WebGL2ComputeRenderingContext", V8SharedWorkerGlobalScopePartial::WebGL2ComputeRenderingContextConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::WebGPUEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "GPU", V8SharedWorkerGlobalScopePartial::GPUConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUAdapter", V8SharedWorkerGlobalScopePartial::GPUAdapterConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUBindGroup", V8SharedWorkerGlobalScopePartial::GPUBindGroupConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUBindGroupLayout", V8SharedWorkerGlobalScopePartial::GPUBindGroupLayoutConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUBuffer", V8SharedWorkerGlobalScopePartial::GPUBufferConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUBufferUsage", V8SharedWorkerGlobalScopePartial::GPUBufferUsageConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUCanvasContext", V8SharedWorkerGlobalScopePartial::GPUCanvasContextConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUColorWrite", V8SharedWorkerGlobalScopePartial::GPUColorWriteConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUCommandBuffer", V8SharedWorkerGlobalScopePartial::GPUCommandBufferConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUCommandEncoder", V8SharedWorkerGlobalScopePartial::GPUCommandEncoderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUComputePassEncoder", V8SharedWorkerGlobalScopePartial::GPUComputePassEncoderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUComputePipeline", V8SharedWorkerGlobalScopePartial::GPUComputePipelineConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUDevice", V8SharedWorkerGlobalScopePartial::GPUDeviceConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUFence", V8SharedWorkerGlobalScopePartial::GPUFenceConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUOutOfMemoryError", V8SharedWorkerGlobalScopePartial::GPUOutOfMemoryErrorConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUPipelineLayout", V8SharedWorkerGlobalScopePartial::GPUPipelineLayoutConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUQueue", V8SharedWorkerGlobalScopePartial::GPUQueueConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPURenderBundle", V8SharedWorkerGlobalScopePartial::GPURenderBundleConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPURenderBundleEncoder", V8SharedWorkerGlobalScopePartial::GPURenderBundleEncoderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPURenderPassEncoder", V8SharedWorkerGlobalScopePartial::GPURenderPassEncoderConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPURenderPipeline", V8SharedWorkerGlobalScopePartial::GPURenderPipelineConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUSampler", V8SharedWorkerGlobalScopePartial::GPUSamplerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUShaderModule", V8SharedWorkerGlobalScopePartial::GPUShaderModuleConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUShaderStage", V8SharedWorkerGlobalScopePartial::GPUShaderStageConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUSwapChain", V8SharedWorkerGlobalScopePartial::GPUSwapChainConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUTexture", V8SharedWorkerGlobalScopePartial::GPUTextureConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUTextureUsage", V8SharedWorkerGlobalScopePartial::GPUTextureUsageConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUTextureView", V8SharedWorkerGlobalScopePartial::GPUTextureViewConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUUncapturedErrorEvent", V8SharedWorkerGlobalScopePartial::GPUUncapturedErrorEventConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "GPUValidationError", V8SharedWorkerGlobalScopePartial::GPUValidationErrorConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
  if (RuntimeEnabledFeatures::WebSocketStreamEnabled()) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "WebSocketStream", V8SharedWorkerGlobalScopePartial::WebSocketStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance_template, prototype_template,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }

  // Custom signature
  if (RuntimeEnabledFeatures::FileSystemEnabled()) {
    {
      // Install webkitRequestFileSystem configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"webkitRequestFileSystem", V8SharedWorkerGlobalScopePartial::WebkitRequestFileSystemMethodCallback, 2, v8::None, V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::FileSystemEnabled()) {
    {
      // Install webkitRequestFileSystemSync configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"webkitRequestFileSystemSync", V8SharedWorkerGlobalScopePartial::WebkitRequestFileSystemSyncMethodCallback, 2, v8::None, V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::FileSystemEnabled()) {
    {
      // Install webkitResolveLocalFileSystemURL configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"webkitResolveLocalFileSystemURL", V8SharedWorkerGlobalScopePartial::WebkitResolveLocalFileSystemURLMethodCallback, 2, v8::None, V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
  if (RuntimeEnabledFeatures::FileSystemEnabled()) {
    {
      // Install webkitResolveLocalFileSystemSyncURL configuration
      constexpr V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
          {"webkitResolveLocalFileSystemSyncURL", V8SharedWorkerGlobalScopePartial::WebkitResolveLocalFileSystemSyncURLMethodCallback, 1, v8::None, V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
      };
      for (const auto& config : kConfigurations) {
        V8DOMConfiguration::InstallMethod(
            isolate, world, instance_template, prototype_template,
            interface_template, signature, config);
      }
    }
  }
}

void V8SharedWorkerGlobalScopePartial::InstallQuicTransport(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance,
    v8::Local<v8::Object> prototype,
    v8::Local<v8::Function> interface) {
  v8::Local<v8::FunctionTemplate> interface_template =
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo()->DomTemplate(isolate, world);
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  static constexpr V8DOMConfiguration::AttributeConfiguration
  kAttributeConfigurations[] = {
      { "BidirectionalStream", V8SharedWorkerGlobalScopePartial::BidirectionalStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "QuicTransport", V8SharedWorkerGlobalScopePartial::QuicTransportConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "ReceiveStream", V8SharedWorkerGlobalScopePartial::ReceiveStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      { "SendStream", V8SharedWorkerGlobalScopePartial::SendStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAttributes(
      isolate, world, instance, prototype,
      kAttributeConfigurations, base::size(kAttributeConfigurations));
}

void V8SharedWorkerGlobalScopePartial::InstallQuicTransport(
    ScriptState* script_state, v8::Local<v8::Object> instance) {
  V8PerContextData* per_context_data = script_state->PerContextData();
  v8::Local<v8::Object> prototype = per_context_data->PrototypeForType(
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo());
  v8::Local<v8::Function> interface = per_context_data->ConstructorForType(
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo());
  ALLOW_UNUSED_LOCAL(interface);
  InstallQuicTransport(script_state->GetIsolate(), script_state->World(), instance, prototype, interface);
}

void V8SharedWorkerGlobalScopePartial::InstallNativeFileSystem(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance,
    v8::Local<v8::Object> prototype,
    v8::Local<v8::Function> interface) {
  v8::Local<v8::FunctionTemplate> interface_template =
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo()->DomTemplate(isolate, world);
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  ExecutionContext* execution_context = ToExecutionContext(isolate->GetCurrentContext());
  bool is_secure_context = (execution_context && execution_context->IsSecureContext());
  if (is_secure_context) {
    static constexpr V8DOMConfiguration::AttributeConfiguration
    kAttributeConfigurations[] = {
        { "FileSystemDirectoryHandle", V8SharedWorkerGlobalScopePartial::FileSystemDirectoryHandleConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "FileSystemFileHandle", V8SharedWorkerGlobalScopePartial::FileSystemFileHandleConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "FileSystemHandle", V8SharedWorkerGlobalScopePartial::FileSystemHandleConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        { "FileSystemWritableFileStream", V8SharedWorkerGlobalScopePartial::FileSystemWritableFileStreamConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAttributes(
        isolate, world, instance, prototype,
        kAttributeConfigurations, base::size(kAttributeConfigurations));
  }
}

void V8SharedWorkerGlobalScopePartial::InstallNativeFileSystem(
    ScriptState* script_state, v8::Local<v8::Object> instance) {
  V8PerContextData* per_context_data = script_state->PerContextData();
  v8::Local<v8::Object> prototype = per_context_data->PrototypeForType(
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo());
  v8::Local<v8::Function> interface = per_context_data->ConstructorForType(
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo());
  ALLOW_UNUSED_LOCAL(interface);
  InstallNativeFileSystem(script_state->GetIsolate(), script_state->World(), instance, prototype, interface);
}

void V8SharedWorkerGlobalScopePartial::InstallNotificationTriggers(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance,
    v8::Local<v8::Object> prototype,
    v8::Local<v8::Function> interface) {
  v8::Local<v8::FunctionTemplate> interface_template =
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo()->DomTemplate(isolate, world);
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  static constexpr V8DOMConfiguration::AttributeConfiguration
  kAttributeConfigurations[] = {
      { "TimestampTrigger", V8SharedWorkerGlobalScopePartial::TimestampTriggerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAttributes(
      isolate, world, instance, prototype,
      kAttributeConfigurations, base::size(kAttributeConfigurations));
}

void V8SharedWorkerGlobalScopePartial::InstallNotificationTriggers(
    ScriptState* script_state, v8::Local<v8::Object> instance) {
  V8PerContextData* per_context_data = script_state->PerContextData();
  v8::Local<v8::Object> prototype = per_context_data->PrototypeForType(
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo());
  v8::Local<v8::Function> interface = per_context_data->ConstructorForType(
      V8SharedWorkerGlobalScope::GetWrapperTypeInfo());
  ALLOW_UNUSED_LOCAL(interface);
  InstallNotificationTriggers(script_state->GetIsolate(), script_state->World(), instance, prototype, interface);
}

void V8SharedWorkerGlobalScopePartial::InstallConditionalFeatures(
    v8::Local<v8::Context> context,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance_object,
    v8::Local<v8::Object> prototype_object,
    v8::Local<v8::Function> interface_object,
    v8::Local<v8::FunctionTemplate> interface_template) {
  CHECK(!interface_template.IsEmpty());
  DCHECK((!prototype_object.IsEmpty() && !interface_object.IsEmpty()) ||
         !instance_object.IsEmpty());
  V8SharedWorkerGlobalScope::InstallConditionalFeatures(
      context, world, instance_object, prototype_object, interface_object, interface_template);

  v8::Isolate* isolate = context->GetIsolate();

  ExecutionContext* execution_context = ToExecutionContext(context);
  DCHECK(execution_context);
  bool is_secure_context = (execution_context && execution_context->IsSecureContext());

  if (!instance_object.IsEmpty()) {
    if (is_secure_context) {
      static constexpr V8DOMConfiguration::AttributeConfiguration
      kAttributeConfigurations[] = {
          { "Cache", V8SharedWorkerGlobalScopePartial::CacheConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "CacheStorage", V8SharedWorkerGlobalScopePartial::CacheStorageConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "CryptoKey", V8SharedWorkerGlobalScopePartial::CryptoKeyConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "Lock", V8SharedWorkerGlobalScopePartial::LockConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "LockManager", V8SharedWorkerGlobalScopePartial::LockManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "NavigationPreloadManager", V8SharedWorkerGlobalScopePartial::NavigationPreloadManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "ServiceWorkerRegistration", V8SharedWorkerGlobalScopePartial::ServiceWorkerRegistrationConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "StorageManager", V8SharedWorkerGlobalScopePartial::StorageManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
          { "SubtleCrypto", V8SharedWorkerGlobalScopePartial::SubtleCryptoConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
      };
      V8DOMConfiguration::InstallAttributes(
          isolate, world, instance_object, prototype_object,
          kAttributeConfigurations, base::size(kAttributeConfigurations));

      if (RuntimeEnabledFeatures::BarcodeDetectorEnabled()) {
        static constexpr V8DOMConfiguration::AttributeConfiguration
        kAttributeConfigurations[] = {
            { "BarcodeDetector", V8SharedWorkerGlobalScopePartial::BarcodeDetectorConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        };
        V8DOMConfiguration::InstallAttributes(
            isolate, world, instance_object, prototype_object,
            kAttributeConfigurations, base::size(kAttributeConfigurations));
      }
      if (RuntimeEnabledFeatures::FaceDetectorEnabled()) {
        static constexpr V8DOMConfiguration::AttributeConfiguration
        kAttributeConfigurations[] = {
            { "FaceDetector", V8SharedWorkerGlobalScopePartial::FaceDetectorConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        };
        V8DOMConfiguration::InstallAttributes(
            isolate, world, instance_object, prototype_object,
            kAttributeConfigurations, base::size(kAttributeConfigurations));
      }
      if (RuntimeEnabledFeatures::FontAccessEnabled()) {
        static constexpr V8DOMConfiguration::AttributeConfiguration
        kAttributeConfigurations[] = {
            { "FontManager", V8SharedWorkerGlobalScopePartial::FontManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        };
        V8DOMConfiguration::InstallAttributes(
            isolate, world, instance_object, prototype_object,
            kAttributeConfigurations, base::size(kAttributeConfigurations));
      }
      if (RuntimeEnabledFeatures::NativeIOEnabled()) {
        static constexpr V8DOMConfiguration::AttributeConfiguration
        kAttributeConfigurations[] = {
            { "NativeIOFile", V8SharedWorkerGlobalScopePartial::NativeIOFileConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
            { "NativeIOManager", V8SharedWorkerGlobalScopePartial::NativeIOManagerConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        };
        V8DOMConfiguration::InstallAttributes(
            isolate, world, instance_object, prototype_object,
            kAttributeConfigurations, base::size(kAttributeConfigurations));
      }
      if (RuntimeEnabledFeatures::TextDetectorEnabled()) {
        static constexpr V8DOMConfiguration::AttributeConfiguration
        kAttributeConfigurations[] = {
            { "TextDetector", V8SharedWorkerGlobalScopePartial::TextDetectorConstructorGetterCallback, nullptr, static_cast<v8::PropertyAttribute>(v8::DontEnum), V8DOMConfiguration::kOnInstance, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kReplaceWithDataProperty, V8DOMConfiguration::kAllWorlds },
        };
        V8DOMConfiguration::InstallAttributes(
            isolate, world, instance_object, prototype_object,
            kAttributeConfigurations, base::size(kAttributeConfigurations));
      }
    }
  }
}

void V8SharedWorkerGlobalScopePartial::Initialize() {
  // Should be invoked from ModulesInitializer.
  V8SharedWorkerGlobalScope::UpdateWrapperTypeInfo(
      &V8SharedWorkerGlobalScopePartial::InstallV8SharedWorkerGlobalScopeTemplate,
      nullptr,
      &V8SharedWorkerGlobalScopePartial::InstallRuntimeEnabledFeaturesOnTemplate,
      V8SharedWorkerGlobalScopePartial::InstallConditionalFeatures);
}

}  // namespace blink
