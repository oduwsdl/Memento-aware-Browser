// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/cloud_print_private.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/cloud_print_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace cloud_print_private {
//
// Types
//

PrinterSettings::PrinterSettings()
: connect(false) {}

PrinterSettings::~PrinterSettings() {}
PrinterSettings::PrinterSettings(PrinterSettings&& rhs)
: name(std::move(rhs.name)),
connect(rhs.connect){
}

PrinterSettings& PrinterSettings::operator=(PrinterSettings&& rhs)
{
name = std::move(rhs.name);
connect = rhs.connect;
return *this;
}

// static
bool PrinterSettings::Populate(
    const base::Value& value, PrinterSettings* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* connect_value = NULL;
  if (!dict->GetWithoutPathExpansion("connect", &connect_value)) {
    return false;
  }
  {
    if (!connect_value->GetAsBoolean(&out->connect)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PrinterSettings> PrinterSettings::FromValue(const base::Value& value) {
  std::unique_ptr<PrinterSettings> out(new PrinterSettings());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PrinterSettings::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("connect", std::make_unique<base::Value>(this->connect));


  return to_value_result;
}


UserSettings::UserSettings()
: connect_new_printers(false) {}

UserSettings::~UserSettings() {}
UserSettings::UserSettings(UserSettings&& rhs)
: printers(std::move(rhs.printers)),
connect_new_printers(rhs.connect_new_printers){
}

UserSettings& UserSettings::operator=(UserSettings&& rhs)
{
printers = std::move(rhs.printers);
connect_new_printers = rhs.connect_new_printers;
return *this;
}

// static
bool UserSettings::Populate(
    const base::Value& value, UserSettings* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* printers_value = NULL;
  if (!dict->GetWithoutPathExpansion("printers", &printers_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!printers_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->printers)) {
        return false;
      }
    }
  }

  const base::Value* connect_new_printers_value = NULL;
  if (!dict->GetWithoutPathExpansion("connectNewPrinters", &connect_new_printers_value)) {
    return false;
  }
  {
    if (!connect_new_printers_value->GetAsBoolean(&out->connect_new_printers)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<UserSettings> UserSettings::FromValue(const base::Value& value) {
  std::unique_ptr<UserSettings> out(new UserSettings());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> UserSettings::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("printers", json_schema_compiler::util::CreateValueFromArray(this->printers));

  to_value_result->SetWithoutPathExpansion("connectNewPrinters", std::make_unique<base::Value>(this->connect_new_printers));


  return to_value_result;
}



//
// Functions
//

namespace SetupConnector {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 4) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* user_email_value = NULL;
  if (args.Get(0, &user_email_value) &&
      !user_email_value->is_none()) {
    {
      if (!user_email_value->GetAsString(&params->user_email)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* robot_email_value = NULL;
  if (args.Get(1, &robot_email_value) &&
      !robot_email_value->is_none()) {
    {
      if (!robot_email_value->GetAsString(&params->robot_email)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* credentials_value = NULL;
  if (args.Get(2, &credentials_value) &&
      !credentials_value->is_none()) {
    {
      if (!credentials_value->GetAsString(&params->credentials)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* user_settings_value = NULL;
  if (args.Get(3, &user_settings_value) &&
      !user_settings_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!user_settings_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!UserSettings::Populate(*dictionary, &params->user_settings)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetupConnector

namespace GetHostName {

std::unique_ptr<base::ListValue> Results::Create(const std::string& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace GetHostName

namespace GetPrinters {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetPrinters

namespace GetClientId {

std::unique_ptr<base::ListValue> Results::Create(const std::string& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace GetClientId

}  // namespace cloud_print_private
}  // namespace api
}  // namespace extensions

