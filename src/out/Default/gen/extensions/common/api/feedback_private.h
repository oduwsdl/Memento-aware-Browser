// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/feedback_private.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_FEEDBACK_PRIVATE_H__
#define EXTENSIONS_COMMON_API_FEEDBACK_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace feedback_private {

//
// Types
//

struct AttachedFile {
  AttachedFile();
  ~AttachedFile();
  AttachedFile(AttachedFile&& rhs);
  AttachedFile& operator=(AttachedFile&& rhs);

  // Populates a AttachedFile object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AttachedFile* out);

  // Creates a AttachedFile object from a base::Value, or NULL on failure.
  static std::unique_ptr<AttachedFile> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AttachedFile object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  struct Data {
    Data();
    ~Data();
    Data(Data&& rhs);
    Data& operator=(Data&& rhs);

    // Populates a Data object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Data* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Data object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Data);
  };


  std::string name;

  std::unique_ptr<Data> data;


 private:
  DISALLOW_COPY_AND_ASSIGN(AttachedFile);
};

struct SystemInformation {
  SystemInformation();
  ~SystemInformation();
  SystemInformation(SystemInformation&& rhs);
  SystemInformation& operator=(SystemInformation&& rhs);

  // Populates a SystemInformation object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, SystemInformation* out);

  // Creates a SystemInformation object from a base::Value, or NULL on failure.
  static std::unique_ptr<SystemInformation> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SystemInformation object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::string key;

  std::string value;


 private:
  DISALLOW_COPY_AND_ASSIGN(SystemInformation);
};

// Supported feedback flows.
enum FeedbackFlow {
  FEEDBACK_FLOW_NONE,
  FEEDBACK_FLOW_REGULAR,
  FEEDBACK_FLOW_LOGIN,
  FEEDBACK_FLOW_SADTABCRASH,
  FEEDBACK_FLOW_GOOGLEINTERNAL,
  FEEDBACK_FLOW_LAST = FEEDBACK_FLOW_GOOGLEINTERNAL,
};


const char* ToString(FeedbackFlow as_enum);
FeedbackFlow ParseFeedbackFlow(const std::string& as_string);

struct FeedbackInfo {
  FeedbackInfo();
  ~FeedbackInfo();
  FeedbackInfo(FeedbackInfo&& rhs);
  FeedbackInfo& operator=(FeedbackInfo&& rhs);

  // Populates a FeedbackInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, FeedbackInfo* out);

  // Creates a FeedbackInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<FeedbackInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FeedbackInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Screenshot to send with this feedback.
  struct Screenshot {
    Screenshot();
    ~Screenshot();
    Screenshot(Screenshot&& rhs);
    Screenshot& operator=(Screenshot&& rhs);

    // Populates a Screenshot object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Screenshot* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Screenshot object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(Screenshot);
  };


  // File to attach to the feedback report.
  std::unique_ptr<AttachedFile> attached_file;

  // An optional tag to label what type this feedback is.
  std::unique_ptr<std::string> category_tag;

  // The feedback text describing the user issue.
  std::string description;

  // The placeholder text that will be shown in the description field when it's
  // empty.
  std::unique_ptr<std::string> description_placeholder;

  // The e-mail of the user that initiated this feedback.
  std::unique_ptr<std::string> email;

  // The URL of the page that this issue was being experienced on.
  std::unique_ptr<std::string> page_url;

  // Optional product ID to override the Chrome [OS] product id that is usually
  // passed to the feedback server.
  std::unique_ptr<int> product_id;

  // Screenshot to send with this feedback.
  std::unique_ptr<Screenshot> screenshot;

  // Optional id for performance trace data that can be included in this report.
  std::unique_ptr<int> trace_id;

  // An array of key/value pairs providing system information for this feedback
  // report.
  std::unique_ptr<std::vector<SystemInformation>> system_information;

  // True if we have permission to add histograms to this feedback report.
  std::unique_ptr<bool> send_histograms;

  // Optional feedback UI flow. Default is the regular user flow.
  FeedbackFlow flow;

  // TODO(rkc): Remove these once we have bindings to send blobs to Chrome. Used
  // internally to store the blob uuid after parameter customization.
  std::unique_ptr<std::string> attached_file_blob_uuid;

  std::unique_ptr<std::string> screenshot_blob_uuid;

  // Whether to use the system-provided window frame or custom frame controls.
  std::unique_ptr<bool> use_system_window_frame;

  // Whether or not to send bluetooth logs with this report.
  std::unique_ptr<bool> send_bluetooth_logs;

  // Whether or not to send tab titles with this report.
  std::unique_ptr<bool> send_tab_titles;

  // Whether or not to send Assistant feedback to Assistant server.
  std::unique_ptr<bool> assistant_debug_info_allowed;

  // Whether or not triggered from Assistant.
  std::unique_ptr<bool> from_assistant;

  // Whether or not to include bluetooth logs.
  std::unique_ptr<bool> include_bluetooth_logs;


 private:
  DISALLOW_COPY_AND_ASSIGN(FeedbackInfo);
};

