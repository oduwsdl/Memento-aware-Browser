// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/data_reduction_proxy.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/data_reduction_proxy.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace data_reduction_proxy {
//
// Functions
//

namespace ClearDataSavings {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ClearDataSavings

namespace GetDataUsage {

Results::Data_usage::Data_usage()
 {}

Results::Data_usage::~Data_usage() {}
Results::Data_usage::Data_usage(Data_usage&& rhs)
: data_usage_buckets(std::move(rhs.data_usage_buckets)){
}

Results::Data_usage& Results::Data_usage::operator=(Data_usage&& rhs)
{
data_usage_buckets = std::move(rhs.data_usage_buckets);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Data_usage::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("data_usage_buckets", json_schema_compiler::util::CreateValueFromArray(this->data_usage_buckets));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Data_usage& data_usage) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((data_usage).ToValue());

  return create_results;
}
}  // namespace GetDataUsage

}  // namespace data_reduction_proxy
}  // namespace api
}  // namespace extensions

