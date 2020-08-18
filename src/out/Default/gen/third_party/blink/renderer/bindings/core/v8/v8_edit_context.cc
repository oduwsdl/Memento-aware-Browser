// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_edit_context.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/js_event_handler.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_rect.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_edit_context_init.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/inspector/console_message.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/heap/heap.h"
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
const WrapperTypeInfo v8_edit_context_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8EditContext::DomTemplate,
    nullptr,
    "EditContext",
    V8EventTarget::GetWrapperTypeInfo(),
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in EditContext.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& EditContext::wrapper_type_info_ = v8_edit_context_wrapper_type_info;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, EditContext>::value,
    "EditContext does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&EditContext::HasPendingActivity),
                  decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "EditContext is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace edit_context_v8_internal {

static void TextAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  V8SetReturnValueString(info, impl->text(), info.GetIsolate());
}

static void TextAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  impl->setText(cpp_value);
}

static void SelectionStartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->selectionStart());
}

static void SelectionStartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "EditContext", "selectionStart");

  // Prepare the value to be set.
  uint32_t cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setSelectionStart(cpp_value, exception_state);
}

static void SelectionEndAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  V8SetReturnValueUnsigned(info, impl->selectionEnd());
}

static void SelectionEndAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "EditContext", "selectionEnd");

  // Prepare the value to be set.
  uint32_t cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), v8_value, exception_state);
  if (exception_state.HadException())
    return;

  impl->setSelectionEnd(cpp_value, exception_state);
}

static void InputModeAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  V8SetReturnValueString(info, impl->inputMode(), info.GetIsolate());
}

static void InputModeAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "EditContext", "inputMode");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  // Type check per: http://heycam.github.io/webidl/#dfn-attribute-setter
  // Returns undefined without setting the value if the value is invalid.
  DummyExceptionStateForTesting dummy_exception_state;
  {
    const char* const kValidValues[] = {
      "none",
      "text",
      "decimal",
      "search",
      "email",
      "numeric",
      "tel",
      "url",
      "password",
  };
    if (!IsValidEnum(cpp_value, kValidValues, base::size(kValidValues),
                     "EditContextInputMode", dummy_exception_state)) {
      ExecutionContext::ForCurrentRealm(info)->AddConsoleMessage(
          MakeGarbageCollected<ConsoleMessage>(
              mojom::ConsoleMessageSource::kJavaScript,
              mojom::ConsoleMessageLevel::kWarning,
              dummy_exception_state.Message()));
      return;
    }
  }

  impl->setInputMode(cpp_value);
}

static void InputPanelPolicyAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  V8SetReturnValueString(info, impl->inputPanelPolicy(), info.GetIsolate());
}

static void InputPanelPolicyAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "EditContext", "inputPanelPolicy");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  // Type check per: http://heycam.github.io/webidl/#dfn-attribute-setter
  // Returns undefined without setting the value if the value is invalid.
  DummyExceptionStateForTesting dummy_exception_state;
  {
    const char* const kValidValues[] = {
      "auto",
      "manual",
  };
    if (!IsValidEnum(cpp_value, kValidValues, base::size(kValidValues),
                     "EditContextInputPanelPolicy", dummy_exception_state)) {
      ExecutionContext::ForCurrentRealm(info)->AddConsoleMessage(
          MakeGarbageCollected<ConsoleMessage>(
              mojom::ConsoleMessageSource::kJavaScript,
              mojom::ConsoleMessageLevel::kWarning,
              dummy_exception_state.Message()));
      return;
    }
  }

  impl->setInputPanelPolicy(cpp_value);
}

static void EnterKeyHintAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  V8SetReturnValueString(info, impl->enterKeyHint(), info.GetIsolate());
}

