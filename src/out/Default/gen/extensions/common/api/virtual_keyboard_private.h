// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/virtual_keyboard_private.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_VIRTUAL_KEYBOARD_PRIVATE_H__
#define EXTENSIONS_COMMON_API_VIRTUAL_KEYBOARD_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace virtual_keyboard_private {

//
// Types
//

// One of keyup or keydown.
enum VirtualKeyboardEventType {
  VIRTUAL_KEYBOARD_EVENT_TYPE_NONE,
  VIRTUAL_KEYBOARD_EVENT_TYPE_KEYUP,
  VIRTUAL_KEYBOARD_EVENT_TYPE_KEYDOWN,
  VIRTUAL_KEYBOARD_EVENT_TYPE_LAST = VIRTUAL_KEYBOARD_EVENT_TYPE_KEYDOWN,
};


const char* ToString(VirtualKeyboardEventType as_enum);
VirtualKeyboardEventType ParseVirtualKeyboardEventType(const std::string& as_string);

struct VirtualKeyboardEvent {
  VirtualKeyboardEvent();
  ~VirtualKeyboardEvent();
  VirtualKeyboardEvent(VirtualKeyboardEvent&& rhs);
  VirtualKeyboardEvent& operator=(VirtualKeyboardEvent&& rhs);

  // Populates a VirtualKeyboardEvent object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, VirtualKeyboardEvent* out);

  // Creates a VirtualKeyboardEvent object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<VirtualKeyboardEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this VirtualKeyboardEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  VirtualKeyboardEventType type;

  // Unicode value of the key.
  int char_value;

  // Virtual key code, which is independent of the keyboard layout or modifier
  // state.
  int key_code;

  // Name of the key, which is independent of modifier state.
  std::string key_name;

  // Flag for modifiers that are active. None = 0, Shift = 2, Control = 4, Alt =
  // 8.
  std::unique_ptr<int> modifiers;


 private:
  DISALLOW_COPY_AND_ASSIGN(VirtualKeyboardEvent);
};

// The value of the virtual keyboard mode to set to.
enum KeyboardMode {
  KEYBOARD_MODE_NONE,
  KEYBOARD_MODE_FULL_WIDTH,
  KEYBOARD_MODE_FLOATING,
  KEYBOARD_MODE_LAST = KEYBOARD_MODE_FLOATING,
};


const char* ToString(KeyboardMode as_enum);
KeyboardMode ParseKeyboardMode(const std::string& as_string);

// The value of the virtual keyboard state to change to.
enum KeyboardState {
  KEYBOARD_STATE_NONE,
  KEYBOARD_STATE_ENABLED,
  KEYBOARD_STATE_DISABLED,
  KEYBOARD_STATE_AUTO,
  KEYBOARD_STATE_LAST = KEYBOARD_STATE_AUTO,
};


const char* ToString(KeyboardState as_enum);
KeyboardState ParseKeyboardState(const std::string& as_string);

struct Bounds {
  Bounds();
  ~Bounds();
  Bounds(Bounds&& rhs);
  Bounds& operator=(Bounds&& rhs);

  // Populates a Bounds object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Bounds* out);

  // Creates a Bounds object from a base::Value, or NULL on failure.
  static std::unique_ptr<Bounds> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Bounds object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The position of the virtual keyboard window's left edge.
  int left;

  // The position of the virtual keyboard window's top edge.
  int top;

  // The width of the virtual keyboard window.
  int width;

  // The height of the virtual keyboard window.
  int height;


 private:
  DISALLOW_COPY_AND_ASSIGN(Bounds);
};

struct KeyboardConfig {
  KeyboardConfig();
  ~KeyboardConfig();
  KeyboardConfig(KeyboardConfig&& rhs);
  KeyboardConfig& operator=(KeyboardConfig&& rhs);

  // Populates a KeyboardConfig object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, KeyboardConfig* out);

  // Creates a KeyboardConfig object from a base::Value, or NULL on failure.
  static std::unique_ptr<KeyboardConfig> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this KeyboardConfig object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Virtual keyboard layout string.
  std::string layout;

