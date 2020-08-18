// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DATABASE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DATABASE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_database.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {



template <>
struct FromValue<database::Database> {
  static std::unique_ptr<database::Database> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::Database::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::Database& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::Error> {
  static std::unique_ptr<database::Error> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::Error::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::Error& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::DisableParams> {
  static std::unique_ptr<database::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::DisableResult> {
  static std::unique_ptr<database::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::EnableParams> {
  static std::unique_ptr<database::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::EnableResult> {
  static std::unique_ptr<database::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::ExecuteSQLParams> {
  static std::unique_ptr<database::ExecuteSQLParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::ExecuteSQLParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::ExecuteSQLParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::ExecuteSQLResult> {
  static std::unique_ptr<database::ExecuteSQLResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::ExecuteSQLResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::ExecuteSQLResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::GetDatabaseTableNamesParams> {
  static std::unique_ptr<database::GetDatabaseTableNamesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::GetDatabaseTableNamesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::GetDatabaseTableNamesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::GetDatabaseTableNamesResult> {
  static std::unique_ptr<database::GetDatabaseTableNamesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::GetDatabaseTableNamesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::GetDatabaseTableNamesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<database::AddDatabaseParams> {
  static std::unique_ptr<database::AddDatabaseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return database::AddDatabaseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const database::AddDatabaseParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DATABASE_H_
