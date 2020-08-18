// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PERMISSIONS_CAMERA_DEVICE_PERMISSION_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PERMISSIONS_CAMERA_DEVICE_PERMISSION_DESCRIPTOR_H_

#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/permissions/permission_descriptor.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT CameraDevicePermissionDescriptor : public PermissionDescriptor {
 public:
  static CameraDevicePermissionDescriptor* Create() { return MakeGarbageCollected<CameraDevicePermissionDescriptor>(); }
  static CameraDevicePermissionDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<CameraDevicePermissionDescriptor>();
  }

  CameraDevicePermissionDescriptor();
  virtual ~CameraDevicePermissionDescriptor();

  bool hasPanTiltZoom() const { return has_pan_tilt_zoom_; }
  bool panTiltZoom() const {
    DCHECK(has_pan_tilt_zoom_);
    return pan_tilt_zoom_;
  }
  inline void setPanTiltZoom(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_pan_tilt_zoom_ = false;

  bool pan_tilt_zoom_;

  friend class V8CameraDevicePermissionDescriptor;
};

void CameraDevicePermissionDescriptor::setPanTiltZoom(bool value) {
  pan_tilt_zoom_ = value;
  has_pan_tilt_zoom_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PERMISSIONS_CAMERA_DEVICE_PERMISSION_DESCRIPTOR_H_
