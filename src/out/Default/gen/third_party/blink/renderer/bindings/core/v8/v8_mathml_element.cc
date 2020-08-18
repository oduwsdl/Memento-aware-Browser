// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_mathml_element.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/js_event_handler.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_css_style_declaration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_string_map.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_focus_options.h"
#include "third_party/blink/renderer/core/css/cssom/element_computed_style_map.h"
#include "third_party/blink/renderer/core/dom/document_and_element_event_handlers.h"
#include "third_party/blink/renderer/core/dom/global_event_handlers.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/fullscreen/element_fullscreen.h"
#include "third_party/blink/renderer/core/html/custom/ce_reactions_scope.h"
#include "third_party/blink/renderer/core/html/custom/v0_custom_element_processing_stack.h"
#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
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
const WrapperTypeInfo v8_mathml_element_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8MathMLElement::DomTemplate,
    nullptr,
    "MathMLElement",
    V8Element::GetWrapperTypeInfo(),
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kNodeClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in MathMLElement.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& MathMLElement::wrapper_type_info_ = v8_mathml_element_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, MathMLElement>::value,
    "MathMLElement inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&MathMLElement::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "MathMLElement is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace mathml_element_v8_internal {

static void StyleAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V8SetReturnValueFast(info, WTF::GetPtr(impl->style()), impl);
}

static void StyleAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  // [PutForwards] => style.cssText
  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "MathMLElement", "style");
  v8::Local<v8::Value> target;
  if (!holder->Get(isolate->GetCurrentContext(), V8AtomicString(isolate, "style"))
      .ToLocal(&target)) {
    return;
  }
  if (!target->IsObject()) {
    exception_state.ThrowTypeError("The attribute value is not an object");
    return;
  }
  bool result;
  if (!target.As<v8::Object>()->Set(
          isolate->GetCurrentContext(),
          V8AtomicString(isolate, "cssText"),
          v8_value).To(&result)) {
    return;
  }
  if (!result)
    return;
}

