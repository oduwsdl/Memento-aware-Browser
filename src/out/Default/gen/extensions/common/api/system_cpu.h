// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_cpu.idl
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_SYSTEM_CPU_H__
#define EXTENSIONS_COMMON_API_SYSTEM_CPU_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace system_cpu {

//
// Types
//

struct CpuTime {
  CpuTime();
  ~CpuTime();
  CpuTime(CpuTime&& rhs);
  CpuTime& operator=(CpuTime&& rhs);

  // Populates a CpuTime object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, CpuTime* out);

  // Creates a CpuTime object from a base::Value, or NULL on failure.
  static std::unique_ptr<CpuTime> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CpuTime object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The cumulative time used by userspace programs on this processor.
  double user;

  // The cumulative time used by kernel programs on this processor.
  double kernel;

  // The cumulative time spent idle by this processor.
  double idle;

  // The total cumulative time for this processor.  This value is equal to user +
  // kernel + idle.
  double total;


 private:
  DISALLOW_COPY_AND_ASSIGN(CpuTime);
};

struct ProcessorInfo {
  ProcessorInfo();
  ~ProcessorInfo();
  ProcessorInfo(ProcessorInfo&& rhs);
  ProcessorInfo& operator=(ProcessorInfo&& rhs);

  // Populates a ProcessorInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ProcessorInfo* out);

  // Creates a ProcessorInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProcessorInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProcessorInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Cumulative usage info for this logical processor.
  CpuTime usage;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProcessorInfo);
};

struct CpuInfo {
  CpuInfo();
  ~CpuInfo();
  CpuInfo(CpuInfo&& rhs);
  CpuInfo& operator=(CpuInfo&& rhs);

  // Populates a CpuInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, CpuInfo* out);

  // Creates a CpuInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<CpuInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CpuInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The number of logical processors.
  int num_of_processors;

  // The architecture name of the processors.
  std::string arch_name;

  // The model name of the processors.
  std::string model_name;

  // A set of feature codes indicating some of the processor's capabilities. The
  // currently supported codes are "mmx", "sse", "sse2", "sse3", "ssse3",
  // "sse4_1", "sse4_2", and "avx".
  std::vector<std::string> features;

  // Information about each logical processor.
  std::vector<ProcessorInfo> processors;

  // <p>List of CPU temperature readings from each thermal zone of the CPU.
  // Temperatures are in degrees Celsius.</p><p><b>Currently supported on Chrome
  // OS only.</b></p>
  std::vector<double> temperatures;


 private:
  DISALLOW_COPY_AND_ASSIGN(CpuInfo);
};


//
// Functions
//

namespace GetInfo {

namespace Results {

std::unique_ptr<base::ListValue> Create(const CpuInfo& info);
}  // namespace Results

}  // namespace GetInfo

}  // namespace system_cpu
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_SYSTEM_CPU_H__
