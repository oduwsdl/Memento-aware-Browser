// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_SECURITY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_SECURITY_H_

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

namespace security {

// Details about the security state of the page certificate.
class HEADLESS_EXPORT CertificateSecurityState {
 public:
  static std::unique_ptr<CertificateSecurityState> Parse(const base::Value& value, ErrorReporter* errors);
  ~CertificateSecurityState() { }

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

  // Page certificate.
  const std::vector<std::string>* GetCertificate() const { return &certificate_; }
  void SetCertificate(std::vector<std::string> value) { certificate_ = std::move(value); }

  // Certificate subject name.
  std::string GetSubjectName() const { return subject_name_; }
  void SetSubjectName(const std::string& value) { subject_name_ = value; }

  // Name of the issuing CA.
  std::string GetIssuer() const { return issuer_; }
  void SetIssuer(const std::string& value) { issuer_ = value; }

  // Certificate valid from date.
  double GetValidFrom() const { return valid_from_; }
  void SetValidFrom(double value) { valid_from_ = value; }

  // Certificate valid to (expiration) date
  double GetValidTo() const { return valid_to_; }
  void SetValidTo(double value) { valid_to_ = value; }

  // The highest priority network error code, if the certificate has an error.
  bool HasCertificateNetworkError() const { return !!certificate_network_error_; }
  std::string GetCertificateNetworkError() const { DCHECK(HasCertificateNetworkError()); return certificate_network_error_.value(); }
  void SetCertificateNetworkError(const std::string& value) { certificate_network_error_ = value; }

  // True if the certificate uses a weak signature aglorithm.
  bool GetCertificateHasWeakSignature() const { return certificate_has_weak_signature_; }
  void SetCertificateHasWeakSignature(bool value) { certificate_has_weak_signature_ = value; }

  // True if the certificate has a SHA1 signature in the chain.
  bool GetCertificateHasSha1Signature() const { return certificate_has_sha1_signature_; }
  void SetCertificateHasSha1Signature(bool value) { certificate_has_sha1_signature_ = value; }

  // True if modern SSL
  bool GetModernSSL() const { return modernssl_; }
  void SetModernSSL(bool value) { modernssl_ = value; }

  // True if the connection is using an obsolete SSL protocol.
  bool GetObsoleteSslProtocol() const { return obsolete_ssl_protocol_; }
  void SetObsoleteSslProtocol(bool value) { obsolete_ssl_protocol_ = value; }

  // True if the connection is using an obsolete SSL key exchange.
  bool GetObsoleteSslKeyExchange() const { return obsolete_ssl_key_exchange_; }
  void SetObsoleteSslKeyExchange(bool value) { obsolete_ssl_key_exchange_ = value; }

  // True if the connection is using an obsolete SSL cipher.
  bool GetObsoleteSslCipher() const { return obsolete_ssl_cipher_; }
  void SetObsoleteSslCipher(bool value) { obsolete_ssl_cipher_ = value; }

  // True if the connection is using an obsolete SSL signature.
  bool GetObsoleteSslSignature() const { return obsolete_ssl_signature_; }
  void SetObsoleteSslSignature(bool value) { obsolete_ssl_signature_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CertificateSecurityState> Clone() const;

  template<int STATE>
  class CertificateSecurityStateBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProtocolSet = 1 << 1,
    kKeyExchangeSet = 1 << 2,
    kCipherSet = 1 << 3,
    kCertificateSet = 1 << 4,
    kSubjectNameSet = 1 << 5,
    kIssuerSet = 1 << 6,
    kValidFromSet = 1 << 7,
    kValidToSet = 1 << 8,
    kCertificateHasWeakSignatureSet = 1 << 9,
    kCertificateHasSha1SignatureSet = 1 << 10,
    kModernSSLSet = 1 << 11,
    kObsoleteSslProtocolSet = 1 << 12,
    kObsoleteSslKeyExchangeSet = 1 << 13,
    kObsoleteSslCipherSet = 1 << 14,
    kObsoleteSslSignatureSet = 1 << 15,
      kAllRequiredFieldsSet = (kProtocolSet | kKeyExchangeSet | kCipherSet | kCertificateSet | kSubjectNameSet | kIssuerSet | kValidFromSet | kValidToSet | kCertificateHasWeakSignatureSet | kCertificateHasSha1SignatureSet | kModernSSLSet | kObsoleteSslProtocolSet | kObsoleteSslKeyExchangeSet | kObsoleteSslCipherSet | kObsoleteSslSignatureSet | 0)
    };

    CertificateSecurityStateBuilder<STATE | kProtocolSet>& SetProtocol(const std::string& value) {
      static_assert(!(STATE & kProtocolSet), "property protocol should not have already been set");
      result_->SetProtocol(value);
      return CastState<kProtocolSet>();
    }

    CertificateSecurityStateBuilder<STATE | kKeyExchangeSet>& SetKeyExchange(const std::string& value) {
      static_assert(!(STATE & kKeyExchangeSet), "property keyExchange should not have already been set");
      result_->SetKeyExchange(value);
      return CastState<kKeyExchangeSet>();
    }

    CertificateSecurityStateBuilder<STATE>& SetKeyExchangeGroup(const std::string& value) {
      result_->SetKeyExchangeGroup(value);
      return *this;
    }

    CertificateSecurityStateBuilder<STATE | kCipherSet>& SetCipher(const std::string& value) {
      static_assert(!(STATE & kCipherSet), "property cipher should not have already been set");
      result_->SetCipher(value);
      return CastState<kCipherSet>();
    }

    CertificateSecurityStateBuilder<STATE>& SetMac(const std::string& value) {
      result_->SetMac(value);
      return *this;
    }

