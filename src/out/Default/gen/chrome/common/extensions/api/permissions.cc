// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/permissions.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/permissions.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace permissions {
//
// Types
//

Permissions::Permissions()
 {}

Permissions::~Permissions() {}
Permissions::Permissions(Permissions&& rhs)
: permissions(std::move(rhs.permissions)),
origins(std::move(rhs.origins)){
}

Permissions& Permissions::operator=(Permissions&& rhs)
{
permissions = std::move(rhs.permissions);
origins = std::move(rhs.origins);
return *this;
}

// static
bool Permissions::Populate(
    const base::Value& value, Permissions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* permissions_value = NULL;
  if (dict->GetWithoutPathExpansion("permissions", &permissions_value)) {
    {
      const base::ListValue* list = NULL;
      if (!permissions_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->permissions)) {
          return false;
        }
      }
    }
  }

  const base::Value* origins_value = NULL;
  if (dict->GetWithoutPathExpansion("origins", &origins_value)) {
    {
      const base::ListValue* list = NULL;
      if (!origins_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->origins)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Permissions> Permissions::FromValue(const base::Value& value) {
  std::unique_ptr<Permissions> out(new Permissions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Permissions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->permissions.get()) {
    to_value_result->SetWithoutPathExpansion("permissions", json_schema_compiler::util::CreateValueFromOptionalArray(this->permissions));

  }
  if (this->origins.get()) {
    to_value_result->SetWithoutPathExpansion("origins", json_schema_compiler::util::CreateValueFromOptionalArray(this->origins));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetAll {

std::unique_ptr<base::ListValue> Results::Create(const Permissions& permissions) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((permissions).ToValue());

  return create_results;
}
}  // namespace GetAll

namespace Contains {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* permissions_value = NULL;
  if (args.Get(0, &permissions_value) &&
      !permissions_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!permissions_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Permissions::Populate(*dictionary, &params->permissions)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace Contains

namespace Request {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* permissions_value = NULL;
  if (args.Get(0, &permissions_value) &&
      !permissions_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!permissions_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Permissions::Populate(*dictionary, &params->permissions)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool granted) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(granted));

  return create_results;
}
}  // namespace Request

namespace Remove {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* permissions_value = NULL;
  if (args.Get(0, &permissions_value) &&
      !permissions_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!permissions_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Permissions::Populate(*dictionary, &params->permissions)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool removed) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(removed));

  return create_results;
}
}  // namespace Remove

//
// Events
//

namespace OnAdded {

const char kEventName[] = "permissions.onAdded";

std::unique_ptr<base::ListValue> Create(const Permissions& permissions) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((permissions).ToValue());

  return create_results;
}

}  // namespace OnAdded

namespace OnRemoved {

const char kEventName[] = "permissions.onRemoved";

std::unique_ptr<base::ListValue> Create(const Permissions& permissions) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((permissions).ToValue());

  return create_results;
}

}  // namespace OnRemoved

}  // namespace permissions
}  // namespace api
}  // namespace extensions

