// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/language_settings_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_LANGUAGE_SETTINGS_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_LANGUAGE_SETTINGS_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace language_settings_private {

//
// Types
//

enum MoveType {
  MOVE_TYPE_NONE,
  MOVE_TYPE_TOP,
  MOVE_TYPE_UP,
  MOVE_TYPE_DOWN,
  MOVE_TYPE_UNKNOWN,
  MOVE_TYPE_LAST = MOVE_TYPE_UNKNOWN,
};


const char* ToString(MoveType as_enum);
MoveType ParseMoveType(const std::string& as_string);

struct Language {
  Language();
  ~Language();
  Language(Language&& rhs);
  Language& operator=(Language&& rhs);

  // Populates a Language object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Language* out);

  // Creates a Language object from a base::Value, or NULL on failure.
  static std::unique_ptr<Language> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Language object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique code identifying the language.
  std::string code;

  // The name of the language, in the current UI language.
  std::string display_name;

  // The name of the language as it is in its own language.
  std::string native_display_name;

  // Whether the UI can be displayed in this language. Defaults to false.
  std::unique_ptr<bool> supports_ui;

  // Whether this language can be used for spell checking. Defaults to false.
  std::unique_ptr<bool> supports_spellcheck;

  // Whether this language has translations for the current target language.
  // Defaults to false.
  std::unique_ptr<bool> supports_translate;

  // Whether this language is prohibited as a UI locale (not in the list of the
  // 'AllowedLanguages' policy). Defaults to false.
  std::unique_ptr<bool> is_prohibited_language;


 private:
  DISALLOW_COPY_AND_ASSIGN(Language);
};

struct SpellcheckDictionaryStatus {
  SpellcheckDictionaryStatus();
  ~SpellcheckDictionaryStatus();
  SpellcheckDictionaryStatus(SpellcheckDictionaryStatus&& rhs);
  SpellcheckDictionaryStatus& operator=(SpellcheckDictionaryStatus&& rhs);

  // Populates a SpellcheckDictionaryStatus object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, SpellcheckDictionaryStatus* out);

  // Creates a SpellcheckDictionaryStatus object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<SpellcheckDictionaryStatus> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SpellcheckDictionaryStatus object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The language code of the dictionary that the status describes.
  std::string language_code;

  // Whether the dictionary is ready (has been loaded from disk or successfully
  // downloaded).
  bool is_ready;

  // Whether the dictionary is being downloaded. Defaults to false.
  std::unique_ptr<bool> is_downloading;

  // Whether the dictionary download failed. Defaults to false.
  std::unique_ptr<bool> download_failed;


 private:
  DISALLOW_COPY_AND_ASSIGN(SpellcheckDictionaryStatus);
};

struct InputMethod {
  InputMethod();
  ~InputMethod();
  InputMethod(InputMethod&& rhs);
  InputMethod& operator=(InputMethod&& rhs);

  // Populates a InputMethod object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, InputMethod* out);

  // Creates a InputMethod object from a base::Value, or NULL on failure.
  static std::unique_ptr<InputMethod> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InputMethod object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the input method descriptor.
  std::string id;

  // The human-readable name of the input method.
  std::string display_name;

  // The language codes this input method supports.
  std::vector<std::string> language_codes;

  // True if the input method is enabled.
  std::unique_ptr<bool> enabled;

  // True if the input method extension has an options page.
  std::unique_ptr<bool> has_options_page;

  // True if the input method is not allowed by policy.
  std::unique_ptr<bool> is_prohibited_by_policy;


 private:
  DISALLOW_COPY_AND_ASSIGN(InputMethod);
};

struct InputMethodLists {
  InputMethodLists();
  ~InputMethodLists();
  InputMethodLists(InputMethodLists&& rhs);
  InputMethodLists& operator=(InputMethodLists&& rhs);

  // Populates a InputMethodLists object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, InputMethodLists* out);

  // Creates a InputMethodLists object from a base::Value, or NULL on failure.
  static std::unique_ptr<InputMethodLists> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InputMethodLists object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The list of component extension input methods.
  std::vector<InputMethod> component_extension_imes;

  // The list of third-party extension input methods.
  std::vector<InputMethod> third_party_extension_imes;


 private:
  DISALLOW_COPY_AND_ASSIGN(InputMethodLists);
};


//
// Functions
//

namespace GetLanguageList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Language>& languages);
}  // namespace Results

}  // namespace GetLanguageList

namespace EnableLanguage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string language_code;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace EnableLanguage

namespace DisableLanguage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string language_code;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace DisableLanguage

namespace SetEnableTranslationForLanguage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string language_code;

  bool enable;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetEnableTranslationForLanguage

namespace MoveLanguage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string language_code;

  MoveType move_type;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace MoveLanguage

namespace GetSpellcheckDictionaryStatuses {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<SpellcheckDictionaryStatus>& status);
}  // namespace Results

}  // namespace GetSpellcheckDictionaryStatuses

namespace GetSpellcheckWords {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& words);
}  // namespace Results

}  // namespace GetSpellcheckWords

namespace AddSpellcheckWord {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string word;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace AddSpellcheckWord

namespace RemoveSpellcheckWord {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string word;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemoveSpellcheckWord

namespace GetTranslateTargetLanguage {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& language_code);
}  // namespace Results

}  // namespace GetTranslateTargetLanguage

namespace GetInputMethodLists {

namespace Results {

std::unique_ptr<base::ListValue> Create(const InputMethodLists& lists);
}  // namespace Results

}  // namespace GetInputMethodLists

namespace AddInputMethod {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string input_method_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace AddInputMethod

namespace RemoveInputMethod {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string input_method_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemoveInputMethod

namespace RetryDownloadDictionary {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string language_code;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RetryDownloadDictionary

//
// Events
//

namespace OnSpellcheckDictionariesChanged {

extern const char kEventName[];  // "languageSettingsPrivate.onSpellcheckDictionariesChanged"

std::unique_ptr<base::ListValue> Create(const std::vector<SpellcheckDictionaryStatus>& statuses);
}  // namespace OnSpellcheckDictionariesChanged

namespace OnCustomDictionaryChanged {

extern const char kEventName[];  // "languageSettingsPrivate.onCustomDictionaryChanged"

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& words_added, const std::vector<std::string>& words_removed);
}  // namespace OnCustomDictionaryChanged

namespace OnInputMethodAdded {

extern const char kEventName[];  // "languageSettingsPrivate.onInputMethodAdded"

std::unique_ptr<base::ListValue> Create(const std::string& input_method_id);
}  // namespace OnInputMethodAdded

namespace OnInputMethodRemoved {

extern const char kEventName[];  // "languageSettingsPrivate.onInputMethodRemoved"

std::unique_ptr<base::ListValue> Create(const std::string& input_method_id);
}  // namespace OnInputMethodRemoved

}  // namespace language_settings_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_LANGUAGE_SETTINGS_PRIVATE_H__
