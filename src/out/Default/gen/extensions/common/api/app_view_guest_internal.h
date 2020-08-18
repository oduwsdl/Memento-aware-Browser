// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/app_view_guest_internal.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_APP_VIEW_GUEST_INTERNAL_H__
#define EXTENSIONS_COMMON_API_APP_VIEW_GUEST_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace app_view_guest_internal {

//
// Functions
//

namespace AttachFrame {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string url;

  int guest_instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int instance_id);
}  // namespace Results

}  // namespace AttachFrame

namespace DenyRequest {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int guest_instance_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace DenyRequest

}  // namespace app_view_guest_internal
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_APP_VIEW_GUEST_INTERNAL_H__
