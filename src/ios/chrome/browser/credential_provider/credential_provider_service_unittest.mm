// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ios/chrome/browser/credential_provider/credential_provider_service.h"

#include "base/files/scoped_temp_dir.h"
#include "base/strings/utf_string_conversions.h"
#import "base/test/ios/wait_util.h"
#include "components/autofill/core/common/password_form.h"
#include "components/password_manager/core/browser/password_store_default.h"
#include "ios/chrome/browser/browser_state/test_chrome_browser_state.h"
#include "ios/chrome/browser/signin/authentication_service_factory.h"
#import "ios/chrome/browser/signin/authentication_service_fake.h"
#include "ios/chrome/common/app_group/app_group_constants.h"
#import "ios/chrome/common/credential_provider/archivable_credential_store.h"
#import "ios/chrome/common/credential_provider/constants.h"
#import "ios/chrome/common/credential_provider/credential.h"
#import "ios/public/provider/chrome/browser/signin/fake_chrome_identity.h"
#import "ios/public/provider/chrome/browser/signin/fake_chrome_identity_service.h"
#include "ios/web/public/test/web_task_environment.h"
#import "testing/gtest_mac.h"
#include "testing/platform_test.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

namespace {

using autofill::PasswordForm;
using base::test::ios::WaitUntilConditionOrTimeout;
using base::test::ios::kWaitForFileOperationTimeout;
using password_manager::PasswordStoreDefault;
using password_manager::LoginDatabase;

class CredentialProviderServiceTest : public PlatformTest {
 public:
  CredentialProviderServiceTest()
      : chrome_browser_state_(TestChromeBrowserState::Builder().Build()) {}

  void SetUp() override {
    PlatformTest::SetUp();
    ASSERT_TRUE(temp_dir_.CreateUniqueTempDir());
    password_store_ = CreatePasswordStore();
    password_store_->Init(nullptr);

    NSUserDefaults* shared_defaults = app_group::GetGroupUserDefaults();
    EXPECT_FALSE([shared_defaults
        boolForKey:kUserDefaultsCredentialProviderFirstTimeSyncCompleted]);

    credential_store_ = [[ArchivableCredentialStore alloc] initWithFileURL:nil];

    TestChromeBrowserState::Builder builder;
    builder.AddTestingFactory(
        AuthenticationServiceFactory::GetInstance(),
        base::BindRepeating(
            &AuthenticationServiceFake::CreateAuthenticationService));
    chrome_browser_state_ = builder.Build();

    auth_service_ = static_cast<AuthenticationServiceFake*>(
        AuthenticationServiceFactory::GetInstance()->GetForBrowserState(
            chrome_browser_state_.get()));

    credential_provider_service_ = std::make_unique<CredentialProviderService>(
        password_store_, auth_service_, credential_store_, nullptr);
  }

  void TearDown() override {
    credential_provider_service_->Shutdown();
    password_store_->ShutdownOnUIThread();
    NSUserDefaults* shared_defaults = app_group::GetGroupUserDefaults();
    [shared_defaults removeObjectForKey:
                         kUserDefaultsCredentialProviderFirstTimeSyncCompleted];
    PlatformTest::TearDown();
  }

  scoped_refptr<PasswordStoreDefault> CreatePasswordStore() {
    return base::MakeRefCounted<PasswordStoreDefault>(
        std::make_unique<LoginDatabase>(
            temp_dir_.GetPath().Append(FILE_PATH_LITERAL("login_test")),
            password_manager::IsAccountStore(false)));
  }

 protected:
  base::ScopedTempDir temp_dir_;
  web::WebTaskEnvironment task_environment_;
  scoped_refptr<PasswordStoreDefault> password_store_;
  ArchivableCredentialStore* credential_store_;
  AuthenticationServiceFake* auth_service_;
  std::unique_ptr<CredentialProviderService> credential_provider_service_;
  std::unique_ptr<TestChromeBrowserState> chrome_browser_state_;

