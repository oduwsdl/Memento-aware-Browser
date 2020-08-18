// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_OUTPUT_SIGNALS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_OUTPUT_SIGNALS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT SerialOutputSignals : public IDLDictionaryBase {
 public:
  static SerialOutputSignals* Create() { return MakeGarbageCollected<SerialOutputSignals>(); }
  static SerialOutputSignals* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<SerialOutputSignals>();
  }

  SerialOutputSignals();
  virtual ~SerialOutputSignals();

  bool hasBrk() const { return has_brk_; }
  bool brk() const {
    DCHECK(has_brk_);
    return brk_;
  }
  inline void setBrk(bool);

  bool hasDtr() const { return has_dtr_; }
  bool dtr() const {
    DCHECK(has_dtr_);
    return dtr_;
  }
  inline void setDtr(bool);

  bool hasRts() const { return has_rts_; }
  bool rts() const {
    DCHECK(has_rts_);
    return rts_;
  }
  inline void setRts(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_brk_ = false;
  bool has_dtr_ = false;
  bool has_rts_ = false;

  bool brk_;
  bool dtr_;
  bool rts_;

  friend class V8SerialOutputSignals;
};

void SerialOutputSignals::setBrk(bool value) {
  brk_ = value;
  has_brk_ = true;
}

void SerialOutputSignals::setDtr(bool value) {
  dtr_ = value;
  has_dtr_ = true;
}

void SerialOutputSignals::setRts(bool value) {
  rts_ = value;
  has_rts_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_OUTPUT_SIGNALS_H_