    CertificateSecurityStateBuilder<STATE | kCertificateSet>& SetCertificate(std::vector<std::string> value) {
      static_assert(!(STATE & kCertificateSet), "property certificate should not have already been set");
      result_->SetCertificate(std::move(value));
      return CastState<kCertificateSet>();
    }

    CertificateSecurityStateBuilder<STATE | kSubjectNameSet>& SetSubjectName(const std::string& value) {
      static_assert(!(STATE & kSubjectNameSet), "property subjectName should not have already been set");
      result_->SetSubjectName(value);
      return CastState<kSubjectNameSet>();
    }

    CertificateSecurityStateBuilder<STATE | kIssuerSet>& SetIssuer(const std::string& value) {
      static_assert(!(STATE & kIssuerSet), "property issuer should not have already been set");
      result_->SetIssuer(value);
      return CastState<kIssuerSet>();
    }

    CertificateSecurityStateBuilder<STATE | kValidFromSet>& SetValidFrom(double value) {
      static_assert(!(STATE & kValidFromSet), "property validFrom should not have already been set");
      result_->SetValidFrom(value);
      return CastState<kValidFromSet>();
    }

    CertificateSecurityStateBuilder<STATE | kValidToSet>& SetValidTo(double value) {
      static_assert(!(STATE & kValidToSet), "property validTo should not have already been set");
      result_->SetValidTo(value);
      return CastState<kValidToSet>();
    }

    CertificateSecurityStateBuilder<STATE>& SetCertificateNetworkError(const std::string& value) {
      result_->SetCertificateNetworkError(value);
      return *this;
    }

    CertificateSecurityStateBuilder<STATE | kCertificateHasWeakSignatureSet>& SetCertificateHasWeakSignature(bool value) {
      static_assert(!(STATE & kCertificateHasWeakSignatureSet), "property certificateHasWeakSignature should not have already been set");
      result_->SetCertificateHasWeakSignature(value);
      return CastState<kCertificateHasWeakSignatureSet>();
    }

    CertificateSecurityStateBuilder<STATE | kCertificateHasSha1SignatureSet>& SetCertificateHasSha1Signature(bool value) {
      static_assert(!(STATE & kCertificateHasSha1SignatureSet), "property certificateHasSha1Signature should not have already been set");
      result_->SetCertificateHasSha1Signature(value);
      return CastState<kCertificateHasSha1SignatureSet>();
    }

    CertificateSecurityStateBuilder<STATE | kModernSSLSet>& SetModernSSL(bool value) {
      static_assert(!(STATE & kModernSSLSet), "property modernSSL should not have already been set");
      result_->SetModernSSL(value);
      return CastState<kModernSSLSet>();
    }

    CertificateSecurityStateBuilder<STATE | kObsoleteSslProtocolSet>& SetObsoleteSslProtocol(bool value) {
      static_assert(!(STATE & kObsoleteSslProtocolSet), "property obsoleteSslProtocol should not have already been set");
      result_->SetObsoleteSslProtocol(value);
      return CastState<kObsoleteSslProtocolSet>();
    }

    CertificateSecurityStateBuilder<STATE | kObsoleteSslKeyExchangeSet>& SetObsoleteSslKeyExchange(bool value) {
      static_assert(!(STATE & kObsoleteSslKeyExchangeSet), "property obsoleteSslKeyExchange should not have already been set");
      result_->SetObsoleteSslKeyExchange(value);
      return CastState<kObsoleteSslKeyExchangeSet>();
    }

    CertificateSecurityStateBuilder<STATE | kObsoleteSslCipherSet>& SetObsoleteSslCipher(bool value) {
      static_assert(!(STATE & kObsoleteSslCipherSet), "property obsoleteSslCipher should not have already been set");
      result_->SetObsoleteSslCipher(value);
      return CastState<kObsoleteSslCipherSet>();
    }

    CertificateSecurityStateBuilder<STATE | kObsoleteSslSignatureSet>& SetObsoleteSslSignature(bool value) {
      static_assert(!(STATE & kObsoleteSslSignatureSet), "property obsoleteSslSignature should not have already been set");
      result_->SetObsoleteSslSignature(value);
      return CastState<kObsoleteSslSignatureSet>();
    }

    std::unique_ptr<CertificateSecurityState> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CertificateSecurityState;
    CertificateSecurityStateBuilder() : result_(new CertificateSecurityState()) { }

    template<int STEP> CertificateSecurityStateBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CertificateSecurityStateBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CertificateSecurityState> result_;
  };

  static CertificateSecurityStateBuilder<0> Builder() {
    return CertificateSecurityStateBuilder<0>();
  }

 private:
  CertificateSecurityState() { }

  std::string protocol_;
  std::string key_exchange_;
  base::Optional<std::string> key_exchange_group_;
  std::string cipher_;
  base::Optional<std::string> mac_;
  std::vector<std::string> certificate_;
  std::string subject_name_;
  std::string issuer_;
  double valid_from_;
  double valid_to_;
  base::Optional<std::string> certificate_network_error_;
  bool certificate_has_weak_signature_;
  bool certificate_has_sha1_signature_;
  bool modernssl_;
  bool obsolete_ssl_protocol_;
  bool obsolete_ssl_key_exchange_;
  bool obsolete_ssl_cipher_;
  bool obsolete_ssl_signature_;

  DISALLOW_COPY_AND_ASSIGN(CertificateSecurityState);
};


class HEADLESS_EXPORT SafetyTipInfo {
 public:
  static std::unique_ptr<SafetyTipInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~SafetyTipInfo() { }

