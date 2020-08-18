// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_WEB_AUTHN_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_WEB_AUTHN_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_web_authn.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace web_authn {

class HEADLESS_EXPORT VirtualAuthenticatorOptions {
 public:
  static std::unique_ptr<VirtualAuthenticatorOptions> Parse(const base::Value& value, ErrorReporter* errors);
  ~VirtualAuthenticatorOptions() { }

  ::headless::web_authn::AuthenticatorProtocol GetProtocol() const { return protocol_; }
  void SetProtocol(::headless::web_authn::AuthenticatorProtocol value) { protocol_ = value; }

  ::headless::web_authn::AuthenticatorTransport GetTransport() const { return transport_; }
  void SetTransport(::headless::web_authn::AuthenticatorTransport value) { transport_ = value; }

  // Defaults to false.
  bool HasHasResidentKey() const { return !!has_resident_key_; }
  bool GetHasResidentKey() const { DCHECK(HasHasResidentKey()); return has_resident_key_.value(); }
  void SetHasResidentKey(bool value) { has_resident_key_ = value; }

  // Defaults to false.
  bool HasHasUserVerification() const { return !!has_user_verification_; }
  bool GetHasUserVerification() const { DCHECK(HasHasUserVerification()); return has_user_verification_.value(); }
  void SetHasUserVerification(bool value) { has_user_verification_ = value; }

  // If set to true, tests of user presence will succeed immediately.
  // Otherwise, they will not be resolved. Defaults to true.
  bool HasAutomaticPresenceSimulation() const { return !!automatic_presence_simulation_; }
  bool GetAutomaticPresenceSimulation() const { DCHECK(HasAutomaticPresenceSimulation()); return automatic_presence_simulation_.value(); }
  void SetAutomaticPresenceSimulation(bool value) { automatic_presence_simulation_ = value; }

  // Sets whether User Verification succeeds or fails for an authenticator.
  // Defaults to false.
  bool HasIsUserVerified() const { return !!is_user_verified_; }
  bool GetIsUserVerified() const { DCHECK(HasIsUserVerified()); return is_user_verified_.value(); }
  void SetIsUserVerified(bool value) { is_user_verified_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<VirtualAuthenticatorOptions> Clone() const;

  template<int STATE>
  class VirtualAuthenticatorOptionsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProtocolSet = 1 << 1,
    kTransportSet = 1 << 2,
      kAllRequiredFieldsSet = (kProtocolSet | kTransportSet | 0)
    };

    VirtualAuthenticatorOptionsBuilder<STATE | kProtocolSet>& SetProtocol(::headless::web_authn::AuthenticatorProtocol value) {
      static_assert(!(STATE & kProtocolSet), "property protocol should not have already been set");
      result_->SetProtocol(value);
      return CastState<kProtocolSet>();
    }

    VirtualAuthenticatorOptionsBuilder<STATE | kTransportSet>& SetTransport(::headless::web_authn::AuthenticatorTransport value) {
      static_assert(!(STATE & kTransportSet), "property transport should not have already been set");
      result_->SetTransport(value);
      return CastState<kTransportSet>();
    }

    VirtualAuthenticatorOptionsBuilder<STATE>& SetHasResidentKey(bool value) {
      result_->SetHasResidentKey(value);
      return *this;
    }

    VirtualAuthenticatorOptionsBuilder<STATE>& SetHasUserVerification(bool value) {
      result_->SetHasUserVerification(value);
      return *this;
    }

    VirtualAuthenticatorOptionsBuilder<STATE>& SetAutomaticPresenceSimulation(bool value) {
      result_->SetAutomaticPresenceSimulation(value);
      return *this;
    }

    VirtualAuthenticatorOptionsBuilder<STATE>& SetIsUserVerified(bool value) {
      result_->SetIsUserVerified(value);
      return *this;
    }

    std::unique_ptr<VirtualAuthenticatorOptions> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class VirtualAuthenticatorOptions;
    VirtualAuthenticatorOptionsBuilder() : result_(new VirtualAuthenticatorOptions()) { }

    template<int STEP> VirtualAuthenticatorOptionsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<VirtualAuthenticatorOptionsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<VirtualAuthenticatorOptions> result_;
  };

  static VirtualAuthenticatorOptionsBuilder<0> Builder() {
    return VirtualAuthenticatorOptionsBuilder<0>();
  }

 private:
  VirtualAuthenticatorOptions() { }

  ::headless::web_authn::AuthenticatorProtocol protocol_;
  ::headless::web_authn::AuthenticatorTransport transport_;
  base::Optional<bool> has_resident_key_;
  base::Optional<bool> has_user_verification_;
  base::Optional<bool> automatic_presence_simulation_;
  base::Optional<bool> is_user_verified_;

  DISALLOW_COPY_AND_ASSIGN(VirtualAuthenticatorOptions);
};


class HEADLESS_EXPORT Credential {
 public:
  static std::unique_ptr<Credential> Parse(const base::Value& value, ErrorReporter* errors);
  ~Credential() { }

  protocol::Binary GetCredentialId() const { return credential_id_; }
  void SetCredentialId(const protocol::Binary& value) { credential_id_ = value; }

  bool GetIsResidentCredential() const { return is_resident_credential_; }
  void SetIsResidentCredential(bool value) { is_resident_credential_ = value; }

  // Relying Party ID the credential is scoped to. Must be set when adding a
  // credential.
  bool HasRpId() const { return !!rp_id_; }
  std::string GetRpId() const { DCHECK(HasRpId()); return rp_id_.value(); }
  void SetRpId(const std::string& value) { rp_id_ = value; }

  // The ECDSA P-256 private key in PKCS#8 format.
  protocol::Binary GetPrivateKey() const { return private_key_; }
  void SetPrivateKey(const protocol::Binary& value) { private_key_ = value; }

  // An opaque byte sequence with a maximum size of 64 bytes mapping the
  // credential to a specific user.
  bool HasUserHandle() const { return !!user_handle_; }
  protocol::Binary GetUserHandle() const { DCHECK(HasUserHandle()); return user_handle_.value(); }
  void SetUserHandle(const protocol::Binary& value) { user_handle_ = value; }

  // Signature counter. This is incremented by one for each successful
  // assertion.
  // See https://w3c.github.io/webauthn/#signature-counter
  int GetSignCount() const { return sign_count_; }
  void SetSignCount(int value) { sign_count_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Credential> Clone() const;

  template<int STATE>
  class CredentialBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCredentialIdSet = 1 << 1,
    kIsResidentCredentialSet = 1 << 2,
    kPrivateKeySet = 1 << 3,
    kSignCountSet = 1 << 4,
      kAllRequiredFieldsSet = (kCredentialIdSet | kIsResidentCredentialSet | kPrivateKeySet | kSignCountSet | 0)
    };

    CredentialBuilder<STATE | kCredentialIdSet>& SetCredentialId(const protocol::Binary& value) {
      static_assert(!(STATE & kCredentialIdSet), "property credentialId should not have already been set");
      result_->SetCredentialId(value);
      return CastState<kCredentialIdSet>();
    }

    CredentialBuilder<STATE | kIsResidentCredentialSet>& SetIsResidentCredential(bool value) {
      static_assert(!(STATE & kIsResidentCredentialSet), "property isResidentCredential should not have already been set");
      result_->SetIsResidentCredential(value);
      return CastState<kIsResidentCredentialSet>();
    }

    CredentialBuilder<STATE>& SetRpId(const std::string& value) {
      result_->SetRpId(value);
      return *this;
    }

    CredentialBuilder<STATE | kPrivateKeySet>& SetPrivateKey(const protocol::Binary& value) {
      static_assert(!(STATE & kPrivateKeySet), "property privateKey should not have already been set");
      result_->SetPrivateKey(value);
      return CastState<kPrivateKeySet>();
    }

    CredentialBuilder<STATE>& SetUserHandle(const protocol::Binary& value) {
      result_->SetUserHandle(value);
      return *this;
    }

