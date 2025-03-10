// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/lite_video/lite_video_features.h"

#include "base/feature_list.h"
#include "base/json/json_reader.h"
#include "base/metrics/field_trial.h"
#include "base/metrics/field_trial_params.h"
#include "base/metrics/histogram_macros.h"
#include "base/optional.h"
#include "base/values.h"
#include "chrome/common/chrome_features.h"

namespace lite_video {
namespace features {

bool IsLiteVideoEnabled() {
  return base::FeatureList::IsEnabled(::features::kLiteVideo);
}

base::Optional<base::Value> GetLiteVideoOriginHintsFromFieldTrial() {
  if (!IsLiteVideoEnabled())
    return base::nullopt;
  const std::string lite_video_origin_hints_json =
      base::GetFieldTrialParamValueByFeature(::features::kLiteVideo,
                                             "lite_video_origin_hints");
  if (lite_video_origin_hints_json.empty())
    return base::nullopt;

  base::Optional<base::Value> lite_video_origin_hints =
      base::JSONReader::Read(lite_video_origin_hints_json);

  UMA_HISTOGRAM_BOOLEAN(
      "LiteVideo.OriginHints.ParseResult",
      lite_video_origin_hints && lite_video_origin_hints->is_dict());

  return lite_video_origin_hints;
}

int LiteVideoTargetDownlinkRTTLatencyMs() {
  return GetFieldTrialParamByFeatureAsInt(
      ::features::kLiteVideo, "target_downlink_rtt_latency_ms", 2500);
}
int LiteVideoKilobytesToBufferBeforeThrottle() {
  return GetFieldTrialParamByFeatureAsInt(
      ::features::kLiteVideo, "kilobyte_to_buffer_before_throttle", 500);
}

}  // namespace features
}  // namespace lite_video
