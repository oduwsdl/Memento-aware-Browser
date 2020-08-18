// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/virtual_keyboard.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_VIRTUAL_KEYBOARD_H__
#define EXTENSIONS_COMMON_API_VIRTUAL_KEYBOARD_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace virtual_keyboard {

//
// Types
//

struct FeatureRestrictions {
  FeatureRestrictions();
  ~FeatureRestrictions();
  FeatureRestrictions(FeatureRestrictions&& rhs);
  FeatureRestrictions& operator=(FeatureRestrictions&& rhs);

  // Populates a FeatureRestrictions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, FeatureRestrictions* out);

  // Creates a FeatureRestrictions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<FeatureRestrictions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FeatureRestrictions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether virtual keyboards can provide auto-complete.
  std::unique_ptr<bool> auto_complete_enabled;

  // Whether virtual keyboards can provide auto-correct.
  std::unique_ptr<bool> auto_correct_enabled;

  // Whether virtual keyboards can provide input via handwriting recognition.
  std::unique_ptr<bool> handwriting_enabled;

  // Whether virtual keyboards can provide spell-check.
  std::unique_ptr<bool> spell_check_enabled;

  // Whether virtual keyboards can provide voice input.
  std::unique_ptr<bool> voice_input_enabled;


 private:
  DISALLOW_COPY_AND_ASSIGN(FeatureRestrictions);
};


//
// Functions
//

namespace RestrictFeatures {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // the preferences to enabled/disabled virtual keyboard features.
  FeatureRestrictions restrictions;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const FeatureRestrictions& update);
}  // namespace Results

}  // namespace RestrictFeatures

}  // namespace virtual_keyboard
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_VIRTUAL_KEYBOARD_H__
