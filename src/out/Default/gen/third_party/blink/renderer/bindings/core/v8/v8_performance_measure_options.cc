// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_performance_measure_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8PerformanceMeasureOptionsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "detail",
    "duration",
    "end",
    "start",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8PerformanceMeasureOptions::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, PerformanceMeasureOptions* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8PerformanceMeasureOptionsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> detail_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&detail_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (detail_value.IsEmpty() || detail_value->IsUndefined()) {
    // Do nothing.
  } else {
    ScriptValue detail_cpp_value = ScriptValue(isolate, detail_value);
    impl->setDetail(detail_cpp_value);
  }

  v8::Local<v8::Value> duration_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&duration_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (duration_value.IsEmpty() || duration_value->IsUndefined()) {
    // Do nothing.
  } else {
    double duration_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, duration_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setDuration(duration_cpp_value);
  }

  v8::Local<v8::Value> end_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&end_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (end_value.IsEmpty() || end_value->IsUndefined()) {
    // Do nothing.
  } else {
    StringOrDouble end_cpp_value;
    V8StringOrDouble::ToImpl(isolate, end_value, end_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setEnd(end_cpp_value);
  }

  v8::Local<v8::Value> start_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&start_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (start_value.IsEmpty() || start_value->IsUndefined()) {
    // Do nothing.
  } else {
    StringOrDouble start_cpp_value;
    V8StringOrDouble::ToImpl(isolate, start_value, start_cpp_value, UnionTypeConversionMode::kNotNullable, exception_state);
    if (exception_state.HadException())
      return;
    impl->setStart(start_cpp_value);
  }
}

v8::Local<v8::Value> PerformanceMeasureOptions::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8PerformanceMeasureOptions(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8PerformanceMeasureOptions(const PerformanceMeasureOptions* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8PerformanceMeasureOptionsKeys(isolate).data();
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

  v8::Local<v8::Value> detail_value;
  bool detail_has_value_or_default = false;
  if (impl->hasDetail()) {
    detail_value = impl->detail().V8Value();
    detail_has_value_or_default = true;
  }
  if (detail_has_value_or_default &&
      !create_property(0, detail_value)) {
    return false;
  }

  v8::Local<v8::Value> duration_value;
  bool duration_has_value_or_default = false;
  if (impl->hasDuration()) {
    duration_value = v8::Number::New(isolate, impl->duration());
    duration_has_value_or_default = true;
  }
  if (duration_has_value_or_default &&
      !create_property(1, duration_value)) {
    return false;
  }

  v8::Local<v8::Value> end_value;
  bool end_has_value_or_default = false;
  if (impl->hasEnd()) {
    end_value = ToV8(impl->end(), creationContext, isolate);
    end_has_value_or_default = true;
  }
  if (end_has_value_or_default &&
      !create_property(2, end_value)) {
    return false;
  }

  v8::Local<v8::Value> start_value;
  bool start_has_value_or_default = false;
  if (impl->hasStart()) {
    start_value = ToV8(impl->start(), creationContext, isolate);
    start_has_value_or_default = true;
  }
  if (start_has_value_or_default &&
      !create_property(3, start_value)) {
    return false;
  }

  return true;
}

PerformanceMeasureOptions* NativeValueTraits<PerformanceMeasureOptions>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  PerformanceMeasureOptions* impl = MakeGarbageCollected<PerformanceMeasureOptions>();
  V8PerformanceMeasureOptions::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
