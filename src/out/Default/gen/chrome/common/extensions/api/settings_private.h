// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/settings_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_SETTINGS_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_SETTINGS_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace settings_private {

//
// Types
//

enum PrefType {
  PREF_TYPE_NONE,
  PREF_TYPE_BOOLEAN,
  PREF_TYPE_NUMBER,
  PREF_TYPE_STRING,
  PREF_TYPE_URL,
  PREF_TYPE_LIST,
  PREF_TYPE_DICTIONARY,
  PREF_TYPE_LAST = PREF_TYPE_DICTIONARY,
};


const char* ToString(PrefType as_enum);
PrefType ParsePrefType(const std::string& as_string);

enum ControlledBy {
  CONTROLLED_BY_NONE,
  CONTROLLED_BY_DEVICE_POLICY,
  CONTROLLED_BY_USER_POLICY,
  CONTROLLED_BY_OWNER,
  CONTROLLED_BY_PRIMARY_USER,
  CONTROLLED_BY_EXTENSION,
  CONTROLLED_BY_PARENT,
  CONTROLLED_BY_CHILD_RESTRICTION,
  CONTROLLED_BY_LAST = CONTROLLED_BY_CHILD_RESTRICTION,
};


const char* ToString(ControlledBy as_enum);
ControlledBy ParseControlledBy(const std::string& as_string);

enum Enforcement {
  ENFORCEMENT_NONE,
  ENFORCEMENT_ENFORCED,
  ENFORCEMENT_RECOMMENDED,
  ENFORCEMENT_PARENT_SUPERVISED,
  ENFORCEMENT_LAST = ENFORCEMENT_PARENT_SUPERVISED,
};


const char* ToString(Enforcement as_enum);
Enforcement ParseEnforcement(const std::string& as_string);

struct PrefObject {
  PrefObject();
  ~PrefObject();
  PrefObject(PrefObject&& rhs);
  PrefObject& operator=(PrefObject&& rhs);

  // Populates a PrefObject object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, PrefObject* out);

  // Creates a PrefObject object from a base::Value, or NULL on failure.
  static std::unique_ptr<PrefObject> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PrefObject object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The key for the pref.
  std::string key;

  // The type of the pref (e.g., boolean, string, etc.).
  PrefType type;

  // The current value of the pref.
  std::unique_ptr<base::Value> value;

  // The policy source of the pref; an undefined value means there is no policy.
  ControlledBy controlled_by;

  // The owner name if controlledBy == OWNER. The primary user name if
  // controlledBy == PRIMARY_USER. The extension name if controlledBy ==
  // EXTENSION.
  std::unique_ptr<std::string> controlled_by_name;

  // The policy enforcement of the pref; must be specified if controlledBy is also
  // present.
  Enforcement enforcement;

  // The recommended value if enforcement == RECOMMENDED.
  std::unique_ptr<base::Value> recommended_value;

  // If enforcement == ENFORCED this optionally specifies preference values that
  // are still available for selection by the user. If set, must contain at least
  // 2 distinct values, as must contain |value| and |recommendedValue| (if
  // present).
  std::unique_ptr<std::vector<std::unique_ptr<base::Value>>> user_selectable_values;

  // If true, user control of the preference is disabled for reasons unrelated to
  // controlledBy (e.g. no signed-in profile is present). A false value is a
  // no-op.
  std::unique_ptr<bool> user_control_disabled;

  // The extension ID if controlledBy == EXTENSION.
  std::unique_ptr<std::string> extension_id;

  // Whether the controlling extension can be disabled if controlledBy ==
  // EXTENSION.
  std::unique_ptr<bool> extension_can_be_disabled;


 private:
  DISALLOW_COPY_AND_ASSIGN(PrefObject);
};


//
// Functions
//

namespace SetPref {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The name of the pref.
  std::string name;

  // The new value of the pref.
  std::unique_ptr<base::Value> value;

  // An optional user metrics identifier.
  std::unique_ptr<std::string> page_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetPref

namespace GetAllPrefs {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<PrefObject>& prefs);
}  // namespace Results

}  // namespace GetAllPrefs

namespace GetPref {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const PrefObject& pref);
}  // namespace Results

}  // namespace GetPref

namespace GetDefaultZoom {

namespace Results {

std::unique_ptr<base::ListValue> Create(double zoom);
}  // namespace Results

}  // namespace GetDefaultZoom

namespace SetDefaultZoom {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  double zoom;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetDefaultZoom

//
// Events
//

namespace OnPrefsChanged {

extern const char kEventName[];  // "settingsPrivate.onPrefsChanged"

std::unique_ptr<base::ListValue> Create(const std::vector<PrefObject>& prefs);
}  // namespace OnPrefsChanged

}  // namespace settings_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_SETTINGS_PRIVATE_H__
