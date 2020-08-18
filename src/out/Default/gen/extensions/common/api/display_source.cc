// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/display_source.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/display_source.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace display_source {
//
// Types
//

const char* ToString(ErrorType enum_param) {
  switch (enum_param) {
    case ERROR_TYPE_CONNECTION_ERROR:
      return "connection_error";
    case ERROR_TYPE_CAPABILITIES_NEGOTIATION_ERROR:
      return "capabilities_negotiation_error";
    case ERROR_TYPE_MEDIA_PIPELINE_ERROR:
      return "media_pipeline_error";
    case ERROR_TYPE_TIMEOUT_ERROR:
      return "timeout_error";
    case ERROR_TYPE_UNKNOWN_ERROR:
      return "unknown_error";
    case ERROR_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ErrorType ParseErrorType(const std::string& enum_string) {
  if (enum_string == "connection_error")
    return ERROR_TYPE_CONNECTION_ERROR;
  if (enum_string == "capabilities_negotiation_error")
    return ERROR_TYPE_CAPABILITIES_NEGOTIATION_ERROR;
  if (enum_string == "media_pipeline_error")
    return ERROR_TYPE_MEDIA_PIPELINE_ERROR;
  if (enum_string == "timeout_error")
    return ERROR_TYPE_TIMEOUT_ERROR;
  if (enum_string == "unknown_error")
    return ERROR_TYPE_UNKNOWN_ERROR;
  return ERROR_TYPE_NONE;
}


ErrorInfo::ErrorInfo()
: type(ERROR_TYPE_NONE) {}

ErrorInfo::~ErrorInfo() {}
ErrorInfo::ErrorInfo(ErrorInfo&& rhs)
: type(rhs.type),
description(std::move(rhs.description)){
}

ErrorInfo& ErrorInfo::operator=(ErrorInfo&& rhs)
{
type = rhs.type;
description = std::move(rhs.description);
return *this;
}

// static
bool ErrorInfo::Populate(
    const base::Value& value, ErrorInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string error_type_as_string;
    if (!type_value->GetAsString(&error_type_as_string)) {
      return false;
    }
    out->type = ParseErrorType(error_type_as_string);
    if (out->type == ERROR_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* description_value = NULL;
  if (dict->GetWithoutPathExpansion("description", &description_value)) {
    {
      std::string temp;
      if (!description_value->GetAsString(&temp)) {
        out->description.reset();
        return false;
      }
      else
        out->description.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ErrorInfo> ErrorInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ErrorInfo> out(new ErrorInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ErrorInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(display_source::ToString(this->type)));

  if (this->description.get()) {
    to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(*this->description));

  }

  return to_value_result;
}


const char* ToString(SinkState enum_param) {
  switch (enum_param) {
    case SINK_STATE_CONNECTED:
      return "Connected";
    case SINK_STATE_CONNECTING:
      return "Connecting";
    case SINK_STATE_DISCONNECTED:
      return "Disconnected";
    case SINK_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SinkState ParseSinkState(const std::string& enum_string) {
  if (enum_string == "Connected")
    return SINK_STATE_CONNECTED;
  if (enum_string == "Connecting")
    return SINK_STATE_CONNECTING;
  if (enum_string == "Disconnected")
    return SINK_STATE_DISCONNECTED;
  return SINK_STATE_NONE;
}


SinkInfo::SinkInfo()
: id(0),
state(SINK_STATE_NONE) {}

SinkInfo::~SinkInfo() {}
SinkInfo::SinkInfo(SinkInfo&& rhs)
: id(rhs.id),
name(std::move(rhs.name)),
state(rhs.state){
}

SinkInfo& SinkInfo::operator=(SinkInfo&& rhs)
{
id = rhs.id;
name = std::move(rhs.name);
state = rhs.state;
return *this;
}

// static
bool SinkInfo::Populate(
    const base::Value& value, SinkInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("state", &state_value)) {
    return false;
  }
  {
    std::string sink_state_as_string;
    if (!state_value->GetAsString(&sink_state_as_string)) {
      return false;
    }
    out->state = ParseSinkState(sink_state_as_string);
    if (out->state == SINK_STATE_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SinkInfo> SinkInfo::FromValue(const base::Value& value) {
  std::unique_ptr<SinkInfo> out(new SinkInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SinkInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(display_source::ToString(this->state)));


  return to_value_result;
}


const char* ToString(AuthenticationMethod enum_param) {
  switch (enum_param) {
    case AUTHENTICATION_METHOD_PBC:
      return "PBC";
    case AUTHENTICATION_METHOD_PIN:
      return "PIN";
    case AUTHENTICATION_METHOD_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

AuthenticationMethod ParseAuthenticationMethod(const std::string& enum_string) {
  if (enum_string == "PBC")
    return AUTHENTICATION_METHOD_PBC;
  if (enum_string == "PIN")
    return AUTHENTICATION_METHOD_PIN;
  return AUTHENTICATION_METHOD_NONE;
}


AuthenticationInfo::AuthenticationInfo()
: method(AUTHENTICATION_METHOD_NONE) {}

AuthenticationInfo::~AuthenticationInfo() {}
AuthenticationInfo::AuthenticationInfo(AuthenticationInfo&& rhs)
: method(rhs.method),
data(std::move(rhs.data)){
}

AuthenticationInfo& AuthenticationInfo::operator=(AuthenticationInfo&& rhs)
{
method = rhs.method;
data = std::move(rhs.data);
return *this;
}

// static
bool AuthenticationInfo::Populate(
    const base::Value& value, AuthenticationInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* method_value = NULL;
  if (!dict->GetWithoutPathExpansion("method", &method_value)) {
    return false;
  }
  {
    std::string authentication_method_as_string;
    if (!method_value->GetAsString(&authentication_method_as_string)) {
      return false;
    }
    out->method = ParseAuthenticationMethod(authentication_method_as_string);
    if (out->method == AUTHENTICATION_METHOD_NONE) {
      return false;
    }
  }

  const base::Value* data_value = NULL;
  if (dict->GetWithoutPathExpansion("data", &data_value)) {
    {
      std::string temp;
      if (!data_value->GetAsString(&temp)) {
        out->data.reset();
        return false;
      }
      else
        out->data.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<AuthenticationInfo> AuthenticationInfo::FromValue(const base::Value& value) {
  std::unique_ptr<AuthenticationInfo> out(new AuthenticationInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AuthenticationInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("method", std::make_unique<base::Value>(display_source::ToString(this->method)));

  if (this->data.get()) {
    to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(*this->data));

  }

  return to_value_result;
}


StartSessionInfo::AudioTrack::AudioTrack()
 {}

StartSessionInfo::AudioTrack::~AudioTrack() {}
StartSessionInfo::AudioTrack::AudioTrack(AudioTrack&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

StartSessionInfo::AudioTrack& StartSessionInfo::AudioTrack::operator=(AudioTrack&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool StartSessionInfo::AudioTrack::Populate(
    const base::Value& value, AudioTrack* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> StartSessionInfo::AudioTrack::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


StartSessionInfo::VideoTrack::VideoTrack()
 {}

StartSessionInfo::VideoTrack::~VideoTrack() {}
StartSessionInfo::VideoTrack::VideoTrack(VideoTrack&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

StartSessionInfo::VideoTrack& StartSessionInfo::VideoTrack::operator=(VideoTrack&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool StartSessionInfo::VideoTrack::Populate(
    const base::Value& value, VideoTrack* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> StartSessionInfo::VideoTrack::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



StartSessionInfo::StartSessionInfo()
: sink_id(0) {}

StartSessionInfo::~StartSessionInfo() {}
StartSessionInfo::StartSessionInfo(StartSessionInfo&& rhs)
: sink_id(rhs.sink_id),
authentication_info(std::move(rhs.authentication_info)),
audio_track(std::move(rhs.audio_track)),
video_track(std::move(rhs.video_track)){
}

StartSessionInfo& StartSessionInfo::operator=(StartSessionInfo&& rhs)
{
sink_id = rhs.sink_id;
authentication_info = std::move(rhs.authentication_info);
audio_track = std::move(rhs.audio_track);
video_track = std::move(rhs.video_track);
return *this;
}

// static
bool StartSessionInfo::Populate(
    const base::Value& value, StartSessionInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* sink_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("sinkId", &sink_id_value)) {
    return false;
  }
  {
    if (!sink_id_value->GetAsInteger(&out->sink_id)) {
      return false;
    }
  }

  const base::Value* authentication_info_value = NULL;
  if (dict->GetWithoutPathExpansion("authenticationInfo", &authentication_info_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!authentication_info_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<AuthenticationInfo> temp(new AuthenticationInfo());
        if (!AuthenticationInfo::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->authentication_info = std::move(temp);
      }
    }
  }

  const base::Value* audio_track_value = NULL;
  if (dict->GetWithoutPathExpansion("audioTrack", &audio_track_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!audio_track_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<AudioTrack> temp(new AudioTrack());
        if (!AudioTrack::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->audio_track = std::move(temp);
      }
    }
  }

  const base::Value* video_track_value = NULL;
  if (dict->GetWithoutPathExpansion("videoTrack", &video_track_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!video_track_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<VideoTrack> temp(new VideoTrack());
        if (!VideoTrack::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->video_track = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<StartSessionInfo> StartSessionInfo::FromValue(const base::Value& value) {
  std::unique_ptr<StartSessionInfo> out(new StartSessionInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> StartSessionInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("sinkId", std::make_unique<base::Value>(this->sink_id));

  if (this->authentication_info.get()) {
    to_value_result->SetWithoutPathExpansion("authenticationInfo", (this->authentication_info)->ToValue());

  }
  if (this->audio_track.get()) {
    to_value_result->SetWithoutPathExpansion("audioTrack", (this->audio_track)->ToValue());

  }
  if (this->video_track.get()) {
    to_value_result->SetWithoutPathExpansion("videoTrack", (this->video_track)->ToValue());

  }

  return to_value_result;
}



//
// Functions
//

namespace GetAvailableSinks {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<SinkInfo>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetAvailableSinks

namespace RequestAuthentication {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* sink_id_value = NULL;
  if (args.Get(0, &sink_id_value) &&
      !sink_id_value->is_none()) {
    {
      if (!sink_id_value->GetAsInteger(&params->sink_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const AuthenticationInfo& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace RequestAuthentication

//
// Events
//

namespace OnSinksUpdated {

const char kEventName[] = "displaySource.onSinksUpdated";

std::unique_ptr<base::ListValue> Create(const std::vector<SinkInfo>& sinks) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(sinks));

  return create_results;
}

}  // namespace OnSinksUpdated

}  // namespace display_source
}  // namespace api
}  // namespace extensions

