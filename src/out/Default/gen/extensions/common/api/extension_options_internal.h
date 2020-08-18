// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/extension_options_internal.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_EXTENSION_OPTIONS_INTERNAL_H__
#define EXTENSIONS_COMMON_API_EXTENSION_OPTIONS_INTERNAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace extension_options_internal {

//
// Types
//

struct SizeChangedOptions {
  SizeChangedOptions();
  ~SizeChangedOptions();
  SizeChangedOptions(SizeChangedOptions&& rhs);
  SizeChangedOptions& operator=(SizeChangedOptions&& rhs);

  // Populates a SizeChangedOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, SizeChangedOptions* out);

  // Creates a SizeChangedOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<SizeChangedOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SizeChangedOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int old_width;

  int old_height;

  int new_width;

  int new_height;


 private:
  DISALLOW_COPY_AND_ASSIGN(SizeChangedOptions);
};

struct PreferredSizeChangedOptions {
  PreferredSizeChangedOptions();
  ~PreferredSizeChangedOptions();
  PreferredSizeChangedOptions(PreferredSizeChangedOptions&& rhs);
  PreferredSizeChangedOptions& operator=(PreferredSizeChangedOptions&& rhs);

  // Populates a PreferredSizeChangedOptions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, PreferredSizeChangedOptions* out);

  // Creates a PreferredSizeChangedOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<PreferredSizeChangedOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PreferredSizeChangedOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  double width;

  double height;


 private:
  DISALLOW_COPY_AND_ASSIGN(PreferredSizeChangedOptions);
};


//
// Events
//

namespace OnClose {

extern const char kEventName[];  // "extensionOptionsInternal.onClose"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnClose

namespace OnLoad {

extern const char kEventName[];  // "extensionOptionsInternal.onLoad"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnLoad

namespace OnPreferredSizeChanged {

extern const char kEventName[];  // "extensionOptionsInternal.onPreferredSizeChanged"

std::unique_ptr<base::ListValue> Create(const PreferredSizeChangedOptions& options);
}  // namespace OnPreferredSizeChanged

}  // namespace extension_options_internal
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_EXTENSION_OPTIONS_INTERNAL_H__
