// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_SNAPSHOT_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_SNAPSHOT_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_css.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_dom_debugger.h"
#include "headless/public/devtools/domains/types_dom_snapshot.h"
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
namespace dom_snapshot {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

// This domain facilitates obtaining document snapshots with DOM, layout, and style information.
class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleGetSnapshotResponse(base::OnceCallback<void(std::unique_ptr<GetSnapshotResult>)> callback, const base::Value& response);
  static void HandleCaptureSnapshotResponse(base::OnceCallback<void(std::unique_ptr<CaptureSnapshotResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // Disables DOM snapshot agent for the given page.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables DOM snapshot agent for the given page.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Returns a document snapshot, including the full DOM tree of the root node (including iframes,
  // template contents, and imported documents) in a flattened array, as well as layout and
  // white-listed computed style information for the nodes. Shadow DOM in the returned DOM tree is
  // flattened.
  void GetSnapshot(std::unique_ptr<GetSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<GetSnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetSnapshotResult>)>());

  // Returns a document snapshot, including the full DOM tree of the root node (including iframes,
  // template contents, and imported documents) in a flattened array, as well as layout and
  // white-listed computed style information for the nodes. Shadow DOM in the returned DOM tree is
  // flattened.
  void CaptureSnapshot(std::unique_ptr<CaptureSnapshotParams> params, base::OnceCallback<void(std::unique_ptr<CaptureSnapshotResult>)> callback = base::OnceCallback<void(std::unique_ptr<CaptureSnapshotResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace dom_snapshot
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_SNAPSHOT_H_
