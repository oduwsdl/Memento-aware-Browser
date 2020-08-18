// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_EMULATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_EMULATION_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace emulation {

// Screen orientation.
class HEADLESS_EXPORT ScreenOrientation {
 public:
  static std::unique_ptr<ScreenOrientation> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScreenOrientation() { }

  // Orientation type.
  ::headless::emulation::ScreenOrientationType GetType() const { return type_; }
  void SetType(::headless::emulation::ScreenOrientationType value) { type_ = value; }

  // Orientation angle.
  int GetAngle() const { return angle_; }
  void SetAngle(int value) { angle_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScreenOrientation> Clone() const;

  template<int STATE>
  class ScreenOrientationBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kAngleSet = 1 << 2,
      kAllRequiredFieldsSet = (kTypeSet | kAngleSet | 0)
    };

    ScreenOrientationBuilder<STATE | kTypeSet>& SetType(::headless::emulation::ScreenOrientationType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    ScreenOrientationBuilder<STATE | kAngleSet>& SetAngle(int value) {
      static_assert(!(STATE & kAngleSet), "property angle should not have already been set");
      result_->SetAngle(value);
      return CastState<kAngleSet>();
    }

    std::unique_ptr<ScreenOrientation> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScreenOrientation;
    ScreenOrientationBuilder() : result_(new ScreenOrientation()) { }

    template<int STEP> ScreenOrientationBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScreenOrientationBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScreenOrientation> result_;
  };

  static ScreenOrientationBuilder<0> Builder() {
    return ScreenOrientationBuilder<0>();
  }

 private:
  ScreenOrientation() { }

  ::headless::emulation::ScreenOrientationType type_;
  int angle_;

  DISALLOW_COPY_AND_ASSIGN(ScreenOrientation);
};


class HEADLESS_EXPORT MediaFeature {
 public:
  static std::unique_ptr<MediaFeature> Parse(const base::Value& value, ErrorReporter* errors);
  ~MediaFeature() { }

  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MediaFeature> Clone() const;

  template<int STATE>
  class MediaFeatureBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    MediaFeatureBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    MediaFeatureBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<MediaFeature> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MediaFeature;
    MediaFeatureBuilder() : result_(new MediaFeature()) { }

    template<int STEP> MediaFeatureBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MediaFeatureBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MediaFeature> result_;
  };

  static MediaFeatureBuilder<0> Builder() {
    return MediaFeatureBuilder<0>();
  }

 private:
  MediaFeature() { }

  std::string name_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(MediaFeature);
};


// Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
class HEADLESS_EXPORT UserAgentBrandVersion {
 public:
  static std::unique_ptr<UserAgentBrandVersion> Parse(const base::Value& value, ErrorReporter* errors);
  ~UserAgentBrandVersion() { }

  std::string GetBrand() const { return brand_; }
  void SetBrand(const std::string& value) { brand_ = value; }

  std::string GetVersion() const { return version_; }
  void SetVersion(const std::string& value) { version_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UserAgentBrandVersion> Clone() const;

  template<int STATE>
  class UserAgentBrandVersionBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBrandSet = 1 << 1,
    kVersionSet = 1 << 2,
      kAllRequiredFieldsSet = (kBrandSet | kVersionSet | 0)
    };

    UserAgentBrandVersionBuilder<STATE | kBrandSet>& SetBrand(const std::string& value) {
      static_assert(!(STATE & kBrandSet), "property brand should not have already been set");
      result_->SetBrand(value);
      return CastState<kBrandSet>();
    }

    UserAgentBrandVersionBuilder<STATE | kVersionSet>& SetVersion(const std::string& value) {
      static_assert(!(STATE & kVersionSet), "property version should not have already been set");
      result_->SetVersion(value);
      return CastState<kVersionSet>();
    }

    std::unique_ptr<UserAgentBrandVersion> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UserAgentBrandVersion;
    UserAgentBrandVersionBuilder() : result_(new UserAgentBrandVersion()) { }

    template<int STEP> UserAgentBrandVersionBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UserAgentBrandVersionBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UserAgentBrandVersion> result_;
  };

  static UserAgentBrandVersionBuilder<0> Builder() {
    return UserAgentBrandVersionBuilder<0>();
  }

 private:
  UserAgentBrandVersion() { }

  std::string brand_;
  std::string version_;

  DISALLOW_COPY_AND_ASSIGN(UserAgentBrandVersion);
};


// Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
class HEADLESS_EXPORT UserAgentMetadata {
 public:
  static std::unique_ptr<UserAgentMetadata> Parse(const base::Value& value, ErrorReporter* errors);
  ~UserAgentMetadata() { }

  const std::vector<std::unique_ptr<::headless::emulation::UserAgentBrandVersion>>* GetBrands() const { return &brands_; }
  void SetBrands(std::vector<std::unique_ptr<::headless::emulation::UserAgentBrandVersion>> value) { brands_ = std::move(value); }

  std::string GetFullVersion() const { return full_version_; }
  void SetFullVersion(const std::string& value) { full_version_ = value; }

  std::string GetPlatform() const { return platform_; }
  void SetPlatform(const std::string& value) { platform_ = value; }

  std::string GetPlatformVersion() const { return platform_version_; }
  void SetPlatformVersion(const std::string& value) { platform_version_ = value; }

  std::string GetArchitecture() const { return architecture_; }
  void SetArchitecture(const std::string& value) { architecture_ = value; }

  std::string GetModel() const { return model_; }
  void SetModel(const std::string& value) { model_ = value; }

  bool GetMobile() const { return mobile_; }
  void SetMobile(bool value) { mobile_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UserAgentMetadata> Clone() const;

  template<int STATE>
  class UserAgentMetadataBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBrandsSet = 1 << 1,
    kFullVersionSet = 1 << 2,
    kPlatformSet = 1 << 3,
    kPlatformVersionSet = 1 << 4,
    kArchitectureSet = 1 << 5,
    kModelSet = 1 << 6,
    kMobileSet = 1 << 7,
      kAllRequiredFieldsSet = (kBrandsSet | kFullVersionSet | kPlatformSet | kPlatformVersionSet | kArchitectureSet | kModelSet | kMobileSet | 0)
    };

    UserAgentMetadataBuilder<STATE | kBrandsSet>& SetBrands(std::vector<std::unique_ptr<::headless::emulation::UserAgentBrandVersion>> value) {
      static_assert(!(STATE & kBrandsSet), "property brands should not have already been set");
      result_->SetBrands(std::move(value));
      return CastState<kBrandsSet>();
    }

    UserAgentMetadataBuilder<STATE | kFullVersionSet>& SetFullVersion(const std::string& value) {
      static_assert(!(STATE & kFullVersionSet), "property fullVersion should not have already been set");
      result_->SetFullVersion(value);
      return CastState<kFullVersionSet>();
    }

    UserAgentMetadataBuilder<STATE | kPlatformSet>& SetPlatform(const std::string& value) {
      static_assert(!(STATE & kPlatformSet), "property platform should not have already been set");
      result_->SetPlatform(value);
      return CastState<kPlatformSet>();
    }

    UserAgentMetadataBuilder<STATE | kPlatformVersionSet>& SetPlatformVersion(const std::string& value) {
      static_assert(!(STATE & kPlatformVersionSet), "property platformVersion should not have already been set");
      result_->SetPlatformVersion(value);
      return CastState<kPlatformVersionSet>();
    }

    UserAgentMetadataBuilder<STATE | kArchitectureSet>& SetArchitecture(const std::string& value) {
      static_assert(!(STATE & kArchitectureSet), "property architecture should not have already been set");
      result_->SetArchitecture(value);
      return CastState<kArchitectureSet>();
    }

    UserAgentMetadataBuilder<STATE | kModelSet>& SetModel(const std::string& value) {
      static_assert(!(STATE & kModelSet), "property model should not have already been set");
      result_->SetModel(value);
      return CastState<kModelSet>();
    }

    UserAgentMetadataBuilder<STATE | kMobileSet>& SetMobile(bool value) {
      static_assert(!(STATE & kMobileSet), "property mobile should not have already been set");
      result_->SetMobile(value);
      return CastState<kMobileSet>();
    }

    std::unique_ptr<UserAgentMetadata> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UserAgentMetadata;
    UserAgentMetadataBuilder() : result_(new UserAgentMetadata()) { }

    template<int STEP> UserAgentMetadataBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UserAgentMetadataBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UserAgentMetadata> result_;
  };

  static UserAgentMetadataBuilder<0> Builder() {
    return UserAgentMetadataBuilder<0>();
  }

 private:
  UserAgentMetadata() { }

  std::vector<std::unique_ptr<::headless::emulation::UserAgentBrandVersion>> brands_;
  std::string full_version_;
  std::string platform_;
  std::string platform_version_;
  std::string architecture_;
  std::string model_;
  bool mobile_;

  DISALLOW_COPY_AND_ASSIGN(UserAgentMetadata);
};


// Parameters for the CanEmulate command.
class HEADLESS_EXPORT CanEmulateParams {
 public:
  static std::unique_ptr<CanEmulateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanEmulateParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanEmulateParams> Clone() const;

  template<int STATE>
  class CanEmulateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CanEmulateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanEmulateParams;
    CanEmulateParamsBuilder() : result_(new CanEmulateParams()) { }

