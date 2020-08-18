// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_VIRTUALKEYBOARD_VIRTUAL_KEYBOARD_GEOMETRY_CHANGE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_VIRTUALKEYBOARD_VIRTUAL_KEYBOARD_GEOMETRY_CHANGE_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class DOMRect;

class MODULES_EXPORT VirtualKeyboardGeometryChangeEventInit : public EventInit {
 public:
  static VirtualKeyboardGeometryChangeEventInit* Create() { return MakeGarbageCollected<VirtualKeyboardGeometryChangeEventInit>(); }
  static VirtualKeyboardGeometryChangeEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<VirtualKeyboardGeometryChangeEventInit>();
  }

  VirtualKeyboardGeometryChangeEventInit();
  virtual ~VirtualKeyboardGeometryChangeEventInit();

  bool hasBoundingRect() const { return !!bounding_rect_; }
  DOMRect* boundingRect() const {
    return bounding_rect_;
  }
  inline void setBoundingRect(DOMRect*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<DOMRect> bounding_rect_;

  friend class V8VirtualKeyboardGeometryChangeEventInit;
};

void VirtualKeyboardGeometryChangeEventInit::setBoundingRect(DOMRect* value) {
  bounding_rect_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_VIRTUALKEYBOARD_VIRTUAL_KEYBOARD_GEOMETRY_CHANGE_EVENT_INIT_H_
