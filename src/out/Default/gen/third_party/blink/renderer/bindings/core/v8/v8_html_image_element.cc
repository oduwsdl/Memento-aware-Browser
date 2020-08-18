// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_html_image_element.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_promise.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_constructor.h"
#include "third_party/blink/renderer/core/css/cssom/element_computed_style_map.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/web_feature.h"
#include "third_party/blink/renderer/core/fullscreen/element_fullscreen.h"
#include "third_party/blink/renderer/core/html/custom/ce_reactions_scope.h"
#include "third_party/blink/renderer/core/html/custom/v0_custom_element_processing_stack.h"
#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/core/keywords.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
#include "third_party/blink/renderer/platform/bindings/v8_private_property.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
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
const WrapperTypeInfo v8_html_image_element_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8HTMLImageElement::DomTemplate,
    nullptr,
    "HTMLImageElement",
    V8HTMLElement::GetWrapperTypeInfo(),
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kNodeClassId,
    WrapperTypeInfo::kInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in HTMLImageElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& HTMLImageElement::wrapper_type_info_ = v8_html_image_element_wrapper_type_info;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, HTMLImageElement>::value,
    "HTMLImageElement does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&HTMLImageElement::HasPendingActivity),
                  decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "HTMLImageElement is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace html_image_element_v8_internal {

static void AltAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->FastGetAttribute(html_names::kAltAttr), info.GetIsolate());
}

static void SrcAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->GetURLAttribute(html_names::kSrcAttr), info.GetIsolate());
}

static void SrcAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "HTMLImageElement", "src");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setAttribute(html_names::kSrcAttr, cpp_value);
}

static void SrcsetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->FastGetAttribute(html_names::kSrcsetAttr), info.GetIsolate());
}

static void SizesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->FastGetAttribute(html_names::kSizesAttr), info.GetIsolate());
}

static void CrossOriginAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  String cpp_value(impl->FastGetAttribute(html_names::kCrossoriginAttr));

  AtomicString atomic_cpp_value(cpp_value.LowerASCII());
  if (cpp_value.IsNull()) {
    ;
  } else if (cpp_value.IsEmpty()) {
    cpp_value = keywords::kAnonymous;
  } else if (atomic_cpp_value == keywords::kAnonymous) {
    cpp_value = keywords::kAnonymous;
  } else if (atomic_cpp_value == keywords::kUseCredentials) {
    cpp_value = keywords::kUseCredentials;
  } else {
    cpp_value = keywords::kAnonymous;
  }

  V8SetReturnValueStringOrNull(info, cpp_value, info.GetIsolate());
}

static void CrossOriginAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kCrossoriginAttr, cpp_value);
}

static void UseMapAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->FastGetAttribute(html_names::kUsemapAttr), info.GetIsolate());
}

static void IsMapAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueBool(info, impl->FastHasAttribute(html_names::kIsmapAttr));
}

static void WidthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->width());
}

static void WidthAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "HTMLImageElement", "width");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  uint32_t cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setWidth(cpp_value);
}

static void HeightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->height());
}

static void HeightAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "HTMLImageElement", "height");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  uint32_t cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setHeight(cpp_value);
}

static void NaturalWidthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->naturalWidth());
}

static void NaturalHeightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->naturalHeight());
}

static void CompleteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueBool(info, impl->complete());
}

static void CurrentSrcAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->currentSrc(), info.GetIsolate());
}

static void ReferrerPolicyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  String cpp_value(impl->FastGetAttribute(html_names::kReferrerpolicyAttr));

  AtomicString atomic_cpp_value(cpp_value.LowerASCII());
  if (cpp_value.IsEmpty()) {
    cpp_value = g_empty_atom;
  } else if (atomic_cpp_value == g_empty_atom) {
    cpp_value = g_empty_atom;
  } else if (atomic_cpp_value == keywords::kNoReferrer) {
    cpp_value = keywords::kNoReferrer;
  } else if (atomic_cpp_value == keywords::kOrigin) {
    cpp_value = keywords::kOrigin;
  } else if (atomic_cpp_value == keywords::kNoReferrerWhenDowngrade) {
    cpp_value = keywords::kNoReferrerWhenDowngrade;
  } else if (atomic_cpp_value == keywords::kOriginWhenCrossOrigin) {
    cpp_value = keywords::kOriginWhenCrossOrigin;
  } else if (atomic_cpp_value == keywords::kUnsafeUrl) {
    cpp_value = keywords::kUnsafeUrl;
  } else {
    cpp_value = g_empty_atom;
  }

  V8SetReturnValueString(info, cpp_value, info.GetIsolate());
}

