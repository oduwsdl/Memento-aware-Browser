// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/history.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/history.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace history {
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
    case TRANSITION_TYPE_AUTO_TOPLEVEL:
      return "auto_toplevel";
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
  if (enum_string == "auto_toplevel")
    return TRANSITION_TYPE_AUTO_TOPLEVEL;
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


HistoryItem::HistoryItem()
 {}

HistoryItem::~HistoryItem() {}
HistoryItem::HistoryItem(HistoryItem&& rhs)
: id(std::move(rhs.id)),
url(std::move(rhs.url)),
title(std::move(rhs.title)),
last_visit_time(std::move(rhs.last_visit_time)),
visit_count(std::move(rhs.visit_count)),
typed_count(std::move(rhs.typed_count)){
}

HistoryItem& HistoryItem::operator=(HistoryItem&& rhs)
{
id = std::move(rhs.id);
url = std::move(rhs.url);
title = std::move(rhs.title);
last_visit_time = std::move(rhs.last_visit_time);
visit_count = std::move(rhs.visit_count);
typed_count = std::move(rhs.typed_count);
return *this;
}

// static
bool HistoryItem::Populate(
    const base::Value& value, HistoryItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
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

  const base::Value* title_value = NULL;
  if (dict->GetWithoutPathExpansion("title", &title_value)) {
    {
      std::string temp;
      if (!title_value->GetAsString(&temp)) {
        out->title.reset();
        return false;
      }
      else
        out->title.reset(new std::string(temp));
    }
  }

  const base::Value* last_visit_time_value = NULL;
  if (dict->GetWithoutPathExpansion("lastVisitTime", &last_visit_time_value)) {
    {
      double temp;
      if (!last_visit_time_value->GetAsDouble(&temp)) {
        out->last_visit_time.reset();
        return false;
      }
      else
        out->last_visit_time.reset(new double(temp));
    }
  }

  const base::Value* visit_count_value = NULL;
  if (dict->GetWithoutPathExpansion("visitCount", &visit_count_value)) {
    {
      int temp;
      if (!visit_count_value->GetAsInteger(&temp)) {
        out->visit_count.reset();
        return false;
      }
      else
        out->visit_count.reset(new int(temp));
    }
  }

  const base::Value* typed_count_value = NULL;
  if (dict->GetWithoutPathExpansion("typedCount", &typed_count_value)) {
    {
      int temp;
      if (!typed_count_value->GetAsInteger(&temp)) {
        out->typed_count.reset();
        return false;
      }
      else
        out->typed_count.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<HistoryItem> HistoryItem::FromValue(const base::Value& value) {
  std::unique_ptr<HistoryItem> out(new HistoryItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> HistoryItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  if (this->title.get()) {
    to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(*this->title));

  }
  if (this->last_visit_time.get()) {
    to_value_result->SetWithoutPathExpansion("lastVisitTime", std::make_unique<base::Value>(*this->last_visit_time));

  }
  if (this->visit_count.get()) {
    to_value_result->SetWithoutPathExpansion("visitCount", std::make_unique<base::Value>(*this->visit_count));

  }
  if (this->typed_count.get()) {
    to_value_result->SetWithoutPathExpansion("typedCount", std::make_unique<base::Value>(*this->typed_count));

  }

  return to_value_result;
}


VisitItem::VisitItem()
: transition(TRANSITION_TYPE_NONE) {}

VisitItem::~VisitItem() {}
VisitItem::VisitItem(VisitItem&& rhs)
: id(std::move(rhs.id)),
visit_id(std::move(rhs.visit_id)),
visit_time(std::move(rhs.visit_time)),
referring_visit_id(std::move(rhs.referring_visit_id)),
transition(rhs.transition){
}

VisitItem& VisitItem::operator=(VisitItem&& rhs)
{
id = std::move(rhs.id);
visit_id = std::move(rhs.visit_id);
visit_time = std::move(rhs.visit_time);
referring_visit_id = std::move(rhs.referring_visit_id);
transition = rhs.transition;
return *this;
}

// static
bool VisitItem::Populate(
    const base::Value& value, VisitItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* visit_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("visitId", &visit_id_value)) {
    return false;
  }
  {
    if (!visit_id_value->GetAsString(&out->visit_id)) {
      return false;
    }
  }

  const base::Value* visit_time_value = NULL;
  if (dict->GetWithoutPathExpansion("visitTime", &visit_time_value)) {
    {
      double temp;
      if (!visit_time_value->GetAsDouble(&temp)) {
        out->visit_time.reset();
        return false;
      }
      else
        out->visit_time.reset(new double(temp));
    }
  }

  const base::Value* referring_visit_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("referringVisitId", &referring_visit_id_value)) {
    return false;
  }
  {
    if (!referring_visit_id_value->GetAsString(&out->referring_visit_id)) {
      return false;
    }
  }

  const base::Value* transition_value = NULL;
  if (!dict->GetWithoutPathExpansion("transition", &transition_value)) {
    return false;
  }
  {
    std::string transition_type_as_string;
    if (!transition_value->GetAsString(&transition_type_as_string)) {
      return false;
    }
    out->transition = ParseTransitionType(transition_type_as_string);
    if (out->transition == TRANSITION_TYPE_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<VisitItem> VisitItem::FromValue(const base::Value& value) {
  std::unique_ptr<VisitItem> out(new VisitItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> VisitItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("visitId", std::make_unique<base::Value>(this->visit_id));

  if (this->visit_time.get()) {
    to_value_result->SetWithoutPathExpansion("visitTime", std::make_unique<base::Value>(*this->visit_time));

  }
  to_value_result->SetWithoutPathExpansion("referringVisitId", std::make_unique<base::Value>(this->referring_visit_id));

  to_value_result->SetWithoutPathExpansion("transition", std::make_unique<base::Value>(history::ToString(this->transition)));


  return to_value_result;
}



//
// Functions
//

namespace Search {

Params::Query::Query()
 {}

Params::Query::~Query() {}
Params::Query::Query(Query&& rhs)
: text(std::move(rhs.text)),
start_time(std::move(rhs.start_time)),
end_time(std::move(rhs.end_time)),
max_results(std::move(rhs.max_results)){
}

Params::Query& Params::Query::operator=(Query&& rhs)
{
text = std::move(rhs.text);
start_time = std::move(rhs.start_time);
end_time = std::move(rhs.end_time);
max_results = std::move(rhs.max_results);
return *this;
}

// static
bool Params::Query::Populate(
    const base::Value& value, Query* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* text_value = NULL;
  if (!dict->GetWithoutPathExpansion("text", &text_value)) {
    return false;
  }
  {
    if (!text_value->GetAsString(&out->text)) {
      return false;
    }
  }

  const base::Value* start_time_value = NULL;
  if (dict->GetWithoutPathExpansion("startTime", &start_time_value)) {
    {
      double temp;
      if (!start_time_value->GetAsDouble(&temp)) {
        out->start_time.reset();
        return false;
      }
      else
        out->start_time.reset(new double(temp));
    }
  }

  const base::Value* end_time_value = NULL;
  if (dict->GetWithoutPathExpansion("endTime", &end_time_value)) {
    {
      double temp;
      if (!end_time_value->GetAsDouble(&temp)) {
        out->end_time.reset();
        return false;
      }
      else
        out->end_time.reset(new double(temp));
    }
  }

  const base::Value* max_results_value = NULL;
  if (dict->GetWithoutPathExpansion("maxResults", &max_results_value)) {
    {
      int temp;
      if (!max_results_value->GetAsInteger(&temp)) {
        out->max_results.reset();
        return false;
      }
      else
        out->max_results.reset(new int(temp));
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

  const base::Value* query_value = NULL;
  if (args.Get(0, &query_value) &&
      !query_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!query_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Query::Populate(*dictionary, &params->query)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<HistoryItem>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace Search

namespace GetVisits {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: url(std::move(rhs.url)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<VisitItem>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace GetVisits

namespace AddUrl {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: url(std::move(rhs.url)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace AddUrl

namespace DeleteUrl {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: url(std::move(rhs.url)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace DeleteUrl

namespace DeleteRange {

Params::Range::Range()
: start_time(0.0),
end_time(0.0) {}

Params::Range::~Range() {}
Params::Range::Range(Range&& rhs)
: start_time(rhs.start_time),
end_time(rhs.end_time){
}

Params::Range& Params::Range::operator=(Range&& rhs)
{
start_time = rhs.start_time;
end_time = rhs.end_time;
return *this;
}

// static
bool Params::Range::Populate(
    const base::Value& value, Range* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* start_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("startTime", &start_time_value)) {
    return false;
  }
  {
    if (!start_time_value->GetAsDouble(&out->start_time)) {
      return false;
    }
  }

  const base::Value* end_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("endTime", &end_time_value)) {
    return false;
  }
  {
    if (!end_time_value->GetAsDouble(&out->end_time)) {
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

  const base::Value* range_value = NULL;
  if (args.Get(0, &range_value) &&
      !range_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!range_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Range::Populate(*dictionary, &params->range)) {
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
}  // namespace DeleteRange

namespace DeleteAll {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace DeleteAll

//
// Events
//

namespace OnVisited {

const char kEventName[] = "history.onVisited";

std::unique_ptr<base::ListValue> Create(const HistoryItem& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}

}  // namespace OnVisited

namespace OnVisitRemoved {

const char kEventName[] = "history.onVisitRemoved";

Removed::Removed()
: all_history(false) {}

Removed::~Removed() {}
Removed::Removed(Removed&& rhs)
: all_history(rhs.all_history),
urls(std::move(rhs.urls)){
}

Removed& Removed::operator=(Removed&& rhs)
{
all_history = rhs.all_history;
urls = std::move(rhs.urls);
return *this;
}

std::unique_ptr<base::DictionaryValue> Removed::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("allHistory", std::make_unique<base::Value>(this->all_history));

  if (this->urls.get()) {
    to_value_result->SetWithoutPathExpansion("urls", json_schema_compiler::util::CreateValueFromOptionalArray(this->urls));

  }

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Removed& removed) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((removed).ToValue());

  return create_results;
}

}  // namespace OnVisitRemoved

}  // namespace history
}  // namespace api
}  // namespace extensions

