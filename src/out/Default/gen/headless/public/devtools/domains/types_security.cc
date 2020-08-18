// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace security {

std::unique_ptr<CertificateSecurityState> CertificateSecurityState::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CertificateSecurityState");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CertificateSecurityState> result(new CertificateSecurityState());
  errors->Push();
  errors->SetName("CertificateSecurityState");
  const base::Value* protocol_value = value.FindKey("protocol");
  if (protocol_value) {
    errors->SetName("protocol");
    result->protocol_ = internal::FromValue<std::string>::Parse(*protocol_value, errors);
  } else {
    errors->AddError("required property missing: protocol");
  }
  const base::Value* key_exchange_value = value.FindKey("keyExchange");
  if (key_exchange_value) {
    errors->SetName("keyExchange");
    result->key_exchange_ = internal::FromValue<std::string>::Parse(*key_exchange_value, errors);
  } else {
    errors->AddError("required property missing: keyExchange");
  }
  const base::Value* key_exchange_group_value = value.FindKey("keyExchangeGroup");
  if (key_exchange_group_value) {
    errors->SetName("keyExchangeGroup");
    result->key_exchange_group_ = internal::FromValue<std::string>::Parse(*key_exchange_group_value, errors);
  }
  const base::Value* cipher_value = value.FindKey("cipher");
  if (cipher_value) {
    errors->SetName("cipher");
    result->cipher_ = internal::FromValue<std::string>::Parse(*cipher_value, errors);
  } else {
    errors->AddError("required property missing: cipher");
  }
  const base::Value* mac_value = value.FindKey("mac");
  if (mac_value) {
    errors->SetName("mac");
    result->mac_ = internal::FromValue<std::string>::Parse(*mac_value, errors);
  }
  const base::Value* certificate_value = value.FindKey("certificate");
  if (certificate_value) {
    errors->SetName("certificate");
    result->certificate_ = internal::FromValue<std::vector<std::string>>::Parse(*certificate_value, errors);
  } else {
    errors->AddError("required property missing: certificate");
  }
  const base::Value* subject_name_value = value.FindKey("subjectName");
  if (subject_name_value) {
    errors->SetName("subjectName");
    result->subject_name_ = internal::FromValue<std::string>::Parse(*subject_name_value, errors);
  } else {
    errors->AddError("required property missing: subjectName");
  }
  const base::Value* issuer_value = value.FindKey("issuer");
  if (issuer_value) {
    errors->SetName("issuer");
    result->issuer_ = internal::FromValue<std::string>::Parse(*issuer_value, errors);
  } else {
    errors->AddError("required property missing: issuer");
  }
  const base::Value* valid_from_value = value.FindKey("validFrom");
  if (valid_from_value) {
    errors->SetName("validFrom");
    result->valid_from_ = internal::FromValue<double>::Parse(*valid_from_value, errors);
  } else {
    errors->AddError("required property missing: validFrom");
  }
  const base::Value* valid_to_value = value.FindKey("validTo");
  if (valid_to_value) {
    errors->SetName("validTo");
    result->valid_to_ = internal::FromValue<double>::Parse(*valid_to_value, errors);
  } else {
    errors->AddError("required property missing: validTo");
  }
  const base::Value* certificate_network_error_value = value.FindKey("certificateNetworkError");
  if (certificate_network_error_value) {
    errors->SetName("certificateNetworkError");
    result->certificate_network_error_ = internal::FromValue<std::string>::Parse(*certificate_network_error_value, errors);
  }
  const base::Value* certificate_has_weak_signature_value = value.FindKey("certificateHasWeakSignature");
  if (certificate_has_weak_signature_value) {
    errors->SetName("certificateHasWeakSignature");
    result->certificate_has_weak_signature_ = internal::FromValue<bool>::Parse(*certificate_has_weak_signature_value, errors);
  } else {
    errors->AddError("required property missing: certificateHasWeakSignature");
  }
  const base::Value* certificate_has_sha1_signature_value = value.FindKey("certificateHasSha1Signature");
  if (certificate_has_sha1_signature_value) {
    errors->SetName("certificateHasSha1Signature");
    result->certificate_has_sha1_signature_ = internal::FromValue<bool>::Parse(*certificate_has_sha1_signature_value, errors);
  } else {
    errors->AddError("required property missing: certificateHasSha1Signature");
  }
  const base::Value* modernssl_value = value.FindKey("modernSSL");
  if (modernssl_value) {
    errors->SetName("modernSSL");
    result->modernssl_ = internal::FromValue<bool>::Parse(*modernssl_value, errors);
  } else {
    errors->AddError("required property missing: modernSSL");
  }
  const base::Value* obsolete_ssl_protocol_value = value.FindKey("obsoleteSslProtocol");
  if (obsolete_ssl_protocol_value) {
    errors->SetName("obsoleteSslProtocol");
    result->obsolete_ssl_protocol_ = internal::FromValue<bool>::Parse(*obsolete_ssl_protocol_value, errors);
  } else {
    errors->AddError("required property missing: obsoleteSslProtocol");
  }
  const base::Value* obsolete_ssl_key_exchange_value = value.FindKey("obsoleteSslKeyExchange");
  if (obsolete_ssl_key_exchange_value) {
    errors->SetName("obsoleteSslKeyExchange");
    result->obsolete_ssl_key_exchange_ = internal::FromValue<bool>::Parse(*obsolete_ssl_key_exchange_value, errors);
  } else {
    errors->AddError("required property missing: obsoleteSslKeyExchange");
  }
  const base::Value* obsolete_ssl_cipher_value = value.FindKey("obsoleteSslCipher");
  if (obsolete_ssl_cipher_value) {
    errors->SetName("obsoleteSslCipher");
    result->obsolete_ssl_cipher_ = internal::FromValue<bool>::Parse(*obsolete_ssl_cipher_value, errors);
  } else {
    errors->AddError("required property missing: obsoleteSslCipher");
  }
  const base::Value* obsolete_ssl_signature_value = value.FindKey("obsoleteSslSignature");
  if (obsolete_ssl_signature_value) {
    errors->SetName("obsoleteSslSignature");
    result->obsolete_ssl_signature_ = internal::FromValue<bool>::Parse(*obsolete_ssl_signature_value, errors);
  } else {
    errors->AddError("required property missing: obsoleteSslSignature");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CertificateSecurityState::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("protocol", internal::ToValue(protocol_));
  result->Set("keyExchange", internal::ToValue(key_exchange_));
  if (key_exchange_group_)
    result->Set("keyExchangeGroup", internal::ToValue(key_exchange_group_.value()));
  result->Set("cipher", internal::ToValue(cipher_));
  if (mac_)
    result->Set("mac", internal::ToValue(mac_.value()));
  result->Set("certificate", internal::ToValue(certificate_));
  result->Set("subjectName", internal::ToValue(subject_name_));
  result->Set("issuer", internal::ToValue(issuer_));
  result->Set("validFrom", internal::ToValue(valid_from_));
  result->Set("validTo", internal::ToValue(valid_to_));
  if (certificate_network_error_)
    result->Set("certificateNetworkError", internal::ToValue(certificate_network_error_.value()));
  result->Set("certificateHasWeakSignature", internal::ToValue(certificate_has_weak_signature_));
  result->Set("certificateHasSha1Signature", internal::ToValue(certificate_has_sha1_signature_));
  result->Set("modernSSL", internal::ToValue(modernssl_));
  result->Set("obsoleteSslProtocol", internal::ToValue(obsolete_ssl_protocol_));
  result->Set("obsoleteSslKeyExchange", internal::ToValue(obsolete_ssl_key_exchange_));
  result->Set("obsoleteSslCipher", internal::ToValue(obsolete_ssl_cipher_));
  result->Set("obsoleteSslSignature", internal::ToValue(obsolete_ssl_signature_));
  return std::move(result);
}

