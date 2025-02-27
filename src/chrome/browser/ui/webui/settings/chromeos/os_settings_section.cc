// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/webui/settings/chromeos/os_settings_section.h"

#include "base/check.h"
#include "base/strings/utf_string_conversions.h"
#include "base/system/sys_info.h"
#include "chrome/grit/generated_resources.h"
#include "ui/base/l10n/l10n_util.h"

namespace chromeos {
namespace settings {

// static
base::string16 OsSettingsSection::GetHelpUrlWithBoard(
    const std::string& original_url) {
  return base::ASCIIToUTF16(original_url +
                            "&b=" + base::SysInfo::GetLsbReleaseBoard());
}

// static
void OsSettingsSection::RegisterNestedSettingBulk(
    mojom::Subpage subpage,
    const base::span<const mojom::Setting>& settings,
    HierarchyGenerator* generator) {
  for (const auto& setting : settings)
    generator->RegisterNestedSetting(setting, subpage);
}

OsSettingsSection::~OsSettingsSection() = default;

OsSettingsSection::OsSettingsSection(Profile* profile,
                                     SearchTagRegistry* search_tag_registry)
    : profile_(profile), search_tag_registry_(search_tag_registry) {
  DCHECK(profile);
  DCHECK(search_tag_registry);
}

OsSettingsSection::OsSettingsSection() = default;

std::string OsSettingsSection::ModifySearchResultUrl(
    mojom::SearchResultType type,
    OsSettingsIdentifier id,
    const std::string& url_to_modify) const {
  // Default case for static URLs which do not need to be modified.
  return url_to_modify;
}

mojom::SearchResultPtr OsSettingsSection::GenerateSectionSearchResult(
    double relevance_score) const {
  return mojom::SearchResult::New(
      /*result_text=*/l10n_util::GetStringUTF16(GetSectionNameMessageId()),
      /*canonical_result_text=*/
      l10n_util::GetStringUTF16(GetSectionNameMessageId()),
      ModifySearchResultUrl(mojom::SearchResultType::kSection,
                            {.section = GetSection()}, GetSectionPath()),
      GetSectionIcon(), relevance_score,
      std::vector<base::string16>{
          l10n_util::GetStringUTF16(IDS_INTERNAL_APP_SETTINGS),
          l10n_util::GetStringUTF16(GetSectionNameMessageId())},
      mojom::SearchResultDefaultRank::kMedium,
      mojom::SearchResultType::kSection,
      mojom::SearchResultIdentifier::NewSection(GetSection()));
}

}  // namespace settings
}  // namespace chromeos
