// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_ANIMATION_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_ANIMATION_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_animation.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace animation {

// Animation instance.
class HEADLESS_EXPORT Animation {
 public:
  static std::unique_ptr<Animation> Parse(const base::Value& value, ErrorReporter* errors);
  ~Animation() { }

  // `Animation`'s id.
  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  // `Animation`'s name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // `Animation`'s internal paused state.
  bool GetPausedState() const { return paused_state_; }
  void SetPausedState(bool value) { paused_state_ = value; }

  // `Animation`'s play state.
  std::string GetPlayState() const { return play_state_; }
  void SetPlayState(const std::string& value) { play_state_ = value; }

  // `Animation`'s playback rate.
  double GetPlaybackRate() const { return playback_rate_; }
  void SetPlaybackRate(double value) { playback_rate_ = value; }

  // `Animation`'s start time.
  double GetStartTime() const { return start_time_; }
  void SetStartTime(double value) { start_time_ = value; }

  // `Animation`'s current time.
  double GetCurrentTime() const { return current_time_; }
  void SetCurrentTime(double value) { current_time_ = value; }

  // Animation type of `Animation`.
  ::headless::animation::AnimationType GetType() const { return type_; }
  void SetType(::headless::animation::AnimationType value) { type_ = value; }

  // `Animation`'s source animation node.
  bool HasSource() const { return !!source_; }
  const ::headless::animation::AnimationEffect* GetSource() const { DCHECK(HasSource()); return source_.value().get(); }
  void SetSource(std::unique_ptr<::headless::animation::AnimationEffect> value) { source_ = std::move(value); }

  // A unique ID for `Animation` representing the sources that triggered this CSS
  // animation/transition.
  bool HasCssId() const { return !!css_id_; }
  std::string GetCssId() const { DCHECK(HasCssId()); return css_id_.value(); }
  void SetCssId(const std::string& value) { css_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Animation> Clone() const;

  template<int STATE>
  class AnimationBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kNameSet = 1 << 2,
    kPausedStateSet = 1 << 3,
    kPlayStateSet = 1 << 4,
    kPlaybackRateSet = 1 << 5,
    kStartTimeSet = 1 << 6,
    kCurrentTimeSet = 1 << 7,
    kTypeSet = 1 << 8,
      kAllRequiredFieldsSet = (kIdSet | kNameSet | kPausedStateSet | kPlayStateSet | kPlaybackRateSet | kStartTimeSet | kCurrentTimeSet | kTypeSet | 0)
    };

    AnimationBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    AnimationBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    AnimationBuilder<STATE | kPausedStateSet>& SetPausedState(bool value) {
      static_assert(!(STATE & kPausedStateSet), "property pausedState should not have already been set");
      result_->SetPausedState(value);
      return CastState<kPausedStateSet>();
    }

    AnimationBuilder<STATE | kPlayStateSet>& SetPlayState(const std::string& value) {
      static_assert(!(STATE & kPlayStateSet), "property playState should not have already been set");
      result_->SetPlayState(value);
      return CastState<kPlayStateSet>();
    }

    AnimationBuilder<STATE | kPlaybackRateSet>& SetPlaybackRate(double value) {
      static_assert(!(STATE & kPlaybackRateSet), "property playbackRate should not have already been set");
      result_->SetPlaybackRate(value);
      return CastState<kPlaybackRateSet>();
    }

    AnimationBuilder<STATE | kStartTimeSet>& SetStartTime(double value) {
      static_assert(!(STATE & kStartTimeSet), "property startTime should not have already been set");
      result_->SetStartTime(value);
      return CastState<kStartTimeSet>();
    }

    AnimationBuilder<STATE | kCurrentTimeSet>& SetCurrentTime(double value) {
      static_assert(!(STATE & kCurrentTimeSet), "property currentTime should not have already been set");
      result_->SetCurrentTime(value);
      return CastState<kCurrentTimeSet>();
    }

    AnimationBuilder<STATE | kTypeSet>& SetType(::headless::animation::AnimationType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    AnimationBuilder<STATE>& SetSource(std::unique_ptr<::headless::animation::AnimationEffect> value) {
      result_->SetSource(std::move(value));
      return *this;
    }

    AnimationBuilder<STATE>& SetCssId(const std::string& value) {
      result_->SetCssId(value);
      return *this;
    }

    std::unique_ptr<Animation> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Animation;
    AnimationBuilder() : result_(new Animation()) { }

    template<int STEP> AnimationBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AnimationBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Animation> result_;
  };

  static AnimationBuilder<0> Builder() {
    return AnimationBuilder<0>();
  }

 private:
  Animation() { }

  std::string id_;
  std::string name_;
  bool paused_state_;
  std::string play_state_;
  double playback_rate_;
  double start_time_;
  double current_time_;
  ::headless::animation::AnimationType type_;
  base::Optional<std::unique_ptr<::headless::animation::AnimationEffect>> source_;
  base::Optional<std::string> css_id_;