    CredentialBuilder<STATE | kSignCountSet>& SetSignCount(int value) {
      static_assert(!(STATE & kSignCountSet), "property signCount should not have already been set");
      result_->SetSignCount(value);
      return CastState<kSignCountSet>();
    }

    std::unique_ptr<Credential> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Credential;
    CredentialBuilder() : result_(new Credential()) { }

    template<int STEP> CredentialBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CredentialBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Credential> result_;
  };

  static CredentialBuilder<0> Builder() {
    return CredentialBuilder<0>();
  }

 private:
  Credential() { }

  protocol::Binary credential_id_;
  bool is_resident_credential_;
  base::Optional<std::string> rp_id_;
  protocol::Binary private_key_;
  base::Optional<protocol::Binary> user_handle_;
  int sign_count_;

  DISALLOW_COPY_AND_ASSIGN(Credential);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the AddVirtualAuthenticator command.
class HEADLESS_EXPORT AddVirtualAuthenticatorParams {
 public:
  static std::unique_ptr<AddVirtualAuthenticatorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddVirtualAuthenticatorParams() { }

  const ::headless::web_authn::VirtualAuthenticatorOptions* GetOptions() const { return options_.get(); }
  void SetOptions(std::unique_ptr<::headless::web_authn::VirtualAuthenticatorOptions> value) { options_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddVirtualAuthenticatorParams> Clone() const;

  template<int STATE>
  class AddVirtualAuthenticatorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOptionsSet = 1 << 1,
      kAllRequiredFieldsSet = (kOptionsSet | 0)
    };

    AddVirtualAuthenticatorParamsBuilder<STATE | kOptionsSet>& SetOptions(std::unique_ptr<::headless::web_authn::VirtualAuthenticatorOptions> value) {
      static_assert(!(STATE & kOptionsSet), "property options should not have already been set");
      result_->SetOptions(std::move(value));
      return CastState<kOptionsSet>();
    }

    std::unique_ptr<AddVirtualAuthenticatorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddVirtualAuthenticatorParams;
    AddVirtualAuthenticatorParamsBuilder() : result_(new AddVirtualAuthenticatorParams()) { }

    template<int STEP> AddVirtualAuthenticatorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddVirtualAuthenticatorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddVirtualAuthenticatorParams> result_;
  };

  static AddVirtualAuthenticatorParamsBuilder<0> Builder() {
    return AddVirtualAuthenticatorParamsBuilder<0>();
  }

 private:
  AddVirtualAuthenticatorParams() { }

  std::unique_ptr<::headless::web_authn::VirtualAuthenticatorOptions> options_;

  DISALLOW_COPY_AND_ASSIGN(AddVirtualAuthenticatorParams);
};


// Result for the AddVirtualAuthenticator command.
class HEADLESS_EXPORT AddVirtualAuthenticatorResult {
 public:
  static std::unique_ptr<AddVirtualAuthenticatorResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddVirtualAuthenticatorResult() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddVirtualAuthenticatorResult> Clone() const;

  template<int STATE>
  class AddVirtualAuthenticatorResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | 0)
    };

    AddVirtualAuthenticatorResultBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    std::unique_ptr<AddVirtualAuthenticatorResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddVirtualAuthenticatorResult;
    AddVirtualAuthenticatorResultBuilder() : result_(new AddVirtualAuthenticatorResult()) { }

    template<int STEP> AddVirtualAuthenticatorResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddVirtualAuthenticatorResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddVirtualAuthenticatorResult> result_;
  };

  static AddVirtualAuthenticatorResultBuilder<0> Builder() {
    return AddVirtualAuthenticatorResultBuilder<0>();
  }

 private:
  AddVirtualAuthenticatorResult() { }

  std::string authenticator_id_;

  DISALLOW_COPY_AND_ASSIGN(AddVirtualAuthenticatorResult);
};


// Parameters for the RemoveVirtualAuthenticator command.
class HEADLESS_EXPORT RemoveVirtualAuthenticatorParams {
 public:
  static std::unique_ptr<RemoveVirtualAuthenticatorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveVirtualAuthenticatorParams() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveVirtualAuthenticatorParams> Clone() const;

