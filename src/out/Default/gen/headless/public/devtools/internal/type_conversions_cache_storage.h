// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CACHE_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CACHE_STORAGE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_cache_storage.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<cache_storage::CachedResponseType> {
  static cache_storage::CachedResponseType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return cache_storage::CachedResponseType::BASIC;
    }
    if (value.GetString() == "basic")
      return cache_storage::CachedResponseType::BASIC;
    if (value.GetString() == "cors")
      return cache_storage::CachedResponseType::CORS;
    if (value.GetString() == "default")
      return cache_storage::CachedResponseType::DEFAULT;
    if (value.GetString() == "error")
      return cache_storage::CachedResponseType::ERR;
    if (value.GetString() == "opaqueResponse")
      return cache_storage::CachedResponseType::OPAQUE_RESPONSE;
    if (value.GetString() == "opaqueRedirect")
      return cache_storage::CachedResponseType::OPAQUE_REDIRECT;
    errors->AddError("invalid enum value");
    return cache_storage::CachedResponseType::BASIC;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::CachedResponseType& value) {
  switch (value) {
    case cache_storage::CachedResponseType::BASIC:
      return std::make_unique<base::Value>("basic");
    case cache_storage::CachedResponseType::CORS:
      return std::make_unique<base::Value>("cors");
    case cache_storage::CachedResponseType::DEFAULT:
      return std::make_unique<base::Value>("default");
    case cache_storage::CachedResponseType::ERR:
      return std::make_unique<base::Value>("error");
    case cache_storage::CachedResponseType::OPAQUE_RESPONSE:
      return std::make_unique<base::Value>("opaqueResponse");
    case cache_storage::CachedResponseType::OPAQUE_REDIRECT:
      return std::make_unique<base::Value>("opaqueRedirect");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<cache_storage::DataEntry> {
  static std::unique_ptr<cache_storage::DataEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::DataEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::DataEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::Cache> {
  static std::unique_ptr<cache_storage::Cache> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::Cache::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::Cache& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::Header> {
  static std::unique_ptr<cache_storage::Header> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::Header::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::Header& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::CachedResponse> {
  static std::unique_ptr<cache_storage::CachedResponse> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::CachedResponse::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::CachedResponse& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::DeleteCacheParams> {
  static std::unique_ptr<cache_storage::DeleteCacheParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::DeleteCacheParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::DeleteCacheParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::DeleteCacheResult> {
  static std::unique_ptr<cache_storage::DeleteCacheResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::DeleteCacheResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::DeleteCacheResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::DeleteEntryParams> {
  static std::unique_ptr<cache_storage::DeleteEntryParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::DeleteEntryParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::DeleteEntryParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::DeleteEntryResult> {
  static std::unique_ptr<cache_storage::DeleteEntryResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::DeleteEntryResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::DeleteEntryResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::RequestCacheNamesParams> {
  static std::unique_ptr<cache_storage::RequestCacheNamesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::RequestCacheNamesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::RequestCacheNamesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::RequestCacheNamesResult> {
  static std::unique_ptr<cache_storage::RequestCacheNamesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::RequestCacheNamesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::RequestCacheNamesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::RequestCachedResponseParams> {
  static std::unique_ptr<cache_storage::RequestCachedResponseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::RequestCachedResponseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::RequestCachedResponseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::RequestCachedResponseResult> {
  static std::unique_ptr<cache_storage::RequestCachedResponseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::RequestCachedResponseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::RequestCachedResponseResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::RequestEntriesParams> {
  static std::unique_ptr<cache_storage::RequestEntriesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::RequestEntriesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::RequestEntriesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<cache_storage::RequestEntriesResult> {
  static std::unique_ptr<cache_storage::RequestEntriesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return cache_storage::RequestEntriesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const cache_storage::RequestEntriesResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CACHE_STORAGE_H_
