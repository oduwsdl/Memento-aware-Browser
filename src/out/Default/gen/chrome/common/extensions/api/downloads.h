// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/downloads.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_DOWNLOADS_H__
#define CHROME_COMMON_EXTENSIONS_API_DOWNLOADS_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace downloads {

//
// Types
//

struct HeaderNameValuePair {
  HeaderNameValuePair();
  ~HeaderNameValuePair();
  HeaderNameValuePair(HeaderNameValuePair&& rhs);
  HeaderNameValuePair& operator=(HeaderNameValuePair&& rhs);

  // Populates a HeaderNameValuePair object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, HeaderNameValuePair* out);

  // Creates a HeaderNameValuePair object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<HeaderNameValuePair> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HeaderNameValuePair object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Name of the HTTP header.
  std::string name;

  // Value of the HTTP header.
  std::string value;


 private:
  DISALLOW_COPY_AND_ASSIGN(HeaderNameValuePair);
};

// <dl><dt>uniquify</dt>     <dd>To avoid duplication, the <code>filename</code>
// is changed to     include a counter before the filename extension.</dd>
// <dt>overwrite</dt>     <dd>The existing file will be overwritten with the new
// file.</dd>     <dt>prompt</dt>     <dd>The user will be prompted with a file
// chooser dialog.</dd> </dl>
enum FilenameConflictAction {
  FILENAME_CONFLICT_ACTION_NONE,
  FILENAME_CONFLICT_ACTION_UNIQUIFY,
  FILENAME_CONFLICT_ACTION_OVERWRITE,
  FILENAME_CONFLICT_ACTION_PROMPT,
  FILENAME_CONFLICT_ACTION_LAST = FILENAME_CONFLICT_ACTION_PROMPT,
};


const char* ToString(FilenameConflictAction as_enum);
FilenameConflictAction ParseFilenameConflictAction(const std::string& as_string);

struct FilenameSuggestion {
  FilenameSuggestion();
  ~FilenameSuggestion();
  FilenameSuggestion(FilenameSuggestion&& rhs);
  FilenameSuggestion& operator=(FilenameSuggestion&& rhs);

  // Populates a FilenameSuggestion object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, FilenameSuggestion* out);

  // Creates a FilenameSuggestion object from a base::Value, or NULL on failure.
  static std::unique_ptr<FilenameSuggestion> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FilenameSuggestion object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The $(ref:DownloadItem)'s new target $(ref:DownloadItem.filename), as a path
  // relative to the user's default Downloads directory, possibly containing
  // subdirectories. Absolute paths, empty paths, and paths containing
  // back-references ".." will be ignored.
  std::string filename;

  // The action to take if <code>filename</code> already exists.
  FilenameConflictAction conflict_action;


 private:
  DISALLOW_COPY_AND_ASSIGN(FilenameSuggestion);
};

enum HttpMethod {
  HTTP_METHOD_NONE,
  HTTP_METHOD_GET,
  HTTP_METHOD_POST,
  HTTP_METHOD_LAST = HTTP_METHOD_POST,
};


const char* ToString(HttpMethod as_enum);
HttpMethod ParseHttpMethod(const std::string& as_string);

