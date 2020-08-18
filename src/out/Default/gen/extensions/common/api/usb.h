// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/usb.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_USB_H__
#define EXTENSIONS_COMMON_API_USB_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace usb {

//
// Types
//

// Direction, Recipient, RequestType, and TransferType all map to their
// namesakes within the USB specification.
enum Direction {
  DIRECTION_NONE,
  DIRECTION_IN,
  DIRECTION_OUT,
  DIRECTION_LAST = DIRECTION_OUT,
};


const char* ToString(Direction as_enum);
Direction ParseDirection(const std::string& as_string);

enum Recipient {
  RECIPIENT_NONE,
  RECIPIENT_DEVICE,
  RECIPIENT_INTERFACE,
  RECIPIENT_ENDPOINT,
  RECIPIENT_OTHER,
  RECIPIENT_LAST = RECIPIENT_OTHER,
};


const char* ToString(Recipient as_enum);
Recipient ParseRecipient(const std::string& as_string);

enum RequestType {
  REQUEST_TYPE_NONE,
  REQUEST_TYPE_STANDARD,
  REQUEST_TYPE_CLASS,
  REQUEST_TYPE_VENDOR,
  REQUEST_TYPE_RESERVED,
  REQUEST_TYPE_LAST = REQUEST_TYPE_RESERVED,
};


const char* ToString(RequestType as_enum);
RequestType ParseRequestType(const std::string& as_string);

enum TransferType {
  TRANSFER_TYPE_NONE,
  TRANSFER_TYPE_CONTROL,
  TRANSFER_TYPE_INTERRUPT,
  TRANSFER_TYPE_ISOCHRONOUS,
  TRANSFER_TYPE_BULK,
  TRANSFER_TYPE_LAST = TRANSFER_TYPE_BULK,
};


const char* ToString(TransferType as_enum);
TransferType ParseTransferType(const std::string& as_string);

// For interrupt and isochronous modes, SynchronizationType and UsageType map to
// their namesakes within the USB specification.
enum SynchronizationType {
  SYNCHRONIZATION_TYPE_NONE,
  SYNCHRONIZATION_TYPE_ASYNCHRONOUS,
  SYNCHRONIZATION_TYPE_ADAPTIVE,
  SYNCHRONIZATION_TYPE_SYNCHRONOUS,
  SYNCHRONIZATION_TYPE_LAST = SYNCHRONIZATION_TYPE_SYNCHRONOUS,
};


const char* ToString(SynchronizationType as_enum);
SynchronizationType ParseSynchronizationType(const std::string& as_string);

enum UsageType {
  USAGE_TYPE_NONE,
  USAGE_TYPE_DATA,
  USAGE_TYPE_FEEDBACK,
  USAGE_TYPE_EXPLICITFEEDBACK,
  USAGE_TYPE_PERIODIC,
  USAGE_TYPE_NOTIFICATION,
  USAGE_TYPE_LAST = USAGE_TYPE_NOTIFICATION,
};


const char* ToString(UsageType as_enum);
UsageType ParseUsageType(const std::string& as_string);

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

  // An opaque ID for the USB device. It remains unchanged until the device is
  // unplugged.
  int device;

  // The device vendor ID.
  int vendor_id;

  // The product ID.
  int product_id;

  // The device version (bcdDevice field).
  int version;

  // The iProduct string read from the device, if available.
  std::string product_name;

  // The iManufacturer string read from the device, if available.
  std::string manufacturer_name;

  // The iSerialNumber string read from the device, if available.
  std::string serial_number;


 private:
  DISALLOW_COPY_AND_ASSIGN(Device);
};

struct ConnectionHandle {
  ConnectionHandle();
  ~ConnectionHandle();
  ConnectionHandle(ConnectionHandle&& rhs);
  ConnectionHandle& operator=(ConnectionHandle&& rhs);

  // Populates a ConnectionHandle object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ConnectionHandle* out);

  // Creates a ConnectionHandle object from a base::Value, or NULL on failure.
  static std::unique_ptr<ConnectionHandle> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ConnectionHandle object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // An opaque handle representing this connection to the USB device and all
  // associated claimed interfaces and pending transfers. A new handle is created
  // each time the device is opened. The connection handle is different from
  // $(ref:Device.device).
  int handle;

  // The device vendor ID.
  int vendor_id;

  // The product ID.
  int product_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(ConnectionHandle);
};

struct EndpointDescriptor {
  EndpointDescriptor();
  ~EndpointDescriptor();
  EndpointDescriptor(EndpointDescriptor&& rhs);
  EndpointDescriptor& operator=(EndpointDescriptor&& rhs);

  // Populates a EndpointDescriptor object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, EndpointDescriptor* out);

