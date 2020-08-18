// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_FETCH_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_FETCH_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_fetch.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace fetch {

class HEADLESS_EXPORT RequestPattern {
 public:
  static std::unique_ptr<RequestPattern> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestPattern() { }

  // Wildcards ('*' -> zero or more, '?' -> exactly one) are allowed. Escape character is
  // backslash. Omitting is equivalent to "*".
  bool HasUrlPattern() const { return !!url_pattern_; }
  std::string GetUrlPattern() const { DCHECK(HasUrlPattern()); return url_pattern_.value(); }
  void SetUrlPattern(const std::string& value) { url_pattern_ = value; }

  // If set, only requests for matching resource types will be intercepted.
  bool HasResourceType() const { return !!resource_type_; }
  ::headless::network::ResourceType GetResourceType() const { DCHECK(HasResourceType()); return resource_type_.value(); }
  void SetResourceType(::headless::network::ResourceType value) { resource_type_ = value; }

  // Stage at wich to begin intercepting requests. Default is Request.
  bool HasRequestStage() const { return !!request_stage_; }
  ::headless::fetch::RequestStage GetRequestStage() const { DCHECK(HasRequestStage()); return request_stage_.value(); }
  void SetRequestStage(::headless::fetch::RequestStage value) { request_stage_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestPattern> Clone() const;

  template<int STATE>
  class RequestPatternBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    RequestPatternBuilder<STATE>& SetUrlPattern(const std::string& value) {
      result_->SetUrlPattern(value);
      return *this;
    }

    RequestPatternBuilder<STATE>& SetResourceType(::headless::network::ResourceType value) {
      result_->SetResourceType(value);
      return *this;
    }

    RequestPatternBuilder<STATE>& SetRequestStage(::headless::fetch::RequestStage value) {
      result_->SetRequestStage(value);
      return *this;
    }

    std::unique_ptr<RequestPattern> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestPattern;
    RequestPatternBuilder() : result_(new RequestPattern()) { }

    template<int STEP> RequestPatternBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestPatternBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestPattern> result_;
  };

  static RequestPatternBuilder<0> Builder() {
    return RequestPatternBuilder<0>();
  }

 private:
  RequestPattern() { }

  base::Optional<std::string> url_pattern_;
  base::Optional<::headless::network::ResourceType> resource_type_;
  base::Optional<::headless::fetch::RequestStage> request_stage_;

  DISALLOW_COPY_AND_ASSIGN(RequestPattern);
};


// Response HTTP header entry
class HEADLESS_EXPORT HeaderEntry {
 public:
  static std::unique_ptr<HeaderEntry> Parse(const base::Value& value, ErrorReporter* errors);
  ~HeaderEntry() { }

  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HeaderEntry> Clone() const;

  template<int STATE>
  class HeaderEntryBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    HeaderEntryBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    HeaderEntryBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<HeaderEntry> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HeaderEntry;
    HeaderEntryBuilder() : result_(new HeaderEntry()) { }

    template<int STEP> HeaderEntryBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HeaderEntryBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HeaderEntry> result_;
  };

  static HeaderEntryBuilder<0> Builder() {
    return HeaderEntryBuilder<0>();
  }

 private:
  HeaderEntry() { }

  std::string name_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(HeaderEntry);
};


// Authorization challenge for HTTP status code 401 or 407.
class HEADLESS_EXPORT AuthChallenge {
 public:
  static std::unique_ptr<AuthChallenge> Parse(const base::Value& value, ErrorReporter* errors);
  ~AuthChallenge() { }

  // Source of the authentication challenge.
  bool HasSource() const { return !!source_; }
  ::headless::fetch::AuthChallengeSource GetSource() const { DCHECK(HasSource()); return source_.value(); }
  void SetSource(::headless::fetch::AuthChallengeSource value) { source_ = value; }

  // Origin of the challenger.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  // The authentication scheme used, such as basic or digest
  std::string GetScheme() const { return scheme_; }
  void SetScheme(const std::string& value) { scheme_ = value; }

  // The realm of the challenge. May be empty.
  std::string GetRealm() const { return realm_; }
  void SetRealm(const std::string& value) { realm_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AuthChallenge> Clone() const;

  template<int STATE>
  class AuthChallengeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
    kSchemeSet = 1 << 2,
    kRealmSet = 1 << 3,
      kAllRequiredFieldsSet = (kOriginSet | kSchemeSet | kRealmSet | 0)
    };

    AuthChallengeBuilder<STATE>& SetSource(::headless::fetch::AuthChallengeSource value) {
      result_->SetSource(value);
      return *this;
    }

    AuthChallengeBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    AuthChallengeBuilder<STATE | kSchemeSet>& SetScheme(const std::string& value) {
      static_assert(!(STATE & kSchemeSet), "property scheme should not have already been set");
      result_->SetScheme(value);
      return CastState<kSchemeSet>();
    }

    AuthChallengeBuilder<STATE | kRealmSet>& SetRealm(const std::string& value) {
      static_assert(!(STATE & kRealmSet), "property realm should not have already been set");
      result_->SetRealm(value);
      return CastState<kRealmSet>();
    }

    std::unique_ptr<AuthChallenge> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AuthChallenge;
    AuthChallengeBuilder() : result_(new AuthChallenge()) { }

    template<int STEP> AuthChallengeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AuthChallengeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AuthChallenge> result_;
  };

  static AuthChallengeBuilder<0> Builder() {
    return AuthChallengeBuilder<0>();
  }

 private:
  AuthChallenge() { }

  base::Optional<::headless::fetch::AuthChallengeSource> source_;
  std::string origin_;
  std::string scheme_;
  std::string realm_;

  DISALLOW_COPY_AND_ASSIGN(AuthChallenge);
};


// Response to an AuthChallenge.
class HEADLESS_EXPORT AuthChallengeResponse {
 public:
  static std::unique_ptr<AuthChallengeResponse> Parse(const base::Value& value, ErrorReporter* errors);
  ~AuthChallengeResponse() { }

  // The decision on what to do in response to the authorization challenge.  Default means
  // deferring to the default behavior of the net stack, which will likely either the Cancel
  // authentication or display a popup dialog box.
  ::headless::fetch::AuthChallengeResponseResponse GetResponse() const { return response_; }
  void SetResponse(::headless::fetch::AuthChallengeResponseResponse value) { response_ = value; }

  // The username to provide, possibly empty. Should only be set if response is
  // ProvideCredentials.
  bool HasUsername() const { return !!username_; }
  std::string GetUsername() const { DCHECK(HasUsername()); return username_.value(); }
  void SetUsername(const std::string& value) { username_ = value; }

  // The password to provide, possibly empty. Should only be set if response is
  // ProvideCredentials.
  bool HasPassword() const { return !!password_; }
  std::string GetPassword() const { DCHECK(HasPassword()); return password_.value(); }
  void SetPassword(const std::string& value) { password_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AuthChallengeResponse> Clone() const;

  template<int STATE>
  class AuthChallengeResponseBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResponseSet = 1 << 1,
      kAllRequiredFieldsSet = (kResponseSet | 0)
    };

    AuthChallengeResponseBuilder<STATE | kResponseSet>& SetResponse(::headless::fetch::AuthChallengeResponseResponse value) {
      static_assert(!(STATE & kResponseSet), "property response should not have already been set");
      result_->SetResponse(value);
      return CastState<kResponseSet>();
    }

    AuthChallengeResponseBuilder<STATE>& SetUsername(const std::string& value) {
      result_->SetUsername(value);
      return *this;
    }

    AuthChallengeResponseBuilder<STATE>& SetPassword(const std::string& value) {
      result_->SetPassword(value);
      return *this;
    }

    std::unique_ptr<AuthChallengeResponse> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AuthChallengeResponse;
    AuthChallengeResponseBuilder() : result_(new AuthChallengeResponse()) { }

