// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/bluetooth_private.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_BLUETOOTH_PRIVATE_H__
#define EXTENSIONS_COMMON_API_BLUETOOTH_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"


namespace extensions {
namespace api {
namespace bluetooth_private {

//
// Types
//

// Events that can occur during pairing. The method used for pairing varies
// depending on the capability of the two devices.
enum PairingEventType {
  PAIRING_EVENT_TYPE_NONE,
  PAIRING_EVENT_TYPE_REQUESTPINCODE,
  PAIRING_EVENT_TYPE_DISPLAYPINCODE,
  PAIRING_EVENT_TYPE_REQUESTPASSKEY,
  PAIRING_EVENT_TYPE_DISPLAYPASSKEY,
  PAIRING_EVENT_TYPE_KEYSENTERED,
  PAIRING_EVENT_TYPE_CONFIRMPASSKEY,
  PAIRING_EVENT_TYPE_REQUESTAUTHORIZATION,
  PAIRING_EVENT_TYPE_COMPLETE,
  PAIRING_EVENT_TYPE_LAST = PAIRING_EVENT_TYPE_COMPLETE,
};


const char* ToString(PairingEventType as_enum);
PairingEventType ParsePairingEventType(const std::string& as_string);

// Results for connect(). See function declaration for details.
enum ConnectResultType {
  CONNECT_RESULT_TYPE_NONE,
  CONNECT_RESULT_TYPE_ALREADYCONNECTED,
  CONNECT_RESULT_TYPE_AUTHCANCELED,
  CONNECT_RESULT_TYPE_AUTHFAILED,
  CONNECT_RESULT_TYPE_AUTHREJECTED,
  CONNECT_RESULT_TYPE_AUTHTIMEOUT,
  CONNECT_RESULT_TYPE_FAILED,
  CONNECT_RESULT_TYPE_INPROGRESS,
  CONNECT_RESULT_TYPE_SUCCESS,
  CONNECT_RESULT_TYPE_UNKNOWNERROR,
  CONNECT_RESULT_TYPE_UNSUPPORTEDDEVICE,
  CONNECT_RESULT_TYPE_LAST = CONNECT_RESULT_TYPE_UNSUPPORTEDDEVICE,
};


const char* ToString(ConnectResultType as_enum);
ConnectResultType ParseConnectResultType(const std::string& as_string);

// Valid pairing responses.
enum PairingResponse {
  PAIRING_RESPONSE_NONE,
  PAIRING_RESPONSE_CONFIRM,
  PAIRING_RESPONSE_REJECT,
  PAIRING_RESPONSE_CANCEL,
  PAIRING_RESPONSE_LAST = PAIRING_RESPONSE_CANCEL,
};


const char* ToString(PairingResponse as_enum);
PairingResponse ParsePairingResponse(const std::string& as_string);

enum TransportType {
  TRANSPORT_TYPE_NONE,
  TRANSPORT_TYPE_LE,
  TRANSPORT_TYPE_BREDR,
  TRANSPORT_TYPE_DUAL,
  TRANSPORT_TYPE_LAST = TRANSPORT_TYPE_DUAL,
};


const char* ToString(TransportType as_enum);
TransportType ParseTransportType(const std::string& as_string);

struct PairingEvent {
  PairingEvent();
  ~PairingEvent();
  PairingEvent(PairingEvent&& rhs);
  PairingEvent& operator=(PairingEvent&& rhs);

  // Populates a PairingEvent object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, PairingEvent* out);

  // Creates a PairingEvent object from a base::Value, or NULL on failure.
  static std::unique_ptr<PairingEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PairingEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  PairingEventType pairing;

  extensions::api::bluetooth::Device device;

  std::unique_ptr<std::string> pincode;

  std::unique_ptr<int> passkey;

  std::unique_ptr<int> entered_key;


 private:
  DISALLOW_COPY_AND_ASSIGN(PairingEvent);
};

struct NewAdapterState {
  NewAdapterState();
  ~NewAdapterState();
  NewAdapterState(NewAdapterState&& rhs);
  NewAdapterState& operator=(NewAdapterState&& rhs);

  // Populates a NewAdapterState object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, NewAdapterState* out);

  // Creates a NewAdapterState object from a base::Value, or NULL on failure.
  static std::unique_ptr<NewAdapterState> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NewAdapterState object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The human-readable name of the adapter.
  std::unique_ptr<std::string> name;

