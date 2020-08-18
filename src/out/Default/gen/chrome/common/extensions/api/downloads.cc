// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/downloads.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/downloads.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace downloads {
//
// Types
//

HeaderNameValuePair::HeaderNameValuePair()
 {}

HeaderNameValuePair::~HeaderNameValuePair() {}
HeaderNameValuePair::HeaderNameValuePair(HeaderNameValuePair&& rhs)
: name(std::move(rhs.name)),
value(std::move(rhs.value)){
}

HeaderNameValuePair& HeaderNameValuePair::operator=(HeaderNameValuePair&& rhs)
{
name = std::move(rhs.name);
value = std::move(rhs.value);
return *this;
}

// static
bool HeaderNameValuePair::Populate(
    const base::Value& value, HeaderNameValuePair* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    return false;
  }
  {
    if (!value_value->GetAsString(&out->value)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<HeaderNameValuePair> HeaderNameValuePair::FromValue(const base::Value& value) {
  std::unique_ptr<HeaderNameValuePair> out(new HeaderNameValuePair());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HeaderNameValuePair::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));


  return to_value_result;
}


const char* ToString(FilenameConflictAction enum_param) {
  switch (enum_param) {
    case FILENAME_CONFLICT_ACTION_UNIQUIFY:
      return "uniquify";
    case FILENAME_CONFLICT_ACTION_OVERWRITE:
      return "overwrite";
    case FILENAME_CONFLICT_ACTION_PROMPT:
      return "prompt";
    case FILENAME_CONFLICT_ACTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FilenameConflictAction ParseFilenameConflictAction(const std::string& enum_string) {
  if (enum_string == "uniquify")
    return FILENAME_CONFLICT_ACTION_UNIQUIFY;
  if (enum_string == "overwrite")
    return FILENAME_CONFLICT_ACTION_OVERWRITE;
  if (enum_string == "prompt")
    return FILENAME_CONFLICT_ACTION_PROMPT;
  return FILENAME_CONFLICT_ACTION_NONE;
}


FilenameSuggestion::FilenameSuggestion()
: conflict_action(FILENAME_CONFLICT_ACTION_NONE) {}

FilenameSuggestion::~FilenameSuggestion() {}
FilenameSuggestion::FilenameSuggestion(FilenameSuggestion&& rhs)
: filename(std::move(rhs.filename)),
conflict_action(rhs.conflict_action){
}

FilenameSuggestion& FilenameSuggestion::operator=(FilenameSuggestion&& rhs)
{
filename = std::move(rhs.filename);
conflict_action = rhs.conflict_action;
return *this;
}

// static
bool FilenameSuggestion::Populate(
    const base::Value& value, FilenameSuggestion* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->conflict_action = FILENAME_CONFLICT_ACTION_NONE;
  const base::Value* filename_value = NULL;
  if (!dict->GetWithoutPathExpansion("filename", &filename_value)) {
    return false;
  }
  {
    if (!filename_value->GetAsString(&out->filename)) {
      return false;
    }
  }

  const base::Value* conflict_action_value = NULL;
  if (dict->GetWithoutPathExpansion("conflictAction", &conflict_action_value)) {
    {
      std::string filename_conflict_action_as_string;
      if (!conflict_action_value->GetAsString(&filename_conflict_action_as_string)) {
        return false;
      }
      out->conflict_action = ParseFilenameConflictAction(filename_conflict_action_as_string);
      if (out->conflict_action == FILENAME_CONFLICT_ACTION_NONE) {
        return false;
      }
    }
    } else {
    out->conflict_action = FILENAME_CONFLICT_ACTION_NONE;
  }

  return true;
}

// static
std::unique_ptr<FilenameSuggestion> FilenameSuggestion::FromValue(const base::Value& value) {
  std::unique_ptr<FilenameSuggestion> out(new FilenameSuggestion());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FilenameSuggestion::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("filename", std::make_unique<base::Value>(this->filename));

  if (this->conflict_action != FILENAME_CONFLICT_ACTION_NONE) {
    to_value_result->SetWithoutPathExpansion("conflictAction", std::make_unique<base::Value>(downloads::ToString(this->conflict_action)));

  }

  return to_value_result;
}


const char* ToString(HttpMethod enum_param) {
  switch (enum_param) {
    case HTTP_METHOD_GET:
      return "GET";
    case HTTP_METHOD_POST:
      return "POST";
    case HTTP_METHOD_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

HttpMethod ParseHttpMethod(const std::string& enum_string) {
  if (enum_string == "GET")
    return HTTP_METHOD_GET;
  if (enum_string == "POST")
    return HTTP_METHOD_POST;
  return HTTP_METHOD_NONE;
}


const char* ToString(InterruptReason enum_param) {
  switch (enum_param) {
    case INTERRUPT_REASON_FILE_FAILED:
      return "FILE_FAILED";
    case INTERRUPT_REASON_FILE_ACCESS_DENIED:
      return "FILE_ACCESS_DENIED";
    case INTERRUPT_REASON_FILE_NO_SPACE:
      return "FILE_NO_SPACE";
    case INTERRUPT_REASON_FILE_NAME_TOO_LONG:
      return "FILE_NAME_TOO_LONG";
    case INTERRUPT_REASON_FILE_TOO_LARGE:
      return "FILE_TOO_LARGE";
    case INTERRUPT_REASON_FILE_VIRUS_INFECTED:
      return "FILE_VIRUS_INFECTED";
    case INTERRUPT_REASON_FILE_TRANSIENT_ERROR:
      return "FILE_TRANSIENT_ERROR";
    case INTERRUPT_REASON_FILE_BLOCKED:
      return "FILE_BLOCKED";
    case INTERRUPT_REASON_FILE_SECURITY_CHECK_FAILED:
      return "FILE_SECURITY_CHECK_FAILED";
    case INTERRUPT_REASON_FILE_TOO_SHORT:
      return "FILE_TOO_SHORT";
    case INTERRUPT_REASON_FILE_HASH_MISMATCH:
      return "FILE_HASH_MISMATCH";
    case INTERRUPT_REASON_FILE_SAME_AS_SOURCE:
      return "FILE_SAME_AS_SOURCE";
    case INTERRUPT_REASON_NETWORK_FAILED:
      return "NETWORK_FAILED";
    case INTERRUPT_REASON_NETWORK_TIMEOUT:
      return "NETWORK_TIMEOUT";
    case INTERRUPT_REASON_NETWORK_DISCONNECTED:
      return "NETWORK_DISCONNECTED";
    case INTERRUPT_REASON_NETWORK_SERVER_DOWN:
      return "NETWORK_SERVER_DOWN";
    case INTERRUPT_REASON_NETWORK_INVALID_REQUEST:
      return "NETWORK_INVALID_REQUEST";
    case INTERRUPT_REASON_SERVER_FAILED:
      return "SERVER_FAILED";
    case INTERRUPT_REASON_SERVER_NO_RANGE:
      return "SERVER_NO_RANGE";
    case INTERRUPT_REASON_SERVER_BAD_CONTENT:
      return "SERVER_BAD_CONTENT";
    case INTERRUPT_REASON_SERVER_UNAUTHORIZED:
      return "SERVER_UNAUTHORIZED";
    case INTERRUPT_REASON_SERVER_CERT_PROBLEM:
      return "SERVER_CERT_PROBLEM";
    case INTERRUPT_REASON_SERVER_FORBIDDEN:
      return "SERVER_FORBIDDEN";
    case INTERRUPT_REASON_SERVER_UNREACHABLE:
      return "SERVER_UNREACHABLE";
    case INTERRUPT_REASON_SERVER_CONTENT_LENGTH_MISMATCH:
      return "SERVER_CONTENT_LENGTH_MISMATCH";
    case INTERRUPT_REASON_SERVER_CROSS_ORIGIN_REDIRECT:
      return "SERVER_CROSS_ORIGIN_REDIRECT";
    case INTERRUPT_REASON_USER_CANCELED:
      return "USER_CANCELED";
    case INTERRUPT_REASON_USER_SHUTDOWN:
      return "USER_SHUTDOWN";
    case INTERRUPT_REASON_CRASH:
      return "CRASH";
    case INTERRUPT_REASON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

InterruptReason ParseInterruptReason(const std::string& enum_string) {
  if (enum_string == "FILE_FAILED")
    return INTERRUPT_REASON_FILE_FAILED;
  if (enum_string == "FILE_ACCESS_DENIED")
    return INTERRUPT_REASON_FILE_ACCESS_DENIED;
  if (enum_string == "FILE_NO_SPACE")
    return INTERRUPT_REASON_FILE_NO_SPACE;
  if (enum_string == "FILE_NAME_TOO_LONG")
    return INTERRUPT_REASON_FILE_NAME_TOO_LONG;
  if (enum_string == "FILE_TOO_LARGE")
    return INTERRUPT_REASON_FILE_TOO_LARGE;
  if (enum_string == "FILE_VIRUS_INFECTED")
    return INTERRUPT_REASON_FILE_VIRUS_INFECTED;
  if (enum_string == "FILE_TRANSIENT_ERROR")
    return INTERRUPT_REASON_FILE_TRANSIENT_ERROR;
  if (enum_string == "FILE_BLOCKED")
    return INTERRUPT_REASON_FILE_BLOCKED;
  if (enum_string == "FILE_SECURITY_CHECK_FAILED")
    return INTERRUPT_REASON_FILE_SECURITY_CHECK_FAILED;
  if (enum_string == "FILE_TOO_SHORT")
    return INTERRUPT_REASON_FILE_TOO_SHORT;
  if (enum_string == "FILE_HASH_MISMATCH")
    return INTERRUPT_REASON_FILE_HASH_MISMATCH;
  if (enum_string == "FILE_SAME_AS_SOURCE")
    return INTERRUPT_REASON_FILE_SAME_AS_SOURCE;
  if (enum_string == "NETWORK_FAILED")
    return INTERRUPT_REASON_NETWORK_FAILED;
  if (enum_string == "NETWORK_TIMEOUT")
    return INTERRUPT_REASON_NETWORK_TIMEOUT;
  if (enum_string == "NETWORK_DISCONNECTED")
    return INTERRUPT_REASON_NETWORK_DISCONNECTED;
  if (enum_string == "NETWORK_SERVER_DOWN")
    return INTERRUPT_REASON_NETWORK_SERVER_DOWN;
  if (enum_string == "NETWORK_INVALID_REQUEST")
    return INTERRUPT_REASON_NETWORK_INVALID_REQUEST;
  if (enum_string == "SERVER_FAILED")
    return INTERRUPT_REASON_SERVER_FAILED;
  if (enum_string == "SERVER_NO_RANGE")
    return INTERRUPT_REASON_SERVER_NO_RANGE;
  if (enum_string == "SERVER_BAD_CONTENT")
    return INTERRUPT_REASON_SERVER_BAD_CONTENT;
  if (enum_string == "SERVER_UNAUTHORIZED")
    return INTERRUPT_REASON_SERVER_UNAUTHORIZED;
  if (enum_string == "SERVER_CERT_PROBLEM")
    return INTERRUPT_REASON_SERVER_CERT_PROBLEM;
  if (enum_string == "SERVER_FORBIDDEN")
    return INTERRUPT_REASON_SERVER_FORBIDDEN;
  if (enum_string == "SERVER_UNREACHABLE")
    return INTERRUPT_REASON_SERVER_UNREACHABLE;
  if (enum_string == "SERVER_CONTENT_LENGTH_MISMATCH")
    return INTERRUPT_REASON_SERVER_CONTENT_LENGTH_MISMATCH;
  if (enum_string == "SERVER_CROSS_ORIGIN_REDIRECT")
    return INTERRUPT_REASON_SERVER_CROSS_ORIGIN_REDIRECT;
  if (enum_string == "USER_CANCELED")
    return INTERRUPT_REASON_USER_CANCELED;
  if (enum_string == "USER_SHUTDOWN")
    return INTERRUPT_REASON_USER_SHUTDOWN;
  if (enum_string == "CRASH")
    return INTERRUPT_REASON_CRASH;
  return INTERRUPT_REASON_NONE;
}


DownloadOptions::DownloadOptions()
: conflict_action(FILENAME_CONFLICT_ACTION_NONE),
method(HTTP_METHOD_NONE) {}

DownloadOptions::~DownloadOptions() {}
DownloadOptions::DownloadOptions(DownloadOptions&& rhs)
: url(std::move(rhs.url)),
filename(std::move(rhs.filename)),
conflict_action(rhs.conflict_action),
save_as(std::move(rhs.save_as)),
method(rhs.method),
headers(std::move(rhs.headers)),
body(std::move(rhs.body)){
}

DownloadOptions& DownloadOptions::operator=(DownloadOptions&& rhs)
{
url = std::move(rhs.url);
filename = std::move(rhs.filename);
conflict_action = rhs.conflict_action;
save_as = std::move(rhs.save_as);
method = rhs.method;
headers = std::move(rhs.headers);
body = std::move(rhs.body);
return *this;
}

// static
bool DownloadOptions::Populate(
    const base::Value& value, DownloadOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->conflict_action = FILENAME_CONFLICT_ACTION_NONE;
  out->method = HTTP_METHOD_NONE;
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* filename_value = NULL;
  if (dict->GetWithoutPathExpansion("filename", &filename_value)) {
    {
      std::string temp;
      if (!filename_value->GetAsString(&temp)) {
        out->filename.reset();
        return false;
      }
      else
        out->filename.reset(new std::string(temp));
    }
  }

  const base::Value* conflict_action_value = NULL;
  if (dict->GetWithoutPathExpansion("conflictAction", &conflict_action_value)) {
    {
      std::string filename_conflict_action_as_string;
      if (!conflict_action_value->GetAsString(&filename_conflict_action_as_string)) {
        return false;
      }
      out->conflict_action = ParseFilenameConflictAction(filename_conflict_action_as_string);
      if (out->conflict_action == FILENAME_CONFLICT_ACTION_NONE) {
        return false;
      }
    }
    } else {
    out->conflict_action = FILENAME_CONFLICT_ACTION_NONE;
  }

  const base::Value* save_as_value = NULL;
  if (dict->GetWithoutPathExpansion("saveAs", &save_as_value)) {
    {
      bool temp;
      if (!save_as_value->GetAsBoolean(&temp)) {
        out->save_as.reset();
        return false;
      }
      else
        out->save_as.reset(new bool(temp));
    }
  }

  const base::Value* method_value = NULL;
  if (dict->GetWithoutPathExpansion("method", &method_value)) {
    {
      std::string http_method_as_string;
      if (!method_value->GetAsString(&http_method_as_string)) {
        return false;
      }
      out->method = ParseHttpMethod(http_method_as_string);
      if (out->method == HTTP_METHOD_NONE) {
        return false;
      }
    }
    } else {
    out->method = HTTP_METHOD_NONE;
  }

  const base::Value* headers_value = NULL;
  if (dict->GetWithoutPathExpansion("headers", &headers_value)) {
    {
      const base::ListValue* list = NULL;
      if (!headers_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->headers)) {
          return false;
        }
      }
    }
  }

  const base::Value* body_value = NULL;
  if (dict->GetWithoutPathExpansion("body", &body_value)) {
    {
      std::string temp;
      if (!body_value->GetAsString(&temp)) {
        out->body.reset();
        return false;
      }
      else
        out->body.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DownloadOptions> DownloadOptions::FromValue(const base::Value& value) {
  std::unique_ptr<DownloadOptions> out(new DownloadOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DownloadOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  if (this->filename.get()) {
    to_value_result->SetWithoutPathExpansion("filename", std::make_unique<base::Value>(*this->filename));

  }
  if (this->conflict_action != FILENAME_CONFLICT_ACTION_NONE) {
    to_value_result->SetWithoutPathExpansion("conflictAction", std::make_unique<base::Value>(downloads::ToString(this->conflict_action)));

  }
  if (this->save_as.get()) {
    to_value_result->SetWithoutPathExpansion("saveAs", std::make_unique<base::Value>(*this->save_as));

  }
  if (this->method != HTTP_METHOD_NONE) {
    to_value_result->SetWithoutPathExpansion("method", std::make_unique<base::Value>(downloads::ToString(this->method)));

  }
  if (this->headers.get()) {
    to_value_result->SetWithoutPathExpansion("headers", json_schema_compiler::util::CreateValueFromOptionalArray(this->headers));

  }
  if (this->body.get()) {
    to_value_result->SetWithoutPathExpansion("body", std::make_unique<base::Value>(*this->body));

  }

  return to_value_result;
}


const char* ToString(DangerType enum_param) {
  switch (enum_param) {
    case DANGER_TYPE_FILE:
      return "file";
    case DANGER_TYPE_URL:
      return "url";
    case DANGER_TYPE_CONTENT:
      return "content";
    case DANGER_TYPE_UNCOMMON:
      return "uncommon";
    case DANGER_TYPE_HOST:
      return "host";
    case DANGER_TYPE_UNWANTED:
      return "unwanted";
    case DANGER_TYPE_SAFE:
      return "safe";
    case DANGER_TYPE_ACCEPTED:
      return "accepted";
    case DANGER_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DangerType ParseDangerType(const std::string& enum_string) {
  if (enum_string == "file")
    return DANGER_TYPE_FILE;
  if (enum_string == "url")
    return DANGER_TYPE_URL;
  if (enum_string == "content")
    return DANGER_TYPE_CONTENT;
  if (enum_string == "uncommon")
    return DANGER_TYPE_UNCOMMON;
  if (enum_string == "host")
    return DANGER_TYPE_HOST;
  if (enum_string == "unwanted")
    return DANGER_TYPE_UNWANTED;
  if (enum_string == "safe")
    return DANGER_TYPE_SAFE;
  if (enum_string == "accepted")
    return DANGER_TYPE_ACCEPTED;
  return DANGER_TYPE_NONE;
}


const char* ToString(State enum_param) {
  switch (enum_param) {
    case STATE_IN_PROGRESS:
      return "in_progress";
    case STATE_INTERRUPTED:
      return "interrupted";
    case STATE_COMPLETE:
      return "complete";
    case STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

State ParseState(const std::string& enum_string) {
  if (enum_string == "in_progress")
    return STATE_IN_PROGRESS;
  if (enum_string == "interrupted")
    return STATE_INTERRUPTED;
  if (enum_string == "complete")
    return STATE_COMPLETE;
  return STATE_NONE;
}


DownloadItem::DownloadItem()
: id(0),
incognito(false),
danger(DANGER_TYPE_NONE),
state(STATE_NONE),
paused(false),
can_resume(false),
error(INTERRUPT_REASON_NONE),
bytes_received(0.0),
total_bytes(0.0),
file_size(0.0),
exists(false) {}

DownloadItem::~DownloadItem() {}
DownloadItem::DownloadItem(DownloadItem&& rhs)
: id(rhs.id),
url(std::move(rhs.url)),
final_url(std::move(rhs.final_url)),
referrer(std::move(rhs.referrer)),
filename(std::move(rhs.filename)),
incognito(rhs.incognito),
danger(rhs.danger),
mime(std::move(rhs.mime)),
start_time(std::move(rhs.start_time)),
end_time(std::move(rhs.end_time)),
estimated_end_time(std::move(rhs.estimated_end_time)),
state(rhs.state),
paused(rhs.paused),
can_resume(rhs.can_resume),
error(rhs.error),
bytes_received(rhs.bytes_received),
total_bytes(rhs.total_bytes),
file_size(rhs.file_size),
exists(rhs.exists),
by_extension_id(std::move(rhs.by_extension_id)),
by_extension_name(std::move(rhs.by_extension_name)){
}

DownloadItem& DownloadItem::operator=(DownloadItem&& rhs)
{
id = rhs.id;
url = std::move(rhs.url);
final_url = std::move(rhs.final_url);
referrer = std::move(rhs.referrer);
filename = std::move(rhs.filename);
incognito = rhs.incognito;
danger = rhs.danger;
mime = std::move(rhs.mime);
start_time = std::move(rhs.start_time);
end_time = std::move(rhs.end_time);
estimated_end_time = std::move(rhs.estimated_end_time);
state = rhs.state;
paused = rhs.paused;
can_resume = rhs.can_resume;
error = rhs.error;
bytes_received = rhs.bytes_received;
total_bytes = rhs.total_bytes;
file_size = rhs.file_size;
exists = rhs.exists;
by_extension_id = std::move(rhs.by_extension_id);
by_extension_name = std::move(rhs.by_extension_name);
return *this;
}

// static
bool DownloadItem::Populate(
    const base::Value& value, DownloadItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->error = INTERRUPT_REASON_NONE;
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* final_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("finalUrl", &final_url_value)) {
    return false;
  }
  {
    if (!final_url_value->GetAsString(&out->final_url)) {
      return false;
    }
  }

  const base::Value* referrer_value = NULL;
  if (!dict->GetWithoutPathExpansion("referrer", &referrer_value)) {
    return false;
  }
  {
    if (!referrer_value->GetAsString(&out->referrer)) {
      return false;
    }
  }

  const base::Value* filename_value = NULL;
  if (!dict->GetWithoutPathExpansion("filename", &filename_value)) {
    return false;
  }
  {
    if (!filename_value->GetAsString(&out->filename)) {
      return false;
    }
  }

  const base::Value* incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    return false;
  }
  {
    if (!incognito_value->GetAsBoolean(&out->incognito)) {
      return false;
    }
  }

  const base::Value* danger_value = NULL;
  if (!dict->GetWithoutPathExpansion("danger", &danger_value)) {
    return false;
  }
  {
    std::string danger_type_as_string;
    if (!danger_value->GetAsString(&danger_type_as_string)) {
      return false;
    }
    out->danger = ParseDangerType(danger_type_as_string);
    if (out->danger == DANGER_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* mime_value = NULL;
  if (!dict->GetWithoutPathExpansion("mime", &mime_value)) {
    return false;
  }
  {
    if (!mime_value->GetAsString(&out->mime)) {
      return false;
    }
  }

  const base::Value* start_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("startTime", &start_time_value)) {
    return false;
  }
  {
    if (!start_time_value->GetAsString(&out->start_time)) {
      return false;
    }
  }

  const base::Value* end_time_value = NULL;
  if (dict->GetWithoutPathExpansion("endTime", &end_time_value)) {
    {
      std::string temp;
      if (!end_time_value->GetAsString(&temp)) {
        out->end_time.reset();
        return false;
      }
      else
        out->end_time.reset(new std::string(temp));
    }
  }

  const base::Value* estimated_end_time_value = NULL;
  if (dict->GetWithoutPathExpansion("estimatedEndTime", &estimated_end_time_value)) {
    {
      std::string temp;
      if (!estimated_end_time_value->GetAsString(&temp)) {
        out->estimated_end_time.reset();
        return false;
      }
      else
        out->estimated_end_time.reset(new std::string(temp));
    }
  }

  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("state", &state_value)) {
    return false;
  }
  {
    std::string state_as_string;
    if (!state_value->GetAsString(&state_as_string)) {
      return false;
    }
    out->state = ParseState(state_as_string);
    if (out->state == STATE_NONE) {
      return false;
    }
  }

  const base::Value* paused_value = NULL;
  if (!dict->GetWithoutPathExpansion("paused", &paused_value)) {
    return false;
  }
  {
    if (!paused_value->GetAsBoolean(&out->paused)) {
      return false;
    }
  }

  const base::Value* can_resume_value = NULL;
  if (!dict->GetWithoutPathExpansion("canResume", &can_resume_value)) {
    return false;
  }
  {
    if (!can_resume_value->GetAsBoolean(&out->can_resume)) {
      return false;
    }
  }

  const base::Value* error_value = NULL;
  if (dict->GetWithoutPathExpansion("error", &error_value)) {
    {
      std::string interrupt_reason_as_string;
      if (!error_value->GetAsString(&interrupt_reason_as_string)) {
        return false;
      }
      out->error = ParseInterruptReason(interrupt_reason_as_string);
      if (out->error == INTERRUPT_REASON_NONE) {
        return false;
      }
    }
    } else {
    out->error = INTERRUPT_REASON_NONE;
  }

  const base::Value* bytes_received_value = NULL;
  if (!dict->GetWithoutPathExpansion("bytesReceived", &bytes_received_value)) {
    return false;
  }
  {
    if (!bytes_received_value->GetAsDouble(&out->bytes_received)) {
      return false;
    }
  }

  const base::Value* total_bytes_value = NULL;
  if (!dict->GetWithoutPathExpansion("totalBytes", &total_bytes_value)) {
    return false;
  }
  {
    if (!total_bytes_value->GetAsDouble(&out->total_bytes)) {
      return false;
    }
  }

  const base::Value* file_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("fileSize", &file_size_value)) {
    return false;
  }
  {
    if (!file_size_value->GetAsDouble(&out->file_size)) {
      return false;
    }
  }

  const base::Value* exists_value = NULL;
  if (!dict->GetWithoutPathExpansion("exists", &exists_value)) {
    return false;
  }
  {
    if (!exists_value->GetAsBoolean(&out->exists)) {
      return false;
    }
  }

  const base::Value* by_extension_id_value = NULL;
  if (dict->GetWithoutPathExpansion("byExtensionId", &by_extension_id_value)) {
    {
      std::string temp;
      if (!by_extension_id_value->GetAsString(&temp)) {
        out->by_extension_id.reset();
        return false;
      }
      else
        out->by_extension_id.reset(new std::string(temp));
    }
  }

  const base::Value* by_extension_name_value = NULL;
  if (dict->GetWithoutPathExpansion("byExtensionName", &by_extension_name_value)) {
    {
      std::string temp;
      if (!by_extension_name_value->GetAsString(&temp)) {
        out->by_extension_name.reset();
        return false;
      }
      else
        out->by_extension_name.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DownloadItem> DownloadItem::FromValue(const base::Value& value) {
  std::unique_ptr<DownloadItem> out(new DownloadItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DownloadItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("finalUrl", std::make_unique<base::Value>(this->final_url));

  to_value_result->SetWithoutPathExpansion("referrer", std::make_unique<base::Value>(this->referrer));

  to_value_result->SetWithoutPathExpansion("filename", std::make_unique<base::Value>(this->filename));

  to_value_result->SetWithoutPathExpansion("incognito", std::make_unique<base::Value>(this->incognito));

  to_value_result->SetWithoutPathExpansion("danger", std::make_unique<base::Value>(downloads::ToString(this->danger)));

  to_value_result->SetWithoutPathExpansion("mime", std::make_unique<base::Value>(this->mime));

  to_value_result->SetWithoutPathExpansion("startTime", std::make_unique<base::Value>(this->start_time));

  if (this->end_time.get()) {
    to_value_result->SetWithoutPathExpansion("endTime", std::make_unique<base::Value>(*this->end_time));

  }
  if (this->estimated_end_time.get()) {
    to_value_result->SetWithoutPathExpansion("estimatedEndTime", std::make_unique<base::Value>(*this->estimated_end_time));

  }
  to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(downloads::ToString(this->state)));

  to_value_result->SetWithoutPathExpansion("paused", std::make_unique<base::Value>(this->paused));

  to_value_result->SetWithoutPathExpansion("canResume", std::make_unique<base::Value>(this->can_resume));

  if (this->error != INTERRUPT_REASON_NONE) {
    to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(downloads::ToString(this->error)));

  }
  to_value_result->SetWithoutPathExpansion("bytesReceived", std::make_unique<base::Value>(this->bytes_received));

  to_value_result->SetWithoutPathExpansion("totalBytes", std::make_unique<base::Value>(this->total_bytes));

  to_value_result->SetWithoutPathExpansion("fileSize", std::make_unique<base::Value>(this->file_size));

  to_value_result->SetWithoutPathExpansion("exists", std::make_unique<base::Value>(this->exists));

  if (this->by_extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("byExtensionId", std::make_unique<base::Value>(*this->by_extension_id));

  }
  if (this->by_extension_name.get()) {
    to_value_result->SetWithoutPathExpansion("byExtensionName", std::make_unique<base::Value>(*this->by_extension_name));

  }

  return to_value_result;
}


DownloadQuery::DownloadQuery()
: danger(DANGER_TYPE_NONE),
state(STATE_NONE),
error(INTERRUPT_REASON_NONE) {}

DownloadQuery::~DownloadQuery() {}
DownloadQuery::DownloadQuery(DownloadQuery&& rhs)
: query(std::move(rhs.query)),
started_before(std::move(rhs.started_before)),
started_after(std::move(rhs.started_after)),
ended_before(std::move(rhs.ended_before)),
ended_after(std::move(rhs.ended_after)),
total_bytes_greater(std::move(rhs.total_bytes_greater)),
total_bytes_less(std::move(rhs.total_bytes_less)),
filename_regex(std::move(rhs.filename_regex)),
url_regex(std::move(rhs.url_regex)),
final_url_regex(std::move(rhs.final_url_regex)),
limit(std::move(rhs.limit)),
order_by(std::move(rhs.order_by)),
id(std::move(rhs.id)),
url(std::move(rhs.url)),
final_url(std::move(rhs.final_url)),
filename(std::move(rhs.filename)),
danger(rhs.danger),
mime(std::move(rhs.mime)),
start_time(std::move(rhs.start_time)),
end_time(std::move(rhs.end_time)),
state(rhs.state),
paused(std::move(rhs.paused)),
error(rhs.error),
bytes_received(std::move(rhs.bytes_received)),
total_bytes(std::move(rhs.total_bytes)),
file_size(std::move(rhs.file_size)),
exists(std::move(rhs.exists)){
}

DownloadQuery& DownloadQuery::operator=(DownloadQuery&& rhs)
{
query = std::move(rhs.query);
started_before = std::move(rhs.started_before);
started_after = std::move(rhs.started_after);
ended_before = std::move(rhs.ended_before);
ended_after = std::move(rhs.ended_after);
total_bytes_greater = std::move(rhs.total_bytes_greater);
total_bytes_less = std::move(rhs.total_bytes_less);
filename_regex = std::move(rhs.filename_regex);
url_regex = std::move(rhs.url_regex);
final_url_regex = std::move(rhs.final_url_regex);
limit = std::move(rhs.limit);
order_by = std::move(rhs.order_by);
id = std::move(rhs.id);
url = std::move(rhs.url);
final_url = std::move(rhs.final_url);
filename = std::move(rhs.filename);
danger = rhs.danger;
mime = std::move(rhs.mime);
start_time = std::move(rhs.start_time);
end_time = std::move(rhs.end_time);
state = rhs.state;
paused = std::move(rhs.paused);
error = rhs.error;
bytes_received = std::move(rhs.bytes_received);
total_bytes = std::move(rhs.total_bytes);
file_size = std::move(rhs.file_size);
exists = std::move(rhs.exists);
return *this;
}

// static
bool DownloadQuery::Populate(
    const base::Value& value, DownloadQuery* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->danger = DANGER_TYPE_NONE;
  out->state = STATE_NONE;
  out->error = INTERRUPT_REASON_NONE;
  const base::Value* query_value = NULL;
  if (dict->GetWithoutPathExpansion("query", &query_value)) {
    {
      const base::ListValue* list = NULL;
      if (!query_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->query)) {
          return false;
        }
      }
    }
  }

  const base::Value* started_before_value = NULL;
  if (dict->GetWithoutPathExpansion("startedBefore", &started_before_value)) {
    {
      std::string temp;
      if (!started_before_value->GetAsString(&temp)) {
        out->started_before.reset();
        return false;
      }
      else
        out->started_before.reset(new std::string(temp));
    }
  }

  const base::Value* started_after_value = NULL;
  if (dict->GetWithoutPathExpansion("startedAfter", &started_after_value)) {
    {
      std::string temp;
      if (!started_after_value->GetAsString(&temp)) {
        out->started_after.reset();
        return false;
      }
      else
        out->started_after.reset(new std::string(temp));
    }
  }

  const base::Value* ended_before_value = NULL;
  if (dict->GetWithoutPathExpansion("endedBefore", &ended_before_value)) {
    {
      std::string temp;
      if (!ended_before_value->GetAsString(&temp)) {
        out->ended_before.reset();
        return false;
      }
      else
        out->ended_before.reset(new std::string(temp));
    }
  }

  const base::Value* ended_after_value = NULL;
  if (dict->GetWithoutPathExpansion("endedAfter", &ended_after_value)) {
    {
      std::string temp;
      if (!ended_after_value->GetAsString(&temp)) {
        out->ended_after.reset();
        return false;
      }
      else
        out->ended_after.reset(new std::string(temp));
    }
  }

  const base::Value* total_bytes_greater_value = NULL;
  if (dict->GetWithoutPathExpansion("totalBytesGreater", &total_bytes_greater_value)) {
    {
      double temp;
      if (!total_bytes_greater_value->GetAsDouble(&temp)) {
        out->total_bytes_greater.reset();
        return false;
      }
      else
        out->total_bytes_greater.reset(new double(temp));
    }
  }

  const base::Value* total_bytes_less_value = NULL;
  if (dict->GetWithoutPathExpansion("totalBytesLess", &total_bytes_less_value)) {
    {
      double temp;
      if (!total_bytes_less_value->GetAsDouble(&temp)) {
        out->total_bytes_less.reset();
        return false;
      }
      else
        out->total_bytes_less.reset(new double(temp));
    }
  }

  const base::Value* filename_regex_value = NULL;
  if (dict->GetWithoutPathExpansion("filenameRegex", &filename_regex_value)) {
    {
      std::string temp;
      if (!filename_regex_value->GetAsString(&temp)) {
        out->filename_regex.reset();
        return false;
      }
      else
        out->filename_regex.reset(new std::string(temp));
    }
  }

  const base::Value* url_regex_value = NULL;
  if (dict->GetWithoutPathExpansion("urlRegex", &url_regex_value)) {
    {
      std::string temp;
      if (!url_regex_value->GetAsString(&temp)) {
        out->url_regex.reset();
        return false;
      }
      else
        out->url_regex.reset(new std::string(temp));
    }
  }

  const base::Value* final_url_regex_value = NULL;
  if (dict->GetWithoutPathExpansion("finalUrlRegex", &final_url_regex_value)) {
    {
      std::string temp;
      if (!final_url_regex_value->GetAsString(&temp)) {
        out->final_url_regex.reset();
        return false;
      }
      else
        out->final_url_regex.reset(new std::string(temp));
    }
  }

  const base::Value* limit_value = NULL;
  if (dict->GetWithoutPathExpansion("limit", &limit_value)) {
    {
      int temp;
      if (!limit_value->GetAsInteger(&temp)) {
        out->limit.reset();
        return false;
      }
      else
        out->limit.reset(new int(temp));
    }
  }

  const base::Value* order_by_value = NULL;
  if (dict->GetWithoutPathExpansion("orderBy", &order_by_value)) {
    {
      const base::ListValue* list = NULL;
      if (!order_by_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->order_by)) {
          return false;
        }
      }
    }
  }

  const base::Value* id_value = NULL;
  if (dict->GetWithoutPathExpansion("id", &id_value)) {
    {
      int temp;
      if (!id_value->GetAsInteger(&temp)) {
        out->id.reset();
        return false;
      }
      else
        out->id.reset(new int(temp));
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
    }
  }

  const base::Value* final_url_value = NULL;
  if (dict->GetWithoutPathExpansion("finalUrl", &final_url_value)) {
    {
      std::string temp;
      if (!final_url_value->GetAsString(&temp)) {
        out->final_url.reset();
        return false;
      }
      else
        out->final_url.reset(new std::string(temp));
    }
  }

  const base::Value* filename_value = NULL;
  if (dict->GetWithoutPathExpansion("filename", &filename_value)) {
    {
      std::string temp;
      if (!filename_value->GetAsString(&temp)) {
        out->filename.reset();
        return false;
      }
      else
        out->filename.reset(new std::string(temp));
    }
  }

  const base::Value* danger_value = NULL;
  if (dict->GetWithoutPathExpansion("danger", &danger_value)) {
    {
      std::string danger_type_as_string;
      if (!danger_value->GetAsString(&danger_type_as_string)) {
        return false;
      }
      out->danger = ParseDangerType(danger_type_as_string);
      if (out->danger == DANGER_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->danger = DANGER_TYPE_NONE;
  }

  const base::Value* mime_value = NULL;
  if (dict->GetWithoutPathExpansion("mime", &mime_value)) {
    {
      std::string temp;
      if (!mime_value->GetAsString(&temp)) {
        out->mime.reset();
        return false;
      }
      else
        out->mime.reset(new std::string(temp));
    }
  }

  const base::Value* start_time_value = NULL;
  if (dict->GetWithoutPathExpansion("startTime", &start_time_value)) {
    {
      std::string temp;
      if (!start_time_value->GetAsString(&temp)) {
        out->start_time.reset();
        return false;
      }
      else
        out->start_time.reset(new std::string(temp));
    }
  }

  const base::Value* end_time_value = NULL;
  if (dict->GetWithoutPathExpansion("endTime", &end_time_value)) {
    {
      std::string temp;
      if (!end_time_value->GetAsString(&temp)) {
        out->end_time.reset();
        return false;
      }
      else
        out->end_time.reset(new std::string(temp));
    }
  }

  const base::Value* state_value = NULL;
  if (dict->GetWithoutPathExpansion("state", &state_value)) {
    {
      std::string state_as_string;
      if (!state_value->GetAsString(&state_as_string)) {
        return false;
      }
      out->state = ParseState(state_as_string);
      if (out->state == STATE_NONE) {
        return false;
      }
    }
    } else {
    out->state = STATE_NONE;
  }

  const base::Value* paused_value = NULL;
  if (dict->GetWithoutPathExpansion("paused", &paused_value)) {
    {
      bool temp;
      if (!paused_value->GetAsBoolean(&temp)) {
        out->paused.reset();
        return false;
      }
      else
        out->paused.reset(new bool(temp));
    }
  }

  const base::Value* error_value = NULL;
  if (dict->GetWithoutPathExpansion("error", &error_value)) {
    {
      std::string interrupt_reason_as_string;
      if (!error_value->GetAsString(&interrupt_reason_as_string)) {
        return false;
      }
      out->error = ParseInterruptReason(interrupt_reason_as_string);
      if (out->error == INTERRUPT_REASON_NONE) {
        return false;
      }
    }
    } else {
    out->error = INTERRUPT_REASON_NONE;
  }

  const base::Value* bytes_received_value = NULL;
  if (dict->GetWithoutPathExpansion("bytesReceived", &bytes_received_value)) {
    {
      double temp;
      if (!bytes_received_value->GetAsDouble(&temp)) {
        out->bytes_received.reset();
        return false;
      }
      else
        out->bytes_received.reset(new double(temp));
    }
  }

  const base::Value* total_bytes_value = NULL;
  if (dict->GetWithoutPathExpansion("totalBytes", &total_bytes_value)) {
    {
      double temp;
      if (!total_bytes_value->GetAsDouble(&temp)) {
        out->total_bytes.reset();
        return false;
      }
      else
        out->total_bytes.reset(new double(temp));
    }
  }

  const base::Value* file_size_value = NULL;
  if (dict->GetWithoutPathExpansion("fileSize", &file_size_value)) {
    {
      double temp;
      if (!file_size_value->GetAsDouble(&temp)) {
        out->file_size.reset();
        return false;
      }
      else
        out->file_size.reset(new double(temp));
    }
  }

  const base::Value* exists_value = NULL;
  if (dict->GetWithoutPathExpansion("exists", &exists_value)) {
    {
      bool temp;
      if (!exists_value->GetAsBoolean(&temp)) {
        out->exists.reset();
        return false;
      }
      else
        out->exists.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DownloadQuery> DownloadQuery::FromValue(const base::Value& value) {
  std::unique_ptr<DownloadQuery> out(new DownloadQuery());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DownloadQuery::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->query.get()) {
    to_value_result->SetWithoutPathExpansion("query", json_schema_compiler::util::CreateValueFromOptionalArray(this->query));

  }
  if (this->started_before.get()) {
    to_value_result->SetWithoutPathExpansion("startedBefore", std::make_unique<base::Value>(*this->started_before));

  }
  if (this->started_after.get()) {
    to_value_result->SetWithoutPathExpansion("startedAfter", std::make_unique<base::Value>(*this->started_after));

  }
  if (this->ended_before.get()) {
    to_value_result->SetWithoutPathExpansion("endedBefore", std::make_unique<base::Value>(*this->ended_before));

  }
  if (this->ended_after.get()) {
    to_value_result->SetWithoutPathExpansion("endedAfter", std::make_unique<base::Value>(*this->ended_after));

  }
  if (this->total_bytes_greater.get()) {
    to_value_result->SetWithoutPathExpansion("totalBytesGreater", std::make_unique<base::Value>(*this->total_bytes_greater));

  }
  if (this->total_bytes_less.get()) {
    to_value_result->SetWithoutPathExpansion("totalBytesLess", std::make_unique<base::Value>(*this->total_bytes_less));

  }
  if (this->filename_regex.get()) {
    to_value_result->SetWithoutPathExpansion("filenameRegex", std::make_unique<base::Value>(*this->filename_regex));

  }
  if (this->url_regex.get()) {
    to_value_result->SetWithoutPathExpansion("urlRegex", std::make_unique<base::Value>(*this->url_regex));

  }
  if (this->final_url_regex.get()) {
    to_value_result->SetWithoutPathExpansion("finalUrlRegex", std::make_unique<base::Value>(*this->final_url_regex));

  }
  if (this->limit.get()) {
    to_value_result->SetWithoutPathExpansion("limit", std::make_unique<base::Value>(*this->limit));

  }
  if (this->order_by.get()) {
    to_value_result->SetWithoutPathExpansion("orderBy", json_schema_compiler::util::CreateValueFromOptionalArray(this->order_by));

  }
  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  if (this->final_url.get()) {
    to_value_result->SetWithoutPathExpansion("finalUrl", std::make_unique<base::Value>(*this->final_url));

  }
  if (this->filename.get()) {
    to_value_result->SetWithoutPathExpansion("filename", std::make_unique<base::Value>(*this->filename));

  }
  if (this->danger != DANGER_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("danger", std::make_unique<base::Value>(downloads::ToString(this->danger)));

  }
  if (this->mime.get()) {
    to_value_result->SetWithoutPathExpansion("mime", std::make_unique<base::Value>(*this->mime));

  }
  if (this->start_time.get()) {
    to_value_result->SetWithoutPathExpansion("startTime", std::make_unique<base::Value>(*this->start_time));

  }
  if (this->end_time.get()) {
    to_value_result->SetWithoutPathExpansion("endTime", std::make_unique<base::Value>(*this->end_time));

  }
  if (this->state != STATE_NONE) {
    to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(downloads::ToString(this->state)));

  }
  if (this->paused.get()) {
    to_value_result->SetWithoutPathExpansion("paused", std::make_unique<base::Value>(*this->paused));

  }
  if (this->error != INTERRUPT_REASON_NONE) {
    to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(downloads::ToString(this->error)));

  }
  if (this->bytes_received.get()) {
    to_value_result->SetWithoutPathExpansion("bytesReceived", std::make_unique<base::Value>(*this->bytes_received));

  }
  if (this->total_bytes.get()) {
    to_value_result->SetWithoutPathExpansion("totalBytes", std::make_unique<base::Value>(*this->total_bytes));

  }
  if (this->file_size.get()) {
    to_value_result->SetWithoutPathExpansion("fileSize", std::make_unique<base::Value>(*this->file_size));

  }
  if (this->exists.get()) {
    to_value_result->SetWithoutPathExpansion("exists", std::make_unique<base::Value>(*this->exists));

  }

  return to_value_result;
}


StringDelta::StringDelta()
 {}

StringDelta::~StringDelta() {}
StringDelta::StringDelta(StringDelta&& rhs)
: previous(std::move(rhs.previous)),
current(std::move(rhs.current)){
}

StringDelta& StringDelta::operator=(StringDelta&& rhs)
{
previous = std::move(rhs.previous);
current = std::move(rhs.current);
return *this;
}

// static
bool StringDelta::Populate(
    const base::Value& value, StringDelta* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* previous_value = NULL;
  if (dict->GetWithoutPathExpansion("previous", &previous_value)) {
    {
      std::string temp;
      if (!previous_value->GetAsString(&temp)) {
        out->previous.reset();
        return false;
      }
      else
        out->previous.reset(new std::string(temp));
    }
  }

  const base::Value* current_value = NULL;
  if (dict->GetWithoutPathExpansion("current", &current_value)) {
    {
      std::string temp;
      if (!current_value->GetAsString(&temp)) {
        out->current.reset();
        return false;
      }
      else
        out->current.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<StringDelta> StringDelta::FromValue(const base::Value& value) {
  std::unique_ptr<StringDelta> out(new StringDelta());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> StringDelta::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->previous.get()) {
    to_value_result->SetWithoutPathExpansion("previous", std::make_unique<base::Value>(*this->previous));

  }
  if (this->current.get()) {
    to_value_result->SetWithoutPathExpansion("current", std::make_unique<base::Value>(*this->current));

  }

  return to_value_result;
}


DoubleDelta::DoubleDelta()
 {}

DoubleDelta::~DoubleDelta() {}
DoubleDelta::DoubleDelta(DoubleDelta&& rhs)
: previous(std::move(rhs.previous)),
current(std::move(rhs.current)){
}

DoubleDelta& DoubleDelta::operator=(DoubleDelta&& rhs)
{
previous = std::move(rhs.previous);
current = std::move(rhs.current);
return *this;
}

// static
bool DoubleDelta::Populate(
    const base::Value& value, DoubleDelta* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* previous_value = NULL;
  if (dict->GetWithoutPathExpansion("previous", &previous_value)) {
    {
      double temp;
      if (!previous_value->GetAsDouble(&temp)) {
        out->previous.reset();
        return false;
      }
      else
        out->previous.reset(new double(temp));
    }
  }

  const base::Value* current_value = NULL;
  if (dict->GetWithoutPathExpansion("current", &current_value)) {
    {
      double temp;
      if (!current_value->GetAsDouble(&temp)) {
        out->current.reset();
        return false;
      }
      else
        out->current.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DoubleDelta> DoubleDelta::FromValue(const base::Value& value) {
  std::unique_ptr<DoubleDelta> out(new DoubleDelta());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DoubleDelta::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->previous.get()) {
    to_value_result->SetWithoutPathExpansion("previous", std::make_unique<base::Value>(*this->previous));

  }
  if (this->current.get()) {
    to_value_result->SetWithoutPathExpansion("current", std::make_unique<base::Value>(*this->current));

  }

  return to_value_result;
}


BooleanDelta::BooleanDelta()
 {}

BooleanDelta::~BooleanDelta() {}
BooleanDelta::BooleanDelta(BooleanDelta&& rhs)
: previous(std::move(rhs.previous)),
current(std::move(rhs.current)){
}

BooleanDelta& BooleanDelta::operator=(BooleanDelta&& rhs)
{
previous = std::move(rhs.previous);
current = std::move(rhs.current);
return *this;
}

// static
bool BooleanDelta::Populate(
    const base::Value& value, BooleanDelta* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* previous_value = NULL;
  if (dict->GetWithoutPathExpansion("previous", &previous_value)) {
    {
      bool temp;
      if (!previous_value->GetAsBoolean(&temp)) {
        out->previous.reset();
        return false;
      }
      else
        out->previous.reset(new bool(temp));
    }
  }

  const base::Value* current_value = NULL;
  if (dict->GetWithoutPathExpansion("current", &current_value)) {
    {
      bool temp;
      if (!current_value->GetAsBoolean(&temp)) {
        out->current.reset();
        return false;
      }
      else
        out->current.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<BooleanDelta> BooleanDelta::FromValue(const base::Value& value) {
  std::unique_ptr<BooleanDelta> out(new BooleanDelta());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> BooleanDelta::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->previous.get()) {
    to_value_result->SetWithoutPathExpansion("previous", std::make_unique<base::Value>(*this->previous));

  }
  if (this->current.get()) {
    to_value_result->SetWithoutPathExpansion("current", std::make_unique<base::Value>(*this->current));

  }

  return to_value_result;
}


DownloadDelta::DownloadDelta()
: id(0) {}

DownloadDelta::~DownloadDelta() {}
DownloadDelta::DownloadDelta(DownloadDelta&& rhs)
: id(rhs.id),
url(std::move(rhs.url)),
final_url(std::move(rhs.final_url)),
filename(std::move(rhs.filename)),
danger(std::move(rhs.danger)),
mime(std::move(rhs.mime)),
start_time(std::move(rhs.start_time)),
end_time(std::move(rhs.end_time)),
state(std::move(rhs.state)),
can_resume(std::move(rhs.can_resume)),
paused(std::move(rhs.paused)),
error(std::move(rhs.error)),
total_bytes(std::move(rhs.total_bytes)),
file_size(std::move(rhs.file_size)),
exists(std::move(rhs.exists)){
}

DownloadDelta& DownloadDelta::operator=(DownloadDelta&& rhs)
{
id = rhs.id;
url = std::move(rhs.url);
final_url = std::move(rhs.final_url);
filename = std::move(rhs.filename);
danger = std::move(rhs.danger);
mime = std::move(rhs.mime);
start_time = std::move(rhs.start_time);
end_time = std::move(rhs.end_time);
state = std::move(rhs.state);
can_resume = std::move(rhs.can_resume);
paused = std::move(rhs.paused);
error = std::move(rhs.error);
total_bytes = std::move(rhs.total_bytes);
file_size = std::move(rhs.file_size);
exists = std::move(rhs.exists);
return *this;
}

// static
bool DownloadDelta::Populate(
    const base::Value& value, DownloadDelta* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!url_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->url = std::move(temp);
      }
    }
  }

  const base::Value* final_url_value = NULL;
  if (dict->GetWithoutPathExpansion("finalUrl", &final_url_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!final_url_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->final_url = std::move(temp);
      }
    }
  }

  const base::Value* filename_value = NULL;
  if (dict->GetWithoutPathExpansion("filename", &filename_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!filename_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->filename = std::move(temp);
      }
    }
  }

  const base::Value* danger_value = NULL;
  if (dict->GetWithoutPathExpansion("danger", &danger_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!danger_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->danger = std::move(temp);
      }
    }
  }

  const base::Value* mime_value = NULL;
  if (dict->GetWithoutPathExpansion("mime", &mime_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!mime_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->mime = std::move(temp);
      }
    }
  }

  const base::Value* start_time_value = NULL;
  if (dict->GetWithoutPathExpansion("startTime", &start_time_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!start_time_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->start_time = std::move(temp);
      }
    }
  }

  const base::Value* end_time_value = NULL;
  if (dict->GetWithoutPathExpansion("endTime", &end_time_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!end_time_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->end_time = std::move(temp);
      }
    }
  }

  const base::Value* state_value = NULL;
  if (dict->GetWithoutPathExpansion("state", &state_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!state_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->state = std::move(temp);
      }
    }
  }

  const base::Value* can_resume_value = NULL;
  if (dict->GetWithoutPathExpansion("canResume", &can_resume_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!can_resume_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<BooleanDelta> temp(new BooleanDelta());
        if (!BooleanDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->can_resume = std::move(temp);
      }
    }
  }

  const base::Value* paused_value = NULL;
  if (dict->GetWithoutPathExpansion("paused", &paused_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!paused_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<BooleanDelta> temp(new BooleanDelta());
        if (!BooleanDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->paused = std::move(temp);
      }
    }
  }

  const base::Value* error_value = NULL;
  if (dict->GetWithoutPathExpansion("error", &error_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!error_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<StringDelta> temp(new StringDelta());
        if (!StringDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->error = std::move(temp);
      }
    }
  }

  const base::Value* total_bytes_value = NULL;
  if (dict->GetWithoutPathExpansion("totalBytes", &total_bytes_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!total_bytes_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<DoubleDelta> temp(new DoubleDelta());
        if (!DoubleDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->total_bytes = std::move(temp);
      }
    }
  }

  const base::Value* file_size_value = NULL;
  if (dict->GetWithoutPathExpansion("fileSize", &file_size_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!file_size_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<DoubleDelta> temp(new DoubleDelta());
        if (!DoubleDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->file_size = std::move(temp);
      }
    }
  }

  const base::Value* exists_value = NULL;
  if (dict->GetWithoutPathExpansion("exists", &exists_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!exists_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<BooleanDelta> temp(new BooleanDelta());
        if (!BooleanDelta::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->exists = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<DownloadDelta> DownloadDelta::FromValue(const base::Value& value) {
  std::unique_ptr<DownloadDelta> out(new DownloadDelta());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DownloadDelta::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", (this->url)->ToValue());

  }
  if (this->final_url.get()) {
    to_value_result->SetWithoutPathExpansion("finalUrl", (this->final_url)->ToValue());

  }
  if (this->filename.get()) {
    to_value_result->SetWithoutPathExpansion("filename", (this->filename)->ToValue());

  }
  if (this->danger.get()) {
    to_value_result->SetWithoutPathExpansion("danger", (this->danger)->ToValue());

  }
  if (this->mime.get()) {
    to_value_result->SetWithoutPathExpansion("mime", (this->mime)->ToValue());

  }
  if (this->start_time.get()) {
    to_value_result->SetWithoutPathExpansion("startTime", (this->start_time)->ToValue());

  }
  if (this->end_time.get()) {
    to_value_result->SetWithoutPathExpansion("endTime", (this->end_time)->ToValue());

  }
  if (this->state.get()) {
    to_value_result->SetWithoutPathExpansion("state", (this->state)->ToValue());

  }
  if (this->can_resume.get()) {
    to_value_result->SetWithoutPathExpansion("canResume", (this->can_resume)->ToValue());

  }
  if (this->paused.get()) {
    to_value_result->SetWithoutPathExpansion("paused", (this->paused)->ToValue());

  }
  if (this->error.get()) {
    to_value_result->SetWithoutPathExpansion("error", (this->error)->ToValue());

  }
  if (this->total_bytes.get()) {
    to_value_result->SetWithoutPathExpansion("totalBytes", (this->total_bytes)->ToValue());

  }
  if (this->file_size.get()) {
    to_value_result->SetWithoutPathExpansion("fileSize", (this->file_size)->ToValue());

  }
  if (this->exists.get()) {
    to_value_result->SetWithoutPathExpansion("exists", (this->exists)->ToValue());

  }

  return to_value_result;
}


GetFileIconOptions::GetFileIconOptions()
 {}

GetFileIconOptions::~GetFileIconOptions() {}
GetFileIconOptions::GetFileIconOptions(GetFileIconOptions&& rhs)
: size(std::move(rhs.size)){
}

GetFileIconOptions& GetFileIconOptions::operator=(GetFileIconOptions&& rhs)
{
size = std::move(rhs.size);
return *this;
}

// static
bool GetFileIconOptions::Populate(
    const base::Value& value, GetFileIconOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* size_value = NULL;
  if (dict->GetWithoutPathExpansion("size", &size_value)) {
    {
      int temp;
      if (!size_value->GetAsInteger(&temp)) {
        out->size.reset();
        return false;
      }
      else
        out->size.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<GetFileIconOptions> GetFileIconOptions::FromValue(const base::Value& value) {
  std::unique_ptr<GetFileIconOptions> out(new GetFileIconOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GetFileIconOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->size.get()) {
    to_value_result->SetWithoutPathExpansion("size", std::make_unique<base::Value>(*this->size));

  }

  return to_value_result;
}



//
// Functions
//

namespace Download {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DownloadOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int download_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(download_id));

  return create_results;
}
}  // namespace Download

namespace Search {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* query_value = NULL;
  if (args.Get(0, &query_value) &&
      !query_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!query_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DownloadQuery::Populate(*dictionary, &params->query)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<DownloadItem>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace Search

namespace Pause {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Pause

namespace Resume {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Resume

namespace Cancel {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Cancel

namespace GetFileIcon {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<GetFileIconOptions> temp(new GetFileIconOptions());
        if (!GetFileIconOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& icon_url) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(icon_url));

  return create_results;
}
}  // namespace GetFileIcon

namespace Open {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Open

namespace Show {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Show

namespace ShowDefaultFolder {

}  // namespace ShowDefaultFolder

namespace Erase {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* query_value = NULL;
  if (args.Get(0, &query_value) &&
      !query_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!query_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DownloadQuery::Populate(*dictionary, &params->query)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<int>& erased_ids) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(erased_ids));

  return create_results;
}
}  // namespace Erase

namespace RemoveFile {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RemoveFile

namespace AcceptDanger {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* download_id_value = NULL;
  if (args.Get(0, &download_id_value) &&
      !download_id_value->is_none()) {
    {
      if (!download_id_value->GetAsInteger(&params->download_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace AcceptDanger

namespace SetShelfEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetShelfEnabled

//
// Events
//

namespace OnCreated {

const char kEventName[] = "downloads.onCreated";

std::unique_ptr<base::ListValue> Create(const DownloadItem& download_item) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((download_item).ToValue());

  return create_results;
}

}  // namespace OnCreated

namespace OnErased {

const char kEventName[] = "downloads.onErased";

std::unique_ptr<base::ListValue> Create(int download_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(download_id));

  return create_results;
}

}  // namespace OnErased

namespace OnChanged {

const char kEventName[] = "downloads.onChanged";

std::unique_ptr<base::ListValue> Create(const DownloadDelta& download_delta) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((download_delta).ToValue());

  return create_results;
}

}  // namespace OnChanged

namespace OnDeterminingFilename {

const char kEventName[] = "downloads.onDeterminingFilename";

std::unique_ptr<base::ListValue> Create(const DownloadItem& download_item) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((download_item).ToValue());

  return create_results;
}

}  // namespace OnDeterminingFilename

}  // namespace downloads
}  // namespace api
}  // namespace extensions