static void ReferrerPolicyAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kReferrerpolicyAttr, cpp_value);
}

static void DecodingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  String cpp_value(impl->FastGetAttribute(html_names::kDecodingAttr));

  AtomicString atomic_cpp_value(cpp_value.LowerASCII());
  if (cpp_value.IsEmpty()) {
    cpp_value = keywords::kAuto;
  } else if (atomic_cpp_value == keywords::kAsync) {
    cpp_value = keywords::kAsync;
  } else if (atomic_cpp_value == keywords::kSync) {
    cpp_value = keywords::kSync;
  } else if (atomic_cpp_value == keywords::kAuto) {
    cpp_value = keywords::kAuto;
  } else {
    cpp_value = keywords::kAuto;
  }

  V8SetReturnValueString(info, cpp_value, info.GetIsolate());
}

static void DecodingAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kDecodingAttr, cpp_value);
}

static void ImportanceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  String cpp_value(impl->FastGetAttribute(html_names::kImportanceAttr));

  AtomicString atomic_cpp_value(cpp_value.LowerASCII());
  if (cpp_value.IsEmpty()) {
    cpp_value = keywords::kAuto;
  } else if (atomic_cpp_value == keywords::kLow) {
    cpp_value = keywords::kLow;
  } else if (atomic_cpp_value == keywords::kAuto) {
    cpp_value = keywords::kAuto;
  } else if (atomic_cpp_value == keywords::kHigh) {
    cpp_value = keywords::kHigh;
  } else {
    cpp_value = keywords::kAuto;
  }

  V8SetReturnValueString(info, cpp_value, info.GetIsolate());
}

static void ImportanceAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kImportanceAttr, cpp_value);
}

static void LoadingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  String cpp_value(impl->FastGetAttribute(html_names::kLoadingAttr));

  AtomicString atomic_cpp_value(cpp_value.LowerASCII());
  if (cpp_value.IsEmpty()) {
    cpp_value = keywords::kAuto;
  } else if (atomic_cpp_value == keywords::kLazy) {
    cpp_value = keywords::kLazy;
  } else if (atomic_cpp_value == keywords::kEager) {
    cpp_value = keywords::kEager;
  } else if (atomic_cpp_value == keywords::kAuto) {
    cpp_value = keywords::kAuto;
  } else {
    cpp_value = keywords::kAuto;
  }

  V8SetReturnValueString(info, cpp_value, info.GetIsolate());
}

static void LoadingAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kLoadingAttr, cpp_value);
}

static void NameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->GetNameAttribute(), info.GetIsolate());
}

static void LowsrcAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->GetURLAttribute(html_names::kLowsrcAttr), info.GetIsolate());
}

static void LowsrcAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kLowsrcAttr, cpp_value);
}

static void AlignAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->FastGetAttribute(html_names::kAlignAttr), info.GetIsolate());
}

static void HspaceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueUnsigned(info, std::max(0, static_cast<int>(impl->GetIntegralAttribute(html_names::kHspaceAttr))));
}

static void HspaceAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "HTMLImageElement", "hspace");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  uint32_t cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->SetUnsignedIntegralAttribute(html_names::kHspaceAttr, cpp_value);
}

static void VspaceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueUnsigned(info, std::max(0, static_cast<int>(impl->GetIntegralAttribute(html_names::kVspaceAttr))));
}

static void VspaceAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "HTMLImageElement", "vspace");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  uint32_t cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->SetUnsignedIntegralAttribute(html_names::kVspaceAttr, cpp_value);
}

static void LongDescAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->GetURLAttribute(html_names::kLongdescAttr), info.GetIsolate());
}

static void LongDescAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kLongdescAttr, cpp_value);
}

static void BorderAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->FastGetAttribute(html_names::kBorderAttr), info.GetIsolate());
}

static void BorderAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAsEmptyString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kBorderAttr, cpp_value);
}

static void XAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueInt(info, impl->x());
}

static void YAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(holder);

  V8SetReturnValueInt(info, impl->y());
}

