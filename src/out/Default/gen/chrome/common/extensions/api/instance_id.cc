// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/instance_id.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/instance_id.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace instance_id {
//
// Functions
//

namespace GetID {

std::unique_ptr<base::ListValue> Results::Create(const std::string& instance_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(instance_id));

  return create_results;
}
}  // namespace GetID

namespace GetCreationTime {

std::unique_ptr<base::ListValue> Results::Create(double creation_time) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(creation_time));

  return create_results;
}
}  // namespace GetCreationTime

namespace GetToken {

Params::GetTokenParams::Options::Options()
 {}

Params::GetTokenParams::Options::~Options() {}
Params::GetTokenParams::Options::Options(Options&& rhs)
: additional_properties(std::move(rhs.additional_properties)){
}

Params::GetTokenParams::Options& Params::GetTokenParams::Options::operator=(Options&& rhs)
{
additional_properties = std::move(rhs.additional_properties);
return *this;
}

// static
bool Params::GetTokenParams::Options::Populate(
    const base::Value& value, Options* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  for (base::DictionaryValue::Iterator it(*dict);
       !it.IsAtEnd(); it.Advance()) {
    std::string tmp;
    {
      if (!(&it.value())->GetAsString(&tmp)) {
        return false;
      }
    }
    out->additional_properties[it.key()] = tmp;
  }
  return true;
}



Params::GetTokenParams::GetTokenParams()
 {}

Params::GetTokenParams::~GetTokenParams() {}
Params::GetTokenParams::GetTokenParams(GetTokenParams&& rhs)
: authorized_entity(std::move(rhs.authorized_entity)),
scope(std::move(rhs.scope)),
options(std::move(rhs.options)){
}

Params::GetTokenParams& Params::GetTokenParams::operator=(GetTokenParams&& rhs)
{
authorized_entity = std::move(rhs.authorized_entity);
scope = std::move(rhs.scope);
options = std::move(rhs.options);
return *this;
}

// static
bool Params::GetTokenParams::Populate(
    const base::Value& value, GetTokenParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* authorized_entity_value = NULL;
  if (!dict->GetWithoutPathExpansion("authorizedEntity", &authorized_entity_value)) {
    return false;
  }
  {
    if (!authorized_entity_value->GetAsString(&out->authorized_entity)) {
      return false;
    }
  }

  const base::Value* scope_value = NULL;
  if (!dict->GetWithoutPathExpansion("scope", &scope_value)) {
    return false;
  }
  {
    if (!scope_value->GetAsString(&out->scope)) {
      return false;
    }
  }

  const base::Value* options_value = NULL;
  if (dict->GetWithoutPathExpansion("options", &options_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Options> temp(new Options());
        if (!Options::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->options = std::move(temp);
      }
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* get_token_params_value = NULL;
  if (args.Get(0, &get_token_params_value) &&
      !get_token_params_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!get_token_params_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!GetTokenParams::Populate(*dictionary, &params->get_token_params)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& token) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(token));

  return create_results;
}
}  // namespace GetToken

namespace DeleteToken {

Params::DeleteTokenParams::DeleteTokenParams()
 {}

Params::DeleteTokenParams::~DeleteTokenParams() {}
Params::DeleteTokenParams::DeleteTokenParams(DeleteTokenParams&& rhs)
: authorized_entity(std::move(rhs.authorized_entity)),
scope(std::move(rhs.scope)){
}

Params::DeleteTokenParams& Params::DeleteTokenParams::operator=(DeleteTokenParams&& rhs)
{
authorized_entity = std::move(rhs.authorized_entity);
scope = std::move(rhs.scope);
return *this;
}

// static
bool Params::DeleteTokenParams::Populate(
    const base::Value& value, DeleteTokenParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* authorized_entity_value = NULL;
  if (!dict->GetWithoutPathExpansion("authorizedEntity", &authorized_entity_value)) {
    return false;
  }
  {
    if (!authorized_entity_value->GetAsString(&out->authorized_entity)) {
      return false;
    }
  }

  const base::Value* scope_value = NULL;
  if (!dict->GetWithoutPathExpansion("scope", &scope_value)) {
    return false;
  }
  {
    if (!scope_value->GetAsString(&out->scope)) {
      return false;
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* delete_token_params_value = NULL;
  if (args.Get(0, &delete_token_params_value) &&
      !delete_token_params_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!delete_token_params_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DeleteTokenParams::Populate(*dictionary, &params->delete_token_params)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace DeleteToken

namespace DeleteID {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace DeleteID

//
// Events
//

namespace OnTokenRefresh {

const char kEventName[] = "instanceID.onTokenRefresh";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnTokenRefresh

}  // namespace instance_id
}  // namespace api
}  // namespace extensions