  // Describes whether the page triggers any safety tips or reputation warnings. Default is unknown.
  ::headless::security::SafetyTipStatus GetSafetyTipStatus() const { return safety_tip_status_; }
  void SetSafetyTipStatus(::headless::security::SafetyTipStatus value) { safety_tip_status_ = value; }

  // The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches.
  bool HasSafeUrl() const { return !!safe_url_; }
  std::string GetSafeUrl() const { DCHECK(HasSafeUrl()); return safe_url_.value(); }
  void SetSafeUrl(const std::string& value) { safe_url_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SafetyTipInfo> Clone() const;

  template<int STATE>
  class SafetyTipInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSafetyTipStatusSet = 1 << 1,
      kAllRequiredFieldsSet = (kSafetyTipStatusSet | 0)
    };

    SafetyTipInfoBuilder<STATE | kSafetyTipStatusSet>& SetSafetyTipStatus(::headless::security::SafetyTipStatus value) {
      static_assert(!(STATE & kSafetyTipStatusSet), "property safetyTipStatus should not have already been set");
      result_->SetSafetyTipStatus(value);
      return CastState<kSafetyTipStatusSet>();
    }

    SafetyTipInfoBuilder<STATE>& SetSafeUrl(const std::string& value) {
      result_->SetSafeUrl(value);
      return *this;
    }

    std::unique_ptr<SafetyTipInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SafetyTipInfo;
    SafetyTipInfoBuilder() : result_(new SafetyTipInfo()) { }

    template<int STEP> SafetyTipInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SafetyTipInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SafetyTipInfo> result_;
  };

  static SafetyTipInfoBuilder<0> Builder() {
    return SafetyTipInfoBuilder<0>();
  }

 private:
  SafetyTipInfo() { }

  ::headless::security::SafetyTipStatus safety_tip_status_;
  base::Optional<std::string> safe_url_;

  DISALLOW_COPY_AND_ASSIGN(SafetyTipInfo);
};


// Security state information about the page.
class HEADLESS_EXPORT VisibleSecurityState {
 public:
  static std::unique_ptr<VisibleSecurityState> Parse(const base::Value& value, ErrorReporter* errors);
  ~VisibleSecurityState() { }

  // The security level of the page.
  ::headless::security::SecurityState GetSecurityState() const { return security_state_; }
  void SetSecurityState(::headless::security::SecurityState value) { security_state_ = value; }

  // Security state details about the page certificate.
  bool HasCertificateSecurityState() const { return !!certificate_security_state_; }
  const ::headless::security::CertificateSecurityState* GetCertificateSecurityState() const { DCHECK(HasCertificateSecurityState()); return certificate_security_state_.value().get(); }
  void SetCertificateSecurityState(std::unique_ptr<::headless::security::CertificateSecurityState> value) { certificate_security_state_ = std::move(value); }

  // The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown.
  bool HasSafetyTipInfo() const { return !!safety_tip_info_; }
  const ::headless::security::SafetyTipInfo* GetSafetyTipInfo() const { DCHECK(HasSafetyTipInfo()); return safety_tip_info_.value().get(); }
  void SetSafetyTipInfo(std::unique_ptr<::headless::security::SafetyTipInfo> value) { safety_tip_info_ = std::move(value); }

  // Array of security state issues ids.
  const std::vector<std::string>* GetSecurityStateIssueIds() const { return &security_state_issue_ids_; }
  void SetSecurityStateIssueIds(std::vector<std::string> value) { security_state_issue_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<VisibleSecurityState> Clone() const;

  template<int STATE>
  class VisibleSecurityStateBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityStateSet = 1 << 1,
    kSecurityStateIssueIdsSet = 1 << 2,
      kAllRequiredFieldsSet = (kSecurityStateSet | kSecurityStateIssueIdsSet | 0)
    };

    VisibleSecurityStateBuilder<STATE | kSecurityStateSet>& SetSecurityState(::headless::security::SecurityState value) {
      static_assert(!(STATE & kSecurityStateSet), "property securityState should not have already been set");
      result_->SetSecurityState(value);
      return CastState<kSecurityStateSet>();
    }

    VisibleSecurityStateBuilder<STATE>& SetCertificateSecurityState(std::unique_ptr<::headless::security::CertificateSecurityState> value) {
      result_->SetCertificateSecurityState(std::move(value));
      return *this;
    }

    VisibleSecurityStateBuilder<STATE>& SetSafetyTipInfo(std::unique_ptr<::headless::security::SafetyTipInfo> value) {
      result_->SetSafetyTipInfo(std::move(value));
      return *this;
    }

    VisibleSecurityStateBuilder<STATE | kSecurityStateIssueIdsSet>& SetSecurityStateIssueIds(std::vector<std::string> value) {
      static_assert(!(STATE & kSecurityStateIssueIdsSet), "property securityStateIssueIds should not have already been set");
      result_->SetSecurityStateIssueIds(std::move(value));
      return CastState<kSecurityStateIssueIdsSet>();
    }

    std::unique_ptr<VisibleSecurityState> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class VisibleSecurityState;
    VisibleSecurityStateBuilder() : result_(new VisibleSecurityState()) { }

    template<int STEP> VisibleSecurityStateBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<VisibleSecurityStateBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<VisibleSecurityState> result_;
  };

  static VisibleSecurityStateBuilder<0> Builder() {
    return VisibleSecurityStateBuilder<0>();
  }

 private:
  VisibleSecurityState() { }

  ::headless::security::SecurityState security_state_;
  base::Optional<std::unique_ptr<::headless::security::CertificateSecurityState>> certificate_security_state_;
  base::Optional<std::unique_ptr<::headless::security::SafetyTipInfo>> safety_tip_info_;
  std::vector<std::string> security_state_issue_ids_;

  DISALLOW_COPY_AND_ASSIGN(VisibleSecurityState);
};


