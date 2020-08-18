// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_BROWSER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_BROWSER_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {



template <>
struct FromValue<browser::WindowState> {
  static browser::WindowState Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return browser::WindowState::NORMAL;
    }
    if (value.GetString() == "normal")
      return browser::WindowState::NORMAL;
    if (value.GetString() == "minimized")
      return browser::WindowState::MINIMIZED;
    if (value.GetString() == "maximized")
      return browser::WindowState::MAXIMIZED;
    if (value.GetString() == "fullscreen")
      return browser::WindowState::FULLSCREEN;
    errors->AddError("invalid enum value");
    return browser::WindowState::NORMAL;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::WindowState& value) {
  switch (value) {
    case browser::WindowState::NORMAL:
      return std::make_unique<base::Value>("normal");
    case browser::WindowState::MINIMIZED:
      return std::make_unique<base::Value>("minimized");
    case browser::WindowState::MAXIMIZED:
      return std::make_unique<base::Value>("maximized");
    case browser::WindowState::FULLSCREEN:
      return std::make_unique<base::Value>("fullscreen");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<browser::Bounds> {
  static std::unique_ptr<browser::Bounds> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::Bounds::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::Bounds& value) {
  return value.Serialize();
}

template <>
struct FromValue<browser::PermissionType> {
  static browser::PermissionType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return browser::PermissionType::ACCESSIBILITY_EVENTS;
    }
    if (value.GetString() == "accessibilityEvents")
      return browser::PermissionType::ACCESSIBILITY_EVENTS;
    if (value.GetString() == "audioCapture")
      return browser::PermissionType::AUDIO_CAPTURE;
    if (value.GetString() == "backgroundSync")
      return browser::PermissionType::BACKGROUND_SYNC;
    if (value.GetString() == "backgroundFetch")
      return browser::PermissionType::BACKGROUND_FETCH;
    if (value.GetString() == "clipboardReadWrite")
      return browser::PermissionType::CLIPBOARD_READ_WRITE;
    if (value.GetString() == "clipboardSanitizedWrite")
      return browser::PermissionType::CLIPBOARD_SANITIZED_WRITE;
    if (value.GetString() == "durableStorage")
      return browser::PermissionType::DURABLE_STORAGE;
    if (value.GetString() == "flash")
      return browser::PermissionType::FLASH;
    if (value.GetString() == "geolocation")
      return browser::PermissionType::GEOLOCATION;
    if (value.GetString() == "midi")
      return browser::PermissionType::MIDI;
    if (value.GetString() == "midiSysex")
      return browser::PermissionType::MIDI_SYSEX;
    if (value.GetString() == "nfc")
      return browser::PermissionType::NFC;
    if (value.GetString() == "notifications")
      return browser::PermissionType::NOTIFICATIONS;
    if (value.GetString() == "paymentHandler")
      return browser::PermissionType::PAYMENT_HANDLER;
    if (value.GetString() == "periodicBackgroundSync")
      return browser::PermissionType::PERIODIC_BACKGROUND_SYNC;
    if (value.GetString() == "protectedMediaIdentifier")
      return browser::PermissionType::PROTECTED_MEDIA_IDENTIFIER;
    if (value.GetString() == "sensors")
      return browser::PermissionType::SENSORS;
    if (value.GetString() == "videoCapture")
      return browser::PermissionType::VIDEO_CAPTURE;
    if (value.GetString() == "idleDetection")
      return browser::PermissionType::IDLE_DETECTION;
    if (value.GetString() == "wakeLockScreen")
      return browser::PermissionType::WAKE_LOCK_SCREEN;
    if (value.GetString() == "wakeLockSystem")
      return browser::PermissionType::WAKE_LOCK_SYSTEM;
    errors->AddError("invalid enum value");
    return browser::PermissionType::ACCESSIBILITY_EVENTS;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::PermissionType& value) {
  switch (value) {
    case browser::PermissionType::ACCESSIBILITY_EVENTS:
      return std::make_unique<base::Value>("accessibilityEvents");
    case browser::PermissionType::AUDIO_CAPTURE:
      return std::make_unique<base::Value>("audioCapture");
    case browser::PermissionType::BACKGROUND_SYNC:
      return std::make_unique<base::Value>("backgroundSync");
    case browser::PermissionType::BACKGROUND_FETCH:
      return std::make_unique<base::Value>("backgroundFetch");
    case browser::PermissionType::CLIPBOARD_READ_WRITE:
      return std::make_unique<base::Value>("clipboardReadWrite");
    case browser::PermissionType::CLIPBOARD_SANITIZED_WRITE:
      return std::make_unique<base::Value>("clipboardSanitizedWrite");
    case browser::PermissionType::DURABLE_STORAGE:
      return std::make_unique<base::Value>("durableStorage");
    case browser::PermissionType::FLASH:
      return std::make_unique<base::Value>("flash");
    case browser::PermissionType::GEOLOCATION:
      return std::make_unique<base::Value>("geolocation");
    case browser::PermissionType::MIDI:
      return std::make_unique<base::Value>("midi");
    case browser::PermissionType::MIDI_SYSEX:
      return std::make_unique<base::Value>("midiSysex");
    case browser::PermissionType::NFC:
      return std::make_unique<base::Value>("nfc");
    case browser::PermissionType::NOTIFICATIONS:
      return std::make_unique<base::Value>("notifications");
    case browser::PermissionType::PAYMENT_HANDLER:
      return std::make_unique<base::Value>("paymentHandler");
    case browser::PermissionType::PERIODIC_BACKGROUND_SYNC:
      return std::make_unique<base::Value>("periodicBackgroundSync");
    case browser::PermissionType::PROTECTED_MEDIA_IDENTIFIER:
      return std::make_unique<base::Value>("protectedMediaIdentifier");
    case browser::PermissionType::SENSORS:
      return std::make_unique<base::Value>("sensors");
    case browser::PermissionType::VIDEO_CAPTURE:
      return std::make_unique<base::Value>("videoCapture");
    case browser::PermissionType::IDLE_DETECTION:
      return std::make_unique<base::Value>("idleDetection");
    case browser::PermissionType::WAKE_LOCK_SCREEN:
      return std::make_unique<base::Value>("wakeLockScreen");
    case browser::PermissionType::WAKE_LOCK_SYSTEM:
      return std::make_unique<base::Value>("wakeLockSystem");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<browser::PermissionSetting> {
  static browser::PermissionSetting Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return browser::PermissionSetting::GRANTED;
    }
    if (value.GetString() == "granted")
      return browser::PermissionSetting::GRANTED;
    if (value.GetString() == "denied")
      return browser::PermissionSetting::DENIED;
    if (value.GetString() == "prompt")
      return browser::PermissionSetting::PROMPT;
    errors->AddError("invalid enum value");
    return browser::PermissionSetting::GRANTED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::PermissionSetting& value) {
  switch (value) {
    case browser::PermissionSetting::GRANTED:
      return std::make_unique<base::Value>("granted");
    case browser::PermissionSetting::DENIED:
      return std::make_unique<base::Value>("denied");
    case browser::PermissionSetting::PROMPT:
      return std::make_unique<base::Value>("prompt");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<browser::PermissionDescriptor> {
  static std::unique_ptr<browser::PermissionDescriptor> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::PermissionDescriptor::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::PermissionDescriptor& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::Bucket> {
  static std::unique_ptr<browser::Bucket> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::Bucket::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::Bucket& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::Histogram> {
  static std::unique_ptr<browser::Histogram> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::Histogram::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::Histogram& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::SetPermissionParams> {
  static std::unique_ptr<browser::SetPermissionParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetPermissionParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetPermissionParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::SetPermissionResult> {
  static std::unique_ptr<browser::SetPermissionResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetPermissionResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetPermissionResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GrantPermissionsParams> {
  static std::unique_ptr<browser::GrantPermissionsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GrantPermissionsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GrantPermissionsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GrantPermissionsResult> {
  static std::unique_ptr<browser::GrantPermissionsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GrantPermissionsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GrantPermissionsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::ResetPermissionsParams> {
  static std::unique_ptr<browser::ResetPermissionsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::ResetPermissionsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::ResetPermissionsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::ResetPermissionsResult> {
  static std::unique_ptr<browser::ResetPermissionsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::ResetPermissionsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::ResetPermissionsResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<browser::SetDownloadBehaviorBehavior> {
  static browser::SetDownloadBehaviorBehavior Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return browser::SetDownloadBehaviorBehavior::DENY;
    }
    if (value.GetString() == "deny")
      return browser::SetDownloadBehaviorBehavior::DENY;
    if (value.GetString() == "allow")
      return browser::SetDownloadBehaviorBehavior::ALLOW;
    if (value.GetString() == "allowAndName")
      return browser::SetDownloadBehaviorBehavior::ALLOW_AND_NAME;
    if (value.GetString() == "default")
      return browser::SetDownloadBehaviorBehavior::DEFAULT;
    errors->AddError("invalid enum value");
    return browser::SetDownloadBehaviorBehavior::DENY;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetDownloadBehaviorBehavior& value) {
  switch (value) {
    case browser::SetDownloadBehaviorBehavior::DENY:
      return std::make_unique<base::Value>("deny");
    case browser::SetDownloadBehaviorBehavior::ALLOW:
      return std::make_unique<base::Value>("allow");
    case browser::SetDownloadBehaviorBehavior::ALLOW_AND_NAME:
      return std::make_unique<base::Value>("allowAndName");
    case browser::SetDownloadBehaviorBehavior::DEFAULT:
      return std::make_unique<base::Value>("default");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<browser::SetDownloadBehaviorParams> {
  static std::unique_ptr<browser::SetDownloadBehaviorParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetDownloadBehaviorParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetDownloadBehaviorParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::SetDownloadBehaviorResult> {
  static std::unique_ptr<browser::SetDownloadBehaviorResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetDownloadBehaviorResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetDownloadBehaviorResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::CloseParams> {
  static std::unique_ptr<browser::CloseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::CloseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::CloseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::CloseResult> {
  static std::unique_ptr<browser::CloseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::CloseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::CloseResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::CrashParams> {
  static std::unique_ptr<browser::CrashParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::CrashParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::CrashParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::CrashResult> {
  static std::unique_ptr<browser::CrashResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::CrashResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::CrashResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::CrashGpuProcessParams> {
  static std::unique_ptr<browser::CrashGpuProcessParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::CrashGpuProcessParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::CrashGpuProcessParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::CrashGpuProcessResult> {
  static std::unique_ptr<browser::CrashGpuProcessResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::CrashGpuProcessResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::CrashGpuProcessResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetVersionParams> {
  static std::unique_ptr<browser::GetVersionParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetVersionParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetVersionParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetVersionResult> {
  static std::unique_ptr<browser::GetVersionResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetVersionResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetVersionResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetBrowserCommandLineParams> {
  static std::unique_ptr<browser::GetBrowserCommandLineParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetBrowserCommandLineParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetBrowserCommandLineParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetBrowserCommandLineResult> {
  static std::unique_ptr<browser::GetBrowserCommandLineResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetBrowserCommandLineResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetBrowserCommandLineResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetHistogramsParams> {
  static std::unique_ptr<browser::GetHistogramsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetHistogramsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetHistogramsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetHistogramsResult> {
  static std::unique_ptr<browser::GetHistogramsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetHistogramsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetHistogramsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetHistogramParams> {
  static std::unique_ptr<browser::GetHistogramParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetHistogramParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetHistogramParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetHistogramResult> {
  static std::unique_ptr<browser::GetHistogramResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetHistogramResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetHistogramResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetWindowBoundsParams> {
  static std::unique_ptr<browser::GetWindowBoundsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetWindowBoundsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetWindowBoundsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetWindowBoundsResult> {
  static std::unique_ptr<browser::GetWindowBoundsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetWindowBoundsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetWindowBoundsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetWindowForTargetParams> {
  static std::unique_ptr<browser::GetWindowForTargetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetWindowForTargetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetWindowForTargetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::GetWindowForTargetResult> {
  static std::unique_ptr<browser::GetWindowForTargetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::GetWindowForTargetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::GetWindowForTargetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::SetWindowBoundsParams> {
  static std::unique_ptr<browser::SetWindowBoundsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetWindowBoundsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetWindowBoundsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::SetWindowBoundsResult> {
  static std::unique_ptr<browser::SetWindowBoundsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetWindowBoundsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetWindowBoundsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::SetDockTileParams> {
  static std::unique_ptr<browser::SetDockTileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetDockTileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetDockTileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<browser::SetDockTileResult> {
  static std::unique_ptr<browser::SetDockTileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return browser::SetDockTileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const browser::SetDockTileResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_BROWSER_H_
