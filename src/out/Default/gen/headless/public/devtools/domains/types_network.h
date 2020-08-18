// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_NETWORK_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_NETWORK_H_

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

namespace network {

// Timing information for the request.
class HEADLESS_EXPORT ResourceTiming {
 public:
  static std::unique_ptr<ResourceTiming> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResourceTiming() { }

  // Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
  // milliseconds relatively to this requestTime.
  double GetRequestTime() const { return request_time_; }
  void SetRequestTime(double value) { request_time_ = value; }

  // Started resolving proxy.
  double GetProxyStart() const { return proxy_start_; }
  void SetProxyStart(double value) { proxy_start_ = value; }

  // Finished resolving proxy.
  double GetProxyEnd() const { return proxy_end_; }
  void SetProxyEnd(double value) { proxy_end_ = value; }

  // Started DNS address resolve.
  double GetDnsStart() const { return dns_start_; }
  void SetDnsStart(double value) { dns_start_ = value; }

  // Finished DNS address resolve.
  double GetDnsEnd() const { return dns_end_; }
  void SetDnsEnd(double value) { dns_end_ = value; }

  // Started connecting to the remote host.
  double GetConnectStart() const { return connect_start_; }
  void SetConnectStart(double value) { connect_start_ = value; }

  // Connected to the remote host.
  double GetConnectEnd() const { return connect_end_; }
  void SetConnectEnd(double value) { connect_end_ = value; }

  // Started SSL handshake.
  double GetSslStart() const { return ssl_start_; }
  void SetSslStart(double value) { ssl_start_ = value; }

  // Finished SSL handshake.
  double GetSslEnd() const { return ssl_end_; }
  void SetSslEnd(double value) { ssl_end_ = value; }

  // Started running ServiceWorker.
  double GetWorkerStart() const { return worker_start_; }
  void SetWorkerStart(double value) { worker_start_ = value; }

  // Finished Starting ServiceWorker.
  double GetWorkerReady() const { return worker_ready_; }
  void SetWorkerReady(double value) { worker_ready_ = value; }

  // Started fetch event.
  double GetWorkerFetchStart() const { return worker_fetch_start_; }
  void SetWorkerFetchStart(double value) { worker_fetch_start_ = value; }

  // Settled fetch event respondWith promise.
  double GetWorkerRespondWithSettled() const { return worker_respond_with_settled_; }
  void SetWorkerRespondWithSettled(double value) { worker_respond_with_settled_ = value; }

  // Started sending request.
  double GetSendStart() const { return send_start_; }
  void SetSendStart(double value) { send_start_ = value; }

  // Finished sending request.
  double GetSendEnd() const { return send_end_; }
  void SetSendEnd(double value) { send_end_ = value; }

  // Time the server started pushing request.
  double GetPushStart() const { return push_start_; }
  void SetPushStart(double value) { push_start_ = value; }

  // Time the server finished pushing request.
  double GetPushEnd() const { return push_end_; }
  void SetPushEnd(double value) { push_end_ = value; }

  // Finished receiving response headers.
  double GetReceiveHeadersEnd() const { return receive_headers_end_; }
  void SetReceiveHeadersEnd(double value) { receive_headers_end_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResourceTiming> Clone() const;

  template<int STATE>
  class ResourceTimingBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestTimeSet = 1 << 1,
    kProxyStartSet = 1 << 2,
    kProxyEndSet = 1 << 3,
    kDnsStartSet = 1 << 4,
    kDnsEndSet = 1 << 5,
    kConnectStartSet = 1 << 6,
    kConnectEndSet = 1 << 7,
    kSslStartSet = 1 << 8,
    kSslEndSet = 1 << 9,
    kWorkerStartSet = 1 << 10,
    kWorkerReadySet = 1 << 11,
    kWorkerFetchStartSet = 1 << 12,
    kWorkerRespondWithSettledSet = 1 << 13,
    kSendStartSet = 1 << 14,
    kSendEndSet = 1 << 15,
    kPushStartSet = 1 << 16,
    kPushEndSet = 1 << 17,
    kReceiveHeadersEndSet = 1 << 18,
      kAllRequiredFieldsSet = (kRequestTimeSet | kProxyStartSet | kProxyEndSet | kDnsStartSet | kDnsEndSet | kConnectStartSet | kConnectEndSet | kSslStartSet | kSslEndSet | kWorkerStartSet | kWorkerReadySet | kWorkerFetchStartSet | kWorkerRespondWithSettledSet | kSendStartSet | kSendEndSet | kPushStartSet | kPushEndSet | kReceiveHeadersEndSet | 0)
    };

    ResourceTimingBuilder<STATE | kRequestTimeSet>& SetRequestTime(double value) {
      static_assert(!(STATE & kRequestTimeSet), "property requestTime should not have already been set");
      result_->SetRequestTime(value);
      return CastState<kRequestTimeSet>();
    }

    ResourceTimingBuilder<STATE | kProxyStartSet>& SetProxyStart(double value) {
      static_assert(!(STATE & kProxyStartSet), "property proxyStart should not have already been set");
      result_->SetProxyStart(value);
      return CastState<kProxyStartSet>();
    }

    ResourceTimingBuilder<STATE | kProxyEndSet>& SetProxyEnd(double value) {
      static_assert(!(STATE & kProxyEndSet), "property proxyEnd should not have already been set");
      result_->SetProxyEnd(value);
      return CastState<kProxyEndSet>();
    }

    ResourceTimingBuilder<STATE | kDnsStartSet>& SetDnsStart(double value) {
      static_assert(!(STATE & kDnsStartSet), "property dnsStart should not have already been set");
      result_->SetDnsStart(value);
      return CastState<kDnsStartSet>();
    }

    ResourceTimingBuilder<STATE | kDnsEndSet>& SetDnsEnd(double value) {
      static_assert(!(STATE & kDnsEndSet), "property dnsEnd should not have already been set");
      result_->SetDnsEnd(value);
      return CastState<kDnsEndSet>();
    }

    ResourceTimingBuilder<STATE | kConnectStartSet>& SetConnectStart(double value) {
      static_assert(!(STATE & kConnectStartSet), "property connectStart should not have already been set");
      result_->SetConnectStart(value);
      return CastState<kConnectStartSet>();
    }

    ResourceTimingBuilder<STATE | kConnectEndSet>& SetConnectEnd(double value) {
      static_assert(!(STATE & kConnectEndSet), "property connectEnd should not have already been set");
      result_->SetConnectEnd(value);
      return CastState<kConnectEndSet>();
    }

    ResourceTimingBuilder<STATE | kSslStartSet>& SetSslStart(double value) {
      static_assert(!(STATE & kSslStartSet), "property sslStart should not have already been set");
      result_->SetSslStart(value);
      return CastState<kSslStartSet>();
    }

    ResourceTimingBuilder<STATE | kSslEndSet>& SetSslEnd(double value) {
      static_assert(!(STATE & kSslEndSet), "property sslEnd should not have already been set");
      result_->SetSslEnd(value);
      return CastState<kSslEndSet>();
    }

    ResourceTimingBuilder<STATE | kWorkerStartSet>& SetWorkerStart(double value) {
      static_assert(!(STATE & kWorkerStartSet), "property workerStart should not have already been set");
      result_->SetWorkerStart(value);
      return CastState<kWorkerStartSet>();
    }

    ResourceTimingBuilder<STATE | kWorkerReadySet>& SetWorkerReady(double value) {
      static_assert(!(STATE & kWorkerReadySet), "property workerReady should not have already been set");
      result_->SetWorkerReady(value);
      return CastState<kWorkerReadySet>();
    }

    ResourceTimingBuilder<STATE | kWorkerFetchStartSet>& SetWorkerFetchStart(double value) {
      static_assert(!(STATE & kWorkerFetchStartSet), "property workerFetchStart should not have already been set");
      result_->SetWorkerFetchStart(value);
      return CastState<kWorkerFetchStartSet>();
    }

    ResourceTimingBuilder<STATE | kWorkerRespondWithSettledSet>& SetWorkerRespondWithSettled(double value) {
      static_assert(!(STATE & kWorkerRespondWithSettledSet), "property workerRespondWithSettled should not have already been set");
      result_->SetWorkerRespondWithSettled(value);
      return CastState<kWorkerRespondWithSettledSet>();
    }

    ResourceTimingBuilder<STATE | kSendStartSet>& SetSendStart(double value) {
      static_assert(!(STATE & kSendStartSet), "property sendStart should not have already been set");
      result_->SetSendStart(value);
      return CastState<kSendStartSet>();
    }

    ResourceTimingBuilder<STATE | kSendEndSet>& SetSendEnd(double value) {
      static_assert(!(STATE & kSendEndSet), "property sendEnd should not have already been set");
      result_->SetSendEnd(value);
      return CastState<kSendEndSet>();
    }

    ResourceTimingBuilder<STATE | kPushStartSet>& SetPushStart(double value) {
      static_assert(!(STATE & kPushStartSet), "property pushStart should not have already been set");
      result_->SetPushStart(value);
      return CastState<kPushStartSet>();
    }

    ResourceTimingBuilder<STATE | kPushEndSet>& SetPushEnd(double value) {
      static_assert(!(STATE & kPushEndSet), "property pushEnd should not have already been set");
      result_->SetPushEnd(value);
      return CastState<kPushEndSet>();
    }

    ResourceTimingBuilder<STATE | kReceiveHeadersEndSet>& SetReceiveHeadersEnd(double value) {
      static_assert(!(STATE & kReceiveHeadersEndSet), "property receiveHeadersEnd should not have already been set");
      result_->SetReceiveHeadersEnd(value);
      return CastState<kReceiveHeadersEndSet>();
    }

    std::unique_ptr<ResourceTiming> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResourceTiming;
    ResourceTimingBuilder() : result_(new ResourceTiming()) { }

    template<int STEP> ResourceTimingBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResourceTimingBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResourceTiming> result_;
  };

  static ResourceTimingBuilder<0> Builder() {
    return ResourceTimingBuilder<0>();
  }

 private:
  ResourceTiming() { }

  double request_time_;
  double proxy_start_;
  double proxy_end_;
  double dns_start_;
  double dns_end_;
  double connect_start_;
  double connect_end_;
  double ssl_start_;
  double ssl_end_;
  double worker_start_;
  double worker_ready_;
  double worker_fetch_start_;
  double worker_respond_with_settled_;
  double send_start_;
  double send_end_;
  double push_start_;
  double push_end_;
  double receive_headers_end_;

  DISALLOW_COPY_AND_ASSIGN(ResourceTiming);
};


// HTTP request data.
class HEADLESS_EXPORT Request {
 public:
  static std::unique_ptr<Request> Parse(const base::Value& value, ErrorReporter* errors);
  ~Request() { }

  // Request URL (without fragment).
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Fragment of the requested URL starting with hash, if present.
  bool HasUrlFragment() const { return !!url_fragment_; }
  std::string GetUrlFragment() const { DCHECK(HasUrlFragment()); return url_fragment_.value(); }
  void SetUrlFragment(const std::string& value) { url_fragment_ = value; }

  // HTTP request method.
  std::string GetMethod() const { return method_; }
  void SetMethod(const std::string& value) { method_ = value; }

  // HTTP request headers.
  const base::DictionaryValue* GetHeaders() const { return headers_.get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  // HTTP POST request data.
  bool HasPostData() const { return !!post_data_; }
  std::string GetPostData() const { DCHECK(HasPostData()); return post_data_.value(); }
  void SetPostData(const std::string& value) { post_data_ = value; }

  // True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long.
  bool HasHasPostData() const { return !!has_post_data_; }
  bool GetHasPostData() const { DCHECK(HasHasPostData()); return has_post_data_.value(); }
  void SetHasPostData(bool value) { has_post_data_ = value; }

  // The mixed content type of the request.
  bool HasMixedContentType() const { return !!mixed_content_type_; }
  ::headless::security::MixedContentType GetMixedContentType() const { DCHECK(HasMixedContentType()); return mixed_content_type_.value(); }
  void SetMixedContentType(::headless::security::MixedContentType value) { mixed_content_type_ = value; }

  // Priority of the resource request at the time request is sent.
  ::headless::network::ResourcePriority GetInitialPriority() const { return initial_priority_; }
  void SetInitialPriority(::headless::network::ResourcePriority value) { initial_priority_ = value; }

  // The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/
  ::headless::network::RequestReferrerPolicy GetReferrerPolicy() const { return referrer_policy_; }
  void SetReferrerPolicy(::headless::network::RequestReferrerPolicy value) { referrer_policy_ = value; }

  // Whether is loaded via link preload.
  bool HasIsLinkPreload() const { return !!is_link_preload_; }
  bool GetIsLinkPreload() const { DCHECK(HasIsLinkPreload()); return is_link_preload_.value(); }
  void SetIsLinkPreload(bool value) { is_link_preload_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Request> Clone() const;

  template<int STATE>
  class RequestBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kMethodSet = 1 << 2,
    kHeadersSet = 1 << 3,
    kInitialPrioritySet = 1 << 4,
    kReferrerPolicySet = 1 << 5,
      kAllRequiredFieldsSet = (kUrlSet | kMethodSet | kHeadersSet | kInitialPrioritySet | kReferrerPolicySet | 0)
    };

    RequestBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    RequestBuilder<STATE>& SetUrlFragment(const std::string& value) {
      result_->SetUrlFragment(value);
      return *this;
    }

    RequestBuilder<STATE | kMethodSet>& SetMethod(const std::string& value) {
      static_assert(!(STATE & kMethodSet), "property method should not have already been set");
      result_->SetMethod(value);
      return CastState<kMethodSet>();
    }

    RequestBuilder<STATE | kHeadersSet>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kHeadersSet), "property headers should not have already been set");
      result_->SetHeaders(std::move(value));
      return CastState<kHeadersSet>();
    }

    RequestBuilder<STATE>& SetPostData(const std::string& value) {
      result_->SetPostData(value);
      return *this;
    }

    RequestBuilder<STATE>& SetHasPostData(bool value) {
      result_->SetHasPostData(value);
      return *this;
    }

    RequestBuilder<STATE>& SetMixedContentType(::headless::security::MixedContentType value) {
      result_->SetMixedContentType(value);
      return *this;
    }

    RequestBuilder<STATE | kInitialPrioritySet>& SetInitialPriority(::headless::network::ResourcePriority value) {
      static_assert(!(STATE & kInitialPrioritySet), "property initialPriority should not have already been set");
      result_->SetInitialPriority(value);
      return CastState<kInitialPrioritySet>();
    }

    RequestBuilder<STATE | kReferrerPolicySet>& SetReferrerPolicy(::headless::network::RequestReferrerPolicy value) {
      static_assert(!(STATE & kReferrerPolicySet), "property referrerPolicy should not have already been set");
      result_->SetReferrerPolicy(value);
      return CastState<kReferrerPolicySet>();
    }

    RequestBuilder<STATE>& SetIsLinkPreload(bool value) {
      result_->SetIsLinkPreload(value);
      return *this;
    }

    std::unique_ptr<Request> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Request;
    RequestBuilder() : result_(new Request()) { }

    template<int STEP> RequestBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Request> result_;
  };

  static RequestBuilder<0> Builder() {
    return RequestBuilder<0>();
  }

 private:
  Request() { }

  std::string url_;
  base::Optional<std::string> url_fragment_;
  std::string method_;
  std::unique_ptr<base::DictionaryValue> headers_;
  base::Optional<std::string> post_data_;
  base::Optional<bool> has_post_data_;
  base::Optional<::headless::security::MixedContentType> mixed_content_type_;
  ::headless::network::ResourcePriority initial_priority_;
  ::headless::network::RequestReferrerPolicy referrer_policy_;
  base::Optional<bool> is_link_preload_;

  DISALLOW_COPY_AND_ASSIGN(Request);
};


// Details of a signed certificate timestamp (SCT).
class HEADLESS_EXPORT SignedCertificateTimestamp {
 public:
  static std::unique_ptr<SignedCertificateTimestamp> Parse(const base::Value& value, ErrorReporter* errors);
  ~SignedCertificateTimestamp() { }

  // Validation status.
  std::string GetStatus() const { return status_; }
  void SetStatus(const std::string& value) { status_ = value; }

  // Origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  // Log name / description.
  std::string GetLogDescription() const { return log_description_; }
  void SetLogDescription(const std::string& value) { log_description_ = value; }

  // Log ID.
  std::string GetLogId() const { return log_id_; }
  void SetLogId(const std::string& value) { log_id_ = value; }

  // Issuance date.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Hash algorithm.
  std::string GetHashAlgorithm() const { return hash_algorithm_; }
  void SetHashAlgorithm(const std::string& value) { hash_algorithm_ = value; }

  // Signature algorithm.
  std::string GetSignatureAlgorithm() const { return signature_algorithm_; }
  void SetSignatureAlgorithm(const std::string& value) { signature_algorithm_ = value; }

  // Signature data.
  std::string GetSignatureData() const { return signature_data_; }
  void SetSignatureData(const std::string& value) { signature_data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SignedCertificateTimestamp> Clone() const;

  template<int STATE>
  class SignedCertificateTimestampBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStatusSet = 1 << 1,
    kOriginSet = 1 << 2,
    kLogDescriptionSet = 1 << 3,
    kLogIdSet = 1 << 4,
    kTimestampSet = 1 << 5,
    kHashAlgorithmSet = 1 << 6,
    kSignatureAlgorithmSet = 1 << 7,
    kSignatureDataSet = 1 << 8,
      kAllRequiredFieldsSet = (kStatusSet | kOriginSet | kLogDescriptionSet | kLogIdSet | kTimestampSet | kHashAlgorithmSet | kSignatureAlgorithmSet | kSignatureDataSet | 0)
    };

    SignedCertificateTimestampBuilder<STATE | kStatusSet>& SetStatus(const std::string& value) {
      static_assert(!(STATE & kStatusSet), "property status should not have already been set");
      result_->SetStatus(value);
      return CastState<kStatusSet>();
    }

    SignedCertificateTimestampBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    SignedCertificateTimestampBuilder<STATE | kLogDescriptionSet>& SetLogDescription(const std::string& value) {
      static_assert(!(STATE & kLogDescriptionSet), "property logDescription should not have already been set");
      result_->SetLogDescription(value);
      return CastState<kLogDescriptionSet>();
    }

    SignedCertificateTimestampBuilder<STATE | kLogIdSet>& SetLogId(const std::string& value) {
      static_assert(!(STATE & kLogIdSet), "property logId should not have already been set");
      result_->SetLogId(value);
      return CastState<kLogIdSet>();
    }

    SignedCertificateTimestampBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    SignedCertificateTimestampBuilder<STATE | kHashAlgorithmSet>& SetHashAlgorithm(const std::string& value) {
      static_assert(!(STATE & kHashAlgorithmSet), "property hashAlgorithm should not have already been set");
      result_->SetHashAlgorithm(value);
      return CastState<kHashAlgorithmSet>();
    }

    SignedCertificateTimestampBuilder<STATE | kSignatureAlgorithmSet>& SetSignatureAlgorithm(const std::string& value) {
      static_assert(!(STATE & kSignatureAlgorithmSet), "property signatureAlgorithm should not have already been set");
      result_->SetSignatureAlgorithm(value);
      return CastState<kSignatureAlgorithmSet>();
    }

    SignedCertificateTimestampBuilder<STATE | kSignatureDataSet>& SetSignatureData(const std::string& value) {
      static_assert(!(STATE & kSignatureDataSet), "property signatureData should not have already been set");
      result_->SetSignatureData(value);
      return CastState<kSignatureDataSet>();
    }

    std::unique_ptr<SignedCertificateTimestamp> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SignedCertificateTimestamp;
    SignedCertificateTimestampBuilder() : result_(new SignedCertificateTimestamp()) { }

    template<int STEP> SignedCertificateTimestampBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SignedCertificateTimestampBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SignedCertificateTimestamp> result_;
  };

  static SignedCertificateTimestampBuilder<0> Builder() {
    return SignedCertificateTimestampBuilder<0>();
  }

 private:
  SignedCertificateTimestamp() { }

  std::string status_;
  std::string origin_;
  std::string log_description_;
  std::string log_id_;
  double timestamp_;
  std::string hash_algorithm_;
  std::string signature_algorithm_;
  std::string signature_data_;

  DISALLOW_COPY_AND_ASSIGN(SignedCertificateTimestamp);
};


// Security details about a request.
class HEADLESS_EXPORT SecurityDetails {
 public:
  static std::unique_ptr<SecurityDetails> Parse(const base::Value& value, ErrorReporter* errors);
  ~SecurityDetails() { }

  // Protocol name (e.g. "TLS 1.2" or "QUIC").
  std::string GetProtocol() const { return protocol_; }
  void SetProtocol(const std::string& value) { protocol_ = value; }

  // Key Exchange used by the connection, or the empty string if not applicable.
  std::string GetKeyExchange() const { return key_exchange_; }
  void SetKeyExchange(const std::string& value) { key_exchange_ = value; }

  // (EC)DH group used by the connection, if applicable.
  bool HasKeyExchangeGroup() const { return !!key_exchange_group_; }
  std::string GetKeyExchangeGroup() const { DCHECK(HasKeyExchangeGroup()); return key_exchange_group_.value(); }
  void SetKeyExchangeGroup(const std::string& value) { key_exchange_group_ = value; }

  // Cipher name.
  std::string GetCipher() const { return cipher_; }
  void SetCipher(const std::string& value) { cipher_ = value; }

  // TLS MAC. Note that AEAD ciphers do not have separate MACs.
  bool HasMac() const { return !!mac_; }
  std::string GetMac() const { DCHECK(HasMac()); return mac_.value(); }
  void SetMac(const std::string& value) { mac_ = value; }

  // Certificate ID value.
  int GetCertificateId() const { return certificate_id_; }
  void SetCertificateId(int value) { certificate_id_ = value; }

  // Certificate subject name.
  std::string GetSubjectName() const { return subject_name_; }
  void SetSubjectName(const std::string& value) { subject_name_ = value; }

  // Subject Alternative Name (SAN) DNS names and IP addresses.
  const std::vector<std::string>* GetSanList() const { return &san_list_; }
  void SetSanList(std::vector<std::string> value) { san_list_ = std::move(value); }

  // Name of the issuing CA.
  std::string GetIssuer() const { return issuer_; }
  void SetIssuer(const std::string& value) { issuer_ = value; }

  // Certificate valid from date.
  double GetValidFrom() const { return valid_from_; }
  void SetValidFrom(double value) { valid_from_ = value; }

  // Certificate valid to (expiration) date
  double GetValidTo() const { return valid_to_; }
  void SetValidTo(double value) { valid_to_ = value; }

  // List of signed certificate timestamps (SCTs).
  const std::vector<std::unique_ptr<::headless::network::SignedCertificateTimestamp>>* GetSignedCertificateTimestampList() const { return &signed_certificate_timestamp_list_; }
  void SetSignedCertificateTimestampList(std::vector<std::unique_ptr<::headless::network::SignedCertificateTimestamp>> value) { signed_certificate_timestamp_list_ = std::move(value); }

  // Whether the request complied with Certificate Transparency policy
  ::headless::network::CertificateTransparencyCompliance GetCertificateTransparencyCompliance() const { return certificate_transparency_compliance_; }
  void SetCertificateTransparencyCompliance(::headless::network::CertificateTransparencyCompliance value) { certificate_transparency_compliance_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SecurityDetails> Clone() const;

  template<int STATE>
  class SecurityDetailsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProtocolSet = 1 << 1,
    kKeyExchangeSet = 1 << 2,
    kCipherSet = 1 << 3,
    kCertificateIdSet = 1 << 4,
    kSubjectNameSet = 1 << 5,
    kSanListSet = 1 << 6,
    kIssuerSet = 1 << 7,
    kValidFromSet = 1 << 8,
    kValidToSet = 1 << 9,
    kSignedCertificateTimestampListSet = 1 << 10,
    kCertificateTransparencyComplianceSet = 1 << 11,
      kAllRequiredFieldsSet = (kProtocolSet | kKeyExchangeSet | kCipherSet | kCertificateIdSet | kSubjectNameSet | kSanListSet | kIssuerSet | kValidFromSet | kValidToSet | kSignedCertificateTimestampListSet | kCertificateTransparencyComplianceSet | 0)
    };

    SecurityDetailsBuilder<STATE | kProtocolSet>& SetProtocol(const std::string& value) {
      static_assert(!(STATE & kProtocolSet), "property protocol should not have already been set");
      result_->SetProtocol(value);
      return CastState<kProtocolSet>();
    }

    SecurityDetailsBuilder<STATE | kKeyExchangeSet>& SetKeyExchange(const std::string& value) {
      static_assert(!(STATE & kKeyExchangeSet), "property keyExchange should not have already been set");
      result_->SetKeyExchange(value);
      return CastState<kKeyExchangeSet>();
    }

