// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/power.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_POWER_H__
#define EXTENSIONS_COMMON_API_POWER_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace power {

//
// Types
//

enum Level {
  LEVEL_NONE,
  LEVEL_SYSTEM,
  LEVEL_DISPLAY,
  LEVEL_LAST = LEVEL_DISPLAY,
};


const char* ToString(Level as_enum);
Level ParseLevel(const std::string& as_string);


//
// Functions
//

namespace RequestKeepAwake {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  Level level;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RequestKeepAwake

namespace ReleaseKeepAwake {

}  // namespace ReleaseKeepAwake

}  // namespace power
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_POWER_H__
