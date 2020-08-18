// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/mdns.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/mdns.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace mdns {
//
// Properties
//

const int MAX_SERVICE_INSTANCES_PER_EVENT = 2048;

//
// Types
//

MDnsService::MDnsService()
 {}

MDnsService::~MDnsService() {}
MDnsService::MDnsService(MDnsService&& rhs)
: service_name(std::move(rhs.service_name)),
service_host_port(std::move(rhs.service_host_port)),
ip_address(std::move(rhs.ip_address)),
service_data(std::move(rhs.service_data)){
}

MDnsService& MDnsService::operator=(MDnsService&& rhs)
{
service_name = std::move(rhs.service_name);
service_host_port = std::move(rhs.service_host_port);
ip_address = std::move(rhs.ip_address);
service_data = std::move(rhs.service_data);
return *this;
}

// static
bool MDnsService::Populate(
    const base::Value& value, MDnsService* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* service_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("serviceName", &service_name_value)) {
    return false;
  }
  {
    if (!service_name_value->GetAsString(&out->service_name)) {
      return false;
    }
  }

  const base::Value* service_host_port_value = NULL;
  if (!dict->GetWithoutPathExpansion("serviceHostPort", &service_host_port_value)) {
    return false;
  }
  {
    if (!service_host_port_value->GetAsString(&out->service_host_port)) {
      return false;
    }
  }

  const base::Value* ip_address_value = NULL;
  if (!dict->GetWithoutPathExpansion("ipAddress", &ip_address_value)) {
    return false;
  }
  {
    if (!ip_address_value->GetAsString(&out->ip_address)) {
      return false;
    }
  }

  const base::Value* service_data_value = NULL;
  if (!dict->GetWithoutPathExpansion("serviceData", &service_data_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!service_data_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->service_data)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<MDnsService> MDnsService::FromValue(const base::Value& value) {
  std::unique_ptr<MDnsService> out(new MDnsService());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MDnsService::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("serviceName", std::make_unique<base::Value>(this->service_name));

  to_value_result->SetWithoutPathExpansion("serviceHostPort", std::make_unique<base::Value>(this->service_host_port));

  to_value_result->SetWithoutPathExpansion("ipAddress", std::make_unique<base::Value>(this->ip_address));

  to_value_result->SetWithoutPathExpansion("serviceData", json_schema_compiler::util::CreateValueFromArray(this->service_data));


  return to_value_result;
}



//
// Functions
//

namespace ForceDiscovery {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ForceDiscovery

//
// Events
//

namespace OnServiceList {

const char kEventName[] = "mdns.onServiceList";

std::unique_ptr<base::ListValue> Create(const std::vector<MDnsService>& services) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(services));

  return create_results;
}

}  // namespace OnServiceList

}  // namespace mdns
}  // namespace api
}  // namespace extensions