  template<int STATE>
  class RemoveVirtualAuthenticatorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | 0)
    };

    RemoveVirtualAuthenticatorParamsBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    std::unique_ptr<RemoveVirtualAuthenticatorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveVirtualAuthenticatorParams;
    RemoveVirtualAuthenticatorParamsBuilder() : result_(new RemoveVirtualAuthenticatorParams()) { }

    template<int STEP> RemoveVirtualAuthenticatorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveVirtualAuthenticatorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveVirtualAuthenticatorParams> result_;
  };

  static RemoveVirtualAuthenticatorParamsBuilder<0> Builder() {
    return RemoveVirtualAuthenticatorParamsBuilder<0>();
  }

 private:
  RemoveVirtualAuthenticatorParams() { }

  std::string authenticator_id_;

  DISALLOW_COPY_AND_ASSIGN(RemoveVirtualAuthenticatorParams);
};


// Result for the RemoveVirtualAuthenticator command.
class HEADLESS_EXPORT RemoveVirtualAuthenticatorResult {
 public:
  static std::unique_ptr<RemoveVirtualAuthenticatorResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveVirtualAuthenticatorResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveVirtualAuthenticatorResult> Clone() const;

  template<int STATE>
  class RemoveVirtualAuthenticatorResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RemoveVirtualAuthenticatorResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveVirtualAuthenticatorResult;
    RemoveVirtualAuthenticatorResultBuilder() : result_(new RemoveVirtualAuthenticatorResult()) { }

    template<int STEP> RemoveVirtualAuthenticatorResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveVirtualAuthenticatorResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveVirtualAuthenticatorResult> result_;
  };

  static RemoveVirtualAuthenticatorResultBuilder<0> Builder() {
    return RemoveVirtualAuthenticatorResultBuilder<0>();
  }

 private:
  RemoveVirtualAuthenticatorResult() { }


  DISALLOW_COPY_AND_ASSIGN(RemoveVirtualAuthenticatorResult);
};


// Parameters for the AddCredential command.
class HEADLESS_EXPORT AddCredentialParams {
 public:
  static std::unique_ptr<AddCredentialParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddCredentialParams() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  const ::headless::web_authn::Credential* GetCredential() const { return credential_.get(); }
  void SetCredential(std::unique_ptr<::headless::web_authn::Credential> value) { credential_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddCredentialParams> Clone() const;

  template<int STATE>
  class AddCredentialParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
    kCredentialSet = 1 << 2,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | kCredentialSet | 0)
    };

    AddCredentialParamsBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    AddCredentialParamsBuilder<STATE | kCredentialSet>& SetCredential(std::unique_ptr<::headless::web_authn::Credential> value) {
      static_assert(!(STATE & kCredentialSet), "property credential should not have already been set");
      result_->SetCredential(std::move(value));
      return CastState<kCredentialSet>();
    }

    std::unique_ptr<AddCredentialParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddCredentialParams;
    AddCredentialParamsBuilder() : result_(new AddCredentialParams()) { }

    template<int STEP> AddCredentialParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddCredentialParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddCredentialParams> result_;
  };

  static AddCredentialParamsBuilder<0> Builder() {
    return AddCredentialParamsBuilder<0>();
  }

 private:
  AddCredentialParams() { }

  std::string authenticator_id_;
  std::unique_ptr<::headless::web_authn::Credential> credential_;

  DISALLOW_COPY_AND_ASSIGN(AddCredentialParams);
};


// Result for the AddCredential command.
class HEADLESS_EXPORT AddCredentialResult {
 public:
  static std::unique_ptr<AddCredentialResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddCredentialResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddCredentialResult> Clone() const;

  template<int STATE>
  class AddCredentialResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<AddCredentialResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddCredentialResult;
    AddCredentialResultBuilder() : result_(new AddCredentialResult()) { }

