// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/downloads_internal.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_DOWNLOADS_INTERNAL_H__
#define CHROME_COMMON_EXTENSIONS_API_DOWNLOADS_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace downloads_internal {

//
// Functions
//

namespace DetermineFilename {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int download_id;

  std::string filename;

  std::string conflict_action;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace DetermineFilename

}  // namespace downloads_internal
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_DOWNLOADS_INTERNAL_H__
