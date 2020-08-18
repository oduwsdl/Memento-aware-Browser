// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_WEB_AUDIO_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_WEB_AUDIO_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_web_audio.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace web_audio {

// Fields in AudioContext that change in real-time.
class HEADLESS_EXPORT ContextRealtimeData {
 public:
  static std::unique_ptr<ContextRealtimeData> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContextRealtimeData() { }

  // The current context time in second in BaseAudioContext.
  double GetCurrentTime() const { return current_time_; }
  void SetCurrentTime(double value) { current_time_ = value; }

  // The time spent on rendering graph divided by render qunatum duration,
  // and multiplied by 100. 100 means the audio renderer reached the full
  // capacity and glitch may occur.
  double GetRenderCapacity() const { return render_capacity_; }
  void SetRenderCapacity(double value) { render_capacity_ = value; }

  // A running mean of callback interval.
  double GetCallbackIntervalMean() const { return callback_interval_mean_; }
  void SetCallbackIntervalMean(double value) { callback_interval_mean_ = value; }

  // A running variance of callback interval.
  double GetCallbackIntervalVariance() const { return callback_interval_variance_; }
  void SetCallbackIntervalVariance(double value) { callback_interval_variance_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContextRealtimeData> Clone() const;

  template<int STATE>
  class ContextRealtimeDataBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCurrentTimeSet = 1 << 1,
    kRenderCapacitySet = 1 << 2,
    kCallbackIntervalMeanSet = 1 << 3,
    kCallbackIntervalVarianceSet = 1 << 4,
      kAllRequiredFieldsSet = (kCurrentTimeSet | kRenderCapacitySet | kCallbackIntervalMeanSet | kCallbackIntervalVarianceSet | 0)
    };

    ContextRealtimeDataBuilder<STATE | kCurrentTimeSet>& SetCurrentTime(double value) {
      static_assert(!(STATE & kCurrentTimeSet), "property currentTime should not have already been set");
      result_->SetCurrentTime(value);
      return CastState<kCurrentTimeSet>();
    }

    ContextRealtimeDataBuilder<STATE | kRenderCapacitySet>& SetRenderCapacity(double value) {
      static_assert(!(STATE & kRenderCapacitySet), "property renderCapacity should not have already been set");
      result_->SetRenderCapacity(value);
      return CastState<kRenderCapacitySet>();
    }

    ContextRealtimeDataBuilder<STATE | kCallbackIntervalMeanSet>& SetCallbackIntervalMean(double value) {
      static_assert(!(STATE & kCallbackIntervalMeanSet), "property callbackIntervalMean should not have already been set");
      result_->SetCallbackIntervalMean(value);
      return CastState<kCallbackIntervalMeanSet>();
    }

    ContextRealtimeDataBuilder<STATE | kCallbackIntervalVarianceSet>& SetCallbackIntervalVariance(double value) {
      static_assert(!(STATE & kCallbackIntervalVarianceSet), "property callbackIntervalVariance should not have already been set");
      result_->SetCallbackIntervalVariance(value);
      return CastState<kCallbackIntervalVarianceSet>();
    }

    std::unique_ptr<ContextRealtimeData> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContextRealtimeData;
    ContextRealtimeDataBuilder() : result_(new ContextRealtimeData()) { }

    template<int STEP> ContextRealtimeDataBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContextRealtimeDataBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContextRealtimeData> result_;
  };

  static ContextRealtimeDataBuilder<0> Builder() {
    return ContextRealtimeDataBuilder<0>();
  }

 private:
  ContextRealtimeData() { }

  double current_time_;
  double render_capacity_;
  double callback_interval_mean_;
  double callback_interval_variance_;

  DISALLOW_COPY_AND_ASSIGN(ContextRealtimeData);
};


// Protocol object for BaseAudioContext
class HEADLESS_EXPORT BaseAudioContext {
 public:
  static std::unique_ptr<BaseAudioContext> Parse(const base::Value& value, ErrorReporter* errors);
  ~BaseAudioContext() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  ::headless::web_audio::ContextType GetContextType() const { return context_type_; }
  void SetContextType(::headless::web_audio::ContextType value) { context_type_ = value; }

  ::headless::web_audio::ContextState GetContextState() const { return context_state_; }
  void SetContextState(::headless::web_audio::ContextState value) { context_state_ = value; }

  bool HasRealtimeData() const { return !!realtime_data_; }
  const ::headless::web_audio::ContextRealtimeData* GetRealtimeData() const { DCHECK(HasRealtimeData()); return realtime_data_.value().get(); }
  void SetRealtimeData(std::unique_ptr<::headless::web_audio::ContextRealtimeData> value) { realtime_data_ = std::move(value); }

  // Platform-dependent callback buffer size.
  double GetCallbackBufferSize() const { return callback_buffer_size_; }
  void SetCallbackBufferSize(double value) { callback_buffer_size_ = value; }

  // Number of output channels supported by audio hardware in use.
  double GetMaxOutputChannelCount() const { return max_output_channel_count_; }
  void SetMaxOutputChannelCount(double value) { max_output_channel_count_ = value; }

  // Context sample rate.
  double GetSampleRate() const { return sample_rate_; }
  void SetSampleRate(double value) { sample_rate_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BaseAudioContext> Clone() const;

  template<int STATE>
  class BaseAudioContextBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kContextTypeSet = 1 << 2,
    kContextStateSet = 1 << 3,
    kCallbackBufferSizeSet = 1 << 4,
    kMaxOutputChannelCountSet = 1 << 5,
    kSampleRateSet = 1 << 6,
      kAllRequiredFieldsSet = (kContextIdSet | kContextTypeSet | kContextStateSet | kCallbackBufferSizeSet | kMaxOutputChannelCountSet | kSampleRateSet | 0)
    };

    BaseAudioContextBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    BaseAudioContextBuilder<STATE | kContextTypeSet>& SetContextType(::headless::web_audio::ContextType value) {
      static_assert(!(STATE & kContextTypeSet), "property contextType should not have already been set");
      result_->SetContextType(value);
      return CastState<kContextTypeSet>();
    }

    BaseAudioContextBuilder<STATE | kContextStateSet>& SetContextState(::headless::web_audio::ContextState value) {
      static_assert(!(STATE & kContextStateSet), "property contextState should not have already been set");
      result_->SetContextState(value);
      return CastState<kContextStateSet>();
    }

    BaseAudioContextBuilder<STATE>& SetRealtimeData(std::unique_ptr<::headless::web_audio::ContextRealtimeData> value) {
      result_->SetRealtimeData(std::move(value));
      return *this;
    }

    BaseAudioContextBuilder<STATE | kCallbackBufferSizeSet>& SetCallbackBufferSize(double value) {
      static_assert(!(STATE & kCallbackBufferSizeSet), "property callbackBufferSize should not have already been set");
      result_->SetCallbackBufferSize(value);
      return CastState<kCallbackBufferSizeSet>();
    }

    BaseAudioContextBuilder<STATE | kMaxOutputChannelCountSet>& SetMaxOutputChannelCount(double value) {
      static_assert(!(STATE & kMaxOutputChannelCountSet), "property maxOutputChannelCount should not have already been set");
      result_->SetMaxOutputChannelCount(value);
      return CastState<kMaxOutputChannelCountSet>();
    }

    BaseAudioContextBuilder<STATE | kSampleRateSet>& SetSampleRate(double value) {
      static_assert(!(STATE & kSampleRateSet), "property sampleRate should not have already been set");
      result_->SetSampleRate(value);
      return CastState<kSampleRateSet>();
    }

    std::unique_ptr<BaseAudioContext> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BaseAudioContext;
    BaseAudioContextBuilder() : result_(new BaseAudioContext()) { }

    template<int STEP> BaseAudioContextBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BaseAudioContextBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BaseAudioContext> result_;
  };

  static BaseAudioContextBuilder<0> Builder() {
    return BaseAudioContextBuilder<0>();
  }

 private:
  BaseAudioContext() { }

  std::string context_id_;
  ::headless::web_audio::ContextType context_type_;
  ::headless::web_audio::ContextState context_state_;
  base::Optional<std::unique_ptr<::headless::web_audio::ContextRealtimeData>> realtime_data_;
  double callback_buffer_size_;
  double max_output_channel_count_;
  double sample_rate_;

  DISALLOW_COPY_AND_ASSIGN(BaseAudioContext);
};


// Protocol object for AudioListner
class HEADLESS_EXPORT AudioListener {
 public:
  static std::unique_ptr<AudioListener> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioListener() { }

  std::string GetListenerId() const { return listener_id_; }
  void SetListenerId(const std::string& value) { listener_id_ = value; }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioListener> Clone() const;

  template<int STATE>
  class AudioListenerBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kListenerIdSet = 1 << 1,
    kContextIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kListenerIdSet | kContextIdSet | 0)
    };

    AudioListenerBuilder<STATE | kListenerIdSet>& SetListenerId(const std::string& value) {
      static_assert(!(STATE & kListenerIdSet), "property listenerId should not have already been set");
      result_->SetListenerId(value);
      return CastState<kListenerIdSet>();
    }

    AudioListenerBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    std::unique_ptr<AudioListener> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioListener;
    AudioListenerBuilder() : result_(new AudioListener()) { }

    template<int STEP> AudioListenerBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioListenerBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioListener> result_;
  };

  static AudioListenerBuilder<0> Builder() {
    return AudioListenerBuilder<0>();
  }

 private:
  AudioListener() { }

  std::string listener_id_;
  std::string context_id_;

  DISALLOW_COPY_AND_ASSIGN(AudioListener);
};


// Protocol object for AudioNode
class HEADLESS_EXPORT AudioNode {
 public:
  static std::unique_ptr<AudioNode> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioNode() { }

  std::string GetNodeId() const { return node_id_; }
  void SetNodeId(const std::string& value) { node_id_ = value; }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetNodeType() const { return node_type_; }
  void SetNodeType(const std::string& value) { node_type_ = value; }

  double GetNumberOfInputs() const { return number_of_inputs_; }
  void SetNumberOfInputs(double value) { number_of_inputs_ = value; }

  double GetNumberOfOutputs() const { return number_of_outputs_; }
  void SetNumberOfOutputs(double value) { number_of_outputs_ = value; }

  double GetChannelCount() const { return channel_count_; }
  void SetChannelCount(double value) { channel_count_ = value; }

  ::headless::web_audio::ChannelCountMode GetChannelCountMode() const { return channel_count_mode_; }
  void SetChannelCountMode(::headless::web_audio::ChannelCountMode value) { channel_count_mode_ = value; }

  ::headless::web_audio::ChannelInterpretation GetChannelInterpretation() const { return channel_interpretation_; }
  void SetChannelInterpretation(::headless::web_audio::ChannelInterpretation value) { channel_interpretation_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioNode> Clone() const;

  template<int STATE>
  class AudioNodeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kContextIdSet = 1 << 2,
    kNodeTypeSet = 1 << 3,
    kNumberOfInputsSet = 1 << 4,
    kNumberOfOutputsSet = 1 << 5,
    kChannelCountSet = 1 << 6,
    kChannelCountModeSet = 1 << 7,
    kChannelInterpretationSet = 1 << 8,
      kAllRequiredFieldsSet = (kNodeIdSet | kContextIdSet | kNodeTypeSet | kNumberOfInputsSet | kNumberOfOutputsSet | kChannelCountSet | kChannelCountModeSet | kChannelInterpretationSet | 0)
    };

