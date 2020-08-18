// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/identity_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/identity_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace identity_private {
//
// Functions
//

namespace SetConsentResult {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* result_value = NULL;
  if (args.Get(0, &result_value) &&
      !result_value->is_none()) {
    {
      if (!result_value->GetAsString(&params->result)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* window_id_value = NULL;
  if (args.Get(1, &window_id_value) &&
      !window_id_value->is_none()) {
    {
      if (!window_id_value->GetAsString(&params->window_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetConsentResult

//
// Events
//

namespace OnWebFlowRequest {

const char kEventName[] = "identityPrivate.onWebFlowRequest";

std::unique_ptr<base::ListValue> Create(const std::string& key, const std::string& url, const std::string& mode, const std::string& partition) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(key));

  create_results->Append(std::make_unique<base::Value>(url));

  create_results->Append(std::make_unique<base::Value>(mode));

  create_results->Append(std::make_unique<base::Value>(partition));

  return create_results;
}

}  // namespace OnWebFlowRequest

}  // namespace identity_private
}  // namespace api
}  // namespace extensions

