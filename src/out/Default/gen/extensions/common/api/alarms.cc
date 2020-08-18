// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/alarms.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/alarms.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace alarms {
//
// Types
//

Alarm::Alarm()
: scheduled_time(0.0) {}

Alarm::~Alarm() {}
Alarm::Alarm(Alarm&& rhs)
: name(std::move(rhs.name)),
scheduled_time(rhs.scheduled_time),
period_in_minutes(std::move(rhs.period_in_minutes)){
}

Alarm& Alarm::operator=(Alarm&& rhs)
{
name = std::move(rhs.name);
scheduled_time = rhs.scheduled_time;
period_in_minutes = std::move(rhs.period_in_minutes);
return *this;
}

// static
bool Alarm::Populate(
    const base::Value& value, Alarm* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* scheduled_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("scheduledTime", &scheduled_time_value)) {
    return false;
  }
  {
    if (!scheduled_time_value->GetAsDouble(&out->scheduled_time)) {
      return false;
    }
  }

  const base::Value* period_in_minutes_value = NULL;
  if (dict->GetWithoutPathExpansion("periodInMinutes", &period_in_minutes_value)) {
    {
      double temp;
      if (!period_in_minutes_value->GetAsDouble(&temp)) {
        out->period_in_minutes.reset();
        return false;
      }
      else
        out->period_in_minutes.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Alarm> Alarm::FromValue(const base::Value& value) {
  std::unique_ptr<Alarm> out(new Alarm());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Alarm::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("scheduledTime", std::make_unique<base::Value>(this->scheduled_time));

  if (this->period_in_minutes.get()) {
    to_value_result->SetWithoutPathExpansion("periodInMinutes", std::make_unique<base::Value>(*this->period_in_minutes));

  }

  return to_value_result;
}


AlarmCreateInfo::AlarmCreateInfo()
 {}

AlarmCreateInfo::~AlarmCreateInfo() {}
AlarmCreateInfo::AlarmCreateInfo(AlarmCreateInfo&& rhs)
: when(std::move(rhs.when)),
delay_in_minutes(std::move(rhs.delay_in_minutes)),
period_in_minutes(std::move(rhs.period_in_minutes)){
}

AlarmCreateInfo& AlarmCreateInfo::operator=(AlarmCreateInfo&& rhs)
{
when = std::move(rhs.when);
delay_in_minutes = std::move(rhs.delay_in_minutes);
period_in_minutes = std::move(rhs.period_in_minutes);
return *this;
}

// static
bool AlarmCreateInfo::Populate(
    const base::Value& value, AlarmCreateInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* when_value = NULL;
  if (dict->GetWithoutPathExpansion("when", &when_value)) {
    {
      double temp;
      if (!when_value->GetAsDouble(&temp)) {
        out->when.reset();
        return false;
      }
      else
        out->when.reset(new double(temp));
    }
  }

  const base::Value* delay_in_minutes_value = NULL;
  if (dict->GetWithoutPathExpansion("delayInMinutes", &delay_in_minutes_value)) {
    {
      double temp;
      if (!delay_in_minutes_value->GetAsDouble(&temp)) {
        out->delay_in_minutes.reset();
        return false;
      }
      else
        out->delay_in_minutes.reset(new double(temp));
    }
  }

  const base::Value* period_in_minutes_value = NULL;
  if (dict->GetWithoutPathExpansion("periodInMinutes", &period_in_minutes_value)) {
    {
      double temp;
      if (!period_in_minutes_value->GetAsDouble(&temp)) {
        out->period_in_minutes.reset();
        return false;
      }
      else
        out->period_in_minutes.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<AlarmCreateInfo> AlarmCreateInfo::FromValue(const base::Value& value) {
  std::unique_ptr<AlarmCreateInfo> out(new AlarmCreateInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AlarmCreateInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->when.get()) {
    to_value_result->SetWithoutPathExpansion("when", std::make_unique<base::Value>(*this->when));

  }
  if (this->delay_in_minutes.get()) {
    to_value_result->SetWithoutPathExpansion("delayInMinutes", std::make_unique<base::Value>(*this->delay_in_minutes));

  }
  if (this->period_in_minutes.get()) {
    to_value_result->SetWithoutPathExpansion("periodInMinutes", std::make_unique<base::Value>(*this->period_in_minutes));

  }

  return to_value_result;
}



//
// Functions
//

namespace Create {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* name_value = NULL;
  if (args.Get(0, &name_value) &&
      !name_value->is_none()) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        params->name.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->name.reset(new std::string(temp));
    }
  }

  const base::Value* alarm_info_value = NULL;
  if (args.Get(1, &alarm_info_value) &&
      !alarm_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!alarm_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!AlarmCreateInfo::Populate(*dictionary, &params->alarm_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Create

namespace Get {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* name_value = NULL;
  if (args.Get(0, &name_value) &&
      !name_value->is_none()) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        params->name.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->name.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Alarm& alarm) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((alarm).ToValue());

  return create_results;
}
}  // namespace Get

namespace GetAll {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<Alarm>& alarms) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(alarms));

  return create_results;
}
}  // namespace GetAll

namespace Clear {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* name_value = NULL;
  if (args.Get(0, &name_value) &&
      !name_value->is_none()) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        params->name.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->name.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool was_cleared) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(was_cleared));

  return create_results;
}
}  // namespace Clear

namespace ClearAll {

std::unique_ptr<base::ListValue> Results::Create(bool was_cleared) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(was_cleared));

  return create_results;
}
}  // namespace ClearAll

//
// Events
//

namespace OnAlarm {

const char kEventName[] = "alarms.onAlarm";

std::unique_ptr<base::ListValue> Create(const Alarm& alarm) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((alarm).ToValue());

  return create_results;
}

}  // namespace OnAlarm

}  // namespace alarms
}  // namespace api
}  // namespace extensions