    AudioNodeBuilder<STATE | kNodeIdSet>& SetNodeId(const std::string& value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    AudioNodeBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    AudioNodeBuilder<STATE | kNodeTypeSet>& SetNodeType(const std::string& value) {
      static_assert(!(STATE & kNodeTypeSet), "property nodeType should not have already been set");
      result_->SetNodeType(value);
      return CastState<kNodeTypeSet>();
    }

    AudioNodeBuilder<STATE | kNumberOfInputsSet>& SetNumberOfInputs(double value) {
      static_assert(!(STATE & kNumberOfInputsSet), "property numberOfInputs should not have already been set");
      result_->SetNumberOfInputs(value);
      return CastState<kNumberOfInputsSet>();
    }

    AudioNodeBuilder<STATE | kNumberOfOutputsSet>& SetNumberOfOutputs(double value) {
      static_assert(!(STATE & kNumberOfOutputsSet), "property numberOfOutputs should not have already been set");
      result_->SetNumberOfOutputs(value);
      return CastState<kNumberOfOutputsSet>();
    }

    AudioNodeBuilder<STATE | kChannelCountSet>& SetChannelCount(double value) {
      static_assert(!(STATE & kChannelCountSet), "property channelCount should not have already been set");
      result_->SetChannelCount(value);
      return CastState<kChannelCountSet>();
    }

    AudioNodeBuilder<STATE | kChannelCountModeSet>& SetChannelCountMode(::headless::web_audio::ChannelCountMode value) {
      static_assert(!(STATE & kChannelCountModeSet), "property channelCountMode should not have already been set");
      result_->SetChannelCountMode(value);
      return CastState<kChannelCountModeSet>();
    }

    AudioNodeBuilder<STATE | kChannelInterpretationSet>& SetChannelInterpretation(::headless::web_audio::ChannelInterpretation value) {
      static_assert(!(STATE & kChannelInterpretationSet), "property channelInterpretation should not have already been set");
      result_->SetChannelInterpretation(value);
      return CastState<kChannelInterpretationSet>();
    }

    std::unique_ptr<AudioNode> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioNode;
    AudioNodeBuilder() : result_(new AudioNode()) { }

    template<int STEP> AudioNodeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioNodeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioNode> result_;
  };

  static AudioNodeBuilder<0> Builder() {
    return AudioNodeBuilder<0>();
  }

 private:
  AudioNode() { }

  std::string node_id_;
  std::string context_id_;
  std::string node_type_;
  double number_of_inputs_;
  double number_of_outputs_;
  double channel_count_;
  ::headless::web_audio::ChannelCountMode channel_count_mode_;
  ::headless::web_audio::ChannelInterpretation channel_interpretation_;

  DISALLOW_COPY_AND_ASSIGN(AudioNode);
};


// Protocol object for AudioParam
class HEADLESS_EXPORT AudioParam {
 public:
  static std::unique_ptr<AudioParam> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioParam() { }

  std::string GetParamId() const { return param_id_; }
  void SetParamId(const std::string& value) { param_id_ = value; }

  std::string GetNodeId() const { return node_id_; }
  void SetNodeId(const std::string& value) { node_id_ = value; }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetParamType() const { return param_type_; }
  void SetParamType(const std::string& value) { param_type_ = value; }

  ::headless::web_audio::AutomationRate GetRate() const { return rate_; }
  void SetRate(::headless::web_audio::AutomationRate value) { rate_ = value; }

  double GetDefaultValue() const { return default_value_; }
  void SetDefaultValue(double value) { default_value_ = value; }

  double GetMinValue() const { return min_value_; }
  void SetMinValue(double value) { min_value_ = value; }

  double GetMaxValue() const { return max_value_; }
  void SetMaxValue(double value) { max_value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioParam> Clone() const;

  template<int STATE>
  class AudioParamBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kParamIdSet = 1 << 1,
    kNodeIdSet = 1 << 2,
    kContextIdSet = 1 << 3,
    kParamTypeSet = 1 << 4,
    kRateSet = 1 << 5,
    kDefaultValueSet = 1 << 6,
    kMinValueSet = 1 << 7,
    kMaxValueSet = 1 << 8,
      kAllRequiredFieldsSet = (kParamIdSet | kNodeIdSet | kContextIdSet | kParamTypeSet | kRateSet | kDefaultValueSet | kMinValueSet | kMaxValueSet | 0)
    };

    AudioParamBuilder<STATE | kParamIdSet>& SetParamId(const std::string& value) {
      static_assert(!(STATE & kParamIdSet), "property paramId should not have already been set");
      result_->SetParamId(value);
      return CastState<kParamIdSet>();
    }

    AudioParamBuilder<STATE | kNodeIdSet>& SetNodeId(const std::string& value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    AudioParamBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    AudioParamBuilder<STATE | kParamTypeSet>& SetParamType(const std::string& value) {
      static_assert(!(STATE & kParamTypeSet), "property paramType should not have already been set");
      result_->SetParamType(value);
      return CastState<kParamTypeSet>();
    }

    AudioParamBuilder<STATE | kRateSet>& SetRate(::headless::web_audio::AutomationRate value) {
      static_assert(!(STATE & kRateSet), "property rate should not have already been set");
      result_->SetRate(value);
      return CastState<kRateSet>();
    }

    AudioParamBuilder<STATE | kDefaultValueSet>& SetDefaultValue(double value) {
      static_assert(!(STATE & kDefaultValueSet), "property defaultValue should not have already been set");
      result_->SetDefaultValue(value);
      return CastState<kDefaultValueSet>();
    }

    AudioParamBuilder<STATE | kMinValueSet>& SetMinValue(double value) {
      static_assert(!(STATE & kMinValueSet), "property minValue should not have already been set");
      result_->SetMinValue(value);
      return CastState<kMinValueSet>();
    }

    AudioParamBuilder<STATE | kMaxValueSet>& SetMaxValue(double value) {
      static_assert(!(STATE & kMaxValueSet), "property maxValue should not have already been set");
      result_->SetMaxValue(value);
      return CastState<kMaxValueSet>();
    }

    std::unique_ptr<AudioParam> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioParam;
    AudioParamBuilder() : result_(new AudioParam()) { }

    template<int STEP> AudioParamBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioParamBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioParam> result_;
  };

