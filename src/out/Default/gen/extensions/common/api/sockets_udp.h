// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/sockets_udp.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SOCKETS_UDP_H__
#define EXTENSIONS_COMMON_API_SOCKETS_UDP_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace sockets_udp {

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

  // Flag indicating if the socket is left open when the event page of the
  // application is unloaded (see <a
  // href="http://developer.chrome.com/apps/app_lifecycle.html">Manage App
  // Lifecycle</a>). The default value is "false." When the application is loaded,
  // any sockets previously opened with persistent=true can be fetched with
  // <code>getSockets</code>.
  std::unique_ptr<bool> persistent;

  // An application-defined string associated with the socket.
  std::unique_ptr<std::string> name;

  // The size of the buffer used to receive data. If the buffer is too small to
  // receive the UDP packet, data is lost. The default value is 4096.
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
  // deprecated <code>$(ref:socket)</code> API.
  int socket_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(CreateInfo);
};

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

  // The result code returned from the underlying network call. A negative value
  // indicates an error.
  int result_code;

  // The number of bytes sent (if result == 0)
  std::unique_ptr<int> bytes_sent;


 private:
  DISALLOW_COPY_AND_ASSIGN(SendInfo);
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

  // Flag indicating whether the socket is left open when the application is
  // suspended (see <code>SocketProperties.persistent</code>).
  bool persistent;

  // Application-defined string associated with the socket.
  std::unique_ptr<std::string> name;

  // The size of the buffer used to receive data. If no buffer size has been
  // specified explictly, the value is not provided.
  std::unique_ptr<int> buffer_size;

  // Flag indicating whether the socket is blocked from firing onReceive events.
  bool paused;

  // If the underlying socket is bound, contains its local IPv4/6 address.
  std::unique_ptr<std::string> local_address;

  // If the underlying socket is bound, contains its local port.
  std::unique_ptr<int> local_port;


 private:
  DISALLOW_COPY_AND_ASSIGN(SocketInfo);
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

  // The socket ID.
  int socket_id;

  // The UDP packet content (truncated to the current buffer size).
  std::vector<uint8_t> data;

  // The address of the host the packet comes from.
  std::string remote_address;

  // The port of the host the packet comes from.
  int remote_port;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReceiveInfo);
};

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

  // The socket ID.
  int socket_id;

  // The result code returned from the underlying recvfrom() call.
  int result_code;


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

  // The socket ID.
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

namespace Bind {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;

  // The address of the local machine. DNS name, IPv4 and IPv6 formats are
  // supported. Use "0.0.0.0" to accept packets from all local available network
  // interfaces.
  std::string address;

  // The port of the local machine. Use "0" to bind to a free port.
  int port;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result code returned from the underlying network call. A negative value
// indicates an error.
std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace Bind

namespace Send {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;

  // The data to send.
  std::vector<uint8_t> data;

  // The address of the remote machine.
  std::string address;

  // The port of the remote machine.
  int port;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Result of the <code>send</code> method.
std::unique_ptr<base::ListValue> Create(const SendInfo& send_info);
}  // namespace Results

}  // namespace Send

namespace Close {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Close

namespace GetInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
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

// Array of object containing socket information.
std::unique_ptr<base::ListValue> Create(const std::vector<SocketInfo>& socket_infos);
}  // namespace Results

}  // namespace GetSockets

namespace JoinGroup {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;

  // The group address to join. Domain names are not supported.
  std::string address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result code returned from the underlying network call. A negative value
// indicates an error.
std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace JoinGroup

namespace LeaveGroup {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;

  // The group address to leave. Domain names are not supported.
  std::string address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result code returned from the underlying network call. A negative value
// indicates an error.
std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace LeaveGroup

namespace SetMulticastTimeToLive {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;

  // The time-to-live value.
  int ttl;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result code returned from the underlying network call. A negative value
// indicates an error.
std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace SetMulticastTimeToLive

namespace SetMulticastLoopbackMode {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;

  // Indicate whether to enable loopback mode.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result code returned from the underlying network call. A negative value
// indicates an error.
std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace SetMulticastLoopbackMode

namespace GetJoinedGroups {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Array of groups the socket joined.
std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& groups);
}  // namespace Results

}  // namespace GetJoinedGroups

namespace SetBroadcast {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket ID.
  int socket_id;

  // <code>true</code> to enable broadcast packets, <code>false</code> to disable
  // them.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result code returned from the underlying network call.
std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace SetBroadcast

//
// Events
//

namespace OnReceive {

extern const char kEventName[];  // "sockets.udp.onReceive"

// The event data.
std::unique_ptr<base::ListValue> Create(const ReceiveInfo& info);
}  // namespace OnReceive

namespace OnReceiveError {

extern const char kEventName[];  // "sockets.udp.onReceiveError"

// The event data.
std::unique_ptr<base::ListValue> Create(const ReceiveErrorInfo& info);
}  // namespace OnReceiveError

}  // namespace sockets_udp
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SOCKETS_UDP_H__
