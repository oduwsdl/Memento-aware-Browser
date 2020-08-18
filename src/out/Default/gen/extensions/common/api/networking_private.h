// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/networking_private.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_NETWORKING_PRIVATE_H__
#define EXTENSIONS_COMMON_API_NETWORKING_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace networking_private {

//
// Types
//

enum ActivationStateType {
  ACTIVATION_STATE_TYPE_NONE,
  ACTIVATION_STATE_TYPE_ACTIVATED,
  ACTIVATION_STATE_TYPE_ACTIVATING,
  ACTIVATION_STATE_TYPE_NOTACTIVATED,
  ACTIVATION_STATE_TYPE_PARTIALLYACTIVATED,
  ACTIVATION_STATE_TYPE_LAST = ACTIVATION_STATE_TYPE_PARTIALLYACTIVATED,
};


const char* ToString(ActivationStateType as_enum);
ActivationStateType ParseActivationStateType(const std::string& as_string);

enum CaptivePortalStatus {
  CAPTIVE_PORTAL_STATUS_NONE,
  CAPTIVE_PORTAL_STATUS_UNKNOWN,
  CAPTIVE_PORTAL_STATUS_OFFLINE,
  CAPTIVE_PORTAL_STATUS_ONLINE,
  CAPTIVE_PORTAL_STATUS_PORTAL,
  CAPTIVE_PORTAL_STATUS_PROXYAUTHREQUIRED,
  CAPTIVE_PORTAL_STATUS_LAST = CAPTIVE_PORTAL_STATUS_PROXYAUTHREQUIRED,
};


const char* ToString(CaptivePortalStatus as_enum);
CaptivePortalStatus ParseCaptivePortalStatus(const std::string& as_string);

enum ConnectionStateType {
  CONNECTION_STATE_TYPE_NONE,
  CONNECTION_STATE_TYPE_CONNECTED,
  CONNECTION_STATE_TYPE_CONNECTING,
  CONNECTION_STATE_TYPE_NOTCONNECTED,
  CONNECTION_STATE_TYPE_LAST = CONNECTION_STATE_TYPE_NOTCONNECTED,
};


const char* ToString(ConnectionStateType as_enum);
ConnectionStateType ParseConnectionStateType(const std::string& as_string);

enum DeviceStateType {
  DEVICE_STATE_TYPE_NONE,
  DEVICE_STATE_TYPE_UNINITIALIZED,
  DEVICE_STATE_TYPE_DISABLED,
  DEVICE_STATE_TYPE_ENABLING,
  DEVICE_STATE_TYPE_ENABLED,
  DEVICE_STATE_TYPE_PROHIBITED,
  DEVICE_STATE_TYPE_LAST = DEVICE_STATE_TYPE_PROHIBITED,
};


const char* ToString(DeviceStateType as_enum);
DeviceStateType ParseDeviceStateType(const std::string& as_string);

enum IPConfigType {
  IP_CONFIG_TYPE_NONE,
  IP_CONFIG_TYPE_DHCP,
  IP_CONFIG_TYPE_STATIC,
  IP_CONFIG_TYPE_LAST = IP_CONFIG_TYPE_STATIC,
};


const char* ToString(IPConfigType as_enum);
IPConfigType ParseIPConfigType(const std::string& as_string);

enum NetworkType {
  NETWORK_TYPE_NONE,
  NETWORK_TYPE_ALL,
  NETWORK_TYPE_CELLULAR,
  NETWORK_TYPE_ETHERNET,
  NETWORK_TYPE_TETHER,
  NETWORK_TYPE_VPN,
  NETWORK_TYPE_WIRELESS,
  NETWORK_TYPE_WIFI,
  NETWORK_TYPE_LAST = NETWORK_TYPE_WIFI,
};


const char* ToString(NetworkType as_enum);
NetworkType ParseNetworkType(const std::string& as_string);

enum ProxySettingsType {
  PROXY_SETTINGS_TYPE_NONE,
  PROXY_SETTINGS_TYPE_DIRECT,
  PROXY_SETTINGS_TYPE_MANUAL,
  PROXY_SETTINGS_TYPE_PAC,
  PROXY_SETTINGS_TYPE_WPAD,
  PROXY_SETTINGS_TYPE_LAST = PROXY_SETTINGS_TYPE_WPAD,
};


const char* ToString(ProxySettingsType as_enum);
ProxySettingsType ParseProxySettingsType(const std::string& as_string);

struct ManagedBoolean {
  ManagedBoolean();
  ~ManagedBoolean();
  ManagedBoolean(ManagedBoolean&& rhs);
  ManagedBoolean& operator=(ManagedBoolean&& rhs);

  // Populates a ManagedBoolean object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ManagedBoolean* out);

  // Creates a ManagedBoolean object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManagedBoolean> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedBoolean object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> active;

  std::unique_ptr<std::string> effective;

  std::unique_ptr<bool> user_policy;

  std::unique_ptr<bool> device_policy;

  std::unique_ptr<bool> user_setting;

  std::unique_ptr<bool> shared_setting;

  std::unique_ptr<bool> user_editable;

  std::unique_ptr<bool> device_editable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedBoolean);
};

struct ManagedLong {
  ManagedLong();
  ~ManagedLong();
  ManagedLong(ManagedLong&& rhs);
  ManagedLong& operator=(ManagedLong&& rhs);

  // Populates a ManagedLong object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ManagedLong* out);

  // Creates a ManagedLong object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManagedLong> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedLong object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<int> active;

  std::unique_ptr<std::string> effective;

  std::unique_ptr<int> user_policy;

  std::unique_ptr<int> device_policy;

  std::unique_ptr<int> user_setting;

  std::unique_ptr<int> shared_setting;

  std::unique_ptr<bool> user_editable;

  std::unique_ptr<bool> device_editable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedLong);
};

struct ManagedDOMString {
  ManagedDOMString();
  ~ManagedDOMString();
  ManagedDOMString(ManagedDOMString&& rhs);
  ManagedDOMString& operator=(ManagedDOMString&& rhs);

  // Populates a ManagedDOMString object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedDOMString* out);

  // Creates a ManagedDOMString object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManagedDOMString> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedDOMString object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> active;

  std::unique_ptr<std::string> effective;

  std::unique_ptr<std::string> user_policy;

  std::unique_ptr<std::string> device_policy;

  std::unique_ptr<std::string> user_setting;

  std::unique_ptr<std::string> shared_setting;

  std::unique_ptr<bool> user_editable;

  std::unique_ptr<bool> device_editable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedDOMString);
};

struct ManagedDOMStringList {
  ManagedDOMStringList();
  ~ManagedDOMStringList();
  ManagedDOMStringList(ManagedDOMStringList&& rhs);
  ManagedDOMStringList& operator=(ManagedDOMStringList&& rhs);

  // Populates a ManagedDOMStringList object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedDOMStringList* out);

  // Creates a ManagedDOMStringList object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedDOMStringList> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedDOMStringList object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::vector<std::string>> active;

  std::unique_ptr<std::string> effective;

  std::unique_ptr<std::vector<std::string>> user_policy;

  std::unique_ptr<std::vector<std::string>> device_policy;

  std::unique_ptr<std::vector<std::string>> user_setting;

  std::unique_ptr<std::vector<std::string>> shared_setting;

  std::unique_ptr<bool> user_editable;

  std::unique_ptr<bool> device_editable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedDOMStringList);
};

struct ManagedIPConfigType {
  ManagedIPConfigType();
  ~ManagedIPConfigType();
  ManagedIPConfigType(ManagedIPConfigType&& rhs);
  ManagedIPConfigType& operator=(ManagedIPConfigType&& rhs);

  // Populates a ManagedIPConfigType object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedIPConfigType* out);

  // Creates a ManagedIPConfigType object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedIPConfigType> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedIPConfigType object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  IPConfigType active;

  std::unique_ptr<std::string> effective;

  IPConfigType user_policy;

  IPConfigType device_policy;

  IPConfigType user_setting;

  IPConfigType shared_setting;

  std::unique_ptr<bool> user_editable;

  std::unique_ptr<bool> device_editable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedIPConfigType);
};

struct ManagedProxySettingsType {
  ManagedProxySettingsType();
  ~ManagedProxySettingsType();
  ManagedProxySettingsType(ManagedProxySettingsType&& rhs);
  ManagedProxySettingsType& operator=(ManagedProxySettingsType&& rhs);

  // Populates a ManagedProxySettingsType object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedProxySettingsType* out);

  // Creates a ManagedProxySettingsType object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedProxySettingsType> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedProxySettingsType object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ProxySettingsType active;

  std::unique_ptr<std::string> effective;

