// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.h.template is used to generate vector_icons.h. Edit the former
// rather than the latter.

#ifndef COMPONENTS_OMNIBOX_BROWSER_VECTOR_ICONS_H_
#define COMPONENTS_OMNIBOX_BROWSER_VECTOR_ICONS_H_

namespace gfx {
struct VectorIcon;
}

#define VECTOR_ICON_TEMPLATE_H(icon_name) \
extern const gfx::VectorIcon icon_name;

namespace omnibox {

VECTOR_ICON_TEMPLATE_H(kTabIcon)
VECTOR_ICON_TEMPLATE_H(kCalculatorIcon)
VECTOR_ICON_TEMPLATE_H(kBlankIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerCalculatorIcon)
VECTOR_ICON_TEMPLATE_H(kChevronIcon)
VECTOR_ICON_TEMPLATE_H(kDriveSheetsIcon)
VECTOR_ICON_TEMPLATE_H(kHttpIcon)
VECTOR_ICON_TEMPLATE_H(kDriveDocsIcon)
VECTOR_ICON_TEMPLATE_H(kDriveVideoIcon)
VECTOR_ICON_TEMPLATE_H(kKeywordSearchIcon)
VECTOR_ICON_TEMPLATE_H(kClockIcon)
VECTOR_ICON_TEMPLATE_H(kBookmarkIcon)
VECTOR_ICON_TEMPLATE_H(kDriveSlidesIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerDictionaryIcon)
VECTOR_ICON_TEMPLATE_H(kDrivePdfIcon)
VECTOR_ICON_TEMPLATE_H(kDriveFolderIcon)
VECTOR_ICON_TEMPLATE_H(kHttpsValidIcon)
VECTOR_ICON_TEMPLATE_H(kHttpsValidInChipIcon)
VECTOR_ICON_TEMPLATE_H(kNotSecureWarningIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerTranslationIcon)
VECTOR_ICON_TEMPLATE_H(kProductIcon)
VECTOR_ICON_TEMPLATE_H(kDriveLogoIcon)
VECTOR_ICON_TEMPLATE_H(kDriveImageIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerDefaultIcon)
VECTOR_ICON_TEMPLATE_H(kPedalIcon)
VECTOR_ICON_TEMPLATE_H(kDriveFormsIcon)
VECTOR_ICON_TEMPLATE_H(kFindInPageIcon)
VECTOR_ICON_TEMPLATE_H(kMementoIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerFinanceIcon)
VECTOR_ICON_TEMPLATE_H(kExtensionAppIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerCurrencyIcon)
VECTOR_ICON_TEMPLATE_H(kStarActiveIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerWhenIsIcon)
VECTOR_ICON_TEMPLATE_H(kPageIcon)
VECTOR_ICON_TEMPLATE_H(kSwitchIcon)
VECTOR_ICON_TEMPLATE_H(kPlusIcon)
VECTOR_ICON_TEMPLATE_H(kOfflinePinIcon)
VECTOR_ICON_TEMPLATE_H(kAnswerSunriseIcon)
VECTOR_ICON_TEMPLATE_H(kStarIcon)
VECTOR_ICON_TEMPLATE_H(kClearIcon)

}

#undef VECTOR_ICON_TEMPLATE_H

#endif  // COMPONENTS_OMNIBOX_BROWSER_VECTOR_ICONS_H_
