// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/guest_view_internal.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/guest_view_internal.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace guest_view_internal {
//
// Types
//

Size::Size()
: width(0),
height(0) {}

Size::~Size() {}
Size::Size(Size&& rhs)
: width(rhs.width),
height(rhs.height){
}

Size& Size::operator=(Size&& rhs)
{
width = rhs.width;
height = rhs.height;
return *this;
}

// static
bool Size::Populate(
    const base::Value& value, Size* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* width_value = NULL;
  if (!dict->GetWithoutPathExpansion("width", &width_value)) {
    return false;
  }
  {
    if (!width_value->GetAsInteger(&out->width)) {
      return false;
    }
  }

  const base::Value* height_value = NULL;
  if (!dict->GetWithoutPathExpansion("height", &height_value)) {
    return false;
  }
  {
    if (!height_value->GetAsInteger(&out->height)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Size> Size::FromValue(const base::Value& value) {
  std::unique_ptr<Size> out(new Size());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Size::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));


  return to_value_result;
}


SizeParams::SizeParams()
 {}

SizeParams::~SizeParams() {}
SizeParams::SizeParams(SizeParams&& rhs)
: enable_auto_size(std::move(rhs.enable_auto_size)),
min(std::move(rhs.min)),
max(std::move(rhs.max)),
normal(std::move(rhs.normal)){
}

SizeParams& SizeParams::operator=(SizeParams&& rhs)
{
enable_auto_size = std::move(rhs.enable_auto_size);
min = std::move(rhs.min);
max = std::move(rhs.max);
normal = std::move(rhs.normal);
return *this;
}

// static
bool SizeParams::Populate(
    const base::Value& value, SizeParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* enable_auto_size_value = NULL;
  if (dict->GetWithoutPathExpansion("enableAutoSize", &enable_auto_size_value)) {
    {
      bool temp;
      if (!enable_auto_size_value->GetAsBoolean(&temp)) {
        out->enable_auto_size.reset();
        return false;
      }
      else
        out->enable_auto_size.reset(new bool(temp));
    }
  }

  const base::Value* min_value = NULL;
  if (dict->GetWithoutPathExpansion("min", &min_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!min_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Size> temp(new Size());
        if (!Size::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->min = std::move(temp);
      }
    }
  }

  const base::Value* max_value = NULL;
  if (dict->GetWithoutPathExpansion("max", &max_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!max_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Size> temp(new Size());
        if (!Size::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->max = std::move(temp);
      }
    }
  }

  const base::Value* normal_value = NULL;
  if (dict->GetWithoutPathExpansion("normal", &normal_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!normal_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Size> temp(new Size());
        if (!Size::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->normal = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<SizeParams> SizeParams::FromValue(const base::Value& value) {
  std::unique_ptr<SizeParams> out(new SizeParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SizeParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->enable_auto_size.get()) {
    to_value_result->SetWithoutPathExpansion("enableAutoSize", std::make_unique<base::Value>(*this->enable_auto_size));

  }
  if (this->min.get()) {
    to_value_result->SetWithoutPathExpansion("min", (this->min)->ToValue());

  }
  if (this->max.get()) {
    to_value_result->SetWithoutPathExpansion("max", (this->max)->ToValue());

  }
  if (this->normal.get()) {
    to_value_result->SetWithoutPathExpansion("normal", (this->normal)->ToValue());

  }

  return to_value_result;
}



//
// Functions
//

namespace CreateGuest {

Params::CreateParams::CreateParams()
 {}

Params::CreateParams::~CreateParams() {}
Params::CreateParams::CreateParams(CreateParams&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::CreateParams& Params::CreateParams::operator=(CreateParams&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::CreateParams::Populate(
    const base::Value& value, CreateParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* view_type_value = NULL;
  if (args.Get(0, &view_type_value) &&
      !view_type_value->is_none()) {
    {
      if (!view_type_value->GetAsString(&params->view_type)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* create_params_value = NULL;
  if (args.Get(1, &create_params_value) &&
      !create_params_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!create_params_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CreateParams::Populate(*dictionary, &params->create_params)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::ReturnParams::ReturnParams()
 {}

Results::ReturnParams::~ReturnParams() {}
Results::ReturnParams::ReturnParams(ReturnParams&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::ReturnParams& Results::ReturnParams::operator=(ReturnParams&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::ReturnParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const ReturnParams& return_params) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((return_params).ToValue());

  return create_results;
}
}  // namespace CreateGuest

namespace DestroyGuest {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
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
}  // namespace DestroyGuest

namespace SetSize {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* params_value = NULL;
  if (args.Get(1, &params_value) &&
      !params_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!params_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!SizeParams::Populate(*dictionary, &params->params)) {
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
}  // namespace SetSize

}  // namespace guest_view_internal
}  // namespace api
}  // namespace extensions

