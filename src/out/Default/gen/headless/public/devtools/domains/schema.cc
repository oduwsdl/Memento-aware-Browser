// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/schema.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace schema {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}


void Domain::GetDomains(std::unique_ptr<GetDomainsParams> params, base::OnceCallback<void(std::unique_ptr<GetDomainsResult>)> callback) {
  dispatcher_->SendMessage("Schema.getDomains", params->Serialize(), base::BindOnce(&Domain::HandleGetDomainsResponse, std::move(callback)));
}

void Domain::GetDomains(base::OnceCallback<void(std::unique_ptr<GetDomainsResult>)> callback) {
  std::unique_ptr<GetDomainsParams> params = GetDomainsParams::Builder()
      .Build();
dispatcher_->SendMessage("Schema.getDomains", params->Serialize(), base::BindOnce(&Domain::HandleGetDomainsResponse, std::move(callback)));
}


// static
void Domain::HandleGetDomainsResponse(base::OnceCallback<void(std::unique_ptr<GetDomainsResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<GetDomainsResult> result = GetDomainsResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

Domain::Domain(internal::MessageDispatcher* dispatcher)
    : dispatcher_(dispatcher) {
}

Domain::~Domain() {}

ExperimentalDomain::ExperimentalDomain(internal::MessageDispatcher* dispatcher)
    : Domain(dispatcher) {}

ExperimentalDomain::~ExperimentalDomain() {}


}  // namespace schema

} // namespace headless