    template<int STEP> AuthChallengeResponseBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AuthChallengeResponseBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AuthChallengeResponse> result_;
  };

  static AuthChallengeResponseBuilder<0> Builder() {
    return AuthChallengeResponseBuilder<0>();
  }

 private:
  AuthChallengeResponse() { }

  ::headless::fetch::AuthChallengeResponseResponse response_;
  base::Optional<std::string> username_;
  base::Optional<std::string> password_;

  DISALLOW_COPY_AND_ASSIGN(AuthChallengeResponse);
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

  // If specified, only requests matching any of these patterns will produce
  // fetchRequested event and will be paused until clients response. If not set,
  // all requests will be affected.
  bool HasPatterns() const { return !!patterns_; }
  const std::vector<std::unique_ptr<::headless::fetch::RequestPattern>>* GetPatterns() const { DCHECK(HasPatterns()); return &patterns_.value(); }
  void SetPatterns(std::vector<std::unique_ptr<::headless::fetch::RequestPattern>> value) { patterns_ = std::move(value); }

  // If true, authRequired events will be issued and requests will be paused
  // expecting a call to continueWithAuth.
  bool HasHandleAuthRequests() const { return !!handle_auth_requests_; }
  bool GetHandleAuthRequests() const { DCHECK(HasHandleAuthRequests()); return handle_auth_requests_.value(); }
  void SetHandleAuthRequests(bool value) { handle_auth_requests_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    EnableParamsBuilder<STATE>& SetPatterns(std::vector<std::unique_ptr<::headless::fetch::RequestPattern>> value) {
      result_->SetPatterns(std::move(value));
      return *this;
    }

    EnableParamsBuilder<STATE>& SetHandleAuthRequests(bool value) {
      result_->SetHandleAuthRequests(value);
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

  base::Optional<std::vector<std::unique_ptr<::headless::fetch::RequestPattern>>> patterns_;
  base::Optional<bool> handle_auth_requests_;

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


// Parameters for the FailRequest command.
class HEADLESS_EXPORT FailRequestParams {
 public:
  static std::unique_ptr<FailRequestParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FailRequestParams() { }

  // An id the client received in requestPaused event.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Causes the request to fail with the given reason.
  ::headless::network::ErrorReason GetErrorReason() const { return error_reason_; }
  void SetErrorReason(::headless::network::ErrorReason value) { error_reason_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FailRequestParams> Clone() const;

  template<int STATE>
  class FailRequestParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kErrorReasonSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kErrorReasonSet | 0)
    };

    FailRequestParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    FailRequestParamsBuilder<STATE | kErrorReasonSet>& SetErrorReason(::headless::network::ErrorReason value) {
      static_assert(!(STATE & kErrorReasonSet), "property errorReason should not have already been set");
      result_->SetErrorReason(value);
      return CastState<kErrorReasonSet>();
    }

    std::unique_ptr<FailRequestParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FailRequestParams;
    FailRequestParamsBuilder() : result_(new FailRequestParams()) { }

    template<int STEP> FailRequestParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FailRequestParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FailRequestParams> result_;
  };

  static FailRequestParamsBuilder<0> Builder() {
    return FailRequestParamsBuilder<0>();
  }

 private:
  FailRequestParams() { }

  std::string request_id_;
  ::headless::network::ErrorReason error_reason_;

  DISALLOW_COPY_AND_ASSIGN(FailRequestParams);
};


// Result for the FailRequest command.
class HEADLESS_EXPORT FailRequestResult {
 public:
  static std::unique_ptr<FailRequestResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~FailRequestResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FailRequestResult> Clone() const;

  template<int STATE>
  class FailRequestResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<FailRequestResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FailRequestResult;
    FailRequestResultBuilder() : result_(new FailRequestResult()) { }

    template<int STEP> FailRequestResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FailRequestResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FailRequestResult> result_;
  };

  static FailRequestResultBuilder<0> Builder() {
    return FailRequestResultBuilder<0>();
  }

 private:
  FailRequestResult() { }


  DISALLOW_COPY_AND_ASSIGN(FailRequestResult);
};


// Parameters for the FulfillRequest command.
class HEADLESS_EXPORT FulfillRequestParams {
 public:
  static std::unique_ptr<FulfillRequestParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FulfillRequestParams() { }

  // An id the client received in requestPaused event.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // An HTTP response code.
  int GetResponseCode() const { return response_code_; }
  void SetResponseCode(int value) { response_code_ = value; }

  // Response headers.
  bool HasResponseHeaders() const { return !!response_headers_; }
  const std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>* GetResponseHeaders() const { DCHECK(HasResponseHeaders()); return &response_headers_.value(); }
  void SetResponseHeaders(std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>> value) { response_headers_ = std::move(value); }

  // Alternative way of specifying response headers as a \0-separated
  // series of name: value pairs. Prefer the above method unless you
  // need to represent some non-UTF8 values that can't be transmitted
  // over the protocol as text.
  bool HasBinaryResponseHeaders() const { return !!binary_response_headers_; }
  protocol::Binary GetBinaryResponseHeaders() const { DCHECK(HasBinaryResponseHeaders()); return binary_response_headers_.value(); }
  void SetBinaryResponseHeaders(const protocol::Binary& value) { binary_response_headers_ = value; }

  // A response body.
  bool HasBody() const { return !!body_; }
  protocol::Binary GetBody() const { DCHECK(HasBody()); return body_.value(); }
  void SetBody(const protocol::Binary& value) { body_ = value; }

