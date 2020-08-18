// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/bluetooth_low_energy.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_BLUETOOTH_LOW_ENERGY_H__
#define EXTENSIONS_COMMON_API_BLUETOOTH_LOW_ENERGY_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace bluetooth_low_energy {

//
// Types
//

// Values representing the possible properties of a characteristic.
// Characteristic permissions are inferred from these properties. Please see the
// Bluetooth 4.x spec to see the meaning of each individual property.
enum CharacteristicProperty {
  CHARACTERISTIC_PROPERTY_NONE,
  CHARACTERISTIC_PROPERTY_BROADCAST,
  CHARACTERISTIC_PROPERTY_READ,
  CHARACTERISTIC_PROPERTY_WRITEWITHOUTRESPONSE,
  CHARACTERISTIC_PROPERTY_WRITE,
  CHARACTERISTIC_PROPERTY_NOTIFY,
  CHARACTERISTIC_PROPERTY_INDICATE,
  CHARACTERISTIC_PROPERTY_AUTHENTICATEDSIGNEDWRITES,
  CHARACTERISTIC_PROPERTY_EXTENDEDPROPERTIES,
  CHARACTERISTIC_PROPERTY_RELIABLEWRITE,
  CHARACTERISTIC_PROPERTY_WRITABLEAUXILIARIES,
  CHARACTERISTIC_PROPERTY_ENCRYPTREAD,
  CHARACTERISTIC_PROPERTY_ENCRYPTWRITE,
  CHARACTERISTIC_PROPERTY_ENCRYPTAUTHENTICATEDREAD,
  CHARACTERISTIC_PROPERTY_ENCRYPTAUTHENTICATEDWRITE,
  CHARACTERISTIC_PROPERTY_LAST = CHARACTERISTIC_PROPERTY_ENCRYPTAUTHENTICATEDWRITE,
};


const char* ToString(CharacteristicProperty as_enum);
CharacteristicProperty ParseCharacteristicProperty(const std::string& as_string);

// Values representing possible permissions for a descriptor. Please see the
// Bluetooth 4.x spec to see the meaning of each individual permission.
enum DescriptorPermission {
  DESCRIPTOR_PERMISSION_NONE,
  DESCRIPTOR_PERMISSION_READ,
  DESCRIPTOR_PERMISSION_WRITE,
  DESCRIPTOR_PERMISSION_ENCRYPTEDREAD,
  DESCRIPTOR_PERMISSION_ENCRYPTEDWRITE,
  DESCRIPTOR_PERMISSION_ENCRYPTEDAUTHENTICATEDREAD,
  DESCRIPTOR_PERMISSION_ENCRYPTEDAUTHENTICATEDWRITE,
  DESCRIPTOR_PERMISSION_LAST = DESCRIPTOR_PERMISSION_ENCRYPTEDAUTHENTICATEDWRITE,
};


const char* ToString(DescriptorPermission as_enum);
DescriptorPermission ParseDescriptorPermission(const std::string& as_string);

// Type of advertisement. If 'broadcast' is chosen, the sent advertisement type
// will be ADV_NONCONN_IND and the device will broadcast with a random MAC
// Address. If set to 'peripheral', the advertisement type will be ADV_IND or
// ADV_SCAN_IND and the device will broadcast with real Bluetooth Adapter's MAC
// Address.
enum AdvertisementType {
  ADVERTISEMENT_TYPE_NONE,
  ADVERTISEMENT_TYPE_BROADCAST,
  ADVERTISEMENT_TYPE_PERIPHERAL,
  ADVERTISEMENT_TYPE_LAST = ADVERTISEMENT_TYPE_PERIPHERAL,
};


const char* ToString(AdvertisementType as_enum);
AdvertisementType ParseAdvertisementType(const std::string& as_string);

struct Device {
  Device();
  ~Device();
  Device(Device&& rhs);
  Device& operator=(Device&& rhs);

  // Populates a Device object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Device* out);

  // Creates a Device object from a base::Value, or NULL on failure.
  static std::unique_ptr<Device> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Device object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The address of the device, in the format 'XX:XX:XX:XX:XX:XX'.
  std::string address;

