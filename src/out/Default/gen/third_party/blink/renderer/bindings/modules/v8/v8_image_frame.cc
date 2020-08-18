// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_image_frame.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_image_bitmap.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ImageFrameExternalKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "complete",
    "duration",
    "image",
    "orientation",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ImageFrameExternal::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ImageFrameExternal* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): complete, duration, image, orientation.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ImageFrameExternalKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> complete_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&complete_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (complete_value.IsEmpty() || complete_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member complete is undefined.");
    return;
  } else {
    bool complete_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, complete_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setComplete(complete_cpp_value);
  }

  v8::Local<v8::Value> duration_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&duration_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (duration_value.IsEmpty() || duration_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member duration is undefined.");
    return;
  } else {
    uint64_t duration_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, duration_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDuration(duration_cpp_value);
  }

  v8::Local<v8::Value> image_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&image_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (image_value.IsEmpty() || image_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member image is undefined.");
    return;
  } else {
    ImageBitmap* image_cpp_value = V8ImageBitmap::ToImplWithTypeCheck(isolate, image_value);
    if (!image_cpp_value) {
      exception_state.ThrowTypeError("member image is not of type ImageBitmap.");
      return;
    }
    impl->setImage(image_cpp_value);
  }

  v8::Local<v8::Value> orientation_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&orientation_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (orientation_value.IsEmpty() || orientation_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member orientation is undefined.");
    return;
  } else {
    uint32_t orientation_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, orientation_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setOrientation(orientation_cpp_value);
  }
}

v8::Local<v8::Value> ImageFrameExternal::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ImageFrameExternal(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ImageFrameExternal(const ImageFrameExternal* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ImageFrameExternalKeys(isolate).data();
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

  v8::Local<v8::Value> complete_value;
  bool complete_has_value_or_default = false;
  if (impl->hasComplete()) {
    complete_value = v8::Boolean::New(isolate, impl->complete());
    complete_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (complete_has_value_or_default &&
      !create_property(0, complete_value)) {
    return false;
  }

  v8::Local<v8::Value> duration_value;
  bool duration_has_value_or_default = false;
  if (impl->hasDuration()) {
    duration_value = v8::Number::New(isolate, static_cast<double>(impl->duration()));
    duration_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (duration_has_value_or_default &&
      !create_property(1, duration_value)) {
    return false;
  }

  v8::Local<v8::Value> image_value;
  bool image_has_value_or_default = false;
  if (impl->hasImage()) {
    image_value = ToV8(impl->image(), creationContext, isolate);
    image_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (image_has_value_or_default &&
      !create_property(2, image_value)) {
    return false;
  }

  v8::Local<v8::Value> orientation_value;
  bool orientation_has_value_or_default = false;
  if (impl->hasOrientation()) {
    orientation_value = v8::Integer::NewFromUnsigned(isolate, impl->orientation());
    orientation_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (orientation_has_value_or_default &&
      !create_property(3, orientation_value)) {
    return false;
  }

  return true;
}

ImageFrameExternal* NativeValueTraits<ImageFrameExternal>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ImageFrameExternal* impl = MakeGarbageCollected<ImageFrameExternal>();
  V8ImageFrameExternal::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
