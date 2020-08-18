// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PERMISSIONS_CLIPBOARD_PERMISSION_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PERMISSIONS_CLIPBOARD_PERMISSION_DESCRIPTOR_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/permissions/permission_descriptor.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT ClipboardPermissionDescriptor : public PermissionDescriptor {
 public:
  static ClipboardPermissionDescriptor* Create() { return MakeGarbageCollected<ClipboardPermissionDescriptor>(); }
  static ClipboardPermissionDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<ClipboardPermissionDescriptor>();
  }

  ClipboardPermissionDescriptor();
  virtual ~ClipboardPermissionDescriptor();

  bool hasAllowWithoutGesture() const { return has_allow_without_gesture_; }
  bool allowWithoutGesture() const {
    DCHECK(has_allow_without_gesture_);
    return allow_without_gesture_;
  }
  inline void setAllowWithoutGesture(bool);

  bool hasAllowWithoutSanitization() const { return has_allow_without_sanitization_; }
  bool allowWithoutSanitization() const {
    DCHECK(has_allow_without_sanitization_);
    return allow_without_sanitization_;
  }
  inline void setAllowWithoutSanitization(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_allow_without_gesture_ = false;
  bool has_allow_without_sanitization_ = false;

  bool allow_without_gesture_;
  bool allow_without_sanitization_;

  friend class V8ClipboardPermissionDescriptor;
};

void ClipboardPermissionDescriptor::setAllowWithoutGesture(bool value) {
  allow_without_gesture_ = value;
  has_allow_without_gesture_ = true;
}

void ClipboardPermissionDescriptor::setAllowWithoutSanitization(bool value) {
  allow_without_sanitization_ = value;
  has_allow_without_sanitization_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PERMISSIONS_CLIPBOARD_PERMISSION_DESCRIPTOR_H_
