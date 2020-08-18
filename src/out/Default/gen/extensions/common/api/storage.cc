// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/storage.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/storage.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace storage {
//
// Properties
//

namespace sync {
  const int QUOTA_BYTES = 102400;
  const int QUOTA_BYTES_PER_ITEM = 8192;
  const int MAX_ITEMS = 512;
  const int MAX_WRITE_OPERATIONS_PER_HOUR = 1800;
  const int MAX_WRITE_OPERATIONS_PER_MINUTE = 120;
  const int MAX_SUSTAINED_WRITE_OPERATIONS_PER_MINUTE = 1000000;
}  // namespace sync

namespace local {
  const int QUOTA_BYTES = 5242880;
}  // namespace local

//
// Types
//

StorageChange::StorageChange()
 {}

StorageChange::~StorageChange() {}
StorageChange::StorageChange(StorageChange&& rhs)
: old_value(std::move(rhs.old_value)),
new_value(std::move(rhs.new_value)){
}

StorageChange& StorageChange::operator=(StorageChange&& rhs)
{
old_value = std::move(rhs.old_value);
new_value = std::move(rhs.new_value);
return *this;
}

// static
bool StorageChange::Populate(
    const base::Value& value, StorageChange* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* old_value_value = NULL;
  if (dict->GetWithoutPathExpansion("oldValue", &old_value_value)) {
    {
      out->old_value = old_value_value->CreateDeepCopy();
    }
  }

  const base::Value* new_value_value = NULL;
  if (dict->GetWithoutPathExpansion("newValue", &new_value_value)) {
    {
      out->new_value = new_value_value->CreateDeepCopy();
    }
  }

  return true;
}

// static
std::unique_ptr<StorageChange> StorageChange::FromValue(const base::Value& value) {
  std::unique_ptr<StorageChange> out(new StorageChange());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> StorageChange::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->old_value.get()) {
    to_value_result->SetWithoutPathExpansion("oldValue", (this->old_value)->CreateDeepCopy());

  }
  if (this->new_value.get()) {
    to_value_result->SetWithoutPathExpansion("newValue", (this->new_value)->CreateDeepCopy());

  }

  return to_value_result;
}


namespace StorageArea {

namespace Get {

Params::Keys::Object::Object()
 {}

Params::Keys::Object::~Object() {}
Params::Keys::Object::Object(Object&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::Keys::Object& Params::Keys::Object::operator=(Object&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::Keys::Object::Populate(
    const base::Value& value, Object* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}



Params::Keys::Keys()
 {}

Params::Keys::~Keys() {}
Params::Keys::Keys(Keys&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)),
as_object(std::move(rhs.as_object)){
}

Params::Keys& Params::Keys::operator=(Keys&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
as_object = std::move(rhs.as_object);
return *this;
}

// static
bool Params::Keys::Populate(
    const base::Value& value, Keys* out) {
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::LIST) {
    {
      const base::ListValue* list = NULL;
      if (!(&value)->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_strings)) {
          return false;
        }
      }
    }
    return true;
  }
  if (value.type() == base::Value::Type::DICTIONARY) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!(&value)->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Object> temp(new Object());
        if (!Object::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->as_object = std::move(temp);
      }
    }
    return true;
  }
  return false;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* keys_value = NULL;
  if (args.Get(0, &keys_value) &&
      !keys_value->is_none()) {
    {
      std::unique_ptr<Keys> temp(new Keys());
      if (!Keys::Populate(*keys_value, temp.get()))
        return std::unique_ptr<Params>();
      params->keys = std::move(temp);
    }
  }

  return params;
}


Results::Items::Items()
 {}

Results::Items::~Items() {}
Results::Items::Items(Items&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Items& Results::Items::operator=(Items&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Items::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Items& items) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((items).ToValue());

  return create_results;
}
}  // namespace Get

namespace GetBytesInUse {

Params::Keys::Keys()
 {}

Params::Keys::~Keys() {}
Params::Keys::Keys(Keys&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)){
}

Params::Keys& Params::Keys::operator=(Keys&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool Params::Keys::Populate(
    const base::Value& value, Keys* out) {
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::LIST) {
    {
      const base::ListValue* list = NULL;
      if (!(&value)->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_strings)) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* keys_value = NULL;
  if (args.Get(0, &keys_value) &&
      !keys_value->is_none()) {
    {
      std::unique_ptr<Keys> temp(new Keys());
      if (!Keys::Populate(*keys_value, temp.get()))
        return std::unique_ptr<Params>();
      params->keys = std::move(temp);
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int bytes_in_use) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(bytes_in_use));

  return create_results;
}
}  // namespace GetBytesInUse

namespace Set {

Params::Items::Items()
 {}

Params::Items::~Items() {}
Params::Items::Items(Items&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::Items& Params::Items::operator=(Items&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::Items::Populate(
    const base::Value& value, Items* out) {
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
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* items_value = NULL;
  if (args.Get(0, &items_value) &&
      !items_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!items_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Items::Populate(*dictionary, &params->items)) {
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
}  // namespace Set

namespace Remove {

Params::Keys::Keys()
 {}

Params::Keys::~Keys() {}
Params::Keys::Keys(Keys&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)){
}

Params::Keys& Params::Keys::operator=(Keys&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool Params::Keys::Populate(
    const base::Value& value, Keys* out) {
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::LIST) {
    {
      const base::ListValue* list = NULL;
      if (!(&value)->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_strings)) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* keys_value = NULL;
  if (args.Get(0, &keys_value) &&
      !keys_value->is_none()) {
    {
      if (!Keys::Populate(*keys_value, &params->keys))
        return std::unique_ptr<Params>();
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
}  // namespace Remove

namespace Clear {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Clear

}  // namespace StorageArea


//
// Events
//

namespace OnChanged {

const char kEventName[] = "storage.onChanged";

Changes::Changes()
 {}

Changes::~Changes() {}
Changes::Changes(Changes&& rhs)
: additional_properties(std::move(rhs.additional_properties)){
}

Changes& Changes::operator=(Changes&& rhs)
{
additional_properties = std::move(rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Changes::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  for (const auto& it : additional_properties) {
    to_value_result->SetWithoutPathExpansion(it.first, (it.second).ToValue());

  }

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Changes& changes, const std::string& area_name) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((changes).ToValue());

  create_results->Append(std::make_unique<base::Value>(area_name));

  return create_results;
}

}  // namespace OnChanged

}  // namespace storage
}  // namespace api
}  // namespace extensions