static void OncopyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(DocumentAndElementEventHandlers::oncopy(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncopyAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  DocumentAndElementEventHandlers::setOncopy(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncutAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(DocumentAndElementEventHandlers::oncut(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncutAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  DocumentAndElementEventHandlers::setOncut(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpasteAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(DocumentAndElementEventHandlers::onpaste(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpasteAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  DocumentAndElementEventHandlers::setOnpaste(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnabortAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onabort(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnabortAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnabort(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnblurAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onblur(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnblurAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnblur(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncancelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::oncancel(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncancelAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOncancel(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncanplayAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::oncanplay(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncanplayAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOncanplay(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncanplaythroughAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::oncanplaythrough(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncanplaythroughAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOncanplaythrough(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnchangeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onchange(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnchangeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnchange(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnclickAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onclick(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnclickAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnclick(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncloseAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onclose(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncloseAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnclose(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncontextmenuAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::oncontextmenu(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncontextmenuAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOncontextmenu(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncuechangeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::oncuechange(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncuechangeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOncuechange(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndblclickAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondblclick(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndblclickAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndblclick(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndragAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondrag(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndragAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndrag(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndragendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondragend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndragendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndragend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndragenterAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondragenter(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndragenterAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndragenter(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndragleaveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondragleave(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndragleaveAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndragleave(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndragoverAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondragover(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndragoverAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndragover(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndragstartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondragstart(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndragstartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndragstart(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndropAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondrop(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndropAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndrop(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OndurationchangeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ondurationchange(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OndurationchangeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOndurationchange(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnemptiedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onemptied(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnemptiedAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnemptied(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnendedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onended(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnendedAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnended(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnerrorAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, GlobalEventHandlers::onerror(*impl)));
}

static void OnerrorAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.
  /* no V8 -> C++ conversion for IDL type: OnErrorEventHandler */

  GlobalEventHandlers::setOnerror(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kOnErrorEventHandler));
}

static void OnfocusAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onfocus(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnfocusAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnfocus(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnformdataAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onformdata(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnformdataAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnformdata(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OninputAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::oninput(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OninputAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOninput(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OninvalidAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::oninvalid(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OninvalidAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOninvalid(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnkeydownAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onkeydown(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnkeydownAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnkeydown(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnkeypressAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onkeypress(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnkeypressAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnkeypress(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnkeyupAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onkeyup(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnkeyupAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnkeyup(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnloadAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onload(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnloadAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnload(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnloadeddataAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onloadeddata(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnloadeddataAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnloadeddata(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnloadedmetadataAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onloadedmetadata(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnloadedmetadataAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnloadedmetadata(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnloadstartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onloadstart(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnloadstartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnloadstart(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmousedownAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmousedown(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmousedownAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmousedown(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmouseenterAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  // [LenientThis]
  // Make sure that info.Holder() really points to an instance if [LenientThis].
  if (!V8MathMLElement::HasInstance(info.Holder(), info.GetIsolate()))
    return; // Return silently because of [LenientThis].

  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmouseenter(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmouseenterAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  // [LenientThis]
  // Make sure that info.Holder() really points to an instance if [LenientThis].
  if (!V8MathMLElement::HasInstance(holder, isolate))
    return; // Return silently because of [LenientThis].

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmouseenter(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmouseleaveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  // [LenientThis]
  // Make sure that info.Holder() really points to an instance if [LenientThis].
  if (!V8MathMLElement::HasInstance(info.Holder(), info.GetIsolate()))
    return; // Return silently because of [LenientThis].

  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmouseleave(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmouseleaveAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  // [LenientThis]
  // Make sure that info.Holder() really points to an instance if [LenientThis].
  if (!V8MathMLElement::HasInstance(holder, isolate))
    return; // Return silently because of [LenientThis].

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmouseleave(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmousemoveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmousemove(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmousemoveAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmousemove(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmouseoutAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmouseout(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmouseoutAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmouseout(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmouseoverAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmouseover(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmouseoverAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmouseover(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmouseupAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmouseup(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmouseupAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmouseup(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnmousewheelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onmousewheel(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnmousewheelAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnmousewheel(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnoverscrollAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onoverscroll(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnoverscrollAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnoverscroll(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpauseAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpause(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpauseAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpause(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnplayAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onplay(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnplayAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnplay(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnplayingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onplaying(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnplayingAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnplaying(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnprogressAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onprogress(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnprogressAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnprogress(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnratechangeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onratechange(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnratechangeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnratechange(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnresetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onreset(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnresetAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnreset(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnresizeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onresize(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnresizeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnresize(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnscrollAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onscroll(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnscrollAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnscroll(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnscrollendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onscrollend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnscrollendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnscrollend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnseekedAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onseeked(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnseekedAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnseeked(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnseekingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onseeking(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnseekingAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnseeking(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnselectAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onselect(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnselectAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnselect(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnstalledAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onstalled(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnstalledAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnstalled(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnsubmitAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onsubmit(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnsubmitAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnsubmit(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnsuspendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onsuspend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnsuspendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnsuspend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntimeupdateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ontimeupdate(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntimeupdateAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOntimeupdate(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntoggleAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ontoggle(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntoggleAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOntoggle(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnvolumechangeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onvolumechange(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnvolumechangeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnvolumechange(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnwaitingAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onwaiting(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnwaitingAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnwaiting(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnwebkitanimationendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onwebkitanimationend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnwebkitanimationendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnwebkitanimationend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnwebkitanimationiterationAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onwebkitanimationiteration(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnwebkitanimationiterationAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnwebkitanimationiteration(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnwebkitanimationstartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onwebkitanimationstart(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnwebkitanimationstartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnwebkitanimationstart(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnwebkittransitionendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onwebkittransitionend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnwebkittransitionendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnwebkittransitionend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnwheelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onwheel(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnwheelAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnwheel(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnauxclickAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onauxclick(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnauxclickAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnauxclick(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OngotpointercaptureAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ongotpointercapture(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OngotpointercaptureAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOngotpointercapture(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnlostpointercaptureAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onlostpointercapture(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnlostpointercaptureAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnlostpointercapture(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointerdownAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointerdown(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointerdownAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointerdown(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointermoveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointermove(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointermoveAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointermove(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointerrawupdateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointerrawupdate(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointerrawupdateAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointerrawupdate(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointerupAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointerup(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointerupAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointerup(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointercancelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointercancel(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointercancelAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointercancel(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointeroverAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointerover(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointeroverAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointerover(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointeroutAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointerout(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointeroutAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointerout(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointerenterAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointerenter(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointerenterAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointerenter(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnpointerleaveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onpointerleave(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnpointerleaveAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnpointerleave(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntouchcancelAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ontouchcancel(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntouchcancelAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOntouchcancel(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntouchendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ontouchend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntouchendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOntouchend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntouchmoveAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ontouchmove(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntouchmoveAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOntouchmove(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntouchstartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ontouchstart(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntouchstartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOntouchstart(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnselectstartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onselectstart(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnselectstartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnselectstart(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnselectionchangeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onselectionchange(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnselectionchangeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnselectionchange(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnanimationendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onanimationend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnanimationendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnanimationend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnanimationiterationAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onanimationiteration(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnanimationiterationAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnanimationiteration(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OnanimationstartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::onanimationstart(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OnanimationstartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOnanimationstart(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntransitionendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  EventListener* cpp_value(GlobalEventHandlers::ontransitionend(*impl));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntransitionendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  // Prepare the value to be set.

  GlobalEventHandlers::setOntransitionend(*impl, JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void DatasetAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V8SetReturnValueFast(info, WTF::GetPtr(impl->dataset()), impl);
}

static void DatasetAttributeGetterForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V8SetReturnValueForMainWorld(info, WTF::GetPtr(impl->dataset()));
}

static void NonceAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V8SetReturnValueString(info, impl->nonce(), info.GetIsolate());
}

static void NonceAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setNonce(cpp_value);
}

static void AutofocusAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V8SetReturnValueBool(info, impl->FastHasAttribute(html_names::kAutofocusAttr));
}

static void TabIndexAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V8SetReturnValueInt(info, impl->tabIndex());
}

static void TabIndexAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  MathMLElement* impl = V8MathMLElement::ToImpl(holder);

  V0CustomElementProcessingStack::CallbackDeliveryScope delivery_scope;

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "MathMLElement", "tabIndex");
  CEReactionsScope ce_reactions_scope;

  // Prepare the value to be set.
  int32_t cpp_value = NativeValueTraits<IDLLong>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setTabIndex(cpp_value);
}

static void FocusMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "MathMLElement", "focus");

  MathMLElement* impl = V8MathMLElement::ToImpl(info.Holder());

  FocusOptions* options;
  if (!info[0]->IsNullOrUndefined() && !info[0]->IsObject()) {
    exception_state.ThrowTypeError("parameter 1 ('options') is not an object.");
    return;
  }
  options = NativeValueTraits<FocusOptions>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  impl->focus(options);
}

static void BlurMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  MathMLElement* impl = V8MathMLElement::ToImpl(info.Holder());

  impl->blur();
}

}  // namespace mathml_element_v8_internal

void V8MathMLElement::StyleAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_style_Getter");

  mathml_element_v8_internal::StyleAttributeGetter(info);
}

void V8MathMLElement::StyleAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_style_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::StyleAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncopyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncopy_Getter");

  mathml_element_v8_internal::OncopyAttributeGetter(info);
}

void V8MathMLElement::OncopyAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncopy_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncopyAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncutAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncut_Getter");

  mathml_element_v8_internal::OncutAttributeGetter(info);
}

void V8MathMLElement::OncutAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncut_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncutAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpasteAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpaste_Getter");

  mathml_element_v8_internal::OnpasteAttributeGetter(info);
}

void V8MathMLElement::OnpasteAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpaste_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpasteAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnabortAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onabort_Getter");

  mathml_element_v8_internal::OnabortAttributeGetter(info);
}

void V8MathMLElement::OnabortAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onabort_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnabortAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnblurAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onblur_Getter");

  mathml_element_v8_internal::OnblurAttributeGetter(info);
}

void V8MathMLElement::OnblurAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onblur_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnblurAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncancelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncancel_Getter");

  mathml_element_v8_internal::OncancelAttributeGetter(info);
}

void V8MathMLElement::OncancelAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncancel_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncancelAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncanplayAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncanplay_Getter");

  mathml_element_v8_internal::OncanplayAttributeGetter(info);
}

void V8MathMLElement::OncanplayAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncanplay_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncanplayAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncanplaythroughAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncanplaythrough_Getter");

  mathml_element_v8_internal::OncanplaythroughAttributeGetter(info);
}

void V8MathMLElement::OncanplaythroughAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncanplaythrough_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncanplaythroughAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnchangeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onchange_Getter");

  mathml_element_v8_internal::OnchangeAttributeGetter(info);
}

void V8MathMLElement::OnchangeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onchange_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnchangeAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnclickAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onclick_Getter");

  mathml_element_v8_internal::OnclickAttributeGetter(info);
}

void V8MathMLElement::OnclickAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onclick_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnclickAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncloseAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onclose_Getter");

  mathml_element_v8_internal::OncloseAttributeGetter(info);
}

void V8MathMLElement::OncloseAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onclose_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncloseAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncontextmenuAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncontextmenu_Getter");

  mathml_element_v8_internal::OncontextmenuAttributeGetter(info);
}

void V8MathMLElement::OncontextmenuAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncontextmenu_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncontextmenuAttributeSetter(v8_value, info);
}

void V8MathMLElement::OncuechangeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncuechange_Getter");

  mathml_element_v8_internal::OncuechangeAttributeGetter(info);
}

void V8MathMLElement::OncuechangeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oncuechange_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OncuechangeAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndblclickAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondblclick_Getter");

  mathml_element_v8_internal::OndblclickAttributeGetter(info);
}

void V8MathMLElement::OndblclickAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondblclick_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndblclickAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndragAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondrag_Getter");

  mathml_element_v8_internal::OndragAttributeGetter(info);
}

void V8MathMLElement::OndragAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondrag_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndragAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndragendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragend_Getter");

  mathml_element_v8_internal::OndragendAttributeGetter(info);
}

void V8MathMLElement::OndragendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndragendAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndragenterAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragenter_Getter");

  mathml_element_v8_internal::OndragenterAttributeGetter(info);
}

void V8MathMLElement::OndragenterAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragenter_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndragenterAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndragleaveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragleave_Getter");

  mathml_element_v8_internal::OndragleaveAttributeGetter(info);
}

void V8MathMLElement::OndragleaveAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragleave_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndragleaveAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndragoverAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragover_Getter");

  mathml_element_v8_internal::OndragoverAttributeGetter(info);
}

void V8MathMLElement::OndragoverAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragover_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndragoverAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndragstartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragstart_Getter");

  mathml_element_v8_internal::OndragstartAttributeGetter(info);
}

void V8MathMLElement::OndragstartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondragstart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndragstartAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndropAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondrop_Getter");

  mathml_element_v8_internal::OndropAttributeGetter(info);
}

void V8MathMLElement::OndropAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondrop_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndropAttributeSetter(v8_value, info);
}

void V8MathMLElement::OndurationchangeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondurationchange_Getter");

  mathml_element_v8_internal::OndurationchangeAttributeGetter(info);
}

void V8MathMLElement::OndurationchangeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ondurationchange_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OndurationchangeAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnemptiedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onemptied_Getter");

  mathml_element_v8_internal::OnemptiedAttributeGetter(info);
}

void V8MathMLElement::OnemptiedAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onemptied_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnemptiedAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnendedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onended_Getter");

  mathml_element_v8_internal::OnendedAttributeGetter(info);
}

void V8MathMLElement::OnendedAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onended_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnendedAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnerrorAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onerror_Getter");

  mathml_element_v8_internal::OnerrorAttributeGetter(info);
}

void V8MathMLElement::OnerrorAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onerror_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnerrorAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnfocusAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onfocus_Getter");

  mathml_element_v8_internal::OnfocusAttributeGetter(info);
}

void V8MathMLElement::OnfocusAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onfocus_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnfocusAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnformdataAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onformdata_Getter");

  mathml_element_v8_internal::OnformdataAttributeGetter(info);
}

void V8MathMLElement::OnformdataAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onformdata_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnformdataAttributeSetter(v8_value, info);
}

void V8MathMLElement::OninputAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oninput_Getter");

  mathml_element_v8_internal::OninputAttributeGetter(info);
}

void V8MathMLElement::OninputAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oninput_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OninputAttributeSetter(v8_value, info);
}

void V8MathMLElement::OninvalidAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oninvalid_Getter");

  mathml_element_v8_internal::OninvalidAttributeGetter(info);
}

void V8MathMLElement::OninvalidAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_oninvalid_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OninvalidAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnkeydownAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onkeydown_Getter");

  mathml_element_v8_internal::OnkeydownAttributeGetter(info);
}

void V8MathMLElement::OnkeydownAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onkeydown_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnkeydownAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnkeypressAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onkeypress_Getter");

  mathml_element_v8_internal::OnkeypressAttributeGetter(info);
}

void V8MathMLElement::OnkeypressAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onkeypress_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnkeypressAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnkeyupAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onkeyup_Getter");

  mathml_element_v8_internal::OnkeyupAttributeGetter(info);
}

void V8MathMLElement::OnkeyupAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onkeyup_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnkeyupAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnloadAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onload_Getter");

  mathml_element_v8_internal::OnloadAttributeGetter(info);
}

void V8MathMLElement::OnloadAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onload_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnloadAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnloadeddataAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onloadeddata_Getter");

  mathml_element_v8_internal::OnloadeddataAttributeGetter(info);
}

void V8MathMLElement::OnloadeddataAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onloadeddata_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnloadeddataAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnloadedmetadataAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onloadedmetadata_Getter");

  mathml_element_v8_internal::OnloadedmetadataAttributeGetter(info);
}

void V8MathMLElement::OnloadedmetadataAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onloadedmetadata_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnloadedmetadataAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnloadstartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onloadstart_Getter");

  mathml_element_v8_internal::OnloadstartAttributeGetter(info);
}

void V8MathMLElement::OnloadstartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onloadstart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnloadstartAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmousedownAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmousedown_Getter");

  mathml_element_v8_internal::OnmousedownAttributeGetter(info);
}

void V8MathMLElement::OnmousedownAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmousedown_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmousedownAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmouseenterAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseenter_Getter");

  mathml_element_v8_internal::OnmouseenterAttributeGetter(info);
}

void V8MathMLElement::OnmouseenterAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseenter_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmouseenterAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmouseleaveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseleave_Getter");

  mathml_element_v8_internal::OnmouseleaveAttributeGetter(info);
}

void V8MathMLElement::OnmouseleaveAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseleave_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmouseleaveAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmousemoveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmousemove_Getter");

  mathml_element_v8_internal::OnmousemoveAttributeGetter(info);
}

void V8MathMLElement::OnmousemoveAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmousemove_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmousemoveAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmouseoutAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseout_Getter");

  mathml_element_v8_internal::OnmouseoutAttributeGetter(info);
}

void V8MathMLElement::OnmouseoutAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseout_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmouseoutAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmouseoverAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseover_Getter");

  mathml_element_v8_internal::OnmouseoverAttributeGetter(info);
}

void V8MathMLElement::OnmouseoverAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseover_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmouseoverAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmouseupAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseup_Getter");

  mathml_element_v8_internal::OnmouseupAttributeGetter(info);
}

void V8MathMLElement::OnmouseupAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmouseup_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmouseupAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnmousewheelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmousewheel_Getter");

  mathml_element_v8_internal::OnmousewheelAttributeGetter(info);
}

void V8MathMLElement::OnmousewheelAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onmousewheel_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnmousewheelAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnoverscrollAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onoverscroll_Getter");

  mathml_element_v8_internal::OnoverscrollAttributeGetter(info);
}

void V8MathMLElement::OnoverscrollAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onoverscroll_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnoverscrollAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpauseAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpause_Getter");

  mathml_element_v8_internal::OnpauseAttributeGetter(info);
}

void V8MathMLElement::OnpauseAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpause_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpauseAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnplayAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onplay_Getter");

  mathml_element_v8_internal::OnplayAttributeGetter(info);
}

void V8MathMLElement::OnplayAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onplay_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnplayAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnplayingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onplaying_Getter");

  mathml_element_v8_internal::OnplayingAttributeGetter(info);
}

void V8MathMLElement::OnplayingAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onplaying_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnplayingAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnprogressAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onprogress_Getter");

  mathml_element_v8_internal::OnprogressAttributeGetter(info);
}

void V8MathMLElement::OnprogressAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onprogress_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnprogressAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnratechangeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onratechange_Getter");

  mathml_element_v8_internal::OnratechangeAttributeGetter(info);
}

void V8MathMLElement::OnratechangeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onratechange_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnratechangeAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnresetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onreset_Getter");

  mathml_element_v8_internal::OnresetAttributeGetter(info);
}

void V8MathMLElement::OnresetAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onreset_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnresetAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnresizeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onresize_Getter");

  mathml_element_v8_internal::OnresizeAttributeGetter(info);
}

void V8MathMLElement::OnresizeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onresize_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnresizeAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnscrollAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onscroll_Getter");

  mathml_element_v8_internal::OnscrollAttributeGetter(info);
}

void V8MathMLElement::OnscrollAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onscroll_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnscrollAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnscrollendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onscrollend_Getter");

  mathml_element_v8_internal::OnscrollendAttributeGetter(info);
}

void V8MathMLElement::OnscrollendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onscrollend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnscrollendAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnseekedAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onseeked_Getter");

  mathml_element_v8_internal::OnseekedAttributeGetter(info);
}

void V8MathMLElement::OnseekedAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onseeked_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnseekedAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnseekingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onseeking_Getter");

  mathml_element_v8_internal::OnseekingAttributeGetter(info);
}

void V8MathMLElement::OnseekingAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onseeking_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnseekingAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnselectAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onselect_Getter");

  mathml_element_v8_internal::OnselectAttributeGetter(info);
}

void V8MathMLElement::OnselectAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onselect_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnselectAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnstalledAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onstalled_Getter");

  mathml_element_v8_internal::OnstalledAttributeGetter(info);
}

void V8MathMLElement::OnstalledAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onstalled_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnstalledAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnsubmitAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onsubmit_Getter");

  mathml_element_v8_internal::OnsubmitAttributeGetter(info);
}

void V8MathMLElement::OnsubmitAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onsubmit_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnsubmitAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnsuspendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onsuspend_Getter");

  mathml_element_v8_internal::OnsuspendAttributeGetter(info);
}

void V8MathMLElement::OnsuspendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onsuspend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnsuspendAttributeSetter(v8_value, info);
}

void V8MathMLElement::OntimeupdateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontimeupdate_Getter");

  mathml_element_v8_internal::OntimeupdateAttributeGetter(info);
}

void V8MathMLElement::OntimeupdateAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontimeupdate_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OntimeupdateAttributeSetter(v8_value, info);
}

void V8MathMLElement::OntoggleAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontoggle_Getter");

  mathml_element_v8_internal::OntoggleAttributeGetter(info);
}

void V8MathMLElement::OntoggleAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontoggle_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OntoggleAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnvolumechangeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onvolumechange_Getter");

  mathml_element_v8_internal::OnvolumechangeAttributeGetter(info);
}

void V8MathMLElement::OnvolumechangeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onvolumechange_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnvolumechangeAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnwaitingAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwaiting_Getter");

  mathml_element_v8_internal::OnwaitingAttributeGetter(info);
}

void V8MathMLElement::OnwaitingAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwaiting_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnwaitingAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnwebkitanimationendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkitanimationend_Getter");

  mathml_element_v8_internal::OnwebkitanimationendAttributeGetter(info);
}

void V8MathMLElement::OnwebkitanimationendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkitanimationend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnwebkitanimationendAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnwebkitanimationiterationAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkitanimationiteration_Getter");

  mathml_element_v8_internal::OnwebkitanimationiterationAttributeGetter(info);
}

void V8MathMLElement::OnwebkitanimationiterationAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkitanimationiteration_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnwebkitanimationiterationAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnwebkitanimationstartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkitanimationstart_Getter");

  mathml_element_v8_internal::OnwebkitanimationstartAttributeGetter(info);
}

void V8MathMLElement::OnwebkitanimationstartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkitanimationstart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnwebkitanimationstartAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnwebkittransitionendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkittransitionend_Getter");

  mathml_element_v8_internal::OnwebkittransitionendAttributeGetter(info);
}

void V8MathMLElement::OnwebkittransitionendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwebkittransitionend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnwebkittransitionendAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnwheelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwheel_Getter");

  mathml_element_v8_internal::OnwheelAttributeGetter(info);
}

void V8MathMLElement::OnwheelAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onwheel_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnwheelAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnauxclickAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onauxclick_Getter");

  mathml_element_v8_internal::OnauxclickAttributeGetter(info);
}

void V8MathMLElement::OnauxclickAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onauxclick_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnauxclickAttributeSetter(v8_value, info);
}

void V8MathMLElement::OngotpointercaptureAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ongotpointercapture_Getter");

  mathml_element_v8_internal::OngotpointercaptureAttributeGetter(info);
}

void V8MathMLElement::OngotpointercaptureAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ongotpointercapture_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OngotpointercaptureAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnlostpointercaptureAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onlostpointercapture_Getter");

  mathml_element_v8_internal::OnlostpointercaptureAttributeGetter(info);
}

void V8MathMLElement::OnlostpointercaptureAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onlostpointercapture_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnlostpointercaptureAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointerdownAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerdown_Getter");

  mathml_element_v8_internal::OnpointerdownAttributeGetter(info);
}

void V8MathMLElement::OnpointerdownAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerdown_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointerdownAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointermoveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointermove_Getter");

  mathml_element_v8_internal::OnpointermoveAttributeGetter(info);
}

void V8MathMLElement::OnpointermoveAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointermove_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointermoveAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointerrawupdateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerrawupdate_Getter");

  mathml_element_v8_internal::OnpointerrawupdateAttributeGetter(info);
}

void V8MathMLElement::OnpointerrawupdateAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerrawupdate_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointerrawupdateAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointerupAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerup_Getter");

  mathml_element_v8_internal::OnpointerupAttributeGetter(info);
}

void V8MathMLElement::OnpointerupAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerup_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointerupAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointercancelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointercancel_Getter");

  mathml_element_v8_internal::OnpointercancelAttributeGetter(info);
}

void V8MathMLElement::OnpointercancelAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointercancel_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointercancelAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointeroverAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerover_Getter");

  mathml_element_v8_internal::OnpointeroverAttributeGetter(info);
}

void V8MathMLElement::OnpointeroverAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerover_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointeroverAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointeroutAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerout_Getter");

  mathml_element_v8_internal::OnpointeroutAttributeGetter(info);
}

void V8MathMLElement::OnpointeroutAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerout_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointeroutAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointerenterAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerenter_Getter");

  mathml_element_v8_internal::OnpointerenterAttributeGetter(info);
}

void V8MathMLElement::OnpointerenterAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerenter_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointerenterAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnpointerleaveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerleave_Getter");

  mathml_element_v8_internal::OnpointerleaveAttributeGetter(info);
}

void V8MathMLElement::OnpointerleaveAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onpointerleave_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnpointerleaveAttributeSetter(v8_value, info);
}

void V8MathMLElement::OntouchcancelAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchcancel_Getter");

  mathml_element_v8_internal::OntouchcancelAttributeGetter(info);
}

void V8MathMLElement::OntouchcancelAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchcancel_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OntouchcancelAttributeSetter(v8_value, info);
}

void V8MathMLElement::OntouchendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchend_Getter");

  mathml_element_v8_internal::OntouchendAttributeGetter(info);
}

void V8MathMLElement::OntouchendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OntouchendAttributeSetter(v8_value, info);
}

void V8MathMLElement::OntouchmoveAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchmove_Getter");

  mathml_element_v8_internal::OntouchmoveAttributeGetter(info);
}

void V8MathMLElement::OntouchmoveAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchmove_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OntouchmoveAttributeSetter(v8_value, info);
}

void V8MathMLElement::OntouchstartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchstart_Getter");

  mathml_element_v8_internal::OntouchstartAttributeGetter(info);
}

void V8MathMLElement::OntouchstartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontouchstart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OntouchstartAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnselectstartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onselectstart_Getter");

  mathml_element_v8_internal::OnselectstartAttributeGetter(info);
}

void V8MathMLElement::OnselectstartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onselectstart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnselectstartAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnselectionchangeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onselectionchange_Getter");

  mathml_element_v8_internal::OnselectionchangeAttributeGetter(info);
}

void V8MathMLElement::OnselectionchangeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onselectionchange_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnselectionchangeAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnanimationendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onanimationend_Getter");

  mathml_element_v8_internal::OnanimationendAttributeGetter(info);
}

void V8MathMLElement::OnanimationendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onanimationend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnanimationendAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnanimationiterationAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onanimationiteration_Getter");

  mathml_element_v8_internal::OnanimationiterationAttributeGetter(info);
}

void V8MathMLElement::OnanimationiterationAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onanimationiteration_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnanimationiterationAttributeSetter(v8_value, info);
}

void V8MathMLElement::OnanimationstartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onanimationstart_Getter");

  mathml_element_v8_internal::OnanimationstartAttributeGetter(info);
}

void V8MathMLElement::OnanimationstartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_onanimationstart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OnanimationstartAttributeSetter(v8_value, info);
}

void V8MathMLElement::OntransitionendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontransitionend_Getter");

  mathml_element_v8_internal::OntransitionendAttributeGetter(info);
}

void V8MathMLElement::OntransitionendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_ontransitionend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::OntransitionendAttributeSetter(v8_value, info);
}

void V8MathMLElement::DatasetAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_dataset_Getter");

  mathml_element_v8_internal::DatasetAttributeGetter(info);
}

void V8MathMLElement::DatasetAttributeGetterCallbackForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_dataset_Getter");

  mathml_element_v8_internal::DatasetAttributeGetterForMainWorld(info);
}

void V8MathMLElement::NonceAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_nonce_Getter");

  mathml_element_v8_internal::NonceAttributeGetter(info);
}

void V8MathMLElement::NonceAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_nonce_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::NonceAttributeSetter(v8_value, info);
}

void V8MathMLElement::AutofocusAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_autofocus_Getter");

  mathml_element_v8_internal::AutofocusAttributeGetter(info);
}

void V8MathMLElement::AutofocusAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_autofocus_Setter");

  V8SetReflectedBooleanAttribute(info, "MathMLElement", "autofocus", html_names::kAutofocusAttr);
}

void V8MathMLElement::TabIndexAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_tabIndex_Getter");

  mathml_element_v8_internal::TabIndexAttributeGetter(info);
}

void V8MathMLElement::TabIndexAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_tabIndex_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  mathml_element_v8_internal::TabIndexAttributeSetter(v8_value, info);
}

void V8MathMLElement::FocusMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("MathMLElement.focus");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_focus");

  mathml_element_v8_internal::FocusMethod(info);
}

void V8MathMLElement::BlurMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("MathMLElement.blur");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_MathMLElement_blur");

  mathml_element_v8_internal::BlurMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8MathMLElementMethods[] = {
    {"focus", V8MathMLElement::FocusMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"blur", V8MathMLElement::BlurMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8MathMLElementTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8MathMLElement::GetWrapperTypeInfo()->interface_name, V8Element::DomTemplate(isolate, world), V8MathMLElement::kInternalFieldCount);

  if (!RuntimeEnabledFeatures::MathMLCoreEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "style", V8MathMLElement::StyleAttributeGetterCallback, V8MathMLElement::StyleAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncopy", V8MathMLElement::OncopyAttributeGetterCallback, V8MathMLElement::OncopyAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncut", V8MathMLElement::OncutAttributeGetterCallback, V8MathMLElement::OncutAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpaste", V8MathMLElement::OnpasteAttributeGetterCallback, V8MathMLElement::OnpasteAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onabort", V8MathMLElement::OnabortAttributeGetterCallback, V8MathMLElement::OnabortAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onblur", V8MathMLElement::OnblurAttributeGetterCallback, V8MathMLElement::OnblurAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncancel", V8MathMLElement::OncancelAttributeGetterCallback, V8MathMLElement::OncancelAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncanplay", V8MathMLElement::OncanplayAttributeGetterCallback, V8MathMLElement::OncanplayAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncanplaythrough", V8MathMLElement::OncanplaythroughAttributeGetterCallback, V8MathMLElement::OncanplaythroughAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onchange", V8MathMLElement::OnchangeAttributeGetterCallback, V8MathMLElement::OnchangeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onclick", V8MathMLElement::OnclickAttributeGetterCallback, V8MathMLElement::OnclickAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onclose", V8MathMLElement::OncloseAttributeGetterCallback, V8MathMLElement::OncloseAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncontextmenu", V8MathMLElement::OncontextmenuAttributeGetterCallback, V8MathMLElement::OncontextmenuAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncuechange", V8MathMLElement::OncuechangeAttributeGetterCallback, V8MathMLElement::OncuechangeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondblclick", V8MathMLElement::OndblclickAttributeGetterCallback, V8MathMLElement::OndblclickAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondrag", V8MathMLElement::OndragAttributeGetterCallback, V8MathMLElement::OndragAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondragend", V8MathMLElement::OndragendAttributeGetterCallback, V8MathMLElement::OndragendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondragenter", V8MathMLElement::OndragenterAttributeGetterCallback, V8MathMLElement::OndragenterAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondragleave", V8MathMLElement::OndragleaveAttributeGetterCallback, V8MathMLElement::OndragleaveAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondragover", V8MathMLElement::OndragoverAttributeGetterCallback, V8MathMLElement::OndragoverAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondragstart", V8MathMLElement::OndragstartAttributeGetterCallback, V8MathMLElement::OndragstartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondrop", V8MathMLElement::OndropAttributeGetterCallback, V8MathMLElement::OndropAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ondurationchange", V8MathMLElement::OndurationchangeAttributeGetterCallback, V8MathMLElement::OndurationchangeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onemptied", V8MathMLElement::OnemptiedAttributeGetterCallback, V8MathMLElement::OnemptiedAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onended", V8MathMLElement::OnendedAttributeGetterCallback, V8MathMLElement::OnendedAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onerror", V8MathMLElement::OnerrorAttributeGetterCallback, V8MathMLElement::OnerrorAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onfocus", V8MathMLElement::OnfocusAttributeGetterCallback, V8MathMLElement::OnfocusAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onformdata", V8MathMLElement::OnformdataAttributeGetterCallback, V8MathMLElement::OnformdataAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oninput", V8MathMLElement::OninputAttributeGetterCallback, V8MathMLElement::OninputAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oninvalid", V8MathMLElement::OninvalidAttributeGetterCallback, V8MathMLElement::OninvalidAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onkeydown", V8MathMLElement::OnkeydownAttributeGetterCallback, V8MathMLElement::OnkeydownAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onkeypress", V8MathMLElement::OnkeypressAttributeGetterCallback, V8MathMLElement::OnkeypressAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onkeyup", V8MathMLElement::OnkeyupAttributeGetterCallback, V8MathMLElement::OnkeyupAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onload", V8MathMLElement::OnloadAttributeGetterCallback, V8MathMLElement::OnloadAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onloadeddata", V8MathMLElement::OnloadeddataAttributeGetterCallback, V8MathMLElement::OnloadeddataAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onloadedmetadata", V8MathMLElement::OnloadedmetadataAttributeGetterCallback, V8MathMLElement::OnloadedmetadataAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onloadstart", V8MathMLElement::OnloadstartAttributeGetterCallback, V8MathMLElement::OnloadstartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmousedown", V8MathMLElement::OnmousedownAttributeGetterCallback, V8MathMLElement::OnmousedownAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmouseenter", V8MathMLElement::OnmouseenterAttributeGetterCallback, V8MathMLElement::OnmouseenterAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kDoNotCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmouseleave", V8MathMLElement::OnmouseleaveAttributeGetterCallback, V8MathMLElement::OnmouseleaveAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kDoNotCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmousemove", V8MathMLElement::OnmousemoveAttributeGetterCallback, V8MathMLElement::OnmousemoveAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmouseout", V8MathMLElement::OnmouseoutAttributeGetterCallback, V8MathMLElement::OnmouseoutAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmouseover", V8MathMLElement::OnmouseoverAttributeGetterCallback, V8MathMLElement::OnmouseoverAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmouseup", V8MathMLElement::OnmouseupAttributeGetterCallback, V8MathMLElement::OnmouseupAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onmousewheel", V8MathMLElement::OnmousewheelAttributeGetterCallback, V8MathMLElement::OnmousewheelAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpause", V8MathMLElement::OnpauseAttributeGetterCallback, V8MathMLElement::OnpauseAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onplay", V8MathMLElement::OnplayAttributeGetterCallback, V8MathMLElement::OnplayAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onplaying", V8MathMLElement::OnplayingAttributeGetterCallback, V8MathMLElement::OnplayingAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onprogress", V8MathMLElement::OnprogressAttributeGetterCallback, V8MathMLElement::OnprogressAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onratechange", V8MathMLElement::OnratechangeAttributeGetterCallback, V8MathMLElement::OnratechangeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onreset", V8MathMLElement::OnresetAttributeGetterCallback, V8MathMLElement::OnresetAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onresize", V8MathMLElement::OnresizeAttributeGetterCallback, V8MathMLElement::OnresizeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onscroll", V8MathMLElement::OnscrollAttributeGetterCallback, V8MathMLElement::OnscrollAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onseeked", V8MathMLElement::OnseekedAttributeGetterCallback, V8MathMLElement::OnseekedAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onseeking", V8MathMLElement::OnseekingAttributeGetterCallback, V8MathMLElement::OnseekingAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onselect", V8MathMLElement::OnselectAttributeGetterCallback, V8MathMLElement::OnselectAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onstalled", V8MathMLElement::OnstalledAttributeGetterCallback, V8MathMLElement::OnstalledAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onsubmit", V8MathMLElement::OnsubmitAttributeGetterCallback, V8MathMLElement::OnsubmitAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onsuspend", V8MathMLElement::OnsuspendAttributeGetterCallback, V8MathMLElement::OnsuspendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontimeupdate", V8MathMLElement::OntimeupdateAttributeGetterCallback, V8MathMLElement::OntimeupdateAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontoggle", V8MathMLElement::OntoggleAttributeGetterCallback, V8MathMLElement::OntoggleAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onvolumechange", V8MathMLElement::OnvolumechangeAttributeGetterCallback, V8MathMLElement::OnvolumechangeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onwaiting", V8MathMLElement::OnwaitingAttributeGetterCallback, V8MathMLElement::OnwaitingAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onwebkitanimationend", V8MathMLElement::OnwebkitanimationendAttributeGetterCallback, V8MathMLElement::OnwebkitanimationendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onwebkitanimationiteration", V8MathMLElement::OnwebkitanimationiterationAttributeGetterCallback, V8MathMLElement::OnwebkitanimationiterationAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onwebkitanimationstart", V8MathMLElement::OnwebkitanimationstartAttributeGetterCallback, V8MathMLElement::OnwebkitanimationstartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onwebkittransitionend", V8MathMLElement::OnwebkittransitionendAttributeGetterCallback, V8MathMLElement::OnwebkittransitionendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onwheel", V8MathMLElement::OnwheelAttributeGetterCallback, V8MathMLElement::OnwheelAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onauxclick", V8MathMLElement::OnauxclickAttributeGetterCallback, V8MathMLElement::OnauxclickAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ongotpointercapture", V8MathMLElement::OngotpointercaptureAttributeGetterCallback, V8MathMLElement::OngotpointercaptureAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onlostpointercapture", V8MathMLElement::OnlostpointercaptureAttributeGetterCallback, V8MathMLElement::OnlostpointercaptureAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointerdown", V8MathMLElement::OnpointerdownAttributeGetterCallback, V8MathMLElement::OnpointerdownAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointermove", V8MathMLElement::OnpointermoveAttributeGetterCallback, V8MathMLElement::OnpointermoveAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointerup", V8MathMLElement::OnpointerupAttributeGetterCallback, V8MathMLElement::OnpointerupAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointercancel", V8MathMLElement::OnpointercancelAttributeGetterCallback, V8MathMLElement::OnpointercancelAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointerover", V8MathMLElement::OnpointeroverAttributeGetterCallback, V8MathMLElement::OnpointeroverAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointerout", V8MathMLElement::OnpointeroutAttributeGetterCallback, V8MathMLElement::OnpointeroutAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointerenter", V8MathMLElement::OnpointerenterAttributeGetterCallback, V8MathMLElement::OnpointerenterAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onpointerleave", V8MathMLElement::OnpointerleaveAttributeGetterCallback, V8MathMLElement::OnpointerleaveAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onselectstart", V8MathMLElement::OnselectstartAttributeGetterCallback, V8MathMLElement::OnselectstartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onselectionchange", V8MathMLElement::OnselectionchangeAttributeGetterCallback, V8MathMLElement::OnselectionchangeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onanimationend", V8MathMLElement::OnanimationendAttributeGetterCallback, V8MathMLElement::OnanimationendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onanimationiteration", V8MathMLElement::OnanimationiterationAttributeGetterCallback, V8MathMLElement::OnanimationiterationAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "onanimationstart", V8MathMLElement::OnanimationstartAttributeGetterCallback, V8MathMLElement::OnanimationstartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontransitionend", V8MathMLElement::OntransitionendAttributeGetterCallback, V8MathMLElement::OntransitionendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "dataset", V8MathMLElement::DatasetAttributeGetterCallbackForMainWorld, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kMainWorld },
      { "dataset", V8MathMLElement::DatasetAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kNonMainWorlds },
      { "nonce", V8MathMLElement::NonceAttributeGetterCallback, V8MathMLElement::NonceAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "autofocus", V8MathMLElement::AutofocusAttributeGetterCallback, V8MathMLElement::AutofocusAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "tabIndex", V8MathMLElement::TabIndexAttributeGetterCallback, V8MathMLElement::TabIndexAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasNoSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8MathMLElementMethods, base::size(kV8MathMLElementMethods));

  // Custom signature

  V8MathMLElement::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8MathMLElement::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  if (!RuntimeEnabledFeatures::MathMLCoreEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  if (RuntimeEnabledFeatures::OverscrollCustomizationEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "onoverscroll", V8MathMLElement::OnoverscrollAttributeGetterCallback, V8MathMLElement::OnoverscrollAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        { "onscrollend", V8MathMLElement::OnscrollendAttributeGetterCallback, V8MathMLElement::OnscrollendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }
  if (RuntimeEnabledFeatures::PointerRawUpdateEnabled()) {
    static constexpr V8DOMConfiguration::AccessorConfiguration
    kAccessorConfigurations[] = {
        { "onpointerrawupdate", V8MathMLElement::OnpointerrawupdateAttributeGetterCallback, V8MathMLElement::OnpointerrawupdateAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
    };
    V8DOMConfiguration::InstallAccessors(
        isolate, world, instance_template, prototype_template, interface_template,
        signature, kAccessorConfigurations,
        base::size(kAccessorConfigurations));
  }

  // Custom signature
}

void V8MathMLElement::InstallTouchEventFeatureDetection(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance,
    v8::Local<v8::Object> prototype,
    v8::Local<v8::Function> interface) {
  v8::Local<v8::FunctionTemplate> interface_template =
      V8MathMLElement::GetWrapperTypeInfo()->DomTemplate(isolate, world);
  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  static constexpr V8DOMConfiguration::AccessorConfiguration
  kAccessorConfigurations[] = {
      { "ontouchcancel", V8MathMLElement::OntouchcancelAttributeGetterCallback, V8MathMLElement::OntouchcancelAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontouchend", V8MathMLElement::OntouchendAttributeGetterCallback, V8MathMLElement::OntouchendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontouchmove", V8MathMLElement::OntouchmoveAttributeGetterCallback, V8MathMLElement::OntouchmoveAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontouchstart", V8MathMLElement::OntouchstartAttributeGetterCallback, V8MathMLElement::OntouchstartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance, prototype, interface,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
}

void V8MathMLElement::InstallTouchEventFeatureDetection(
    ScriptState* script_state, v8::Local<v8::Object> instance) {
  V8PerContextData* per_context_data = script_state->PerContextData();
  v8::Local<v8::Object> prototype = per_context_data->PrototypeForType(
      V8MathMLElement::GetWrapperTypeInfo());
  v8::Local<v8::Function> interface = per_context_data->ConstructorForType(
      V8MathMLElement::GetWrapperTypeInfo());
  ALLOW_UNUSED_LOCAL(interface);
  InstallTouchEventFeatureDetection(script_state->GetIsolate(), script_state->World(), instance, prototype, interface);
}

void V8MathMLElement::InstallTouchEventFeatureDetection(ScriptState* script_state) {
  InstallTouchEventFeatureDetection(script_state, v8::Local<v8::Object>());
}

v8::Local<v8::FunctionTemplate> V8MathMLElement::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8MathMLElement::GetWrapperTypeInfo()),
      InstallV8MathMLElementTemplate);
}

bool V8MathMLElement::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8MathMLElement::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8MathMLElement::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8MathMLElement::GetWrapperTypeInfo(), v8_value);
}

MathMLElement* V8MathMLElement::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