  DISALLOW_COPY_AND_ASSIGN(Animation);
};


// AnimationEffect instance
class HEADLESS_EXPORT AnimationEffect {
 public:
  static std::unique_ptr<AnimationEffect> Parse(const base::Value& value, ErrorReporter* errors);
  ~AnimationEffect() { }

  // `AnimationEffect`'s delay.
  double GetDelay() const { return delay_; }
  void SetDelay(double value) { delay_ = value; }

  // `AnimationEffect`'s end delay.
  double GetEndDelay() const { return end_delay_; }
  void SetEndDelay(double value) { end_delay_ = value; }

  // `AnimationEffect`'s iteration start.
  double GetIterationStart() const { return iteration_start_; }
  void SetIterationStart(double value) { iteration_start_ = value; }

  // `AnimationEffect`'s iterations.
  double GetIterations() const { return iterations_; }
  void SetIterations(double value) { iterations_ = value; }

  // `AnimationEffect`'s iteration duration.
  double GetDuration() const { return duration_; }
  void SetDuration(double value) { duration_ = value; }

  // `AnimationEffect`'s playback direction.
  std::string GetDirection() const { return direction_; }
  void SetDirection(const std::string& value) { direction_ = value; }

  // `AnimationEffect`'s fill mode.
  std::string GetFill() const { return fill_; }
  void SetFill(const std::string& value) { fill_ = value; }

  // `AnimationEffect`'s target node.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // `AnimationEffect`'s keyframes.
  bool HasKeyframesRule() const { return !!keyframes_rule_; }
  const ::headless::animation::KeyframesRule* GetKeyframesRule() const { DCHECK(HasKeyframesRule()); return keyframes_rule_.value().get(); }
  void SetKeyframesRule(std::unique_ptr<::headless::animation::KeyframesRule> value) { keyframes_rule_ = std::move(value); }

  // `AnimationEffect`'s timing function.
  std::string GetEasing() const { return easing_; }
  void SetEasing(const std::string& value) { easing_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AnimationEffect> Clone() const;

  template<int STATE>
  class AnimationEffectBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDelaySet = 1 << 1,
    kEndDelaySet = 1 << 2,
    kIterationStartSet = 1 << 3,
    kIterationsSet = 1 << 4,
    kDurationSet = 1 << 5,
    kDirectionSet = 1 << 6,
    kFillSet = 1 << 7,
    kEasingSet = 1 << 8,
      kAllRequiredFieldsSet = (kDelaySet | kEndDelaySet | kIterationStartSet | kIterationsSet | kDurationSet | kDirectionSet | kFillSet | kEasingSet | 0)
    };

    AnimationEffectBuilder<STATE | kDelaySet>& SetDelay(double value) {
      static_assert(!(STATE & kDelaySet), "property delay should not have already been set");
      result_->SetDelay(value);
      return CastState<kDelaySet>();
    }

    AnimationEffectBuilder<STATE | kEndDelaySet>& SetEndDelay(double value) {
      static_assert(!(STATE & kEndDelaySet), "property endDelay should not have already been set");
      result_->SetEndDelay(value);
      return CastState<kEndDelaySet>();
    }

    AnimationEffectBuilder<STATE | kIterationStartSet>& SetIterationStart(double value) {
      static_assert(!(STATE & kIterationStartSet), "property iterationStart should not have already been set");
      result_->SetIterationStart(value);
      return CastState<kIterationStartSet>();
    }

    AnimationEffectBuilder<STATE | kIterationsSet>& SetIterations(double value) {
      static_assert(!(STATE & kIterationsSet), "property iterations should not have already been set");
      result_->SetIterations(value);
      return CastState<kIterationsSet>();
    }

    AnimationEffectBuilder<STATE | kDurationSet>& SetDuration(double value) {
      static_assert(!(STATE & kDurationSet), "property duration should not have already been set");
      result_->SetDuration(value);
      return CastState<kDurationSet>();
    }

    AnimationEffectBuilder<STATE | kDirectionSet>& SetDirection(const std::string& value) {
      static_assert(!(STATE & kDirectionSet), "property direction should not have already been set");
      result_->SetDirection(value);
      return CastState<kDirectionSet>();
    }

    AnimationEffectBuilder<STATE | kFillSet>& SetFill(const std::string& value) {
      static_assert(!(STATE & kFillSet), "property fill should not have already been set");
      result_->SetFill(value);
      return CastState<kFillSet>();
    }

    AnimationEffectBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    AnimationEffectBuilder<STATE>& SetKeyframesRule(std::unique_ptr<::headless::animation::KeyframesRule> value) {
      result_->SetKeyframesRule(std::move(value));
      return *this;
    }