enum InterruptReason {
  INTERRUPT_REASON_NONE,
  INTERRUPT_REASON_FILE_FAILED,
  INTERRUPT_REASON_FILE_ACCESS_DENIED,
  INTERRUPT_REASON_FILE_NO_SPACE,
  INTERRUPT_REASON_FILE_NAME_TOO_LONG,
  INTERRUPT_REASON_FILE_TOO_LARGE,
  INTERRUPT_REASON_FILE_VIRUS_INFECTED,
  INTERRUPT_REASON_FILE_TRANSIENT_ERROR,
  INTERRUPT_REASON_FILE_BLOCKED,
  INTERRUPT_REASON_FILE_SECURITY_CHECK_FAILED,
  INTERRUPT_REASON_FILE_TOO_SHORT,
  INTERRUPT_REASON_FILE_HASH_MISMATCH,
  INTERRUPT_REASON_FILE_SAME_AS_SOURCE,
  INTERRUPT_REASON_NETWORK_FAILED,
  INTERRUPT_REASON_NETWORK_TIMEOUT,
  INTERRUPT_REASON_NETWORK_DISCONNECTED,
  INTERRUPT_REASON_NETWORK_SERVER_DOWN,
  INTERRUPT_REASON_NETWORK_INVALID_REQUEST,
  INTERRUPT_REASON_SERVER_FAILED,
  INTERRUPT_REASON_SERVER_NO_RANGE,
  INTERRUPT_REASON_SERVER_BAD_CONTENT,
  INTERRUPT_REASON_SERVER_UNAUTHORIZED,
  INTERRUPT_REASON_SERVER_CERT_PROBLEM,
  INTERRUPT_REASON_SERVER_FORBIDDEN,
  INTERRUPT_REASON_SERVER_UNREACHABLE,
  INTERRUPT_REASON_SERVER_CONTENT_LENGTH_MISMATCH,
  INTERRUPT_REASON_SERVER_CROSS_ORIGIN_REDIRECT,
  INTERRUPT_REASON_USER_CANCELED,
  INTERRUPT_REASON_USER_SHUTDOWN,
  INTERRUPT_REASON_CRASH,
  INTERRUPT_REASON_LAST = INTERRUPT_REASON_CRASH,
};


const char* ToString(InterruptReason as_enum);
InterruptReason ParseInterruptReason(const std::string& as_string);

struct DownloadOptions {
  DownloadOptions();
  ~DownloadOptions();
  DownloadOptions(DownloadOptions&& rhs);
  DownloadOptions& operator=(DownloadOptions&& rhs);

  // Populates a DownloadOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, DownloadOptions* out);

  // Creates a DownloadOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<DownloadOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DownloadOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The URL to download.
  std::string url;

  // A file path relative to the Downloads directory to contain the downloaded
  // file, possibly containing subdirectories. Absolute paths, empty paths, and
  // paths containing back-references ".." will cause an error.
  // $(ref:onDeterminingFilename) allows suggesting a filename after the file's
  // MIME type and a tentative filename have been determined.
  std::unique_ptr<std::string> filename;

  // The action to take if <code>filename</code> already exists.
  FilenameConflictAction conflict_action;

  // Use a file-chooser to allow the user to select a filename regardless of
  // whether <code>filename</code> is set or already exists.
  std::unique_ptr<bool> save_as;

  // The HTTP method to use if the URL uses the HTTP[S] protocol.
  HttpMethod method;

  // Extra HTTP headers to send with the request if the URL uses the HTTP[s]
  // protocol. Each header is represented as a dictionary containing the keys
  // <code>name</code> and either <code>value</code> or <code>binaryValue</code>,
  // restricted to those allowed by XMLHttpRequest.
  std::unique_ptr<std::vector<HeaderNameValuePair>> headers;

  // Post body.
  std::unique_ptr<std::string> body;


 private:
  DISALLOW_COPY_AND_ASSIGN(DownloadOptions);
};

// <dl><dt>file</dt>     <dd>The download's filename is suspicious.</dd>
// <dt>url</dt>     <dd>The download's URL is known to be malicious.</dd>
// <dt>content</dt>     <dd>The downloaded file is known to be malicious.</dd>
// <dt>uncommon</dt>     <dd>The download's URL is not commonly downloaded and
// could be     dangerous.</dd>     <dt>host</dt>     <dd>The download came from
// a host known to distribute malicious     binaries and is likely
// dangerous.</dd>     <dt>unwanted</dt>     <dd>The download is potentially
// unwanted or unsafe. E.g. it could make     changes to browser or computer
// settings.</dd>     <dt>safe</dt>     <dd>The download presents no known
// danger to the user's computer.</dd>     <dt>accepted</dt>     <dd>The user
// has accepted the dangerous download.</dd> </dl>
enum DangerType {
  DANGER_TYPE_NONE,
  DANGER_TYPE_FILE,
  DANGER_TYPE_URL,
  DANGER_TYPE_CONTENT,
  DANGER_TYPE_UNCOMMON,
  DANGER_TYPE_HOST,
  DANGER_TYPE_UNWANTED,
  DANGER_TYPE_SAFE,
  DANGER_TYPE_ACCEPTED,
  DANGER_TYPE_LAST = DANGER_TYPE_ACCEPTED,
};


