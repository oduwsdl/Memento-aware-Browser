// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_audits.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_audits.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace audits {

std::unique_ptr<AffectedCookie> AffectedCookie::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AffectedCookie");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AffectedCookie> result(new AffectedCookie());
  errors->Push();
  errors->SetName("AffectedCookie");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* path_value = value.FindKey("path");
  if (path_value) {
    errors->SetName("path");
    result->path_ = internal::FromValue<std::string>::Parse(*path_value, errors);
  } else {
    errors->AddError("required property missing: path");
  }
  const base::Value* domain_value = value.FindKey("domain");
  if (domain_value) {
    errors->SetName("domain");
    result->domain_ = internal::FromValue<std::string>::Parse(*domain_value, errors);
  } else {
    errors->AddError("required property missing: domain");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AffectedCookie::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("path", internal::ToValue(path_));
  result->Set("domain", internal::ToValue(domain_));
  return std::move(result);
}

std::unique_ptr<AffectedCookie> AffectedCookie::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AffectedCookie> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AffectedRequest> AffectedRequest::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AffectedRequest");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AffectedRequest> result(new AffectedRequest());
  errors->Push();
  errors->SetName("AffectedRequest");
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
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AffectedRequest::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  return std::move(result);
}

std::unique_ptr<AffectedRequest> AffectedRequest::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AffectedRequest> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AffectedFrame> AffectedFrame::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AffectedFrame");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AffectedFrame> result(new AffectedFrame());
  errors->Push();
  errors->SetName("AffectedFrame");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AffectedFrame::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<AffectedFrame> AffectedFrame::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AffectedFrame> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SameSiteCookieIssueDetails> SameSiteCookieIssueDetails::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SameSiteCookieIssueDetails");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SameSiteCookieIssueDetails> result(new SameSiteCookieIssueDetails());
  errors->Push();
  errors->SetName("SameSiteCookieIssueDetails");
  const base::Value* cookie_value = value.FindKey("cookie");
  if (cookie_value) {
    errors->SetName("cookie");
    result->cookie_ = internal::FromValue<::headless::audits::AffectedCookie>::Parse(*cookie_value, errors);
  } else {
    errors->AddError("required property missing: cookie");
  }
  const base::Value* cookie_warning_reasons_value = value.FindKey("cookieWarningReasons");
  if (cookie_warning_reasons_value) {
    errors->SetName("cookieWarningReasons");
    result->cookie_warning_reasons_ = internal::FromValue<std::vector<::headless::audits::SameSiteCookieWarningReason>>::Parse(*cookie_warning_reasons_value, errors);
  } else {
    errors->AddError("required property missing: cookieWarningReasons");
  }
  const base::Value* cookie_exclusion_reasons_value = value.FindKey("cookieExclusionReasons");
  if (cookie_exclusion_reasons_value) {
    errors->SetName("cookieExclusionReasons");
    result->cookie_exclusion_reasons_ = internal::FromValue<std::vector<::headless::audits::SameSiteCookieExclusionReason>>::Parse(*cookie_exclusion_reasons_value, errors);
  } else {
    errors->AddError("required property missing: cookieExclusionReasons");
  }
  const base::Value* operation_value = value.FindKey("operation");
  if (operation_value) {
    errors->SetName("operation");
    result->operation_ = internal::FromValue<::headless::audits::SameSiteCookieOperation>::Parse(*operation_value, errors);
  } else {
    errors->AddError("required property missing: operation");
  }
  const base::Value* site_for_cookies_value = value.FindKey("siteForCookies");
  if (site_for_cookies_value) {
    errors->SetName("siteForCookies");
    result->site_for_cookies_ = internal::FromValue<std::string>::Parse(*site_for_cookies_value, errors);
  }
  const base::Value* cookie_url_value = value.FindKey("cookieUrl");
  if (cookie_url_value) {
    errors->SetName("cookieUrl");
    result->cookie_url_ = internal::FromValue<std::string>::Parse(*cookie_url_value, errors);
  }
  const base::Value* request_value = value.FindKey("request");
  if (request_value) {
    errors->SetName("request");
    result->request_ = internal::FromValue<::headless::audits::AffectedRequest>::Parse(*request_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SameSiteCookieIssueDetails::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookie", internal::ToValue(*cookie_));
  result->Set("cookieWarningReasons", internal::ToValue(cookie_warning_reasons_));
  result->Set("cookieExclusionReasons", internal::ToValue(cookie_exclusion_reasons_));
  result->Set("operation", internal::ToValue(operation_));
  if (site_for_cookies_)
    result->Set("siteForCookies", internal::ToValue(site_for_cookies_.value()));
  if (cookie_url_)
    result->Set("cookieUrl", internal::ToValue(cookie_url_.value()));
  if (request_)
    result->Set("request", internal::ToValue(*request_.value()));
  return std::move(result);
}

std::unique_ptr<SameSiteCookieIssueDetails> SameSiteCookieIssueDetails::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SameSiteCookieIssueDetails> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MixedContentIssueDetails> MixedContentIssueDetails::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MixedContentIssueDetails");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MixedContentIssueDetails> result(new MixedContentIssueDetails());
  errors->Push();
  errors->SetName("MixedContentIssueDetails");
  const base::Value* resource_type_value = value.FindKey("resourceType");
  if (resource_type_value) {
    errors->SetName("resourceType");
    result->resource_type_ = internal::FromValue<::headless::audits::MixedContentResourceType>::Parse(*resource_type_value, errors);
  }
  const base::Value* resolution_status_value = value.FindKey("resolutionStatus");
  if (resolution_status_value) {
    errors->SetName("resolutionStatus");
    result->resolution_status_ = internal::FromValue<::headless::audits::MixedContentResolutionStatus>::Parse(*resolution_status_value, errors);
  } else {
    errors->AddError("required property missing: resolutionStatus");
  }
  const base::Value* insecureurl_value = value.FindKey("insecureURL");
  if (insecureurl_value) {
    errors->SetName("insecureURL");
    result->insecureurl_ = internal::FromValue<std::string>::Parse(*insecureurl_value, errors);
  } else {
    errors->AddError("required property missing: insecureURL");
  }
  const base::Value* main_resourceurl_value = value.FindKey("mainResourceURL");
  if (main_resourceurl_value) {
    errors->SetName("mainResourceURL");
    result->main_resourceurl_ = internal::FromValue<std::string>::Parse(*main_resourceurl_value, errors);
  } else {
    errors->AddError("required property missing: mainResourceURL");
  }
  const base::Value* request_value = value.FindKey("request");
  if (request_value) {
    errors->SetName("request");
    result->request_ = internal::FromValue<::headless::audits::AffectedRequest>::Parse(*request_value, errors);
  }
  const base::Value* frame_value = value.FindKey("frame");
  if (frame_value) {
    errors->SetName("frame");
    result->frame_ = internal::FromValue<::headless::audits::AffectedFrame>::Parse(*frame_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MixedContentIssueDetails::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (resource_type_)
    result->Set("resourceType", internal::ToValue(resource_type_.value()));
  result->Set("resolutionStatus", internal::ToValue(resolution_status_));
  result->Set("insecureURL", internal::ToValue(insecureurl_));
  result->Set("mainResourceURL", internal::ToValue(main_resourceurl_));
  if (request_)
    result->Set("request", internal::ToValue(*request_.value()));
  if (frame_)
    result->Set("frame", internal::ToValue(*frame_.value()));
  return std::move(result);
}

std::unique_ptr<MixedContentIssueDetails> MixedContentIssueDetails::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MixedContentIssueDetails> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BlockedByResponseIssueDetails> BlockedByResponseIssueDetails::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BlockedByResponseIssueDetails");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BlockedByResponseIssueDetails> result(new BlockedByResponseIssueDetails());
  errors->Push();
  errors->SetName("BlockedByResponseIssueDetails");
  const base::Value* request_value = value.FindKey("request");
  if (request_value) {
    errors->SetName("request");
    result->request_ = internal::FromValue<::headless::audits::AffectedRequest>::Parse(*request_value, errors);
  } else {
    errors->AddError("required property missing: request");
  }
  const base::Value* frame_value = value.FindKey("frame");
  if (frame_value) {
    errors->SetName("frame");
    result->frame_ = internal::FromValue<::headless::audits::AffectedFrame>::Parse(*frame_value, errors);
  }
  const base::Value* reason_value = value.FindKey("reason");
  if (reason_value) {
    errors->SetName("reason");
    result->reason_ = internal::FromValue<::headless::audits::BlockedByResponseReason>::Parse(*reason_value, errors);
  } else {
    errors->AddError("required property missing: reason");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BlockedByResponseIssueDetails::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("request", internal::ToValue(*request_));
  if (frame_)
    result->Set("frame", internal::ToValue(*frame_.value()));
  result->Set("reason", internal::ToValue(reason_));
  return std::move(result);
}

std::unique_ptr<BlockedByResponseIssueDetails> BlockedByResponseIssueDetails::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BlockedByResponseIssueDetails> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InspectorIssueDetails> InspectorIssueDetails::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InspectorIssueDetails");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InspectorIssueDetails> result(new InspectorIssueDetails());
  errors->Push();
  errors->SetName("InspectorIssueDetails");
  const base::Value* same_site_cookie_issue_details_value = value.FindKey("sameSiteCookieIssueDetails");
  if (same_site_cookie_issue_details_value) {
    errors->SetName("sameSiteCookieIssueDetails");
    result->same_site_cookie_issue_details_ = internal::FromValue<::headless::audits::SameSiteCookieIssueDetails>::Parse(*same_site_cookie_issue_details_value, errors);
  }
  const base::Value* mixed_content_issue_details_value = value.FindKey("mixedContentIssueDetails");
  if (mixed_content_issue_details_value) {
    errors->SetName("mixedContentIssueDetails");
    result->mixed_content_issue_details_ = internal::FromValue<::headless::audits::MixedContentIssueDetails>::Parse(*mixed_content_issue_details_value, errors);
  }
  const base::Value* blocked_by_response_issue_details_value = value.FindKey("blockedByResponseIssueDetails");
  if (blocked_by_response_issue_details_value) {
    errors->SetName("blockedByResponseIssueDetails");
    result->blocked_by_response_issue_details_ = internal::FromValue<::headless::audits::BlockedByResponseIssueDetails>::Parse(*blocked_by_response_issue_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InspectorIssueDetails::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (same_site_cookie_issue_details_)
    result->Set("sameSiteCookieIssueDetails", internal::ToValue(*same_site_cookie_issue_details_.value()));
  if (mixed_content_issue_details_)
    result->Set("mixedContentIssueDetails", internal::ToValue(*mixed_content_issue_details_.value()));
  if (blocked_by_response_issue_details_)
    result->Set("blockedByResponseIssueDetails", internal::ToValue(*blocked_by_response_issue_details_.value()));
  return std::move(result);
}

std::unique_ptr<InspectorIssueDetails> InspectorIssueDetails::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InspectorIssueDetails> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InspectorIssue> InspectorIssue::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InspectorIssue");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InspectorIssue> result(new InspectorIssue());
  errors->Push();
  errors->SetName("InspectorIssue");
  const base::Value* code_value = value.FindKey("code");
  if (code_value) {
    errors->SetName("code");
    result->code_ = internal::FromValue<::headless::audits::InspectorIssueCode>::Parse(*code_value, errors);
  } else {
    errors->AddError("required property missing: code");
  }
  const base::Value* details_value = value.FindKey("details");
  if (details_value) {
    errors->SetName("details");
    result->details_ = internal::FromValue<::headless::audits::InspectorIssueDetails>::Parse(*details_value, errors);
  } else {
    errors->AddError("required property missing: details");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InspectorIssue::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("code", internal::ToValue(code_));
  result->Set("details", internal::ToValue(*details_));
  return std::move(result);
}

std::unique_ptr<InspectorIssue> InspectorIssue::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InspectorIssue> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetEncodedResponseParams> GetEncodedResponseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetEncodedResponseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetEncodedResponseParams> result(new GetEncodedResponseParams());
  errors->Push();
  errors->SetName("GetEncodedResponseParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* encoding_value = value.FindKey("encoding");
  if (encoding_value) {
    errors->SetName("encoding");
    result->encoding_ = internal::FromValue<::headless::audits::GetEncodedResponseEncoding>::Parse(*encoding_value, errors);
  } else {
    errors->AddError("required property missing: encoding");
  }
  const base::Value* quality_value = value.FindKey("quality");
  if (quality_value) {
    errors->SetName("quality");
    result->quality_ = internal::FromValue<double>::Parse(*quality_value, errors);
  }
  const base::Value* size_only_value = value.FindKey("sizeOnly");
  if (size_only_value) {
    errors->SetName("sizeOnly");
    result->size_only_ = internal::FromValue<bool>::Parse(*size_only_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetEncodedResponseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("encoding", internal::ToValue(encoding_));
  if (quality_)
    result->Set("quality", internal::ToValue(quality_.value()));
  if (size_only_)
    result->Set("sizeOnly", internal::ToValue(size_only_.value()));
  return std::move(result);
}

std::unique_ptr<GetEncodedResponseParams> GetEncodedResponseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetEncodedResponseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetEncodedResponseResult> GetEncodedResponseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetEncodedResponseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetEncodedResponseResult> result(new GetEncodedResponseResult());
  errors->Push();
  errors->SetName("GetEncodedResponseResult");
  const base::Value* body_value = value.FindKey("body");
  if (body_value) {
    errors->SetName("body");
    result->body_ = internal::FromValue<protocol::Binary>::Parse(*body_value, errors);
  }
  const base::Value* original_size_value = value.FindKey("originalSize");
  if (original_size_value) {
    errors->SetName("originalSize");
    result->original_size_ = internal::FromValue<int>::Parse(*original_size_value, errors);
  } else {
    errors->AddError("required property missing: originalSize");
  }
  const base::Value* encoded_size_value = value.FindKey("encodedSize");
  if (encoded_size_value) {
    errors->SetName("encodedSize");
    result->encoded_size_ = internal::FromValue<int>::Parse(*encoded_size_value, errors);
  } else {
    errors->AddError("required property missing: encodedSize");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetEncodedResponseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (body_)
    result->Set("body", internal::ToValue(body_.value()));
  result->Set("originalSize", internal::ToValue(original_size_));
  result->Set("encodedSize", internal::ToValue(encoded_size_));
  return std::move(result);
}

std::unique_ptr<GetEncodedResponseResult> GetEncodedResponseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetEncodedResponseResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<IssueAddedParams> IssueAddedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("IssueAddedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<IssueAddedParams> result(new IssueAddedParams());
  errors->Push();
  errors->SetName("IssueAddedParams");
  const base::Value* issue_value = value.FindKey("issue");
  if (issue_value) {
    errors->SetName("issue");
    result->issue_ = internal::FromValue<::headless::audits::InspectorIssue>::Parse(*issue_value, errors);
  } else {
    errors->AddError("required property missing: issue");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> IssueAddedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("issue", internal::ToValue(*issue_));
  return std::move(result);
}

std::unique_ptr<IssueAddedParams> IssueAddedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<IssueAddedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace audits
}  // namespace headless
