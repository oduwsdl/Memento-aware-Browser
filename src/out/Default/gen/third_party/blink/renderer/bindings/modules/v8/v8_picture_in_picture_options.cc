// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_picture_in_picture_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8PictureInPictureOptionsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "height",
    "interactive",
    "width",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8PictureInPictureOptions::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, PictureInPictureOptions* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8PictureInPictureOptionsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> height_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&height_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (height_value.IsEmpty() || height_value->IsUndefined()) {
    // Do nothing.
  } else {
    int32_t height_cpp_value = NativeValueTraits<IDLLong>::NativeValue(isolate, height_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setHeight(height_cpp_value);
  }

  v8::Local<v8::Value> interactive_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&interactive_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (interactive_value.IsEmpty() || interactive_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool interactive_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, interactive_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setInteractive(interactive_cpp_value);
  }

  v8::Local<v8::Value> width_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&width_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (width_value.IsEmpty() || width_value->IsUndefined()) {
    // Do nothing.
  } else {
    int32_t width_cpp_value = NativeValueTraits<IDLLong>::NativeValue(isolate, width_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setWidth(width_cpp_value);
  }
}

v8::Local<v8::Value> PictureInPictureOptions::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8PictureInPictureOptions(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8PictureInPictureOptions(const PictureInPictureOptions* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8PictureInPictureOptionsKeys(isolate).data();
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

  v8::Local<v8::Value> height_value;
  bool height_has_value_or_default = false;
  if (impl->hasHeight()) {
    height_value = v8::Integer::New(isolate, impl->height());
    height_has_value_or_default = true;
  }
  if (height_has_value_or_default &&
      !create_property(0, height_value)) {
    return false;
  }

  v8::Local<v8::Value> interactive_value;
  bool interactive_has_value_or_default = false;
  if (impl->hasInteractive()) {
    interactive_value = v8::Boolean::New(isolate, impl->interactive());
    interactive_has_value_or_default = true;
  } else {
    interactive_value = v8::Boolean::New(isolate, false);
    interactive_has_value_or_default = true;
  }
  if (interactive_has_value_or_default &&
      !create_property(1, interactive_value)) {
    return false;
  }

  v8::Local<v8::Value> width_value;
  bool width_has_value_or_default = false;
  if (impl->hasWidth()) {
    width_value = v8::Integer::New(isolate, impl->width());
    width_has_value_or_default = true;
  }
  if (width_has_value_or_default &&
      !create_property(2, width_value)) {
    return false;
  }

  return true;
}

PictureInPictureOptions* NativeValueTraits<PictureInPictureOptions>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  PictureInPictureOptions* impl = MakeGarbageCollected<PictureInPictureOptions>();
  V8PictureInPictureOptions::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
