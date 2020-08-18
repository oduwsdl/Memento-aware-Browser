// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/autofill_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_AUTOFILL_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_AUTOFILL_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace autofill_private {

//
// Types
//

// Fields used as part of an address.
enum AddressField {
  ADDRESS_FIELD_NONE,
  ADDRESS_FIELD_FULL_NAME,
  ADDRESS_FIELD_COMPANY_NAME,
  ADDRESS_FIELD_ADDRESS_LINES,
  ADDRESS_FIELD_ADDRESS_LEVEL_1,
  ADDRESS_FIELD_ADDRESS_LEVEL_2,
  ADDRESS_FIELD_ADDRESS_LEVEL_3,
  ADDRESS_FIELD_POSTAL_CODE,
  ADDRESS_FIELD_SORTING_CODE,
  ADDRESS_FIELD_COUNTRY_CODE,
  ADDRESS_FIELD_LAST = ADDRESS_FIELD_COUNTRY_CODE,
};


const char* ToString(AddressField as_enum);
AddressField ParseAddressField(const std::string& as_string);

struct AutofillMetadata {
  AutofillMetadata();
  ~AutofillMetadata();
  AutofillMetadata(AutofillMetadata&& rhs);
  AutofillMetadata& operator=(AutofillMetadata&& rhs);

  // Populates a AutofillMetadata object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AutofillMetadata* out);

  // Creates a AutofillMetadata object from a base::Value, or NULL on failure.
  static std::unique_ptr<AutofillMetadata> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AutofillMetadata object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Short summary of the address which is displayed in the UI; an undefined value
  // means that this entry has just been created on the client and has not yet
  // been given a summary.
  std::string summary_label;

  // Short, secondary summary of the address which is displalyed in the UI; an
  // undefined value means that this entry has just been created on the client and
  // has not yet been given a summary.
  std::unique_ptr<std::string> summary_sublabel;

  // Whether the entry is locally owned by Chrome (as opposed to being a profile
  // synced down from the server). Non-local entries may not be editable.
  std::unique_ptr<bool> is_local;

  // For credit cards, whether this is a full copy of the card
  std::unique_ptr<bool> is_cached;

  // For credit cards, whether this is migratable (both the card number and
  // expiration date valid and does not have the duplicated server card).
  std::unique_ptr<bool> is_migratable;


 private:
  DISALLOW_COPY_AND_ASSIGN(AutofillMetadata);
};

struct AddressEntry {
  AddressEntry();
  ~AddressEntry();
  AddressEntry(AddressEntry&& rhs);
  AddressEntry& operator=(AddressEntry&& rhs);

  // Populates a AddressEntry object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AddressEntry* out);

  // Creates a AddressEntry object from a base::Value, or NULL on failure.
  static std::unique_ptr<AddressEntry> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AddressEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Globally unique identifier for this entry.
  std::unique_ptr<std::string> guid;

  std::unique_ptr<std::vector<std::string>> full_names;

  std::unique_ptr<std::string> company_name;

  // Street address (multiple lines, newlines preserved).
  std::unique_ptr<std::string> address_lines;

  // The broadest administrative level in the address, i.e. the province within
  // which the locality is found; for example, in the US, this would be the state;
  // in Switzerland it would be the canton; in the UK, the post town.
  std::unique_ptr<std::string> address_level1;

  // The second administrative level, in addresses with two or more administrative
  // levels; in the countries with two administrative levels, this would typically
  // be the city, town, village, or other locality within which the relevant
  // street address is found.
  std::unique_ptr<std::string> address_level2;

  // The third administrative level, in addresses with three or more
  // administrative levels.
  std::unique_ptr<std::string> address_level3;

  // Postal code, post code, ZIP code, CEDEX code (if CEDEX, append "CEDEX", and
  // the arrondissement, if relevant, to the address-level2 field).
  std::unique_ptr<std::string> postal_code;

  // A sorting code is similar to a postal code. However, whereas a postal code
  // normally refers to a single geographical location, a sorting code often does
  // not. Instead, a sorting code is assigned to an organization, which might be
  // geographically distributed. The most prominent example of a sorting code
  // system is CEDEX in France.
  std::unique_ptr<std::string> sorting_code;

  // A two-character string representing the address' country. See
  // autofill_country.cc for a list of valid codes.
  std::unique_ptr<std::string> country_code;

  std::unique_ptr<std::vector<std::string>> phone_numbers;

  std::unique_ptr<std::vector<std::string>> email_addresses;

  std::unique_ptr<std::string> language_code;

  std::unique_ptr<AutofillMetadata> metadata;


 private:
  DISALLOW_COPY_AND_ASSIGN(AddressEntry);
};

struct CountryEntry {
  CountryEntry();
  ~CountryEntry();
  CountryEntry(CountryEntry&& rhs);
  CountryEntry& operator=(CountryEntry&& rhs);

  // Populates a CountryEntry object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, CountryEntry* out);

  // Creates a CountryEntry object from a base::Value, or NULL on failure.
  static std::unique_ptr<CountryEntry> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CountryEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The internationalized name of the country.
  std::unique_ptr<std::string> name;

  // A two-character string representing the country.
  std::unique_ptr<std::string> country_code;


 private:
  DISALLOW_COPY_AND_ASSIGN(CountryEntry);
};

struct AddressComponent {
  AddressComponent();
  ~AddressComponent();
  AddressComponent(AddressComponent&& rhs);
  AddressComponent& operator=(AddressComponent&& rhs);

  // Populates a AddressComponent object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AddressComponent* out);

