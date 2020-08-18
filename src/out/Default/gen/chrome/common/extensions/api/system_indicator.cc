// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/system_indicator.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/system_indicator.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace system_indicator {
//
// Types
//

SetIconDetails::SetIconDetails()
 {}

SetIconDetails::~SetIconDetails() {}
SetIconDetails::SetIconDetails(SetIconDetails&& rhs)
: path(std::move(rhs.path)),
image_data(std::move(rhs.image_data)){
}

SetIconDetails& SetIconDetails::operator=(SetIconDetails&& rhs)
{
path = std::move(rhs.path);
image_data = std::move(rhs.image_data);
return *this;
}

// static
bool SetIconDetails::Populate(
    const base::Value& value, SetIconDetails* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* path_value = NULL;
  if (dict->GetWithoutPathExpansion("path", &path_value)) {
    {
      out->path = path_value->CreateDeepCopy();
    }
  }

  const base::Value* image_data_value = NULL;
  if (dict->GetWithoutPathExpansion("imageData", &image_data_value)) {
    {
      out->image_data = image_data_value->CreateDeepCopy();
    }
  }

  return true;
}

// static
std::unique_ptr<SetIconDetails> SetIconDetails::FromValue(const base::Value& value) {
  std::unique_ptr<SetIconDetails> out(new SetIconDetails());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SetIconDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->path.get()) {
    to_value_result->SetWithoutPathExpansion("path", (this->path)->CreateDeepCopy());

  }
  if (this->image_data.get()) {
    to_value_result->SetWithoutPathExpansion("imageData", (this->image_data)->CreateDeepCopy());

  }

  return to_value_result;
}



//
// Functions
//

namespace SetIcon {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!SetIconDetails::Populate(*dictionary, &params->details)) {
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
}  // namespace SetIcon

namespace Enable {

}  // namespace Enable

namespace Disable {

}  // namespace Disable

//
// Events
//

namespace OnClicked {

const char kEventName[] = "systemIndicator.onClicked";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnClicked

}  // namespace system_indicator
}  // namespace api
}  // namespace extensions

