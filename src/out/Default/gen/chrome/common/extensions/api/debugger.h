// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/debugger.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_DEBUGGER_H__
#define CHROME_COMMON_EXTENSIONS_API_DEBUGGER_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace debugger {

//
// Types
//

// Debuggee identifier. Either tabId or extensionId must be specified
struct Debuggee {
  Debuggee();
  ~Debuggee();
  Debuggee(Debuggee&& rhs);
  Debuggee& operator=(Debuggee&& rhs);

  // Populates a Debuggee object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Debuggee* out);

  // Creates a Debuggee object from a base::Value, or NULL on failure.
  static std::unique_ptr<Debuggee> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Debuggee object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The id of the tab which you intend to debug.
  std::unique_ptr<int> tab_id;

  // The id of the extension which you intend to debug. Attaching to an extension
  // background page is only possible when 'silent-debugger-extension-api' flag is
  // enabled on the target browser.
  std::unique_ptr<std::string> extension_id;

  // The opaque id of the debug target.
  std::unique_ptr<std::string> target_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(Debuggee);
};

// Target type.
enum TargetInfoType {
  TARGET_INFO_TYPE_NONE,
  TARGET_INFO_TYPE_PAGE,
  TARGET_INFO_TYPE_BACKGROUND_PAGE,
  TARGET_INFO_TYPE_WORKER,
  TARGET_INFO_TYPE_OTHER,
  TARGET_INFO_TYPE_LAST = TARGET_INFO_TYPE_OTHER,
};


const char* ToString(TargetInfoType as_enum);
TargetInfoType ParseTargetInfoType(const std::string& as_string);

// Connection termination reason.
enum DetachReason {
  DETACH_REASON_NONE,
  DETACH_REASON_TARGET_CLOSED,
  DETACH_REASON_CANCELED_BY_USER,
  DETACH_REASON_LAST = DETACH_REASON_CANCELED_BY_USER,
};


const char* ToString(DetachReason as_enum);
DetachReason ParseDetachReason(const std::string& as_string);

// Debug target information
struct TargetInfo {
  TargetInfo();
  ~TargetInfo();
  TargetInfo(TargetInfo&& rhs);
  TargetInfo& operator=(TargetInfo&& rhs);

  // Populates a TargetInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, TargetInfo* out);

  // Creates a TargetInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<TargetInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TargetInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Target type.
  TargetInfoType type;

  // Target id.
  std::string id;

  // The tab id, defined if type == 'page'.
  std::unique_ptr<int> tab_id;

  // The extension id, defined if type = 'background_page'.
  std::unique_ptr<std::string> extension_id;

  // True if debugger is already attached.
  bool attached;

  // Target page title.
  std::string title;

  // Target URL.
  std::string url;

  // Target favicon URL.
  std::unique_ptr<std::string> favicon_url;


 private:
  DISALLOW_COPY_AND_ASSIGN(TargetInfo);
};


//
// Functions
//

namespace Attach {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Debugging target to which you want to attach.
  Debuggee target;

  // Required debugging protocol version ("0.1"). One can only attach to the
  // debuggee with matching major version and greater or equal minor version. List
  // of the protocol versions can be obtained <a
  // href='https://developer.chrome.com/devtools/docs/debugger-protocol'>here</a>.
  std::string required_version;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Attach

namespace Detach {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Debugging target from which you want to detach.
  Debuggee target;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Detach

namespace SendCommand {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // JSON object with request parameters. This object must conform to the remote
  // debugging params scheme for given method.
  struct CommandParams {
    CommandParams();
    ~CommandParams();
    CommandParams(CommandParams&& rhs);
    CommandParams& operator=(CommandParams&& rhs);

    // Populates a CommandParams object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, CommandParams* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(CommandParams);
  };


  // Debugging target to which you want to send the command.
  Debuggee target;

  // Method name. Should be one of the methods defined by the <a
  // href='https://developer.chrome.com/devtools/docs/debugger-protocol'>remote
  // debugging protocol</a>.
  std::string method;

  // JSON object with request parameters. This object must conform to the remote
  // debugging params scheme for given method.
  std::unique_ptr<CommandParams> command_params;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// JSON object with the response. Structure of the response varies depending on
// the method name and is defined by the 'returns' attribute of the command
// description in the remote debugging protocol.
struct Result {
  Result();
  ~Result();
  Result(Result&& rhs);
  Result& operator=(Result&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Result object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Result);
};


// JSON object with the response. Structure of the response varies depending on
// the method name and is defined by the 'returns' attribute of the command
// description in the remote debugging protocol.
std::unique_ptr<base::ListValue> Create(const Result& result);
}  // namespace Results

}  // namespace SendCommand

namespace GetTargets {

namespace Results {

// Array of TargetInfo objects corresponding to the available debug targets.
std::unique_ptr<base::ListValue> Create(const std::vector<TargetInfo>& result);
}  // namespace Results

}  // namespace GetTargets

//
// Events
//

namespace OnEvent {

extern const char kEventName[];  // "debugger.onEvent"

// JSON object with the parameters. Structure of the parameters varies depending
// on the method name and is defined by the 'parameters' attribute of the event
// description in the remote debugging protocol.
struct Params {
  Params();
  ~Params();
  Params(Params&& rhs);
  Params& operator=(Params&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Params object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Params);
};


// The debuggee that generated this event.
// Method name. Should be one of the notifications defined by the <a
// href='https://developer.chrome.com/devtools/docs/debugger-protocol'>remote
// debugging protocol</a>.
// JSON object with the parameters. Structure of the parameters varies depending
// on the method name and is defined by the 'parameters' attribute of the event
// description in the remote debugging protocol.
std::unique_ptr<base::ListValue> Create(const Debuggee& source, const std::string& method, const Params& params);
}  // namespace OnEvent

namespace OnDetach {

extern const char kEventName[];  // "debugger.onDetach"

// The debuggee that was detached.
// Connection termination reason.
std::unique_ptr<base::ListValue> Create(const Debuggee& source, const DetachReason& reason);
}  // namespace OnDetach

}  // namespace debugger
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_DEBUGGER_H__
