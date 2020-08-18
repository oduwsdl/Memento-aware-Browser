// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/web_view_internal.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/web_view_internal.h"
#include <set>
#include <utility>
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"
#include "extensions/common/api/extension_types.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace web_view_internal {
//
// Types
//

DataTypeSet::DataTypeSet()
 {}

DataTypeSet::~DataTypeSet() {}
DataTypeSet::DataTypeSet(DataTypeSet&& rhs)
: appcache(std::move(rhs.appcache)),
cookies(std::move(rhs.cookies)),
session_cookies(std::move(rhs.session_cookies)),
persistent_cookies(std::move(rhs.persistent_cookies)),
file_systems(std::move(rhs.file_systems)),
indexed_db(std::move(rhs.indexed_db)),
local_storage(std::move(rhs.local_storage)),
web_sql(std::move(rhs.web_sql)),
cache(std::move(rhs.cache)){
}

DataTypeSet& DataTypeSet::operator=(DataTypeSet&& rhs)
{
appcache = std::move(rhs.appcache);
cookies = std::move(rhs.cookies);
session_cookies = std::move(rhs.session_cookies);
persistent_cookies = std::move(rhs.persistent_cookies);
file_systems = std::move(rhs.file_systems);
indexed_db = std::move(rhs.indexed_db);
local_storage = std::move(rhs.local_storage);
web_sql = std::move(rhs.web_sql);
cache = std::move(rhs.cache);
return *this;
}