    template<int STEP> CanEmulateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanEmulateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanEmulateParams> result_;
  };

  static CanEmulateParamsBuilder<0> Builder() {
    return CanEmulateParamsBuilder<0>();
  }

 private:
  CanEmulateParams() { }


  DISALLOW_COPY_AND_ASSIGN(CanEmulateParams);
};


// Result for the CanEmulate command.
class HEADLESS_EXPORT CanEmulateResult {
 public:
  static std::unique_ptr<CanEmulateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanEmulateResult() { }

  // True if emulation is supported.
  bool GetResult() const { return result_; }
  void SetResult(bool value) { result_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanEmulateResult> Clone() const;

  template<int STATE>
  class CanEmulateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    CanEmulateResultBuilder<STATE | kResultSet>& SetResult(bool value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(value);
      return CastState<kResultSet>();
    }

    std::unique_ptr<CanEmulateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanEmulateResult;
    CanEmulateResultBuilder() : result_(new CanEmulateResult()) { }

    template<int STEP> CanEmulateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanEmulateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanEmulateResult> result_;
  };

  static CanEmulateResultBuilder<0> Builder() {
    return CanEmulateResultBuilder<0>();
  }

 private:
  CanEmulateResult() { }

  bool result_;

  DISALLOW_COPY_AND_ASSIGN(CanEmulateResult);
};


// Parameters for the ClearDeviceMetricsOverride command.
class HEADLESS_EXPORT ClearDeviceMetricsOverrideParams {
 public:
  static std::unique_ptr<ClearDeviceMetricsOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceMetricsOverrideParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceMetricsOverrideParams> Clone() const;

  template<int STATE>
  class ClearDeviceMetricsOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceMetricsOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceMetricsOverrideParams;
    ClearDeviceMetricsOverrideParamsBuilder() : result_(new ClearDeviceMetricsOverrideParams()) { }

    template<int STEP> ClearDeviceMetricsOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceMetricsOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceMetricsOverrideParams> result_;
  };

  static ClearDeviceMetricsOverrideParamsBuilder<0> Builder() {
    return ClearDeviceMetricsOverrideParamsBuilder<0>();
  }

 private:
  ClearDeviceMetricsOverrideParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceMetricsOverrideParams);
};


// Result for the ClearDeviceMetricsOverride command.
class HEADLESS_EXPORT ClearDeviceMetricsOverrideResult {
 public:
  static std::unique_ptr<ClearDeviceMetricsOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceMetricsOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceMetricsOverrideResult> Clone() const;

  template<int STATE>
  class ClearDeviceMetricsOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceMetricsOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceMetricsOverrideResult;
    ClearDeviceMetricsOverrideResultBuilder() : result_(new ClearDeviceMetricsOverrideResult()) { }

    template<int STEP> ClearDeviceMetricsOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceMetricsOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceMetricsOverrideResult> result_;
  };

  static ClearDeviceMetricsOverrideResultBuilder<0> Builder() {
    return ClearDeviceMetricsOverrideResultBuilder<0>();
  }

 private:
  ClearDeviceMetricsOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceMetricsOverrideResult);
};


// Parameters for the ClearGeolocationOverride command.
class HEADLESS_EXPORT ClearGeolocationOverrideParams {
 public:
  static std::unique_ptr<ClearGeolocationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearGeolocationOverrideParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearGeolocationOverrideParams> Clone() const;

  template<int STATE>
  class ClearGeolocationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearGeolocationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearGeolocationOverrideParams;
    ClearGeolocationOverrideParamsBuilder() : result_(new ClearGeolocationOverrideParams()) { }

    template<int STEP> ClearGeolocationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearGeolocationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearGeolocationOverrideParams> result_;
  };

  static ClearGeolocationOverrideParamsBuilder<0> Builder() {
    return ClearGeolocationOverrideParamsBuilder<0>();
  }

 private:
  ClearGeolocationOverrideParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearGeolocationOverrideParams);
};


// Result for the ClearGeolocationOverride command.
class HEADLESS_EXPORT ClearGeolocationOverrideResult {
 public:
  static std::unique_ptr<ClearGeolocationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearGeolocationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearGeolocationOverrideResult> Clone() const;

  template<int STATE>
  class ClearGeolocationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearGeolocationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearGeolocationOverrideResult;
    ClearGeolocationOverrideResultBuilder() : result_(new ClearGeolocationOverrideResult()) { }

    template<int STEP> ClearGeolocationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearGeolocationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearGeolocationOverrideResult> result_;
  };

  static ClearGeolocationOverrideResultBuilder<0> Builder() {
    return ClearGeolocationOverrideResultBuilder<0>();
  }

 private:
  ClearGeolocationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearGeolocationOverrideResult);
};


// Parameters for the ResetPageScaleFactor command.
class HEADLESS_EXPORT ResetPageScaleFactorParams {
 public:
  static std::unique_ptr<ResetPageScaleFactorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResetPageScaleFactorParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResetPageScaleFactorParams> Clone() const;

  template<int STATE>
  class ResetPageScaleFactorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ResetPageScaleFactorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResetPageScaleFactorParams;
    ResetPageScaleFactorParamsBuilder() : result_(new ResetPageScaleFactorParams()) { }

    template<int STEP> ResetPageScaleFactorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResetPageScaleFactorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResetPageScaleFactorParams> result_;
  };

  static ResetPageScaleFactorParamsBuilder<0> Builder() {
    return ResetPageScaleFactorParamsBuilder<0>();
  }

 private:
  ResetPageScaleFactorParams() { }


  DISALLOW_COPY_AND_ASSIGN(ResetPageScaleFactorParams);
};


// Result for the ResetPageScaleFactor command.
class HEADLESS_EXPORT ResetPageScaleFactorResult {
 public:
  static std::unique_ptr<ResetPageScaleFactorResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResetPageScaleFactorResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResetPageScaleFactorResult> Clone() const;

  template<int STATE>
  class ResetPageScaleFactorResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ResetPageScaleFactorResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResetPageScaleFactorResult;
    ResetPageScaleFactorResultBuilder() : result_(new ResetPageScaleFactorResult()) { }

    template<int STEP> ResetPageScaleFactorResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResetPageScaleFactorResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResetPageScaleFactorResult> result_;
  };

  static ResetPageScaleFactorResultBuilder<0> Builder() {
    return ResetPageScaleFactorResultBuilder<0>();
  }

 private:
  ResetPageScaleFactorResult() { }


  DISALLOW_COPY_AND_ASSIGN(ResetPageScaleFactorResult);
};


// Parameters for the SetFocusEmulationEnabled command.
class HEADLESS_EXPORT SetFocusEmulationEnabledParams {
 public:
  static std::unique_ptr<SetFocusEmulationEnabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFocusEmulationEnabledParams() { }

  // Whether to enable to disable focus emulation.
  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFocusEmulationEnabledParams> Clone() const;

  template<int STATE>
  class SetFocusEmulationEnabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetFocusEmulationEnabledParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    std::unique_ptr<SetFocusEmulationEnabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFocusEmulationEnabledParams;
    SetFocusEmulationEnabledParamsBuilder() : result_(new SetFocusEmulationEnabledParams()) { }

    template<int STEP> SetFocusEmulationEnabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFocusEmulationEnabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFocusEmulationEnabledParams> result_;
  };

  static SetFocusEmulationEnabledParamsBuilder<0> Builder() {
    return SetFocusEmulationEnabledParamsBuilder<0>();
  }

 private:
  SetFocusEmulationEnabledParams() { }

  bool enabled_;

  DISALLOW_COPY_AND_ASSIGN(SetFocusEmulationEnabledParams);
};


// Result for the SetFocusEmulationEnabled command.
class HEADLESS_EXPORT SetFocusEmulationEnabledResult {
 public:
  static std::unique_ptr<SetFocusEmulationEnabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFocusEmulationEnabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFocusEmulationEnabledResult> Clone() const;

  template<int STATE>
  class SetFocusEmulationEnabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetFocusEmulationEnabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFocusEmulationEnabledResult;
    SetFocusEmulationEnabledResultBuilder() : result_(new SetFocusEmulationEnabledResult()) { }

    template<int STEP> SetFocusEmulationEnabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFocusEmulationEnabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFocusEmulationEnabledResult> result_;
  };

  static SetFocusEmulationEnabledResultBuilder<0> Builder() {
    return SetFocusEmulationEnabledResultBuilder<0>();
  }

 private:
  SetFocusEmulationEnabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetFocusEmulationEnabledResult);
};


// Parameters for the SetCPUThrottlingRate command.
class HEADLESS_EXPORT SetCPUThrottlingRateParams {
 public:
  static std::unique_ptr<SetCPUThrottlingRateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCPUThrottlingRateParams() { }

  // Throttling rate as a slowdown factor (1 is no throttle, 2 is 2x slowdown, etc).
  double GetRate() const { return rate_; }
  void SetRate(double value) { rate_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCPUThrottlingRateParams> Clone() const;

  template<int STATE>
  class SetCPUThrottlingRateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRateSet = 1 << 1,
      kAllRequiredFieldsSet = (kRateSet | 0)
    };

