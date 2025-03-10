// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/page_load_metrics/browser/observers/back_forward_cache_page_load_metrics_observer.h"

#include "components/page_load_metrics/browser/page_load_metrics_util.h"

namespace internal {

const char kHistogramFirstPaintAfterBackForwardCacheRestore[] =
    "PageLoad.PaintTiming.NavigationToFirstPaint.AfterBackForwardCacheRestore";

}  // namespace internal

BackForwardCachePageLoadMetricsObserver::
    BackForwardCachePageLoadMetricsObserver() = default;

BackForwardCachePageLoadMetricsObserver::
    ~BackForwardCachePageLoadMetricsObserver() = default;

page_load_metrics::PageLoadMetricsObserver::ObservePolicy
BackForwardCachePageLoadMetricsObserver::OnEnterBackForwardCache(
    const page_load_metrics::mojom::PageLoadTiming& timing) {
  return CONTINUE_OBSERVING;
}

void BackForwardCachePageLoadMetricsObserver::
    OnFirstPaintAfterBackForwardCacheRestoreInPage(
        const page_load_metrics::mojom::BackForwardCacheTiming& timing) {
  auto first_paint = timing.first_paint_after_back_forward_cache_restore;
  DCHECK(!first_paint.is_zero());
  if (page_load_metrics::
          WasStartedInForegroundOptionalEventInForegroundAfterBackForwardCacheRestore(
              first_paint, GetDelegate())) {
    PAGE_LOAD_HISTOGRAM(
        internal::kHistogramFirstPaintAfterBackForwardCacheRestore,
        first_paint);
  }
}
