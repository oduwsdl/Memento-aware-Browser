// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_ndef_record_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_ndef_message_init.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8NDEFRecordInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "data",
    "encoding",
    "id",
    "lang",
    "mediaType",
    "recordType",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8NDEFRecordInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, NDEFRecordInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): recordType.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8NDEFRecordInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> data_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&data_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (data_value.IsEmpty() || data_value->IsUndefined()) {
    // Do nothing.
  } else {
    StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit data_cpp_value;
    V8StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit::ToImpl(isolate, data_value, data_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setData(data_cpp_value);
  }

  v8::Local<v8::Value> encoding_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&encoding_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (encoding_value.IsEmpty() || encoding_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> encoding_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, encoding_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setEncoding(encoding_cpp_value);
  }

  v8::Local<v8::Value> id_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (id_value.IsEmpty() || id_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> id_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, id_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setId(id_cpp_value);
  }

  v8::Local<v8::Value> lang_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&lang_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (lang_value.IsEmpty() || lang_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> lang_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, lang_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setLang(lang_cpp_value);
  }

  v8::Local<v8::Value> media_type_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&media_type_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (media_type_value.IsEmpty() || media_type_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> media_type_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, media_type_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setMediaType(media_type_cpp_value);
  }

  v8::Local<v8::Value> record_type_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&record_type_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (record_type_value.IsEmpty() || record_type_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member recordType is undefined.");
    return;
  } else {
    V8StringResource<> record_type_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, record_type_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRecordType(record_type_cpp_value);
  }
}

v8::Local<v8::Value> NDEFRecordInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8NDEFRecordInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8NDEFRecordInit(const NDEFRecordInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8NDEFRecordInitKeys(isolate).data();
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

  v8::Local<v8::Value> data_value;
  bool data_has_value_or_default = false;
  if (impl->hasData()) {
    data_value = ToV8(impl->data(), creationContext, isolate);
    data_has_value_or_default = true;
  }
  if (data_has_value_or_default &&
      !create_property(0, data_value)) {
    return false;
  }

  v8::Local<v8::Value> encoding_value;
  bool encoding_has_value_or_default = false;
  if (impl->hasEncoding()) {
    encoding_value = V8String(isolate, impl->encoding());
    encoding_has_value_or_default = true;
  }
  if (encoding_has_value_or_default &&
      !create_property(1, encoding_value)) {
    return false;
  }

  v8::Local<v8::Value> id_value;
  bool id_has_value_or_default = false;
  if (impl->hasId()) {
    id_value = V8String(isolate, impl->id());
    id_has_value_or_default = true;
  }
  if (id_has_value_or_default &&
      !create_property(2, id_value)) {
    return false;
  }

  v8::Local<v8::Value> lang_value;
  bool lang_has_value_or_default = false;
  if (impl->hasLang()) {
    lang_value = V8String(isolate, impl->lang());
    lang_has_value_or_default = true;
  }
  if (lang_has_value_or_default &&
      !create_property(3, lang_value)) {
    return false;
  }

  v8::Local<v8::Value> media_type_value;
  bool media_type_has_value_or_default = false;
  if (impl->hasMediaType()) {
    media_type_value = V8String(isolate, impl->mediaType());
    media_type_has_value_or_default = true;
  }
  if (media_type_has_value_or_default &&
      !create_property(4, media_type_value)) {
    return false;
  }

  v8::Local<v8::Value> record_type_value;
  bool record_type_has_value_or_default = false;
  if (impl->hasRecordType()) {
    record_type_value = V8String(isolate, impl->recordType());
    record_type_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (record_type_has_value_or_default &&
      !create_property(5, record_type_value)) {
    return false;
  }

  return true;
}

NDEFRecordInit* NativeValueTraits<NDEFRecordInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  NDEFRecordInit* impl = MakeGarbageCollected<NDEFRecordInit>();
  V8NDEFRecordInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
