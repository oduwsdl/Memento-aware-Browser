// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_texture_data_layout.h"

namespace blink {

GPUTextureDataLayout::GPUTextureDataLayout() {
  setOffset(0);
  setRowsPerImage(0u);
}

GPUTextureDataLayout::~GPUTextureDataLayout() = default;

void GPUTextureDataLayout::Trace(Visitor* visitor) const {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
