// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_FONT_ACCESS_FONT_ITERATOR_ENTRY_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_FONT_ACCESS_FONT_ITERATOR_ENTRY_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class FontMetadata;

class MODULES_EXPORT FontIteratorEntry : public IDLDictionaryBase {
 public:
  static FontIteratorEntry* Create() { return MakeGarbageCollected<FontIteratorEntry>(); }
  static FontIteratorEntry* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<FontIteratorEntry>();
  }

  FontIteratorEntry();
  virtual ~FontIteratorEntry();

  bool hasDone() const { return has_done_; }
  bool done() const {
    DCHECK(has_done_);
    return done_;
  }
  inline void setDone(bool);

  bool hasValue() const { return !!value_; }
  FontMetadata* value() const {
    return value_;
  }
  inline void setValue(FontMetadata*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_done_ = false;

  bool done_;
  Member<FontMetadata> value_;

  friend class V8FontIteratorEntry;
};

void FontIteratorEntry::setDone(bool value) {
  done_ = value;
  has_done_ = true;
}

void FontIteratorEntry::setValue(FontMetadata* value) {
  value_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_FONT_ACCESS_FONT_ITERATOR_ENTRY_H_