    AnimationEffectBuilder<STATE | kEasingSet>& SetEasing(const std::string& value) {
      static_assert(!(STATE & kEasingSet), "property easing should not have already been set");
      result_->SetEasing(value);
      return CastState<kEasingSet>();
    }

    std::unique_ptr<AnimationEffect> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AnimationEffect;
    AnimationEffectBuilder() : result_(new AnimationEffect()) { }

    template<int STEP> AnimationEffectBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AnimationEffectBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AnimationEffect> result_;
  };

  static AnimationEffectBuilder<0> Builder() {
    return AnimationEffectBuilder<0>();
  }

 private:
  AnimationEffect() { }

  double delay_;
  double end_delay_;
  double iteration_start_;
  double iterations_;
  double duration_;
  std::string direction_;
  std::string fill_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::unique_ptr<::headless::animation::KeyframesRule>> keyframes_rule_;
  std::string easing_;

  DISALLOW_COPY_AND_ASSIGN(AnimationEffect);
};


// Keyframes Rule
class HEADLESS_EXPORT KeyframesRule {
 public:
  static std::unique_ptr<KeyframesRule> Parse(const base::Value& value, ErrorReporter* errors);
  ~KeyframesRule() { }

  // CSS keyframed animation's name.
  bool HasName() const { return !!name_; }
  std::string GetName() const { DCHECK(HasName()); return name_.value(); }
  void SetName(const std::string& value) { name_ = value; }

  // List of animation keyframes.
  const std::vector<std::unique_ptr<::headless::animation::KeyframeStyle>>* GetKeyframes() const { return &keyframes_; }
  void SetKeyframes(std::vector<std::unique_ptr<::headless::animation::KeyframeStyle>> value) { keyframes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<KeyframesRule> Clone() const;

  template<int STATE>
  class KeyframesRuleBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kKeyframesSet = 1 << 1,
      kAllRequiredFieldsSet = (kKeyframesSet | 0)
    };

    KeyframesRuleBuilder<STATE>& SetName(const std::string& value) {
      result_->SetName(value);
      return *this;
    }

    KeyframesRuleBuilder<STATE | kKeyframesSet>& SetKeyframes(std::vector<std::unique_ptr<::headless::animation::KeyframeStyle>> value) {
      static_assert(!(STATE & kKeyframesSet), "property keyframes should not have already been set");
      result_->SetKeyframes(std::move(value));
      return CastState<kKeyframesSet>();
    }

    std::unique_ptr<KeyframesRule> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class KeyframesRule;
    KeyframesRuleBuilder() : result_(new KeyframesRule()) { }

    template<int STEP> KeyframesRuleBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<KeyframesRuleBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<KeyframesRule> result_;
  };

  static KeyframesRuleBuilder<0> Builder() {
    return KeyframesRuleBuilder<0>();
  }

 private:
  KeyframesRule() { }

  base::Optional<std::string> name_;
  std::vector<std::unique_ptr<::headless::animation::KeyframeStyle>> keyframes_;

  DISALLOW_COPY_AND_ASSIGN(KeyframesRule);
};


// Keyframe Style
class HEADLESS_EXPORT KeyframeStyle {
 public:
  static std::unique_ptr<KeyframeStyle> Parse(const base::Value& value, ErrorReporter* errors);
  ~KeyframeStyle() { }

  // Keyframe's time offset.
  std::string GetOffset() const { return offset_; }
  void SetOffset(const std::string& value) { offset_ = value; }

  // `AnimationEffect`'s timing function.
  std::string GetEasing() const { return easing_; }
  void SetEasing(const std::string& value) { easing_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<KeyframeStyle> Clone() const;

  template<int STATE>
  class KeyframeStyleBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOffsetSet = 1 << 1,
    kEasingSet = 1 << 2,
      kAllRequiredFieldsSet = (kOffsetSet | kEasingSet | 0)
    };

    KeyframeStyleBuilder<STATE | kOffsetSet>& SetOffset(const std::string& value) {
      static_assert(!(STATE & kOffsetSet), "property offset should not have already been set");
      result_->SetOffset(value);
      return CastState<kOffsetSet>();
    }

    KeyframeStyleBuilder<STATE | kEasingSet>& SetEasing(const std::string& value) {
      static_assert(!(STATE & kEasingSet), "property easing should not have already been set");
      result_->SetEasing(value);
      return CastState<kEasingSet>();
    }

    std::unique_ptr<KeyframeStyle> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class KeyframeStyle;
    KeyframeStyleBuilder() : result_(new KeyframeStyle()) { }

    template<int STEP> KeyframeStyleBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<KeyframeStyleBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<KeyframeStyle> result_;
  };

  static KeyframeStyleBuilder<0> Builder() {
    return KeyframeStyleBuilder<0>();
  }

 private:
  KeyframeStyle() { }

  std::string offset_;
  std::string easing_;

  DISALLOW_COPY_AND_ASSIGN(KeyframeStyle);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the GetCurrentAnimationTime command.
