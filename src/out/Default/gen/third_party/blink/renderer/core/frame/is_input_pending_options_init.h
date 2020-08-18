// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_IS_INPUT_PENDING_OPTIONS_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_IS_INPUT_PENDING_OPTIONS_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT IsInputPendingOptionsInit : public IDLDictionaryBase {
 public:
  static IsInputPendingOptionsInit* Create() { return MakeGarbageCollected<IsInputPendingOptionsInit>(); }
  static IsInputPendingOptionsInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<IsInputPendingOptionsInit>();
  }

  IsInputPendingOptionsInit();
  virtual ~IsInputPendingOptionsInit();

  bool hasIncludeContinuous() const { return has_include_continuous_; }
  bool includeContinuous() const {
    DCHECK(has_include_continuous_);
    return include_continuous_;
  }
  inline void setIncludeContinuous(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_include_continuous_ = false;

  bool include_continuous_;

  friend class V8IsInputPendingOptionsInit;
};

void IsInputPendingOptionsInit::setIncludeContinuous(bool value) {
  include_continuous_ = value;
  has_include_continuous_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_IS_INPUT_PENDING_OPTIONS_INIT_H_
