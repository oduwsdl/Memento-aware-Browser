// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_MESSAGE_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_MESSAGE_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class NDEFRecordInit;

class MODULES_EXPORT NDEFMessageInit : public IDLDictionaryBase {
 public:
  static NDEFMessageInit* Create() { return MakeGarbageCollected<NDEFMessageInit>(); }
  static NDEFMessageInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<NDEFMessageInit>();
  }

  NDEFMessageInit();
  virtual ~NDEFMessageInit();

  bool hasRecords() const { return has_records_; }
  const HeapVector<Member<NDEFRecordInit>>& records() const {
    DCHECK(has_records_);
    return records_;
  }
  void setRecords(const HeapVector<Member<NDEFRecordInit>>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_records_ = false;

  HeapVector<Member<NDEFRecordInit>> records_;

  friend class V8NDEFMessageInit;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_MESSAGE_INIT_H_