    SetCPUThrottlingRateParamsBuilder<STATE | kRateSet>& SetRate(double value) {
      static_assert(!(STATE & kRateSet), "property rate should not have already been set");
      result_->SetRate(value);
      return CastState<kRateSet>();
    }

    std::unique_ptr<SetCPUThrottlingRateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCPUThrottlingRateParams;
    SetCPUThrottlingRateParamsBuilder() : result_(new SetCPUThrottlingRateParams()) { }

    template<int STEP> SetCPUThrottlingRateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCPUThrottlingRateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCPUThrottlingRateParams> result_;
  };

  static SetCPUThrottlingRateParamsBuilder<0> Builder() {
    return SetCPUThrottlingRateParamsBuilder<0>();
  }

 private:
  SetCPUThrottlingRateParams() { }

  double rate_;

  DISALLOW_COPY_AND_ASSIGN(SetCPUThrottlingRateParams);
};


// Result for the SetCPUThrottlingRate command.
class HEADLESS_EXPORT SetCPUThrottlingRateResult {
 public:
  static std::unique_ptr<SetCPUThrottlingRateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCPUThrottlingRateResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCPUThrottlingRateResult> Clone() const;

  template<int STATE>
  class SetCPUThrottlingRateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetCPUThrottlingRateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCPUThrottlingRateResult;
    SetCPUThrottlingRateResultBuilder() : result_(new SetCPUThrottlingRateResult()) { }

    template<int STEP> SetCPUThrottlingRateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCPUThrottlingRateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCPUThrottlingRateResult> result_;
  };

  static SetCPUThrottlingRateResultBuilder<0> Builder() {
    return SetCPUThrottlingRateResultBuilder<0>();
  }

 private:
  SetCPUThrottlingRateResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetCPUThrottlingRateResult);
};


// Parameters for the SetDefaultBackgroundColorOverride command.
class HEADLESS_EXPORT SetDefaultBackgroundColorOverrideParams {
 public:
  static std::unique_ptr<SetDefaultBackgroundColorOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDefaultBackgroundColorOverrideParams() { }

  // RGBA of the default background color. If not specified, any existing override will be
  // cleared.
  bool HasColor() const { return !!color_; }
  const ::headless::dom::RGBA* GetColor() const { DCHECK(HasColor()); return color_.value().get(); }
  void SetColor(std::unique_ptr<::headless::dom::RGBA> value) { color_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDefaultBackgroundColorOverrideParams> Clone() const;

  template<int STATE>
  class SetDefaultBackgroundColorOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    SetDefaultBackgroundColorOverrideParamsBuilder<STATE>& SetColor(std::unique_ptr<::headless::dom::RGBA> value) {
      result_->SetColor(std::move(value));
      return *this;
    }

    std::unique_ptr<SetDefaultBackgroundColorOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDefaultBackgroundColorOverrideParams;
    SetDefaultBackgroundColorOverrideParamsBuilder() : result_(new SetDefaultBackgroundColorOverrideParams()) { }

    template<int STEP> SetDefaultBackgroundColorOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDefaultBackgroundColorOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDefaultBackgroundColorOverrideParams> result_;
  };

  static SetDefaultBackgroundColorOverrideParamsBuilder<0> Builder() {
    return SetDefaultBackgroundColorOverrideParamsBuilder<0>();
  }

 private:
  SetDefaultBackgroundColorOverrideParams() { }

  base::Optional<std::unique_ptr<::headless::dom::RGBA>> color_;

  DISALLOW_COPY_AND_ASSIGN(SetDefaultBackgroundColorOverrideParams);
};


// Result for the SetDefaultBackgroundColorOverride command.
class HEADLESS_EXPORT SetDefaultBackgroundColorOverrideResult {
 public:
  static std::unique_ptr<SetDefaultBackgroundColorOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDefaultBackgroundColorOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDefaultBackgroundColorOverrideResult> Clone() const;

  template<int STATE>
  class SetDefaultBackgroundColorOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDefaultBackgroundColorOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDefaultBackgroundColorOverrideResult;
    SetDefaultBackgroundColorOverrideResultBuilder() : result_(new SetDefaultBackgroundColorOverrideResult()) { }

    template<int STEP> SetDefaultBackgroundColorOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDefaultBackgroundColorOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDefaultBackgroundColorOverrideResult> result_;
  };

  static SetDefaultBackgroundColorOverrideResultBuilder<0> Builder() {
    return SetDefaultBackgroundColorOverrideResultBuilder<0>();
  }

 private:
  SetDefaultBackgroundColorOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDefaultBackgroundColorOverrideResult);
};


// Parameters for the SetDeviceMetricsOverride command.
class HEADLESS_EXPORT SetDeviceMetricsOverrideParams {
 public:
  static std::unique_ptr<SetDeviceMetricsOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceMetricsOverrideParams() { }

  // Overriding width value in pixels (minimum 0, maximum 10000000). 0 disables the override.
  int GetWidth() const { return width_; }
  void SetWidth(int value) { width_ = value; }

  // Overriding height value in pixels (minimum 0, maximum 10000000). 0 disables the override.
  int GetHeight() const { return height_; }
  void SetHeight(int value) { height_ = value; }

  // Overriding device scale factor value. 0 disables the override.
  double GetDeviceScaleFactor() const { return device_scale_factor_; }
  void SetDeviceScaleFactor(double value) { device_scale_factor_ = value; }

  // Whether to emulate mobile device. This includes viewport meta tag, overlay scrollbars, text
  // autosizing and more.
  bool GetMobile() const { return mobile_; }
  void SetMobile(bool value) { mobile_ = value; }

  // Scale to apply to resulting view image.
  bool HasScale() const { return !!scale_; }
  double GetScale() const { DCHECK(HasScale()); return scale_.value(); }
  void SetScale(double value) { scale_ = value; }

  // Overriding screen width value in pixels (minimum 0, maximum 10000000).
  bool HasScreenWidth() const { return !!screen_width_; }
  int GetScreenWidth() const { DCHECK(HasScreenWidth()); return screen_width_.value(); }
  void SetScreenWidth(int value) { screen_width_ = value; }

  // Overriding screen height value in pixels (minimum 0, maximum 10000000).
  bool HasScreenHeight() const { return !!screen_height_; }
  int GetScreenHeight() const { DCHECK(HasScreenHeight()); return screen_height_.value(); }
  void SetScreenHeight(int value) { screen_height_ = value; }

  // Overriding view X position on screen in pixels (minimum 0, maximum 10000000).
  bool HasPositionX() const { return !!positionx_; }
  int GetPositionX() const { DCHECK(HasPositionX()); return positionx_.value(); }
  void SetPositionX(int value) { positionx_ = value; }

  // Overriding view Y position on screen in pixels (minimum 0, maximum 10000000).
  bool HasPositionY() const { return !!positiony_; }
  int GetPositionY() const { DCHECK(HasPositionY()); return positiony_.value(); }
  void SetPositionY(int value) { positiony_ = value; }

  // Do not set visible view size, rely upon explicit setVisibleSize call.
  bool HasDontSetVisibleSize() const { return !!dont_set_visible_size_; }
  bool GetDontSetVisibleSize() const { DCHECK(HasDontSetVisibleSize()); return dont_set_visible_size_.value(); }
  void SetDontSetVisibleSize(bool value) { dont_set_visible_size_ = value; }

  // Screen orientation override.
  bool HasScreenOrientation() const { return !!screen_orientation_; }
  const ::headless::emulation::ScreenOrientation* GetScreenOrientation() const { DCHECK(HasScreenOrientation()); return screen_orientation_.value().get(); }
  void SetScreenOrientation(std::unique_ptr<::headless::emulation::ScreenOrientation> value) { screen_orientation_ = std::move(value); }

  // If set, the visible area of the page will be overridden to this viewport. This viewport
  // change is not observed by the page, e.g. viewport-relative elements do not change positions.
  bool HasViewport() const { return !!viewport_; }
  const ::headless::page::Viewport* GetViewport() const { DCHECK(HasViewport()); return viewport_.value().get(); }
  void SetViewport(std::unique_ptr<::headless::page::Viewport> value) { viewport_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceMetricsOverrideParams> Clone() const;

  template<int STATE>
  class SetDeviceMetricsOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kWidthSet = 1 << 1,
    kHeightSet = 1 << 2,
    kDeviceScaleFactorSet = 1 << 3,
    kMobileSet = 1 << 4,
      kAllRequiredFieldsSet = (kWidthSet | kHeightSet | kDeviceScaleFactorSet | kMobileSet | 0)
    };