  static AudioParamBuilder<0> Builder() {
    return AudioParamBuilder<0>();
  }

 private:
  AudioParam() { }

  std::string param_id_;
  std::string node_id_;
  std::string context_id_;
  std::string param_type_;
  ::headless::web_audio::AutomationRate rate_;
  double default_value_;
  double min_value_;
  double max_value_;

  DISALLOW_COPY_AND_ASSIGN(AudioParam);
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


// Parameters for the GetRealtimeData command.
class HEADLESS_EXPORT GetRealtimeDataParams {
 public:
  static std::unique_ptr<GetRealtimeDataParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRealtimeDataParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRealtimeDataParams> Clone() const;

  template<int STATE>
  class GetRealtimeDataParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kContextIdSet | 0)
    };

    GetRealtimeDataParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    std::unique_ptr<GetRealtimeDataParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRealtimeDataParams;
    GetRealtimeDataParamsBuilder() : result_(new GetRealtimeDataParams()) { }

    template<int STEP> GetRealtimeDataParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRealtimeDataParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRealtimeDataParams> result_;
  };

  static GetRealtimeDataParamsBuilder<0> Builder() {
    return GetRealtimeDataParamsBuilder<0>();
  }

 private:
  GetRealtimeDataParams() { }

  std::string context_id_;

  DISALLOW_COPY_AND_ASSIGN(GetRealtimeDataParams);
};


// Result for the GetRealtimeData command.
class HEADLESS_EXPORT GetRealtimeDataResult {
 public:
  static std::unique_ptr<GetRealtimeDataResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetRealtimeDataResult() { }

  const ::headless::web_audio::ContextRealtimeData* GetRealtimeData() const { return realtime_data_.get(); }
  void SetRealtimeData(std::unique_ptr<::headless::web_audio::ContextRealtimeData> value) { realtime_data_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetRealtimeDataResult> Clone() const;

  template<int STATE>
  class GetRealtimeDataResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRealtimeDataSet = 1 << 1,
      kAllRequiredFieldsSet = (kRealtimeDataSet | 0)
    };

    GetRealtimeDataResultBuilder<STATE | kRealtimeDataSet>& SetRealtimeData(std::unique_ptr<::headless::web_audio::ContextRealtimeData> value) {
      static_assert(!(STATE & kRealtimeDataSet), "property realtimeData should not have already been set");
      result_->SetRealtimeData(std::move(value));
      return CastState<kRealtimeDataSet>();
    }

    std::unique_ptr<GetRealtimeDataResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetRealtimeDataResult;
    GetRealtimeDataResultBuilder() : result_(new GetRealtimeDataResult()) { }

    template<int STEP> GetRealtimeDataResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetRealtimeDataResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetRealtimeDataResult> result_;
  };

  static GetRealtimeDataResultBuilder<0> Builder() {
    return GetRealtimeDataResultBuilder<0>();
  }

 private:
  GetRealtimeDataResult() { }

  std::unique_ptr<::headless::web_audio::ContextRealtimeData> realtime_data_;

  DISALLOW_COPY_AND_ASSIGN(GetRealtimeDataResult);
};


// Parameters for the ContextCreated event.
class HEADLESS_EXPORT ContextCreatedParams {
 public:
  static std::unique_ptr<ContextCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContextCreatedParams() { }

  const ::headless::web_audio::BaseAudioContext* GetContext() const { return context_.get(); }
  void SetContext(std::unique_ptr<::headless::web_audio::BaseAudioContext> value) { context_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContextCreatedParams> Clone() const;

  template<int STATE>
  class ContextCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextSet = 1 << 1,
      kAllRequiredFieldsSet = (kContextSet | 0)
    };

    ContextCreatedParamsBuilder<STATE | kContextSet>& SetContext(std::unique_ptr<::headless::web_audio::BaseAudioContext> value) {
      static_assert(!(STATE & kContextSet), "property context should not have already been set");
      result_->SetContext(std::move(value));
      return CastState<kContextSet>();
    }

    std::unique_ptr<ContextCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContextCreatedParams;
    ContextCreatedParamsBuilder() : result_(new ContextCreatedParams()) { }

    template<int STEP> ContextCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContextCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContextCreatedParams> result_;
  };

  static ContextCreatedParamsBuilder<0> Builder() {
    return ContextCreatedParamsBuilder<0>();
  }

 private:
  ContextCreatedParams() { }

  std::unique_ptr<::headless::web_audio::BaseAudioContext> context_;

  DISALLOW_COPY_AND_ASSIGN(ContextCreatedParams);
};


// Parameters for the ContextWillBeDestroyed event.
class HEADLESS_EXPORT ContextWillBeDestroyedParams {
 public:
  static std::unique_ptr<ContextWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContextWillBeDestroyedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContextWillBeDestroyedParams> Clone() const;

