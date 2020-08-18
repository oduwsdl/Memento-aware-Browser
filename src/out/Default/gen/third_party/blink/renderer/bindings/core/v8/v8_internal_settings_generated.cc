// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_internal_settings_generated.h"

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
const WrapperTypeInfo v8_internal_settings_generated_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8InternalSettingsGenerated::DomTemplate,
    nullptr,
    "InternalSettingsGenerated",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in InternalSettingsGenerated.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& InternalSettingsGenerated::wrapper_type_info_ = v8_internal_settings_generated_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, InternalSettingsGenerated>::value,
    "InternalSettingsGenerated inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&InternalSettingsGenerated::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "InternalSettingsGenerated is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace internal_settings_generated_v8_internal {

static void SetDOMPasteAllowedMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDOMPasteAllowed");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool dom_paste_allowed;
  dom_paste_allowed = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDOMPasteAllowed(dom_paste_allowed);
}

static void SetDontSendKeyEventsToJavascriptMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDontSendKeyEventsToJavascript");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool dont_send_key_events_to_javascript;
  dont_send_key_events_to_javascript = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDontSendKeyEventsToJavascript(dont_send_key_events_to_javascript);
}

static void SetHighlightAdsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setHighlightAds");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool highlight_ads;
  highlight_ads = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setHighlightAds(highlight_ads);
}

static void SetNetworkQuietTimeoutMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setNetworkQuietTimeout");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  double network_quiet_timeout;
  network_quiet_timeout = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setNetworkQuietTimeout(network_quiet_timeout);
}

static void SetAccelerated2dCanvasMSAASampleCountMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAccelerated2dCanvasMSAASampleCount");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t accelerated_2d_canvas_msaa_sample_count;
  accelerated_2d_canvas_msaa_sample_count = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAccelerated2dCanvasMSAASampleCount(accelerated_2d_canvas_msaa_sample_count);
}

static void SetAcceleratedCompositingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAcceleratedCompositingEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool accelerated_compositing_enabled;
  accelerated_compositing_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAcceleratedCompositingEnabled(accelerated_compositing_enabled);
}

static void SetAccessibilityAlwaysShowFocusMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAccessibilityAlwaysShowFocus");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool accessibility_always_show_focus;
  accessibility_always_show_focus = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAccessibilityAlwaysShowFocus(accessibility_always_show_focus);
}

static void SetAccessibilityFontScaleFactorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAccessibilityFontScaleFactor");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  double accessibility_font_scale_factor;
  accessibility_font_scale_factor = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAccessibilityFontScaleFactor(accessibility_font_scale_factor);
}

static void SetAccessibilityPasswordValuesEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAccessibilityPasswordValuesEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool accessibility_password_values_enabled;
  accessibility_password_values_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAccessibilityPasswordValuesEnabled(accessibility_password_values_enabled);
}

static void SetAllowCustomScrollbarInMainFrameMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAllowCustomScrollbarInMainFrame");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool allow_custom_scrollbar_in_main_frame;
  allow_custom_scrollbar_in_main_frame = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAllowCustomScrollbarInMainFrame(allow_custom_scrollbar_in_main_frame);
}

static void SetAllowFileAccessFromFileURLsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAllowFileAccessFromFileURLs");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool allow_file_access_from_file_urls;
  allow_file_access_from_file_urls = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAllowFileAccessFromFileURLs(allow_file_access_from_file_urls);
}

static void SetAllowGeolocationOnInsecureOriginsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAllowGeolocationOnInsecureOrigins");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool allow_geolocation_on_insecure_origins;
  allow_geolocation_on_insecure_origins = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAllowGeolocationOnInsecureOrigins(allow_geolocation_on_insecure_origins);
}

static void SetAllowRunningOfInsecureContentMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAllowRunningOfInsecureContent");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool allow_running_of_insecure_content;
  allow_running_of_insecure_content = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAllowRunningOfInsecureContent(allow_running_of_insecure_content);
}

static void SetAllowScriptsToCloseWindowsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAllowScriptsToCloseWindows");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool allow_scripts_to_close_windows;
  allow_scripts_to_close_windows = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAllowScriptsToCloseWindows(allow_scripts_to_close_windows);
}

static void SetAllowUniversalAccessFromFileURLsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAllowUniversalAccessFromFileURLs");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool allow_universal_access_from_file_urls;
  allow_universal_access_from_file_urls = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAllowUniversalAccessFromFileURLs(allow_universal_access_from_file_urls);
}

static void SetAlwaysShowContextMenuOnTouchMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAlwaysShowContextMenuOnTouch");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool always_show_context_menu_on_touch;
  always_show_context_menu_on_touch = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAlwaysShowContextMenuOnTouch(always_show_context_menu_on_touch);
}

static void SetAntialiased2dCanvasEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAntialiased2dCanvasEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool antialiased_2d_canvas_enabled;
  antialiased_2d_canvas_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAntialiased2dCanvasEnabled(antialiased_2d_canvas_enabled);
}

static void SetAntialiasedClips2dCanvasEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAntialiasedClips2dCanvasEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool antialiased_clips_2d_canvas_enabled;
  antialiased_clips_2d_canvas_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAntialiasedClips2dCanvasEnabled(antialiased_clips_2d_canvas_enabled);
}

static void SetAriaModalPrunesAXTreeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAriaModalPrunesAXTree");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool aria_modal_prunes_ax_tree;
  aria_modal_prunes_ax_tree = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAriaModalPrunesAXTree(aria_modal_prunes_ax_tree);
}

static void SetAvailableHoverTypesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAvailableHoverTypes");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t available_hover_types;
  available_hover_types = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAvailableHoverTypes(available_hover_types);
}

static void SetAvailablePointerTypesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setAvailablePointerTypes");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t available_pointer_types;
  available_pointer_types = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setAvailablePointerTypes(available_pointer_types);
}

static void SetBarrelButtonForDragEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setBarrelButtonForDragEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool barrel_button_for_drag_enabled;
  barrel_button_for_drag_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setBarrelButtonForDragEnabled(barrel_button_for_drag_enabled);
}

static void SetCaretBrowsingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setCaretBrowsingEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool caret_browsing_enabled;
  caret_browsing_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setCaretBrowsingEnabled(caret_browsing_enabled);
}

static void SetCookieEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setCookieEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool cookie_enabled;
  cookie_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setCookieEnabled(cookie_enabled);
}

static void SetDataSaverHoldbackWebApiMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDataSaverHoldbackWebApi");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool data_saver_holdback_web_api;
  data_saver_holdback_web_api = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDataSaverHoldbackWebApi(data_saver_holdback_web_api);
}

static void SetDefaultFixedFontSizeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDefaultFixedFontSize");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t default_fixed_font_size;
  default_fixed_font_size = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDefaultFixedFontSize(default_fixed_font_size);
}

static void SetDefaultFontSizeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDefaultFontSize");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t default_font_size;
  default_font_size = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDefaultFontSize(default_font_size);
}

static void SetDefaultTextEncodingNameMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setDefaultTextEncodingName", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> default_text_encoding_name;
  default_text_encoding_name = info[0];
  if (!default_text_encoding_name.Prepare())
    return;

  impl->setDefaultTextEncodingName(default_text_encoding_name);
}

static void SetDefaultVideoPosterURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setDefaultVideoPosterURL", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> default_video_poster_url;
  default_video_poster_url = info[0];
  if (!default_video_poster_url.Prepare())
    return;

  impl->setDefaultVideoPosterURL(default_video_poster_url);
}

static void SetDeviceScaleAdjustmentMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDeviceScaleAdjustment");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  double device_scale_adjustment;
  device_scale_adjustment = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDeviceScaleAdjustment(device_scale_adjustment);
}

static void SetDisableReadingFromCanvasMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDisableReadingFromCanvas");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool disable_reading_from_canvas;
  disable_reading_from_canvas = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDisableReadingFromCanvas(disable_reading_from_canvas);
}

static void SetDisallowFetchForDocWrittenScriptsInMainFrameMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDisallowFetchForDocWrittenScriptsInMainFrame");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool disallow_fetch_for_doc_written_scripts_in_main_frame;
  disallow_fetch_for_doc_written_scripts_in_main_frame = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDisallowFetchForDocWrittenScriptsInMainFrame(disallow_fetch_for_doc_written_scripts_in_main_frame);
}

static void SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g;
  disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g);
}

static void SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnectionsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections;
  disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections);
}

static void SetDNSPrefetchingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDNSPrefetchingEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool dns_prefetching_enabled;
  dns_prefetching_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDNSPrefetchingEnabled(dns_prefetching_enabled);
}

static void SetDoHtmlPreloadScanningMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDoHtmlPreloadScanning");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool do_html_preload_scanning;
  do_html_preload_scanning = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDoHtmlPreloadScanning(do_html_preload_scanning);
}

static void SetDoNotUpdateSelectionOnMutatingSelectionRangeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDoNotUpdateSelectionOnMutatingSelectionRange");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool do_not_update_selection_on_mutating_selection_range;
  do_not_update_selection_on_mutating_selection_range = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDoNotUpdateSelectionOnMutatingSelectionRange(do_not_update_selection_on_mutating_selection_range);
}

static void SetDownloadableBinaryFontsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setDownloadableBinaryFontsEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool downloadable_binary_fonts_enabled;
  downloadable_binary_fonts_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setDownloadableBinaryFontsEnabled(downloadable_binary_fonts_enabled);
}

static void SetEmbeddedMediaExperienceEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setEmbeddedMediaExperienceEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool embedded_media_experience_enabled;
  embedded_media_experience_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setEmbeddedMediaExperienceEnabled(embedded_media_experience_enabled);
}

static void SetForceAndroidOverlayScrollbarMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceAndroidOverlayScrollbar");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool force_android_overlay_scrollbar;
  force_android_overlay_scrollbar = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceAndroidOverlayScrollbar(force_android_overlay_scrollbar);
}

static void SetForceDarkModeBackgroundBrightnessThresholdMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceDarkModeBackgroundBrightnessThreshold");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t force_dark_mode_background_brightness_threshold;
  force_dark_mode_background_brightness_threshold = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceDarkModeBackgroundBrightnessThreshold(force_dark_mode_background_brightness_threshold);
}

static void SetForceDarkModeContrastMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceDarkModeContrast");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  double force_dark_mode_contrast;
  force_dark_mode_contrast = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceDarkModeContrast(force_dark_mode_contrast);
}

static void SetForceDarkModeEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceDarkModeEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool force_dark_mode_enabled;
  force_dark_mode_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceDarkModeEnabled(force_dark_mode_enabled);
}

static void SetForceDarkModeGrayscaleMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceDarkModeGrayscale");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool force_dark_mode_grayscale;
  force_dark_mode_grayscale = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceDarkModeGrayscale(force_dark_mode_grayscale);
}

