// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/sessions.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/sessions.h"
#include <set>
#include <utility>
#include "chrome/common/extensions/api/tabs.h"
#include "chrome/common/extensions/api/windows.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace sessions {
//
// Properties
//

const int MAX_SESSION_RESULTS = 25;

//
// Types
//

Filter::Filter()
 {}

Filter::~Filter() {}
Filter::Filter(Filter&& rhs)
: max_results(std::move(rhs.max_results)){
}

Filter& Filter::operator=(Filter&& rhs)
{
max_results = std::move(rhs.max_results);
return *this;
}

// static
bool Filter::Populate(
    const base::Value& value, Filter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* max_results_value = NULL;
  if (dict->GetWithoutPathExpansion("maxResults", &max_results_value)) {
    {
      int temp;
      if (!max_results_value->GetAsInteger(&temp)) {
        out->max_results.reset();
        return false;
      }
      else
        out->max_results.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Filter> Filter::FromValue(const base::Value& value) {
  std::unique_ptr<Filter> out(new Filter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Filter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->max_results.get()) {
    to_value_result->SetWithoutPathExpansion("maxResults", std::make_unique<base::Value>(*this->max_results));

  }

  return to_value_result;
}


Session::Session()
: last_modified(0) {}

Session::~Session() {}
Session::Session(Session&& rhs)
: last_modified(rhs.last_modified),
tab(std::move(rhs.tab)),
window(std::move(rhs.window)){
}

Session& Session::operator=(Session&& rhs)
{
last_modified = rhs.last_modified;
tab = std::move(rhs.tab);
window = std::move(rhs.window);
return *this;
}

// static
bool Session::Populate(
    const base::Value& value, Session* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* last_modified_value = NULL;
  if (!dict->GetWithoutPathExpansion("lastModified", &last_modified_value)) {
    return false;
  }
  {
    if (!last_modified_value->GetAsInteger(&out->last_modified)) {
      return false;
    }
  }

  const base::Value* tab_value = NULL;
  if (dict->GetWithoutPathExpansion("tab", &tab_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tab_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<extensions::api::tabs::Tab> temp(new extensions::api::tabs::Tab());
        if (!extensions::api::tabs::Tab::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tab = std::move(temp);
      }
    }
  }

  const base::Value* window_value = NULL;
  if (dict->GetWithoutPathExpansion("window", &window_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!window_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<extensions::api::windows::Window> temp(new extensions::api::windows::Window());
        if (!extensions::api::windows::Window::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->window = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Session> Session::FromValue(const base::Value& value) {
  std::unique_ptr<Session> out(new Session());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Session::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("lastModified", std::make_unique<base::Value>(this->last_modified));

  if (this->tab.get()) {
    to_value_result->SetWithoutPathExpansion("tab", (this->tab)->ToValue());

  }
  if (this->window.get()) {
    to_value_result->SetWithoutPathExpansion("window", (this->window)->ToValue());

  }

  return to_value_result;
}


Device::Device()
 {}

Device::~Device() {}
Device::Device(Device&& rhs)
: info(std::move(rhs.info)),
device_name(std::move(rhs.device_name)),
sessions(std::move(rhs.sessions)){
}

Device& Device::operator=(Device&& rhs)
{
info = std::move(rhs.info);
device_name = std::move(rhs.device_name);
sessions = std::move(rhs.sessions);
return *this;
}

// static
bool Device::Populate(
    const base::Value& value, Device* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* info_value = NULL;
  if (!dict->GetWithoutPathExpansion("info", &info_value)) {
    return false;
  }
  {
    if (!info_value->GetAsString(&out->info)) {
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

  const base::Value* sessions_value = NULL;
  if (!dict->GetWithoutPathExpansion("sessions", &sessions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!sessions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->sessions)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Device> Device::FromValue(const base::Value& value) {
  std::unique_ptr<Device> out(new Device());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Device::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("info", std::make_unique<base::Value>(this->info));

  to_value_result->SetWithoutPathExpansion("deviceName", std::make_unique<base::Value>(this->device_name));

  to_value_result->SetWithoutPathExpansion("sessions", json_schema_compiler::util::CreateValueFromArray(this->sessions));


  return to_value_result;
}



//
// Functions
//

namespace GetRecentlyClosed {

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
        std::unique_ptr<Filter> temp(new Filter());
        if (!Filter::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->filter = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Session>& sessions) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(sessions));

  return create_results;
}
}  // namespace GetRecentlyClosed

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
        std::unique_ptr<Filter> temp(new Filter());
        if (!Filter::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->filter = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Device>& devices) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(devices));

  return create_results;
}
}  // namespace GetDevices

namespace Restore {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* session_id_value = NULL;
  if (args.Get(0, &session_id_value) &&
      !session_id_value->is_none()) {
    {
      std::string temp;
      if (!session_id_value->GetAsString(&temp)) {
        params->session_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->session_id.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Session& restored_session) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((restored_session).ToValue());

  return create_results;
}
}  // namespace Restore

//
// Events
//

namespace OnChanged {

const char kEventName[] = "sessions.onChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnChanged

}  // namespace sessions
}  // namespace api
}  // namespace extensions