static void EnterKeyHintAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  ExceptionState exception_state(isolate, ExceptionState::kSetterContext, "EditContext", "enterKeyHint");

  // Prepare the value to be set.
  V8StringResource<> cpp_value = v8_value;
  if (!cpp_value.Prepare())
    return;

  // Type check per: http://heycam.github.io/webidl/#dfn-attribute-setter
  // Returns undefined without setting the value if the value is invalid.
  DummyExceptionStateForTesting dummy_exception_state;
  {
    const char* const kValidValues[] = {
      "enter",
      "done",
      "go",
      "next",
      "previous",
      "search",
      "send",
  };
    if (!IsValidEnum(cpp_value, kValidValues, base::size(kValidValues),
                     "EditContextEnterKeyHint", dummy_exception_state)) {
      ExecutionContext::ForCurrentRealm(info)->AddConsoleMessage(
          MakeGarbageCollected<ConsoleMessage>(
              mojom::ConsoleMessageSource::kJavaScript,
              mojom::ConsoleMessageLevel::kWarning,
              dummy_exception_state.Message()));
      return;
    }
  }

  impl->setEnterKeyHint(cpp_value);
}

static void OntextupdateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  EventListener* cpp_value(WTF::GetPtr(impl->ontextupdate()));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntextupdateAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  // Prepare the value to be set.

  impl->setOntextupdate(JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OntextformatupdateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  EventListener* cpp_value(WTF::GetPtr(impl->ontextformatupdate()));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OntextformatupdateAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  // Prepare the value to be set.

  impl->setOntextformatupdate(JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncompositionstartAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  EventListener* cpp_value(WTF::GetPtr(impl->oncompositionstart()));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncompositionstartAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  // Prepare the value to be set.

  impl->setOncompositionstart(JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void OncompositionendAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EditContext* impl = V8EditContext::ToImpl(holder);

  EventListener* cpp_value(WTF::GetPtr(impl->oncompositionend()));

  V8SetReturnValue(info, JSEventHandler::AsV8Value(info.GetIsolate(), impl, cpp_value));
}

static void OncompositionendAttributeSetter(
    v8::Local<v8::Value> v8_value, const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  ALLOW_UNUSED_LOCAL(isolate);

  v8::Local<v8::Object> holder = info.Holder();
  ALLOW_UNUSED_LOCAL(holder);

  EditContext* impl = V8EditContext::ToImpl(holder);

  // Prepare the value to be set.

  impl->setOncompositionend(JSEventHandler::CreateOrNull(v8_value, JSEventHandler::HandlerType::kEventHandler));
}

static void FocusMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EditContext* impl = V8EditContext::ToImpl(info.Holder());

  impl->focus();
}

static void BlurMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EditContext* impl = V8EditContext::ToImpl(info.Holder());

  impl->blur();
}

static void UpdateSelectionMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "EditContext", "updateSelection");

  EditContext* impl = V8EditContext::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  uint32_t start;
  uint32_t end;
  start = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  end = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  impl->updateSelection(start, end, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void UpdateLayoutMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EditContext* impl = V8EditContext::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("updateLayout", "EditContext", ExceptionMessages::NotEnoughArguments(2, info.Length())));
    return;
  }

  DOMRect* control_bounds;
  DOMRect* selection_bounds;
  control_bounds = V8DOMRect::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!control_bounds) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("updateLayout", "EditContext", ExceptionMessages::ArgumentNotOfType(0, "DOMRect")));
    return;
  }

  selection_bounds = V8DOMRect::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!selection_bounds) {
    V8ThrowException::ThrowTypeError(info.GetIsolate(), ExceptionMessages::FailedToExecute("updateLayout", "EditContext", ExceptionMessages::ArgumentNotOfType(1, "DOMRect")));
    return;
  }

  impl->updateLayout(control_bounds, selection_bounds);
}

static void UpdateTextMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "EditContext", "updateText");

  EditContext* impl = V8EditContext::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 3)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(3, info.Length()));
    return;
  }

  uint32_t start;
  uint32_t end;
  V8StringResource<> new_text;
  start = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  end = NativeValueTraits<IDLUnsignedLong>::NativeValue(info.GetIsolate(), info[1], exception_state);
  if (exception_state.HadException())
    return;

  new_text = info[2];
  if (!new_text.Prepare())
    return;

  impl->updateText(start, end, new_text, exception_state);
  if (exception_state.HadException()) {
    return;
  }
}

