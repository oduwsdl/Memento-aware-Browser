// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_AUDITS_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_AUDITS_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_audits.h"
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

namespace audits {

// Information about a cookie that is affected by an inspector issue.
class HEADLESS_EXPORT AffectedCookie {
 public:
  static std::unique_ptr<AffectedCookie> Parse(const base::Value& value, ErrorReporter* errors);
  ~AffectedCookie() { }

  // The following three properties uniquely identify a cookie
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::string GetPath() const { return path_; }
  void SetPath(const std::string& value) { path_ = value; }

  std::string GetDomain() const { return domain_; }
  void SetDomain(const std::string& value) { domain_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AffectedCookie> Clone() const;

  template<int STATE>
  class AffectedCookieBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kPathSet = 1 << 2,
    kDomainSet = 1 << 3,
      kAllRequiredFieldsSet = (kNameSet | kPathSet | kDomainSet | 0)
    };

    AffectedCookieBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    AffectedCookieBuilder<STATE | kPathSet>& SetPath(const std::string& value) {
      static_assert(!(STATE & kPathSet), "property path should not have already been set");
      result_->SetPath(value);
      return CastState<kPathSet>();
    }

    AffectedCookieBuilder<STATE | kDomainSet>& SetDomain(const std::string& value) {
      static_assert(!(STATE & kDomainSet), "property domain should not have already been set");
      result_->SetDomain(value);
      return CastState<kDomainSet>();
    }

    std::unique_ptr<AffectedCookie> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AffectedCookie;
    AffectedCookieBuilder() : result_(new AffectedCookie()) { }

    template<int STEP> AffectedCookieBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AffectedCookieBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AffectedCookie> result_;
  };

  static AffectedCookieBuilder<0> Builder() {
    return AffectedCookieBuilder<0>();
  }

 private:
  AffectedCookie() { }

  std::string name_;
  std::string path_;
  std::string domain_;

  DISALLOW_COPY_AND_ASSIGN(AffectedCookie);
};


// Information about a request that is affected by an inspector issue.
class HEADLESS_EXPORT AffectedRequest {
 public:
  static std::unique_ptr<AffectedRequest> Parse(const base::Value& value, ErrorReporter* errors);
  ~AffectedRequest() { }

  // The unique request id.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AffectedRequest> Clone() const;

  template<int STATE>
  class AffectedRequestBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kRequestIdSet | 0)
    };

    AffectedRequestBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    AffectedRequestBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    std::unique_ptr<AffectedRequest> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AffectedRequest;
    AffectedRequestBuilder() : result_(new AffectedRequest()) { }

    template<int STEP> AffectedRequestBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AffectedRequestBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AffectedRequest> result_;
  };

  static AffectedRequestBuilder<0> Builder() {
    return AffectedRequestBuilder<0>();
  }

 private:
  AffectedRequest() { }

  std::string request_id_;
  base::Optional<std::string> url_;

  DISALLOW_COPY_AND_ASSIGN(AffectedRequest);
};


// Information about the frame affected by an inspector issue.
class HEADLESS_EXPORT AffectedFrame {
 public:
  static std::unique_ptr<AffectedFrame> Parse(const base::Value& value, ErrorReporter* errors);
  ~AffectedFrame() { }

  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AffectedFrame> Clone() const;

  template<int STATE>
  class AffectedFrameBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    AffectedFrameBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<AffectedFrame> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AffectedFrame;
    AffectedFrameBuilder() : result_(new AffectedFrame()) { }

    template<int STEP> AffectedFrameBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AffectedFrameBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AffectedFrame> result_;
  };

  static AffectedFrameBuilder<0> Builder() {
    return AffectedFrameBuilder<0>();
  }

 private:
  AffectedFrame() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(AffectedFrame);
};


// This information is currently necessary, as the front-end has a difficult
// time finding a specific cookie. With this, we can convey specific error
// information without the cookie.
class HEADLESS_EXPORT SameSiteCookieIssueDetails {
 public:
  static std::unique_ptr<SameSiteCookieIssueDetails> Parse(const base::Value& value, ErrorReporter* errors);
  ~SameSiteCookieIssueDetails() { }

  const ::headless::audits::AffectedCookie* GetCookie() const { return cookie_.get(); }
  void SetCookie(std::unique_ptr<::headless::audits::AffectedCookie> value) { cookie_ = std::move(value); }

