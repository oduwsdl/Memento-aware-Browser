// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_CLIPBOARD_CLIPBOARD_ITEM_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_CLIPBOARD_CLIPBOARD_ITEM_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT ClipboardItemOptions : public IDLDictionaryBase {
 public:
  static ClipboardItemOptions* Create() { return MakeGarbageCollected<ClipboardItemOptions>(); }
  static ClipboardItemOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ClipboardItemOptions>();
  }

  ClipboardItemOptions();
  virtual ~ClipboardItemOptions();

  bool hasRaw() const { return has_raw_; }
  bool raw() const {
    DCHECK(has_raw_);
    return raw_;
  }
  inline void setRaw(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_raw_ = false;

  bool raw_;

  friend class V8ClipboardItemOptions;
};

void ClipboardItemOptions::setRaw(bool value) {
  raw_ = value;
  has_raw_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_CLIPBOARD_CLIPBOARD_ITEM_OPTIONS_H_
