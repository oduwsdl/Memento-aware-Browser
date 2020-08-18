// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_element_internals.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_token_list.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_file.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_form_data.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_form_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_node_list.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_validity_state.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_validity_state_flags.h"
#include "third_party/blink/renderer/core/dom/name_node_list.h"
#include "third_party/blink/renderer/core/dom/node_list.h"
#include "third_party/blink/renderer/core/dom/static_node_list.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/html/custom/ce_reactions_scope.h"
#include "third_party/blink/renderer/core/html/custom/v0_custom_element_processing_stack.h"
#include "third_party/blink/renderer/core/html/forms/labels_node_list.h"
#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/bindings/v8_private_property.h"
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
const WrapperTypeInfo v8_element_internals_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8ElementInternals::DomTemplate,
    nullptr,
    "ElementInternals",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in ElementInternals.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& ElementInternals::wrapper_type_info_ = v8_element_internals_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, ElementInternals>::value,
    "ElementInternals inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&ElementInternals::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "ElementInternals is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace element_internals_v8_internal {

static void FormAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kGetterContext, "ElementInternals", "form");

  HTMLFormElement* cpp_value(impl->form(exception_state));

  if (UNLIKELY(exception_state.HadException()))
    return;

  V8SetReturnValueFast(info, cpp_value, impl);
}

static void WillValidateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kGetterContext, "ElementInternals", "willValidate");

  bool cpp_value(impl->willValidate(exception_state));

  if (UNLIKELY(exception_state.HadException()))
    return;

  V8SetReturnValueBool(info, cpp_value);
}

static void ValidityAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kGetterContext, "ElementInternals", "validity");

  ValidityState* cpp_value(impl->validity(exception_state));

  if (UNLIKELY(exception_state.HadException()))
    return;

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void ValidationMessageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kGetterContext, "ElementInternals", "validationMessage");

  String cpp_value(impl->ValidationMessageForBinding(exception_state));

  if (UNLIKELY(exception_state.HadException()))
    return;

  V8SetReturnValueString(info, cpp_value, info.GetIsolate());
}

static void LabelsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kGetterContext, "ElementInternals", "labels");

  NodeList* cpp_value(impl->labels(exception_state));

  if (UNLIKELY(exception_state.HadException()))
    return;

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void StatesAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  DOMTokenList* cpp_value(WTF::GetPtr(impl->states()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void RoleAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kRoleAttr), info.GetIsolate());
}

static void RoleAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kRoleAttr, cpp_value);
}

static void AriaAtomicAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaAtomicAttr), info.GetIsolate());
}

static void AriaAtomicAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaAtomicAttr, cpp_value);
}

static void AriaAutoCompleteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaAutocompleteAttr), info.GetIsolate());
}

static void AriaAutoCompleteAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaAutocompleteAttr, cpp_value);
}

static void AriaBusyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaBusyAttr), info.GetIsolate());
}

static void AriaBusyAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaBusyAttr, cpp_value);
}

static void AriaCheckedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaCheckedAttr), info.GetIsolate());
}

static void AriaCheckedAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaCheckedAttr, cpp_value);
}

static void AriaColCountAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaColcountAttr), info.GetIsolate());
}

static void AriaColCountAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaColcountAttr, cpp_value);
}

static void AriaColIndexAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaColindexAttr), info.GetIsolate());
}

static void AriaColIndexAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaColindexAttr, cpp_value);
}

static void AriaColSpanAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaColspanAttr), info.GetIsolate());
}

static void AriaColSpanAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaColspanAttr, cpp_value);
}

static void AriaCurrentAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaCurrentAttr), info.GetIsolate());
}

static void AriaCurrentAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaCurrentAttr, cpp_value);
}

static void AriaDescriptionAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaDescriptionAttr), info.GetIsolate());
}

static void AriaDescriptionAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaDescriptionAttr, cpp_value);
}

static void AriaDisabledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaDisabledAttr), info.GetIsolate());
}

static void AriaDisabledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaDisabledAttr, cpp_value);
}

static void AriaExpandedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaExpandedAttr), info.GetIsolate());
}

static void AriaExpandedAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaExpandedAttr, cpp_value);
}

static void AriaHasPopupAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaHaspopupAttr), info.GetIsolate());
}

static void AriaHasPopupAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaHaspopupAttr, cpp_value);
}

static void AriaHiddenAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaHiddenAttr), info.GetIsolate());
}

static void AriaHiddenAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaHiddenAttr, cpp_value);
}

static void AriaKeyShortcutsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaKeyshortcutsAttr), info.GetIsolate());
}

static void AriaKeyShortcutsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaKeyshortcutsAttr, cpp_value);
}