  // A textual representation of responseCode.
  // If absent, a standard phrase matching responseCode is used.
  bool HasResponsePhrase() const { return !!response_phrase_; }
  std::string GetResponsePhrase() const { DCHECK(HasResponsePhrase()); return response_phrase_.value(); }
  void SetResponsePhrase(const std::string& value) { response_phrase_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FulfillRequestParams> Clone() const;

  template<int STATE>
  class FulfillRequestParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kResponseCodeSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kResponseCodeSet | 0)
    };

    FulfillRequestParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    FulfillRequestParamsBuilder<STATE | kResponseCodeSet>& SetResponseCode(int value) {
      static_assert(!(STATE & kResponseCodeSet), "property responseCode should not have already been set");
      result_->SetResponseCode(value);
      return CastState<kResponseCodeSet>();
    }

    FulfillRequestParamsBuilder<STATE>& SetResponseHeaders(std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>> value) {
      result_->SetResponseHeaders(std::move(value));
      return *this;
    }

    FulfillRequestParamsBuilder<STATE>& SetBinaryResponseHeaders(const protocol::Binary& value) {
      result_->SetBinaryResponseHeaders(value);
      return *this;
    }

    FulfillRequestParamsBuilder<STATE>& SetBody(const protocol::Binary& value) {
      result_->SetBody(value);
      return *this;
    }

    FulfillRequestParamsBuilder<STATE>& SetResponsePhrase(const std::string& value) {
      result_->SetResponsePhrase(value);
      return *this;
    }

    std::unique_ptr<FulfillRequestParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FulfillRequestParams;
    FulfillRequestParamsBuilder() : result_(new FulfillRequestParams()) { }

    template<int STEP> FulfillRequestParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FulfillRequestParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FulfillRequestParams> result_;
  };

  static FulfillRequestParamsBuilder<0> Builder() {
    return FulfillRequestParamsBuilder<0>();
  }

 private:
  FulfillRequestParams() { }

  std::string request_id_;
  int response_code_;
  base::Optional<std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>> response_headers_;
  base::Optional<protocol::Binary> binary_response_headers_;
  base::Optional<protocol::Binary> body_;
  base::Optional<std::string> response_phrase_;

  DISALLOW_COPY_AND_ASSIGN(FulfillRequestParams);
};


// Result for the FulfillRequest command.
class HEADLESS_EXPORT FulfillRequestResult {
 public:
  static std::unique_ptr<FulfillRequestResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~FulfillRequestResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FulfillRequestResult> Clone() const;

  template<int STATE>
  class FulfillRequestResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<FulfillRequestResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FulfillRequestResult;
    FulfillRequestResultBuilder() : result_(new FulfillRequestResult()) { }

    template<int STEP> FulfillRequestResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FulfillRequestResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FulfillRequestResult> result_;
  };

  static FulfillRequestResultBuilder<0> Builder() {
    return FulfillRequestResultBuilder<0>();
  }

 private:
  FulfillRequestResult() { }


  DISALLOW_COPY_AND_ASSIGN(FulfillRequestResult);
};


// Parameters for the ContinueRequest command.
class HEADLESS_EXPORT ContinueRequestParams {
 public:
  static std::unique_ptr<ContinueRequestParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContinueRequestParams() { }

  // An id the client received in requestPaused event.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // If set, the request url will be modified in a way that's not observable by page.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // If set, the request method is overridden.
  bool HasMethod() const { return !!method_; }
  std::string GetMethod() const { DCHECK(HasMethod()); return method_.value(); }
  void SetMethod(const std::string& value) { method_ = value; }

  // If set, overrides the post data in the request.
  bool HasPostData() const { return !!post_data_; }
  std::string GetPostData() const { DCHECK(HasPostData()); return post_data_.value(); }
  void SetPostData(const std::string& value) { post_data_ = value; }