  // The human-readable name of the device.
  std::unique_ptr<std::string> name;

  // The class of the device, a bit-field defined by
  // http://www.bluetooth.org/en-us/specification/assigned-numbers/baseband.
  std::unique_ptr<int> device_class;


 private:
  DISALLOW_COPY_AND_ASSIGN(Device);
};

struct Service {
  Service();
  ~Service();
  Service(Service&& rhs);
  Service& operator=(Service&& rhs);

  // Populates a Service object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Service* out);

  // Creates a Service object from a base::Value, or NULL on failure.
  static std::unique_ptr<Service> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Service object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The UUID of the service, e.g. 0000180d-0000-1000-8000-00805f9b34fb.
  std::string uuid;

  // Indicates whether the type of this service is primary or secondary.
  bool is_primary;

  // Returns the identifier assigned to this service. Use the instance ID to
  // distinguish between services from a peripheral with the same UUID and to make
  // function calls that take in a service identifier. Present, if this instance
  // represents a remote service.
  std::unique_ptr<std::string> instance_id;

  // The device address of the remote peripheral that the GATT service belongs to.
  // Present, if this instance represents a remote service.
  std::unique_ptr<std::string> device_address;


 private:
  DISALLOW_COPY_AND_ASSIGN(Service);
};

struct Characteristic {
  Characteristic();
  ~Characteristic();
  Characteristic(Characteristic&& rhs);
  Characteristic& operator=(Characteristic&& rhs);

  // Populates a Characteristic object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, Characteristic* out);

  // Creates a Characteristic object from a base::Value, or NULL on failure.
  static std::unique_ptr<Characteristic> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Characteristic object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The UUID of the characteristic, e.g. 00002a37-0000-1000-8000-00805f9b34fb.
  std::string uuid;

  // The GATT service this characteristic belongs to.
  std::unique_ptr<Service> service;

  // The properties of this characteristic.
  std::vector<CharacteristicProperty> properties;

  // Returns the identifier assigned to this characteristic. Use the instance ID
  // to distinguish between characteristics from a peripheral with the same UUID
  // and to make function calls that take in a characteristic identifier. Present,
  // if this instance represents a remote characteristic.
  std::unique_ptr<std::string> instance_id;

  // The currently cached characteristic value. This value gets updated when the
  // value of the characteristic is read or updated via a notification or
  // indication.
  std::unique_ptr<std::vector<uint8_t>> value;


 private:
  DISALLOW_COPY_AND_ASSIGN(Characteristic);
};

struct Descriptor {
  Descriptor();
  ~Descriptor();
  Descriptor(Descriptor&& rhs);
  Descriptor& operator=(Descriptor&& rhs);

  // Populates a Descriptor object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Descriptor* out);

  // Creates a Descriptor object from a base::Value, or NULL on failure.
  static std::unique_ptr<Descriptor> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Descriptor object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The UUID of the characteristic descriptor, e.g.
  // 00002902-0000-1000-8000-00805f9b34fb.
  std::string uuid;

  // The GATT characteristic this descriptor belongs to.
  std::unique_ptr<Characteristic> characteristic;

  // The permissions of this descriptor.
  std::vector<DescriptorPermission> permissions;

  // Returns the identifier assigned to this descriptor. Use the instance ID to
  // distinguish between descriptors from a peripheral with the same UUID and to
  // make function calls that take in a descriptor identifier. Present, if this
  // instance represents a remote characteristic.
  std::unique_ptr<std::string> instance_id;

  // The currently cached descriptor value. This value gets updated when the value
  // of the descriptor is read.
  std::unique_ptr<std::vector<uint8_t>> value;


 private:
  DISALLOW_COPY_AND_ASSIGN(Descriptor);
};

struct ConnectProperties {
  ConnectProperties();
  ~ConnectProperties();
  ConnectProperties(ConnectProperties&& rhs);
  ConnectProperties& operator=(ConnectProperties&& rhs);

  // Populates a ConnectProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ConnectProperties* out);