static void DecodeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "HTMLImageElement", "decode");
  ExceptionToRejectPromiseScope reject_promise_scope(info, exception_state);

  // V8DOMConfiguration::kDoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8HTMLImageElement::HasInstance(info.Holder(), info.GetIsolate())) {
    exception_state.ThrowTypeError("Illegal invocation");
    return;
  }
  HTMLImageElement* impl = V8HTMLImageElement::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  ScriptPromise result = impl->decode(script_state, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result.V8Value());
}

CORE_EXPORT void ConstructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_Constructor");

  if (!info.IsConstructCall()) {
    V8ThrowException::ThrowTypeError(
        info.GetIsolate(),
        ExceptionMessages::ConstructorNotCallableAsFunction("HTMLImageElement"));
    return;
  }

  if (ConstructorMode::Current(info.GetIsolate()) == ConstructorMode::kWrapExistingObject) {
    V8SetReturnValue(info, info.Holder());
    return;
  }

  V8HTMLConstructor::HtmlConstructor(
      info, *V8HTMLImageElement::GetWrapperTypeInfo(), HTMLElementType::kHTMLImageElement);
}

}  // namespace html_image_element_v8_internal

void V8HTMLImageElement::AltAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_alt_Getter");

  html_image_element_v8_internal::AltAttributeGetter(info);
}

void V8HTMLImageElement::AltAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_alt_Setter");

  V8SetReflectedDOMStringAttribute(info, html_names::kAltAttr);
}

void V8HTMLImageElement::SrcAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_src_Getter");

  html_image_element_v8_internal::SrcAttributeGetter(info);
}

void V8HTMLImageElement::SrcAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_src_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::SrcAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::SrcsetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_srcset_Getter");

  html_image_element_v8_internal::SrcsetAttributeGetter(info);
}

void V8HTMLImageElement::SrcsetAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_srcset_Setter");

  V8SetReflectedDOMStringAttribute(info, html_names::kSrcsetAttr);
}

void V8HTMLImageElement::SizesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_sizes_Getter");

  html_image_element_v8_internal::SizesAttributeGetter(info);
}

void V8HTMLImageElement::SizesAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_sizes_Setter");

  V8SetReflectedDOMStringAttribute(info, html_names::kSizesAttr);
}

void V8HTMLImageElement::CrossOriginAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_crossOrigin_Getter");

  html_image_element_v8_internal::CrossOriginAttributeGetter(info);
}

void V8HTMLImageElement::CrossOriginAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_crossOrigin_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::CrossOriginAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::UseMapAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_useMap_Getter");

  html_image_element_v8_internal::UseMapAttributeGetter(info);
}

void V8HTMLImageElement::UseMapAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_useMap_Setter");

  V8SetReflectedDOMStringAttribute(info, html_names::kUsemapAttr);
}

void V8HTMLImageElement::IsMapAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_isMap_Getter");

  html_image_element_v8_internal::IsMapAttributeGetter(info);
}

void V8HTMLImageElement::IsMapAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_isMap_Setter");

  V8SetReflectedBooleanAttribute(info, "HTMLImageElement", "isMap", html_names::kIsmapAttr);
}

void V8HTMLImageElement::WidthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_width_Getter");

  html_image_element_v8_internal::WidthAttributeGetter(info);
}

void V8HTMLImageElement::WidthAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_width_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::WidthAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::HeightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_height_Getter");

  html_image_element_v8_internal::HeightAttributeGetter(info);
}

void V8HTMLImageElement::HeightAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_height_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::HeightAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::NaturalWidthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_naturalWidth_Getter");

  html_image_element_v8_internal::NaturalWidthAttributeGetter(info);
}

void V8HTMLImageElement::NaturalHeightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_naturalHeight_Getter");

  html_image_element_v8_internal::NaturalHeightAttributeGetter(info);
}

void V8HTMLImageElement::CompleteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_complete_Getter");

  html_image_element_v8_internal::CompleteAttributeGetter(info);
}

void V8HTMLImageElement::CurrentSrcAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_currentSrc_Getter");

  html_image_element_v8_internal::CurrentSrcAttributeGetter(info);
}

void V8HTMLImageElement::ReferrerPolicyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_referrerPolicy_Getter");

  html_image_element_v8_internal::ReferrerPolicyAttributeGetter(info);
}

void V8HTMLImageElement::ReferrerPolicyAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_referrerPolicy_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::ReferrerPolicyAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::DecodingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_decoding_Getter");

  html_image_element_v8_internal::DecodingAttributeGetter(info);
}

