// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/test.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/test.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace test {
//
// Functions
//

namespace GetConfig {

Results::TestConfig::FtpServer::FtpServer()
: port(0) {}

Results::TestConfig::FtpServer::~FtpServer() {}
Results::TestConfig::FtpServer::FtpServer(FtpServer&& rhs)
: port(rhs.port){
}

Results::TestConfig::FtpServer& Results::TestConfig::FtpServer::operator=(FtpServer&& rhs)
{
port = rhs.port;
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::TestConfig::FtpServer::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("port", std::make_unique<base::Value>(this->port));


  return to_value_result;
}


Results::TestConfig::TestServer::TestServer()
: port(0) {}

Results::TestConfig::TestServer::~TestServer() {}
Results::TestConfig::TestServer::TestServer(TestServer&& rhs)
: port(rhs.port){
}

Results::TestConfig::TestServer& Results::TestConfig::TestServer::operator=(TestServer&& rhs)
{
port = rhs.port;
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::TestConfig::TestServer::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("port", std::make_unique<base::Value>(this->port));


  return to_value_result;
}


Results::TestConfig::LoginStatus::LoginStatus()
 {}

Results::TestConfig::LoginStatus::~LoginStatus() {}
Results::TestConfig::LoginStatus::LoginStatus(LoginStatus&& rhs)
: is_logged_in(std::move(rhs.is_logged_in)),
is_screen_locked(std::move(rhs.is_screen_locked)){
}

Results::TestConfig::LoginStatus& Results::TestConfig::LoginStatus::operator=(LoginStatus&& rhs)
{
is_logged_in = std::move(rhs.is_logged_in);
is_screen_locked = std::move(rhs.is_screen_locked);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::TestConfig::LoginStatus::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->is_logged_in.get()) {
    to_value_result->SetWithoutPathExpansion("isLoggedIn", std::make_unique<base::Value>(*this->is_logged_in));

  }
  if (this->is_screen_locked.get()) {
    to_value_result->SetWithoutPathExpansion("isScreenLocked", std::make_unique<base::Value>(*this->is_screen_locked));

  }

  return to_value_result;
}



Results::TestConfig::TestConfig()
 {}

Results::TestConfig::~TestConfig() {}
Results::TestConfig::TestConfig(TestConfig&& rhs)
: custom_arg(std::move(rhs.custom_arg)),
ftp_server(std::move(rhs.ftp_server)),
test_server(std::move(rhs.test_server)),
test_data_directory(std::move(rhs.test_data_directory)),
test_web_socket_port(std::move(rhs.test_web_socket_port)),
login_status(std::move(rhs.login_status)){
}

Results::TestConfig& Results::TestConfig::operator=(TestConfig&& rhs)
{
custom_arg = std::move(rhs.custom_arg);
ftp_server = std::move(rhs.ftp_server);
test_server = std::move(rhs.test_server);
test_data_directory = std::move(rhs.test_data_directory);
test_web_socket_port = std::move(rhs.test_web_socket_port);
login_status = std::move(rhs.login_status);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::TestConfig::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->custom_arg.get()) {
    to_value_result->SetWithoutPathExpansion("customArg", std::make_unique<base::Value>(*this->custom_arg));

  }
  if (this->ftp_server.get()) {
    to_value_result->SetWithoutPathExpansion("ftpServer", (this->ftp_server)->ToValue());

  }
  if (this->test_server.get()) {
    to_value_result->SetWithoutPathExpansion("testServer", (this->test_server)->ToValue());

  }
  if (this->test_data_directory.get()) {
    to_value_result->SetWithoutPathExpansion("testDataDirectory", std::make_unique<base::Value>(*this->test_data_directory));

  }
  if (this->test_web_socket_port.get()) {
    to_value_result->SetWithoutPathExpansion("testWebSocketPort", std::make_unique<base::Value>(*this->test_web_socket_port));

  }
  if (this->login_status.get()) {
    to_value_result->SetWithoutPathExpansion("loginStatus", (this->login_status)->ToValue());

  }

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const TestConfig& test_config) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((test_config).ToValue());

  return create_results;
}
}  // namespace GetConfig

namespace NotifyFail {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* message_value = NULL;
  if (args.Get(0, &message_value) &&
      !message_value->is_none()) {
    {
      if (!message_value->GetAsString(&params->message)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace NotifyFail

namespace NotifyPass {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* message_value = NULL;
  if (args.Get(0, &message_value) &&
      !message_value->is_none()) {
    {
      std::string temp;
      if (!message_value->GetAsString(&temp)) {
        params->message.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->message.reset(new std::string(temp));
    }
  }

  return params;
}


}  // namespace NotifyPass

namespace Log {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* message_value = NULL;
  if (args.Get(0, &message_value) &&
      !message_value->is_none()) {
    {
      if (!message_value->GetAsString(&params->message)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Log

namespace PassMessage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* message_value = NULL;
  if (args.Get(0, &message_value) &&
      !message_value->is_none()) {
    {
      if (!message_value->GetAsString(&params->message)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& response) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(response));

  return create_results;
}
}  // namespace PassMessage

namespace WaitForRoundTrip {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* message_value = NULL;
  if (args.Get(0, &message_value) &&
      !message_value->is_none()) {
    {
      if (!message_value->GetAsString(&params->message)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& message) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(message));

  return create_results;
}
}  // namespace WaitForRoundTrip

//
// Events
//

namespace OnMessage {

const char kEventName[] = "test.onMessage";

Info::Info()
: last_message(false) {}

Info::~Info() {}
Info::Info(Info&& rhs)
: data(std::move(rhs.data)),
last_message(rhs.last_message){
}

Info& Info::operator=(Info&& rhs)
{
data = std::move(rhs.data);
last_message = rhs.last_message;
return *this;
}

std::unique_ptr<base::DictionaryValue> Info::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(this->data));

  to_value_result->SetWithoutPathExpansion("lastMessage", std::make_unique<base::Value>(this->last_message));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Info& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnMessage

}  // namespace test
}  // namespace api
}  // namespace extensions

