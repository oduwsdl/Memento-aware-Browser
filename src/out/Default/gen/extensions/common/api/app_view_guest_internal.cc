// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/app_view_guest_internal.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/app_view_guest_internal.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace app_view_guest_internal {
//
// Functions
//

namespace AttachFrame {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* url_value = NULL;
  if (args.Get(0, &url_value) &&
      !url_value->is_none()) {
    {
      if (!url_value->GetAsString(&params->url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* guest_instance_id_value = NULL;
  if (args.Get(1, &guest_instance_id_value) &&
      !guest_instance_id_value->is_none()) {
    {
      if (!guest_instance_id_value->GetAsInteger(&params->guest_instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int instance_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(instance_id));

  return create_results;
}
}  // namespace AttachFrame

namespace DenyRequest {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* guest_instance_id_value = NULL;
  if (args.Get(0, &guest_instance_id_value) &&
      !guest_instance_id_value->is_none()) {
    {
      if (!guest_instance_id_value->GetAsInteger(&params->guest_instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace DenyRequest

}  // namespace app_view_guest_internal
}  // namespace api
}  // namespace extensions