    template<int STEP> AddCredentialResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddCredentialResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddCredentialResult> result_;
  };

  static AddCredentialResultBuilder<0> Builder() {
    return AddCredentialResultBuilder<0>();
  }

 private:
  AddCredentialResult() { }


  DISALLOW_COPY_AND_ASSIGN(AddCredentialResult);
};


// Parameters for the GetCredential command.
class HEADLESS_EXPORT GetCredentialParams {
 public:
  static std::unique_ptr<GetCredentialParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCredentialParams() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  protocol::Binary GetCredentialId() const { return credential_id_; }
  void SetCredentialId(const protocol::Binary& value) { credential_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCredentialParams> Clone() const;

  template<int STATE>
  class GetCredentialParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
    kCredentialIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | kCredentialIdSet | 0)
    };

    GetCredentialParamsBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    GetCredentialParamsBuilder<STATE | kCredentialIdSet>& SetCredentialId(const protocol::Binary& value) {
      static_assert(!(STATE & kCredentialIdSet), "property credentialId should not have already been set");
      result_->SetCredentialId(value);
      return CastState<kCredentialIdSet>();
    }

    std::unique_ptr<GetCredentialParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCredentialParams;
    GetCredentialParamsBuilder() : result_(new GetCredentialParams()) { }

    template<int STEP> GetCredentialParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCredentialParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCredentialParams> result_;
  };

  static GetCredentialParamsBuilder<0> Builder() {
    return GetCredentialParamsBuilder<0>();
  }

 private:
  GetCredentialParams() { }

  std::string authenticator_id_;
  protocol::Binary credential_id_;

  DISALLOW_COPY_AND_ASSIGN(GetCredentialParams);
};


// Result for the GetCredential command.
class HEADLESS_EXPORT GetCredentialResult {
 public:
  static std::unique_ptr<GetCredentialResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCredentialResult() { }

  const ::headless::web_authn::Credential* GetCredential() const { return credential_.get(); }
  void SetCredential(std::unique_ptr<::headless::web_authn::Credential> value) { credential_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCredentialResult> Clone() const;

  template<int STATE>
  class GetCredentialResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCredentialSet = 1 << 1,
      kAllRequiredFieldsSet = (kCredentialSet | 0)
    };

    GetCredentialResultBuilder<STATE | kCredentialSet>& SetCredential(std::unique_ptr<::headless::web_authn::Credential> value) {
      static_assert(!(STATE & kCredentialSet), "property credential should not have already been set");
      result_->SetCredential(std::move(value));
      return CastState<kCredentialSet>();
    }

    std::unique_ptr<GetCredentialResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCredentialResult;
    GetCredentialResultBuilder() : result_(new GetCredentialResult()) { }

    template<int STEP> GetCredentialResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCredentialResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCredentialResult> result_;
  };

  static GetCredentialResultBuilder<0> Builder() {
    return GetCredentialResultBuilder<0>();
  }

 private:
  GetCredentialResult() { }

  std::unique_ptr<::headless::web_authn::Credential> credential_;

  DISALLOW_COPY_AND_ASSIGN(GetCredentialResult);
};


// Parameters for the GetCredentials command.
class HEADLESS_EXPORT GetCredentialsParams {
 public:
  static std::unique_ptr<GetCredentialsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCredentialsParams() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCredentialsParams> Clone() const;

  template<int STATE>
  class GetCredentialsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | 0)
    };

    GetCredentialsParamsBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    std::unique_ptr<GetCredentialsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCredentialsParams;
    GetCredentialsParamsBuilder() : result_(new GetCredentialsParams()) { }

    template<int STEP> GetCredentialsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCredentialsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCredentialsParams> result_;
  };

  static GetCredentialsParamsBuilder<0> Builder() {
    return GetCredentialsParamsBuilder<0>();
  }

 private:
  GetCredentialsParams() { }

  std::string authenticator_id_;

  DISALLOW_COPY_AND_ASSIGN(GetCredentialsParams);
};


// Result for the GetCredentials command.
class HEADLESS_EXPORT GetCredentialsResult {
 public:
  static std::unique_ptr<GetCredentialsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCredentialsResult() { }

