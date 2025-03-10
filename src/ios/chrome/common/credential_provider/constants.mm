// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/common/credential_provider/constants.h"

#include <ostream>

#include "base/check.h"
#include "ios/chrome/common/app_group/app_group_constants.h"
#include "ios/chrome/common/ios_app_bundle_id_prefix_buildflags.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

namespace {

// Filename for the archivable storage.
NSString* const kArchivableStorageFilename = @"credential_store";

// Credential Provider dedicated shared folder name.
NSString* const kCredentialProviderContainer = @"credential_provider";

}  // namespace

NSURL* CredentialProviderSharedArchivableStoreURL() {
  NSURL* groupURL = [[NSFileManager defaultManager]
      containerURLForSecurityApplicationGroupIdentifier:app_group::
                                                            ApplicationGroup()];
  NSURL* credentialProviderURL =
      [groupURL URLByAppendingPathComponent:kCredentialProviderContainer];
  return [credentialProviderURL
      URLByAppendingPathComponent:kArchivableStorageFilename];
}

// If an update requires a forced sync, update the version from VN to V(N+1) and
// keep in sync with kUserDefaultsCredentialProviderFirstTimeSyncCompleted.
NSString* const kUserDefaultsCredentialProviderASIdentityStoreSyncCompleted =
    @"UserDefaultsCredentialProviderASIdentityStoreSyncCompleted.V0";

// If an update requires a forced sync, update the version from VN to V(N+1) and
// keep in sync with kUserDefaultsCredentialProviderFirstTimeSyncCompleted.
NSString* const kUserDefaultsCredentialProviderFirstTimeSyncCompleted =
    @"UserDefaultsCredentialProviderFirstTimeSyncCompleted.V0";

NSString* const kUserDefaultsCredentialProviderConsentVerified =
    @"UserDefaultsCredentialProviderConsentVerified";

NSString* const kUserDefaultsCredentialProviderManagedUserID =
    @"kUserDefaultsCredentialProviderManagedUserID";