  // Creates a EndpointDescriptor object from a base::Value, or NULL on failure.
  static std::unique_ptr<EndpointDescriptor> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EndpointDescriptor object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Endpoint address.
  int address;

  // Transfer type.
  TransferType type;

  // Transfer direction.
  Direction direction;

  // Maximum packet size.
  int maximum_packet_size;

  // Transfer synchronization mode (isochronous only).
  SynchronizationType synchronization;

  // Endpoint usage hint.
  UsageType usage;

  // Polling interval (interrupt and isochronous only).
  std::unique_ptr<int> polling_interval;

  // Extra descriptor data associated with this endpoint.
  std::vector<uint8_t> extra_data;


 private:
  DISALLOW_COPY_AND_ASSIGN(EndpointDescriptor);
};

struct InterfaceDescriptor {
  InterfaceDescriptor();
  ~InterfaceDescriptor();
  InterfaceDescriptor(InterfaceDescriptor&& rhs);
  InterfaceDescriptor& operator=(InterfaceDescriptor&& rhs);

  // Populates a InterfaceDescriptor object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, InterfaceDescriptor* out);

  // Creates a InterfaceDescriptor object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<InterfaceDescriptor> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InterfaceDescriptor object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The interface number.
  int interface_number;

  // The interface alternate setting number (defaults to <code>0</code).
  int alternate_setting;

  // The USB interface class.
  int interface_class;

  // The USB interface sub-class.
  int interface_subclass;

  // The USB interface protocol.
  int interface_protocol;

  // Description of the interface.
  std::unique_ptr<std::string> description;

  // Available endpoints.
  std::vector<EndpointDescriptor> endpoints;

  // Extra descriptor data associated with this interface.
  std::vector<uint8_t> extra_data;


 private:
  DISALLOW_COPY_AND_ASSIGN(InterfaceDescriptor);
};

struct ConfigDescriptor {
  ConfigDescriptor();
  ~ConfigDescriptor();
  ConfigDescriptor(ConfigDescriptor&& rhs);
  ConfigDescriptor& operator=(ConfigDescriptor&& rhs);

  // Populates a ConfigDescriptor object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ConfigDescriptor* out);

  // Creates a ConfigDescriptor object from a base::Value, or NULL on failure.
  static std::unique_ptr<ConfigDescriptor> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ConfigDescriptor object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Is this the active configuration?
  bool active;

  // The configuration number.
  int configuration_value;

  // Description of the configuration.
  std::unique_ptr<std::string> description;

  // The device is self-powered.
  bool self_powered;

  // The device supports remote wakeup.
  bool remote_wakeup;

  // The maximum power needed by this device in milliamps (mA).
  int max_power;

  // Available interfaces.
  std::vector<InterfaceDescriptor> interfaces;

  // Extra descriptor data associated with this configuration.
  std::vector<uint8_t> extra_data;


 private:
  DISALLOW_COPY_AND_ASSIGN(ConfigDescriptor);
};

struct ControlTransferInfo {
  ControlTransferInfo();
  ~ControlTransferInfo();
  ControlTransferInfo(ControlTransferInfo&& rhs);
  ControlTransferInfo& operator=(ControlTransferInfo&& rhs);

  // Populates a ControlTransferInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ControlTransferInfo* out);

  // Creates a ControlTransferInfo object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ControlTransferInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ControlTransferInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The transfer direction (<code>"in"</code> or <code>"out"</code>).
  Direction direction;

  // The transfer target. The target given by <code>index</code> must be claimed
  // if <code>"interface"</code> or <code>"endpoint"</code>.
  Recipient recipient;

  // The request type.
  RequestType request_type;

  // The <code>bRequest</code> field, see <i>Universal Serial Bus Specification
  // Revision 1.1</i> &sect; 9.3.
  int request;

  // The <code>wValue</code> field, see <i>Ibid</i>.
  int value;

  // The <code>wIndex</code> field, see <i>Ibid</i>.
  int index;

  // The maximum number of bytes to receive (required only by input transfers).
  std::unique_ptr<int> length;

  // The data to transmit (required only by output transfers).
  std::unique_ptr<std::vector<uint8_t>> data;

  // Request timeout (in milliseconds). The default value <code>0</code> indicates
  // no timeout.
  std::unique_ptr<int> timeout;


 private:
  DISALLOW_COPY_AND_ASSIGN(ControlTransferInfo);
};

struct GenericTransferInfo {
  GenericTransferInfo();
  ~GenericTransferInfo();
  GenericTransferInfo(GenericTransferInfo&& rhs);
  GenericTransferInfo& operator=(GenericTransferInfo&& rhs);