    SecurityDetailsBuilder<STATE>& SetKeyExchangeGroup(const std::string& value) {
      result_->SetKeyExchangeGroup(value);
      return *this;
    }

    SecurityDetailsBuilder<STATE | kCipherSet>& SetCipher(const std::string& value) {
      static_assert(!(STATE & kCipherSet), "property cipher should not have already been set");
      result_->SetCipher(value);
      return CastState<kCipherSet>();
    }

    SecurityDetailsBuilder<STATE>& SetMac(const std::string& value) {
      result_->SetMac(value);
      return *this;
    }

    SecurityDetailsBuilder<STATE | kCertificateIdSet>& SetCertificateId(int value) {
      static_assert(!(STATE & kCertificateIdSet), "property certificateId should not have already been set");
      result_->SetCertificateId(value);
      return CastState<kCertificateIdSet>();
    }

    SecurityDetailsBuilder<STATE | kSubjectNameSet>& SetSubjectName(const std::string& value) {
      static_assert(!(STATE & kSubjectNameSet), "property subjectName should not have already been set");
      result_->SetSubjectName(value);
      return CastState<kSubjectNameSet>();
    }

    SecurityDetailsBuilder<STATE | kSanListSet>& SetSanList(std::vector<std::string> value) {
      static_assert(!(STATE & kSanListSet), "property sanList should not have already been set");
      result_->SetSanList(std::move(value));
      return CastState<kSanListSet>();
    }

    SecurityDetailsBuilder<STATE | kIssuerSet>& SetIssuer(const std::string& value) {
      static_assert(!(STATE & kIssuerSet), "property issuer should not have already been set");
      result_->SetIssuer(value);
      return CastState<kIssuerSet>();
    }

    SecurityDetailsBuilder<STATE | kValidFromSet>& SetValidFrom(double value) {
      static_assert(!(STATE & kValidFromSet), "property validFrom should not have already been set");
      result_->SetValidFrom(value);
      return CastState<kValidFromSet>();
    }

    SecurityDetailsBuilder<STATE | kValidToSet>& SetValidTo(double value) {
      static_assert(!(STATE & kValidToSet), "property validTo should not have already been set");
      result_->SetValidTo(value);
      return CastState<kValidToSet>();
    }

    SecurityDetailsBuilder<STATE | kSignedCertificateTimestampListSet>& SetSignedCertificateTimestampList(std::vector<std::unique_ptr<::headless::network::SignedCertificateTimestamp>> value) {
      static_assert(!(STATE & kSignedCertificateTimestampListSet), "property signedCertificateTimestampList should not have already been set");
      result_->SetSignedCertificateTimestampList(std::move(value));
      return CastState<kSignedCertificateTimestampListSet>();
    }

    SecurityDetailsBuilder<STATE | kCertificateTransparencyComplianceSet>& SetCertificateTransparencyCompliance(::headless::network::CertificateTransparencyCompliance value) {
      static_assert(!(STATE & kCertificateTransparencyComplianceSet), "property certificateTransparencyCompliance should not have already been set");
      result_->SetCertificateTransparencyCompliance(value);
      return CastState<kCertificateTransparencyComplianceSet>();
    }

    std::unique_ptr<SecurityDetails> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SecurityDetails;
    SecurityDetailsBuilder() : result_(new SecurityDetails()) { }

    template<int STEP> SecurityDetailsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SecurityDetailsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SecurityDetails> result_;
  };

  static SecurityDetailsBuilder<0> Builder() {
    return SecurityDetailsBuilder<0>();
  }

 private:
  SecurityDetails() { }

  std::string protocol_;
  std::string key_exchange_;
  base::Optional<std::string> key_exchange_group_;
  std::string cipher_;
  base::Optional<std::string> mac_;
  int certificate_id_;
  std::string subject_name_;
  std::vector<std::string> san_list_;
  std::string issuer_;
  double valid_from_;
  double valid_to_;
  std::vector<std::unique_ptr<::headless::network::SignedCertificateTimestamp>> signed_certificate_timestamp_list_;
  ::headless::network::CertificateTransparencyCompliance certificate_transparency_compliance_;

  DISALLOW_COPY_AND_ASSIGN(SecurityDetails);
};


// HTTP response data.
class HEADLESS_EXPORT Response {
 public:
  static std::unique_ptr<Response> Parse(const base::Value& value, ErrorReporter* errors);
  ~Response() { }

  // Response URL. This URL can be different from CachedResource.url in case of redirect.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // HTTP response status code.
  int GetStatus() const { return status_; }
  void SetStatus(int value) { status_ = value; }

  // HTTP response status text.
  std::string GetStatusText() const { return status_text_; }
  void SetStatusText(const std::string& value) { status_text_ = value; }

  // HTTP response headers.
  const base::DictionaryValue* GetHeaders() const { return headers_.get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  // HTTP response headers text.
  bool HasHeadersText() const { return !!headers_text_; }
  std::string GetHeadersText() const { DCHECK(HasHeadersText()); return headers_text_.value(); }
  void SetHeadersText(const std::string& value) { headers_text_ = value; }

  // Resource mimeType as determined by the browser.
  std::string GetMimeType() const { return mime_type_; }
  void SetMimeType(const std::string& value) { mime_type_ = value; }

  // Refined HTTP request headers that were actually transmitted over the network.
  bool HasRequestHeaders() const { return !!request_headers_; }
  const base::DictionaryValue* GetRequestHeaders() const { DCHECK(HasRequestHeaders()); return request_headers_.value().get(); }
  void SetRequestHeaders(std::unique_ptr<base::DictionaryValue> value) { request_headers_ = std::move(value); }

  // HTTP request headers text.
  bool HasRequestHeadersText() const { return !!request_headers_text_; }
  std::string GetRequestHeadersText() const { DCHECK(HasRequestHeadersText()); return request_headers_text_.value(); }
  void SetRequestHeadersText(const std::string& value) { request_headers_text_ = value; }

  // Specifies whether physical connection was actually reused for this request.
  bool GetConnectionReused() const { return connection_reused_; }
  void SetConnectionReused(bool value) { connection_reused_ = value; }

  // Physical connection id that was actually used for this request.
  double GetConnectionId() const { return connection_id_; }
  void SetConnectionId(double value) { connection_id_ = value; }

  // Remote IP address.
  bool HasRemoteIPAddress() const { return !!remoteip_address_; }
  std::string GetRemoteIPAddress() const { DCHECK(HasRemoteIPAddress()); return remoteip_address_.value(); }
  void SetRemoteIPAddress(const std::string& value) { remoteip_address_ = value; }

  // Remote port.
  bool HasRemotePort() const { return !!remote_port_; }
  int GetRemotePort() const { DCHECK(HasRemotePort()); return remote_port_.value(); }
  void SetRemotePort(int value) { remote_port_ = value; }

  // Specifies that the request was served from the disk cache.
  bool HasFromDiskCache() const { return !!from_disk_cache_; }
  bool GetFromDiskCache() const { DCHECK(HasFromDiskCache()); return from_disk_cache_.value(); }
  void SetFromDiskCache(bool value) { from_disk_cache_ = value; }

  // Specifies that the request was served from the ServiceWorker.
  bool HasFromServiceWorker() const { return !!from_service_worker_; }
  bool GetFromServiceWorker() const { DCHECK(HasFromServiceWorker()); return from_service_worker_.value(); }
  void SetFromServiceWorker(bool value) { from_service_worker_ = value; }

  // Specifies that the request was served from the prefetch cache.
  bool HasFromPrefetchCache() const { return !!from_prefetch_cache_; }
  bool GetFromPrefetchCache() const { DCHECK(HasFromPrefetchCache()); return from_prefetch_cache_.value(); }
  void SetFromPrefetchCache(bool value) { from_prefetch_cache_ = value; }

  // Total number of bytes received for this request so far.
  double GetEncodedDataLength() const { return encoded_data_length_; }
  void SetEncodedDataLength(double value) { encoded_data_length_ = value; }

  // Timing information for the given request.
  bool HasTiming() const { return !!timing_; }
  const ::headless::network::ResourceTiming* GetTiming() const { DCHECK(HasTiming()); return timing_.value().get(); }
  void SetTiming(std::unique_ptr<::headless::network::ResourceTiming> value) { timing_ = std::move(value); }

  // Response source of response from ServiceWorker.
  bool HasServiceWorkerResponseSource() const { return !!service_worker_response_source_; }
  ::headless::network::ServiceWorkerResponseSource GetServiceWorkerResponseSource() const { DCHECK(HasServiceWorkerResponseSource()); return service_worker_response_source_.value(); }
  void SetServiceWorkerResponseSource(::headless::network::ServiceWorkerResponseSource value) { service_worker_response_source_ = value; }

  // The time at which the returned response was generated.
  bool HasResponseTime() const { return !!response_time_; }
  double GetResponseTime() const { DCHECK(HasResponseTime()); return response_time_.value(); }
  void SetResponseTime(double value) { response_time_ = value; }

  // Cache Storage Cache Name.
  bool HasCacheStorageCacheName() const { return !!cache_storage_cache_name_; }
  std::string GetCacheStorageCacheName() const { DCHECK(HasCacheStorageCacheName()); return cache_storage_cache_name_.value(); }
  void SetCacheStorageCacheName(const std::string& value) { cache_storage_cache_name_ = value; }

  // Protocol used to fetch this request.
  bool HasProtocol() const { return !!protocol_; }
  std::string GetProtocol() const { DCHECK(HasProtocol()); return protocol_.value(); }
  void SetProtocol(const std::string& value) { protocol_ = value; }

  // Security state of the request resource.
  ::headless::security::SecurityState GetSecurityState() const { return security_state_; }
  void SetSecurityState(::headless::security::SecurityState value) { security_state_ = value; }

  // Security details for the request.
  bool HasSecurityDetails() const { return !!security_details_; }
  const ::headless::network::SecurityDetails* GetSecurityDetails() const { DCHECK(HasSecurityDetails()); return security_details_.value().get(); }
  void SetSecurityDetails(std::unique_ptr<::headless::network::SecurityDetails> value) { security_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Response> Clone() const;

  template<int STATE>
  class ResponseBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kStatusSet = 1 << 2,
    kStatusTextSet = 1 << 3,
    kHeadersSet = 1 << 4,
    kMimeTypeSet = 1 << 5,
    kConnectionReusedSet = 1 << 6,
    kConnectionIdSet = 1 << 7,
    kEncodedDataLengthSet = 1 << 8,
    kSecurityStateSet = 1 << 9,
      kAllRequiredFieldsSet = (kUrlSet | kStatusSet | kStatusTextSet | kHeadersSet | kMimeTypeSet | kConnectionReusedSet | kConnectionIdSet | kEncodedDataLengthSet | kSecurityStateSet | 0)
    };

    ResponseBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    ResponseBuilder<STATE | kStatusSet>& SetStatus(int value) {
      static_assert(!(STATE & kStatusSet), "property status should not have already been set");
      result_->SetStatus(value);
      return CastState<kStatusSet>();
    }

    ResponseBuilder<STATE | kStatusTextSet>& SetStatusText(const std::string& value) {
      static_assert(!(STATE & kStatusTextSet), "property statusText should not have already been set");
      result_->SetStatusText(value);
      return CastState<kStatusTextSet>();
    }

    ResponseBuilder<STATE | kHeadersSet>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kHeadersSet), "property headers should not have already been set");
      result_->SetHeaders(std::move(value));
      return CastState<kHeadersSet>();
    }

    ResponseBuilder<STATE>& SetHeadersText(const std::string& value) {
      result_->SetHeadersText(value);
      return *this;
    }

    ResponseBuilder<STATE | kMimeTypeSet>& SetMimeType(const std::string& value) {
      static_assert(!(STATE & kMimeTypeSet), "property mimeType should not have already been set");
      result_->SetMimeType(value);
      return CastState<kMimeTypeSet>();
    }

    ResponseBuilder<STATE>& SetRequestHeaders(std::unique_ptr<base::DictionaryValue> value) {
      result_->SetRequestHeaders(std::move(value));
      return *this;
    }

    ResponseBuilder<STATE>& SetRequestHeadersText(const std::string& value) {
      result_->SetRequestHeadersText(value);
      return *this;
    }

    ResponseBuilder<STATE | kConnectionReusedSet>& SetConnectionReused(bool value) {
      static_assert(!(STATE & kConnectionReusedSet), "property connectionReused should not have already been set");
      result_->SetConnectionReused(value);
      return CastState<kConnectionReusedSet>();
    }

    ResponseBuilder<STATE | kConnectionIdSet>& SetConnectionId(double value) {
      static_assert(!(STATE & kConnectionIdSet), "property connectionId should not have already been set");
      result_->SetConnectionId(value);
      return CastState<kConnectionIdSet>();
    }

    ResponseBuilder<STATE>& SetRemoteIPAddress(const std::string& value) {
      result_->SetRemoteIPAddress(value);
      return *this;
    }

    ResponseBuilder<STATE>& SetRemotePort(int value) {
      result_->SetRemotePort(value);
      return *this;
    }

    ResponseBuilder<STATE>& SetFromDiskCache(bool value) {
      result_->SetFromDiskCache(value);
      return *this;
    }

    ResponseBuilder<STATE>& SetFromServiceWorker(bool value) {
      result_->SetFromServiceWorker(value);
      return *this;
    }

    ResponseBuilder<STATE>& SetFromPrefetchCache(bool value) {
      result_->SetFromPrefetchCache(value);
      return *this;
    }

    ResponseBuilder<STATE | kEncodedDataLengthSet>& SetEncodedDataLength(double value) {
      static_assert(!(STATE & kEncodedDataLengthSet), "property encodedDataLength should not have already been set");
      result_->SetEncodedDataLength(value);
      return CastState<kEncodedDataLengthSet>();
    }

    ResponseBuilder<STATE>& SetTiming(std::unique_ptr<::headless::network::ResourceTiming> value) {
      result_->SetTiming(std::move(value));
      return *this;
    }

    ResponseBuilder<STATE>& SetServiceWorkerResponseSource(::headless::network::ServiceWorkerResponseSource value) {
      result_->SetServiceWorkerResponseSource(value);
      return *this;
    }

    ResponseBuilder<STATE>& SetResponseTime(double value) {
      result_->SetResponseTime(value);
      return *this;
    }

    ResponseBuilder<STATE>& SetCacheStorageCacheName(const std::string& value) {
      result_->SetCacheStorageCacheName(value);
      return *this;
    }

    ResponseBuilder<STATE>& SetProtocol(const std::string& value) {
      result_->SetProtocol(value);
      return *this;
    }

    ResponseBuilder<STATE | kSecurityStateSet>& SetSecurityState(::headless::security::SecurityState value) {
      static_assert(!(STATE & kSecurityStateSet), "property securityState should not have already been set");
      result_->SetSecurityState(value);
      return CastState<kSecurityStateSet>();
    }

    ResponseBuilder<STATE>& SetSecurityDetails(std::unique_ptr<::headless::network::SecurityDetails> value) {
      result_->SetSecurityDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<Response> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Response;
    ResponseBuilder() : result_(new Response()) { }

    template<int STEP> ResponseBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResponseBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Response> result_;
  };

  static ResponseBuilder<0> Builder() {
    return ResponseBuilder<0>();
  }

 private:
  Response() { }

  std::string url_;
  int status_;
  std::string status_text_;
  std::unique_ptr<base::DictionaryValue> headers_;
  base::Optional<std::string> headers_text_;
  std::string mime_type_;
  base::Optional<std::unique_ptr<base::DictionaryValue>> request_headers_;
  base::Optional<std::string> request_headers_text_;
  bool connection_reused_;
  double connection_id_;
  base::Optional<std::string> remoteip_address_;
  base::Optional<int> remote_port_;
  base::Optional<bool> from_disk_cache_;
  base::Optional<bool> from_service_worker_;
  base::Optional<bool> from_prefetch_cache_;
  double encoded_data_length_;
  base::Optional<std::unique_ptr<::headless::network::ResourceTiming>> timing_;
  base::Optional<::headless::network::ServiceWorkerResponseSource> service_worker_response_source_;
  base::Optional<double> response_time_;
  base::Optional<std::string> cache_storage_cache_name_;
  base::Optional<std::string> protocol_;
  ::headless::security::SecurityState security_state_;
  base::Optional<std::unique_ptr<::headless::network::SecurityDetails>> security_details_;

  DISALLOW_COPY_AND_ASSIGN(Response);
};


// WebSocket request data.
class HEADLESS_EXPORT WebSocketRequest {
 public:
  static std::unique_ptr<WebSocketRequest> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketRequest() { }

  // HTTP request headers.
  const base::DictionaryValue* GetHeaders() const { return headers_.get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketRequest> Clone() const;

  template<int STATE>
  class WebSocketRequestBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHeadersSet = 1 << 1,
      kAllRequiredFieldsSet = (kHeadersSet | 0)
    };

    WebSocketRequestBuilder<STATE | kHeadersSet>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kHeadersSet), "property headers should not have already been set");
      result_->SetHeaders(std::move(value));
      return CastState<kHeadersSet>();
    }

    std::unique_ptr<WebSocketRequest> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketRequest;
    WebSocketRequestBuilder() : result_(new WebSocketRequest()) { }

    template<int STEP> WebSocketRequestBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketRequestBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketRequest> result_;
  };

  static WebSocketRequestBuilder<0> Builder() {
    return WebSocketRequestBuilder<0>();
  }

 private:
  WebSocketRequest() { }

  std::unique_ptr<base::DictionaryValue> headers_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketRequest);
};


// WebSocket response data.
class HEADLESS_EXPORT WebSocketResponse {
 public:
  static std::unique_ptr<WebSocketResponse> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketResponse() { }

  // HTTP response status code.
  int GetStatus() const { return status_; }
  void SetStatus(int value) { status_ = value; }

  // HTTP response status text.
  std::string GetStatusText() const { return status_text_; }
  void SetStatusText(const std::string& value) { status_text_ = value; }

  // HTTP response headers.
  const base::DictionaryValue* GetHeaders() const { return headers_.get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  // HTTP response headers text.
  bool HasHeadersText() const { return !!headers_text_; }
  std::string GetHeadersText() const { DCHECK(HasHeadersText()); return headers_text_.value(); }
  void SetHeadersText(const std::string& value) { headers_text_ = value; }

  // HTTP request headers.
  bool HasRequestHeaders() const { return !!request_headers_; }
  const base::DictionaryValue* GetRequestHeaders() const { DCHECK(HasRequestHeaders()); return request_headers_.value().get(); }
  void SetRequestHeaders(std::unique_ptr<base::DictionaryValue> value) { request_headers_ = std::move(value); }

  // HTTP request headers text.
  bool HasRequestHeadersText() const { return !!request_headers_text_; }
  std::string GetRequestHeadersText() const { DCHECK(HasRequestHeadersText()); return request_headers_text_.value(); }
  void SetRequestHeadersText(const std::string& value) { request_headers_text_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketResponse> Clone() const;

  template<int STATE>
  class WebSocketResponseBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStatusSet = 1 << 1,
    kStatusTextSet = 1 << 2,
    kHeadersSet = 1 << 3,
      kAllRequiredFieldsSet = (kStatusSet | kStatusTextSet | kHeadersSet | 0)
    };

    WebSocketResponseBuilder<STATE | kStatusSet>& SetStatus(int value) {
      static_assert(!(STATE & kStatusSet), "property status should not have already been set");
      result_->SetStatus(value);
      return CastState<kStatusSet>();
    }

    WebSocketResponseBuilder<STATE | kStatusTextSet>& SetStatusText(const std::string& value) {
      static_assert(!(STATE & kStatusTextSet), "property statusText should not have already been set");
      result_->SetStatusText(value);
      return CastState<kStatusTextSet>();
    }

    WebSocketResponseBuilder<STATE | kHeadersSet>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kHeadersSet), "property headers should not have already been set");
      result_->SetHeaders(std::move(value));
      return CastState<kHeadersSet>();
    }

    WebSocketResponseBuilder<STATE>& SetHeadersText(const std::string& value) {
      result_->SetHeadersText(value);
      return *this;
    }

    WebSocketResponseBuilder<STATE>& SetRequestHeaders(std::unique_ptr<base::DictionaryValue> value) {
      result_->SetRequestHeaders(std::move(value));
      return *this;
    }

    WebSocketResponseBuilder<STATE>& SetRequestHeadersText(const std::string& value) {
      result_->SetRequestHeadersText(value);
      return *this;
    }

    std::unique_ptr<WebSocketResponse> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketResponse;
    WebSocketResponseBuilder() : result_(new WebSocketResponse()) { }

    template<int STEP> WebSocketResponseBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketResponseBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketResponse> result_;
  };

  static WebSocketResponseBuilder<0> Builder() {
    return WebSocketResponseBuilder<0>();
  }

 private:
  WebSocketResponse() { }

  int status_;
  std::string status_text_;
  std::unique_ptr<base::DictionaryValue> headers_;
  base::Optional<std::string> headers_text_;
  base::Optional<std::unique_ptr<base::DictionaryValue>> request_headers_;
  base::Optional<std::string> request_headers_text_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketResponse);
};


// WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests.
class HEADLESS_EXPORT WebSocketFrame {
 public:
  static std::unique_ptr<WebSocketFrame> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketFrame() { }

  // WebSocket message opcode.
  double GetOpcode() const { return opcode_; }
  void SetOpcode(double value) { opcode_ = value; }

  // WebSocket message mask.
  bool GetMask() const { return mask_; }
  void SetMask(bool value) { mask_ = value; }

  // WebSocket message payload data.
  // If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
  // If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data.
  std::string GetPayloadData() const { return payload_data_; }
  void SetPayloadData(const std::string& value) { payload_data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketFrame> Clone() const;

  template<int STATE>
  class WebSocketFrameBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOpcodeSet = 1 << 1,
    kMaskSet = 1 << 2,
    kPayloadDataSet = 1 << 3,
      kAllRequiredFieldsSet = (kOpcodeSet | kMaskSet | kPayloadDataSet | 0)
    };

    WebSocketFrameBuilder<STATE | kOpcodeSet>& SetOpcode(double value) {
      static_assert(!(STATE & kOpcodeSet), "property opcode should not have already been set");
      result_->SetOpcode(value);
      return CastState<kOpcodeSet>();
    }

    WebSocketFrameBuilder<STATE | kMaskSet>& SetMask(bool value) {
      static_assert(!(STATE & kMaskSet), "property mask should not have already been set");
      result_->SetMask(value);
      return CastState<kMaskSet>();
    }

    WebSocketFrameBuilder<STATE | kPayloadDataSet>& SetPayloadData(const std::string& value) {
      static_assert(!(STATE & kPayloadDataSet), "property payloadData should not have already been set");
      result_->SetPayloadData(value);
      return CastState<kPayloadDataSet>();
    }

    std::unique_ptr<WebSocketFrame> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketFrame;
    WebSocketFrameBuilder() : result_(new WebSocketFrame()) { }

    template<int STEP> WebSocketFrameBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketFrameBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketFrame> result_;
  };

  static WebSocketFrameBuilder<0> Builder() {
    return WebSocketFrameBuilder<0>();
  }

 private:
  WebSocketFrame() { }

  double opcode_;
  bool mask_;
  std::string payload_data_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketFrame);
};


// Information about the cached resource.
class HEADLESS_EXPORT CachedResource {
 public:
  static std::unique_ptr<CachedResource> Parse(const base::Value& value, ErrorReporter* errors);
  ~CachedResource() { }

  // Resource URL. This is the url of the original network request.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Type of this resource.
  ::headless::network::ResourceType GetType() const { return type_; }
  void SetType(::headless::network::ResourceType value) { type_ = value; }

  // Cached response data.
  bool HasResponse() const { return !!response_; }
  const ::headless::network::Response* GetResponse() const { DCHECK(HasResponse()); return response_.value().get(); }
  void SetResponse(std::unique_ptr<::headless::network::Response> value) { response_ = std::move(value); }

  // Cached response body size.
  double GetBodySize() const { return body_size_; }
  void SetBodySize(double value) { body_size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CachedResource> Clone() const;

  template<int STATE>
  class CachedResourceBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kTypeSet = 1 << 2,
    kBodySizeSet = 1 << 3,
      kAllRequiredFieldsSet = (kUrlSet | kTypeSet | kBodySizeSet | 0)
    };

    CachedResourceBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    CachedResourceBuilder<STATE | kTypeSet>& SetType(::headless::network::ResourceType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    CachedResourceBuilder<STATE>& SetResponse(std::unique_ptr<::headless::network::Response> value) {
      result_->SetResponse(std::move(value));
      return *this;
    }

    CachedResourceBuilder<STATE | kBodySizeSet>& SetBodySize(double value) {
      static_assert(!(STATE & kBodySizeSet), "property bodySize should not have already been set");
      result_->SetBodySize(value);
      return CastState<kBodySizeSet>();
    }

    std::unique_ptr<CachedResource> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CachedResource;
    CachedResourceBuilder() : result_(new CachedResource()) { }

    template<int STEP> CachedResourceBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CachedResourceBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CachedResource> result_;
  };

  static CachedResourceBuilder<0> Builder() {
    return CachedResourceBuilder<0>();
  }

 private:
  CachedResource() { }

  std::string url_;
  ::headless::network::ResourceType type_;
  base::Optional<std::unique_ptr<::headless::network::Response>> response_;
  double body_size_;

  DISALLOW_COPY_AND_ASSIGN(CachedResource);
};


// Information about the request initiator.
class HEADLESS_EXPORT Initiator {
 public:
  static std::unique_ptr<Initiator> Parse(const base::Value& value, ErrorReporter* errors);
  ~Initiator() { }

  // Type of this initiator.
  ::headless::network::InitiatorType GetType() const { return type_; }
  void SetType(::headless::network::InitiatorType value) { type_ = value; }

  // Initiator JavaScript stack trace, set for Script only.
  bool HasStack() const { return !!stack_; }
  const ::headless::runtime::StackTrace* GetStack() const { DCHECK(HasStack()); return stack_.value().get(); }
  void SetStack(std::unique_ptr<::headless::runtime::StackTrace> value) { stack_ = std::move(value); }

  // Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // Initiator line number, set for Parser type or for Script type (when script is importing
  // module) (0-based).
  bool HasLineNumber() const { return !!line_number_; }
  double GetLineNumber() const { DCHECK(HasLineNumber()); return line_number_.value(); }
  void SetLineNumber(double value) { line_number_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Initiator> Clone() const;

  template<int STATE>
  class InitiatorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    InitiatorBuilder<STATE | kTypeSet>& SetType(::headless::network::InitiatorType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    InitiatorBuilder<STATE>& SetStack(std::unique_ptr<::headless::runtime::StackTrace> value) {
      result_->SetStack(std::move(value));
      return *this;
    }

    InitiatorBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    InitiatorBuilder<STATE>& SetLineNumber(double value) {
      result_->SetLineNumber(value);
      return *this;
    }

    std::unique_ptr<Initiator> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Initiator;
    InitiatorBuilder() : result_(new Initiator()) { }

    template<int STEP> InitiatorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InitiatorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Initiator> result_;
  };

  static InitiatorBuilder<0> Builder() {
    return InitiatorBuilder<0>();
  }

 private:
  Initiator() { }

  ::headless::network::InitiatorType type_;
  base::Optional<std::unique_ptr<::headless::runtime::StackTrace>> stack_;
  base::Optional<std::string> url_;
  base::Optional<double> line_number_;

  DISALLOW_COPY_AND_ASSIGN(Initiator);
};


// Cookie object
class HEADLESS_EXPORT Cookie {
 public:
  static std::unique_ptr<Cookie> Parse(const base::Value& value, ErrorReporter* errors);
  ~Cookie() { }

  // Cookie name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Cookie value.
  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  // Cookie domain.
  std::string GetDomain() const { return domain_; }
  void SetDomain(const std::string& value) { domain_ = value; }

  // Cookie path.
  std::string GetPath() const { return path_; }
  void SetPath(const std::string& value) { path_ = value; }

  // Cookie expiration date as the number of seconds since the UNIX epoch.
  double GetExpires() const { return expires_; }
  void SetExpires(double value) { expires_ = value; }

  // Cookie size.
  int GetSize() const { return size_; }
  void SetSize(int value) { size_ = value; }

  // True if cookie is http-only.
  bool GetHttpOnly() const { return http_only_; }
  void SetHttpOnly(bool value) { http_only_ = value; }

  // True if cookie is secure.
  bool GetSecure() const { return secure_; }
  void SetSecure(bool value) { secure_ = value; }

  // True in case of session cookie.
  bool GetSession() const { return session_; }
  void SetSession(bool value) { session_ = value; }

  // Cookie SameSite type.
  bool HasSameSite() const { return !!same_site_; }
  ::headless::network::CookieSameSite GetSameSite() const { DCHECK(HasSameSite()); return same_site_.value(); }
  void SetSameSite(::headless::network::CookieSameSite value) { same_site_ = value; }

  // Cookie Priority
  ::headless::network::CookiePriority GetPriority() const { return priority_; }
  void SetPriority(::headless::network::CookiePriority value) { priority_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Cookie> Clone() const;

  template<int STATE>
  class CookieBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
    kDomainSet = 1 << 3,
    kPathSet = 1 << 4,
    kExpiresSet = 1 << 5,
    kSizeSet = 1 << 6,
    kHttpOnlySet = 1 << 7,
    kSecureSet = 1 << 8,
    kSessionSet = 1 << 9,
    kPrioritySet = 1 << 10,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | kDomainSet | kPathSet | kExpiresSet | kSizeSet | kHttpOnlySet | kSecureSet | kSessionSet | kPrioritySet | 0)
    };

    CookieBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    CookieBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    CookieBuilder<STATE | kDomainSet>& SetDomain(const std::string& value) {
      static_assert(!(STATE & kDomainSet), "property domain should not have already been set");
      result_->SetDomain(value);
      return CastState<kDomainSet>();
    }

    CookieBuilder<STATE | kPathSet>& SetPath(const std::string& value) {
      static_assert(!(STATE & kPathSet), "property path should not have already been set");
      result_->SetPath(value);
      return CastState<kPathSet>();
    }

    CookieBuilder<STATE | kExpiresSet>& SetExpires(double value) {
      static_assert(!(STATE & kExpiresSet), "property expires should not have already been set");
      result_->SetExpires(value);
      return CastState<kExpiresSet>();
    }

    CookieBuilder<STATE | kSizeSet>& SetSize(int value) {
      static_assert(!(STATE & kSizeSet), "property size should not have already been set");
      result_->SetSize(value);
      return CastState<kSizeSet>();
    }

    CookieBuilder<STATE | kHttpOnlySet>& SetHttpOnly(bool value) {
      static_assert(!(STATE & kHttpOnlySet), "property httpOnly should not have already been set");
      result_->SetHttpOnly(value);
      return CastState<kHttpOnlySet>();
    }

    CookieBuilder<STATE | kSecureSet>& SetSecure(bool value) {
      static_assert(!(STATE & kSecureSet), "property secure should not have already been set");
      result_->SetSecure(value);
      return CastState<kSecureSet>();
    }

    CookieBuilder<STATE | kSessionSet>& SetSession(bool value) {
      static_assert(!(STATE & kSessionSet), "property session should not have already been set");
      result_->SetSession(value);
      return CastState<kSessionSet>();
    }

    CookieBuilder<STATE>& SetSameSite(::headless::network::CookieSameSite value) {
      result_->SetSameSite(value);
      return *this;
    }

    CookieBuilder<STATE | kPrioritySet>& SetPriority(::headless::network::CookiePriority value) {
      static_assert(!(STATE & kPrioritySet), "property priority should not have already been set");
      result_->SetPriority(value);
      return CastState<kPrioritySet>();
    }

    std::unique_ptr<Cookie> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Cookie;
    CookieBuilder() : result_(new Cookie()) { }

    template<int STEP> CookieBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CookieBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Cookie> result_;
  };

  static CookieBuilder<0> Builder() {
    return CookieBuilder<0>();
  }

 private:
  Cookie() { }

  std::string name_;
  std::string value_;
  std::string domain_;
  std::string path_;
  double expires_;
  int size_;
  bool http_only_;
  bool secure_;
  bool session_;
  base::Optional<::headless::network::CookieSameSite> same_site_;
  ::headless::network::CookiePriority priority_;

  DISALLOW_COPY_AND_ASSIGN(Cookie);
};


// A cookie which was not stored from a response with the corresponding reason.
class HEADLESS_EXPORT BlockedSetCookieWithReason {
 public:
  static std::unique_ptr<BlockedSetCookieWithReason> Parse(const base::Value& value, ErrorReporter* errors);
  ~BlockedSetCookieWithReason() { }

  // The reason(s) this cookie was blocked.
  const std::vector<::headless::network::SetCookieBlockedReason>* GetBlockedReasons() const { return &blocked_reasons_; }
  void SetBlockedReasons(std::vector<::headless::network::SetCookieBlockedReason> value) { blocked_reasons_ = std::move(value); }

  // The string representing this individual cookie as it would appear in the header.
  // This is not the entire "cookie" or "set-cookie" header which could have multiple cookies.
  std::string GetCookieLine() const { return cookie_line_; }
  void SetCookieLine(const std::string& value) { cookie_line_ = value; }

  // The cookie object which represents the cookie which was not stored. It is optional because
  // sometimes complete cookie information is not available, such as in the case of parsing
  // errors.
  bool HasCookie() const { return !!cookie_; }
  const ::headless::network::Cookie* GetCookie() const { DCHECK(HasCookie()); return cookie_.value().get(); }
  void SetCookie(std::unique_ptr<::headless::network::Cookie> value) { cookie_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BlockedSetCookieWithReason> Clone() const;

  template<int STATE>
  class BlockedSetCookieWithReasonBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBlockedReasonsSet = 1 << 1,
    kCookieLineSet = 1 << 2,
      kAllRequiredFieldsSet = (kBlockedReasonsSet | kCookieLineSet | 0)
    };

    BlockedSetCookieWithReasonBuilder<STATE | kBlockedReasonsSet>& SetBlockedReasons(std::vector<::headless::network::SetCookieBlockedReason> value) {
      static_assert(!(STATE & kBlockedReasonsSet), "property blockedReasons should not have already been set");
      result_->SetBlockedReasons(std::move(value));
      return CastState<kBlockedReasonsSet>();
    }

    BlockedSetCookieWithReasonBuilder<STATE | kCookieLineSet>& SetCookieLine(const std::string& value) {
      static_assert(!(STATE & kCookieLineSet), "property cookieLine should not have already been set");
      result_->SetCookieLine(value);
      return CastState<kCookieLineSet>();
    }

    BlockedSetCookieWithReasonBuilder<STATE>& SetCookie(std::unique_ptr<::headless::network::Cookie> value) {
      result_->SetCookie(std::move(value));
      return *this;
    }

    std::unique_ptr<BlockedSetCookieWithReason> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BlockedSetCookieWithReason;
    BlockedSetCookieWithReasonBuilder() : result_(new BlockedSetCookieWithReason()) { }

    template<int STEP> BlockedSetCookieWithReasonBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BlockedSetCookieWithReasonBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BlockedSetCookieWithReason> result_;
  };

  static BlockedSetCookieWithReasonBuilder<0> Builder() {
    return BlockedSetCookieWithReasonBuilder<0>();
  }

 private:
  BlockedSetCookieWithReason() { }

  std::vector<::headless::network::SetCookieBlockedReason> blocked_reasons_;
  std::string cookie_line_;
  base::Optional<std::unique_ptr<::headless::network::Cookie>> cookie_;

  DISALLOW_COPY_AND_ASSIGN(BlockedSetCookieWithReason);
};


// A cookie with was not sent with a request with the corresponding reason.
class HEADLESS_EXPORT BlockedCookieWithReason {
 public:
  static std::unique_ptr<BlockedCookieWithReason> Parse(const base::Value& value, ErrorReporter* errors);
  ~BlockedCookieWithReason() { }

  // The reason(s) the cookie was blocked.
  const std::vector<::headless::network::CookieBlockedReason>* GetBlockedReasons() const { return &blocked_reasons_; }
  void SetBlockedReasons(std::vector<::headless::network::CookieBlockedReason> value) { blocked_reasons_ = std::move(value); }

  // The cookie object representing the cookie which was not sent.
  const ::headless::network::Cookie* GetCookie() const { return cookie_.get(); }
  void SetCookie(std::unique_ptr<::headless::network::Cookie> value) { cookie_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BlockedCookieWithReason> Clone() const;

  template<int STATE>
  class BlockedCookieWithReasonBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBlockedReasonsSet = 1 << 1,
    kCookieSet = 1 << 2,
      kAllRequiredFieldsSet = (kBlockedReasonsSet | kCookieSet | 0)
    };

    BlockedCookieWithReasonBuilder<STATE | kBlockedReasonsSet>& SetBlockedReasons(std::vector<::headless::network::CookieBlockedReason> value) {
      static_assert(!(STATE & kBlockedReasonsSet), "property blockedReasons should not have already been set");
      result_->SetBlockedReasons(std::move(value));
      return CastState<kBlockedReasonsSet>();
    }

    BlockedCookieWithReasonBuilder<STATE | kCookieSet>& SetCookie(std::unique_ptr<::headless::network::Cookie> value) {
      static_assert(!(STATE & kCookieSet), "property cookie should not have already been set");
      result_->SetCookie(std::move(value));
      return CastState<kCookieSet>();
    }

    std::unique_ptr<BlockedCookieWithReason> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BlockedCookieWithReason;
    BlockedCookieWithReasonBuilder() : result_(new BlockedCookieWithReason()) { }

    template<int STEP> BlockedCookieWithReasonBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BlockedCookieWithReasonBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BlockedCookieWithReason> result_;
  };

  static BlockedCookieWithReasonBuilder<0> Builder() {
    return BlockedCookieWithReasonBuilder<0>();
  }

 private:
  BlockedCookieWithReason() { }

  std::vector<::headless::network::CookieBlockedReason> blocked_reasons_;
  std::unique_ptr<::headless::network::Cookie> cookie_;

  DISALLOW_COPY_AND_ASSIGN(BlockedCookieWithReason);
};


// Cookie parameter object
class HEADLESS_EXPORT CookieParam {
 public:
  static std::unique_ptr<CookieParam> Parse(const base::Value& value, ErrorReporter* errors);
  ~CookieParam() { }

  // Cookie name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Cookie value.
  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  // The request-URI to associate with the setting of the cookie. This value can affect the
  // default domain and path values of the created cookie.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // Cookie domain.
  bool HasDomain() const { return !!domain_; }
  std::string GetDomain() const { DCHECK(HasDomain()); return domain_.value(); }
  void SetDomain(const std::string& value) { domain_ = value; }

  // Cookie path.
  bool HasPath() const { return !!path_; }
  std::string GetPath() const { DCHECK(HasPath()); return path_.value(); }
  void SetPath(const std::string& value) { path_ = value; }

  // True if cookie is secure.
  bool HasSecure() const { return !!secure_; }
  bool GetSecure() const { DCHECK(HasSecure()); return secure_.value(); }
  void SetSecure(bool value) { secure_ = value; }

  // True if cookie is http-only.
  bool HasHttpOnly() const { return !!http_only_; }
  bool GetHttpOnly() const { DCHECK(HasHttpOnly()); return http_only_.value(); }
  void SetHttpOnly(bool value) { http_only_ = value; }

  // Cookie SameSite type.
  bool HasSameSite() const { return !!same_site_; }
  ::headless::network::CookieSameSite GetSameSite() const { DCHECK(HasSameSite()); return same_site_.value(); }
  void SetSameSite(::headless::network::CookieSameSite value) { same_site_ = value; }

  // Cookie expiration date, session cookie if not set
  bool HasExpires() const { return !!expires_; }
  double GetExpires() const { DCHECK(HasExpires()); return expires_.value(); }
  void SetExpires(double value) { expires_ = value; }

  // Cookie Priority.
  bool HasPriority() const { return !!priority_; }
  ::headless::network::CookiePriority GetPriority() const { DCHECK(HasPriority()); return priority_.value(); }
  void SetPriority(::headless::network::CookiePriority value) { priority_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CookieParam> Clone() const;

  template<int STATE>
  class CookieParamBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    CookieParamBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    CookieParamBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    CookieParamBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    CookieParamBuilder<STATE>& SetDomain(const std::string& value) {
      result_->SetDomain(value);
      return *this;
    }

    CookieParamBuilder<STATE>& SetPath(const std::string& value) {
      result_->SetPath(value);
      return *this;
    }

    CookieParamBuilder<STATE>& SetSecure(bool value) {
      result_->SetSecure(value);
      return *this;
    }

    CookieParamBuilder<STATE>& SetHttpOnly(bool value) {
      result_->SetHttpOnly(value);
      return *this;
    }

    CookieParamBuilder<STATE>& SetSameSite(::headless::network::CookieSameSite value) {
      result_->SetSameSite(value);
      return *this;
    }

    CookieParamBuilder<STATE>& SetExpires(double value) {
      result_->SetExpires(value);
      return *this;
    }

    CookieParamBuilder<STATE>& SetPriority(::headless::network::CookiePriority value) {
      result_->SetPriority(value);
      return *this;
    }

    std::unique_ptr<CookieParam> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CookieParam;
    CookieParamBuilder() : result_(new CookieParam()) { }

    template<int STEP> CookieParamBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CookieParamBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CookieParam> result_;
  };

  static CookieParamBuilder<0> Builder() {
    return CookieParamBuilder<0>();
  }

 private:
  CookieParam() { }

  std::string name_;
  std::string value_;
  base::Optional<std::string> url_;
  base::Optional<std::string> domain_;
  base::Optional<std::string> path_;
  base::Optional<bool> secure_;
  base::Optional<bool> http_only_;
  base::Optional<::headless::network::CookieSameSite> same_site_;
  base::Optional<double> expires_;
  base::Optional<::headless::network::CookiePriority> priority_;

  DISALLOW_COPY_AND_ASSIGN(CookieParam);
};


// Authorization challenge for HTTP status code 401 or 407.
class HEADLESS_EXPORT AuthChallenge {
 public:
  static std::unique_ptr<AuthChallenge> Parse(const base::Value& value, ErrorReporter* errors);
  ~AuthChallenge() { }

  // Source of the authentication challenge.
  bool HasSource() const { return !!source_; }
  ::headless::network::AuthChallengeSource GetSource() const { DCHECK(HasSource()); return source_.value(); }
  void SetSource(::headless::network::AuthChallengeSource value) { source_ = value; }

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

    AuthChallengeBuilder<STATE>& SetSource(::headless::network::AuthChallengeSource value) {
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

  base::Optional<::headless::network::AuthChallengeSource> source_;
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
  ::headless::network::AuthChallengeResponseResponse GetResponse() const { return response_; }
  void SetResponse(::headless::network::AuthChallengeResponseResponse value) { response_ = value; }

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

    AuthChallengeResponseBuilder<STATE | kResponseSet>& SetResponse(::headless::network::AuthChallengeResponseResponse value) {
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

  ::headless::network::AuthChallengeResponseResponse response_;
  base::Optional<std::string> username_;
  base::Optional<std::string> password_;

  DISALLOW_COPY_AND_ASSIGN(AuthChallengeResponse);
};


// Request pattern for interception.
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
  bool HasInterceptionStage() const { return !!interception_stage_; }
  ::headless::network::InterceptionStage GetInterceptionStage() const { DCHECK(HasInterceptionStage()); return interception_stage_.value(); }
  void SetInterceptionStage(::headless::network::InterceptionStage value) { interception_stage_ = value; }

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

    RequestPatternBuilder<STATE>& SetInterceptionStage(::headless::network::InterceptionStage value) {
      result_->SetInterceptionStage(value);
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
  base::Optional<::headless::network::InterceptionStage> interception_stage_;

  DISALLOW_COPY_AND_ASSIGN(RequestPattern);
};


// Information about a signed exchange signature.
// https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1
class HEADLESS_EXPORT SignedExchangeSignature {
 public:
  static std::unique_ptr<SignedExchangeSignature> Parse(const base::Value& value, ErrorReporter* errors);
  ~SignedExchangeSignature() { }

  // Signed exchange signature label.
  std::string GetLabel() const { return label_; }
  void SetLabel(const std::string& value) { label_ = value; }

  // The hex string of signed exchange signature.
  std::string GetSignature() const { return signature_; }
  void SetSignature(const std::string& value) { signature_ = value; }

  // Signed exchange signature integrity.
  std::string GetIntegrity() const { return integrity_; }
  void SetIntegrity(const std::string& value) { integrity_ = value; }

  // Signed exchange signature cert Url.
  bool HasCertUrl() const { return !!cert_url_; }
  std::string GetCertUrl() const { DCHECK(HasCertUrl()); return cert_url_.value(); }
  void SetCertUrl(const std::string& value) { cert_url_ = value; }

  // The hex string of signed exchange signature cert sha256.
  bool HasCertSha256() const { return !!cert_sha256_; }
  std::string GetCertSha256() const { DCHECK(HasCertSha256()); return cert_sha256_.value(); }
  void SetCertSha256(const std::string& value) { cert_sha256_ = value; }

  // Signed exchange signature validity Url.
  std::string GetValidityUrl() const { return validity_url_; }
  void SetValidityUrl(const std::string& value) { validity_url_ = value; }

  // Signed exchange signature date.
  int GetDate() const { return date_; }
  void SetDate(int value) { date_ = value; }

  // Signed exchange signature expires.
  int GetExpires() const { return expires_; }
  void SetExpires(int value) { expires_ = value; }

  // The encoded certificates.
  bool HasCertificates() const { return !!certificates_; }
  const std::vector<std::string>* GetCertificates() const { DCHECK(HasCertificates()); return &certificates_.value(); }
  void SetCertificates(std::vector<std::string> value) { certificates_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SignedExchangeSignature> Clone() const;

  template<int STATE>
  class SignedExchangeSignatureBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLabelSet = 1 << 1,
    kSignatureSet = 1 << 2,
    kIntegritySet = 1 << 3,
    kValidityUrlSet = 1 << 4,
    kDateSet = 1 << 5,
    kExpiresSet = 1 << 6,
      kAllRequiredFieldsSet = (kLabelSet | kSignatureSet | kIntegritySet | kValidityUrlSet | kDateSet | kExpiresSet | 0)
    };

    SignedExchangeSignatureBuilder<STATE | kLabelSet>& SetLabel(const std::string& value) {
      static_assert(!(STATE & kLabelSet), "property label should not have already been set");
      result_->SetLabel(value);
      return CastState<kLabelSet>();
    }

    SignedExchangeSignatureBuilder<STATE | kSignatureSet>& SetSignature(const std::string& value) {
      static_assert(!(STATE & kSignatureSet), "property signature should not have already been set");
      result_->SetSignature(value);
      return CastState<kSignatureSet>();
    }

    SignedExchangeSignatureBuilder<STATE | kIntegritySet>& SetIntegrity(const std::string& value) {
      static_assert(!(STATE & kIntegritySet), "property integrity should not have already been set");
      result_->SetIntegrity(value);
      return CastState<kIntegritySet>();
    }

    SignedExchangeSignatureBuilder<STATE>& SetCertUrl(const std::string& value) {
      result_->SetCertUrl(value);
      return *this;
    }

    SignedExchangeSignatureBuilder<STATE>& SetCertSha256(const std::string& value) {
      result_->SetCertSha256(value);
      return *this;
    }

    SignedExchangeSignatureBuilder<STATE | kValidityUrlSet>& SetValidityUrl(const std::string& value) {
      static_assert(!(STATE & kValidityUrlSet), "property validityUrl should not have already been set");
      result_->SetValidityUrl(value);
      return CastState<kValidityUrlSet>();
    }

    SignedExchangeSignatureBuilder<STATE | kDateSet>& SetDate(int value) {
      static_assert(!(STATE & kDateSet), "property date should not have already been set");
      result_->SetDate(value);
      return CastState<kDateSet>();
    }

    SignedExchangeSignatureBuilder<STATE | kExpiresSet>& SetExpires(int value) {
      static_assert(!(STATE & kExpiresSet), "property expires should not have already been set");
      result_->SetExpires(value);
      return CastState<kExpiresSet>();
    }

    SignedExchangeSignatureBuilder<STATE>& SetCertificates(std::vector<std::string> value) {
      result_->SetCertificates(std::move(value));
      return *this;
    }

    std::unique_ptr<SignedExchangeSignature> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SignedExchangeSignature;
    SignedExchangeSignatureBuilder() : result_(new SignedExchangeSignature()) { }

    template<int STEP> SignedExchangeSignatureBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SignedExchangeSignatureBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SignedExchangeSignature> result_;
  };

  static SignedExchangeSignatureBuilder<0> Builder() {
    return SignedExchangeSignatureBuilder<0>();
  }

 private:
  SignedExchangeSignature() { }

  std::string label_;
  std::string signature_;
  std::string integrity_;
  base::Optional<std::string> cert_url_;
  base::Optional<std::string> cert_sha256_;
  std::string validity_url_;
  int date_;
  int expires_;
  base::Optional<std::vector<std::string>> certificates_;

  DISALLOW_COPY_AND_ASSIGN(SignedExchangeSignature);
};


// Information about a signed exchange header.
// https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation
class HEADLESS_EXPORT SignedExchangeHeader {
 public:
  static std::unique_ptr<SignedExchangeHeader> Parse(const base::Value& value, ErrorReporter* errors);
  ~SignedExchangeHeader() { }

