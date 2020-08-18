// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PERFORMANCE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PERFORMANCE_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_performance.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace performance {

// Run-time execution metric.
class HEADLESS_EXPORT Metric {
 public:
  static std::unique_ptr<Metric> Parse(const base::Value& value, ErrorReporter* errors);
  ~Metric() { }

  // Metric name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Metric value.
  double GetValue() const { return value_; }
  void SetValue(double value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Metric> Clone() const;

  template<int STATE>
  class MetricBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    MetricBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    MetricBuilder<STATE | kValueSet>& SetValue(double value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<Metric> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Metric;
    MetricBuilder() : result_(new Metric()) { }

    template<int STEP> MetricBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MetricBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Metric> result_;
  };

  static MetricBuilder<0> Builder() {
    return MetricBuilder<0>();
  }

 private:
  Metric() { }

  std::string name_;
  double value_;

  DISALLOW_COPY_AND_ASSIGN(Metric);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  // Time domain to use for collecting and reporting duration metrics.
  bool HasTimeDomain() const { return !!time_domain_; }
  ::headless::performance::EnableTimeDomain GetTimeDomain() const { DCHECK(HasTimeDomain()); return time_domain_.value(); }
  void SetTimeDomain(::headless::performance::EnableTimeDomain value) { time_domain_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    EnableParamsBuilder<STATE>& SetTimeDomain(::headless::performance::EnableTimeDomain value) {
      result_->SetTimeDomain(value);
      return *this;
    }

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }

  base::Optional<::headless::performance::EnableTimeDomain> time_domain_;

  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the SetTimeDomain command.
class HEADLESS_EXPORT SetTimeDomainParams {
 public:
  static std::unique_ptr<SetTimeDomainParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTimeDomainParams() { }

  // Time domain
  ::headless::performance::SetTimeDomainTimeDomain GetTimeDomain() const { return time_domain_; }
  void SetTimeDomain(::headless::performance::SetTimeDomainTimeDomain value) { time_domain_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTimeDomainParams> Clone() const;

  template<int STATE>
  class SetTimeDomainParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimeDomainSet = 1 << 1,
      kAllRequiredFieldsSet = (kTimeDomainSet | 0)
    };

    SetTimeDomainParamsBuilder<STATE | kTimeDomainSet>& SetTimeDomain(::headless::performance::SetTimeDomainTimeDomain value) {
      static_assert(!(STATE & kTimeDomainSet), "property timeDomain should not have already been set");
      result_->SetTimeDomain(value);
      return CastState<kTimeDomainSet>();
    }

    std::unique_ptr<SetTimeDomainParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTimeDomainParams;
    SetTimeDomainParamsBuilder() : result_(new SetTimeDomainParams()) { }

    template<int STEP> SetTimeDomainParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTimeDomainParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTimeDomainParams> result_;
  };

  static SetTimeDomainParamsBuilder<0> Builder() {
    return SetTimeDomainParamsBuilder<0>();
  }

 private:
  SetTimeDomainParams() { }

  ::headless::performance::SetTimeDomainTimeDomain time_domain_;

  DISALLOW_COPY_AND_ASSIGN(SetTimeDomainParams);
};


// Result for the SetTimeDomain command.
class HEADLESS_EXPORT SetTimeDomainResult {
 public:
  static std::unique_ptr<SetTimeDomainResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTimeDomainResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTimeDomainResult> Clone() const;

  template<int STATE>
  class SetTimeDomainResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetTimeDomainResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTimeDomainResult;
    SetTimeDomainResultBuilder() : result_(new SetTimeDomainResult()) { }

    template<int STEP> SetTimeDomainResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTimeDomainResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTimeDomainResult> result_;
  };

  static SetTimeDomainResultBuilder<0> Builder() {
    return SetTimeDomainResultBuilder<0>();
  }

 private:
  SetTimeDomainResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetTimeDomainResult);
};


// Parameters for the GetMetrics command.
class HEADLESS_EXPORT GetMetricsParams {
 public:
  static std::unique_ptr<GetMetricsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetMetricsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetMetricsParams> Clone() const;

