// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_ndef_message_init.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_ndef_record_init.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8NDEFMessageInitKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "records",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8NDEFMessageInit::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, NDEFMessageInit* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): records.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8NDEFMessageInitKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> records_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&records_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (records_value.IsEmpty() || records_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member records is undefined.");
    return;
  } else {
    HeapVector<Member<NDEFRecordInit>> records_cpp_value = NativeValueTraits<IDLSequence<NDEFRecordInit>>::NativeValue(isolate, records_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setRecords(records_cpp_value);
  }
}

v8::Local<v8::Value> NDEFMessageInit::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8NDEFMessageInit(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8NDEFMessageInit(const NDEFMessageInit* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8NDEFMessageInitKeys(isolate).data();
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

  v8::Local<v8::Value> records_value;
  bool records_has_value_or_default = false;
  if (impl->hasRecords()) {
    records_value = ToV8(impl->records(), creationContext, isolate);
    records_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (records_has_value_or_default &&
      !create_property(0, records_value)) {
    return false;
  }

  return true;
}

NDEFMessageInit* NativeValueTraits<NDEFMessageInit>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  NDEFMessageInit* impl = MakeGarbageCollected<NDEFMessageInit>();
  V8NDEFMessageInit::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