  // Virtual keyboard is in hotrod mode.
  bool hotrodmode;

  // True if accessibility virtual keyboard is enabled.
  bool a11ymode;

  // List of experimental feature flags.
  std::vector<std::string> features;


 private:
  DISALLOW_COPY_AND_ASSIGN(KeyboardConfig);
};

struct ContainerBehaviorOptions {
  ContainerBehaviorOptions();
  ~ContainerBehaviorOptions();
  ContainerBehaviorOptions(ContainerBehaviorOptions&& rhs);
  ContainerBehaviorOptions& operator=(ContainerBehaviorOptions&& rhs);

  // Populates a ContainerBehaviorOptions object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ContainerBehaviorOptions* out);

  // Creates a ContainerBehaviorOptions object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ContainerBehaviorOptions> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ContainerBehaviorOptions object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The value of the virtual keyboard mode to set to.
  KeyboardMode mode;

  // The bounds of the virtual keyboard after changing mode
  Bounds bounds;


 private:
  DISALLOW_COPY_AND_ASSIGN(ContainerBehaviorOptions);
};


//
// Functions
//

namespace InsertText {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The text that will be inserted.
  std::string text;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace InsertText

namespace SendKeyEvent {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  VirtualKeyboardEvent key_event;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SendKeyEvent

namespace HideKeyboard {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace HideKeyboard

namespace SetHotrodKeyboard {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool enable;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetHotrodKeyboard

namespace LockKeyboard {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool lock;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace LockKeyboard

namespace KeyboardLoaded {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace KeyboardLoaded

namespace GetKeyboardConfig {

namespace Results {

std::unique_ptr<base::ListValue> Create(const KeyboardConfig& config);
}  // namespace Results

}  // namespace GetKeyboardConfig

namespace OpenSettings {

}  // namespace OpenSettings

namespace SetContainerBehavior {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Optional parameters for new container behavior.
  ContainerBehaviorOptions options;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Whether the container mode changed successfully
std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetContainerBehavior

namespace SetDraggableArea {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The value of draggable rect area of floating keyboard.
  Bounds bounds;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetDraggableArea

namespace SetKeyboardState {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The value of the virtual keyboard state to change to.
  KeyboardState state;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetKeyboardState

namespace SetOccludedBounds {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // List of rectangles representing regions occluded by the keyboard.
  std::vector<Bounds> bounds_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetOccludedBounds

namespace SetHitTestBounds {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // List of rectangles representing regions where events targeting the keyboard
  // should be handled.
  std::vector<Bounds> bounds_list;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetHitTestBounds

namespace SetAreaToRemainOnScreen {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The bounds of the area inside the keyboard window, relative to the window
  // origin, that should not be moved off screen. Any area outside of this bounds
  // can be moved off screen.
  Bounds bounds;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetAreaToRemainOnScreen

namespace SetWindowBoundsInScreen {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // A rectangle defining the new bounds of the window in screen coordinates.
  Bounds bounds;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace SetWindowBoundsInScreen

//
// Events
//

namespace OnBoundsChanged {

extern const char kEventName[];  // "virtualKeyboardPrivate.onBoundsChanged"

// The virtual keyboard bounds
std::unique_ptr<base::ListValue> Create(const Bounds& bounds);
}  // namespace OnBoundsChanged

namespace OnKeyboardClosed {

extern const char kEventName[];  // "virtualKeyboardPrivate.onKeyboardClosed"

std::unique_ptr<base::ListValue> Create();
}  // namespace OnKeyboardClosed

namespace OnKeyboardConfigChanged {

extern const char kEventName[];  // "virtualKeyboardPrivate.onKeyboardConfigChanged"

// The virtual keyboard config
std::unique_ptr<base::ListValue> Create(const KeyboardConfig& config);
}  // namespace OnKeyboardConfigChanged

}  // namespace virtual_keyboard_private
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_VIRTUAL_KEYBOARD_PRIVATE_H__