// An explanation of an factor contributing to the security state.
class HEADLESS_EXPORT SecurityStateExplanation {
 public:
  static std::unique_ptr<SecurityStateExplanation> Parse(const base::Value& value, ErrorReporter* errors);
  ~SecurityStateExplanation() { }

  // Security state representing the severity of the factor being explained.
  ::headless::security::SecurityState GetSecurityState() const { return security_state_; }
  void SetSecurityState(::headless::security::SecurityState value) { security_state_ = value; }

  // Title describing the type of factor.
  std::string GetTitle() const { return title_; }
  void SetTitle(const std::string& value) { title_ = value; }

  // Short phrase describing the type of factor.
  std::string GetSummary() const { return summary_; }
  void SetSummary(const std::string& value) { summary_ = value; }

  // Full text explanation of the factor.
  std::string GetDescription() const { return description_; }
  void SetDescription(const std::string& value) { description_ = value; }

  // The type of mixed content described by the explanation.
  ::headless::security::MixedContentType GetMixedContentType() const { return mixed_content_type_; }
  void SetMixedContentType(::headless::security::MixedContentType value) { mixed_content_type_ = value; }

  // Page certificate.
  const std::vector<std::string>* GetCertificate() const { return &certificate_; }
  void SetCertificate(std::vector<std::string> value) { certificate_ = std::move(value); }

  // Recommendations to fix any issues.
  bool HasRecommendations() const { return !!recommendations_; }
  const std::vector<std::string>* GetRecommendations() const { DCHECK(HasRecommendations()); return &recommendations_.value(); }
  void SetRecommendations(std::vector<std::string> value) { recommendations_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SecurityStateExplanation> Clone() const;

  template<int STATE>
  class SecurityStateExplanationBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityStateSet = 1 << 1,
    kTitleSet = 1 << 2,
    kSummarySet = 1 << 3,
    kDescriptionSet = 1 << 4,
    kMixedContentTypeSet = 1 << 5,
    kCertificateSet = 1 << 6,
      kAllRequiredFieldsSet = (kSecurityStateSet | kTitleSet | kSummarySet | kDescriptionSet | kMixedContentTypeSet | kCertificateSet | 0)
    };

    SecurityStateExplanationBuilder<STATE | kSecurityStateSet>& SetSecurityState(::headless::security::SecurityState value) {
      static_assert(!(STATE & kSecurityStateSet), "property securityState should not have already been set");
      result_->SetSecurityState(value);
      return CastState<kSecurityStateSet>();
    }

    SecurityStateExplanationBuilder<STATE | kTitleSet>& SetTitle(const std::string& value) {
      static_assert(!(STATE & kTitleSet), "property title should not have already been set");
      result_->SetTitle(value);
      return CastState<kTitleSet>();
    }

    SecurityStateExplanationBuilder<STATE | kSummarySet>& SetSummary(const std::string& value) {
      static_assert(!(STATE & kSummarySet), "property summary should not have already been set");
      result_->SetSummary(value);
      return CastState<kSummarySet>();
    }

    SecurityStateExplanationBuilder<STATE | kDescriptionSet>& SetDescription(const std::string& value) {
      static_assert(!(STATE & kDescriptionSet), "property description should not have already been set");
      result_->SetDescription(value);
      return CastState<kDescriptionSet>();
    }

    SecurityStateExplanationBuilder<STATE | kMixedContentTypeSet>& SetMixedContentType(::headless::security::MixedContentType value) {
      static_assert(!(STATE & kMixedContentTypeSet), "property mixedContentType should not have already been set");
      result_->SetMixedContentType(value);
      return CastState<kMixedContentTypeSet>();
    }

    SecurityStateExplanationBuilder<STATE | kCertificateSet>& SetCertificate(std::vector<std::string> value) {
      static_assert(!(STATE & kCertificateSet), "property certificate should not have already been set");
      result_->SetCertificate(std::move(value));
      return CastState<kCertificateSet>();
    }

    SecurityStateExplanationBuilder<STATE>& SetRecommendations(std::vector<std::string> value) {
      result_->SetRecommendations(std::move(value));
      return *this;
    }

    std::unique_ptr<SecurityStateExplanation> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SecurityStateExplanation;
    SecurityStateExplanationBuilder() : result_(new SecurityStateExplanation()) { }

    template<int STEP> SecurityStateExplanationBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SecurityStateExplanationBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SecurityStateExplanation> result_;
  };

  static SecurityStateExplanationBuilder<0> Builder() {
    return SecurityStateExplanationBuilder<0>();
  }

 private:
  SecurityStateExplanation() { }

  ::headless::security::SecurityState security_state_;
  std::string title_;
  std::string summary_;
  std::string description_;
  ::headless::security::MixedContentType mixed_content_type_;
  std::vector<std::string> certificate_;
  base::Optional<std::vector<std::string>> recommendations_;

  DISALLOW_COPY_AND_ASSIGN(SecurityStateExplanation);
};


// Information about insecure content on the page.
class HEADLESS_EXPORT InsecureContentStatus {
 public:
  static std::unique_ptr<InsecureContentStatus> Parse(const base::Value& value, ErrorReporter* errors);
  ~InsecureContentStatus() { }

  // Always false.
  bool GetRanMixedContent() const { return ran_mixed_content_; }
  void SetRanMixedContent(bool value) { ran_mixed_content_ = value; }

  // Always false.
  bool GetDisplayedMixedContent() const { return displayed_mixed_content_; }
  void SetDisplayedMixedContent(bool value) { displayed_mixed_content_ = value; }