void V8HTMLImageElement::DecodingAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_decoding_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::DecodingAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::ImportanceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_importance_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kPriorityHints);

  html_image_element_v8_internal::ImportanceAttributeGetter(info);
}

void V8HTMLImageElement::ImportanceAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_importance_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  UseCounter::Count(CurrentExecutionContext(info.GetIsolate()), WebFeature::kPriorityHints);

  html_image_element_v8_internal::ImportanceAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::LoadingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_loading_Getter");

  html_image_element_v8_internal::LoadingAttributeGetter(info);
}

void V8HTMLImageElement::LoadingAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_loading_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::LoadingAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::NameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_name_Getter");

  html_image_element_v8_internal::NameAttributeGetter(info);
}

void V8HTMLImageElement::NameAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_name_Setter");

  V8SetReflectedDOMStringAttribute(info, html_names::kNameAttr);
}

void V8HTMLImageElement::LowsrcAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_lowsrc_Getter");

  html_image_element_v8_internal::LowsrcAttributeGetter(info);
}

void V8HTMLImageElement::LowsrcAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_lowsrc_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::LowsrcAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::AlignAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_align_Getter");

  html_image_element_v8_internal::AlignAttributeGetter(info);
}

void V8HTMLImageElement::AlignAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_align_Setter");

  V8SetReflectedDOMStringAttribute(info, html_names::kAlignAttr);
}

void V8HTMLImageElement::HspaceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_hspace_Getter");

  html_image_element_v8_internal::HspaceAttributeGetter(info);
}

void V8HTMLImageElement::HspaceAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_hspace_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::HspaceAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::VspaceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_vspace_Getter");

  html_image_element_v8_internal::VspaceAttributeGetter(info);
}

void V8HTMLImageElement::VspaceAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_vspace_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::VspaceAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::LongDescAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_longDesc_Getter");

  html_image_element_v8_internal::LongDescAttributeGetter(info);
}

void V8HTMLImageElement::LongDescAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_longDesc_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::LongDescAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::BorderAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_border_Getter");

  html_image_element_v8_internal::BorderAttributeGetter(info);
}

void V8HTMLImageElement::BorderAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_border_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  html_image_element_v8_internal::BorderAttributeSetter(v8_value, info);
}

void V8HTMLImageElement::XAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_x_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kHTMLImageElementX);

  html_image_element_v8_internal::XAttributeGetter(info);
}

void V8HTMLImageElement::YAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_y_Getter");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kHTMLImageElementY);

  html_image_element_v8_internal::YAttributeGetter(info);
}

void V8HTMLImageElement::DecodeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("HTMLImageElement.decode");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_decode");

  html_image_element_v8_internal::DecodeMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8HTMLImageElementMethods[] = {
    {"decode", V8HTMLImageElement::DecodeMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kDoNotCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo v8_html_image_element_constructor_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8HTMLImageElementConstructor::DomTemplate,
    nullptr,
    "HTMLImageElement",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kNodeClassId,
    WrapperTypeInfo::kInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

static void V8HTMLImageElementConstructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_HTMLImageElement_ConstructorCallback");

  if (!info.IsConstructCall()) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::ConstructorNotCallableAsFunction("Image"));
    return;
  }

  if (ConstructorMode::Current(info.GetIsolate()) == ConstructorMode::kWrapExistingObject) {
    V8SetReturnValue(info, info.Holder());
    return;
  }

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kConstructionContext, "HTMLImageElement");

  uint32_t width;
  uint32_t height;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  if (UNLIKELY(num_args_passed <= 0)) {
    Document& document = *ToLocalDOMWindow(
        info.NewTarget().As<v8::Object>()->CreationContext())->document();
    HTMLImageElement* impl = HTMLImageElement::CreateForJSConstructor(document);
    v8::Local<v8::Object> wrapper = info.Holder();
    wrapper = impl->AssociateWithWrapper(info.GetIsolate(), V8HTMLImageElementConstructor::GetWrapperTypeInfo(), wrapper);
    V8SetReturnValue(info, wrapper);
    return;
  }
  width = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  if (UNLIKELY(num_args_passed <= 1)) {
    Document& document = *ToLocalDOMWindow(
        info.NewTarget().As<v8::Object>()->CreationContext())->document();
    HTMLImageElement* impl = HTMLImageElement::CreateForJSConstructor(document, width);
    v8::Local<v8::Object> wrapper = info.Holder();
    wrapper = impl->AssociateWithWrapper(info.GetIsolate(), V8HTMLImageElementConstructor::GetWrapperTypeInfo(), wrapper);
    V8SetReturnValue(info, wrapper);
    return;
  }
  height = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  Document& document = *ToLocalDOMWindow(
      info.NewTarget().As<v8::Object>()->CreationContext())->document();
  HTMLImageElement* impl = HTMLImageElement::CreateForJSConstructor(document, width, height);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->AssociateWithWrapper(info.GetIsolate(), V8HTMLImageElementConstructor::GetWrapperTypeInfo(), wrapper);
  V8SetReturnValue(info, wrapper);
}

