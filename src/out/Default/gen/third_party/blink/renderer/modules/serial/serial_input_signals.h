// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_INPUT_SIGNALS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_INPUT_SIGNALS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT SerialInputSignals : public IDLDictionaryBase {
 public:
  static SerialInputSignals* Create() { return MakeGarbageCollected<SerialInputSignals>(); }
  static SerialInputSignals* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<SerialInputSignals>();
  }

  SerialInputSignals();
  virtual ~SerialInputSignals();

  bool hasCts() const { return has_cts_; }
  bool cts() const {
    DCHECK(has_cts_);
    return cts_;
  }
  inline void setCts(bool);

  bool hasDcd() const { return has_dcd_; }
  bool dcd() const {
    DCHECK(has_dcd_);
    return dcd_;
  }
  inline void setDcd(bool);

  bool hasDsr() const { return has_dsr_; }
  bool dsr() const {
    DCHECK(has_dsr_);
    return dsr_;
  }
  inline void setDsr(bool);

  bool hasRi() const { return has_ri_; }
  bool ri() const {
    DCHECK(has_ri_);
    return ri_;
  }
  inline void setRi(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_cts_ = false;
  bool has_dcd_ = false;
  bool has_dsr_ = false;
  bool has_ri_ = false;

  bool cts_;
  bool dcd_;
  bool dsr_;
  bool ri_;

  friend class V8SerialInputSignals;
};

void SerialInputSignals::setCts(bool value) {
  cts_ = value;
  has_cts_ = true;
}

void SerialInputSignals::setDcd(bool value) {
  dcd_ = value;
  has_dcd_ = true;
}

void SerialInputSignals::setDsr(bool value) {
  dsr_ = value;
  has_dsr_ = true;
}

void SerialInputSignals::setRi(bool value) {
  ri_ = value;
  has_ri_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_INPUT_SIGNALS_H_
