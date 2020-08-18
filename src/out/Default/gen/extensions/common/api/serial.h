// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/serial.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SERIAL_H__
#define EXTENSIONS_COMMON_API_SERIAL_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace serial {

//
// Types
//

struct DeviceInfo {
  DeviceInfo();
  ~DeviceInfo();
  DeviceInfo(DeviceInfo&& rhs);
  DeviceInfo& operator=(DeviceInfo&& rhs);

  // Populates a DeviceInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, DeviceInfo* out);

  // Creates a DeviceInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<DeviceInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The device's system path. This should be passed as the <code>path</code>
  // argument to <code>chrome.serial.connect</code> in order to connect to this
  // device.
  std::string path;

  // A PCI or USB vendor ID if one can be determined for the underlying device.
  std::unique_ptr<int> vendor_id;

  // A USB product ID if one can be determined for the underlying device.
  std::unique_ptr<int> product_id;

  // A human-readable display name for the underlying device if one can be queried
  // from the host driver.
  std::unique_ptr<std::string> display_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceInfo);
};

enum DataBits {
  DATA_BITS_NONE,
  DATA_BITS_SEVEN,
  DATA_BITS_EIGHT,
  DATA_BITS_LAST = DATA_BITS_EIGHT,
};


const char* ToString(DataBits as_enum);
DataBits ParseDataBits(const std::string& as_string);

enum ParityBit {
  PARITY_BIT_NONE,
  PARITY_BIT_NO,
  PARITY_BIT_ODD,
  PARITY_BIT_EVEN,
  PARITY_BIT_LAST = PARITY_BIT_EVEN,
};


const char* ToString(ParityBit as_enum);
ParityBit ParseParityBit(const std::string& as_string);

enum StopBits {
  STOP_BITS_NONE,
  STOP_BITS_ONE,
  STOP_BITS_TWO,
  STOP_BITS_LAST = STOP_BITS_TWO,
};


const char* ToString(StopBits as_enum);
StopBits ParseStopBits(const std::string& as_string);

struct ConnectionOptions {
  ConnectionOptions();
  ~ConnectionOptions();
  ConnectionOptions(ConnectionOptions&& rhs);
  ConnectionOptions& operator=(ConnectionOptions&& rhs);

  // Populates a ConnectionOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ConnectionOptions* out);

  // Creates a ConnectionOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<ConnectionOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ConnectionOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Flag indicating whether or not the connection should be left open when the
  // application is suspended (see <a
  // href="http://developer.chrome.com/apps/app_lifecycle.html">Manage App
  // Lifecycle</a>). The default value is "false." When the application is loaded,
  // any serial connections previously opened with persistent=true can be fetched
  // with <code>getConnections</code>.
  std::unique_ptr<bool> persistent;

  // An application-defined string to associate with the connection.
  std::unique_ptr<std::string> name;

  // The size of the buffer used to receive data. The default value is 4096.
  std::unique_ptr<int> buffer_size;

  // The requested bitrate of the connection to be opened. For compatibility with
  // the widest range of hardware, this number should match one of
  // commonly-available bitrates, such as 110, 300, 1200, 2400, 4800, 9600, 14400,
  // 19200, 38400, 57600, 115200. There is no guarantee, of course, that the
  // device connected to the serial port will support the requested bitrate, even
  // if the port itself supports that bitrate. <code>9600</code> will be passed by
  // default.
  std::unique_ptr<int> bitrate;

  // <code>"eight"</code> will be passed by default.
  DataBits data_bits;

  // <code>"no"</code> will be passed by default.
  ParityBit parity_bit;

  // <code>"one"</code> will be passed by default.
  StopBits stop_bits;

  // Flag indicating whether or not to enable RTS/CTS hardware flow control.
  // Defaults to false.
  std::unique_ptr<bool> cts_flow_control;

  // The maximum amount of time (in milliseconds) to wait for new data before
  // raising an <code>onReceiveError</code> event with a "timeout" error. If zero,
  // receive timeout errors will not be raised for the connection. Defaults to 0.
  std::unique_ptr<int> receive_timeout;

  // The maximum amount of time (in milliseconds) to wait for a <code>send</code>
  // operation to complete before calling the callback with a "timeout" error. If
  // zero, send timeout errors will not be triggered. Defaults to 0.
  std::unique_ptr<int> send_timeout;