  const std::vector<::headless::audits::SameSiteCookieWarningReason>* GetCookieWarningReasons() const { return &cookie_warning_reasons_; }
  void SetCookieWarningReasons(std::vector<::headless::audits::SameSiteCookieWarningReason> value) { cookie_warning_reasons_ = std::move(value); }

  const std::vector<::headless::audits::SameSiteCookieExclusionReason>* GetCookieExclusionReasons() const { return &cookie_exclusion_reasons_; }
  void SetCookieExclusionReasons(std::vector<::headless::audits::SameSiteCookieExclusionReason> value) { cookie_exclusion_reasons_ = std::move(value); }

  // Optionally identifies the site-for-cookies and the cookie url, which
  // may be used by the front-end as additional context.
  ::headless::audits::SameSiteCookieOperation GetOperation() const { return operation_; }
  void SetOperation(::headless::audits::SameSiteCookieOperation value) { operation_ = value; }

  bool HasSiteForCookies() const { return !!site_for_cookies_; }
  std::string GetSiteForCookies() const { DCHECK(HasSiteForCookies()); return site_for_cookies_.value(); }
  void SetSiteForCookies(const std::string& value) { site_for_cookies_ = value; }

  bool HasCookieUrl() const { return !!cookie_url_; }
  std::string GetCookieUrl() const { DCHECK(HasCookieUrl()); return cookie_url_.value(); }
  void SetCookieUrl(const std::string& value) { cookie_url_ = value; }

  bool HasRequest() const { return !!request_; }
  const ::headless::audits::AffectedRequest* GetRequest() const { DCHECK(HasRequest()); return request_.value().get(); }
  void SetRequest(std::unique_ptr<::headless::audits::AffectedRequest> value) { request_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SameSiteCookieIssueDetails> Clone() const;

  template<int STATE>
  class SameSiteCookieIssueDetailsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCookieSet = 1 << 1,
    kCookieWarningReasonsSet = 1 << 2,
    kCookieExclusionReasonsSet = 1 << 3,
    kOperationSet = 1 << 4,
      kAllRequiredFieldsSet = (kCookieSet | kCookieWarningReasonsSet | kCookieExclusionReasonsSet | kOperationSet | 0)
    };

    SameSiteCookieIssueDetailsBuilder<STATE | kCookieSet>& SetCookie(std::unique_ptr<::headless::audits::AffectedCookie> value) {
      static_assert(!(STATE & kCookieSet), "property cookie should not have already been set");
      result_->SetCookie(std::move(value));
      return CastState<kCookieSet>();
    }

    SameSiteCookieIssueDetailsBuilder<STATE | kCookieWarningReasonsSet>& SetCookieWarningReasons(std::vector<::headless::audits::SameSiteCookieWarningReason> value) {
      static_assert(!(STATE & kCookieWarningReasonsSet), "property cookieWarningReasons should not have already been set");
      result_->SetCookieWarningReasons(std::move(value));
      return CastState<kCookieWarningReasonsSet>();
    }

    SameSiteCookieIssueDetailsBuilder<STATE | kCookieExclusionReasonsSet>& SetCookieExclusionReasons(std::vector<::headless::audits::SameSiteCookieExclusionReason> value) {
      static_assert(!(STATE & kCookieExclusionReasonsSet), "property cookieExclusionReasons should not have already been set");
      result_->SetCookieExclusionReasons(std::move(value));
      return CastState<kCookieExclusionReasonsSet>();
    }

    SameSiteCookieIssueDetailsBuilder<STATE | kOperationSet>& SetOperation(::headless::audits::SameSiteCookieOperation value) {
      static_assert(!(STATE & kOperationSet), "property operation should not have already been set");
      result_->SetOperation(value);
      return CastState<kOperationSet>();
    }

    SameSiteCookieIssueDetailsBuilder<STATE>& SetSiteForCookies(const std::string& value) {
      result_->SetSiteForCookies(value);
      return *this;
    }

    SameSiteCookieIssueDetailsBuilder<STATE>& SetCookieUrl(const std::string& value) {
      result_->SetCookieUrl(value);
      return *this;
    }

    SameSiteCookieIssueDetailsBuilder<STATE>& SetRequest(std::unique_ptr<::headless::audits::AffectedRequest> value) {
      result_->SetRequest(std::move(value));
      return *this;
    }

