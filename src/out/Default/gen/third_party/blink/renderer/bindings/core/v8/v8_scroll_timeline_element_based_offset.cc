// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/v8_scroll_timeline_element_based_offset.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_element.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ScrollTimelineElementBasedOffsetKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "edge",
    "target",
    "threshold",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ScrollTimelineElementBasedOffset::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ScrollTimelineElementBasedOffset* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ScrollTimelineElementBasedOffsetKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> edge_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&edge_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (edge_value.IsEmpty() || edge_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> edge_cpp_value = edge_value;
    if (!edge_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "start",
        "end",
    };
    if (!IsValidEnum(edge_cpp_value, kValidValues, base::size(kValidValues), "Edge", exception_state))
      return;
    impl->setEdge(edge_cpp_value);
  }

  v8::Local<v8::Value> target_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&target_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (target_value.IsEmpty() || target_value->IsUndefined()) {
    // Do nothing.
  } else {
    Element* target_cpp_value = V8Element::ToImplWithTypeCheck(isolate, target_value);
    if (!target_cpp_value) {
      exception_state.ThrowTypeError("member target is not of type Element.");
      return;
    }
    impl->setTarget(target_cpp_value);
  }

  v8::Local<v8::Value> threshold_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&threshold_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (threshold_value.IsEmpty() || threshold_value->IsUndefined()) {
    // Do nothing.
  } else {
    double threshold_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, threshold_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setThreshold(threshold_cpp_value);
  }
}

v8::Local<v8::Value> ScrollTimelineElementBasedOffset::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ScrollTimelineElementBasedOffset(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ScrollTimelineElementBasedOffset(const ScrollTimelineElementBasedOffset* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ScrollTimelineElementBasedOffsetKeys(isolate).data();
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

  v8::Local<v8::Value> edge_value;
  bool edge_has_value_or_default = false;
  if (impl->hasEdge()) {
    edge_value = V8String(isolate, impl->edge());
    edge_has_value_or_default = true;
  } else {
    edge_value = V8String(isolate, "start");
    edge_has_value_or_default = true;
  }
  if (edge_has_value_or_default &&
      !create_property(0, edge_value)) {
    return false;
  }

  v8::Local<v8::Value> target_value;
  bool target_has_value_or_default = false;
  if (impl->hasTarget()) {
    target_value = ToV8(impl->target(), creationContext, isolate);
    target_has_value_or_default = true;
  }
  if (target_has_value_or_default &&
      !create_property(1, target_value)) {
    return false;
  }

  v8::Local<v8::Value> threshold_value;
  bool threshold_has_value_or_default = false;
  if (impl->hasThreshold()) {
    threshold_value = v8::Number::New(isolate, impl->threshold());
    threshold_has_value_or_default = true;
  } else {
    threshold_value = v8::Number::New(isolate, 0);
    threshold_has_value_or_default = true;
  }
  if (threshold_has_value_or_default &&
      !create_property(2, threshold_value)) {
    return false;
  }

  return true;
}

ScrollTimelineElementBasedOffset* NativeValueTraits<ScrollTimelineElementBasedOffset>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ScrollTimelineElementBasedOffset* impl = MakeGarbageCollected<ScrollTimelineElementBasedOffset>();
  V8ScrollTimelineElementBasedOffset::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
