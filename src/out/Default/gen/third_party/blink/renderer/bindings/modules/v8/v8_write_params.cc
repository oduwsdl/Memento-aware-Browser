// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_write_params.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_array_buffer_view.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_blob.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/flexible_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8WriteParamsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "data",
    "position",
    "size",
    "type",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8WriteParams::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, WriteParams* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): type.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8WriteParamsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> data_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&data_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (data_value.IsEmpty() || data_value->IsUndefined()) {
    // Do nothing.
  } else if (data_value->IsNull()) {
    impl->setDataToNull();
  } else {
    ArrayBufferOrArrayBufferViewOrBlobOrUSVString data_cpp_value;
    V8ArrayBufferOrArrayBufferViewOrBlobOrUSVString::ToImpl(isolate, data_value, data_cpp_value, UnionTypeConversionMode::kNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setData(data_cpp_value);
  }

  v8::Local<v8::Value> position_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&position_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (position_value.IsEmpty() || position_value->IsUndefined()) {
    // Do nothing.
  } else if (position_value->IsNull()) {
    impl->setPositionToNull();
  } else {
    uint64_t position_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, position_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setPosition(position_cpp_value);
  }

  v8::Local<v8::Value> size_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&size_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (size_value.IsEmpty() || size_value->IsUndefined()) {
    // Do nothing.
  } else if (size_value->IsNull()) {
    impl->setSizeToNull();
  } else {
    uint64_t size_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, size_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setSize(size_cpp_value);
  }

  v8::Local<v8::Value> type_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&type_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (type_value.IsEmpty() || type_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member type is undefined.");
    return;
  } else {
    V8StringResource<> type_cpp_value = type_value;
    if (!type_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "truncate",
        "seek",
        "write",
    };
    if (!IsValidEnum(type_cpp_value, kValidValues, base::size(kValidValues), "WriteCommandType", exception_state))
      return;
    impl->setType(type_cpp_value);
  }
}

v8::Local<v8::Value> WriteParams::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8WriteParams(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8WriteParams(const WriteParams* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8WriteParamsKeys(isolate).data();
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
  } else {
    data_value = v8::Null(isolate);
    data_has_value_or_default = true;
  }
  if (data_has_value_or_default &&
      !create_property(0, data_value)) {
    return false;
  }

  v8::Local<v8::Value> position_value;
  bool position_has_value_or_default = false;
  if (impl->hasPosition()) {
    position_value = v8::Number::New(isolate, static_cast<double>(impl->position()));
    position_has_value_or_default = true;
  } else {
    position_value = v8::Null(isolate);
    position_has_value_or_default = true;
  }
  if (position_has_value_or_default &&
      !create_property(1, position_value)) {
    return false;
  }

  v8::Local<v8::Value> size_value;
  bool size_has_value_or_default = false;
  if (impl->hasSize()) {
    size_value = v8::Number::New(isolate, static_cast<double>(impl->size()));
    size_has_value_or_default = true;
  } else {
    size_value = v8::Null(isolate);
    size_has_value_or_default = true;
  }
  if (size_has_value_or_default &&
      !create_property(2, size_value)) {
    return false;
  }

  v8::Local<v8::Value> type_value;
  bool type_has_value_or_default = false;
  if (impl->hasType()) {
    type_value = V8String(isolate, impl->type());
    type_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (type_has_value_or_default &&
      !create_property(3, type_value)) {
    return false;
  }

  return true;
}

WriteParams* NativeValueTraits<WriteParams>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  WriteParams* impl = MakeGarbageCollected<WriteParams>();
  V8WriteParams::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
