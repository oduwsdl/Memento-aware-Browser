// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/web_navigation.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/web_navigation.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace web_navigation {
//
// Types
//

const char* ToString(TransitionType enum_param) {
  switch (enum_param) {
    case TRANSITION_TYPE_LINK:
      return "link";
    case TRANSITION_TYPE_TYPED:
      return "typed";
    case TRANSITION_TYPE_AUTO_BOOKMARK:
      return "auto_bookmark";
    case TRANSITION_TYPE_AUTO_SUBFRAME:
      return "auto_subframe";
    case TRANSITION_TYPE_MANUAL_SUBFRAME:
      return "manual_subframe";
    case TRANSITION_TYPE_GENERATED:
      return "generated";
    case TRANSITION_TYPE_START_PAGE:
      return "start_page";
    case TRANSITION_TYPE_FORM_SUBMIT:
      return "form_submit";
    case TRANSITION_TYPE_RELOAD:
      return "reload";
    case TRANSITION_TYPE_KEYWORD:
      return "keyword";
    case TRANSITION_TYPE_KEYWORD_GENERATED:
      return "keyword_generated";
    case TRANSITION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TransitionType ParseTransitionType(const std::string& enum_string) {
  if (enum_string == "link")
    return TRANSITION_TYPE_LINK;
  if (enum_string == "typed")
    return TRANSITION_TYPE_TYPED;
  if (enum_string == "auto_bookmark")
    return TRANSITION_TYPE_AUTO_BOOKMARK;
  if (enum_string == "auto_subframe")
    return TRANSITION_TYPE_AUTO_SUBFRAME;
  if (enum_string == "manual_subframe")
    return TRANSITION_TYPE_MANUAL_SUBFRAME;
  if (enum_string == "generated")
    return TRANSITION_TYPE_GENERATED;
  if (enum_string == "start_page")
    return TRANSITION_TYPE_START_PAGE;
  if (enum_string == "form_submit")
    return TRANSITION_TYPE_FORM_SUBMIT;
  if (enum_string == "reload")
    return TRANSITION_TYPE_RELOAD;
  if (enum_string == "keyword")
    return TRANSITION_TYPE_KEYWORD;
  if (enum_string == "keyword_generated")
    return TRANSITION_TYPE_KEYWORD_GENERATED;
  return TRANSITION_TYPE_NONE;
}


const char* ToString(TransitionQualifier enum_param) {
  switch (enum_param) {
    case TRANSITION_QUALIFIER_CLIENT_REDIRECT:
      return "client_redirect";
    case TRANSITION_QUALIFIER_SERVER_REDIRECT:
      return "server_redirect";
    case TRANSITION_QUALIFIER_FORWARD_BACK:
      return "forward_back";
    case TRANSITION_QUALIFIER_FROM_ADDRESS_BAR:
      return "from_address_bar";
    case TRANSITION_QUALIFIER_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TransitionQualifier ParseTransitionQualifier(const std::string& enum_string) {
  if (enum_string == "client_redirect")
    return TRANSITION_QUALIFIER_CLIENT_REDIRECT;
  if (enum_string == "server_redirect")
    return TRANSITION_QUALIFIER_SERVER_REDIRECT;
  if (enum_string == "forward_back")
    return TRANSITION_QUALIFIER_FORWARD_BACK;
  if (enum_string == "from_address_bar")
    return TRANSITION_QUALIFIER_FROM_ADDRESS_BAR;
  return TRANSITION_QUALIFIER_NONE;
}



//
// Functions
//

namespace GetFrame {

Params::Details::Details()
: tab_id(0),
frame_id(0) {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
process_id(std::move(rhs.process_id)),
frame_id(rhs.frame_id){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
process_id = std::move(rhs.process_id);
frame_id = rhs.frame_id;
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tab_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    return false;
  }
  {
    if (!tab_id_value->GetAsInteger(&out->tab_id)) {
      return false;
    }
  }

  const base::Value* process_id_value = NULL;
  if (dict->GetWithoutPathExpansion("processId", &process_id_value)) {
    {
      int temp;
      if (!process_id_value->GetAsInteger(&temp)) {
        out->process_id.reset();
        return false;
      }
      else
        out->process_id.reset(new int(temp));
    }
  }

  const base::Value* frame_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("frameId", &frame_id_value)) {
    return false;
  }
  {
    if (!frame_id_value->GetAsInteger(&out->frame_id)) {
      return false;
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Details::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Details::Details()
: error_occurred(false),
parent_frame_id(0) {}

Results::Details::~Details() {}
Results::Details::Details(Details&& rhs)
: error_occurred(rhs.error_occurred),
url(std::move(rhs.url)),
parent_frame_id(rhs.parent_frame_id){
}

Results::Details& Results::Details::operator=(Details&& rhs)
{
error_occurred = rhs.error_occurred;
url = std::move(rhs.url);
parent_frame_id = rhs.parent_frame_id;
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("errorOccurred", std::make_unique<base::Value>(this->error_occurred));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}
}  // namespace GetFrame

namespace GetAllFrames {

Params::Details::Details()
: tab_id(0) {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: tab_id(rhs.tab_id){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* tab_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    return false;
  }
  {
    if (!tab_id_value->GetAsInteger(&out->tab_id)) {
      return false;
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Details::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::DetailsType::DetailsType()
: error_occurred(false),
process_id(0),
frame_id(0),
parent_frame_id(0) {}

Results::DetailsType::~DetailsType() {}
Results::DetailsType::DetailsType(DetailsType&& rhs)
: error_occurred(rhs.error_occurred),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
url(std::move(rhs.url)){
}

Results::DetailsType& Results::DetailsType::operator=(DetailsType&& rhs)
{
error_occurred = rhs.error_occurred;
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
url = std::move(rhs.url);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::DetailsType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("errorOccurred", std::make_unique<base::Value>(this->error_occurred));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));


  return to_value_result;
}



std::unique_ptr<base::ListValue> Results::Create(const std::vector<DetailsType>& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(details));

  return create_results;
}
}  // namespace GetAllFrames

//
// Events
//

namespace OnBeforeNavigate {

const char kEventName[] = "webNavigation.onBeforeNavigate";

Details::Details()
: tab_id(0),
process_id(0),
frame_id(0),
parent_frame_id(0),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
url(std::move(rhs.url)),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
url = std::move(rhs.url);
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnBeforeNavigate

namespace OnCommitted {

const char kEventName[] = "webNavigation.onCommitted";

Details::Details()
: tab_id(0),
process_id(0),
frame_id(0),
parent_frame_id(0),
transition_type(TRANSITION_TYPE_NONE),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
url(std::move(rhs.url)),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
transition_type(rhs.transition_type),
transition_qualifiers(std::move(rhs.transition_qualifiers)),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
url = std::move(rhs.url);
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
transition_type = rhs.transition_type;
transition_qualifiers = std::move(rhs.transition_qualifiers);
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("transitionType", std::make_unique<base::Value>(web_navigation::ToString(this->transition_type)));

  {
    std::vector<std::string> transitionQualifiers_list;
    for (const auto& it : (this->transition_qualifiers)) {
    transitionQualifiers_list.push_back(web_navigation::ToString(it));
  }
  to_value_result->SetWithoutPathExpansion("transitionQualifiers", json_schema_compiler::util::CreateValueFromArray(transitionQualifiers_list));
  }

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnCommitted

namespace OnDOMContentLoaded {

const char kEventName[] = "webNavigation.onDOMContentLoaded";

Details::Details()
: tab_id(0),
process_id(0),
frame_id(0),
parent_frame_id(0),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
url(std::move(rhs.url)),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
url = std::move(rhs.url);
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnDOMContentLoaded

namespace OnCompleted {

const char kEventName[] = "webNavigation.onCompleted";

Details::Details()
: tab_id(0),
process_id(0),
frame_id(0),
parent_frame_id(0),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
url(std::move(rhs.url)),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
url = std::move(rhs.url);
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnCompleted

namespace OnErrorOccurred {

const char kEventName[] = "webNavigation.onErrorOccurred";

Details::Details()
: tab_id(0),
process_id(0),
frame_id(0),
parent_frame_id(0),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
url(std::move(rhs.url)),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
error(std::move(rhs.error)),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
url = std::move(rhs.url);
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
error = std::move(rhs.error);
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(this->error));

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnErrorOccurred

namespace OnCreatedNavigationTarget {

const char kEventName[] = "webNavigation.onCreatedNavigationTarget";

Details::Details()
: source_tab_id(0),
source_process_id(0),
source_frame_id(0),
tab_id(0),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: source_tab_id(rhs.source_tab_id),
source_process_id(rhs.source_process_id),
source_frame_id(rhs.source_frame_id),
url(std::move(rhs.url)),
tab_id(rhs.tab_id),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
source_tab_id = rhs.source_tab_id;
source_process_id = rhs.source_process_id;
source_frame_id = rhs.source_frame_id;
url = std::move(rhs.url);
tab_id = rhs.tab_id;
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("sourceTabId", std::make_unique<base::Value>(this->source_tab_id));

  to_value_result->SetWithoutPathExpansion("sourceProcessId", std::make_unique<base::Value>(this->source_process_id));

  to_value_result->SetWithoutPathExpansion("sourceFrameId", std::make_unique<base::Value>(this->source_frame_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnCreatedNavigationTarget

namespace OnReferenceFragmentUpdated {

const char kEventName[] = "webNavigation.onReferenceFragmentUpdated";

Details::Details()
: tab_id(0),
process_id(0),
frame_id(0),
parent_frame_id(0),
transition_type(TRANSITION_TYPE_NONE),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
url(std::move(rhs.url)),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
transition_type(rhs.transition_type),
transition_qualifiers(std::move(rhs.transition_qualifiers)),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
url = std::move(rhs.url);
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
transition_type = rhs.transition_type;
transition_qualifiers = std::move(rhs.transition_qualifiers);
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("transitionType", std::make_unique<base::Value>(web_navigation::ToString(this->transition_type)));

  {
    std::vector<std::string> transitionQualifiers_list;
    for (const auto& it : (this->transition_qualifiers)) {
    transitionQualifiers_list.push_back(web_navigation::ToString(it));
  }
  to_value_result->SetWithoutPathExpansion("transitionQualifiers", json_schema_compiler::util::CreateValueFromArray(transitionQualifiers_list));
  }

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnReferenceFragmentUpdated

namespace OnTabReplaced {

const char kEventName[] = "webNavigation.onTabReplaced";

Details::Details()
: replaced_tab_id(0),
tab_id(0),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: replaced_tab_id(rhs.replaced_tab_id),
tab_id(rhs.tab_id),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
replaced_tab_id = rhs.replaced_tab_id;
tab_id = rhs.tab_id;
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("replacedTabId", std::make_unique<base::Value>(this->replaced_tab_id));

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnTabReplaced

namespace OnHistoryStateUpdated {

const char kEventName[] = "webNavigation.onHistoryStateUpdated";

Details::Details()
: tab_id(0),
process_id(0),
frame_id(0),
parent_frame_id(0),
transition_type(TRANSITION_TYPE_NONE),
time_stamp(0.0) {}

Details::~Details() {}
Details::Details(Details&& rhs)
: tab_id(rhs.tab_id),
url(std::move(rhs.url)),
process_id(rhs.process_id),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
transition_type(rhs.transition_type),
transition_qualifiers(std::move(rhs.transition_qualifiers)),
time_stamp(rhs.time_stamp){
}

Details& Details::operator=(Details&& rhs)
{
tab_id = rhs.tab_id;
url = std::move(rhs.url);
process_id = rhs.process_id;
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
transition_type = rhs.transition_type;
transition_qualifiers = std::move(rhs.transition_qualifiers);
time_stamp = rhs.time_stamp;
return *this;
}

std::unique_ptr<base::DictionaryValue> Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("processId", std::make_unique<base::Value>(this->process_id));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("transitionType", std::make_unique<base::Value>(web_navigation::ToString(this->transition_type)));

  {
    std::vector<std::string> transitionQualifiers_list;
    for (const auto& it : (this->transition_qualifiers)) {
    transitionQualifiers_list.push_back(web_navigation::ToString(it));
  }
  to_value_result->SetWithoutPathExpansion("transitionQualifiers", json_schema_compiler::util::CreateValueFromArray(transitionQualifiers_list));
  }

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}

}  // namespace OnHistoryStateUpdated

}  // namespace web_navigation
}  // namespace api
}  // namespace extensions