  // If set, overrides the request headers.
  bool HasHeaders() const { return !!headers_; }
  const std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>* GetHeaders() const { DCHECK(HasHeaders()); return &headers_.value(); }
  void SetHeaders(std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>> value) { headers_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContinueRequestParams> Clone() const;

  template<int STATE>
  class ContinueRequestParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kRequestIdSet | 0)
    };

    ContinueRequestParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    ContinueRequestParamsBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    ContinueRequestParamsBuilder<STATE>& SetMethod(const std::string& value) {
      result_->SetMethod(value);
      return *this;
    }

    ContinueRequestParamsBuilder<STATE>& SetPostData(const std::string& value) {
      result_->SetPostData(value);
      return *this;
    }

    ContinueRequestParamsBuilder<STATE>& SetHeaders(std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>> value) {
      result_->SetHeaders(std::move(value));
      return *this;
    }

    std::unique_ptr<ContinueRequestParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContinueRequestParams;
    ContinueRequestParamsBuilder() : result_(new ContinueRequestParams()) { }

    template<int STEP> ContinueRequestParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContinueRequestParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContinueRequestParams> result_;
  };

  static ContinueRequestParamsBuilder<0> Builder() {
    return ContinueRequestParamsBuilder<0>();
  }

 private:
  ContinueRequestParams() { }

  std::string request_id_;
  base::Optional<std::string> url_;
  base::Optional<std::string> method_;
  base::Optional<std::string> post_data_;
  base::Optional<std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>> headers_;

  DISALLOW_COPY_AND_ASSIGN(ContinueRequestParams);
};


// Result for the ContinueRequest command.
class HEADLESS_EXPORT ContinueRequestResult {
 public:
  static std::unique_ptr<ContinueRequestResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContinueRequestResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContinueRequestResult> Clone() const;

  template<int STATE>
  class ContinueRequestResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ContinueRequestResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContinueRequestResult;
    ContinueRequestResultBuilder() : result_(new ContinueRequestResult()) { }

    template<int STEP> ContinueRequestResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContinueRequestResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContinueRequestResult> result_;
  };

  static ContinueRequestResultBuilder<0> Builder() {
    return ContinueRequestResultBuilder<0>();
  }

 private:
  ContinueRequestResult() { }


  DISALLOW_COPY_AND_ASSIGN(ContinueRequestResult);
};


// Parameters for the ContinueWithAuth command.
class HEADLESS_EXPORT ContinueWithAuthParams {
 public:
  static std::unique_ptr<ContinueWithAuthParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContinueWithAuthParams() { }

  // An id the client received in authRequired event.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Response to  with an authChallenge.
  const ::headless::fetch::AuthChallengeResponse* GetAuthChallengeResponse() const { return auth_challenge_response_.get(); }
  void SetAuthChallengeResponse(std::unique_ptr<::headless::fetch::AuthChallengeResponse> value) { auth_challenge_response_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContinueWithAuthParams> Clone() const;

  template<int STATE>
  class ContinueWithAuthParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kAuthChallengeResponseSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kAuthChallengeResponseSet | 0)
    };

    ContinueWithAuthParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    ContinueWithAuthParamsBuilder<STATE | kAuthChallengeResponseSet>& SetAuthChallengeResponse(std::unique_ptr<::headless::fetch::AuthChallengeResponse> value) {
      static_assert(!(STATE & kAuthChallengeResponseSet), "property authChallengeResponse should not have already been set");
      result_->SetAuthChallengeResponse(std::move(value));
      return CastState<kAuthChallengeResponseSet>();
    }

    std::unique_ptr<ContinueWithAuthParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContinueWithAuthParams;
    ContinueWithAuthParamsBuilder() : result_(new ContinueWithAuthParams()) { }

    template<int STEP> ContinueWithAuthParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContinueWithAuthParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContinueWithAuthParams> result_;
  };

  static ContinueWithAuthParamsBuilder<0> Builder() {
    return ContinueWithAuthParamsBuilder<0>();
  }

 private:
  ContinueWithAuthParams() { }

  std::string request_id_;
  std::unique_ptr<::headless::fetch::AuthChallengeResponse> auth_challenge_response_;

  DISALLOW_COPY_AND_ASSIGN(ContinueWithAuthParams);
};


// Result for the ContinueWithAuth command.
class HEADLESS_EXPORT ContinueWithAuthResult {
 public:
  static std::unique_ptr<ContinueWithAuthResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContinueWithAuthResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContinueWithAuthResult> Clone() const;

  template<int STATE>
  class ContinueWithAuthResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ContinueWithAuthResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContinueWithAuthResult;
    ContinueWithAuthResultBuilder() : result_(new ContinueWithAuthResult()) { }

    template<int STEP> ContinueWithAuthResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContinueWithAuthResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContinueWithAuthResult> result_;
  };

  static ContinueWithAuthResultBuilder<0> Builder() {
    return ContinueWithAuthResultBuilder<0>();
  }

 private:
  ContinueWithAuthResult() { }


  DISALLOW_COPY_AND_ASSIGN(ContinueWithAuthResult);
};