    std::unique_ptr<SameSiteCookieIssueDetails> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SameSiteCookieIssueDetails;
    SameSiteCookieIssueDetailsBuilder() : result_(new SameSiteCookieIssueDetails()) { }

    template<int STEP> SameSiteCookieIssueDetailsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SameSiteCookieIssueDetailsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SameSiteCookieIssueDetails> result_;
  };

  static SameSiteCookieIssueDetailsBuilder<0> Builder() {
    return SameSiteCookieIssueDetailsBuilder<0>();
  }

 private:
  SameSiteCookieIssueDetails() { }

  std::unique_ptr<::headless::audits::AffectedCookie> cookie_;
  std::vector<::headless::audits::SameSiteCookieWarningReason> cookie_warning_reasons_;
  std::vector<::headless::audits::SameSiteCookieExclusionReason> cookie_exclusion_reasons_;
  ::headless::audits::SameSiteCookieOperation operation_;
  base::Optional<std::string> site_for_cookies_;
  base::Optional<std::string> cookie_url_;
  base::Optional<std::unique_ptr<::headless::audits::AffectedRequest>> request_;

  DISALLOW_COPY_AND_ASSIGN(SameSiteCookieIssueDetails);
};


class HEADLESS_EXPORT MixedContentIssueDetails {
 public:
  static std::unique_ptr<MixedContentIssueDetails> Parse(const base::Value& value, ErrorReporter* errors);
  ~MixedContentIssueDetails() { }

  // The type of resource causing the mixed content issue (css, js, iframe,
  // form,...). Marked as optional because it is mapped to from
  // blink::mojom::RequestContextType, which will be replaced
  // by network::mojom::RequestDestination
  bool HasResourceType() const { return !!resource_type_; }
  ::headless::audits::MixedContentResourceType GetResourceType() const { DCHECK(HasResourceType()); return resource_type_.value(); }
  void SetResourceType(::headless::audits::MixedContentResourceType value) { resource_type_ = value; }

  // The way the mixed content issue is being resolved.
  ::headless::audits::MixedContentResolutionStatus GetResolutionStatus() const { return resolution_status_; }
  void SetResolutionStatus(::headless::audits::MixedContentResolutionStatus value) { resolution_status_ = value; }

  // The unsafe http url causing the mixed content issue.
  std::string GetInsecureURL() const { return insecureurl_; }
  void SetInsecureURL(const std::string& value) { insecureurl_ = value; }

  // The url responsible for the call to an unsafe url.
  std::string GetMainResourceURL() const { return main_resourceurl_; }
  void SetMainResourceURL(const std::string& value) { main_resourceurl_ = value; }

  // The mixed content request.
  // Does not always exist (e.g. for unsafe form submission urls).
  bool HasRequest() const { return !!request_; }
  const ::headless::audits::AffectedRequest* GetRequest() const { DCHECK(HasRequest()); return request_.value().get(); }
  void SetRequest(std::unique_ptr<::headless::audits::AffectedRequest> value) { request_ = std::move(value); }

  // Optional because not every mixed content issue is necessarily linked to a frame.
  bool HasFrame() const { return !!frame_; }
  const ::headless::audits::AffectedFrame* GetFrame() const { DCHECK(HasFrame()); return frame_.value().get(); }
  void SetFrame(std::unique_ptr<::headless::audits::AffectedFrame> value) { frame_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MixedContentIssueDetails> Clone() const;

  template<int STATE>
  class MixedContentIssueDetailsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResolutionStatusSet = 1 << 1,
    kInsecureURLSet = 1 << 2,
    kMainResourceURLSet = 1 << 3,
      kAllRequiredFieldsSet = (kResolutionStatusSet | kInsecureURLSet | kMainResourceURLSet | 0)
    };

    MixedContentIssueDetailsBuilder<STATE>& SetResourceType(::headless::audits::MixedContentResourceType value) {
      result_->SetResourceType(value);
      return *this;
    }

    MixedContentIssueDetailsBuilder<STATE | kResolutionStatusSet>& SetResolutionStatus(::headless::audits::MixedContentResolutionStatus value) {
      static_assert(!(STATE & kResolutionStatusSet), "property resolutionStatus should not have already been set");
      result_->SetResolutionStatus(value);
      return CastState<kResolutionStatusSet>();
    }