    SetDeviceMetricsOverrideParamsBuilder<STATE | kWidthSet>& SetWidth(int value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE | kHeightSet>& SetHeight(int value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE | kDeviceScaleFactorSet>& SetDeviceScaleFactor(double value) {
      static_assert(!(STATE & kDeviceScaleFactorSet), "property deviceScaleFactor should not have already been set");
      result_->SetDeviceScaleFactor(value);
      return CastState<kDeviceScaleFactorSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE | kMobileSet>& SetMobile(bool value) {
      static_assert(!(STATE & kMobileSet), "property mobile should not have already been set");
      result_->SetMobile(value);
      return CastState<kMobileSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScale(double value) {
      result_->SetScale(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScreenWidth(int value) {
      result_->SetScreenWidth(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScreenHeight(int value) {
      result_->SetScreenHeight(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetPositionX(int value) {
      result_->SetPositionX(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetPositionY(int value) {
      result_->SetPositionY(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetDontSetVisibleSize(bool value) {
      result_->SetDontSetVisibleSize(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScreenOrientation(std::unique_ptr<::headless::emulation::ScreenOrientation> value) {
      result_->SetScreenOrientation(std::move(value));
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetViewport(std::unique_ptr<::headless::page::Viewport> value) {
      result_->SetViewport(std::move(value));
      return *this;
    }

    std::unique_ptr<SetDeviceMetricsOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceMetricsOverrideParams;
    SetDeviceMetricsOverrideParamsBuilder() : result_(new SetDeviceMetricsOverrideParams()) { }

    template<int STEP> SetDeviceMetricsOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceMetricsOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceMetricsOverrideParams> result_;
  };

  static SetDeviceMetricsOverrideParamsBuilder<0> Builder() {
    return SetDeviceMetricsOverrideParamsBuilder<0>();
  }

 private:
  SetDeviceMetricsOverrideParams() { }

  int width_;
  int height_;
  double device_scale_factor_;
  bool mobile_;
  base::Optional<double> scale_;
  base::Optional<int> screen_width_;
  base::Optional<int> screen_height_;
  base::Optional<int> positionx_;
  base::Optional<int> positiony_;
  base::Optional<bool> dont_set_visible_size_;
  base::Optional<std::unique_ptr<::headless::emulation::ScreenOrientation>> screen_orientation_;
  base::Optional<std::unique_ptr<::headless::page::Viewport>> viewport_;

  DISALLOW_COPY_AND_ASSIGN(SetDeviceMetricsOverrideParams);
};


// Result for the SetDeviceMetricsOverride command.
class HEADLESS_EXPORT SetDeviceMetricsOverrideResult {
 public:
  static std::unique_ptr<SetDeviceMetricsOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceMetricsOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceMetricsOverrideResult> Clone() const;

  template<int STATE>
  class SetDeviceMetricsOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDeviceMetricsOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceMetricsOverrideResult;
    SetDeviceMetricsOverrideResultBuilder() : result_(new SetDeviceMetricsOverrideResult()) { }

    template<int STEP> SetDeviceMetricsOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceMetricsOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceMetricsOverrideResult> result_;
  };

  static SetDeviceMetricsOverrideResultBuilder<0> Builder() {
    return SetDeviceMetricsOverrideResultBuilder<0>();
  }

 private:
  SetDeviceMetricsOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDeviceMetricsOverrideResult);
};


// Parameters for the SetScrollbarsHidden command.
class HEADLESS_EXPORT SetScrollbarsHiddenParams {
 public:
  static std::unique_ptr<SetScrollbarsHiddenParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetScrollbarsHiddenParams() { }

  // Whether scrollbars should be always hidden.
  bool GetHidden() const { return hidden_; }
  void SetHidden(bool value) { hidden_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetScrollbarsHiddenParams> Clone() const;

  template<int STATE>
  class SetScrollbarsHiddenParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHiddenSet = 1 << 1,
      kAllRequiredFieldsSet = (kHiddenSet | 0)
    };

    SetScrollbarsHiddenParamsBuilder<STATE | kHiddenSet>& SetHidden(bool value) {
      static_assert(!(STATE & kHiddenSet), "property hidden should not have already been set");
      result_->SetHidden(value);
      return CastState<kHiddenSet>();
    }

    std::unique_ptr<SetScrollbarsHiddenParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetScrollbarsHiddenParams;
    SetScrollbarsHiddenParamsBuilder() : result_(new SetScrollbarsHiddenParams()) { }

    template<int STEP> SetScrollbarsHiddenParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetScrollbarsHiddenParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetScrollbarsHiddenParams> result_;
  };

  static SetScrollbarsHiddenParamsBuilder<0> Builder() {
    return SetScrollbarsHiddenParamsBuilder<0>();
  }

 private:
  SetScrollbarsHiddenParams() { }

  bool hidden_;

  DISALLOW_COPY_AND_ASSIGN(SetScrollbarsHiddenParams);
};


// Result for the SetScrollbarsHidden command.
class HEADLESS_EXPORT SetScrollbarsHiddenResult {
 public:
  static std::unique_ptr<SetScrollbarsHiddenResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetScrollbarsHiddenResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetScrollbarsHiddenResult> Clone() const;

  template<int STATE>
  class SetScrollbarsHiddenResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetScrollbarsHiddenResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetScrollbarsHiddenResult;
    SetScrollbarsHiddenResultBuilder() : result_(new SetScrollbarsHiddenResult()) { }

    template<int STEP> SetScrollbarsHiddenResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetScrollbarsHiddenResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetScrollbarsHiddenResult> result_;
  };

  static SetScrollbarsHiddenResultBuilder<0> Builder() {
    return SetScrollbarsHiddenResultBuilder<0>();
  }

 private:
  SetScrollbarsHiddenResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetScrollbarsHiddenResult);
};


// Parameters for the SetDocumentCookieDisabled command.
class HEADLESS_EXPORT SetDocumentCookieDisabledParams {
 public:
  static std::unique_ptr<SetDocumentCookieDisabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDocumentCookieDisabledParams() { }

  // Whether document.coookie API should be disabled.
  bool GetDisabled() const { return disabled_; }
  void SetDisabled(bool value) { disabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDocumentCookieDisabledParams> Clone() const;

  template<int STATE>
  class SetDocumentCookieDisabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDisabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kDisabledSet | 0)
    };

    SetDocumentCookieDisabledParamsBuilder<STATE | kDisabledSet>& SetDisabled(bool value) {
      static_assert(!(STATE & kDisabledSet), "property disabled should not have already been set");
      result_->SetDisabled(value);
      return CastState<kDisabledSet>();
    }

    std::unique_ptr<SetDocumentCookieDisabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDocumentCookieDisabledParams;
    SetDocumentCookieDisabledParamsBuilder() : result_(new SetDocumentCookieDisabledParams()) { }

    template<int STEP> SetDocumentCookieDisabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDocumentCookieDisabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDocumentCookieDisabledParams> result_;
  };

  static SetDocumentCookieDisabledParamsBuilder<0> Builder() {
    return SetDocumentCookieDisabledParamsBuilder<0>();
  }

 private:
  SetDocumentCookieDisabledParams() { }

  bool disabled_;

  DISALLOW_COPY_AND_ASSIGN(SetDocumentCookieDisabledParams);
};


// Result for the SetDocumentCookieDisabled command.
class HEADLESS_EXPORT SetDocumentCookieDisabledResult {
 public:
  static std::unique_ptr<SetDocumentCookieDisabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDocumentCookieDisabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDocumentCookieDisabledResult> Clone() const;

  template<int STATE>
  class SetDocumentCookieDisabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDocumentCookieDisabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDocumentCookieDisabledResult;
    SetDocumentCookieDisabledResultBuilder() : result_(new SetDocumentCookieDisabledResult()) { }

    template<int STEP> SetDocumentCookieDisabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDocumentCookieDisabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDocumentCookieDisabledResult> result_;
  };

  static SetDocumentCookieDisabledResultBuilder<0> Builder() {
    return SetDocumentCookieDisabledResultBuilder<0>();
  }

 private:
  SetDocumentCookieDisabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDocumentCookieDisabledResult);
};


// Parameters for the SetEmitTouchEventsForMouse command.
class HEADLESS_EXPORT SetEmitTouchEventsForMouseParams {
 public:
  static std::unique_ptr<SetEmitTouchEventsForMouseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetEmitTouchEventsForMouseParams() { }

  // Whether touch emulation based on mouse input should be enabled.
  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  // Touch/gesture events configuration. Default: current platform.
  bool HasConfiguration() const { return !!configuration_; }
  ::headless::emulation::SetEmitTouchEventsForMouseConfiguration GetConfiguration() const { DCHECK(HasConfiguration()); return configuration_.value(); }
  void SetConfiguration(::headless::emulation::SetEmitTouchEventsForMouseConfiguration value) { configuration_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetEmitTouchEventsForMouseParams> Clone() const;

  template<int STATE>
  class SetEmitTouchEventsForMouseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetEmitTouchEventsForMouseParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    SetEmitTouchEventsForMouseParamsBuilder<STATE>& SetConfiguration(::headless::emulation::SetEmitTouchEventsForMouseConfiguration value) {
      result_->SetConfiguration(value);
      return *this;
    }

    std::unique_ptr<SetEmitTouchEventsForMouseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetEmitTouchEventsForMouseParams;
    SetEmitTouchEventsForMouseParamsBuilder() : result_(new SetEmitTouchEventsForMouseParams()) { }

    template<int STEP> SetEmitTouchEventsForMouseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetEmitTouchEventsForMouseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetEmitTouchEventsForMouseParams> result_;
  };

  static SetEmitTouchEventsForMouseParamsBuilder<0> Builder() {
    return SetEmitTouchEventsForMouseParamsBuilder<0>();
  }

 private:
  SetEmitTouchEventsForMouseParams() { }

  bool enabled_;
  base::Optional<::headless::emulation::SetEmitTouchEventsForMouseConfiguration> configuration_;

  DISALLOW_COPY_AND_ASSIGN(SetEmitTouchEventsForMouseParams);
};


// Result for the SetEmitTouchEventsForMouse command.
class HEADLESS_EXPORT SetEmitTouchEventsForMouseResult {
 public:
  static std::unique_ptr<SetEmitTouchEventsForMouseResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetEmitTouchEventsForMouseResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetEmitTouchEventsForMouseResult> Clone() const;

  template<int STATE>
  class SetEmitTouchEventsForMouseResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetEmitTouchEventsForMouseResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetEmitTouchEventsForMouseResult;
    SetEmitTouchEventsForMouseResultBuilder() : result_(new SetEmitTouchEventsForMouseResult()) { }

    template<int STEP> SetEmitTouchEventsForMouseResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetEmitTouchEventsForMouseResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetEmitTouchEventsForMouseResult> result_;
  };

  static SetEmitTouchEventsForMouseResultBuilder<0> Builder() {
    return SetEmitTouchEventsForMouseResultBuilder<0>();
  }

 private:
  SetEmitTouchEventsForMouseResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetEmitTouchEventsForMouseResult);
};


// Parameters for the SetEmulatedMedia command.
class HEADLESS_EXPORT SetEmulatedMediaParams {
 public:
  static std::unique_ptr<SetEmulatedMediaParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetEmulatedMediaParams() { }

  // Media type to emulate. Empty string disables the override.
  bool HasMedia() const { return !!media_; }
  std::string GetMedia() const { DCHECK(HasMedia()); return media_.value(); }
  void SetMedia(const std::string& value) { media_ = value; }

  // Media features to emulate.
  bool HasFeatures() const { return !!features_; }
  const std::vector<std::unique_ptr<::headless::emulation::MediaFeature>>* GetFeatures() const { DCHECK(HasFeatures()); return &features_.value(); }
  void SetFeatures(std::vector<std::unique_ptr<::headless::emulation::MediaFeature>> value) { features_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetEmulatedMediaParams> Clone() const;

  template<int STATE>
  class SetEmulatedMediaParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    SetEmulatedMediaParamsBuilder<STATE>& SetMedia(const std::string& value) {
      result_->SetMedia(value);
      return *this;
    }

    SetEmulatedMediaParamsBuilder<STATE>& SetFeatures(std::vector<std::unique_ptr<::headless::emulation::MediaFeature>> value) {
      result_->SetFeatures(std::move(value));
      return *this;
    }

    std::unique_ptr<SetEmulatedMediaParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetEmulatedMediaParams;
    SetEmulatedMediaParamsBuilder() : result_(new SetEmulatedMediaParams()) { }

    template<int STEP> SetEmulatedMediaParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetEmulatedMediaParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetEmulatedMediaParams> result_;
  };

  static SetEmulatedMediaParamsBuilder<0> Builder() {
    return SetEmulatedMediaParamsBuilder<0>();
  }

 private:
  SetEmulatedMediaParams() { }

  base::Optional<std::string> media_;
  base::Optional<std::vector<std::unique_ptr<::headless::emulation::MediaFeature>>> features_;

  DISALLOW_COPY_AND_ASSIGN(SetEmulatedMediaParams);
};


// Result for the SetEmulatedMedia command.
class HEADLESS_EXPORT SetEmulatedMediaResult {
 public:
  static std::unique_ptr<SetEmulatedMediaResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetEmulatedMediaResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetEmulatedMediaResult> Clone() const;

  template<int STATE>
  class SetEmulatedMediaResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetEmulatedMediaResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetEmulatedMediaResult;
    SetEmulatedMediaResultBuilder() : result_(new SetEmulatedMediaResult()) { }

    template<int STEP> SetEmulatedMediaResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetEmulatedMediaResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetEmulatedMediaResult> result_;
  };

  static SetEmulatedMediaResultBuilder<0> Builder() {
    return SetEmulatedMediaResultBuilder<0>();
  }

 private:
  SetEmulatedMediaResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetEmulatedMediaResult);
};


// Parameters for the SetEmulatedVisionDeficiency command.
class HEADLESS_EXPORT SetEmulatedVisionDeficiencyParams {
 public:
  static std::unique_ptr<SetEmulatedVisionDeficiencyParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetEmulatedVisionDeficiencyParams() { }

  // Vision deficiency to emulate.
  ::headless::emulation::SetEmulatedVisionDeficiencyType GetType() const { return type_; }
  void SetType(::headless::emulation::SetEmulatedVisionDeficiencyType value) { type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetEmulatedVisionDeficiencyParams> Clone() const;

  template<int STATE>
  class SetEmulatedVisionDeficiencyParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    SetEmulatedVisionDeficiencyParamsBuilder<STATE | kTypeSet>& SetType(::headless::emulation::SetEmulatedVisionDeficiencyType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    std::unique_ptr<SetEmulatedVisionDeficiencyParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetEmulatedVisionDeficiencyParams;
    SetEmulatedVisionDeficiencyParamsBuilder() : result_(new SetEmulatedVisionDeficiencyParams()) { }

    template<int STEP> SetEmulatedVisionDeficiencyParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetEmulatedVisionDeficiencyParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetEmulatedVisionDeficiencyParams> result_;
  };

  static SetEmulatedVisionDeficiencyParamsBuilder<0> Builder() {
    return SetEmulatedVisionDeficiencyParamsBuilder<0>();
  }

 private:
  SetEmulatedVisionDeficiencyParams() { }

  ::headless::emulation::SetEmulatedVisionDeficiencyType type_;

  DISALLOW_COPY_AND_ASSIGN(SetEmulatedVisionDeficiencyParams);
};


// Result for the SetEmulatedVisionDeficiency command.
class HEADLESS_EXPORT SetEmulatedVisionDeficiencyResult {
 public:
  static std::unique_ptr<SetEmulatedVisionDeficiencyResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetEmulatedVisionDeficiencyResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetEmulatedVisionDeficiencyResult> Clone() const;

  template<int STATE>
  class SetEmulatedVisionDeficiencyResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetEmulatedVisionDeficiencyResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetEmulatedVisionDeficiencyResult;
    SetEmulatedVisionDeficiencyResultBuilder() : result_(new SetEmulatedVisionDeficiencyResult()) { }

    template<int STEP> SetEmulatedVisionDeficiencyResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetEmulatedVisionDeficiencyResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetEmulatedVisionDeficiencyResult> result_;
  };

  static SetEmulatedVisionDeficiencyResultBuilder<0> Builder() {
    return SetEmulatedVisionDeficiencyResultBuilder<0>();
  }

 private:
  SetEmulatedVisionDeficiencyResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetEmulatedVisionDeficiencyResult);
};


// Parameters for the SetGeolocationOverride command.
class HEADLESS_EXPORT SetGeolocationOverrideParams {
 public:
  static std::unique_ptr<SetGeolocationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetGeolocationOverrideParams() { }

  // Mock latitude
  bool HasLatitude() const { return !!latitude_; }
  double GetLatitude() const { DCHECK(HasLatitude()); return latitude_.value(); }
  void SetLatitude(double value) { latitude_ = value; }

  // Mock longitude
  bool HasLongitude() const { return !!longitude_; }
  double GetLongitude() const { DCHECK(HasLongitude()); return longitude_.value(); }
  void SetLongitude(double value) { longitude_ = value; }

  // Mock accuracy
  bool HasAccuracy() const { return !!accuracy_; }
  double GetAccuracy() const { DCHECK(HasAccuracy()); return accuracy_.value(); }
  void SetAccuracy(double value) { accuracy_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetGeolocationOverrideParams> Clone() const;

  template<int STATE>
  class SetGeolocationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    SetGeolocationOverrideParamsBuilder<STATE>& SetLatitude(double value) {
      result_->SetLatitude(value);
      return *this;
    }

    SetGeolocationOverrideParamsBuilder<STATE>& SetLongitude(double value) {
      result_->SetLongitude(value);
      return *this;
    }

    SetGeolocationOverrideParamsBuilder<STATE>& SetAccuracy(double value) {
      result_->SetAccuracy(value);
      return *this;
    }

    std::unique_ptr<SetGeolocationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetGeolocationOverrideParams;
    SetGeolocationOverrideParamsBuilder() : result_(new SetGeolocationOverrideParams()) { }

    template<int STEP> SetGeolocationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetGeolocationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetGeolocationOverrideParams> result_;
  };

  static SetGeolocationOverrideParamsBuilder<0> Builder() {
    return SetGeolocationOverrideParamsBuilder<0>();
  }

 private:
  SetGeolocationOverrideParams() { }

  base::Optional<double> latitude_;
  base::Optional<double> longitude_;
  base::Optional<double> accuracy_;

  DISALLOW_COPY_AND_ASSIGN(SetGeolocationOverrideParams);
};


// Result for the SetGeolocationOverride command.
class HEADLESS_EXPORT SetGeolocationOverrideResult {
 public:
  static std::unique_ptr<SetGeolocationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetGeolocationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetGeolocationOverrideResult> Clone() const;

  template<int STATE>
  class SetGeolocationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetGeolocationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetGeolocationOverrideResult;
    SetGeolocationOverrideResultBuilder() : result_(new SetGeolocationOverrideResult()) { }

    template<int STEP> SetGeolocationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetGeolocationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetGeolocationOverrideResult> result_;
  };

  static SetGeolocationOverrideResultBuilder<0> Builder() {
    return SetGeolocationOverrideResultBuilder<0>();
  }

 private:
  SetGeolocationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetGeolocationOverrideResult);
};


