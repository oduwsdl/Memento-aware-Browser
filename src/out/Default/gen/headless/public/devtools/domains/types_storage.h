// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_STORAGE_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_browser.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/devtools/internal/types_forward_declarations_storage.h"
#include "headless/public/devtools/internal/types_forward_declarations_target.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace storage {

// Usage for a storage type.
class HEADLESS_EXPORT UsageForType {
 public:
  static std::unique_ptr<UsageForType> Parse(const base::Value& value, ErrorReporter* errors);
  ~UsageForType() { }

  // Name of storage type.
  ::headless::storage::StorageType GetStorageType() const { return storage_type_; }
  void SetStorageType(::headless::storage::StorageType value) { storage_type_ = value; }

  // Storage usage (bytes).
  double GetUsage() const { return usage_; }
  void SetUsage(double value) { usage_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UsageForType> Clone() const;

  template<int STATE>
  class UsageForTypeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStorageTypeSet = 1 << 1,
    kUsageSet = 1 << 2,
      kAllRequiredFieldsSet = (kStorageTypeSet | kUsageSet | 0)
    };

    UsageForTypeBuilder<STATE | kStorageTypeSet>& SetStorageType(::headless::storage::StorageType value) {
      static_assert(!(STATE & kStorageTypeSet), "property storageType should not have already been set");
      result_->SetStorageType(value);
      return CastState<kStorageTypeSet>();
    }

    UsageForTypeBuilder<STATE | kUsageSet>& SetUsage(double value) {
      static_assert(!(STATE & kUsageSet), "property usage should not have already been set");
      result_->SetUsage(value);
      return CastState<kUsageSet>();
    }

    std::unique_ptr<UsageForType> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UsageForType;
    UsageForTypeBuilder() : result_(new UsageForType()) { }

    template<int STEP> UsageForTypeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UsageForTypeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UsageForType> result_;
  };

  static UsageForTypeBuilder<0> Builder() {
    return UsageForTypeBuilder<0>();
  }

 private:
  UsageForType() { }

  ::headless::storage::StorageType storage_type_;
  double usage_;

  DISALLOW_COPY_AND_ASSIGN(UsageForType);
};


// Parameters for the ClearDataForOrigin command.
class HEADLESS_EXPORT ClearDataForOriginParams {
 public:
  static std::unique_ptr<ClearDataForOriginParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDataForOriginParams() { }

  // Security origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  // Comma separated list of StorageType to clear.
  std::string GetStorageTypes() const { return storage_types_; }
  void SetStorageTypes(const std::string& value) { storage_types_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDataForOriginParams> Clone() const;

  template<int STATE>
  class ClearDataForOriginParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
    kStorageTypesSet = 1 << 2,
      kAllRequiredFieldsSet = (kOriginSet | kStorageTypesSet | 0)
    };

    ClearDataForOriginParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    ClearDataForOriginParamsBuilder<STATE | kStorageTypesSet>& SetStorageTypes(const std::string& value) {
      static_assert(!(STATE & kStorageTypesSet), "property storageTypes should not have already been set");
      result_->SetStorageTypes(value);
      return CastState<kStorageTypesSet>();
    }

    std::unique_ptr<ClearDataForOriginParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDataForOriginParams;
    ClearDataForOriginParamsBuilder() : result_(new ClearDataForOriginParams()) { }

    template<int STEP> ClearDataForOriginParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDataForOriginParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDataForOriginParams> result_;
  };

  static ClearDataForOriginParamsBuilder<0> Builder() {
    return ClearDataForOriginParamsBuilder<0>();
  }

 private:
  ClearDataForOriginParams() { }

  std::string origin_;
  std::string storage_types_;

  DISALLOW_COPY_AND_ASSIGN(ClearDataForOriginParams);
};


// Result for the ClearDataForOrigin command.
class HEADLESS_EXPORT ClearDataForOriginResult {
 public:
  static std::unique_ptr<ClearDataForOriginResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDataForOriginResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDataForOriginResult> Clone() const;

  template<int STATE>
  class ClearDataForOriginResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDataForOriginResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDataForOriginResult;
    ClearDataForOriginResultBuilder() : result_(new ClearDataForOriginResult()) { }

