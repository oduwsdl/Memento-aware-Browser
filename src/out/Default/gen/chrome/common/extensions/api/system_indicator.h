// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/system_indicator.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_SYSTEM_INDICATOR_H__
#define CHROME_COMMON_EXTENSIONS_API_SYSTEM_INDICATOR_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace system_indicator {

//
// Types
//

struct SetIconDetails {
  SetIconDetails();
  ~SetIconDetails();
  SetIconDetails(SetIconDetails&& rhs);
  SetIconDetails& operator=(SetIconDetails&& rhs);

  // Populates a SetIconDetails object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, SetIconDetails* out);

  // Creates a SetIconDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<SetIconDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SetIconDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<base::Value> path;

  std::unique_ptr<base::Value> image_data;


 private:
  DISALLOW_COPY_AND_ASSIGN(SetIconDetails);
};


//
// Functions
//

namespace SetIcon {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  SetIconDetails details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetIcon

namespace Enable {

}  // namespace Enable

namespace Disable {

}  // namespace Disable

//
// Events
//

namespace OnClicked {

extern const char kEventName[];  // "systemIndicator.onClicked"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnClicked

}  // namespace system_indicator
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_SYSTEM_INDICATOR_H__
