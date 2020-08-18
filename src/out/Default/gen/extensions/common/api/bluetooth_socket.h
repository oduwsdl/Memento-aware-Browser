// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/bluetooth_socket.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_BLUETOOTH_SOCKET_H__
#define EXTENSIONS_COMMON_API_BLUETOOTH_SOCKET_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace bluetooth_socket {

//
// Types
//

struct SocketProperties {
  SocketProperties();
  ~SocketProperties();
  SocketProperties(SocketProperties&& rhs);
  SocketProperties& operator=(SocketProperties&& rhs);

  // Populates a SocketProperties object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, SocketProperties* out);

  // Creates a SocketProperties object from a base::Value, or NULL on failure.
  static std::unique_ptr<SocketProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SocketProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Flag indicating whether the socket is left open when the event page of the
  // application is unloaded (see <a
  // href="http://developer.chrome.com/apps/app_lifecycle.html">Manage App
  // Lifecycle</a>). The default value is <code>false.</code> When the application
  // is loaded, any sockets previously opened with persistent=true can be fetched
  // with $ref:getSockets.
  std::unique_ptr<bool> persistent;

  // An application-defined string associated with the socket.
  std::unique_ptr<std::string> name;

  // The size of the buffer used to receive data. The default value is 4096.
  std::unique_ptr<int> buffer_size;


 private:
  DISALLOW_COPY_AND_ASSIGN(SocketProperties);
};

struct CreateInfo {
  CreateInfo();
  ~CreateInfo();
  CreateInfo(CreateInfo&& rhs);
  CreateInfo& operator=(CreateInfo&& rhs);

  // Populates a CreateInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, CreateInfo* out);

  // Creates a CreateInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<CreateInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CreateInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the newly created socket. Note that socket IDs created from this
  // API are not compatible with socket IDs created from other APIs, such as the
  // <code>$(ref:sockets.tcp)</code> API.
  int socket_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(CreateInfo);
};

struct ListenOptions {
  ListenOptions();
  ~ListenOptions();
  ListenOptions(ListenOptions&& rhs);
  ListenOptions& operator=(ListenOptions&& rhs);

  // Populates a ListenOptions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ListenOptions* out);

  // Creates a ListenOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<ListenOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ListenOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The RFCOMM Channel used by <code>listenUsingRfcomm</code>. If specified, this
  // channel must not be previously in use or the method call will fail. When not
  // specified, an unused channel will be automatically allocated.
  std::unique_ptr<int> channel;

  // The L2CAP PSM used by <code>listenUsingL2cap</code>. If specified, this PSM
  // must not be previously in use or the method call with fail. When not
  // specified, an unused PSM will be automatically allocated.
  std::unique_ptr<int> psm;

  // Length of the socket's listen queue. The default value depends on the
  // operating system's host subsystem.
  std::unique_ptr<int> backlog;


 private:
  DISALLOW_COPY_AND_ASSIGN(ListenOptions);
};

struct SocketInfo {
  SocketInfo();
  ~SocketInfo();
  SocketInfo(SocketInfo&& rhs);
  SocketInfo& operator=(SocketInfo&& rhs);

  // Populates a SocketInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, SocketInfo* out);

  // Creates a SocketInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<SocketInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SocketInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The socket identifier.
  int socket_id;

  // Flag indicating if the socket remains open when the event page of the
  // application is unloaded (see <code>SocketProperties.persistent</code>). The
  // default value is "false".
  bool persistent;

  // Application-defined string associated with the socket.
  std::unique_ptr<std::string> name;

  // The size of the buffer used to receive data. If no buffer size has been
  // specified explictly, the value is not provided.
  std::unique_ptr<int> buffer_size;

  // Flag indicating whether a connected socket blocks its peer from sending more
  // data, or whether connection requests on a listening socket are dispatched
  // through the <code>onAccept</code> event or queued up in the listen queue
  // backlog. See <code>setPaused</code>. The default value is "false".
  bool paused;

  // Flag indicating whether the socket is connected to a remote peer.
  bool connected;

  // If the underlying socket is connected, contains the Bluetooth address of the
  // device it is connected to.
  std::unique_ptr<std::string> address;

  // If the underlying socket is connected, contains information about the service
  // UUID it is connected to, otherwise if the underlying socket is listening,
  // contains information about the service UUID it is listening on.
  std::unique_ptr<std::string> uuid;


 private:
  DISALLOW_COPY_AND_ASSIGN(SocketInfo);
};

struct AcceptInfo {
  AcceptInfo();
  ~AcceptInfo();
  AcceptInfo(AcceptInfo&& rhs);
  AcceptInfo& operator=(AcceptInfo&& rhs);

  // Populates a AcceptInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, AcceptInfo* out);

