// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/webui/settings/chromeos/languages_section.h"

#include "base/feature_list.h"
#include "base/no_destructor.h"
#include "base/strings/utf_string_conversions.h"
#include "chrome/browser/ui/webui/settings/chromeos/os_settings_features_util.h"
#include "chrome/browser/ui/webui/settings/chromeos/search/search_tag_registry.h"
#include "chrome/browser/ui/webui/settings/languages_handler.h"
#include "chrome/browser/ui/webui/webui_util.h"
#include "chrome/common/url_constants.h"
#include "chrome/grit/generated_resources.h"
#include "chromeos/constants/chromeos_features.h"
#include "content/public/browser/web_ui_data_source.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/webui/web_ui_util.h"

namespace chromeos {
namespace settings {
namespace {

const std::vector<SearchConcept>& GetLanguagesSearchConcepts() {
  static const base::NoDestructor<std::vector<SearchConcept>> tags({
      {IDS_OS_SETTINGS_TAG_LANGUAGES_INPUT,
       mojom::kLanguagesAndInputDetailsSubpagePath,
       mojom::SearchResultIcon::kGlobe,
       mojom::SearchResultDefaultRank::kMedium,
       mojom::SearchResultType::kSubpage,
       {.subpage = mojom::Subpage::kLanguagesAndInputDetails}},
      {IDS_OS_SETTINGS_TAG_LANGUAGES_INPUT_METHODS,
       mojom::kManageInputMethodsSubpagePath,
       mojom::SearchResultIcon::kGlobe,
       mojom::SearchResultDefaultRank::kMedium,
       mojom::SearchResultType::kSubpage,
       {.subpage = mojom::Subpage::kManageInputMethods}},
      {IDS_OS_SETTINGS_TAG_LANGUAGES_INPUT_ADD_LANGUAGE,
       mojom::kLanguagesAndInputDetailsSubpagePath,
       mojom::SearchResultIcon::kGlobe,
       mojom::SearchResultDefaultRank::kMedium,
       mojom::SearchResultType::kSetting,
       {.setting = mojom::Setting::kAddLanguage}},
      {IDS_OS_SETTINGS_TAG_LANGUAGES_INPUT_INPUT_OPTIONS_SHELF,
       mojom::kLanguagesAndInputDetailsSubpagePath,
       mojom::SearchResultIcon::kGlobe,
       mojom::SearchResultDefaultRank::kMedium,
       mojom::SearchResultType::kSetting,
       {.setting = mojom::Setting::kShowInputOptionsInShelf},
       {IDS_OS_SETTINGS_TAG_LANGUAGES_INPUT_INPUT_OPTIONS_SHELF_ALT1,
        SearchConcept::kAltTagEnd}},
  });
  return *tags;
}

const std::vector<SearchConcept>& GetSmartInputsSearchConcepts() {
  static const base::NoDestructor<std::vector<SearchConcept>> tags({
      {IDS_OS_SETTINGS_TAG_LANGUAGES_SMART_INPUTS,
       mojom::kSmartInputsSubpagePath,
       mojom::SearchResultIcon::kGlobe,
       mojom::SearchResultDefaultRank::kMedium,
       mojom::SearchResultType::kSubpage,
       {.subpage = mojom::Subpage::kSmartInputs}},
  });
  return *tags;
}

const std::vector<SearchConcept>& GetAssistivePersonalInfoSearchConcepts() {
  static const base::NoDestructor<std::vector<SearchConcept>> tags({
      {IDS_OS_SETTINGS_TAG_LANGUAGES_PERSONAL_INFORMATION_SUGGESTIONS,
       mojom::kSmartInputsSubpagePath,
       mojom::SearchResultIcon::kGlobe,
       mojom::SearchResultDefaultRank::kMedium,
       mojom::SearchResultType::kSetting,
       {.setting = mojom::Setting::kShowPersonalInformationSuggestions}},
  });
  return *tags;
}

const std::vector<SearchConcept>& GetEmojiSuggestionSearchConcepts() {
  static const base::NoDestructor<std::vector<SearchConcept>> tags({
      {IDS_OS_SETTINGS_TAG_LANGUAGES_EMOJI_SUGGESTIONS,
       mojom::kSmartInputsSubpagePath,
       mojom::SearchResultIcon::kGlobe,
       mojom::SearchResultDefaultRank::kMedium,
       mojom::SearchResultType::kSetting,
       {.setting = mojom::Setting::kShowEmojiSuggestions}},
  });
  return *tags;
}

bool IsAssistivePersonalInfoAllowed() {
  return !features::IsGuestModeActive() &&
         base::FeatureList::IsEnabled(
             ::chromeos::features::kAssistPersonalInfo);
}

bool IsEmojiSuggestionAllowed() {
  return base::FeatureList::IsEnabled(
      ::chromeos::features::kEmojiSuggestAddition);
}

void AddSmartInputsStrings(content::WebUIDataSource* html_source) {
  static constexpr webui::LocalizedString kLocalizedStrings[] = {
      {"smartInputsTitle", IDS_SETTINGS_SMART_INPUTS_TITLE},
      {"personalInfoSuggestionTitle",
       IDS_SETTINGS_SMART_INPUTS_PERSONAL_INFO_TITLE},
      {"personalInfoSuggestionDescription",
       IDS_SETTINGS_SMART_INPUTS_PERSONAL_INFO_DESCRIPTION},
      {"showPersonalInfoSuggestion",
       IDS_SETTINGS_SMART_INPUTS_SHOW_PERSONAL_INFO},
      {"managePersonalInfo", IDS_SETTINGS_SMART_INPUTS_MANAGE_PERSONAL_INFO},
      {"emojiSuggestionTitle",
       IDS_SETTINGS_SMART_INPUTS_EMOJI_SUGGESTION_TITLE},
      {"showEmojiSuggestion", IDS_SETTINGS_SMART_INPUTS_SHOW_EMOJI_SUGGESTION},
  };
  AddLocalizedStringsBulk(html_source, kLocalizedStrings);

  html_source->AddBoolean("allowAssistivePersonalInfo",
                          IsAssistivePersonalInfoAllowed());
  html_source->AddBoolean("allowEmojiSuggestion", IsEmojiSuggestionAllowed());
}

}  // namespace

LanguagesSection::LanguagesSection(Profile* profile,
                                   SearchTagRegistry* search_tag_registry)
    : OsSettingsSection(profile, search_tag_registry) {
  registry()->AddSearchTags(GetLanguagesSearchConcepts());

  if (IsAssistivePersonalInfoAllowed() || IsEmojiSuggestionAllowed()) {
    registry()->AddSearchTags(GetSmartInputsSearchConcepts());
    if (IsAssistivePersonalInfoAllowed())
      registry()->AddSearchTags(GetAssistivePersonalInfoSearchConcepts());
    if (IsEmojiSuggestionAllowed())
      registry()->AddSearchTags(GetEmojiSuggestionSearchConcepts());
  }
}

LanguagesSection::~LanguagesSection() = default;

void LanguagesSection::AddLoadTimeData(content::WebUIDataSource* html_source) {
  static constexpr webui::LocalizedString kLocalizedStrings[] = {
      {"orderLanguagesInstructions",
       IDS_SETTINGS_LANGUAGES_LANGUAGES_LIST_ORDERING_INSTRUCTIONS},
      {"osLanguagesPageTitle", IDS_OS_SETTINGS_LANGUAGES_AND_INPUT_PAGE_TITLE},
      {"osLanguagesListTitle", IDS_OS_SETTINGS_LANGUAGES_LIST_TITLE},
      {"inputMethodsListTitle",
       IDS_SETTINGS_LANGUAGES_INPUT_METHODS_LIST_TITLE},
      {"inputMethodEnabled", IDS_SETTINGS_LANGUAGES_INPUT_METHOD_ENABLED},
      {"inputMethodsExpandA11yLabel",
       IDS_SETTINGS_LANGUAGES_INPUT_METHODS_EXPAND_ACCESSIBILITY_LABEL},
      {"inputMethodsManagedbyPolicy",
       IDS_SETTINGS_LANGUAGES_INPUT_METHODS_MANAGED_BY_POLICY},
      {"manageInputMethods", IDS_SETTINGS_LANGUAGES_INPUT_METHODS_MANAGE},
      {"manageInputMethodsPageTitle",
       IDS_SETTINGS_LANGUAGES_MANAGE_INPUT_METHODS_TITLE},
      {"showImeMenu", IDS_SETTINGS_LANGUAGES_SHOW_IME_MENU},
      {"displayLanguageRestart",
       IDS_SETTINGS_LANGUAGES_RESTART_TO_DISPLAY_LANGUAGE},
      {"moveDown", IDS_SETTINGS_LANGUAGES_LANGUAGES_LIST_MOVE_DOWN},
      {"displayInThisLanguage",
       IDS_SETTINGS_LANGUAGES_DISPLAY_IN_THIS_LANGUAGE},
      {"searchLanguages", IDS_SETTINGS_LANGUAGE_SEARCH},
      {"addLanguagesDialogTitle",
       IDS_SETTINGS_LANGUAGES_MANAGE_LANGUAGES_TITLE},
      {"moveToTop", IDS_SETTINGS_LANGUAGES_LANGUAGES_LIST_MOVE_TO_TOP},
      {"isDisplayedInThisLanguage",
       IDS_SETTINGS_LANGUAGES_IS_DISPLAYED_IN_THIS_LANGUAGE},
      {"removeLanguage", IDS_SETTINGS_LANGUAGES_LANGUAGES_LIST_REMOVE},
      {"addLanguages", IDS_SETTINGS_LANGUAGES_LANGUAGES_ADD},
      {"moveUp", IDS_SETTINGS_LANGUAGES_LANGUAGES_LIST_MOVE_UP},
  };
  AddLocalizedStringsBulk(html_source, kLocalizedStrings);
  AddSmartInputsStrings(html_source);

  html_source->AddString(
      "languagesLearnMoreURL",
      base::ASCIIToUTF16(chrome::kLanguageSettingsLearnMoreUrl));
  html_source->AddBoolean("imeOptionsInSettings",
                          base::FeatureList::IsEnabled(
                              ::chromeos::features::kImeOptionsInSettings));
}

void LanguagesSection::AddHandlers(content::WebUI* web_ui) {
  web_ui->AddMessageHandler(
      std::make_unique<::settings::LanguagesHandler>(profile()));
}

int LanguagesSection::GetSectionNameMessageId() const {
  return IDS_OS_SETTINGS_LANGUAGES_AND_INPUT_PAGE_TITLE;
}

mojom::Section LanguagesSection::GetSection() const {
  return mojom::Section::kLanguagesAndInput;
}

mojom::SearchResultIcon LanguagesSection::GetSectionIcon() const {
  return mojom::SearchResultIcon::kGlobe;
}

std::string LanguagesSection::GetSectionPath() const {
  return mojom::kLanguagesAndInputSectionPath;
}

void LanguagesSection::RegisterHierarchy(HierarchyGenerator* generator) const {
  // Languages and input details.
  generator->RegisterTopLevelSubpage(
      IDS_OS_SETTINGS_LANGUAGES_AND_INPUT_PAGE_TITLE,
      mojom::Subpage::kLanguagesAndInputDetails,
      mojom::SearchResultIcon::kGlobe, mojom::SearchResultDefaultRank::kMedium,
      mojom::kLanguagesAndInputDetailsSubpagePath);
  static constexpr mojom::Setting kLanguagesAndInputDetailsSettings[] = {
      mojom::Setting::kAddLanguage,
      mojom::Setting::kShowInputOptionsInShelf,
  };
  RegisterNestedSettingBulk(mojom::Subpage::kLanguagesAndInputDetails,
                            kLanguagesAndInputDetailsSettings, generator);

  // Manage input methods.
  generator->RegisterNestedSubpage(
      IDS_SETTINGS_LANGUAGES_MANAGE_INPUT_METHODS_TITLE,
      mojom::Subpage::kManageInputMethods,
      mojom::Subpage::kLanguagesAndInputDetails,
      mojom::SearchResultIcon::kGlobe, mojom::SearchResultDefaultRank::kMedium,
      mojom::kManageInputMethodsSubpagePath);

  // Input method options.
  generator->RegisterNestedSubpage(
      IDS_SETTINGS_LANGUAGES_INPUT_METHOD_OPTIONS_TITLE,
      mojom::Subpage::kInputMethodOptions,
      mojom::Subpage::kLanguagesAndInputDetails,
      mojom::SearchResultIcon::kGlobe, mojom::SearchResultDefaultRank::kMedium,
      mojom::kInputMethodOptionsSubpagePath);

  // Smart inputs.
  generator->RegisterTopLevelSubpage(
      IDS_SETTINGS_SMART_INPUTS_TITLE, mojom::Subpage::kSmartInputs,
      mojom::SearchResultIcon::kGlobe, mojom::SearchResultDefaultRank::kMedium,
      mojom::kSmartInputsSubpagePath);
  static constexpr mojom::Setting kSmartInputsFeaturesSettings[] = {
      mojom::Setting::kShowPersonalInformationSuggestions,
      mojom::Setting::kShowEmojiSuggestions,
  };
  RegisterNestedSettingBulk(mojom::Subpage::kSmartInputs,
                            kSmartInputsFeaturesSettings, generator);
}

}  // namespace settings
}  // namespace chromeos
