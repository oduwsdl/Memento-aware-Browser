// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_profiler_frame.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ProfilerFrameKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "column",
    "line",
    "name",
    "resourceId",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ProfilerFrame::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ProfilerFrame* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): name.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ProfilerFrameKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> column_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&column_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (column_value.IsEmpty() || column_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t column_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, column_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setColumn(column_cpp_value);
  }

  v8::Local<v8::Value> line_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&line_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (line_value.IsEmpty() || line_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t line_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, line_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setLine(line_cpp_value);
  }

  v8::Local<v8::Value> name_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&name_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (name_value.IsEmpty() || name_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member name is undefined.");
    return;
  } else {
    V8StringResource<> name_cpp_value = name_value;
    if (!name_cpp_value.Prepare(exception_state))
      return;
    impl->setName(name_cpp_value);
  }

  v8::Local<v8::Value> resource_id_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&resource_id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (resource_id_value.IsEmpty() || resource_id_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint64_t resource_id_cpp_value = NativeValueTraits<IDLUnsignedLongLong>::NativeValue(isolate, resource_id_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setResourceId(resource_id_cpp_value);
  }
}

v8::Local<v8::Value> ProfilerFrame::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ProfilerFrame(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ProfilerFrame(const ProfilerFrame* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ProfilerFrameKeys(isolate).data();
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

  v8::Local<v8::Value> column_value;
  bool column_has_value_or_default = false;
  if (impl->hasColumn()) {
    column_value = v8::Number::New(isolate, static_cast<double>(impl->column()));
    column_has_value_or_default = true;
  }
  if (column_has_value_or_default &&
      !create_property(0, column_value)) {
    return false;
  }

  v8::Local<v8::Value> line_value;
  bool line_has_value_or_default = false;
  if (impl->hasLine()) {
    line_value = v8::Number::New(isolate, static_cast<double>(impl->line()));
    line_has_value_or_default = true;
  }
  if (line_has_value_or_default &&
      !create_property(1, line_value)) {
    return false;
  }

  v8::Local<v8::Value> name_value;
  bool name_has_value_or_default = false;
  if (impl->hasName()) {
    name_value = V8String(isolate, impl->name());
    name_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (name_has_value_or_default &&
      !create_property(2, name_value)) {
    return false;
  }

  v8::Local<v8::Value> resource_id_value;
  bool resource_id_has_value_or_default = false;
  if (impl->hasResourceId()) {
    resource_id_value = v8::Number::New(isolate, static_cast<double>(impl->resourceId()));
    resource_id_has_value_or_default = true;
  }
  if (resource_id_has_value_or_default &&
      !create_property(3, resource_id_value)) {
    return false;
  }

  return true;
}

ProfilerFrame* NativeValueTraits<ProfilerFrame>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ProfilerFrame* impl = MakeGarbageCollected<ProfilerFrame>();
  V8ProfilerFrame::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
