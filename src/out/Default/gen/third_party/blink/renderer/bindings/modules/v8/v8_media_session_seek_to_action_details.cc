// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_media_session_seek_to_action_details.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_media_session_action_details.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8MediaSessionSeekToActionDetailsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "fastSeek",
    "seekTime",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8MediaSessionSeekToActionDetails::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, MediaSessionSeekToActionDetails* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): seekTime.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  V8MediaSessionActionDetails::ToImpl(isolate, v8_value, impl, exception_state);
  if (exception_state.HadException())
    return;

  const auto* keys = eternalV8MediaSessionSeekToActionDetailsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> fast_seek_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&fast_seek_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (fast_seek_value.IsEmpty() || fast_seek_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool fast_seek_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, fast_seek_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setFastSeek(fast_seek_cpp_value);
  }

  v8::Local<v8::Value> seek_time_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&seek_time_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (seek_time_value.IsEmpty() || seek_time_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member seekTime is undefined.");
    return;
  } else {
    double seek_time_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, seek_time_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSeekTime(seek_time_cpp_value);
  }
}

v8::Local<v8::Value> MediaSessionSeekToActionDetails::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8MediaSessionSeekToActionDetails(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8MediaSessionSeekToActionDetails(const MediaSessionSeekToActionDetails* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8MediaSessionActionDetails(impl, dictionary, creationContext, isolate))
    return false;

  const auto* keys = eternalV8MediaSessionSeekToActionDetailsKeys(isolate).data();
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

  v8::Local<v8::Value> fast_seek_value;
  bool fast_seek_has_value_or_default = false;
  if (impl->hasFastSeek()) {
    fast_seek_value = v8::Boolean::New(isolate, impl->fastSeek());
    fast_seek_has_value_or_default = true;
  }
  if (fast_seek_has_value_or_default &&
      !create_property(0, fast_seek_value)) {
    return false;
  }

  v8::Local<v8::Value> seek_time_value;
  bool seek_time_has_value_or_default = false;
  if (impl->hasSeekTime()) {
    seek_time_value = v8::Number::New(isolate, impl->seekTime());
    seek_time_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (seek_time_has_value_or_default &&
      !create_property(1, seek_time_value)) {
    return false;
  }

  return true;
}

MediaSessionSeekToActionDetails* NativeValueTraits<MediaSessionSeekToActionDetails>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  MediaSessionSeekToActionDetails* impl = MakeGarbageCollected<MediaSessionSeekToActionDetails>();
  V8MediaSessionSeekToActionDetails::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
