// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_LOG_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_LOG_H_

#include "base/values.h"

namespace headless {

namespace log {
class LogEntry;
class ViolationSetting;
class ClearParams;
class ClearResult;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class StartViolationsReportParams;
class StartViolationsReportResult;
class StopViolationsReportParams;
class StopViolationsReportResult;
class EntryAddedParams;

enum class LogEntrySource {
  XML,
  JAVASCRIPT,
  NETWORK,
  STORAGE,
  APPCACHE,
  RENDERING,
  SECURITY,
  DEPRECATION,
  WORKER,
  VIOLATION,
  INTERVENTION,
  RECOMMENDATION,
  OTHER
};

enum class LogEntryLevel {
  VERBOSE,
  INFO,
  WARNING,
  ERR
};

enum class ViolationSettingName {
  LONG_TASK,
  LONG_LAYOUT,
  BLOCKED_EVENT,
  BLOCKED_PARSER,
  DISCOURAGEDAPI_USE,
  HANDLER,
  RECURRING_HANDLER
};

}  // namespace log

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_LOG_H_
