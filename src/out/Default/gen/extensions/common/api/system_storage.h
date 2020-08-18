// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_storage.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SYSTEM_STORAGE_H__
#define EXTENSIONS_COMMON_API_SYSTEM_STORAGE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace system_storage {

//
// Types
//

enum StorageUnitType {
  STORAGE_UNIT_TYPE_NONE,
  STORAGE_UNIT_TYPE_FIXED,
  STORAGE_UNIT_TYPE_REMOVABLE,
  STORAGE_UNIT_TYPE_UNKNOWN,
  STORAGE_UNIT_TYPE_LAST = STORAGE_UNIT_TYPE_UNKNOWN,
};


const char* ToString(StorageUnitType as_enum);
StorageUnitType ParseStorageUnitType(const std::string& as_string);

struct StorageUnitInfo {
  StorageUnitInfo();
  ~StorageUnitInfo();
  StorageUnitInfo(StorageUnitInfo&& rhs);
  StorageUnitInfo& operator=(StorageUnitInfo&& rhs);

  // Populates a StorageUnitInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, StorageUnitInfo* out);

  // Creates a StorageUnitInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<StorageUnitInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StorageUnitInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The transient ID that uniquely identifies the storage device. This ID will be
  // persistent within the same run of a single application. It will not be a
  // persistent identifier between different runs of an application, or between
  // different applications.
  std::string id;

  // The name of the storage unit.
  std::string name;

  // The media type of the storage unit.
  StorageUnitType type;

  // The total amount of the storage space, in bytes.
  double capacity;


 private:
  DISALLOW_COPY_AND_ASSIGN(StorageUnitInfo);
};

struct StorageAvailableCapacityInfo {
  StorageAvailableCapacityInfo();
  ~StorageAvailableCapacityInfo();
  StorageAvailableCapacityInfo(StorageAvailableCapacityInfo&& rhs);
  StorageAvailableCapacityInfo& operator=(StorageAvailableCapacityInfo&& rhs);

  // Populates a StorageAvailableCapacityInfo object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, StorageAvailableCapacityInfo* out);

  // Creates a StorageAvailableCapacityInfo object from a base::Value, or NULL
  // on failure.
  static std::unique_ptr<StorageAvailableCapacityInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this StorageAvailableCapacityInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A copied |id| of getAvailableCapacity function parameter |id|.
  std::string id;

  // The available capacity of the storage device, in bytes.
  double available_capacity;


 private:
  DISALLOW_COPY_AND_ASSIGN(StorageAvailableCapacityInfo);
};

enum EjectDeviceResultCode {
  EJECT_DEVICE_RESULT_CODE_NONE,
  EJECT_DEVICE_RESULT_CODE_SUCCESS,
  EJECT_DEVICE_RESULT_CODE_IN_USE,
  EJECT_DEVICE_RESULT_CODE_NO_SUCH_DEVICE,
  EJECT_DEVICE_RESULT_CODE_FAILURE,
  EJECT_DEVICE_RESULT_CODE_LAST = EJECT_DEVICE_RESULT_CODE_FAILURE,
};


const char* ToString(EjectDeviceResultCode as_enum);
EjectDeviceResultCode ParseEjectDeviceResultCode(const std::string& as_string);


//
// Functions
//

namespace GetInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<StorageUnitInfo>& info);
}  // namespace Results

}  // namespace GetInfo

namespace EjectDevice {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const EjectDeviceResultCode& result);
}  // namespace Results

}  // namespace EjectDevice

namespace GetAvailableCapacity {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const StorageAvailableCapacityInfo& info);
}  // namespace Results

}  // namespace GetAvailableCapacity

//
// Events
//

namespace OnAttached {

extern const char kEventName[];  // "system.storage.onAttached"

std::unique_ptr<base::ListValue> Create(const StorageUnitInfo& info);
}  // namespace OnAttached

namespace OnDetached {

extern const char kEventName[];  // "system.storage.onDetached"

std::unique_ptr<base::ListValue> Create(const std::string& id);
}  // namespace OnDetached

}  // namespace system_storage
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SYSTEM_STORAGE_H__
