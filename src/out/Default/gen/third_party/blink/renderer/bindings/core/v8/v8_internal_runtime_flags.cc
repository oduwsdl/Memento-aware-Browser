// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_internal_runtime_flags.h"

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
const WrapperTypeInfo v8_internal_runtime_flags_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8InternalRuntimeFlags::DomTemplate,
    nullptr,
    "InternalRuntimeFlags",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in InternalRuntimeFlags.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& InternalRuntimeFlags::wrapper_type_info_ = v8_internal_runtime_flags_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, InternalRuntimeFlags>::value,
    "InternalRuntimeFlags inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&InternalRuntimeFlags::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "InternalRuntimeFlags is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace internal_runtime_flags_v8_internal {

static void Accelerated2dCanvasEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->accelerated2dCanvasEnabled());
}

static void Accelerated2dCanvasEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "accelerated2dCanvasEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setAccelerated2dCanvasEnabled(cpp_value);
}

static void AcceleratedSmallCanvasesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->acceleratedSmallCanvasesEnabled());
}

static void AccessibilityExposeARIAAnnotationsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->accessibilityExposeARIAAnnotationsEnabled());
}

static void AccessibilityExposeDisplayNoneEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->accessibilityExposeDisplayNoneEnabled());
}

static void AccessibilityExposeHTMLElementEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->accessibilityExposeHTMLElementEnabled());
}

static void AccessibilityObjectModelEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->accessibilityObjectModelEnabled());
}

static void AddressSpaceEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->addressSpaceEnabled());
}

static void AdTaggingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->adTaggingEnabled());
}

static void AllowActivationDelegationAttrEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->allowActivationDelegationAttrEnabled());
}

static void AllowContentInitiatedDataUrlNavigationsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->allowContentInitiatedDataUrlNavigationsEnabled());
}

static void AllowSyncXHRInPageDismissalEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->allowSyncXHRInPageDismissalEnabled());
}

static void AnimationWorkletEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->animationWorkletEnabled());
}

static void AomAriaPropertiesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->aomAriaPropertiesEnabled());
}

static void AomAriaRelationshipPropertiesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->aomAriaRelationshipPropertiesEnabled());
}

static void AppCacheEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->appCacheEnabled());
}

static void AudioOutputDevicesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->audioOutputDevicesEnabled());
}

static void AudioVideoTracksEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->audioVideoTracksEnabled());
}

static void AudioWorkletRealtimeThreadEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->audioWorkletRealtimeThreadEnabled());
}

static void AutoLazyLoadOnReloadsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->autoLazyLoadOnReloadsEnabled());
}

static void AutomaticLazyFrameLoadingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->automaticLazyFrameLoadingEnabled());
}

static void AutomaticLazyImageLoadingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->automaticLazyImageLoadingEnabled());
}

static void AutomationControlledEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->automationControlledEnabled());
}

static void AutomationControlledEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "automationControlledEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setAutomationControlledEnabled(cpp_value);
}

static void AutoPictureInPictureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->autoPictureInPictureEnabled());
}

static void AutoplayIgnoresWebAudioEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->autoplayIgnoresWebAudioEnabled());
}

static void AutoplayIgnoresWebAudioEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "autoplayIgnoresWebAudioEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setAutoplayIgnoresWebAudioEnabled(cpp_value);
}

static void BackForwardCacheEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->backForwardCacheEnabled());
}

static void BackgroundFetchEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->backgroundFetchEnabled());
}

static void BackgroundVideoTrackOptimizationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->backgroundVideoTrackOptimizationEnabled());
}

static void BadgingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->badgingEnabled());
}

static void BarcodeDetectorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->barcodeDetectorEnabled());
}

static void BeforeMatchEventEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->beforeMatchEventEnabled());
}

static void BidiCaretAffinityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->bidiCaretAffinityEnabled());
}

static void BlinkRuntimeCallStatsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->blinkRuntimeCallStatsEnabled());
}

static void BlockCredentialedSubresourcesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->blockCredentialedSubresourcesEnabled());
}

static void BlockFlowHandlesWebkitLineClampEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->blockFlowHandlesWebkitLineClampEnabled());
}

static void BlockHTMLParserOnStyleSheetsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->blockHTMLParserOnStyleSheetsEnabled());
}

static void BlockingDownloadsInSandboxEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->blockingDownloadsInSandboxEnabled());
}

static void BlockingFocusWithoutUserActivationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->blockingFocusWithoutUserActivationEnabled());
}

static void BrowserVerifiedUserActivationKeyboardEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->browserVerifiedUserActivationKeyboardEnabled());
}

static void BrowserVerifiedUserActivationMouseEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->browserVerifiedUserActivationMouseEnabled());
}

static void CacheInlineScriptCodeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cacheInlineScriptCodeEnabled());
}

static void CacheStorageCodeCacheHintEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cacheStorageCodeCacheHintEnabled());
}

static void Canvas2dContextLostRestoredEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->canvas2dContextLostRestoredEnabled());
}

static void Canvas2dImageChromiumEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->canvas2dImageChromiumEnabled());
}

static void Canvas2dScrollPathIntoViewEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->canvas2dScrollPathIntoViewEnabled());
}

static void CanvasColorManagementEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->canvasColorManagementEnabled());
}

static void CanvasHitRegionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->canvasHitRegionEnabled());
}

static void CanvasImageSmoothingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->canvasImageSmoothingEnabled());
}

static void CaptureTimeInCsrcEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->captureTimeInCsrcEnabled());
}

static void ClickPointerEventEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->clickPointerEventEnabled());
}

static void ClickRetargettingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->clickRetargettingEnabled());
}

static void CompositeAfterPaintEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->compositeAfterPaintEnabled());
}

static void CompositedSelectionUpdateEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->compositedSelectionUpdateEnabled());
}

static void ComputedAccessibilityInfoEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->computedAccessibilityInfoEnabled());
}

static void ConsolidatedMovementXYEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->consolidatedMovementXYEnabled());
}

static void ContactsManagerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->contactsManagerEnabled());
}

static void ContactsManagerExtraPropertiesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->contactsManagerExtraPropertiesEnabled());
}

static void ContentIndexEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->contentIndexEnabled());
}

static void ContextMenuEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->contextMenuEnabled());
}

static void ConversionMeasurementEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->conversionMeasurementEnabled());
}

static void CookieDeprecationMessagesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cookieDeprecationMessagesEnabled());
}

static void CookieStoreDocumentEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cookieStoreDocumentEnabled());
}

static void CookieStoreWorkerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cookieStoreWorkerEnabled());
}

static void CookiesWithoutSameSiteMustBeSecureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cookiesWithoutSameSiteMustBeSecureEnabled());
}

static void CooperativeSchedulingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cooperativeSchedulingEnabled());
}

static void CorsRFC1918EnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->corsRFC1918Enabled());
}

static void CrossOriginIsolationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->crossOriginIsolationEnabled());
}

static void CSS3TextEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->css3TextEnabled());
}

static void CSSAspectRatioPropertyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssAspectRatioPropertyEnabled());
}

static void CSSCalcAsIntEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssCalcAsIntEnabled());
}

static void CSSCascadeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssCascadeEnabled());
}

static void CSSColorSchemeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssColorSchemeEnabled());
}

static void CSSColorSchemeUARenderingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssColorSchemeUARenderingEnabled());
}

static void CSSContentVisibilityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssContentVisibilityEnabled());
}

static void CSSContentVisibilityHiddenMatchableEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssContentVisibilityHiddenMatchableEnabled());
}

static void CSSFocusVisibleEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssFocusVisibleEnabled());
}

static void CSSFoldablesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssFoldablesEnabled());
}

static void CSSFontSizeAdjustEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssFontSizeAdjustEnabled());
}

static void CSSHexAlphaColorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssHexAlphaColorEnabled());
}

static void CSSIndependentTransformPropertiesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssIndependentTransformPropertiesEnabled());
}

static void CSSLayoutAPIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssLayoutAPIEnabled());
}

static void CSSLogicalEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssLogicalEnabled());
}

static void CSSLogicalEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "cssLogicalEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setCSSLogicalEnabled(cpp_value);
}

static void CSSLogicalOverflowEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssLogicalOverflowEnabled());
}

static void CSSMarkerNestedPseudoElementEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssMarkerNestedPseudoElementEnabled());
}

static void CSSMarkerPseudoElementEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssMarkerPseudoElementEnabled());
}

static void CSSMatchedPropertiesCacheDependenciesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssMatchedPropertiesCacheDependenciesEnabled());
}

static void CSSMathStyleEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssMathStyleEnabled());
}

static void CSSMathSuperscriptShiftStyleEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssMathSuperscriptShiftStyleEnabled());
}

static void CSSMathVariantEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssMathVariantEnabled());
}

static void CSSModulesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssModulesEnabled());
}

static void CSSOffsetPathRayEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssOffsetPathRayEnabled());
}

static void CSSOffsetPathRayContainEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssOffsetPathRayContainEnabled());
}

static void CSSOffsetPositionAnchorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssOffsetPositionAnchorEnabled());
}

static void CSSOMViewScrollCoordinatesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssomViewScrollCoordinatesEnabled());
}

static void CSSPaintAPIArgumentsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssPaintAPIArgumentsEnabled());
}

static void CSSPictureInPictureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssPictureInPictureEnabled());
}

static void CSSPseudoIsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssPseudoIsEnabled());
}

static void CSSPseudoWhereEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssPseudoWhereEnabled());
}

static void CSSReducedFontLoadingInvalidationsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssReducedFontLoadingInvalidationsEnabled());
}

static void CSSReducedFontLoadingLayoutInvalidationsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssReducedFontLoadingLayoutInvalidationsEnabled());
}

static void CSSRevertEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssRevertEnabled());
}

static void CSSScrollTimelineEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssScrollTimelineEnabled());
}

static void CSSSnapSizeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssSnapSizeEnabled());
}

static void CSSSupportsSelectorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssSupportsSelectorEnabled());
}

static void CSSVariables2AtPropertyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssVariables2AtPropertyEnabled());
}

static void CSSVariables2ImageValuesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssVariables2ImageValuesEnabled());
}

static void CSSVariables2TransformValuesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->cssVariables2TransformValuesEnabled());
}

static void CustomElementDefaultStyleEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->customElementDefaultStyleEnabled());
}

static void CustomElementsV0EnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->customElementsV0Enabled());
}

static void CustomStatePseudoClassEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->customStatePseudoClassEnabled());
}

static void DatabaseEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->databaseEnabled());
}

static void DeclarativeShadowDOMEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->declarativeShadowDOMEnabled());
}

static void DecodeJpeg420ImagesToYUVEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->decodeJpeg420ImagesToYUVEnabled());
}

static void DecodeLossyWebPImagesToYUVEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->decodeLossyWebPImagesToYUVEnabled());
}

static void DelayAsyncScriptExecutionUntilFinishedParsingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->delayAsyncScriptExecutionUntilFinishedParsingEnabled());
}

static void DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->delayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled());
}

static void DelegatedInkTrailsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->delegatedInkTrailsEnabled());
}

static void DesktopCaptureDisableLocalEchoControlEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->desktopCaptureDisableLocalEchoControlEnabled());
}

static void DigitalGoodsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->digitalGoodsEnabled());
}

static void DisableHardwareNoiseSuppressionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->disableHardwareNoiseSuppressionEnabled());
}

static void DisableLayerSquashingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->disableLayerSquashingEnabled());
}

static void DisallowDocumentAccessEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->disallowDocumentAccessEnabled());
}

static void DisplayCutoutAPIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->displayCutoutAPIEnabled());
}

static void DisplayCutoutAPIEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "displayCutoutAPIEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setDisplayCutoutAPIEnabled(cpp_value);
}

static void DocumentCookieEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->documentCookieEnabled());
}

static void DocumentDomainEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->documentDomainEnabled());
}

static void DocumentPolicyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->documentPolicyEnabled());
}

static void DocumentWriteEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->documentWriteEnabled());
}

static void EditContextEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->editContextEnabled());
}

static void EditContextEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "editContextEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setEditContextEnabled(cpp_value);
}

static void EditingNGEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->editingNGEnabled());
}

static void EncryptedMediaEncryptionSchemeQueryEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->encryptedMediaEncryptionSchemeQueryEnabled());
}

static void EncryptedMediaHdcpPolicyCheckEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->encryptedMediaHdcpPolicyCheckEnabled());
}

static void EncryptedMediaPersistentUsageRecordSessionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->encryptedMediaPersistentUsageRecordSessionEnabled());
}

static void EnterKeyHintAttributeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->enterKeyHintAttributeEnabled());
}

static void EventTimingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->eventTimingEnabled());
}

static void ExecCommandInJavaScriptEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->execCommandInJavaScriptEnabled());
}

static void ExpensiveBackgroundTimerThrottlingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->expensiveBackgroundTimerThrottlingEnabled());
}

static void ExperimentalAutoplayDynamicDelegationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->experimentalAutoplayDynamicDelegationEnabled());
}

static void ExperimentalContentSecurityPolicyFeaturesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->experimentalContentSecurityPolicyFeaturesEnabled());
}

static void ExperimentalIsInputPendingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->experimentalIsInputPendingEnabled());
}

static void ExperimentalJSProfilerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->experimentalJSProfilerEnabled());
}

static void ExperimentalProductivityFeaturesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->experimentalProductivityFeaturesEnabled());
}

static void ExtendedTextMetricsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->extendedTextMetricsEnabled());
}

static void ExtraWebGLVideoTextureMetadataEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->extraWebGLVideoTextureMetadataEnabled());
}

static void FaceDetectorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->faceDetectorEnabled());
}

static void FeaturePolicyForClientHintsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->featurePolicyForClientHintsEnabled());
}

static void FeaturePolicyForSandboxEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->featurePolicyForSandboxEnabled());
}

static void FeaturePolicyReportingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->featurePolicyReportingEnabled());
}

static void FeaturePolicyVibrateFeatureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->featurePolicyVibrateFeatureEnabled());
}

static void FetchUploadStreamingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->fetchUploadStreamingEnabled());
}

static void FileHandlingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->fileHandlingEnabled());
}

static void FileSystemEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->fileSystemEnabled());
}

static void FlexGapsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->flexGapsEnabled());
}

static void FocuslessSpatialNavigationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->focuslessSpatialNavigationEnabled());
}

static void FocuslessSpatialNavigationEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "focuslessSpatialNavigationEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setFocuslessSpatialNavigationEnabled(cpp_value);
}

static void FontAccessEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->fontAccessEnabled());
}

static void FontSrcLocalMatchingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->fontSrcLocalMatchingEnabled());
}

static void ForcedColorsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->forcedColorsEnabled());
}

static void ForceDeferScriptInterventionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->forceDeferScriptInterventionEnabled());
}

static void ForceEagerMeasureMemoryEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->forceEagerMeasureMemoryEnabled());
}

static void ForceLoadAtTopEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->forceLoadAtTopEnabled());
}

static void ForceOverlayFullscreenVideoEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->forceOverlayFullscreenVideoEnabled());
}

static void ForceSynchronousHTMLParsingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->forceSynchronousHTMLParsingEnabled());
}

static void ForceTallerSelectPopupEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->forceTallerSelectPopupEnabled());
}

static void FractionalScrollOffsetsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->fractionalScrollOffsetsEnabled());
}

static void FreezeFramesOnVisibilityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->freezeFramesOnVisibilityEnabled());
}

static void GamepadButtonAxisEventsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->gamepadButtonAxisEventsEnabled());
}

static void GetDisplayMediaEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->getDisplayMediaEnabled());
}

static void GroupEffectEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->groupEffectEnabled());
}

static void HrefTranslateEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->hrefTranslateEnabled());
}

static void HTMLImportsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->htmlImportsEnabled());
}

static void IdbObserverEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->idbObserverEnabled());
}

static void IdbRelaxedDurabilityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->idbRelaxedDurabilityEnabled());
}

static void IdleDetectionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->idleDetectionEnabled());
}

static void IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->ignoreCrossOriginWindowWhenNamedAccessOnWindowEnabled());
}

static void ImageOrientationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->imageOrientationEnabled());
}

static void ImplicitRootScrollerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->implicitRootScrollerEnabled());
}

static void ImplicitRootScrollerEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "implicitRootScrollerEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setImplicitRootScrollerEnabled(cpp_value);
}

static void ImportMapsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->importMapsEnabled());
}

static void InertAttributeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->inertAttributeEnabled());
}

static void InputElementRawValueEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->inputElementRawValueEnabled());
}

static void InputMultipleFieldsUIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->inputMultipleFieldsUIEnabled());
}

static void InstalledAppEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->installedAppEnabled());
}

static void IntersectionObserverDocumentScrollingElementRootEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->intersectionObserverDocumentScrollingElementRootEnabled());
}

static void IsolatedCodeCacheEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->isolatedCodeCacheEnabled());
}

static void IsolatedWorldCSPEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->isolatedWorldCSPEnabled());
}

static void KeyboardFocusableScrollersEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->keyboardFocusableScrollersEnabled());
}

static void LangAttributeAwareFormControlUIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->langAttributeAwareFormControlUIEnabled());
}

static void LangClientHintHeaderEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->langClientHintHeaderEnabled());
}

static void LayoutNGEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGEnabled());
}

static void LayoutNGBlockFragmentationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGBlockFragmentationEnabled());
}

static void LayoutNGFieldsetEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGFieldsetEnabled());
}

static void LayoutNGFlexBoxEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGFlexBoxEnabled());
}

static void LayoutNGForControlsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGForControlsEnabled());
}

static void LayoutNGFragmentItemEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGFragmentItemEnabled());
}

static void LayoutNGFragmentTraversalEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGFragmentTraversalEnabled());
}

static void LayoutNGGridEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGGridEnabled());
}

static void LayoutNGRubyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGRubyEnabled());
}

static void LayoutNGTableEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutNGTableEnabled());
}

static void LayoutShiftAttributionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->layoutShiftAttributionEnabled());
}

static void LazyFrameLoadingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->lazyFrameLoadingEnabled());
}

static void LazyFrameVisibleLoadTimeMetricsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->lazyFrameVisibleLoadTimeMetricsEnabled());
}

static void LazyImageLoadingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->lazyImageLoadingEnabled());
}

static void LazyImageVisibleLoadTimeMetricsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->lazyImageVisibleLoadTimeMetricsEnabled());
}

static void LazyInitializeMediaControlsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->lazyInitializeMediaControlsEnabled());
}

static void LegacyNativeFileSystemEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->legacyNativeFileSystemEnabled());
}

static void LegacyWindowsDWriteFontFallbackEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->legacyWindowsDWriteFontFallbackEnabled());
}

static void LinkDisabledNewSpecBehaviorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->linkDisabledNewSpecBehaviorEnabled());
}

static void ManualSlottingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->manualSlottingEnabled());
}

static void MathMLCoreEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mathmlCoreEnabled());
}

static void MeasureMemoryEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->measureMemoryEnabled());
}

static void MediaCapabilitiesDynamicRangeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCapabilitiesDynamicRangeEnabled());
}

static void MediaCapabilitiesEncodingInfoEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCapabilitiesEncodingInfoEnabled());
}

static void MediaCapabilitiesEncryptedMediaEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCapabilitiesEncryptedMediaEnabled());
}

static void MediaCapabilitiesSpatialAudioEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCapabilitiesSpatialAudioEnabled());
}

static void MediaCaptureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCaptureEnabled());
}

static void MediaCaptureDepthVideoKindEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCaptureDepthVideoKindEnabled());
}

static void MediaCapturePanTiltEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCapturePanTiltEnabled());
}

static void MediaCastOverlayButtonEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaCastOverlayButtonEnabled());
}

static void MediaControlsExpandGestureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaControlsExpandGestureEnabled());
}

static void MediaControlsOverlayPlayButtonEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaControlsOverlayPlayButtonEnabled());
}

static void MediaControlsOverlayPlayButtonEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "mediaControlsOverlayPlayButtonEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setMediaControlsOverlayPlayButtonEnabled(cpp_value);
}

static void MediaControlsUseCutOutByDefaultEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaControlsUseCutOutByDefaultEnabled());
}

static void MediaDocumentDownloadButtonEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaDocumentDownloadButtonEnabled());
}

static void MediaElementVolumeGreaterThanOneEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaElementVolumeGreaterThanOneEnabled());
}

static void MediaEngagementBypassAutoplayPoliciesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaEngagementBypassAutoplayPoliciesEnabled());
}

static void MediaFeedsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaFeedsEnabled());
}

static void MediaLatencyHintEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaLatencyHintEnabled());
}

static void MediaQueryNavigationControlsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaQueryNavigationControlsEnabled());
}

static void MediaSessionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaSessionEnabled());
}

static void MediaSessionPositionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaSessionPositionEnabled());
}

static void MediaSourceExperimentalEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaSourceExperimentalEnabled());
}

static void MediaSourceInWorkersEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaSourceInWorkersEnabled());
}

static void MediaSourceNewAbortAndDurationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaSourceNewAbortAndDurationEnabled());
}

static void MediaSourceStableEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mediaSourceStableEnabled());
}

static void MetaColorSchemeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->metaColorSchemeEnabled());
}

static void MiddleClickAutoscrollEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->middleClickAutoscrollEnabled());
}

static void MobileLayoutThemeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mobileLayoutThemeEnabled());
}

static void ModuleServiceWorkerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->moduleServiceWorkerEnabled());
}

static void ModuleSharedWorkerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->moduleSharedWorkerEnabled());
}

static void MojoJSEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mojoJSEnabled());
}

static void MojoJSTestEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mojoJSTestEnabled());
}

static void MouseSubframeNoImplicitCaptureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->mouseSubframeNoImplicitCaptureEnabled());
}

static void NamedPagesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->namedPagesEnabled());
}

static void NativeFileSystemEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->nativeFileSystemEnabled());
}

static void NativeIOEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->nativeIOEnabled());
}

static void NavigatorContentUtilsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->navigatorContentUtilsEnabled());
}

static void NavigatorLanguageInInsecureContextEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->navigatorLanguageInInsecureContextEnabled());
}

static void NavigatorLanguageInInsecureContextEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "navigatorLanguageInInsecureContextEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setNavigatorLanguageInInsecureContextEnabled(cpp_value);
}

static void NetInfoDownlinkMaxEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->netInfoDownlinkMaxEnabled());
}

static void NeverSlowModeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->neverSlowModeEnabled());
}

static void NewCanvas2DAPIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->newCanvas2DAPIEnabled());
}

static void NewRemotePlaybackPipelineEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->newRemotePlaybackPipelineEnabled());
}

static void NoIdleEncodingForWebTestsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->noIdleEncodingForWebTestsEnabled());
}

static void NotificationConstructorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->notificationConstructorEnabled());
}

static void NotificationContentImageEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->notificationContentImageEnabled());
}

static void NotificationsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->notificationsEnabled());
}

static void NotificationTriggersEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->notificationTriggersEnabled());
}

static void OffMainThreadCSSPaintEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->offMainThreadCSSPaintEnabled());
}

static void OffscreenCanvasCommitEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->offscreenCanvasCommitEnabled());
}

static void OnDeviceChangeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->onDeviceChangeEnabled());
}

static void OrientationEventEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->orientationEventEnabled());
}

static void OriginIsolationHeaderEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originIsolationHeaderEnabled());
}

static void OriginPolicyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originPolicyEnabled());
}

static void OriginTrialsSampleAPIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originTrialsSampleAPIEnabled());
}

static void OriginTrialsSampleAPIDependentEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originTrialsSampleAPIDependentEnabled());
}

static void OriginTrialsSampleAPIDeprecationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originTrialsSampleAPIDeprecationEnabled());
}

static void OriginTrialsSampleAPIImpliedEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originTrialsSampleAPIImpliedEnabled());
}

static void OriginTrialsSampleAPIInvalidOSEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originTrialsSampleAPIInvalidOSEnabled());
}

static void OriginTrialsSampleAPINavigationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originTrialsSampleAPINavigationEnabled());
}

static void OriginTrialsSampleAPIThirdPartyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->originTrialsSampleAPIThirdPartyEnabled());
}

static void OutOfBlinkCorsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->outOfBlinkCorsEnabled());
}

static void OverflowIconsForMediaControlsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->overflowIconsForMediaControlsEnabled());
}

static void OverscrollCustomizationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->overscrollCustomizationEnabled());
}

static void OverscrollCustomizationEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "overscrollCustomizationEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setOverscrollCustomizationEnabled(cpp_value);
}

static void PageFreezeOptInEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pageFreezeOptInEnabled());
}

static void PageFreezeOptOutEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pageFreezeOptOutEnabled());
}

static void PagePopupEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pagePopupEnabled());
}

static void PaintUnderInvalidationCheckingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paintUnderInvalidationCheckingEnabled());
}

static void PaintUnderInvalidationCheckingEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "paintUnderInvalidationCheckingEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setPaintUnderInvalidationCheckingEnabled(cpp_value);
}

static void ParseUrlProtocolHandlerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->parseUrlProtocolHandlerEnabled());
}

static void PassPaintVisualRectToCompositorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->passPaintVisualRectToCompositorEnabled());
}

static void PasswordRevealEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->passwordRevealEnabled());
}

static void PaymentAppEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentAppEnabled());
}

static void PaymentHandlerChangePaymentMethodEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentHandlerChangePaymentMethodEnabled());
}

static void PaymentHandlerHandlesShippingAndContactEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentHandlerHandlesShippingAndContactEnabled());
}

static void PaymentHandlerMinimalUIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentHandlerMinimalUIEnabled());
}

static void PaymentMethodChangeEventEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentMethodChangeEventEnabled());
}

static void PaymentRequestEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentRequestEnabled());
}

static void PaymentRequestMerchantValidationEventEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentRequestMerchantValidationEventEnabled());
}

static void PaymentRetryEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->paymentRetryEnabled());
}

static void PercentBasedScrollingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->percentBasedScrollingEnabled());
}

static void PercentBasedScrollingEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "percentBasedScrollingEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setPercentBasedScrollingEnabled(cpp_value);
}

static void PerformanceManagerInstrumentationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->performanceManagerInstrumentationEnabled());
}

static void PeriodicBackgroundSyncEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->periodicBackgroundSyncEnabled());
}

static void PerMethodCanMakePaymentQuotaEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->perMethodCanMakePaymentQuotaEnabled());
}

static void PermissionDelegationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->permissionDelegationEnabled());
}

static void PermissionsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->permissionsEnabled());
}

static void PermissionsRequestRevokeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->permissionsRequestRevokeEnabled());
}

static void PictureInPictureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pictureInPictureEnabled());
}

static void PictureInPictureEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "pictureInPictureEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setPictureInPictureEnabled(cpp_value);
}

static void PictureInPictureAPIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pictureInPictureAPIEnabled());
}

static void PictureInPictureV2EnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pictureInPictureV2Enabled());
}

static void PictureInPictureV2EnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "pictureInPictureV2Enabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setPictureInPictureV2Enabled(cpp_value);
}

static void PNaClEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pNaClEnabled());
}

static void PointerLockOptionsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pointerLockOptionsEnabled());
}

static void PointerRawUpdateEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pointerRawUpdateEnabled());
}

static void PortalsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->portalsEnabled());
}

static void PostAnimationFrameEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->postAnimationFrameEnabled());
}

static void PreciseMemoryInfoEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->preciseMemoryInfoEnabled());
}

static void PreferNonCompositedScrollingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->preferNonCompositedScrollingEnabled());
}

static void PreferNonCompositedScrollingEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "preferNonCompositedScrollingEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setPreferNonCompositedScrollingEnabled(cpp_value);
}

static void PrefersReducedDataEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->prefersReducedDataEnabled());
}

static void PrefixedVideoFullscreenEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->prefixedVideoFullscreenEnabled());
}

static void PresentationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->presentationEnabled());
}

static void PriorityHintsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->priorityHintsEnabled());
}

static void PushMessagingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pushMessagingEnabled());
}

static void PushMessagingSubscriptionChangeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->pushMessagingSubscriptionChangeEnabled());
}

static void QuicTransportEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->quicTransportEnabled());
}

static void RawClipboardEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rawClipboardEnabled());
}

static void ReducedReferrerGranularityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->reducedReferrerGranularityEnabled());
}

static void RemotePlaybackEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->remotePlaybackEnabled());
}

static void RemotePlaybackBackendEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->remotePlaybackBackendEnabled());
}

static void RemotePlaybackBackendEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "remotePlaybackBackendEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setRemotePlaybackBackendEnabled(cpp_value);
}

static void RequestVideoFrameCallbackEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->requestVideoFrameCallbackEnabled());
}

static void ResizeObserverUpdatesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->resizeObserverUpdatesEnabled());
}

static void RestrictAppCacheToSecureContextsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->restrictAppCacheToSecureContextsEnabled());
}

static void RestrictAutomaticLazyFrameLoadingToDataSaverEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->restrictAutomaticLazyFrameLoadingToDataSaverEnabled());
}

static void RestrictAutomaticLazyImageLoadingToDataSaverEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->restrictAutomaticLazyImageLoadingToDataSaverEnabled());
}

static void RTCAudioJitterBufferMaxPacketsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcAudioJitterBufferMaxPacketsEnabled());
}

static void RTCAudioJitterBufferRtxHandlingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcAudioJitterBufferRtxHandlingEnabled());
}

static void RTCIceTransportExtensionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcIceTransportExtensionEnabled());
}

static void RTCInsertableStreamsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcInsertableStreamsEnabled());
}

static void RTCQuicTransportEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcQuicTransportEnabled());
}

static void RTCStatsRelativePacketArrivalDelayEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcStatsRelativePacketArrivalDelayEnabled());
}

static void RTCSvcScalabilityModeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcSvcScalabilityModeEnabled());
}

static void RTCUnifiedPlanEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcUnifiedPlanEnabled());
}

static void RTCUnifiedPlanByDefaultEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->rtcUnifiedPlanByDefaultEnabled());
}

static void SameSiteByDefaultCookiesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->sameSiteByDefaultCookiesEnabled());
}

static void ScreenWakeLockEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->screenWakeLockEnabled());
}

static void ScriptedSpeechRecognitionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->scriptedSpeechRecognitionEnabled());
}

static void ScriptedSpeechSynthesisEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->scriptedSpeechSynthesisEnabled());
}

static void ScrollCustomizationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->scrollCustomizationEnabled());
}

static void ScrollSnapAfterLayoutEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->scrollSnapAfterLayoutEnabled());
}

static void ScrollTimelineEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->scrollTimelineEnabled());
}

static void ScrollTopLeftInteropEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->scrollTopLeftInteropEnabled());
}

static void ScrollUnificationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->scrollUnificationEnabled());
}

static void SendBeaconThrowForBlobWithNonSimpleTypeEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->sendBeaconThrowForBlobWithNonSimpleTypeEnabled());
}

static void SendMouseEventsDisabledFormControlsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->sendMouseEventsDisabledFormControlsEnabled());
}

static void SensorExtraClassesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->sensorExtraClassesEnabled());
}

static void SerialEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->serialEnabled());
}

static void ServiceWorkerClientLifecycleStateEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->serviceWorkerClientLifecycleStateEnabled());
}

static void ServiceWorkerFetchEventWorkerTimingEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->serviceWorkerFetchEventWorkerTimingEnabled());
}

static void ShadowDOMV0EnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->shadowDOMV0Enabled());
}

static void SharedArrayBufferEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->sharedArrayBufferEnabled());
}

static void SharedWorkerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->sharedWorkerEnabled());
}

static void SignatureBasedIntegrityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->signatureBasedIntegrityEnabled());
}

static void SignedExchangePrefetchCacheForNavigationsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->signedExchangePrefetchCacheForNavigationsEnabled());
}

static void SignedExchangeSubresourcePrefetchEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->signedExchangeSubresourcePrefetchEnabled());
}

static void SkipAdEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->skipAdEnabled());
}

static void SkipTouchEventFilterEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->skipTouchEventFilterEnabled());
}

static void SkipTouchEventFilterEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "skipTouchEventFilterEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setSkipTouchEventFilterEnabled(cpp_value);
}

static void SmsReceiverEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->smsReceiverEnabled());
}

static void SquashAfterPaintEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->squashAfterPaintEnabled());
}

static void StableBlinkFeaturesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->stableBlinkFeaturesEnabled());
}

static void StorageAccessAPIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->storageAccessAPIEnabled());
}

static void StrictMimeTypesForWorkersEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->strictMimeTypesForWorkersEnabled());
}

static void SubresourceWebBundlesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->subresourceWebBundlesEnabled());
}

static void SurfaceEmbeddingFeaturesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->surfaceEmbeddingFeaturesEnabled());
}

static void SystemWakeLockEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->systemWakeLockEnabled());
}

static void TestFeatureEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->testFeatureEnabled());
}

static void TestFeatureDependentEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->testFeatureDependentEnabled());
}

static void TestFeatureImpliedEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->testFeatureImpliedEnabled());
}

static void TextDetectorEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->textDetectorEnabled());
}

static void TextFragmentIdentifiersEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->textFragmentIdentifiersEnabled());
}

static void ThirdPartyOriginTrialsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->thirdPartyOriginTrialsEnabled());
}

static void TimerThrottlingForBackgroundTabsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->timerThrottlingForBackgroundTabsEnabled());
}

static void TimerThrottlingForHiddenFramesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->timerThrottlingForHiddenFramesEnabled());
}

static void TimeZoneChangeEventEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->timeZoneChangeEventEnabled());
}

static void TouchEventFeatureDetectionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->touchEventFeatureDetectionEnabled());
}

static void TrackLayoutPassesPerBlockEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->trackLayoutPassesPerBlockEnabled());
}

static void TransferableStreamsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->transferableStreamsEnabled());
}

static void TransformInteropEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->transformInteropEnabled());
}

static void TranslateServiceEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->translateServiceEnabled());
}

static void TrustedDOMTypesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->trustedDOMTypesEnabled());
}

static void TrustTokensEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->trustTokensEnabled());
}

static void TrustTokensAlwaysAllowIssuanceEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->trustTokensAlwaysAllowIssuanceEnabled());
}

static void UnclosedFormControlIsInvalidEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->unclosedFormControlIsInvalidEnabled());
}

static void UnderlineOffsetThicknessEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->underlineOffsetThicknessEnabled());
}

static void UnoptimizedImagePoliciesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->unoptimizedImagePoliciesEnabled());
}

static void UnsizedMediaPolicyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->unsizedMediaPolicyEnabled());
}

static void UserActivationPostMessageTransferEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->userActivationPostMessageTransferEnabled());
}

static void UserActivationSameOriginVisibilityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->userActivationSameOriginVisibilityEnabled());
}

static void UserAgentClientHintEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->userAgentClientHintEnabled());
}

static void V8IdleTasksEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->v8IdleTasksEnabled());
}

static void VideoAutoFullscreenEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->videoAutoFullscreenEnabled());
}

static void VideoAutoFullscreenEnabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "InternalRuntimeFlags", "videoAutoFullscreenEnabled");

  // Prepare the value to be set.
  bool cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setVideoAutoFullscreenEnabled(cpp_value);
}

static void VideoFullscreenOrientationLockEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->videoFullscreenOrientationLockEnabled());
}

static void VideoPlaybackQualityEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->videoPlaybackQualityEnabled());
}

static void VideoRotateToFullscreenEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->videoRotateToFullscreenEnabled());
}

static void VideoWakeLockOptimisationHiddenMutedEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->videoWakeLockOptimisationHiddenMutedEnabled());
}

static void VirtualKeyboardEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->virtualKeyboardEnabled());
}

static void VisibilityCollapseColumnEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->visibilityCollapseColumnEnabled());
}

static void WakeLockEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->wakeLockEnabled());
}

static void WebAnimationsAPIEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webAnimationsAPIEnabled());
}

static void WebAnimationsSVGEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webAnimationsSVGEnabled());
}

static void WebAssemblySimdEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webAssemblySimdEnabled());
}

static void WebAssemblyThreadsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webAssemblyThreadsEnabled());
}

static void WebAuthEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webAuthEnabled());
}

static void WebAuthenticationGetAssertionFeaturePolicyEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webAuthenticationGetAssertionFeaturePolicyEnabled());
}

static void WebBluetoothEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webBluetoothEnabled());
}

static void WebBluetoothGetDevicesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webBluetoothGetDevicesEnabled());
}

static void WebBluetoothRemoteCharacteristicNewWriteValueEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webBluetoothRemoteCharacteristicNewWriteValueEnabled());
}

static void WebBluetoothScanningEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webBluetoothScanningEnabled());
}

static void WebBluetoothWatchAdvertisementsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webBluetoothWatchAdvertisementsEnabled());
}

static void WebCodecsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webCodecsEnabled());
}

static void WebCryptoCurve25519EnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webCryptoCurve25519Enabled());
}

static void WebGL2ComputeContextEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webgl2ComputeContextEnabled());
}

