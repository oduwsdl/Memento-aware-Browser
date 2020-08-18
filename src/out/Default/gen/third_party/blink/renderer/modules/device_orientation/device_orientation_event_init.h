// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_DEVICE_ORIENTATION_DEVICE_ORIENTATION_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_DEVICE_ORIENTATION_DEVICE_ORIENTATION_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT DeviceOrientationEventInit : public EventInit {
 public:
  static DeviceOrientationEventInit* Create() { return MakeGarbageCollected<DeviceOrientationEventInit>(); }
  static DeviceOrientationEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<DeviceOrientationEventInit>();
  }

  DeviceOrientationEventInit();
  virtual ~DeviceOrientationEventInit();

  bool hasAbsolute() const { return has_absolute_; }
  bool absolute() const {
    DCHECK(has_absolute_);
    return absolute_;
  }
  inline void setAbsolute(bool);

  bool hasAlpha() const { return has_alpha_; }
  double alpha() const {
    DCHECK(has_alpha_);
    return alpha_;
  }
  inline void setAlpha(double);
  inline void setAlphaToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasAlphaNonNull() const { return has_alpha_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasAlphaNonNull| in advance to check the condition.
  double alphaNonNull() const {
    DCHECK(hasAlphaNonNull());
    return alpha_;
  }

  bool hasBeta() const { return has_beta_; }
  double beta() const {
    DCHECK(has_beta_);
    return beta_;
  }
  inline void setBeta(double);
  inline void setBetaToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasBetaNonNull() const { return has_beta_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasBetaNonNull| in advance to check the condition.
  double betaNonNull() const {
    DCHECK(hasBetaNonNull());
    return beta_;
  }

  bool hasGamma() const { return has_gamma_; }
  double gamma() const {
    DCHECK(has_gamma_);
    return gamma_;
  }
  inline void setGamma(double);
  inline void setGammaToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasGammaNonNull() const { return has_gamma_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasGammaNonNull| in advance to check the condition.
  double gammaNonNull() const {
    DCHECK(hasGammaNonNull());
    return gamma_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_absolute_ = false;
  bool has_alpha_ = false;
  bool has_beta_ = false;
  bool has_gamma_ = false;

  bool absolute_;
  double alpha_;
  double beta_;
  double gamma_;

  friend class V8DeviceOrientationEventInit;
};

void DeviceOrientationEventInit::setAbsolute(bool value) {
  absolute_ = value;
  has_absolute_ = true;
}

void DeviceOrientationEventInit::setAlpha(double value) {
  alpha_ = value;
  has_alpha_ = true;
}

void DeviceOrientationEventInit::setAlphaToNull() {
  has_alpha_ = false;
}

void DeviceOrientationEventInit::setBeta(double value) {
  beta_ = value;
  has_beta_ = true;
}

void DeviceOrientationEventInit::setBetaToNull() {
  has_beta_ = false;
}

void DeviceOrientationEventInit::setGamma(double value) {
  gamma_ = value;
  has_gamma_ = true;
}

void DeviceOrientationEventInit::setGammaToNull() {
  has_gamma_ = false;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_DEVICE_ORIENTATION_DEVICE_ORIENTATION_EVENT_INIT_H_
