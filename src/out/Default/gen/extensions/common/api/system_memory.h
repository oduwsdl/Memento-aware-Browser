// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_memory.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SYSTEM_MEMORY_H__
#define EXTENSIONS_COMMON_API_SYSTEM_MEMORY_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace system_memory {

//
// Types
//

struct MemoryInfo {
  MemoryInfo();
  ~MemoryInfo();
  MemoryInfo(MemoryInfo&& rhs);
  MemoryInfo& operator=(MemoryInfo&& rhs);

  // Populates a MemoryInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, MemoryInfo* out);

  // Creates a MemoryInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<MemoryInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MemoryInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The total amount of physical memory capacity, in bytes.
  double capacity;

  // The amount of available capacity, in bytes.
  double available_capacity;


 private:
  DISALLOW_COPY_AND_ASSIGN(MemoryInfo);
};


//
// Functions
//

namespace GetInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const MemoryInfo& info);
}  // namespace Results

}  // namespace GetInfo

}  // namespace system_memory
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SYSTEM_MEMORY_H__
