// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/processes.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/processes.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace processes {
//
// Types
//

const char* ToString(ProcessType enum_param) {
  switch (enum_param) {
    case PROCESS_TYPE_BROWSER:
      return "browser";
    case PROCESS_TYPE_RENDERER:
      return "renderer";
    case PROCESS_TYPE_EXTENSION:
      return "extension";
    case PROCESS_TYPE_NOTIFICATION:
      return "notification";
    case PROCESS_TYPE_PLUGIN:
      return "plugin";
    case PROCESS_TYPE_WORKER:
      return "worker";
    case PROCESS_TYPE_NACL:
      return "nacl";
    case PROCESS_TYPE_SERVICE_WORKER:
      return "service_worker";
    case PROCESS_TYPE_UTILITY:
      return "utility";
    case PROCESS_TYPE_GPU:
      return "gpu";
    case PROCESS_TYPE_OTHER:
      return "other";
    case PROCESS_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ProcessType ParseProcessType(const std::string& enum_string) {
  if (enum_string == "browser")
    return PROCESS_TYPE_BROWSER;
  if (enum_string == "renderer")
    return PROCESS_TYPE_RENDERER;
  if (enum_string == "extension")
    return PROCESS_TYPE_EXTENSION;
  if (enum_string == "notification")
    return PROCESS_TYPE_NOTIFICATION;
  if (enum_string == "plugin")
    return PROCESS_TYPE_PLUGIN;
  if (enum_string == "worker")
    return PROCESS_TYPE_WORKER;
  if (enum_string == "nacl")
    return PROCESS_TYPE_NACL;
  if (enum_string == "service_worker")
    return PROCESS_TYPE_SERVICE_WORKER;
  if (enum_string == "utility")
    return PROCESS_TYPE_UTILITY;
  if (enum_string == "gpu")
    return PROCESS_TYPE_GPU;
  if (enum_string == "other")
    return PROCESS_TYPE_OTHER;
  return PROCESS_TYPE_NONE;
}


TaskInfo::TaskInfo()
 {}

TaskInfo::~TaskInfo() {}
TaskInfo::TaskInfo(TaskInfo&& rhs)
: title(std::move(rhs.title)),
tab_id(std::move(rhs.tab_id)){
}

TaskInfo& TaskInfo::operator=(TaskInfo&& rhs)
{
title = std::move(rhs.title);
tab_id = std::move(rhs.tab_id);
return *this;
}

// static
bool TaskInfo::Populate(
    const base::Value& value, TaskInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* title_value = NULL;
  if (!dict->GetWithoutPathExpansion("title", &title_value)) {
    return false;
  }
  {
    if (!title_value->GetAsString(&out->title)) {
      return false;
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

  return true;
}

// static
std::unique_ptr<TaskInfo> TaskInfo::FromValue(const base::Value& value) {
  std::unique_ptr<TaskInfo> out(new TaskInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TaskInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  if (this->tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(*this->tab_id));

  }

  return to_value_result;
}


Cache::Cache()
: size(0.0),
live_size(0.0) {}

Cache::~Cache() {}
Cache::Cache(Cache&& rhs)
: size(rhs.size),
live_size(rhs.live_size){
}

Cache& Cache::operator=(Cache&& rhs)
{
size = rhs.size;
live_size = rhs.live_size;
return *this;
}

// static
bool Cache::Populate(
    const base::Value& value, Cache* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* size_value = NULL;
  if (!dict->GetWithoutPathExpansion("size", &size_value)) {
    return false;
  }
  {
    if (!size_value->GetAsDouble(&out->size)) {
      return false;
    }
  }

  const base::Value* live_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("liveSize", &live_size_value)) {
    return false;
  }
  {
    if (!live_size_value->GetAsDouble(&out->live_size)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Cache> Cache::FromValue(const base::Value& value) {
  std::unique_ptr<Cache> out(new Cache());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Cache::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("size", std::make_unique<base::Value>(this->size));

  to_value_result->SetWithoutPathExpansion("liveSize", std::make_unique<base::Value>(this->live_size));


  return to_value_result;
}


Process::Process()
: id(0),
os_process_id(0),
type(PROCESS_TYPE_NONE),
nacl_debug_port(0) {}

Process::~Process() {}
Process::Process(Process&& rhs)
: id(rhs.id),
os_process_id(rhs.os_process_id),
type(rhs.type),
profile(std::move(rhs.profile)),
nacl_debug_port(rhs.nacl_debug_port),
tasks(std::move(rhs.tasks)),
cpu(std::move(rhs.cpu)),
network(std::move(rhs.network)),
private_memory(std::move(rhs.private_memory)),
js_memory_allocated(std::move(rhs.js_memory_allocated)),
js_memory_used(std::move(rhs.js_memory_used)),
sqlite_memory(std::move(rhs.sqlite_memory)),
image_cache(std::move(rhs.image_cache)),
script_cache(std::move(rhs.script_cache)),
css_cache(std::move(rhs.css_cache)){
}

Process& Process::operator=(Process&& rhs)
{
id = rhs.id;
os_process_id = rhs.os_process_id;
type = rhs.type;
profile = std::move(rhs.profile);
nacl_debug_port = rhs.nacl_debug_port;
tasks = std::move(rhs.tasks);
cpu = std::move(rhs.cpu);
network = std::move(rhs.network);
private_memory = std::move(rhs.private_memory);
js_memory_allocated = std::move(rhs.js_memory_allocated);
js_memory_used = std::move(rhs.js_memory_used);
sqlite_memory = std::move(rhs.sqlite_memory);
image_cache = std::move(rhs.image_cache);
script_cache = std::move(rhs.script_cache);
css_cache = std::move(rhs.css_cache);
return *this;
}

// static
bool Process::Populate(
    const base::Value& value, Process* out) {
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

  const base::Value* os_process_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("osProcessId", &os_process_id_value)) {
    return false;
  }
  {
    if (!os_process_id_value->GetAsInteger(&out->os_process_id)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string process_type_as_string;
    if (!type_value->GetAsString(&process_type_as_string)) {
      return false;
    }
    out->type = ParseProcessType(process_type_as_string);
    if (out->type == PROCESS_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* profile_value = NULL;
  if (!dict->GetWithoutPathExpansion("profile", &profile_value)) {
    return false;
  }
  {
    if (!profile_value->GetAsString(&out->profile)) {
      return false;
    }
  }

  const base::Value* nacl_debug_port_value = NULL;
  if (!dict->GetWithoutPathExpansion("naclDebugPort", &nacl_debug_port_value)) {
    return false;
  }
  {
    if (!nacl_debug_port_value->GetAsInteger(&out->nacl_debug_port)) {
      return false;
    }
  }

  const base::Value* tasks_value = NULL;
  if (!dict->GetWithoutPathExpansion("tasks", &tasks_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!tasks_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->tasks)) {
        return false;
      }
    }
  }

  const base::Value* cpu_value = NULL;
  if (dict->GetWithoutPathExpansion("cpu", &cpu_value)) {
    {
      double temp;
      if (!cpu_value->GetAsDouble(&temp)) {
        out->cpu.reset();
        return false;
      }
      else
        out->cpu.reset(new double(temp));
    }
  }

  const base::Value* network_value = NULL;
  if (dict->GetWithoutPathExpansion("network", &network_value)) {
    {
      double temp;
      if (!network_value->GetAsDouble(&temp)) {
        out->network.reset();
        return false;
      }
      else
        out->network.reset(new double(temp));
    }
  }

  const base::Value* private_memory_value = NULL;
  if (dict->GetWithoutPathExpansion("privateMemory", &private_memory_value)) {
    {
      double temp;
      if (!private_memory_value->GetAsDouble(&temp)) {
        out->private_memory.reset();
        return false;
      }
      else
        out->private_memory.reset(new double(temp));
    }
  }

  const base::Value* js_memory_allocated_value = NULL;
  if (dict->GetWithoutPathExpansion("jsMemoryAllocated", &js_memory_allocated_value)) {
    {
      double temp;
      if (!js_memory_allocated_value->GetAsDouble(&temp)) {
        out->js_memory_allocated.reset();
        return false;
      }
      else
        out->js_memory_allocated.reset(new double(temp));
    }
  }

  const base::Value* js_memory_used_value = NULL;
  if (dict->GetWithoutPathExpansion("jsMemoryUsed", &js_memory_used_value)) {
    {
      double temp;
      if (!js_memory_used_value->GetAsDouble(&temp)) {
        out->js_memory_used.reset();
        return false;
      }
      else
        out->js_memory_used.reset(new double(temp));
    }
  }

  const base::Value* sqlite_memory_value = NULL;
  if (dict->GetWithoutPathExpansion("sqliteMemory", &sqlite_memory_value)) {
    {
      double temp;
      if (!sqlite_memory_value->GetAsDouble(&temp)) {
        out->sqlite_memory.reset();
        return false;
      }
      else
        out->sqlite_memory.reset(new double(temp));
    }
  }

  const base::Value* image_cache_value = NULL;
  if (dict->GetWithoutPathExpansion("imageCache", &image_cache_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!image_cache_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Cache> temp(new Cache());
        if (!Cache::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->image_cache = std::move(temp);
      }
    }
  }

  const base::Value* script_cache_value = NULL;
  if (dict->GetWithoutPathExpansion("scriptCache", &script_cache_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!script_cache_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Cache> temp(new Cache());
        if (!Cache::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->script_cache = std::move(temp);
      }
    }
  }

  const base::Value* css_cache_value = NULL;
  if (dict->GetWithoutPathExpansion("cssCache", &css_cache_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!css_cache_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Cache> temp(new Cache());
        if (!Cache::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->css_cache = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Process> Process::FromValue(const base::Value& value) {
  std::unique_ptr<Process> out(new Process());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Process::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("osProcessId", std::make_unique<base::Value>(this->os_process_id));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(processes::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("profile", std::make_unique<base::Value>(this->profile));

  to_value_result->SetWithoutPathExpansion("naclDebugPort", std::make_unique<base::Value>(this->nacl_debug_port));

  to_value_result->SetWithoutPathExpansion("tasks", json_schema_compiler::util::CreateValueFromArray(this->tasks));

  if (this->cpu.get()) {
    to_value_result->SetWithoutPathExpansion("cpu", std::make_unique<base::Value>(*this->cpu));

  }
  if (this->network.get()) {
    to_value_result->SetWithoutPathExpansion("network", std::make_unique<base::Value>(*this->network));

  }
  if (this->private_memory.get()) {
    to_value_result->SetWithoutPathExpansion("privateMemory", std::make_unique<base::Value>(*this->private_memory));

  }
  if (this->js_memory_allocated.get()) {
    to_value_result->SetWithoutPathExpansion("jsMemoryAllocated", std::make_unique<base::Value>(*this->js_memory_allocated));

  }
  if (this->js_memory_used.get()) {
    to_value_result->SetWithoutPathExpansion("jsMemoryUsed", std::make_unique<base::Value>(*this->js_memory_used));

  }
  if (this->sqlite_memory.get()) {
    to_value_result->SetWithoutPathExpansion("sqliteMemory", std::make_unique<base::Value>(*this->sqlite_memory));

  }
  if (this->image_cache.get()) {
    to_value_result->SetWithoutPathExpansion("imageCache", (this->image_cache)->ToValue());

  }
  if (this->script_cache.get()) {
    to_value_result->SetWithoutPathExpansion("scriptCache", (this->script_cache)->ToValue());

  }
  if (this->css_cache.get()) {
    to_value_result->SetWithoutPathExpansion("cssCache", (this->css_cache)->ToValue());

  }

  return to_value_result;
}



//
// Functions
//

namespace GetProcessIdForTab {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* tab_id_value = NULL;
  if (args.Get(0, &tab_id_value) &&
      !tab_id_value->is_none()) {
    {
      if (!tab_id_value->GetAsInteger(&params->tab_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(int process_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(process_id));

  return create_results;
}
}  // namespace GetProcessIdForTab

namespace Terminate {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* process_id_value = NULL;
  if (args.Get(0, &process_id_value) &&
      !process_id_value->is_none()) {
    {
      if (!process_id_value->GetAsInteger(&params->process_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool did_terminate) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(did_terminate));

  return create_results;
}
}  // namespace Terminate

namespace GetProcessInfo {

Params::ProcessIds::ProcessIds()
 {}

Params::ProcessIds::~ProcessIds() {}
Params::ProcessIds::ProcessIds(ProcessIds&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_integers(std::move(rhs.as_integers)){
}

Params::ProcessIds& Params::ProcessIds::operator=(ProcessIds&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_integers = std::move(rhs.as_integers);
return *this;
}

// static
bool Params::ProcessIds::Populate(
    const base::Value& value, ProcessIds* out) {
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::LIST) {
    {
      const base::ListValue* list = NULL;
      if (!(&value)->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_integers)) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* process_ids_value = NULL;
  if (args.Get(0, &process_ids_value) &&
      !process_ids_value->is_none()) {
    {
      if (!ProcessIds::Populate(*process_ids_value, &params->process_ids))
        return std::unique_ptr<Params>();
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* include_memory_value = NULL;
  if (args.Get(1, &include_memory_value) &&
      !include_memory_value->is_none()) {
    {
      if (!include_memory_value->GetAsBoolean(&params->include_memory)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Processes::Processes()
 {}

Results::Processes::~Processes() {}
Results::Processes::Processes(Processes&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::Processes& Results::Processes::operator=(Processes&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Processes::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Processes& processes) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((processes).ToValue());

  return create_results;
}
}  // namespace GetProcessInfo

//
// Events
//

namespace OnUpdated {

const char kEventName[] = "processes.onUpdated";

Processes::Processes()
 {}

Processes::~Processes() {}
Processes::Processes(Processes&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Processes& Processes::operator=(Processes&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Processes::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Processes& processes) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((processes).ToValue());

  return create_results;
}

}  // namespace OnUpdated

namespace OnUpdatedWithMemory {

const char kEventName[] = "processes.onUpdatedWithMemory";

Processes::Processes()
 {}

Processes::~Processes() {}
Processes::Processes(Processes&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Processes& Processes::operator=(Processes&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Processes::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Processes& processes) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((processes).ToValue());

  return create_results;
}

}  // namespace OnUpdatedWithMemory

namespace OnCreated {

const char kEventName[] = "processes.onCreated";

std::unique_ptr<base::ListValue> Create(const Process& process) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((process).ToValue());

  return create_results;
}

}  // namespace OnCreated

namespace OnUnresponsive {

const char kEventName[] = "processes.onUnresponsive";

std::unique_ptr<base::ListValue> Create(const Process& process) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((process).ToValue());

  return create_results;
}

}  // namespace OnUnresponsive

namespace OnExited {

const char kEventName[] = "processes.onExited";

std::unique_ptr<base::ListValue> Create(int process_id, int exit_type, int exit_code) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(process_id));

  create_results->Append(std::make_unique<base::Value>(exit_type));

  create_results->Append(std::make_unique<base::Value>(exit_code));

  return create_results;
}

}  // namespace OnExited

}  // namespace processes
}  // namespace api
}  // namespace extensions

