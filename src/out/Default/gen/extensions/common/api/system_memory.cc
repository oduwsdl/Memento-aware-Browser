// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_memory.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/system_memory.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace system_memory {
//
// Types
//

MemoryInfo::MemoryInfo()
: capacity(0.0),
available_capacity(0.0) {}

MemoryInfo::~MemoryInfo() {}
MemoryInfo::MemoryInfo(MemoryInfo&& rhs)
: capacity(rhs.capacity),
available_capacity(rhs.available_capacity){
}

MemoryInfo& MemoryInfo::operator=(MemoryInfo&& rhs)
{
capacity = rhs.capacity;
available_capacity = rhs.available_capacity;
return *this;
}

// static
bool MemoryInfo::Populate(
    const base::Value& value, MemoryInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* capacity_value = NULL;
  if (!dict->GetWithoutPathExpansion("capacity", &capacity_value)) {
    return false;
  }
  {
    if (!capacity_value->GetAsDouble(&out->capacity)) {
      return false;
    }
  }

  const base::Value* available_capacity_value = NULL;
  if (!dict->GetWithoutPathExpansion("availableCapacity", &available_capacity_value)) {
    return false;
  }
  {
    if (!available_capacity_value->GetAsDouble(&out->available_capacity)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<MemoryInfo> MemoryInfo::FromValue(const base::Value& value) {
  std::unique_ptr<MemoryInfo> out(new MemoryInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MemoryInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("capacity", std::make_unique<base::Value>(this->capacity));

  to_value_result->SetWithoutPathExpansion("availableCapacity", std::make_unique<base::Value>(this->available_capacity));


  return to_value_result;
}



//
// Functions
//

namespace GetInfo {

std::unique_ptr<base::ListValue> Results::Create(const MemoryInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetInfo

}  // namespace system_memory
}  // namespace api
}  // namespace extensions