const char* ToString(DangerType as_enum);
DangerType ParseDangerType(const std::string& as_string);

// <dl><dt>in_progress</dt>     <dd>The download is currently receiving data
// from the server.</dd>     <dt>interrupted</dt>     <dd>An error broke the
// connection with the file host.</dd>     <dt>complete</dt>     <dd>The
// download completed successfully.</dd> </dl>
enum State {
  STATE_NONE,
  STATE_IN_PROGRESS,
  STATE_INTERRUPTED,
  STATE_COMPLETE,
  STATE_LAST = STATE_COMPLETE,
};


const char* ToString(State as_enum);
State ParseState(const std::string& as_string);

struct DownloadItem {
  DownloadItem();
  ~DownloadItem();
  DownloadItem(DownloadItem&& rhs);
  DownloadItem& operator=(DownloadItem&& rhs);

  // Populates a DownloadItem object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DownloadItem* out);

  // Creates a DownloadItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<DownloadItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DownloadItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // An identifier that is persistent across browser sessions.
  int id;

  // The absolute URL that this download initiated from, before any redirects.
  std::string url;

  // The absolute URL that this download is being made from, after all redirects.
  std::string final_url;

  // Absolute URL.
  std::string referrer;

  // Absolute local path.
  std::string filename;

  // False if this download is recorded in the history, true if it is not
  // recorded.
  bool incognito;

  // Indication of whether this download is thought to be safe or known to be
  // suspicious.
  DangerType danger;

  // The file's MIME type.
  std::string mime;

  // The time when the download began in ISO 8601 format. May be passed directly
  // to the Date constructor: <code>chrome.downloads.search({},
  // function(items){items.forEach(function(item){console.log(new
  // Date(item.startTime))})})</code>
  std::string start_time;

  // The time when the download ended in ISO 8601 format. May be passed directly
  // to the Date constructor: <code>chrome.downloads.search({},
  // function(items){items.forEach(function(item){if (item.endTime)
  // console.log(new Date(item.endTime))})})</code>
  std::unique_ptr<std::string> end_time;

  // Estimated time when the download will complete in ISO 8601 format. May be
  // passed directly to the Date constructor: <code>chrome.downloads.search({},
  // function(items){items.forEach(function(item){if (item.estimatedEndTime)
  // console.log(new Date(item.estimatedEndTime))})})</code>
  std::unique_ptr<std::string> estimated_end_time;

  // Indicates whether the download is progressing, interrupted, or complete.
  State state;

  // True if the download has stopped reading data from the host, but kept the
  // connection open.
  bool paused;

  // True if the download is in progress and paused, or else if it is interrupted
  // and can be resumed starting from where it was interrupted.
  bool can_resume;

  // Why the download was interrupted. Several kinds of HTTP errors may be grouped
  // under one of the errors beginning with <code>SERVER_</code>. Errors relating
  // to the network begin with <code>NETWORK_</code>, errors relating to the
  // process of writing the file to the file system begin with <code>FILE_</code>,
  // and interruptions initiated by the user begin with <code>USER_</code>.
  InterruptReason error;

  // Number of bytes received so far from the host, without considering file
  // compression.
  double bytes_received;

  // Number of bytes in the whole file, without considering file compression, or
  // -1 if unknown.
  double total_bytes;

  // Number of bytes in the whole file post-decompression, or -1 if unknown.
  double file_size;

