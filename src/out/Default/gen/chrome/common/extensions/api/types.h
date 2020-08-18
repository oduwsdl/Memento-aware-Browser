// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/types.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_TYPES_H__
#define CHROME_COMMON_EXTENSIONS_API_TYPES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace types {

//
// Types
//

// The scope of the ChromeSetting. One of<ul><li><var>regular</var>: setting for
// the regular profile (which is inherited by the incognito profile if not
// overridden elsewhere),</li><li><var>regular_only</var>: setting for the
// regular profile only (not inherited by the incognito
// profile),</li><li><var>incognito_persistent</var>: setting for the incognito
// profile that survives browser restarts (overrides regular
// preferences),</li><li><var>incognito_session_only</var>: setting for the
// incognito profile that can only be set during an incognito session and is
// deleted when the incognito session ends (overrides regular and
// incognito_persistent preferences).</li></ul>
enum ChromeSettingScope {
  CHROME_SETTING_SCOPE_NONE,
  CHROME_SETTING_SCOPE_REGULAR,
  CHROME_SETTING_SCOPE_REGULAR_ONLY,
  CHROME_SETTING_SCOPE_INCOGNITO_PERSISTENT,
  CHROME_SETTING_SCOPE_INCOGNITO_SESSION_ONLY,
  CHROME_SETTING_SCOPE_LAST = CHROME_SETTING_SCOPE_INCOGNITO_SESSION_ONLY,
};


const char* ToString(ChromeSettingScope as_enum);
ChromeSettingScope ParseChromeSettingScope(const std::string& as_string);

// One of<ul><li><var>not_controllable</var>: cannot be controlled by any
// extension</li><li><var>controlled_by_other_extensions</var>: controlled by
// extensions with higher
// precedence</li><li><var>controllable_by_this_extension</var>: can be
// controlled by this extension</li><li><var>controlled_by_this_extension</var>:
// controlled by this extension</li></ul>
enum LevelOfControl {
  LEVEL_OF_CONTROL_NONE,
  LEVEL_OF_CONTROL_NOT_CONTROLLABLE,
  LEVEL_OF_CONTROL_CONTROLLED_BY_OTHER_EXTENSIONS,
  LEVEL_OF_CONTROL_CONTROLLABLE_BY_THIS_EXTENSION,
  LEVEL_OF_CONTROL_CONTROLLED_BY_THIS_EXTENSION,
  LEVEL_OF_CONTROL_LAST = LEVEL_OF_CONTROL_CONTROLLED_BY_THIS_EXTENSION,
};


const char* ToString(LevelOfControl as_enum);
LevelOfControl ParseLevelOfControl(const std::string& as_string);

// An interface that allows access to a Chrome browser setting. See
// $(ref:accessibilityFeatures) for an example.
struct ChromeSetting {
  ChromeSetting();
  ~ChromeSetting();
  ChromeSetting(ChromeSetting&& rhs);
  ChromeSetting& operator=(ChromeSetting&& rhs);

  // Populates a ChromeSetting object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ChromeSetting* out);

  // Creates a ChromeSetting object from a base::Value, or NULL on failure.
  static std::unique_ptr<ChromeSetting> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ChromeSetting object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(ChromeSetting);
};


}  // namespace types
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_TYPES_H__