  // Always false.
  bool GetContainedMixedForm() const { return contained_mixed_form_; }
  void SetContainedMixedForm(bool value) { contained_mixed_form_ = value; }

  // Always false.
  bool GetRanContentWithCertErrors() const { return ran_content_with_cert_errors_; }
  void SetRanContentWithCertErrors(bool value) { ran_content_with_cert_errors_ = value; }

  // Always false.
  bool GetDisplayedContentWithCertErrors() const { return displayed_content_with_cert_errors_; }
  void SetDisplayedContentWithCertErrors(bool value) { displayed_content_with_cert_errors_ = value; }

  // Always set to unknown.
  ::headless::security::SecurityState GetRanInsecureContentStyle() const { return ran_insecure_content_style_; }
  void SetRanInsecureContentStyle(::headless::security::SecurityState value) { ran_insecure_content_style_ = value; }

  // Always set to unknown.
  ::headless::security::SecurityState GetDisplayedInsecureContentStyle() const { return displayed_insecure_content_style_; }
  void SetDisplayedInsecureContentStyle(::headless::security::SecurityState value) { displayed_insecure_content_style_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InsecureContentStatus> Clone() const;

  template<int STATE>
  class InsecureContentStatusBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRanMixedContentSet = 1 << 1,
    kDisplayedMixedContentSet = 1 << 2,
    kContainedMixedFormSet = 1 << 3,
    kRanContentWithCertErrorsSet = 1 << 4,
    kDisplayedContentWithCertErrorsSet = 1 << 5,
    kRanInsecureContentStyleSet = 1 << 6,
    kDisplayedInsecureContentStyleSet = 1 << 7,
      kAllRequiredFieldsSet = (kRanMixedContentSet | kDisplayedMixedContentSet | kContainedMixedFormSet | kRanContentWithCertErrorsSet | kDisplayedContentWithCertErrorsSet | kRanInsecureContentStyleSet | kDisplayedInsecureContentStyleSet | 0)
    };

    InsecureContentStatusBuilder<STATE | kRanMixedContentSet>& SetRanMixedContent(bool value) {
      static_assert(!(STATE & kRanMixedContentSet), "property ranMixedContent should not have already been set");
      result_->SetRanMixedContent(value);
      return CastState<kRanMixedContentSet>();
    }

    InsecureContentStatusBuilder<STATE | kDisplayedMixedContentSet>& SetDisplayedMixedContent(bool value) {
      static_assert(!(STATE & kDisplayedMixedContentSet), "property displayedMixedContent should not have already been set");
      result_->SetDisplayedMixedContent(value);
      return CastState<kDisplayedMixedContentSet>();
    }

    InsecureContentStatusBuilder<STATE | kContainedMixedFormSet>& SetContainedMixedForm(bool value) {
      static_assert(!(STATE & kContainedMixedFormSet), "property containedMixedForm should not have already been set");
      result_->SetContainedMixedForm(value);
      return CastState<kContainedMixedFormSet>();
    }

    InsecureContentStatusBuilder<STATE | kRanContentWithCertErrorsSet>& SetRanContentWithCertErrors(bool value) {
      static_assert(!(STATE & kRanContentWithCertErrorsSet), "property ranContentWithCertErrors should not have already been set");
      result_->SetRanContentWithCertErrors(value);
      return CastState<kRanContentWithCertErrorsSet>();
    }

    InsecureContentStatusBuilder<STATE | kDisplayedContentWithCertErrorsSet>& SetDisplayedContentWithCertErrors(bool value) {
      static_assert(!(STATE & kDisplayedContentWithCertErrorsSet), "property displayedContentWithCertErrors should not have already been set");
      result_->SetDisplayedContentWithCertErrors(value);
      return CastState<kDisplayedContentWithCertErrorsSet>();
    }

    InsecureContentStatusBuilder<STATE | kRanInsecureContentStyleSet>& SetRanInsecureContentStyle(::headless::security::SecurityState value) {
      static_assert(!(STATE & kRanInsecureContentStyleSet), "property ranInsecureContentStyle should not have already been set");
      result_->SetRanInsecureContentStyle(value);
      return CastState<kRanInsecureContentStyleSet>();
    }

    InsecureContentStatusBuilder<STATE | kDisplayedInsecureContentStyleSet>& SetDisplayedInsecureContentStyle(::headless::security::SecurityState value) {
      static_assert(!(STATE & kDisplayedInsecureContentStyleSet), "property displayedInsecureContentStyle should not have already been set");
      result_->SetDisplayedInsecureContentStyle(value);
      return CastState<kDisplayedInsecureContentStyleSet>();
    }

    std::unique_ptr<InsecureContentStatus> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InsecureContentStatus;
    InsecureContentStatusBuilder() : result_(new InsecureContentStatus()) { }

    template<int STEP> InsecureContentStatusBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InsecureContentStatusBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InsecureContentStatus> result_;
  };

  static InsecureContentStatusBuilder<0> Builder() {
    return InsecureContentStatusBuilder<0>();
  }

 private:
  InsecureContentStatus() { }

  bool ran_mixed_content_;
  bool displayed_mixed_content_;
  bool contained_mixed_form_;
  bool ran_content_with_cert_errors_;
  bool displayed_content_with_cert_errors_;
  ::headless::security::SecurityState ran_insecure_content_style_;
  ::headless::security::SecurityState displayed_insecure_content_style_;

  DISALLOW_COPY_AND_ASSIGN(InsecureContentStatus);
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


// Parameters for the SetIgnoreCertificateErrors command.
class HEADLESS_EXPORT SetIgnoreCertificateErrorsParams {
 public:
  static std::unique_ptr<SetIgnoreCertificateErrorsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetIgnoreCertificateErrorsParams() { }

