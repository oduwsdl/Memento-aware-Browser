// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/networking_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/networking_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace networking_private {
//
// Types
//

const char* ToString(ActivationStateType enum_param) {
  switch (enum_param) {
    case ACTIVATION_STATE_TYPE_ACTIVATED:
      return "Activated";
    case ACTIVATION_STATE_TYPE_ACTIVATING:
      return "Activating";
    case ACTIVATION_STATE_TYPE_NOTACTIVATED:
      return "NotActivated";
    case ACTIVATION_STATE_TYPE_PARTIALLYACTIVATED:
      return "PartiallyActivated";
    case ACTIVATION_STATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ActivationStateType ParseActivationStateType(const std::string& enum_string) {
  if (enum_string == "Activated")
    return ACTIVATION_STATE_TYPE_ACTIVATED;
  if (enum_string == "Activating")
    return ACTIVATION_STATE_TYPE_ACTIVATING;
  if (enum_string == "NotActivated")
    return ACTIVATION_STATE_TYPE_NOTACTIVATED;
  if (enum_string == "PartiallyActivated")
    return ACTIVATION_STATE_TYPE_PARTIALLYACTIVATED;
  return ACTIVATION_STATE_TYPE_NONE;
}


const char* ToString(CaptivePortalStatus enum_param) {
  switch (enum_param) {
    case CAPTIVE_PORTAL_STATUS_UNKNOWN:
      return "Unknown";
    case CAPTIVE_PORTAL_STATUS_OFFLINE:
      return "Offline";
    case CAPTIVE_PORTAL_STATUS_ONLINE:
      return "Online";
    case CAPTIVE_PORTAL_STATUS_PORTAL:
      return "Portal";
    case CAPTIVE_PORTAL_STATUS_PROXYAUTHREQUIRED:
      return "ProxyAuthRequired";
    case CAPTIVE_PORTAL_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CaptivePortalStatus ParseCaptivePortalStatus(const std::string& enum_string) {
  if (enum_string == "Unknown")
    return CAPTIVE_PORTAL_STATUS_UNKNOWN;
  if (enum_string == "Offline")
    return CAPTIVE_PORTAL_STATUS_OFFLINE;
  if (enum_string == "Online")
    return CAPTIVE_PORTAL_STATUS_ONLINE;
  if (enum_string == "Portal")
    return CAPTIVE_PORTAL_STATUS_PORTAL;
  if (enum_string == "ProxyAuthRequired")
    return CAPTIVE_PORTAL_STATUS_PROXYAUTHREQUIRED;
  return CAPTIVE_PORTAL_STATUS_NONE;
}


const char* ToString(ConnectionStateType enum_param) {
  switch (enum_param) {
    case CONNECTION_STATE_TYPE_CONNECTED:
      return "Connected";
    case CONNECTION_STATE_TYPE_CONNECTING:
      return "Connecting";
    case CONNECTION_STATE_TYPE_NOTCONNECTED:
      return "NotConnected";
    case CONNECTION_STATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ConnectionStateType ParseConnectionStateType(const std::string& enum_string) {
  if (enum_string == "Connected")
    return CONNECTION_STATE_TYPE_CONNECTED;
  if (enum_string == "Connecting")
    return CONNECTION_STATE_TYPE_CONNECTING;
  if (enum_string == "NotConnected")
    return CONNECTION_STATE_TYPE_NOTCONNECTED;
  return CONNECTION_STATE_TYPE_NONE;
}


const char* ToString(DeviceStateType enum_param) {
  switch (enum_param) {
    case DEVICE_STATE_TYPE_UNINITIALIZED:
      return "Uninitialized";
    case DEVICE_STATE_TYPE_DISABLED:
      return "Disabled";
    case DEVICE_STATE_TYPE_ENABLING:
      return "Enabling";
    case DEVICE_STATE_TYPE_ENABLED:
      return "Enabled";
    case DEVICE_STATE_TYPE_PROHIBITED:
      return "Prohibited";
    case DEVICE_STATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DeviceStateType ParseDeviceStateType(const std::string& enum_string) {
  if (enum_string == "Uninitialized")
    return DEVICE_STATE_TYPE_UNINITIALIZED;
  if (enum_string == "Disabled")
    return DEVICE_STATE_TYPE_DISABLED;
  if (enum_string == "Enabling")
    return DEVICE_STATE_TYPE_ENABLING;
  if (enum_string == "Enabled")
    return DEVICE_STATE_TYPE_ENABLED;
  if (enum_string == "Prohibited")
    return DEVICE_STATE_TYPE_PROHIBITED;
  return DEVICE_STATE_TYPE_NONE;
}


const char* ToString(IPConfigType enum_param) {
  switch (enum_param) {
    case IP_CONFIG_TYPE_DHCP:
      return "DHCP";
    case IP_CONFIG_TYPE_STATIC:
      return "Static";
    case IP_CONFIG_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

IPConfigType ParseIPConfigType(const std::string& enum_string) {
  if (enum_string == "DHCP")
    return IP_CONFIG_TYPE_DHCP;
  if (enum_string == "Static")
    return IP_CONFIG_TYPE_STATIC;
  return IP_CONFIG_TYPE_NONE;
}


const char* ToString(NetworkType enum_param) {
  switch (enum_param) {
    case NETWORK_TYPE_ALL:
      return "All";
    case NETWORK_TYPE_CELLULAR:
      return "Cellular";
    case NETWORK_TYPE_ETHERNET:
      return "Ethernet";
    case NETWORK_TYPE_TETHER:
      return "Tether";
    case NETWORK_TYPE_VPN:
      return "VPN";
    case NETWORK_TYPE_WIRELESS:
      return "Wireless";
    case NETWORK_TYPE_WIFI:
      return "WiFi";
    case NETWORK_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

NetworkType ParseNetworkType(const std::string& enum_string) {
  if (enum_string == "All")
    return NETWORK_TYPE_ALL;
  if (enum_string == "Cellular")
    return NETWORK_TYPE_CELLULAR;
  if (enum_string == "Ethernet")
    return NETWORK_TYPE_ETHERNET;
  if (enum_string == "Tether")
    return NETWORK_TYPE_TETHER;
  if (enum_string == "VPN")
    return NETWORK_TYPE_VPN;
  if (enum_string == "Wireless")
    return NETWORK_TYPE_WIRELESS;
  if (enum_string == "WiFi")
    return NETWORK_TYPE_WIFI;
  return NETWORK_TYPE_NONE;
}


const char* ToString(ProxySettingsType enum_param) {
  switch (enum_param) {
    case PROXY_SETTINGS_TYPE_DIRECT:
      return "Direct";
    case PROXY_SETTINGS_TYPE_MANUAL:
      return "Manual";
    case PROXY_SETTINGS_TYPE_PAC:
      return "PAC";
    case PROXY_SETTINGS_TYPE_WPAD:
      return "WPAD";
    case PROXY_SETTINGS_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ProxySettingsType ParseProxySettingsType(const std::string& enum_string) {
  if (enum_string == "Direct")
    return PROXY_SETTINGS_TYPE_DIRECT;
  if (enum_string == "Manual")
    return PROXY_SETTINGS_TYPE_MANUAL;
  if (enum_string == "PAC")
    return PROXY_SETTINGS_TYPE_PAC;
  if (enum_string == "WPAD")
    return PROXY_SETTINGS_TYPE_WPAD;
  return PROXY_SETTINGS_TYPE_NONE;
}


ManagedBoolean::ManagedBoolean()
 {}

ManagedBoolean::~ManagedBoolean() {}
ManagedBoolean::ManagedBoolean(ManagedBoolean&& rhs)
: active(std::move(rhs.active)),
effective(std::move(rhs.effective)),
user_policy(std::move(rhs.user_policy)),
device_policy(std::move(rhs.device_policy)),
user_setting(std::move(rhs.user_setting)),
shared_setting(std::move(rhs.shared_setting)),
user_editable(std::move(rhs.user_editable)),
device_editable(std::move(rhs.device_editable)){
}

ManagedBoolean& ManagedBoolean::operator=(ManagedBoolean&& rhs)
{
active = std::move(rhs.active);
effective = std::move(rhs.effective);
user_policy = std::move(rhs.user_policy);
device_policy = std::move(rhs.device_policy);
user_setting = std::move(rhs.user_setting);
shared_setting = std::move(rhs.shared_setting);
user_editable = std::move(rhs.user_editable);
device_editable = std::move(rhs.device_editable);
return *this;
}

// static
bool ManagedBoolean::Populate(
    const base::Value& value, ManagedBoolean* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("Active", &active_value)) {
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

  const base::Value* effective_value = NULL;
  if (dict->GetWithoutPathExpansion("Effective", &effective_value)) {
    {
      std::string temp;
      if (!effective_value->GetAsString(&temp)) {
        out->effective.reset();
        return false;
      }
      else
        out->effective.reset(new std::string(temp));
    }
  }

  const base::Value* user_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("UserPolicy", &user_policy_value)) {
    {
      bool temp;
      if (!user_policy_value->GetAsBoolean(&temp)) {
        out->user_policy.reset();
        return false;
      }
      else
        out->user_policy.reset(new bool(temp));
    }
  }

  const base::Value* device_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("DevicePolicy", &device_policy_value)) {
    {
      bool temp;
      if (!device_policy_value->GetAsBoolean(&temp)) {
        out->device_policy.reset();
        return false;
      }
      else
        out->device_policy.reset(new bool(temp));
    }
  }

  const base::Value* user_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("UserSetting", &user_setting_value)) {
    {
      bool temp;
      if (!user_setting_value->GetAsBoolean(&temp)) {
        out->user_setting.reset();
        return false;
      }
      else
        out->user_setting.reset(new bool(temp));
    }
  }

  const base::Value* shared_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("SharedSetting", &shared_setting_value)) {
    {
      bool temp;
      if (!shared_setting_value->GetAsBoolean(&temp)) {
        out->shared_setting.reset();
        return false;
      }
      else
        out->shared_setting.reset(new bool(temp));
    }
  }

  const base::Value* user_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("UserEditable", &user_editable_value)) {
    {
      bool temp;
      if (!user_editable_value->GetAsBoolean(&temp)) {
        out->user_editable.reset();
        return false;
      }
      else
        out->user_editable.reset(new bool(temp));
    }
  }

  const base::Value* device_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("DeviceEditable", &device_editable_value)) {
    {
      bool temp;
      if (!device_editable_value->GetAsBoolean(&temp)) {
        out->device_editable.reset();
        return false;
      }
      else
        out->device_editable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedBoolean> ManagedBoolean::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedBoolean> out(new ManagedBoolean());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedBoolean::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->active.get()) {
    to_value_result->SetWithoutPathExpansion("Active", std::make_unique<base::Value>(*this->active));

  }
  if (this->effective.get()) {
    to_value_result->SetWithoutPathExpansion("Effective", std::make_unique<base::Value>(*this->effective));

  }
  if (this->user_policy.get()) {
    to_value_result->SetWithoutPathExpansion("UserPolicy", std::make_unique<base::Value>(*this->user_policy));

  }
  if (this->device_policy.get()) {
    to_value_result->SetWithoutPathExpansion("DevicePolicy", std::make_unique<base::Value>(*this->device_policy));

  }
  if (this->user_setting.get()) {
    to_value_result->SetWithoutPathExpansion("UserSetting", std::make_unique<base::Value>(*this->user_setting));

  }
  if (this->shared_setting.get()) {
    to_value_result->SetWithoutPathExpansion("SharedSetting", std::make_unique<base::Value>(*this->shared_setting));

  }
  if (this->user_editable.get()) {
    to_value_result->SetWithoutPathExpansion("UserEditable", std::make_unique<base::Value>(*this->user_editable));

  }
  if (this->device_editable.get()) {
    to_value_result->SetWithoutPathExpansion("DeviceEditable", std::make_unique<base::Value>(*this->device_editable));

  }

  return to_value_result;
}


ManagedLong::ManagedLong()
 {}

ManagedLong::~ManagedLong() {}
ManagedLong::ManagedLong(ManagedLong&& rhs)
: active(std::move(rhs.active)),
effective(std::move(rhs.effective)),
user_policy(std::move(rhs.user_policy)),
device_policy(std::move(rhs.device_policy)),
user_setting(std::move(rhs.user_setting)),
shared_setting(std::move(rhs.shared_setting)),
user_editable(std::move(rhs.user_editable)),
device_editable(std::move(rhs.device_editable)){
}

ManagedLong& ManagedLong::operator=(ManagedLong&& rhs)
{
active = std::move(rhs.active);
effective = std::move(rhs.effective);
user_policy = std::move(rhs.user_policy);
device_policy = std::move(rhs.device_policy);
user_setting = std::move(rhs.user_setting);
shared_setting = std::move(rhs.shared_setting);
user_editable = std::move(rhs.user_editable);
device_editable = std::move(rhs.device_editable);
return *this;
}

// static
bool ManagedLong::Populate(
    const base::Value& value, ManagedLong* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("Active", &active_value)) {
    {
      int temp;
      if (!active_value->GetAsInteger(&temp)) {
        out->active.reset();
        return false;
      }
      else
        out->active.reset(new int(temp));
    }
  }

  const base::Value* effective_value = NULL;
  if (dict->GetWithoutPathExpansion("Effective", &effective_value)) {
    {
      std::string temp;
      if (!effective_value->GetAsString(&temp)) {
        out->effective.reset();
        return false;
      }
      else
        out->effective.reset(new std::string(temp));
    }
  }

  const base::Value* user_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("UserPolicy", &user_policy_value)) {
    {
      int temp;
      if (!user_policy_value->GetAsInteger(&temp)) {
        out->user_policy.reset();
        return false;
      }
      else
        out->user_policy.reset(new int(temp));
    }
  }

  const base::Value* device_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("DevicePolicy", &device_policy_value)) {
    {
      int temp;
      if (!device_policy_value->GetAsInteger(&temp)) {
        out->device_policy.reset();
        return false;
      }
      else
        out->device_policy.reset(new int(temp));
    }
  }

  const base::Value* user_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("UserSetting", &user_setting_value)) {
    {
      int temp;
      if (!user_setting_value->GetAsInteger(&temp)) {
        out->user_setting.reset();
        return false;
      }
      else
        out->user_setting.reset(new int(temp));
    }
  }

  const base::Value* shared_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("SharedSetting", &shared_setting_value)) {
    {
      int temp;
      if (!shared_setting_value->GetAsInteger(&temp)) {
        out->shared_setting.reset();
        return false;
      }
      else
        out->shared_setting.reset(new int(temp));
    }
  }

  const base::Value* user_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("UserEditable", &user_editable_value)) {
    {
      bool temp;
      if (!user_editable_value->GetAsBoolean(&temp)) {
        out->user_editable.reset();
        return false;
      }
      else
        out->user_editable.reset(new bool(temp));
    }
  }

  const base::Value* device_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("DeviceEditable", &device_editable_value)) {
    {
      bool temp;
      if (!device_editable_value->GetAsBoolean(&temp)) {
        out->device_editable.reset();
        return false;
      }
      else
        out->device_editable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedLong> ManagedLong::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedLong> out(new ManagedLong());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedLong::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->active.get()) {
    to_value_result->SetWithoutPathExpansion("Active", std::make_unique<base::Value>(*this->active));

  }
  if (this->effective.get()) {
    to_value_result->SetWithoutPathExpansion("Effective", std::make_unique<base::Value>(*this->effective));

  }
  if (this->user_policy.get()) {
    to_value_result->SetWithoutPathExpansion("UserPolicy", std::make_unique<base::Value>(*this->user_policy));

  }
  if (this->device_policy.get()) {
    to_value_result->SetWithoutPathExpansion("DevicePolicy", std::make_unique<base::Value>(*this->device_policy));

  }
  if (this->user_setting.get()) {
    to_value_result->SetWithoutPathExpansion("UserSetting", std::make_unique<base::Value>(*this->user_setting));

  }
  if (this->shared_setting.get()) {
    to_value_result->SetWithoutPathExpansion("SharedSetting", std::make_unique<base::Value>(*this->shared_setting));

  }
  if (this->user_editable.get()) {
    to_value_result->SetWithoutPathExpansion("UserEditable", std::make_unique<base::Value>(*this->user_editable));

  }
  if (this->device_editable.get()) {
    to_value_result->SetWithoutPathExpansion("DeviceEditable", std::make_unique<base::Value>(*this->device_editable));

  }

  return to_value_result;
}


ManagedDOMString::ManagedDOMString()
 {}

ManagedDOMString::~ManagedDOMString() {}
ManagedDOMString::ManagedDOMString(ManagedDOMString&& rhs)
: active(std::move(rhs.active)),
effective(std::move(rhs.effective)),
user_policy(std::move(rhs.user_policy)),
device_policy(std::move(rhs.device_policy)),
user_setting(std::move(rhs.user_setting)),
shared_setting(std::move(rhs.shared_setting)),
user_editable(std::move(rhs.user_editable)),
device_editable(std::move(rhs.device_editable)){
}

ManagedDOMString& ManagedDOMString::operator=(ManagedDOMString&& rhs)
{
active = std::move(rhs.active);
effective = std::move(rhs.effective);
user_policy = std::move(rhs.user_policy);
device_policy = std::move(rhs.device_policy);
user_setting = std::move(rhs.user_setting);
shared_setting = std::move(rhs.shared_setting);
user_editable = std::move(rhs.user_editable);
device_editable = std::move(rhs.device_editable);
return *this;
}

// static
bool ManagedDOMString::Populate(
    const base::Value& value, ManagedDOMString* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("Active", &active_value)) {
    {
      std::string temp;
      if (!active_value->GetAsString(&temp)) {
        out->active.reset();
        return false;
      }
      else
        out->active.reset(new std::string(temp));
    }
  }

  const base::Value* effective_value = NULL;
  if (dict->GetWithoutPathExpansion("Effective", &effective_value)) {
    {
      std::string temp;
      if (!effective_value->GetAsString(&temp)) {
        out->effective.reset();
        return false;
      }
      else
        out->effective.reset(new std::string(temp));
    }
  }

  const base::Value* user_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("UserPolicy", &user_policy_value)) {
    {
      std::string temp;
      if (!user_policy_value->GetAsString(&temp)) {
        out->user_policy.reset();
        return false;
      }
      else
        out->user_policy.reset(new std::string(temp));
    }
  }

  const base::Value* device_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("DevicePolicy", &device_policy_value)) {
    {
      std::string temp;
      if (!device_policy_value->GetAsString(&temp)) {
        out->device_policy.reset();
        return false;
      }
      else
        out->device_policy.reset(new std::string(temp));
    }
  }

  const base::Value* user_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("UserSetting", &user_setting_value)) {
    {
      std::string temp;
      if (!user_setting_value->GetAsString(&temp)) {
        out->user_setting.reset();
        return false;
      }
      else
        out->user_setting.reset(new std::string(temp));
    }
  }

  const base::Value* shared_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("SharedSetting", &shared_setting_value)) {
    {
      std::string temp;
      if (!shared_setting_value->GetAsString(&temp)) {
        out->shared_setting.reset();
        return false;
      }
      else
        out->shared_setting.reset(new std::string(temp));
    }
  }

  const base::Value* user_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("UserEditable", &user_editable_value)) {
    {
      bool temp;
      if (!user_editable_value->GetAsBoolean(&temp)) {
        out->user_editable.reset();
        return false;
      }
      else
        out->user_editable.reset(new bool(temp));
    }
  }

  const base::Value* device_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("DeviceEditable", &device_editable_value)) {
    {
      bool temp;
      if (!device_editable_value->GetAsBoolean(&temp)) {
        out->device_editable.reset();
        return false;
      }
      else
        out->device_editable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedDOMString> ManagedDOMString::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedDOMString> out(new ManagedDOMString());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedDOMString::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->active.get()) {
    to_value_result->SetWithoutPathExpansion("Active", std::make_unique<base::Value>(*this->active));

  }
  if (this->effective.get()) {
    to_value_result->SetWithoutPathExpansion("Effective", std::make_unique<base::Value>(*this->effective));

  }
  if (this->user_policy.get()) {
    to_value_result->SetWithoutPathExpansion("UserPolicy", std::make_unique<base::Value>(*this->user_policy));

  }
  if (this->device_policy.get()) {
    to_value_result->SetWithoutPathExpansion("DevicePolicy", std::make_unique<base::Value>(*this->device_policy));

  }
  if (this->user_setting.get()) {
    to_value_result->SetWithoutPathExpansion("UserSetting", std::make_unique<base::Value>(*this->user_setting));

  }
  if (this->shared_setting.get()) {
    to_value_result->SetWithoutPathExpansion("SharedSetting", std::make_unique<base::Value>(*this->shared_setting));

  }
  if (this->user_editable.get()) {
    to_value_result->SetWithoutPathExpansion("UserEditable", std::make_unique<base::Value>(*this->user_editable));

  }
  if (this->device_editable.get()) {
    to_value_result->SetWithoutPathExpansion("DeviceEditable", std::make_unique<base::Value>(*this->device_editable));

  }

  return to_value_result;
}


ManagedDOMStringList::ManagedDOMStringList()
 {}

ManagedDOMStringList::~ManagedDOMStringList() {}
ManagedDOMStringList::ManagedDOMStringList(ManagedDOMStringList&& rhs)
: active(std::move(rhs.active)),
effective(std::move(rhs.effective)),
user_policy(std::move(rhs.user_policy)),
device_policy(std::move(rhs.device_policy)),
user_setting(std::move(rhs.user_setting)),
shared_setting(std::move(rhs.shared_setting)),
user_editable(std::move(rhs.user_editable)),
device_editable(std::move(rhs.device_editable)){
}

ManagedDOMStringList& ManagedDOMStringList::operator=(ManagedDOMStringList&& rhs)
{
active = std::move(rhs.active);
effective = std::move(rhs.effective);
user_policy = std::move(rhs.user_policy);
device_policy = std::move(rhs.device_policy);
user_setting = std::move(rhs.user_setting);
shared_setting = std::move(rhs.shared_setting);
user_editable = std::move(rhs.user_editable);
device_editable = std::move(rhs.device_editable);
return *this;
}

// static
bool ManagedDOMStringList::Populate(
    const base::Value& value, ManagedDOMStringList* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("Active", &active_value)) {
    {
      const base::ListValue* list = NULL;
      if (!active_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->active)) {
          return false;
        }
      }
    }
  }

  const base::Value* effective_value = NULL;
  if (dict->GetWithoutPathExpansion("Effective", &effective_value)) {
    {
      std::string temp;
      if (!effective_value->GetAsString(&temp)) {
        out->effective.reset();
        return false;
      }
      else
        out->effective.reset(new std::string(temp));
    }
  }

  const base::Value* user_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("UserPolicy", &user_policy_value)) {
    {
      const base::ListValue* list = NULL;
      if (!user_policy_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->user_policy)) {
          return false;
        }
      }
    }
  }

  const base::Value* device_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("DevicePolicy", &device_policy_value)) {
    {
      const base::ListValue* list = NULL;
      if (!device_policy_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->device_policy)) {
          return false;
        }
      }
    }
  }

  const base::Value* user_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("UserSetting", &user_setting_value)) {
    {
      const base::ListValue* list = NULL;
      if (!user_setting_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->user_setting)) {
          return false;
        }
      }
    }
  }

  const base::Value* shared_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("SharedSetting", &shared_setting_value)) {
    {
      const base::ListValue* list = NULL;
      if (!shared_setting_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->shared_setting)) {
          return false;
        }
      }
    }
  }

  const base::Value* user_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("UserEditable", &user_editable_value)) {
    {
      bool temp;
      if (!user_editable_value->GetAsBoolean(&temp)) {
        out->user_editable.reset();
        return false;
      }
      else
        out->user_editable.reset(new bool(temp));
    }
  }

  const base::Value* device_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("DeviceEditable", &device_editable_value)) {
    {
      bool temp;
      if (!device_editable_value->GetAsBoolean(&temp)) {
        out->device_editable.reset();
        return false;
      }
      else
        out->device_editable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedDOMStringList> ManagedDOMStringList::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedDOMStringList> out(new ManagedDOMStringList());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedDOMStringList::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->active.get()) {
    to_value_result->SetWithoutPathExpansion("Active", json_schema_compiler::util::CreateValueFromOptionalArray(this->active));

  }
  if (this->effective.get()) {
    to_value_result->SetWithoutPathExpansion("Effective", std::make_unique<base::Value>(*this->effective));

  }
  if (this->user_policy.get()) {
    to_value_result->SetWithoutPathExpansion("UserPolicy", json_schema_compiler::util::CreateValueFromOptionalArray(this->user_policy));

  }
  if (this->device_policy.get()) {
    to_value_result->SetWithoutPathExpansion("DevicePolicy", json_schema_compiler::util::CreateValueFromOptionalArray(this->device_policy));

  }
  if (this->user_setting.get()) {
    to_value_result->SetWithoutPathExpansion("UserSetting", json_schema_compiler::util::CreateValueFromOptionalArray(this->user_setting));

  }
  if (this->shared_setting.get()) {
    to_value_result->SetWithoutPathExpansion("SharedSetting", json_schema_compiler::util::CreateValueFromOptionalArray(this->shared_setting));

  }
  if (this->user_editable.get()) {
    to_value_result->SetWithoutPathExpansion("UserEditable", std::make_unique<base::Value>(*this->user_editable));

  }
  if (this->device_editable.get()) {
    to_value_result->SetWithoutPathExpansion("DeviceEditable", std::make_unique<base::Value>(*this->device_editable));

  }

  return to_value_result;
}


ManagedIPConfigType::ManagedIPConfigType()
: active(IP_CONFIG_TYPE_NONE),
user_policy(IP_CONFIG_TYPE_NONE),
device_policy(IP_CONFIG_TYPE_NONE),
user_setting(IP_CONFIG_TYPE_NONE),
shared_setting(IP_CONFIG_TYPE_NONE) {}

ManagedIPConfigType::~ManagedIPConfigType() {}
ManagedIPConfigType::ManagedIPConfigType(ManagedIPConfigType&& rhs)
: active(rhs.active),
effective(std::move(rhs.effective)),
user_policy(rhs.user_policy),
device_policy(rhs.device_policy),
user_setting(rhs.user_setting),
shared_setting(rhs.shared_setting),
user_editable(std::move(rhs.user_editable)),
device_editable(std::move(rhs.device_editable)){
}

ManagedIPConfigType& ManagedIPConfigType::operator=(ManagedIPConfigType&& rhs)
{
active = rhs.active;
effective = std::move(rhs.effective);
user_policy = rhs.user_policy;
device_policy = rhs.device_policy;
user_setting = rhs.user_setting;
shared_setting = rhs.shared_setting;
user_editable = std::move(rhs.user_editable);
device_editable = std::move(rhs.device_editable);
return *this;
}