  DISALLOW_COPY_AND_ASSIGN(CredentialProviderServiceTest);
};

// Test that CredentialProviderService can be created.
TEST_F(CredentialProviderServiceTest, Create) {
  EXPECT_TRUE(credential_provider_service_);
}

// Test that CredentialProviderService syncs all the credentials the first time
// it runs.
TEST_F(CredentialProviderServiceTest, FirstSync) {
  EXPECT_TRUE(WaitUntilConditionOrTimeout(kWaitForFileOperationTimeout, ^{
    base::RunLoop().RunUntilIdle();
    return [app_group::GetGroupUserDefaults()
        boolForKey:kUserDefaultsCredentialProviderFirstTimeSyncCompleted];
  }));
}

// Test that CredentialProviderService observes changes in the password store.
TEST_F(CredentialProviderServiceTest, PasswordChanges) {
  EXPECT_EQ(0u, credential_store_.credentials.count);

  PasswordForm form;
  form.url = GURL("http://0.com");
  form.signon_realm = "http://www.example.com/";
  form.action = GURL("http://www.example.com/action");
  form.password_element = base::ASCIIToUTF16("pwd");
  form.password_value = base::ASCIIToUTF16("example");

  password_store_->AddLogin(form);
  task_environment_.RunUntilIdle();

  // Expect the store to be populated with 1 credential.
  ASSERT_EQ(1u, credential_store_.credentials.count);

  NSString* keychainIdentifier =
      credential_store_.credentials.firstObject.keychainIdentifier;
  form.password_value = base::ASCIIToUTF16("secret");

  password_store_->UpdateLogin(form);
  task_environment_.RunUntilIdle();

  // Expect that the credential in the store now has a different keychain
  // identifier.
  id<Credential> credential = credential_store_.credentials.firstObject;
  EXPECT_NSNE(keychainIdentifier, credential.keychainIdentifier);
  ASSERT_EQ(1u, credential_store_.credentials.count);

  password_store_->RemoveLogin(form);
  task_environment_.RunUntilIdle();

  // Expect the store to be empty.
  ASSERT_EQ(0u, credential_store_.credentials.count);
}

// Test that CredentialProviderService observes changes in the primary identity.
TEST_F(CredentialProviderServiceTest, AccountChange) {
  PasswordForm form;
  form.url = GURL("http://0.com");
  form.signon_realm = "http://www.example.com/";
  form.action = GURL("http://www.example.com/action");
  form.password_element = base::ASCIIToUTF16("pwd");
  form.password_value = base::ASCIIToUTF16("example");

  password_store_->AddLogin(form);
  task_environment_.RunUntilIdle();

  EXPECT_FALSE(auth_service_->GetAuthenticatedIdentity());
  EXPECT_FALSE(credential_store_.credentials.firstObject.validationIdentifier);

  ios::FakeChromeIdentityService* identity_service =
      ios::FakeChromeIdentityService::GetInstanceFromChromeProvider();
  identity_service->AddManagedIdentities(@[ @"Name" ]);
  ChromeIdentity* identity =
      identity_service->GetAllIdentitiesSortedForDisplay().firstObject;
  auth_service_->SignIn(identity);

  ASSERT_TRUE(auth_service_->GetAuthenticatedIdentity());
  ASSERT_TRUE(auth_service_->IsAuthenticatedIdentityManaged());

  credential_provider_service_->OnPrimaryAccountSet(CoreAccountInfo());

  ASSERT_TRUE(WaitUntilConditionOrTimeout(kWaitForFileOperationTimeout, ^{
    base::RunLoop().RunUntilIdle();
    return [auth_service_->GetAuthenticatedIdentity().gaiaID
        isEqualToString:credential_store_.credentials.firstObject
                            .validationIdentifier];
  }));

  auth_service_->SignOut(signin_metrics::SIGNOUT_TEST,
                         /*force_clear_browsing_data=*/false, nil);
  credential_provider_service_->OnPrimaryAccountCleared(CoreAccountInfo());

  ASSERT_TRUE(WaitUntilConditionOrTimeout(kWaitForFileOperationTimeout, ^{
    base::RunLoop().RunUntilIdle();
    return ![auth_service_->GetAuthenticatedIdentity().gaiaID
        isEqualToString:credential_store_.credentials.firstObject
                            .validationIdentifier];
  }));
}

}  // namespace
