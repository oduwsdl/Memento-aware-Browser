// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_fetch.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_fetch.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace fetch {

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
  const base::Value* request_stage_value = value.FindKey("requestStage");
  if (request_stage_value) {
    errors->SetName("requestStage");
    result->request_stage_ = internal::FromValue<::headless::fetch::RequestStage>::Parse(*request_stage_value, errors);
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
  if (request_stage_)
    result->Set("requestStage", internal::ToValue(request_stage_.value()));
  return std::move(result);
}

std::unique_ptr<RequestPattern> RequestPattern::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestPattern> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<HeaderEntry> HeaderEntry::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("HeaderEntry");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<HeaderEntry> result(new HeaderEntry());
  errors->Push();
  errors->SetName("HeaderEntry");
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
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> HeaderEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<HeaderEntry> HeaderEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<HeaderEntry> result = Parse(*Serialize(), &errors);
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
    result->source_ = internal::FromValue<::headless::fetch::AuthChallengeSource>::Parse(*source_value, errors);
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
    result->response_ = internal::FromValue<::headless::fetch::AuthChallengeResponseResponse>::Parse(*response_value, errors);
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
  const base::Value* patterns_value = value.FindKey("patterns");
  if (patterns_value) {
    errors->SetName("patterns");
    result->patterns_ = internal::FromValue<std::vector<std::unique_ptr<::headless::fetch::RequestPattern>>>::Parse(*patterns_value, errors);
  }
  const base::Value* handle_auth_requests_value = value.FindKey("handleAuthRequests");
  if (handle_auth_requests_value) {
    errors->SetName("handleAuthRequests");
    result->handle_auth_requests_ = internal::FromValue<bool>::Parse(*handle_auth_requests_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (patterns_)
    result->Set("patterns", internal::ToValue(patterns_.value()));
  if (handle_auth_requests_)
    result->Set("handleAuthRequests", internal::ToValue(handle_auth_requests_.value()));
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


std::unique_ptr<FailRequestParams> FailRequestParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FailRequestParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FailRequestParams> result(new FailRequestParams());
  errors->Push();
  errors->SetName("FailRequestParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* error_reason_value = value.FindKey("errorReason");
  if (error_reason_value) {
    errors->SetName("errorReason");
    result->error_reason_ = internal::FromValue<::headless::network::ErrorReason>::Parse(*error_reason_value, errors);
  } else {
    errors->AddError("required property missing: errorReason");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FailRequestParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("errorReason", internal::ToValue(error_reason_));
  return std::move(result);
}

std::unique_ptr<FailRequestParams> FailRequestParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FailRequestParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FailRequestResult> FailRequestResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FailRequestResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FailRequestResult> result(new FailRequestResult());
  errors->Push();
  errors->SetName("FailRequestResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FailRequestResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<FailRequestResult> FailRequestResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FailRequestResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FulfillRequestParams> FulfillRequestParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FulfillRequestParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FulfillRequestParams> result(new FulfillRequestParams());
  errors->Push();
  errors->SetName("FulfillRequestParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
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
    result->response_headers_ = internal::FromValue<std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>>::Parse(*response_headers_value, errors);
  }
  const base::Value* binary_response_headers_value = value.FindKey("binaryResponseHeaders");
  if (binary_response_headers_value) {
    errors->SetName("binaryResponseHeaders");
    result->binary_response_headers_ = internal::FromValue<protocol::Binary>::Parse(*binary_response_headers_value, errors);
  }
  const base::Value* body_value = value.FindKey("body");
  if (body_value) {
    errors->SetName("body");
    result->body_ = internal::FromValue<protocol::Binary>::Parse(*body_value, errors);
  }
  const base::Value* response_phrase_value = value.FindKey("responsePhrase");
  if (response_phrase_value) {
    errors->SetName("responsePhrase");
    result->response_phrase_ = internal::FromValue<std::string>::Parse(*response_phrase_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FulfillRequestParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("responseCode", internal::ToValue(response_code_));
  if (response_headers_)
    result->Set("responseHeaders", internal::ToValue(response_headers_.value()));
  if (binary_response_headers_)
    result->Set("binaryResponseHeaders", internal::ToValue(binary_response_headers_.value()));
  if (body_)
    result->Set("body", internal::ToValue(body_.value()));
  if (response_phrase_)
    result->Set("responsePhrase", internal::ToValue(response_phrase_.value()));
  return std::move(result);
}

std::unique_ptr<FulfillRequestParams> FulfillRequestParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FulfillRequestParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FulfillRequestResult> FulfillRequestResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FulfillRequestResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FulfillRequestResult> result(new FulfillRequestResult());
  errors->Push();
  errors->SetName("FulfillRequestResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FulfillRequestResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<FulfillRequestResult> FulfillRequestResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FulfillRequestResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContinueRequestParams> ContinueRequestParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContinueRequestParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContinueRequestParams> result(new ContinueRequestParams());
  errors->Push();
  errors->SetName("ContinueRequestParams");
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
    result->headers_ = internal::FromValue<std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>>::Parse(*headers_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContinueRequestParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (method_)
    result->Set("method", internal::ToValue(method_.value()));
  if (post_data_)
    result->Set("postData", internal::ToValue(post_data_.value()));
  if (headers_)
    result->Set("headers", internal::ToValue(headers_.value()));
  return std::move(result);
}

std::unique_ptr<ContinueRequestParams> ContinueRequestParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContinueRequestParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContinueRequestResult> ContinueRequestResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContinueRequestResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContinueRequestResult> result(new ContinueRequestResult());
  errors->Push();
  errors->SetName("ContinueRequestResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContinueRequestResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ContinueRequestResult> ContinueRequestResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContinueRequestResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContinueWithAuthParams> ContinueWithAuthParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContinueWithAuthParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContinueWithAuthParams> result(new ContinueWithAuthParams());
  errors->Push();
  errors->SetName("ContinueWithAuthParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
  }
  const base::Value* auth_challenge_response_value = value.FindKey("authChallengeResponse");
  if (auth_challenge_response_value) {
    errors->SetName("authChallengeResponse");
    result->auth_challenge_response_ = internal::FromValue<::headless::fetch::AuthChallengeResponse>::Parse(*auth_challenge_response_value, errors);
  } else {
    errors->AddError("required property missing: authChallengeResponse");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContinueWithAuthParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("authChallengeResponse", internal::ToValue(*auth_challenge_response_));
  return std::move(result);
}

std::unique_ptr<ContinueWithAuthParams> ContinueWithAuthParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContinueWithAuthParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContinueWithAuthResult> ContinueWithAuthResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContinueWithAuthResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContinueWithAuthResult> result(new ContinueWithAuthResult());
  errors->Push();
  errors->SetName("ContinueWithAuthResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContinueWithAuthResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ContinueWithAuthResult> ContinueWithAuthResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContinueWithAuthResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<TakeResponseBodyAsStreamParams> TakeResponseBodyAsStreamParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeResponseBodyAsStreamParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeResponseBodyAsStreamParams> result(new TakeResponseBodyAsStreamParams());
  errors->Push();
  errors->SetName("TakeResponseBodyAsStreamParams");
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

std::unique_ptr<base::Value> TakeResponseBodyAsStreamParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  return std::move(result);
}

std::unique_ptr<TakeResponseBodyAsStreamParams> TakeResponseBodyAsStreamParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeResponseBodyAsStreamParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeResponseBodyAsStreamResult> TakeResponseBodyAsStreamResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeResponseBodyAsStreamResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeResponseBodyAsStreamResult> result(new TakeResponseBodyAsStreamResult());
  errors->Push();
  errors->SetName("TakeResponseBodyAsStreamResult");
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

std::unique_ptr<base::Value> TakeResponseBodyAsStreamResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("stream", internal::ToValue(stream_));
  return std::move(result);
}

std::unique_ptr<TakeResponseBodyAsStreamResult> TakeResponseBodyAsStreamResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeResponseBodyAsStreamResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestPausedParams> RequestPausedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestPausedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestPausedParams> result(new RequestPausedParams());
  errors->Push();
  errors->SetName("RequestPausedParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
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
    result->response_headers_ = internal::FromValue<std::vector<std::unique_ptr<::headless::fetch::HeaderEntry>>>::Parse(*response_headers_value, errors);
  }
  const base::Value* network_id_value = value.FindKey("networkId");
  if (network_id_value) {
    errors->SetName("networkId");
    result->network_id_ = internal::FromValue<std::string>::Parse(*network_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestPausedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("request", internal::ToValue(*request_));
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("resourceType", internal::ToValue(resource_type_));
  if (response_error_reason_)
    result->Set("responseErrorReason", internal::ToValue(response_error_reason_.value()));
  if (response_status_code_)
    result->Set("responseStatusCode", internal::ToValue(response_status_code_.value()));
  if (response_headers_)
    result->Set("responseHeaders", internal::ToValue(response_headers_.value()));
  if (network_id_)
    result->Set("networkId", internal::ToValue(network_id_.value()));
  return std::move(result);
}

std::unique_ptr<RequestPausedParams> RequestPausedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestPausedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AuthRequiredParams> AuthRequiredParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AuthRequiredParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AuthRequiredParams> result(new AuthRequiredParams());
  errors->Push();
  errors->SetName("AuthRequiredParams");
  const base::Value* request_id_value = value.FindKey("requestId");
  if (request_id_value) {
    errors->SetName("requestId");
    result->request_id_ = internal::FromValue<std::string>::Parse(*request_id_value, errors);
  } else {
    errors->AddError("required property missing: requestId");
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
  const base::Value* auth_challenge_value = value.FindKey("authChallenge");
  if (auth_challenge_value) {
    errors->SetName("authChallenge");
    result->auth_challenge_ = internal::FromValue<::headless::fetch::AuthChallenge>::Parse(*auth_challenge_value, errors);
  } else {
    errors->AddError("required property missing: authChallenge");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AuthRequiredParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestId", internal::ToValue(request_id_));
  result->Set("request", internal::ToValue(*request_));
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("resourceType", internal::ToValue(resource_type_));
  result->Set("authChallenge", internal::ToValue(*auth_challenge_));
  return std::move(result);
}

std::unique_ptr<AuthRequiredParams> AuthRequiredParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AuthRequiredParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace fetch
}  // namespace headless
