// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_LOG_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_LOG_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_log.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<log::LogEntry> {
  static std::unique_ptr<log::LogEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::LogEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::LogEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::ViolationSetting> {
  static std::unique_ptr<log::ViolationSetting> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::ViolationSetting::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::ViolationSetting& value) {
  return value.Serialize();
}

template <>
struct FromValue<log::LogEntrySource> {
  static log::LogEntrySource Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return log::LogEntrySource::XML;
    }
    if (value.GetString() == "xml")
      return log::LogEntrySource::XML;
    if (value.GetString() == "javascript")
      return log::LogEntrySource::JAVASCRIPT;
    if (value.GetString() == "network")
      return log::LogEntrySource::NETWORK;
    if (value.GetString() == "storage")
      return log::LogEntrySource::STORAGE;
    if (value.GetString() == "appcache")
      return log::LogEntrySource::APPCACHE;
    if (value.GetString() == "rendering")
      return log::LogEntrySource::RENDERING;
    if (value.GetString() == "security")
      return log::LogEntrySource::SECURITY;
    if (value.GetString() == "deprecation")
      return log::LogEntrySource::DEPRECATION;
    if (value.GetString() == "worker")
      return log::LogEntrySource::WORKER;
    if (value.GetString() == "violation")
      return log::LogEntrySource::VIOLATION;
    if (value.GetString() == "intervention")
      return log::LogEntrySource::INTERVENTION;
    if (value.GetString() == "recommendation")
      return log::LogEntrySource::RECOMMENDATION;
    if (value.GetString() == "other")
      return log::LogEntrySource::OTHER;
    errors->AddError("invalid enum value");
    return log::LogEntrySource::XML;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::LogEntrySource& value) {
  switch (value) {
    case log::LogEntrySource::XML:
      return std::make_unique<base::Value>("xml");
    case log::LogEntrySource::JAVASCRIPT:
      return std::make_unique<base::Value>("javascript");
    case log::LogEntrySource::NETWORK:
      return std::make_unique<base::Value>("network");
    case log::LogEntrySource::STORAGE:
      return std::make_unique<base::Value>("storage");
    case log::LogEntrySource::APPCACHE:
      return std::make_unique<base::Value>("appcache");
    case log::LogEntrySource::RENDERING:
      return std::make_unique<base::Value>("rendering");
    case log::LogEntrySource::SECURITY:
      return std::make_unique<base::Value>("security");
    case log::LogEntrySource::DEPRECATION:
      return std::make_unique<base::Value>("deprecation");
    case log::LogEntrySource::WORKER:
      return std::make_unique<base::Value>("worker");
    case log::LogEntrySource::VIOLATION:
      return std::make_unique<base::Value>("violation");
    case log::LogEntrySource::INTERVENTION:
      return std::make_unique<base::Value>("intervention");
    case log::LogEntrySource::RECOMMENDATION:
      return std::make_unique<base::Value>("recommendation");
    case log::LogEntrySource::OTHER:
      return std::make_unique<base::Value>("other");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<log::LogEntryLevel> {
  static log::LogEntryLevel Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return log::LogEntryLevel::VERBOSE;
    }
    if (value.GetString() == "verbose")
      return log::LogEntryLevel::VERBOSE;
    if (value.GetString() == "info")
      return log::LogEntryLevel::INFO;
    if (value.GetString() == "warning")
      return log::LogEntryLevel::WARNING;
    if (value.GetString() == "error")
      return log::LogEntryLevel::ERR;
    errors->AddError("invalid enum value");
    return log::LogEntryLevel::VERBOSE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::LogEntryLevel& value) {
  switch (value) {
    case log::LogEntryLevel::VERBOSE:
      return std::make_unique<base::Value>("verbose");
    case log::LogEntryLevel::INFO:
      return std::make_unique<base::Value>("info");
    case log::LogEntryLevel::WARNING:
      return std::make_unique<base::Value>("warning");
    case log::LogEntryLevel::ERR:
      return std::make_unique<base::Value>("error");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<log::ViolationSettingName> {
  static log::ViolationSettingName Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return log::ViolationSettingName::LONG_TASK;
    }
    if (value.GetString() == "longTask")
      return log::ViolationSettingName::LONG_TASK;
    if (value.GetString() == "longLayout")
      return log::ViolationSettingName::LONG_LAYOUT;
    if (value.GetString() == "blockedEvent")
      return log::ViolationSettingName::BLOCKED_EVENT;
    if (value.GetString() == "blockedParser")
      return log::ViolationSettingName::BLOCKED_PARSER;
    if (value.GetString() == "discouragedAPIUse")
      return log::ViolationSettingName::DISCOURAGEDAPI_USE;
    if (value.GetString() == "handler")
      return log::ViolationSettingName::HANDLER;
    if (value.GetString() == "recurringHandler")
      return log::ViolationSettingName::RECURRING_HANDLER;
    errors->AddError("invalid enum value");
    return log::ViolationSettingName::LONG_TASK;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::ViolationSettingName& value) {
  switch (value) {
    case log::ViolationSettingName::LONG_TASK:
      return std::make_unique<base::Value>("longTask");
    case log::ViolationSettingName::LONG_LAYOUT:
      return std::make_unique<base::Value>("longLayout");
    case log::ViolationSettingName::BLOCKED_EVENT:
      return std::make_unique<base::Value>("blockedEvent");
    case log::ViolationSettingName::BLOCKED_PARSER:
      return std::make_unique<base::Value>("blockedParser");
    case log::ViolationSettingName::DISCOURAGEDAPI_USE:
      return std::make_unique<base::Value>("discouragedAPIUse");
    case log::ViolationSettingName::HANDLER:
      return std::make_unique<base::Value>("handler");
    case log::ViolationSettingName::RECURRING_HANDLER:
      return std::make_unique<base::Value>("recurringHandler");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<log::ClearParams> {
  static std::unique_ptr<log::ClearParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::ClearParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::ClearParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::ClearResult> {
  static std::unique_ptr<log::ClearResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::ClearResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::ClearResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::DisableParams> {
  static std::unique_ptr<log::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::DisableResult> {
  static std::unique_ptr<log::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::EnableParams> {
  static std::unique_ptr<log::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::EnableResult> {
  static std::unique_ptr<log::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::StartViolationsReportParams> {
  static std::unique_ptr<log::StartViolationsReportParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::StartViolationsReportParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::StartViolationsReportParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::StartViolationsReportResult> {
  static std::unique_ptr<log::StartViolationsReportResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::StartViolationsReportResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::StartViolationsReportResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::StopViolationsReportParams> {
  static std::unique_ptr<log::StopViolationsReportParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::StopViolationsReportParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::StopViolationsReportParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::StopViolationsReportResult> {
  static std::unique_ptr<log::StopViolationsReportResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::StopViolationsReportResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::StopViolationsReportResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<log::EntryAddedParams> {
  static std::unique_ptr<log::EntryAddedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return log::EntryAddedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const log::EntryAddedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_LOG_H_
