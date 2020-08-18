// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/audio.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_AUDIO_H__
#define EXTENSIONS_COMMON_API_AUDIO_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace audio {

//
// Types
//

// Type of stream an audio device provides.
enum StreamType {
  STREAM_TYPE_NONE,
  STREAM_TYPE_INPUT,
  STREAM_TYPE_OUTPUT,
  STREAM_TYPE_LAST = STREAM_TYPE_OUTPUT,
};


const char* ToString(StreamType as_enum);
StreamType ParseStreamType(const std::string& as_string);

// Available audio device types.
enum DeviceType {
  DEVICE_TYPE_NONE,
  DEVICE_TYPE_HEADPHONE,
  DEVICE_TYPE_MIC,
  DEVICE_TYPE_USB,
  DEVICE_TYPE_BLUETOOTH,
  DEVICE_TYPE_HDMI,
  DEVICE_TYPE_INTERNAL_SPEAKER,
  DEVICE_TYPE_INTERNAL_MIC,
  DEVICE_TYPE_FRONT_MIC,
  DEVICE_TYPE_REAR_MIC,
  DEVICE_TYPE_KEYBOARD_MIC,
  DEVICE_TYPE_HOTWORD,
  DEVICE_TYPE_LINEOUT,
  DEVICE_TYPE_POST_MIX_LOOPBACK,
  DEVICE_TYPE_POST_DSP_LOOPBACK,
  DEVICE_TYPE_OTHER,
  DEVICE_TYPE_LAST = DEVICE_TYPE_OTHER,
};


const char* ToString(DeviceType as_enum);
DeviceType ParseDeviceType(const std::string& as_string);

struct OutputDeviceInfo {
  OutputDeviceInfo();
  ~OutputDeviceInfo();
  OutputDeviceInfo(OutputDeviceInfo&& rhs);
  OutputDeviceInfo& operator=(OutputDeviceInfo&& rhs);

  // Populates a OutputDeviceInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, OutputDeviceInfo* out);

  // Creates a OutputDeviceInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<OutputDeviceInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this OutputDeviceInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier of the audio output device.
  std::string id;

  // The user-friendly name (e.g. "Bose Amplifier").
  std::string name;

  // True if this is the current active device.
  bool is_active;

  // True if this is muted.
  bool is_muted;

  // The output volume ranging from 0.0 to 100.0.
  double volume;


 private:
  DISALLOW_COPY_AND_ASSIGN(OutputDeviceInfo);
};

struct InputDeviceInfo {
  InputDeviceInfo();
  ~InputDeviceInfo();
  InputDeviceInfo(InputDeviceInfo&& rhs);
  InputDeviceInfo& operator=(InputDeviceInfo&& rhs);

  // Populates a InputDeviceInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, InputDeviceInfo* out);

  // Creates a InputDeviceInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<InputDeviceInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InputDeviceInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier of the audio input device.
  std::string id;

  // The user-friendly name (e.g. "USB Microphone").
  std::string name;

  // True if this is the current active device.
  bool is_active;

  // True if this is muted.
  bool is_muted;

  // The input gain ranging from 0.0 to 100.0.
  double gain;


 private:
  DISALLOW_COPY_AND_ASSIGN(InputDeviceInfo);
};

struct AudioDeviceInfo {
  AudioDeviceInfo();
  ~AudioDeviceInfo();
  AudioDeviceInfo(AudioDeviceInfo&& rhs);
  AudioDeviceInfo& operator=(AudioDeviceInfo&& rhs);

  // Populates a AudioDeviceInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AudioDeviceInfo* out);

  // Creates a AudioDeviceInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<AudioDeviceInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AudioDeviceInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The unique identifier of the audio device.
  std::string id;

  // Stream type associated with this device.
  StreamType stream_type;

  // Type of the device.
  DeviceType device_type;

  // The user-friendly name (e.g. "USB Microphone").
  std::string display_name;

  // Device name.
  std::string device_name;

  // True if this is the current active device.
  bool is_active;

  // The sound level of the device, volume for output, gain for input.
  int level;

  // The stable/persisted device id string when available.
  std::unique_ptr<std::string> stable_device_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(AudioDeviceInfo);
};

struct DeviceFilter {
  DeviceFilter();
  ~DeviceFilter();
  DeviceFilter(DeviceFilter&& rhs);
  DeviceFilter& operator=(DeviceFilter&& rhs);

  // Populates a DeviceFilter object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DeviceFilter* out);

  // Creates a DeviceFilter object from a base::Value, or NULL on failure.
  static std::unique_ptr<DeviceFilter> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceFilter object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // If set, only audio devices whose stream type is included in this list will
  // satisfy the filter.
  std::unique_ptr<std::vector<StreamType>> stream_types;

  // If set, only audio devices whose active state matches this value will satisfy
  // the filter.
  std::unique_ptr<bool> is_active;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceFilter);
};

struct DeviceProperties {
  DeviceProperties();
  ~DeviceProperties();
  DeviceProperties(DeviceProperties&& rhs);
  DeviceProperties& operator=(DeviceProperties&& rhs);

  // Populates a DeviceProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DeviceProperties* out);

  // Creates a DeviceProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<DeviceProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // True if this is muted.
  std::unique_ptr<bool> is_muted;

  // If this is an output device then this field indicates the output volume. If
  // this is an input device then this field is ignored.
  std::unique_ptr<double> volume;

  // If this is an input device then this field indicates the input gain. If this
  // is an output device then this field is ignored.
  std::unique_ptr<double> gain;

