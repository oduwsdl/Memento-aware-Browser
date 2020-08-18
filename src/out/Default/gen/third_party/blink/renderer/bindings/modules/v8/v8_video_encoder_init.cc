// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_video_encoder_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_video_encoder_output_callback.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_web_codecs_error_callback.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8VideoEncoderInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "error",
    "output",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8VideoEncoderInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, VideoEncoderInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): output.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8VideoEncoderInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> error_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&error_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (error_value.IsEmpty() || error_value->IsUndefined()) {
    // Do nothing.
  } else {
    if (!error_value->IsFunction()) {
      exception_state.ThrowTypeError("member error is not a function.");
      return;
    }
    V8WebCodecsErrorCallback* error_cpp_value = V8WebCodecsErrorCallback::Create(error_value.As<v8::Function>());
    impl->setError(error_cpp_value);
  }

  v8::Local<v8::Value> output_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&output_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (output_value.IsEmpty() || output_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member output is undefined.");
    return;
  } else {
    if (!output_value->IsFunction()) {
      exception_state.ThrowTypeError("member output is not a function.");
      return;
    }
    V8VideoEncoderOutputCallback* output_cpp_value = V8VideoEncoderOutputCallback::Create(output_value.As<v8::Function>());
    impl->setOutput(output_cpp_value);
  }
}

v8::Local<v8::Value> VideoEncoderInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8VideoEncoderInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8VideoEncoderInit(const VideoEncoderInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8VideoEncoderInitKeys(isolate).data();
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

  v8::Local<v8::Value> error_value;
  bool error_has_value_or_default = false;
  if (impl->hasError()) {
    error_value = ToV8(impl->error(), creationContext, isolate);
    error_has_value_or_default = true;
  }
  if (error_has_value_or_default &&
      !create_property(0, error_value)) {
    return false;
  }

  v8::Local<v8::Value> output_value;
  bool output_has_value_or_default = false;
  if (impl->hasOutput()) {
    output_value = ToV8(impl->output(), creationContext, isolate);
    output_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (output_has_value_or_default &&
      !create_property(1, output_value)) {
    return false;
  }

  return true;
}

VideoEncoderInit* NativeValueTraits<VideoEncoderInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  VideoEncoderInit* impl = MakeGarbageCollected<VideoEncoderInit>();
  V8VideoEncoderInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
