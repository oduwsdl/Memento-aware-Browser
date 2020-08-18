// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_CONTENT_INDEX_CONTENT_ICON_DEFINITION_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_CONTENT_INDEX_CONTENT_ICON_DEFINITION_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT ContentIconDefinition : public IDLDictionaryBase {
 public:
  static ContentIconDefinition* Create() { return MakeGarbageCollected<ContentIconDefinition>(); }
  static ContentIconDefinition* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ContentIconDefinition>();
  }

  ContentIconDefinition();
  virtual ~ContentIconDefinition();

  bool hasSizes() const { return !sizes_.IsNull(); }
  const String& sizes() const {
    return sizes_;
  }
  inline void setSizes(const String&);

  bool hasSrc() const { return !src_.IsNull(); }
  const String& src() const {
    return src_;
  }
  inline void setSrc(const String&);

  bool hasType() const { return !type_.IsNull(); }
  const String& type() const {
    return type_;
  }
  inline void setType(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String sizes_;
  String src_;
  String type_;

  friend class V8ContentIconDefinition;
};

void ContentIconDefinition::setSizes(const String& value) {
  sizes_ = value;
}

void ContentIconDefinition::setSrc(const String& value) {
  src_ = value;
}

void ContentIconDefinition::setType(const String& value) {
  type_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_CONTENT_INDEX_CONTENT_ICON_DEFINITION_H_
