// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_ACCESSIBILITY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_ACCESSIBILITY_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_accessibility.h"
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
namespace accessibility {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

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
  static void HandleGetPartialAXTreeResponse(base::OnceCallback<void(std::unique_ptr<GetPartialAXTreeResult>)> callback, const base::Value& response);
  static void HandleGetFullAXTreeResponse(base::OnceCallback<void(std::unique_ptr<GetFullAXTreeResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // Disables the accessibility domain.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables the accessibility domain which causes `AXNodeId`s to remain consistent between method calls.
  // This turns on accessibility for the page, which can impact performance until accessibility is disabled.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  // Fetches the accessibility node and partial accessibility tree for this DOM node, if it exists.
  void GetPartialAXTree(std::unique_ptr<GetPartialAXTreeParams> params, base::OnceCallback<void(std::unique_ptr<GetPartialAXTreeResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetPartialAXTreeResult>)>());

  // Fetches the entire accessibility tree
  void GetFullAXTree(std::unique_ptr<GetFullAXTreeParams> params, base::OnceCallback<void(std::unique_ptr<GetFullAXTreeResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetFullAXTreeResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace accessibility
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_ACCESSIBILITY_H_
