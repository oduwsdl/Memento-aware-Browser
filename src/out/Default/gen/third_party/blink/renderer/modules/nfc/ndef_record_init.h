// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_RECORD_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_RECORD_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/modules/v8/string_or_array_buffer_or_array_buffer_view_or_ndef_message_init.h"
#include "third_party/blink/renderer/core/typed_arrays/array_buffer_view_helpers.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_typed_array.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/nfc/ndef_message_init.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT NDEFRecordInit : public IDLDictionaryBase {
 public:
  static NDEFRecordInit* Create() { return MakeGarbageCollected<NDEFRecordInit>(); }
  static NDEFRecordInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<NDEFRecordInit>();
  }

  NDEFRecordInit();
  virtual ~NDEFRecordInit();

  bool hasData() const { return !data_.IsNull(); }
  const StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit& data() const {
    return data_;
  }
  void setData(const StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit&);

  bool hasEncoding() const { return !encoding_.IsNull(); }
  const String& encoding() const {
    return encoding_;
  }
  inline void setEncoding(const String&);

  bool hasId() const { return !id_.IsNull(); }
  const String& id() const {
    return id_;
  }
  inline void setId(const String&);

  bool hasLang() const { return !lang_.IsNull(); }
  const String& lang() const {
    return lang_;
  }
  inline void setLang(const String&);

  bool hasMediaType() const { return !media_type_.IsNull(); }
  const String& mediaType() const {
    return media_type_;
  }
  inline void setMediaType(const String&);

  bool hasRecordType() const { return !record_type_.IsNull(); }
  const String& recordType() const {
    return record_type_;
  }
  inline void setRecordType(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  StringOrArrayBufferOrArrayBufferViewOrNDEFMessageInit data_;
  String encoding_;
  String id_;
  String lang_;
  String media_type_;
  String record_type_;

  friend class V8NDEFRecordInit;
};

void NDEFRecordInit::setEncoding(const String& value) {
  encoding_ = value;
}

void NDEFRecordInit::setId(const String& value) {
  id_ = value;
}

void NDEFRecordInit::setLang(const String& value) {
  lang_ = value;
}

void NDEFRecordInit::setMediaType(const String& value) {
  media_type_ = value;
}

void NDEFRecordInit::setRecordType(const String& value) {
  record_type_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_RECORD_INIT_H_
