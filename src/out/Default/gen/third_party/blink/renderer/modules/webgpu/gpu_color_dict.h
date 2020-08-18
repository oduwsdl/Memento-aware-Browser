// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_COLOR_DICT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_COLOR_DICT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT GPUColorDict : public IDLDictionaryBase {
 public:
  static GPUColorDict* Create() { return MakeGarbageCollected<GPUColorDict>(); }
  static GPUColorDict* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<GPUColorDict>();
  }

  GPUColorDict();
  virtual ~GPUColorDict();

  bool hasA() const { return has_a_; }
  double a() const {
    DCHECK(has_a_);
    return a_;
  }
  inline void setA(double);

  bool hasB() const { return has_b_; }
  double b() const {
    DCHECK(has_b_);
    return b_;
  }
  inline void setB(double);

  bool hasG() const { return has_g_; }
  double g() const {
    DCHECK(has_g_);
    return g_;
  }
  inline void setG(double);

  bool hasR() const { return has_r_; }
  double r() const {
    DCHECK(has_r_);
    return r_;
  }
  inline void setR(double);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_a_ = false;
  bool has_b_ = false;
  bool has_g_ = false;
  bool has_r_ = false;

  double a_;
  double b_;
  double g_;
  double r_;

  friend class V8GPUColorDict;
};

void GPUColorDict::setA(double value) {
  a_ = value;
  has_a_ = true;
}

void GPUColorDict::setB(double value) {
  b_ = value;
  has_b_ = true;
}

void GPUColorDict::setG(double value) {
  g_ = value;
  has_g_ = true;
}

void GPUColorDict::setR(double value) {
  r_ = value;
  has_r_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBGPU_GPU_COLOR_DICT_H_
