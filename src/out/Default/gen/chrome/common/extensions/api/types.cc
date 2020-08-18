// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/types.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/types.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace types {
//
// Types
//

const char* ToString(ChromeSettingScope enum_param) {
  switch (enum_param) {
    case CHROME_SETTING_SCOPE_REGULAR:
      return "regular";
    case CHROME_SETTING_SCOPE_REGULAR_ONLY:
      return "regular_only";
    case CHROME_SETTING_SCOPE_INCOGNITO_PERSISTENT:
      return "incognito_persistent";
    case CHROME_SETTING_SCOPE_INCOGNITO_SESSION_ONLY:
      return "incognito_session_only";
    case CHROME_SETTING_SCOPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ChromeSettingScope ParseChromeSettingScope(const std::string& enum_string) {
  if (enum_string == "regular")
    return CHROME_SETTING_SCOPE_REGULAR;
  if (enum_string == "regular_only")
    return CHROME_SETTING_SCOPE_REGULAR_ONLY;
  if (enum_string == "incognito_persistent")
    return CHROME_SETTING_SCOPE_INCOGNITO_PERSISTENT;
  if (enum_string == "incognito_session_only")
    return CHROME_SETTING_SCOPE_INCOGNITO_SESSION_ONLY;
  return CHROME_SETTING_SCOPE_NONE;
}


const char* ToString(LevelOfControl enum_param) {
  switch (enum_param) {
    case LEVEL_OF_CONTROL_NOT_CONTROLLABLE:
      return "not_controllable";
    case LEVEL_OF_CONTROL_CONTROLLED_BY_OTHER_EXTENSIONS:
      return "controlled_by_other_extensions";
    case LEVEL_OF_CONTROL_CONTROLLABLE_BY_THIS_EXTENSION:
      return "controllable_by_this_extension";
    case LEVEL_OF_CONTROL_CONTROLLED_BY_THIS_EXTENSION:
      return "controlled_by_this_extension";
    case LEVEL_OF_CONTROL_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LevelOfControl ParseLevelOfControl(const std::string& enum_string) {
  if (enum_string == "not_controllable")
    return LEVEL_OF_CONTROL_NOT_CONTROLLABLE;
  if (enum_string == "controlled_by_other_extensions")
    return LEVEL_OF_CONTROL_CONTROLLED_BY_OTHER_EXTENSIONS;
  if (enum_string == "controllable_by_this_extension")
    return LEVEL_OF_CONTROL_CONTROLLABLE_BY_THIS_EXTENSION;
  if (enum_string == "controlled_by_this_extension")
    return LEVEL_OF_CONTROL_CONTROLLED_BY_THIS_EXTENSION;
  return LEVEL_OF_CONTROL_NONE;
}


ChromeSetting::ChromeSetting()
 {}

ChromeSetting::~ChromeSetting() {}
ChromeSetting::ChromeSetting(ChromeSetting&& rhs)
{
}

ChromeSetting& ChromeSetting::operator=(ChromeSetting&& rhs)
{

return *this;
}

// static
bool ChromeSetting::Populate(
    const base::Value& value, ChromeSetting* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<ChromeSetting> ChromeSetting::FromValue(const base::Value& value) {
  std::unique_ptr<ChromeSetting> out(new ChromeSetting());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ChromeSetting::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}



}  // namespace types
}  // namespace api
}  // namespace extensions

