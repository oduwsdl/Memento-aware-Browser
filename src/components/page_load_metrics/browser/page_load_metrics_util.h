// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAGE_LOAD_METRICS_BROWSER_PAGE_LOAD_METRICS_UTIL_H_
#define COMPONENTS_PAGE_LOAD_METRICS_BROWSER_PAGE_LOAD_METRICS_UTIL_H_

#include "base/metrics/histogram_macros.h"
#include "base/optional.h"
#include "base/time/time.h"
#include "components/page_load_metrics/browser/page_load_metrics_observer.h"
#include "components/page_load_metrics/common/page_load_metrics_util.h"
#include "third_party/blink/public/common/loader/loading_behavior_flag.h"

// Up to 10 minutes, with 100 buckets.
#define PAGE_LOAD_HISTOGRAM(name, sample)                           \
  UMA_HISTOGRAM_CUSTOM_TIMES(name, sample,                          \
                             base::TimeDelta::FromMilliseconds(10), \
                             base::TimeDelta::FromMinutes(10), 100)

// Up to 1 hour, with 100 buckets.
#define PAGE_LOAD_LONG_HISTOGRAM(name, sample)                      \
  UMA_HISTOGRAM_CUSTOM_TIMES(name, sample,                          \
                             base::TimeDelta::FromMilliseconds(10), \
                             base::TimeDelta::FromHours(1), 100)

// Records |bytes| to |histogram_name| in kilobytes (i.e., bytes / 1024).
#define PAGE_BYTES_HISTOGRAM(histogram_name, bytes) \
  UMA_HISTOGRAM_CUSTOM_COUNTS(                      \
      histogram_name, static_cast<int>((bytes) / 1024), 1, 500 * 1024, 50)

#define PAGE_RESOURCE_COUNT_HISTOGRAM UMA_HISTOGRAM_COUNTS_10000

namespace page_load_metrics {

// Reasons a page load can be aborted.
enum PageAbortReason {
  // Represents no abort.
  ABORT_NONE,

  // The page was reloaded, possibly by the user.
  ABORT_RELOAD,

  // The page was navigated away from, via a back or forward navigation.
  ABORT_FORWARD_BACK,

  // If the page load is replaced by a new navigation. This includes link
  // clicks, typing in the omnibox (not a reload), and form submissions.
  ABORT_NEW_NAVIGATION,

  // The page load was stopped (e.g. the user presses the stop X button).
  ABORT_STOP,

  // Page load ended due to closing the tab or browser.
  ABORT_CLOSE,

  // The page load was backgrounded, e.g. the browser was minimized or the user
  // switched tabs. Note that the same page may be foregrounded in the future,
  // so this is not a 'terminal' abort type.
  ABORT_BACKGROUND,

  // We don't know why the page load ended. This is the value we assign to a
  // terminated provisional load if the only signal we get is the load finished
  // without committing, either without error or with net::ERR_ABORTED.
  ABORT_OTHER
};

// Information related to a page load abort.
struct PageAbortInfo {
  PageAbortInfo()
      : reason(ABORT_NONE),
        user_initiated_info(UserInitiatedInfo::NotUserInitiated()) {}
  PageAbortInfo(PageAbortReason reason,
                UserInitiatedInfo user_initiated_info,
                base::TimeDelta time_to_abort)
      : reason(reason),
        user_initiated_info(user_initiated_info),
        time_to_abort(time_to_abort) {}

  // The reason / cause for the abort.
  const PageAbortReason reason;

  // The fields below are only valid if reason != ABORT_NONE.

  // Information about whether the abort was initiated by a user.
  const UserInitiatedInfo user_initiated_info;

  // The time from navigation start to the time the page load was aborted.
  const base::TimeDelta time_to_abort;
};

// Returns true if:
// - We have timing information for the event.
// - The page load started while the page was in the foreground.
// - The event occurred prior to the page being moved to the background.
// When a page is backgrounded, some events (e.g. paint) are delayed. Since
// these data points can skew the mean, they should not be mixed with timing
// events that occurred in the foreground.
// If the event time delta and background time delta are equal, we still
// consider the event to be logged in the foreground histogram since any
// background specific handling would not yet have been applied to that event.
bool WasStartedInForegroundOptionalEventInForeground(
    const base::Optional<base::TimeDelta>& event,
    const PageLoadMetricsObserverDelegate& delegate);

bool WasStartedInForegroundOptionalEventInForegroundAfterBackForwardCacheRestore(
    const base::Optional<base::TimeDelta>& event,
    const PageLoadMetricsObserverDelegate& delegate);

// Returns true if:
// - We have timing information for the event.
// - The page load started in the background.
// - Moved to the foreground prior to the event.
// - Not moved back to the background prior to the event.
bool WasStartedInBackgroundOptionalEventInForeground(
    const base::Optional<base::TimeDelta>& event,
    const PageLoadMetricsObserverDelegate& delegate);

PageAbortInfo GetPageAbortInfo(const PageLoadMetricsObserverDelegate& delegate);

// Get the duration of time that the page spent in the foreground, from
// navigation start until one of the following events:
// * the load of the main resource fails
// * the page load is stopped
// * the tab hosting the page is closed
// * the render process hosting the page goes away
// * a new navigation which later commits is initiated in the same tab
// * the tab hosting the page is backgrounded
base::Optional<base::TimeDelta> GetInitialForegroundDuration(
    const PageLoadMetricsObserverDelegate& delegate,
    base::TimeTicks app_background_time);

// Whether the given url has a Google Search hostname.
// Examples:
//   https://www.google.com -> true
//   https://www.google.co.jp -> true
//   https://www.google.example.com -> false
//   https://docs.google.com -> false
bool IsGoogleSearchHostname(const GURL& url);

// Whether the given url is for a Google Search results page. See
// https://docs.google.com/document/d/1jNPZ6Aeh0KV6umw1yZrrkfXRfxWNruwu7FELLx_cpOg/edit
// for additional details.
// Examples:
//   https://www.google.com/#q=test -> true
//   https://www.google.com/search?q=test -> true
//   https://www.google.com/ -> false
//   https://www.google.com/about/ -> false
bool IsGoogleSearchResultUrl(const GURL& url);

// Whether the given url is a Google Search redirector URL.
bool IsGoogleSearchRedirectorUrl(const GURL& url);

// Whether the given query string contains the given component. The query
// parameter should contain the query string of a URL (the portion following
// the question mark, excluding the question mark). The component must fully
// match a component in the query string. For example, 'foo=bar' would match
// the query string 'a=b&foo=bar&c=d' but would not match 'a=b&zzzfoo=bar&c=d'
// since, though foo=bar appears in the query string, the key specified in the
// component 'foo' does not match the full key in the query string
// 'zzzfoo'. For QueryContainsComponent, the component should of the form
// 'key=value'. For QueryContainsComponentPrefix, the component should be of
// the form 'key=' (where the value is not specified).
// Note: The heuristic used by these functions will not find a component at the
// beginning of the query string if the component starts with a delimiter
// character ('?' or '#'). For example, '?foo=bar' will match the query string
// 'a=b&?foo=bar' but not the query string '?foo=bar&a=b'.
bool QueryContainsComponent(const base::StringPiece query,
                            const base::StringPiece component);
bool QueryContainsComponentPrefix(const base::StringPiece query,
                                  const base::StringPiece component);

}  // namespace page_load_metrics

#endif  // COMPONENTS_PAGE_LOAD_METRICS_BROWSER_PAGE_LOAD_METRICS_UTIL_H_
