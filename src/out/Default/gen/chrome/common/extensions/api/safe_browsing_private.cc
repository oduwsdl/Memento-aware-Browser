// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/safe_browsing_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/safe_browsing_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace safe_browsing_private {
//
// Types
//

const char* ToString(URLType enum_param) {
  switch (enum_param) {
    case URL_TYPE_EVENT_URL:
      return "EVENT_URL";
    case URL_TYPE_LANDING_PAGE:
      return "LANDING_PAGE";
    case URL_TYPE_LANDING_REFERRER:
      return "LANDING_REFERRER";
    case URL_TYPE_CLIENT_REDIRECT:
      return "CLIENT_REDIRECT";
    case URL_TYPE_RECENT_NAVIGATION:
      return "RECENT_NAVIGATION";
    case URL_TYPE_REFERRER:
      return "REFERRER";
    case URL_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

URLType ParseURLType(const std::string& enum_string) {
  if (enum_string == "EVENT_URL")
    return URL_TYPE_EVENT_URL;
  if (enum_string == "LANDING_PAGE")
    return URL_TYPE_LANDING_PAGE;
  if (enum_string == "LANDING_REFERRER")
    return URL_TYPE_LANDING_REFERRER;
  if (enum_string == "CLIENT_REDIRECT")
    return URL_TYPE_CLIENT_REDIRECT;
  if (enum_string == "RECENT_NAVIGATION")
    return URL_TYPE_RECENT_NAVIGATION;
  if (enum_string == "REFERRER")
    return URL_TYPE_REFERRER;
  return URL_TYPE_NONE;
}


const char* ToString(NavigationInitiation enum_param) {
  switch (enum_param) {
    case NAVIGATION_INITIATION_BROWSER_INITIATED:
      return "BROWSER_INITIATED";
    case NAVIGATION_INITIATION_RENDERER_INITIATED_WITHOUT_USER_GESTURE:
      return "RENDERER_INITIATED_WITHOUT_USER_GESTURE";
    case NAVIGATION_INITIATION_RENDERER_INITIATED_WITH_USER_GESTURE:
      return "RENDERER_INITIATED_WITH_USER_GESTURE";
    case NAVIGATION_INITIATION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

NavigationInitiation ParseNavigationInitiation(const std::string& enum_string) {
  if (enum_string == "BROWSER_INITIATED")
    return NAVIGATION_INITIATION_BROWSER_INITIATED;
  if (enum_string == "RENDERER_INITIATED_WITHOUT_USER_GESTURE")
    return NAVIGATION_INITIATION_RENDERER_INITIATED_WITHOUT_USER_GESTURE;
  if (enum_string == "RENDERER_INITIATED_WITH_USER_GESTURE")
    return NAVIGATION_INITIATION_RENDERER_INITIATED_WITH_USER_GESTURE;
  return NAVIGATION_INITIATION_NONE;
}


PolicySpecifiedPasswordReuse::PolicySpecifiedPasswordReuse()
: is_phishing_url(false) {}

PolicySpecifiedPasswordReuse::~PolicySpecifiedPasswordReuse() {}
PolicySpecifiedPasswordReuse::PolicySpecifiedPasswordReuse(PolicySpecifiedPasswordReuse&& rhs)
: url(std::move(rhs.url)),
user_name(std::move(rhs.user_name)),
is_phishing_url(rhs.is_phishing_url){
}

PolicySpecifiedPasswordReuse& PolicySpecifiedPasswordReuse::operator=(PolicySpecifiedPasswordReuse&& rhs)
{
url = std::move(rhs.url);
user_name = std::move(rhs.user_name);
is_phishing_url = rhs.is_phishing_url;
return *this;
}

// static
bool PolicySpecifiedPasswordReuse::Populate(
    const base::Value& value, PolicySpecifiedPasswordReuse* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* user_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("userName", &user_name_value)) {
    return false;
  }
  {
    if (!user_name_value->GetAsString(&out->user_name)) {
      return false;
    }
  }

  const base::Value* is_phishing_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("isPhishingUrl", &is_phishing_url_value)) {
    return false;
  }
  {
    if (!is_phishing_url_value->GetAsBoolean(&out->is_phishing_url)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PolicySpecifiedPasswordReuse> PolicySpecifiedPasswordReuse::FromValue(const base::Value& value) {
  std::unique_ptr<PolicySpecifiedPasswordReuse> out(new PolicySpecifiedPasswordReuse());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PolicySpecifiedPasswordReuse::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("userName", std::make_unique<base::Value>(this->user_name));

  to_value_result->SetWithoutPathExpansion("isPhishingUrl", std::make_unique<base::Value>(this->is_phishing_url));


  return to_value_result;
}


DangerousDownloadInfo::DangerousDownloadInfo()
 {}

DangerousDownloadInfo::~DangerousDownloadInfo() {}
DangerousDownloadInfo::DangerousDownloadInfo(DangerousDownloadInfo&& rhs)
: url(std::move(rhs.url)),
file_name(std::move(rhs.file_name)),
download_digest_sha256(std::move(rhs.download_digest_sha256)),
user_name(std::move(rhs.user_name)){
}

DangerousDownloadInfo& DangerousDownloadInfo::operator=(DangerousDownloadInfo&& rhs)
{
url = std::move(rhs.url);
file_name = std::move(rhs.file_name);
download_digest_sha256 = std::move(rhs.download_digest_sha256);
user_name = std::move(rhs.user_name);
return *this;
}

// static
bool DangerousDownloadInfo::Populate(
    const base::Value& value, DangerousDownloadInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* file_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("fileName", &file_name_value)) {
    return false;
  }
  {
    if (!file_name_value->GetAsString(&out->file_name)) {
      return false;
    }
  }

  const base::Value* download_digest_sha256_value = NULL;
  if (!dict->GetWithoutPathExpansion("downloadDigestSha256", &download_digest_sha256_value)) {
    return false;
  }
  {
    if (!download_digest_sha256_value->GetAsString(&out->download_digest_sha256)) {
      return false;
    }
  }

  const base::Value* user_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("userName", &user_name_value)) {
    return false;
  }
  {
    if (!user_name_value->GetAsString(&out->user_name)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<DangerousDownloadInfo> DangerousDownloadInfo::FromValue(const base::Value& value) {
  std::unique_ptr<DangerousDownloadInfo> out(new DangerousDownloadInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DangerousDownloadInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("fileName", std::make_unique<base::Value>(this->file_name));

  to_value_result->SetWithoutPathExpansion("downloadDigestSha256", std::make_unique<base::Value>(this->download_digest_sha256));

  to_value_result->SetWithoutPathExpansion("userName", std::make_unique<base::Value>(this->user_name));


  return to_value_result;
}


InterstitialInfo::InterstitialInfo()
 {}

InterstitialInfo::~InterstitialInfo() {}
InterstitialInfo::InterstitialInfo(InterstitialInfo&& rhs)
: url(std::move(rhs.url)),
reason(std::move(rhs.reason)),
net_error_code(std::move(rhs.net_error_code)),
user_name(std::move(rhs.user_name)){
}

InterstitialInfo& InterstitialInfo::operator=(InterstitialInfo&& rhs)
{
url = std::move(rhs.url);
reason = std::move(rhs.reason);
net_error_code = std::move(rhs.net_error_code);
user_name = std::move(rhs.user_name);
return *this;
}

// static
bool InterstitialInfo::Populate(
    const base::Value& value, InterstitialInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* reason_value = NULL;
  if (!dict->GetWithoutPathExpansion("reason", &reason_value)) {
    return false;
  }
  {
    if (!reason_value->GetAsString(&out->reason)) {
      return false;
    }
  }

  const base::Value* net_error_code_value = NULL;
  if (dict->GetWithoutPathExpansion("netErrorCode", &net_error_code_value)) {
    {
      std::string temp;
      if (!net_error_code_value->GetAsString(&temp)) {
        out->net_error_code.reset();
        return false;
      }
      else
        out->net_error_code.reset(new std::string(temp));
    }
  }

  const base::Value* user_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("userName", &user_name_value)) {
    return false;
  }
  {
    if (!user_name_value->GetAsString(&out->user_name)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<InterstitialInfo> InterstitialInfo::FromValue(const base::Value& value) {
  std::unique_ptr<InterstitialInfo> out(new InterstitialInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InterstitialInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("reason", std::make_unique<base::Value>(this->reason));

  if (this->net_error_code.get()) {
    to_value_result->SetWithoutPathExpansion("netErrorCode", std::make_unique<base::Value>(*this->net_error_code));

  }
  to_value_result->SetWithoutPathExpansion("userName", std::make_unique<base::Value>(this->user_name));


  return to_value_result;
}


ServerRedirect::ServerRedirect()
 {}

ServerRedirect::~ServerRedirect() {}
ServerRedirect::ServerRedirect(ServerRedirect&& rhs)
: url(std::move(rhs.url)){
}

ServerRedirect& ServerRedirect::operator=(ServerRedirect&& rhs)
{
url = std::move(rhs.url);
return *this;
}

// static
bool ServerRedirect::Populate(
    const base::Value& value, ServerRedirect* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ServerRedirect> ServerRedirect::FromValue(const base::Value& value) {
  std::unique_ptr<ServerRedirect> out(new ServerRedirect());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ServerRedirect::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }

  return to_value_result;
}


ReferrerChainEntry::ReferrerChainEntry()
: url_type(URL_TYPE_NONE),
navigation_initiation(NAVIGATION_INITIATION_NONE) {}

ReferrerChainEntry::~ReferrerChainEntry() {}
ReferrerChainEntry::ReferrerChainEntry(ReferrerChainEntry&& rhs)
: url(std::move(rhs.url)),
main_frame_url(std::move(rhs.main_frame_url)),
url_type(rhs.url_type),
ip_addresses(std::move(rhs.ip_addresses)),
referrer_url(std::move(rhs.referrer_url)),
referrer_main_frame_url(std::move(rhs.referrer_main_frame_url)),
is_retargeting(std::move(rhs.is_retargeting)),
navigation_time_ms(std::move(rhs.navigation_time_ms)),
server_redirect_chain(std::move(rhs.server_redirect_chain)),
navigation_initiation(rhs.navigation_initiation),
maybe_launched_by_external_app(std::move(rhs.maybe_launched_by_external_app)){
}

ReferrerChainEntry& ReferrerChainEntry::operator=(ReferrerChainEntry&& rhs)
{
url = std::move(rhs.url);
main_frame_url = std::move(rhs.main_frame_url);
url_type = rhs.url_type;
ip_addresses = std::move(rhs.ip_addresses);
referrer_url = std::move(rhs.referrer_url);
referrer_main_frame_url = std::move(rhs.referrer_main_frame_url);
is_retargeting = std::move(rhs.is_retargeting);
navigation_time_ms = std::move(rhs.navigation_time_ms);
server_redirect_chain = std::move(rhs.server_redirect_chain);
navigation_initiation = rhs.navigation_initiation;
maybe_launched_by_external_app = std::move(rhs.maybe_launched_by_external_app);
return *this;
}

// static
bool ReferrerChainEntry::Populate(
    const base::Value& value, ReferrerChainEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->navigation_initiation = NAVIGATION_INITIATION_NONE;
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* main_frame_url_value = NULL;
  if (dict->GetWithoutPathExpansion("mainFrameUrl", &main_frame_url_value)) {
    {
      std::string temp;
      if (!main_frame_url_value->GetAsString(&temp)) {
        out->main_frame_url.reset();
        return false;
      }
      else
        out->main_frame_url.reset(new std::string(temp));
    }
  }

  const base::Value* url_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("urlType", &url_type_value)) {
    return false;
  }
  {
    std::string url_type_as_string;
    if (!url_type_value->GetAsString(&url_type_as_string)) {
      return false;
    }
    out->url_type = ParseURLType(url_type_as_string);
    if (out->url_type == URL_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* ip_addresses_value = NULL;
  if (dict->GetWithoutPathExpansion("ipAddresses", &ip_addresses_value)) {
    {
      const base::ListValue* list = NULL;
      if (!ip_addresses_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->ip_addresses)) {
          return false;
        }
      }
    }
  }

  const base::Value* referrer_url_value = NULL;
  if (dict->GetWithoutPathExpansion("referrerUrl", &referrer_url_value)) {
    {
      std::string temp;
      if (!referrer_url_value->GetAsString(&temp)) {
        out->referrer_url.reset();
        return false;
      }
      else
        out->referrer_url.reset(new std::string(temp));
    }
  }

  const base::Value* referrer_main_frame_url_value = NULL;
  if (dict->GetWithoutPathExpansion("referrerMainFrameUrl", &referrer_main_frame_url_value)) {
    {
      std::string temp;
      if (!referrer_main_frame_url_value->GetAsString(&temp)) {
        out->referrer_main_frame_url.reset();
        return false;
      }
      else
        out->referrer_main_frame_url.reset(new std::string(temp));
    }
  }

  const base::Value* is_retargeting_value = NULL;
  if (dict->GetWithoutPathExpansion("isRetargeting", &is_retargeting_value)) {
    {
      bool temp;
      if (!is_retargeting_value->GetAsBoolean(&temp)) {
        out->is_retargeting.reset();
        return false;
      }
      else
        out->is_retargeting.reset(new bool(temp));
    }
  }

  const base::Value* navigation_time_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("navigationTimeMs", &navigation_time_ms_value)) {
    {
      double temp;
      if (!navigation_time_ms_value->GetAsDouble(&temp)) {
        out->navigation_time_ms.reset();
        return false;
      }
      else
        out->navigation_time_ms.reset(new double(temp));
    }
  }

  const base::Value* server_redirect_chain_value = NULL;
  if (dict->GetWithoutPathExpansion("serverRedirectChain", &server_redirect_chain_value)) {
    {
      const base::ListValue* list = NULL;
      if (!server_redirect_chain_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->server_redirect_chain)) {
          return false;
        }
      }
    }
  }

  const base::Value* navigation_initiation_value = NULL;
  if (dict->GetWithoutPathExpansion("navigationInitiation", &navigation_initiation_value)) {
    {
      std::string navigation_initiation_as_string;
      if (!navigation_initiation_value->GetAsString(&navigation_initiation_as_string)) {
        return false;
      }
      out->navigation_initiation = ParseNavigationInitiation(navigation_initiation_as_string);
      if (out->navigation_initiation == NAVIGATION_INITIATION_NONE) {
        return false;
      }
    }
    } else {
    out->navigation_initiation = NAVIGATION_INITIATION_NONE;
  }

  const base::Value* maybe_launched_by_external_app_value = NULL;
  if (dict->GetWithoutPathExpansion("maybeLaunchedByExternalApp", &maybe_launched_by_external_app_value)) {
    {
      bool temp;
      if (!maybe_launched_by_external_app_value->GetAsBoolean(&temp)) {
        out->maybe_launched_by_external_app.reset();
        return false;
      }
      else
        out->maybe_launched_by_external_app.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ReferrerChainEntry> ReferrerChainEntry::FromValue(const base::Value& value) {
  std::unique_ptr<ReferrerChainEntry> out(new ReferrerChainEntry());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReferrerChainEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  if (this->main_frame_url.get()) {
    to_value_result->SetWithoutPathExpansion("mainFrameUrl", std::make_unique<base::Value>(*this->main_frame_url));

  }
  to_value_result->SetWithoutPathExpansion("urlType", std::make_unique<base::Value>(safe_browsing_private::ToString(this->url_type)));

  if (this->ip_addresses.get()) {
    to_value_result->SetWithoutPathExpansion("ipAddresses", json_schema_compiler::util::CreateValueFromOptionalArray(this->ip_addresses));

  }
  if (this->referrer_url.get()) {
    to_value_result->SetWithoutPathExpansion("referrerUrl", std::make_unique<base::Value>(*this->referrer_url));

  }
  if (this->referrer_main_frame_url.get()) {
    to_value_result->SetWithoutPathExpansion("referrerMainFrameUrl", std::make_unique<base::Value>(*this->referrer_main_frame_url));

  }
  if (this->is_retargeting.get()) {
    to_value_result->SetWithoutPathExpansion("isRetargeting", std::make_unique<base::Value>(*this->is_retargeting));

  }
  if (this->navigation_time_ms.get()) {
    to_value_result->SetWithoutPathExpansion("navigationTimeMs", std::make_unique<base::Value>(*this->navigation_time_ms));

  }
  if (this->server_redirect_chain.get()) {
    to_value_result->SetWithoutPathExpansion("serverRedirectChain", json_schema_compiler::util::CreateValueFromOptionalArray(this->server_redirect_chain));

  }
  if (this->navigation_initiation != NAVIGATION_INITIATION_NONE) {
    to_value_result->SetWithoutPathExpansion("navigationInitiation", std::make_unique<base::Value>(safe_browsing_private::ToString(this->navigation_initiation)));

  }
  if (this->maybe_launched_by_external_app.get()) {
    to_value_result->SetWithoutPathExpansion("maybeLaunchedByExternalApp", std::make_unique<base::Value>(*this->maybe_launched_by_external_app));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetReferrerChain {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      if (!tab_id_value->GetAsInteger(&params->tab_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<ReferrerChainEntry>& entries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(entries));

  return create_results;
}
}  // namespace GetReferrerChain

//
// Events
//

namespace OnPolicySpecifiedPasswordReuseDetected {

const char kEventName[] = "safeBrowsingPrivate.onPolicySpecifiedPasswordReuseDetected";

std::unique_ptr<base::ListValue> Create(const PolicySpecifiedPasswordReuse& reuse_details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((reuse_details).ToValue());

  return create_results;
}

}  // namespace OnPolicySpecifiedPasswordReuseDetected

namespace OnPolicySpecifiedPasswordChanged {

const char kEventName[] = "safeBrowsingPrivate.onPolicySpecifiedPasswordChanged";

std::unique_ptr<base::ListValue> Create(const std::string& user_name) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(user_name));

  return create_results;
}

}  // namespace OnPolicySpecifiedPasswordChanged

namespace OnDangerousDownloadOpened {

const char kEventName[] = "safeBrowsingPrivate.onDangerousDownloadOpened";

std::unique_ptr<base::ListValue> Create(const DangerousDownloadInfo& dict) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((dict).ToValue());

  return create_results;
}

}  // namespace OnDangerousDownloadOpened

namespace OnSecurityInterstitialShown {

const char kEventName[] = "safeBrowsingPrivate.onSecurityInterstitialShown";

std::unique_ptr<base::ListValue> Create(const InterstitialInfo& dict) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((dict).ToValue());

  return create_results;
}

}  // namespace OnSecurityInterstitialShown

namespace OnSecurityInterstitialProceeded {

const char kEventName[] = "safeBrowsingPrivate.onSecurityInterstitialProceeded";

std::unique_ptr<base::ListValue> Create(const InterstitialInfo& dict) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((dict).ToValue());

  return create_results;
}

}  // namespace OnSecurityInterstitialProceeded

}  // namespace safe_browsing_private
}  // namespace api
}  // namespace extensions

