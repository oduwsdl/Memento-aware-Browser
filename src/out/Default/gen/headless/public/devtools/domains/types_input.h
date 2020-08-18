// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_INPUT_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_INPUT_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_input.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace input {

class HEADLESS_EXPORT TouchPoint {
 public:
  static std::unique_ptr<TouchPoint> Parse(const base::Value& value, ErrorReporter* errors);
  ~TouchPoint() { }

  // X coordinate of the event relative to the main frame's viewport in CSS pixels.
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
  // the top of the viewport and Y increases as it proceeds towards the bottom of the viewport.
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // X radius of the touch area (default: 1.0).
  bool HasRadiusX() const { return !!radiusx_; }
  double GetRadiusX() const { DCHECK(HasRadiusX()); return radiusx_.value(); }
  void SetRadiusX(double value) { radiusx_ = value; }

  // Y radius of the touch area (default: 1.0).
  bool HasRadiusY() const { return !!radiusy_; }
  double GetRadiusY() const { DCHECK(HasRadiusY()); return radiusy_.value(); }
  void SetRadiusY(double value) { radiusy_ = value; }

  // Rotation angle (default: 0.0).
  bool HasRotationAngle() const { return !!rotation_angle_; }
  double GetRotationAngle() const { DCHECK(HasRotationAngle()); return rotation_angle_.value(); }
  void SetRotationAngle(double value) { rotation_angle_ = value; }

  // Force (default: 1.0).
  bool HasForce() const { return !!force_; }
  double GetForce() const { DCHECK(HasForce()); return force_.value(); }
  void SetForce(double value) { force_ = value; }

  // Identifier used to track touch sources between events, must be unique within an event.
  bool HasId() const { return !!id_; }
  double GetId() const { DCHECK(HasId()); return id_.value(); }
  void SetId(double value) { id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TouchPoint> Clone() const;

  template<int STATE>
  class TouchPointBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
      kAllRequiredFieldsSet = (kXSet | kYSet | 0)
    };

    TouchPointBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    TouchPointBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    TouchPointBuilder<STATE>& SetRadiusX(double value) {
      result_->SetRadiusX(value);
      return *this;
    }

    TouchPointBuilder<STATE>& SetRadiusY(double value) {
      result_->SetRadiusY(value);
      return *this;
    }

    TouchPointBuilder<STATE>& SetRotationAngle(double value) {
      result_->SetRotationAngle(value);
      return *this;
    }

    TouchPointBuilder<STATE>& SetForce(double value) {
      result_->SetForce(value);
      return *this;
    }

    TouchPointBuilder<STATE>& SetId(double value) {
      result_->SetId(value);
      return *this;
    }

    std::unique_ptr<TouchPoint> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TouchPoint;
    TouchPointBuilder() : result_(new TouchPoint()) { }

    template<int STEP> TouchPointBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TouchPointBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TouchPoint> result_;
  };

  static TouchPointBuilder<0> Builder() {
    return TouchPointBuilder<0>();
  }

 private:
  TouchPoint() { }

  double x_;
  double y_;
  base::Optional<double> radiusx_;
  base::Optional<double> radiusy_;
  base::Optional<double> rotation_angle_;
  base::Optional<double> force_;
  base::Optional<double> id_;

  DISALLOW_COPY_AND_ASSIGN(TouchPoint);
};


// Parameters for the DispatchKeyEvent command.
class HEADLESS_EXPORT DispatchKeyEventParams {
 public:
  static std::unique_ptr<DispatchKeyEventParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DispatchKeyEventParams() { }

  // Type of the key event.
  ::headless::input::DispatchKeyEventType GetType() const { return type_; }
  void SetType(::headless::input::DispatchKeyEventType value) { type_ = value; }

  // Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
  // (default: 0).
  bool HasModifiers() const { return !!modifiers_; }
  int GetModifiers() const { DCHECK(HasModifiers()); return modifiers_.value(); }
  void SetModifiers(int value) { modifiers_ = value; }

  // Time at which the event occurred.
  bool HasTimestamp() const { return !!timestamp_; }
  double GetTimestamp() const { DCHECK(HasTimestamp()); return timestamp_.value(); }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Text as generated by processing a virtual key code with a keyboard layout. Not needed for
  // for `keyUp` and `rawKeyDown` events (default: "")
  bool HasText() const { return !!text_; }
  std::string GetText() const { DCHECK(HasText()); return text_.value(); }
  void SetText(const std::string& value) { text_ = value; }

  // Text that would have been generated by the keyboard if no modifiers were pressed (except for
  // shift). Useful for shortcut (accelerator) key handling (default: "").
  bool HasUnmodifiedText() const { return !!unmodified_text_; }
  std::string GetUnmodifiedText() const { DCHECK(HasUnmodifiedText()); return unmodified_text_.value(); }
  void SetUnmodifiedText(const std::string& value) { unmodified_text_ = value; }

  // Unique key identifier (e.g., 'U+0041') (default: "").
  bool HasKeyIdentifier() const { return !!key_identifier_; }
  std::string GetKeyIdentifier() const { DCHECK(HasKeyIdentifier()); return key_identifier_.value(); }
  void SetKeyIdentifier(const std::string& value) { key_identifier_ = value; }

  // Unique DOM defined string value for each physical key (e.g., 'KeyA') (default: "").
  bool HasCode() const { return !!code_; }
  std::string GetCode() const { DCHECK(HasCode()); return code_.value(); }
  void SetCode(const std::string& value) { code_ = value; }

  // Unique DOM defined string value describing the meaning of the key in the context of active
  // modifiers, keyboard layout, etc (e.g., 'AltGr') (default: "").
  bool HasKey() const { return !!key_; }
  std::string GetKey() const { DCHECK(HasKey()); return key_.value(); }
  void SetKey(const std::string& value) { key_ = value; }