  // Creates a AcceptInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<AcceptInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AcceptInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The server socket identifier.
  int socket_id;

  // The client socket identifier, i.e. the socket identifier of the newly
  // established connection. This socket identifier should be used only with
  // functions from the <code>chrome.bluetoothSocket</code> namespace. Note the
  // client socket is initially paused and must be explictly un-paused by the
  // application to start receiving data.
  int client_socket_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(AcceptInfo);
};

enum AcceptError {
  ACCEPT_ERROR_NONE,
  ACCEPT_ERROR_SYSTEM_ERROR,
  ACCEPT_ERROR_NOT_LISTENING,
  ACCEPT_ERROR_LAST = ACCEPT_ERROR_NOT_LISTENING,
};


const char* ToString(AcceptError as_enum);
AcceptError ParseAcceptError(const std::string& as_string);

struct AcceptErrorInfo {
  AcceptErrorInfo();
  ~AcceptErrorInfo();
  AcceptErrorInfo(AcceptErrorInfo&& rhs);
  AcceptErrorInfo& operator=(AcceptErrorInfo&& rhs);

  // Populates a AcceptErrorInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, AcceptErrorInfo* out);

  // Creates a AcceptErrorInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<AcceptErrorInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AcceptErrorInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The server socket identifier.
  int socket_id;

  // The error message.
  std::string error_message;

  // An error code indicating what went wrong.
  AcceptError error;


 private:
  DISALLOW_COPY_AND_ASSIGN(AcceptErrorInfo);
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

  // The socket identifier.
  int socket_id;

  // The data received, with a maxium size of <code>bufferSize</code>.
  std::vector<uint8_t> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReceiveInfo);
};

enum ReceiveError {
  RECEIVE_ERROR_NONE,
  RECEIVE_ERROR_DISCONNECTED,
  RECEIVE_ERROR_SYSTEM_ERROR,
  RECEIVE_ERROR_NOT_CONNECTED,
  RECEIVE_ERROR_LAST = RECEIVE_ERROR_NOT_CONNECTED,
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

  // The socket identifier.
  int socket_id;

  // The error message.
  std::string error_message;

  // An error code indicating what went wrong.
  ReceiveError error;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReceiveErrorInfo);
};


//
// Functions
//

namespace Create {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket properties (optional).
  std::unique_ptr<SocketProperties> properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result of the socket creation.
std::unique_ptr<base::ListValue> Create(const CreateInfo& create_info);
}  // namespace Results

}  // namespace Create

namespace Update {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;

  // The properties to update.
  SocketProperties properties;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Update

namespace SetPaused {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int socket_id;

  bool paused;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetPaused

namespace ListenUsingRfcomm {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;

  // Service UUID to listen on.
  std::string uuid;

  // Optional additional options for the service.
  std::unique_ptr<ListenOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ListenUsingRfcomm

namespace ListenUsingL2cap {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;

  // Service UUID to listen on.
  std::string uuid;

  // Optional additional options for the service.
  std::unique_ptr<ListenOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ListenUsingL2cap

namespace Connect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;

  // The address of the Bluetooth device.
  std::string address;

  // The UUID of the service to connect to.
  std::string uuid;


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

  // The socket identifier.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Disconnect

namespace Close {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Close

namespace Send {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;

  // The data to send.
  std::vector<uint8_t> data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The number of bytes sent.
std::unique_ptr<base::ListValue> Create(int bytes_sent);
}  // namespace Results

}  // namespace Send

namespace GetInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Object containing the socket information.
std::unique_ptr<base::ListValue> Create(const SocketInfo& socket_info);
}  // namespace Results

}  // namespace GetInfo

namespace GetSockets {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<SocketInfo>& sockets);
}  // namespace Results

}  // namespace GetSockets

//
// Events
//

namespace OnAccept {

extern const char kEventName[];  // "bluetoothSocket.onAccept"

// The event data.
std::unique_ptr<base::ListValue> Create(const AcceptInfo& info);
}  // namespace OnAccept

namespace OnAcceptError {

extern const char kEventName[];  // "bluetoothSocket.onAcceptError"

// The event data.
std::unique_ptr<base::ListValue> Create(const AcceptErrorInfo& info);
}  // namespace OnAcceptError

namespace OnReceive {

extern const char kEventName[];  // "bluetoothSocket.onReceive"

// The event data.
std::unique_ptr<base::ListValue> Create(const ReceiveInfo& info);
}  // namespace OnReceive

namespace OnReceiveError {

extern const char kEventName[];  // "bluetoothSocket.onReceiveError"

// The event data.
std::unique_ptr<base::ListValue> Create(const ReceiveErrorInfo& info);
}  // namespace OnReceiveError

}  // namespace bluetooth_socket
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_BLUETOOTH_SOCKET_H__