// Status of the sending of a feedback report.
enum Status {
  STATUS_NONE,
  STATUS_SUCCESS,
  STATUS_DELAYED,
  STATUS_LAST = STATUS_DELAYED,
};


const char* ToString(Status as_enum);
Status ParseStatus(const std::string& as_string);

// The type of the landing page shown to the user when the feedback report is
// successfully sent, if one should be shown.
enum LandingPageType {
  LANDING_PAGE_TYPE_NONE,
  LANDING_PAGE_TYPE_NORMAL,
  LANDING_PAGE_TYPE_TECHSTOP,
  LANDING_PAGE_TYPE_NOLANDINGPAGE,
  LANDING_PAGE_TYPE_LAST = LANDING_PAGE_TYPE_NOLANDINGPAGE,
};


const char* ToString(LandingPageType as_enum);
LandingPageType ParseLandingPageType(const std::string& as_string);

// Allowed log sources on Chrome OS.
enum LogSource {
  LOG_SOURCE_NONE,
  LOG_SOURCE_MESSAGES,
  LOG_SOURCE_UILATEST,
  LOG_SOURCE_DRMMODETEST,
  LOG_SOURCE_LSUSB,
  LOG_SOURCE_ATRUSLOG,
  LOG_SOURCE_NETLOG,
  LOG_SOURCE_EVENTLOG,
  LOG_SOURCE_UPDATEENGINELOG,
  LOG_SOURCE_POWERDLATEST,
  LOG_SOURCE_POWERDPREVIOUS,
  LOG_SOURCE_LSPCI,
  LOG_SOURCE_IFCONFIG,
  LOG_SOURCE_UPTIME,
  LOG_SOURCE_LAST = LOG_SOURCE_UPTIME,
};


const char* ToString(LogSource as_enum);
LogSource ParseLogSource(const std::string& as_string);

struct ReadLogSourceParams {
  ReadLogSourceParams();
  ~ReadLogSourceParams();
  ReadLogSourceParams(ReadLogSourceParams&& rhs);
  ReadLogSourceParams& operator=(ReadLogSourceParams&& rhs);

  // Populates a ReadLogSourceParams object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ReadLogSourceParams* out);

  // Creates a ReadLogSourceParams object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ReadLogSourceParams> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReadLogSourceParams object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The log source from which to read.
  LogSource source;

  // For file-based log sources, read from source without closing the file handle.
  // The next time $(ref:readLogSource) is called, the file read will continue
  // where it left off. $(ref:readLogSource) can be called with
  // <code>incremental=true</code> repeatedly. To subsequently close the file
  // handle, pass in <code>incremental=false</code>.
  bool incremental;

  // To read from an existing file handle, set this to a valid
  // <code>readerId</code> value that was returned from a previous
  // $(ref:readLogSource) call. The reader must previously have been created for
  // the same value of <code>source</code>. If no <code>readerId</code> is
  // provided, $(ref:readLogSource) will attempt to open a new log source reader
  // handle.
  std::unique_ptr<int> reader_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReadLogSourceParams);
};

struct ReadLogSourceResult {
  ReadLogSourceResult();
  ~ReadLogSourceResult();
  ReadLogSourceResult(ReadLogSourceResult&& rhs);
  ReadLogSourceResult& operator=(ReadLogSourceResult&& rhs);

  // Populates a ReadLogSourceResult object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ReadLogSourceResult* out);

  // Creates a ReadLogSourceResult object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ReadLogSourceResult> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ReadLogSourceResult object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the log source reader that was created to read from the log source.
  // If the reader was destroyed at the end of a read by passing in
  // <code>incremental=false</code>, this is always set to 0. If the call was to
  // use an existing reader with an existing ID, this will be set to the same
  // <code>readerId</code> that was passed into $(ref:readLogSource).
  int reader_id;

  // Each DOMString in this array represents one line of logging that was fetched
  // from the log source.
  std::vector<std::string> log_lines;


 private:
  DISALLOW_COPY_AND_ASSIGN(ReadLogSourceResult);
};


//
// Functions
//

namespace GetUserEmail {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& email);
}  // namespace Results

}  // namespace GetUserEmail

namespace GetSystemInformation {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<SystemInformation>& system_information);
}  // namespace Results

}  // namespace GetSystemInformation

namespace SendFeedback {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  FeedbackInfo feedback;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Status& status, const LandingPageType& type);
}  // namespace Results

}  // namespace SendFeedback

namespace GetStrings {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  FeedbackFlow flow;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

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


std::unique_ptr<base::ListValue> Create(const Result& result);
}  // namespace Results

}  // namespace GetStrings

namespace ReadLogSource {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  ReadLogSourceParams params;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ReadLogSourceResult& result);
}  // namespace Results

}  // namespace ReadLogSource

namespace LoginFeedbackComplete {

}  // namespace LoginFeedbackComplete

//
// Events
//

namespace OnFeedbackRequested {

extern const char kEventName[];  // "feedbackPrivate.onFeedbackRequested"

std::unique_ptr<base::ListValue> Create(const FeedbackInfo& feedback);
}  // namespace OnFeedbackRequested

}  // namespace feedback_private
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_FEEDBACK_PRIVATE_H__
