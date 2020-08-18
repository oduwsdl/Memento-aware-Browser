// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_TEXTURE_DATA_LAYOUT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_TEXTURE_DATA_LAYOUT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT GPUTextureDataLayout : public IDLDictionaryBase {
 public:
  static GPUTextureDataLayout* Create() { return MakeGarbageCollected<GPUTextureDataLayout>(); }
  static GPUTextureDataLayout* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUTextureDataLayout>();
  }

  GPUTextureDataLayout();
  virtual ~GPUTextureDataLayout();

  bool hasBytesPerRow() const { return has_bytes_per_row_; }
  uint32_t bytesPerRow() const {
    DCHECK(has_bytes_per_row_);
    return bytes_per_row_;
  }
  inline void setBytesPerRow(uint32_t);

  bool hasOffset() const { return has_offset_; }
  uint64_t offset() const {
    DCHECK(has_offset_);
    return offset_;
  }
  inline void setOffset(uint64_t);

  bool hasRowsPerImage() const { return has_rows_per_image_; }
  uint32_t rowsPerImage() const {
    DCHECK(has_rows_per_image_);
    return rows_per_image_;
  }
  inline void setRowsPerImage(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_bytes_per_row_ = false;
  bool has_offset_ = false;
  bool has_rows_per_image_ = false;

  uint32_t bytes_per_row_;
  uint64_t offset_;
  uint32_t rows_per_image_;

  friend class V8GPUTextureDataLayout;
};

void GPUTextureDataLayout::setBytesPerRow(uint32_t value) {
  bytes_per_row_ = value;
  has_bytes_per_row_ = true;
}

void GPUTextureDataLayout::setOffset(uint64_t value) {
  offset_ = value;
  has_offset_ = true;
}

void GPUTextureDataLayout::setRowsPerImage(uint32_t value) {
  rows_per_image_ = value;
  has_rows_per_image_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_TEXTURE_DATA_LAYOUT_H_
