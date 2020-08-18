// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/socket.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SOCKET_H__
#define EXTENSIONS_COMMON_API_SOCKET_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace socket {

//
// Types
//

enum SocketType {
  SOCKET_TYPE_NONE,
  SOCKET_TYPE_TCP,
  SOCKET_TYPE_UDP,
  SOCKET_TYPE_LAST = SOCKET_TYPE_UDP,
};


const char* ToString(SocketType as_enum);
SocketType ParseSocketType(const std::string& as_string);

struct CreateOptions {
  CreateOptions();
  ~CreateOptions();
  CreateOptions(CreateOptions&& rhs);
  CreateOptions& operator=(CreateOptions&& rhs);

  // Populates a CreateOptions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, CreateOptions* out);

  // Creates a CreateOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<CreateOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CreateOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;


 private:
  DISALLOW_COPY_AND_ASSIGN(CreateOptions);
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

  // The id of the newly created socket.
  int socket_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(CreateInfo);
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

  int result_code;

  // The id of the accepted socket.
  std::unique_ptr<int> socket_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(AcceptInfo);
};

struct ReadInfo {
  ReadInfo();
  ~ReadInfo();
  ReadInfo(ReadInfo&& rhs);
  ReadInfo& operator=(ReadInfo&& rhs);

  // Populates a ReadInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ReadInfo* out);

  // Creates a ReadInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ReadInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReadInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The resultCode returned from the underlying read() call.
  int result_code;

  std::vector<uint8_t> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReadInfo);
};

struct WriteInfo {
  WriteInfo();
  ~WriteInfo();
  WriteInfo(WriteInfo&& rhs);
  WriteInfo& operator=(WriteInfo&& rhs);

  // Populates a WriteInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, WriteInfo* out);

  // Creates a WriteInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<WriteInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this WriteInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The number of bytes sent, or a negative error code.
  int bytes_written;


 private:
  DISALLOW_COPY_AND_ASSIGN(WriteInfo);
};

struct RecvFromInfo {
  RecvFromInfo();
  ~RecvFromInfo();
  RecvFromInfo(RecvFromInfo&& rhs);
  RecvFromInfo& operator=(RecvFromInfo&& rhs);

  // Populates a RecvFromInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RecvFromInfo* out);

  // Creates a RecvFromInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<RecvFromInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RecvFromInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The resultCode returned from the underlying recvfrom() call.
  int result_code;

  std::vector<uint8_t> data;

  // The address of the remote machine.
  std::string address;

  int port;


 private:
  DISALLOW_COPY_AND_ASSIGN(RecvFromInfo);
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

  // The type of the passed socket. This will be <code>tcp</code> or
  // <code>udp</code>.
  SocketType socket_type;

  // <p>Whether or not the underlying socket is connected.</p><p>For
  // <code>tcp</code> sockets, this will remain true even if the remote peer has
  // disconnected. Reading or writing to the socket may then result in an error,
  // hinting that this socket should be disconnected via
  // <code>disconnect()</code>.</p><p>For <code>udp</code> sockets, this just
  // represents whether a default remote address has been specified for reading
  // and writing packets.</p>
  bool connected;

  // If the underlying socket is connected, contains the IPv4/6 address of the
  // peer.
  std::unique_ptr<std::string> peer_address;

  // If the underlying socket is connected, contains the port of the connected
  // peer.
  std::unique_ptr<int> peer_port;

  // If the underlying socket is bound or connected, contains its local IPv4/6
  // address.
  std::unique_ptr<std::string> local_address;

  // If the underlying socket is bound or connected, contains its local port.
  std::unique_ptr<int> local_port;


 private:
  DISALLOW_COPY_AND_ASSIGN(SocketInfo);
};

struct NetworkInterface {
  NetworkInterface();
  ~NetworkInterface();
  NetworkInterface(NetworkInterface&& rhs);
  NetworkInterface& operator=(NetworkInterface&& rhs);

  // Populates a NetworkInterface object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, NetworkInterface* out);

  // Creates a NetworkInterface object from a base::Value, or NULL on failure.
  static std::unique_ptr<NetworkInterface> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this NetworkInterface object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The underlying name of the adapter. On *nix, this will typically be "eth0",
  // "lo", etc.
  std::string name;

  // The available IPv4/6 address.
  std::string address;

  // The prefix length
  int prefix_length;