class HEADLESS_EXPORT GetCurrentAnimationTimeParams {
 public:
  static std::unique_ptr<GetCurrentAnimationTimeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCurrentAnimationTimeParams() { }

  // Id of animation.
  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCurrentAnimationTimeParams> Clone() const;

  template<int STATE>
  class GetCurrentAnimationTimeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdSet | 0)
    };

    GetCurrentAnimationTimeParamsBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    std::unique_ptr<GetCurrentAnimationTimeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCurrentAnimationTimeParams;
    GetCurrentAnimationTimeParamsBuilder() : result_(new GetCurrentAnimationTimeParams()) { }

    template<int STEP> GetCurrentAnimationTimeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCurrentAnimationTimeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCurrentAnimationTimeParams> result_;
  };

  static GetCurrentAnimationTimeParamsBuilder<0> Builder() {
    return GetCurrentAnimationTimeParamsBuilder<0>();
  }

 private:
  GetCurrentAnimationTimeParams() { }

  std::string id_;

  DISALLOW_COPY_AND_ASSIGN(GetCurrentAnimationTimeParams);
};


// Result for the GetCurrentAnimationTime command.
class HEADLESS_EXPORT GetCurrentAnimationTimeResult {
 public:
  static std::unique_ptr<GetCurrentAnimationTimeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCurrentAnimationTimeResult() { }

  // Current time of the page.
  double GetCurrentTime() const { return current_time_; }
  void SetCurrentTime(double value) { current_time_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCurrentAnimationTimeResult> Clone() const;

  template<int STATE>
  class GetCurrentAnimationTimeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCurrentTimeSet = 1 << 1,
      kAllRequiredFieldsSet = (kCurrentTimeSet | 0)
    };

    GetCurrentAnimationTimeResultBuilder<STATE | kCurrentTimeSet>& SetCurrentTime(double value) {
      static_assert(!(STATE & kCurrentTimeSet), "property currentTime should not have already been set");
      result_->SetCurrentTime(value);
      return CastState<kCurrentTimeSet>();
    }

    std::unique_ptr<GetCurrentAnimationTimeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCurrentAnimationTimeResult;
    GetCurrentAnimationTimeResultBuilder() : result_(new GetCurrentAnimationTimeResult()) { }

    template<int STEP> GetCurrentAnimationTimeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCurrentAnimationTimeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCurrentAnimationTimeResult> result_;
  };

  static GetCurrentAnimationTimeResultBuilder<0> Builder() {
    return GetCurrentAnimationTimeResultBuilder<0>();
  }

 private:
  GetCurrentAnimationTimeResult() { }

  double current_time_;

  DISALLOW_COPY_AND_ASSIGN(GetCurrentAnimationTimeResult);
};


// Parameters for the GetPlaybackRate command.
class HEADLESS_EXPORT GetPlaybackRateParams {
 public:
  static std::unique_ptr<GetPlaybackRateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetPlaybackRateParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetPlaybackRateParams> Clone() const;

  template<int STATE>
  class GetPlaybackRateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetPlaybackRateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetPlaybackRateParams;
    GetPlaybackRateParamsBuilder() : result_(new GetPlaybackRateParams()) { }

    template<int STEP> GetPlaybackRateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetPlaybackRateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetPlaybackRateParams> result_;
  };

  static GetPlaybackRateParamsBuilder<0> Builder() {
    return GetPlaybackRateParamsBuilder<0>();
  }

 private:
  GetPlaybackRateParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetPlaybackRateParams);
};


// Result for the GetPlaybackRate command.
class HEADLESS_EXPORT GetPlaybackRateResult {
 public:
  static std::unique_ptr<GetPlaybackRateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetPlaybackRateResult() { }

  // Playback rate for animations on page.
  double GetPlaybackRate() const { return playback_rate_; }
  void SetPlaybackRate(double value) { playback_rate_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetPlaybackRateResult> Clone() const;

  template<int STATE>
  class GetPlaybackRateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlaybackRateSet = 1 << 1,
      kAllRequiredFieldsSet = (kPlaybackRateSet | 0)
    };

    GetPlaybackRateResultBuilder<STATE | kPlaybackRateSet>& SetPlaybackRate(double value) {
      static_assert(!(STATE & kPlaybackRateSet), "property playbackRate should not have already been set");
      result_->SetPlaybackRate(value);
      return CastState<kPlaybackRateSet>();
    }

    std::unique_ptr<GetPlaybackRateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetPlaybackRateResult;
    GetPlaybackRateResultBuilder() : result_(new GetPlaybackRateResult()) { }

