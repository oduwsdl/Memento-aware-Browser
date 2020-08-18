// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/activity_log_private.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/activity_log_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace activity_log_private {
//
// Types
//

const char* ToString(ExtensionActivityType enum_param) {
  switch (enum_param) {
    case EXTENSION_ACTIVITY_TYPE_API_CALL:
      return "api_call";
    case EXTENSION_ACTIVITY_TYPE_API_EVENT:
      return "api_event";
    case EXTENSION_ACTIVITY_TYPE_CONTENT_SCRIPT:
      return "content_script";
    case EXTENSION_ACTIVITY_TYPE_DOM_ACCESS:
      return "dom_access";
    case EXTENSION_ACTIVITY_TYPE_DOM_EVENT:
      return "dom_event";
    case EXTENSION_ACTIVITY_TYPE_WEB_REQUEST:
      return "web_request";
    case EXTENSION_ACTIVITY_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionActivityType ParseExtensionActivityType(const std::string& enum_string) {
  if (enum_string == "api_call")
    return EXTENSION_ACTIVITY_TYPE_API_CALL;
  if (enum_string == "api_event")
    return EXTENSION_ACTIVITY_TYPE_API_EVENT;
  if (enum_string == "content_script")
    return EXTENSION_ACTIVITY_TYPE_CONTENT_SCRIPT;
  if (enum_string == "dom_access")
    return EXTENSION_ACTIVITY_TYPE_DOM_ACCESS;
  if (enum_string == "dom_event")
    return EXTENSION_ACTIVITY_TYPE_DOM_EVENT;
  if (enum_string == "web_request")
    return EXTENSION_ACTIVITY_TYPE_WEB_REQUEST;
  return EXTENSION_ACTIVITY_TYPE_NONE;
}


const char* ToString(ExtensionActivityFilter enum_param) {
  switch (enum_param) {
    case EXTENSION_ACTIVITY_FILTER_API_CALL:
      return "api_call";
    case EXTENSION_ACTIVITY_FILTER_API_EVENT:
      return "api_event";
    case EXTENSION_ACTIVITY_FILTER_CONTENT_SCRIPT:
      return "content_script";
    case EXTENSION_ACTIVITY_FILTER_DOM_ACCESS:
      return "dom_access";
    case EXTENSION_ACTIVITY_FILTER_DOM_EVENT:
      return "dom_event";
    case EXTENSION_ACTIVITY_FILTER_WEB_REQUEST:
      return "web_request";
    case EXTENSION_ACTIVITY_FILTER_ANY:
      return "any";
    case EXTENSION_ACTIVITY_FILTER_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionActivityFilter ParseExtensionActivityFilter(const std::string& enum_string) {
  if (enum_string == "api_call")
    return EXTENSION_ACTIVITY_FILTER_API_CALL;
  if (enum_string == "api_event")
    return EXTENSION_ACTIVITY_FILTER_API_EVENT;
  if (enum_string == "content_script")
    return EXTENSION_ACTIVITY_FILTER_CONTENT_SCRIPT;
  if (enum_string == "dom_access")
    return EXTENSION_ACTIVITY_FILTER_DOM_ACCESS;
  if (enum_string == "dom_event")
    return EXTENSION_ACTIVITY_FILTER_DOM_EVENT;
  if (enum_string == "web_request")
    return EXTENSION_ACTIVITY_FILTER_WEB_REQUEST;
  if (enum_string == "any")
    return EXTENSION_ACTIVITY_FILTER_ANY;
  return EXTENSION_ACTIVITY_FILTER_NONE;
}


const char* ToString(ExtensionActivityDomVerb enum_param) {
  switch (enum_param) {
    case EXTENSION_ACTIVITY_DOM_VERB_GETTER:
      return "getter";
    case EXTENSION_ACTIVITY_DOM_VERB_SETTER:
      return "setter";
    case EXTENSION_ACTIVITY_DOM_VERB_METHOD:
      return "method";
    case EXTENSION_ACTIVITY_DOM_VERB_INSERTED:
      return "inserted";
    case EXTENSION_ACTIVITY_DOM_VERB_XHR:
      return "xhr";
    case EXTENSION_ACTIVITY_DOM_VERB_WEBREQUEST:
      return "webrequest";
    case EXTENSION_ACTIVITY_DOM_VERB_MODIFIED:
      return "modified";
    case EXTENSION_ACTIVITY_DOM_VERB_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExtensionActivityDomVerb ParseExtensionActivityDomVerb(const std::string& enum_string) {
  if (enum_string == "getter")
    return EXTENSION_ACTIVITY_DOM_VERB_GETTER;
  if (enum_string == "setter")
    return EXTENSION_ACTIVITY_DOM_VERB_SETTER;
  if (enum_string == "method")
    return EXTENSION_ACTIVITY_DOM_VERB_METHOD;
  if (enum_string == "inserted")
    return EXTENSION_ACTIVITY_DOM_VERB_INSERTED;
  if (enum_string == "xhr")
    return EXTENSION_ACTIVITY_DOM_VERB_XHR;
  if (enum_string == "webrequest")
    return EXTENSION_ACTIVITY_DOM_VERB_WEBREQUEST;
  if (enum_string == "modified")
    return EXTENSION_ACTIVITY_DOM_VERB_MODIFIED;
  return EXTENSION_ACTIVITY_DOM_VERB_NONE;
}


ExtensionActivity::Other::Other()
: dom_verb(EXTENSION_ACTIVITY_DOM_VERB_NONE) {}

ExtensionActivity::Other::~Other() {}
ExtensionActivity::Other::Other(Other&& rhs)
: prerender(std::move(rhs.prerender)),
dom_verb(rhs.dom_verb),
web_request(std::move(rhs.web_request)),
extra(std::move(rhs.extra)){
}

ExtensionActivity::Other& ExtensionActivity::Other::operator=(Other&& rhs)
{
prerender = std::move(rhs.prerender);
dom_verb = rhs.dom_verb;
web_request = std::move(rhs.web_request);
extra = std::move(rhs.extra);
return *this;
}

// static
bool ExtensionActivity::Other::Populate(
    const base::Value& value, Other* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->dom_verb = EXTENSION_ACTIVITY_DOM_VERB_NONE;
  const base::Value* prerender_value = NULL;
  if (dict->GetWithoutPathExpansion("prerender", &prerender_value)) {
    {
      bool temp;
      if (!prerender_value->GetAsBoolean(&temp)) {
        out->prerender.reset();
        return false;
      }
      else
        out->prerender.reset(new bool(temp));
    }
  }

  const base::Value* dom_verb_value = NULL;
  if (dict->GetWithoutPathExpansion("domVerb", &dom_verb_value)) {
    {
      std::string extension_activity_dom_verb_as_string;
      if (!dom_verb_value->GetAsString(&extension_activity_dom_verb_as_string)) {
        return false;
      }
      out->dom_verb = ParseExtensionActivityDomVerb(extension_activity_dom_verb_as_string);
      if (out->dom_verb == EXTENSION_ACTIVITY_DOM_VERB_NONE) {
        return false;
      }
    }
    } else {
    out->dom_verb = EXTENSION_ACTIVITY_DOM_VERB_NONE;
  }

  const base::Value* web_request_value = NULL;
  if (dict->GetWithoutPathExpansion("webRequest", &web_request_value)) {
    {
      std::string temp;
      if (!web_request_value->GetAsString(&temp)) {
        out->web_request.reset();
        return false;
      }
      else
        out->web_request.reset(new std::string(temp));
    }
  }

  const base::Value* extra_value = NULL;
  if (dict->GetWithoutPathExpansion("extra", &extra_value)) {
    {
      std::string temp;
      if (!extra_value->GetAsString(&temp)) {
        out->extra.reset();
        return false;
      }
      else
        out->extra.reset(new std::string(temp));
    }
  }

  return true;
}

std::unique_ptr<base::DictionaryValue> ExtensionActivity::Other::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->prerender.get()) {
    to_value_result->SetWithoutPathExpansion("prerender", std::make_unique<base::Value>(*this->prerender));

  }
  if (this->dom_verb != EXTENSION_ACTIVITY_DOM_VERB_NONE) {
    to_value_result->SetWithoutPathExpansion("domVerb", std::make_unique<base::Value>(activity_log_private::ToString(this->dom_verb)));

  }
  if (this->web_request.get()) {
    to_value_result->SetWithoutPathExpansion("webRequest", std::make_unique<base::Value>(*this->web_request));

  }
  if (this->extra.get()) {
    to_value_result->SetWithoutPathExpansion("extra", std::make_unique<base::Value>(*this->extra));

  }

  return to_value_result;
}



ExtensionActivity::ExtensionActivity()
: activity_type(EXTENSION_ACTIVITY_TYPE_NONE) {}

ExtensionActivity::~ExtensionActivity() {}
ExtensionActivity::ExtensionActivity(ExtensionActivity&& rhs)
: activity_id(std::move(rhs.activity_id)),
extension_id(std::move(rhs.extension_id)),
activity_type(rhs.activity_type),
time(std::move(rhs.time)),
api_call(std::move(rhs.api_call)),
args(std::move(rhs.args)),
count(std::move(rhs.count)),
page_url(std::move(rhs.page_url)),
page_title(std::move(rhs.page_title)),
arg_url(std::move(rhs.arg_url)),
other(std::move(rhs.other)){
}

ExtensionActivity& ExtensionActivity::operator=(ExtensionActivity&& rhs)
{
activity_id = std::move(rhs.activity_id);
extension_id = std::move(rhs.extension_id);
activity_type = rhs.activity_type;
time = std::move(rhs.time);
api_call = std::move(rhs.api_call);
args = std::move(rhs.args);
count = std::move(rhs.count);
page_url = std::move(rhs.page_url);
page_title = std::move(rhs.page_title);
arg_url = std::move(rhs.arg_url);
other = std::move(rhs.other);
return *this;
}

// static
bool ExtensionActivity::Populate(
    const base::Value& value, ExtensionActivity* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* activity_id_value = NULL;
  if (dict->GetWithoutPathExpansion("activityId", &activity_id_value)) {
    {
      std::string temp;
      if (!activity_id_value->GetAsString(&temp)) {
        out->activity_id.reset();
        return false;
      }
      else
        out->activity_id.reset(new std::string(temp));
    }
  }

  const base::Value* extension_id_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    {
      std::string temp;
      if (!extension_id_value->GetAsString(&temp)) {
        out->extension_id.reset();
        return false;
      }
      else
        out->extension_id.reset(new std::string(temp));
    }
  }

  const base::Value* activity_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("activityType", &activity_type_value)) {
    return false;
  }
  {
    std::string extension_activity_type_as_string;
    if (!activity_type_value->GetAsString(&extension_activity_type_as_string)) {
      return false;
    }
    out->activity_type = ParseExtensionActivityType(extension_activity_type_as_string);
    if (out->activity_type == EXTENSION_ACTIVITY_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* time_value = NULL;
  if (dict->GetWithoutPathExpansion("time", &time_value)) {
    {
      double temp;
      if (!time_value->GetAsDouble(&temp)) {
        out->time.reset();
        return false;
      }
      else
        out->time.reset(new double(temp));
    }
  }

  const base::Value* api_call_value = NULL;
  if (dict->GetWithoutPathExpansion("apiCall", &api_call_value)) {
    {
      std::string temp;
      if (!api_call_value->GetAsString(&temp)) {
        out->api_call.reset();
        return false;
      }
      else
        out->api_call.reset(new std::string(temp));
    }
  }

  const base::Value* args_value = NULL;
  if (dict->GetWithoutPathExpansion("args", &args_value)) {
    {
      std::string temp;
      if (!args_value->GetAsString(&temp)) {
        out->args.reset();
        return false;
      }
      else
        out->args.reset(new std::string(temp));
    }
  }

  const base::Value* count_value = NULL;
  if (dict->GetWithoutPathExpansion("count", &count_value)) {
    {
      double temp;
      if (!count_value->GetAsDouble(&temp)) {
        out->count.reset();
        return false;
      }
      else
        out->count.reset(new double(temp));
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

  const base::Value* page_title_value = NULL;
  if (dict->GetWithoutPathExpansion("pageTitle", &page_title_value)) {
    {
      std::string temp;
      if (!page_title_value->GetAsString(&temp)) {
        out->page_title.reset();
        return false;
      }
      else
        out->page_title.reset(new std::string(temp));
    }
  }

  const base::Value* arg_url_value = NULL;
  if (dict->GetWithoutPathExpansion("argUrl", &arg_url_value)) {
    {
      std::string temp;
      if (!arg_url_value->GetAsString(&temp)) {
        out->arg_url.reset();
        return false;
      }
      else
        out->arg_url.reset(new std::string(temp));
    }
  }

  const base::Value* other_value = NULL;
  if (dict->GetWithoutPathExpansion("other", &other_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!other_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Other> temp(new Other());
        if (!Other::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->other = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ExtensionActivity> ExtensionActivity::FromValue(const base::Value& value) {
  std::unique_ptr<ExtensionActivity> out(new ExtensionActivity());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExtensionActivity::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->activity_id.get()) {
    to_value_result->SetWithoutPathExpansion("activityId", std::make_unique<base::Value>(*this->activity_id));

  }
  if (this->extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(*this->extension_id));

  }
  to_value_result->SetWithoutPathExpansion("activityType", std::make_unique<base::Value>(activity_log_private::ToString(this->activity_type)));

  if (this->time.get()) {
    to_value_result->SetWithoutPathExpansion("time", std::make_unique<base::Value>(*this->time));

  }
  if (this->api_call.get()) {
    to_value_result->SetWithoutPathExpansion("apiCall", std::make_unique<base::Value>(*this->api_call));

  }
  if (this->args.get()) {
    to_value_result->SetWithoutPathExpansion("args", std::make_unique<base::Value>(*this->args));

  }
  if (this->count.get()) {
    to_value_result->SetWithoutPathExpansion("count", std::make_unique<base::Value>(*this->count));

  }
  if (this->page_url.get()) {
    to_value_result->SetWithoutPathExpansion("pageUrl", std::make_unique<base::Value>(*this->page_url));

  }
  if (this->page_title.get()) {
    to_value_result->SetWithoutPathExpansion("pageTitle", std::make_unique<base::Value>(*this->page_title));

  }
  if (this->arg_url.get()) {
    to_value_result->SetWithoutPathExpansion("argUrl", std::make_unique<base::Value>(*this->arg_url));

  }
  if (this->other.get()) {
    to_value_result->SetWithoutPathExpansion("other", (this->other)->ToValue());

  }

  return to_value_result;
}


Filter::Filter()
: activity_type(EXTENSION_ACTIVITY_FILTER_NONE) {}

Filter::~Filter() {}
Filter::Filter(Filter&& rhs)
: extension_id(std::move(rhs.extension_id)),
activity_type(rhs.activity_type),
api_call(std::move(rhs.api_call)),
page_url(std::move(rhs.page_url)),
arg_url(std::move(rhs.arg_url)),
days_ago(std::move(rhs.days_ago)){
}

Filter& Filter::operator=(Filter&& rhs)
{
extension_id = std::move(rhs.extension_id);
activity_type = rhs.activity_type;
api_call = std::move(rhs.api_call);
page_url = std::move(rhs.page_url);
arg_url = std::move(rhs.arg_url);
days_ago = std::move(rhs.days_ago);
return *this;
}

// static
bool Filter::Populate(
    const base::Value& value, Filter* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* extension_id_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionId", &extension_id_value)) {
    {
      std::string temp;
      if (!extension_id_value->GetAsString(&temp)) {
        out->extension_id.reset();
        return false;
      }
      else
        out->extension_id.reset(new std::string(temp));
    }
  }

  const base::Value* activity_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("activityType", &activity_type_value)) {
    return false;
  }
  {
    std::string extension_activity_filter_as_string;
    if (!activity_type_value->GetAsString(&extension_activity_filter_as_string)) {
      return false;
    }
    out->activity_type = ParseExtensionActivityFilter(extension_activity_filter_as_string);
    if (out->activity_type == EXTENSION_ACTIVITY_FILTER_NONE) {
      return false;
    }
  }

  const base::Value* api_call_value = NULL;
  if (dict->GetWithoutPathExpansion("apiCall", &api_call_value)) {
    {
      std::string temp;
      if (!api_call_value->GetAsString(&temp)) {
        out->api_call.reset();
        return false;
      }
      else
        out->api_call.reset(new std::string(temp));
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

  const base::Value* arg_url_value = NULL;
  if (dict->GetWithoutPathExpansion("argUrl", &arg_url_value)) {
    {
      std::string temp;
      if (!arg_url_value->GetAsString(&temp)) {
        out->arg_url.reset();
        return false;
      }
      else
        out->arg_url.reset(new std::string(temp));
    }
  }

  const base::Value* days_ago_value = NULL;
  if (dict->GetWithoutPathExpansion("daysAgo", &days_ago_value)) {
    {
      int temp;
      if (!days_ago_value->GetAsInteger(&temp)) {
        out->days_ago.reset();
        return false;
      }
      else
        out->days_ago.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Filter> Filter::FromValue(const base::Value& value) {
  std::unique_ptr<Filter> out(new Filter());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Filter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->extension_id.get()) {
    to_value_result->SetWithoutPathExpansion("extensionId", std::make_unique<base::Value>(*this->extension_id));

  }
  to_value_result->SetWithoutPathExpansion("activityType", std::make_unique<base::Value>(activity_log_private::ToString(this->activity_type)));

  if (this->api_call.get()) {
    to_value_result->SetWithoutPathExpansion("apiCall", std::make_unique<base::Value>(*this->api_call));

  }
  if (this->page_url.get()) {
    to_value_result->SetWithoutPathExpansion("pageUrl", std::make_unique<base::Value>(*this->page_url));

  }
  if (this->arg_url.get()) {
    to_value_result->SetWithoutPathExpansion("argUrl", std::make_unique<base::Value>(*this->arg_url));

  }
  if (this->days_ago.get()) {
    to_value_result->SetWithoutPathExpansion("daysAgo", std::make_unique<base::Value>(*this->days_ago));

  }

  return to_value_result;
}


ActivityResultSet::ActivityResultSet()
 {}

ActivityResultSet::~ActivityResultSet() {}
ActivityResultSet::ActivityResultSet(ActivityResultSet&& rhs)
: activities(std::move(rhs.activities)){
}

ActivityResultSet& ActivityResultSet::operator=(ActivityResultSet&& rhs)
{
activities = std::move(rhs.activities);
return *this;
}

// static
bool ActivityResultSet::Populate(
    const base::Value& value, ActivityResultSet* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* activities_value = NULL;
  if (!dict->GetWithoutPathExpansion("activities", &activities_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!activities_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->activities)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ActivityResultSet> ActivityResultSet::FromValue(const base::Value& value) {
  std::unique_ptr<ActivityResultSet> out(new ActivityResultSet());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ActivityResultSet::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("activities", json_schema_compiler::util::CreateValueFromArray(this->activities));


  return to_value_result;
}



//
// Functions
//

namespace GetExtensionActivities {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* filter_value = NULL;
  if (args.Get(0, &filter_value) &&
      !filter_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!filter_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Filter::Populate(*dictionary, &params->filter)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ActivityResultSet& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetExtensionActivities

namespace DeleteActivities {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* activity_ids_value = NULL;
  if (args.Get(0, &activity_ids_value) &&
      !activity_ids_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!activity_ids_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->activity_ids)) {
          return std::unique_ptr<Params>();
        }
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
}  // namespace DeleteActivities

namespace DeleteActivitiesByExtension {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* extension_id_value = NULL;
  if (args.Get(0, &extension_id_value) &&
      !extension_id_value->is_none()) {
    {
      if (!extension_id_value->GetAsString(&params->extension_id)) {
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
}  // namespace DeleteActivitiesByExtension

namespace DeleteDatabase {

}  // namespace DeleteDatabase

namespace DeleteUrls {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* urls_value = NULL;
  if (args.Get(0, &urls_value) &&
      !urls_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!urls_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &params->urls)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }

  return params;
}


}  // namespace DeleteUrls

//
// Events
//

namespace OnExtensionActivity {

const char kEventName[] = "activityLogPrivate.onExtensionActivity";

std::unique_ptr<base::ListValue> Create(const ExtensionActivity& activity) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((activity).ToValue());

  return create_results;
}

}  // namespace OnExtensionActivity

}  // namespace activity_log_private
}  // namespace api
}  // namespace extensions

