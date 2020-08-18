// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_encoded_audio_frame_metadata.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8RTCEncodedAudioFrameMetadataKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "contributingSources",
    "synchronizationSource",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8RTCEncodedAudioFrameMetadata::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, RTCEncodedAudioFrameMetadata* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8RTCEncodedAudioFrameMetadataKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> contributing_sources_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&contributing_sources_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (contributing_sources_value.IsEmpty() || contributing_sources_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<uint32_t> contributing_sources_cpp_value = NativeValueTraits<IDLSequence<IDLUnsignedLong>>::NativeValue(isolate, contributing_sources_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setContributingSources(contributing_sources_cpp_value);
  }

  v8::Local<v8::Value> synchronization_source_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&synchronization_source_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (synchronization_source_value.IsEmpty() || synchronization_source_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t synchronization_source_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, synchronization_source_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSynchronizationSource(synchronization_source_cpp_value);
  }
}

v8::Local<v8::Value> RTCEncodedAudioFrameMetadata::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8RTCEncodedAudioFrameMetadata(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8RTCEncodedAudioFrameMetadata(const RTCEncodedAudioFrameMetadata* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8RTCEncodedAudioFrameMetadataKeys(isolate).data();
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

  v8::Local<v8::Value> contributing_sources_value;
  bool contributing_sources_has_value_or_default = false;
  if (impl->hasContributingSources()) {
    contributing_sources_value = ToV8(impl->contributingSources(), creationContext, isolate);
    contributing_sources_has_value_or_default = true;
  }
  if (contributing_sources_has_value_or_default &&
      !create_property(0, contributing_sources_value)) {
    return false;
  }

  v8::Local<v8::Value> synchronization_source_value;
  bool synchronization_source_has_value_or_default = false;
  if (impl->hasSynchronizationSource()) {
    synchronization_source_value = v8::Integer::NewFromUnsigned(isolate, impl->synchronizationSource());
    synchronization_source_has_value_or_default = true;
  }
  if (synchronization_source_has_value_or_default &&
      !create_property(1, synchronization_source_value)) {
    return false;
  }

  return true;
}

RTCEncodedAudioFrameMetadata* NativeValueTraits<RTCEncodedAudioFrameMetadata>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  RTCEncodedAudioFrameMetadata* impl = MakeGarbageCollected<RTCEncodedAudioFrameMetadata>();
  V8RTCEncodedAudioFrameMetadata::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