  // Whether the downloaded file still exists. This information may be out of date
  // because Chrome does not automatically watch for file removal. Call
  // $(ref:search)() in order to trigger the check for file existence. When the
  // existence check completes, if the file has been deleted, then an
  // $(ref:onChanged) event will fire. Note that $(ref:search)() does not wait for
  // the existence check to finish before returning, so results from
  // $(ref:search)() may not accurately reflect the file system. Also,
  // $(ref:search)() may be called as often as necessary, but will not check for
  // file existence any more frequently than once every 10 seconds.
  bool exists;

  // The identifier for the extension that initiated this download if this
  // download was initiated by an extension. Does not change once it is set.
  std::unique_ptr<std::string> by_extension_id;

  // The localized name of the extension that initiated this download if this
  // download was initiated by an extension. May change if the extension changes
  // its name or if the user changes their locale.
  std::unique_ptr<std::string> by_extension_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(DownloadItem);
};

struct DownloadQuery {
  DownloadQuery();
  ~DownloadQuery();
  DownloadQuery(DownloadQuery&& rhs);
  DownloadQuery& operator=(DownloadQuery&& rhs);

  // Populates a DownloadQuery object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DownloadQuery* out);

  // Creates a DownloadQuery object from a base::Value, or NULL on failure.
  static std::unique_ptr<DownloadQuery> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DownloadQuery object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // This array of search terms limits results to $(ref:DownloadItem) whose
  // <code>filename</code> or <code>url</code> or <code>finalUrl</code> contain
  // all of the search terms that do not begin with a dash '-' and none of the
  // search terms that do begin with a dash.
  std::unique_ptr<std::vector<std::string>> query;

  // Limits results to $(ref:DownloadItem) that started before the given ms since
  // the epoch.
  std::unique_ptr<std::string> started_before;

  // Limits results to $(ref:DownloadItem) that started after the given ms since
  // the epoch.
  std::unique_ptr<std::string> started_after;

  // Limits results to $(ref:DownloadItem) that ended before the given ms since
  // the epoch.
  std::unique_ptr<std::string> ended_before;

  // Limits results to $(ref:DownloadItem) that ended after the given ms since the
  // epoch.
  std::unique_ptr<std::string> ended_after;

  // Limits results to $(ref:DownloadItem) whose <code>totalBytes</code> is
  // greater than the given integer.
  std::unique_ptr<double> total_bytes_greater;

  // Limits results to $(ref:DownloadItem) whose <code>totalBytes</code> is less
  // than the given integer.
  std::unique_ptr<double> total_bytes_less;

  // Limits results to $(ref:DownloadItem) whose <code>filename</code> matches the
  // given regular expression.
  std::unique_ptr<std::string> filename_regex;

  // Limits results to $(ref:DownloadItem) whose <code>url</code> matches the
  // given regular expression.
  std::unique_ptr<std::string> url_regex;

  // Limits results to $(ref:DownloadItem) whose <code>finalUrl</code> matches the
  // given regular expression.
  std::unique_ptr<std::string> final_url_regex;

  // The maximum number of matching $(ref:DownloadItem) returned. Defaults to
  // 1000. Set to 0 in order to return all matching $(ref:DownloadItem). See
  // $(ref:search) for how to page through results.
  std::unique_ptr<int> limit;

  // Set elements of this array to $(ref:DownloadItem) properties in order to sort
  // search results. For example, setting <code>orderBy=['startTime']</code> sorts
  // the $(ref:DownloadItem) by their start time in ascending order. To specify
  // descending order, prefix with a hyphen: '-startTime'.
  std::unique_ptr<std::vector<std::string>> order_by;

  // The <code>id</code> of the $(ref:DownloadItem) to query.
  std::unique_ptr<int> id;

  // The absolute URL that this download initiated from, before any redirects.
  std::unique_ptr<std::string> url;

  // The absolute URL that this download is being made from, after all redirects.
  std::unique_ptr<std::string> final_url;

