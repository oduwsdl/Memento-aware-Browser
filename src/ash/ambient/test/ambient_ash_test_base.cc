// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/ambient/test/ambient_ash_test_base.h"

#include <memory>

#include "ash/ambient/ambient_photo_controller.h"
#include "ash/ambient/fake_ambient_backend_controller_impl.h"
#include "ash/ambient/ui/ambient_container_view.h"
#include "ash/ambient/ui/photo_view.h"
#include "ash/shell.h"
#include "chromeos/constants/chromeos_features.h"
#include "ui/gfx/image/image_skia.h"

namespace ash {

AmbientAshTestBase::AmbientAshTestBase()
    : AshTestBase(base::test::TaskEnvironment::TimeSource::MOCK_TIME) {}

AmbientAshTestBase::~AmbientAshTestBase() = default;

void AmbientAshTestBase::SetUp() {
  scoped_feature_list_.InitAndEnableFeature(
      chromeos::features::kAmbientModeFeature);
  image_downloader_ = std::make_unique<TestImageDownloader>();
  ambient_client_ = std::make_unique<TestAmbientClient>();

  AshTestBase::SetUp();

  // Need to reset first and then assign the TestPhotoClient because can only
  // have one instance of AmbientBackendController.
  Shell::Get()->ambient_controller()->set_backend_controller_for_testing(
      nullptr);
  Shell::Get()->ambient_controller()->set_backend_controller_for_testing(
      std::make_unique<FakeAmbientBackendControllerImpl>());
}

void AmbientAshTestBase::TearDown() {
  ambient_client_.reset();
  image_downloader_.reset();

  AshTestBase::TearDown();
}

void AmbientAshTestBase::ShowAmbientScreen() {
  // The widget will be destroyed in |AshTestBase::TearDown()|.
  ambient_controller()->CreateWidget();
}

void AmbientAshTestBase::HideAmbientScreen() {
  ambient_controller()->HideContainerView();
}

void AmbientAshTestBase::LockScreen() {
  GetSessionControllerClient()->LockScreen();
}

void AmbientAshTestBase::UnlockScreen() {
  GetSessionControllerClient()->UnlockScreen();
}

const gfx::ImageSkia& AmbientAshTestBase::GetImageInPhotoView() {
  return container_view()
      ->photo_view_for_testing()
      ->GetCurrentImagesForTesting();
}

void AmbientAshTestBase::IssueAccessToken(const std::string& token,
                                          bool with_error) {
  ambient_client_->IssueAccessToken(token, with_error);
}

bool AmbientAshTestBase::IsAccessTokenRequestPending() const {
  return ambient_client_->IsAccessTokenRequestPending();
}

AmbientController* AmbientAshTestBase::ambient_controller() {
  return Shell::Get()->ambient_controller();
}

AmbientPhotoController* AmbientAshTestBase::photo_controller() {
  return ambient_controller()->get_ambient_photo_controller_for_testing();
}

AmbientContainerView* AmbientAshTestBase::container_view() {
  return ambient_controller()->get_container_view_for_testing();
}

}  // namespace ash
