// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_item_details.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_payment_currency_amount.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ItemDetailsKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "description",
    "itemId",
    "price",
    "title",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ItemDetails::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ItemDetails* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ItemDetailsKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> description_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&description_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (description_value.IsEmpty() || description_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> description_cpp_value = description_value;
    if (!description_cpp_value.Prepare(exception_state))
      return;
    impl->setDescription(description_cpp_value);
  }

  v8::Local<v8::Value> item_id_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&item_id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (item_id_value.IsEmpty() || item_id_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> item_id_cpp_value = item_id_value;
    if (!item_id_cpp_value.Prepare(exception_state))
      return;
    impl->setItemId(item_id_cpp_value);
  }

  v8::Local<v8::Value> price_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&price_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (price_value.IsEmpty() || price_value->IsUndefined()) {
    // Do nothing.
  } else {
    PaymentCurrencyAmount* price_cpp_value = NativeValueTraits<PaymentCurrencyAmount>::NativeValue(isolate, price_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setPrice(price_cpp_value);
  }

  v8::Local<v8::Value> title_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&title_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (title_value.IsEmpty() || title_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> title_cpp_value = title_value;
    if (!title_cpp_value.Prepare(exception_state))
      return;
    impl->setTitle(title_cpp_value);
  }
}

v8::Local<v8::Value> ItemDetails::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ItemDetails(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ItemDetails(const ItemDetails* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ItemDetailsKeys(isolate).data();
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

  v8::Local<v8::Value> description_value;
  bool description_has_value_or_default = false;
  if (impl->hasDescription()) {
    description_value = V8String(isolate, impl->description());
    description_has_value_or_default = true;
  }
  if (description_has_value_or_default &&
      !create_property(0, description_value)) {
    return false;
  }

  v8::Local<v8::Value> item_id_value;
  bool item_id_has_value_or_default = false;
  if (impl->hasItemId()) {
    item_id_value = V8String(isolate, impl->itemId());
    item_id_has_value_or_default = true;
  }
  if (item_id_has_value_or_default &&
      !create_property(1, item_id_value)) {
    return false;
  }

  v8::Local<v8::Value> price_value;
  bool price_has_value_or_default = false;
  if (impl->hasPrice()) {
    price_value = ToV8(impl->price(), creationContext, isolate);
    price_has_value_or_default = true;
  }
  if (price_has_value_or_default &&
      !create_property(2, price_value)) {
    return false;
  }

  v8::Local<v8::Value> title_value;
  bool title_has_value_or_default = false;
  if (impl->hasTitle()) {
    title_value = V8String(isolate, impl->title());
    title_has_value_or_default = true;
  }
  if (title_has_value_or_default &&
      !create_property(3, title_value)) {
    return false;
  }

  return true;
}

ItemDetails* NativeValueTraits<ItemDetails>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ItemDetails* impl = MakeGarbageCollected<ItemDetails>();
  V8ItemDetails::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
