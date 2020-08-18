// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_CAST_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_CAST_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_cast.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace cast {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // This is fired whenever the list of available sinks changes. A sink is a
  // device or a software surface that you can cast to.
  virtual void OnSinksUpdated(const SinksUpdatedParams& params) {}
  // This is fired whenever the outstanding issue/error message changes.
  // |issueMessage| is empty if there is no issue.
  virtual void OnIssueUpdated(const IssueUpdatedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // Experimental: This is fired whenever the list of available sinks changes. A sink is a
  // device or a software surface that you can cast to.
  virtual void OnSinksUpdated(const SinksUpdatedParams& params) final {}
  // Experimental: This is fired whenever the outstanding issue/error message changes.
  // |issueMessage| is empty if there is no issue.
  virtual void OnIssueUpdated(const IssueUpdatedParams& params) final {}
};

// A domain for interacting with Cast, Presentation API, and Remote Playback API
// functionalities.
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

  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleSetSinkToUseResponse(base::OnceCallback<void(std::unique_ptr<SetSinkToUseResult>)> callback, const base::Value& response);
  static void HandleStartTabMirroringResponse(base::OnceCallback<void(std::unique_ptr<StartTabMirroringResult>)> callback, const base::Value& response);
  static void HandleStopCastingResponse(base::OnceCallback<void(std::unique_ptr<StopCastingResult>)> callback, const base::Value& response);

  void DispatchSinksUpdatedEvent(const base::Value& params);
  void DispatchIssueUpdatedEvent(const base::Value& params);

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

  // Starts observing for sinks that can be used for tab mirroring, and if set,
  // sinks compatible with |presentationUrl| as well. When sinks are found, a
  // |sinksUpdated| event is fired.
  // Also starts observing for issue messages. When an issue is added or removed,
  // an |issueUpdated| event is fired.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Stops observing for sinks and issues.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Sets a sink to be used when the web page requests the browser to choose a
  // sink via Presentation API, Remote Playback API, or Cast SDK.
  void SetSinkToUse(std::unique_ptr<SetSinkToUseParams> params, base::OnceCallback<void(std::unique_ptr<SetSinkToUseResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetSinkToUseResult>)>());

  // Starts mirroring the tab to the sink.
  void StartTabMirroring(std::unique_ptr<StartTabMirroringParams> params, base::OnceCallback<void(std::unique_ptr<StartTabMirroringResult>)> callback = base::OnceCallback<void(std::unique_ptr<StartTabMirroringResult>)>());

  // Stops the active Cast session on the sink.
  void StopCasting(std::unique_ptr<StopCastingParams> params, base::OnceCallback<void(std::unique_ptr<StopCastingResult>)> callback = base::OnceCallback<void(std::unique_ptr<StopCastingResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace cast
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_CAST_H_
