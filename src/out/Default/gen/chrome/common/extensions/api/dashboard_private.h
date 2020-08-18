// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/dashboard_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_DASHBOARD_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_DASHBOARD_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace dashboard_private {

//
// Types
//

// Whether the API call succeeded, or the reason for failure.
enum Result {
  RESULT_NONE,
  RESULT_EMPTY_STRING,
  RESULT_UNKNOWN_ERROR,
  RESULT_USER_CANCELLED,
  RESULT_INVALID_ID,
  RESULT_MANIFEST_ERROR,
  RESULT_ICON_ERROR,
  RESULT_INVALID_ICON_URL,
  RESULT_LAST = RESULT_INVALID_ICON_URL,
};


const char* ToString(Result as_enum);
Result ParseResult(const std::string& as_string);


//
// Functions
//

namespace ShowPermissionPromptForDelegatedInstall {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Populates a Details object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Details* out);

    // The id of the extension to be installled.
    std::string id;

    // A string with the contents of the extension's manifest.json file. During the
    // install process, the browser will check that the downloaded extension's
    // manifest matches what was passed in here.
    std::string manifest;

    // The display name of the user for whom the extension should be installed.
    std::string delegated_user;

    std::unique_ptr<std::string> icon_url;

    // A string to use instead of the raw value of the 'name' key from
    // manifest.json.
    std::unique_ptr<std::string> localized_name;


   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  Details details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// A string result code, which will be empty upon success. The possible values
// in the case of errors include 'unknown_error', 'user_cancelled',
// 'manifest_error', 'icon_error', 'invalid_id', and 'invalid_icon_url'.
std::unique_ptr<base::ListValue> Create(const Result& result);
}  // namespace Results

}  // namespace ShowPermissionPromptForDelegatedInstall

}  // namespace dashboard_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_DASHBOARD_PRIVATE_H__
