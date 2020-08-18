// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_DOM_POINTER_LOCK_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_DOM_POINTER_LOCK_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT PointerLockOptions : public IDLDictionaryBase {
 public:
  static PointerLockOptions* Create() { return MakeGarbageCollected<PointerLockOptions>(); }
  static PointerLockOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<PointerLockOptions>();
  }

  PointerLockOptions();
  virtual ~PointerLockOptions();

  bool hasUnadjustedMovement() const { return has_unadjusted_movement_; }
  bool unadjustedMovement() const {
    DCHECK(has_unadjusted_movement_);
    return unadjusted_movement_;
  }
  inline void setUnadjustedMovement(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_unadjusted_movement_ = false;

  bool unadjusted_movement_;

  friend class V8PointerLockOptions;
};

void PointerLockOptions::setUnadjustedMovement(bool value) {
  unadjusted_movement_ = value;
  has_unadjusted_movement_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_DOM_POINTER_LOCK_OPTIONS_H_
