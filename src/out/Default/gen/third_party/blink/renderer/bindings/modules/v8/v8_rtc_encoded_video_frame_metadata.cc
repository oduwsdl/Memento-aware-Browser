// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_encoded_video_frame_metadata.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8RTCEncodedVideoFrameMetadataKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "contributingSources",
    "dependencies",
    "frameId",
    "height",
    "spatialIndex",
    "synchronizationSource",
    "temporalIndex",
    "width",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8RTCEncodedVideoFrameMetadata::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, RTCEncodedVideoFrameMetadata* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8RTCEncodedVideoFrameMetadataKeys(isolate).data();
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

  v8::Local<v8::Value> dependencies_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&dependencies_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (dependencies_value.IsEmpty() || dependencies_value->IsUndefined()) {
    // Do nothing.
  } else {
    Vector<int64_t> dependencies_cpp_value = NativeValueTraits<IDLSequence<IDLLongLong>>::NativeValue(isolate, dependencies_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDependencies(dependencies_cpp_value);
  }

  v8::Local<v8::Value> frame_id_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&frame_id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (frame_id_value.IsEmpty() || frame_id_value->IsUndefined()) {
    // Do nothing.
  } else {
    int64_t frame_id_cpp_value = NativeValueTraits<IDLLongLong>::NativeValue(isolate, frame_id_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setFrameId(frame_id_cpp_value);
  }

  v8::Local<v8::Value> height_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&height_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (height_value.IsEmpty() || height_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint16_t height_cpp_value = NativeValueTraits<IDLUnsignedShort>::NativeValue(isolate, height_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setHeight(height_cpp_value);
  }

  v8::Local<v8::Value> spatial_index_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&spatial_index_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (spatial_index_value.IsEmpty() || spatial_index_value->IsUndefined()) {
    // Do nothing.
  } else {
    int32_t spatial_index_cpp_value = NativeValueTraits<IDLLong>::NativeValue(isolate, spatial_index_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSpatialIndex(spatial_index_cpp_value);
  }

  v8::Local<v8::Value> synchronization_source_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&synchronization_source_value)) {
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

  v8::Local<v8::Value> temporal_index_value;
  if (!v8Object->Get(context, keys[6].Get(isolate)).ToLocal(&temporal_index_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (temporal_index_value.IsEmpty() || temporal_index_value->IsUndefined()) {
    // Do nothing.
  } else {
    int32_t temporal_index_cpp_value = NativeValueTraits<IDLLong>::NativeValue(isolate, temporal_index_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setTemporalIndex(temporal_index_cpp_value);
  }

  v8::Local<v8::Value> width_value;
  if (!v8Object->Get(context, keys[7].Get(isolate)).ToLocal(&width_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (width_value.IsEmpty() || width_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint16_t width_cpp_value = NativeValueTraits<IDLUnsignedShort>::NativeValue(isolate, width_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setWidth(width_cpp_value);
  }
}

v8::Local<v8::Value> RTCEncodedVideoFrameMetadata::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8RTCEncodedVideoFrameMetadata(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8RTCEncodedVideoFrameMetadata(const RTCEncodedVideoFrameMetadata* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8RTCEncodedVideoFrameMetadataKeys(isolate).data();
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

  v8::Local<v8::Value> dependencies_value;
  bool dependencies_has_value_or_default = false;
  if (impl->hasDependencies()) {
    dependencies_value = ToV8(impl->dependencies(), creationContext, isolate);
    dependencies_has_value_or_default = true;
  }
  if (dependencies_has_value_or_default &&
      !create_property(1, dependencies_value)) {
    return false;
  }

  v8::Local<v8::Value> frame_id_value;
  bool frame_id_has_value_or_default = false;
  if (impl->hasFrameId()) {
    frame_id_value = v8::Number::New(isolate, static_cast<double>(impl->frameId()));
    frame_id_has_value_or_default = true;
  }
  if (frame_id_has_value_or_default &&
      !create_property(2, frame_id_value)) {
    return false;
  }

  v8::Local<v8::Value> height_value;
  bool height_has_value_or_default = false;
  if (impl->hasHeight()) {
    height_value = v8::Integer::NewFromUnsigned(isolate, impl->height());
    height_has_value_or_default = true;
  }
  if (height_has_value_or_default &&
      !create_property(3, height_value)) {
    return false;
  }

  v8::Local<v8::Value> spatial_index_value;
  bool spatial_index_has_value_or_default = false;
  if (impl->hasSpatialIndex()) {
    spatial_index_value = v8::Integer::New(isolate, impl->spatialIndex());
    spatial_index_has_value_or_default = true;
  }
  if (spatial_index_has_value_or_default &&
      !create_property(4, spatial_index_value)) {
    return false;
  }

  v8::Local<v8::Value> synchronization_source_value;
  bool synchronization_source_has_value_or_default = false;
  if (impl->hasSynchronizationSource()) {
    synchronization_source_value = v8::Integer::NewFromUnsigned(isolate, impl->synchronizationSource());
    synchronization_source_has_value_or_default = true;
  }
  if (synchronization_source_has_value_or_default &&
      !create_property(5, synchronization_source_value)) {
    return false;
  }

  v8::Local<v8::Value> temporal_index_value;
  bool temporal_index_has_value_or_default = false;
  if (impl->hasTemporalIndex()) {
    temporal_index_value = v8::Integer::New(isolate, impl->temporalIndex());
    temporal_index_has_value_or_default = true;
  }
  if (temporal_index_has_value_or_default &&
      !create_property(6, temporal_index_value)) {
    return false;
  }

  v8::Local<v8::Value> width_value;
  bool width_has_value_or_default = false;
  if (impl->hasWidth()) {
    width_value = v8::Integer::NewFromUnsigned(isolate, impl->width());
    width_has_value_or_default = true;
  }
  if (width_has_value_or_default &&
      !create_property(7, width_value)) {
    return false;
  }

  return true;
}

RTCEncodedVideoFrameMetadata* NativeValueTraits<RTCEncodedVideoFrameMetadata>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  RTCEncodedVideoFrameMetadata* impl = MakeGarbageCollected<RTCEncodedVideoFrameMetadata>();
  V8RTCEncodedVideoFrameMetadata::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