std::unique_ptr<CertificateSecurityState> CertificateSecurityState::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CertificateSecurityState> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SafetyTipInfo> SafetyTipInfo::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SafetyTipInfo");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SafetyTipInfo> result(new SafetyTipInfo());
  errors->Push();
  errors->SetName("SafetyTipInfo");
  const base::Value* safety_tip_status_value = value.FindKey("safetyTipStatus");
  if (safety_tip_status_value) {
    errors->SetName("safetyTipStatus");
    result->safety_tip_status_ = internal::FromValue<::headless::security::SafetyTipStatus>::Parse(*safety_tip_status_value, errors);
  } else {
    errors->AddError("required property missing: safetyTipStatus");
  }
  const base::Value* safe_url_value = value.FindKey("safeUrl");
  if (safe_url_value) {
    errors->SetName("safeUrl");
    result->safe_url_ = internal::FromValue<std::string>::Parse(*safe_url_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SafetyTipInfo::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("safetyTipStatus", internal::ToValue(safety_tip_status_));
  if (safe_url_)
    result->Set("safeUrl", internal::ToValue(safe_url_.value()));
  return std::move(result);
}

std::unique_ptr<SafetyTipInfo> SafetyTipInfo::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SafetyTipInfo> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<VisibleSecurityState> VisibleSecurityState::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("VisibleSecurityState");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<VisibleSecurityState> result(new VisibleSecurityState());
  errors->Push();
  errors->SetName("VisibleSecurityState");
  const base::Value* security_state_value = value.FindKey("securityState");
  if (security_state_value) {
    errors->SetName("securityState");
    result->security_state_ = internal::FromValue<::headless::security::SecurityState>::Parse(*security_state_value, errors);
  } else {
    errors->AddError("required property missing: securityState");
  }
  const base::Value* certificate_security_state_value = value.FindKey("certificateSecurityState");
  if (certificate_security_state_value) {
    errors->SetName("certificateSecurityState");
    result->certificate_security_state_ = internal::FromValue<::headless::security::CertificateSecurityState>::Parse(*certificate_security_state_value, errors);
  }
  const base::Value* safety_tip_info_value = value.FindKey("safetyTipInfo");
  if (safety_tip_info_value) {
    errors->SetName("safetyTipInfo");
    result->safety_tip_info_ = internal::FromValue<::headless::security::SafetyTipInfo>::Parse(*safety_tip_info_value, errors);
  }
  const base::Value* security_state_issue_ids_value = value.FindKey("securityStateIssueIds");
  if (security_state_issue_ids_value) {
    errors->SetName("securityStateIssueIds");
    result->security_state_issue_ids_ = internal::FromValue<std::vector<std::string>>::Parse(*security_state_issue_ids_value, errors);
  } else {
    errors->AddError("required property missing: securityStateIssueIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> VisibleSecurityState::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityState", internal::ToValue(security_state_));
  if (certificate_security_state_)
    result->Set("certificateSecurityState", internal::ToValue(*certificate_security_state_.value()));
  if (safety_tip_info_)
    result->Set("safetyTipInfo", internal::ToValue(*safety_tip_info_.value()));
  result->Set("securityStateIssueIds", internal::ToValue(security_state_issue_ids_));
  return std::move(result);
}

std::unique_ptr<VisibleSecurityState> VisibleSecurityState::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<VisibleSecurityState> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SecurityStateExplanation> SecurityStateExplanation::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SecurityStateExplanation");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SecurityStateExplanation> result(new SecurityStateExplanation());
  errors->Push();
  errors->SetName("SecurityStateExplanation");
  const base::Value* security_state_value = value.FindKey("securityState");
  if (security_state_value) {
    errors->SetName("securityState");
    result->security_state_ = internal::FromValue<::headless::security::SecurityState>::Parse(*security_state_value, errors);
  } else {
    errors->AddError("required property missing: securityState");
  }
  const base::Value* title_value = value.FindKey("title");
  if (title_value) {
    errors->SetName("title");
    result->title_ = internal::FromValue<std::string>::Parse(*title_value, errors);
  } else {
    errors->AddError("required property missing: title");
  }
  const base::Value* summary_value = value.FindKey("summary");
  if (summary_value) {
    errors->SetName("summary");
    result->summary_ = internal::FromValue<std::string>::Parse(*summary_value, errors);
  } else {
    errors->AddError("required property missing: summary");
  }
  const base::Value* description_value = value.FindKey("description");
  if (description_value) {
    errors->SetName("description");
    result->description_ = internal::FromValue<std::string>::Parse(*description_value, errors);
  } else {
    errors->AddError("required property missing: description");
  }
  const base::Value* mixed_content_type_value = value.FindKey("mixedContentType");
  if (mixed_content_type_value) {
    errors->SetName("mixedContentType");
    result->mixed_content_type_ = internal::FromValue<::headless::security::MixedContentType>::Parse(*mixed_content_type_value, errors);
  } else {
    errors->AddError("required property missing: mixedContentType");
  }
  const base::Value* certificate_value = value.FindKey("certificate");
  if (certificate_value) {
    errors->SetName("certificate");
    result->certificate_ = internal::FromValue<std::vector<std::string>>::Parse(*certificate_value, errors);
  } else {
    errors->AddError("required property missing: certificate");
  }
  const base::Value* recommendations_value = value.FindKey("recommendations");
  if (recommendations_value) {
    errors->SetName("recommendations");
    result->recommendations_ = internal::FromValue<std::vector<std::string>>::Parse(*recommendations_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SecurityStateExplanation::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityState", internal::ToValue(security_state_));
  result->Set("title", internal::ToValue(title_));
  result->Set("summary", internal::ToValue(summary_));
  result->Set("description", internal::ToValue(description_));
  result->Set("mixedContentType", internal::ToValue(mixed_content_type_));
  result->Set("certificate", internal::ToValue(certificate_));
  if (recommendations_)
    result->Set("recommendations", internal::ToValue(recommendations_.value()));
  return std::move(result);
}

std::unique_ptr<SecurityStateExplanation> SecurityStateExplanation::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SecurityStateExplanation> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InsecureContentStatus> InsecureContentStatus::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InsecureContentStatus");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InsecureContentStatus> result(new InsecureContentStatus());
  errors->Push();
  errors->SetName("InsecureContentStatus");
  const base::Value* ran_mixed_content_value = value.FindKey("ranMixedContent");
  if (ran_mixed_content_value) {
    errors->SetName("ranMixedContent");
    result->ran_mixed_content_ = internal::FromValue<bool>::Parse(*ran_mixed_content_value, errors);
  } else {
    errors->AddError("required property missing: ranMixedContent");
  }
  const base::Value* displayed_mixed_content_value = value.FindKey("displayedMixedContent");
  if (displayed_mixed_content_value) {
    errors->SetName("displayedMixedContent");
    result->displayed_mixed_content_ = internal::FromValue<bool>::Parse(*displayed_mixed_content_value, errors);
  } else {
    errors->AddError("required property missing: displayedMixedContent");
  }
  const base::Value* contained_mixed_form_value = value.FindKey("containedMixedForm");
  if (contained_mixed_form_value) {
    errors->SetName("containedMixedForm");
    result->contained_mixed_form_ = internal::FromValue<bool>::Parse(*contained_mixed_form_value, errors);
  } else {
    errors->AddError("required property missing: containedMixedForm");
  }
  const base::Value* ran_content_with_cert_errors_value = value.FindKey("ranContentWithCertErrors");
  if (ran_content_with_cert_errors_value) {
    errors->SetName("ranContentWithCertErrors");
    result->ran_content_with_cert_errors_ = internal::FromValue<bool>::Parse(*ran_content_with_cert_errors_value, errors);
  } else {
    errors->AddError("required property missing: ranContentWithCertErrors");
  }
  const base::Value* displayed_content_with_cert_errors_value = value.FindKey("displayedContentWithCertErrors");
  if (displayed_content_with_cert_errors_value) {
    errors->SetName("displayedContentWithCertErrors");
    result->displayed_content_with_cert_errors_ = internal::FromValue<bool>::Parse(*displayed_content_with_cert_errors_value, errors);
  } else {
    errors->AddError("required property missing: displayedContentWithCertErrors");
  }
  const base::Value* ran_insecure_content_style_value = value.FindKey("ranInsecureContentStyle");
  if (ran_insecure_content_style_value) {
    errors->SetName("ranInsecureContentStyle");
    result->ran_insecure_content_style_ = internal::FromValue<::headless::security::SecurityState>::Parse(*ran_insecure_content_style_value, errors);
  } else {
    errors->AddError("required property missing: ranInsecureContentStyle");
  }
  const base::Value* displayed_insecure_content_style_value = value.FindKey("displayedInsecureContentStyle");
  if (displayed_insecure_content_style_value) {
    errors->SetName("displayedInsecureContentStyle");
    result->displayed_insecure_content_style_ = internal::FromValue<::headless::security::SecurityState>::Parse(*displayed_insecure_content_style_value, errors);
  } else {
    errors->AddError("required property missing: displayedInsecureContentStyle");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InsecureContentStatus::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("ranMixedContent", internal::ToValue(ran_mixed_content_));
  result->Set("displayedMixedContent", internal::ToValue(displayed_mixed_content_));
  result->Set("containedMixedForm", internal::ToValue(contained_mixed_form_));
  result->Set("ranContentWithCertErrors", internal::ToValue(ran_content_with_cert_errors_));
  result->Set("displayedContentWithCertErrors", internal::ToValue(displayed_content_with_cert_errors_));
  result->Set("ranInsecureContentStyle", internal::ToValue(ran_insecure_content_style_));
  result->Set("displayedInsecureContentStyle", internal::ToValue(displayed_insecure_content_style_));
  return std::move(result);
}

std::unique_ptr<InsecureContentStatus> InsecureContentStatus::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InsecureContentStatus> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetIgnoreCertificateErrorsParams> SetIgnoreCertificateErrorsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetIgnoreCertificateErrorsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetIgnoreCertificateErrorsParams> result(new SetIgnoreCertificateErrorsParams());
  errors->Push();
  errors->SetName("SetIgnoreCertificateErrorsParams");
  const base::Value* ignore_value = value.FindKey("ignore");
  if (ignore_value) {
    errors->SetName("ignore");
    result->ignore_ = internal::FromValue<bool>::Parse(*ignore_value, errors);
  } else {
    errors->AddError("required property missing: ignore");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetIgnoreCertificateErrorsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("ignore", internal::ToValue(ignore_));
  return std::move(result);
}

std::unique_ptr<SetIgnoreCertificateErrorsParams> SetIgnoreCertificateErrorsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetIgnoreCertificateErrorsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetIgnoreCertificateErrorsResult> SetIgnoreCertificateErrorsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetIgnoreCertificateErrorsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetIgnoreCertificateErrorsResult> result(new SetIgnoreCertificateErrorsResult());
  errors->Push();
  errors->SetName("SetIgnoreCertificateErrorsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetIgnoreCertificateErrorsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetIgnoreCertificateErrorsResult> SetIgnoreCertificateErrorsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetIgnoreCertificateErrorsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HandleCertificateErrorParams> HandleCertificateErrorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HandleCertificateErrorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HandleCertificateErrorParams> result(new HandleCertificateErrorParams());
  errors->Push();
  errors->SetName("HandleCertificateErrorParams");
  const base::Value* event_id_value = value.FindKey("eventId");
  if (event_id_value) {
    errors->SetName("eventId");
    result->event_id_ = internal::FromValue<int>::Parse(*event_id_value, errors);
  } else {
    errors->AddError("required property missing: eventId");
  }
  const base::Value* action_value = value.FindKey("action");
  if (action_value) {
    errors->SetName("action");
    result->action_ = internal::FromValue<::headless::security::CertificateErrorAction>::Parse(*action_value, errors);
  } else {
    errors->AddError("required property missing: action");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HandleCertificateErrorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("eventId", internal::ToValue(event_id_));
  result->Set("action", internal::ToValue(action_));
  return std::move(result);
}

std::unique_ptr<HandleCertificateErrorParams> HandleCertificateErrorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HandleCertificateErrorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HandleCertificateErrorResult> HandleCertificateErrorResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HandleCertificateErrorResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HandleCertificateErrorResult> result(new HandleCertificateErrorResult());
  errors->Push();
  errors->SetName("HandleCertificateErrorResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HandleCertificateErrorResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<HandleCertificateErrorResult> HandleCertificateErrorResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HandleCertificateErrorResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetOverrideCertificateErrorsParams> SetOverrideCertificateErrorsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetOverrideCertificateErrorsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetOverrideCertificateErrorsParams> result(new SetOverrideCertificateErrorsParams());
  errors->Push();
  errors->SetName("SetOverrideCertificateErrorsParams");
  const base::Value* override_value = value.FindKey("override");
  if (override_value) {
    errors->SetName("override");
    result->override_ = internal::FromValue<bool>::Parse(*override_value, errors);
  } else {
    errors->AddError("required property missing: override");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetOverrideCertificateErrorsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("override", internal::ToValue(override_));
  return std::move(result);
}

std::unique_ptr<SetOverrideCertificateErrorsParams> SetOverrideCertificateErrorsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetOverrideCertificateErrorsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetOverrideCertificateErrorsResult> SetOverrideCertificateErrorsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetOverrideCertificateErrorsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetOverrideCertificateErrorsResult> result(new SetOverrideCertificateErrorsResult());
  errors->Push();
  errors->SetName("SetOverrideCertificateErrorsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetOverrideCertificateErrorsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetOverrideCertificateErrorsResult> SetOverrideCertificateErrorsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetOverrideCertificateErrorsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CertificateErrorParams> CertificateErrorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CertificateErrorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CertificateErrorParams> result(new CertificateErrorParams());
  errors->Push();
  errors->SetName("CertificateErrorParams");
  const base::Value* event_id_value = value.FindKey("eventId");
  if (event_id_value) {
    errors->SetName("eventId");
    result->event_id_ = internal::FromValue<int>::Parse(*event_id_value, errors);
  } else {
    errors->AddError("required property missing: eventId");
  }
  const base::Value* error_type_value = value.FindKey("errorType");
  if (error_type_value) {
    errors->SetName("errorType");
    result->error_type_ = internal::FromValue<std::string>::Parse(*error_type_value, errors);
  } else {
    errors->AddError("required property missing: errorType");
  }
  const base::Value* requesturl_value = value.FindKey("requestURL");
  if (requesturl_value) {
    errors->SetName("requestURL");
    result->requesturl_ = internal::FromValue<std::string>::Parse(*requesturl_value, errors);
  } else {
    errors->AddError("required property missing: requestURL");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CertificateErrorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("eventId", internal::ToValue(event_id_));
  result->Set("errorType", internal::ToValue(error_type_));
  result->Set("requestURL", internal::ToValue(requesturl_));
  return std::move(result);
}

std::unique_ptr<CertificateErrorParams> CertificateErrorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CertificateErrorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<VisibleSecurityStateChangedParams> VisibleSecurityStateChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("VisibleSecurityStateChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<VisibleSecurityStateChangedParams> result(new VisibleSecurityStateChangedParams());
  errors->Push();
  errors->SetName("VisibleSecurityStateChangedParams");
  const base::Value* visible_security_state_value = value.FindKey("visibleSecurityState");
  if (visible_security_state_value) {
    errors->SetName("visibleSecurityState");
    result->visible_security_state_ = internal::FromValue<::headless::security::VisibleSecurityState>::Parse(*visible_security_state_value, errors);
  } else {
    errors->AddError("required property missing: visibleSecurityState");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> VisibleSecurityStateChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("visibleSecurityState", internal::ToValue(*visible_security_state_));
  return std::move(result);
}

std::unique_ptr<VisibleSecurityStateChangedParams> VisibleSecurityStateChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<VisibleSecurityStateChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SecurityStateChangedParams> SecurityStateChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SecurityStateChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SecurityStateChangedParams> result(new SecurityStateChangedParams());
  errors->Push();
  errors->SetName("SecurityStateChangedParams");
  const base::Value* security_state_value = value.FindKey("securityState");
  if (security_state_value) {
    errors->SetName("securityState");
    result->security_state_ = internal::FromValue<::headless::security::SecurityState>::Parse(*security_state_value, errors);
  } else {
    errors->AddError("required property missing: securityState");
  }
  const base::Value* scheme_is_cryptographic_value = value.FindKey("schemeIsCryptographic");
  if (scheme_is_cryptographic_value) {
    errors->SetName("schemeIsCryptographic");
    result->scheme_is_cryptographic_ = internal::FromValue<bool>::Parse(*scheme_is_cryptographic_value, errors);
  } else {
    errors->AddError("required property missing: schemeIsCryptographic");
  }
  const base::Value* explanations_value = value.FindKey("explanations");
  if (explanations_value) {
    errors->SetName("explanations");
    result->explanations_ = internal::FromValue<std::vector<std::unique_ptr<::headless::security::SecurityStateExplanation>>>::Parse(*explanations_value, errors);
  } else {
    errors->AddError("required property missing: explanations");
  }
  const base::Value* insecure_content_status_value = value.FindKey("insecureContentStatus");
  if (insecure_content_status_value) {
    errors->SetName("insecureContentStatus");
    result->insecure_content_status_ = internal::FromValue<::headless::security::InsecureContentStatus>::Parse(*insecure_content_status_value, errors);
  } else {
    errors->AddError("required property missing: insecureContentStatus");
  }
  const base::Value* summary_value = value.FindKey("summary");
  if (summary_value) {
    errors->SetName("summary");
    result->summary_ = internal::FromValue<std::string>::Parse(*summary_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SecurityStateChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityState", internal::ToValue(security_state_));
  result->Set("schemeIsCryptographic", internal::ToValue(scheme_is_cryptographic_));
  result->Set("explanations", internal::ToValue(explanations_));
  result->Set("insecureContentStatus", internal::ToValue(*insecure_content_status_));
  if (summary_)
    result->Set("summary", internal::ToValue(summary_.value()));
  return std::move(result);
}

std::unique_ptr<SecurityStateChangedParams> SecurityStateChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SecurityStateChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace security
}  // namespace headless
