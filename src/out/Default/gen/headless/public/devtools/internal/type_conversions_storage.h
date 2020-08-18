// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_STORAGE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_storage.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {

template <>
struct FromValue<storage::StorageType> {
  static storage::StorageType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return storage::StorageType::APPCACHE;
    }
    if (value.GetString() == "appcache")
      return storage::StorageType::APPCACHE;
    if (value.GetString() == "cookies")
      return storage::StorageType::COOKIES;
    if (value.GetString() == "file_systems")
      return storage::StorageType::FILE_SYSTEMS;
    if (value.GetString() == "indexeddb")
      return storage::StorageType::INDEXEDDB;
    if (value.GetString() == "local_storage")
      return storage::StorageType::LOCAL_STORAGE;
    if (value.GetString() == "shader_cache")
      return storage::StorageType::SHADER_CACHE;
    if (value.GetString() == "websql")
      return storage::StorageType::WEBSQL;
    if (value.GetString() == "service_workers")
      return storage::StorageType::SERVICE_WORKERS;
    if (value.GetString() == "cache_storage")
      return storage::StorageType::CACHE_STORAGE;
    if (value.GetString() == "all")
      return storage::StorageType::ALL;
    if (value.GetString() == "other")
      return storage::StorageType::OTHER;
    errors->AddError("invalid enum value");
    return storage::StorageType::APPCACHE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::StorageType& value) {
  switch (value) {
    case storage::StorageType::APPCACHE:
      return std::make_unique<base::Value>("appcache");
    case storage::StorageType::COOKIES:
      return std::make_unique<base::Value>("cookies");
    case storage::StorageType::FILE_SYSTEMS:
      return std::make_unique<base::Value>("file_systems");
    case storage::StorageType::INDEXEDDB:
      return std::make_unique<base::Value>("indexeddb");
    case storage::StorageType::LOCAL_STORAGE:
      return std::make_unique<base::Value>("local_storage");
    case storage::StorageType::SHADER_CACHE:
      return std::make_unique<base::Value>("shader_cache");
    case storage::StorageType::WEBSQL:
      return std::make_unique<base::Value>("websql");
    case storage::StorageType::SERVICE_WORKERS:
      return std::make_unique<base::Value>("service_workers");
    case storage::StorageType::CACHE_STORAGE:
      return std::make_unique<base::Value>("cache_storage");
    case storage::StorageType::ALL:
      return std::make_unique<base::Value>("all");
    case storage::StorageType::OTHER:
      return std::make_unique<base::Value>("other");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<storage::UsageForType> {
  static std::unique_ptr<storage::UsageForType> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::UsageForType::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::UsageForType& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::ClearDataForOriginParams> {
  static std::unique_ptr<storage::ClearDataForOriginParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::ClearDataForOriginParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::ClearDataForOriginParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::ClearDataForOriginResult> {
  static std::unique_ptr<storage::ClearDataForOriginResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::ClearDataForOriginResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::ClearDataForOriginResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::GetCookiesParams> {
  static std::unique_ptr<storage::GetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::GetCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::GetCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::GetCookiesResult> {
  static std::unique_ptr<storage::GetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::GetCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::GetCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::SetCookiesParams> {
  static std::unique_ptr<storage::SetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::SetCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::SetCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::SetCookiesResult> {
  static std::unique_ptr<storage::SetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::SetCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::SetCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::ClearCookiesParams> {
  static std::unique_ptr<storage::ClearCookiesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::ClearCookiesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::ClearCookiesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::ClearCookiesResult> {
  static std::unique_ptr<storage::ClearCookiesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::ClearCookiesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::ClearCookiesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::GetUsageAndQuotaParams> {
  static std::unique_ptr<storage::GetUsageAndQuotaParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::GetUsageAndQuotaParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::GetUsageAndQuotaParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::GetUsageAndQuotaResult> {
  static std::unique_ptr<storage::GetUsageAndQuotaResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::GetUsageAndQuotaResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::GetUsageAndQuotaResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::TrackCacheStorageForOriginParams> {
  static std::unique_ptr<storage::TrackCacheStorageForOriginParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::TrackCacheStorageForOriginParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::TrackCacheStorageForOriginParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::TrackCacheStorageForOriginResult> {
  static std::unique_ptr<storage::TrackCacheStorageForOriginResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::TrackCacheStorageForOriginResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::TrackCacheStorageForOriginResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::TrackIndexedDBForOriginParams> {
  static std::unique_ptr<storage::TrackIndexedDBForOriginParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::TrackIndexedDBForOriginParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::TrackIndexedDBForOriginParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::TrackIndexedDBForOriginResult> {
  static std::unique_ptr<storage::TrackIndexedDBForOriginResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::TrackIndexedDBForOriginResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::TrackIndexedDBForOriginResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::UntrackCacheStorageForOriginParams> {
  static std::unique_ptr<storage::UntrackCacheStorageForOriginParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::UntrackCacheStorageForOriginParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::UntrackCacheStorageForOriginParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::UntrackCacheStorageForOriginResult> {
  static std::unique_ptr<storage::UntrackCacheStorageForOriginResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::UntrackCacheStorageForOriginResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::UntrackCacheStorageForOriginResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::UntrackIndexedDBForOriginParams> {
  static std::unique_ptr<storage::UntrackIndexedDBForOriginParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::UntrackIndexedDBForOriginParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::UntrackIndexedDBForOriginParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::UntrackIndexedDBForOriginResult> {
  static std::unique_ptr<storage::UntrackIndexedDBForOriginResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::UntrackIndexedDBForOriginResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::UntrackIndexedDBForOriginResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::CacheStorageContentUpdatedParams> {
  static std::unique_ptr<storage::CacheStorageContentUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::CacheStorageContentUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::CacheStorageContentUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::CacheStorageListUpdatedParams> {
  static std::unique_ptr<storage::CacheStorageListUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::CacheStorageListUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::CacheStorageListUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::IndexedDBContentUpdatedParams> {
  static std::unique_ptr<storage::IndexedDBContentUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::IndexedDBContentUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::IndexedDBContentUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<storage::IndexedDBListUpdatedParams> {
  static std::unique_ptr<storage::IndexedDBListUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return storage::IndexedDBListUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const storage::IndexedDBListUpdatedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_STORAGE_H_
