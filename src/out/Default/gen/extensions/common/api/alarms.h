// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/alarms.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_ALARMS_H__
#define EXTENSIONS_COMMON_API_ALARMS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace alarms {

//
// Types
//

struct Alarm {
  Alarm();
  ~Alarm();
  Alarm(Alarm&& rhs);
  Alarm& operator=(Alarm&& rhs);

  // Populates a Alarm object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Alarm* out);

  // Creates a Alarm object from a base::Value, or NULL on failure.
  static std::unique_ptr<Alarm> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Alarm object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Name of this alarm.
  std::string name;

  // Time at which this alarm was scheduled to fire, in milliseconds past the
  // epoch (e.g. <code>Date.now() + n</code>).  For performance reasons, the alarm
  // may have been delayed an arbitrary amount beyond this.
  double scheduled_time;

  // If not null, the alarm is a repeating alarm and will fire again in
  // <var>periodInMinutes</var> minutes.
  std::unique_ptr<double> period_in_minutes;


 private:
  DISALLOW_COPY_AND_ASSIGN(Alarm);
};

struct AlarmCreateInfo {
  AlarmCreateInfo();
  ~AlarmCreateInfo();
  AlarmCreateInfo(AlarmCreateInfo&& rhs);
  AlarmCreateInfo& operator=(AlarmCreateInfo&& rhs);

  // Populates a AlarmCreateInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AlarmCreateInfo* out);

  // Creates a AlarmCreateInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<AlarmCreateInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AlarmCreateInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Time at which the alarm should fire, in milliseconds past the epoch (e.g.
  // <code>Date.now() + n</code>).
  std::unique_ptr<double> when;

  // <p>Length of time in minutes after which the <code>onAlarm</code> event
  // should fire.</p><p><!-- TODO: need minimum=0 --></p>
  std::unique_ptr<double> delay_in_minutes;

  // <p>If set, the onAlarm event should fire every <var>periodInMinutes</var>
  // minutes after the initial event specified by <var>when</var> or
  // <var>delayInMinutes</var>.  If not set, the alarm will only fire
  // once.</p><p><!-- TODO: need minimum=0 --></p>
  std::unique_ptr<double> period_in_minutes;


 private:
  DISALLOW_COPY_AND_ASSIGN(AlarmCreateInfo);
};


//
// Functions
//

namespace Create {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Optional name to identify this alarm. Defaults to the empty string.
  std::unique_ptr<std::string> name;

  // Describes when the alarm should fire.  The initial time must be specified by
  // either <var>when</var> or <var>delayInMinutes</var> (but not both).  If
  // <var>periodInMinutes</var> is set, the alarm will repeat every
  // <var>periodInMinutes</var> minutes after the initial event.  If neither
  // <var>when</var> or <var>delayInMinutes</var> is set for a repeating alarm,
  // <var>periodInMinutes</var> is used as the default for
  // <var>delayInMinutes</var>.
  AlarmCreateInfo alarm_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Create

namespace Get {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The name of the alarm to get. Defaults to the empty string.
  std::unique_ptr<std::string> name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Alarm& alarm);
}  // namespace Results

}  // namespace Get

namespace GetAll {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Alarm>& alarms);
}  // namespace Results

}  // namespace GetAll

namespace Clear {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The name of the alarm to clear. Defaults to the empty string.
  std::unique_ptr<std::string> name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool was_cleared);
}  // namespace Results

}  // namespace Clear

namespace ClearAll {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool was_cleared);
}  // namespace Results

}  // namespace ClearAll

//
// Events
//

namespace OnAlarm {

extern const char kEventName[];  // "alarms.onAlarm"

// The alarm that has elapsed.
std::unique_ptr<base::ListValue> Create(const Alarm& alarm);
}  // namespace OnAlarm

}  // namespace alarms
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_ALARMS_H__
