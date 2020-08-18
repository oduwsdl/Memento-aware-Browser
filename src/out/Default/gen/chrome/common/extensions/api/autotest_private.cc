// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/autotest_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/autotest_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace autotest_private {
//
// Types
//

const char* ToString(ShelfAlignmentType enum_param) {
  switch (enum_param) {
    case SHELF_ALIGNMENT_TYPE_BOTTOM:
      return "Bottom";
    case SHELF_ALIGNMENT_TYPE_LEFT:
      return "Left";
    case SHELF_ALIGNMENT_TYPE_RIGHT:
      return "Right";
    case SHELF_ALIGNMENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ShelfAlignmentType ParseShelfAlignmentType(const std::string& enum_string) {
  if (enum_string == "Bottom")
    return SHELF_ALIGNMENT_TYPE_BOTTOM;
  if (enum_string == "Left")
    return SHELF_ALIGNMENT_TYPE_LEFT;
  if (enum_string == "Right")
    return SHELF_ALIGNMENT_TYPE_RIGHT;
  return SHELF_ALIGNMENT_TYPE_NONE;
}


const char* ToString(ShelfItemType enum_param) {
  switch (enum_param) {
    case SHELF_ITEM_TYPE_APP:
      return "App";
    case SHELF_ITEM_TYPE_PINNEDAPP:
      return "PinnedApp";
    case SHELF_ITEM_TYPE_BROWSERSHORTCUT:
      return "BrowserShortcut";
    case SHELF_ITEM_TYPE_DIALOG:
      return "Dialog";
    case SHELF_ITEM_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ShelfItemType ParseShelfItemType(const std::string& enum_string) {
  if (enum_string == "App")
    return SHELF_ITEM_TYPE_APP;
  if (enum_string == "PinnedApp")
    return SHELF_ITEM_TYPE_PINNEDAPP;
  if (enum_string == "BrowserShortcut")
    return SHELF_ITEM_TYPE_BROWSERSHORTCUT;
  if (enum_string == "Dialog")
    return SHELF_ITEM_TYPE_DIALOG;
  return SHELF_ITEM_TYPE_NONE;
}


const char* ToString(ShelfItemStatus enum_param) {
  switch (enum_param) {
    case SHELF_ITEM_STATUS_CLOSED:
      return "Closed";
    case SHELF_ITEM_STATUS_RUNNING:
      return "Running";
    case SHELF_ITEM_STATUS_ATTENTION:
      return "Attention";
    case SHELF_ITEM_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ShelfItemStatus ParseShelfItemStatus(const std::string& enum_string) {
  if (enum_string == "Closed")
    return SHELF_ITEM_STATUS_CLOSED;
  if (enum_string == "Running")
    return SHELF_ITEM_STATUS_RUNNING;
  if (enum_string == "Attention")
    return SHELF_ITEM_STATUS_ATTENTION;
  return SHELF_ITEM_STATUS_NONE;
}


const char* ToString(AppType enum_param) {
  switch (enum_param) {
    case APP_TYPE_ARC:
      return "Arc";
    case APP_TYPE_BUILTIN:
      return "BuiltIn";
    case APP_TYPE_CROSTINI:
      return "Crostini";
    case APP_TYPE_EXTENSION:
      return "Extension";
    case APP_TYPE_WEB:
      return "Web";
    case APP_TYPE_MACNATIVE:
      return "MacNative";
    case APP_TYPE_PLUGINVM:
      return "PluginVm";
    case APP_TYPE_LACROS:
      return "Lacros";
    case APP_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

AppType ParseAppType(const std::string& enum_string) {
  if (enum_string == "Arc")
    return APP_TYPE_ARC;
  if (enum_string == "BuiltIn")
    return APP_TYPE_BUILTIN;
  if (enum_string == "Crostini")
    return APP_TYPE_CROSTINI;
  if (enum_string == "Extension")
    return APP_TYPE_EXTENSION;
  if (enum_string == "Web")
    return APP_TYPE_WEB;
  if (enum_string == "MacNative")
    return APP_TYPE_MACNATIVE;
  if (enum_string == "PluginVm")
    return APP_TYPE_PLUGINVM;
  if (enum_string == "Lacros")
    return APP_TYPE_LACROS;
  return APP_TYPE_NONE;
}


const char* ToString(AppReadiness enum_param) {
  switch (enum_param) {
    case APP_READINESS_READY:
      return "Ready";
    case APP_READINESS_DISABLEDBYBLACKLIST:
      return "DisabledByBlacklist";
    case APP_READINESS_DISABLEDBYPOLICY:
      return "DisabledByPolicy";
    case APP_READINESS_DISABLEDBYUSER:
      return "DisabledByUser";
    case APP_READINESS_TERMINATED:
      return "Terminated";
    case APP_READINESS_UNINSTALLEDBYUSER:
      return "UninstalledByUser";
    case APP_READINESS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

AppReadiness ParseAppReadiness(const std::string& enum_string) {
  if (enum_string == "Ready")
    return APP_READINESS_READY;
  if (enum_string == "DisabledByBlacklist")
    return APP_READINESS_DISABLEDBYBLACKLIST;
  if (enum_string == "DisabledByPolicy")
    return APP_READINESS_DISABLEDBYPOLICY;
  if (enum_string == "DisabledByUser")
    return APP_READINESS_DISABLEDBYUSER;
  if (enum_string == "Terminated")
    return APP_READINESS_TERMINATED;
  if (enum_string == "UninstalledByUser")
    return APP_READINESS_UNINSTALLEDBYUSER;
  return APP_READINESS_NONE;
}


const char* ToString(WindowStateType enum_param) {
  switch (enum_param) {
    case WINDOW_STATE_TYPE_NORMAL:
      return "Normal";
    case WINDOW_STATE_TYPE_MINIMIZED:
      return "Minimized";
    case WINDOW_STATE_TYPE_MAXIMIZED:
      return "Maximized";
    case WINDOW_STATE_TYPE_FULLSCREEN:
      return "Fullscreen";
    case WINDOW_STATE_TYPE_LEFTSNAPPED:
      return "LeftSnapped";
    case WINDOW_STATE_TYPE_RIGHTSNAPPED:
      return "RightSnapped";
    case WINDOW_STATE_TYPE_PIP:
      return "PIP";
    case WINDOW_STATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

WindowStateType ParseWindowStateType(const std::string& enum_string) {
  if (enum_string == "Normal")
    return WINDOW_STATE_TYPE_NORMAL;
  if (enum_string == "Minimized")
    return WINDOW_STATE_TYPE_MINIMIZED;
  if (enum_string == "Maximized")
    return WINDOW_STATE_TYPE_MAXIMIZED;
  if (enum_string == "Fullscreen")
    return WINDOW_STATE_TYPE_FULLSCREEN;
  if (enum_string == "LeftSnapped")
    return WINDOW_STATE_TYPE_LEFTSNAPPED;
  if (enum_string == "RightSnapped")
    return WINDOW_STATE_TYPE_RIGHTSNAPPED;
  if (enum_string == "PIP")
    return WINDOW_STATE_TYPE_PIP;
  return WINDOW_STATE_TYPE_NONE;
}


const char* ToString(WMEventType enum_param) {
  switch (enum_param) {
    case WM_EVENT_TYPE_WMEVENTNORMAL:
      return "WMEventNormal";
    case WM_EVENT_TYPE_WMEVENTMAXIMIZE:
      return "WMEventMaximize";
    case WM_EVENT_TYPE_WMEVENTMINIMIZE:
      return "WMEventMinimize";
    case WM_EVENT_TYPE_WMEVENTFULLSCREEN:
      return "WMEventFullscreen";
    case WM_EVENT_TYPE_WMEVENTSNAPLEFT:
      return "WMEventSnapLeft";
    case WM_EVENT_TYPE_WMEVENTSNAPRIGHT:
      return "WMEventSnapRight";
    case WM_EVENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

WMEventType ParseWMEventType(const std::string& enum_string) {
  if (enum_string == "WMEventNormal")
    return WM_EVENT_TYPE_WMEVENTNORMAL;
  if (enum_string == "WMEventMaximize")
    return WM_EVENT_TYPE_WMEVENTMAXIMIZE;
  if (enum_string == "WMEventMinimize")
    return WM_EVENT_TYPE_WMEVENTMINIMIZE;
  if (enum_string == "WMEventFullscreen")
    return WM_EVENT_TYPE_WMEVENTFULLSCREEN;
  if (enum_string == "WMEventSnapLeft")
    return WM_EVENT_TYPE_WMEVENTSNAPLEFT;
  if (enum_string == "WMEventSnapRight")
    return WM_EVENT_TYPE_WMEVENTSNAPRIGHT;
  return WM_EVENT_TYPE_NONE;
}


const char* ToString(RotationType enum_param) {
  switch (enum_param) {
    case ROTATION_TYPE_ROTATE0:
      return "Rotate0";
    case ROTATION_TYPE_ROTATE90:
      return "Rotate90";
    case ROTATION_TYPE_ROTATE180:
      return "Rotate180";
    case ROTATION_TYPE_ROTATE270:
      return "Rotate270";
    case ROTATION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

RotationType ParseRotationType(const std::string& enum_string) {
  if (enum_string == "Rotate0")
    return ROTATION_TYPE_ROTATE0;
  if (enum_string == "Rotate90")
    return ROTATION_TYPE_ROTATE90;
  if (enum_string == "Rotate180")
    return ROTATION_TYPE_ROTATE180;
  if (enum_string == "Rotate270")
    return ROTATION_TYPE_ROTATE270;
  return ROTATION_TYPE_NONE;
}


const char* ToString(LauncherStateType enum_param) {
  switch (enum_param) {
    case LAUNCHER_STATE_TYPE_CLOSED:
      return "Closed";
    case LAUNCHER_STATE_TYPE_PEEKING:
      return "Peeking";
    case LAUNCHER_STATE_TYPE_HALF:
      return "Half";
    case LAUNCHER_STATE_TYPE_FULLSCREENALLAPPS:
      return "FullscreenAllApps";
    case LAUNCHER_STATE_TYPE_FULLSCREENSEARCH:
      return "FullscreenSearch";
    case LAUNCHER_STATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LauncherStateType ParseLauncherStateType(const std::string& enum_string) {
  if (enum_string == "Closed")
    return LAUNCHER_STATE_TYPE_CLOSED;
  if (enum_string == "Peeking")
    return LAUNCHER_STATE_TYPE_PEEKING;
  if (enum_string == "Half")
    return LAUNCHER_STATE_TYPE_HALF;
  if (enum_string == "FullscreenAllApps")
    return LAUNCHER_STATE_TYPE_FULLSCREENALLAPPS;
  if (enum_string == "FullscreenSearch")
    return LAUNCHER_STATE_TYPE_FULLSCREENSEARCH;
  return LAUNCHER_STATE_TYPE_NONE;
}


const char* ToString(OverviewStateType enum_param) {
  switch (enum_param) {
    case OVERVIEW_STATE_TYPE_SHOWN:
      return "Shown";
    case OVERVIEW_STATE_TYPE_HIDDEN:
      return "Hidden";
    case OVERVIEW_STATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OverviewStateType ParseOverviewStateType(const std::string& enum_string) {
  if (enum_string == "Shown")
    return OVERVIEW_STATE_TYPE_SHOWN;
  if (enum_string == "Hidden")
    return OVERVIEW_STATE_TYPE_HIDDEN;
  return OVERVIEW_STATE_TYPE_NONE;
}


const char* ToString(MouseButton enum_param) {
  switch (enum_param) {
    case MOUSE_BUTTON_LEFT:
      return "Left";
    case MOUSE_BUTTON_MIDDLE:
      return "Middle";
    case MOUSE_BUTTON_RIGHT:
      return "Right";
    case MOUSE_BUTTON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MouseButton ParseMouseButton(const std::string& enum_string) {
  if (enum_string == "Left")
    return MOUSE_BUTTON_LEFT;
  if (enum_string == "Middle")
    return MOUSE_BUTTON_MIDDLE;
  if (enum_string == "Right")
    return MOUSE_BUTTON_RIGHT;
  return MOUSE_BUTTON_NONE;
}


WindowStateChangeDict::WindowStateChangeDict()
: event_type(WM_EVENT_TYPE_NONE) {}

WindowStateChangeDict::~WindowStateChangeDict() {}
WindowStateChangeDict::WindowStateChangeDict(WindowStateChangeDict&& rhs)
: event_type(rhs.event_type),
fail_if_no_change(std::move(rhs.fail_if_no_change)){
}

WindowStateChangeDict& WindowStateChangeDict::operator=(WindowStateChangeDict&& rhs)
{
event_type = rhs.event_type;
fail_if_no_change = std::move(rhs.fail_if_no_change);
return *this;
}

// static
bool WindowStateChangeDict::Populate(
    const base::Value& value, WindowStateChangeDict* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* event_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("eventType", &event_type_value)) {
    return false;
  }
  {
    std::string wm_event_type_as_string;
    if (!event_type_value->GetAsString(&wm_event_type_as_string)) {
      return false;
    }
    out->event_type = ParseWMEventType(wm_event_type_as_string);
    if (out->event_type == WM_EVENT_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* fail_if_no_change_value = NULL;
  if (dict->GetWithoutPathExpansion("failIfNoChange", &fail_if_no_change_value)) {
    {
      bool temp;
      if (!fail_if_no_change_value->GetAsBoolean(&temp)) {
        out->fail_if_no_change.reset();
        return false;
      }
      else
        out->fail_if_no_change.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<WindowStateChangeDict> WindowStateChangeDict::FromValue(const base::Value& value) {
  std::unique_ptr<WindowStateChangeDict> out(new WindowStateChangeDict());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> WindowStateChangeDict::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("eventType", std::make_unique<base::Value>(autotest_private::ToString(this->event_type)));

  if (this->fail_if_no_change.get()) {
    to_value_result->SetWithoutPathExpansion("failIfNoChange", std::make_unique<base::Value>(*this->fail_if_no_change));

  }

  return to_value_result;
}


LoginStatusDict::LoginStatusDict()
: is_logged_in(false),
is_owner(false),
is_screen_locked(false),
is_ready_for_password(false),
is_regular_user(false),
is_guest(false),
is_kiosk(false) {}

LoginStatusDict::~LoginStatusDict() {}
LoginStatusDict::LoginStatusDict(LoginStatusDict&& rhs)
: is_logged_in(rhs.is_logged_in),
is_owner(rhs.is_owner),
is_screen_locked(rhs.is_screen_locked),
is_ready_for_password(rhs.is_ready_for_password),
is_regular_user(rhs.is_regular_user),
is_guest(rhs.is_guest),
is_kiosk(rhs.is_kiosk),
email(std::move(rhs.email)),
display_email(std::move(rhs.display_email)),
user_image(std::move(rhs.user_image)){
}

LoginStatusDict& LoginStatusDict::operator=(LoginStatusDict&& rhs)
{
is_logged_in = rhs.is_logged_in;
is_owner = rhs.is_owner;
is_screen_locked = rhs.is_screen_locked;
is_ready_for_password = rhs.is_ready_for_password;
is_regular_user = rhs.is_regular_user;
is_guest = rhs.is_guest;
is_kiosk = rhs.is_kiosk;
email = std::move(rhs.email);
display_email = std::move(rhs.display_email);
user_image = std::move(rhs.user_image);
return *this;
}

// static
bool LoginStatusDict::Populate(
    const base::Value& value, LoginStatusDict* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* is_logged_in_value = NULL;
  if (!dict->GetWithoutPathExpansion("isLoggedIn", &is_logged_in_value)) {
    return false;
  }
  {
    if (!is_logged_in_value->GetAsBoolean(&out->is_logged_in)) {
      return false;
    }
  }

  const base::Value* is_owner_value = NULL;
  if (!dict->GetWithoutPathExpansion("isOwner", &is_owner_value)) {
    return false;
  }
  {
    if (!is_owner_value->GetAsBoolean(&out->is_owner)) {
      return false;
    }
  }

  const base::Value* is_screen_locked_value = NULL;
  if (!dict->GetWithoutPathExpansion("isScreenLocked", &is_screen_locked_value)) {
    return false;
  }
  {
    if (!is_screen_locked_value->GetAsBoolean(&out->is_screen_locked)) {
      return false;
    }
  }

  const base::Value* is_ready_for_password_value = NULL;
  if (!dict->GetWithoutPathExpansion("isReadyForPassword", &is_ready_for_password_value)) {
    return false;
  }
  {
    if (!is_ready_for_password_value->GetAsBoolean(&out->is_ready_for_password)) {
      return false;
    }
  }

  const base::Value* is_regular_user_value = NULL;
  if (!dict->GetWithoutPathExpansion("isRegularUser", &is_regular_user_value)) {
    return false;
  }
  {
    if (!is_regular_user_value->GetAsBoolean(&out->is_regular_user)) {
      return false;
    }
  }

  const base::Value* is_guest_value = NULL;
  if (!dict->GetWithoutPathExpansion("isGuest", &is_guest_value)) {
    return false;
  }
  {
    if (!is_guest_value->GetAsBoolean(&out->is_guest)) {
      return false;
    }
  }

  const base::Value* is_kiosk_value = NULL;
  if (!dict->GetWithoutPathExpansion("isKiosk", &is_kiosk_value)) {
    return false;
  }
  {
    if (!is_kiosk_value->GetAsBoolean(&out->is_kiosk)) {
      return false;
    }
  }

  const base::Value* email_value = NULL;
  if (!dict->GetWithoutPathExpansion("email", &email_value)) {
    return false;
  }
  {
    if (!email_value->GetAsString(&out->email)) {
      return false;
    }
  }

  const base::Value* display_email_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayEmail", &display_email_value)) {
    return false;
  }
  {
    if (!display_email_value->GetAsString(&out->display_email)) {
      return false;
    }
  }

  const base::Value* user_image_value = NULL;
  if (!dict->GetWithoutPathExpansion("userImage", &user_image_value)) {
    return false;
  }
  {
    if (!user_image_value->GetAsString(&out->user_image)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<LoginStatusDict> LoginStatusDict::FromValue(const base::Value& value) {
  std::unique_ptr<LoginStatusDict> out(new LoginStatusDict());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> LoginStatusDict::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("isLoggedIn", std::make_unique<base::Value>(this->is_logged_in));

  to_value_result->SetWithoutPathExpansion("isOwner", std::make_unique<base::Value>(this->is_owner));

  to_value_result->SetWithoutPathExpansion("isScreenLocked", std::make_unique<base::Value>(this->is_screen_locked));

  to_value_result->SetWithoutPathExpansion("isReadyForPassword", std::make_unique<base::Value>(this->is_ready_for_password));

  to_value_result->SetWithoutPathExpansion("isRegularUser", std::make_unique<base::Value>(this->is_regular_user));

  to_value_result->SetWithoutPathExpansion("isGuest", std::make_unique<base::Value>(this->is_guest));

  to_value_result->SetWithoutPathExpansion("isKiosk", std::make_unique<base::Value>(this->is_kiosk));

  to_value_result->SetWithoutPathExpansion("email", std::make_unique<base::Value>(this->email));

  to_value_result->SetWithoutPathExpansion("displayEmail", std::make_unique<base::Value>(this->display_email));

  to_value_result->SetWithoutPathExpansion("userImage", std::make_unique<base::Value>(this->user_image));


  return to_value_result;
}


ExtensionInfoDict::ExtensionInfoDict()
: is_component(false),
is_internal(false),
is_user_installed(false),
is_enabled(false),
allowed_in_incognito(false),
has_page_action(false) {}

ExtensionInfoDict::~ExtensionInfoDict() {}
ExtensionInfoDict::ExtensionInfoDict(ExtensionInfoDict&& rhs)
: id(std::move(rhs.id)),
version(std::move(rhs.version)),
name(std::move(rhs.name)),
public_key(std::move(rhs.public_key)),
description(std::move(rhs.description)),
background_url(std::move(rhs.background_url)),
options_url(std::move(rhs.options_url)),
host_permissions(std::move(rhs.host_permissions)),
effective_host_permissions(std::move(rhs.effective_host_permissions)),
api_permissions(std::move(rhs.api_permissions)),
is_component(rhs.is_component),
is_internal(rhs.is_internal),
is_user_installed(rhs.is_user_installed),
is_enabled(rhs.is_enabled),
allowed_in_incognito(rhs.allowed_in_incognito),
has_page_action(rhs.has_page_action){
}

ExtensionInfoDict& ExtensionInfoDict::operator=(ExtensionInfoDict&& rhs)
{
id = std::move(rhs.id);
version = std::move(rhs.version);
name = std::move(rhs.name);
public_key = std::move(rhs.public_key);
description = std::move(rhs.description);
background_url = std::move(rhs.background_url);
options_url = std::move(rhs.options_url);
host_permissions = std::move(rhs.host_permissions);
effective_host_permissions = std::move(rhs.effective_host_permissions);
api_permissions = std::move(rhs.api_permissions);
is_component = rhs.is_component;
is_internal = rhs.is_internal;
is_user_installed = rhs.is_user_installed;
is_enabled = rhs.is_enabled;
allowed_in_incognito = rhs.allowed_in_incognito;
has_page_action = rhs.has_page_action;
return *this;
}

// static
bool ExtensionInfoDict::Populate(
    const base::Value& value, ExtensionInfoDict* out) {
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

  const base::Value* version_value = NULL;
  if (!dict->GetWithoutPathExpansion("version", &version_value)) {
    return false;
  }
  {
    if (!version_value->GetAsString(&out->version)) {
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

  const base::Value* public_key_value = NULL;
  if (!dict->GetWithoutPathExpansion("publicKey", &public_key_value)) {
    return false;
  }
  {
    if (!public_key_value->GetAsString(&out->public_key)) {
      return false;
    }
  }

  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* background_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("backgroundUrl", &background_url_value)) {
    return false;
  }
  {
    if (!background_url_value->GetAsString(&out->background_url)) {
      return false;
    }
  }

  const base::Value* options_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("optionsUrl", &options_url_value)) {
    return false;
  }
  {
    if (!options_url_value->GetAsString(&out->options_url)) {
      return false;
    }
  }

  const base::Value* host_permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("hostPermissions", &host_permissions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!host_permissions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->host_permissions)) {
        return false;
      }
    }
  }

  const base::Value* effective_host_permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("effectiveHostPermissions", &effective_host_permissions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!effective_host_permissions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->effective_host_permissions)) {
        return false;
      }
    }
  }

  const base::Value* api_permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("apiPermissions", &api_permissions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!api_permissions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->api_permissions)) {
        return false;
      }
    }
  }

  const base::Value* is_component_value = NULL;
  if (!dict->GetWithoutPathExpansion("isComponent", &is_component_value)) {
    return false;
  }
  {
    if (!is_component_value->GetAsBoolean(&out->is_component)) {
      return false;
    }
  }

  const base::Value* is_internal_value = NULL;
  if (!dict->GetWithoutPathExpansion("isInternal", &is_internal_value)) {
    return false;
  }
  {
    if (!is_internal_value->GetAsBoolean(&out->is_internal)) {
      return false;
    }
  }

  const base::Value* is_user_installed_value = NULL;
  if (!dict->GetWithoutPathExpansion("isUserInstalled", &is_user_installed_value)) {
    return false;
  }
  {
    if (!is_user_installed_value->GetAsBoolean(&out->is_user_installed)) {
      return false;
    }
  }

  const base::Value* is_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("isEnabled", &is_enabled_value)) {
    return false;
  }
  {
    if (!is_enabled_value->GetAsBoolean(&out->is_enabled)) {
      return false;
    }
  }

  const base::Value* allowed_in_incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("allowedInIncognito", &allowed_in_incognito_value)) {
    return false;
  }
  {
    if (!allowed_in_incognito_value->GetAsBoolean(&out->allowed_in_incognito)) {
      return false;
    }
  }

  const base::Value* has_page_action_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasPageAction", &has_page_action_value)) {
    return false;
  }
  {
    if (!has_page_action_value->GetAsBoolean(&out->has_page_action)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ExtensionInfoDict> ExtensionInfoDict::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionInfoDict> out(new ExtensionInfoDict());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionInfoDict::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("version", std::make_unique<base::Value>(this->version));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("publicKey", std::make_unique<base::Value>(this->public_key));

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  to_value_result->SetWithoutPathExpansion("backgroundUrl", std::make_unique<base::Value>(this->background_url));

  to_value_result->SetWithoutPathExpansion("optionsUrl", std::make_unique<base::Value>(this->options_url));

  to_value_result->SetWithoutPathExpansion("hostPermissions", json_schema_compiler::util::CreateValueFromArray(this->host_permissions));

  to_value_result->SetWithoutPathExpansion("effectiveHostPermissions", json_schema_compiler::util::CreateValueFromArray(this->effective_host_permissions));

  to_value_result->SetWithoutPathExpansion("apiPermissions", json_schema_compiler::util::CreateValueFromArray(this->api_permissions));

  to_value_result->SetWithoutPathExpansion("isComponent", std::make_unique<base::Value>(this->is_component));

  to_value_result->SetWithoutPathExpansion("isInternal", std::make_unique<base::Value>(this->is_internal));

  to_value_result->SetWithoutPathExpansion("isUserInstalled", std::make_unique<base::Value>(this->is_user_installed));

  to_value_result->SetWithoutPathExpansion("isEnabled", std::make_unique<base::Value>(this->is_enabled));

  to_value_result->SetWithoutPathExpansion("allowedInIncognito", std::make_unique<base::Value>(this->allowed_in_incognito));

  to_value_result->SetWithoutPathExpansion("hasPageAction", std::make_unique<base::Value>(this->has_page_action));


  return to_value_result;
}


ExtensionsInfoArray::ExtensionsInfoArray()
 {}

ExtensionsInfoArray::~ExtensionsInfoArray() {}
ExtensionsInfoArray::ExtensionsInfoArray(ExtensionsInfoArray&& rhs)
: extensions(std::move(rhs.extensions)){
}

ExtensionsInfoArray& ExtensionsInfoArray::operator=(ExtensionsInfoArray&& rhs)
{
extensions = std::move(rhs.extensions);
return *this;
}

// static
bool ExtensionsInfoArray::Populate(
    const base::Value& value, ExtensionsInfoArray* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* extensions_value = NULL;
  if (!dict->GetWithoutPathExpansion("extensions", &extensions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!extensions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->extensions)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ExtensionsInfoArray> ExtensionsInfoArray::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionsInfoArray> out(new ExtensionsInfoArray());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionsInfoArray::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("extensions", json_schema_compiler::util::CreateValueFromArray(this->extensions));


  return to_value_result;
}


Notification::Notification()
: priority(0),
progress(0) {}

Notification::~Notification() {}
Notification::Notification(Notification&& rhs)
: id(std::move(rhs.id)),
type(std::move(rhs.type)),
title(std::move(rhs.title)),
message(std::move(rhs.message)),
priority(rhs.priority),
progress(rhs.progress){
}

Notification& Notification::operator=(Notification&& rhs)
{
id = std::move(rhs.id);
type = std::move(rhs.type);
title = std::move(rhs.title);
message = std::move(rhs.message);
priority = rhs.priority;
progress = rhs.progress;
return *this;
}

// static
bool Notification::Populate(
    const base::Value& value, Notification* out) {
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

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    if (!type_value->GetAsString(&out->type)) {
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

  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  const base::Value* priority_value = NULL;
  if (!dict->GetWithoutPathExpansion("priority", &priority_value)) {
    return false;
  }
  {
    if (!priority_value->GetAsInteger(&out->priority)) {
      return false;
    }
  }

  const base::Value* progress_value = NULL;
  if (!dict->GetWithoutPathExpansion("progress", &progress_value)) {
    return false;
  }
  {
    if (!progress_value->GetAsInteger(&out->progress)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Notification> Notification::FromValue(const base::Value& value) {
  std::unique_ptr<Notification> out(new Notification());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Notification::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(this->type));

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));

  to_value_result->SetWithoutPathExpansion("priority", std::make_unique<base::Value>(this->priority));

  to_value_result->SetWithoutPathExpansion("progress", std::make_unique<base::Value>(this->progress));


  return to_value_result;
}


Printer::Printer()
 {}

Printer::~Printer() {}
Printer::Printer(Printer&& rhs)
: printer_name(std::move(rhs.printer_name)),
printer_id(std::move(rhs.printer_id)),
printer_type(std::move(rhs.printer_type)),
printer_desc(std::move(rhs.printer_desc)),
printer_make_and_model(std::move(rhs.printer_make_and_model)),
printer_uri(std::move(rhs.printer_uri)),
printer_ppd(std::move(rhs.printer_ppd)){
}

Printer& Printer::operator=(Printer&& rhs)
{
printer_name = std::move(rhs.printer_name);
printer_id = std::move(rhs.printer_id);
printer_type = std::move(rhs.printer_type);
printer_desc = std::move(rhs.printer_desc);
printer_make_and_model = std::move(rhs.printer_make_and_model);
printer_uri = std::move(rhs.printer_uri);
printer_ppd = std::move(rhs.printer_ppd);
return *this;
}

// static
bool Printer::Populate(
    const base::Value& value, Printer* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* printer_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("printerName", &printer_name_value)) {
    return false;
  }
  {
    if (!printer_name_value->GetAsString(&out->printer_name)) {
      return false;
    }
  }

  const base::Value* printer_id_value = NULL;
  if (dict->GetWithoutPathExpansion("printerId", &printer_id_value)) {
    {
      std::string temp;
      if (!printer_id_value->GetAsString(&temp)) {
        out->printer_id.reset();
        return false;
      }
      else
        out->printer_id.reset(new std::string(temp));
    }
  }

  const base::Value* printer_type_value = NULL;
  if (dict->GetWithoutPathExpansion("printerType", &printer_type_value)) {
    {
      std::string temp;
      if (!printer_type_value->GetAsString(&temp)) {
        out->printer_type.reset();
        return false;
      }
      else
        out->printer_type.reset(new std::string(temp));
    }
  }

  const base::Value* printer_desc_value = NULL;
  if (dict->GetWithoutPathExpansion("printerDesc", &printer_desc_value)) {
    {
      std::string temp;
      if (!printer_desc_value->GetAsString(&temp)) {
        out->printer_desc.reset();
        return false;
      }
      else
        out->printer_desc.reset(new std::string(temp));
    }
  }

  const base::Value* printer_make_and_model_value = NULL;
  if (dict->GetWithoutPathExpansion("printerMakeAndModel", &printer_make_and_model_value)) {
    {
      std::string temp;
      if (!printer_make_and_model_value->GetAsString(&temp)) {
        out->printer_make_and_model.reset();
        return false;
      }
      else
        out->printer_make_and_model.reset(new std::string(temp));
    }
  }

  const base::Value* printer_uri_value = NULL;
  if (dict->GetWithoutPathExpansion("printerUri", &printer_uri_value)) {
    {
      std::string temp;
      if (!printer_uri_value->GetAsString(&temp)) {
        out->printer_uri.reset();
        return false;
      }
      else
        out->printer_uri.reset(new std::string(temp));
    }
  }

  const base::Value* printer_ppd_value = NULL;
  if (dict->GetWithoutPathExpansion("printerPpd", &printer_ppd_value)) {
    {
      std::string temp;
      if (!printer_ppd_value->GetAsString(&temp)) {
        out->printer_ppd.reset();
        return false;
      }
      else
        out->printer_ppd.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Printer> Printer::FromValue(const base::Value& value) {
  std::unique_ptr<Printer> out(new Printer());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Printer::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("printerName", std::make_unique<base::Value>(this->printer_name));

  if (this->printer_id.get()) {
    to_value_result->SetWithoutPathExpansion("printerId", std::make_unique<base::Value>(*this->printer_id));

  }
  if (this->printer_type.get()) {
    to_value_result->SetWithoutPathExpansion("printerType", std::make_unique<base::Value>(*this->printer_type));

  }
  if (this->printer_desc.get()) {
    to_value_result->SetWithoutPathExpansion("printerDesc", std::make_unique<base::Value>(*this->printer_desc));

  }
  if (this->printer_make_and_model.get()) {
    to_value_result->SetWithoutPathExpansion("printerMakeAndModel", std::make_unique<base::Value>(*this->printer_make_and_model));

  }
  if (this->printer_uri.get()) {
    to_value_result->SetWithoutPathExpansion("printerUri", std::make_unique<base::Value>(*this->printer_uri));

  }
  if (this->printer_ppd.get()) {
    to_value_result->SetWithoutPathExpansion("printerPpd", std::make_unique<base::Value>(*this->printer_ppd));

  }

  return to_value_result;
}


ArcState::ArcState()
: provisioned(false),
tos_needed(false) {}

ArcState::~ArcState() {}
ArcState::ArcState(ArcState&& rhs)
: provisioned(rhs.provisioned),
tos_needed(rhs.tos_needed){
}

ArcState& ArcState::operator=(ArcState&& rhs)
{
provisioned = rhs.provisioned;
tos_needed = rhs.tos_needed;
return *this;
}

// static
bool ArcState::Populate(
    const base::Value& value, ArcState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* provisioned_value = NULL;
  if (!dict->GetWithoutPathExpansion("provisioned", &provisioned_value)) {
    return false;
  }
  {
    if (!provisioned_value->GetAsBoolean(&out->provisioned)) {
      return false;
    }
  }

  const base::Value* tos_needed_value = NULL;
  if (!dict->GetWithoutPathExpansion("tosNeeded", &tos_needed_value)) {
    return false;
  }
  {
    if (!tos_needed_value->GetAsBoolean(&out->tos_needed)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ArcState> ArcState::FromValue(const base::Value& value) {
  std::unique_ptr<ArcState> out(new ArcState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ArcState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("provisioned", std::make_unique<base::Value>(this->provisioned));

  to_value_result->SetWithoutPathExpansion("tosNeeded", std::make_unique<base::Value>(this->tos_needed));


  return to_value_result;
}


PlayStoreState::PlayStoreState()
: allowed(false) {}

PlayStoreState::~PlayStoreState() {}
PlayStoreState::PlayStoreState(PlayStoreState&& rhs)
: allowed(rhs.allowed),
enabled(std::move(rhs.enabled)),
managed(std::move(rhs.managed)){
}

PlayStoreState& PlayStoreState::operator=(PlayStoreState&& rhs)
{
allowed = rhs.allowed;
enabled = std::move(rhs.enabled);
managed = std::move(rhs.managed);
return *this;
}

// static
bool PlayStoreState::Populate(
    const base::Value& value, PlayStoreState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* allowed_value = NULL;
  if (!dict->GetWithoutPathExpansion("allowed", &allowed_value)) {
    return false;
  }
  {
    if (!allowed_value->GetAsBoolean(&out->allowed)) {
      return false;
    }
  }

  const base::Value* enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("enabled", &enabled_value)) {
    {
      bool temp;
      if (!enabled_value->GetAsBoolean(&temp)) {
        out->enabled.reset();
        return false;
      }
      else
        out->enabled.reset(new bool(temp));
    }
  }

  const base::Value* managed_value = NULL;
  if (dict->GetWithoutPathExpansion("managed", &managed_value)) {
    {
      bool temp;
      if (!managed_value->GetAsBoolean(&temp)) {
        out->managed.reset();
        return false;
      }
      else
        out->managed.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<PlayStoreState> PlayStoreState::FromValue(const base::Value& value) {
  std::unique_ptr<PlayStoreState> out(new PlayStoreState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PlayStoreState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("allowed", std::make_unique<base::Value>(this->allowed));

  if (this->enabled.get()) {
    to_value_result->SetWithoutPathExpansion("enabled", std::make_unique<base::Value>(*this->enabled));

  }
  if (this->managed.get()) {
    to_value_result->SetWithoutPathExpansion("managed", std::make_unique<base::Value>(*this->managed));

  }

  return to_value_result;
}


AssistantQueryResponse::AssistantQueryResponse()
 {}

AssistantQueryResponse::~AssistantQueryResponse() {}
AssistantQueryResponse::AssistantQueryResponse(AssistantQueryResponse&& rhs)
: text(std::move(rhs.text)),
html_response(std::move(rhs.html_response)),
html_fallback(std::move(rhs.html_fallback)){
}

AssistantQueryResponse& AssistantQueryResponse::operator=(AssistantQueryResponse&& rhs)
{
text = std::move(rhs.text);
html_response = std::move(rhs.html_response);
html_fallback = std::move(rhs.html_fallback);
return *this;
}

// static
bool AssistantQueryResponse::Populate(
    const base::Value& value, AssistantQueryResponse* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* text_value = NULL;
  if (dict->GetWithoutPathExpansion("text", &text_value)) {
    {
      std::string temp;
      if (!text_value->GetAsString(&temp)) {
        out->text.reset();
        return false;
      }
      else
        out->text.reset(new std::string(temp));
    }
  }

  const base::Value* html_response_value = NULL;
  if (dict->GetWithoutPathExpansion("htmlResponse", &html_response_value)) {
    {
      std::string temp;
      if (!html_response_value->GetAsString(&temp)) {
        out->html_response.reset();
        return false;
      }
      else
        out->html_response.reset(new std::string(temp));
    }
  }

  const base::Value* html_fallback_value = NULL;
  if (dict->GetWithoutPathExpansion("htmlFallback", &html_fallback_value)) {
    {
      std::string temp;
      if (!html_fallback_value->GetAsString(&temp)) {
        out->html_fallback.reset();
        return false;
      }
      else
        out->html_fallback.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<AssistantQueryResponse> AssistantQueryResponse::FromValue(const base::Value& value) {
  std::unique_ptr<AssistantQueryResponse> out(new AssistantQueryResponse());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AssistantQueryResponse::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->text.get()) {
    to_value_result->SetWithoutPathExpansion("text", std::make_unique<base::Value>(*this->text));

  }
  if (this->html_response.get()) {
    to_value_result->SetWithoutPathExpansion("htmlResponse", std::make_unique<base::Value>(*this->html_response));

  }
  if (this->html_fallback.get()) {
    to_value_result->SetWithoutPathExpansion("htmlFallback", std::make_unique<base::Value>(*this->html_fallback));

  }

  return to_value_result;
}


AssistantQueryStatus::AssistantQueryStatus()
: is_mic_open(false) {}

AssistantQueryStatus::~AssistantQueryStatus() {}
AssistantQueryStatus::AssistantQueryStatus(AssistantQueryStatus&& rhs)
: is_mic_open(rhs.is_mic_open),
query_text(std::move(rhs.query_text)),
query_response(std::move(rhs.query_response)){
}

AssistantQueryStatus& AssistantQueryStatus::operator=(AssistantQueryStatus&& rhs)
{
is_mic_open = rhs.is_mic_open;
query_text = std::move(rhs.query_text);
query_response = std::move(rhs.query_response);
return *this;
}

// static
bool AssistantQueryStatus::Populate(
    const base::Value& value, AssistantQueryStatus* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* is_mic_open_value = NULL;
  if (!dict->GetWithoutPathExpansion("isMicOpen", &is_mic_open_value)) {
    return false;
  }
  {
    if (!is_mic_open_value->GetAsBoolean(&out->is_mic_open)) {
      return false;
    }
  }

  const base::Value* query_text_value = NULL;
  if (!dict->GetWithoutPathExpansion("queryText", &query_text_value)) {
    return false;
  }
  {
    if (!query_text_value->GetAsString(&out->query_text)) {
      return false;
    }
  }

  const base::Value* query_response_value = NULL;
  if (!dict->GetWithoutPathExpansion("queryResponse", &query_response_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!query_response_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!AssistantQueryResponse::Populate(*dictionary, &out->query_response)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AssistantQueryStatus> AssistantQueryStatus::FromValue(const base::Value& value) {
  std::unique_ptr<AssistantQueryStatus> out(new AssistantQueryStatus());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AssistantQueryStatus::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("isMicOpen", std::make_unique<base::Value>(this->is_mic_open));

  to_value_result->SetWithoutPathExpansion("queryText", std::make_unique<base::Value>(this->query_text));

  to_value_result->SetWithoutPathExpansion("queryResponse", (this->query_response).ToValue());


  return to_value_result;
}


ArcAppDict::ArcAppDict()
: last_launch_time(0.0),
install_time(0.0),
sticky(false),
notifications_enabled(false),
ready(false),
suspended(false),
show_in_launcher(false),
shortcut(false),
launchable(false) {}

ArcAppDict::~ArcAppDict() {}
ArcAppDict::ArcAppDict(ArcAppDict&& rhs)
: name(std::move(rhs.name)),
package_name(std::move(rhs.package_name)),
activity(std::move(rhs.activity)),
intent_uri(std::move(rhs.intent_uri)),
icon_resource_id(std::move(rhs.icon_resource_id)),
last_launch_time(rhs.last_launch_time),
install_time(rhs.install_time),
sticky(rhs.sticky),
notifications_enabled(rhs.notifications_enabled),
ready(rhs.ready),
suspended(rhs.suspended),
show_in_launcher(rhs.show_in_launcher),
shortcut(rhs.shortcut),
launchable(rhs.launchable){
}

ArcAppDict& ArcAppDict::operator=(ArcAppDict&& rhs)
{
name = std::move(rhs.name);
package_name = std::move(rhs.package_name);
activity = std::move(rhs.activity);
intent_uri = std::move(rhs.intent_uri);
icon_resource_id = std::move(rhs.icon_resource_id);
last_launch_time = rhs.last_launch_time;
install_time = rhs.install_time;
sticky = rhs.sticky;
notifications_enabled = rhs.notifications_enabled;
ready = rhs.ready;
suspended = rhs.suspended;
show_in_launcher = rhs.show_in_launcher;
shortcut = rhs.shortcut;
launchable = rhs.launchable;
return *this;
}

// static
bool ArcAppDict::Populate(
    const base::Value& value, ArcAppDict* out) {
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

  const base::Value* package_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("packageName", &package_name_value)) {
    return false;
  }
  {
    if (!package_name_value->GetAsString(&out->package_name)) {
      return false;
    }
  }

  const base::Value* activity_value = NULL;
  if (!dict->GetWithoutPathExpansion("activity", &activity_value)) {
    return false;
  }
  {
    if (!activity_value->GetAsString(&out->activity)) {
      return false;
    }
  }

  const base::Value* intent_uri_value = NULL;
  if (!dict->GetWithoutPathExpansion("intentUri", &intent_uri_value)) {
    return false;
  }
  {
    if (!intent_uri_value->GetAsString(&out->intent_uri)) {
      return false;
    }
  }

  const base::Value* icon_resource_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("iconResourceId", &icon_resource_id_value)) {
    return false;
  }
  {
    if (!icon_resource_id_value->GetAsString(&out->icon_resource_id)) {
      return false;
    }
  }

  const base::Value* last_launch_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("lastLaunchTime", &last_launch_time_value)) {
    return false;
  }
  {
    if (!last_launch_time_value->GetAsDouble(&out->last_launch_time)) {
      return false;
    }
  }

  const base::Value* install_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("installTime", &install_time_value)) {
    return false;
  }
  {
    if (!install_time_value->GetAsDouble(&out->install_time)) {
      return false;
    }
  }

  const base::Value* sticky_value = NULL;
  if (!dict->GetWithoutPathExpansion("sticky", &sticky_value)) {
    return false;
  }
  {
    if (!sticky_value->GetAsBoolean(&out->sticky)) {
      return false;
    }
  }

  const base::Value* notifications_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("notificationsEnabled", &notifications_enabled_value)) {
    return false;
  }
  {
    if (!notifications_enabled_value->GetAsBoolean(&out->notifications_enabled)) {
      return false;
    }
  }

  const base::Value* ready_value = NULL;
  if (!dict->GetWithoutPathExpansion("ready", &ready_value)) {
    return false;
  }
  {
    if (!ready_value->GetAsBoolean(&out->ready)) {
      return false;
    }
  }

  const base::Value* suspended_value = NULL;
  if (!dict->GetWithoutPathExpansion("suspended", &suspended_value)) {
    return false;
  }
  {
    if (!suspended_value->GetAsBoolean(&out->suspended)) {
      return false;
    }
  }

  const base::Value* show_in_launcher_value = NULL;
  if (!dict->GetWithoutPathExpansion("showInLauncher", &show_in_launcher_value)) {
    return false;
  }
  {
    if (!show_in_launcher_value->GetAsBoolean(&out->show_in_launcher)) {
      return false;
    }
  }

  const base::Value* shortcut_value = NULL;
  if (!dict->GetWithoutPathExpansion("shortcut", &shortcut_value)) {
    return false;
  }
  {
    if (!shortcut_value->GetAsBoolean(&out->shortcut)) {
      return false;
    }
  }

  const base::Value* launchable_value = NULL;
  if (!dict->GetWithoutPathExpansion("launchable", &launchable_value)) {
    return false;
  }
  {
    if (!launchable_value->GetAsBoolean(&out->launchable)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ArcAppDict> ArcAppDict::FromValue(const base::Value& value) {
  std::unique_ptr<ArcAppDict> out(new ArcAppDict());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ArcAppDict::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("packageName", std::make_unique<base::Value>(this->package_name));

  to_value_result->SetWithoutPathExpansion("activity", std::make_unique<base::Value>(this->activity));

  to_value_result->SetWithoutPathExpansion("intentUri", std::make_unique<base::Value>(this->intent_uri));

  to_value_result->SetWithoutPathExpansion("iconResourceId", std::make_unique<base::Value>(this->icon_resource_id));

  to_value_result->SetWithoutPathExpansion("lastLaunchTime", std::make_unique<base::Value>(this->last_launch_time));

  to_value_result->SetWithoutPathExpansion("installTime", std::make_unique<base::Value>(this->install_time));

  to_value_result->SetWithoutPathExpansion("sticky", std::make_unique<base::Value>(this->sticky));

  to_value_result->SetWithoutPathExpansion("notificationsEnabled", std::make_unique<base::Value>(this->notifications_enabled));

  to_value_result->SetWithoutPathExpansion("ready", std::make_unique<base::Value>(this->ready));

  to_value_result->SetWithoutPathExpansion("suspended", std::make_unique<base::Value>(this->suspended));

  to_value_result->SetWithoutPathExpansion("showInLauncher", std::make_unique<base::Value>(this->show_in_launcher));

  to_value_result->SetWithoutPathExpansion("shortcut", std::make_unique<base::Value>(this->shortcut));

  to_value_result->SetWithoutPathExpansion("launchable", std::make_unique<base::Value>(this->launchable));


  return to_value_result;
}


ArcPackageDict::ArcPackageDict()
: package_version(0),
last_backup_time(0.0),
should_sync(false),
system(false),
vpn_provider(false) {}

ArcPackageDict::~ArcPackageDict() {}
ArcPackageDict::ArcPackageDict(ArcPackageDict&& rhs)
: package_name(std::move(rhs.package_name)),
package_version(rhs.package_version),
last_backup_android_id(std::move(rhs.last_backup_android_id)),
last_backup_time(rhs.last_backup_time),
should_sync(rhs.should_sync),
system(rhs.system),
vpn_provider(rhs.vpn_provider){
}

ArcPackageDict& ArcPackageDict::operator=(ArcPackageDict&& rhs)
{
package_name = std::move(rhs.package_name);
package_version = rhs.package_version;
last_backup_android_id = std::move(rhs.last_backup_android_id);
last_backup_time = rhs.last_backup_time;
should_sync = rhs.should_sync;
system = rhs.system;
vpn_provider = rhs.vpn_provider;
return *this;
}

// static
bool ArcPackageDict::Populate(
    const base::Value& value, ArcPackageDict* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* package_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("packageName", &package_name_value)) {
    return false;
  }
  {
    if (!package_name_value->GetAsString(&out->package_name)) {
      return false;
    }
  }

  const base::Value* package_version_value = NULL;
  if (!dict->GetWithoutPathExpansion("packageVersion", &package_version_value)) {
    return false;
  }
  {
    if (!package_version_value->GetAsInteger(&out->package_version)) {
      return false;
    }
  }

  const base::Value* last_backup_android_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("lastBackupAndroidId", &last_backup_android_id_value)) {
    return false;
  }
  {
    if (!last_backup_android_id_value->GetAsString(&out->last_backup_android_id)) {
      return false;
    }
  }

  const base::Value* last_backup_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("lastBackupTime", &last_backup_time_value)) {
    return false;
  }
  {
    if (!last_backup_time_value->GetAsDouble(&out->last_backup_time)) {
      return false;
    }
  }

  const base::Value* should_sync_value = NULL;
  if (!dict->GetWithoutPathExpansion("shouldSync", &should_sync_value)) {
    return false;
  }
  {
    if (!should_sync_value->GetAsBoolean(&out->should_sync)) {
      return false;
    }
  }

  const base::Value* system_value = NULL;
  if (!dict->GetWithoutPathExpansion("system", &system_value)) {
    return false;
  }
  {
    if (!system_value->GetAsBoolean(&out->system)) {
      return false;
    }
  }

  const base::Value* vpn_provider_value = NULL;
  if (!dict->GetWithoutPathExpansion("vpnProvider", &vpn_provider_value)) {
    return false;
  }
  {
    if (!vpn_provider_value->GetAsBoolean(&out->vpn_provider)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ArcPackageDict> ArcPackageDict::FromValue(const base::Value& value) {
  std::unique_ptr<ArcPackageDict> out(new ArcPackageDict());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ArcPackageDict::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("packageName", std::make_unique<base::Value>(this->package_name));

  to_value_result->SetWithoutPathExpansion("packageVersion", std::make_unique<base::Value>(this->package_version));

  to_value_result->SetWithoutPathExpansion("lastBackupAndroidId", std::make_unique<base::Value>(this->last_backup_android_id));

  to_value_result->SetWithoutPathExpansion("lastBackupTime", std::make_unique<base::Value>(this->last_backup_time));

  to_value_result->SetWithoutPathExpansion("shouldSync", std::make_unique<base::Value>(this->should_sync));

  to_value_result->SetWithoutPathExpansion("system", std::make_unique<base::Value>(this->system));

  to_value_result->SetWithoutPathExpansion("vpnProvider", std::make_unique<base::Value>(this->vpn_provider));


  return to_value_result;
}


Location::Location()
: x(0.0),
y(0.0) {}

Location::~Location() {}
Location::Location(Location&& rhs)
: x(rhs.x),
y(rhs.y){
}

Location& Location::operator=(Location&& rhs)
{
x = rhs.x;
y = rhs.y;
return *this;
}

// static
bool Location::Populate(
    const base::Value& value, Location* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* x_value = NULL;
  if (!dict->GetWithoutPathExpansion("x", &x_value)) {
    return false;
  }
  {
    if (!x_value->GetAsDouble(&out->x)) {
      return false;
    }
  }

  const base::Value* y_value = NULL;
  if (!dict->GetWithoutPathExpansion("y", &y_value)) {
    return false;
  }
  {
    if (!y_value->GetAsDouble(&out->y)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Location> Location::FromValue(const base::Value& value) {
  std::unique_ptr<Location> out(new Location());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Location::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("x", std::make_unique<base::Value>(this->x));

  to_value_result->SetWithoutPathExpansion("y", std::make_unique<base::Value>(this->y));


  return to_value_result;
}


Bounds::Bounds()
: left(0.0),
top(0.0),
width(0.0),
height(0.0) {}

Bounds::~Bounds() {}
Bounds::Bounds(Bounds&& rhs)
: left(rhs.left),
top(rhs.top),
width(rhs.width),
height(rhs.height){
}

Bounds& Bounds::operator=(Bounds&& rhs)
{
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
return *this;
}

// static
bool Bounds::Populate(
    const base::Value& value, Bounds* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* left_value = NULL;
  if (!dict->GetWithoutPathExpansion("left", &left_value)) {
    return false;
  }
  {
    if (!left_value->GetAsDouble(&out->left)) {
      return false;
    }
  }

  const base::Value* top_value = NULL;
  if (!dict->GetWithoutPathExpansion("top", &top_value)) {
    return false;
  }
  {
    if (!top_value->GetAsDouble(&out->top)) {
      return false;
    }
  }

  const base::Value* width_value = NULL;
  if (!dict->GetWithoutPathExpansion("width", &width_value)) {
    return false;
  }
  {
    if (!width_value->GetAsDouble(&out->width)) {
      return false;
    }
  }

  const base::Value* height_value = NULL;
  if (!dict->GetWithoutPathExpansion("height", &height_value)) {
    return false;
  }
  {
    if (!height_value->GetAsDouble(&out->height)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Bounds> Bounds::FromValue(const base::Value& value) {
  std::unique_ptr<Bounds> out(new Bounds());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Bounds::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));


  return to_value_result;
}


ArcAppTracingInfo::ArcAppTracingInfo()
: success(false),
fps(0.0),
commit_deviation(0.0),
render_quality(0.0) {}

ArcAppTracingInfo::~ArcAppTracingInfo() {}
ArcAppTracingInfo::ArcAppTracingInfo(ArcAppTracingInfo&& rhs)
: success(rhs.success),
fps(rhs.fps),
commit_deviation(rhs.commit_deviation),
render_quality(rhs.render_quality){
}

ArcAppTracingInfo& ArcAppTracingInfo::operator=(ArcAppTracingInfo&& rhs)
{
success = rhs.success;
fps = rhs.fps;
commit_deviation = rhs.commit_deviation;
render_quality = rhs.render_quality;
return *this;
}

// static
bool ArcAppTracingInfo::Populate(
    const base::Value& value, ArcAppTracingInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* success_value = NULL;
  if (!dict->GetWithoutPathExpansion("success", &success_value)) {
    return false;
  }
  {
    if (!success_value->GetAsBoolean(&out->success)) {
      return false;
    }
  }

  const base::Value* fps_value = NULL;
  if (!dict->GetWithoutPathExpansion("fps", &fps_value)) {
    return false;
  }
  {
    if (!fps_value->GetAsDouble(&out->fps)) {
      return false;
    }
  }

  const base::Value* commit_deviation_value = NULL;
  if (!dict->GetWithoutPathExpansion("commitDeviation", &commit_deviation_value)) {
    return false;
  }
  {
    if (!commit_deviation_value->GetAsDouble(&out->commit_deviation)) {
      return false;
    }
  }

  const base::Value* render_quality_value = NULL;
  if (!dict->GetWithoutPathExpansion("renderQuality", &render_quality_value)) {
    return false;
  }
  {
    if (!render_quality_value->GetAsDouble(&out->render_quality)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ArcAppTracingInfo> ArcAppTracingInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ArcAppTracingInfo> out(new ArcAppTracingInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ArcAppTracingInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("success", std::make_unique<base::Value>(this->success));

  to_value_result->SetWithoutPathExpansion("fps", std::make_unique<base::Value>(this->fps));

  to_value_result->SetWithoutPathExpansion("commitDeviation", std::make_unique<base::Value>(this->commit_deviation));

  to_value_result->SetWithoutPathExpansion("renderQuality", std::make_unique<base::Value>(this->render_quality));


  return to_value_result;
}


App::App()
: type(APP_TYPE_NONE),
readiness(APP_READINESS_NONE) {}

App::~App() {}
App::App(App&& rhs)
: app_id(std::move(rhs.app_id)),
name(std::move(rhs.name)),
short_name(std::move(rhs.short_name)),
type(rhs.type),
readiness(rhs.readiness),
additional_search_terms(std::move(rhs.additional_search_terms)),
show_in_launcher(std::move(rhs.show_in_launcher)),
show_in_search(std::move(rhs.show_in_search)){
}

App& App::operator=(App&& rhs)
{
app_id = std::move(rhs.app_id);
name = std::move(rhs.name);
short_name = std::move(rhs.short_name);
type = rhs.type;
readiness = rhs.readiness;
additional_search_terms = std::move(rhs.additional_search_terms);
show_in_launcher = std::move(rhs.show_in_launcher);
show_in_search = std::move(rhs.show_in_search);
return *this;
}

// static
bool App::Populate(
    const base::Value& value, App* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = APP_TYPE_NONE;
  out->readiness = APP_READINESS_NONE;
  const base::Value* app_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("appId", &app_id_value)) {
    return false;
  }
  {
    if (!app_id_value->GetAsString(&out->app_id)) {
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

  const base::Value* short_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("shortName", &short_name_value)) {
    return false;
  }
  {
    if (!short_name_value->GetAsString(&out->short_name)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string app_type_as_string;
      if (!type_value->GetAsString(&app_type_as_string)) {
        return false;
      }
      out->type = ParseAppType(app_type_as_string);
      if (out->type == APP_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = APP_TYPE_NONE;
  }

  const base::Value* readiness_value = NULL;
  if (dict->GetWithoutPathExpansion("readiness", &readiness_value)) {
    {
      std::string app_readiness_as_string;
      if (!readiness_value->GetAsString(&app_readiness_as_string)) {
        return false;
      }
      out->readiness = ParseAppReadiness(app_readiness_as_string);
      if (out->readiness == APP_READINESS_NONE) {
        return false;
      }
    }
    } else {
    out->readiness = APP_READINESS_NONE;
  }

  const base::Value* additional_search_terms_value = NULL;
  if (!dict->GetWithoutPathExpansion("additionalSearchTerms", &additional_search_terms_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!additional_search_terms_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->additional_search_terms)) {
        return false;
      }
    }
  }

  const base::Value* show_in_launcher_value = NULL;
  if (dict->GetWithoutPathExpansion("showInLauncher", &show_in_launcher_value)) {
    {
      bool temp;
      if (!show_in_launcher_value->GetAsBoolean(&temp)) {
        out->show_in_launcher.reset();
        return false;
      }
      else
        out->show_in_launcher.reset(new bool(temp));
    }
  }

  const base::Value* show_in_search_value = NULL;
  if (dict->GetWithoutPathExpansion("showInSearch", &show_in_search_value)) {
    {
      bool temp;
      if (!show_in_search_value->GetAsBoolean(&temp)) {
        out->show_in_search.reset();
        return false;
      }
      else
        out->show_in_search.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<App> App::FromValue(const base::Value& value) {
  std::unique_ptr<App> out(new App());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> App::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("appId", std::make_unique<base::Value>(this->app_id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("shortName", std::make_unique<base::Value>(this->short_name));

  if (this->type != APP_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(autotest_private::ToString(this->type)));

  }
  if (this->readiness != APP_READINESS_NONE) {
    to_value_result->SetWithoutPathExpansion("readiness", std::make_unique<base::Value>(autotest_private::ToString(this->readiness)));

  }
  to_value_result->SetWithoutPathExpansion("additionalSearchTerms", json_schema_compiler::util::CreateValueFromArray(this->additional_search_terms));

  if (this->show_in_launcher.get()) {
    to_value_result->SetWithoutPathExpansion("showInLauncher", std::make_unique<base::Value>(*this->show_in_launcher));

  }
  if (this->show_in_search.get()) {
    to_value_result->SetWithoutPathExpansion("showInSearch", std::make_unique<base::Value>(*this->show_in_search));

  }

  return to_value_result;
}


ShelfItem::ShelfItem()
: type(SHELF_ITEM_TYPE_NONE),
status(SHELF_ITEM_STATUS_NONE),
shows_tooltip(false),
pinned_by_policy(false),
has_notification(false) {}

ShelfItem::~ShelfItem() {}
ShelfItem::ShelfItem(ShelfItem&& rhs)
: app_id(std::move(rhs.app_id)),
launch_id(std::move(rhs.launch_id)),
title(std::move(rhs.title)),
type(rhs.type),
status(rhs.status),
shows_tooltip(rhs.shows_tooltip),
pinned_by_policy(rhs.pinned_by_policy),
has_notification(rhs.has_notification){
}

ShelfItem& ShelfItem::operator=(ShelfItem&& rhs)
{
app_id = std::move(rhs.app_id);
launch_id = std::move(rhs.launch_id);
title = std::move(rhs.title);
type = rhs.type;
status = rhs.status;
shows_tooltip = rhs.shows_tooltip;
pinned_by_policy = rhs.pinned_by_policy;
has_notification = rhs.has_notification;
return *this;
}

// static
bool ShelfItem::Populate(
    const base::Value& value, ShelfItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = SHELF_ITEM_TYPE_NONE;
  const base::Value* app_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("appId", &app_id_value)) {
    return false;
  }
  {
    if (!app_id_value->GetAsString(&out->app_id)) {
      return false;
    }
  }

  const base::Value* launch_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("launchId", &launch_id_value)) {
    return false;
  }
  {
    if (!launch_id_value->GetAsString(&out->launch_id)) {
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

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string shelf_item_type_as_string;
      if (!type_value->GetAsString(&shelf_item_type_as_string)) {
        return false;
      }
      out->type = ParseShelfItemType(shelf_item_type_as_string);
      if (out->type == SHELF_ITEM_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = SHELF_ITEM_TYPE_NONE;
  }

  const base::Value* status_value = NULL;
  if (!dict->GetWithoutPathExpansion("status", &status_value)) {
    return false;
  }
  {
    std::string shelf_item_status_as_string;
    if (!status_value->GetAsString(&shelf_item_status_as_string)) {
      return false;
    }
    out->status = ParseShelfItemStatus(shelf_item_status_as_string);
    if (out->status == SHELF_ITEM_STATUS_NONE) {
      return false;
    }
  }

  const base::Value* shows_tooltip_value = NULL;
  if (!dict->GetWithoutPathExpansion("showsTooltip", &shows_tooltip_value)) {
    return false;
  }
  {
    if (!shows_tooltip_value->GetAsBoolean(&out->shows_tooltip)) {
      return false;
    }
  }

  const base::Value* pinned_by_policy_value = NULL;
  if (!dict->GetWithoutPathExpansion("pinnedByPolicy", &pinned_by_policy_value)) {
    return false;
  }
  {
    if (!pinned_by_policy_value->GetAsBoolean(&out->pinned_by_policy)) {
      return false;
    }
  }

  const base::Value* has_notification_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasNotification", &has_notification_value)) {
    return false;
  }
  {
    if (!has_notification_value->GetAsBoolean(&out->has_notification)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ShelfItem> ShelfItem::FromValue(const base::Value& value) {
  std::unique_ptr<ShelfItem> out(new ShelfItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ShelfItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("appId", std::make_unique<base::Value>(this->app_id));

  to_value_result->SetWithoutPathExpansion("launchId", std::make_unique<base::Value>(this->launch_id));

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  if (this->type != SHELF_ITEM_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(autotest_private::ToString(this->type)));

  }
  to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(autotest_private::ToString(this->status)));

  to_value_result->SetWithoutPathExpansion("showsTooltip", std::make_unique<base::Value>(this->shows_tooltip));

  to_value_result->SetWithoutPathExpansion("pinnedByPolicy", std::make_unique<base::Value>(this->pinned_by_policy));

  to_value_result->SetWithoutPathExpansion("hasNotification", std::make_unique<base::Value>(this->has_notification));


  return to_value_result;
}


const char* ToString(AppWindowType enum_param) {
  switch (enum_param) {
    case APP_WINDOW_TYPE_BROWSER:
      return "Browser";
    case APP_WINDOW_TYPE_CHROMEAPP:
      return "ChromeApp";
    case APP_WINDOW_TYPE_ARCAPP:
      return "ArcApp";
    case APP_WINDOW_TYPE_CROSTINIAPP:
      return "CrostiniApp";
    case APP_WINDOW_TYPE_SYSTEMAPP:
      return "SystemApp";
    case APP_WINDOW_TYPE_EXTENSIONAPP:
      return "ExtensionApp";
    case APP_WINDOW_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

AppWindowType ParseAppWindowType(const std::string& enum_string) {
  if (enum_string == "Browser")
    return APP_WINDOW_TYPE_BROWSER;
  if (enum_string == "ChromeApp")
    return APP_WINDOW_TYPE_CHROMEAPP;
  if (enum_string == "ArcApp")
    return APP_WINDOW_TYPE_ARCAPP;
  if (enum_string == "CrostiniApp")
    return APP_WINDOW_TYPE_CROSTINIAPP;
  if (enum_string == "SystemApp")
    return APP_WINDOW_TYPE_SYSTEMAPP;
  if (enum_string == "ExtensionApp")
    return APP_WINDOW_TYPE_EXTENSIONAPP;
  return APP_WINDOW_TYPE_NONE;
}


const char* ToString(HotseatState enum_param) {
  switch (enum_param) {
    case HOTSEAT_STATE_HIDDEN:
      return "Hidden";
    case HOTSEAT_STATE_SHOWNCLAMSHELL:
      return "ShownClamShell";
    case HOTSEAT_STATE_SHOWNHOMELAUNCHER:
      return "ShownHomeLauncher";
    case HOTSEAT_STATE_EXTENDED:
      return "Extended";
    case HOTSEAT_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

HotseatState ParseHotseatState(const std::string& enum_string) {
  if (enum_string == "Hidden")
    return HOTSEAT_STATE_HIDDEN;
  if (enum_string == "ShownClamShell")
    return HOTSEAT_STATE_SHOWNCLAMSHELL;
  if (enum_string == "ShownHomeLauncher")
    return HOTSEAT_STATE_SHOWNHOMELAUNCHER;
  if (enum_string == "Extended")
    return HOTSEAT_STATE_EXTENDED;
  return HOTSEAT_STATE_NONE;
}


const char* ToString(FrameMode enum_param) {
  switch (enum_param) {
    case FRAME_MODE_NORMAL:
      return "Normal";
    case FRAME_MODE_IMMERSIVE:
      return "Immersive";
    case FRAME_MODE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FrameMode ParseFrameMode(const std::string& enum_string) {
  if (enum_string == "Normal")
    return FRAME_MODE_NORMAL;
  if (enum_string == "Immersive")
    return FRAME_MODE_IMMERSIVE;
  return FRAME_MODE_NONE;
}


OverviewInfo::OverviewInfo()
: is_dragged(false) {}

OverviewInfo::~OverviewInfo() {}
OverviewInfo::OverviewInfo(OverviewInfo&& rhs)
: bounds(std::move(rhs.bounds)),
is_dragged(rhs.is_dragged){
}

OverviewInfo& OverviewInfo::operator=(OverviewInfo&& rhs)
{
bounds = std::move(rhs.bounds);
is_dragged = rhs.is_dragged;
return *this;
}

// static
bool OverviewInfo::Populate(
    const base::Value& value, OverviewInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("bounds", &bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->bounds)) {
      return false;
    }
  }

  const base::Value* is_dragged_value = NULL;
  if (!dict->GetWithoutPathExpansion("isDragged", &is_dragged_value)) {
    return false;
  }
  {
    if (!is_dragged_value->GetAsBoolean(&out->is_dragged)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<OverviewInfo> OverviewInfo::FromValue(const base::Value& value) {
  std::unique_ptr<OverviewInfo> out(new OverviewInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OverviewInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("bounds", (this->bounds).ToValue());

  to_value_result->SetWithoutPathExpansion("isDragged", std::make_unique<base::Value>(this->is_dragged));


  return to_value_result;
}


AppWindowInfo::AppWindowInfo()
: id(0),
window_type(APP_WINDOW_TYPE_NONE),
state_type(WINDOW_STATE_TYPE_NONE),
is_visible(false),
can_focus(false),
is_animating(false),
target_visibility(false),
is_active(false),
has_focus(false),
on_active_desk(false),
has_capture(false),
can_resize(false),
frame_mode(FRAME_MODE_NONE),
is_frame_visible(false),
caption_height(0),
caption_button_enabled_status(0),
caption_button_visible_status(0) {}

AppWindowInfo::~AppWindowInfo() {}
AppWindowInfo::AppWindowInfo(AppWindowInfo&& rhs)
: id(rhs.id),
name(std::move(rhs.name)),
window_type(rhs.window_type),
state_type(rhs.state_type),
bounds_in_root(std::move(rhs.bounds_in_root)),
display_id(std::move(rhs.display_id)),
is_visible(rhs.is_visible),
can_focus(rhs.can_focus),
title(std::move(rhs.title)),
is_animating(rhs.is_animating),
target_bounds(std::move(rhs.target_bounds)),
target_visibility(rhs.target_visibility),
is_active(rhs.is_active),
has_focus(rhs.has_focus),
on_active_desk(rhs.on_active_desk),
has_capture(rhs.has_capture),
can_resize(rhs.can_resize),
frame_mode(rhs.frame_mode),
is_frame_visible(rhs.is_frame_visible),
caption_height(rhs.caption_height),
caption_button_enabled_status(rhs.caption_button_enabled_status),
caption_button_visible_status(rhs.caption_button_visible_status),
arc_package_name(std::move(rhs.arc_package_name)),
overview_info(std::move(rhs.overview_info)){
}

AppWindowInfo& AppWindowInfo::operator=(AppWindowInfo&& rhs)
{
id = rhs.id;
name = std::move(rhs.name);
window_type = rhs.window_type;
state_type = rhs.state_type;
bounds_in_root = std::move(rhs.bounds_in_root);
display_id = std::move(rhs.display_id);
is_visible = rhs.is_visible;
can_focus = rhs.can_focus;
title = std::move(rhs.title);
is_animating = rhs.is_animating;
target_bounds = std::move(rhs.target_bounds);
target_visibility = rhs.target_visibility;
is_active = rhs.is_active;
has_focus = rhs.has_focus;
on_active_desk = rhs.on_active_desk;
has_capture = rhs.has_capture;
can_resize = rhs.can_resize;
frame_mode = rhs.frame_mode;
is_frame_visible = rhs.is_frame_visible;
caption_height = rhs.caption_height;
caption_button_enabled_status = rhs.caption_button_enabled_status;
caption_button_visible_status = rhs.caption_button_visible_status;
arc_package_name = std::move(rhs.arc_package_name);
overview_info = std::move(rhs.overview_info);
return *this;
}

// static
bool AppWindowInfo::Populate(
    const base::Value& value, AppWindowInfo* out) {
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

  const base::Value* window_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("windowType", &window_type_value)) {
    return false;
  }
  {
    std::string app_window_type_as_string;
    if (!window_type_value->GetAsString(&app_window_type_as_string)) {
      return false;
    }
    out->window_type = ParseAppWindowType(app_window_type_as_string);
    if (out->window_type == APP_WINDOW_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* state_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("stateType", &state_type_value)) {
    return false;
  }
  {
    std::string window_state_type_as_string;
    if (!state_type_value->GetAsString(&window_state_type_as_string)) {
      return false;
    }
    out->state_type = ParseWindowStateType(window_state_type_as_string);
    if (out->state_type == WINDOW_STATE_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* bounds_in_root_value = NULL;
  if (!dict->GetWithoutPathExpansion("boundsInRoot", &bounds_in_root_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!bounds_in_root_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->bounds_in_root)) {
      return false;
    }
  }

  const base::Value* display_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayId", &display_id_value)) {
    return false;
  }
  {
    if (!display_id_value->GetAsString(&out->display_id)) {
      return false;
    }
  }

  const base::Value* is_visible_value = NULL;
  if (!dict->GetWithoutPathExpansion("isVisible", &is_visible_value)) {
    return false;
  }
  {
    if (!is_visible_value->GetAsBoolean(&out->is_visible)) {
      return false;
    }
  }

  const base::Value* can_focus_value = NULL;
  if (!dict->GetWithoutPathExpansion("canFocus", &can_focus_value)) {
    return false;
  }
  {
    if (!can_focus_value->GetAsBoolean(&out->can_focus)) {
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

  const base::Value* is_animating_value = NULL;
  if (!dict->GetWithoutPathExpansion("isAnimating", &is_animating_value)) {
    return false;
  }
  {
    if (!is_animating_value->GetAsBoolean(&out->is_animating)) {
      return false;
    }
  }

  const base::Value* target_bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("targetBounds", &target_bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!target_bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->target_bounds)) {
      return false;
    }
  }

  const base::Value* target_visibility_value = NULL;
  if (!dict->GetWithoutPathExpansion("targetVisibility", &target_visibility_value)) {
    return false;
  }
  {
    if (!target_visibility_value->GetAsBoolean(&out->target_visibility)) {
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

  const base::Value* has_focus_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasFocus", &has_focus_value)) {
    return false;
  }
  {
    if (!has_focus_value->GetAsBoolean(&out->has_focus)) {
      return false;
    }
  }

  const base::Value* on_active_desk_value = NULL;
  if (!dict->GetWithoutPathExpansion("onActiveDesk", &on_active_desk_value)) {
    return false;
  }
  {
    if (!on_active_desk_value->GetAsBoolean(&out->on_active_desk)) {
      return false;
    }
  }

  const base::Value* has_capture_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasCapture", &has_capture_value)) {
    return false;
  }
  {
    if (!has_capture_value->GetAsBoolean(&out->has_capture)) {
      return false;
    }
  }

  const base::Value* can_resize_value = NULL;
  if (!dict->GetWithoutPathExpansion("canResize", &can_resize_value)) {
    return false;
  }
  {
    if (!can_resize_value->GetAsBoolean(&out->can_resize)) {
      return false;
    }
  }

  const base::Value* frame_mode_value = NULL;
  if (!dict->GetWithoutPathExpansion("frameMode", &frame_mode_value)) {
    return false;
  }
  {
    std::string frame_mode_as_string;
    if (!frame_mode_value->GetAsString(&frame_mode_as_string)) {
      return false;
    }
    out->frame_mode = ParseFrameMode(frame_mode_as_string);
    if (out->frame_mode == FRAME_MODE_NONE) {
      return false;
    }
  }

  const base::Value* is_frame_visible_value = NULL;
  if (!dict->GetWithoutPathExpansion("isFrameVisible", &is_frame_visible_value)) {
    return false;
  }
  {
    if (!is_frame_visible_value->GetAsBoolean(&out->is_frame_visible)) {
      return false;
    }
  }

  const base::Value* caption_height_value = NULL;
  if (!dict->GetWithoutPathExpansion("captionHeight", &caption_height_value)) {
    return false;
  }
  {
    if (!caption_height_value->GetAsInteger(&out->caption_height)) {
      return false;
    }
  }

  const base::Value* caption_button_enabled_status_value = NULL;
  if (!dict->GetWithoutPathExpansion("captionButtonEnabledStatus", &caption_button_enabled_status_value)) {
    return false;
  }
  {
    if (!caption_button_enabled_status_value->GetAsInteger(&out->caption_button_enabled_status)) {
      return false;
    }
  }

  const base::Value* caption_button_visible_status_value = NULL;
  if (!dict->GetWithoutPathExpansion("captionButtonVisibleStatus", &caption_button_visible_status_value)) {
    return false;
  }
  {
    if (!caption_button_visible_status_value->GetAsInteger(&out->caption_button_visible_status)) {
      return false;
    }
  }

  const base::Value* arc_package_name_value = NULL;
  if (dict->GetWithoutPathExpansion("arcPackageName", &arc_package_name_value)) {
    {
      std::string temp;
      if (!arc_package_name_value->GetAsString(&temp)) {
        out->arc_package_name.reset();
        return false;
      }
      else
        out->arc_package_name.reset(new std::string(temp));
    }
  }

  const base::Value* overview_info_value = NULL;
  if (dict->GetWithoutPathExpansion("overviewInfo", &overview_info_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!overview_info_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<OverviewInfo> temp(new OverviewInfo());
        if (!OverviewInfo::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->overview_info = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<AppWindowInfo> AppWindowInfo::FromValue(const base::Value& value) {
  std::unique_ptr<AppWindowInfo> out(new AppWindowInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AppWindowInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("windowType", std::make_unique<base::Value>(autotest_private::ToString(this->window_type)));

  to_value_result->SetWithoutPathExpansion("stateType", std::make_unique<base::Value>(autotest_private::ToString(this->state_type)));

  to_value_result->SetWithoutPathExpansion("boundsInRoot", (this->bounds_in_root).ToValue());

  to_value_result->SetWithoutPathExpansion("displayId", std::make_unique<base::Value>(this->display_id));

  to_value_result->SetWithoutPathExpansion("isVisible", std::make_unique<base::Value>(this->is_visible));

  to_value_result->SetWithoutPathExpansion("canFocus", std::make_unique<base::Value>(this->can_focus));

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  to_value_result->SetWithoutPathExpansion("isAnimating", std::make_unique<base::Value>(this->is_animating));

  to_value_result->SetWithoutPathExpansion("targetBounds", (this->target_bounds).ToValue());

  to_value_result->SetWithoutPathExpansion("targetVisibility", std::make_unique<base::Value>(this->target_visibility));

  to_value_result->SetWithoutPathExpansion("isActive", std::make_unique<base::Value>(this->is_active));

  to_value_result->SetWithoutPathExpansion("hasFocus", std::make_unique<base::Value>(this->has_focus));

  to_value_result->SetWithoutPathExpansion("onActiveDesk", std::make_unique<base::Value>(this->on_active_desk));

  to_value_result->SetWithoutPathExpansion("hasCapture", std::make_unique<base::Value>(this->has_capture));

  to_value_result->SetWithoutPathExpansion("canResize", std::make_unique<base::Value>(this->can_resize));

  to_value_result->SetWithoutPathExpansion("frameMode", std::make_unique<base::Value>(autotest_private::ToString(this->frame_mode)));

  to_value_result->SetWithoutPathExpansion("isFrameVisible", std::make_unique<base::Value>(this->is_frame_visible));

  to_value_result->SetWithoutPathExpansion("captionHeight", std::make_unique<base::Value>(this->caption_height));

  to_value_result->SetWithoutPathExpansion("captionButtonEnabledStatus", std::make_unique<base::Value>(this->caption_button_enabled_status));

  to_value_result->SetWithoutPathExpansion("captionButtonVisibleStatus", std::make_unique<base::Value>(this->caption_button_visible_status));

  if (this->arc_package_name.get()) {
    to_value_result->SetWithoutPathExpansion("arcPackageName", std::make_unique<base::Value>(*this->arc_package_name));

  }
  if (this->overview_info.get()) {
    to_value_result->SetWithoutPathExpansion("overviewInfo", (this->overview_info)->ToValue());

  }

  return to_value_result;
}


Accelerator::Accelerator()
: shift(false),
control(false),
alt(false),
search(false),
pressed(false) {}

Accelerator::~Accelerator() {}
Accelerator::Accelerator(Accelerator&& rhs)
: key_code(std::move(rhs.key_code)),
shift(rhs.shift),
control(rhs.control),
alt(rhs.alt),
search(rhs.search),
pressed(rhs.pressed){
}

Accelerator& Accelerator::operator=(Accelerator&& rhs)
{
key_code = std::move(rhs.key_code);
shift = rhs.shift;
control = rhs.control;
alt = rhs.alt;
search = rhs.search;
pressed = rhs.pressed;
return *this;
}

// static
bool Accelerator::Populate(
    const base::Value& value, Accelerator* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* key_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("keyCode", &key_code_value)) {
    return false;
  }
  {
    if (!key_code_value->GetAsString(&out->key_code)) {
      return false;
    }
  }

  const base::Value* shift_value = NULL;
  if (!dict->GetWithoutPathExpansion("shift", &shift_value)) {
    return false;
  }
  {
    if (!shift_value->GetAsBoolean(&out->shift)) {
      return false;
    }
  }

  const base::Value* control_value = NULL;
  if (!dict->GetWithoutPathExpansion("control", &control_value)) {
    return false;
  }
  {
    if (!control_value->GetAsBoolean(&out->control)) {
      return false;
    }
  }

  const base::Value* alt_value = NULL;
  if (!dict->GetWithoutPathExpansion("alt", &alt_value)) {
    return false;
  }
  {
    if (!alt_value->GetAsBoolean(&out->alt)) {
      return false;
    }
  }

  const base::Value* search_value = NULL;
  if (!dict->GetWithoutPathExpansion("search", &search_value)) {
    return false;
  }
  {
    if (!search_value->GetAsBoolean(&out->search)) {
      return false;
    }
  }

  const base::Value* pressed_value = NULL;
  if (!dict->GetWithoutPathExpansion("pressed", &pressed_value)) {
    return false;
  }
  {
    if (!pressed_value->GetAsBoolean(&out->pressed)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Accelerator> Accelerator::FromValue(const base::Value& value) {
  std::unique_ptr<Accelerator> out(new Accelerator());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Accelerator::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("keyCode", std::make_unique<base::Value>(this->key_code));

  to_value_result->SetWithoutPathExpansion("shift", std::make_unique<base::Value>(this->shift));

  to_value_result->SetWithoutPathExpansion("control", std::make_unique<base::Value>(this->control));

  to_value_result->SetWithoutPathExpansion("alt", std::make_unique<base::Value>(this->alt));

  to_value_result->SetWithoutPathExpansion("search", std::make_unique<base::Value>(this->search));

  to_value_result->SetWithoutPathExpansion("pressed", std::make_unique<base::Value>(this->pressed));


  return to_value_result;
}


ScrollableShelfState::ScrollableShelfState()
 {}

ScrollableShelfState::~ScrollableShelfState() {}
ScrollableShelfState::ScrollableShelfState(ScrollableShelfState&& rhs)
: scroll_distance(std::move(rhs.scroll_distance)){
}

ScrollableShelfState& ScrollableShelfState::operator=(ScrollableShelfState&& rhs)
{
scroll_distance = std::move(rhs.scroll_distance);
return *this;
}

// static
bool ScrollableShelfState::Populate(
    const base::Value& value, ScrollableShelfState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* scroll_distance_value = NULL;
  if (dict->GetWithoutPathExpansion("scrollDistance", &scroll_distance_value)) {
    {
      double temp;
      if (!scroll_distance_value->GetAsDouble(&temp)) {
        out->scroll_distance.reset();
        return false;
      }
      else
        out->scroll_distance.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ScrollableShelfState> ScrollableShelfState::FromValue(const base::Value& value) {
  std::unique_ptr<ScrollableShelfState> out(new ScrollableShelfState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ScrollableShelfState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->scroll_distance.get()) {
    to_value_result->SetWithoutPathExpansion("scrollDistance", std::make_unique<base::Value>(*this->scroll_distance));

  }

  return to_value_result;
}


ShelfState::ShelfState()
 {}

ShelfState::~ShelfState() {}
ShelfState::ShelfState(ShelfState&& rhs)
: scroll_distance(std::move(rhs.scroll_distance)){
}

ShelfState& ShelfState::operator=(ShelfState&& rhs)
{
scroll_distance = std::move(rhs.scroll_distance);
return *this;
}

// static
bool ShelfState::Populate(
    const base::Value& value, ShelfState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* scroll_distance_value = NULL;
  if (dict->GetWithoutPathExpansion("scrollDistance", &scroll_distance_value)) {
    {
      double temp;
      if (!scroll_distance_value->GetAsDouble(&temp)) {
        out->scroll_distance.reset();
        return false;
      }
      else
        out->scroll_distance.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ShelfState> ShelfState::FromValue(const base::Value& value) {
  std::unique_ptr<ShelfState> out(new ShelfState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ShelfState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->scroll_distance.get()) {
    to_value_result->SetWithoutPathExpansion("scrollDistance", std::make_unique<base::Value>(*this->scroll_distance));

  }

  return to_value_result;
}


ScrollableShelfInfo::ScrollableShelfInfo()
: main_axis_offset(0.0),
page_offset(0.0),
is_animating(false),
is_overflow(false),
is_shelf_widget_animating(false) {}

ScrollableShelfInfo::~ScrollableShelfInfo() {}
ScrollableShelfInfo::ScrollableShelfInfo(ScrollableShelfInfo&& rhs)
: main_axis_offset(rhs.main_axis_offset),
page_offset(rhs.page_offset),
target_main_axis_offset(std::move(rhs.target_main_axis_offset)),
left_arrow_bounds(std::move(rhs.left_arrow_bounds)),
right_arrow_bounds(std::move(rhs.right_arrow_bounds)),
is_animating(rhs.is_animating),
is_overflow(rhs.is_overflow),
icons_bounds_in_screen(std::move(rhs.icons_bounds_in_screen)),
is_shelf_widget_animating(rhs.is_shelf_widget_animating){
}

ScrollableShelfInfo& ScrollableShelfInfo::operator=(ScrollableShelfInfo&& rhs)
{
main_axis_offset = rhs.main_axis_offset;
page_offset = rhs.page_offset;
target_main_axis_offset = std::move(rhs.target_main_axis_offset);
left_arrow_bounds = std::move(rhs.left_arrow_bounds);
right_arrow_bounds = std::move(rhs.right_arrow_bounds);
is_animating = rhs.is_animating;
is_overflow = rhs.is_overflow;
icons_bounds_in_screen = std::move(rhs.icons_bounds_in_screen);
is_shelf_widget_animating = rhs.is_shelf_widget_animating;
return *this;
}

// static
bool ScrollableShelfInfo::Populate(
    const base::Value& value, ScrollableShelfInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* main_axis_offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("mainAxisOffset", &main_axis_offset_value)) {
    return false;
  }
  {
    if (!main_axis_offset_value->GetAsDouble(&out->main_axis_offset)) {
      return false;
    }
  }

  const base::Value* page_offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("pageOffset", &page_offset_value)) {
    return false;
  }
  {
    if (!page_offset_value->GetAsDouble(&out->page_offset)) {
      return false;
    }
  }

  const base::Value* target_main_axis_offset_value = NULL;
  if (dict->GetWithoutPathExpansion("targetMainAxisOffset", &target_main_axis_offset_value)) {
    {
      double temp;
      if (!target_main_axis_offset_value->GetAsDouble(&temp)) {
        out->target_main_axis_offset.reset();
        return false;
      }
      else
        out->target_main_axis_offset.reset(new double(temp));
    }
  }

  const base::Value* left_arrow_bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("leftArrowBounds", &left_arrow_bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!left_arrow_bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->left_arrow_bounds)) {
      return false;
    }
  }

  const base::Value* right_arrow_bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("rightArrowBounds", &right_arrow_bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!right_arrow_bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->right_arrow_bounds)) {
      return false;
    }
  }

  const base::Value* is_animating_value = NULL;
  if (!dict->GetWithoutPathExpansion("isAnimating", &is_animating_value)) {
    return false;
  }
  {
    if (!is_animating_value->GetAsBoolean(&out->is_animating)) {
      return false;
    }
  }

  const base::Value* is_overflow_value = NULL;
  if (!dict->GetWithoutPathExpansion("isOverflow", &is_overflow_value)) {
    return false;
  }
  {
    if (!is_overflow_value->GetAsBoolean(&out->is_overflow)) {
      return false;
    }
  }

  const base::Value* icons_bounds_in_screen_value = NULL;
  if (!dict->GetWithoutPathExpansion("iconsBoundsInScreen", &icons_bounds_in_screen_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!icons_bounds_in_screen_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->icons_bounds_in_screen)) {
        return false;
      }
    }
  }

  const base::Value* is_shelf_widget_animating_value = NULL;
  if (!dict->GetWithoutPathExpansion("isShelfWidgetAnimating", &is_shelf_widget_animating_value)) {
    return false;
  }
  {
    if (!is_shelf_widget_animating_value->GetAsBoolean(&out->is_shelf_widget_animating)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ScrollableShelfInfo> ScrollableShelfInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ScrollableShelfInfo> out(new ScrollableShelfInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ScrollableShelfInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("mainAxisOffset", std::make_unique<base::Value>(this->main_axis_offset));

  to_value_result->SetWithoutPathExpansion("pageOffset", std::make_unique<base::Value>(this->page_offset));

  if (this->target_main_axis_offset.get()) {
    to_value_result->SetWithoutPathExpansion("targetMainAxisOffset", std::make_unique<base::Value>(*this->target_main_axis_offset));

  }
  to_value_result->SetWithoutPathExpansion("leftArrowBounds", (this->left_arrow_bounds).ToValue());

  to_value_result->SetWithoutPathExpansion("rightArrowBounds", (this->right_arrow_bounds).ToValue());

  to_value_result->SetWithoutPathExpansion("isAnimating", std::make_unique<base::Value>(this->is_animating));

  to_value_result->SetWithoutPathExpansion("isOverflow", std::make_unique<base::Value>(this->is_overflow));

  to_value_result->SetWithoutPathExpansion("iconsBoundsInScreen", json_schema_compiler::util::CreateValueFromArray(this->icons_bounds_in_screen));

  to_value_result->SetWithoutPathExpansion("isShelfWidgetAnimating", std::make_unique<base::Value>(this->is_shelf_widget_animating));


  return to_value_result;
}


HotseatSwipeDescriptor::HotseatSwipeDescriptor()
 {}

HotseatSwipeDescriptor::~HotseatSwipeDescriptor() {}
HotseatSwipeDescriptor::HotseatSwipeDescriptor(HotseatSwipeDescriptor&& rhs)
: swipe_start_location(std::move(rhs.swipe_start_location)),
swipe_end_location(std::move(rhs.swipe_end_location)){
}

HotseatSwipeDescriptor& HotseatSwipeDescriptor::operator=(HotseatSwipeDescriptor&& rhs)
{
swipe_start_location = std::move(rhs.swipe_start_location);
swipe_end_location = std::move(rhs.swipe_end_location);
return *this;
}

// static
bool HotseatSwipeDescriptor::Populate(
    const base::Value& value, HotseatSwipeDescriptor* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* swipe_start_location_value = NULL;
  if (!dict->GetWithoutPathExpansion("swipeStartLocation", &swipe_start_location_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!swipe_start_location_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Location::Populate(*dictionary, &out->swipe_start_location)) {
      return false;
    }
  }

  const base::Value* swipe_end_location_value = NULL;
  if (!dict->GetWithoutPathExpansion("swipeEndLocation", &swipe_end_location_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!swipe_end_location_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Location::Populate(*dictionary, &out->swipe_end_location)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<HotseatSwipeDescriptor> HotseatSwipeDescriptor::FromValue(const base::Value& value) {
  std::unique_ptr<HotseatSwipeDescriptor> out(new HotseatSwipeDescriptor());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HotseatSwipeDescriptor::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("swipeStartLocation", (this->swipe_start_location).ToValue());

  to_value_result->SetWithoutPathExpansion("swipeEndLocation", (this->swipe_end_location).ToValue());


  return to_value_result;
}


HotseatInfo::HotseatInfo()
: state(HOTSEAT_STATE_NONE),
is_animating(false) {}

HotseatInfo::~HotseatInfo() {}
HotseatInfo::HotseatInfo(HotseatInfo&& rhs)
: swipe_up(std::move(rhs.swipe_up)),
state(rhs.state),
is_animating(rhs.is_animating){
}

HotseatInfo& HotseatInfo::operator=(HotseatInfo&& rhs)
{
swipe_up = std::move(rhs.swipe_up);
state = rhs.state;
is_animating = rhs.is_animating;
return *this;
}

// static
bool HotseatInfo::Populate(
    const base::Value& value, HotseatInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* swipe_up_value = NULL;
  if (!dict->GetWithoutPathExpansion("swipeUp", &swipe_up_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!swipe_up_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!HotseatSwipeDescriptor::Populate(*dictionary, &out->swipe_up)) {
      return false;
    }
  }

  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("state", &state_value)) {
    return false;
  }
  {
    std::string hotseat_state_as_string;
    if (!state_value->GetAsString(&hotseat_state_as_string)) {
      return false;
    }
    out->state = ParseHotseatState(hotseat_state_as_string);
    if (out->state == HOTSEAT_STATE_NONE) {
      return false;
    }
  }

  const base::Value* is_animating_value = NULL;
  if (!dict->GetWithoutPathExpansion("isAnimating", &is_animating_value)) {
    return false;
  }
  {
    if (!is_animating_value->GetAsBoolean(&out->is_animating)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<HotseatInfo> HotseatInfo::FromValue(const base::Value& value) {
  std::unique_ptr<HotseatInfo> out(new HotseatInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HotseatInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("swipeUp", (this->swipe_up).ToValue());

  to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(autotest_private::ToString(this->state)));

  to_value_result->SetWithoutPathExpansion("isAnimating", std::make_unique<base::Value>(this->is_animating));


  return to_value_result;
}


ShelfUIInfo::ShelfUIInfo()
 {}

ShelfUIInfo::~ShelfUIInfo() {}
ShelfUIInfo::ShelfUIInfo(ShelfUIInfo&& rhs)
: hotseat_info(std::move(rhs.hotseat_info)),
scrollable_shelf_info(std::move(rhs.scrollable_shelf_info)){
}

ShelfUIInfo& ShelfUIInfo::operator=(ShelfUIInfo&& rhs)
{
hotseat_info = std::move(rhs.hotseat_info);
scrollable_shelf_info = std::move(rhs.scrollable_shelf_info);
return *this;
}

// static
bool ShelfUIInfo::Populate(
    const base::Value& value, ShelfUIInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* hotseat_info_value = NULL;
  if (!dict->GetWithoutPathExpansion("hotseatInfo", &hotseat_info_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!hotseat_info_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!HotseatInfo::Populate(*dictionary, &out->hotseat_info)) {
      return false;
    }
  }

  const base::Value* scrollable_shelf_info_value = NULL;
  if (!dict->GetWithoutPathExpansion("scrollableShelfInfo", &scrollable_shelf_info_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!scrollable_shelf_info_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ScrollableShelfInfo::Populate(*dictionary, &out->scrollable_shelf_info)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ShelfUIInfo> ShelfUIInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ShelfUIInfo> out(new ShelfUIInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ShelfUIInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("hotseatInfo", (this->hotseat_info).ToValue());

  to_value_result->SetWithoutPathExpansion("scrollableShelfInfo", (this->scrollable_shelf_info).ToValue());


  return to_value_result;
}


TraceConfig::TraceConfig()
 {}

TraceConfig::~TraceConfig() {}
TraceConfig::TraceConfig(TraceConfig&& rhs)
: record_mode(std::move(rhs.record_mode)),
trace_buffer_size_in_events(std::move(rhs.trace_buffer_size_in_events)),
trace_buffer_size_in_kb(std::move(rhs.trace_buffer_size_in_kb)),
enable_systrace(std::move(rhs.enable_systrace)),
enable_argument_filter(std::move(rhs.enable_argument_filter)),
included_categories(std::move(rhs.included_categories)),
excluded_categories(std::move(rhs.excluded_categories)),
included_process_ids(std::move(rhs.included_process_ids)),
enable_systrace_events(std::move(rhs.enable_systrace_events)){
}

TraceConfig& TraceConfig::operator=(TraceConfig&& rhs)
{
record_mode = std::move(rhs.record_mode);
trace_buffer_size_in_events = std::move(rhs.trace_buffer_size_in_events);
trace_buffer_size_in_kb = std::move(rhs.trace_buffer_size_in_kb);
enable_systrace = std::move(rhs.enable_systrace);
enable_argument_filter = std::move(rhs.enable_argument_filter);
included_categories = std::move(rhs.included_categories);
excluded_categories = std::move(rhs.excluded_categories);
included_process_ids = std::move(rhs.included_process_ids);
enable_systrace_events = std::move(rhs.enable_systrace_events);
return *this;
}

// static
bool TraceConfig::Populate(
    const base::Value& value, TraceConfig* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* record_mode_value = NULL;
  if (dict->GetWithoutPathExpansion("record_mode", &record_mode_value)) {
    {
      std::string temp;
      if (!record_mode_value->GetAsString(&temp)) {
        out->record_mode.reset();
        return false;
      }
      else
        out->record_mode.reset(new std::string(temp));
    }
  }

  const base::Value* trace_buffer_size_in_events_value = NULL;
  if (dict->GetWithoutPathExpansion("trace_buffer_size_in_events", &trace_buffer_size_in_events_value)) {
    {
      int temp;
      if (!trace_buffer_size_in_events_value->GetAsInteger(&temp)) {
        out->trace_buffer_size_in_events.reset();
        return false;
      }
      else
        out->trace_buffer_size_in_events.reset(new int(temp));
    }
  }

  const base::Value* trace_buffer_size_in_kb_value = NULL;
  if (dict->GetWithoutPathExpansion("trace_buffer_size_in_kb", &trace_buffer_size_in_kb_value)) {
    {
      int temp;
      if (!trace_buffer_size_in_kb_value->GetAsInteger(&temp)) {
        out->trace_buffer_size_in_kb.reset();
        return false;
      }
      else
        out->trace_buffer_size_in_kb.reset(new int(temp));
    }
  }

  const base::Value* enable_systrace_value = NULL;
  if (dict->GetWithoutPathExpansion("enable_systrace", &enable_systrace_value)) {
    {
      bool temp;
      if (!enable_systrace_value->GetAsBoolean(&temp)) {
        out->enable_systrace.reset();
        return false;
      }
      else
        out->enable_systrace.reset(new bool(temp));
    }
  }

  const base::Value* enable_argument_filter_value = NULL;
  if (dict->GetWithoutPathExpansion("enable_argument_filter", &enable_argument_filter_value)) {
    {
      bool temp;
      if (!enable_argument_filter_value->GetAsBoolean(&temp)) {
        out->enable_argument_filter.reset();
        return false;
      }
      else
        out->enable_argument_filter.reset(new bool(temp));
    }
  }

  const base::Value* included_categories_value = NULL;
  if (dict->GetWithoutPathExpansion("included_categories", &included_categories_value)) {
    {
      const base::ListValue* list = NULL;
      if (!included_categories_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->included_categories)) {
          return false;
        }
      }
    }
  }

  const base::Value* excluded_categories_value = NULL;
  if (dict->GetWithoutPathExpansion("excluded_categories", &excluded_categories_value)) {
    {
      const base::ListValue* list = NULL;
      if (!excluded_categories_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->excluded_categories)) {
          return false;
        }
      }
    }
  }

  const base::Value* included_process_ids_value = NULL;
  if (dict->GetWithoutPathExpansion("included_process_ids", &included_process_ids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!included_process_ids_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->included_process_ids)) {
          return false;
        }
      }
    }
  }

  const base::Value* enable_systrace_events_value = NULL;
  if (dict->GetWithoutPathExpansion("enable_systrace_events", &enable_systrace_events_value)) {
    {
      const base::ListValue* list = NULL;
      if (!enable_systrace_events_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->enable_systrace_events)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<TraceConfig> TraceConfig::FromValue(const base::Value& value) {
  std::unique_ptr<TraceConfig> out(new TraceConfig());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TraceConfig::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->record_mode.get()) {
    to_value_result->SetWithoutPathExpansion("record_mode", std::make_unique<base::Value>(*this->record_mode));

  }
  if (this->trace_buffer_size_in_events.get()) {
    to_value_result->SetWithoutPathExpansion("trace_buffer_size_in_events", std::make_unique<base::Value>(*this->trace_buffer_size_in_events));

  }
  if (this->trace_buffer_size_in_kb.get()) {
    to_value_result->SetWithoutPathExpansion("trace_buffer_size_in_kb", std::make_unique<base::Value>(*this->trace_buffer_size_in_kb));

  }
  if (this->enable_systrace.get()) {
    to_value_result->SetWithoutPathExpansion("enable_systrace", std::make_unique<base::Value>(*this->enable_systrace));

  }
  if (this->enable_argument_filter.get()) {
    to_value_result->SetWithoutPathExpansion("enable_argument_filter", std::make_unique<base::Value>(*this->enable_argument_filter));

  }
  if (this->included_categories.get()) {
    to_value_result->SetWithoutPathExpansion("included_categories", json_schema_compiler::util::CreateValueFromOptionalArray(this->included_categories));

  }
  if (this->excluded_categories.get()) {
    to_value_result->SetWithoutPathExpansion("excluded_categories", json_schema_compiler::util::CreateValueFromOptionalArray(this->excluded_categories));

  }
  if (this->included_process_ids.get()) {
    to_value_result->SetWithoutPathExpansion("included_process_ids", json_schema_compiler::util::CreateValueFromOptionalArray(this->included_process_ids));

  }
  if (this->enable_systrace_events.get()) {
    to_value_result->SetWithoutPathExpansion("enable_systrace_events", json_schema_compiler::util::CreateValueFromOptionalArray(this->enable_systrace_events));

  }

  return to_value_result;
}


SetWindowBoundsResult::SetWindowBoundsResult()
 {}

SetWindowBoundsResult::~SetWindowBoundsResult() {}
SetWindowBoundsResult::SetWindowBoundsResult(SetWindowBoundsResult&& rhs)
: bounds(std::move(rhs.bounds)),
display_id(std::move(rhs.display_id)){
}

SetWindowBoundsResult& SetWindowBoundsResult::operator=(SetWindowBoundsResult&& rhs)
{
bounds = std::move(rhs.bounds);
display_id = std::move(rhs.display_id);
return *this;
}

// static
bool SetWindowBoundsResult::Populate(
    const base::Value& value, SetWindowBoundsResult* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("bounds", &bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->bounds)) {
      return false;
    }
  }

  const base::Value* display_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayId", &display_id_value)) {
    return false;
  }
  {
    if (!display_id_value->GetAsString(&out->display_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SetWindowBoundsResult> SetWindowBoundsResult::FromValue(const base::Value& value) {
  std::unique_ptr<SetWindowBoundsResult> out(new SetWindowBoundsResult());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SetWindowBoundsResult::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("bounds", (this->bounds).ToValue());

  to_value_result->SetWithoutPathExpansion("displayId", std::make_unique<base::Value>(this->display_id));


  return to_value_result;
}



//
// Functions
//

namespace InitializeEvents {

}  // namespace InitializeEvents

namespace Logout {

}  // namespace Logout

namespace Restart {

}  // namespace Restart

namespace Shutdown {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* force_value = NULL;
  if (args.Get(0, &force_value) &&
      !force_value->is_none()) {
    {
      if (!force_value->GetAsBoolean(&params->force)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Shutdown

namespace LoginStatus {

std::unique_ptr<base::ListValue> Results::Create(const LoginStatusDict& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((status).ToValue());

  return create_results;
}
}  // namespace LoginStatus

namespace LockScreen {

}  // namespace LockScreen

namespace GetExtensionsInfo {

std::unique_ptr<base::ListValue> Results::Create(const ExtensionsInfoArray& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetExtensionsInfo

namespace GetAllEnterprisePolicies {

std::unique_ptr<base::ListValue> Results::Create(const base::Value& all_policies) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((all_policies).CreateDeepCopy());

  return create_results;
}
}  // namespace GetAllEnterprisePolicies

namespace RefreshEnterprisePolicies {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RefreshEnterprisePolicies

namespace SimulateAsanMemoryBug {

}  // namespace SimulateAsanMemoryBug

namespace SetTouchpadSensitivity {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* value_value = NULL;
  if (args.Get(0, &value_value) &&
      !value_value->is_none()) {
    {
      if (!value_value->GetAsInteger(&params->value)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetTouchpadSensitivity

namespace SetTapToClick {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetTapToClick

namespace SetThreeFingerClick {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetThreeFingerClick

namespace SetTapDragging {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetTapDragging

namespace SetNaturalScroll {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetNaturalScroll

namespace SetMouseSensitivity {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* value_value = NULL;
  if (args.Get(0, &value_value) &&
      !value_value->is_none()) {
    {
      if (!value_value->GetAsInteger(&params->value)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetMouseSensitivity

namespace SetPrimaryButtonRight {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* right_value = NULL;
  if (args.Get(0, &right_value) &&
      !right_value->is_none()) {
    {
      if (!right_value->GetAsBoolean(&params->right)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetPrimaryButtonRight

namespace SetMouseReverseScroll {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetMouseReverseScroll

namespace GetVisibleNotifications {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<Notification>& notifications) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(notifications));

  return create_results;
}
}  // namespace GetVisibleNotifications

namespace GetArcStartTime {

std::unique_ptr<base::ListValue> Results::Create(double start_time) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(start_time));

  return create_results;
}
}  // namespace GetArcStartTime

namespace GetArcState {

std::unique_ptr<base::ListValue> Results::Create(const ArcState& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetArcState

namespace GetPlayStoreState {

std::unique_ptr<base::ListValue> Results::Create(const PlayStoreState& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetPlayStoreState

namespace GetPrinterList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<Printer>& printers) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(printers));

  return create_results;
}
}  // namespace GetPrinterList

namespace IsAppShown {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_value = NULL;
  if (args.Get(0, &app_id_value) &&
      !app_id_value->is_none()) {
    {
      if (!app_id_value->GetAsString(&params->app_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool app_shown) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(app_shown));

  return create_results;
}
}  // namespace IsAppShown

namespace IsArcProvisioned {

std::unique_ptr<base::ListValue> Results::Create(bool arc_provisioned) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(arc_provisioned));

  return create_results;
}
}  // namespace IsArcProvisioned

namespace GetArcApp {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_value = NULL;
  if (args.Get(0, &app_id_value) &&
      !app_id_value->is_none()) {
    {
      if (!app_id_value->GetAsString(&params->app_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ArcAppDict& package) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((package).ToValue());

  return create_results;
}
}  // namespace GetArcApp

namespace GetArcPackage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* package_name_value = NULL;
  if (args.Get(0, &package_name_value) &&
      !package_name_value->is_none()) {
    {
      if (!package_name_value->GetAsString(&params->package_name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ArcPackageDict& package) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((package).ToValue());

  return create_results;
}
}  // namespace GetArcPackage

namespace LaunchArcApp {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_value = NULL;
  if (args.Get(0, &app_id_value) &&
      !app_id_value->is_none()) {
    {
      if (!app_id_value->GetAsString(&params->app_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* intent_value = NULL;
  if (args.Get(1, &intent_value) &&
      !intent_value->is_none()) {
    {
      if (!intent_value->GetAsString(&params->intent)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool app_launched) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(app_launched));

  return create_results;
}
}  // namespace LaunchArcApp

namespace LaunchApp {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_value = NULL;
  if (args.Get(0, &app_id_value) &&
      !app_id_value->is_none()) {
    {
      if (!app_id_value->GetAsString(&params->app_id)) {
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
}  // namespace LaunchApp

namespace CloseApp {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_value = NULL;
  if (args.Get(0, &app_id_value) &&
      !app_id_value->is_none()) {
    {
      if (!app_id_value->GetAsString(&params->app_id)) {
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
}  // namespace CloseApp

namespace UpdatePrinter {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* printer_value = NULL;
  if (args.Get(0, &printer_value) &&
      !printer_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!printer_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Printer::Populate(*dictionary, &params->printer)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace UpdatePrinter

namespace RemovePrinter {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* printer_id_value = NULL;
  if (args.Get(0, &printer_id_value) &&
      !printer_id_value->is_none()) {
    {
      if (!printer_id_value->GetAsString(&params->printer_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RemovePrinter

namespace SetPlayStoreEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
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
}  // namespace SetPlayStoreEnabled

namespace GetClipboardTextData {

std::unique_ptr<base::ListValue> Results::Create(const std::string& data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(data));

  return create_results;
}
}  // namespace GetClipboardTextData

namespace SetClipboardTextData {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* data_value = NULL;
  if (args.Get(0, &data_value) &&
      !data_value->is_none()) {
    {
      if (!data_value->GetAsString(&params->data)) {
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
}  // namespace SetClipboardTextData

namespace RunCrostiniInstaller {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RunCrostiniInstaller

namespace RunCrostiniUninstaller {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RunCrostiniUninstaller

namespace SetCrostiniEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
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
}  // namespace SetCrostiniEnabled

namespace ExportCrostini {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* path_value = NULL;
  if (args.Get(0, &path_value) &&
      !path_value->is_none()) {
    {
      if (!path_value->GetAsString(&params->path)) {
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
}  // namespace ExportCrostini

namespace ImportCrostini {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* path_value = NULL;
  if (args.Get(0, &path_value) &&
      !path_value->is_none()) {
    {
      if (!path_value->GetAsString(&params->path)) {
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
}  // namespace ImportCrostini

namespace InstallPluginVM {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* image_url_value = NULL;
  if (args.Get(0, &image_url_value) &&
      !image_url_value->is_none()) {
    {
      if (!image_url_value->GetAsString(&params->image_url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* image_hash_value = NULL;
  if (args.Get(1, &image_hash_value) &&
      !image_hash_value->is_none()) {
    {
      if (!image_hash_value->GetAsString(&params->image_hash)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* license_key_value = NULL;
  if (args.Get(2, &license_key_value) &&
      !license_key_value->is_none()) {
    {
      if (!license_key_value->GetAsString(&params->license_key)) {
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
}  // namespace InstallPluginVM

namespace SetPluginVMPolicy {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* image_url_value = NULL;
  if (args.Get(0, &image_url_value) &&
      !image_url_value->is_none()) {
    {
      if (!image_url_value->GetAsString(&params->image_url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* image_hash_value = NULL;
  if (args.Get(1, &image_hash_value) &&
      !image_hash_value->is_none()) {
    {
      if (!image_hash_value->GetAsString(&params->image_hash)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* license_key_value = NULL;
  if (args.Get(2, &license_key_value) &&
      !license_key_value->is_none()) {
    {
      if (!license_key_value->GetAsString(&params->license_key)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetPluginVMPolicy

namespace ShowPluginVMInstaller {

}  // namespace ShowPluginVMInstaller

namespace RegisterComponent {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* name_value = NULL;
  if (args.Get(0, &name_value) &&
      !name_value->is_none()) {
    {
      if (!name_value->GetAsString(&params->name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* path_value = NULL;
  if (args.Get(1, &path_value) &&
      !path_value->is_none()) {
    {
      if (!path_value->GetAsString(&params->path)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RegisterComponent

namespace TakeScreenshot {

std::unique_ptr<base::ListValue> Results::Create(const std::string& base64_png) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(base64_png));

  return create_results;
}
}  // namespace TakeScreenshot

namespace TakeScreenshotForDisplay {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      if (!display_id_value->GetAsString(&params->display_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& base64_png) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(base64_png));

  return create_results;
}
}  // namespace TakeScreenshotForDisplay

namespace BootstrapMachineLearningService {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace BootstrapMachineLearningService

namespace SetAssistantEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* timeout_ms_value = NULL;
  if (args.Get(1, &timeout_ms_value) &&
      !timeout_ms_value->is_none()) {
    {
      if (!timeout_ms_value->GetAsInteger(&params->timeout_ms)) {
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
}  // namespace SetAssistantEnabled

namespace EnableAssistantAndWaitForReady {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace EnableAssistantAndWaitForReady

namespace SendAssistantTextQuery {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* query_value = NULL;
  if (args.Get(0, &query_value) &&
      !query_value->is_none()) {
    {
      if (!query_value->GetAsString(&params->query)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* timeout_ms_value = NULL;
  if (args.Get(1, &timeout_ms_value) &&
      !timeout_ms_value->is_none()) {
    {
      if (!timeout_ms_value->GetAsInteger(&params->timeout_ms)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const AssistantQueryStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((status).ToValue());

  return create_results;
}
}  // namespace SendAssistantTextQuery

namespace WaitForAssistantQueryStatus {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* timeout_s_value = NULL;
  if (args.Get(0, &timeout_s_value) &&
      !timeout_s_value->is_none()) {
    {
      if (!timeout_s_value->GetAsInteger(&params->timeout_s)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const AssistantQueryStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((status).ToValue());

  return create_results;
}
}  // namespace WaitForAssistantQueryStatus

namespace IsArcPackageListInitialRefreshed {

std::unique_ptr<base::ListValue> Results::Create(bool refreshed) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(refreshed));

  return create_results;
}
}  // namespace IsArcPackageListInitialRefreshed

namespace SetWhitelistedPref {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* pref_name_value = NULL;
  if (args.Get(0, &pref_name_value) &&
      !pref_name_value->is_none()) {
    {
      if (!pref_name_value->GetAsString(&params->pref_name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* value_value = NULL;
  if (args.Get(1, &value_value) &&
      !value_value->is_none()) {
    {
      params->value = value_value->CreateDeepCopy();
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
}  // namespace SetWhitelistedPref

namespace SetCrostiniAppScaled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_value = NULL;
  if (args.Get(0, &app_id_value) &&
      !app_id_value->is_none()) {
    {
      if (!app_id_value->GetAsString(&params->app_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* scaled_value = NULL;
  if (args.Get(1, &scaled_value) &&
      !scaled_value->is_none()) {
    {
      if (!scaled_value->GetAsBoolean(&params->scaled)) {
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
}  // namespace SetCrostiniAppScaled

namespace GetPrimaryDisplayScaleFactor {

std::unique_ptr<base::ListValue> Results::Create(double scale_factor) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(scale_factor));

  return create_results;
}
}  // namespace GetPrimaryDisplayScaleFactor

namespace IsTabletModeEnabled {

std::unique_ptr<base::ListValue> Results::Create(bool enabled) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(enabled));

  return create_results;
}
}  // namespace IsTabletModeEnabled

namespace SetTabletModeEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool enabled) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(enabled));

  return create_results;
}
}  // namespace SetTabletModeEnabled

namespace GetAllInstalledApps {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<App>& apps) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(apps));

  return create_results;
}
}  // namespace GetAllInstalledApps

namespace GetShelfItems {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<ShelfItem>& items) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(items));

  return create_results;
}
}  // namespace GetShelfItems

namespace GetShelfAutoHideBehavior {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      if (!display_id_value->GetAsString(&params->display_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& behavior) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(behavior));

  return create_results;
}
}  // namespace GetShelfAutoHideBehavior

namespace SetShelfAutoHideBehavior {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      if (!display_id_value->GetAsString(&params->display_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* behavior_value = NULL;
  if (args.Get(1, &behavior_value) &&
      !behavior_value->is_none()) {
    {
      if (!behavior_value->GetAsString(&params->behavior)) {
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
}  // namespace SetShelfAutoHideBehavior

namespace GetShelfAlignment {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      if (!display_id_value->GetAsString(&params->display_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ShelfAlignmentType& alignment) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(autotest_private::ToString(alignment)));

  return create_results;
}
}  // namespace GetShelfAlignment

namespace SetShelfAlignment {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      if (!display_id_value->GetAsString(&params->display_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* alignment_value = NULL;
  if (args.Get(1, &alignment_value) &&
      !alignment_value->is_none()) {
    {
      std::string shelf_alignment_type_as_string;
      if (!alignment_value->GetAsString(&shelf_alignment_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->alignment = ParseShelfAlignmentType(shelf_alignment_type_as_string);
      if (params->alignment == SHELF_ALIGNMENT_TYPE_NONE) {
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
}  // namespace SetShelfAlignment

namespace PinShelfIcon {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* app_id_value = NULL;
  if (args.Get(0, &app_id_value) &&
      !app_id_value->is_none()) {
    {
      if (!app_id_value->GetAsString(&params->app_id)) {
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
}  // namespace PinShelfIcon

namespace SetOverviewModeState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* start_value = NULL;
  if (args.Get(0, &start_value) &&
      !start_value->is_none()) {
    {
      if (!start_value->GetAsBoolean(&params->start)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool finished) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(finished));

  return create_results;
}
}  // namespace SetOverviewModeState

namespace ShowVirtualKeyboardIfEnabled {

}  // namespace ShowVirtualKeyboardIfEnabled

namespace ArcAppTracingStart {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ArcAppTracingStart

namespace ArcAppTracingStopAndAnalyze {

std::unique_ptr<base::ListValue> Results::Create(const ArcAppTracingInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace ArcAppTracingStopAndAnalyze

namespace SwapWindowsInSplitView {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SwapWindowsInSplitView

namespace SetArcAppWindowFocus {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* package_name_value = NULL;
  if (args.Get(0, &package_name_value) &&
      !package_name_value->is_none()) {
    {
      if (!package_name_value->GetAsString(&params->package_name)) {
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
}  // namespace SetArcAppWindowFocus

namespace WaitForDisplayRotation {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      if (!display_id_value->GetAsString(&params->display_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* rotation_value = NULL;
  if (args.Get(1, &rotation_value) &&
      !rotation_value->is_none()) {
    {
      std::string rotation_type_as_string;
      if (!rotation_value->GetAsString(&rotation_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->rotation = ParseRotationType(rotation_type_as_string);
      if (params->rotation == ROTATION_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace WaitForDisplayRotation

namespace GetAppWindowList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<AppWindowInfo>& window_list) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(window_list));

  return create_results;
}
}  // namespace GetAppWindowList

namespace SetAppWindowState {

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
      if (!id_value->GetAsInteger(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* change_value = NULL;
  if (args.Get(1, &change_value) &&
      !change_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!change_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!WindowStateChangeDict::Populate(*dictionary, &params->change)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const WindowStateType& current_type) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(autotest_private::ToString(current_type)));

  return create_results;
}
}  // namespace SetAppWindowState

namespace CloseAppWindow {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsInteger(&params->id)) {
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
}  // namespace CloseAppWindow

namespace InstallPWAForCurrentURL {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* timeout_ms_value = NULL;
  if (args.Get(0, &timeout_ms_value) &&
      !timeout_ms_value->is_none()) {
    {
      if (!timeout_ms_value->GetAsInteger(&params->timeout_ms)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& app_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(app_id));

  return create_results;
}
}  // namespace InstallPWAForCurrentURL

namespace ActivateAccelerator {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* accelerator_value = NULL;
  if (args.Get(0, &accelerator_value) &&
      !accelerator_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!accelerator_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Accelerator::Populate(*dictionary, &params->accelerator)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace ActivateAccelerator

namespace WaitForLauncherState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* launcher_state_value = NULL;
  if (args.Get(0, &launcher_state_value) &&
      !launcher_state_value->is_none()) {
    {
      std::string launcher_state_type_as_string;
      if (!launcher_state_value->GetAsString(&launcher_state_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->launcher_state = ParseLauncherStateType(launcher_state_type_as_string);
      if (params->launcher_state == LAUNCHER_STATE_TYPE_NONE) {
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
}  // namespace WaitForLauncherState

namespace WaitForOverviewState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* overview_state_value = NULL;
  if (args.Get(0, &overview_state_value) &&
      !overview_state_value->is_none()) {
    {
      std::string overview_state_type_as_string;
      if (!overview_state_value->GetAsString(&overview_state_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->overview_state = ParseOverviewStateType(overview_state_type_as_string);
      if (params->overview_state == OVERVIEW_STATE_TYPE_NONE) {
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
}  // namespace WaitForOverviewState

namespace CreateNewDesk {

std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace CreateNewDesk

namespace ActivateDeskAtIndex {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* index_value = NULL;
  if (args.Get(0, &index_value) &&
      !index_value->is_none()) {
    {
      if (!index_value->GetAsInteger(&params->index)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace ActivateDeskAtIndex

namespace RemoveActiveDesk {

std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace RemoveActiveDesk

namespace MouseClick {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* button_value = NULL;
  if (args.Get(0, &button_value) &&
      !button_value->is_none()) {
    {
      std::string mouse_button_as_string;
      if (!button_value->GetAsString(&mouse_button_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->button = ParseMouseButton(mouse_button_as_string);
      if (params->button == MOUSE_BUTTON_NONE) {
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
}  // namespace MouseClick

namespace MousePress {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* button_value = NULL;
  if (args.Get(0, &button_value) &&
      !button_value->is_none()) {
    {
      std::string mouse_button_as_string;
      if (!button_value->GetAsString(&mouse_button_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->button = ParseMouseButton(mouse_button_as_string);
      if (params->button == MOUSE_BUTTON_NONE) {
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
}  // namespace MousePress

namespace MouseRelease {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* button_value = NULL;
  if (args.Get(0, &button_value) &&
      !button_value->is_none()) {
    {
      std::string mouse_button_as_string;
      if (!button_value->GetAsString(&mouse_button_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->button = ParseMouseButton(mouse_button_as_string);
      if (params->button == MOUSE_BUTTON_NONE) {
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
}  // namespace MouseRelease

namespace MouseMove {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* location_value = NULL;
  if (args.Get(0, &location_value) &&
      !location_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!location_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Location::Populate(*dictionary, &params->location)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* duration_in_ms_value = NULL;
  if (args.Get(1, &duration_in_ms_value) &&
      !duration_in_ms_value->is_none()) {
    {
      if (!duration_in_ms_value->GetAsDouble(&params->duration_in_ms)) {
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
}  // namespace MouseMove

namespace SetMetricsEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
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
}  // namespace SetMetricsEnabled

namespace StartTracing {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* config_value = NULL;
  if (args.Get(0, &config_value) &&
      !config_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!config_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!TraceConfig::Populate(*dictionary, &params->config)) {
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
}  // namespace StartTracing

namespace StopTracing {

std::unique_ptr<base::ListValue> Results::Create(const std::string& data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(data));

  return create_results;
}
}  // namespace StopTracing

namespace SetArcTouchMode {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
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
}  // namespace SetArcTouchMode

namespace GetScrollableShelfInfoForState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* state_value = NULL;
  if (args.Get(0, &state_value) &&
      !state_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!state_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ScrollableShelfState::Populate(*dictionary, &params->state)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ScrollableShelfInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetScrollableShelfInfoForState

namespace GetShelfUIInfoForState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* state_value = NULL;
  if (args.Get(0, &state_value) &&
      !state_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!state_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ShelfState::Populate(*dictionary, &params->state)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ShelfUIInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetShelfUIInfoForState

namespace SetWindowBounds {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsInteger(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* bounds_value = NULL;
  if (args.Get(1, &bounds_value) &&
      !bounds_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!bounds_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Bounds::Populate(*dictionary, &params->bounds)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* display_id_value = NULL;
  if (args.Get(2, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      if (!display_id_value->GetAsString(&params->display_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const SetWindowBoundsResult& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace SetWindowBounds

namespace StartSmoothnessTracking {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      std::string temp;
      if (!display_id_value->GetAsString(&temp)) {
        params->display_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->display_id.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace StartSmoothnessTracking

namespace StopSmoothnessTracking {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* display_id_value = NULL;
  if (args.Get(0, &display_id_value) &&
      !display_id_value->is_none()) {
    {
      std::string temp;
      if (!display_id_value->GetAsString(&temp)) {
        params->display_id.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->display_id.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int smoothness) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(smoothness));

  return create_results;
}
}  // namespace StopSmoothnessTracking

namespace DisableSwitchAccessDialog {

}  // namespace DisableSwitchAccessDialog

namespace WaitForAmbientPhotoAnimation {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* photo_refresh_interval_value = NULL;
  if (args.Get(0, &photo_refresh_interval_value) &&
      !photo_refresh_interval_value->is_none()) {
    {
      if (!photo_refresh_interval_value->GetAsInteger(&params->photo_refresh_interval)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* num_completions_value = NULL;
  if (args.Get(1, &num_completions_value) &&
      !num_completions_value->is_none()) {
    {
      if (!num_completions_value->GetAsInteger(&params->num_completions)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* timeout_value = NULL;
  if (args.Get(2, &timeout_value) &&
      !timeout_value->is_none()) {
    {
      if (!timeout_value->GetAsInteger(&params->timeout)) {
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
}  // namespace WaitForAmbientPhotoAnimation

//
// Events
//

namespace OnClipboardDataChanged {

const char kEventName[] = "autotestPrivate.onClipboardDataChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnClipboardDataChanged

}  // namespace autotest_private
}  // namespace api
}  // namespace extensions

