// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_origin_3d_dict.h"

namespace blink {

GPUOrigin3DDict::GPUOrigin3DDict() {
  setX(0u);
  setY(0u);
  setZ(0u);
}

GPUOrigin3DDict::~GPUOrigin3DDict() = default;

void GPUOrigin3DDict::Trace(Visitor* visitor) const {
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