// static
bool DataTypeSet::Populate(
    const base::Value& value, DataTypeSet* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* appcache_value = NULL;
  if (dict->GetWithoutPathExpansion("appcache", &appcache_value)) {
    {
      bool temp;
      if (!appcache_value->GetAsBoolean(&temp)) {
        out->appcache.reset();
        return false;
      }
      else
        out->appcache.reset(new bool(temp));
    }
  }

  const base::Value* cookies_value = NULL;
  if (dict->GetWithoutPathExpansion("cookies", &cookies_value)) {
    {
      bool temp;
      if (!cookies_value->GetAsBoolean(&temp)) {
        out->cookies.reset();
        return false;
      }
      else
        out->cookies.reset(new bool(temp));
    }
  }

  const base::Value* session_cookies_value = NULL;
  if (dict->GetWithoutPathExpansion("sessionCookies", &session_cookies_value)) {
    {
      bool temp;
      if (!session_cookies_value->GetAsBoolean(&temp)) {
        out->session_cookies.reset();
        return false;
      }
      else
        out->session_cookies.reset(new bool(temp));
    }
  }

  const base::Value* persistent_cookies_value = NULL;
  if (dict->GetWithoutPathExpansion("persistentCookies", &persistent_cookies_value)) {
    {
      bool temp;
      if (!persistent_cookies_value->GetAsBoolean(&temp)) {
        out->persistent_cookies.reset();
        return false;
      }
      else
        out->persistent_cookies.reset(new bool(temp));
    }
  }

  const base::Value* file_systems_value = NULL;
  if (dict->GetWithoutPathExpansion("fileSystems", &file_systems_value)) {
    {
      bool temp;
      if (!file_systems_value->GetAsBoolean(&temp)) {
        out->file_systems.reset();
        return false;
      }
      else
        out->file_systems.reset(new bool(temp));
    }
  }

  const base::Value* indexed_db_value = NULL;
  if (dict->GetWithoutPathExpansion("indexedDB", &indexed_db_value)) {
    {
      bool temp;
      if (!indexed_db_value->GetAsBoolean(&temp)) {
        out->indexed_db.reset();
        return false;
      }
      else
        out->indexed_db.reset(new bool(temp));
    }
  }

  const base::Value* local_storage_value = NULL;
  if (dict->GetWithoutPathExpansion("localStorage", &local_storage_value)) {
    {
      bool temp;
      if (!local_storage_value->GetAsBoolean(&temp)) {
        out->local_storage.reset();
        return false;
      }
      else
        out->local_storage.reset(new bool(temp));
    }
  }

  const base::Value* web_sql_value = NULL;
  if (dict->GetWithoutPathExpansion("webSQL", &web_sql_value)) {
    {
      bool temp;
      if (!web_sql_value->GetAsBoolean(&temp)) {
        out->web_sql.reset();
        return false;
      }
      else
        out->web_sql.reset(new bool(temp));
    }
  }

  const base::Value* cache_value = NULL;
  if (dict->GetWithoutPathExpansion("cache", &cache_value)) {
    {
      bool temp;
      if (!cache_value->GetAsBoolean(&temp)) {
        out->cache.reset();
        return false;
      }
      else
        out->cache.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DataTypeSet> DataTypeSet::FromValue(const base::Value& value) {
  std::unique_ptr<DataTypeSet> out(new DataTypeSet());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DataTypeSet::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->appcache.get()) {
    to_value_result->SetWithoutPathExpansion("appcache", std::make_unique<base::Value>(*this->appcache));

  }
  if (this->cookies.get()) {
    to_value_result->SetWithoutPathExpansion("cookies", std::make_unique<base::Value>(*this->cookies));

  }
  if (this->session_cookies.get()) {
    to_value_result->SetWithoutPathExpansion("sessionCookies", std::make_unique<base::Value>(*this->session_cookies));

  }
  if (this->persistent_cookies.get()) {
    to_value_result->SetWithoutPathExpansion("persistentCookies", std::make_unique<base::Value>(*this->persistent_cookies));

  }
  if (this->file_systems.get()) {
    to_value_result->SetWithoutPathExpansion("fileSystems", std::make_unique<base::Value>(*this->file_systems));

  }
  if (this->indexed_db.get()) {
    to_value_result->SetWithoutPathExpansion("indexedDB", std::make_unique<base::Value>(*this->indexed_db));

  }
  if (this->local_storage.get()) {
    to_value_result->SetWithoutPathExpansion("localStorage", std::make_unique<base::Value>(*this->local_storage));

  }
  if (this->web_sql.get()) {
    to_value_result->SetWithoutPathExpansion("webSQL", std::make_unique<base::Value>(*this->web_sql));

  }
  if (this->cache.get()) {
    to_value_result->SetWithoutPathExpansion("cache", std::make_unique<base::Value>(*this->cache));

  }

  return to_value_result;
}


RemovalOptions::RemovalOptions()
 {}

RemovalOptions::~RemovalOptions() {}
RemovalOptions::RemovalOptions(RemovalOptions&& rhs)
: since(std::move(rhs.since)){
}

RemovalOptions& RemovalOptions::operator=(RemovalOptions&& rhs)
{
since = std::move(rhs.since);
return *this;
}

// static
bool RemovalOptions::Populate(
    const base::Value& value, RemovalOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* since_value = NULL;
  if (dict->GetWithoutPathExpansion("since", &since_value)) {
    {
      double temp;
      if (!since_value->GetAsDouble(&temp)) {
        out->since.reset();
        return false;
      }
      else
        out->since.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<RemovalOptions> RemovalOptions::FromValue(const base::Value& value) {
  std::unique_ptr<RemovalOptions> out(new RemovalOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RemovalOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->since.get()) {
    to_value_result->SetWithoutPathExpansion("since", std::make_unique<base::Value>(*this->since));

  }

  return to_value_result;
}


const char* ToString(ZoomMode enum_param) {
  switch (enum_param) {
    case ZOOM_MODE_PER_ORIGIN:
      return "per-origin";
    case ZOOM_MODE_PER_VIEW:
      return "per-view";
    case ZOOM_MODE_DISABLED:
      return "disabled";
    case ZOOM_MODE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ZoomMode ParseZoomMode(const std::string& enum_string) {
  if (enum_string == "per-origin")
    return ZOOM_MODE_PER_ORIGIN;
  if (enum_string == "per-view")
    return ZOOM_MODE_PER_VIEW;
  if (enum_string == "disabled")
    return ZOOM_MODE_DISABLED;
  return ZOOM_MODE_NONE;
}


const char* ToString(StopFindingAction enum_param) {
  switch (enum_param) {
    case STOP_FINDING_ACTION_CLEAR:
      return "clear";
    case STOP_FINDING_ACTION_KEEP:
      return "keep";
    case STOP_FINDING_ACTION_ACTIVATE:
      return "activate";
    case STOP_FINDING_ACTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

StopFindingAction ParseStopFindingAction(const std::string& enum_string) {
  if (enum_string == "clear")
    return STOP_FINDING_ACTION_CLEAR;
  if (enum_string == "keep")
    return STOP_FINDING_ACTION_KEEP;
  if (enum_string == "activate")
    return STOP_FINDING_ACTION_ACTIVATE;
  return STOP_FINDING_ACTION_NONE;
}


const char* ToString(SetPermissionAction enum_param) {
  switch (enum_param) {
    case SET_PERMISSION_ACTION_ALLOW:
      return "allow";
    case SET_PERMISSION_ACTION_DENY:
      return "deny";
    case SET_PERMISSION_ACTION_DEFAULT:
      return "default";
    case SET_PERMISSION_ACTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SetPermissionAction ParseSetPermissionAction(const std::string& enum_string) {
  if (enum_string == "allow")
    return SET_PERMISSION_ACTION_ALLOW;
  if (enum_string == "deny")
    return SET_PERMISSION_ACTION_DENY;
  if (enum_string == "default")
    return SET_PERMISSION_ACTION_DEFAULT;
  return SET_PERMISSION_ACTION_NONE;
}


InjectionItems::InjectionItems()
 {}

InjectionItems::~InjectionItems() {}
InjectionItems::InjectionItems(InjectionItems&& rhs)
: code(std::move(rhs.code)),
files(std::move(rhs.files)){
}

InjectionItems& InjectionItems::operator=(InjectionItems&& rhs)
{
code = std::move(rhs.code);
files = std::move(rhs.files);
return *this;
}

// static
bool InjectionItems::Populate(
    const base::Value& value, InjectionItems* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* code_value = NULL;
  if (dict->GetWithoutPathExpansion("code", &code_value)) {
    {
      std::string temp;
      if (!code_value->GetAsString(&temp)) {
        out->code.reset();
        return false;
      }
      else
        out->code.reset(new std::string(temp));
    }
  }

  const base::Value* files_value = NULL;
  if (dict->GetWithoutPathExpansion("files", &files_value)) {
    {
      const base::ListValue* list = NULL;
      if (!files_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->files)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<InjectionItems> InjectionItems::FromValue(const base::Value& value) {
  std::unique_ptr<InjectionItems> out(new InjectionItems());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> InjectionItems::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->code.get()) {
    to_value_result->SetWithoutPathExpansion("code", std::make_unique<base::Value>(*this->code));

  }
  if (this->files.get()) {
    to_value_result->SetWithoutPathExpansion("files", json_schema_compiler::util::CreateValueFromOptionalArray(this->files));

  }

  return to_value_result;
}


ContentScriptDetails::ContentScriptDetails()
: run_at(extension_types::RUN_AT_NONE) {}

ContentScriptDetails::~ContentScriptDetails() {}
ContentScriptDetails::ContentScriptDetails(ContentScriptDetails&& rhs)
: name(std::move(rhs.name)),
matches(std::move(rhs.matches)),
exclude_matches(std::move(rhs.exclude_matches)),
match_about_blank(std::move(rhs.match_about_blank)),
css(std::move(rhs.css)),
js(std::move(rhs.js)),
run_at(rhs.run_at),
all_frames(std::move(rhs.all_frames)),
include_globs(std::move(rhs.include_globs)),
exclude_globs(std::move(rhs.exclude_globs)){
}

ContentScriptDetails& ContentScriptDetails::operator=(ContentScriptDetails&& rhs)
{
name = std::move(rhs.name);
matches = std::move(rhs.matches);
exclude_matches = std::move(rhs.exclude_matches);
match_about_blank = std::move(rhs.match_about_blank);
css = std::move(rhs.css);
js = std::move(rhs.js);
run_at = rhs.run_at;
all_frames = std::move(rhs.all_frames);
include_globs = std::move(rhs.include_globs);
exclude_globs = std::move(rhs.exclude_globs);
return *this;
}

// static
bool ContentScriptDetails::Populate(
    const base::Value& value, ContentScriptDetails* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->run_at = extension_types::RUN_AT_NONE;
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* matches_value = NULL;
  if (!dict->GetWithoutPathExpansion("matches", &matches_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!matches_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->matches)) {
        return false;
      }
    }
  }

  const base::Value* exclude_matches_value = NULL;
  if (dict->GetWithoutPathExpansion("exclude_matches", &exclude_matches_value)) {
    {
      const base::ListValue* list = NULL;
      if (!exclude_matches_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->exclude_matches)) {
          return false;
        }
      }
    }
  }

  const base::Value* match_about_blank_value = NULL;
  if (dict->GetWithoutPathExpansion("match_about_blank", &match_about_blank_value)) {
    {
      bool temp;
      if (!match_about_blank_value->GetAsBoolean(&temp)) {
        out->match_about_blank.reset();
        return false;
      }
      else
        out->match_about_blank.reset(new bool(temp));
    }
  }

  const base::Value* css_value = NULL;
  if (dict->GetWithoutPathExpansion("css", &css_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!css_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<InjectionItems> temp(new InjectionItems());
        if (!InjectionItems::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->css = std::move(temp);
      }
    }
  }

  const base::Value* js_value = NULL;
  if (dict->GetWithoutPathExpansion("js", &js_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!js_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<InjectionItems> temp(new InjectionItems());
        if (!InjectionItems::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->js = std::move(temp);
      }
    }
  }

  const base::Value* run_at_value = NULL;
  if (dict->GetWithoutPathExpansion("run_at", &run_at_value)) {
    {
      std::string run_at_as_string;
      if (!run_at_value->GetAsString(&run_at_as_string)) {
        return false;
      }
      out->run_at = extension_types::ParseRunAt(run_at_as_string);
      if (out->run_at == extension_types::RUN_AT_NONE) {
        return false;
      }
    }
    } else {
    out->run_at = extension_types::RUN_AT_NONE;
  }

  const base::Value* all_frames_value = NULL;
  if (dict->GetWithoutPathExpansion("all_frames", &all_frames_value)) {
    {
      bool temp;
      if (!all_frames_value->GetAsBoolean(&temp)) {
        out->all_frames.reset();
        return false;
      }
      else
        out->all_frames.reset(new bool(temp));
    }
  }

  const base::Value* include_globs_value = NULL;
  if (dict->GetWithoutPathExpansion("include_globs", &include_globs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!include_globs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->include_globs)) {
          return false;
        }
      }
    }
  }

  const base::Value* exclude_globs_value = NULL;
  if (dict->GetWithoutPathExpansion("exclude_globs", &exclude_globs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!exclude_globs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->exclude_globs)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<ContentScriptDetails> ContentScriptDetails::FromValue(const base::Value& value) {
  std::unique_ptr<ContentScriptDetails> out(new ContentScriptDetails());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ContentScriptDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("matches", json_schema_compiler::util::CreateValueFromArray(this->matches));

  if (this->exclude_matches.get()) {
    to_value_result->SetWithoutPathExpansion("exclude_matches", json_schema_compiler::util::CreateValueFromOptionalArray(this->exclude_matches));

  }
  if (this->match_about_blank.get()) {
    to_value_result->SetWithoutPathExpansion("match_about_blank", std::make_unique<base::Value>(*this->match_about_blank));

  }
  if (this->css.get()) {
    to_value_result->SetWithoutPathExpansion("css", (this->css)->ToValue());

  }
  if (this->js.get()) {
    to_value_result->SetWithoutPathExpansion("js", (this->js)->ToValue());

  }
  if (this->run_at != extension_types::RUN_AT_NONE) {
    to_value_result->SetWithoutPathExpansion("run_at", std::make_unique<base::Value>(extension_types::ToString(this->run_at)));

  }
  if (this->all_frames.get()) {
    to_value_result->SetWithoutPathExpansion("all_frames", std::make_unique<base::Value>(*this->all_frames));

  }
  if (this->include_globs.get()) {
    to_value_result->SetWithoutPathExpansion("include_globs", json_schema_compiler::util::CreateValueFromOptionalArray(this->include_globs));

  }
  if (this->exclude_globs.get()) {
    to_value_result->SetWithoutPathExpansion("exclude_globs", json_schema_compiler::util::CreateValueFromOptionalArray(this->exclude_globs));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetAudioState {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool audible) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(audible));

  return create_results;
}
}  // namespace GetAudioState

namespace SetAudioMuted {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* mute_value = NULL;
  if (args.Get(1, &mute_value) &&
      !mute_value->is_none()) {
    {
      if (!mute_value->GetAsBoolean(&params->mute)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetAudioMuted

namespace IsAudioMuted {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool muted) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(muted));

  return create_results;
}
}  // namespace IsAudioMuted

namespace ExecuteScript {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* src_value = NULL;
  if (args.Get(1, &src_value) &&
      !src_value->is_none()) {
    {
      if (!src_value->GetAsString(&params->src)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* details_value = NULL;
  if (args.Get(2, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!extensions::api::extension_types::InjectDetails::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::unique_ptr<base::Value>>& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(result));

  return create_results;
}
}  // namespace ExecuteScript

namespace InsertCSS {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* src_value = NULL;
  if (args.Get(1, &src_value) &&
      !src_value->is_none()) {
    {
      if (!src_value->GetAsString(&params->src)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* details_value = NULL;
  if (args.Get(2, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!extensions::api::extension_types::InjectDetails::Populate(*dictionary, &params->details)) {
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
}  // namespace InsertCSS

namespace AddContentScripts {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* content_script_list_value = NULL;
  if (args.Get(1, &content_script_list_value) &&
      !content_script_list_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!content_script_list_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->content_script_list)) {
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


}  // namespace AddContentScripts

namespace RemoveContentScripts {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* script_name_list_value = NULL;
  if (args.Get(1, &script_name_list_value) &&
      !script_name_list_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!script_name_list_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &params->script_name_list)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }

  return params;
}


}  // namespace RemoveContentScripts

namespace SetZoom {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* zoom_factor_value = NULL;
  if (args.Get(1, &zoom_factor_value) &&
      !zoom_factor_value->is_none()) {
    {
      if (!zoom_factor_value->GetAsDouble(&params->zoom_factor)) {
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
}  // namespace SetZoom

namespace GetZoom {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(double zoom_factor) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(zoom_factor));

  return create_results;
}
}  // namespace GetZoom

namespace SetZoomMode {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* zoom_mode_value = NULL;
  if (args.Get(1, &zoom_mode_value) &&
      !zoom_mode_value->is_none()) {
    {
      std::string zoom_mode_as_string;
      if (!zoom_mode_value->GetAsString(&zoom_mode_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->zoom_mode = ParseZoomMode(zoom_mode_as_string);
      if (params->zoom_mode == ZOOM_MODE_NONE) {
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
}  // namespace SetZoomMode

namespace GetZoomMode {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ZoomMode& zoom_mode) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(web_view_internal::ToString(zoom_mode)));

  return create_results;
}
}  // namespace GetZoomMode

namespace Find {

Params::Options::Options()
 {}

Params::Options::~Options() {}
Params::Options::Options(Options&& rhs)
: backward(std::move(rhs.backward)),
match_case(std::move(rhs.match_case)){
}

Params::Options& Params::Options::operator=(Options&& rhs)
{
backward = std::move(rhs.backward);
match_case = std::move(rhs.match_case);
return *this;
}

// static
bool Params::Options::Populate(
    const base::Value& value, Options* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* backward_value = NULL;
  if (dict->GetWithoutPathExpansion("backward", &backward_value)) {
    {
      bool temp;
      if (!backward_value->GetAsBoolean(&temp)) {
        out->backward.reset();
        return false;
      }
      else
        out->backward.reset(new bool(temp));
    }
  }

  const base::Value* match_case_value = NULL;
  if (dict->GetWithoutPathExpansion("matchCase", &match_case_value)) {
    {
      bool temp;
      if (!match_case_value->GetAsBoolean(&temp)) {
        out->match_case.reset();
        return false;
      }
      else
        out->match_case.reset(new bool(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* search_text_value = NULL;
  if (args.Get(1, &search_text_value) &&
      !search_text_value->is_none()) {
    {
      if (!search_text_value->GetAsString(&params->search_text)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(2, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<Options> temp(new Options());
        if (!Options::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


Results::Results::SelectionRect::SelectionRect()
: left(0),
top(0),
width(0),
height(0) {}

Results::Results::SelectionRect::~SelectionRect() {}
Results::Results::SelectionRect::SelectionRect(SelectionRect&& rhs)
: left(rhs.left),
top(rhs.top),
width(rhs.width),
height(rhs.height){
}

Results::Results::SelectionRect& Results::Results::SelectionRect::operator=(SelectionRect&& rhs)
{
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Results::SelectionRect::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));


  return to_value_result;
}



Results::Results::Results()
: number_of_matches(0),
active_match_ordinal(0),
canceled(false) {}

Results::Results::~Results() {}
Results::Results::Results(Results&& rhs)
: number_of_matches(rhs.number_of_matches),
active_match_ordinal(rhs.active_match_ordinal),
selection_rect(std::move(rhs.selection_rect)),
canceled(rhs.canceled){
}

Results::Results& Results::Results::operator=(Results&& rhs)
{
number_of_matches = rhs.number_of_matches;
active_match_ordinal = rhs.active_match_ordinal;
selection_rect = std::move(rhs.selection_rect);
canceled = rhs.canceled;
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Results::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("numberOfMatches", std::make_unique<base::Value>(this->number_of_matches));

  to_value_result->SetWithoutPathExpansion("activeMatchOrdinal", std::make_unique<base::Value>(this->active_match_ordinal));

  to_value_result->SetWithoutPathExpansion("selectionRect", (this->selection_rect).ToValue());

  to_value_result->SetWithoutPathExpansion("canceled", std::make_unique<base::Value>(this->canceled));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Results& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((results).ToValue());

  return create_results;
}
}  // namespace Find

namespace StopFinding {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());
  params->action = STOP_FINDING_ACTION_NONE;

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* action_value = NULL;
  if (args.Get(1, &action_value) &&
      !action_value->is_none()) {
    {
      std::string stop_finding_action_as_string;
      if (!action_value->GetAsString(&stop_finding_action_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->action = ParseStopFindingAction(stop_finding_action_as_string);
      if (params->action == STOP_FINDING_ACTION_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }

  return params;
}


}  // namespace StopFinding

namespace LoadDataWithBaseUrl {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 3 || args.GetSize() > 4) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* data_url_value = NULL;
  if (args.Get(1, &data_url_value) &&
      !data_url_value->is_none()) {
    {
      if (!data_url_value->GetAsString(&params->data_url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* base_url_value = NULL;
  if (args.Get(2, &base_url_value) &&
      !base_url_value->is_none()) {
    {
      if (!base_url_value->GetAsString(&params->base_url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* virtual_url_value = NULL;
  if (args.Get(3, &virtual_url_value) &&
      !virtual_url_value->is_none()) {
    {
      std::string temp;
      if (!virtual_url_value->GetAsString(&temp)) {
        params->virtual_url.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->virtual_url.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace LoadDataWithBaseUrl

namespace Go {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* relative_index_value = NULL;
  if (args.Get(1, &relative_index_value) &&
      !relative_index_value->is_none()) {
    {
      if (!relative_index_value->GetAsInteger(&params->relative_index)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace Go

namespace OverrideUserAgent {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* user_agent_override_value = NULL;
  if (args.Get(1, &user_agent_override_value) &&
      !user_agent_override_value->is_none()) {
    {
      if (!user_agent_override_value->GetAsString(&params->user_agent_override)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OverrideUserAgent

namespace Reload {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Reload

namespace SetAllowTransparency {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* allow_value = NULL;
  if (args.Get(1, &allow_value) &&
      !allow_value->is_none()) {
    {
      if (!allow_value->GetAsBoolean(&params->allow)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetAllowTransparency

namespace SetAllowScaling {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* allow_value = NULL;
  if (args.Get(1, &allow_value) &&
      !allow_value->is_none()) {
    {
      if (!allow_value->GetAsBoolean(&params->allow)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetAllowScaling

namespace SetName {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* frame_name_value = NULL;
  if (args.Get(1, &frame_name_value) &&
      !frame_name_value->is_none()) {
    {
      if (!frame_name_value->GetAsString(&params->frame_name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetName

namespace SetPermission {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 3 || args.GetSize() > 4) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* request_id_value = NULL;
  if (args.Get(1, &request_id_value) &&
      !request_id_value->is_none()) {
    {
      if (!request_id_value->GetAsInteger(&params->request_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* action_value = NULL;
  if (args.Get(2, &action_value) &&
      !action_value->is_none()) {
    {
      std::string set_permission_action_as_string;
      if (!action_value->GetAsString(&set_permission_action_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->action = ParseSetPermissionAction(set_permission_action_as_string);
      if (params->action == SET_PERMISSION_ACTION_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* user_input_value = NULL;
  if (args.Get(3, &user_input_value) &&
      !user_input_value->is_none()) {
    {
      std::string temp;
      if (!user_input_value->GetAsString(&temp)) {
        params->user_input.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->user_input.reset(new std::string(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool allowed) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(allowed));

  return create_results;
}
}  // namespace SetPermission

namespace Navigate {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* src_value = NULL;
  if (args.Get(1, &src_value) &&
      !src_value->is_none()) {
    {
      if (!src_value->GetAsString(&params->src)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Navigate

namespace Stop {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Stop

namespace Terminate {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace Terminate

namespace CaptureVisibleRegion {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
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
        std::unique_ptr<extensions::api::extension_types::ImageDetails> temp(new extensions::api::extension_types::ImageDetails());
        if (!extensions::api::extension_types::ImageDetails::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& data_url) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(data_url));

  return create_results;
}
}  // namespace CaptureVisibleRegion

namespace SetSpatialNavigationEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* spatial_nav_enabled_value = NULL;
  if (args.Get(1, &spatial_nav_enabled_value) &&
      !spatial_nav_enabled_value->is_none()) {
    {
      if (!spatial_nav_enabled_value->GetAsBoolean(&params->spatial_nav_enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetSpatialNavigationEnabled

namespace IsSpatialNavigationEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool spatial_nav_enabled) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(spatial_nav_enabled));

  return create_results;
}
}  // namespace IsSpatialNavigationEnabled

namespace ClearData {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
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
      if (!RemovalOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* data_to_remove_value = NULL;
  if (args.Get(2, &data_to_remove_value) &&
      !data_to_remove_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!data_to_remove_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DataTypeSet::Populate(*dictionary, &params->data_to_remove)) {
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
}  // namespace ClearData

}  // namespace web_view_internal
}  // namespace api
}  // namespace extensions

