// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/tabs.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/tabs.h"
#include <set>
#include <utility>
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"
#include "chrome/common/extensions/api/windows.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace tabs {
//
// Properties
//

const int TAB_ID_NONE = -1;

//
// Types
//

const char* ToString(TabStatus enum_param) {
  switch (enum_param) {
    case TAB_STATUS_UNLOADED:
      return "unloaded";
    case TAB_STATUS_LOADING:
      return "loading";
    case TAB_STATUS_COMPLETE:
      return "complete";
    case TAB_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TabStatus ParseTabStatus(const std::string& enum_string) {
  if (enum_string == "unloaded")
    return TAB_STATUS_UNLOADED;
  if (enum_string == "loading")
    return TAB_STATUS_LOADING;
  if (enum_string == "complete")
    return TAB_STATUS_COMPLETE;
  return TAB_STATUS_NONE;
}


const char* ToString(MutedInfoReason enum_param) {
  switch (enum_param) {
    case MUTED_INFO_REASON_USER:
      return "user";
    case MUTED_INFO_REASON_CAPTURE:
      return "capture";
    case MUTED_INFO_REASON_EXTENSION:
      return "extension";
    case MUTED_INFO_REASON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MutedInfoReason ParseMutedInfoReason(const std::string& enum_string) {
  if (enum_string == "user")
    return MUTED_INFO_REASON_USER;
  if (enum_string == "capture")
    return MUTED_INFO_REASON_CAPTURE;
  if (enum_string == "extension")
    return MUTED_INFO_REASON_EXTENSION;
  return MUTED_INFO_REASON_NONE;
}


MutedInfo::MutedInfo()
: muted(false),
reason(MUTED_INFO_REASON_NONE) {}

MutedInfo::~MutedInfo() {}
MutedInfo::MutedInfo(MutedInfo&& rhs)
: muted(rhs.muted),
reason(rhs.reason),
extension_id(std::move(rhs.extension_id)){
}

MutedInfo& MutedInfo::operator=(MutedInfo&& rhs)
{
muted = rhs.muted;
reason = rhs.reason;
extension_id = std::move(rhs.extension_id);
return *this;
}

// static
bool MutedInfo::Populate(
    const base::Value& value, MutedInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->reason = MUTED_INFO_REASON_NONE;
  const base::Value* muted_value = NULL;
  if (!dict->GetWithoutPathExpansion("muted", &muted_value)) {
    return false;
  }
  {
    if (!muted_value->GetAsBoolean(&out->muted)) {
      return false;
    }
  }

  const base::Value* reason_value = NULL;
  if (dict->GetWithoutPathExpansion("reason", &reason_value)) {
    {
      std::string muted_info_reason_as_string;
      if (!reason_value->GetAsString(&muted_info_reason_as_string)) {
        return false;
      }
      out->reason = ParseMutedInfoReason(muted_info_reason_as_string);
      if (out->reason == MUTED_INFO_REASON_NONE) {
        return false;
      }
    }
    } else {
    out->reason = MUTED_INFO_REASON_NONE;
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

  return true;
}

// static
std::unique_ptr<MutedInfo> MutedInfo::FromValue(const base::Value& value) {
  std::unique_ptr<MutedInfo> out(new MutedInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MutedInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("muted", std::make_unique<base::Value>(this->muted));

  if (this->reason != MUTED_INFO_REASON_NONE) {
    to_value_result->SetWithoutPathExpansion("reason", std::make_unique<base::Value>(tabs::ToString(this->reason)));

  }
  if (this->extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(*this->extension_id));

  }

  return to_value_result;
}


Tab::Tab()
: index(0),
window_id(0),
selected(false),
highlighted(false),
active(false),
pinned(false),
discarded(false),
auto_discardable(false),
status(TAB_STATUS_NONE),
incognito(false) {}

Tab::~Tab() {}
Tab::Tab(Tab&& rhs)
: id(std::move(rhs.id)),
index(rhs.index),
window_id(rhs.window_id),
opener_tab_id(std::move(rhs.opener_tab_id)),
selected(rhs.selected),
highlighted(rhs.highlighted),
active(rhs.active),
pinned(rhs.pinned),
audible(std::move(rhs.audible)),
discarded(rhs.discarded),
auto_discardable(rhs.auto_discardable),
muted_info(std::move(rhs.muted_info)),
url(std::move(rhs.url)),
pending_url(std::move(rhs.pending_url)),
title(std::move(rhs.title)),
fav_icon_url(std::move(rhs.fav_icon_url)),
status(rhs.status),
incognito(rhs.incognito),
width(std::move(rhs.width)),
height(std::move(rhs.height)),
session_id(std::move(rhs.session_id)){
}

Tab& Tab::operator=(Tab&& rhs)
{
id = std::move(rhs.id);
index = rhs.index;
window_id = rhs.window_id;
opener_tab_id = std::move(rhs.opener_tab_id);
selected = rhs.selected;
highlighted = rhs.highlighted;
active = rhs.active;
pinned = rhs.pinned;
audible = std::move(rhs.audible);
discarded = rhs.discarded;
auto_discardable = rhs.auto_discardable;
muted_info = std::move(rhs.muted_info);
url = std::move(rhs.url);
pending_url = std::move(rhs.pending_url);
title = std::move(rhs.title);
fav_icon_url = std::move(rhs.fav_icon_url);
status = rhs.status;
incognito = rhs.incognito;
width = std::move(rhs.width);
height = std::move(rhs.height);
session_id = std::move(rhs.session_id);
return *this;
}

// static
bool Tab::Populate(
    const base::Value& value, Tab* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->status = TAB_STATUS_NONE;
  const base::Value* id_value = NULL;
  if (dict->GetWithoutPathExpansion("id", &id_value)) {
    {
      int temp;
      if (!id_value->GetAsInteger(&temp)) {
        out->id.reset();
        return false;
      }
      else
        out->id.reset(new int(temp));
    }
  }

  const base::Value* index_value = NULL;
  if (!dict->GetWithoutPathExpansion("index", &index_value)) {
    return false;
  }
  {
    if (!index_value->GetAsInteger(&out->index)) {
      return false;
    }
  }

  const base::Value* window_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("windowId", &window_id_value)) {
    return false;
  }
  {
    if (!window_id_value->GetAsInteger(&out->window_id)) {
      return false;
    }
  }

  const base::Value* opener_tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("openerTabId", &opener_tab_id_value)) {
    {
      int temp;
      if (!opener_tab_id_value->GetAsInteger(&temp)) {
        out->opener_tab_id.reset();
        return false;
      }
      else
        out->opener_tab_id.reset(new int(temp));
    }
  }

  const base::Value* selected_value = NULL;
  if (!dict->GetWithoutPathExpansion("selected", &selected_value)) {
    return false;
  }
  {
    if (!selected_value->GetAsBoolean(&out->selected)) {
      return false;
    }
  }

  const base::Value* highlighted_value = NULL;
  if (!dict->GetWithoutPathExpansion("highlighted", &highlighted_value)) {
    return false;
  }
  {
    if (!highlighted_value->GetAsBoolean(&out->highlighted)) {
      return false;
    }
  }

  const base::Value* active_value = NULL;
  if (!dict->GetWithoutPathExpansion("active", &active_value)) {
    return false;
  }
  {
    if (!active_value->GetAsBoolean(&out->active)) {
      return false;
    }
  }

  const base::Value* pinned_value = NULL;
  if (!dict->GetWithoutPathExpansion("pinned", &pinned_value)) {
    return false;
  }
  {
    if (!pinned_value->GetAsBoolean(&out->pinned)) {
      return false;
    }
  }

  const base::Value* audible_value = NULL;
  if (dict->GetWithoutPathExpansion("audible", &audible_value)) {
    {
      bool temp;
      if (!audible_value->GetAsBoolean(&temp)) {
        out->audible.reset();
        return false;
      }
      else
        out->audible.reset(new bool(temp));
    }
  }

  const base::Value* discarded_value = NULL;
  if (!dict->GetWithoutPathExpansion("discarded", &discarded_value)) {
    return false;
  }
  {
    if (!discarded_value->GetAsBoolean(&out->discarded)) {
      return false;
    }
  }

  const base::Value* auto_discardable_value = NULL;
  if (!dict->GetWithoutPathExpansion("autoDiscardable", &auto_discardable_value)) {
    return false;
  }
  {
    if (!auto_discardable_value->GetAsBoolean(&out->auto_discardable)) {
      return false;
    }
  }

  const base::Value* muted_info_value = NULL;
  if (dict->GetWithoutPathExpansion("mutedInfo", &muted_info_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!muted_info_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<MutedInfo> temp(new MutedInfo());
        if (!MutedInfo::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->muted_info = std::move(temp);
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

  const base::Value* pending_url_value = NULL;
  if (dict->GetWithoutPathExpansion("pendingUrl", &pending_url_value)) {
    {
      std::string temp;
      if (!pending_url_value->GetAsString(&temp)) {
        out->pending_url.reset();
        return false;
      }
      else
        out->pending_url.reset(new std::string(temp));
    }
  }

  const base::Value* title_value = NULL;
  if (dict->GetWithoutPathExpansion("title", &title_value)) {
    {
      std::string temp;
      if (!title_value->GetAsString(&temp)) {
        out->title.reset();
        return false;
      }
      else
        out->title.reset(new std::string(temp));
    }
  }

  const base::Value* fav_icon_url_value = NULL;
  if (dict->GetWithoutPathExpansion("favIconUrl", &fav_icon_url_value)) {
    {
      std::string temp;
      if (!fav_icon_url_value->GetAsString(&temp)) {
        out->fav_icon_url.reset();
        return false;
      }
      else
        out->fav_icon_url.reset(new std::string(temp));
    }
  }

  const base::Value* status_value = NULL;
  if (dict->GetWithoutPathExpansion("status", &status_value)) {
    {
      std::string tab_status_as_string;
      if (!status_value->GetAsString(&tab_status_as_string)) {
        return false;
      }
      out->status = ParseTabStatus(tab_status_as_string);
      if (out->status == TAB_STATUS_NONE) {
        return false;
      }
    }
    } else {
    out->status = TAB_STATUS_NONE;
  }

  const base::Value* incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    return false;
  }
  {
    if (!incognito_value->GetAsBoolean(&out->incognito)) {
      return false;
    }
  }

  const base::Value* width_value = NULL;
  if (dict->GetWithoutPathExpansion("width", &width_value)) {
    {
      int temp;
      if (!width_value->GetAsInteger(&temp)) {
        out->width.reset();
        return false;
      }
      else
        out->width.reset(new int(temp));
    }
  }

  const base::Value* height_value = NULL;
  if (dict->GetWithoutPathExpansion("height", &height_value)) {
    {
      int temp;
      if (!height_value->GetAsInteger(&temp)) {
        out->height.reset();
        return false;
      }
      else
        out->height.reset(new int(temp));
    }
  }

  const base::Value* session_id_value = NULL;
  if (dict->GetWithoutPathExpansion("sessionId", &session_id_value)) {
    {
      std::string temp;
      if (!session_id_value->GetAsString(&temp)) {
        out->session_id.reset();
        return false;
      }
      else
        out->session_id.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Tab> Tab::FromValue(const base::Value& value) {
  std::unique_ptr<Tab> out(new Tab());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Tab::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }
  to_value_result->SetWithoutPathExpansion("index", std::make_unique<base::Value>(this->index));

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));

  if (this->opener_tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("openerTabId", std::make_unique<base::Value>(*this->opener_tab_id));

  }
  to_value_result->SetWithoutPathExpansion("selected", std::make_unique<base::Value>(this->selected));

  to_value_result->SetWithoutPathExpansion("highlighted", std::make_unique<base::Value>(this->highlighted));

  to_value_result->SetWithoutPathExpansion("active", std::make_unique<base::Value>(this->active));

  to_value_result->SetWithoutPathExpansion("pinned", std::make_unique<base::Value>(this->pinned));

  if (this->audible.get()) {
    to_value_result->SetWithoutPathExpansion("audible", std::make_unique<base::Value>(*this->audible));

  }
  to_value_result->SetWithoutPathExpansion("discarded", std::make_unique<base::Value>(this->discarded));

  to_value_result->SetWithoutPathExpansion("autoDiscardable", std::make_unique<base::Value>(this->auto_discardable));

  if (this->muted_info.get()) {
    to_value_result->SetWithoutPathExpansion("mutedInfo", (this->muted_info)->ToValue());

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  if (this->pending_url.get()) {
    to_value_result->SetWithoutPathExpansion("pendingUrl", std::make_unique<base::Value>(*this->pending_url));

  }
  if (this->title.get()) {
    to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(*this->title));

  }
  if (this->fav_icon_url.get()) {
    to_value_result->SetWithoutPathExpansion("favIconUrl", std::make_unique<base::Value>(*this->fav_icon_url));

  }
  if (this->status != TAB_STATUS_NONE) {
    to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(tabs::ToString(this->status)));

  }
  to_value_result->SetWithoutPathExpansion("incognito", std::make_unique<base::Value>(this->incognito));

  if (this->width.get()) {
    to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(*this->width));

  }
  if (this->height.get()) {
    to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(*this->height));

  }
  if (this->session_id.get()) {
    to_value_result->SetWithoutPathExpansion("sessionId", std::make_unique<base::Value>(*this->session_id));

  }

  return to_value_result;
}


const char* ToString(ZoomSettingsMode enum_param) {
  switch (enum_param) {
    case ZOOM_SETTINGS_MODE_AUTOMATIC:
      return "automatic";
    case ZOOM_SETTINGS_MODE_MANUAL:
      return "manual";
    case ZOOM_SETTINGS_MODE_DISABLED:
      return "disabled";
    case ZOOM_SETTINGS_MODE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ZoomSettingsMode ParseZoomSettingsMode(const std::string& enum_string) {
  if (enum_string == "automatic")
    return ZOOM_SETTINGS_MODE_AUTOMATIC;
  if (enum_string == "manual")
    return ZOOM_SETTINGS_MODE_MANUAL;
  if (enum_string == "disabled")
    return ZOOM_SETTINGS_MODE_DISABLED;
  return ZOOM_SETTINGS_MODE_NONE;
}


const char* ToString(ZoomSettingsScope enum_param) {
  switch (enum_param) {
    case ZOOM_SETTINGS_SCOPE_PER_ORIGIN:
      return "per-origin";
    case ZOOM_SETTINGS_SCOPE_PER_TAB:
      return "per-tab";
    case ZOOM_SETTINGS_SCOPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ZoomSettingsScope ParseZoomSettingsScope(const std::string& enum_string) {
  if (enum_string == "per-origin")
    return ZOOM_SETTINGS_SCOPE_PER_ORIGIN;
  if (enum_string == "per-tab")
    return ZOOM_SETTINGS_SCOPE_PER_TAB;
  return ZOOM_SETTINGS_SCOPE_NONE;
}


ZoomSettings::ZoomSettings()
: mode(ZOOM_SETTINGS_MODE_NONE),
scope(ZOOM_SETTINGS_SCOPE_NONE) {}

ZoomSettings::~ZoomSettings() {}
ZoomSettings::ZoomSettings(ZoomSettings&& rhs)
: mode(rhs.mode),
scope(rhs.scope),
default_zoom_factor(std::move(rhs.default_zoom_factor)){
}

ZoomSettings& ZoomSettings::operator=(ZoomSettings&& rhs)
{
mode = rhs.mode;
scope = rhs.scope;
default_zoom_factor = std::move(rhs.default_zoom_factor);
return *this;
}

// static
bool ZoomSettings::Populate(
    const base::Value& value, ZoomSettings* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->mode = ZOOM_SETTINGS_MODE_NONE;
  out->scope = ZOOM_SETTINGS_SCOPE_NONE;
  const base::Value* mode_value = NULL;
  if (dict->GetWithoutPathExpansion("mode", &mode_value)) {
    {
      std::string zoom_settings_mode_as_string;
      if (!mode_value->GetAsString(&zoom_settings_mode_as_string)) {
        return false;
      }
      out->mode = ParseZoomSettingsMode(zoom_settings_mode_as_string);
      if (out->mode == ZOOM_SETTINGS_MODE_NONE) {
        return false;
      }
    }
    } else {
    out->mode = ZOOM_SETTINGS_MODE_NONE;
  }

  const base::Value* scope_value = NULL;
  if (dict->GetWithoutPathExpansion("scope", &scope_value)) {
    {
      std::string zoom_settings_scope_as_string;
      if (!scope_value->GetAsString(&zoom_settings_scope_as_string)) {
        return false;
      }
      out->scope = ParseZoomSettingsScope(zoom_settings_scope_as_string);
      if (out->scope == ZOOM_SETTINGS_SCOPE_NONE) {
        return false;
      }
    }
    } else {
    out->scope = ZOOM_SETTINGS_SCOPE_NONE;
  }

  const base::Value* default_zoom_factor_value = NULL;
  if (dict->GetWithoutPathExpansion("defaultZoomFactor", &default_zoom_factor_value)) {
    {
      double temp;
      if (!default_zoom_factor_value->GetAsDouble(&temp)) {
        out->default_zoom_factor.reset();
        return false;
      }
      else
        out->default_zoom_factor.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ZoomSettings> ZoomSettings::FromValue(const base::Value& value) {
  std::unique_ptr<ZoomSettings> out(new ZoomSettings());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ZoomSettings::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->mode != ZOOM_SETTINGS_MODE_NONE) {
    to_value_result->SetWithoutPathExpansion("mode", std::make_unique<base::Value>(tabs::ToString(this->mode)));

  }
  if (this->scope != ZOOM_SETTINGS_SCOPE_NONE) {
    to_value_result->SetWithoutPathExpansion("scope", std::make_unique<base::Value>(tabs::ToString(this->scope)));

  }
  if (this->default_zoom_factor.get()) {
    to_value_result->SetWithoutPathExpansion("defaultZoomFactor", std::make_unique<base::Value>(*this->default_zoom_factor));

  }

  return to_value_result;
}


const char* ToString(WindowType enum_param) {
  switch (enum_param) {
    case WINDOW_TYPE_NORMAL:
      return "normal";
    case WINDOW_TYPE_POPUP:
      return "popup";
    case WINDOW_TYPE_PANEL:
      return "panel";
    case WINDOW_TYPE_APP:
      return "app";
    case WINDOW_TYPE_DEVTOOLS:
      return "devtools";
    case WINDOW_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

WindowType ParseWindowType(const std::string& enum_string) {
  if (enum_string == "normal")
    return WINDOW_TYPE_NORMAL;
  if (enum_string == "popup")
    return WINDOW_TYPE_POPUP;
  if (enum_string == "panel")
    return WINDOW_TYPE_PANEL;
  if (enum_string == "app")
    return WINDOW_TYPE_APP;
  if (enum_string == "devtools")
    return WINDOW_TYPE_DEVTOOLS;
  return WINDOW_TYPE_NONE;
}



//
// Functions
//

namespace Get {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      if (!tab_id_value->GetAsInteger(&params->tab_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}
}  // namespace Get

namespace GetCurrent {

std::unique_ptr<base::ListValue> Results::Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}
}  // namespace GetCurrent

namespace GetSelected {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* window_id_value = NULL;
  if (args.Get(0, &window_id_value) &&
      !window_id_value->is_none()) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        params->window_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->window_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}
}  // namespace GetSelected

namespace GetAllInWindow {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* window_id_value = NULL;
  if (args.Get(0, &window_id_value) &&
      !window_id_value->is_none()) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        params->window_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->window_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Tab>& tabs) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(tabs));

  return create_results;
}
}  // namespace GetAllInWindow

namespace Create {

Params::CreateProperties::CreateProperties()
 {}

Params::CreateProperties::~CreateProperties() {}
Params::CreateProperties::CreateProperties(CreateProperties&& rhs)
: window_id(std::move(rhs.window_id)),
index(std::move(rhs.index)),
url(std::move(rhs.url)),
active(std::move(rhs.active)),
selected(std::move(rhs.selected)),
pinned(std::move(rhs.pinned)),
opener_tab_id(std::move(rhs.opener_tab_id)){
}

Params::CreateProperties& Params::CreateProperties::operator=(CreateProperties&& rhs)
{
window_id = std::move(rhs.window_id);
index = std::move(rhs.index);
url = std::move(rhs.url);
active = std::move(rhs.active);
selected = std::move(rhs.selected);
pinned = std::move(rhs.pinned);
opener_tab_id = std::move(rhs.opener_tab_id);
return *this;
}

// static
bool Params::CreateProperties::Populate(
    const base::Value& value, CreateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* window_id_value = NULL;
  if (dict->GetWithoutPathExpansion("windowId", &window_id_value)) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        out->window_id.reset();
        return false;
      }
      else
        out->window_id.reset(new int(temp));
    }
  }

  const base::Value* index_value = NULL;
  if (dict->GetWithoutPathExpansion("index", &index_value)) {
    {
      int temp;
      if (!index_value->GetAsInteger(&temp)) {
        out->index.reset();
        return false;
      }
      else
        out->index.reset(new int(temp));
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

  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("active", &active_value)) {
    {
      bool temp;
      if (!active_value->GetAsBoolean(&temp)) {
        out->active.reset();
        return false;
      }
      else
        out->active.reset(new bool(temp));
    }
  }

  const base::Value* selected_value = NULL;
  if (dict->GetWithoutPathExpansion("selected", &selected_value)) {
    {
      bool temp;
      if (!selected_value->GetAsBoolean(&temp)) {
        out->selected.reset();
        return false;
      }
      else
        out->selected.reset(new bool(temp));
    }
  }

  const base::Value* pinned_value = NULL;
  if (dict->GetWithoutPathExpansion("pinned", &pinned_value)) {
    {
      bool temp;
      if (!pinned_value->GetAsBoolean(&temp)) {
        out->pinned.reset();
        return false;
      }
      else
        out->pinned.reset(new bool(temp));
    }
  }

  const base::Value* opener_tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("openerTabId", &opener_tab_id_value)) {
    {
      int temp;
      if (!opener_tab_id_value->GetAsInteger(&temp)) {
        out->opener_tab_id.reset();
        return false;
      }
      else
        out->opener_tab_id.reset(new int(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* create_properties_value = NULL;
  if (args.Get(0, &create_properties_value) &&
      !create_properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!create_properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CreateProperties::Populate(*dictionary, &params->create_properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}
}  // namespace Create

namespace Duplicate {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      if (!tab_id_value->GetAsInteger(&params->tab_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}
}  // namespace Duplicate

namespace Query {

Params::QueryInfo::Url::Url()
 {}

Params::QueryInfo::Url::~Url() {}
Params::QueryInfo::Url::Url(Url&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)){
}

Params::QueryInfo::Url& Params::QueryInfo::Url::operator=(Url&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool Params::QueryInfo::Url::Populate(
    const base::Value& value, Url* out) {
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
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



Params::QueryInfo::QueryInfo()
: status(TAB_STATUS_NONE),
window_type(WINDOW_TYPE_NONE) {}

Params::QueryInfo::~QueryInfo() {}
Params::QueryInfo::QueryInfo(QueryInfo&& rhs)
: active(std::move(rhs.active)),
pinned(std::move(rhs.pinned)),
audible(std::move(rhs.audible)),
muted(std::move(rhs.muted)),
highlighted(std::move(rhs.highlighted)),
discarded(std::move(rhs.discarded)),
auto_discardable(std::move(rhs.auto_discardable)),
current_window(std::move(rhs.current_window)),
last_focused_window(std::move(rhs.last_focused_window)),
status(rhs.status),
title(std::move(rhs.title)),
url(std::move(rhs.url)),
window_id(std::move(rhs.window_id)),
window_type(rhs.window_type),
index(std::move(rhs.index)){
}

Params::QueryInfo& Params::QueryInfo::operator=(QueryInfo&& rhs)
{
active = std::move(rhs.active);
pinned = std::move(rhs.pinned);
audible = std::move(rhs.audible);
muted = std::move(rhs.muted);
highlighted = std::move(rhs.highlighted);
discarded = std::move(rhs.discarded);
auto_discardable = std::move(rhs.auto_discardable);
current_window = std::move(rhs.current_window);
last_focused_window = std::move(rhs.last_focused_window);
status = rhs.status;
title = std::move(rhs.title);
url = std::move(rhs.url);
window_id = std::move(rhs.window_id);
window_type = rhs.window_type;
index = std::move(rhs.index);
return *this;
}

// static
bool Params::QueryInfo::Populate(
    const base::Value& value, QueryInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->status = TAB_STATUS_NONE;
  out->window_type = WINDOW_TYPE_NONE;
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("active", &active_value)) {
    {
      bool temp;
      if (!active_value->GetAsBoolean(&temp)) {
        out->active.reset();
        return false;
      }
      else
        out->active.reset(new bool(temp));
    }
  }

  const base::Value* pinned_value = NULL;
  if (dict->GetWithoutPathExpansion("pinned", &pinned_value)) {
    {
      bool temp;
      if (!pinned_value->GetAsBoolean(&temp)) {
        out->pinned.reset();
        return false;
      }
      else
        out->pinned.reset(new bool(temp));
    }
  }

  const base::Value* audible_value = NULL;
  if (dict->GetWithoutPathExpansion("audible", &audible_value)) {
    {
      bool temp;
      if (!audible_value->GetAsBoolean(&temp)) {
        out->audible.reset();
        return false;
      }
      else
        out->audible.reset(new bool(temp));
    }
  }

  const base::Value* muted_value = NULL;
  if (dict->GetWithoutPathExpansion("muted", &muted_value)) {
    {
      bool temp;
      if (!muted_value->GetAsBoolean(&temp)) {
        out->muted.reset();
        return false;
      }
      else
        out->muted.reset(new bool(temp));
    }
  }

  const base::Value* highlighted_value = NULL;
  if (dict->GetWithoutPathExpansion("highlighted", &highlighted_value)) {
    {
      bool temp;
      if (!highlighted_value->GetAsBoolean(&temp)) {
        out->highlighted.reset();
        return false;
      }
      else
        out->highlighted.reset(new bool(temp));
    }
  }

  const base::Value* discarded_value = NULL;
  if (dict->GetWithoutPathExpansion("discarded", &discarded_value)) {
    {
      bool temp;
      if (!discarded_value->GetAsBoolean(&temp)) {
        out->discarded.reset();
        return false;
      }
      else
        out->discarded.reset(new bool(temp));
    }
  }

  const base::Value* auto_discardable_value = NULL;
  if (dict->GetWithoutPathExpansion("autoDiscardable", &auto_discardable_value)) {
    {
      bool temp;
      if (!auto_discardable_value->GetAsBoolean(&temp)) {
        out->auto_discardable.reset();
        return false;
      }
      else
        out->auto_discardable.reset(new bool(temp));
    }
  }

  const base::Value* current_window_value = NULL;
  if (dict->GetWithoutPathExpansion("currentWindow", &current_window_value)) {
    {
      bool temp;
      if (!current_window_value->GetAsBoolean(&temp)) {
        out->current_window.reset();
        return false;
      }
      else
        out->current_window.reset(new bool(temp));
    }
  }

  const base::Value* last_focused_window_value = NULL;
  if (dict->GetWithoutPathExpansion("lastFocusedWindow", &last_focused_window_value)) {
    {
      bool temp;
      if (!last_focused_window_value->GetAsBoolean(&temp)) {
        out->last_focused_window.reset();
        return false;
      }
      else
        out->last_focused_window.reset(new bool(temp));
    }
  }

  const base::Value* status_value = NULL;
  if (dict->GetWithoutPathExpansion("status", &status_value)) {
    {
      std::string tab_status_as_string;
      if (!status_value->GetAsString(&tab_status_as_string)) {
        return false;
      }
      out->status = ParseTabStatus(tab_status_as_string);
      if (out->status == TAB_STATUS_NONE) {
        return false;
      }
    }
    } else {
    out->status = TAB_STATUS_NONE;
  }

  const base::Value* title_value = NULL;
  if (dict->GetWithoutPathExpansion("title", &title_value)) {
    {
      std::string temp;
      if (!title_value->GetAsString(&temp)) {
        out->title.reset();
        return false;
      }
      else
        out->title.reset(new std::string(temp));
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::unique_ptr<Url> temp(new Url());
      if (!Url::Populate(*url_value, temp.get()))
        return false;
      out->url = std::move(temp);
    }
  }

  const base::Value* window_id_value = NULL;
  if (dict->GetWithoutPathExpansion("windowId", &window_id_value)) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        out->window_id.reset();
        return false;
      }
      else
        out->window_id.reset(new int(temp));
    }
  }

  const base::Value* window_type_value = NULL;
  if (dict->GetWithoutPathExpansion("windowType", &window_type_value)) {
    {
      std::string window_type_as_string;
      if (!window_type_value->GetAsString(&window_type_as_string)) {
        return false;
      }
      out->window_type = ParseWindowType(window_type_as_string);
      if (out->window_type == WINDOW_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->window_type = WINDOW_TYPE_NONE;
  }

  const base::Value* index_value = NULL;
  if (dict->GetWithoutPathExpansion("index", &index_value)) {
    {
      int temp;
      if (!index_value->GetAsInteger(&temp)) {
        out->index.reset();
        return false;
      }
      else
        out->index.reset(new int(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* query_info_value = NULL;
  if (args.Get(0, &query_info_value) &&
      !query_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!query_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!QueryInfo::Populate(*dictionary, &params->query_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Tab>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace Query

namespace Highlight {

Params::HighlightInfo::Tabs::Tabs()
 {}

Params::HighlightInfo::Tabs::~Tabs() {}
Params::HighlightInfo::Tabs::Tabs(Tabs&& rhs)
: as_integers(std::move(rhs.as_integers)),
as_integer(std::move(rhs.as_integer)){
}

Params::HighlightInfo::Tabs& Params::HighlightInfo::Tabs::operator=(Tabs&& rhs)
{
as_integers = std::move(rhs.as_integers);
as_integer = std::move(rhs.as_integer);
return *this;
}

// static
bool Params::HighlightInfo::Tabs::Populate(
    const base::Value& value, Tabs* out) {
  if (value.type() == base::Value::Type::LIST) {
    {
      const base::ListValue* list = NULL;
      if (!(&value)->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_integers)) {
          return false;
        }
      }
    }
    return true;
  }
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
    }
    return true;
  }
  return false;
}



Params::HighlightInfo::HighlightInfo()
 {}

Params::HighlightInfo::~HighlightInfo() {}
Params::HighlightInfo::HighlightInfo(HighlightInfo&& rhs)
: window_id(std::move(rhs.window_id)),
tabs(std::move(rhs.tabs)){
}

Params::HighlightInfo& Params::HighlightInfo::operator=(HighlightInfo&& rhs)
{
window_id = std::move(rhs.window_id);
tabs = std::move(rhs.tabs);
return *this;
}

// static
bool Params::HighlightInfo::Populate(
    const base::Value& value, HighlightInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* window_id_value = NULL;
  if (dict->GetWithoutPathExpansion("windowId", &window_id_value)) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        out->window_id.reset();
        return false;
      }
      else
        out->window_id.reset(new int(temp));
    }
  }

  const base::Value* tabs_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabs", &tabs_value)) {
    return false;
  }
  {
    if (!Tabs::Populate(*tabs_value, &out->tabs))
      return false;
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* highlight_info_value = NULL;
  if (args.Get(0, &highlight_info_value) &&
      !highlight_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!highlight_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!HighlightInfo::Populate(*dictionary, &params->highlight_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const extensions::api::windows::Window& window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((window).ToValue());

  return create_results;
}
}  // namespace Highlight

namespace Update {

Params::UpdateProperties::UpdateProperties()
 {}

Params::UpdateProperties::~UpdateProperties() {}
Params::UpdateProperties::UpdateProperties(UpdateProperties&& rhs)
: url(std::move(rhs.url)),
active(std::move(rhs.active)),
highlighted(std::move(rhs.highlighted)),
selected(std::move(rhs.selected)),
pinned(std::move(rhs.pinned)),
muted(std::move(rhs.muted)),
opener_tab_id(std::move(rhs.opener_tab_id)),
auto_discardable(std::move(rhs.auto_discardable)){
}

Params::UpdateProperties& Params::UpdateProperties::operator=(UpdateProperties&& rhs)
{
url = std::move(rhs.url);
active = std::move(rhs.active);
highlighted = std::move(rhs.highlighted);
selected = std::move(rhs.selected);
pinned = std::move(rhs.pinned);
muted = std::move(rhs.muted);
opener_tab_id = std::move(rhs.opener_tab_id);
auto_discardable = std::move(rhs.auto_discardable);
return *this;
}

// static
bool Params::UpdateProperties::Populate(
    const base::Value& value, UpdateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("active", &active_value)) {
    {
      bool temp;
      if (!active_value->GetAsBoolean(&temp)) {
        out->active.reset();
        return false;
      }
      else
        out->active.reset(new bool(temp));
    }
  }

  const base::Value* highlighted_value = NULL;
  if (dict->GetWithoutPathExpansion("highlighted", &highlighted_value)) {
    {
      bool temp;
      if (!highlighted_value->GetAsBoolean(&temp)) {
        out->highlighted.reset();
        return false;
      }
      else
        out->highlighted.reset(new bool(temp));
    }
  }

  const base::Value* selected_value = NULL;
  if (dict->GetWithoutPathExpansion("selected", &selected_value)) {
    {
      bool temp;
      if (!selected_value->GetAsBoolean(&temp)) {
        out->selected.reset();
        return false;
      }
      else
        out->selected.reset(new bool(temp));
    }
  }

  const base::Value* pinned_value = NULL;
  if (dict->GetWithoutPathExpansion("pinned", &pinned_value)) {
    {
      bool temp;
      if (!pinned_value->GetAsBoolean(&temp)) {
        out->pinned.reset();
        return false;
      }
      else
        out->pinned.reset(new bool(temp));
    }
  }

  const base::Value* muted_value = NULL;
  if (dict->GetWithoutPathExpansion("muted", &muted_value)) {
    {
      bool temp;
      if (!muted_value->GetAsBoolean(&temp)) {
        out->muted.reset();
        return false;
      }
      else
        out->muted.reset(new bool(temp));
    }
  }

  const base::Value* opener_tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("openerTabId", &opener_tab_id_value)) {
    {
      int temp;
      if (!opener_tab_id_value->GetAsInteger(&temp)) {
        out->opener_tab_id.reset();
        return false;
      }
      else
        out->opener_tab_id.reset(new int(temp));
    }
  }

  const base::Value* auto_discardable_value = NULL;
  if (dict->GetWithoutPathExpansion("autoDiscardable", &auto_discardable_value)) {
    {
      bool temp;
      if (!auto_discardable_value->GetAsBoolean(&temp)) {
        out->auto_discardable.reset();
        return false;
      }
      else
        out->auto_discardable.reset(new bool(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  const base::Value* update_properties_value = NULL;
  if (args.Get(1, &update_properties_value) &&
      !update_properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!update_properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!UpdateProperties::Populate(*dictionary, &params->update_properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}
}  // namespace Update

namespace Move {

Params::TabIds::TabIds()
 {}

Params::TabIds::~TabIds() {}
Params::TabIds::TabIds(TabIds&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_integers(std::move(rhs.as_integers)){
}

Params::TabIds& Params::TabIds::operator=(TabIds&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_integers = std::move(rhs.as_integers);
return *this;
}

// static
bool Params::TabIds::Populate(
    const base::Value& value, TabIds* out) {
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
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
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_integers)) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}


Params::MoveProperties::MoveProperties()
: index(0) {}

Params::MoveProperties::~MoveProperties() {}
Params::MoveProperties::MoveProperties(MoveProperties&& rhs)
: window_id(std::move(rhs.window_id)),
index(rhs.index){
}

Params::MoveProperties& Params::MoveProperties::operator=(MoveProperties&& rhs)
{
window_id = std::move(rhs.window_id);
index = rhs.index;
return *this;
}

// static
bool Params::MoveProperties::Populate(
    const base::Value& value, MoveProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* window_id_value = NULL;
  if (dict->GetWithoutPathExpansion("windowId", &window_id_value)) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        out->window_id.reset();
        return false;
      }
      else
        out->window_id.reset(new int(temp));
    }
  }

  const base::Value* index_value = NULL;
  if (!dict->GetWithoutPathExpansion("index", &index_value)) {
    return false;
  }
  {
    if (!index_value->GetAsInteger(&out->index)) {
      return false;
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_ids_value = NULL;
  if (args.Get(0, &tab_ids_value) &&
      !tab_ids_value->is_none()) {
    {
      if (!TabIds::Populate(*tab_ids_value, &params->tab_ids))
        return std::unique_ptr<Params>();
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* move_properties_value = NULL;
  if (args.Get(1, &move_properties_value) &&
      !move_properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!move_properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!MoveProperties::Populate(*dictionary, &params->move_properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Tabs::Tabs()
 {}

Results::Tabs::~Tabs() {}
Results::Tabs::Tabs(Tabs&& rhs)
: as_tab(std::move(rhs.as_tab)),
as_tabs(std::move(rhs.as_tabs)){
}

Results::Tabs& Results::Tabs::operator=(Tabs&& rhs)
{
as_tab = std::move(rhs.as_tab);
as_tabs = std::move(rhs.as_tabs);
return *this;
}

std::unique_ptr<base::Value> Results::Tabs::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_tab) {
    DCHECK(!result) << "Cannot set multiple choices for tabs";
    result = (as_tab)->ToValue();

  }
  if (as_tabs) {
    DCHECK(!result) << "Cannot set multiple choices for tabs";
    result = json_schema_compiler::util::CreateValueFromOptionalArray(as_tabs);

  }
  DCHECK(result) << "Must set at least one choice for tabs";
  return result;
}


std::unique_ptr<base::ListValue> Results::Create(const Tabs& tabs) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tabs).ToValue());

  return create_results;
}
}  // namespace Move

namespace Reload {

Params::ReloadProperties::ReloadProperties()
 {}

Params::ReloadProperties::~ReloadProperties() {}
Params::ReloadProperties::ReloadProperties(ReloadProperties&& rhs)
: bypass_cache(std::move(rhs.bypass_cache)){
}

Params::ReloadProperties& Params::ReloadProperties::operator=(ReloadProperties&& rhs)
{
bypass_cache = std::move(rhs.bypass_cache);
return *this;
}

// static
bool Params::ReloadProperties::Populate(
    const base::Value& value, ReloadProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* bypass_cache_value = NULL;
  if (dict->GetWithoutPathExpansion("bypassCache", &bypass_cache_value)) {
    {
      bool temp;
      if (!bypass_cache_value->GetAsBoolean(&temp)) {
        out->bypass_cache.reset();
        return false;
      }
      else
        out->bypass_cache.reset(new bool(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  const base::Value* reload_properties_value = NULL;
  if (args.Get(1, &reload_properties_value) &&
      !reload_properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!reload_properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<ReloadProperties> temp(new ReloadProperties());
        if (!ReloadProperties::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->reload_properties = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Reload

namespace Remove {

Params::TabIds::TabIds()
 {}

Params::TabIds::~TabIds() {}
Params::TabIds::TabIds(TabIds&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_integers(std::move(rhs.as_integers)){
}

Params::TabIds& Params::TabIds::operator=(TabIds&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_integers = std::move(rhs.as_integers);
return *this;
}

// static
bool Params::TabIds::Populate(
    const base::Value& value, TabIds* out) {
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
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
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_integers)) {
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

  const base::Value* tab_ids_value = NULL;
  if (args.Get(0, &tab_ids_value) &&
      !tab_ids_value->is_none()) {
    {
      if (!TabIds::Populate(*tab_ids_value, &params->tab_ids))
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
}  // namespace Remove

namespace DetectLanguage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& language) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(language));

  return create_results;
}
}  // namespace DetectLanguage

namespace CaptureVisibleTab {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* window_id_value = NULL;
  if (args.Get(0, &window_id_value) &&
      !window_id_value->is_none()) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        params->window_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->window_id.reset(new int(temp));
    }
  }

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<extensions::api::extension_types::ImageDetails> temp(new extensions::api::extension_types::ImageDetails());
        if (!extensions::api::extension_types::ImageDetails::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& data_url) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(data_url));

  return create_results;
}
}  // namespace CaptureVisibleTab

namespace ExecuteScript {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  const base::Value* details_value = NULL;
  if (args.Get(1, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!extensions::api::extension_types::InjectDetails::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::unique_ptr<base::Value>>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace ExecuteScript

namespace InsertCSS {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  const base::Value* details_value = NULL;
  if (args.Get(1, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!extensions::api::extension_types::InjectDetails::Populate(*dictionary, &params->details)) {
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
}  // namespace InsertCSS

namespace SetZoom {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  const base::Value* zoom_factor_value = NULL;
  if (args.Get(1, &zoom_factor_value) &&
      !zoom_factor_value->is_none()) {
    {
      if (!zoom_factor_value->GetAsDouble(&params->zoom_factor)) {
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
}  // namespace SetZoom

namespace GetZoom {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(double zoom_factor) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(zoom_factor));

  return create_results;
}
}  // namespace GetZoom

namespace SetZoomSettings {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  const base::Value* zoom_settings_value = NULL;
  if (args.Get(1, &zoom_settings_value) &&
      !zoom_settings_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!zoom_settings_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ZoomSettings::Populate(*dictionary, &params->zoom_settings)) {
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
}  // namespace SetZoomSettings

namespace GetZoomSettings {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ZoomSettings& zoom_settings) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((zoom_settings).ToValue());

  return create_results;
}
}  // namespace GetZoomSettings

namespace Discard {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}
}  // namespace Discard

namespace GoForward {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace GoForward

namespace GoBack {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        params->tab_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->tab_id.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace GoBack

//
// Events
//

namespace OnCreated {

const char kEventName[] = "tabs.onCreated";

std::unique_ptr<base::ListValue> Create(const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((tab).ToValue());

  return create_results;
}

}  // namespace OnCreated

namespace OnUpdated {

const char kEventName[] = "tabs.onUpdated";

ChangeInfo::ChangeInfo()
: status(TAB_STATUS_NONE) {}

ChangeInfo::~ChangeInfo() {}
ChangeInfo::ChangeInfo(ChangeInfo&& rhs)
: status(rhs.status),
url(std::move(rhs.url)),
pinned(std::move(rhs.pinned)),
audible(std::move(rhs.audible)),
discarded(std::move(rhs.discarded)),
auto_discardable(std::move(rhs.auto_discardable)),
muted_info(std::move(rhs.muted_info)),
fav_icon_url(std::move(rhs.fav_icon_url)),
title(std::move(rhs.title)){
}

ChangeInfo& ChangeInfo::operator=(ChangeInfo&& rhs)
{
status = rhs.status;
url = std::move(rhs.url);
pinned = std::move(rhs.pinned);
audible = std::move(rhs.audible);
discarded = std::move(rhs.discarded);
auto_discardable = std::move(rhs.auto_discardable);
muted_info = std::move(rhs.muted_info);
fav_icon_url = std::move(rhs.fav_icon_url);
title = std::move(rhs.title);
return *this;
}

std::unique_ptr<base::DictionaryValue> ChangeInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->status != TAB_STATUS_NONE) {
    to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(tabs::ToString(this->status)));

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  if (this->pinned.get()) {
    to_value_result->SetWithoutPathExpansion("pinned", std::make_unique<base::Value>(*this->pinned));

  }
  if (this->audible.get()) {
    to_value_result->SetWithoutPathExpansion("audible", std::make_unique<base::Value>(*this->audible));

  }
  if (this->discarded.get()) {
    to_value_result->SetWithoutPathExpansion("discarded", std::make_unique<base::Value>(*this->discarded));

  }
  if (this->auto_discardable.get()) {
    to_value_result->SetWithoutPathExpansion("autoDiscardable", std::make_unique<base::Value>(*this->auto_discardable));

  }
  if (this->muted_info.get()) {
    to_value_result->SetWithoutPathExpansion("mutedInfo", (this->muted_info)->ToValue());

  }
  if (this->fav_icon_url.get()) {
    to_value_result->SetWithoutPathExpansion("favIconUrl", std::make_unique<base::Value>(*this->fav_icon_url));

  }
  if (this->title.get()) {
    to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(*this->title));

  }

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(int tab_id, const ChangeInfo& change_info, const Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tab_id));

  create_results->Append((change_info).ToValue());

  create_results->Append((tab).ToValue());

  return create_results;
}

}  // namespace OnUpdated

namespace OnMoved {

const char kEventName[] = "tabs.onMoved";

MoveInfo::MoveInfo()
: window_id(0),
from_index(0),
to_index(0) {}

MoveInfo::~MoveInfo() {}
MoveInfo::MoveInfo(MoveInfo&& rhs)
: window_id(rhs.window_id),
from_index(rhs.from_index),
to_index(rhs.to_index){
}

MoveInfo& MoveInfo::operator=(MoveInfo&& rhs)
{
window_id = rhs.window_id;
from_index = rhs.from_index;
to_index = rhs.to_index;
return *this;
}

std::unique_ptr<base::DictionaryValue> MoveInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));

  to_value_result->SetWithoutPathExpansion("fromIndex", std::make_unique<base::Value>(this->from_index));

  to_value_result->SetWithoutPathExpansion("toIndex", std::make_unique<base::Value>(this->to_index));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(int tab_id, const MoveInfo& move_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tab_id));

  create_results->Append((move_info).ToValue());

  return create_results;
}

}  // namespace OnMoved

namespace OnSelectionChanged {

const char kEventName[] = "tabs.onSelectionChanged";

SelectInfo::SelectInfo()
: window_id(0) {}

SelectInfo::~SelectInfo() {}
SelectInfo::SelectInfo(SelectInfo&& rhs)
: window_id(rhs.window_id){
}

SelectInfo& SelectInfo::operator=(SelectInfo&& rhs)
{
window_id = rhs.window_id;
return *this;
}

std::unique_ptr<base::DictionaryValue> SelectInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(int tab_id, const SelectInfo& select_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tab_id));

  create_results->Append((select_info).ToValue());

  return create_results;
}

}  // namespace OnSelectionChanged

namespace OnActiveChanged {

const char kEventName[] = "tabs.onActiveChanged";

SelectInfo::SelectInfo()
: window_id(0) {}

SelectInfo::~SelectInfo() {}
SelectInfo::SelectInfo(SelectInfo&& rhs)
: window_id(rhs.window_id){
}

SelectInfo& SelectInfo::operator=(SelectInfo&& rhs)
{
window_id = rhs.window_id;
return *this;
}

std::unique_ptr<base::DictionaryValue> SelectInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(int tab_id, const SelectInfo& select_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tab_id));

  create_results->Append((select_info).ToValue());

  return create_results;
}

}  // namespace OnActiveChanged

namespace OnActivated {

const char kEventName[] = "tabs.onActivated";

ActiveInfo::ActiveInfo()
: tab_id(0),
window_id(0) {}

ActiveInfo::~ActiveInfo() {}
ActiveInfo::ActiveInfo(ActiveInfo&& rhs)
: tab_id(rhs.tab_id),
window_id(rhs.window_id){
}

ActiveInfo& ActiveInfo::operator=(ActiveInfo&& rhs)
{
tab_id = rhs.tab_id;
window_id = rhs.window_id;
return *this;
}

std::unique_ptr<base::DictionaryValue> ActiveInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const ActiveInfo& active_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((active_info).ToValue());

  return create_results;
}

}  // namespace OnActivated

namespace OnHighlightChanged {

const char kEventName[] = "tabs.onHighlightChanged";

SelectInfo::SelectInfo()
: window_id(0) {}

SelectInfo::~SelectInfo() {}
SelectInfo::SelectInfo(SelectInfo&& rhs)
: window_id(rhs.window_id),
tab_ids(std::move(rhs.tab_ids)){
}

SelectInfo& SelectInfo::operator=(SelectInfo&& rhs)
{
window_id = rhs.window_id;
tab_ids = std::move(rhs.tab_ids);
return *this;
}

std::unique_ptr<base::DictionaryValue> SelectInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));

  to_value_result->SetWithoutPathExpansion("tabIds", json_schema_compiler::util::CreateValueFromArray(this->tab_ids));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const SelectInfo& select_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((select_info).ToValue());

  return create_results;
}

}  // namespace OnHighlightChanged

namespace OnHighlighted {

const char kEventName[] = "tabs.onHighlighted";

HighlightInfo::HighlightInfo()
: window_id(0) {}

HighlightInfo::~HighlightInfo() {}
HighlightInfo::HighlightInfo(HighlightInfo&& rhs)
: window_id(rhs.window_id),
tab_ids(std::move(rhs.tab_ids)){
}

HighlightInfo& HighlightInfo::operator=(HighlightInfo&& rhs)
{
window_id = rhs.window_id;
tab_ids = std::move(rhs.tab_ids);
return *this;
}

std::unique_ptr<base::DictionaryValue> HighlightInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));

  to_value_result->SetWithoutPathExpansion("tabIds", json_schema_compiler::util::CreateValueFromArray(this->tab_ids));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const HighlightInfo& highlight_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((highlight_info).ToValue());

  return create_results;
}

}  // namespace OnHighlighted

namespace OnDetached {

const char kEventName[] = "tabs.onDetached";

DetachInfo::DetachInfo()
: old_window_id(0),
old_position(0) {}

DetachInfo::~DetachInfo() {}
DetachInfo::DetachInfo(DetachInfo&& rhs)
: old_window_id(rhs.old_window_id),
old_position(rhs.old_position){
}

DetachInfo& DetachInfo::operator=(DetachInfo&& rhs)
{
old_window_id = rhs.old_window_id;
old_position = rhs.old_position;
return *this;
}

std::unique_ptr<base::DictionaryValue> DetachInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("oldWindowId", std::make_unique<base::Value>(this->old_window_id));

  to_value_result->SetWithoutPathExpansion("oldPosition", std::make_unique<base::Value>(this->old_position));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(int tab_id, const DetachInfo& detach_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tab_id));

  create_results->Append((detach_info).ToValue());

  return create_results;
}

}  // namespace OnDetached

namespace OnAttached {

const char kEventName[] = "tabs.onAttached";

AttachInfo::AttachInfo()
: new_window_id(0),
new_position(0) {}

AttachInfo::~AttachInfo() {}
AttachInfo::AttachInfo(AttachInfo&& rhs)
: new_window_id(rhs.new_window_id),
new_position(rhs.new_position){
}

AttachInfo& AttachInfo::operator=(AttachInfo&& rhs)
{
new_window_id = rhs.new_window_id;
new_position = rhs.new_position;
return *this;
}

std::unique_ptr<base::DictionaryValue> AttachInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("newWindowId", std::make_unique<base::Value>(this->new_window_id));

  to_value_result->SetWithoutPathExpansion("newPosition", std::make_unique<base::Value>(this->new_position));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(int tab_id, const AttachInfo& attach_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tab_id));

  create_results->Append((attach_info).ToValue());

  return create_results;
}

}  // namespace OnAttached

