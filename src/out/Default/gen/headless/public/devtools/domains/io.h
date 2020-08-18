// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_IO_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_IO_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace io {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

// Input/Output operations for streams produced by DevTools.
class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Close the stream, discard any temporary backing storage.
  void Close(std::unique_ptr<CloseParams> params, base::OnceCallback<void(std::unique_ptr<CloseResult>)> callback = base::OnceCallback<void(std::unique_ptr<CloseResult>)>());
  void Close(const std::string& handle, base::OnceClosure callback = base::OnceClosure());
  void Close(std::unique_ptr<CloseParams> params, base::OnceClosure callback);

  // Read a chunk of the stream
  void Read(std::unique_ptr<ReadParams> params, base::OnceCallback<void(std::unique_ptr<ReadResult>)> callback = base::OnceCallback<void(std::unique_ptr<ReadResult>)>());
  void Read(const std::string& handle, base::OnceCallback<void(std::unique_ptr<ReadResult>)> callback = base::OnceCallback<void(std::unique_ptr<ReadResult>)>());

  // Return UUID of Blob object specified by a remote object id.
  void ResolveBlob(std::unique_ptr<ResolveBlobParams> params, base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)>());
  void ResolveBlob(const std::string& object_id, base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)> callback = base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)>());

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleCloseResponse(base::OnceCallback<void(std::unique_ptr<CloseResult>)> callback, const base::Value& response);
  static void HandleReadResponse(base::OnceCallback<void(std::unique_ptr<ReadResult>)> callback, const base::Value& response);
  static void HandleResolveBlobResponse(base::OnceCallback<void(std::unique_ptr<ResolveBlobResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();



 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace io
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_IO_H_