  ProxySettingsType user_policy;

  ProxySettingsType device_policy;

  ProxySettingsType user_setting;

  ProxySettingsType shared_setting;

  std::unique_ptr<bool> user_editable;

  std::unique_ptr<bool> device_editable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedProxySettingsType);
};

struct APNProperties {
  APNProperties();
  ~APNProperties();
  APNProperties(APNProperties&& rhs);
  APNProperties& operator=(APNProperties&& rhs);

  // Populates a APNProperties object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, APNProperties* out);

  // Creates a APNProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<APNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this APNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string access_point_name;

  std::unique_ptr<std::string> authentication;

  std::unique_ptr<std::string> language;

  std::unique_ptr<std::string> localized_name;

  std::unique_ptr<std::string> name;

  std::unique_ptr<std::string> password;

  std::unique_ptr<std::string> username;


 private:
  DISALLOW_COPY_AND_ASSIGN(APNProperties);
};

struct ManagedAPNProperties {
  ManagedAPNProperties();
  ~ManagedAPNProperties();
  ManagedAPNProperties(ManagedAPNProperties&& rhs);
  ManagedAPNProperties& operator=(ManagedAPNProperties&& rhs);

  // Populates a ManagedAPNProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedAPNProperties* out);

  // Creates a ManagedAPNProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedAPNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedAPNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ManagedDOMString access_point_name;

  std::unique_ptr<ManagedDOMString> authentication;

  std::unique_ptr<ManagedDOMString> language;

  std::unique_ptr<ManagedDOMString> localized_name;

  std::unique_ptr<ManagedDOMString> name;

  std::unique_ptr<ManagedDOMString> password;

  std::unique_ptr<ManagedDOMString> username;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedAPNProperties);
};

struct ManagedAPNList {
  ManagedAPNList();
  ~ManagedAPNList();
  ManagedAPNList(ManagedAPNList&& rhs);
  ManagedAPNList& operator=(ManagedAPNList&& rhs);

  // Populates a ManagedAPNList object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ManagedAPNList* out);

  // Creates a ManagedAPNList object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManagedAPNList> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedAPNList object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::vector<APNProperties>> active;

  std::unique_ptr<std::string> effective;

  std::unique_ptr<std::vector<APNProperties>> user_policy;

  std::unique_ptr<std::vector<APNProperties>> device_policy;

  std::unique_ptr<std::vector<APNProperties>> user_setting;

  std::unique_ptr<std::vector<APNProperties>> shared_setting;

  std::unique_ptr<bool> user_editable;

  std::unique_ptr<bool> device_editable;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedAPNList);
};

struct CellularProviderProperties {
  CellularProviderProperties();
  ~CellularProviderProperties();
  CellularProviderProperties(CellularProviderProperties&& rhs);
  CellularProviderProperties& operator=(CellularProviderProperties&& rhs);

  // Populates a CellularProviderProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, CellularProviderProperties* out);

  // Creates a CellularProviderProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<CellularProviderProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CellularProviderProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string name;

  std::string code;

  std::unique_ptr<std::string> country;


 private:
  DISALLOW_COPY_AND_ASSIGN(CellularProviderProperties);
};

struct CellularSimState {
  CellularSimState();
  ~CellularSimState();
  CellularSimState(CellularSimState&& rhs);
  CellularSimState& operator=(CellularSimState&& rhs);

  // Populates a CellularSimState object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, CellularSimState* out);

  // Creates a CellularSimState object from a base::Value, or NULL on failure.
  static std::unique_ptr<CellularSimState> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CellularSimState object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether or not a PIN should be required.
  bool require_pin;

  // The current PIN (required for any change, even when the SIM is unlocked).
  std::string current_pin;

  // If provided, change the PIN to |newPin|. |requirePin| must be true.
  std::unique_ptr<std::string> new_pin;


 private:
  DISALLOW_COPY_AND_ASSIGN(CellularSimState);
};

struct IssuerSubjectPattern {
  IssuerSubjectPattern();
  ~IssuerSubjectPattern();
  IssuerSubjectPattern(IssuerSubjectPattern&& rhs);
  IssuerSubjectPattern& operator=(IssuerSubjectPattern&& rhs);

  // Populates a IssuerSubjectPattern object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, IssuerSubjectPattern* out);

  // Creates a IssuerSubjectPattern object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<IssuerSubjectPattern> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this IssuerSubjectPattern object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> common_name;

  std::unique_ptr<std::string> locality;

  std::unique_ptr<std::string> organization;

  std::unique_ptr<std::string> organizational_unit;


 private:
  DISALLOW_COPY_AND_ASSIGN(IssuerSubjectPattern);
};

struct ManagedIssuerSubjectPattern {
  ManagedIssuerSubjectPattern();
  ~ManagedIssuerSubjectPattern();
  ManagedIssuerSubjectPattern(ManagedIssuerSubjectPattern&& rhs);
  ManagedIssuerSubjectPattern& operator=(ManagedIssuerSubjectPattern&& rhs);

  // Populates a ManagedIssuerSubjectPattern object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedIssuerSubjectPattern* out);

  // Creates a ManagedIssuerSubjectPattern object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedIssuerSubjectPattern> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedIssuerSubjectPattern object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedDOMString> common_name;

  std::unique_ptr<ManagedDOMString> locality;

  std::unique_ptr<ManagedDOMString> organization;

  std::unique_ptr<ManagedDOMString> organizational_unit;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedIssuerSubjectPattern);
};

struct CertificatePattern {
  CertificatePattern();
  ~CertificatePattern();
  CertificatePattern(CertificatePattern&& rhs);
  CertificatePattern& operator=(CertificatePattern&& rhs);

  // Populates a CertificatePattern object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, CertificatePattern* out);

  // Creates a CertificatePattern object from a base::Value, or NULL on failure.
  static std::unique_ptr<CertificatePattern> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CertificatePattern object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::vector<std::string>> enrollment_uri;

  std::unique_ptr<IssuerSubjectPattern> issuer;

  std::unique_ptr<std::vector<std::string>> issuer_cape_ms;

  std::unique_ptr<std::vector<std::string>> issuer_ca_ref;

  std::unique_ptr<IssuerSubjectPattern> subject;


 private:
  DISALLOW_COPY_AND_ASSIGN(CertificatePattern);
};

struct ManagedCertificatePattern {
  ManagedCertificatePattern();
  ~ManagedCertificatePattern();
  ManagedCertificatePattern(ManagedCertificatePattern&& rhs);
  ManagedCertificatePattern& operator=(ManagedCertificatePattern&& rhs);

  // Populates a ManagedCertificatePattern object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedCertificatePattern* out);

  // Creates a ManagedCertificatePattern object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedCertificatePattern> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedCertificatePattern object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedDOMStringList> enrollment_uri;

  std::unique_ptr<ManagedIssuerSubjectPattern> issuer;

  std::unique_ptr<ManagedDOMStringList> issuer_ca_ref;

  std::unique_ptr<ManagedIssuerSubjectPattern> subject;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedCertificatePattern);
};

struct EAPProperties {
  EAPProperties();
  ~EAPProperties();
  EAPProperties(EAPProperties&& rhs);
  EAPProperties& operator=(EAPProperties&& rhs);

  // Populates a EAPProperties object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, EAPProperties* out);

  // Creates a EAPProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<EAPProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EAPProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> anonymous_identity;

  std::unique_ptr<CertificatePattern> client_cert_pattern;

  std::unique_ptr<std::string> client_cert_pkcs11_id;

  std::unique_ptr<std::string> client_cert_ref;

  std::unique_ptr<std::string> client_cert_type;

  std::unique_ptr<std::string> identity;

  std::unique_ptr<std::string> inner;

  // The outer EAP type. Required by ONC, but may not be provided when translating
  // from Shill.
  std::unique_ptr<std::string> outer;

  std::unique_ptr<std::string> password;

  std::unique_ptr<bool> save_credentials;

  std::unique_ptr<std::vector<std::string>> server_cape_ms;

  std::unique_ptr<std::vector<std::string>> server_ca_refs;

  std::unique_ptr<std::string> subject_match;

  std::unique_ptr<std::string> tls_version_max;

  std::unique_ptr<bool> use_proactive_key_caching;

  std::unique_ptr<bool> use_system_c_as;


 private:
  DISALLOW_COPY_AND_ASSIGN(EAPProperties);
};

struct ManagedEAPProperties {
  ManagedEAPProperties();
  ~ManagedEAPProperties();
  ManagedEAPProperties(ManagedEAPProperties&& rhs);
  ManagedEAPProperties& operator=(ManagedEAPProperties&& rhs);

