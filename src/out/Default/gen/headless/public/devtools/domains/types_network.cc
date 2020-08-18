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

namespace network {

std::unique_ptr<ResourceTiming> ResourceTiming::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResourceTiming");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResourceTiming> result(new ResourceTiming());
  errors->Push();
  errors->SetName("ResourceTiming");
  const base::Value* request_time_value = value.FindKey("requestTime");
  if (request_time_value) {
    errors->SetName("requestTime");
    result->request_time_ = internal::FromValue<double>::Parse(*request_time_value, errors);
  } else {
    errors->AddError("required property missing: requestTime");
  }
  const base::Value* proxy_start_value = value.FindKey("proxyStart");
  if (proxy_start_value) {
    errors->SetName("proxyStart");
    result->proxy_start_ = internal::FromValue<double>::Parse(*proxy_start_value, errors);
  } else {
    errors->AddError("required property missing: proxyStart");
  }
  const base::Value* proxy_end_value = value.FindKey("proxyEnd");
  if (proxy_end_value) {
    errors->SetName("proxyEnd");
    result->proxy_end_ = internal::FromValue<double>::Parse(*proxy_end_value, errors);
  } else {
    errors->AddError("required property missing: proxyEnd");
  }
  const base::Value* dns_start_value = value.FindKey("dnsStart");
  if (dns_start_value) {
    errors->SetName("dnsStart");
    result->dns_start_ = internal::FromValue<double>::Parse(*dns_start_value, errors);
  } else {
    errors->AddError("required property missing: dnsStart");
  }
  const base::Value* dns_end_value = value.FindKey("dnsEnd");
  if (dns_end_value) {
    errors->SetName("dnsEnd");
    result->dns_end_ = internal::FromValue<double>::Parse(*dns_end_value, errors);
  } else {
    errors->AddError("required property missing: dnsEnd");
  }
  const base::Value* connect_start_value = value.FindKey("connectStart");
  if (connect_start_value) {
    errors->SetName("connectStart");
    result->connect_start_ = internal::FromValue<double>::Parse(*connect_start_value, errors);
  } else {
    errors->AddError("required property missing: connectStart");
  }
  const base::Value* connect_end_value = value.FindKey("connectEnd");
  if (connect_end_value) {
    errors->SetName("connectEnd");
    result->connect_end_ = internal::FromValue<double>::Parse(*connect_end_value, errors);
  } else {
    errors->AddError("required property missing: connectEnd");
  }
  const base::Value* ssl_start_value = value.FindKey("sslStart");
  if (ssl_start_value) {
    errors->SetName("sslStart");
    result->ssl_start_ = internal::FromValue<double>::Parse(*ssl_start_value, errors);
  } else {
    errors->AddError("required property missing: sslStart");
  }
  const base::Value* ssl_end_value = value.FindKey("sslEnd");
  if (ssl_end_value) {
    errors->SetName("sslEnd");
    result->ssl_end_ = internal::FromValue<double>::Parse(*ssl_end_value, errors);
  } else {
    errors->AddError("required property missing: sslEnd");
  }
  const base::Value* worker_start_value = value.FindKey("workerStart");
  if (worker_start_value) {
    errors->SetName("workerStart");
    result->worker_start_ = internal::FromValue<double>::Parse(*worker_start_value, errors);
  } else {
    errors->AddError("required property missing: workerStart");
  }
  const base::Value* worker_ready_value = value.FindKey("workerReady");
  if (worker_ready_value) {
    errors->SetName("workerReady");
    result->worker_ready_ = internal::FromValue<double>::Parse(*worker_ready_value, errors);
  } else {
    errors->AddError("required property missing: workerReady");
  }
  const base::Value* worker_fetch_start_value = value.FindKey("workerFetchStart");
  if (worker_fetch_start_value) {
    errors->SetName("workerFetchStart");
    result->worker_fetch_start_ = internal::FromValue<double>::Parse(*worker_fetch_start_value, errors);
  } else {
    errors->AddError("required property missing: workerFetchStart");
  }
  const base::Value* worker_respond_with_settled_value = value.FindKey("workerRespondWithSettled");
  if (worker_respond_with_settled_value) {
    errors->SetName("workerRespondWithSettled");
    result->worker_respond_with_settled_ = internal::FromValue<double>::Parse(*worker_respond_with_settled_value, errors);
  } else {
    errors->AddError("required property missing: workerRespondWithSettled");
  }
  const base::Value* send_start_value = value.FindKey("sendStart");
  if (send_start_value) {
    errors->SetName("sendStart");
    result->send_start_ = internal::FromValue<double>::Parse(*send_start_value, errors);
  } else {
    errors->AddError("required property missing: sendStart");
  }
  const base::Value* send_end_value = value.FindKey("sendEnd");
  if (send_end_value) {
    errors->SetName("sendEnd");
    result->send_end_ = internal::FromValue<double>::Parse(*send_end_value, errors);
  } else {
    errors->AddError("required property missing: sendEnd");
  }
  const base::Value* push_start_value = value.FindKey("pushStart");
  if (push_start_value) {
    errors->SetName("pushStart");
    result->push_start_ = internal::FromValue<double>::Parse(*push_start_value, errors);
  } else {
    errors->AddError("required property missing: pushStart");
  }
  const base::Value* push_end_value = value.FindKey("pushEnd");
  if (push_end_value) {
    errors->SetName("pushEnd");
    result->push_end_ = internal::FromValue<double>::Parse(*push_end_value, errors);
  } else {
    errors->AddError("required property missing: pushEnd");
  }
  const base::Value* receive_headers_end_value = value.FindKey("receiveHeadersEnd");
  if (receive_headers_end_value) {
    errors->SetName("receiveHeadersEnd");
    result->receive_headers_end_ = internal::FromValue<double>::Parse(*receive_headers_end_value, errors);
  } else {
    errors->AddError("required property missing: receiveHeadersEnd");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResourceTiming::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestTime", internal::ToValue(request_time_));
  result->Set("proxyStart", internal::ToValue(proxy_start_));
  result->Set("proxyEnd", internal::ToValue(proxy_end_));
  result->Set("dnsStart", internal::ToValue(dns_start_));
  result->Set("dnsEnd", internal::ToValue(dns_end_));
  result->Set("connectStart", internal::ToValue(connect_start_));
  result->Set("connectEnd", internal::ToValue(connect_end_));
  result->Set("sslStart", internal::ToValue(ssl_start_));
  result->Set("sslEnd", internal::ToValue(ssl_end_));
  result->Set("workerStart", internal::ToValue(worker_start_));
  result->Set("workerReady", internal::ToValue(worker_ready_));
  result->Set("workerFetchStart", internal::ToValue(worker_fetch_start_));
  result->Set("workerRespondWithSettled", internal::ToValue(worker_respond_with_settled_));
  result->Set("sendStart", internal::ToValue(send_start_));
  result->Set("sendEnd", internal::ToValue(send_end_));
  result->Set("pushStart", internal::ToValue(push_start_));
  result->Set("pushEnd", internal::ToValue(push_end_));
  result->Set("receiveHeadersEnd", internal::ToValue(receive_headers_end_));
  return std::move(result);
}

std::unique_ptr<ResourceTiming> ResourceTiming::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResourceTiming> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Request> Request::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Request");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Request> result(new Request());
  errors->Push();
  errors->SetName("Request");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* url_fragment_value = value.FindKey("urlFragment");
  if (url_fragment_value) {
    errors->SetName("urlFragment");
    result->url_fragment_ = internal::FromValue<std::string>::Parse(*url_fragment_value, errors);
  }
  const base::Value* method_value = value.FindKey("method");
  if (method_value) {
    errors->SetName("method");
    result->method_ = internal::FromValue<std::string>::Parse(*method_value, errors);
  } else {
    errors->AddError("required property missing: method");
  }
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  } else {
    errors->AddError("required property missing: headers");
  }
  const base::Value* post_data_value = value.FindKey("postData");
  if (post_data_value) {
    errors->SetName("postData");
    result->post_data_ = internal::FromValue<std::string>::Parse(*post_data_value, errors);
  }
  const base::Value* has_post_data_value = value.FindKey("hasPostData");
  if (has_post_data_value) {
    errors->SetName("hasPostData");
    result->has_post_data_ = internal::FromValue<bool>::Parse(*has_post_data_value, errors);
  }
  const base::Value* mixed_content_type_value = value.FindKey("mixedContentType");
  if (mixed_content_type_value) {
    errors->SetName("mixedContentType");
    result->mixed_content_type_ = internal::FromValue<::headless::security::MixedContentType>::Parse(*mixed_content_type_value, errors);
  }
  const base::Value* initial_priority_value = value.FindKey("initialPriority");
  if (initial_priority_value) {
    errors->SetName("initialPriority");
    result->initial_priority_ = internal::FromValue<::headless::network::ResourcePriority>::Parse(*initial_priority_value, errors);
  } else {
    errors->AddError("required property missing: initialPriority");
  }
  const base::Value* referrer_policy_value = value.FindKey("referrerPolicy");
  if (referrer_policy_value) {
    errors->SetName("referrerPolicy");
    result->referrer_policy_ = internal::FromValue<::headless::network::RequestReferrerPolicy>::Parse(*referrer_policy_value, errors);
  } else {
    errors->AddError("required property missing: referrerPolicy");
  }
  const base::Value* is_link_preload_value = value.FindKey("isLinkPreload");
  if (is_link_preload_value) {
    errors->SetName("isLinkPreload");
    result->is_link_preload_ = internal::FromValue<bool>::Parse(*is_link_preload_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Request::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  if (url_fragment_)
    result->Set("urlFragment", internal::ToValue(url_fragment_.value()));
  result->Set("method", internal::ToValue(method_));
  result->Set("headers", internal::ToValue(*headers_));
  if (post_data_)
    result->Set("postData", internal::ToValue(post_data_.value()));
  if (has_post_data_)
    result->Set("hasPostData", internal::ToValue(has_post_data_.value()));
  if (mixed_content_type_)
    result->Set("mixedContentType", internal::ToValue(mixed_content_type_.value()));
  result->Set("initialPriority", internal::ToValue(initial_priority_));
  result->Set("referrerPolicy", internal::ToValue(referrer_policy_));
  if (is_link_preload_)
    result->Set("isLinkPreload", internal::ToValue(is_link_preload_.value()));
  return std::move(result);
}

std::unique_ptr<Request> Request::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Request> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SignedCertificateTimestamp> SignedCertificateTimestamp::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SignedCertificateTimestamp");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SignedCertificateTimestamp> result(new SignedCertificateTimestamp());
  errors->Push();
  errors->SetName("SignedCertificateTimestamp");
  const base::Value* status_value = value.FindKey("status");
  if (status_value) {
    errors->SetName("status");
    result->status_ = internal::FromValue<std::string>::Parse(*status_value, errors);
  } else {
    errors->AddError("required property missing: status");
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* log_description_value = value.FindKey("logDescription");
  if (log_description_value) {
    errors->SetName("logDescription");
    result->log_description_ = internal::FromValue<std::string>::Parse(*log_description_value, errors);
  } else {
    errors->AddError("required property missing: logDescription");
  }
  const base::Value* log_id_value = value.FindKey("logId");
  if (log_id_value) {
    errors->SetName("logId");
    result->log_id_ = internal::FromValue<std::string>::Parse(*log_id_value, errors);
  } else {
    errors->AddError("required property missing: logId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* hash_algorithm_value = value.FindKey("hashAlgorithm");
  if (hash_algorithm_value) {
    errors->SetName("hashAlgorithm");
    result->hash_algorithm_ = internal::FromValue<std::string>::Parse(*hash_algorithm_value, errors);
  } else {
    errors->AddError("required property missing: hashAlgorithm");
  }
  const base::Value* signature_algorithm_value = value.FindKey("signatureAlgorithm");
  if (signature_algorithm_value) {
    errors->SetName("signatureAlgorithm");
    result->signature_algorithm_ = internal::FromValue<std::string>::Parse(*signature_algorithm_value, errors);
  } else {
    errors->AddError("required property missing: signatureAlgorithm");
  }
  const base::Value* signature_data_value = value.FindKey("signatureData");
  if (signature_data_value) {
    errors->SetName("signatureData");
    result->signature_data_ = internal::FromValue<std::string>::Parse(*signature_data_value, errors);
  } else {
    errors->AddError("required property missing: signatureData");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SignedCertificateTimestamp::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("status", internal::ToValue(status_));
  result->Set("origin", internal::ToValue(origin_));
  result->Set("logDescription", internal::ToValue(log_description_));
  result->Set("logId", internal::ToValue(log_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("hashAlgorithm", internal::ToValue(hash_algorithm_));
  result->Set("signatureAlgorithm", internal::ToValue(signature_algorithm_));
  result->Set("signatureData", internal::ToValue(signature_data_));
  return std::move(result);
}

std::unique_ptr<SignedCertificateTimestamp> SignedCertificateTimestamp::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SignedCertificateTimestamp> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SecurityDetails> SecurityDetails::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SecurityDetails");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SecurityDetails> result(new SecurityDetails());
  errors->Push();
  errors->SetName("SecurityDetails");
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
  const base::Value* certificate_id_value = value.FindKey("certificateId");
  if (certificate_id_value) {
    errors->SetName("certificateId");
    result->certificate_id_ = internal::FromValue<int>::Parse(*certificate_id_value, errors);
  } else {
    errors->AddError("required property missing: certificateId");
  }
  const base::Value* subject_name_value = value.FindKey("subjectName");
  if (subject_name_value) {
    errors->SetName("subjectName");
    result->subject_name_ = internal::FromValue<std::string>::Parse(*subject_name_value, errors);
  } else {
    errors->AddError("required property missing: subjectName");
  }
  const base::Value* san_list_value = value.FindKey("sanList");
  if (san_list_value) {
    errors->SetName("sanList");
    result->san_list_ = internal::FromValue<std::vector<std::string>>::Parse(*san_list_value, errors);
  } else {
    errors->AddError("required property missing: sanList");
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
  const base::Value* signed_certificate_timestamp_list_value = value.FindKey("signedCertificateTimestampList");
  if (signed_certificate_timestamp_list_value) {
    errors->SetName("signedCertificateTimestampList");
    result->signed_certificate_timestamp_list_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::SignedCertificateTimestamp>>>::Parse(*signed_certificate_timestamp_list_value, errors);
  } else {
    errors->AddError("required property missing: signedCertificateTimestampList");
  }
  const base::Value* certificate_transparency_compliance_value = value.FindKey("certificateTransparencyCompliance");
  if (certificate_transparency_compliance_value) {
    errors->SetName("certificateTransparencyCompliance");
    result->certificate_transparency_compliance_ = internal::FromValue<::headless::network::CertificateTransparencyCompliance>::Parse(*certificate_transparency_compliance_value, errors);
  } else {
    errors->AddError("required property missing: certificateTransparencyCompliance");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SecurityDetails::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("protocol", internal::ToValue(protocol_));
  result->Set("keyExchange", internal::ToValue(key_exchange_));
  if (key_exchange_group_)
    result->Set("keyExchangeGroup", internal::ToValue(key_exchange_group_.value()));
  result->Set("cipher", internal::ToValue(cipher_));
  if (mac_)
    result->Set("mac", internal::ToValue(mac_.value()));
  result->Set("certificateId", internal::ToValue(certificate_id_));
  result->Set("subjectName", internal::ToValue(subject_name_));
  result->Set("sanList", internal::ToValue(san_list_));
  result->Set("issuer", internal::ToValue(issuer_));
  result->Set("validFrom", internal::ToValue(valid_from_));
  result->Set("validTo", internal::ToValue(valid_to_));
  result->Set("signedCertificateTimestampList", internal::ToValue(signed_certificate_timestamp_list_));
  result->Set("certificateTransparencyCompliance", internal::ToValue(certificate_transparency_compliance_));
  return std::move(result);
}

std::unique_ptr<SecurityDetails> SecurityDetails::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SecurityDetails> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Response> Response::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Response");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Response> result(new Response());
  errors->Push();
  errors->SetName("Response");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* status_value = value.FindKey("status");
  if (status_value) {
    errors->SetName("status");
    result->status_ = internal::FromValue<int>::Parse(*status_value, errors);
  } else {
    errors->AddError("required property missing: status");
  }
  const base::Value* status_text_value = value.FindKey("statusText");
  if (status_text_value) {
    errors->SetName("statusText");
    result->status_text_ = internal::FromValue<std::string>::Parse(*status_text_value, errors);
  } else {
    errors->AddError("required property missing: statusText");
  }
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  } else {
    errors->AddError("required property missing: headers");
  }
  const base::Value* headers_text_value = value.FindKey("headersText");
  if (headers_text_value) {
    errors->SetName("headersText");
    result->headers_text_ = internal::FromValue<std::string>::Parse(*headers_text_value, errors);
  }
  const base::Value* mime_type_value = value.FindKey("mimeType");
  if (mime_type_value) {
    errors->SetName("mimeType");
    result->mime_type_ = internal::FromValue<std::string>::Parse(*mime_type_value, errors);
  } else {
    errors->AddError("required property missing: mimeType");
  }
  const base::Value* request_headers_value = value.FindKey("requestHeaders");
  if (request_headers_value) {
    errors->SetName("requestHeaders");
    result->request_headers_ = internal::FromValue<base::DictionaryValue>::Parse(*request_headers_value, errors);
  }
  const base::Value* request_headers_text_value = value.FindKey("requestHeadersText");
  if (request_headers_text_value) {
    errors->SetName("requestHeadersText");
    result->request_headers_text_ = internal::FromValue<std::string>::Parse(*request_headers_text_value, errors);
  }
  const base::Value* connection_reused_value = value.FindKey("connectionReused");
  if (connection_reused_value) {
    errors->SetName("connectionReused");
    result->connection_reused_ = internal::FromValue<bool>::Parse(*connection_reused_value, errors);
  } else {
    errors->AddError("required property missing: connectionReused");
  }
  const base::Value* connection_id_value = value.FindKey("connectionId");
  if (connection_id_value) {
    errors->SetName("connectionId");
    result->connection_id_ = internal::FromValue<double>::Parse(*connection_id_value, errors);
  } else {
    errors->AddError("required property missing: connectionId");
  }
  const base::Value* remoteip_address_value = value.FindKey("remoteIPAddress");
  if (remoteip_address_value) {
    errors->SetName("remoteIPAddress");
    result->remoteip_address_ = internal::FromValue<std::string>::Parse(*remoteip_address_value, errors);
  }
  const base::Value* remote_port_value = value.FindKey("remotePort");
  if (remote_port_value) {
    errors->SetName("remotePort");
    result->remote_port_ = internal::FromValue<int>::Parse(*remote_port_value, errors);
  }
  const base::Value* from_disk_cache_value = value.FindKey("fromDiskCache");
  if (from_disk_cache_value) {
    errors->SetName("fromDiskCache");
    result->from_disk_cache_ = internal::FromValue<bool>::Parse(*from_disk_cache_value, errors);
  }
  const base::Value* from_service_worker_value = value.FindKey("fromServiceWorker");
  if (from_service_worker_value) {
    errors->SetName("fromServiceWorker");
    result->from_service_worker_ = internal::FromValue<bool>::Parse(*from_service_worker_value, errors);
  }
  const base::Value* from_prefetch_cache_value = value.FindKey("fromPrefetchCache");
  if (from_prefetch_cache_value) {
    errors->SetName("fromPrefetchCache");
    result->from_prefetch_cache_ = internal::FromValue<bool>::Parse(*from_prefetch_cache_value, errors);
  }
  const base::Value* encoded_data_length_value = value.FindKey("encodedDataLength");
  if (encoded_data_length_value) {
    errors->SetName("encodedDataLength");
    result->encoded_data_length_ = internal::FromValue<double>::Parse(*encoded_data_length_value, errors);
  } else {
    errors->AddError("required property missing: encodedDataLength");
  }
  const base::Value* timing_value = value.FindKey("timing");
  if (timing_value) {
    errors->SetName("timing");
    result->timing_ = internal::FromValue<::headless::network::ResourceTiming>::Parse(*timing_value, errors);
  }
  const base::Value* service_worker_response_source_value = value.FindKey("serviceWorkerResponseSource");
  if (service_worker_response_source_value) {
    errors->SetName("serviceWorkerResponseSource");
    result->service_worker_response_source_ = internal::FromValue<::headless::network::ServiceWorkerResponseSource>::Parse(*service_worker_response_source_value, errors);
  }
  const base::Value* response_time_value = value.FindKey("responseTime");
  if (response_time_value) {
    errors->SetName("responseTime");
    result->response_time_ = internal::FromValue<double>::Parse(*response_time_value, errors);
  }
  const base::Value* cache_storage_cache_name_value = value.FindKey("cacheStorageCacheName");
  if (cache_storage_cache_name_value) {
    errors->SetName("cacheStorageCacheName");
    result->cache_storage_cache_name_ = internal::FromValue<std::string>::Parse(*cache_storage_cache_name_value, errors);
  }
  const base::Value* protocol_value = value.FindKey("protocol");
  if (protocol_value) {
    errors->SetName("protocol");
    result->protocol_ = internal::FromValue<std::string>::Parse(*protocol_value, errors);
  }
  const base::Value* security_state_value = value.FindKey("securityState");
  if (security_state_value) {
    errors->SetName("securityState");
    result->security_state_ = internal::FromValue<::headless::security::SecurityState>::Parse(*security_state_value, errors);
  } else {
    errors->AddError("required property missing: securityState");
  }
  const base::Value* security_details_value = value.FindKey("securityDetails");
  if (security_details_value) {
    errors->SetName("securityDetails");
    result->security_details_ = internal::FromValue<::headless::network::SecurityDetails>::Parse(*security_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Response::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("status", internal::ToValue(status_));
  result->Set("statusText", internal::ToValue(status_text_));
  result->Set("headers", internal::ToValue(*headers_));
  if (headers_text_)
    result->Set("headersText", internal::ToValue(headers_text_.value()));
  result->Set("mimeType", internal::ToValue(mime_type_));
  if (request_headers_)
    result->Set("requestHeaders", internal::ToValue(*request_headers_.value()));
  if (request_headers_text_)
    result->Set("requestHeadersText", internal::ToValue(request_headers_text_.value()));
  result->Set("connectionReused", internal::ToValue(connection_reused_));
  result->Set("connectionId", internal::ToValue(connection_id_));
  if (remoteip_address_)
    result->Set("remoteIPAddress", internal::ToValue(remoteip_address_.value()));
  if (remote_port_)
    result->Set("remotePort", internal::ToValue(remote_port_.value()));
  if (from_disk_cache_)
    result->Set("fromDiskCache", internal::ToValue(from_disk_cache_.value()));
  if (from_service_worker_)
    result->Set("fromServiceWorker", internal::ToValue(from_service_worker_.value()));
  if (from_prefetch_cache_)
    result->Set("fromPrefetchCache", internal::ToValue(from_prefetch_cache_.value()));
  result->Set("encodedDataLength", internal::ToValue(encoded_data_length_));
  if (timing_)
    result->Set("timing", internal::ToValue(*timing_.value()));
  if (service_worker_response_source_)
    result->Set("serviceWorkerResponseSource", internal::ToValue(service_worker_response_source_.value()));
  if (response_time_)
    result->Set("responseTime", internal::ToValue(response_time_.value()));
  if (cache_storage_cache_name_)
    result->Set("cacheStorageCacheName", internal::ToValue(cache_storage_cache_name_.value()));
  if (protocol_)
    result->Set("protocol", internal::ToValue(protocol_.value()));
  result->Set("securityState", internal::ToValue(security_state_));
  if (security_details_)
    result->Set("securityDetails", internal::ToValue(*security_details_.value()));
  return std::move(result);
}

std::unique_ptr<Response> Response::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Response> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketRequest> WebSocketRequest::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketRequest");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketRequest> result(new WebSocketRequest());
  errors->Push();
  errors->SetName("WebSocketRequest");
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  } else {
    errors->AddError("required property missing: headers");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketRequest::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("headers", internal::ToValue(*headers_));
  return std::move(result);
}

std::unique_ptr<WebSocketRequest> WebSocketRequest::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketRequest> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketResponse> WebSocketResponse::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketResponse");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketResponse> result(new WebSocketResponse());
  errors->Push();
  errors->SetName("WebSocketResponse");
  const base::Value* status_value = value.FindKey("status");
  if (status_value) {
    errors->SetName("status");
    result->status_ = internal::FromValue<int>::Parse(*status_value, errors);
  } else {
    errors->AddError("required property missing: status");
  }
  const base::Value* status_text_value = value.FindKey("statusText");
  if (status_text_value) {
    errors->SetName("statusText");
    result->status_text_ = internal::FromValue<std::string>::Parse(*status_text_value, errors);
  } else {
    errors->AddError("required property missing: statusText");
  }
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  } else {
    errors->AddError("required property missing: headers");
  }
  const base::Value* headers_text_value = value.FindKey("headersText");
  if (headers_text_value) {
    errors->SetName("headersText");
    result->headers_text_ = internal::FromValue<std::string>::Parse(*headers_text_value, errors);
  }
  const base::Value* request_headers_value = value.FindKey("requestHeaders");
  if (request_headers_value) {
    errors->SetName("requestHeaders");
    result->request_headers_ = internal::FromValue<base::DictionaryValue>::Parse(*request_headers_value, errors);
  }
  const base::Value* request_headers_text_value = value.FindKey("requestHeadersText");
  if (request_headers_text_value) {
    errors->SetName("requestHeadersText");
    result->request_headers_text_ = internal::FromValue<std::string>::Parse(*request_headers_text_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketResponse::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("status", internal::ToValue(status_));
  result->Set("statusText", internal::ToValue(status_text_));
  result->Set("headers", internal::ToValue(*headers_));
  if (headers_text_)
    result->Set("headersText", internal::ToValue(headers_text_.value()));
  if (request_headers_)
    result->Set("requestHeaders", internal::ToValue(*request_headers_.value()));
  if (request_headers_text_)
    result->Set("requestHeadersText", internal::ToValue(request_headers_text_.value()));
  return std::move(result);
}

std::unique_ptr<WebSocketResponse> WebSocketResponse::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketResponse> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketFrame> WebSocketFrame::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketFrame");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketFrame> result(new WebSocketFrame());
  errors->Push();
  errors->SetName("WebSocketFrame");
  const base::Value* opcode_value = value.FindKey("opcode");
  if (opcode_value) {
    errors->SetName("opcode");
    result->opcode_ = internal::FromValue<double>::Parse(*opcode_value, errors);
  } else {
    errors->AddError("required property missing: opcode");
  }
  const base::Value* mask_value = value.FindKey("mask");
  if (mask_value) {
    errors->SetName("mask");
    result->mask_ = internal::FromValue<bool>::Parse(*mask_value, errors);
  } else {
    errors->AddError("required property missing: mask");
  }
  const base::Value* payload_data_value = value.FindKey("payloadData");
  if (payload_data_value) {
    errors->SetName("payloadData");
    result->payload_data_ = internal::FromValue<std::string>::Parse(*payload_data_value, errors);
  } else {
    errors->AddError("required property missing: payloadData");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketFrame::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("opcode", internal::ToValue(opcode_));
  result->Set("mask", internal::ToValue(mask_));
  result->Set("payloadData", internal::ToValue(payload_data_));
  return std::move(result);
}

std::unique_ptr<WebSocketFrame> WebSocketFrame::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketFrame> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CachedResource> CachedResource::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CachedResource");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CachedResource> result(new CachedResource());
  errors->Push();
  errors->SetName("CachedResource");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::network::ResourceType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* response_value = value.FindKey("response");
  if (response_value) {
    errors->SetName("response");
    result->response_ = internal::FromValue<::headless::network::Response>::Parse(*response_value, errors);
  }
  const base::Value* body_size_value = value.FindKey("bodySize");
  if (body_size_value) {
    errors->SetName("bodySize");
    result->body_size_ = internal::FromValue<double>::Parse(*body_size_value, errors);
  } else {
    errors->AddError("required property missing: bodySize");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CachedResource::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("type", internal::ToValue(type_));
  if (response_)
    result->Set("response", internal::ToValue(*response_.value()));
  result->Set("bodySize", internal::ToValue(body_size_));
  return std::move(result);
}

std::unique_ptr<CachedResource> CachedResource::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CachedResource> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Initiator> Initiator::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Initiator");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Initiator> result(new Initiator());
  errors->Push();
  errors->SetName("Initiator");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::network::InitiatorType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* stack_value = value.FindKey("stack");
  if (stack_value) {
    errors->SetName("stack");
    result->stack_ = internal::FromValue<::headless::runtime::StackTrace>::Parse(*stack_value, errors);
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* line_number_value = value.FindKey("lineNumber");
  if (line_number_value) {
    errors->SetName("lineNumber");
    result->line_number_ = internal::FromValue<double>::Parse(*line_number_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Initiator::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  if (stack_)
    result->Set("stack", internal::ToValue(*stack_.value()));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (line_number_)
    result->Set("lineNumber", internal::ToValue(line_number_.value()));
  return std::move(result);
}

std::unique_ptr<Initiator> Initiator::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Initiator> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Cookie> Cookie::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Cookie");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Cookie> result(new Cookie());
  errors->Push();
  errors->SetName("Cookie");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  const base::Value* domain_value = value.FindKey("domain");
  if (domain_value) {
    errors->SetName("domain");
    result->domain_ = internal::FromValue<std::string>::Parse(*domain_value, errors);
  } else {
    errors->AddError("required property missing: domain");
  }
  const base::Value* path_value = value.FindKey("path");
  if (path_value) {
    errors->SetName("path");
    result->path_ = internal::FromValue<std::string>::Parse(*path_value, errors);
  } else {
    errors->AddError("required property missing: path");
  }
  const base::Value* expires_value = value.FindKey("expires");
  if (expires_value) {
    errors->SetName("expires");
    result->expires_ = internal::FromValue<double>::Parse(*expires_value, errors);
  } else {
    errors->AddError("required property missing: expires");
  }
  const base::Value* size_value = value.FindKey("size");
  if (size_value) {
    errors->SetName("size");
    result->size_ = internal::FromValue<int>::Parse(*size_value, errors);
  } else {
    errors->AddError("required property missing: size");
  }
  const base::Value* http_only_value = value.FindKey("httpOnly");
  if (http_only_value) {
    errors->SetName("httpOnly");
    result->http_only_ = internal::FromValue<bool>::Parse(*http_only_value, errors);
  } else {
    errors->AddError("required property missing: httpOnly");
  }
  const base::Value* secure_value = value.FindKey("secure");
  if (secure_value) {
    errors->SetName("secure");
    result->secure_ = internal::FromValue<bool>::Parse(*secure_value, errors);
  } else {
    errors->AddError("required property missing: secure");
  }
  const base::Value* session_value = value.FindKey("session");
  if (session_value) {
    errors->SetName("session");
    result->session_ = internal::FromValue<bool>::Parse(*session_value, errors);
  } else {
    errors->AddError("required property missing: session");
  }
  const base::Value* same_site_value = value.FindKey("sameSite");
  if (same_site_value) {
    errors->SetName("sameSite");
    result->same_site_ = internal::FromValue<::headless::network::CookieSameSite>::Parse(*same_site_value, errors);
  }
  const base::Value* priority_value = value.FindKey("priority");
  if (priority_value) {
    errors->SetName("priority");
    result->priority_ = internal::FromValue<::headless::network::CookiePriority>::Parse(*priority_value, errors);
  } else {
    errors->AddError("required property missing: priority");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Cookie::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  result->Set("domain", internal::ToValue(domain_));
  result->Set("path", internal::ToValue(path_));
  result->Set("expires", internal::ToValue(expires_));
  result->Set("size", internal::ToValue(size_));
  result->Set("httpOnly", internal::ToValue(http_only_));
  result->Set("secure", internal::ToValue(secure_));
  result->Set("session", internal::ToValue(session_));
  if (same_site_)
    result->Set("sameSite", internal::ToValue(same_site_.value()));
  result->Set("priority", internal::ToValue(priority_));
  return std::move(result);
}

std::unique_ptr<Cookie> Cookie::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Cookie> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BlockedSetCookieWithReason> BlockedSetCookieWithReason::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BlockedSetCookieWithReason");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BlockedSetCookieWithReason> result(new BlockedSetCookieWithReason());
  errors->Push();
  errors->SetName("BlockedSetCookieWithReason");
  const base::Value* blocked_reasons_value = value.FindKey("blockedReasons");
  if (blocked_reasons_value) {
    errors->SetName("blockedReasons");
    result->blocked_reasons_ = internal::FromValue<std::vector<::headless::network::SetCookieBlockedReason>>::Parse(*blocked_reasons_value, errors);
  } else {
    errors->AddError("required property missing: blockedReasons");
  }
  const base::Value* cookie_line_value = value.FindKey("cookieLine");
  if (cookie_line_value) {
    errors->SetName("cookieLine");
    result->cookie_line_ = internal::FromValue<std::string>::Parse(*cookie_line_value, errors);
  } else {
    errors->AddError("required property missing: cookieLine");
  }
  const base::Value* cookie_value = value.FindKey("cookie");
  if (cookie_value) {
    errors->SetName("cookie");
    result->cookie_ = internal::FromValue<::headless::network::Cookie>::Parse(*cookie_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BlockedSetCookieWithReason::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("blockedReasons", internal::ToValue(blocked_reasons_));
  result->Set("cookieLine", internal::ToValue(cookie_line_));
  if (cookie_)
    result->Set("cookie", internal::ToValue(*cookie_.value()));
  return std::move(result);
}

std::unique_ptr<BlockedSetCookieWithReason> BlockedSetCookieWithReason::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BlockedSetCookieWithReason> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BlockedCookieWithReason> BlockedCookieWithReason::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BlockedCookieWithReason");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BlockedCookieWithReason> result(new BlockedCookieWithReason());
  errors->Push();
  errors->SetName("BlockedCookieWithReason");
  const base::Value* blocked_reasons_value = value.FindKey("blockedReasons");
  if (blocked_reasons_value) {
    errors->SetName("blockedReasons");
    result->blocked_reasons_ = internal::FromValue<std::vector<::headless::network::CookieBlockedReason>>::Parse(*blocked_reasons_value, errors);
  } else {
    errors->AddError("required property missing: blockedReasons");
  }
  const base::Value* cookie_value = value.FindKey("cookie");
  if (cookie_value) {
    errors->SetName("cookie");
    result->cookie_ = internal::FromValue<::headless::network::Cookie>::Parse(*cookie_value, errors);
  } else {
    errors->AddError("required property missing: cookie");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BlockedCookieWithReason::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("blockedReasons", internal::ToValue(blocked_reasons_));
  result->Set("cookie", internal::ToValue(*cookie_));
  return std::move(result);
}

std::unique_ptr<BlockedCookieWithReason> BlockedCookieWithReason::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BlockedCookieWithReason> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CookieParam> CookieParam::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CookieParam");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CookieParam> result(new CookieParam());
  errors->Push();
  errors->SetName("CookieParam");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* domain_value = value.FindKey("domain");
  if (domain_value) {
    errors->SetName("domain");
    result->domain_ = internal::FromValue<std::string>::Parse(*domain_value, errors);
  }
  const base::Value* path_value = value.FindKey("path");
  if (path_value) {
    errors->SetName("path");
    result->path_ = internal::FromValue<std::string>::Parse(*path_value, errors);
  }
  const base::Value* secure_value = value.FindKey("secure");
  if (secure_value) {
    errors->SetName("secure");
    result->secure_ = internal::FromValue<bool>::Parse(*secure_value, errors);
  }
  const base::Value* http_only_value = value.FindKey("httpOnly");
  if (http_only_value) {
    errors->SetName("httpOnly");
    result->http_only_ = internal::FromValue<bool>::Parse(*http_only_value, errors);
  }
  const base::Value* same_site_value = value.FindKey("sameSite");
  if (same_site_value) {
    errors->SetName("sameSite");
    result->same_site_ = internal::FromValue<::headless::network::CookieSameSite>::Parse(*same_site_value, errors);
  }
  const base::Value* expires_value = value.FindKey("expires");
  if (expires_value) {
    errors->SetName("expires");
    result->expires_ = internal::FromValue<double>::Parse(*expires_value, errors);
  }
  const base::Value* priority_value = value.FindKey("priority");
  if (priority_value) {
    errors->SetName("priority");
    result->priority_ = internal::FromValue<::headless::network::CookiePriority>::Parse(*priority_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CookieParam::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (domain_)
    result->Set("domain", internal::ToValue(domain_.value()));
  if (path_)
    result->Set("path", internal::ToValue(path_.value()));
  if (secure_)
    result->Set("secure", internal::ToValue(secure_.value()));
  if (http_only_)
    result->Set("httpOnly", internal::ToValue(http_only_.value()));
  if (same_site_)
    result->Set("sameSite", internal::ToValue(same_site_.value()));
  if (expires_)
    result->Set("expires", internal::ToValue(expires_.value()));
  if (priority_)
    result->Set("priority", internal::ToValue(priority_.value()));
  return std::move(result);
}

std::unique_ptr<CookieParam> CookieParam::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CookieParam> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AuthChallenge> AuthChallenge::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AuthChallenge");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AuthChallenge> result(new AuthChallenge());
  errors->Push();
  errors->SetName("AuthChallenge");
  const base::Value* source_value = value.FindKey("source");
  if (source_value) {
    errors->SetName("source");
    result->source_ = internal::FromValue<::headless::network::AuthChallengeSource>::Parse(*source_value, errors);
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* scheme_value = value.FindKey("scheme");
  if (scheme_value) {
    errors->SetName("scheme");
    result->scheme_ = internal::FromValue<std::string>::Parse(*scheme_value, errors);
  } else {
    errors->AddError("required property missing: scheme");
  }
  const base::Value* realm_value = value.FindKey("realm");
  if (realm_value) {
    errors->SetName("realm");
    result->realm_ = internal::FromValue<std::string>::Parse(*realm_value, errors);
  } else {
    errors->AddError("required property missing: realm");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AuthChallenge::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (source_)
    result->Set("source", internal::ToValue(source_.value()));
  result->Set("origin", internal::ToValue(origin_));
  result->Set("scheme", internal::ToValue(scheme_));
  result->Set("realm", internal::ToValue(realm_));
  return std::move(result);
}

std::unique_ptr<AuthChallenge> AuthChallenge::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AuthChallenge> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AuthChallengeResponse> AuthChallengeResponse::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AuthChallengeResponse");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AuthChallengeResponse> result(new AuthChallengeResponse());
  errors->Push();
  errors->SetName("AuthChallengeResponse");
  const base::Value* response_value = value.FindKey("response");
  if (response_value) {
    errors->SetName("response");
    result->response_ = internal::FromValue<::headless::network::AuthChallengeResponseResponse>::Parse(*response_value, errors);
  } else {
    errors->AddError("required property missing: response");
  }
  const base::Value* username_value = value.FindKey("username");
  if (username_value) {
    errors->SetName("username");
    result->username_ = internal::FromValue<std::string>::Parse(*username_value, errors);
  }
  const base::Value* password_value = value.FindKey("password");
  if (password_value) {
    errors->SetName("password");
    result->password_ = internal::FromValue<std::string>::Parse(*password_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AuthChallengeResponse::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("response", internal::ToValue(response_));
  if (username_)
    result->Set("username", internal::ToValue(username_.value()));
  if (password_)
    result->Set("password", internal::ToValue(password_.value()));
  return std::move(result);
}

std::unique_ptr<AuthChallengeResponse> AuthChallengeResponse::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AuthChallengeResponse> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestPattern> RequestPattern::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestPattern");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestPattern> result(new RequestPattern());
  errors->Push();
  errors->SetName("RequestPattern");
  const base::Value* url_pattern_value = value.FindKey("urlPattern");
  if (url_pattern_value) {
    errors->SetName("urlPattern");
    result->url_pattern_ = internal::FromValue<std::string>::Parse(*url_pattern_value, errors);
  }
  const base::Value* resource_type_value = value.FindKey("resourceType");
  if (resource_type_value) {
    errors->SetName("resourceType");
    result->resource_type_ = internal::FromValue<::headless::network::ResourceType>::Parse(*resource_type_value, errors);
  }
  const base::Value* interception_stage_value = value.FindKey("interceptionStage");
  if (interception_stage_value) {
    errors->SetName("interceptionStage");
    result->interception_stage_ = internal::FromValue<::headless::network::InterceptionStage>::Parse(*interception_stage_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestPattern::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (url_pattern_)
    result->Set("urlPattern", internal::ToValue(url_pattern_.value()));
  if (resource_type_)
    result->Set("resourceType", internal::ToValue(resource_type_.value()));
  if (interception_stage_)
    result->Set("interceptionStage", internal::ToValue(interception_stage_.value()));
  return std::move(result);
}

std::unique_ptr<RequestPattern> RequestPattern::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestPattern> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SignedExchangeSignature> SignedExchangeSignature::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SignedExchangeSignature");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SignedExchangeSignature> result(new SignedExchangeSignature());
  errors->Push();
  errors->SetName("SignedExchangeSignature");
  const base::Value* label_value = value.FindKey("label");
  if (label_value) {
    errors->SetName("label");
    result->label_ = internal::FromValue<std::string>::Parse(*label_value, errors);
  } else {
    errors->AddError("required property missing: label");
  }
  const base::Value* signature_value = value.FindKey("signature");
  if (signature_value) {
    errors->SetName("signature");
    result->signature_ = internal::FromValue<std::string>::Parse(*signature_value, errors);
  } else {
    errors->AddError("required property missing: signature");
  }
  const base::Value* integrity_value = value.FindKey("integrity");
  if (integrity_value) {
    errors->SetName("integrity");
    result->integrity_ = internal::FromValue<std::string>::Parse(*integrity_value, errors);
  } else {
    errors->AddError("required property missing: integrity");
  }
  const base::Value* cert_url_value = value.FindKey("certUrl");
  if (cert_url_value) {
    errors->SetName("certUrl");
    result->cert_url_ = internal::FromValue<std::string>::Parse(*cert_url_value, errors);
  }
  const base::Value* cert_sha256_value = value.FindKey("certSha256");
  if (cert_sha256_value) {
    errors->SetName("certSha256");
    result->cert_sha256_ = internal::FromValue<std::string>::Parse(*cert_sha256_value, errors);
  }
  const base::Value* validity_url_value = value.FindKey("validityUrl");
  if (validity_url_value) {
    errors->SetName("validityUrl");
    result->validity_url_ = internal::FromValue<std::string>::Parse(*validity_url_value, errors);
  } else {
    errors->AddError("required property missing: validityUrl");
  }
  const base::Value* date_value = value.FindKey("date");
  if (date_value) {
    errors->SetName("date");
    result->date_ = internal::FromValue<int>::Parse(*date_value, errors);
  } else {
    errors->AddError("required property missing: date");
  }
  const base::Value* expires_value = value.FindKey("expires");
  if (expires_value) {
    errors->SetName("expires");
    result->expires_ = internal::FromValue<int>::Parse(*expires_value, errors);
  } else {
    errors->AddError("required property missing: expires");
  }
  const base::Value* certificates_value = value.FindKey("certificates");
  if (certificates_value) {
    errors->SetName("certificates");
    result->certificates_ = internal::FromValue<std::vector<std::string>>::Parse(*certificates_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SignedExchangeSignature::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("label", internal::ToValue(label_));
  result->Set("signature", internal::ToValue(signature_));
  result->Set("integrity", internal::ToValue(integrity_));
  if (cert_url_)
    result->Set("certUrl", internal::ToValue(cert_url_.value()));
  if (cert_sha256_)
    result->Set("certSha256", internal::ToValue(cert_sha256_.value()));
  result->Set("validityUrl", internal::ToValue(validity_url_));
  result->Set("date", internal::ToValue(date_));
  result->Set("expires", internal::ToValue(expires_));
  if (certificates_)
    result->Set("certificates", internal::ToValue(certificates_.value()));
  return std::move(result);
}

std::unique_ptr<SignedExchangeSignature> SignedExchangeSignature::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SignedExchangeSignature> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SignedExchangeHeader> SignedExchangeHeader::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SignedExchangeHeader");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SignedExchangeHeader> result(new SignedExchangeHeader());
  errors->Push();
  errors->SetName("SignedExchangeHeader");
  const base::Value* request_url_value = value.FindKey("requestUrl");
  if (request_url_value) {
    errors->SetName("requestUrl");
    result->request_url_ = internal::FromValue<std::string>::Parse(*request_url_value, errors);
  } else {
    errors->AddError("required property missing: requestUrl");
  }
  const base::Value* response_code_value = value.FindKey("responseCode");
  if (response_code_value) {
    errors->SetName("responseCode");
    result->response_code_ = internal::FromValue<int>::Parse(*response_code_value, errors);
  } else {
    errors->AddError("required property missing: responseCode");
  }
  const base::Value* response_headers_value = value.FindKey("responseHeaders");
  if (response_headers_value) {
    errors->SetName("responseHeaders");
    result->response_headers_ = internal::FromValue<base::DictionaryValue>::Parse(*response_headers_value, errors);
  } else {
    errors->AddError("required property missing: responseHeaders");
  }
  const base::Value* signatures_value = value.FindKey("signatures");
  if (signatures_value) {
    errors->SetName("signatures");
    result->signatures_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::SignedExchangeSignature>>>::Parse(*signatures_value, errors);
  } else {
    errors->AddError("required property missing: signatures");
  }
  const base::Value* header_integrity_value = value.FindKey("headerIntegrity");
  if (header_integrity_value) {
    errors->SetName("headerIntegrity");
    result->header_integrity_ = internal::FromValue<std::string>::Parse(*header_integrity_value, errors);
  } else {
    errors->AddError("required property missing: headerIntegrity");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SignedExchangeHeader::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestUrl", internal::ToValue(request_url_));
  result->Set("responseCode", internal::ToValue(response_code_));
  result->Set("responseHeaders", internal::ToValue(*response_headers_));
  result->Set("signatures", internal::ToValue(signatures_));
  result->Set("headerIntegrity", internal::ToValue(header_integrity_));
  return std::move(result);
}

std::unique_ptr<SignedExchangeHeader> SignedExchangeHeader::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SignedExchangeHeader> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SignedExchangeError> SignedExchangeError::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SignedExchangeError");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SignedExchangeError> result(new SignedExchangeError());
  errors->Push();
  errors->SetName("SignedExchangeError");
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  const base::Value* signature_index_value = value.FindKey("signatureIndex");
  if (signature_index_value) {
    errors->SetName("signatureIndex");
    result->signature_index_ = internal::FromValue<int>::Parse(*signature_index_value, errors);
  }
  const base::Value* error_field_value = value.FindKey("errorField");
  if (error_field_value) {
    errors->SetName("errorField");
    result->error_field_ = internal::FromValue<::headless::network::SignedExchangeErrorField>::Parse(*error_field_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SignedExchangeError::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("message", internal::ToValue(message_));
  if (signature_index_)
    result->Set("signatureIndex", internal::ToValue(signature_index_.value()));
  if (error_field_)
    result->Set("errorField", internal::ToValue(error_field_.value()));
  return std::move(result);
}

std::unique_ptr<SignedExchangeError> SignedExchangeError::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SignedExchangeError> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SignedExchangeInfo> SignedExchangeInfo::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SignedExchangeInfo");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SignedExchangeInfo> result(new SignedExchangeInfo());
  errors->Push();
  errors->SetName("SignedExchangeInfo");
  const base::Value* outer_response_value = value.FindKey("outerResponse");
  if (outer_response_value) {
    errors->SetName("outerResponse");
    result->outer_response_ = internal::FromValue<::headless::network::Response>::Parse(*outer_response_value, errors);
  } else {
    errors->AddError("required property missing: outerResponse");
  }
  const base::Value* header_value = value.FindKey("header");
  if (header_value) {
    errors->SetName("header");
    result->header_ = internal::FromValue<::headless::network::SignedExchangeHeader>::Parse(*header_value, errors);
  }
  const base::Value* security_details_value = value.FindKey("securityDetails");
  if (security_details_value) {
    errors->SetName("securityDetails");
    result->security_details_ = internal::FromValue<::headless::network::SecurityDetails>::Parse(*security_details_value, errors);
  }
  const base::Value* errors_value = value.FindKey("errors");
  if (errors_value) {
    errors->SetName("errors");
    result->errors_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::SignedExchangeError>>>::Parse(*errors_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SignedExchangeInfo::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("outerResponse", internal::ToValue(*outer_response_));
  if (header_)
    result->Set("header", internal::ToValue(*header_.value()));
  if (security_details_)
    result->Set("securityDetails", internal::ToValue(*security_details_.value()));
  if (errors_)
    result->Set("errors", internal::ToValue(errors_.value()));
  return std::move(result);
}

std::unique_ptr<SignedExchangeInfo> SignedExchangeInfo::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SignedExchangeInfo> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CanClearBrowserCacheParams> CanClearBrowserCacheParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CanClearBrowserCacheParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CanClearBrowserCacheParams> result(new CanClearBrowserCacheParams());
  errors->Push();
  errors->SetName("CanClearBrowserCacheParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CanClearBrowserCacheParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CanClearBrowserCacheParams> CanClearBrowserCacheParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CanClearBrowserCacheParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CanClearBrowserCacheResult> CanClearBrowserCacheResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CanClearBrowserCacheResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CanClearBrowserCacheResult> result(new CanClearBrowserCacheResult());
  errors->Push();
  errors->SetName("CanClearBrowserCacheResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<bool>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CanClearBrowserCacheResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<CanClearBrowserCacheResult> CanClearBrowserCacheResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CanClearBrowserCacheResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CanClearBrowserCookiesParams> CanClearBrowserCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CanClearBrowserCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CanClearBrowserCookiesParams> result(new CanClearBrowserCookiesParams());
  errors->Push();
  errors->SetName("CanClearBrowserCookiesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CanClearBrowserCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CanClearBrowserCookiesParams> CanClearBrowserCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CanClearBrowserCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CanClearBrowserCookiesResult> CanClearBrowserCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CanClearBrowserCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CanClearBrowserCookiesResult> result(new CanClearBrowserCookiesResult());
  errors->Push();
  errors->SetName("CanClearBrowserCookiesResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<bool>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CanClearBrowserCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<CanClearBrowserCookiesResult> CanClearBrowserCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CanClearBrowserCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CanEmulateNetworkConditionsParams> CanEmulateNetworkConditionsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CanEmulateNetworkConditionsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CanEmulateNetworkConditionsParams> result(new CanEmulateNetworkConditionsParams());
  errors->Push();
  errors->SetName("CanEmulateNetworkConditionsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CanEmulateNetworkConditionsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CanEmulateNetworkConditionsParams> CanEmulateNetworkConditionsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CanEmulateNetworkConditionsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CanEmulateNetworkConditionsResult> CanEmulateNetworkConditionsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CanEmulateNetworkConditionsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CanEmulateNetworkConditionsResult> result(new CanEmulateNetworkConditionsResult());
  errors->Push();
  errors->SetName("CanEmulateNetworkConditionsResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<bool>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CanEmulateNetworkConditionsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<CanEmulateNetworkConditionsResult> CanEmulateNetworkConditionsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CanEmulateNetworkConditionsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearBrowserCacheParams> ClearBrowserCacheParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearBrowserCacheParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearBrowserCacheParams> result(new ClearBrowserCacheParams());
  errors->Push();
  errors->SetName("ClearBrowserCacheParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearBrowserCacheParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearBrowserCacheParams> ClearBrowserCacheParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearBrowserCacheParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearBrowserCacheResult> ClearBrowserCacheResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearBrowserCacheResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearBrowserCacheResult> result(new ClearBrowserCacheResult());
  errors->Push();
  errors->SetName("ClearBrowserCacheResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearBrowserCacheResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearBrowserCacheResult> ClearBrowserCacheResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearBrowserCacheResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearBrowserCookiesParams> ClearBrowserCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearBrowserCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearBrowserCookiesParams> result(new ClearBrowserCookiesParams());
  errors->Push();
  errors->SetName("ClearBrowserCookiesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearBrowserCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearBrowserCookiesParams> ClearBrowserCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearBrowserCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearBrowserCookiesResult> ClearBrowserCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearBrowserCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearBrowserCookiesResult> result(new ClearBrowserCookiesResult());
  errors->Push();
  errors->SetName("ClearBrowserCookiesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearBrowserCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearBrowserCookiesResult> ClearBrowserCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearBrowserCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContinueInterceptedRequestParams> ContinueInterceptedRequestParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContinueInterceptedRequestParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContinueInterceptedRequestParams> result(new ContinueInterceptedRequestParams());
  errors->Push();
  errors->SetName("ContinueInterceptedRequestParams");
  const base::Value* interception_id_value = value.FindKey("interceptionId");
  if (interception_id_value) {
    errors->SetName("interceptionId");
    result->interception_id_ = internal::FromValue<std::string>::Parse(*interception_id_value, errors);
  } else {
    errors->AddError("required property missing: interceptionId");
  }
  const base::Value* error_reason_value = value.FindKey("errorReason");
  if (error_reason_value) {
    errors->SetName("errorReason");
    result->error_reason_ = internal::FromValue<::headless::network::ErrorReason>::Parse(*error_reason_value, errors);
  }
  const base::Value* raw_response_value = value.FindKey("rawResponse");
  if (raw_response_value) {
    errors->SetName("rawResponse");
    result->raw_response_ = internal::FromValue<protocol::Binary>::Parse(*raw_response_value, errors);
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* method_value = value.FindKey("method");
  if (method_value) {
    errors->SetName("method");
    result->method_ = internal::FromValue<std::string>::Parse(*method_value, errors);
  }
  const base::Value* post_data_value = value.FindKey("postData");
  if (post_data_value) {
    errors->SetName("postData");
    result->post_data_ = internal::FromValue<std::string>::Parse(*post_data_value, errors);
  }
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  }
  const base::Value* auth_challenge_response_value = value.FindKey("authChallengeResponse");
  if (auth_challenge_response_value) {
    errors->SetName("authChallengeResponse");
    result->auth_challenge_response_ = internal::FromValue<::headless::network::AuthChallengeResponse>::Parse(*auth_challenge_response_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContinueInterceptedRequestParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("interceptionId", internal::ToValue(interception_id_));
  if (error_reason_)
    result->Set("errorReason", internal::ToValue(error_reason_.value()));
  if (raw_response_)
    result->Set("rawResponse", internal::ToValue(raw_response_.value()));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (method_)
    result->Set("method", internal::ToValue(method_.value()));
  if (post_data_)
    result->Set("postData", internal::ToValue(post_data_.value()));
  if (headers_)
    result->Set("headers", internal::ToValue(*headers_.value()));
  if (auth_challenge_response_)
    result->Set("authChallengeResponse", internal::ToValue(*auth_challenge_response_.value()));
  return std::move(result);
}

std::unique_ptr<ContinueInterceptedRequestParams> ContinueInterceptedRequestParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContinueInterceptedRequestParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContinueInterceptedRequestResult> ContinueInterceptedRequestResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContinueInterceptedRequestResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContinueInterceptedRequestResult> result(new ContinueInterceptedRequestResult());
  errors->Push();
  errors->SetName("ContinueInterceptedRequestResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContinueInterceptedRequestResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ContinueInterceptedRequestResult> ContinueInterceptedRequestResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContinueInterceptedRequestResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteCookiesParams> DeleteCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteCookiesParams> result(new DeleteCookiesParams());
  errors->Push();
  errors->SetName("DeleteCookiesParams");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* domain_value = value.FindKey("domain");
  if (domain_value) {
    errors->SetName("domain");
    result->domain_ = internal::FromValue<std::string>::Parse(*domain_value, errors);
  }
  const base::Value* path_value = value.FindKey("path");
  if (path_value) {
    errors->SetName("path");
    result->path_ = internal::FromValue<std::string>::Parse(*path_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (domain_)
    result->Set("domain", internal::ToValue(domain_.value()));
  if (path_)
    result->Set("path", internal::ToValue(path_.value()));
  return std::move(result);
}

std::unique_ptr<DeleteCookiesParams> DeleteCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteCookiesResult> DeleteCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteCookiesResult> result(new DeleteCookiesResult());
  errors->Push();
  errors->SetName("DeleteCookiesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DeleteCookiesResult> DeleteCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteCookiesResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<EmulateNetworkConditionsParams> EmulateNetworkConditionsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EmulateNetworkConditionsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EmulateNetworkConditionsParams> result(new EmulateNetworkConditionsParams());
  errors->Push();
  errors->SetName("EmulateNetworkConditionsParams");
  const base::Value* offline_value = value.FindKey("offline");
  if (offline_value) {
    errors->SetName("offline");
    result->offline_ = internal::FromValue<bool>::Parse(*offline_value, errors);
  } else {
    errors->AddError("required property missing: offline");
  }
  const base::Value* latency_value = value.FindKey("latency");
  if (latency_value) {
    errors->SetName("latency");
    result->latency_ = internal::FromValue<double>::Parse(*latency_value, errors);
  } else {
    errors->AddError("required property missing: latency");
  }
  const base::Value* download_throughput_value = value.FindKey("downloadThroughput");
  if (download_throughput_value) {
    errors->SetName("downloadThroughput");
    result->download_throughput_ = internal::FromValue<double>::Parse(*download_throughput_value, errors);
  } else {
    errors->AddError("required property missing: downloadThroughput");
  }
  const base::Value* upload_throughput_value = value.FindKey("uploadThroughput");
  if (upload_throughput_value) {
    errors->SetName("uploadThroughput");
    result->upload_throughput_ = internal::FromValue<double>::Parse(*upload_throughput_value, errors);
  } else {
    errors->AddError("required property missing: uploadThroughput");
  }
  const base::Value* connection_type_value = value.FindKey("connectionType");
  if (connection_type_value) {
    errors->SetName("connectionType");
    result->connection_type_ = internal::FromValue<::headless::network::ConnectionType>::Parse(*connection_type_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EmulateNetworkConditionsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("offline", internal::ToValue(offline_));
  result->Set("latency", internal::ToValue(latency_));
  result->Set("downloadThroughput", internal::ToValue(download_throughput_));
  result->Set("uploadThroughput", internal::ToValue(upload_throughput_));
  if (connection_type_)
    result->Set("connectionType", internal::ToValue(connection_type_.value()));
  return std::move(result);
}

std::unique_ptr<EmulateNetworkConditionsParams> EmulateNetworkConditionsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EmulateNetworkConditionsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EmulateNetworkConditionsResult> EmulateNetworkConditionsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EmulateNetworkConditionsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EmulateNetworkConditionsResult> result(new EmulateNetworkConditionsResult());
  errors->Push();
  errors->SetName("EmulateNetworkConditionsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EmulateNetworkConditionsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EmulateNetworkConditionsResult> EmulateNetworkConditionsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EmulateNetworkConditionsResult> result = Parse(*Serialize(), &errors);
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
  const base::Value* max_total_buffer_size_value = value.FindKey("maxTotalBufferSize");
  if (max_total_buffer_size_value) {
    errors->SetName("maxTotalBufferSize");
    result->max_total_buffer_size_ = internal::FromValue<int>::Parse(*max_total_buffer_size_value, errors);
  }
  const base::Value* max_resource_buffer_size_value = value.FindKey("maxResourceBufferSize");
  if (max_resource_buffer_size_value) {
    errors->SetName("maxResourceBufferSize");
    result->max_resource_buffer_size_ = internal::FromValue<int>::Parse(*max_resource_buffer_size_value, errors);
  }
  const base::Value* max_post_data_size_value = value.FindKey("maxPostDataSize");
  if (max_post_data_size_value) {
    errors->SetName("maxPostDataSize");
    result->max_post_data_size_ = internal::FromValue<int>::Parse(*max_post_data_size_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (max_total_buffer_size_)
    result->Set("maxTotalBufferSize", internal::ToValue(max_total_buffer_size_.value()));
  if (max_resource_buffer_size_)
    result->Set("maxResourceBufferSize", internal::ToValue(max_resource_buffer_size_.value()));
  if (max_post_data_size_)
    result->Set("maxPostDataSize", internal::ToValue(max_post_data_size_.value()));
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


std::unique_ptr<GetAllCookiesParams> GetAllCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAllCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAllCookiesParams> result(new GetAllCookiesParams());
  errors->Push();
  errors->SetName("GetAllCookiesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAllCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetAllCookiesParams> GetAllCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAllCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetAllCookiesResult> GetAllCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetAllCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetAllCookiesResult> result(new GetAllCookiesResult());
  errors->Push();
  errors->SetName("GetAllCookiesResult");
  const base::Value* cookies_value = value.FindKey("cookies");
  if (cookies_value) {
    errors->SetName("cookies");
    result->cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::Cookie>>>::Parse(*cookies_value, errors);
  } else {
    errors->AddError("required property missing: cookies");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetAllCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookies", internal::ToValue(cookies_));
  return std::move(result);
}

std::unique_ptr<GetAllCookiesResult> GetAllCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetAllCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCertificateParams> GetCertificateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCertificateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCertificateParams> result(new GetCertificateParams());
  errors->Push();
  errors->SetName("GetCertificateParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCertificateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<GetCertificateParams> GetCertificateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCertificateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCertificateResult> GetCertificateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCertificateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCertificateResult> result(new GetCertificateResult());
  errors->Push();
  errors->SetName("GetCertificateResult");
  const base::Value* table_names_value = value.FindKey("tableNames");
  if (table_names_value) {
    errors->SetName("tableNames");
    result->table_names_ = internal::FromValue<std::vector<std::string>>::Parse(*table_names_value, errors);
  } else {
    errors->AddError("required property missing: tableNames");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCertificateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("tableNames", internal::ToValue(table_names_));
  return std::move(result);
}

std::unique_ptr<GetCertificateResult> GetCertificateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCertificateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCookiesParams> GetCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCookiesParams> result(new GetCookiesParams());
  errors->Push();
  errors->SetName("GetCookiesParams");
  const base::Value* urls_value = value.FindKey("urls");
  if (urls_value) {
    errors->SetName("urls");
    result->urls_ = internal::FromValue<std::vector<std::string>>::Parse(*urls_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (urls_)
    result->Set("urls", internal::ToValue(urls_.value()));
  return std::move(result);
}

std::unique_ptr<GetCookiesParams> GetCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCookiesResult> GetCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCookiesResult> result(new GetCookiesResult());
  errors->Push();
  errors->SetName("GetCookiesResult");
  const base::Value* cookies_value = value.FindKey("cookies");
  if (cookies_value) {
    errors->SetName("cookies");
    result->cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::Cookie>>>::Parse(*cookies_value, errors);
  } else {
    errors->AddError("required property missing: cookies");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookies", internal::ToValue(cookies_));
  return std::move(result);
}

std::unique_ptr<GetCookiesResult> GetCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResponseBodyParams> GetResponseBodyParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResponseBodyParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResponseBodyParams> result(new GetResponseBodyParams());
  errors->Push();
  errors->SetName("GetResponseBodyParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResponseBodyParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  return std::move(result);
}

std::unique_ptr<GetResponseBodyParams> GetResponseBodyParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResponseBodyParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResponseBodyResult> GetResponseBodyResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResponseBodyResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResponseBodyResult> result(new GetResponseBodyResult());
  errors->Push();
  errors->SetName("GetResponseBodyResult");
  const base::Value* body_value = value.FindKey("body");
  if (body_value) {
    errors->SetName("body");
    result->body_ = internal::FromValue<std::string>::Parse(*body_value, errors);
  } else {
    errors->AddError("required property missing: body");
  }
  const base::Value* base64_encoded_value = value.FindKey("base64Encoded");
  if (base64_encoded_value) {
    errors->SetName("base64Encoded");
    result->base64_encoded_ = internal::FromValue<bool>::Parse(*base64_encoded_value, errors);
  } else {
    errors->AddError("required property missing: base64Encoded");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResponseBodyResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("body", internal::ToValue(body_));
  result->Set("base64Encoded", internal::ToValue(base64_encoded_));
  return std::move(result);
}

std::unique_ptr<GetResponseBodyResult> GetResponseBodyResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResponseBodyResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetRequestPostDataParams> GetRequestPostDataParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRequestPostDataParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRequestPostDataParams> result(new GetRequestPostDataParams());
  errors->Push();
  errors->SetName("GetRequestPostDataParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRequestPostDataParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  return std::move(result);
}

std::unique_ptr<GetRequestPostDataParams> GetRequestPostDataParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRequestPostDataParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetRequestPostDataResult> GetRequestPostDataResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRequestPostDataResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRequestPostDataResult> result(new GetRequestPostDataResult());
  errors->Push();
  errors->SetName("GetRequestPostDataResult");
  const base::Value* post_data_value = value.FindKey("postData");
  if (post_data_value) {
    errors->SetName("postData");
    result->post_data_ = internal::FromValue<std::string>::Parse(*post_data_value, errors);
  } else {
    errors->AddError("required property missing: postData");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRequestPostDataResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("postData", internal::ToValue(post_data_));
  return std::move(result);
}

std::unique_ptr<GetRequestPostDataResult> GetRequestPostDataResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRequestPostDataResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResponseBodyForInterceptionParams> GetResponseBodyForInterceptionParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResponseBodyForInterceptionParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResponseBodyForInterceptionParams> result(new GetResponseBodyForInterceptionParams());
  errors->Push();
  errors->SetName("GetResponseBodyForInterceptionParams");
  const base::Value* interception_id_value = value.FindKey("interceptionId");
  if (interception_id_value) {
    errors->SetName("interceptionId");
    result->interception_id_ = internal::FromValue<std::string>::Parse(*interception_id_value, errors);
  } else {
    errors->AddError("required property missing: interceptionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResponseBodyForInterceptionParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("interceptionId", internal::ToValue(interception_id_));
  return std::move(result);
}

std::unique_ptr<GetResponseBodyForInterceptionParams> GetResponseBodyForInterceptionParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResponseBodyForInterceptionParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetResponseBodyForInterceptionResult> GetResponseBodyForInterceptionResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetResponseBodyForInterceptionResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetResponseBodyForInterceptionResult> result(new GetResponseBodyForInterceptionResult());
  errors->Push();
  errors->SetName("GetResponseBodyForInterceptionResult");
  const base::Value* body_value = value.FindKey("body");
  if (body_value) {
    errors->SetName("body");
    result->body_ = internal::FromValue<std::string>::Parse(*body_value, errors);
  } else {
    errors->AddError("required property missing: body");
  }
  const base::Value* base64_encoded_value = value.FindKey("base64Encoded");
  if (base64_encoded_value) {
    errors->SetName("base64Encoded");
    result->base64_encoded_ = internal::FromValue<bool>::Parse(*base64_encoded_value, errors);
  } else {
    errors->AddError("required property missing: base64Encoded");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetResponseBodyForInterceptionResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("body", internal::ToValue(body_));
  result->Set("base64Encoded", internal::ToValue(base64_encoded_));
  return std::move(result);
}

std::unique_ptr<GetResponseBodyForInterceptionResult> GetResponseBodyForInterceptionResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetResponseBodyForInterceptionResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> TakeResponseBodyForInterceptionAsStreamParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeResponseBodyForInterceptionAsStreamParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> result(new TakeResponseBodyForInterceptionAsStreamParams());
  errors->Push();
  errors->SetName("TakeResponseBodyForInterceptionAsStreamParams");
  const base::Value* interception_id_value = value.FindKey("interceptionId");
  if (interception_id_value) {
    errors->SetName("interceptionId");
    result->interception_id_ = internal::FromValue<std::string>::Parse(*interception_id_value, errors);
  } else {
    errors->AddError("required property missing: interceptionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeResponseBodyForInterceptionAsStreamParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("interceptionId", internal::ToValue(interception_id_));
  return std::move(result);
}

std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> TakeResponseBodyForInterceptionAsStreamParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeResponseBodyForInterceptionAsStreamParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> TakeResponseBodyForInterceptionAsStreamResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeResponseBodyForInterceptionAsStreamResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> result(new TakeResponseBodyForInterceptionAsStreamResult());
  errors->Push();
  errors->SetName("TakeResponseBodyForInterceptionAsStreamResult");
  const base::Value* stream_value = value.FindKey("stream");
  if (stream_value) {
    errors->SetName("stream");
    result->stream_ = internal::FromValue<std::string>::Parse(*stream_value, errors);
  } else {
    errors->AddError("required property missing: stream");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeResponseBodyForInterceptionAsStreamResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("stream", internal::ToValue(stream_));
  return std::move(result);
}

std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> TakeResponseBodyForInterceptionAsStreamResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeResponseBodyForInterceptionAsStreamResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReplayXHRParams> ReplayXHRParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReplayXHRParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReplayXHRParams> result(new ReplayXHRParams());
  errors->Push();
  errors->SetName("ReplayXHRParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReplayXHRParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  return std::move(result);
}

std::unique_ptr<ReplayXHRParams> ReplayXHRParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReplayXHRParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReplayXHRResult> ReplayXHRResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReplayXHRResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReplayXHRResult> result(new ReplayXHRResult());
  errors->Push();
  errors->SetName("ReplayXHRResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReplayXHRResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ReplayXHRResult> ReplayXHRResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReplayXHRResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SearchInResponseBodyParams> SearchInResponseBodyParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SearchInResponseBodyParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SearchInResponseBodyParams> result(new SearchInResponseBodyParams());
  errors->Push();
  errors->SetName("SearchInResponseBodyParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* query_value = value.FindKey("query");
  if (query_value) {
    errors->SetName("query");
    result->query_ = internal::FromValue<std::string>::Parse(*query_value, errors);
  } else {
    errors->AddError("required property missing: query");
  }
  const base::Value* case_sensitive_value = value.FindKey("caseSensitive");
  if (case_sensitive_value) {
    errors->SetName("caseSensitive");
    result->case_sensitive_ = internal::FromValue<bool>::Parse(*case_sensitive_value, errors);
  }
  const base::Value* is_regex_value = value.FindKey("isRegex");
  if (is_regex_value) {
    errors->SetName("isRegex");
    result->is_regex_ = internal::FromValue<bool>::Parse(*is_regex_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SearchInResponseBodyParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("query", internal::ToValue(query_));
  if (case_sensitive_)
    result->Set("caseSensitive", internal::ToValue(case_sensitive_.value()));
  if (is_regex_)
    result->Set("isRegex", internal::ToValue(is_regex_.value()));
  return std::move(result);
}

std::unique_ptr<SearchInResponseBodyParams> SearchInResponseBodyParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SearchInResponseBodyParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SearchInResponseBodyResult> SearchInResponseBodyResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SearchInResponseBodyResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SearchInResponseBodyResult> result(new SearchInResponseBodyResult());
  errors->Push();
  errors->SetName("SearchInResponseBodyResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::debugger::SearchMatch>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SearchInResponseBodyResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  return std::move(result);
}

std::unique_ptr<SearchInResponseBodyResult> SearchInResponseBodyResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SearchInResponseBodyResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetBlockedURLsParams> SetBlockedURLsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetBlockedURLsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetBlockedURLsParams> result(new SetBlockedURLsParams());
  errors->Push();
  errors->SetName("SetBlockedURLsParams");
  const base::Value* urls_value = value.FindKey("urls");
  if (urls_value) {
    errors->SetName("urls");
    result->urls_ = internal::FromValue<std::vector<std::string>>::Parse(*urls_value, errors);
  } else {
    errors->AddError("required property missing: urls");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetBlockedURLsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("urls", internal::ToValue(urls_));
  return std::move(result);
}

std::unique_ptr<SetBlockedURLsParams> SetBlockedURLsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetBlockedURLsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetBlockedURLsResult> SetBlockedURLsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetBlockedURLsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetBlockedURLsResult> result(new SetBlockedURLsResult());
  errors->Push();
  errors->SetName("SetBlockedURLsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetBlockedURLsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetBlockedURLsResult> SetBlockedURLsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetBlockedURLsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetBypassServiceWorkerParams> SetBypassServiceWorkerParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetBypassServiceWorkerParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetBypassServiceWorkerParams> result(new SetBypassServiceWorkerParams());
  errors->Push();
  errors->SetName("SetBypassServiceWorkerParams");
  const base::Value* bypass_value = value.FindKey("bypass");
  if (bypass_value) {
    errors->SetName("bypass");
    result->bypass_ = internal::FromValue<bool>::Parse(*bypass_value, errors);
  } else {
    errors->AddError("required property missing: bypass");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetBypassServiceWorkerParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("bypass", internal::ToValue(bypass_));
  return std::move(result);
}

std::unique_ptr<SetBypassServiceWorkerParams> SetBypassServiceWorkerParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetBypassServiceWorkerParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetBypassServiceWorkerResult> SetBypassServiceWorkerResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetBypassServiceWorkerResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetBypassServiceWorkerResult> result(new SetBypassServiceWorkerResult());
  errors->Push();
  errors->SetName("SetBypassServiceWorkerResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetBypassServiceWorkerResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetBypassServiceWorkerResult> SetBypassServiceWorkerResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetBypassServiceWorkerResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCacheDisabledParams> SetCacheDisabledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCacheDisabledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCacheDisabledParams> result(new SetCacheDisabledParams());
  errors->Push();
  errors->SetName("SetCacheDisabledParams");
  const base::Value* cache_disabled_value = value.FindKey("cacheDisabled");
  if (cache_disabled_value) {
    errors->SetName("cacheDisabled");
    result->cache_disabled_ = internal::FromValue<bool>::Parse(*cache_disabled_value, errors);
  } else {
    errors->AddError("required property missing: cacheDisabled");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCacheDisabledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cacheDisabled", internal::ToValue(cache_disabled_));
  return std::move(result);
}

std::unique_ptr<SetCacheDisabledParams> SetCacheDisabledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCacheDisabledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCacheDisabledResult> SetCacheDisabledResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCacheDisabledResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCacheDisabledResult> result(new SetCacheDisabledResult());
  errors->Push();
  errors->SetName("SetCacheDisabledResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCacheDisabledResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetCacheDisabledResult> SetCacheDisabledResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCacheDisabledResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCookieParams> SetCookieParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCookieParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCookieParams> result(new SetCookieParams());
  errors->Push();
  errors->SetName("SetCookieParams");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* domain_value = value.FindKey("domain");
  if (domain_value) {
    errors->SetName("domain");
    result->domain_ = internal::FromValue<std::string>::Parse(*domain_value, errors);
  }
  const base::Value* path_value = value.FindKey("path");
  if (path_value) {
    errors->SetName("path");
    result->path_ = internal::FromValue<std::string>::Parse(*path_value, errors);
  }
  const base::Value* secure_value = value.FindKey("secure");
  if (secure_value) {
    errors->SetName("secure");
    result->secure_ = internal::FromValue<bool>::Parse(*secure_value, errors);
  }
  const base::Value* http_only_value = value.FindKey("httpOnly");
  if (http_only_value) {
    errors->SetName("httpOnly");
    result->http_only_ = internal::FromValue<bool>::Parse(*http_only_value, errors);
  }
  const base::Value* same_site_value = value.FindKey("sameSite");
  if (same_site_value) {
    errors->SetName("sameSite");
    result->same_site_ = internal::FromValue<::headless::network::CookieSameSite>::Parse(*same_site_value, errors);
  }
  const base::Value* expires_value = value.FindKey("expires");
  if (expires_value) {
    errors->SetName("expires");
    result->expires_ = internal::FromValue<double>::Parse(*expires_value, errors);
  }
  const base::Value* priority_value = value.FindKey("priority");
  if (priority_value) {
    errors->SetName("priority");
    result->priority_ = internal::FromValue<::headless::network::CookiePriority>::Parse(*priority_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCookieParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (domain_)
    result->Set("domain", internal::ToValue(domain_.value()));
  if (path_)
    result->Set("path", internal::ToValue(path_.value()));
  if (secure_)
    result->Set("secure", internal::ToValue(secure_.value()));
  if (http_only_)
    result->Set("httpOnly", internal::ToValue(http_only_.value()));
  if (same_site_)
    result->Set("sameSite", internal::ToValue(same_site_.value()));
  if (expires_)
    result->Set("expires", internal::ToValue(expires_.value()));
  if (priority_)
    result->Set("priority", internal::ToValue(priority_.value()));
  return std::move(result);
}

std::unique_ptr<SetCookieParams> SetCookieParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCookieParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCookieResult> SetCookieResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCookieResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCookieResult> result(new SetCookieResult());
  errors->Push();
  errors->SetName("SetCookieResult");
  const base::Value* success_value = value.FindKey("success");
  if (success_value) {
    errors->SetName("success");
    result->success_ = internal::FromValue<bool>::Parse(*success_value, errors);
  } else {
    errors->AddError("required property missing: success");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCookieResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("success", internal::ToValue(success_));
  return std::move(result);
}

std::unique_ptr<SetCookieResult> SetCookieResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCookieResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCookiesParams> SetCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCookiesParams> result(new SetCookiesParams());
  errors->Push();
  errors->SetName("SetCookiesParams");
  const base::Value* cookies_value = value.FindKey("cookies");
  if (cookies_value) {
    errors->SetName("cookies");
    result->cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::CookieParam>>>::Parse(*cookies_value, errors);
  } else {
    errors->AddError("required property missing: cookies");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookies", internal::ToValue(cookies_));
  return std::move(result);
}

std::unique_ptr<SetCookiesParams> SetCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCookiesResult> SetCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCookiesResult> result(new SetCookiesResult());
  errors->Push();
  errors->SetName("SetCookiesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetCookiesResult> SetCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDataSizeLimitsForTestParams> SetDataSizeLimitsForTestParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDataSizeLimitsForTestParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDataSizeLimitsForTestParams> result(new SetDataSizeLimitsForTestParams());
  errors->Push();
  errors->SetName("SetDataSizeLimitsForTestParams");
  const base::Value* max_total_size_value = value.FindKey("maxTotalSize");
  if (max_total_size_value) {
    errors->SetName("maxTotalSize");
    result->max_total_size_ = internal::FromValue<int>::Parse(*max_total_size_value, errors);
  } else {
    errors->AddError("required property missing: maxTotalSize");
  }
  const base::Value* max_resource_size_value = value.FindKey("maxResourceSize");
  if (max_resource_size_value) {
    errors->SetName("maxResourceSize");
    result->max_resource_size_ = internal::FromValue<int>::Parse(*max_resource_size_value, errors);
  } else {
    errors->AddError("required property missing: maxResourceSize");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDataSizeLimitsForTestParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("maxTotalSize", internal::ToValue(max_total_size_));
  result->Set("maxResourceSize", internal::ToValue(max_resource_size_));
  return std::move(result);
}

std::unique_ptr<SetDataSizeLimitsForTestParams> SetDataSizeLimitsForTestParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDataSizeLimitsForTestParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDataSizeLimitsForTestResult> SetDataSizeLimitsForTestResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDataSizeLimitsForTestResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDataSizeLimitsForTestResult> result(new SetDataSizeLimitsForTestResult());
  errors->Push();
  errors->SetName("SetDataSizeLimitsForTestResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDataSizeLimitsForTestResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDataSizeLimitsForTestResult> SetDataSizeLimitsForTestResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDataSizeLimitsForTestResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetExtraHTTPHeadersParams> SetExtraHTTPHeadersParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetExtraHTTPHeadersParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetExtraHTTPHeadersParams> result(new SetExtraHTTPHeadersParams());
  errors->Push();
  errors->SetName("SetExtraHTTPHeadersParams");
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  } else {
    errors->AddError("required property missing: headers");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetExtraHTTPHeadersParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("headers", internal::ToValue(*headers_));
  return std::move(result);
}

std::unique_ptr<SetExtraHTTPHeadersParams> SetExtraHTTPHeadersParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetExtraHTTPHeadersParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetExtraHTTPHeadersResult> SetExtraHTTPHeadersResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetExtraHTTPHeadersResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetExtraHTTPHeadersResult> result(new SetExtraHTTPHeadersResult());
  errors->Push();
  errors->SetName("SetExtraHTTPHeadersResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetExtraHTTPHeadersResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetExtraHTTPHeadersResult> SetExtraHTTPHeadersResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetExtraHTTPHeadersResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRequestInterceptionParams> SetRequestInterceptionParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRequestInterceptionParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRequestInterceptionParams> result(new SetRequestInterceptionParams());
  errors->Push();
  errors->SetName("SetRequestInterceptionParams");
  const base::Value* patterns_value = value.FindKey("patterns");
  if (patterns_value) {
    errors->SetName("patterns");
    result->patterns_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::RequestPattern>>>::Parse(*patterns_value, errors);
  } else {
    errors->AddError("required property missing: patterns");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRequestInterceptionParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("patterns", internal::ToValue(patterns_));
  return std::move(result);
}

std::unique_ptr<SetRequestInterceptionParams> SetRequestInterceptionParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRequestInterceptionParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRequestInterceptionResult> SetRequestInterceptionResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRequestInterceptionResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRequestInterceptionResult> result(new SetRequestInterceptionResult());
  errors->Push();
  errors->SetName("SetRequestInterceptionResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRequestInterceptionResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetRequestInterceptionResult> SetRequestInterceptionResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRequestInterceptionResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetUserAgentOverrideParams> SetUserAgentOverrideParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetUserAgentOverrideParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetUserAgentOverrideParams> result(new SetUserAgentOverrideParams());
  errors->Push();
  errors->SetName("SetUserAgentOverrideParams");
  const base::Value* user_agent_value = value.FindKey("userAgent");
  if (user_agent_value) {
    errors->SetName("userAgent");
    result->user_agent_ = internal::FromValue<std::string>::Parse(*user_agent_value, errors);
  } else {
    errors->AddError("required property missing: userAgent");
  }
  const base::Value* accept_language_value = value.FindKey("acceptLanguage");
  if (accept_language_value) {
    errors->SetName("acceptLanguage");
    result->accept_language_ = internal::FromValue<std::string>::Parse(*accept_language_value, errors);
  }
  const base::Value* platform_value = value.FindKey("platform");
  if (platform_value) {
    errors->SetName("platform");
    result->platform_ = internal::FromValue<std::string>::Parse(*platform_value, errors);
  }
  const base::Value* user_agent_metadata_value = value.FindKey("userAgentMetadata");
  if (user_agent_metadata_value) {
    errors->SetName("userAgentMetadata");
    result->user_agent_metadata_ = internal::FromValue<::headless::emulation::UserAgentMetadata>::Parse(*user_agent_metadata_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetUserAgentOverrideParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("userAgent", internal::ToValue(user_agent_));
  if (accept_language_)
    result->Set("acceptLanguage", internal::ToValue(accept_language_.value()));
  if (platform_)
    result->Set("platform", internal::ToValue(platform_.value()));
  if (user_agent_metadata_)
    result->Set("userAgentMetadata", internal::ToValue(*user_agent_metadata_.value()));
  return std::move(result);
}

std::unique_ptr<SetUserAgentOverrideParams> SetUserAgentOverrideParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetUserAgentOverrideParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetUserAgentOverrideResult> SetUserAgentOverrideResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetUserAgentOverrideResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetUserAgentOverrideResult> result(new SetUserAgentOverrideResult());
  errors->Push();
  errors->SetName("SetUserAgentOverrideResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetUserAgentOverrideResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetUserAgentOverrideResult> SetUserAgentOverrideResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetUserAgentOverrideResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DataReceivedParams> DataReceivedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DataReceivedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DataReceivedParams> result(new DataReceivedParams());
  errors->Push();
  errors->SetName("DataReceivedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* data_length_value = value.FindKey("dataLength");
  if (data_length_value) {
    errors->SetName("dataLength");
    result->data_length_ = internal::FromValue<int>::Parse(*data_length_value, errors);
  } else {
    errors->AddError("required property missing: dataLength");
  }
  const base::Value* encoded_data_length_value = value.FindKey("encodedDataLength");
  if (encoded_data_length_value) {
    errors->SetName("encodedDataLength");
    result->encoded_data_length_ = internal::FromValue<int>::Parse(*encoded_data_length_value, errors);
  } else {
    errors->AddError("required property missing: encodedDataLength");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DataReceivedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("dataLength", internal::ToValue(data_length_));
  result->Set("encodedDataLength", internal::ToValue(encoded_data_length_));
  return std::move(result);
}

std::unique_ptr<DataReceivedParams> DataReceivedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DataReceivedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EventSourceMessageReceivedParams> EventSourceMessageReceivedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EventSourceMessageReceivedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EventSourceMessageReceivedParams> result(new EventSourceMessageReceivedParams());
  errors->Push();
  errors->SetName("EventSourceMessageReceivedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* event_name_value = value.FindKey("eventName");
  if (event_name_value) {
    errors->SetName("eventName");
    result->event_name_ = internal::FromValue<std::string>::Parse(*event_name_value, errors);
  } else {
    errors->AddError("required property missing: eventName");
  }
  const base::Value* event_id_value = value.FindKey("eventId");
  if (event_id_value) {
    errors->SetName("eventId");
    result->event_id_ = internal::FromValue<std::string>::Parse(*event_id_value, errors);
  } else {
    errors->AddError("required property missing: eventId");
  }
  const base::Value* data_value = value.FindKey("data");
  if (data_value) {
    errors->SetName("data");
    result->data_ = internal::FromValue<std::string>::Parse(*data_value, errors);
  } else {
    errors->AddError("required property missing: data");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EventSourceMessageReceivedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("eventName", internal::ToValue(event_name_));
  result->Set("eventId", internal::ToValue(event_id_));
  result->Set("data", internal::ToValue(data_));
  return std::move(result);
}

std::unique_ptr<EventSourceMessageReceivedParams> EventSourceMessageReceivedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EventSourceMessageReceivedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LoadingFailedParams> LoadingFailedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LoadingFailedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LoadingFailedParams> result(new LoadingFailedParams());
  errors->Push();
  errors->SetName("LoadingFailedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::network::ResourceType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* error_text_value = value.FindKey("errorText");
  if (error_text_value) {
    errors->SetName("errorText");
    result->error_text_ = internal::FromValue<std::string>::Parse(*error_text_value, errors);
  } else {
    errors->AddError("required property missing: errorText");
  }
  const base::Value* canceled_value = value.FindKey("canceled");
  if (canceled_value) {
    errors->SetName("canceled");
    result->canceled_ = internal::FromValue<bool>::Parse(*canceled_value, errors);
  }
  const base::Value* blocked_reason_value = value.FindKey("blockedReason");
  if (blocked_reason_value) {
    errors->SetName("blockedReason");
    result->blocked_reason_ = internal::FromValue<::headless::network::BlockedReason>::Parse(*blocked_reason_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LoadingFailedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("type", internal::ToValue(type_));
  result->Set("errorText", internal::ToValue(error_text_));
  if (canceled_)
    result->Set("canceled", internal::ToValue(canceled_.value()));
  if (blocked_reason_)
    result->Set("blockedReason", internal::ToValue(blocked_reason_.value()));
  return std::move(result);
}

std::unique_ptr<LoadingFailedParams> LoadingFailedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LoadingFailedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LoadingFinishedParams> LoadingFinishedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LoadingFinishedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LoadingFinishedParams> result(new LoadingFinishedParams());
  errors->Push();
  errors->SetName("LoadingFinishedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* encoded_data_length_value = value.FindKey("encodedDataLength");
  if (encoded_data_length_value) {
    errors->SetName("encodedDataLength");
    result->encoded_data_length_ = internal::FromValue<double>::Parse(*encoded_data_length_value, errors);
  } else {
    errors->AddError("required property missing: encodedDataLength");
  }
  const base::Value* should_report_corb_blocking_value = value.FindKey("shouldReportCorbBlocking");
  if (should_report_corb_blocking_value) {
    errors->SetName("shouldReportCorbBlocking");
    result->should_report_corb_blocking_ = internal::FromValue<bool>::Parse(*should_report_corb_blocking_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LoadingFinishedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("encodedDataLength", internal::ToValue(encoded_data_length_));
  if (should_report_corb_blocking_)
    result->Set("shouldReportCorbBlocking", internal::ToValue(should_report_corb_blocking_.value()));
  return std::move(result);
}

std::unique_ptr<LoadingFinishedParams> LoadingFinishedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LoadingFinishedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestInterceptedParams> RequestInterceptedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestInterceptedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestInterceptedParams> result(new RequestInterceptedParams());
  errors->Push();
  errors->SetName("RequestInterceptedParams");
  const base::Value* interception_id_value = value.FindKey("interceptionId");
  if (interception_id_value) {
    errors->SetName("interceptionId");
    result->interception_id_ = internal::FromValue<std::string>::Parse(*interception_id_value, errors);
  } else {
    errors->AddError("required property missing: interceptionId");
  }
  const base::Value* request_value = value.FindKey("request");
  if (request_value) {
    errors->SetName("request");
    result->request_ = internal::FromValue<::headless::network::Request>::Parse(*request_value, errors);
  } else {
    errors->AddError("required property missing: request");
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* resource_type_value = value.FindKey("resourceType");
  if (resource_type_value) {
    errors->SetName("resourceType");
    result->resource_type_ = internal::FromValue<::headless::network::ResourceType>::Parse(*resource_type_value, errors);
  } else {
    errors->AddError("required property missing: resourceType");
  }
  const base::Value* is_navigation_request_value = value.FindKey("isNavigationRequest");
  if (is_navigation_request_value) {
    errors->SetName("isNavigationRequest");
    result->is_navigation_request_ = internal::FromValue<bool>::Parse(*is_navigation_request_value, errors);
  } else {
    errors->AddError("required property missing: isNavigationRequest");
  }
  const base::Value* is_download_value = value.FindKey("isDownload");
  if (is_download_value) {
    errors->SetName("isDownload");
    result->is_download_ = internal::FromValue<bool>::Parse(*is_download_value, errors);
  }
  const base::Value* redirect_url_value = value.FindKey("redirectUrl");
  if (redirect_url_value) {
    errors->SetName("redirectUrl");
    result->redirect_url_ = internal::FromValue<std::string>::Parse(*redirect_url_value, errors);
  }
  const base::Value* auth_challenge_value = value.FindKey("authChallenge");
  if (auth_challenge_value) {
    errors->SetName("authChallenge");
    result->auth_challenge_ = internal::FromValue<::headless::network::AuthChallenge>::Parse(*auth_challenge_value, errors);
  }
  const base::Value* response_error_reason_value = value.FindKey("responseErrorReason");
  if (response_error_reason_value) {
    errors->SetName("responseErrorReason");
    result->response_error_reason_ = internal::FromValue<::headless::network::ErrorReason>::Parse(*response_error_reason_value, errors);
  }
  const base::Value* response_status_code_value = value.FindKey("responseStatusCode");
  if (response_status_code_value) {
    errors->SetName("responseStatusCode");
    result->response_status_code_ = internal::FromValue<int>::Parse(*response_status_code_value, errors);
  }
  const base::Value* response_headers_value = value.FindKey("responseHeaders");
  if (response_headers_value) {
    errors->SetName("responseHeaders");
    result->response_headers_ = internal::FromValue<base::DictionaryValue>::Parse(*response_headers_value, errors);
  }
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestInterceptedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("interceptionId", internal::ToValue(interception_id_));
  result->Set("request", internal::ToValue(*request_));
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("resourceType", internal::ToValue(resource_type_));
  result->Set("isNavigationRequest", internal::ToValue(is_navigation_request_));
  if (is_download_)
    result->Set("isDownload", internal::ToValue(is_download_.value()));
  if (redirect_url_)
    result->Set("redirectUrl", internal::ToValue(redirect_url_.value()));
  if (auth_challenge_)
    result->Set("authChallenge", internal::ToValue(*auth_challenge_.value()));
  if (response_error_reason_)
    result->Set("responseErrorReason", internal::ToValue(response_error_reason_.value()));
  if (response_status_code_)
    result->Set("responseStatusCode", internal::ToValue(response_status_code_.value()));
  if (response_headers_)
    result->Set("responseHeaders", internal::ToValue(*response_headers_.value()));
  if (request_id_)
    result->Set("requestId", internal::ToValue(request_id_.value()));
  return std::move(result);
}

std::unique_ptr<RequestInterceptedParams> RequestInterceptedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestInterceptedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestServedFromCacheParams> RequestServedFromCacheParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestServedFromCacheParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestServedFromCacheParams> result(new RequestServedFromCacheParams());
  errors->Push();
  errors->SetName("RequestServedFromCacheParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestServedFromCacheParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  return std::move(result);
}

std::unique_ptr<RequestServedFromCacheParams> RequestServedFromCacheParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestServedFromCacheParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestWillBeSentParams> RequestWillBeSentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestWillBeSentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestWillBeSentParams> result(new RequestWillBeSentParams());
  errors->Push();
  errors->SetName("RequestWillBeSentParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* loader_id_value = value.FindKey("loaderId");
  if (loader_id_value) {
    errors->SetName("loaderId");
    result->loader_id_ = internal::FromValue<std::string>::Parse(*loader_id_value, errors);
  } else {
    errors->AddError("required property missing: loaderId");
  }
  const base::Value* documenturl_value = value.FindKey("documentURL");
  if (documenturl_value) {
    errors->SetName("documentURL");
    result->documenturl_ = internal::FromValue<std::string>::Parse(*documenturl_value, errors);
  } else {
    errors->AddError("required property missing: documentURL");
  }
  const base::Value* request_value = value.FindKey("request");
  if (request_value) {
    errors->SetName("request");
    result->request_ = internal::FromValue<::headless::network::Request>::Parse(*request_value, errors);
  } else {
    errors->AddError("required property missing: request");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* wall_time_value = value.FindKey("wallTime");
  if (wall_time_value) {
    errors->SetName("wallTime");
    result->wall_time_ = internal::FromValue<double>::Parse(*wall_time_value, errors);
  } else {
    errors->AddError("required property missing: wallTime");
  }
  const base::Value* initiator_value = value.FindKey("initiator");
  if (initiator_value) {
    errors->SetName("initiator");
    result->initiator_ = internal::FromValue<::headless::network::Initiator>::Parse(*initiator_value, errors);
  } else {
    errors->AddError("required property missing: initiator");
  }
  const base::Value* redirect_response_value = value.FindKey("redirectResponse");
  if (redirect_response_value) {
    errors->SetName("redirectResponse");
    result->redirect_response_ = internal::FromValue<::headless::network::Response>::Parse(*redirect_response_value, errors);
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::network::ResourceType>::Parse(*type_value, errors);
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  }
  const base::Value* has_user_gesture_value = value.FindKey("hasUserGesture");
  if (has_user_gesture_value) {
    errors->SetName("hasUserGesture");
    result->has_user_gesture_ = internal::FromValue<bool>::Parse(*has_user_gesture_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestWillBeSentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("loaderId", internal::ToValue(loader_id_));
  result->Set("documentURL", internal::ToValue(documenturl_));
  result->Set("request", internal::ToValue(*request_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("wallTime", internal::ToValue(wall_time_));
  result->Set("initiator", internal::ToValue(*initiator_));
  if (redirect_response_)
    result->Set("redirectResponse", internal::ToValue(*redirect_response_.value()));
  if (type_)
    result->Set("type", internal::ToValue(type_.value()));
  if (frame_id_)
    result->Set("frameId", internal::ToValue(frame_id_.value()));
  if (has_user_gesture_)
    result->Set("hasUserGesture", internal::ToValue(has_user_gesture_.value()));
  return std::move(result);
}

std::unique_ptr<RequestWillBeSentParams> RequestWillBeSentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestWillBeSentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResourceChangedPriorityParams> ResourceChangedPriorityParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResourceChangedPriorityParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResourceChangedPriorityParams> result(new ResourceChangedPriorityParams());
  errors->Push();
  errors->SetName("ResourceChangedPriorityParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* new_priority_value = value.FindKey("newPriority");
  if (new_priority_value) {
    errors->SetName("newPriority");
    result->new_priority_ = internal::FromValue<::headless::network::ResourcePriority>::Parse(*new_priority_value, errors);
  } else {
    errors->AddError("required property missing: newPriority");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResourceChangedPriorityParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("newPriority", internal::ToValue(new_priority_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<ResourceChangedPriorityParams> ResourceChangedPriorityParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResourceChangedPriorityParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SignedExchangeReceivedParams> SignedExchangeReceivedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SignedExchangeReceivedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SignedExchangeReceivedParams> result(new SignedExchangeReceivedParams());
  errors->Push();
  errors->SetName("SignedExchangeReceivedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* info_value = value.FindKey("info");
  if (info_value) {
    errors->SetName("info");
    result->info_ = internal::FromValue<::headless::network::SignedExchangeInfo>::Parse(*info_value, errors);
  } else {
    errors->AddError("required property missing: info");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SignedExchangeReceivedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("info", internal::ToValue(*info_));
  return std::move(result);
}

std::unique_ptr<SignedExchangeReceivedParams> SignedExchangeReceivedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SignedExchangeReceivedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResponseReceivedParams> ResponseReceivedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResponseReceivedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResponseReceivedParams> result(new ResponseReceivedParams());
  errors->Push();
  errors->SetName("ResponseReceivedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* loader_id_value = value.FindKey("loaderId");
  if (loader_id_value) {
    errors->SetName("loaderId");
    result->loader_id_ = internal::FromValue<std::string>::Parse(*loader_id_value, errors);
  } else {
    errors->AddError("required property missing: loaderId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::network::ResourceType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* response_value = value.FindKey("response");
  if (response_value) {
    errors->SetName("response");
    result->response_ = internal::FromValue<::headless::network::Response>::Parse(*response_value, errors);
  } else {
    errors->AddError("required property missing: response");
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResponseReceivedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("loaderId", internal::ToValue(loader_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("type", internal::ToValue(type_));
  result->Set("response", internal::ToValue(*response_));
  if (frame_id_)
    result->Set("frameId", internal::ToValue(frame_id_.value()));
  return std::move(result);
}

std::unique_ptr<ResponseReceivedParams> ResponseReceivedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResponseReceivedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketClosedParams> WebSocketClosedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketClosedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketClosedParams> result(new WebSocketClosedParams());
  errors->Push();
  errors->SetName("WebSocketClosedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketClosedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<WebSocketClosedParams> WebSocketClosedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketClosedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketCreatedParams> WebSocketCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketCreatedParams> result(new WebSocketCreatedParams());
  errors->Push();
  errors->SetName("WebSocketCreatedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* initiator_value = value.FindKey("initiator");
  if (initiator_value) {
    errors->SetName("initiator");
    result->initiator_ = internal::FromValue<::headless::network::Initiator>::Parse(*initiator_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("url", internal::ToValue(url_));
  if (initiator_)
    result->Set("initiator", internal::ToValue(*initiator_.value()));
  return std::move(result);
}

std::unique_ptr<WebSocketCreatedParams> WebSocketCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketFrameErrorParams> WebSocketFrameErrorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketFrameErrorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketFrameErrorParams> result(new WebSocketFrameErrorParams());
  errors->Push();
  errors->SetName("WebSocketFrameErrorParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* error_message_value = value.FindKey("errorMessage");
  if (error_message_value) {
    errors->SetName("errorMessage");
    result->error_message_ = internal::FromValue<std::string>::Parse(*error_message_value, errors);
  } else {
    errors->AddError("required property missing: errorMessage");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketFrameErrorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("errorMessage", internal::ToValue(error_message_));
  return std::move(result);
}

std::unique_ptr<WebSocketFrameErrorParams> WebSocketFrameErrorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketFrameErrorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketFrameReceivedParams> WebSocketFrameReceivedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketFrameReceivedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketFrameReceivedParams> result(new WebSocketFrameReceivedParams());
  errors->Push();
  errors->SetName("WebSocketFrameReceivedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* response_value = value.FindKey("response");
  if (response_value) {
    errors->SetName("response");
    result->response_ = internal::FromValue<::headless::network::WebSocketFrame>::Parse(*response_value, errors);
  } else {
    errors->AddError("required property missing: response");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketFrameReceivedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("response", internal::ToValue(*response_));
  return std::move(result);
}

std::unique_ptr<WebSocketFrameReceivedParams> WebSocketFrameReceivedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketFrameReceivedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketFrameSentParams> WebSocketFrameSentParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketFrameSentParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketFrameSentParams> result(new WebSocketFrameSentParams());
  errors->Push();
  errors->SetName("WebSocketFrameSentParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* response_value = value.FindKey("response");
  if (response_value) {
    errors->SetName("response");
    result->response_ = internal::FromValue<::headless::network::WebSocketFrame>::Parse(*response_value, errors);
  } else {
    errors->AddError("required property missing: response");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketFrameSentParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("response", internal::ToValue(*response_));
  return std::move(result);
}

std::unique_ptr<WebSocketFrameSentParams> WebSocketFrameSentParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketFrameSentParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketHandshakeResponseReceivedParams> WebSocketHandshakeResponseReceivedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketHandshakeResponseReceivedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketHandshakeResponseReceivedParams> result(new WebSocketHandshakeResponseReceivedParams());
  errors->Push();
  errors->SetName("WebSocketHandshakeResponseReceivedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* response_value = value.FindKey("response");
  if (response_value) {
    errors->SetName("response");
    result->response_ = internal::FromValue<::headless::network::WebSocketResponse>::Parse(*response_value, errors);
  } else {
    errors->AddError("required property missing: response");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketHandshakeResponseReceivedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("response", internal::ToValue(*response_));
  return std::move(result);
}

std::unique_ptr<WebSocketHandshakeResponseReceivedParams> WebSocketHandshakeResponseReceivedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketHandshakeResponseReceivedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<WebSocketWillSendHandshakeRequestParams> WebSocketWillSendHandshakeRequestParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("WebSocketWillSendHandshakeRequestParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<WebSocketWillSendHandshakeRequestParams> result(new WebSocketWillSendHandshakeRequestParams());
  errors->Push();
  errors->SetName("WebSocketWillSendHandshakeRequestParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* wall_time_value = value.FindKey("wallTime");
  if (wall_time_value) {
    errors->SetName("wallTime");
    result->wall_time_ = internal::FromValue<double>::Parse(*wall_time_value, errors);
  } else {
    errors->AddError("required property missing: wallTime");
  }
  const base::Value* request_value = value.FindKey("request");
  if (request_value) {
    errors->SetName("request");
    result->request_ = internal::FromValue<::headless::network::WebSocketRequest>::Parse(*request_value, errors);
  } else {
    errors->AddError("required property missing: request");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> WebSocketWillSendHandshakeRequestParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("wallTime", internal::ToValue(wall_time_));
  result->Set("request", internal::ToValue(*request_));
  return std::move(result);
}

std::unique_ptr<WebSocketWillSendHandshakeRequestParams> WebSocketWillSendHandshakeRequestParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<WebSocketWillSendHandshakeRequestParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestWillBeSentExtraInfoParams> RequestWillBeSentExtraInfoParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestWillBeSentExtraInfoParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestWillBeSentExtraInfoParams> result(new RequestWillBeSentExtraInfoParams());
  errors->Push();
  errors->SetName("RequestWillBeSentExtraInfoParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* associated_cookies_value = value.FindKey("associatedCookies");
  if (associated_cookies_value) {
    errors->SetName("associatedCookies");
    result->associated_cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::BlockedCookieWithReason>>>::Parse(*associated_cookies_value, errors);
  } else {
    errors->AddError("required property missing: associatedCookies");
  }
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  } else {
    errors->AddError("required property missing: headers");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestWillBeSentExtraInfoParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("associatedCookies", internal::ToValue(associated_cookies_));
  result->Set("headers", internal::ToValue(*headers_));
  return std::move(result);
}

std::unique_ptr<RequestWillBeSentExtraInfoParams> RequestWillBeSentExtraInfoParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestWillBeSentExtraInfoParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResponseReceivedExtraInfoParams> ResponseReceivedExtraInfoParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResponseReceivedExtraInfoParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResponseReceivedExtraInfoParams> result(new ResponseReceivedExtraInfoParams());
  errors->Push();
  errors->SetName("ResponseReceivedExtraInfoParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* blocked_cookies_value = value.FindKey("blockedCookies");
  if (blocked_cookies_value) {
    errors->SetName("blockedCookies");
    result->blocked_cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::BlockedSetCookieWithReason>>>::Parse(*blocked_cookies_value, errors);
  } else {
    errors->AddError("required property missing: blockedCookies");
  }
  const base::Value* headers_value = value.FindKey("headers");
  if (headers_value) {
    errors->SetName("headers");
    result->headers_ = internal::FromValue<base::DictionaryValue>::Parse(*headers_value, errors);
  } else {
    errors->AddError("required property missing: headers");
  }
  const base::Value* headers_text_value = value.FindKey("headersText");
  if (headers_text_value) {
    errors->SetName("headersText");
    result->headers_text_ = internal::FromValue<std::string>::Parse(*headers_text_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResponseReceivedExtraInfoParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("blockedCookies", internal::ToValue(blocked_cookies_));
  result->Set("headers", internal::ToValue(*headers_));
  if (headers_text_)
    result->Set("headersText", internal::ToValue(headers_text_.value()));
  return std::move(result);
}

std::unique_ptr<ResponseReceivedExtraInfoParams> ResponseReceivedExtraInfoParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResponseReceivedExtraInfoParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace network
}  // namespace headless
