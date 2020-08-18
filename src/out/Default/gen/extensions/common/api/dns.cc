// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/dns.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/dns.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace dns {
//
// Types
//

ResolveCallbackResolveInfo::ResolveCallbackResolveInfo()
: result_code(0) {}

ResolveCallbackResolveInfo::~ResolveCallbackResolveInfo() {}
ResolveCallbackResolveInfo::ResolveCallbackResolveInfo(ResolveCallbackResolveInfo&& rhs)
: result_code(rhs.result_code),
address(std::move(rhs.address)){
}

ResolveCallbackResolveInfo& ResolveCallbackResolveInfo::operator=(ResolveCallbackResolveInfo&& rhs)
{
result_code = rhs.result_code;
address = std::move(rhs.address);
return *this;
}

// static
bool ResolveCallbackResolveInfo::Populate(
    const base::Value& value, ResolveCallbackResolveInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* result_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("resultCode", &result_code_value)) {
    return false;
  }
  {
    if (!result_code_value->GetAsInteger(&out->result_code)) {
      return false;
    }
  }

  const base::Value* address_value = NULL;
  if (dict->GetWithoutPathExpansion("address", &address_value)) {
    {
      std::string temp;
      if (!address_value->GetAsString(&temp)) {
        out->address.reset();
        return false;
      }
      else
        out->address.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ResolveCallbackResolveInfo> ResolveCallbackResolveInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ResolveCallbackResolveInfo> out(new ResolveCallbackResolveInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ResolveCallbackResolveInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("resultCode", std::make_unique<base::Value>(this->result_code));

  if (this->address.get()) {
    to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(*this->address));

  }

  return to_value_result;
}



//
// Functions
//

namespace Resolve {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* hostname_value = NULL;
  if (args.Get(0, &hostname_value) &&
      !hostname_value->is_none()) {
    {
      if (!hostname_value->GetAsString(&params->hostname)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ResolveCallbackResolveInfo& resolve_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((resolve_info).ToValue());

  return create_results;
}
}  // namespace Resolve

}  // namespace dns
}  // namespace api
}  // namespace extensions