static void AriaLabelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaLabelAttr), info.GetIsolate());
}

static void AriaLabelAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaLabelAttr, cpp_value);
}

static void AriaLevelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaLevelAttr), info.GetIsolate());
}

static void AriaLevelAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaLevelAttr, cpp_value);
}

static void AriaLiveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaLiveAttr), info.GetIsolate());
}

static void AriaLiveAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaLiveAttr, cpp_value);
}

static void AriaModalAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaModalAttr), info.GetIsolate());
}

static void AriaModalAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaModalAttr, cpp_value);
}

static void AriaMultiLineAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaMultilineAttr), info.GetIsolate());
}

static void AriaMultiLineAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaMultilineAttr, cpp_value);
}

static void AriaMultiSelectableAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaMultiselectableAttr), info.GetIsolate());
}

static void AriaMultiSelectableAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaMultiselectableAttr, cpp_value);
}

static void AriaOrientationAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaOrientationAttr), info.GetIsolate());
}

static void AriaOrientationAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaOrientationAttr, cpp_value);
}

static void AriaPlaceholderAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaPlaceholderAttr), info.GetIsolate());
}

static void AriaPlaceholderAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaPlaceholderAttr, cpp_value);
}

static void AriaPosInSetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaPosinsetAttr), info.GetIsolate());
}

static void AriaPosInSetAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaPosinsetAttr, cpp_value);
}

static void AriaPressedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaPressedAttr), info.GetIsolate());
}

static void AriaPressedAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaPressedAttr, cpp_value);
}

static void AriaReadOnlyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaReadonlyAttr), info.GetIsolate());
}

static void AriaReadOnlyAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaReadonlyAttr, cpp_value);
}

static void AriaRelevantAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaRelevantAttr), info.GetIsolate());
}

static void AriaRelevantAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaRelevantAttr, cpp_value);
}

static void AriaRequiredAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaRequiredAttr), info.GetIsolate());
}

static void AriaRequiredAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaRequiredAttr, cpp_value);
}

static void AriaRoleDescriptionAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaRoledescriptionAttr), info.GetIsolate());
}

static void AriaRoleDescriptionAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaRoledescriptionAttr, cpp_value);
}

static void AriaRowCountAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaRowcountAttr), info.GetIsolate());
}

static void AriaRowCountAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaRowcountAttr, cpp_value);
}

static void AriaRowIndexAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaRowindexAttr), info.GetIsolate());
}

static void AriaRowIndexAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaRowindexAttr, cpp_value);
}

static void AriaRowSpanAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaRowspanAttr), info.GetIsolate());
}

static void AriaRowSpanAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaRowspanAttr, cpp_value);
}

static void AriaSelectedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaSelectedAttr), info.GetIsolate());
}

static void AriaSelectedAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaSelectedAttr, cpp_value);
}

static void AriaSetSizeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaSetsizeAttr), info.GetIsolate());
}

static void AriaSetSizeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaSetsizeAttr, cpp_value);
}

static void AriaSortAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaSortAttr), info.GetIsolate());
}

static void AriaSortAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaSortAttr, cpp_value);
}

static void AriaValueMaxAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaValuemaxAttr), info.GetIsolate());
}

static void AriaValueMaxAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaValuemaxAttr, cpp_value);
}

static void AriaValueMinAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaValueminAttr), info.GetIsolate());
}

static void AriaValueMinAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaValueminAttr, cpp_value);
}

static void AriaValueNowAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaValuenowAttr), info.GetIsolate());
}

static void AriaValueNowAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaValuenowAttr, cpp_value);
}

static void AriaValueTextAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueStringOrNull(info, impl->FastGetAttribute(html_names::kAriaValuetextAttr), info.GetIsolate());
}

static void AriaValueTextAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<kTreatNullAndUndefinedAsNullString> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setAttribute(html_names::kAriaValuetextAttr, cpp_value);
}

static void AriaActiveDescendantElementAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueFast(info, impl->GetElementAttribute(html_names::kAriaActivedescendantAttr), impl);
}

static void AriaActiveDescendantElementAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaActiveDescendantElement");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  Element* cpp_value = V8Element::ToImplWithTypeCheck(info.GetIsolate(), v8_value);

  // Type check per: http://heycam.github.io/webidl/#es-interface
  if (!cpp_value && !IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("The provided value is not of type 'Element'.");
    return;
  }

  impl->SetElementAttribute(html_names::kAriaActivedescendantAttr, cpp_value);
}