 private:
  DISALLOW_COPY_AND_ASSIGN(ConnectionOptions);
};

struct ConnectionInfo {
  ConnectionInfo();
  ~ConnectionInfo();
  ConnectionInfo(ConnectionInfo&& rhs);
  ConnectionInfo& operator=(ConnectionInfo&& rhs);

  // Populates a ConnectionInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ConnectionInfo* out);

  // Creates a ConnectionInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ConnectionInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ConnectionInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The id of the serial port connection.
  int connection_id;

  // Flag indicating whether the connection is blocked from firing onReceive
  // events.
  bool paused;

  // See <code>ConnectionOptions.persistent</code>
  bool persistent;

  // See <code>ConnectionOptions.name</code>
  std::string name;

  // See <code>ConnectionOptions.bufferSize</code>
  int buffer_size;

  // See <code>ConnectionOptions.receiveTimeout</code>
  int receive_timeout;

  // See <code>ConnectionOptions.sendTimeout</code>
  int send_timeout;

  // See <code>ConnectionOptions.bitrate</code>. This field may be omitted or
  // inaccurate if a non-standard bitrate is in use, or if an error occurred while
  // querying the underlying device.
  std::unique_ptr<int> bitrate;

  // See <code>ConnectionOptions.dataBits</code>. This field may be omitted if an
  // error occurred while querying the underlying device.
  DataBits data_bits;

  // See <code>ConnectionOptions.parityBit</code>. This field may be omitted if an
  // error occurred while querying the underlying device.
  ParityBit parity_bit;

  // See <code>ConnectionOptions.stopBits</code>. This field may be omitted if an
  // error occurred while querying the underlying device.
  StopBits stop_bits;

  // See <code>ConnectionOptions.ctsFlowControl</code>. This field may be omitted
  // if an error occurred while querying the underlying device.
  std::unique_ptr<bool> cts_flow_control;


 private:
  DISALLOW_COPY_AND_ASSIGN(ConnectionInfo);
};

enum SendError {
  SEND_ERROR_NONE,
  SEND_ERROR_DISCONNECTED,
  SEND_ERROR_PENDING,
  SEND_ERROR_TIMEOUT,
  SEND_ERROR_SYSTEM_ERROR,
  SEND_ERROR_LAST = SEND_ERROR_SYSTEM_ERROR,
};


const char* ToString(SendError as_enum);
SendError ParseSendError(const std::string& as_string);

struct SendInfo {
  SendInfo();
  ~SendInfo();
  SendInfo(SendInfo&& rhs);
  SendInfo& operator=(SendInfo&& rhs);

  // Populates a SendInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, SendInfo* out);

  // Creates a SendInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<SendInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SendInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The number of bytes sent.
  int bytes_sent;

  // An error code if an error occurred.
  SendError error;


 private:
  DISALLOW_COPY_AND_ASSIGN(SendInfo);
};

struct HostControlSignals {
  HostControlSignals();
  ~HostControlSignals();
  HostControlSignals(HostControlSignals&& rhs);
  HostControlSignals& operator=(HostControlSignals&& rhs);

  // Populates a HostControlSignals object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, HostControlSignals* out);

  // Creates a HostControlSignals object from a base::Value, or NULL on failure.
  static std::unique_ptr<HostControlSignals> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HostControlSignals object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // DTR (Data Terminal Ready).
  std::unique_ptr<bool> dtr;

  // RTS (Request To Send).
  std::unique_ptr<bool> rts;


 private:
  DISALLOW_COPY_AND_ASSIGN(HostControlSignals);
};

struct DeviceControlSignals {
  DeviceControlSignals();
  ~DeviceControlSignals();
  DeviceControlSignals(DeviceControlSignals&& rhs);
  DeviceControlSignals& operator=(DeviceControlSignals&& rhs);

  // Populates a DeviceControlSignals object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DeviceControlSignals* out);

  // Creates a DeviceControlSignals object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<DeviceControlSignals> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DeviceControlSignals object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // DCD (Data Carrier Detect) or RLSD (Receive Line Signal/ Detect).
  bool dcd;

  // CTS (Clear To Send).
  bool cts;

