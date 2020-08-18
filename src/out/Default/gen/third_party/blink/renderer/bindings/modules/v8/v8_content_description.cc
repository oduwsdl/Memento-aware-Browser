// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_content_description.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_content_icon_definition.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8ContentDescriptionKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "category",
    "description",
    "icons",
    "id",
    "title",
    "url",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8ContentDescription::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, ContentDescription* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    exception_state.ThrowTypeError("Missing required member(s): description, id, title, url.");
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  const auto* keys = eternalV8ContentDescriptionKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> category_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&category_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (category_value.IsEmpty() || category_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> category_cpp_value = category_value;
    if (!category_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "",
        "homepage",
        "article",
        "video",
        "audio",
    };
    if (!IsValidEnum(category_cpp_value, kValidValues, base::size(kValidValues), "ContentCategory", exception_state))
      return;
    impl->setCategory(category_cpp_value);
  }

  v8::Local<v8::Value> description_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&description_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (description_value.IsEmpty() || description_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member description is undefined.");
    return;
  } else {
    V8StringResource<> description_cpp_value = description_value;
    if (!description_cpp_value.Prepare(exception_state))
      return;
    impl->setDescription(description_cpp_value);
  }

  v8::Local<v8::Value> icons_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&icons_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (icons_value.IsEmpty() || icons_value->IsUndefined()) {
    // Do nothing.
  } else {
    HeapVector<Member<ContentIconDefinition>> icons_cpp_value = NativeValueTraits<IDLSequence<ContentIconDefinition>>::NativeValue(isolate, icons_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setIcons(icons_cpp_value);
  }

  v8::Local<v8::Value> id_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&id_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (id_value.IsEmpty() || id_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member id is undefined.");
    return;
  } else {
    V8StringResource<> id_cpp_value = id_value;
    if (!id_cpp_value.Prepare(exception_state))
      return;
    impl->setId(id_cpp_value);
  }

  v8::Local<v8::Value> title_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&title_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (title_value.IsEmpty() || title_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member title is undefined.");
    return;
  } else {
    V8StringResource<> title_cpp_value = title_value;
    if (!title_cpp_value.Prepare(exception_state))
      return;
    impl->setTitle(title_cpp_value);
  }

  v8::Local<v8::Value> url_value;
  if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&url_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (url_value.IsEmpty() || url_value->IsUndefined()) {
    exception_state.ThrowTypeError("required member url is undefined.");
    return;
  } else {
    V8StringResource<> url_cpp_value = NativeValueTraits<IDLUSVString>::NativeValue(isolate, url_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setUrl(url_cpp_value);
  }
}

v8::Local<v8::Value> ContentDescription::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8ContentDescription(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8ContentDescription(const ContentDescription* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  const auto* keys = eternalV8ContentDescriptionKeys(isolate).data();
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

  v8::Local<v8::Value> category_value;
  bool category_has_value_or_default = false;
  if (impl->hasCategory()) {
    category_value = V8String(isolate, impl->category());
    category_has_value_or_default = true;
  } else {
    category_value = V8String(isolate, WTF::g_empty_string);
    category_has_value_or_default = true;
  }
  if (category_has_value_or_default &&
      !create_property(0, category_value)) {
    return false;
  }

  v8::Local<v8::Value> description_value;
  bool description_has_value_or_default = false;
  if (impl->hasDescription()) {
    description_value = V8String(isolate, impl->description());
    description_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (description_has_value_or_default &&
      !create_property(1, description_value)) {
    return false;
  }

  v8::Local<v8::Value> icons_value;
  bool icons_has_value_or_default = false;
  if (impl->hasIcons()) {
    icons_value = ToV8(impl->icons(), creationContext, isolate);
    icons_has_value_or_default = true;
  } else {
    icons_value = ToV8(HeapVector<Member<ContentIconDefinition>>(), creationContext, isolate);
    icons_has_value_or_default = true;
  }
  if (icons_has_value_or_default &&
      !create_property(2, icons_value)) {
    return false;
  }

  v8::Local<v8::Value> id_value;
  bool id_has_value_or_default = false;
  if (impl->hasId()) {
    id_value = V8String(isolate, impl->id());
    id_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (id_has_value_or_default &&
      !create_property(3, id_value)) {
    return false;
  }

  v8::Local<v8::Value> title_value;
  bool title_has_value_or_default = false;
  if (impl->hasTitle()) {
    title_value = V8String(isolate, impl->title());
    title_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (title_has_value_or_default &&
      !create_property(4, title_value)) {
    return false;
  }

  v8::Local<v8::Value> url_value;
  bool url_has_value_or_default = false;
  if (impl->hasUrl()) {
    url_value = V8String(isolate, impl->url());
    url_has_value_or_default = true;
  } else {
    NOTREACHED();
  }
  if (url_has_value_or_default &&
      !create_property(5, url_value)) {
    return false;
  }

  return true;
}

ContentDescription* NativeValueTraits<ContentDescription>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  ContentDescription* impl = MakeGarbageCollected<ContentDescription>();
  V8ContentDescription::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