v8::Local<v8::FunctionTemplate> V8HTMLImageElementConstructor::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  static int dom_template_key; // This address is used for a key to look up the dom template.
  V8PerIsolateData* data = V8PerIsolateData::From(isolate);
  v8::Local<v8::FunctionTemplate> result =
      data->FindInterfaceTemplate(world, &dom_template_key);
  if (!result.IsEmpty())
    return result;

  result = v8::FunctionTemplate::New(isolate, V8HTMLImageElementConstructorCallback);
  v8::Local<v8::ObjectTemplate> instance_template = result->InstanceTemplate();
  instance_template->SetInternalFieldCount(V8HTMLImageElement::kInternalFieldCount);
  result->SetClassName(V8AtomicString(isolate, "Image"));
  result->Inherit(V8HTMLImageElement::DomTemplate(isolate, world));
  data->SetInterfaceTemplate(world, &dom_template_key, result);
  return result;
}

void V8HTMLImageElementConstructor::NamedConstructorAttributeGetter(
    v8::Local<v8::Name> property_name,
    const v8::PropertyCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Context> creationContext = info.Holder()->CreationContext();
  V8PerContextData* per_context_data = V8PerContextData::From(creationContext);
  if (!per_context_data) {
    // TODO(yukishiino): Return a valid named constructor even after the context is detached
    return;
  }

  v8::Local<v8::Function> named_constructor =
      per_context_data->ConstructorForType(V8HTMLImageElementConstructor::GetWrapperTypeInfo());

  // Set the prototype of named constructors to the regular constructor.
  static const V8PrivateProperty::SymbolKey kPrivatePropertyInitialized;
  auto private_property =
      V8PrivateProperty::GetSymbol(
          info.GetIsolate(), kPrivatePropertyInitialized);
  v8::Local<v8::Context> current_context = info.GetIsolate()->GetCurrentContext();
  v8::Local<v8::Value> private_value;

  if (!private_property.GetOrUndefined(named_constructor).ToLocal(&private_value) ||
      private_value->IsUndefined()) {
    v8::Local<v8::Function> interface =
        per_context_data->ConstructorForType(V8HTMLImageElement::GetWrapperTypeInfo());
    v8::Local<v8::Value> interface_prototype =
        interface->Get(current_context, V8AtomicString(info.GetIsolate(), "prototype"))
        .ToLocalChecked();
    // https://heycam.github.io/webidl/#named-constructors
    // 8. Perform ! DefinePropertyOrThrow(F, "prototype",
    //        PropertyDescriptor{[[Value]]: proto, [[Writable]]: false,
    //                           [[Enumerable]]: false,
    //                           [Configurable]]: false}).
    const v8::PropertyAttribute prototype_attributes =
        static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontEnum | v8::DontDelete);
    bool result = named_constructor->DefineOwnProperty(
        current_context, V8AtomicString(info.GetIsolate(), "prototype"),
        interface_prototype, prototype_attributes).ToChecked();
    CHECK(result);
    private_property.Set(named_constructor, v8::True(info.GetIsolate()));
  }

  V8SetReturnValue(info, named_constructor);
}