  // RI (Ring Indicator).
  bool ri;

  // DSR (Data Set Ready).
  bool dsr;


 private:
  DISALLOW_COPY_AND_ASSIGN(DeviceControlSignals);
};

struct ReceiveInfo {
  ReceiveInfo();
  ~ReceiveInfo();
  ReceiveInfo(ReceiveInfo&& rhs);
  ReceiveInfo& operator=(ReceiveInfo&& rhs);

  // Populates a ReceiveInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ReceiveInfo* out);

  // Creates a ReceiveInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ReceiveInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReceiveInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The connection identifier.
  int connection_id;

  // The data received.
  std::vector<uint8_t> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReceiveInfo);
};

enum ReceiveError {
  RECEIVE_ERROR_NONE,
  RECEIVE_ERROR_DISCONNECTED,
  RECEIVE_ERROR_TIMEOUT,
  RECEIVE_ERROR_DEVICE_LOST,
  RECEIVE_ERROR_BREAK,
  RECEIVE_ERROR_FRAME_ERROR,
  RECEIVE_ERROR_OVERRUN,
  RECEIVE_ERROR_BUFFER_OVERFLOW,
  RECEIVE_ERROR_PARITY_ERROR,
  RECEIVE_ERROR_SYSTEM_ERROR,
  RECEIVE_ERROR_LAST = RECEIVE_ERROR_SYSTEM_ERROR,
};


const char* ToString(ReceiveError as_enum);
ReceiveError ParseReceiveError(const std::string& as_string);

struct ReceiveErrorInfo {
  ReceiveErrorInfo();
  ~ReceiveErrorInfo();
  ReceiveErrorInfo(ReceiveErrorInfo&& rhs);
  ReceiveErrorInfo& operator=(ReceiveErrorInfo&& rhs);

  // Populates a ReceiveErrorInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ReceiveErrorInfo* out);

  // Creates a ReceiveErrorInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ReceiveErrorInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReceiveErrorInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The connection identifier.
  int connection_id;

  // An error code indicating what went wrong.
  ReceiveError error;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReceiveErrorInfo);
};


//
// Functions
//

namespace GetDevices {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<DeviceInfo>& ports);
}  // namespace Results

}  // namespace GetDevices

namespace Connect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The system path of the serial port to open.
  std::string path;

  // Port configuration options.
  std::unique_ptr<ConnectionOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ConnectionInfo& connection_info);
}  // namespace Results

}  // namespace Connect

namespace Update {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the opened connection.
  int connection_id;

  // Port configuration options.
  ConnectionOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace Update

namespace Disconnect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the opened connection.
  int connection_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace Disconnect

namespace SetPaused {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the opened connection.
  int connection_id;

  // Flag to indicate whether to pause or unpause.
  bool paused;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetPaused

namespace GetInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the opened connection.
  int connection_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ConnectionInfo& connection_info);
}  // namespace Results

}  // namespace GetInfo

namespace GetConnections {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ConnectionInfo>& connection_infos);
}  // namespace Results

}  // namespace GetConnections

namespace Send {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the connection.
  int connection_id;

  // The data to send.
  std::vector<uint8_t> data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const SendInfo& send_info);
}  // namespace Results

}  // namespace Send

namespace Flush {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int connection_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace Flush

namespace GetControlSignals {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the connection.
  int connection_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const DeviceControlSignals& signals);
}  // namespace Results

}  // namespace GetControlSignals

namespace SetControlSignals {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the connection.
  int connection_id;

  // The set of signal changes to send to the device.
  HostControlSignals signals;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace SetControlSignals

namespace SetBreak {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the connection.
  int connection_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace SetBreak

namespace ClearBreak {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the connection.
  int connection_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace ClearBreak

//
// Events
//

namespace OnReceive {

extern const char kEventName[];  // "serial.onReceive"

// Event data.
std::unique_ptr<base::ListValue> Create(const ReceiveInfo& info);
}  // namespace OnReceive

namespace OnReceiveError {

extern const char kEventName[];  // "serial.onReceiveError"

std::unique_ptr<base::ListValue> Create(const ReceiveErrorInfo& info);
}  // namespace OnReceiveError

}  // namespace serial
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SERIAL_H__
