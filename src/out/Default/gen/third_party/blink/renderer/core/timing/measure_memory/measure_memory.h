// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MeasureMemoryBreakdown;

class CORE_EXPORT MeasureMemory : public IDLDictionaryBase {
 public:
  static MeasureMemory* Create() { return MakeGarbageCollected<MeasureMemory>(); }
  static MeasureMemory* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<MeasureMemory>();
  }

  MeasureMemory();
  virtual ~MeasureMemory();

  bool hasBreakdown() const { return has_breakdown_; }
  const HeapVector<Member<MeasureMemoryBreakdown>>& breakdown() const {
    DCHECK(has_breakdown_);
    return breakdown_;
  }
  void setBreakdown(const HeapVector<Member<MeasureMemoryBreakdown>>&);

  bool hasBytes() const { return has_bytes_; }
  uint64_t bytes() const {
    DCHECK(has_bytes_);
    return bytes_;
  }
  inline void setBytes(uint64_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_breakdown_ = false;
  bool has_bytes_ = false;

  HeapVector<Member<MeasureMemoryBreakdown>> breakdown_;
  uint64_t bytes_;

  friend class V8MeasureMemory;
};

void MeasureMemory::setBytes(uint64_t value) {
  bytes_ = value;
  has_bytes_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_H_