  // Populates a ManagedEAPProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedEAPProperties* out);

  // Creates a ManagedEAPProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedEAPProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedEAPProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedDOMString> anonymous_identity;

  std::unique_ptr<ManagedCertificatePattern> client_cert_pattern;

  std::unique_ptr<ManagedDOMString> client_cert_pkcs11_id;

  std::unique_ptr<ManagedDOMString> client_cert_ref;

  std::unique_ptr<ManagedDOMString> client_cert_type;

  std::unique_ptr<ManagedDOMString> identity;

  std::unique_ptr<ManagedDOMString> inner;

  // The outer EAP type. Required by ONC, but may not be provided when translating
  // from Shill.
  std::unique_ptr<ManagedDOMString> outer;

  std::unique_ptr<ManagedDOMString> password;

  std::unique_ptr<ManagedBoolean> save_credentials;

  std::unique_ptr<ManagedDOMStringList> server_cape_ms;

  std::unique_ptr<ManagedDOMStringList> server_ca_refs;

  std::unique_ptr<ManagedDOMString> subject_match;

  std::unique_ptr<ManagedDOMString> tls_version_max;

  std::unique_ptr<ManagedBoolean> use_proactive_key_caching;

  std::unique_ptr<ManagedBoolean> use_system_c_as;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedEAPProperties);
};

struct FoundNetworkProperties {
  FoundNetworkProperties();
  ~FoundNetworkProperties();
  FoundNetworkProperties(FoundNetworkProperties&& rhs);
  FoundNetworkProperties& operator=(FoundNetworkProperties&& rhs);

  // Populates a FoundNetworkProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, FoundNetworkProperties* out);

  // Creates a FoundNetworkProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<FoundNetworkProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FoundNetworkProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string status;

  std::string network_id;

  std::string technology;

  std::unique_ptr<std::string> short_name;

  std::unique_ptr<std::string> long_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(FoundNetworkProperties);
};

struct IPConfigProperties {
  IPConfigProperties();
  ~IPConfigProperties();
  IPConfigProperties(IPConfigProperties&& rhs);
  IPConfigProperties& operator=(IPConfigProperties&& rhs);

  // Populates a IPConfigProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, IPConfigProperties* out);

  // Creates a IPConfigProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<IPConfigProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this IPConfigProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> gateway;

  std::unique_ptr<std::string> ip_address;

  std::unique_ptr<std::vector<std::string>> excluded_routes;

  std::unique_ptr<std::vector<std::string>> included_routes;

  std::unique_ptr<std::vector<std::string>> name_servers;

  std::unique_ptr<std::vector<std::string>> search_domains;

  std::unique_ptr<int> routing_prefix;

  std::unique_ptr<std::string> type;

  std::unique_ptr<std::string> web_proxy_auto_discovery_url;


 private:
  DISALLOW_COPY_AND_ASSIGN(IPConfigProperties);
};

struct ManagedIPConfigProperties {
  ManagedIPConfigProperties();
  ~ManagedIPConfigProperties();
  ManagedIPConfigProperties(ManagedIPConfigProperties&& rhs);
  ManagedIPConfigProperties& operator=(ManagedIPConfigProperties&& rhs);

  // Populates a ManagedIPConfigProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedIPConfigProperties* out);

  // Creates a ManagedIPConfigProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedIPConfigProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedIPConfigProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedDOMString> gateway;

  std::unique_ptr<ManagedDOMString> ip_address;

  std::unique_ptr<ManagedDOMStringList> name_servers;

  std::unique_ptr<ManagedLong> routing_prefix;

  std::unique_ptr<ManagedDOMString> type;

  std::unique_ptr<ManagedDOMString> web_proxy_auto_discovery_url;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedIPConfigProperties);
};

struct XAUTHProperties {
  XAUTHProperties();
  ~XAUTHProperties();
  XAUTHProperties(XAUTHProperties&& rhs);
  XAUTHProperties& operator=(XAUTHProperties&& rhs);

  // Populates a XAUTHProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, XAUTHProperties* out);

  // Creates a XAUTHProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<XAUTHProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this XAUTHProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> password;

  std::unique_ptr<bool> save_credentials;

  std::unique_ptr<std::string> username;


 private:
  DISALLOW_COPY_AND_ASSIGN(XAUTHProperties);
};

struct ManagedXAUTHProperties {
  ManagedXAUTHProperties();
  ~ManagedXAUTHProperties();
  ManagedXAUTHProperties(ManagedXAUTHProperties&& rhs);
  ManagedXAUTHProperties& operator=(ManagedXAUTHProperties&& rhs);

  // Populates a ManagedXAUTHProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedXAUTHProperties* out);

  // Creates a ManagedXAUTHProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedXAUTHProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedXAUTHProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedDOMString> password;

  std::unique_ptr<ManagedBoolean> save_credentials;

  std::unique_ptr<ManagedDOMString> username;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedXAUTHProperties);
};

struct IPSecProperties {
  IPSecProperties();
  ~IPSecProperties();
  IPSecProperties(IPSecProperties&& rhs);
  IPSecProperties& operator=(IPSecProperties&& rhs);

  // Populates a IPSecProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, IPSecProperties* out);

  // Creates a IPSecProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<IPSecProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this IPSecProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string authentication_type;

  std::unique_ptr<CertificatePattern> client_cert_pattern;

  std::unique_ptr<std::string> client_cert_pkcs11_id;

  std::unique_ptr<std::string> client_cert_ref;

  std::unique_ptr<std::string> client_cert_type;

  std::unique_ptr<EAPProperties> eap;

  std::unique_ptr<std::string> group;

  std::unique_ptr<int> ike_version;

  std::unique_ptr<std::string> psk;

  std::unique_ptr<bool> save_credentials;

  std::unique_ptr<std::vector<std::string>> server_cape_ms;

  std::unique_ptr<std::vector<std::string>> server_ca_refs;

  std::unique_ptr<XAUTHProperties> xauth;


 private:
  DISALLOW_COPY_AND_ASSIGN(IPSecProperties);
};

struct ManagedIPSecProperties {
  ManagedIPSecProperties();
  ~ManagedIPSecProperties();
  ManagedIPSecProperties(ManagedIPSecProperties&& rhs);
  ManagedIPSecProperties& operator=(ManagedIPSecProperties&& rhs);

  // Populates a ManagedIPSecProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedIPSecProperties* out);

  // Creates a ManagedIPSecProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedIPSecProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedIPSecProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ManagedDOMString authentication_type;

  std::unique_ptr<ManagedCertificatePattern> client_cert_pattern;

  std::unique_ptr<ManagedDOMString> client_cert_pkcs11_id;

  std::unique_ptr<ManagedDOMString> client_cert_ref;

  std::unique_ptr<ManagedDOMString> client_cert_type;

  std::unique_ptr<ManagedEAPProperties> eap;

  std::unique_ptr<ManagedDOMString> group;

  std::unique_ptr<ManagedLong> ike_version;

  std::unique_ptr<ManagedDOMString> psk;

  std::unique_ptr<ManagedBoolean> save_credentials;

  std::unique_ptr<ManagedDOMStringList> server_cape_ms;

  std::unique_ptr<ManagedDOMStringList> server_ca_refs;

  std::unique_ptr<ManagedXAUTHProperties> xauth;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedIPSecProperties);
};

struct L2TPProperties {
  L2TPProperties();
  ~L2TPProperties();
  L2TPProperties(L2TPProperties&& rhs);
  L2TPProperties& operator=(L2TPProperties&& rhs);

  // Populates a L2TPProperties object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, L2TPProperties* out);

  // Creates a L2TPProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<L2TPProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this L2TPProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> lcp_echo_disabled;

  std::unique_ptr<std::string> password;

  std::unique_ptr<bool> save_credentials;

  std::unique_ptr<std::string> username;


 private:
  DISALLOW_COPY_AND_ASSIGN(L2TPProperties);
};

struct ManagedL2TPProperties {
  ManagedL2TPProperties();
  ~ManagedL2TPProperties();
  ManagedL2TPProperties(ManagedL2TPProperties&& rhs);
  ManagedL2TPProperties& operator=(ManagedL2TPProperties&& rhs);

  // Populates a ManagedL2TPProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedL2TPProperties* out);

  // Creates a ManagedL2TPProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedL2TPProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedL2TPProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedBoolean> lcp_echo_disabled;

  std::unique_ptr<ManagedDOMString> password;

  std::unique_ptr<ManagedBoolean> save_credentials;

  std::unique_ptr<ManagedDOMString> username;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedL2TPProperties);
};

