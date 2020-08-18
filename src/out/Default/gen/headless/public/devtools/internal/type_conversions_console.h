// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CONSOLE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CONSOLE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_console.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<console::ConsoleMessage> {
  static std::unique_ptr<console::ConsoleMessage> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::ConsoleMessage::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::ConsoleMessage& value) {
  return value.Serialize();
}

template <>
struct FromValue<console::ConsoleMessageSource> {
  static console::ConsoleMessageSource Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return console::ConsoleMessageSource::XML;
    }
    if (value.GetString() == "xml")
      return console::ConsoleMessageSource::XML;
    if (value.GetString() == "javascript")
      return console::ConsoleMessageSource::JAVASCRIPT;
    if (value.GetString() == "network")
      return console::ConsoleMessageSource::NETWORK;
    if (value.GetString() == "console-api")
      return console::ConsoleMessageSource::CONSOLE_API;
    if (value.GetString() == "storage")
      return console::ConsoleMessageSource::STORAGE;
    if (value.GetString() == "appcache")
      return console::ConsoleMessageSource::APPCACHE;
    if (value.GetString() == "rendering")
      return console::ConsoleMessageSource::RENDERING;
    if (value.GetString() == "security")
      return console::ConsoleMessageSource::SECURITY;
    if (value.GetString() == "other")
      return console::ConsoleMessageSource::OTHER;
    if (value.GetString() == "deprecation")
      return console::ConsoleMessageSource::DEPRECATION;
    if (value.GetString() == "worker")
      return console::ConsoleMessageSource::WORKER;
    errors->AddError("invalid enum value");
    return console::ConsoleMessageSource::XML;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::ConsoleMessageSource& value) {
  switch (value) {
    case console::ConsoleMessageSource::XML:
      return std::make_unique<base::Value>("xml");
    case console::ConsoleMessageSource::JAVASCRIPT:
      return std::make_unique<base::Value>("javascript");
    case console::ConsoleMessageSource::NETWORK:
      return std::make_unique<base::Value>("network");
    case console::ConsoleMessageSource::CONSOLE_API:
      return std::make_unique<base::Value>("console-api");
    case console::ConsoleMessageSource::STORAGE:
      return std::make_unique<base::Value>("storage");
    case console::ConsoleMessageSource::APPCACHE:
      return std::make_unique<base::Value>("appcache");
    case console::ConsoleMessageSource::RENDERING:
      return std::make_unique<base::Value>("rendering");
    case console::ConsoleMessageSource::SECURITY:
      return std::make_unique<base::Value>("security");
    case console::ConsoleMessageSource::OTHER:
      return std::make_unique<base::Value>("other");
    case console::ConsoleMessageSource::DEPRECATION:
      return std::make_unique<base::Value>("deprecation");
    case console::ConsoleMessageSource::WORKER:
      return std::make_unique<base::Value>("worker");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<console::ConsoleMessageLevel> {
  static console::ConsoleMessageLevel Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return console::ConsoleMessageLevel::LOG;
    }
    if (value.GetString() == "log")
      return console::ConsoleMessageLevel::LOG;
    if (value.GetString() == "warning")
      return console::ConsoleMessageLevel::WARNING;
    if (value.GetString() == "error")
      return console::ConsoleMessageLevel::ERR;
    if (value.GetString() == "debug")
      return console::ConsoleMessageLevel::DEBUG;
    if (value.GetString() == "info")
      return console::ConsoleMessageLevel::INFO;
    errors->AddError("invalid enum value");
    return console::ConsoleMessageLevel::LOG;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::ConsoleMessageLevel& value) {
  switch (value) {
    case console::ConsoleMessageLevel::LOG:
      return std::make_unique<base::Value>("log");
    case console::ConsoleMessageLevel::WARNING:
      return std::make_unique<base::Value>("warning");
    case console::ConsoleMessageLevel::ERR:
      return std::make_unique<base::Value>("error");
    case console::ConsoleMessageLevel::DEBUG:
      return std::make_unique<base::Value>("debug");
    case console::ConsoleMessageLevel::INFO:
      return std::make_unique<base::Value>("info");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<console::ClearMessagesParams> {
  static std::unique_ptr<console::ClearMessagesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::ClearMessagesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::ClearMessagesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<console::ClearMessagesResult> {
  static std::unique_ptr<console::ClearMessagesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::ClearMessagesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::ClearMessagesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<console::DisableParams> {
  static std::unique_ptr<console::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<console::DisableResult> {
  static std::unique_ptr<console::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<console::EnableParams> {
  static std::unique_ptr<console::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<console::EnableResult> {
  static std::unique_ptr<console::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<console::MessageAddedParams> {
  static std::unique_ptr<console::MessageAddedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return console::MessageAddedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const console::MessageAddedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CONSOLE_H_
