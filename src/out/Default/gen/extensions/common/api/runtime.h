// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/runtime.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_RUNTIME_H__
#define EXTENSIONS_COMMON_API_RUNTIME_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace runtime {

//
// Properties
//

//
// Types
//

// The operating system chrome is running on.
enum PlatformOs {
  PLATFORM_OS_NONE,
  PLATFORM_OS_MAC,
  PLATFORM_OS_WIN,
  PLATFORM_OS_ANDROID,
  PLATFORM_OS_CROS,
  PLATFORM_OS_LINUX,
  PLATFORM_OS_OPENBSD,
  PLATFORM_OS_LAST = PLATFORM_OS_OPENBSD,
};


const char* ToString(PlatformOs as_enum);
PlatformOs ParsePlatformOs(const std::string& as_string);

// The machine's processor architecture.
enum PlatformArch {
  PLATFORM_ARCH_NONE,
  PLATFORM_ARCH_ARM,
  PLATFORM_ARCH_ARM64,
  PLATFORM_ARCH_X86_32,
  PLATFORM_ARCH_X86_64,
  PLATFORM_ARCH_MIPS,
  PLATFORM_ARCH_MIPS64,
  PLATFORM_ARCH_LAST = PLATFORM_ARCH_MIPS64,
};


const char* ToString(PlatformArch as_enum);
PlatformArch ParsePlatformArch(const std::string& as_string);

// The native client architecture. This may be different from arch on some
// platforms.
enum PlatformNaclArch {
  PLATFORM_NACL_ARCH_NONE,
  PLATFORM_NACL_ARCH_ARM,
  PLATFORM_NACL_ARCH_X86_32,
  PLATFORM_NACL_ARCH_X86_64,
  PLATFORM_NACL_ARCH_MIPS,
  PLATFORM_NACL_ARCH_MIPS64,
  PLATFORM_NACL_ARCH_LAST = PLATFORM_NACL_ARCH_MIPS64,
};


const char* ToString(PlatformNaclArch as_enum);
PlatformNaclArch ParsePlatformNaclArch(const std::string& as_string);

// An object containing information about the current platform.
struct PlatformInfo {
  PlatformInfo();
  ~PlatformInfo();
  PlatformInfo(PlatformInfo&& rhs);
  PlatformInfo& operator=(PlatformInfo&& rhs);

  // Populates a PlatformInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, PlatformInfo* out);

  // Creates a PlatformInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<PlatformInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PlatformInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The operating system chrome is running on.
  PlatformOs os;

  // The machine's processor architecture.
  PlatformArch arch;

  // The native client architecture. This may be different from arch on some
  // platforms.
  PlatformNaclArch nacl_arch;


 private:
  DISALLOW_COPY_AND_ASSIGN(PlatformInfo);
};

// Result of the update check.
enum RequestUpdateCheckStatus {
  REQUEST_UPDATE_CHECK_STATUS_NONE,
  REQUEST_UPDATE_CHECK_STATUS_THROTTLED,
  REQUEST_UPDATE_CHECK_STATUS_NO_UPDATE,
  REQUEST_UPDATE_CHECK_STATUS_UPDATE_AVAILABLE,
  REQUEST_UPDATE_CHECK_STATUS_LAST = REQUEST_UPDATE_CHECK_STATUS_UPDATE_AVAILABLE,
};


const char* ToString(RequestUpdateCheckStatus as_enum);
RequestUpdateCheckStatus ParseRequestUpdateCheckStatus(const std::string& as_string);

// The reason that this event is being dispatched.
enum OnInstalledReason {
  ON_INSTALLED_REASON_NONE,
  ON_INSTALLED_REASON_INSTALL,
  ON_INSTALLED_REASON_UPDATE,
  ON_INSTALLED_REASON_CHROME_UPDATE,
  ON_INSTALLED_REASON_SHARED_MODULE_UPDATE,
  ON_INSTALLED_REASON_LAST = ON_INSTALLED_REASON_SHARED_MODULE_UPDATE,
};


const char* ToString(OnInstalledReason as_enum);
OnInstalledReason ParseOnInstalledReason(const std::string& as_string);