// static
bool ManagedIPConfigType::Populate(
    const base::Value& value, ManagedIPConfigType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->active = IP_CONFIG_TYPE_NONE;
  out->user_policy = IP_CONFIG_TYPE_NONE;
  out->device_policy = IP_CONFIG_TYPE_NONE;
  out->user_setting = IP_CONFIG_TYPE_NONE;
  out->shared_setting = IP_CONFIG_TYPE_NONE;
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("Active", &active_value)) {
    {
      std::string ip_config_type_as_string;
      if (!active_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->active = ParseIPConfigType(ip_config_type_as_string);
      if (out->active == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->active = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* effective_value = NULL;
  if (dict->GetWithoutPathExpansion("Effective", &effective_value)) {
    {
      std::string temp;
      if (!effective_value->GetAsString(&temp)) {
        out->effective.reset();
        return false;
      }
      else
        out->effective.reset(new std::string(temp));
    }
  }

  const base::Value* user_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("UserPolicy", &user_policy_value)) {
    {
      std::string ip_config_type_as_string;
      if (!user_policy_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->user_policy = ParseIPConfigType(ip_config_type_as_string);
      if (out->user_policy == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->user_policy = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* device_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("DevicePolicy", &device_policy_value)) {
    {
      std::string ip_config_type_as_string;
      if (!device_policy_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->device_policy = ParseIPConfigType(ip_config_type_as_string);
      if (out->device_policy == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->device_policy = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* user_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("UserSetting", &user_setting_value)) {
    {
      std::string ip_config_type_as_string;
      if (!user_setting_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->user_setting = ParseIPConfigType(ip_config_type_as_string);
      if (out->user_setting == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->user_setting = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* shared_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("SharedSetting", &shared_setting_value)) {
    {
      std::string ip_config_type_as_string;
      if (!shared_setting_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->shared_setting = ParseIPConfigType(ip_config_type_as_string);
      if (out->shared_setting == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->shared_setting = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* user_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("UserEditable", &user_editable_value)) {
    {
      bool temp;
      if (!user_editable_value->GetAsBoolean(&temp)) {
        out->user_editable.reset();
        return false;
      }
      else
        out->user_editable.reset(new bool(temp));
    }
  }

  const base::Value* device_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("DeviceEditable", &device_editable_value)) {
    {
      bool temp;
      if (!device_editable_value->GetAsBoolean(&temp)) {
        out->device_editable.reset();
        return false;
      }
      else
        out->device_editable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedIPConfigType> ManagedIPConfigType::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedIPConfigType> out(new ManagedIPConfigType());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedIPConfigType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->active != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("Active", std::make_unique<base::Value>(networking_private::ToString(this->active)));

  }
  if (this->effective.get()) {
    to_value_result->SetWithoutPathExpansion("Effective", std::make_unique<base::Value>(*this->effective));

  }
  if (this->user_policy != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("UserPolicy", std::make_unique<base::Value>(networking_private::ToString(this->user_policy)));

  }
  if (this->device_policy != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("DevicePolicy", std::make_unique<base::Value>(networking_private::ToString(this->device_policy)));

  }
  if (this->user_setting != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("UserSetting", std::make_unique<base::Value>(networking_private::ToString(this->user_setting)));

  }
  if (this->shared_setting != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("SharedSetting", std::make_unique<base::Value>(networking_private::ToString(this->shared_setting)));

  }
  if (this->user_editable.get()) {
    to_value_result->SetWithoutPathExpansion("UserEditable", std::make_unique<base::Value>(*this->user_editable));

  }
  if (this->device_editable.get()) {
    to_value_result->SetWithoutPathExpansion("DeviceEditable", std::make_unique<base::Value>(*this->device_editable));

  }

  return to_value_result;
}


ManagedProxySettingsType::ManagedProxySettingsType()
: active(PROXY_SETTINGS_TYPE_NONE),
user_policy(PROXY_SETTINGS_TYPE_NONE),
device_policy(PROXY_SETTINGS_TYPE_NONE),
user_setting(PROXY_SETTINGS_TYPE_NONE),
shared_setting(PROXY_SETTINGS_TYPE_NONE) {}

ManagedProxySettingsType::~ManagedProxySettingsType() {}
ManagedProxySettingsType::ManagedProxySettingsType(ManagedProxySettingsType&& rhs)
: active(rhs.active),
effective(std::move(rhs.effective)),
user_policy(rhs.user_policy),
device_policy(rhs.device_policy),
user_setting(rhs.user_setting),
shared_setting(rhs.shared_setting),
user_editable(std::move(rhs.user_editable)),
device_editable(std::move(rhs.device_editable)){
}

ManagedProxySettingsType& ManagedProxySettingsType::operator=(ManagedProxySettingsType&& rhs)
{
active = rhs.active;
effective = std::move(rhs.effective);
user_policy = rhs.user_policy;
device_policy = rhs.device_policy;
user_setting = rhs.user_setting;
shared_setting = rhs.shared_setting;
user_editable = std::move(rhs.user_editable);
device_editable = std::move(rhs.device_editable);
return *this;
}

// static
bool ManagedProxySettingsType::Populate(
    const base::Value& value, ManagedProxySettingsType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->active = PROXY_SETTINGS_TYPE_NONE;
  out->user_policy = PROXY_SETTINGS_TYPE_NONE;
  out->device_policy = PROXY_SETTINGS_TYPE_NONE;
  out->user_setting = PROXY_SETTINGS_TYPE_NONE;
  out->shared_setting = PROXY_SETTINGS_TYPE_NONE;
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("Active", &active_value)) {
    {
      std::string proxy_settings_type_as_string;
      if (!active_value->GetAsString(&proxy_settings_type_as_string)) {
        return false;
      }
      out->active = ParseProxySettingsType(proxy_settings_type_as_string);
      if (out->active == PROXY_SETTINGS_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->active = PROXY_SETTINGS_TYPE_NONE;
  }

  const base::Value* effective_value = NULL;
  if (dict->GetWithoutPathExpansion("Effective", &effective_value)) {
    {
      std::string temp;
      if (!effective_value->GetAsString(&temp)) {
        out->effective.reset();
        return false;
      }
      else
        out->effective.reset(new std::string(temp));
    }
  }

  const base::Value* user_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("UserPolicy", &user_policy_value)) {
    {
      std::string proxy_settings_type_as_string;
      if (!user_policy_value->GetAsString(&proxy_settings_type_as_string)) {
        return false;
      }
      out->user_policy = ParseProxySettingsType(proxy_settings_type_as_string);
      if (out->user_policy == PROXY_SETTINGS_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->user_policy = PROXY_SETTINGS_TYPE_NONE;
  }

  const base::Value* device_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("DevicePolicy", &device_policy_value)) {
    {
      std::string proxy_settings_type_as_string;
      if (!device_policy_value->GetAsString(&proxy_settings_type_as_string)) {
        return false;
      }
      out->device_policy = ParseProxySettingsType(proxy_settings_type_as_string);
      if (out->device_policy == PROXY_SETTINGS_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->device_policy = PROXY_SETTINGS_TYPE_NONE;
  }

  const base::Value* user_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("UserSetting", &user_setting_value)) {
    {
      std::string proxy_settings_type_as_string;
      if (!user_setting_value->GetAsString(&proxy_settings_type_as_string)) {
        return false;
      }
      out->user_setting = ParseProxySettingsType(proxy_settings_type_as_string);
      if (out->user_setting == PROXY_SETTINGS_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->user_setting = PROXY_SETTINGS_TYPE_NONE;
  }

  const base::Value* shared_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("SharedSetting", &shared_setting_value)) {
    {
      std::string proxy_settings_type_as_string;
      if (!shared_setting_value->GetAsString(&proxy_settings_type_as_string)) {
        return false;
      }
      out->shared_setting = ParseProxySettingsType(proxy_settings_type_as_string);
      if (out->shared_setting == PROXY_SETTINGS_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->shared_setting = PROXY_SETTINGS_TYPE_NONE;
  }

  const base::Value* user_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("UserEditable", &user_editable_value)) {
    {
      bool temp;
      if (!user_editable_value->GetAsBoolean(&temp)) {
        out->user_editable.reset();
        return false;
      }
      else
        out->user_editable.reset(new bool(temp));
    }
  }

  const base::Value* device_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("DeviceEditable", &device_editable_value)) {
    {
      bool temp;
      if (!device_editable_value->GetAsBoolean(&temp)) {
        out->device_editable.reset();
        return false;
      }
      else
        out->device_editable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedProxySettingsType> ManagedProxySettingsType::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedProxySettingsType> out(new ManagedProxySettingsType());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedProxySettingsType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->active != PROXY_SETTINGS_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("Active", std::make_unique<base::Value>(networking_private::ToString(this->active)));

  }
  if (this->effective.get()) {
    to_value_result->SetWithoutPathExpansion("Effective", std::make_unique<base::Value>(*this->effective));

  }
  if (this->user_policy != PROXY_SETTINGS_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("UserPolicy", std::make_unique<base::Value>(networking_private::ToString(this->user_policy)));

  }
  if (this->device_policy != PROXY_SETTINGS_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("DevicePolicy", std::make_unique<base::Value>(networking_private::ToString(this->device_policy)));

  }
  if (this->user_setting != PROXY_SETTINGS_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("UserSetting", std::make_unique<base::Value>(networking_private::ToString(this->user_setting)));

  }
  if (this->shared_setting != PROXY_SETTINGS_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("SharedSetting", std::make_unique<base::Value>(networking_private::ToString(this->shared_setting)));

  }
  if (this->user_editable.get()) {
    to_value_result->SetWithoutPathExpansion("UserEditable", std::make_unique<base::Value>(*this->user_editable));

  }
  if (this->device_editable.get()) {
    to_value_result->SetWithoutPathExpansion("DeviceEditable", std::make_unique<base::Value>(*this->device_editable));

  }

  return to_value_result;
}


APNProperties::APNProperties()
 {}

APNProperties::~APNProperties() {}
APNProperties::APNProperties(APNProperties&& rhs)
: access_point_name(std::move(rhs.access_point_name)),
authentication(std::move(rhs.authentication)),
language(std::move(rhs.language)),
localized_name(std::move(rhs.localized_name)),
name(std::move(rhs.name)),
password(std::move(rhs.password)),
username(std::move(rhs.username)){
}

APNProperties& APNProperties::operator=(APNProperties&& rhs)
{
access_point_name = std::move(rhs.access_point_name);
authentication = std::move(rhs.authentication);
language = std::move(rhs.language);
localized_name = std::move(rhs.localized_name);
name = std::move(rhs.name);
password = std::move(rhs.password);
username = std::move(rhs.username);
return *this;
}

// static
bool APNProperties::Populate(
    const base::Value& value, APNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* access_point_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("AccessPointName", &access_point_name_value)) {
    return false;
  }
  {
    if (!access_point_name_value->GetAsString(&out->access_point_name)) {
      return false;
    }
  }

  const base::Value* authentication_value = NULL;
  if (dict->GetWithoutPathExpansion("Authentication", &authentication_value)) {
    {
      std::string temp;
      if (!authentication_value->GetAsString(&temp)) {
        out->authentication.reset();
        return false;
      }
      else
        out->authentication.reset(new std::string(temp));
    }
  }

  const base::Value* language_value = NULL;
  if (dict->GetWithoutPathExpansion("Language", &language_value)) {
    {
      std::string temp;
      if (!language_value->GetAsString(&temp)) {
        out->language.reset();
        return false;
      }
      else
        out->language.reset(new std::string(temp));
    }
  }

  const base::Value* localized_name_value = NULL;
  if (dict->GetWithoutPathExpansion("LocalizedName", &localized_name_value)) {
    {
      std::string temp;
      if (!localized_name_value->GetAsString(&temp)) {
        out->localized_name.reset();
        return false;
      }
      else
        out->localized_name.reset(new std::string(temp));
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      std::string temp;
      if (!password_value->GetAsString(&temp)) {
        out->password.reset();
        return false;
      }
      else
        out->password.reset(new std::string(temp));
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      std::string temp;
      if (!username_value->GetAsString(&temp)) {
        out->username.reset();
        return false;
      }
      else
        out->username.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<APNProperties> APNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<APNProperties> out(new APNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> APNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("AccessPointName", std::make_unique<base::Value>(this->access_point_name));

  if (this->authentication.get()) {
    to_value_result->SetWithoutPathExpansion("Authentication", std::make_unique<base::Value>(*this->authentication));

  }
  if (this->language.get()) {
    to_value_result->SetWithoutPathExpansion("Language", std::make_unique<base::Value>(*this->language));

  }
  if (this->localized_name.get()) {
    to_value_result->SetWithoutPathExpansion("LocalizedName", std::make_unique<base::Value>(*this->localized_name));

  }
  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", std::make_unique<base::Value>(*this->name));

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", std::make_unique<base::Value>(*this->password));

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", std::make_unique<base::Value>(*this->username));

  }

  return to_value_result;
}


ManagedAPNProperties::ManagedAPNProperties()
 {}

ManagedAPNProperties::~ManagedAPNProperties() {}
ManagedAPNProperties::ManagedAPNProperties(ManagedAPNProperties&& rhs)
: access_point_name(std::move(rhs.access_point_name)),
authentication(std::move(rhs.authentication)),
language(std::move(rhs.language)),
localized_name(std::move(rhs.localized_name)),
name(std::move(rhs.name)),
password(std::move(rhs.password)),
username(std::move(rhs.username)){
}

ManagedAPNProperties& ManagedAPNProperties::operator=(ManagedAPNProperties&& rhs)
{
access_point_name = std::move(rhs.access_point_name);
authentication = std::move(rhs.authentication);
language = std::move(rhs.language);
localized_name = std::move(rhs.localized_name);
name = std::move(rhs.name);
password = std::move(rhs.password);
username = std::move(rhs.username);
return *this;
}

// static
bool ManagedAPNProperties::Populate(
    const base::Value& value, ManagedAPNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* access_point_name_value = NULL;
  if (!dict->GetWithoutPathExpansion("AccessPointName", &access_point_name_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!access_point_name_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ManagedDOMString::Populate(*dictionary, &out->access_point_name)) {
      return false;
    }
  }

  const base::Value* authentication_value = NULL;
  if (dict->GetWithoutPathExpansion("Authentication", &authentication_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!authentication_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->authentication = std::move(temp);
      }
    }
  }

  const base::Value* language_value = NULL;
  if (dict->GetWithoutPathExpansion("Language", &language_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!language_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->language = std::move(temp);
      }
    }
  }

  const base::Value* localized_name_value = NULL;
  if (dict->GetWithoutPathExpansion("LocalizedName", &localized_name_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!localized_name_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->localized_name = std::move(temp);
      }
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!name_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->name = std::move(temp);
      }
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!password_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->password = std::move(temp);
      }
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!username_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->username = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedAPNProperties> ManagedAPNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedAPNProperties> out(new ManagedAPNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedAPNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("AccessPointName", (this->access_point_name).ToValue());

  if (this->authentication.get()) {
    to_value_result->SetWithoutPathExpansion("Authentication", (this->authentication)->ToValue());

  }
  if (this->language.get()) {
    to_value_result->SetWithoutPathExpansion("Language", (this->language)->ToValue());

  }
  if (this->localized_name.get()) {
    to_value_result->SetWithoutPathExpansion("LocalizedName", (this->localized_name)->ToValue());

  }
  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", (this->name)->ToValue());

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", (this->password)->ToValue());

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", (this->username)->ToValue());

  }

  return to_value_result;
}


ManagedAPNList::ManagedAPNList()
 {}

ManagedAPNList::~ManagedAPNList() {}
ManagedAPNList::ManagedAPNList(ManagedAPNList&& rhs)
: active(std::move(rhs.active)),
effective(std::move(rhs.effective)),
user_policy(std::move(rhs.user_policy)),
device_policy(std::move(rhs.device_policy)),
user_setting(std::move(rhs.user_setting)),
shared_setting(std::move(rhs.shared_setting)),
user_editable(std::move(rhs.user_editable)),
device_editable(std::move(rhs.device_editable)){
}

ManagedAPNList& ManagedAPNList::operator=(ManagedAPNList&& rhs)
{
active = std::move(rhs.active);
effective = std::move(rhs.effective);
user_policy = std::move(rhs.user_policy);
device_policy = std::move(rhs.device_policy);
user_setting = std::move(rhs.user_setting);
shared_setting = std::move(rhs.shared_setting);
user_editable = std::move(rhs.user_editable);
device_editable = std::move(rhs.device_editable);
return *this;
}

// static
bool ManagedAPNList::Populate(
    const base::Value& value, ManagedAPNList* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* active_value = NULL;
  if (dict->GetWithoutPathExpansion("Active", &active_value)) {
    {
      const base::ListValue* list = NULL;
      if (!active_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->active)) {
          return false;
        }
      }
    }
  }

  const base::Value* effective_value = NULL;
  if (dict->GetWithoutPathExpansion("Effective", &effective_value)) {
    {
      std::string temp;
      if (!effective_value->GetAsString(&temp)) {
        out->effective.reset();
        return false;
      }
      else
        out->effective.reset(new std::string(temp));
    }
  }

  const base::Value* user_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("UserPolicy", &user_policy_value)) {
    {
      const base::ListValue* list = NULL;
      if (!user_policy_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->user_policy)) {
          return false;
        }
      }
    }
  }

  const base::Value* device_policy_value = NULL;
  if (dict->GetWithoutPathExpansion("DevicePolicy", &device_policy_value)) {
    {
      const base::ListValue* list = NULL;
      if (!device_policy_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->device_policy)) {
          return false;
        }
      }
    }
  }

  const base::Value* user_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("UserSetting", &user_setting_value)) {
    {
      const base::ListValue* list = NULL;
      if (!user_setting_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->user_setting)) {
          return false;
        }
      }
    }
  }

  const base::Value* shared_setting_value = NULL;
  if (dict->GetWithoutPathExpansion("SharedSetting", &shared_setting_value)) {
    {
      const base::ListValue* list = NULL;
      if (!shared_setting_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->shared_setting)) {
          return false;
        }
      }
    }
  }

  const base::Value* user_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("UserEditable", &user_editable_value)) {
    {
      bool temp;
      if (!user_editable_value->GetAsBoolean(&temp)) {
        out->user_editable.reset();
        return false;
      }
      else
        out->user_editable.reset(new bool(temp));
    }
  }

  const base::Value* device_editable_value = NULL;
  if (dict->GetWithoutPathExpansion("DeviceEditable", &device_editable_value)) {
    {
      bool temp;
      if (!device_editable_value->GetAsBoolean(&temp)) {
        out->device_editable.reset();
        return false;
      }
      else
        out->device_editable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedAPNList> ManagedAPNList::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedAPNList> out(new ManagedAPNList());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedAPNList::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->active.get()) {
    to_value_result->SetWithoutPathExpansion("Active", json_schema_compiler::util::CreateValueFromOptionalArray(this->active));

  }
  if (this->effective.get()) {
    to_value_result->SetWithoutPathExpansion("Effective", std::make_unique<base::Value>(*this->effective));

  }
  if (this->user_policy.get()) {
    to_value_result->SetWithoutPathExpansion("UserPolicy", json_schema_compiler::util::CreateValueFromOptionalArray(this->user_policy));

  }
  if (this->device_policy.get()) {
    to_value_result->SetWithoutPathExpansion("DevicePolicy", json_schema_compiler::util::CreateValueFromOptionalArray(this->device_policy));

  }
  if (this->user_setting.get()) {
    to_value_result->SetWithoutPathExpansion("UserSetting", json_schema_compiler::util::CreateValueFromOptionalArray(this->user_setting));

  }
  if (this->shared_setting.get()) {
    to_value_result->SetWithoutPathExpansion("SharedSetting", json_schema_compiler::util::CreateValueFromOptionalArray(this->shared_setting));

  }
  if (this->user_editable.get()) {
    to_value_result->SetWithoutPathExpansion("UserEditable", std::make_unique<base::Value>(*this->user_editable));

  }
  if (this->device_editable.get()) {
    to_value_result->SetWithoutPathExpansion("DeviceEditable", std::make_unique<base::Value>(*this->device_editable));

  }

  return to_value_result;
}


CellularProviderProperties::CellularProviderProperties()
 {}

CellularProviderProperties::~CellularProviderProperties() {}
CellularProviderProperties::CellularProviderProperties(CellularProviderProperties&& rhs)
: name(std::move(rhs.name)),
code(std::move(rhs.code)),
country(std::move(rhs.country)){
}

CellularProviderProperties& CellularProviderProperties::operator=(CellularProviderProperties&& rhs)
{
name = std::move(rhs.name);
code = std::move(rhs.code);
country = std::move(rhs.country);
return *this;
}

// static
bool CellularProviderProperties::Populate(
    const base::Value& value, CellularProviderProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("Name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* code_value = NULL;
  if (!dict->GetWithoutPathExpansion("Code", &code_value)) {
    return false;
  }
  {
    if (!code_value->GetAsString(&out->code)) {
      return false;
    }
  }

  const base::Value* country_value = NULL;
  if (dict->GetWithoutPathExpansion("Country", &country_value)) {
    {
      std::string temp;
      if (!country_value->GetAsString(&temp)) {
        out->country.reset();
        return false;
      }
      else
        out->country.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<CellularProviderProperties> CellularProviderProperties::FromValue(const base::Value& value) {
  std::unique_ptr<CellularProviderProperties> out(new CellularProviderProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CellularProviderProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("Code", std::make_unique<base::Value>(this->code));

  if (this->country.get()) {
    to_value_result->SetWithoutPathExpansion("Country", std::make_unique<base::Value>(*this->country));

  }

  return to_value_result;
}


CellularSimState::CellularSimState()
: require_pin(false) {}

CellularSimState::~CellularSimState() {}
CellularSimState::CellularSimState(CellularSimState&& rhs)
: require_pin(rhs.require_pin),
current_pin(std::move(rhs.current_pin)),
new_pin(std::move(rhs.new_pin)){
}

CellularSimState& CellularSimState::operator=(CellularSimState&& rhs)
{
require_pin = rhs.require_pin;
current_pin = std::move(rhs.current_pin);
new_pin = std::move(rhs.new_pin);
return *this;
}

// static
bool CellularSimState::Populate(
    const base::Value& value, CellularSimState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* require_pin_value = NULL;
  if (!dict->GetWithoutPathExpansion("requirePin", &require_pin_value)) {
    return false;
  }
  {
    if (!require_pin_value->GetAsBoolean(&out->require_pin)) {
      return false;
    }
  }

  const base::Value* current_pin_value = NULL;
  if (!dict->GetWithoutPathExpansion("currentPin", &current_pin_value)) {
    return false;
  }
  {
    if (!current_pin_value->GetAsString(&out->current_pin)) {
      return false;
    }
  }

  const base::Value* new_pin_value = NULL;
  if (dict->GetWithoutPathExpansion("newPin", &new_pin_value)) {
    {
      std::string temp;
      if (!new_pin_value->GetAsString(&temp)) {
        out->new_pin.reset();
        return false;
      }
      else
        out->new_pin.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<CellularSimState> CellularSimState::FromValue(const base::Value& value) {
  std::unique_ptr<CellularSimState> out(new CellularSimState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CellularSimState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("requirePin", std::make_unique<base::Value>(this->require_pin));

  to_value_result->SetWithoutPathExpansion("currentPin", std::make_unique<base::Value>(this->current_pin));

  if (this->new_pin.get()) {
    to_value_result->SetWithoutPathExpansion("newPin", std::make_unique<base::Value>(*this->new_pin));

  }

  return to_value_result;
}


IssuerSubjectPattern::IssuerSubjectPattern()
 {}

IssuerSubjectPattern::~IssuerSubjectPattern() {}
IssuerSubjectPattern::IssuerSubjectPattern(IssuerSubjectPattern&& rhs)
: common_name(std::move(rhs.common_name)),
locality(std::move(rhs.locality)),
organization(std::move(rhs.organization)),
organizational_unit(std::move(rhs.organizational_unit)){
}

IssuerSubjectPattern& IssuerSubjectPattern::operator=(IssuerSubjectPattern&& rhs)
{
common_name = std::move(rhs.common_name);
locality = std::move(rhs.locality);
organization = std::move(rhs.organization);
organizational_unit = std::move(rhs.organizational_unit);
return *this;
}

// static
bool IssuerSubjectPattern::Populate(
    const base::Value& value, IssuerSubjectPattern* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* common_name_value = NULL;
  if (dict->GetWithoutPathExpansion("CommonName", &common_name_value)) {
    {
      std::string temp;
      if (!common_name_value->GetAsString(&temp)) {
        out->common_name.reset();
        return false;
      }
      else
        out->common_name.reset(new std::string(temp));
    }
  }

  const base::Value* locality_value = NULL;
  if (dict->GetWithoutPathExpansion("Locality", &locality_value)) {
    {
      std::string temp;
      if (!locality_value->GetAsString(&temp)) {
        out->locality.reset();
        return false;
      }
      else
        out->locality.reset(new std::string(temp));
    }
  }

  const base::Value* organization_value = NULL;
  if (dict->GetWithoutPathExpansion("Organization", &organization_value)) {
    {
      std::string temp;
      if (!organization_value->GetAsString(&temp)) {
        out->organization.reset();
        return false;
      }
      else
        out->organization.reset(new std::string(temp));
    }
  }

  const base::Value* organizational_unit_value = NULL;
  if (dict->GetWithoutPathExpansion("OrganizationalUnit", &organizational_unit_value)) {
    {
      std::string temp;
      if (!organizational_unit_value->GetAsString(&temp)) {
        out->organizational_unit.reset();
        return false;
      }
      else
        out->organizational_unit.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<IssuerSubjectPattern> IssuerSubjectPattern::FromValue(const base::Value& value) {
  std::unique_ptr<IssuerSubjectPattern> out(new IssuerSubjectPattern());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> IssuerSubjectPattern::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->common_name.get()) {
    to_value_result->SetWithoutPathExpansion("CommonName", std::make_unique<base::Value>(*this->common_name));

  }
  if (this->locality.get()) {
    to_value_result->SetWithoutPathExpansion("Locality", std::make_unique<base::Value>(*this->locality));

  }
  if (this->organization.get()) {
    to_value_result->SetWithoutPathExpansion("Organization", std::make_unique<base::Value>(*this->organization));

  }
  if (this->organizational_unit.get()) {
    to_value_result->SetWithoutPathExpansion("OrganizationalUnit", std::make_unique<base::Value>(*this->organizational_unit));

  }

  return to_value_result;
}


ManagedIssuerSubjectPattern::ManagedIssuerSubjectPattern()
 {}

ManagedIssuerSubjectPattern::~ManagedIssuerSubjectPattern() {}
ManagedIssuerSubjectPattern::ManagedIssuerSubjectPattern(ManagedIssuerSubjectPattern&& rhs)
: common_name(std::move(rhs.common_name)),
locality(std::move(rhs.locality)),
organization(std::move(rhs.organization)),
organizational_unit(std::move(rhs.organizational_unit)){
}

ManagedIssuerSubjectPattern& ManagedIssuerSubjectPattern::operator=(ManagedIssuerSubjectPattern&& rhs)
{
common_name = std::move(rhs.common_name);
locality = std::move(rhs.locality);
organization = std::move(rhs.organization);
organizational_unit = std::move(rhs.organizational_unit);
return *this;
}

// static
bool ManagedIssuerSubjectPattern::Populate(
    const base::Value& value, ManagedIssuerSubjectPattern* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* common_name_value = NULL;
  if (dict->GetWithoutPathExpansion("CommonName", &common_name_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!common_name_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->common_name = std::move(temp);
      }
    }
  }

  const base::Value* locality_value = NULL;
  if (dict->GetWithoutPathExpansion("Locality", &locality_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!locality_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->locality = std::move(temp);
      }
    }
  }

  const base::Value* organization_value = NULL;
  if (dict->GetWithoutPathExpansion("Organization", &organization_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!organization_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->organization = std::move(temp);
      }
    }
  }

  const base::Value* organizational_unit_value = NULL;
  if (dict->GetWithoutPathExpansion("OrganizationalUnit", &organizational_unit_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!organizational_unit_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->organizational_unit = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedIssuerSubjectPattern> ManagedIssuerSubjectPattern::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedIssuerSubjectPattern> out(new ManagedIssuerSubjectPattern());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedIssuerSubjectPattern::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->common_name.get()) {
    to_value_result->SetWithoutPathExpansion("CommonName", (this->common_name)->ToValue());

  }
  if (this->locality.get()) {
    to_value_result->SetWithoutPathExpansion("Locality", (this->locality)->ToValue());

  }
  if (this->organization.get()) {
    to_value_result->SetWithoutPathExpansion("Organization", (this->organization)->ToValue());

  }
  if (this->organizational_unit.get()) {
    to_value_result->SetWithoutPathExpansion("OrganizationalUnit", (this->organizational_unit)->ToValue());

  }

  return to_value_result;
}


CertificatePattern::CertificatePattern()
 {}

CertificatePattern::~CertificatePattern() {}
CertificatePattern::CertificatePattern(CertificatePattern&& rhs)
: enrollment_uri(std::move(rhs.enrollment_uri)),
issuer(std::move(rhs.issuer)),
issuer_cape_ms(std::move(rhs.issuer_cape_ms)),
issuer_ca_ref(std::move(rhs.issuer_ca_ref)),
subject(std::move(rhs.subject)){
}

CertificatePattern& CertificatePattern::operator=(CertificatePattern&& rhs)
{
enrollment_uri = std::move(rhs.enrollment_uri);
issuer = std::move(rhs.issuer);
issuer_cape_ms = std::move(rhs.issuer_cape_ms);
issuer_ca_ref = std::move(rhs.issuer_ca_ref);
subject = std::move(rhs.subject);
return *this;
}

// static
bool CertificatePattern::Populate(
    const base::Value& value, CertificatePattern* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* enrollment_uri_value = NULL;
  if (dict->GetWithoutPathExpansion("EnrollmentURI", &enrollment_uri_value)) {
    {
      const base::ListValue* list = NULL;
      if (!enrollment_uri_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->enrollment_uri)) {
          return false;
        }
      }
    }
  }

  const base::Value* issuer_value = NULL;
  if (dict->GetWithoutPathExpansion("Issuer", &issuer_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!issuer_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IssuerSubjectPattern> temp(new IssuerSubjectPattern());
        if (!IssuerSubjectPattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->issuer = std::move(temp);
      }
    }
  }

  const base::Value* issuer_cape_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("IssuerCAPEMs", &issuer_cape_ms_value)) {
    {
      const base::ListValue* list = NULL;
      if (!issuer_cape_ms_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->issuer_cape_ms)) {
          return false;
        }
      }
    }
  }

  const base::Value* issuer_ca_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("IssuerCARef", &issuer_ca_ref_value)) {
    {
      const base::ListValue* list = NULL;
      if (!issuer_ca_ref_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->issuer_ca_ref)) {
          return false;
        }
      }
    }
  }

  const base::Value* subject_value = NULL;
  if (dict->GetWithoutPathExpansion("Subject", &subject_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!subject_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IssuerSubjectPattern> temp(new IssuerSubjectPattern());
        if (!IssuerSubjectPattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->subject = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<CertificatePattern> CertificatePattern::FromValue(const base::Value& value) {
  std::unique_ptr<CertificatePattern> out(new CertificatePattern());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CertificatePattern::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->enrollment_uri.get()) {
    to_value_result->SetWithoutPathExpansion("EnrollmentURI", json_schema_compiler::util::CreateValueFromOptionalArray(this->enrollment_uri));

  }
  if (this->issuer.get()) {
    to_value_result->SetWithoutPathExpansion("Issuer", (this->issuer)->ToValue());

  }
  if (this->issuer_cape_ms.get()) {
    to_value_result->SetWithoutPathExpansion("IssuerCAPEMs", json_schema_compiler::util::CreateValueFromOptionalArray(this->issuer_cape_ms));

  }
  if (this->issuer_ca_ref.get()) {
    to_value_result->SetWithoutPathExpansion("IssuerCARef", json_schema_compiler::util::CreateValueFromOptionalArray(this->issuer_ca_ref));

  }
  if (this->subject.get()) {
    to_value_result->SetWithoutPathExpansion("Subject", (this->subject)->ToValue());

  }

  return to_value_result;
}


ManagedCertificatePattern::ManagedCertificatePattern()
 {}

ManagedCertificatePattern::~ManagedCertificatePattern() {}
ManagedCertificatePattern::ManagedCertificatePattern(ManagedCertificatePattern&& rhs)
: enrollment_uri(std::move(rhs.enrollment_uri)),
issuer(std::move(rhs.issuer)),
issuer_ca_ref(std::move(rhs.issuer_ca_ref)),
subject(std::move(rhs.subject)){
}

ManagedCertificatePattern& ManagedCertificatePattern::operator=(ManagedCertificatePattern&& rhs)
{
enrollment_uri = std::move(rhs.enrollment_uri);
issuer = std::move(rhs.issuer);
issuer_ca_ref = std::move(rhs.issuer_ca_ref);
subject = std::move(rhs.subject);
return *this;
}

// static
bool ManagedCertificatePattern::Populate(
    const base::Value& value, ManagedCertificatePattern* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* enrollment_uri_value = NULL;
  if (dict->GetWithoutPathExpansion("EnrollmentURI", &enrollment_uri_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!enrollment_uri_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->enrollment_uri = std::move(temp);
      }
    }
  }

  const base::Value* issuer_value = NULL;
  if (dict->GetWithoutPathExpansion("Issuer", &issuer_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!issuer_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedIssuerSubjectPattern> temp(new ManagedIssuerSubjectPattern());
        if (!ManagedIssuerSubjectPattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->issuer = std::move(temp);
      }
    }
  }

  const base::Value* issuer_ca_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("IssuerCARef", &issuer_ca_ref_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!issuer_ca_ref_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->issuer_ca_ref = std::move(temp);
      }
    }
  }

  const base::Value* subject_value = NULL;
  if (dict->GetWithoutPathExpansion("Subject", &subject_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!subject_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedIssuerSubjectPattern> temp(new ManagedIssuerSubjectPattern());
        if (!ManagedIssuerSubjectPattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->subject = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedCertificatePattern> ManagedCertificatePattern::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedCertificatePattern> out(new ManagedCertificatePattern());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedCertificatePattern::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->enrollment_uri.get()) {
    to_value_result->SetWithoutPathExpansion("EnrollmentURI", (this->enrollment_uri)->ToValue());

  }
  if (this->issuer.get()) {
    to_value_result->SetWithoutPathExpansion("Issuer", (this->issuer)->ToValue());

  }
  if (this->issuer_ca_ref.get()) {
    to_value_result->SetWithoutPathExpansion("IssuerCARef", (this->issuer_ca_ref)->ToValue());

  }
  if (this->subject.get()) {
    to_value_result->SetWithoutPathExpansion("Subject", (this->subject)->ToValue());

  }

  return to_value_result;
}


EAPProperties::EAPProperties()
 {}

EAPProperties::~EAPProperties() {}
EAPProperties::EAPProperties(EAPProperties&& rhs)
: anonymous_identity(std::move(rhs.anonymous_identity)),
client_cert_pattern(std::move(rhs.client_cert_pattern)),
client_cert_pkcs11_id(std::move(rhs.client_cert_pkcs11_id)),
client_cert_ref(std::move(rhs.client_cert_ref)),
client_cert_type(std::move(rhs.client_cert_type)),
identity(std::move(rhs.identity)),
inner(std::move(rhs.inner)),
outer(std::move(rhs.outer)),
password(std::move(rhs.password)),
save_credentials(std::move(rhs.save_credentials)),
server_cape_ms(std::move(rhs.server_cape_ms)),
server_ca_refs(std::move(rhs.server_ca_refs)),
subject_match(std::move(rhs.subject_match)),
tls_version_max(std::move(rhs.tls_version_max)),
use_proactive_key_caching(std::move(rhs.use_proactive_key_caching)),
use_system_c_as(std::move(rhs.use_system_c_as)){
}

EAPProperties& EAPProperties::operator=(EAPProperties&& rhs)
{
anonymous_identity = std::move(rhs.anonymous_identity);
client_cert_pattern = std::move(rhs.client_cert_pattern);
client_cert_pkcs11_id = std::move(rhs.client_cert_pkcs11_id);
client_cert_ref = std::move(rhs.client_cert_ref);
client_cert_type = std::move(rhs.client_cert_type);
identity = std::move(rhs.identity);
inner = std::move(rhs.inner);
outer = std::move(rhs.outer);
password = std::move(rhs.password);
save_credentials = std::move(rhs.save_credentials);
server_cape_ms = std::move(rhs.server_cape_ms);
server_ca_refs = std::move(rhs.server_ca_refs);
subject_match = std::move(rhs.subject_match);
tls_version_max = std::move(rhs.tls_version_max);
use_proactive_key_caching = std::move(rhs.use_proactive_key_caching);
use_system_c_as = std::move(rhs.use_system_c_as);
return *this;
}

// static
bool EAPProperties::Populate(
    const base::Value& value, EAPProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* anonymous_identity_value = NULL;
  if (dict->GetWithoutPathExpansion("AnonymousIdentity", &anonymous_identity_value)) {
    {
      std::string temp;
      if (!anonymous_identity_value->GetAsString(&temp)) {
        out->anonymous_identity.reset();
        return false;
      }
      else
        out->anonymous_identity.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_pattern_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPattern", &client_cert_pattern_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pattern_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CertificatePattern> temp(new CertificatePattern());
        if (!CertificatePattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pattern = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_pkcs11_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPKCS11Id", &client_cert_pkcs11_id_value)) {
    {
      std::string temp;
      if (!client_cert_pkcs11_id_value->GetAsString(&temp)) {
        out->client_cert_pkcs11_id.reset();
        return false;
      }
      else
        out->client_cert_pkcs11_id.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertRef", &client_cert_ref_value)) {
    {
      std::string temp;
      if (!client_cert_ref_value->GetAsString(&temp)) {
        out->client_cert_ref.reset();
        return false;
      }
      else
        out->client_cert_ref.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertType", &client_cert_type_value)) {
    {
      std::string temp;
      if (!client_cert_type_value->GetAsString(&temp)) {
        out->client_cert_type.reset();
        return false;
      }
      else
        out->client_cert_type.reset(new std::string(temp));
    }
  }

  const base::Value* identity_value = NULL;
  if (dict->GetWithoutPathExpansion("Identity", &identity_value)) {
    {
      std::string temp;
      if (!identity_value->GetAsString(&temp)) {
        out->identity.reset();
        return false;
      }
      else
        out->identity.reset(new std::string(temp));
    }
  }

  const base::Value* inner_value = NULL;
  if (dict->GetWithoutPathExpansion("Inner", &inner_value)) {
    {
      std::string temp;
      if (!inner_value->GetAsString(&temp)) {
        out->inner.reset();
        return false;
      }
      else
        out->inner.reset(new std::string(temp));
    }
  }

  const base::Value* outer_value = NULL;
  if (dict->GetWithoutPathExpansion("Outer", &outer_value)) {
    {
      std::string temp;
      if (!outer_value->GetAsString(&temp)) {
        out->outer.reset();
        return false;
      }
      else
        out->outer.reset(new std::string(temp));
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      std::string temp;
      if (!password_value->GetAsString(&temp)) {
        out->password.reset();
        return false;
      }
      else
        out->password.reset(new std::string(temp));
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      bool temp;
      if (!save_credentials_value->GetAsBoolean(&temp)) {
        out->save_credentials.reset();
        return false;
      }
      else
        out->save_credentials.reset(new bool(temp));
    }
  }

  const base::Value* server_cape_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCAPEMs", &server_cape_ms_value)) {
    {
      const base::ListValue* list = NULL;
      if (!server_cape_ms_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->server_cape_ms)) {
          return false;
        }
      }
    }
  }

  const base::Value* server_ca_refs_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCARefs", &server_ca_refs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!server_ca_refs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->server_ca_refs)) {
          return false;
        }
      }
    }
  }

  const base::Value* subject_match_value = NULL;
  if (dict->GetWithoutPathExpansion("SubjectMatch", &subject_match_value)) {
    {
      std::string temp;
      if (!subject_match_value->GetAsString(&temp)) {
        out->subject_match.reset();
        return false;
      }
      else
        out->subject_match.reset(new std::string(temp));
    }
  }

  const base::Value* tls_version_max_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSVersionMax", &tls_version_max_value)) {
    {
      std::string temp;
      if (!tls_version_max_value->GetAsString(&temp)) {
        out->tls_version_max.reset();
        return false;
      }
      else
        out->tls_version_max.reset(new std::string(temp));
    }
  }

  const base::Value* use_proactive_key_caching_value = NULL;
  if (dict->GetWithoutPathExpansion("UseProactiveKeyCaching", &use_proactive_key_caching_value)) {
    {
      bool temp;
      if (!use_proactive_key_caching_value->GetAsBoolean(&temp)) {
        out->use_proactive_key_caching.reset();
        return false;
      }
      else
        out->use_proactive_key_caching.reset(new bool(temp));
    }
  }

  const base::Value* use_system_c_as_value = NULL;
  if (dict->GetWithoutPathExpansion("UseSystemCAs", &use_system_c_as_value)) {
    {
      bool temp;
      if (!use_system_c_as_value->GetAsBoolean(&temp)) {
        out->use_system_c_as.reset();
        return false;
      }
      else
        out->use_system_c_as.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<EAPProperties> EAPProperties::FromValue(const base::Value& value) {
  std::unique_ptr<EAPProperties> out(new EAPProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EAPProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->anonymous_identity.get()) {
    to_value_result->SetWithoutPathExpansion("AnonymousIdentity", std::make_unique<base::Value>(*this->anonymous_identity));

  }
  if (this->client_cert_pattern.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPattern", (this->client_cert_pattern)->ToValue());

  }
  if (this->client_cert_pkcs11_id.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPKCS11Id", std::make_unique<base::Value>(*this->client_cert_pkcs11_id));

  }
  if (this->client_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertRef", std::make_unique<base::Value>(*this->client_cert_ref));

  }
  if (this->client_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertType", std::make_unique<base::Value>(*this->client_cert_type));

  }
  if (this->identity.get()) {
    to_value_result->SetWithoutPathExpansion("Identity", std::make_unique<base::Value>(*this->identity));

  }
  if (this->inner.get()) {
    to_value_result->SetWithoutPathExpansion("Inner", std::make_unique<base::Value>(*this->inner));

  }
  if (this->outer.get()) {
    to_value_result->SetWithoutPathExpansion("Outer", std::make_unique<base::Value>(*this->outer));

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", std::make_unique<base::Value>(*this->password));

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", std::make_unique<base::Value>(*this->save_credentials));

  }
  if (this->server_cape_ms.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCAPEMs", json_schema_compiler::util::CreateValueFromOptionalArray(this->server_cape_ms));

  }
  if (this->server_ca_refs.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCARefs", json_schema_compiler::util::CreateValueFromOptionalArray(this->server_ca_refs));

  }
  if (this->subject_match.get()) {
    to_value_result->SetWithoutPathExpansion("SubjectMatch", std::make_unique<base::Value>(*this->subject_match));

  }
  if (this->tls_version_max.get()) {
    to_value_result->SetWithoutPathExpansion("TLSVersionMax", std::make_unique<base::Value>(*this->tls_version_max));

  }
  if (this->use_proactive_key_caching.get()) {
    to_value_result->SetWithoutPathExpansion("UseProactiveKeyCaching", std::make_unique<base::Value>(*this->use_proactive_key_caching));

  }
  if (this->use_system_c_as.get()) {
    to_value_result->SetWithoutPathExpansion("UseSystemCAs", std::make_unique<base::Value>(*this->use_system_c_as));

  }

  return to_value_result;
}


ManagedEAPProperties::ManagedEAPProperties()
 {}

ManagedEAPProperties::~ManagedEAPProperties() {}
ManagedEAPProperties::ManagedEAPProperties(ManagedEAPProperties&& rhs)
: anonymous_identity(std::move(rhs.anonymous_identity)),
client_cert_pattern(std::move(rhs.client_cert_pattern)),
client_cert_pkcs11_id(std::move(rhs.client_cert_pkcs11_id)),
client_cert_ref(std::move(rhs.client_cert_ref)),
client_cert_type(std::move(rhs.client_cert_type)),
identity(std::move(rhs.identity)),
inner(std::move(rhs.inner)),
outer(std::move(rhs.outer)),
password(std::move(rhs.password)),
save_credentials(std::move(rhs.save_credentials)),
server_cape_ms(std::move(rhs.server_cape_ms)),
server_ca_refs(std::move(rhs.server_ca_refs)),
subject_match(std::move(rhs.subject_match)),
tls_version_max(std::move(rhs.tls_version_max)),
use_proactive_key_caching(std::move(rhs.use_proactive_key_caching)),
use_system_c_as(std::move(rhs.use_system_c_as)){
}

ManagedEAPProperties& ManagedEAPProperties::operator=(ManagedEAPProperties&& rhs)
{
anonymous_identity = std::move(rhs.anonymous_identity);
client_cert_pattern = std::move(rhs.client_cert_pattern);
client_cert_pkcs11_id = std::move(rhs.client_cert_pkcs11_id);
client_cert_ref = std::move(rhs.client_cert_ref);
client_cert_type = std::move(rhs.client_cert_type);
identity = std::move(rhs.identity);
inner = std::move(rhs.inner);
outer = std::move(rhs.outer);
password = std::move(rhs.password);
save_credentials = std::move(rhs.save_credentials);
server_cape_ms = std::move(rhs.server_cape_ms);
server_ca_refs = std::move(rhs.server_ca_refs);
subject_match = std::move(rhs.subject_match);
tls_version_max = std::move(rhs.tls_version_max);
use_proactive_key_caching = std::move(rhs.use_proactive_key_caching);
use_system_c_as = std::move(rhs.use_system_c_as);
return *this;
}

// static
bool ManagedEAPProperties::Populate(
    const base::Value& value, ManagedEAPProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* anonymous_identity_value = NULL;
  if (dict->GetWithoutPathExpansion("AnonymousIdentity", &anonymous_identity_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!anonymous_identity_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->anonymous_identity = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_pattern_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPattern", &client_cert_pattern_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pattern_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedCertificatePattern> temp(new ManagedCertificatePattern());
        if (!ManagedCertificatePattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pattern = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_pkcs11_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPKCS11Id", &client_cert_pkcs11_id_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pkcs11_id_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pkcs11_id = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertRef", &client_cert_ref_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_ref_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_ref = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertType", &client_cert_type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_type = std::move(temp);
      }
    }
  }

  const base::Value* identity_value = NULL;
  if (dict->GetWithoutPathExpansion("Identity", &identity_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!identity_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->identity = std::move(temp);
      }
    }
  }

  const base::Value* inner_value = NULL;
  if (dict->GetWithoutPathExpansion("Inner", &inner_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!inner_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->inner = std::move(temp);
      }
    }
  }

  const base::Value* outer_value = NULL;
  if (dict->GetWithoutPathExpansion("Outer", &outer_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!outer_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->outer = std::move(temp);
      }
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!password_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->password = std::move(temp);
      }
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!save_credentials_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->save_credentials = std::move(temp);
      }
    }
  }

  const base::Value* server_cape_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCAPEMs", &server_cape_ms_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_cape_ms_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_cape_ms = std::move(temp);
      }
    }
  }

  const base::Value* server_ca_refs_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCARefs", &server_ca_refs_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_ca_refs_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_ca_refs = std::move(temp);
      }
    }
  }

  const base::Value* subject_match_value = NULL;
  if (dict->GetWithoutPathExpansion("SubjectMatch", &subject_match_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!subject_match_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->subject_match = std::move(temp);
      }
    }
  }

  const base::Value* tls_version_max_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSVersionMax", &tls_version_max_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tls_version_max_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tls_version_max = std::move(temp);
      }
    }
  }

  const base::Value* use_proactive_key_caching_value = NULL;
  if (dict->GetWithoutPathExpansion("UseProactiveKeyCaching", &use_proactive_key_caching_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!use_proactive_key_caching_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->use_proactive_key_caching = std::move(temp);
      }
    }
  }

  const base::Value* use_system_c_as_value = NULL;
  if (dict->GetWithoutPathExpansion("UseSystemCAs", &use_system_c_as_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!use_system_c_as_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->use_system_c_as = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedEAPProperties> ManagedEAPProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedEAPProperties> out(new ManagedEAPProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedEAPProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->anonymous_identity.get()) {
    to_value_result->SetWithoutPathExpansion("AnonymousIdentity", (this->anonymous_identity)->ToValue());

  }
  if (this->client_cert_pattern.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPattern", (this->client_cert_pattern)->ToValue());

  }
  if (this->client_cert_pkcs11_id.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPKCS11Id", (this->client_cert_pkcs11_id)->ToValue());

  }
  if (this->client_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertRef", (this->client_cert_ref)->ToValue());

  }
  if (this->client_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertType", (this->client_cert_type)->ToValue());

  }
  if (this->identity.get()) {
    to_value_result->SetWithoutPathExpansion("Identity", (this->identity)->ToValue());

  }
  if (this->inner.get()) {
    to_value_result->SetWithoutPathExpansion("Inner", (this->inner)->ToValue());

  }
  if (this->outer.get()) {
    to_value_result->SetWithoutPathExpansion("Outer", (this->outer)->ToValue());

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", (this->password)->ToValue());

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", (this->save_credentials)->ToValue());

  }
  if (this->server_cape_ms.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCAPEMs", (this->server_cape_ms)->ToValue());

  }
  if (this->server_ca_refs.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCARefs", (this->server_ca_refs)->ToValue());

  }
  if (this->subject_match.get()) {
    to_value_result->SetWithoutPathExpansion("SubjectMatch", (this->subject_match)->ToValue());

  }
  if (this->tls_version_max.get()) {
    to_value_result->SetWithoutPathExpansion("TLSVersionMax", (this->tls_version_max)->ToValue());

  }
  if (this->use_proactive_key_caching.get()) {
    to_value_result->SetWithoutPathExpansion("UseProactiveKeyCaching", (this->use_proactive_key_caching)->ToValue());

  }
  if (this->use_system_c_as.get()) {
    to_value_result->SetWithoutPathExpansion("UseSystemCAs", (this->use_system_c_as)->ToValue());

  }

  return to_value_result;
}


FoundNetworkProperties::FoundNetworkProperties()
 {}

FoundNetworkProperties::~FoundNetworkProperties() {}
FoundNetworkProperties::FoundNetworkProperties(FoundNetworkProperties&& rhs)
: status(std::move(rhs.status)),
network_id(std::move(rhs.network_id)),
technology(std::move(rhs.technology)),
short_name(std::move(rhs.short_name)),
long_name(std::move(rhs.long_name)){
}

FoundNetworkProperties& FoundNetworkProperties::operator=(FoundNetworkProperties&& rhs)
{
status = std::move(rhs.status);
network_id = std::move(rhs.network_id);
technology = std::move(rhs.technology);
short_name = std::move(rhs.short_name);
long_name = std::move(rhs.long_name);
return *this;
}

// static
bool FoundNetworkProperties::Populate(
    const base::Value& value, FoundNetworkProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* status_value = NULL;
  if (!dict->GetWithoutPathExpansion("Status", &status_value)) {
    return false;
  }
  {
    if (!status_value->GetAsString(&out->status)) {
      return false;
    }
  }

  const base::Value* network_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("NetworkId", &network_id_value)) {
    return false;
  }
  {
    if (!network_id_value->GetAsString(&out->network_id)) {
      return false;
    }
  }

  const base::Value* technology_value = NULL;
  if (!dict->GetWithoutPathExpansion("Technology", &technology_value)) {
    return false;
  }
  {
    if (!technology_value->GetAsString(&out->technology)) {
      return false;
    }
  }

  const base::Value* short_name_value = NULL;
  if (dict->GetWithoutPathExpansion("ShortName", &short_name_value)) {
    {
      std::string temp;
      if (!short_name_value->GetAsString(&temp)) {
        out->short_name.reset();
        return false;
      }
      else
        out->short_name.reset(new std::string(temp));
    }
  }

  const base::Value* long_name_value = NULL;
  if (dict->GetWithoutPathExpansion("LongName", &long_name_value)) {
    {
      std::string temp;
      if (!long_name_value->GetAsString(&temp)) {
        out->long_name.reset();
        return false;
      }
      else
        out->long_name.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<FoundNetworkProperties> FoundNetworkProperties::FromValue(const base::Value& value) {
  std::unique_ptr<FoundNetworkProperties> out(new FoundNetworkProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FoundNetworkProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Status", std::make_unique<base::Value>(this->status));

  to_value_result->SetWithoutPathExpansion("NetworkId", std::make_unique<base::Value>(this->network_id));

  to_value_result->SetWithoutPathExpansion("Technology", std::make_unique<base::Value>(this->technology));

  if (this->short_name.get()) {
    to_value_result->SetWithoutPathExpansion("ShortName", std::make_unique<base::Value>(*this->short_name));

  }
  if (this->long_name.get()) {
    to_value_result->SetWithoutPathExpansion("LongName", std::make_unique<base::Value>(*this->long_name));

  }

  return to_value_result;
}


IPConfigProperties::IPConfigProperties()
 {}

IPConfigProperties::~IPConfigProperties() {}
IPConfigProperties::IPConfigProperties(IPConfigProperties&& rhs)
: gateway(std::move(rhs.gateway)),
ip_address(std::move(rhs.ip_address)),
excluded_routes(std::move(rhs.excluded_routes)),
included_routes(std::move(rhs.included_routes)),
name_servers(std::move(rhs.name_servers)),
search_domains(std::move(rhs.search_domains)),
routing_prefix(std::move(rhs.routing_prefix)),
type(std::move(rhs.type)),
web_proxy_auto_discovery_url(std::move(rhs.web_proxy_auto_discovery_url)){
}

IPConfigProperties& IPConfigProperties::operator=(IPConfigProperties&& rhs)
{
gateway = std::move(rhs.gateway);
ip_address = std::move(rhs.ip_address);
excluded_routes = std::move(rhs.excluded_routes);
included_routes = std::move(rhs.included_routes);
name_servers = std::move(rhs.name_servers);
search_domains = std::move(rhs.search_domains);
routing_prefix = std::move(rhs.routing_prefix);
type = std::move(rhs.type);
web_proxy_auto_discovery_url = std::move(rhs.web_proxy_auto_discovery_url);
return *this;
}

// static
bool IPConfigProperties::Populate(
    const base::Value& value, IPConfigProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* gateway_value = NULL;
  if (dict->GetWithoutPathExpansion("Gateway", &gateway_value)) {
    {
      std::string temp;
      if (!gateway_value->GetAsString(&temp)) {
        out->gateway.reset();
        return false;
      }
      else
        out->gateway.reset(new std::string(temp));
    }
  }

  const base::Value* ip_address_value = NULL;
  if (dict->GetWithoutPathExpansion("IPAddress", &ip_address_value)) {
    {
      std::string temp;
      if (!ip_address_value->GetAsString(&temp)) {
        out->ip_address.reset();
        return false;
      }
      else
        out->ip_address.reset(new std::string(temp));
    }
  }

  const base::Value* excluded_routes_value = NULL;
  if (dict->GetWithoutPathExpansion("ExcludedRoutes", &excluded_routes_value)) {
    {
      const base::ListValue* list = NULL;
      if (!excluded_routes_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->excluded_routes)) {
          return false;
        }
      }
    }
  }

  const base::Value* included_routes_value = NULL;
  if (dict->GetWithoutPathExpansion("IncludedRoutes", &included_routes_value)) {
    {
      const base::ListValue* list = NULL;
      if (!included_routes_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->included_routes)) {
          return false;
        }
      }
    }
  }

  const base::Value* name_servers_value = NULL;
  if (dict->GetWithoutPathExpansion("NameServers", &name_servers_value)) {
    {
      const base::ListValue* list = NULL;
      if (!name_servers_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->name_servers)) {
          return false;
        }
      }
    }
  }

  const base::Value* search_domains_value = NULL;
  if (dict->GetWithoutPathExpansion("SearchDomains", &search_domains_value)) {
    {
      const base::ListValue* list = NULL;
      if (!search_domains_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->search_domains)) {
          return false;
        }
      }
    }
  }

  const base::Value* routing_prefix_value = NULL;
  if (dict->GetWithoutPathExpansion("RoutingPrefix", &routing_prefix_value)) {
    {
      int temp;
      if (!routing_prefix_value->GetAsInteger(&temp)) {
        out->routing_prefix.reset();
        return false;
      }
      else
        out->routing_prefix.reset(new int(temp));
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("Type", &type_value)) {
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

  const base::Value* web_proxy_auto_discovery_url_value = NULL;
  if (dict->GetWithoutPathExpansion("WebProxyAutoDiscoveryUrl", &web_proxy_auto_discovery_url_value)) {
    {
      std::string temp;
      if (!web_proxy_auto_discovery_url_value->GetAsString(&temp)) {
        out->web_proxy_auto_discovery_url.reset();
        return false;
      }
      else
        out->web_proxy_auto_discovery_url.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<IPConfigProperties> IPConfigProperties::FromValue(const base::Value& value) {
  std::unique_ptr<IPConfigProperties> out(new IPConfigProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> IPConfigProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->gateway.get()) {
    to_value_result->SetWithoutPathExpansion("Gateway", std::make_unique<base::Value>(*this->gateway));

  }
  if (this->ip_address.get()) {
    to_value_result->SetWithoutPathExpansion("IPAddress", std::make_unique<base::Value>(*this->ip_address));

  }
  if (this->excluded_routes.get()) {
    to_value_result->SetWithoutPathExpansion("ExcludedRoutes", json_schema_compiler::util::CreateValueFromOptionalArray(this->excluded_routes));

  }
  if (this->included_routes.get()) {
    to_value_result->SetWithoutPathExpansion("IncludedRoutes", json_schema_compiler::util::CreateValueFromOptionalArray(this->included_routes));

  }
  if (this->name_servers.get()) {
    to_value_result->SetWithoutPathExpansion("NameServers", json_schema_compiler::util::CreateValueFromOptionalArray(this->name_servers));

  }
  if (this->search_domains.get()) {
    to_value_result->SetWithoutPathExpansion("SearchDomains", json_schema_compiler::util::CreateValueFromOptionalArray(this->search_domains));

  }
  if (this->routing_prefix.get()) {
    to_value_result->SetWithoutPathExpansion("RoutingPrefix", std::make_unique<base::Value>(*this->routing_prefix));

  }
  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(*this->type));

  }
  if (this->web_proxy_auto_discovery_url.get()) {
    to_value_result->SetWithoutPathExpansion("WebProxyAutoDiscoveryUrl", std::make_unique<base::Value>(*this->web_proxy_auto_discovery_url));

  }

  return to_value_result;
}


ManagedIPConfigProperties::ManagedIPConfigProperties()
 {}

ManagedIPConfigProperties::~ManagedIPConfigProperties() {}
ManagedIPConfigProperties::ManagedIPConfigProperties(ManagedIPConfigProperties&& rhs)
: gateway(std::move(rhs.gateway)),
ip_address(std::move(rhs.ip_address)),
name_servers(std::move(rhs.name_servers)),
routing_prefix(std::move(rhs.routing_prefix)),
type(std::move(rhs.type)),
web_proxy_auto_discovery_url(std::move(rhs.web_proxy_auto_discovery_url)){
}

ManagedIPConfigProperties& ManagedIPConfigProperties::operator=(ManagedIPConfigProperties&& rhs)
{
gateway = std::move(rhs.gateway);
ip_address = std::move(rhs.ip_address);
name_servers = std::move(rhs.name_servers);
routing_prefix = std::move(rhs.routing_prefix);
type = std::move(rhs.type);
web_proxy_auto_discovery_url = std::move(rhs.web_proxy_auto_discovery_url);
return *this;
}

// static
bool ManagedIPConfigProperties::Populate(
    const base::Value& value, ManagedIPConfigProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* gateway_value = NULL;
  if (dict->GetWithoutPathExpansion("Gateway", &gateway_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!gateway_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->gateway = std::move(temp);
      }
    }
  }

  const base::Value* ip_address_value = NULL;
  if (dict->GetWithoutPathExpansion("IPAddress", &ip_address_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ip_address_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ip_address = std::move(temp);
      }
    }
  }

  const base::Value* name_servers_value = NULL;
  if (dict->GetWithoutPathExpansion("NameServers", &name_servers_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!name_servers_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->name_servers = std::move(temp);
      }
    }
  }

  const base::Value* routing_prefix_value = NULL;
  if (dict->GetWithoutPathExpansion("RoutingPrefix", &routing_prefix_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!routing_prefix_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedLong> temp(new ManagedLong());
        if (!ManagedLong::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->routing_prefix = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("Type", &type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->type = std::move(temp);
      }
    }
  }

  const base::Value* web_proxy_auto_discovery_url_value = NULL;
  if (dict->GetWithoutPathExpansion("WebProxyAutoDiscoveryUrl", &web_proxy_auto_discovery_url_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!web_proxy_auto_discovery_url_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->web_proxy_auto_discovery_url = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedIPConfigProperties> ManagedIPConfigProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedIPConfigProperties> out(new ManagedIPConfigProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedIPConfigProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->gateway.get()) {
    to_value_result->SetWithoutPathExpansion("Gateway", (this->gateway)->ToValue());

  }
  if (this->ip_address.get()) {
    to_value_result->SetWithoutPathExpansion("IPAddress", (this->ip_address)->ToValue());

  }
  if (this->name_servers.get()) {
    to_value_result->SetWithoutPathExpansion("NameServers", (this->name_servers)->ToValue());

  }
  if (this->routing_prefix.get()) {
    to_value_result->SetWithoutPathExpansion("RoutingPrefix", (this->routing_prefix)->ToValue());

  }
  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("Type", (this->type)->ToValue());

  }
  if (this->web_proxy_auto_discovery_url.get()) {
    to_value_result->SetWithoutPathExpansion("WebProxyAutoDiscoveryUrl", (this->web_proxy_auto_discovery_url)->ToValue());

  }

  return to_value_result;
}


XAUTHProperties::XAUTHProperties()
 {}

XAUTHProperties::~XAUTHProperties() {}
XAUTHProperties::XAUTHProperties(XAUTHProperties&& rhs)
: password(std::move(rhs.password)),
save_credentials(std::move(rhs.save_credentials)),
username(std::move(rhs.username)){
}

XAUTHProperties& XAUTHProperties::operator=(XAUTHProperties&& rhs)
{
password = std::move(rhs.password);
save_credentials = std::move(rhs.save_credentials);
username = std::move(rhs.username);
return *this;
}

// static
bool XAUTHProperties::Populate(
    const base::Value& value, XAUTHProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      std::string temp;
      if (!password_value->GetAsString(&temp)) {
        out->password.reset();
        return false;
      }
      else
        out->password.reset(new std::string(temp));
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      bool temp;
      if (!save_credentials_value->GetAsBoolean(&temp)) {
        out->save_credentials.reset();
        return false;
      }
      else
        out->save_credentials.reset(new bool(temp));
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      std::string temp;
      if (!username_value->GetAsString(&temp)) {
        out->username.reset();
        return false;
      }
      else
        out->username.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<XAUTHProperties> XAUTHProperties::FromValue(const base::Value& value) {
  std::unique_ptr<XAUTHProperties> out(new XAUTHProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> XAUTHProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", std::make_unique<base::Value>(*this->password));

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", std::make_unique<base::Value>(*this->save_credentials));

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", std::make_unique<base::Value>(*this->username));

  }

  return to_value_result;
}


ManagedXAUTHProperties::ManagedXAUTHProperties()
 {}

ManagedXAUTHProperties::~ManagedXAUTHProperties() {}
ManagedXAUTHProperties::ManagedXAUTHProperties(ManagedXAUTHProperties&& rhs)
: password(std::move(rhs.password)),
save_credentials(std::move(rhs.save_credentials)),
username(std::move(rhs.username)){
}

ManagedXAUTHProperties& ManagedXAUTHProperties::operator=(ManagedXAUTHProperties&& rhs)
{
password = std::move(rhs.password);
save_credentials = std::move(rhs.save_credentials);
username = std::move(rhs.username);
return *this;
}

// static
bool ManagedXAUTHProperties::Populate(
    const base::Value& value, ManagedXAUTHProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!password_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->password = std::move(temp);
      }
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!save_credentials_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->save_credentials = std::move(temp);
      }
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!username_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->username = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedXAUTHProperties> ManagedXAUTHProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedXAUTHProperties> out(new ManagedXAUTHProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedXAUTHProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", (this->password)->ToValue());

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", (this->save_credentials)->ToValue());

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", (this->username)->ToValue());

  }

  return to_value_result;
}