  // Creates a AddressComponent object from a base::Value, or NULL on failure.
  static std::unique_ptr<AddressComponent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AddressComponent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The field type.
  AddressField field;

  // The name of the field.
  std::string field_name;

  // A hint for the UI regarding whether the input is likely to be long.
  bool is_long_field;

  // A placeholder for the text field to be used when the user has not yet input a
  // value for the field.
  std::unique_ptr<std::string> placeholder;


 private:
  DISALLOW_COPY_AND_ASSIGN(AddressComponent);
};

struct AddressComponentRow {
  AddressComponentRow();
  ~AddressComponentRow();
  AddressComponentRow(AddressComponentRow&& rhs);
  AddressComponentRow& operator=(AddressComponentRow&& rhs);

  // Populates a AddressComponentRow object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AddressComponentRow* out);

  // Creates a AddressComponentRow object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<AddressComponentRow> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AddressComponentRow object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::vector<AddressComponent> row;


 private:
  DISALLOW_COPY_AND_ASSIGN(AddressComponentRow);
};

struct AddressComponents {
  AddressComponents();
  ~AddressComponents();
  AddressComponents(AddressComponents&& rhs);
  AddressComponents& operator=(AddressComponents&& rhs);

  // Populates a AddressComponents object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AddressComponents* out);

  // Creates a AddressComponents object from a base::Value, or NULL on failure.
  static std::unique_ptr<AddressComponents> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AddressComponents object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The components.
  std::vector<AddressComponentRow> components;

  // The language code.
  std::string language_code;


 private:
  DISALLOW_COPY_AND_ASSIGN(AddressComponents);
};

struct CreditCardEntry {
  CreditCardEntry();
  ~CreditCardEntry();
  CreditCardEntry(CreditCardEntry&& rhs);
  CreditCardEntry& operator=(CreditCardEntry&& rhs);

  // Populates a CreditCardEntry object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, CreditCardEntry* out);

  // Creates a CreditCardEntry object from a base::Value, or NULL on failure.
  static std::unique_ptr<CreditCardEntry> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CreditCardEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Globally unique identifier for this entry.
  std::unique_ptr<std::string> guid;

  // Name of the person who owns the credit card.
  std::unique_ptr<std::string> name;

  // Credit card number.
  std::unique_ptr<std::string> card_number;

  // Month as 2-character string ("01" = January, "12" = December).
  std::unique_ptr<std::string> expiration_month;

  // Year as a 4-character string (as in "2015").
  std::unique_ptr<std::string> expiration_year;

  // Credit card's nickname.
  std::unique_ptr<std::string> nickname;

  std::unique_ptr<AutofillMetadata> metadata;


 private:
  DISALLOW_COPY_AND_ASSIGN(CreditCardEntry);
};

struct ValidatePhoneParams {
  ValidatePhoneParams();
  ~ValidatePhoneParams();
  ValidatePhoneParams(ValidatePhoneParams&& rhs);
  ValidatePhoneParams& operator=(ValidatePhoneParams&& rhs);

  // Populates a ValidatePhoneParams object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ValidatePhoneParams* out);

  // Creates a ValidatePhoneParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ValidatePhoneParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ValidatePhoneParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The phone numbers to validate.
  std::vector<std::string> phone_numbers;

  // The index into |phoneNumbers| at which the newly-added/edited phone number
  // resides.
  int index_of_new_number;

  // A two-character string representing the address' country. See
  // autofill_country.cc for a list of valid codes.
  std::string country_code;


 private:
  DISALLOW_COPY_AND_ASSIGN(ValidatePhoneParams);
};


//
// Functions
//

namespace SaveAddress {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The address entry to save.
  AddressEntry address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SaveAddress

namespace GetCountryList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<CountryEntry>& countries);
}  // namespace Results

}  // namespace GetCountryList

namespace GetAddressComponents {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A two-character string representing the address' country     whose components
  // should be returned. See autofill_country.cc for a     list of valid codes.
  std::string country_code;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const AddressComponents& components);
}  // namespace Results

}  // namespace GetAddressComponents

namespace GetAddressList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<AddressEntry>& entries);
}  // namespace Results

}  // namespace GetAddressList

namespace SaveCreditCard {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The card entry to save.
  CreditCardEntry card;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SaveCreditCard

namespace RemoveEntry {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // ID of the entry to remove.
  std::string guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemoveEntry

namespace ValidatePhoneNumbers {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The parameters to this function.
  ValidatePhoneParams params;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& validated_phone_numbers);
}  // namespace Results

}  // namespace ValidatePhoneNumbers

namespace GetCreditCardList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<CreditCardEntry>& entries);
}  // namespace Results

}  // namespace GetCreditCardList

namespace MaskCreditCard {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // GUID of the credit card to mask.
  std::string guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace MaskCreditCard

namespace MigrateCreditCards {

}  // namespace MigrateCreditCards

namespace LogServerCardLinkClicked {

}  // namespace LogServerCardLinkClicked

namespace SetCreditCardFIDOAuthEnabledState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetCreditCardFIDOAuthEnabledState

namespace GetUpiIdList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& entries);
}  // namespace Results

}  // namespace GetUpiIdList

//
// Events
//

namespace OnPersonalDataChanged {

extern const char kEventName[];  // "autofillPrivate.onPersonalDataChanged"

std::unique_ptr<base::ListValue> Create(const std::vector<AddressEntry>& address_entries, const std::vector<CreditCardEntry>& credit_card_entries);
}  // namespace OnPersonalDataChanged

}  // namespace autofill_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_AUTOFILL_PRIVATE_H__
