// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_text_update_event_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8TextUpdateEventInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "newSelectionEnd",
    "newSelectionStart",
    "updateRangeEnd",
    "updateRangeStart",
    "updateText",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8TextUpdateEventInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, TextUpdateEventInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8TextUpdateEventInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> new_selection_end_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&new_selection_end_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (new_selection_end_value.IsEmpty() || new_selection_end_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t new_selection_end_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, new_selection_end_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setNewSelectionEnd(new_selection_end_cpp_value);
  }

  v8::Local<v8::Value> new_selection_start_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&new_selection_start_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (new_selection_start_value.IsEmpty() || new_selection_start_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t new_selection_start_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, new_selection_start_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setNewSelectionStart(new_selection_start_cpp_value);
  }

  v8::Local<v8::Value> update_range_end_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&update_range_end_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (update_range_end_value.IsEmpty() || update_range_end_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t update_range_end_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, update_range_end_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setUpdateRangeEnd(update_range_end_cpp_value);
  }

  v8::Local<v8::Value> update_range_start_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&update_range_start_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (update_range_start_value.IsEmpty() || update_range_start_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t update_range_start_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, update_range_start_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setUpdateRangeStart(update_range_start_cpp_value);
  }

  v8::Local<v8::Value> update_text_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&update_text_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (update_text_value.IsEmpty() || update_text_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> update_text_cpp_value = update_text_value;
    if (!update_text_cpp_value.Prepare(exception_state))
      return;
    impl->setUpdateText(update_text_cpp_value);
  }
}

v8::Local<v8::Value> TextUpdateEventInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8TextUpdateEventInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8TextUpdateEventInit(const TextUpdateEventInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8TextUpdateEventInitKeys(isolate).data();
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

  v8::Local<v8::Value> new_selection_end_value;
  bool new_selection_end_has_value_or_default = false;
  if (impl->hasNewSelectionEnd()) {
    new_selection_end_value = v8::Integer::NewFromUnsigned(isolate, impl->newSelectionEnd());
    new_selection_end_has_value_or_default = true;
  }
  if (new_selection_end_has_value_or_default &&
      !create_property(0, new_selection_end_value)) {
    return false;
  }

  v8::Local<v8::Value> new_selection_start_value;
  bool new_selection_start_has_value_or_default = false;
  if (impl->hasNewSelectionStart()) {
    new_selection_start_value = v8::Integer::NewFromUnsigned(isolate, impl->newSelectionStart());
    new_selection_start_has_value_or_default = true;
  }
  if (new_selection_start_has_value_or_default &&
      !create_property(1, new_selection_start_value)) {
    return false;
  }

  v8::Local<v8::Value> update_range_end_value;
  bool update_range_end_has_value_or_default = false;
  if (impl->hasUpdateRangeEnd()) {
    update_range_end_value = v8::Integer::NewFromUnsigned(isolate, impl->updateRangeEnd());
    update_range_end_has_value_or_default = true;
  }
  if (update_range_end_has_value_or_default &&
      !create_property(2, update_range_end_value)) {
    return false;
  }

  v8::Local<v8::Value> update_range_start_value;
  bool update_range_start_has_value_or_default = false;
  if (impl->hasUpdateRangeStart()) {
    update_range_start_value = v8::Integer::NewFromUnsigned(isolate, impl->updateRangeStart());
    update_range_start_has_value_or_default = true;
  }
  if (update_range_start_has_value_or_default &&
      !create_property(3, update_range_start_value)) {
    return false;
  }

  v8::Local<v8::Value> update_text_value;
  bool update_text_has_value_or_default = false;
  if (impl->hasUpdateText()) {
    update_text_value = V8String(isolate, impl->updateText());
    update_text_has_value_or_default = true;
  }
  if (update_text_has_value_or_default &&
      !create_property(4, update_text_value)) {
    return false;
  }

  return true;
}

TextUpdateEventInit* NativeValueTraits<TextUpdateEventInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  TextUpdateEventInit* impl = MakeGarbageCollected<TextUpdateEventInit>();
  V8TextUpdateEventInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
