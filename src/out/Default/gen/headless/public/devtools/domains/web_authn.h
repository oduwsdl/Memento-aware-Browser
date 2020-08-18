// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_WEB_AUTHN_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_WEB_AUTHN_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_web_authn.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace web_authn {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

// This domain allows configuring virtual authenticators to test the WebAuthn
// API.
class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleAddVirtualAuthenticatorResponse(base::OnceCallback<void(std::unique_ptr<AddVirtualAuthenticatorResult>)> callback, const base::Value& response);
  static void HandleRemoveVirtualAuthenticatorResponse(base::OnceCallback<void(std::unique_ptr<RemoveVirtualAuthenticatorResult>)> callback, const base::Value& response);
  static void HandleAddCredentialResponse(base::OnceCallback<void(std::unique_ptr<AddCredentialResult>)> callback, const base::Value& response);
  static void HandleGetCredentialResponse(base::OnceCallback<void(std::unique_ptr<GetCredentialResult>)> callback, const base::Value& response);
  static void HandleGetCredentialsResponse(base::OnceCallback<void(std::unique_ptr<GetCredentialsResult>)> callback, const base::Value& response);
  static void HandleRemoveCredentialResponse(base::OnceCallback<void(std::unique_ptr<RemoveCredentialResult>)> callback, const base::Value& response);
  static void HandleClearCredentialsResponse(base::OnceCallback<void(std::unique_ptr<ClearCredentialsResult>)> callback, const base::Value& response);
  static void HandleSetUserVerifiedResponse(base::OnceCallback<void(std::unique_ptr<SetUserVerifiedResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // Enable the WebAuthn domain and start intercepting credential storage and
  // retrieval with a virtual authenticator.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Disable the WebAuthn domain.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Creates and adds a virtual authenticator.
  void AddVirtualAuthenticator(std::unique_ptr<AddVirtualAuthenticatorParams> params, base::OnceCallback<void(std::unique_ptr<AddVirtualAuthenticatorResult>)> callback = base::OnceCallback<void(std::unique_ptr<AddVirtualAuthenticatorResult>)>());

  // Removes the given authenticator.
  void RemoveVirtualAuthenticator(std::unique_ptr<RemoveVirtualAuthenticatorParams> params, base::OnceCallback<void(std::unique_ptr<RemoveVirtualAuthenticatorResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveVirtualAuthenticatorResult>)>());

  // Adds the credential to the specified authenticator.
  void AddCredential(std::unique_ptr<AddCredentialParams> params, base::OnceCallback<void(std::unique_ptr<AddCredentialResult>)> callback = base::OnceCallback<void(std::unique_ptr<AddCredentialResult>)>());

  // Returns a single credential stored in the given virtual authenticator that
  // matches the credential ID.
  void GetCredential(std::unique_ptr<GetCredentialParams> params, base::OnceCallback<void(std::unique_ptr<GetCredentialResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCredentialResult>)>());

  // Returns all the credentials stored in the given virtual authenticator.
  void GetCredentials(std::unique_ptr<GetCredentialsParams> params, base::OnceCallback<void(std::unique_ptr<GetCredentialsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetCredentialsResult>)>());

  // Removes a credential from the authenticator.
  void RemoveCredential(std::unique_ptr<RemoveCredentialParams> params, base::OnceCallback<void(std::unique_ptr<RemoveCredentialResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveCredentialResult>)>());

  // Clears all the credentials from the specified device.
  void ClearCredentials(std::unique_ptr<ClearCredentialsParams> params, base::OnceCallback<void(std::unique_ptr<ClearCredentialsResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearCredentialsResult>)>());

  // Sets whether User Verification succeeds or fails for an authenticator.
  // The default is true.
  void SetUserVerified(std::unique_ptr<SetUserVerifiedParams> params, base::OnceCallback<void(std::unique_ptr<SetUserVerifiedResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetUserVerifiedResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace web_authn
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_WEB_AUTHN_H_
