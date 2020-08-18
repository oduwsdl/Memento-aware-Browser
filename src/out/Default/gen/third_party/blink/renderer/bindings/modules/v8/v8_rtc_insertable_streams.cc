// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_insertable_streams.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_readable_stream.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_writable_stream.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8RTCInsertableStreamsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "readableStream",
    "writableStream",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8RTCInsertableStreams::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, RTCInsertableStreams* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8RTCInsertableStreamsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> readable_stream_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&readable_stream_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (readable_stream_value.IsEmpty() || readable_stream_value->IsUndefined()) {
    // Do nothing.
  } else {
    ReadableStream* readable_stream_cpp_value = V8ReadableStream::ToImplWithTypeCheck(isolate, readable_stream_value);
    if (!readable_stream_cpp_value) {
      exception_state.ThrowTypeError("member readableStream is not of type ReadableStream.");
      return;
    }
    impl->setReadableStream(readable_stream_cpp_value);
  }

  v8::Local<v8::Value> writable_stream_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&writable_stream_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (writable_stream_value.IsEmpty() || writable_stream_value->IsUndefined()) {
    // Do nothing.
  } else {
    WritableStream* writable_stream_cpp_value = V8WritableStream::ToImplWithTypeCheck(isolate, writable_stream_value);
    if (!writable_stream_cpp_value) {
      exception_state.ThrowTypeError("member writableStream is not of type WritableStream.");
      return;
    }
    impl->setWritableStream(writable_stream_cpp_value);
  }
}

v8::Local<v8::Value> RTCInsertableStreams::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8RTCInsertableStreams(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8RTCInsertableStreams(const RTCInsertableStreams* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8RTCInsertableStreamsKeys(isolate).data();
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

  v8::Local<v8::Value> readable_stream_value;
  bool readable_stream_has_value_or_default = false;
  if (impl->hasReadableStream()) {
    readable_stream_value = ToV8(impl->readableStream(), creationContext, isolate);
    readable_stream_has_value_or_default = true;
  }
  if (readable_stream_has_value_or_default &&
      !create_property(0, readable_stream_value)) {
    return false;
  }

  v8::Local<v8::Value> writable_stream_value;
  bool writable_stream_has_value_or_default = false;
  if (impl->hasWritableStream()) {
    writable_stream_value = ToV8(impl->writableStream(), creationContext, isolate);
    writable_stream_has_value_or_default = true;
  }
  if (writable_stream_has_value_or_default &&
      !create_property(1, writable_stream_value)) {
    return false;
  }

  return true;
}

RTCInsertableStreams* NativeValueTraits<RTCInsertableStreams>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  RTCInsertableStreams* impl = MakeGarbageCollected<RTCInsertableStreams>();
  V8RTCInsertableStreams::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
