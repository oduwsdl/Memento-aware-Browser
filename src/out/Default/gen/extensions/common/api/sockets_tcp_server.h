// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/sockets_tcp_server.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SOCKETS_TCP_SERVER_H__
#define EXTENSIONS_COMMON_API_SOCKETS_TCP_SERVER_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace sockets_tcp_server {

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

  // Flag indicating if the socket remains open when the event page of the
  // application is unloaded (see <a
  // href="http://developer.chrome.com/apps/app_lifecycle.html">Manage App
  // Lifecycle</a>). The default value is "false." When the application is loaded,
  // any sockets previously opened with persistent=true can be fetched with
  // <code>getSockets</code>.
  std::unique_ptr<bool> persistent;

  // An application-defined string associated with the socket.
  std::unique_ptr<std::string> name;


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

  // The ID of the newly created server socket. Note that socket IDs created from
  // this API are not compatible with socket IDs created from other APIs, such as
  // the deprecated <code>$(ref:socket)</code> API.
  int socket_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(CreateInfo);
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

  // Flag indicating whether connection requests on a listening socket are
  // dispatched through the <code>onAccept</code> event or queued up in the listen
  // queue backlog. See <code>setPaused</code>. The default value is "false".
  bool paused;

  // If the socket is listening, contains its local IPv4/6 address.
  std::unique_ptr<std::string> local_address;

  // If the socket is listening, contains its local port.
  std::unique_ptr<int> local_port;


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
  // functions from the <code>chrome.sockets.tcp</code> namespace. Note the client
  // socket is initially paused and must be explictly un-paused by the application
  // to start receiving data.
  int client_socket_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(AcceptInfo);
};

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

  // The result code returned from the underlying network call.
  int result_code;


 private:
  DISALLOW_COPY_AND_ASSIGN(AcceptErrorInfo);
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

namespace Listen {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socket identifier.
  int socket_id;

  // The address of the local machine.
  std::string address;

  // The port of the local machine. When set to <code>0</code>, a free port is
  // chosen dynamically. The dynamically allocated port can be found by calling
  // <code>getInfo</code>.
  int port;

  // Length of the socket's listen queue. The default value depends on the
  // Operating System (SOMAXCONN), which ensures a reasonable queue length for
  // most applications.
  std::unique_ptr<int> backlog;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The result code returned from the underlying network call. A negative value
// indicates an error.
std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace Listen

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

// Array of object containing socket information.
std::unique_ptr<base::ListValue> Create(const std::vector<SocketInfo>& socket_infos);
}  // namespace Results

}  // namespace GetSockets

//
// Events
//

namespace OnAccept {

extern const char kEventName[];  // "sockets.tcpServer.onAccept"

// The event data.
std::unique_ptr<base::ListValue> Create(const AcceptInfo& info);
}  // namespace OnAccept

namespace OnAcceptError {

extern const char kEventName[];  // "sockets.tcpServer.onAcceptError"

// The event data.
std::unique_ptr<base::ListValue> Create(const AcceptErrorInfo& info);
}  // namespace OnAcceptError

}  // namespace sockets_tcp_server
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SOCKETS_TCP_SERVER_H__