    template<int STEP> GetPlaybackRateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetPlaybackRateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetPlaybackRateResult> result_;
  };

  static GetPlaybackRateResultBuilder<0> Builder() {
    return GetPlaybackRateResultBuilder<0>();
  }

 private:
  GetPlaybackRateResult() { }

  double playback_rate_;

  DISALLOW_COPY_AND_ASSIGN(GetPlaybackRateResult);
};


// Parameters for the ReleaseAnimations command.
class HEADLESS_EXPORT ReleaseAnimationsParams {
 public:
  static std::unique_ptr<ReleaseAnimationsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseAnimationsParams() { }

  // List of animation ids to seek.
  const std::vector<std::string>* GetAnimations() const { return &animations_; }
  void SetAnimations(std::vector<std::string> value) { animations_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseAnimationsParams> Clone() const;

  template<int STATE>
  class ReleaseAnimationsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAnimationsSet = 1 << 1,
      kAllRequiredFieldsSet = (kAnimationsSet | 0)
    };

    ReleaseAnimationsParamsBuilder<STATE | kAnimationsSet>& SetAnimations(std::vector<std::string> value) {
      static_assert(!(STATE & kAnimationsSet), "property animations should not have already been set");
      result_->SetAnimations(std::move(value));
      return CastState<kAnimationsSet>();
    }

    std::unique_ptr<ReleaseAnimationsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseAnimationsParams;
    ReleaseAnimationsParamsBuilder() : result_(new ReleaseAnimationsParams()) { }

    template<int STEP> ReleaseAnimationsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseAnimationsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseAnimationsParams> result_;
  };

  static ReleaseAnimationsParamsBuilder<0> Builder() {
    return ReleaseAnimationsParamsBuilder<0>();
  }

 private:
  ReleaseAnimationsParams() { }

  std::vector<std::string> animations_;

  DISALLOW_COPY_AND_ASSIGN(ReleaseAnimationsParams);
};


// Result for the ReleaseAnimations command.
class HEADLESS_EXPORT ReleaseAnimationsResult {
 public:
  static std::unique_ptr<ReleaseAnimationsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseAnimationsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseAnimationsResult> Clone() const;

  template<int STATE>
  class ReleaseAnimationsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ReleaseAnimationsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseAnimationsResult;
    ReleaseAnimationsResultBuilder() : result_(new ReleaseAnimationsResult()) { }

    template<int STEP> ReleaseAnimationsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseAnimationsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseAnimationsResult> result_;
  };

  static ReleaseAnimationsResultBuilder<0> Builder() {
    return ReleaseAnimationsResultBuilder<0>();
  }

 private:
  ReleaseAnimationsResult() { }


  DISALLOW_COPY_AND_ASSIGN(ReleaseAnimationsResult);
};


// Parameters for the ResolveAnimation command.
class HEADLESS_EXPORT ResolveAnimationParams {
 public:
  static std::unique_ptr<ResolveAnimationParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResolveAnimationParams() { }

  // Animation id.
  std::string GetAnimationId() const { return animation_id_; }
  void SetAnimationId(const std::string& value) { animation_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResolveAnimationParams> Clone() const;

  template<int STATE>
  class ResolveAnimationParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAnimationIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kAnimationIdSet | 0)
    };

    ResolveAnimationParamsBuilder<STATE | kAnimationIdSet>& SetAnimationId(const std::string& value) {
      static_assert(!(STATE & kAnimationIdSet), "property animationId should not have already been set");
      result_->SetAnimationId(value);
      return CastState<kAnimationIdSet>();
    }

    std::unique_ptr<ResolveAnimationParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResolveAnimationParams;
    ResolveAnimationParamsBuilder() : result_(new ResolveAnimationParams()) { }

    template<int STEP> ResolveAnimationParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResolveAnimationParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResolveAnimationParams> result_;
  };

  static ResolveAnimationParamsBuilder<0> Builder() {
    return ResolveAnimationParamsBuilder<0>();
  }

 private:
  ResolveAnimationParams() { }

  std::string animation_id_;

  DISALLOW_COPY_AND_ASSIGN(ResolveAnimationParams);
};


// Result for the ResolveAnimation command.
class HEADLESS_EXPORT ResolveAnimationResult {
 public:
  static std::unique_ptr<ResolveAnimationResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResolveAnimationResult() { }

  // Corresponding remote object.
  const ::headless::runtime::RemoteObject* GetRemoteObject() const { return remote_object_.get(); }
  void SetRemoteObject(std::unique_ptr<::headless::runtime::RemoteObject> value) { remote_object_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResolveAnimationResult> Clone() const;

  template<int STATE>
  class ResolveAnimationResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRemoteObjectSet = 1 << 1,
      kAllRequiredFieldsSet = (kRemoteObjectSet | 0)
    };