static void SetForceDarkModeTextBrightnessThresholdMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceDarkModeTextBrightnessThreshold");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t force_dark_mode_text_brightness_threshold;
  force_dark_mode_text_brightness_threshold = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceDarkModeTextBrightnessThreshold(force_dark_mode_text_brightness_threshold);
}

static void SetForceMainWorldInitializationMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceMainWorldInitialization");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool force_main_world_initialization;
  force_main_world_initialization = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceMainWorldInitialization(force_main_world_initialization);
}

static void SetForceTouchEventFeatureDetectionForInspectorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceTouchEventFeatureDetectionForInspector");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool force_touch_event_feature_detection_for_inspector;
  force_touch_event_feature_detection_for_inspector = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceTouchEventFeatureDetectionForInspector(force_touch_event_feature_detection_for_inspector);
}

static void SetForceZeroLayoutHeightMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setForceZeroLayoutHeight");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool force_zero_layout_height;
  force_zero_layout_height = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setForceZeroLayoutHeight(force_zero_layout_height);
}

static void SetFullscreenSupportedMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setFullscreenSupported");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool fullscreen_supported;
  fullscreen_supported = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setFullscreenSupported(fullscreen_supported);
}

static void SetHideDownloadUIMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setHideDownloadUI");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool hide_download_ui;
  hide_download_ui = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setHideDownloadUI(hide_download_ui);
}

static void SetHideScrollbarsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setHideScrollbars");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool hide_scrollbars;
  hide_scrollbars = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setHideScrollbars(hide_scrollbars);
}

static void SetHyperlinkAuditingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setHyperlinkAuditingEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool hyperlink_auditing_enabled;
  hyperlink_auditing_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setHyperlinkAuditingEnabled(hyperlink_auditing_enabled);
}

static void SetIgnoreMainFrameOverflowHiddenQuirkMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setIgnoreMainFrameOverflowHiddenQuirk");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool ignore_main_frame_overflow_hidden_quirk;
  ignore_main_frame_overflow_hidden_quirk = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setIgnoreMainFrameOverflowHiddenQuirk(ignore_main_frame_overflow_hidden_quirk);
}

static void SetImagesEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setImagesEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool images_enabled;
  images_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setImagesEnabled(images_enabled);
}

static void SetImmersiveModeEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setImmersiveModeEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool immersive_mode_enabled;
  immersive_mode_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setImmersiveModeEnabled(immersive_mode_enabled);
}

static void SetInlineTextBoxAccessibilityEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setInlineTextBoxAccessibilityEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool inline_text_box_accessibility_enabled;
  inline_text_box_accessibility_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setInlineTextBoxAccessibilityEnabled(inline_text_box_accessibility_enabled);
}

static void SetJavaScriptCanAccessClipboardMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setJavaScriptCanAccessClipboard");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool java_script_can_access_clipboard;
  java_script_can_access_clipboard = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setJavaScriptCanAccessClipboard(java_script_can_access_clipboard);
}

static void SetLazyFrameLoadingDistanceThresholdPx2GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyFrameLoadingDistanceThresholdPx2G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_frame_loading_distance_threshold_px_2_g;
  lazy_frame_loading_distance_threshold_px_2_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyFrameLoadingDistanceThresholdPx2G(lazy_frame_loading_distance_threshold_px_2_g);
}

static void SetLazyFrameLoadingDistanceThresholdPx3GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyFrameLoadingDistanceThresholdPx3G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_frame_loading_distance_threshold_px_3_g;
  lazy_frame_loading_distance_threshold_px_3_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyFrameLoadingDistanceThresholdPx3G(lazy_frame_loading_distance_threshold_px_3_g);
}

static void SetLazyFrameLoadingDistanceThresholdPx4GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyFrameLoadingDistanceThresholdPx4G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_frame_loading_distance_threshold_px_4_g;
  lazy_frame_loading_distance_threshold_px_4_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyFrameLoadingDistanceThresholdPx4G(lazy_frame_loading_distance_threshold_px_4_g);
}

static void SetLazyFrameLoadingDistanceThresholdPxOfflineMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyFrameLoadingDistanceThresholdPxOffline");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_frame_loading_distance_threshold_px_offline;
  lazy_frame_loading_distance_threshold_px_offline = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyFrameLoadingDistanceThresholdPxOffline(lazy_frame_loading_distance_threshold_px_offline);
}

static void SetLazyFrameLoadingDistanceThresholdPxSlow2GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyFrameLoadingDistanceThresholdPxSlow2G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_frame_loading_distance_threshold_px_slow_2_g;
  lazy_frame_loading_distance_threshold_px_slow_2_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyFrameLoadingDistanceThresholdPxSlow2G(lazy_frame_loading_distance_threshold_px_slow_2_g);
}

static void SetLazyFrameLoadingDistanceThresholdPxUnknownMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyFrameLoadingDistanceThresholdPxUnknown");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_frame_loading_distance_threshold_px_unknown;
  lazy_frame_loading_distance_threshold_px_unknown = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyFrameLoadingDistanceThresholdPxUnknown(lazy_frame_loading_distance_threshold_px_unknown);
}

static void SetLazyImageFirstKFullyLoad2GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageFirstKFullyLoad2G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_first_k_fully_load_2_g;
  lazy_image_first_k_fully_load_2_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageFirstKFullyLoad2G(lazy_image_first_k_fully_load_2_g);
}

static void SetLazyImageFirstKFullyLoad3GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageFirstKFullyLoad3G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_first_k_fully_load_3_g;
  lazy_image_first_k_fully_load_3_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageFirstKFullyLoad3G(lazy_image_first_k_fully_load_3_g);
}

static void SetLazyImageFirstKFullyLoad4GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageFirstKFullyLoad4G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_first_k_fully_load_4_g;
  lazy_image_first_k_fully_load_4_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageFirstKFullyLoad4G(lazy_image_first_k_fully_load_4_g);
}

static void SetLazyImageFirstKFullyLoadSlow2GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageFirstKFullyLoadSlow2G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_first_k_fully_load_slow_2_g;
  lazy_image_first_k_fully_load_slow_2_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageFirstKFullyLoadSlow2G(lazy_image_first_k_fully_load_slow_2_g);
}

static void SetLazyImageFirstKFullyLoadUnknownMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageFirstKFullyLoadUnknown");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_first_k_fully_load_unknown;
  lazy_image_first_k_fully_load_unknown = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageFirstKFullyLoadUnknown(lazy_image_first_k_fully_load_unknown);
}

static void SetLazyImageLoadingDistanceThresholdPx2GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageLoadingDistanceThresholdPx2G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_loading_distance_threshold_px_2_g;
  lazy_image_loading_distance_threshold_px_2_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageLoadingDistanceThresholdPx2G(lazy_image_loading_distance_threshold_px_2_g);
}

static void SetLazyImageLoadingDistanceThresholdPx3GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageLoadingDistanceThresholdPx3G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_loading_distance_threshold_px_3_g;
  lazy_image_loading_distance_threshold_px_3_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageLoadingDistanceThresholdPx3G(lazy_image_loading_distance_threshold_px_3_g);
}

static void SetLazyImageLoadingDistanceThresholdPx4GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageLoadingDistanceThresholdPx4G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_loading_distance_threshold_px_4_g;
  lazy_image_loading_distance_threshold_px_4_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageLoadingDistanceThresholdPx4G(lazy_image_loading_distance_threshold_px_4_g);
}

static void SetLazyImageLoadingDistanceThresholdPxOfflineMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageLoadingDistanceThresholdPxOffline");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_loading_distance_threshold_px_offline;
  lazy_image_loading_distance_threshold_px_offline = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageLoadingDistanceThresholdPxOffline(lazy_image_loading_distance_threshold_px_offline);
}

static void SetLazyImageLoadingDistanceThresholdPxSlow2GMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageLoadingDistanceThresholdPxSlow2G");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_loading_distance_threshold_px_slow_2_g;
  lazy_image_loading_distance_threshold_px_slow_2_g = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageLoadingDistanceThresholdPxSlow2G(lazy_image_loading_distance_threshold_px_slow_2_g);
}

static void SetLazyImageLoadingDistanceThresholdPxUnknownMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyImageLoadingDistanceThresholdPxUnknown");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t lazy_image_loading_distance_threshold_px_unknown;
  lazy_image_loading_distance_threshold_px_unknown = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyImageLoadingDistanceThresholdPxUnknown(lazy_image_loading_distance_threshold_px_unknown);
}

static void SetLazyLoadEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLazyLoadEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool lazy_load_enabled;
  lazy_load_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLazyLoadEnabled(lazy_load_enabled);
}

static void SetLoadWithOverviewModeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLoadWithOverviewMode");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool load_with_overview_mode;
  load_with_overview_mode = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLoadWithOverviewMode(load_with_overview_mode);
}

static void SetLoadsImagesAutomaticallyMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLoadsImagesAutomatically");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool loads_images_automatically;
  loads_images_automatically = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLoadsImagesAutomatically(loads_images_automatically);
}

static void SetLocalStorageEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLocalStorageEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool local_storage_enabled;
  local_storage_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLocalStorageEnabled(local_storage_enabled);
}

static void SetLogDnsPrefetchAndPreconnectMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLogDnsPrefetchAndPreconnect");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool log_dns_prefetch_and_preconnect;
  log_dns_prefetch_and_preconnect = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLogDnsPrefetchAndPreconnect(log_dns_prefetch_and_preconnect);
}

static void SetLogPreloadMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setLogPreload");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool log_preload;
  log_preload = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setLogPreload(log_preload);
}

static void SetMainFrameClipsContentMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMainFrameClipsContent");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool main_frame_clips_content;
  main_frame_clips_content = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMainFrameClipsContent(main_frame_clips_content);
}

static void SetMainFrameResizesAreOrientationChangesMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMainFrameResizesAreOrientationChanges");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool main_frame_resizes_are_orientation_changes;
  main_frame_resizes_are_orientation_changes = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMainFrameResizesAreOrientationChanges(main_frame_resizes_are_orientation_changes);
}

static void SetMaxTouchPointsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMaxTouchPoints");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t max_touch_points;
  max_touch_points = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMaxTouchPoints(max_touch_points);
}

static void SetMediaControlsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMediaControlsEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool media_controls_enabled;
  media_controls_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMediaControlsEnabled(media_controls_enabled);
}

static void SetMediaTypeOverrideMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setMediaTypeOverride", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> media_type_override;
  media_type_override = info[0];
  if (!media_type_override.Prepare())
    return;

  impl->setMediaTypeOverride(media_type_override);
}

static void SetMinimumFontSizeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMinimumFontSize");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t minimum_font_size;
  minimum_font_size = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMinimumFontSize(minimum_font_size);
}

static void SetMinimumLogicalFontSizeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMinimumLogicalFontSize");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t minimum_logical_font_size;
  minimum_logical_font_size = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMinimumLogicalFontSize(minimum_logical_font_size);
}

static void SetMockGestureTapHighlightsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMockGestureTapHighlightsEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool mock_gesture_tap_highlights_enabled;
  mock_gesture_tap_highlights_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMockGestureTapHighlightsEnabled(mock_gesture_tap_highlights_enabled);
}

static void SetMultiTargetTapNotificationEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setMultiTargetTapNotificationEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool multi_target_tap_notification_enabled;
  multi_target_tap_notification_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setMultiTargetTapNotificationEnabled(multi_target_tap_notification_enabled);
}

static void SetNavigateOnDragDropMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setNavigateOnDragDrop");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool navigate_on_drag_drop;
  navigate_on_drag_drop = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setNavigateOnDragDrop(navigate_on_drag_drop);
}

static void SetNavigatorPlatformOverrideMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setNavigatorPlatformOverride", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> navigator_platform_override;
  navigator_platform_override = info[0];
  if (!navigator_platform_override.Prepare())
    return;

  impl->setNavigatorPlatformOverride(navigator_platform_override);
}

static void SetOfflineWebApplicationCacheEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setOfflineWebApplicationCacheEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool offline_web_application_cache_enabled;
  offline_web_application_cache_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setOfflineWebApplicationCacheEnabled(offline_web_application_cache_enabled);
}

static void SetPasswordEchoDurationInSecondsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPasswordEchoDurationInSeconds");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  double password_echo_duration_in_seconds;
  password_echo_duration_in_seconds = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPasswordEchoDurationInSeconds(password_echo_duration_in_seconds);
}

static void SetPasswordEchoEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPasswordEchoEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool password_echo_enabled;
  password_echo_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPasswordEchoEnabled(password_echo_enabled);
}

static void SetPictureInPictureEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPictureInPictureEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool picture_in_picture_enabled;
  picture_in_picture_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPictureInPictureEnabled(picture_in_picture_enabled);
}

static void SetPluginsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPluginsEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool plugins_enabled;
  plugins_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPluginsEnabled(plugins_enabled);
}

static void SetPreferCompositingToLCDTextEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPreferCompositingToLCDTextEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool prefer_compositing_to_lcd_text_enabled;
  prefer_compositing_to_lcd_text_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPreferCompositingToLCDTextEnabled(prefer_compositing_to_lcd_text_enabled);
}

static void SetPreferHiddenVolumeControlsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPreferHiddenVolumeControls");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool prefer_hidden_volume_controls;
  prefer_hidden_volume_controls = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPreferHiddenVolumeControls(prefer_hidden_volume_controls);
}

static void SetPrefersReducedMotionMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPrefersReducedMotion");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool prefers_reduced_motion;
  prefers_reduced_motion = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPrefersReducedMotion(prefers_reduced_motion);
}

static void SetPresentationReceiverMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPresentationReceiver");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool presentation_receiver;
  presentation_receiver = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPresentationReceiver(presentation_receiver);
}

static void SetPresentationRequiresUserGestureMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setPresentationRequiresUserGesture");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool presentation_requires_user_gesture;
  presentation_requires_user_gesture = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setPresentationRequiresUserGesture(presentation_requires_user_gesture);
}

static void SetReportScreenSizeInPhysicalPixelsQuirkMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setReportScreenSizeInPhysicalPixelsQuirk");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool report_screen_size_in_physical_pixels_quirk;
  report_screen_size_in_physical_pixels_quirk = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setReportScreenSizeInPhysicalPixelsQuirk(report_screen_size_in_physical_pixels_quirk);
}

static void SetRubberBandingOnCompositorThreadMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setRubberBandingOnCompositorThread");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool rubber_banding_on_compositor_thread;
  rubber_banding_on_compositor_thread = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setRubberBandingOnCompositorThread(rubber_banding_on_compositor_thread);
}

static void SetScriptEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setScriptEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool script_enabled;
  script_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setScriptEnabled(script_enabled);
}

static void SetScrollAnimatorEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setScrollAnimatorEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool scroll_animator_enabled;
  scroll_animator_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setScrollAnimatorEnabled(scroll_animator_enabled);
}

static void SetSelectTrailingWhitespaceEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSelectTrailingWhitespaceEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool select_trailing_whitespace_enabled;
  select_trailing_whitespace_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSelectTrailingWhitespaceEnabled(select_trailing_whitespace_enabled);
}

static void SetSelectionIncludesAltImageTextMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSelectionIncludesAltImageText");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool selection_includes_alt_image_text;
  selection_includes_alt_image_text = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSelectionIncludesAltImageText(selection_includes_alt_image_text);
}

static void SetShouldClearDocumentBackgroundMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setShouldClearDocumentBackground");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool should_clear_document_background;
  should_clear_document_background = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setShouldClearDocumentBackground(should_clear_document_background);
}

static void SetShouldPrintBackgroundsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setShouldPrintBackgrounds");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool should_print_backgrounds;
  should_print_backgrounds = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setShouldPrintBackgrounds(should_print_backgrounds);
}

static void SetShouldProtectAgainstIpcFloodingMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setShouldProtectAgainstIpcFlooding");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool should_protect_against_ipc_flooding;
  should_protect_against_ipc_flooding = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setShouldProtectAgainstIpcFlooding(should_protect_against_ipc_flooding);
}

static void SetShouldRespectImageOrientationMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setShouldRespectImageOrientation");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool should_respect_image_orientation;
  should_respect_image_orientation = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setShouldRespectImageOrientation(should_respect_image_orientation);
}

static void SetShouldReuseGlobalForUnownedMainFrameMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setShouldReuseGlobalForUnownedMainFrame");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool should_reuse_global_for_unowned_main_frame;
  should_reuse_global_for_unowned_main_frame = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setShouldReuseGlobalForUnownedMainFrame(should_reuse_global_for_unowned_main_frame);
}

static void SetShowContextMenuOnMouseUpMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setShowContextMenuOnMouseUp");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool show_context_menu_on_mouse_up;
  show_context_menu_on_mouse_up = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setShowContextMenuOnMouseUp(show_context_menu_on_mouse_up);
}

static void SetShrinksViewportContentToFitMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setShrinksViewportContentToFit");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool shrinks_viewport_content_to_fit;
  shrinks_viewport_content_to_fit = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setShrinksViewportContentToFit(shrinks_viewport_content_to_fit);
}

static void SetSmartInsertDeleteEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSmartInsertDeleteEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool smart_insert_delete_enabled;
  smart_insert_delete_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSmartInsertDeleteEnabled(smart_insert_delete_enabled);
}

static void SetSmoothScrollForFindEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSmoothScrollForFindEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool smooth_scroll_for_find_enabled;
  smooth_scroll_for_find_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSmoothScrollForFindEnabled(smooth_scroll_for_find_enabled);
}

static void SetSpatialNavigationEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSpatialNavigationEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool spatial_navigation_enabled;
  spatial_navigation_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSpatialNavigationEnabled(spatial_navigation_enabled);
}

static void SetSpellCheckEnabledByDefaultMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSpellCheckEnabledByDefault");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool spell_check_enabled_by_default;
  spell_check_enabled_by_default = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSpellCheckEnabledByDefault(spell_check_enabled_by_default);
}

static void SetStrictMixedContentCheckingMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setStrictMixedContentChecking");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool strict_mixed_content_checking;
  strict_mixed_content_checking = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setStrictMixedContentChecking(strict_mixed_content_checking);
}

static void SetStrictMixedContentCheckingForPluginMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setStrictMixedContentCheckingForPlugin");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool strict_mixed_content_checking_for_plugin;
  strict_mixed_content_checking_for_plugin = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setStrictMixedContentCheckingForPlugin(strict_mixed_content_checking_for_plugin);
}

static void SetStrictPowerfulFeatureRestrictionsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setStrictPowerfulFeatureRestrictions");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool strict_powerful_feature_restrictions;
  strict_powerful_feature_restrictions = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setStrictPowerfulFeatureRestrictions(strict_powerful_feature_restrictions);
}

static void SetStrictlyBlockBlockableMixedContentMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setStrictlyBlockBlockableMixedContent");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool strictly_block_blockable_mixed_content;
  strictly_block_blockable_mixed_content = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setStrictlyBlockBlockableMixedContent(strictly_block_blockable_mixed_content);
}

static void SetSupportsMultipleWindowsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSupportsMultipleWindows");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool supports_multiple_windows;
  supports_multiple_windows = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSupportsMultipleWindows(supports_multiple_windows);
}

static void SetSyncXHRInDocumentsEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setSyncXHRInDocumentsEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool sync_xhr_in_documents_enabled;
  sync_xhr_in_documents_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setSyncXHRInDocumentsEnabled(sync_xhr_in_documents_enabled);
}

static void SetTextAreasAreResizableMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setTextAreasAreResizable");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool text_areas_are_resizable;
  text_areas_are_resizable = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setTextAreasAreResizable(text_areas_are_resizable);
}

static void SetTextTrackBackgroundColorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackBackgroundColor", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_background_color;
  text_track_background_color = info[0];
  if (!text_track_background_color.Prepare())
    return;

  impl->setTextTrackBackgroundColor(text_track_background_color);
}

static void SetTextTrackFontFamilyMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackFontFamily", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_font_family;
  text_track_font_family = info[0];
  if (!text_track_font_family.Prepare())
    return;

  impl->setTextTrackFontFamily(text_track_font_family);
}

static void SetTextTrackFontStyleMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackFontStyle", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_font_style;
  text_track_font_style = info[0];
  if (!text_track_font_style.Prepare())
    return;

  impl->setTextTrackFontStyle(text_track_font_style);
}

static void SetTextTrackFontVariantMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackFontVariant", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_font_variant;
  text_track_font_variant = info[0];
  if (!text_track_font_variant.Prepare())
    return;

  impl->setTextTrackFontVariant(text_track_font_variant);
}

static void SetTextTrackMarginPercentageMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setTextTrackMarginPercentage");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  double text_track_margin_percentage;
  text_track_margin_percentage = NativeValueTraits<IDLDouble>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setTextTrackMarginPercentage(text_track_margin_percentage);
}

static void SetTextTrackTextColorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackTextColor", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_text_color;
  text_track_text_color = info[0];
  if (!text_track_text_color.Prepare())
    return;

  impl->setTextTrackTextColor(text_track_text_color);
}

static void SetTextTrackTextShadowMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackTextShadow", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_text_shadow;
  text_track_text_shadow = info[0];
  if (!text_track_text_shadow.Prepare())
    return;

  impl->setTextTrackTextShadow(text_track_text_shadow);
}

static void SetTextTrackTextSizeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackTextSize", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_text_size;
  text_track_text_size = info[0];
  if (!text_track_text_size.Prepare())
    return;

  impl->setTextTrackTextSize(text_track_text_size);
}

static void SetTextTrackWindowColorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackWindowColor", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_window_color;
  text_track_window_color = info[0];
  if (!text_track_window_color.Prepare())
    return;

  impl->setTextTrackWindowColor(text_track_window_color);
}

static void SetTextTrackWindowPaddingMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackWindowPadding", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_window_padding;
  text_track_window_padding = info[0];
  if (!text_track_window_padding.Prepare())
    return;

  impl->setTextTrackWindowPadding(text_track_window_padding);
}

static void SetTextTrackWindowRadiusMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setTextTrackWindowRadius", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> text_track_window_radius;
  text_track_window_radius = info[0];
  if (!text_track_window_radius.Prepare())
    return;

  impl->setTextTrackWindowRadius(text_track_window_radius);
}

static void SetThreadedScrollingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setThreadedScrollingEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool threaded_scrolling_enabled;
  threaded_scrolling_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setThreadedScrollingEnabled(threaded_scrolling_enabled);
}

static void SetTouchAdjustmentEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setTouchAdjustmentEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool touch_adjustment_enabled;
  touch_adjustment_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setTouchAdjustmentEnabled(touch_adjustment_enabled);
}

static void SetTouchDragDropEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setTouchDragDropEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool touch_drag_drop_enabled;
  touch_drag_drop_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setTouchDragDropEnabled(touch_drag_drop_enabled);
}

static void SetTouchEditingEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setTouchEditingEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool touch_editing_enabled;
  touch_editing_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setTouchEditingEnabled(touch_editing_enabled);
}

static void SetUseLegacyBackgroundSizeShorthandBehaviorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setUseLegacyBackgroundSizeShorthandBehavior");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool use_legacy_background_size_shorthand_behavior;
  use_legacy_background_size_shorthand_behavior = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setUseLegacyBackgroundSizeShorthandBehavior(use_legacy_background_size_shorthand_behavior);
}

static void SetUseWideViewportMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setUseWideViewport");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool use_wide_viewport;
  use_wide_viewport = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setUseWideViewport(use_wide_viewport);
}

static void SetValidationMessageTimerMagnificationMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setValidationMessageTimerMagnification");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  int32_t validation_message_timer_magnification;
  validation_message_timer_magnification = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setValidationMessageTimerMagnification(validation_message_timer_magnification);
}

static void SetViewportEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setViewportEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool viewport_enabled;
  viewport_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setViewportEnabled(viewport_enabled);
}

static void SetViewportMetaEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setViewportMetaEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool viewport_meta_enabled;
  viewport_meta_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setViewportMetaEnabled(viewport_meta_enabled);
}

static void SetViewportMetaMergeContentQuirkMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setViewportMetaMergeContentQuirk");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool viewport_meta_merge_content_quirk;
  viewport_meta_merge_content_quirk = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setViewportMetaMergeContentQuirk(viewport_meta_merge_content_quirk);
}

static void SetViewportMetaZeroValuesQuirkMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setViewportMetaZeroValuesQuirk");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool viewport_meta_zero_values_quirk;
  viewport_meta_zero_values_quirk = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setViewportMetaZeroValuesQuirk(viewport_meta_zero_values_quirk);
}

static void SetWebAppScopeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("setWebAppScope", "InternalSettingsGenerated", ExceptionMessages::NotEnoughArguments(1, info.Length())));
    return;
  }

  V8StringResource<> web_app_scope;
  web_app_scope = info[0];
  if (!web_app_scope.Prepare())
    return;

  impl->setWebAppScope(web_app_scope);
}

static void SetWebGL1EnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setWebGL1Enabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool web_gl_1_enabled;
  web_gl_1_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setWebGL1Enabled(web_gl_1_enabled);
}

static void SetWebGL2EnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setWebGL2Enabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool webgl2_enabled;
  webgl2_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setWebGL2Enabled(webgl2_enabled);
}

static void SetWebGLErrorsToConsoleEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setWebGLErrorsToConsoleEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool web_gl_errors_to_console_enabled;
  web_gl_errors_to_console_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setWebGLErrorsToConsoleEnabled(web_gl_errors_to_console_enabled);
}

static void SetWebSecurityEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setWebSecurityEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool web_security_enabled;
  web_security_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setWebSecurityEnabled(web_security_enabled);
}

static void SetWideViewportQuirkEnabledMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "InternalSettingsGenerated", "setWideViewportQuirkEnabled");

  InternalSettingsGenerated* impl = V8InternalSettingsGenerated::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  bool wide_viewport_quirk_enabled;
  wide_viewport_quirk_enabled = NativeValueTraits<IDLBoolean>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->setWideViewportQuirkEnabled(wide_viewport_quirk_enabled);
}

}  // namespace internal_settings_generated_v8_internal

void V8InternalSettingsGenerated::SetDOMPasteAllowedMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDOMPasteAllowed");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDOMPasteAllowed");

  internal_settings_generated_v8_internal::SetDOMPasteAllowedMethod(info);
}

void V8InternalSettingsGenerated::SetDontSendKeyEventsToJavascriptMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDontSendKeyEventsToJavascript");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDontSendKeyEventsToJavascript");

  internal_settings_generated_v8_internal::SetDontSendKeyEventsToJavascriptMethod(info);
}

void V8InternalSettingsGenerated::SetHighlightAdsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setHighlightAds");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setHighlightAds");

  internal_settings_generated_v8_internal::SetHighlightAdsMethod(info);
}

void V8InternalSettingsGenerated::SetNetworkQuietTimeoutMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setNetworkQuietTimeout");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setNetworkQuietTimeout");

  internal_settings_generated_v8_internal::SetNetworkQuietTimeoutMethod(info);
}

void V8InternalSettingsGenerated::SetAccelerated2dCanvasMSAASampleCountMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAccelerated2dCanvasMSAASampleCount");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAccelerated2dCanvasMSAASampleCount");

  internal_settings_generated_v8_internal::SetAccelerated2dCanvasMSAASampleCountMethod(info);
}

void V8InternalSettingsGenerated::SetAcceleratedCompositingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAcceleratedCompositingEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAcceleratedCompositingEnabled");

  internal_settings_generated_v8_internal::SetAcceleratedCompositingEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetAccessibilityAlwaysShowFocusMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAccessibilityAlwaysShowFocus");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAccessibilityAlwaysShowFocus");

  internal_settings_generated_v8_internal::SetAccessibilityAlwaysShowFocusMethod(info);
}

void V8InternalSettingsGenerated::SetAccessibilityFontScaleFactorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAccessibilityFontScaleFactor");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAccessibilityFontScaleFactor");

  internal_settings_generated_v8_internal::SetAccessibilityFontScaleFactorMethod(info);
}

void V8InternalSettingsGenerated::SetAccessibilityPasswordValuesEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAccessibilityPasswordValuesEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAccessibilityPasswordValuesEnabled");

  internal_settings_generated_v8_internal::SetAccessibilityPasswordValuesEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetAllowCustomScrollbarInMainFrameMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAllowCustomScrollbarInMainFrame");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAllowCustomScrollbarInMainFrame");

  internal_settings_generated_v8_internal::SetAllowCustomScrollbarInMainFrameMethod(info);
}

void V8InternalSettingsGenerated::SetAllowFileAccessFromFileURLsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAllowFileAccessFromFileURLs");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAllowFileAccessFromFileURLs");

  internal_settings_generated_v8_internal::SetAllowFileAccessFromFileURLsMethod(info);
}

void V8InternalSettingsGenerated::SetAllowGeolocationOnInsecureOriginsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAllowGeolocationOnInsecureOrigins");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAllowGeolocationOnInsecureOrigins");

  internal_settings_generated_v8_internal::SetAllowGeolocationOnInsecureOriginsMethod(info);
}

void V8InternalSettingsGenerated::SetAllowRunningOfInsecureContentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAllowRunningOfInsecureContent");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAllowRunningOfInsecureContent");

  internal_settings_generated_v8_internal::SetAllowRunningOfInsecureContentMethod(info);
}

void V8InternalSettingsGenerated::SetAllowScriptsToCloseWindowsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAllowScriptsToCloseWindows");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAllowScriptsToCloseWindows");

  internal_settings_generated_v8_internal::SetAllowScriptsToCloseWindowsMethod(info);
}

void V8InternalSettingsGenerated::SetAllowUniversalAccessFromFileURLsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAllowUniversalAccessFromFileURLs");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAllowUniversalAccessFromFileURLs");

  internal_settings_generated_v8_internal::SetAllowUniversalAccessFromFileURLsMethod(info);
}

void V8InternalSettingsGenerated::SetAlwaysShowContextMenuOnTouchMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAlwaysShowContextMenuOnTouch");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAlwaysShowContextMenuOnTouch");

  internal_settings_generated_v8_internal::SetAlwaysShowContextMenuOnTouchMethod(info);
}

void V8InternalSettingsGenerated::SetAntialiased2dCanvasEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAntialiased2dCanvasEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAntialiased2dCanvasEnabled");

  internal_settings_generated_v8_internal::SetAntialiased2dCanvasEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetAntialiasedClips2dCanvasEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAntialiasedClips2dCanvasEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAntialiasedClips2dCanvasEnabled");

  internal_settings_generated_v8_internal::SetAntialiasedClips2dCanvasEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetAriaModalPrunesAXTreeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAriaModalPrunesAXTree");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAriaModalPrunesAXTree");

  internal_settings_generated_v8_internal::SetAriaModalPrunesAXTreeMethod(info);
}

void V8InternalSettingsGenerated::SetAvailableHoverTypesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAvailableHoverTypes");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAvailableHoverTypes");

  internal_settings_generated_v8_internal::SetAvailableHoverTypesMethod(info);
}

void V8InternalSettingsGenerated::SetAvailablePointerTypesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setAvailablePointerTypes");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setAvailablePointerTypes");

  internal_settings_generated_v8_internal::SetAvailablePointerTypesMethod(info);
}

void V8InternalSettingsGenerated::SetBarrelButtonForDragEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setBarrelButtonForDragEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setBarrelButtonForDragEnabled");

  internal_settings_generated_v8_internal::SetBarrelButtonForDragEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetCaretBrowsingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setCaretBrowsingEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setCaretBrowsingEnabled");

  internal_settings_generated_v8_internal::SetCaretBrowsingEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetCookieEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setCookieEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setCookieEnabled");

  internal_settings_generated_v8_internal::SetCookieEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetDataSaverHoldbackWebApiMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDataSaverHoldbackWebApi");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDataSaverHoldbackWebApi");

  internal_settings_generated_v8_internal::SetDataSaverHoldbackWebApiMethod(info);
}

void V8InternalSettingsGenerated::SetDefaultFixedFontSizeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDefaultFixedFontSize");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDefaultFixedFontSize");

  internal_settings_generated_v8_internal::SetDefaultFixedFontSizeMethod(info);
}

void V8InternalSettingsGenerated::SetDefaultFontSizeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDefaultFontSize");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDefaultFontSize");

  internal_settings_generated_v8_internal::SetDefaultFontSizeMethod(info);
}

void V8InternalSettingsGenerated::SetDefaultTextEncodingNameMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDefaultTextEncodingName");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDefaultTextEncodingName");

  internal_settings_generated_v8_internal::SetDefaultTextEncodingNameMethod(info);
}

