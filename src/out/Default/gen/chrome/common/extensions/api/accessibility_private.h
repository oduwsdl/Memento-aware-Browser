// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/accessibility_private.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_ACCESSIBILITY_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_ACCESSIBILITY_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace accessibility_private {

//
// Types
//

// Information about an alert
struct AlertInfo {
  AlertInfo();
  ~AlertInfo();
  AlertInfo(AlertInfo&& rhs);
  AlertInfo& operator=(AlertInfo&& rhs);

  // Populates a AlertInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, AlertInfo* out);

  // Creates a AlertInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<AlertInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AlertInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The message the alert is showing.
  std::string message;


 private:
  DISALLOW_COPY_AND_ASSIGN(AlertInfo);
};

// Bounding rectangle in global screen coordinates.
struct ScreenRect {
  ScreenRect();
  ~ScreenRect();
  ScreenRect(ScreenRect&& rhs);
  ScreenRect& operator=(ScreenRect&& rhs);

  // Populates a ScreenRect object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, ScreenRect* out);

  // Creates a ScreenRect object from a base::Value, or NULL on failure.
  static std::unique_ptr<ScreenRect> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ScreenRect object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Left coordinate in global screen coordinates.
  int left;

  // Top coordinate in global screen coordinates.
  int top;

  // Width in pixels.
  int width;

  // Height in pixels.
  int height;


 private:
  DISALLOW_COPY_AND_ASSIGN(ScreenRect);
};

// Accessibility gestures fired by the touch exploration controller.
enum Gesture {
  GESTURE_NONE,
  GESTURE_CLICK,
  GESTURE_SWIPELEFT1,
  GESTURE_SWIPEUP1,
  GESTURE_SWIPERIGHT1,
  GESTURE_SWIPEDOWN1,
  GESTURE_SWIPELEFT2,
  GESTURE_SWIPEUP2,
  GESTURE_SWIPERIGHT2,
  GESTURE_SWIPEDOWN2,
  GESTURE_SWIPELEFT3,
  GESTURE_SWIPEUP3,
  GESTURE_SWIPERIGHT3,
  GESTURE_SWIPEDOWN3,
  GESTURE_SWIPELEFT4,
  GESTURE_SWIPEUP4,
  GESTURE_SWIPERIGHT4,
  GESTURE_SWIPEDOWN4,
  GESTURE_TAP2,
  GESTURE_TAP3,
  GESTURE_TAP4,
  GESTURE_LAST = GESTURE_TAP4,
};


const char* ToString(Gesture as_enum);
Gesture ParseGesture(const std::string& as_string);

// Commands that can be triggered by switch activation.
enum SwitchAccessCommand {
  SWITCH_ACCESS_COMMAND_NONE,
  SWITCH_ACCESS_COMMAND_SELECT,
  SWITCH_ACCESS_COMMAND_NEXT,
  SWITCH_ACCESS_COMMAND_PREVIOUS,
  SWITCH_ACCESS_COMMAND_LAST = SWITCH_ACCESS_COMMAND_PREVIOUS,
};


const char* ToString(SwitchAccessCommand as_enum);
SwitchAccessCommand ParseSwitchAccessCommand(const std::string& as_string);

// Different Switch Access bubbles that can be shown or hidden.
enum SwitchAccessBubble {
  SWITCH_ACCESS_BUBBLE_NONE,
  SWITCH_ACCESS_BUBBLE_BACKBUTTON,
  SWITCH_ACCESS_BUBBLE_MENU,
  SWITCH_ACCESS_BUBBLE_LAST = SWITCH_ACCESS_BUBBLE_MENU,
};


const char* ToString(SwitchAccessBubble as_enum);
SwitchAccessBubble ParseSwitchAccessBubble(const std::string& as_string);

