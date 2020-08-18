// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/string_or_worker_options.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"

namespace blink {

StringOrWorkerOptions::StringOrWorkerOptions() : type_(SpecificType::kNone) {}

const String& StringOrWorkerOptions::GetAsString() const {
  DCHECK(IsString());
  return string_;
}

void StringOrWorkerOptions::SetString(const String& value) {
  DCHECK(IsNull());
  string_ = value;
  type_ = SpecificType::kString;
}

StringOrWorkerOptions StringOrWorkerOptions::FromString(const String& value) {
  StringOrWorkerOptions container;
  container.SetString(value);
  return container;
}

WorkerOptions* StringOrWorkerOptions::GetAsWorkerOptions() const {
  DCHECK(IsWorkerOptions());
  return worker_options_;
}

void StringOrWorkerOptions::SetWorkerOptions(WorkerOptions* value) {
  DCHECK(IsNull());
  worker_options_ = value;
  type_ = SpecificType::kWorkerOptions;
}

StringOrWorkerOptions StringOrWorkerOptions::FromWorkerOptions(WorkerOptions* value) {
  StringOrWorkerOptions container;
  container.SetWorkerOptions(value);
  return container;
}

StringOrWorkerOptions::StringOrWorkerOptions(const StringOrWorkerOptions&) = default;
StringOrWorkerOptions::~StringOrWorkerOptions() = default;
StringOrWorkerOptions& StringOrWorkerOptions::operator=(const StringOrWorkerOptions&) = default;

void StringOrWorkerOptions::Trace(Visitor* visitor) const {
  visitor->Trace(worker_options_);
}

void V8StringOrWorkerOptions::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    StringOrWorkerOptions& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (IsUndefinedOrNull(v8_value)) {
    WorkerOptions* cpp_value = NativeValueTraits<WorkerOptions>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetWorkerOptions(cpp_value);
    return;
  }

  if (v8_value->IsObject()) {
    WorkerOptions* cpp_value = NativeValueTraits<WorkerOptions>::NativeValue(isolate, v8_value, exception_state);
    if (exception_state.HadException())
      return;
    impl.SetWorkerOptions(cpp_value);
    return;
  }

  {
    V8StringResource<> cpp_value = v8_value;
    if (!cpp_value.Prepare(exception_state))
      return;
    impl.SetString(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const StringOrWorkerOptions& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case StringOrWorkerOptions::SpecificType::kNone:
      return v8::Null(isolate);
    case StringOrWorkerOptions::SpecificType::kString:
      return V8String(isolate, impl.GetAsString());
    case StringOrWorkerOptions::SpecificType::kWorkerOptions:
      return ToV8(impl.GetAsWorkerOptions(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

StringOrWorkerOptions NativeValueTraits<StringOrWorkerOptions>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  StringOrWorkerOptions impl;
  V8StringOrWorkerOptions::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

