// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_PORT_REQUEST_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_PORT_REQUEST_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class SerialPortFilter;

class MODULES_EXPORT SerialPortRequestOptions : public IDLDictionaryBase {
 public:
  static SerialPortRequestOptions* Create() { return MakeGarbageCollected<SerialPortRequestOptions>(); }
  static SerialPortRequestOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<SerialPortRequestOptions>();
  }

  SerialPortRequestOptions();
  virtual ~SerialPortRequestOptions();

  bool hasFilters() const { return has_filters_; }
  const HeapVector<Member<SerialPortFilter>>& filters() const {
    DCHECK(has_filters_);
    return filters_;
  }
  void setFilters(const HeapVector<Member<SerialPortFilter>>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_filters_ = false;

  HeapVector<Member<SerialPortFilter>> filters_;

  friend class V8SerialPortRequestOptions;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_PORT_REQUEST_OPTIONS_H_
