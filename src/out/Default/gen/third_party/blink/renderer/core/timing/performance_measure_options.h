// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PERFORMANCE_MEASURE_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PERFORMANCE_MEASURE_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/core/v8/string_or_double.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT PerformanceMeasureOptions : public IDLDictionaryBase {
 public:
  static PerformanceMeasureOptions* Create() { return MakeGarbageCollected<PerformanceMeasureOptions>(); }
  static PerformanceMeasureOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<PerformanceMeasureOptions>();
  }

  PerformanceMeasureOptions();
  virtual ~PerformanceMeasureOptions();

  bool hasDetail() const { return !(detail_.IsEmpty() || detail_.IsUndefined()); }
  ScriptValue detail() const {
    return detail_;
  }
  void setDetail(ScriptValue);

  bool hasDuration() const { return has_duration_; }
  double duration() const {
    DCHECK(has_duration_);
    return duration_;
  }
  inline void setDuration(double);

  bool hasEnd() const { return !end_.IsNull(); }
  const StringOrDouble& end() const {
    return end_;
  }
  void setEnd(const StringOrDouble&);

  bool hasStart() const { return !start_.IsNull(); }
  const StringOrDouble& start() const {
    return start_;
  }
  void setStart(const StringOrDouble&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_duration_ = false;

  ScriptValue detail_;
  double duration_;
  StringOrDouble end_;
  StringOrDouble start_;

  friend class V8PerformanceMeasureOptions;
};

void PerformanceMeasureOptions::setDuration(double value) {
  duration_ = value;
  has_duration_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_TIMING_PERFORMANCE_MEASURE_OPTIONS_H_
