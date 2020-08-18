// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_IMAGE_BITMAP_COPY_VIEW_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_IMAGE_BITMAP_COPY_VIEW_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/modules/v8/unsigned_long_enforce_range_sequence_or_gpu_origin_2d_dict.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_origin_2d_dict.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class ImageBitmap;

class MODULES_EXPORT GPUImageBitmapCopyView : public IDLDictionaryBase {
 public:
  static GPUImageBitmapCopyView* Create() { return MakeGarbageCollected<GPUImageBitmapCopyView>(); }
  static GPUImageBitmapCopyView* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUImageBitmapCopyView>();
  }

  GPUImageBitmapCopyView();
  virtual ~GPUImageBitmapCopyView();

  bool hasImageBitmap() const { return !!image_bitmap_; }
  ImageBitmap* imageBitmap() const {
    return image_bitmap_;
  }
  inline void setImageBitmap(ImageBitmap*);

  bool hasOrigin() const { return !origin_.IsNull(); }
  const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict& origin() const {
    return origin_;
  }
  void setOrigin(const UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<ImageBitmap> image_bitmap_;
  UnsignedLongEnforceRangeSequenceOrGPUOrigin2DDict origin_;

  friend class V8GPUImageBitmapCopyView;
};

void GPUImageBitmapCopyView::setImageBitmap(ImageBitmap* value) {
  image_bitmap_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_IMAGE_BITMAP_COPY_VIEW_H_
