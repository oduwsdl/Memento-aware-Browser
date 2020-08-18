// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/dashboard_private.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/dashboard_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace dashboard_private {
//
// Types
//

const char* ToString(Result enum_param) {
  switch (enum_param) {
    case RESULT_EMPTY_STRING:
      return "";
    case RESULT_UNKNOWN_ERROR:
      return "unknown_error";
    case RESULT_USER_CANCELLED:
      return "user_cancelled";
    case RESULT_INVALID_ID:
      return "invalid_id";
    case RESULT_MANIFEST_ERROR:
      return "manifest_error";
    case RESULT_ICON_ERROR:
      return "icon_error";
    case RESULT_INVALID_ICON_URL:
      return "invalid_icon_url";
    case RESULT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Result ParseResult(const std::string& enum_string) {
  if (enum_string == "")
    return RESULT_EMPTY_STRING;
  if (enum_string == "unknown_error")
    return RESULT_UNKNOWN_ERROR;
  if (enum_string == "user_cancelled")
    return RESULT_USER_CANCELLED;
  if (enum_string == "invalid_id")
    return RESULT_INVALID_ID;
  if (enum_string == "manifest_error")
    return RESULT_MANIFEST_ERROR;
  if (enum_string == "icon_error")
    return RESULT_ICON_ERROR;
  if (enum_string == "invalid_icon_url")
    return RESULT_INVALID_ICON_URL;
  return RESULT_NONE;
}



//
// Functions
//

namespace ShowPermissionPromptForDelegatedInstall {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: id(std::move(rhs.id)),
manifest(std::move(rhs.manifest)),
delegated_user(std::move(rhs.delegated_user)),
icon_url(std::move(rhs.icon_url)),
localized_name(std::move(rhs.localized_name)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
id = std::move(rhs.id);
manifest = std::move(rhs.manifest);
delegated_user = std::move(rhs.delegated_user);
icon_url = std::move(rhs.icon_url);
localized_name = std::move(rhs.localized_name);
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

  const base::Value* delegated_user_value = NULL;
  if (!dict->GetWithoutPathExpansion("delegatedUser", &delegated_user_value)) {
    return false;
  }
  {
    if (!delegated_user_value->GetAsString(&out->delegated_user)) {
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
  create_results->Append(std::make_unique<base::Value>(dashboard_private::ToString(result)));

  return create_results;
}
}  // namespace ShowPermissionPromptForDelegatedInstall

}  // namespace dashboard_private
}  // namespace api
}  // namespace extensions