// Parameters for the GetResponseBody command.
class HEADLESS_EXPORT GetResponseBodyParams {
 public:
  static std::unique_ptr<GetResponseBodyParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResponseBodyParams() { }

  // Identifier for the intercepted request to get body for.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResponseBodyParams> Clone() const;

  template<int STATE>
  class GetResponseBodyParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kRequestIdSet | 0)
    };

    GetResponseBodyParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    std::unique_ptr<GetResponseBodyParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResponseBodyParams;
    GetResponseBodyParamsBuilder() : result_(new GetResponseBodyParams()) { }

    template<int STEP> GetResponseBodyParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResponseBodyParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResponseBodyParams> result_;
  };

  static GetResponseBodyParamsBuilder<0> Builder() {
    return GetResponseBodyParamsBuilder<0>();
  }

 private:
  GetResponseBodyParams() { }

  std::string request_id_;

  DISALLOW_COPY_AND_ASSIGN(GetResponseBodyParams);
};


// Result for the GetResponseBody command.
class HEADLESS_EXPORT GetResponseBodyResult {
 public:
  static std::unique_ptr<GetResponseBodyResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResponseBodyResult() { }

  // Response body.
  std::string GetBody() const { return body_; }
  void SetBody(const std::string& value) { body_ = value; }

  // True, if content was sent as base64.
  bool GetBase64Encoded() const { return base64_encoded_; }
  void SetBase64Encoded(bool value) { base64_encoded_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResponseBodyResult> Clone() const;

  template<int STATE>
  class GetResponseBodyResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBodySet = 1 << 1,
    kBase64EncodedSet = 1 << 2,
      kAllRequiredFieldsSet = (kBodySet | kBase64EncodedSet | 0)
    };

    GetResponseBodyResultBuilder<STATE | kBodySet>& SetBody(const std::string& value) {
      static_assert(!(STATE & kBodySet), "property body should not have already been set");
      result_->SetBody(value);
      return CastState<kBodySet>();
    }

    GetResponseBodyResultBuilder<STATE | kBase64EncodedSet>& SetBase64Encoded(bool value) {
      static_assert(!(STATE & kBase64EncodedSet), "property base64Encoded should not have already been set");
      result_->SetBase64Encoded(value);
      return CastState<kBase64EncodedSet>();
    }

    std::unique_ptr<GetResponseBodyResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResponseBodyResult;
    GetResponseBodyResultBuilder() : result_(new GetResponseBodyResult()) { }

    template<int STEP> GetResponseBodyResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResponseBodyResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResponseBodyResult> result_;
  };

  static GetResponseBodyResultBuilder<0> Builder() {
    return GetResponseBodyResultBuilder<0>();
  }

 private:
  GetResponseBodyResult() { }

  std::string body_;
  bool base64_encoded_;

  DISALLOW_COPY_AND_ASSIGN(GetResponseBodyResult);
};


// Parameters for the TakeResponseBodyAsStream command.
class HEADLESS_EXPORT TakeResponseBodyAsStreamParams {
 public:
  static std::unique_ptr<TakeResponseBodyAsStreamParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakeResponseBodyAsStreamParams() { }

  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakeResponseBodyAsStreamParams> Clone() const;

  template<int STATE>
  class TakeResponseBodyAsStreamParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kRequestIdSet | 0)
    };

    TakeResponseBodyAsStreamParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    std::unique_ptr<TakeResponseBodyAsStreamParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakeResponseBodyAsStreamParams;
    TakeResponseBodyAsStreamParamsBuilder() : result_(new TakeResponseBodyAsStreamParams()) { }

    template<int STEP> TakeResponseBodyAsStreamParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakeResponseBodyAsStreamParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakeResponseBodyAsStreamParams> result_;
  };

  static TakeResponseBodyAsStreamParamsBuilder<0> Builder() {
    return TakeResponseBodyAsStreamParamsBuilder<0>();
  }

 private:
  TakeResponseBodyAsStreamParams() { }

  std::string request_id_;

  DISALLOW_COPY_AND_ASSIGN(TakeResponseBodyAsStreamParams);
};


// Result for the TakeResponseBodyAsStream command.
class HEADLESS_EXPORT TakeResponseBodyAsStreamResult {
 public:
  static std::unique_ptr<TakeResponseBodyAsStreamResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakeResponseBodyAsStreamResult() { }

  std::string GetStream() const { return stream_; }
  void SetStream(const std::string& value) { stream_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakeResponseBodyAsStreamResult> Clone() const;

  template<int STATE>
  class TakeResponseBodyAsStreamResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStreamSet = 1 << 1,
      kAllRequiredFieldsSet = (kStreamSet | 0)
    };