  // Windows virtual key code (default: 0).
  bool HasWindowsVirtualKeyCode() const { return !!windows_virtual_key_code_; }
  int GetWindowsVirtualKeyCode() const { DCHECK(HasWindowsVirtualKeyCode()); return windows_virtual_key_code_.value(); }
  void SetWindowsVirtualKeyCode(int value) { windows_virtual_key_code_ = value; }

  // Native virtual key code (default: 0).
  bool HasNativeVirtualKeyCode() const { return !!native_virtual_key_code_; }
  int GetNativeVirtualKeyCode() const { DCHECK(HasNativeVirtualKeyCode()); return native_virtual_key_code_.value(); }
  void SetNativeVirtualKeyCode(int value) { native_virtual_key_code_ = value; }

  // Whether the event was generated from auto repeat (default: false).
  bool HasAutoRepeat() const { return !!auto_repeat_; }
  bool GetAutoRepeat() const { DCHECK(HasAutoRepeat()); return auto_repeat_.value(); }
  void SetAutoRepeat(bool value) { auto_repeat_ = value; }

  // Whether the event was generated from the keypad (default: false).
  bool HasIsKeypad() const { return !!is_keypad_; }
  bool GetIsKeypad() const { DCHECK(HasIsKeypad()); return is_keypad_.value(); }
  void SetIsKeypad(bool value) { is_keypad_ = value; }

  // Whether the event was a system key event (default: false).
  bool HasIsSystemKey() const { return !!is_system_key_; }
  bool GetIsSystemKey() const { DCHECK(HasIsSystemKey()); return is_system_key_.value(); }
  void SetIsSystemKey(bool value) { is_system_key_ = value; }