  // Creates a ConnectProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<ConnectProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ConnectProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Flag indicating whether a connection to the device is left open when the
  // event page of the application is unloaded (see <a
  // href="http://developer.chrome.com/apps/app_lifecycle.html">Manage App
  // Lifecycle</a>). The default value is <code>false.</code>
  bool persistent;


 private:
  DISALLOW_COPY_AND_ASSIGN(ConnectProperties);
};

struct NotificationProperties {
  NotificationProperties();
  ~NotificationProperties();
  NotificationProperties(NotificationProperties&& rhs);
  NotificationProperties& operator=(NotificationProperties&& rhs);

  // Populates a NotificationProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, NotificationProperties* out);

  // Creates a NotificationProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<NotificationProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NotificationProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Flag indicating whether the app should receive notifications when the event
  // page of the application is unloaded (see <a
  // href="http://developer.chrome.com/apps/app_lifecycle.html">Manage App
  // Lifecycle</a>). The default value is <code>false</code>.
  bool persistent;


 private:
  DISALLOW_COPY_AND_ASSIGN(NotificationProperties);
};

struct ManufacturerData {
  ManufacturerData();
  ~ManufacturerData();
  ManufacturerData(ManufacturerData&& rhs);
  ManufacturerData& operator=(ManufacturerData&& rhs);

  // Populates a ManufacturerData object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ManufacturerData* out);

  // Creates a ManufacturerData object from a base::Value, or NULL on failure.
  static std::unique_ptr<ManufacturerData> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ManufacturerData object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int id;

  std::vector<int> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(ManufacturerData);
};

struct ServiceData {
  ServiceData();
  ~ServiceData();
  ServiceData(ServiceData&& rhs);
  ServiceData& operator=(ServiceData&& rhs);

  // Populates a ServiceData object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ServiceData* out);

  // Creates a ServiceData object from a base::Value, or NULL on failure.
  static std::unique_ptr<ServiceData> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ServiceData object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string uuid;

  std::vector<int> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(ServiceData);
};

struct Advertisement {
  Advertisement();
  ~Advertisement();
  Advertisement(Advertisement&& rhs);
  Advertisement& operator=(Advertisement&& rhs);

  // Populates a Advertisement object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, Advertisement* out);

  // Creates a Advertisement object from a base::Value, or NULL on failure.
  static std::unique_ptr<Advertisement> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Advertisement object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Type of advertisement.
  AdvertisementType type;

  // List of UUIDs to include in the "Service UUIDs" field of the Advertising
  // Data. These UUIDs can be of the 16bit, 32bit or 128 formats.
  std::unique_ptr<std::vector<std::string>> service_uuids;

  // List of manufacturer specific data to be included in "Manufacturer Specific
  // Data" fields of the advertising data.
  std::unique_ptr<std::vector<ManufacturerData>> manufacturer_data;

  // List of UUIDs to include in the "Solicit UUIDs" field of the Advertising
  // Data. These UUIDs can be of the 16bit, 32bit or 128 formats.
  std::unique_ptr<std::vector<std::string>> solicit_uuids;

  // List of service data to be included in "Service Data" fields of the
  // advertising data.
  std::unique_ptr<std::vector<ServiceData>> service_data;


 private:
  DISALLOW_COPY_AND_ASSIGN(Advertisement);
};

struct Request {
  Request();
  ~Request();
  Request(Request&& rhs);
  Request& operator=(Request&& rhs);

  // Populates a Request object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Request* out);

  // Creates a Request object from a base::Value, or NULL on failure.
  static std::unique_ptr<Request> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Request object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Unique ID for this request. Use this ID when responding to this request.
  int request_id;

  // Device that send this request.
  Device device;

  // Value to write (if this is a write request).
  std::unique_ptr<std::vector<uint8_t>> value;


 private:
  DISALLOW_COPY_AND_ASSIGN(Request);
};

struct Response {
  Response();
  ~Response();
  Response(Response&& rhs);
  Response& operator=(Response&& rhs);

  // Populates a Response object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Response* out);

