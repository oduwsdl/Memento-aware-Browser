// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/debugger.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/debugger.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace debugger {
//
// Types
//

Debuggee::Debuggee()
 {}

Debuggee::~Debuggee() {}
Debuggee::Debuggee(Debuggee&& rhs)
: tab_id(std::move(rhs.tab_id)),
extension_id(std::move(rhs.extension_id)),
target_id(std::move(rhs.target_id)){
}

Debuggee& Debuggee::operator=(Debuggee&& rhs)
{
tab_id = std::move(rhs.tab_id);
extension_id = std::move(rhs.extension_id);
target_id = std::move(rhs.target_id);
return *this;
}

// static
bool Debuggee::Populate(
    const base::Value& value, Debuggee* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        out->tab_id.reset();
        return false;
      }
      else
        out->tab_id.reset(new int(temp));
    }
  }

  const base::Value* extension_id_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    {
      std::string temp;
      if (!extension_id_value->GetAsString(&temp)) {
        out->extension_id.reset();
        return false;
      }
      else
        out->extension_id.reset(new std::string(temp));
    }
  }

  const base::Value* target_id_value = NULL;
  if (dict->GetWithoutPathExpansion("targetId", &target_id_value)) {
    {
      std::string temp;
      if (!target_id_value->GetAsString(&temp)) {
        out->target_id.reset();
        return false;
      }
      else
        out->target_id.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Debuggee> Debuggee::FromValue(const base::Value& value) {
  std::unique_ptr<Debuggee> out(new Debuggee());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Debuggee::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(*this->tab_id));

  }
  if (this->extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(*this->extension_id));

  }
  if (this->target_id.get()) {
    to_value_result->SetWithoutPathExpansion("targetId", std::make_unique<base::Value>(*this->target_id));

  }

  return to_value_result;
}