  // Populates a GenericTransferInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, GenericTransferInfo* out);

  // Creates a GenericTransferInfo object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<GenericTransferInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GenericTransferInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The transfer direction (<code>"in"</code> or <code>"out"</code>).
  Direction direction;

  // The target endpoint address. The interface containing this endpoint must be
  // claimed.
  int endpoint;

  // The maximum number of bytes to receive (required only by input transfers).
  std::unique_ptr<int> length;

  // The data to transmit (required only by output transfers).
  std::unique_ptr<std::vector<uint8_t>> data;

  // Request timeout (in milliseconds). The default value <code>0</code> indicates
  // no timeout.
  std::unique_ptr<int> timeout;


 private:
  DISALLOW_COPY_AND_ASSIGN(GenericTransferInfo);
};

struct IsochronousTransferInfo {
  IsochronousTransferInfo();
  ~IsochronousTransferInfo();
  IsochronousTransferInfo(IsochronousTransferInfo&& rhs);
  IsochronousTransferInfo& operator=(IsochronousTransferInfo&& rhs);

  // Populates a IsochronousTransferInfo object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, IsochronousTransferInfo* out);

  // Creates a IsochronousTransferInfo object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<IsochronousTransferInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this IsochronousTransferInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Transfer parameters. The transfer length or data buffer specified in this
  // parameter block is split along <code>packetLength</code> boundaries to form
  // the individual packets of the transfer.
  GenericTransferInfo transfer_info;

  // The total number of packets in this transfer.
  int packets;

  // The length of each of the packets in this transfer.
  int packet_length;


 private:
  DISALLOW_COPY_AND_ASSIGN(IsochronousTransferInfo);
};

struct TransferResultInfo {
  TransferResultInfo();
  ~TransferResultInfo();
  TransferResultInfo(TransferResultInfo&& rhs);
  TransferResultInfo& operator=(TransferResultInfo&& rhs);

  // Populates a TransferResultInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, TransferResultInfo* out);

  // Creates a TransferResultInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<TransferResultInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TransferResultInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A value of <code>0</code> indicates that the transfer was a success. Other
  // values indicate failure.
  std::unique_ptr<int> result_code;

  // The data returned by an input transfer. <code>undefined</code> for output
  // transfers.
  std::unique_ptr<std::vector<uint8_t>> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(TransferResultInfo);
};

struct DeviceFilter {
  DeviceFilter();
  ~DeviceFilter();
  DeviceFilter(DeviceFilter&& rhs);
  DeviceFilter& operator=(DeviceFilter&& rhs);

  // Populates a DeviceFilter object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DeviceFilter* out);

  // Creates a DeviceFilter object from a base::Value, or NULL on failure.
  static std::unique_ptr<DeviceFilter> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceFilter object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Device vendor ID.
  std::unique_ptr<int> vendor_id;

  // Device product ID, checked only if the vendor ID matches.
  std::unique_ptr<int> product_id;

  // USB interface class, matches any interface on the device.
  std::unique_ptr<int> interface_class;

  // USB interface sub-class, checked only if the interface class matches.
  std::unique_ptr<int> interface_subclass;

  // USB interface protocol, checked only if the interface sub-class matches.
  std::unique_ptr<int> interface_protocol;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceFilter);
};

struct EnumerateDevicesOptions {
  EnumerateDevicesOptions();
  ~EnumerateDevicesOptions();
  EnumerateDevicesOptions(EnumerateDevicesOptions&& rhs);
  EnumerateDevicesOptions& operator=(EnumerateDevicesOptions&& rhs);

  // Populates a EnumerateDevicesOptions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, EnumerateDevicesOptions* out);

  // Creates a EnumerateDevicesOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<EnumerateDevicesOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EnumerateDevicesOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<int> vendor_id;

  std::unique_ptr<int> product_id;

  // A device matching any given filter will be returned. An empty filter list
  // will return all devices the app has permission for.
  std::unique_ptr<std::vector<DeviceFilter>> filters;


 private:
  DISALLOW_COPY_AND_ASSIGN(EnumerateDevicesOptions);
};

struct EnumerateDevicesAndRequestAccessOptions {
  EnumerateDevicesAndRequestAccessOptions();
  ~EnumerateDevicesAndRequestAccessOptions();
  EnumerateDevicesAndRequestAccessOptions(EnumerateDevicesAndRequestAccessOptions&& rhs);
  EnumerateDevicesAndRequestAccessOptions& operator=(EnumerateDevicesAndRequestAccessOptions&& rhs);

  // Populates a EnumerateDevicesAndRequestAccessOptions object from a
  // base::Value. Returns whether |out| was successfully populated.
  static bool Populate(const base::Value& value, EnumerateDevicesAndRequestAccessOptions* out);

