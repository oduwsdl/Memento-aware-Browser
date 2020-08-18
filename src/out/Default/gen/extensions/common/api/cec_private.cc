// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/cec_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/cec_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace cec_private {
//
// Types
//

const char* ToString(DisplayCecPowerState enum_param) {
  switch (enum_param) {
    case DISPLAY_CEC_POWER_STATE_ERROR:
      return "error";
    case DISPLAY_CEC_POWER_STATE_ADAPTERNOTCONFIGURED:
      return "adapterNotConfigured";
    case DISPLAY_CEC_POWER_STATE_NODEVICE:
      return "noDevice";
    case DISPLAY_CEC_POWER_STATE_ON:
      return "on";
    case DISPLAY_CEC_POWER_STATE_STANDBY:
      return "standby";
    case DISPLAY_CEC_POWER_STATE_TRANSITIONINGTOON:
      return "transitioningToOn";
    case DISPLAY_CEC_POWER_STATE_TRANSITIONINGTOSTANDBY:
      return "transitioningToStandby";
    case DISPLAY_CEC_POWER_STATE_UNKNOWN:
      return "unknown";
    case DISPLAY_CEC_POWER_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DisplayCecPowerState ParseDisplayCecPowerState(const std::string& enum_string) {
  if (enum_string == "error")
    return DISPLAY_CEC_POWER_STATE_ERROR;
  if (enum_string == "adapterNotConfigured")
    return DISPLAY_CEC_POWER_STATE_ADAPTERNOTCONFIGURED;
  if (enum_string == "noDevice")
    return DISPLAY_CEC_POWER_STATE_NODEVICE;
  if (enum_string == "on")
    return DISPLAY_CEC_POWER_STATE_ON;
  if (enum_string == "standby")
    return DISPLAY_CEC_POWER_STATE_STANDBY;
  if (enum_string == "transitioningToOn")
    return DISPLAY_CEC_POWER_STATE_TRANSITIONINGTOON;
  if (enum_string == "transitioningToStandby")
    return DISPLAY_CEC_POWER_STATE_TRANSITIONINGTOSTANDBY;
  if (enum_string == "unknown")
    return DISPLAY_CEC_POWER_STATE_UNKNOWN;
  return DISPLAY_CEC_POWER_STATE_NONE;
}



//
// Functions
//

namespace SendStandBy {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SendStandBy

namespace SendWakeUp {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SendWakeUp

namespace QueryDisplayCecPowerState {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<DisplayCecPowerState>& power_states) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  {
    std::vector<std::string> powerStates_list;
    for (const auto& it : (power_states)) {
    powerStates_list.push_back(cec_private::ToString(it));
  }
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(powerStates_list));
  }

  return create_results;
}
}  // namespace QueryDisplayCecPowerState

}  // namespace cec_private
}  // namespace api
}  // namespace extensions