  // If true, all certificate errors will be ignored.
  bool GetIgnore() const { return ignore_; }
  void SetIgnore(bool value) { ignore_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetIgnoreCertificateErrorsParams> Clone() const;

  template<int STATE>
  class SetIgnoreCertificateErrorsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIgnoreSet = 1 << 1,
      kAllRequiredFieldsSet = (kIgnoreSet | 0)
    };

    SetIgnoreCertificateErrorsParamsBuilder<STATE | kIgnoreSet>& SetIgnore(bool value) {
      static_assert(!(STATE & kIgnoreSet), "property ignore should not have already been set");
      result_->SetIgnore(value);
      return CastState<kIgnoreSet>();
    }

    std::unique_ptr<SetIgnoreCertificateErrorsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetIgnoreCertificateErrorsParams;
    SetIgnoreCertificateErrorsParamsBuilder() : result_(new SetIgnoreCertificateErrorsParams()) { }

    template<int STEP> SetIgnoreCertificateErrorsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetIgnoreCertificateErrorsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetIgnoreCertificateErrorsParams> result_;
  };

  static SetIgnoreCertificateErrorsParamsBuilder<0> Builder() {
    return SetIgnoreCertificateErrorsParamsBuilder<0>();
  }

 private:
  SetIgnoreCertificateErrorsParams() { }

  bool ignore_;

  DISALLOW_COPY_AND_ASSIGN(SetIgnoreCertificateErrorsParams);
};


// Result for the SetIgnoreCertificateErrors command.
class HEADLESS_EXPORT SetIgnoreCertificateErrorsResult {
 public:
  static std::unique_ptr<SetIgnoreCertificateErrorsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetIgnoreCertificateErrorsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetIgnoreCertificateErrorsResult> Clone() const;

  template<int STATE>
  class SetIgnoreCertificateErrorsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetIgnoreCertificateErrorsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetIgnoreCertificateErrorsResult;
    SetIgnoreCertificateErrorsResultBuilder() : result_(new SetIgnoreCertificateErrorsResult()) { }

    template<int STEP> SetIgnoreCertificateErrorsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetIgnoreCertificateErrorsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetIgnoreCertificateErrorsResult> result_;
  };

  static SetIgnoreCertificateErrorsResultBuilder<0> Builder() {
    return SetIgnoreCertificateErrorsResultBuilder<0>();
  }

 private:
  SetIgnoreCertificateErrorsResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetIgnoreCertificateErrorsResult);
};


// Parameters for the HandleCertificateError command.
class HEADLESS_EXPORT HandleCertificateErrorParams {
 public:
  static std::unique_ptr<HandleCertificateErrorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~HandleCertificateErrorParams() { }

  // The ID of the event.
  int GetEventId() const { return event_id_; }
  void SetEventId(int value) { event_id_ = value; }

  // The action to take on the certificate error.
  ::headless::security::CertificateErrorAction GetAction() const { return action_; }
  void SetAction(::headless::security::CertificateErrorAction value) { action_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HandleCertificateErrorParams> Clone() const;

  template<int STATE>
  class HandleCertificateErrorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEventIdSet = 1 << 1,
    kActionSet = 1 << 2,
      kAllRequiredFieldsSet = (kEventIdSet | kActionSet | 0)
    };

    HandleCertificateErrorParamsBuilder<STATE | kEventIdSet>& SetEventId(int value) {
      static_assert(!(STATE & kEventIdSet), "property eventId should not have already been set");
      result_->SetEventId(value);
      return CastState<kEventIdSet>();
    }

    HandleCertificateErrorParamsBuilder<STATE | kActionSet>& SetAction(::headless::security::CertificateErrorAction value) {
      static_assert(!(STATE & kActionSet), "property action should not have already been set");
      result_->SetAction(value);
      return CastState<kActionSet>();
    }

    std::unique_ptr<HandleCertificateErrorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HandleCertificateErrorParams;
    HandleCertificateErrorParamsBuilder() : result_(new HandleCertificateErrorParams()) { }

    template<int STEP> HandleCertificateErrorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HandleCertificateErrorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HandleCertificateErrorParams> result_;
  };

  static HandleCertificateErrorParamsBuilder<0> Builder() {
    return HandleCertificateErrorParamsBuilder<0>();
  }

 private:
  HandleCertificateErrorParams() { }

  int event_id_;
  ::headless::security::CertificateErrorAction action_;

  DISALLOW_COPY_AND_ASSIGN(HandleCertificateErrorParams);
};


// Result for the HandleCertificateError command.
class HEADLESS_EXPORT HandleCertificateErrorResult {
 public:
  static std::unique_ptr<HandleCertificateErrorResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~HandleCertificateErrorResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HandleCertificateErrorResult> Clone() const;

  template<int STATE>
  class HandleCertificateErrorResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HandleCertificateErrorResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HandleCertificateErrorResult;
    HandleCertificateErrorResultBuilder() : result_(new HandleCertificateErrorResult()) { }

    template<int STEP> HandleCertificateErrorResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HandleCertificateErrorResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HandleCertificateErrorResult> result_;
  };

  static HandleCertificateErrorResultBuilder<0> Builder() {
    return HandleCertificateErrorResultBuilder<0>();
  }

 private:
  HandleCertificateErrorResult() { }


  DISALLOW_COPY_AND_ASSIGN(HandleCertificateErrorResult);
};


// Parameters for the SetOverrideCertificateErrors command.
class HEADLESS_EXPORT SetOverrideCertificateErrorsParams {
 public:
  static std::unique_ptr<SetOverrideCertificateErrorsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetOverrideCertificateErrorsParams() { }

