// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INPUT_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INPUT_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_input.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<input::TouchPoint> {
  static std::unique_ptr<input::TouchPoint> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::TouchPoint::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::TouchPoint& value) {
  return value.Serialize();
}

template <>
struct FromValue<input::GestureSourceType> {
  static input::GestureSourceType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return input::GestureSourceType::DEFAULT;
    }
    if (value.GetString() == "default")
      return input::GestureSourceType::DEFAULT;
    if (value.GetString() == "touch")
      return input::GestureSourceType::TOUCH;
    if (value.GetString() == "mouse")
      return input::GestureSourceType::MOUSE;
    errors->AddError("invalid enum value");
    return input::GestureSourceType::DEFAULT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::GestureSourceType& value) {
  switch (value) {
    case input::GestureSourceType::DEFAULT:
      return std::make_unique<base::Value>("default");
    case input::GestureSourceType::TOUCH:
      return std::make_unique<base::Value>("touch");
    case input::GestureSourceType::MOUSE:
      return std::make_unique<base::Value>("mouse");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<input::MouseButton> {
  static input::MouseButton Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return input::MouseButton::NONE;
    }
    if (value.GetString() == "none")
      return input::MouseButton::NONE;
    if (value.GetString() == "left")
      return input::MouseButton::LEFT;
    if (value.GetString() == "middle")
      return input::MouseButton::MIDDLE;
    if (value.GetString() == "right")
      return input::MouseButton::RIGHT;
    if (value.GetString() == "back")
      return input::MouseButton::BACK;
    if (value.GetString() == "forward")
      return input::MouseButton::FORWARD;
    errors->AddError("invalid enum value");
    return input::MouseButton::NONE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::MouseButton& value) {
  switch (value) {
    case input::MouseButton::NONE:
      return std::make_unique<base::Value>("none");
    case input::MouseButton::LEFT:
      return std::make_unique<base::Value>("left");
    case input::MouseButton::MIDDLE:
      return std::make_unique<base::Value>("middle");
    case input::MouseButton::RIGHT:
      return std::make_unique<base::Value>("right");
    case input::MouseButton::BACK:
      return std::make_unique<base::Value>("back");
    case input::MouseButton::FORWARD:
      return std::make_unique<base::Value>("forward");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<input::DispatchKeyEventType> {
  static input::DispatchKeyEventType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return input::DispatchKeyEventType::KEY_DOWN;
    }
    if (value.GetString() == "keyDown")
      return input::DispatchKeyEventType::KEY_DOWN;
    if (value.GetString() == "keyUp")
      return input::DispatchKeyEventType::KEY_UP;
    if (value.GetString() == "rawKeyDown")
      return input::DispatchKeyEventType::RAW_KEY_DOWN;
    if (value.GetString() == "char")
      return input::DispatchKeyEventType::CHAR;
    errors->AddError("invalid enum value");
    return input::DispatchKeyEventType::KEY_DOWN;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchKeyEventType& value) {
  switch (value) {
    case input::DispatchKeyEventType::KEY_DOWN:
      return std::make_unique<base::Value>("keyDown");
    case input::DispatchKeyEventType::KEY_UP:
      return std::make_unique<base::Value>("keyUp");
    case input::DispatchKeyEventType::RAW_KEY_DOWN:
      return std::make_unique<base::Value>("rawKeyDown");
    case input::DispatchKeyEventType::CHAR:
      return std::make_unique<base::Value>("char");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<input::DispatchKeyEventParams> {
  static std::unique_ptr<input::DispatchKeyEventParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::DispatchKeyEventParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchKeyEventParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::DispatchKeyEventResult> {
  static std::unique_ptr<input::DispatchKeyEventResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::DispatchKeyEventResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchKeyEventResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::InsertTextParams> {
  static std::unique_ptr<input::InsertTextParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::InsertTextParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::InsertTextParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::InsertTextResult> {
  static std::unique_ptr<input::InsertTextResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::InsertTextResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::InsertTextResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<input::DispatchMouseEventType> {
  static input::DispatchMouseEventType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return input::DispatchMouseEventType::MOUSE_PRESSED;
    }
    if (value.GetString() == "mousePressed")
      return input::DispatchMouseEventType::MOUSE_PRESSED;
    if (value.GetString() == "mouseReleased")
      return input::DispatchMouseEventType::MOUSE_RELEASED;
    if (value.GetString() == "mouseMoved")
      return input::DispatchMouseEventType::MOUSE_PTR_MOVED;
    if (value.GetString() == "mouseWheel")
      return input::DispatchMouseEventType::MOUSE_WHEEL;
    errors->AddError("invalid enum value");
    return input::DispatchMouseEventType::MOUSE_PRESSED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchMouseEventType& value) {
  switch (value) {
    case input::DispatchMouseEventType::MOUSE_PRESSED:
      return std::make_unique<base::Value>("mousePressed");
    case input::DispatchMouseEventType::MOUSE_RELEASED:
      return std::make_unique<base::Value>("mouseReleased");
    case input::DispatchMouseEventType::MOUSE_PTR_MOVED:
      return std::make_unique<base::Value>("mouseMoved");
    case input::DispatchMouseEventType::MOUSE_WHEEL:
      return std::make_unique<base::Value>("mouseWheel");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<input::DispatchMouseEventPointerType> {
  static input::DispatchMouseEventPointerType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return input::DispatchMouseEventPointerType::MOUSE;
    }
    if (value.GetString() == "mouse")
      return input::DispatchMouseEventPointerType::MOUSE;
    if (value.GetString() == "pen")
      return input::DispatchMouseEventPointerType::PEN;
    errors->AddError("invalid enum value");
    return input::DispatchMouseEventPointerType::MOUSE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchMouseEventPointerType& value) {
  switch (value) {
    case input::DispatchMouseEventPointerType::MOUSE:
      return std::make_unique<base::Value>("mouse");
    case input::DispatchMouseEventPointerType::PEN:
      return std::make_unique<base::Value>("pen");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<input::DispatchMouseEventParams> {
  static std::unique_ptr<input::DispatchMouseEventParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::DispatchMouseEventParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchMouseEventParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::DispatchMouseEventResult> {
  static std::unique_ptr<input::DispatchMouseEventResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::DispatchMouseEventResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchMouseEventResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<input::DispatchTouchEventType> {
  static input::DispatchTouchEventType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return input::DispatchTouchEventType::TOUCH_START;
    }
    if (value.GetString() == "touchStart")
      return input::DispatchTouchEventType::TOUCH_START;
    if (value.GetString() == "touchEnd")
      return input::DispatchTouchEventType::TOUCH_END;
    if (value.GetString() == "touchMove")
      return input::DispatchTouchEventType::TOUCH_MOVE;
    if (value.GetString() == "touchCancel")
      return input::DispatchTouchEventType::TOUCH_CANCEL;
    errors->AddError("invalid enum value");
    return input::DispatchTouchEventType::TOUCH_START;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchTouchEventType& value) {
  switch (value) {
    case input::DispatchTouchEventType::TOUCH_START:
      return std::make_unique<base::Value>("touchStart");
    case input::DispatchTouchEventType::TOUCH_END:
      return std::make_unique<base::Value>("touchEnd");
    case input::DispatchTouchEventType::TOUCH_MOVE:
      return std::make_unique<base::Value>("touchMove");
    case input::DispatchTouchEventType::TOUCH_CANCEL:
      return std::make_unique<base::Value>("touchCancel");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<input::DispatchTouchEventParams> {
  static std::unique_ptr<input::DispatchTouchEventParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::DispatchTouchEventParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchTouchEventParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::DispatchTouchEventResult> {
  static std::unique_ptr<input::DispatchTouchEventResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::DispatchTouchEventResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::DispatchTouchEventResult& value) {
  return value.Serialize();
}

template <>
struct FromValue<input::EmulateTouchFromMouseEventType> {
  static input::EmulateTouchFromMouseEventType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return input::EmulateTouchFromMouseEventType::MOUSE_PRESSED;
    }
    if (value.GetString() == "mousePressed")
      return input::EmulateTouchFromMouseEventType::MOUSE_PRESSED;
    if (value.GetString() == "mouseReleased")
      return input::EmulateTouchFromMouseEventType::MOUSE_RELEASED;
    if (value.GetString() == "mouseMoved")
      return input::EmulateTouchFromMouseEventType::MOUSE_PTR_MOVED;
    if (value.GetString() == "mouseWheel")
      return input::EmulateTouchFromMouseEventType::MOUSE_WHEEL;
    errors->AddError("invalid enum value");
    return input::EmulateTouchFromMouseEventType::MOUSE_PRESSED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::EmulateTouchFromMouseEventType& value) {
  switch (value) {
    case input::EmulateTouchFromMouseEventType::MOUSE_PRESSED:
      return std::make_unique<base::Value>("mousePressed");
    case input::EmulateTouchFromMouseEventType::MOUSE_RELEASED:
      return std::make_unique<base::Value>("mouseReleased");
    case input::EmulateTouchFromMouseEventType::MOUSE_PTR_MOVED:
      return std::make_unique<base::Value>("mouseMoved");
    case input::EmulateTouchFromMouseEventType::MOUSE_WHEEL:
      return std::make_unique<base::Value>("mouseWheel");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<input::EmulateTouchFromMouseEventParams> {
  static std::unique_ptr<input::EmulateTouchFromMouseEventParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::EmulateTouchFromMouseEventParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::EmulateTouchFromMouseEventParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::EmulateTouchFromMouseEventResult> {
  static std::unique_ptr<input::EmulateTouchFromMouseEventResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::EmulateTouchFromMouseEventResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::EmulateTouchFromMouseEventResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SetIgnoreInputEventsParams> {
  static std::unique_ptr<input::SetIgnoreInputEventsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SetIgnoreInputEventsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SetIgnoreInputEventsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SetIgnoreInputEventsResult> {
  static std::unique_ptr<input::SetIgnoreInputEventsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SetIgnoreInputEventsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SetIgnoreInputEventsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SynthesizePinchGestureParams> {
  static std::unique_ptr<input::SynthesizePinchGestureParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SynthesizePinchGestureParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SynthesizePinchGestureParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SynthesizePinchGestureResult> {
  static std::unique_ptr<input::SynthesizePinchGestureResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SynthesizePinchGestureResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SynthesizePinchGestureResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SynthesizeScrollGestureParams> {
  static std::unique_ptr<input::SynthesizeScrollGestureParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SynthesizeScrollGestureParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SynthesizeScrollGestureParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SynthesizeScrollGestureResult> {
  static std::unique_ptr<input::SynthesizeScrollGestureResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SynthesizeScrollGestureResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SynthesizeScrollGestureResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SynthesizeTapGestureParams> {
  static std::unique_ptr<input::SynthesizeTapGestureParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SynthesizeTapGestureParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SynthesizeTapGestureParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<input::SynthesizeTapGestureResult> {
  static std::unique_ptr<input::SynthesizeTapGestureResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return input::SynthesizeTapGestureResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const input::SynthesizeTapGestureResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INPUT_H_
