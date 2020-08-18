// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_encoded_video_config.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8EncodedVideoConfigKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "codec",
    "description",
    "sampleAspect",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8EncodedVideoConfig::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, EncodedVideoConfig* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): codec.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8EncodedVideoConfigKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> codec_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&codec_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (codec_value.IsEmpty() || codec_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member codec is undefined.");
    return;
  } else {
    V8StringResource<> codec_cpp_value = codec_value;
    if (!codec_cpp_value.Prepare(exception_state))
      return;
    impl->setCodec(codec_cpp_value);
  }

  v8::Local<v8::Value> description_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&description_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (description_value.IsEmpty() || description_value->IsUndefined()) {
    // Do nothing.
  } else {
    ArrayBufferOrArrayBufferView description_cpp_value;
    V8ArrayBufferOrArrayBufferView::ToImpl(isolate, description_value, description_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDescription(description_cpp_value);
  }

  v8::Local<v8::Value> sample_aspect_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&sample_aspect_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (sample_aspect_value.IsEmpty() || sample_aspect_value->IsUndefined()) {
    // Do nothing.
  } else {
    double sample_aspect_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, sample_aspect_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSampleAspect(sample_aspect_cpp_value);
  }
}

v8::Local<v8::Value> EncodedVideoConfig::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8EncodedVideoConfig(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8EncodedVideoConfig(const EncodedVideoConfig* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8EncodedVideoConfigKeys(isolate).data();
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

  v8::Local<v8::Value> codec_value;
  bool codec_has_value_or_default = false;
  if (impl->hasCodec()) {
    codec_value = V8String(isolate, impl->codec());
    codec_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (codec_has_value_or_default &&
      !create_property(0, codec_value)) {
    return false;
  }

  v8::Local<v8::Value> description_value;
  bool description_has_value_or_default = false;
  if (impl->hasDescription()) {
    description_value = ToV8(impl->description(), creationContext, isolate);
    description_has_value_or_default = true;
  }
  if (description_has_value_or_default &&
      !create_property(1, description_value)) {
    return false;
  }

  v8::Local<v8::Value> sample_aspect_value;
  bool sample_aspect_has_value_or_default = false;
  if (impl->hasSampleAspect()) {
    sample_aspect_value = v8::Number::New(isolate, impl->sampleAspect());
    sample_aspect_has_value_or_default = true;
  }
  if (sample_aspect_has_value_or_default &&
      !create_property(2, sample_aspect_value)) {
    return false;
  }

  return true;
}

EncodedVideoConfig* NativeValueTraits<EncodedVideoConfig>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  EncodedVideoConfig* impl = MakeGarbageCollected<EncodedVideoConfig>();
  V8EncodedVideoConfig::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