    MixedContentIssueDetailsBuilder<STATE | kInsecureURLSet>& SetInsecureURL(const std::string& value) {
      static_assert(!(STATE & kInsecureURLSet), "property insecureURL should not have already been set");
      result_->SetInsecureURL(value);
      return CastState<kInsecureURLSet>();
    }

    MixedContentIssueDetailsBuilder<STATE | kMainResourceURLSet>& SetMainResourceURL(const std::string& value) {
      static_assert(!(STATE & kMainResourceURLSet), "property mainResourceURL should not have already been set");
      result_->SetMainResourceURL(value);
      return CastState<kMainResourceURLSet>();
    }

    MixedContentIssueDetailsBuilder<STATE>& SetRequest(std::unique_ptr<::headless::audits::AffectedRequest> value) {
      result_->SetRequest(std::move(value));
      return *this;
    }

    MixedContentIssueDetailsBuilder<STATE>& SetFrame(std::unique_ptr<::headless::audits::AffectedFrame> value) {
      result_->SetFrame(std::move(value));
      return *this;
    }

    std::unique_ptr<MixedContentIssueDetails> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MixedContentIssueDetails;
    MixedContentIssueDetailsBuilder() : result_(new MixedContentIssueDetails()) { }

    template<int STEP> MixedContentIssueDetailsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MixedContentIssueDetailsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MixedContentIssueDetails> result_;
  };

  static MixedContentIssueDetailsBuilder<0> Builder() {
    return MixedContentIssueDetailsBuilder<0>();
  }

 private:
  MixedContentIssueDetails() { }

  base::Optional<::headless::audits::MixedContentResourceType> resource_type_;
  ::headless::audits::MixedContentResolutionStatus resolution_status_;
  std::string insecureurl_;
  std::string main_resourceurl_;
  base::Optional<std::unique_ptr<::headless::audits::AffectedRequest>> request_;
  base::Optional<std::unique_ptr<::headless::audits::AffectedFrame>> frame_;

  DISALLOW_COPY_AND_ASSIGN(MixedContentIssueDetails);
};


// Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
// code. Currently only used for COEP/COOP, but may be extended to include
// some CSP errors in the future.
class HEADLESS_EXPORT BlockedByResponseIssueDetails {
 public:
  static std::unique_ptr<BlockedByResponseIssueDetails> Parse(const base::Value& value, ErrorReporter* errors);
  ~BlockedByResponseIssueDetails() { }

  const ::headless::audits::AffectedRequest* GetRequest() const { return request_.get(); }
  void SetRequest(std::unique_ptr<::headless::audits::AffectedRequest> value) { request_ = std::move(value); }

  bool HasFrame() const { return !!frame_; }
  const ::headless::audits::AffectedFrame* GetFrame() const { DCHECK(HasFrame()); return frame_.value().get(); }
  void SetFrame(std::unique_ptr<::headless::audits::AffectedFrame> value) { frame_ = std::move(value); }

  ::headless::audits::BlockedByResponseReason GetReason() const { return reason_; }
  void SetReason(::headless::audits::BlockedByResponseReason value) { reason_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BlockedByResponseIssueDetails> Clone() const;

  template<int STATE>
  class BlockedByResponseIssueDetailsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestSet = 1 << 1,
    kReasonSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestSet | kReasonSet | 0)
    };

    BlockedByResponseIssueDetailsBuilder<STATE | kRequestSet>& SetRequest(std::unique_ptr<::headless::audits::AffectedRequest> value) {
      static_assert(!(STATE & kRequestSet), "property request should not have already been set");
      result_->SetRequest(std::move(value));
      return CastState<kRequestSet>();
    }

    BlockedByResponseIssueDetailsBuilder<STATE>& SetFrame(std::unique_ptr<::headless::audits::AffectedFrame> value) {
      result_->SetFrame(std::move(value));
      return *this;
    }

    BlockedByResponseIssueDetailsBuilder<STATE | kReasonSet>& SetReason(::headless::audits::BlockedByResponseReason value) {
      static_assert(!(STATE & kReasonSet), "property reason should not have already been set");
      result_->SetReason(value);
      return CastState<kReasonSet>();
    }

    std::unique_ptr<BlockedByResponseIssueDetails> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BlockedByResponseIssueDetails;
    BlockedByResponseIssueDetailsBuilder() : result_(new BlockedByResponseIssueDetails()) { }

    template<int STEP> BlockedByResponseIssueDetailsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BlockedByResponseIssueDetailsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BlockedByResponseIssueDetails> result_;
  };

  static BlockedByResponseIssueDetailsBuilder<0> Builder() {
    return BlockedByResponseIssueDetailsBuilder<0>();
  }

 private:
  BlockedByResponseIssueDetails() { }

  std::unique_ptr<::headless::audits::AffectedRequest> request_;
  base::Optional<std::unique_ptr<::headless::audits::AffectedFrame>> frame_;
  ::headless::audits::BlockedByResponseReason reason_;

  DISALLOW_COPY_AND_ASSIGN(BlockedByResponseIssueDetails);
};