 private:
  DISALLOW_COPY_AND_ASSIGN(NetworkInterface);
};

struct TLSVersionConstraints {
  TLSVersionConstraints();
  ~TLSVersionConstraints();
  TLSVersionConstraints(TLSVersionConstraints&& rhs);
  TLSVersionConstraints& operator=(TLSVersionConstraints&& rhs);

  // Populates a TLSVersionConstraints object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, TLSVersionConstraints* out);

  // Creates a TLSVersionConstraints object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<TLSVersionConstraints> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TLSVersionConstraints object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The minimum and maximum acceptable versions of TLS. These will be
  // <code>tls1</code>, <code>tls1.1</code>, <code>tls1.2</code>, or
  // <code>tls1.3</code>.
  std::unique_ptr<std::string> min;

  std::unique_ptr<std::string> max;


 private:
  DISALLOW_COPY_AND_ASSIGN(TLSVersionConstraints);
};

struct SecureOptions {
  SecureOptions();
  ~SecureOptions();
  SecureOptions(SecureOptions&& rhs);
  SecureOptions& operator=(SecureOptions&& rhs);

  // Populates a SecureOptions object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, SecureOptions* out);

  // Creates a SecureOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<SecureOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SecureOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<TLSVersionConstraints> tls_version;


 private:
  DISALLOW_COPY_AND_ASSIGN(SecureOptions);
};


//
// Functions
//

namespace Create {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The type of socket to create. Must be <code>tcp</code> or <code>udp</code>.
  SocketType type;

  // The socket options.
  std::unique_ptr<CreateOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const CreateInfo& create_info);
}  // namespace Results

}  // namespace Create

namespace Destroy {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Destroy

namespace Connect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The hostname or IP address of the remote machine.
  std::string hostname;

  // The port of the remote machine.
  int port;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace Connect

namespace Bind {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The address of the local machine.
  std::string address;

  // The port of the local machine.
  int port;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace Bind

namespace Disconnect {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Disconnect

namespace Read {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The read buffer size.
  std::unique_ptr<int> buffer_size;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ReadInfo& read_info);
}  // namespace Results

}  // namespace Read

namespace Write {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The data to write.
  std::vector<uint8_t> data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const WriteInfo& write_info);
}  // namespace Results

}  // namespace Write

namespace RecvFrom {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The receive buffer size.
  std::unique_ptr<int> buffer_size;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const RecvFromInfo& recv_from_info);
}  // namespace Results

}  // namespace RecvFrom

namespace SendTo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The data to write.
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

std::unique_ptr<base::ListValue> Create(const WriteInfo& write_info);
}  // namespace Results

}  // namespace SendTo

namespace Listen {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The address of the local machine.
  std::string address;

  // The port of the local machine.
  int port;

  // Length of the socket's listen queue.
  std::unique_ptr<int> backlog;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace Listen

namespace Accept {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const AcceptInfo& accept_info);
}  // namespace Results

}  // namespace Accept

namespace SetKeepAlive {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // If true, enable keep-alive functionality.
  bool enable;

  // Set the delay seconds between the last data packet received and the first
  // keepalive probe. Default is 0.
  std::unique_ptr<int> delay;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace SetKeepAlive

namespace SetNoDelay {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // If true, disables Nagle's algorithm.
  bool no_delay;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool result);
}  // namespace Results

}  // namespace SetNoDelay

namespace GetInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const SocketInfo& result);
}  // namespace Results

}  // namespace GetInfo

namespace GetNetworkList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<NetworkInterface>& result);
}  // namespace Results

}  // namespace GetNetworkList

namespace JoinGroup {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The group address to join. Domain names are not supported.
  std::string address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace JoinGroup

namespace LeaveGroup {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The group address to leave. Domain names are not supported.
  std::string address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace LeaveGroup

namespace SetMulticastTimeToLive {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // The time-to-live value.
  int ttl;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace SetMulticastTimeToLive

namespace SetMulticastLoopbackMode {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;

  // Indicate whether to enable loopback mode.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace SetMulticastLoopbackMode

namespace GetJoinedGroups {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The socketId.
  int socket_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& groups);
}  // namespace Results

}  // namespace GetJoinedGroups

namespace Secure {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The connected socket to use.
  int socket_id;

  // Constraints and parameters for the TLS connection.
  std::unique_ptr<SecureOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int result);
}  // namespace Results

}  // namespace Secure

}  // namespace socket
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SOCKET_H__