static void AriaControlsElementsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  base::Optional<HeapVector<Member<Element>>> cpp_value(impl->GetElementArrayAttribute(html_names::kAriaControlsAttr));

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, FreezeV8Object(ToV8(cpp_value.value(), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void AriaControlsElementsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaControlsElements");
  CEReactionsScope ce_reactions_scope;

  bool is_null = IsUndefinedOrNull(v8_value);

  // Prepare the value to be set.
  base::Optional<HeapVector<Member<Element>>> cpp_value = is_null ? base::nullopt : base::Optional<HeapVector<Member<Element>>>(NativeValueTraits<IDLSequence<Element>>::NativeValue(info.GetIsolate(), v8_value, exception_state));
  if (exception_state.HadException())
    return;

  impl->SetElementArrayAttribute(html_names::kAriaControlsAttr, cpp_value);
}

static void AriaDescribedByElementsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  base::Optional<HeapVector<Member<Element>>> cpp_value(impl->GetElementArrayAttribute(html_names::kAriaDescribedbyAttr));

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, FreezeV8Object(ToV8(cpp_value.value(), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void AriaDescribedByElementsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaDescribedByElements");
  CEReactionsScope ce_reactions_scope;

  bool is_null = IsUndefinedOrNull(v8_value);

  // Prepare the value to be set.
  base::Optional<HeapVector<Member<Element>>> cpp_value = is_null ? base::nullopt : base::Optional<HeapVector<Member<Element>>>(NativeValueTraits<IDLSequence<Element>>::NativeValue(info.GetIsolate(), v8_value, exception_state));
  if (exception_state.HadException())
    return;

  impl->SetElementArrayAttribute(html_names::kAriaDescribedbyAttr, cpp_value);
}

static void AriaDetailsElementsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  base::Optional<HeapVector<Member<Element>>> cpp_value(impl->GetElementArrayAttribute(html_names::kAriaDetailsAttr));

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, FreezeV8Object(ToV8(cpp_value.value(), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void AriaDetailsElementsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaDetailsElements");
  CEReactionsScope ce_reactions_scope;

  bool is_null = IsUndefinedOrNull(v8_value);

  // Prepare the value to be set.
  base::Optional<HeapVector<Member<Element>>> cpp_value = is_null ? base::nullopt : base::Optional<HeapVector<Member<Element>>>(NativeValueTraits<IDLSequence<Element>>::NativeValue(info.GetIsolate(), v8_value, exception_state));
  if (exception_state.HadException())
    return;

  impl->SetElementArrayAttribute(html_names::kAriaDetailsAttr, cpp_value);
}

static void AriaErrorMessageElementAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V8SetReturnValueFast(info, impl->GetElementAttribute(html_names::kAriaErrormessageAttr), impl);
}

static void AriaErrorMessageElementAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaErrorMessageElement");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  Element* cpp_value = V8Element::ToImplWithTypeCheck(info.GetIsolate(), v8_value);

  // Type check per: http://heycam.github.io/webidl/#es-interface
  if (!cpp_value && !IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("The provided value is not of type 'Element'.");
    return;
  }

  impl->SetElementAttribute(html_names::kAriaErrormessageAttr, cpp_value);
}

static void AriaFlowToElementsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  base::Optional<HeapVector<Member<Element>>> cpp_value(impl->GetElementArrayAttribute(html_names::kAriaFlowtoAttr));

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, FreezeV8Object(ToV8(cpp_value.value(), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void AriaFlowToElementsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaFlowToElements");
  CEReactionsScope ce_reactions_scope;

  bool is_null = IsUndefinedOrNull(v8_value);

  // Prepare the value to be set.
  base::Optional<HeapVector<Member<Element>>> cpp_value = is_null ? base::nullopt : base::Optional<HeapVector<Member<Element>>>(NativeValueTraits<IDLSequence<Element>>::NativeValue(info.GetIsolate(), v8_value, exception_state));
  if (exception_state.HadException())
    return;

  impl->SetElementArrayAttribute(html_names::kAriaFlowtoAttr, cpp_value);
}

static void AriaLabelledByElementsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  base::Optional<HeapVector<Member<Element>>> cpp_value(impl->GetElementArrayAttribute(html_names::kAriaLabelledbyAttr));

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, FreezeV8Object(ToV8(cpp_value.value(), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void AriaLabelledByElementsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaLabelledByElements");
  CEReactionsScope ce_reactions_scope;

  bool is_null = IsUndefinedOrNull(v8_value);

  // Prepare the value to be set.
  base::Optional<HeapVector<Member<Element>>> cpp_value = is_null ? base::nullopt : base::Optional<HeapVector<Member<Element>>>(NativeValueTraits<IDLSequence<Element>>::NativeValue(info.GetIsolate(), v8_value, exception_state));
  if (exception_state.HadException())
    return;

  impl->SetElementArrayAttribute(html_names::kAriaLabelledbyAttr, cpp_value);
}

static void AriaOwnsElementsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  base::Optional<HeapVector<Member<Element>>> cpp_value(impl->GetElementArrayAttribute(html_names::kAriaOwnsAttr));

  if (!cpp_value.has_value()) {
    V8SetReturnValueNull(info);
    return;
  }

  V8SetReturnValue(info, FreezeV8Object(ToV8(cpp_value.value(), info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void AriaOwnsElementsAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  ElementInternals* impl = V8ElementInternals::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "ElementInternals", "ariaOwnsElements");
  CEReactionsScope ce_reactions_scope;

  bool is_null = IsUndefinedOrNull(v8_value);

  // Prepare the value to be set.
  base::Optional<HeapVector<Member<Element>>> cpp_value = is_null ? base::nullopt : base::Optional<HeapVector<Member<Element>>>(NativeValueTraits<IDLSequence<Element>>::NativeValue(info.GetIsolate(), v8_value, exception_state));
  if (exception_state.HadException())
    return;

  impl->SetElementArrayAttribute(html_names::kAriaOwnsAttr, cpp_value);
}

static void SetFormValueMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "ElementInternals", "setFormValue");

  ElementInternals* impl = V8ElementInternals::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  FileOrUSVStringOrFormData value;
  FileOrUSVStringOrFormData state;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  V8FileOrUSVStringOrFormData::ToImpl(info.GetIsolate(), info[0], value, UnionTypeConversionMode::kNullable, exception_state);
  if (exception_state.HadException())
    return;

  if (UNLIKELY(num_args_passed <= 1)) {
    impl->setFormValue(value, exception_state);
    if (exception_state.HadException()) {
      return;
    }
    return;
  }
  V8FileOrUSVStringOrFormData::ToImpl(info.GetIsolate(), info[1], state, UnionTypeConversionMode::kNullable, exception_state);
  if (exception_state.HadException())
    return;

  impl->setFormValue(value, state, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void SetValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "ElementInternals", "setValidity");

  ElementInternals* impl = V8ElementInternals::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  ValidityStateFlags* flags;
  V8StringResource<> message;
  Element* anchor;
  int num_args_passed = info.Length();
  while (num_args_passed > 0) {
    if (!info[num_args_passed - 1]->IsUndefined())
      break;
    --num_args_passed;
  }
  if (!info[0]->IsNullOrUndefined() && !info[0]->IsObject()) {
    exception_state.ThrowTypeError("parameter 1 ('flags') is not an object.");
    return;
  }
  flags = NativeValueTraits<ValidityStateFlags>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  if (UNLIKELY(num_args_passed <= 1)) {
    impl->setValidity(flags, exception_state);
    if (exception_state.HadException()) {
      return;
    }
    return;
  }
  message = info[1];
  if (!message.Prepare())
    return;

  if (UNLIKELY(num_args_passed <= 2)) {
    impl->setValidity(flags, message, exception_state);
    if (exception_state.HadException()) {
      return;
    }
    return;
  }
  anchor = V8Element::ToImplWithTypeCheck(info.GetIsolate(), info[2]);
  if (!anchor) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(2, "Element"));
    return;
  }

  impl->setValidity(flags, message, anchor, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void CheckValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "ElementInternals", "checkValidity");

  ElementInternals* impl = V8ElementInternals::ToImpl(info.Holder());

  bool result = impl->checkValidity(exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValueBool(info, result);
}

static void ReportValidityMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "ElementInternals", "reportValidity");

  ElementInternals* impl = V8ElementInternals::ToImpl(info.Holder());

  bool result = impl->reportValidity(exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValueBool(info, result);
}

}  // namespace element_internals_v8_internal