  const std::vector<std::unique_ptr<::headless::web_authn::Credential>>* GetCredentials() const { return &credentials_; }
  void SetCredentials(std::vector<std::unique_ptr<::headless::web_authn::Credential>> value) { credentials_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCredentialsResult> Clone() const;

  template<int STATE>
  class GetCredentialsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCredentialsSet = 1 << 1,
      kAllRequiredFieldsSet = (kCredentialsSet | 0)
    };

    GetCredentialsResultBuilder<STATE | kCredentialsSet>& SetCredentials(std::vector<std::unique_ptr<::headless::web_authn::Credential>> value) {
      static_assert(!(STATE & kCredentialsSet), "property credentials should not have already been set");
      result_->SetCredentials(std::move(value));
      return CastState<kCredentialsSet>();
    }

    std::unique_ptr<GetCredentialsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCredentialsResult;
    GetCredentialsResultBuilder() : result_(new GetCredentialsResult()) { }

    template<int STEP> GetCredentialsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCredentialsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCredentialsResult> result_;
  };

  static GetCredentialsResultBuilder<0> Builder() {
    return GetCredentialsResultBuilder<0>();
  }

 private:
  GetCredentialsResult() { }

  std::vector<std::unique_ptr<::headless::web_authn::Credential>> credentials_;

  DISALLOW_COPY_AND_ASSIGN(GetCredentialsResult);
};


// Parameters for the RemoveCredential command.
class HEADLESS_EXPORT RemoveCredentialParams {
 public:
  static std::unique_ptr<RemoveCredentialParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveCredentialParams() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  protocol::Binary GetCredentialId() const { return credential_id_; }
  void SetCredentialId(const protocol::Binary& value) { credential_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveCredentialParams> Clone() const;

  template<int STATE>
  class RemoveCredentialParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
    kCredentialIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | kCredentialIdSet | 0)
    };

    RemoveCredentialParamsBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    RemoveCredentialParamsBuilder<STATE | kCredentialIdSet>& SetCredentialId(const protocol::Binary& value) {
      static_assert(!(STATE & kCredentialIdSet), "property credentialId should not have already been set");
      result_->SetCredentialId(value);
      return CastState<kCredentialIdSet>();
    }

    std::unique_ptr<RemoveCredentialParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveCredentialParams;
    RemoveCredentialParamsBuilder() : result_(new RemoveCredentialParams()) { }

    template<int STEP> RemoveCredentialParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveCredentialParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveCredentialParams> result_;
  };

  static RemoveCredentialParamsBuilder<0> Builder() {
    return RemoveCredentialParamsBuilder<0>();
  }

 private:
  RemoveCredentialParams() { }

  std::string authenticator_id_;
  protocol::Binary credential_id_;

  DISALLOW_COPY_AND_ASSIGN(RemoveCredentialParams);
};


// Result for the RemoveCredential command.
class HEADLESS_EXPORT RemoveCredentialResult {
 public:
  static std::unique_ptr<RemoveCredentialResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveCredentialResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveCredentialResult> Clone() const;

  template<int STATE>
  class RemoveCredentialResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RemoveCredentialResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveCredentialResult;
    RemoveCredentialResultBuilder() : result_(new RemoveCredentialResult()) { }

    template<int STEP> RemoveCredentialResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveCredentialResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveCredentialResult> result_;
  };

  static RemoveCredentialResultBuilder<0> Builder() {
    return RemoveCredentialResultBuilder<0>();
  }

 private:
  RemoveCredentialResult() { }


  DISALLOW_COPY_AND_ASSIGN(RemoveCredentialResult);
};


// Parameters for the ClearCredentials command.
class HEADLESS_EXPORT ClearCredentialsParams {
 public:
  static std::unique_ptr<ClearCredentialsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearCredentialsParams() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearCredentialsParams> Clone() const;

