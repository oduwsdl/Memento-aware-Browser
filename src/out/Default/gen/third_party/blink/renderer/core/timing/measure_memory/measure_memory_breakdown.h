// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_BREAKDOWN_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_BREAKDOWN_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class CORE_EXPORT MeasureMemoryBreakdown : public IDLDictionaryBase {
 public:
  static MeasureMemoryBreakdown* Create() { return MakeGarbageCollected<MeasureMemoryBreakdown>(); }
  static MeasureMemoryBreakdown* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<MeasureMemoryBreakdown>();
  }

  MeasureMemoryBreakdown();
  virtual ~MeasureMemoryBreakdown();

  bool hasAttribution() const { return has_attribution_; }
  const Vector<String>& attribution() const {
    DCHECK(has_attribution_);
    return attribution_;
  }
  void setAttribution(const Vector<String>&);

  bool hasBytes() const { return has_bytes_; }
  uint64_t bytes() const {
    DCHECK(has_bytes_);
    return bytes_;
  }
  inline void setBytes(uint64_t);

  bool hasUserAgentSpecificTypes() const { return has_user_agent_specific_types_; }
  const Vector<String>& userAgentSpecificTypes() const {
    DCHECK(has_user_agent_specific_types_);
    return user_agent_specific_types_;
  }
  void setUserAgentSpecificTypes(const Vector<String>&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_attribution_ = false;
  bool has_bytes_ = false;
  bool has_user_agent_specific_types_ = false;

  Vector<String> attribution_;
  uint64_t bytes_;
  Vector<String> user_agent_specific_types_;

  friend class V8MeasureMemoryBreakdown;
};

void MeasureMemoryBreakdown::setBytes(uint64_t value) {
  bytes_ = value;
  has_bytes_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_MEASURE_MEMORY_MEASURE_MEMORY_BREAKDOWN_H_