void V8InternalSettingsGenerated::SetDefaultVideoPosterURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDefaultVideoPosterURL");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDefaultVideoPosterURL");

  internal_settings_generated_v8_internal::SetDefaultVideoPosterURLMethod(info);
}

void V8InternalSettingsGenerated::SetDeviceScaleAdjustmentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDeviceScaleAdjustment");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDeviceScaleAdjustment");

  internal_settings_generated_v8_internal::SetDeviceScaleAdjustmentMethod(info);
}

void V8InternalSettingsGenerated::SetDisableReadingFromCanvasMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDisableReadingFromCanvas");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDisableReadingFromCanvas");

  internal_settings_generated_v8_internal::SetDisableReadingFromCanvasMethod(info);
}

void V8InternalSettingsGenerated::SetDisallowFetchForDocWrittenScriptsInMainFrameMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDisallowFetchForDocWrittenScriptsInMainFrame");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDisallowFetchForDocWrittenScriptsInMainFrame");

  internal_settings_generated_v8_internal::SetDisallowFetchForDocWrittenScriptsInMainFrameMethod(info);
}

void V8InternalSettingsGenerated::SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G");

  internal_settings_generated_v8_internal::SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2GMethod(info);
}

void V8InternalSettingsGenerated::SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnectionsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections");

  internal_settings_generated_v8_internal::SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnectionsMethod(info);
}

void V8InternalSettingsGenerated::SetDNSPrefetchingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDNSPrefetchingEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDNSPrefetchingEnabled");

  internal_settings_generated_v8_internal::SetDNSPrefetchingEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetDoHtmlPreloadScanningMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDoHtmlPreloadScanning");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDoHtmlPreloadScanning");

  internal_settings_generated_v8_internal::SetDoHtmlPreloadScanningMethod(info);
}

void V8InternalSettingsGenerated::SetDoNotUpdateSelectionOnMutatingSelectionRangeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDoNotUpdateSelectionOnMutatingSelectionRange");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDoNotUpdateSelectionOnMutatingSelectionRange");

  internal_settings_generated_v8_internal::SetDoNotUpdateSelectionOnMutatingSelectionRangeMethod(info);
}

void V8InternalSettingsGenerated::SetDownloadableBinaryFontsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setDownloadableBinaryFontsEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setDownloadableBinaryFontsEnabled");

  internal_settings_generated_v8_internal::SetDownloadableBinaryFontsEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetEmbeddedMediaExperienceEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setEmbeddedMediaExperienceEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setEmbeddedMediaExperienceEnabled");

  internal_settings_generated_v8_internal::SetEmbeddedMediaExperienceEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetForceAndroidOverlayScrollbarMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceAndroidOverlayScrollbar");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceAndroidOverlayScrollbar");

  internal_settings_generated_v8_internal::SetForceAndroidOverlayScrollbarMethod(info);
}

void V8InternalSettingsGenerated::SetForceDarkModeBackgroundBrightnessThresholdMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceDarkModeBackgroundBrightnessThreshold");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceDarkModeBackgroundBrightnessThreshold");

  internal_settings_generated_v8_internal::SetForceDarkModeBackgroundBrightnessThresholdMethod(info);
}

void V8InternalSettingsGenerated::SetForceDarkModeContrastMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceDarkModeContrast");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceDarkModeContrast");

  internal_settings_generated_v8_internal::SetForceDarkModeContrastMethod(info);
}

void V8InternalSettingsGenerated::SetForceDarkModeEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceDarkModeEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceDarkModeEnabled");

  internal_settings_generated_v8_internal::SetForceDarkModeEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetForceDarkModeGrayscaleMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceDarkModeGrayscale");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceDarkModeGrayscale");

  internal_settings_generated_v8_internal::SetForceDarkModeGrayscaleMethod(info);
}

void V8InternalSettingsGenerated::SetForceDarkModeTextBrightnessThresholdMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceDarkModeTextBrightnessThreshold");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceDarkModeTextBrightnessThreshold");

  internal_settings_generated_v8_internal::SetForceDarkModeTextBrightnessThresholdMethod(info);
}

void V8InternalSettingsGenerated::SetForceMainWorldInitializationMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceMainWorldInitialization");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceMainWorldInitialization");

  internal_settings_generated_v8_internal::SetForceMainWorldInitializationMethod(info);
}

void V8InternalSettingsGenerated::SetForceTouchEventFeatureDetectionForInspectorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceTouchEventFeatureDetectionForInspector");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceTouchEventFeatureDetectionForInspector");

  internal_settings_generated_v8_internal::SetForceTouchEventFeatureDetectionForInspectorMethod(info);
}

void V8InternalSettingsGenerated::SetForceZeroLayoutHeightMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setForceZeroLayoutHeight");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setForceZeroLayoutHeight");

  internal_settings_generated_v8_internal::SetForceZeroLayoutHeightMethod(info);
}

void V8InternalSettingsGenerated::SetFullscreenSupportedMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setFullscreenSupported");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setFullscreenSupported");

  internal_settings_generated_v8_internal::SetFullscreenSupportedMethod(info);
}

void V8InternalSettingsGenerated::SetHideDownloadUIMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setHideDownloadUI");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setHideDownloadUI");

  internal_settings_generated_v8_internal::SetHideDownloadUIMethod(info);
}

void V8InternalSettingsGenerated::SetHideScrollbarsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setHideScrollbars");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setHideScrollbars");

  internal_settings_generated_v8_internal::SetHideScrollbarsMethod(info);
}

void V8InternalSettingsGenerated::SetHyperlinkAuditingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setHyperlinkAuditingEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setHyperlinkAuditingEnabled");

  internal_settings_generated_v8_internal::SetHyperlinkAuditingEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetIgnoreMainFrameOverflowHiddenQuirkMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setIgnoreMainFrameOverflowHiddenQuirk");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setIgnoreMainFrameOverflowHiddenQuirk");

  internal_settings_generated_v8_internal::SetIgnoreMainFrameOverflowHiddenQuirkMethod(info);
}

void V8InternalSettingsGenerated::SetImagesEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setImagesEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setImagesEnabled");

  internal_settings_generated_v8_internal::SetImagesEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetImmersiveModeEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setImmersiveModeEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setImmersiveModeEnabled");

  internal_settings_generated_v8_internal::SetImmersiveModeEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetInlineTextBoxAccessibilityEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setInlineTextBoxAccessibilityEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setInlineTextBoxAccessibilityEnabled");

  internal_settings_generated_v8_internal::SetInlineTextBoxAccessibilityEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetJavaScriptCanAccessClipboardMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setJavaScriptCanAccessClipboard");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setJavaScriptCanAccessClipboard");

  internal_settings_generated_v8_internal::SetJavaScriptCanAccessClipboardMethod(info);
}

void V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPx2GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyFrameLoadingDistanceThresholdPx2G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyFrameLoadingDistanceThresholdPx2G");

  internal_settings_generated_v8_internal::SetLazyFrameLoadingDistanceThresholdPx2GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPx3GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyFrameLoadingDistanceThresholdPx3G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyFrameLoadingDistanceThresholdPx3G");

  internal_settings_generated_v8_internal::SetLazyFrameLoadingDistanceThresholdPx3GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPx4GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyFrameLoadingDistanceThresholdPx4G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyFrameLoadingDistanceThresholdPx4G");

  internal_settings_generated_v8_internal::SetLazyFrameLoadingDistanceThresholdPx4GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPxOfflineMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyFrameLoadingDistanceThresholdPxOffline");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyFrameLoadingDistanceThresholdPxOffline");

  internal_settings_generated_v8_internal::SetLazyFrameLoadingDistanceThresholdPxOfflineMethod(info);
}

void V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPxSlow2GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyFrameLoadingDistanceThresholdPxSlow2G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyFrameLoadingDistanceThresholdPxSlow2G");

  internal_settings_generated_v8_internal::SetLazyFrameLoadingDistanceThresholdPxSlow2GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPxUnknownMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyFrameLoadingDistanceThresholdPxUnknown");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyFrameLoadingDistanceThresholdPxUnknown");

  internal_settings_generated_v8_internal::SetLazyFrameLoadingDistanceThresholdPxUnknownMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoad2GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageFirstKFullyLoad2G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageFirstKFullyLoad2G");

  internal_settings_generated_v8_internal::SetLazyImageFirstKFullyLoad2GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoad3GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageFirstKFullyLoad3G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageFirstKFullyLoad3G");

  internal_settings_generated_v8_internal::SetLazyImageFirstKFullyLoad3GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoad4GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageFirstKFullyLoad4G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageFirstKFullyLoad4G");

  internal_settings_generated_v8_internal::SetLazyImageFirstKFullyLoad4GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoadSlow2GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageFirstKFullyLoadSlow2G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageFirstKFullyLoadSlow2G");

  internal_settings_generated_v8_internal::SetLazyImageFirstKFullyLoadSlow2GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoadUnknownMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageFirstKFullyLoadUnknown");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageFirstKFullyLoadUnknown");

  internal_settings_generated_v8_internal::SetLazyImageFirstKFullyLoadUnknownMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPx2GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageLoadingDistanceThresholdPx2G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageLoadingDistanceThresholdPx2G");

  internal_settings_generated_v8_internal::SetLazyImageLoadingDistanceThresholdPx2GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPx3GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageLoadingDistanceThresholdPx3G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageLoadingDistanceThresholdPx3G");

  internal_settings_generated_v8_internal::SetLazyImageLoadingDistanceThresholdPx3GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPx4GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageLoadingDistanceThresholdPx4G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageLoadingDistanceThresholdPx4G");

  internal_settings_generated_v8_internal::SetLazyImageLoadingDistanceThresholdPx4GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPxOfflineMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageLoadingDistanceThresholdPxOffline");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageLoadingDistanceThresholdPxOffline");

  internal_settings_generated_v8_internal::SetLazyImageLoadingDistanceThresholdPxOfflineMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPxSlow2GMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageLoadingDistanceThresholdPxSlow2G");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageLoadingDistanceThresholdPxSlow2G");

  internal_settings_generated_v8_internal::SetLazyImageLoadingDistanceThresholdPxSlow2GMethod(info);
}

void V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPxUnknownMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyImageLoadingDistanceThresholdPxUnknown");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyImageLoadingDistanceThresholdPxUnknown");

  internal_settings_generated_v8_internal::SetLazyImageLoadingDistanceThresholdPxUnknownMethod(info);
}

void V8InternalSettingsGenerated::SetLazyLoadEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLazyLoadEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLazyLoadEnabled");

  internal_settings_generated_v8_internal::SetLazyLoadEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetLoadWithOverviewModeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLoadWithOverviewMode");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLoadWithOverviewMode");

  internal_settings_generated_v8_internal::SetLoadWithOverviewModeMethod(info);
}

void V8InternalSettingsGenerated::SetLoadsImagesAutomaticallyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLoadsImagesAutomatically");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLoadsImagesAutomatically");

  internal_settings_generated_v8_internal::SetLoadsImagesAutomaticallyMethod(info);
}

