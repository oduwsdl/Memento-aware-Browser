// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/identity.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_IDENTITY_H__
#define CHROME_COMMON_EXTENSIONS_API_IDENTITY_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace identity {

//
// Types
//

struct AccountInfo {
  AccountInfo();
  ~AccountInfo();
  AccountInfo(AccountInfo&& rhs);
  AccountInfo& operator=(AccountInfo&& rhs);

  // Populates a AccountInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, AccountInfo* out);

  // Creates a AccountInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<AccountInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AccountInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A unique identifier for the account. This ID will not change for the lifetime
  // of the account.
  std::string id;


 private:
  DISALLOW_COPY_AND_ASSIGN(AccountInfo);
};

enum AccountStatus {
  ACCOUNT_STATUS_NONE,
  ACCOUNT_STATUS_SYNC,
  ACCOUNT_STATUS_ANY,
  ACCOUNT_STATUS_LAST = ACCOUNT_STATUS_ANY,
};


const char* ToString(AccountStatus as_enum);
AccountStatus ParseAccountStatus(const std::string& as_string);

struct ProfileDetails {
  ProfileDetails();
  ~ProfileDetails();
  ProfileDetails(ProfileDetails&& rhs);
  ProfileDetails& operator=(ProfileDetails&& rhs);

  // Populates a ProfileDetails object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ProfileDetails* out);

  // Creates a ProfileDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProfileDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProfileDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A status of the primary account signed into a profile whose
  // <code>ProfileUserInfo</code> should be returned. Defaults to
  // <code>SYNC</code> account status.
  AccountStatus account_status;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProfileDetails);
};

struct ProfileUserInfo {
  ProfileUserInfo();
  ~ProfileUserInfo();
  ProfileUserInfo(ProfileUserInfo&& rhs);
  ProfileUserInfo& operator=(ProfileUserInfo&& rhs);

  // Populates a ProfileUserInfo object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ProfileUserInfo* out);

  // Creates a ProfileUserInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<ProfileUserInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ProfileUserInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // An email address for the user account signed into the current profile. Empty
  // if the user is not signed in or the <code>identity.email</code> manifest
  // permission is not specified.
  std::string email;

  // A unique identifier for the account. This ID will not change for the lifetime
  // of the account. Empty if the user is not signed in or (in M41+) the
  // <code>identity.email</code> manifest permission is not specified.
  std::string id;


 private:
  DISALLOW_COPY_AND_ASSIGN(ProfileUserInfo);
};

struct TokenDetails {
  TokenDetails();
  ~TokenDetails();
  TokenDetails(TokenDetails&& rhs);
  TokenDetails& operator=(TokenDetails&& rhs);

  // Populates a TokenDetails object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, TokenDetails* out);

  // Creates a TokenDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<TokenDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TokenDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Fetching a token may require the user to sign-in to Chrome, or approve the
  // application's requested scopes. If the interactive flag is <code>true</code>,
  // <code>getAuthToken</code> will prompt the user as necessary. When the flag is
  // <code>false</code> or omitted, <code>getAuthToken</code> will return failure
  // any time a prompt would be required.
  std::unique_ptr<bool> interactive;

  // The account ID whose token should be returned. If not specified, the function
  // will use an account from the Chrome profile: the Sync account if there is
  // one, or otherwise the first Google web account.
  std::unique_ptr<AccountInfo> account;

  // <p>A list of OAuth2 scopes to request.</p><p>When the <code>scopes</code>
  // field is present, it overrides the list of scopes specified in
  // manifest.json.</p>
  std::unique_ptr<std::vector<std::string>> scopes;


 private:
  DISALLOW_COPY_AND_ASSIGN(TokenDetails);
};

struct InvalidTokenDetails {
  InvalidTokenDetails();
  ~InvalidTokenDetails();
  InvalidTokenDetails(InvalidTokenDetails&& rhs);
  InvalidTokenDetails& operator=(InvalidTokenDetails&& rhs);

  // Populates a InvalidTokenDetails object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, InvalidTokenDetails* out);

  // Creates a InvalidTokenDetails object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<InvalidTokenDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InvalidTokenDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The specific token that should be removed from the cache.
  std::string token;


 private:
  DISALLOW_COPY_AND_ASSIGN(InvalidTokenDetails);
};

struct WebAuthFlowDetails {
  WebAuthFlowDetails();
  ~WebAuthFlowDetails();
  WebAuthFlowDetails(WebAuthFlowDetails&& rhs);
  WebAuthFlowDetails& operator=(WebAuthFlowDetails&& rhs);

  // Populates a WebAuthFlowDetails object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, WebAuthFlowDetails* out);

  // Creates a WebAuthFlowDetails object from a base::Value, or NULL on failure.
  static std::unique_ptr<WebAuthFlowDetails> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this WebAuthFlowDetails object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The URL that initiates the auth flow.
  std::string url;

  // <p>Whether to launch auth flow in interactive mode.</p><p>Since some auth
  // flows may immediately redirect to a result URL,
  // <code>launchWebAuthFlow</code> hides its web view until the first navigation
  // either redirects to the final URL, or finishes loading a page meant to be
  // displayed.</p><p>If the interactive flag is <code>true</code>, the window
  // will be displayed when a page load completes. If the flag is
  // <code>false</code> or omitted, <code>launchWebAuthFlow</code> will return
  // with an error if the initial navigation does not complete the flow.</p>
  std::unique_ptr<bool> interactive;


 private:
  DISALLOW_COPY_AND_ASSIGN(WebAuthFlowDetails);
};


//
// Functions
//

namespace GetAccounts {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<AccountInfo>& accounts);
}  // namespace Results

}  // namespace GetAccounts

namespace GetAuthToken {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Token options.
  std::unique_ptr<TokenDetails> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& token);
}  // namespace Results

}  // namespace GetAuthToken

namespace GetProfileUserInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Profile options.
  std::unique_ptr<ProfileDetails> details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const ProfileUserInfo& user_info);
}  // namespace Results

}  // namespace GetProfileUserInfo

namespace RemoveCachedAuthToken {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Token information.
  InvalidTokenDetails details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveCachedAuthToken

namespace LaunchWebAuthFlow {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // WebAuth flow options.
  WebAuthFlowDetails details;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& response_url);
}  // namespace Results

}  // namespace LaunchWebAuthFlow

//
// Events
//

namespace OnSignInChanged {

extern const char kEventName[];  // "identity.onSignInChanged"

std::unique_ptr<base::ListValue> Create(const AccountInfo& account, bool signed_in);
}  // namespace OnSignInChanged

}  // namespace identity
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_IDENTITY_H__