static void Constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_ConstructorCallback");

  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kConstructionContext, "EditContext");
  ScriptState* script_state = ScriptState::From(
      info.NewTarget().As<v8::Object>()->CreationContext());

  EditContextInit* options;
  if (!info[0]->IsNullOrUndefined() && !info[0]->IsObject()) {
    exception_state.ThrowTypeError("parameter 1 ('options') is not an object.");
    return;
  }
  options = NativeValueTraits<EditContextInit>::NativeValue(info.GetIsolate(), info[0], exception_state);
  if (exception_state.HadException())
    return;

  EditContext* impl = EditContext::Create(script_state, options);
  v8::Local<v8::Object> wrapper = info.Holder();
  wrapper = impl->AssociateWithWrapper(info.GetIsolate(), V8EditContext::GetWrapperTypeInfo(), wrapper);
  V8SetReturnValue(info, wrapper);
}

CORE_EXPORT void ConstructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_Constructor");

  if (!info.IsConstructCall()) {
    V8ThrowException::ThrowTypeError(
        info.GetIsolate(),
        ExceptionMessages::ConstructorNotCallableAsFunction("EditContext"));
    return;
  }

  if (ConstructorMode::Current(info.GetIsolate()) == ConstructorMode::kWrapExistingObject) {
    V8SetReturnValue(info, info.Holder());
    return;
  }

  edit_context_v8_internal::Constructor(info);
}

}  // namespace edit_context_v8_internal

void V8EditContext::TextAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_text_Getter");

  edit_context_v8_internal::TextAttributeGetter(info);
}

void V8EditContext::TextAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_text_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::TextAttributeSetter(v8_value, info);
}

void V8EditContext::SelectionStartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_selectionStart_Getter");

  edit_context_v8_internal::SelectionStartAttributeGetter(info);
}

void V8EditContext::SelectionStartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_selectionStart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::SelectionStartAttributeSetter(v8_value, info);
}

void V8EditContext::SelectionEndAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_selectionEnd_Getter");

  edit_context_v8_internal::SelectionEndAttributeGetter(info);
}

void V8EditContext::SelectionEndAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_selectionEnd_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::SelectionEndAttributeSetter(v8_value, info);
}

void V8EditContext::InputModeAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_inputMode_Getter");

  edit_context_v8_internal::InputModeAttributeGetter(info);
}

void V8EditContext::InputModeAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_inputMode_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::InputModeAttributeSetter(v8_value, info);
}

void V8EditContext::InputPanelPolicyAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_inputPanelPolicy_Getter");

  edit_context_v8_internal::InputPanelPolicyAttributeGetter(info);
}

void V8EditContext::InputPanelPolicyAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_inputPanelPolicy_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::InputPanelPolicyAttributeSetter(v8_value, info);
}

void V8EditContext::EnterKeyHintAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_enterKeyHint_Getter");

  edit_context_v8_internal::EnterKeyHintAttributeGetter(info);
}

void V8EditContext::EnterKeyHintAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_enterKeyHint_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::EnterKeyHintAttributeSetter(v8_value, info);
}

void V8EditContext::OntextupdateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_ontextupdate_Getter");

  edit_context_v8_internal::OntextupdateAttributeGetter(info);
}

void V8EditContext::OntextupdateAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_ontextupdate_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::OntextupdateAttributeSetter(v8_value, info);
}

void V8EditContext::OntextformatupdateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_ontextformatupdate_Getter");

  edit_context_v8_internal::OntextformatupdateAttributeGetter(info);
}

void V8EditContext::OntextformatupdateAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_ontextformatupdate_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::OntextformatupdateAttributeSetter(v8_value, info);
}

void V8EditContext::OncompositionstartAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_oncompositionstart_Getter");

  edit_context_v8_internal::OncompositionstartAttributeGetter(info);
}

void V8EditContext::OncompositionstartAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_oncompositionstart_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::OncompositionstartAttributeSetter(v8_value, info);
}