  // Whether or not the adapter has power.
  std::unique_ptr<bool> powered;

  // Whether the adapter is discoverable by other devices.
  std::unique_ptr<bool> discoverable;


 private:
  DISALLOW_COPY_AND_ASSIGN(NewAdapterState);
};

struct SetPairingResponseOptions {
  SetPairingResponseOptions();
  ~SetPairingResponseOptions();
  SetPairingResponseOptions(SetPairingResponseOptions&& rhs);
  SetPairingResponseOptions& operator=(SetPairingResponseOptions&& rhs);

  // Populates a SetPairingResponseOptions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, SetPairingResponseOptions* out);

  // Creates a SetPairingResponseOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<SetPairingResponseOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SetPairingResponseOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The remote device to send the pairing response.
  extensions::api::bluetooth::Device device;

  // The response type.
  PairingResponse response;

  // A 1-16 character alphanumeric set in response to <code>requestPincode</code>.
  std::unique_ptr<std::string> pincode;

  // An integer between 0-999999 set in response to <code>requestPasskey</code>.
  std::unique_ptr<int> passkey;


 private:
  DISALLOW_COPY_AND_ASSIGN(SetPairingResponseOptions);
};

struct DiscoveryFilter {
  DiscoveryFilter();
  ~DiscoveryFilter();
  DiscoveryFilter(DiscoveryFilter&& rhs);
  DiscoveryFilter& operator=(DiscoveryFilter&& rhs);

  // Populates a DiscoveryFilter object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DiscoveryFilter* out);

  // Creates a DiscoveryFilter object from a base::Value, or NULL on failure.
  static std::unique_ptr<DiscoveryFilter> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DiscoveryFilter object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // uuid of service or array of uuids
  struct Uuids {
    Uuids();
    ~Uuids();
    Uuids(Uuids&& rhs);
    Uuids& operator=(Uuids&& rhs);

    // Populates a Uuids object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Uuids* out);

    // Returns a new base::Value representing the serialized form of this Uuids
    // object.
    std::unique_ptr<base::Value> ToValue() const;
    // Choices:
    std::unique_ptr<std::string> as_string;
    std::unique_ptr<std::vector<std::string>> as_strings;

   private:
    DISALLOW_COPY_AND_ASSIGN(Uuids);
  };


  // Transport type.
  TransportType transport;

  // uuid of service or array of uuids
  std::unique_ptr<Uuids> uuids;

  // RSSI ranging value. Only devices with RSSI higher than this value will be
  // reported.
  std::unique_ptr<int> rssi;

  // Pathloss ranging value. Only devices with pathloss lower than this value will
  // be reported.
  std::unique_ptr<int> pathloss;


 private:
  DISALLOW_COPY_AND_ASSIGN(DiscoveryFilter);
};


//
// Functions
//

namespace SetAdapterState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The new state of the adapter.
  NewAdapterState adapter_state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetAdapterState

namespace SetPairingResponse {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  SetPairingResponseOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetPairingResponse

namespace DisconnectAll {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string device_address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DisconnectAll

namespace ForgetDevice {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string device_address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ForgetDevice

namespace SetDiscoveryFilter {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  DiscoveryFilter discovery_filter;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetDiscoveryFilter

namespace Connect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string device_address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ConnectResultType& result);
}  // namespace Results

}  // namespace Connect

namespace Pair {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string device_address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Pair

namespace RecordPairing {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  extensions::api::bluetooth::Transport transport;

  int pairing_duration_ms;

  ConnectResultType result;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordPairing

namespace RecordReconnection {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  ConnectResultType result;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordReconnection

namespace RecordDeviceSelection {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int selection_duration_ms;

  bool was_paired;

  extensions::api::bluetooth::Transport transport;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordDeviceSelection

//
// Events
//

namespace OnPairing {

extern const char kEventName[];  // "bluetoothPrivate.onPairing"

// A pairing event.
std::unique_ptr<base::ListValue> Create(const PairingEvent& pairing_event);
}  // namespace OnPairing

namespace OnDeviceAddressChanged {

extern const char kEventName[];  // "bluetoothPrivate.onDeviceAddressChanged"

std::unique_ptr<base::ListValue> Create(const extensions::api::bluetooth::Device& device, const std::string& old_address);
}  // namespace OnDeviceAddressChanged

}  // namespace bluetooth_private
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_BLUETOOTH_PRIVATE_H__