// Available actions to be shown in the Switch Access menu. Must be kept in sync
// with the strings in ash/system/accessibility/switch_access_menu_view.cc
enum SwitchAccessMenuAction {
  SWITCH_ACCESS_MENU_ACTION_NONE,
  SWITCH_ACCESS_MENU_ACTION_COPY,
  SWITCH_ACCESS_MENU_ACTION_CUT,
  SWITCH_ACCESS_MENU_ACTION_DECREMENT,
  SWITCH_ACCESS_MENU_ACTION_DICTATION,
  SWITCH_ACCESS_MENU_ACTION_ENDTEXTSELECTION,
  SWITCH_ACCESS_MENU_ACTION_INCREMENT,
  SWITCH_ACCESS_MENU_ACTION_JUMPTOBEGINNINGOFTEXT,
  SWITCH_ACCESS_MENU_ACTION_JUMPTOENDOFTEXT,
  SWITCH_ACCESS_MENU_ACTION_KEYBOARD,
  SWITCH_ACCESS_MENU_ACTION_MOVEBACKWARDONECHAROFTEXT,
  SWITCH_ACCESS_MENU_ACTION_MOVEBACKWARDONEWORDOFTEXT,
  SWITCH_ACCESS_MENU_ACTION_MOVECURSOR,
  SWITCH_ACCESS_MENU_ACTION_MOVEDOWNONELINEOFTEXT,
  SWITCH_ACCESS_MENU_ACTION_MOVEFORWARDONECHAROFTEXT,
  SWITCH_ACCESS_MENU_ACTION_MOVEFORWARDONEWORDOFTEXT,
  SWITCH_ACCESS_MENU_ACTION_MOVEUPONELINEOFTEXT,
  SWITCH_ACCESS_MENU_ACTION_PASTE,
  SWITCH_ACCESS_MENU_ACTION_SCROLLDOWN,
  SWITCH_ACCESS_MENU_ACTION_SCROLLLEFT,
  SWITCH_ACCESS_MENU_ACTION_SCROLLRIGHT,
  SWITCH_ACCESS_MENU_ACTION_SCROLLUP,
  SWITCH_ACCESS_MENU_ACTION_SELECT,
  SWITCH_ACCESS_MENU_ACTION_SETTINGS,
  SWITCH_ACCESS_MENU_ACTION_STARTTEXTSELECTION,
  SWITCH_ACCESS_MENU_ACTION_LAST = SWITCH_ACCESS_MENU_ACTION_STARTTEXTSELECTION,
};


const char* ToString(SwitchAccessMenuAction as_enum);
SwitchAccessMenuAction ParseSwitchAccessMenuAction(const std::string& as_string);

// The event to send
enum SyntheticKeyboardEventType {
  SYNTHETIC_KEYBOARD_EVENT_TYPE_NONE,
  SYNTHETIC_KEYBOARD_EVENT_TYPE_KEYUP,
  SYNTHETIC_KEYBOARD_EVENT_TYPE_KEYDOWN,
  SYNTHETIC_KEYBOARD_EVENT_TYPE_LAST = SYNTHETIC_KEYBOARD_EVENT_TYPE_KEYDOWN,
};


const char* ToString(SyntheticKeyboardEventType as_enum);
SyntheticKeyboardEventType ParseSyntheticKeyboardEventType(const std::string& as_string);

struct SyntheticKeyboardModifiers {
  SyntheticKeyboardModifiers();
  ~SyntheticKeyboardModifiers();
  SyntheticKeyboardModifiers(SyntheticKeyboardModifiers&& rhs);
  SyntheticKeyboardModifiers& operator=(SyntheticKeyboardModifiers&& rhs);

  // Populates a SyntheticKeyboardModifiers object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, SyntheticKeyboardModifiers* out);

  // Creates a SyntheticKeyboardModifiers object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<SyntheticKeyboardModifiers> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SyntheticKeyboardModifiers object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Control modifier.
  std::unique_ptr<bool> ctrl;

  // alt modifier.
  std::unique_ptr<bool> alt;

  // search modifier.
  std::unique_ptr<bool> search;

  // shift modifier.
  std::unique_ptr<bool> shift;


 private:
  DISALLOW_COPY_AND_ASSIGN(SyntheticKeyboardModifiers);
};

struct SyntheticKeyboardEvent {
  SyntheticKeyboardEvent();
  ~SyntheticKeyboardEvent();
  SyntheticKeyboardEvent(SyntheticKeyboardEvent&& rhs);
  SyntheticKeyboardEvent& operator=(SyntheticKeyboardEvent&& rhs);

  // Populates a SyntheticKeyboardEvent object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, SyntheticKeyboardEvent* out);

  // Creates a SyntheticKeyboardEvent object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<SyntheticKeyboardEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SyntheticKeyboardEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  SyntheticKeyboardEventType type;

  // Virtual key code, which is independent of the keyboard layout or modifier
  // state.
  int key_code;

  // Contains all active modifiers.
  std::unique_ptr<SyntheticKeyboardModifiers> modifiers;


 private:
  DISALLOW_COPY_AND_ASSIGN(SyntheticKeyboardEvent);
};

