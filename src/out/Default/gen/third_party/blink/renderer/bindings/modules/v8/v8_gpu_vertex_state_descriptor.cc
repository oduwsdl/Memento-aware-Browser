// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_gpu_vertex_state_descriptor.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8GPUVertexStateDescriptorKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "indexFormat",
    "vertexBuffers",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8GPUVertexStateDescriptor::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, GPUVertexStateDescriptor* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8GPUVertexStateDescriptorKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> index_format_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&index_format_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (index_format_value.IsEmpty() || index_format_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> index_format_cpp_value = index_format_value;
    if (!index_format_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "uint16",
        "uint32",
    };
    if (!IsValidEnum(index_format_cpp_value, kValidValues, base::size(kValidValues), "GPUIndexFormat", exception_state))
      return;
    impl->setIndexFormat(index_format_cpp_value);
  }

  v8::Local<v8::Value> vertex_buffers_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&vertex_buffers_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (vertex_buffers_value.IsEmpty() || vertex_buffers_value->IsUndefined()) {
    // Do nothing.
  } else {
    ScriptValue vertex_buffers_cpp_value = NativeValueTraits<IDLObject>::NativeValue(isolate, vertex_buffers_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setVertexBuffers(vertex_buffers_cpp_value);
  }
}

v8::Local<v8::Value> GPUVertexStateDescriptor::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8GPUVertexStateDescriptor(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8GPUVertexStateDescriptor(const GPUVertexStateDescriptor* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8GPUVertexStateDescriptorKeys(isolate).data();
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

  v8::Local<v8::Value> index_format_value;
  bool index_format_has_value_or_default = false;
  if (impl->hasIndexFormat()) {
    index_format_value = V8String(isolate, impl->indexFormat());
    index_format_has_value_or_default = true;
  } else {
    index_format_value = V8String(isolate, "uint32");
    index_format_has_value_or_default = true;
  }
  if (index_format_has_value_or_default &&
      !create_property(0, index_format_value)) {
    return false;
  }

  v8::Local<v8::Value> vertex_buffers_value;
  bool vertex_buffers_has_value_or_default = false;
  if (impl->hasVertexBuffers()) {
    DCHECK(impl->vertexBuffers().IsObject());
    vertex_buffers_value = impl->vertexBuffers().V8Value();
    vertex_buffers_has_value_or_default = true;
  }
  if (vertex_buffers_has_value_or_default &&
      !create_property(1, vertex_buffers_value)) {
    return false;
  }

  return true;
}

GPUVertexStateDescriptor* NativeValueTraits<GPUVertexStateDescriptor>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  GPUVertexStateDescriptor* impl = MakeGarbageCollected<GPUVertexStateDescriptor>();
  V8GPUVertexStateDescriptor::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