  // Whether the event was from the left or right side of the keyboard. 1=Left, 2=Right (default:
  // 0).
  bool HasLocation() const { return !!location_; }
  int GetLocation() const { DCHECK(HasLocation()); return location_.value(); }
  void SetLocation(int value) { location_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DispatchKeyEventParams> Clone() const;

  template<int STATE>
  class DispatchKeyEventParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    DispatchKeyEventParamsBuilder<STATE | kTypeSet>& SetType(::headless::input::DispatchKeyEventType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    DispatchKeyEventParamsBuilder<STATE>& SetModifiers(int value) {
      result_->SetModifiers(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetTimestamp(double value) {
      result_->SetTimestamp(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetText(const std::string& value) {
      result_->SetText(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetUnmodifiedText(const std::string& value) {
      result_->SetUnmodifiedText(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetKeyIdentifier(const std::string& value) {
      result_->SetKeyIdentifier(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetCode(const std::string& value) {
      result_->SetCode(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetKey(const std::string& value) {
      result_->SetKey(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetWindowsVirtualKeyCode(int value) {
      result_->SetWindowsVirtualKeyCode(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetNativeVirtualKeyCode(int value) {
      result_->SetNativeVirtualKeyCode(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetAutoRepeat(bool value) {
      result_->SetAutoRepeat(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetIsKeypad(bool value) {
      result_->SetIsKeypad(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetIsSystemKey(bool value) {
      result_->SetIsSystemKey(value);
      return *this;
    }

    DispatchKeyEventParamsBuilder<STATE>& SetLocation(int value) {
      result_->SetLocation(value);
      return *this;
    }

    std::unique_ptr<DispatchKeyEventParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DispatchKeyEventParams;
    DispatchKeyEventParamsBuilder() : result_(new DispatchKeyEventParams()) { }

    template<int STEP> DispatchKeyEventParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DispatchKeyEventParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DispatchKeyEventParams> result_;
  };

  static DispatchKeyEventParamsBuilder<0> Builder() {
    return DispatchKeyEventParamsBuilder<0>();
  }

 private:
  DispatchKeyEventParams() { }

  ::headless::input::DispatchKeyEventType type_;
  base::Optional<int> modifiers_;
  base::Optional<double> timestamp_;
  base::Optional<std::string> text_;
  base::Optional<std::string> unmodified_text_;
  base::Optional<std::string> key_identifier_;
  base::Optional<std::string> code_;
  base::Optional<std::string> key_;
  base::Optional<int> windows_virtual_key_code_;
  base::Optional<int> native_virtual_key_code_;
  base::Optional<bool> auto_repeat_;
  base::Optional<bool> is_keypad_;
  base::Optional<bool> is_system_key_;
  base::Optional<int> location_;

  DISALLOW_COPY_AND_ASSIGN(DispatchKeyEventParams);
};


// Result for the DispatchKeyEvent command.
class HEADLESS_EXPORT DispatchKeyEventResult {
 public:
  static std::unique_ptr<DispatchKeyEventResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DispatchKeyEventResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DispatchKeyEventResult> Clone() const;

  template<int STATE>
  class DispatchKeyEventResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DispatchKeyEventResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DispatchKeyEventResult;
    DispatchKeyEventResultBuilder() : result_(new DispatchKeyEventResult()) { }

    template<int STEP> DispatchKeyEventResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DispatchKeyEventResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DispatchKeyEventResult> result_;
  };

  static DispatchKeyEventResultBuilder<0> Builder() {
    return DispatchKeyEventResultBuilder<0>();
  }

 private:
  DispatchKeyEventResult() { }


  DISALLOW_COPY_AND_ASSIGN(DispatchKeyEventResult);
};


// Parameters for the InsertText command.
class HEADLESS_EXPORT InsertTextParams {
 public:
  static std::unique_ptr<InsertTextParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~InsertTextParams() { }

  // The text to insert.
  std::string GetText() const { return text_; }
  void SetText(const std::string& value) { text_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InsertTextParams> Clone() const;

  template<int STATE>
  class InsertTextParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTextSet = 1 << 1,
      kAllRequiredFieldsSet = (kTextSet | 0)
    };

    InsertTextParamsBuilder<STATE | kTextSet>& SetText(const std::string& value) {
      static_assert(!(STATE & kTextSet), "property text should not have already been set");
      result_->SetText(value);
      return CastState<kTextSet>();
    }

    std::unique_ptr<InsertTextParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InsertTextParams;
    InsertTextParamsBuilder() : result_(new InsertTextParams()) { }

    template<int STEP> InsertTextParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InsertTextParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InsertTextParams> result_;
  };

  static InsertTextParamsBuilder<0> Builder() {
    return InsertTextParamsBuilder<0>();
  }

 private:
  InsertTextParams() { }

  std::string text_;

  DISALLOW_COPY_AND_ASSIGN(InsertTextParams);
};


// Result for the InsertText command.
class HEADLESS_EXPORT InsertTextResult {
 public:
  static std::unique_ptr<InsertTextResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~InsertTextResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InsertTextResult> Clone() const;

  template<int STATE>
  class InsertTextResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<InsertTextResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InsertTextResult;
    InsertTextResultBuilder() : result_(new InsertTextResult()) { }

    template<int STEP> InsertTextResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InsertTextResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InsertTextResult> result_;
  };

  static InsertTextResultBuilder<0> Builder() {
    return InsertTextResultBuilder<0>();
  }

 private:
  InsertTextResult() { }


  DISALLOW_COPY_AND_ASSIGN(InsertTextResult);
};


// Parameters for the DispatchMouseEvent command.
class HEADLESS_EXPORT DispatchMouseEventParams {
 public:
  static std::unique_ptr<DispatchMouseEventParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DispatchMouseEventParams() { }

  // Type of the mouse event.
  ::headless::input::DispatchMouseEventType GetType() const { return type_; }
  void SetType(::headless::input::DispatchMouseEventType value) { type_ = value; }

  // X coordinate of the event relative to the main frame's viewport in CSS pixels.
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
  // the top of the viewport and Y increases as it proceeds towards the bottom of the viewport.
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
  // (default: 0).
  bool HasModifiers() const { return !!modifiers_; }
  int GetModifiers() const { DCHECK(HasModifiers()); return modifiers_.value(); }
  void SetModifiers(int value) { modifiers_ = value; }

  // Time at which the event occurred.
  bool HasTimestamp() const { return !!timestamp_; }
  double GetTimestamp() const { DCHECK(HasTimestamp()); return timestamp_.value(); }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Mouse button (default: "none").
  bool HasButton() const { return !!button_; }
  ::headless::input::MouseButton GetButton() const { DCHECK(HasButton()); return button_.value(); }
  void SetButton(::headless::input::MouseButton value) { button_ = value; }

  // A number indicating which buttons are pressed on the mouse when a mouse event is triggered.
  // Left=1, Right=2, Middle=4, Back=8, Forward=16, None=0.
  bool HasButtons() const { return !!buttons_; }
  int GetButtons() const { DCHECK(HasButtons()); return buttons_.value(); }
  void SetButtons(int value) { buttons_ = value; }

  // Number of times the mouse button was clicked (default: 0).
  bool HasClickCount() const { return !!click_count_; }
  int GetClickCount() const { DCHECK(HasClickCount()); return click_count_.value(); }
  void SetClickCount(int value) { click_count_ = value; }

  // X delta in CSS pixels for mouse wheel event (default: 0).
  bool HasDeltaX() const { return !!deltax_; }
  double GetDeltaX() const { DCHECK(HasDeltaX()); return deltax_.value(); }
  void SetDeltaX(double value) { deltax_ = value; }

  // Y delta in CSS pixels for mouse wheel event (default: 0).
  bool HasDeltaY() const { return !!deltay_; }
  double GetDeltaY() const { DCHECK(HasDeltaY()); return deltay_.value(); }
  void SetDeltaY(double value) { deltay_ = value; }

  // Pointer type (default: "mouse").
  bool HasPointerType() const { return !!pointer_type_; }
  ::headless::input::DispatchMouseEventPointerType GetPointerType() const { DCHECK(HasPointerType()); return pointer_type_.value(); }
  void SetPointerType(::headless::input::DispatchMouseEventPointerType value) { pointer_type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DispatchMouseEventParams> Clone() const;

  template<int STATE>
  class DispatchMouseEventParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kXSet = 1 << 2,
    kYSet = 1 << 3,
      kAllRequiredFieldsSet = (kTypeSet | kXSet | kYSet | 0)
    };

    DispatchMouseEventParamsBuilder<STATE | kTypeSet>& SetType(::headless::input::DispatchMouseEventType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    DispatchMouseEventParamsBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    DispatchMouseEventParamsBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    DispatchMouseEventParamsBuilder<STATE>& SetModifiers(int value) {
      result_->SetModifiers(value);
      return *this;
    }

    DispatchMouseEventParamsBuilder<STATE>& SetTimestamp(double value) {
      result_->SetTimestamp(value);
      return *this;
    }

    DispatchMouseEventParamsBuilder<STATE>& SetButton(::headless::input::MouseButton value) {
      result_->SetButton(value);
      return *this;
    }

    DispatchMouseEventParamsBuilder<STATE>& SetButtons(int value) {
      result_->SetButtons(value);
      return *this;
    }

    DispatchMouseEventParamsBuilder<STATE>& SetClickCount(int value) {
      result_->SetClickCount(value);
      return *this;
    }

    DispatchMouseEventParamsBuilder<STATE>& SetDeltaX(double value) {
      result_->SetDeltaX(value);
      return *this;
    }

    DispatchMouseEventParamsBuilder<STATE>& SetDeltaY(double value) {
      result_->SetDeltaY(value);
      return *this;
    }

    DispatchMouseEventParamsBuilder<STATE>& SetPointerType(::headless::input::DispatchMouseEventPointerType value) {
      result_->SetPointerType(value);
      return *this;
    }

    std::unique_ptr<DispatchMouseEventParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DispatchMouseEventParams;
    DispatchMouseEventParamsBuilder() : result_(new DispatchMouseEventParams()) { }

    template<int STEP> DispatchMouseEventParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DispatchMouseEventParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DispatchMouseEventParams> result_;
  };

  static DispatchMouseEventParamsBuilder<0> Builder() {
    return DispatchMouseEventParamsBuilder<0>();
  }

 private:
  DispatchMouseEventParams() { }

  ::headless::input::DispatchMouseEventType type_;
  double x_;
  double y_;
  base::Optional<int> modifiers_;
  base::Optional<double> timestamp_;
  base::Optional<::headless::input::MouseButton> button_;
  base::Optional<int> buttons_;
  base::Optional<int> click_count_;
  base::Optional<double> deltax_;
  base::Optional<double> deltay_;
  base::Optional<::headless::input::DispatchMouseEventPointerType> pointer_type_;

  DISALLOW_COPY_AND_ASSIGN(DispatchMouseEventParams);
};


// Result for the DispatchMouseEvent command.
class HEADLESS_EXPORT DispatchMouseEventResult {
 public:
  static std::unique_ptr<DispatchMouseEventResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DispatchMouseEventResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DispatchMouseEventResult> Clone() const;

  template<int STATE>
  class DispatchMouseEventResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DispatchMouseEventResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DispatchMouseEventResult;
    DispatchMouseEventResultBuilder() : result_(new DispatchMouseEventResult()) { }

    template<int STEP> DispatchMouseEventResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DispatchMouseEventResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DispatchMouseEventResult> result_;
  };

  static DispatchMouseEventResultBuilder<0> Builder() {
    return DispatchMouseEventResultBuilder<0>();
  }

 private:
  DispatchMouseEventResult() { }


  DISALLOW_COPY_AND_ASSIGN(DispatchMouseEventResult);
};


// Parameters for the DispatchTouchEvent command.
class HEADLESS_EXPORT DispatchTouchEventParams {
 public:
  static std::unique_ptr<DispatchTouchEventParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DispatchTouchEventParams() { }

  // Type of the touch event. TouchEnd and TouchCancel must not contain any touch points, while
  // TouchStart and TouchMove must contains at least one.
  ::headless::input::DispatchTouchEventType GetType() const { return type_; }
  void SetType(::headless::input::DispatchTouchEventType value) { type_ = value; }

  // Active touch points on the touch device. One event per any changed point (compared to
  // previous touch event in a sequence) is generated, emulating pressing/moving/releasing points
  // one by one.
  const std::vector<std::unique_ptr<::headless::input::TouchPoint>>* GetTouchPoints() const { return &touch_points_; }
  void SetTouchPoints(std::vector<std::unique_ptr<::headless::input::TouchPoint>> value) { touch_points_ = std::move(value); }

  // Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
  // (default: 0).
  bool HasModifiers() const { return !!modifiers_; }
  int GetModifiers() const { DCHECK(HasModifiers()); return modifiers_.value(); }
  void SetModifiers(int value) { modifiers_ = value; }

  // Time at which the event occurred.
  bool HasTimestamp() const { return !!timestamp_; }
  double GetTimestamp() const { DCHECK(HasTimestamp()); return timestamp_.value(); }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DispatchTouchEventParams> Clone() const;

  template<int STATE>
  class DispatchTouchEventParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kTouchPointsSet = 1 << 2,
      kAllRequiredFieldsSet = (kTypeSet | kTouchPointsSet | 0)
    };

    DispatchTouchEventParamsBuilder<STATE | kTypeSet>& SetType(::headless::input::DispatchTouchEventType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    DispatchTouchEventParamsBuilder<STATE | kTouchPointsSet>& SetTouchPoints(std::vector<std::unique_ptr<::headless::input::TouchPoint>> value) {
      static_assert(!(STATE & kTouchPointsSet), "property touchPoints should not have already been set");
      result_->SetTouchPoints(std::move(value));
      return CastState<kTouchPointsSet>();
    }

    DispatchTouchEventParamsBuilder<STATE>& SetModifiers(int value) {
      result_->SetModifiers(value);
      return *this;
    }

    DispatchTouchEventParamsBuilder<STATE>& SetTimestamp(double value) {
      result_->SetTimestamp(value);
      return *this;
    }

    std::unique_ptr<DispatchTouchEventParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DispatchTouchEventParams;
    DispatchTouchEventParamsBuilder() : result_(new DispatchTouchEventParams()) { }

    template<int STEP> DispatchTouchEventParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DispatchTouchEventParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DispatchTouchEventParams> result_;
  };

  static DispatchTouchEventParamsBuilder<0> Builder() {
    return DispatchTouchEventParamsBuilder<0>();
  }

 private:
  DispatchTouchEventParams() { }

  ::headless::input::DispatchTouchEventType type_;
  std::vector<std::unique_ptr<::headless::input::TouchPoint>> touch_points_;
  base::Optional<int> modifiers_;
  base::Optional<double> timestamp_;

  DISALLOW_COPY_AND_ASSIGN(DispatchTouchEventParams);
};


// Result for the DispatchTouchEvent command.
class HEADLESS_EXPORT DispatchTouchEventResult {
 public:
  static std::unique_ptr<DispatchTouchEventResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DispatchTouchEventResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DispatchTouchEventResult> Clone() const;

  template<int STATE>
  class DispatchTouchEventResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DispatchTouchEventResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DispatchTouchEventResult;
    DispatchTouchEventResultBuilder() : result_(new DispatchTouchEventResult()) { }

    template<int STEP> DispatchTouchEventResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DispatchTouchEventResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DispatchTouchEventResult> result_;
  };

  static DispatchTouchEventResultBuilder<0> Builder() {
    return DispatchTouchEventResultBuilder<0>();
  }

 private:
  DispatchTouchEventResult() { }


  DISALLOW_COPY_AND_ASSIGN(DispatchTouchEventResult);
};


// Parameters for the EmulateTouchFromMouseEvent command.
class HEADLESS_EXPORT EmulateTouchFromMouseEventParams {
 public:
  static std::unique_ptr<EmulateTouchFromMouseEventParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EmulateTouchFromMouseEventParams() { }

  // Type of the mouse event.
  ::headless::input::EmulateTouchFromMouseEventType GetType() const { return type_; }
  void SetType(::headless::input::EmulateTouchFromMouseEventType value) { type_ = value; }

  // X coordinate of the mouse pointer in DIP.
  int GetX() const { return x_; }
  void SetX(int value) { x_ = value; }

  // Y coordinate of the mouse pointer in DIP.
  int GetY() const { return y_; }
  void SetY(int value) { y_ = value; }

  // Mouse button. Only "none", "left", "right" are supported.
  ::headless::input::MouseButton GetButton() const { return button_; }
  void SetButton(::headless::input::MouseButton value) { button_ = value; }

  // Time at which the event occurred (default: current time).
  bool HasTimestamp() const { return !!timestamp_; }
  double GetTimestamp() const { DCHECK(HasTimestamp()); return timestamp_.value(); }
  void SetTimestamp(double value) { timestamp_ = value; }

  // X delta in DIP for mouse wheel event (default: 0).
  bool HasDeltaX() const { return !!deltax_; }
  double GetDeltaX() const { DCHECK(HasDeltaX()); return deltax_.value(); }
  void SetDeltaX(double value) { deltax_ = value; }

  // Y delta in DIP for mouse wheel event (default: 0).
  bool HasDeltaY() const { return !!deltay_; }
  double GetDeltaY() const { DCHECK(HasDeltaY()); return deltay_.value(); }
  void SetDeltaY(double value) { deltay_ = value; }

  // Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
  // (default: 0).
  bool HasModifiers() const { return !!modifiers_; }
  int GetModifiers() const { DCHECK(HasModifiers()); return modifiers_.value(); }
  void SetModifiers(int value) { modifiers_ = value; }

  // Number of times the mouse button was clicked (default: 0).
  bool HasClickCount() const { return !!click_count_; }
  int GetClickCount() const { DCHECK(HasClickCount()); return click_count_.value(); }
  void SetClickCount(int value) { click_count_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EmulateTouchFromMouseEventParams> Clone() const;

  template<int STATE>
  class EmulateTouchFromMouseEventParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kXSet = 1 << 2,
    kYSet = 1 << 3,
    kButtonSet = 1 << 4,
      kAllRequiredFieldsSet = (kTypeSet | kXSet | kYSet | kButtonSet | 0)
    };

    EmulateTouchFromMouseEventParamsBuilder<STATE | kTypeSet>& SetType(::headless::input::EmulateTouchFromMouseEventType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE | kXSet>& SetX(int value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE | kYSet>& SetY(int value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE | kButtonSet>& SetButton(::headless::input::MouseButton value) {
      static_assert(!(STATE & kButtonSet), "property button should not have already been set");
      result_->SetButton(value);
      return CastState<kButtonSet>();
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE>& SetTimestamp(double value) {
      result_->SetTimestamp(value);
      return *this;
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE>& SetDeltaX(double value) {
      result_->SetDeltaX(value);
      return *this;
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE>& SetDeltaY(double value) {
      result_->SetDeltaY(value);
      return *this;
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE>& SetModifiers(int value) {
      result_->SetModifiers(value);
      return *this;
    }

    EmulateTouchFromMouseEventParamsBuilder<STATE>& SetClickCount(int value) {
      result_->SetClickCount(value);
      return *this;
    }

    std::unique_ptr<EmulateTouchFromMouseEventParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EmulateTouchFromMouseEventParams;
    EmulateTouchFromMouseEventParamsBuilder() : result_(new EmulateTouchFromMouseEventParams()) { }

    template<int STEP> EmulateTouchFromMouseEventParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EmulateTouchFromMouseEventParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EmulateTouchFromMouseEventParams> result_;
  };

  static EmulateTouchFromMouseEventParamsBuilder<0> Builder() {
    return EmulateTouchFromMouseEventParamsBuilder<0>();
  }

 private:
  EmulateTouchFromMouseEventParams() { }

  ::headless::input::EmulateTouchFromMouseEventType type_;
  int x_;
  int y_;
  ::headless::input::MouseButton button_;
  base::Optional<double> timestamp_;
  base::Optional<double> deltax_;
  base::Optional<double> deltay_;
  base::Optional<int> modifiers_;
  base::Optional<int> click_count_;

  DISALLOW_COPY_AND_ASSIGN(EmulateTouchFromMouseEventParams);
};


// Result for the EmulateTouchFromMouseEvent command.
class HEADLESS_EXPORT EmulateTouchFromMouseEventResult {
 public:
  static std::unique_ptr<EmulateTouchFromMouseEventResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EmulateTouchFromMouseEventResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EmulateTouchFromMouseEventResult> Clone() const;

  template<int STATE>
  class EmulateTouchFromMouseEventResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EmulateTouchFromMouseEventResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EmulateTouchFromMouseEventResult;
    EmulateTouchFromMouseEventResultBuilder() : result_(new EmulateTouchFromMouseEventResult()) { }

    template<int STEP> EmulateTouchFromMouseEventResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EmulateTouchFromMouseEventResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EmulateTouchFromMouseEventResult> result_;
  };

  static EmulateTouchFromMouseEventResultBuilder<0> Builder() {
    return EmulateTouchFromMouseEventResultBuilder<0>();
  }

 private:
  EmulateTouchFromMouseEventResult() { }


  DISALLOW_COPY_AND_ASSIGN(EmulateTouchFromMouseEventResult);
};


// Parameters for the SetIgnoreInputEvents command.
class HEADLESS_EXPORT SetIgnoreInputEventsParams {
 public:
  static std::unique_ptr<SetIgnoreInputEventsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetIgnoreInputEventsParams() { }

  // Ignores input events processing when set to true.
  bool GetIgnore() const { return ignore_; }
  void SetIgnore(bool value) { ignore_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetIgnoreInputEventsParams> Clone() const;

  template<int STATE>
  class SetIgnoreInputEventsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIgnoreSet = 1 << 1,
      kAllRequiredFieldsSet = (kIgnoreSet | 0)
    };

    SetIgnoreInputEventsParamsBuilder<STATE | kIgnoreSet>& SetIgnore(bool value) {
      static_assert(!(STATE & kIgnoreSet), "property ignore should not have already been set");
      result_->SetIgnore(value);
      return CastState<kIgnoreSet>();
    }

    std::unique_ptr<SetIgnoreInputEventsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetIgnoreInputEventsParams;
    SetIgnoreInputEventsParamsBuilder() : result_(new SetIgnoreInputEventsParams()) { }

    template<int STEP> SetIgnoreInputEventsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetIgnoreInputEventsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetIgnoreInputEventsParams> result_;
  };

  static SetIgnoreInputEventsParamsBuilder<0> Builder() {
    return SetIgnoreInputEventsParamsBuilder<0>();
  }

 private:
  SetIgnoreInputEventsParams() { }

  bool ignore_;

  DISALLOW_COPY_AND_ASSIGN(SetIgnoreInputEventsParams);
};


// Result for the SetIgnoreInputEvents command.
class HEADLESS_EXPORT SetIgnoreInputEventsResult {
 public:
  static std::unique_ptr<SetIgnoreInputEventsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetIgnoreInputEventsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetIgnoreInputEventsResult> Clone() const;

  template<int STATE>
  class SetIgnoreInputEventsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetIgnoreInputEventsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetIgnoreInputEventsResult;
    SetIgnoreInputEventsResultBuilder() : result_(new SetIgnoreInputEventsResult()) { }

    template<int STEP> SetIgnoreInputEventsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetIgnoreInputEventsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetIgnoreInputEventsResult> result_;
  };

  static SetIgnoreInputEventsResultBuilder<0> Builder() {
    return SetIgnoreInputEventsResultBuilder<0>();
  }

 private:
  SetIgnoreInputEventsResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetIgnoreInputEventsResult);
};


// Parameters for the SynthesizePinchGesture command.
class HEADLESS_EXPORT SynthesizePinchGestureParams {
 public:
  static std::unique_ptr<SynthesizePinchGestureParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SynthesizePinchGestureParams() { }

  // X coordinate of the start of the gesture in CSS pixels.
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Y coordinate of the start of the gesture in CSS pixels.
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // Relative scale factor after zooming (>1.0 zooms in, <1.0 zooms out).
  double GetScaleFactor() const { return scale_factor_; }
  void SetScaleFactor(double value) { scale_factor_ = value; }

  // Relative pointer speed in pixels per second (default: 800).
  bool HasRelativeSpeed() const { return !!relative_speed_; }
  int GetRelativeSpeed() const { DCHECK(HasRelativeSpeed()); return relative_speed_.value(); }
  void SetRelativeSpeed(int value) { relative_speed_ = value; }

  // Which type of input events to be generated (default: 'default', which queries the platform
  // for the preferred input type).
  bool HasGestureSourceType() const { return !!gesture_source_type_; }
  ::headless::input::GestureSourceType GetGestureSourceType() const { DCHECK(HasGestureSourceType()); return gesture_source_type_.value(); }
  void SetGestureSourceType(::headless::input::GestureSourceType value) { gesture_source_type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SynthesizePinchGestureParams> Clone() const;

  template<int STATE>
  class SynthesizePinchGestureParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
    kScaleFactorSet = 1 << 3,
      kAllRequiredFieldsSet = (kXSet | kYSet | kScaleFactorSet | 0)
    };

    SynthesizePinchGestureParamsBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    SynthesizePinchGestureParamsBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    SynthesizePinchGestureParamsBuilder<STATE | kScaleFactorSet>& SetScaleFactor(double value) {
      static_assert(!(STATE & kScaleFactorSet), "property scaleFactor should not have already been set");
      result_->SetScaleFactor(value);
      return CastState<kScaleFactorSet>();
    }

    SynthesizePinchGestureParamsBuilder<STATE>& SetRelativeSpeed(int value) {
      result_->SetRelativeSpeed(value);
      return *this;
    }

    SynthesizePinchGestureParamsBuilder<STATE>& SetGestureSourceType(::headless::input::GestureSourceType value) {
      result_->SetGestureSourceType(value);
      return *this;
    }

    std::unique_ptr<SynthesizePinchGestureParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SynthesizePinchGestureParams;
    SynthesizePinchGestureParamsBuilder() : result_(new SynthesizePinchGestureParams()) { }

    template<int STEP> SynthesizePinchGestureParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SynthesizePinchGestureParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SynthesizePinchGestureParams> result_;
  };

  static SynthesizePinchGestureParamsBuilder<0> Builder() {
    return SynthesizePinchGestureParamsBuilder<0>();
  }

 private:
  SynthesizePinchGestureParams() { }

  double x_;
  double y_;
  double scale_factor_;
  base::Optional<int> relative_speed_;
  base::Optional<::headless::input::GestureSourceType> gesture_source_type_;

  DISALLOW_COPY_AND_ASSIGN(SynthesizePinchGestureParams);
};


// Result for the SynthesizePinchGesture command.
class HEADLESS_EXPORT SynthesizePinchGestureResult {
 public:
  static std::unique_ptr<SynthesizePinchGestureResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SynthesizePinchGestureResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SynthesizePinchGestureResult> Clone() const;

  template<int STATE>
  class SynthesizePinchGestureResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SynthesizePinchGestureResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SynthesizePinchGestureResult;
    SynthesizePinchGestureResultBuilder() : result_(new SynthesizePinchGestureResult()) { }

    template<int STEP> SynthesizePinchGestureResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SynthesizePinchGestureResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SynthesizePinchGestureResult> result_;
  };

  static SynthesizePinchGestureResultBuilder<0> Builder() {
    return SynthesizePinchGestureResultBuilder<0>();
  }

 private:
  SynthesizePinchGestureResult() { }


  DISALLOW_COPY_AND_ASSIGN(SynthesizePinchGestureResult);
};


// Parameters for the SynthesizeScrollGesture command.
class HEADLESS_EXPORT SynthesizeScrollGestureParams {
 public:
  static std::unique_ptr<SynthesizeScrollGestureParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SynthesizeScrollGestureParams() { }

  // X coordinate of the start of the gesture in CSS pixels.
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Y coordinate of the start of the gesture in CSS pixels.
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // The distance to scroll along the X axis (positive to scroll left).
  bool HasXDistance() const { return !!x_distance_; }
  double GetXDistance() const { DCHECK(HasXDistance()); return x_distance_.value(); }
  void SetXDistance(double value) { x_distance_ = value; }

  // The distance to scroll along the Y axis (positive to scroll up).
  bool HasYDistance() const { return !!y_distance_; }
  double GetYDistance() const { DCHECK(HasYDistance()); return y_distance_.value(); }
  void SetYDistance(double value) { y_distance_ = value; }

  // The number of additional pixels to scroll back along the X axis, in addition to the given
  // distance.
  bool HasXOverscroll() const { return !!x_overscroll_; }
  double GetXOverscroll() const { DCHECK(HasXOverscroll()); return x_overscroll_.value(); }
  void SetXOverscroll(double value) { x_overscroll_ = value; }

  // The number of additional pixels to scroll back along the Y axis, in addition to the given
  // distance.
  bool HasYOverscroll() const { return !!y_overscroll_; }
  double GetYOverscroll() const { DCHECK(HasYOverscroll()); return y_overscroll_.value(); }
  void SetYOverscroll(double value) { y_overscroll_ = value; }

  // Prevent fling (default: true).
  bool HasPreventFling() const { return !!prevent_fling_; }
  bool GetPreventFling() const { DCHECK(HasPreventFling()); return prevent_fling_.value(); }
  void SetPreventFling(bool value) { prevent_fling_ = value; }

  // Swipe speed in pixels per second (default: 800).
  bool HasSpeed() const { return !!speed_; }
  int GetSpeed() const { DCHECK(HasSpeed()); return speed_.value(); }
  void SetSpeed(int value) { speed_ = value; }

  // Which type of input events to be generated (default: 'default', which queries the platform
  // for the preferred input type).
  bool HasGestureSourceType() const { return !!gesture_source_type_; }
  ::headless::input::GestureSourceType GetGestureSourceType() const { DCHECK(HasGestureSourceType()); return gesture_source_type_.value(); }
  void SetGestureSourceType(::headless::input::GestureSourceType value) { gesture_source_type_ = value; }

  // The number of times to repeat the gesture (default: 0).
  bool HasRepeatCount() const { return !!repeat_count_; }
  int GetRepeatCount() const { DCHECK(HasRepeatCount()); return repeat_count_.value(); }
  void SetRepeatCount(int value) { repeat_count_ = value; }

  // The number of milliseconds delay between each repeat. (default: 250).
  bool HasRepeatDelayMs() const { return !!repeat_delay_ms_; }
  int GetRepeatDelayMs() const { DCHECK(HasRepeatDelayMs()); return repeat_delay_ms_.value(); }
  void SetRepeatDelayMs(int value) { repeat_delay_ms_ = value; }

  // The name of the interaction markers to generate, if not empty (default: "").
  bool HasInteractionMarkerName() const { return !!interaction_marker_name_; }
  std::string GetInteractionMarkerName() const { DCHECK(HasInteractionMarkerName()); return interaction_marker_name_.value(); }
  void SetInteractionMarkerName(const std::string& value) { interaction_marker_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SynthesizeScrollGestureParams> Clone() const;

  template<int STATE>
  class SynthesizeScrollGestureParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
      kAllRequiredFieldsSet = (kXSet | kYSet | 0)
    };

    SynthesizeScrollGestureParamsBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    SynthesizeScrollGestureParamsBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetXDistance(double value) {
      result_->SetXDistance(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetYDistance(double value) {
      result_->SetYDistance(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetXOverscroll(double value) {
      result_->SetXOverscroll(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetYOverscroll(double value) {
      result_->SetYOverscroll(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetPreventFling(bool value) {
      result_->SetPreventFling(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetSpeed(int value) {
      result_->SetSpeed(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetGestureSourceType(::headless::input::GestureSourceType value) {
      result_->SetGestureSourceType(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetRepeatCount(int value) {
      result_->SetRepeatCount(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetRepeatDelayMs(int value) {
      result_->SetRepeatDelayMs(value);
      return *this;
    }

    SynthesizeScrollGestureParamsBuilder<STATE>& SetInteractionMarkerName(const std::string& value) {
      result_->SetInteractionMarkerName(value);
      return *this;
    }

    std::unique_ptr<SynthesizeScrollGestureParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SynthesizeScrollGestureParams;
    SynthesizeScrollGestureParamsBuilder() : result_(new SynthesizeScrollGestureParams()) { }

    template<int STEP> SynthesizeScrollGestureParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SynthesizeScrollGestureParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SynthesizeScrollGestureParams> result_;
  };

  static SynthesizeScrollGestureParamsBuilder<0> Builder() {
    return SynthesizeScrollGestureParamsBuilder<0>();
  }

 private:
  SynthesizeScrollGestureParams() { }

  double x_;
  double y_;
  base::Optional<double> x_distance_;
  base::Optional<double> y_distance_;
  base::Optional<double> x_overscroll_;
  base::Optional<double> y_overscroll_;
  base::Optional<bool> prevent_fling_;
  base::Optional<int> speed_;
  base::Optional<::headless::input::GestureSourceType> gesture_source_type_;
  base::Optional<int> repeat_count_;
  base::Optional<int> repeat_delay_ms_;
  base::Optional<std::string> interaction_marker_name_;

  DISALLOW_COPY_AND_ASSIGN(SynthesizeScrollGestureParams);
};


// Result for the SynthesizeScrollGesture command.
class HEADLESS_EXPORT SynthesizeScrollGestureResult {
 public:
  static std::unique_ptr<SynthesizeScrollGestureResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SynthesizeScrollGestureResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SynthesizeScrollGestureResult> Clone() const;

  template<int STATE>
  class SynthesizeScrollGestureResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SynthesizeScrollGestureResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SynthesizeScrollGestureResult;
    SynthesizeScrollGestureResultBuilder() : result_(new SynthesizeScrollGestureResult()) { }

    template<int STEP> SynthesizeScrollGestureResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SynthesizeScrollGestureResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SynthesizeScrollGestureResult> result_;
  };

  static SynthesizeScrollGestureResultBuilder<0> Builder() {
    return SynthesizeScrollGestureResultBuilder<0>();
  }

 private:
  SynthesizeScrollGestureResult() { }


  DISALLOW_COPY_AND_ASSIGN(SynthesizeScrollGestureResult);
};


// Parameters for the SynthesizeTapGesture command.
class HEADLESS_EXPORT SynthesizeTapGestureParams {
 public:
  static std::unique_ptr<SynthesizeTapGestureParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SynthesizeTapGestureParams() { }

  // X coordinate of the start of the gesture in CSS pixels.
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Y coordinate of the start of the gesture in CSS pixels.
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // Duration between touchdown and touchup events in ms (default: 50).
  bool HasDuration() const { return !!duration_; }
  int GetDuration() const { DCHECK(HasDuration()); return duration_.value(); }
  void SetDuration(int value) { duration_ = value; }

  // Number of times to perform the tap (e.g. 2 for double tap, default: 1).
  bool HasTapCount() const { return !!tap_count_; }
  int GetTapCount() const { DCHECK(HasTapCount()); return tap_count_.value(); }
  void SetTapCount(int value) { tap_count_ = value; }

  // Which type of input events to be generated (default: 'default', which queries the platform
  // for the preferred input type).
  bool HasGestureSourceType() const { return !!gesture_source_type_; }
  ::headless::input::GestureSourceType GetGestureSourceType() const { DCHECK(HasGestureSourceType()); return gesture_source_type_.value(); }
  void SetGestureSourceType(::headless::input::GestureSourceType value) { gesture_source_type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SynthesizeTapGestureParams> Clone() const;

  template<int STATE>
  class SynthesizeTapGestureParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
      kAllRequiredFieldsSet = (kXSet | kYSet | 0)
    };

    SynthesizeTapGestureParamsBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    SynthesizeTapGestureParamsBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    SynthesizeTapGestureParamsBuilder<STATE>& SetDuration(int value) {
      result_->SetDuration(value);
      return *this;
    }

    SynthesizeTapGestureParamsBuilder<STATE>& SetTapCount(int value) {
      result_->SetTapCount(value);
      return *this;
    }

    SynthesizeTapGestureParamsBuilder<STATE>& SetGestureSourceType(::headless::input::GestureSourceType value) {
      result_->SetGestureSourceType(value);
      return *this;
    }

    std::unique_ptr<SynthesizeTapGestureParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SynthesizeTapGestureParams;
    SynthesizeTapGestureParamsBuilder() : result_(new SynthesizeTapGestureParams()) { }

    template<int STEP> SynthesizeTapGestureParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SynthesizeTapGestureParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SynthesizeTapGestureParams> result_;
  };

  static SynthesizeTapGestureParamsBuilder<0> Builder() {
    return SynthesizeTapGestureParamsBuilder<0>();
  }

 private:
  SynthesizeTapGestureParams() { }

  double x_;
  double y_;
  base::Optional<int> duration_;
  base::Optional<int> tap_count_;
  base::Optional<::headless::input::GestureSourceType> gesture_source_type_;

  DISALLOW_COPY_AND_ASSIGN(SynthesizeTapGestureParams);
};


// Result for the SynthesizeTapGesture command.
class HEADLESS_EXPORT SynthesizeTapGestureResult {
 public:
  static std::unique_ptr<SynthesizeTapGestureResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SynthesizeTapGestureResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SynthesizeTapGestureResult> Clone() const;

  template<int STATE>
  class SynthesizeTapGestureResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SynthesizeTapGestureResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SynthesizeTapGestureResult;
    SynthesizeTapGestureResultBuilder() : result_(new SynthesizeTapGestureResult()) { }

    template<int STEP> SynthesizeTapGestureResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SynthesizeTapGestureResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SynthesizeTapGestureResult> result_;
  };

  static SynthesizeTapGestureResultBuilder<0> Builder() {
    return SynthesizeTapGestureResultBuilder<0>();
  }

 private:
  SynthesizeTapGestureResult() { }


  DISALLOW_COPY_AND_ASSIGN(SynthesizeTapGestureResult);
};


}  // namespace input

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_INPUT_H_
