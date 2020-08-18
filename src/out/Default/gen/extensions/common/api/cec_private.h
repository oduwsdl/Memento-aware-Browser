// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/cec_private.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_CEC_PRIVATE_H__
#define EXTENSIONS_COMMON_API_CEC_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace cec_private {

//
// Types
//

enum DisplayCecPowerState {
  DISPLAY_CEC_POWER_STATE_NONE,
  DISPLAY_CEC_POWER_STATE_ERROR,
  DISPLAY_CEC_POWER_STATE_ADAPTERNOTCONFIGURED,
  DISPLAY_CEC_POWER_STATE_NODEVICE,
  DISPLAY_CEC_POWER_STATE_ON,
  DISPLAY_CEC_POWER_STATE_STANDBY,
  DISPLAY_CEC_POWER_STATE_TRANSITIONINGTOON,
  DISPLAY_CEC_POWER_STATE_TRANSITIONINGTOSTANDBY,
  DISPLAY_CEC_POWER_STATE_UNKNOWN,
  DISPLAY_CEC_POWER_STATE_LAST = DISPLAY_CEC_POWER_STATE_UNKNOWN,
};


const char* ToString(DisplayCecPowerState as_enum);
DisplayCecPowerState ParseDisplayCecPowerState(const std::string& as_string);


//
// Functions
//

namespace SendStandBy {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SendStandBy

namespace SendWakeUp {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SendWakeUp

namespace QueryDisplayCecPowerState {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<DisplayCecPowerState>& power_states);
}  // namespace Results

}  // namespace QueryDisplayCecPowerState

}  // namespace cec_private
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_CEC_PRIVATE_H__
