// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/runtime.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/runtime.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace runtime {
//
// Properties
//

//
// Types
//

const char* ToString(PlatformOs enum_param) {
  switch (enum_param) {
    case PLATFORM_OS_MAC:
      return "mac";
    case PLATFORM_OS_WIN:
      return "win";
    case PLATFORM_OS_ANDROID:
      return "android";
    case PLATFORM_OS_CROS:
      return "cros";
    case PLATFORM_OS_LINUX:
      return "linux";
    case PLATFORM_OS_OPENBSD:
      return "openbsd";
    case PLATFORM_OS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PlatformOs ParsePlatformOs(const std::string& enum_string) {
  if (enum_string == "mac")
    return PLATFORM_OS_MAC;
  if (enum_string == "win")
    return PLATFORM_OS_WIN;
  if (enum_string == "android")
    return PLATFORM_OS_ANDROID;
  if (enum_string == "cros")
    return PLATFORM_OS_CROS;
  if (enum_string == "linux")
    return PLATFORM_OS_LINUX;
  if (enum_string == "openbsd")
    return PLATFORM_OS_OPENBSD;
  return PLATFORM_OS_NONE;
}


const char* ToString(PlatformArch enum_param) {
  switch (enum_param) {
    case PLATFORM_ARCH_ARM:
      return "arm";
    case PLATFORM_ARCH_ARM64:
      return "arm64";
    case PLATFORM_ARCH_X86_32:
      return "x86-32";
    case PLATFORM_ARCH_X86_64:
      return "x86-64";
    case PLATFORM_ARCH_MIPS:
      return "mips";
    case PLATFORM_ARCH_MIPS64:
      return "mips64";
    case PLATFORM_ARCH_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PlatformArch ParsePlatformArch(const std::string& enum_string) {
  if (enum_string == "arm")
    return PLATFORM_ARCH_ARM;
  if (enum_string == "arm64")
    return PLATFORM_ARCH_ARM64;
  if (enum_string == "x86-32")
    return PLATFORM_ARCH_X86_32;
  if (enum_string == "x86-64")
    return PLATFORM_ARCH_X86_64;
  if (enum_string == "mips")
    return PLATFORM_ARCH_MIPS;
  if (enum_string == "mips64")
    return PLATFORM_ARCH_MIPS64;
  return PLATFORM_ARCH_NONE;
}


const char* ToString(PlatformNaclArch enum_param) {
  switch (enum_param) {
    case PLATFORM_NACL_ARCH_ARM:
      return "arm";
    case PLATFORM_NACL_ARCH_X86_32:
      return "x86-32";
    case PLATFORM_NACL_ARCH_X86_64:
      return "x86-64";
    case PLATFORM_NACL_ARCH_MIPS:
      return "mips";
    case PLATFORM_NACL_ARCH_MIPS64:
      return "mips64";
    case PLATFORM_NACL_ARCH_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PlatformNaclArch ParsePlatformNaclArch(const std::string& enum_string) {
  if (enum_string == "arm")
    return PLATFORM_NACL_ARCH_ARM;
  if (enum_string == "x86-32")
    return PLATFORM_NACL_ARCH_X86_32;
  if (enum_string == "x86-64")
    return PLATFORM_NACL_ARCH_X86_64;
  if (enum_string == "mips")
    return PLATFORM_NACL_ARCH_MIPS;
  if (enum_string == "mips64")
    return PLATFORM_NACL_ARCH_MIPS64;
  return PLATFORM_NACL_ARCH_NONE;
}


PlatformInfo::PlatformInfo()
: os(PLATFORM_OS_NONE),
arch(PLATFORM_ARCH_NONE),
nacl_arch(PLATFORM_NACL_ARCH_NONE) {}

PlatformInfo::~PlatformInfo() {}
PlatformInfo::PlatformInfo(PlatformInfo&& rhs)
: os(rhs.os),
arch(rhs.arch),
nacl_arch(rhs.nacl_arch){
}

PlatformInfo& PlatformInfo::operator=(PlatformInfo&& rhs)
{
os = rhs.os;
arch = rhs.arch;
nacl_arch = rhs.nacl_arch;
return *this;
}

// static
bool PlatformInfo::Populate(
    const base::Value& value, PlatformInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* os_value = NULL;
  if (!dict->GetWithoutPathExpansion("os", &os_value)) {
    return false;
  }
  {
    std::string platform_os_as_string;
    if (!os_value->GetAsString(&platform_os_as_string)) {
      return false;
    }
    out->os = ParsePlatformOs(platform_os_as_string);
    if (out->os == PLATFORM_OS_NONE) {
      return false;
    }
  }

  const base::Value* arch_value = NULL;
  if (!dict->GetWithoutPathExpansion("arch", &arch_value)) {
    return false;
  }
  {
    std::string platform_arch_as_string;
    if (!arch_value->GetAsString(&platform_arch_as_string)) {
      return false;
    }
    out->arch = ParsePlatformArch(platform_arch_as_string);
    if (out->arch == PLATFORM_ARCH_NONE) {
      return false;
    }
  }

  const base::Value* nacl_arch_value = NULL;
  if (!dict->GetWithoutPathExpansion("nacl_arch", &nacl_arch_value)) {
    return false;
  }
  {
    std::string platform_nacl_arch_as_string;
    if (!nacl_arch_value->GetAsString(&platform_nacl_arch_as_string)) {
      return false;
    }
    out->nacl_arch = ParsePlatformNaclArch(platform_nacl_arch_as_string);
    if (out->nacl_arch == PLATFORM_NACL_ARCH_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PlatformInfo> PlatformInfo::FromValue(const base::Value& value) {
  std::unique_ptr<PlatformInfo> out(new PlatformInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PlatformInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("os", std::make_unique<base::Value>(runtime::ToString(this->os)));

  to_value_result->SetWithoutPathExpansion("arch", std::make_unique<base::Value>(runtime::ToString(this->arch)));

  to_value_result->SetWithoutPathExpansion("nacl_arch", std::make_unique<base::Value>(runtime::ToString(this->nacl_arch)));


  return to_value_result;
}


const char* ToString(RequestUpdateCheckStatus enum_param) {
  switch (enum_param) {
    case REQUEST_UPDATE_CHECK_STATUS_THROTTLED:
      return "throttled";
    case REQUEST_UPDATE_CHECK_STATUS_NO_UPDATE:
      return "no_update";
    case REQUEST_UPDATE_CHECK_STATUS_UPDATE_AVAILABLE:
      return "update_available";
    case REQUEST_UPDATE_CHECK_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

RequestUpdateCheckStatus ParseRequestUpdateCheckStatus(const std::string& enum_string) {
  if (enum_string == "throttled")
    return REQUEST_UPDATE_CHECK_STATUS_THROTTLED;
  if (enum_string == "no_update")
    return REQUEST_UPDATE_CHECK_STATUS_NO_UPDATE;
  if (enum_string == "update_available")
    return REQUEST_UPDATE_CHECK_STATUS_UPDATE_AVAILABLE;
  return REQUEST_UPDATE_CHECK_STATUS_NONE;
}


const char* ToString(OnInstalledReason enum_param) {
  switch (enum_param) {
    case ON_INSTALLED_REASON_INSTALL:
      return "install";
    case ON_INSTALLED_REASON_UPDATE:
      return "update";
    case ON_INSTALLED_REASON_CHROME_UPDATE:
      return "chrome_update";
    case ON_INSTALLED_REASON_SHARED_MODULE_UPDATE:
      return "shared_module_update";
    case ON_INSTALLED_REASON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnInstalledReason ParseOnInstalledReason(const std::string& enum_string) {
  if (enum_string == "install")
    return ON_INSTALLED_REASON_INSTALL;
  if (enum_string == "update")
    return ON_INSTALLED_REASON_UPDATE;
  if (enum_string == "chrome_update")
    return ON_INSTALLED_REASON_CHROME_UPDATE;
  if (enum_string == "shared_module_update")
    return ON_INSTALLED_REASON_SHARED_MODULE_UPDATE;
  return ON_INSTALLED_REASON_NONE;
}


const char* ToString(OnRestartRequiredReason enum_param) {
  switch (enum_param) {
    case ON_RESTART_REQUIRED_REASON_APP_UPDATE:
      return "app_update";
    case ON_RESTART_REQUIRED_REASON_OS_UPDATE:
      return "os_update";
    case ON_RESTART_REQUIRED_REASON_PERIODIC:
      return "periodic";
    case ON_RESTART_REQUIRED_REASON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnRestartRequiredReason ParseOnRestartRequiredReason(const std::string& enum_string) {
  if (enum_string == "app_update")
    return ON_RESTART_REQUIRED_REASON_APP_UPDATE;
  if (enum_string == "os_update")
    return ON_RESTART_REQUIRED_REASON_OS_UPDATE;
  if (enum_string == "periodic")
    return ON_RESTART_REQUIRED_REASON_PERIODIC;
  return ON_RESTART_REQUIRED_REASON_NONE;
}



//
// Functions
//

namespace GetBackgroundPage {

Results::BackgroundPage::BackgroundPage()
 {}

Results::BackgroundPage::~BackgroundPage() {}
Results::BackgroundPage::BackgroundPage(BackgroundPage&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::BackgroundPage& Results::BackgroundPage::operator=(BackgroundPage&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::BackgroundPage::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const BackgroundPage& background_page) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((background_page).ToValue());

  return create_results;
}
}  // namespace GetBackgroundPage

namespace OpenOptionsPage {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace OpenOptionsPage

namespace SetUninstallURL {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
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

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetUninstallURL

namespace Reload {

}  // namespace Reload

namespace RequestUpdateCheck {

Results::Details::Details()
 {}

Results::Details::~Details() {}
Results::Details::Details(Details&& rhs)
: version(std::move(rhs.version)){
}

Results::Details& Results::Details::operator=(Details&& rhs)
{
version = std::move(rhs.version);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("version", std::make_unique<base::Value>(this->version));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const RequestUpdateCheckStatus& status, const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(runtime::ToString(status)));

  create_results->Append((details).ToValue());

  return create_results;
}
}  // namespace RequestUpdateCheck

namespace Restart {

}  // namespace Restart

namespace RestartAfterDelay {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* seconds_value = NULL;
  if (args.Get(0, &seconds_value) &&
      !seconds_value->is_none()) {
    {
      if (!seconds_value->GetAsInteger(&params->seconds)) {
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
}  // namespace RestartAfterDelay

namespace GetPlatformInfo {

std::unique_ptr<base::ListValue> Results::Create(const PlatformInfo& platform_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((platform_info).ToValue());

  return create_results;
}
}  // namespace GetPlatformInfo

namespace GetPackageDirectoryEntry {

Results::DirectoryEntry::DirectoryEntry()
 {}

Results::DirectoryEntry::~DirectoryEntry() {}
Results::DirectoryEntry::DirectoryEntry(DirectoryEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::DirectoryEntry& Results::DirectoryEntry::operator=(DirectoryEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::DirectoryEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const DirectoryEntry& directory_entry) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((directory_entry).ToValue());

  return create_results;
}
}  // namespace GetPackageDirectoryEntry

//
// Events
//

namespace OnStartup {

const char kEventName[] = "runtime.onStartup";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnStartup

namespace OnInstalled {

const char kEventName[] = "runtime.onInstalled";

Details::Details()
: reason(ON_INSTALLED_REASON_NONE) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: reason(rhs.reason),
previous_version(std::move(rhs.previous_version)),
id(std::move(rhs.id)){
}

Details& Details::operator=(Details&& rhs)
{
reason = rhs.reason;
previous_version = std::move(rhs.previous_version);
id = std::move(rhs.id);
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("reason", std::make_unique<base::Value>(runtime::ToString(this->reason)));

  if (this->previous_version.get()) {
    to_value_result->SetWithoutPathExpansion("previousVersion", std::make_unique<base::Value>(*this->previous_version));

  }
  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnInstalled

namespace OnSuspend {

const char kEventName[] = "runtime.onSuspend";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnSuspend

namespace OnSuspendCanceled {

const char kEventName[] = "runtime.onSuspendCanceled";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnSuspendCanceled

namespace OnUpdateAvailable {

const char kEventName[] = "runtime.onUpdateAvailable";

Details::Details()
 {}

Details::~Details() {}
Details::Details(Details&& rhs)
: version(std::move(rhs.version)){
additional_properties.Swap(&rhs.additional_properties);
}

Details& Details::operator=(Details&& rhs)
{
version = std::move(rhs.version);additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("version", std::make_unique<base::Value>(this->version));

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnUpdateAvailable

namespace OnBrowserUpdateAvailable {

const char kEventName[] = "runtime.onBrowserUpdateAvailable";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnBrowserUpdateAvailable

namespace OnRestartRequired {

const char kEventName[] = "runtime.onRestartRequired";

std::unique_ptr<base::ListValue> Create(const OnRestartRequiredReason& reason) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(runtime::ToString(reason)));

  return create_results;
}

}  // namespace OnRestartRequired

}  // namespace runtime
}  // namespace api
}  // namespace extensions