static void WebGLDraftExtensionsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webglDraftExtensionsEnabled());
}

static void WebGLImageChromiumEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webglImageChromiumEnabled());
}

static void WebGPUEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webgpuEnabled());
}

static void WebHIDEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webHIDEnabled());
}

static void WebNFCEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webNFCEnabled());
}

static void WebSchedulerEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webSchedulerEnabled());
}

static void WebShareEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webShareEnabled());
}

static void WebShareV2EnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webShareV2Enabled());
}

static void WebSocketStreamEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->websocketStreamEnabled());
}

static void WebUSBEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webUSBEnabled());
}

static void WebUSBOnDedicatedWorkersEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webUSBOnDedicatedWorkersEnabled());
}

static void WebVTTRegionsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webVTTRegionsEnabled());
}

static void WebXREnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXREnabled());
}

static void WebXRAnchorsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXRAnchorsEnabled());
}

static void WebXRARModuleEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXRARModuleEnabled());
}

static void WebXRCameraAccessEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXRCameraAccessEnabled());
}

static void WebXRHitTestEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXRHitTestEnabled());
}

static void WebXRHitTestEntityTypesEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXRHitTestEntityTypesEnabled());
}

static void WebXRLightEstimationEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXRLightEstimationEnabled());
}

static void WebXRPlaneDetectionEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->webXRPlaneDetectionEnabled());
}

static void WindowPlacementEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->windowPlacementEnabled());
}

static void WindowSegmentsEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->windowSegmentsEnabled());
}

static void XsltEnabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  InternalRuntimeFlags* impl = V8InternalRuntimeFlags::ToImpl(holder);

  V8SetReturnValueBool(info, impl->xsltEnabled());
}

}  // namespace internal_runtime_flags_v8_internal

