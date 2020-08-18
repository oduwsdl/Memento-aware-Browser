// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_web_authn.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_web_authn.h"

namespace headless {

namespace web_authn {

std::unique_ptr<VirtualAuthenticatorOptions> VirtualAuthenticatorOptions::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("VirtualAuthenticatorOptions");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<VirtualAuthenticatorOptions> result(new VirtualAuthenticatorOptions());
  errors->Push();
  errors->SetName("VirtualAuthenticatorOptions");
  const base::Value* protocol_value = value.FindKey("protocol");
  if (protocol_value) {
    errors->SetName("protocol");
    result->protocol_ = internal::FromValue<::headless::web_authn::AuthenticatorProtocol>::Parse(*protocol_value, errors);
  } else {
    errors->AddError("required property missing: protocol");
  }
  const base::Value* transport_value = value.FindKey("transport");
  if (transport_value) {
    errors->SetName("transport");
    result->transport_ = internal::FromValue<::headless::web_authn::AuthenticatorTransport>::Parse(*transport_value, errors);
  } else {
    errors->AddError("required property missing: transport");
  }
  const base::Value* has_resident_key_value = value.FindKey("hasResidentKey");
  if (has_resident_key_value) {
    errors->SetName("hasResidentKey");
    result->has_resident_key_ = internal::FromValue<bool>::Parse(*has_resident_key_value, errors);
  }
  const base::Value* has_user_verification_value = value.FindKey("hasUserVerification");
  if (has_user_verification_value) {
    errors->SetName("hasUserVerification");
    result->has_user_verification_ = internal::FromValue<bool>::Parse(*has_user_verification_value, errors);
  }
  const base::Value* automatic_presence_simulation_value = value.FindKey("automaticPresenceSimulation");
  if (automatic_presence_simulation_value) {
    errors->SetName("automaticPresenceSimulation");
    result->automatic_presence_simulation_ = internal::FromValue<bool>::Parse(*automatic_presence_simulation_value, errors);
  }
  const base::Value* is_user_verified_value = value.FindKey("isUserVerified");
  if (is_user_verified_value) {
    errors->SetName("isUserVerified");
    result->is_user_verified_ = internal::FromValue<bool>::Parse(*is_user_verified_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> VirtualAuthenticatorOptions::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("protocol", internal::ToValue(protocol_));
  result->Set("transport", internal::ToValue(transport_));
  if (has_resident_key_)
    result->Set("hasResidentKey", internal::ToValue(has_resident_key_.value()));
  if (has_user_verification_)
    result->Set("hasUserVerification", internal::ToValue(has_user_verification_.value()));
  if (automatic_presence_simulation_)
    result->Set("automaticPresenceSimulation", internal::ToValue(automatic_presence_simulation_.value()));
  if (is_user_verified_)
    result->Set("isUserVerified", internal::ToValue(is_user_verified_.value()));
  return std::move(result);
}

std::unique_ptr<VirtualAuthenticatorOptions> VirtualAuthenticatorOptions::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<VirtualAuthenticatorOptions> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Credential> Credential::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Credential");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Credential> result(new Credential());
  errors->Push();
  errors->SetName("Credential");
  const base::Value* credential_id_value = value.FindKey("credentialId");
  if (credential_id_value) {
    errors->SetName("credentialId");
    result->credential_id_ = internal::FromValue<protocol::Binary>::Parse(*credential_id_value, errors);
  } else {
    errors->AddError("required property missing: credentialId");
  }
  const base::Value* is_resident_credential_value = value.FindKey("isResidentCredential");
  if (is_resident_credential_value) {
    errors->SetName("isResidentCredential");
    result->is_resident_credential_ = internal::FromValue<bool>::Parse(*is_resident_credential_value, errors);
  } else {
    errors->AddError("required property missing: isResidentCredential");
  }
  const base::Value* rp_id_value = value.FindKey("rpId");
  if (rp_id_value) {
    errors->SetName("rpId");
    result->rp_id_ = internal::FromValue<std::string>::Parse(*rp_id_value, errors);
  }
  const base::Value* private_key_value = value.FindKey("privateKey");
  if (private_key_value) {
    errors->SetName("privateKey");
    result->private_key_ = internal::FromValue<protocol::Binary>::Parse(*private_key_value, errors);
  } else {
    errors->AddError("required property missing: privateKey");
  }
  const base::Value* user_handle_value = value.FindKey("userHandle");
  if (user_handle_value) {
    errors->SetName("userHandle");
    result->user_handle_ = internal::FromValue<protocol::Binary>::Parse(*user_handle_value, errors);
  }
  const base::Value* sign_count_value = value.FindKey("signCount");
  if (sign_count_value) {
    errors->SetName("signCount");
    result->sign_count_ = internal::FromValue<int>::Parse(*sign_count_value, errors);
  } else {
    errors->AddError("required property missing: signCount");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Credential::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("credentialId", internal::ToValue(credential_id_));
  result->Set("isResidentCredential", internal::ToValue(is_resident_credential_));
  if (rp_id_)
    result->Set("rpId", internal::ToValue(rp_id_.value()));
  result->Set("privateKey", internal::ToValue(private_key_));
  if (user_handle_)
    result->Set("userHandle", internal::ToValue(user_handle_.value()));
  result->Set("signCount", internal::ToValue(sign_count_));
  return std::move(result);
}

std::unique_ptr<Credential> Credential::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Credential> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddVirtualAuthenticatorParams> AddVirtualAuthenticatorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddVirtualAuthenticatorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddVirtualAuthenticatorParams> result(new AddVirtualAuthenticatorParams());
  errors->Push();
  errors->SetName("AddVirtualAuthenticatorParams");
  const base::Value* options_value = value.FindKey("options");
  if (options_value) {
    errors->SetName("options");
    result->options_ = internal::FromValue<::headless::web_authn::VirtualAuthenticatorOptions>::Parse(*options_value, errors);
  } else {
    errors->AddError("required property missing: options");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddVirtualAuthenticatorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("options", internal::ToValue(*options_));
  return std::move(result);
}

std::unique_ptr<AddVirtualAuthenticatorParams> AddVirtualAuthenticatorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddVirtualAuthenticatorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddVirtualAuthenticatorResult> AddVirtualAuthenticatorResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddVirtualAuthenticatorResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddVirtualAuthenticatorResult> result(new AddVirtualAuthenticatorResult());
  errors->Push();
  errors->SetName("AddVirtualAuthenticatorResult");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddVirtualAuthenticatorResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  return std::move(result);
}

std::unique_ptr<AddVirtualAuthenticatorResult> AddVirtualAuthenticatorResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddVirtualAuthenticatorResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveVirtualAuthenticatorParams> RemoveVirtualAuthenticatorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveVirtualAuthenticatorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveVirtualAuthenticatorParams> result(new RemoveVirtualAuthenticatorParams());
  errors->Push();
  errors->SetName("RemoveVirtualAuthenticatorParams");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveVirtualAuthenticatorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  return std::move(result);
}

std::unique_ptr<RemoveVirtualAuthenticatorParams> RemoveVirtualAuthenticatorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveVirtualAuthenticatorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveVirtualAuthenticatorResult> RemoveVirtualAuthenticatorResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveVirtualAuthenticatorResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveVirtualAuthenticatorResult> result(new RemoveVirtualAuthenticatorResult());
  errors->Push();
  errors->SetName("RemoveVirtualAuthenticatorResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveVirtualAuthenticatorResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveVirtualAuthenticatorResult> RemoveVirtualAuthenticatorResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveVirtualAuthenticatorResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddCredentialParams> AddCredentialParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddCredentialParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddCredentialParams> result(new AddCredentialParams());
  errors->Push();
  errors->SetName("AddCredentialParams");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  const base::Value* credential_value = value.FindKey("credential");
  if (credential_value) {
    errors->SetName("credential");
    result->credential_ = internal::FromValue<::headless::web_authn::Credential>::Parse(*credential_value, errors);
  } else {
    errors->AddError("required property missing: credential");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddCredentialParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  result->Set("credential", internal::ToValue(*credential_));
  return std::move(result);
}

std::unique_ptr<AddCredentialParams> AddCredentialParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddCredentialParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddCredentialResult> AddCredentialResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddCredentialResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddCredentialResult> result(new AddCredentialResult());
  errors->Push();
  errors->SetName("AddCredentialResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddCredentialResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<AddCredentialResult> AddCredentialResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddCredentialResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCredentialParams> GetCredentialParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCredentialParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCredentialParams> result(new GetCredentialParams());
  errors->Push();
  errors->SetName("GetCredentialParams");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  const base::Value* credential_id_value = value.FindKey("credentialId");
  if (credential_id_value) {
    errors->SetName("credentialId");
    result->credential_id_ = internal::FromValue<protocol::Binary>::Parse(*credential_id_value, errors);
  } else {
    errors->AddError("required property missing: credentialId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCredentialParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  result->Set("credentialId", internal::ToValue(credential_id_));
  return std::move(result);
}

std::unique_ptr<GetCredentialParams> GetCredentialParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCredentialParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCredentialResult> GetCredentialResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCredentialResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCredentialResult> result(new GetCredentialResult());
  errors->Push();
  errors->SetName("GetCredentialResult");
  const base::Value* credential_value = value.FindKey("credential");
  if (credential_value) {
    errors->SetName("credential");
    result->credential_ = internal::FromValue<::headless::web_authn::Credential>::Parse(*credential_value, errors);
  } else {
    errors->AddError("required property missing: credential");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCredentialResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("credential", internal::ToValue(*credential_));
  return std::move(result);
}

std::unique_ptr<GetCredentialResult> GetCredentialResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCredentialResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCredentialsParams> GetCredentialsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCredentialsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCredentialsParams> result(new GetCredentialsParams());
  errors->Push();
  errors->SetName("GetCredentialsParams");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCredentialsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  return std::move(result);
}

std::unique_ptr<GetCredentialsParams> GetCredentialsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCredentialsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCredentialsResult> GetCredentialsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCredentialsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCredentialsResult> result(new GetCredentialsResult());
  errors->Push();
  errors->SetName("GetCredentialsResult");
  const base::Value* credentials_value = value.FindKey("credentials");
  if (credentials_value) {
    errors->SetName("credentials");
    result->credentials_ = internal::FromValue<std::vector<std::unique_ptr<::headless::web_authn::Credential>>>::Parse(*credentials_value, errors);
  } else {
    errors->AddError("required property missing: credentials");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCredentialsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("credentials", internal::ToValue(credentials_));
  return std::move(result);
}

std::unique_ptr<GetCredentialsResult> GetCredentialsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCredentialsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveCredentialParams> RemoveCredentialParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveCredentialParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveCredentialParams> result(new RemoveCredentialParams());
  errors->Push();
  errors->SetName("RemoveCredentialParams");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  const base::Value* credential_id_value = value.FindKey("credentialId");
  if (credential_id_value) {
    errors->SetName("credentialId");
    result->credential_id_ = internal::FromValue<protocol::Binary>::Parse(*credential_id_value, errors);
  } else {
    errors->AddError("required property missing: credentialId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveCredentialParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  result->Set("credentialId", internal::ToValue(credential_id_));
  return std::move(result);
}

std::unique_ptr<RemoveCredentialParams> RemoveCredentialParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveCredentialParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveCredentialResult> RemoveCredentialResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveCredentialResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveCredentialResult> result(new RemoveCredentialResult());
  errors->Push();
  errors->SetName("RemoveCredentialResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveCredentialResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveCredentialResult> RemoveCredentialResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveCredentialResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearCredentialsParams> ClearCredentialsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearCredentialsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearCredentialsParams> result(new ClearCredentialsParams());
  errors->Push();
  errors->SetName("ClearCredentialsParams");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearCredentialsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  return std::move(result);
}

std::unique_ptr<ClearCredentialsParams> ClearCredentialsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearCredentialsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearCredentialsResult> ClearCredentialsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearCredentialsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearCredentialsResult> result(new ClearCredentialsResult());
  errors->Push();
  errors->SetName("ClearCredentialsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearCredentialsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearCredentialsResult> ClearCredentialsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearCredentialsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetUserVerifiedParams> SetUserVerifiedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetUserVerifiedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetUserVerifiedParams> result(new SetUserVerifiedParams());
  errors->Push();
  errors->SetName("SetUserVerifiedParams");
  const base::Value* authenticator_id_value = value.FindKey("authenticatorId");
  if (authenticator_id_value) {
    errors->SetName("authenticatorId");
    result->authenticator_id_ = internal::FromValue<std::string>::Parse(*authenticator_id_value, errors);
  } else {
    errors->AddError("required property missing: authenticatorId");
  }
  const base::Value* is_user_verified_value = value.FindKey("isUserVerified");
  if (is_user_verified_value) {
    errors->SetName("isUserVerified");
    result->is_user_verified_ = internal::FromValue<bool>::Parse(*is_user_verified_value, errors);
  } else {
    errors->AddError("required property missing: isUserVerified");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetUserVerifiedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("authenticatorId", internal::ToValue(authenticator_id_));
  result->Set("isUserVerified", internal::ToValue(is_user_verified_));
  return std::move(result);
}

std::unique_ptr<SetUserVerifiedParams> SetUserVerifiedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetUserVerifiedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetUserVerifiedResult> SetUserVerifiedResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetUserVerifiedResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetUserVerifiedResult> result(new SetUserVerifiedResult());
  errors->Push();
  errors->SetName("SetUserVerifiedResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetUserVerifiedResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetUserVerifiedResult> SetUserVerifiedResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetUserVerifiedResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace web_authn
}  // namespace headless
