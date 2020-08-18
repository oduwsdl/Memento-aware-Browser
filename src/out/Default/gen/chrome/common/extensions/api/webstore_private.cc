// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/webstore_private.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/webstore_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace webstore_private {
//
// Types
//

const char* ToString(Result enum_param) {
  switch (enum_param) {
    case RESULT_EMPTY_STRING:
      return "";
    case RESULT_SUCCESS:
      return "success";
    case RESULT_USER_GESTURE_REQUIRED:
      return "user_gesture_required";
    case RESULT_UNKNOWN_ERROR:
      return "unknown_error";
    case RESULT_FEATURE_DISABLED:
      return "feature_disabled";
    case RESULT_UNSUPPORTED_EXTENSION_TYPE:
      return "unsupported_extension_type";
    case RESULT_MISSING_DEPENDENCIES:
      return "missing_dependencies";
    case RESULT_INSTALL_ERROR:
      return "install_error";
    case RESULT_USER_CANCELLED:
      return "user_cancelled";
    case RESULT_INVALID_ID:
      return "invalid_id";
    case RESULT_BLACKLISTED:
      return "blacklisted";
    case RESULT_BLOCKED_BY_POLICY:
      return "blocked_by_policy";
    case RESULT_INSTALL_IN_PROGRESS:
      return "install_in_progress";
    case RESULT_LAUNCH_IN_PROGRESS:
      return "launch_in_progress";
    case RESULT_MANIFEST_ERROR:
      return "manifest_error";
    case RESULT_ICON_ERROR:
      return "icon_error";
    case RESULT_INVALID_ICON_URL:
      return "invalid_icon_url";
    case RESULT_ALREADY_INSTALLED:
      return "already_installed";
    case RESULT_BLOCKED_FOR_CHILD_ACCOUNT:
      return "blocked_for_child_account";
    case RESULT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Result ParseResult(const std::string& enum_string) {
  if (enum_string == "")
    return RESULT_EMPTY_STRING;
  if (enum_string == "success")
    return RESULT_SUCCESS;
  if (enum_string == "user_gesture_required")
    return RESULT_USER_GESTURE_REQUIRED;
  if (enum_string == "unknown_error")
    return RESULT_UNKNOWN_ERROR;
  if (enum_string == "feature_disabled")
    return RESULT_FEATURE_DISABLED;
  if (enum_string == "unsupported_extension_type")
    return RESULT_UNSUPPORTED_EXTENSION_TYPE;
  if (enum_string == "missing_dependencies")
    return RESULT_MISSING_DEPENDENCIES;
  if (enum_string == "install_error")
    return RESULT_INSTALL_ERROR;
  if (enum_string == "user_cancelled")
    return RESULT_USER_CANCELLED;
  if (enum_string == "invalid_id")
    return RESULT_INVALID_ID;
  if (enum_string == "blacklisted")
    return RESULT_BLACKLISTED;
  if (enum_string == "blocked_by_policy")
    return RESULT_BLOCKED_BY_POLICY;
  if (enum_string == "install_in_progress")
    return RESULT_INSTALL_IN_PROGRESS;
  if (enum_string == "launch_in_progress")
    return RESULT_LAUNCH_IN_PROGRESS;
  if (enum_string == "manifest_error")
    return RESULT_MANIFEST_ERROR;
  if (enum_string == "icon_error")
    return RESULT_ICON_ERROR;
  if (enum_string == "invalid_icon_url")
    return RESULT_INVALID_ICON_URL;
  if (enum_string == "already_installed")
    return RESULT_ALREADY_INSTALLED;
  if (enum_string == "blocked_for_child_account")
    return RESULT_BLOCKED_FOR_CHILD_ACCOUNT;
  return RESULT_NONE;
}


const char* ToString(WebGlStatus enum_param) {
  switch (enum_param) {
    case WEB_GL_STATUS_WEBGL_ALLOWED:
      return "webgl_allowed";
    case WEB_GL_STATUS_WEBGL_BLOCKED:
      return "webgl_blocked";
    case WEB_GL_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

WebGlStatus ParseWebGlStatus(const std::string& enum_string) {
  if (enum_string == "webgl_allowed")
    return WEB_GL_STATUS_WEBGL_ALLOWED;
  if (enum_string == "webgl_blocked")
    return WEB_GL_STATUS_WEBGL_BLOCKED;
  return WEB_GL_STATUS_NONE;
}


const char* ToString(ExtensionInstallStatus enum_param) {
  switch (enum_param) {
    case EXTENSION_INSTALL_STATUS_CAN_REQUEST:
      return "can_request";
    case EXTENSION_INSTALL_STATUS_REQUEST_PENDING:
      return "request_pending";
    case EXTENSION_INSTALL_STATUS_BLOCKED_BY_POLICY:
      return "blocked_by_policy";
    case EXTENSION_INSTALL_STATUS_INSTALLABLE:
      return "installable";
    case EXTENSION_INSTALL_STATUS_ENABLED:
      return "enabled";
    case EXTENSION_INSTALL_STATUS_DISABLED:
      return "disabled";
    case EXTENSION_INSTALL_STATUS_TERMINATED:
      return "terminated";
    case EXTENSION_INSTALL_STATUS_BLACKLISTED:
      return "blacklisted";
    case EXTENSION_INSTALL_STATUS_CUSTODIAN_APPROVAL_REQUIRED:
      return "custodian_approval_required";
    case EXTENSION_INSTALL_STATUS_FORCE_INSTALLED:
      return "force_installed";
    case EXTENSION_INSTALL_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionInstallStatus ParseExtensionInstallStatus(const std::string& enum_string) {
  if (enum_string == "can_request")
    return EXTENSION_INSTALL_STATUS_CAN_REQUEST;
  if (enum_string == "request_pending")
    return EXTENSION_INSTALL_STATUS_REQUEST_PENDING;
  if (enum_string == "blocked_by_policy")
    return EXTENSION_INSTALL_STATUS_BLOCKED_BY_POLICY;
  if (enum_string == "installable")
    return EXTENSION_INSTALL_STATUS_INSTALLABLE;
  if (enum_string == "enabled")
    return EXTENSION_INSTALL_STATUS_ENABLED;
  if (enum_string == "disabled")
    return EXTENSION_INSTALL_STATUS_DISABLED;
  if (enum_string == "terminated")
    return EXTENSION_INSTALL_STATUS_TERMINATED;
  if (enum_string == "blacklisted")
    return EXTENSION_INSTALL_STATUS_BLACKLISTED;
  if (enum_string == "custodian_approval_required")
    return EXTENSION_INSTALL_STATUS_CUSTODIAN_APPROVAL_REQUIRED;
  if (enum_string == "force_installed")
    return EXTENSION_INSTALL_STATUS_FORCE_INSTALLED;
  return EXTENSION_INSTALL_STATUS_NONE;
}



//
// Functions
//

namespace BeginInstallWithManifest3 {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: id(std::move(rhs.id)),
manifest(std::move(rhs.manifest)),
icon_url(std::move(rhs.icon_url)),
localized_name(std::move(rhs.localized_name)),
locale(std::move(rhs.locale)),
app_install_bubble(std::move(rhs.app_install_bubble)),
enable_launcher(std::move(rhs.enable_launcher)),
authuser(std::move(rhs.authuser)){
additional_properties.Swap(&rhs.additional_properties);
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
id = std::move(rhs.id);
manifest = std::move(rhs.manifest);
icon_url = std::move(rhs.icon_url);
localized_name = std::move(rhs.localized_name);
locale = std::move(rhs.locale);
app_install_bubble = std::move(rhs.app_install_bubble);
enable_launcher = std::move(rhs.enable_launcher);
authuser = std::move(rhs.authuser);additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* manifest_value = NULL;
  if (!dict->GetWithoutPathExpansion("manifest", &manifest_value)) {
    return false;
  }
  {
    if (!manifest_value->GetAsString(&out->manifest)) {
      return false;
    }
  }

  const base::Value* icon_url_value = NULL;
  if (dict->GetWithoutPathExpansion("iconUrl", &icon_url_value)) {
    {
      std::string temp;
      if (!icon_url_value->GetAsString(&temp)) {
        out->icon_url.reset();
        return false;
      }
      else
        out->icon_url.reset(new std::string(temp));
    }
  }

  const base::Value* localized_name_value = NULL;
  if (dict->GetWithoutPathExpansion("localizedName", &localized_name_value)) {
    {
      std::string temp;
      if (!localized_name_value->GetAsString(&temp)) {
        out->localized_name.reset();
        return false;
      }
      else
        out->localized_name.reset(new std::string(temp));
    }
  }

  const base::Value* locale_value = NULL;
  if (dict->GetWithoutPathExpansion("locale", &locale_value)) {
    {
      std::string temp;
      if (!locale_value->GetAsString(&temp)) {
        out->locale.reset();
        return false;
      }
      else
        out->locale.reset(new std::string(temp));
    }
  }

  const base::Value* app_install_bubble_value = NULL;
  if (dict->GetWithoutPathExpansion("appInstallBubble", &app_install_bubble_value)) {
    {
      bool temp;
      if (!app_install_bubble_value->GetAsBoolean(&temp)) {
        out->app_install_bubble.reset();
        return false;
      }
      else
        out->app_install_bubble.reset(new bool(temp));
    }
  }

  const base::Value* enable_launcher_value = NULL;
  if (dict->GetWithoutPathExpansion("enableLauncher", &enable_launcher_value)) {
    {
      bool temp;
      if (!enable_launcher_value->GetAsBoolean(&temp)) {
        out->enable_launcher.reset();
        return false;
      }
      else
        out->enable_launcher.reset(new bool(temp));
    }
  }

  const base::Value* authuser_value = NULL;
  if (dict->GetWithoutPathExpansion("authuser", &authuser_value)) {
    {
      std::string temp;
      if (!authuser_value->GetAsString(&temp)) {
        out->authuser.reset();
        return false;
      }
      else
        out->authuser.reset(new std::string(temp));
    }
  }

  out->additional_properties.MergeDictionary(dict);
  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Details::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Result& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(webstore_private::ToString(result)));

  return create_results;
}
}  // namespace BeginInstallWithManifest3

namespace CompleteInstall {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* expected_id_value = NULL;
  if (args.Get(0, &expected_id_value) &&
      !expected_id_value->is_none()) {
    {
      if (!expected_id_value->GetAsString(&params->expected_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace CompleteInstall

namespace EnableAppLauncher {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace EnableAppLauncher

namespace GetBrowserLogin {

Results::Info::Info()
 {}

Results::Info::~Info() {}
Results::Info::Info(Info&& rhs)
: login(std::move(rhs.login)){
}

Results::Info& Results::Info::operator=(Info&& rhs)
{
login = std::move(rhs.login);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Info::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("login", std::make_unique<base::Value>(this->login));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Info& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetBrowserLogin

namespace GetStoreLogin {

std::unique_ptr<base::ListValue> Results::Create(const std::string& login) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(login));

  return create_results;
}
}  // namespace GetStoreLogin

namespace SetStoreLogin {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* login_value = NULL;
  if (args.Get(0, &login_value) &&
      !login_value->is_none()) {
    {
      if (!login_value->GetAsString(&params->login)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetStoreLogin

namespace GetWebGLStatus {

std::unique_ptr<base::ListValue> Results::Create(const WebGlStatus& webgl_status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(webstore_private::ToString(webgl_status)));

  return create_results;
}
}  // namespace GetWebGLStatus

namespace GetIsLauncherEnabled {

std::unique_ptr<base::ListValue> Results::Create(bool is_enabled) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(is_enabled));

  return create_results;
}
}  // namespace GetIsLauncherEnabled

namespace IsInIncognitoMode {

std::unique_ptr<base::ListValue> Results::Create(bool is_incognito) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(is_incognito));

  return create_results;
}
}  // namespace IsInIncognitoMode

namespace GetEphemeralAppsEnabled {

std::unique_ptr<base::ListValue> Results::Create(bool is_enabled) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(is_enabled));

  return create_results;
}
}  // namespace GetEphemeralAppsEnabled

namespace LaunchEphemeralApp {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Result& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(webstore_private::ToString(result)));

  return create_results;
}
}  // namespace LaunchEphemeralApp

namespace IsPendingCustodianApproval {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool is_pending_approval) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(is_pending_approval));

  return create_results;
}
}  // namespace IsPendingCustodianApproval

namespace GetReferrerChain {

std::unique_ptr<base::ListValue> Results::Create(const std::string& referrer_chain) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(referrer_chain));

  return create_results;
}
}  // namespace GetReferrerChain

namespace GetExtensionStatus {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* manifest_value = NULL;
  if (args.Get(1, &manifest_value) &&
      !manifest_value->is_none()) {
    {
      std::string temp;
      if (!manifest_value->GetAsString(&temp)) {
        params->manifest.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->manifest.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ExtensionInstallStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(webstore_private::ToString(status)));

  return create_results;
}
}  // namespace GetExtensionStatus

namespace RequestExtension {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ExtensionInstallStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(webstore_private::ToString(status)));

  return create_results;
}
}  // namespace RequestExtension

}  // namespace webstore_private
}  // namespace api
}  // namespace extensions