void V8InternalRuntimeFlags::Accelerated2dCanvasEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_accelerated2dCanvasEnabled_Getter");

  internal_runtime_flags_v8_internal::Accelerated2dCanvasEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::Accelerated2dCanvasEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_accelerated2dCanvasEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::Accelerated2dCanvasEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::AcceleratedSmallCanvasesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_acceleratedSmallCanvasesEnabled_Getter");

  internal_runtime_flags_v8_internal::AcceleratedSmallCanvasesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AccessibilityExposeARIAAnnotationsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_accessibilityExposeARIAAnnotationsEnabled_Getter");

  internal_runtime_flags_v8_internal::AccessibilityExposeARIAAnnotationsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AccessibilityExposeDisplayNoneEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_accessibilityExposeDisplayNoneEnabled_Getter");

  internal_runtime_flags_v8_internal::AccessibilityExposeDisplayNoneEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AccessibilityExposeHTMLElementEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_accessibilityExposeHTMLElementEnabled_Getter");

  internal_runtime_flags_v8_internal::AccessibilityExposeHTMLElementEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AccessibilityObjectModelEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_accessibilityObjectModelEnabled_Getter");

  internal_runtime_flags_v8_internal::AccessibilityObjectModelEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AddressSpaceEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_addressSpaceEnabled_Getter");

  internal_runtime_flags_v8_internal::AddressSpaceEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AdTaggingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_adTaggingEnabled_Getter");

  internal_runtime_flags_v8_internal::AdTaggingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AllowActivationDelegationAttrEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_allowActivationDelegationAttrEnabled_Getter");

  internal_runtime_flags_v8_internal::AllowActivationDelegationAttrEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AllowContentInitiatedDataUrlNavigationsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_allowContentInitiatedDataUrlNavigationsEnabled_Getter");

  internal_runtime_flags_v8_internal::AllowContentInitiatedDataUrlNavigationsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AllowSyncXHRInPageDismissalEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_allowSyncXHRInPageDismissalEnabled_Getter");

  internal_runtime_flags_v8_internal::AllowSyncXHRInPageDismissalEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AnimationWorkletEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_animationWorkletEnabled_Getter");

  internal_runtime_flags_v8_internal::AnimationWorkletEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AomAriaPropertiesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_aomAriaPropertiesEnabled_Getter");

  internal_runtime_flags_v8_internal::AomAriaPropertiesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AomAriaRelationshipPropertiesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_aomAriaRelationshipPropertiesEnabled_Getter");

  internal_runtime_flags_v8_internal::AomAriaRelationshipPropertiesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AppCacheEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_appCacheEnabled_Getter");

  internal_runtime_flags_v8_internal::AppCacheEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AudioOutputDevicesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_audioOutputDevicesEnabled_Getter");

  internal_runtime_flags_v8_internal::AudioOutputDevicesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AudioVideoTracksEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_audioVideoTracksEnabled_Getter");

  internal_runtime_flags_v8_internal::AudioVideoTracksEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AudioWorkletRealtimeThreadEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_audioWorkletRealtimeThreadEnabled_Getter");

  internal_runtime_flags_v8_internal::AudioWorkletRealtimeThreadEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AutoLazyLoadOnReloadsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_autoLazyLoadOnReloadsEnabled_Getter");

  internal_runtime_flags_v8_internal::AutoLazyLoadOnReloadsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AutomaticLazyFrameLoadingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_automaticLazyFrameLoadingEnabled_Getter");

  internal_runtime_flags_v8_internal::AutomaticLazyFrameLoadingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AutomaticLazyImageLoadingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_automaticLazyImageLoadingEnabled_Getter");

  internal_runtime_flags_v8_internal::AutomaticLazyImageLoadingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AutomationControlledEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_automationControlledEnabled_Getter");

  internal_runtime_flags_v8_internal::AutomationControlledEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AutomationControlledEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_automationControlledEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::AutomationControlledEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::AutoPictureInPictureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_autoPictureInPictureEnabled_Getter");

  internal_runtime_flags_v8_internal::AutoPictureInPictureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AutoplayIgnoresWebAudioEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_autoplayIgnoresWebAudioEnabled_Getter");

  internal_runtime_flags_v8_internal::AutoplayIgnoresWebAudioEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::AutoplayIgnoresWebAudioEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_autoplayIgnoresWebAudioEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::AutoplayIgnoresWebAudioEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::BackForwardCacheEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_backForwardCacheEnabled_Getter");

  internal_runtime_flags_v8_internal::BackForwardCacheEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BackgroundFetchEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_backgroundFetchEnabled_Getter");

  internal_runtime_flags_v8_internal::BackgroundFetchEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BackgroundVideoTrackOptimizationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_backgroundVideoTrackOptimizationEnabled_Getter");

  internal_runtime_flags_v8_internal::BackgroundVideoTrackOptimizationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BadgingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_badgingEnabled_Getter");

  internal_runtime_flags_v8_internal::BadgingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BarcodeDetectorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_barcodeDetectorEnabled_Getter");

  internal_runtime_flags_v8_internal::BarcodeDetectorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BeforeMatchEventEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_beforeMatchEventEnabled_Getter");

  internal_runtime_flags_v8_internal::BeforeMatchEventEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BidiCaretAffinityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_bidiCaretAffinityEnabled_Getter");

  internal_runtime_flags_v8_internal::BidiCaretAffinityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BlinkRuntimeCallStatsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_blinkRuntimeCallStatsEnabled_Getter");

  internal_runtime_flags_v8_internal::BlinkRuntimeCallStatsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BlockCredentialedSubresourcesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_blockCredentialedSubresourcesEnabled_Getter");

  internal_runtime_flags_v8_internal::BlockCredentialedSubresourcesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BlockFlowHandlesWebkitLineClampEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_blockFlowHandlesWebkitLineClampEnabled_Getter");

  internal_runtime_flags_v8_internal::BlockFlowHandlesWebkitLineClampEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BlockHTMLParserOnStyleSheetsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_blockHTMLParserOnStyleSheetsEnabled_Getter");

  internal_runtime_flags_v8_internal::BlockHTMLParserOnStyleSheetsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BlockingDownloadsInSandboxEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_blockingDownloadsInSandboxEnabled_Getter");

  internal_runtime_flags_v8_internal::BlockingDownloadsInSandboxEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BlockingFocusWithoutUserActivationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_blockingFocusWithoutUserActivationEnabled_Getter");

  internal_runtime_flags_v8_internal::BlockingFocusWithoutUserActivationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BrowserVerifiedUserActivationKeyboardEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_browserVerifiedUserActivationKeyboardEnabled_Getter");

  internal_runtime_flags_v8_internal::BrowserVerifiedUserActivationKeyboardEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::BrowserVerifiedUserActivationMouseEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_browserVerifiedUserActivationMouseEnabled_Getter");

  internal_runtime_flags_v8_internal::BrowserVerifiedUserActivationMouseEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CacheInlineScriptCodeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cacheInlineScriptCodeEnabled_Getter");

  internal_runtime_flags_v8_internal::CacheInlineScriptCodeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CacheStorageCodeCacheHintEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cacheStorageCodeCacheHintEnabled_Getter");

  internal_runtime_flags_v8_internal::CacheStorageCodeCacheHintEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::Canvas2dContextLostRestoredEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_canvas2dContextLostRestoredEnabled_Getter");

  internal_runtime_flags_v8_internal::Canvas2dContextLostRestoredEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::Canvas2dImageChromiumEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_canvas2dImageChromiumEnabled_Getter");

  internal_runtime_flags_v8_internal::Canvas2dImageChromiumEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::Canvas2dScrollPathIntoViewEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_canvas2dScrollPathIntoViewEnabled_Getter");

  internal_runtime_flags_v8_internal::Canvas2dScrollPathIntoViewEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CanvasColorManagementEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_canvasColorManagementEnabled_Getter");

  internal_runtime_flags_v8_internal::CanvasColorManagementEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CanvasHitRegionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_canvasHitRegionEnabled_Getter");

  internal_runtime_flags_v8_internal::CanvasHitRegionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CanvasImageSmoothingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_canvasImageSmoothingEnabled_Getter");

  internal_runtime_flags_v8_internal::CanvasImageSmoothingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CaptureTimeInCsrcEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_captureTimeInCsrcEnabled_Getter");

  internal_runtime_flags_v8_internal::CaptureTimeInCsrcEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ClickPointerEventEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_clickPointerEventEnabled_Getter");

  internal_runtime_flags_v8_internal::ClickPointerEventEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ClickRetargettingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_clickRetargettingEnabled_Getter");

  internal_runtime_flags_v8_internal::ClickRetargettingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CompositeAfterPaintEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_compositeAfterPaintEnabled_Getter");

  internal_runtime_flags_v8_internal::CompositeAfterPaintEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CompositedSelectionUpdateEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_compositedSelectionUpdateEnabled_Getter");

  internal_runtime_flags_v8_internal::CompositedSelectionUpdateEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ComputedAccessibilityInfoEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_computedAccessibilityInfoEnabled_Getter");

  internal_runtime_flags_v8_internal::ComputedAccessibilityInfoEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ConsolidatedMovementXYEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_consolidatedMovementXYEnabled_Getter");

  internal_runtime_flags_v8_internal::ConsolidatedMovementXYEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ContactsManagerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_contactsManagerEnabled_Getter");

  internal_runtime_flags_v8_internal::ContactsManagerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ContactsManagerExtraPropertiesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_contactsManagerExtraPropertiesEnabled_Getter");

  internal_runtime_flags_v8_internal::ContactsManagerExtraPropertiesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ContentIndexEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_contentIndexEnabled_Getter");

  internal_runtime_flags_v8_internal::ContentIndexEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ContextMenuEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_contextMenuEnabled_Getter");

  internal_runtime_flags_v8_internal::ContextMenuEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ConversionMeasurementEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_conversionMeasurementEnabled_Getter");

  internal_runtime_flags_v8_internal::ConversionMeasurementEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CookieDeprecationMessagesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cookieDeprecationMessagesEnabled_Getter");

  internal_runtime_flags_v8_internal::CookieDeprecationMessagesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CookieStoreDocumentEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cookieStoreDocumentEnabled_Getter");

  internal_runtime_flags_v8_internal::CookieStoreDocumentEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CookieStoreWorkerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cookieStoreWorkerEnabled_Getter");

  internal_runtime_flags_v8_internal::CookieStoreWorkerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CookiesWithoutSameSiteMustBeSecureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cookiesWithoutSameSiteMustBeSecureEnabled_Getter");

  internal_runtime_flags_v8_internal::CookiesWithoutSameSiteMustBeSecureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CooperativeSchedulingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cooperativeSchedulingEnabled_Getter");

  internal_runtime_flags_v8_internal::CooperativeSchedulingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CorsRFC1918EnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_corsRFC1918Enabled_Getter");

  internal_runtime_flags_v8_internal::CorsRFC1918EnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CrossOriginIsolationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_crossOriginIsolationEnabled_Getter");

  internal_runtime_flags_v8_internal::CrossOriginIsolationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSS3TextEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_css3TextEnabled_Getter");

  internal_runtime_flags_v8_internal::CSS3TextEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSAspectRatioPropertyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssAspectRatioPropertyEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSAspectRatioPropertyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSCalcAsIntEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssCalcAsIntEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSCalcAsIntEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSCascadeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssCascadeEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSCascadeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSColorSchemeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssColorSchemeEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSColorSchemeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSColorSchemeUARenderingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssColorSchemeUARenderingEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSColorSchemeUARenderingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSContentVisibilityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssContentVisibilityEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSContentVisibilityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSContentVisibilityHiddenMatchableEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssContentVisibilityHiddenMatchableEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSContentVisibilityHiddenMatchableEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSFocusVisibleEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssFocusVisibleEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSFocusVisibleEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSFoldablesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssFoldablesEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSFoldablesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSFontSizeAdjustEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssFontSizeAdjustEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSFontSizeAdjustEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSHexAlphaColorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssHexAlphaColorEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSHexAlphaColorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSIndependentTransformPropertiesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssIndependentTransformPropertiesEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSIndependentTransformPropertiesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSLayoutAPIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssLayoutAPIEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSLayoutAPIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSLogicalEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssLogicalEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSLogicalEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSLogicalEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssLogicalEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::CSSLogicalEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::CSSLogicalOverflowEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssLogicalOverflowEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSLogicalOverflowEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSMarkerNestedPseudoElementEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssMarkerNestedPseudoElementEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSMarkerNestedPseudoElementEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSMarkerPseudoElementEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssMarkerPseudoElementEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSMarkerPseudoElementEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSMatchedPropertiesCacheDependenciesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssMatchedPropertiesCacheDependenciesEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSMatchedPropertiesCacheDependenciesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSMathStyleEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssMathStyleEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSMathStyleEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSMathSuperscriptShiftStyleEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssMathSuperscriptShiftStyleEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSMathSuperscriptShiftStyleEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSMathVariantEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssMathVariantEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSMathVariantEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSModulesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssModulesEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSModulesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSOffsetPathRayEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssOffsetPathRayEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSOffsetPathRayEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSOffsetPathRayContainEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssOffsetPathRayContainEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSOffsetPathRayContainEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSOffsetPositionAnchorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssOffsetPositionAnchorEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSOffsetPositionAnchorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSOMViewScrollCoordinatesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssomViewScrollCoordinatesEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSOMViewScrollCoordinatesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSPaintAPIArgumentsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssPaintAPIArgumentsEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSPaintAPIArgumentsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSPictureInPictureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssPictureInPictureEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSPictureInPictureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSPseudoIsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssPseudoIsEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSPseudoIsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSPseudoWhereEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssPseudoWhereEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSPseudoWhereEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSReducedFontLoadingInvalidationsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssReducedFontLoadingInvalidationsEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSReducedFontLoadingInvalidationsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSReducedFontLoadingLayoutInvalidationsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssReducedFontLoadingLayoutInvalidationsEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSReducedFontLoadingLayoutInvalidationsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSRevertEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssRevertEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSRevertEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSScrollTimelineEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssScrollTimelineEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSScrollTimelineEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSSnapSizeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssSnapSizeEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSSnapSizeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSSupportsSelectorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssSupportsSelectorEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSSupportsSelectorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSVariables2AtPropertyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssVariables2AtPropertyEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSVariables2AtPropertyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSVariables2ImageValuesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssVariables2ImageValuesEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSVariables2ImageValuesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CSSVariables2TransformValuesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_cssVariables2TransformValuesEnabled_Getter");

  internal_runtime_flags_v8_internal::CSSVariables2TransformValuesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CustomElementDefaultStyleEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_customElementDefaultStyleEnabled_Getter");

  internal_runtime_flags_v8_internal::CustomElementDefaultStyleEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CustomElementsV0EnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_customElementsV0Enabled_Getter");

  internal_runtime_flags_v8_internal::CustomElementsV0EnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::CustomStatePseudoClassEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_customStatePseudoClassEnabled_Getter");

  internal_runtime_flags_v8_internal::CustomStatePseudoClassEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DatabaseEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_databaseEnabled_Getter");

  internal_runtime_flags_v8_internal::DatabaseEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DeclarativeShadowDOMEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_declarativeShadowDOMEnabled_Getter");

  internal_runtime_flags_v8_internal::DeclarativeShadowDOMEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DecodeJpeg420ImagesToYUVEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_decodeJpeg420ImagesToYUVEnabled_Getter");

  internal_runtime_flags_v8_internal::DecodeJpeg420ImagesToYUVEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DecodeLossyWebPImagesToYUVEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_decodeLossyWebPImagesToYUVEnabled_Getter");

  internal_runtime_flags_v8_internal::DecodeLossyWebPImagesToYUVEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DelayAsyncScriptExecutionUntilFinishedParsingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_delayAsyncScriptExecutionUntilFinishedParsingEnabled_Getter");

  internal_runtime_flags_v8_internal::DelayAsyncScriptExecutionUntilFinishedParsingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_delayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled_Getter");

  internal_runtime_flags_v8_internal::DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DelegatedInkTrailsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_delegatedInkTrailsEnabled_Getter");

  internal_runtime_flags_v8_internal::DelegatedInkTrailsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DesktopCaptureDisableLocalEchoControlEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_desktopCaptureDisableLocalEchoControlEnabled_Getter");

  internal_runtime_flags_v8_internal::DesktopCaptureDisableLocalEchoControlEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DigitalGoodsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_digitalGoodsEnabled_Getter");

  internal_runtime_flags_v8_internal::DigitalGoodsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DisableHardwareNoiseSuppressionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_disableHardwareNoiseSuppressionEnabled_Getter");

  internal_runtime_flags_v8_internal::DisableHardwareNoiseSuppressionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DisableLayerSquashingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_disableLayerSquashingEnabled_Getter");

  internal_runtime_flags_v8_internal::DisableLayerSquashingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DisallowDocumentAccessEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_disallowDocumentAccessEnabled_Getter");

  internal_runtime_flags_v8_internal::DisallowDocumentAccessEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DisplayCutoutAPIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_displayCutoutAPIEnabled_Getter");

  internal_runtime_flags_v8_internal::DisplayCutoutAPIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DisplayCutoutAPIEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_displayCutoutAPIEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::DisplayCutoutAPIEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::DocumentCookieEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_documentCookieEnabled_Getter");

  internal_runtime_flags_v8_internal::DocumentCookieEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DocumentDomainEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_documentDomainEnabled_Getter");

  internal_runtime_flags_v8_internal::DocumentDomainEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DocumentPolicyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_documentPolicyEnabled_Getter");

  internal_runtime_flags_v8_internal::DocumentPolicyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::DocumentWriteEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_documentWriteEnabled_Getter");

  internal_runtime_flags_v8_internal::DocumentWriteEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::EditContextEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_editContextEnabled_Getter");

  internal_runtime_flags_v8_internal::EditContextEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::EditContextEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_editContextEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::EditContextEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::EditingNGEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_editingNGEnabled_Getter");

  internal_runtime_flags_v8_internal::EditingNGEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::EncryptedMediaEncryptionSchemeQueryEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_encryptedMediaEncryptionSchemeQueryEnabled_Getter");

  internal_runtime_flags_v8_internal::EncryptedMediaEncryptionSchemeQueryEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::EncryptedMediaHdcpPolicyCheckEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_encryptedMediaHdcpPolicyCheckEnabled_Getter");

  internal_runtime_flags_v8_internal::EncryptedMediaHdcpPolicyCheckEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::EncryptedMediaPersistentUsageRecordSessionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_encryptedMediaPersistentUsageRecordSessionEnabled_Getter");

  internal_runtime_flags_v8_internal::EncryptedMediaPersistentUsageRecordSessionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::EnterKeyHintAttributeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_enterKeyHintAttributeEnabled_Getter");

  internal_runtime_flags_v8_internal::EnterKeyHintAttributeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::EventTimingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_eventTimingEnabled_Getter");

  internal_runtime_flags_v8_internal::EventTimingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExecCommandInJavaScriptEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_execCommandInJavaScriptEnabled_Getter");

  internal_runtime_flags_v8_internal::ExecCommandInJavaScriptEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExpensiveBackgroundTimerThrottlingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_expensiveBackgroundTimerThrottlingEnabled_Getter");

  internal_runtime_flags_v8_internal::ExpensiveBackgroundTimerThrottlingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExperimentalAutoplayDynamicDelegationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_experimentalAutoplayDynamicDelegationEnabled_Getter");

  internal_runtime_flags_v8_internal::ExperimentalAutoplayDynamicDelegationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExperimentalContentSecurityPolicyFeaturesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_experimentalContentSecurityPolicyFeaturesEnabled_Getter");

  internal_runtime_flags_v8_internal::ExperimentalContentSecurityPolicyFeaturesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExperimentalIsInputPendingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_experimentalIsInputPendingEnabled_Getter");

  internal_runtime_flags_v8_internal::ExperimentalIsInputPendingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExperimentalJSProfilerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_experimentalJSProfilerEnabled_Getter");

  internal_runtime_flags_v8_internal::ExperimentalJSProfilerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExperimentalProductivityFeaturesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_experimentalProductivityFeaturesEnabled_Getter");

  internal_runtime_flags_v8_internal::ExperimentalProductivityFeaturesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExtendedTextMetricsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_extendedTextMetricsEnabled_Getter");

  internal_runtime_flags_v8_internal::ExtendedTextMetricsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ExtraWebGLVideoTextureMetadataEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_extraWebGLVideoTextureMetadataEnabled_Getter");

  internal_runtime_flags_v8_internal::ExtraWebGLVideoTextureMetadataEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FaceDetectorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_faceDetectorEnabled_Getter");

  internal_runtime_flags_v8_internal::FaceDetectorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FeaturePolicyForClientHintsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_featurePolicyForClientHintsEnabled_Getter");

  internal_runtime_flags_v8_internal::FeaturePolicyForClientHintsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FeaturePolicyForSandboxEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_featurePolicyForSandboxEnabled_Getter");

  internal_runtime_flags_v8_internal::FeaturePolicyForSandboxEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FeaturePolicyReportingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_featurePolicyReportingEnabled_Getter");

  internal_runtime_flags_v8_internal::FeaturePolicyReportingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FeaturePolicyVibrateFeatureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_featurePolicyVibrateFeatureEnabled_Getter");

  internal_runtime_flags_v8_internal::FeaturePolicyVibrateFeatureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FetchUploadStreamingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_fetchUploadStreamingEnabled_Getter");

  internal_runtime_flags_v8_internal::FetchUploadStreamingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FileHandlingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_fileHandlingEnabled_Getter");

  internal_runtime_flags_v8_internal::FileHandlingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FileSystemEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_fileSystemEnabled_Getter");

  internal_runtime_flags_v8_internal::FileSystemEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FlexGapsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_flexGapsEnabled_Getter");

  internal_runtime_flags_v8_internal::FlexGapsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FocuslessSpatialNavigationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_focuslessSpatialNavigationEnabled_Getter");

  internal_runtime_flags_v8_internal::FocuslessSpatialNavigationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FocuslessSpatialNavigationEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_focuslessSpatialNavigationEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::FocuslessSpatialNavigationEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::FontAccessEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_fontAccessEnabled_Getter");

  internal_runtime_flags_v8_internal::FontAccessEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FontSrcLocalMatchingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_fontSrcLocalMatchingEnabled_Getter");

  internal_runtime_flags_v8_internal::FontSrcLocalMatchingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ForcedColorsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_forcedColorsEnabled_Getter");

  internal_runtime_flags_v8_internal::ForcedColorsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ForceDeferScriptInterventionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_forceDeferScriptInterventionEnabled_Getter");

  internal_runtime_flags_v8_internal::ForceDeferScriptInterventionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ForceEagerMeasureMemoryEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_forceEagerMeasureMemoryEnabled_Getter");

  internal_runtime_flags_v8_internal::ForceEagerMeasureMemoryEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ForceLoadAtTopEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_forceLoadAtTopEnabled_Getter");

  internal_runtime_flags_v8_internal::ForceLoadAtTopEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ForceOverlayFullscreenVideoEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_forceOverlayFullscreenVideoEnabled_Getter");

  internal_runtime_flags_v8_internal::ForceOverlayFullscreenVideoEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ForceSynchronousHTMLParsingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_forceSynchronousHTMLParsingEnabled_Getter");

  internal_runtime_flags_v8_internal::ForceSynchronousHTMLParsingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ForceTallerSelectPopupEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_forceTallerSelectPopupEnabled_Getter");

  internal_runtime_flags_v8_internal::ForceTallerSelectPopupEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FractionalScrollOffsetsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_fractionalScrollOffsetsEnabled_Getter");

  internal_runtime_flags_v8_internal::FractionalScrollOffsetsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::FreezeFramesOnVisibilityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_freezeFramesOnVisibilityEnabled_Getter");

  internal_runtime_flags_v8_internal::FreezeFramesOnVisibilityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::GamepadButtonAxisEventsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_gamepadButtonAxisEventsEnabled_Getter");

  internal_runtime_flags_v8_internal::GamepadButtonAxisEventsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::GetDisplayMediaEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_getDisplayMediaEnabled_Getter");

  internal_runtime_flags_v8_internal::GetDisplayMediaEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::GroupEffectEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_groupEffectEnabled_Getter");

  internal_runtime_flags_v8_internal::GroupEffectEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::HrefTranslateEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_hrefTranslateEnabled_Getter");

  internal_runtime_flags_v8_internal::HrefTranslateEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::HTMLImportsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_htmlImportsEnabled_Getter");

  internal_runtime_flags_v8_internal::HTMLImportsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::IdbObserverEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_idbObserverEnabled_Getter");

  internal_runtime_flags_v8_internal::IdbObserverEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::IdbRelaxedDurabilityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_idbRelaxedDurabilityEnabled_Getter");

  internal_runtime_flags_v8_internal::IdbRelaxedDurabilityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::IdleDetectionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_idleDetectionEnabled_Getter");

  internal_runtime_flags_v8_internal::IdleDetectionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_ignoreCrossOriginWindowWhenNamedAccessOnWindowEnabled_Getter");

  internal_runtime_flags_v8_internal::IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ImageOrientationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_imageOrientationEnabled_Getter");

  internal_runtime_flags_v8_internal::ImageOrientationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ImplicitRootScrollerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_implicitRootScrollerEnabled_Getter");

  internal_runtime_flags_v8_internal::ImplicitRootScrollerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ImplicitRootScrollerEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_implicitRootScrollerEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::ImplicitRootScrollerEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::ImportMapsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_importMapsEnabled_Getter");

  internal_runtime_flags_v8_internal::ImportMapsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::InertAttributeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_inertAttributeEnabled_Getter");

  internal_runtime_flags_v8_internal::InertAttributeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::InputElementRawValueEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_inputElementRawValueEnabled_Getter");

  internal_runtime_flags_v8_internal::InputElementRawValueEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::InputMultipleFieldsUIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_inputMultipleFieldsUIEnabled_Getter");

  internal_runtime_flags_v8_internal::InputMultipleFieldsUIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::InstalledAppEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_installedAppEnabled_Getter");

  internal_runtime_flags_v8_internal::InstalledAppEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::IntersectionObserverDocumentScrollingElementRootEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_intersectionObserverDocumentScrollingElementRootEnabled_Getter");

  internal_runtime_flags_v8_internal::IntersectionObserverDocumentScrollingElementRootEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::IsolatedCodeCacheEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_isolatedCodeCacheEnabled_Getter");

  internal_runtime_flags_v8_internal::IsolatedCodeCacheEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::IsolatedWorldCSPEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_isolatedWorldCSPEnabled_Getter");

  internal_runtime_flags_v8_internal::IsolatedWorldCSPEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::KeyboardFocusableScrollersEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_keyboardFocusableScrollersEnabled_Getter");

  internal_runtime_flags_v8_internal::KeyboardFocusableScrollersEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LangAttributeAwareFormControlUIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_langAttributeAwareFormControlUIEnabled_Getter");

  internal_runtime_flags_v8_internal::LangAttributeAwareFormControlUIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LangClientHintHeaderEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_langClientHintHeaderEnabled_Getter");

  internal_runtime_flags_v8_internal::LangClientHintHeaderEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGBlockFragmentationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGBlockFragmentationEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGBlockFragmentationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGFieldsetEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGFieldsetEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGFieldsetEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGFlexBoxEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGFlexBoxEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGFlexBoxEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGForControlsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGForControlsEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGForControlsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGFragmentItemEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGFragmentItemEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGFragmentItemEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGFragmentTraversalEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGFragmentTraversalEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGFragmentTraversalEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGGridEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGGridEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGGridEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGRubyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGRubyEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGRubyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutNGTableEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutNGTableEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutNGTableEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LayoutShiftAttributionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_layoutShiftAttributionEnabled_Getter");

  internal_runtime_flags_v8_internal::LayoutShiftAttributionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LazyFrameLoadingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_lazyFrameLoadingEnabled_Getter");

  internal_runtime_flags_v8_internal::LazyFrameLoadingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LazyFrameVisibleLoadTimeMetricsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_lazyFrameVisibleLoadTimeMetricsEnabled_Getter");

  internal_runtime_flags_v8_internal::LazyFrameVisibleLoadTimeMetricsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LazyImageLoadingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_lazyImageLoadingEnabled_Getter");

  internal_runtime_flags_v8_internal::LazyImageLoadingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LazyImageVisibleLoadTimeMetricsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_lazyImageVisibleLoadTimeMetricsEnabled_Getter");

  internal_runtime_flags_v8_internal::LazyImageVisibleLoadTimeMetricsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LazyInitializeMediaControlsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_lazyInitializeMediaControlsEnabled_Getter");

  internal_runtime_flags_v8_internal::LazyInitializeMediaControlsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LegacyNativeFileSystemEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_legacyNativeFileSystemEnabled_Getter");

  internal_runtime_flags_v8_internal::LegacyNativeFileSystemEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LegacyWindowsDWriteFontFallbackEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_legacyWindowsDWriteFontFallbackEnabled_Getter");

  internal_runtime_flags_v8_internal::LegacyWindowsDWriteFontFallbackEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::LinkDisabledNewSpecBehaviorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_linkDisabledNewSpecBehaviorEnabled_Getter");

  internal_runtime_flags_v8_internal::LinkDisabledNewSpecBehaviorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ManualSlottingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_manualSlottingEnabled_Getter");

  internal_runtime_flags_v8_internal::ManualSlottingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MathMLCoreEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mathmlCoreEnabled_Getter");

  internal_runtime_flags_v8_internal::MathMLCoreEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MeasureMemoryEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_measureMemoryEnabled_Getter");

  internal_runtime_flags_v8_internal::MeasureMemoryEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCapabilitiesDynamicRangeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCapabilitiesDynamicRangeEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCapabilitiesDynamicRangeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCapabilitiesEncodingInfoEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCapabilitiesEncodingInfoEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCapabilitiesEncodingInfoEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCapabilitiesEncryptedMediaEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCapabilitiesEncryptedMediaEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCapabilitiesEncryptedMediaEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCapabilitiesSpatialAudioEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCapabilitiesSpatialAudioEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCapabilitiesSpatialAudioEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCaptureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCaptureEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCaptureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCaptureDepthVideoKindEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCaptureDepthVideoKindEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCaptureDepthVideoKindEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCapturePanTiltEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCapturePanTiltEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCapturePanTiltEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaCastOverlayButtonEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaCastOverlayButtonEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaCastOverlayButtonEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaControlsExpandGestureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaControlsExpandGestureEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaControlsExpandGestureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaControlsOverlayPlayButtonEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaControlsOverlayPlayButtonEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaControlsOverlayPlayButtonEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaControlsOverlayPlayButtonEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaControlsOverlayPlayButtonEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::MediaControlsOverlayPlayButtonEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::MediaControlsUseCutOutByDefaultEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaControlsUseCutOutByDefaultEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaControlsUseCutOutByDefaultEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaDocumentDownloadButtonEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaDocumentDownloadButtonEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaDocumentDownloadButtonEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaElementVolumeGreaterThanOneEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaElementVolumeGreaterThanOneEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaElementVolumeGreaterThanOneEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaEngagementBypassAutoplayPoliciesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaEngagementBypassAutoplayPoliciesEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaEngagementBypassAutoplayPoliciesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaFeedsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaFeedsEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaFeedsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaLatencyHintEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaLatencyHintEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaLatencyHintEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaQueryNavigationControlsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaQueryNavigationControlsEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaQueryNavigationControlsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaSessionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaSessionEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaSessionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaSessionPositionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaSessionPositionEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaSessionPositionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaSourceExperimentalEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaSourceExperimentalEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaSourceExperimentalEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaSourceInWorkersEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaSourceInWorkersEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaSourceInWorkersEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaSourceNewAbortAndDurationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaSourceNewAbortAndDurationEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaSourceNewAbortAndDurationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MediaSourceStableEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mediaSourceStableEnabled_Getter");

  internal_runtime_flags_v8_internal::MediaSourceStableEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MetaColorSchemeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_metaColorSchemeEnabled_Getter");

  internal_runtime_flags_v8_internal::MetaColorSchemeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MiddleClickAutoscrollEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_middleClickAutoscrollEnabled_Getter");

  internal_runtime_flags_v8_internal::MiddleClickAutoscrollEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MobileLayoutThemeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mobileLayoutThemeEnabled_Getter");

  internal_runtime_flags_v8_internal::MobileLayoutThemeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ModuleServiceWorkerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_moduleServiceWorkerEnabled_Getter");

  internal_runtime_flags_v8_internal::ModuleServiceWorkerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ModuleSharedWorkerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_moduleSharedWorkerEnabled_Getter");

  internal_runtime_flags_v8_internal::ModuleSharedWorkerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MojoJSEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mojoJSEnabled_Getter");

  internal_runtime_flags_v8_internal::MojoJSEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MojoJSTestEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mojoJSTestEnabled_Getter");

  internal_runtime_flags_v8_internal::MojoJSTestEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::MouseSubframeNoImplicitCaptureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_mouseSubframeNoImplicitCaptureEnabled_Getter");

  internal_runtime_flags_v8_internal::MouseSubframeNoImplicitCaptureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NamedPagesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_namedPagesEnabled_Getter");

  internal_runtime_flags_v8_internal::NamedPagesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NativeFileSystemEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_nativeFileSystemEnabled_Getter");

  internal_runtime_flags_v8_internal::NativeFileSystemEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NativeIOEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_nativeIOEnabled_Getter");

  internal_runtime_flags_v8_internal::NativeIOEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NavigatorContentUtilsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_navigatorContentUtilsEnabled_Getter");

  internal_runtime_flags_v8_internal::NavigatorContentUtilsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NavigatorLanguageInInsecureContextEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_navigatorLanguageInInsecureContextEnabled_Getter");

  internal_runtime_flags_v8_internal::NavigatorLanguageInInsecureContextEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NavigatorLanguageInInsecureContextEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_navigatorLanguageInInsecureContextEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::NavigatorLanguageInInsecureContextEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::NetInfoDownlinkMaxEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_netInfoDownlinkMaxEnabled_Getter");

  internal_runtime_flags_v8_internal::NetInfoDownlinkMaxEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NeverSlowModeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_neverSlowModeEnabled_Getter");

  internal_runtime_flags_v8_internal::NeverSlowModeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NewCanvas2DAPIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_newCanvas2DAPIEnabled_Getter");

  internal_runtime_flags_v8_internal::NewCanvas2DAPIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NewRemotePlaybackPipelineEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_newRemotePlaybackPipelineEnabled_Getter");

  internal_runtime_flags_v8_internal::NewRemotePlaybackPipelineEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NoIdleEncodingForWebTestsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_noIdleEncodingForWebTestsEnabled_Getter");

  internal_runtime_flags_v8_internal::NoIdleEncodingForWebTestsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NotificationConstructorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_notificationConstructorEnabled_Getter");

  internal_runtime_flags_v8_internal::NotificationConstructorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NotificationContentImageEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_notificationContentImageEnabled_Getter");

  internal_runtime_flags_v8_internal::NotificationContentImageEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NotificationsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_notificationsEnabled_Getter");

  internal_runtime_flags_v8_internal::NotificationsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::NotificationTriggersEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_notificationTriggersEnabled_Getter");

  internal_runtime_flags_v8_internal::NotificationTriggersEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OffMainThreadCSSPaintEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_offMainThreadCSSPaintEnabled_Getter");

  internal_runtime_flags_v8_internal::OffMainThreadCSSPaintEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OffscreenCanvasCommitEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_offscreenCanvasCommitEnabled_Getter");

  internal_runtime_flags_v8_internal::OffscreenCanvasCommitEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OnDeviceChangeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_onDeviceChangeEnabled_Getter");

  internal_runtime_flags_v8_internal::OnDeviceChangeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OrientationEventEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_orientationEventEnabled_Getter");

  internal_runtime_flags_v8_internal::OrientationEventEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginIsolationHeaderEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originIsolationHeaderEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginIsolationHeaderEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginPolicyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originPolicyEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginPolicyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginTrialsSampleAPIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originTrialsSampleAPIEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginTrialsSampleAPIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginTrialsSampleAPIDependentEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originTrialsSampleAPIDependentEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginTrialsSampleAPIDependentEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginTrialsSampleAPIDeprecationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originTrialsSampleAPIDeprecationEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginTrialsSampleAPIDeprecationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginTrialsSampleAPIImpliedEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originTrialsSampleAPIImpliedEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginTrialsSampleAPIImpliedEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginTrialsSampleAPIInvalidOSEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originTrialsSampleAPIInvalidOSEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginTrialsSampleAPIInvalidOSEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginTrialsSampleAPINavigationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originTrialsSampleAPINavigationEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginTrialsSampleAPINavigationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OriginTrialsSampleAPIThirdPartyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_originTrialsSampleAPIThirdPartyEnabled_Getter");

  internal_runtime_flags_v8_internal::OriginTrialsSampleAPIThirdPartyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OutOfBlinkCorsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_outOfBlinkCorsEnabled_Getter");

  internal_runtime_flags_v8_internal::OutOfBlinkCorsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OverflowIconsForMediaControlsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_overflowIconsForMediaControlsEnabled_Getter");

  internal_runtime_flags_v8_internal::OverflowIconsForMediaControlsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OverscrollCustomizationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_overscrollCustomizationEnabled_Getter");

  internal_runtime_flags_v8_internal::OverscrollCustomizationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::OverscrollCustomizationEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_overscrollCustomizationEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::OverscrollCustomizationEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::PageFreezeOptInEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pageFreezeOptInEnabled_Getter");

  internal_runtime_flags_v8_internal::PageFreezeOptInEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PageFreezeOptOutEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pageFreezeOptOutEnabled_Getter");

  internal_runtime_flags_v8_internal::PageFreezeOptOutEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PagePopupEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pagePopupEnabled_Getter");

  internal_runtime_flags_v8_internal::PagePopupEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaintUnderInvalidationCheckingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paintUnderInvalidationCheckingEnabled_Getter");

  internal_runtime_flags_v8_internal::PaintUnderInvalidationCheckingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaintUnderInvalidationCheckingEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paintUnderInvalidationCheckingEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::PaintUnderInvalidationCheckingEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::ParseUrlProtocolHandlerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_parseUrlProtocolHandlerEnabled_Getter");

  internal_runtime_flags_v8_internal::ParseUrlProtocolHandlerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PassPaintVisualRectToCompositorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_passPaintVisualRectToCompositorEnabled_Getter");

  internal_runtime_flags_v8_internal::PassPaintVisualRectToCompositorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PasswordRevealEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_passwordRevealEnabled_Getter");

  internal_runtime_flags_v8_internal::PasswordRevealEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentAppEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentAppEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentAppEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentHandlerChangePaymentMethodEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentHandlerChangePaymentMethodEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentHandlerChangePaymentMethodEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentHandlerHandlesShippingAndContactEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentHandlerHandlesShippingAndContactEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentHandlerHandlesShippingAndContactEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentHandlerMinimalUIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentHandlerMinimalUIEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentHandlerMinimalUIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentMethodChangeEventEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentMethodChangeEventEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentMethodChangeEventEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentRequestEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentRequestEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentRequestEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentRequestMerchantValidationEventEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentRequestMerchantValidationEventEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentRequestMerchantValidationEventEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PaymentRetryEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_paymentRetryEnabled_Getter");

  internal_runtime_flags_v8_internal::PaymentRetryEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PercentBasedScrollingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_percentBasedScrollingEnabled_Getter");

  internal_runtime_flags_v8_internal::PercentBasedScrollingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PercentBasedScrollingEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_percentBasedScrollingEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::PercentBasedScrollingEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::PerformanceManagerInstrumentationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_performanceManagerInstrumentationEnabled_Getter");

  internal_runtime_flags_v8_internal::PerformanceManagerInstrumentationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PeriodicBackgroundSyncEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_periodicBackgroundSyncEnabled_Getter");

  internal_runtime_flags_v8_internal::PeriodicBackgroundSyncEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PerMethodCanMakePaymentQuotaEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_perMethodCanMakePaymentQuotaEnabled_Getter");

  internal_runtime_flags_v8_internal::PerMethodCanMakePaymentQuotaEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PermissionDelegationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_permissionDelegationEnabled_Getter");

  internal_runtime_flags_v8_internal::PermissionDelegationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PermissionsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_permissionsEnabled_Getter");

  internal_runtime_flags_v8_internal::PermissionsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PermissionsRequestRevokeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_permissionsRequestRevokeEnabled_Getter");

  internal_runtime_flags_v8_internal::PermissionsRequestRevokeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PictureInPictureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pictureInPictureEnabled_Getter");

  internal_runtime_flags_v8_internal::PictureInPictureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PictureInPictureEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pictureInPictureEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::PictureInPictureEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::PictureInPictureAPIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pictureInPictureAPIEnabled_Getter");

  internal_runtime_flags_v8_internal::PictureInPictureAPIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PictureInPictureV2EnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pictureInPictureV2Enabled_Getter");

  internal_runtime_flags_v8_internal::PictureInPictureV2EnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PictureInPictureV2EnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pictureInPictureV2Enabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::PictureInPictureV2EnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::PNaClEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pNaClEnabled_Getter");

  internal_runtime_flags_v8_internal::PNaClEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PointerLockOptionsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pointerLockOptionsEnabled_Getter");

  internal_runtime_flags_v8_internal::PointerLockOptionsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PointerRawUpdateEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pointerRawUpdateEnabled_Getter");

  internal_runtime_flags_v8_internal::PointerRawUpdateEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PortalsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_portalsEnabled_Getter");

  internal_runtime_flags_v8_internal::PortalsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PostAnimationFrameEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_postAnimationFrameEnabled_Getter");

  internal_runtime_flags_v8_internal::PostAnimationFrameEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PreciseMemoryInfoEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_preciseMemoryInfoEnabled_Getter");

  internal_runtime_flags_v8_internal::PreciseMemoryInfoEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PreferNonCompositedScrollingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_preferNonCompositedScrollingEnabled_Getter");

  internal_runtime_flags_v8_internal::PreferNonCompositedScrollingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PreferNonCompositedScrollingEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_preferNonCompositedScrollingEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::PreferNonCompositedScrollingEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::PrefersReducedDataEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_prefersReducedDataEnabled_Getter");

  internal_runtime_flags_v8_internal::PrefersReducedDataEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PrefixedVideoFullscreenEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_prefixedVideoFullscreenEnabled_Getter");

  internal_runtime_flags_v8_internal::PrefixedVideoFullscreenEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PresentationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_presentationEnabled_Getter");

  internal_runtime_flags_v8_internal::PresentationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PriorityHintsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_priorityHintsEnabled_Getter");

  internal_runtime_flags_v8_internal::PriorityHintsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PushMessagingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pushMessagingEnabled_Getter");

  internal_runtime_flags_v8_internal::PushMessagingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::PushMessagingSubscriptionChangeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_pushMessagingSubscriptionChangeEnabled_Getter");

  internal_runtime_flags_v8_internal::PushMessagingSubscriptionChangeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::QuicTransportEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_quicTransportEnabled_Getter");

  internal_runtime_flags_v8_internal::QuicTransportEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RawClipboardEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rawClipboardEnabled_Getter");

  internal_runtime_flags_v8_internal::RawClipboardEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ReducedReferrerGranularityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_reducedReferrerGranularityEnabled_Getter");

  internal_runtime_flags_v8_internal::ReducedReferrerGranularityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RemotePlaybackEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_remotePlaybackEnabled_Getter");

  internal_runtime_flags_v8_internal::RemotePlaybackEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RemotePlaybackBackendEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_remotePlaybackBackendEnabled_Getter");

  internal_runtime_flags_v8_internal::RemotePlaybackBackendEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RemotePlaybackBackendEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_remotePlaybackBackendEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::RemotePlaybackBackendEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::RequestVideoFrameCallbackEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_requestVideoFrameCallbackEnabled_Getter");

  internal_runtime_flags_v8_internal::RequestVideoFrameCallbackEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ResizeObserverUpdatesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_resizeObserverUpdatesEnabled_Getter");

  internal_runtime_flags_v8_internal::ResizeObserverUpdatesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RestrictAppCacheToSecureContextsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_restrictAppCacheToSecureContextsEnabled_Getter");

  internal_runtime_flags_v8_internal::RestrictAppCacheToSecureContextsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RestrictAutomaticLazyFrameLoadingToDataSaverEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_restrictAutomaticLazyFrameLoadingToDataSaverEnabled_Getter");

  internal_runtime_flags_v8_internal::RestrictAutomaticLazyFrameLoadingToDataSaverEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RestrictAutomaticLazyImageLoadingToDataSaverEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_restrictAutomaticLazyImageLoadingToDataSaverEnabled_Getter");

  internal_runtime_flags_v8_internal::RestrictAutomaticLazyImageLoadingToDataSaverEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCAudioJitterBufferMaxPacketsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcAudioJitterBufferMaxPacketsEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCAudioJitterBufferMaxPacketsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCAudioJitterBufferRtxHandlingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcAudioJitterBufferRtxHandlingEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCAudioJitterBufferRtxHandlingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCIceTransportExtensionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcIceTransportExtensionEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCIceTransportExtensionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCInsertableStreamsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcInsertableStreamsEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCInsertableStreamsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCQuicTransportEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcQuicTransportEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCQuicTransportEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCStatsRelativePacketArrivalDelayEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcStatsRelativePacketArrivalDelayEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCStatsRelativePacketArrivalDelayEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCSvcScalabilityModeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcSvcScalabilityModeEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCSvcScalabilityModeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCUnifiedPlanEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcUnifiedPlanEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCUnifiedPlanEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::RTCUnifiedPlanByDefaultEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_rtcUnifiedPlanByDefaultEnabled_Getter");

  internal_runtime_flags_v8_internal::RTCUnifiedPlanByDefaultEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SameSiteByDefaultCookiesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_sameSiteByDefaultCookiesEnabled_Getter");

  internal_runtime_flags_v8_internal::SameSiteByDefaultCookiesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScreenWakeLockEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_screenWakeLockEnabled_Getter");

  internal_runtime_flags_v8_internal::ScreenWakeLockEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScriptedSpeechRecognitionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_scriptedSpeechRecognitionEnabled_Getter");

  internal_runtime_flags_v8_internal::ScriptedSpeechRecognitionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScriptedSpeechSynthesisEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_scriptedSpeechSynthesisEnabled_Getter");

  internal_runtime_flags_v8_internal::ScriptedSpeechSynthesisEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScrollCustomizationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_scrollCustomizationEnabled_Getter");

  internal_runtime_flags_v8_internal::ScrollCustomizationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScrollSnapAfterLayoutEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_scrollSnapAfterLayoutEnabled_Getter");

  internal_runtime_flags_v8_internal::ScrollSnapAfterLayoutEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScrollTimelineEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_scrollTimelineEnabled_Getter");

  internal_runtime_flags_v8_internal::ScrollTimelineEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScrollTopLeftInteropEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_scrollTopLeftInteropEnabled_Getter");

  internal_runtime_flags_v8_internal::ScrollTopLeftInteropEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ScrollUnificationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_scrollUnificationEnabled_Getter");

  internal_runtime_flags_v8_internal::ScrollUnificationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SendBeaconThrowForBlobWithNonSimpleTypeEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_sendBeaconThrowForBlobWithNonSimpleTypeEnabled_Getter");

  internal_runtime_flags_v8_internal::SendBeaconThrowForBlobWithNonSimpleTypeEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SendMouseEventsDisabledFormControlsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_sendMouseEventsDisabledFormControlsEnabled_Getter");

  internal_runtime_flags_v8_internal::SendMouseEventsDisabledFormControlsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SensorExtraClassesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_sensorExtraClassesEnabled_Getter");

  internal_runtime_flags_v8_internal::SensorExtraClassesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SerialEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_serialEnabled_Getter");

  internal_runtime_flags_v8_internal::SerialEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ServiceWorkerClientLifecycleStateEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_serviceWorkerClientLifecycleStateEnabled_Getter");

  internal_runtime_flags_v8_internal::ServiceWorkerClientLifecycleStateEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ServiceWorkerFetchEventWorkerTimingEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_serviceWorkerFetchEventWorkerTimingEnabled_Getter");

  internal_runtime_flags_v8_internal::ServiceWorkerFetchEventWorkerTimingEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ShadowDOMV0EnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_shadowDOMV0Enabled_Getter");

  internal_runtime_flags_v8_internal::ShadowDOMV0EnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SharedArrayBufferEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_sharedArrayBufferEnabled_Getter");

  internal_runtime_flags_v8_internal::SharedArrayBufferEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SharedWorkerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_sharedWorkerEnabled_Getter");

  internal_runtime_flags_v8_internal::SharedWorkerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SignatureBasedIntegrityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_signatureBasedIntegrityEnabled_Getter");

  internal_runtime_flags_v8_internal::SignatureBasedIntegrityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SignedExchangePrefetchCacheForNavigationsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_signedExchangePrefetchCacheForNavigationsEnabled_Getter");

  internal_runtime_flags_v8_internal::SignedExchangePrefetchCacheForNavigationsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SignedExchangeSubresourcePrefetchEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_signedExchangeSubresourcePrefetchEnabled_Getter");

  internal_runtime_flags_v8_internal::SignedExchangeSubresourcePrefetchEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SkipAdEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_skipAdEnabled_Getter");

  internal_runtime_flags_v8_internal::SkipAdEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SkipTouchEventFilterEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_skipTouchEventFilterEnabled_Getter");

  internal_runtime_flags_v8_internal::SkipTouchEventFilterEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SkipTouchEventFilterEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_skipTouchEventFilterEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::SkipTouchEventFilterEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::SmsReceiverEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_smsReceiverEnabled_Getter");

  internal_runtime_flags_v8_internal::SmsReceiverEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SquashAfterPaintEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_squashAfterPaintEnabled_Getter");

  internal_runtime_flags_v8_internal::SquashAfterPaintEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::StableBlinkFeaturesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_stableBlinkFeaturesEnabled_Getter");

  internal_runtime_flags_v8_internal::StableBlinkFeaturesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::StorageAccessAPIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_storageAccessAPIEnabled_Getter");

  internal_runtime_flags_v8_internal::StorageAccessAPIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::StrictMimeTypesForWorkersEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_strictMimeTypesForWorkersEnabled_Getter");

  internal_runtime_flags_v8_internal::StrictMimeTypesForWorkersEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SubresourceWebBundlesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_subresourceWebBundlesEnabled_Getter");

  internal_runtime_flags_v8_internal::SubresourceWebBundlesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SurfaceEmbeddingFeaturesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_surfaceEmbeddingFeaturesEnabled_Getter");

  internal_runtime_flags_v8_internal::SurfaceEmbeddingFeaturesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::SystemWakeLockEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_systemWakeLockEnabled_Getter");

  internal_runtime_flags_v8_internal::SystemWakeLockEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TestFeatureEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_testFeatureEnabled_Getter");

  internal_runtime_flags_v8_internal::TestFeatureEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TestFeatureDependentEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_testFeatureDependentEnabled_Getter");

  internal_runtime_flags_v8_internal::TestFeatureDependentEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TestFeatureImpliedEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_testFeatureImpliedEnabled_Getter");

  internal_runtime_flags_v8_internal::TestFeatureImpliedEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TextDetectorEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_textDetectorEnabled_Getter");

  internal_runtime_flags_v8_internal::TextDetectorEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TextFragmentIdentifiersEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_textFragmentIdentifiersEnabled_Getter");

  internal_runtime_flags_v8_internal::TextFragmentIdentifiersEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::ThirdPartyOriginTrialsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_thirdPartyOriginTrialsEnabled_Getter");

  internal_runtime_flags_v8_internal::ThirdPartyOriginTrialsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TimerThrottlingForBackgroundTabsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_timerThrottlingForBackgroundTabsEnabled_Getter");

  internal_runtime_flags_v8_internal::TimerThrottlingForBackgroundTabsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TimerThrottlingForHiddenFramesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_timerThrottlingForHiddenFramesEnabled_Getter");

  internal_runtime_flags_v8_internal::TimerThrottlingForHiddenFramesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TimeZoneChangeEventEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_timeZoneChangeEventEnabled_Getter");

  internal_runtime_flags_v8_internal::TimeZoneChangeEventEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TouchEventFeatureDetectionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_touchEventFeatureDetectionEnabled_Getter");

  internal_runtime_flags_v8_internal::TouchEventFeatureDetectionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TrackLayoutPassesPerBlockEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_trackLayoutPassesPerBlockEnabled_Getter");

  internal_runtime_flags_v8_internal::TrackLayoutPassesPerBlockEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TransferableStreamsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_transferableStreamsEnabled_Getter");

  internal_runtime_flags_v8_internal::TransferableStreamsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TransformInteropEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_transformInteropEnabled_Getter");

  internal_runtime_flags_v8_internal::TransformInteropEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TranslateServiceEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_translateServiceEnabled_Getter");

  internal_runtime_flags_v8_internal::TranslateServiceEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TrustedDOMTypesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_trustedDOMTypesEnabled_Getter");

  internal_runtime_flags_v8_internal::TrustedDOMTypesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TrustTokensEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_trustTokensEnabled_Getter");

  internal_runtime_flags_v8_internal::TrustTokensEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::TrustTokensAlwaysAllowIssuanceEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_trustTokensAlwaysAllowIssuanceEnabled_Getter");

  internal_runtime_flags_v8_internal::TrustTokensAlwaysAllowIssuanceEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::UnclosedFormControlIsInvalidEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_unclosedFormControlIsInvalidEnabled_Getter");

  internal_runtime_flags_v8_internal::UnclosedFormControlIsInvalidEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::UnderlineOffsetThicknessEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_underlineOffsetThicknessEnabled_Getter");

  internal_runtime_flags_v8_internal::UnderlineOffsetThicknessEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::UnoptimizedImagePoliciesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_unoptimizedImagePoliciesEnabled_Getter");

  internal_runtime_flags_v8_internal::UnoptimizedImagePoliciesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::UnsizedMediaPolicyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_unsizedMediaPolicyEnabled_Getter");

  internal_runtime_flags_v8_internal::UnsizedMediaPolicyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::UserActivationPostMessageTransferEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_userActivationPostMessageTransferEnabled_Getter");

  internal_runtime_flags_v8_internal::UserActivationPostMessageTransferEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::UserActivationSameOriginVisibilityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_userActivationSameOriginVisibilityEnabled_Getter");

  internal_runtime_flags_v8_internal::UserActivationSameOriginVisibilityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::UserAgentClientHintEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_userAgentClientHintEnabled_Getter");

  internal_runtime_flags_v8_internal::UserAgentClientHintEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::V8IdleTasksEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_v8IdleTasksEnabled_Getter");

  internal_runtime_flags_v8_internal::V8IdleTasksEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::VideoAutoFullscreenEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_videoAutoFullscreenEnabled_Getter");

  internal_runtime_flags_v8_internal::VideoAutoFullscreenEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::VideoAutoFullscreenEnabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_videoAutoFullscreenEnabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  internal_runtime_flags_v8_internal::VideoAutoFullscreenEnabledAttributeSetter(v8_value, info);
}