// The type of event to send
enum SyntheticMouseEventType {
  SYNTHETIC_MOUSE_EVENT_TYPE_NONE,
  SYNTHETIC_MOUSE_EVENT_TYPE_PRESS,
  SYNTHETIC_MOUSE_EVENT_TYPE_RELEASE,
  SYNTHETIC_MOUSE_EVENT_TYPE_DRAG,
  SYNTHETIC_MOUSE_EVENT_TYPE_MOVE,
  SYNTHETIC_MOUSE_EVENT_TYPE_ENTER,
  SYNTHETIC_MOUSE_EVENT_TYPE_EXIT,
  SYNTHETIC_MOUSE_EVENT_TYPE_LAST = SYNTHETIC_MOUSE_EVENT_TYPE_EXIT,
};


const char* ToString(SyntheticMouseEventType as_enum);
SyntheticMouseEventType ParseSyntheticMouseEventType(const std::string& as_string);

struct SyntheticMouseEvent {
  SyntheticMouseEvent();
  ~SyntheticMouseEvent();
  SyntheticMouseEvent(SyntheticMouseEvent&& rhs);
  SyntheticMouseEvent& operator=(SyntheticMouseEvent&& rhs);

  // Populates a SyntheticMouseEvent object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, SyntheticMouseEvent* out);

  // Creates a SyntheticMouseEvent object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<SyntheticMouseEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SyntheticMouseEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  SyntheticMouseEventType type;

  // X coordinate for mouse event in global screen coordinates
  int x;

  // Y coordinate for mouse event in global screen coordinates
  int y;


 private:
  DISALLOW_COPY_AND_ASSIGN(SyntheticMouseEvent);
};

// The state of the Select-to-Speak extension
enum SelectToSpeakState {
  SELECT_TO_SPEAK_STATE_NONE,
  SELECT_TO_SPEAK_STATE_SELECTING,
  SELECT_TO_SPEAK_STATE_SPEAKING,
  SELECT_TO_SPEAK_STATE_INACTIVE,
  SELECT_TO_SPEAK_STATE_LAST = SELECT_TO_SPEAK_STATE_INACTIVE,
};


const char* ToString(SelectToSpeakState as_enum);
SelectToSpeakState ParseSelectToSpeakState(const std::string& as_string);

// The type of visual appearance for the focus ring.
enum FocusType {
  FOCUS_TYPE_NONE,
  FOCUS_TYPE_GLOW,
  FOCUS_TYPE_SOLID,
  FOCUS_TYPE_DASHED,
  FOCUS_TYPE_LAST = FOCUS_TYPE_DASHED,
};


const char* ToString(FocusType as_enum);
FocusType ParseFocusType(const std::string& as_string);

struct FocusRingInfo {
  FocusRingInfo();
  ~FocusRingInfo();
  FocusRingInfo(FocusRingInfo&& rhs);
  FocusRingInfo& operator=(FocusRingInfo&& rhs);

  // Populates a FocusRingInfo object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, FocusRingInfo* out);

  // Creates a FocusRingInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<FocusRingInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this FocusRingInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Array of rectangles to draw the accessibility focus ring around.
  std::vector<ScreenRect> rects;

  // The FocusType for the ring.
  FocusType type;

  // A RGB hex-value color string (e.g. #3F8213) that describes the primary color
  // of the focus ring.
  std::string color;

  // A RGB hex-value color string (e.g. #3F82E4) that describes the secondary
  // color of the focus ring, if there is one.
  std::unique_ptr<std::string> secondary_color;

  // A RGB hex-value color string (e.g. #803F82E4) that describes the color drawn
  // outside of the focus ring and over the rest of the display.
  std::unique_ptr<std::string> background_color;

  // An identifier for this focus ring, unique within the extension.
  std::unique_ptr<std::string> id;


 private:
  DISALLOW_COPY_AND_ASSIGN(FocusRingInfo);
};


//
// Functions
//

namespace GetBatteryDescription {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& battery_description);
}  // namespace Results

}  // namespace GetBatteryDescription

namespace SetNativeAccessibilityEnabled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // True if native accessibility support should be enabled.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetNativeAccessibilityEnabled

namespace SetFocusRings {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Array of focus rings to draw.
  std::vector<FocusRingInfo> focus_rings;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetFocusRings

namespace SetHighlights {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Array of rectangles to draw the highlight around.
  std::vector<ScreenRect> rects;

