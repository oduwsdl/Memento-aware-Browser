// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/data_reduction_proxy.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_DATA_REDUCTION_PROXY_H__
#define CHROME_COMMON_EXTENSIONS_API_DATA_REDUCTION_PROXY_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace data_reduction_proxy {

//
// Functions
//

namespace ClearDataSavings {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ClearDataSavings

namespace GetDataUsage {

namespace Results {

// Data usage history.
struct Data_usage {
  Data_usage();
  ~Data_usage();
  Data_usage(Data_usage&& rhs);
  Data_usage& operator=(Data_usage&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Data_usage object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Data usage for the past 60 days broken down by time intervals. Each element
  // contains data usage for |kDataUsageBucketLengthMins| minutes.
  std::vector<std::unique_ptr<base::Value>> data_usage_buckets;


 private:
  DISALLOW_COPY_AND_ASSIGN(Data_usage);
};


// Data usage history.
std::unique_ptr<base::ListValue> Create(const Data_usage& data_usage);
}  // namespace Results

}  // namespace GetDataUsage

}  // namespace data_reduction_proxy
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_DATA_REDUCTION_PROXY_H__