void V8InternalRuntimeFlags::VideoFullscreenOrientationLockEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_videoFullscreenOrientationLockEnabled_Getter");

  internal_runtime_flags_v8_internal::VideoFullscreenOrientationLockEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::VideoPlaybackQualityEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_videoPlaybackQualityEnabled_Getter");

  internal_runtime_flags_v8_internal::VideoPlaybackQualityEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::VideoRotateToFullscreenEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_videoRotateToFullscreenEnabled_Getter");

  internal_runtime_flags_v8_internal::VideoRotateToFullscreenEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::VideoWakeLockOptimisationHiddenMutedEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_videoWakeLockOptimisationHiddenMutedEnabled_Getter");

  internal_runtime_flags_v8_internal::VideoWakeLockOptimisationHiddenMutedEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::VirtualKeyboardEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_virtualKeyboardEnabled_Getter");

  internal_runtime_flags_v8_internal::VirtualKeyboardEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::VisibilityCollapseColumnEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_visibilityCollapseColumnEnabled_Getter");

  internal_runtime_flags_v8_internal::VisibilityCollapseColumnEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WakeLockEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_wakeLockEnabled_Getter");

  internal_runtime_flags_v8_internal::WakeLockEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebAnimationsAPIEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webAnimationsAPIEnabled_Getter");

  internal_runtime_flags_v8_internal::WebAnimationsAPIEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebAnimationsSVGEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webAnimationsSVGEnabled_Getter");

  internal_runtime_flags_v8_internal::WebAnimationsSVGEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebAssemblySimdEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webAssemblySimdEnabled_Getter");

  internal_runtime_flags_v8_internal::WebAssemblySimdEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebAssemblyThreadsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webAssemblyThreadsEnabled_Getter");

  internal_runtime_flags_v8_internal::WebAssemblyThreadsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebAuthEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webAuthEnabled_Getter");

  internal_runtime_flags_v8_internal::WebAuthEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebAuthenticationGetAssertionFeaturePolicyEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webAuthenticationGetAssertionFeaturePolicyEnabled_Getter");

  internal_runtime_flags_v8_internal::WebAuthenticationGetAssertionFeaturePolicyEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebBluetoothEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webBluetoothEnabled_Getter");

  internal_runtime_flags_v8_internal::WebBluetoothEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebBluetoothGetDevicesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webBluetoothGetDevicesEnabled_Getter");

  internal_runtime_flags_v8_internal::WebBluetoothGetDevicesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebBluetoothRemoteCharacteristicNewWriteValueEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webBluetoothRemoteCharacteristicNewWriteValueEnabled_Getter");

  internal_runtime_flags_v8_internal::WebBluetoothRemoteCharacteristicNewWriteValueEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebBluetoothScanningEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webBluetoothScanningEnabled_Getter");

  internal_runtime_flags_v8_internal::WebBluetoothScanningEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebBluetoothWatchAdvertisementsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webBluetoothWatchAdvertisementsEnabled_Getter");

  internal_runtime_flags_v8_internal::WebBluetoothWatchAdvertisementsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebCodecsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webCodecsEnabled_Getter");

  internal_runtime_flags_v8_internal::WebCodecsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebCryptoCurve25519EnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webCryptoCurve25519Enabled_Getter");

  internal_runtime_flags_v8_internal::WebCryptoCurve25519EnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebGL2ComputeContextEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webgl2ComputeContextEnabled_Getter");

  internal_runtime_flags_v8_internal::WebGL2ComputeContextEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebGLDraftExtensionsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webglDraftExtensionsEnabled_Getter");

  internal_runtime_flags_v8_internal::WebGLDraftExtensionsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebGLImageChromiumEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webglImageChromiumEnabled_Getter");

  internal_runtime_flags_v8_internal::WebGLImageChromiumEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebGPUEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webgpuEnabled_Getter");

  internal_runtime_flags_v8_internal::WebGPUEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebHIDEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webHIDEnabled_Getter");

  internal_runtime_flags_v8_internal::WebHIDEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebNFCEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webNFCEnabled_Getter");

  internal_runtime_flags_v8_internal::WebNFCEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebSchedulerEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webSchedulerEnabled_Getter");

  internal_runtime_flags_v8_internal::WebSchedulerEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebShareEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webShareEnabled_Getter");

  internal_runtime_flags_v8_internal::WebShareEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebShareV2EnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webShareV2Enabled_Getter");

  internal_runtime_flags_v8_internal::WebShareV2EnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebSocketStreamEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_websocketStreamEnabled_Getter");

  internal_runtime_flags_v8_internal::WebSocketStreamEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebUSBEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webUSBEnabled_Getter");

  internal_runtime_flags_v8_internal::WebUSBEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebUSBOnDedicatedWorkersEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webUSBOnDedicatedWorkersEnabled_Getter");

  internal_runtime_flags_v8_internal::WebUSBOnDedicatedWorkersEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebVTTRegionsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webVTTRegionsEnabled_Getter");

  internal_runtime_flags_v8_internal::WebVTTRegionsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXREnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXREnabled_Getter");

  internal_runtime_flags_v8_internal::WebXREnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXRAnchorsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXRAnchorsEnabled_Getter");

  internal_runtime_flags_v8_internal::WebXRAnchorsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXRARModuleEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXRARModuleEnabled_Getter");

  internal_runtime_flags_v8_internal::WebXRARModuleEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXRCameraAccessEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXRCameraAccessEnabled_Getter");

  internal_runtime_flags_v8_internal::WebXRCameraAccessEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXRHitTestEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXRHitTestEnabled_Getter");

  internal_runtime_flags_v8_internal::WebXRHitTestEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXRHitTestEntityTypesEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXRHitTestEntityTypesEnabled_Getter");

  internal_runtime_flags_v8_internal::WebXRHitTestEntityTypesEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXRLightEstimationEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXRLightEstimationEnabled_Getter");

  internal_runtime_flags_v8_internal::WebXRLightEstimationEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WebXRPlaneDetectionEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_webXRPlaneDetectionEnabled_Getter");

  internal_runtime_flags_v8_internal::WebXRPlaneDetectionEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WindowPlacementEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_windowPlacementEnabled_Getter");

  internal_runtime_flags_v8_internal::WindowPlacementEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::WindowSegmentsEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_windowSegmentsEnabled_Getter");

  internal_runtime_flags_v8_internal::WindowSegmentsEnabledAttributeGetter(info);
}

