// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/feedback_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/feedback_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace feedback_private {
//
// Types
//

AttachedFile::Data::Data()
 {}

AttachedFile::Data::~Data() {}
AttachedFile::Data::Data(Data&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

AttachedFile::Data& AttachedFile::Data::operator=(Data&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool AttachedFile::Data::Populate(
    const base::Value& value, Data* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> AttachedFile::Data::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



AttachedFile::AttachedFile()
 {}

AttachedFile::~AttachedFile() {}
AttachedFile::AttachedFile(AttachedFile&& rhs)
: name(std::move(rhs.name)),
data(std::move(rhs.data)){
}

AttachedFile& AttachedFile::operator=(AttachedFile&& rhs)
{
name = std::move(rhs.name);
data = std::move(rhs.data);
return *this;
}

// static
bool AttachedFile::Populate(
    const base::Value& value, AttachedFile* out) {
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

  const base::Value* data_value = NULL;
  if (dict->GetWithoutPathExpansion("data", &data_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!data_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Data> temp(new Data());
        if (!Data::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->data = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<AttachedFile> AttachedFile::FromValue(const base::Value& value) {
  std::unique_ptr<AttachedFile> out(new AttachedFile());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AttachedFile::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  if (this->data.get()) {
    to_value_result->SetWithoutPathExpansion("data", (this->data)->ToValue());

  }

  return to_value_result;
}


SystemInformation::SystemInformation()
 {}

SystemInformation::~SystemInformation() {}
SystemInformation::SystemInformation(SystemInformation&& rhs)
: key(std::move(rhs.key)),
value(std::move(rhs.value)){
}

SystemInformation& SystemInformation::operator=(SystemInformation&& rhs)
{
key = std::move(rhs.key);
value = std::move(rhs.value);
return *this;
}

// static
bool SystemInformation::Populate(
    const base::Value& value, SystemInformation* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* key_value = NULL;
  if (!dict->GetWithoutPathExpansion("key", &key_value)) {
    return false;
  }
  {
    if (!key_value->GetAsString(&out->key)) {
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
std::unique_ptr<SystemInformation> SystemInformation::FromValue(const base::Value& value) {
  std::unique_ptr<SystemInformation> out(new SystemInformation());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SystemInformation::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("key", std::make_unique<base::Value>(this->key));

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));


  return to_value_result;
}


const char* ToString(FeedbackFlow enum_param) {
  switch (enum_param) {
    case FEEDBACK_FLOW_REGULAR:
      return "regular";
    case FEEDBACK_FLOW_LOGIN:
      return "login";
    case FEEDBACK_FLOW_SADTABCRASH:
      return "sadTabCrash";
    case FEEDBACK_FLOW_GOOGLEINTERNAL:
      return "googleInternal";
    case FEEDBACK_FLOW_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FeedbackFlow ParseFeedbackFlow(const std::string& enum_string) {
  if (enum_string == "regular")
    return FEEDBACK_FLOW_REGULAR;
  if (enum_string == "login")
    return FEEDBACK_FLOW_LOGIN;
  if (enum_string == "sadTabCrash")
    return FEEDBACK_FLOW_SADTABCRASH;
  if (enum_string == "googleInternal")
    return FEEDBACK_FLOW_GOOGLEINTERNAL;
  return FEEDBACK_FLOW_NONE;
}


FeedbackInfo::Screenshot::Screenshot()
 {}

FeedbackInfo::Screenshot::~Screenshot() {}
FeedbackInfo::Screenshot::Screenshot(Screenshot&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

FeedbackInfo::Screenshot& FeedbackInfo::Screenshot::operator=(Screenshot&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool FeedbackInfo::Screenshot::Populate(
    const base::Value& value, Screenshot* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> FeedbackInfo::Screenshot::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



FeedbackInfo::FeedbackInfo()
: flow(FEEDBACK_FLOW_NONE) {}

FeedbackInfo::~FeedbackInfo() {}
FeedbackInfo::FeedbackInfo(FeedbackInfo&& rhs)
: attached_file(std::move(rhs.attached_file)),
category_tag(std::move(rhs.category_tag)),
description(std::move(rhs.description)),
description_placeholder(std::move(rhs.description_placeholder)),
email(std::move(rhs.email)),
page_url(std::move(rhs.page_url)),
product_id(std::move(rhs.product_id)),
screenshot(std::move(rhs.screenshot)),
trace_id(std::move(rhs.trace_id)),
system_information(std::move(rhs.system_information)),
send_histograms(std::move(rhs.send_histograms)),
flow(rhs.flow),
attached_file_blob_uuid(std::move(rhs.attached_file_blob_uuid)),
screenshot_blob_uuid(std::move(rhs.screenshot_blob_uuid)),
use_system_window_frame(std::move(rhs.use_system_window_frame)),
send_bluetooth_logs(std::move(rhs.send_bluetooth_logs)),
send_tab_titles(std::move(rhs.send_tab_titles)),
assistant_debug_info_allowed(std::move(rhs.assistant_debug_info_allowed)),
from_assistant(std::move(rhs.from_assistant)),
include_bluetooth_logs(std::move(rhs.include_bluetooth_logs)){
}

FeedbackInfo& FeedbackInfo::operator=(FeedbackInfo&& rhs)
{
attached_file = std::move(rhs.attached_file);
category_tag = std::move(rhs.category_tag);
description = std::move(rhs.description);
description_placeholder = std::move(rhs.description_placeholder);
email = std::move(rhs.email);
page_url = std::move(rhs.page_url);
product_id = std::move(rhs.product_id);
screenshot = std::move(rhs.screenshot);
trace_id = std::move(rhs.trace_id);
system_information = std::move(rhs.system_information);
send_histograms = std::move(rhs.send_histograms);
flow = rhs.flow;
attached_file_blob_uuid = std::move(rhs.attached_file_blob_uuid);
screenshot_blob_uuid = std::move(rhs.screenshot_blob_uuid);
use_system_window_frame = std::move(rhs.use_system_window_frame);
send_bluetooth_logs = std::move(rhs.send_bluetooth_logs);
send_tab_titles = std::move(rhs.send_tab_titles);
assistant_debug_info_allowed = std::move(rhs.assistant_debug_info_allowed);
from_assistant = std::move(rhs.from_assistant);
include_bluetooth_logs = std::move(rhs.include_bluetooth_logs);
return *this;
}

// static
bool FeedbackInfo::Populate(
    const base::Value& value, FeedbackInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->flow = FEEDBACK_FLOW_NONE;
  const base::Value* attached_file_value = NULL;
  if (dict->GetWithoutPathExpansion("attachedFile", &attached_file_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!attached_file_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<AttachedFile> temp(new AttachedFile());
        if (!AttachedFile::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->attached_file = std::move(temp);
      }
    }
  }

  const base::Value* category_tag_value = NULL;
  if (dict->GetWithoutPathExpansion("categoryTag", &category_tag_value)) {
    {
      std::string temp;
      if (!category_tag_value->GetAsString(&temp)) {
        out->category_tag.reset();
        return false;
      }
      else
        out->category_tag.reset(new std::string(temp));
    }
  }

  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* description_placeholder_value = NULL;
  if (dict->GetWithoutPathExpansion("descriptionPlaceholder", &description_placeholder_value)) {
    {
      std::string temp;
      if (!description_placeholder_value->GetAsString(&temp)) {
        out->description_placeholder.reset();
        return false;
      }
      else
        out->description_placeholder.reset(new std::string(temp));
    }
  }

  const base::Value* email_value = NULL;
  if (dict->GetWithoutPathExpansion("email", &email_value)) {
    {
      std::string temp;
      if (!email_value->GetAsString(&temp)) {
        out->email.reset();
        return false;
      }
      else
        out->email.reset(new std::string(temp));
    }
  }

  const base::Value* page_url_value = NULL;
  if (dict->GetWithoutPathExpansion("pageUrl", &page_url_value)) {
    {
      std::string temp;
      if (!page_url_value->GetAsString(&temp)) {
        out->page_url.reset();
        return false;
      }
      else
        out->page_url.reset(new std::string(temp));
    }
  }

  const base::Value* product_id_value = NULL;
  if (dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    {
      int temp;
      if (!product_id_value->GetAsInteger(&temp)) {
        out->product_id.reset();
        return false;
      }
      else
        out->product_id.reset(new int(temp));
    }
  }

  const base::Value* screenshot_value = NULL;
  if (dict->GetWithoutPathExpansion("screenshot", &screenshot_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!screenshot_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Screenshot> temp(new Screenshot());
        if (!Screenshot::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->screenshot = std::move(temp);
      }
    }
  }

  const base::Value* trace_id_value = NULL;
  if (dict->GetWithoutPathExpansion("traceId", &trace_id_value)) {
    {
      int temp;
      if (!trace_id_value->GetAsInteger(&temp)) {
        out->trace_id.reset();
        return false;
      }
      else
        out->trace_id.reset(new int(temp));
    }
  }

  const base::Value* system_information_value = NULL;
  if (dict->GetWithoutPathExpansion("systemInformation", &system_information_value)) {
    {
      const base::ListValue* list = NULL;
      if (!system_information_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->system_information)) {
          return false;
        }
      }
    }
  }

  const base::Value* send_histograms_value = NULL;
  if (dict->GetWithoutPathExpansion("sendHistograms", &send_histograms_value)) {
    {
      bool temp;
      if (!send_histograms_value->GetAsBoolean(&temp)) {
        out->send_histograms.reset();
        return false;
      }
      else
        out->send_histograms.reset(new bool(temp));
    }
  }

  const base::Value* flow_value = NULL;
  if (dict->GetWithoutPathExpansion("flow", &flow_value)) {
    {
      std::string feedback_flow_as_string;
      if (!flow_value->GetAsString(&feedback_flow_as_string)) {
        return false;
      }
      out->flow = ParseFeedbackFlow(feedback_flow_as_string);
      if (out->flow == FEEDBACK_FLOW_NONE) {
        return false;
      }
    }
    } else {
    out->flow = FEEDBACK_FLOW_NONE;
  }

  const base::Value* attached_file_blob_uuid_value = NULL;
  if (dict->GetWithoutPathExpansion("attachedFileBlobUuid", &attached_file_blob_uuid_value)) {
    {
      std::string temp;
      if (!attached_file_blob_uuid_value->GetAsString(&temp)) {
        out->attached_file_blob_uuid.reset();
        return false;
      }
      else
        out->attached_file_blob_uuid.reset(new std::string(temp));
    }
  }

  const base::Value* screenshot_blob_uuid_value = NULL;
  if (dict->GetWithoutPathExpansion("screenshotBlobUuid", &screenshot_blob_uuid_value)) {
    {
      std::string temp;
      if (!screenshot_blob_uuid_value->GetAsString(&temp)) {
        out->screenshot_blob_uuid.reset();
        return false;
      }
      else
        out->screenshot_blob_uuid.reset(new std::string(temp));
    }
  }

  const base::Value* use_system_window_frame_value = NULL;
  if (dict->GetWithoutPathExpansion("useSystemWindowFrame", &use_system_window_frame_value)) {
    {
      bool temp;
      if (!use_system_window_frame_value->GetAsBoolean(&temp)) {
        out->use_system_window_frame.reset();
        return false;
      }
      else
        out->use_system_window_frame.reset(new bool(temp));
    }
  }

  const base::Value* send_bluetooth_logs_value = NULL;
  if (dict->GetWithoutPathExpansion("sendBluetoothLogs", &send_bluetooth_logs_value)) {
    {
      bool temp;
      if (!send_bluetooth_logs_value->GetAsBoolean(&temp)) {
        out->send_bluetooth_logs.reset();
        return false;
      }
      else
        out->send_bluetooth_logs.reset(new bool(temp));
    }
  }

  const base::Value* send_tab_titles_value = NULL;
  if (dict->GetWithoutPathExpansion("sendTabTitles", &send_tab_titles_value)) {
    {
      bool temp;
      if (!send_tab_titles_value->GetAsBoolean(&temp)) {
        out->send_tab_titles.reset();
        return false;
      }
      else
        out->send_tab_titles.reset(new bool(temp));
    }
  }

  const base::Value* assistant_debug_info_allowed_value = NULL;
  if (dict->GetWithoutPathExpansion("assistantDebugInfoAllowed", &assistant_debug_info_allowed_value)) {
    {
      bool temp;
      if (!assistant_debug_info_allowed_value->GetAsBoolean(&temp)) {
        out->assistant_debug_info_allowed.reset();
        return false;
      }
      else
        out->assistant_debug_info_allowed.reset(new bool(temp));
    }
  }

  const base::Value* from_assistant_value = NULL;
  if (dict->GetWithoutPathExpansion("fromAssistant", &from_assistant_value)) {
    {
      bool temp;
      if (!from_assistant_value->GetAsBoolean(&temp)) {
        out->from_assistant.reset();
        return false;
      }
      else
        out->from_assistant.reset(new bool(temp));
    }
  }

  const base::Value* include_bluetooth_logs_value = NULL;
  if (dict->GetWithoutPathExpansion("includeBluetoothLogs", &include_bluetooth_logs_value)) {
    {
      bool temp;
      if (!include_bluetooth_logs_value->GetAsBoolean(&temp)) {
        out->include_bluetooth_logs.reset();
        return false;
      }
      else
        out->include_bluetooth_logs.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<FeedbackInfo> FeedbackInfo::FromValue(const base::Value& value) {
  std::unique_ptr<FeedbackInfo> out(new FeedbackInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FeedbackInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->attached_file.get()) {
    to_value_result->SetWithoutPathExpansion("attachedFile", (this->attached_file)->ToValue());

  }
  if (this->category_tag.get()) {
    to_value_result->SetWithoutPathExpansion("categoryTag", std::make_unique<base::Value>(*this->category_tag));

  }
  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  if (this->description_placeholder.get()) {
    to_value_result->SetWithoutPathExpansion("descriptionPlaceholder", std::make_unique<base::Value>(*this->description_placeholder));

  }
  if (this->email.get()) {
    to_value_result->SetWithoutPathExpansion("email", std::make_unique<base::Value>(*this->email));

  }
  if (this->page_url.get()) {
    to_value_result->SetWithoutPathExpansion("pageUrl", std::make_unique<base::Value>(*this->page_url));

  }
  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->screenshot.get()) {
    to_value_result->SetWithoutPathExpansion("screenshot", (this->screenshot)->ToValue());

  }
  if (this->trace_id.get()) {
    to_value_result->SetWithoutPathExpansion("traceId", std::make_unique<base::Value>(*this->trace_id));

  }
  if (this->system_information.get()) {
    to_value_result->SetWithoutPathExpansion("systemInformation", json_schema_compiler::util::CreateValueFromOptionalArray(this->system_information));

  }
  if (this->send_histograms.get()) {
    to_value_result->SetWithoutPathExpansion("sendHistograms", std::make_unique<base::Value>(*this->send_histograms));

  }
  if (this->flow != FEEDBACK_FLOW_NONE) {
    to_value_result->SetWithoutPathExpansion("flow", std::make_unique<base::Value>(feedback_private::ToString(this->flow)));

  }
  if (this->attached_file_blob_uuid.get()) {
    to_value_result->SetWithoutPathExpansion("attachedFileBlobUuid", std::make_unique<base::Value>(*this->attached_file_blob_uuid));

  }
  if (this->screenshot_blob_uuid.get()) {
    to_value_result->SetWithoutPathExpansion("screenshotBlobUuid", std::make_unique<base::Value>(*this->screenshot_blob_uuid));

  }
  if (this->use_system_window_frame.get()) {
    to_value_result->SetWithoutPathExpansion("useSystemWindowFrame", std::make_unique<base::Value>(*this->use_system_window_frame));

  }
  if (this->send_bluetooth_logs.get()) {
    to_value_result->SetWithoutPathExpansion("sendBluetoothLogs", std::make_unique<base::Value>(*this->send_bluetooth_logs));

  }
  if (this->send_tab_titles.get()) {
    to_value_result->SetWithoutPathExpansion("sendTabTitles", std::make_unique<base::Value>(*this->send_tab_titles));

  }
  if (this->assistant_debug_info_allowed.get()) {
    to_value_result->SetWithoutPathExpansion("assistantDebugInfoAllowed", std::make_unique<base::Value>(*this->assistant_debug_info_allowed));

  }
  if (this->from_assistant.get()) {
    to_value_result->SetWithoutPathExpansion("fromAssistant", std::make_unique<base::Value>(*this->from_assistant));

  }
  if (this->include_bluetooth_logs.get()) {
    to_value_result->SetWithoutPathExpansion("includeBluetoothLogs", std::make_unique<base::Value>(*this->include_bluetooth_logs));

  }

  return to_value_result;
}


const char* ToString(Status enum_param) {
  switch (enum_param) {
    case STATUS_SUCCESS:
      return "success";
    case STATUS_DELAYED:
      return "delayed";
    case STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Status ParseStatus(const std::string& enum_string) {
  if (enum_string == "success")
    return STATUS_SUCCESS;
  if (enum_string == "delayed")
    return STATUS_DELAYED;
  return STATUS_NONE;
}


const char* ToString(LandingPageType enum_param) {
  switch (enum_param) {
    case LANDING_PAGE_TYPE_NORMAL:
      return "normal";
    case LANDING_PAGE_TYPE_TECHSTOP:
      return "techstop";
    case LANDING_PAGE_TYPE_NOLANDINGPAGE:
      return "noLandingPage";
    case LANDING_PAGE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LandingPageType ParseLandingPageType(const std::string& enum_string) {
  if (enum_string == "normal")
    return LANDING_PAGE_TYPE_NORMAL;
  if (enum_string == "techstop")
    return LANDING_PAGE_TYPE_TECHSTOP;
  if (enum_string == "noLandingPage")
    return LANDING_PAGE_TYPE_NOLANDINGPAGE;
  return LANDING_PAGE_TYPE_NONE;
}


const char* ToString(LogSource enum_param) {
  switch (enum_param) {
    case LOG_SOURCE_MESSAGES:
      return "messages";
    case LOG_SOURCE_UILATEST:
      return "uiLatest";
    case LOG_SOURCE_DRMMODETEST:
      return "drmModetest";
    case LOG_SOURCE_LSUSB:
      return "lsusb";
    case LOG_SOURCE_ATRUSLOG:
      return "atrusLog";
    case LOG_SOURCE_NETLOG:
      return "netLog";
    case LOG_SOURCE_EVENTLOG:
      return "eventLog";
    case LOG_SOURCE_UPDATEENGINELOG:
      return "updateEngineLog";
    case LOG_SOURCE_POWERDLATEST:
      return "powerdLatest";
    case LOG_SOURCE_POWERDPREVIOUS:
      return "powerdPrevious";
    case LOG_SOURCE_LSPCI:
      return "lspci";
    case LOG_SOURCE_IFCONFIG:
      return "ifconfig";
    case LOG_SOURCE_UPTIME:
      return "uptime";
    case LOG_SOURCE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LogSource ParseLogSource(const std::string& enum_string) {
  if (enum_string == "messages")
    return LOG_SOURCE_MESSAGES;
  if (enum_string == "uiLatest")
    return LOG_SOURCE_UILATEST;
  if (enum_string == "drmModetest")
    return LOG_SOURCE_DRMMODETEST;
  if (enum_string == "lsusb")
    return LOG_SOURCE_LSUSB;
  if (enum_string == "atrusLog")
    return LOG_SOURCE_ATRUSLOG;
  if (enum_string == "netLog")
    return LOG_SOURCE_NETLOG;
  if (enum_string == "eventLog")
    return LOG_SOURCE_EVENTLOG;
  if (enum_string == "updateEngineLog")
    return LOG_SOURCE_UPDATEENGINELOG;
  if (enum_string == "powerdLatest")
    return LOG_SOURCE_POWERDLATEST;
  if (enum_string == "powerdPrevious")
    return LOG_SOURCE_POWERDPREVIOUS;
  if (enum_string == "lspci")
    return LOG_SOURCE_LSPCI;
  if (enum_string == "ifconfig")
    return LOG_SOURCE_IFCONFIG;
  if (enum_string == "uptime")
    return LOG_SOURCE_UPTIME;
  return LOG_SOURCE_NONE;
}


ReadLogSourceParams::ReadLogSourceParams()
: source(LOG_SOURCE_NONE),
incremental(false) {}

ReadLogSourceParams::~ReadLogSourceParams() {}
ReadLogSourceParams::ReadLogSourceParams(ReadLogSourceParams&& rhs)
: source(rhs.source),
incremental(rhs.incremental),
reader_id(std::move(rhs.reader_id)){
}

ReadLogSourceParams& ReadLogSourceParams::operator=(ReadLogSourceParams&& rhs)
{
source = rhs.source;
incremental = rhs.incremental;
reader_id = std::move(rhs.reader_id);
return *this;
}

// static
bool ReadLogSourceParams::Populate(
    const base::Value& value, ReadLogSourceParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* source_value = NULL;
  if (!dict->GetWithoutPathExpansion("source", &source_value)) {
    return false;
  }
  {
    std::string log_source_as_string;
    if (!source_value->GetAsString(&log_source_as_string)) {
      return false;
    }
    out->source = ParseLogSource(log_source_as_string);
    if (out->source == LOG_SOURCE_NONE) {
      return false;
    }
  }

  const base::Value* incremental_value = NULL;
  if (!dict->GetWithoutPathExpansion("incremental", &incremental_value)) {
    return false;
  }
  {
    if (!incremental_value->GetAsBoolean(&out->incremental)) {
      return false;
    }
  }

  const base::Value* reader_id_value = NULL;
  if (dict->GetWithoutPathExpansion("readerId", &reader_id_value)) {
    {
      int temp;
      if (!reader_id_value->GetAsInteger(&temp)) {
        out->reader_id.reset();
        return false;
      }
      else
        out->reader_id.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ReadLogSourceParams> ReadLogSourceParams::FromValue(const base::Value& value) {
  std::unique_ptr<ReadLogSourceParams> out(new ReadLogSourceParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReadLogSourceParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("source", std::make_unique<base::Value>(feedback_private::ToString(this->source)));

  to_value_result->SetWithoutPathExpansion("incremental", std::make_unique<base::Value>(this->incremental));

  if (this->reader_id.get()) {
    to_value_result->SetWithoutPathExpansion("readerId", std::make_unique<base::Value>(*this->reader_id));

  }

  return to_value_result;
}


ReadLogSourceResult::ReadLogSourceResult()
: reader_id(0) {}

ReadLogSourceResult::~ReadLogSourceResult() {}
ReadLogSourceResult::ReadLogSourceResult(ReadLogSourceResult&& rhs)
: reader_id(rhs.reader_id),
log_lines(std::move(rhs.log_lines)){
}

ReadLogSourceResult& ReadLogSourceResult::operator=(ReadLogSourceResult&& rhs)
{
reader_id = rhs.reader_id;
log_lines = std::move(rhs.log_lines);
return *this;
}

// static
bool ReadLogSourceResult::Populate(
    const base::Value& value, ReadLogSourceResult* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* reader_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("readerId", &reader_id_value)) {
    return false;
  }
  {
    if (!reader_id_value->GetAsInteger(&out->reader_id)) {
      return false;
    }
  }

  const base::Value* log_lines_value = NULL;
  if (!dict->GetWithoutPathExpansion("logLines", &log_lines_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!log_lines_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->log_lines)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ReadLogSourceResult> ReadLogSourceResult::FromValue(const base::Value& value) {
  std::unique_ptr<ReadLogSourceResult> out(new ReadLogSourceResult());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ReadLogSourceResult::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("readerId", std::make_unique<base::Value>(this->reader_id));

  to_value_result->SetWithoutPathExpansion("logLines", json_schema_compiler::util::CreateValueFromArray(this->log_lines));


  return to_value_result;
}



//
// Functions
//

namespace GetUserEmail {

std::unique_ptr<base::ListValue> Results::Create(const std::string& email) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(email));

  return create_results;
}
}  // namespace GetUserEmail

namespace GetSystemInformation {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<SystemInformation>& system_information) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(system_information));

  return create_results;
}
}  // namespace GetSystemInformation

namespace SendFeedback {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* feedback_value = NULL;
  if (args.Get(0, &feedback_value) &&
      !feedback_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!feedback_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!FeedbackInfo::Populate(*dictionary, &params->feedback)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Status& status, const LandingPageType& type) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(feedback_private::ToString(status)));

  create_results->Append(std::make_unique<base::Value>(feedback_private::ToString(type)));

  return create_results;
}
}  // namespace SendFeedback

namespace GetStrings {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* flow_value = NULL;
  if (args.Get(0, &flow_value) &&
      !flow_value->is_none()) {
    {
      std::string feedback_flow_as_string;
      if (!flow_value->GetAsString(&feedback_flow_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->flow = ParseFeedbackFlow(feedback_flow_as_string);
      if (params->flow == FEEDBACK_FLOW_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Result::Result()
 {}

Results::Result::~Result() {}
Results::Result::Result(Result&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Result& Results::Result::operator=(Result&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Result::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Result& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetStrings

namespace ReadLogSource {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* params_value = NULL;
  if (args.Get(0, &params_value) &&
      !params_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!params_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ReadLogSourceParams::Populate(*dictionary, &params->params)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ReadLogSourceResult& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace ReadLogSource

namespace LoginFeedbackComplete {

}  // namespace LoginFeedbackComplete

//
// Events
//

namespace OnFeedbackRequested {

const char kEventName[] = "feedbackPrivate.onFeedbackRequested";

std::unique_ptr<base::ListValue> Create(const FeedbackInfo& feedback) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((feedback).ToValue());

  return create_results;
}

}  // namespace OnFeedbackRequested

}  // namespace feedback_private
}  // namespace api
}  // namespace extensions

