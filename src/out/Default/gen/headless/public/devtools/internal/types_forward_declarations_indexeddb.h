// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_INDEXEDDB_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_INDEXEDDB_H_

#include "base/values.h"

namespace headless {

namespace indexeddb {
class DatabaseWithObjectStores;
class ObjectStore;
class ObjectStoreIndex;
class Key;
class KeyRange;
class DataEntry;
class KeyPath;
class ClearObjectStoreParams;
class ClearObjectStoreResult;
class DeleteDatabaseParams;
class DeleteDatabaseResult;
class DeleteObjectStoreEntriesParams;
class DeleteObjectStoreEntriesResult;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class RequestDataParams;
class RequestDataResult;
class GetMetadataParams;
class GetMetadataResult;
class RequestDatabaseParams;
class RequestDatabaseResult;
class RequestDatabaseNamesParams;
class RequestDatabaseNamesResult;

enum class KeyType {
  NUMBER,
  STRING,
  DATE,
  ARRAY
};

enum class KeyPathType {
  NONE,
  STRING,
  ARRAY
};

}  // namespace indexeddb

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_INDEXEDDB_H_
