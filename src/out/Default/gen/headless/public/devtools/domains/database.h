// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DATABASE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DATABASE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_database.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace database {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnAddDatabase(const AddDatabaseParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnAddDatabase(const AddDatabaseParams& params) final {}
};

class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleExecuteSQLResponse(base::OnceCallback<void(std::unique_ptr<ExecuteSQLResult>)> callback, const base::Value& response);
  static void HandleGetDatabaseTableNamesResponse(base::OnceCallback<void(std::unique_ptr<GetDatabaseTableNamesResult>)> callback, const base::Value& response);

  void DispatchAddDatabaseEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  // Disables database tracking, prevents database events from being sent to the client.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables database tracking, database events will now be delivered to the client.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  void ExecuteSQL(std::unique_ptr<ExecuteSQLParams> params, base::OnceCallback<void(std::unique_ptr<ExecuteSQLResult>)> callback = base::OnceCallback<void(std::unique_ptr<ExecuteSQLResult>)>());

  void GetDatabaseTableNames(std::unique_ptr<GetDatabaseTableNamesParams> params, base::OnceCallback<void(std::unique_ptr<GetDatabaseTableNamesResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetDatabaseTableNamesResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace database
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DATABASE_H_