struct PaymentPortal {
  PaymentPortal();
  ~PaymentPortal();
  PaymentPortal(PaymentPortal&& rhs);
  PaymentPortal& operator=(PaymentPortal&& rhs);

  // Populates a PaymentPortal object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, PaymentPortal* out);

  // Creates a PaymentPortal object from a base::Value, or NULL on failure.
  static std::unique_ptr<PaymentPortal> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PaymentPortal object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string method;

  std::unique_ptr<std::string> post_data;

  std::unique_ptr<std::string> url;


 private:
  DISALLOW_COPY_AND_ASSIGN(PaymentPortal);
};

struct ProxyLocation {
  ProxyLocation();
  ~ProxyLocation();
  ProxyLocation(ProxyLocation&& rhs);
  ProxyLocation& operator=(ProxyLocation&& rhs);

  // Populates a ProxyLocation object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ProxyLocation* out);

  // Creates a ProxyLocation object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProxyLocation> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProxyLocation object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string host;

  int port;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProxyLocation);
};

struct ManagedProxyLocation {
  ManagedProxyLocation();
  ~ManagedProxyLocation();
  ManagedProxyLocation(ManagedProxyLocation&& rhs);
  ManagedProxyLocation& operator=(ManagedProxyLocation&& rhs);

  // Populates a ManagedProxyLocation object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedProxyLocation* out);

  // Creates a ManagedProxyLocation object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedProxyLocation> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedProxyLocation object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ManagedDOMString host;

  ManagedLong port;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedProxyLocation);
};

struct ManualProxySettings {
  ManualProxySettings();
  ~ManualProxySettings();
  ManualProxySettings(ManualProxySettings&& rhs);
  ManualProxySettings& operator=(ManualProxySettings&& rhs);

  // Populates a ManualProxySettings object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManualProxySettings* out);

  // Creates a ManualProxySettings object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManualProxySettings> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManualProxySettings object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ProxyLocation> http_proxy;

  std::unique_ptr<ProxyLocation> secure_http_proxy;

  std::unique_ptr<ProxyLocation> ftp_proxy;

  std::unique_ptr<ProxyLocation> socks;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManualProxySettings);
};

struct ManagedManualProxySettings {
  ManagedManualProxySettings();
  ~ManagedManualProxySettings();
  ManagedManualProxySettings(ManagedManualProxySettings&& rhs);
  ManagedManualProxySettings& operator=(ManagedManualProxySettings&& rhs);

  // Populates a ManagedManualProxySettings object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedManualProxySettings* out);

  // Creates a ManagedManualProxySettings object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedManualProxySettings> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedManualProxySettings object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedProxyLocation> http_proxy;

  std::unique_ptr<ManagedProxyLocation> secure_http_proxy;

  std::unique_ptr<ManagedProxyLocation> ftp_proxy;

  std::unique_ptr<ManagedProxyLocation> socks;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedManualProxySettings);
};

struct ProxySettings {
  ProxySettings();
  ~ProxySettings();
  ProxySettings(ProxySettings&& rhs);
  ProxySettings& operator=(ProxySettings&& rhs);

  // Populates a ProxySettings object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ProxySettings* out);

  // Creates a ProxySettings object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProxySettings> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProxySettings object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ProxySettingsType type;

  std::unique_ptr<ManualProxySettings> manual;

  std::unique_ptr<std::vector<std::string>> exclude_domains;

  std::unique_ptr<std::string> pac;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProxySettings);
};

struct ManagedProxySettings {
  ManagedProxySettings();
  ~ManagedProxySettings();
  ManagedProxySettings(ManagedProxySettings&& rhs);
  ManagedProxySettings& operator=(ManagedProxySettings&& rhs);

  // Populates a ManagedProxySettings object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedProxySettings* out);

  // Creates a ManagedProxySettings object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedProxySettings> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedProxySettings object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ManagedProxySettingsType type;

  std::unique_ptr<ManagedManualProxySettings> manual;

  std::unique_ptr<ManagedDOMStringList> exclude_domains;

  std::unique_ptr<ManagedDOMString> pac;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedProxySettings);
};

struct VerifyX509 {
  VerifyX509();
  ~VerifyX509();
  VerifyX509(VerifyX509&& rhs);
  VerifyX509& operator=(VerifyX509&& rhs);

  // Populates a VerifyX509 object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, VerifyX509* out);

  // Creates a VerifyX509 object from a base::Value, or NULL on failure.
  static std::unique_ptr<VerifyX509> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this VerifyX509 object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> name;

  std::unique_ptr<std::string> type;


 private:
  DISALLOW_COPY_AND_ASSIGN(VerifyX509);
};

struct ManagedVerifyX509 {
  ManagedVerifyX509();
  ~ManagedVerifyX509();
  ManagedVerifyX509(ManagedVerifyX509&& rhs);
  ManagedVerifyX509& operator=(ManagedVerifyX509&& rhs);

  // Populates a ManagedVerifyX509 object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedVerifyX509* out);

  // Creates a ManagedVerifyX509 object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManagedVerifyX509> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedVerifyX509 object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedDOMString> name;

  std::unique_ptr<ManagedDOMString> type;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedVerifyX509);
};

struct OpenVPNProperties {
  OpenVPNProperties();
  ~OpenVPNProperties();
  OpenVPNProperties(OpenVPNProperties&& rhs);
  OpenVPNProperties& operator=(OpenVPNProperties&& rhs);

  // Populates a OpenVPNProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, OpenVPNProperties* out);

  // Creates a OpenVPNProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<OpenVPNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this OpenVPNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> auth;

  std::unique_ptr<std::string> auth_retry;

  std::unique_ptr<bool> auth_no_cache;

  std::unique_ptr<std::string> cipher;

  std::unique_ptr<std::string> client_cert_pkcs11_id;

  std::unique_ptr<CertificatePattern> client_cert_pattern;

  std::unique_ptr<std::string> client_cert_ref;

  std::unique_ptr<std::string> client_cert_type;

  std::unique_ptr<std::string> comp_lzo;

  std::unique_ptr<bool> comp_no_adapt;

  std::unique_ptr<std::vector<std::string>> extra_hosts;

  std::unique_ptr<bool> ignore_default_route;

  std::unique_ptr<std::string> key_direction;

  std::unique_ptr<std::string> ns_cert_type;

  std::unique_ptr<std::string> otp;

  std::unique_ptr<std::string> password;

  std::unique_ptr<int> port;

  std::unique_ptr<std::string> proto;

  std::unique_ptr<bool> push_peer_info;

  std::unique_ptr<std::string> remote_cert_eku;

  std::unique_ptr<std::vector<std::string>> remote_cert_ku;

  std::unique_ptr<std::string> remote_cert_tls;

  std::unique_ptr<int> reneg_sec;

  std::unique_ptr<bool> save_credentials;

  std::unique_ptr<std::vector<std::string>> server_cape_ms;

  std::unique_ptr<std::vector<std::string>> server_ca_refs;

  std::unique_ptr<std::string> server_cert_ref;

  std::unique_ptr<int> server_poll_timeout;

  std::unique_ptr<int> shaper;

  std::unique_ptr<std::string> static_challenge;

  std::unique_ptr<std::string> tls_auth_contents;

  std::unique_ptr<std::string> tls_remote;

  std::unique_ptr<std::string> tls_version_min;

  std::unique_ptr<std::string> user_authentication_type;

  std::unique_ptr<std::string> username;

  std::unique_ptr<std::string> verb;

  std::unique_ptr<std::string> verify_hash;

  std::unique_ptr<VerifyX509> verify_x509;


 private:
  DISALLOW_COPY_AND_ASSIGN(OpenVPNProperties);
};

struct ManagedOpenVPNProperties {
  ManagedOpenVPNProperties();
  ~ManagedOpenVPNProperties();
  ManagedOpenVPNProperties(ManagedOpenVPNProperties&& rhs);
  ManagedOpenVPNProperties& operator=(ManagedOpenVPNProperties&& rhs);

  // Populates a ManagedOpenVPNProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedOpenVPNProperties* out);

  // Creates a ManagedOpenVPNProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedOpenVPNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedOpenVPNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedDOMString> auth;

  std::unique_ptr<ManagedDOMString> auth_retry;

  std::unique_ptr<ManagedBoolean> auth_no_cache;

  std::unique_ptr<ManagedDOMString> cipher;

  std::unique_ptr<ManagedDOMString> client_cert_pkcs11_id;

  std::unique_ptr<ManagedCertificatePattern> client_cert_pattern;

  std::unique_ptr<ManagedDOMString> client_cert_ref;

  std::unique_ptr<ManagedDOMString> client_cert_type;