static void InstallV8HTMLImageElementTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8HTMLImageElement::GetWrapperTypeInfo()->interface_name, V8HTMLElement::DomTemplate(isolate, world), V8HTMLImageElement::kInternalFieldCount);
  interface_template->SetCallHandler(html_image_element_v8_internal::ConstructorCallback);
  interface_template->SetLength(0);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "alt", V8HTMLImageElement::AltAttributeGetterCallback, V8HTMLImageElement::AltAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "src", V8HTMLImageElement::SrcAttributeGetterCallback, V8HTMLImageElement::SrcAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "srcset", V8HTMLImageElement::SrcsetAttributeGetterCallback, V8HTMLImageElement::SrcsetAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "sizes", V8HTMLImageElement::SizesAttributeGetterCallback, V8HTMLImageElement::SizesAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "crossOrigin", V8HTMLImageElement::CrossOriginAttributeGetterCallback, V8HTMLImageElement::CrossOriginAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "useMap", V8HTMLImageElement::UseMapAttributeGetterCallback, V8HTMLImageElement::UseMapAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "isMap", V8HTMLImageElement::IsMapAttributeGetterCallback, V8HTMLImageElement::IsMapAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "width", V8HTMLImageElement::WidthAttributeGetterCallback, V8HTMLImageElement::WidthAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "height", V8HTMLImageElement::HeightAttributeGetterCallback, V8HTMLImageElement::HeightAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "naturalWidth", V8HTMLImageElement::NaturalWidthAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "naturalHeight", V8HTMLImageElement::NaturalHeightAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "complete", V8HTMLImageElement::CompleteAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "currentSrc", V8HTMLImageElement::CurrentSrcAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "referrerPolicy", V8HTMLImageElement::ReferrerPolicyAttributeGetterCallback, V8HTMLImageElement::ReferrerPolicyAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "decoding", V8HTMLImageElement::DecodingAttributeGetterCallback, V8HTMLImageElement::DecodingAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "name", V8HTMLImageElement::NameAttributeGetterCallback, V8HTMLImageElement::NameAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "lowsrc", V8HTMLImageElement::LowsrcAttributeGetterCallback, V8HTMLImageElement::LowsrcAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "align", V8HTMLImageElement::AlignAttributeGetterCallback, V8HTMLImageElement::AlignAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "hspace", V8HTMLImageElement::HspaceAttributeGetterCallback, V8HTMLImageElement::HspaceAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "vspace", V8HTMLImageElement::VspaceAttributeGetterCallback, V8HTMLImageElement::VspaceAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "longDesc", V8HTMLImageElement::LongDescAttributeGetterCallback, V8HTMLImageElement::LongDescAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "border", V8HTMLImageElement::BorderAttributeGetterCallback, V8HTMLImageElement::BorderAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "x", V8HTMLImageElement::XAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "y", V8HTMLImageElement::YAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8HTMLImageElementMethods, base::size(kV8HTMLImageElementMethods));

  // Custom signature

  V8HTMLImageElement::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8HTMLImageElement::InstallRuntimeEnabledFeaturesOnTemplate(
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

  if (RuntimeEnabledFeatures::LazyImageLoadingEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "loading", V8HTMLImageElement::LoadingAttributeGetterCallback, V8HTMLImageElement::LoadingAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }

  // Custom signature
}

void V8HTMLImageElement::InstallPriorityHints(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance,
    v8::Local<v8::Object> prototype,
    v8::Local<v8::Function> interface) {
  v8::Local<v8::FunctionTemplate> interface_template =
      V8HTMLImageElement::GetWrapperTypeInfo()->DomTemplate(isolate, world);
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "importance", V8HTMLImageElement::ImportanceAttributeGetterCallback, V8HTMLImageElement::ImportanceAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance, prototype, interface,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
}

void V8HTMLImageElement::InstallPriorityHints(
    ScriptState* script_state, v8::Local<v8::Object> instance) {
  V8PerContextData* per_context_data = script_state->PerContextData();
  v8::Local<v8::Object> prototype = per_context_data->PrototypeForType(
      V8HTMLImageElement::GetWrapperTypeInfo());
  v8::Local<v8::Function> interface = per_context_data->ConstructorForType(
      V8HTMLImageElement::GetWrapperTypeInfo());
  ALLOW_UNUSED_LOCAL(interface);
  InstallPriorityHints(script_state->GetIsolate(), script_state->World(), instance, prototype, interface);
}

void V8HTMLImageElement::InstallPriorityHints(ScriptState* script_state) {
  InstallPriorityHints(script_state, v8::Local<v8::Object>());
}

v8::Local<v8::FunctionTemplate> V8HTMLImageElement::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8HTMLImageElement::GetWrapperTypeInfo()),
      InstallV8HTMLImageElementTemplate);
}

bool V8HTMLImageElement::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8HTMLImageElement::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8HTMLImageElement::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8HTMLImageElement::GetWrapperTypeInfo(), v8_value);
}

HTMLImageElement* V8HTMLImageElement::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