// This struct holds a list of optional fields with additional information
// specific to the kind of issue. When adding a new issue code, please also
// add a new optional field to this type.
class HEADLESS_EXPORT InspectorIssueDetails {
 public:
  static std::unique_ptr<InspectorIssueDetails> Parse(const base::Value& value, ErrorReporter* errors);
  ~InspectorIssueDetails() { }

  bool HasSameSiteCookieIssueDetails() const { return !!same_site_cookie_issue_details_; }
  const ::headless::audits::SameSiteCookieIssueDetails* GetSameSiteCookieIssueDetails() const { DCHECK(HasSameSiteCookieIssueDetails()); return same_site_cookie_issue_details_.value().get(); }
  void SetSameSiteCookieIssueDetails(std::unique_ptr<::headless::audits::SameSiteCookieIssueDetails> value) { same_site_cookie_issue_details_ = std::move(value); }

  bool HasMixedContentIssueDetails() const { return !!mixed_content_issue_details_; }
  const ::headless::audits::MixedContentIssueDetails* GetMixedContentIssueDetails() const { DCHECK(HasMixedContentIssueDetails()); return mixed_content_issue_details_.value().get(); }
  void SetMixedContentIssueDetails(std::unique_ptr<::headless::audits::MixedContentIssueDetails> value) { mixed_content_issue_details_ = std::move(value); }

  bool HasBlockedByResponseIssueDetails() const { return !!blocked_by_response_issue_details_; }
  const ::headless::audits::BlockedByResponseIssueDetails* GetBlockedByResponseIssueDetails() const { DCHECK(HasBlockedByResponseIssueDetails()); return blocked_by_response_issue_details_.value().get(); }
  void SetBlockedByResponseIssueDetails(std::unique_ptr<::headless::audits::BlockedByResponseIssueDetails> value) { blocked_by_response_issue_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InspectorIssueDetails> Clone() const;

  template<int STATE>
  class InspectorIssueDetailsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    InspectorIssueDetailsBuilder<STATE>& SetSameSiteCookieIssueDetails(std::unique_ptr<::headless::audits::SameSiteCookieIssueDetails> value) {
      result_->SetSameSiteCookieIssueDetails(std::move(value));
      return *this;
    }

    InspectorIssueDetailsBuilder<STATE>& SetMixedContentIssueDetails(std::unique_ptr<::headless::audits::MixedContentIssueDetails> value) {
      result_->SetMixedContentIssueDetails(std::move(value));
      return *this;
    }

    InspectorIssueDetailsBuilder<STATE>& SetBlockedByResponseIssueDetails(std::unique_ptr<::headless::audits::BlockedByResponseIssueDetails> value) {
      result_->SetBlockedByResponseIssueDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<InspectorIssueDetails> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InspectorIssueDetails;
    InspectorIssueDetailsBuilder() : result_(new InspectorIssueDetails()) { }

    template<int STEP> InspectorIssueDetailsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InspectorIssueDetailsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InspectorIssueDetails> result_;
  };

  static InspectorIssueDetailsBuilder<0> Builder() {
    return InspectorIssueDetailsBuilder<0>();
  }

 private:
  InspectorIssueDetails() { }

  base::Optional<std::unique_ptr<::headless::audits::SameSiteCookieIssueDetails>> same_site_cookie_issue_details_;
  base::Optional<std::unique_ptr<::headless::audits::MixedContentIssueDetails>> mixed_content_issue_details_;
  base::Optional<std::unique_ptr<::headless::audits::BlockedByResponseIssueDetails>> blocked_by_response_issue_details_;

  DISALLOW_COPY_AND_ASSIGN(InspectorIssueDetails);
};


// An inspector issue reported from the back-end.
class HEADLESS_EXPORT InspectorIssue {
 public:
  static std::unique_ptr<InspectorIssue> Parse(const base::Value& value, ErrorReporter* errors);
  ~InspectorIssue() { }

