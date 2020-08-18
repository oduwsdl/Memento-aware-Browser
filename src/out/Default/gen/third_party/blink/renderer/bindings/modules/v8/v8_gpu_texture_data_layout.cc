// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_texture_data_layout.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8GPUTextureDataLayoutKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "bytesPerRow",
    "offset",
    "rowsPerImage",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8GPUTextureDataLayout::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPUTextureDataLayout* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): bytesPerRow.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8GPUTextureDataLayoutKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> bytes_per_row_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&bytes_per_row_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (bytes_per_row_value.IsEmpty() || bytes_per_row_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member bytesPerRow is undefined.");
    return;
  } else {
    uint32_t bytes_per_row_cpp_value = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(isolate, bytes_per_row_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setBytesPerRow(bytes_per_row_cpp_value);
  }

  v8::Local<v8::Value> offset_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&offset_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (offset_value.IsEmpty() || offset_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t offset_cpp_value = NativeValueTraits<IDLUnsignedLongLongEnforceRange>::NativeValue(isolate, offset_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setOffset(offset_cpp_value);
  }

  v8::Local<v8::Value> rows_per_image_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&rows_per_image_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (rows_per_image_value.IsEmpty() || rows_per_image_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t rows_per_image_cpp_value = NativeValueTraits<IDLUnsignedLongEnforceRange>::NativeValue(isolate, rows_per_image_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRowsPerImage(rows_per_image_cpp_value);
  }
}

v8::Local<v8::Value> GPUTextureDataLayout::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPUTextureDataLayout(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPUTextureDataLayout(const GPUTextureDataLayout* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8GPUTextureDataLayoutKeys(isolate).data();
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

  v8::Local<v8::Value> bytes_per_row_value;
  bool bytes_per_row_has_value_or_default = false;
  if (impl->hasBytesPerRow()) {
    bytes_per_row_value = v8::Integer::NewFromUnsigned(isolate, impl->bytesPerRow());
    bytes_per_row_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (bytes_per_row_has_value_or_default &&
      !create_property(0, bytes_per_row_value)) {
    return false;
  }

  v8::Local<v8::Value> offset_value;
  bool offset_has_value_or_default = false;
  if (impl->hasOffset()) {
    offset_value = v8::Number::New(isolate, static_cast<double>(impl->offset()));
    offset_has_value_or_default = true;
  } else {
    offset_value = v8::Number::New(isolate, static_cast<double>(0));
    offset_has_value_or_default = true;
  }
  if (offset_has_value_or_default &&
      !create_property(1, offset_value)) {
    return false;
  }

  v8::Local<v8::Value> rows_per_image_value;
  bool rows_per_image_has_value_or_default = false;
  if (impl->hasRowsPerImage()) {
    rows_per_image_value = v8::Integer::NewFromUnsigned(isolate, impl->rowsPerImage());
    rows_per_image_has_value_or_default = true;
  } else {
    rows_per_image_value = v8::Integer::NewFromUnsigned(isolate, 0u);
    rows_per_image_has_value_or_default = true;
  }
  if (rows_per_image_has_value_or_default &&
      !create_property(2, rows_per_image_value)) {
    return false;
  }

  return true;
}

GPUTextureDataLayout* NativeValueTraits<GPUTextureDataLayout>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPUTextureDataLayout* impl = MakeGarbageCollected<GPUTextureDataLayout>();
  V8GPUTextureDataLayout::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