  template<int STATE>
  class ContextWillBeDestroyedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kContextIdSet | 0)
    };

    ContextWillBeDestroyedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    std::unique_ptr<ContextWillBeDestroyedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContextWillBeDestroyedParams;
    ContextWillBeDestroyedParamsBuilder() : result_(new ContextWillBeDestroyedParams()) { }

    template<int STEP> ContextWillBeDestroyedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContextWillBeDestroyedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContextWillBeDestroyedParams> result_;
  };

  static ContextWillBeDestroyedParamsBuilder<0> Builder() {
    return ContextWillBeDestroyedParamsBuilder<0>();
  }

 private:
  ContextWillBeDestroyedParams() { }

  std::string context_id_;

  DISALLOW_COPY_AND_ASSIGN(ContextWillBeDestroyedParams);
};


// Parameters for the ContextChanged event.
class HEADLESS_EXPORT ContextChangedParams {
 public:
  static std::unique_ptr<ContextChangedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ContextChangedParams() { }

  const ::headless::web_audio::BaseAudioContext* GetContext() const { return context_.get(); }
  void SetContext(std::unique_ptr<::headless::web_audio::BaseAudioContext> value) { context_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ContextChangedParams> Clone() const;

  template<int STATE>
  class ContextChangedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextSet = 1 << 1,
      kAllRequiredFieldsSet = (kContextSet | 0)
    };

    ContextChangedParamsBuilder<STATE | kContextSet>& SetContext(std::unique_ptr<::headless::web_audio::BaseAudioContext> value) {
      static_assert(!(STATE & kContextSet), "property context should not have already been set");
      result_->SetContext(std::move(value));
      return CastState<kContextSet>();
    }

    std::unique_ptr<ContextChangedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ContextChangedParams;
    ContextChangedParamsBuilder() : result_(new ContextChangedParams()) { }

    template<int STEP> ContextChangedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ContextChangedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ContextChangedParams> result_;
  };

  static ContextChangedParamsBuilder<0> Builder() {
    return ContextChangedParamsBuilder<0>();
  }

 private:
  ContextChangedParams() { }

  std::unique_ptr<::headless::web_audio::BaseAudioContext> context_;

  DISALLOW_COPY_AND_ASSIGN(ContextChangedParams);
};


// Parameters for the AudioListenerCreated event.
class HEADLESS_EXPORT AudioListenerCreatedParams {
 public:
  static std::unique_ptr<AudioListenerCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioListenerCreatedParams() { }

  const ::headless::web_audio::AudioListener* GetListener() const { return listener_.get(); }
  void SetListener(std::unique_ptr<::headless::web_audio::AudioListener> value) { listener_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioListenerCreatedParams> Clone() const;

  template<int STATE>
  class AudioListenerCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kListenerSet = 1 << 1,
      kAllRequiredFieldsSet = (kListenerSet | 0)
    };

    AudioListenerCreatedParamsBuilder<STATE | kListenerSet>& SetListener(std::unique_ptr<::headless::web_audio::AudioListener> value) {
      static_assert(!(STATE & kListenerSet), "property listener should not have already been set");
      result_->SetListener(std::move(value));
      return CastState<kListenerSet>();
    }

    std::unique_ptr<AudioListenerCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioListenerCreatedParams;
    AudioListenerCreatedParamsBuilder() : result_(new AudioListenerCreatedParams()) { }

    template<int STEP> AudioListenerCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioListenerCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioListenerCreatedParams> result_;
  };

  static AudioListenerCreatedParamsBuilder<0> Builder() {
    return AudioListenerCreatedParamsBuilder<0>();
  }

 private:
  AudioListenerCreatedParams() { }

  std::unique_ptr<::headless::web_audio::AudioListener> listener_;

  DISALLOW_COPY_AND_ASSIGN(AudioListenerCreatedParams);
};


// Parameters for the AudioListenerWillBeDestroyed event.
class HEADLESS_EXPORT AudioListenerWillBeDestroyedParams {
 public:
  static std::unique_ptr<AudioListenerWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioListenerWillBeDestroyedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetListenerId() const { return listener_id_; }
  void SetListenerId(const std::string& value) { listener_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioListenerWillBeDestroyedParams> Clone() const;

  template<int STATE>
  class AudioListenerWillBeDestroyedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kListenerIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kContextIdSet | kListenerIdSet | 0)
    };

    AudioListenerWillBeDestroyedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    AudioListenerWillBeDestroyedParamsBuilder<STATE | kListenerIdSet>& SetListenerId(const std::string& value) {
      static_assert(!(STATE & kListenerIdSet), "property listenerId should not have already been set");
      result_->SetListenerId(value);
      return CastState<kListenerIdSet>();
    }

    std::unique_ptr<AudioListenerWillBeDestroyedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioListenerWillBeDestroyedParams;
    AudioListenerWillBeDestroyedParamsBuilder() : result_(new AudioListenerWillBeDestroyedParams()) { }

    template<int STEP> AudioListenerWillBeDestroyedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioListenerWillBeDestroyedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioListenerWillBeDestroyedParams> result_;
  };

  static AudioListenerWillBeDestroyedParamsBuilder<0> Builder() {
    return AudioListenerWillBeDestroyedParamsBuilder<0>();
  }

 private:
  AudioListenerWillBeDestroyedParams() { }

  std::string context_id_;
  std::string listener_id_;

  DISALLOW_COPY_AND_ASSIGN(AudioListenerWillBeDestroyedParams);
};


// Parameters for the AudioNodeCreated event.
class HEADLESS_EXPORT AudioNodeCreatedParams {
 public:
  static std::unique_ptr<AudioNodeCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioNodeCreatedParams() { }

