// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/audio.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/audio.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace audio {
//
// Types
//

const char* ToString(StreamType enum_param) {
  switch (enum_param) {
    case STREAM_TYPE_INPUT:
      return "INPUT";
    case STREAM_TYPE_OUTPUT:
      return "OUTPUT";
    case STREAM_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

StreamType ParseStreamType(const std::string& enum_string) {
  if (enum_string == "INPUT")
    return STREAM_TYPE_INPUT;
  if (enum_string == "OUTPUT")
    return STREAM_TYPE_OUTPUT;
  return STREAM_TYPE_NONE;
}


const char* ToString(DeviceType enum_param) {
  switch (enum_param) {
    case DEVICE_TYPE_HEADPHONE:
      return "HEADPHONE";
    case DEVICE_TYPE_MIC:
      return "MIC";
    case DEVICE_TYPE_USB:
      return "USB";
    case DEVICE_TYPE_BLUETOOTH:
      return "BLUETOOTH";
    case DEVICE_TYPE_HDMI:
      return "HDMI";
    case DEVICE_TYPE_INTERNAL_SPEAKER:
      return "INTERNAL_SPEAKER";
    case DEVICE_TYPE_INTERNAL_MIC:
      return "INTERNAL_MIC";
    case DEVICE_TYPE_FRONT_MIC:
      return "FRONT_MIC";
    case DEVICE_TYPE_REAR_MIC:
      return "REAR_MIC";
    case DEVICE_TYPE_KEYBOARD_MIC:
      return "KEYBOARD_MIC";
    case DEVICE_TYPE_HOTWORD:
      return "HOTWORD";
    case DEVICE_TYPE_LINEOUT:
      return "LINEOUT";
    case DEVICE_TYPE_POST_MIX_LOOPBACK:
      return "POST_MIX_LOOPBACK";
    case DEVICE_TYPE_POST_DSP_LOOPBACK:
      return "POST_DSP_LOOPBACK";
    case DEVICE_TYPE_OTHER:
      return "OTHER";
    case DEVICE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DeviceType ParseDeviceType(const std::string& enum_string) {
  if (enum_string == "HEADPHONE")
    return DEVICE_TYPE_HEADPHONE;
  if (enum_string == "MIC")
    return DEVICE_TYPE_MIC;
  if (enum_string == "USB")
    return DEVICE_TYPE_USB;
  if (enum_string == "BLUETOOTH")
    return DEVICE_TYPE_BLUETOOTH;
  if (enum_string == "HDMI")
    return DEVICE_TYPE_HDMI;
  if (enum_string == "INTERNAL_SPEAKER")
    return DEVICE_TYPE_INTERNAL_SPEAKER;
  if (enum_string == "INTERNAL_MIC")
    return DEVICE_TYPE_INTERNAL_MIC;
  if (enum_string == "FRONT_MIC")
    return DEVICE_TYPE_FRONT_MIC;
  if (enum_string == "REAR_MIC")
    return DEVICE_TYPE_REAR_MIC;
  if (enum_string == "KEYBOARD_MIC")
    return DEVICE_TYPE_KEYBOARD_MIC;
  if (enum_string == "HOTWORD")
    return DEVICE_TYPE_HOTWORD;
  if (enum_string == "LINEOUT")
    return DEVICE_TYPE_LINEOUT;
  if (enum_string == "POST_MIX_LOOPBACK")
    return DEVICE_TYPE_POST_MIX_LOOPBACK;
  if (enum_string == "POST_DSP_LOOPBACK")
    return DEVICE_TYPE_POST_DSP_LOOPBACK;
  if (enum_string == "OTHER")
    return DEVICE_TYPE_OTHER;
  return DEVICE_TYPE_NONE;
}


OutputDeviceInfo::OutputDeviceInfo()
: is_active(false),
is_muted(false),
volume(0.0) {}

OutputDeviceInfo::~OutputDeviceInfo() {}
OutputDeviceInfo::OutputDeviceInfo(OutputDeviceInfo&& rhs)
: id(std::move(rhs.id)),
name(std::move(rhs.name)),
is_active(rhs.is_active),
is_muted(rhs.is_muted),
volume(rhs.volume){
}

OutputDeviceInfo& OutputDeviceInfo::operator=(OutputDeviceInfo&& rhs)
{
id = std::move(rhs.id);
name = std::move(rhs.name);
is_active = rhs.is_active;
is_muted = rhs.is_muted;
volume = rhs.volume;
return *this;
}

// static
bool OutputDeviceInfo::Populate(
    const base::Value& value, OutputDeviceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
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

  const base::Value* is_active_value = NULL;
  if (!dict->GetWithoutPathExpansion("isActive", &is_active_value)) {
    return false;
  }
  {
    if (!is_active_value->GetAsBoolean(&out->is_active)) {
      return false;
    }
  }

  const base::Value* is_muted_value = NULL;
  if (!dict->GetWithoutPathExpansion("isMuted", &is_muted_value)) {
    return false;
  }
  {
    if (!is_muted_value->GetAsBoolean(&out->is_muted)) {
      return false;
    }
  }

  const base::Value* volume_value = NULL;
  if (!dict->GetWithoutPathExpansion("volume", &volume_value)) {
    return false;
  }
  {
    if (!volume_value->GetAsDouble(&out->volume)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<OutputDeviceInfo> OutputDeviceInfo::FromValue(const base::Value& value) {
  std::unique_ptr<OutputDeviceInfo> out(new OutputDeviceInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OutputDeviceInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("isActive", std::make_unique<base::Value>(this->is_active));

  to_value_result->SetWithoutPathExpansion("isMuted", std::make_unique<base::Value>(this->is_muted));

  to_value_result->SetWithoutPathExpansion("volume", std::make_unique<base::Value>(this->volume));


  return to_value_result;
}


InputDeviceInfo::InputDeviceInfo()
: is_active(false),
is_muted(false),
gain(0.0) {}

InputDeviceInfo::~InputDeviceInfo() {}
InputDeviceInfo::InputDeviceInfo(InputDeviceInfo&& rhs)
: id(std::move(rhs.id)),
name(std::move(rhs.name)),
is_active(rhs.is_active),
is_muted(rhs.is_muted),
gain(rhs.gain){
}

InputDeviceInfo& InputDeviceInfo::operator=(InputDeviceInfo&& rhs)
{
id = std::move(rhs.id);
name = std::move(rhs.name);
is_active = rhs.is_active;
is_muted = rhs.is_muted;
gain = rhs.gain;
return *this;
}

// static
bool InputDeviceInfo::Populate(
    const base::Value& value, InputDeviceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
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

  const base::Value* is_active_value = NULL;
  if (!dict->GetWithoutPathExpansion("isActive", &is_active_value)) {
    return false;
  }
  {
    if (!is_active_value->GetAsBoolean(&out->is_active)) {
      return false;
    }
  }

  const base::Value* is_muted_value = NULL;
  if (!dict->GetWithoutPathExpansion("isMuted", &is_muted_value)) {
    return false;
  }
  {
    if (!is_muted_value->GetAsBoolean(&out->is_muted)) {
      return false;
    }
  }

  const base::Value* gain_value = NULL;
  if (!dict->GetWithoutPathExpansion("gain", &gain_value)) {
    return false;
  }
  {
    if (!gain_value->GetAsDouble(&out->gain)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<InputDeviceInfo> InputDeviceInfo::FromValue(const base::Value& value) {
  std::unique_ptr<InputDeviceInfo> out(new InputDeviceInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InputDeviceInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("isActive", std::make_unique<base::Value>(this->is_active));

  to_value_result->SetWithoutPathExpansion("isMuted", std::make_unique<base::Value>(this->is_muted));

  to_value_result->SetWithoutPathExpansion("gain", std::make_unique<base::Value>(this->gain));


  return to_value_result;
}


AudioDeviceInfo::AudioDeviceInfo()
: stream_type(STREAM_TYPE_NONE),
device_type(DEVICE_TYPE_NONE),
is_active(false),
level(0) {}

AudioDeviceInfo::~AudioDeviceInfo() {}
AudioDeviceInfo::AudioDeviceInfo(AudioDeviceInfo&& rhs)
: id(std::move(rhs.id)),
stream_type(rhs.stream_type),
device_type(rhs.device_type),
display_name(std::move(rhs.display_name)),
device_name(std::move(rhs.device_name)),
is_active(rhs.is_active),
level(rhs.level),
stable_device_id(std::move(rhs.stable_device_id)){
}

AudioDeviceInfo& AudioDeviceInfo::operator=(AudioDeviceInfo&& rhs)
{
id = std::move(rhs.id);
stream_type = rhs.stream_type;
device_type = rhs.device_type;
display_name = std::move(rhs.display_name);
device_name = std::move(rhs.device_name);
is_active = rhs.is_active;
level = rhs.level;
stable_device_id = std::move(rhs.stable_device_id);
return *this;
}

// static
bool AudioDeviceInfo::Populate(
    const base::Value& value, AudioDeviceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* stream_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("streamType", &stream_type_value)) {
    return false;
  }
  {
    std::string stream_type_as_string;
    if (!stream_type_value->GetAsString(&stream_type_as_string)) {
      return false;
    }
    out->stream_type = ParseStreamType(stream_type_as_string);
    if (out->stream_type == STREAM_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* device_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceType", &device_type_value)) {
    return false;
  }
  {
    std::string device_type_as_string;
    if (!device_type_value->GetAsString(&device_type_as_string)) {
      return false;
    }
    out->device_type = ParseDeviceType(device_type_as_string);
    if (out->device_type == DEVICE_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* display_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayName", &display_name_value)) {
    return false;
  }
  {
    if (!display_name_value->GetAsString(&out->display_name)) {
      return false;
    }
  }

  const base::Value* device_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceName", &device_name_value)) {
    return false;
  }
  {
    if (!device_name_value->GetAsString(&out->device_name)) {
      return false;
    }
  }

  const base::Value* is_active_value = NULL;
  if (!dict->GetWithoutPathExpansion("isActive", &is_active_value)) {
    return false;
  }
  {
    if (!is_active_value->GetAsBoolean(&out->is_active)) {
      return false;
    }
  }

  const base::Value* level_value = NULL;
  if (!dict->GetWithoutPathExpansion("level", &level_value)) {
    return false;
  }
  {
    if (!level_value->GetAsInteger(&out->level)) {
      return false;
    }
  }

  const base::Value* stable_device_id_value = NULL;
  if (dict->GetWithoutPathExpansion("stableDeviceId", &stable_device_id_value)) {
    {
      std::string temp;
      if (!stable_device_id_value->GetAsString(&temp)) {
        out->stable_device_id.reset();
        return false;
      }
      else
        out->stable_device_id.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<AudioDeviceInfo> AudioDeviceInfo::FromValue(const base::Value& value) {
  std::unique_ptr<AudioDeviceInfo> out(new AudioDeviceInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AudioDeviceInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("streamType", std::make_unique<base::Value>(audio::ToString(this->stream_type)));

  to_value_result->SetWithoutPathExpansion("deviceType", std::make_unique<base::Value>(audio::ToString(this->device_type)));

  to_value_result->SetWithoutPathExpansion("displayName", std::make_unique<base::Value>(this->display_name));

  to_value_result->SetWithoutPathExpansion("deviceName", std::make_unique<base::Value>(this->device_name));

  to_value_result->SetWithoutPathExpansion("isActive", std::make_unique<base::Value>(this->is_active));

  to_value_result->SetWithoutPathExpansion("level", std::make_unique<base::Value>(this->level));

  if (this->stable_device_id.get()) {
    to_value_result->SetWithoutPathExpansion("stableDeviceId", std::make_unique<base::Value>(*this->stable_device_id));

  }

  return to_value_result;
}


DeviceFilter::DeviceFilter()
 {}

DeviceFilter::~DeviceFilter() {}
DeviceFilter::DeviceFilter(DeviceFilter&& rhs)
: stream_types(std::move(rhs.stream_types)),
is_active(std::move(rhs.is_active)){
}

DeviceFilter& DeviceFilter::operator=(DeviceFilter&& rhs)
{
stream_types = std::move(rhs.stream_types);
is_active = std::move(rhs.is_active);
return *this;
}

// static
bool DeviceFilter::Populate(
    const base::Value& value, DeviceFilter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* stream_types_value = NULL;
  if (dict->GetWithoutPathExpansion("streamTypes", &stream_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!stream_types_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->stream_types.reset(new std::vector<StreamType>);
        for (const auto& it : *(list)) {
          StreamType tmp;
          std::string stream_type_as_string;
          if (!(it).GetAsString(&stream_type_as_string)) {
            return false;
          }
          tmp = ParseStreamType(stream_type_as_string);
          if (tmp == STREAM_TYPE_NONE) {
            return false;
          }
          out->stream_types->push_back(tmp);
        }
      }
    }
  }

  const base::Value* is_active_value = NULL;
  if (dict->GetWithoutPathExpansion("isActive", &is_active_value)) {
    {
      bool temp;
      if (!is_active_value->GetAsBoolean(&temp)) {
        out->is_active.reset();
        return false;
      }
      else
        out->is_active.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceFilter> DeviceFilter::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceFilter> out(new DeviceFilter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->stream_types.get()) {
    {
      std::vector<std::string> streamTypes_list;
      for (const auto& it : *(this->stream_types)) {
      streamTypes_list.push_back(audio::ToString(it));
    }
    to_value_result->SetWithoutPathExpansion("streamTypes", json_schema_compiler::util::CreateValueFromArray(streamTypes_list));
    }

  }
  if (this->is_active.get()) {
    to_value_result->SetWithoutPathExpansion("isActive", std::make_unique<base::Value>(*this->is_active));

  }

  return to_value_result;
}


DeviceProperties::DeviceProperties()
 {}

DeviceProperties::~DeviceProperties() {}
DeviceProperties::DeviceProperties(DeviceProperties&& rhs)
: is_muted(std::move(rhs.is_muted)),
volume(std::move(rhs.volume)),
gain(std::move(rhs.gain)),
level(std::move(rhs.level)){
}

DeviceProperties& DeviceProperties::operator=(DeviceProperties&& rhs)
{
is_muted = std::move(rhs.is_muted);
volume = std::move(rhs.volume);
gain = std::move(rhs.gain);
level = std::move(rhs.level);
return *this;
}

// static
bool DeviceProperties::Populate(
    const base::Value& value, DeviceProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* is_muted_value = NULL;
  if (dict->GetWithoutPathExpansion("isMuted", &is_muted_value)) {
    {
      bool temp;
      if (!is_muted_value->GetAsBoolean(&temp)) {
        out->is_muted.reset();
        return false;
      }
      else
        out->is_muted.reset(new bool(temp));
    }
  }

  const base::Value* volume_value = NULL;
  if (dict->GetWithoutPathExpansion("volume", &volume_value)) {
    {
      double temp;
      if (!volume_value->GetAsDouble(&temp)) {
        out->volume.reset();
        return false;
      }
      else
        out->volume.reset(new double(temp));
    }
  }

  const base::Value* gain_value = NULL;
  if (dict->GetWithoutPathExpansion("gain", &gain_value)) {
    {
      double temp;
      if (!gain_value->GetAsDouble(&temp)) {
        out->gain.reset();
        return false;
      }
      else
        out->gain.reset(new double(temp));
    }
  }

  const base::Value* level_value = NULL;
  if (dict->GetWithoutPathExpansion("level", &level_value)) {
    {
      int temp;
      if (!level_value->GetAsInteger(&temp)) {
        out->level.reset();
        return false;
      }
      else
        out->level.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceProperties> DeviceProperties::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceProperties> out(new DeviceProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->is_muted.get()) {
    to_value_result->SetWithoutPathExpansion("isMuted", std::make_unique<base::Value>(*this->is_muted));

  }
  if (this->volume.get()) {
    to_value_result->SetWithoutPathExpansion("volume", std::make_unique<base::Value>(*this->volume));

  }
  if (this->gain.get()) {
    to_value_result->SetWithoutPathExpansion("gain", std::make_unique<base::Value>(*this->gain));

  }
  if (this->level.get()) {
    to_value_result->SetWithoutPathExpansion("level", std::make_unique<base::Value>(*this->level));

  }

  return to_value_result;
}


DeviceIdLists::DeviceIdLists()
 {}

DeviceIdLists::~DeviceIdLists() {}
DeviceIdLists::DeviceIdLists(DeviceIdLists&& rhs)
: input(std::move(rhs.input)),
output(std::move(rhs.output)){
}

DeviceIdLists& DeviceIdLists::operator=(DeviceIdLists&& rhs)
{
input = std::move(rhs.input);
output = std::move(rhs.output);
return *this;
}

// static
bool DeviceIdLists::Populate(
    const base::Value& value, DeviceIdLists* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* input_value = NULL;
  if (dict->GetWithoutPathExpansion("input", &input_value)) {
    {
      const base::ListValue* list = NULL;
      if (!input_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->input)) {
          return false;
        }
      }
    }
  }

  const base::Value* output_value = NULL;
  if (dict->GetWithoutPathExpansion("output", &output_value)) {
    {
      const base::ListValue* list = NULL;
      if (!output_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->output)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceIdLists> DeviceIdLists::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceIdLists> out(new DeviceIdLists());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceIdLists::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->input.get()) {
    to_value_result->SetWithoutPathExpansion("input", json_schema_compiler::util::CreateValueFromOptionalArray(this->input));

  }
  if (this->output.get()) {
    to_value_result->SetWithoutPathExpansion("output", json_schema_compiler::util::CreateValueFromOptionalArray(this->output));

  }

  return to_value_result;
}


MuteChangedEvent::MuteChangedEvent()
: stream_type(STREAM_TYPE_NONE),
is_muted(false) {}

MuteChangedEvent::~MuteChangedEvent() {}
MuteChangedEvent::MuteChangedEvent(MuteChangedEvent&& rhs)
: stream_type(rhs.stream_type),
is_muted(rhs.is_muted){
}

MuteChangedEvent& MuteChangedEvent::operator=(MuteChangedEvent&& rhs)
{
stream_type = rhs.stream_type;
is_muted = rhs.is_muted;
return *this;
}

// static
bool MuteChangedEvent::Populate(
    const base::Value& value, MuteChangedEvent* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* stream_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("streamType", &stream_type_value)) {
    return false;
  }
  {
    std::string stream_type_as_string;
    if (!stream_type_value->GetAsString(&stream_type_as_string)) {
      return false;
    }
    out->stream_type = ParseStreamType(stream_type_as_string);
    if (out->stream_type == STREAM_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* is_muted_value = NULL;
  if (!dict->GetWithoutPathExpansion("isMuted", &is_muted_value)) {
    return false;
  }
  {
    if (!is_muted_value->GetAsBoolean(&out->is_muted)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<MuteChangedEvent> MuteChangedEvent::FromValue(const base::Value& value) {
  std::unique_ptr<MuteChangedEvent> out(new MuteChangedEvent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MuteChangedEvent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("streamType", std::make_unique<base::Value>(audio::ToString(this->stream_type)));

  to_value_result->SetWithoutPathExpansion("isMuted", std::make_unique<base::Value>(this->is_muted));


  return to_value_result;
}


LevelChangedEvent::LevelChangedEvent()
: level(0) {}

LevelChangedEvent::~LevelChangedEvent() {}
LevelChangedEvent::LevelChangedEvent(LevelChangedEvent&& rhs)
: device_id(std::move(rhs.device_id)),
level(rhs.level){
}

LevelChangedEvent& LevelChangedEvent::operator=(LevelChangedEvent&& rhs)
{
device_id = std::move(rhs.device_id);
level = rhs.level;
return *this;
}

// static
bool LevelChangedEvent::Populate(
    const base::Value& value, LevelChangedEvent* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* device_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceId", &device_id_value)) {
    return false;
  }
  {
    if (!device_id_value->GetAsString(&out->device_id)) {
      return false;
    }
  }

  const base::Value* level_value = NULL;
  if (!dict->GetWithoutPathExpansion("level", &level_value)) {
    return false;
  }
  {
    if (!level_value->GetAsInteger(&out->level)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<LevelChangedEvent> LevelChangedEvent::FromValue(const base::Value& value) {
  std::unique_ptr<LevelChangedEvent> out(new LevelChangedEvent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> LevelChangedEvent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("deviceId", std::make_unique<base::Value>(this->device_id));

  to_value_result->SetWithoutPathExpansion("level", std::make_unique<base::Value>(this->level));


  return to_value_result;
}



//
// Functions
//

namespace GetDevices {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* filter_value = NULL;
  if (args.Get(0, &filter_value) &&
      !filter_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!filter_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<DeviceFilter> temp(new DeviceFilter());
        if (!DeviceFilter::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->filter = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<AudioDeviceInfo>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace GetDevices

namespace SetActiveDevices {

Params::Ids::Ids()
 {}

Params::Ids::~Ids() {}
Params::Ids::Ids(Ids&& rhs)
: as_device_id_lists(std::move(rhs.as_device_id_lists)),
as_strings(std::move(rhs.as_strings)){
}

Params::Ids& Params::Ids::operator=(Ids&& rhs)
{
as_device_id_lists = std::move(rhs.as_device_id_lists);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool Params::Ids::Populate(
    const base::Value& value, Ids* out) {
  if (value.type() == base::Value::Type::DICTIONARY) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!(&value)->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<DeviceIdLists> temp(new DeviceIdLists());
        if (!DeviceIdLists::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->as_device_id_lists = std::move(temp);
      }
    }
    return true;
  }
  if (value.type() == base::Value::Type::LIST) {
    {
      const base::ListValue* list = NULL;
      if (!(&value)->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_strings)) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* ids_value = NULL;
  if (args.Get(0, &ids_value) &&
      !ids_value->is_none()) {
    {
      if (!Ids::Populate(*ids_value, &params->ids))
        return std::unique_ptr<Params>();
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetActiveDevices

namespace SetProperties {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* properties_value = NULL;
  if (args.Get(1, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DeviceProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetProperties

namespace GetMute {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* stream_type_value = NULL;
  if (args.Get(0, &stream_type_value) &&
      !stream_type_value->is_none()) {
    {
      std::string stream_type_as_string;
      if (!stream_type_value->GetAsString(&stream_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->stream_type = ParseStreamType(stream_type_as_string);
      if (params->stream_type == STREAM_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool value) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(value));

  return create_results;
}
}  // namespace GetMute

namespace SetMute {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* stream_type_value = NULL;
  if (args.Get(0, &stream_type_value) &&
      !stream_type_value->is_none()) {
    {
      std::string stream_type_as_string;
      if (!stream_type_value->GetAsString(&stream_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->stream_type = ParseStreamType(stream_type_as_string);
      if (params->stream_type == STREAM_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* is_muted_value = NULL;
  if (args.Get(1, &is_muted_value) &&
      !is_muted_value->is_none()) {
    {
      if (!is_muted_value->GetAsBoolean(&params->is_muted)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetMute

namespace GetInfo {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<OutputDeviceInfo>& output_info, const std::vector<InputDeviceInfo>& input_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(output_info));

  create_results->Append(json_schema_compiler::util::CreateValueFromArray(input_info));

  return create_results;
}
}  // namespace GetInfo

//
// Events
//

namespace OnLevelChanged {

const char kEventName[] = "audio.onLevelChanged";

std::unique_ptr<base::ListValue> Create(const LevelChangedEvent& event) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((event).ToValue());

  return create_results;
}

}  // namespace OnLevelChanged

namespace OnMuteChanged {

const char kEventName[] = "audio.onMuteChanged";

std::unique_ptr<base::ListValue> Create(const MuteChangedEvent& event) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((event).ToValue());

  return create_results;
}

}  // namespace OnMuteChanged

namespace OnDeviceListChanged {

const char kEventName[] = "audio.onDeviceListChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<AudioDeviceInfo>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}

}  // namespace OnDeviceListChanged

namespace OnDeviceChanged {

const char kEventName[] = "audio.onDeviceChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnDeviceChanged

}  // namespace audio
}  // namespace api
}  // namespace extensions