void V8ElementInternals::FormAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_form_Getter");

  element_internals_v8_internal::FormAttributeGetter(info);
}

void V8ElementInternals::WillValidateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_willValidate_Getter");

  element_internals_v8_internal::WillValidateAttributeGetter(info);
}

void V8ElementInternals::ValidityAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_validity_Getter");

  element_internals_v8_internal::ValidityAttributeGetter(info);
}

void V8ElementInternals::ValidationMessageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_validationMessage_Getter");

  element_internals_v8_internal::ValidationMessageAttributeGetter(info);
}

void V8ElementInternals::LabelsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_labels_Getter");

  element_internals_v8_internal::LabelsAttributeGetter(info);
}

void V8ElementInternals::StatesAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_states_Getter");

  element_internals_v8_internal::StatesAttributeGetter(info);
}

void V8ElementInternals::RoleAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_role_Getter");

  element_internals_v8_internal::RoleAttributeGetter(info);
}

void V8ElementInternals::RoleAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_role_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::RoleAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaAtomicAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaAtomic_Getter");

  element_internals_v8_internal::AriaAtomicAttributeGetter(info);
}

void V8ElementInternals::AriaAtomicAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaAtomic_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaAtomicAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaAutoCompleteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaAutoComplete_Getter");

  element_internals_v8_internal::AriaAutoCompleteAttributeGetter(info);
}

