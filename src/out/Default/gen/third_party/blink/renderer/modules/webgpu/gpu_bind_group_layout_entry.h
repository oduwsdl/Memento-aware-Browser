// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BIND_GROUP_LAYOUT_ENTRY_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BIND_GROUP_LAYOUT_ENTRY_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT GPUBindGroupLayoutEntry : public IDLDictionaryBase {
 public:
  static GPUBindGroupLayoutEntry* Create() { return MakeGarbageCollected<GPUBindGroupLayoutEntry>(); }
  static GPUBindGroupLayoutEntry* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUBindGroupLayoutEntry>();
  }

  GPUBindGroupLayoutEntry();
  virtual ~GPUBindGroupLayoutEntry();

  bool hasBinding() const { return has_binding_; }
  uint32_t binding() const {
    DCHECK(has_binding_);
    return binding_;
  }
  inline void setBinding(uint32_t);

  bool hasHasDynamicOffset() const { return has_has_dynamic_offset_; }
  bool hasDynamicOffset() const {
    DCHECK(has_has_dynamic_offset_);
    return has_dynamic_offset_;
  }
  inline void setHasDynamicOffset(bool);

  bool hasMultisampled() const { return has_multisampled_; }
  bool multisampled() const {
    DCHECK(has_multisampled_);
    return multisampled_;
  }
  inline void setMultisampled(bool);

  bool hasStorageTextureFormat() const { return !storage_texture_format_.IsNull(); }
  const String& storageTextureFormat() const {
    return storage_texture_format_;
  }
  inline void setStorageTextureFormat(const String&);

  bool hasTextureComponentType() const { return !texture_component_type_.IsNull(); }
  const String& textureComponentType() const {
    return texture_component_type_;
  }
  inline void setTextureComponentType(const String&);

  bool hasType() const { return !type_.IsNull(); }
  const String& type() const {
    return type_;
  }
  inline void setType(const String&);

  bool hasViewDimension() const { return !view_dimension_.IsNull(); }
  const String& viewDimension() const {
    return view_dimension_;
  }
  inline void setViewDimension(const String&);

  bool hasVisibility() const { return has_visibility_; }
  uint32_t visibility() const {
    DCHECK(has_visibility_);
    return visibility_;
  }
  inline void setVisibility(uint32_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_binding_ = false;
  bool has_has_dynamic_offset_ = false;
  bool has_multisampled_ = false;
  bool has_visibility_ = false;

  uint32_t binding_;
  bool has_dynamic_offset_;
  bool multisampled_;
  String storage_texture_format_;
  String texture_component_type_;
  String type_;
  String view_dimension_;
  uint32_t visibility_;

  friend class V8GPUBindGroupLayoutEntry;
};

void GPUBindGroupLayoutEntry::setBinding(uint32_t value) {
  binding_ = value;
  has_binding_ = true;
}

void GPUBindGroupLayoutEntry::setHasDynamicOffset(bool value) {
  has_dynamic_offset_ = value;
  has_has_dynamic_offset_ = true;
}

void GPUBindGroupLayoutEntry::setMultisampled(bool value) {
  multisampled_ = value;
  has_multisampled_ = true;
}

void GPUBindGroupLayoutEntry::setStorageTextureFormat(const String& value) {
  storage_texture_format_ = value;
}

void GPUBindGroupLayoutEntry::setTextureComponentType(const String& value) {
  texture_component_type_ = value;
}

void GPUBindGroupLayoutEntry::setType(const String& value) {
  type_ = value;
}

void GPUBindGroupLayoutEntry::setViewDimension(const String& value) {
  view_dimension_ = value;
}

void GPUBindGroupLayoutEntry::setVisibility(uint32_t value) {
  visibility_ = value;
  has_visibility_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_BIND_GROUP_LAYOUT_ENTRY_H_