    template<int STEP> ClearDataForOriginResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDataForOriginResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDataForOriginResult> result_;
  };

  static ClearDataForOriginResultBuilder<0> Builder() {
    return ClearDataForOriginResultBuilder<0>();
  }

 private:
  ClearDataForOriginResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDataForOriginResult);
};


// Parameters for the GetCookies command.
class HEADLESS_EXPORT GetCookiesParams {
 public:
  static std::unique_ptr<GetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCookiesParams() { }

  // Browser context to use when called on the browser endpoint.
  bool HasBrowserContextId() const { return !!browser_context_id_; }
  std::string GetBrowserContextId() const { DCHECK(HasBrowserContextId()); return browser_context_id_.value(); }
  void SetBrowserContextId(const std::string& value) { browser_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCookiesParams> Clone() const;

  template<int STATE>
  class GetCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetCookiesParamsBuilder<STATE>& SetBrowserContextId(const std::string& value) {
      result_->SetBrowserContextId(value);
      return *this;
    }

    std::unique_ptr<GetCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCookiesParams;
    GetCookiesParamsBuilder() : result_(new GetCookiesParams()) { }

    template<int STEP> GetCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCookiesParams> result_;
  };

  static GetCookiesParamsBuilder<0> Builder() {
    return GetCookiesParamsBuilder<0>();
  }

 private:
  GetCookiesParams() { }

  base::Optional<std::string> browser_context_id_;

  DISALLOW_COPY_AND_ASSIGN(GetCookiesParams);
};


// Result for the GetCookies command.
class HEADLESS_EXPORT GetCookiesResult {
 public:
  static std::unique_ptr<GetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCookiesResult() { }

  // Array of cookie objects.
  const std::vector<std::unique_ptr<::headless::network::Cookie>>* GetCookies() const { return &cookies_; }
  void SetCookies(std::vector<std::unique_ptr<::headless::network::Cookie>> value) { cookies_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCookiesResult> Clone() const;

  template<int STATE>
  class GetCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCookiesSet = 1 << 1,
      kAllRequiredFieldsSet = (kCookiesSet | 0)
    };

    GetCookiesResultBuilder<STATE | kCookiesSet>& SetCookies(std::vector<std::unique_ptr<::headless::network::Cookie>> value) {
      static_assert(!(STATE & kCookiesSet), "property cookies should not have already been set");
      result_->SetCookies(std::move(value));
      return CastState<kCookiesSet>();
    }

    std::unique_ptr<GetCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCookiesResult;
    GetCookiesResultBuilder() : result_(new GetCookiesResult()) { }

    template<int STEP> GetCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCookiesResult> result_;
  };

  static GetCookiesResultBuilder<0> Builder() {
    return GetCookiesResultBuilder<0>();
  }

 private:
  GetCookiesResult() { }

  std::vector<std::unique_ptr<::headless::network::Cookie>> cookies_;

  DISALLOW_COPY_AND_ASSIGN(GetCookiesResult);
};


// Parameters for the SetCookies command.
class HEADLESS_EXPORT SetCookiesParams {
 public:
  static std::unique_ptr<SetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCookiesParams() { }

  // Cookies to be set.
  const std::vector<std::unique_ptr<::headless::network::CookieParam>>* GetCookies() const { return &cookies_; }
  void SetCookies(std::vector<std::unique_ptr<::headless::network::CookieParam>> value) { cookies_ = std::move(value); }

  // Browser context to use when called on the browser endpoint.
  bool HasBrowserContextId() const { return !!browser_context_id_; }
  std::string GetBrowserContextId() const { DCHECK(HasBrowserContextId()); return browser_context_id_.value(); }
  void SetBrowserContextId(const std::string& value) { browser_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCookiesParams> Clone() const;

  template<int STATE>
  class SetCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCookiesSet = 1 << 1,
      kAllRequiredFieldsSet = (kCookiesSet | 0)
    };

    SetCookiesParamsBuilder<STATE | kCookiesSet>& SetCookies(std::vector<std::unique_ptr<::headless::network::CookieParam>> value) {
      static_assert(!(STATE & kCookiesSet), "property cookies should not have already been set");
      result_->SetCookies(std::move(value));
      return CastState<kCookiesSet>();
    }

    SetCookiesParamsBuilder<STATE>& SetBrowserContextId(const std::string& value) {
      result_->SetBrowserContextId(value);
      return *this;
    }

