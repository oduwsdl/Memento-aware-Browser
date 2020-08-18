// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_video_encoder_config.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8VideoEncoderConfigKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "bitrate",
    "codec",
    "framerate",
    "height",
    "profile",
    "width",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8VideoEncoderConfig::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, VideoEncoderConfig* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): codec, height, width.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8VideoEncoderConfigKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> bitrate_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&bitrate_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (bitrate_value.IsEmpty() || bitrate_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t bitrate_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, bitrate_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setBitrate(bitrate_cpp_value);
  }

  v8::Local<v8::Value> codec_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&codec_value)) {
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

  v8::Local<v8::Value> framerate_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&framerate_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (framerate_value.IsEmpty() || framerate_value->IsUndefined()) {
    // Do nothing.
  } else {
    double framerate_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, framerate_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setFramerate(framerate_cpp_value);
  }

  v8::Local<v8::Value> height_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&height_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (height_value.IsEmpty() || height_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member height is undefined.");
    return;
  } else {
    uint32_t height_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, height_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setHeight(height_cpp_value);
  }

  v8::Local<v8::Value> profile_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&profile_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (profile_value.IsEmpty() || profile_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> profile_cpp_value = profile_value;
    if (!profile_cpp_value.Prepare(exception_state))
      return;
    impl->setProfile(profile_cpp_value);
  }

  v8::Local<v8::Value> width_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&width_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (width_value.IsEmpty() || width_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member width is undefined.");
    return;
  } else {
    uint32_t width_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, width_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setWidth(width_cpp_value);
  }
}

v8::Local<v8::Value> VideoEncoderConfig::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8VideoEncoderConfig(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8VideoEncoderConfig(const VideoEncoderConfig* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8VideoEncoderConfigKeys(isolate).data();
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

  v8::Local<v8::Value> bitrate_value;
  bool bitrate_has_value_or_default = false;
  if (impl->hasBitrate()) {
    bitrate_value = v8::Number::New(isolate, static_cast<double>(impl->bitrate()));
    bitrate_has_value_or_default = true;
  }
  if (bitrate_has_value_or_default &&
      !create_property(0, bitrate_value)) {
    return false;
  }

  v8::Local<v8::Value> codec_value;
  bool codec_has_value_or_default = false;
  if (impl->hasCodec()) {
    codec_value = V8String(isolate, impl->codec());
    codec_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (codec_has_value_or_default &&
      !create_property(1, codec_value)) {
    return false;
  }

  v8::Local<v8::Value> framerate_value;
  bool framerate_has_value_or_default = false;
  if (impl->hasFramerate()) {
    framerate_value = v8::Number::New(isolate, impl->framerate());
    framerate_has_value_or_default = true;
  }
  if (framerate_has_value_or_default &&
      !create_property(2, framerate_value)) {
    return false;
  }

  v8::Local<v8::Value> height_value;
  bool height_has_value_or_default = false;
  if (impl->hasHeight()) {
    height_value = v8::Integer::NewFromUnsigned(isolate, impl->height());
    height_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (height_has_value_or_default &&
      !create_property(3, height_value)) {
    return false;
  }

  v8::Local<v8::Value> profile_value;
  bool profile_has_value_or_default = false;
  if (impl->hasProfile()) {
    profile_value = V8String(isolate, impl->profile());
    profile_has_value_or_default = true;
  }
  if (profile_has_value_or_default &&
      !create_property(4, profile_value)) {
    return false;
  }

  v8::Local<v8::Value> width_value;
  bool width_has_value_or_default = false;
  if (impl->hasWidth()) {
    width_value = v8::Integer::NewFromUnsigned(isolate, impl->width());
    width_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (width_has_value_or_default &&
      !create_property(5, width_value)) {
    return false;
  }

  return true;
}

VideoEncoderConfig* NativeValueTraits<VideoEncoderConfig>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  VideoEncoderConfig* impl = MakeGarbageCollected<VideoEncoderConfig>();
  V8VideoEncoderConfig::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
