// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_animation.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_animation.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace animation {

std::unique_ptr<Animation> Animation::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Animation");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Animation> result(new Animation());
  errors->Push();
  errors->SetName("Animation");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* paused_state_value = value.FindKey("pausedState");
  if (paused_state_value) {
    errors->SetName("pausedState");
    result->paused_state_ = internal::FromValue<bool>::Parse(*paused_state_value, errors);
  } else {
    errors->AddError("required property missing: pausedState");
  }
  const base::Value* play_state_value = value.FindKey("playState");
  if (play_state_value) {
    errors->SetName("playState");
    result->play_state_ = internal::FromValue<std::string>::Parse(*play_state_value, errors);
  } else {
    errors->AddError("required property missing: playState");
  }
  const base::Value* playback_rate_value = value.FindKey("playbackRate");
  if (playback_rate_value) {
    errors->SetName("playbackRate");
    result->playback_rate_ = internal::FromValue<double>::Parse(*playback_rate_value, errors);
  } else {
    errors->AddError("required property missing: playbackRate");
  }
  const base::Value* start_time_value = value.FindKey("startTime");
  if (start_time_value) {
    errors->SetName("startTime");
    result->start_time_ = internal::FromValue<double>::Parse(*start_time_value, errors);
  } else {
    errors->AddError("required property missing: startTime");
  }
  const base::Value* current_time_value = value.FindKey("currentTime");
  if (current_time_value) {
    errors->SetName("currentTime");
    result->current_time_ = internal::FromValue<double>::Parse(*current_time_value, errors);
  } else {
    errors->AddError("required property missing: currentTime");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::animation::AnimationType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* source_value = value.FindKey("source");
  if (source_value) {
    errors->SetName("source");
    result->source_ = internal::FromValue<::headless::animation::AnimationEffect>::Parse(*source_value, errors);
  }
  const base::Value* css_id_value = value.FindKey("cssId");
  if (css_id_value) {
    errors->SetName("cssId");
    result->css_id_ = internal::FromValue<std::string>::Parse(*css_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Animation::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  result->Set("name", internal::ToValue(name_));
  result->Set("pausedState", internal::ToValue(paused_state_));
  result->Set("playState", internal::ToValue(play_state_));
  result->Set("playbackRate", internal::ToValue(playback_rate_));
  result->Set("startTime", internal::ToValue(start_time_));
  result->Set("currentTime", internal::ToValue(current_time_));
  result->Set("type", internal::ToValue(type_));
  if (source_)
    result->Set("source", internal::ToValue(*source_.value()));
  if (css_id_)
    result->Set("cssId", internal::ToValue(css_id_.value()));
  return std::move(result);
}

std::unique_ptr<Animation> Animation::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Animation> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AnimationEffect> AnimationEffect::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AnimationEffect");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AnimationEffect> result(new AnimationEffect());
  errors->Push();
  errors->SetName("AnimationEffect");
  const base::Value* delay_value = value.FindKey("delay");
  if (delay_value) {
    errors->SetName("delay");
    result->delay_ = internal::FromValue<double>::Parse(*delay_value, errors);
  } else {
    errors->AddError("required property missing: delay");
  }
  const base::Value* end_delay_value = value.FindKey("endDelay");
  if (end_delay_value) {
    errors->SetName("endDelay");
    result->end_delay_ = internal::FromValue<double>::Parse(*end_delay_value, errors);
  } else {
    errors->AddError("required property missing: endDelay");
  }
  const base::Value* iteration_start_value = value.FindKey("iterationStart");
  if (iteration_start_value) {
    errors->SetName("iterationStart");
    result->iteration_start_ = internal::FromValue<double>::Parse(*iteration_start_value, errors);
  } else {
    errors->AddError("required property missing: iterationStart");
  }
  const base::Value* iterations_value = value.FindKey("iterations");
  if (iterations_value) {
    errors->SetName("iterations");
    result->iterations_ = internal::FromValue<double>::Parse(*iterations_value, errors);
  } else {
    errors->AddError("required property missing: iterations");
  }
  const base::Value* duration_value = value.FindKey("duration");
  if (duration_value) {
    errors->SetName("duration");
    result->duration_ = internal::FromValue<double>::Parse(*duration_value, errors);
  } else {
    errors->AddError("required property missing: duration");
  }
  const base::Value* direction_value = value.FindKey("direction");
  if (direction_value) {
    errors->SetName("direction");
    result->direction_ = internal::FromValue<std::string>::Parse(*direction_value, errors);
  } else {
    errors->AddError("required property missing: direction");
  }
  const base::Value* fill_value = value.FindKey("fill");
  if (fill_value) {
    errors->SetName("fill");
    result->fill_ = internal::FromValue<std::string>::Parse(*fill_value, errors);
  } else {
    errors->AddError("required property missing: fill");
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* keyframes_rule_value = value.FindKey("keyframesRule");
  if (keyframes_rule_value) {
    errors->SetName("keyframesRule");
    result->keyframes_rule_ = internal::FromValue<::headless::animation::KeyframesRule>::Parse(*keyframes_rule_value, errors);
  }
  const base::Value* easing_value = value.FindKey("easing");
  if (easing_value) {
    errors->SetName("easing");
    result->easing_ = internal::FromValue<std::string>::Parse(*easing_value, errors);
  } else {
    errors->AddError("required property missing: easing");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AnimationEffect::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("delay", internal::ToValue(delay_));
  result->Set("endDelay", internal::ToValue(end_delay_));
  result->Set("iterationStart", internal::ToValue(iteration_start_));
  result->Set("iterations", internal::ToValue(iterations_));
  result->Set("duration", internal::ToValue(duration_));
  result->Set("direction", internal::ToValue(direction_));
  result->Set("fill", internal::ToValue(fill_));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  if (keyframes_rule_)
    result->Set("keyframesRule", internal::ToValue(*keyframes_rule_.value()));
  result->Set("easing", internal::ToValue(easing_));
  return std::move(result);
}

std::unique_ptr<AnimationEffect> AnimationEffect::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AnimationEffect> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<KeyframesRule> KeyframesRule::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("KeyframesRule");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<KeyframesRule> result(new KeyframesRule());
  errors->Push();
  errors->SetName("KeyframesRule");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  }
  const base::Value* keyframes_value = value.FindKey("keyframes");
  if (keyframes_value) {
    errors->SetName("keyframes");
    result->keyframes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::animation::KeyframeStyle>>>::Parse(*keyframes_value, errors);
  } else {
    errors->AddError("required property missing: keyframes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> KeyframesRule::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (name_)
    result->Set("name", internal::ToValue(name_.value()));
  result->Set("keyframes", internal::ToValue(keyframes_));
  return std::move(result);
}

std::unique_ptr<KeyframesRule> KeyframesRule::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<KeyframesRule> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<KeyframeStyle> KeyframeStyle::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("KeyframeStyle");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<KeyframeStyle> result(new KeyframeStyle());
  errors->Push();
  errors->SetName("KeyframeStyle");
  const base::Value* offset_value = value.FindKey("offset");
  if (offset_value) {
    errors->SetName("offset");
    result->offset_ = internal::FromValue<std::string>::Parse(*offset_value, errors);
  } else {
    errors->AddError("required property missing: offset");
  }
  const base::Value* easing_value = value.FindKey("easing");
  if (easing_value) {
    errors->SetName("easing");
    result->easing_ = internal::FromValue<std::string>::Parse(*easing_value, errors);
  } else {
    errors->AddError("required property missing: easing");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> KeyframeStyle::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("offset", internal::ToValue(offset_));
  result->Set("easing", internal::ToValue(easing_));
  return std::move(result);
}

std::unique_ptr<KeyframeStyle> KeyframeStyle::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<KeyframeStyle> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCurrentAnimationTimeParams> GetCurrentAnimationTimeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCurrentAnimationTimeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCurrentAnimationTimeParams> result(new GetCurrentAnimationTimeParams());
  errors->Push();
  errors->SetName("GetCurrentAnimationTimeParams");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCurrentAnimationTimeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  return std::move(result);
}

std::unique_ptr<GetCurrentAnimationTimeParams> GetCurrentAnimationTimeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCurrentAnimationTimeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCurrentAnimationTimeResult> GetCurrentAnimationTimeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCurrentAnimationTimeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCurrentAnimationTimeResult> result(new GetCurrentAnimationTimeResult());
  errors->Push();
  errors->SetName("GetCurrentAnimationTimeResult");
  const base::Value* current_time_value = value.FindKey("currentTime");
  if (current_time_value) {
    errors->SetName("currentTime");
    result->current_time_ = internal::FromValue<double>::Parse(*current_time_value, errors);
  } else {
    errors->AddError("required property missing: currentTime");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCurrentAnimationTimeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("currentTime", internal::ToValue(current_time_));
  return std::move(result);
}

std::unique_ptr<GetCurrentAnimationTimeResult> GetCurrentAnimationTimeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCurrentAnimationTimeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetPlaybackRateParams> GetPlaybackRateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetPlaybackRateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetPlaybackRateParams> result(new GetPlaybackRateParams());
  errors->Push();
  errors->SetName("GetPlaybackRateParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetPlaybackRateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetPlaybackRateParams> GetPlaybackRateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetPlaybackRateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetPlaybackRateResult> GetPlaybackRateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetPlaybackRateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetPlaybackRateResult> result(new GetPlaybackRateResult());
  errors->Push();
  errors->SetName("GetPlaybackRateResult");
  const base::Value* playback_rate_value = value.FindKey("playbackRate");
  if (playback_rate_value) {
    errors->SetName("playbackRate");
    result->playback_rate_ = internal::FromValue<double>::Parse(*playback_rate_value, errors);
  } else {
    errors->AddError("required property missing: playbackRate");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetPlaybackRateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("playbackRate", internal::ToValue(playback_rate_));
  return std::move(result);
}

std::unique_ptr<GetPlaybackRateResult> GetPlaybackRateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetPlaybackRateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseAnimationsParams> ReleaseAnimationsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseAnimationsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseAnimationsParams> result(new ReleaseAnimationsParams());
  errors->Push();
  errors->SetName("ReleaseAnimationsParams");
  const base::Value* animations_value = value.FindKey("animations");
  if (animations_value) {
    errors->SetName("animations");
    result->animations_ = internal::FromValue<std::vector<std::string>>::Parse(*animations_value, errors);
  } else {
    errors->AddError("required property missing: animations");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseAnimationsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("animations", internal::ToValue(animations_));
  return std::move(result);
}

std::unique_ptr<ReleaseAnimationsParams> ReleaseAnimationsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseAnimationsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseAnimationsResult> ReleaseAnimationsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseAnimationsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseAnimationsResult> result(new ReleaseAnimationsResult());
  errors->Push();
  errors->SetName("ReleaseAnimationsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseAnimationsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ReleaseAnimationsResult> ReleaseAnimationsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseAnimationsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResolveAnimationParams> ResolveAnimationParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResolveAnimationParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResolveAnimationParams> result(new ResolveAnimationParams());
  errors->Push();
  errors->SetName("ResolveAnimationParams");
  const base::Value* animation_id_value = value.FindKey("animationId");
  if (animation_id_value) {
    errors->SetName("animationId");
    result->animation_id_ = internal::FromValue<std::string>::Parse(*animation_id_value, errors);
  } else {
    errors->AddError("required property missing: animationId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResolveAnimationParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("animationId", internal::ToValue(animation_id_));
  return std::move(result);
}

std::unique_ptr<ResolveAnimationParams> ResolveAnimationParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResolveAnimationParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResolveAnimationResult> ResolveAnimationResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResolveAnimationResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResolveAnimationResult> result(new ResolveAnimationResult());
  errors->Push();
  errors->SetName("ResolveAnimationResult");
  const base::Value* remote_object_value = value.FindKey("remoteObject");
  if (remote_object_value) {
    errors->SetName("remoteObject");
    result->remote_object_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*remote_object_value, errors);
  } else {
    errors->AddError("required property missing: remoteObject");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResolveAnimationResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("remoteObject", internal::ToValue(*remote_object_));
  return std::move(result);
}

std::unique_ptr<ResolveAnimationResult> ResolveAnimationResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResolveAnimationResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SeekAnimationsParams> SeekAnimationsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SeekAnimationsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SeekAnimationsParams> result(new SeekAnimationsParams());
  errors->Push();
  errors->SetName("SeekAnimationsParams");
  const base::Value* animations_value = value.FindKey("animations");
  if (animations_value) {
    errors->SetName("animations");
    result->animations_ = internal::FromValue<std::vector<std::string>>::Parse(*animations_value, errors);
  } else {
    errors->AddError("required property missing: animations");
  }
  const base::Value* current_time_value = value.FindKey("currentTime");
  if (current_time_value) {
    errors->SetName("currentTime");
    result->current_time_ = internal::FromValue<double>::Parse(*current_time_value, errors);
  } else {
    errors->AddError("required property missing: currentTime");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SeekAnimationsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("animations", internal::ToValue(animations_));
  result->Set("currentTime", internal::ToValue(current_time_));
  return std::move(result);
}

std::unique_ptr<SeekAnimationsParams> SeekAnimationsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SeekAnimationsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SeekAnimationsResult> SeekAnimationsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SeekAnimationsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SeekAnimationsResult> result(new SeekAnimationsResult());
  errors->Push();
  errors->SetName("SeekAnimationsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SeekAnimationsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SeekAnimationsResult> SeekAnimationsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SeekAnimationsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPausedParams> SetPausedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPausedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPausedParams> result(new SetPausedParams());
  errors->Push();
  errors->SetName("SetPausedParams");
  const base::Value* animations_value = value.FindKey("animations");
  if (animations_value) {
    errors->SetName("animations");
    result->animations_ = internal::FromValue<std::vector<std::string>>::Parse(*animations_value, errors);
  } else {
    errors->AddError("required property missing: animations");
  }
  const base::Value* paused_value = value.FindKey("paused");
  if (paused_value) {
    errors->SetName("paused");
    result->paused_ = internal::FromValue<bool>::Parse(*paused_value, errors);
  } else {
    errors->AddError("required property missing: paused");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetPausedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("animations", internal::ToValue(animations_));
  result->Set("paused", internal::ToValue(paused_));
  return std::move(result);
}

std::unique_ptr<SetPausedParams> SetPausedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPausedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPausedResult> SetPausedResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPausedResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPausedResult> result(new SetPausedResult());
  errors->Push();
  errors->SetName("SetPausedResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetPausedResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetPausedResult> SetPausedResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPausedResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPlaybackRateParams> SetPlaybackRateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPlaybackRateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPlaybackRateParams> result(new SetPlaybackRateParams());
  errors->Push();
  errors->SetName("SetPlaybackRateParams");
  const base::Value* playback_rate_value = value.FindKey("playbackRate");
  if (playback_rate_value) {
    errors->SetName("playbackRate");
    result->playback_rate_ = internal::FromValue<double>::Parse(*playback_rate_value, errors);
  } else {
    errors->AddError("required property missing: playbackRate");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetPlaybackRateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("playbackRate", internal::ToValue(playback_rate_));
  return std::move(result);
}

std::unique_ptr<SetPlaybackRateParams> SetPlaybackRateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPlaybackRateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPlaybackRateResult> SetPlaybackRateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPlaybackRateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPlaybackRateResult> result(new SetPlaybackRateResult());
  errors->Push();
  errors->SetName("SetPlaybackRateResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetPlaybackRateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetPlaybackRateResult> SetPlaybackRateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPlaybackRateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetTimingParams> SetTimingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetTimingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetTimingParams> result(new SetTimingParams());
  errors->Push();
  errors->SetName("SetTimingParams");
  const base::Value* animation_id_value = value.FindKey("animationId");
  if (animation_id_value) {
    errors->SetName("animationId");
    result->animation_id_ = internal::FromValue<std::string>::Parse(*animation_id_value, errors);
  } else {
    errors->AddError("required property missing: animationId");
  }
  const base::Value* duration_value = value.FindKey("duration");
  if (duration_value) {
    errors->SetName("duration");
    result->duration_ = internal::FromValue<double>::Parse(*duration_value, errors);
  } else {
    errors->AddError("required property missing: duration");
  }
  const base::Value* delay_value = value.FindKey("delay");
  if (delay_value) {
    errors->SetName("delay");
    result->delay_ = internal::FromValue<double>::Parse(*delay_value, errors);
  } else {
    errors->AddError("required property missing: delay");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetTimingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("animationId", internal::ToValue(animation_id_));
  result->Set("duration", internal::ToValue(duration_));
  result->Set("delay", internal::ToValue(delay_));
  return std::move(result);
}

std::unique_ptr<SetTimingParams> SetTimingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetTimingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetTimingResult> SetTimingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetTimingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetTimingResult> result(new SetTimingResult());
  errors->Push();
  errors->SetName("SetTimingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetTimingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetTimingResult> SetTimingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetTimingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AnimationCanceledParams> AnimationCanceledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AnimationCanceledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AnimationCanceledParams> result(new AnimationCanceledParams());
  errors->Push();
  errors->SetName("AnimationCanceledParams");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AnimationCanceledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  return std::move(result);
}

std::unique_ptr<AnimationCanceledParams> AnimationCanceledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AnimationCanceledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AnimationCreatedParams> AnimationCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AnimationCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AnimationCreatedParams> result(new AnimationCreatedParams());
  errors->Push();
  errors->SetName("AnimationCreatedParams");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AnimationCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  return std::move(result);
}

std::unique_ptr<AnimationCreatedParams> AnimationCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AnimationCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AnimationStartedParams> AnimationStartedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AnimationStartedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AnimationStartedParams> result(new AnimationStartedParams());
  errors->Push();
  errors->SetName("AnimationStartedParams");
  const base::Value* animation_value = value.FindKey("animation");
  if (animation_value) {
    errors->SetName("animation");
    result->animation_ = internal::FromValue<::headless::animation::Animation>::Parse(*animation_value, errors);
  } else {
    errors->AddError("required property missing: animation");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AnimationStartedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("animation", internal::ToValue(*animation_));
  return std::move(result);
}

std::unique_ptr<AnimationStartedParams> AnimationStartedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AnimationStartedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace animation
}  // namespace headless
