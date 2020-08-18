// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/io.h"

#include "base/bind.h"
#include "headless/public/util/error_reporter.h"

namespace headless {

namespace io {

ExperimentalDomain* Domain::GetExperimental() {
  return static_cast<ExperimentalDomain*>(this);
}


void Domain::Close(std::unique_ptr<CloseParams> params, base::OnceCallback<void(std::unique_ptr<CloseResult>)> callback) {
  dispatcher_->SendMessage("IO.close", params->Serialize(), base::BindOnce(&Domain::HandleCloseResponse, std::move(callback)));
}

void Domain::Close(const std::string& handle, base::OnceClosure callback) {
  std::unique_ptr<CloseParams> params = CloseParams::Builder()
      .SetHandle(std::move(handle))
      .Build();
  dispatcher_->SendMessage("IO.close", params->Serialize(), std::move(callback));
}
void Domain::Close(std::unique_ptr<CloseParams> params, base::OnceClosure callback) {
  dispatcher_->SendMessage("IO.close", params->Serialize(), std::move(callback));
}
void Domain::Read(std::unique_ptr<ReadParams> params, base::OnceCallback<void(std::unique_ptr<ReadResult>)> callback) {
  dispatcher_->SendMessage("IO.read", params->Serialize(), base::BindOnce(&Domain::HandleReadResponse, std::move(callback)));
}

void Domain::Read(const std::string& handle, base::OnceCallback<void(std::unique_ptr<ReadResult>)> callback) {
  std::unique_ptr<ReadParams> params = ReadParams::Builder()
      .SetHandle(std::move(handle))
      .Build();
dispatcher_->SendMessage("IO.read", params->Serialize(), base::BindOnce(&Domain::HandleReadResponse, std::move(callback)));
}
void Domain::ResolveBlob(std::unique_ptr<ResolveBlobParams> params, base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)> callback) {
  dispatcher_->SendMessage("IO.resolveBlob", params->Serialize(), base::BindOnce(&Domain::HandleResolveBlobResponse, std::move(callback)));
}

void Domain::ResolveBlob(const std::string& object_id, base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)> callback) {
  std::unique_ptr<ResolveBlobParams> params = ResolveBlobParams::Builder()
      .SetObjectId(std::move(object_id))
      .Build();
dispatcher_->SendMessage("IO.resolveBlob", params->Serialize(), base::BindOnce(&Domain::HandleResolveBlobResponse, std::move(callback)));
}


// static
void Domain::HandleCloseResponse(base::OnceCallback<void(std::unique_ptr<CloseResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<CloseResult> result = CloseResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleReadResponse(base::OnceCallback<void(std::unique_ptr<ReadResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ReadResult> result = ReadResult::Parse(response, &errors);
  DCHECK(!errors.HasErrors()) << errors.ToString();
  std::move(callback).Run(std::move(result));
}

// static
void Domain::HandleResolveBlobResponse(base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)> callback, const base::Value& response) {
  if (callback.is_null())
    return;
  // This is an error response.
  if (response.is_none()) {
    std::move(callback).Run(nullptr);
    return;
  }
  ErrorReporter errors;
  std::unique_ptr<ResolveBlobResult> result = ResolveBlobResult::Parse(response, &errors);
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


}  // namespace io

} // namespace headless
