// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/cryptotoken_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/cryptotoken_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace cryptotoken_private {
//
// Types
//

CanAppIdGetAttestationOptions::CanAppIdGetAttestationOptions()
: tab_id(0) {}

CanAppIdGetAttestationOptions::~CanAppIdGetAttestationOptions() {}
CanAppIdGetAttestationOptions::CanAppIdGetAttestationOptions(CanAppIdGetAttestationOptions&& rhs)
: app_id(std::move(rhs.app_id)),
origin(std::move(rhs.origin)),
tab_id(rhs.tab_id){
}

CanAppIdGetAttestationOptions& CanAppIdGetAttestationOptions::operator=(CanAppIdGetAttestationOptions&& rhs)
{
app_id = std::move(rhs.app_id);
origin = std::move(rhs.origin);
tab_id = rhs.tab_id;
return *this;
}

// static
bool CanAppIdGetAttestationOptions::Populate(
    const base::Value& value, CanAppIdGetAttestationOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* app_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("appId", &app_id_value)) {
    return false;
  }
  {
    if (!app_id_value->GetAsString(&out->app_id)) {
      return false;
    }
  }

  const base::Value* origin_value = NULL;
  if (!dict->GetWithoutPathExpansion("origin", &origin_value)) {
    return false;
  }
  {
    if (!origin_value->GetAsString(&out->origin)) {
      return false;
    }
  }

  const base::Value* tab_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    return false;
  }
  {
    if (!tab_id_value->GetAsInteger(&out->tab_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<CanAppIdGetAttestationOptions> CanAppIdGetAttestationOptions::FromValue(const base::Value& value) {
  std::unique_ptr<CanAppIdGetAttestationOptions> out(new CanAppIdGetAttestationOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CanAppIdGetAttestationOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("appId", std::make_unique<base::Value>(this->app_id));

  to_value_result->SetWithoutPathExpansion("origin", std::make_unique<base::Value>(this->origin));

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));


  return to_value_result;
}



//
// Functions
//

namespace CanOriginAssertAppId {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* security_origin_value = NULL;
  if (args.Get(0, &security_origin_value) &&
      !security_origin_value->is_none()) {
    {
      if (!security_origin_value->GetAsString(&params->security_origin)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* app_id_url_value = NULL;
  if (args.Get(1, &app_id_url_value) &&
      !app_id_url_value->is_none()) {
    {
      if (!app_id_url_value->GetAsString(&params->app_id_url)) {
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
}  // namespace CanOriginAssertAppId

namespace IsAppIdHashInEnterpriseContext {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_hash_value = NULL;
  if (args.Get(0, &app_id_hash_value) &&
      !app_id_hash_value->is_none()) {
    {
      if (!app_id_hash_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->app_id_hash = app_id_hash_value->GetBlob();
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
}  // namespace IsAppIdHashInEnterpriseContext

namespace CanAppIdGetAttestation {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CanAppIdGetAttestationOptions::Populate(*dictionary, &params->options)) {
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
}  // namespace CanAppIdGetAttestation

namespace RecordRegisterRequest {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      if (!tab_id_value->GetAsInteger(&params->tab_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* frame_id_value = NULL;
  if (args.Get(1, &frame_id_value) &&
      !frame_id_value->is_none()) {
    {
      if (!frame_id_value->GetAsInteger(&params->frame_id)) {
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
}  // namespace RecordRegisterRequest

namespace RecordSignRequest {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      if (!tab_id_value->GetAsInteger(&params->tab_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* frame_id_value = NULL;
  if (args.Get(1, &frame_id_value) &&
      !frame_id_value->is_none()) {
    {
      if (!frame_id_value->GetAsInteger(&params->frame_id)) {
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
}  // namespace RecordSignRequest

}  // namespace cryptotoken_private
}  // namespace api
}  // namespace extensions