void V8InternalSettingsGenerated::SetLocalStorageEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLocalStorageEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLocalStorageEnabled");

  internal_settings_generated_v8_internal::SetLocalStorageEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetLogDnsPrefetchAndPreconnectMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLogDnsPrefetchAndPreconnect");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLogDnsPrefetchAndPreconnect");

  internal_settings_generated_v8_internal::SetLogDnsPrefetchAndPreconnectMethod(info);
}

void V8InternalSettingsGenerated::SetLogPreloadMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setLogPreload");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setLogPreload");

  internal_settings_generated_v8_internal::SetLogPreloadMethod(info);
}

void V8InternalSettingsGenerated::SetMainFrameClipsContentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMainFrameClipsContent");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMainFrameClipsContent");

  internal_settings_generated_v8_internal::SetMainFrameClipsContentMethod(info);
}

void V8InternalSettingsGenerated::SetMainFrameResizesAreOrientationChangesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMainFrameResizesAreOrientationChanges");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMainFrameResizesAreOrientationChanges");

  internal_settings_generated_v8_internal::SetMainFrameResizesAreOrientationChangesMethod(info);
}

void V8InternalSettingsGenerated::SetMaxTouchPointsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMaxTouchPoints");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMaxTouchPoints");

  internal_settings_generated_v8_internal::SetMaxTouchPointsMethod(info);
}

void V8InternalSettingsGenerated::SetMediaControlsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMediaControlsEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMediaControlsEnabled");

  internal_settings_generated_v8_internal::SetMediaControlsEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetMediaTypeOverrideMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMediaTypeOverride");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMediaTypeOverride");

  internal_settings_generated_v8_internal::SetMediaTypeOverrideMethod(info);
}

void V8InternalSettingsGenerated::SetMinimumFontSizeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMinimumFontSize");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMinimumFontSize");

  internal_settings_generated_v8_internal::SetMinimumFontSizeMethod(info);
}

void V8InternalSettingsGenerated::SetMinimumLogicalFontSizeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMinimumLogicalFontSize");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMinimumLogicalFontSize");

  internal_settings_generated_v8_internal::SetMinimumLogicalFontSizeMethod(info);
}

void V8InternalSettingsGenerated::SetMockGestureTapHighlightsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMockGestureTapHighlightsEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMockGestureTapHighlightsEnabled");

  internal_settings_generated_v8_internal::SetMockGestureTapHighlightsEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetMultiTargetTapNotificationEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setMultiTargetTapNotificationEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setMultiTargetTapNotificationEnabled");

  internal_settings_generated_v8_internal::SetMultiTargetTapNotificationEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetNavigateOnDragDropMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setNavigateOnDragDrop");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setNavigateOnDragDrop");

  internal_settings_generated_v8_internal::SetNavigateOnDragDropMethod(info);
}

void V8InternalSettingsGenerated::SetNavigatorPlatformOverrideMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setNavigatorPlatformOverride");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setNavigatorPlatformOverride");

  internal_settings_generated_v8_internal::SetNavigatorPlatformOverrideMethod(info);
}

void V8InternalSettingsGenerated::SetOfflineWebApplicationCacheEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setOfflineWebApplicationCacheEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setOfflineWebApplicationCacheEnabled");

  internal_settings_generated_v8_internal::SetOfflineWebApplicationCacheEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetPasswordEchoDurationInSecondsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPasswordEchoDurationInSeconds");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPasswordEchoDurationInSeconds");

  internal_settings_generated_v8_internal::SetPasswordEchoDurationInSecondsMethod(info);
}

void V8InternalSettingsGenerated::SetPasswordEchoEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPasswordEchoEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPasswordEchoEnabled");

  internal_settings_generated_v8_internal::SetPasswordEchoEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetPictureInPictureEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPictureInPictureEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPictureInPictureEnabled");

  internal_settings_generated_v8_internal::SetPictureInPictureEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetPluginsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPluginsEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPluginsEnabled");

  internal_settings_generated_v8_internal::SetPluginsEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetPreferCompositingToLCDTextEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPreferCompositingToLCDTextEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPreferCompositingToLCDTextEnabled");

  internal_settings_generated_v8_internal::SetPreferCompositingToLCDTextEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetPreferHiddenVolumeControlsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPreferHiddenVolumeControls");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPreferHiddenVolumeControls");

  internal_settings_generated_v8_internal::SetPreferHiddenVolumeControlsMethod(info);
}

void V8InternalSettingsGenerated::SetPrefersReducedMotionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPrefersReducedMotion");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPrefersReducedMotion");

  internal_settings_generated_v8_internal::SetPrefersReducedMotionMethod(info);
}

void V8InternalSettingsGenerated::SetPresentationReceiverMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPresentationReceiver");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPresentationReceiver");

  internal_settings_generated_v8_internal::SetPresentationReceiverMethod(info);
}

void V8InternalSettingsGenerated::SetPresentationRequiresUserGestureMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setPresentationRequiresUserGesture");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setPresentationRequiresUserGesture");

  internal_settings_generated_v8_internal::SetPresentationRequiresUserGestureMethod(info);
}

void V8InternalSettingsGenerated::SetReportScreenSizeInPhysicalPixelsQuirkMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setReportScreenSizeInPhysicalPixelsQuirk");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setReportScreenSizeInPhysicalPixelsQuirk");

  internal_settings_generated_v8_internal::SetReportScreenSizeInPhysicalPixelsQuirkMethod(info);
}

void V8InternalSettingsGenerated::SetRubberBandingOnCompositorThreadMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setRubberBandingOnCompositorThread");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setRubberBandingOnCompositorThread");

  internal_settings_generated_v8_internal::SetRubberBandingOnCompositorThreadMethod(info);
}

void V8InternalSettingsGenerated::SetScriptEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setScriptEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setScriptEnabled");

  internal_settings_generated_v8_internal::SetScriptEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetScrollAnimatorEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setScrollAnimatorEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setScrollAnimatorEnabled");

  internal_settings_generated_v8_internal::SetScrollAnimatorEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetSelectTrailingWhitespaceEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSelectTrailingWhitespaceEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSelectTrailingWhitespaceEnabled");

  internal_settings_generated_v8_internal::SetSelectTrailingWhitespaceEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetSelectionIncludesAltImageTextMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSelectionIncludesAltImageText");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSelectionIncludesAltImageText");

  internal_settings_generated_v8_internal::SetSelectionIncludesAltImageTextMethod(info);
}

void V8InternalSettingsGenerated::SetShouldClearDocumentBackgroundMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setShouldClearDocumentBackground");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setShouldClearDocumentBackground");

  internal_settings_generated_v8_internal::SetShouldClearDocumentBackgroundMethod(info);
}

void V8InternalSettingsGenerated::SetShouldPrintBackgroundsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setShouldPrintBackgrounds");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setShouldPrintBackgrounds");

  internal_settings_generated_v8_internal::SetShouldPrintBackgroundsMethod(info);
}

void V8InternalSettingsGenerated::SetShouldProtectAgainstIpcFloodingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setShouldProtectAgainstIpcFlooding");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setShouldProtectAgainstIpcFlooding");

  internal_settings_generated_v8_internal::SetShouldProtectAgainstIpcFloodingMethod(info);
}

void V8InternalSettingsGenerated::SetShouldRespectImageOrientationMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setShouldRespectImageOrientation");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setShouldRespectImageOrientation");

  internal_settings_generated_v8_internal::SetShouldRespectImageOrientationMethod(info);
}

void V8InternalSettingsGenerated::SetShouldReuseGlobalForUnownedMainFrameMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setShouldReuseGlobalForUnownedMainFrame");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setShouldReuseGlobalForUnownedMainFrame");

  internal_settings_generated_v8_internal::SetShouldReuseGlobalForUnownedMainFrameMethod(info);
}

void V8InternalSettingsGenerated::SetShowContextMenuOnMouseUpMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setShowContextMenuOnMouseUp");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setShowContextMenuOnMouseUp");

  internal_settings_generated_v8_internal::SetShowContextMenuOnMouseUpMethod(info);
}

void V8InternalSettingsGenerated::SetShrinksViewportContentToFitMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setShrinksViewportContentToFit");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setShrinksViewportContentToFit");

  internal_settings_generated_v8_internal::SetShrinksViewportContentToFitMethod(info);
}

void V8InternalSettingsGenerated::SetSmartInsertDeleteEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSmartInsertDeleteEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSmartInsertDeleteEnabled");

  internal_settings_generated_v8_internal::SetSmartInsertDeleteEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetSmoothScrollForFindEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSmoothScrollForFindEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSmoothScrollForFindEnabled");

  internal_settings_generated_v8_internal::SetSmoothScrollForFindEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetSpatialNavigationEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSpatialNavigationEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSpatialNavigationEnabled");

  internal_settings_generated_v8_internal::SetSpatialNavigationEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetSpellCheckEnabledByDefaultMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSpellCheckEnabledByDefault");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSpellCheckEnabledByDefault");

  internal_settings_generated_v8_internal::SetSpellCheckEnabledByDefaultMethod(info);
}

void V8InternalSettingsGenerated::SetStrictMixedContentCheckingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setStrictMixedContentChecking");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setStrictMixedContentChecking");

  internal_settings_generated_v8_internal::SetStrictMixedContentCheckingMethod(info);
}

void V8InternalSettingsGenerated::SetStrictMixedContentCheckingForPluginMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setStrictMixedContentCheckingForPlugin");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setStrictMixedContentCheckingForPlugin");

  internal_settings_generated_v8_internal::SetStrictMixedContentCheckingForPluginMethod(info);
}

void V8InternalSettingsGenerated::SetStrictPowerfulFeatureRestrictionsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setStrictPowerfulFeatureRestrictions");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setStrictPowerfulFeatureRestrictions");

  internal_settings_generated_v8_internal::SetStrictPowerfulFeatureRestrictionsMethod(info);
}

void V8InternalSettingsGenerated::SetStrictlyBlockBlockableMixedContentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setStrictlyBlockBlockableMixedContent");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setStrictlyBlockBlockableMixedContent");

  internal_settings_generated_v8_internal::SetStrictlyBlockBlockableMixedContentMethod(info);
}

void V8InternalSettingsGenerated::SetSupportsMultipleWindowsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSupportsMultipleWindows");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSupportsMultipleWindows");

  internal_settings_generated_v8_internal::SetSupportsMultipleWindowsMethod(info);
}