  std::unique_ptr<ManagedDOMString> comp_lzo;

  std::unique_ptr<ManagedBoolean> comp_no_adapt;

  std::unique_ptr<ManagedDOMStringList> extra_hosts;

  std::unique_ptr<ManagedBoolean> ignore_default_route;

  std::unique_ptr<ManagedDOMString> key_direction;

  std::unique_ptr<ManagedDOMString> ns_cert_type;

  std::unique_ptr<ManagedDOMString> otp;

  std::unique_ptr<ManagedDOMString> password;

  std::unique_ptr<ManagedLong> port;

  std::unique_ptr<ManagedDOMString> proto;

  std::unique_ptr<ManagedBoolean> push_peer_info;

  std::unique_ptr<ManagedDOMString> remote_cert_eku;

  std::unique_ptr<ManagedDOMStringList> remote_cert_ku;

  std::unique_ptr<ManagedDOMString> remote_cert_tls;

  std::unique_ptr<ManagedLong> reneg_sec;

  std::unique_ptr<ManagedBoolean> save_credentials;

  std::unique_ptr<ManagedDOMStringList> server_cape_ms;

  std::unique_ptr<ManagedDOMStringList> server_ca_refs;

  std::unique_ptr<ManagedDOMString> server_cert_ref;

  std::unique_ptr<ManagedLong> server_poll_timeout;

  std::unique_ptr<ManagedLong> shaper;

  std::unique_ptr<ManagedDOMString> static_challenge;

  std::unique_ptr<ManagedDOMString> tls_auth_contents;

  std::unique_ptr<ManagedDOMString> tls_remote;

  std::unique_ptr<ManagedDOMString> tls_version_min;

  std::unique_ptr<ManagedDOMString> user_authentication_type;

  std::unique_ptr<ManagedDOMString> username;

  std::unique_ptr<ManagedDOMString> verb;

  std::unique_ptr<ManagedDOMString> verify_hash;

  std::unique_ptr<ManagedVerifyX509> verify_x509;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedOpenVPNProperties);
};

struct SIMLockStatus {
  SIMLockStatus();
  ~SIMLockStatus();
  SIMLockStatus(SIMLockStatus&& rhs);
  SIMLockStatus& operator=(SIMLockStatus&& rhs);

  // Populates a SIMLockStatus object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, SIMLockStatus* out);

  // Creates a SIMLockStatus object from a base::Value, or NULL on failure.
  static std::unique_ptr<SIMLockStatus> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SIMLockStatus object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string lock_type;

  // sim-pin, sim-puk, or ''
  bool lock_enabled;

  std::unique_ptr<int> retries_left;


 private:
  DISALLOW_COPY_AND_ASSIGN(SIMLockStatus);
};

struct ThirdPartyVPNProperties {
  ThirdPartyVPNProperties();
  ~ThirdPartyVPNProperties();
  ThirdPartyVPNProperties(ThirdPartyVPNProperties&& rhs);
  ThirdPartyVPNProperties& operator=(ThirdPartyVPNProperties&& rhs);

  // Populates a ThirdPartyVPNProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ThirdPartyVPNProperties* out);

  // Creates a ThirdPartyVPNProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ThirdPartyVPNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ThirdPartyVPNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string extension_id;

  std::unique_ptr<std::string> provider_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(ThirdPartyVPNProperties);
};

struct ManagedThirdPartyVPNProperties {
  ManagedThirdPartyVPNProperties();
  ~ManagedThirdPartyVPNProperties();
  ManagedThirdPartyVPNProperties(ManagedThirdPartyVPNProperties&& rhs);
  ManagedThirdPartyVPNProperties& operator=(ManagedThirdPartyVPNProperties&& rhs);

  // Populates a ManagedThirdPartyVPNProperties object from a base::Value.
  // Returns whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedThirdPartyVPNProperties* out);

  // Creates a ManagedThirdPartyVPNProperties object from a base::Value, or NULL
  // on failure.
  static std::unique_ptr<ManagedThirdPartyVPNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedThirdPartyVPNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ManagedDOMString extension_id;

  std::unique_ptr<std::string> provider_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedThirdPartyVPNProperties);
};

struct CellularProperties {
  CellularProperties();
  ~CellularProperties();
  CellularProperties(CellularProperties&& rhs);
  CellularProperties& operator=(CellularProperties&& rhs);

  // Populates a CellularProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, CellularProperties* out);

  // Creates a CellularProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<CellularProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CellularProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> auto_connect;

  std::unique_ptr<APNProperties> apn;

  std::unique_ptr<std::vector<APNProperties>> apn_list;

  std::unique_ptr<std::string> activation_type;

  ActivationStateType activation_state;

  std::unique_ptr<bool> allow_roaming;

  std::unique_ptr<std::string> esn;

  std::unique_ptr<std::string> family;

  std::unique_ptr<std::string> firmware_revision;

  std::unique_ptr<std::vector<FoundNetworkProperties>> found_networks;

  std::unique_ptr<std::string> hardware_revision;

  std::unique_ptr<CellularProviderProperties> home_provider;

  std::unique_ptr<std::string> iccid;

  std::unique_ptr<std::string> imei;

  std::unique_ptr<APNProperties> last_good_apn;

  std::unique_ptr<std::string> manufacturer;

  std::unique_ptr<std::string> mdn;

  std::unique_ptr<std::string> meid;

  std::unique_ptr<std::string> min;

  std::unique_ptr<std::string> model_id;

  std::unique_ptr<std::string> network_technology;

  std::unique_ptr<PaymentPortal> payment_portal;

  std::unique_ptr<std::string> roaming_state;

  std::unique_ptr<bool> scanning;

  std::unique_ptr<CellularProviderProperties> serving_operator;

  std::unique_ptr<SIMLockStatus> sim_lock_status;

  std::unique_ptr<bool> sim_present;

  std::unique_ptr<int> signal_strength;

  std::unique_ptr<bool> support_network_scan;


 private:
  DISALLOW_COPY_AND_ASSIGN(CellularProperties);
};

struct ManagedCellularProperties {
  ManagedCellularProperties();
  ~ManagedCellularProperties();
  ManagedCellularProperties(ManagedCellularProperties&& rhs);
  ManagedCellularProperties& operator=(ManagedCellularProperties&& rhs);

  // Populates a ManagedCellularProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedCellularProperties* out);

  // Creates a ManagedCellularProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedCellularProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedCellularProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedBoolean> auto_connect;

  std::unique_ptr<ManagedAPNProperties> apn;

  std::unique_ptr<ManagedAPNList> apn_list;

  std::unique_ptr<std::string> activation_type;

  ActivationStateType activation_state;

  std::unique_ptr<bool> allow_roaming;

  std::unique_ptr<std::string> esn;

  std::unique_ptr<std::string> family;

  std::unique_ptr<std::string> firmware_revision;

  std::unique_ptr<std::vector<FoundNetworkProperties>> found_networks;

  std::unique_ptr<std::string> hardware_revision;

  std::unique_ptr<CellularProviderProperties> home_provider;

  std::unique_ptr<std::string> iccid;

  std::unique_ptr<std::string> imei;

  std::unique_ptr<APNProperties> last_good_apn;

  std::unique_ptr<std::string> manufacturer;

  std::unique_ptr<std::string> mdn;

  std::unique_ptr<std::string> meid;

  std::unique_ptr<std::string> min;

  std::unique_ptr<std::string> model_id;

  std::unique_ptr<std::string> network_technology;

  std::unique_ptr<PaymentPortal> payment_portal;

  std::unique_ptr<std::string> roaming_state;

  std::unique_ptr<bool> scanning;

  std::unique_ptr<CellularProviderProperties> serving_operator;

  std::unique_ptr<SIMLockStatus> sim_lock_status;

  std::unique_ptr<bool> sim_present;

  std::unique_ptr<int> signal_strength;

  std::unique_ptr<bool> support_network_scan;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedCellularProperties);
};

struct CellularStateProperties {
  CellularStateProperties();
  ~CellularStateProperties();
  CellularStateProperties(CellularStateProperties&& rhs);
  CellularStateProperties& operator=(CellularStateProperties&& rhs);

  // Populates a CellularStateProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, CellularStateProperties* out);

  // Creates a CellularStateProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<CellularStateProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CellularStateProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ActivationStateType activation_state;

  std::unique_ptr<std::string> network_technology;

  std::unique_ptr<std::string> roaming_state;

  std::unique_ptr<bool> scanning;

  std::unique_ptr<bool> sim_present;

  std::unique_ptr<int> signal_strength;


 private:
  DISALLOW_COPY_AND_ASSIGN(CellularStateProperties);
};

