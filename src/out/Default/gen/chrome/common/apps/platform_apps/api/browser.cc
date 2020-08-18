// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/apps/platform_apps/api/browser.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/apps/platform_apps/api/browser.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace chrome_apps {
namespace api {
namespace browser {
//
// Types
//

OpenTabOptions::OpenTabOptions()
 {}

OpenTabOptions::~OpenTabOptions() {}
OpenTabOptions::OpenTabOptions(OpenTabOptions&& rhs)
: url(std::move(rhs.url)){
}

OpenTabOptions& OpenTabOptions::operator=(OpenTabOptions&& rhs)
{
url = std::move(rhs.url);
return *this;
}

// static
bool OpenTabOptions::Populate(
    const base::Value& value, OpenTabOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<OpenTabOptions> OpenTabOptions::FromValue(const base::Value& value) {
  std::unique_ptr<OpenTabOptions> out(new OpenTabOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OpenTabOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));


  return to_value_result;
}



//
// Functions
//

namespace OpenTab {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!OpenTabOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace OpenTab

}  // namespace browser
}  // namespace api
}  // namespace chrome_apps