void V8InternalSettingsGenerated::SetSyncXHRInDocumentsEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setSyncXHRInDocumentsEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setSyncXHRInDocumentsEnabled");

  internal_settings_generated_v8_internal::SetSyncXHRInDocumentsEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetTextAreasAreResizableMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextAreasAreResizable");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextAreasAreResizable");

  internal_settings_generated_v8_internal::SetTextAreasAreResizableMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackBackgroundColorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackBackgroundColor");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackBackgroundColor");

  internal_settings_generated_v8_internal::SetTextTrackBackgroundColorMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackFontFamilyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackFontFamily");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackFontFamily");

  internal_settings_generated_v8_internal::SetTextTrackFontFamilyMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackFontStyleMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackFontStyle");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackFontStyle");

  internal_settings_generated_v8_internal::SetTextTrackFontStyleMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackFontVariantMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackFontVariant");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackFontVariant");

  internal_settings_generated_v8_internal::SetTextTrackFontVariantMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackMarginPercentageMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackMarginPercentage");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackMarginPercentage");

  internal_settings_generated_v8_internal::SetTextTrackMarginPercentageMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackTextColorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackTextColor");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackTextColor");

  internal_settings_generated_v8_internal::SetTextTrackTextColorMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackTextShadowMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackTextShadow");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackTextShadow");

  internal_settings_generated_v8_internal::SetTextTrackTextShadowMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackTextSizeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackTextSize");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackTextSize");

  internal_settings_generated_v8_internal::SetTextTrackTextSizeMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackWindowColorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackWindowColor");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackWindowColor");

  internal_settings_generated_v8_internal::SetTextTrackWindowColorMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackWindowPaddingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackWindowPadding");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackWindowPadding");

  internal_settings_generated_v8_internal::SetTextTrackWindowPaddingMethod(info);
}

void V8InternalSettingsGenerated::SetTextTrackWindowRadiusMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTextTrackWindowRadius");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTextTrackWindowRadius");

  internal_settings_generated_v8_internal::SetTextTrackWindowRadiusMethod(info);
}

void V8InternalSettingsGenerated::SetThreadedScrollingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setThreadedScrollingEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setThreadedScrollingEnabled");

  internal_settings_generated_v8_internal::SetThreadedScrollingEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetTouchAdjustmentEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTouchAdjustmentEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTouchAdjustmentEnabled");

  internal_settings_generated_v8_internal::SetTouchAdjustmentEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetTouchDragDropEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTouchDragDropEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTouchDragDropEnabled");

  internal_settings_generated_v8_internal::SetTouchDragDropEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetTouchEditingEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setTouchEditingEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setTouchEditingEnabled");

  internal_settings_generated_v8_internal::SetTouchEditingEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetUseLegacyBackgroundSizeShorthandBehaviorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setUseLegacyBackgroundSizeShorthandBehavior");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setUseLegacyBackgroundSizeShorthandBehavior");

  internal_settings_generated_v8_internal::SetUseLegacyBackgroundSizeShorthandBehaviorMethod(info);
}

void V8InternalSettingsGenerated::SetUseWideViewportMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setUseWideViewport");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setUseWideViewport");

  internal_settings_generated_v8_internal::SetUseWideViewportMethod(info);
}

void V8InternalSettingsGenerated::SetValidationMessageTimerMagnificationMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setValidationMessageTimerMagnification");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setValidationMessageTimerMagnification");

  internal_settings_generated_v8_internal::SetValidationMessageTimerMagnificationMethod(info);
}

void V8InternalSettingsGenerated::SetViewportEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setViewportEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setViewportEnabled");

  internal_settings_generated_v8_internal::SetViewportEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetViewportMetaEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setViewportMetaEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setViewportMetaEnabled");

  internal_settings_generated_v8_internal::SetViewportMetaEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetViewportMetaMergeContentQuirkMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setViewportMetaMergeContentQuirk");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setViewportMetaMergeContentQuirk");

  internal_settings_generated_v8_internal::SetViewportMetaMergeContentQuirkMethod(info);
}

void V8InternalSettingsGenerated::SetViewportMetaZeroValuesQuirkMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setViewportMetaZeroValuesQuirk");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setViewportMetaZeroValuesQuirk");

  internal_settings_generated_v8_internal::SetViewportMetaZeroValuesQuirkMethod(info);
}

void V8InternalSettingsGenerated::SetWebAppScopeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setWebAppScope");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setWebAppScope");

  internal_settings_generated_v8_internal::SetWebAppScopeMethod(info);
}

void V8InternalSettingsGenerated::SetWebGL1EnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setWebGL1Enabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setWebGL1Enabled");

  internal_settings_generated_v8_internal::SetWebGL1EnabledMethod(info);
}

void V8InternalSettingsGenerated::SetWebGL2EnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setWebGL2Enabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setWebGL2Enabled");

  internal_settings_generated_v8_internal::SetWebGL2EnabledMethod(info);
}

void V8InternalSettingsGenerated::SetWebGLErrorsToConsoleEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setWebGLErrorsToConsoleEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setWebGLErrorsToConsoleEnabled");

  internal_settings_generated_v8_internal::SetWebGLErrorsToConsoleEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetWebSecurityEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setWebSecurityEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setWebSecurityEnabled");

  internal_settings_generated_v8_internal::SetWebSecurityEnabledMethod(info);
}

