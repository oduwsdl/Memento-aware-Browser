// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_PERFORMANCE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_PERFORMANCE_H_

#include "base/values.h"

namespace headless {

namespace performance {
class Metric;
class DisableParams;
class DisableResult;
class EnableParams;
class EnableResult;
class SetTimeDomainParams;
class SetTimeDomainResult;
class GetMetricsParams;
class GetMetricsResult;
class MetricsParams;

enum class EnableTimeDomain {
  TIME_TICKS,
  THREAD_TICKS
};

enum class SetTimeDomainTimeDomain {
  TIME_TICKS,
  THREAD_TICKS
};

}  // namespace performance

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_PERFORMANCE_H_