void V8ElementInternals::AriaAutoCompleteAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaAutoComplete_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaAutoCompleteAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaBusyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaBusy_Getter");

  element_internals_v8_internal::AriaBusyAttributeGetter(info);
}

void V8ElementInternals::AriaBusyAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaBusy_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaBusyAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaCheckedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaChecked_Getter");

  element_internals_v8_internal::AriaCheckedAttributeGetter(info);
}

void V8ElementInternals::AriaCheckedAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaChecked_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaCheckedAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaColCountAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaColCount_Getter");

  element_internals_v8_internal::AriaColCountAttributeGetter(info);
}

void V8ElementInternals::AriaColCountAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaColCount_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaColCountAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaColIndexAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaColIndex_Getter");

  element_internals_v8_internal::AriaColIndexAttributeGetter(info);
}

void V8ElementInternals::AriaColIndexAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaColIndex_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaColIndexAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaColSpanAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaColSpan_Getter");

  element_internals_v8_internal::AriaColSpanAttributeGetter(info);
}

void V8ElementInternals::AriaColSpanAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaColSpan_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaColSpanAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaCurrentAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaCurrent_Getter");

  element_internals_v8_internal::AriaCurrentAttributeGetter(info);
}

void V8ElementInternals::AriaCurrentAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaCurrent_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaCurrentAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaDescriptionAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDescription_Getter");

  element_internals_v8_internal::AriaDescriptionAttributeGetter(info);
}

void V8ElementInternals::AriaDescriptionAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDescription_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaDescriptionAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaDisabledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDisabled_Getter");

  element_internals_v8_internal::AriaDisabledAttributeGetter(info);
}

void V8ElementInternals::AriaDisabledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDisabled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaDisabledAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaExpandedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaExpanded_Getter");

  element_internals_v8_internal::AriaExpandedAttributeGetter(info);
}

void V8ElementInternals::AriaExpandedAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaExpanded_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaExpandedAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaHasPopupAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaHasPopup_Getter");

  element_internals_v8_internal::AriaHasPopupAttributeGetter(info);
}

void V8ElementInternals::AriaHasPopupAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaHasPopup_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaHasPopupAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaHiddenAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaHidden_Getter");

  element_internals_v8_internal::AriaHiddenAttributeGetter(info);
}

void V8ElementInternals::AriaHiddenAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaHidden_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaHiddenAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaKeyShortcutsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaKeyShortcuts_Getter");

  element_internals_v8_internal::AriaKeyShortcutsAttributeGetter(info);
}

void V8ElementInternals::AriaKeyShortcutsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaKeyShortcuts_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaKeyShortcutsAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaLabelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLabel_Getter");

  element_internals_v8_internal::AriaLabelAttributeGetter(info);
}

void V8ElementInternals::AriaLabelAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLabel_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaLabelAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaLevelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLevel_Getter");

  element_internals_v8_internal::AriaLevelAttributeGetter(info);
}

void V8ElementInternals::AriaLevelAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLevel_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaLevelAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaLiveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLive_Getter");

  element_internals_v8_internal::AriaLiveAttributeGetter(info);
}

void V8ElementInternals::AriaLiveAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLive_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaLiveAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaModalAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaModal_Getter");

  element_internals_v8_internal::AriaModalAttributeGetter(info);
}

void V8ElementInternals::AriaModalAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaModal_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaModalAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaMultiLineAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaMultiLine_Getter");

  element_internals_v8_internal::AriaMultiLineAttributeGetter(info);
}

void V8ElementInternals::AriaMultiLineAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaMultiLine_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaMultiLineAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaMultiSelectableAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaMultiSelectable_Getter");

  element_internals_v8_internal::AriaMultiSelectableAttributeGetter(info);
}

void V8ElementInternals::AriaMultiSelectableAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaMultiSelectable_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaMultiSelectableAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaOrientationAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaOrientation_Getter");

  element_internals_v8_internal::AriaOrientationAttributeGetter(info);
}

void V8ElementInternals::AriaOrientationAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaOrientation_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaOrientationAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaPlaceholderAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaPlaceholder_Getter");

  element_internals_v8_internal::AriaPlaceholderAttributeGetter(info);
}

void V8ElementInternals::AriaPlaceholderAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaPlaceholder_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaPlaceholderAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaPosInSetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaPosInSet_Getter");

  element_internals_v8_internal::AriaPosInSetAttributeGetter(info);
}