  // Absolute local path.
  std::unique_ptr<std::string> filename;

  // Indication of whether this download is thought to be safe or known to be
  // suspicious.
  DangerType danger;

  // The file's MIME type.
  std::unique_ptr<std::string> mime;

  // The time when the download began in ISO 8601 format.
  std::unique_ptr<std::string> start_time;

  // The time when the download ended in ISO 8601 format.
  std::unique_ptr<std::string> end_time;

  // Indicates whether the download is progressing, interrupted, or complete.
  State state;

  // True if the download has stopped reading data from the host, but kept the
  // connection open.
  std::unique_ptr<bool> paused;

  // Why a download was interrupted.
  InterruptReason error;

  // Number of bytes received so far from the host, without considering file
  // compression.
  std::unique_ptr<double> bytes_received;

  // Number of bytes in the whole file, without considering file compression, or
  // -1 if unknown.
  std::unique_ptr<double> total_bytes;

  // Number of bytes in the whole file post-decompression, or -1 if unknown.
  std::unique_ptr<double> file_size;

  // Whether the downloaded file exists;
  std::unique_ptr<bool> exists;


 private:
  DISALLOW_COPY_AND_ASSIGN(DownloadQuery);
};

struct StringDelta {
  StringDelta();
  ~StringDelta();
  StringDelta(StringDelta&& rhs);
  StringDelta& operator=(StringDelta&& rhs);

  // Populates a StringDelta object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, StringDelta* out);

  // Creates a StringDelta object from a base::Value, or NULL on failure.
  static std::unique_ptr<StringDelta> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StringDelta object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<std::string> previous;

  std::unique_ptr<std::string> current;


 private:
  DISALLOW_COPY_AND_ASSIGN(StringDelta);
};

struct DoubleDelta {
  DoubleDelta();
  ~DoubleDelta();
  DoubleDelta(DoubleDelta&& rhs);
  DoubleDelta& operator=(DoubleDelta&& rhs);

  // Populates a DoubleDelta object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DoubleDelta* out);

  // Creates a DoubleDelta object from a base::Value, or NULL on failure.
  static std::unique_ptr<DoubleDelta> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DoubleDelta object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<double> previous;

  std::unique_ptr<double> current;


 private:
  DISALLOW_COPY_AND_ASSIGN(DoubleDelta);
};

struct BooleanDelta {
  BooleanDelta();
  ~BooleanDelta();
  BooleanDelta(BooleanDelta&& rhs);
  BooleanDelta& operator=(BooleanDelta&& rhs);

  // Populates a BooleanDelta object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, BooleanDelta* out);

  // Creates a BooleanDelta object from a base::Value, or NULL on failure.
  static std::unique_ptr<BooleanDelta> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this BooleanDelta object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::unique_ptr<bool> previous;

  std::unique_ptr<bool> current;


 private:
  DISALLOW_COPY_AND_ASSIGN(BooleanDelta);
};

struct DownloadDelta {
  DownloadDelta();
  ~DownloadDelta();
  DownloadDelta(DownloadDelta&& rhs);
  DownloadDelta& operator=(DownloadDelta&& rhs);

  // Populates a DownloadDelta object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DownloadDelta* out);

  // Creates a DownloadDelta object from a base::Value, or NULL on failure.
  static std::unique_ptr<DownloadDelta> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DownloadDelta object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The <code>id</code> of the $(ref:DownloadItem) that changed.
  int id;

  // The change in <code>url</code>, if any.
  std::unique_ptr<StringDelta> url;

  // The change in <code>finalUrl</code>, if any.
  std::unique_ptr<StringDelta> final_url;

  // The change in <code>filename</code>, if any.
  std::unique_ptr<StringDelta> filename;

  // The change in <code>danger</code>, if any.
  std::unique_ptr<StringDelta> danger;

  // The change in <code>mime</code>, if any.
  std::unique_ptr<StringDelta> mime;

