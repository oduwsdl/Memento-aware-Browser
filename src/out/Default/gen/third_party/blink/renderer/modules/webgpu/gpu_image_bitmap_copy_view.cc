// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_image_bitmap_copy_view.h"

#include "third_party/blink/renderer/core/imagebitmap/image_bitmap.h"

namespace blink {

GPUImageBitmapCopyView::GPUImageBitmapCopyView() {
  setOrigin(UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict::FromGPUOrigin2DDict(MakeGarbageCollected<GPUOrigin2DDict>()));
}

GPUImageBitmapCopyView::~GPUImageBitmapCopyView() = default;

void GPUImageBitmapCopyView::setOrigin(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& value) {
  origin_ = value;
}

void GPUImageBitmapCopyView::Trace(Visitor* visitor) const {
  visitor->Trace(image_bitmap_);
  visitor->Trace(origin_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
