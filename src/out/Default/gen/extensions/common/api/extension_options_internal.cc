// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/extension_options_internal.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/extension_options_internal.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace extension_options_internal {
//
// Types
//

SizeChangedOptions::SizeChangedOptions()
: old_width(0),
old_height(0),
new_width(0),
new_height(0) {}

SizeChangedOptions::~SizeChangedOptions() {}
SizeChangedOptions::SizeChangedOptions(SizeChangedOptions&& rhs)
: old_width(rhs.old_width),
old_height(rhs.old_height),
new_width(rhs.new_width),
new_height(rhs.new_height){
}

SizeChangedOptions& SizeChangedOptions::operator=(SizeChangedOptions&& rhs)
{
old_width = rhs.old_width;
old_height = rhs.old_height;
new_width = rhs.new_width;
new_height = rhs.new_height;
return *this;
}

// static
bool SizeChangedOptions::Populate(
    const base::Value& value, SizeChangedOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* old_width_value = NULL;
  if (!dict->GetWithoutPathExpansion("oldWidth", &old_width_value)) {
    return false;
  }
  {
    if (!old_width_value->GetAsInteger(&out->old_width)) {
      return false;
    }
  }

  const base::Value* old_height_value = NULL;
  if (!dict->GetWithoutPathExpansion("oldHeight", &old_height_value)) {
    return false;
  }
  {
    if (!old_height_value->GetAsInteger(&out->old_height)) {
      return false;
    }
  }

  const base::Value* new_width_value = NULL;
  if (!dict->GetWithoutPathExpansion("newWidth", &new_width_value)) {
    return false;
  }
  {
    if (!new_width_value->GetAsInteger(&out->new_width)) {
      return false;
    }
  }

  const base::Value* new_height_value = NULL;
  if (!dict->GetWithoutPathExpansion("newHeight", &new_height_value)) {
    return false;
  }
  {
    if (!new_height_value->GetAsInteger(&out->new_height)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SizeChangedOptions> SizeChangedOptions::FromValue(const base::Value& value) {
  std::unique_ptr<SizeChangedOptions> out(new SizeChangedOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SizeChangedOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("oldWidth", std::make_unique<base::Value>(this->old_width));

  to_value_result->SetWithoutPathExpansion("oldHeight", std::make_unique<base::Value>(this->old_height));

  to_value_result->SetWithoutPathExpansion("newWidth", std::make_unique<base::Value>(this->new_width));

  to_value_result->SetWithoutPathExpansion("newHeight", std::make_unique<base::Value>(this->new_height));


  return to_value_result;
}


PreferredSizeChangedOptions::PreferredSizeChangedOptions()
: width(0.0),
height(0.0) {}

PreferredSizeChangedOptions::~PreferredSizeChangedOptions() {}
PreferredSizeChangedOptions::PreferredSizeChangedOptions(PreferredSizeChangedOptions&& rhs)
: width(rhs.width),
height(rhs.height){
}

PreferredSizeChangedOptions& PreferredSizeChangedOptions::operator=(PreferredSizeChangedOptions&& rhs)
{
width = rhs.width;
height = rhs.height;
return *this;
}

// static
bool PreferredSizeChangedOptions::Populate(
    const base::Value& value, PreferredSizeChangedOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* width_value = NULL;
  if (!dict->GetWithoutPathExpansion("width", &width_value)) {
    return false;
  }
  {
    if (!width_value->GetAsDouble(&out->width)) {
      return false;
    }
  }

  const base::Value* height_value = NULL;
  if (!dict->GetWithoutPathExpansion("height", &height_value)) {
    return false;
  }
  {
    if (!height_value->GetAsDouble(&out->height)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PreferredSizeChangedOptions> PreferredSizeChangedOptions::FromValue(const base::Value& value) {
  std::unique_ptr<PreferredSizeChangedOptions> out(new PreferredSizeChangedOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PreferredSizeChangedOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));


  return to_value_result;
}



//
// Events
//

namespace OnClose {

const char kEventName[] = "extensionOptionsInternal.onClose";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnClose

namespace OnLoad {

const char kEventName[] = "extensionOptionsInternal.onLoad";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnLoad

namespace OnPreferredSizeChanged {

const char kEventName[] = "extensionOptionsInternal.onPreferredSizeChanged";

std::unique_ptr<base::ListValue> Create(const PreferredSizeChangedOptions& options) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((options).ToValue());

  return create_results;
}

}  // namespace OnPreferredSizeChanged

}  // namespace extension_options_internal
}  // namespace api
}  // namespace extensions