void V8ElementInternals::AriaPosInSetAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaPosInSet_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaPosInSetAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaPressedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaPressed_Getter");

  element_internals_v8_internal::AriaPressedAttributeGetter(info);
}

void V8ElementInternals::AriaPressedAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaPressed_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaPressedAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaReadOnlyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaReadOnly_Getter");

  element_internals_v8_internal::AriaReadOnlyAttributeGetter(info);
}

void V8ElementInternals::AriaReadOnlyAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaReadOnly_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaReadOnlyAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaRelevantAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRelevant_Getter");

  element_internals_v8_internal::AriaRelevantAttributeGetter(info);
}

void V8ElementInternals::AriaRelevantAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRelevant_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaRelevantAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaRequiredAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRequired_Getter");

  element_internals_v8_internal::AriaRequiredAttributeGetter(info);
}

void V8ElementInternals::AriaRequiredAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRequired_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaRequiredAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaRoleDescriptionAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRoleDescription_Getter");

  element_internals_v8_internal::AriaRoleDescriptionAttributeGetter(info);
}

void V8ElementInternals::AriaRoleDescriptionAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRoleDescription_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaRoleDescriptionAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaRowCountAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRowCount_Getter");

  element_internals_v8_internal::AriaRowCountAttributeGetter(info);
}

void V8ElementInternals::AriaRowCountAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRowCount_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaRowCountAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaRowIndexAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRowIndex_Getter");

  element_internals_v8_internal::AriaRowIndexAttributeGetter(info);
}

void V8ElementInternals::AriaRowIndexAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRowIndex_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaRowIndexAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaRowSpanAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRowSpan_Getter");

  element_internals_v8_internal::AriaRowSpanAttributeGetter(info);
}

void V8ElementInternals::AriaRowSpanAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaRowSpan_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaRowSpanAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaSelectedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaSelected_Getter");

  element_internals_v8_internal::AriaSelectedAttributeGetter(info);
}

void V8ElementInternals::AriaSelectedAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaSelected_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaSelectedAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaSetSizeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaSetSize_Getter");

  element_internals_v8_internal::AriaSetSizeAttributeGetter(info);
}

void V8ElementInternals::AriaSetSizeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaSetSize_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaSetSizeAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaSortAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaSort_Getter");

  element_internals_v8_internal::AriaSortAttributeGetter(info);
}

void V8ElementInternals::AriaSortAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaSort_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaSortAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaValueMaxAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueMax_Getter");

  element_internals_v8_internal::AriaValueMaxAttributeGetter(info);
}

void V8ElementInternals::AriaValueMaxAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueMax_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaValueMaxAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaValueMinAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueMin_Getter");

  element_internals_v8_internal::AriaValueMinAttributeGetter(info);
}

void V8ElementInternals::AriaValueMinAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueMin_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaValueMinAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaValueNowAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueNow_Getter");

  element_internals_v8_internal::AriaValueNowAttributeGetter(info);
}

void V8ElementInternals::AriaValueNowAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueNow_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaValueNowAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaValueTextAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueText_Getter");

  element_internals_v8_internal::AriaValueTextAttributeGetter(info);
}

void V8ElementInternals::AriaValueTextAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaValueText_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaValueTextAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaActiveDescendantElementAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaActiveDescendantElement_Getter");

  element_internals_v8_internal::AriaActiveDescendantElementAttributeGetter(info);
}

void V8ElementInternals::AriaActiveDescendantElementAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaActiveDescendantElement_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaActiveDescendantElementAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaControlsElementsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaControlsElements_Getter");

  element_internals_v8_internal::AriaControlsElementsAttributeGetter(info);
}

void V8ElementInternals::AriaControlsElementsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaControlsElements_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaControlsElementsAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaDescribedByElementsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDescribedByElements_Getter");

  element_internals_v8_internal::AriaDescribedByElementsAttributeGetter(info);
}

void V8ElementInternals::AriaDescribedByElementsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDescribedByElements_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaDescribedByElementsAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaDetailsElementsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDetailsElements_Getter");

  element_internals_v8_internal::AriaDetailsElementsAttributeGetter(info);
}

void V8ElementInternals::AriaDetailsElementsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaDetailsElements_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaDetailsElementsAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaErrorMessageElementAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaErrorMessageElement_Getter");

  element_internals_v8_internal::AriaErrorMessageElementAttributeGetter(info);
}

void V8ElementInternals::AriaErrorMessageElementAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaErrorMessageElement_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaErrorMessageElementAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaFlowToElementsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaFlowToElements_Getter");

  element_internals_v8_internal::AriaFlowToElementsAttributeGetter(info);
}

