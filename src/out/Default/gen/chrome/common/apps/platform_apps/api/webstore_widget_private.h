// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/apps/platform_apps/api/webstore_widget_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_APPS_PLATFORM_APPS_API_WEBSTORE_WIDGET_PRIVATE_H__
#define CHROME_COMMON_APPS_PLATFORM_APPS_API_WEBSTORE_WIDGET_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace chrome_apps {
namespace api {
namespace webstore_widget_private {

//
// Functions
//

namespace InstallWebstoreItem {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string item_id;

  bool silent_installation;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace InstallWebstoreItem

}  // namespace webstore_widget_private
}  // namespace api
}  // namespace chrome_apps
#endif  // CHROME_COMMON_APPS_PLATFORM_APPS_API_WEBSTORE_WIDGET_PRIVATE_H__