IPSecProperties::IPSecProperties()
 {}

IPSecProperties::~IPSecProperties() {}
IPSecProperties::IPSecProperties(IPSecProperties&& rhs)
: authentication_type(std::move(rhs.authentication_type)),
client_cert_pattern(std::move(rhs.client_cert_pattern)),
client_cert_pkcs11_id(std::move(rhs.client_cert_pkcs11_id)),
client_cert_ref(std::move(rhs.client_cert_ref)),
client_cert_type(std::move(rhs.client_cert_type)),
eap(std::move(rhs.eap)),
group(std::move(rhs.group)),
ike_version(std::move(rhs.ike_version)),
psk(std::move(rhs.psk)),
save_credentials(std::move(rhs.save_credentials)),
server_cape_ms(std::move(rhs.server_cape_ms)),
server_ca_refs(std::move(rhs.server_ca_refs)),
xauth(std::move(rhs.xauth)){
}

IPSecProperties& IPSecProperties::operator=(IPSecProperties&& rhs)
{
authentication_type = std::move(rhs.authentication_type);
client_cert_pattern = std::move(rhs.client_cert_pattern);
client_cert_pkcs11_id = std::move(rhs.client_cert_pkcs11_id);
client_cert_ref = std::move(rhs.client_cert_ref);
client_cert_type = std::move(rhs.client_cert_type);
eap = std::move(rhs.eap);
group = std::move(rhs.group);
ike_version = std::move(rhs.ike_version);
psk = std::move(rhs.psk);
save_credentials = std::move(rhs.save_credentials);
server_cape_ms = std::move(rhs.server_cape_ms);
server_ca_refs = std::move(rhs.server_ca_refs);
xauth = std::move(rhs.xauth);
return *this;
}