    ResolveAnimationResultBuilder<STATE | kRemoteObjectSet>& SetRemoteObject(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kRemoteObjectSet), "property remoteObject should not have already been set");
      result_->SetRemoteObject(std::move(value));
      return CastState<kRemoteObjectSet>();
    }

    std::unique_ptr<ResolveAnimationResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResolveAnimationResult;
    ResolveAnimationResultBuilder() : result_(new ResolveAnimationResult()) { }

    template<int STEP> ResolveAnimationResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResolveAnimationResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResolveAnimationResult> result_;
  };

  static ResolveAnimationResultBuilder<0> Builder() {
    return ResolveAnimationResultBuilder<0>();
  }

 private:
  ResolveAnimationResult() { }

  std::unique_ptr<::headless::runtime::RemoteObject> remote_object_;

  DISALLOW_COPY_AND_ASSIGN(ResolveAnimationResult);
};


// Parameters for the SeekAnimations command.
class HEADLESS_EXPORT SeekAnimationsParams {
 public:
  static std::unique_ptr<SeekAnimationsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SeekAnimationsParams() { }

  // List of animation ids to seek.
  const std::vector<std::string>* GetAnimations() const { return &animations_; }
  void SetAnimations(std::vector<std::string> value) { animations_ = std::move(value); }

  // Set the current time of each animation.
  double GetCurrentTime() const { return current_time_; }
  void SetCurrentTime(double value) { current_time_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SeekAnimationsParams> Clone() const;

  template<int STATE>
  class SeekAnimationsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAnimationsSet = 1 << 1,
    kCurrentTimeSet = 1 << 2,
      kAllRequiredFieldsSet = (kAnimationsSet | kCurrentTimeSet | 0)
    };

    SeekAnimationsParamsBuilder<STATE | kAnimationsSet>& SetAnimations(std::vector<std::string> value) {
      static_assert(!(STATE & kAnimationsSet), "property animations should not have already been set");
      result_->SetAnimations(std::move(value));
      return CastState<kAnimationsSet>();
    }

    SeekAnimationsParamsBuilder<STATE | kCurrentTimeSet>& SetCurrentTime(double value) {
      static_assert(!(STATE & kCurrentTimeSet), "property currentTime should not have already been set");
      result_->SetCurrentTime(value);
      return CastState<kCurrentTimeSet>();
    }

    std::unique_ptr<SeekAnimationsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SeekAnimationsParams;
    SeekAnimationsParamsBuilder() : result_(new SeekAnimationsParams()) { }

    template<int STEP> SeekAnimationsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SeekAnimationsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SeekAnimationsParams> result_;
  };

  static SeekAnimationsParamsBuilder<0> Builder() {
    return SeekAnimationsParamsBuilder<0>();
  }

 private:
  SeekAnimationsParams() { }

  std::vector<std::string> animations_;
  double current_time_;

  DISALLOW_COPY_AND_ASSIGN(SeekAnimationsParams);
};


// Result for the SeekAnimations command.
class HEADLESS_EXPORT SeekAnimationsResult {
 public:
  static std::unique_ptr<SeekAnimationsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SeekAnimationsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SeekAnimationsResult> Clone() const;

  template<int STATE>
  class SeekAnimationsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SeekAnimationsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SeekAnimationsResult;
    SeekAnimationsResultBuilder() : result_(new SeekAnimationsResult()) { }

    template<int STEP> SeekAnimationsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SeekAnimationsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SeekAnimationsResult> result_;
  };

  static SeekAnimationsResultBuilder<0> Builder() {
    return SeekAnimationsResultBuilder<0>();
  }

 private:
  SeekAnimationsResult() { }


  DISALLOW_COPY_AND_ASSIGN(SeekAnimationsResult);
};


// Parameters for the SetPaused command.
class HEADLESS_EXPORT SetPausedParams {
 public:
  static std::unique_ptr<SetPausedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPausedParams() { }

  // Animations to set the pause state of.
  const std::vector<std::string>* GetAnimations() const { return &animations_; }
  void SetAnimations(std::vector<std::string> value) { animations_ = std::move(value); }

  // Paused state to set to.
  bool GetPaused() const { return paused_; }
  void SetPaused(bool value) { paused_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPausedParams> Clone() const;

  template<int STATE>
  class SetPausedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAnimationsSet = 1 << 1,
    kPausedSet = 1 << 2,
      kAllRequiredFieldsSet = (kAnimationsSet | kPausedSet | 0)
    };

    SetPausedParamsBuilder<STATE | kAnimationsSet>& SetAnimations(std::vector<std::string> value) {
      static_assert(!(STATE & kAnimationsSet), "property animations should not have already been set");
      result_->SetAnimations(std::move(value));
      return CastState<kAnimationsSet>();
    }

    SetPausedParamsBuilder<STATE | kPausedSet>& SetPaused(bool value) {
      static_assert(!(STATE & kPausedSet), "property paused should not have already been set");
      result_->SetPaused(value);
      return CastState<kPausedSet>();
    }

