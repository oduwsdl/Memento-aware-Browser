// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/braille_display_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_BRAILLE_DISPLAY_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_BRAILLE_DISPLAY_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace braille_display_private {

//
// Types
//

// Braille display keyboard command.
enum KeyCommand {
  KEY_COMMAND_NONE,
  KEY_COMMAND_LINE_UP,
  KEY_COMMAND_LINE_DOWN,
  KEY_COMMAND_PAN_LEFT,
  KEY_COMMAND_PAN_RIGHT,
  KEY_COMMAND_TOP,
  KEY_COMMAND_BOTTOM,
  KEY_COMMAND_ROUTING,
  KEY_COMMAND_SECONDARY_ROUTING,
  KEY_COMMAND_DOTS,
  KEY_COMMAND_CHORD,
  KEY_COMMAND_STANDARD_KEY,
  KEY_COMMAND_LAST = KEY_COMMAND_STANDARD_KEY,
};


const char* ToString(KeyCommand as_enum);
KeyCommand ParseKeyCommand(const std::string& as_string);

struct KeyEvent {
  KeyEvent();
  ~KeyEvent();
  KeyEvent(KeyEvent&& rhs);
  KeyEvent& operator=(KeyEvent&& rhs);

  // Populates a KeyEvent object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, KeyEvent* out);

  // Creates a KeyEvent object from a base::Value, or NULL on failure.
  static std::unique_ptr<KeyEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this KeyEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  KeyCommand command;

  // 0-based display position for commands that involve a routing key.
  std::unique_ptr<int> display_position;

  // Braille dot keys that were pressed, stored in the low-order bits. Dot 1 is
  // stored in bit 0, dot2 in bit 1, etc.
  std::unique_ptr<int> braille_dots;

  // DOM keyboard event code.  This is present when command is standard_key and
  // the braille display event represents a non-alphanumeric key such as an arrow
  // key or function key. The value is as defined by the |code| property in
  // http://www.w3.org/TR/uievents/#keyboard-event-interface
  std::unique_ptr<std::string> standard_key_code;

  // DOM keyboard event character value.  This is present if the braille key event
  // corresponds to a character.
  std::unique_ptr<std::string> standard_key_char;

  // Whether the space key was pressed.
  std::unique_ptr<bool> space_key;

  // Whether the alt key was pressed.
  std::unique_ptr<bool> alt_key;

  // Whether the shift key was pressed.
  std::unique_ptr<bool> shift_key;

  // Whether the ctrl key was pressed.
  std::unique_ptr<bool> ctrl_key;


 private:
  DISALLOW_COPY_AND_ASSIGN(KeyEvent);
};

struct DisplayState {
  DisplayState();
  ~DisplayState();
  DisplayState(DisplayState&& rhs);
  DisplayState& operator=(DisplayState&& rhs);

  // Populates a DisplayState object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, DisplayState* out);

  // Creates a DisplayState object from a base::Value, or NULL on failure.
  static std::unique_ptr<DisplayState> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this DisplayState object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Whether a braille display is currently available.
  bool available;

  // Number of rows of braille cells on the currently connected display.
  std::unique_ptr<int> text_row_count;

  // Number of columns of braille cells on the currently connected display.
  std::unique_ptr<int> text_column_count;

  // The number of dots in a braille cell on the currently connected display.
  std::unique_ptr<int> cell_size;


 private:
  DISALLOW_COPY_AND_ASSIGN(DisplayState);
};


//
// Functions
//

namespace GetDisplayState {

namespace Results {

std::unique_ptr<base::ListValue> Create(const DisplayState& result);
}  // namespace Results

}  // namespace GetDisplayState

namespace WriteDots {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::vector<uint8_t> cells;

  int columns;

  int rows;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace WriteDots

namespace UpdateBluetoothBrailleDisplayAddress {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string address;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace UpdateBluetoothBrailleDisplayAddress

//
// Events
//

namespace OnDisplayStateChanged {

extern const char kEventName[];  // "brailleDisplayPrivate.onDisplayStateChanged"

std::unique_ptr<base::ListValue> Create(const DisplayState& state);
}  // namespace OnDisplayStateChanged

namespace OnKeyEvent {

extern const char kEventName[];  // "brailleDisplayPrivate.onKeyEvent"

std::unique_ptr<base::ListValue> Create(const KeyEvent& event);
}  // namespace OnKeyEvent

}  // namespace braille_display_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_BRAILLE_DISPLAY_PRIVATE_H__
