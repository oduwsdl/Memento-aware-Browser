// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_device_descriptor.h"

#include "third_party/blink/renderer/modules/webgpu/gpu_limits.h"

namespace blink {

GPUDeviceDescriptor::GPUDeviceDescriptor() {
  setExtensions(Vector<String>());
  setLimits(MakeGarbageCollected<GPULimits>());
}

GPUDeviceDescriptor::~GPUDeviceDescriptor() = default;

void GPUDeviceDescriptor::setExtensions(const Vector<String>& value) {
  extensions_ = value;
  has_extensions_ = true;
}

void GPUDeviceDescriptor::setLimits(GPULimits* value) {
  limits_ = value;
}

void GPUDeviceDescriptor::Trace(Visitor* visitor) const {
  visitor->Trace(limits_);
  GPUObjectDescriptorBase::Trace(visitor);
}

}  // namespace blink
