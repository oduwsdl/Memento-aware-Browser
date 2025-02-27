// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/login/test/active_directory_login_mixin.h"

#include <initializer_list>

#include "ash/public/cpp/login_screen_test_api.h"
#include "base/strings/string_piece.h"
#include "chrome/browser/chromeos/login/test/js_checker.h"
#include "chrome/browser/chromeos/login/test/oobe_screen_waiter.h"
#include "chrome/browser/chromeos/login/ui/login_display_host.h"
#include "chrome/browser/ui/webui/chromeos/login/gaia_screen_handler.h"
#include "chrome/browser/ui/webui/chromeos/login/oobe_ui.h"
#include "chrome/browser/ui/webui/chromeos/login/signin_screen_handler.h"
#include "chromeos/dbus/authpolicy/fake_authpolicy_client.h"
#include "content/public/test/browser_test_utils.h"

namespace chromeos {

namespace {

constexpr char kGaiaSigninId[] = "gaia-signin";
constexpr char kAdOfflineAuthId[] = "offline-ad-auth";
constexpr char kPasswordChangeId[] = "active-directory-password-change";
constexpr char kAdOldPasswordInput[] = "oldPassword";
constexpr char kAdNewPassword1Input[] = "newPassword";
constexpr char kAdNewPassword2Input[] = "newPasswordRepeat";

const test::UIPath kGaiaSigninDialogId = {kGaiaSigninId, "signin-frame-dialog"};
const test::UIPath kAdMachineInput = {kGaiaSigninId, kAdOfflineAuthId,
                                      "machineNameInput"};
const test::UIPath kAdMoreOptionsButton = {kGaiaSigninId, kAdOfflineAuthId,
                                           "moreOptionsBtn"};
const test::UIPath kAdUserInput = {kGaiaSigninId, kAdOfflineAuthId,
                                   "userInput"};
const test::UIPath kAdPasswordInput = {kGaiaSigninId, kAdOfflineAuthId,
                                       "passwordInput"};
const test::UIPath kAdCredsButton = {kGaiaSigninId, kAdOfflineAuthId,
                                     "nextButton"};
const test::UIPath kAdAutocompleteRealm = {kGaiaSigninId, kAdOfflineAuthId,
                                           "userRealm"};

const test::UIPath kAdAnimatedPages = {kPasswordChangeId, "animatedPages"};
const test::UIPath kFormButtonId = {kPasswordChangeId, "inputForm", "button"};
const test::UIPath kCloseButtonId = {kPasswordChangeId, "navigation",
                                     "closeButton"};
const test::UIPath kAdOldPasswordInputPath = {kPasswordChangeId,
                                              kAdOldPasswordInput};
const test::UIPath kAdNewPassword1InputPath = {kPasswordChangeId,
                                               kAdNewPassword1Input};
const test::UIPath kAdNewPassword2InputPath = {kPasswordChangeId,
                                               kAdNewPassword2Input};

}  // namespace

ActiveDirectoryLoginMixin::ActiveDirectoryLoginMixin(
    InProcessBrowserTestMixinHost* host)
    : InProcessBrowserTestMixin(host) {}

void ActiveDirectoryLoginMixin::SetUpInProcessBrowserTestFixture() {
  AuthPolicyClient::InitializeFake();
  FakeAuthPolicyClient::Get()->DisableOperationDelayForTesting();
}

void ActiveDirectoryLoginMixin::SetUpOnMainThread() {
  // Set the threshold to a max value to disable the offline message screen on
  // slow configurations like MSAN, where it otherwise triggers on every run.
  LoginDisplayHost::default_host()
      ->GetOobeUI()
      ->signin_screen_handler()
      ->SetOfflineTimeoutForTesting(base::TimeDelta::Max());

  message_queue_ = std::make_unique<content::DOMMessageQueue>();
  SetupActiveDirectoryJSNotifications();
}

void ActiveDirectoryLoginMixin::TriggerPasswordChangeScreen() {
  OobeScreenWaiter screen_waiter(
      OobeScreen::SCREEN_ACTIVE_DIRECTORY_PASSWORD_CHANGE);

  FakeAuthPolicyClient::Get()->set_auth_error(
      authpolicy::ERROR_PASSWORD_EXPIRED);
  SubmitActiveDirectoryCredentials("any_user@any_realm", "any_password");
  screen_waiter.Wait();
  TestPasswordChangeNoErrors();
}

void ActiveDirectoryLoginMixin::ClosePasswordChangeScreen() {
  test::OobeJS().TapOnPath(kCloseButtonId);
}

// Checks if Active Directory login is visible.
void ActiveDirectoryLoginMixin::TestLoginVisible() {
  OobeScreenWaiter screen_waiter(GaiaView::kScreenId);
  screen_waiter.Wait();

  // Wait for the Active Directory signin visible.
  std::initializer_list<base::StringPiece> ad_screen{kGaiaSigninId,
                                                     kAdOfflineAuthId};
  test::OobeJS().CreateVisibilityWaiter(true, ad_screen)->Wait();

  // Checks if Gaia signin is hidden.
  test::OobeJS().ExpectHiddenPath(kGaiaSigninDialogId);

  test::OobeJS().ExpectPathDisplayed(true, ad_screen);
  test::OobeJS().ExpectHiddenPath(kAdMachineInput);
  test::OobeJS().ExpectHiddenPath(kAdMoreOptionsButton);
  test::OobeJS().ExpectVisiblePath(kAdUserInput);
  test::OobeJS().ExpectVisiblePath(kAdPasswordInput);

  test::OobeJS().ExpectElementText(autocomplete_realm_, kAdAutocompleteRealm);

  EXPECT_TRUE(ash::LoginScreenTestApi::IsLoginShelfShown());
}

// Checks if Active Directory password change screen is shown.
void ActiveDirectoryLoginMixin::TestPasswordChangeVisible() {
  // Checks if Gaia signin is hidden.
  test::OobeJS().ExpectHiddenPath(kGaiaSigninDialogId);
  // Checks if Active Directory signin is visible.
  test::OobeJS().ExpectVisible(kPasswordChangeId);
  test::OobeJS().ExpectTrue(test::GetOobeElementPath(kAdAnimatedPages) +
                            ".selected == 0");
  test::OobeJS().ExpectVisiblePath(kCloseButtonId);
}

// Checks if user input is marked as invalid.
void ActiveDirectoryLoginMixin::TestUserError() {
  TestLoginVisible();
  test::OobeJS().ExpectInvalidPath(kAdUserInput);
}

void ActiveDirectoryLoginMixin::SetUserInput(const std::string& value) {
  test::OobeJS().TypeIntoPath(value, kAdUserInput);
}

void ActiveDirectoryLoginMixin::TestUserInput(const std::string& value) {
  test::OobeJS().ExpectElementValue(value, kAdUserInput);
}

// Checks if password input is marked as invalid.
void ActiveDirectoryLoginMixin::TestPasswordError() {
  TestLoginVisible();
  test::OobeJS().ExpectInvalidPath(kAdPasswordInput);
}

// Checks that machine, password and user inputs are valid.
void ActiveDirectoryLoginMixin::TestNoError() {
  TestLoginVisible();
  test::OobeJS().ExpectValidPath(kAdMachineInput);
  test::OobeJS().ExpectValidPath(kAdUserInput);
  test::OobeJS().ExpectValidPath(kAdPasswordInput);
}

// Checks if autocomplete domain is visible for the user input.
void ActiveDirectoryLoginMixin::TestDomainVisible() {
  test::OobeJS().ExpectVisiblePath(kAdAutocompleteRealm);
}

// Checks if autocomplete domain is hidden for the user input.
void ActiveDirectoryLoginMixin::TestDomainHidden() {
  test::OobeJS().ExpectHiddenPath(kAdAutocompleteRealm);
}

void ActiveDirectoryLoginMixin::TestPasswordChangeNoErrors() {
  TestPasswordChangeError("");
}

void ActiveDirectoryLoginMixin::TestPasswordChangeOldPasswordError() {
  TestPasswordChangeError(kAdOldPasswordInput);
}

void ActiveDirectoryLoginMixin::TestPasswordChangeNewPasswordError() {
  TestPasswordChangeError(kAdNewPassword1Input);
}

void ActiveDirectoryLoginMixin::TestPasswordChangeConfirmNewPasswordError() {
  TestPasswordChangeError(kAdNewPassword2Input);
}

// Checks if Active Directory password change screen is shown. Also checks if
// |invalid_element| is invalidated and all the other elements are valid.
void ActiveDirectoryLoginMixin::TestPasswordChangeError(
    const std::string& invalid_element) {
  TestPasswordChangeVisible();
  for (const char* element :
       {kAdOldPasswordInput, kAdNewPassword1Input, kAdNewPassword2Input}) {
    if (element != invalid_element)
      test::OobeJS().ExpectValidPath({kPasswordChangeId, element});
    else
      test::OobeJS().ExpectInvalidPath({kPasswordChangeId, element});
  }
}

// Sets username and password for the Active Directory login and submits it.
void ActiveDirectoryLoginMixin::SubmitActiveDirectoryCredentials(
    const std::string& username,
    const std::string& password) {
  test::OobeJS().TypeIntoPath(username, kAdUserInput);
  test::OobeJS().TypeIntoPath(password, kAdPasswordInput);
  test::OobeJS().ClickOnPath(kAdCredsButton);
}

// Sets username and password for the Active Directory login and submits it.
void ActiveDirectoryLoginMixin::SubmitActiveDirectoryPasswordChangeCredentials(
    const std::string& old_password,
    const std::string& new_password1,
    const std::string& new_password2) {
  test::OobeJS().TypeIntoPath(old_password, kAdOldPasswordInputPath);
  test::OobeJS().TypeIntoPath(new_password1, kAdNewPassword1InputPath);
  test::OobeJS().TypeIntoPath(new_password2, kAdNewPassword2InputPath);
  test::OobeJS().ClickOnPath(kFormButtonId);
}

void ActiveDirectoryLoginMixin::SetupActiveDirectoryJSNotifications() {
  test::OobeJS().Evaluate(
      "var testInvalidateAd = login.GaiaSigninScreen.invalidateAd;"
      "login.GaiaSigninScreen.invalidateAd = function(user, errorState) {"
      "  testInvalidateAd(user, errorState);"
      "  window.domAutomationController.send('ShowAuthError');"
      "}");
}

void ActiveDirectoryLoginMixin::WaitForAuthError() {
  const std::string& expected_message = "\"ShowAuthError\"";
  std::string message;
  do {
    ASSERT_TRUE(message_queue_->WaitForMessage(&message));
  } while (message != expected_message);
}

ActiveDirectoryLoginMixin::~ActiveDirectoryLoginMixin() = default;

}  // namespace chromeos
