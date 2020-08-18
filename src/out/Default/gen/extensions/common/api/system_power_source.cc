// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_power_source.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/system_power_source.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace system_power_source {
//
// Types
//

const char* ToString(PowerSourceType enum_param) {
  switch (enum_param) {
    case POWER_SOURCE_TYPE_UNKNOWN:
      return "unknown";
    case POWER_SOURCE_TYPE_MAINS:
      return "mains";
    case POWER_SOURCE_TYPE_USB:
      return "usb";
    case POWER_SOURCE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PowerSourceType ParsePowerSourceType(const std::string& enum_string) {
  if (enum_string == "unknown")
    return POWER_SOURCE_TYPE_UNKNOWN;
  if (enum_string == "mains")
    return POWER_SOURCE_TYPE_MAINS;
  if (enum_string == "usb")
    return POWER_SOURCE_TYPE_USB;
  return POWER_SOURCE_TYPE_NONE;
}


PowerSourceInfo::PowerSourceInfo()
: type(POWER_SOURCE_TYPE_NONE),
active(false) {}

PowerSourceInfo::~PowerSourceInfo() {}
PowerSourceInfo::PowerSourceInfo(PowerSourceInfo&& rhs)
: type(rhs.type),
max_power(std::move(rhs.max_power)),
active(rhs.active){
}

PowerSourceInfo& PowerSourceInfo::operator=(PowerSourceInfo&& rhs)
{
type = rhs.type;
max_power = std::move(rhs.max_power);
active = rhs.active;
return *this;
}

// static
bool PowerSourceInfo::Populate(
    const base::Value& value, PowerSourceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string power_source_type_as_string;
    if (!type_value->GetAsString(&power_source_type_as_string)) {
      return false;
    }
    out->type = ParsePowerSourceType(power_source_type_as_string);
    if (out->type == POWER_SOURCE_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* max_power_value = NULL;
  if (dict->GetWithoutPathExpansion("maxPower", &max_power_value)) {
    {
      double temp;
      if (!max_power_value->GetAsDouble(&temp)) {
        out->max_power.reset();
        return false;
      }
      else
        out->max_power.reset(new double(temp));
    }
  }

  const base::Value* active_value = NULL;
  if (!dict->GetWithoutPathExpansion("active", &active_value)) {
    return false;
  }
  {
    if (!active_value->GetAsBoolean(&out->active)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PowerSourceInfo> PowerSourceInfo::FromValue(const base::Value& value) {
  std::unique_ptr<PowerSourceInfo> out(new PowerSourceInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PowerSourceInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(system_power_source::ToString(this->type)));

  if (this->max_power.get()) {
    to_value_result->SetWithoutPathExpansion("maxPower", std::make_unique<base::Value>(*this->max_power));

  }
  to_value_result->SetWithoutPathExpansion("active", std::make_unique<base::Value>(this->active));


  return to_value_result;
}



//
// Functions
//

namespace GetPowerSourceInfo {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<PowerSourceInfo>& power_source_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(power_source_info));

  return create_results;
}
}  // namespace GetPowerSourceInfo

namespace RequestStatusUpdate {

}  // namespace RequestStatusUpdate

//
// Events
//

namespace OnPowerChanged {

const char kEventName[] = "system.powerSource.onPowerChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<PowerSourceInfo>& power_source_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(power_source_info));

  return create_results;
}

}  // namespace OnPowerChanged

}  // namespace system_power_source
}  // namespace api
}  // namespace extensions

