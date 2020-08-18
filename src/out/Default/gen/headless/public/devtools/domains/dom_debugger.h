// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_DEBUGGER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_DEBUGGER_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_dom_debugger.h"
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
namespace dom_debugger {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

// DOM debugging allows setting breakpoints on particular DOM operations and events. JavaScript
// execution will stop on these operations as if there was a regular breakpoint set.
class HEADLESS_EXPORT Domain {
 public:

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

  // Returns event listeners of the given object.
  void GetEventListeners(std::unique_ptr<GetEventListenersParams> params, base::OnceCallback<void(std::unique_ptr<GetEventListenersResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetEventListenersResult>)>());
  void GetEventListeners(const std::string& object_id, base::OnceCallback<void(std::unique_ptr<GetEventListenersResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetEventListenersResult>)>());

  // Removes DOM breakpoint that was set using `setDOMBreakpoint`.
  void RemoveDOMBreakpoint(std::unique_ptr<RemoveDOMBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<RemoveDOMBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveDOMBreakpointResult>)>());
  void RemoveDOMBreakpoint(int node_id, ::headless::dom_debugger::DOMBreakpointType type, base::OnceClosure callback = base::OnceClosure());
  void RemoveDOMBreakpoint(std::unique_ptr<RemoveDOMBreakpointParams> params, base::OnceClosure callback);

  // Removes breakpoint on particular DOM event.
  void RemoveEventListenerBreakpoint(std::unique_ptr<RemoveEventListenerBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<RemoveEventListenerBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveEventListenerBreakpointResult>)>());
  void RemoveEventListenerBreakpoint(const std::string& event_name, base::OnceClosure callback = base::OnceClosure());
  void RemoveEventListenerBreakpoint(std::unique_ptr<RemoveEventListenerBreakpointParams> params, base::OnceClosure callback);

  // Removes breakpoint from XMLHttpRequest.
  void RemoveXHRBreakpoint(std::unique_ptr<RemoveXHRBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<RemoveXHRBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveXHRBreakpointResult>)>());
  void RemoveXHRBreakpoint(const std::string& url, base::OnceClosure callback = base::OnceClosure());
  void RemoveXHRBreakpoint(std::unique_ptr<RemoveXHRBreakpointParams> params, base::OnceClosure callback);

  // Sets breakpoint on particular operation with DOM.
  void SetDOMBreakpoint(std::unique_ptr<SetDOMBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetDOMBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDOMBreakpointResult>)>());
  void SetDOMBreakpoint(int node_id, ::headless::dom_debugger::DOMBreakpointType type, base::OnceClosure callback = base::OnceClosure());
  void SetDOMBreakpoint(std::unique_ptr<SetDOMBreakpointParams> params, base::OnceClosure callback);

  // Sets breakpoint on particular DOM event.
  void SetEventListenerBreakpoint(std::unique_ptr<SetEventListenerBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetEventListenerBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetEventListenerBreakpointResult>)>());
  void SetEventListenerBreakpoint(const std::string& event_name, base::OnceClosure callback = base::OnceClosure());
  void SetEventListenerBreakpoint(std::unique_ptr<SetEventListenerBreakpointParams> params, base::OnceClosure callback);

  // Sets breakpoint on XMLHttpRequest.
  void SetXHRBreakpoint(std::unique_ptr<SetXHRBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetXHRBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetXHRBreakpointResult>)>());
  void SetXHRBreakpoint(const std::string& url, base::OnceClosure callback = base::OnceClosure());
  void SetXHRBreakpoint(std::unique_ptr<SetXHRBreakpointParams> params, base::OnceClosure callback);

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleGetEventListenersResponse(base::OnceCallback<void(std::unique_ptr<GetEventListenersResult>)> callback, const base::Value& response);
  static void HandleRemoveDOMBreakpointResponse(base::OnceCallback<void(std::unique_ptr<RemoveDOMBreakpointResult>)> callback, const base::Value& response);
  static void HandleRemoveEventListenerBreakpointResponse(base::OnceCallback<void(std::unique_ptr<RemoveEventListenerBreakpointResult>)> callback, const base::Value& response);
  static void HandleRemoveInstrumentationBreakpointResponse(base::OnceCallback<void(std::unique_ptr<RemoveInstrumentationBreakpointResult>)> callback, const base::Value& response);
  static void HandleRemoveXHRBreakpointResponse(base::OnceCallback<void(std::unique_ptr<RemoveXHRBreakpointResult>)> callback, const base::Value& response);
  static void HandleSetDOMBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetDOMBreakpointResult>)> callback, const base::Value& response);
  static void HandleSetEventListenerBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetEventListenerBreakpointResult>)> callback, const base::Value& response);
  static void HandleSetInstrumentationBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback, const base::Value& response);
  static void HandleSetXHRBreakpointResponse(base::OnceCallback<void(std::unique_ptr<SetXHRBreakpointResult>)> callback, const base::Value& response);


  internal::MessageDispatcher* dispatcher_;  // Not owned.

 private:
  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();


  // Removes breakpoint on particular native event.
  void RemoveInstrumentationBreakpoint(std::unique_ptr<RemoveInstrumentationBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<RemoveInstrumentationBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveInstrumentationBreakpointResult>)>());

  // Sets breakpoint on particular native event.
  void SetInstrumentationBreakpoint(std::unique_ptr<SetInstrumentationBreakpointParams> params, base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetInstrumentationBreakpointResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace dom_debugger
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_DEBUGGER_H_