void V8InternalSettingsGenerated::SetWideViewportQuirkEnabledMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("InternalSettingsGenerated.setWideViewportQuirkEnabled");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_InternalSettingsGenerated_setWideViewportQuirkEnabled");

  internal_settings_generated_v8_internal::SetWideViewportQuirkEnabledMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8InternalSettingsGeneratedMethods[] = {
    {"setDOMPasteAllowed", V8InternalSettingsGenerated::SetDOMPasteAllowedMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDontSendKeyEventsToJavascript", V8InternalSettingsGenerated::SetDontSendKeyEventsToJavascriptMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setHighlightAds", V8InternalSettingsGenerated::SetHighlightAdsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setNetworkQuietTimeout", V8InternalSettingsGenerated::SetNetworkQuietTimeoutMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAccelerated2dCanvasMSAASampleCount", V8InternalSettingsGenerated::SetAccelerated2dCanvasMSAASampleCountMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAcceleratedCompositingEnabled", V8InternalSettingsGenerated::SetAcceleratedCompositingEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAccessibilityAlwaysShowFocus", V8InternalSettingsGenerated::SetAccessibilityAlwaysShowFocusMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAccessibilityFontScaleFactor", V8InternalSettingsGenerated::SetAccessibilityFontScaleFactorMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAccessibilityPasswordValuesEnabled", V8InternalSettingsGenerated::SetAccessibilityPasswordValuesEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAllowCustomScrollbarInMainFrame", V8InternalSettingsGenerated::SetAllowCustomScrollbarInMainFrameMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAllowFileAccessFromFileURLs", V8InternalSettingsGenerated::SetAllowFileAccessFromFileURLsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAllowGeolocationOnInsecureOrigins", V8InternalSettingsGenerated::SetAllowGeolocationOnInsecureOriginsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAllowRunningOfInsecureContent", V8InternalSettingsGenerated::SetAllowRunningOfInsecureContentMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAllowScriptsToCloseWindows", V8InternalSettingsGenerated::SetAllowScriptsToCloseWindowsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAllowUniversalAccessFromFileURLs", V8InternalSettingsGenerated::SetAllowUniversalAccessFromFileURLsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAlwaysShowContextMenuOnTouch", V8InternalSettingsGenerated::SetAlwaysShowContextMenuOnTouchMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAntialiased2dCanvasEnabled", V8InternalSettingsGenerated::SetAntialiased2dCanvasEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAntialiasedClips2dCanvasEnabled", V8InternalSettingsGenerated::SetAntialiasedClips2dCanvasEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAriaModalPrunesAXTree", V8InternalSettingsGenerated::SetAriaModalPrunesAXTreeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAvailableHoverTypes", V8InternalSettingsGenerated::SetAvailableHoverTypesMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setAvailablePointerTypes", V8InternalSettingsGenerated::SetAvailablePointerTypesMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setBarrelButtonForDragEnabled", V8InternalSettingsGenerated::SetBarrelButtonForDragEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setCaretBrowsingEnabled", V8InternalSettingsGenerated::SetCaretBrowsingEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setCookieEnabled", V8InternalSettingsGenerated::SetCookieEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDataSaverHoldbackWebApi", V8InternalSettingsGenerated::SetDataSaverHoldbackWebApiMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDefaultFixedFontSize", V8InternalSettingsGenerated::SetDefaultFixedFontSizeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDefaultFontSize", V8InternalSettingsGenerated::SetDefaultFontSizeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDefaultTextEncodingName", V8InternalSettingsGenerated::SetDefaultTextEncodingNameMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDefaultVideoPosterURL", V8InternalSettingsGenerated::SetDefaultVideoPosterURLMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDeviceScaleAdjustment", V8InternalSettingsGenerated::SetDeviceScaleAdjustmentMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDisableReadingFromCanvas", V8InternalSettingsGenerated::SetDisableReadingFromCanvasMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDisallowFetchForDocWrittenScriptsInMainFrame", V8InternalSettingsGenerated::SetDisallowFetchForDocWrittenScriptsInMainFrameMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G", V8InternalSettingsGenerated::SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections", V8InternalSettingsGenerated::SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnectionsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDNSPrefetchingEnabled", V8InternalSettingsGenerated::SetDNSPrefetchingEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDoHtmlPreloadScanning", V8InternalSettingsGenerated::SetDoHtmlPreloadScanningMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDoNotUpdateSelectionOnMutatingSelectionRange", V8InternalSettingsGenerated::SetDoNotUpdateSelectionOnMutatingSelectionRangeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setDownloadableBinaryFontsEnabled", V8InternalSettingsGenerated::SetDownloadableBinaryFontsEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setEmbeddedMediaExperienceEnabled", V8InternalSettingsGenerated::SetEmbeddedMediaExperienceEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceAndroidOverlayScrollbar", V8InternalSettingsGenerated::SetForceAndroidOverlayScrollbarMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceDarkModeBackgroundBrightnessThreshold", V8InternalSettingsGenerated::SetForceDarkModeBackgroundBrightnessThresholdMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceDarkModeContrast", V8InternalSettingsGenerated::SetForceDarkModeContrastMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceDarkModeEnabled", V8InternalSettingsGenerated::SetForceDarkModeEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceDarkModeGrayscale", V8InternalSettingsGenerated::SetForceDarkModeGrayscaleMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceDarkModeTextBrightnessThreshold", V8InternalSettingsGenerated::SetForceDarkModeTextBrightnessThresholdMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceMainWorldInitialization", V8InternalSettingsGenerated::SetForceMainWorldInitializationMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceTouchEventFeatureDetectionForInspector", V8InternalSettingsGenerated::SetForceTouchEventFeatureDetectionForInspectorMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setForceZeroLayoutHeight", V8InternalSettingsGenerated::SetForceZeroLayoutHeightMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setFullscreenSupported", V8InternalSettingsGenerated::SetFullscreenSupportedMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setHideDownloadUI", V8InternalSettingsGenerated::SetHideDownloadUIMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setHideScrollbars", V8InternalSettingsGenerated::SetHideScrollbarsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setHyperlinkAuditingEnabled", V8InternalSettingsGenerated::SetHyperlinkAuditingEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setIgnoreMainFrameOverflowHiddenQuirk", V8InternalSettingsGenerated::SetIgnoreMainFrameOverflowHiddenQuirkMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setImagesEnabled", V8InternalSettingsGenerated::SetImagesEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setImmersiveModeEnabled", V8InternalSettingsGenerated::SetImmersiveModeEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setInlineTextBoxAccessibilityEnabled", V8InternalSettingsGenerated::SetInlineTextBoxAccessibilityEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setJavaScriptCanAccessClipboard", V8InternalSettingsGenerated::SetJavaScriptCanAccessClipboardMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyFrameLoadingDistanceThresholdPx2G", V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPx2GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyFrameLoadingDistanceThresholdPx3G", V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPx3GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyFrameLoadingDistanceThresholdPx4G", V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPx4GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyFrameLoadingDistanceThresholdPxOffline", V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPxOfflineMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyFrameLoadingDistanceThresholdPxSlow2G", V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPxSlow2GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyFrameLoadingDistanceThresholdPxUnknown", V8InternalSettingsGenerated::SetLazyFrameLoadingDistanceThresholdPxUnknownMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageFirstKFullyLoad2G", V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoad2GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageFirstKFullyLoad3G", V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoad3GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageFirstKFullyLoad4G", V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoad4GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageFirstKFullyLoadSlow2G", V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoadSlow2GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageFirstKFullyLoadUnknown", V8InternalSettingsGenerated::SetLazyImageFirstKFullyLoadUnknownMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageLoadingDistanceThresholdPx2G", V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPx2GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageLoadingDistanceThresholdPx3G", V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPx3GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageLoadingDistanceThresholdPx4G", V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPx4GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageLoadingDistanceThresholdPxOffline", V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPxOfflineMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageLoadingDistanceThresholdPxSlow2G", V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPxSlow2GMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyImageLoadingDistanceThresholdPxUnknown", V8InternalSettingsGenerated::SetLazyImageLoadingDistanceThresholdPxUnknownMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLazyLoadEnabled", V8InternalSettingsGenerated::SetLazyLoadEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLoadWithOverviewMode", V8InternalSettingsGenerated::SetLoadWithOverviewModeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLoadsImagesAutomatically", V8InternalSettingsGenerated::SetLoadsImagesAutomaticallyMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLocalStorageEnabled", V8InternalSettingsGenerated::SetLocalStorageEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLogDnsPrefetchAndPreconnect", V8InternalSettingsGenerated::SetLogDnsPrefetchAndPreconnectMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setLogPreload", V8InternalSettingsGenerated::SetLogPreloadMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMainFrameClipsContent", V8InternalSettingsGenerated::SetMainFrameClipsContentMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMainFrameResizesAreOrientationChanges", V8InternalSettingsGenerated::SetMainFrameResizesAreOrientationChangesMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMaxTouchPoints", V8InternalSettingsGenerated::SetMaxTouchPointsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMediaControlsEnabled", V8InternalSettingsGenerated::SetMediaControlsEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMediaTypeOverride", V8InternalSettingsGenerated::SetMediaTypeOverrideMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMinimumFontSize", V8InternalSettingsGenerated::SetMinimumFontSizeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMinimumLogicalFontSize", V8InternalSettingsGenerated::SetMinimumLogicalFontSizeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMockGestureTapHighlightsEnabled", V8InternalSettingsGenerated::SetMockGestureTapHighlightsEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setMultiTargetTapNotificationEnabled", V8InternalSettingsGenerated::SetMultiTargetTapNotificationEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setNavigateOnDragDrop", V8InternalSettingsGenerated::SetNavigateOnDragDropMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setNavigatorPlatformOverride", V8InternalSettingsGenerated::SetNavigatorPlatformOverrideMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setOfflineWebApplicationCacheEnabled", V8InternalSettingsGenerated::SetOfflineWebApplicationCacheEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPasswordEchoDurationInSeconds", V8InternalSettingsGenerated::SetPasswordEchoDurationInSecondsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPasswordEchoEnabled", V8InternalSettingsGenerated::SetPasswordEchoEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPictureInPictureEnabled", V8InternalSettingsGenerated::SetPictureInPictureEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPluginsEnabled", V8InternalSettingsGenerated::SetPluginsEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPreferCompositingToLCDTextEnabled", V8InternalSettingsGenerated::SetPreferCompositingToLCDTextEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPreferHiddenVolumeControls", V8InternalSettingsGenerated::SetPreferHiddenVolumeControlsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPrefersReducedMotion", V8InternalSettingsGenerated::SetPrefersReducedMotionMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPresentationReceiver", V8InternalSettingsGenerated::SetPresentationReceiverMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setPresentationRequiresUserGesture", V8InternalSettingsGenerated::SetPresentationRequiresUserGestureMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setReportScreenSizeInPhysicalPixelsQuirk", V8InternalSettingsGenerated::SetReportScreenSizeInPhysicalPixelsQuirkMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setRubberBandingOnCompositorThread", V8InternalSettingsGenerated::SetRubberBandingOnCompositorThreadMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setScriptEnabled", V8InternalSettingsGenerated::SetScriptEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setScrollAnimatorEnabled", V8InternalSettingsGenerated::SetScrollAnimatorEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSelectTrailingWhitespaceEnabled", V8InternalSettingsGenerated::SetSelectTrailingWhitespaceEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSelectionIncludesAltImageText", V8InternalSettingsGenerated::SetSelectionIncludesAltImageTextMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setShouldClearDocumentBackground", V8InternalSettingsGenerated::SetShouldClearDocumentBackgroundMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setShouldPrintBackgrounds", V8InternalSettingsGenerated::SetShouldPrintBackgroundsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setShouldProtectAgainstIpcFlooding", V8InternalSettingsGenerated::SetShouldProtectAgainstIpcFloodingMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setShouldRespectImageOrientation", V8InternalSettingsGenerated::SetShouldRespectImageOrientationMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setShouldReuseGlobalForUnownedMainFrame", V8InternalSettingsGenerated::SetShouldReuseGlobalForUnownedMainFrameMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setShowContextMenuOnMouseUp", V8InternalSettingsGenerated::SetShowContextMenuOnMouseUpMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setShrinksViewportContentToFit", V8InternalSettingsGenerated::SetShrinksViewportContentToFitMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSmartInsertDeleteEnabled", V8InternalSettingsGenerated::SetSmartInsertDeleteEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSmoothScrollForFindEnabled", V8InternalSettingsGenerated::SetSmoothScrollForFindEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSpatialNavigationEnabled", V8InternalSettingsGenerated::SetSpatialNavigationEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSpellCheckEnabledByDefault", V8InternalSettingsGenerated::SetSpellCheckEnabledByDefaultMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setStrictMixedContentChecking", V8InternalSettingsGenerated::SetStrictMixedContentCheckingMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setStrictMixedContentCheckingForPlugin", V8InternalSettingsGenerated::SetStrictMixedContentCheckingForPluginMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setStrictPowerfulFeatureRestrictions", V8InternalSettingsGenerated::SetStrictPowerfulFeatureRestrictionsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setStrictlyBlockBlockableMixedContent", V8InternalSettingsGenerated::SetStrictlyBlockBlockableMixedContentMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSupportsMultipleWindows", V8InternalSettingsGenerated::SetSupportsMultipleWindowsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setSyncXHRInDocumentsEnabled", V8InternalSettingsGenerated::SetSyncXHRInDocumentsEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextAreasAreResizable", V8InternalSettingsGenerated::SetTextAreasAreResizableMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackBackgroundColor", V8InternalSettingsGenerated::SetTextTrackBackgroundColorMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackFontFamily", V8InternalSettingsGenerated::SetTextTrackFontFamilyMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackFontStyle", V8InternalSettingsGenerated::SetTextTrackFontStyleMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackFontVariant", V8InternalSettingsGenerated::SetTextTrackFontVariantMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackMarginPercentage", V8InternalSettingsGenerated::SetTextTrackMarginPercentageMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackTextColor", V8InternalSettingsGenerated::SetTextTrackTextColorMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackTextShadow", V8InternalSettingsGenerated::SetTextTrackTextShadowMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackTextSize", V8InternalSettingsGenerated::SetTextTrackTextSizeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackWindowColor", V8InternalSettingsGenerated::SetTextTrackWindowColorMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackWindowPadding", V8InternalSettingsGenerated::SetTextTrackWindowPaddingMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTextTrackWindowRadius", V8InternalSettingsGenerated::SetTextTrackWindowRadiusMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setThreadedScrollingEnabled", V8InternalSettingsGenerated::SetThreadedScrollingEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTouchAdjustmentEnabled", V8InternalSettingsGenerated::SetTouchAdjustmentEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTouchDragDropEnabled", V8InternalSettingsGenerated::SetTouchDragDropEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setTouchEditingEnabled", V8InternalSettingsGenerated::SetTouchEditingEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setUseLegacyBackgroundSizeShorthandBehavior", V8InternalSettingsGenerated::SetUseLegacyBackgroundSizeShorthandBehaviorMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setUseWideViewport", V8InternalSettingsGenerated::SetUseWideViewportMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setValidationMessageTimerMagnification", V8InternalSettingsGenerated::SetValidationMessageTimerMagnificationMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setViewportEnabled", V8InternalSettingsGenerated::SetViewportEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setViewportMetaEnabled", V8InternalSettingsGenerated::SetViewportMetaEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setViewportMetaMergeContentQuirk", V8InternalSettingsGenerated::SetViewportMetaMergeContentQuirkMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setViewportMetaZeroValuesQuirk", V8InternalSettingsGenerated::SetViewportMetaZeroValuesQuirkMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setWebAppScope", V8InternalSettingsGenerated::SetWebAppScopeMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setWebGL1Enabled", V8InternalSettingsGenerated::SetWebGL1EnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setWebGL2Enabled", V8InternalSettingsGenerated::SetWebGL2EnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setWebGLErrorsToConsoleEnabled", V8InternalSettingsGenerated::SetWebGLErrorsToConsoleEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setWebSecurityEnabled", V8InternalSettingsGenerated::SetWebSecurityEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setWideViewportQuirkEnabled", V8InternalSettingsGenerated::SetWideViewportQuirkEnabledMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8InternalSettingsGeneratedTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8InternalSettingsGenerated::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8InternalSettingsGenerated::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8InternalSettingsGeneratedMethods, base::size(kV8InternalSettingsGeneratedMethods));

  // Custom signature

  V8InternalSettingsGenerated::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8InternalSettingsGenerated::InstallRuntimeEnabledFeaturesOnTemplate(
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

v8::Local<v8::FunctionTemplate> V8InternalSettingsGenerated::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8InternalSettingsGenerated::GetWrapperTypeInfo()),
      InstallV8InternalSettingsGeneratedTemplate);
}

bool V8InternalSettingsGenerated::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8InternalSettingsGenerated::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8InternalSettingsGenerated::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8InternalSettingsGenerated::GetWrapperTypeInfo(), v8_value);
}

InternalSettingsGenerated* V8InternalSettingsGenerated::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
