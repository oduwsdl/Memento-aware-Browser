// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_CHROME_BROWSER_UI_UI_FEATURE_FLAGS_H_
#define IOS_CHROME_BROWSER_UI_UI_FEATURE_FLAGS_H_

#include "Availability.h"
#include "base/feature_list.h"

// Feature to open tab switcher after sliding down the toolbar.
extern const base::Feature kExpandedTabStrip;

// Feature to take snapshots using |-drawViewHierarchy:|.
extern const base::Feature kSnapshotDrawView;

// Feature to apply UI Refresh theme to the settings.
extern const base::Feature kSettingsRefresh;

// Feature flag for embedders to block restore urls.
extern const base::Feature kEmbedderBlockRestoreUrl;

// Feature flag disabling progress bar animation.
extern const base::Feature kDisableProgressBarAnimation;

// Feature flag to use the unstacked tabstrip when voiceover is enabled.
extern const base::Feature kVoiceOverUnstackedTabstrip;

// Feature flag to always force an unstacked tabstrip.
extern const base::Feature kForceUnstackedTabstrip;

// Feature flag to have the Browser contained by the TabGrid instead of being
// presented.
extern const base::Feature kContainedBVC;

// Test-only: Feature flag used to verify that EG2 can trigger flags. Must be
// always disabled by default, because it is used to verify that enabling
// features in tests works.
extern const base::Feature kTestFeature;

// Feature flag to display a new option that wipes synced data on a local
// device when signing out from a non-managed account.
extern const base::Feature kClearSyncedData;

// Verify if the crash in https://crbug.com/816427 is fixed on iOS 12.
extern const base::Feature kFirstResponderSendAction;

// Feature flag to enable the new sign-in architecture.
extern const base::Feature kNewSigninArchitecture;

// Feature flag to enable QR code generation for a URL.
extern const base::Feature kQRCodeGeneration;

// Feature flag that enables the native UI Context Menus (not for Web content).
extern const base::Feature kEnableNativeContextMenus;

#if defined(__IPHONE_13_4)
// Feature flag to enable Pointer support on tablets
extern const base::Feature kPointerSupport;
#endif  // defined(__IPHONE_13_4)

// Feature flag to enable MyGoogle account management UI in iOS Settings.
extern const base::Feature kEnableMyGoogle;

// Feature flag to enable showing a different UI when the setting is managed by
// an enterprise policy.
extern const base::Feature kEnableIOSManagedSettingsUI;

// Enables the safety check in settings on iOS.
extern const base::Feature kSafetyCheckIOS;

// Feature flag to enable new illustrations and UI on empty states.
extern const base::Feature kIllustratedEmptyStates;

#endif  // IOS_CHROME_BROWSER_UI_UI_FEATURE_FLAGS_H_