// Parameters for the SetNavigatorOverrides command.
class HEADLESS_EXPORT SetNavigatorOverridesParams {
 public:
  static std::unique_ptr<SetNavigatorOverridesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNavigatorOverridesParams() { }

  // The platform navigator.platform should return.
  std::string GetPlatform() const { return platform_; }
  void SetPlatform(const std::string& value) { platform_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNavigatorOverridesParams> Clone() const;

  template<int STATE>
  class SetNavigatorOverridesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlatformSet = 1 << 1,
      kAllRequiredFieldsSet = (kPlatformSet | 0)
    };

    SetNavigatorOverridesParamsBuilder<STATE | kPlatformSet>& SetPlatform(const std::string& value) {
      static_assert(!(STATE & kPlatformSet), "property platform should not have already been set");
      result_->SetPlatform(value);
      return CastState<kPlatformSet>();
    }

    std::unique_ptr<SetNavigatorOverridesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNavigatorOverridesParams;
    SetNavigatorOverridesParamsBuilder() : result_(new SetNavigatorOverridesParams()) { }

    template<int STEP> SetNavigatorOverridesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNavigatorOverridesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNavigatorOverridesParams> result_;
  };

  static SetNavigatorOverridesParamsBuilder<0> Builder() {
    return SetNavigatorOverridesParamsBuilder<0>();
  }

 private:
  SetNavigatorOverridesParams() { }

  std::string platform_;

  DISALLOW_COPY_AND_ASSIGN(SetNavigatorOverridesParams);
};