void V8EditContext::OncompositionendAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_oncompositionend_Getter");

  edit_context_v8_internal::OncompositionendAttributeGetter(info);
}

void V8EditContext::OncompositionendAttributeSetterCallback(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_oncompositionend_Setter");

  v8::Local<v8::Value> v8_value = info[0];

  edit_context_v8_internal::OncompositionendAttributeSetter(v8_value, info);
}

void V8EditContext::FocusMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("EditContext.focus");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_focus");

  edit_context_v8_internal::FocusMethod(info);
}

void V8EditContext::BlurMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("EditContext.blur");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_blur");

  edit_context_v8_internal::BlurMethod(info);
}

void V8EditContext::UpdateSelectionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("EditContext.updateSelection");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_updateSelection");

  edit_context_v8_internal::UpdateSelectionMethod(info);
}

void V8EditContext::UpdateLayoutMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("EditContext.updateLayout");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_updateLayout");

  edit_context_v8_internal::UpdateLayoutMethod(info);
}

void V8EditContext::UpdateTextMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("EditContext.updateText");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_EditContext_updateText");

  edit_context_v8_internal::UpdateTextMethod(info);
}

static constexpr V8DOMConfiguration::MethodConfiguration kV8EditContextMethods[] = {
    {"focus", V8EditContext::FocusMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"blur", V8EditContext::BlurMethodCallback, 0, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"updateSelection", V8EditContext::UpdateSelectionMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"updateLayout", V8EditContext::UpdateLayoutMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
    {"updateText", V8EditContext::UpdateTextMethodCallback, 3, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds},
};

static void InstallV8EditContextTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8EditContext::GetWrapperTypeInfo()->interface_name, V8EventTarget::DomTemplate(isolate, world), V8EditContext::kInternalFieldCount);
  interface_template->SetCallHandler(edit_context_v8_internal::ConstructorCallback);
  interface_template->SetLength(0);

  if (!RuntimeEnabledFeatures::EditContextEnabled()) {
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
      { "text", V8EditContext::TextAttributeGetterCallback, V8EditContext::TextAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "selectionStart", V8EditContext::SelectionStartAttributeGetterCallback, V8EditContext::SelectionStartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "selectionEnd", V8EditContext::SelectionEndAttributeGetterCallback, V8EditContext::SelectionEndAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "inputMode", V8EditContext::InputModeAttributeGetterCallback, V8EditContext::InputModeAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "inputPanelPolicy", V8EditContext::InputPanelPolicyAttributeGetterCallback, V8EditContext::InputPanelPolicyAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "enterKeyHint", V8EditContext::EnterKeyHintAttributeGetterCallback, V8EditContext::EnterKeyHintAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontextupdate", V8EditContext::OntextupdateAttributeGetterCallback, V8EditContext::OntextupdateAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "ontextformatupdate", V8EditContext::OntextformatupdateAttributeGetterCallback, V8EditContext::OntextformatupdateAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncompositionstart", V8EditContext::OncompositionstartAttributeGetterCallback, V8EditContext::OncompositionstartAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      { "oncompositionend", V8EditContext::OncompositionendAttributeGetterCallback, V8EditContext::OncompositionendAttributeSetterCallback, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
  };
  V8DOMConfiguration::InstallAccessors(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kAccessorConfigurations,
      base::size(kAccessorConfigurations));
  V8DOMConfiguration::InstallMethods(
      isolate, world, instance_template, prototype_template, interface_template,
      signature, kV8EditContextMethods, base::size(kV8EditContextMethods));

  // Custom signature

  V8EditContext::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8EditContext::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  if (!RuntimeEnabledFeatures::EditContextEnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  // Custom signature
}

v8::Local<v8::FunctionTemplate> V8EditContext::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8EditContext::GetWrapperTypeInfo()),
      InstallV8EditContextTemplate);
}

bool V8EditContext::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8EditContext::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8EditContext::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8EditContext::GetWrapperTypeInfo(), v8_value);
}

EditContext* V8EditContext::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