// static
bool IPSecProperties::Populate(
    const base::Value& value, IPSecProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* authentication_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("AuthenticationType", &authentication_type_value)) {
    return false;
  }
  {
    if (!authentication_type_value->GetAsString(&out->authentication_type)) {
      return false;
    }
  }

  const base::Value* client_cert_pattern_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPattern", &client_cert_pattern_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pattern_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CertificatePattern> temp(new CertificatePattern());
        if (!CertificatePattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pattern = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_pkcs11_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPKCS11Id", &client_cert_pkcs11_id_value)) {
    {
      std::string temp;
      if (!client_cert_pkcs11_id_value->GetAsString(&temp)) {
        out->client_cert_pkcs11_id.reset();
        return false;
      }
      else
        out->client_cert_pkcs11_id.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertRef", &client_cert_ref_value)) {
    {
      std::string temp;
      if (!client_cert_ref_value->GetAsString(&temp)) {
        out->client_cert_ref.reset();
        return false;
      }
      else
        out->client_cert_ref.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertType", &client_cert_type_value)) {
    {
      std::string temp;
      if (!client_cert_type_value->GetAsString(&temp)) {
        out->client_cert_type.reset();
        return false;
      }
      else
        out->client_cert_type.reset(new std::string(temp));
    }
  }

  const base::Value* eap_value = NULL;
  if (dict->GetWithoutPathExpansion("EAP", &eap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!eap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<EAPProperties> temp(new EAPProperties());
        if (!EAPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->eap = std::move(temp);
      }
    }
  }

  const base::Value* group_value = NULL;
  if (dict->GetWithoutPathExpansion("Group", &group_value)) {
    {
      std::string temp;
      if (!group_value->GetAsString(&temp)) {
        out->group.reset();
        return false;
      }
      else
        out->group.reset(new std::string(temp));
    }
  }

  const base::Value* ike_version_value = NULL;
  if (dict->GetWithoutPathExpansion("IKEVersion", &ike_version_value)) {
    {
      int temp;
      if (!ike_version_value->GetAsInteger(&temp)) {
        out->ike_version.reset();
        return false;
      }
      else
        out->ike_version.reset(new int(temp));
    }
  }

  const base::Value* psk_value = NULL;
  if (dict->GetWithoutPathExpansion("PSK", &psk_value)) {
    {
      std::string temp;
      if (!psk_value->GetAsString(&temp)) {
        out->psk.reset();
        return false;
      }
      else
        out->psk.reset(new std::string(temp));
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      bool temp;
      if (!save_credentials_value->GetAsBoolean(&temp)) {
        out->save_credentials.reset();
        return false;
      }
      else
        out->save_credentials.reset(new bool(temp));
    }
  }

  const base::Value* server_cape_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCAPEMs", &server_cape_ms_value)) {
    {
      const base::ListValue* list = NULL;
      if (!server_cape_ms_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->server_cape_ms)) {
          return false;
        }
      }
    }
  }

  const base::Value* server_ca_refs_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCARefs", &server_ca_refs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!server_ca_refs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->server_ca_refs)) {
          return false;
        }
      }
    }
  }

  const base::Value* xauth_value = NULL;
  if (dict->GetWithoutPathExpansion("XAUTH", &xauth_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!xauth_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<XAUTHProperties> temp(new XAUTHProperties());
        if (!XAUTHProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->xauth = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<IPSecProperties> IPSecProperties::FromValue(const base::Value& value) {
  std::unique_ptr<IPSecProperties> out(new IPSecProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> IPSecProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("AuthenticationType", std::make_unique<base::Value>(this->authentication_type));

  if (this->client_cert_pattern.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPattern", (this->client_cert_pattern)->ToValue());

  }
  if (this->client_cert_pkcs11_id.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPKCS11Id", std::make_unique<base::Value>(*this->client_cert_pkcs11_id));

  }
  if (this->client_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertRef", std::make_unique<base::Value>(*this->client_cert_ref));

  }
  if (this->client_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertType", std::make_unique<base::Value>(*this->client_cert_type));

  }
  if (this->eap.get()) {
    to_value_result->SetWithoutPathExpansion("EAP", (this->eap)->ToValue());

  }
  if (this->group.get()) {
    to_value_result->SetWithoutPathExpansion("Group", std::make_unique<base::Value>(*this->group));

  }
  if (this->ike_version.get()) {
    to_value_result->SetWithoutPathExpansion("IKEVersion", std::make_unique<base::Value>(*this->ike_version));

  }
  if (this->psk.get()) {
    to_value_result->SetWithoutPathExpansion("PSK", std::make_unique<base::Value>(*this->psk));

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", std::make_unique<base::Value>(*this->save_credentials));

  }
  if (this->server_cape_ms.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCAPEMs", json_schema_compiler::util::CreateValueFromOptionalArray(this->server_cape_ms));

  }
  if (this->server_ca_refs.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCARefs", json_schema_compiler::util::CreateValueFromOptionalArray(this->server_ca_refs));

  }
  if (this->xauth.get()) {
    to_value_result->SetWithoutPathExpansion("XAUTH", (this->xauth)->ToValue());

  }

  return to_value_result;
}


ManagedIPSecProperties::ManagedIPSecProperties()
 {}

ManagedIPSecProperties::~ManagedIPSecProperties() {}
ManagedIPSecProperties::ManagedIPSecProperties(ManagedIPSecProperties&& rhs)
: authentication_type(std::move(rhs.authentication_type)),
client_cert_pattern(std::move(rhs.client_cert_pattern)),
client_cert_pkcs11_id(std::move(rhs.client_cert_pkcs11_id)),
client_cert_ref(std::move(rhs.client_cert_ref)),
client_cert_type(std::move(rhs.client_cert_type)),
eap(std::move(rhs.eap)),
group(std::move(rhs.group)),
ike_version(std::move(rhs.ike_version)),
psk(std::move(rhs.psk)),
save_credentials(std::move(rhs.save_credentials)),
server_cape_ms(std::move(rhs.server_cape_ms)),
server_ca_refs(std::move(rhs.server_ca_refs)),
xauth(std::move(rhs.xauth)){
}

ManagedIPSecProperties& ManagedIPSecProperties::operator=(ManagedIPSecProperties&& rhs)
{
authentication_type = std::move(rhs.authentication_type);
client_cert_pattern = std::move(rhs.client_cert_pattern);
client_cert_pkcs11_id = std::move(rhs.client_cert_pkcs11_id);
client_cert_ref = std::move(rhs.client_cert_ref);
client_cert_type = std::move(rhs.client_cert_type);
eap = std::move(rhs.eap);
group = std::move(rhs.group);
ike_version = std::move(rhs.ike_version);
psk = std::move(rhs.psk);
save_credentials = std::move(rhs.save_credentials);
server_cape_ms = std::move(rhs.server_cape_ms);
server_ca_refs = std::move(rhs.server_ca_refs);
xauth = std::move(rhs.xauth);
return *this;
}

// static
bool ManagedIPSecProperties::Populate(
    const base::Value& value, ManagedIPSecProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* authentication_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("AuthenticationType", &authentication_type_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!authentication_type_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ManagedDOMString::Populate(*dictionary, &out->authentication_type)) {
      return false;
    }
  }

  const base::Value* client_cert_pattern_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPattern", &client_cert_pattern_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pattern_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedCertificatePattern> temp(new ManagedCertificatePattern());
        if (!ManagedCertificatePattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pattern = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_pkcs11_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPKCS11Id", &client_cert_pkcs11_id_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pkcs11_id_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pkcs11_id = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertRef", &client_cert_ref_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_ref_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_ref = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertType", &client_cert_type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_type = std::move(temp);
      }
    }
  }

  const base::Value* eap_value = NULL;
  if (dict->GetWithoutPathExpansion("EAP", &eap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!eap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedEAPProperties> temp(new ManagedEAPProperties());
        if (!ManagedEAPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->eap = std::move(temp);
      }
    }
  }

  const base::Value* group_value = NULL;
  if (dict->GetWithoutPathExpansion("Group", &group_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!group_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->group = std::move(temp);
      }
    }
  }

  const base::Value* ike_version_value = NULL;
  if (dict->GetWithoutPathExpansion("IKEVersion", &ike_version_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ike_version_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedLong> temp(new ManagedLong());
        if (!ManagedLong::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ike_version = std::move(temp);
      }
    }
  }

  const base::Value* psk_value = NULL;
  if (dict->GetWithoutPathExpansion("PSK", &psk_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!psk_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->psk = std::move(temp);
      }
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!save_credentials_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->save_credentials = std::move(temp);
      }
    }
  }

  const base::Value* server_cape_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCAPEMs", &server_cape_ms_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_cape_ms_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_cape_ms = std::move(temp);
      }
    }
  }

  const base::Value* server_ca_refs_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCARefs", &server_ca_refs_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_ca_refs_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_ca_refs = std::move(temp);
      }
    }
  }

  const base::Value* xauth_value = NULL;
  if (dict->GetWithoutPathExpansion("XAUTH", &xauth_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!xauth_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedXAUTHProperties> temp(new ManagedXAUTHProperties());
        if (!ManagedXAUTHProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->xauth = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedIPSecProperties> ManagedIPSecProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedIPSecProperties> out(new ManagedIPSecProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedIPSecProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("AuthenticationType", (this->authentication_type).ToValue());

  if (this->client_cert_pattern.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPattern", (this->client_cert_pattern)->ToValue());

  }
  if (this->client_cert_pkcs11_id.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPKCS11Id", (this->client_cert_pkcs11_id)->ToValue());

  }
  if (this->client_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertRef", (this->client_cert_ref)->ToValue());

  }
  if (this->client_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertType", (this->client_cert_type)->ToValue());

  }
  if (this->eap.get()) {
    to_value_result->SetWithoutPathExpansion("EAP", (this->eap)->ToValue());

  }
  if (this->group.get()) {
    to_value_result->SetWithoutPathExpansion("Group", (this->group)->ToValue());

  }
  if (this->ike_version.get()) {
    to_value_result->SetWithoutPathExpansion("IKEVersion", (this->ike_version)->ToValue());

  }
  if (this->psk.get()) {
    to_value_result->SetWithoutPathExpansion("PSK", (this->psk)->ToValue());

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", (this->save_credentials)->ToValue());

  }
  if (this->server_cape_ms.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCAPEMs", (this->server_cape_ms)->ToValue());

  }
  if (this->server_ca_refs.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCARefs", (this->server_ca_refs)->ToValue());

  }
  if (this->xauth.get()) {
    to_value_result->SetWithoutPathExpansion("XAUTH", (this->xauth)->ToValue());

  }

  return to_value_result;
}


L2TPProperties::L2TPProperties()
 {}

L2TPProperties::~L2TPProperties() {}
L2TPProperties::L2TPProperties(L2TPProperties&& rhs)
: lcp_echo_disabled(std::move(rhs.lcp_echo_disabled)),
password(std::move(rhs.password)),
save_credentials(std::move(rhs.save_credentials)),
username(std::move(rhs.username)){
}

L2TPProperties& L2TPProperties::operator=(L2TPProperties&& rhs)
{
lcp_echo_disabled = std::move(rhs.lcp_echo_disabled);
password = std::move(rhs.password);
save_credentials = std::move(rhs.save_credentials);
username = std::move(rhs.username);
return *this;
}

// static
bool L2TPProperties::Populate(
    const base::Value& value, L2TPProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* lcp_echo_disabled_value = NULL;
  if (dict->GetWithoutPathExpansion("LcpEchoDisabled", &lcp_echo_disabled_value)) {
    {
      bool temp;
      if (!lcp_echo_disabled_value->GetAsBoolean(&temp)) {
        out->lcp_echo_disabled.reset();
        return false;
      }
      else
        out->lcp_echo_disabled.reset(new bool(temp));
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      std::string temp;
      if (!password_value->GetAsString(&temp)) {
        out->password.reset();
        return false;
      }
      else
        out->password.reset(new std::string(temp));
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      bool temp;
      if (!save_credentials_value->GetAsBoolean(&temp)) {
        out->save_credentials.reset();
        return false;
      }
      else
        out->save_credentials.reset(new bool(temp));
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      std::string temp;
      if (!username_value->GetAsString(&temp)) {
        out->username.reset();
        return false;
      }
      else
        out->username.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<L2TPProperties> L2TPProperties::FromValue(const base::Value& value) {
  std::unique_ptr<L2TPProperties> out(new L2TPProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> L2TPProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->lcp_echo_disabled.get()) {
    to_value_result->SetWithoutPathExpansion("LcpEchoDisabled", std::make_unique<base::Value>(*this->lcp_echo_disabled));

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", std::make_unique<base::Value>(*this->password));

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", std::make_unique<base::Value>(*this->save_credentials));

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", std::make_unique<base::Value>(*this->username));

  }

  return to_value_result;
}


ManagedL2TPProperties::ManagedL2TPProperties()
 {}

ManagedL2TPProperties::~ManagedL2TPProperties() {}
ManagedL2TPProperties::ManagedL2TPProperties(ManagedL2TPProperties&& rhs)
: lcp_echo_disabled(std::move(rhs.lcp_echo_disabled)),
password(std::move(rhs.password)),
save_credentials(std::move(rhs.save_credentials)),
username(std::move(rhs.username)){
}

ManagedL2TPProperties& ManagedL2TPProperties::operator=(ManagedL2TPProperties&& rhs)
{
lcp_echo_disabled = std::move(rhs.lcp_echo_disabled);
password = std::move(rhs.password);
save_credentials = std::move(rhs.save_credentials);
username = std::move(rhs.username);
return *this;
}

// static
bool ManagedL2TPProperties::Populate(
    const base::Value& value, ManagedL2TPProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* lcp_echo_disabled_value = NULL;
  if (dict->GetWithoutPathExpansion("LcpEchoDisabled", &lcp_echo_disabled_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!lcp_echo_disabled_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->lcp_echo_disabled = std::move(temp);
      }
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!password_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->password = std::move(temp);
      }
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!save_credentials_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->save_credentials = std::move(temp);
      }
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!username_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->username = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedL2TPProperties> ManagedL2TPProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedL2TPProperties> out(new ManagedL2TPProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedL2TPProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->lcp_echo_disabled.get()) {
    to_value_result->SetWithoutPathExpansion("LcpEchoDisabled", (this->lcp_echo_disabled)->ToValue());

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", (this->password)->ToValue());

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", (this->save_credentials)->ToValue());

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", (this->username)->ToValue());

  }

  return to_value_result;
}


PaymentPortal::PaymentPortal()
 {}

PaymentPortal::~PaymentPortal() {}
PaymentPortal::PaymentPortal(PaymentPortal&& rhs)
: method(std::move(rhs.method)),
post_data(std::move(rhs.post_data)),
url(std::move(rhs.url)){
}

PaymentPortal& PaymentPortal::operator=(PaymentPortal&& rhs)
{
method = std::move(rhs.method);
post_data = std::move(rhs.post_data);
url = std::move(rhs.url);
return *this;
}

// static
bool PaymentPortal::Populate(
    const base::Value& value, PaymentPortal* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* method_value = NULL;
  if (!dict->GetWithoutPathExpansion("Method", &method_value)) {
    return false;
  }
  {
    if (!method_value->GetAsString(&out->method)) {
      return false;
    }
  }

  const base::Value* post_data_value = NULL;
  if (dict->GetWithoutPathExpansion("PostData", &post_data_value)) {
    {
      std::string temp;
      if (!post_data_value->GetAsString(&temp)) {
        out->post_data.reset();
        return false;
      }
      else
        out->post_data.reset(new std::string(temp));
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("Url", &url_value)) {
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

  return true;
}

// static
std::unique_ptr<PaymentPortal> PaymentPortal::FromValue(const base::Value& value) {
  std::unique_ptr<PaymentPortal> out(new PaymentPortal());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PaymentPortal::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Method", std::make_unique<base::Value>(this->method));

  if (this->post_data.get()) {
    to_value_result->SetWithoutPathExpansion("PostData", std::make_unique<base::Value>(*this->post_data));

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("Url", std::make_unique<base::Value>(*this->url));

  }

  return to_value_result;
}


ProxyLocation::ProxyLocation()
: port(0) {}

ProxyLocation::~ProxyLocation() {}
ProxyLocation::ProxyLocation(ProxyLocation&& rhs)
: host(std::move(rhs.host)),
port(rhs.port){
}

ProxyLocation& ProxyLocation::operator=(ProxyLocation&& rhs)
{
host = std::move(rhs.host);
port = rhs.port;
return *this;
}

// static
bool ProxyLocation::Populate(
    const base::Value& value, ProxyLocation* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* host_value = NULL;
  if (!dict->GetWithoutPathExpansion("Host", &host_value)) {
    return false;
  }
  {
    if (!host_value->GetAsString(&out->host)) {
      return false;
    }
  }

  const base::Value* port_value = NULL;
  if (!dict->GetWithoutPathExpansion("Port", &port_value)) {
    return false;
  }
  {
    if (!port_value->GetAsInteger(&out->port)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ProxyLocation> ProxyLocation::FromValue(const base::Value& value) {
  std::unique_ptr<ProxyLocation> out(new ProxyLocation());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ProxyLocation::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Host", std::make_unique<base::Value>(this->host));

  to_value_result->SetWithoutPathExpansion("Port", std::make_unique<base::Value>(this->port));


  return to_value_result;
}


ManagedProxyLocation::ManagedProxyLocation()
 {}

ManagedProxyLocation::~ManagedProxyLocation() {}
ManagedProxyLocation::ManagedProxyLocation(ManagedProxyLocation&& rhs)
: host(std::move(rhs.host)),
port(std::move(rhs.port)){
}

ManagedProxyLocation& ManagedProxyLocation::operator=(ManagedProxyLocation&& rhs)
{
host = std::move(rhs.host);
port = std::move(rhs.port);
return *this;
}

// static
bool ManagedProxyLocation::Populate(
    const base::Value& value, ManagedProxyLocation* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* host_value = NULL;
  if (!dict->GetWithoutPathExpansion("Host", &host_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!host_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ManagedDOMString::Populate(*dictionary, &out->host)) {
      return false;
    }
  }

  const base::Value* port_value = NULL;
  if (!dict->GetWithoutPathExpansion("Port", &port_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!port_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ManagedLong::Populate(*dictionary, &out->port)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedProxyLocation> ManagedProxyLocation::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedProxyLocation> out(new ManagedProxyLocation());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedProxyLocation::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Host", (this->host).ToValue());

  to_value_result->SetWithoutPathExpansion("Port", (this->port).ToValue());


  return to_value_result;
}


ManualProxySettings::ManualProxySettings()
 {}

ManualProxySettings::~ManualProxySettings() {}
ManualProxySettings::ManualProxySettings(ManualProxySettings&& rhs)
: http_proxy(std::move(rhs.http_proxy)),
secure_http_proxy(std::move(rhs.secure_http_proxy)),
ftp_proxy(std::move(rhs.ftp_proxy)),
socks(std::move(rhs.socks)){
}

ManualProxySettings& ManualProxySettings::operator=(ManualProxySettings&& rhs)
{
http_proxy = std::move(rhs.http_proxy);
secure_http_proxy = std::move(rhs.secure_http_proxy);
ftp_proxy = std::move(rhs.ftp_proxy);
socks = std::move(rhs.socks);
return *this;
}

// static
bool ManualProxySettings::Populate(
    const base::Value& value, ManualProxySettings* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* http_proxy_value = NULL;
  if (dict->GetWithoutPathExpansion("HTTPProxy", &http_proxy_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!http_proxy_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ProxyLocation> temp(new ProxyLocation());
        if (!ProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->http_proxy = std::move(temp);
      }
    }
  }

  const base::Value* secure_http_proxy_value = NULL;
  if (dict->GetWithoutPathExpansion("SecureHTTPProxy", &secure_http_proxy_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!secure_http_proxy_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ProxyLocation> temp(new ProxyLocation());
        if (!ProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->secure_http_proxy = std::move(temp);
      }
    }
  }

  const base::Value* ftp_proxy_value = NULL;
  if (dict->GetWithoutPathExpansion("FTPProxy", &ftp_proxy_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ftp_proxy_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ProxyLocation> temp(new ProxyLocation());
        if (!ProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ftp_proxy = std::move(temp);
      }
    }
  }

  const base::Value* socks_value = NULL;
  if (dict->GetWithoutPathExpansion("SOCKS", &socks_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!socks_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ProxyLocation> temp(new ProxyLocation());
        if (!ProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->socks = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManualProxySettings> ManualProxySettings::FromValue(const base::Value& value) {
  std::unique_ptr<ManualProxySettings> out(new ManualProxySettings());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManualProxySettings::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->http_proxy.get()) {
    to_value_result->SetWithoutPathExpansion("HTTPProxy", (this->http_proxy)->ToValue());

  }
  if (this->secure_http_proxy.get()) {
    to_value_result->SetWithoutPathExpansion("SecureHTTPProxy", (this->secure_http_proxy)->ToValue());

  }
  if (this->ftp_proxy.get()) {
    to_value_result->SetWithoutPathExpansion("FTPProxy", (this->ftp_proxy)->ToValue());

  }
  if (this->socks.get()) {
    to_value_result->SetWithoutPathExpansion("SOCKS", (this->socks)->ToValue());

  }

  return to_value_result;
}


ManagedManualProxySettings::ManagedManualProxySettings()
 {}

ManagedManualProxySettings::~ManagedManualProxySettings() {}
ManagedManualProxySettings::ManagedManualProxySettings(ManagedManualProxySettings&& rhs)
: http_proxy(std::move(rhs.http_proxy)),
secure_http_proxy(std::move(rhs.secure_http_proxy)),
ftp_proxy(std::move(rhs.ftp_proxy)),
socks(std::move(rhs.socks)){
}

ManagedManualProxySettings& ManagedManualProxySettings::operator=(ManagedManualProxySettings&& rhs)
{
http_proxy = std::move(rhs.http_proxy);
secure_http_proxy = std::move(rhs.secure_http_proxy);
ftp_proxy = std::move(rhs.ftp_proxy);
socks = std::move(rhs.socks);
return *this;
}

// static
bool ManagedManualProxySettings::Populate(
    const base::Value& value, ManagedManualProxySettings* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* http_proxy_value = NULL;
  if (dict->GetWithoutPathExpansion("HTTPProxy", &http_proxy_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!http_proxy_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedProxyLocation> temp(new ManagedProxyLocation());
        if (!ManagedProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->http_proxy = std::move(temp);
      }
    }
  }

  const base::Value* secure_http_proxy_value = NULL;
  if (dict->GetWithoutPathExpansion("SecureHTTPProxy", &secure_http_proxy_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!secure_http_proxy_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedProxyLocation> temp(new ManagedProxyLocation());
        if (!ManagedProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->secure_http_proxy = std::move(temp);
      }
    }
  }

  const base::Value* ftp_proxy_value = NULL;
  if (dict->GetWithoutPathExpansion("FTPProxy", &ftp_proxy_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ftp_proxy_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedProxyLocation> temp(new ManagedProxyLocation());
        if (!ManagedProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ftp_proxy = std::move(temp);
      }
    }
  }

  const base::Value* socks_value = NULL;
  if (dict->GetWithoutPathExpansion("SOCKS", &socks_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!socks_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedProxyLocation> temp(new ManagedProxyLocation());
        if (!ManagedProxyLocation::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->socks = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedManualProxySettings> ManagedManualProxySettings::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedManualProxySettings> out(new ManagedManualProxySettings());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedManualProxySettings::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->http_proxy.get()) {
    to_value_result->SetWithoutPathExpansion("HTTPProxy", (this->http_proxy)->ToValue());

  }
  if (this->secure_http_proxy.get()) {
    to_value_result->SetWithoutPathExpansion("SecureHTTPProxy", (this->secure_http_proxy)->ToValue());

  }
  if (this->ftp_proxy.get()) {
    to_value_result->SetWithoutPathExpansion("FTPProxy", (this->ftp_proxy)->ToValue());

  }
  if (this->socks.get()) {
    to_value_result->SetWithoutPathExpansion("SOCKS", (this->socks)->ToValue());

  }

  return to_value_result;
}


ProxySettings::ProxySettings()
: type(PROXY_SETTINGS_TYPE_NONE) {}

ProxySettings::~ProxySettings() {}
ProxySettings::ProxySettings(ProxySettings&& rhs)
: type(rhs.type),
manual(std::move(rhs.manual)),
exclude_domains(std::move(rhs.exclude_domains)),
pac(std::move(rhs.pac)){
}

ProxySettings& ProxySettings::operator=(ProxySettings&& rhs)
{
type = rhs.type;
manual = std::move(rhs.manual);
exclude_domains = std::move(rhs.exclude_domains);
pac = std::move(rhs.pac);
return *this;
}

// static
bool ProxySettings::Populate(
    const base::Value& value, ProxySettings* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("Type", &type_value)) {
    return false;
  }
  {
    std::string proxy_settings_type_as_string;
    if (!type_value->GetAsString(&proxy_settings_type_as_string)) {
      return false;
    }
    out->type = ParseProxySettingsType(proxy_settings_type_as_string);
    if (out->type == PROXY_SETTINGS_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* manual_value = NULL;
  if (dict->GetWithoutPathExpansion("Manual", &manual_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!manual_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManualProxySettings> temp(new ManualProxySettings());
        if (!ManualProxySettings::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->manual = std::move(temp);
      }
    }
  }

  const base::Value* exclude_domains_value = NULL;
  if (dict->GetWithoutPathExpansion("ExcludeDomains", &exclude_domains_value)) {
    {
      const base::ListValue* list = NULL;
      if (!exclude_domains_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->exclude_domains)) {
          return false;
        }
      }
    }
  }

  const base::Value* pac_value = NULL;
  if (dict->GetWithoutPathExpansion("PAC", &pac_value)) {
    {
      std::string temp;
      if (!pac_value->GetAsString(&temp)) {
        out->pac.reset();
        return false;
      }
      else
        out->pac.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ProxySettings> ProxySettings::FromValue(const base::Value& value) {
  std::unique_ptr<ProxySettings> out(new ProxySettings());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ProxySettings::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(networking_private::ToString(this->type)));

  if (this->manual.get()) {
    to_value_result->SetWithoutPathExpansion("Manual", (this->manual)->ToValue());

  }
  if (this->exclude_domains.get()) {
    to_value_result->SetWithoutPathExpansion("ExcludeDomains", json_schema_compiler::util::CreateValueFromOptionalArray(this->exclude_domains));

  }
  if (this->pac.get()) {
    to_value_result->SetWithoutPathExpansion("PAC", std::make_unique<base::Value>(*this->pac));

  }

  return to_value_result;
}


ManagedProxySettings::ManagedProxySettings()
 {}

ManagedProxySettings::~ManagedProxySettings() {}
ManagedProxySettings::ManagedProxySettings(ManagedProxySettings&& rhs)
: type(std::move(rhs.type)),
manual(std::move(rhs.manual)),
exclude_domains(std::move(rhs.exclude_domains)),
pac(std::move(rhs.pac)){
}

ManagedProxySettings& ManagedProxySettings::operator=(ManagedProxySettings&& rhs)
{
type = std::move(rhs.type);
manual = std::move(rhs.manual);
exclude_domains = std::move(rhs.exclude_domains);
pac = std::move(rhs.pac);
return *this;
}

// static
bool ManagedProxySettings::Populate(
    const base::Value& value, ManagedProxySettings* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("Type", &type_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!type_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ManagedProxySettingsType::Populate(*dictionary, &out->type)) {
      return false;
    }
  }

  const base::Value* manual_value = NULL;
  if (dict->GetWithoutPathExpansion("Manual", &manual_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!manual_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedManualProxySettings> temp(new ManagedManualProxySettings());
        if (!ManagedManualProxySettings::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->manual = std::move(temp);
      }
    }
  }

  const base::Value* exclude_domains_value = NULL;
  if (dict->GetWithoutPathExpansion("ExcludeDomains", &exclude_domains_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!exclude_domains_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->exclude_domains = std::move(temp);
      }
    }
  }

  const base::Value* pac_value = NULL;
  if (dict->GetWithoutPathExpansion("PAC", &pac_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!pac_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->pac = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedProxySettings> ManagedProxySettings::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedProxySettings> out(new ManagedProxySettings());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedProxySettings::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Type", (this->type).ToValue());

  if (this->manual.get()) {
    to_value_result->SetWithoutPathExpansion("Manual", (this->manual)->ToValue());

  }
  if (this->exclude_domains.get()) {
    to_value_result->SetWithoutPathExpansion("ExcludeDomains", (this->exclude_domains)->ToValue());

  }
  if (this->pac.get()) {
    to_value_result->SetWithoutPathExpansion("PAC", (this->pac)->ToValue());

  }

  return to_value_result;
}


VerifyX509::VerifyX509()
 {}

VerifyX509::~VerifyX509() {}
VerifyX509::VerifyX509(VerifyX509&& rhs)
: name(std::move(rhs.name)),
type(std::move(rhs.type)){
}

VerifyX509& VerifyX509::operator=(VerifyX509&& rhs)
{
name = std::move(rhs.name);
type = std::move(rhs.type);
return *this;
}

// static
bool VerifyX509::Populate(
    const base::Value& value, VerifyX509* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("Type", &type_value)) {
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
std::unique_ptr<VerifyX509> VerifyX509::FromValue(const base::Value& value) {
  std::unique_ptr<VerifyX509> out(new VerifyX509());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> VerifyX509::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", std::make_unique<base::Value>(*this->name));

  }
  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(*this->type));

  }

  return to_value_result;
}


ManagedVerifyX509::ManagedVerifyX509()
 {}

ManagedVerifyX509::~ManagedVerifyX509() {}
ManagedVerifyX509::ManagedVerifyX509(ManagedVerifyX509&& rhs)
: name(std::move(rhs.name)),
type(std::move(rhs.type)){
}

ManagedVerifyX509& ManagedVerifyX509::operator=(ManagedVerifyX509&& rhs)
{
name = std::move(rhs.name);
type = std::move(rhs.type);
return *this;
}

// static
bool ManagedVerifyX509::Populate(
    const base::Value& value, ManagedVerifyX509* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!name_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->name = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("Type", &type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->type = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedVerifyX509> ManagedVerifyX509::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedVerifyX509> out(new ManagedVerifyX509());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedVerifyX509::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", (this->name)->ToValue());

  }
  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("Type", (this->type)->ToValue());

  }

  return to_value_result;
}


OpenVPNProperties::OpenVPNProperties()
 {}

OpenVPNProperties::~OpenVPNProperties() {}
OpenVPNProperties::OpenVPNProperties(OpenVPNProperties&& rhs)
: auth(std::move(rhs.auth)),
auth_retry(std::move(rhs.auth_retry)),
auth_no_cache(std::move(rhs.auth_no_cache)),
cipher(std::move(rhs.cipher)),
client_cert_pkcs11_id(std::move(rhs.client_cert_pkcs11_id)),
client_cert_pattern(std::move(rhs.client_cert_pattern)),
client_cert_ref(std::move(rhs.client_cert_ref)),
client_cert_type(std::move(rhs.client_cert_type)),
comp_lzo(std::move(rhs.comp_lzo)),
comp_no_adapt(std::move(rhs.comp_no_adapt)),
extra_hosts(std::move(rhs.extra_hosts)),
ignore_default_route(std::move(rhs.ignore_default_route)),
key_direction(std::move(rhs.key_direction)),
ns_cert_type(std::move(rhs.ns_cert_type)),
otp(std::move(rhs.otp)),
password(std::move(rhs.password)),
port(std::move(rhs.port)),
proto(std::move(rhs.proto)),
push_peer_info(std::move(rhs.push_peer_info)),
remote_cert_eku(std::move(rhs.remote_cert_eku)),
remote_cert_ku(std::move(rhs.remote_cert_ku)),
remote_cert_tls(std::move(rhs.remote_cert_tls)),
reneg_sec(std::move(rhs.reneg_sec)),
save_credentials(std::move(rhs.save_credentials)),
server_cape_ms(std::move(rhs.server_cape_ms)),
server_ca_refs(std::move(rhs.server_ca_refs)),
server_cert_ref(std::move(rhs.server_cert_ref)),
server_poll_timeout(std::move(rhs.server_poll_timeout)),
shaper(std::move(rhs.shaper)),
static_challenge(std::move(rhs.static_challenge)),
tls_auth_contents(std::move(rhs.tls_auth_contents)),
tls_remote(std::move(rhs.tls_remote)),
tls_version_min(std::move(rhs.tls_version_min)),
user_authentication_type(std::move(rhs.user_authentication_type)),
username(std::move(rhs.username)),
verb(std::move(rhs.verb)),
verify_hash(std::move(rhs.verify_hash)),
verify_x509(std::move(rhs.verify_x509)){
}

OpenVPNProperties& OpenVPNProperties::operator=(OpenVPNProperties&& rhs)
{
auth = std::move(rhs.auth);
auth_retry = std::move(rhs.auth_retry);
auth_no_cache = std::move(rhs.auth_no_cache);
cipher = std::move(rhs.cipher);
client_cert_pkcs11_id = std::move(rhs.client_cert_pkcs11_id);
client_cert_pattern = std::move(rhs.client_cert_pattern);
client_cert_ref = std::move(rhs.client_cert_ref);
client_cert_type = std::move(rhs.client_cert_type);
comp_lzo = std::move(rhs.comp_lzo);
comp_no_adapt = std::move(rhs.comp_no_adapt);
extra_hosts = std::move(rhs.extra_hosts);
ignore_default_route = std::move(rhs.ignore_default_route);
key_direction = std::move(rhs.key_direction);
ns_cert_type = std::move(rhs.ns_cert_type);
otp = std::move(rhs.otp);
password = std::move(rhs.password);
port = std::move(rhs.port);
proto = std::move(rhs.proto);
push_peer_info = std::move(rhs.push_peer_info);
remote_cert_eku = std::move(rhs.remote_cert_eku);
remote_cert_ku = std::move(rhs.remote_cert_ku);
remote_cert_tls = std::move(rhs.remote_cert_tls);
reneg_sec = std::move(rhs.reneg_sec);
save_credentials = std::move(rhs.save_credentials);
server_cape_ms = std::move(rhs.server_cape_ms);
server_ca_refs = std::move(rhs.server_ca_refs);
server_cert_ref = std::move(rhs.server_cert_ref);
server_poll_timeout = std::move(rhs.server_poll_timeout);
shaper = std::move(rhs.shaper);
static_challenge = std::move(rhs.static_challenge);
tls_auth_contents = std::move(rhs.tls_auth_contents);
tls_remote = std::move(rhs.tls_remote);
tls_version_min = std::move(rhs.tls_version_min);
user_authentication_type = std::move(rhs.user_authentication_type);
username = std::move(rhs.username);
verb = std::move(rhs.verb);
verify_hash = std::move(rhs.verify_hash);
verify_x509 = std::move(rhs.verify_x509);
return *this;
}

// static
bool OpenVPNProperties::Populate(
    const base::Value& value, OpenVPNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* auth_value = NULL;
  if (dict->GetWithoutPathExpansion("Auth", &auth_value)) {
    {
      std::string temp;
      if (!auth_value->GetAsString(&temp)) {
        out->auth.reset();
        return false;
      }
      else
        out->auth.reset(new std::string(temp));
    }
  }

  const base::Value* auth_retry_value = NULL;
  if (dict->GetWithoutPathExpansion("AuthRetry", &auth_retry_value)) {
    {
      std::string temp;
      if (!auth_retry_value->GetAsString(&temp)) {
        out->auth_retry.reset();
        return false;
      }
      else
        out->auth_retry.reset(new std::string(temp));
    }
  }

  const base::Value* auth_no_cache_value = NULL;
  if (dict->GetWithoutPathExpansion("AuthNoCache", &auth_no_cache_value)) {
    {
      bool temp;
      if (!auth_no_cache_value->GetAsBoolean(&temp)) {
        out->auth_no_cache.reset();
        return false;
      }
      else
        out->auth_no_cache.reset(new bool(temp));
    }
  }

  const base::Value* cipher_value = NULL;
  if (dict->GetWithoutPathExpansion("Cipher", &cipher_value)) {
    {
      std::string temp;
      if (!cipher_value->GetAsString(&temp)) {
        out->cipher.reset();
        return false;
      }
      else
        out->cipher.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_pkcs11_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPKCS11Id", &client_cert_pkcs11_id_value)) {
    {
      std::string temp;
      if (!client_cert_pkcs11_id_value->GetAsString(&temp)) {
        out->client_cert_pkcs11_id.reset();
        return false;
      }
      else
        out->client_cert_pkcs11_id.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_pattern_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPattern", &client_cert_pattern_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pattern_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CertificatePattern> temp(new CertificatePattern());
        if (!CertificatePattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pattern = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertRef", &client_cert_ref_value)) {
    {
      std::string temp;
      if (!client_cert_ref_value->GetAsString(&temp)) {
        out->client_cert_ref.reset();
        return false;
      }
      else
        out->client_cert_ref.reset(new std::string(temp));
    }
  }

  const base::Value* client_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertType", &client_cert_type_value)) {
    {
      std::string temp;
      if (!client_cert_type_value->GetAsString(&temp)) {
        out->client_cert_type.reset();
        return false;
      }
      else
        out->client_cert_type.reset(new std::string(temp));
    }
  }

  const base::Value* comp_lzo_value = NULL;
  if (dict->GetWithoutPathExpansion("CompLZO", &comp_lzo_value)) {
    {
      std::string temp;
      if (!comp_lzo_value->GetAsString(&temp)) {
        out->comp_lzo.reset();
        return false;
      }
      else
        out->comp_lzo.reset(new std::string(temp));
    }
  }

  const base::Value* comp_no_adapt_value = NULL;
  if (dict->GetWithoutPathExpansion("CompNoAdapt", &comp_no_adapt_value)) {
    {
      bool temp;
      if (!comp_no_adapt_value->GetAsBoolean(&temp)) {
        out->comp_no_adapt.reset();
        return false;
      }
      else
        out->comp_no_adapt.reset(new bool(temp));
    }
  }

  const base::Value* extra_hosts_value = NULL;
  if (dict->GetWithoutPathExpansion("ExtraHosts", &extra_hosts_value)) {
    {
      const base::ListValue* list = NULL;
      if (!extra_hosts_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->extra_hosts)) {
          return false;
        }
      }
    }
  }

  const base::Value* ignore_default_route_value = NULL;
  if (dict->GetWithoutPathExpansion("IgnoreDefaultRoute", &ignore_default_route_value)) {
    {
      bool temp;
      if (!ignore_default_route_value->GetAsBoolean(&temp)) {
        out->ignore_default_route.reset();
        return false;
      }
      else
        out->ignore_default_route.reset(new bool(temp));
    }
  }

  const base::Value* key_direction_value = NULL;
  if (dict->GetWithoutPathExpansion("KeyDirection", &key_direction_value)) {
    {
      std::string temp;
      if (!key_direction_value->GetAsString(&temp)) {
        out->key_direction.reset();
        return false;
      }
      else
        out->key_direction.reset(new std::string(temp));
    }
  }

  const base::Value* ns_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("NsCertType", &ns_cert_type_value)) {
    {
      std::string temp;
      if (!ns_cert_type_value->GetAsString(&temp)) {
        out->ns_cert_type.reset();
        return false;
      }
      else
        out->ns_cert_type.reset(new std::string(temp));
    }
  }

  const base::Value* otp_value = NULL;
  if (dict->GetWithoutPathExpansion("OTP", &otp_value)) {
    {
      std::string temp;
      if (!otp_value->GetAsString(&temp)) {
        out->otp.reset();
        return false;
      }
      else
        out->otp.reset(new std::string(temp));
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      std::string temp;
      if (!password_value->GetAsString(&temp)) {
        out->password.reset();
        return false;
      }
      else
        out->password.reset(new std::string(temp));
    }
  }

  const base::Value* port_value = NULL;
  if (dict->GetWithoutPathExpansion("Port", &port_value)) {
    {
      int temp;
      if (!port_value->GetAsInteger(&temp)) {
        out->port.reset();
        return false;
      }
      else
        out->port.reset(new int(temp));
    }
  }

  const base::Value* proto_value = NULL;
  if (dict->GetWithoutPathExpansion("Proto", &proto_value)) {
    {
      std::string temp;
      if (!proto_value->GetAsString(&temp)) {
        out->proto.reset();
        return false;
      }
      else
        out->proto.reset(new std::string(temp));
    }
  }

  const base::Value* push_peer_info_value = NULL;
  if (dict->GetWithoutPathExpansion("PushPeerInfo", &push_peer_info_value)) {
    {
      bool temp;
      if (!push_peer_info_value->GetAsBoolean(&temp)) {
        out->push_peer_info.reset();
        return false;
      }
      else
        out->push_peer_info.reset(new bool(temp));
    }
  }

  const base::Value* remote_cert_eku_value = NULL;
  if (dict->GetWithoutPathExpansion("RemoteCertEKU", &remote_cert_eku_value)) {
    {
      std::string temp;
      if (!remote_cert_eku_value->GetAsString(&temp)) {
        out->remote_cert_eku.reset();
        return false;
      }
      else
        out->remote_cert_eku.reset(new std::string(temp));
    }
  }

  const base::Value* remote_cert_ku_value = NULL;
  if (dict->GetWithoutPathExpansion("RemoteCertKU", &remote_cert_ku_value)) {
    {
      const base::ListValue* list = NULL;
      if (!remote_cert_ku_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->remote_cert_ku)) {
          return false;
        }
      }
    }
  }

  const base::Value* remote_cert_tls_value = NULL;
  if (dict->GetWithoutPathExpansion("RemoteCertTLS", &remote_cert_tls_value)) {
    {
      std::string temp;
      if (!remote_cert_tls_value->GetAsString(&temp)) {
        out->remote_cert_tls.reset();
        return false;
      }
      else
        out->remote_cert_tls.reset(new std::string(temp));
    }
  }

  const base::Value* reneg_sec_value = NULL;
  if (dict->GetWithoutPathExpansion("RenegSec", &reneg_sec_value)) {
    {
      int temp;
      if (!reneg_sec_value->GetAsInteger(&temp)) {
        out->reneg_sec.reset();
        return false;
      }
      else
        out->reneg_sec.reset(new int(temp));
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      bool temp;
      if (!save_credentials_value->GetAsBoolean(&temp)) {
        out->save_credentials.reset();
        return false;
      }
      else
        out->save_credentials.reset(new bool(temp));
    }
  }

  const base::Value* server_cape_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCAPEMs", &server_cape_ms_value)) {
    {
      const base::ListValue* list = NULL;
      if (!server_cape_ms_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->server_cape_ms)) {
          return false;
        }
      }
    }
  }

  const base::Value* server_ca_refs_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCARefs", &server_ca_refs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!server_ca_refs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->server_ca_refs)) {
          return false;
        }
      }
    }
  }

  const base::Value* server_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCertRef", &server_cert_ref_value)) {
    {
      std::string temp;
      if (!server_cert_ref_value->GetAsString(&temp)) {
        out->server_cert_ref.reset();
        return false;
      }
      else
        out->server_cert_ref.reset(new std::string(temp));
    }
  }

  const base::Value* server_poll_timeout_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerPollTimeout", &server_poll_timeout_value)) {
    {
      int temp;
      if (!server_poll_timeout_value->GetAsInteger(&temp)) {
        out->server_poll_timeout.reset();
        return false;
      }
      else
        out->server_poll_timeout.reset(new int(temp));
    }
  }

  const base::Value* shaper_value = NULL;
  if (dict->GetWithoutPathExpansion("Shaper", &shaper_value)) {
    {
      int temp;
      if (!shaper_value->GetAsInteger(&temp)) {
        out->shaper.reset();
        return false;
      }
      else
        out->shaper.reset(new int(temp));
    }
  }

  const base::Value* static_challenge_value = NULL;
  if (dict->GetWithoutPathExpansion("StaticChallenge", &static_challenge_value)) {
    {
      std::string temp;
      if (!static_challenge_value->GetAsString(&temp)) {
        out->static_challenge.reset();
        return false;
      }
      else
        out->static_challenge.reset(new std::string(temp));
    }
  }

  const base::Value* tls_auth_contents_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSAuthContents", &tls_auth_contents_value)) {
    {
      std::string temp;
      if (!tls_auth_contents_value->GetAsString(&temp)) {
        out->tls_auth_contents.reset();
        return false;
      }
      else
        out->tls_auth_contents.reset(new std::string(temp));
    }
  }

  const base::Value* tls_remote_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSRemote", &tls_remote_value)) {
    {
      std::string temp;
      if (!tls_remote_value->GetAsString(&temp)) {
        out->tls_remote.reset();
        return false;
      }
      else
        out->tls_remote.reset(new std::string(temp));
    }
  }

  const base::Value* tls_version_min_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSVersionMin", &tls_version_min_value)) {
    {
      std::string temp;
      if (!tls_version_min_value->GetAsString(&temp)) {
        out->tls_version_min.reset();
        return false;
      }
      else
        out->tls_version_min.reset(new std::string(temp));
    }
  }

  const base::Value* user_authentication_type_value = NULL;
  if (dict->GetWithoutPathExpansion("UserAuthenticationType", &user_authentication_type_value)) {
    {
      std::string temp;
      if (!user_authentication_type_value->GetAsString(&temp)) {
        out->user_authentication_type.reset();
        return false;
      }
      else
        out->user_authentication_type.reset(new std::string(temp));
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      std::string temp;
      if (!username_value->GetAsString(&temp)) {
        out->username.reset();
        return false;
      }
      else
        out->username.reset(new std::string(temp));
    }
  }

  const base::Value* verb_value = NULL;
  if (dict->GetWithoutPathExpansion("Verb", &verb_value)) {
    {
      std::string temp;
      if (!verb_value->GetAsString(&temp)) {
        out->verb.reset();
        return false;
      }
      else
        out->verb.reset(new std::string(temp));
    }
  }

  const base::Value* verify_hash_value = NULL;
  if (dict->GetWithoutPathExpansion("VerifyHash", &verify_hash_value)) {
    {
      std::string temp;
      if (!verify_hash_value->GetAsString(&temp)) {
        out->verify_hash.reset();
        return false;
      }
      else
        out->verify_hash.reset(new std::string(temp));
    }
  }

  const base::Value* verify_x509_value = NULL;
  if (dict->GetWithoutPathExpansion("VerifyX509", &verify_x509_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!verify_x509_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<VerifyX509> temp(new VerifyX509());
        if (!VerifyX509::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->verify_x509 = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<OpenVPNProperties> OpenVPNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<OpenVPNProperties> out(new OpenVPNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OpenVPNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auth.get()) {
    to_value_result->SetWithoutPathExpansion("Auth", std::make_unique<base::Value>(*this->auth));

  }
  if (this->auth_retry.get()) {
    to_value_result->SetWithoutPathExpansion("AuthRetry", std::make_unique<base::Value>(*this->auth_retry));

  }
  if (this->auth_no_cache.get()) {
    to_value_result->SetWithoutPathExpansion("AuthNoCache", std::make_unique<base::Value>(*this->auth_no_cache));

  }
  if (this->cipher.get()) {
    to_value_result->SetWithoutPathExpansion("Cipher", std::make_unique<base::Value>(*this->cipher));

  }
  if (this->client_cert_pkcs11_id.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPKCS11Id", std::make_unique<base::Value>(*this->client_cert_pkcs11_id));

  }
  if (this->client_cert_pattern.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPattern", (this->client_cert_pattern)->ToValue());

  }
  if (this->client_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertRef", std::make_unique<base::Value>(*this->client_cert_ref));

  }
  if (this->client_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertType", std::make_unique<base::Value>(*this->client_cert_type));

  }
  if (this->comp_lzo.get()) {
    to_value_result->SetWithoutPathExpansion("CompLZO", std::make_unique<base::Value>(*this->comp_lzo));

  }
  if (this->comp_no_adapt.get()) {
    to_value_result->SetWithoutPathExpansion("CompNoAdapt", std::make_unique<base::Value>(*this->comp_no_adapt));

  }
  if (this->extra_hosts.get()) {
    to_value_result->SetWithoutPathExpansion("ExtraHosts", json_schema_compiler::util::CreateValueFromOptionalArray(this->extra_hosts));

  }
  if (this->ignore_default_route.get()) {
    to_value_result->SetWithoutPathExpansion("IgnoreDefaultRoute", std::make_unique<base::Value>(*this->ignore_default_route));

  }
  if (this->key_direction.get()) {
    to_value_result->SetWithoutPathExpansion("KeyDirection", std::make_unique<base::Value>(*this->key_direction));

  }
  if (this->ns_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("NsCertType", std::make_unique<base::Value>(*this->ns_cert_type));

  }
  if (this->otp.get()) {
    to_value_result->SetWithoutPathExpansion("OTP", std::make_unique<base::Value>(*this->otp));

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", std::make_unique<base::Value>(*this->password));

  }
  if (this->port.get()) {
    to_value_result->SetWithoutPathExpansion("Port", std::make_unique<base::Value>(*this->port));

  }
  if (this->proto.get()) {
    to_value_result->SetWithoutPathExpansion("Proto", std::make_unique<base::Value>(*this->proto));

  }
  if (this->push_peer_info.get()) {
    to_value_result->SetWithoutPathExpansion("PushPeerInfo", std::make_unique<base::Value>(*this->push_peer_info));

  }
  if (this->remote_cert_eku.get()) {
    to_value_result->SetWithoutPathExpansion("RemoteCertEKU", std::make_unique<base::Value>(*this->remote_cert_eku));

  }
  if (this->remote_cert_ku.get()) {
    to_value_result->SetWithoutPathExpansion("RemoteCertKU", json_schema_compiler::util::CreateValueFromOptionalArray(this->remote_cert_ku));

  }
  if (this->remote_cert_tls.get()) {
    to_value_result->SetWithoutPathExpansion("RemoteCertTLS", std::make_unique<base::Value>(*this->remote_cert_tls));

  }
  if (this->reneg_sec.get()) {
    to_value_result->SetWithoutPathExpansion("RenegSec", std::make_unique<base::Value>(*this->reneg_sec));

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", std::make_unique<base::Value>(*this->save_credentials));

  }
  if (this->server_cape_ms.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCAPEMs", json_schema_compiler::util::CreateValueFromOptionalArray(this->server_cape_ms));

  }
  if (this->server_ca_refs.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCARefs", json_schema_compiler::util::CreateValueFromOptionalArray(this->server_ca_refs));

  }
  if (this->server_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCertRef", std::make_unique<base::Value>(*this->server_cert_ref));

  }
  if (this->server_poll_timeout.get()) {
    to_value_result->SetWithoutPathExpansion("ServerPollTimeout", std::make_unique<base::Value>(*this->server_poll_timeout));

  }
  if (this->shaper.get()) {
    to_value_result->SetWithoutPathExpansion("Shaper", std::make_unique<base::Value>(*this->shaper));

  }
  if (this->static_challenge.get()) {
    to_value_result->SetWithoutPathExpansion("StaticChallenge", std::make_unique<base::Value>(*this->static_challenge));

  }
  if (this->tls_auth_contents.get()) {
    to_value_result->SetWithoutPathExpansion("TLSAuthContents", std::make_unique<base::Value>(*this->tls_auth_contents));

  }
  if (this->tls_remote.get()) {
    to_value_result->SetWithoutPathExpansion("TLSRemote", std::make_unique<base::Value>(*this->tls_remote));

  }
  if (this->tls_version_min.get()) {
    to_value_result->SetWithoutPathExpansion("TLSVersionMin", std::make_unique<base::Value>(*this->tls_version_min));

  }
  if (this->user_authentication_type.get()) {
    to_value_result->SetWithoutPathExpansion("UserAuthenticationType", std::make_unique<base::Value>(*this->user_authentication_type));

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", std::make_unique<base::Value>(*this->username));

  }
  if (this->verb.get()) {
    to_value_result->SetWithoutPathExpansion("Verb", std::make_unique<base::Value>(*this->verb));

  }
  if (this->verify_hash.get()) {
    to_value_result->SetWithoutPathExpansion("VerifyHash", std::make_unique<base::Value>(*this->verify_hash));

  }
  if (this->verify_x509.get()) {
    to_value_result->SetWithoutPathExpansion("VerifyX509", (this->verify_x509)->ToValue());

  }

  return to_value_result;
}


ManagedOpenVPNProperties::ManagedOpenVPNProperties()
 {}

ManagedOpenVPNProperties::~ManagedOpenVPNProperties() {}
ManagedOpenVPNProperties::ManagedOpenVPNProperties(ManagedOpenVPNProperties&& rhs)
: auth(std::move(rhs.auth)),
auth_retry(std::move(rhs.auth_retry)),
auth_no_cache(std::move(rhs.auth_no_cache)),
cipher(std::move(rhs.cipher)),
client_cert_pkcs11_id(std::move(rhs.client_cert_pkcs11_id)),
client_cert_pattern(std::move(rhs.client_cert_pattern)),
client_cert_ref(std::move(rhs.client_cert_ref)),
client_cert_type(std::move(rhs.client_cert_type)),
comp_lzo(std::move(rhs.comp_lzo)),
comp_no_adapt(std::move(rhs.comp_no_adapt)),
extra_hosts(std::move(rhs.extra_hosts)),
ignore_default_route(std::move(rhs.ignore_default_route)),
key_direction(std::move(rhs.key_direction)),
ns_cert_type(std::move(rhs.ns_cert_type)),
otp(std::move(rhs.otp)),
password(std::move(rhs.password)),
port(std::move(rhs.port)),
proto(std::move(rhs.proto)),
push_peer_info(std::move(rhs.push_peer_info)),
remote_cert_eku(std::move(rhs.remote_cert_eku)),
remote_cert_ku(std::move(rhs.remote_cert_ku)),
remote_cert_tls(std::move(rhs.remote_cert_tls)),
reneg_sec(std::move(rhs.reneg_sec)),
save_credentials(std::move(rhs.save_credentials)),
server_cape_ms(std::move(rhs.server_cape_ms)),
server_ca_refs(std::move(rhs.server_ca_refs)),
server_cert_ref(std::move(rhs.server_cert_ref)),
server_poll_timeout(std::move(rhs.server_poll_timeout)),
shaper(std::move(rhs.shaper)),
static_challenge(std::move(rhs.static_challenge)),
tls_auth_contents(std::move(rhs.tls_auth_contents)),
tls_remote(std::move(rhs.tls_remote)),
tls_version_min(std::move(rhs.tls_version_min)),
user_authentication_type(std::move(rhs.user_authentication_type)),
username(std::move(rhs.username)),
verb(std::move(rhs.verb)),
verify_hash(std::move(rhs.verify_hash)),
verify_x509(std::move(rhs.verify_x509)){
}

ManagedOpenVPNProperties& ManagedOpenVPNProperties::operator=(ManagedOpenVPNProperties&& rhs)
{
auth = std::move(rhs.auth);
auth_retry = std::move(rhs.auth_retry);
auth_no_cache = std::move(rhs.auth_no_cache);
cipher = std::move(rhs.cipher);
client_cert_pkcs11_id = std::move(rhs.client_cert_pkcs11_id);
client_cert_pattern = std::move(rhs.client_cert_pattern);
client_cert_ref = std::move(rhs.client_cert_ref);
client_cert_type = std::move(rhs.client_cert_type);
comp_lzo = std::move(rhs.comp_lzo);
comp_no_adapt = std::move(rhs.comp_no_adapt);
extra_hosts = std::move(rhs.extra_hosts);
ignore_default_route = std::move(rhs.ignore_default_route);
key_direction = std::move(rhs.key_direction);
ns_cert_type = std::move(rhs.ns_cert_type);
otp = std::move(rhs.otp);
password = std::move(rhs.password);
port = std::move(rhs.port);
proto = std::move(rhs.proto);
push_peer_info = std::move(rhs.push_peer_info);
remote_cert_eku = std::move(rhs.remote_cert_eku);
remote_cert_ku = std::move(rhs.remote_cert_ku);
remote_cert_tls = std::move(rhs.remote_cert_tls);
reneg_sec = std::move(rhs.reneg_sec);
save_credentials = std::move(rhs.save_credentials);
server_cape_ms = std::move(rhs.server_cape_ms);
server_ca_refs = std::move(rhs.server_ca_refs);
server_cert_ref = std::move(rhs.server_cert_ref);
server_poll_timeout = std::move(rhs.server_poll_timeout);
shaper = std::move(rhs.shaper);
static_challenge = std::move(rhs.static_challenge);
tls_auth_contents = std::move(rhs.tls_auth_contents);
tls_remote = std::move(rhs.tls_remote);
tls_version_min = std::move(rhs.tls_version_min);
user_authentication_type = std::move(rhs.user_authentication_type);
username = std::move(rhs.username);
verb = std::move(rhs.verb);
verify_hash = std::move(rhs.verify_hash);
verify_x509 = std::move(rhs.verify_x509);
return *this;
}

// static
bool ManagedOpenVPNProperties::Populate(
    const base::Value& value, ManagedOpenVPNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* auth_value = NULL;
  if (dict->GetWithoutPathExpansion("Auth", &auth_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!auth_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->auth = std::move(temp);
      }
    }
  }

  const base::Value* auth_retry_value = NULL;
  if (dict->GetWithoutPathExpansion("AuthRetry", &auth_retry_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!auth_retry_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->auth_retry = std::move(temp);
      }
    }
  }

  const base::Value* auth_no_cache_value = NULL;
  if (dict->GetWithoutPathExpansion("AuthNoCache", &auth_no_cache_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!auth_no_cache_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->auth_no_cache = std::move(temp);
      }
    }
  }

  const base::Value* cipher_value = NULL;
  if (dict->GetWithoutPathExpansion("Cipher", &cipher_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!cipher_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->cipher = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_pkcs11_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPKCS11Id", &client_cert_pkcs11_id_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pkcs11_id_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pkcs11_id = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_pattern_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertPattern", &client_cert_pattern_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_pattern_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedCertificatePattern> temp(new ManagedCertificatePattern());
        if (!ManagedCertificatePattern::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_pattern = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertRef", &client_cert_ref_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_ref_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_ref = std::move(temp);
      }
    }
  }

  const base::Value* client_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ClientCertType", &client_cert_type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!client_cert_type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->client_cert_type = std::move(temp);
      }
    }
  }

  const base::Value* comp_lzo_value = NULL;
  if (dict->GetWithoutPathExpansion("CompLZO", &comp_lzo_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!comp_lzo_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->comp_lzo = std::move(temp);
      }
    }
  }

  const base::Value* comp_no_adapt_value = NULL;
  if (dict->GetWithoutPathExpansion("CompNoAdapt", &comp_no_adapt_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!comp_no_adapt_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->comp_no_adapt = std::move(temp);
      }
    }
  }

  const base::Value* extra_hosts_value = NULL;
  if (dict->GetWithoutPathExpansion("ExtraHosts", &extra_hosts_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!extra_hosts_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->extra_hosts = std::move(temp);
      }
    }
  }

  const base::Value* ignore_default_route_value = NULL;
  if (dict->GetWithoutPathExpansion("IgnoreDefaultRoute", &ignore_default_route_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ignore_default_route_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ignore_default_route = std::move(temp);
      }
    }
  }

  const base::Value* key_direction_value = NULL;
  if (dict->GetWithoutPathExpansion("KeyDirection", &key_direction_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!key_direction_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->key_direction = std::move(temp);
      }
    }
  }

  const base::Value* ns_cert_type_value = NULL;
  if (dict->GetWithoutPathExpansion("NsCertType", &ns_cert_type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ns_cert_type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ns_cert_type = std::move(temp);
      }
    }
  }

  const base::Value* otp_value = NULL;
  if (dict->GetWithoutPathExpansion("OTP", &otp_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!otp_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->otp = std::move(temp);
      }
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("Password", &password_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!password_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->password = std::move(temp);
      }
    }
  }

  const base::Value* port_value = NULL;
  if (dict->GetWithoutPathExpansion("Port", &port_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!port_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedLong> temp(new ManagedLong());
        if (!ManagedLong::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->port = std::move(temp);
      }
    }
  }

  const base::Value* proto_value = NULL;
  if (dict->GetWithoutPathExpansion("Proto", &proto_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!proto_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->proto = std::move(temp);
      }
    }
  }

  const base::Value* push_peer_info_value = NULL;
  if (dict->GetWithoutPathExpansion("PushPeerInfo", &push_peer_info_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!push_peer_info_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->push_peer_info = std::move(temp);
      }
    }
  }

  const base::Value* remote_cert_eku_value = NULL;
  if (dict->GetWithoutPathExpansion("RemoteCertEKU", &remote_cert_eku_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!remote_cert_eku_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->remote_cert_eku = std::move(temp);
      }
    }
  }

  const base::Value* remote_cert_ku_value = NULL;
  if (dict->GetWithoutPathExpansion("RemoteCertKU", &remote_cert_ku_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!remote_cert_ku_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->remote_cert_ku = std::move(temp);
      }
    }
  }

  const base::Value* remote_cert_tls_value = NULL;
  if (dict->GetWithoutPathExpansion("RemoteCertTLS", &remote_cert_tls_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!remote_cert_tls_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->remote_cert_tls = std::move(temp);
      }
    }
  }

  const base::Value* reneg_sec_value = NULL;
  if (dict->GetWithoutPathExpansion("RenegSec", &reneg_sec_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!reneg_sec_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedLong> temp(new ManagedLong());
        if (!ManagedLong::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->reneg_sec = std::move(temp);
      }
    }
  }

  const base::Value* save_credentials_value = NULL;
  if (dict->GetWithoutPathExpansion("SaveCredentials", &save_credentials_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!save_credentials_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->save_credentials = std::move(temp);
      }
    }
  }

  const base::Value* server_cape_ms_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCAPEMs", &server_cape_ms_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_cape_ms_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_cape_ms = std::move(temp);
      }
    }
  }

  const base::Value* server_ca_refs_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCARefs", &server_ca_refs_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_ca_refs_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMStringList> temp(new ManagedDOMStringList());
        if (!ManagedDOMStringList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_ca_refs = std::move(temp);
      }
    }
  }

  const base::Value* server_cert_ref_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerCertRef", &server_cert_ref_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_cert_ref_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_cert_ref = std::move(temp);
      }
    }
  }

  const base::Value* server_poll_timeout_value = NULL;
  if (dict->GetWithoutPathExpansion("ServerPollTimeout", &server_poll_timeout_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!server_poll_timeout_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedLong> temp(new ManagedLong());
        if (!ManagedLong::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->server_poll_timeout = std::move(temp);
      }
    }
  }

  const base::Value* shaper_value = NULL;
  if (dict->GetWithoutPathExpansion("Shaper", &shaper_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!shaper_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedLong> temp(new ManagedLong());
        if (!ManagedLong::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->shaper = std::move(temp);
      }
    }
  }

  const base::Value* static_challenge_value = NULL;
  if (dict->GetWithoutPathExpansion("StaticChallenge", &static_challenge_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!static_challenge_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->static_challenge = std::move(temp);
      }
    }
  }

  const base::Value* tls_auth_contents_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSAuthContents", &tls_auth_contents_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tls_auth_contents_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tls_auth_contents = std::move(temp);
      }
    }
  }

  const base::Value* tls_remote_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSRemote", &tls_remote_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tls_remote_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tls_remote = std::move(temp);
      }
    }
  }

  const base::Value* tls_version_min_value = NULL;
  if (dict->GetWithoutPathExpansion("TLSVersionMin", &tls_version_min_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tls_version_min_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tls_version_min = std::move(temp);
      }
    }
  }

  const base::Value* user_authentication_type_value = NULL;
  if (dict->GetWithoutPathExpansion("UserAuthenticationType", &user_authentication_type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!user_authentication_type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->user_authentication_type = std::move(temp);
      }
    }
  }

  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("Username", &username_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!username_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->username = std::move(temp);
      }
    }
  }

  const base::Value* verb_value = NULL;
  if (dict->GetWithoutPathExpansion("Verb", &verb_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!verb_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->verb = std::move(temp);
      }
    }
  }

  const base::Value* verify_hash_value = NULL;
  if (dict->GetWithoutPathExpansion("VerifyHash", &verify_hash_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!verify_hash_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->verify_hash = std::move(temp);
      }
    }
  }

  const base::Value* verify_x509_value = NULL;
  if (dict->GetWithoutPathExpansion("VerifyX509", &verify_x509_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!verify_x509_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedVerifyX509> temp(new ManagedVerifyX509());
        if (!ManagedVerifyX509::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->verify_x509 = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedOpenVPNProperties> ManagedOpenVPNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedOpenVPNProperties> out(new ManagedOpenVPNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedOpenVPNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auth.get()) {
    to_value_result->SetWithoutPathExpansion("Auth", (this->auth)->ToValue());

  }
  if (this->auth_retry.get()) {
    to_value_result->SetWithoutPathExpansion("AuthRetry", (this->auth_retry)->ToValue());

  }
  if (this->auth_no_cache.get()) {
    to_value_result->SetWithoutPathExpansion("AuthNoCache", (this->auth_no_cache)->ToValue());

  }
  if (this->cipher.get()) {
    to_value_result->SetWithoutPathExpansion("Cipher", (this->cipher)->ToValue());

  }
  if (this->client_cert_pkcs11_id.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPKCS11Id", (this->client_cert_pkcs11_id)->ToValue());

  }
  if (this->client_cert_pattern.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertPattern", (this->client_cert_pattern)->ToValue());

  }
  if (this->client_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertRef", (this->client_cert_ref)->ToValue());

  }
  if (this->client_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("ClientCertType", (this->client_cert_type)->ToValue());

  }
  if (this->comp_lzo.get()) {
    to_value_result->SetWithoutPathExpansion("CompLZO", (this->comp_lzo)->ToValue());

  }
  if (this->comp_no_adapt.get()) {
    to_value_result->SetWithoutPathExpansion("CompNoAdapt", (this->comp_no_adapt)->ToValue());

  }
  if (this->extra_hosts.get()) {
    to_value_result->SetWithoutPathExpansion("ExtraHosts", (this->extra_hosts)->ToValue());

  }
  if (this->ignore_default_route.get()) {
    to_value_result->SetWithoutPathExpansion("IgnoreDefaultRoute", (this->ignore_default_route)->ToValue());

  }
  if (this->key_direction.get()) {
    to_value_result->SetWithoutPathExpansion("KeyDirection", (this->key_direction)->ToValue());

  }
  if (this->ns_cert_type.get()) {
    to_value_result->SetWithoutPathExpansion("NsCertType", (this->ns_cert_type)->ToValue());

  }
  if (this->otp.get()) {
    to_value_result->SetWithoutPathExpansion("OTP", (this->otp)->ToValue());

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("Password", (this->password)->ToValue());

  }
  if (this->port.get()) {
    to_value_result->SetWithoutPathExpansion("Port", (this->port)->ToValue());

  }
  if (this->proto.get()) {
    to_value_result->SetWithoutPathExpansion("Proto", (this->proto)->ToValue());

  }
  if (this->push_peer_info.get()) {
    to_value_result->SetWithoutPathExpansion("PushPeerInfo", (this->push_peer_info)->ToValue());

  }
  if (this->remote_cert_eku.get()) {
    to_value_result->SetWithoutPathExpansion("RemoteCertEKU", (this->remote_cert_eku)->ToValue());

  }
  if (this->remote_cert_ku.get()) {
    to_value_result->SetWithoutPathExpansion("RemoteCertKU", (this->remote_cert_ku)->ToValue());

  }
  if (this->remote_cert_tls.get()) {
    to_value_result->SetWithoutPathExpansion("RemoteCertTLS", (this->remote_cert_tls)->ToValue());

  }
  if (this->reneg_sec.get()) {
    to_value_result->SetWithoutPathExpansion("RenegSec", (this->reneg_sec)->ToValue());

  }
  if (this->save_credentials.get()) {
    to_value_result->SetWithoutPathExpansion("SaveCredentials", (this->save_credentials)->ToValue());

  }
  if (this->server_cape_ms.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCAPEMs", (this->server_cape_ms)->ToValue());

  }
  if (this->server_ca_refs.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCARefs", (this->server_ca_refs)->ToValue());

  }
  if (this->server_cert_ref.get()) {
    to_value_result->SetWithoutPathExpansion("ServerCertRef", (this->server_cert_ref)->ToValue());

  }
  if (this->server_poll_timeout.get()) {
    to_value_result->SetWithoutPathExpansion("ServerPollTimeout", (this->server_poll_timeout)->ToValue());

  }
  if (this->shaper.get()) {
    to_value_result->SetWithoutPathExpansion("Shaper", (this->shaper)->ToValue());

  }
  if (this->static_challenge.get()) {
    to_value_result->SetWithoutPathExpansion("StaticChallenge", (this->static_challenge)->ToValue());

  }
  if (this->tls_auth_contents.get()) {
    to_value_result->SetWithoutPathExpansion("TLSAuthContents", (this->tls_auth_contents)->ToValue());

  }
  if (this->tls_remote.get()) {
    to_value_result->SetWithoutPathExpansion("TLSRemote", (this->tls_remote)->ToValue());

  }
  if (this->tls_version_min.get()) {
    to_value_result->SetWithoutPathExpansion("TLSVersionMin", (this->tls_version_min)->ToValue());

  }
  if (this->user_authentication_type.get()) {
    to_value_result->SetWithoutPathExpansion("UserAuthenticationType", (this->user_authentication_type)->ToValue());

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("Username", (this->username)->ToValue());

  }
  if (this->verb.get()) {
    to_value_result->SetWithoutPathExpansion("Verb", (this->verb)->ToValue());

  }
  if (this->verify_hash.get()) {
    to_value_result->SetWithoutPathExpansion("VerifyHash", (this->verify_hash)->ToValue());

  }
  if (this->verify_x509.get()) {
    to_value_result->SetWithoutPathExpansion("VerifyX509", (this->verify_x509)->ToValue());

  }

  return to_value_result;
}


SIMLockStatus::SIMLockStatus()
: lock_enabled(false) {}

SIMLockStatus::~SIMLockStatus() {}
SIMLockStatus::SIMLockStatus(SIMLockStatus&& rhs)
: lock_type(std::move(rhs.lock_type)),
lock_enabled(rhs.lock_enabled),
retries_left(std::move(rhs.retries_left)){
}

SIMLockStatus& SIMLockStatus::operator=(SIMLockStatus&& rhs)
{
lock_type = std::move(rhs.lock_type);
lock_enabled = rhs.lock_enabled;
retries_left = std::move(rhs.retries_left);
return *this;
}

// static
bool SIMLockStatus::Populate(
    const base::Value& value, SIMLockStatus* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* lock_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("LockType", &lock_type_value)) {
    return false;
  }
  {
    if (!lock_type_value->GetAsString(&out->lock_type)) {
      return false;
    }
  }

  const base::Value* lock_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("LockEnabled", &lock_enabled_value)) {
    return false;
  }
  {
    if (!lock_enabled_value->GetAsBoolean(&out->lock_enabled)) {
      return false;
    }
  }

  const base::Value* retries_left_value = NULL;
  if (dict->GetWithoutPathExpansion("RetriesLeft", &retries_left_value)) {
    {
      int temp;
      if (!retries_left_value->GetAsInteger(&temp)) {
        out->retries_left.reset();
        return false;
      }
      else
        out->retries_left.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<SIMLockStatus> SIMLockStatus::FromValue(const base::Value& value) {
  std::unique_ptr<SIMLockStatus> out(new SIMLockStatus());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SIMLockStatus::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("LockType", std::make_unique<base::Value>(this->lock_type));

  to_value_result->SetWithoutPathExpansion("LockEnabled", std::make_unique<base::Value>(this->lock_enabled));

  if (this->retries_left.get()) {
    to_value_result->SetWithoutPathExpansion("RetriesLeft", std::make_unique<base::Value>(*this->retries_left));

  }

  return to_value_result;
}


ThirdPartyVPNProperties::ThirdPartyVPNProperties()
 {}

ThirdPartyVPNProperties::~ThirdPartyVPNProperties() {}
ThirdPartyVPNProperties::ThirdPartyVPNProperties(ThirdPartyVPNProperties&& rhs)
: extension_id(std::move(rhs.extension_id)),
provider_name(std::move(rhs.provider_name)){
}

ThirdPartyVPNProperties& ThirdPartyVPNProperties::operator=(ThirdPartyVPNProperties&& rhs)
{
extension_id = std::move(rhs.extension_id);
provider_name = std::move(rhs.provider_name);
return *this;
}

// static
bool ThirdPartyVPNProperties::Populate(
    const base::Value& value, ThirdPartyVPNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("ExtensionID", &extension_id_value)) {
    return false;
  }
  {
    if (!extension_id_value->GetAsString(&out->extension_id)) {
      return false;
    }
  }

  const base::Value* provider_name_value = NULL;
  if (dict->GetWithoutPathExpansion("ProviderName", &provider_name_value)) {
    {
      std::string temp;
      if (!provider_name_value->GetAsString(&temp)) {
        out->provider_name.reset();
        return false;
      }
      else
        out->provider_name.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ThirdPartyVPNProperties> ThirdPartyVPNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ThirdPartyVPNProperties> out(new ThirdPartyVPNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ThirdPartyVPNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("ExtensionID", std::make_unique<base::Value>(this->extension_id));

  if (this->provider_name.get()) {
    to_value_result->SetWithoutPathExpansion("ProviderName", std::make_unique<base::Value>(*this->provider_name));

  }

  return to_value_result;
}


ManagedThirdPartyVPNProperties::ManagedThirdPartyVPNProperties()
 {}

ManagedThirdPartyVPNProperties::~ManagedThirdPartyVPNProperties() {}
ManagedThirdPartyVPNProperties::ManagedThirdPartyVPNProperties(ManagedThirdPartyVPNProperties&& rhs)
: extension_id(std::move(rhs.extension_id)),
provider_name(std::move(rhs.provider_name)){
}

ManagedThirdPartyVPNProperties& ManagedThirdPartyVPNProperties::operator=(ManagedThirdPartyVPNProperties&& rhs)
{
extension_id = std::move(rhs.extension_id);
provider_name = std::move(rhs.provider_name);
return *this;
}

// static
bool ManagedThirdPartyVPNProperties::Populate(
    const base::Value& value, ManagedThirdPartyVPNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* extension_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("ExtensionID", &extension_id_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!extension_id_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ManagedDOMString::Populate(*dictionary, &out->extension_id)) {
      return false;
    }
  }

  const base::Value* provider_name_value = NULL;
  if (dict->GetWithoutPathExpansion("ProviderName", &provider_name_value)) {
    {
      std::string temp;
      if (!provider_name_value->GetAsString(&temp)) {
        out->provider_name.reset();
        return false;
      }
      else
        out->provider_name.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedThirdPartyVPNProperties> ManagedThirdPartyVPNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedThirdPartyVPNProperties> out(new ManagedThirdPartyVPNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedThirdPartyVPNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("ExtensionID", (this->extension_id).ToValue());

  if (this->provider_name.get()) {
    to_value_result->SetWithoutPathExpansion("ProviderName", std::make_unique<base::Value>(*this->provider_name));

  }

  return to_value_result;
}


CellularProperties::CellularProperties()
: activation_state(ACTIVATION_STATE_TYPE_NONE) {}

CellularProperties::~CellularProperties() {}
CellularProperties::CellularProperties(CellularProperties&& rhs)
: auto_connect(std::move(rhs.auto_connect)),
apn(std::move(rhs.apn)),
apn_list(std::move(rhs.apn_list)),
activation_type(std::move(rhs.activation_type)),
activation_state(rhs.activation_state),
allow_roaming(std::move(rhs.allow_roaming)),
esn(std::move(rhs.esn)),
family(std::move(rhs.family)),
firmware_revision(std::move(rhs.firmware_revision)),
found_networks(std::move(rhs.found_networks)),
hardware_revision(std::move(rhs.hardware_revision)),
home_provider(std::move(rhs.home_provider)),
iccid(std::move(rhs.iccid)),
imei(std::move(rhs.imei)),
last_good_apn(std::move(rhs.last_good_apn)),
manufacturer(std::move(rhs.manufacturer)),
mdn(std::move(rhs.mdn)),
meid(std::move(rhs.meid)),
min(std::move(rhs.min)),
model_id(std::move(rhs.model_id)),
network_technology(std::move(rhs.network_technology)),
payment_portal(std::move(rhs.payment_portal)),
roaming_state(std::move(rhs.roaming_state)),
scanning(std::move(rhs.scanning)),
serving_operator(std::move(rhs.serving_operator)),
sim_lock_status(std::move(rhs.sim_lock_status)),
sim_present(std::move(rhs.sim_present)),
signal_strength(std::move(rhs.signal_strength)),
support_network_scan(std::move(rhs.support_network_scan)){
}

CellularProperties& CellularProperties::operator=(CellularProperties&& rhs)
{
auto_connect = std::move(rhs.auto_connect);
apn = std::move(rhs.apn);
apn_list = std::move(rhs.apn_list);
activation_type = std::move(rhs.activation_type);
activation_state = rhs.activation_state;
allow_roaming = std::move(rhs.allow_roaming);
esn = std::move(rhs.esn);
family = std::move(rhs.family);
firmware_revision = std::move(rhs.firmware_revision);
found_networks = std::move(rhs.found_networks);
hardware_revision = std::move(rhs.hardware_revision);
home_provider = std::move(rhs.home_provider);
iccid = std::move(rhs.iccid);
imei = std::move(rhs.imei);
last_good_apn = std::move(rhs.last_good_apn);
manufacturer = std::move(rhs.manufacturer);
mdn = std::move(rhs.mdn);
meid = std::move(rhs.meid);
min = std::move(rhs.min);
model_id = std::move(rhs.model_id);
network_technology = std::move(rhs.network_technology);
payment_portal = std::move(rhs.payment_portal);
roaming_state = std::move(rhs.roaming_state);
scanning = std::move(rhs.scanning);
serving_operator = std::move(rhs.serving_operator);
sim_lock_status = std::move(rhs.sim_lock_status);
sim_present = std::move(rhs.sim_present);
signal_strength = std::move(rhs.signal_strength);
support_network_scan = std::move(rhs.support_network_scan);
return *this;
}

// static
bool CellularProperties::Populate(
    const base::Value& value, CellularProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->activation_state = ACTIVATION_STATE_TYPE_NONE;
  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      bool temp;
      if (!auto_connect_value->GetAsBoolean(&temp)) {
        out->auto_connect.reset();
        return false;
      }
      else
        out->auto_connect.reset(new bool(temp));
    }
  }

  const base::Value* apn_value = NULL;
  if (dict->GetWithoutPathExpansion("APN", &apn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!apn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<APNProperties> temp(new APNProperties());
        if (!APNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->apn = std::move(temp);
      }
    }
  }

  const base::Value* apn_list_value = NULL;
  if (dict->GetWithoutPathExpansion("APNList", &apn_list_value)) {
    {
      const base::ListValue* list = NULL;
      if (!apn_list_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->apn_list)) {
          return false;
        }
      }
    }
  }

  const base::Value* activation_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ActivationType", &activation_type_value)) {
    {
      std::string temp;
      if (!activation_type_value->GetAsString(&temp)) {
        out->activation_type.reset();
        return false;
      }
      else
        out->activation_type.reset(new std::string(temp));
    }
  }

  const base::Value* activation_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ActivationState", &activation_state_value)) {
    {
      std::string activation_state_type_as_string;
      if (!activation_state_value->GetAsString(&activation_state_type_as_string)) {
        return false;
      }
      out->activation_state = ParseActivationStateType(activation_state_type_as_string);
      if (out->activation_state == ACTIVATION_STATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->activation_state = ACTIVATION_STATE_TYPE_NONE;
  }

  const base::Value* allow_roaming_value = NULL;
  if (dict->GetWithoutPathExpansion("AllowRoaming", &allow_roaming_value)) {
    {
      bool temp;
      if (!allow_roaming_value->GetAsBoolean(&temp)) {
        out->allow_roaming.reset();
        return false;
      }
      else
        out->allow_roaming.reset(new bool(temp));
    }
  }

  const base::Value* esn_value = NULL;
  if (dict->GetWithoutPathExpansion("ESN", &esn_value)) {
    {
      std::string temp;
      if (!esn_value->GetAsString(&temp)) {
        out->esn.reset();
        return false;
      }
      else
        out->esn.reset(new std::string(temp));
    }
  }

  const base::Value* family_value = NULL;
  if (dict->GetWithoutPathExpansion("Family", &family_value)) {
    {
      std::string temp;
      if (!family_value->GetAsString(&temp)) {
        out->family.reset();
        return false;
      }
      else
        out->family.reset(new std::string(temp));
    }
  }

  const base::Value* firmware_revision_value = NULL;
  if (dict->GetWithoutPathExpansion("FirmwareRevision", &firmware_revision_value)) {
    {
      std::string temp;
      if (!firmware_revision_value->GetAsString(&temp)) {
        out->firmware_revision.reset();
        return false;
      }
      else
        out->firmware_revision.reset(new std::string(temp));
    }
  }

  const base::Value* found_networks_value = NULL;
  if (dict->GetWithoutPathExpansion("FoundNetworks", &found_networks_value)) {
    {
      const base::ListValue* list = NULL;
      if (!found_networks_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->found_networks)) {
          return false;
        }
      }
    }
  }

  const base::Value* hardware_revision_value = NULL;
  if (dict->GetWithoutPathExpansion("HardwareRevision", &hardware_revision_value)) {
    {
      std::string temp;
      if (!hardware_revision_value->GetAsString(&temp)) {
        out->hardware_revision.reset();
        return false;
      }
      else
        out->hardware_revision.reset(new std::string(temp));
    }
  }

  const base::Value* home_provider_value = NULL;
  if (dict->GetWithoutPathExpansion("HomeProvider", &home_provider_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!home_provider_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CellularProviderProperties> temp(new CellularProviderProperties());
        if (!CellularProviderProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->home_provider = std::move(temp);
      }
    }
  }

  const base::Value* iccid_value = NULL;
  if (dict->GetWithoutPathExpansion("ICCID", &iccid_value)) {
    {
      std::string temp;
      if (!iccid_value->GetAsString(&temp)) {
        out->iccid.reset();
        return false;
      }
      else
        out->iccid.reset(new std::string(temp));
    }
  }

  const base::Value* imei_value = NULL;
  if (dict->GetWithoutPathExpansion("IMEI", &imei_value)) {
    {
      std::string temp;
      if (!imei_value->GetAsString(&temp)) {
        out->imei.reset();
        return false;
      }
      else
        out->imei.reset(new std::string(temp));
    }
  }

  const base::Value* last_good_apn_value = NULL;
  if (dict->GetWithoutPathExpansion("LastGoodAPN", &last_good_apn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!last_good_apn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<APNProperties> temp(new APNProperties());
        if (!APNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->last_good_apn = std::move(temp);
      }
    }
  }

  const base::Value* manufacturer_value = NULL;
  if (dict->GetWithoutPathExpansion("Manufacturer", &manufacturer_value)) {
    {
      std::string temp;
      if (!manufacturer_value->GetAsString(&temp)) {
        out->manufacturer.reset();
        return false;
      }
      else
        out->manufacturer.reset(new std::string(temp));
    }
  }

  const base::Value* mdn_value = NULL;
  if (dict->GetWithoutPathExpansion("MDN", &mdn_value)) {
    {
      std::string temp;
      if (!mdn_value->GetAsString(&temp)) {
        out->mdn.reset();
        return false;
      }
      else
        out->mdn.reset(new std::string(temp));
    }
  }

  const base::Value* meid_value = NULL;
  if (dict->GetWithoutPathExpansion("MEID", &meid_value)) {
    {
      std::string temp;
      if (!meid_value->GetAsString(&temp)) {
        out->meid.reset();
        return false;
      }
      else
        out->meid.reset(new std::string(temp));
    }
  }

  const base::Value* min_value = NULL;
  if (dict->GetWithoutPathExpansion("MIN", &min_value)) {
    {
      std::string temp;
      if (!min_value->GetAsString(&temp)) {
        out->min.reset();
        return false;
      }
      else
        out->min.reset(new std::string(temp));
    }
  }

  const base::Value* model_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ModelID", &model_id_value)) {
    {
      std::string temp;
      if (!model_id_value->GetAsString(&temp)) {
        out->model_id.reset();
        return false;
      }
      else
        out->model_id.reset(new std::string(temp));
    }
  }

  const base::Value* network_technology_value = NULL;
  if (dict->GetWithoutPathExpansion("NetworkTechnology", &network_technology_value)) {
    {
      std::string temp;
      if (!network_technology_value->GetAsString(&temp)) {
        out->network_technology.reset();
        return false;
      }
      else
        out->network_technology.reset(new std::string(temp));
    }
  }

  const base::Value* payment_portal_value = NULL;
  if (dict->GetWithoutPathExpansion("PaymentPortal", &payment_portal_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!payment_portal_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<PaymentPortal> temp(new PaymentPortal());
        if (!PaymentPortal::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->payment_portal = std::move(temp);
      }
    }
  }

  const base::Value* roaming_state_value = NULL;
  if (dict->GetWithoutPathExpansion("RoamingState", &roaming_state_value)) {
    {
      std::string temp;
      if (!roaming_state_value->GetAsString(&temp)) {
        out->roaming_state.reset();
        return false;
      }
      else
        out->roaming_state.reset(new std::string(temp));
    }
  }

  const base::Value* scanning_value = NULL;
  if (dict->GetWithoutPathExpansion("Scanning", &scanning_value)) {
    {
      bool temp;
      if (!scanning_value->GetAsBoolean(&temp)) {
        out->scanning.reset();
        return false;
      }
      else
        out->scanning.reset(new bool(temp));
    }
  }

  const base::Value* serving_operator_value = NULL;
  if (dict->GetWithoutPathExpansion("ServingOperator", &serving_operator_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!serving_operator_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CellularProviderProperties> temp(new CellularProviderProperties());
        if (!CellularProviderProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->serving_operator = std::move(temp);
      }
    }
  }

  const base::Value* sim_lock_status_value = NULL;
  if (dict->GetWithoutPathExpansion("SIMLockStatus", &sim_lock_status_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!sim_lock_status_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<SIMLockStatus> temp(new SIMLockStatus());
        if (!SIMLockStatus::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->sim_lock_status = std::move(temp);
      }
    }
  }

  const base::Value* sim_present_value = NULL;
  if (dict->GetWithoutPathExpansion("SIMPresent", &sim_present_value)) {
    {
      bool temp;
      if (!sim_present_value->GetAsBoolean(&temp)) {
        out->sim_present.reset();
        return false;
      }
      else
        out->sim_present.reset(new bool(temp));
    }
  }

  const base::Value* signal_strength_value = NULL;
  if (dict->GetWithoutPathExpansion("SignalStrength", &signal_strength_value)) {
    {
      int temp;
      if (!signal_strength_value->GetAsInteger(&temp)) {
        out->signal_strength.reset();
        return false;
      }
      else
        out->signal_strength.reset(new int(temp));
    }
  }

  const base::Value* support_network_scan_value = NULL;
  if (dict->GetWithoutPathExpansion("SupportNetworkScan", &support_network_scan_value)) {
    {
      bool temp;
      if (!support_network_scan_value->GetAsBoolean(&temp)) {
        out->support_network_scan.reset();
        return false;
      }
      else
        out->support_network_scan.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<CellularProperties> CellularProperties::FromValue(const base::Value& value) {
  std::unique_ptr<CellularProperties> out(new CellularProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CellularProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", std::make_unique<base::Value>(*this->auto_connect));

  }
  if (this->apn.get()) {
    to_value_result->SetWithoutPathExpansion("APN", (this->apn)->ToValue());

  }
  if (this->apn_list.get()) {
    to_value_result->SetWithoutPathExpansion("APNList", json_schema_compiler::util::CreateValueFromOptionalArray(this->apn_list));

  }
  if (this->activation_type.get()) {
    to_value_result->SetWithoutPathExpansion("ActivationType", std::make_unique<base::Value>(*this->activation_type));

  }
  if (this->activation_state != ACTIVATION_STATE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("ActivationState", std::make_unique<base::Value>(networking_private::ToString(this->activation_state)));

  }
  if (this->allow_roaming.get()) {
    to_value_result->SetWithoutPathExpansion("AllowRoaming", std::make_unique<base::Value>(*this->allow_roaming));

  }
  if (this->esn.get()) {
    to_value_result->SetWithoutPathExpansion("ESN", std::make_unique<base::Value>(*this->esn));

  }
  if (this->family.get()) {
    to_value_result->SetWithoutPathExpansion("Family", std::make_unique<base::Value>(*this->family));

  }
  if (this->firmware_revision.get()) {
    to_value_result->SetWithoutPathExpansion("FirmwareRevision", std::make_unique<base::Value>(*this->firmware_revision));

  }
  if (this->found_networks.get()) {
    to_value_result->SetWithoutPathExpansion("FoundNetworks", json_schema_compiler::util::CreateValueFromOptionalArray(this->found_networks));

  }
  if (this->hardware_revision.get()) {
    to_value_result->SetWithoutPathExpansion("HardwareRevision", std::make_unique<base::Value>(*this->hardware_revision));

  }
  if (this->home_provider.get()) {
    to_value_result->SetWithoutPathExpansion("HomeProvider", (this->home_provider)->ToValue());

  }
  if (this->iccid.get()) {
    to_value_result->SetWithoutPathExpansion("ICCID", std::make_unique<base::Value>(*this->iccid));

  }
  if (this->imei.get()) {
    to_value_result->SetWithoutPathExpansion("IMEI", std::make_unique<base::Value>(*this->imei));

  }
  if (this->last_good_apn.get()) {
    to_value_result->SetWithoutPathExpansion("LastGoodAPN", (this->last_good_apn)->ToValue());

  }
  if (this->manufacturer.get()) {
    to_value_result->SetWithoutPathExpansion("Manufacturer", std::make_unique<base::Value>(*this->manufacturer));

  }
  if (this->mdn.get()) {
    to_value_result->SetWithoutPathExpansion("MDN", std::make_unique<base::Value>(*this->mdn));

  }
  if (this->meid.get()) {
    to_value_result->SetWithoutPathExpansion("MEID", std::make_unique<base::Value>(*this->meid));

  }
  if (this->min.get()) {
    to_value_result->SetWithoutPathExpansion("MIN", std::make_unique<base::Value>(*this->min));

  }
  if (this->model_id.get()) {
    to_value_result->SetWithoutPathExpansion("ModelID", std::make_unique<base::Value>(*this->model_id));

  }
  if (this->network_technology.get()) {
    to_value_result->SetWithoutPathExpansion("NetworkTechnology", std::make_unique<base::Value>(*this->network_technology));

  }
  if (this->payment_portal.get()) {
    to_value_result->SetWithoutPathExpansion("PaymentPortal", (this->payment_portal)->ToValue());

  }
  if (this->roaming_state.get()) {
    to_value_result->SetWithoutPathExpansion("RoamingState", std::make_unique<base::Value>(*this->roaming_state));

  }
  if (this->scanning.get()) {
    to_value_result->SetWithoutPathExpansion("Scanning", std::make_unique<base::Value>(*this->scanning));

  }
  if (this->serving_operator.get()) {
    to_value_result->SetWithoutPathExpansion("ServingOperator", (this->serving_operator)->ToValue());

  }
  if (this->sim_lock_status.get()) {
    to_value_result->SetWithoutPathExpansion("SIMLockStatus", (this->sim_lock_status)->ToValue());

  }
  if (this->sim_present.get()) {
    to_value_result->SetWithoutPathExpansion("SIMPresent", std::make_unique<base::Value>(*this->sim_present));

  }
  if (this->signal_strength.get()) {
    to_value_result->SetWithoutPathExpansion("SignalStrength", std::make_unique<base::Value>(*this->signal_strength));

  }
  if (this->support_network_scan.get()) {
    to_value_result->SetWithoutPathExpansion("SupportNetworkScan", std::make_unique<base::Value>(*this->support_network_scan));

  }

  return to_value_result;
}


ManagedCellularProperties::ManagedCellularProperties()
: activation_state(ACTIVATION_STATE_TYPE_NONE) {}

ManagedCellularProperties::~ManagedCellularProperties() {}
ManagedCellularProperties::ManagedCellularProperties(ManagedCellularProperties&& rhs)
: auto_connect(std::move(rhs.auto_connect)),
apn(std::move(rhs.apn)),
apn_list(std::move(rhs.apn_list)),
activation_type(std::move(rhs.activation_type)),
activation_state(rhs.activation_state),
allow_roaming(std::move(rhs.allow_roaming)),
esn(std::move(rhs.esn)),
family(std::move(rhs.family)),
firmware_revision(std::move(rhs.firmware_revision)),
found_networks(std::move(rhs.found_networks)),
hardware_revision(std::move(rhs.hardware_revision)),
home_provider(std::move(rhs.home_provider)),
iccid(std::move(rhs.iccid)),
imei(std::move(rhs.imei)),
last_good_apn(std::move(rhs.last_good_apn)),
manufacturer(std::move(rhs.manufacturer)),
mdn(std::move(rhs.mdn)),
meid(std::move(rhs.meid)),
min(std::move(rhs.min)),
model_id(std::move(rhs.model_id)),
network_technology(std::move(rhs.network_technology)),
payment_portal(std::move(rhs.payment_portal)),
roaming_state(std::move(rhs.roaming_state)),
scanning(std::move(rhs.scanning)),
serving_operator(std::move(rhs.serving_operator)),
sim_lock_status(std::move(rhs.sim_lock_status)),
sim_present(std::move(rhs.sim_present)),
signal_strength(std::move(rhs.signal_strength)),
support_network_scan(std::move(rhs.support_network_scan)){
}

ManagedCellularProperties& ManagedCellularProperties::operator=(ManagedCellularProperties&& rhs)
{
auto_connect = std::move(rhs.auto_connect);
apn = std::move(rhs.apn);
apn_list = std::move(rhs.apn_list);
activation_type = std::move(rhs.activation_type);
activation_state = rhs.activation_state;
allow_roaming = std::move(rhs.allow_roaming);
esn = std::move(rhs.esn);
family = std::move(rhs.family);
firmware_revision = std::move(rhs.firmware_revision);
found_networks = std::move(rhs.found_networks);
hardware_revision = std::move(rhs.hardware_revision);
home_provider = std::move(rhs.home_provider);
iccid = std::move(rhs.iccid);
imei = std::move(rhs.imei);
last_good_apn = std::move(rhs.last_good_apn);
manufacturer = std::move(rhs.manufacturer);
mdn = std::move(rhs.mdn);
meid = std::move(rhs.meid);
min = std::move(rhs.min);
model_id = std::move(rhs.model_id);
network_technology = std::move(rhs.network_technology);
payment_portal = std::move(rhs.payment_portal);
roaming_state = std::move(rhs.roaming_state);
scanning = std::move(rhs.scanning);
serving_operator = std::move(rhs.serving_operator);
sim_lock_status = std::move(rhs.sim_lock_status);
sim_present = std::move(rhs.sim_present);
signal_strength = std::move(rhs.signal_strength);
support_network_scan = std::move(rhs.support_network_scan);
return *this;
}

// static
bool ManagedCellularProperties::Populate(
    const base::Value& value, ManagedCellularProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->activation_state = ACTIVATION_STATE_TYPE_NONE;
  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!auto_connect_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->auto_connect = std::move(temp);
      }
    }
  }

  const base::Value* apn_value = NULL;
  if (dict->GetWithoutPathExpansion("APN", &apn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!apn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedAPNProperties> temp(new ManagedAPNProperties());
        if (!ManagedAPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->apn = std::move(temp);
      }
    }
  }

  const base::Value* apn_list_value = NULL;
  if (dict->GetWithoutPathExpansion("APNList", &apn_list_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!apn_list_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedAPNList> temp(new ManagedAPNList());
        if (!ManagedAPNList::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->apn_list = std::move(temp);
      }
    }
  }

  const base::Value* activation_type_value = NULL;
  if (dict->GetWithoutPathExpansion("ActivationType", &activation_type_value)) {
    {
      std::string temp;
      if (!activation_type_value->GetAsString(&temp)) {
        out->activation_type.reset();
        return false;
      }
      else
        out->activation_type.reset(new std::string(temp));
    }
  }

  const base::Value* activation_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ActivationState", &activation_state_value)) {
    {
      std::string activation_state_type_as_string;
      if (!activation_state_value->GetAsString(&activation_state_type_as_string)) {
        return false;
      }
      out->activation_state = ParseActivationStateType(activation_state_type_as_string);
      if (out->activation_state == ACTIVATION_STATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->activation_state = ACTIVATION_STATE_TYPE_NONE;
  }

  const base::Value* allow_roaming_value = NULL;
  if (dict->GetWithoutPathExpansion("AllowRoaming", &allow_roaming_value)) {
    {
      bool temp;
      if (!allow_roaming_value->GetAsBoolean(&temp)) {
        out->allow_roaming.reset();
        return false;
      }
      else
        out->allow_roaming.reset(new bool(temp));
    }
  }

  const base::Value* esn_value = NULL;
  if (dict->GetWithoutPathExpansion("ESN", &esn_value)) {
    {
      std::string temp;
      if (!esn_value->GetAsString(&temp)) {
        out->esn.reset();
        return false;
      }
      else
        out->esn.reset(new std::string(temp));
    }
  }

  const base::Value* family_value = NULL;
  if (dict->GetWithoutPathExpansion("Family", &family_value)) {
    {
      std::string temp;
      if (!family_value->GetAsString(&temp)) {
        out->family.reset();
        return false;
      }
      else
        out->family.reset(new std::string(temp));
    }
  }

  const base::Value* firmware_revision_value = NULL;
  if (dict->GetWithoutPathExpansion("FirmwareRevision", &firmware_revision_value)) {
    {
      std::string temp;
      if (!firmware_revision_value->GetAsString(&temp)) {
        out->firmware_revision.reset();
        return false;
      }
      else
        out->firmware_revision.reset(new std::string(temp));
    }
  }

  const base::Value* found_networks_value = NULL;
  if (dict->GetWithoutPathExpansion("FoundNetworks", &found_networks_value)) {
    {
      const base::ListValue* list = NULL;
      if (!found_networks_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->found_networks)) {
          return false;
        }
      }
    }
  }

  const base::Value* hardware_revision_value = NULL;
  if (dict->GetWithoutPathExpansion("HardwareRevision", &hardware_revision_value)) {
    {
      std::string temp;
      if (!hardware_revision_value->GetAsString(&temp)) {
        out->hardware_revision.reset();
        return false;
      }
      else
        out->hardware_revision.reset(new std::string(temp));
    }
  }

  const base::Value* home_provider_value = NULL;
  if (dict->GetWithoutPathExpansion("HomeProvider", &home_provider_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!home_provider_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CellularProviderProperties> temp(new CellularProviderProperties());
        if (!CellularProviderProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->home_provider = std::move(temp);
      }
    }
  }

  const base::Value* iccid_value = NULL;
  if (dict->GetWithoutPathExpansion("ICCID", &iccid_value)) {
    {
      std::string temp;
      if (!iccid_value->GetAsString(&temp)) {
        out->iccid.reset();
        return false;
      }
      else
        out->iccid.reset(new std::string(temp));
    }
  }

  const base::Value* imei_value = NULL;
  if (dict->GetWithoutPathExpansion("IMEI", &imei_value)) {
    {
      std::string temp;
      if (!imei_value->GetAsString(&temp)) {
        out->imei.reset();
        return false;
      }
      else
        out->imei.reset(new std::string(temp));
    }
  }

  const base::Value* last_good_apn_value = NULL;
  if (dict->GetWithoutPathExpansion("LastGoodAPN", &last_good_apn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!last_good_apn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<APNProperties> temp(new APNProperties());
        if (!APNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->last_good_apn = std::move(temp);
      }
    }
  }

  const base::Value* manufacturer_value = NULL;
  if (dict->GetWithoutPathExpansion("Manufacturer", &manufacturer_value)) {
    {
      std::string temp;
      if (!manufacturer_value->GetAsString(&temp)) {
        out->manufacturer.reset();
        return false;
      }
      else
        out->manufacturer.reset(new std::string(temp));
    }
  }

  const base::Value* mdn_value = NULL;
  if (dict->GetWithoutPathExpansion("MDN", &mdn_value)) {
    {
      std::string temp;
      if (!mdn_value->GetAsString(&temp)) {
        out->mdn.reset();
        return false;
      }
      else
        out->mdn.reset(new std::string(temp));
    }
  }

  const base::Value* meid_value = NULL;
  if (dict->GetWithoutPathExpansion("MEID", &meid_value)) {
    {
      std::string temp;
      if (!meid_value->GetAsString(&temp)) {
        out->meid.reset();
        return false;
      }
      else
        out->meid.reset(new std::string(temp));
    }
  }

  const base::Value* min_value = NULL;
  if (dict->GetWithoutPathExpansion("MIN", &min_value)) {
    {
      std::string temp;
      if (!min_value->GetAsString(&temp)) {
        out->min.reset();
        return false;
      }
      else
        out->min.reset(new std::string(temp));
    }
  }

  const base::Value* model_id_value = NULL;
  if (dict->GetWithoutPathExpansion("ModelID", &model_id_value)) {
    {
      std::string temp;
      if (!model_id_value->GetAsString(&temp)) {
        out->model_id.reset();
        return false;
      }
      else
        out->model_id.reset(new std::string(temp));
    }
  }

  const base::Value* network_technology_value = NULL;
  if (dict->GetWithoutPathExpansion("NetworkTechnology", &network_technology_value)) {
    {
      std::string temp;
      if (!network_technology_value->GetAsString(&temp)) {
        out->network_technology.reset();
        return false;
      }
      else
        out->network_technology.reset(new std::string(temp));
    }
  }

  const base::Value* payment_portal_value = NULL;
  if (dict->GetWithoutPathExpansion("PaymentPortal", &payment_portal_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!payment_portal_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<PaymentPortal> temp(new PaymentPortal());
        if (!PaymentPortal::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->payment_portal = std::move(temp);
      }
    }
  }

  const base::Value* roaming_state_value = NULL;
  if (dict->GetWithoutPathExpansion("RoamingState", &roaming_state_value)) {
    {
      std::string temp;
      if (!roaming_state_value->GetAsString(&temp)) {
        out->roaming_state.reset();
        return false;
      }
      else
        out->roaming_state.reset(new std::string(temp));
    }
  }

  const base::Value* scanning_value = NULL;
  if (dict->GetWithoutPathExpansion("Scanning", &scanning_value)) {
    {
      bool temp;
      if (!scanning_value->GetAsBoolean(&temp)) {
        out->scanning.reset();
        return false;
      }
      else
        out->scanning.reset(new bool(temp));
    }
  }

  const base::Value* serving_operator_value = NULL;
  if (dict->GetWithoutPathExpansion("ServingOperator", &serving_operator_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!serving_operator_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CellularProviderProperties> temp(new CellularProviderProperties());
        if (!CellularProviderProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->serving_operator = std::move(temp);
      }
    }
  }

  const base::Value* sim_lock_status_value = NULL;
  if (dict->GetWithoutPathExpansion("SIMLockStatus", &sim_lock_status_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!sim_lock_status_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<SIMLockStatus> temp(new SIMLockStatus());
        if (!SIMLockStatus::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->sim_lock_status = std::move(temp);
      }
    }
  }

  const base::Value* sim_present_value = NULL;
  if (dict->GetWithoutPathExpansion("SIMPresent", &sim_present_value)) {
    {
      bool temp;
      if (!sim_present_value->GetAsBoolean(&temp)) {
        out->sim_present.reset();
        return false;
      }
      else
        out->sim_present.reset(new bool(temp));
    }
  }

  const base::Value* signal_strength_value = NULL;
  if (dict->GetWithoutPathExpansion("SignalStrength", &signal_strength_value)) {
    {
      int temp;
      if (!signal_strength_value->GetAsInteger(&temp)) {
        out->signal_strength.reset();
        return false;
      }
      else
        out->signal_strength.reset(new int(temp));
    }
  }

  const base::Value* support_network_scan_value = NULL;
  if (dict->GetWithoutPathExpansion("SupportNetworkScan", &support_network_scan_value)) {
    {
      bool temp;
      if (!support_network_scan_value->GetAsBoolean(&temp)) {
        out->support_network_scan.reset();
        return false;
      }
      else
        out->support_network_scan.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedCellularProperties> ManagedCellularProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedCellularProperties> out(new ManagedCellularProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedCellularProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", (this->auto_connect)->ToValue());

  }
  if (this->apn.get()) {
    to_value_result->SetWithoutPathExpansion("APN", (this->apn)->ToValue());

  }
  if (this->apn_list.get()) {
    to_value_result->SetWithoutPathExpansion("APNList", (this->apn_list)->ToValue());

  }
  if (this->activation_type.get()) {
    to_value_result->SetWithoutPathExpansion("ActivationType", std::make_unique<base::Value>(*this->activation_type));

  }
  if (this->activation_state != ACTIVATION_STATE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("ActivationState", std::make_unique<base::Value>(networking_private::ToString(this->activation_state)));

  }
  if (this->allow_roaming.get()) {
    to_value_result->SetWithoutPathExpansion("AllowRoaming", std::make_unique<base::Value>(*this->allow_roaming));

  }
  if (this->esn.get()) {
    to_value_result->SetWithoutPathExpansion("ESN", std::make_unique<base::Value>(*this->esn));

  }
  if (this->family.get()) {
    to_value_result->SetWithoutPathExpansion("Family", std::make_unique<base::Value>(*this->family));

  }
  if (this->firmware_revision.get()) {
    to_value_result->SetWithoutPathExpansion("FirmwareRevision", std::make_unique<base::Value>(*this->firmware_revision));

  }
  if (this->found_networks.get()) {
    to_value_result->SetWithoutPathExpansion("FoundNetworks", json_schema_compiler::util::CreateValueFromOptionalArray(this->found_networks));

  }
  if (this->hardware_revision.get()) {
    to_value_result->SetWithoutPathExpansion("HardwareRevision", std::make_unique<base::Value>(*this->hardware_revision));

  }
  if (this->home_provider.get()) {
    to_value_result->SetWithoutPathExpansion("HomeProvider", (this->home_provider)->ToValue());

  }
  if (this->iccid.get()) {
    to_value_result->SetWithoutPathExpansion("ICCID", std::make_unique<base::Value>(*this->iccid));

  }
  if (this->imei.get()) {
    to_value_result->SetWithoutPathExpansion("IMEI", std::make_unique<base::Value>(*this->imei));

  }
  if (this->last_good_apn.get()) {
    to_value_result->SetWithoutPathExpansion("LastGoodAPN", (this->last_good_apn)->ToValue());

  }
  if (this->manufacturer.get()) {
    to_value_result->SetWithoutPathExpansion("Manufacturer", std::make_unique<base::Value>(*this->manufacturer));

  }
  if (this->mdn.get()) {
    to_value_result->SetWithoutPathExpansion("MDN", std::make_unique<base::Value>(*this->mdn));

  }
  if (this->meid.get()) {
    to_value_result->SetWithoutPathExpansion("MEID", std::make_unique<base::Value>(*this->meid));

  }
  if (this->min.get()) {
    to_value_result->SetWithoutPathExpansion("MIN", std::make_unique<base::Value>(*this->min));

  }
  if (this->model_id.get()) {
    to_value_result->SetWithoutPathExpansion("ModelID", std::make_unique<base::Value>(*this->model_id));

  }
  if (this->network_technology.get()) {
    to_value_result->SetWithoutPathExpansion("NetworkTechnology", std::make_unique<base::Value>(*this->network_technology));

  }
  if (this->payment_portal.get()) {
    to_value_result->SetWithoutPathExpansion("PaymentPortal", (this->payment_portal)->ToValue());

  }
  if (this->roaming_state.get()) {
    to_value_result->SetWithoutPathExpansion("RoamingState", std::make_unique<base::Value>(*this->roaming_state));

  }
  if (this->scanning.get()) {
    to_value_result->SetWithoutPathExpansion("Scanning", std::make_unique<base::Value>(*this->scanning));

  }
  if (this->serving_operator.get()) {
    to_value_result->SetWithoutPathExpansion("ServingOperator", (this->serving_operator)->ToValue());

  }
  if (this->sim_lock_status.get()) {
    to_value_result->SetWithoutPathExpansion("SIMLockStatus", (this->sim_lock_status)->ToValue());

  }
  if (this->sim_present.get()) {
    to_value_result->SetWithoutPathExpansion("SIMPresent", std::make_unique<base::Value>(*this->sim_present));

  }
  if (this->signal_strength.get()) {
    to_value_result->SetWithoutPathExpansion("SignalStrength", std::make_unique<base::Value>(*this->signal_strength));

  }
  if (this->support_network_scan.get()) {
    to_value_result->SetWithoutPathExpansion("SupportNetworkScan", std::make_unique<base::Value>(*this->support_network_scan));

  }

  return to_value_result;
}


CellularStateProperties::CellularStateProperties()
: activation_state(ACTIVATION_STATE_TYPE_NONE) {}

CellularStateProperties::~CellularStateProperties() {}
CellularStateProperties::CellularStateProperties(CellularStateProperties&& rhs)
: activation_state(rhs.activation_state),
network_technology(std::move(rhs.network_technology)),
roaming_state(std::move(rhs.roaming_state)),
scanning(std::move(rhs.scanning)),
sim_present(std::move(rhs.sim_present)),
signal_strength(std::move(rhs.signal_strength)){
}

CellularStateProperties& CellularStateProperties::operator=(CellularStateProperties&& rhs)
{
activation_state = rhs.activation_state;
network_technology = std::move(rhs.network_technology);
roaming_state = std::move(rhs.roaming_state);
scanning = std::move(rhs.scanning);
sim_present = std::move(rhs.sim_present);
signal_strength = std::move(rhs.signal_strength);
return *this;
}

// static
bool CellularStateProperties::Populate(
    const base::Value& value, CellularStateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->activation_state = ACTIVATION_STATE_TYPE_NONE;
  const base::Value* activation_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ActivationState", &activation_state_value)) {
    {
      std::string activation_state_type_as_string;
      if (!activation_state_value->GetAsString(&activation_state_type_as_string)) {
        return false;
      }
      out->activation_state = ParseActivationStateType(activation_state_type_as_string);
      if (out->activation_state == ACTIVATION_STATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->activation_state = ACTIVATION_STATE_TYPE_NONE;
  }

  const base::Value* network_technology_value = NULL;
  if (dict->GetWithoutPathExpansion("NetworkTechnology", &network_technology_value)) {
    {
      std::string temp;
      if (!network_technology_value->GetAsString(&temp)) {
        out->network_technology.reset();
        return false;
      }
      else
        out->network_technology.reset(new std::string(temp));
    }
  }

  const base::Value* roaming_state_value = NULL;
  if (dict->GetWithoutPathExpansion("RoamingState", &roaming_state_value)) {
    {
      std::string temp;
      if (!roaming_state_value->GetAsString(&temp)) {
        out->roaming_state.reset();
        return false;
      }
      else
        out->roaming_state.reset(new std::string(temp));
    }
  }

  const base::Value* scanning_value = NULL;
  if (dict->GetWithoutPathExpansion("Scanning", &scanning_value)) {
    {
      bool temp;
      if (!scanning_value->GetAsBoolean(&temp)) {
        out->scanning.reset();
        return false;
      }
      else
        out->scanning.reset(new bool(temp));
    }
  }

  const base::Value* sim_present_value = NULL;
  if (dict->GetWithoutPathExpansion("SIMPresent", &sim_present_value)) {
    {
      bool temp;
      if (!sim_present_value->GetAsBoolean(&temp)) {
        out->sim_present.reset();
        return false;
      }
      else
        out->sim_present.reset(new bool(temp));
    }
  }

  const base::Value* signal_strength_value = NULL;
  if (dict->GetWithoutPathExpansion("SignalStrength", &signal_strength_value)) {
    {
      int temp;
      if (!signal_strength_value->GetAsInteger(&temp)) {
        out->signal_strength.reset();
        return false;
      }
      else
        out->signal_strength.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<CellularStateProperties> CellularStateProperties::FromValue(const base::Value& value) {
  std::unique_ptr<CellularStateProperties> out(new CellularStateProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CellularStateProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->activation_state != ACTIVATION_STATE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("ActivationState", std::make_unique<base::Value>(networking_private::ToString(this->activation_state)));

  }
  if (this->network_technology.get()) {
    to_value_result->SetWithoutPathExpansion("NetworkTechnology", std::make_unique<base::Value>(*this->network_technology));

  }
  if (this->roaming_state.get()) {
    to_value_result->SetWithoutPathExpansion("RoamingState", std::make_unique<base::Value>(*this->roaming_state));

  }
  if (this->scanning.get()) {
    to_value_result->SetWithoutPathExpansion("Scanning", std::make_unique<base::Value>(*this->scanning));

  }
  if (this->sim_present.get()) {
    to_value_result->SetWithoutPathExpansion("SIMPresent", std::make_unique<base::Value>(*this->sim_present));

  }
  if (this->signal_strength.get()) {
    to_value_result->SetWithoutPathExpansion("SignalStrength", std::make_unique<base::Value>(*this->signal_strength));

  }

  return to_value_result;
}


EAPStateProperties::EAPStateProperties()
 {}

EAPStateProperties::~EAPStateProperties() {}
EAPStateProperties::EAPStateProperties(EAPStateProperties&& rhs)
: outer(std::move(rhs.outer)){
}

EAPStateProperties& EAPStateProperties::operator=(EAPStateProperties&& rhs)
{
outer = std::move(rhs.outer);
return *this;
}

// static
bool EAPStateProperties::Populate(
    const base::Value& value, EAPStateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* outer_value = NULL;
  if (dict->GetWithoutPathExpansion("Outer", &outer_value)) {
    {
      std::string temp;
      if (!outer_value->GetAsString(&temp)) {
        out->outer.reset();
        return false;
      }
      else
        out->outer.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<EAPStateProperties> EAPStateProperties::FromValue(const base::Value& value) {
  std::unique_ptr<EAPStateProperties> out(new EAPStateProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EAPStateProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->outer.get()) {
    to_value_result->SetWithoutPathExpansion("Outer", std::make_unique<base::Value>(*this->outer));

  }

  return to_value_result;
}


EthernetProperties::EthernetProperties()
 {}

EthernetProperties::~EthernetProperties() {}
EthernetProperties::EthernetProperties(EthernetProperties&& rhs)
: auto_connect(std::move(rhs.auto_connect)),
authentication(std::move(rhs.authentication)),
eap(std::move(rhs.eap)){
}

EthernetProperties& EthernetProperties::operator=(EthernetProperties&& rhs)
{
auto_connect = std::move(rhs.auto_connect);
authentication = std::move(rhs.authentication);
eap = std::move(rhs.eap);
return *this;
}

// static
bool EthernetProperties::Populate(
    const base::Value& value, EthernetProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      bool temp;
      if (!auto_connect_value->GetAsBoolean(&temp)) {
        out->auto_connect.reset();
        return false;
      }
      else
        out->auto_connect.reset(new bool(temp));
    }
  }

  const base::Value* authentication_value = NULL;
  if (dict->GetWithoutPathExpansion("Authentication", &authentication_value)) {
    {
      std::string temp;
      if (!authentication_value->GetAsString(&temp)) {
        out->authentication.reset();
        return false;
      }
      else
        out->authentication.reset(new std::string(temp));
    }
  }

  const base::Value* eap_value = NULL;
  if (dict->GetWithoutPathExpansion("EAP", &eap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!eap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<EAPProperties> temp(new EAPProperties());
        if (!EAPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->eap = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<EthernetProperties> EthernetProperties::FromValue(const base::Value& value) {
  std::unique_ptr<EthernetProperties> out(new EthernetProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EthernetProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", std::make_unique<base::Value>(*this->auto_connect));

  }
  if (this->authentication.get()) {
    to_value_result->SetWithoutPathExpansion("Authentication", std::make_unique<base::Value>(*this->authentication));

  }
  if (this->eap.get()) {
    to_value_result->SetWithoutPathExpansion("EAP", (this->eap)->ToValue());

  }

  return to_value_result;
}


ManagedEthernetProperties::ManagedEthernetProperties()
 {}

ManagedEthernetProperties::~ManagedEthernetProperties() {}
ManagedEthernetProperties::ManagedEthernetProperties(ManagedEthernetProperties&& rhs)
: auto_connect(std::move(rhs.auto_connect)),
authentication(std::move(rhs.authentication)),
eap(std::move(rhs.eap)){
}

ManagedEthernetProperties& ManagedEthernetProperties::operator=(ManagedEthernetProperties&& rhs)
{
auto_connect = std::move(rhs.auto_connect);
authentication = std::move(rhs.authentication);
eap = std::move(rhs.eap);
return *this;
}

// static
bool ManagedEthernetProperties::Populate(
    const base::Value& value, ManagedEthernetProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!auto_connect_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->auto_connect = std::move(temp);
      }
    }
  }

  const base::Value* authentication_value = NULL;
  if (dict->GetWithoutPathExpansion("Authentication", &authentication_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!authentication_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->authentication = std::move(temp);
      }
    }
  }

  const base::Value* eap_value = NULL;
  if (dict->GetWithoutPathExpansion("EAP", &eap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!eap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedEAPProperties> temp(new ManagedEAPProperties());
        if (!ManagedEAPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->eap = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedEthernetProperties> ManagedEthernetProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedEthernetProperties> out(new ManagedEthernetProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedEthernetProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", (this->auto_connect)->ToValue());

  }
  if (this->authentication.get()) {
    to_value_result->SetWithoutPathExpansion("Authentication", (this->authentication)->ToValue());

  }
  if (this->eap.get()) {
    to_value_result->SetWithoutPathExpansion("EAP", (this->eap)->ToValue());

  }

  return to_value_result;
}


EthernetStateProperties::EthernetStateProperties()
 {}

EthernetStateProperties::~EthernetStateProperties() {}
EthernetStateProperties::EthernetStateProperties(EthernetStateProperties&& rhs)
: authentication(std::move(rhs.authentication)){
}

EthernetStateProperties& EthernetStateProperties::operator=(EthernetStateProperties&& rhs)
{
authentication = std::move(rhs.authentication);
return *this;
}

// static
bool EthernetStateProperties::Populate(
    const base::Value& value, EthernetStateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* authentication_value = NULL;
  if (!dict->GetWithoutPathExpansion("Authentication", &authentication_value)) {
    return false;
  }
  {
    if (!authentication_value->GetAsString(&out->authentication)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<EthernetStateProperties> EthernetStateProperties::FromValue(const base::Value& value) {
  std::unique_ptr<EthernetStateProperties> out(new EthernetStateProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> EthernetStateProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Authentication", std::make_unique<base::Value>(this->authentication));


  return to_value_result;
}


TetherProperties::TetherProperties()
: has_connected_to_host(false) {}

TetherProperties::~TetherProperties() {}
TetherProperties::TetherProperties(TetherProperties&& rhs)
: battery_percentage(std::move(rhs.battery_percentage)),
carrier(std::move(rhs.carrier)),
has_connected_to_host(rhs.has_connected_to_host),
signal_strength(std::move(rhs.signal_strength)){
}

TetherProperties& TetherProperties::operator=(TetherProperties&& rhs)
{
battery_percentage = std::move(rhs.battery_percentage);
carrier = std::move(rhs.carrier);
has_connected_to_host = rhs.has_connected_to_host;
signal_strength = std::move(rhs.signal_strength);
return *this;
}

// static
bool TetherProperties::Populate(
    const base::Value& value, TetherProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* battery_percentage_value = NULL;
  if (dict->GetWithoutPathExpansion("BatteryPercentage", &battery_percentage_value)) {
    {
      int temp;
      if (!battery_percentage_value->GetAsInteger(&temp)) {
        out->battery_percentage.reset();
        return false;
      }
      else
        out->battery_percentage.reset(new int(temp));
    }
  }

  const base::Value* carrier_value = NULL;
  if (dict->GetWithoutPathExpansion("Carrier", &carrier_value)) {
    {
      std::string temp;
      if (!carrier_value->GetAsString(&temp)) {
        out->carrier.reset();
        return false;
      }
      else
        out->carrier.reset(new std::string(temp));
    }
  }

  const base::Value* has_connected_to_host_value = NULL;
  if (!dict->GetWithoutPathExpansion("HasConnectedToHost", &has_connected_to_host_value)) {
    return false;
  }
  {
    if (!has_connected_to_host_value->GetAsBoolean(&out->has_connected_to_host)) {
      return false;
    }
  }

  const base::Value* signal_strength_value = NULL;
  if (dict->GetWithoutPathExpansion("SignalStrength", &signal_strength_value)) {
    {
      int temp;
      if (!signal_strength_value->GetAsInteger(&temp)) {
        out->signal_strength.reset();
        return false;
      }
      else
        out->signal_strength.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<TetherProperties> TetherProperties::FromValue(const base::Value& value) {
  std::unique_ptr<TetherProperties> out(new TetherProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TetherProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->battery_percentage.get()) {
    to_value_result->SetWithoutPathExpansion("BatteryPercentage", std::make_unique<base::Value>(*this->battery_percentage));

  }
  if (this->carrier.get()) {
    to_value_result->SetWithoutPathExpansion("Carrier", std::make_unique<base::Value>(*this->carrier));

  }
  to_value_result->SetWithoutPathExpansion("HasConnectedToHost", std::make_unique<base::Value>(this->has_connected_to_host));

  if (this->signal_strength.get()) {
    to_value_result->SetWithoutPathExpansion("SignalStrength", std::make_unique<base::Value>(*this->signal_strength));

  }

  return to_value_result;
}


VPNProperties::VPNProperties()
 {}

VPNProperties::~VPNProperties() {}
VPNProperties::VPNProperties(VPNProperties&& rhs)
: auto_connect(std::move(rhs.auto_connect)),
host(std::move(rhs.host)),
i_psec(std::move(rhs.i_psec)),
l2tp(std::move(rhs.l2tp)),
open_vpn(std::move(rhs.open_vpn)),
third_party_vpn(std::move(rhs.third_party_vpn)),
type(std::move(rhs.type)){
}

VPNProperties& VPNProperties::operator=(VPNProperties&& rhs)
{
auto_connect = std::move(rhs.auto_connect);
host = std::move(rhs.host);
i_psec = std::move(rhs.i_psec);
l2tp = std::move(rhs.l2tp);
open_vpn = std::move(rhs.open_vpn);
third_party_vpn = std::move(rhs.third_party_vpn);
type = std::move(rhs.type);
return *this;
}

// static
bool VPNProperties::Populate(
    const base::Value& value, VPNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      bool temp;
      if (!auto_connect_value->GetAsBoolean(&temp)) {
        out->auto_connect.reset();
        return false;
      }
      else
        out->auto_connect.reset(new bool(temp));
    }
  }

  const base::Value* host_value = NULL;
  if (dict->GetWithoutPathExpansion("Host", &host_value)) {
    {
      std::string temp;
      if (!host_value->GetAsString(&temp)) {
        out->host.reset();
        return false;
      }
      else
        out->host.reset(new std::string(temp));
    }
  }

  const base::Value* i_psec_value = NULL;
  if (dict->GetWithoutPathExpansion("IPsec", &i_psec_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!i_psec_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IPSecProperties> temp(new IPSecProperties());
        if (!IPSecProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->i_psec = std::move(temp);
      }
    }
  }

  const base::Value* l2tp_value = NULL;
  if (dict->GetWithoutPathExpansion("L2TP", &l2tp_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!l2tp_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<L2TPProperties> temp(new L2TPProperties());
        if (!L2TPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->l2tp = std::move(temp);
      }
    }
  }

  const base::Value* open_vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("OpenVPN", &open_vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!open_vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<OpenVPNProperties> temp(new OpenVPNProperties());
        if (!OpenVPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->open_vpn = std::move(temp);
      }
    }
  }

  const base::Value* third_party_vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("ThirdPartyVPN", &third_party_vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!third_party_vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ThirdPartyVPNProperties> temp(new ThirdPartyVPNProperties());
        if (!ThirdPartyVPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->third_party_vpn = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("Type", &type_value)) {
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
std::unique_ptr<VPNProperties> VPNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<VPNProperties> out(new VPNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> VPNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", std::make_unique<base::Value>(*this->auto_connect));

  }
  if (this->host.get()) {
    to_value_result->SetWithoutPathExpansion("Host", std::make_unique<base::Value>(*this->host));

  }
  if (this->i_psec.get()) {
    to_value_result->SetWithoutPathExpansion("IPsec", (this->i_psec)->ToValue());

  }
  if (this->l2tp.get()) {
    to_value_result->SetWithoutPathExpansion("L2TP", (this->l2tp)->ToValue());

  }
  if (this->open_vpn.get()) {
    to_value_result->SetWithoutPathExpansion("OpenVPN", (this->open_vpn)->ToValue());

  }
  if (this->third_party_vpn.get()) {
    to_value_result->SetWithoutPathExpansion("ThirdPartyVPN", (this->third_party_vpn)->ToValue());

  }
  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(*this->type));

  }

  return to_value_result;
}


ManagedVPNProperties::ManagedVPNProperties()
 {}

ManagedVPNProperties::~ManagedVPNProperties() {}
ManagedVPNProperties::ManagedVPNProperties(ManagedVPNProperties&& rhs)
: auto_connect(std::move(rhs.auto_connect)),
host(std::move(rhs.host)),
i_psec(std::move(rhs.i_psec)),
l2tp(std::move(rhs.l2tp)),
open_vpn(std::move(rhs.open_vpn)),
third_party_vpn(std::move(rhs.third_party_vpn)),
type(std::move(rhs.type)){
}

ManagedVPNProperties& ManagedVPNProperties::operator=(ManagedVPNProperties&& rhs)
{
auto_connect = std::move(rhs.auto_connect);
host = std::move(rhs.host);
i_psec = std::move(rhs.i_psec);
l2tp = std::move(rhs.l2tp);
open_vpn = std::move(rhs.open_vpn);
third_party_vpn = std::move(rhs.third_party_vpn);
type = std::move(rhs.type);
return *this;
}

// static
bool ManagedVPNProperties::Populate(
    const base::Value& value, ManagedVPNProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!auto_connect_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->auto_connect = std::move(temp);
      }
    }
  }

  const base::Value* host_value = NULL;
  if (dict->GetWithoutPathExpansion("Host", &host_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!host_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->host = std::move(temp);
      }
    }
  }

  const base::Value* i_psec_value = NULL;
  if (dict->GetWithoutPathExpansion("IPsec", &i_psec_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!i_psec_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedIPSecProperties> temp(new ManagedIPSecProperties());
        if (!ManagedIPSecProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->i_psec = std::move(temp);
      }
    }
  }

  const base::Value* l2tp_value = NULL;
  if (dict->GetWithoutPathExpansion("L2TP", &l2tp_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!l2tp_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedL2TPProperties> temp(new ManagedL2TPProperties());
        if (!ManagedL2TPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->l2tp = std::move(temp);
      }
    }
  }

  const base::Value* open_vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("OpenVPN", &open_vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!open_vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedOpenVPNProperties> temp(new ManagedOpenVPNProperties());
        if (!ManagedOpenVPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->open_vpn = std::move(temp);
      }
    }
  }

  const base::Value* third_party_vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("ThirdPartyVPN", &third_party_vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!third_party_vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedThirdPartyVPNProperties> temp(new ManagedThirdPartyVPNProperties());
        if (!ManagedThirdPartyVPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->third_party_vpn = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("Type", &type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->type = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedVPNProperties> ManagedVPNProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedVPNProperties> out(new ManagedVPNProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedVPNProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", (this->auto_connect)->ToValue());

  }
  if (this->host.get()) {
    to_value_result->SetWithoutPathExpansion("Host", (this->host)->ToValue());

  }
  if (this->i_psec.get()) {
    to_value_result->SetWithoutPathExpansion("IPsec", (this->i_psec)->ToValue());

  }
  if (this->l2tp.get()) {
    to_value_result->SetWithoutPathExpansion("L2TP", (this->l2tp)->ToValue());

  }
  if (this->open_vpn.get()) {
    to_value_result->SetWithoutPathExpansion("OpenVPN", (this->open_vpn)->ToValue());

  }
  if (this->third_party_vpn.get()) {
    to_value_result->SetWithoutPathExpansion("ThirdPartyVPN", (this->third_party_vpn)->ToValue());

  }
  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("Type", (this->type)->ToValue());

  }

  return to_value_result;
}


VPNStateProperties::VPNStateProperties()
 {}

VPNStateProperties::~VPNStateProperties() {}
VPNStateProperties::VPNStateProperties(VPNStateProperties&& rhs)
: type(std::move(rhs.type)),
i_psec(std::move(rhs.i_psec)),
third_party_vpn(std::move(rhs.third_party_vpn)){
}

VPNStateProperties& VPNStateProperties::operator=(VPNStateProperties&& rhs)
{
type = std::move(rhs.type);
i_psec = std::move(rhs.i_psec);
third_party_vpn = std::move(rhs.third_party_vpn);
return *this;
}

// static
bool VPNStateProperties::Populate(
    const base::Value& value, VPNStateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("Type", &type_value)) {
    return false;
  }
  {
    if (!type_value->GetAsString(&out->type)) {
      return false;
    }
  }

  const base::Value* i_psec_value = NULL;
  if (dict->GetWithoutPathExpansion("IPsec", &i_psec_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!i_psec_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IPSecProperties> temp(new IPSecProperties());
        if (!IPSecProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->i_psec = std::move(temp);
      }
    }
  }

  const base::Value* third_party_vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("ThirdPartyVPN", &third_party_vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!third_party_vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ThirdPartyVPNProperties> temp(new ThirdPartyVPNProperties());
        if (!ThirdPartyVPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->third_party_vpn = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<VPNStateProperties> VPNStateProperties::FromValue(const base::Value& value) {
  std::unique_ptr<VPNStateProperties> out(new VPNStateProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> VPNStateProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(this->type));

  if (this->i_psec.get()) {
    to_value_result->SetWithoutPathExpansion("IPsec", (this->i_psec)->ToValue());

  }
  if (this->third_party_vpn.get()) {
    to_value_result->SetWithoutPathExpansion("ThirdPartyVPN", (this->third_party_vpn)->ToValue());

  }

  return to_value_result;
}


WiFiProperties::WiFiProperties()
 {}

WiFiProperties::~WiFiProperties() {}
WiFiProperties::WiFiProperties(WiFiProperties&& rhs)
: allow_gateway_arp_polling(std::move(rhs.allow_gateway_arp_polling)),
auto_connect(std::move(rhs.auto_connect)),
bssid(std::move(rhs.bssid)),
eap(std::move(rhs.eap)),
frequency(std::move(rhs.frequency)),
frequency_list(std::move(rhs.frequency_list)),
ft_enabled(std::move(rhs.ft_enabled)),
hex_ssid(std::move(rhs.hex_ssid)),
hidden_ssid(std::move(rhs.hidden_ssid)),
passphrase(std::move(rhs.passphrase)),
ssid(std::move(rhs.ssid)),
security(std::move(rhs.security)),
signal_strength(std::move(rhs.signal_strength)),
tethering_state(std::move(rhs.tethering_state)){
}

WiFiProperties& WiFiProperties::operator=(WiFiProperties&& rhs)
{
allow_gateway_arp_polling = std::move(rhs.allow_gateway_arp_polling);
auto_connect = std::move(rhs.auto_connect);
bssid = std::move(rhs.bssid);
eap = std::move(rhs.eap);
frequency = std::move(rhs.frequency);
frequency_list = std::move(rhs.frequency_list);
ft_enabled = std::move(rhs.ft_enabled);
hex_ssid = std::move(rhs.hex_ssid);
hidden_ssid = std::move(rhs.hidden_ssid);
passphrase = std::move(rhs.passphrase);
ssid = std::move(rhs.ssid);
security = std::move(rhs.security);
signal_strength = std::move(rhs.signal_strength);
tethering_state = std::move(rhs.tethering_state);
return *this;
}

// static
bool WiFiProperties::Populate(
    const base::Value& value, WiFiProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* allow_gateway_arp_polling_value = NULL;
  if (dict->GetWithoutPathExpansion("AllowGatewayARPPolling", &allow_gateway_arp_polling_value)) {
    {
      bool temp;
      if (!allow_gateway_arp_polling_value->GetAsBoolean(&temp)) {
        out->allow_gateway_arp_polling.reset();
        return false;
      }
      else
        out->allow_gateway_arp_polling.reset(new bool(temp));
    }
  }

  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      bool temp;
      if (!auto_connect_value->GetAsBoolean(&temp)) {
        out->auto_connect.reset();
        return false;
      }
      else
        out->auto_connect.reset(new bool(temp));
    }
  }

  const base::Value* bssid_value = NULL;
  if (dict->GetWithoutPathExpansion("BSSID", &bssid_value)) {
    {
      std::string temp;
      if (!bssid_value->GetAsString(&temp)) {
        out->bssid.reset();
        return false;
      }
      else
        out->bssid.reset(new std::string(temp));
    }
  }

  const base::Value* eap_value = NULL;
  if (dict->GetWithoutPathExpansion("EAP", &eap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!eap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<EAPProperties> temp(new EAPProperties());
        if (!EAPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->eap = std::move(temp);
      }
    }
  }

  const base::Value* frequency_value = NULL;
  if (dict->GetWithoutPathExpansion("Frequency", &frequency_value)) {
    {
      int temp;
      if (!frequency_value->GetAsInteger(&temp)) {
        out->frequency.reset();
        return false;
      }
      else
        out->frequency.reset(new int(temp));
    }
  }

  const base::Value* frequency_list_value = NULL;
  if (dict->GetWithoutPathExpansion("FrequencyList", &frequency_list_value)) {
    {
      const base::ListValue* list = NULL;
      if (!frequency_list_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->frequency_list)) {
          return false;
        }
      }
    }
  }

  const base::Value* ft_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("FTEnabled", &ft_enabled_value)) {
    {
      bool temp;
      if (!ft_enabled_value->GetAsBoolean(&temp)) {
        out->ft_enabled.reset();
        return false;
      }
      else
        out->ft_enabled.reset(new bool(temp));
    }
  }

  const base::Value* hex_ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("HexSSID", &hex_ssid_value)) {
    {
      std::string temp;
      if (!hex_ssid_value->GetAsString(&temp)) {
        out->hex_ssid.reset();
        return false;
      }
      else
        out->hex_ssid.reset(new std::string(temp));
    }
  }

  const base::Value* hidden_ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("HiddenSSID", &hidden_ssid_value)) {
    {
      bool temp;
      if (!hidden_ssid_value->GetAsBoolean(&temp)) {
        out->hidden_ssid.reset();
        return false;
      }
      else
        out->hidden_ssid.reset(new bool(temp));
    }
  }

  const base::Value* passphrase_value = NULL;
  if (dict->GetWithoutPathExpansion("Passphrase", &passphrase_value)) {
    {
      std::string temp;
      if (!passphrase_value->GetAsString(&temp)) {
        out->passphrase.reset();
        return false;
      }
      else
        out->passphrase.reset(new std::string(temp));
    }
  }

  const base::Value* ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("SSID", &ssid_value)) {
    {
      std::string temp;
      if (!ssid_value->GetAsString(&temp)) {
        out->ssid.reset();
        return false;
      }
      else
        out->ssid.reset(new std::string(temp));
    }
  }

  const base::Value* security_value = NULL;
  if (dict->GetWithoutPathExpansion("Security", &security_value)) {
    {
      std::string temp;
      if (!security_value->GetAsString(&temp)) {
        out->security.reset();
        return false;
      }
      else
        out->security.reset(new std::string(temp));
    }
  }

  const base::Value* signal_strength_value = NULL;
  if (dict->GetWithoutPathExpansion("SignalStrength", &signal_strength_value)) {
    {
      int temp;
      if (!signal_strength_value->GetAsInteger(&temp)) {
        out->signal_strength.reset();
        return false;
      }
      else
        out->signal_strength.reset(new int(temp));
    }
  }

  const base::Value* tethering_state_value = NULL;
  if (dict->GetWithoutPathExpansion("TetheringState", &tethering_state_value)) {
    {
      std::string temp;
      if (!tethering_state_value->GetAsString(&temp)) {
        out->tethering_state.reset();
        return false;
      }
      else
        out->tethering_state.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<WiFiProperties> WiFiProperties::FromValue(const base::Value& value) {
  std::unique_ptr<WiFiProperties> out(new WiFiProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> WiFiProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->allow_gateway_arp_polling.get()) {
    to_value_result->SetWithoutPathExpansion("AllowGatewayARPPolling", std::make_unique<base::Value>(*this->allow_gateway_arp_polling));

  }
  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", std::make_unique<base::Value>(*this->auto_connect));

  }
  if (this->bssid.get()) {
    to_value_result->SetWithoutPathExpansion("BSSID", std::make_unique<base::Value>(*this->bssid));

  }
  if (this->eap.get()) {
    to_value_result->SetWithoutPathExpansion("EAP", (this->eap)->ToValue());

  }
  if (this->frequency.get()) {
    to_value_result->SetWithoutPathExpansion("Frequency", std::make_unique<base::Value>(*this->frequency));

  }
  if (this->frequency_list.get()) {
    to_value_result->SetWithoutPathExpansion("FrequencyList", json_schema_compiler::util::CreateValueFromOptionalArray(this->frequency_list));

  }
  if (this->ft_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("FTEnabled", std::make_unique<base::Value>(*this->ft_enabled));

  }
  if (this->hex_ssid.get()) {
    to_value_result->SetWithoutPathExpansion("HexSSID", std::make_unique<base::Value>(*this->hex_ssid));

  }
  if (this->hidden_ssid.get()) {
    to_value_result->SetWithoutPathExpansion("HiddenSSID", std::make_unique<base::Value>(*this->hidden_ssid));

  }
  if (this->passphrase.get()) {
    to_value_result->SetWithoutPathExpansion("Passphrase", std::make_unique<base::Value>(*this->passphrase));

  }
  if (this->ssid.get()) {
    to_value_result->SetWithoutPathExpansion("SSID", std::make_unique<base::Value>(*this->ssid));

  }
  if (this->security.get()) {
    to_value_result->SetWithoutPathExpansion("Security", std::make_unique<base::Value>(*this->security));

  }
  if (this->signal_strength.get()) {
    to_value_result->SetWithoutPathExpansion("SignalStrength", std::make_unique<base::Value>(*this->signal_strength));

  }
  if (this->tethering_state.get()) {
    to_value_result->SetWithoutPathExpansion("TetheringState", std::make_unique<base::Value>(*this->tethering_state));

  }

  return to_value_result;
}


ManagedWiFiProperties::ManagedWiFiProperties()
 {}

ManagedWiFiProperties::~ManagedWiFiProperties() {}
ManagedWiFiProperties::ManagedWiFiProperties(ManagedWiFiProperties&& rhs)
: allow_gateway_arp_polling(std::move(rhs.allow_gateway_arp_polling)),
auto_connect(std::move(rhs.auto_connect)),
bssid(std::move(rhs.bssid)),
eap(std::move(rhs.eap)),
frequency(std::move(rhs.frequency)),
frequency_list(std::move(rhs.frequency_list)),
ft_enabled(std::move(rhs.ft_enabled)),
hex_ssid(std::move(rhs.hex_ssid)),
hidden_ssid(std::move(rhs.hidden_ssid)),
passphrase(std::move(rhs.passphrase)),
ssid(std::move(rhs.ssid)),
security(std::move(rhs.security)),
signal_strength(std::move(rhs.signal_strength)),
tethering_state(std::move(rhs.tethering_state)){
}

ManagedWiFiProperties& ManagedWiFiProperties::operator=(ManagedWiFiProperties&& rhs)
{
allow_gateway_arp_polling = std::move(rhs.allow_gateway_arp_polling);
auto_connect = std::move(rhs.auto_connect);
bssid = std::move(rhs.bssid);
eap = std::move(rhs.eap);
frequency = std::move(rhs.frequency);
frequency_list = std::move(rhs.frequency_list);
ft_enabled = std::move(rhs.ft_enabled);
hex_ssid = std::move(rhs.hex_ssid);
hidden_ssid = std::move(rhs.hidden_ssid);
passphrase = std::move(rhs.passphrase);
ssid = std::move(rhs.ssid);
security = std::move(rhs.security);
signal_strength = std::move(rhs.signal_strength);
tethering_state = std::move(rhs.tethering_state);
return *this;
}

// static
bool ManagedWiFiProperties::Populate(
    const base::Value& value, ManagedWiFiProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* allow_gateway_arp_polling_value = NULL;
  if (dict->GetWithoutPathExpansion("AllowGatewayARPPolling", &allow_gateway_arp_polling_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!allow_gateway_arp_polling_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->allow_gateway_arp_polling = std::move(temp);
      }
    }
  }

  const base::Value* auto_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AutoConnect", &auto_connect_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!auto_connect_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->auto_connect = std::move(temp);
      }
    }
  }

  const base::Value* bssid_value = NULL;
  if (dict->GetWithoutPathExpansion("BSSID", &bssid_value)) {
    {
      std::string temp;
      if (!bssid_value->GetAsString(&temp)) {
        out->bssid.reset();
        return false;
      }
      else
        out->bssid.reset(new std::string(temp));
    }
  }

  const base::Value* eap_value = NULL;
  if (dict->GetWithoutPathExpansion("EAP", &eap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!eap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedEAPProperties> temp(new ManagedEAPProperties());
        if (!ManagedEAPProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->eap = std::move(temp);
      }
    }
  }

  const base::Value* frequency_value = NULL;
  if (dict->GetWithoutPathExpansion("Frequency", &frequency_value)) {
    {
      int temp;
      if (!frequency_value->GetAsInteger(&temp)) {
        out->frequency.reset();
        return false;
      }
      else
        out->frequency.reset(new int(temp));
    }
  }

  const base::Value* frequency_list_value = NULL;
  if (dict->GetWithoutPathExpansion("FrequencyList", &frequency_list_value)) {
    {
      const base::ListValue* list = NULL;
      if (!frequency_list_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->frequency_list)) {
          return false;
        }
      }
    }
  }

  const base::Value* ft_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("FTEnabled", &ft_enabled_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ft_enabled_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ft_enabled = std::move(temp);
      }
    }
  }

  const base::Value* hex_ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("HexSSID", &hex_ssid_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!hex_ssid_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->hex_ssid = std::move(temp);
      }
    }
  }

  const base::Value* hidden_ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("HiddenSSID", &hidden_ssid_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!hidden_ssid_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->hidden_ssid = std::move(temp);
      }
    }
  }

  const base::Value* passphrase_value = NULL;
  if (dict->GetWithoutPathExpansion("Passphrase", &passphrase_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!passphrase_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->passphrase = std::move(temp);
      }
    }
  }

  const base::Value* ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("SSID", &ssid_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ssid_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ssid = std::move(temp);
      }
    }
  }

  const base::Value* security_value = NULL;
  if (!dict->GetWithoutPathExpansion("Security", &security_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!security_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ManagedDOMString::Populate(*dictionary, &out->security)) {
      return false;
    }
  }

  const base::Value* signal_strength_value = NULL;
  if (dict->GetWithoutPathExpansion("SignalStrength", &signal_strength_value)) {
    {
      int temp;
      if (!signal_strength_value->GetAsInteger(&temp)) {
        out->signal_strength.reset();
        return false;
      }
      else
        out->signal_strength.reset(new int(temp));
    }
  }

  const base::Value* tethering_state_value = NULL;
  if (dict->GetWithoutPathExpansion("TetheringState", &tethering_state_value)) {
    {
      std::string temp;
      if (!tethering_state_value->GetAsString(&temp)) {
        out->tethering_state.reset();
        return false;
      }
      else
        out->tethering_state.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedWiFiProperties> ManagedWiFiProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedWiFiProperties> out(new ManagedWiFiProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedWiFiProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->allow_gateway_arp_polling.get()) {
    to_value_result->SetWithoutPathExpansion("AllowGatewayARPPolling", (this->allow_gateway_arp_polling)->ToValue());

  }
  if (this->auto_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AutoConnect", (this->auto_connect)->ToValue());

  }
  if (this->bssid.get()) {
    to_value_result->SetWithoutPathExpansion("BSSID", std::make_unique<base::Value>(*this->bssid));

  }
  if (this->eap.get()) {
    to_value_result->SetWithoutPathExpansion("EAP", (this->eap)->ToValue());

  }
  if (this->frequency.get()) {
    to_value_result->SetWithoutPathExpansion("Frequency", std::make_unique<base::Value>(*this->frequency));

  }
  if (this->frequency_list.get()) {
    to_value_result->SetWithoutPathExpansion("FrequencyList", json_schema_compiler::util::CreateValueFromOptionalArray(this->frequency_list));

  }
  if (this->ft_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("FTEnabled", (this->ft_enabled)->ToValue());

  }
  if (this->hex_ssid.get()) {
    to_value_result->SetWithoutPathExpansion("HexSSID", (this->hex_ssid)->ToValue());

  }
  if (this->hidden_ssid.get()) {
    to_value_result->SetWithoutPathExpansion("HiddenSSID", (this->hidden_ssid)->ToValue());

  }
  if (this->passphrase.get()) {
    to_value_result->SetWithoutPathExpansion("Passphrase", (this->passphrase)->ToValue());

  }
  if (this->ssid.get()) {
    to_value_result->SetWithoutPathExpansion("SSID", (this->ssid)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("Security", (this->security).ToValue());

  if (this->signal_strength.get()) {
    to_value_result->SetWithoutPathExpansion("SignalStrength", std::make_unique<base::Value>(*this->signal_strength));

  }
  if (this->tethering_state.get()) {
    to_value_result->SetWithoutPathExpansion("TetheringState", std::make_unique<base::Value>(*this->tethering_state));

  }

  return to_value_result;
}


WiFiStateProperties::WiFiStateProperties()
 {}

WiFiStateProperties::~WiFiStateProperties() {}
WiFiStateProperties::WiFiStateProperties(WiFiStateProperties&& rhs)
: bssid(std::move(rhs.bssid)),
eap(std::move(rhs.eap)),
frequency(std::move(rhs.frequency)),
hex_ssid(std::move(rhs.hex_ssid)),
security(std::move(rhs.security)),
signal_strength(std::move(rhs.signal_strength)),
ssid(std::move(rhs.ssid)),
tethering_state(std::move(rhs.tethering_state)){
}

WiFiStateProperties& WiFiStateProperties::operator=(WiFiStateProperties&& rhs)
{
bssid = std::move(rhs.bssid);
eap = std::move(rhs.eap);
frequency = std::move(rhs.frequency);
hex_ssid = std::move(rhs.hex_ssid);
security = std::move(rhs.security);
signal_strength = std::move(rhs.signal_strength);
ssid = std::move(rhs.ssid);
tethering_state = std::move(rhs.tethering_state);
return *this;
}

// static
bool WiFiStateProperties::Populate(
    const base::Value& value, WiFiStateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* bssid_value = NULL;
  if (dict->GetWithoutPathExpansion("BSSID", &bssid_value)) {
    {
      std::string temp;
      if (!bssid_value->GetAsString(&temp)) {
        out->bssid.reset();
        return false;
      }
      else
        out->bssid.reset(new std::string(temp));
    }
  }

  const base::Value* eap_value = NULL;
  if (dict->GetWithoutPathExpansion("EAP", &eap_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!eap_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<EAPStateProperties> temp(new EAPStateProperties());
        if (!EAPStateProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->eap = std::move(temp);
      }
    }
  }

  const base::Value* frequency_value = NULL;
  if (dict->GetWithoutPathExpansion("Frequency", &frequency_value)) {
    {
      int temp;
      if (!frequency_value->GetAsInteger(&temp)) {
        out->frequency.reset();
        return false;
      }
      else
        out->frequency.reset(new int(temp));
    }
  }

  const base::Value* hex_ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("HexSSID", &hex_ssid_value)) {
    {
      std::string temp;
      if (!hex_ssid_value->GetAsString(&temp)) {
        out->hex_ssid.reset();
        return false;
      }
      else
        out->hex_ssid.reset(new std::string(temp));
    }
  }

  const base::Value* security_value = NULL;
  if (!dict->GetWithoutPathExpansion("Security", &security_value)) {
    return false;
  }
  {
    if (!security_value->GetAsString(&out->security)) {
      return false;
    }
  }

  const base::Value* signal_strength_value = NULL;
  if (dict->GetWithoutPathExpansion("SignalStrength", &signal_strength_value)) {
    {
      int temp;
      if (!signal_strength_value->GetAsInteger(&temp)) {
        out->signal_strength.reset();
        return false;
      }
      else
        out->signal_strength.reset(new int(temp));
    }
  }

  const base::Value* ssid_value = NULL;
  if (dict->GetWithoutPathExpansion("SSID", &ssid_value)) {
    {
      std::string temp;
      if (!ssid_value->GetAsString(&temp)) {
        out->ssid.reset();
        return false;
      }
      else
        out->ssid.reset(new std::string(temp));
    }
  }

  const base::Value* tethering_state_value = NULL;
  if (dict->GetWithoutPathExpansion("TetheringState", &tethering_state_value)) {
    {
      std::string temp;
      if (!tethering_state_value->GetAsString(&temp)) {
        out->tethering_state.reset();
        return false;
      }
      else
        out->tethering_state.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<WiFiStateProperties> WiFiStateProperties::FromValue(const base::Value& value) {
  std::unique_ptr<WiFiStateProperties> out(new WiFiStateProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> WiFiStateProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->bssid.get()) {
    to_value_result->SetWithoutPathExpansion("BSSID", std::make_unique<base::Value>(*this->bssid));

  }
  if (this->eap.get()) {
    to_value_result->SetWithoutPathExpansion("EAP", (this->eap)->ToValue());

  }
  if (this->frequency.get()) {
    to_value_result->SetWithoutPathExpansion("Frequency", std::make_unique<base::Value>(*this->frequency));

  }
  if (this->hex_ssid.get()) {
    to_value_result->SetWithoutPathExpansion("HexSSID", std::make_unique<base::Value>(*this->hex_ssid));

  }
  to_value_result->SetWithoutPathExpansion("Security", std::make_unique<base::Value>(this->security));

  if (this->signal_strength.get()) {
    to_value_result->SetWithoutPathExpansion("SignalStrength", std::make_unique<base::Value>(*this->signal_strength));

  }
  if (this->ssid.get()) {
    to_value_result->SetWithoutPathExpansion("SSID", std::make_unique<base::Value>(*this->ssid));

  }
  if (this->tethering_state.get()) {
    to_value_result->SetWithoutPathExpansion("TetheringState", std::make_unique<base::Value>(*this->tethering_state));

  }

  return to_value_result;
}


NetworkConfigProperties::NetworkConfigProperties()
: ip_address_config_type(IP_CONFIG_TYPE_NONE),
name_servers_config_type(IP_CONFIG_TYPE_NONE),
type(NETWORK_TYPE_NONE) {}

NetworkConfigProperties::~NetworkConfigProperties() {}
NetworkConfigProperties::NetworkConfigProperties(NetworkConfigProperties&& rhs)
: cellular(std::move(rhs.cellular)),
ethernet(std::move(rhs.ethernet)),
guid(std::move(rhs.guid)),
ip_address_config_type(rhs.ip_address_config_type),
name(std::move(rhs.name)),
name_servers_config_type(rhs.name_servers_config_type),
priority(std::move(rhs.priority)),
proxy_settings(std::move(rhs.proxy_settings)),
static_ip_config(std::move(rhs.static_ip_config)),
type(rhs.type),
vpn(std::move(rhs.vpn)),
wi_fi(std::move(rhs.wi_fi)){
}

NetworkConfigProperties& NetworkConfigProperties::operator=(NetworkConfigProperties&& rhs)
{
cellular = std::move(rhs.cellular);
ethernet = std::move(rhs.ethernet);
guid = std::move(rhs.guid);
ip_address_config_type = rhs.ip_address_config_type;
name = std::move(rhs.name);
name_servers_config_type = rhs.name_servers_config_type;
priority = std::move(rhs.priority);
proxy_settings = std::move(rhs.proxy_settings);
static_ip_config = std::move(rhs.static_ip_config);
type = rhs.type;
vpn = std::move(rhs.vpn);
wi_fi = std::move(rhs.wi_fi);
return *this;
}

// static
bool NetworkConfigProperties::Populate(
    const base::Value& value, NetworkConfigProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->ip_address_config_type = IP_CONFIG_TYPE_NONE;
  out->name_servers_config_type = IP_CONFIG_TYPE_NONE;
  out->type = NETWORK_TYPE_NONE;
  const base::Value* cellular_value = NULL;
  if (dict->GetWithoutPathExpansion("Cellular", &cellular_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!cellular_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CellularProperties> temp(new CellularProperties());
        if (!CellularProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->cellular = std::move(temp);
      }
    }
  }

  const base::Value* ethernet_value = NULL;
  if (dict->GetWithoutPathExpansion("Ethernet", &ethernet_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ethernet_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<EthernetProperties> temp(new EthernetProperties());
        if (!EthernetProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ethernet = std::move(temp);
      }
    }
  }

  const base::Value* guid_value = NULL;
  if (dict->GetWithoutPathExpansion("GUID", &guid_value)) {
    {
      std::string temp;
      if (!guid_value->GetAsString(&temp)) {
        out->guid.reset();
        return false;
      }
      else
        out->guid.reset(new std::string(temp));
    }
  }

  const base::Value* ip_address_config_type_value = NULL;
  if (dict->GetWithoutPathExpansion("IPAddressConfigType", &ip_address_config_type_value)) {
    {
      std::string ip_config_type_as_string;
      if (!ip_address_config_type_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->ip_address_config_type = ParseIPConfigType(ip_config_type_as_string);
      if (out->ip_address_config_type == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->ip_address_config_type = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* name_servers_config_type_value = NULL;
  if (dict->GetWithoutPathExpansion("NameServersConfigType", &name_servers_config_type_value)) {
    {
      std::string ip_config_type_as_string;
      if (!name_servers_config_type_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->name_servers_config_type = ParseIPConfigType(ip_config_type_as_string);
      if (out->name_servers_config_type == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->name_servers_config_type = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* priority_value = NULL;
  if (dict->GetWithoutPathExpansion("Priority", &priority_value)) {
    {
      int temp;
      if (!priority_value->GetAsInteger(&temp)) {
        out->priority.reset();
        return false;
      }
      else
        out->priority.reset(new int(temp));
    }
  }

  const base::Value* proxy_settings_value = NULL;
  if (dict->GetWithoutPathExpansion("ProxySettings", &proxy_settings_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!proxy_settings_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ProxySettings> temp(new ProxySettings());
        if (!ProxySettings::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->proxy_settings = std::move(temp);
      }
    }
  }

  const base::Value* static_ip_config_value = NULL;
  if (dict->GetWithoutPathExpansion("StaticIPConfig", &static_ip_config_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!static_ip_config_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IPConfigProperties> temp(new IPConfigProperties());
        if (!IPConfigProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->static_ip_config = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("Type", &type_value)) {
    {
      std::string network_type_as_string;
      if (!type_value->GetAsString(&network_type_as_string)) {
        return false;
      }
      out->type = ParseNetworkType(network_type_as_string);
      if (out->type == NETWORK_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = NETWORK_TYPE_NONE;
  }

  const base::Value* vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("VPN", &vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<VPNProperties> temp(new VPNProperties());
        if (!VPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->vpn = std::move(temp);
      }
    }
  }

  const base::Value* wi_fi_value = NULL;
  if (dict->GetWithoutPathExpansion("WiFi", &wi_fi_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!wi_fi_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<WiFiProperties> temp(new WiFiProperties());
        if (!WiFiProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->wi_fi = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<NetworkConfigProperties> NetworkConfigProperties::FromValue(const base::Value& value) {
  std::unique_ptr<NetworkConfigProperties> out(new NetworkConfigProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NetworkConfigProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->cellular.get()) {
    to_value_result->SetWithoutPathExpansion("Cellular", (this->cellular)->ToValue());

  }
  if (this->ethernet.get()) {
    to_value_result->SetWithoutPathExpansion("Ethernet", (this->ethernet)->ToValue());

  }
  if (this->guid.get()) {
    to_value_result->SetWithoutPathExpansion("GUID", std::make_unique<base::Value>(*this->guid));

  }
  if (this->ip_address_config_type != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("IPAddressConfigType", std::make_unique<base::Value>(networking_private::ToString(this->ip_address_config_type)));

  }
  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", std::make_unique<base::Value>(*this->name));

  }
  if (this->name_servers_config_type != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("NameServersConfigType", std::make_unique<base::Value>(networking_private::ToString(this->name_servers_config_type)));

  }
  if (this->priority.get()) {
    to_value_result->SetWithoutPathExpansion("Priority", std::make_unique<base::Value>(*this->priority));

  }
  if (this->proxy_settings.get()) {
    to_value_result->SetWithoutPathExpansion("ProxySettings", (this->proxy_settings)->ToValue());

  }
  if (this->static_ip_config.get()) {
    to_value_result->SetWithoutPathExpansion("StaticIPConfig", (this->static_ip_config)->ToValue());

  }
  if (this->type != NETWORK_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(networking_private::ToString(this->type)));

  }
  if (this->vpn.get()) {
    to_value_result->SetWithoutPathExpansion("VPN", (this->vpn)->ToValue());

  }
  if (this->wi_fi.get()) {
    to_value_result->SetWithoutPathExpansion("WiFi", (this->wi_fi)->ToValue());

  }

  return to_value_result;
}


NetworkProperties::NetworkProperties()
: connection_state(CONNECTION_STATE_TYPE_NONE),
ip_address_config_type(IP_CONFIG_TYPE_NONE),
name_servers_config_type(IP_CONFIG_TYPE_NONE),
type(NETWORK_TYPE_NONE) {}

NetworkProperties::~NetworkProperties() {}
NetworkProperties::NetworkProperties(NetworkProperties&& rhs)
: cellular(std::move(rhs.cellular)),
connectable(std::move(rhs.connectable)),
connection_state(rhs.connection_state),
error_state(std::move(rhs.error_state)),
ethernet(std::move(rhs.ethernet)),
guid(std::move(rhs.guid)),
ip_address_config_type(rhs.ip_address_config_type),
ip_configs(std::move(rhs.ip_configs)),
mac_address(std::move(rhs.mac_address)),
metered(std::move(rhs.metered)),
name(std::move(rhs.name)),
name_servers_config_type(rhs.name_servers_config_type),
priority(std::move(rhs.priority)),
proxy_settings(std::move(rhs.proxy_settings)),
restricted_connectivity(std::move(rhs.restricted_connectivity)),
static_ip_config(std::move(rhs.static_ip_config)),
saved_ip_config(std::move(rhs.saved_ip_config)),
source(std::move(rhs.source)),
tether(std::move(rhs.tether)),
type(rhs.type),
vpn(std::move(rhs.vpn)),
wi_fi(std::move(rhs.wi_fi)){
}

NetworkProperties& NetworkProperties::operator=(NetworkProperties&& rhs)
{
cellular = std::move(rhs.cellular);
connectable = std::move(rhs.connectable);
connection_state = rhs.connection_state;
error_state = std::move(rhs.error_state);
ethernet = std::move(rhs.ethernet);
guid = std::move(rhs.guid);
ip_address_config_type = rhs.ip_address_config_type;
ip_configs = std::move(rhs.ip_configs);
mac_address = std::move(rhs.mac_address);
metered = std::move(rhs.metered);
name = std::move(rhs.name);
name_servers_config_type = rhs.name_servers_config_type;
priority = std::move(rhs.priority);
proxy_settings = std::move(rhs.proxy_settings);
restricted_connectivity = std::move(rhs.restricted_connectivity);
static_ip_config = std::move(rhs.static_ip_config);
saved_ip_config = std::move(rhs.saved_ip_config);
source = std::move(rhs.source);
tether = std::move(rhs.tether);
type = rhs.type;
vpn = std::move(rhs.vpn);
wi_fi = std::move(rhs.wi_fi);
return *this;
}

// static
bool NetworkProperties::Populate(
    const base::Value& value, NetworkProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->connection_state = CONNECTION_STATE_TYPE_NONE;
  out->ip_address_config_type = IP_CONFIG_TYPE_NONE;
  out->name_servers_config_type = IP_CONFIG_TYPE_NONE;
  const base::Value* cellular_value = NULL;
  if (dict->GetWithoutPathExpansion("Cellular", &cellular_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!cellular_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CellularProperties> temp(new CellularProperties());
        if (!CellularProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->cellular = std::move(temp);
      }
    }
  }

  const base::Value* connectable_value = NULL;
  if (dict->GetWithoutPathExpansion("Connectable", &connectable_value)) {
    {
      bool temp;
      if (!connectable_value->GetAsBoolean(&temp)) {
        out->connectable.reset();
        return false;
      }
      else
        out->connectable.reset(new bool(temp));
    }
  }

  const base::Value* connection_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ConnectionState", &connection_state_value)) {
    {
      std::string connection_state_type_as_string;
      if (!connection_state_value->GetAsString(&connection_state_type_as_string)) {
        return false;
      }
      out->connection_state = ParseConnectionStateType(connection_state_type_as_string);
      if (out->connection_state == CONNECTION_STATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->connection_state = CONNECTION_STATE_TYPE_NONE;
  }

  const base::Value* error_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ErrorState", &error_state_value)) {
    {
      std::string temp;
      if (!error_state_value->GetAsString(&temp)) {
        out->error_state.reset();
        return false;
      }
      else
        out->error_state.reset(new std::string(temp));
    }
  }

  const base::Value* ethernet_value = NULL;
  if (dict->GetWithoutPathExpansion("Ethernet", &ethernet_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ethernet_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<EthernetProperties> temp(new EthernetProperties());
        if (!EthernetProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ethernet = std::move(temp);
      }
    }
  }

  const base::Value* guid_value = NULL;
  if (!dict->GetWithoutPathExpansion("GUID", &guid_value)) {
    return false;
  }
  {
    if (!guid_value->GetAsString(&out->guid)) {
      return false;
    }
  }

  const base::Value* ip_address_config_type_value = NULL;
  if (dict->GetWithoutPathExpansion("IPAddressConfigType", &ip_address_config_type_value)) {
    {
      std::string ip_config_type_as_string;
      if (!ip_address_config_type_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->ip_address_config_type = ParseIPConfigType(ip_config_type_as_string);
      if (out->ip_address_config_type == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->ip_address_config_type = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* ip_configs_value = NULL;
  if (dict->GetWithoutPathExpansion("IPConfigs", &ip_configs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!ip_configs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->ip_configs)) {
          return false;
        }
      }
    }
  }

  const base::Value* mac_address_value = NULL;
  if (dict->GetWithoutPathExpansion("MacAddress", &mac_address_value)) {
    {
      std::string temp;
      if (!mac_address_value->GetAsString(&temp)) {
        out->mac_address.reset();
        return false;
      }
      else
        out->mac_address.reset(new std::string(temp));
    }
  }

  const base::Value* metered_value = NULL;
  if (dict->GetWithoutPathExpansion("Metered", &metered_value)) {
    {
      bool temp;
      if (!metered_value->GetAsBoolean(&temp)) {
        out->metered.reset();
        return false;
      }
      else
        out->metered.reset(new bool(temp));
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* name_servers_config_type_value = NULL;
  if (dict->GetWithoutPathExpansion("NameServersConfigType", &name_servers_config_type_value)) {
    {
      std::string ip_config_type_as_string;
      if (!name_servers_config_type_value->GetAsString(&ip_config_type_as_string)) {
        return false;
      }
      out->name_servers_config_type = ParseIPConfigType(ip_config_type_as_string);
      if (out->name_servers_config_type == IP_CONFIG_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->name_servers_config_type = IP_CONFIG_TYPE_NONE;
  }

  const base::Value* priority_value = NULL;
  if (dict->GetWithoutPathExpansion("Priority", &priority_value)) {
    {
      int temp;
      if (!priority_value->GetAsInteger(&temp)) {
        out->priority.reset();
        return false;
      }
      else
        out->priority.reset(new int(temp));
    }
  }

  const base::Value* proxy_settings_value = NULL;
  if (dict->GetWithoutPathExpansion("ProxySettings", &proxy_settings_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!proxy_settings_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ProxySettings> temp(new ProxySettings());
        if (!ProxySettings::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->proxy_settings = std::move(temp);
      }
    }
  }

  const base::Value* restricted_connectivity_value = NULL;
  if (dict->GetWithoutPathExpansion("RestrictedConnectivity", &restricted_connectivity_value)) {
    {
      bool temp;
      if (!restricted_connectivity_value->GetAsBoolean(&temp)) {
        out->restricted_connectivity.reset();
        return false;
      }
      else
        out->restricted_connectivity.reset(new bool(temp));
    }
  }

  const base::Value* static_ip_config_value = NULL;
  if (dict->GetWithoutPathExpansion("StaticIPConfig", &static_ip_config_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!static_ip_config_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IPConfigProperties> temp(new IPConfigProperties());
        if (!IPConfigProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->static_ip_config = std::move(temp);
      }
    }
  }

  const base::Value* saved_ip_config_value = NULL;
  if (dict->GetWithoutPathExpansion("SavedIPConfig", &saved_ip_config_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!saved_ip_config_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IPConfigProperties> temp(new IPConfigProperties());
        if (!IPConfigProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->saved_ip_config = std::move(temp);
      }
    }
  }

  const base::Value* source_value = NULL;
  if (dict->GetWithoutPathExpansion("Source", &source_value)) {
    {
      std::string temp;
      if (!source_value->GetAsString(&temp)) {
        out->source.reset();
        return false;
      }
      else
        out->source.reset(new std::string(temp));
    }
  }

  const base::Value* tether_value = NULL;
  if (dict->GetWithoutPathExpansion("Tether", &tether_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tether_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<TetherProperties> temp(new TetherProperties());
        if (!TetherProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tether = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("Type", &type_value)) {
    return false;
  }
  {
    std::string network_type_as_string;
    if (!type_value->GetAsString(&network_type_as_string)) {
      return false;
    }
    out->type = ParseNetworkType(network_type_as_string);
    if (out->type == NETWORK_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("VPN", &vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<VPNProperties> temp(new VPNProperties());
        if (!VPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->vpn = std::move(temp);
      }
    }
  }

  const base::Value* wi_fi_value = NULL;
  if (dict->GetWithoutPathExpansion("WiFi", &wi_fi_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!wi_fi_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<WiFiProperties> temp(new WiFiProperties());
        if (!WiFiProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->wi_fi = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<NetworkProperties> NetworkProperties::FromValue(const base::Value& value) {
  std::unique_ptr<NetworkProperties> out(new NetworkProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NetworkProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->cellular.get()) {
    to_value_result->SetWithoutPathExpansion("Cellular", (this->cellular)->ToValue());

  }
  if (this->connectable.get()) {
    to_value_result->SetWithoutPathExpansion("Connectable", std::make_unique<base::Value>(*this->connectable));

  }
  if (this->connection_state != CONNECTION_STATE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("ConnectionState", std::make_unique<base::Value>(networking_private::ToString(this->connection_state)));

  }
  if (this->error_state.get()) {
    to_value_result->SetWithoutPathExpansion("ErrorState", std::make_unique<base::Value>(*this->error_state));

  }
  if (this->ethernet.get()) {
    to_value_result->SetWithoutPathExpansion("Ethernet", (this->ethernet)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("GUID", std::make_unique<base::Value>(this->guid));

  if (this->ip_address_config_type != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("IPAddressConfigType", std::make_unique<base::Value>(networking_private::ToString(this->ip_address_config_type)));

  }
  if (this->ip_configs.get()) {
    to_value_result->SetWithoutPathExpansion("IPConfigs", json_schema_compiler::util::CreateValueFromOptionalArray(this->ip_configs));

  }
  if (this->mac_address.get()) {
    to_value_result->SetWithoutPathExpansion("MacAddress", std::make_unique<base::Value>(*this->mac_address));

  }
  if (this->metered.get()) {
    to_value_result->SetWithoutPathExpansion("Metered", std::make_unique<base::Value>(*this->metered));

  }
  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", std::make_unique<base::Value>(*this->name));

  }
  if (this->name_servers_config_type != IP_CONFIG_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("NameServersConfigType", std::make_unique<base::Value>(networking_private::ToString(this->name_servers_config_type)));

  }
  if (this->priority.get()) {
    to_value_result->SetWithoutPathExpansion("Priority", std::make_unique<base::Value>(*this->priority));

  }
  if (this->proxy_settings.get()) {
    to_value_result->SetWithoutPathExpansion("ProxySettings", (this->proxy_settings)->ToValue());

  }
  if (this->restricted_connectivity.get()) {
    to_value_result->SetWithoutPathExpansion("RestrictedConnectivity", std::make_unique<base::Value>(*this->restricted_connectivity));

  }
  if (this->static_ip_config.get()) {
    to_value_result->SetWithoutPathExpansion("StaticIPConfig", (this->static_ip_config)->ToValue());

  }
  if (this->saved_ip_config.get()) {
    to_value_result->SetWithoutPathExpansion("SavedIPConfig", (this->saved_ip_config)->ToValue());

  }
  if (this->source.get()) {
    to_value_result->SetWithoutPathExpansion("Source", std::make_unique<base::Value>(*this->source));

  }
  if (this->tether.get()) {
    to_value_result->SetWithoutPathExpansion("Tether", (this->tether)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(networking_private::ToString(this->type)));

  if (this->vpn.get()) {
    to_value_result->SetWithoutPathExpansion("VPN", (this->vpn)->ToValue());

  }
  if (this->wi_fi.get()) {
    to_value_result->SetWithoutPathExpansion("WiFi", (this->wi_fi)->ToValue());

  }

  return to_value_result;
}


ManagedProperties::ManagedProperties()
: connection_state(CONNECTION_STATE_TYPE_NONE),
type(NETWORK_TYPE_NONE) {}

ManagedProperties::~ManagedProperties() {}
ManagedProperties::ManagedProperties(ManagedProperties&& rhs)
: cellular(std::move(rhs.cellular)),
connectable(std::move(rhs.connectable)),
connection_state(rhs.connection_state),
error_state(std::move(rhs.error_state)),
ethernet(std::move(rhs.ethernet)),
guid(std::move(rhs.guid)),
ip_address_config_type(std::move(rhs.ip_address_config_type)),
ip_configs(std::move(rhs.ip_configs)),
mac_address(std::move(rhs.mac_address)),
metered(std::move(rhs.metered)),
name(std::move(rhs.name)),
name_servers_config_type(std::move(rhs.name_servers_config_type)),
priority(std::move(rhs.priority)),
proxy_settings(std::move(rhs.proxy_settings)),
restricted_connectivity(std::move(rhs.restricted_connectivity)),
static_ip_config(std::move(rhs.static_ip_config)),
saved_ip_config(std::move(rhs.saved_ip_config)),
source(std::move(rhs.source)),
tether(std::move(rhs.tether)),
type(rhs.type),
vpn(std::move(rhs.vpn)),
wi_fi(std::move(rhs.wi_fi)){
}

ManagedProperties& ManagedProperties::operator=(ManagedProperties&& rhs)
{
cellular = std::move(rhs.cellular);
connectable = std::move(rhs.connectable);
connection_state = rhs.connection_state;
error_state = std::move(rhs.error_state);
ethernet = std::move(rhs.ethernet);
guid = std::move(rhs.guid);
ip_address_config_type = std::move(rhs.ip_address_config_type);
ip_configs = std::move(rhs.ip_configs);
mac_address = std::move(rhs.mac_address);
metered = std::move(rhs.metered);
name = std::move(rhs.name);
name_servers_config_type = std::move(rhs.name_servers_config_type);
priority = std::move(rhs.priority);
proxy_settings = std::move(rhs.proxy_settings);
restricted_connectivity = std::move(rhs.restricted_connectivity);
static_ip_config = std::move(rhs.static_ip_config);
saved_ip_config = std::move(rhs.saved_ip_config);
source = std::move(rhs.source);
tether = std::move(rhs.tether);
type = rhs.type;
vpn = std::move(rhs.vpn);
wi_fi = std::move(rhs.wi_fi);
return *this;
}

// static
bool ManagedProperties::Populate(
    const base::Value& value, ManagedProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->connection_state = CONNECTION_STATE_TYPE_NONE;
  const base::Value* cellular_value = NULL;
  if (dict->GetWithoutPathExpansion("Cellular", &cellular_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!cellular_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedCellularProperties> temp(new ManagedCellularProperties());
        if (!ManagedCellularProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->cellular = std::move(temp);
      }
    }
  }

  const base::Value* connectable_value = NULL;
  if (dict->GetWithoutPathExpansion("Connectable", &connectable_value)) {
    {
      bool temp;
      if (!connectable_value->GetAsBoolean(&temp)) {
        out->connectable.reset();
        return false;
      }
      else
        out->connectable.reset(new bool(temp));
    }
  }

  const base::Value* connection_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ConnectionState", &connection_state_value)) {
    {
      std::string connection_state_type_as_string;
      if (!connection_state_value->GetAsString(&connection_state_type_as_string)) {
        return false;
      }
      out->connection_state = ParseConnectionStateType(connection_state_type_as_string);
      if (out->connection_state == CONNECTION_STATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->connection_state = CONNECTION_STATE_TYPE_NONE;
  }

  const base::Value* error_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ErrorState", &error_state_value)) {
    {
      std::string temp;
      if (!error_state_value->GetAsString(&temp)) {
        out->error_state.reset();
        return false;
      }
      else
        out->error_state.reset(new std::string(temp));
    }
  }

  const base::Value* ethernet_value = NULL;
  if (dict->GetWithoutPathExpansion("Ethernet", &ethernet_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ethernet_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedEthernetProperties> temp(new ManagedEthernetProperties());
        if (!ManagedEthernetProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ethernet = std::move(temp);
      }
    }
  }

  const base::Value* guid_value = NULL;
  if (!dict->GetWithoutPathExpansion("GUID", &guid_value)) {
    return false;
  }
  {
    if (!guid_value->GetAsString(&out->guid)) {
      return false;
    }
  }

  const base::Value* ip_address_config_type_value = NULL;
  if (dict->GetWithoutPathExpansion("IPAddressConfigType", &ip_address_config_type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ip_address_config_type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedIPConfigType> temp(new ManagedIPConfigType());
        if (!ManagedIPConfigType::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ip_address_config_type = std::move(temp);
      }
    }
  }

  const base::Value* ip_configs_value = NULL;
  if (dict->GetWithoutPathExpansion("IPConfigs", &ip_configs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!ip_configs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->ip_configs)) {
          return false;
        }
      }
    }
  }

  const base::Value* mac_address_value = NULL;
  if (dict->GetWithoutPathExpansion("MacAddress", &mac_address_value)) {
    {
      std::string temp;
      if (!mac_address_value->GetAsString(&temp)) {
        out->mac_address.reset();
        return false;
      }
      else
        out->mac_address.reset(new std::string(temp));
    }
  }

  const base::Value* metered_value = NULL;
  if (dict->GetWithoutPathExpansion("Metered", &metered_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!metered_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedBoolean> temp(new ManagedBoolean());
        if (!ManagedBoolean::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->metered = std::move(temp);
      }
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!name_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedDOMString> temp(new ManagedDOMString());
        if (!ManagedDOMString::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->name = std::move(temp);
      }
    }
  }

  const base::Value* name_servers_config_type_value = NULL;
  if (dict->GetWithoutPathExpansion("NameServersConfigType", &name_servers_config_type_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!name_servers_config_type_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedIPConfigType> temp(new ManagedIPConfigType());
        if (!ManagedIPConfigType::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->name_servers_config_type = std::move(temp);
      }
    }
  }

  const base::Value* priority_value = NULL;
  if (dict->GetWithoutPathExpansion("Priority", &priority_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!priority_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedLong> temp(new ManagedLong());
        if (!ManagedLong::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->priority = std::move(temp);
      }
    }
  }

  const base::Value* proxy_settings_value = NULL;
  if (dict->GetWithoutPathExpansion("ProxySettings", &proxy_settings_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!proxy_settings_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedProxySettings> temp(new ManagedProxySettings());
        if (!ManagedProxySettings::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->proxy_settings = std::move(temp);
      }
    }
  }

  const base::Value* restricted_connectivity_value = NULL;
  if (dict->GetWithoutPathExpansion("RestrictedConnectivity", &restricted_connectivity_value)) {
    {
      bool temp;
      if (!restricted_connectivity_value->GetAsBoolean(&temp)) {
        out->restricted_connectivity.reset();
        return false;
      }
      else
        out->restricted_connectivity.reset(new bool(temp));
    }
  }

  const base::Value* static_ip_config_value = NULL;
  if (dict->GetWithoutPathExpansion("StaticIPConfig", &static_ip_config_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!static_ip_config_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedIPConfigProperties> temp(new ManagedIPConfigProperties());
        if (!ManagedIPConfigProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->static_ip_config = std::move(temp);
      }
    }
  }

  const base::Value* saved_ip_config_value = NULL;
  if (dict->GetWithoutPathExpansion("SavedIPConfig", &saved_ip_config_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!saved_ip_config_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<IPConfigProperties> temp(new IPConfigProperties());
        if (!IPConfigProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->saved_ip_config = std::move(temp);
      }
    }
  }

  const base::Value* source_value = NULL;
  if (dict->GetWithoutPathExpansion("Source", &source_value)) {
    {
      std::string temp;
      if (!source_value->GetAsString(&temp)) {
        out->source.reset();
        return false;
      }
      else
        out->source.reset(new std::string(temp));
    }
  }

  const base::Value* tether_value = NULL;
  if (dict->GetWithoutPathExpansion("Tether", &tether_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tether_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<TetherProperties> temp(new TetherProperties());
        if (!TetherProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tether = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("Type", &type_value)) {
    return false;
  }
  {
    std::string network_type_as_string;
    if (!type_value->GetAsString(&network_type_as_string)) {
      return false;
    }
    out->type = ParseNetworkType(network_type_as_string);
    if (out->type == NETWORK_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("VPN", &vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedVPNProperties> temp(new ManagedVPNProperties());
        if (!ManagedVPNProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->vpn = std::move(temp);
      }
    }
  }

  const base::Value* wi_fi_value = NULL;
  if (dict->GetWithoutPathExpansion("WiFi", &wi_fi_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!wi_fi_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ManagedWiFiProperties> temp(new ManagedWiFiProperties());
        if (!ManagedWiFiProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->wi_fi = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ManagedProperties> ManagedProperties::FromValue(const base::Value& value) {
  std::unique_ptr<ManagedProperties> out(new ManagedProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ManagedProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->cellular.get()) {
    to_value_result->SetWithoutPathExpansion("Cellular", (this->cellular)->ToValue());

  }
  if (this->connectable.get()) {
    to_value_result->SetWithoutPathExpansion("Connectable", std::make_unique<base::Value>(*this->connectable));

  }
  if (this->connection_state != CONNECTION_STATE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("ConnectionState", std::make_unique<base::Value>(networking_private::ToString(this->connection_state)));

  }
  if (this->error_state.get()) {
    to_value_result->SetWithoutPathExpansion("ErrorState", std::make_unique<base::Value>(*this->error_state));

  }
  if (this->ethernet.get()) {
    to_value_result->SetWithoutPathExpansion("Ethernet", (this->ethernet)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("GUID", std::make_unique<base::Value>(this->guid));

  if (this->ip_address_config_type.get()) {
    to_value_result->SetWithoutPathExpansion("IPAddressConfigType", (this->ip_address_config_type)->ToValue());

  }
  if (this->ip_configs.get()) {
    to_value_result->SetWithoutPathExpansion("IPConfigs", json_schema_compiler::util::CreateValueFromOptionalArray(this->ip_configs));

  }
  if (this->mac_address.get()) {
    to_value_result->SetWithoutPathExpansion("MacAddress", std::make_unique<base::Value>(*this->mac_address));

  }
  if (this->metered.get()) {
    to_value_result->SetWithoutPathExpansion("Metered", (this->metered)->ToValue());

  }
  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", (this->name)->ToValue());

  }
  if (this->name_servers_config_type.get()) {
    to_value_result->SetWithoutPathExpansion("NameServersConfigType", (this->name_servers_config_type)->ToValue());

  }
  if (this->priority.get()) {
    to_value_result->SetWithoutPathExpansion("Priority", (this->priority)->ToValue());

  }
  if (this->proxy_settings.get()) {
    to_value_result->SetWithoutPathExpansion("ProxySettings", (this->proxy_settings)->ToValue());

  }
  if (this->restricted_connectivity.get()) {
    to_value_result->SetWithoutPathExpansion("RestrictedConnectivity", std::make_unique<base::Value>(*this->restricted_connectivity));

  }
  if (this->static_ip_config.get()) {
    to_value_result->SetWithoutPathExpansion("StaticIPConfig", (this->static_ip_config)->ToValue());

  }
  if (this->saved_ip_config.get()) {
    to_value_result->SetWithoutPathExpansion("SavedIPConfig", (this->saved_ip_config)->ToValue());

  }
  if (this->source.get()) {
    to_value_result->SetWithoutPathExpansion("Source", std::make_unique<base::Value>(*this->source));

  }
  if (this->tether.get()) {
    to_value_result->SetWithoutPathExpansion("Tether", (this->tether)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(networking_private::ToString(this->type)));

  if (this->vpn.get()) {
    to_value_result->SetWithoutPathExpansion("VPN", (this->vpn)->ToValue());

  }
  if (this->wi_fi.get()) {
    to_value_result->SetWithoutPathExpansion("WiFi", (this->wi_fi)->ToValue());

  }

  return to_value_result;
}


NetworkStateProperties::NetworkStateProperties()
: connection_state(CONNECTION_STATE_TYPE_NONE),
type(NETWORK_TYPE_NONE) {}

NetworkStateProperties::~NetworkStateProperties() {}
NetworkStateProperties::NetworkStateProperties(NetworkStateProperties&& rhs)
: cellular(std::move(rhs.cellular)),
connectable(std::move(rhs.connectable)),
connection_state(rhs.connection_state),
ethernet(std::move(rhs.ethernet)),
error_state(std::move(rhs.error_state)),
guid(std::move(rhs.guid)),
name(std::move(rhs.name)),
priority(std::move(rhs.priority)),
source(std::move(rhs.source)),
tether(std::move(rhs.tether)),
type(rhs.type),
vpn(std::move(rhs.vpn)),
wi_fi(std::move(rhs.wi_fi)){
}

NetworkStateProperties& NetworkStateProperties::operator=(NetworkStateProperties&& rhs)
{
cellular = std::move(rhs.cellular);
connectable = std::move(rhs.connectable);
connection_state = rhs.connection_state;
ethernet = std::move(rhs.ethernet);
error_state = std::move(rhs.error_state);
guid = std::move(rhs.guid);
name = std::move(rhs.name);
priority = std::move(rhs.priority);
source = std::move(rhs.source);
tether = std::move(rhs.tether);
type = rhs.type;
vpn = std::move(rhs.vpn);
wi_fi = std::move(rhs.wi_fi);
return *this;
}

// static
bool NetworkStateProperties::Populate(
    const base::Value& value, NetworkStateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->connection_state = CONNECTION_STATE_TYPE_NONE;
  const base::Value* cellular_value = NULL;
  if (dict->GetWithoutPathExpansion("Cellular", &cellular_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!cellular_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<CellularStateProperties> temp(new CellularStateProperties());
        if (!CellularStateProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->cellular = std::move(temp);
      }
    }
  }

  const base::Value* connectable_value = NULL;
  if (dict->GetWithoutPathExpansion("Connectable", &connectable_value)) {
    {
      bool temp;
      if (!connectable_value->GetAsBoolean(&temp)) {
        out->connectable.reset();
        return false;
      }
      else
        out->connectable.reset(new bool(temp));
    }
  }

  const base::Value* connection_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ConnectionState", &connection_state_value)) {
    {
      std::string connection_state_type_as_string;
      if (!connection_state_value->GetAsString(&connection_state_type_as_string)) {
        return false;
      }
      out->connection_state = ParseConnectionStateType(connection_state_type_as_string);
      if (out->connection_state == CONNECTION_STATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->connection_state = CONNECTION_STATE_TYPE_NONE;
  }

  const base::Value* ethernet_value = NULL;
  if (dict->GetWithoutPathExpansion("Ethernet", &ethernet_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!ethernet_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<EthernetStateProperties> temp(new EthernetStateProperties());
        if (!EthernetStateProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->ethernet = std::move(temp);
      }
    }
  }

  const base::Value* error_state_value = NULL;
  if (dict->GetWithoutPathExpansion("ErrorState", &error_state_value)) {
    {
      std::string temp;
      if (!error_state_value->GetAsString(&temp)) {
        out->error_state.reset();
        return false;
      }
      else
        out->error_state.reset(new std::string(temp));
    }
  }

  const base::Value* guid_value = NULL;
  if (!dict->GetWithoutPathExpansion("GUID", &guid_value)) {
    return false;
  }
  {
    if (!guid_value->GetAsString(&out->guid)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("Name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* priority_value = NULL;
  if (dict->GetWithoutPathExpansion("Priority", &priority_value)) {
    {
      int temp;
      if (!priority_value->GetAsInteger(&temp)) {
        out->priority.reset();
        return false;
      }
      else
        out->priority.reset(new int(temp));
    }
  }

  const base::Value* source_value = NULL;
  if (dict->GetWithoutPathExpansion("Source", &source_value)) {
    {
      std::string temp;
      if (!source_value->GetAsString(&temp)) {
        out->source.reset();
        return false;
      }
      else
        out->source.reset(new std::string(temp));
    }
  }

  const base::Value* tether_value = NULL;
  if (dict->GetWithoutPathExpansion("Tether", &tether_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tether_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<TetherProperties> temp(new TetherProperties());
        if (!TetherProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->tether = std::move(temp);
      }
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("Type", &type_value)) {
    return false;
  }
  {
    std::string network_type_as_string;
    if (!type_value->GetAsString(&network_type_as_string)) {
      return false;
    }
    out->type = ParseNetworkType(network_type_as_string);
    if (out->type == NETWORK_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* vpn_value = NULL;
  if (dict->GetWithoutPathExpansion("VPN", &vpn_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!vpn_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<VPNStateProperties> temp(new VPNStateProperties());
        if (!VPNStateProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->vpn = std::move(temp);
      }
    }
  }

  const base::Value* wi_fi_value = NULL;
  if (dict->GetWithoutPathExpansion("WiFi", &wi_fi_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!wi_fi_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<WiFiStateProperties> temp(new WiFiStateProperties());
        if (!WiFiStateProperties::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->wi_fi = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<NetworkStateProperties> NetworkStateProperties::FromValue(const base::Value& value) {
  std::unique_ptr<NetworkStateProperties> out(new NetworkStateProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NetworkStateProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->cellular.get()) {
    to_value_result->SetWithoutPathExpansion("Cellular", (this->cellular)->ToValue());

  }
  if (this->connectable.get()) {
    to_value_result->SetWithoutPathExpansion("Connectable", std::make_unique<base::Value>(*this->connectable));

  }
  if (this->connection_state != CONNECTION_STATE_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("ConnectionState", std::make_unique<base::Value>(networking_private::ToString(this->connection_state)));

  }
  if (this->ethernet.get()) {
    to_value_result->SetWithoutPathExpansion("Ethernet", (this->ethernet)->ToValue());

  }
  if (this->error_state.get()) {
    to_value_result->SetWithoutPathExpansion("ErrorState", std::make_unique<base::Value>(*this->error_state));

  }
  to_value_result->SetWithoutPathExpansion("GUID", std::make_unique<base::Value>(this->guid));

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("Name", std::make_unique<base::Value>(*this->name));

  }
  if (this->priority.get()) {
    to_value_result->SetWithoutPathExpansion("Priority", std::make_unique<base::Value>(*this->priority));

  }
  if (this->source.get()) {
    to_value_result->SetWithoutPathExpansion("Source", std::make_unique<base::Value>(*this->source));

  }
  if (this->tether.get()) {
    to_value_result->SetWithoutPathExpansion("Tether", (this->tether)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(networking_private::ToString(this->type)));

  if (this->vpn.get()) {
    to_value_result->SetWithoutPathExpansion("VPN", (this->vpn)->ToValue());

  }
  if (this->wi_fi.get()) {
    to_value_result->SetWithoutPathExpansion("WiFi", (this->wi_fi)->ToValue());

  }

  return to_value_result;
}


DeviceStateProperties::DeviceStateProperties()
: state(DEVICE_STATE_TYPE_NONE),
type(NETWORK_TYPE_NONE) {}

DeviceStateProperties::~DeviceStateProperties() {}
DeviceStateProperties::DeviceStateProperties(DeviceStateProperties&& rhs)
: scanning(std::move(rhs.scanning)),
sim_lock_status(std::move(rhs.sim_lock_status)),
sim_present(std::move(rhs.sim_present)),
state(rhs.state),
type(rhs.type),
managed_network_available(std::move(rhs.managed_network_available)){
}

DeviceStateProperties& DeviceStateProperties::operator=(DeviceStateProperties&& rhs)
{
scanning = std::move(rhs.scanning);
sim_lock_status = std::move(rhs.sim_lock_status);
sim_present = std::move(rhs.sim_present);
state = rhs.state;
type = rhs.type;
managed_network_available = std::move(rhs.managed_network_available);
return *this;
}

// static
bool DeviceStateProperties::Populate(
    const base::Value& value, DeviceStateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* scanning_value = NULL;
  if (dict->GetWithoutPathExpansion("Scanning", &scanning_value)) {
    {
      bool temp;
      if (!scanning_value->GetAsBoolean(&temp)) {
        out->scanning.reset();
        return false;
      }
      else
        out->scanning.reset(new bool(temp));
    }
  }

  const base::Value* sim_lock_status_value = NULL;
  if (dict->GetWithoutPathExpansion("SIMLockStatus", &sim_lock_status_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!sim_lock_status_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<SIMLockStatus> temp(new SIMLockStatus());
        if (!SIMLockStatus::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->sim_lock_status = std::move(temp);
      }
    }
  }

  const base::Value* sim_present_value = NULL;
  if (dict->GetWithoutPathExpansion("SIMPresent", &sim_present_value)) {
    {
      bool temp;
      if (!sim_present_value->GetAsBoolean(&temp)) {
        out->sim_present.reset();
        return false;
      }
      else
        out->sim_present.reset(new bool(temp));
    }
  }

  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("State", &state_value)) {
    return false;
  }
  {
    std::string device_state_type_as_string;
    if (!state_value->GetAsString(&device_state_type_as_string)) {
      return false;
    }
    out->state = ParseDeviceStateType(device_state_type_as_string);
    if (out->state == DEVICE_STATE_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("Type", &type_value)) {
    return false;
  }
  {
    std::string network_type_as_string;
    if (!type_value->GetAsString(&network_type_as_string)) {
      return false;
    }
    out->type = ParseNetworkType(network_type_as_string);
    if (out->type == NETWORK_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* managed_network_available_value = NULL;
  if (dict->GetWithoutPathExpansion("ManagedNetworkAvailable", &managed_network_available_value)) {
    {
      bool temp;
      if (!managed_network_available_value->GetAsBoolean(&temp)) {
        out->managed_network_available.reset();
        return false;
      }
      else
        out->managed_network_available.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DeviceStateProperties> DeviceStateProperties::FromValue(const base::Value& value) {
  std::unique_ptr<DeviceStateProperties> out(new DeviceStateProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DeviceStateProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->scanning.get()) {
    to_value_result->SetWithoutPathExpansion("Scanning", std::make_unique<base::Value>(*this->scanning));

  }
  if (this->sim_lock_status.get()) {
    to_value_result->SetWithoutPathExpansion("SIMLockStatus", (this->sim_lock_status)->ToValue());

  }
  if (this->sim_present.get()) {
    to_value_result->SetWithoutPathExpansion("SIMPresent", std::make_unique<base::Value>(*this->sim_present));

  }
  to_value_result->SetWithoutPathExpansion("State", std::make_unique<base::Value>(networking_private::ToString(this->state)));

  to_value_result->SetWithoutPathExpansion("Type", std::make_unique<base::Value>(networking_private::ToString(this->type)));

  if (this->managed_network_available.get()) {
    to_value_result->SetWithoutPathExpansion("ManagedNetworkAvailable", std::make_unique<base::Value>(*this->managed_network_available));

  }

  return to_value_result;
}


VerificationProperties::VerificationProperties()
 {}

VerificationProperties::~VerificationProperties() {}
VerificationProperties::VerificationProperties(VerificationProperties&& rhs)
: certificate(std::move(rhs.certificate)),
intermediate_certificates(std::move(rhs.intermediate_certificates)),
public_key(std::move(rhs.public_key)),
nonce(std::move(rhs.nonce)),
signed_data(std::move(rhs.signed_data)),
device_serial(std::move(rhs.device_serial)),
device_ssid(std::move(rhs.device_ssid)),
device_bssid(std::move(rhs.device_bssid)){
}

VerificationProperties& VerificationProperties::operator=(VerificationProperties&& rhs)
{
certificate = std::move(rhs.certificate);
intermediate_certificates = std::move(rhs.intermediate_certificates);
public_key = std::move(rhs.public_key);
nonce = std::move(rhs.nonce);
signed_data = std::move(rhs.signed_data);
device_serial = std::move(rhs.device_serial);
device_ssid = std::move(rhs.device_ssid);
device_bssid = std::move(rhs.device_bssid);
return *this;
}

// static
bool VerificationProperties::Populate(
    const base::Value& value, VerificationProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* certificate_value = NULL;
  if (!dict->GetWithoutPathExpansion("certificate", &certificate_value)) {
    return false;
  }
  {
    if (!certificate_value->GetAsString(&out->certificate)) {
      return false;
    }
  }

  const base::Value* intermediate_certificates_value = NULL;
  if (dict->GetWithoutPathExpansion("intermediateCertificates", &intermediate_certificates_value)) {
    {
      const base::ListValue* list = NULL;
      if (!intermediate_certificates_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->intermediate_certificates)) {
          return false;
        }
      }
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

  const base::Value* nonce_value = NULL;
  if (!dict->GetWithoutPathExpansion("nonce", &nonce_value)) {
    return false;
  }
  {
    if (!nonce_value->GetAsString(&out->nonce)) {
      return false;
    }
  }

  const base::Value* signed_data_value = NULL;
  if (!dict->GetWithoutPathExpansion("signedData", &signed_data_value)) {
    return false;
  }
  {
    if (!signed_data_value->GetAsString(&out->signed_data)) {
      return false;
    }
  }

  const base::Value* device_serial_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceSerial", &device_serial_value)) {
    return false;
  }
  {
    if (!device_serial_value->GetAsString(&out->device_serial)) {
      return false;
    }
  }

  const base::Value* device_ssid_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceSsid", &device_ssid_value)) {
    return false;
  }
  {
    if (!device_ssid_value->GetAsString(&out->device_ssid)) {
      return false;
    }
  }

  const base::Value* device_bssid_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceBssid", &device_bssid_value)) {
    return false;
  }
  {
    if (!device_bssid_value->GetAsString(&out->device_bssid)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<VerificationProperties> VerificationProperties::FromValue(const base::Value& value) {
  std::unique_ptr<VerificationProperties> out(new VerificationProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> VerificationProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("certificate", std::make_unique<base::Value>(this->certificate));

  if (this->intermediate_certificates.get()) {
    to_value_result->SetWithoutPathExpansion("intermediateCertificates", json_schema_compiler::util::CreateValueFromOptionalArray(this->intermediate_certificates));

  }
  to_value_result->SetWithoutPathExpansion("publicKey", std::make_unique<base::Value>(this->public_key));

  to_value_result->SetWithoutPathExpansion("nonce", std::make_unique<base::Value>(this->nonce));

  to_value_result->SetWithoutPathExpansion("signedData", std::make_unique<base::Value>(this->signed_data));

  to_value_result->SetWithoutPathExpansion("deviceSerial", std::make_unique<base::Value>(this->device_serial));

  to_value_result->SetWithoutPathExpansion("deviceSsid", std::make_unique<base::Value>(this->device_ssid));

  to_value_result->SetWithoutPathExpansion("deviceBssid", std::make_unique<base::Value>(this->device_bssid));


  return to_value_result;
}


NetworkFilter::NetworkFilter()
: network_type(NETWORK_TYPE_NONE) {}

NetworkFilter::~NetworkFilter() {}
NetworkFilter::NetworkFilter(NetworkFilter&& rhs)
: network_type(rhs.network_type),
visible(std::move(rhs.visible)),
configured(std::move(rhs.configured)),
limit(std::move(rhs.limit)){
}

NetworkFilter& NetworkFilter::operator=(NetworkFilter&& rhs)
{
network_type = rhs.network_type;
visible = std::move(rhs.visible);
configured = std::move(rhs.configured);
limit = std::move(rhs.limit);
return *this;
}

// static
bool NetworkFilter::Populate(
    const base::Value& value, NetworkFilter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* network_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("networkType", &network_type_value)) {
    return false;
  }
  {
    std::string network_type_as_string;
    if (!network_type_value->GetAsString(&network_type_as_string)) {
      return false;
    }
    out->network_type = ParseNetworkType(network_type_as_string);
    if (out->network_type == NETWORK_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* visible_value = NULL;
  if (dict->GetWithoutPathExpansion("visible", &visible_value)) {
    {
      bool temp;
      if (!visible_value->GetAsBoolean(&temp)) {
        out->visible.reset();
        return false;
      }
      else
        out->visible.reset(new bool(temp));
    }
  }

  const base::Value* configured_value = NULL;
  if (dict->GetWithoutPathExpansion("configured", &configured_value)) {
    {
      bool temp;
      if (!configured_value->GetAsBoolean(&temp)) {
        out->configured.reset();
        return false;
      }
      else
        out->configured.reset(new bool(temp));
    }
  }

  const base::Value* limit_value = NULL;
  if (dict->GetWithoutPathExpansion("limit", &limit_value)) {
    {
      int temp;
      if (!limit_value->GetAsInteger(&temp)) {
        out->limit.reset();
        return false;
      }
      else
        out->limit.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<NetworkFilter> NetworkFilter::FromValue(const base::Value& value) {
  std::unique_ptr<NetworkFilter> out(new NetworkFilter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NetworkFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("networkType", std::make_unique<base::Value>(networking_private::ToString(this->network_type)));

  if (this->visible.get()) {
    to_value_result->SetWithoutPathExpansion("visible", std::make_unique<base::Value>(*this->visible));

  }
  if (this->configured.get()) {
    to_value_result->SetWithoutPathExpansion("configured", std::make_unique<base::Value>(*this->configured));

  }
  if (this->limit.get()) {
    to_value_result->SetWithoutPathExpansion("limit", std::make_unique<base::Value>(*this->limit));

  }

  return to_value_result;
}


GlobalPolicy::GlobalPolicy()
 {}

GlobalPolicy::~GlobalPolicy() {}
GlobalPolicy::GlobalPolicy(GlobalPolicy&& rhs)
: allow_only_policy_networks_to_autoconnect(std::move(rhs.allow_only_policy_networks_to_autoconnect)),
allow_only_policy_networks_to_connect(std::move(rhs.allow_only_policy_networks_to_connect)),
allow_only_policy_networks_to_connect_if_available(std::move(rhs.allow_only_policy_networks_to_connect_if_available)),
blacklisted_hex_ssi_ds(std::move(rhs.blacklisted_hex_ssi_ds)){
}

GlobalPolicy& GlobalPolicy::operator=(GlobalPolicy&& rhs)
{
allow_only_policy_networks_to_autoconnect = std::move(rhs.allow_only_policy_networks_to_autoconnect);
allow_only_policy_networks_to_connect = std::move(rhs.allow_only_policy_networks_to_connect);
allow_only_policy_networks_to_connect_if_available = std::move(rhs.allow_only_policy_networks_to_connect_if_available);
blacklisted_hex_ssi_ds = std::move(rhs.blacklisted_hex_ssi_ds);
return *this;
}

// static
bool GlobalPolicy::Populate(
    const base::Value& value, GlobalPolicy* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* allow_only_policy_networks_to_autoconnect_value = NULL;
  if (dict->GetWithoutPathExpansion("AllowOnlyPolicyNetworksToAutoconnect", &allow_only_policy_networks_to_autoconnect_value)) {
    {
      bool temp;
      if (!allow_only_policy_networks_to_autoconnect_value->GetAsBoolean(&temp)) {
        out->allow_only_policy_networks_to_autoconnect.reset();
        return false;
      }
      else
        out->allow_only_policy_networks_to_autoconnect.reset(new bool(temp));
    }
  }

  const base::Value* allow_only_policy_networks_to_connect_value = NULL;
  if (dict->GetWithoutPathExpansion("AllowOnlyPolicyNetworksToConnect", &allow_only_policy_networks_to_connect_value)) {
    {
      bool temp;
      if (!allow_only_policy_networks_to_connect_value->GetAsBoolean(&temp)) {
        out->allow_only_policy_networks_to_connect.reset();
        return false;
      }
      else
        out->allow_only_policy_networks_to_connect.reset(new bool(temp));
    }
  }

  const base::Value* allow_only_policy_networks_to_connect_if_available_value = NULL;
  if (dict->GetWithoutPathExpansion("AllowOnlyPolicyNetworksToConnectIfAvailable", &allow_only_policy_networks_to_connect_if_available_value)) {
    {
      bool temp;
      if (!allow_only_policy_networks_to_connect_if_available_value->GetAsBoolean(&temp)) {
        out->allow_only_policy_networks_to_connect_if_available.reset();
        return false;
      }
      else
        out->allow_only_policy_networks_to_connect_if_available.reset(new bool(temp));
    }
  }

  const base::Value* blacklisted_hex_ssi_ds_value = NULL;
  if (dict->GetWithoutPathExpansion("BlacklistedHexSSIDs", &blacklisted_hex_ssi_ds_value)) {
    {
      const base::ListValue* list = NULL;
      if (!blacklisted_hex_ssi_ds_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->blacklisted_hex_ssi_ds)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<GlobalPolicy> GlobalPolicy::FromValue(const base::Value& value) {
  std::unique_ptr<GlobalPolicy> out(new GlobalPolicy());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GlobalPolicy::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->allow_only_policy_networks_to_autoconnect.get()) {
    to_value_result->SetWithoutPathExpansion("AllowOnlyPolicyNetworksToAutoconnect", std::make_unique<base::Value>(*this->allow_only_policy_networks_to_autoconnect));

  }
  if (this->allow_only_policy_networks_to_connect.get()) {
    to_value_result->SetWithoutPathExpansion("AllowOnlyPolicyNetworksToConnect", std::make_unique<base::Value>(*this->allow_only_policy_networks_to_connect));

  }
  if (this->allow_only_policy_networks_to_connect_if_available.get()) {
    to_value_result->SetWithoutPathExpansion("AllowOnlyPolicyNetworksToConnectIfAvailable", std::make_unique<base::Value>(*this->allow_only_policy_networks_to_connect_if_available));

  }
  if (this->blacklisted_hex_ssi_ds.get()) {
    to_value_result->SetWithoutPathExpansion("BlacklistedHexSSIDs", json_schema_compiler::util::CreateValueFromOptionalArray(this->blacklisted_hex_ssi_ds));

  }

  return to_value_result;
}


Certificate::Certificate()
: hardware_backed(false),
device_wide(false) {}

Certificate::~Certificate() {}
Certificate::Certificate(Certificate&& rhs)
: hash(std::move(rhs.hash)),
issued_by(std::move(rhs.issued_by)),
issued_to(std::move(rhs.issued_to)),
pem(std::move(rhs.pem)),
pkcs11_id(std::move(rhs.pkcs11_id)),
hardware_backed(rhs.hardware_backed),
device_wide(rhs.device_wide){
}

Certificate& Certificate::operator=(Certificate&& rhs)
{
hash = std::move(rhs.hash);
issued_by = std::move(rhs.issued_by);
issued_to = std::move(rhs.issued_to);
pem = std::move(rhs.pem);
pkcs11_id = std::move(rhs.pkcs11_id);
hardware_backed = rhs.hardware_backed;
device_wide = rhs.device_wide;
return *this;
}

// static
bool Certificate::Populate(
    const base::Value& value, Certificate* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* hash_value = NULL;
  if (!dict->GetWithoutPathExpansion("hash", &hash_value)) {
    return false;
  }
  {
    if (!hash_value->GetAsString(&out->hash)) {
      return false;
    }
  }

  const base::Value* issued_by_value = NULL;
  if (!dict->GetWithoutPathExpansion("issuedBy", &issued_by_value)) {
    return false;
  }
  {
    if (!issued_by_value->GetAsString(&out->issued_by)) {
      return false;
    }
  }

  const base::Value* issued_to_value = NULL;
  if (!dict->GetWithoutPathExpansion("issuedTo", &issued_to_value)) {
    return false;
  }
  {
    if (!issued_to_value->GetAsString(&out->issued_to)) {
      return false;
    }
  }

  const base::Value* pem_value = NULL;
  if (dict->GetWithoutPathExpansion("pem", &pem_value)) {
    {
      std::string temp;
      if (!pem_value->GetAsString(&temp)) {
        out->pem.reset();
        return false;
      }
      else
        out->pem.reset(new std::string(temp));
    }
  }

  const base::Value* pkcs11_id_value = NULL;
  if (dict->GetWithoutPathExpansion("PKCS11Id", &pkcs11_id_value)) {
    {
      std::string temp;
      if (!pkcs11_id_value->GetAsString(&temp)) {
        out->pkcs11_id.reset();
        return false;
      }
      else
        out->pkcs11_id.reset(new std::string(temp));
    }
  }

  const base::Value* hardware_backed_value = NULL;
  if (!dict->GetWithoutPathExpansion("hardwareBacked", &hardware_backed_value)) {
    return false;
  }
  {
    if (!hardware_backed_value->GetAsBoolean(&out->hardware_backed)) {
      return false;
    }
  }

  const base::Value* device_wide_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceWide", &device_wide_value)) {
    return false;
  }
  {
    if (!device_wide_value->GetAsBoolean(&out->device_wide)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Certificate> Certificate::FromValue(const base::Value& value) {
  std::unique_ptr<Certificate> out(new Certificate());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Certificate::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("hash", std::make_unique<base::Value>(this->hash));

  to_value_result->SetWithoutPathExpansion("issuedBy", std::make_unique<base::Value>(this->issued_by));

  to_value_result->SetWithoutPathExpansion("issuedTo", std::make_unique<base::Value>(this->issued_to));

  if (this->pem.get()) {
    to_value_result->SetWithoutPathExpansion("pem", std::make_unique<base::Value>(*this->pem));

  }
  if (this->pkcs11_id.get()) {
    to_value_result->SetWithoutPathExpansion("PKCS11Id", std::make_unique<base::Value>(*this->pkcs11_id));

  }
  to_value_result->SetWithoutPathExpansion("hardwareBacked", std::make_unique<base::Value>(this->hardware_backed));

  to_value_result->SetWithoutPathExpansion("deviceWide", std::make_unique<base::Value>(this->device_wide));


  return to_value_result;
}


CertificateLists::CertificateLists()
 {}

CertificateLists::~CertificateLists() {}
CertificateLists::CertificateLists(CertificateLists&& rhs)
: server_ca_certificates(std::move(rhs.server_ca_certificates)),
user_certificates(std::move(rhs.user_certificates)){
}

CertificateLists& CertificateLists::operator=(CertificateLists&& rhs)
{
server_ca_certificates = std::move(rhs.server_ca_certificates);
user_certificates = std::move(rhs.user_certificates);
return *this;
}

// static
bool CertificateLists::Populate(
    const base::Value& value, CertificateLists* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* server_ca_certificates_value = NULL;
  if (!dict->GetWithoutPathExpansion("serverCaCertificates", &server_ca_certificates_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!server_ca_certificates_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->server_ca_certificates)) {
        return false;
      }
    }
  }

  const base::Value* user_certificates_value = NULL;
  if (!dict->GetWithoutPathExpansion("userCertificates", &user_certificates_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!user_certificates_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->user_certificates)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<CertificateLists> CertificateLists::FromValue(const base::Value& value) {
  std::unique_ptr<CertificateLists> out(new CertificateLists());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CertificateLists::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("serverCaCertificates", json_schema_compiler::util::CreateValueFromArray(this->server_ca_certificates));

  to_value_result->SetWithoutPathExpansion("userCertificates", json_schema_compiler::util::CreateValueFromArray(this->user_certificates));


  return to_value_result;
}



//
// Functions
//

namespace GetProperties {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const NetworkProperties& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetProperties

namespace GetManagedProperties {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ManagedProperties& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetManagedProperties

namespace GetState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const NetworkStateProperties& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetState

namespace SetProperties {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
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
      if (!NetworkConfigProperties::Populate(*dictionary, &params->properties)) {
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

namespace CreateNetwork {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* shared_value = NULL;
  if (args.Get(0, &shared_value) &&
      !shared_value->is_none()) {
    {
      if (!shared_value->GetAsBoolean(&params->shared)) {
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
      if (!NetworkConfigProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace CreateNetwork

namespace ForgetNetwork {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
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
}  // namespace ForgetNetwork

namespace GetNetworks {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
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
      if (!NetworkFilter::Populate(*dictionary, &params->filter)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<NetworkStateProperties>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetNetworks

namespace GetVisibleNetworks {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_type_value = NULL;
  if (args.Get(0, &network_type_value) &&
      !network_type_value->is_none()) {
    {
      std::string network_type_as_string;
      if (!network_type_value->GetAsString(&network_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->network_type = ParseNetworkType(network_type_as_string);
      if (params->network_type == NETWORK_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<NetworkStateProperties>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetVisibleNetworks

namespace GetEnabledNetworkTypes {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<NetworkType>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  {
    std::vector<std::string> result_list;
    for (const auto& it : (result)) {
    result_list.push_back(networking_private::ToString(it));
  }
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result_list));
  }

  return create_results;
}
}  // namespace GetEnabledNetworkTypes

namespace GetDeviceStates {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<DeviceStateProperties>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace GetDeviceStates

namespace EnableNetworkType {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_type_value = NULL;
  if (args.Get(0, &network_type_value) &&
      !network_type_value->is_none()) {
    {
      std::string network_type_as_string;
      if (!network_type_value->GetAsString(&network_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->network_type = ParseNetworkType(network_type_as_string);
      if (params->network_type == NETWORK_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace EnableNetworkType

namespace DisableNetworkType {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_type_value = NULL;
  if (args.Get(0, &network_type_value) &&
      !network_type_value->is_none()) {
    {
      std::string network_type_as_string;
      if (!network_type_value->GetAsString(&network_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->network_type = ParseNetworkType(network_type_as_string);
      if (params->network_type == NETWORK_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace DisableNetworkType

namespace RequestNetworkScan {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());
  params->network_type = NETWORK_TYPE_NONE;

  const base::Value* network_type_value = NULL;
  if (args.Get(0, &network_type_value) &&
      !network_type_value->is_none()) {
    {
      std::string network_type_as_string;
      if (!network_type_value->GetAsString(&network_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->network_type = ParseNetworkType(network_type_as_string);
      if (params->network_type == NETWORK_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }

  return params;
}


}  // namespace RequestNetworkScan

namespace StartConnect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
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
}  // namespace StartConnect

namespace StartDisconnect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
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
}  // namespace StartDisconnect

namespace StartActivate {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* carrier_value = NULL;
  if (args.Get(1, &carrier_value) &&
      !carrier_value->is_none()) {
    {
      std::string temp;
      if (!carrier_value->GetAsString(&temp)) {
        params->carrier.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->carrier.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace StartActivate

namespace VerifyDestination {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* properties_value = NULL;
  if (args.Get(0, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!VerificationProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace VerifyDestination

namespace VerifyAndEncryptData {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* properties_value = NULL;
  if (args.Get(0, &properties_value) &&
      !properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!VerificationProperties::Populate(*dictionary, &params->properties)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* data_value = NULL;
  if (args.Get(1, &data_value) &&
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


std::unique_ptr<base::ListValue> Results::Create(const std::string& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace VerifyAndEncryptData

namespace SetWifiTDLSEnabledState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* ip_or_mac_address_value = NULL;
  if (args.Get(0, &ip_or_mac_address_value) &&
      !ip_or_mac_address_value->is_none()) {
    {
      if (!ip_or_mac_address_value->GetAsString(&params->ip_or_mac_address)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* enabled_value = NULL;
  if (args.Get(1, &enabled_value) &&
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


std::unique_ptr<base::ListValue> Results::Create(const std::string& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace SetWifiTDLSEnabledState

namespace GetWifiTDLSStatus {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* ip_or_mac_address_value = NULL;
  if (args.Get(0, &ip_or_mac_address_value) &&
      !ip_or_mac_address_value->is_none()) {
    {
      if (!ip_or_mac_address_value->GetAsString(&params->ip_or_mac_address)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace GetWifiTDLSStatus

namespace GetCaptivePortalStatus {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const CaptivePortalStatus& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(networking_private::ToString(result)));

  return create_results;
}
}  // namespace GetCaptivePortalStatus

namespace UnlockCellularSim {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* pin_value = NULL;
  if (args.Get(1, &pin_value) &&
      !pin_value->is_none()) {
    {
      if (!pin_value->GetAsString(&params->pin)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* puk_value = NULL;
  if (args.Get(2, &puk_value) &&
      !puk_value->is_none()) {
    {
      std::string temp;
      if (!puk_value->GetAsString(&temp)) {
        params->puk.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->puk.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace UnlockCellularSim

namespace SetCellularSimState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* sim_state_value = NULL;
  if (args.Get(1, &sim_state_value) &&
      !sim_state_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!sim_state_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CellularSimState::Populate(*dictionary, &params->sim_state)) {
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
}  // namespace SetCellularSimState

namespace SelectCellularMobileNetwork {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* network_guid_value = NULL;
  if (args.Get(0, &network_guid_value) &&
      !network_guid_value->is_none()) {
    {
      if (!network_guid_value->GetAsString(&params->network_guid)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* network_id_value = NULL;
  if (args.Get(1, &network_id_value) &&
      !network_id_value->is_none()) {
    {
      if (!network_id_value->GetAsString(&params->network_id)) {
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
}  // namespace SelectCellularMobileNetwork

namespace GetGlobalPolicy {

std::unique_ptr<base::ListValue> Results::Create(const GlobalPolicy& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetGlobalPolicy

namespace GetCertificateLists {

std::unique_ptr<base::ListValue> Results::Create(const CertificateLists& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetCertificateLists

//
// Events
//

namespace OnNetworksChanged {

const char kEventName[] = "networkingPrivate.onNetworksChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& changes) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(changes));

  return create_results;
}

}  // namespace OnNetworksChanged

namespace OnNetworkListChanged {

const char kEventName[] = "networkingPrivate.onNetworkListChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& changes) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(changes));

  return create_results;
}

}  // namespace OnNetworkListChanged

namespace OnDeviceStateListChanged {

const char kEventName[] = "networkingPrivate.onDeviceStateListChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnDeviceStateListChanged

namespace OnPortalDetectionCompleted {

const char kEventName[] = "networkingPrivate.onPortalDetectionCompleted";

std::unique_ptr<base::ListValue> Create(const std::string& network_guid, const CaptivePortalStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(network_guid));

  create_results->Append(std::make_unique<base::Value>(networking_private::ToString(status)));

  return create_results;
}

}  // namespace OnPortalDetectionCompleted

namespace OnCertificateListsChanged {

const char kEventName[] = "networkingPrivate.onCertificateListsChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnCertificateListsChanged

}  // namespace networking_private
}  // namespace api
}  // namespace extensions