// Result for the SetNavigatorOverrides command.
class HEADLESS_EXPORT SetNavigatorOverridesResult {
 public:
  static std::unique_ptr<SetNavigatorOverridesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetNavigatorOverridesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetNavigatorOverridesResult> Clone() const;

  template<int STATE>
  class SetNavigatorOverridesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetNavigatorOverridesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetNavigatorOverridesResult;
    SetNavigatorOverridesResultBuilder() : result_(new SetNavigatorOverridesResult()) { }

    template<int STEP> SetNavigatorOverridesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetNavigatorOverridesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetNavigatorOverridesResult> result_;
  };

  static SetNavigatorOverridesResultBuilder<0> Builder() {
    return SetNavigatorOverridesResultBuilder<0>();
  }

 private:
  SetNavigatorOverridesResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetNavigatorOverridesResult);
};


// Parameters for the SetPageScaleFactor command.
class HEADLESS_EXPORT SetPageScaleFactorParams {
 public:
  static std::unique_ptr<SetPageScaleFactorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPageScaleFactorParams() { }

  // Page scale factor.
  double GetPageScaleFactor() const { return page_scale_factor_; }
  void SetPageScaleFactor(double value) { page_scale_factor_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPageScaleFactorParams> Clone() const;

  template<int STATE>
  class SetPageScaleFactorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPageScaleFactorSet = 1 << 1,
      kAllRequiredFieldsSet = (kPageScaleFactorSet | 0)
    };

    SetPageScaleFactorParamsBuilder<STATE | kPageScaleFactorSet>& SetPageScaleFactor(double value) {
      static_assert(!(STATE & kPageScaleFactorSet), "property pageScaleFactor should not have already been set");
      result_->SetPageScaleFactor(value);
      return CastState<kPageScaleFactorSet>();
    }

    std::unique_ptr<SetPageScaleFactorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPageScaleFactorParams;
    SetPageScaleFactorParamsBuilder() : result_(new SetPageScaleFactorParams()) { }

    template<int STEP> SetPageScaleFactorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPageScaleFactorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPageScaleFactorParams> result_;
  };

  static SetPageScaleFactorParamsBuilder<0> Builder() {
    return SetPageScaleFactorParamsBuilder<0>();
  }

 private:
  SetPageScaleFactorParams() { }

  double page_scale_factor_;

  DISALLOW_COPY_AND_ASSIGN(SetPageScaleFactorParams);
};


// Result for the SetPageScaleFactor command.
class HEADLESS_EXPORT SetPageScaleFactorResult {
 public:
  static std::unique_ptr<SetPageScaleFactorResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPageScaleFactorResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPageScaleFactorResult> Clone() const;

  template<int STATE>
  class SetPageScaleFactorResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetPageScaleFactorResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPageScaleFactorResult;
    SetPageScaleFactorResultBuilder() : result_(new SetPageScaleFactorResult()) { }

    template<int STEP> SetPageScaleFactorResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPageScaleFactorResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPageScaleFactorResult> result_;
  };

  static SetPageScaleFactorResultBuilder<0> Builder() {
    return SetPageScaleFactorResultBuilder<0>();
  }

 private:
  SetPageScaleFactorResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetPageScaleFactorResult);
};


// Parameters for the SetScriptExecutionDisabled command.
class HEADLESS_EXPORT SetScriptExecutionDisabledParams {
 public:
  static std::unique_ptr<SetScriptExecutionDisabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetScriptExecutionDisabledParams() { }

  // Whether script execution should be disabled in the page.
  bool GetValue() const { return value_; }
  void SetValue(bool value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetScriptExecutionDisabledParams> Clone() const;

  template<int STATE>
  class SetScriptExecutionDisabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kValueSet = 1 << 1,
      kAllRequiredFieldsSet = (kValueSet | 0)
    };

    SetScriptExecutionDisabledParamsBuilder<STATE | kValueSet>& SetValue(bool value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<SetScriptExecutionDisabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetScriptExecutionDisabledParams;
    SetScriptExecutionDisabledParamsBuilder() : result_(new SetScriptExecutionDisabledParams()) { }

    template<int STEP> SetScriptExecutionDisabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetScriptExecutionDisabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetScriptExecutionDisabledParams> result_;
  };

  static SetScriptExecutionDisabledParamsBuilder<0> Builder() {
    return SetScriptExecutionDisabledParamsBuilder<0>();
  }

 private:
  SetScriptExecutionDisabledParams() { }

  bool value_;

  DISALLOW_COPY_AND_ASSIGN(SetScriptExecutionDisabledParams);
};


// Result for the SetScriptExecutionDisabled command.
class HEADLESS_EXPORT SetScriptExecutionDisabledResult {
 public:
  static std::unique_ptr<SetScriptExecutionDisabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetScriptExecutionDisabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetScriptExecutionDisabledResult> Clone() const;

  template<int STATE>
  class SetScriptExecutionDisabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetScriptExecutionDisabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetScriptExecutionDisabledResult;
    SetScriptExecutionDisabledResultBuilder() : result_(new SetScriptExecutionDisabledResult()) { }

    template<int STEP> SetScriptExecutionDisabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetScriptExecutionDisabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetScriptExecutionDisabledResult> result_;
  };

  static SetScriptExecutionDisabledResultBuilder<0> Builder() {
    return SetScriptExecutionDisabledResultBuilder<0>();
  }

 private:
  SetScriptExecutionDisabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetScriptExecutionDisabledResult);
};


// Parameters for the SetTouchEmulationEnabled command.
class HEADLESS_EXPORT SetTouchEmulationEnabledParams {
 public:
  static std::unique_ptr<SetTouchEmulationEnabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTouchEmulationEnabledParams() { }

  // Whether the touch event emulation should be enabled.
  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  // Maximum touch points supported. Defaults to one.
  bool HasMaxTouchPoints() const { return !!max_touch_points_; }
  int GetMaxTouchPoints() const { DCHECK(HasMaxTouchPoints()); return max_touch_points_.value(); }
  void SetMaxTouchPoints(int value) { max_touch_points_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTouchEmulationEnabledParams> Clone() const;

  template<int STATE>
  class SetTouchEmulationEnabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetTouchEmulationEnabledParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    SetTouchEmulationEnabledParamsBuilder<STATE>& SetMaxTouchPoints(int value) {
      result_->SetMaxTouchPoints(value);
      return *this;
    }

    std::unique_ptr<SetTouchEmulationEnabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTouchEmulationEnabledParams;
    SetTouchEmulationEnabledParamsBuilder() : result_(new SetTouchEmulationEnabledParams()) { }

    template<int STEP> SetTouchEmulationEnabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTouchEmulationEnabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTouchEmulationEnabledParams> result_;
  };

  static SetTouchEmulationEnabledParamsBuilder<0> Builder() {
    return SetTouchEmulationEnabledParamsBuilder<0>();
  }

 private:
  SetTouchEmulationEnabledParams() { }

  bool enabled_;
  base::Optional<int> max_touch_points_;

  DISALLOW_COPY_AND_ASSIGN(SetTouchEmulationEnabledParams);
};


// Result for the SetTouchEmulationEnabled command.
class HEADLESS_EXPORT SetTouchEmulationEnabledResult {
 public:
  static std::unique_ptr<SetTouchEmulationEnabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTouchEmulationEnabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTouchEmulationEnabledResult> Clone() const;

