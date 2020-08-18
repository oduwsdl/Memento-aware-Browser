// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_DOM_DEBUGGER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_DOM_DEBUGGER_H_

#include "base/values.h"

namespace headless {

namespace dom_debugger {
class EventListener;
class GetEventListenersParams;
class GetEventListenersResult;
class RemoveDOMBreakpointParams;
class RemoveDOMBreakpointResult;
class RemoveEventListenerBreakpointParams;
class RemoveEventListenerBreakpointResult;
class RemoveInstrumentationBreakpointParams;
class RemoveInstrumentationBreakpointResult;
class RemoveXHRBreakpointParams;
class RemoveXHRBreakpointResult;
class SetDOMBreakpointParams;
class SetDOMBreakpointResult;
class SetEventListenerBreakpointParams;
class SetEventListenerBreakpointResult;
class SetInstrumentationBreakpointParams;
class SetInstrumentationBreakpointResult;
class SetXHRBreakpointParams;
class SetXHRBreakpointResult;

enum class DOMBreakpointType {
  SUBTREE_MODIFIED,
  ATTRIBUTE_MODIFIED,
  NODE_REMOVED
};

}  // namespace dom_debugger

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_DOM_DEBUGGER_H_
