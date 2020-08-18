// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_LOG_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_LOG_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_log.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace log {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Issued when new message was logged.
  virtual void OnEntryAdded(const EntryAddedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Issued when new message was logged.
  virtual void OnEntryAdded(const EntryAddedParams& params) {}
};

// Provides access to log entries.
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Clears the log.
  void Clear(std::unique_ptr<ClearParams> params, base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearResult>)>());
  void Clear(base::OnceClosure callback = base::OnceClosure());
  void Clear(std::unique_ptr<ClearParams> params, base::OnceClosure callback);

  // Disables log domain, prevents further log entries from being reported to the client.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());
  void Disable(base::OnceClosure callback = base::OnceClosure());
  void Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback);

  // Enables log domain, sends the entries collected so far to the client by means of the
  // `entryAdded` notification.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());
  void Enable(base::OnceClosure callback = base::OnceClosure());
  void Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback);

  // start violation reporting.
  void StartViolationsReport(std::unique_ptr<StartViolationsReportParams> params, base::OnceCallback<void(std::unique_ptr<StartViolationsReportResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartViolationsReportResult>)>());
  void StartViolationsReport(std::vector<std::unique_ptr<::headless::log::ViolationSetting>> config, base::OnceClosure callback = base::OnceClosure());
  void StartViolationsReport(std::unique_ptr<StartViolationsReportParams> params, base::OnceClosure callback);

  // Stop violation reporting.
  void StopViolationsReport(std::unique_ptr<StopViolationsReportParams> params, base::OnceCallback<void(std::unique_ptr<StopViolationsReportResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopViolationsReportResult>)>());
  void StopViolationsReport(base::OnceClosure callback = base::OnceClosure());
  void StopViolationsReport(std::unique_ptr<StopViolationsReportParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleClearResponse(base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleStartViolationsReportResponse(base::OnceCallback<void(std::unique_ptr<StartViolationsReportResult>)> callback, const base::Value& response);
  static void HandleStopViolationsReportResponse(base::OnceCallback<void(std::unique_ptr<StopViolationsReportResult>)> callback, const base::Value& response);

  void DispatchEntryAddedEvent(const base::Value& params);

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


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace log
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_LOG_H_
