// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/apps/platform_apps/api/sync_file_system.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_APPS_PLATFORM_APPS_API_SYNC_FILE_SYSTEM_H__
#define CHROME_COMMON_APPS_PLATFORM_APPS_API_SYNC_FILE_SYSTEM_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace chrome_apps {
namespace api {
namespace sync_file_system {

//
// Types
//

enum SyncAction {
  SYNC_ACTION_NONE,
  SYNC_ACTION_ADDED,
  SYNC_ACTION_UPDATED,
  SYNC_ACTION_DELETED,
  SYNC_ACTION_LAST = SYNC_ACTION_DELETED,
};


const char* ToString(SyncAction as_enum);
SyncAction ParseSyncAction(const std::string& as_string);

enum ServiceStatus {
  SERVICE_STATUS_NONE,
  SERVICE_STATUS_INITIALIZING,
  SERVICE_STATUS_RUNNING,
  SERVICE_STATUS_AUTHENTICATION_REQUIRED,
  SERVICE_STATUS_TEMPORARY_UNAVAILABLE,
  SERVICE_STATUS_DISABLED,
  SERVICE_STATUS_LAST = SERVICE_STATUS_DISABLED,
};


const char* ToString(ServiceStatus as_enum);
ServiceStatus ParseServiceStatus(const std::string& as_string);

enum FileStatus {
  FILE_STATUS_NONE,
  FILE_STATUS_SYNCED,
  FILE_STATUS_PENDING,
  FILE_STATUS_CONFLICTING,
  FILE_STATUS_LAST = FILE_STATUS_CONFLICTING,
};


const char* ToString(FileStatus as_enum);
FileStatus ParseFileStatus(const std::string& as_string);

enum SyncDirection {
  SYNC_DIRECTION_NONE,
  SYNC_DIRECTION_LOCAL_TO_REMOTE,
  SYNC_DIRECTION_REMOTE_TO_LOCAL,
  SYNC_DIRECTION_LAST = SYNC_DIRECTION_REMOTE_TO_LOCAL,
};


const char* ToString(SyncDirection as_enum);
SyncDirection ParseSyncDirection(const std::string& as_string);

enum ConflictResolutionPolicy {
  CONFLICT_RESOLUTION_POLICY_NONE,
  CONFLICT_RESOLUTION_POLICY_LAST_WRITE_WIN,
  CONFLICT_RESOLUTION_POLICY_MANUAL,
  CONFLICT_RESOLUTION_POLICY_LAST = CONFLICT_RESOLUTION_POLICY_MANUAL,
};


const char* ToString(ConflictResolutionPolicy as_enum);
ConflictResolutionPolicy ParseConflictResolutionPolicy(const std::string& as_string);

struct FileInfo {
  FileInfo();
  ~FileInfo();
  FileInfo(FileInfo&& rhs);
  FileInfo& operator=(FileInfo&& rhs);

  // Populates a FileInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, FileInfo* out);

  // Creates a FileInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<FileInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FileInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // <code>fileEntry</code> for the target file whose status has changed. Contains
  // name and path information of synchronized file. On file deletion,
  // <code>fileEntry</code> information will still be available but file will no
  // longer exist.
  struct FileEntry {
    FileEntry();
    ~FileEntry();
    FileEntry(FileEntry&& rhs);
    FileEntry& operator=(FileEntry&& rhs);

    // Populates a FileEntry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, FileEntry* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this FileEntry object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(FileEntry);
  };


  // <code>fileEntry</code> for the target file whose status has changed. Contains
  // name and path information of synchronized file. On file deletion,
  // <code>fileEntry</code> information will still be available but file will no
  // longer exist.
  FileEntry file_entry;

  // Resulting file status after $(ref:onFileStatusChanged) event. The status
  // value can be <code>'synced'</code>, <code>'pending'</code> or
  // <code>'conflicting'</code>.
  FileStatus status;

  // Sync action taken to fire $(ref:onFileStatusChanged) event. The action value
  // can be <code>'added'</code>, <code>'updated'</code> or
  // <code>'deleted'</code>. Only applies if status is <code>'synced'</code>.
  SyncAction action;

  // Sync direction for the $(ref:onFileStatusChanged) event. Sync direction value
  // can be <code>'local_to_remote'</code> or <code>'remote_to_local'</code>. Only
  // applies if status is <code>'synced'</code>.
  SyncDirection direction;


 private:
  DISALLOW_COPY_AND_ASSIGN(FileInfo);
};

struct FileStatusInfo {
  FileStatusInfo();
  ~FileStatusInfo();
  FileStatusInfo(FileStatusInfo&& rhs);
  FileStatusInfo& operator=(FileStatusInfo&& rhs);

  // Populates a FileStatusInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, FileStatusInfo* out);