  template<int STATE>
  class GetMetricsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetMetricsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetMetricsParams;
    GetMetricsParamsBuilder() : result_(new GetMetricsParams()) { }

    template<int STEP> GetMetricsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetMetricsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetMetricsParams> result_;
  };

  static GetMetricsParamsBuilder<0> Builder() {
    return GetMetricsParamsBuilder<0>();
  }

 private:
  GetMetricsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetMetricsParams);
};


// Result for the GetMetrics command.
class HEADLESS_EXPORT GetMetricsResult {
 public:
  static std::unique_ptr<GetMetricsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetMetricsResult() { }

  // Current values for run-time metrics.
  const std::vector<std::unique_ptr<::headless::performance::Metric>>* GetMetrics() const { return &metrics_; }
  void SetMetrics(std::vector<std::unique_ptr<::headless::performance::Metric>> value) { metrics_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetMetricsResult> Clone() const;

  template<int STATE>
  class GetMetricsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMetricsSet = 1 << 1,
      kAllRequiredFieldsSet = (kMetricsSet | 0)
    };

    GetMetricsResultBuilder<STATE | kMetricsSet>& SetMetrics(std::vector<std::unique_ptr<::headless::performance::Metric>> value) {
      static_assert(!(STATE & kMetricsSet), "property metrics should not have already been set");
      result_->SetMetrics(std::move(value));
      return CastState<kMetricsSet>();
    }

    std::unique_ptr<GetMetricsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetMetricsResult;
    GetMetricsResultBuilder() : result_(new GetMetricsResult()) { }

    template<int STEP> GetMetricsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetMetricsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetMetricsResult> result_;
  };

  static GetMetricsResultBuilder<0> Builder() {
    return GetMetricsResultBuilder<0>();
  }

 private:
  GetMetricsResult() { }

  std::vector<std::unique_ptr<::headless::performance::Metric>> metrics_;

  DISALLOW_COPY_AND_ASSIGN(GetMetricsResult);
};


// Parameters for the Metrics event.
class HEADLESS_EXPORT MetricsParams {
 public:
  static std::unique_ptr<MetricsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~MetricsParams() { }

  // Current values of the metrics.
  const std::vector<std::unique_ptr<::headless::performance::Metric>>* GetMetrics() const { return &metrics_; }
  void SetMetrics(std::vector<std::unique_ptr<::headless::performance::Metric>> value) { metrics_ = std::move(value); }

  // Timestamp title.
  std::string GetTitle() const { return title_; }
  void SetTitle(const std::string& value) { title_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MetricsParams> Clone() const;

  template<int STATE>
  class MetricsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMetricsSet = 1 << 1,
    kTitleSet = 1 << 2,
      kAllRequiredFieldsSet = (kMetricsSet | kTitleSet | 0)
    };

    MetricsParamsBuilder<STATE | kMetricsSet>& SetMetrics(std::vector<std::unique_ptr<::headless::performance::Metric>> value) {
      static_assert(!(STATE & kMetricsSet), "property metrics should not have already been set");
      result_->SetMetrics(std::move(value));
      return CastState<kMetricsSet>();
    }

    MetricsParamsBuilder<STATE | kTitleSet>& SetTitle(const std::string& value) {
      static_assert(!(STATE & kTitleSet), "property title should not have already been set");
      result_->SetTitle(value);
      return CastState<kTitleSet>();
    }

    std::unique_ptr<MetricsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MetricsParams;
    MetricsParamsBuilder() : result_(new MetricsParams()) { }

    template<int STEP> MetricsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MetricsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MetricsParams> result_;
  };

  static MetricsParamsBuilder<0> Builder() {
    return MetricsParamsBuilder<0>();
  }

 private:
  MetricsParams() { }

  std::vector<std::unique_ptr<::headless::performance::Metric>> metrics_;
  std::string title_;

  DISALLOW_COPY_AND_ASSIGN(MetricsParams);
};


}  // namespace performance

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PERFORMANCE_H_