void V8ElementInternals::AriaFlowToElementsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaFlowToElements_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaFlowToElementsAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaLabelledByElementsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLabelledByElements_Getter");

  element_internals_v8_internal::AriaLabelledByElementsAttributeGetter(info);
}

void V8ElementInternals::AriaLabelledByElementsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaLabelledByElements_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaLabelledByElementsAttributeSetter(v8_value, info);
}

void V8ElementInternals::AriaOwnsElementsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaOwnsElements_Getter");

  element_internals_v8_internal::AriaOwnsElementsAttributeGetter(info);
}

void V8ElementInternals::AriaOwnsElementsAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_ariaOwnsElements_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  element_internals_v8_internal::AriaOwnsElementsAttributeSetter(v8_value, info);
}

void V8ElementInternals::SetFormValueMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ElementInternals.setFormValue");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_setFormValue");

  element_internals_v8_internal::SetFormValueMethod(info);
}

void V8ElementInternals::SetValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ElementInternals.setValidity");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_setValidity");

  element_internals_v8_internal::SetValidityMethod(info);
}

void V8ElementInternals::CheckValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ElementInternals.checkValidity");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_checkValidity");

  element_internals_v8_internal::CheckValidityMethod(info);
}

void V8ElementInternals::ReportValidityMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("ElementInternals.reportValidity");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_ElementInternals_reportValidity");

  element_internals_v8_internal::ReportValidityMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8ElementInternalsMethods[] = {
    {"setFormValue", V8ElementInternals::SetFormValueMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"setValidity", V8ElementInternals::SetValidityMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"checkValidity", V8ElementInternals::CheckValidityMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"reportValidity", V8ElementInternals::ReportValidityMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8ElementInternalsTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8ElementInternals::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8ElementInternals::kInternalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "form", V8ElementInternals::FormAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "willValidate", V8ElementInternals::WillValidateAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "validity", V8ElementInternals::ValidityAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "validationMessage", V8ElementInternals::ValidationMessageAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "labels", V8ElementInternals::LabelsAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8ElementInternalsMethods, base::size(kV8ElementInternalsMethods));

  // Custom signature

  V8ElementInternals::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8ElementInternals::InstallRuntimeEnabledFeaturesOnTemplate(
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

  if (RuntimeEnabledFeatures::AOMAriaPropertiesEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "ariaAtomic", V8ElementInternals::AriaAtomicAttributeGetterCallback, V8ElementInternals::AriaAtomicAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaAutoComplete", V8ElementInternals::AriaAutoCompleteAttributeGetterCallback, V8ElementInternals::AriaAutoCompleteAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaBusy", V8ElementInternals::AriaBusyAttributeGetterCallback, V8ElementInternals::AriaBusyAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaChecked", V8ElementInternals::AriaCheckedAttributeGetterCallback, V8ElementInternals::AriaCheckedAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaColCount", V8ElementInternals::AriaColCountAttributeGetterCallback, V8ElementInternals::AriaColCountAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaColIndex", V8ElementInternals::AriaColIndexAttributeGetterCallback, V8ElementInternals::AriaColIndexAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaColSpan", V8ElementInternals::AriaColSpanAttributeGetterCallback, V8ElementInternals::AriaColSpanAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaCurrent", V8ElementInternals::AriaCurrentAttributeGetterCallback, V8ElementInternals::AriaCurrentAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaDisabled", V8ElementInternals::AriaDisabledAttributeGetterCallback, V8ElementInternals::AriaDisabledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaExpanded", V8ElementInternals::AriaExpandedAttributeGetterCallback, V8ElementInternals::AriaExpandedAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaHasPopup", V8ElementInternals::AriaHasPopupAttributeGetterCallback, V8ElementInternals::AriaHasPopupAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaHidden", V8ElementInternals::AriaHiddenAttributeGetterCallback, V8ElementInternals::AriaHiddenAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaKeyShortcuts", V8ElementInternals::AriaKeyShortcutsAttributeGetterCallback, V8ElementInternals::AriaKeyShortcutsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaLabel", V8ElementInternals::AriaLabelAttributeGetterCallback, V8ElementInternals::AriaLabelAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaLevel", V8ElementInternals::AriaLevelAttributeGetterCallback, V8ElementInternals::AriaLevelAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaLive", V8ElementInternals::AriaLiveAttributeGetterCallback, V8ElementInternals::AriaLiveAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaModal", V8ElementInternals::AriaModalAttributeGetterCallback, V8ElementInternals::AriaModalAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaMultiLine", V8ElementInternals::AriaMultiLineAttributeGetterCallback, V8ElementInternals::AriaMultiLineAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaMultiSelectable", V8ElementInternals::AriaMultiSelectableAttributeGetterCallback, V8ElementInternals::AriaMultiSelectableAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaOrientation", V8ElementInternals::AriaOrientationAttributeGetterCallback, V8ElementInternals::AriaOrientationAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaPlaceholder", V8ElementInternals::AriaPlaceholderAttributeGetterCallback, V8ElementInternals::AriaPlaceholderAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaPosInSet", V8ElementInternals::AriaPosInSetAttributeGetterCallback, V8ElementInternals::AriaPosInSetAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaPressed", V8ElementInternals::AriaPressedAttributeGetterCallback, V8ElementInternals::AriaPressedAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaReadOnly", V8ElementInternals::AriaReadOnlyAttributeGetterCallback, V8ElementInternals::AriaReadOnlyAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaRelevant", V8ElementInternals::AriaRelevantAttributeGetterCallback, V8ElementInternals::AriaRelevantAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaRequired", V8ElementInternals::AriaRequiredAttributeGetterCallback, V8ElementInternals::AriaRequiredAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaRoleDescription", V8ElementInternals::AriaRoleDescriptionAttributeGetterCallback, V8ElementInternals::AriaRoleDescriptionAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaRowCount", V8ElementInternals::AriaRowCountAttributeGetterCallback, V8ElementInternals::AriaRowCountAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaRowIndex", V8ElementInternals::AriaRowIndexAttributeGetterCallback, V8ElementInternals::AriaRowIndexAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaRowSpan", V8ElementInternals::AriaRowSpanAttributeGetterCallback, V8ElementInternals::AriaRowSpanAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaSelected", V8ElementInternals::AriaSelectedAttributeGetterCallback, V8ElementInternals::AriaSelectedAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaSetSize", V8ElementInternals::AriaSetSizeAttributeGetterCallback, V8ElementInternals::AriaSetSizeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaSort", V8ElementInternals::AriaSortAttributeGetterCallback, V8ElementInternals::AriaSortAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaValueMax", V8ElementInternals::AriaValueMaxAttributeGetterCallback, V8ElementInternals::AriaValueMaxAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaValueMin", V8ElementInternals::AriaValueMinAttributeGetterCallback, V8ElementInternals::AriaValueMinAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaValueNow", V8ElementInternals::AriaValueNowAttributeGetterCallback, V8ElementInternals::AriaValueNowAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaValueText", V8ElementInternals::AriaValueTextAttributeGetterCallback, V8ElementInternals::AriaValueTextAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }
  if (RuntimeEnabledFeatures::AOMAriaRelationshipPropertiesEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "ariaActiveDescendantElement", V8ElementInternals::AriaActiveDescendantElementAttributeGetterCallback, V8ElementInternals::AriaActiveDescendantElementAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaErrorMessageElement", V8ElementInternals::AriaErrorMessageElementAttributeGetterCallback, V8ElementInternals::AriaErrorMessageElementAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaControlsElements", V8ElementInternals::AriaControlsElementsAttributeGetterCallback, V8ElementInternals::AriaControlsElementsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaDescribedByElements", V8ElementInternals::AriaDescribedByElementsAttributeGetterCallback, V8ElementInternals::AriaDescribedByElementsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaDetailsElements", V8ElementInternals::AriaDetailsElementsAttributeGetterCallback, V8ElementInternals::AriaDetailsElementsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaFlowToElements", V8ElementInternals::AriaFlowToElementsAttributeGetterCallback, V8ElementInternals::AriaFlowToElementsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaLabelledByElements", V8ElementInternals::AriaLabelledByElementsAttributeGetterCallback, V8ElementInternals::AriaLabelledByElementsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "ariaOwnsElements", V8ElementInternals::AriaOwnsElementsAttributeGetterCallback, V8ElementInternals::AriaOwnsElementsAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }
  if (RuntimeEnabledFeatures::AccessibilityExposeARIAAnnotationsEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "ariaDescription", V8ElementInternals::AriaDescriptionAttributeGetterCallback, V8ElementInternals::AriaDescriptionAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }
  if (RuntimeEnabledFeatures::AccessibilityObjectModelEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "role", V8ElementInternals::RoleAttributeGetterCallback, V8ElementInternals::RoleAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }
  if (RuntimeEnabledFeatures::CustomStatePseudoClassEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "states", V8ElementInternals::StatesAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }

  // Custom signature
}

v8::Local<v8::FunctionTemplate> V8ElementInternals::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8ElementInternals::GetWrapperTypeInfo()),
      InstallV8ElementInternalsTemplate);
}

bool V8ElementInternals::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8ElementInternals::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8ElementInternals::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8ElementInternals::GetWrapperTypeInfo(), v8_value);
}

ElementInternals* V8ElementInternals::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
