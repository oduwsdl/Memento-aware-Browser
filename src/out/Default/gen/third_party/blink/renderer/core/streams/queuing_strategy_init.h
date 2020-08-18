// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STREAMS_QUEUING_STRATEGY_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STREAMS_QUEUING_STRATEGY_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT QueuingStrategyInit : public IDLDictionaryBase {
 public:
  static QueuingStrategyInit* Create() { return MakeGarbageCollected<QueuingStrategyInit>(); }
  static QueuingStrategyInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<QueuingStrategyInit>();
  }

  QueuingStrategyInit();
  virtual ~QueuingStrategyInit();

  bool hasHighWaterMark() const { return !(high_water_mark_.IsEmpty() || high_water_mark_.IsUndefined()); }
  ScriptValue highWaterMark() const {
    return high_water_mark_;
  }
  void setHighWaterMark(ScriptValue);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  ScriptValue high_water_mark_;

  friend class V8QueuingStrategyInit;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_STREAMS_QUEUING_STRATEGY_INIT_H_