  template<int STATE>
  class SetTouchEmulationEnabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetTouchEmulationEnabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTouchEmulationEnabledResult;
    SetTouchEmulationEnabledResultBuilder() : result_(new SetTouchEmulationEnabledResult()) { }

    template<int STEP> SetTouchEmulationEnabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTouchEmulationEnabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTouchEmulationEnabledResult> result_;
  };

  static SetTouchEmulationEnabledResultBuilder<0> Builder() {
    return SetTouchEmulationEnabledResultBuilder<0>();
  }

 private:
  SetTouchEmulationEnabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetTouchEmulationEnabledResult);
};


// Parameters for the SetVirtualTimePolicy command.
class HEADLESS_EXPORT SetVirtualTimePolicyParams {
 public:
  static std::unique_ptr<SetVirtualTimePolicyParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetVirtualTimePolicyParams() { }

  ::headless::emulation::VirtualTimePolicy GetPolicy() const { return policy_; }
  void SetPolicy(::headless::emulation::VirtualTimePolicy value) { policy_ = value; }

  // If set, after this many virtual milliseconds have elapsed virtual time will be paused and a
  // virtualTimeBudgetExpired event is sent.
  bool HasBudget() const { return !!budget_; }
  double GetBudget() const { DCHECK(HasBudget()); return budget_.value(); }
  void SetBudget(double value) { budget_ = value; }

  // If set this specifies the maximum number of tasks that can be run before virtual is forced
  // forwards to prevent deadlock.
  bool HasMaxVirtualTimeTaskStarvationCount() const { return !!max_virtual_time_task_starvation_count_; }
  int GetMaxVirtualTimeTaskStarvationCount() const { DCHECK(HasMaxVirtualTimeTaskStarvationCount()); return max_virtual_time_task_starvation_count_.value(); }
  void SetMaxVirtualTimeTaskStarvationCount(int value) { max_virtual_time_task_starvation_count_ = value; }

  // If set the virtual time policy change should be deferred until any frame starts navigating.
  // Note any previous deferred policy change is superseded.
  bool HasWaitForNavigation() const { return !!wait_for_navigation_; }
  bool GetWaitForNavigation() const { DCHECK(HasWaitForNavigation()); return wait_for_navigation_.value(); }
  void SetWaitForNavigation(bool value) { wait_for_navigation_ = value; }

  // If set, base::Time::Now will be overriden to initially return this value.
  bool HasInitialVirtualTime() const { return !!initial_virtual_time_; }
  double GetInitialVirtualTime() const { DCHECK(HasInitialVirtualTime()); return initial_virtual_time_.value(); }
  void SetInitialVirtualTime(double value) { initial_virtual_time_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetVirtualTimePolicyParams> Clone() const;

  template<int STATE>
  class SetVirtualTimePolicyParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPolicySet = 1 << 1,
      kAllRequiredFieldsSet = (kPolicySet | 0)
    };

    SetVirtualTimePolicyParamsBuilder<STATE | kPolicySet>& SetPolicy(::headless::emulation::VirtualTimePolicy value) {
      static_assert(!(STATE & kPolicySet), "property policy should not have already been set");
      result_->SetPolicy(value);
      return CastState<kPolicySet>();
    }

    SetVirtualTimePolicyParamsBuilder<STATE>& SetBudget(double value) {
      result_->SetBudget(value);
      return *this;
    }

    SetVirtualTimePolicyParamsBuilder<STATE>& SetMaxVirtualTimeTaskStarvationCount(int value) {
      result_->SetMaxVirtualTimeTaskStarvationCount(value);
      return *this;
    }

    SetVirtualTimePolicyParamsBuilder<STATE>& SetWaitForNavigation(bool value) {
      result_->SetWaitForNavigation(value);
      return *this;
    }

    SetVirtualTimePolicyParamsBuilder<STATE>& SetInitialVirtualTime(double value) {
      result_->SetInitialVirtualTime(value);
      return *this;
    }

    std::unique_ptr<SetVirtualTimePolicyParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetVirtualTimePolicyParams;
    SetVirtualTimePolicyParamsBuilder() : result_(new SetVirtualTimePolicyParams()) { }

    template<int STEP> SetVirtualTimePolicyParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetVirtualTimePolicyParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetVirtualTimePolicyParams> result_;
  };

  static SetVirtualTimePolicyParamsBuilder<0> Builder() {
    return SetVirtualTimePolicyParamsBuilder<0>();
  }

 private:
  SetVirtualTimePolicyParams() { }

  ::headless::emulation::VirtualTimePolicy policy_;
  base::Optional<double> budget_;
  base::Optional<int> max_virtual_time_task_starvation_count_;
  base::Optional<bool> wait_for_navigation_;
  base::Optional<double> initial_virtual_time_;

  DISALLOW_COPY_AND_ASSIGN(SetVirtualTimePolicyParams);
};


// Result for the SetVirtualTimePolicy command.
class HEADLESS_EXPORT SetVirtualTimePolicyResult {
 public:
  static std::unique_ptr<SetVirtualTimePolicyResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetVirtualTimePolicyResult() { }

  // Absolute timestamp at which virtual time was first enabled (up time in milliseconds).
  double GetVirtualTimeTicksBase() const { return virtual_time_ticks_base_; }
  void SetVirtualTimeTicksBase(double value) { virtual_time_ticks_base_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetVirtualTimePolicyResult> Clone() const;

  template<int STATE>
  class SetVirtualTimePolicyResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kVirtualTimeTicksBaseSet = 1 << 1,
      kAllRequiredFieldsSet = (kVirtualTimeTicksBaseSet | 0)
    };

    SetVirtualTimePolicyResultBuilder<STATE | kVirtualTimeTicksBaseSet>& SetVirtualTimeTicksBase(double value) {
      static_assert(!(STATE & kVirtualTimeTicksBaseSet), "property virtualTimeTicksBase should not have already been set");
      result_->SetVirtualTimeTicksBase(value);
      return CastState<kVirtualTimeTicksBaseSet>();
    }

    std::unique_ptr<SetVirtualTimePolicyResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetVirtualTimePolicyResult;
    SetVirtualTimePolicyResultBuilder() : result_(new SetVirtualTimePolicyResult()) { }

    template<int STEP> SetVirtualTimePolicyResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetVirtualTimePolicyResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetVirtualTimePolicyResult> result_;
  };

  static SetVirtualTimePolicyResultBuilder<0> Builder() {
    return SetVirtualTimePolicyResultBuilder<0>();
  }

 private:
  SetVirtualTimePolicyResult() { }

  double virtual_time_ticks_base_;

  DISALLOW_COPY_AND_ASSIGN(SetVirtualTimePolicyResult);
};


// Parameters for the SetLocaleOverride command.
class HEADLESS_EXPORT SetLocaleOverrideParams {
 public:
  static std::unique_ptr<SetLocaleOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetLocaleOverrideParams() { }

  // ICU style C locale (e.g. "en_US"). If not specified or empty, disables the override and
  // restores default host system locale.
  bool HasLocale() const { return !!locale_; }
  std::string GetLocale() const { DCHECK(HasLocale()); return locale_.value(); }
  void SetLocale(const std::string& value) { locale_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetLocaleOverrideParams> Clone() const;

  template<int STATE>
  class SetLocaleOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    SetLocaleOverrideParamsBuilder<STATE>& SetLocale(const std::string& value) {
      result_->SetLocale(value);
      return *this;
    }

    std::unique_ptr<SetLocaleOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetLocaleOverrideParams;
    SetLocaleOverrideParamsBuilder() : result_(new SetLocaleOverrideParams()) { }

    template<int STEP> SetLocaleOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetLocaleOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetLocaleOverrideParams> result_;
  };

  static SetLocaleOverrideParamsBuilder<0> Builder() {
    return SetLocaleOverrideParamsBuilder<0>();
  }

 private:
  SetLocaleOverrideParams() { }

  base::Optional<std::string> locale_;

  DISALLOW_COPY_AND_ASSIGN(SetLocaleOverrideParams);
};


// Result for the SetLocaleOverride command.
class HEADLESS_EXPORT SetLocaleOverrideResult {
 public:
  static std::unique_ptr<SetLocaleOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetLocaleOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetLocaleOverrideResult> Clone() const;

  template<int STATE>
  class SetLocaleOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetLocaleOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetLocaleOverrideResult;
    SetLocaleOverrideResultBuilder() : result_(new SetLocaleOverrideResult()) { }

    template<int STEP> SetLocaleOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetLocaleOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetLocaleOverrideResult> result_;
  };

  static SetLocaleOverrideResultBuilder<0> Builder() {
    return SetLocaleOverrideResultBuilder<0>();
  }

 private:
  SetLocaleOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetLocaleOverrideResult);
};


// Parameters for the SetTimezoneOverride command.
class HEADLESS_EXPORT SetTimezoneOverrideParams {
 public:
  static std::unique_ptr<SetTimezoneOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTimezoneOverrideParams() { }