// The reason that the event is being dispatched. 'app_update' is used when the
// restart is needed because the application is updated to a newer version.
// 'os_update' is used when the restart is needed because the browser/OS is
// updated to a newer version. 'periodic' is used when the system runs for more
// than the permitted uptime set in the enterprise policy.
enum OnRestartRequiredReason {
  ON_RESTART_REQUIRED_REASON_NONE,
  ON_RESTART_REQUIRED_REASON_APP_UPDATE,
  ON_RESTART_REQUIRED_REASON_OS_UPDATE,
  ON_RESTART_REQUIRED_REASON_PERIODIC,
  ON_RESTART_REQUIRED_REASON_LAST = ON_RESTART_REQUIRED_REASON_PERIODIC,
};


const char* ToString(OnRestartRequiredReason as_enum);
OnRestartRequiredReason ParseOnRestartRequiredReason(const std::string& as_string);


//
// Functions
//

namespace GetBackgroundPage {

namespace Results {

// The JavaScript 'window' object for the background page.
struct BackgroundPage {
  BackgroundPage();
  ~BackgroundPage();
  BackgroundPage(BackgroundPage&& rhs);
  BackgroundPage& operator=(BackgroundPage&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this BackgroundPage object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(BackgroundPage);
};


// The JavaScript 'window' object for the background page.
std::unique_ptr<base::ListValue> Create(const BackgroundPage& background_page);
}  // namespace Results

}  // namespace GetBackgroundPage

namespace OpenOptionsPage {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace OpenOptionsPage

namespace SetUninstallURL {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // URL to be opened after the extension is uninstalled. This URL must have an
  // http: or https: scheme. Set an empty string to not open a new tab upon
  // uninstallation.
  std::string url;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetUninstallURL

namespace Reload {

}  // namespace Reload

namespace RequestUpdateCheck {

namespace Results {

// If an update is available, this contains more information about the available
// update.
struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The version of the available update.
  std::string version;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


// Result of the update check.
// If an update is available, this contains more information about the available
// update.
std::unique_ptr<base::ListValue> Create(const RequestUpdateCheckStatus& status, const Details& details);
}  // namespace Results

}  // namespace RequestUpdateCheck

namespace Restart {

}  // namespace Restart

namespace RestartAfterDelay {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Time to wait in seconds before rebooting the device, or -1 to cancel a
  // scheduled reboot.
  int seconds;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RestartAfterDelay

namespace GetPlatformInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const PlatformInfo& platform_info);
}  // namespace Results

}  // namespace GetPlatformInfo

namespace GetPackageDirectoryEntry {

namespace Results {

struct DirectoryEntry {
  DirectoryEntry();
  ~DirectoryEntry();
  DirectoryEntry(DirectoryEntry&& rhs);
  DirectoryEntry& operator=(DirectoryEntry&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DirectoryEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(DirectoryEntry);
};


std::unique_ptr<base::ListValue> Create(const DirectoryEntry& directory_entry);
}  // namespace Results

}  // namespace GetPackageDirectoryEntry

//
// Events
//

namespace OnStartup {

extern const char kEventName[];  // "runtime.onStartup"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnStartup

namespace OnInstalled {

extern const char kEventName[];  // "runtime.onInstalled"

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The reason that this event is being dispatched.
  OnInstalledReason reason;

  // Indicates the previous version of the extension, which has just been updated.
  // This is present only if 'reason' is 'update'.
  std::unique_ptr<std::string> previous_version;

  // Indicates the ID of the imported shared module extension which updated. This
  // is present only if 'reason' is 'shared_module_update'.
  std::unique_ptr<std::string> id;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace OnInstalled

namespace OnSuspend {

extern const char kEventName[];  // "runtime.onSuspend"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnSuspend

namespace OnSuspendCanceled {

extern const char kEventName[];  // "runtime.onSuspendCanceled"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnSuspendCanceled

namespace OnUpdateAvailable {

extern const char kEventName[];  // "runtime.onUpdateAvailable"

// The manifest details of the available update.
struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The version number of the available update.
  std::string version;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


// The manifest details of the available update.
std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace OnUpdateAvailable

namespace OnBrowserUpdateAvailable {

extern const char kEventName[];  // "runtime.onBrowserUpdateAvailable"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnBrowserUpdateAvailable

namespace OnRestartRequired {

extern const char kEventName[];  // "runtime.onRestartRequired"

// The reason that the event is being dispatched.
std::unique_ptr<base::ListValue> Create(const OnRestartRequiredReason& reason);
}  // namespace OnRestartRequired

}  // namespace runtime
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_RUNTIME_H__