const char* ToString(TargetInfoType enum_param) {
  switch (enum_param) {
    case TARGET_INFO_TYPE_PAGE:
      return "page";
    case TARGET_INFO_TYPE_BACKGROUND_PAGE:
      return "background_page";
    case TARGET_INFO_TYPE_WORKER:
      return "worker";
    case TARGET_INFO_TYPE_OTHER:
      return "other";
    case TARGET_INFO_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TargetInfoType ParseTargetInfoType(const std::string& enum_string) {
  if (enum_string == "page")
    return TARGET_INFO_TYPE_PAGE;
  if (enum_string == "background_page")
    return TARGET_INFO_TYPE_BACKGROUND_PAGE;
  if (enum_string == "worker")
    return TARGET_INFO_TYPE_WORKER;
  if (enum_string == "other")
    return TARGET_INFO_TYPE_OTHER;
  return TARGET_INFO_TYPE_NONE;
}


const char* ToString(DetachReason enum_param) {
  switch (enum_param) {
    case DETACH_REASON_TARGET_CLOSED:
      return "target_closed";
    case DETACH_REASON_CANCELED_BY_USER:
      return "canceled_by_user";
    case DETACH_REASON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DetachReason ParseDetachReason(const std::string& enum_string) {
  if (enum_string == "target_closed")
    return DETACH_REASON_TARGET_CLOSED;
  if (enum_string == "canceled_by_user")
    return DETACH_REASON_CANCELED_BY_USER;
  return DETACH_REASON_NONE;
}


TargetInfo::TargetInfo()
: type(TARGET_INFO_TYPE_NONE),
attached(false) {}

TargetInfo::~TargetInfo() {}
TargetInfo::TargetInfo(TargetInfo&& rhs)
: type(rhs.type),
id(std::move(rhs.id)),
tab_id(std::move(rhs.tab_id)),
extension_id(std::move(rhs.extension_id)),
attached(rhs.attached),
title(std::move(rhs.title)),
url(std::move(rhs.url)),
favicon_url(std::move(rhs.favicon_url)){
}

TargetInfo& TargetInfo::operator=(TargetInfo&& rhs)
{
type = rhs.type;
id = std::move(rhs.id);
tab_id = std::move(rhs.tab_id);
extension_id = std::move(rhs.extension_id);
attached = rhs.attached;
title = std::move(rhs.title);
url = std::move(rhs.url);
favicon_url = std::move(rhs.favicon_url);
return *this;
}

// static
bool TargetInfo::Populate(
    const base::Value& value, TargetInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string target_info_type_as_string;
    if (!type_value->GetAsString(&target_info_type_as_string)) {
      return false;
    }
    out->type = ParseTargetInfoType(target_info_type_as_string);
    if (out->type == TARGET_INFO_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        out->tab_id.reset();
        return false;
      }
      else
        out->tab_id.reset(new int(temp));
    }
  }

  const base::Value* extension_id_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    {
      std::string temp;
      if (!extension_id_value->GetAsString(&temp)) {
        out->extension_id.reset();
        return false;
      }
      else
        out->extension_id.reset(new std::string(temp));
    }
  }

  const base::Value* attached_value = NULL;
  if (!dict->GetWithoutPathExpansion("attached", &attached_value)) {
    return false;
  }
  {
    if (!attached_value->GetAsBoolean(&out->attached)) {
      return false;
    }
  }

  const base::Value* title_value = NULL;
  if (!dict->GetWithoutPathExpansion("title", &title_value)) {
    return false;
  }
  {
    if (!title_value->GetAsString(&out->title)) {
      return false;
    }
  }

  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* favicon_url_value = NULL;
  if (dict->GetWithoutPathExpansion("faviconUrl", &favicon_url_value)) {
    {
      std::string temp;
      if (!favicon_url_value->GetAsString(&temp)) {
        out->favicon_url.reset();
        return false;
      }
      else
        out->favicon_url.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<TargetInfo> TargetInfo::FromValue(const base::Value& value) {
  std::unique_ptr<TargetInfo> out(new TargetInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TargetInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(debugger::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  if (this->tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(*this->tab_id));

  }
  if (this->extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(*this->extension_id));

  }
  to_value_result->SetWithoutPathExpansion("attached", std::make_unique<base::Value>(this->attached));

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  if (this->favicon_url.get()) {
    to_value_result->SetWithoutPathExpansion("faviconUrl", std::make_unique<base::Value>(*this->favicon_url));

  }

  return to_value_result;
}



//
// Functions
//

namespace Attach {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* target_value = NULL;
  if (args.Get(0, &target_value) &&
      !target_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!target_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Debuggee::Populate(*dictionary, &params->target)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* required_version_value = NULL;
  if (args.Get(1, &required_version_value) &&
      !required_version_value->is_none()) {
    {
      if (!required_version_value->GetAsString(&params->required_version)) {
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
}  // namespace Attach

namespace Detach {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* target_value = NULL;
  if (args.Get(0, &target_value) &&
      !target_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!target_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Debuggee::Populate(*dictionary, &params->target)) {
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
}  // namespace Detach

namespace SendCommand {

Params::CommandParams::CommandParams()
 {}

Params::CommandParams::~CommandParams() {}
Params::CommandParams::CommandParams(CommandParams&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::CommandParams& Params::CommandParams::operator=(CommandParams&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::CommandParams::Populate(
    const base::Value& value, CommandParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* target_value = NULL;
  if (args.Get(0, &target_value) &&
      !target_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!target_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Debuggee::Populate(*dictionary, &params->target)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* method_value = NULL;
  if (args.Get(1, &method_value) &&
      !method_value->is_none()) {
    {
      if (!method_value->GetAsString(&params->method)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* command_params_value = NULL;
  if (args.Get(2, &command_params_value) &&
      !command_params_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!command_params_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<CommandParams> temp(new CommandParams());
        if (!CommandParams::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->command_params = std::move(temp);
      }
    }
  }

  return params;
}


Results::Result::Result()
 {}

Results::Result::~Result() {}
Results::Result::Result(Result&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Result& Results::Result::operator=(Result&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Result::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Result& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace SendCommand

namespace GetTargets {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<TargetInfo>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetTargets

//
// Events
//

namespace OnEvent {

const char kEventName[] = "debugger.onEvent";

Params::Params()
 {}

Params::~Params() {}
Params::Params(Params&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params& Params::operator=(Params&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Params::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Debuggee& source, const std::string& method, const Params& params) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((source).ToValue());

  create_results->Append(std::make_unique<base::Value>(method));

  create_results->Append((params).ToValue());

  return create_results;
}

}  // namespace OnEvent

namespace OnDetach {

const char kEventName[] = "debugger.onDetach";

std::unique_ptr<base::ListValue> Create(const Debuggee& source, const DetachReason& reason) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((source).ToValue());

  create_results->Append(std::make_unique<base::Value>(debugger::ToString(reason)));

  return create_results;
}

}  // namespace OnDetach

}  // namespace debugger
}  // namespace api
}  // namespace extensions