  // The timezone identifier. If empty, disables the override and
  // restores default host system timezone.
  std::string GetTimezoneId() const { return timezone_id_; }
  void SetTimezoneId(const std::string& value) { timezone_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTimezoneOverrideParams> Clone() const;

  template<int STATE>
  class SetTimezoneOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimezoneIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kTimezoneIdSet | 0)
    };

    SetTimezoneOverrideParamsBuilder<STATE | kTimezoneIdSet>& SetTimezoneId(const std::string& value) {
      static_assert(!(STATE & kTimezoneIdSet), "property timezoneId should not have already been set");
      result_->SetTimezoneId(value);
      return CastState<kTimezoneIdSet>();
    }

    std::unique_ptr<SetTimezoneOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTimezoneOverrideParams;
    SetTimezoneOverrideParamsBuilder() : result_(new SetTimezoneOverrideParams()) { }

    template<int STEP> SetTimezoneOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTimezoneOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTimezoneOverrideParams> result_;
  };

  static SetTimezoneOverrideParamsBuilder<0> Builder() {
    return SetTimezoneOverrideParamsBuilder<0>();
  }

 private:
  SetTimezoneOverrideParams() { }

  std::string timezone_id_;

  DISALLOW_COPY_AND_ASSIGN(SetTimezoneOverrideParams);
};


// Result for the SetTimezoneOverride command.
class HEADLESS_EXPORT SetTimezoneOverrideResult {
 public:
  static std::unique_ptr<SetTimezoneOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTimezoneOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTimezoneOverrideResult> Clone() const;

  template<int STATE>
  class SetTimezoneOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetTimezoneOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTimezoneOverrideResult;
    SetTimezoneOverrideResultBuilder() : result_(new SetTimezoneOverrideResult()) { }

    template<int STEP> SetTimezoneOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTimezoneOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTimezoneOverrideResult> result_;
  };

  static SetTimezoneOverrideResultBuilder<0> Builder() {
    return SetTimezoneOverrideResultBuilder<0>();
  }

 private:
  SetTimezoneOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetTimezoneOverrideResult);
};


// Parameters for the SetVisibleSize command.
class HEADLESS_EXPORT SetVisibleSizeParams {
 public:
  static std::unique_ptr<SetVisibleSizeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetVisibleSizeParams() { }

  // Frame width (DIP).
  int GetWidth() const { return width_; }
  void SetWidth(int value) { width_ = value; }

  // Frame height (DIP).
  int GetHeight() const { return height_; }
  void SetHeight(int value) { height_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetVisibleSizeParams> Clone() const;

  template<int STATE>
  class SetVisibleSizeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kWidthSet = 1 << 1,
    kHeightSet = 1 << 2,
      kAllRequiredFieldsSet = (kWidthSet | kHeightSet | 0)
    };

    SetVisibleSizeParamsBuilder<STATE | kWidthSet>& SetWidth(int value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    SetVisibleSizeParamsBuilder<STATE | kHeightSet>& SetHeight(int value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    std::unique_ptr<SetVisibleSizeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetVisibleSizeParams;
    SetVisibleSizeParamsBuilder() : result_(new SetVisibleSizeParams()) { }

    template<int STEP> SetVisibleSizeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetVisibleSizeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetVisibleSizeParams> result_;
  };

  static SetVisibleSizeParamsBuilder<0> Builder() {
    return SetVisibleSizeParamsBuilder<0>();
  }

 private:
  SetVisibleSizeParams() { }

  int width_;
  int height_;

  DISALLOW_COPY_AND_ASSIGN(SetVisibleSizeParams);
};


// Result for the SetVisibleSize command.
class HEADLESS_EXPORT SetVisibleSizeResult {
 public:
  static std::unique_ptr<SetVisibleSizeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetVisibleSizeResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetVisibleSizeResult> Clone() const;

  template<int STATE>
  class SetVisibleSizeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetVisibleSizeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetVisibleSizeResult;
    SetVisibleSizeResultBuilder() : result_(new SetVisibleSizeResult()) { }

    template<int STEP> SetVisibleSizeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetVisibleSizeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetVisibleSizeResult> result_;
  };

  static SetVisibleSizeResultBuilder<0> Builder() {
    return SetVisibleSizeResultBuilder<0>();
  }

 private:
  SetVisibleSizeResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetVisibleSizeResult);
};


// Parameters for the SetUserAgentOverride command.
class HEADLESS_EXPORT SetUserAgentOverrideParams {
 public:
  static std::unique_ptr<SetUserAgentOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetUserAgentOverrideParams() { }

  // User agent to use.
  std::string GetUserAgent() const { return user_agent_; }
  void SetUserAgent(const std::string& value) { user_agent_ = value; }

  // Browser langugage to emulate.
  bool HasAcceptLanguage() const { return !!accept_language_; }
  std::string GetAcceptLanguage() const { DCHECK(HasAcceptLanguage()); return accept_language_.value(); }
  void SetAcceptLanguage(const std::string& value) { accept_language_ = value; }

  // The platform navigator.platform should return.
  bool HasPlatform() const { return !!platform_; }
  std::string GetPlatform() const { DCHECK(HasPlatform()); return platform_.value(); }
  void SetPlatform(const std::string& value) { platform_ = value; }

  // To be sent in Sec-CH-UA-* headers and returned in navigator.userAgentData
  bool HasUserAgentMetadata() const { return !!user_agent_metadata_; }
  const ::headless::emulation::UserAgentMetadata* GetUserAgentMetadata() const { DCHECK(HasUserAgentMetadata()); return user_agent_metadata_.value().get(); }
  void SetUserAgentMetadata(std::unique_ptr<::headless::emulation::UserAgentMetadata> value) { user_agent_metadata_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetUserAgentOverrideParams> Clone() const;

  template<int STATE>
  class SetUserAgentOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUserAgentSet = 1 << 1,
      kAllRequiredFieldsSet = (kUserAgentSet | 0)
    };

    SetUserAgentOverrideParamsBuilder<STATE | kUserAgentSet>& SetUserAgent(const std::string& value) {
      static_assert(!(STATE & kUserAgentSet), "property userAgent should not have already been set");
      result_->SetUserAgent(value);
      return CastState<kUserAgentSet>();
    }

    SetUserAgentOverrideParamsBuilder<STATE>& SetAcceptLanguage(const std::string& value) {
      result_->SetAcceptLanguage(value);
      return *this;
    }

    SetUserAgentOverrideParamsBuilder<STATE>& SetPlatform(const std::string& value) {
      result_->SetPlatform(value);
      return *this;
    }

    SetUserAgentOverrideParamsBuilder<STATE>& SetUserAgentMetadata(std::unique_ptr<::headless::emulation::UserAgentMetadata> value) {
      result_->SetUserAgentMetadata(std::move(value));
      return *this;
    }

    std::unique_ptr<SetUserAgentOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetUserAgentOverrideParams;
    SetUserAgentOverrideParamsBuilder() : result_(new SetUserAgentOverrideParams()) { }

    template<int STEP> SetUserAgentOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetUserAgentOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetUserAgentOverrideParams> result_;
  };

  static SetUserAgentOverrideParamsBuilder<0> Builder() {
    return SetUserAgentOverrideParamsBuilder<0>();
  }

 private:
  SetUserAgentOverrideParams() { }

  std::string user_agent_;
  base::Optional<std::string> accept_language_;
  base::Optional<std::string> platform_;
  base::Optional<std::unique_ptr<::headless::emulation::UserAgentMetadata>> user_agent_metadata_;

  DISALLOW_COPY_AND_ASSIGN(SetUserAgentOverrideParams);
};


// Result for the SetUserAgentOverride command.
class HEADLESS_EXPORT SetUserAgentOverrideResult {
 public:
  static std::unique_ptr<SetUserAgentOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetUserAgentOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetUserAgentOverrideResult> Clone() const;

  template<int STATE>
  class SetUserAgentOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetUserAgentOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetUserAgentOverrideResult;
    SetUserAgentOverrideResultBuilder() : result_(new SetUserAgentOverrideResult()) { }

    template<int STEP> SetUserAgentOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetUserAgentOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetUserAgentOverrideResult> result_;
  };

  static SetUserAgentOverrideResultBuilder<0> Builder() {
    return SetUserAgentOverrideResultBuilder<0>();
  }

 private:
  SetUserAgentOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetUserAgentOverrideResult);
};


// Parameters for the VirtualTimeBudgetExpired event.
class HEADLESS_EXPORT VirtualTimeBudgetExpiredParams {
 public:
  static std::unique_ptr<VirtualTimeBudgetExpiredParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~VirtualTimeBudgetExpiredParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<VirtualTimeBudgetExpiredParams> Clone() const;

  template<int STATE>
  class VirtualTimeBudgetExpiredParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<VirtualTimeBudgetExpiredParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class VirtualTimeBudgetExpiredParams;
    VirtualTimeBudgetExpiredParamsBuilder() : result_(new VirtualTimeBudgetExpiredParams()) { }

    template<int STEP> VirtualTimeBudgetExpiredParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<VirtualTimeBudgetExpiredParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<VirtualTimeBudgetExpiredParams> result_;
  };

  static VirtualTimeBudgetExpiredParamsBuilder<0> Builder() {
    return VirtualTimeBudgetExpiredParamsBuilder<0>();
  }

 private:
  VirtualTimeBudgetExpiredParams() { }


  DISALLOW_COPY_AND_ASSIGN(VirtualTimeBudgetExpiredParams);
};


}  // namespace emulation

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_EMULATION_H_