  // <p>   The audio device's desired sound level. Defaults to the device's
  // current sound level. </p>  <p>If used with audio input device, represents
  // audio device gain.</p> <p>If used with audio output device, represents audio
  // device volume.</p>
  std::unique_ptr<int> level;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceProperties);
};

struct DeviceIdLists {
  DeviceIdLists();
  ~DeviceIdLists();
  DeviceIdLists(DeviceIdLists&& rhs);
  DeviceIdLists& operator=(DeviceIdLists&& rhs);

  // Populates a DeviceIdLists object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DeviceIdLists* out);

  // Creates a DeviceIdLists object from a base::Value, or NULL on failure.
  static std::unique_ptr<DeviceIdLists> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceIdLists object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // <p>List of input devices specified by their ID.</p> <p>To indicate input
  // devices should be unaffected, leave this property   unset.</p>
  std::unique_ptr<std::vector<std::string>> input;

  // <p>List of output devices specified by their ID.</p> <p>To indicate output
  // devices should be unaffected, leave this property   unset.</p>
  std::unique_ptr<std::vector<std::string>> output;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceIdLists);
};

struct MuteChangedEvent {
  MuteChangedEvent();
  ~MuteChangedEvent();
  MuteChangedEvent(MuteChangedEvent&& rhs);
  MuteChangedEvent& operator=(MuteChangedEvent&& rhs);

  // Populates a MuteChangedEvent object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, MuteChangedEvent* out);

  // Creates a MuteChangedEvent object from a base::Value, or NULL on failure.
  static std::unique_ptr<MuteChangedEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MuteChangedEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The type of the stream for which the mute value changed. The updated mute
  // value applies to all devices with this stream type.
  StreamType stream_type;

  // Whether or not the stream is now muted.
  bool is_muted;


 private:
  DISALLOW_COPY_AND_ASSIGN(MuteChangedEvent);
};

struct LevelChangedEvent {
  LevelChangedEvent();
  ~LevelChangedEvent();
  LevelChangedEvent(LevelChangedEvent&& rhs);
  LevelChangedEvent& operator=(LevelChangedEvent&& rhs);

  // Populates a LevelChangedEvent object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, LevelChangedEvent* out);

  // Creates a LevelChangedEvent object from a base::Value, or NULL on failure.
  static std::unique_ptr<LevelChangedEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this LevelChangedEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // ID of device whose sound level has changed.
  std::string device_id;

  // The device's new sound level.
  int level;


 private:
  DISALLOW_COPY_AND_ASSIGN(LevelChangedEvent);
};


//
// Functions
//

namespace GetDevices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Device properties by which to filter the list of returned     audio devices.
  // If the filter is not set or set to <code>{}</code>,     returned device list
  // will contain all available audio devices.
  std::unique_ptr<DeviceFilter> filter;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<AudioDeviceInfo>& devices);
}  // namespace Results

}  // namespace GetDevices

namespace SetActiveDevices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // <p>Specifies IDs of devices that should be active. If either the     input or
  // output list is not set, devices in that category are     unaffected.     </p>
  // <p>It is an error to pass in a non-existent device ID.</p>
  // <p><b>NOTE:</b> While the method signature allows device IDs to be     passed
  // as a list of strings, this method of setting active devices     is deprecated
  // and should not be relied upon to work. Please use     $(ref:DeviceIdLists)
  // instead.     </p>
  struct Ids {
    Ids();
    ~Ids();
    Ids(Ids&& rhs);
    Ids& operator=(Ids&& rhs);

    // Populates a Ids object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Ids* out);
    // Choices:
    std::unique_ptr<DeviceIdLists> as_device_id_lists;
    std::unique_ptr<std::vector<std::string>> as_strings;

   private:
    DISALLOW_COPY_AND_ASSIGN(Ids);
  };


  // <p>Specifies IDs of devices that should be active. If either the     input or
  // output list is not set, devices in that category are     unaffected.     </p>
  // <p>It is an error to pass in a non-existent device ID.</p>
  // <p><b>NOTE:</b> While the method signature allows device IDs to be     passed
  // as a list of strings, this method of setting active devices     is deprecated
  // and should not be relied upon to work. Please use     $(ref:DeviceIdLists)
  // instead.     </p>
  Ids ids;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetActiveDevices

namespace SetProperties {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;

  DeviceProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetProperties

namespace GetMute {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Stream type for which mute state should be fetched.
  StreamType stream_type;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool value);
}  // namespace Results

}  // namespace GetMute

namespace SetMute {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Stream type for which mute state should be set.
  StreamType stream_type;

  // New mute value.
  bool is_muted;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetMute

namespace GetInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<OutputDeviceInfo>& output_info, const std::vector<InputDeviceInfo>& input_info);
}  // namespace Results

}  // namespace GetInfo

//
// Events
//

namespace OnLevelChanged {

extern const char kEventName[];  // "audio.onLevelChanged"

std::unique_ptr<base::ListValue> Create(const LevelChangedEvent& event);
}  // namespace OnLevelChanged

namespace OnMuteChanged {

extern const char kEventName[];  // "audio.onMuteChanged"

std::unique_ptr<base::ListValue> Create(const MuteChangedEvent& event);
}  // namespace OnMuteChanged

namespace OnDeviceListChanged {

extern const char kEventName[];  // "audio.onDeviceListChanged"

// List of all present audio devices after the change.
std::unique_ptr<base::ListValue> Create(const std::vector<AudioDeviceInfo>& devices);
}  // namespace OnDeviceListChanged

namespace OnDeviceChanged {

extern const char kEventName[];  // "audio.onDeviceChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnDeviceChanged

}  // namespace audio
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_AUDIO_H__
