// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_cpu.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/system_cpu.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace system_cpu {
//
// Types
//

CpuTime::CpuTime()
: user(0.0),
kernel(0.0),
idle(0.0),
total(0.0) {}

CpuTime::~CpuTime() {}
CpuTime::CpuTime(CpuTime&& rhs)
: user(rhs.user),
kernel(rhs.kernel),
idle(rhs.idle),
total(rhs.total){
}

CpuTime& CpuTime::operator=(CpuTime&& rhs)
{
user = rhs.user;
kernel = rhs.kernel;
idle = rhs.idle;
total = rhs.total;
return *this;
}

// static
bool CpuTime::Populate(
    const base::Value& value, CpuTime* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* user_value = NULL;
  if (!dict->GetWithoutPathExpansion("user", &user_value)) {
    return false;
  }
  {
    if (!user_value->GetAsDouble(&out->user)) {
      return false;
    }
  }

  const base::Value* kernel_value = NULL;
  if (!dict->GetWithoutPathExpansion("kernel", &kernel_value)) {
    return false;
  }
  {
    if (!kernel_value->GetAsDouble(&out->kernel)) {
      return false;
    }
  }

  const base::Value* idle_value = NULL;
  if (!dict->GetWithoutPathExpansion("idle", &idle_value)) {
    return false;
  }
  {
    if (!idle_value->GetAsDouble(&out->idle)) {
      return false;
    }
  }

  const base::Value* total_value = NULL;
  if (!dict->GetWithoutPathExpansion("total", &total_value)) {
    return false;
  }
  {
    if (!total_value->GetAsDouble(&out->total)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<CpuTime> CpuTime::FromValue(const base::Value& value) {
  std::unique_ptr<CpuTime> out(new CpuTime());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CpuTime::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("user", std::make_unique<base::Value>(this->user));

  to_value_result->SetWithoutPathExpansion("kernel", std::make_unique<base::Value>(this->kernel));

  to_value_result->SetWithoutPathExpansion("idle", std::make_unique<base::Value>(this->idle));

  to_value_result->SetWithoutPathExpansion("total", std::make_unique<base::Value>(this->total));


  return to_value_result;
}


ProcessorInfo::ProcessorInfo()
 {}

ProcessorInfo::~ProcessorInfo() {}
ProcessorInfo::ProcessorInfo(ProcessorInfo&& rhs)
: usage(std::move(rhs.usage)){
}

ProcessorInfo& ProcessorInfo::operator=(ProcessorInfo&& rhs)
{
usage = std::move(rhs.usage);
return *this;
}

// static
bool ProcessorInfo::Populate(
    const base::Value& value, ProcessorInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* usage_value = NULL;
  if (!dict->GetWithoutPathExpansion("usage", &usage_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!usage_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!CpuTime::Populate(*dictionary, &out->usage)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ProcessorInfo> ProcessorInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ProcessorInfo> out(new ProcessorInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ProcessorInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("usage", (this->usage).ToValue());


  return to_value_result;
}


CpuInfo::CpuInfo()
: num_of_processors(0) {}

CpuInfo::~CpuInfo() {}
CpuInfo::CpuInfo(CpuInfo&& rhs)
: num_of_processors(rhs.num_of_processors),
arch_name(std::move(rhs.arch_name)),
model_name(std::move(rhs.model_name)),
features(std::move(rhs.features)),
processors(std::move(rhs.processors)),
temperatures(std::move(rhs.temperatures)){
}

CpuInfo& CpuInfo::operator=(CpuInfo&& rhs)
{
num_of_processors = rhs.num_of_processors;
arch_name = std::move(rhs.arch_name);
model_name = std::move(rhs.model_name);
features = std::move(rhs.features);
processors = std::move(rhs.processors);
temperatures = std::move(rhs.temperatures);
return *this;
}

// static
bool CpuInfo::Populate(
    const base::Value& value, CpuInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* num_of_processors_value = NULL;
  if (!dict->GetWithoutPathExpansion("numOfProcessors", &num_of_processors_value)) {
    return false;
  }
  {
    if (!num_of_processors_value->GetAsInteger(&out->num_of_processors)) {
      return false;
    }
  }

  const base::Value* arch_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("archName", &arch_name_value)) {
    return false;
  }
  {
    if (!arch_name_value->GetAsString(&out->arch_name)) {
      return false;
    }
  }

  const base::Value* model_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("modelName", &model_name_value)) {
    return false;
  }
  {
    if (!model_name_value->GetAsString(&out->model_name)) {
      return false;
    }
  }

  const base::Value* features_value = NULL;
  if (!dict->GetWithoutPathExpansion("features", &features_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!features_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->features)) {
        return false;
      }
    }
  }

  const base::Value* processors_value = NULL;
  if (!dict->GetWithoutPathExpansion("processors", &processors_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!processors_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->processors)) {
        return false;
      }
    }
  }

  const base::Value* temperatures_value = NULL;
  if (!dict->GetWithoutPathExpansion("temperatures", &temperatures_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!temperatures_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->temperatures)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<CpuInfo> CpuInfo::FromValue(const base::Value& value) {
  std::unique_ptr<CpuInfo> out(new CpuInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CpuInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("numOfProcessors", std::make_unique<base::Value>(this->num_of_processors));

  to_value_result->SetWithoutPathExpansion("archName", std::make_unique<base::Value>(this->arch_name));

  to_value_result->SetWithoutPathExpansion("modelName", std::make_unique<base::Value>(this->model_name));

  to_value_result->SetWithoutPathExpansion("features", json_schema_compiler::util::CreateValueFromArray(this->features));

  to_value_result->SetWithoutPathExpansion("processors", json_schema_compiler::util::CreateValueFromArray(this->processors));

  to_value_result->SetWithoutPathExpansion("temperatures", json_schema_compiler::util::CreateValueFromArray(this->temperatures));


  return to_value_result;
}



//
// Functions
//

namespace GetInfo {

std::unique_ptr<base::ListValue> Results::Create(const CpuInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetInfo

}  // namespace system_cpu
}  // namespace api
}  // namespace extensions

