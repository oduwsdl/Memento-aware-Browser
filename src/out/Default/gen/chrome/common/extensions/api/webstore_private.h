// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/webstore_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_WEBSTORE_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_WEBSTORE_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace webstore_private {

//
// Types
//

// Whether the API call succeeded, or the reason for failure.
enum Result {
  RESULT_NONE,
  RESULT_EMPTY_STRING,
  RESULT_SUCCESS,
  RESULT_USER_GESTURE_REQUIRED,
  RESULT_UNKNOWN_ERROR,
  RESULT_FEATURE_DISABLED,
  RESULT_UNSUPPORTED_EXTENSION_TYPE,
  RESULT_MISSING_DEPENDENCIES,
  RESULT_INSTALL_ERROR,
  RESULT_USER_CANCELLED,
  RESULT_INVALID_ID,
  RESULT_BLACKLISTED,
  RESULT_BLOCKED_BY_POLICY,
  RESULT_INSTALL_IN_PROGRESS,
  RESULT_LAUNCH_IN_PROGRESS,
  RESULT_MANIFEST_ERROR,
  RESULT_ICON_ERROR,
  RESULT_INVALID_ICON_URL,
  RESULT_ALREADY_INSTALLED,
  RESULT_BLOCKED_FOR_CHILD_ACCOUNT,
  RESULT_LAST = RESULT_BLOCKED_FOR_CHILD_ACCOUNT,
};


const char* ToString(Result as_enum);
Result ParseResult(const std::string& as_string);

enum WebGlStatus {
  WEB_GL_STATUS_NONE,
  WEB_GL_STATUS_WEBGL_ALLOWED,
  WEB_GL_STATUS_WEBGL_BLOCKED,
  WEB_GL_STATUS_LAST = WEB_GL_STATUS_WEBGL_BLOCKED,
};


const char* ToString(WebGlStatus as_enum);
WebGlStatus ParseWebGlStatus(const std::string& as_string);

enum ExtensionInstallStatus {
  EXTENSION_INSTALL_STATUS_NONE,
  EXTENSION_INSTALL_STATUS_CAN_REQUEST,
  EXTENSION_INSTALL_STATUS_REQUEST_PENDING,
  EXTENSION_INSTALL_STATUS_BLOCKED_BY_POLICY,
  EXTENSION_INSTALL_STATUS_INSTALLABLE,
  EXTENSION_INSTALL_STATUS_ENABLED,
  EXTENSION_INSTALL_STATUS_DISABLED,
  EXTENSION_INSTALL_STATUS_TERMINATED,
  EXTENSION_INSTALL_STATUS_BLACKLISTED,
  EXTENSION_INSTALL_STATUS_CUSTODIAN_APPROVAL_REQUIRED,
  EXTENSION_INSTALL_STATUS_FORCE_INSTALLED,
  EXTENSION_INSTALL_STATUS_LAST = EXTENSION_INSTALL_STATUS_FORCE_INSTALLED,
};


const char* ToString(ExtensionInstallStatus as_enum);
ExtensionInstallStatus ParseExtensionInstallStatus(const std::string& as_string);


//
// Functions
//

namespace BeginInstallWithManifest3 {

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

    // The id of the extension to be installed.
    std::string id;

    // A string with the contents of the extension's manifest.json file. During the
    // install process, the browser will check that the downloaded extension's
    // manifest matches what was passed in here.
    std::string manifest;

    std::unique_ptr<std::string> icon_url;

    // A string to use instead of the raw value of the 'name' key from
    // manifest.json.
    std::unique_ptr<std::string> localized_name;

    // The name of the locale used for generating localizedName. This should be the
    // name of one of the directories in the _locales folder of the extension, or
    // the default_locale setting from the manifest.
    std::unique_ptr<std::string> locale;

    // A flag to change the UI we show when an app is installed - a value of true
    // means to show a bubble pointing at the new tab button (instead of the default
    // behavior of opening the new tab page and animating the app icon).
    std::unique_ptr<bool> app_install_bubble;

    // A flag to cause the app launcher to be installed before installing the
    // extension, if it isn't installed already.
    std::unique_ptr<bool> enable_launcher;

    // The authuser index to be included with CRX download requests in multi-login
    // sessions.
    std::unique_ptr<std::string> authuser;

    base::DictionaryValue additional_properties;

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
// 'manifest_error', 'icon_error', 'invalid_id', 'permission_denied',
// 'invalid_icon_url' and 'already_installed'.
std::unique_ptr<base::ListValue> Create(const Result& result);
}  // namespace Results

}  // namespace BeginInstallWithManifest3

namespace CompleteInstall {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to be installed. This should match a previous call to
  // beginInstallWithManifest3.
  std::string expected_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace CompleteInstall

namespace EnableAppLauncher {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace EnableAppLauncher

namespace GetBrowserLogin {

namespace Results {

struct Info {
  Info();
  ~Info();
  Info(Info&& rhs);
  Info& operator=(Info&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Info object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string login;


 private:
  DISALLOW_COPY_AND_ASSIGN(Info);
};


std::unique_ptr<base::ListValue> Create(const Info& info);
}  // namespace Results

}  // namespace GetBrowserLogin

namespace GetStoreLogin {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& login);
}  // namespace Results

}  // namespace GetStoreLogin

namespace SetStoreLogin {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string login;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetStoreLogin

namespace GetWebGLStatus {

namespace Results {

std::unique_ptr<base::ListValue> Create(const WebGlStatus& webgl_status);
}  // namespace Results

}  // namespace GetWebGLStatus

namespace GetIsLauncherEnabled {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool is_enabled);
}  // namespace Results

}  // namespace GetIsLauncherEnabled

namespace IsInIncognitoMode {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool is_incognito);
}  // namespace Results

}  // namespace IsInIncognitoMode

namespace GetEphemeralAppsEnabled {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool is_enabled);
}  // namespace Results

}  // namespace GetEphemeralAppsEnabled

namespace LaunchEphemeralApp {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The extension id of the app to launch.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Whether an attempt to launch an app succeeded, or the reason for failure.
std::unique_ptr<base::ListValue> Create(const Result& result);
}  // namespace Results

}  // namespace LaunchEphemeralApp

namespace IsPendingCustodianApproval {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The extension id of the extension to be checked.
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool is_pending_approval);
}  // namespace Results

}  // namespace IsPendingCustodianApproval

namespace GetReferrerChain {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& referrer_chain);
}  // namespace Results

}  // namespace GetReferrerChain

namespace GetExtensionStatus {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension
  std::string id;

  // The manifest of the extension
  std::unique_ptr<std::string> manifest;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ExtensionInstallStatus& status);
}  // namespace Results

}  // namespace GetExtensionStatus

namespace RequestExtension {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the extension to be requested. The webstore should call this after
  // a call to getExtensionStatus
  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ExtensionInstallStatus& status);
}  // namespace Results

}  // namespace RequestExtension

}  // namespace webstore_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_WEBSTORE_PRIVATE_H__