    std::unique_ptr<SetPausedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPausedParams;
    SetPausedParamsBuilder() : result_(new SetPausedParams()) { }

    template<int STEP> SetPausedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPausedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPausedParams> result_;
  };

  static SetPausedParamsBuilder<0> Builder() {
    return SetPausedParamsBuilder<0>();
  }

 private:
  SetPausedParams() { }

  std::vector<std::string> animations_;
  bool paused_;

  DISALLOW_COPY_AND_ASSIGN(SetPausedParams);
};


// Result for the SetPaused command.
class HEADLESS_EXPORT SetPausedResult {
 public:
  static std::unique_ptr<SetPausedResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPausedResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPausedResult> Clone() const;

  template<int STATE>
  class SetPausedResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetPausedResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPausedResult;
    SetPausedResultBuilder() : result_(new SetPausedResult()) { }

    template<int STEP> SetPausedResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPausedResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPausedResult> result_;
  };

  static SetPausedResultBuilder<0> Builder() {
    return SetPausedResultBuilder<0>();
  }

 private:
  SetPausedResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetPausedResult);
};


// Parameters for the SetPlaybackRate command.
class HEADLESS_EXPORT SetPlaybackRateParams {
 public:
  static std::unique_ptr<SetPlaybackRateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPlaybackRateParams() { }

  // Playback rate for animations on page
  double GetPlaybackRate() const { return playback_rate_; }
  void SetPlaybackRate(double value) { playback_rate_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPlaybackRateParams> Clone() const;

  template<int STATE>
  class SetPlaybackRateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPlaybackRateSet = 1 << 1,
      kAllRequiredFieldsSet = (kPlaybackRateSet | 0)
    };

    SetPlaybackRateParamsBuilder<STATE | kPlaybackRateSet>& SetPlaybackRate(double value) {
      static_assert(!(STATE & kPlaybackRateSet), "property playbackRate should not have already been set");
      result_->SetPlaybackRate(value);
      return CastState<kPlaybackRateSet>();
    }

    std::unique_ptr<SetPlaybackRateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPlaybackRateParams;
    SetPlaybackRateParamsBuilder() : result_(new SetPlaybackRateParams()) { }

    template<int STEP> SetPlaybackRateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPlaybackRateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPlaybackRateParams> result_;
  };

  static SetPlaybackRateParamsBuilder<0> Builder() {
    return SetPlaybackRateParamsBuilder<0>();
  }

 private:
  SetPlaybackRateParams() { }

  double playback_rate_;

  DISALLOW_COPY_AND_ASSIGN(SetPlaybackRateParams);
};


// Result for the SetPlaybackRate command.
class HEADLESS_EXPORT SetPlaybackRateResult {
 public:
  static std::unique_ptr<SetPlaybackRateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetPlaybackRateResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetPlaybackRateResult> Clone() const;

  template<int STATE>
  class SetPlaybackRateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetPlaybackRateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetPlaybackRateResult;
    SetPlaybackRateResultBuilder() : result_(new SetPlaybackRateResult()) { }

    template<int STEP> SetPlaybackRateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetPlaybackRateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetPlaybackRateResult> result_;
  };

  static SetPlaybackRateResultBuilder<0> Builder() {
    return SetPlaybackRateResultBuilder<0>();
  }

 private:
  SetPlaybackRateResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetPlaybackRateResult);
};


// Parameters for the SetTiming command.
class HEADLESS_EXPORT SetTimingParams {
 public:
  static std::unique_ptr<SetTimingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTimingParams() { }

  // Animation id.
  std::string GetAnimationId() const { return animation_id_; }
  void SetAnimationId(const std::string& value) { animation_id_ = value; }

  // Duration of the animation.
  double GetDuration() const { return duration_; }
  void SetDuration(double value) { duration_ = value; }

  // Delay of the animation.
  double GetDelay() const { return delay_; }
  void SetDelay(double value) { delay_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTimingParams> Clone() const;

  template<int STATE>
  class SetTimingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAnimationIdSet = 1 << 1,
    kDurationSet = 1 << 2,
    kDelaySet = 1 << 3,
      kAllRequiredFieldsSet = (kAnimationIdSet | kDurationSet | kDelaySet | 0)
    };

    SetTimingParamsBuilder<STATE | kAnimationIdSet>& SetAnimationId(const std::string& value) {
      static_assert(!(STATE & kAnimationIdSet), "property animationId should not have already been set");
      result_->SetAnimationId(value);
      return CastState<kAnimationIdSet>();
    }

    SetTimingParamsBuilder<STATE | kDurationSet>& SetDuration(double value) {
      static_assert(!(STATE & kDurationSet), "property duration should not have already been set");
      result_->SetDuration(value);
      return CastState<kDurationSet>();
    }

