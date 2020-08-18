// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_detected_barcode.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_rect_read_only.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_point_2d.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8DetectedBarcodeKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "boundingBox",
    "cornerPoints",
    "format",
    "rawValue",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8DetectedBarcode::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, DetectedBarcode* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): boundingBox, cornerPoints, format, rawValue.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8DetectedBarcodeKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> bounding_box_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&bounding_box_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (bounding_box_value.IsEmpty() || bounding_box_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member boundingBox is undefined.");
    return;
  } else {
    DOMRectReadOnly* bounding_box_cpp_value = V8DOMRectReadOnly::ToImplWithTypeCheck(isolate, bounding_box_value);
    if (!bounding_box_cpp_value) {
      exception_state.ThrowTypeError("member boundingBox is not of type DOMRectReadOnly.");
      return;
    }
    impl->setBoundingBox(bounding_box_cpp_value);
  }

  v8::Local<v8::Value> corner_points_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&corner_points_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (corner_points_value.IsEmpty() || corner_points_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member cornerPoints is undefined.");
    return;
  } else {
    HeapVector<Member<Point2D>> corner_points_cpp_value = NativeValueTraits<IDLSequence<Point2D>>::NativeValue(isolate, corner_points_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setCornerPoints(corner_points_cpp_value);
  }

  v8::Local<v8::Value> format_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&format_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (format_value.IsEmpty() || format_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member format is undefined.");
    return;
  } else {
    V8StringResource<> format_cpp_value = format_value;
    if (!format_cpp_value.Prepare(exception_state))
      return;
    impl->setFormat(format_cpp_value);
  }

  v8::Local<v8::Value> raw_value_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&raw_value_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (raw_value_value.IsEmpty() || raw_value_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member rawValue is undefined.");
    return;
  } else {
    V8StringResource<> raw_value_cpp_value = raw_value_value;
    if (!raw_value_cpp_value.Prepare(exception_state))
      return;
    impl->setRawValue(raw_value_cpp_value);
  }
}

v8::Local<v8::Value> DetectedBarcode::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8DetectedBarcode(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8DetectedBarcode(const DetectedBarcode* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8DetectedBarcodeKeys(isolate).data();
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

  v8::Local<v8::Value> bounding_box_value;
  bool bounding_box_has_value_or_default = false;
  if (impl->hasBoundingBox()) {
    bounding_box_value = ToV8(impl->boundingBox(), creationContext, isolate);
    bounding_box_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (bounding_box_has_value_or_default &&
      !create_property(0, bounding_box_value)) {
    return false;
  }

  v8::Local<v8::Value> corner_points_value;
  bool corner_points_has_value_or_default = false;
  if (impl->hasCornerPoints()) {
    corner_points_value = FreezeV8Object(ToV8(impl->cornerPoints(), creationContext, isolate), isolate);
    corner_points_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (corner_points_has_value_or_default &&
      !create_property(1, corner_points_value)) {
    return false;
  }

  v8::Local<v8::Value> format_value;
  bool format_has_value_or_default = false;
  if (impl->hasFormat()) {
    format_value = V8String(isolate, impl->format());
    format_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (format_has_value_or_default &&
      !create_property(2, format_value)) {
    return false;
  }

  v8::Local<v8::Value> raw_value_value;
  bool raw_value_has_value_or_default = false;
  if (impl->hasRawValue()) {
    raw_value_value = V8String(isolate, impl->rawValue());
    raw_value_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (raw_value_has_value_or_default &&
      !create_property(3, raw_value_value)) {
    return false;
  }

  return true;
}

DetectedBarcode* NativeValueTraits<DetectedBarcode>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  DetectedBarcode* impl = MakeGarbageCollected<DetectedBarcode>();
  V8DetectedBarcode::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
