// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_CONSOLE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_CONSOLE_H_

#include "base/values.h"

namespace headless {

namespace console {
class ConsoleMessage;
class ClearMessagesParams;
class ClearMessagesResult;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class MessageAddedParams;

enum class ConsoleMessageSource {
  XML,
  JAVASCRIPT,
  NETWORK,
  CONSOLE_API,
  STORAGE,
  APPCACHE,
  RENDERING,
  SECURITY,
  OTHER,
  DEPRECATION,
  WORKER
};

enum class ConsoleMessageLevel {
  LOG,
  WARNING,
  ERR,
  DEBUG,
  INFO
};

}  // namespace console

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_CONSOLE_H_
