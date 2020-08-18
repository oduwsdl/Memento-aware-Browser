// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_texture_copy_view.h"

#include "third_party/blink/renderer/modules/webgpu/gpu_texture.h"

namespace blink {

GPUTextureCopyView::GPUTextureCopyView() {
  setMipLevel(0u);
  setOrigin(UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict::FromGPUOrigin3DDict(MakeGarbageCollected<GPUOrigin3DDict>()));
}

GPUTextureCopyView::~GPUTextureCopyView() = default;

void GPUTextureCopyView::setOrigin(const UnsignedLongEnforceRangeSequenceOrGPUOrigin3DDict& value) {
  origin_ = value;
}

void GPUTextureCopyView::Trace(Visitor* visitor) const {
  visitor->Trace(origin_);
  visitor->Trace(texture_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
