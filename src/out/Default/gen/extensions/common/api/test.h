// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/test.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_TEST_H__
#define EXTENSIONS_COMMON_API_TEST_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace test {

//
// Functions
//

namespace GetConfig {

namespace Results {

struct TestConfig {
  TestConfig();
  ~TestConfig();
  TestConfig(TestConfig&& rhs);
  TestConfig& operator=(TestConfig&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TestConfig object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Details on the FTP server used to mock network responses.  Will be set only
  // if test calls ExtensionApiTest::StartFTPServer().
  struct FtpServer {
    FtpServer();
    ~FtpServer();
    FtpServer(FtpServer&& rhs);
    FtpServer& operator=(FtpServer&& rhs);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this FtpServer object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // The port on which the FTP server is listening.
    int port;


   private:
    DISALLOW_COPY_AND_ASSIGN(FtpServer);
  };

  // Details on the test server used to mock network responses.  Will be set only
  // if test calls ExtensionApiTest::StartEmbeddedTestServer().
  struct TestServer {
    TestServer();
    ~TestServer();
    TestServer(TestServer&& rhs);
    TestServer& operator=(TestServer&& rhs);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this TestServer object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // The port on which the test server is listening.
    int port;


   private:
    DISALLOW_COPY_AND_ASSIGN(TestServer);
  };

  // Login status.
  struct LoginStatus {
    LoginStatus();
    ~LoginStatus();
    LoginStatus(LoginStatus&& rhs);
    LoginStatus& operator=(LoginStatus&& rhs);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this LoginStatus object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // Whether there's a logged-in user.
    std::unique_ptr<bool> is_logged_in;

    // Whether the screen is locked.
    std::unique_ptr<bool> is_screen_locked;


   private:
    DISALLOW_COPY_AND_ASSIGN(LoginStatus);
  };


  // Additional string argument to pass to test.
  std::unique_ptr<std::string> custom_arg;

  // Details on the FTP server used to mock network responses.  Will be set only
  // if test calls ExtensionApiTest::StartFTPServer().
  std::unique_ptr<FtpServer> ftp_server;

  // Details on the test server used to mock network responses.  Will be set only
  // if test calls ExtensionApiTest::StartEmbeddedTestServer().
  std::unique_ptr<TestServer> test_server;

  // file:/// URL for the API test data directory.
  std::unique_ptr<std::string> test_data_directory;

  // The port on which the test WebSocket server is listening.
  std::unique_ptr<int> test_web_socket_port;

  // Login status.
  std::unique_ptr<LoginStatus> login_status;


 private:
  DISALLOW_COPY_AND_ASSIGN(TestConfig);
};


std::unique_ptr<base::ListValue> Create(const TestConfig& test_config);
}  // namespace Results

}  // namespace GetConfig

namespace NotifyFail {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string message;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace NotifyFail

namespace NotifyPass {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::unique_ptr<std::string> message;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace NotifyPass

namespace Log {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string message;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Log

namespace PassMessage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string message;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& response);
}  // namespace Results

}  // namespace PassMessage

namespace WaitForRoundTrip {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string message;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& message);
}  // namespace Results

}  // namespace WaitForRoundTrip

//
// Events
//

namespace OnMessage {

extern const char kEventName[];  // "test.onMessage"

struct Info {
  Info();
  ~Info();
  Info(Info&& rhs);
  Info& operator=(Info&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Info object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Additional information.
  std::string data;

  // True if this was the last message for this test
  bool last_message;


 private:
  DISALLOW_COPY_AND_ASSIGN(Info);
};


std::unique_ptr<base::ListValue> Create(const Info& info);
}  // namespace OnMessage

}  // namespace test
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_TEST_H__
