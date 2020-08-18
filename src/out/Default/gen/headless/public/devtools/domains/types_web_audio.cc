// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_web_audio.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_web_audio.h"

namespace headless {

namespace web_audio {

std::unique_ptr<ContextRealtimeData> ContextRealtimeData::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContextRealtimeData");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContextRealtimeData> result(new ContextRealtimeData());
  errors->Push();
  errors->SetName("ContextRealtimeData");
  const base::Value* current_time_value = value.FindKey("currentTime");
  if (current_time_value) {
    errors->SetName("currentTime");
    result->current_time_ = internal::FromValue<double>::Parse(*current_time_value, errors);
  } else {
    errors->AddError("required property missing: currentTime");
  }
  const base::Value* render_capacity_value = value.FindKey("renderCapacity");
  if (render_capacity_value) {
    errors->SetName("renderCapacity");
    result->render_capacity_ = internal::FromValue<double>::Parse(*render_capacity_value, errors);
  } else {
    errors->AddError("required property missing: renderCapacity");
  }
  const base::Value* callback_interval_mean_value = value.FindKey("callbackIntervalMean");
  if (callback_interval_mean_value) {
    errors->SetName("callbackIntervalMean");
    result->callback_interval_mean_ = internal::FromValue<double>::Parse(*callback_interval_mean_value, errors);
  } else {
    errors->AddError("required property missing: callbackIntervalMean");
  }
  const base::Value* callback_interval_variance_value = value.FindKey("callbackIntervalVariance");
  if (callback_interval_variance_value) {
    errors->SetName("callbackIntervalVariance");
    result->callback_interval_variance_ = internal::FromValue<double>::Parse(*callback_interval_variance_value, errors);
  } else {
    errors->AddError("required property missing: callbackIntervalVariance");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContextRealtimeData::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("currentTime", internal::ToValue(current_time_));
  result->Set("renderCapacity", internal::ToValue(render_capacity_));
  result->Set("callbackIntervalMean", internal::ToValue(callback_interval_mean_));
  result->Set("callbackIntervalVariance", internal::ToValue(callback_interval_variance_));
  return std::move(result);
}

std::unique_ptr<ContextRealtimeData> ContextRealtimeData::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContextRealtimeData> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BaseAudioContext> BaseAudioContext::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BaseAudioContext");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BaseAudioContext> result(new BaseAudioContext());
  errors->Push();
  errors->SetName("BaseAudioContext");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* context_type_value = value.FindKey("contextType");
  if (context_type_value) {
    errors->SetName("contextType");
    result->context_type_ = internal::FromValue<::headless::web_audio::ContextType>::Parse(*context_type_value, errors);
  } else {
    errors->AddError("required property missing: contextType");
  }
  const base::Value* context_state_value = value.FindKey("contextState");
  if (context_state_value) {
    errors->SetName("contextState");
    result->context_state_ = internal::FromValue<::headless::web_audio::ContextState>::Parse(*context_state_value, errors);
  } else {
    errors->AddError("required property missing: contextState");
  }
  const base::Value* realtime_data_value = value.FindKey("realtimeData");
  if (realtime_data_value) {
    errors->SetName("realtimeData");
    result->realtime_data_ = internal::FromValue<::headless::web_audio::ContextRealtimeData>::Parse(*realtime_data_value, errors);
  }
  const base::Value* callback_buffer_size_value = value.FindKey("callbackBufferSize");
  if (callback_buffer_size_value) {
    errors->SetName("callbackBufferSize");
    result->callback_buffer_size_ = internal::FromValue<double>::Parse(*callback_buffer_size_value, errors);
  } else {
    errors->AddError("required property missing: callbackBufferSize");
  }
  const base::Value* max_output_channel_count_value = value.FindKey("maxOutputChannelCount");
  if (max_output_channel_count_value) {
    errors->SetName("maxOutputChannelCount");
    result->max_output_channel_count_ = internal::FromValue<double>::Parse(*max_output_channel_count_value, errors);
  } else {
    errors->AddError("required property missing: maxOutputChannelCount");
  }
  const base::Value* sample_rate_value = value.FindKey("sampleRate");
  if (sample_rate_value) {
    errors->SetName("sampleRate");
    result->sample_rate_ = internal::FromValue<double>::Parse(*sample_rate_value, errors);
  } else {
    errors->AddError("required property missing: sampleRate");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BaseAudioContext::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("contextType", internal::ToValue(context_type_));
  result->Set("contextState", internal::ToValue(context_state_));
  if (realtime_data_)
    result->Set("realtimeData", internal::ToValue(*realtime_data_.value()));
  result->Set("callbackBufferSize", internal::ToValue(callback_buffer_size_));
  result->Set("maxOutputChannelCount", internal::ToValue(max_output_channel_count_));
  result->Set("sampleRate", internal::ToValue(sample_rate_));
  return std::move(result);
}

std::unique_ptr<BaseAudioContext> BaseAudioContext::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BaseAudioContext> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioListener> AudioListener::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioListener");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioListener> result(new AudioListener());
  errors->Push();
  errors->SetName("AudioListener");
  const base::Value* listener_id_value = value.FindKey("listenerId");
  if (listener_id_value) {
    errors->SetName("listenerId");
    result->listener_id_ = internal::FromValue<std::string>::Parse(*listener_id_value, errors);
  } else {
    errors->AddError("required property missing: listenerId");
  }
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioListener::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("listenerId", internal::ToValue(listener_id_));
  result->Set("contextId", internal::ToValue(context_id_));
  return std::move(result);
}

std::unique_ptr<AudioListener> AudioListener::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioListener> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioNode> AudioNode::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioNode");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioNode> result(new AudioNode());
  errors->Push();
  errors->SetName("AudioNode");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<std::string>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* node_type_value = value.FindKey("nodeType");
  if (node_type_value) {
    errors->SetName("nodeType");
    result->node_type_ = internal::FromValue<std::string>::Parse(*node_type_value, errors);
  } else {
    errors->AddError("required property missing: nodeType");
  }
  const base::Value* number_of_inputs_value = value.FindKey("numberOfInputs");
  if (number_of_inputs_value) {
    errors->SetName("numberOfInputs");
    result->number_of_inputs_ = internal::FromValue<double>::Parse(*number_of_inputs_value, errors);
  } else {
    errors->AddError("required property missing: numberOfInputs");
  }
  const base::Value* number_of_outputs_value = value.FindKey("numberOfOutputs");
  if (number_of_outputs_value) {
    errors->SetName("numberOfOutputs");
    result->number_of_outputs_ = internal::FromValue<double>::Parse(*number_of_outputs_value, errors);
  } else {
    errors->AddError("required property missing: numberOfOutputs");
  }
  const base::Value* channel_count_value = value.FindKey("channelCount");
  if (channel_count_value) {
    errors->SetName("channelCount");
    result->channel_count_ = internal::FromValue<double>::Parse(*channel_count_value, errors);
  } else {
    errors->AddError("required property missing: channelCount");
  }
  const base::Value* channel_count_mode_value = value.FindKey("channelCountMode");
  if (channel_count_mode_value) {
    errors->SetName("channelCountMode");
    result->channel_count_mode_ = internal::FromValue<::headless::web_audio::ChannelCountMode>::Parse(*channel_count_mode_value, errors);
  } else {
    errors->AddError("required property missing: channelCountMode");
  }
  const base::Value* channel_interpretation_value = value.FindKey("channelInterpretation");
  if (channel_interpretation_value) {
    errors->SetName("channelInterpretation");
    result->channel_interpretation_ = internal::FromValue<::headless::web_audio::ChannelInterpretation>::Parse(*channel_interpretation_value, errors);
  } else {
    errors->AddError("required property missing: channelInterpretation");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioNode::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("nodeType", internal::ToValue(node_type_));
  result->Set("numberOfInputs", internal::ToValue(number_of_inputs_));
  result->Set("numberOfOutputs", internal::ToValue(number_of_outputs_));
  result->Set("channelCount", internal::ToValue(channel_count_));
  result->Set("channelCountMode", internal::ToValue(channel_count_mode_));
  result->Set("channelInterpretation", internal::ToValue(channel_interpretation_));
  return std::move(result);
}

std::unique_ptr<AudioNode> AudioNode::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioNode> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioParam> AudioParam::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioParam");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioParam> result(new AudioParam());
  errors->Push();
  errors->SetName("AudioParam");
  const base::Value* param_id_value = value.FindKey("paramId");
  if (param_id_value) {
    errors->SetName("paramId");
    result->param_id_ = internal::FromValue<std::string>::Parse(*param_id_value, errors);
  } else {
    errors->AddError("required property missing: paramId");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<std::string>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* param_type_value = value.FindKey("paramType");
  if (param_type_value) {
    errors->SetName("paramType");
    result->param_type_ = internal::FromValue<std::string>::Parse(*param_type_value, errors);
  } else {
    errors->AddError("required property missing: paramType");
  }
  const base::Value* rate_value = value.FindKey("rate");
  if (rate_value) {
    errors->SetName("rate");
    result->rate_ = internal::FromValue<::headless::web_audio::AutomationRate>::Parse(*rate_value, errors);
  } else {
    errors->AddError("required property missing: rate");
  }
  const base::Value* default_value_value = value.FindKey("defaultValue");
  if (default_value_value) {
    errors->SetName("defaultValue");
    result->default_value_ = internal::FromValue<double>::Parse(*default_value_value, errors);
  } else {
    errors->AddError("required property missing: defaultValue");
  }
  const base::Value* min_value_value = value.FindKey("minValue");
  if (min_value_value) {
    errors->SetName("minValue");
    result->min_value_ = internal::FromValue<double>::Parse(*min_value_value, errors);
  } else {
    errors->AddError("required property missing: minValue");
  }
  const base::Value* max_value_value = value.FindKey("maxValue");
  if (max_value_value) {
    errors->SetName("maxValue");
    result->max_value_ = internal::FromValue<double>::Parse(*max_value_value, errors);
  } else {
    errors->AddError("required property missing: maxValue");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioParam::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("paramId", internal::ToValue(param_id_));
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("paramType", internal::ToValue(param_type_));
  result->Set("rate", internal::ToValue(rate_));
  result->Set("defaultValue", internal::ToValue(default_value_));
  result->Set("minValue", internal::ToValue(min_value_));
  result->Set("maxValue", internal::ToValue(max_value_));
  return std::move(result);
}

std::unique_ptr<AudioParam> AudioParam::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioParam> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<GetRealtimeDataParams> GetRealtimeDataParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRealtimeDataParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRealtimeDataParams> result(new GetRealtimeDataParams());
  errors->Push();
  errors->SetName("GetRealtimeDataParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRealtimeDataParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  return std::move(result);
}

std::unique_ptr<GetRealtimeDataParams> GetRealtimeDataParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRealtimeDataParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetRealtimeDataResult> GetRealtimeDataResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetRealtimeDataResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetRealtimeDataResult> result(new GetRealtimeDataResult());
  errors->Push();
  errors->SetName("GetRealtimeDataResult");
  const base::Value* realtime_data_value = value.FindKey("realtimeData");
  if (realtime_data_value) {
    errors->SetName("realtimeData");
    result->realtime_data_ = internal::FromValue<::headless::web_audio::ContextRealtimeData>::Parse(*realtime_data_value, errors);
  } else {
    errors->AddError("required property missing: realtimeData");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetRealtimeDataResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("realtimeData", internal::ToValue(*realtime_data_));
  return std::move(result);
}

std::unique_ptr<GetRealtimeDataResult> GetRealtimeDataResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetRealtimeDataResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContextCreatedParams> ContextCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContextCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContextCreatedParams> result(new ContextCreatedParams());
  errors->Push();
  errors->SetName("ContextCreatedParams");
  const base::Value* context_value = value.FindKey("context");
  if (context_value) {
    errors->SetName("context");
    result->context_ = internal::FromValue<::headless::web_audio::BaseAudioContext>::Parse(*context_value, errors);
  } else {
    errors->AddError("required property missing: context");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContextCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("context", internal::ToValue(*context_));
  return std::move(result);
}

std::unique_ptr<ContextCreatedParams> ContextCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContextCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContextWillBeDestroyedParams> ContextWillBeDestroyedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContextWillBeDestroyedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContextWillBeDestroyedParams> result(new ContextWillBeDestroyedParams());
  errors->Push();
  errors->SetName("ContextWillBeDestroyedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContextWillBeDestroyedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  return std::move(result);
}

std::unique_ptr<ContextWillBeDestroyedParams> ContextWillBeDestroyedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContextWillBeDestroyedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ContextChangedParams> ContextChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ContextChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ContextChangedParams> result(new ContextChangedParams());
  errors->Push();
  errors->SetName("ContextChangedParams");
  const base::Value* context_value = value.FindKey("context");
  if (context_value) {
    errors->SetName("context");
    result->context_ = internal::FromValue<::headless::web_audio::BaseAudioContext>::Parse(*context_value, errors);
  } else {
    errors->AddError("required property missing: context");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ContextChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("context", internal::ToValue(*context_));
  return std::move(result);
}

std::unique_ptr<ContextChangedParams> ContextChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ContextChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioListenerCreatedParams> AudioListenerCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioListenerCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioListenerCreatedParams> result(new AudioListenerCreatedParams());
  errors->Push();
  errors->SetName("AudioListenerCreatedParams");
  const base::Value* listener_value = value.FindKey("listener");
  if (listener_value) {
    errors->SetName("listener");
    result->listener_ = internal::FromValue<::headless::web_audio::AudioListener>::Parse(*listener_value, errors);
  } else {
    errors->AddError("required property missing: listener");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioListenerCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("listener", internal::ToValue(*listener_));
  return std::move(result);
}

std::unique_ptr<AudioListenerCreatedParams> AudioListenerCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioListenerCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioListenerWillBeDestroyedParams> AudioListenerWillBeDestroyedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioListenerWillBeDestroyedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioListenerWillBeDestroyedParams> result(new AudioListenerWillBeDestroyedParams());
  errors->Push();
  errors->SetName("AudioListenerWillBeDestroyedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* listener_id_value = value.FindKey("listenerId");
  if (listener_id_value) {
    errors->SetName("listenerId");
    result->listener_id_ = internal::FromValue<std::string>::Parse(*listener_id_value, errors);
  } else {
    errors->AddError("required property missing: listenerId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioListenerWillBeDestroyedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("listenerId", internal::ToValue(listener_id_));
  return std::move(result);
}

std::unique_ptr<AudioListenerWillBeDestroyedParams> AudioListenerWillBeDestroyedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioListenerWillBeDestroyedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioNodeCreatedParams> AudioNodeCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioNodeCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioNodeCreatedParams> result(new AudioNodeCreatedParams());
  errors->Push();
  errors->SetName("AudioNodeCreatedParams");
  const base::Value* node_value = value.FindKey("node");
  if (node_value) {
    errors->SetName("node");
    result->node_ = internal::FromValue<::headless::web_audio::AudioNode>::Parse(*node_value, errors);
  } else {
    errors->AddError("required property missing: node");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioNodeCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("node", internal::ToValue(*node_));
  return std::move(result);
}

std::unique_ptr<AudioNodeCreatedParams> AudioNodeCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioNodeCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioNodeWillBeDestroyedParams> AudioNodeWillBeDestroyedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioNodeWillBeDestroyedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioNodeWillBeDestroyedParams> result(new AudioNodeWillBeDestroyedParams());
  errors->Push();
  errors->SetName("AudioNodeWillBeDestroyedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<std::string>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioNodeWillBeDestroyedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<AudioNodeWillBeDestroyedParams> AudioNodeWillBeDestroyedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioNodeWillBeDestroyedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioParamCreatedParams> AudioParamCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioParamCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioParamCreatedParams> result(new AudioParamCreatedParams());
  errors->Push();
  errors->SetName("AudioParamCreatedParams");
  const base::Value* param_value = value.FindKey("param");
  if (param_value) {
    errors->SetName("param");
    result->param_ = internal::FromValue<::headless::web_audio::AudioParam>::Parse(*param_value, errors);
  } else {
    errors->AddError("required property missing: param");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioParamCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("param", internal::ToValue(*param_));
  return std::move(result);
}

std::unique_ptr<AudioParamCreatedParams> AudioParamCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioParamCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AudioParamWillBeDestroyedParams> AudioParamWillBeDestroyedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AudioParamWillBeDestroyedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AudioParamWillBeDestroyedParams> result(new AudioParamWillBeDestroyedParams());
  errors->Push();
  errors->SetName("AudioParamWillBeDestroyedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<std::string>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* param_id_value = value.FindKey("paramId");
  if (param_id_value) {
    errors->SetName("paramId");
    result->param_id_ = internal::FromValue<std::string>::Parse(*param_id_value, errors);
  } else {
    errors->AddError("required property missing: paramId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AudioParamWillBeDestroyedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("paramId", internal::ToValue(param_id_));
  return std::move(result);
}

std::unique_ptr<AudioParamWillBeDestroyedParams> AudioParamWillBeDestroyedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AudioParamWillBeDestroyedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NodesConnectedParams> NodesConnectedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NodesConnectedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NodesConnectedParams> result(new NodesConnectedParams());
  errors->Push();
  errors->SetName("NodesConnectedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* source_id_value = value.FindKey("sourceId");
  if (source_id_value) {
    errors->SetName("sourceId");
    result->source_id_ = internal::FromValue<std::string>::Parse(*source_id_value, errors);
  } else {
    errors->AddError("required property missing: sourceId");
  }
  const base::Value* destination_id_value = value.FindKey("destinationId");
  if (destination_id_value) {
    errors->SetName("destinationId");
    result->destination_id_ = internal::FromValue<std::string>::Parse(*destination_id_value, errors);
  } else {
    errors->AddError("required property missing: destinationId");
  }
  const base::Value* source_output_index_value = value.FindKey("sourceOutputIndex");
  if (source_output_index_value) {
    errors->SetName("sourceOutputIndex");
    result->source_output_index_ = internal::FromValue<double>::Parse(*source_output_index_value, errors);
  }
  const base::Value* destination_input_index_value = value.FindKey("destinationInputIndex");
  if (destination_input_index_value) {
    errors->SetName("destinationInputIndex");
    result->destination_input_index_ = internal::FromValue<double>::Parse(*destination_input_index_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NodesConnectedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("sourceId", internal::ToValue(source_id_));
  result->Set("destinationId", internal::ToValue(destination_id_));
  if (source_output_index_)
    result->Set("sourceOutputIndex", internal::ToValue(source_output_index_.value()));
  if (destination_input_index_)
    result->Set("destinationInputIndex", internal::ToValue(destination_input_index_.value()));
  return std::move(result);
}

std::unique_ptr<NodesConnectedParams> NodesConnectedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NodesConnectedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NodesDisconnectedParams> NodesDisconnectedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NodesDisconnectedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NodesDisconnectedParams> result(new NodesDisconnectedParams());
  errors->Push();
  errors->SetName("NodesDisconnectedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* source_id_value = value.FindKey("sourceId");
  if (source_id_value) {
    errors->SetName("sourceId");
    result->source_id_ = internal::FromValue<std::string>::Parse(*source_id_value, errors);
  } else {
    errors->AddError("required property missing: sourceId");
  }
  const base::Value* destination_id_value = value.FindKey("destinationId");
  if (destination_id_value) {
    errors->SetName("destinationId");
    result->destination_id_ = internal::FromValue<std::string>::Parse(*destination_id_value, errors);
  } else {
    errors->AddError("required property missing: destinationId");
  }
  const base::Value* source_output_index_value = value.FindKey("sourceOutputIndex");
  if (source_output_index_value) {
    errors->SetName("sourceOutputIndex");
    result->source_output_index_ = internal::FromValue<double>::Parse(*source_output_index_value, errors);
  }
  const base::Value* destination_input_index_value = value.FindKey("destinationInputIndex");
  if (destination_input_index_value) {
    errors->SetName("destinationInputIndex");
    result->destination_input_index_ = internal::FromValue<double>::Parse(*destination_input_index_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NodesDisconnectedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("sourceId", internal::ToValue(source_id_));
  result->Set("destinationId", internal::ToValue(destination_id_));
  if (source_output_index_)
    result->Set("sourceOutputIndex", internal::ToValue(source_output_index_.value()));
  if (destination_input_index_)
    result->Set("destinationInputIndex", internal::ToValue(destination_input_index_.value()));
  return std::move(result);
}

std::unique_ptr<NodesDisconnectedParams> NodesDisconnectedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NodesDisconnectedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NodeParamConnectedParams> NodeParamConnectedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NodeParamConnectedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NodeParamConnectedParams> result(new NodeParamConnectedParams());
  errors->Push();
  errors->SetName("NodeParamConnectedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* source_id_value = value.FindKey("sourceId");
  if (source_id_value) {
    errors->SetName("sourceId");
    result->source_id_ = internal::FromValue<std::string>::Parse(*source_id_value, errors);
  } else {
    errors->AddError("required property missing: sourceId");
  }
  const base::Value* destination_id_value = value.FindKey("destinationId");
  if (destination_id_value) {
    errors->SetName("destinationId");
    result->destination_id_ = internal::FromValue<std::string>::Parse(*destination_id_value, errors);
  } else {
    errors->AddError("required property missing: destinationId");
  }
  const base::Value* source_output_index_value = value.FindKey("sourceOutputIndex");
  if (source_output_index_value) {
    errors->SetName("sourceOutputIndex");
    result->source_output_index_ = internal::FromValue<double>::Parse(*source_output_index_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NodeParamConnectedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("sourceId", internal::ToValue(source_id_));
  result->Set("destinationId", internal::ToValue(destination_id_));
  if (source_output_index_)
    result->Set("sourceOutputIndex", internal::ToValue(source_output_index_.value()));
  return std::move(result);
}

std::unique_ptr<NodeParamConnectedParams> NodeParamConnectedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NodeParamConnectedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NodeParamDisconnectedParams> NodeParamDisconnectedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NodeParamDisconnectedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NodeParamDisconnectedParams> result(new NodeParamDisconnectedParams());
  errors->Push();
  errors->SetName("NodeParamDisconnectedParams");
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<std::string>::Parse(*context_id_value, errors);
  } else {
    errors->AddError("required property missing: contextId");
  }
  const base::Value* source_id_value = value.FindKey("sourceId");
  if (source_id_value) {
    errors->SetName("sourceId");
    result->source_id_ = internal::FromValue<std::string>::Parse(*source_id_value, errors);
  } else {
    errors->AddError("required property missing: sourceId");
  }
  const base::Value* destination_id_value = value.FindKey("destinationId");
  if (destination_id_value) {
    errors->SetName("destinationId");
    result->destination_id_ = internal::FromValue<std::string>::Parse(*destination_id_value, errors);
  } else {
    errors->AddError("required property missing: destinationId");
  }
  const base::Value* source_output_index_value = value.FindKey("sourceOutputIndex");
  if (source_output_index_value) {
    errors->SetName("sourceOutputIndex");
    result->source_output_index_ = internal::FromValue<double>::Parse(*source_output_index_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NodeParamDisconnectedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("contextId", internal::ToValue(context_id_));
  result->Set("sourceId", internal::ToValue(source_id_));
  result->Set("destinationId", internal::ToValue(destination_id_));
  if (source_output_index_)
    result->Set("sourceOutputIndex", internal::ToValue(source_output_index_.value()));
  return std::move(result);
}

std::unique_ptr<NodeParamDisconnectedParams> NodeParamDisconnectedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NodeParamDisconnectedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace web_audio
}  // namespace headless
