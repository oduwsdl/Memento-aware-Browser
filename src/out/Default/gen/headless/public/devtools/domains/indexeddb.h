// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_INDEXEDDB_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_INDEXEDDB_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_indexeddb.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace indexeddb {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleClearObjectStoreResponse(base::OnceCallback<void(std::unique_ptr<ClearObjectStoreResult>)> callback, const base::Value& response);
  static void HandleDeleteDatabaseResponse(base::OnceCallback<void(std::unique_ptr<DeleteDatabaseResult>)> callback, const base::Value& response);
  static void HandleDeleteObjectStoreEntriesResponse(base::OnceCallback<void(std::unique_ptr<DeleteObjectStoreEntriesResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleRequestDataResponse(base::OnceCallback<void(std::unique_ptr<RequestDataResult>)> callback, const base::Value& response);
  static void HandleGetMetadataResponse(base::OnceCallback<void(std::unique_ptr<GetMetadataResult>)> callback, const base::Value& response);
  static void HandleRequestDatabaseResponse(base::OnceCallback<void(std::unique_ptr<RequestDatabaseResult>)> callback, const base::Value& response);
  static void HandleRequestDatabaseNamesResponse(base::OnceCallback<void(std::unique_ptr<RequestDatabaseNamesResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // Clears all entries from an object store.
  void ClearObjectStore(std::unique_ptr<ClearObjectStoreParams> params, base::OnceCallback<void(std::unique_ptr<ClearObjectStoreResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearObjectStoreResult>)>());

  // Deletes a database.
  void DeleteDatabase(std::unique_ptr<DeleteDatabaseParams> params, base::OnceCallback<void(std::unique_ptr<DeleteDatabaseResult>)> callback = base::OnceCallback<void(std::unique_ptr<DeleteDatabaseResult>)>());

  // Delete a range of entries from an object store
  void DeleteObjectStoreEntries(std::unique_ptr<DeleteObjectStoreEntriesParams> params, base::OnceCallback<void(std::unique_ptr<DeleteObjectStoreEntriesResult>)> callback = base::OnceCallback<void(std::unique_ptr<DeleteObjectStoreEntriesResult>)>());

  // Disables events from backend.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables events from backend.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Requests data from object store or index.
  void RequestData(std::unique_ptr<RequestDataParams> params, base::OnceCallback<void(std::unique_ptr<RequestDataResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestDataResult>)>());

  // Gets metadata of an object store
  void GetMetadata(std::unique_ptr<GetMetadataParams> params, base::OnceCallback<void(std::unique_ptr<GetMetadataResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetMetadataResult>)>());

  // Requests database with given name in given frame.
  void RequestDatabase(std::unique_ptr<RequestDatabaseParams> params, base::OnceCallback<void(std::unique_ptr<RequestDatabaseResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestDatabaseResult>)>());

  // Requests database names for given security origin.
  void RequestDatabaseNames(std::unique_ptr<RequestDatabaseNamesParams> params, base::OnceCallback<void(std::unique_ptr<RequestDatabaseNamesResult>)> callback = base::OnceCallback<void(std::unique_ptr<RequestDatabaseNamesResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace indexeddb
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_INDEXEDDB_H_