void V8InternalRuntimeFlags::XsltEnabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalRuntimeFlags_xsltEnabled_Getter");

  internal_runtime_flags_v8_internal::XsltEnabledAttributeGetter(info);
}

static void InstallV8InternalRuntimeFlagsTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8InternalRuntimeFlags::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8InternalRuntimeFlags::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "accelerated2dCanvasEnabled", V8InternalRuntimeFlags::Accelerated2dCanvasEnabledAttributeGetterCallback, V8InternalRuntimeFlags::Accelerated2dCanvasEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "acceleratedSmallCanvasesEnabled", V8InternalRuntimeFlags::AcceleratedSmallCanvasesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "accessibilityExposeARIAAnnotationsEnabled", V8InternalRuntimeFlags::AccessibilityExposeARIAAnnotationsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "accessibilityExposeDisplayNoneEnabled", V8InternalRuntimeFlags::AccessibilityExposeDisplayNoneEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "accessibilityExposeHTMLElementEnabled", V8InternalRuntimeFlags::AccessibilityExposeHTMLElementEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "accessibilityObjectModelEnabled", V8InternalRuntimeFlags::AccessibilityObjectModelEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "addressSpaceEnabled", V8InternalRuntimeFlags::AddressSpaceEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "adTaggingEnabled", V8InternalRuntimeFlags::AdTaggingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "allowActivationDelegationAttrEnabled", V8InternalRuntimeFlags::AllowActivationDelegationAttrEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "allowContentInitiatedDataUrlNavigationsEnabled", V8InternalRuntimeFlags::AllowContentInitiatedDataUrlNavigationsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "allowSyncXHRInPageDismissalEnabled", V8InternalRuntimeFlags::AllowSyncXHRInPageDismissalEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "animationWorkletEnabled", V8InternalRuntimeFlags::AnimationWorkletEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "aomAriaPropertiesEnabled", V8InternalRuntimeFlags::AomAriaPropertiesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "aomAriaRelationshipPropertiesEnabled", V8InternalRuntimeFlags::AomAriaRelationshipPropertiesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "appCacheEnabled", V8InternalRuntimeFlags::AppCacheEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "audioOutputDevicesEnabled", V8InternalRuntimeFlags::AudioOutputDevicesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "audioVideoTracksEnabled", V8InternalRuntimeFlags::AudioVideoTracksEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "audioWorkletRealtimeThreadEnabled", V8InternalRuntimeFlags::AudioWorkletRealtimeThreadEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "autoLazyLoadOnReloadsEnabled", V8InternalRuntimeFlags::AutoLazyLoadOnReloadsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "automaticLazyFrameLoadingEnabled", V8InternalRuntimeFlags::AutomaticLazyFrameLoadingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "automaticLazyImageLoadingEnabled", V8InternalRuntimeFlags::AutomaticLazyImageLoadingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "automationControlledEnabled", V8InternalRuntimeFlags::AutomationControlledEnabledAttributeGetterCallback, V8InternalRuntimeFlags::AutomationControlledEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "autoPictureInPictureEnabled", V8InternalRuntimeFlags::AutoPictureInPictureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "autoplayIgnoresWebAudioEnabled", V8InternalRuntimeFlags::AutoplayIgnoresWebAudioEnabledAttributeGetterCallback, V8InternalRuntimeFlags::AutoplayIgnoresWebAudioEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "backForwardCacheEnabled", V8InternalRuntimeFlags::BackForwardCacheEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "backgroundFetchEnabled", V8InternalRuntimeFlags::BackgroundFetchEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "backgroundVideoTrackOptimizationEnabled", V8InternalRuntimeFlags::BackgroundVideoTrackOptimizationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "badgingEnabled", V8InternalRuntimeFlags::BadgingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "barcodeDetectorEnabled", V8InternalRuntimeFlags::BarcodeDetectorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "beforeMatchEventEnabled", V8InternalRuntimeFlags::BeforeMatchEventEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "bidiCaretAffinityEnabled", V8InternalRuntimeFlags::BidiCaretAffinityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "blinkRuntimeCallStatsEnabled", V8InternalRuntimeFlags::BlinkRuntimeCallStatsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "blockCredentialedSubresourcesEnabled", V8InternalRuntimeFlags::BlockCredentialedSubresourcesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "blockFlowHandlesWebkitLineClampEnabled", V8InternalRuntimeFlags::BlockFlowHandlesWebkitLineClampEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "blockHTMLParserOnStyleSheetsEnabled", V8InternalRuntimeFlags::BlockHTMLParserOnStyleSheetsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "blockingDownloadsInSandboxEnabled", V8InternalRuntimeFlags::BlockingDownloadsInSandboxEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "blockingFocusWithoutUserActivationEnabled", V8InternalRuntimeFlags::BlockingFocusWithoutUserActivationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "browserVerifiedUserActivationKeyboardEnabled", V8InternalRuntimeFlags::BrowserVerifiedUserActivationKeyboardEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "browserVerifiedUserActivationMouseEnabled", V8InternalRuntimeFlags::BrowserVerifiedUserActivationMouseEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cacheInlineScriptCodeEnabled", V8InternalRuntimeFlags::CacheInlineScriptCodeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cacheStorageCodeCacheHintEnabled", V8InternalRuntimeFlags::CacheStorageCodeCacheHintEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "canvas2dContextLostRestoredEnabled", V8InternalRuntimeFlags::Canvas2dContextLostRestoredEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "canvas2dImageChromiumEnabled", V8InternalRuntimeFlags::Canvas2dImageChromiumEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "canvas2dScrollPathIntoViewEnabled", V8InternalRuntimeFlags::Canvas2dScrollPathIntoViewEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "canvasColorManagementEnabled", V8InternalRuntimeFlags::CanvasColorManagementEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "canvasHitRegionEnabled", V8InternalRuntimeFlags::CanvasHitRegionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "canvasImageSmoothingEnabled", V8InternalRuntimeFlags::CanvasImageSmoothingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "captureTimeInCsrcEnabled", V8InternalRuntimeFlags::CaptureTimeInCsrcEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "clickPointerEventEnabled", V8InternalRuntimeFlags::ClickPointerEventEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "clickRetargettingEnabled", V8InternalRuntimeFlags::ClickRetargettingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "compositeAfterPaintEnabled", V8InternalRuntimeFlags::CompositeAfterPaintEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "compositedSelectionUpdateEnabled", V8InternalRuntimeFlags::CompositedSelectionUpdateEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "computedAccessibilityInfoEnabled", V8InternalRuntimeFlags::ComputedAccessibilityInfoEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "consolidatedMovementXYEnabled", V8InternalRuntimeFlags::ConsolidatedMovementXYEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "contactsManagerEnabled", V8InternalRuntimeFlags::ContactsManagerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "contactsManagerExtraPropertiesEnabled", V8InternalRuntimeFlags::ContactsManagerExtraPropertiesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "contentIndexEnabled", V8InternalRuntimeFlags::ContentIndexEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "contextMenuEnabled", V8InternalRuntimeFlags::ContextMenuEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "conversionMeasurementEnabled", V8InternalRuntimeFlags::ConversionMeasurementEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cookieDeprecationMessagesEnabled", V8InternalRuntimeFlags::CookieDeprecationMessagesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cookieStoreDocumentEnabled", V8InternalRuntimeFlags::CookieStoreDocumentEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cookieStoreWorkerEnabled", V8InternalRuntimeFlags::CookieStoreWorkerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cookiesWithoutSameSiteMustBeSecureEnabled", V8InternalRuntimeFlags::CookiesWithoutSameSiteMustBeSecureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cooperativeSchedulingEnabled", V8InternalRuntimeFlags::CooperativeSchedulingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "corsRFC1918Enabled", V8InternalRuntimeFlags::CorsRFC1918EnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "crossOriginIsolationEnabled", V8InternalRuntimeFlags::CrossOriginIsolationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "css3TextEnabled", V8InternalRuntimeFlags::CSS3TextEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssAspectRatioPropertyEnabled", V8InternalRuntimeFlags::CSSAspectRatioPropertyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssCalcAsIntEnabled", V8InternalRuntimeFlags::CSSCalcAsIntEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssCascadeEnabled", V8InternalRuntimeFlags::CSSCascadeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssColorSchemeEnabled", V8InternalRuntimeFlags::CSSColorSchemeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssColorSchemeUARenderingEnabled", V8InternalRuntimeFlags::CSSColorSchemeUARenderingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssContentVisibilityEnabled", V8InternalRuntimeFlags::CSSContentVisibilityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssContentVisibilityHiddenMatchableEnabled", V8InternalRuntimeFlags::CSSContentVisibilityHiddenMatchableEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssFocusVisibleEnabled", V8InternalRuntimeFlags::CSSFocusVisibleEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssFoldablesEnabled", V8InternalRuntimeFlags::CSSFoldablesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssFontSizeAdjustEnabled", V8InternalRuntimeFlags::CSSFontSizeAdjustEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssHexAlphaColorEnabled", V8InternalRuntimeFlags::CSSHexAlphaColorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssIndependentTransformPropertiesEnabled", V8InternalRuntimeFlags::CSSIndependentTransformPropertiesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssLayoutAPIEnabled", V8InternalRuntimeFlags::CSSLayoutAPIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssLogicalEnabled", V8InternalRuntimeFlags::CSSLogicalEnabledAttributeGetterCallback, V8InternalRuntimeFlags::CSSLogicalEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssLogicalOverflowEnabled", V8InternalRuntimeFlags::CSSLogicalOverflowEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssMarkerNestedPseudoElementEnabled", V8InternalRuntimeFlags::CSSMarkerNestedPseudoElementEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssMarkerPseudoElementEnabled", V8InternalRuntimeFlags::CSSMarkerPseudoElementEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssMatchedPropertiesCacheDependenciesEnabled", V8InternalRuntimeFlags::CSSMatchedPropertiesCacheDependenciesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssMathStyleEnabled", V8InternalRuntimeFlags::CSSMathStyleEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssMathSuperscriptShiftStyleEnabled", V8InternalRuntimeFlags::CSSMathSuperscriptShiftStyleEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssMathVariantEnabled", V8InternalRuntimeFlags::CSSMathVariantEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssModulesEnabled", V8InternalRuntimeFlags::CSSModulesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssOffsetPathRayEnabled", V8InternalRuntimeFlags::CSSOffsetPathRayEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssOffsetPathRayContainEnabled", V8InternalRuntimeFlags::CSSOffsetPathRayContainEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssOffsetPositionAnchorEnabled", V8InternalRuntimeFlags::CSSOffsetPositionAnchorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssomViewScrollCoordinatesEnabled", V8InternalRuntimeFlags::CSSOMViewScrollCoordinatesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssPaintAPIArgumentsEnabled", V8InternalRuntimeFlags::CSSPaintAPIArgumentsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssPictureInPictureEnabled", V8InternalRuntimeFlags::CSSPictureInPictureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssPseudoIsEnabled", V8InternalRuntimeFlags::CSSPseudoIsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssPseudoWhereEnabled", V8InternalRuntimeFlags::CSSPseudoWhereEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssReducedFontLoadingInvalidationsEnabled", V8InternalRuntimeFlags::CSSReducedFontLoadingInvalidationsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssReducedFontLoadingLayoutInvalidationsEnabled", V8InternalRuntimeFlags::CSSReducedFontLoadingLayoutInvalidationsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssRevertEnabled", V8InternalRuntimeFlags::CSSRevertEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssScrollTimelineEnabled", V8InternalRuntimeFlags::CSSScrollTimelineEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssSnapSizeEnabled", V8InternalRuntimeFlags::CSSSnapSizeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssSupportsSelectorEnabled", V8InternalRuntimeFlags::CSSSupportsSelectorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssVariables2AtPropertyEnabled", V8InternalRuntimeFlags::CSSVariables2AtPropertyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssVariables2ImageValuesEnabled", V8InternalRuntimeFlags::CSSVariables2ImageValuesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "cssVariables2TransformValuesEnabled", V8InternalRuntimeFlags::CSSVariables2TransformValuesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "customElementDefaultStyleEnabled", V8InternalRuntimeFlags::CustomElementDefaultStyleEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "customElementsV0Enabled", V8InternalRuntimeFlags::CustomElementsV0EnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "customStatePseudoClassEnabled", V8InternalRuntimeFlags::CustomStatePseudoClassEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "databaseEnabled", V8InternalRuntimeFlags::DatabaseEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "declarativeShadowDOMEnabled", V8InternalRuntimeFlags::DeclarativeShadowDOMEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "decodeJpeg420ImagesToYUVEnabled", V8InternalRuntimeFlags::DecodeJpeg420ImagesToYUVEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "decodeLossyWebPImagesToYUVEnabled", V8InternalRuntimeFlags::DecodeLossyWebPImagesToYUVEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "delayAsyncScriptExecutionUntilFinishedParsingEnabled", V8InternalRuntimeFlags::DelayAsyncScriptExecutionUntilFinishedParsingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "delayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabled", V8InternalRuntimeFlags::DelayAsyncScriptExecutionUntilFirstPaintOrFinishedParsingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "delegatedInkTrailsEnabled", V8InternalRuntimeFlags::DelegatedInkTrailsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "desktopCaptureDisableLocalEchoControlEnabled", V8InternalRuntimeFlags::DesktopCaptureDisableLocalEchoControlEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "digitalGoodsEnabled", V8InternalRuntimeFlags::DigitalGoodsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "disableHardwareNoiseSuppressionEnabled", V8InternalRuntimeFlags::DisableHardwareNoiseSuppressionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "disableLayerSquashingEnabled", V8InternalRuntimeFlags::DisableLayerSquashingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "disallowDocumentAccessEnabled", V8InternalRuntimeFlags::DisallowDocumentAccessEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "displayCutoutAPIEnabled", V8InternalRuntimeFlags::DisplayCutoutAPIEnabledAttributeGetterCallback, V8InternalRuntimeFlags::DisplayCutoutAPIEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "documentCookieEnabled", V8InternalRuntimeFlags::DocumentCookieEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "documentDomainEnabled", V8InternalRuntimeFlags::DocumentDomainEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "documentPolicyEnabled", V8InternalRuntimeFlags::DocumentPolicyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "documentWriteEnabled", V8InternalRuntimeFlags::DocumentWriteEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "editContextEnabled", V8InternalRuntimeFlags::EditContextEnabledAttributeGetterCallback, V8InternalRuntimeFlags::EditContextEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "editingNGEnabled", V8InternalRuntimeFlags::EditingNGEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "encryptedMediaEncryptionSchemeQueryEnabled", V8InternalRuntimeFlags::EncryptedMediaEncryptionSchemeQueryEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "encryptedMediaHdcpPolicyCheckEnabled", V8InternalRuntimeFlags::EncryptedMediaHdcpPolicyCheckEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "encryptedMediaPersistentUsageRecordSessionEnabled", V8InternalRuntimeFlags::EncryptedMediaPersistentUsageRecordSessionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "enterKeyHintAttributeEnabled", V8InternalRuntimeFlags::EnterKeyHintAttributeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "eventTimingEnabled", V8InternalRuntimeFlags::EventTimingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "execCommandInJavaScriptEnabled", V8InternalRuntimeFlags::ExecCommandInJavaScriptEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "expensiveBackgroundTimerThrottlingEnabled", V8InternalRuntimeFlags::ExpensiveBackgroundTimerThrottlingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "experimentalAutoplayDynamicDelegationEnabled", V8InternalRuntimeFlags::ExperimentalAutoplayDynamicDelegationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "experimentalContentSecurityPolicyFeaturesEnabled", V8InternalRuntimeFlags::ExperimentalContentSecurityPolicyFeaturesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "experimentalIsInputPendingEnabled", V8InternalRuntimeFlags::ExperimentalIsInputPendingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "experimentalJSProfilerEnabled", V8InternalRuntimeFlags::ExperimentalJSProfilerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "experimentalProductivityFeaturesEnabled", V8InternalRuntimeFlags::ExperimentalProductivityFeaturesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "extendedTextMetricsEnabled", V8InternalRuntimeFlags::ExtendedTextMetricsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "extraWebGLVideoTextureMetadataEnabled", V8InternalRuntimeFlags::ExtraWebGLVideoTextureMetadataEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "faceDetectorEnabled", V8InternalRuntimeFlags::FaceDetectorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "featurePolicyForClientHintsEnabled", V8InternalRuntimeFlags::FeaturePolicyForClientHintsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "featurePolicyForSandboxEnabled", V8InternalRuntimeFlags::FeaturePolicyForSandboxEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "featurePolicyReportingEnabled", V8InternalRuntimeFlags::FeaturePolicyReportingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "featurePolicyVibrateFeatureEnabled", V8InternalRuntimeFlags::FeaturePolicyVibrateFeatureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "fetchUploadStreamingEnabled", V8InternalRuntimeFlags::FetchUploadStreamingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "fileHandlingEnabled", V8InternalRuntimeFlags::FileHandlingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "fileSystemEnabled", V8InternalRuntimeFlags::FileSystemEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "flexGapsEnabled", V8InternalRuntimeFlags::FlexGapsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "focuslessSpatialNavigationEnabled", V8InternalRuntimeFlags::FocuslessSpatialNavigationEnabledAttributeGetterCallback, V8InternalRuntimeFlags::FocuslessSpatialNavigationEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "fontAccessEnabled", V8InternalRuntimeFlags::FontAccessEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "fontSrcLocalMatchingEnabled", V8InternalRuntimeFlags::FontSrcLocalMatchingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "forcedColorsEnabled", V8InternalRuntimeFlags::ForcedColorsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "forceDeferScriptInterventionEnabled", V8InternalRuntimeFlags::ForceDeferScriptInterventionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "forceEagerMeasureMemoryEnabled", V8InternalRuntimeFlags::ForceEagerMeasureMemoryEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "forceLoadAtTopEnabled", V8InternalRuntimeFlags::ForceLoadAtTopEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "forceOverlayFullscreenVideoEnabled", V8InternalRuntimeFlags::ForceOverlayFullscreenVideoEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "forceSynchronousHTMLParsingEnabled", V8InternalRuntimeFlags::ForceSynchronousHTMLParsingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "forceTallerSelectPopupEnabled", V8InternalRuntimeFlags::ForceTallerSelectPopupEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "fractionalScrollOffsetsEnabled", V8InternalRuntimeFlags::FractionalScrollOffsetsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "freezeFramesOnVisibilityEnabled", V8InternalRuntimeFlags::FreezeFramesOnVisibilityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "gamepadButtonAxisEventsEnabled", V8InternalRuntimeFlags::GamepadButtonAxisEventsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "getDisplayMediaEnabled", V8InternalRuntimeFlags::GetDisplayMediaEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "groupEffectEnabled", V8InternalRuntimeFlags::GroupEffectEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "hrefTranslateEnabled", V8InternalRuntimeFlags::HrefTranslateEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "htmlImportsEnabled", V8InternalRuntimeFlags::HTMLImportsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "idbObserverEnabled", V8InternalRuntimeFlags::IdbObserverEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "idbRelaxedDurabilityEnabled", V8InternalRuntimeFlags::IdbRelaxedDurabilityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "idleDetectionEnabled", V8InternalRuntimeFlags::IdleDetectionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ignoreCrossOriginWindowWhenNamedAccessOnWindowEnabled", V8InternalRuntimeFlags::IgnoreCrossOriginWindowWhenNamedAccessOnWindowEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "imageOrientationEnabled", V8InternalRuntimeFlags::ImageOrientationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "implicitRootScrollerEnabled", V8InternalRuntimeFlags::ImplicitRootScrollerEnabledAttributeGetterCallback, V8InternalRuntimeFlags::ImplicitRootScrollerEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "importMapsEnabled", V8InternalRuntimeFlags::ImportMapsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "inertAttributeEnabled", V8InternalRuntimeFlags::InertAttributeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "inputElementRawValueEnabled", V8InternalRuntimeFlags::InputElementRawValueEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "inputMultipleFieldsUIEnabled", V8InternalRuntimeFlags::InputMultipleFieldsUIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "installedAppEnabled", V8InternalRuntimeFlags::InstalledAppEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "intersectionObserverDocumentScrollingElementRootEnabled", V8InternalRuntimeFlags::IntersectionObserverDocumentScrollingElementRootEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "isolatedCodeCacheEnabled", V8InternalRuntimeFlags::IsolatedCodeCacheEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "isolatedWorldCSPEnabled", V8InternalRuntimeFlags::IsolatedWorldCSPEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "keyboardFocusableScrollersEnabled", V8InternalRuntimeFlags::KeyboardFocusableScrollersEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "langAttributeAwareFormControlUIEnabled", V8InternalRuntimeFlags::LangAttributeAwareFormControlUIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "langClientHintHeaderEnabled", V8InternalRuntimeFlags::LangClientHintHeaderEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGEnabled", V8InternalRuntimeFlags::LayoutNGEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGBlockFragmentationEnabled", V8InternalRuntimeFlags::LayoutNGBlockFragmentationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGFieldsetEnabled", V8InternalRuntimeFlags::LayoutNGFieldsetEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGFlexBoxEnabled", V8InternalRuntimeFlags::LayoutNGFlexBoxEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGForControlsEnabled", V8InternalRuntimeFlags::LayoutNGForControlsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGFragmentItemEnabled", V8InternalRuntimeFlags::LayoutNGFragmentItemEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGFragmentTraversalEnabled", V8InternalRuntimeFlags::LayoutNGFragmentTraversalEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGGridEnabled", V8InternalRuntimeFlags::LayoutNGGridEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGRubyEnabled", V8InternalRuntimeFlags::LayoutNGRubyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutNGTableEnabled", V8InternalRuntimeFlags::LayoutNGTableEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "layoutShiftAttributionEnabled", V8InternalRuntimeFlags::LayoutShiftAttributionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "lazyFrameLoadingEnabled", V8InternalRuntimeFlags::LazyFrameLoadingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "lazyFrameVisibleLoadTimeMetricsEnabled", V8InternalRuntimeFlags::LazyFrameVisibleLoadTimeMetricsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "lazyImageLoadingEnabled", V8InternalRuntimeFlags::LazyImageLoadingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "lazyImageVisibleLoadTimeMetricsEnabled", V8InternalRuntimeFlags::LazyImageVisibleLoadTimeMetricsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "lazyInitializeMediaControlsEnabled", V8InternalRuntimeFlags::LazyInitializeMediaControlsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "legacyNativeFileSystemEnabled", V8InternalRuntimeFlags::LegacyNativeFileSystemEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "legacyWindowsDWriteFontFallbackEnabled", V8InternalRuntimeFlags::LegacyWindowsDWriteFontFallbackEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "linkDisabledNewSpecBehaviorEnabled", V8InternalRuntimeFlags::LinkDisabledNewSpecBehaviorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "manualSlottingEnabled", V8InternalRuntimeFlags::ManualSlottingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mathmlCoreEnabled", V8InternalRuntimeFlags::MathMLCoreEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "measureMemoryEnabled", V8InternalRuntimeFlags::MeasureMemoryEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCapabilitiesDynamicRangeEnabled", V8InternalRuntimeFlags::MediaCapabilitiesDynamicRangeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCapabilitiesEncodingInfoEnabled", V8InternalRuntimeFlags::MediaCapabilitiesEncodingInfoEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCapabilitiesEncryptedMediaEnabled", V8InternalRuntimeFlags::MediaCapabilitiesEncryptedMediaEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCapabilitiesSpatialAudioEnabled", V8InternalRuntimeFlags::MediaCapabilitiesSpatialAudioEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCaptureEnabled", V8InternalRuntimeFlags::MediaCaptureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCaptureDepthVideoKindEnabled", V8InternalRuntimeFlags::MediaCaptureDepthVideoKindEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCapturePanTiltEnabled", V8InternalRuntimeFlags::MediaCapturePanTiltEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaCastOverlayButtonEnabled", V8InternalRuntimeFlags::MediaCastOverlayButtonEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaControlsExpandGestureEnabled", V8InternalRuntimeFlags::MediaControlsExpandGestureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaControlsOverlayPlayButtonEnabled", V8InternalRuntimeFlags::MediaControlsOverlayPlayButtonEnabledAttributeGetterCallback, V8InternalRuntimeFlags::MediaControlsOverlayPlayButtonEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaControlsUseCutOutByDefaultEnabled", V8InternalRuntimeFlags::MediaControlsUseCutOutByDefaultEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaDocumentDownloadButtonEnabled", V8InternalRuntimeFlags::MediaDocumentDownloadButtonEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaElementVolumeGreaterThanOneEnabled", V8InternalRuntimeFlags::MediaElementVolumeGreaterThanOneEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaEngagementBypassAutoplayPoliciesEnabled", V8InternalRuntimeFlags::MediaEngagementBypassAutoplayPoliciesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaFeedsEnabled", V8InternalRuntimeFlags::MediaFeedsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaLatencyHintEnabled", V8InternalRuntimeFlags::MediaLatencyHintEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaQueryNavigationControlsEnabled", V8InternalRuntimeFlags::MediaQueryNavigationControlsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaSessionEnabled", V8InternalRuntimeFlags::MediaSessionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaSessionPositionEnabled", V8InternalRuntimeFlags::MediaSessionPositionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaSourceExperimentalEnabled", V8InternalRuntimeFlags::MediaSourceExperimentalEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaSourceInWorkersEnabled", V8InternalRuntimeFlags::MediaSourceInWorkersEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaSourceNewAbortAndDurationEnabled", V8InternalRuntimeFlags::MediaSourceNewAbortAndDurationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mediaSourceStableEnabled", V8InternalRuntimeFlags::MediaSourceStableEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "metaColorSchemeEnabled", V8InternalRuntimeFlags::MetaColorSchemeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "middleClickAutoscrollEnabled", V8InternalRuntimeFlags::MiddleClickAutoscrollEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mobileLayoutThemeEnabled", V8InternalRuntimeFlags::MobileLayoutThemeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "moduleServiceWorkerEnabled", V8InternalRuntimeFlags::ModuleServiceWorkerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "moduleSharedWorkerEnabled", V8InternalRuntimeFlags::ModuleSharedWorkerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mojoJSEnabled", V8InternalRuntimeFlags::MojoJSEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mojoJSTestEnabled", V8InternalRuntimeFlags::MojoJSTestEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "mouseSubframeNoImplicitCaptureEnabled", V8InternalRuntimeFlags::MouseSubframeNoImplicitCaptureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "namedPagesEnabled", V8InternalRuntimeFlags::NamedPagesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "nativeFileSystemEnabled", V8InternalRuntimeFlags::NativeFileSystemEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "nativeIOEnabled", V8InternalRuntimeFlags::NativeIOEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "navigatorContentUtilsEnabled", V8InternalRuntimeFlags::NavigatorContentUtilsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "navigatorLanguageInInsecureContextEnabled", V8InternalRuntimeFlags::NavigatorLanguageInInsecureContextEnabledAttributeGetterCallback, V8InternalRuntimeFlags::NavigatorLanguageInInsecureContextEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "netInfoDownlinkMaxEnabled", V8InternalRuntimeFlags::NetInfoDownlinkMaxEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "neverSlowModeEnabled", V8InternalRuntimeFlags::NeverSlowModeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "newCanvas2DAPIEnabled", V8InternalRuntimeFlags::NewCanvas2DAPIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "newRemotePlaybackPipelineEnabled", V8InternalRuntimeFlags::NewRemotePlaybackPipelineEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "noIdleEncodingForWebTestsEnabled", V8InternalRuntimeFlags::NoIdleEncodingForWebTestsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "notificationConstructorEnabled", V8InternalRuntimeFlags::NotificationConstructorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "notificationContentImageEnabled", V8InternalRuntimeFlags::NotificationContentImageEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "notificationsEnabled", V8InternalRuntimeFlags::NotificationsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "notificationTriggersEnabled", V8InternalRuntimeFlags::NotificationTriggersEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "offMainThreadCSSPaintEnabled", V8InternalRuntimeFlags::OffMainThreadCSSPaintEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "offscreenCanvasCommitEnabled", V8InternalRuntimeFlags::OffscreenCanvasCommitEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onDeviceChangeEnabled", V8InternalRuntimeFlags::OnDeviceChangeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "orientationEventEnabled", V8InternalRuntimeFlags::OrientationEventEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originIsolationHeaderEnabled", V8InternalRuntimeFlags::OriginIsolationHeaderEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originPolicyEnabled", V8InternalRuntimeFlags::OriginPolicyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originTrialsSampleAPIEnabled", V8InternalRuntimeFlags::OriginTrialsSampleAPIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originTrialsSampleAPIDependentEnabled", V8InternalRuntimeFlags::OriginTrialsSampleAPIDependentEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originTrialsSampleAPIDeprecationEnabled", V8InternalRuntimeFlags::OriginTrialsSampleAPIDeprecationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originTrialsSampleAPIImpliedEnabled", V8InternalRuntimeFlags::OriginTrialsSampleAPIImpliedEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originTrialsSampleAPIInvalidOSEnabled", V8InternalRuntimeFlags::OriginTrialsSampleAPIInvalidOSEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originTrialsSampleAPINavigationEnabled", V8InternalRuntimeFlags::OriginTrialsSampleAPINavigationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "originTrialsSampleAPIThirdPartyEnabled", V8InternalRuntimeFlags::OriginTrialsSampleAPIThirdPartyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "outOfBlinkCorsEnabled", V8InternalRuntimeFlags::OutOfBlinkCorsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "overflowIconsForMediaControlsEnabled", V8InternalRuntimeFlags::OverflowIconsForMediaControlsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "overscrollCustomizationEnabled", V8InternalRuntimeFlags::OverscrollCustomizationEnabledAttributeGetterCallback, V8InternalRuntimeFlags::OverscrollCustomizationEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pageFreezeOptInEnabled", V8InternalRuntimeFlags::PageFreezeOptInEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pageFreezeOptOutEnabled", V8InternalRuntimeFlags::PageFreezeOptOutEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pagePopupEnabled", V8InternalRuntimeFlags::PagePopupEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paintUnderInvalidationCheckingEnabled", V8InternalRuntimeFlags::PaintUnderInvalidationCheckingEnabledAttributeGetterCallback, V8InternalRuntimeFlags::PaintUnderInvalidationCheckingEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "parseUrlProtocolHandlerEnabled", V8InternalRuntimeFlags::ParseUrlProtocolHandlerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "passPaintVisualRectToCompositorEnabled", V8InternalRuntimeFlags::PassPaintVisualRectToCompositorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "passwordRevealEnabled", V8InternalRuntimeFlags::PasswordRevealEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentAppEnabled", V8InternalRuntimeFlags::PaymentAppEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentHandlerChangePaymentMethodEnabled", V8InternalRuntimeFlags::PaymentHandlerChangePaymentMethodEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentHandlerHandlesShippingAndContactEnabled", V8InternalRuntimeFlags::PaymentHandlerHandlesShippingAndContactEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentHandlerMinimalUIEnabled", V8InternalRuntimeFlags::PaymentHandlerMinimalUIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentMethodChangeEventEnabled", V8InternalRuntimeFlags::PaymentMethodChangeEventEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentRequestEnabled", V8InternalRuntimeFlags::PaymentRequestEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentRequestMerchantValidationEventEnabled", V8InternalRuntimeFlags::PaymentRequestMerchantValidationEventEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "paymentRetryEnabled", V8InternalRuntimeFlags::PaymentRetryEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "percentBasedScrollingEnabled", V8InternalRuntimeFlags::PercentBasedScrollingEnabledAttributeGetterCallback, V8InternalRuntimeFlags::PercentBasedScrollingEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "performanceManagerInstrumentationEnabled", V8InternalRuntimeFlags::PerformanceManagerInstrumentationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "periodicBackgroundSyncEnabled", V8InternalRuntimeFlags::PeriodicBackgroundSyncEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "perMethodCanMakePaymentQuotaEnabled", V8InternalRuntimeFlags::PerMethodCanMakePaymentQuotaEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "permissionDelegationEnabled", V8InternalRuntimeFlags::PermissionDelegationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "permissionsEnabled", V8InternalRuntimeFlags::PermissionsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "permissionsRequestRevokeEnabled", V8InternalRuntimeFlags::PermissionsRequestRevokeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pictureInPictureEnabled", V8InternalRuntimeFlags::PictureInPictureEnabledAttributeGetterCallback, V8InternalRuntimeFlags::PictureInPictureEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pictureInPictureAPIEnabled", V8InternalRuntimeFlags::PictureInPictureAPIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pictureInPictureV2Enabled", V8InternalRuntimeFlags::PictureInPictureV2EnabledAttributeGetterCallback, V8InternalRuntimeFlags::PictureInPictureV2EnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pNaClEnabled", V8InternalRuntimeFlags::PNaClEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pointerLockOptionsEnabled", V8InternalRuntimeFlags::PointerLockOptionsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pointerRawUpdateEnabled", V8InternalRuntimeFlags::PointerRawUpdateEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "portalsEnabled", V8InternalRuntimeFlags::PortalsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "postAnimationFrameEnabled", V8InternalRuntimeFlags::PostAnimationFrameEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "preciseMemoryInfoEnabled", V8InternalRuntimeFlags::PreciseMemoryInfoEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "preferNonCompositedScrollingEnabled", V8InternalRuntimeFlags::PreferNonCompositedScrollingEnabledAttributeGetterCallback, V8InternalRuntimeFlags::PreferNonCompositedScrollingEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "prefersReducedDataEnabled", V8InternalRuntimeFlags::PrefersReducedDataEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "prefixedVideoFullscreenEnabled", V8InternalRuntimeFlags::PrefixedVideoFullscreenEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "presentationEnabled", V8InternalRuntimeFlags::PresentationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "priorityHintsEnabled", V8InternalRuntimeFlags::PriorityHintsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pushMessagingEnabled", V8InternalRuntimeFlags::PushMessagingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "pushMessagingSubscriptionChangeEnabled", V8InternalRuntimeFlags::PushMessagingSubscriptionChangeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "quicTransportEnabled", V8InternalRuntimeFlags::QuicTransportEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rawClipboardEnabled", V8InternalRuntimeFlags::RawClipboardEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "reducedReferrerGranularityEnabled", V8InternalRuntimeFlags::ReducedReferrerGranularityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "remotePlaybackEnabled", V8InternalRuntimeFlags::RemotePlaybackEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "remotePlaybackBackendEnabled", V8InternalRuntimeFlags::RemotePlaybackBackendEnabledAttributeGetterCallback, V8InternalRuntimeFlags::RemotePlaybackBackendEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "requestVideoFrameCallbackEnabled", V8InternalRuntimeFlags::RequestVideoFrameCallbackEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "resizeObserverUpdatesEnabled", V8InternalRuntimeFlags::ResizeObserverUpdatesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "restrictAppCacheToSecureContextsEnabled", V8InternalRuntimeFlags::RestrictAppCacheToSecureContextsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "restrictAutomaticLazyFrameLoadingToDataSaverEnabled", V8InternalRuntimeFlags::RestrictAutomaticLazyFrameLoadingToDataSaverEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "restrictAutomaticLazyImageLoadingToDataSaverEnabled", V8InternalRuntimeFlags::RestrictAutomaticLazyImageLoadingToDataSaverEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcAudioJitterBufferMaxPacketsEnabled", V8InternalRuntimeFlags::RTCAudioJitterBufferMaxPacketsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcAudioJitterBufferRtxHandlingEnabled", V8InternalRuntimeFlags::RTCAudioJitterBufferRtxHandlingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcIceTransportExtensionEnabled", V8InternalRuntimeFlags::RTCIceTransportExtensionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcInsertableStreamsEnabled", V8InternalRuntimeFlags::RTCInsertableStreamsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcQuicTransportEnabled", V8InternalRuntimeFlags::RTCQuicTransportEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcStatsRelativePacketArrivalDelayEnabled", V8InternalRuntimeFlags::RTCStatsRelativePacketArrivalDelayEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcSvcScalabilityModeEnabled", V8InternalRuntimeFlags::RTCSvcScalabilityModeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcUnifiedPlanEnabled", V8InternalRuntimeFlags::RTCUnifiedPlanEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "rtcUnifiedPlanByDefaultEnabled", V8InternalRuntimeFlags::RTCUnifiedPlanByDefaultEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sameSiteByDefaultCookiesEnabled", V8InternalRuntimeFlags::SameSiteByDefaultCookiesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "screenWakeLockEnabled", V8InternalRuntimeFlags::ScreenWakeLockEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "scriptedSpeechRecognitionEnabled", V8InternalRuntimeFlags::ScriptedSpeechRecognitionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "scriptedSpeechSynthesisEnabled", V8InternalRuntimeFlags::ScriptedSpeechSynthesisEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "scrollCustomizationEnabled", V8InternalRuntimeFlags::ScrollCustomizationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "scrollSnapAfterLayoutEnabled", V8InternalRuntimeFlags::ScrollSnapAfterLayoutEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "scrollTimelineEnabled", V8InternalRuntimeFlags::ScrollTimelineEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "scrollTopLeftInteropEnabled", V8InternalRuntimeFlags::ScrollTopLeftInteropEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "scrollUnificationEnabled", V8InternalRuntimeFlags::ScrollUnificationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sendBeaconThrowForBlobWithNonSimpleTypeEnabled", V8InternalRuntimeFlags::SendBeaconThrowForBlobWithNonSimpleTypeEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sendMouseEventsDisabledFormControlsEnabled", V8InternalRuntimeFlags::SendMouseEventsDisabledFormControlsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sensorExtraClassesEnabled", V8InternalRuntimeFlags::SensorExtraClassesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "serialEnabled", V8InternalRuntimeFlags::SerialEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "serviceWorkerClientLifecycleStateEnabled", V8InternalRuntimeFlags::ServiceWorkerClientLifecycleStateEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "serviceWorkerFetchEventWorkerTimingEnabled", V8InternalRuntimeFlags::ServiceWorkerFetchEventWorkerTimingEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "shadowDOMV0Enabled", V8InternalRuntimeFlags::ShadowDOMV0EnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sharedArrayBufferEnabled", V8InternalRuntimeFlags::SharedArrayBufferEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sharedWorkerEnabled", V8InternalRuntimeFlags::SharedWorkerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "signatureBasedIntegrityEnabled", V8InternalRuntimeFlags::SignatureBasedIntegrityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "signedExchangePrefetchCacheForNavigationsEnabled", V8InternalRuntimeFlags::SignedExchangePrefetchCacheForNavigationsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "signedExchangeSubresourcePrefetchEnabled", V8InternalRuntimeFlags::SignedExchangeSubresourcePrefetchEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "skipAdEnabled", V8InternalRuntimeFlags::SkipAdEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "skipTouchEventFilterEnabled", V8InternalRuntimeFlags::SkipTouchEventFilterEnabledAttributeGetterCallback, V8InternalRuntimeFlags::SkipTouchEventFilterEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "smsReceiverEnabled", V8InternalRuntimeFlags::SmsReceiverEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "squashAfterPaintEnabled", V8InternalRuntimeFlags::SquashAfterPaintEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "stableBlinkFeaturesEnabled", V8InternalRuntimeFlags::StableBlinkFeaturesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "storageAccessAPIEnabled", V8InternalRuntimeFlags::StorageAccessAPIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "strictMimeTypesForWorkersEnabled", V8InternalRuntimeFlags::StrictMimeTypesForWorkersEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "subresourceWebBundlesEnabled", V8InternalRuntimeFlags::SubresourceWebBundlesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "surfaceEmbeddingFeaturesEnabled", V8InternalRuntimeFlags::SurfaceEmbeddingFeaturesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "systemWakeLockEnabled", V8InternalRuntimeFlags::SystemWakeLockEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "testFeatureEnabled", V8InternalRuntimeFlags::TestFeatureEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "testFeatureDependentEnabled", V8InternalRuntimeFlags::TestFeatureDependentEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "testFeatureImpliedEnabled", V8InternalRuntimeFlags::TestFeatureImpliedEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "textDetectorEnabled", V8InternalRuntimeFlags::TextDetectorEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "textFragmentIdentifiersEnabled", V8InternalRuntimeFlags::TextFragmentIdentifiersEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "thirdPartyOriginTrialsEnabled", V8InternalRuntimeFlags::ThirdPartyOriginTrialsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "timerThrottlingForBackgroundTabsEnabled", V8InternalRuntimeFlags::TimerThrottlingForBackgroundTabsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "timerThrottlingForHiddenFramesEnabled", V8InternalRuntimeFlags::TimerThrottlingForHiddenFramesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "timeZoneChangeEventEnabled", V8InternalRuntimeFlags::TimeZoneChangeEventEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "touchEventFeatureDetectionEnabled", V8InternalRuntimeFlags::TouchEventFeatureDetectionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "trackLayoutPassesPerBlockEnabled", V8InternalRuntimeFlags::TrackLayoutPassesPerBlockEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "transferableStreamsEnabled", V8InternalRuntimeFlags::TransferableStreamsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "transformInteropEnabled", V8InternalRuntimeFlags::TransformInteropEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "translateServiceEnabled", V8InternalRuntimeFlags::TranslateServiceEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "trustedDOMTypesEnabled", V8InternalRuntimeFlags::TrustedDOMTypesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "trustTokensEnabled", V8InternalRuntimeFlags::TrustTokensEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "trustTokensAlwaysAllowIssuanceEnabled", V8InternalRuntimeFlags::TrustTokensAlwaysAllowIssuanceEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "unclosedFormControlIsInvalidEnabled", V8InternalRuntimeFlags::UnclosedFormControlIsInvalidEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "underlineOffsetThicknessEnabled", V8InternalRuntimeFlags::UnderlineOffsetThicknessEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "unoptimizedImagePoliciesEnabled", V8InternalRuntimeFlags::UnoptimizedImagePoliciesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "unsizedMediaPolicyEnabled", V8InternalRuntimeFlags::UnsizedMediaPolicyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "userActivationPostMessageTransferEnabled", V8InternalRuntimeFlags::UserActivationPostMessageTransferEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "userActivationSameOriginVisibilityEnabled", V8InternalRuntimeFlags::UserActivationSameOriginVisibilityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "userAgentClientHintEnabled", V8InternalRuntimeFlags::UserAgentClientHintEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "v8IdleTasksEnabled", V8InternalRuntimeFlags::V8IdleTasksEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "videoAutoFullscreenEnabled", V8InternalRuntimeFlags::VideoAutoFullscreenEnabledAttributeGetterCallback, V8InternalRuntimeFlags::VideoAutoFullscreenEnabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "videoFullscreenOrientationLockEnabled", V8InternalRuntimeFlags::VideoFullscreenOrientationLockEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "videoPlaybackQualityEnabled", V8InternalRuntimeFlags::VideoPlaybackQualityEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "videoRotateToFullscreenEnabled", V8InternalRuntimeFlags::VideoRotateToFullscreenEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "videoWakeLockOptimisationHiddenMutedEnabled", V8InternalRuntimeFlags::VideoWakeLockOptimisationHiddenMutedEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "virtualKeyboardEnabled", V8InternalRuntimeFlags::VirtualKeyboardEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "visibilityCollapseColumnEnabled", V8InternalRuntimeFlags::VisibilityCollapseColumnEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "wakeLockEnabled", V8InternalRuntimeFlags::WakeLockEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webAnimationsAPIEnabled", V8InternalRuntimeFlags::WebAnimationsAPIEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webAnimationsSVGEnabled", V8InternalRuntimeFlags::WebAnimationsSVGEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webAssemblySimdEnabled", V8InternalRuntimeFlags::WebAssemblySimdEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webAssemblyThreadsEnabled", V8InternalRuntimeFlags::WebAssemblyThreadsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webAuthEnabled", V8InternalRuntimeFlags::WebAuthEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webAuthenticationGetAssertionFeaturePolicyEnabled", V8InternalRuntimeFlags::WebAuthenticationGetAssertionFeaturePolicyEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webBluetoothEnabled", V8InternalRuntimeFlags::WebBluetoothEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webBluetoothGetDevicesEnabled", V8InternalRuntimeFlags::WebBluetoothGetDevicesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webBluetoothRemoteCharacteristicNewWriteValueEnabled", V8InternalRuntimeFlags::WebBluetoothRemoteCharacteristicNewWriteValueEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webBluetoothScanningEnabled", V8InternalRuntimeFlags::WebBluetoothScanningEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webBluetoothWatchAdvertisementsEnabled", V8InternalRuntimeFlags::WebBluetoothWatchAdvertisementsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webCodecsEnabled", V8InternalRuntimeFlags::WebCodecsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webCryptoCurve25519Enabled", V8InternalRuntimeFlags::WebCryptoCurve25519EnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webgl2ComputeContextEnabled", V8InternalRuntimeFlags::WebGL2ComputeContextEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webglDraftExtensionsEnabled", V8InternalRuntimeFlags::WebGLDraftExtensionsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webglImageChromiumEnabled", V8InternalRuntimeFlags::WebGLImageChromiumEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webgpuEnabled", V8InternalRuntimeFlags::WebGPUEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webHIDEnabled", V8InternalRuntimeFlags::WebHIDEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webNFCEnabled", V8InternalRuntimeFlags::WebNFCEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webSchedulerEnabled", V8InternalRuntimeFlags::WebSchedulerEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webShareEnabled", V8InternalRuntimeFlags::WebShareEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webShareV2Enabled", V8InternalRuntimeFlags::WebShareV2EnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "websocketStreamEnabled", V8InternalRuntimeFlags::WebSocketStreamEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webUSBEnabled", V8InternalRuntimeFlags::WebUSBEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webUSBOnDedicatedWorkersEnabled", V8InternalRuntimeFlags::WebUSBOnDedicatedWorkersEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webVTTRegionsEnabled", V8InternalRuntimeFlags::WebVTTRegionsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXREnabled", V8InternalRuntimeFlags::WebXREnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXRAnchorsEnabled", V8InternalRuntimeFlags::WebXRAnchorsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXRARModuleEnabled", V8InternalRuntimeFlags::WebXRARModuleEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXRCameraAccessEnabled", V8InternalRuntimeFlags::WebXRCameraAccessEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXRHitTestEnabled", V8InternalRuntimeFlags::WebXRHitTestEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXRHitTestEntityTypesEnabled", V8InternalRuntimeFlags::WebXRHitTestEntityTypesEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXRLightEstimationEnabled", V8InternalRuntimeFlags::WebXRLightEstimationEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "webXRPlaneDetectionEnabled", V8InternalRuntimeFlags::WebXRPlaneDetectionEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "windowPlacementEnabled", V8InternalRuntimeFlags::WindowPlacementEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "windowSegmentsEnabled", V8InternalRuntimeFlags::WindowSegmentsEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "xsltEnabled", V8InternalRuntimeFlags::XsltEnabledAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));

  // Custom signature

  V8InternalRuntimeFlags::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8InternalRuntimeFlags::InstallRuntimeEnabledFeaturesOnTemplate(
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

v8::Local<v8::FunctionTemplate> V8InternalRuntimeFlags::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8InternalRuntimeFlags::GetWrapperTypeInfo()),
      InstallV8InternalRuntimeFlagsTemplate);
}

bool V8InternalRuntimeFlags::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8InternalRuntimeFlags::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8InternalRuntimeFlags::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8InternalRuntimeFlags::GetWrapperTypeInfo(), v8_value);
}

InternalRuntimeFlags* V8InternalRuntimeFlags::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
