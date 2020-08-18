// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_WEB_AUDIO_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_WEB_AUDIO_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_web_audio.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<web_audio::ContextType> {
  static web_audio::ContextType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return web_audio::ContextType::REALTIME;
    }
    if (value.GetString() == "realtime")
      return web_audio::ContextType::REALTIME;
    if (value.GetString() == "offline")
      return web_audio::ContextType::OFFLINE;
    errors->AddError("invalid enum value");
    return web_audio::ContextType::REALTIME;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ContextType& value) {
  switch (value) {
    case web_audio::ContextType::REALTIME:
      return std::make_unique<base::Value>("realtime");
    case web_audio::ContextType::OFFLINE:
      return std::make_unique<base::Value>("offline");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<web_audio::ContextState> {
  static web_audio::ContextState Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return web_audio::ContextState::SUSPENDED;
    }
    if (value.GetString() == "suspended")
      return web_audio::ContextState::SUSPENDED;
    if (value.GetString() == "running")
      return web_audio::ContextState::RUNNING;
    if (value.GetString() == "closed")
      return web_audio::ContextState::CLOSED;
    errors->AddError("invalid enum value");
    return web_audio::ContextState::SUSPENDED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ContextState& value) {
  switch (value) {
    case web_audio::ContextState::SUSPENDED:
      return std::make_unique<base::Value>("suspended");
    case web_audio::ContextState::RUNNING:
      return std::make_unique<base::Value>("running");
    case web_audio::ContextState::CLOSED:
      return std::make_unique<base::Value>("closed");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<web_audio::ChannelCountMode> {
  static web_audio::ChannelCountMode Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return web_audio::ChannelCountMode::CLAMPED_MAX;
    }
    if (value.GetString() == "clamped-max")
      return web_audio::ChannelCountMode::CLAMPED_MAX;
    if (value.GetString() == "explicit")
      return web_audio::ChannelCountMode::EXPLICIT;
    if (value.GetString() == "max")
      return web_audio::ChannelCountMode::MAX;
    errors->AddError("invalid enum value");
    return web_audio::ChannelCountMode::CLAMPED_MAX;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ChannelCountMode& value) {
  switch (value) {
    case web_audio::ChannelCountMode::CLAMPED_MAX:
      return std::make_unique<base::Value>("clamped-max");
    case web_audio::ChannelCountMode::EXPLICIT:
      return std::make_unique<base::Value>("explicit");
    case web_audio::ChannelCountMode::MAX:
      return std::make_unique<base::Value>("max");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<web_audio::ChannelInterpretation> {
  static web_audio::ChannelInterpretation Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return web_audio::ChannelInterpretation::DISCRETE;
    }
    if (value.GetString() == "discrete")
      return web_audio::ChannelInterpretation::DISCRETE;
    if (value.GetString() == "speakers")
      return web_audio::ChannelInterpretation::SPEAKERS;
    errors->AddError("invalid enum value");
    return web_audio::ChannelInterpretation::DISCRETE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ChannelInterpretation& value) {
  switch (value) {
    case web_audio::ChannelInterpretation::DISCRETE:
      return std::make_unique<base::Value>("discrete");
    case web_audio::ChannelInterpretation::SPEAKERS:
      return std::make_unique<base::Value>("speakers");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<web_audio::AutomationRate> {
  static web_audio::AutomationRate Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return web_audio::AutomationRate::A_RATE;
    }
    if (value.GetString() == "a-rate")
      return web_audio::AutomationRate::A_RATE;
    if (value.GetString() == "k-rate")
      return web_audio::AutomationRate::K_RATE;
    errors->AddError("invalid enum value");
    return web_audio::AutomationRate::A_RATE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AutomationRate& value) {
  switch (value) {
    case web_audio::AutomationRate::A_RATE:
      return std::make_unique<base::Value>("a-rate");
    case web_audio::AutomationRate::K_RATE:
      return std::make_unique<base::Value>("k-rate");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<web_audio::ContextRealtimeData> {
  static std::unique_ptr<web_audio::ContextRealtimeData> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::ContextRealtimeData::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ContextRealtimeData& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::BaseAudioContext> {
  static std::unique_ptr<web_audio::BaseAudioContext> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::BaseAudioContext::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::BaseAudioContext& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioListener> {
  static std::unique_ptr<web_audio::AudioListener> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioListener::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioListener& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioNode> {
  static std::unique_ptr<web_audio::AudioNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioParam> {
  static std::unique_ptr<web_audio::AudioParam> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioParam::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioParam& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::EnableParams> {
  static std::unique_ptr<web_audio::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::EnableResult> {
  static std::unique_ptr<web_audio::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::DisableParams> {
  static std::unique_ptr<web_audio::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::DisableResult> {
  static std::unique_ptr<web_audio::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::GetRealtimeDataParams> {
  static std::unique_ptr<web_audio::GetRealtimeDataParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::GetRealtimeDataParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::GetRealtimeDataParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::GetRealtimeDataResult> {
  static std::unique_ptr<web_audio::GetRealtimeDataResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::GetRealtimeDataResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::GetRealtimeDataResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::ContextCreatedParams> {
  static std::unique_ptr<web_audio::ContextCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::ContextCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ContextCreatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::ContextWillBeDestroyedParams> {
  static std::unique_ptr<web_audio::ContextWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::ContextWillBeDestroyedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ContextWillBeDestroyedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::ContextChangedParams> {
  static std::unique_ptr<web_audio::ContextChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::ContextChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::ContextChangedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioListenerCreatedParams> {
  static std::unique_ptr<web_audio::AudioListenerCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioListenerCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioListenerCreatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioListenerWillBeDestroyedParams> {
  static std::unique_ptr<web_audio::AudioListenerWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioListenerWillBeDestroyedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioListenerWillBeDestroyedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioNodeCreatedParams> {
  static std::unique_ptr<web_audio::AudioNodeCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioNodeCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioNodeCreatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioNodeWillBeDestroyedParams> {
  static std::unique_ptr<web_audio::AudioNodeWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioNodeWillBeDestroyedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioNodeWillBeDestroyedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioParamCreatedParams> {
  static std::unique_ptr<web_audio::AudioParamCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioParamCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioParamCreatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::AudioParamWillBeDestroyedParams> {
  static std::unique_ptr<web_audio::AudioParamWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::AudioParamWillBeDestroyedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::AudioParamWillBeDestroyedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::NodesConnectedParams> {
  static std::unique_ptr<web_audio::NodesConnectedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::NodesConnectedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::NodesConnectedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::NodesDisconnectedParams> {
  static std::unique_ptr<web_audio::NodesDisconnectedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::NodesDisconnectedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::NodesDisconnectedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::NodeParamConnectedParams> {
  static std::unique_ptr<web_audio::NodeParamConnectedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::NodeParamConnectedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::NodeParamConnectedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<web_audio::NodeParamDisconnectedParams> {
  static std::unique_ptr<web_audio::NodeParamDisconnectedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return web_audio::NodeParamDisconnectedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const web_audio::NodeParamDisconnectedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_WEB_AUDIO_H_
