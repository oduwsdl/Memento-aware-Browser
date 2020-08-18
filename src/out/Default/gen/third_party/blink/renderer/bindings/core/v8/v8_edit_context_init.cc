// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_edit_context_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8EditContextInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "enterKeyHint",
    "inputMode",
    "inputPanelPolicy",
    "selectionEnd",
    "selectionStart",
    "text",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8EditContextInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, EditContextInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8EditContextInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> enter_key_hint_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&enter_key_hint_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (enter_key_hint_value.IsEmpty() || enter_key_hint_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> enter_key_hint_cpp_value = enter_key_hint_value;
    if (!enter_key_hint_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "enter",
        "done",
        "go",
        "next",
        "previous",
        "search",
        "send",
    };
    if (!IsValidEnum(enter_key_hint_cpp_value, kValidValues, base::size(kValidValues), "EditContextEnterKeyHint", exception_state))
      return;
    impl->setEnterKeyHint(enter_key_hint_cpp_value);
  }

  v8::Local<v8::Value> input_mode_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&input_mode_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (input_mode_value.IsEmpty() || input_mode_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> input_mode_cpp_value = input_mode_value;
    if (!input_mode_cpp_value.Prepare(exception_state))
      return;
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
    if (!IsValidEnum(input_mode_cpp_value, kValidValues, base::size(kValidValues), "EditContextInputMode", exception_state))
      return;
    impl->setInputMode(input_mode_cpp_value);
  }

  v8::Local<v8::Value> input_panel_policy_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&input_panel_policy_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (input_panel_policy_value.IsEmpty() || input_panel_policy_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> input_panel_policy_cpp_value = input_panel_policy_value;
    if (!input_panel_policy_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "auto",
        "manual",
    };
    if (!IsValidEnum(input_panel_policy_cpp_value, kValidValues, base::size(kValidValues), "EditContextInputPanelPolicy", exception_state))
      return;
    impl->setInputPanelPolicy(input_panel_policy_cpp_value);
  }

  v8::Local<v8::Value> selection_end_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&selection_end_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (selection_end_value.IsEmpty() || selection_end_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t selection_end_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, selection_end_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSelectionEnd(selection_end_cpp_value);
  }

  v8::Local<v8::Value> selection_start_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&selection_start_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (selection_start_value.IsEmpty() || selection_start_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t selection_start_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, selection_start_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSelectionStart(selection_start_cpp_value);
  }

  v8::Local<v8::Value> text_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&text_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (text_value.IsEmpty() || text_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> text_cpp_value = text_value;
    if (!text_cpp_value.Prepare(exception_state))
      return;
    impl->setText(text_cpp_value);
  }
}

v8::Local<v8::Value> EditContextInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8EditContextInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8EditContextInit(const EditContextInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8EditContextInitKeys(isolate).data();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto create_property = [dictionary, context, keys, isolate](
                             size_t key_index, v8::Local<v8::Value> value) {
    bool added_property;
    v8::Local<v8::Name> key = keys[key_index].Get(isolate);
    if (!dictionary->CreateDataProperty(context, key, value)
             .To(&added_property)) {
      return false;
    }
    return added_property;
  };

  v8::Local<v8::Value> enter_key_hint_value;
  bool enter_key_hint_has_value_or_default = false;
  if (impl->hasEnterKeyHint()) {
    enter_key_hint_value = V8String(isolate, impl->enterKeyHint());
    enter_key_hint_has_value_or_default = true;
  }
  if (enter_key_hint_has_value_or_default &&
      !create_property(0, enter_key_hint_value)) {
    return false;
  }

  v8::Local<v8::Value> input_mode_value;
  bool input_mode_has_value_or_default = false;
  if (impl->hasInputMode()) {
    input_mode_value = V8String(isolate, impl->inputMode());
    input_mode_has_value_or_default = true;
  }
  if (input_mode_has_value_or_default &&
      !create_property(1, input_mode_value)) {
    return false;
  }

  v8::Local<v8::Value> input_panel_policy_value;
  bool input_panel_policy_has_value_or_default = false;
  if (impl->hasInputPanelPolicy()) {
    input_panel_policy_value = V8String(isolate, impl->inputPanelPolicy());
    input_panel_policy_has_value_or_default = true;
  }
  if (input_panel_policy_has_value_or_default &&
      !create_property(2, input_panel_policy_value)) {
    return false;
  }

  v8::Local<v8::Value> selection_end_value;
  bool selection_end_has_value_or_default = false;
  if (impl->hasSelectionEnd()) {
    selection_end_value = v8::Integer::NewFromUnsigned(isolate, impl->selectionEnd());
    selection_end_has_value_or_default = true;
  }
  if (selection_end_has_value_or_default &&
      !create_property(3, selection_end_value)) {
    return false;
  }

  v8::Local<v8::Value> selection_start_value;
  bool selection_start_has_value_or_default = false;
  if (impl->hasSelectionStart()) {
    selection_start_value = v8::Integer::NewFromUnsigned(isolate, impl->selectionStart());
    selection_start_has_value_or_default = true;
  }
  if (selection_start_has_value_or_default &&
      !create_property(4, selection_start_value)) {
    return false;
  }

  v8::Local<v8::Value> text_value;
  bool text_has_value_or_default = false;
  if (impl->hasText()) {
    text_value = V8String(isolate, impl->text());
    text_has_value_or_default = true;
  }
  if (text_has_value_or_default &&
      !create_property(5, text_value)) {
    return false;
  }

  return true;
}

EditContextInit* NativeValueTraits<EditContextInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  EditContextInit* impl = MakeGarbageCollected<EditContextInit>();
  V8EditContextInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
