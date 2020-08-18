// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/apps/platform_apps/api/webstore_widget_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/apps/platform_apps/api/webstore_widget_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace chrome_apps {
namespace api {
namespace webstore_widget_private {
//
// Functions
//

namespace InstallWebstoreItem {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* item_id_value = NULL;
  if (args.Get(0, &item_id_value) &&
      !item_id_value->is_none()) {
    {
      if (!item_id_value->GetAsString(&params->item_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* silent_installation_value = NULL;
  if (args.Get(1, &silent_installation_value) &&
      !silent_installation_value->is_none()) {
    {
      if (!silent_installation_value->GetAsBoolean(&params->silent_installation)) {
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
}  // namespace InstallWebstoreItem

}  // namespace webstore_widget_private
}  // namespace api
}  // namespace chrome_apps