  const ::headless::web_audio::AudioNode* GetNode() const { return node_.get(); }
  void SetNode(std::unique_ptr<::headless::web_audio::AudioNode> value) { node_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioNodeCreatedParams> Clone() const;

  template<int STATE>
  class AudioNodeCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodeSet | 0)
    };

    AudioNodeCreatedParamsBuilder<STATE | kNodeSet>& SetNode(std::unique_ptr<::headless::web_audio::AudioNode> value) {
      static_assert(!(STATE & kNodeSet), "property node should not have already been set");
      result_->SetNode(std::move(value));
      return CastState<kNodeSet>();
    }

    std::unique_ptr<AudioNodeCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioNodeCreatedParams;
    AudioNodeCreatedParamsBuilder() : result_(new AudioNodeCreatedParams()) { }

    template<int STEP> AudioNodeCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioNodeCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioNodeCreatedParams> result_;
  };

  static AudioNodeCreatedParamsBuilder<0> Builder() {
    return AudioNodeCreatedParamsBuilder<0>();
  }

 private:
  AudioNodeCreatedParams() { }

  std::unique_ptr<::headless::web_audio::AudioNode> node_;

  DISALLOW_COPY_AND_ASSIGN(AudioNodeCreatedParams);
};


// Parameters for the AudioNodeWillBeDestroyed event.
class HEADLESS_EXPORT AudioNodeWillBeDestroyedParams {
 public:
  static std::unique_ptr<AudioNodeWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioNodeWillBeDestroyedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetNodeId() const { return node_id_; }
  void SetNodeId(const std::string& value) { node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioNodeWillBeDestroyedParams> Clone() const;

  template<int STATE>
  class AudioNodeWillBeDestroyedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kNodeIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kContextIdSet | kNodeIdSet | 0)
    };

    AudioNodeWillBeDestroyedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    AudioNodeWillBeDestroyedParamsBuilder<STATE | kNodeIdSet>& SetNodeId(const std::string& value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    std::unique_ptr<AudioNodeWillBeDestroyedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioNodeWillBeDestroyedParams;
    AudioNodeWillBeDestroyedParamsBuilder() : result_(new AudioNodeWillBeDestroyedParams()) { }

    template<int STEP> AudioNodeWillBeDestroyedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioNodeWillBeDestroyedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioNodeWillBeDestroyedParams> result_;
  };

  static AudioNodeWillBeDestroyedParamsBuilder<0> Builder() {
    return AudioNodeWillBeDestroyedParamsBuilder<0>();
  }

 private:
  AudioNodeWillBeDestroyedParams() { }

  std::string context_id_;
  std::string node_id_;

  DISALLOW_COPY_AND_ASSIGN(AudioNodeWillBeDestroyedParams);
};


// Parameters for the AudioParamCreated event.
class HEADLESS_EXPORT AudioParamCreatedParams {
 public:
  static std::unique_ptr<AudioParamCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioParamCreatedParams() { }

  const ::headless::web_audio::AudioParam* GetParam() const { return param_.get(); }
  void SetParam(std::unique_ptr<::headless::web_audio::AudioParam> value) { param_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioParamCreatedParams> Clone() const;

  template<int STATE>
  class AudioParamCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kParamSet = 1 << 1,
      kAllRequiredFieldsSet = (kParamSet | 0)
    };

    AudioParamCreatedParamsBuilder<STATE | kParamSet>& SetParam(std::unique_ptr<::headless::web_audio::AudioParam> value) {
      static_assert(!(STATE & kParamSet), "property param should not have already been set");
      result_->SetParam(std::move(value));
      return CastState<kParamSet>();
    }

    std::unique_ptr<AudioParamCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioParamCreatedParams;
    AudioParamCreatedParamsBuilder() : result_(new AudioParamCreatedParams()) { }

    template<int STEP> AudioParamCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioParamCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioParamCreatedParams> result_;
  };

  static AudioParamCreatedParamsBuilder<0> Builder() {
    return AudioParamCreatedParamsBuilder<0>();
  }

 private:
  AudioParamCreatedParams() { }

  std::unique_ptr<::headless::web_audio::AudioParam> param_;

  DISALLOW_COPY_AND_ASSIGN(AudioParamCreatedParams);
};


// Parameters for the AudioParamWillBeDestroyed event.
class HEADLESS_EXPORT AudioParamWillBeDestroyedParams {
 public:
  static std::unique_ptr<AudioParamWillBeDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AudioParamWillBeDestroyedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetNodeId() const { return node_id_; }
  void SetNodeId(const std::string& value) { node_id_ = value; }

  std::string GetParamId() const { return param_id_; }
  void SetParamId(const std::string& value) { param_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AudioParamWillBeDestroyedParams> Clone() const;

  template<int STATE>
  class AudioParamWillBeDestroyedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kNodeIdSet = 1 << 2,
    kParamIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kContextIdSet | kNodeIdSet | kParamIdSet | 0)
    };

    AudioParamWillBeDestroyedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    AudioParamWillBeDestroyedParamsBuilder<STATE | kNodeIdSet>& SetNodeId(const std::string& value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    AudioParamWillBeDestroyedParamsBuilder<STATE | kParamIdSet>& SetParamId(const std::string& value) {
      static_assert(!(STATE & kParamIdSet), "property paramId should not have already been set");
      result_->SetParamId(value);
      return CastState<kParamIdSet>();
    }

    std::unique_ptr<AudioParamWillBeDestroyedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AudioParamWillBeDestroyedParams;
    AudioParamWillBeDestroyedParamsBuilder() : result_(new AudioParamWillBeDestroyedParams()) { }

    template<int STEP> AudioParamWillBeDestroyedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AudioParamWillBeDestroyedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AudioParamWillBeDestroyedParams> result_;
  };

  static AudioParamWillBeDestroyedParamsBuilder<0> Builder() {
    return AudioParamWillBeDestroyedParamsBuilder<0>();
  }

 private:
  AudioParamWillBeDestroyedParams() { }

  std::string context_id_;
  std::string node_id_;
  std::string param_id_;

  DISALLOW_COPY_AND_ASSIGN(AudioParamWillBeDestroyedParams);
};