  // CSS-style hex color string beginning with # like #FF9982 or #EEE.
  std::string color;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetHighlights

namespace SetKeyboardListener {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // True if the caller wants to listen to key events; false to stop listening to
  // events. Note that there is only ever one extension listening to key events.
  bool enabled;

  // True if key events should be swallowed natively and not propagated if
  // preventDefault() gets called by the extension's background page.
  bool capture;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetKeyboardListener

namespace DarkenScreen {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // True to darken screen; false to undarken screen.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace DarkenScreen

namespace ForwardKeyEventsToSwitchAccess {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool should_forward;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace ForwardKeyEventsToSwitchAccess

namespace UpdateSwitchAccessBubble {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Which bubble to show/hide
  SwitchAccessBubble bubble;

  // True if the bubble should be shown, false otherwise
  bool show;

  // A rectangle indicating the bounds of the object the menu should be displayed
  // next to.
  std::unique_ptr<ScreenRect> anchor;

  // The actions to be shown in the menu.
  std::unique_ptr<std::vector<SwitchAccessMenuAction>> actions;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace UpdateSwitchAccessBubble

namespace SetNativeChromeVoxArcSupportForCurrentApp {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // True for ChromeVox (native), false for TalkBack.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetNativeChromeVoxArcSupportForCurrentApp

namespace SendSyntheticKeyEvent {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The event to send.
  SyntheticKeyboardEvent key_event;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SendSyntheticKeyEvent

namespace EnableChromeVoxMouseEvents {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // True if ChromeVox should receive mouse events.
  bool enabled;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace EnableChromeVoxMouseEvents

namespace SendSyntheticMouseEvent {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The event to send.
  SyntheticMouseEvent mouse_event;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SendSyntheticMouseEvent

namespace OnSelectToSpeakStateChanged {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  SelectToSpeakState state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OnSelectToSpeakStateChanged

namespace OnScrollableBoundsForPointFound {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  ScreenRect rect;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OnScrollableBoundsForPointFound

namespace ToggleDictation {

}  // namespace ToggleDictation

namespace SetVirtualKeyboardVisible {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool is_visible;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetVirtualKeyboardVisible

namespace OpenSettingsSubpage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string subpage;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OpenSettingsSubpage

//
// Events
//

namespace OnIntroduceChromeVox {

extern const char kEventName[];  // "accessibilityPrivate.onIntroduceChromeVox"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnIntroduceChromeVox

namespace OnAccessibilityGesture {

extern const char kEventName[];  // "accessibilityPrivate.onAccessibilityGesture"

std::unique_ptr<base::ListValue> Create(const Gesture& gesture);
}  // namespace OnAccessibilityGesture

namespace OnTwoFingerTouchStart {

extern const char kEventName[];  // "accessibilityPrivate.onTwoFingerTouchStart"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnTwoFingerTouchStart

namespace OnTwoFingerTouchStop {

extern const char kEventName[];  // "accessibilityPrivate.onTwoFingerTouchStop"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnTwoFingerTouchStop

namespace OnSelectToSpeakStateChangeRequested {

extern const char kEventName[];  // "accessibilityPrivate.onSelectToSpeakStateChangeRequested"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnSelectToSpeakStateChangeRequested

namespace OnSwitchAccessCommand {

extern const char kEventName[];  // "accessibilityPrivate.onSwitchAccessCommand"

std::unique_ptr<base::ListValue> Create(const SwitchAccessCommand& command);
}  // namespace OnSwitchAccessCommand

namespace OnAnnounceForAccessibility {

extern const char kEventName[];  // "accessibilityPrivate.onAnnounceForAccessibility"

// Text to be announced.
std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& announce_text);
}  // namespace OnAnnounceForAccessibility

namespace FindScrollableBoundsForPoint {

extern const char kEventName[];  // "accessibilityPrivate.findScrollableBoundsForPoint"

// X screen coordinate of the point.
// Y screen coordinate of the point.
std::unique_ptr<base::ListValue> Create(double x, double y);
}  // namespace FindScrollableBoundsForPoint

namespace OnCustomSpokenFeedbackToggled {

extern const char kEventName[];  // "accessibilityPrivate.onCustomSpokenFeedbackToggled"

// True if the active window implements custom spoken feedback features.
std::unique_ptr<base::ListValue> Create(bool enabled);
}  // namespace OnCustomSpokenFeedbackToggled

}  // namespace accessibility_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_ACCESSIBILITY_PRIVATE_H__
