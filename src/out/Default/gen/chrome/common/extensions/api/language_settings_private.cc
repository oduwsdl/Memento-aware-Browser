// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/language_settings_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/language_settings_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace language_settings_private {
//
// Types
//

const char* ToString(MoveType enum_param) {
  switch (enum_param) {
    case MOVE_TYPE_TOP:
      return "TOP";
    case MOVE_TYPE_UP:
      return "UP";
    case MOVE_TYPE_DOWN:
      return "DOWN";
    case MOVE_TYPE_UNKNOWN:
      return "UNKNOWN";
    case MOVE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MoveType ParseMoveType(const std::string& enum_string) {
  if (enum_string == "TOP")
    return MOVE_TYPE_TOP;
  if (enum_string == "UP")
    return MOVE_TYPE_UP;
  if (enum_string == "DOWN")
    return MOVE_TYPE_DOWN;
  if (enum_string == "UNKNOWN")
    return MOVE_TYPE_UNKNOWN;
  return MOVE_TYPE_NONE;
}


Language::Language()
 {}

Language::~Language() {}
Language::Language(Language&& rhs)
: code(std::move(rhs.code)),
display_name(std::move(rhs.display_name)),
native_display_name(std::move(rhs.native_display_name)),
supports_ui(std::move(rhs.supports_ui)),
supports_spellcheck(std::move(rhs.supports_spellcheck)),
supports_translate(std::move(rhs.supports_translate)),
is_prohibited_language(std::move(rhs.is_prohibited_language)){
}

Language& Language::operator=(Language&& rhs)
{
code = std::move(rhs.code);
display_name = std::move(rhs.display_name);
native_display_name = std::move(rhs.native_display_name);
supports_ui = std::move(rhs.supports_ui);
supports_spellcheck = std::move(rhs.supports_spellcheck);
supports_translate = std::move(rhs.supports_translate);
is_prohibited_language = std::move(rhs.is_prohibited_language);
return *this;
}

// static
bool Language::Populate(
    const base::Value& value, Language* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* code_value = NULL;
  if (!dict->GetWithoutPathExpansion("code", &code_value)) {
    return false;
  }
  {
    if (!code_value->GetAsString(&out->code)) {
      return false;
    }
  }

  const base::Value* display_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayName", &display_name_value)) {
    return false;
  }
  {
    if (!display_name_value->GetAsString(&out->display_name)) {
      return false;
    }
  }

  const base::Value* native_display_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("nativeDisplayName", &native_display_name_value)) {
    return false;
  }
  {
    if (!native_display_name_value->GetAsString(&out->native_display_name)) {
      return false;
    }
  }

  const base::Value* supports_ui_value = NULL;
  if (dict->GetWithoutPathExpansion("supportsUI", &supports_ui_value)) {
    {
      bool temp;
      if (!supports_ui_value->GetAsBoolean(&temp)) {
        out->supports_ui.reset();
        return false;
      }
      else
        out->supports_ui.reset(new bool(temp));
    }
  }

  const base::Value* supports_spellcheck_value = NULL;
  if (dict->GetWithoutPathExpansion("supportsSpellcheck", &supports_spellcheck_value)) {
    {
      bool temp;
      if (!supports_spellcheck_value->GetAsBoolean(&temp)) {
        out->supports_spellcheck.reset();
        return false;
      }
      else
        out->supports_spellcheck.reset(new bool(temp));
    }
  }

  const base::Value* supports_translate_value = NULL;
  if (dict->GetWithoutPathExpansion("supportsTranslate", &supports_translate_value)) {
    {
      bool temp;
      if (!supports_translate_value->GetAsBoolean(&temp)) {
        out->supports_translate.reset();
        return false;
      }
      else
        out->supports_translate.reset(new bool(temp));
    }
  }

  const base::Value* is_prohibited_language_value = NULL;
  if (dict->GetWithoutPathExpansion("isProhibitedLanguage", &is_prohibited_language_value)) {
    {
      bool temp;
      if (!is_prohibited_language_value->GetAsBoolean(&temp)) {
        out->is_prohibited_language.reset();
        return false;
      }
      else
        out->is_prohibited_language.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Language> Language::FromValue(const base::Value& value) {
  std::unique_ptr<Language> out(new Language());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Language::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("code", std::make_unique<base::Value>(this->code));

  to_value_result->SetWithoutPathExpansion("displayName", std::make_unique<base::Value>(this->display_name));

  to_value_result->SetWithoutPathExpansion("nativeDisplayName", std::make_unique<base::Value>(this->native_display_name));

  if (this->supports_ui.get()) {
    to_value_result->SetWithoutPathExpansion("supportsUI", std::make_unique<base::Value>(*this->supports_ui));

  }
  if (this->supports_spellcheck.get()) {
    to_value_result->SetWithoutPathExpansion("supportsSpellcheck", std::make_unique<base::Value>(*this->supports_spellcheck));

  }
  if (this->supports_translate.get()) {
    to_value_result->SetWithoutPathExpansion("supportsTranslate", std::make_unique<base::Value>(*this->supports_translate));

  }
  if (this->is_prohibited_language.get()) {
    to_value_result->SetWithoutPathExpansion("isProhibitedLanguage", std::make_unique<base::Value>(*this->is_prohibited_language));

  }

  return to_value_result;
}


SpellcheckDictionaryStatus::SpellcheckDictionaryStatus()
: is_ready(false) {}

SpellcheckDictionaryStatus::~SpellcheckDictionaryStatus() {}
SpellcheckDictionaryStatus::SpellcheckDictionaryStatus(SpellcheckDictionaryStatus&& rhs)
: language_code(std::move(rhs.language_code)),
is_ready(rhs.is_ready),
is_downloading(std::move(rhs.is_downloading)),
download_failed(std::move(rhs.download_failed)){
}

SpellcheckDictionaryStatus& SpellcheckDictionaryStatus::operator=(SpellcheckDictionaryStatus&& rhs)
{
language_code = std::move(rhs.language_code);
is_ready = rhs.is_ready;
is_downloading = std::move(rhs.is_downloading);
download_failed = std::move(rhs.download_failed);
return *this;
}

// static
bool SpellcheckDictionaryStatus::Populate(
    const base::Value& value, SpellcheckDictionaryStatus* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* language_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("languageCode", &language_code_value)) {
    return false;
  }
  {
    if (!language_code_value->GetAsString(&out->language_code)) {
      return false;
    }
  }

  const base::Value* is_ready_value = NULL;
  if (!dict->GetWithoutPathExpansion("isReady", &is_ready_value)) {
    return false;
  }
  {
    if (!is_ready_value->GetAsBoolean(&out->is_ready)) {
      return false;
    }
  }

  const base::Value* is_downloading_value = NULL;
  if (dict->GetWithoutPathExpansion("isDownloading", &is_downloading_value)) {
    {
      bool temp;
      if (!is_downloading_value->GetAsBoolean(&temp)) {
        out->is_downloading.reset();
        return false;
      }
      else
        out->is_downloading.reset(new bool(temp));
    }
  }

  const base::Value* download_failed_value = NULL;
  if (dict->GetWithoutPathExpansion("downloadFailed", &download_failed_value)) {
    {
      bool temp;
      if (!download_failed_value->GetAsBoolean(&temp)) {
        out->download_failed.reset();
        return false;
      }
      else
        out->download_failed.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<SpellcheckDictionaryStatus> SpellcheckDictionaryStatus::FromValue(const base::Value& value) {
  std::unique_ptr<SpellcheckDictionaryStatus> out(new SpellcheckDictionaryStatus());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SpellcheckDictionaryStatus::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("languageCode", std::make_unique<base::Value>(this->language_code));

  to_value_result->SetWithoutPathExpansion("isReady", std::make_unique<base::Value>(this->is_ready));

  if (this->is_downloading.get()) {
    to_value_result->SetWithoutPathExpansion("isDownloading", std::make_unique<base::Value>(*this->is_downloading));

  }
  if (this->download_failed.get()) {
    to_value_result->SetWithoutPathExpansion("downloadFailed", std::make_unique<base::Value>(*this->download_failed));

  }

  return to_value_result;
}


InputMethod::InputMethod()
 {}

InputMethod::~InputMethod() {}
InputMethod::InputMethod(InputMethod&& rhs)
: id(std::move(rhs.id)),
display_name(std::move(rhs.display_name)),
language_codes(std::move(rhs.language_codes)),
enabled(std::move(rhs.enabled)),
has_options_page(std::move(rhs.has_options_page)),
is_prohibited_by_policy(std::move(rhs.is_prohibited_by_policy)){
}

InputMethod& InputMethod::operator=(InputMethod&& rhs)
{
id = std::move(rhs.id);
display_name = std::move(rhs.display_name);
language_codes = std::move(rhs.language_codes);
enabled = std::move(rhs.enabled);
has_options_page = std::move(rhs.has_options_page);
is_prohibited_by_policy = std::move(rhs.is_prohibited_by_policy);
return *this;
}

// static
bool InputMethod::Populate(
    const base::Value& value, InputMethod* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* display_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayName", &display_name_value)) {
    return false;
  }
  {
    if (!display_name_value->GetAsString(&out->display_name)) {
      return false;
    }
  }

  const base::Value* language_codes_value = NULL;
  if (!dict->GetWithoutPathExpansion("languageCodes", &language_codes_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!language_codes_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->language_codes)) {
        return false;
      }
    }
  }

  const base::Value* enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("enabled", &enabled_value)) {
    {
      bool temp;
      if (!enabled_value->GetAsBoolean(&temp)) {
        out->enabled.reset();
        return false;
      }
      else
        out->enabled.reset(new bool(temp));
    }
  }

  const base::Value* has_options_page_value = NULL;
  if (dict->GetWithoutPathExpansion("hasOptionsPage", &has_options_page_value)) {
    {
      bool temp;
      if (!has_options_page_value->GetAsBoolean(&temp)) {
        out->has_options_page.reset();
        return false;
      }
      else
        out->has_options_page.reset(new bool(temp));
    }
  }

  const base::Value* is_prohibited_by_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("isProhibitedByPolicy", &is_prohibited_by_policy_value)) {
    {
      bool temp;
      if (!is_prohibited_by_policy_value->GetAsBoolean(&temp)) {
        out->is_prohibited_by_policy.reset();
        return false;
      }
      else
        out->is_prohibited_by_policy.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<InputMethod> InputMethod::FromValue(const base::Value& value) {
  std::unique_ptr<InputMethod> out(new InputMethod());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InputMethod::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("displayName", std::make_unique<base::Value>(this->display_name));

  to_value_result->SetWithoutPathExpansion("languageCodes", json_schema_compiler::util::CreateValueFromArray(this->language_codes));

  if (this->enabled.get()) {
    to_value_result->SetWithoutPathExpansion("enabled", std::make_unique<base::Value>(*this->enabled));

  }
  if (this->has_options_page.get()) {
    to_value_result->SetWithoutPathExpansion("hasOptionsPage", std::make_unique<base::Value>(*this->has_options_page));

  }
  if (this->is_prohibited_by_policy.get()) {
    to_value_result->SetWithoutPathExpansion("isProhibitedByPolicy", std::make_unique<base::Value>(*this->is_prohibited_by_policy));

  }

  return to_value_result;
}


InputMethodLists::InputMethodLists()
 {}

InputMethodLists::~InputMethodLists() {}
InputMethodLists::InputMethodLists(InputMethodLists&& rhs)
: component_extension_imes(std::move(rhs.component_extension_imes)),
third_party_extension_imes(std::move(rhs.third_party_extension_imes)){
}

InputMethodLists& InputMethodLists::operator=(InputMethodLists&& rhs)
{
component_extension_imes = std::move(rhs.component_extension_imes);
third_party_extension_imes = std::move(rhs.third_party_extension_imes);
return *this;
}

// static
bool InputMethodLists::Populate(
    const base::Value& value, InputMethodLists* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* component_extension_imes_value = NULL;
  if (!dict->GetWithoutPathExpansion("componentExtensionImes", &component_extension_imes_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!component_extension_imes_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->component_extension_imes)) {
        return false;
      }
    }
  }

  const base::Value* third_party_extension_imes_value = NULL;
  if (!dict->GetWithoutPathExpansion("thirdPartyExtensionImes", &third_party_extension_imes_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!third_party_extension_imes_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->third_party_extension_imes)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<InputMethodLists> InputMethodLists::FromValue(const base::Value& value) {
  std::unique_ptr<InputMethodLists> out(new InputMethodLists());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InputMethodLists::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("componentExtensionImes", json_schema_compiler::util::CreateValueFromArray(this->component_extension_imes));

  to_value_result->SetWithoutPathExpansion("thirdPartyExtensionImes", json_schema_compiler::util::CreateValueFromArray(this->third_party_extension_imes));


  return to_value_result;
}



//
// Functions
//

namespace GetLanguageList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<Language>& languages) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(languages));

  return create_results;
}
}  // namespace GetLanguageList

