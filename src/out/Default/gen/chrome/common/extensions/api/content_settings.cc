// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/content_settings.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/content_settings.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace content_settings {
//
// Properties
//

//
// Types
//

ResourceIdentifier::ResourceIdentifier()
 {}

ResourceIdentifier::~ResourceIdentifier() {}
ResourceIdentifier::ResourceIdentifier(ResourceIdentifier&& rhs)
: id(std::move(rhs.id)),
description(std::move(rhs.description)){
}

ResourceIdentifier& ResourceIdentifier::operator=(ResourceIdentifier&& rhs)
{
id = std::move(rhs.id);
description = std::move(rhs.description);
return *this;
}

// static
bool ResourceIdentifier::Populate(
    const base::Value& value, ResourceIdentifier* out) {
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

  const base::Value* description_value = NULL;
  if (dict->GetWithoutPathExpansion("description", &description_value)) {
    {
      std::string temp;
      if (!description_value->GetAsString(&temp)) {
        out->description.reset();
        return false;
      }
      else
        out->description.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ResourceIdentifier> ResourceIdentifier::FromValue(const base::Value& value) {
  std::unique_ptr<ResourceIdentifier> out(new ResourceIdentifier());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ResourceIdentifier::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  if (this->description.get()) {
    to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(*this->description));

  }

  return to_value_result;
}


const char* ToString(Scope enum_param) {
  switch (enum_param) {
    case SCOPE_REGULAR:
      return "regular";
    case SCOPE_INCOGNITO_SESSION_ONLY:
      return "incognito_session_only";
    case SCOPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Scope ParseScope(const std::string& enum_string) {
  if (enum_string == "regular")
    return SCOPE_REGULAR;
  if (enum_string == "incognito_session_only")
    return SCOPE_INCOGNITO_SESSION_ONLY;
  return SCOPE_NONE;
}


namespace ContentSetting {

namespace Clear {

Params::Details::Details()
: scope(SCOPE_NONE) {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: scope(rhs.scope){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
scope = rhs.scope;
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->scope = SCOPE_NONE;
  const base::Value* scope_value = NULL;
  if (dict->GetWithoutPathExpansion("scope", &scope_value)) {
    {
      std::string scope_as_string;
      if (!scope_value->GetAsString(&scope_as_string)) {
        return false;
      }
      out->scope = ParseScope(scope_as_string);
      if (out->scope == SCOPE_NONE) {
        return false;
      }
    }
    } else {
    out->scope = SCOPE_NONE;
  }

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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Clear

namespace Get {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: primary_url(std::move(rhs.primary_url)),
secondary_url(std::move(rhs.secondary_url)),
resource_identifier(std::move(rhs.resource_identifier)),
incognito(std::move(rhs.incognito)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
primary_url = std::move(rhs.primary_url);
secondary_url = std::move(rhs.secondary_url);
resource_identifier = std::move(rhs.resource_identifier);
incognito = std::move(rhs.incognito);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* primary_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("primaryUrl", &primary_url_value)) {
    return false;
  }
  {
    if (!primary_url_value->GetAsString(&out->primary_url)) {
      return false;
    }
  }

  const base::Value* secondary_url_value = NULL;
  if (dict->GetWithoutPathExpansion("secondaryUrl", &secondary_url_value)) {
    {
      std::string temp;
      if (!secondary_url_value->GetAsString(&temp)) {
        out->secondary_url.reset();
        return false;
      }
      else
        out->secondary_url.reset(new std::string(temp));
    }
  }

  const base::Value* resource_identifier_value = NULL;
  if (dict->GetWithoutPathExpansion("resourceIdentifier", &resource_identifier_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!resource_identifier_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ResourceIdentifier> temp(new ResourceIdentifier());
        if (!ResourceIdentifier::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->resource_identifier = std::move(temp);
      }
    }
  }

  const base::Value* incognito_value = NULL;
  if (dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    {
      bool temp;
      if (!incognito_value->GetAsBoolean(&temp)) {
        out->incognito.reset();
        return false;
      }
      else
        out->incognito.reset(new bool(temp));
    }
  }

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


Results::Details::Details()
 {}

Results::Details::~Details() {}
Results::Details::Details(Details&& rhs)
: setting(std::move(rhs.setting)){
}

Results::Details& Results::Details::operator=(Details&& rhs)
{
setting = std::move(rhs.setting);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("setting", (this->setting)->CreateDeepCopy());


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}
}  // namespace Get

namespace Set {

Params::Details::Details()
: scope(SCOPE_NONE) {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: primary_pattern(std::move(rhs.primary_pattern)),
secondary_pattern(std::move(rhs.secondary_pattern)),
resource_identifier(std::move(rhs.resource_identifier)),
setting(std::move(rhs.setting)),
scope(rhs.scope){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
primary_pattern = std::move(rhs.primary_pattern);
secondary_pattern = std::move(rhs.secondary_pattern);
resource_identifier = std::move(rhs.resource_identifier);
setting = std::move(rhs.setting);
scope = rhs.scope;
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->scope = SCOPE_NONE;
  const base::Value* primary_pattern_value = NULL;
  if (!dict->GetWithoutPathExpansion("primaryPattern", &primary_pattern_value)) {
    return false;
  }
  {
    if (!primary_pattern_value->GetAsString(&out->primary_pattern)) {
      return false;
    }
  }

  const base::Value* secondary_pattern_value = NULL;
  if (dict->GetWithoutPathExpansion("secondaryPattern", &secondary_pattern_value)) {
    {
      std::string temp;
      if (!secondary_pattern_value->GetAsString(&temp)) {
        out->secondary_pattern.reset();
        return false;
      }
      else
        out->secondary_pattern.reset(new std::string(temp));
    }
  }

  const base::Value* resource_identifier_value = NULL;
  if (dict->GetWithoutPathExpansion("resourceIdentifier", &resource_identifier_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!resource_identifier_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ResourceIdentifier> temp(new ResourceIdentifier());
        if (!ResourceIdentifier::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->resource_identifier = std::move(temp);
      }
    }
  }

  const base::Value* setting_value = NULL;
  if (!dict->GetWithoutPathExpansion("setting", &setting_value)) {
    return false;
  }
  {
    out->setting = setting_value->CreateDeepCopy();
  }

  const base::Value* scope_value = NULL;
  if (dict->GetWithoutPathExpansion("scope", &scope_value)) {
    {
      std::string scope_as_string;
      if (!scope_value->GetAsString(&scope_as_string)) {
        return false;
      }
      out->scope = ParseScope(scope_as_string);
      if (out->scope == SCOPE_NONE) {
        return false;
      }
    }
    } else {
    out->scope = SCOPE_NONE;
  }

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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Set

namespace GetResourceIdentifiers {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<ResourceIdentifier>& resource_identifiers) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(resource_identifiers));

  return create_results;
}
}  // namespace GetResourceIdentifiers

}  // namespace ContentSetting

const char* ToString(CookiesContentSetting enum_param) {
  switch (enum_param) {
    case COOKIES_CONTENT_SETTING_ALLOW:
      return "allow";
    case COOKIES_CONTENT_SETTING_BLOCK:
      return "block";
    case COOKIES_CONTENT_SETTING_SESSION_ONLY:
      return "session_only";
    case COOKIES_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CookiesContentSetting ParseCookiesContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return COOKIES_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return COOKIES_CONTENT_SETTING_BLOCK;
  if (enum_string == "session_only")
    return COOKIES_CONTENT_SETTING_SESSION_ONLY;
  return COOKIES_CONTENT_SETTING_NONE;
}


const char* ToString(ImagesContentSetting enum_param) {
  switch (enum_param) {
    case IMAGES_CONTENT_SETTING_ALLOW:
      return "allow";
    case IMAGES_CONTENT_SETTING_BLOCK:
      return "block";
    case IMAGES_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ImagesContentSetting ParseImagesContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return IMAGES_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return IMAGES_CONTENT_SETTING_BLOCK;
  return IMAGES_CONTENT_SETTING_NONE;
}


const char* ToString(JavascriptContentSetting enum_param) {
  switch (enum_param) {
    case JAVASCRIPT_CONTENT_SETTING_ALLOW:
      return "allow";
    case JAVASCRIPT_CONTENT_SETTING_BLOCK:
      return "block";
    case JAVASCRIPT_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

JavascriptContentSetting ParseJavascriptContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return JAVASCRIPT_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return JAVASCRIPT_CONTENT_SETTING_BLOCK;
  return JAVASCRIPT_CONTENT_SETTING_NONE;
}


const char* ToString(LocationContentSetting enum_param) {
  switch (enum_param) {
    case LOCATION_CONTENT_SETTING_ALLOW:
      return "allow";
    case LOCATION_CONTENT_SETTING_BLOCK:
      return "block";
    case LOCATION_CONTENT_SETTING_ASK:
      return "ask";
    case LOCATION_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LocationContentSetting ParseLocationContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return LOCATION_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return LOCATION_CONTENT_SETTING_BLOCK;
  if (enum_string == "ask")
    return LOCATION_CONTENT_SETTING_ASK;
  return LOCATION_CONTENT_SETTING_NONE;
}


const char* ToString(PluginsContentSetting enum_param) {
  switch (enum_param) {
    case PLUGINS_CONTENT_SETTING_ALLOW:
      return "allow";
    case PLUGINS_CONTENT_SETTING_BLOCK:
      return "block";
    case PLUGINS_CONTENT_SETTING_DETECT_IMPORTANT_CONTENT:
      return "detect_important_content";
    case PLUGINS_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PluginsContentSetting ParsePluginsContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return PLUGINS_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return PLUGINS_CONTENT_SETTING_BLOCK;
  if (enum_string == "detect_important_content")
    return PLUGINS_CONTENT_SETTING_DETECT_IMPORTANT_CONTENT;
  return PLUGINS_CONTENT_SETTING_NONE;
}


const char* ToString(PopupsContentSetting enum_param) {
  switch (enum_param) {
    case POPUPS_CONTENT_SETTING_ALLOW:
      return "allow";
    case POPUPS_CONTENT_SETTING_BLOCK:
      return "block";
    case POPUPS_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PopupsContentSetting ParsePopupsContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return POPUPS_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return POPUPS_CONTENT_SETTING_BLOCK;
  return POPUPS_CONTENT_SETTING_NONE;
}


const char* ToString(NotificationsContentSetting enum_param) {
  switch (enum_param) {
    case NOTIFICATIONS_CONTENT_SETTING_ALLOW:
      return "allow";
    case NOTIFICATIONS_CONTENT_SETTING_BLOCK:
      return "block";
    case NOTIFICATIONS_CONTENT_SETTING_ASK:
      return "ask";
    case NOTIFICATIONS_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

NotificationsContentSetting ParseNotificationsContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return NOTIFICATIONS_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return NOTIFICATIONS_CONTENT_SETTING_BLOCK;
  if (enum_string == "ask")
    return NOTIFICATIONS_CONTENT_SETTING_ASK;
  return NOTIFICATIONS_CONTENT_SETTING_NONE;
}


const char* ToString(FullscreenContentSetting enum_param) {
  switch (enum_param) {
    case FULLSCREEN_CONTENT_SETTING_ALLOW:
      return "allow";
    case FULLSCREEN_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FullscreenContentSetting ParseFullscreenContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return FULLSCREEN_CONTENT_SETTING_ALLOW;
  return FULLSCREEN_CONTENT_SETTING_NONE;
}


const char* ToString(MouselockContentSetting enum_param) {
  switch (enum_param) {
    case MOUSELOCK_CONTENT_SETTING_ALLOW:
      return "allow";
    case MOUSELOCK_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MouselockContentSetting ParseMouselockContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return MOUSELOCK_CONTENT_SETTING_ALLOW;
  return MOUSELOCK_CONTENT_SETTING_NONE;
}


const char* ToString(MicrophoneContentSetting enum_param) {
  switch (enum_param) {
    case MICROPHONE_CONTENT_SETTING_ALLOW:
      return "allow";
    case MICROPHONE_CONTENT_SETTING_BLOCK:
      return "block";
    case MICROPHONE_CONTENT_SETTING_ASK:
      return "ask";
    case MICROPHONE_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MicrophoneContentSetting ParseMicrophoneContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return MICROPHONE_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return MICROPHONE_CONTENT_SETTING_BLOCK;
  if (enum_string == "ask")
    return MICROPHONE_CONTENT_SETTING_ASK;
  return MICROPHONE_CONTENT_SETTING_NONE;
}


const char* ToString(CameraContentSetting enum_param) {
  switch (enum_param) {
    case CAMERA_CONTENT_SETTING_ALLOW:
      return "allow";
    case CAMERA_CONTENT_SETTING_BLOCK:
      return "block";
    case CAMERA_CONTENT_SETTING_ASK:
      return "ask";
    case CAMERA_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CameraContentSetting ParseCameraContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return CAMERA_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return CAMERA_CONTENT_SETTING_BLOCK;
  if (enum_string == "ask")
    return CAMERA_CONTENT_SETTING_ASK;
  return CAMERA_CONTENT_SETTING_NONE;
}


const char* ToString(PpapiBrokerContentSetting enum_param) {
  switch (enum_param) {
    case PPAPI_BROKER_CONTENT_SETTING_ALLOW:
      return "allow";
    case PPAPI_BROKER_CONTENT_SETTING_BLOCK:
      return "block";
    case PPAPI_BROKER_CONTENT_SETTING_ASK:
      return "ask";
    case PPAPI_BROKER_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PpapiBrokerContentSetting ParsePpapiBrokerContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return PPAPI_BROKER_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return PPAPI_BROKER_CONTENT_SETTING_BLOCK;
  if (enum_string == "ask")
    return PPAPI_BROKER_CONTENT_SETTING_ASK;
  return PPAPI_BROKER_CONTENT_SETTING_NONE;
}


const char* ToString(MultipleAutomaticDownloadsContentSetting enum_param) {
  switch (enum_param) {
    case MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_ALLOW:
      return "allow";
    case MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_BLOCK:
      return "block";
    case MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_ASK:
      return "ask";
    case MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MultipleAutomaticDownloadsContentSetting ParseMultipleAutomaticDownloadsContentSetting(const std::string& enum_string) {
  if (enum_string == "allow")
    return MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_ALLOW;
  if (enum_string == "block")
    return MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_BLOCK;
  if (enum_string == "ask")
    return MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_ASK;
  return MULTIPLE_AUTOMATIC_DOWNLOADS_CONTENT_SETTING_NONE;
}



}  // namespace content_settings
}  // namespace api
}  // namespace extensions

