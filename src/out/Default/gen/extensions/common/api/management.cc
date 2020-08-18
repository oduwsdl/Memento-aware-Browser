// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/management.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/management.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace management {
//
// Types
//

IconInfo::IconInfo()
: size(0) {}

IconInfo::~IconInfo() {}
IconInfo::IconInfo(IconInfo&& rhs)
: size(rhs.size),
url(std::move(rhs.url)){
}

IconInfo& IconInfo::operator=(IconInfo&& rhs)
{
size = rhs.size;
url = std::move(rhs.url);
return *this;
}

// static
bool IconInfo::Populate(
    const base::Value& value, IconInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* size_value = NULL;
  if (!dict->GetWithoutPathExpansion("size", &size_value)) {
    return false;
  }
  {
    if (!size_value->GetAsInteger(&out->size)) {
      return false;
    }
  }

  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<IconInfo> IconInfo::FromValue(const base::Value& value) {
  std::unique_ptr<IconInfo> out(new IconInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> IconInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("size", std::make_unique<base::Value>(this->size));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));


  return to_value_result;
}


const char* ToString(LaunchType enum_param) {
  switch (enum_param) {
    case LAUNCH_TYPE_OPEN_AS_REGULAR_TAB:
      return "OPEN_AS_REGULAR_TAB";
    case LAUNCH_TYPE_OPEN_AS_PINNED_TAB:
      return "OPEN_AS_PINNED_TAB";
    case LAUNCH_TYPE_OPEN_AS_WINDOW:
      return "OPEN_AS_WINDOW";
    case LAUNCH_TYPE_OPEN_FULL_SCREEN:
      return "OPEN_FULL_SCREEN";
    case LAUNCH_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LaunchType ParseLaunchType(const std::string& enum_string) {
  if (enum_string == "OPEN_AS_REGULAR_TAB")
    return LAUNCH_TYPE_OPEN_AS_REGULAR_TAB;
  if (enum_string == "OPEN_AS_PINNED_TAB")
    return LAUNCH_TYPE_OPEN_AS_PINNED_TAB;
  if (enum_string == "OPEN_AS_WINDOW")
    return LAUNCH_TYPE_OPEN_AS_WINDOW;
  if (enum_string == "OPEN_FULL_SCREEN")
    return LAUNCH_TYPE_OPEN_FULL_SCREEN;
  return LAUNCH_TYPE_NONE;
}


const char* ToString(ExtensionDisabledReason enum_param) {
  switch (enum_param) {
    case EXTENSION_DISABLED_REASON_UNKNOWN:
      return "unknown";
    case EXTENSION_DISABLED_REASON_PERMISSIONS_INCREASE:
      return "permissions_increase";
    case EXTENSION_DISABLED_REASON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionDisabledReason ParseExtensionDisabledReason(const std::string& enum_string) {
  if (enum_string == "unknown")
    return EXTENSION_DISABLED_REASON_UNKNOWN;
  if (enum_string == "permissions_increase")
    return EXTENSION_DISABLED_REASON_PERMISSIONS_INCREASE;
  return EXTENSION_DISABLED_REASON_NONE;
}


const char* ToString(ExtensionType enum_param) {
  switch (enum_param) {
    case EXTENSION_TYPE_EXTENSION:
      return "extension";
    case EXTENSION_TYPE_HOSTED_APP:
      return "hosted_app";
    case EXTENSION_TYPE_PACKAGED_APP:
      return "packaged_app";
    case EXTENSION_TYPE_LEGACY_PACKAGED_APP:
      return "legacy_packaged_app";
    case EXTENSION_TYPE_THEME:
      return "theme";
    case EXTENSION_TYPE_LOGIN_SCREEN_EXTENSION:
      return "login_screen_extension";
    case EXTENSION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionType ParseExtensionType(const std::string& enum_string) {
  if (enum_string == "extension")
    return EXTENSION_TYPE_EXTENSION;
  if (enum_string == "hosted_app")
    return EXTENSION_TYPE_HOSTED_APP;
  if (enum_string == "packaged_app")
    return EXTENSION_TYPE_PACKAGED_APP;
  if (enum_string == "legacy_packaged_app")
    return EXTENSION_TYPE_LEGACY_PACKAGED_APP;
  if (enum_string == "theme")
    return EXTENSION_TYPE_THEME;
  if (enum_string == "login_screen_extension")
    return EXTENSION_TYPE_LOGIN_SCREEN_EXTENSION;
  return EXTENSION_TYPE_NONE;
}


const char* ToString(ExtensionInstallType enum_param) {
  switch (enum_param) {
    case EXTENSION_INSTALL_TYPE_ADMIN:
      return "admin";
    case EXTENSION_INSTALL_TYPE_DEVELOPMENT:
      return "development";
    case EXTENSION_INSTALL_TYPE_NORMAL:
      return "normal";
    case EXTENSION_INSTALL_TYPE_SIDELOAD:
      return "sideload";
    case EXTENSION_INSTALL_TYPE_OTHER:
      return "other";
    case EXTENSION_INSTALL_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionInstallType ParseExtensionInstallType(const std::string& enum_string) {
  if (enum_string == "admin")
    return EXTENSION_INSTALL_TYPE_ADMIN;
  if (enum_string == "development")
    return EXTENSION_INSTALL_TYPE_DEVELOPMENT;
  if (enum_string == "normal")
    return EXTENSION_INSTALL_TYPE_NORMAL;
  if (enum_string == "sideload")
    return EXTENSION_INSTALL_TYPE_SIDELOAD;
  if (enum_string == "other")
    return EXTENSION_INSTALL_TYPE_OTHER;
  return EXTENSION_INSTALL_TYPE_NONE;
}


ExtensionInfo::ExtensionInfo()
: may_disable(false),
enabled(false),
disabled_reason(EXTENSION_DISABLED_REASON_NONE),
is_app(false),
type(EXTENSION_TYPE_NONE),
offline_enabled(false),
install_type(EXTENSION_INSTALL_TYPE_NONE),
launch_type(LAUNCH_TYPE_NONE) {}

ExtensionInfo::~ExtensionInfo() {}
ExtensionInfo::ExtensionInfo(ExtensionInfo&& rhs)
: id(std::move(rhs.id)),
name(std::move(rhs.name)),
short_name(std::move(rhs.short_name)),
description(std::move(rhs.description)),
version(std::move(rhs.version)),
version_name(std::move(rhs.version_name)),
may_disable(rhs.may_disable),
may_enable(std::move(rhs.may_enable)),
enabled(rhs.enabled),
disabled_reason(rhs.disabled_reason),
is_app(rhs.is_app),
type(rhs.type),
app_launch_url(std::move(rhs.app_launch_url)),
homepage_url(std::move(rhs.homepage_url)),
update_url(std::move(rhs.update_url)),
offline_enabled(rhs.offline_enabled),
options_url(std::move(rhs.options_url)),
icons(std::move(rhs.icons)),
permissions(std::move(rhs.permissions)),
host_permissions(std::move(rhs.host_permissions)),
install_type(rhs.install_type),
launch_type(rhs.launch_type),
available_launch_types(std::move(rhs.available_launch_types)){
}

ExtensionInfo& ExtensionInfo::operator=(ExtensionInfo&& rhs)
{
id = std::move(rhs.id);
name = std::move(rhs.name);
short_name = std::move(rhs.short_name);
description = std::move(rhs.description);
version = std::move(rhs.version);
version_name = std::move(rhs.version_name);
may_disable = rhs.may_disable;
may_enable = std::move(rhs.may_enable);
enabled = rhs.enabled;
disabled_reason = rhs.disabled_reason;
is_app = rhs.is_app;
type = rhs.type;
app_launch_url = std::move(rhs.app_launch_url);
homepage_url = std::move(rhs.homepage_url);
update_url = std::move(rhs.update_url);
offline_enabled = rhs.offline_enabled;
options_url = std::move(rhs.options_url);
icons = std::move(rhs.icons);
permissions = std::move(rhs.permissions);
host_permissions = std::move(rhs.host_permissions);
install_type = rhs.install_type;
launch_type = rhs.launch_type;
available_launch_types = std::move(rhs.available_launch_types);
return *this;
}

// static
bool ExtensionInfo::Populate(
    const base::Value& value, ExtensionInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->disabled_reason = EXTENSION_DISABLED_REASON_NONE;
  out->launch_type = LAUNCH_TYPE_NONE;
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* short_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("shortName", &short_name_value)) {
    return false;
  }
  {
    if (!short_name_value->GetAsString(&out->short_name)) {
      return false;
    }
  }

  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* version_value = NULL;
  if (!dict->GetWithoutPathExpansion("version", &version_value)) {
    return false;
  }
  {
    if (!version_value->GetAsString(&out->version)) {
      return false;
    }
  }

  const base::Value* version_name_value = NULL;
  if (dict->GetWithoutPathExpansion("versionName", &version_name_value)) {
    {
      std::string temp;
      if (!version_name_value->GetAsString(&temp)) {
        out->version_name.reset();
        return false;
      }
      else
        out->version_name.reset(new std::string(temp));
    }
  }

  const base::Value* may_disable_value = NULL;
  if (!dict->GetWithoutPathExpansion("mayDisable", &may_disable_value)) {
    return false;
  }
  {
    if (!may_disable_value->GetAsBoolean(&out->may_disable)) {
      return false;
    }
  }

  const base::Value* may_enable_value = NULL;
  if (dict->GetWithoutPathExpansion("mayEnable", &may_enable_value)) {
    {
      bool temp;
      if (!may_enable_value->GetAsBoolean(&temp)) {
        out->may_enable.reset();
        return false;
      }
      else
        out->may_enable.reset(new bool(temp));
    }
  }

  const base::Value* enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("enabled", &enabled_value)) {
    return false;
  }
  {
    if (!enabled_value->GetAsBoolean(&out->enabled)) {
      return false;
    }
  }

  const base::Value* disabled_reason_value = NULL;
  if (dict->GetWithoutPathExpansion("disabledReason", &disabled_reason_value)) {
    {
      std::string extension_disabled_reason_as_string;
      if (!disabled_reason_value->GetAsString(&extension_disabled_reason_as_string)) {
        return false;
      }
      out->disabled_reason = ParseExtensionDisabledReason(extension_disabled_reason_as_string);
      if (out->disabled_reason == EXTENSION_DISABLED_REASON_NONE) {
        return false;
      }
    }
    } else {
    out->disabled_reason = EXTENSION_DISABLED_REASON_NONE;
  }

  const base::Value* is_app_value = NULL;
  if (!dict->GetWithoutPathExpansion("isApp", &is_app_value)) {
    return false;
  }
  {
    if (!is_app_value->GetAsBoolean(&out->is_app)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string extension_type_as_string;
    if (!type_value->GetAsString(&extension_type_as_string)) {
      return false;
    }
    out->type = ParseExtensionType(extension_type_as_string);
    if (out->type == EXTENSION_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* app_launch_url_value = NULL;
  if (dict->GetWithoutPathExpansion("appLaunchUrl", &app_launch_url_value)) {
    {
      std::string temp;
      if (!app_launch_url_value->GetAsString(&temp)) {
        out->app_launch_url.reset();
        return false;
      }
      else
        out->app_launch_url.reset(new std::string(temp));
    }
  }

  const base::Value* homepage_url_value = NULL;
  if (dict->GetWithoutPathExpansion("homepageUrl", &homepage_url_value)) {
    {
      std::string temp;
      if (!homepage_url_value->GetAsString(&temp)) {
        out->homepage_url.reset();
        return false;
      }
      else
        out->homepage_url.reset(new std::string(temp));
    }
  }

  const base::Value* update_url_value = NULL;
  if (dict->GetWithoutPathExpansion("updateUrl", &update_url_value)) {
    {
      std::string temp;
      if (!update_url_value->GetAsString(&temp)) {
        out->update_url.reset();
        return false;
      }
      else
        out->update_url.reset(new std::string(temp));
    }
  }

  const base::Value* offline_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("offlineEnabled", &offline_enabled_value)) {
    return false;
  }
  {
    if (!offline_enabled_value->GetAsBoolean(&out->offline_enabled)) {
      return false;
    }
  }

  const base::Value* options_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("optionsUrl", &options_url_value)) {
    return false;
  }
  {
    if (!options_url_value->GetAsString(&out->options_url)) {
      return false;
    }
  }

  const base::Value* icons_value = NULL;
  if (dict->GetWithoutPathExpansion("icons", &icons_value)) {
    {
      const base::ListValue* list = NULL;
      if (!icons_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->icons)) {
          return false;
        }
      }
    }
  }

  const base::Value* permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("permissions", &permissions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!permissions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->permissions)) {
        return false;
      }
    }
  }

  const base::Value* host_permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("hostPermissions", &host_permissions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!host_permissions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->host_permissions)) {
        return false;
      }
    }
  }

  const base::Value* install_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("installType", &install_type_value)) {
    return false;
  }
  {
    std::string extension_install_type_as_string;
    if (!install_type_value->GetAsString(&extension_install_type_as_string)) {
      return false;
    }
    out->install_type = ParseExtensionInstallType(extension_install_type_as_string);
    if (out->install_type == EXTENSION_INSTALL_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* launch_type_value = NULL;
  if (dict->GetWithoutPathExpansion("launchType", &launch_type_value)) {
    {
      std::string launch_type_as_string;
      if (!launch_type_value->GetAsString(&launch_type_as_string)) {
        return false;
      }
      out->launch_type = ParseLaunchType(launch_type_as_string);
      if (out->launch_type == LAUNCH_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->launch_type = LAUNCH_TYPE_NONE;
  }

  const base::Value* available_launch_types_value = NULL;
  if (dict->GetWithoutPathExpansion("availableLaunchTypes", &available_launch_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!available_launch_types_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->available_launch_types.reset(new std::vector<LaunchType>);
        for (const auto& it : *(list)) {
          LaunchType tmp;
          std::string launch_type_as_string;
          if (!(it).GetAsString(&launch_type_as_string)) {
            return false;
          }
          tmp = ParseLaunchType(launch_type_as_string);
          if (tmp == LAUNCH_TYPE_NONE) {
            return false;
          }
          out->available_launch_types->push_back(tmp);
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ExtensionInfo> ExtensionInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionInfo> out(new ExtensionInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("shortName", std::make_unique<base::Value>(this->short_name));

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  to_value_result->SetWithoutPathExpansion("version", std::make_unique<base::Value>(this->version));

  if (this->version_name.get()) {
    to_value_result->SetWithoutPathExpansion("versionName", std::make_unique<base::Value>(*this->version_name));

  }
  to_value_result->SetWithoutPathExpansion("mayDisable", std::make_unique<base::Value>(this->may_disable));

  if (this->may_enable.get()) {
    to_value_result->SetWithoutPathExpansion("mayEnable", std::make_unique<base::Value>(*this->may_enable));

  }
  to_value_result->SetWithoutPathExpansion("enabled", std::make_unique<base::Value>(this->enabled));

  if (this->disabled_reason != EXTENSION_DISABLED_REASON_NONE) {
    to_value_result->SetWithoutPathExpansion("disabledReason", std::make_unique<base::Value>(management::ToString(this->disabled_reason)));

  }
  to_value_result->SetWithoutPathExpansion("isApp", std::make_unique<base::Value>(this->is_app));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(management::ToString(this->type)));

  if (this->app_launch_url.get()) {
    to_value_result->SetWithoutPathExpansion("appLaunchUrl", std::make_unique<base::Value>(*this->app_launch_url));

  }
  if (this->homepage_url.get()) {
    to_value_result->SetWithoutPathExpansion("homepageUrl", std::make_unique<base::Value>(*this->homepage_url));

  }
  if (this->update_url.get()) {
    to_value_result->SetWithoutPathExpansion("updateUrl", std::make_unique<base::Value>(*this->update_url));

  }
  to_value_result->SetWithoutPathExpansion("offlineEnabled", std::make_unique<base::Value>(this->offline_enabled));

  to_value_result->SetWithoutPathExpansion("optionsUrl", std::make_unique<base::Value>(this->options_url));

  if (this->icons.get()) {
    to_value_result->SetWithoutPathExpansion("icons", json_schema_compiler::util::CreateValueFromOptionalArray(this->icons));

  }
  to_value_result->SetWithoutPathExpansion("permissions", json_schema_compiler::util::CreateValueFromArray(this->permissions));

  to_value_result->SetWithoutPathExpansion("hostPermissions", json_schema_compiler::util::CreateValueFromArray(this->host_permissions));

  to_value_result->SetWithoutPathExpansion("installType", std::make_unique<base::Value>(management::ToString(this->install_type)));

  if (this->launch_type != LAUNCH_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("launchType", std::make_unique<base::Value>(management::ToString(this->launch_type)));

  }
  if (this->available_launch_types.get()) {
    {
      std::vector<std::string> availableLaunchTypes_list;
      for (const auto& it : *(this->available_launch_types)) {
      availableLaunchTypes_list.push_back(management::ToString(it));
    }
    to_value_result->SetWithoutPathExpansion("availableLaunchTypes", json_schema_compiler::util::CreateValueFromArray(availableLaunchTypes_list));
    }

  }

  return to_value_result;
}



//
// Functions
//

namespace GetAll {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<ExtensionInfo>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetAll

namespace Get {

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


std::unique_ptr<base::ListValue> Results::Create(const ExtensionInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace Get

namespace GetSelf {

std::unique_ptr<base::ListValue> Results::Create(const ExtensionInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetSelf

namespace GetPermissionWarningsById {

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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& permission_warnings) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(permission_warnings));

  return create_results;
}
}  // namespace GetPermissionWarningsById

namespace GetPermissionWarningsByManifest {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* manifest_str_value = NULL;
  if (args.Get(0, &manifest_str_value) &&
      !manifest_str_value->is_none()) {
    {
      if (!manifest_str_value->GetAsString(&params->manifest_str)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& permission_warnings) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(permission_warnings));

  return create_results;
}
}  // namespace GetPermissionWarningsByManifest

namespace SetEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
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

  const base::Value* enabled_value = NULL;
  if (args.Get(1, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
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
}  // namespace SetEnabled

namespace Uninstall {

Params::Options::Options()
 {}

Params::Options::~Options() {}
Params::Options::Options(Options&& rhs)
: show_confirm_dialog(std::move(rhs.show_confirm_dialog)){
}

Params::Options& Params::Options::operator=(Options&& rhs)
{
show_confirm_dialog = std::move(rhs.show_confirm_dialog);
return *this;
}

// static
bool Params::Options::Populate(
    const base::Value& value, Options* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* show_confirm_dialog_value = NULL;
  if (dict->GetWithoutPathExpansion("showConfirmDialog", &show_confirm_dialog_value)) {
    {
      bool temp;
      if (!show_confirm_dialog_value->GetAsBoolean(&temp)) {
        out->show_confirm_dialog.reset();
        return false;
      }
      else
        out->show_confirm_dialog.reset(new bool(temp));
    }
  }

  return true;
}


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

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<Options> temp(new Options());
        if (!Options::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Uninstall

namespace UninstallSelf {

Params::Options::Options()
 {}

Params::Options::~Options() {}
Params::Options::Options(Options&& rhs)
: show_confirm_dialog(std::move(rhs.show_confirm_dialog)){
}

Params::Options& Params::Options::operator=(Options&& rhs)
{
show_confirm_dialog = std::move(rhs.show_confirm_dialog);
return *this;
}

// static
bool Params::Options::Populate(
    const base::Value& value, Options* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* show_confirm_dialog_value = NULL;
  if (dict->GetWithoutPathExpansion("showConfirmDialog", &show_confirm_dialog_value)) {
    {
      bool temp;
      if (!show_confirm_dialog_value->GetAsBoolean(&temp)) {
        out->show_confirm_dialog.reset();
        return false;
      }
      else
        out->show_confirm_dialog.reset(new bool(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<Options> temp(new Options());
        if (!Options::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace UninstallSelf

namespace LaunchApp {

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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace LaunchApp

namespace CreateAppShortcut {

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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace CreateAppShortcut

namespace SetLaunchType {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
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

  const base::Value* launch_type_value = NULL;
  if (args.Get(1, &launch_type_value) &&
      !launch_type_value->is_none()) {
    {
      std::string launch_type_as_string;
      if (!launch_type_value->GetAsString(&launch_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->launch_type = ParseLaunchType(launch_type_as_string);
      if (params->launch_type == LAUNCH_TYPE_NONE) {
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
}  // namespace SetLaunchType

namespace GenerateAppForLink {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* url_value = NULL;
  if (args.Get(0, &url_value) &&
      !url_value->is_none()) {
    {
      if (!url_value->GetAsString(&params->url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* title_value = NULL;
  if (args.Get(1, &title_value) &&
      !title_value->is_none()) {
    {
      if (!title_value->GetAsString(&params->title)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ExtensionInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GenerateAppForLink

namespace CanInstallReplacementAndroidApp {

std::unique_ptr<base::ListValue> Results::Create(bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace CanInstallReplacementAndroidApp

namespace InstallReplacementAndroidApp {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace InstallReplacementAndroidApp

namespace InstallReplacementWebApp {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace InstallReplacementWebApp

//
// Events
//

namespace OnInstalled {

const char kEventName[] = "management.onInstalled";

std::unique_ptr<base::ListValue> Create(const ExtensionInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnInstalled

namespace OnUninstalled {

const char kEventName[] = "management.onUninstalled";

std::unique_ptr<base::ListValue> Create(const std::string& id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(id));

  return create_results;
}

}  // namespace OnUninstalled

namespace OnEnabled {

const char kEventName[] = "management.onEnabled";

std::unique_ptr<base::ListValue> Create(const ExtensionInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnEnabled

namespace OnDisabled {

const char kEventName[] = "management.onDisabled";

std::unique_ptr<base::ListValue> Create(const ExtensionInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnDisabled

}  // namespace management
}  // namespace api
}  // namespace extensions