  // Signed exchange request URL.
  std::string GetRequestUrl() const { return request_url_; }
  void SetRequestUrl(const std::string& value) { request_url_ = value; }

  // Signed exchange response code.
  int GetResponseCode() const { return response_code_; }
  void SetResponseCode(int value) { response_code_ = value; }

  // Signed exchange response headers.
  const base::DictionaryValue* GetResponseHeaders() const { return response_headers_.get(); }
  void SetResponseHeaders(std::unique_ptr<base::DictionaryValue> value) { response_headers_ = std::move(value); }

  // Signed exchange response signature.
  const std::vector<std::unique_ptr<::headless::network::SignedExchangeSignature>>* GetSignatures() const { return &signatures_; }
  void SetSignatures(std::vector<std::unique_ptr<::headless::network::SignedExchangeSignature>> value) { signatures_ = std::move(value); }

  // Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>".
  std::string GetHeaderIntegrity() const { return header_integrity_; }
  void SetHeaderIntegrity(const std::string& value) { header_integrity_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SignedExchangeHeader> Clone() const;

  template<int STATE>
  class SignedExchangeHeaderBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestUrlSet = 1 << 1,
    kResponseCodeSet = 1 << 2,
    kResponseHeadersSet = 1 << 3,
    kSignaturesSet = 1 << 4,
    kHeaderIntegritySet = 1 << 5,
      kAllRequiredFieldsSet = (kRequestUrlSet | kResponseCodeSet | kResponseHeadersSet | kSignaturesSet | kHeaderIntegritySet | 0)
    };

    SignedExchangeHeaderBuilder<STATE | kRequestUrlSet>& SetRequestUrl(const std::string& value) {
      static_assert(!(STATE & kRequestUrlSet), "property requestUrl should not have already been set");
      result_->SetRequestUrl(value);
      return CastState<kRequestUrlSet>();
    }

    SignedExchangeHeaderBuilder<STATE | kResponseCodeSet>& SetResponseCode(int value) {
      static_assert(!(STATE & kResponseCodeSet), "property responseCode should not have already been set");
      result_->SetResponseCode(value);
      return CastState<kResponseCodeSet>();
    }

    SignedExchangeHeaderBuilder<STATE | kResponseHeadersSet>& SetResponseHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kResponseHeadersSet), "property responseHeaders should not have already been set");
      result_->SetResponseHeaders(std::move(value));
      return CastState<kResponseHeadersSet>();
    }

    SignedExchangeHeaderBuilder<STATE | kSignaturesSet>& SetSignatures(std::vector<std::unique_ptr<::headless::network::SignedExchangeSignature>> value) {
      static_assert(!(STATE & kSignaturesSet), "property signatures should not have already been set");
      result_->SetSignatures(std::move(value));
      return CastState<kSignaturesSet>();
    }

    SignedExchangeHeaderBuilder<STATE | kHeaderIntegritySet>& SetHeaderIntegrity(const std::string& value) {
      static_assert(!(STATE & kHeaderIntegritySet), "property headerIntegrity should not have already been set");
      result_->SetHeaderIntegrity(value);
      return CastState<kHeaderIntegritySet>();
    }

    std::unique_ptr<SignedExchangeHeader> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SignedExchangeHeader;
    SignedExchangeHeaderBuilder() : result_(new SignedExchangeHeader()) { }

    template<int STEP> SignedExchangeHeaderBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SignedExchangeHeaderBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SignedExchangeHeader> result_;
  };

  static SignedExchangeHeaderBuilder<0> Builder() {
    return SignedExchangeHeaderBuilder<0>();
  }

 private:
  SignedExchangeHeader() { }

  std::string request_url_;
  int response_code_;
  std::unique_ptr<base::DictionaryValue> response_headers_;
  std::vector<std::unique_ptr<::headless::network::SignedExchangeSignature>> signatures_;
  std::string header_integrity_;

  DISALLOW_COPY_AND_ASSIGN(SignedExchangeHeader);
};


// Information about a signed exchange response.
class HEADLESS_EXPORT SignedExchangeError {
 public:
  static std::unique_ptr<SignedExchangeError> Parse(const base::Value& value, ErrorReporter* errors);
  ~SignedExchangeError() { }

  // Error message.
  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  // The index of the signature which caused the error.
  bool HasSignatureIndex() const { return !!signature_index_; }
  int GetSignatureIndex() const { DCHECK(HasSignatureIndex()); return signature_index_.value(); }
  void SetSignatureIndex(int value) { signature_index_ = value; }

  // The field which caused the error.
  bool HasErrorField() const { return !!error_field_; }
  ::headless::network::SignedExchangeErrorField GetErrorField() const { DCHECK(HasErrorField()); return error_field_.value(); }
  void SetErrorField(::headless::network::SignedExchangeErrorField value) { error_field_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SignedExchangeError> Clone() const;

  template<int STATE>
  class SignedExchangeErrorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMessageSet = 1 << 1,
      kAllRequiredFieldsSet = (kMessageSet | 0)
    };

    SignedExchangeErrorBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    SignedExchangeErrorBuilder<STATE>& SetSignatureIndex(int value) {
      result_->SetSignatureIndex(value);
      return *this;
    }

    SignedExchangeErrorBuilder<STATE>& SetErrorField(::headless::network::SignedExchangeErrorField value) {
      result_->SetErrorField(value);
      return *this;
    }

    std::unique_ptr<SignedExchangeError> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SignedExchangeError;
    SignedExchangeErrorBuilder() : result_(new SignedExchangeError()) { }

    template<int STEP> SignedExchangeErrorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SignedExchangeErrorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SignedExchangeError> result_;
  };

  static SignedExchangeErrorBuilder<0> Builder() {
    return SignedExchangeErrorBuilder<0>();
  }

 private:
  SignedExchangeError() { }

  std::string message_;
  base::Optional<int> signature_index_;
  base::Optional<::headless::network::SignedExchangeErrorField> error_field_;

  DISALLOW_COPY_AND_ASSIGN(SignedExchangeError);
};


// Information about a signed exchange response.
class HEADLESS_EXPORT SignedExchangeInfo {
 public:
  static std::unique_ptr<SignedExchangeInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~SignedExchangeInfo() { }

  // The outer response of signed HTTP exchange which was received from network.
  const ::headless::network::Response* GetOuterResponse() const { return outer_response_.get(); }
  void SetOuterResponse(std::unique_ptr<::headless::network::Response> value) { outer_response_ = std::move(value); }

  // Information about the signed exchange header.
  bool HasHeader() const { return !!header_; }
  const ::headless::network::SignedExchangeHeader* GetHeader() const { DCHECK(HasHeader()); return header_.value().get(); }
  void SetHeader(std::unique_ptr<::headless::network::SignedExchangeHeader> value) { header_ = std::move(value); }

  // Security details for the signed exchange header.
  bool HasSecurityDetails() const { return !!security_details_; }
  const ::headless::network::SecurityDetails* GetSecurityDetails() const { DCHECK(HasSecurityDetails()); return security_details_.value().get(); }
  void SetSecurityDetails(std::unique_ptr<::headless::network::SecurityDetails> value) { security_details_ = std::move(value); }

  // Errors occurred while handling the signed exchagne.
  bool HasErrors() const { return !!errors_; }
  const std::vector<std::unique_ptr<::headless::network::SignedExchangeError>>* GetErrors() const { DCHECK(HasErrors()); return &errors_.value(); }
  void SetErrors(std::vector<std::unique_ptr<::headless::network::SignedExchangeError>> value) { errors_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SignedExchangeInfo> Clone() const;

  template<int STATE>
  class SignedExchangeInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOuterResponseSet = 1 << 1,
      kAllRequiredFieldsSet = (kOuterResponseSet | 0)
    };

    SignedExchangeInfoBuilder<STATE | kOuterResponseSet>& SetOuterResponse(std::unique_ptr<::headless::network::Response> value) {
      static_assert(!(STATE & kOuterResponseSet), "property outerResponse should not have already been set");
      result_->SetOuterResponse(std::move(value));
      return CastState<kOuterResponseSet>();
    }

    SignedExchangeInfoBuilder<STATE>& SetHeader(std::unique_ptr<::headless::network::SignedExchangeHeader> value) {
      result_->SetHeader(std::move(value));
      return *this;
    }

    SignedExchangeInfoBuilder<STATE>& SetSecurityDetails(std::unique_ptr<::headless::network::SecurityDetails> value) {
      result_->SetSecurityDetails(std::move(value));
      return *this;
    }

    SignedExchangeInfoBuilder<STATE>& SetErrors(std::vector<std::unique_ptr<::headless::network::SignedExchangeError>> value) {
      result_->SetErrors(std::move(value));
      return *this;
    }

    std::unique_ptr<SignedExchangeInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SignedExchangeInfo;
    SignedExchangeInfoBuilder() : result_(new SignedExchangeInfo()) { }

    template<int STEP> SignedExchangeInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SignedExchangeInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SignedExchangeInfo> result_;
  };

  static SignedExchangeInfoBuilder<0> Builder() {
    return SignedExchangeInfoBuilder<0>();
  }

 private:
  SignedExchangeInfo() { }

  std::unique_ptr<::headless::network::Response> outer_response_;
  base::Optional<std::unique_ptr<::headless::network::SignedExchangeHeader>> header_;
  base::Optional<std::unique_ptr<::headless::network::SecurityDetails>> security_details_;
  base::Optional<std::vector<std::unique_ptr<::headless::network::SignedExchangeError>>> errors_;

  DISALLOW_COPY_AND_ASSIGN(SignedExchangeInfo);
};


// Parameters for the CanClearBrowserCache command.
class HEADLESS_EXPORT CanClearBrowserCacheParams {
 public:
  static std::unique_ptr<CanClearBrowserCacheParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanClearBrowserCacheParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanClearBrowserCacheParams> Clone() const;

  template<int STATE>
  class CanClearBrowserCacheParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CanClearBrowserCacheParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanClearBrowserCacheParams;
    CanClearBrowserCacheParamsBuilder() : result_(new CanClearBrowserCacheParams()) { }

    template<int STEP> CanClearBrowserCacheParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanClearBrowserCacheParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanClearBrowserCacheParams> result_;
  };

  static CanClearBrowserCacheParamsBuilder<0> Builder() {
    return CanClearBrowserCacheParamsBuilder<0>();
  }

 private:
  CanClearBrowserCacheParams() { }


  DISALLOW_COPY_AND_ASSIGN(CanClearBrowserCacheParams);
};


// Result for the CanClearBrowserCache command.
class HEADLESS_EXPORT CanClearBrowserCacheResult {
 public:
  static std::unique_ptr<CanClearBrowserCacheResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanClearBrowserCacheResult() { }

  // True if browser cache can be cleared.
  bool GetResult() const { return result_; }
  void SetResult(bool value) { result_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanClearBrowserCacheResult> Clone() const;

  template<int STATE>
  class CanClearBrowserCacheResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    CanClearBrowserCacheResultBuilder<STATE | kResultSet>& SetResult(bool value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(value);
      return CastState<kResultSet>();
    }

    std::unique_ptr<CanClearBrowserCacheResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanClearBrowserCacheResult;
    CanClearBrowserCacheResultBuilder() : result_(new CanClearBrowserCacheResult()) { }

    template<int STEP> CanClearBrowserCacheResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanClearBrowserCacheResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanClearBrowserCacheResult> result_;
  };

  static CanClearBrowserCacheResultBuilder<0> Builder() {
    return CanClearBrowserCacheResultBuilder<0>();
  }

 private:
  CanClearBrowserCacheResult() { }

  bool result_;

  DISALLOW_COPY_AND_ASSIGN(CanClearBrowserCacheResult);
};


// Parameters for the CanClearBrowserCookies command.
class HEADLESS_EXPORT CanClearBrowserCookiesParams {
 public:
  static std::unique_ptr<CanClearBrowserCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanClearBrowserCookiesParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanClearBrowserCookiesParams> Clone() const;

  template<int STATE>
  class CanClearBrowserCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CanClearBrowserCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanClearBrowserCookiesParams;
    CanClearBrowserCookiesParamsBuilder() : result_(new CanClearBrowserCookiesParams()) { }

    template<int STEP> CanClearBrowserCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanClearBrowserCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanClearBrowserCookiesParams> result_;
  };

  static CanClearBrowserCookiesParamsBuilder<0> Builder() {
    return CanClearBrowserCookiesParamsBuilder<0>();
  }

 private:
  CanClearBrowserCookiesParams() { }


  DISALLOW_COPY_AND_ASSIGN(CanClearBrowserCookiesParams);
};


// Result for the CanClearBrowserCookies command.
class HEADLESS_EXPORT CanClearBrowserCookiesResult {
 public:
  static std::unique_ptr<CanClearBrowserCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanClearBrowserCookiesResult() { }

  // True if browser cookies can be cleared.
  bool GetResult() const { return result_; }
  void SetResult(bool value) { result_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanClearBrowserCookiesResult> Clone() const;

  template<int STATE>
  class CanClearBrowserCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    CanClearBrowserCookiesResultBuilder<STATE | kResultSet>& SetResult(bool value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(value);
      return CastState<kResultSet>();
    }

    std::unique_ptr<CanClearBrowserCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanClearBrowserCookiesResult;
    CanClearBrowserCookiesResultBuilder() : result_(new CanClearBrowserCookiesResult()) { }

    template<int STEP> CanClearBrowserCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanClearBrowserCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanClearBrowserCookiesResult> result_;
  };

  static CanClearBrowserCookiesResultBuilder<0> Builder() {
    return CanClearBrowserCookiesResultBuilder<0>();
  }

 private:
  CanClearBrowserCookiesResult() { }

  bool result_;

  DISALLOW_COPY_AND_ASSIGN(CanClearBrowserCookiesResult);
};


// Parameters for the CanEmulateNetworkConditions command.
class HEADLESS_EXPORT CanEmulateNetworkConditionsParams {
 public:
  static std::unique_ptr<CanEmulateNetworkConditionsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanEmulateNetworkConditionsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanEmulateNetworkConditionsParams> Clone() const;

  template<int STATE>
  class CanEmulateNetworkConditionsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CanEmulateNetworkConditionsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanEmulateNetworkConditionsParams;
    CanEmulateNetworkConditionsParamsBuilder() : result_(new CanEmulateNetworkConditionsParams()) { }

    template<int STEP> CanEmulateNetworkConditionsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanEmulateNetworkConditionsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanEmulateNetworkConditionsParams> result_;
  };

  static CanEmulateNetworkConditionsParamsBuilder<0> Builder() {
    return CanEmulateNetworkConditionsParamsBuilder<0>();
  }

 private:
  CanEmulateNetworkConditionsParams() { }


  DISALLOW_COPY_AND_ASSIGN(CanEmulateNetworkConditionsParams);
};


// Result for the CanEmulateNetworkConditions command.
class HEADLESS_EXPORT CanEmulateNetworkConditionsResult {
 public:
  static std::unique_ptr<CanEmulateNetworkConditionsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CanEmulateNetworkConditionsResult() { }

  // True if emulation of network conditions is supported.
  bool GetResult() const { return result_; }
  void SetResult(bool value) { result_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CanEmulateNetworkConditionsResult> Clone() const;

  template<int STATE>
  class CanEmulateNetworkConditionsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    CanEmulateNetworkConditionsResultBuilder<STATE | kResultSet>& SetResult(bool value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(value);
      return CastState<kResultSet>();
    }

    std::unique_ptr<CanEmulateNetworkConditionsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CanEmulateNetworkConditionsResult;
    CanEmulateNetworkConditionsResultBuilder() : result_(new CanEmulateNetworkConditionsResult()) { }

    template<int STEP> CanEmulateNetworkConditionsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CanEmulateNetworkConditionsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CanEmulateNetworkConditionsResult> result_;
  };

  static CanEmulateNetworkConditionsResultBuilder<0> Builder() {
    return CanEmulateNetworkConditionsResultBuilder<0>();
  }

 private:
  CanEmulateNetworkConditionsResult() { }

  bool result_;

  DISALLOW_COPY_AND_ASSIGN(CanEmulateNetworkConditionsResult);
};


// Parameters for the ClearBrowserCache command.
class HEADLESS_EXPORT ClearBrowserCacheParams {
 public:
  static std::unique_ptr<ClearBrowserCacheParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearBrowserCacheParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearBrowserCacheParams> Clone() const;

  template<int STATE>
  class ClearBrowserCacheParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearBrowserCacheParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearBrowserCacheParams;
    ClearBrowserCacheParamsBuilder() : result_(new ClearBrowserCacheParams()) { }

    template<int STEP> ClearBrowserCacheParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearBrowserCacheParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearBrowserCacheParams> result_;
  };

  static ClearBrowserCacheParamsBuilder<0> Builder() {
    return ClearBrowserCacheParamsBuilder<0>();
  }

 private:
  ClearBrowserCacheParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearBrowserCacheParams);
};


// Result for the ClearBrowserCache command.
class HEADLESS_EXPORT ClearBrowserCacheResult {
 public:
  static std::unique_ptr<ClearBrowserCacheResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearBrowserCacheResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearBrowserCacheResult> Clone() const;

  template<int STATE>
  class ClearBrowserCacheResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearBrowserCacheResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearBrowserCacheResult;
    ClearBrowserCacheResultBuilder() : result_(new ClearBrowserCacheResult()) { }

    template<int STEP> ClearBrowserCacheResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearBrowserCacheResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearBrowserCacheResult> result_;
  };

  static ClearBrowserCacheResultBuilder<0> Builder() {
    return ClearBrowserCacheResultBuilder<0>();
  }

 private:
  ClearBrowserCacheResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearBrowserCacheResult);
};


// Parameters for the ClearBrowserCookies command.
class HEADLESS_EXPORT ClearBrowserCookiesParams {
 public:
  static std::unique_ptr<ClearBrowserCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearBrowserCookiesParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearBrowserCookiesParams> Clone() const;

  template<int STATE>
  class ClearBrowserCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearBrowserCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearBrowserCookiesParams;
    ClearBrowserCookiesParamsBuilder() : result_(new ClearBrowserCookiesParams()) { }

    template<int STEP> ClearBrowserCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearBrowserCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearBrowserCookiesParams> result_;
  };

  static ClearBrowserCookiesParamsBuilder<0> Builder() {
    return ClearBrowserCookiesParamsBuilder<0>();
  }

 private:
  ClearBrowserCookiesParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearBrowserCookiesParams);
};


// Result for the ClearBrowserCookies command.
class HEADLESS_EXPORT ClearBrowserCookiesResult {
 public:
  static std::unique_ptr<ClearBrowserCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearBrowserCookiesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearBrowserCookiesResult> Clone() const;

  template<int STATE>
  class ClearBrowserCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearBrowserCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearBrowserCookiesResult;
    ClearBrowserCookiesResultBuilder() : result_(new ClearBrowserCookiesResult()) { }

    template<int STEP> ClearBrowserCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearBrowserCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearBrowserCookiesResult> result_;
  };

  static ClearBrowserCookiesResultBuilder<0> Builder() {
    return ClearBrowserCookiesResultBuilder<0>();
  }

 private:
  ClearBrowserCookiesResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearBrowserCookiesResult);
};


// Parameters for the ContinueInterceptedRequest command.
class HEADLESS_EXPORT ContinueInterceptedRequestParams {
 public:
  static std::unique_ptr<ContinueInterceptedRequestParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContinueInterceptedRequestParams() { }

  std::string GetInterceptionId() const { return interception_id_; }
  void SetInterceptionId(const std::string& value) { interception_id_ = value; }

  // If set this causes the request to fail with the given reason. Passing `Aborted` for requests
  // marked with `isNavigationRequest` also cancels the navigation. Must not be set in response
  // to an authChallenge.
  bool HasErrorReason() const { return !!error_reason_; }
  ::headless::network::ErrorReason GetErrorReason() const { DCHECK(HasErrorReason()); return error_reason_.value(); }
  void SetErrorReason(::headless::network::ErrorReason value) { error_reason_ = value; }

  // If set the requests completes using with the provided base64 encoded raw response, including
  // HTTP status line and headers etc... Must not be set in response to an authChallenge.
  bool HasRawResponse() const { return !!raw_response_; }
  protocol::Binary GetRawResponse() const { DCHECK(HasRawResponse()); return raw_response_.value(); }
  void SetRawResponse(const protocol::Binary& value) { raw_response_ = value; }

  // If set the request url will be modified in a way that's not observable by page. Must not be
  // set in response to an authChallenge.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // If set this allows the request method to be overridden. Must not be set in response to an
  // authChallenge.
  bool HasMethod() const { return !!method_; }
  std::string GetMethod() const { DCHECK(HasMethod()); return method_.value(); }
  void SetMethod(const std::string& value) { method_ = value; }

  // If set this allows postData to be set. Must not be set in response to an authChallenge.
  bool HasPostData() const { return !!post_data_; }
  std::string GetPostData() const { DCHECK(HasPostData()); return post_data_.value(); }
  void SetPostData(const std::string& value) { post_data_ = value; }

  // If set this allows the request headers to be changed. Must not be set in response to an
  // authChallenge.
  bool HasHeaders() const { return !!headers_; }
  const base::DictionaryValue* GetHeaders() const { DCHECK(HasHeaders()); return headers_.value().get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  // Response to a requestIntercepted with an authChallenge. Must not be set otherwise.
  bool HasAuthChallengeResponse() const { return !!auth_challenge_response_; }
  const ::headless::network::AuthChallengeResponse* GetAuthChallengeResponse() const { DCHECK(HasAuthChallengeResponse()); return auth_challenge_response_.value().get(); }
  void SetAuthChallengeResponse(std::unique_ptr<::headless::network::AuthChallengeResponse> value) { auth_challenge_response_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContinueInterceptedRequestParams> Clone() const;

  template<int STATE>
  class ContinueInterceptedRequestParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kInterceptionIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kInterceptionIdSet | 0)
    };

    ContinueInterceptedRequestParamsBuilder<STATE | kInterceptionIdSet>& SetInterceptionId(const std::string& value) {
      static_assert(!(STATE & kInterceptionIdSet), "property interceptionId should not have already been set");
      result_->SetInterceptionId(value);
      return CastState<kInterceptionIdSet>();
    }

    ContinueInterceptedRequestParamsBuilder<STATE>& SetErrorReason(::headless::network::ErrorReason value) {
      result_->SetErrorReason(value);
      return *this;
    }

    ContinueInterceptedRequestParamsBuilder<STATE>& SetRawResponse(const protocol::Binary& value) {
      result_->SetRawResponse(value);
      return *this;
    }

    ContinueInterceptedRequestParamsBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    ContinueInterceptedRequestParamsBuilder<STATE>& SetMethod(const std::string& value) {
      result_->SetMethod(value);
      return *this;
    }

    ContinueInterceptedRequestParamsBuilder<STATE>& SetPostData(const std::string& value) {
      result_->SetPostData(value);
      return *this;
    }

    ContinueInterceptedRequestParamsBuilder<STATE>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      result_->SetHeaders(std::move(value));
      return *this;
    }

    ContinueInterceptedRequestParamsBuilder<STATE>& SetAuthChallengeResponse(std::unique_ptr<::headless::network::AuthChallengeResponse> value) {
      result_->SetAuthChallengeResponse(std::move(value));
      return *this;
    }

    std::unique_ptr<ContinueInterceptedRequestParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContinueInterceptedRequestParams;
    ContinueInterceptedRequestParamsBuilder() : result_(new ContinueInterceptedRequestParams()) { }

    template<int STEP> ContinueInterceptedRequestParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContinueInterceptedRequestParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContinueInterceptedRequestParams> result_;
  };

  static ContinueInterceptedRequestParamsBuilder<0> Builder() {
    return ContinueInterceptedRequestParamsBuilder<0>();
  }

 private:
  ContinueInterceptedRequestParams() { }

  std::string interception_id_;
  base::Optional<::headless::network::ErrorReason> error_reason_;
  base::Optional<protocol::Binary> raw_response_;
  base::Optional<std::string> url_;
  base::Optional<std::string> method_;
  base::Optional<std::string> post_data_;
  base::Optional<std::unique_ptr<base::DictionaryValue>> headers_;
  base::Optional<std::unique_ptr<::headless::network::AuthChallengeResponse>> auth_challenge_response_;

  DISALLOW_COPY_AND_ASSIGN(ContinueInterceptedRequestParams);
};