    std::unique_ptr<SetCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCookiesParams;
    SetCookiesParamsBuilder() : result_(new SetCookiesParams()) { }

    template<int STEP> SetCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCookiesParams> result_;
  };

  static SetCookiesParamsBuilder<0> Builder() {
    return SetCookiesParamsBuilder<0>();
  }

 private:
  SetCookiesParams() { }

  std::vector<std::unique_ptr<::headless::network::CookieParam>> cookies_;
  base::Optional<std::string> browser_context_id_;

  DISALLOW_COPY_AND_ASSIGN(SetCookiesParams);
};


// Result for the SetCookies command.
class HEADLESS_EXPORT SetCookiesResult {
 public:
  static std::unique_ptr<SetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCookiesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCookiesResult> Clone() const;

  template<int STATE>
  class SetCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCookiesResult;
    SetCookiesResultBuilder() : result_(new SetCookiesResult()) { }

    template<int STEP> SetCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCookiesResult> result_;
  };

  static SetCookiesResultBuilder<0> Builder() {
    return SetCookiesResultBuilder<0>();
  }

 private:
  SetCookiesResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetCookiesResult);
};


// Parameters for the ClearCookies command.
class HEADLESS_EXPORT ClearCookiesParams {
 public:
  static std::unique_ptr<ClearCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearCookiesParams() { }

  // Browser context to use when called on the browser endpoint.
  bool HasBrowserContextId() const { return !!browser_context_id_; }
  std::string GetBrowserContextId() const { DCHECK(HasBrowserContextId()); return browser_context_id_.value(); }
  void SetBrowserContextId(const std::string& value) { browser_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearCookiesParams> Clone() const;

  template<int STATE>
  class ClearCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    ClearCookiesParamsBuilder<STATE>& SetBrowserContextId(const std::string& value) {
      result_->SetBrowserContextId(value);
      return *this;
    }

    std::unique_ptr<ClearCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearCookiesParams;
    ClearCookiesParamsBuilder() : result_(new ClearCookiesParams()) { }

    template<int STEP> ClearCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearCookiesParams> result_;
  };

  static ClearCookiesParamsBuilder<0> Builder() {
    return ClearCookiesParamsBuilder<0>();
  }

 private:
  ClearCookiesParams() { }

  base::Optional<std::string> browser_context_id_;

  DISALLOW_COPY_AND_ASSIGN(ClearCookiesParams);
};


// Result for the ClearCookies command.
class HEADLESS_EXPORT ClearCookiesResult {
 public:
  static std::unique_ptr<ClearCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearCookiesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearCookiesResult> Clone() const;

  template<int STATE>
  class ClearCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearCookiesResult;
    ClearCookiesResultBuilder() : result_(new ClearCookiesResult()) { }

    template<int STEP> ClearCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearCookiesResult> result_;
  };

  static ClearCookiesResultBuilder<0> Builder() {
    return ClearCookiesResultBuilder<0>();
  }

 private:
  ClearCookiesResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearCookiesResult);
};


// Parameters for the GetUsageAndQuota command.
class HEADLESS_EXPORT GetUsageAndQuotaParams {
 public:
  static std::unique_ptr<GetUsageAndQuotaParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetUsageAndQuotaParams() { }

  // Security origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetUsageAndQuotaParams> Clone() const;

  template<int STATE>
  class GetUsageAndQuotaParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    GetUsageAndQuotaParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<GetUsageAndQuotaParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetUsageAndQuotaParams;
    GetUsageAndQuotaParamsBuilder() : result_(new GetUsageAndQuotaParams()) { }

    template<int STEP> GetUsageAndQuotaParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetUsageAndQuotaParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetUsageAndQuotaParams> result_;
  };

  static GetUsageAndQuotaParamsBuilder<0> Builder() {
    return GetUsageAndQuotaParamsBuilder<0>();
  }

 private:
  GetUsageAndQuotaParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(GetUsageAndQuotaParams);
};


// Result for the GetUsageAndQuota command.
class HEADLESS_EXPORT GetUsageAndQuotaResult {
 public:
  static std::unique_ptr<GetUsageAndQuotaResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetUsageAndQuotaResult() { }

  // Storage usage (bytes).
  double GetUsage() const { return usage_; }
  void SetUsage(double value) { usage_ = value; }

