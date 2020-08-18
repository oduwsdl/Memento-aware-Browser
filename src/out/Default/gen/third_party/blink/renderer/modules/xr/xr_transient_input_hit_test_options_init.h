// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_TRANSIENT_INPUT_HIT_TEST_OPTIONS_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_TRANSIENT_INPUT_HIT_TEST_OPTIONS_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class XRRay;

class MODULES_EXPORT XRTransientInputHitTestOptionsInit : public IDLDictionaryBase {
 public:
  static XRTransientInputHitTestOptionsInit* Create() { return MakeGarbageCollected<XRTransientInputHitTestOptionsInit>(); }
  static XRTransientInputHitTestOptionsInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<XRTransientInputHitTestOptionsInit>();
  }

  XRTransientInputHitTestOptionsInit();
  virtual ~XRTransientInputHitTestOptionsInit();

  bool hasEntityTypes() const { return has_entity_types_; }
  const Vector<String>& entityTypes() const {
    DCHECK(has_entity_types_);
    return entity_types_;
  }
  void setEntityTypes(const Vector<String>&);

  bool hasOffsetRay() const { return !!offset_ray_; }
  XRRay* offsetRay() const {
    return offset_ray_;
  }
  inline void setOffsetRay(XRRay*);

  bool hasProfile() const { return !profile_.IsNull(); }
  const String& profile() const {
    return profile_;
  }
  inline void setProfile(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_entity_types_ = false;

  Vector<String> entity_types_;
  Member<XRRay> offset_ray_;
  String profile_;

  friend class V8XRTransientInputHitTestOptionsInit;
};

void XRTransientInputHitTestOptionsInit::setOffsetRay(XRRay* value) {
  offset_ray_ = value;
}

void XRTransientInputHitTestOptionsInit::setProfile(const String& value) {
  profile_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_TRANSIENT_INPUT_HIT_TEST_OPTIONS_INIT_H_
