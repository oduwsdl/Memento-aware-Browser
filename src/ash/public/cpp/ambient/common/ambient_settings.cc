// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/public/cpp/ambient/common/ambient_settings.h"

namespace ash {

ArtSetting::ArtSetting() = default;

ArtSetting::ArtSetting(const ArtSetting&) = default;

ArtSetting::ArtSetting(ArtSetting&&) = default;

ArtSetting& ArtSetting::operator=(const ArtSetting&) = default;

ArtSetting& ArtSetting::operator=(ArtSetting&&) = default;

ArtSetting::~ArtSetting() = default;

AmbientSettings::AmbientSettings() = default;

AmbientSettings::AmbientSettings(const AmbientSettings&) = default;

AmbientSettings::AmbientSettings(AmbientSettings&&) = default;

AmbientSettings& AmbientSettings::operator=(const AmbientSettings&) = default;

AmbientSettings& AmbientSettings::operator=(AmbientSettings&&) = default;

AmbientSettings::~AmbientSettings() = default;

}  // namespace ash
