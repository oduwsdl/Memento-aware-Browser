// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_CONTENT_INDEX_CONTENT_DESCRIPTION_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_CONTENT_INDEX_CONTENT_DESCRIPTION_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class ContentIconDefinition;

class MODULES_EXPORT ContentDescription : public IDLDictionaryBase {
 public:
  static ContentDescription* Create() { return MakeGarbageCollected<ContentDescription>(); }
  static ContentDescription* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ContentDescription>();
  }

  ContentDescription();
  virtual ~ContentDescription();

  bool hasCategory() const { return !category_.IsNull(); }
  const String& category() const {
    return category_;
  }
  inline void setCategory(const String&);

  bool hasDescription() const { return !description_.IsNull(); }
  const String& description() const {
    return description_;
  }
  inline void setDescription(const String&);

  bool hasIcons() const { return has_icons_; }
  const HeapVector<Member<ContentIconDefinition>>& icons() const {
    DCHECK(has_icons_);
    return icons_;
  }
  void setIcons(const HeapVector<Member<ContentIconDefinition>>&);

  bool hasId() const { return !id_.IsNull(); }
  const String& id() const {
    return id_;
  }
  inline void setId(const String&);

  bool hasTitle() const { return !title_.IsNull(); }
  const String& title() const {
    return title_;
  }
  inline void setTitle(const String&);

  bool hasUrl() const { return !url_.IsNull(); }
  const String& url() const {
    return url_;
  }
  inline void setUrl(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_icons_ = false;

  String category_;
  String description_;
  HeapVector<Member<ContentIconDefinition>> icons_;
  String id_;
  String title_;
  String url_;

  friend class V8ContentDescription;
};

void ContentDescription::setCategory(const String& value) {
  category_ = value;
}

void ContentDescription::setDescription(const String& value) {
  description_ = value;
}

void ContentDescription::setId(const String& value) {
  id_ = value;
}

void ContentDescription::setTitle(const String& value) {
  title_ = value;
}

void ContentDescription::setUrl(const String& value) {
  url_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_CONTENT_INDEX_CONTENT_DESCRIPTION_H_