namespace EnableLanguage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* language_code_value = NULL;
  if (args.Get(0, &language_code_value) &&
      !language_code_value->is_none()) {
    {
      if (!language_code_value->GetAsString(&params->language_code)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace EnableLanguage

namespace DisableLanguage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* language_code_value = NULL;
  if (args.Get(0, &language_code_value) &&
      !language_code_value->is_none()) {
    {
      if (!language_code_value->GetAsString(&params->language_code)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace DisableLanguage

namespace SetEnableTranslationForLanguage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* language_code_value = NULL;
  if (args.Get(0, &language_code_value) &&
      !language_code_value->is_none()) {
    {
      if (!language_code_value->GetAsString(&params->language_code)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* enable_value = NULL;
  if (args.Get(1, &enable_value) &&
      !enable_value->is_none()) {
    {
      if (!enable_value->GetAsBoolean(&params->enable)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetEnableTranslationForLanguage

namespace MoveLanguage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* language_code_value = NULL;
  if (args.Get(0, &language_code_value) &&
      !language_code_value->is_none()) {
    {
      if (!language_code_value->GetAsString(&params->language_code)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* move_type_value = NULL;
  if (args.Get(1, &move_type_value) &&
      !move_type_value->is_none()) {
    {
      std::string move_type_as_string;
      if (!move_type_value->GetAsString(&move_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->move_type = ParseMoveType(move_type_as_string);
      if (params->move_type == MOVE_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace MoveLanguage

namespace GetSpellcheckDictionaryStatuses {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<SpellcheckDictionaryStatus>& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(status));

  return create_results;
}
}  // namespace GetSpellcheckDictionaryStatuses

namespace GetSpellcheckWords {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& words) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(words));

  return create_results;
}
}  // namespace GetSpellcheckWords

namespace AddSpellcheckWord {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* word_value = NULL;
  if (args.Get(0, &word_value) &&
      !word_value->is_none()) {
    {
      if (!word_value->GetAsString(&params->word)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace AddSpellcheckWord

namespace RemoveSpellcheckWord {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* word_value = NULL;
  if (args.Get(0, &word_value) &&
      !word_value->is_none()) {
    {
      if (!word_value->GetAsString(&params->word)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RemoveSpellcheckWord

namespace GetTranslateTargetLanguage {

std::unique_ptr<base::ListValue> Results::Create(const std::string& language_code) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(language_code));

  return create_results;
}
}  // namespace GetTranslateTargetLanguage

namespace GetInputMethodLists {

std::unique_ptr<base::ListValue> Results::Create(const InputMethodLists& lists) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((lists).ToValue());

  return create_results;
}
}  // namespace GetInputMethodLists

namespace AddInputMethod {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* input_method_id_value = NULL;
  if (args.Get(0, &input_method_id_value) &&
      !input_method_id_value->is_none()) {
    {
      if (!input_method_id_value->GetAsString(&params->input_method_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace AddInputMethod

namespace RemoveInputMethod {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* input_method_id_value = NULL;
  if (args.Get(0, &input_method_id_value) &&
      !input_method_id_value->is_none()) {
    {
      if (!input_method_id_value->GetAsString(&params->input_method_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RemoveInputMethod

namespace RetryDownloadDictionary {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* language_code_value = NULL;
  if (args.Get(0, &language_code_value) &&
      !language_code_value->is_none()) {
    {
      if (!language_code_value->GetAsString(&params->language_code)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RetryDownloadDictionary

//
// Events
//

namespace OnSpellcheckDictionariesChanged {

const char kEventName[] = "languageSettingsPrivate.onSpellcheckDictionariesChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<SpellcheckDictionaryStatus>& statuses) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(statuses));

  return create_results;
}

}  // namespace OnSpellcheckDictionariesChanged

namespace OnCustomDictionaryChanged {

const char kEventName[] = "languageSettingsPrivate.onCustomDictionaryChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& words_added, const std::vector<std::string>& words_removed) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(words_added));

  create_results->Append(json_schema_compiler::util::CreateValueFromArray(words_removed));

  return create_results;
}

}  // namespace OnCustomDictionaryChanged

namespace OnInputMethodAdded {

const char kEventName[] = "languageSettingsPrivate.onInputMethodAdded";

std::unique_ptr<base::ListValue> Create(const std::string& input_method_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(input_method_id));

  return create_results;
}

}  // namespace OnInputMethodAdded

namespace OnInputMethodRemoved {

const char kEventName[] = "languageSettingsPrivate.onInputMethodRemoved";

std::unique_ptr<base::ListValue> Create(const std::string& input_method_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(input_method_id));

  return create_results;
}

}  // namespace OnInputMethodRemoved

}  // namespace language_settings_private
}  // namespace api
}  // namespace extensions

