// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/downloads_internal.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/downloads_internal.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace downloads_internal {
//
// Functions
//

namespace DetermineFilename {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* filename_value = NULL;
  if (args.Get(1, &filename_value) &&
      !filename_value->is_none()) {
    {
      if (!filename_value->GetAsString(&params->filename)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* conflict_action_value = NULL;
  if (args.Get(2, &conflict_action_value) &&
      !conflict_action_value->is_none()) {
    {
      if (!conflict_action_value->GetAsString(&params->conflict_action)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace DetermineFilename

}  // namespace downloads_internal
}  // namespace api
}  // namespace extensions