  ::headless::audits::InspectorIssueCode GetCode() const { return code_; }
  void SetCode(::headless::audits::InspectorIssueCode value) { code_ = value; }

  const ::headless::audits::InspectorIssueDetails* GetDetails() const { return details_.get(); }
  void SetDetails(std::unique_ptr<::headless::audits::InspectorIssueDetails> value) { details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InspectorIssue> Clone() const;

  template<int STATE>
  class InspectorIssueBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCodeSet = 1 << 1,
    kDetailsSet = 1 << 2,
      kAllRequiredFieldsSet = (kCodeSet | kDetailsSet | 0)
    };

    InspectorIssueBuilder<STATE | kCodeSet>& SetCode(::headless::audits::InspectorIssueCode value) {
      static_assert(!(STATE & kCodeSet), "property code should not have already been set");
      result_->SetCode(value);
      return CastState<kCodeSet>();
    }

    InspectorIssueBuilder<STATE | kDetailsSet>& SetDetails(std::unique_ptr<::headless::audits::InspectorIssueDetails> value) {
      static_assert(!(STATE & kDetailsSet), "property details should not have already been set");
      result_->SetDetails(std::move(value));
      return CastState<kDetailsSet>();
    }

    std::unique_ptr<InspectorIssue> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InspectorIssue;
    InspectorIssueBuilder() : result_(new InspectorIssue()) { }

    template<int STEP> InspectorIssueBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InspectorIssueBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InspectorIssue> result_;
  };

  static InspectorIssueBuilder<0> Builder() {
    return InspectorIssueBuilder<0>();
  }

 private:
  InspectorIssue() { }

  ::headless::audits::InspectorIssueCode code_;
  std::unique_ptr<::headless::audits::InspectorIssueDetails> details_;

  DISALLOW_COPY_AND_ASSIGN(InspectorIssue);
};


// Parameters for the GetEncodedResponse command.
class HEADLESS_EXPORT GetEncodedResponseParams {
 public:
  static std::unique_ptr<GetEncodedResponseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetEncodedResponseParams() { }

  // Identifier of the network request to get content for.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // The encoding to use.
  ::headless::audits::GetEncodedResponseEncoding GetEncoding() const { return encoding_; }
  void SetEncoding(::headless::audits::GetEncodedResponseEncoding value) { encoding_ = value; }

  // The quality of the encoding (0-1). (defaults to 1)
  bool HasQuality() const { return !!quality_; }
  double GetQuality() const { DCHECK(HasQuality()); return quality_.value(); }
  void SetQuality(double value) { quality_ = value; }

  // Whether to only return the size information (defaults to false).
  bool HasSizeOnly() const { return !!size_only_; }
  bool GetSizeOnly() const { DCHECK(HasSizeOnly()); return size_only_.value(); }
  void SetSizeOnly(bool value) { size_only_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetEncodedResponseParams> Clone() const;

  template<int STATE>
  class GetEncodedResponseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kEncodingSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kEncodingSet | 0)
    };

    GetEncodedResponseParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    GetEncodedResponseParamsBuilder<STATE | kEncodingSet>& SetEncoding(::headless::audits::GetEncodedResponseEncoding value) {
      static_assert(!(STATE & kEncodingSet), "property encoding should not have already been set");
      result_->SetEncoding(value);
      return CastState<kEncodingSet>();
    }

    GetEncodedResponseParamsBuilder<STATE>& SetQuality(double value) {
      result_->SetQuality(value);
      return *this;
    }

    GetEncodedResponseParamsBuilder<STATE>& SetSizeOnly(bool value) {
      result_->SetSizeOnly(value);
      return *this;
    }

    std::unique_ptr<GetEncodedResponseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetEncodedResponseParams;
    GetEncodedResponseParamsBuilder() : result_(new GetEncodedResponseParams()) { }

    template<int STEP> GetEncodedResponseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetEncodedResponseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetEncodedResponseParams> result_;
  };

  static GetEncodedResponseParamsBuilder<0> Builder() {
    return GetEncodedResponseParamsBuilder<0>();
  }

 private:
  GetEncodedResponseParams() { }

  std::string request_id_;
  ::headless::audits::GetEncodedResponseEncoding encoding_;
  base::Optional<double> quality_;
  base::Optional<bool> size_only_;

  DISALLOW_COPY_AND_ASSIGN(GetEncodedResponseParams);
};