  // Storage quota (bytes).
  double GetQuota() const { return quota_; }
  void SetQuota(double value) { quota_ = value; }

  // Storage usage per type (bytes).
  const std::vector<std::unique_ptr<::headless::storage::UsageForType>>* GetUsageBreakdown() const { return &usage_breakdown_; }
  void SetUsageBreakdown(std::vector<std::unique_ptr<::headless::storage::UsageForType>> value) { usage_breakdown_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetUsageAndQuotaResult> Clone() const;

  template<int STATE>
  class GetUsageAndQuotaResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUsageSet = 1 << 1,
    kQuotaSet = 1 << 2,
    kUsageBreakdownSet = 1 << 3,
      kAllRequiredFieldsSet = (kUsageSet | kQuotaSet | kUsageBreakdownSet | 0)
    };

    GetUsageAndQuotaResultBuilder<STATE | kUsageSet>& SetUsage(double value) {
      static_assert(!(STATE & kUsageSet), "property usage should not have already been set");
      result_->SetUsage(value);
      return CastState<kUsageSet>();
    }

    GetUsageAndQuotaResultBuilder<STATE | kQuotaSet>& SetQuota(double value) {
      static_assert(!(STATE & kQuotaSet), "property quota should not have already been set");
      result_->SetQuota(value);
      return CastState<kQuotaSet>();
    }

    GetUsageAndQuotaResultBuilder<STATE | kUsageBreakdownSet>& SetUsageBreakdown(std::vector<std::unique_ptr<::headless::storage::UsageForType>> value) {
      static_assert(!(STATE & kUsageBreakdownSet), "property usageBreakdown should not have already been set");
      result_->SetUsageBreakdown(std::move(value));
      return CastState<kUsageBreakdownSet>();
    }

    std::unique_ptr<GetUsageAndQuotaResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetUsageAndQuotaResult;
    GetUsageAndQuotaResultBuilder() : result_(new GetUsageAndQuotaResult()) { }

    template<int STEP> GetUsageAndQuotaResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetUsageAndQuotaResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetUsageAndQuotaResult> result_;
  };

  static GetUsageAndQuotaResultBuilder<0> Builder() {
    return GetUsageAndQuotaResultBuilder<0>();
  }

 private:
  GetUsageAndQuotaResult() { }

  double usage_;
  double quota_;
  std::vector<std::unique_ptr<::headless::storage::UsageForType>> usage_breakdown_;

  DISALLOW_COPY_AND_ASSIGN(GetUsageAndQuotaResult);
};


// Parameters for the TrackCacheStorageForOrigin command.
class HEADLESS_EXPORT TrackCacheStorageForOriginParams {
 public:
  static std::unique_ptr<TrackCacheStorageForOriginParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TrackCacheStorageForOriginParams() { }

  // Security origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TrackCacheStorageForOriginParams> Clone() const;

  template<int STATE>
  class TrackCacheStorageForOriginParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    TrackCacheStorageForOriginParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<TrackCacheStorageForOriginParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TrackCacheStorageForOriginParams;
    TrackCacheStorageForOriginParamsBuilder() : result_(new TrackCacheStorageForOriginParams()) { }

    template<int STEP> TrackCacheStorageForOriginParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TrackCacheStorageForOriginParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TrackCacheStorageForOriginParams> result_;
  };

  static TrackCacheStorageForOriginParamsBuilder<0> Builder() {
    return TrackCacheStorageForOriginParamsBuilder<0>();
  }

 private:
  TrackCacheStorageForOriginParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(TrackCacheStorageForOriginParams);
};


// Result for the TrackCacheStorageForOrigin command.
class HEADLESS_EXPORT TrackCacheStorageForOriginResult {
 public:
  static std::unique_ptr<TrackCacheStorageForOriginResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~TrackCacheStorageForOriginResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TrackCacheStorageForOriginResult> Clone() const;

  template<int STATE>
  class TrackCacheStorageForOriginResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<TrackCacheStorageForOriginResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TrackCacheStorageForOriginResult;
    TrackCacheStorageForOriginResultBuilder() : result_(new TrackCacheStorageForOriginResult()) { }

    template<int STEP> TrackCacheStorageForOriginResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TrackCacheStorageForOriginResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TrackCacheStorageForOriginResult> result_;
  };

  static TrackCacheStorageForOriginResultBuilder<0> Builder() {
    return TrackCacheStorageForOriginResultBuilder<0>();
  }

 private:
  TrackCacheStorageForOriginResult() { }


  DISALLOW_COPY_AND_ASSIGN(TrackCacheStorageForOriginResult);
};


// Parameters for the TrackIndexedDBForOrigin command.
class HEADLESS_EXPORT TrackIndexedDBForOriginParams {
 public:
  static std::unique_ptr<TrackIndexedDBForOriginParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TrackIndexedDBForOriginParams() { }

  // Security origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TrackIndexedDBForOriginParams> Clone() const;

  template<int STATE>
  class TrackIndexedDBForOriginParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    TrackIndexedDBForOriginParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<TrackIndexedDBForOriginParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TrackIndexedDBForOriginParams;
    TrackIndexedDBForOriginParamsBuilder() : result_(new TrackIndexedDBForOriginParams()) { }

    template<int STEP> TrackIndexedDBForOriginParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TrackIndexedDBForOriginParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TrackIndexedDBForOriginParams> result_;
  };

  static TrackIndexedDBForOriginParamsBuilder<0> Builder() {
    return TrackIndexedDBForOriginParamsBuilder<0>();
  }

 private:
  TrackIndexedDBForOriginParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(TrackIndexedDBForOriginParams);
};


// Result for the TrackIndexedDBForOrigin command.
class HEADLESS_EXPORT TrackIndexedDBForOriginResult {
 public:
  static std::unique_ptr<TrackIndexedDBForOriginResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~TrackIndexedDBForOriginResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TrackIndexedDBForOriginResult> Clone() const;

  template<int STATE>
  class TrackIndexedDBForOriginResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<TrackIndexedDBForOriginResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TrackIndexedDBForOriginResult;
    TrackIndexedDBForOriginResultBuilder() : result_(new TrackIndexedDBForOriginResult()) { }

    template<int STEP> TrackIndexedDBForOriginResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TrackIndexedDBForOriginResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TrackIndexedDBForOriginResult> result_;
  };

  static TrackIndexedDBForOriginResultBuilder<0> Builder() {
    return TrackIndexedDBForOriginResultBuilder<0>();
  }

 private:
  TrackIndexedDBForOriginResult() { }


  DISALLOW_COPY_AND_ASSIGN(TrackIndexedDBForOriginResult);
};


// Parameters for the UntrackCacheStorageForOrigin command.
class HEADLESS_EXPORT UntrackCacheStorageForOriginParams {
 public:
  static std::unique_ptr<UntrackCacheStorageForOriginParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~UntrackCacheStorageForOriginParams() { }

  // Security origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UntrackCacheStorageForOriginParams> Clone() const;

  template<int STATE>
  class UntrackCacheStorageForOriginParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    UntrackCacheStorageForOriginParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<UntrackCacheStorageForOriginParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UntrackCacheStorageForOriginParams;
    UntrackCacheStorageForOriginParamsBuilder() : result_(new UntrackCacheStorageForOriginParams()) { }

    template<int STEP> UntrackCacheStorageForOriginParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UntrackCacheStorageForOriginParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UntrackCacheStorageForOriginParams> result_;
  };

  static UntrackCacheStorageForOriginParamsBuilder<0> Builder() {
    return UntrackCacheStorageForOriginParamsBuilder<0>();
  }

 private:
  UntrackCacheStorageForOriginParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(UntrackCacheStorageForOriginParams);
};


// Result for the UntrackCacheStorageForOrigin command.
class HEADLESS_EXPORT UntrackCacheStorageForOriginResult {
 public:
  static std::unique_ptr<UntrackCacheStorageForOriginResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~UntrackCacheStorageForOriginResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UntrackCacheStorageForOriginResult> Clone() const;

  template<int STATE>
  class UntrackCacheStorageForOriginResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<UntrackCacheStorageForOriginResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UntrackCacheStorageForOriginResult;
    UntrackCacheStorageForOriginResultBuilder() : result_(new UntrackCacheStorageForOriginResult()) { }

    template<int STEP> UntrackCacheStorageForOriginResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UntrackCacheStorageForOriginResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UntrackCacheStorageForOriginResult> result_;
  };

  static UntrackCacheStorageForOriginResultBuilder<0> Builder() {
    return UntrackCacheStorageForOriginResultBuilder<0>();
  }

 private:
  UntrackCacheStorageForOriginResult() { }


  DISALLOW_COPY_AND_ASSIGN(UntrackCacheStorageForOriginResult);
};


// Parameters for the UntrackIndexedDBForOrigin command.
class HEADLESS_EXPORT UntrackIndexedDBForOriginParams {
 public:
  static std::unique_ptr<UntrackIndexedDBForOriginParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~UntrackIndexedDBForOriginParams() { }

  // Security origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UntrackIndexedDBForOriginParams> Clone() const;

  template<int STATE>
  class UntrackIndexedDBForOriginParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    UntrackIndexedDBForOriginParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<UntrackIndexedDBForOriginParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UntrackIndexedDBForOriginParams;
    UntrackIndexedDBForOriginParamsBuilder() : result_(new UntrackIndexedDBForOriginParams()) { }

    template<int STEP> UntrackIndexedDBForOriginParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UntrackIndexedDBForOriginParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UntrackIndexedDBForOriginParams> result_;
  };

  static UntrackIndexedDBForOriginParamsBuilder<0> Builder() {
    return UntrackIndexedDBForOriginParamsBuilder<0>();
  }

 private:
  UntrackIndexedDBForOriginParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(UntrackIndexedDBForOriginParams);
};


// Result for the UntrackIndexedDBForOrigin command.
class HEADLESS_EXPORT UntrackIndexedDBForOriginResult {
 public:
  static std::unique_ptr<UntrackIndexedDBForOriginResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~UntrackIndexedDBForOriginResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<UntrackIndexedDBForOriginResult> Clone() const;

  template<int STATE>
  class UntrackIndexedDBForOriginResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<UntrackIndexedDBForOriginResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class UntrackIndexedDBForOriginResult;
    UntrackIndexedDBForOriginResultBuilder() : result_(new UntrackIndexedDBForOriginResult()) { }

    template<int STEP> UntrackIndexedDBForOriginResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<UntrackIndexedDBForOriginResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<UntrackIndexedDBForOriginResult> result_;
  };

  static UntrackIndexedDBForOriginResultBuilder<0> Builder() {
    return UntrackIndexedDBForOriginResultBuilder<0>();
  }

 private:
  UntrackIndexedDBForOriginResult() { }


  DISALLOW_COPY_AND_ASSIGN(UntrackIndexedDBForOriginResult);
};


// Parameters for the CacheStorageContentUpdated event.
class HEADLESS_EXPORT CacheStorageContentUpdatedParams {
 public:
  static std::unique_ptr<CacheStorageContentUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CacheStorageContentUpdatedParams() { }

  // Origin to update.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  // Name of cache in origin.
  std::string GetCacheName() const { return cache_name_; }
  void SetCacheName(const std::string& value) { cache_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CacheStorageContentUpdatedParams> Clone() const;

  template<int STATE>
  class CacheStorageContentUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
    kCacheNameSet = 1 << 2,
      kAllRequiredFieldsSet = (kOriginSet | kCacheNameSet | 0)
    };

    CacheStorageContentUpdatedParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    CacheStorageContentUpdatedParamsBuilder<STATE | kCacheNameSet>& SetCacheName(const std::string& value) {
      static_assert(!(STATE & kCacheNameSet), "property cacheName should not have already been set");
      result_->SetCacheName(value);
      return CastState<kCacheNameSet>();
    }

    std::unique_ptr<CacheStorageContentUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CacheStorageContentUpdatedParams;
    CacheStorageContentUpdatedParamsBuilder() : result_(new CacheStorageContentUpdatedParams()) { }

    template<int STEP> CacheStorageContentUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CacheStorageContentUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CacheStorageContentUpdatedParams> result_;
  };

  static CacheStorageContentUpdatedParamsBuilder<0> Builder() {
    return CacheStorageContentUpdatedParamsBuilder<0>();
  }

 private:
  CacheStorageContentUpdatedParams() { }

  std::string origin_;
  std::string cache_name_;

  DISALLOW_COPY_AND_ASSIGN(CacheStorageContentUpdatedParams);
};