  // The change in <code>startTime</code>, if any.
  std::unique_ptr<StringDelta> start_time;

  // The change in <code>endTime</code>, if any.
  std::unique_ptr<StringDelta> end_time;

  // The change in <code>state</code>, if any.
  std::unique_ptr<StringDelta> state;

  // The change in <code>canResume</code>, if any.
  std::unique_ptr<BooleanDelta> can_resume;

  // The change in <code>paused</code>, if any.
  std::unique_ptr<BooleanDelta> paused;

  // The change in <code>error</code>, if any.
  std::unique_ptr<StringDelta> error;

  // The change in <code>totalBytes</code>, if any.
  std::unique_ptr<DoubleDelta> total_bytes;

  // The change in <code>fileSize</code>, if any.
  std::unique_ptr<DoubleDelta> file_size;

  // The change in <code>exists</code>, if any.
  std::unique_ptr<BooleanDelta> exists;


 private:
  DISALLOW_COPY_AND_ASSIGN(DownloadDelta);
};

struct GetFileIconOptions {
  GetFileIconOptions();
  ~GetFileIconOptions();
  GetFileIconOptions(GetFileIconOptions&& rhs);
  GetFileIconOptions& operator=(GetFileIconOptions&& rhs);

  // Populates a GetFileIconOptions object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, GetFileIconOptions* out);

  // Creates a GetFileIconOptions object from a base::Value, or NULL on failure.
  static std::unique_ptr<GetFileIconOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this GetFileIconOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The size of the returned icon. The icon will be square with dimensions size *
  // size pixels. The default and largest size for the icon is 32x32 pixels. The
  // only supported sizes are 16 and 32. It is an error to specify any other size.
  std::unique_ptr<int> size;


 private:
  DISALLOW_COPY_AND_ASSIGN(GetFileIconOptions);
};


//
// Functions
//

namespace Download {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // What to download and how.
  DownloadOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(int download_id);
}  // namespace Results

}  // namespace Download

namespace Search {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  DownloadQuery query;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<DownloadItem>& results);
}  // namespace Results

}  // namespace Search

namespace Pause {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the download to pause.
  int download_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Pause

namespace Resume {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the download to resume.
  int download_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Resume

namespace Cancel {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id of the download to cancel.
  int download_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace Cancel

namespace GetFileIcon {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The identifier for the download.
  int download_id;

  std::unique_ptr<GetFileIconOptions> options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& icon_url);
}  // namespace Results

}  // namespace GetFileIcon

namespace Open {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The identifier for the downloaded file.
  int download_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Open

namespace Show {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The identifier for the downloaded file.
  int download_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace Show

namespace ShowDefaultFolder {

}  // namespace ShowDefaultFolder

namespace Erase {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  DownloadQuery query;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<int>& erased_ids);
}  // namespace Results

}  // namespace Erase

namespace RemoveFile {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  int download_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveFile

namespace AcceptDanger {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The identifier for the $(ref:DownloadItem).
  int download_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace AcceptDanger

namespace SetShelfEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetShelfEnabled

//
// Events
//

namespace OnCreated {

extern const char kEventName[];  // "downloads.onCreated"

std::unique_ptr<base::ListValue> Create(const DownloadItem& download_item);
}  // namespace OnCreated

namespace OnErased {

extern const char kEventName[];  // "downloads.onErased"

// The <code>id</code> of the $(ref:DownloadItem) that was erased.
std::unique_ptr<base::ListValue> Create(int download_id);
}  // namespace OnErased

namespace OnChanged {

extern const char kEventName[];  // "downloads.onChanged"

std::unique_ptr<base::ListValue> Create(const DownloadDelta& download_delta);
}  // namespace OnChanged

namespace OnDeterminingFilename {

extern const char kEventName[];  // "downloads.onDeterminingFilename"

std::unique_ptr<base::ListValue> Create(const DownloadItem& download_item);
}  // namespace OnDeterminingFilename

}  // namespace downloads
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_DOWNLOADS_H__