  // Creates a FileStatusInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<FileStatusInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FileStatusInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // One of the Entry's originally given to getFileStatuses.
  struct FileEntry {
    FileEntry();
    ~FileEntry();
    FileEntry(FileEntry&& rhs);
    FileEntry& operator=(FileEntry&& rhs);

    // Populates a FileEntry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, FileEntry* out);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this FileEntry object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(FileEntry);
  };


  // One of the Entry's originally given to getFileStatuses.
  FileEntry file_entry;

  // The status value can be <code>'synced'</code>, <code>'pending'</code> or
  // <code>'conflicting'</code>.
  FileStatus status;

  // Optional error that is only returned if there was a problem retrieving the
  // FileStatus for the given file.
  std::unique_ptr<std::string> error;


 private:
  DISALLOW_COPY_AND_ASSIGN(FileStatusInfo);
};

struct StorageInfo {
  StorageInfo();
  ~StorageInfo();
  StorageInfo(StorageInfo&& rhs);
  StorageInfo& operator=(StorageInfo&& rhs);

  // Populates a StorageInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, StorageInfo* out);

  // Creates a StorageInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<StorageInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StorageInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  int usage_bytes;

  int quota_bytes;


 private:
  DISALLOW_COPY_AND_ASSIGN(StorageInfo);
};

struct ServiceInfo {
  ServiceInfo();
  ~ServiceInfo();
  ServiceInfo(ServiceInfo&& rhs);
  ServiceInfo& operator=(ServiceInfo&& rhs);

  // Populates a ServiceInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ServiceInfo* out);

  // Creates a ServiceInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ServiceInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ServiceInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  ServiceStatus state;

  std::string description;


 private:
  DISALLOW_COPY_AND_ASSIGN(ServiceInfo);
};


//
// Functions
//

namespace RequestFileSystem {

namespace Results {

struct FileSystem {
  FileSystem();
  ~FileSystem();
  FileSystem(FileSystem&& rhs);
  FileSystem& operator=(FileSystem&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FileSystem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(FileSystem);
};


std::unique_ptr<base::ListValue> Create(const FileSystem& file_system);
}  // namespace Results

}  // namespace RequestFileSystem

namespace SetConflictResolutionPolicy {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  ConflictResolutionPolicy policy;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetConflictResolutionPolicy

namespace GetConflictResolutionPolicy {

namespace Results {

std::unique_ptr<base::ListValue> Create(const ConflictResolutionPolicy& policy);
}  // namespace Results

}  // namespace GetConflictResolutionPolicy

namespace GetUsageAndQuota {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct FileSystem {
    FileSystem();
    ~FileSystem();
    FileSystem(FileSystem&& rhs);
    FileSystem& operator=(FileSystem&& rhs);

    // Populates a FileSystem object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, FileSystem* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(FileSystem);
  };


  FileSystem file_system;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const StorageInfo& info);
}  // namespace Results

}  // namespace GetUsageAndQuota

namespace GetFileStatus {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct FileEntry {
    FileEntry();
    ~FileEntry();
    FileEntry(FileEntry&& rhs);
    FileEntry& operator=(FileEntry&& rhs);

    // Populates a FileEntry object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, FileEntry* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(FileEntry);
  };


  FileEntry file_entry;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const FileStatus& status);
}  // namespace Results

}  // namespace GetFileStatus

namespace GetFileStatuses {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct FileEntriesType {
    FileEntriesType();
    ~FileEntriesType();
    FileEntriesType(FileEntriesType&& rhs);
    FileEntriesType& operator=(FileEntriesType&& rhs);

    // Populates a FileEntriesType object from a base::Value. Returns whether
    // |out| was successfully populated.
    static bool Populate(const base::Value& value, FileEntriesType* out);

    base::DictionaryValue additional_properties;

   private:
    DISALLOW_COPY_AND_ASSIGN(FileEntriesType);
  };



  std::vector<FileEntriesType> file_entries;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<FileStatusInfo>& status);
}  // namespace Results

}  // namespace GetFileStatuses

namespace GetServiceStatus {

namespace Results {

std::unique_ptr<base::ListValue> Create(const ServiceStatus& status);
}  // namespace Results

}  // namespace GetServiceStatus

//
// Events
//

namespace OnServiceStatusChanged {

extern const char kEventName[];  // "syncFileSystem.onServiceStatusChanged"

std::unique_ptr<base::ListValue> Create(const ServiceInfo& detail);
}  // namespace OnServiceStatusChanged

namespace OnFileStatusChanged {

extern const char kEventName[];  // "syncFileSystem.onFileStatusChanged"

std::unique_ptr<base::ListValue> Create(const FileInfo& detail);
}  // namespace OnFileStatusChanged

}  // namespace sync_file_system
}  // namespace api
}  // namespace chrome_apps
#endif  // CHROME_COMMON_APPS_PLATFORM_APPS_API_SYNC_FILE_SYSTEM_H__