    SetTimingParamsBuilder<STATE | kDelaySet>& SetDelay(double value) {
      static_assert(!(STATE & kDelaySet), "property delay should not have already been set");
      result_->SetDelay(value);
      return CastState<kDelaySet>();
    }

    std::unique_ptr<SetTimingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTimingParams;
    SetTimingParamsBuilder() : result_(new SetTimingParams()) { }

    template<int STEP> SetTimingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTimingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTimingParams> result_;
  };

  static SetTimingParamsBuilder<0> Builder() {
    return SetTimingParamsBuilder<0>();
  }

 private:
  SetTimingParams() { }

  std::string animation_id_;
  double duration_;
  double delay_;

  DISALLOW_COPY_AND_ASSIGN(SetTimingParams);
};


// Result for the SetTiming command.
class HEADLESS_EXPORT SetTimingResult {
 public:
  static std::unique_ptr<SetTimingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTimingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTimingResult> Clone() const;

  template<int STATE>
  class SetTimingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetTimingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTimingResult;
    SetTimingResultBuilder() : result_(new SetTimingResult()) { }

    template<int STEP> SetTimingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTimingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTimingResult> result_;
  };

  static SetTimingResultBuilder<0> Builder() {
    return SetTimingResultBuilder<0>();
  }

 private:
  SetTimingResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetTimingResult);
};


// Parameters for the AnimationCanceled event.
class HEADLESS_EXPORT AnimationCanceledParams {
 public:
  static std::unique_ptr<AnimationCanceledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AnimationCanceledParams() { }

  // Id of the animation that was cancelled.
  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AnimationCanceledParams> Clone() const;

  template<int STATE>
  class AnimationCanceledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdSet | 0)
    };

    AnimationCanceledParamsBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    std::unique_ptr<AnimationCanceledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AnimationCanceledParams;
    AnimationCanceledParamsBuilder() : result_(new AnimationCanceledParams()) { }

    template<int STEP> AnimationCanceledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AnimationCanceledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AnimationCanceledParams> result_;
  };

  static AnimationCanceledParamsBuilder<0> Builder() {
    return AnimationCanceledParamsBuilder<0>();
  }

 private:
  AnimationCanceledParams() { }

  std::string id_;

  DISALLOW_COPY_AND_ASSIGN(AnimationCanceledParams);
};


// Parameters for the AnimationCreated event.
class HEADLESS_EXPORT AnimationCreatedParams {
 public:
  static std::unique_ptr<AnimationCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AnimationCreatedParams() { }

  // Id of the animation that was created.
  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AnimationCreatedParams> Clone() const;

  template<int STATE>
  class AnimationCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdSet | 0)
    };

    AnimationCreatedParamsBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    std::unique_ptr<AnimationCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AnimationCreatedParams;
    AnimationCreatedParamsBuilder() : result_(new AnimationCreatedParams()) { }

    template<int STEP> AnimationCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AnimationCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AnimationCreatedParams> result_;
  };

  static AnimationCreatedParamsBuilder<0> Builder() {
    return AnimationCreatedParamsBuilder<0>();
  }

 private:
  AnimationCreatedParams() { }

  std::string id_;

  DISALLOW_COPY_AND_ASSIGN(AnimationCreatedParams);
};


// Parameters for the AnimationStarted event.
class HEADLESS_EXPORT AnimationStartedParams {
 public:
  static std::unique_ptr<AnimationStartedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AnimationStartedParams() { }

  // Animation that was started.
  const ::headless::animation::Animation* GetAnimation() const { return animation_.get(); }
  void SetAnimation(std::unique_ptr<::headless::animation::Animation> value) { animation_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AnimationStartedParams> Clone() const;

  template<int STATE>
  class AnimationStartedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAnimationSet = 1 << 1,
      kAllRequiredFieldsSet = (kAnimationSet | 0)
    };

    AnimationStartedParamsBuilder<STATE | kAnimationSet>& SetAnimation(std::unique_ptr<::headless::animation::Animation> value) {
      static_assert(!(STATE & kAnimationSet), "property animation should not have already been set");
      result_->SetAnimation(std::move(value));
      return CastState<kAnimationSet>();
    }

    std::unique_ptr<AnimationStartedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AnimationStartedParams;
    AnimationStartedParamsBuilder() : result_(new AnimationStartedParams()) { }

    template<int STEP> AnimationStartedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AnimationStartedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AnimationStartedParams> result_;
  };

  static AnimationStartedParamsBuilder<0> Builder() {
    return AnimationStartedParamsBuilder<0>();
  }

 private:
  AnimationStartedParams() { }

  std::unique_ptr<::headless::animation::Animation> animation_;

  DISALLOW_COPY_AND_ASSIGN(AnimationStartedParams);
};


}  // namespace animation

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_ANIMATION_H_
