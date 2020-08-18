// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/webrtc_logging_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_WEBRTC_LOGGING_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_WEBRTC_LOGGING_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace webrtc_logging_private {

//
// Types
//

struct MetaDataEntry {
  MetaDataEntry();
  ~MetaDataEntry();
  MetaDataEntry(MetaDataEntry&& rhs);
  MetaDataEntry& operator=(MetaDataEntry&& rhs);

  // Populates a MetaDataEntry object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, MetaDataEntry* out);

  // Creates a MetaDataEntry object from a base::Value, or NULL on failure.
  static std::unique_ptr<MetaDataEntry> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MetaDataEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The meta data entry key.
  std::string key;

  // The meta data entry value.
  std::string value;


 private:
  DISALLOW_COPY_AND_ASSIGN(MetaDataEntry);
};

struct UploadResult {
  UploadResult();
  ~UploadResult();
  UploadResult(UploadResult&& rhs);
  UploadResult& operator=(UploadResult&& rhs);

  // Populates a UploadResult object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, UploadResult* out);

  // Creates a UploadResult object from a base::Value, or NULL on failure.
  static std::unique_ptr<UploadResult> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this UploadResult object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The report ID for the uploaded log. Will be empty if not successful.
  std::string report_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(UploadResult);
};

struct RequestInfo {
  RequestInfo();
  ~RequestInfo();
  RequestInfo(RequestInfo&& rhs);
  RequestInfo& operator=(RequestInfo&& rhs);

  // Populates a RequestInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RequestInfo* out);

  // Creates a RequestInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<RequestInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RequestInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The tab identifier from the chrome.tabs API, if the request is from a tab.
  std::unique_ptr<int> tab_id;

  // The guest process id for the requester, if the request is from a webview.
  std::unique_ptr<int> guest_process_id;

  // Use the render process of the webview in the current page. This allows an app
  // to make a request for a webview it contains. If there are more or less than 1
  // webview, this will fail with a runtime error.
  std::unique_ptr<bool> target_webview;


 private:
  DISALLOW_COPY_AND_ASSIGN(RequestInfo);
};

struct RecordingInfo {
  RecordingInfo();
  ~RecordingInfo();
  RecordingInfo(RecordingInfo&& rhs);
  RecordingInfo& operator=(RecordingInfo&& rhs);

  // Populates a RecordingInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, RecordingInfo* out);

  // Creates a RecordingInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<RecordingInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this RecordingInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Absolute path prefix for the files with the audio debug recordings.
  std::string prefix_path;

  // Indicates if recording was stopped (either by a timed callback after the time
  // limit has elapsed, or by a manual call).
  bool did_stop;

  // Indicates if recording was stopped manually through a
  // stopAudioDebugRecordings() call.
  bool did_manual_stop;


 private:
  DISALLOW_COPY_AND_ASSIGN(RecordingInfo);
};

struct StartEventLoggingResult {
  StartEventLoggingResult();
  ~StartEventLoggingResult();
  StartEventLoggingResult(StartEventLoggingResult&& rhs);
  StartEventLoggingResult& operator=(StartEventLoggingResult&& rhs);

  // Populates a StartEventLoggingResult object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, StartEventLoggingResult* out);

  // Creates a StartEventLoggingResult object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<StartEventLoggingResult> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StartEventLoggingResult object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The log ID. Non-empty if and only if StartEventLogging() was successful.
  std::string log_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(StartEventLoggingResult);
};


//
// Functions
//

namespace SetMetaData {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  std::vector<MetaDataEntry> meta_data;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetMetaData

namespace Start {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Start

namespace SetUploadOnRenderClose {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  bool should_upload;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetUploadOnRenderClose

namespace Stop {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Stop

namespace Store {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  std::string log_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Store

namespace UploadStored {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  std::string log_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const UploadResult& result);
}  // namespace Results

}  // namespace UploadStored

namespace Upload {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const UploadResult& result);
}  // namespace Results

}  // namespace Upload

namespace Discard {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Discard

namespace StartRtpDump {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  bool incoming;

  bool outgoing;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartRtpDump

namespace StopRtpDump {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  bool incoming;

  bool outgoing;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StopRtpDump

namespace StartAudioDebugRecordings {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  int seconds;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const RecordingInfo& info);
}  // namespace Results

}  // namespace StartAudioDebugRecordings

namespace StopAudioDebugRecordings {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const RecordingInfo& info);
}  // namespace Results

}  // namespace StopAudioDebugRecordings

namespace StartEventLogging {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  RequestInfo request;

  std::string security_origin;

  std::string session_id;

  int max_log_size_bytes;

  int output_period_ms;

  int web_app_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const StartEventLoggingResult& result);
}  // namespace Results

}  // namespace StartEventLogging

namespace GetLogsDirectory {

namespace Results {

struct Entry {
  Entry();
  ~Entry();
  Entry(Entry&& rhs);
  Entry& operator=(Entry&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Entry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Entry);
};


std::unique_ptr<base::ListValue> Create(const Entry& entry);
}  // namespace Results

}  // namespace GetLogsDirectory

}  // namespace webrtc_logging_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_WEBRTC_LOGGING_PRIVATE_H__
