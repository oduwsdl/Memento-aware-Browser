// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_DOM_OVERLAY_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_DOM_OVERLAY_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class Element;

class MODULES_EXPORT XRDOMOverlayInit : public IDLDictionaryBase {
 public:
  static XRDOMOverlayInit* Create() { return MakeGarbageCollected<XRDOMOverlayInit>(); }
  static XRDOMOverlayInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<XRDOMOverlayInit>();
  }

  XRDOMOverlayInit();
  virtual ~XRDOMOverlayInit();

  bool hasRoot() const { return !!root_; }
  Element* root() const {
    return root_;
  }
  inline void setRoot(Element*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<Element> root_;

  friend class V8XRDOMOverlayInit;
};

void XRDOMOverlayInit::setRoot(Element* value) {
  root_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_XR_XR_DOM_OVERLAY_INIT_H_