struct EAPStateProperties {
  EAPStateProperties();
  ~EAPStateProperties();
  EAPStateProperties(EAPStateProperties&& rhs);
  EAPStateProperties& operator=(EAPStateProperties&& rhs);

  // Populates a EAPStateProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, EAPStateProperties* out);

  // Creates a EAPStateProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<EAPStateProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EAPStateProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> outer;


 private:
  DISALLOW_COPY_AND_ASSIGN(EAPStateProperties);
};

struct EthernetProperties {
  EthernetProperties();
  ~EthernetProperties();
  EthernetProperties(EthernetProperties&& rhs);
  EthernetProperties& operator=(EthernetProperties&& rhs);

  // Populates a EthernetProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, EthernetProperties* out);

  // Creates a EthernetProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<EthernetProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EthernetProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> auto_connect;

  std::unique_ptr<std::string> authentication;

  std::unique_ptr<EAPProperties> eap;


 private:
  DISALLOW_COPY_AND_ASSIGN(EthernetProperties);
};

struct ManagedEthernetProperties {
  ManagedEthernetProperties();
  ~ManagedEthernetProperties();
  ManagedEthernetProperties(ManagedEthernetProperties&& rhs);
  ManagedEthernetProperties& operator=(ManagedEthernetProperties&& rhs);

  // Populates a ManagedEthernetProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedEthernetProperties* out);

  // Creates a ManagedEthernetProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedEthernetProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedEthernetProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedBoolean> auto_connect;

  std::unique_ptr<ManagedDOMString> authentication;

  std::unique_ptr<ManagedEAPProperties> eap;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedEthernetProperties);
};

struct EthernetStateProperties {
  EthernetStateProperties();
  ~EthernetStateProperties();
  EthernetStateProperties(EthernetStateProperties&& rhs);
  EthernetStateProperties& operator=(EthernetStateProperties&& rhs);

  // Populates a EthernetStateProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, EthernetStateProperties* out);

  // Creates a EthernetStateProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<EthernetStateProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EthernetStateProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string authentication;


 private:
  DISALLOW_COPY_AND_ASSIGN(EthernetStateProperties);
};

struct TetherProperties {
  TetherProperties();
  ~TetherProperties();
  TetherProperties(TetherProperties&& rhs);
  TetherProperties& operator=(TetherProperties&& rhs);

  // Populates a TetherProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, TetherProperties* out);

  // Creates a TetherProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<TetherProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TetherProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<int> battery_percentage;

  std::unique_ptr<std::string> carrier;

  bool has_connected_to_host;

  std::unique_ptr<int> signal_strength;


 private:
  DISALLOW_COPY_AND_ASSIGN(TetherProperties);
};

struct VPNProperties {
  VPNProperties();
  ~VPNProperties();
  VPNProperties(VPNProperties&& rhs);
  VPNProperties& operator=(VPNProperties&& rhs);

  // Populates a VPNProperties object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, VPNProperties* out);

  // Creates a VPNProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<VPNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this VPNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> auto_connect;

  std::unique_ptr<std::string> host;

  std::unique_ptr<IPSecProperties> i_psec;

  std::unique_ptr<L2TPProperties> l2tp;

  std::unique_ptr<OpenVPNProperties> open_vpn;

  std::unique_ptr<ThirdPartyVPNProperties> third_party_vpn;

  // The VPN type. This cannot be an enum because of 'L2TP-IPSec'. This is
  // optional for NetworkConfigProperties which is passed to setProperties which
  // may be used to set only specific properties.
  std::unique_ptr<std::string> type;


 private:
  DISALLOW_COPY_AND_ASSIGN(VPNProperties);
};

struct ManagedVPNProperties {
  ManagedVPNProperties();
  ~ManagedVPNProperties();
  ManagedVPNProperties(ManagedVPNProperties&& rhs);
  ManagedVPNProperties& operator=(ManagedVPNProperties&& rhs);

  // Populates a ManagedVPNProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedVPNProperties* out);

  // Creates a ManagedVPNProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedVPNProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedVPNProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedBoolean> auto_connect;

  std::unique_ptr<ManagedDOMString> host;

  std::unique_ptr<ManagedIPSecProperties> i_psec;

  std::unique_ptr<ManagedL2TPProperties> l2tp;

  std::unique_ptr<ManagedOpenVPNProperties> open_vpn;

  std::unique_ptr<ManagedThirdPartyVPNProperties> third_party_vpn;

  std::unique_ptr<ManagedDOMString> type;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedVPNProperties);
};

struct VPNStateProperties {
  VPNStateProperties();
  ~VPNStateProperties();
  VPNStateProperties(VPNStateProperties&& rhs);
  VPNStateProperties& operator=(VPNStateProperties&& rhs);

  // Populates a VPNStateProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, VPNStateProperties* out);

  // Creates a VPNStateProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<VPNStateProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this VPNStateProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string type;

  std::unique_ptr<IPSecProperties> i_psec;

  std::unique_ptr<ThirdPartyVPNProperties> third_party_vpn;


 private:
  DISALLOW_COPY_AND_ASSIGN(VPNStateProperties);
};

struct WiFiProperties {
  WiFiProperties();
  ~WiFiProperties();
  WiFiProperties(WiFiProperties&& rhs);
  WiFiProperties& operator=(WiFiProperties&& rhs);

  // Populates a WiFiProperties object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, WiFiProperties* out);

  // Creates a WiFiProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<WiFiProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this WiFiProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> allow_gateway_arp_polling;

  std::unique_ptr<bool> auto_connect;

  std::unique_ptr<std::string> bssid;

  std::unique_ptr<EAPProperties> eap;

  std::unique_ptr<int> frequency;

  std::unique_ptr<std::vector<int>> frequency_list;

  std::unique_ptr<bool> ft_enabled;

  std::unique_ptr<std::string> hex_ssid;

  std::unique_ptr<bool> hidden_ssid;

  std::unique_ptr<std::string> passphrase;

  std::unique_ptr<std::string> ssid;

  std::unique_ptr<std::string> security;

  std::unique_ptr<int> signal_strength;

  std::unique_ptr<std::string> tethering_state;


 private:
  DISALLOW_COPY_AND_ASSIGN(WiFiProperties);
};

struct ManagedWiFiProperties {
  ManagedWiFiProperties();
  ~ManagedWiFiProperties();
  ManagedWiFiProperties(ManagedWiFiProperties&& rhs);
  ManagedWiFiProperties& operator=(ManagedWiFiProperties&& rhs);

  // Populates a ManagedWiFiProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedWiFiProperties* out);

  // Creates a ManagedWiFiProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ManagedWiFiProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedWiFiProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedBoolean> allow_gateway_arp_polling;

  std::unique_ptr<ManagedBoolean> auto_connect;

  std::unique_ptr<std::string> bssid;

  std::unique_ptr<ManagedEAPProperties> eap;

  std::unique_ptr<int> frequency;

  std::unique_ptr<std::vector<int>> frequency_list;

  std::unique_ptr<ManagedBoolean> ft_enabled;

  std::unique_ptr<ManagedDOMString> hex_ssid;

  std::unique_ptr<ManagedBoolean> hidden_ssid;

  std::unique_ptr<ManagedDOMString> passphrase;

  std::unique_ptr<ManagedDOMString> ssid;

  ManagedDOMString security;

  std::unique_ptr<int> signal_strength;

  std::unique_ptr<std::string> tethering_state;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedWiFiProperties);
};

struct WiFiStateProperties {
  WiFiStateProperties();
  ~WiFiStateProperties();
  WiFiStateProperties(WiFiStateProperties&& rhs);
  WiFiStateProperties& operator=(WiFiStateProperties&& rhs);

  // Populates a WiFiStateProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, WiFiStateProperties* out);

  // Creates a WiFiStateProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<WiFiStateProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this WiFiStateProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> bssid;

  std::unique_ptr<EAPStateProperties> eap;

  std::unique_ptr<int> frequency;

  std::unique_ptr<std::string> hex_ssid;

  std::string security;

  std::unique_ptr<int> signal_strength;

  std::unique_ptr<std::string> ssid;

  std::unique_ptr<std::string> tethering_state;


 private:
  DISALLOW_COPY_AND_ASSIGN(WiFiStateProperties);
};

struct NetworkConfigProperties {
  NetworkConfigProperties();
  ~NetworkConfigProperties();
  NetworkConfigProperties(NetworkConfigProperties&& rhs);
  NetworkConfigProperties& operator=(NetworkConfigProperties&& rhs);