  // Creates a EnumerateDevicesAndRequestAccessOptions object from a
  // base::Value, or NULL on failure.
  static std::unique_ptr<EnumerateDevicesAndRequestAccessOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this EnumerateDevicesAndRequestAccessOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The device vendor ID.
  int vendor_id;

  // The product ID.
  int product_id;

  // The interface ID to request access to. Only available on Chrome OS. It has no
  // effect on other platforms.
  std::unique_ptr<int> interface_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(EnumerateDevicesAndRequestAccessOptions);
};

struct DevicePromptOptions {
  DevicePromptOptions();
  ~DevicePromptOptions();
  DevicePromptOptions(DevicePromptOptions&& rhs);
  DevicePromptOptions& operator=(DevicePromptOptions&& rhs);

  // Populates a DevicePromptOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DevicePromptOptions* out);

  // Creates a DevicePromptOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<DevicePromptOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DevicePromptOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Allow the user to select multiple devices.
  std::unique_ptr<bool> multiple;

  // Filter the list of devices presented to the user. If multiple filters are
  // provided devices matching any filter will be displayed.
  std::unique_ptr<std::vector<DeviceFilter>> filters;


 private:
  DISALLOW_COPY_AND_ASSIGN(DevicePromptOptions);
};


//
// Functions
//

namespace GetDevices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The properties to search for on target devices.
  EnumerateDevicesOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Device>& devices);
}  // namespace Results

}  // namespace GetDevices

namespace GetUserSelectedDevices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Configuration of the device picker dialog box.
  DevicePromptOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<Device>& devices);
}  // namespace Results

}  // namespace GetUserSelectedDevices

namespace GetConfigurations {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The $(ref:Device) to fetch descriptors from.
  Device device;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ConfigDescriptor>& configs);
}  // namespace Results

}  // namespace GetConfigurations

namespace RequestAccess {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The $(ref:Device) to request access to.
  Device device;

  // The particular interface requested.
  int interface_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace RequestAccess

namespace OpenDevice {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The $(ref:Device) to open.
  Device device;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ConnectionHandle& handle);
}  // namespace Results

}  // namespace OpenDevice

namespace FindDevices {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The properties to search for on target devices.
  EnumerateDevicesAndRequestAccessOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ConnectionHandle>& handles);
}  // namespace Results

}  // namespace FindDevices

namespace CloseDevice {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The $(ref:ConnectionHandle) to close.
  ConnectionHandle handle;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace CloseDevice

namespace SetConfiguration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;

  int configuration_value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetConfiguration

namespace GetConfiguration {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ConfigDescriptor& config);
}  // namespace Results

}  // namespace GetConfiguration

namespace ListInterfaces {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<InterfaceDescriptor>& descriptors);
}  // namespace Results

}  // namespace ListInterfaces

namespace ClaimInterface {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;

  // The interface to be claimed.
  int interface_number;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ClaimInterface

namespace ReleaseInterface {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;

  // The interface to be released.
  int interface_number;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ReleaseInterface

namespace SetInterfaceAlternateSetting {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device where this interface has been     claimed.
  ConnectionHandle handle;

  // The interface to configure.
  int interface_number;

  // The alternate setting to configure.
  int alternate_setting;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetInterfaceAlternateSetting

namespace ControlTransfer {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;

  ControlTransferInfo transfer_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const TransferResultInfo& info);
}  // namespace Results

}  // namespace ControlTransfer

namespace BulkTransfer {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;

  // The transfer parameters.
  GenericTransferInfo transfer_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const TransferResultInfo& info);
}  // namespace Results

}  // namespace BulkTransfer

namespace InterruptTransfer {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;

  // The transfer parameters.
  GenericTransferInfo transfer_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const TransferResultInfo& info);
}  // namespace Results

}  // namespace InterruptTransfer

namespace IsochronousTransfer {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // An open connection to the device.
  ConnectionHandle handle;

  IsochronousTransferInfo transfer_info;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const TransferResultInfo& info);
}  // namespace Results

}  // namespace IsochronousTransfer

namespace ResetDevice {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A connection handle to reset.
  ConnectionHandle handle;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace ResetDevice

//
// Events
//

namespace OnDeviceAdded {

extern const char kEventName[];  // "usb.onDeviceAdded"

std::unique_ptr<base::ListValue> Create(const Device& device);
}  // namespace OnDeviceAdded

namespace OnDeviceRemoved {

extern const char kEventName[];  // "usb.onDeviceRemoved"

std::unique_ptr<base::ListValue> Create(const Device& device);
}  // namespace OnDeviceRemoved

}  // namespace usb
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_USB_H__