namespace OnRemoved {

const char kEventName[] = "tabs.onRemoved";

RemoveInfo::RemoveInfo()
: window_id(0),
is_window_closing(false) {}

RemoveInfo::~RemoveInfo() {}
RemoveInfo::RemoveInfo(RemoveInfo&& rhs)
: window_id(rhs.window_id),
is_window_closing(rhs.is_window_closing){
}

RemoveInfo& RemoveInfo::operator=(RemoveInfo&& rhs)
{
window_id = rhs.window_id;
is_window_closing = rhs.is_window_closing;
return *this;
}

std::unique_ptr<base::DictionaryValue> RemoveInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(this->window_id));

  to_value_result->SetWithoutPathExpansion("isWindowClosing", std::make_unique<base::Value>(this->is_window_closing));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(int tab_id, const RemoveInfo& remove_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(tab_id));

  create_results->Append((remove_info).ToValue());

  return create_results;
}

}  // namespace OnRemoved

namespace OnReplaced {

const char kEventName[] = "tabs.onReplaced";

std::unique_ptr<base::ListValue> Create(int added_tab_id, int removed_tab_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(added_tab_id));

  create_results->Append(std::make_unique<base::Value>(removed_tab_id));

  return create_results;
}

}  // namespace OnReplaced

namespace OnZoomChange {

const char kEventName[] = "tabs.onZoomChange";

ZoomChangeInfo::ZoomChangeInfo()
: tab_id(0),
old_zoom_factor(0.0),
new_zoom_factor(0.0) {}

ZoomChangeInfo::~ZoomChangeInfo() {}
ZoomChangeInfo::ZoomChangeInfo(ZoomChangeInfo&& rhs)
: tab_id(rhs.tab_id),
old_zoom_factor(rhs.old_zoom_factor),
new_zoom_factor(rhs.new_zoom_factor),
zoom_settings(std::move(rhs.zoom_settings)){
}

ZoomChangeInfo& ZoomChangeInfo::operator=(ZoomChangeInfo&& rhs)
{
tab_id = rhs.tab_id;
old_zoom_factor = rhs.old_zoom_factor;
new_zoom_factor = rhs.new_zoom_factor;
zoom_settings = std::move(rhs.zoom_settings);
return *this;
}

std::unique_ptr<base::DictionaryValue> ZoomChangeInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("oldZoomFactor", std::make_unique<base::Value>(this->old_zoom_factor));

  to_value_result->SetWithoutPathExpansion("newZoomFactor", std::make_unique<base::Value>(this->new_zoom_factor));

  to_value_result->SetWithoutPathExpansion("zoomSettings", (this->zoom_settings).ToValue());


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const ZoomChangeInfo& zoom_change_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((zoom_change_info).ToValue());

  return create_results;
}

}  // namespace OnZoomChange

}  // namespace tabs
}  // namespace api
}  // namespace extensions