  // Populates a NetworkConfigProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, NetworkConfigProperties* out);

  // Creates a NetworkConfigProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<NetworkConfigProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NetworkConfigProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<CellularProperties> cellular;

  std::unique_ptr<EthernetProperties> ethernet;

  std::unique_ptr<std::string> guid;

  IPConfigType ip_address_config_type;

  std::unique_ptr<std::string> name;

  IPConfigType name_servers_config_type;

  std::unique_ptr<int> priority;

  std::unique_ptr<ProxySettings> proxy_settings;

  std::unique_ptr<IPConfigProperties> static_ip_config;

  NetworkType type;

  std::unique_ptr<VPNProperties> vpn;

  std::unique_ptr<WiFiProperties> wi_fi;


 private:
  DISALLOW_COPY_AND_ASSIGN(NetworkConfigProperties);
};

struct NetworkProperties {
  NetworkProperties();
  ~NetworkProperties();
  NetworkProperties(NetworkProperties&& rhs);
  NetworkProperties& operator=(NetworkProperties&& rhs);

  // Populates a NetworkProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, NetworkProperties* out);

  // Creates a NetworkProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<NetworkProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NetworkProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<CellularProperties> cellular;

  std::unique_ptr<bool> connectable;

  ConnectionStateType connection_state;

  std::unique_ptr<std::string> error_state;

  std::unique_ptr<EthernetProperties> ethernet;

  std::string guid;

  IPConfigType ip_address_config_type;

  std::unique_ptr<std::vector<IPConfigProperties>> ip_configs;

  std::unique_ptr<std::string> mac_address;

  std::unique_ptr<bool> metered;

  std::unique_ptr<std::string> name;

  IPConfigType name_servers_config_type;

  std::unique_ptr<int> priority;

  std::unique_ptr<ProxySettings> proxy_settings;

  std::unique_ptr<bool> restricted_connectivity;

  std::unique_ptr<IPConfigProperties> static_ip_config;

  std::unique_ptr<IPConfigProperties> saved_ip_config;

  // Indicates whether and how the network is configured. 'Source' can be Device,
  // DevicePolicy, User, UserPolicy or None. 'None' conflicts with extension code
  // generation so we must use a string for 'Source' instead of a SourceType enum.
  std::unique_ptr<std::string> source;

  std::unique_ptr<TetherProperties> tether;

  NetworkType type;

  std::unique_ptr<VPNProperties> vpn;

  std::unique_ptr<WiFiProperties> wi_fi;


 private:
  DISALLOW_COPY_AND_ASSIGN(NetworkProperties);
};

struct ManagedProperties {
  ManagedProperties();
  ~ManagedProperties();
  ManagedProperties(ManagedProperties&& rhs);
  ManagedProperties& operator=(ManagedProperties&& rhs);

  // Populates a ManagedProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManagedProperties* out);

  // Creates a ManagedProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManagedProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManagedProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<ManagedCellularProperties> cellular;

  std::unique_ptr<bool> connectable;

  ConnectionStateType connection_state;

  std::unique_ptr<std::string> error_state;

  std::unique_ptr<ManagedEthernetProperties> ethernet;

  std::string guid;

  std::unique_ptr<ManagedIPConfigType> ip_address_config_type;

  std::unique_ptr<std::vector<IPConfigProperties>> ip_configs;

  std::unique_ptr<std::string> mac_address;

  std::unique_ptr<ManagedBoolean> metered;

  std::unique_ptr<ManagedDOMString> name;

  std::unique_ptr<ManagedIPConfigType> name_servers_config_type;

  std::unique_ptr<ManagedLong> priority;

  std::unique_ptr<ManagedProxySettings> proxy_settings;

  std::unique_ptr<bool> restricted_connectivity;

  std::unique_ptr<ManagedIPConfigProperties> static_ip_config;

  std::unique_ptr<IPConfigProperties> saved_ip_config;

  // See $(ref:NetworkProperties.Source).
  std::unique_ptr<std::string> source;

  std::unique_ptr<TetherProperties> tether;

  NetworkType type;

  std::unique_ptr<ManagedVPNProperties> vpn;

  std::unique_ptr<ManagedWiFiProperties> wi_fi;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManagedProperties);
};

struct NetworkStateProperties {
  NetworkStateProperties();
  ~NetworkStateProperties();
  NetworkStateProperties(NetworkStateProperties&& rhs);
  NetworkStateProperties& operator=(NetworkStateProperties&& rhs);

  // Populates a NetworkStateProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, NetworkStateProperties* out);

  // Creates a NetworkStateProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<NetworkStateProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NetworkStateProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<CellularStateProperties> cellular;

  std::unique_ptr<bool> connectable;

  ConnectionStateType connection_state;

  std::unique_ptr<EthernetStateProperties> ethernet;

  std::unique_ptr<std::string> error_state;

  std::string guid;

  std::unique_ptr<std::string> name;

  std::unique_ptr<int> priority;

  // See $(ref:NetworkProperties.Source).
  std::unique_ptr<std::string> source;

  std::unique_ptr<TetherProperties> tether;

  NetworkType type;

  std::unique_ptr<VPNStateProperties> vpn;

  std::unique_ptr<WiFiStateProperties> wi_fi;


 private:
  DISALLOW_COPY_AND_ASSIGN(NetworkStateProperties);
};

struct DeviceStateProperties {
  DeviceStateProperties();
  ~DeviceStateProperties();
  DeviceStateProperties(DeviceStateProperties&& rhs);
  DeviceStateProperties& operator=(DeviceStateProperties&& rhs);

  // Populates a DeviceStateProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, DeviceStateProperties* out);

  // Creates a DeviceStateProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<DeviceStateProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceStateProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Set if the device is enabled. True if the device is currently scanning.
  std::unique_ptr<bool> scanning;

  // The SIM lock status if Type = Cellular and SIMPresent = True.
  std::unique_ptr<SIMLockStatus> sim_lock_status;

  // Set to the SIM present state if the device type is Cellular.
  std::unique_ptr<bool> sim_present;

  // The current state of the device.
  DeviceStateType state;

  // The network type associated with the device (Cellular, Ethernet or WiFi).
  NetworkType type;

  // Whether or not any managed networks are available/visible.
  std::unique_ptr<bool> managed_network_available;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceStateProperties);
};

struct VerificationProperties {
  VerificationProperties();
  ~VerificationProperties();
  VerificationProperties(VerificationProperties&& rhs);
  VerificationProperties& operator=(VerificationProperties&& rhs);

  // Populates a VerificationProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, VerificationProperties* out);

  // Creates a VerificationProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<VerificationProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this VerificationProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A string containing a PEM-encoded (including the 'BEGIN CERTIFICATE' header
  // and 'END CERTIFICATE' footer) X.509 certificate for use in verifying the
  // signed data.
  std::string certificate;

  // An array of PEM-encoded X.509 intermediate certificate authority
  // certificates. Each PEM-encoded certificate is expected to have the 'BEGIN
  // CERTIFICATE' header and 'END CERTIFICATE' footer.
  std::unique_ptr<std::vector<std::string>> intermediate_certificates;

  // A string containing a base64-encoded RSAPublicKey ASN.1 structure,
  // representing the public key to be used by $(ref:verifyAndEncryptCredentials)
  // and $(ref:verifyAndEncryptData) methods.
  std::string public_key;

  // A string containing a base64-encoded random binary data for use in verifying
  // the signed data.
  std::string nonce;

  // A string containing the identifying data string signed by the device.
  std::string signed_data;

  // A string containing the serial number of the device.
  std::string device_serial;

  // A string containing the SSID of the device. Should be empty for new
  // configurations.
  std::string device_ssid;

  // A string containing the BSSID of the device. Should be empty for new
  // configurations.
  std::string device_bssid;


 private:
  DISALLOW_COPY_AND_ASSIGN(VerificationProperties);
};

struct NetworkFilter {
  NetworkFilter();
  ~NetworkFilter();
  NetworkFilter(NetworkFilter&& rhs);
  NetworkFilter& operator=(NetworkFilter&& rhs);

  // Populates a NetworkFilter object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, NetworkFilter* out);

  // Creates a NetworkFilter object from a base::Value, or NULL on failure.
  static std::unique_ptr<NetworkFilter> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NetworkFilter object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The type of networks to return.
  NetworkType network_type;

  // If true, only include visible (physically connected or in-range) networks.
  // Defaults to 'false'.
  std::unique_ptr<bool> visible;

  // If true, only include configured (saved) networks. Defaults to 'false'.
  std::unique_ptr<bool> configured;

