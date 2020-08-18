// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_SECURITY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_SECURITY_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace security {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  // There is a certificate error. If overriding certificate errors is enabled, then it should be
  // handled with the `handleCertificateError` command. Note: this event does not fire if the
  // certificate error has been allowed internally. Only one client per target should override
  // certificate errors at the same time.
  virtual void OnCertificateError(const CertificateErrorParams& params) {}
  // The security state of the page changed.
  virtual void OnVisibleSecurityStateChanged(const VisibleSecurityStateChangedParams& params) {}
  // The security state of the page changed.
  virtual void OnSecurityStateChanged(const SecurityStateChangedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  // There is a certificate error. If overriding certificate errors is enabled, then it should be
  // handled with the `handleCertificateError` command. Note: this event does not fire if the
  // certificate error has been allowed internally. Only one client per target should override
  // certificate errors at the same time.
  virtual void OnCertificateError(const CertificateErrorParams& params) {}
  // Experimental: The security state of the page changed.
  virtual void OnVisibleSecurityStateChanged(const VisibleSecurityStateChangedParams& params) final {}
  // The security state of the page changed.
  virtual void OnSecurityStateChanged(const SecurityStateChangedParams& params) {}
};

// Security
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Disables tracking security state changes.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());
  void Disable(base::OnceClosure callback = base::OnceClosure());
  void Disable(std::unique_ptr<DisableParams> params, base::OnceClosure callback);

  // Enables tracking security state changes.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());
  void Enable(base::OnceClosure callback = base::OnceClosure());
  void Enable(std::unique_ptr<EnableParams> params, base::OnceClosure callback);

  // Handles a certificate error that fired a certificateError event.
  void HandleCertificateError(std::unique_ptr<HandleCertificateErrorParams> params, base::OnceCallback<void(std::unique_ptr<HandleCertificateErrorResult>)> callback = base::OnceCallback<void(std::unique_ptr<HandleCertificateErrorResult>)>());
  void HandleCertificateError(int event_id, ::headless::security::CertificateErrorAction action, base::OnceClosure callback = base::OnceClosure());
  void HandleCertificateError(std::unique_ptr<HandleCertificateErrorParams> params, base::OnceClosure callback);

  // Enable/disable overriding certificate errors. If enabled, all certificate error events need to
  // be handled by the DevTools client and should be answered with `handleCertificateError` commands.
  void SetOverrideCertificateErrors(std::unique_ptr<SetOverrideCertificateErrorsParams> params, base::OnceCallback<void(std::unique_ptr<SetOverrideCertificateErrorsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetOverrideCertificateErrorsResult>)>());
  void SetOverrideCertificateErrors(bool override, base::OnceClosure callback = base::OnceClosure());
  void SetOverrideCertificateErrors(std::unique_ptr<SetOverrideCertificateErrorsParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleSetIgnoreCertificateErrorsResponse(base::OnceCallback<void(std::unique_ptr<SetIgnoreCertificateErrorsResult>)> callback, const base::Value& response);
  static void HandleHandleCertificateErrorResponse(base::OnceCallback<void(std::unique_ptr<HandleCertificateErrorResult>)> callback, const base::Value& response);
  static void HandleSetOverrideCertificateErrorsResponse(base::OnceCallback<void(std::unique_ptr<SetOverrideCertificateErrorsResult>)> callback, const base::Value& response);

  void DispatchCertificateErrorEvent(const base::Value& params);
  void DispatchVisibleSecurityStateChangedEvent(const base::Value& params);
  void DispatchSecurityStateChangedEvent(const base::Value& params);

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

  // Enable/disable whether all certificate errors should be ignored.
  void SetIgnoreCertificateErrors(std::unique_ptr<SetIgnoreCertificateErrorsParams> params, base::OnceCallback<void(std::unique_ptr<SetIgnoreCertificateErrorsResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetIgnoreCertificateErrorsResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace security
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_SECURITY_H_