  // Creates a Response object from a base::Value, or NULL on failure.
  static std::unique_ptr<Response> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Response object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Id of the request this is a response to.
  int request_id;

  // If this is an error response, this should be true.
  bool is_error;

  // Response value. Write requests and error responses will ignore this
  // parameter.
  std::unique_ptr<std::vector<uint8_t>> value;


 private:
  DISALLOW_COPY_AND_ASSIGN(Response);
};

struct Notification {
  Notification();
  ~Notification();
  Notification(Notification&& rhs);
  Notification& operator=(Notification&& rhs);

  // Populates a Notification object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, Notification* out);

  // Creates a Notification object from a base::Value, or NULL on failure.
  static std::unique_ptr<Notification> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Notification object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // New value of the characteristic.
  std::vector<uint8_t> value;

  // Optional flag for sending an indication instead of a notification.
  std::unique_ptr<bool> should_indicate;


 private:
  DISALLOW_COPY_AND_ASSIGN(Notification);
};


//
// Functions
//

namespace Connect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The Bluetooth address of the remote device to which a GATT connection should
  // be opened.
  std::string device_address;

  // Connection properties (optional).
  std::unique_ptr<ConnectProperties> properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Connect

namespace Disconnect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The Bluetooth address of the remote device.
  std::string device_address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Disconnect

namespace GetService {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the requested GATT service.
  std::string service_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Service& result);
}  // namespace Results

}  // namespace GetService

namespace CreateService {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The service to create.
  Service service;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& service_id);
}  // namespace Results

}  // namespace CreateService

namespace GetServices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The Bluetooth address of the remote device whose GATT services should be
  // returned.
  std::string device_address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Service>& result);
}  // namespace Results

}  // namespace GetServices

namespace GetCharacteristic {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the requested GATT characteristic.
  std::string characteristic_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Characteristic& result);
}  // namespace Results

}  // namespace GetCharacteristic

namespace CreateCharacteristic {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The characteristic to create.
  Characteristic characteristic;

  // ID of the service to create this characteristic for.
  std::string service_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& characteristic_id);
}  // namespace Results

}  // namespace CreateCharacteristic

namespace GetCharacteristics {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT service whose characteristics should be returned.
  std::string service_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Characteristic>& result);
}  // namespace Results

}  // namespace GetCharacteristics

namespace GetIncludedServices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT service whose included services should be
  // returned.
  std::string service_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Service>& result);
}  // namespace Results

}  // namespace GetIncludedServices

namespace GetDescriptor {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the requested GATT characteristic descriptor.
  std::string descriptor_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Descriptor& result);
}  // namespace Results

}  // namespace GetDescriptor

namespace CreateDescriptor {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The descriptor to create.
  Descriptor descriptor;

  // ID of the characteristic to create this descriptor for.
  std::string characteristic_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& descriptor_id);
}  // namespace Results

}  // namespace CreateDescriptor

namespace GetDescriptors {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT characteristic whose descriptors should be
  // returned.
  std::string characteristic_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Descriptor>& result);
}  // namespace Results

}  // namespace GetDescriptors

namespace ReadCharacteristicValue {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT characteristic whose value should be read from
  // the remote device.
  std::string characteristic_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Characteristic& result);
}  // namespace Results

}  // namespace ReadCharacteristicValue

namespace WriteCharacteristicValue {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT characteristic whose value should be written to.
  std::string characteristic_id;

  // The value that should be sent to the remote characteristic as part of the
  // write request.
  std::vector<uint8_t> value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace WriteCharacteristicValue

namespace StartCharacteristicNotifications {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT characteristic that notifications should be
  // enabled on.
  std::string characteristic_id;

  // Notification session properties (optional).
  std::unique_ptr<NotificationProperties> properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartCharacteristicNotifications

namespace StopCharacteristicNotifications {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT characteristic on which this app's notification
  // session should be stopped.
  std::string characteristic_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StopCharacteristicNotifications

namespace NotifyCharacteristicValueChanged {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The characteristic to send the notication for.
  std::string characteristic_id;