    TakeResponseBodyAsStreamResultBuilder<STATE | kStreamSet>& SetStream(const std::string& value) {
      static_assert(!(STATE & kStreamSet), "property stream should not have already been set");
      result_->SetStream(value);
      return CastState<kStreamSet>();
    }

    std::unique_ptr<TakeResponseBodyAsStreamResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakeResponseBodyAsStreamResult;
    TakeResponseBodyAsStreamResultBuilder() : result_(new TakeResponseBodyAsStreamResult()) { }

    template<int STEP> TakeResponseBodyAsStreamResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakeResponseBodyAsStreamResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakeResponseBodyAsStreamResult> result_;
  };

  static TakeResponseBodyAsStreamResultBuilder<0> Builder() {
    return TakeResponseBodyAsStreamResultBuilder<0>();
  }

 private:
  TakeResponseBodyAsStreamResult() { }

  std::string stream_;

  DISALLOW_COPY_AND_ASSIGN(TakeResponseBodyAsStreamResult);
};


// Parameters for the RequestPaused event.
class HEADLESS_EXPORT RequestPausedParams {
 public:
  static std::unique_ptr<RequestPausedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestPausedParams() { }

  // Each request the page makes will have a unique id.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // The details of the request.
  const ::headless::network::Request* GetRequest() const { return request_.get(); }
  void SetRequest(std::unique_ptr<::headless::network::Request> value) { request_ = std::move(value); }

  // The id of the frame that initiated the request.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // How the requested resource will be used.
  ::headless::network::ResourceType GetResourceType() const { return resource_type_; }
  void SetResourceType(::headless::network::ResourceType value) { resource_type_ = value; }

  // Response error if intercepted at response stage.
  bool HasResponseErrorReason() const { return !!response_error_reason_; }
  ::headless::network::ErrorReason GetResponseErrorReason() const { DCHECK(HasResponseErrorReason()); return response_error_reason_.value(); }
  void SetResponseErrorReason(::headless::network::ErrorReason value) { response_error_reason_ = value; }

  // Response code if intercepted at response stage.
  bool HasResponseStatusCode() const { return !!response_status_code_; }
  int GetResponseStatusCode() const { DCHECK(HasResponseStatusCode()); return response_status_code_.value(); }
  void SetResponseStatusCode(int value) { response_status_code_ = value; }

  // Response headers if intercepted at the response stage.
  bool HasResponseHeaders() const { return !!response_headers_; }
  const std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>* GetResponseHeaders() const { DCHECK(HasResponseHeaders()); return &response_headers_.value(); }
  void SetResponseHeaders(std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>> value) { response_headers_ = std::move(value); }

  // If the intercepted request had a corresponding Network.requestWillBeSent event fired for it,
  // then this networkId will be the same as the requestId present in the requestWillBeSent event.
  bool HasNetworkId() const { return !!network_id_; }
  std::string GetNetworkId() const { DCHECK(HasNetworkId()); return network_id_.value(); }
  void SetNetworkId(const std::string& value) { network_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestPausedParams> Clone() const;

  template<int STATE>
  class RequestPausedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kRequestSet = 1 << 2,
    kFrameIdSet = 1 << 3,
    kResourceTypeSet = 1 << 4,
      kAllRequiredFieldsSet = (kRequestIdSet | kRequestSet | kFrameIdSet | kResourceTypeSet | 0)
    };

    RequestPausedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    RequestPausedParamsBuilder<STATE | kRequestSet>& SetRequest(std::unique_ptr<::headless::network::Request> value) {
      static_assert(!(STATE & kRequestSet), "property request should not have already been set");
      result_->SetRequest(std::move(value));
      return CastState<kRequestSet>();
    }

    RequestPausedParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    RequestPausedParamsBuilder<STATE | kResourceTypeSet>& SetResourceType(::headless::network::ResourceType value) {
      static_assert(!(STATE & kResourceTypeSet), "property resourceType should not have already been set");
      result_->SetResourceType(value);
      return CastState<kResourceTypeSet>();
    }

    RequestPausedParamsBuilder<STATE>& SetResponseErrorReason(::headless::network::ErrorReason value) {
      result_->SetResponseErrorReason(value);
      return *this;
    }

    RequestPausedParamsBuilder<STATE>& SetResponseStatusCode(int value) {
      result_->SetResponseStatusCode(value);
      return *this;
    }

