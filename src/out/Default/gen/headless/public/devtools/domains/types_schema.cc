// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_schema.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_schema.h"

namespace headless {

namespace schema {

std::unique_ptr<Domain> Domain::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Domain");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Domain> result(new Domain());
  errors->Push();
  errors->SetName("Domain");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* version_value = value.FindKey("version");
  if (version_value) {
    errors->SetName("version");
    result->version_ = internal::FromValue<std::string>::Parse(*version_value, errors);
  } else {
    errors->AddError("required property missing: version");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Domain::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("version", internal::ToValue(version_));
  return std::move(result);
}

std::unique_ptr<Domain> Domain::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Domain> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDomainsParams> GetDomainsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDomainsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDomainsParams> result(new GetDomainsParams());
  errors->Push();
  errors->SetName("GetDomainsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDomainsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetDomainsParams> GetDomainsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDomainsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDomainsResult> GetDomainsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDomainsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDomainsResult> result(new GetDomainsResult());
  errors->Push();
  errors->SetName("GetDomainsResult");
  const base::Value* domains_value = value.FindKey("domains");
  if (domains_value) {
    errors->SetName("domains");
    result->domains_ = internal::FromValue<std::vector<std::unique_ptr<::headless::schema::Domain>>>::Parse(*domains_value, errors);
  } else {
    errors->AddError("required property missing: domains");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDomainsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("domains", internal::ToValue(domains_));
  return std::move(result);
}

std::unique_ptr<GetDomainsResult> GetDomainsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDomainsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace schema
}  // namespace headless
