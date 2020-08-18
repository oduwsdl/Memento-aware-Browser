// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/app_runtime.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/app_runtime.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace app_runtime {
//
// Types
//

LaunchItem::Entry::Entry()
 {}

LaunchItem::Entry::~Entry() {}
LaunchItem::Entry::Entry(Entry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

LaunchItem::Entry& LaunchItem::Entry::operator=(Entry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool LaunchItem::Entry::Populate(
    const base::Value& value, Entry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> LaunchItem::Entry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



LaunchItem::LaunchItem()
 {}

LaunchItem::~LaunchItem() {}
LaunchItem::LaunchItem(LaunchItem&& rhs)
: entry(std::move(rhs.entry)),
type(std::move(rhs.type)){
}

LaunchItem& LaunchItem::operator=(LaunchItem&& rhs)
{
entry = std::move(rhs.entry);
type = std::move(rhs.type);
return *this;
}

// static
bool LaunchItem::Populate(
    const base::Value& value, LaunchItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* entry_value = NULL;
  if (!dict->GetWithoutPathExpansion("entry", &entry_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!entry_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Entry::Populate(*dictionary, &out->entry)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string temp;
      if (!type_value->GetAsString(&temp)) {
        out->type.reset();
        return false;
      }
      else
        out->type.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<LaunchItem> LaunchItem::FromValue(const base::Value& value) {
  std::unique_ptr<LaunchItem> out(new LaunchItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> LaunchItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("entry", (this->entry).ToValue());

  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(*this->type));

  }

  return to_value_result;
}


const char* ToString(LaunchSource enum_param) {
  switch (enum_param) {
    case LAUNCH_SOURCE_UNTRACKED:
      return "untracked";
    case LAUNCH_SOURCE_APP_LAUNCHER:
      return "app_launcher";
    case LAUNCH_SOURCE_NEW_TAB_PAGE:
      return "new_tab_page";
    case LAUNCH_SOURCE_RELOAD:
      return "reload";
    case LAUNCH_SOURCE_RESTART:
      return "restart";
    case LAUNCH_SOURCE_LOAD_AND_LAUNCH:
      return "load_and_launch";
    case LAUNCH_SOURCE_COMMAND_LINE:
      return "command_line";
    case LAUNCH_SOURCE_FILE_HANDLER:
      return "file_handler";
    case LAUNCH_SOURCE_URL_HANDLER:
      return "url_handler";
    case LAUNCH_SOURCE_SYSTEM_TRAY:
      return "system_tray";
    case LAUNCH_SOURCE_ABOUT_PAGE:
      return "about_page";
    case LAUNCH_SOURCE_KEYBOARD:
      return "keyboard";
    case LAUNCH_SOURCE_EXTENSIONS_PAGE:
      return "extensions_page";
    case LAUNCH_SOURCE_MANAGEMENT_API:
      return "management_api";
    case LAUNCH_SOURCE_EPHEMERAL_APP:
      return "ephemeral_app";
    case LAUNCH_SOURCE_BACKGROUND:
      return "background";
    case LAUNCH_SOURCE_KIOSK:
      return "kiosk";
    case LAUNCH_SOURCE_CHROME_INTERNAL:
      return "chrome_internal";
    case LAUNCH_SOURCE_TEST:
      return "test";
    case LAUNCH_SOURCE_INSTALLED_NOTIFICATION:
      return "installed_notification";
    case LAUNCH_SOURCE_CONTEXT_MENU:
      return "context_menu";
    case LAUNCH_SOURCE_ARC:
      return "arc";
    case LAUNCH_SOURCE_INTENT_URL:
      return "intent_url";
    case LAUNCH_SOURCE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LaunchSource ParseLaunchSource(const std::string& enum_string) {
  if (enum_string == "untracked")
    return LAUNCH_SOURCE_UNTRACKED;
  if (enum_string == "app_launcher")
    return LAUNCH_SOURCE_APP_LAUNCHER;
  if (enum_string == "new_tab_page")
    return LAUNCH_SOURCE_NEW_TAB_PAGE;
  if (enum_string == "reload")
    return LAUNCH_SOURCE_RELOAD;
  if (enum_string == "restart")
    return LAUNCH_SOURCE_RESTART;
  if (enum_string == "load_and_launch")
    return LAUNCH_SOURCE_LOAD_AND_LAUNCH;
  if (enum_string == "command_line")
    return LAUNCH_SOURCE_COMMAND_LINE;
  if (enum_string == "file_handler")
    return LAUNCH_SOURCE_FILE_HANDLER;
  if (enum_string == "url_handler")
    return LAUNCH_SOURCE_URL_HANDLER;
  if (enum_string == "system_tray")
    return LAUNCH_SOURCE_SYSTEM_TRAY;
  if (enum_string == "about_page")
    return LAUNCH_SOURCE_ABOUT_PAGE;
  if (enum_string == "keyboard")
    return LAUNCH_SOURCE_KEYBOARD;
  if (enum_string == "extensions_page")
    return LAUNCH_SOURCE_EXTENSIONS_PAGE;
  if (enum_string == "management_api")
    return LAUNCH_SOURCE_MANAGEMENT_API;
  if (enum_string == "ephemeral_app")
    return LAUNCH_SOURCE_EPHEMERAL_APP;
  if (enum_string == "background")
    return LAUNCH_SOURCE_BACKGROUND;
  if (enum_string == "kiosk")
    return LAUNCH_SOURCE_KIOSK;
  if (enum_string == "chrome_internal")
    return LAUNCH_SOURCE_CHROME_INTERNAL;
  if (enum_string == "test")
    return LAUNCH_SOURCE_TEST;
  if (enum_string == "installed_notification")
    return LAUNCH_SOURCE_INSTALLED_NOTIFICATION;
  if (enum_string == "context_menu")
    return LAUNCH_SOURCE_CONTEXT_MENU;
  if (enum_string == "arc")
    return LAUNCH_SOURCE_ARC;
  if (enum_string == "intent_url")
    return LAUNCH_SOURCE_INTENT_URL;
  return LAUNCH_SOURCE_NONE;
}


const char* ToString(ActionType enum_param) {
  switch (enum_param) {
    case ACTION_TYPE_NEW_NOTE:
      return "new_note";
    case ACTION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ActionType ParseActionType(const std::string& enum_string) {
  if (enum_string == "new_note")
    return ACTION_TYPE_NEW_NOTE;
  return ACTION_TYPE_NONE;
}


ActionData::ActionData()
: action_type(ACTION_TYPE_NONE) {}

ActionData::~ActionData() {}
ActionData::ActionData(ActionData&& rhs)
: action_type(rhs.action_type),
is_lock_screen_action(std::move(rhs.is_lock_screen_action)),
restore_last_action_state(std::move(rhs.restore_last_action_state)){
}

ActionData& ActionData::operator=(ActionData&& rhs)
{
action_type = rhs.action_type;
is_lock_screen_action = std::move(rhs.is_lock_screen_action);
restore_last_action_state = std::move(rhs.restore_last_action_state);
return *this;
}

// static
bool ActionData::Populate(
    const base::Value& value, ActionData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* action_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("actionType", &action_type_value)) {
    return false;
  }
  {
    std::string action_type_as_string;
    if (!action_type_value->GetAsString(&action_type_as_string)) {
      return false;
    }
    out->action_type = ParseActionType(action_type_as_string);
    if (out->action_type == ACTION_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* is_lock_screen_action_value = NULL;
  if (dict->GetWithoutPathExpansion("isLockScreenAction", &is_lock_screen_action_value)) {
    {
      bool temp;
      if (!is_lock_screen_action_value->GetAsBoolean(&temp)) {
        out->is_lock_screen_action.reset();
        return false;
      }
      else
        out->is_lock_screen_action.reset(new bool(temp));
    }
  }

  const base::Value* restore_last_action_state_value = NULL;
  if (dict->GetWithoutPathExpansion("restoreLastActionState", &restore_last_action_state_value)) {
    {
      bool temp;
      if (!restore_last_action_state_value->GetAsBoolean(&temp)) {
        out->restore_last_action_state.reset();
        return false;
      }
      else
        out->restore_last_action_state.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ActionData> ActionData::FromValue(const base::Value& value) {
  std::unique_ptr<ActionData> out(new ActionData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ActionData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("actionType", std::make_unique<base::Value>(app_runtime::ToString(this->action_type)));

  if (this->is_lock_screen_action.get()) {
    to_value_result->SetWithoutPathExpansion("isLockScreenAction", std::make_unique<base::Value>(*this->is_lock_screen_action));

  }
  if (this->restore_last_action_state.get()) {
    to_value_result->SetWithoutPathExpansion("restoreLastActionState", std::make_unique<base::Value>(*this->restore_last_action_state));

  }

  return to_value_result;
}


LaunchData::LaunchData()
: source(LAUNCH_SOURCE_NONE) {}

LaunchData::~LaunchData() {}
LaunchData::LaunchData(LaunchData&& rhs)
: id(std::move(rhs.id)),
items(std::move(rhs.items)),
url(std::move(rhs.url)),
referrer_url(std::move(rhs.referrer_url)),
is_demo_session(std::move(rhs.is_demo_session)),
is_kiosk_session(std::move(rhs.is_kiosk_session)),
is_public_session(std::move(rhs.is_public_session)),
source(rhs.source),
action_data(std::move(rhs.action_data)){
}

LaunchData& LaunchData::operator=(LaunchData&& rhs)
{
id = std::move(rhs.id);
items = std::move(rhs.items);
url = std::move(rhs.url);
referrer_url = std::move(rhs.referrer_url);
is_demo_session = std::move(rhs.is_demo_session);
is_kiosk_session = std::move(rhs.is_kiosk_session);
is_public_session = std::move(rhs.is_public_session);
source = rhs.source;
action_data = std::move(rhs.action_data);
return *this;
}

// static
bool LaunchData::Populate(
    const base::Value& value, LaunchData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->source = LAUNCH_SOURCE_NONE;
  const base::Value* id_value = NULL;
  if (dict->GetWithoutPathExpansion("id", &id_value)) {
    {
      std::string temp;
      if (!id_value->GetAsString(&temp)) {
        out->id.reset();
        return false;
      }
      else
        out->id.reset(new std::string(temp));
    }
  }

  const base::Value* items_value = NULL;
  if (dict->GetWithoutPathExpansion("items", &items_value)) {
    {
      const base::ListValue* list = NULL;
      if (!items_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->items)) {
          return false;
        }
      }
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
    }
  }

  const base::Value* referrer_url_value = NULL;
  if (dict->GetWithoutPathExpansion("referrerUrl", &referrer_url_value)) {
    {
      std::string temp;
      if (!referrer_url_value->GetAsString(&temp)) {
        out->referrer_url.reset();
        return false;
      }
      else
        out->referrer_url.reset(new std::string(temp));
    }
  }

  const base::Value* is_demo_session_value = NULL;
  if (dict->GetWithoutPathExpansion("isDemoSession", &is_demo_session_value)) {
    {
      bool temp;
      if (!is_demo_session_value->GetAsBoolean(&temp)) {
        out->is_demo_session.reset();
        return false;
      }
      else
        out->is_demo_session.reset(new bool(temp));
    }
  }

  const base::Value* is_kiosk_session_value = NULL;
  if (dict->GetWithoutPathExpansion("isKioskSession", &is_kiosk_session_value)) {
    {
      bool temp;
      if (!is_kiosk_session_value->GetAsBoolean(&temp)) {
        out->is_kiosk_session.reset();
        return false;
      }
      else
        out->is_kiosk_session.reset(new bool(temp));
    }
  }

  const base::Value* is_public_session_value = NULL;
  if (dict->GetWithoutPathExpansion("isPublicSession", &is_public_session_value)) {
    {
      bool temp;
      if (!is_public_session_value->GetAsBoolean(&temp)) {
        out->is_public_session.reset();
        return false;
      }
      else
        out->is_public_session.reset(new bool(temp));
    }
  }

  const base::Value* source_value = NULL;
  if (dict->GetWithoutPathExpansion("source", &source_value)) {
    {
      std::string launch_source_as_string;
      if (!source_value->GetAsString(&launch_source_as_string)) {
        return false;
      }
      out->source = ParseLaunchSource(launch_source_as_string);
      if (out->source == LAUNCH_SOURCE_NONE) {
        return false;
      }
    }
    } else {
    out->source = LAUNCH_SOURCE_NONE;
  }

  const base::Value* action_data_value = NULL;
  if (dict->GetWithoutPathExpansion("actionData", &action_data_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!action_data_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ActionData> temp(new ActionData());
        if (!ActionData::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->action_data = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<LaunchData> LaunchData::FromValue(const base::Value& value) {
  std::unique_ptr<LaunchData> out(new LaunchData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> LaunchData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }
  if (this->items.get()) {
    to_value_result->SetWithoutPathExpansion("items", json_schema_compiler::util::CreateValueFromOptionalArray(this->items));

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  if (this->referrer_url.get()) {
    to_value_result->SetWithoutPathExpansion("referrerUrl", std::make_unique<base::Value>(*this->referrer_url));

  }
  if (this->is_demo_session.get()) {
    to_value_result->SetWithoutPathExpansion("isDemoSession", std::make_unique<base::Value>(*this->is_demo_session));

  }
  if (this->is_kiosk_session.get()) {
    to_value_result->SetWithoutPathExpansion("isKioskSession", std::make_unique<base::Value>(*this->is_kiosk_session));

  }
  if (this->is_public_session.get()) {
    to_value_result->SetWithoutPathExpansion("isPublicSession", std::make_unique<base::Value>(*this->is_public_session));

  }
  if (this->source != LAUNCH_SOURCE_NONE) {
    to_value_result->SetWithoutPathExpansion("source", std::make_unique<base::Value>(app_runtime::ToString(this->source)));

  }
  if (this->action_data.get()) {
    to_value_result->SetWithoutPathExpansion("actionData", (this->action_data)->ToValue());

  }

  return to_value_result;
}


EmbedRequest::EmbedRequest()
 {}

EmbedRequest::~EmbedRequest() {}
EmbedRequest::EmbedRequest(EmbedRequest&& rhs)
: embedder_id(std::move(rhs.embedder_id)),
data(std::move(rhs.data)){
}

EmbedRequest& EmbedRequest::operator=(EmbedRequest&& rhs)
{
embedder_id = std::move(rhs.embedder_id);
data = std::move(rhs.data);
return *this;
}

// static
bool EmbedRequest::Populate(
    const base::Value& value, EmbedRequest* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* embedder_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("embedderId", &embedder_id_value)) {
    return false;
  }
  {
    if (!embedder_id_value->GetAsString(&out->embedder_id)) {
      return false;
    }
  }

  const base::Value* data_value = NULL;
  if (dict->GetWithoutPathExpansion("data", &data_value)) {
    {
      out->data = data_value->CreateDeepCopy();
    }
  }

  return true;
}

// static
std::unique_ptr<EmbedRequest> EmbedRequest::FromValue(const base::Value& value) {
  std::unique_ptr<EmbedRequest> out(new EmbedRequest());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EmbedRequest::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("embedderId", std::make_unique<base::Value>(this->embedder_id));

  if (this->data.get()) {
    to_value_result->SetWithoutPathExpansion("data", (this->data)->CreateDeepCopy());

  }

  return to_value_result;
}



//
// Events
//

namespace OnEmbedRequested {

const char kEventName[] = "app.runtime.onEmbedRequested";

std::unique_ptr<base::ListValue> Create(const EmbedRequest& request) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((request).ToValue());

  return create_results;
}

}  // namespace OnEmbedRequested

namespace OnLaunched {

const char kEventName[] = "app.runtime.onLaunched";

std::unique_ptr<base::ListValue> Create(const LaunchData& launch_data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((launch_data).ToValue());

  return create_results;
}

}  // namespace OnLaunched

namespace OnRestarted {

const char kEventName[] = "app.runtime.onRestarted";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnRestarted

}  // namespace app_runtime
}  // namespace api
}  // namespace extensions

