// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/system_private.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/system_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace system_private {
//
// Types
//

const char* ToString(UpdateStatusState enum_param) {
  switch (enum_param) {
    case UPDATE_STATUS_STATE_NOTAVAILABLE:
      return "NotAvailable";
    case UPDATE_STATUS_STATE_UPDATING:
      return "Updating";
    case UPDATE_STATUS_STATE_NEEDRESTART:
      return "NeedRestart";
    case UPDATE_STATUS_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

UpdateStatusState ParseUpdateStatusState(const std::string& enum_string) {
  if (enum_string == "NotAvailable")
    return UPDATE_STATUS_STATE_NOTAVAILABLE;
  if (enum_string == "Updating")
    return UPDATE_STATUS_STATE_UPDATING;
  if (enum_string == "NeedRestart")
    return UPDATE_STATUS_STATE_NEEDRESTART;
  return UPDATE_STATUS_STATE_NONE;
}


const char* ToString(GetIncognitoModeAvailabilityValue enum_param) {
  switch (enum_param) {
    case GET_INCOGNITO_MODE_AVAILABILITY_VALUE_ENABLED:
      return "enabled";
    case GET_INCOGNITO_MODE_AVAILABILITY_VALUE_DISABLED:
      return "disabled";
    case GET_INCOGNITO_MODE_AVAILABILITY_VALUE_FORCED:
      return "forced";
    case GET_INCOGNITO_MODE_AVAILABILITY_VALUE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

GetIncognitoModeAvailabilityValue ParseGetIncognitoModeAvailabilityValue(const std::string& enum_string) {
  if (enum_string == "enabled")
    return GET_INCOGNITO_MODE_AVAILABILITY_VALUE_ENABLED;
  if (enum_string == "disabled")
    return GET_INCOGNITO_MODE_AVAILABILITY_VALUE_DISABLED;
  if (enum_string == "forced")
    return GET_INCOGNITO_MODE_AVAILABILITY_VALUE_FORCED;
  return GET_INCOGNITO_MODE_AVAILABILITY_VALUE_NONE;
}


UpdateStatus::UpdateStatus()
: state(UPDATE_STATUS_STATE_NONE),
download_progress(0.0) {}

UpdateStatus::~UpdateStatus() {}
UpdateStatus::UpdateStatus(UpdateStatus&& rhs)
: state(rhs.state),
download_progress(rhs.download_progress){
}

UpdateStatus& UpdateStatus::operator=(UpdateStatus&& rhs)
{
state = rhs.state;
download_progress = rhs.download_progress;
return *this;
}

// static
bool UpdateStatus::Populate(
    const base::Value& value, UpdateStatus* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("state", &state_value)) {
    return false;
  }
  {
    std::string update_status_state_as_string;
    if (!state_value->GetAsString(&update_status_state_as_string)) {
      return false;
    }
    out->state = ParseUpdateStatusState(update_status_state_as_string);
    if (out->state == UPDATE_STATUS_STATE_NONE) {
      return false;
    }
  }

  const base::Value* download_progress_value = NULL;
  if (!dict->GetWithoutPathExpansion("downloadProgress", &download_progress_value)) {
    return false;
  }
  {
    if (!download_progress_value->GetAsDouble(&out->download_progress)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<UpdateStatus> UpdateStatus::FromValue(const base::Value& value) {
  std::unique_ptr<UpdateStatus> out(new UpdateStatus());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> UpdateStatus::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(system_private::ToString(this->state)));

  to_value_result->SetWithoutPathExpansion("downloadProgress", std::make_unique<base::Value>(this->download_progress));


  return to_value_result;
}



//
// Functions
//

namespace GetIncognitoModeAvailability {

std::unique_ptr<base::ListValue> Results::Create(const GetIncognitoModeAvailabilityValue& value) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(system_private::ToString(value)));

  return create_results;
}
}  // namespace GetIncognitoModeAvailability

namespace GetUpdateStatus {

std::unique_ptr<base::ListValue> Results::Create(const UpdateStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((status).ToValue());

  return create_results;
}
}  // namespace GetUpdateStatus

namespace GetApiKey {

std::unique_ptr<base::ListValue> Results::Create(const std::string& key) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(key));

  return create_results;
}
}  // namespace GetApiKey

}  // namespace system_private
}  // namespace api
}  // namespace extensions

