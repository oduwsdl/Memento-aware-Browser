// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_WRITE_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_WRITE_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class AbortSignal;

class MODULES_EXPORT NDEFWriteOptions : public IDLDictionaryBase {
 public:
  static NDEFWriteOptions* Create() { return MakeGarbageCollected<NDEFWriteOptions>(); }
  static NDEFWriteOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<NDEFWriteOptions>();
  }

  NDEFWriteOptions();
  virtual ~NDEFWriteOptions();

  bool hasIgnoreRead() const { return has_ignore_read_; }
  bool ignoreRead() const {
    DCHECK(has_ignore_read_);
    return ignore_read_;
  }
  inline void setIgnoreRead(bool);

  bool hasOverwrite() const { return has_overwrite_; }
  bool overwrite() const {
    DCHECK(has_overwrite_);
    return overwrite_;
  }
  inline void setOverwrite(bool);

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
  bool has_ignore_read_ = false;
  bool has_overwrite_ = false;
  bool has_signal_ = false;

  bool ignore_read_;
  bool overwrite_;
  Member<AbortSignal> signal_;

  friend class V8NDEFWriteOptions;
};

void NDEFWriteOptions::setIgnoreRead(bool value) {
  ignore_read_ = value;
  has_ignore_read_ = true;
}

void NDEFWriteOptions::setOverwrite(bool value) {
  overwrite_ = value;
  has_overwrite_ = true;
}

void NDEFWriteOptions::setSignal(AbortSignal* value) {
  signal_ = value;
  has_signal_ = true;
}

void NDEFWriteOptions::setSignalToNull() {
  signal_ = Member<AbortSignal>();
  has_signal_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NFC_NDEF_WRITE_OPTIONS_H_
