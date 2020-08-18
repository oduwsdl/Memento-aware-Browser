// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/resources_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_RESOURCES_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_RESOURCES_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace resources_private {

//
// Types
//

enum Component {
  COMPONENT_NONE,
  COMPONENT_IDENTITY,
  COMPONENT_PDF,
  COMPONENT_LAST = COMPONENT_PDF,
};


const char* ToString(Component as_enum);
Component ParseComponent(const std::string& as_string);


//
// Functions
//

namespace GetStrings {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Internal chrome component to get strings for.
  Component component;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Result {
  Result();
  ~Result();
  Result(Result&& rhs);
  Result& operator=(Result&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Result object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Result);
};


std::unique_ptr<base::ListValue> Create(const Result& result);
}  // namespace Results

}  // namespace GetStrings

}  // namespace resources_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_RESOURCES_PRIVATE_H__
