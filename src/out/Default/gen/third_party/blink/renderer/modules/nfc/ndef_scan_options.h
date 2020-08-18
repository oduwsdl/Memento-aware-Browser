// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_SCAN_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_SCAN_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class AbortSignal;

class MODULES_EXPORT NDEFScanOptions : public IDLDictionaryBase {
 public:
  static NDEFScanOptions* Create() { return MakeGarbageCollected<NDEFScanOptions>(); }
  static NDEFScanOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<NDEFScanOptions>();
  }

  NDEFScanOptions();
  virtual ~NDEFScanOptions();

  bool hasId() const { return !id_.IsNull(); }
  const String& id() const {
    return id_;
  }
  inline void setId(const String&);

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

  bool hasSignal() const { return has_signal_; }
  AbortSignal* signal() const {
    return signal_;
  }
  inline void setSignal(AbortSignal*);
  inline void setSignalToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasSignalNonNull() const { return has_signal_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasSignalNonNull| in advance to check the condition.
  AbortSignal* signalNonNull() const {
    DCHECK(hasSignalNonNull());
    return signal_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_signal_ = false;

  String id_;
  String media_type_;
  String record_type_;
  Member<AbortSignal> signal_;

  friend class V8NDEFScanOptions;
};

void NDEFScanOptions::setId(const String& value) {
  id_ = value;
}

void NDEFScanOptions::setMediaType(const String& value) {
  media_type_ = value;
}

void NDEFScanOptions::setRecordType(const String& value) {
  record_type_ = value;
}

void NDEFScanOptions::setSignal(AbortSignal* value) {
  signal_ = value;
  has_signal_ = true;
}

void NDEFScanOptions::setSignalToNull() {
  signal_ = Member<AbortSignal>();
  has_signal_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_SCAN_OPTIONS_H_