  // If true, certificate errors will be overridden.
  bool GetOverride() const { return override_; }
  void SetOverride(bool value) { override_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetOverrideCertificateErrorsParams> Clone() const;

  template<int STATE>
  class SetOverrideCertificateErrorsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOverrideSet = 1 << 1,
      kAllRequiredFieldsSet = (kOverrideSet | 0)
    };

    SetOverrideCertificateErrorsParamsBuilder<STATE | kOverrideSet>& SetOverride(bool value) {
      static_assert(!(STATE & kOverrideSet), "property override should not have already been set");
      result_->SetOverride(value);
      return CastState<kOverrideSet>();
    }

    std::unique_ptr<SetOverrideCertificateErrorsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetOverrideCertificateErrorsParams;
    SetOverrideCertificateErrorsParamsBuilder() : result_(new SetOverrideCertificateErrorsParams()) { }

    template<int STEP> SetOverrideCertificateErrorsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetOverrideCertificateErrorsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetOverrideCertificateErrorsParams> result_;
  };

  static SetOverrideCertificateErrorsParamsBuilder<0> Builder() {
    return SetOverrideCertificateErrorsParamsBuilder<0>();
  }

 private:
  SetOverrideCertificateErrorsParams() { }

  bool override_;

  DISALLOW_COPY_AND_ASSIGN(SetOverrideCertificateErrorsParams);
};


// Result for the SetOverrideCertificateErrors command.
class HEADLESS_EXPORT SetOverrideCertificateErrorsResult {
 public:
  static std::unique_ptr<SetOverrideCertificateErrorsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetOverrideCertificateErrorsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetOverrideCertificateErrorsResult> Clone() const;

  template<int STATE>
  class SetOverrideCertificateErrorsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetOverrideCertificateErrorsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetOverrideCertificateErrorsResult;
    SetOverrideCertificateErrorsResultBuilder() : result_(new SetOverrideCertificateErrorsResult()) { }

    template<int STEP> SetOverrideCertificateErrorsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetOverrideCertificateErrorsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetOverrideCertificateErrorsResult> result_;
  };

  static SetOverrideCertificateErrorsResultBuilder<0> Builder() {
    return SetOverrideCertificateErrorsResultBuilder<0>();
  }

 private:
  SetOverrideCertificateErrorsResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetOverrideCertificateErrorsResult);
};


// Parameters for the CertificateError event.
class HEADLESS_EXPORT CertificateErrorParams {
 public:
  static std::unique_ptr<CertificateErrorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CertificateErrorParams() { }

  // The ID of the event.
  int GetEventId() const { return event_id_; }
  void SetEventId(int value) { event_id_ = value; }

  // The type of the error.
  std::string GetErrorType() const { return error_type_; }
  void SetErrorType(const std::string& value) { error_type_ = value; }

  // The url that was requested.
  std::string GetRequestURL() const { return requesturl_; }
  void SetRequestURL(const std::string& value) { requesturl_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CertificateErrorParams> Clone() const;

  template<int STATE>
  class CertificateErrorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEventIdSet = 1 << 1,
    kErrorTypeSet = 1 << 2,
    kRequestURLSet = 1 << 3,
      kAllRequiredFieldsSet = (kEventIdSet | kErrorTypeSet | kRequestURLSet | 0)
    };

    CertificateErrorParamsBuilder<STATE | kEventIdSet>& SetEventId(int value) {
      static_assert(!(STATE & kEventIdSet), "property eventId should not have already been set");
      result_->SetEventId(value);
      return CastState<kEventIdSet>();
    }

    CertificateErrorParamsBuilder<STATE | kErrorTypeSet>& SetErrorType(const std::string& value) {
      static_assert(!(STATE & kErrorTypeSet), "property errorType should not have already been set");
      result_->SetErrorType(value);
      return CastState<kErrorTypeSet>();
    }

    CertificateErrorParamsBuilder<STATE | kRequestURLSet>& SetRequestURL(const std::string& value) {
      static_assert(!(STATE & kRequestURLSet), "property requestURL should not have already been set");
      result_->SetRequestURL(value);
      return CastState<kRequestURLSet>();
    }

    std::unique_ptr<CertificateErrorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CertificateErrorParams;
    CertificateErrorParamsBuilder() : result_(new CertificateErrorParams()) { }

    template<int STEP> CertificateErrorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CertificateErrorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CertificateErrorParams> result_;
  };

  static CertificateErrorParamsBuilder<0> Builder() {
    return CertificateErrorParamsBuilder<0>();
  }

 private:
  CertificateErrorParams() { }

  int event_id_;
  std::string error_type_;
  std::string requesturl_;

  DISALLOW_COPY_AND_ASSIGN(CertificateErrorParams);
};


// Parameters for the VisibleSecurityStateChanged event.
class HEADLESS_EXPORT VisibleSecurityStateChangedParams {
 public:
  static std::unique_ptr<VisibleSecurityStateChangedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~VisibleSecurityStateChangedParams() { }

  // Security state information about the page.
  const ::headless::security::VisibleSecurityState* GetVisibleSecurityState() const { return visible_security_state_.get(); }
  void SetVisibleSecurityState(std::unique_ptr<::headless::security::VisibleSecurityState> value) { visible_security_state_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<VisibleSecurityStateChangedParams> Clone() const;

  template<int STATE>
  class VisibleSecurityStateChangedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kVisibleSecurityStateSet = 1 << 1,
      kAllRequiredFieldsSet = (kVisibleSecurityStateSet | 0)
    };

