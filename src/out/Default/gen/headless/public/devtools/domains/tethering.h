// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TETHERING_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TETHERING_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_tethering.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace tethering {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // Informs that port was successfully bound and got a specified connection id.
  virtual void OnAccepted(const AcceptedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: Informs that port was successfully bound and got a specified connection id.
  virtual void OnAccepted(const AcceptedParams& params) final {}
};

// The Tethering domain defines methods and events for browser port binding.
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

  static void HandleBindResponse(base::OnceCallback<void(std::unique_ptr<BindResult>)> callback, const base::Value& response);
  static void HandleUnbindResponse(base::OnceCallback<void(std::unique_ptr<UnbindResult>)> callback, const base::Value& response);

  void DispatchAcceptedEvent(const base::Value& params);

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

  // Request browser port binding.
  void Bind(std::unique_ptr<BindParams> params, base::OnceCallback<void(std::unique_ptr<BindResult>)> callback = base::OnceCallback<void(std::unique_ptr<BindResult>)>());

  // Request browser port unbinding.
  void Unbind(std::unique_ptr<UnbindParams> params, base::OnceCallback<void(std::unique_ptr<UnbindResult>)> callback = base::OnceCallback<void(std::unique_ptr<UnbindResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace tethering
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TETHERING_H_