// Parameters for the NodesConnected event.
class HEADLESS_EXPORT NodesConnectedParams {
 public:
  static std::unique_ptr<NodesConnectedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NodesConnectedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetSourceId() const { return source_id_; }
  void SetSourceId(const std::string& value) { source_id_ = value; }

  std::string GetDestinationId() const { return destination_id_; }
  void SetDestinationId(const std::string& value) { destination_id_ = value; }

  bool HasSourceOutputIndex() const { return !!source_output_index_; }
  double GetSourceOutputIndex() const { DCHECK(HasSourceOutputIndex()); return source_output_index_.value(); }
  void SetSourceOutputIndex(double value) { source_output_index_ = value; }

  bool HasDestinationInputIndex() const { return !!destination_input_index_; }
  double GetDestinationInputIndex() const { DCHECK(HasDestinationInputIndex()); return destination_input_index_.value(); }
  void SetDestinationInputIndex(double value) { destination_input_index_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NodesConnectedParams> Clone() const;

  template<int STATE>
  class NodesConnectedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kSourceIdSet = 1 << 2,
    kDestinationIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kContextIdSet | kSourceIdSet | kDestinationIdSet | 0)
    };

    NodesConnectedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    NodesConnectedParamsBuilder<STATE | kSourceIdSet>& SetSourceId(const std::string& value) {
      static_assert(!(STATE & kSourceIdSet), "property sourceId should not have already been set");
      result_->SetSourceId(value);
      return CastState<kSourceIdSet>();
    }

    NodesConnectedParamsBuilder<STATE | kDestinationIdSet>& SetDestinationId(const std::string& value) {
      static_assert(!(STATE & kDestinationIdSet), "property destinationId should not have already been set");
      result_->SetDestinationId(value);
      return CastState<kDestinationIdSet>();
    }

    NodesConnectedParamsBuilder<STATE>& SetSourceOutputIndex(double value) {
      result_->SetSourceOutputIndex(value);
      return *this;
    }

    NodesConnectedParamsBuilder<STATE>& SetDestinationInputIndex(double value) {
      result_->SetDestinationInputIndex(value);
      return *this;
    }

    std::unique_ptr<NodesConnectedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NodesConnectedParams;
    NodesConnectedParamsBuilder() : result_(new NodesConnectedParams()) { }

    template<int STEP> NodesConnectedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NodesConnectedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NodesConnectedParams> result_;
  };

  static NodesConnectedParamsBuilder<0> Builder() {
    return NodesConnectedParamsBuilder<0>();
  }

 private:
  NodesConnectedParams() { }

  std::string context_id_;
  std::string source_id_;
  std::string destination_id_;
  base::Optional<double> source_output_index_;
  base::Optional<double> destination_input_index_;

  DISALLOW_COPY_AND_ASSIGN(NodesConnectedParams);
};


// Parameters for the NodesDisconnected event.
class HEADLESS_EXPORT NodesDisconnectedParams {
 public:
  static std::unique_ptr<NodesDisconnectedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NodesDisconnectedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetSourceId() const { return source_id_; }
  void SetSourceId(const std::string& value) { source_id_ = value; }

  std::string GetDestinationId() const { return destination_id_; }
  void SetDestinationId(const std::string& value) { destination_id_ = value; }

  bool HasSourceOutputIndex() const { return !!source_output_index_; }
  double GetSourceOutputIndex() const { DCHECK(HasSourceOutputIndex()); return source_output_index_.value(); }
  void SetSourceOutputIndex(double value) { source_output_index_ = value; }

  bool HasDestinationInputIndex() const { return !!destination_input_index_; }
  double GetDestinationInputIndex() const { DCHECK(HasDestinationInputIndex()); return destination_input_index_.value(); }
  void SetDestinationInputIndex(double value) { destination_input_index_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NodesDisconnectedParams> Clone() const;

  template<int STATE>
  class NodesDisconnectedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kSourceIdSet = 1 << 2,
    kDestinationIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kContextIdSet | kSourceIdSet | kDestinationIdSet | 0)
    };

    NodesDisconnectedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    NodesDisconnectedParamsBuilder<STATE | kSourceIdSet>& SetSourceId(const std::string& value) {
      static_assert(!(STATE & kSourceIdSet), "property sourceId should not have already been set");
      result_->SetSourceId(value);
      return CastState<kSourceIdSet>();
    }

    NodesDisconnectedParamsBuilder<STATE | kDestinationIdSet>& SetDestinationId(const std::string& value) {
      static_assert(!(STATE & kDestinationIdSet), "property destinationId should not have already been set");
      result_->SetDestinationId(value);
      return CastState<kDestinationIdSet>();
    }

    NodesDisconnectedParamsBuilder<STATE>& SetSourceOutputIndex(double value) {
      result_->SetSourceOutputIndex(value);
      return *this;
    }

    NodesDisconnectedParamsBuilder<STATE>& SetDestinationInputIndex(double value) {
      result_->SetDestinationInputIndex(value);
      return *this;
    }

    std::unique_ptr<NodesDisconnectedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NodesDisconnectedParams;
    NodesDisconnectedParamsBuilder() : result_(new NodesDisconnectedParams()) { }

    template<int STEP> NodesDisconnectedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NodesDisconnectedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NodesDisconnectedParams> result_;
  };

  static NodesDisconnectedParamsBuilder<0> Builder() {
    return NodesDisconnectedParamsBuilder<0>();
  }

 private:
  NodesDisconnectedParams() { }

  std::string context_id_;
  std::string source_id_;
  std::string destination_id_;
  base::Optional<double> source_output_index_;
  base::Optional<double> destination_input_index_;

  DISALLOW_COPY_AND_ASSIGN(NodesDisconnectedParams);
};