// Result for the ContinueInterceptedRequest command.
class HEADLESS_EXPORT ContinueInterceptedRequestResult {
 public:
  static std::unique_ptr<ContinueInterceptedRequestResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContinueInterceptedRequestResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContinueInterceptedRequestResult> Clone() const;

  template<int STATE>
  class ContinueInterceptedRequestResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ContinueInterceptedRequestResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContinueInterceptedRequestResult;
    ContinueInterceptedRequestResultBuilder() : result_(new ContinueInterceptedRequestResult()) { }

    template<int STEP> ContinueInterceptedRequestResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContinueInterceptedRequestResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContinueInterceptedRequestResult> result_;
  };

  static ContinueInterceptedRequestResultBuilder<0> Builder() {
    return ContinueInterceptedRequestResultBuilder<0>();
  }

 private:
  ContinueInterceptedRequestResult() { }


  DISALLOW_COPY_AND_ASSIGN(ContinueInterceptedRequestResult);
};


// Parameters for the DeleteCookies command.
class HEADLESS_EXPORT DeleteCookiesParams {
 public:
  static std::unique_ptr<DeleteCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteCookiesParams() { }

  // Name of the cookies to remove.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // If specified, deletes all the cookies with the given name where domain and path match
  // provided URL.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // If specified, deletes only cookies with the exact domain.
  bool HasDomain() const { return !!domain_; }
  std::string GetDomain() const { DCHECK(HasDomain()); return domain_.value(); }
  void SetDomain(const std::string& value) { domain_ = value; }

  // If specified, deletes only cookies with the exact path.
  bool HasPath() const { return !!path_; }
  std::string GetPath() const { DCHECK(HasPath()); return path_.value(); }
  void SetPath(const std::string& value) { path_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteCookiesParams> Clone() const;

  template<int STATE>
  class DeleteCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
      kAllRequiredFieldsSet = (kNameSet | 0)
    };

    DeleteCookiesParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    DeleteCookiesParamsBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    DeleteCookiesParamsBuilder<STATE>& SetDomain(const std::string& value) {
      result_->SetDomain(value);
      return *this;
    }

    DeleteCookiesParamsBuilder<STATE>& SetPath(const std::string& value) {
      result_->SetPath(value);
      return *this;
    }

    std::unique_ptr<DeleteCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteCookiesParams;
    DeleteCookiesParamsBuilder() : result_(new DeleteCookiesParams()) { }

    template<int STEP> DeleteCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteCookiesParams> result_;
  };

  static DeleteCookiesParamsBuilder<0> Builder() {
    return DeleteCookiesParamsBuilder<0>();
  }

 private:
  DeleteCookiesParams() { }

  std::string name_;
  base::Optional<std::string> url_;
  base::Optional<std::string> domain_;
  base::Optional<std::string> path_;

  DISALLOW_COPY_AND_ASSIGN(DeleteCookiesParams);
};


// Result for the DeleteCookies command.
class HEADLESS_EXPORT DeleteCookiesResult {
 public:
  static std::unique_ptr<DeleteCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteCookiesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteCookiesResult> Clone() const;

  template<int STATE>
  class DeleteCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DeleteCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteCookiesResult;
    DeleteCookiesResultBuilder() : result_(new DeleteCookiesResult()) { }

    template<int STEP> DeleteCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteCookiesResult> result_;
  };

  static DeleteCookiesResultBuilder<0> Builder() {
    return DeleteCookiesResultBuilder<0>();
  }

 private:
  DeleteCookiesResult() { }


  DISALLOW_COPY_AND_ASSIGN(DeleteCookiesResult);
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


// Parameters for the EmulateNetworkConditions command.
class HEADLESS_EXPORT EmulateNetworkConditionsParams {
 public:
  static std::unique_ptr<EmulateNetworkConditionsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EmulateNetworkConditionsParams() { }

  // True to emulate internet disconnection.
  bool GetOffline() const { return offline_; }
  void SetOffline(bool value) { offline_ = value; }

  // Minimum latency from request sent to response headers received (ms).
  double GetLatency() const { return latency_; }
  void SetLatency(double value) { latency_ = value; }

  // Maximal aggregated download throughput (bytes/sec). -1 disables download throttling.
  double GetDownloadThroughput() const { return download_throughput_; }
  void SetDownloadThroughput(double value) { download_throughput_ = value; }

  // Maximal aggregated upload throughput (bytes/sec).  -1 disables upload throttling.
  double GetUploadThroughput() const { return upload_throughput_; }
  void SetUploadThroughput(double value) { upload_throughput_ = value; }

  // Connection type if known.
  bool HasConnectionType() const { return !!connection_type_; }
  ::headless::network::ConnectionType GetConnectionType() const { DCHECK(HasConnectionType()); return connection_type_.value(); }
  void SetConnectionType(::headless::network::ConnectionType value) { connection_type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EmulateNetworkConditionsParams> Clone() const;

  template<int STATE>
  class EmulateNetworkConditionsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOfflineSet = 1 << 1,
    kLatencySet = 1 << 2,
    kDownloadThroughputSet = 1 << 3,
    kUploadThroughputSet = 1 << 4,
      kAllRequiredFieldsSet = (kOfflineSet | kLatencySet | kDownloadThroughputSet | kUploadThroughputSet | 0)
    };

    EmulateNetworkConditionsParamsBuilder<STATE | kOfflineSet>& SetOffline(bool value) {
      static_assert(!(STATE & kOfflineSet), "property offline should not have already been set");
      result_->SetOffline(value);
      return CastState<kOfflineSet>();
    }

    EmulateNetworkConditionsParamsBuilder<STATE | kLatencySet>& SetLatency(double value) {
      static_assert(!(STATE & kLatencySet), "property latency should not have already been set");
      result_->SetLatency(value);
      return CastState<kLatencySet>();
    }

    EmulateNetworkConditionsParamsBuilder<STATE | kDownloadThroughputSet>& SetDownloadThroughput(double value) {
      static_assert(!(STATE & kDownloadThroughputSet), "property downloadThroughput should not have already been set");
      result_->SetDownloadThroughput(value);
      return CastState<kDownloadThroughputSet>();
    }

    EmulateNetworkConditionsParamsBuilder<STATE | kUploadThroughputSet>& SetUploadThroughput(double value) {
      static_assert(!(STATE & kUploadThroughputSet), "property uploadThroughput should not have already been set");
      result_->SetUploadThroughput(value);
      return CastState<kUploadThroughputSet>();
    }

    EmulateNetworkConditionsParamsBuilder<STATE>& SetConnectionType(::headless::network::ConnectionType value) {
      result_->SetConnectionType(value);
      return *this;
    }

    std::unique_ptr<EmulateNetworkConditionsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EmulateNetworkConditionsParams;
    EmulateNetworkConditionsParamsBuilder() : result_(new EmulateNetworkConditionsParams()) { }

    template<int STEP> EmulateNetworkConditionsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EmulateNetworkConditionsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EmulateNetworkConditionsParams> result_;
  };

  static EmulateNetworkConditionsParamsBuilder<0> Builder() {
    return EmulateNetworkConditionsParamsBuilder<0>();
  }

 private:
  EmulateNetworkConditionsParams() { }

  bool offline_;
  double latency_;
  double download_throughput_;
  double upload_throughput_;
  base::Optional<::headless::network::ConnectionType> connection_type_;

  DISALLOW_COPY_AND_ASSIGN(EmulateNetworkConditionsParams);
};


// Result for the EmulateNetworkConditions command.
class HEADLESS_EXPORT EmulateNetworkConditionsResult {
 public:
  static std::unique_ptr<EmulateNetworkConditionsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EmulateNetworkConditionsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EmulateNetworkConditionsResult> Clone() const;

  template<int STATE>
  class EmulateNetworkConditionsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EmulateNetworkConditionsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EmulateNetworkConditionsResult;
    EmulateNetworkConditionsResultBuilder() : result_(new EmulateNetworkConditionsResult()) { }

    template<int STEP> EmulateNetworkConditionsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EmulateNetworkConditionsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EmulateNetworkConditionsResult> result_;
  };

  static EmulateNetworkConditionsResultBuilder<0> Builder() {
    return EmulateNetworkConditionsResultBuilder<0>();
  }

 private:
  EmulateNetworkConditionsResult() { }


  DISALLOW_COPY_AND_ASSIGN(EmulateNetworkConditionsResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  // Buffer size in bytes to use when preserving network payloads (XHRs, etc).
  bool HasMaxTotalBufferSize() const { return !!max_total_buffer_size_; }
  int GetMaxTotalBufferSize() const { DCHECK(HasMaxTotalBufferSize()); return max_total_buffer_size_.value(); }
  void SetMaxTotalBufferSize(int value) { max_total_buffer_size_ = value; }

  // Per-resource buffer size in bytes to use when preserving network payloads (XHRs, etc).
  bool HasMaxResourceBufferSize() const { return !!max_resource_buffer_size_; }
  int GetMaxResourceBufferSize() const { DCHECK(HasMaxResourceBufferSize()); return max_resource_buffer_size_.value(); }
  void SetMaxResourceBufferSize(int value) { max_resource_buffer_size_ = value; }

  // Longest post body size (in bytes) that would be included in requestWillBeSent notification
  bool HasMaxPostDataSize() const { return !!max_post_data_size_; }
  int GetMaxPostDataSize() const { DCHECK(HasMaxPostDataSize()); return max_post_data_size_.value(); }
  void SetMaxPostDataSize(int value) { max_post_data_size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    EnableParamsBuilder<STATE>& SetMaxTotalBufferSize(int value) {
      result_->SetMaxTotalBufferSize(value);
      return *this;
    }

    EnableParamsBuilder<STATE>& SetMaxResourceBufferSize(int value) {
      result_->SetMaxResourceBufferSize(value);
      return *this;
    }

    EnableParamsBuilder<STATE>& SetMaxPostDataSize(int value) {
      result_->SetMaxPostDataSize(value);
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

  base::Optional<int> max_total_buffer_size_;
  base::Optional<int> max_resource_buffer_size_;
  base::Optional<int> max_post_data_size_;

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


// Parameters for the GetAllCookies command.
class HEADLESS_EXPORT GetAllCookiesParams {
 public:
  static std::unique_ptr<GetAllCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAllCookiesParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAllCookiesParams> Clone() const;

  template<int STATE>
  class GetAllCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetAllCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAllCookiesParams;
    GetAllCookiesParamsBuilder() : result_(new GetAllCookiesParams()) { }

    template<int STEP> GetAllCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAllCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAllCookiesParams> result_;
  };

  static GetAllCookiesParamsBuilder<0> Builder() {
    return GetAllCookiesParamsBuilder<0>();
  }

 private:
  GetAllCookiesParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetAllCookiesParams);
};


// Result for the GetAllCookies command.
class HEADLESS_EXPORT GetAllCookiesResult {
 public:
  static std::unique_ptr<GetAllCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAllCookiesResult() { }

  // Array of cookie objects.
  const std::vector<std::unique_ptr<::headless::network::Cookie>>* GetCookies() const { return &cookies_; }
  void SetCookies(std::vector<std::unique_ptr<::headless::network::Cookie>> value) { cookies_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAllCookiesResult> Clone() const;

  template<int STATE>
  class GetAllCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCookiesSet = 1 << 1,
      kAllRequiredFieldsSet = (kCookiesSet | 0)
    };

    GetAllCookiesResultBuilder<STATE | kCookiesSet>& SetCookies(std::vector<std::unique_ptr<::headless::network::Cookie>> value) {
      static_assert(!(STATE & kCookiesSet), "property cookies should not have already been set");
      result_->SetCookies(std::move(value));
      return CastState<kCookiesSet>();
    }

    std::unique_ptr<GetAllCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAllCookiesResult;
    GetAllCookiesResultBuilder() : result_(new GetAllCookiesResult()) { }

    template<int STEP> GetAllCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAllCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAllCookiesResult> result_;
  };

  static GetAllCookiesResultBuilder<0> Builder() {
    return GetAllCookiesResultBuilder<0>();
  }

 private:
  GetAllCookiesResult() { }

  std::vector<std::unique_ptr<::headless::network::Cookie>> cookies_;

  DISALLOW_COPY_AND_ASSIGN(GetAllCookiesResult);
};


// Parameters for the GetCertificate command.
class HEADLESS_EXPORT GetCertificateParams {
 public:
  static std::unique_ptr<GetCertificateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCertificateParams() { }

  // Origin to get certificate for.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCertificateParams> Clone() const;

  template<int STATE>
  class GetCertificateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kOriginSet | 0)
    };

    GetCertificateParamsBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    std::unique_ptr<GetCertificateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCertificateParams;
    GetCertificateParamsBuilder() : result_(new GetCertificateParams()) { }

    template<int STEP> GetCertificateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCertificateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCertificateParams> result_;
  };

  static GetCertificateParamsBuilder<0> Builder() {
    return GetCertificateParamsBuilder<0>();
  }

 private:
  GetCertificateParams() { }

  std::string origin_;

  DISALLOW_COPY_AND_ASSIGN(GetCertificateParams);
};


// Result for the GetCertificate command.
class HEADLESS_EXPORT GetCertificateResult {
 public:
  static std::unique_ptr<GetCertificateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCertificateResult() { }

  const std::vector<std::string>* GetTableNames() const { return &table_names_; }
  void SetTableNames(std::vector<std::string> value) { table_names_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCertificateResult> Clone() const;

  template<int STATE>
  class GetCertificateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTableNamesSet = 1 << 1,
      kAllRequiredFieldsSet = (kTableNamesSet | 0)
    };

    GetCertificateResultBuilder<STATE | kTableNamesSet>& SetTableNames(std::vector<std::string> value) {
      static_assert(!(STATE & kTableNamesSet), "property tableNames should not have already been set");
      result_->SetTableNames(std::move(value));
      return CastState<kTableNamesSet>();
    }

    std::unique_ptr<GetCertificateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCertificateResult;
    GetCertificateResultBuilder() : result_(new GetCertificateResult()) { }

    template<int STEP> GetCertificateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCertificateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCertificateResult> result_;
  };

  static GetCertificateResultBuilder<0> Builder() {
    return GetCertificateResultBuilder<0>();
  }

 private:
  GetCertificateResult() { }

  std::vector<std::string> table_names_;

  DISALLOW_COPY_AND_ASSIGN(GetCertificateResult);
};


// Parameters for the GetCookies command.
class HEADLESS_EXPORT GetCookiesParams {
 public:
  static std::unique_ptr<GetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCookiesParams() { }

  // The list of URLs for which applicable cookies will be fetched
  bool HasUrls() const { return !!urls_; }
  const std::vector<std::string>* GetUrls() const { DCHECK(HasUrls()); return &urls_.value(); }
  void SetUrls(std::vector<std::string> value) { urls_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCookiesParams> Clone() const;

  template<int STATE>
  class GetCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetCookiesParamsBuilder<STATE>& SetUrls(std::vector<std::string> value) {
      result_->SetUrls(std::move(value));
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

  base::Optional<std::vector<std::string>> urls_;

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


// Parameters for the GetResponseBody command.
class HEADLESS_EXPORT GetResponseBodyParams {
 public:
  static std::unique_ptr<GetResponseBodyParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResponseBodyParams() { }

  // Identifier of the network request to get content for.
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


// Parameters for the GetRequestPostData command.
class HEADLESS_EXPORT GetRequestPostDataParams {
 public:
  static std::unique_ptr<GetRequestPostDataParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRequestPostDataParams() { }

  // Identifier of the network request to get content for.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRequestPostDataParams> Clone() const;

  template<int STATE>
  class GetRequestPostDataParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kRequestIdSet | 0)
    };

    GetRequestPostDataParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    std::unique_ptr<GetRequestPostDataParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRequestPostDataParams;
    GetRequestPostDataParamsBuilder() : result_(new GetRequestPostDataParams()) { }

    template<int STEP> GetRequestPostDataParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRequestPostDataParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRequestPostDataParams> result_;
  };

  static GetRequestPostDataParamsBuilder<0> Builder() {
    return GetRequestPostDataParamsBuilder<0>();
  }

 private:
  GetRequestPostDataParams() { }

  std::string request_id_;

  DISALLOW_COPY_AND_ASSIGN(GetRequestPostDataParams);
};


// Result for the GetRequestPostData command.
class HEADLESS_EXPORT GetRequestPostDataResult {
 public:
  static std::unique_ptr<GetRequestPostDataResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRequestPostDataResult() { }

  // Request body string, omitting files from multipart requests
  std::string GetPostData() const { return post_data_; }
  void SetPostData(const std::string& value) { post_data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRequestPostDataResult> Clone() const;

  template<int STATE>
  class GetRequestPostDataResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPostDataSet = 1 << 1,
      kAllRequiredFieldsSet = (kPostDataSet | 0)
    };

    GetRequestPostDataResultBuilder<STATE | kPostDataSet>& SetPostData(const std::string& value) {
      static_assert(!(STATE & kPostDataSet), "property postData should not have already been set");
      result_->SetPostData(value);
      return CastState<kPostDataSet>();
    }

    std::unique_ptr<GetRequestPostDataResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRequestPostDataResult;
    GetRequestPostDataResultBuilder() : result_(new GetRequestPostDataResult()) { }

    template<int STEP> GetRequestPostDataResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRequestPostDataResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRequestPostDataResult> result_;
  };

  static GetRequestPostDataResultBuilder<0> Builder() {
    return GetRequestPostDataResultBuilder<0>();
  }

 private:
  GetRequestPostDataResult() { }

  std::string post_data_;

  DISALLOW_COPY_AND_ASSIGN(GetRequestPostDataResult);
};


// Parameters for the GetResponseBodyForInterception command.
class HEADLESS_EXPORT GetResponseBodyForInterceptionParams {
 public:
  static std::unique_ptr<GetResponseBodyForInterceptionParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResponseBodyForInterceptionParams() { }

  // Identifier for the intercepted request to get body for.
  std::string GetInterceptionId() const { return interception_id_; }
  void SetInterceptionId(const std::string& value) { interception_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResponseBodyForInterceptionParams> Clone() const;

  template<int STATE>
  class GetResponseBodyForInterceptionParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kInterceptionIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kInterceptionIdSet | 0)
    };

    GetResponseBodyForInterceptionParamsBuilder<STATE | kInterceptionIdSet>& SetInterceptionId(const std::string& value) {
      static_assert(!(STATE & kInterceptionIdSet), "property interceptionId should not have already been set");
      result_->SetInterceptionId(value);
      return CastState<kInterceptionIdSet>();
    }

    std::unique_ptr<GetResponseBodyForInterceptionParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResponseBodyForInterceptionParams;
    GetResponseBodyForInterceptionParamsBuilder() : result_(new GetResponseBodyForInterceptionParams()) { }

    template<int STEP> GetResponseBodyForInterceptionParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResponseBodyForInterceptionParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResponseBodyForInterceptionParams> result_;
  };

  static GetResponseBodyForInterceptionParamsBuilder<0> Builder() {
    return GetResponseBodyForInterceptionParamsBuilder<0>();
  }

 private:
  GetResponseBodyForInterceptionParams() { }

  std::string interception_id_;

  DISALLOW_COPY_AND_ASSIGN(GetResponseBodyForInterceptionParams);
};


// Result for the GetResponseBodyForInterception command.
class HEADLESS_EXPORT GetResponseBodyForInterceptionResult {
 public:
  static std::unique_ptr<GetResponseBodyForInterceptionResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResponseBodyForInterceptionResult() { }

  // Response body.
  std::string GetBody() const { return body_; }
  void SetBody(const std::string& value) { body_ = value; }

  // True, if content was sent as base64.
  bool GetBase64Encoded() const { return base64_encoded_; }
  void SetBase64Encoded(bool value) { base64_encoded_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResponseBodyForInterceptionResult> Clone() const;

  template<int STATE>
  class GetResponseBodyForInterceptionResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBodySet = 1 << 1,
    kBase64EncodedSet = 1 << 2,
      kAllRequiredFieldsSet = (kBodySet | kBase64EncodedSet | 0)
    };

    GetResponseBodyForInterceptionResultBuilder<STATE | kBodySet>& SetBody(const std::string& value) {
      static_assert(!(STATE & kBodySet), "property body should not have already been set");
      result_->SetBody(value);
      return CastState<kBodySet>();
    }

    GetResponseBodyForInterceptionResultBuilder<STATE | kBase64EncodedSet>& SetBase64Encoded(bool value) {
      static_assert(!(STATE & kBase64EncodedSet), "property base64Encoded should not have already been set");
      result_->SetBase64Encoded(value);
      return CastState<kBase64EncodedSet>();
    }

    std::unique_ptr<GetResponseBodyForInterceptionResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResponseBodyForInterceptionResult;
    GetResponseBodyForInterceptionResultBuilder() : result_(new GetResponseBodyForInterceptionResult()) { }

    template<int STEP> GetResponseBodyForInterceptionResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResponseBodyForInterceptionResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResponseBodyForInterceptionResult> result_;
  };

  static GetResponseBodyForInterceptionResultBuilder<0> Builder() {
    return GetResponseBodyForInterceptionResultBuilder<0>();
  }

 private:
  GetResponseBodyForInterceptionResult() { }

  std::string body_;
  bool base64_encoded_;

  DISALLOW_COPY_AND_ASSIGN(GetResponseBodyForInterceptionResult);
};


// Parameters for the TakeResponseBodyForInterceptionAsStream command.
class HEADLESS_EXPORT TakeResponseBodyForInterceptionAsStreamParams {
 public:
  static std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakeResponseBodyForInterceptionAsStreamParams() { }

  std::string GetInterceptionId() const { return interception_id_; }
  void SetInterceptionId(const std::string& value) { interception_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> Clone() const;

  template<int STATE>
  class TakeResponseBodyForInterceptionAsStreamParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kInterceptionIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kInterceptionIdSet | 0)
    };

    TakeResponseBodyForInterceptionAsStreamParamsBuilder<STATE | kInterceptionIdSet>& SetInterceptionId(const std::string& value) {
      static_assert(!(STATE & kInterceptionIdSet), "property interceptionId should not have already been set");
      result_->SetInterceptionId(value);
      return CastState<kInterceptionIdSet>();
    }

    std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakeResponseBodyForInterceptionAsStreamParams;
    TakeResponseBodyForInterceptionAsStreamParamsBuilder() : result_(new TakeResponseBodyForInterceptionAsStreamParams()) { }

    template<int STEP> TakeResponseBodyForInterceptionAsStreamParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakeResponseBodyForInterceptionAsStreamParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> result_;
  };

  static TakeResponseBodyForInterceptionAsStreamParamsBuilder<0> Builder() {
    return TakeResponseBodyForInterceptionAsStreamParamsBuilder<0>();
  }

 private:
  TakeResponseBodyForInterceptionAsStreamParams() { }

  std::string interception_id_;

  DISALLOW_COPY_AND_ASSIGN(TakeResponseBodyForInterceptionAsStreamParams);
};


// Result for the TakeResponseBodyForInterceptionAsStream command.
class HEADLESS_EXPORT TakeResponseBodyForInterceptionAsStreamResult {
 public:
  static std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~TakeResponseBodyForInterceptionAsStreamResult() { }

  std::string GetStream() const { return stream_; }
  void SetStream(const std::string& value) { stream_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> Clone() const;

  template<int STATE>
  class TakeResponseBodyForInterceptionAsStreamResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStreamSet = 1 << 1,
      kAllRequiredFieldsSet = (kStreamSet | 0)
    };

    TakeResponseBodyForInterceptionAsStreamResultBuilder<STATE | kStreamSet>& SetStream(const std::string& value) {
      static_assert(!(STATE & kStreamSet), "property stream should not have already been set");
      result_->SetStream(value);
      return CastState<kStreamSet>();
    }

    std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TakeResponseBodyForInterceptionAsStreamResult;
    TakeResponseBodyForInterceptionAsStreamResultBuilder() : result_(new TakeResponseBodyForInterceptionAsStreamResult()) { }

    template<int STEP> TakeResponseBodyForInterceptionAsStreamResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TakeResponseBodyForInterceptionAsStreamResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> result_;
  };

  static TakeResponseBodyForInterceptionAsStreamResultBuilder<0> Builder() {
    return TakeResponseBodyForInterceptionAsStreamResultBuilder<0>();
  }

 private:
  TakeResponseBodyForInterceptionAsStreamResult() { }

  std::string stream_;

  DISALLOW_COPY_AND_ASSIGN(TakeResponseBodyForInterceptionAsStreamResult);
};


// Parameters for the ReplayXHR command.
class HEADLESS_EXPORT ReplayXHRParams {
 public:
  static std::unique_ptr<ReplayXHRParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReplayXHRParams() { }

  // Identifier of XHR to replay.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReplayXHRParams> Clone() const;