  template<int STATE>
  class ClearCredentialsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | 0)
    };

    ClearCredentialsParamsBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    std::unique_ptr<ClearCredentialsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearCredentialsParams;
    ClearCredentialsParamsBuilder() : result_(new ClearCredentialsParams()) { }

    template<int STEP> ClearCredentialsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearCredentialsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearCredentialsParams> result_;
  };

  static ClearCredentialsParamsBuilder<0> Builder() {
    return ClearCredentialsParamsBuilder<0>();
  }

 private:
  ClearCredentialsParams() { }

  std::string authenticator_id_;

  DISALLOW_COPY_AND_ASSIGN(ClearCredentialsParams);
};


// Result for the ClearCredentials command.
class HEADLESS_EXPORT ClearCredentialsResult {
 public:
  static std::unique_ptr<ClearCredentialsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearCredentialsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearCredentialsResult> Clone() const;

  template<int STATE>
  class ClearCredentialsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearCredentialsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearCredentialsResult;
    ClearCredentialsResultBuilder() : result_(new ClearCredentialsResult()) { }

    template<int STEP> ClearCredentialsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearCredentialsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearCredentialsResult> result_;
  };

  static ClearCredentialsResultBuilder<0> Builder() {
    return ClearCredentialsResultBuilder<0>();
  }

 private:
  ClearCredentialsResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearCredentialsResult);
};


// Parameters for the SetUserVerified command.
class HEADLESS_EXPORT SetUserVerifiedParams {
 public:
  static std::unique_ptr<SetUserVerifiedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetUserVerifiedParams() { }

  std::string GetAuthenticatorId() const { return authenticator_id_; }
  void SetAuthenticatorId(const std::string& value) { authenticator_id_ = value; }

  bool GetIsUserVerified() const { return is_user_verified_; }
  void SetIsUserVerified(bool value) { is_user_verified_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetUserVerifiedParams> Clone() const;

  template<int STATE>
  class SetUserVerifiedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAuthenticatorIdSet = 1 << 1,
    kIsUserVerifiedSet = 1 << 2,
      kAllRequiredFieldsSet = (kAuthenticatorIdSet | kIsUserVerifiedSet | 0)
    };

    SetUserVerifiedParamsBuilder<STATE | kAuthenticatorIdSet>& SetAuthenticatorId(const std::string& value) {
      static_assert(!(STATE & kAuthenticatorIdSet), "property authenticatorId should not have already been set");
      result_->SetAuthenticatorId(value);
      return CastState<kAuthenticatorIdSet>();
    }

    SetUserVerifiedParamsBuilder<STATE | kIsUserVerifiedSet>& SetIsUserVerified(bool value) {
      static_assert(!(STATE & kIsUserVerifiedSet), "property isUserVerified should not have already been set");
      result_->SetIsUserVerified(value);
      return CastState<kIsUserVerifiedSet>();
    }

    std::unique_ptr<SetUserVerifiedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetUserVerifiedParams;
    SetUserVerifiedParamsBuilder() : result_(new SetUserVerifiedParams()) { }

    template<int STEP> SetUserVerifiedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetUserVerifiedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetUserVerifiedParams> result_;
  };

  static SetUserVerifiedParamsBuilder<0> Builder() {
    return SetUserVerifiedParamsBuilder<0>();
  }

 private:
  SetUserVerifiedParams() { }

  std::string authenticator_id_;
  bool is_user_verified_;

  DISALLOW_COPY_AND_ASSIGN(SetUserVerifiedParams);
};


// Result for the SetUserVerified command.
class HEADLESS_EXPORT SetUserVerifiedResult {
 public:
  static std::unique_ptr<SetUserVerifiedResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetUserVerifiedResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetUserVerifiedResult> Clone() const;

  template<int STATE>
  class SetUserVerifiedResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetUserVerifiedResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetUserVerifiedResult;
    SetUserVerifiedResultBuilder() : result_(new SetUserVerifiedResult()) { }

    template<int STEP> SetUserVerifiedResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetUserVerifiedResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetUserVerifiedResult> result_;
  };

  static SetUserVerifiedResultBuilder<0> Builder() {
    return SetUserVerifiedResultBuilder<0>();
  }

 private:
  SetUserVerifiedResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetUserVerifiedResult);
};


}  // namespace web_authn

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_WEB_AUTHN_H_
