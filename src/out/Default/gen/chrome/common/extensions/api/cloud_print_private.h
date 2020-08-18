// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/cloud_print_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_CLOUD_PRINT_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_CLOUD_PRINT_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace cloud_print_private {

//
// Types
//

// Settings per printer.
struct PrinterSettings {
  PrinterSettings();
  ~PrinterSettings();
  PrinterSettings(PrinterSettings&& rhs);
  PrinterSettings& operator=(PrinterSettings&& rhs);

  // Populates a PrinterSettings object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, PrinterSettings* out);

  // Creates a PrinterSettings object from a base::Value, or NULL on failure.
  static std::unique_ptr<PrinterSettings> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PrinterSettings object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Unique printer id.
  std::string name;

  // Whether printer is selected.
  bool connect;


 private:
  DISALLOW_COPY_AND_ASSIGN(PrinterSettings);
};

// Settings set by user.
struct UserSettings {
  UserSettings();
  ~UserSettings();
  UserSettings(UserSettings&& rhs);
  UserSettings& operator=(UserSettings&& rhs);

  // Populates a UserSettings object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, UserSettings* out);

  // Creates a UserSettings object from a base::Value, or NULL on failure.
  static std::unique_ptr<UserSettings> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this UserSettings object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Printer settings.
  std::vector<PrinterSettings> printers;

  // Whether should printer be connected.
  bool connect_new_printers;


 private:
  DISALLOW_COPY_AND_ASSIGN(UserSettings);
};


//
// Functions
//

namespace SetupConnector {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The email address of the user.
  std::string user_email;

  // The email address of the robot account.
  std::string robot_email;

  // The login credentials(OAuth2 Auth code).
  std::string credentials;

  // Options configured by user.
  UserSettings user_settings;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetupConnector

namespace GetHostName {

namespace Results {

// Host name.
std::unique_ptr<base::ListValue> Create(const std::string& result);
}  // namespace Results

}  // namespace GetHostName

namespace GetPrinters {

namespace Results {

// List of printer names.
std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& result);
}  // namespace Results

}  // namespace GetPrinters

namespace GetClientId {

namespace Results {

// Client ID.
std::unique_ptr<base::ListValue> Create(const std::string& result);
}  // namespace Results

}  // namespace GetClientId

}  // namespace cloud_print_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_CLOUD_PRINT_PRIVATE_H__