  template<int STATE>
  class ReplayXHRParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kRequestIdSet | 0)
    };

    ReplayXHRParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    std::unique_ptr<ReplayXHRParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReplayXHRParams;
    ReplayXHRParamsBuilder() : result_(new ReplayXHRParams()) { }

    template<int STEP> ReplayXHRParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReplayXHRParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReplayXHRParams> result_;
  };

  static ReplayXHRParamsBuilder<0> Builder() {
    return ReplayXHRParamsBuilder<0>();
  }

 private:
  ReplayXHRParams() { }

  std::string request_id_;

  DISALLOW_COPY_AND_ASSIGN(ReplayXHRParams);
};


// Result for the ReplayXHR command.
class HEADLESS_EXPORT ReplayXHRResult {
 public:
  static std::unique_ptr<ReplayXHRResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReplayXHRResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReplayXHRResult> Clone() const;

  template<int STATE>
  class ReplayXHRResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ReplayXHRResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReplayXHRResult;
    ReplayXHRResultBuilder() : result_(new ReplayXHRResult()) { }

    template<int STEP> ReplayXHRResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReplayXHRResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReplayXHRResult> result_;
  };

  static ReplayXHRResultBuilder<0> Builder() {
    return ReplayXHRResultBuilder<0>();
  }

 private:
  ReplayXHRResult() { }


  DISALLOW_COPY_AND_ASSIGN(ReplayXHRResult);
};


// Parameters for the SearchInResponseBody command.
class HEADLESS_EXPORT SearchInResponseBodyParams {
 public:
  static std::unique_ptr<SearchInResponseBodyParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SearchInResponseBodyParams() { }

  // Identifier of the network response to search.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // String to search for.
  std::string GetQuery() const { return query_; }
  void SetQuery(const std::string& value) { query_ = value; }

  // If true, search is case sensitive.
  bool HasCaseSensitive() const { return !!case_sensitive_; }
  bool GetCaseSensitive() const { DCHECK(HasCaseSensitive()); return case_sensitive_.value(); }
  void SetCaseSensitive(bool value) { case_sensitive_ = value; }

  // If true, treats string parameter as regex.
  bool HasIsRegex() const { return !!is_regex_; }
  bool GetIsRegex() const { DCHECK(HasIsRegex()); return is_regex_.value(); }
  void SetIsRegex(bool value) { is_regex_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SearchInResponseBodyParams> Clone() const;

  template<int STATE>
  class SearchInResponseBodyParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kQuerySet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kQuerySet | 0)
    };

    SearchInResponseBodyParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    SearchInResponseBodyParamsBuilder<STATE | kQuerySet>& SetQuery(const std::string& value) {
      static_assert(!(STATE & kQuerySet), "property query should not have already been set");
      result_->SetQuery(value);
      return CastState<kQuerySet>();
    }

    SearchInResponseBodyParamsBuilder<STATE>& SetCaseSensitive(bool value) {
      result_->SetCaseSensitive(value);
      return *this;
    }

    SearchInResponseBodyParamsBuilder<STATE>& SetIsRegex(bool value) {
      result_->SetIsRegex(value);
      return *this;
    }

    std::unique_ptr<SearchInResponseBodyParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SearchInResponseBodyParams;
    SearchInResponseBodyParamsBuilder() : result_(new SearchInResponseBodyParams()) { }

    template<int STEP> SearchInResponseBodyParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SearchInResponseBodyParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SearchInResponseBodyParams> result_;
  };

  static SearchInResponseBodyParamsBuilder<0> Builder() {
    return SearchInResponseBodyParamsBuilder<0>();
  }

 private:
  SearchInResponseBodyParams() { }

  std::string request_id_;
  std::string query_;
  base::Optional<bool> case_sensitive_;
  base::Optional<bool> is_regex_;

  DISALLOW_COPY_AND_ASSIGN(SearchInResponseBodyParams);
};


// Result for the SearchInResponseBody command.
class HEADLESS_EXPORT SearchInResponseBodyResult {
 public:
  static std::unique_ptr<SearchInResponseBodyResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SearchInResponseBodyResult() { }

  // List of search matches.
  const std::vector<std::unique_ptr<::headless::debugger::SearchMatch>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::debugger::SearchMatch>> value) { result_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SearchInResponseBodyResult> Clone() const;

  template<int STATE>
  class SearchInResponseBodyResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    SearchInResponseBodyResultBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::debugger::SearchMatch>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    std::unique_ptr<SearchInResponseBodyResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SearchInResponseBodyResult;
    SearchInResponseBodyResultBuilder() : result_(new SearchInResponseBodyResult()) { }

    template<int STEP> SearchInResponseBodyResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SearchInResponseBodyResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SearchInResponseBodyResult> result_;
  };

  static SearchInResponseBodyResultBuilder<0> Builder() {
    return SearchInResponseBodyResultBuilder<0>();
  }

 private:
  SearchInResponseBodyResult() { }

  std::vector<std::unique_ptr<::headless::debugger::SearchMatch>> result_;

  DISALLOW_COPY_AND_ASSIGN(SearchInResponseBodyResult);
};


// Parameters for the SetBlockedURLs command.
class HEADLESS_EXPORT SetBlockedURLsParams {
 public:
  static std::unique_ptr<SetBlockedURLsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetBlockedURLsParams() { }

  // URL patterns to block. Wildcards ('*') are allowed.
  const std::vector<std::string>* GetUrls() const { return &urls_; }
  void SetUrls(std::vector<std::string> value) { urls_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetBlockedURLsParams> Clone() const;

  template<int STATE>
  class SetBlockedURLsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlsSet = 1 << 1,
      kAllRequiredFieldsSet = (kUrlsSet | 0)
    };

    SetBlockedURLsParamsBuilder<STATE | kUrlsSet>& SetUrls(std::vector<std::string> value) {
      static_assert(!(STATE & kUrlsSet), "property urls should not have already been set");
      result_->SetUrls(std::move(value));
      return CastState<kUrlsSet>();
    }

    std::unique_ptr<SetBlockedURLsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetBlockedURLsParams;
    SetBlockedURLsParamsBuilder() : result_(new SetBlockedURLsParams()) { }

    template<int STEP> SetBlockedURLsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetBlockedURLsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetBlockedURLsParams> result_;
  };

  static SetBlockedURLsParamsBuilder<0> Builder() {
    return SetBlockedURLsParamsBuilder<0>();
  }

 private:
  SetBlockedURLsParams() { }

  std::vector<std::string> urls_;

  DISALLOW_COPY_AND_ASSIGN(SetBlockedURLsParams);
};


// Result for the SetBlockedURLs command.
class HEADLESS_EXPORT SetBlockedURLsResult {
 public:
  static std::unique_ptr<SetBlockedURLsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetBlockedURLsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetBlockedURLsResult> Clone() const;

  template<int STATE>
  class SetBlockedURLsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetBlockedURLsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetBlockedURLsResult;
    SetBlockedURLsResultBuilder() : result_(new SetBlockedURLsResult()) { }

    template<int STEP> SetBlockedURLsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetBlockedURLsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetBlockedURLsResult> result_;
  };

  static SetBlockedURLsResultBuilder<0> Builder() {
    return SetBlockedURLsResultBuilder<0>();
  }

 private:
  SetBlockedURLsResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetBlockedURLsResult);
};


// Parameters for the SetBypassServiceWorker command.
class HEADLESS_EXPORT SetBypassServiceWorkerParams {
 public:
  static std::unique_ptr<SetBypassServiceWorkerParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetBypassServiceWorkerParams() { }

  // Bypass service worker and load from network.
  bool GetBypass() const { return bypass_; }
  void SetBypass(bool value) { bypass_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetBypassServiceWorkerParams> Clone() const;

  template<int STATE>
  class SetBypassServiceWorkerParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBypassSet = 1 << 1,
      kAllRequiredFieldsSet = (kBypassSet | 0)
    };

    SetBypassServiceWorkerParamsBuilder<STATE | kBypassSet>& SetBypass(bool value) {
      static_assert(!(STATE & kBypassSet), "property bypass should not have already been set");
      result_->SetBypass(value);
      return CastState<kBypassSet>();
    }

    std::unique_ptr<SetBypassServiceWorkerParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetBypassServiceWorkerParams;
    SetBypassServiceWorkerParamsBuilder() : result_(new SetBypassServiceWorkerParams()) { }

    template<int STEP> SetBypassServiceWorkerParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetBypassServiceWorkerParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetBypassServiceWorkerParams> result_;
  };

  static SetBypassServiceWorkerParamsBuilder<0> Builder() {
    return SetBypassServiceWorkerParamsBuilder<0>();
  }

 private:
  SetBypassServiceWorkerParams() { }

  bool bypass_;

  DISALLOW_COPY_AND_ASSIGN(SetBypassServiceWorkerParams);
};


// Result for the SetBypassServiceWorker command.
class HEADLESS_EXPORT SetBypassServiceWorkerResult {
 public:
  static std::unique_ptr<SetBypassServiceWorkerResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetBypassServiceWorkerResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetBypassServiceWorkerResult> Clone() const;

  template<int STATE>
  class SetBypassServiceWorkerResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetBypassServiceWorkerResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetBypassServiceWorkerResult;
    SetBypassServiceWorkerResultBuilder() : result_(new SetBypassServiceWorkerResult()) { }

    template<int STEP> SetBypassServiceWorkerResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetBypassServiceWorkerResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetBypassServiceWorkerResult> result_;
  };

  static SetBypassServiceWorkerResultBuilder<0> Builder() {
    return SetBypassServiceWorkerResultBuilder<0>();
  }

 private:
  SetBypassServiceWorkerResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetBypassServiceWorkerResult);
};


// Parameters for the SetCacheDisabled command.
class HEADLESS_EXPORT SetCacheDisabledParams {
 public:
  static std::unique_ptr<SetCacheDisabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCacheDisabledParams() { }

  // Cache disabled state.
  bool GetCacheDisabled() const { return cache_disabled_; }
  void SetCacheDisabled(bool value) { cache_disabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCacheDisabledParams> Clone() const;

  template<int STATE>
  class SetCacheDisabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCacheDisabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kCacheDisabledSet | 0)
    };

    SetCacheDisabledParamsBuilder<STATE | kCacheDisabledSet>& SetCacheDisabled(bool value) {
      static_assert(!(STATE & kCacheDisabledSet), "property cacheDisabled should not have already been set");
      result_->SetCacheDisabled(value);
      return CastState<kCacheDisabledSet>();
    }

    std::unique_ptr<SetCacheDisabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCacheDisabledParams;
    SetCacheDisabledParamsBuilder() : result_(new SetCacheDisabledParams()) { }

    template<int STEP> SetCacheDisabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCacheDisabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCacheDisabledParams> result_;
  };

  static SetCacheDisabledParamsBuilder<0> Builder() {
    return SetCacheDisabledParamsBuilder<0>();
  }

 private:
  SetCacheDisabledParams() { }

  bool cache_disabled_;

  DISALLOW_COPY_AND_ASSIGN(SetCacheDisabledParams);
};


// Result for the SetCacheDisabled command.
class HEADLESS_EXPORT SetCacheDisabledResult {
 public:
  static std::unique_ptr<SetCacheDisabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCacheDisabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCacheDisabledResult> Clone() const;

  template<int STATE>
  class SetCacheDisabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetCacheDisabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCacheDisabledResult;
    SetCacheDisabledResultBuilder() : result_(new SetCacheDisabledResult()) { }

    template<int STEP> SetCacheDisabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCacheDisabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCacheDisabledResult> result_;
  };

  static SetCacheDisabledResultBuilder<0> Builder() {
    return SetCacheDisabledResultBuilder<0>();
  }

 private:
  SetCacheDisabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetCacheDisabledResult);
};


// Parameters for the SetCookie command.
class HEADLESS_EXPORT SetCookieParams {
 public:
  static std::unique_ptr<SetCookieParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCookieParams() { }

  // Cookie name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Cookie value.
  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  // The request-URI to associate with the setting of the cookie. This value can affect the
  // default domain and path values of the created cookie.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // Cookie domain.
  bool HasDomain() const { return !!domain_; }
  std::string GetDomain() const { DCHECK(HasDomain()); return domain_.value(); }
  void SetDomain(const std::string& value) { domain_ = value; }

  // Cookie path.
  bool HasPath() const { return !!path_; }
  std::string GetPath() const { DCHECK(HasPath()); return path_.value(); }
  void SetPath(const std::string& value) { path_ = value; }

  // True if cookie is secure.
  bool HasSecure() const { return !!secure_; }
  bool GetSecure() const { DCHECK(HasSecure()); return secure_.value(); }
  void SetSecure(bool value) { secure_ = value; }

  // True if cookie is http-only.
  bool HasHttpOnly() const { return !!http_only_; }
  bool GetHttpOnly() const { DCHECK(HasHttpOnly()); return http_only_.value(); }
  void SetHttpOnly(bool value) { http_only_ = value; }

  // Cookie SameSite type.
  bool HasSameSite() const { return !!same_site_; }
  ::headless::network::CookieSameSite GetSameSite() const { DCHECK(HasSameSite()); return same_site_.value(); }
  void SetSameSite(::headless::network::CookieSameSite value) { same_site_ = value; }

  // Cookie expiration date, session cookie if not set
  bool HasExpires() const { return !!expires_; }
  double GetExpires() const { DCHECK(HasExpires()); return expires_.value(); }
  void SetExpires(double value) { expires_ = value; }

  // Cookie Priority type.
  bool HasPriority() const { return !!priority_; }
  ::headless::network::CookiePriority GetPriority() const { DCHECK(HasPriority()); return priority_.value(); }
  void SetPriority(::headless::network::CookiePriority value) { priority_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCookieParams> Clone() const;

  template<int STATE>
  class SetCookieParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    SetCookieParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    SetCookieParamsBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    SetCookieParamsBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    SetCookieParamsBuilder<STATE>& SetDomain(const std::string& value) {
      result_->SetDomain(value);
      return *this;
    }

    SetCookieParamsBuilder<STATE>& SetPath(const std::string& value) {
      result_->SetPath(value);
      return *this;
    }

    SetCookieParamsBuilder<STATE>& SetSecure(bool value) {
      result_->SetSecure(value);
      return *this;
    }

    SetCookieParamsBuilder<STATE>& SetHttpOnly(bool value) {
      result_->SetHttpOnly(value);
      return *this;
    }

    SetCookieParamsBuilder<STATE>& SetSameSite(::headless::network::CookieSameSite value) {
      result_->SetSameSite(value);
      return *this;
    }

    SetCookieParamsBuilder<STATE>& SetExpires(double value) {
      result_->SetExpires(value);
      return *this;
    }

    SetCookieParamsBuilder<STATE>& SetPriority(::headless::network::CookiePriority value) {
      result_->SetPriority(value);
      return *this;
    }

    std::unique_ptr<SetCookieParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCookieParams;
    SetCookieParamsBuilder() : result_(new SetCookieParams()) { }

    template<int STEP> SetCookieParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCookieParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCookieParams> result_;
  };

  static SetCookieParamsBuilder<0> Builder() {
    return SetCookieParamsBuilder<0>();
  }

 private:
  SetCookieParams() { }

  std::string name_;
  std::string value_;
  base::Optional<std::string> url_;
  base::Optional<std::string> domain_;
  base::Optional<std::string> path_;
  base::Optional<bool> secure_;
  base::Optional<bool> http_only_;
  base::Optional<::headless::network::CookieSameSite> same_site_;
  base::Optional<double> expires_;
  base::Optional<::headless::network::CookiePriority> priority_;

  DISALLOW_COPY_AND_ASSIGN(SetCookieParams);
};


// Result for the SetCookie command.
class HEADLESS_EXPORT SetCookieResult {
 public:
  static std::unique_ptr<SetCookieResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCookieResult() { }

  // True if successfully set cookie.
  bool GetSuccess() const { return success_; }
  void SetSuccess(bool value) { success_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCookieResult> Clone() const;

  template<int STATE>
  class SetCookieResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSuccessSet = 1 << 1,
      kAllRequiredFieldsSet = (kSuccessSet | 0)
    };

    SetCookieResultBuilder<STATE | kSuccessSet>& SetSuccess(bool value) {
      static_assert(!(STATE & kSuccessSet), "property success should not have already been set");
      result_->SetSuccess(value);
      return CastState<kSuccessSet>();
    }

    std::unique_ptr<SetCookieResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCookieResult;
    SetCookieResultBuilder() : result_(new SetCookieResult()) { }

    template<int STEP> SetCookieResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCookieResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCookieResult> result_;
  };

  static SetCookieResultBuilder<0> Builder() {
    return SetCookieResultBuilder<0>();
  }

 private:
  SetCookieResult() { }

  bool success_;

  DISALLOW_COPY_AND_ASSIGN(SetCookieResult);
};


// Parameters for the SetCookies command.
class HEADLESS_EXPORT SetCookiesParams {
 public:
  static std::unique_ptr<SetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCookiesParams() { }

  // Cookies to be set.
  const std::vector<std::unique_ptr<::headless::network::CookieParam>>* GetCookies() const { return &cookies_; }
  void SetCookies(std::vector<std::unique_ptr<::headless::network::CookieParam>> value) { cookies_ = std::move(value); }

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


// Parameters for the SetDataSizeLimitsForTest command.
class HEADLESS_EXPORT SetDataSizeLimitsForTestParams {
 public:
  static std::unique_ptr<SetDataSizeLimitsForTestParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDataSizeLimitsForTestParams() { }

  // Maximum total buffer size.
  int GetMaxTotalSize() const { return max_total_size_; }
  void SetMaxTotalSize(int value) { max_total_size_ = value; }

  // Maximum per-resource size.
  int GetMaxResourceSize() const { return max_resource_size_; }
  void SetMaxResourceSize(int value) { max_resource_size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDataSizeLimitsForTestParams> Clone() const;

  template<int STATE>
  class SetDataSizeLimitsForTestParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMaxTotalSizeSet = 1 << 1,
    kMaxResourceSizeSet = 1 << 2,
      kAllRequiredFieldsSet = (kMaxTotalSizeSet | kMaxResourceSizeSet | 0)
    };

    SetDataSizeLimitsForTestParamsBuilder<STATE | kMaxTotalSizeSet>& SetMaxTotalSize(int value) {
      static_assert(!(STATE & kMaxTotalSizeSet), "property maxTotalSize should not have already been set");
      result_->SetMaxTotalSize(value);
      return CastState<kMaxTotalSizeSet>();
    }

    SetDataSizeLimitsForTestParamsBuilder<STATE | kMaxResourceSizeSet>& SetMaxResourceSize(int value) {
      static_assert(!(STATE & kMaxResourceSizeSet), "property maxResourceSize should not have already been set");
      result_->SetMaxResourceSize(value);
      return CastState<kMaxResourceSizeSet>();
    }

    std::unique_ptr<SetDataSizeLimitsForTestParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDataSizeLimitsForTestParams;
    SetDataSizeLimitsForTestParamsBuilder() : result_(new SetDataSizeLimitsForTestParams()) { }

    template<int STEP> SetDataSizeLimitsForTestParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDataSizeLimitsForTestParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDataSizeLimitsForTestParams> result_;
  };

  static SetDataSizeLimitsForTestParamsBuilder<0> Builder() {
    return SetDataSizeLimitsForTestParamsBuilder<0>();
  }

 private:
  SetDataSizeLimitsForTestParams() { }

  int max_total_size_;
  int max_resource_size_;

  DISALLOW_COPY_AND_ASSIGN(SetDataSizeLimitsForTestParams);
};


// Result for the SetDataSizeLimitsForTest command.
class HEADLESS_EXPORT SetDataSizeLimitsForTestResult {
 public:
  static std::unique_ptr<SetDataSizeLimitsForTestResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDataSizeLimitsForTestResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDataSizeLimitsForTestResult> Clone() const;

  template<int STATE>
  class SetDataSizeLimitsForTestResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDataSizeLimitsForTestResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDataSizeLimitsForTestResult;
    SetDataSizeLimitsForTestResultBuilder() : result_(new SetDataSizeLimitsForTestResult()) { }

    template<int STEP> SetDataSizeLimitsForTestResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDataSizeLimitsForTestResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDataSizeLimitsForTestResult> result_;
  };

  static SetDataSizeLimitsForTestResultBuilder<0> Builder() {
    return SetDataSizeLimitsForTestResultBuilder<0>();
  }

 private:
  SetDataSizeLimitsForTestResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDataSizeLimitsForTestResult);
};


// Parameters for the SetExtraHTTPHeaders command.
class HEADLESS_EXPORT SetExtraHTTPHeadersParams {
 public:
  static std::unique_ptr<SetExtraHTTPHeadersParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetExtraHTTPHeadersParams() { }

  // Map with extra HTTP headers.
  const base::DictionaryValue* GetHeaders() const { return headers_.get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetExtraHTTPHeadersParams> Clone() const;

  template<int STATE>
  class SetExtraHTTPHeadersParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHeadersSet = 1 << 1,
      kAllRequiredFieldsSet = (kHeadersSet | 0)
    };

    SetExtraHTTPHeadersParamsBuilder<STATE | kHeadersSet>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kHeadersSet), "property headers should not have already been set");
      result_->SetHeaders(std::move(value));
      return CastState<kHeadersSet>();
    }

    std::unique_ptr<SetExtraHTTPHeadersParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetExtraHTTPHeadersParams;
    SetExtraHTTPHeadersParamsBuilder() : result_(new SetExtraHTTPHeadersParams()) { }

    template<int STEP> SetExtraHTTPHeadersParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetExtraHTTPHeadersParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetExtraHTTPHeadersParams> result_;
  };

  static SetExtraHTTPHeadersParamsBuilder<0> Builder() {
    return SetExtraHTTPHeadersParamsBuilder<0>();
  }

 private:
  SetExtraHTTPHeadersParams() { }

  std::unique_ptr<base::DictionaryValue> headers_;

  DISALLOW_COPY_AND_ASSIGN(SetExtraHTTPHeadersParams);
};


// Result for the SetExtraHTTPHeaders command.
class HEADLESS_EXPORT SetExtraHTTPHeadersResult {
 public:
  static std::unique_ptr<SetExtraHTTPHeadersResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetExtraHTTPHeadersResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetExtraHTTPHeadersResult> Clone() const;

  template<int STATE>
  class SetExtraHTTPHeadersResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetExtraHTTPHeadersResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetExtraHTTPHeadersResult;
    SetExtraHTTPHeadersResultBuilder() : result_(new SetExtraHTTPHeadersResult()) { }

    template<int STEP> SetExtraHTTPHeadersResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetExtraHTTPHeadersResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetExtraHTTPHeadersResult> result_;
  };

  static SetExtraHTTPHeadersResultBuilder<0> Builder() {
    return SetExtraHTTPHeadersResultBuilder<0>();
  }

 private:
  SetExtraHTTPHeadersResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetExtraHTTPHeadersResult);
};


// Parameters for the SetRequestInterception command.
class HEADLESS_EXPORT SetRequestInterceptionParams {
 public:
  static std::unique_ptr<SetRequestInterceptionParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetRequestInterceptionParams() { }

  // Requests matching any of these patterns will be forwarded and wait for the corresponding
  // continueInterceptedRequest call.
  const std::vector<std::unique_ptr<::headless::network::RequestPattern>>* GetPatterns() const { return &patterns_; }
  void SetPatterns(std::vector<std::unique_ptr<::headless::network::RequestPattern>> value) { patterns_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetRequestInterceptionParams> Clone() const;

  template<int STATE>
  class SetRequestInterceptionParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPatternsSet = 1 << 1,
      kAllRequiredFieldsSet = (kPatternsSet | 0)
    };

    SetRequestInterceptionParamsBuilder<STATE | kPatternsSet>& SetPatterns(std::vector<std::unique_ptr<::headless::network::RequestPattern>> value) {
      static_assert(!(STATE & kPatternsSet), "property patterns should not have already been set");
      result_->SetPatterns(std::move(value));
      return CastState<kPatternsSet>();
    }

    std::unique_ptr<SetRequestInterceptionParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetRequestInterceptionParams;
    SetRequestInterceptionParamsBuilder() : result_(new SetRequestInterceptionParams()) { }

    template<int STEP> SetRequestInterceptionParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetRequestInterceptionParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetRequestInterceptionParams> result_;
  };

  static SetRequestInterceptionParamsBuilder<0> Builder() {
    return SetRequestInterceptionParamsBuilder<0>();
  }

 private:
  SetRequestInterceptionParams() { }

  std::vector<std::unique_ptr<::headless::network::RequestPattern>> patterns_;

  DISALLOW_COPY_AND_ASSIGN(SetRequestInterceptionParams);
};


