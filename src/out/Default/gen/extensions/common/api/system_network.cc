// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_network.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/system_network.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace system_network {
//
// Types
//

NetworkInterface::NetworkInterface()
: prefix_length(0) {}

NetworkInterface::~NetworkInterface() {}
NetworkInterface::NetworkInterface(NetworkInterface&& rhs)
: name(std::move(rhs.name)),
address(std::move(rhs.address)),
prefix_length(rhs.prefix_length){
}

NetworkInterface& NetworkInterface::operator=(NetworkInterface&& rhs)
{
name = std::move(rhs.name);
address = std::move(rhs.address);
prefix_length = rhs.prefix_length;
return *this;
}

// static
bool NetworkInterface::Populate(
    const base::Value& value, NetworkInterface* out) {
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

  const base::Value* address_value = NULL;
  if (!dict->GetWithoutPathExpansion("address", &address_value)) {
    return false;
  }
  {
    if (!address_value->GetAsString(&out->address)) {
      return false;
    }
  }

  const base::Value* prefix_length_value = NULL;
  if (!dict->GetWithoutPathExpansion("prefixLength", &prefix_length_value)) {
    return false;
  }
  {
    if (!prefix_length_value->GetAsInteger(&out->prefix_length)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<NetworkInterface> NetworkInterface::FromValue(const base::Value& value) {
  std::unique_ptr<NetworkInterface> out(new NetworkInterface());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NetworkInterface::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("address", std::make_unique<base::Value>(this->address));

  to_value_result->SetWithoutPathExpansion("prefixLength", std::make_unique<base::Value>(this->prefix_length));


  return to_value_result;
}



//
// Functions
//

namespace GetNetworkInterfaces {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<NetworkInterface>& network_interfaces) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(network_interfaces));

  return create_results;
}
}  // namespace GetNetworkInterfaces

}  // namespace system_network
}  // namespace api
}  // namespace extensions