  // Maximum number of networks to return. Defaults to 1000 if unspecified. Use 0
  // for no limit.
  std::unique_ptr<int> limit;


 private:
  DISALLOW_COPY_AND_ASSIGN(NetworkFilter);
};

struct GlobalPolicy {
  GlobalPolicy();
  ~GlobalPolicy();
  GlobalPolicy(GlobalPolicy&& rhs);
  GlobalPolicy& operator=(GlobalPolicy&& rhs);

  // Populates a GlobalPolicy object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, GlobalPolicy* out);

  // Creates a GlobalPolicy object from a base::Value, or NULL on failure.
  static std::unique_ptr<GlobalPolicy> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GlobalPolicy object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // If true, only policy networks may auto connect. Defaults to false.
  std::unique_ptr<bool> allow_only_policy_networks_to_autoconnect;

  // If true, only policy networks may be connected to and no new networks may be
  // added or configured. Defaults to false.
  std::unique_ptr<bool> allow_only_policy_networks_to_connect;

  // If true and a managed network is available in the visible network list, only
  // policy networks may be connected to and no new networks may be added or
  // configured. Defaults to false.
  std::unique_ptr<bool> allow_only_policy_networks_to_connect_if_available;

  // List of blacklisted networks. Connections to blacklisted networks are
  // prohibited. Networks can be whitelisted again by specifying an explicit
  // network configuration. Defaults to an empty list.
  std::unique_ptr<std::vector<std::string>> blacklisted_hex_ssi_ds;


 private:
  DISALLOW_COPY_AND_ASSIGN(GlobalPolicy);
};

struct Certificate {
  Certificate();
  ~Certificate();
  Certificate(Certificate&& rhs);
  Certificate& operator=(Certificate&& rhs);

  // Populates a Certificate object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, Certificate* out);

  // Creates a Certificate object from a base::Value, or NULL on failure.
  static std::unique_ptr<Certificate> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Certificate object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Unique hash for the certificate.
  std::string hash;

  // Certificate issuer common name.
  std::string issued_by;

  // Certificate name or nickname.
  std::string issued_to;

  // PEM for server CA certificates.
  std::unique_ptr<std::string> pem;

  // PKCS#11 id for user certificates.
  std::unique_ptr<std::string> pkcs11_id;

  // Whether or not the certificate is hardware backed.
  bool hardware_backed;

  // Whether or not the certificate is device wide.
  bool device_wide;


 private:
  DISALLOW_COPY_AND_ASSIGN(Certificate);
};

struct CertificateLists {
  CertificateLists();
  ~CertificateLists();
  CertificateLists(CertificateLists&& rhs);
  CertificateLists& operator=(CertificateLists&& rhs);

  // Populates a CertificateLists object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, CertificateLists* out);

  // Creates a CertificateLists object from a base::Value, or NULL on failure.
  static std::unique_ptr<CertificateLists> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CertificateLists object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // List of avaliable server CA certificates.
  std::vector<Certificate> server_ca_certificates;

  // List of available user certificates.
  std::vector<Certificate> user_certificates;


 private:
  DISALLOW_COPY_AND_ASSIGN(CertificateLists);
};


//
// Functions
//

namespace GetProperties {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to get properties for.
  std::string network_guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const NetworkProperties& result);
}  // namespace Results

}  // namespace GetProperties

namespace GetManagedProperties {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to get properties for.
  std::string network_guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ManagedProperties& result);
}  // namespace Results

}  // namespace GetManagedProperties

namespace GetState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to get properties for.
  std::string network_guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const NetworkStateProperties& result);
}  // namespace Results

}  // namespace GetState

namespace SetProperties {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to set properties for.
  std::string network_guid;

  // The properties to set.
  NetworkConfigProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetProperties

namespace CreateNetwork {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // If true, share this network configuration with other users.
  bool shared;

  // The properties to configure the new network with.
  NetworkConfigProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& result);
}  // namespace Results

}  // namespace CreateNetwork

namespace ForgetNetwork {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to forget.
  std::string network_guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ForgetNetwork

namespace GetNetworks {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Describes which networks to return.
  NetworkFilter filter;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<NetworkStateProperties>& result);
}  // namespace Results

}  // namespace GetNetworks

namespace GetVisibleNetworks {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  NetworkType network_type;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<NetworkStateProperties>& result);
}  // namespace Results

}  // namespace GetVisibleNetworks

namespace GetEnabledNetworkTypes {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<NetworkType>& result);
}  // namespace Results

}  // namespace GetEnabledNetworkTypes

namespace GetDeviceStates {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<DeviceStateProperties>& result);
}  // namespace Results

}  // namespace GetDeviceStates

namespace EnableNetworkType {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The type of network to enable.
  NetworkType network_type;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace EnableNetworkType

namespace DisableNetworkType {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The type of network to disable.
  NetworkType network_type;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace DisableNetworkType

namespace RequestNetworkScan {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // If provided, requests a scan specific to the type.     For Cellular a mobile
  // network scan will be requested if supported.
  NetworkType network_type;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RequestNetworkScan

namespace StartConnect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to connect to.
  std::string network_guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartConnect

namespace StartDisconnect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to disconnect from.
  std::string network_guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartDisconnect

namespace StartActivate {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the Cellular network to activate.
  std::string network_guid;

  // Optional name of carrier to activate.
  std::unique_ptr<std::string> carrier;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartActivate

namespace VerifyDestination {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Properties of the destination to use in verifying that it     is a trusted
  // device.
  VerificationProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace VerifyDestination

namespace VerifyAndEncryptData {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Properties of the destination to use in verifying that it     is a trusted
  // device.
  VerificationProperties properties;

  // A string containing the base64-encoded data to encrypt.
  std::string data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& result);
}  // namespace Results

}  // namespace VerifyAndEncryptData

namespace SetWifiTDLSEnabledState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The IP or MAC address of the peer with which to     enable a TDLS connection.
  // |enabled| If true, enable TDLS, otherwise disable TDLS.
  std::string ip_or_mac_address;

  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& result);
}  // namespace Results

}  // namespace SetWifiTDLSEnabledState

namespace GetWifiTDLSStatus {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The IP or MAC address of the peer.
  std::string ip_or_mac_address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& result);
}  // namespace Results

}  // namespace GetWifiTDLSStatus

namespace GetCaptivePortalStatus {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the network to get captive portal status for.
  std::string network_guid;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const CaptivePortalStatus& result);
}  // namespace Results

}  // namespace GetCaptivePortalStatus

namespace UnlockCellularSim {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the cellular network to unlock.     If empty, the default
  // cellular device will be used.
  std::string network_guid;

  // The current SIM PIN, or the new PIN if PUK is provided.
  std::string pin;

  // The operator provided PUK for unblocking a blocked SIM.
  std::unique_ptr<std::string> puk;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UnlockCellularSim

namespace SetCellularSimState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the cellular network to set the SIM state of.     If empty, the
  // default cellular device will be used.
  std::string network_guid;

  // The SIM state to set.
  CellularSimState sim_state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetCellularSimState

namespace SelectCellularMobileNetwork {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The GUID of the cellular network to select the network     for. If empty, the
  // default cellular device will be used.
  std::string network_guid;

  // The networkId to select.
  std::string network_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SelectCellularMobileNetwork

namespace GetGlobalPolicy {

namespace Results {

std::unique_ptr<base::ListValue> Create(const GlobalPolicy& result);
}  // namespace Results

}  // namespace GetGlobalPolicy

namespace GetCertificateLists {

namespace Results {

std::unique_ptr<base::ListValue> Create(const CertificateLists& result);
}  // namespace Results

}  // namespace GetCertificateLists

//
// Events
//

namespace OnNetworksChanged {

extern const char kEventName[];  // "networkingPrivate.onNetworksChanged"

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& changes);
}  // namespace OnNetworksChanged

namespace OnNetworkListChanged {

extern const char kEventName[];  // "networkingPrivate.onNetworkListChanged"

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& changes);
}  // namespace OnNetworkListChanged

namespace OnDeviceStateListChanged {

extern const char kEventName[];  // "networkingPrivate.onDeviceStateListChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnDeviceStateListChanged

namespace OnPortalDetectionCompleted {

extern const char kEventName[];  // "networkingPrivate.onPortalDetectionCompleted"

std::unique_ptr<base::ListValue> Create(const std::string& network_guid, const CaptivePortalStatus& status);
}  // namespace OnPortalDetectionCompleted

namespace OnCertificateListsChanged {

extern const char kEventName[];  // "networkingPrivate.onCertificateListsChanged"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnCertificateListsChanged

}  // namespace networking_private
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_NETWORKING_PRIVATE_H__
