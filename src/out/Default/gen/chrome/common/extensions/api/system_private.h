// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/system_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_SYSTEM_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_SYSTEM_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace system_private {

//
// Types
//

// State of system update.  NotAvailable when there is no available update or
// the update system is in error state, Updating when a system update is in
// progress, NeedRestart when a system update is finished and restart is needed.
enum UpdateStatusState {
  UPDATE_STATUS_STATE_NONE,
  UPDATE_STATUS_STATE_NOTAVAILABLE,
  UPDATE_STATUS_STATE_UPDATING,
  UPDATE_STATUS_STATE_NEEDRESTART,
  UPDATE_STATUS_STATE_LAST = UPDATE_STATUS_STATE_NEEDRESTART,
};


const char* ToString(UpdateStatusState as_enum);
UpdateStatusState ParseUpdateStatusState(const std::string& as_string);

// Exposes whether the incognito mode is available to windows. One of 'enabled',
// 'disabled' (user cannot browse pages in Incognito mode), 'forced' (all
// pages/sessions are forced into Incognito mode).
enum GetIncognitoModeAvailabilityValue {
  GET_INCOGNITO_MODE_AVAILABILITY_VALUE_NONE,
  GET_INCOGNITO_MODE_AVAILABILITY_VALUE_ENABLED,
  GET_INCOGNITO_MODE_AVAILABILITY_VALUE_DISABLED,
  GET_INCOGNITO_MODE_AVAILABILITY_VALUE_FORCED,
  GET_INCOGNITO_MODE_AVAILABILITY_VALUE_LAST = GET_INCOGNITO_MODE_AVAILABILITY_VALUE_FORCED,
};


const char* ToString(GetIncognitoModeAvailabilityValue as_enum);
GetIncognitoModeAvailabilityValue ParseGetIncognitoModeAvailabilityValue(const std::string& as_string);

// Information about the system update.
struct UpdateStatus {
  UpdateStatus();
  ~UpdateStatus();
  UpdateStatus(UpdateStatus&& rhs);
  UpdateStatus& operator=(UpdateStatus&& rhs);

  // Populates a UpdateStatus object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, UpdateStatus* out);

  // Creates a UpdateStatus object from a base::Value, or NULL on failure.
  static std::unique_ptr<UpdateStatus> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this UpdateStatus object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // State of system update.
  UpdateStatusState state;

  // Value between 0 and 1 describing the progress of system update download.
  // This value will be set to 0 when |state| is NotAvailable, 1 when NeedRestart.
  double download_progress;


 private:
  DISALLOW_COPY_AND_ASSIGN(UpdateStatus);
};


//
// Functions
//

namespace GetIncognitoModeAvailability {

namespace Results {

std::unique_ptr<base::ListValue> Create(const GetIncognitoModeAvailabilityValue& value);
}  // namespace Results

}  // namespace GetIncognitoModeAvailability

namespace GetUpdateStatus {

namespace Results {

// Details of the system update
std::unique_ptr<base::ListValue> Create(const UpdateStatus& status);
}  // namespace Results

}  // namespace GetUpdateStatus

namespace GetApiKey {

namespace Results {

// The API key.
std::unique_ptr<base::ListValue> Create(const std::string& key);
}  // namespace Results

}  // namespace GetApiKey

}  // namespace system_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_SYSTEM_PRIVATE_H__
