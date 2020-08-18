// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/resources_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/resources_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace resources_private {
//
// Types
//

const char* ToString(Component enum_param) {
  switch (enum_param) {
    case COMPONENT_IDENTITY:
      return "identity";
    case COMPONENT_PDF:
      return "pdf";
    case COMPONENT_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Component ParseComponent(const std::string& enum_string) {
  if (enum_string == "identity")
    return COMPONENT_IDENTITY;
  if (enum_string == "pdf")
    return COMPONENT_PDF;
  return COMPONENT_NONE;
}



//
// Functions
//

namespace GetStrings {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* component_value = NULL;
  if (args.Get(0, &component_value) &&
      !component_value->is_none()) {
    {
      std::string component_as_string;
      if (!component_value->GetAsString(&component_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->component = ParseComponent(component_as_string);
      if (params->component == COMPONENT_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Result::Result()
 {}

Results::Result::~Result() {}
Results::Result::Result(Result&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Result& Results::Result::operator=(Result&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Result::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Result& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetStrings

}  // namespace resources_private
}  // namespace api
}  // namespace extensions

