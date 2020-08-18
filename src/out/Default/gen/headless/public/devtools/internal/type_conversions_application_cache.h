// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_APPLICATION_CACHE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_APPLICATION_CACHE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_application_cache.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<application_cache::ApplicationCacheResource> {
  static std::unique_ptr<application_cache::ApplicationCacheResource> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::ApplicationCacheResource::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::ApplicationCacheResource& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::ApplicationCache> {
  static std::unique_ptr<application_cache::ApplicationCache> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::ApplicationCache::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::ApplicationCache& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::FrameWithManifest> {
  static std::unique_ptr<application_cache::FrameWithManifest> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::FrameWithManifest::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::FrameWithManifest& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::EnableParams> {
  static std::unique_ptr<application_cache::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::EnableResult> {
  static std::unique_ptr<application_cache::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::GetApplicationCacheForFrameParams> {
  static std::unique_ptr<application_cache::GetApplicationCacheForFrameParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::GetApplicationCacheForFrameParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::GetApplicationCacheForFrameParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::GetApplicationCacheForFrameResult> {
  static std::unique_ptr<application_cache::GetApplicationCacheForFrameResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::GetApplicationCacheForFrameResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::GetApplicationCacheForFrameResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::GetFramesWithManifestsParams> {
  static std::unique_ptr<application_cache::GetFramesWithManifestsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::GetFramesWithManifestsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::GetFramesWithManifestsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::GetFramesWithManifestsResult> {
  static std::unique_ptr<application_cache::GetFramesWithManifestsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::GetFramesWithManifestsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::GetFramesWithManifestsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::GetManifestForFrameParams> {
  static std::unique_ptr<application_cache::GetManifestForFrameParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::GetManifestForFrameParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::GetManifestForFrameParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::GetManifestForFrameResult> {
  static std::unique_ptr<application_cache::GetManifestForFrameResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::GetManifestForFrameResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::GetManifestForFrameResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::ApplicationCacheStatusUpdatedParams> {
  static std::unique_ptr<application_cache::ApplicationCacheStatusUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::ApplicationCacheStatusUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::ApplicationCacheStatusUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<application_cache::NetworkStateUpdatedParams> {
  static std::unique_ptr<application_cache::NetworkStateUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return application_cache::NetworkStateUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const application_cache::NetworkStateUpdatedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_APPLICATION_CACHE_H_
