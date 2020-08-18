// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_PERFORMANCE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_PERFORMANCE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_performance.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace performance {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Current values of the metrics.
  virtual void OnMetrics(const MetricsParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Current values of the metrics.
  virtual void OnMetrics(const MetricsParams& params) {}
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

  // Disable collecting and reporting metrics.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());
  void Disable(base::OnceClosure callback = base::OnceClosure());
  void Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback);

  // Enable collecting and reporting metrics.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());
  void Enable(base::OnceClosure callback = base::OnceClosure());
  void Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback);

  // Retrieve current values of run-time metrics.
  void GetMetrics(std::unique_ptr<GetMetricsParams> params, base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)>());
  void GetMetrics(base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)>());

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleSetTimeDomainResponse(base::OnceCallback<void(std::unique_ptr<SetTimeDomainResult>)> callback, const base::Value& response);
  static void HandleGetMetricsResponse(base::OnceCallback<void(std::unique_ptr<GetMetricsResult>)> callback, const base::Value& response);

  void DispatchMetricsEvent(const base::Value& params);

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

  // Sets time domain to use for collecting and reporting duration metrics.
  // Note that this must be called before enabling metrics collection. Calling
  // this method while metrics collection is enabled returns an error.
  void SetTimeDomain(std::unique_ptr<SetTimeDomainParams> params, base::OnceCallback<void(std::unique_ptr<SetTimeDomainResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetTimeDomainResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace performance
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_PERFORMANCE_H_
