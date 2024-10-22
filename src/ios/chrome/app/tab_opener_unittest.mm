// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <Foundation/Foundation.h>

#include "base/threading/thread.h"
#import "ios/chrome/app/application_delegate/app_state.h"
#include "ios/chrome/app/application_delegate/startup_information.h"
#import "ios/chrome/app/application_delegate/tab_opening.h"
#import "ios/chrome/app/application_delegate/url_opener.h"
#import "ios/chrome/app/application_delegate/url_opener_params.h"
#import "ios/chrome/browser/ui/main/scene_controller.h"
#import "ios/chrome/browser/ui/main/scene_state.h"
#import "ios/testing/scoped_block_swizzler.h"
#include "testing/platform_test.h"
#import "third_party/ocmock/OCMock/OCMock.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

namespace {

// A block that takes the arguments of
// +handleLaunchOptions:applicationActive:tabOpener:startupInformation: and
// returns nothing.
typedef void (^HandleLaunchOptions)(id self,
                                    NSDictionary* options,
                                    BOOL applicationActive,
                                    id<TabOpening> tabOpener,
                                    id<StartupInformation> startupInformation,
                                    AppState* appState);

class TabOpenerTest : public PlatformTest {
 protected:
  void TearDown() override {
    PlatformTest::TearDown();
  }

  BOOL swizzleHasBeenCalled() { return swizzle_block_executed_; }

  void swizzleHandleLaunchOptions(
      URLOpenerParams* expectedParams,
      id<StartupInformation> expectedStartupInformation,
      AppState* expectedAppState) {
    swizzle_block_executed_ = NO;
    swizzle_block_ =
        [^(id self, URLOpenerParams* params, BOOL applicationActive,
           id<TabOpening> tabOpener, id<StartupInformation> startupInformation,
           AppState* appState) {
          swizzle_block_executed_ = YES;
          EXPECT_EQ(expectedParams, params);
          EXPECT_EQ(expectedStartupInformation, startupInformation);
          EXPECT_EQ(scene_controller_, tabOpener);
          EXPECT_EQ(expectedAppState, appState);
        } copy];
    URL_opening_handle_launch_swizzler_.reset(new ScopedBlockSwizzler(
        [URLOpener class],
        @selector(handleLaunchOptions:applicationActive:tabOpener
                                     :startupInformation:appState:),
        swizzle_block_));
  }

  SceneController* GetSceneController() {
    if (!scene_controller_) {
      scene_controller_ =
          [[SceneController alloc] initWithSceneState:scene_state_];
    }
    return scene_controller_;
  }

 private:
  SceneController* scene_controller_;
  SceneState* scene_state_;

  __block BOOL swizzle_block_executed_;
  HandleLaunchOptions swizzle_block_;
  std::unique_ptr<ScopedBlockSwizzler> URL_opening_handle_launch_swizzler_;
};

#pragma mark - Tests.

// Tests that -newTabFromLaunchOptions calls +handleLaunchOption and reset
// options.
TEST_F(TabOpenerTest, openTabFromLaunchWithParamsWithOptions) {
  // Setup.
  NSString* sourceApplication = @"com.apple.mobilesafari";
  URLOpenerParams* params =
      [[URLOpenerParams alloc] initWithURL:nil
                         sourceApplication:sourceApplication];

  id startupInformationMock =
      [OCMockObject mockForProtocol:@protocol(StartupInformation)];
  id appStateMock = [OCMockObject mockForClass:[AppState class]];

  swizzleHandleLaunchOptions(params, startupInformationMock, appStateMock);

  id<TabOpening> tabOpener = GetSceneController();

  // Action.
  [tabOpener openTabFromLaunchWithParams:params
                      startupInformation:startupInformationMock
                                appState:appStateMock];

  // Test.
  EXPECT_TRUE(swizzleHasBeenCalled());
}

// Tests that -newTabFromLaunchOptions do nothing if launchOptions is nil.
TEST_F(TabOpenerTest, openTabFromLaunchWithParamsWithNil) {
  // Setup.
  id startupInformationMock =
      [OCMockObject mockForProtocol:@protocol(StartupInformation)];
  id appStateMock = [OCMockObject mockForClass:[AppState class]];

  swizzleHandleLaunchOptions(nil, startupInformationMock, appStateMock);

  id<TabOpening> tabOpener = GetSceneController();

  // Action.
  [tabOpener openTabFromLaunchWithParams:nil
                      startupInformation:startupInformationMock
                                appState:appStateMock];

  // Test.
  EXPECT_FALSE(swizzleHasBeenCalled());
}
}  // namespace
