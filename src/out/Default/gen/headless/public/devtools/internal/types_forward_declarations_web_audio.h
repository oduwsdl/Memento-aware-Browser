// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_WEB_AUDIO_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_WEB_AUDIO_H_

#include "base/values.h"

namespace headless {

namespace web_audio {
class ContextRealtimeData;
class BaseAudioContext;
class AudioListener;
class AudioNode;
class AudioParam;
class EnableParams;
class EnableResult;
class DisableParams;
class DisableResult;
class GetRealtimeDataParams;
class GetRealtimeDataResult;
class ContextCreatedParams;
class ContextWillBeDestroyedParams;
class ContextChangedParams;
class AudioListenerCreatedParams;
class AudioListenerWillBeDestroyedParams;
class AudioNodeCreatedParams;
class AudioNodeWillBeDestroyedParams;
class AudioParamCreatedParams;
class AudioParamWillBeDestroyedParams;
class NodesConnectedParams;
class NodesDisconnectedParams;
class NodeParamConnectedParams;
class NodeParamDisconnectedParams;

enum class ContextType {
  REALTIME,
  OFFLINE
};

enum class ContextState {
  SUSPENDED,
  RUNNING,
  CLOSED
};

enum class ChannelCountMode {
  CLAMPED_MAX,
  EXPLICIT,
  MAX
};

enum class ChannelInterpretation {
  DISCRETE,
  SPEAKERS
};

enum class AutomationRate {
  A_RATE,
  K_RATE
};

}  // namespace web_audio

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_WEB_AUDIO_H_