// Parameters for the NodeParamConnected event.
class HEADLESS_EXPORT NodeParamConnectedParams {
 public:
  static std::unique_ptr<NodeParamConnectedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NodeParamConnectedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetSourceId() const { return source_id_; }
  void SetSourceId(const std::string& value) { source_id_ = value; }

  std::string GetDestinationId() const { return destination_id_; }
  void SetDestinationId(const std::string& value) { destination_id_ = value; }

  bool HasSourceOutputIndex() const { return !!source_output_index_; }
  double GetSourceOutputIndex() const { DCHECK(HasSourceOutputIndex()); return source_output_index_.value(); }
  void SetSourceOutputIndex(double value) { source_output_index_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NodeParamConnectedParams> Clone() const;

  template<int STATE>
  class NodeParamConnectedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kSourceIdSet = 1 << 2,
    kDestinationIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kContextIdSet | kSourceIdSet | kDestinationIdSet | 0)
    };

    NodeParamConnectedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    NodeParamConnectedParamsBuilder<STATE | kSourceIdSet>& SetSourceId(const std::string& value) {
      static_assert(!(STATE & kSourceIdSet), "property sourceId should not have already been set");
      result_->SetSourceId(value);
      return CastState<kSourceIdSet>();
    }

    NodeParamConnectedParamsBuilder<STATE | kDestinationIdSet>& SetDestinationId(const std::string& value) {
      static_assert(!(STATE & kDestinationIdSet), "property destinationId should not have already been set");
      result_->SetDestinationId(value);
      return CastState<kDestinationIdSet>();
    }

    NodeParamConnectedParamsBuilder<STATE>& SetSourceOutputIndex(double value) {
      result_->SetSourceOutputIndex(value);
      return *this;
    }

    std::unique_ptr<NodeParamConnectedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NodeParamConnectedParams;
    NodeParamConnectedParamsBuilder() : result_(new NodeParamConnectedParams()) { }

    template<int STEP> NodeParamConnectedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NodeParamConnectedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NodeParamConnectedParams> result_;
  };

  static NodeParamConnectedParamsBuilder<0> Builder() {
    return NodeParamConnectedParamsBuilder<0>();
  }

 private:
  NodeParamConnectedParams() { }

  std::string context_id_;
  std::string source_id_;
  std::string destination_id_;
  base::Optional<double> source_output_index_;

  DISALLOW_COPY_AND_ASSIGN(NodeParamConnectedParams);
};


// Parameters for the NodeParamDisconnected event.
class HEADLESS_EXPORT NodeParamDisconnectedParams {
 public:
  static std::unique_ptr<NodeParamDisconnectedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NodeParamDisconnectedParams() { }

  std::string GetContextId() const { return context_id_; }
  void SetContextId(const std::string& value) { context_id_ = value; }

  std::string GetSourceId() const { return source_id_; }
  void SetSourceId(const std::string& value) { source_id_ = value; }

  std::string GetDestinationId() const { return destination_id_; }
  void SetDestinationId(const std::string& value) { destination_id_ = value; }

  bool HasSourceOutputIndex() const { return !!source_output_index_; }
  double GetSourceOutputIndex() const { DCHECK(HasSourceOutputIndex()); return source_output_index_.value(); }
  void SetSourceOutputIndex(double value) { source_output_index_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NodeParamDisconnectedParams> Clone() const;

  template<int STATE>
  class NodeParamDisconnectedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextIdSet = 1 << 1,
    kSourceIdSet = 1 << 2,
    kDestinationIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kContextIdSet | kSourceIdSet | kDestinationIdSet | 0)
    };

    NodeParamDisconnectedParamsBuilder<STATE | kContextIdSet>& SetContextId(const std::string& value) {
      static_assert(!(STATE & kContextIdSet), "property contextId should not have already been set");
      result_->SetContextId(value);
      return CastState<kContextIdSet>();
    }

    NodeParamDisconnectedParamsBuilder<STATE | kSourceIdSet>& SetSourceId(const std::string& value) {
      static_assert(!(STATE & kSourceIdSet), "property sourceId should not have already been set");
      result_->SetSourceId(value);
      return CastState<kSourceIdSet>();
    }

    NodeParamDisconnectedParamsBuilder<STATE | kDestinationIdSet>& SetDestinationId(const std::string& value) {
      static_assert(!(STATE & kDestinationIdSet), "property destinationId should not have already been set");
      result_->SetDestinationId(value);
      return CastState<kDestinationIdSet>();
    }

    NodeParamDisconnectedParamsBuilder<STATE>& SetSourceOutputIndex(double value) {
      result_->SetSourceOutputIndex(value);
      return *this;
    }

    std::unique_ptr<NodeParamDisconnectedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NodeParamDisconnectedParams;
    NodeParamDisconnectedParamsBuilder() : result_(new NodeParamDisconnectedParams()) { }

    template<int STEP> NodeParamDisconnectedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NodeParamDisconnectedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NodeParamDisconnectedParams> result_;
  };

  static NodeParamDisconnectedParamsBuilder<0> Builder() {
    return NodeParamDisconnectedParamsBuilder<0>();
  }

 private:
  NodeParamDisconnectedParams() { }

  std::string context_id_;
  std::string source_id_;
  std::string destination_id_;
  base::Optional<double> source_output_index_;

  DISALLOW_COPY_AND_ASSIGN(NodeParamDisconnectedParams);
};


}  // namespace web_audio

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_WEB_AUDIO_H_