  Notification notification;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace NotifyCharacteristicValueChanged

namespace ReadDescriptorValue {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT characteristic descriptor whose value should be
  // read from the remote device.
  std::string descriptor_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Descriptor& result);
}  // namespace Results

}  // namespace ReadDescriptorValue

namespace WriteDescriptorValue {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The instance ID of the GATT characteristic descriptor whose value should be
  // written to.
  std::string descriptor_id;

  // The value that should be sent to the remote descriptor as part of the write
  // request.
  std::vector<uint8_t> value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace WriteDescriptorValue

namespace RegisterService {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Unique ID of a created service.
  std::string service_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RegisterService

namespace UnregisterService {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Unique ID of a current registered service.
  std::string service_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UnregisterService

namespace RemoveService {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Unique ID of a current registered service.
  std::string service_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveService

namespace RegisterAdvertisement {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The advertisement to advertise.
  Advertisement advertisement;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int advertisement_id);
}  // namespace Results

}  // namespace RegisterAdvertisement

namespace UnregisterAdvertisement {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Id of the advertisement to unregister.
  int advertisement_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UnregisterAdvertisement

namespace ResetAdvertising {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ResetAdvertising

namespace SetAdvertisingInterval {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Minimum interval between advertisments (in milliseconds). This cannot be
  // lower than 20ms (as per the spec).
  int min_interval;

  // Maximum interval between advertisments (in milliseconds). This cannot be more
  // than 10240ms (as per the spec).
  int max_interval;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetAdvertisingInterval

namespace SendRequestResponse {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The response to the request.
  Response response;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SendRequestResponse

//
// Events
//

namespace OnServiceAdded {

extern const char kEventName[];  // "bluetoothLowEnergy.onServiceAdded"

// The GATT service that was added.
std::unique_ptr<base::ListValue> Create(const Service& service);
}  // namespace OnServiceAdded

namespace OnServiceChanged {

extern const char kEventName[];  // "bluetoothLowEnergy.onServiceChanged"

// The GATT service whose state has changed.
std::unique_ptr<base::ListValue> Create(const Service& service);
}  // namespace OnServiceChanged

namespace OnServiceRemoved {

extern const char kEventName[];  // "bluetoothLowEnergy.onServiceRemoved"

// The GATT service that was removed.
std::unique_ptr<base::ListValue> Create(const Service& service);
}  // namespace OnServiceRemoved

namespace OnCharacteristicValueChanged {

extern const char kEventName[];  // "bluetoothLowEnergy.onCharacteristicValueChanged"

// The GATT characteristic whose value has changed.
std::unique_ptr<base::ListValue> Create(const Characteristic& characteristic);
}  // namespace OnCharacteristicValueChanged

namespace OnDescriptorValueChanged {

extern const char kEventName[];  // "bluetoothLowEnergy.onDescriptorValueChanged"

// The GATT characteristic descriptor whose value has changed.
std::unique_ptr<base::ListValue> Create(const Descriptor& descriptor);
}  // namespace OnDescriptorValueChanged

namespace OnCharacteristicReadRequest {

extern const char kEventName[];  // "bluetoothLowEnergy.onCharacteristicReadRequest"

// Request data for this request.
std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& characteristic_id);
}  // namespace OnCharacteristicReadRequest

namespace OnCharacteristicWriteRequest {

extern const char kEventName[];  // "bluetoothLowEnergy.onCharacteristicWriteRequest"

// Request data for this request.
std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& characteristic_id);
}  // namespace OnCharacteristicWriteRequest

namespace OnDescriptorReadRequest {

extern const char kEventName[];  // "bluetoothLowEnergy.onDescriptorReadRequest"

// Request data for this request.
std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& descriptor_id);
}  // namespace OnDescriptorReadRequest

namespace OnDescriptorWriteRequest {

extern const char kEventName[];  // "bluetoothLowEnergy.onDescriptorWriteRequest"

// Request data for this request.
std::unique_ptr<base::ListValue> Create(const Request& request, const std::string& descriptor_id);
}  // namespace OnDescriptorWriteRequest

}  // namespace bluetooth_low_energy
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_BLUETOOTH_LOW_ENERGY_H__