// Parameters for the CacheStorageListUpdated event.
class HEADLESS_EXPORT CacheStorageListUpdatedParams {
 public:
  static std::unique_ptr<CacheStorageListUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CacheStorageListUpdatedParams() { }

  // Origin to update.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CacheStorageListUpdatedParams> Clone() const;

  template<int STATE>
  class CacheStorageListUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    CacheStorageListUpdatedParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<CacheStorageListUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CacheStorageListUpdatedParams;
    CacheStorageListUpdatedParamsBuilder() : result_(new CacheStorageListUpdatedParams()) { }

    template<int STEP> CacheStorageListUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CacheStorageListUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CacheStorageListUpdatedParams> result_;
  };

  static CacheStorageListUpdatedParamsBuilder<0> Builder() {
    return CacheStorageListUpdatedParamsBuilder<0>();
  }

 private:
  CacheStorageListUpdatedParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(CacheStorageListUpdatedParams);
};


// Parameters for the IndexedDBContentUpdated event.
class HEADLESS_EXPORT IndexedDBContentUpdatedParams {
 public:
  static std::unique_ptr<IndexedDBContentUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~IndexedDBContentUpdatedParams() { }

  // Origin to update.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  // Database to update.
  std::string GetDatabaseName() const { return database_name_; }
  void SetDatabaseName(const std::string& value) { database_name_ = value; }

  // ObjectStore to update.
  std::string GetObjectStoreName() const { return object_store_name_; }
  void SetObjectStoreName(const std::string& value) { object_store_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<IndexedDBContentUpdatedParams> Clone() const;

  template<int STATE>
  class IndexedDBContentUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
    kDatabaseNameSet = 1 << 2,
    kObjectStoreNameSet = 1 << 3,
      kAllRequiredFieldsSet = (kOriginSet | kDatabaseNameSet | kObjectStoreNameSet | 0)
    };

    IndexedDBContentUpdatedParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    IndexedDBContentUpdatedParamsBuilder<STATE | kDatabaseNameSet>& SetDatabaseName(const std::string& value) {
      static_assert(!(STATE & kDatabaseNameSet), "property databaseName should not have already been set");
      result_->SetDatabaseName(value);
      return CastState<kDatabaseNameSet>();
    }

    IndexedDBContentUpdatedParamsBuilder<STATE | kObjectStoreNameSet>& SetObjectStoreName(const std::string& value) {
      static_assert(!(STATE & kObjectStoreNameSet), "property objectStoreName should not have already been set");
      result_->SetObjectStoreName(value);
      return CastState<kObjectStoreNameSet>();
    }

    std::unique_ptr<IndexedDBContentUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class IndexedDBContentUpdatedParams;
    IndexedDBContentUpdatedParamsBuilder() : result_(new IndexedDBContentUpdatedParams()) { }

    template<int STEP> IndexedDBContentUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<IndexedDBContentUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<IndexedDBContentUpdatedParams> result_;
  };

  static IndexedDBContentUpdatedParamsBuilder<0> Builder() {
    return IndexedDBContentUpdatedParamsBuilder<0>();
  }

 private:
  IndexedDBContentUpdatedParams() { }

  std::string origin_;
  std::string database_name_;
  std::string object_store_name_;

  DISALLOW_COPY_AND_ASSIGN(IndexedDBContentUpdatedParams);
};


// Parameters for the IndexedDBListUpdated event.
class HEADLESS_EXPORT IndexedDBListUpdatedParams {
 public:
  static std::unique_ptr<IndexedDBListUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~IndexedDBListUpdatedParams() { }

  // Origin to update.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<IndexedDBListUpdatedParams> Clone() const;

  template<int STATE>
  class IndexedDBListUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    IndexedDBListUpdatedParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<IndexedDBListUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class IndexedDBListUpdatedParams;
    IndexedDBListUpdatedParamsBuilder() : result_(new IndexedDBListUpdatedParams()) { }

    template<int STEP> IndexedDBListUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<IndexedDBListUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<IndexedDBListUpdatedParams> result_;
  };

  static IndexedDBListUpdatedParamsBuilder<0> Builder() {
    return IndexedDBListUpdatedParamsBuilder<0>();
  }

 private:
  IndexedDBListUpdatedParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(IndexedDBListUpdatedParams);
};


}  // namespace storage

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_STORAGE_H_