// Result for the SetRequestInterception command.
class HEADLESS_EXPORT SetRequestInterceptionResult {
 public:
  static std::unique_ptr<SetRequestInterceptionResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetRequestInterceptionResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetRequestInterceptionResult> Clone() const;

  template<int STATE>
  class SetRequestInterceptionResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetRequestInterceptionResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetRequestInterceptionResult;
    SetRequestInterceptionResultBuilder() : result_(new SetRequestInterceptionResult()) { }

    template<int STEP> SetRequestInterceptionResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetRequestInterceptionResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetRequestInterceptionResult> result_;
  };

  static SetRequestInterceptionResultBuilder<0> Builder() {
    return SetRequestInterceptionResultBuilder<0>();
  }

 private:
  SetRequestInterceptionResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetRequestInterceptionResult);
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


// Parameters for the DataReceived event.
class HEADLESS_EXPORT DataReceivedParams {
 public:
  static std::unique_ptr<DataReceivedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DataReceivedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Data chunk length.
  int GetDataLength() const { return data_length_; }
  void SetDataLength(int value) { data_length_ = value; }

  // Actual bytes received (might be less than dataLength for compressed encodings).
  int GetEncodedDataLength() const { return encoded_data_length_; }
  void SetEncodedDataLength(int value) { encoded_data_length_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DataReceivedParams> Clone() const;

  template<int STATE>
  class DataReceivedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kDataLengthSet = 1 << 3,
    kEncodedDataLengthSet = 1 << 4,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kDataLengthSet | kEncodedDataLengthSet | 0)
    };

    DataReceivedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    DataReceivedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    DataReceivedParamsBuilder<STATE | kDataLengthSet>& SetDataLength(int value) {
      static_assert(!(STATE & kDataLengthSet), "property dataLength should not have already been set");
      result_->SetDataLength(value);
      return CastState<kDataLengthSet>();
    }

    DataReceivedParamsBuilder<STATE | kEncodedDataLengthSet>& SetEncodedDataLength(int value) {
      static_assert(!(STATE & kEncodedDataLengthSet), "property encodedDataLength should not have already been set");
      result_->SetEncodedDataLength(value);
      return CastState<kEncodedDataLengthSet>();
    }

    std::unique_ptr<DataReceivedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DataReceivedParams;
    DataReceivedParamsBuilder() : result_(new DataReceivedParams()) { }

    template<int STEP> DataReceivedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DataReceivedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DataReceivedParams> result_;
  };

  static DataReceivedParamsBuilder<0> Builder() {
    return DataReceivedParamsBuilder<0>();
  }

 private:
  DataReceivedParams() { }

  std::string request_id_;
  double timestamp_;
  int data_length_;
  int encoded_data_length_;

  DISALLOW_COPY_AND_ASSIGN(DataReceivedParams);
};


// Parameters for the EventSourceMessageReceived event.
class HEADLESS_EXPORT EventSourceMessageReceivedParams {
 public:
  static std::unique_ptr<EventSourceMessageReceivedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EventSourceMessageReceivedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Message type.
  std::string GetEventName() const { return event_name_; }
  void SetEventName(const std::string& value) { event_name_ = value; }

  // Message identifier.
  std::string GetEventId() const { return event_id_; }
  void SetEventId(const std::string& value) { event_id_ = value; }

  // Message content.
  std::string GetData() const { return data_; }
  void SetData(const std::string& value) { data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EventSourceMessageReceivedParams> Clone() const;

  template<int STATE>
  class EventSourceMessageReceivedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kEventNameSet = 1 << 3,
    kEventIdSet = 1 << 4,
    kDataSet = 1 << 5,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kEventNameSet | kEventIdSet | kDataSet | 0)
    };

    EventSourceMessageReceivedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    EventSourceMessageReceivedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    EventSourceMessageReceivedParamsBuilder<STATE | kEventNameSet>& SetEventName(const std::string& value) {
      static_assert(!(STATE & kEventNameSet), "property eventName should not have already been set");
      result_->SetEventName(value);
      return CastState<kEventNameSet>();
    }

    EventSourceMessageReceivedParamsBuilder<STATE | kEventIdSet>& SetEventId(const std::string& value) {
      static_assert(!(STATE & kEventIdSet), "property eventId should not have already been set");
      result_->SetEventId(value);
      return CastState<kEventIdSet>();
    }

    EventSourceMessageReceivedParamsBuilder<STATE | kDataSet>& SetData(const std::string& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    std::unique_ptr<EventSourceMessageReceivedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EventSourceMessageReceivedParams;
    EventSourceMessageReceivedParamsBuilder() : result_(new EventSourceMessageReceivedParams()) { }

    template<int STEP> EventSourceMessageReceivedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EventSourceMessageReceivedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EventSourceMessageReceivedParams> result_;
  };

  static EventSourceMessageReceivedParamsBuilder<0> Builder() {
    return EventSourceMessageReceivedParamsBuilder<0>();
  }

 private:
  EventSourceMessageReceivedParams() { }

  std::string request_id_;
  double timestamp_;
  std::string event_name_;
  std::string event_id_;
  std::string data_;

  DISALLOW_COPY_AND_ASSIGN(EventSourceMessageReceivedParams);
};


// Parameters for the LoadingFailed event.
class HEADLESS_EXPORT LoadingFailedParams {
 public:
  static std::unique_ptr<LoadingFailedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~LoadingFailedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Resource type.
  ::headless::network::ResourceType GetType() const { return type_; }
  void SetType(::headless::network::ResourceType value) { type_ = value; }

  // User friendly error message.
  std::string GetErrorText() const { return error_text_; }
  void SetErrorText(const std::string& value) { error_text_ = value; }

  // True if loading was canceled.
  bool HasCanceled() const { return !!canceled_; }
  bool GetCanceled() const { DCHECK(HasCanceled()); return canceled_.value(); }
  void SetCanceled(bool value) { canceled_ = value; }

  // The reason why loading was blocked, if any.
  bool HasBlockedReason() const { return !!blocked_reason_; }
  ::headless::network::BlockedReason GetBlockedReason() const { DCHECK(HasBlockedReason()); return blocked_reason_.value(); }
  void SetBlockedReason(::headless::network::BlockedReason value) { blocked_reason_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LoadingFailedParams> Clone() const;

  template<int STATE>
  class LoadingFailedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kTypeSet = 1 << 3,
    kErrorTextSet = 1 << 4,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kTypeSet | kErrorTextSet | 0)
    };

    LoadingFailedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    LoadingFailedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    LoadingFailedParamsBuilder<STATE | kTypeSet>& SetType(::headless::network::ResourceType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    LoadingFailedParamsBuilder<STATE | kErrorTextSet>& SetErrorText(const std::string& value) {
      static_assert(!(STATE & kErrorTextSet), "property errorText should not have already been set");
      result_->SetErrorText(value);
      return CastState<kErrorTextSet>();
    }

    LoadingFailedParamsBuilder<STATE>& SetCanceled(bool value) {
      result_->SetCanceled(value);
      return *this;
    }

    LoadingFailedParamsBuilder<STATE>& SetBlockedReason(::headless::network::BlockedReason value) {
      result_->SetBlockedReason(value);
      return *this;
    }

    std::unique_ptr<LoadingFailedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LoadingFailedParams;
    LoadingFailedParamsBuilder() : result_(new LoadingFailedParams()) { }

    template<int STEP> LoadingFailedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LoadingFailedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LoadingFailedParams> result_;
  };

  static LoadingFailedParamsBuilder<0> Builder() {
    return LoadingFailedParamsBuilder<0>();
  }

 private:
  LoadingFailedParams() { }

  std::string request_id_;
  double timestamp_;
  ::headless::network::ResourceType type_;
  std::string error_text_;
  base::Optional<bool> canceled_;
  base::Optional<::headless::network::BlockedReason> blocked_reason_;

  DISALLOW_COPY_AND_ASSIGN(LoadingFailedParams);
};


// Parameters for the LoadingFinished event.
class HEADLESS_EXPORT LoadingFinishedParams {
 public:
  static std::unique_ptr<LoadingFinishedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~LoadingFinishedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Total number of bytes received for this request.
  double GetEncodedDataLength() const { return encoded_data_length_; }
  void SetEncodedDataLength(double value) { encoded_data_length_ = value; }

  // Set when 1) response was blocked by Cross-Origin Read Blocking and also
  // 2) this needs to be reported to the DevTools console.
  bool HasShouldReportCorbBlocking() const { return !!should_report_corb_blocking_; }
  bool GetShouldReportCorbBlocking() const { DCHECK(HasShouldReportCorbBlocking()); return should_report_corb_blocking_.value(); }
  void SetShouldReportCorbBlocking(bool value) { should_report_corb_blocking_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LoadingFinishedParams> Clone() const;

  template<int STATE>
  class LoadingFinishedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kEncodedDataLengthSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kEncodedDataLengthSet | 0)
    };

    LoadingFinishedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    LoadingFinishedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    LoadingFinishedParamsBuilder<STATE | kEncodedDataLengthSet>& SetEncodedDataLength(double value) {
      static_assert(!(STATE & kEncodedDataLengthSet), "property encodedDataLength should not have already been set");
      result_->SetEncodedDataLength(value);
      return CastState<kEncodedDataLengthSet>();
    }

    LoadingFinishedParamsBuilder<STATE>& SetShouldReportCorbBlocking(bool value) {
      result_->SetShouldReportCorbBlocking(value);
      return *this;
    }

    std::unique_ptr<LoadingFinishedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LoadingFinishedParams;
    LoadingFinishedParamsBuilder() : result_(new LoadingFinishedParams()) { }

    template<int STEP> LoadingFinishedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LoadingFinishedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LoadingFinishedParams> result_;
  };

  static LoadingFinishedParamsBuilder<0> Builder() {
    return LoadingFinishedParamsBuilder<0>();
  }

 private:
  LoadingFinishedParams() { }

  std::string request_id_;
  double timestamp_;
  double encoded_data_length_;
  base::Optional<bool> should_report_corb_blocking_;

  DISALLOW_COPY_AND_ASSIGN(LoadingFinishedParams);
};


// Parameters for the RequestIntercepted event.
class HEADLESS_EXPORT RequestInterceptedParams {
 public:
  static std::unique_ptr<RequestInterceptedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestInterceptedParams() { }

  // Each request the page makes will have a unique id, however if any redirects are encountered
  // while processing that fetch, they will be reported with the same id as the original fetch.
  // Likewise if HTTP authentication is needed then the same fetch id will be used.
  std::string GetInterceptionId() const { return interception_id_; }
  void SetInterceptionId(const std::string& value) { interception_id_ = value; }

  const ::headless::network::Request* GetRequest() const { return request_.get(); }
  void SetRequest(std::unique_ptr<::headless::network::Request> value) { request_ = std::move(value); }

  // The id of the frame that initiated the request.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // How the requested resource will be used.
  ::headless::network::ResourceType GetResourceType() const { return resource_type_; }
  void SetResourceType(::headless::network::ResourceType value) { resource_type_ = value; }

  // Whether this is a navigation request, which can abort the navigation completely.
  bool GetIsNavigationRequest() const { return is_navigation_request_; }
  void SetIsNavigationRequest(bool value) { is_navigation_request_ = value; }

  // Set if the request is a navigation that will result in a download.
  // Only present after response is received from the server (i.e. HeadersReceived stage).
  bool HasIsDownload() const { return !!is_download_; }
  bool GetIsDownload() const { DCHECK(HasIsDownload()); return is_download_.value(); }
  void SetIsDownload(bool value) { is_download_ = value; }

  // Redirect location, only sent if a redirect was intercepted.
  bool HasRedirectUrl() const { return !!redirect_url_; }
  std::string GetRedirectUrl() const { DCHECK(HasRedirectUrl()); return redirect_url_.value(); }
  void SetRedirectUrl(const std::string& value) { redirect_url_ = value; }

  // Details of the Authorization Challenge encountered. If this is set then
  // continueInterceptedRequest must contain an authChallengeResponse.
  bool HasAuthChallenge() const { return !!auth_challenge_; }
  const ::headless::network::AuthChallenge* GetAuthChallenge() const { DCHECK(HasAuthChallenge()); return auth_challenge_.value().get(); }
  void SetAuthChallenge(std::unique_ptr<::headless::network::AuthChallenge> value) { auth_challenge_ = std::move(value); }

  // Response error if intercepted at response stage or if redirect occurred while intercepting
  // request.
  bool HasResponseErrorReason() const { return !!response_error_reason_; }
  ::headless::network::ErrorReason GetResponseErrorReason() const { DCHECK(HasResponseErrorReason()); return response_error_reason_.value(); }
  void SetResponseErrorReason(::headless::network::ErrorReason value) { response_error_reason_ = value; }

  // Response code if intercepted at response stage or if redirect occurred while intercepting
  // request or auth retry occurred.
  bool HasResponseStatusCode() const { return !!response_status_code_; }
  int GetResponseStatusCode() const { DCHECK(HasResponseStatusCode()); return response_status_code_.value(); }
  void SetResponseStatusCode(int value) { response_status_code_ = value; }

  // Response headers if intercepted at the response stage or if redirect occurred while
  // intercepting request or auth retry occurred.
  bool HasResponseHeaders() const { return !!response_headers_; }
  const base::DictionaryValue* GetResponseHeaders() const { DCHECK(HasResponseHeaders()); return response_headers_.value().get(); }
  void SetResponseHeaders(std::unique_ptr<base::DictionaryValue> value) { response_headers_ = std::move(value); }

  // If the intercepted request had a corresponding requestWillBeSent event fired for it, then
  // this requestId will be the same as the requestId present in the requestWillBeSent event.
  bool HasRequestId() const { return !!request_id_; }
  std::string GetRequestId() const { DCHECK(HasRequestId()); return request_id_.value(); }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestInterceptedParams> Clone() const;

  template<int STATE>
  class RequestInterceptedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kInterceptionIdSet = 1 << 1,
    kRequestSet = 1 << 2,
    kFrameIdSet = 1 << 3,
    kResourceTypeSet = 1 << 4,
    kIsNavigationRequestSet = 1 << 5,
      kAllRequiredFieldsSet = (kInterceptionIdSet | kRequestSet | kFrameIdSet | kResourceTypeSet | kIsNavigationRequestSet | 0)
    };

    RequestInterceptedParamsBuilder<STATE | kInterceptionIdSet>& SetInterceptionId(const std::string& value) {
      static_assert(!(STATE & kInterceptionIdSet), "property interceptionId should not have already been set");
      result_->SetInterceptionId(value);
      return CastState<kInterceptionIdSet>();
    }

    RequestInterceptedParamsBuilder<STATE | kRequestSet>& SetRequest(std::unique_ptr<::headless::network::Request> value) {
      static_assert(!(STATE & kRequestSet), "property request should not have already been set");
      result_->SetRequest(std::move(value));
      return CastState<kRequestSet>();
    }

    RequestInterceptedParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    RequestInterceptedParamsBuilder<STATE | kResourceTypeSet>& SetResourceType(::headless::network::ResourceType value) {
      static_assert(!(STATE & kResourceTypeSet), "property resourceType should not have already been set");
      result_->SetResourceType(value);
      return CastState<kResourceTypeSet>();
    }

    RequestInterceptedParamsBuilder<STATE | kIsNavigationRequestSet>& SetIsNavigationRequest(bool value) {
      static_assert(!(STATE & kIsNavigationRequestSet), "property isNavigationRequest should not have already been set");
      result_->SetIsNavigationRequest(value);
      return CastState<kIsNavigationRequestSet>();
    }

    RequestInterceptedParamsBuilder<STATE>& SetIsDownload(bool value) {
      result_->SetIsDownload(value);
      return *this;
    }

    RequestInterceptedParamsBuilder<STATE>& SetRedirectUrl(const std::string& value) {
      result_->SetRedirectUrl(value);
      return *this;
    }

    RequestInterceptedParamsBuilder<STATE>& SetAuthChallenge(std::unique_ptr<::headless::network::AuthChallenge> value) {
      result_->SetAuthChallenge(std::move(value));
      return *this;
    }

    RequestInterceptedParamsBuilder<STATE>& SetResponseErrorReason(::headless::network::ErrorReason value) {
      result_->SetResponseErrorReason(value);
      return *this;
    }

    RequestInterceptedParamsBuilder<STATE>& SetResponseStatusCode(int value) {
      result_->SetResponseStatusCode(value);
      return *this;
    }

    RequestInterceptedParamsBuilder<STATE>& SetResponseHeaders(std::unique_ptr<base::DictionaryValue> value) {
      result_->SetResponseHeaders(std::move(value));
      return *this;
    }

    RequestInterceptedParamsBuilder<STATE>& SetRequestId(const std::string& value) {
      result_->SetRequestId(value);
      return *this;
    }

    std::unique_ptr<RequestInterceptedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestInterceptedParams;
    RequestInterceptedParamsBuilder() : result_(new RequestInterceptedParams()) { }

    template<int STEP> RequestInterceptedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestInterceptedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestInterceptedParams> result_;
  };

  static RequestInterceptedParamsBuilder<0> Builder() {
    return RequestInterceptedParamsBuilder<0>();
  }

 private:
  RequestInterceptedParams() { }

  std::string interception_id_;
  std::unique_ptr<::headless::network::Request> request_;
  std::string frame_id_;
  ::headless::network::ResourceType resource_type_;
  bool is_navigation_request_;
  base::Optional<bool> is_download_;
  base::Optional<std::string> redirect_url_;
  base::Optional<std::unique_ptr<::headless::network::AuthChallenge>> auth_challenge_;
  base::Optional<::headless::network::ErrorReason> response_error_reason_;
  base::Optional<int> response_status_code_;
  base::Optional<std::unique_ptr<base::DictionaryValue>> response_headers_;
  base::Optional<std::string> request_id_;

  DISALLOW_COPY_AND_ASSIGN(RequestInterceptedParams);
};


// Parameters for the RequestServedFromCache event.
class HEADLESS_EXPORT RequestServedFromCacheParams {
 public:
  static std::unique_ptr<RequestServedFromCacheParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestServedFromCacheParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestServedFromCacheParams> Clone() const;

  template<int STATE>
  class RequestServedFromCacheParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kRequestIdSet | 0)
    };

    RequestServedFromCacheParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    std::unique_ptr<RequestServedFromCacheParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestServedFromCacheParams;
    RequestServedFromCacheParamsBuilder() : result_(new RequestServedFromCacheParams()) { }

    template<int STEP> RequestServedFromCacheParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestServedFromCacheParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestServedFromCacheParams> result_;
  };

  static RequestServedFromCacheParamsBuilder<0> Builder() {
    return RequestServedFromCacheParamsBuilder<0>();
  }

 private:
  RequestServedFromCacheParams() { }

  std::string request_id_;

  DISALLOW_COPY_AND_ASSIGN(RequestServedFromCacheParams);
};


// Parameters for the RequestWillBeSent event.
class HEADLESS_EXPORT RequestWillBeSentParams {
 public:
  static std::unique_ptr<RequestWillBeSentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestWillBeSentParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Loader identifier. Empty string if the request is fetched from worker.
  std::string GetLoaderId() const { return loader_id_; }
  void SetLoaderId(const std::string& value) { loader_id_ = value; }

  // URL of the document this request is loaded for.
  std::string GetDocumentURL() const { return documenturl_; }
  void SetDocumentURL(const std::string& value) { documenturl_ = value; }

  // Request data.
  const ::headless::network::Request* GetRequest() const { return request_.get(); }
  void SetRequest(std::unique_ptr<::headless::network::Request> value) { request_ = std::move(value); }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Timestamp.
  double GetWallTime() const { return wall_time_; }
  void SetWallTime(double value) { wall_time_ = value; }

  // Request initiator.
  const ::headless::network::Initiator* GetInitiator() const { return initiator_.get(); }
  void SetInitiator(std::unique_ptr<::headless::network::Initiator> value) { initiator_ = std::move(value); }

  // Redirect response data.
  bool HasRedirectResponse() const { return !!redirect_response_; }
  const ::headless::network::Response* GetRedirectResponse() const { DCHECK(HasRedirectResponse()); return redirect_response_.value().get(); }
  void SetRedirectResponse(std::unique_ptr<::headless::network::Response> value) { redirect_response_ = std::move(value); }

  // Type of this resource.
  bool HasType() const { return !!type_; }
  ::headless::network::ResourceType GetType() const { DCHECK(HasType()); return type_.value(); }
  void SetType(::headless::network::ResourceType value) { type_ = value; }

  // Frame identifier.
  bool HasFrameId() const { return !!frame_id_; }
  std::string GetFrameId() const { DCHECK(HasFrameId()); return frame_id_.value(); }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Whether the request is initiated by a user gesture. Defaults to false.
  bool HasHasUserGesture() const { return !!has_user_gesture_; }
  bool GetHasUserGesture() const { DCHECK(HasHasUserGesture()); return has_user_gesture_.value(); }
  void SetHasUserGesture(bool value) { has_user_gesture_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestWillBeSentParams> Clone() const;

  template<int STATE>
  class RequestWillBeSentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kLoaderIdSet = 1 << 2,
    kDocumentURLSet = 1 << 3,
    kRequestSet = 1 << 4,
    kTimestampSet = 1 << 5,
    kWallTimeSet = 1 << 6,
    kInitiatorSet = 1 << 7,
      kAllRequiredFieldsSet = (kRequestIdSet | kLoaderIdSet | kDocumentURLSet | kRequestSet | kTimestampSet | kWallTimeSet | kInitiatorSet | 0)
    };

    RequestWillBeSentParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    RequestWillBeSentParamsBuilder<STATE | kLoaderIdSet>& SetLoaderId(const std::string& value) {
      static_assert(!(STATE & kLoaderIdSet), "property loaderId should not have already been set");
      result_->SetLoaderId(value);
      return CastState<kLoaderIdSet>();
    }

    RequestWillBeSentParamsBuilder<STATE | kDocumentURLSet>& SetDocumentURL(const std::string& value) {
      static_assert(!(STATE & kDocumentURLSet), "property documentURL should not have already been set");
      result_->SetDocumentURL(value);
      return CastState<kDocumentURLSet>();
    }

    RequestWillBeSentParamsBuilder<STATE | kRequestSet>& SetRequest(std::unique_ptr<::headless::network::Request> value) {
      static_assert(!(STATE & kRequestSet), "property request should not have already been set");
      result_->SetRequest(std::move(value));
      return CastState<kRequestSet>();
    }

    RequestWillBeSentParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    RequestWillBeSentParamsBuilder<STATE | kWallTimeSet>& SetWallTime(double value) {
      static_assert(!(STATE & kWallTimeSet), "property wallTime should not have already been set");
      result_->SetWallTime(value);
      return CastState<kWallTimeSet>();
    }

    RequestWillBeSentParamsBuilder<STATE | kInitiatorSet>& SetInitiator(std::unique_ptr<::headless::network::Initiator> value) {
      static_assert(!(STATE & kInitiatorSet), "property initiator should not have already been set");
      result_->SetInitiator(std::move(value));
      return CastState<kInitiatorSet>();
    }

    RequestWillBeSentParamsBuilder<STATE>& SetRedirectResponse(std::unique_ptr<::headless::network::Response> value) {
      result_->SetRedirectResponse(std::move(value));
      return *this;
    }

    RequestWillBeSentParamsBuilder<STATE>& SetType(::headless::network::ResourceType value) {
      result_->SetType(value);
      return *this;
    }

    RequestWillBeSentParamsBuilder<STATE>& SetFrameId(const std::string& value) {
      result_->SetFrameId(value);
      return *this;
    }

    RequestWillBeSentParamsBuilder<STATE>& SetHasUserGesture(bool value) {
      result_->SetHasUserGesture(value);
      return *this;
    }

    std::unique_ptr<RequestWillBeSentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestWillBeSentParams;
    RequestWillBeSentParamsBuilder() : result_(new RequestWillBeSentParams()) { }

    template<int STEP> RequestWillBeSentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestWillBeSentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestWillBeSentParams> result_;
  };

  static RequestWillBeSentParamsBuilder<0> Builder() {
    return RequestWillBeSentParamsBuilder<0>();
  }

 private:
  RequestWillBeSentParams() { }

  std::string request_id_;
  std::string loader_id_;
  std::string documenturl_;
  std::unique_ptr<::headless::network::Request> request_;
  double timestamp_;
  double wall_time_;
  std::unique_ptr<::headless::network::Initiator> initiator_;
  base::Optional<std::unique_ptr<::headless::network::Response>> redirect_response_;
  base::Optional<::headless::network::ResourceType> type_;
  base::Optional<std::string> frame_id_;
  base::Optional<bool> has_user_gesture_;

  DISALLOW_COPY_AND_ASSIGN(RequestWillBeSentParams);
};