    RequestPausedParamsBuilder<STATE>& SetResponseHeaders(std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>> value) {
      result_->SetResponseHeaders(std::move(value));
      return *this;
    }

    RequestPausedParamsBuilder<STATE>& SetNetworkId(const std::string& value) {
      result_->SetNetworkId(value);
      return *this;
    }

    std::unique_ptr<RequestPausedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestPausedParams;
    RequestPausedParamsBuilder() : result_(new RequestPausedParams()) { }

    template<int STEP> RequestPausedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestPausedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestPausedParams> result_;
  };

  static RequestPausedParamsBuilder<0> Builder() {
    return RequestPausedParamsBuilder<0>();
  }

 private:
  RequestPausedParams() { }

  std::string request_id_;
  std::unique_ptr<::headless::network::Request> request_;
  std::string frame_id_;
  ::headless::network::ResourceType resource_type_;
  base::Optional<::headless::network::ErrorReason> response_error_reason_;
  base::Optional<int> response_status_code_;
  base::Optional<std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>> response_headers_;
  base::Optional<std::string> network_id_;

  DISALLOW_COPY_AND_ASSIGN(RequestPausedParams);
};


// Parameters for the AuthRequired event.
class HEADLESS_EXPORT AuthRequiredParams {
 public:
  static std::unique_ptr<AuthRequiredParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AuthRequiredParams() { }

  // Each request the page makes will have a unique id.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // The details of the request.
  const ::headless::network::Request* GetRequest() const { return request_.get(); }
  void SetRequest(std::unique_ptr<::headless::network::Request> value) { request_ = std::move(value); }

  // The id of the frame that initiated the request.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // How the requested resource will be used.
  ::headless::network::ResourceType GetResourceType() const { return resource_type_; }
  void SetResourceType(::headless::network::ResourceType value) { resource_type_ = value; }

  // Details of the Authorization Challenge encountered.
  // If this is set, client should respond with continueRequest that
  // contains AuthChallengeResponse.
  const ::headless::fetch::AuthChallenge* GetAuthChallenge() const { return auth_challenge_.get(); }
  void SetAuthChallenge(std::unique_ptr<::headless::fetch::AuthChallenge> value) { auth_challenge_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AuthRequiredParams> Clone() const;

  template<int STATE>
  class AuthRequiredParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kRequestSet = 1 << 2,
    kFrameIdSet = 1 << 3,
    kResourceTypeSet = 1 << 4,
    kAuthChallengeSet = 1 << 5,
      kAllRequiredFieldsSet = (kRequestIdSet | kRequestSet | kFrameIdSet | kResourceTypeSet | kAuthChallengeSet | 0)
    };

    AuthRequiredParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    AuthRequiredParamsBuilder<STATE | kRequestSet>& SetRequest(std::unique_ptr<::headless::network::Request> value) {
      static_assert(!(STATE & kRequestSet), "property request should not have already been set");
      result_->SetRequest(std::move(value));
      return CastState<kRequestSet>();
    }

    AuthRequiredParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    AuthRequiredParamsBuilder<STATE | kResourceTypeSet>& SetResourceType(::headless::network::ResourceType value) {
      static_assert(!(STATE & kResourceTypeSet), "property resourceType should not have already been set");
      result_->SetResourceType(value);
      return CastState<kResourceTypeSet>();
    }

    AuthRequiredParamsBuilder<STATE | kAuthChallengeSet>& SetAuthChallenge(std::unique_ptr<::headless::fetch::AuthChallenge> value) {
      static_assert(!(STATE & kAuthChallengeSet), "property authChallenge should not have already been set");
      result_->SetAuthChallenge(std::move(value));
      return CastState<kAuthChallengeSet>();
    }

    std::unique_ptr<AuthRequiredParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AuthRequiredParams;
    AuthRequiredParamsBuilder() : result_(new AuthRequiredParams()) { }

    template<int STEP> AuthRequiredParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AuthRequiredParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AuthRequiredParams> result_;
  };

  static AuthRequiredParamsBuilder<0> Builder() {
    return AuthRequiredParamsBuilder<0>();
  }

 private:
  AuthRequiredParams() { }

  std::string request_id_;
  std::unique_ptr<::headless::network::Request> request_;
  std::string frame_id_;
  ::headless::network::ResourceType resource_type_;
  std::unique_ptr<::headless::fetch::AuthChallenge> auth_challenge_;

  DISALLOW_COPY_AND_ASSIGN(AuthRequiredParams);
};


}  // namespace fetch

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_FETCH_H_
