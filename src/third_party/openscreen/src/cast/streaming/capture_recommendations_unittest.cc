// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cast/streaming/capture_recommendations.h"

#include "absl/types/optional.h"
#include "cast/streaming/answer_messages.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "util/chrono_helpers.h"

namespace openscreen {
namespace cast {
namespace capture_recommendations {
namespace {

constexpr Recommendations kDefaultRecommendations{
    Audio{BitRateLimits{32000, 256000}, milliseconds(4000), 2, 44100},
    Video{BitRateLimits{300000, 1920 * 1080 * 30}, Resolution{320, 240, 30},
          Resolution{1920, 1080, 30}, true, milliseconds(4000),
          1920 * 1080 * 30 / 8}};

constexpr DisplayDescription kEmptyDescription{};

constexpr DisplayDescription kValidOnlyResolution{
    Dimensions{1024, 768, SimpleFraction{60, 1}}, absl::nullopt, absl::nullopt};

constexpr DisplayDescription kValidOnlyAspectRatio{
    absl::nullopt, AspectRatio{4, 3}, absl::nullopt};

constexpr DisplayDescription kValidOnlyAspectRatioSixteenNine{
    absl::nullopt, AspectRatio{16, 9}, absl::nullopt};

constexpr DisplayDescription kValidOnlyVariable{
    absl::nullopt, absl::nullopt, AspectRatioConstraint::kVariable};

constexpr DisplayDescription kInvalidOnlyFixed{absl::nullopt, absl::nullopt,
                                               AspectRatioConstraint::kFixed};

constexpr DisplayDescription kValidFixedAspectRatio{
    absl::nullopt, AspectRatio{4, 3}, AspectRatioConstraint::kFixed};

constexpr DisplayDescription kValidVariableAspectRatio{
    absl::nullopt, AspectRatio{4, 3}, AspectRatioConstraint::kVariable};

constexpr DisplayDescription kValidFixedMissingAspectRatio{
    Dimensions{1024, 768, SimpleFraction{60, 1}}, absl::nullopt,
    AspectRatioConstraint::kFixed};

constexpr DisplayDescription kValidDisplayFhd{
    Dimensions{1920, 1080, SimpleFraction{30, 1}}, AspectRatio{16, 9},
    AspectRatioConstraint::kVariable};

constexpr DisplayDescription kValidDisplayXga{
    Dimensions{1024, 768, SimpleFraction{60, 1}}, AspectRatio{4, 3},
    AspectRatioConstraint::kFixed};

constexpr DisplayDescription kValidDisplayTiny{
    Dimensions{300, 200, SimpleFraction{30, 1}}, AspectRatio{3, 2},
    AspectRatioConstraint::kFixed};

constexpr DisplayDescription kValidDisplayMismatched{
    Dimensions{300, 200, SimpleFraction{30, 1}}, AspectRatio{3, 4},
    AspectRatioConstraint::kFixed};

constexpr Constraints kEmptyConstraints{};

constexpr Constraints kValidConstraintsHighEnd{
    {96100, 5, 96000, 500000, std::chrono::seconds(6)},
    {6000000, Dimensions{640, 480, SimpleFraction{30, 1}},
     Dimensions{3840, 2160, SimpleFraction{144, 1}}, 600000, 6000000,
     std::chrono::seconds(6)}};

constexpr Constraints kValidConstraintsLowEnd{
    {22000, 2, 24000, 50000, std::chrono::seconds(1)},
    {60000, Dimensions{120, 80, SimpleFraction{10, 1}},
     Dimensions{1200, 800, SimpleFraction{30, 1}}, 100000, 1000000,
     std::chrono::seconds(1)}};

}  // namespace

TEST(CaptureRecommendationsTest, UsesDefaultsIfNoReceiverInformationAvailable) {
  EXPECT_EQ(kDefaultRecommendations, GetRecommendations(Answer{}));
}

TEST(CaptureRecommendationsTest, EmptyDisplayDescription) {
  Answer answer;
  answer.display = kEmptyDescription;
  EXPECT_EQ(kDefaultRecommendations, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, OnlyResolution) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.maximum = Resolution{1024, 768, 60.0};
  expected.video.bit_rate_limits.maximum = 47185920;
  Answer answer;
  answer.display = kValidOnlyResolution;
  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, OnlyAspectRatioFourThirds) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{320, 240, 30.0};
  expected.video.maximum = Resolution{1440, 1080, 30.0};
  expected.video.supports_scaling = true;
  Answer answer;
  answer.display = kValidOnlyAspectRatio;

  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, OnlyAspectRatioSixteenNine) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{426, 240, 30.0};
  expected.video.maximum = Resolution{1920, 1080, 30.0};
  expected.video.supports_scaling = true;
  Answer answer;
  answer.display = kValidOnlyAspectRatioSixteenNine;

  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, OnlyAspectRatioConstraint) {
  Answer answer;
  answer.display = kValidOnlyVariable;
  EXPECT_EQ(kDefaultRecommendations, GetRecommendations(answer));
}

// It doesn't make sense to just provide a "fixed" aspect ratio with no
// other dimension information, so we just return default recommendations
// in this case and assume the sender will handle it elsewhere, e.g. on
// ANSWER message parsing.
TEST(CaptureRecommendationsTest, OnlyInvalidAspectRatioConstraint) {
  Answer answer;
  answer.display = kInvalidOnlyFixed;
  EXPECT_EQ(kDefaultRecommendations, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, FixedAspectRatioConstraint) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{320, 240, 30.0};
  expected.video.maximum = Resolution{1440, 1080, 30.0};
  expected.video.supports_scaling = false;
  Answer answer;
  answer.display = kValidFixedAspectRatio;
  EXPECT_EQ(expected, GetRecommendations(answer));
}

// Our behavior is actually the same whether the constraint is passed, we
// just percolate the constraint up to the capture devices so that intermediate
// frame sizes between minimum and maximum can be properly scaled.
TEST(CaptureRecommendationsTest, VariableAspectRatioConstraint) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{320, 240, 30.0};
  expected.video.maximum = Resolution{1440, 1080, 30.0};
  Answer answer;
  answer.display = kValidVariableAspectRatio;
  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, ResolutionWithFixedConstraint) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{320, 240, 30.0};
  expected.video.maximum = Resolution{1024, 768, 60.0};
  expected.video.supports_scaling = false;
  expected.video.bit_rate_limits.maximum = 47185920;
  Answer answer;
  answer.display = kValidFixedMissingAspectRatio;
  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, ExplicitFhdChangesMinimum) {
  Answer answer;
  answer.display = kValidDisplayFhd;
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{426, 240, 30.0};
  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, XgaResolution) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{320, 240, 30.0};
  expected.video.maximum = Resolution{1024, 768, 60.0};
  expected.video.supports_scaling = false;
  expected.video.bit_rate_limits.maximum = 47185920;
  Answer answer;
  answer.display = kValidDisplayXga;
  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, MismatchedDisplayAndAspectRatio) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{150, 200, 30.0};
  expected.video.maximum = Resolution{150, 200, 30.0};
  expected.video.supports_scaling = false;
  expected.video.bit_rate_limits.maximum = 300 * 200 * 30;
  Answer answer;
  answer.display = kValidDisplayMismatched;
  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, TinyDisplay) {
  Recommendations expected = kDefaultRecommendations;
  expected.video.minimum = Resolution{300, 200, 30.0};
  expected.video.maximum = Resolution{300, 200, 30.0};
  expected.video.supports_scaling = false;
  expected.video.bit_rate_limits.maximum = 300 * 200 * 30;
  Answer answer;
  answer.display = kValidDisplayTiny;
  EXPECT_EQ(expected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, EmptyConstraints) {
  Answer answer;
  answer.constraints = kEmptyConstraints;
  EXPECT_EQ(kDefaultRecommendations, GetRecommendations(answer));
}

// Generally speaking, if the receiver gives us constraints higher than our
// defaults we will accept them, with the exception of maximum resolutions
// exceeding 1080P.
TEST(CaptureRecommendationsTest, HandlesHighEnd) {
  const Recommendations kExpected{
      Audio{BitRateLimits{96000, 500000}, milliseconds(6000), 5, 96100},
      Video{BitRateLimits{600000, 6000000}, Resolution{640, 480, 30},
            Resolution{1920, 1080, 30}, true, milliseconds(6000), 6000000}};
  Answer answer;
  answer.constraints = kValidConstraintsHighEnd;
  EXPECT_EQ(kExpected, GetRecommendations(answer));
}

// However, if the receiver gives us constraints lower than our minimum
// defaults, we will ignore them--they would result in an unacceptable cast
// experience.
TEST(CaptureRecommendationsTest, HandlesLowEnd) {
  const Recommendations kExpected{
      Audio{BitRateLimits{32000, 50000}, milliseconds(1000), 2, 22000},
      Video{BitRateLimits{300000, 1000000}, Resolution{320, 240, 30},
            Resolution{1200, 800, 30}, true, milliseconds(1000), 60000}};
  Answer answer;
  answer.constraints = kValidConstraintsLowEnd;
  EXPECT_EQ(kExpected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, HandlesTooSmallScreen) {
  const Recommendations kExpected{
      Audio{BitRateLimits{32000, 50000}, milliseconds(1000), 2, 22000},
      Video{BitRateLimits{300000, 1000000}, Resolution{320, 240, 30},
            Resolution{320, 240, 30}, true, milliseconds(1000), 60000}};
  Answer answer;
  answer.constraints = kValidConstraintsLowEnd;
  answer.constraints->video.max_dimensions =
      answer.constraints->video.min_dimensions.value();
  EXPECT_EQ(kExpected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, HandlesMinimumSizeScreen) {
  const Recommendations kExpected{
      Audio{BitRateLimits{32000, 50000}, milliseconds(1000), 2, 22000},
      Video{BitRateLimits{300000, 1000000}, Resolution{320, 240, 30},
            Resolution{320, 240, 30}, true, milliseconds(1000), 60000}};
  Answer answer;
  answer.constraints = kValidConstraintsLowEnd;
  answer.constraints->video.max_dimensions =
      Dimensions{320, 240, SimpleFraction{30, 1}};
  EXPECT_EQ(kExpected, GetRecommendations(answer));
}

TEST(CaptureRecommendationsTest, UsesIntersectionOfDisplayAndConstraints) {
  const Recommendations kExpected{
      Audio{BitRateLimits{96000, 500000}, milliseconds(6000), 5, 96100},
      Video{BitRateLimits{600000, 6000000}, Resolution{640, 480, 30},
            // Max resolution should be 1080P, since that's the display
            // resolution. No reason to capture at 4K, even though the
            // receiver supports it.
            Resolution{1920, 1080, 30}, true, milliseconds(6000), 6000000}};
  Answer answer;
  answer.display = kValidDisplayFhd;
  answer.constraints = kValidConstraintsHighEnd;
  EXPECT_EQ(kExpected, GetRecommendations(answer));
}

}  // namespace capture_recommendations
}  // namespace cast
}  // namespace openscreen
