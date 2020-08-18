// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_video_frame_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8VideoFrameInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "duration",
    "timestamp",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8VideoFrameInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, VideoFrameInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8VideoFrameInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> duration_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&duration_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (duration_value.IsEmpty() || duration_value->IsUndefined()) {
    // Do nothing.
  } else if (duration_value->IsNull()) {
    impl->setDurationToNull();
  } else {
    uint64_t duration_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, duration_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDuration(duration_cpp_value);
  }

  v8::Local<v8::Value> timestamp_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&timestamp_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (timestamp_value.IsEmpty() || timestamp_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t timestamp_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, timestamp_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setTimestamp(timestamp_cpp_value);
  }
}

v8::Local<v8::Value> VideoFrameInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8VideoFrameInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8VideoFrameInit(const VideoFrameInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8VideoFrameInitKeys(isolate).data();
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

  v8::Local<v8::Value> duration_value;
  bool duration_has_value_or_default = false;
  if (impl->hasDuration()) {
    duration_value = v8::Number::New(isolate, static_cast<double>(impl->duration()));
    duration_has_value_or_default = true;
  } else {
    duration_value = v8::Null(isolate);
    duration_has_value_or_default = true;
  }
  if (duration_has_value_or_default &&
      !create_property(0, duration_value)) {
    return false;
  }

  v8::Local<v8::Value> timestamp_value;
  bool timestamp_has_value_or_default = false;
  if (impl->hasTimestamp()) {
    timestamp_value = v8::Number::New(isolate, static_cast<double>(impl->timestamp()));
    timestamp_has_value_or_default = true;
  }
  if (timestamp_has_value_or_default &&
      !create_property(1, timestamp_value)) {
    return false;
  }

  return true;
}

VideoFrameInit* NativeValueTraits<VideoFrameInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  VideoFrameInit* impl = MakeGarbageCollected<VideoFrameInit>();
  V8VideoFrameInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
