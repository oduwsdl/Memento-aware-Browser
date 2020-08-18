// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/enterprise_hardware_platform.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/enterprise_hardware_platform.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace enterprise_hardware_platform {
//
// Types
//

HardwarePlatformInfo::HardwarePlatformInfo()
 {}

HardwarePlatformInfo::~HardwarePlatformInfo() {}
HardwarePlatformInfo::HardwarePlatformInfo(HardwarePlatformInfo&& rhs)
: model(std::move(rhs.model)),
manufacturer(std::move(rhs.manufacturer)){
}

HardwarePlatformInfo& HardwarePlatformInfo::operator=(HardwarePlatformInfo&& rhs)
{
model = std::move(rhs.model);
manufacturer = std::move(rhs.manufacturer);
return *this;
}

// static
bool HardwarePlatformInfo::Populate(
    const base::Value& value, HardwarePlatformInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* model_value = NULL;
  if (!dict->GetWithoutPathExpansion("model", &model_value)) {
    return false;
  }
  {
    if (!model_value->GetAsString(&out->model)) {
      return false;
    }
  }

  const base::Value* manufacturer_value = NULL;
  if (!dict->GetWithoutPathExpansion("manufacturer", &manufacturer_value)) {
    return false;
  }
  {
    if (!manufacturer_value->GetAsString(&out->manufacturer)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<HardwarePlatformInfo> HardwarePlatformInfo::FromValue(const base::Value& value) {
  std::unique_ptr<HardwarePlatformInfo> out(new HardwarePlatformInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HardwarePlatformInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("model", std::make_unique<base::Value>(this->model));

  to_value_result->SetWithoutPathExpansion("manufacturer", std::make_unique<base::Value>(this->manufacturer));


  return to_value_result;
}



//
// Functions
//

namespace GetHardwarePlatformInfo {

std::unique_ptr<base::ListValue> Results::Create(const HardwarePlatformInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetHardwarePlatformInfo

}  // namespace enterprise_hardware_platform
}  // namespace api
}  // namespace extensions

