// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/origin_trial_features_for_modules.cc.tmpl
// by the script generate_origin_trial_features.py.
// DO NOT MODIFY!

// clang-format off

#include "third_party/blink/renderer/bindings/modules/v8/origin_trial_features_for_modules.h"

#include "third_party/blink/renderer/bindings/core/v8/origin_trial_features_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dedicated_worker_global_scope.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_video_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_navigator.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_shared_worker_global_scope.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_window.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_worker_global_scope.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_worker_navigator.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_dedicated_worker_global_scope_partial.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_file_system_directory_handle.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_html_video_element_partial.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_navigator_partial.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_notification.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_ice_transport.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_rtp_receiver.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_rtp_sender.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_service_worker_global_scope.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_service_worker_registration.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_shared_worker_global_scope_partial.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_window_partial.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_worker_global_scope_partial.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_worker_navigator_partial.h"
#include "third_party/blink/renderer/core/context_features/context_feature_settings.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/frame.h"
#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"
#include "third_party/blink/renderer/platform/bindings/origin_trial_features.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

namespace {
InstallOriginTrialFeaturesFunction
    g_original_install_origin_trial_features_function = nullptr;
InstallPendingOriginTrialFeatureFunction
    g_original_install_pending_origin_trial_feature_function = nullptr;

void InstallOriginTrialFeaturesForModules(
    const WrapperTypeInfo* wrapper_type_info,
    const ScriptState* script_state,
    v8::Local<v8::Object> prototype_object,
    v8::Local<v8::Function> interface_object) {
  (*g_original_install_origin_trial_features_function)(
      wrapper_type_info, script_state, prototype_object, interface_object);

  ExecutionContext* execution_context = ExecutionContext::From(script_state);
  if (!execution_context)
    return;
  v8::Isolate* isolate = script_state->GetIsolate();
  const DOMWrapperWorld& world = script_state->World();
  // TODO(iclelland): Extract this common code out of OriginTrialFeaturesForCore
  // and OriginTrialFeaturesForModules into a block.
  if (wrapper_type_info == V8DedicatedWorkerGlobalScope::GetWrapperTypeInfo()) {
    v8::Local<v8::Object> instance_object =
        script_state->GetContext()->Global();
    if (RuntimeEnabledFeatures::NativeFileSystemEnabled(execution_context)) {
      V8DedicatedWorkerGlobalScopePartial::InstallNativeFileSystem(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::IdleDetectionEnabled(execution_context)) {
      V8DedicatedWorkerGlobalScopePartial::InstallIdleDetection(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::QuicTransportEnabled(execution_context)) {
      V8DedicatedWorkerGlobalScopePartial::InstallQuicTransport(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::SerialEnabled(execution_context)) {
      V8DedicatedWorkerGlobalScopePartial::InstallSerial(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::NotificationTriggersEnabled(execution_context)) {
      V8DedicatedWorkerGlobalScopePartial::InstallNotificationTriggers(
          isolate, world, instance_object, prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8FileSystemDirectoryHandle::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::LegacyNativeFileSystemEnabled(execution_context)) {
      V8FileSystemDirectoryHandle::InstallLegacyNativeFileSystem(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLVideoElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::AutoPictureInPictureEnabled(execution_context)) {
      V8HTMLVideoElementPartial::InstallAutoPictureInPicture(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Navigator::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::SerialEnabled(execution_context)) {
      V8NavigatorPartial::InstallSerial(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::WakeLockEnabled(execution_context)) {
      V8NavigatorPartial::InstallWakeLock(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Notification::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::NotificationTriggersEnabled(execution_context)) {
      V8Notification::InstallNotificationTriggers(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8RTCIceTransport::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::RTCIceTransportExtensionEnabled(execution_context)) {
      V8RTCIceTransport::InstallRTCIceTransportExtension(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8RTCRtpReceiver::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::RTCInsertableStreamsEnabled(execution_context)) {
      V8RTCRtpReceiver::InstallRTCInsertableStreams(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8RTCRtpSender::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::RTCInsertableStreamsEnabled(execution_context)) {
      V8RTCRtpSender::InstallRTCInsertableStreams(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8ServiceWorkerGlobalScope::GetWrapperTypeInfo()) {
    v8::Local<v8::Object> instance_object =
        script_state->GetContext()->Global();
    if (RuntimeEnabledFeatures::NativeFileSystemEnabled(execution_context)) {
      V8ServiceWorkerGlobalScope::InstallNativeFileSystem(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::CookieStoreDocumentEnabled(execution_context)) {
      V8ServiceWorkerGlobalScope::InstallCookieStoreDocument(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::NotificationTriggersEnabled(execution_context)) {
      V8ServiceWorkerGlobalScope::InstallNotificationTriggers(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::QuicTransportEnabled(execution_context)) {
      V8ServiceWorkerGlobalScope::InstallQuicTransport(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::CookieStoreWorkerEnabled(execution_context)) {
      V8ServiceWorkerGlobalScope::InstallCookieStoreWorker(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(execution_context)) {
      V8ServiceWorkerGlobalScope::InstallExperimentalJSProfiler(
          isolate, world, instance_object, prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8ServiceWorkerRegistration::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::CookieStoreWorkerEnabled(execution_context)) {
      V8ServiceWorkerRegistration::InstallCookieStoreWorker(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8SharedWorkerGlobalScope::GetWrapperTypeInfo()) {
    v8::Local<v8::Object> instance_object =
        script_state->GetContext()->Global();
    if (RuntimeEnabledFeatures::NativeFileSystemEnabled(execution_context)) {
      V8SharedWorkerGlobalScopePartial::InstallNativeFileSystem(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::QuicTransportEnabled(execution_context)) {
      V8SharedWorkerGlobalScopePartial::InstallQuicTransport(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::NotificationTriggersEnabled(execution_context)) {
      V8SharedWorkerGlobalScopePartial::InstallNotificationTriggers(
          isolate, world, instance_object, prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Window::GetWrapperTypeInfo()) {
    v8::Local<v8::Object> instance_object =
        script_state->GetContext()->Global();
    if (RuntimeEnabledFeatures::IdleDetectionEnabled(execution_context)) {
      V8WindowPartial::InstallIdleDetection(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::NativeFileSystemEnabled(execution_context)) {
      V8WindowPartial::InstallNativeFileSystem(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::CookieStoreDocumentEnabled(execution_context)) {
      V8WindowPartial::InstallCookieStoreDocument(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::NotificationTriggersEnabled(execution_context)) {
      V8WindowPartial::InstallNotificationTriggers(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::QuicTransportEnabled(execution_context)) {
      V8WindowPartial::InstallQuicTransport(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::WebSchedulerEnabled(execution_context)) {
      V8WindowPartial::InstallWebScheduler(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::WakeLockEnabled(execution_context)) {
      V8WindowPartial::InstallWakeLock(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::FileHandlingEnabled(execution_context)) {
      V8WindowPartial::InstallFileHandling(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::SerialEnabled(execution_context)) {
      V8WindowPartial::InstallSerial(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::WebNFCEnabled(execution_context)) {
      V8WindowPartial::InstallWebNFC(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::RTCQuicTransportEnabled(execution_context)) {
      V8WindowPartial::InstallRTCQuicTransport(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::RTCInsertableStreamsEnabled(execution_context)) {
      V8WindowPartial::InstallRTCInsertableStreams(
          isolate, world, instance_object, prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8WorkerGlobalScope::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::NativeFileSystemEnabled(execution_context)) {
      V8WorkerGlobalScopePartial::InstallNativeFileSystem(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8WorkerNavigator::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::SerialEnabled(execution_context)) {
      V8WorkerNavigatorPartial::InstallSerial(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
}

void InstallPendingOriginTrialFeatureForModules(
    OriginTrialFeature feature,
    const ScriptState* script_state) {
  (*g_original_install_pending_origin_trial_feature_function)(feature,
                                                             script_state);

  // TODO(iclelland): Extract this common code out of OriginTrialFeaturesForCore
  // and OriginTrialFeaturesForModules into a block.
  v8::Local<v8::Object> prototype_object;
  v8::Local<v8::Function> interface_object;
  v8::Isolate* isolate = script_state->GetIsolate();
  const DOMWrapperWorld& world = script_state->World();
  V8PerContextData* context_data = script_state->PerContextData();
  switch (feature) {
    case OriginTrialFeature::kAutoPictureInPicture: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLVideoElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLVideoElementPartial::InstallAutoPictureInPicture(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kCookieStoreDocument: {
      V8WindowPartial::InstallCookieStoreDocument(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8ServiceWorkerGlobalScope::InstallCookieStoreDocument(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kCookieStoreWorker: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8ServiceWorkerRegistration::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8ServiceWorkerRegistration::InstallCookieStoreWorker(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      V8ServiceWorkerGlobalScope::InstallCookieStoreWorker(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kExperimentalJSProfiler: {
      V8ServiceWorkerGlobalScope::InstallExperimentalJSProfiler(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kFileHandling: {
      V8WindowPartial::InstallFileHandling(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kIdleDetection: {
      V8DedicatedWorkerGlobalScopePartial::InstallIdleDetection(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8WindowPartial::InstallIdleDetection(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kLegacyNativeFileSystem: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8FileSystemDirectoryHandle::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8FileSystemDirectoryHandle::InstallLegacyNativeFileSystem(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kNativeFileSystem: {
      V8DedicatedWorkerGlobalScopePartial::InstallNativeFileSystem(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8WindowPartial::InstallNativeFileSystem(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8ServiceWorkerGlobalScope::InstallNativeFileSystem(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8SharedWorkerGlobalScopePartial::InstallNativeFileSystem(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8WorkerGlobalScope::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8WorkerGlobalScopePartial::InstallNativeFileSystem(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kNotificationTriggers: {
      V8DedicatedWorkerGlobalScopePartial::InstallNotificationTriggers(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8ServiceWorkerGlobalScope::InstallNotificationTriggers(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8WindowPartial::InstallNotificationTriggers(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Notification::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Notification::InstallNotificationTriggers(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      V8SharedWorkerGlobalScopePartial::InstallNotificationTriggers(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kQuicTransport: {
      V8DedicatedWorkerGlobalScopePartial::InstallQuicTransport(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8WindowPartial::InstallQuicTransport(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8ServiceWorkerGlobalScope::InstallQuicTransport(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8SharedWorkerGlobalScopePartial::InstallQuicTransport(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kRTCIceTransportExtension: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8RTCIceTransport::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8RTCIceTransport::InstallRTCIceTransportExtension(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kRTCInsertableStreams: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8RTCRtpSender::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8RTCRtpSender::InstallRTCInsertableStreams(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      V8WindowPartial::InstallRTCInsertableStreams(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8RTCRtpReceiver::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8RTCRtpReceiver::InstallRTCInsertableStreams(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kRTCQuicTransport: {
      V8WindowPartial::InstallRTCQuicTransport(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kSerial: {
      V8DedicatedWorkerGlobalScopePartial::InstallSerial(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8WindowPartial::InstallSerial(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Navigator::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8NavigatorPartial::InstallSerial(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8WorkerNavigator::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8WorkerNavigatorPartial::InstallSerial(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kWakeLock: {
      V8WindowPartial::InstallWakeLock(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Navigator::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8NavigatorPartial::InstallWakeLock(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kWebNFC: {
      V8WindowPartial::InstallWebNFC(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kWebScheduler: {
      V8WindowPartial::InstallWebScheduler(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    default:
      break;
  }
}

}  // namespace

void RegisterInstallOriginTrialFeaturesForModules() {
  RegisterInstallOriginTrialFeaturesForCore();
  g_original_install_origin_trial_features_function =
      SetInstallOriginTrialFeaturesFunction(
          &InstallOriginTrialFeaturesForModules);
  g_original_install_pending_origin_trial_feature_function =
      SetInstallPendingOriginTrialFeatureFunction(
          &InstallPendingOriginTrialFeatureForModules);
}

}  // namespace blink
