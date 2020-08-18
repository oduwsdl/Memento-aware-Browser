// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_CUSTOM_INTRINSIC_SIZES_RESULT_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_CUSTOM_INTRINSIC_SIZES_RESULT_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class CORE_EXPORT IntrinsicSizesResultOptions : public IDLDictionaryBase {
 public:
  static IntrinsicSizesResultOptions* Create() { return MakeGarbageCollected<IntrinsicSizesResultOptions>(); }
  static IntrinsicSizesResultOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<IntrinsicSizesResultOptions>();
  }

  IntrinsicSizesResultOptions();
  virtual ~IntrinsicSizesResultOptions();

  bool hasMaxContentSize() const { return has_max_content_size_; }
  double maxContentSize() const {
    DCHECK(has_max_content_size_);
    return max_content_size_;
  }
  inline void setMaxContentSize(double);

  bool hasMinContentSize() const { return has_min_content_size_; }
  double minContentSize() const {
    DCHECK(has_min_content_size_);
    return min_content_size_;
  }
  inline void setMinContentSize(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_max_content_size_ = false;
  bool has_min_content_size_ = false;

  double max_content_size_;
  double min_content_size_;

  friend class V8IntrinsicSizesResultOptions;
};

void IntrinsicSizesResultOptions::setMaxContentSize(double value) {
  max_content_size_ = value;
  has_max_content_size_ = true;
}

void IntrinsicSizesResultOptions::setMinContentSize(double value) {
  min_content_size_ = value;
  has_min_content_size_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_CUSTOM_INTRINSIC_SIZES_RESULT_OPTIONS_H_
