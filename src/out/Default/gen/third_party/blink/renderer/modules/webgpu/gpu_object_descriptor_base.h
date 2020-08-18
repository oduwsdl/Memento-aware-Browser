// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_OBJECT_DESCRIPTOR_BASE_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_OBJECT_DESCRIPTOR_BASE_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT GPUObjectDescriptorBase : public IDLDictionaryBase {
 public:
  static GPUObjectDescriptorBase* Create() { return MakeGarbageCollected<GPUObjectDescriptorBase>(); }
  static GPUObjectDescriptorBase* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUObjectDescriptorBase>();
  }

  GPUObjectDescriptorBase();
  virtual ~GPUObjectDescriptorBase();

  bool hasLabel() const { return !label_.IsNull(); }
  const String& label() const {
    return label_;
  }
  inline void setLabel(const String&);
  inline void setLabelToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasLabelNonNull() const { return !label_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasLabelNonNull| in advance to check the condition.
  const String& labelNonNull() const {
    DCHECK(hasLabelNonNull());
    return label_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String label_;

  friend class V8GPUObjectDescriptorBase;
};

void GPUObjectDescriptorBase::setLabel(const String& value) {
  label_ = value;
}

void GPUObjectDescriptorBase::setLabelToNull() {
  label_ = String();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_OBJECT_DESCRIPTOR_BASE_H_
