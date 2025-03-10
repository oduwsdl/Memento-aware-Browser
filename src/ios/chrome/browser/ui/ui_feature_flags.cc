// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ios/chrome/browser/ui/ui_feature_flags.h"

const base::Feature kExpandedTabStrip{"ExpandedTabStrip",
                                      base::FEATURE_DISABLED_BY_DEFAULT};

// TODO(crbug.com/945811): Using |-drawViewHierarchyInRect:afterScreenUpdates:|
// has adverse flickering when taking a snapshot of the NTP while in the app
// switcher.
const base::Feature kSnapshotDrawView{"SnapshotDrawView",
                                      base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kSettingsRefresh{"SettingsRefresh",
                                     base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kEmbedderBlockRestoreUrl{"EmbedderBlockRestoreUrl",
                                             base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kDisableProgressBarAnimation{
    "DisableProgressBarAnimation", base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kVoiceOverUnstackedTabstrip{
    "VoiceOverUnstackedTabstrip", base::FEATURE_ENABLED_BY_DEFAULT};

const base::Feature kForceUnstackedTabstrip{"ForceUnstackedTabstrip",
                                            base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kContainedBVC{"ContainedBVC",
                                  base::FEATURE_ENABLED_BY_DEFAULT};

const base::Feature kTestFeature{"TestFeature",
                                 base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kClearSyncedData{"ClearSyncedData",
                                     base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kFirstResponderSendAction{
    "FirstResponderSendAction", base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kNewSigninArchitecture{"NewSigninArchitecture",
                                           base::FEATURE_ENABLED_BY_DEFAULT};

const base::Feature kQRCodeGeneration{"QRCodeGeneration",
                                      base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kEnableNativeContextMenus{
    "EnableNativeContextMenus", base::FEATURE_DISABLED_BY_DEFAULT};

#if defined(__IPHONE_13_4)
const base::Feature kPointerSupport{"PointerSupport",
                                    base::FEATURE_ENABLED_BY_DEFAULT};
#endif  // defined(__IPHONE_13_4)

const base::Feature kEnableMyGoogle{"EnableMyGoogle",
                                    base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kEnableIOSManagedSettingsUI{
    "EnableIOSManagedSettingsUI", base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kSafetyCheckIOS{"SafetyCheckIOS",
                                    base::FEATURE_DISABLED_BY_DEFAULT};

const base::Feature kIllustratedEmptyStates{"IllustratedEmptyStates",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