// Result for the GetEncodedResponse command.
class HEADLESS_EXPORT GetEncodedResponseResult {
 public:
  static std::unique_ptr<GetEncodedResponseResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetEncodedResponseResult() { }

  // The encoded body as a base64 string. Omitted if sizeOnly is true.
  bool HasBody() const { return !!body_; }
  protocol::Binary GetBody() const { DCHECK(HasBody()); return body_.value(); }
  void SetBody(const protocol::Binary& value) { body_ = value; }

  // Size before re-encoding.
  int GetOriginalSize() const { return original_size_; }
  void SetOriginalSize(int value) { original_size_ = value; }

  // Size after re-encoding.
  int GetEncodedSize() const { return encoded_size_; }
  void SetEncodedSize(int value) { encoded_size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetEncodedResponseResult> Clone() const;

  template<int STATE>
  class GetEncodedResponseResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginalSizeSet = 1 << 1,
    kEncodedSizeSet = 1 << 2,
      kAllRequiredFieldsSet = (kOriginalSizeSet | kEncodedSizeSet | 0)
    };

    GetEncodedResponseResultBuilder<STATE>& SetBody(const protocol::Binary& value) {
      result_->SetBody(value);
      return *this;
    }

    GetEncodedResponseResultBuilder<STATE | kOriginalSizeSet>& SetOriginalSize(int value) {
      static_assert(!(STATE & kOriginalSizeSet), "property originalSize should not have already been set");
      result_->SetOriginalSize(value);
      return CastState<kOriginalSizeSet>();
    }

    GetEncodedResponseResultBuilder<STATE | kEncodedSizeSet>& SetEncodedSize(int value) {
      static_assert(!(STATE & kEncodedSizeSet), "property encodedSize should not have already been set");
      result_->SetEncodedSize(value);
      return CastState<kEncodedSizeSet>();
    }

    std::unique_ptr<GetEncodedResponseResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetEncodedResponseResult;
    GetEncodedResponseResultBuilder() : result_(new GetEncodedResponseResult()) { }

    template<int STEP> GetEncodedResponseResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetEncodedResponseResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetEncodedResponseResult> result_;
  };

  static GetEncodedResponseResultBuilder<0> Builder() {
    return GetEncodedResponseResultBuilder<0>();
  }

 private:
  GetEncodedResponseResult() { }

  base::Optional<protocol::Binary> body_;
  int original_size_;
  int encoded_size_;

  DISALLOW_COPY_AND_ASSIGN(GetEncodedResponseResult);
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

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

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


// Parameters for the IssueAdded event.
class HEADLESS_EXPORT IssueAddedParams {
 public:
  static std::unique_ptr<IssueAddedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~IssueAddedParams() { }

  const ::headless::audits::InspectorIssue* GetIssue() const { return issue_.get(); }
  void SetIssue(std::unique_ptr<::headless::audits::InspectorIssue> value) { issue_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<IssueAddedParams> Clone() const;

  template<int STATE>
  class IssueAddedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIssueSet = 1 << 1,
      kAllRequiredFieldsSet = (kIssueSet | 0)
    };

    IssueAddedParamsBuilder<STATE | kIssueSet>& SetIssue(std::unique_ptr<::headless::audits::InspectorIssue> value) {
      static_assert(!(STATE & kIssueSet), "property issue should not have already been set");
      result_->SetIssue(std::move(value));
      return CastState<kIssueSet>();
    }

    std::unique_ptr<IssueAddedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class IssueAddedParams;
    IssueAddedParamsBuilder() : result_(new IssueAddedParams()) { }

    template<int STEP> IssueAddedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<IssueAddedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<IssueAddedParams> result_;
  };

  static IssueAddedParamsBuilder<0> Builder() {
    return IssueAddedParamsBuilder<0>();
  }

 private:
  IssueAddedParams() { }

  std::unique_ptr<::headless::audits::InspectorIssue> issue_;

  DISALLOW_COPY_AND_ASSIGN(IssueAddedParams);
};


}  // namespace audits

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_AUDITS_H_
