// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/command_line_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_COMMAND_LINE_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_COMMAND_LINE_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace command_line_private {

//
// Functions
//

namespace HasSwitch {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The name of a command line switch, without leading "--", such as
  // "enable-experimental-extension-apis".
  std::string name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Whether the switch is specified on the command line.
std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace HasSwitch

}  // namespace command_line_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_COMMAND_LINE_PRIVATE_H__
