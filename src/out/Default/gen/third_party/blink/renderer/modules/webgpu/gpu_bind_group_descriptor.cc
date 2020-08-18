// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/webgpu/gpu_bind_group_descriptor.h"

#include "third_party/blink/renderer/modules/webgpu/gpu_bind_group_entry.h"
#include "third_party/blink/renderer/modules/webgpu/gpu_bind_group_layout.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

GPUBindGroupDescriptor::GPUBindGroupDescriptor() {
}

GPUBindGroupDescriptor::~GPUBindGroupDescriptor() = default;

void GPUBindGroupDescriptor::setEntries(const HeapVector<Member<GPUBindGroupEntry>>& value) {
  entries_ = value;
  has_entries_ = true;
}

void GPUBindGroupDescriptor::Trace(Visitor* visitor) const {
  visitor->Trace(entries_);
  visitor->Trace(layout_);
  GPUObjectDescriptorBase::Trace(visitor);
}

}  // namespace blink
