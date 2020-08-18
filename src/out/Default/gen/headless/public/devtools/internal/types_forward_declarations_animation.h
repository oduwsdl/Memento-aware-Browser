// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_ANIMATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_ANIMATION_H_

#include "base/values.h"

namespace headless {

namespace animation {
class Animation;
class AnimationEffect;
class KeyframesRule;
class KeyframeStyle;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class GetCurrentAnimationTimeParams;
class GetCurrentAnimationTimeResult;
class GetPlaybackRateParams;
class GetPlaybackRateResult;
class ReleaseAnimationsParams;
class ReleaseAnimationsResult;
class ResolveAnimationParams;
class ResolveAnimationResult;
class SeekAnimationsParams;
class SeekAnimationsResult;
class SetPausedParams;
class SetPausedResult;
class SetPlaybackRateParams;
class SetPlaybackRateResult;
class SetTimingParams;
class SetTimingResult;
class AnimationCanceledParams;
class AnimationCreatedParams;
class AnimationStartedParams;

enum class AnimationType {
  CSS_TRANSITION,
  CSS_ANIMATION,
  WEB_ANIMATION
};

}  // namespace animation

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_ANIMATION_H_
