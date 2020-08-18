// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/bluetooth_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/bluetooth_private.h"
#include <set>
#include <utility>
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"
#include "extensions/common/api/bluetooth.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace bluetooth_private {
//
// Types
//

const char* ToString(PairingEventType enum_param) {
  switch (enum_param) {
    case PAIRING_EVENT_TYPE_REQUESTPINCODE:
      return "requestPincode";
    case PAIRING_EVENT_TYPE_DISPLAYPINCODE:
      return "displayPincode";
    case PAIRING_EVENT_TYPE_REQUESTPASSKEY:
      return "requestPasskey";
    case PAIRING_EVENT_TYPE_DISPLAYPASSKEY:
      return "displayPasskey";
    case PAIRING_EVENT_TYPE_KEYSENTERED:
      return "keysEntered";
    case PAIRING_EVENT_TYPE_CONFIRMPASSKEY:
      return "confirmPasskey";
    case PAIRING_EVENT_TYPE_REQUESTAUTHORIZATION:
      return "requestAuthorization";
    case PAIRING_EVENT_TYPE_COMPLETE:
      return "complete";
    case PAIRING_EVENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PairingEventType ParsePairingEventType(const std::string& enum_string) {
  if (enum_string == "requestPincode")
    return PAIRING_EVENT_TYPE_REQUESTPINCODE;
  if (enum_string == "displayPincode")
    return PAIRING_EVENT_TYPE_DISPLAYPINCODE;
  if (enum_string == "requestPasskey")
    return PAIRING_EVENT_TYPE_REQUESTPASSKEY;
  if (enum_string == "displayPasskey")
    return PAIRING_EVENT_TYPE_DISPLAYPASSKEY;
  if (enum_string == "keysEntered")
    return PAIRING_EVENT_TYPE_KEYSENTERED;
  if (enum_string == "confirmPasskey")
    return PAIRING_EVENT_TYPE_CONFIRMPASSKEY;
  if (enum_string == "requestAuthorization")
    return PAIRING_EVENT_TYPE_REQUESTAUTHORIZATION;
  if (enum_string == "complete")
    return PAIRING_EVENT_TYPE_COMPLETE;
  return PAIRING_EVENT_TYPE_NONE;
}


const char* ToString(ConnectResultType enum_param) {
  switch (enum_param) {
    case CONNECT_RESULT_TYPE_ALREADYCONNECTED:
      return "alreadyConnected";
    case CONNECT_RESULT_TYPE_AUTHCANCELED:
      return "authCanceled";
    case CONNECT_RESULT_TYPE_AUTHFAILED:
      return "authFailed";
    case CONNECT_RESULT_TYPE_AUTHREJECTED:
      return "authRejected";
    case CONNECT_RESULT_TYPE_AUTHTIMEOUT:
      return "authTimeout";
    case CONNECT_RESULT_TYPE_FAILED:
      return "failed";
    case CONNECT_RESULT_TYPE_INPROGRESS:
      return "inProgress";
    case CONNECT_RESULT_TYPE_SUCCESS:
      return "success";
    case CONNECT_RESULT_TYPE_UNKNOWNERROR:
      return "unknownError";
    case CONNECT_RESULT_TYPE_UNSUPPORTEDDEVICE:
      return "unsupportedDevice";
    case CONNECT_RESULT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ConnectResultType ParseConnectResultType(const std::string& enum_string) {
  if (enum_string == "alreadyConnected")
    return CONNECT_RESULT_TYPE_ALREADYCONNECTED;
  if (enum_string == "authCanceled")
    return CONNECT_RESULT_TYPE_AUTHCANCELED;
  if (enum_string == "authFailed")
    return CONNECT_RESULT_TYPE_AUTHFAILED;
  if (enum_string == "authRejected")
    return CONNECT_RESULT_TYPE_AUTHREJECTED;
  if (enum_string == "authTimeout")
    return CONNECT_RESULT_TYPE_AUTHTIMEOUT;
  if (enum_string == "failed")
    return CONNECT_RESULT_TYPE_FAILED;
  if (enum_string == "inProgress")
    return CONNECT_RESULT_TYPE_INPROGRESS;
  if (enum_string == "success")
    return CONNECT_RESULT_TYPE_SUCCESS;
  if (enum_string == "unknownError")
    return CONNECT_RESULT_TYPE_UNKNOWNERROR;
  if (enum_string == "unsupportedDevice")
    return CONNECT_RESULT_TYPE_UNSUPPORTEDDEVICE;
  return CONNECT_RESULT_TYPE_NONE;
}


const char* ToString(PairingResponse enum_param) {
  switch (enum_param) {
    case PAIRING_RESPONSE_CONFIRM:
      return "confirm";
    case PAIRING_RESPONSE_REJECT:
      return "reject";
    case PAIRING_RESPONSE_CANCEL:
      return "cancel";
    case PAIRING_RESPONSE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PairingResponse ParsePairingResponse(const std::string& enum_string) {
  if (enum_string == "confirm")
    return PAIRING_RESPONSE_CONFIRM;
  if (enum_string == "reject")
    return PAIRING_RESPONSE_REJECT;
  if (enum_string == "cancel")
    return PAIRING_RESPONSE_CANCEL;
  return PAIRING_RESPONSE_NONE;
}


const char* ToString(TransportType enum_param) {
  switch (enum_param) {
    case TRANSPORT_TYPE_LE:
      return "le";
    case TRANSPORT_TYPE_BREDR:
      return "bredr";
    case TRANSPORT_TYPE_DUAL:
      return "dual";
    case TRANSPORT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TransportType ParseTransportType(const std::string& enum_string) {
  if (enum_string == "le")
    return TRANSPORT_TYPE_LE;
  if (enum_string == "bredr")
    return TRANSPORT_TYPE_BREDR;
  if (enum_string == "dual")
    return TRANSPORT_TYPE_DUAL;
  return TRANSPORT_TYPE_NONE;
}


PairingEvent::PairingEvent()
: pairing(PAIRING_EVENT_TYPE_NONE) {}

PairingEvent::~PairingEvent() {}
PairingEvent::PairingEvent(PairingEvent&& rhs)
: pairing(rhs.pairing),
device(std::move(rhs.device)),
pincode(std::move(rhs.pincode)),
passkey(std::move(rhs.passkey)),
entered_key(std::move(rhs.entered_key)){
}

PairingEvent& PairingEvent::operator=(PairingEvent&& rhs)
{
pairing = rhs.pairing;
device = std::move(rhs.device);
pincode = std::move(rhs.pincode);
passkey = std::move(rhs.passkey);
entered_key = std::move(rhs.entered_key);
return *this;
}

// static
bool PairingEvent::Populate(
    const base::Value& value, PairingEvent* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* pairing_value = NULL;
  if (!dict->GetWithoutPathExpansion("pairing", &pairing_value)) {
    return false;
  }
  {
    std::string pairing_event_type_as_string;
    if (!pairing_value->GetAsString(&pairing_event_type_as_string)) {
      return false;
    }
    out->pairing = ParsePairingEventType(pairing_event_type_as_string);
    if (out->pairing == PAIRING_EVENT_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* device_value = NULL;
  if (!dict->GetWithoutPathExpansion("device", &device_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!device_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!extensions::api::bluetooth::Device::Populate(*dictionary, &out->device)) {
      return false;
    }
  }

  const base::Value* pincode_value = NULL;
  if (dict->GetWithoutPathExpansion("pincode", &pincode_value)) {
    {
      std::string temp;
      if (!pincode_value->GetAsString(&temp)) {
        out->pincode.reset();
        return false;
      }
      else
        out->pincode.reset(new std::string(temp));
    }
  }

  const base::Value* passkey_value = NULL;
  if (dict->GetWithoutPathExpansion("passkey", &passkey_value)) {
    {
      int temp;
      if (!passkey_value->GetAsInteger(&temp)) {
        out->passkey.reset();
        return false;
      }
      else
        out->passkey.reset(new int(temp));
    }
  }

  const base::Value* entered_key_value = NULL;
  if (dict->GetWithoutPathExpansion("enteredKey", &entered_key_value)) {
    {
      int temp;
      if (!entered_key_value->GetAsInteger(&temp)) {
        out->entered_key.reset();
        return false;
      }
      else
        out->entered_key.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<PairingEvent> PairingEvent::FromValue(const base::Value& value) {
  std::unique_ptr<PairingEvent> out(new PairingEvent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PairingEvent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("pairing", std::make_unique<base::Value>(bluetooth_private::ToString(this->pairing)));

  to_value_result->SetWithoutPathExpansion("device", (this->device).ToValue());

  if (this->pincode.get()) {
    to_value_result->SetWithoutPathExpansion("pincode", std::make_unique<base::Value>(*this->pincode));

  }
  if (this->passkey.get()) {
    to_value_result->SetWithoutPathExpansion("passkey", std::make_unique<base::Value>(*this->passkey));

  }
  if (this->entered_key.get()) {
    to_value_result->SetWithoutPathExpansion("enteredKey", std::make_unique<base::Value>(*this->entered_key));

  }

  return to_value_result;
}


NewAdapterState::NewAdapterState()
 {}

NewAdapterState::~NewAdapterState() {}
NewAdapterState::NewAdapterState(NewAdapterState&& rhs)
: name(std::move(rhs.name)),
powered(std::move(rhs.powered)),
discoverable(std::move(rhs.discoverable)){
}

NewAdapterState& NewAdapterState::operator=(NewAdapterState&& rhs)
{
name = std::move(rhs.name);
powered = std::move(rhs.powered);
discoverable = std::move(rhs.discoverable);
return *this;
}

// static
bool NewAdapterState::Populate(
    const base::Value& value, NewAdapterState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
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

  const base::Value* powered_value = NULL;
  if (dict->GetWithoutPathExpansion("powered", &powered_value)) {
    {
      bool temp;
      if (!powered_value->GetAsBoolean(&temp)) {
        out->powered.reset();
        return false;
      }
      else
        out->powered.reset(new bool(temp));
    }
  }

  const base::Value* discoverable_value = NULL;
  if (dict->GetWithoutPathExpansion("discoverable", &discoverable_value)) {
    {
      bool temp;
      if (!discoverable_value->GetAsBoolean(&temp)) {
        out->discoverable.reset();
        return false;
      }
      else
        out->discoverable.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<NewAdapterState> NewAdapterState::FromValue(const base::Value& value) {
  std::unique_ptr<NewAdapterState> out(new NewAdapterState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> NewAdapterState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(*this->name));

  }
  if (this->powered.get()) {
    to_value_result->SetWithoutPathExpansion("powered", std::make_unique<base::Value>(*this->powered));

  }
  if (this->discoverable.get()) {
    to_value_result->SetWithoutPathExpansion("discoverable", std::make_unique<base::Value>(*this->discoverable));

  }

  return to_value_result;
}


SetPairingResponseOptions::SetPairingResponseOptions()
: response(PAIRING_RESPONSE_NONE) {}

SetPairingResponseOptions::~SetPairingResponseOptions() {}
SetPairingResponseOptions::SetPairingResponseOptions(SetPairingResponseOptions&& rhs)
: device(std::move(rhs.device)),
response(rhs.response),
pincode(std::move(rhs.pincode)),
passkey(std::move(rhs.passkey)){
}

SetPairingResponseOptions& SetPairingResponseOptions::operator=(SetPairingResponseOptions&& rhs)
{
device = std::move(rhs.device);
response = rhs.response;
pincode = std::move(rhs.pincode);
passkey = std::move(rhs.passkey);
return *this;
}

// static
bool SetPairingResponseOptions::Populate(
    const base::Value& value, SetPairingResponseOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* device_value = NULL;
  if (!dict->GetWithoutPathExpansion("device", &device_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!device_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!extensions::api::bluetooth::Device::Populate(*dictionary, &out->device)) {
      return false;
    }
  }

  const base::Value* response_value = NULL;
  if (!dict->GetWithoutPathExpansion("response", &response_value)) {
    return false;
  }
  {
    std::string pairing_response_as_string;
    if (!response_value->GetAsString(&pairing_response_as_string)) {
      return false;
    }
    out->response = ParsePairingResponse(pairing_response_as_string);
    if (out->response == PAIRING_RESPONSE_NONE) {
      return false;
    }
  }

  const base::Value* pincode_value = NULL;
  if (dict->GetWithoutPathExpansion("pincode", &pincode_value)) {
    {
      std::string temp;
      if (!pincode_value->GetAsString(&temp)) {
        out->pincode.reset();
        return false;
      }
      else
        out->pincode.reset(new std::string(temp));
    }
  }

  const base::Value* passkey_value = NULL;
  if (dict->GetWithoutPathExpansion("passkey", &passkey_value)) {
    {
      int temp;
      if (!passkey_value->GetAsInteger(&temp)) {
        out->passkey.reset();
        return false;
      }
      else
        out->passkey.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<SetPairingResponseOptions> SetPairingResponseOptions::FromValue(const base::Value& value) {
  std::unique_ptr<SetPairingResponseOptions> out(new SetPairingResponseOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SetPairingResponseOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("device", (this->device).ToValue());

  to_value_result->SetWithoutPathExpansion("response", std::make_unique<base::Value>(bluetooth_private::ToString(this->response)));

  if (this->pincode.get()) {
    to_value_result->SetWithoutPathExpansion("pincode", std::make_unique<base::Value>(*this->pincode));

  }
  if (this->passkey.get()) {
    to_value_result->SetWithoutPathExpansion("passkey", std::make_unique<base::Value>(*this->passkey));

  }

  return to_value_result;
}


DiscoveryFilter::Uuids::Uuids()
 {}

DiscoveryFilter::Uuids::~Uuids() {}
DiscoveryFilter::Uuids::Uuids(Uuids&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)){
}

DiscoveryFilter::Uuids& DiscoveryFilter::Uuids::operator=(Uuids&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool DiscoveryFilter::Uuids::Populate(
    const base::Value& value, Uuids* out) {
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

std::unique_ptr<base::Value> DiscoveryFilter::Uuids::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for uuids";
    result = std::make_unique<base::Value>(*as_string);

  }
  if (as_strings) {
    DCHECK(!result) << "Cannot set multiple choices for uuids";
    result = json_schema_compiler::util::CreateValueFromOptionalArray(as_strings);

  }
  DCHECK(result) << "Must set at least one choice for uuids";
  return result;
}



DiscoveryFilter::DiscoveryFilter()
: transport(TRANSPORT_TYPE_NONE) {}

DiscoveryFilter::~DiscoveryFilter() {}
DiscoveryFilter::DiscoveryFilter(DiscoveryFilter&& rhs)
: transport(rhs.transport),
uuids(std::move(rhs.uuids)),
rssi(std::move(rhs.rssi)),
pathloss(std::move(rhs.pathloss)){
}

DiscoveryFilter& DiscoveryFilter::operator=(DiscoveryFilter&& rhs)
{
transport = rhs.transport;
uuids = std::move(rhs.uuids);
rssi = std::move(rhs.rssi);
pathloss = std::move(rhs.pathloss);
return *this;
}

// static
bool DiscoveryFilter::Populate(
    const base::Value& value, DiscoveryFilter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->transport = TRANSPORT_TYPE_NONE;
  const base::Value* transport_value = NULL;
  if (dict->GetWithoutPathExpansion("transport", &transport_value)) {
    {
      std::string transport_type_as_string;
      if (!transport_value->GetAsString(&transport_type_as_string)) {
        return false;
      }
      out->transport = ParseTransportType(transport_type_as_string);
      if (out->transport == TRANSPORT_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->transport = TRANSPORT_TYPE_NONE;
  }

  const base::Value* uuids_value = NULL;
  if (dict->GetWithoutPathExpansion("uuids", &uuids_value)) {
    {
      std::unique_ptr<Uuids> temp(new Uuids());
      if (!Uuids::Populate(*uuids_value, temp.get()))
        return false;
      out->uuids = std::move(temp);
    }
  }

  const base::Value* rssi_value = NULL;
  if (dict->GetWithoutPathExpansion("rssi", &rssi_value)) {
    {
      int temp;
      if (!rssi_value->GetAsInteger(&temp)) {
        out->rssi.reset();
        return false;
      }
      else
        out->rssi.reset(new int(temp));
    }
  }

  const base::Value* pathloss_value = NULL;
  if (dict->GetWithoutPathExpansion("pathloss", &pathloss_value)) {
    {
      int temp;
      if (!pathloss_value->GetAsInteger(&temp)) {
        out->pathloss.reset();
        return false;
      }
      else
        out->pathloss.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DiscoveryFilter> DiscoveryFilter::FromValue(const base::Value& value) {
  std::unique_ptr<DiscoveryFilter> out(new DiscoveryFilter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DiscoveryFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->transport != TRANSPORT_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("transport", std::make_unique<base::Value>(bluetooth_private::ToString(this->transport)));

  }
  if (this->uuids.get()) {
    to_value_result->SetWithoutPathExpansion("uuids", (this->uuids)->ToValue());

  }
  if (this->rssi.get()) {
    to_value_result->SetWithoutPathExpansion("rssi", std::make_unique<base::Value>(*this->rssi));

  }
  if (this->pathloss.get()) {
    to_value_result->SetWithoutPathExpansion("pathloss", std::make_unique<base::Value>(*this->pathloss));

  }

  return to_value_result;
}



//
// Functions
//

namespace SetAdapterState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* adapter_state_value = NULL;
  if (args.Get(0, &adapter_state_value) &&
      !adapter_state_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!adapter_state_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!NewAdapterState::Populate(*dictionary, &params->adapter_state)) {
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
}  // namespace SetAdapterState

namespace SetPairingResponse {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!SetPairingResponseOptions::Populate(*dictionary, &params->options)) {
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
}  // namespace SetPairingResponse

namespace DisconnectAll {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_address_value = NULL;
  if (args.Get(0, &device_address_value) &&
      !device_address_value->is_none()) {
    {
      if (!device_address_value->GetAsString(&params->device_address)) {
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
}  // namespace DisconnectAll

namespace ForgetDevice {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_address_value = NULL;
  if (args.Get(0, &device_address_value) &&
      !device_address_value->is_none()) {
    {
      if (!device_address_value->GetAsString(&params->device_address)) {
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
}  // namespace ForgetDevice

namespace SetDiscoveryFilter {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* discovery_filter_value = NULL;
  if (args.Get(0, &discovery_filter_value) &&
      !discovery_filter_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!discovery_filter_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DiscoveryFilter::Populate(*dictionary, &params->discovery_filter)) {
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
}  // namespace SetDiscoveryFilter

namespace Connect {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_address_value = NULL;
  if (args.Get(0, &device_address_value) &&
      !device_address_value->is_none()) {
    {
      if (!device_address_value->GetAsString(&params->device_address)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ConnectResultType& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(bluetooth_private::ToString(result)));

  return create_results;
}
}  // namespace Connect

namespace Pair {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* device_address_value = NULL;
  if (args.Get(0, &device_address_value) &&
      !device_address_value->is_none()) {
    {
      if (!device_address_value->GetAsString(&params->device_address)) {
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
}  // namespace Pair

namespace RecordPairing {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());
  params->result = CONNECT_RESULT_TYPE_NONE;

  const base::Value* transport_value = NULL;
  if (args.Get(0, &transport_value) &&
      !transport_value->is_none()) {
    {
      std::string transport_as_string;
      if (!transport_value->GetAsString(&transport_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->transport = bluetooth::ParseTransport(transport_as_string);
      if (params->transport == bluetooth::TRANSPORT_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* pairing_duration_ms_value = NULL;
  if (args.Get(1, &pairing_duration_ms_value) &&
      !pairing_duration_ms_value->is_none()) {
    {
      if (!pairing_duration_ms_value->GetAsInteger(&params->pairing_duration_ms)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* result_value = NULL;
  if (args.Get(2, &result_value) &&
      !result_value->is_none()) {
    {
      std::string connect_result_type_as_string;
      if (!result_value->GetAsString(&connect_result_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->result = ParseConnectResultType(connect_result_type_as_string);
      if (params->result == CONNECT_RESULT_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }

  return params;
}


}  // namespace RecordPairing

namespace RecordReconnection {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());
  params->result = CONNECT_RESULT_TYPE_NONE;

  const base::Value* result_value = NULL;
  if (args.Get(0, &result_value) &&
      !result_value->is_none()) {
    {
      std::string connect_result_type_as_string;
      if (!result_value->GetAsString(&connect_result_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->result = ParseConnectResultType(connect_result_type_as_string);
      if (params->result == CONNECT_RESULT_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }

  return params;
}


}  // namespace RecordReconnection

namespace RecordDeviceSelection {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* selection_duration_ms_value = NULL;
  if (args.Get(0, &selection_duration_ms_value) &&
      !selection_duration_ms_value->is_none()) {
    {
      if (!selection_duration_ms_value->GetAsInteger(&params->selection_duration_ms)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* was_paired_value = NULL;
  if (args.Get(1, &was_paired_value) &&
      !was_paired_value->is_none()) {
    {
      if (!was_paired_value->GetAsBoolean(&params->was_paired)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* transport_value = NULL;
  if (args.Get(2, &transport_value) &&
      !transport_value->is_none()) {
    {
      std::string transport_as_string;
      if (!transport_value->GetAsString(&transport_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->transport = bluetooth::ParseTransport(transport_as_string);
      if (params->transport == bluetooth::TRANSPORT_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RecordDeviceSelection

//
// Events
//

namespace OnPairing {

const char kEventName[] = "bluetoothPrivate.onPairing";

std::unique_ptr<base::ListValue> Create(const PairingEvent& pairing_event) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((pairing_event).ToValue());

  return create_results;
}

}  // namespace OnPairing

namespace OnDeviceAddressChanged {

const char kEventName[] = "bluetoothPrivate.onDeviceAddressChanged";

std::unique_ptr<base::ListValue> Create(const extensions::api::bluetooth::Device& device, const std::string& old_address) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((device).ToValue());

  create_results->Append(std::make_unique<base::Value>(old_address));

  return create_results;
}

}  // namespace OnDeviceAddressChanged

}  // namespace bluetooth_private
}  // namespace api
}  // namespace extensions

