// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_SESSION_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_SESSION_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class XRDOMOverlayInit;

class MODULES_EXPORT XRSessionInit : public IDLDictionaryBase {
 public:
  static XRSessionInit* Create() { return MakeGarbageCollected<XRSessionInit>(); }
  static XRSessionInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<XRSessionInit>();
  }

  XRSessionInit();
  virtual ~XRSessionInit();

  bool hasDomOverlay() const { return !!dom_overlay_; }
  XRDOMOverlayInit* domOverlay() const {
    return dom_overlay_;
  }
  void setDomOverlay(XRDOMOverlayInit*);

  bool hasOptionalFeatures() const { return has_optional_features_; }
  const HeapVector<ScriptValue>& optionalFeatures() const {
    DCHECK(has_optional_features_);
    return optional_features_;
  }
  void setOptionalFeatures(const HeapVector<ScriptValue>&);

  bool hasRequiredFeatures() const { return has_required_features_; }
  const HeapVector<ScriptValue>& requiredFeatures() const {
    DCHECK(has_required_features_);
    return required_features_;
  }
  void setRequiredFeatures(const HeapVector<ScriptValue>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_optional_features_ = false;
  bool has_required_features_ = false;

  Member<XRDOMOverlayInit> dom_overlay_;
  HeapVector<ScriptValue> optional_features_;
  HeapVector<ScriptValue> required_features_;

  friend class V8XRSessionInit;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_SESSION_INIT_H_
