// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_READING_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_READING_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class NDEFMessageInit;

class MODULES_EXPORT NDEFReadingEventInit : public EventInit {
 public:
  static NDEFReadingEventInit* Create() { return MakeGarbageCollected<NDEFReadingEventInit>(); }
  static NDEFReadingEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<NDEFReadingEventInit>();
  }

  NDEFReadingEventInit();
  virtual ~NDEFReadingEventInit();

  bool hasMessage() const { return !!message_; }
  NDEFMessageInit* message() const {
    return message_;
  }
  void setMessage(NDEFMessageInit*);

  bool hasSerialNumber() const { return !serial_number_.IsNull(); }
  const String& serialNumber() const {
    return serial_number_;
  }
  inline void setSerialNumber(const String&);
  inline void setSerialNumberToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasSerialNumberNonNull() const { return !serial_number_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasSerialNumberNonNull| in advance to check the condition.
  const String& serialNumberNonNull() const {
    DCHECK(hasSerialNumberNonNull());
    return serial_number_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<NDEFMessageInit> message_;
  String serial_number_;

  friend class V8NDEFReadingEventInit;
};

void NDEFReadingEventInit::setSerialNumber(const String& value) {
  serial_number_ = value;
}

void NDEFReadingEventInit::setSerialNumberToNull() {
  serial_number_ = String();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_READING_EVENT_INIT_H_
