// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_image_bitmap_copy_view.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_image_bitmap.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_origin_2d_dict.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8GPUImageBitmapCopyViewKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "imageBitmap",
    "origin",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8GPUImageBitmapCopyView::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPUImageBitmapCopyView* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): imageBitmap.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8GPUImageBitmapCopyViewKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> image_bitmap_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&image_bitmap_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (image_bitmap_value.IsEmpty() || image_bitmap_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member imageBitmap is undefined.");
    return;
  } else {
    ImageBitmap* image_bitmap_cpp_value = V8ImageBitmap::ToImplWithTypeCheck(isolate, image_bitmap_value);
    if (!image_bitmap_cpp_value) {
      exception_state.ThrowTypeError("member imageBitmap is not of type ImageBitmap.");
      return;
    }
    impl->setImageBitmap(image_bitmap_cpp_value);
  }

  v8::Local<v8::Value> origin_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&origin_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (origin_value.IsEmpty() || origin_value->IsUndefined()) {
    // Do nothing.
  } else {
    UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict origin_cpp_value;
    V8UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::ToImpl(isolate, origin_value, origin_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setOrigin(origin_cpp_value);
  }
}

v8::Local<v8::Value> GPUImageBitmapCopyView::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPUImageBitmapCopyView(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPUImageBitmapCopyView(const GPUImageBitmapCopyView* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8GPUImageBitmapCopyViewKeys(isolate).data();
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

  v8::Local<v8::Value> image_bitmap_value;
  bool image_bitmap_has_value_or_default = false;
  if (impl->hasImageBitmap()) {
    image_bitmap_value = ToV8(impl->imageBitmap(), creationContext, isolate);
    image_bitmap_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (image_bitmap_has_value_or_default &&
      !create_property(0, image_bitmap_value)) {
    return false;
  }

  v8::Local<v8::Value> origin_value;
  bool origin_has_value_or_default = false;
  if (impl->hasOrigin()) {
    origin_value = ToV8(impl->origin(), creationContext, isolate);
    origin_has_value_or_default = true;
  } else {
    origin_value = ToV8(UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::FromGPUOrigin2DDict(MakeGarbageCollected<GPUOrigin2DDict>()), creationContext, isolate);
    origin_has_value_or_default = true;
  }
  if (origin_has_value_or_default &&
      !create_property(1, origin_value)) {
    return false;
  }

  return true;
}

GPUImageBitmapCopyView* NativeValueTraits<GPUImageBitmapCopyView>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPUImageBitmapCopyView* impl = MakeGarbageCollected<GPUImageBitmapCopyView>();
  V8GPUImageBitmapCopyView::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
