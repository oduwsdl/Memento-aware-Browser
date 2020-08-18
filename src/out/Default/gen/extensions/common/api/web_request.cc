// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/web_request.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/web_request.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace web_request {
//
// Properties
//

const int MAX_HANDLER_BEHAVIOR_CHANGED_CALLS_PER_10_MINUTES = 20;

//
// Types
//

const char* ToString(ResourceType enum_param) {
  switch (enum_param) {
    case RESOURCE_TYPE_MAIN_FRAME:
      return "main_frame";
    case RESOURCE_TYPE_SUB_FRAME:
      return "sub_frame";
    case RESOURCE_TYPE_STYLESHEET:
      return "stylesheet";
    case RESOURCE_TYPE_SCRIPT:
      return "script";
    case RESOURCE_TYPE_IMAGE:
      return "image";
    case RESOURCE_TYPE_FONT:
      return "font";
    case RESOURCE_TYPE_OBJECT:
      return "object";
    case RESOURCE_TYPE_XMLHTTPREQUEST:
      return "xmlhttprequest";
    case RESOURCE_TYPE_PING:
      return "ping";
    case RESOURCE_TYPE_CSP_REPORT:
      return "csp_report";
    case RESOURCE_TYPE_MEDIA:
      return "media";
    case RESOURCE_TYPE_WEBSOCKET:
      return "websocket";
    case RESOURCE_TYPE_OTHER:
      return "other";
    case RESOURCE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ResourceType ParseResourceType(const std::string& enum_string) {
  if (enum_string == "main_frame")
    return RESOURCE_TYPE_MAIN_FRAME;
  if (enum_string == "sub_frame")
    return RESOURCE_TYPE_SUB_FRAME;
  if (enum_string == "stylesheet")
    return RESOURCE_TYPE_STYLESHEET;
  if (enum_string == "script")
    return RESOURCE_TYPE_SCRIPT;
  if (enum_string == "image")
    return RESOURCE_TYPE_IMAGE;
  if (enum_string == "font")
    return RESOURCE_TYPE_FONT;
  if (enum_string == "object")
    return RESOURCE_TYPE_OBJECT;
  if (enum_string == "xmlhttprequest")
    return RESOURCE_TYPE_XMLHTTPREQUEST;
  if (enum_string == "ping")
    return RESOURCE_TYPE_PING;
  if (enum_string == "csp_report")
    return RESOURCE_TYPE_CSP_REPORT;
  if (enum_string == "media")
    return RESOURCE_TYPE_MEDIA;
  if (enum_string == "websocket")
    return RESOURCE_TYPE_WEBSOCKET;
  if (enum_string == "other")
    return RESOURCE_TYPE_OTHER;
  return RESOURCE_TYPE_NONE;
}


const char* ToString(OnBeforeRequestOptions enum_param) {
  switch (enum_param) {
    case ON_BEFORE_REQUEST_OPTIONS_BLOCKING:
      return "blocking";
    case ON_BEFORE_REQUEST_OPTIONS_REQUESTBODY:
      return "requestBody";
    case ON_BEFORE_REQUEST_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_BEFORE_REQUEST_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnBeforeRequestOptions ParseOnBeforeRequestOptions(const std::string& enum_string) {
  if (enum_string == "blocking")
    return ON_BEFORE_REQUEST_OPTIONS_BLOCKING;
  if (enum_string == "requestBody")
    return ON_BEFORE_REQUEST_OPTIONS_REQUESTBODY;
  if (enum_string == "extraHeaders")
    return ON_BEFORE_REQUEST_OPTIONS_EXTRAHEADERS;
  return ON_BEFORE_REQUEST_OPTIONS_NONE;
}


const char* ToString(OnBeforeSendHeadersOptions enum_param) {
  switch (enum_param) {
    case ON_BEFORE_SEND_HEADERS_OPTIONS_REQUESTHEADERS:
      return "requestHeaders";
    case ON_BEFORE_SEND_HEADERS_OPTIONS_BLOCKING:
      return "blocking";
    case ON_BEFORE_SEND_HEADERS_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_BEFORE_SEND_HEADERS_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnBeforeSendHeadersOptions ParseOnBeforeSendHeadersOptions(const std::string& enum_string) {
  if (enum_string == "requestHeaders")
    return ON_BEFORE_SEND_HEADERS_OPTIONS_REQUESTHEADERS;
  if (enum_string == "blocking")
    return ON_BEFORE_SEND_HEADERS_OPTIONS_BLOCKING;
  if (enum_string == "extraHeaders")
    return ON_BEFORE_SEND_HEADERS_OPTIONS_EXTRAHEADERS;
  return ON_BEFORE_SEND_HEADERS_OPTIONS_NONE;
}


const char* ToString(OnSendHeadersOptions enum_param) {
  switch (enum_param) {
    case ON_SEND_HEADERS_OPTIONS_REQUESTHEADERS:
      return "requestHeaders";
    case ON_SEND_HEADERS_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_SEND_HEADERS_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnSendHeadersOptions ParseOnSendHeadersOptions(const std::string& enum_string) {
  if (enum_string == "requestHeaders")
    return ON_SEND_HEADERS_OPTIONS_REQUESTHEADERS;
  if (enum_string == "extraHeaders")
    return ON_SEND_HEADERS_OPTIONS_EXTRAHEADERS;
  return ON_SEND_HEADERS_OPTIONS_NONE;
}


const char* ToString(OnHeadersReceivedOptions enum_param) {
  switch (enum_param) {
    case ON_HEADERS_RECEIVED_OPTIONS_BLOCKING:
      return "blocking";
    case ON_HEADERS_RECEIVED_OPTIONS_RESPONSEHEADERS:
      return "responseHeaders";
    case ON_HEADERS_RECEIVED_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_HEADERS_RECEIVED_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnHeadersReceivedOptions ParseOnHeadersReceivedOptions(const std::string& enum_string) {
  if (enum_string == "blocking")
    return ON_HEADERS_RECEIVED_OPTIONS_BLOCKING;
  if (enum_string == "responseHeaders")
    return ON_HEADERS_RECEIVED_OPTIONS_RESPONSEHEADERS;
  if (enum_string == "extraHeaders")
    return ON_HEADERS_RECEIVED_OPTIONS_EXTRAHEADERS;
  return ON_HEADERS_RECEIVED_OPTIONS_NONE;
}


const char* ToString(OnAuthRequiredOptions enum_param) {
  switch (enum_param) {
    case ON_AUTH_REQUIRED_OPTIONS_RESPONSEHEADERS:
      return "responseHeaders";
    case ON_AUTH_REQUIRED_OPTIONS_BLOCKING:
      return "blocking";
    case ON_AUTH_REQUIRED_OPTIONS_ASYNCBLOCKING:
      return "asyncBlocking";
    case ON_AUTH_REQUIRED_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_AUTH_REQUIRED_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnAuthRequiredOptions ParseOnAuthRequiredOptions(const std::string& enum_string) {
  if (enum_string == "responseHeaders")
    return ON_AUTH_REQUIRED_OPTIONS_RESPONSEHEADERS;
  if (enum_string == "blocking")
    return ON_AUTH_REQUIRED_OPTIONS_BLOCKING;
  if (enum_string == "asyncBlocking")
    return ON_AUTH_REQUIRED_OPTIONS_ASYNCBLOCKING;
  if (enum_string == "extraHeaders")
    return ON_AUTH_REQUIRED_OPTIONS_EXTRAHEADERS;
  return ON_AUTH_REQUIRED_OPTIONS_NONE;
}


const char* ToString(OnResponseStartedOptions enum_param) {
  switch (enum_param) {
    case ON_RESPONSE_STARTED_OPTIONS_RESPONSEHEADERS:
      return "responseHeaders";
    case ON_RESPONSE_STARTED_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_RESPONSE_STARTED_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnResponseStartedOptions ParseOnResponseStartedOptions(const std::string& enum_string) {
  if (enum_string == "responseHeaders")
    return ON_RESPONSE_STARTED_OPTIONS_RESPONSEHEADERS;
  if (enum_string == "extraHeaders")
    return ON_RESPONSE_STARTED_OPTIONS_EXTRAHEADERS;
  return ON_RESPONSE_STARTED_OPTIONS_NONE;
}


const char* ToString(OnBeforeRedirectOptions enum_param) {
  switch (enum_param) {
    case ON_BEFORE_REDIRECT_OPTIONS_RESPONSEHEADERS:
      return "responseHeaders";
    case ON_BEFORE_REDIRECT_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_BEFORE_REDIRECT_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnBeforeRedirectOptions ParseOnBeforeRedirectOptions(const std::string& enum_string) {
  if (enum_string == "responseHeaders")
    return ON_BEFORE_REDIRECT_OPTIONS_RESPONSEHEADERS;
  if (enum_string == "extraHeaders")
    return ON_BEFORE_REDIRECT_OPTIONS_EXTRAHEADERS;
  return ON_BEFORE_REDIRECT_OPTIONS_NONE;
}


const char* ToString(OnCompletedOptions enum_param) {
  switch (enum_param) {
    case ON_COMPLETED_OPTIONS_RESPONSEHEADERS:
      return "responseHeaders";
    case ON_COMPLETED_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_COMPLETED_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnCompletedOptions ParseOnCompletedOptions(const std::string& enum_string) {
  if (enum_string == "responseHeaders")
    return ON_COMPLETED_OPTIONS_RESPONSEHEADERS;
  if (enum_string == "extraHeaders")
    return ON_COMPLETED_OPTIONS_EXTRAHEADERS;
  return ON_COMPLETED_OPTIONS_NONE;
}


const char* ToString(OnErrorOccurredOptions enum_param) {
  switch (enum_param) {
    case ON_ERROR_OCCURRED_OPTIONS_EXTRAHEADERS:
      return "extraHeaders";
    case ON_ERROR_OCCURRED_OPTIONS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnErrorOccurredOptions ParseOnErrorOccurredOptions(const std::string& enum_string) {
  if (enum_string == "extraHeaders")
    return ON_ERROR_OCCURRED_OPTIONS_EXTRAHEADERS;
  return ON_ERROR_OCCURRED_OPTIONS_NONE;
}


RequestFilter::RequestFilter()
 {}

RequestFilter::~RequestFilter() {}
RequestFilter::RequestFilter(RequestFilter&& rhs)
: urls(std::move(rhs.urls)),
types(std::move(rhs.types)),
tab_id(std::move(rhs.tab_id)),
window_id(std::move(rhs.window_id)){
}

RequestFilter& RequestFilter::operator=(RequestFilter&& rhs)
{
urls = std::move(rhs.urls);
types = std::move(rhs.types);
tab_id = std::move(rhs.tab_id);
window_id = std::move(rhs.window_id);
return *this;
}

// static
bool RequestFilter::Populate(
    const base::Value& value, RequestFilter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* urls_value = NULL;
  if (!dict->GetWithoutPathExpansion("urls", &urls_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!urls_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->urls)) {
        return false;
      }
    }
  }

  const base::Value* types_value = NULL;
  if (dict->GetWithoutPathExpansion("types", &types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!types_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->types.reset(new std::vector<ResourceType>);
        for (const auto& it : *(list)) {
          ResourceType tmp;
          std::string resource_type_as_string;
          if (!(it).GetAsString(&resource_type_as_string)) {
            return false;
          }
          tmp = ParseResourceType(resource_type_as_string);
          if (tmp == RESOURCE_TYPE_NONE) {
            return false;
          }
          out->types->push_back(tmp);
        }
      }
    }
  }

  const base::Value* tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        out->tab_id.reset();
        return false;
      }
      else
        out->tab_id.reset(new int(temp));
    }
  }

  const base::Value* window_id_value = NULL;
  if (dict->GetWithoutPathExpansion("windowId", &window_id_value)) {
    {
      int temp;
      if (!window_id_value->GetAsInteger(&temp)) {
        out->window_id.reset();
        return false;
      }
      else
        out->window_id.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<RequestFilter> RequestFilter::FromValue(const base::Value& value) {
  std::unique_ptr<RequestFilter> out(new RequestFilter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RequestFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("urls", json_schema_compiler::util::CreateValueFromArray(this->urls));

  if (this->types.get()) {
    {
      std::vector<std::string> types_list;
      for (const auto& it : *(this->types)) {
      types_list.push_back(web_request::ToString(it));
    }
    to_value_result->SetWithoutPathExpansion("types", json_schema_compiler::util::CreateValueFromArray(types_list));
    }

  }
  if (this->tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(*this->tab_id));

  }
  if (this->window_id.get()) {
    to_value_result->SetWithoutPathExpansion("windowId", std::make_unique<base::Value>(*this->window_id));

  }

  return to_value_result;
}


UploadData::UploadData()
 {}

UploadData::~UploadData() {}
UploadData::UploadData(UploadData&& rhs)
: bytes(std::move(rhs.bytes)),
file(std::move(rhs.file)){
}

UploadData& UploadData::operator=(UploadData&& rhs)
{
bytes = std::move(rhs.bytes);
file = std::move(rhs.file);
return *this;
}

// static
bool UploadData::Populate(
    const base::Value& value, UploadData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* bytes_value = NULL;
  if (dict->GetWithoutPathExpansion("bytes", &bytes_value)) {
    {
      out->bytes = bytes_value->CreateDeepCopy();
    }
  }

  const base::Value* file_value = NULL;
  if (dict->GetWithoutPathExpansion("file", &file_value)) {
    {
      std::string temp;
      if (!file_value->GetAsString(&temp)) {
        out->file.reset();
        return false;
      }
      else
        out->file.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<UploadData> UploadData::FromValue(const base::Value& value) {
  std::unique_ptr<UploadData> out(new UploadData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> UploadData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->bytes.get()) {
    to_value_result->SetWithoutPathExpansion("bytes", (this->bytes)->CreateDeepCopy());

  }
  if (this->file.get()) {
    to_value_result->SetWithoutPathExpansion("file", std::make_unique<base::Value>(*this->file));

  }

  return to_value_result;
}


FormDataItem::FormDataItem()
 {}

FormDataItem::~FormDataItem() {}
FormDataItem::FormDataItem(FormDataItem&& rhs)
: as_binary(std::move(rhs.as_binary)),
as_string(std::move(rhs.as_string)){
}

FormDataItem& FormDataItem::operator=(FormDataItem&& rhs)
{
as_binary = std::move(rhs.as_binary);
as_string = std::move(rhs.as_string);
return *this;
}

// static
bool FormDataItem::Populate(
    const base::Value& value, FormDataItem* out) {
  if (value.type() == base::Value::Type::BINARY) {
    {
      if (!(&value)->is_blob()) {
        return false;
      }
      else {
        out->as_binary.reset(new std::vector<uint8_t>((&value)->GetBlob()));
      }
    }
    return true;
  }
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
    }
    return true;
  }
  return false;
}

// static
std::unique_ptr<FormDataItem> FormDataItem::FromValue(const base::Value& value) {
  std::unique_ptr<FormDataItem> out(new FormDataItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::Value> FormDataItem::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_binary) {
    DCHECK(!result) << "Cannot set multiple choices for form_data_item";
    result = std::make_unique<base::Value>(*as_binary);

  }
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for form_data_item";
    result = std::make_unique<base::Value>(*as_string);

  }
  DCHECK(result) << "Must set at least one choice for form_data_item";
  return result;
}


const char* ToString(IgnoredActionType enum_param) {
  switch (enum_param) {
    case IGNORED_ACTION_TYPE_REDIRECT:
      return "redirect";
    case IGNORED_ACTION_TYPE_REQUEST_HEADERS:
      return "request_headers";
    case IGNORED_ACTION_TYPE_RESPONSE_HEADERS:
      return "response_headers";
    case IGNORED_ACTION_TYPE_AUTH_CREDENTIALS:
      return "auth_credentials";
    case IGNORED_ACTION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

IgnoredActionType ParseIgnoredActionType(const std::string& enum_string) {
  if (enum_string == "redirect")
    return IGNORED_ACTION_TYPE_REDIRECT;
  if (enum_string == "request_headers")
    return IGNORED_ACTION_TYPE_REQUEST_HEADERS;
  if (enum_string == "response_headers")
    return IGNORED_ACTION_TYPE_RESPONSE_HEADERS;
  if (enum_string == "auth_credentials")
    return IGNORED_ACTION_TYPE_AUTH_CREDENTIALS;
  return IGNORED_ACTION_TYPE_NONE;
}



//
// Functions
//

namespace HandlerBehaviorChanged {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace HandlerBehaviorChanged

//
// Events
//

namespace OnBeforeRequest {

const char kEventName[] = "webRequest.onBeforeRequest";

Details::RequestBody::FormData::FormData()
 {}

Details::RequestBody::FormData::~FormData() {}
Details::RequestBody::FormData::FormData(FormData&& rhs)
: additional_properties(std::move(rhs.additional_properties)){
}

Details::RequestBody::FormData& Details::RequestBody::FormData::operator=(FormData&& rhs)
{
additional_properties = std::move(rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::RequestBody::FormData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  for (const auto& it : additional_properties) {
    to_value_result->SetWithoutPathExpansion(it.first, json_schema_compiler::util::CreateValueFromArray(it.second));

  }

  return to_value_result;
}



Details::RequestBody::RequestBody()
 {}

Details::RequestBody::~RequestBody() {}
Details::RequestBody::RequestBody(RequestBody&& rhs)
: error(std::move(rhs.error)),
form_data(std::move(rhs.form_data)),
raw(std::move(rhs.raw)){
}

Details::RequestBody& Details::RequestBody::operator=(RequestBody&& rhs)
{
error = std::move(rhs.error);
form_data = std::move(rhs.form_data);
raw = std::move(rhs.raw);
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::RequestBody::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->error.get()) {
    to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(*this->error));

  }
  if (this->form_data.get()) {
    to_value_result->SetWithoutPathExpansion("formData", (this->form_data)->ToValue());

  }
  if (this->raw.get()) {
    to_value_result->SetWithoutPathExpansion("raw", json_schema_compiler::util::CreateValueFromOptionalArray(this->raw));

  }

  return to_value_result;
}



Details::Details()
: frame_id(0),
parent_frame_id(0),
tab_id(0),
type(RESOURCE_TYPE_NONE),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: request_id(std::move(rhs.request_id)),
url(std::move(rhs.url)),
method(std::move(rhs.method)),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
request_body(std::move(rhs.request_body)),
tab_id(rhs.tab_id),
type(rhs.type),
initiator(std::move(rhs.initiator)),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
request_id = std::move(rhs.request_id);
url = std::move(rhs.url);
method = std::move(rhs.method);
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
request_body = std::move(rhs.request_body);
tab_id = rhs.tab_id;
type = rhs.type;
initiator = std::move(rhs.initiator);
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("requestId", std::make_unique<base::Value>(this->request_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("method", std::make_unique<base::Value>(this->method));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  if (this->request_body.get()) {
    to_value_result->SetWithoutPathExpansion("requestBody", (this->request_body)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(web_request::ToString(this->type)));

  if (this->initiator.get()) {
    to_value_result->SetWithoutPathExpansion("initiator", std::make_unique<base::Value>(*this->initiator));

  }
  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnBeforeRequest

namespace OnErrorOccurred {

const char kEventName[] = "webRequest.onErrorOccurred";

Details::Details()
: frame_id(0),
parent_frame_id(0),
tab_id(0),
type(RESOURCE_TYPE_NONE),
time_stamp(0.0),
from_cache(false) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: request_id(std::move(rhs.request_id)),
url(std::move(rhs.url)),
method(std::move(rhs.method)),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
tab_id(rhs.tab_id),
type(rhs.type),
initiator(std::move(rhs.initiator)),
time_stamp(rhs.time_stamp),
ip(std::move(rhs.ip)),
from_cache(rhs.from_cache),
error(std::move(rhs.error)){
}

Details& Details::operator=(Details&& rhs)
{
request_id = std::move(rhs.request_id);
url = std::move(rhs.url);
method = std::move(rhs.method);
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
tab_id = rhs.tab_id;
type = rhs.type;
initiator = std::move(rhs.initiator);
time_stamp = rhs.time_stamp;
ip = std::move(rhs.ip);
from_cache = rhs.from_cache;
error = std::move(rhs.error);
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("requestId", std::make_unique<base::Value>(this->request_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("method", std::make_unique<base::Value>(this->method));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(web_request::ToString(this->type)));

  if (this->initiator.get()) {
    to_value_result->SetWithoutPathExpansion("initiator", std::make_unique<base::Value>(*this->initiator));

  }
  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));

  if (this->ip.get()) {
    to_value_result->SetWithoutPathExpansion("ip", std::make_unique<base::Value>(*this->ip));

  }
  to_value_result->SetWithoutPathExpansion("fromCache", std::make_unique<base::Value>(this->from_cache));

  to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(this->error));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnErrorOccurred

namespace OnActionIgnored {

const char kEventName[] = "webRequest.onActionIgnored";

Details::Details()
: action(IGNORED_ACTION_TYPE_NONE) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: request_id(std::move(rhs.request_id)),
action(rhs.action){
}

Details& Details::operator=(Details&& rhs)
{
request_id = std::move(rhs.request_id);
action = rhs.action;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("requestId", std::make_unique<base::Value>(this->request_id));

  to_value_result->SetWithoutPathExpansion("action", std::make_unique<base::Value>(web_request::ToString(this->action)));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnActionIgnored

}  // namespace web_request
}  // namespace api
}  // namespace extensions

