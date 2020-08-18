// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/identity_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_IDENTITY_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_IDENTITY_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace identity_private {

//
// Functions
//

namespace SetConsentResult {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string result;

  std::string window_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetConsentResult

//
// Events
//

namespace OnWebFlowRequest {

extern const char kEventName[];  // "identityPrivate.onWebFlowRequest"

// A unique identifier that the caller can use to locate the dialog window.
// A URL that will be loaded in the webview.
// 'interactive' or 'silent'. The window will be displayed if the mode is
// 'interactive'.
// A name used for the webview partition.
std::unique_ptr<base::ListValue> Create(const std::string& key, const std::string& url, const std::string& mode, const std::string& partition);
}  // namespace OnWebFlowRequest

}  // namespace identity_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_IDENTITY_PRIVATE_H__
