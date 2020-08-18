// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/settings_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/settings_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace settings_private {
//
// Types
//

const char* ToString(PrefType enum_param) {
  switch (enum_param) {
    case PREF_TYPE_BOOLEAN:
      return "BOOLEAN";
    case PREF_TYPE_NUMBER:
      return "NUMBER";
    case PREF_TYPE_STRING:
      return "STRING";
    case PREF_TYPE_URL:
      return "URL";
    case PREF_TYPE_LIST:
      return "LIST";
    case PREF_TYPE_DICTIONARY:
      return "DICTIONARY";
    case PREF_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PrefType ParsePrefType(const std::string& enum_string) {
  if (enum_string == "BOOLEAN")
    return PREF_TYPE_BOOLEAN;
  if (enum_string == "NUMBER")
    return PREF_TYPE_NUMBER;
  if (enum_string == "STRING")
    return PREF_TYPE_STRING;
  if (enum_string == "URL")
    return PREF_TYPE_URL;
  if (enum_string == "LIST")
    return PREF_TYPE_LIST;
  if (enum_string == "DICTIONARY")
    return PREF_TYPE_DICTIONARY;
  return PREF_TYPE_NONE;
}


const char* ToString(ControlledBy enum_param) {
  switch (enum_param) {
    case CONTROLLED_BY_DEVICE_POLICY:
      return "DEVICE_POLICY";
    case CONTROLLED_BY_USER_POLICY:
      return "USER_POLICY";
    case CONTROLLED_BY_OWNER:
      return "OWNER";
    case CONTROLLED_BY_PRIMARY_USER:
      return "PRIMARY_USER";
    case CONTROLLED_BY_EXTENSION:
      return "EXTENSION";
    case CONTROLLED_BY_PARENT:
      return "PARENT";
    case CONTROLLED_BY_CHILD_RESTRICTION:
      return "CHILD_RESTRICTION";
    case CONTROLLED_BY_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ControlledBy ParseControlledBy(const std::string& enum_string) {
  if (enum_string == "DEVICE_POLICY")
    return CONTROLLED_BY_DEVICE_POLICY;
  if (enum_string == "USER_POLICY")
    return CONTROLLED_BY_USER_POLICY;
  if (enum_string == "OWNER")
    return CONTROLLED_BY_OWNER;
  if (enum_string == "PRIMARY_USER")
    return CONTROLLED_BY_PRIMARY_USER;
  if (enum_string == "EXTENSION")
    return CONTROLLED_BY_EXTENSION;
  if (enum_string == "PARENT")
    return CONTROLLED_BY_PARENT;
  if (enum_string == "CHILD_RESTRICTION")
    return CONTROLLED_BY_CHILD_RESTRICTION;
  return CONTROLLED_BY_NONE;
}


const char* ToString(Enforcement enum_param) {
  switch (enum_param) {
    case ENFORCEMENT_ENFORCED:
      return "ENFORCED";
    case ENFORCEMENT_RECOMMENDED:
      return "RECOMMENDED";
    case ENFORCEMENT_PARENT_SUPERVISED:
      return "PARENT_SUPERVISED";
    case ENFORCEMENT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Enforcement ParseEnforcement(const std::string& enum_string) {
  if (enum_string == "ENFORCED")
    return ENFORCEMENT_ENFORCED;
  if (enum_string == "RECOMMENDED")
    return ENFORCEMENT_RECOMMENDED;
  if (enum_string == "PARENT_SUPERVISED")
    return ENFORCEMENT_PARENT_SUPERVISED;
  return ENFORCEMENT_NONE;
}


PrefObject::PrefObject()
: type(PREF_TYPE_NONE),
controlled_by(CONTROLLED_BY_NONE),
enforcement(ENFORCEMENT_NONE) {}

PrefObject::~PrefObject() {}
PrefObject::PrefObject(PrefObject&& rhs)
: key(std::move(rhs.key)),
type(rhs.type),
value(std::move(rhs.value)),
controlled_by(rhs.controlled_by),
controlled_by_name(std::move(rhs.controlled_by_name)),
enforcement(rhs.enforcement),
recommended_value(std::move(rhs.recommended_value)),
user_selectable_values(std::move(rhs.user_selectable_values)),
user_control_disabled(std::move(rhs.user_control_disabled)),
extension_id(std::move(rhs.extension_id)),
extension_can_be_disabled(std::move(rhs.extension_can_be_disabled)){
}

PrefObject& PrefObject::operator=(PrefObject&& rhs)
{
key = std::move(rhs.key);
type = rhs.type;
value = std::move(rhs.value);
controlled_by = rhs.controlled_by;
controlled_by_name = std::move(rhs.controlled_by_name);
enforcement = rhs.enforcement;
recommended_value = std::move(rhs.recommended_value);
user_selectable_values = std::move(rhs.user_selectable_values);
user_control_disabled = std::move(rhs.user_control_disabled);
extension_id = std::move(rhs.extension_id);
extension_can_be_disabled = std::move(rhs.extension_can_be_disabled);
return *this;
}

// static
bool PrefObject::Populate(
    const base::Value& value, PrefObject* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->controlled_by = CONTROLLED_BY_NONE;
  out->enforcement = ENFORCEMENT_NONE;
  const base::Value* key_value = NULL;
  if (!dict->GetWithoutPathExpansion("key", &key_value)) {
    return false;
  }
  {
    if (!key_value->GetAsString(&out->key)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string pref_type_as_string;
    if (!type_value->GetAsString(&pref_type_as_string)) {
      return false;
    }
    out->type = ParsePrefType(pref_type_as_string);
    if (out->type == PREF_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    return false;
  }
  {
    out->value = value_value->CreateDeepCopy();
  }

  const base::Value* controlled_by_value = NULL;
  if (dict->GetWithoutPathExpansion("controlledBy", &controlled_by_value)) {
    {
      std::string controlled_by_as_string;
      if (!controlled_by_value->GetAsString(&controlled_by_as_string)) {
        return false;
      }
      out->controlled_by = ParseControlledBy(controlled_by_as_string);
      if (out->controlled_by == CONTROLLED_BY_NONE) {
        return false;
      }
    }
    } else {
    out->controlled_by = CONTROLLED_BY_NONE;
  }

  const base::Value* controlled_by_name_value = NULL;
  if (dict->GetWithoutPathExpansion("controlledByName", &controlled_by_name_value)) {
    {
      std::string temp;
      if (!controlled_by_name_value->GetAsString(&temp)) {
        out->controlled_by_name.reset();
        return false;
      }
      else
        out->controlled_by_name.reset(new std::string(temp));
    }
  }

  const base::Value* enforcement_value = NULL;
  if (dict->GetWithoutPathExpansion("enforcement", &enforcement_value)) {
    {
      std::string enforcement_as_string;
      if (!enforcement_value->GetAsString(&enforcement_as_string)) {
        return false;
      }
      out->enforcement = ParseEnforcement(enforcement_as_string);
      if (out->enforcement == ENFORCEMENT_NONE) {
        return false;
      }
    }
    } else {
    out->enforcement = ENFORCEMENT_NONE;
  }

  const base::Value* recommended_value_value = NULL;
  if (dict->GetWithoutPathExpansion("recommendedValue", &recommended_value_value)) {
    {
      out->recommended_value = recommended_value_value->CreateDeepCopy();
    }
  }

  const base::Value* user_selectable_values_value = NULL;
  if (dict->GetWithoutPathExpansion("userSelectableValues", &user_selectable_values_value)) {
    {
      const base::ListValue* list = NULL;
      if (!user_selectable_values_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->user_selectable_values)) {
          return false;
        }
      }
    }
  }

  const base::Value* user_control_disabled_value = NULL;
  if (dict->GetWithoutPathExpansion("userControlDisabled", &user_control_disabled_value)) {
    {
      bool temp;
      if (!user_control_disabled_value->GetAsBoolean(&temp)) {
        out->user_control_disabled.reset();
        return false;
      }
      else
        out->user_control_disabled.reset(new bool(temp));
    }
  }

  const base::Value* extension_id_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    {
      std::string temp;
      if (!extension_id_value->GetAsString(&temp)) {
        out->extension_id.reset();
        return false;
      }
      else
        out->extension_id.reset(new std::string(temp));
    }
  }

  const base::Value* extension_can_be_disabled_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionCanBeDisabled", &extension_can_be_disabled_value)) {
    {
      bool temp;
      if (!extension_can_be_disabled_value->GetAsBoolean(&temp)) {
        out->extension_can_be_disabled.reset();
        return false;
      }
      else
        out->extension_can_be_disabled.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<PrefObject> PrefObject::FromValue(const base::Value& value) {
  std::unique_ptr<PrefObject> out(new PrefObject());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PrefObject::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("key", std::make_unique<base::Value>(this->key));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(settings_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("value", (this->value)->CreateDeepCopy());

  if (this->controlled_by != CONTROLLED_BY_NONE) {
    to_value_result->SetWithoutPathExpansion("controlledBy", std::make_unique<base::Value>(settings_private::ToString(this->controlled_by)));

  }
  if (this->controlled_by_name.get()) {
    to_value_result->SetWithoutPathExpansion("controlledByName", std::make_unique<base::Value>(*this->controlled_by_name));

  }
  if (this->enforcement != ENFORCEMENT_NONE) {
    to_value_result->SetWithoutPathExpansion("enforcement", std::make_unique<base::Value>(settings_private::ToString(this->enforcement)));

  }
  if (this->recommended_value.get()) {
    to_value_result->SetWithoutPathExpansion("recommendedValue", (this->recommended_value)->CreateDeepCopy());

  }
  if (this->user_selectable_values.get()) {
    to_value_result->SetWithoutPathExpansion("userSelectableValues", json_schema_compiler::util::CreateValueFromOptionalArray(this->user_selectable_values));

  }
  if (this->user_control_disabled.get()) {
    to_value_result->SetWithoutPathExpansion("userControlDisabled", std::make_unique<base::Value>(*this->user_control_disabled));

  }
  if (this->extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(*this->extension_id));

  }
  if (this->extension_can_be_disabled.get()) {
    to_value_result->SetWithoutPathExpansion("extensionCanBeDisabled", std::make_unique<base::Value>(*this->extension_can_be_disabled));

  }

  return to_value_result;
}



//
// Functions
//

namespace SetPref {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* name_value = NULL;
  if (args.Get(0, &name_value) &&
      !name_value->is_none()) {
    {
      if (!name_value->GetAsString(&params->name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* value_value = NULL;
  if (args.Get(1, &value_value) &&
      !value_value->is_none()) {
    {
      params->value = value_value->CreateDeepCopy();
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* page_id_value = NULL;
  if (args.Get(2, &page_id_value) &&
      !page_id_value->is_none()) {
    {
      std::string temp;
      if (!page_id_value->GetAsString(&temp)) {
        params->page_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->page_id.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace SetPref

namespace GetAllPrefs {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<PrefObject>& prefs) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(prefs));

  return create_results;
}
}  // namespace GetAllPrefs

namespace GetPref {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* name_value = NULL;
  if (args.Get(0, &name_value) &&
      !name_value->is_none()) {
    {
      if (!name_value->GetAsString(&params->name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const PrefObject& pref) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((pref).ToValue());

  return create_results;
}
}  // namespace GetPref

namespace GetDefaultZoom {

std::unique_ptr<base::ListValue> Results::Create(double zoom) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(zoom));

  return create_results;
}
}  // namespace GetDefaultZoom

namespace SetDefaultZoom {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* zoom_value = NULL;
  if (args.Get(0, &zoom_value) &&
      !zoom_value->is_none()) {
    {
      if (!zoom_value->GetAsDouble(&params->zoom)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace SetDefaultZoom

//
// Events
//

namespace OnPrefsChanged {

const char kEventName[] = "settingsPrivate.onPrefsChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<PrefObject>& prefs) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(prefs));

  return create_results;
}

}  // namespace OnPrefsChanged

}  // namespace settings_private
}  // namespace api
}  // namespace extensions

