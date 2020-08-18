// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/autofill_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/autofill_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace autofill_private {
//
// Types
//

const char* ToString(AddressField enum_param) {
  switch (enum_param) {
    case ADDRESS_FIELD_FULL_NAME:
      return "FULL_NAME";
    case ADDRESS_FIELD_COMPANY_NAME:
      return "COMPANY_NAME";
    case ADDRESS_FIELD_ADDRESS_LINES:
      return "ADDRESS_LINES";
    case ADDRESS_FIELD_ADDRESS_LEVEL_1:
      return "ADDRESS_LEVEL_1";
    case ADDRESS_FIELD_ADDRESS_LEVEL_2:
      return "ADDRESS_LEVEL_2";
    case ADDRESS_FIELD_ADDRESS_LEVEL_3:
      return "ADDRESS_LEVEL_3";
    case ADDRESS_FIELD_POSTAL_CODE:
      return "POSTAL_CODE";
    case ADDRESS_FIELD_SORTING_CODE:
      return "SORTING_CODE";
    case ADDRESS_FIELD_COUNTRY_CODE:
      return "COUNTRY_CODE";
    case ADDRESS_FIELD_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

AddressField ParseAddressField(const std::string& enum_string) {
  if (enum_string == "FULL_NAME")
    return ADDRESS_FIELD_FULL_NAME;
  if (enum_string == "COMPANY_NAME")
    return ADDRESS_FIELD_COMPANY_NAME;
  if (enum_string == "ADDRESS_LINES")
    return ADDRESS_FIELD_ADDRESS_LINES;
  if (enum_string == "ADDRESS_LEVEL_1")
    return ADDRESS_FIELD_ADDRESS_LEVEL_1;
  if (enum_string == "ADDRESS_LEVEL_2")
    return ADDRESS_FIELD_ADDRESS_LEVEL_2;
  if (enum_string == "ADDRESS_LEVEL_3")
    return ADDRESS_FIELD_ADDRESS_LEVEL_3;
  if (enum_string == "POSTAL_CODE")
    return ADDRESS_FIELD_POSTAL_CODE;
  if (enum_string == "SORTING_CODE")
    return ADDRESS_FIELD_SORTING_CODE;
  if (enum_string == "COUNTRY_CODE")
    return ADDRESS_FIELD_COUNTRY_CODE;
  return ADDRESS_FIELD_NONE;
}


AutofillMetadata::AutofillMetadata()
 {}

AutofillMetadata::~AutofillMetadata() {}
AutofillMetadata::AutofillMetadata(AutofillMetadata&& rhs)
: summary_label(std::move(rhs.summary_label)),
summary_sublabel(std::move(rhs.summary_sublabel)),
is_local(std::move(rhs.is_local)),
is_cached(std::move(rhs.is_cached)),
is_migratable(std::move(rhs.is_migratable)){
}

AutofillMetadata& AutofillMetadata::operator=(AutofillMetadata&& rhs)
{
summary_label = std::move(rhs.summary_label);
summary_sublabel = std::move(rhs.summary_sublabel);
is_local = std::move(rhs.is_local);
is_cached = std::move(rhs.is_cached);
is_migratable = std::move(rhs.is_migratable);
return *this;
}

// static
bool AutofillMetadata::Populate(
    const base::Value& value, AutofillMetadata* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* summary_label_value = NULL;
  if (!dict->GetWithoutPathExpansion("summaryLabel", &summary_label_value)) {
    return false;
  }
  {
    if (!summary_label_value->GetAsString(&out->summary_label)) {
      return false;
    }
  }

  const base::Value* summary_sublabel_value = NULL;
  if (dict->GetWithoutPathExpansion("summarySublabel", &summary_sublabel_value)) {
    {
      std::string temp;
      if (!summary_sublabel_value->GetAsString(&temp)) {
        out->summary_sublabel.reset();
        return false;
      }
      else
        out->summary_sublabel.reset(new std::string(temp));
    }
  }

  const base::Value* is_local_value = NULL;
  if (dict->GetWithoutPathExpansion("isLocal", &is_local_value)) {
    {
      bool temp;
      if (!is_local_value->GetAsBoolean(&temp)) {
        out->is_local.reset();
        return false;
      }
      else
        out->is_local.reset(new bool(temp));
    }
  }

  const base::Value* is_cached_value = NULL;
  if (dict->GetWithoutPathExpansion("isCached", &is_cached_value)) {
    {
      bool temp;
      if (!is_cached_value->GetAsBoolean(&temp)) {
        out->is_cached.reset();
        return false;
      }
      else
        out->is_cached.reset(new bool(temp));
    }
  }

  const base::Value* is_migratable_value = NULL;
  if (dict->GetWithoutPathExpansion("isMigratable", &is_migratable_value)) {
    {
      bool temp;
      if (!is_migratable_value->GetAsBoolean(&temp)) {
        out->is_migratable.reset();
        return false;
      }
      else
        out->is_migratable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<AutofillMetadata> AutofillMetadata::FromValue(const base::Value& value) {
  std::unique_ptr<AutofillMetadata> out(new AutofillMetadata());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AutofillMetadata::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("summaryLabel", std::make_unique<base::Value>(this->summary_label));

  if (this->summary_sublabel.get()) {
    to_value_result->SetWithoutPathExpansion("summarySublabel", std::make_unique<base::Value>(*this->summary_sublabel));

  }
  if (this->is_local.get()) {
    to_value_result->SetWithoutPathExpansion("isLocal", std::make_unique<base::Value>(*this->is_local));

  }
  if (this->is_cached.get()) {
    to_value_result->SetWithoutPathExpansion("isCached", std::make_unique<base::Value>(*this->is_cached));

  }
  if (this->is_migratable.get()) {
    to_value_result->SetWithoutPathExpansion("isMigratable", std::make_unique<base::Value>(*this->is_migratable));

  }

  return to_value_result;
}


AddressEntry::AddressEntry()
 {}

AddressEntry::~AddressEntry() {}
AddressEntry::AddressEntry(AddressEntry&& rhs)
: guid(std::move(rhs.guid)),
full_names(std::move(rhs.full_names)),
company_name(std::move(rhs.company_name)),
address_lines(std::move(rhs.address_lines)),
address_level1(std::move(rhs.address_level1)),
address_level2(std::move(rhs.address_level2)),
address_level3(std::move(rhs.address_level3)),
postal_code(std::move(rhs.postal_code)),
sorting_code(std::move(rhs.sorting_code)),
country_code(std::move(rhs.country_code)),
phone_numbers(std::move(rhs.phone_numbers)),
email_addresses(std::move(rhs.email_addresses)),
language_code(std::move(rhs.language_code)),
metadata(std::move(rhs.metadata)){
}

AddressEntry& AddressEntry::operator=(AddressEntry&& rhs)
{
guid = std::move(rhs.guid);
full_names = std::move(rhs.full_names);
company_name = std::move(rhs.company_name);
address_lines = std::move(rhs.address_lines);
address_level1 = std::move(rhs.address_level1);
address_level2 = std::move(rhs.address_level2);
address_level3 = std::move(rhs.address_level3);
postal_code = std::move(rhs.postal_code);
sorting_code = std::move(rhs.sorting_code);
country_code = std::move(rhs.country_code);
phone_numbers = std::move(rhs.phone_numbers);
email_addresses = std::move(rhs.email_addresses);
language_code = std::move(rhs.language_code);
metadata = std::move(rhs.metadata);
return *this;
}

// static
bool AddressEntry::Populate(
    const base::Value& value, AddressEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* guid_value = NULL;
  if (dict->GetWithoutPathExpansion("guid", &guid_value)) {
    {
      std::string temp;
      if (!guid_value->GetAsString(&temp)) {
        out->guid.reset();
        return false;
      }
      else
        out->guid.reset(new std::string(temp));
    }
  }

  const base::Value* full_names_value = NULL;
  if (dict->GetWithoutPathExpansion("fullNames", &full_names_value)) {
    {
      const base::ListValue* list = NULL;
      if (!full_names_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->full_names)) {
          return false;
        }
      }
    }
  }

  const base::Value* company_name_value = NULL;
  if (dict->GetWithoutPathExpansion("companyName", &company_name_value)) {
    {
      std::string temp;
      if (!company_name_value->GetAsString(&temp)) {
        out->company_name.reset();
        return false;
      }
      else
        out->company_name.reset(new std::string(temp));
    }
  }

  const base::Value* address_lines_value = NULL;
  if (dict->GetWithoutPathExpansion("addressLines", &address_lines_value)) {
    {
      std::string temp;
      if (!address_lines_value->GetAsString(&temp)) {
        out->address_lines.reset();
        return false;
      }
      else
        out->address_lines.reset(new std::string(temp));
    }
  }

  const base::Value* address_level1_value = NULL;
  if (dict->GetWithoutPathExpansion("addressLevel1", &address_level1_value)) {
    {
      std::string temp;
      if (!address_level1_value->GetAsString(&temp)) {
        out->address_level1.reset();
        return false;
      }
      else
        out->address_level1.reset(new std::string(temp));
    }
  }

  const base::Value* address_level2_value = NULL;
  if (dict->GetWithoutPathExpansion("addressLevel2", &address_level2_value)) {
    {
      std::string temp;
      if (!address_level2_value->GetAsString(&temp)) {
        out->address_level2.reset();
        return false;
      }
      else
        out->address_level2.reset(new std::string(temp));
    }
  }

  const base::Value* address_level3_value = NULL;
  if (dict->GetWithoutPathExpansion("addressLevel3", &address_level3_value)) {
    {
      std::string temp;
      if (!address_level3_value->GetAsString(&temp)) {
        out->address_level3.reset();
        return false;
      }
      else
        out->address_level3.reset(new std::string(temp));
    }
  }

  const base::Value* postal_code_value = NULL;
  if (dict->GetWithoutPathExpansion("postalCode", &postal_code_value)) {
    {
      std::string temp;
      if (!postal_code_value->GetAsString(&temp)) {
        out->postal_code.reset();
        return false;
      }
      else
        out->postal_code.reset(new std::string(temp));
    }
  }

  const base::Value* sorting_code_value = NULL;
  if (dict->GetWithoutPathExpansion("sortingCode", &sorting_code_value)) {
    {
      std::string temp;
      if (!sorting_code_value->GetAsString(&temp)) {
        out->sorting_code.reset();
        return false;
      }
      else
        out->sorting_code.reset(new std::string(temp));
    }
  }

  const base::Value* country_code_value = NULL;
  if (dict->GetWithoutPathExpansion("countryCode", &country_code_value)) {
    {
      std::string temp;
      if (!country_code_value->GetAsString(&temp)) {
        out->country_code.reset();
        return false;
      }
      else
        out->country_code.reset(new std::string(temp));
    }
  }

  const base::Value* phone_numbers_value = NULL;
  if (dict->GetWithoutPathExpansion("phoneNumbers", &phone_numbers_value)) {
    {
      const base::ListValue* list = NULL;
      if (!phone_numbers_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->phone_numbers)) {
          return false;
        }
      }
    }
  }

  const base::Value* email_addresses_value = NULL;
  if (dict->GetWithoutPathExpansion("emailAddresses", &email_addresses_value)) {
    {
      const base::ListValue* list = NULL;
      if (!email_addresses_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->email_addresses)) {
          return false;
        }
      }
    }
  }

  const base::Value* language_code_value = NULL;
  if (dict->GetWithoutPathExpansion("languageCode", &language_code_value)) {
    {
      std::string temp;
      if (!language_code_value->GetAsString(&temp)) {
        out->language_code.reset();
        return false;
      }
      else
        out->language_code.reset(new std::string(temp));
    }
  }

  const base::Value* metadata_value = NULL;
  if (dict->GetWithoutPathExpansion("metadata", &metadata_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!metadata_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<AutofillMetadata> temp(new AutofillMetadata());
        if (!AutofillMetadata::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->metadata = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<AddressEntry> AddressEntry::FromValue(const base::Value& value) {
  std::unique_ptr<AddressEntry> out(new AddressEntry());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AddressEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->guid.get()) {
    to_value_result->SetWithoutPathExpansion("guid", std::make_unique<base::Value>(*this->guid));

  }
  if (this->full_names.get()) {
    to_value_result->SetWithoutPathExpansion("fullNames", json_schema_compiler::util::CreateValueFromOptionalArray(this->full_names));

  }
  if (this->company_name.get()) {
    to_value_result->SetWithoutPathExpansion("companyName", std::make_unique<base::Value>(*this->company_name));

  }
  if (this->address_lines.get()) {
    to_value_result->SetWithoutPathExpansion("addressLines", std::make_unique<base::Value>(*this->address_lines));

  }
  if (this->address_level1.get()) {
    to_value_result->SetWithoutPathExpansion("addressLevel1", std::make_unique<base::Value>(*this->address_level1));

  }
  if (this->address_level2.get()) {
    to_value_result->SetWithoutPathExpansion("addressLevel2", std::make_unique<base::Value>(*this->address_level2));

  }
  if (this->address_level3.get()) {
    to_value_result->SetWithoutPathExpansion("addressLevel3", std::make_unique<base::Value>(*this->address_level3));

  }
  if (this->postal_code.get()) {
    to_value_result->SetWithoutPathExpansion("postalCode", std::make_unique<base::Value>(*this->postal_code));

  }
  if (this->sorting_code.get()) {
    to_value_result->SetWithoutPathExpansion("sortingCode", std::make_unique<base::Value>(*this->sorting_code));

  }
  if (this->country_code.get()) {
    to_value_result->SetWithoutPathExpansion("countryCode", std::make_unique<base::Value>(*this->country_code));

  }
  if (this->phone_numbers.get()) {
    to_value_result->SetWithoutPathExpansion("phoneNumbers", json_schema_compiler::util::CreateValueFromOptionalArray(this->phone_numbers));

  }
  if (this->email_addresses.get()) {
    to_value_result->SetWithoutPathExpansion("emailAddresses", json_schema_compiler::util::CreateValueFromOptionalArray(this->email_addresses));

  }
  if (this->language_code.get()) {
    to_value_result->SetWithoutPathExpansion("languageCode", std::make_unique<base::Value>(*this->language_code));

  }
  if (this->metadata.get()) {
    to_value_result->SetWithoutPathExpansion("metadata", (this->metadata)->ToValue());

  }

  return to_value_result;
}


CountryEntry::CountryEntry()
 {}

CountryEntry::~CountryEntry() {}
CountryEntry::CountryEntry(CountryEntry&& rhs)
: name(std::move(rhs.name)),
country_code(std::move(rhs.country_code)){
}

CountryEntry& CountryEntry::operator=(CountryEntry&& rhs)
{
name = std::move(rhs.name);
country_code = std::move(rhs.country_code);
return *this;
}

// static
bool CountryEntry::Populate(
    const base::Value& value, CountryEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* country_code_value = NULL;
  if (dict->GetWithoutPathExpansion("countryCode", &country_code_value)) {
    {
      std::string temp;
      if (!country_code_value->GetAsString(&temp)) {
        out->country_code.reset();
        return false;
      }
      else
        out->country_code.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<CountryEntry> CountryEntry::FromValue(const base::Value& value) {
  std::unique_ptr<CountryEntry> out(new CountryEntry());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CountryEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(*this->name));

  }
  if (this->country_code.get()) {
    to_value_result->SetWithoutPathExpansion("countryCode", std::make_unique<base::Value>(*this->country_code));

  }

  return to_value_result;
}


AddressComponent::AddressComponent()
: field(ADDRESS_FIELD_NONE),
is_long_field(false) {}

AddressComponent::~AddressComponent() {}
AddressComponent::AddressComponent(AddressComponent&& rhs)
: field(rhs.field),
field_name(std::move(rhs.field_name)),
is_long_field(rhs.is_long_field),
placeholder(std::move(rhs.placeholder)){
}

AddressComponent& AddressComponent::operator=(AddressComponent&& rhs)
{
field = rhs.field;
field_name = std::move(rhs.field_name);
is_long_field = rhs.is_long_field;
placeholder = std::move(rhs.placeholder);
return *this;
}

// static
bool AddressComponent::Populate(
    const base::Value& value, AddressComponent* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* field_value = NULL;
  if (!dict->GetWithoutPathExpansion("field", &field_value)) {
    return false;
  }
  {
    std::string address_field_as_string;
    if (!field_value->GetAsString(&address_field_as_string)) {
      return false;
    }
    out->field = ParseAddressField(address_field_as_string);
    if (out->field == ADDRESS_FIELD_NONE) {
      return false;
    }
  }

  const base::Value* field_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("fieldName", &field_name_value)) {
    return false;
  }
  {
    if (!field_name_value->GetAsString(&out->field_name)) {
      return false;
    }
  }

  const base::Value* is_long_field_value = NULL;
  if (!dict->GetWithoutPathExpansion("isLongField", &is_long_field_value)) {
    return false;
  }
  {
    if (!is_long_field_value->GetAsBoolean(&out->is_long_field)) {
      return false;
    }
  }

  const base::Value* placeholder_value = NULL;
  if (dict->GetWithoutPathExpansion("placeholder", &placeholder_value)) {
    {
      std::string temp;
      if (!placeholder_value->GetAsString(&temp)) {
        out->placeholder.reset();
        return false;
      }
      else
        out->placeholder.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<AddressComponent> AddressComponent::FromValue(const base::Value& value) {
  std::unique_ptr<AddressComponent> out(new AddressComponent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AddressComponent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("field", std::make_unique<base::Value>(autofill_private::ToString(this->field)));

  to_value_result->SetWithoutPathExpansion("fieldName", std::make_unique<base::Value>(this->field_name));

  to_value_result->SetWithoutPathExpansion("isLongField", std::make_unique<base::Value>(this->is_long_field));

  if (this->placeholder.get()) {
    to_value_result->SetWithoutPathExpansion("placeholder", std::make_unique<base::Value>(*this->placeholder));

  }

  return to_value_result;
}


AddressComponentRow::AddressComponentRow()
 {}

AddressComponentRow::~AddressComponentRow() {}
AddressComponentRow::AddressComponentRow(AddressComponentRow&& rhs)
: row(std::move(rhs.row)){
}

AddressComponentRow& AddressComponentRow::operator=(AddressComponentRow&& rhs)
{
row = std::move(rhs.row);
return *this;
}

// static
bool AddressComponentRow::Populate(
    const base::Value& value, AddressComponentRow* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* row_value = NULL;
  if (!dict->GetWithoutPathExpansion("row", &row_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!row_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->row)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<AddressComponentRow> AddressComponentRow::FromValue(const base::Value& value) {
  std::unique_ptr<AddressComponentRow> out(new AddressComponentRow());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AddressComponentRow::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("row", json_schema_compiler::util::CreateValueFromArray(this->row));


  return to_value_result;
}


AddressComponents::AddressComponents()
 {}

AddressComponents::~AddressComponents() {}
AddressComponents::AddressComponents(AddressComponents&& rhs)
: components(std::move(rhs.components)),
language_code(std::move(rhs.language_code)){
}

AddressComponents& AddressComponents::operator=(AddressComponents&& rhs)
{
components = std::move(rhs.components);
language_code = std::move(rhs.language_code);
return *this;
}

// static
bool AddressComponents::Populate(
    const base::Value& value, AddressComponents* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* components_value = NULL;
  if (!dict->GetWithoutPathExpansion("components", &components_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!components_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->components)) {
        return false;
      }
    }
  }

  const base::Value* language_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("languageCode", &language_code_value)) {
    return false;
  }
  {
    if (!language_code_value->GetAsString(&out->language_code)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AddressComponents> AddressComponents::FromValue(const base::Value& value) {
  std::unique_ptr<AddressComponents> out(new AddressComponents());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AddressComponents::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("components", json_schema_compiler::util::CreateValueFromArray(this->components));

  to_value_result->SetWithoutPathExpansion("languageCode", std::make_unique<base::Value>(this->language_code));


  return to_value_result;
}


CreditCardEntry::CreditCardEntry()
 {}

CreditCardEntry::~CreditCardEntry() {}
CreditCardEntry::CreditCardEntry(CreditCardEntry&& rhs)
: guid(std::move(rhs.guid)),
name(std::move(rhs.name)),
card_number(std::move(rhs.card_number)),
expiration_month(std::move(rhs.expiration_month)),
expiration_year(std::move(rhs.expiration_year)),
nickname(std::move(rhs.nickname)),
metadata(std::move(rhs.metadata)){
}

CreditCardEntry& CreditCardEntry::operator=(CreditCardEntry&& rhs)
{
guid = std::move(rhs.guid);
name = std::move(rhs.name);
card_number = std::move(rhs.card_number);
expiration_month = std::move(rhs.expiration_month);
expiration_year = std::move(rhs.expiration_year);
nickname = std::move(rhs.nickname);
metadata = std::move(rhs.metadata);
return *this;
}

// static
bool CreditCardEntry::Populate(
    const base::Value& value, CreditCardEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* guid_value = NULL;
  if (dict->GetWithoutPathExpansion("guid", &guid_value)) {
    {
      std::string temp;
      if (!guid_value->GetAsString(&temp)) {
        out->guid.reset();
        return false;
      }
      else
        out->guid.reset(new std::string(temp));
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* card_number_value = NULL;
  if (dict->GetWithoutPathExpansion("cardNumber", &card_number_value)) {
    {
      std::string temp;
      if (!card_number_value->GetAsString(&temp)) {
        out->card_number.reset();
        return false;
      }
      else
        out->card_number.reset(new std::string(temp));
    }
  }

  const base::Value* expiration_month_value = NULL;
  if (dict->GetWithoutPathExpansion("expirationMonth", &expiration_month_value)) {
    {
      std::string temp;
      if (!expiration_month_value->GetAsString(&temp)) {
        out->expiration_month.reset();
        return false;
      }
      else
        out->expiration_month.reset(new std::string(temp));
    }
  }

  const base::Value* expiration_year_value = NULL;
  if (dict->GetWithoutPathExpansion("expirationYear", &expiration_year_value)) {
    {
      std::string temp;
      if (!expiration_year_value->GetAsString(&temp)) {
        out->expiration_year.reset();
        return false;
      }
      else
        out->expiration_year.reset(new std::string(temp));
    }
  }

  const base::Value* nickname_value = NULL;
  if (dict->GetWithoutPathExpansion("nickname", &nickname_value)) {
    {
      std::string temp;
      if (!nickname_value->GetAsString(&temp)) {
        out->nickname.reset();
        return false;
      }
      else
        out->nickname.reset(new std::string(temp));
    }
  }

  const base::Value* metadata_value = NULL;
  if (dict->GetWithoutPathExpansion("metadata", &metadata_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!metadata_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<AutofillMetadata> temp(new AutofillMetadata());
        if (!AutofillMetadata::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->metadata = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<CreditCardEntry> CreditCardEntry::FromValue(const base::Value& value) {
  std::unique_ptr<CreditCardEntry> out(new CreditCardEntry());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CreditCardEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->guid.get()) {
    to_value_result->SetWithoutPathExpansion("guid", std::make_unique<base::Value>(*this->guid));

  }
  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(*this->name));

  }
  if (this->card_number.get()) {
    to_value_result->SetWithoutPathExpansion("cardNumber", std::make_unique<base::Value>(*this->card_number));

  }
  if (this->expiration_month.get()) {
    to_value_result->SetWithoutPathExpansion("expirationMonth", std::make_unique<base::Value>(*this->expiration_month));

  }
  if (this->expiration_year.get()) {
    to_value_result->SetWithoutPathExpansion("expirationYear", std::make_unique<base::Value>(*this->expiration_year));

  }
  if (this->nickname.get()) {
    to_value_result->SetWithoutPathExpansion("nickname", std::make_unique<base::Value>(*this->nickname));

  }
  if (this->metadata.get()) {
    to_value_result->SetWithoutPathExpansion("metadata", (this->metadata)->ToValue());

  }

  return to_value_result;
}


ValidatePhoneParams::ValidatePhoneParams()
: index_of_new_number(0) {}

ValidatePhoneParams::~ValidatePhoneParams() {}
ValidatePhoneParams::ValidatePhoneParams(ValidatePhoneParams&& rhs)
: phone_numbers(std::move(rhs.phone_numbers)),
index_of_new_number(rhs.index_of_new_number),
country_code(std::move(rhs.country_code)){
}

ValidatePhoneParams& ValidatePhoneParams::operator=(ValidatePhoneParams&& rhs)
{
phone_numbers = std::move(rhs.phone_numbers);
index_of_new_number = rhs.index_of_new_number;
country_code = std::move(rhs.country_code);
return *this;
}

// static
bool ValidatePhoneParams::Populate(
    const base::Value& value, ValidatePhoneParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* phone_numbers_value = NULL;
  if (!dict->GetWithoutPathExpansion("phoneNumbers", &phone_numbers_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!phone_numbers_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->phone_numbers)) {
        return false;
      }
    }
  }

  const base::Value* index_of_new_number_value = NULL;
  if (!dict->GetWithoutPathExpansion("indexOfNewNumber", &index_of_new_number_value)) {
    return false;
  }
  {
    if (!index_of_new_number_value->GetAsInteger(&out->index_of_new_number)) {
      return false;
    }
  }

  const base::Value* country_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("countryCode", &country_code_value)) {
    return false;
  }
  {
    if (!country_code_value->GetAsString(&out->country_code)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ValidatePhoneParams> ValidatePhoneParams::FromValue(const base::Value& value) {
  std::unique_ptr<ValidatePhoneParams> out(new ValidatePhoneParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ValidatePhoneParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("phoneNumbers", json_schema_compiler::util::CreateValueFromArray(this->phone_numbers));

  to_value_result->SetWithoutPathExpansion("indexOfNewNumber", std::make_unique<base::Value>(this->index_of_new_number));

  to_value_result->SetWithoutPathExpansion("countryCode", std::make_unique<base::Value>(this->country_code));


  return to_value_result;
}



//
// Functions
//

namespace SaveAddress {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* address_value = NULL;
  if (args.Get(0, &address_value) &&
      !address_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!address_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!AddressEntry::Populate(*dictionary, &params->address)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SaveAddress

namespace GetCountryList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<CountryEntry>& countries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(countries));

  return create_results;
}
}  // namespace GetCountryList

namespace GetAddressComponents {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* country_code_value = NULL;
  if (args.Get(0, &country_code_value) &&
      !country_code_value->is_none()) {
    {
      if (!country_code_value->GetAsString(&params->country_code)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const AddressComponents& components) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((components).ToValue());

  return create_results;
}
}  // namespace GetAddressComponents

namespace GetAddressList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<AddressEntry>& entries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(entries));

  return create_results;
}
}  // namespace GetAddressList

namespace SaveCreditCard {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* card_value = NULL;
  if (args.Get(0, &card_value) &&
      !card_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!card_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CreditCardEntry::Populate(*dictionary, &params->card)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SaveCreditCard

namespace RemoveEntry {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* guid_value = NULL;
  if (args.Get(0, &guid_value) &&
      !guid_value->is_none()) {
    {
      if (!guid_value->GetAsString(&params->guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RemoveEntry

namespace ValidatePhoneNumbers {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* params_value = NULL;
  if (args.Get(0, &params_value) &&
      !params_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!params_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ValidatePhoneParams::Populate(*dictionary, &params->params)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& validated_phone_numbers) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(validated_phone_numbers));

  return create_results;
}
}  // namespace ValidatePhoneNumbers

namespace GetCreditCardList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<CreditCardEntry>& entries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(entries));

  return create_results;
}
}  // namespace GetCreditCardList

namespace MaskCreditCard {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* guid_value = NULL;
  if (args.Get(0, &guid_value) &&
      !guid_value->is_none()) {
    {
      if (!guid_value->GetAsString(&params->guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace MaskCreditCard

namespace MigrateCreditCards {

}  // namespace MigrateCreditCards

namespace LogServerCardLinkClicked {

}  // namespace LogServerCardLinkClicked

namespace SetCreditCardFIDOAuthEnabledState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetCreditCardFIDOAuthEnabledState

namespace GetUpiIdList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& entries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(entries));

  return create_results;
}
}  // namespace GetUpiIdList

//
// Events
//

namespace OnPersonalDataChanged {

const char kEventName[] = "autofillPrivate.onPersonalDataChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<AddressEntry>& address_entries, const std::vector<CreditCardEntry>& credit_card_entries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(address_entries));

  create_results->Append(json_schema_compiler::util::CreateValueFromArray(credit_card_entries));

  return create_results;
}

}  // namespace OnPersonalDataChanged

}  // namespace autofill_private
}  // namespace api
}  // namespace extensions

