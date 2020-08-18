// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DEVICE_ORIENTATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DEVICE_ORIENTATION_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_device_orientation.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace device_orientation {

// Parameters for the ClearDeviceOrientationOverride command.
class HEADLESS_EXPORT ClearDeviceOrientationOverrideParams {
 public:
  static std::unique_ptr<ClearDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceOrientationOverrideParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceOrientationOverrideParams> Clone() const;

  template<int STATE>
  class ClearDeviceOrientationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceOrientationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceOrientationOverrideParams;
    ClearDeviceOrientationOverrideParamsBuilder() : result_(new ClearDeviceOrientationOverrideParams()) { }

    template<int STEP> ClearDeviceOrientationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceOrientationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceOrientationOverrideParams> result_;
  };

  static ClearDeviceOrientationOverrideParamsBuilder<0> Builder() {
    return ClearDeviceOrientationOverrideParamsBuilder<0>();
  }

 private:
  ClearDeviceOrientationOverrideParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceOrientationOverrideParams);
};


// Result for the ClearDeviceOrientationOverride command.
class HEADLESS_EXPORT ClearDeviceOrientationOverrideResult {
 public:
  static std::unique_ptr<ClearDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceOrientationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceOrientationOverrideResult> Clone() const;

  template<int STATE>
  class ClearDeviceOrientationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceOrientationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceOrientationOverrideResult;
    ClearDeviceOrientationOverrideResultBuilder() : result_(new ClearDeviceOrientationOverrideResult()) { }

    template<int STEP> ClearDeviceOrientationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceOrientationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceOrientationOverrideResult> result_;
  };

  static ClearDeviceOrientationOverrideResultBuilder<0> Builder() {
    return ClearDeviceOrientationOverrideResultBuilder<0>();
  }

 private:
  ClearDeviceOrientationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceOrientationOverrideResult);
};


// Parameters for the SetDeviceOrientationOverride command.
class HEADLESS_EXPORT SetDeviceOrientationOverrideParams {
 public:
  static std::unique_ptr<SetDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceOrientationOverrideParams() { }

  // Mock alpha
  double GetAlpha() const { return alpha_; }
  void SetAlpha(double value) { alpha_ = value; }

  // Mock beta
  double GetBeta() const { return beta_; }
  void SetBeta(double value) { beta_ = value; }

  // Mock gamma
  double GetGamma() const { return gamma_; }
  void SetGamma(double value) { gamma_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceOrientationOverrideParams> Clone() const;

  template<int STATE>
  class SetDeviceOrientationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAlphaSet = 1 << 1,
    kBetaSet = 1 << 2,
    kGammaSet = 1 << 3,
      kAllRequiredFieldsSet = (kAlphaSet | kBetaSet | kGammaSet | 0)
    };

    SetDeviceOrientationOverrideParamsBuilder<STATE | kAlphaSet>& SetAlpha(double value) {
      static_assert(!(STATE & kAlphaSet), "property alpha should not have already been set");
      result_->SetAlpha(value);
      return CastState<kAlphaSet>();
    }

    SetDeviceOrientationOverrideParamsBuilder<STATE | kBetaSet>& SetBeta(double value) {
      static_assert(!(STATE & kBetaSet), "property beta should not have already been set");
      result_->SetBeta(value);
      return CastState<kBetaSet>();
    }

    SetDeviceOrientationOverrideParamsBuilder<STATE | kGammaSet>& SetGamma(double value) {
      static_assert(!(STATE & kGammaSet), "property gamma should not have already been set");
      result_->SetGamma(value);
      return CastState<kGammaSet>();
    }

    std::unique_ptr<SetDeviceOrientationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceOrientationOverrideParams;
    SetDeviceOrientationOverrideParamsBuilder() : result_(new SetDeviceOrientationOverrideParams()) { }

    template<int STEP> SetDeviceOrientationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceOrientationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceOrientationOverrideParams> result_;
  };

  static SetDeviceOrientationOverrideParamsBuilder<0> Builder() {
    return SetDeviceOrientationOverrideParamsBuilder<0>();
  }

 private:
  SetDeviceOrientationOverrideParams() { }

  double alpha_;
  double beta_;
  double gamma_;

  DISALLOW_COPY_AND_ASSIGN(SetDeviceOrientationOverrideParams);
};


// Result for the SetDeviceOrientationOverride command.
class HEADLESS_EXPORT SetDeviceOrientationOverrideResult {
 public:
  static std::unique_ptr<SetDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceOrientationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceOrientationOverrideResult> Clone() const;

  template<int STATE>
  class SetDeviceOrientationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDeviceOrientationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceOrientationOverrideResult;
    SetDeviceOrientationOverrideResultBuilder() : result_(new SetDeviceOrientationOverrideResult()) { }

    template<int STEP> SetDeviceOrientationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceOrientationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceOrientationOverrideResult> result_;
  };

  static SetDeviceOrientationOverrideResultBuilder<0> Builder() {
    return SetDeviceOrientationOverrideResultBuilder<0>();
  }

 private:
  SetDeviceOrientationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDeviceOrientationOverrideResult);
};


}  // namespace device_orientation

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DEVICE_ORIENTATION_H_
