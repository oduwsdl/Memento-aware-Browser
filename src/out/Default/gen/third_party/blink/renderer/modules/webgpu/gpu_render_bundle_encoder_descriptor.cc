// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_render_bundle_encoder_descriptor.h"

namespace blink {

GPURenderBundleEncoderDescriptor::GPURenderBundleEncoderDescriptor() {
  setSampleCount(1u);
}

GPURenderBundleEncoderDescriptor::~GPURenderBundleEncoderDescriptor() = default;

void GPURenderBundleEncoderDescriptor::setColorFormats(const Vector<String>& value) {
  color_formats_ = value;
  has_color_formats_ = true;
}

void GPURenderBundleEncoderDescriptor::Trace(Visitor* visitor) const {
  GPUObjectDescriptorBase::Trace(visitor);
}

}  // namespace blink
