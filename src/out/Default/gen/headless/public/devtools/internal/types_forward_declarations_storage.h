// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_STORAGE_H_

#include "base/values.h"

namespace headless {

namespace storage {
class UsageForType;
class ClearDataForOriginParams;
class ClearDataForOriginResult;
class GetCookiesParams;
class GetCookiesResult;
class SetCookiesParams;
class SetCookiesResult;
class ClearCookiesParams;
class ClearCookiesResult;
class GetUsageAndQuotaParams;
class GetUsageAndQuotaResult;
class TrackCacheStorageForOriginParams;
class TrackCacheStorageForOriginResult;
class TrackIndexedDBForOriginParams;
class TrackIndexedDBForOriginResult;
class UntrackCacheStorageForOriginParams;
class UntrackCacheStorageForOriginResult;
class UntrackIndexedDBForOriginParams;
class UntrackIndexedDBForOriginResult;
class CacheStorageContentUpdatedParams;
class CacheStorageListUpdatedParams;
class IndexedDBContentUpdatedParams;
class IndexedDBListUpdatedParams;

enum class StorageType {
  APPCACHE,
  COOKIES,
  FILE_SYSTEMS,
  INDEXEDDB,
  LOCAL_STORAGE,
  SHADER_CACHE,
  WEBSQL,
  SERVICE_WORKERS,
  CACHE_STORAGE,
  ALL,
  OTHER
};

}  // namespace storage

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_STORAGE_H_
