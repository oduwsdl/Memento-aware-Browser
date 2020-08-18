// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_TRACING_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_TRACING_H_

#include "base/values.h"

namespace headless {

namespace tracing {
using MemoryDumpConfig = base::Value;
class TraceConfig;
class EndParams;
class EndResult;
class GetCategoriesParams;
class GetCategoriesResult;
class RecordClockSyncMarkerParams;
class RecordClockSyncMarkerResult;
class RequestMemoryDumpParams;
class RequestMemoryDumpResult;
class StartParams;
class StartResult;
class BufferUsageParams;
class DataCollectedParams;
class TracingCompleteParams;

enum class StreamFormat {
  JSON,
  PROTO
};

enum class StreamCompression {
  NONE,
  GZIP
};

enum class TraceConfigRecordMode {
  RECORD_UNTIL_FULL,
  RECORD_CONTINUOUSLY,
  RECORD_AS_MUCH_AS_POSSIBLE,
  ECHO_TO_CONSOLE
};

enum class StartTransferMode {
  REPORT_EVENTS,
  RETURN_AS_STREAM
};

}  // namespace tracing

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_TRACING_H_
