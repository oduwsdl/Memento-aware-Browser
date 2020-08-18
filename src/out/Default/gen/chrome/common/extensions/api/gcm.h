// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/gcm.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_GCM_H__
#define CHROME_COMMON_EXTENSIONS_API_GCM_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace gcm {

//
// Properties
//

// The maximum size (in bytes) of all key/value pairs in a message.
extern const int MAX_MESSAGE_SIZE;

//
// Functions
//

namespace Register {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A list of server IDs that are allowed to send messages to the application. It
  // should contain at least one and no more than 100 sender IDs.
  std::vector<std::string> sender_ids;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// A registration ID assigned to the application by the GCM.
std::unique_ptr<base::ListValue> Create(const std::string& registration_id);
}  // namespace Results

}  // namespace Register

namespace Unregister {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Unregister

namespace Send {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A message to send to the other party via GCM.
  struct Message {
    Message();
    ~Message();
    Message(Message&& rhs);
    Message& operator=(Message&& rhs);

    // Populates a Message object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Message* out);

    // Message data to send to the server. Case-insensitive <code>goog.</code> and
    // <code>google</code>, as well as case-sensitive <code>collapse_key</code> are
    // disallowed as key prefixes. Sum of all key/value pairs should not exceed
    // $(ref:gcm.MAX_MESSAGE_SIZE).
    struct Data {
      Data();
      ~Data();
      Data(Data&& rhs);
      Data& operator=(Data&& rhs);

      // Populates a Data object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, Data* out);

      std::map<std::string, std::string> additional_properties;

     private:
      DISALLOW_COPY_AND_ASSIGN(Data);
    };


    // The ID of the server to send the message to as assigned by <a
    // href='https://code.google.com/apis/console'>Google API Console</a>.
    std::string destination_id;

    // The ID of the message. It must be unique for each message in scope of the
    // applications. See the <a href='cloudMessaging#send_messages'>Cloud Messaging
    // documentation</a> for advice for picking and handling an ID.
    std::string message_id;

    // Time-to-live of the message in seconds. If it is not possible to send the
    // message within that time, an onSendError event will be raised. A time-to-live
    // of 0 indicates that the message should be sent immediately or fail if it's
    // not possible. The maximum and a default value of time-to-live is 86400
    // seconds (1 day).
    std::unique_ptr<int> time_to_live;

    // Message data to send to the server. Case-insensitive <code>goog.</code> and
    // <code>google</code>, as well as case-sensitive <code>collapse_key</code> are
    // disallowed as key prefixes. Sum of all key/value pairs should not exceed
    // $(ref:gcm.MAX_MESSAGE_SIZE).
    Data data;


   private:
    DISALLOW_COPY_AND_ASSIGN(Message);
  };


  // A message to send to the other party via GCM.
  Message message;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// The ID of the message that the callback was issued for.
std::unique_ptr<base::ListValue> Create(const std::string& message_id);
}  // namespace Results

}  // namespace Send

//
// Events
//

namespace OnMessage {

extern const char kEventName[];  // "gcm.onMessage"

// A message received from another party via GCM.
struct Message {
  Message();
  ~Message();
  Message(Message&& rhs);
  Message& operator=(Message&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Message object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The message data.
  struct Data {
    Data();
    ~Data();
    Data(Data&& rhs);
    Data& operator=(Data&& rhs);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Data object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    std::map<std::string, std::string> additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Data);
  };


  // The message data.
  Data data;

  // The sender who issued the message.
  std::unique_ptr<std::string> from;

  // The collapse key of a message. See <a
  // href='cloudMessaging#collapsible_messages'>Collapsible Messages</a> section
  // of Cloud Messaging documentation for details.
  std::unique_ptr<std::string> collapse_key;


 private:
  DISALLOW_COPY_AND_ASSIGN(Message);
};


// A message received from another party via GCM.
std::unique_ptr<base::ListValue> Create(const Message& message);
}  // namespace OnMessage

namespace OnMessagesDeleted {

extern const char kEventName[];  // "gcm.onMessagesDeleted"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnMessagesDeleted

namespace OnSendError {

extern const char kEventName[];  // "gcm.onSendError"

// An error that occured while trying to send the message either in Chrome or on
// the GCM server. Application can retry sending the message with a reasonable
// backoff and possibly longer time-to-live.
struct Error {
  Error();
  ~Error();
  Error(Error&& rhs);
  Error& operator=(Error&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Error object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Additional details related to the error, when available.
  struct Details {
    Details();
    ~Details();
    Details(Details&& rhs);
    Details& operator=(Details&& rhs);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Details object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    std::map<std::string, std::string> additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Details);
  };


  // The error message describing the problem.
  std::string error_message;

  // The ID of the message with this error, if error is related to a specific
  // message.
  std::unique_ptr<std::string> message_id;

  // Additional details related to the error, when available.
  Details details;


 private:
  DISALLOW_COPY_AND_ASSIGN(Error);
};


// An error that occured while trying to send the message either in Chrome or on
// the GCM server. Application can retry sending the message with a reasonable
// backoff and possibly longer time-to-live.
std::unique_ptr<base::ListValue> Create(const Error& error);
}  // namespace OnSendError

}  // namespace gcm
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_GCM_H__
