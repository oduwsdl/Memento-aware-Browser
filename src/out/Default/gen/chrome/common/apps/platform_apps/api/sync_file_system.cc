// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/apps/platform_apps/api/sync_file_system.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/apps/platform_apps/api/sync_file_system.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace chrome_apps {
namespace api {
namespace sync_file_system {
//
// Types
//

const char* ToString(SyncAction enum_param) {
  switch (enum_param) {
    case SYNC_ACTION_ADDED:
      return "added";
    case SYNC_ACTION_UPDATED:
      return "updated";
    case SYNC_ACTION_DELETED:
      return "deleted";
    case SYNC_ACTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SyncAction ParseSyncAction(const std::string& enum_string) {
  if (enum_string == "added")
    return SYNC_ACTION_ADDED;
  if (enum_string == "updated")
    return SYNC_ACTION_UPDATED;
  if (enum_string == "deleted")
    return SYNC_ACTION_DELETED;
  return SYNC_ACTION_NONE;
}


const char* ToString(ServiceStatus enum_param) {
  switch (enum_param) {
    case SERVICE_STATUS_INITIALIZING:
      return "initializing";
    case SERVICE_STATUS_RUNNING:
      return "running";
    case SERVICE_STATUS_AUTHENTICATION_REQUIRED:
      return "authentication_required";
    case SERVICE_STATUS_TEMPORARY_UNAVAILABLE:
      return "temporary_unavailable";
    case SERVICE_STATUS_DISABLED:
      return "disabled";
    case SERVICE_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ServiceStatus ParseServiceStatus(const std::string& enum_string) {
  if (enum_string == "initializing")
    return SERVICE_STATUS_INITIALIZING;
  if (enum_string == "running")
    return SERVICE_STATUS_RUNNING;
  if (enum_string == "authentication_required")
    return SERVICE_STATUS_AUTHENTICATION_REQUIRED;
  if (enum_string == "temporary_unavailable")
    return SERVICE_STATUS_TEMPORARY_UNAVAILABLE;
  if (enum_string == "disabled")
    return SERVICE_STATUS_DISABLED;
  return SERVICE_STATUS_NONE;
}


const char* ToString(FileStatus enum_param) {
  switch (enum_param) {
    case FILE_STATUS_SYNCED:
      return "synced";
    case FILE_STATUS_PENDING:
      return "pending";
    case FILE_STATUS_CONFLICTING:
      return "conflicting";
    case FILE_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FileStatus ParseFileStatus(const std::string& enum_string) {
  if (enum_string == "synced")
    return FILE_STATUS_SYNCED;
  if (enum_string == "pending")
    return FILE_STATUS_PENDING;
  if (enum_string == "conflicting")
    return FILE_STATUS_CONFLICTING;
  return FILE_STATUS_NONE;
}


const char* ToString(SyncDirection enum_param) {
  switch (enum_param) {
    case SYNC_DIRECTION_LOCAL_TO_REMOTE:
      return "local_to_remote";
    case SYNC_DIRECTION_REMOTE_TO_LOCAL:
      return "remote_to_local";
    case SYNC_DIRECTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SyncDirection ParseSyncDirection(const std::string& enum_string) {
  if (enum_string == "local_to_remote")
    return SYNC_DIRECTION_LOCAL_TO_REMOTE;
  if (enum_string == "remote_to_local")
    return SYNC_DIRECTION_REMOTE_TO_LOCAL;
  return SYNC_DIRECTION_NONE;
}


const char* ToString(ConflictResolutionPolicy enum_param) {
  switch (enum_param) {
    case CONFLICT_RESOLUTION_POLICY_LAST_WRITE_WIN:
      return "last_write_win";
    case CONFLICT_RESOLUTION_POLICY_MANUAL:
      return "manual";
    case CONFLICT_RESOLUTION_POLICY_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ConflictResolutionPolicy ParseConflictResolutionPolicy(const std::string& enum_string) {
  if (enum_string == "last_write_win")
    return CONFLICT_RESOLUTION_POLICY_LAST_WRITE_WIN;
  if (enum_string == "manual")
    return CONFLICT_RESOLUTION_POLICY_MANUAL;
  return CONFLICT_RESOLUTION_POLICY_NONE;
}


FileInfo::FileEntry::FileEntry()
 {}

FileInfo::FileEntry::~FileEntry() {}
FileInfo::FileEntry::FileEntry(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

FileInfo::FileEntry& FileInfo::FileEntry::operator=(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool FileInfo::FileEntry::Populate(
    const base::Value& value, FileEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> FileInfo::FileEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



FileInfo::FileInfo()
: status(FILE_STATUS_NONE),
action(SYNC_ACTION_NONE),
direction(SYNC_DIRECTION_NONE) {}

FileInfo::~FileInfo() {}
FileInfo::FileInfo(FileInfo&& rhs)
: file_entry(std::move(rhs.file_entry)),
status(rhs.status),
action(rhs.action),
direction(rhs.direction){
}

FileInfo& FileInfo::operator=(FileInfo&& rhs)
{
file_entry = std::move(rhs.file_entry);
status = rhs.status;
action = rhs.action;
direction = rhs.direction;
return *this;
}

// static
bool FileInfo::Populate(
    const base::Value& value, FileInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->action = SYNC_ACTION_NONE;
  out->direction = SYNC_DIRECTION_NONE;
  const base::Value* file_entry_value = NULL;
  if (!dict->GetWithoutPathExpansion("fileEntry", &file_entry_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!file_entry_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!FileEntry::Populate(*dictionary, &out->file_entry)) {
      return false;
    }
  }

  const base::Value* status_value = NULL;
  if (!dict->GetWithoutPathExpansion("status", &status_value)) {
    return false;
  }
  {
    std::string file_status_as_string;
    if (!status_value->GetAsString(&file_status_as_string)) {
      return false;
    }
    out->status = ParseFileStatus(file_status_as_string);
    if (out->status == FILE_STATUS_NONE) {
      return false;
    }
  }

  const base::Value* action_value = NULL;
  if (dict->GetWithoutPathExpansion("action", &action_value)) {
    {
      std::string sync_action_as_string;
      if (!action_value->GetAsString(&sync_action_as_string)) {
        return false;
      }
      out->action = ParseSyncAction(sync_action_as_string);
      if (out->action == SYNC_ACTION_NONE) {
        return false;
      }
    }
    } else {
    out->action = SYNC_ACTION_NONE;
  }

  const base::Value* direction_value = NULL;
  if (dict->GetWithoutPathExpansion("direction", &direction_value)) {
    {
      std::string sync_direction_as_string;
      if (!direction_value->GetAsString(&sync_direction_as_string)) {
        return false;
      }
      out->direction = ParseSyncDirection(sync_direction_as_string);
      if (out->direction == SYNC_DIRECTION_NONE) {
        return false;
      }
    }
    } else {
    out->direction = SYNC_DIRECTION_NONE;
  }

  return true;
}

// static
std::unique_ptr<FileInfo> FileInfo::FromValue(const base::Value& value) {
  std::unique_ptr<FileInfo> out(new FileInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FileInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("fileEntry", (this->file_entry).ToValue());

  to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(sync_file_system::ToString(this->status)));

  if (this->action != SYNC_ACTION_NONE) {
    to_value_result->SetWithoutPathExpansion("action", std::make_unique<base::Value>(sync_file_system::ToString(this->action)));

  }
  if (this->direction != SYNC_DIRECTION_NONE) {
    to_value_result->SetWithoutPathExpansion("direction", std::make_unique<base::Value>(sync_file_system::ToString(this->direction)));

  }

  return to_value_result;
}


FileStatusInfo::FileEntry::FileEntry()
 {}

FileStatusInfo::FileEntry::~FileEntry() {}
FileStatusInfo::FileEntry::FileEntry(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

FileStatusInfo::FileEntry& FileStatusInfo::FileEntry::operator=(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool FileStatusInfo::FileEntry::Populate(
    const base::Value& value, FileEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> FileStatusInfo::FileEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



FileStatusInfo::FileStatusInfo()
: status(FILE_STATUS_NONE) {}

FileStatusInfo::~FileStatusInfo() {}
FileStatusInfo::FileStatusInfo(FileStatusInfo&& rhs)
: file_entry(std::move(rhs.file_entry)),
status(rhs.status),
error(std::move(rhs.error)){
}

FileStatusInfo& FileStatusInfo::operator=(FileStatusInfo&& rhs)
{
file_entry = std::move(rhs.file_entry);
status = rhs.status;
error = std::move(rhs.error);
return *this;
}

// static
bool FileStatusInfo::Populate(
    const base::Value& value, FileStatusInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* file_entry_value = NULL;
  if (!dict->GetWithoutPathExpansion("fileEntry", &file_entry_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!file_entry_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!FileEntry::Populate(*dictionary, &out->file_entry)) {
      return false;
    }
  }

  const base::Value* status_value = NULL;
  if (!dict->GetWithoutPathExpansion("status", &status_value)) {
    return false;
  }
  {
    std::string file_status_as_string;
    if (!status_value->GetAsString(&file_status_as_string)) {
      return false;
    }
    out->status = ParseFileStatus(file_status_as_string);
    if (out->status == FILE_STATUS_NONE) {
      return false;
    }
  }

  const base::Value* error_value = NULL;
  if (dict->GetWithoutPathExpansion("error", &error_value)) {
    {
      std::string temp;
      if (!error_value->GetAsString(&temp)) {
        out->error.reset();
        return false;
      }
      else
        out->error.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<FileStatusInfo> FileStatusInfo::FromValue(const base::Value& value) {
  std::unique_ptr<FileStatusInfo> out(new FileStatusInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FileStatusInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("fileEntry", (this->file_entry).ToValue());

  to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(sync_file_system::ToString(this->status)));

  if (this->error.get()) {
    to_value_result->SetWithoutPathExpansion("error", std::make_unique<base::Value>(*this->error));

  }

  return to_value_result;
}


StorageInfo::StorageInfo()
: usage_bytes(0),
quota_bytes(0) {}

StorageInfo::~StorageInfo() {}
StorageInfo::StorageInfo(StorageInfo&& rhs)
: usage_bytes(rhs.usage_bytes),
quota_bytes(rhs.quota_bytes){
}

StorageInfo& StorageInfo::operator=(StorageInfo&& rhs)
{
usage_bytes = rhs.usage_bytes;
quota_bytes = rhs.quota_bytes;
return *this;
}

// static
bool StorageInfo::Populate(
    const base::Value& value, StorageInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* usage_bytes_value = NULL;
  if (!dict->GetWithoutPathExpansion("usageBytes", &usage_bytes_value)) {
    return false;
  }
  {
    if (!usage_bytes_value->GetAsInteger(&out->usage_bytes)) {
      return false;
    }
  }

  const base::Value* quota_bytes_value = NULL;
  if (!dict->GetWithoutPathExpansion("quotaBytes", &quota_bytes_value)) {
    return false;
  }
  {
    if (!quota_bytes_value->GetAsInteger(&out->quota_bytes)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<StorageInfo> StorageInfo::FromValue(const base::Value& value) {
  std::unique_ptr<StorageInfo> out(new StorageInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> StorageInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("usageBytes", std::make_unique<base::Value>(this->usage_bytes));

  to_value_result->SetWithoutPathExpansion("quotaBytes", std::make_unique<base::Value>(this->quota_bytes));


  return to_value_result;
}


ServiceInfo::ServiceInfo()
: state(SERVICE_STATUS_NONE) {}

ServiceInfo::~ServiceInfo() {}
ServiceInfo::ServiceInfo(ServiceInfo&& rhs)
: state(rhs.state),
description(std::move(rhs.description)){
}

ServiceInfo& ServiceInfo::operator=(ServiceInfo&& rhs)
{
state = rhs.state;
description = std::move(rhs.description);
return *this;
}

// static
bool ServiceInfo::Populate(
    const base::Value& value, ServiceInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("state", &state_value)) {
    return false;
  }
  {
    std::string service_status_as_string;
    if (!state_value->GetAsString(&service_status_as_string)) {
      return false;
    }
    out->state = ParseServiceStatus(service_status_as_string);
    if (out->state == SERVICE_STATUS_NONE) {
      return false;
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

  return true;
}

// static
std::unique_ptr<ServiceInfo> ServiceInfo::FromValue(const base::Value& value) {
  std::unique_ptr<ServiceInfo> out(new ServiceInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ServiceInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(sync_file_system::ToString(this->state)));

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));


  return to_value_result;
}



//
// Functions
//

namespace RequestFileSystem {

Results::FileSystem::FileSystem()
 {}

Results::FileSystem::~FileSystem() {}
Results::FileSystem::FileSystem(FileSystem&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::FileSystem& Results::FileSystem::operator=(FileSystem&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::FileSystem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const FileSystem& file_system) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((file_system).ToValue());

  return create_results;
}
}  // namespace RequestFileSystem

namespace SetConflictResolutionPolicy {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* policy_value = NULL;
  if (args.Get(0, &policy_value) &&
      !policy_value->is_none()) {
    {
      std::string conflict_resolution_policy_as_string;
      if (!policy_value->GetAsString(&conflict_resolution_policy_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->policy = ParseConflictResolutionPolicy(conflict_resolution_policy_as_string);
      if (params->policy == CONFLICT_RESOLUTION_POLICY_NONE) {
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
}  // namespace SetConflictResolutionPolicy

namespace GetConflictResolutionPolicy {

std::unique_ptr<base::ListValue> Results::Create(const ConflictResolutionPolicy& policy) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(sync_file_system::ToString(policy)));

  return create_results;
}
}  // namespace GetConflictResolutionPolicy

namespace GetUsageAndQuota {

Params::FileSystem::FileSystem()
 {}

Params::FileSystem::~FileSystem() {}
Params::FileSystem::FileSystem(FileSystem&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::FileSystem& Params::FileSystem::operator=(FileSystem&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::FileSystem::Populate(
    const base::Value& value, FileSystem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
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

  const base::Value* file_system_value = NULL;
  if (args.Get(0, &file_system_value) &&
      !file_system_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!file_system_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!FileSystem::Populate(*dictionary, &params->file_system)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const StorageInfo& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}
}  // namespace GetUsageAndQuota

namespace GetFileStatus {

Params::FileEntry::FileEntry()
 {}

Params::FileEntry::~FileEntry() {}
Params::FileEntry::FileEntry(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::FileEntry& Params::FileEntry::operator=(FileEntry&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::FileEntry::Populate(
    const base::Value& value, FileEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
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

  const base::Value* file_entry_value = NULL;
  if (args.Get(0, &file_entry_value) &&
      !file_entry_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!file_entry_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!FileEntry::Populate(*dictionary, &params->file_entry)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const FileStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(sync_file_system::ToString(status)));

  return create_results;
}
}  // namespace GetFileStatus

namespace GetFileStatuses {

Params::FileEntriesType::FileEntriesType()
 {}

Params::FileEntriesType::~FileEntriesType() {}
Params::FileEntriesType::FileEntriesType(FileEntriesType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Params::FileEntriesType& Params::FileEntriesType::operator=(FileEntriesType&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool Params::FileEntriesType::Populate(
    const base::Value& value, FileEntriesType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
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

  const base::Value* file_entries_value = NULL;
  if (args.Get(0, &file_entries_value) &&
      !file_entries_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!file_entries_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->file_entries)) {
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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<FileStatusInfo>& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(status));

  return create_results;
}
}  // namespace GetFileStatuses

namespace GetServiceStatus {

std::unique_ptr<base::ListValue> Results::Create(const ServiceStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(sync_file_system::ToString(status)));

  return create_results;
}
}  // namespace GetServiceStatus

//
// Events
//

namespace OnServiceStatusChanged {

const char kEventName[] = "syncFileSystem.onServiceStatusChanged";

std::unique_ptr<base::ListValue> Create(const ServiceInfo& detail) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((detail).ToValue());

  return create_results;
}

}  // namespace OnServiceStatusChanged

namespace OnFileStatusChanged {

const char kEventName[] = "syncFileSystem.onFileStatusChanged";

std::unique_ptr<base::ListValue> Create(const FileInfo& detail) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((detail).ToValue());

  return create_results;
}

}  // namespace OnFileStatusChanged

}  // namespace sync_file_system
}  // namespace api
}  // namespace chrome_apps