// Parameters for the ResourceChangedPriority event.
class HEADLESS_EXPORT ResourceChangedPriorityParams {
 public:
  static std::unique_ptr<ResourceChangedPriorityParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResourceChangedPriorityParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // New priority
  ::headless::network::ResourcePriority GetNewPriority() const { return new_priority_; }
  void SetNewPriority(::headless::network::ResourcePriority value) { new_priority_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResourceChangedPriorityParams> Clone() const;

  template<int STATE>
  class ResourceChangedPriorityParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kNewPrioritySet = 1 << 2,
    kTimestampSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kNewPrioritySet | kTimestampSet | 0)
    };

    ResourceChangedPriorityParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    ResourceChangedPriorityParamsBuilder<STATE | kNewPrioritySet>& SetNewPriority(::headless::network::ResourcePriority value) {
      static_assert(!(STATE & kNewPrioritySet), "property newPriority should not have already been set");
      result_->SetNewPriority(value);
      return CastState<kNewPrioritySet>();
    }

    ResourceChangedPriorityParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    std::unique_ptr<ResourceChangedPriorityParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResourceChangedPriorityParams;
    ResourceChangedPriorityParamsBuilder() : result_(new ResourceChangedPriorityParams()) { }

    template<int STEP> ResourceChangedPriorityParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResourceChangedPriorityParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResourceChangedPriorityParams> result_;
  };

  static ResourceChangedPriorityParamsBuilder<0> Builder() {
    return ResourceChangedPriorityParamsBuilder<0>();
  }

 private:
  ResourceChangedPriorityParams() { }

  std::string request_id_;
  ::headless::network::ResourcePriority new_priority_;
  double timestamp_;

  DISALLOW_COPY_AND_ASSIGN(ResourceChangedPriorityParams);
};


// Parameters for the SignedExchangeReceived event.
class HEADLESS_EXPORT SignedExchangeReceivedParams {
 public:
  static std::unique_ptr<SignedExchangeReceivedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SignedExchangeReceivedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Information about the signed exchange response.
  const ::headless::network::SignedExchangeInfo* GetInfo() const { return info_.get(); }
  void SetInfo(std::unique_ptr<::headless::network::SignedExchangeInfo> value) { info_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SignedExchangeReceivedParams> Clone() const;

  template<int STATE>
  class SignedExchangeReceivedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kInfoSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kInfoSet | 0)
    };

    SignedExchangeReceivedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    SignedExchangeReceivedParamsBuilder<STATE | kInfoSet>& SetInfo(std::unique_ptr<::headless::network::SignedExchangeInfo> value) {
      static_assert(!(STATE & kInfoSet), "property info should not have already been set");
      result_->SetInfo(std::move(value));
      return CastState<kInfoSet>();
    }

    std::unique_ptr<SignedExchangeReceivedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SignedExchangeReceivedParams;
    SignedExchangeReceivedParamsBuilder() : result_(new SignedExchangeReceivedParams()) { }

    template<int STEP> SignedExchangeReceivedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SignedExchangeReceivedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SignedExchangeReceivedParams> result_;
  };

  static SignedExchangeReceivedParamsBuilder<0> Builder() {
    return SignedExchangeReceivedParamsBuilder<0>();
  }

 private:
  SignedExchangeReceivedParams() { }

  std::string request_id_;
  std::unique_ptr<::headless::network::SignedExchangeInfo> info_;

  DISALLOW_COPY_AND_ASSIGN(SignedExchangeReceivedParams);
};


// Parameters for the ResponseReceived event.
class HEADLESS_EXPORT ResponseReceivedParams {
 public:
  static std::unique_ptr<ResponseReceivedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResponseReceivedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Loader identifier. Empty string if the request is fetched from worker.
  std::string GetLoaderId() const { return loader_id_; }
  void SetLoaderId(const std::string& value) { loader_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Resource type.
  ::headless::network::ResourceType GetType() const { return type_; }
  void SetType(::headless::network::ResourceType value) { type_ = value; }

  // Response data.
  const ::headless::network::Response* GetResponse() const { return response_.get(); }
  void SetResponse(std::unique_ptr<::headless::network::Response> value) { response_ = std::move(value); }

  // Frame identifier.
  bool HasFrameId() const { return !!frame_id_; }
  std::string GetFrameId() const { DCHECK(HasFrameId()); return frame_id_.value(); }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResponseReceivedParams> Clone() const;

  template<int STATE>
  class ResponseReceivedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kLoaderIdSet = 1 << 2,
    kTimestampSet = 1 << 3,
    kTypeSet = 1 << 4,
    kResponseSet = 1 << 5,
      kAllRequiredFieldsSet = (kRequestIdSet | kLoaderIdSet | kTimestampSet | kTypeSet | kResponseSet | 0)
    };

    ResponseReceivedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    ResponseReceivedParamsBuilder<STATE | kLoaderIdSet>& SetLoaderId(const std::string& value) {
      static_assert(!(STATE & kLoaderIdSet), "property loaderId should not have already been set");
      result_->SetLoaderId(value);
      return CastState<kLoaderIdSet>();
    }

    ResponseReceivedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    ResponseReceivedParamsBuilder<STATE | kTypeSet>& SetType(::headless::network::ResourceType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    ResponseReceivedParamsBuilder<STATE | kResponseSet>& SetResponse(std::unique_ptr<::headless::network::Response> value) {
      static_assert(!(STATE & kResponseSet), "property response should not have already been set");
      result_->SetResponse(std::move(value));
      return CastState<kResponseSet>();
    }

    ResponseReceivedParamsBuilder<STATE>& SetFrameId(const std::string& value) {
      result_->SetFrameId(value);
      return *this;
    }

    std::unique_ptr<ResponseReceivedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResponseReceivedParams;
    ResponseReceivedParamsBuilder() : result_(new ResponseReceivedParams()) { }

    template<int STEP> ResponseReceivedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResponseReceivedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResponseReceivedParams> result_;
  };

  static ResponseReceivedParamsBuilder<0> Builder() {
    return ResponseReceivedParamsBuilder<0>();
  }

 private:
  ResponseReceivedParams() { }

  std::string request_id_;
  std::string loader_id_;
  double timestamp_;
  ::headless::network::ResourceType type_;
  std::unique_ptr<::headless::network::Response> response_;
  base::Optional<std::string> frame_id_;

  DISALLOW_COPY_AND_ASSIGN(ResponseReceivedParams);
};


// Parameters for the WebSocketClosed event.
class HEADLESS_EXPORT WebSocketClosedParams {
 public:
  static std::unique_ptr<WebSocketClosedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketClosedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketClosedParams> Clone() const;

  template<int STATE>
  class WebSocketClosedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | 0)
    };

    WebSocketClosedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    WebSocketClosedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    std::unique_ptr<WebSocketClosedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketClosedParams;
    WebSocketClosedParamsBuilder() : result_(new WebSocketClosedParams()) { }

    template<int STEP> WebSocketClosedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketClosedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketClosedParams> result_;
  };

  static WebSocketClosedParamsBuilder<0> Builder() {
    return WebSocketClosedParamsBuilder<0>();
  }

 private:
  WebSocketClosedParams() { }

  std::string request_id_;
  double timestamp_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketClosedParams);
};


// Parameters for the WebSocketCreated event.
class HEADLESS_EXPORT WebSocketCreatedParams {
 public:
  static std::unique_ptr<WebSocketCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketCreatedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // WebSocket request URL.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Request initiator.
  bool HasInitiator() const { return !!initiator_; }
  const ::headless::network::Initiator* GetInitiator() const { DCHECK(HasInitiator()); return initiator_.value().get(); }
  void SetInitiator(std::unique_ptr<::headless::network::Initiator> value) { initiator_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketCreatedParams> Clone() const;

  template<int STATE>
  class WebSocketCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kUrlSet = 1 << 2,
      kAllRequiredFieldsSet = (kRequestIdSet | kUrlSet | 0)
    };

    WebSocketCreatedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    WebSocketCreatedParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    WebSocketCreatedParamsBuilder<STATE>& SetInitiator(std::unique_ptr<::headless::network::Initiator> value) {
      result_->SetInitiator(std::move(value));
      return *this;
    }

    std::unique_ptr<WebSocketCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketCreatedParams;
    WebSocketCreatedParamsBuilder() : result_(new WebSocketCreatedParams()) { }

    template<int STEP> WebSocketCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketCreatedParams> result_;
  };

  static WebSocketCreatedParamsBuilder<0> Builder() {
    return WebSocketCreatedParamsBuilder<0>();
  }

 private:
  WebSocketCreatedParams() { }

  std::string request_id_;
  std::string url_;
  base::Optional<std::unique_ptr<::headless::network::Initiator>> initiator_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketCreatedParams);
};


// Parameters for the WebSocketFrameError event.
class HEADLESS_EXPORT WebSocketFrameErrorParams {
 public:
  static std::unique_ptr<WebSocketFrameErrorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketFrameErrorParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // WebSocket error message.
  std::string GetErrorMessage() const { return error_message_; }
  void SetErrorMessage(const std::string& value) { error_message_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketFrameErrorParams> Clone() const;

  template<int STATE>
  class WebSocketFrameErrorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kErrorMessageSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kErrorMessageSet | 0)
    };

    WebSocketFrameErrorParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    WebSocketFrameErrorParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    WebSocketFrameErrorParamsBuilder<STATE | kErrorMessageSet>& SetErrorMessage(const std::string& value) {
      static_assert(!(STATE & kErrorMessageSet), "property errorMessage should not have already been set");
      result_->SetErrorMessage(value);
      return CastState<kErrorMessageSet>();
    }

    std::unique_ptr<WebSocketFrameErrorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketFrameErrorParams;
    WebSocketFrameErrorParamsBuilder() : result_(new WebSocketFrameErrorParams()) { }

    template<int STEP> WebSocketFrameErrorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketFrameErrorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketFrameErrorParams> result_;
  };

  static WebSocketFrameErrorParamsBuilder<0> Builder() {
    return WebSocketFrameErrorParamsBuilder<0>();
  }

 private:
  WebSocketFrameErrorParams() { }

  std::string request_id_;
  double timestamp_;
  std::string error_message_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketFrameErrorParams);
};


// Parameters for the WebSocketFrameReceived event.
class HEADLESS_EXPORT WebSocketFrameReceivedParams {
 public:
  static std::unique_ptr<WebSocketFrameReceivedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketFrameReceivedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // WebSocket response data.
  const ::headless::network::WebSocketFrame* GetResponse() const { return response_.get(); }
  void SetResponse(std::unique_ptr<::headless::network::WebSocketFrame> value) { response_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketFrameReceivedParams> Clone() const;

  template<int STATE>
  class WebSocketFrameReceivedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kResponseSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kResponseSet | 0)
    };

    WebSocketFrameReceivedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    WebSocketFrameReceivedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    WebSocketFrameReceivedParamsBuilder<STATE | kResponseSet>& SetResponse(std::unique_ptr<::headless::network::WebSocketFrame> value) {
      static_assert(!(STATE & kResponseSet), "property response should not have already been set");
      result_->SetResponse(std::move(value));
      return CastState<kResponseSet>();
    }

    std::unique_ptr<WebSocketFrameReceivedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketFrameReceivedParams;
    WebSocketFrameReceivedParamsBuilder() : result_(new WebSocketFrameReceivedParams()) { }

    template<int STEP> WebSocketFrameReceivedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketFrameReceivedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketFrameReceivedParams> result_;
  };

  static WebSocketFrameReceivedParamsBuilder<0> Builder() {
    return WebSocketFrameReceivedParamsBuilder<0>();
  }

 private:
  WebSocketFrameReceivedParams() { }

  std::string request_id_;
  double timestamp_;
  std::unique_ptr<::headless::network::WebSocketFrame> response_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketFrameReceivedParams);
};


// Parameters for the WebSocketFrameSent event.
class HEADLESS_EXPORT WebSocketFrameSentParams {
 public:
  static std::unique_ptr<WebSocketFrameSentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketFrameSentParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // WebSocket response data.
  const ::headless::network::WebSocketFrame* GetResponse() const { return response_.get(); }
  void SetResponse(std::unique_ptr<::headless::network::WebSocketFrame> value) { response_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketFrameSentParams> Clone() const;

  template<int STATE>
  class WebSocketFrameSentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kResponseSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kResponseSet | 0)
    };

    WebSocketFrameSentParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    WebSocketFrameSentParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    WebSocketFrameSentParamsBuilder<STATE | kResponseSet>& SetResponse(std::unique_ptr<::headless::network::WebSocketFrame> value) {
      static_assert(!(STATE & kResponseSet), "property response should not have already been set");
      result_->SetResponse(std::move(value));
      return CastState<kResponseSet>();
    }

    std::unique_ptr<WebSocketFrameSentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketFrameSentParams;
    WebSocketFrameSentParamsBuilder() : result_(new WebSocketFrameSentParams()) { }

    template<int STEP> WebSocketFrameSentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketFrameSentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketFrameSentParams> result_;
  };

  static WebSocketFrameSentParamsBuilder<0> Builder() {
    return WebSocketFrameSentParamsBuilder<0>();
  }

 private:
  WebSocketFrameSentParams() { }

  std::string request_id_;
  double timestamp_;
  std::unique_ptr<::headless::network::WebSocketFrame> response_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketFrameSentParams);
};


// Parameters for the WebSocketHandshakeResponseReceived event.
class HEADLESS_EXPORT WebSocketHandshakeResponseReceivedParams {
 public:
  static std::unique_ptr<WebSocketHandshakeResponseReceivedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketHandshakeResponseReceivedParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // WebSocket response data.
  const ::headless::network::WebSocketResponse* GetResponse() const { return response_.get(); }
  void SetResponse(std::unique_ptr<::headless::network::WebSocketResponse> value) { response_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketHandshakeResponseReceivedParams> Clone() const;

  template<int STATE>
  class WebSocketHandshakeResponseReceivedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kResponseSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kResponseSet | 0)
    };

    WebSocketHandshakeResponseReceivedParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    WebSocketHandshakeResponseReceivedParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    WebSocketHandshakeResponseReceivedParamsBuilder<STATE | kResponseSet>& SetResponse(std::unique_ptr<::headless::network::WebSocketResponse> value) {
      static_assert(!(STATE & kResponseSet), "property response should not have already been set");
      result_->SetResponse(std::move(value));
      return CastState<kResponseSet>();
    }

    std::unique_ptr<WebSocketHandshakeResponseReceivedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketHandshakeResponseReceivedParams;
    WebSocketHandshakeResponseReceivedParamsBuilder() : result_(new WebSocketHandshakeResponseReceivedParams()) { }

    template<int STEP> WebSocketHandshakeResponseReceivedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketHandshakeResponseReceivedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketHandshakeResponseReceivedParams> result_;
  };

  static WebSocketHandshakeResponseReceivedParamsBuilder<0> Builder() {
    return WebSocketHandshakeResponseReceivedParamsBuilder<0>();
  }

 private:
  WebSocketHandshakeResponseReceivedParams() { }

  std::string request_id_;
  double timestamp_;
  std::unique_ptr<::headless::network::WebSocketResponse> response_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketHandshakeResponseReceivedParams);
};


// Parameters for the WebSocketWillSendHandshakeRequest event.
class HEADLESS_EXPORT WebSocketWillSendHandshakeRequestParams {
 public:
  static std::unique_ptr<WebSocketWillSendHandshakeRequestParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WebSocketWillSendHandshakeRequestParams() { }

  // Request identifier.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // Timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // UTC Timestamp.
  double GetWallTime() const { return wall_time_; }
  void SetWallTime(double value) { wall_time_ = value; }

  // WebSocket request data.
  const ::headless::network::WebSocketRequest* GetRequest() const { return request_.get(); }
  void SetRequest(std::unique_ptr<::headless::network::WebSocketRequest> value) { request_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WebSocketWillSendHandshakeRequestParams> Clone() const;

  template<int STATE>
  class WebSocketWillSendHandshakeRequestParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kTimestampSet = 1 << 2,
    kWallTimeSet = 1 << 3,
    kRequestSet = 1 << 4,
      kAllRequiredFieldsSet = (kRequestIdSet | kTimestampSet | kWallTimeSet | kRequestSet | 0)
    };

    WebSocketWillSendHandshakeRequestParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    WebSocketWillSendHandshakeRequestParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    WebSocketWillSendHandshakeRequestParamsBuilder<STATE | kWallTimeSet>& SetWallTime(double value) {
      static_assert(!(STATE & kWallTimeSet), "property wallTime should not have already been set");
      result_->SetWallTime(value);
      return CastState<kWallTimeSet>();
    }

    WebSocketWillSendHandshakeRequestParamsBuilder<STATE | kRequestSet>& SetRequest(std::unique_ptr<::headless::network::WebSocketRequest> value) {
      static_assert(!(STATE & kRequestSet), "property request should not have already been set");
      result_->SetRequest(std::move(value));
      return CastState<kRequestSet>();
    }

    std::unique_ptr<WebSocketWillSendHandshakeRequestParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WebSocketWillSendHandshakeRequestParams;
    WebSocketWillSendHandshakeRequestParamsBuilder() : result_(new WebSocketWillSendHandshakeRequestParams()) { }

    template<int STEP> WebSocketWillSendHandshakeRequestParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WebSocketWillSendHandshakeRequestParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WebSocketWillSendHandshakeRequestParams> result_;
  };

  static WebSocketWillSendHandshakeRequestParamsBuilder<0> Builder() {
    return WebSocketWillSendHandshakeRequestParamsBuilder<0>();
  }

 private:
  WebSocketWillSendHandshakeRequestParams() { }

  std::string request_id_;
  double timestamp_;
  double wall_time_;
  std::unique_ptr<::headless::network::WebSocketRequest> request_;

  DISALLOW_COPY_AND_ASSIGN(WebSocketWillSendHandshakeRequestParams);
};


// Parameters for the RequestWillBeSentExtraInfo event.
class HEADLESS_EXPORT RequestWillBeSentExtraInfoParams {
 public:
  static std::unique_ptr<RequestWillBeSentExtraInfoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestWillBeSentExtraInfoParams() { }

  // Request identifier. Used to match this information to an existing requestWillBeSent event.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // A list of cookies potentially associated to the requested URL. This includes both cookies sent with
  // the request and the ones not sent; the latter are distinguished by having blockedReason field set.
  const std::vector<std::unique_ptr<::headless::network::BlockedCookieWithReason>>* GetAssociatedCookies() const { return &associated_cookies_; }
  void SetAssociatedCookies(std::vector<std::unique_ptr<::headless::network::BlockedCookieWithReason>> value) { associated_cookies_ = std::move(value); }

  // Raw request headers as they will be sent over the wire.
  const base::DictionaryValue* GetHeaders() const { return headers_.get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestWillBeSentExtraInfoParams> Clone() const;

  template<int STATE>
  class RequestWillBeSentExtraInfoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kAssociatedCookiesSet = 1 << 2,
    kHeadersSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kAssociatedCookiesSet | kHeadersSet | 0)
    };

    RequestWillBeSentExtraInfoParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    RequestWillBeSentExtraInfoParamsBuilder<STATE | kAssociatedCookiesSet>& SetAssociatedCookies(std::vector<std::unique_ptr<::headless::network::BlockedCookieWithReason>> value) {
      static_assert(!(STATE & kAssociatedCookiesSet), "property associatedCookies should not have already been set");
      result_->SetAssociatedCookies(std::move(value));
      return CastState<kAssociatedCookiesSet>();
    }

    RequestWillBeSentExtraInfoParamsBuilder<STATE | kHeadersSet>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kHeadersSet), "property headers should not have already been set");
      result_->SetHeaders(std::move(value));
      return CastState<kHeadersSet>();
    }

    std::unique_ptr<RequestWillBeSentExtraInfoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestWillBeSentExtraInfoParams;
    RequestWillBeSentExtraInfoParamsBuilder() : result_(new RequestWillBeSentExtraInfoParams()) { }

    template<int STEP> RequestWillBeSentExtraInfoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestWillBeSentExtraInfoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestWillBeSentExtraInfoParams> result_;
  };

  static RequestWillBeSentExtraInfoParamsBuilder<0> Builder() {
    return RequestWillBeSentExtraInfoParamsBuilder<0>();
  }

 private:
  RequestWillBeSentExtraInfoParams() { }

  std::string request_id_;
  std::vector<std::unique_ptr<::headless::network::BlockedCookieWithReason>> associated_cookies_;
  std::unique_ptr<base::DictionaryValue> headers_;

  DISALLOW_COPY_AND_ASSIGN(RequestWillBeSentExtraInfoParams);
};


// Parameters for the ResponseReceivedExtraInfo event.
class HEADLESS_EXPORT ResponseReceivedExtraInfoParams {
 public:
  static std::unique_ptr<ResponseReceivedExtraInfoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResponseReceivedExtraInfoParams() { }

  // Request identifier. Used to match this information to another responseReceived event.
  std::string GetRequestId() const { return request_id_; }
  void SetRequestId(const std::string& value) { request_id_ = value; }

  // A list of cookies which were not stored from the response along with the corresponding
  // reasons for blocking. The cookies here may not be valid due to syntax errors, which
  // are represented by the invalid cookie line string instead of a proper cookie.
  const std::vector<std::unique_ptr<::headless::network::BlockedSetCookieWithReason>>* GetBlockedCookies() const { return &blocked_cookies_; }
  void SetBlockedCookies(std::vector<std::unique_ptr<::headless::network::BlockedSetCookieWithReason>> value) { blocked_cookies_ = std::move(value); }

  // Raw response headers as they were received over the wire.
  const base::DictionaryValue* GetHeaders() const { return headers_.get(); }
  void SetHeaders(std::unique_ptr<base::DictionaryValue> value) { headers_ = std::move(value); }

  // Raw response header text as it was received over the wire. The raw text may not always be
  // available, such as in the case of HTTP/2 or QUIC.
  bool HasHeadersText() const { return !!headers_text_; }
  std::string GetHeadersText() const { DCHECK(HasHeadersText()); return headers_text_.value(); }
  void SetHeadersText(const std::string& value) { headers_text_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResponseReceivedExtraInfoParams> Clone() const;

  template<int STATE>
  class ResponseReceivedExtraInfoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRequestIdSet = 1 << 1,
    kBlockedCookiesSet = 1 << 2,
    kHeadersSet = 1 << 3,
      kAllRequiredFieldsSet = (kRequestIdSet | kBlockedCookiesSet | kHeadersSet | 0)
    };

    ResponseReceivedExtraInfoParamsBuilder<STATE | kRequestIdSet>& SetRequestId(const std::string& value) {
      static_assert(!(STATE & kRequestIdSet), "property requestId should not have already been set");
      result_->SetRequestId(value);
      return CastState<kRequestIdSet>();
    }

    ResponseReceivedExtraInfoParamsBuilder<STATE | kBlockedCookiesSet>& SetBlockedCookies(std::vector<std::unique_ptr<::headless::network::BlockedSetCookieWithReason>> value) {
      static_assert(!(STATE & kBlockedCookiesSet), "property blockedCookies should not have already been set");
      result_->SetBlockedCookies(std::move(value));
      return CastState<kBlockedCookiesSet>();
    }

    ResponseReceivedExtraInfoParamsBuilder<STATE | kHeadersSet>& SetHeaders(std::unique_ptr<base::DictionaryValue> value) {
      static_assert(!(STATE & kHeadersSet), "property headers should not have already been set");
      result_->SetHeaders(std::move(value));
      return CastState<kHeadersSet>();
    }

    ResponseReceivedExtraInfoParamsBuilder<STATE>& SetHeadersText(const std::string& value) {
      result_->SetHeadersText(value);
      return *this;
    }

    std::unique_ptr<ResponseReceivedExtraInfoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResponseReceivedExtraInfoParams;
    ResponseReceivedExtraInfoParamsBuilder() : result_(new ResponseReceivedExtraInfoParams()) { }

    template<int STEP> ResponseReceivedExtraInfoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResponseReceivedExtraInfoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResponseReceivedExtraInfoParams> result_;
  };

  static ResponseReceivedExtraInfoParamsBuilder<0> Builder() {
    return ResponseReceivedExtraInfoParamsBuilder<0>();
  }

 private:
  ResponseReceivedExtraInfoParams() { }

  std::string request_id_;
  std::vector<std::unique_ptr<::headless::network::BlockedSetCookieWithReason>> blocked_cookies_;
  std::unique_ptr<base::DictionaryValue> headers_;
  base::Optional<std::string> headers_text_;

  DISALLOW_COPY_AND_ASSIGN(ResponseReceivedExtraInfoParams);
};


}  // namespace network

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_NETWORK_H_
