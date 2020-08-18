// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_TARGET_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_TARGET_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_target.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {




template <>
struct FromValue<target::TargetInfo> {
  static std::unique_ptr<target::TargetInfo> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::TargetInfo::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::TargetInfo& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::RemoteLocation> {
  static std::unique_ptr<target::RemoteLocation> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::RemoteLocation::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::RemoteLocation& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::ActivateTargetParams> {
  static std::unique_ptr<target::ActivateTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::ActivateTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::ActivateTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::ActivateTargetResult> {
  static std::unique_ptr<target::ActivateTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::ActivateTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::ActivateTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::AttachToTargetParams> {
  static std::unique_ptr<target::AttachToTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::AttachToTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::AttachToTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::AttachToTargetResult> {
  static std::unique_ptr<target::AttachToTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::AttachToTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::AttachToTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::AttachToBrowserTargetParams> {
  static std::unique_ptr<target::AttachToBrowserTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::AttachToBrowserTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::AttachToBrowserTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::AttachToBrowserTargetResult> {
  static std::unique_ptr<target::AttachToBrowserTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::AttachToBrowserTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::AttachToBrowserTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::CloseTargetParams> {
  static std::unique_ptr<target::CloseTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::CloseTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::CloseTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::CloseTargetResult> {
  static std::unique_ptr<target::CloseTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::CloseTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::CloseTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::ExposeDevToolsProtocolParams> {
  static std::unique_ptr<target::ExposeDevToolsProtocolParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::ExposeDevToolsProtocolParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::ExposeDevToolsProtocolParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::ExposeDevToolsProtocolResult> {
  static std::unique_ptr<target::ExposeDevToolsProtocolResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::ExposeDevToolsProtocolResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::ExposeDevToolsProtocolResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::CreateBrowserContextParams> {
  static std::unique_ptr<target::CreateBrowserContextParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::CreateBrowserContextParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::CreateBrowserContextParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::CreateBrowserContextResult> {
  static std::unique_ptr<target::CreateBrowserContextResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::CreateBrowserContextResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::CreateBrowserContextResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::GetBrowserContextsParams> {
  static std::unique_ptr<target::GetBrowserContextsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::GetBrowserContextsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::GetBrowserContextsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::GetBrowserContextsResult> {
  static std::unique_ptr<target::GetBrowserContextsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::GetBrowserContextsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::GetBrowserContextsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::CreateTargetParams> {
  static std::unique_ptr<target::CreateTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::CreateTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::CreateTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::CreateTargetResult> {
  static std::unique_ptr<target::CreateTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::CreateTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::CreateTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::DetachFromTargetParams> {
  static std::unique_ptr<target::DetachFromTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::DetachFromTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::DetachFromTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::DetachFromTargetResult> {
  static std::unique_ptr<target::DetachFromTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::DetachFromTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::DetachFromTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::DisposeBrowserContextParams> {
  static std::unique_ptr<target::DisposeBrowserContextParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::DisposeBrowserContextParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::DisposeBrowserContextParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::DisposeBrowserContextResult> {
  static std::unique_ptr<target::DisposeBrowserContextResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::DisposeBrowserContextResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::DisposeBrowserContextResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::GetTargetInfoParams> {
  static std::unique_ptr<target::GetTargetInfoParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::GetTargetInfoParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::GetTargetInfoParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::GetTargetInfoResult> {
  static std::unique_ptr<target::GetTargetInfoResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::GetTargetInfoResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::GetTargetInfoResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::GetTargetsParams> {
  static std::unique_ptr<target::GetTargetsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::GetTargetsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::GetTargetsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::GetTargetsResult> {
  static std::unique_ptr<target::GetTargetsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::GetTargetsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::GetTargetsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SendMessageToTargetParams> {
  static std::unique_ptr<target::SendMessageToTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SendMessageToTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SendMessageToTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SendMessageToTargetResult> {
  static std::unique_ptr<target::SendMessageToTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SendMessageToTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SendMessageToTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SetAutoAttachParams> {
  static std::unique_ptr<target::SetAutoAttachParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SetAutoAttachParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SetAutoAttachParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SetAutoAttachResult> {
  static std::unique_ptr<target::SetAutoAttachResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SetAutoAttachResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SetAutoAttachResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SetDiscoverTargetsParams> {
  static std::unique_ptr<target::SetDiscoverTargetsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SetDiscoverTargetsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SetDiscoverTargetsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SetDiscoverTargetsResult> {
  static std::unique_ptr<target::SetDiscoverTargetsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SetDiscoverTargetsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SetDiscoverTargetsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SetRemoteLocationsParams> {
  static std::unique_ptr<target::SetRemoteLocationsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SetRemoteLocationsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SetRemoteLocationsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::SetRemoteLocationsResult> {
  static std::unique_ptr<target::SetRemoteLocationsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::SetRemoteLocationsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::SetRemoteLocationsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::AttachedToTargetParams> {
  static std::unique_ptr<target::AttachedToTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::AttachedToTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::AttachedToTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::DetachedFromTargetParams> {
  static std::unique_ptr<target::DetachedFromTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::DetachedFromTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::DetachedFromTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::ReceivedMessageFromTargetParams> {
  static std::unique_ptr<target::ReceivedMessageFromTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::ReceivedMessageFromTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::ReceivedMessageFromTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::TargetCreatedParams> {
  static std::unique_ptr<target::TargetCreatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::TargetCreatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::TargetCreatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::TargetDestroyedParams> {
  static std::unique_ptr<target::TargetDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::TargetDestroyedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::TargetDestroyedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::TargetCrashedParams> {
  static std::unique_ptr<target::TargetCrashedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::TargetCrashedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::TargetCrashedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<target::TargetInfoChangedParams> {
  static std::unique_ptr<target::TargetInfoChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return target::TargetInfoChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const target::TargetInfoChangedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_TARGET_H_