    VisibleSecurityStateChangedParamsBuilder<STATE | kVisibleSecurityStateSet>& SetVisibleSecurityState(std::unique_ptr<::headless::security::VisibleSecurityState> value) {
      static_assert(!(STATE & kVisibleSecurityStateSet), "property visibleSecurityState should not have already been set");
      result_->SetVisibleSecurityState(std::move(value));
      return CastState<kVisibleSecurityStateSet>();
    }

    std::unique_ptr<VisibleSecurityStateChangedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class VisibleSecurityStateChangedParams;
    VisibleSecurityStateChangedParamsBuilder() : result_(new VisibleSecurityStateChangedParams()) { }

    template<int STEP> VisibleSecurityStateChangedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<VisibleSecurityStateChangedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<VisibleSecurityStateChangedParams> result_;
  };

  static VisibleSecurityStateChangedParamsBuilder<0> Builder() {
    return VisibleSecurityStateChangedParamsBuilder<0>();
  }

 private:
  VisibleSecurityStateChangedParams() { }

  std::unique_ptr<::headless::security::VisibleSecurityState> visible_security_state_;

  DISALLOW_COPY_AND_ASSIGN(VisibleSecurityStateChangedParams);
};


// Parameters for the SecurityStateChanged event.
class HEADLESS_EXPORT SecurityStateChangedParams {
 public:
  static std::unique_ptr<SecurityStateChangedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SecurityStateChangedParams() { }

  // Security state.
  ::headless::security::SecurityState GetSecurityState() const { return security_state_; }
  void SetSecurityState(::headless::security::SecurityState value) { security_state_ = value; }

  // True if the page was loaded over cryptographic transport such as HTTPS.
  bool GetSchemeIsCryptographic() const { return scheme_is_cryptographic_; }
  void SetSchemeIsCryptographic(bool value) { scheme_is_cryptographic_ = value; }

  // List of explanations for the security state. If the overall security state is `insecure` or
  // `warning`, at least one corresponding explanation should be included.
  const std::vector<std::unique_ptr<::headless::security::SecurityStateExplanation>>* GetExplanations() const { return &explanations_; }
  void SetExplanations(std::vector<std::unique_ptr<::headless::security::SecurityStateExplanation>> value) { explanations_ = std::move(value); }

  // Information about insecure content on the page.
  const ::headless::security::InsecureContentStatus* GetInsecureContentStatus() const { return insecure_content_status_.get(); }
  void SetInsecureContentStatus(std::unique_ptr<::headless::security::InsecureContentStatus> value) { insecure_content_status_ = std::move(value); }

  // Overrides user-visible description of the state.
  bool HasSummary() const { return !!summary_; }
  std::string GetSummary() const { DCHECK(HasSummary()); return summary_.value(); }
  void SetSummary(const std::string& value) { summary_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SecurityStateChangedParams> Clone() const;

  template<int STATE>
  class SecurityStateChangedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityStateSet = 1 << 1,
    kSchemeIsCryptographicSet = 1 << 2,
    kExplanationsSet = 1 << 3,
    kInsecureContentStatusSet = 1 << 4,
      kAllRequiredFieldsSet = (kSecurityStateSet | kSchemeIsCryptographicSet | kExplanationsSet | kInsecureContentStatusSet | 0)
    };

    SecurityStateChangedParamsBuilder<STATE | kSecurityStateSet>& SetSecurityState(::headless::security::SecurityState value) {
      static_assert(!(STATE & kSecurityStateSet), "property securityState should not have already been set");
      result_->SetSecurityState(value);
      return CastState<kSecurityStateSet>();
    }

    SecurityStateChangedParamsBuilder<STATE | kSchemeIsCryptographicSet>& SetSchemeIsCryptographic(bool value) {
      static_assert(!(STATE & kSchemeIsCryptographicSet), "property schemeIsCryptographic should not have already been set");
      result_->SetSchemeIsCryptographic(value);
      return CastState<kSchemeIsCryptographicSet>();
    }

    SecurityStateChangedParamsBuilder<STATE | kExplanationsSet>& SetExplanations(std::vector<std::unique_ptr<::headless::security::SecurityStateExplanation>> value) {
      static_assert(!(STATE & kExplanationsSet), "property explanations should not have already been set");
      result_->SetExplanations(std::move(value));
      return CastState<kExplanationsSet>();
    }

    SecurityStateChangedParamsBuilder<STATE | kInsecureContentStatusSet>& SetInsecureContentStatus(std::unique_ptr<::headless::security::InsecureContentStatus> value) {
      static_assert(!(STATE & kInsecureContentStatusSet), "property insecureContentStatus should not have already been set");
      result_->SetInsecureContentStatus(std::move(value));
      return CastState<kInsecureContentStatusSet>();
    }

    SecurityStateChangedParamsBuilder<STATE>& SetSummary(const std::string& value) {
      result_->SetSummary(value);
      return *this;
    }

    std::unique_ptr<SecurityStateChangedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SecurityStateChangedParams;
    SecurityStateChangedParamsBuilder() : result_(new SecurityStateChangedParams()) { }

    template<int STEP> SecurityStateChangedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SecurityStateChangedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SecurityStateChangedParams> result_;
  };

  static SecurityStateChangedParamsBuilder<0> Builder() {
    return SecurityStateChangedParamsBuilder<0>();
  }

 private:
  SecurityStateChangedParams() { }

  ::headless::security::SecurityState security_state_;
  bool scheme_is_cryptographic_;
  std::vector<std::unique_ptr<::headless::security::SecurityStateExplanation>> explanations_;
  std::unique_ptr<::headless::security::InsecureContentStatus> insecure_content_status_;
  base::Optional<std::string> summary_;

  DISALLOW_COPY_AND_ASSIGN(SecurityStateChangedParams);
};


}  // namespace security

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_SECURITY_H_
