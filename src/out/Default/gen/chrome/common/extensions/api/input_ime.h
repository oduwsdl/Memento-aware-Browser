// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/input_ime.json
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_INPUT_IME_H__
#define CHROME_COMMON_EXTENSIONS_API_INPUT_IME_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace input_ime {

//
// Types
//

enum KeyboardEventType {
  KEYBOARD_EVENT_TYPE_NONE,
  KEYBOARD_EVENT_TYPE_KEYUP,
  KEYBOARD_EVENT_TYPE_KEYDOWN,
  KEYBOARD_EVENT_TYPE_LAST = KEYBOARD_EVENT_TYPE_KEYDOWN,
};


const char* ToString(KeyboardEventType as_enum);
KeyboardEventType ParseKeyboardEventType(const std::string& as_string);

// See http://www.w3.org/TR/DOM-Level-3-Events/#events-KeyboardEvent
struct KeyboardEvent {
  KeyboardEvent();
  ~KeyboardEvent();
  KeyboardEvent(KeyboardEvent&& rhs);
  KeyboardEvent& operator=(KeyboardEvent&& rhs);

  // Populates a KeyboardEvent object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, KeyboardEvent* out);

  // Creates a KeyboardEvent object from a base::Value, or NULL on failure.
  static std::unique_ptr<KeyboardEvent> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this KeyboardEvent object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // One of keyup or keydown.
  KeyboardEventType type;

  // (Deprecated) The ID of the request. Use the <code>requestId</code> param from
  // the <code>onKeyEvent</code> event instead.
  std::unique_ptr<std::string> request_id;

  // The extension ID of the sender of this keyevent.
  std::unique_ptr<std::string> extension_id;

  // Value of the key being pressed
  std::string key;

  // Value of the physical key being pressed. The value is not affected by current
  // keyboard layout or modifier state.
  std::string code;

  // The deprecated HTML keyCode, which is system- and implementation-dependent
  // numerical code signifying the unmodified identifier associated with the key
  // pressed.
  std::unique_ptr<int> key_code;

  // Whether or not the ALT key is pressed.
  std::unique_ptr<bool> alt_key;

  // Whether or not the ALTGR key is pressed.
  std::unique_ptr<bool> altgr_key;

  // Whether or not the CTRL key is pressed.
  std::unique_ptr<bool> ctrl_key;

  // Whether or not the SHIFT key is pressed.
  std::unique_ptr<bool> shift_key;

  // Whether or not the CAPS_LOCK is enabled.
  std::unique_ptr<bool> caps_lock;


 private:
  DISALLOW_COPY_AND_ASSIGN(KeyboardEvent);
};

// Type of value this text field edits, (Text, Number, URL, etc)
enum InputContextType {
  INPUT_CONTEXT_TYPE_NONE,
  INPUT_CONTEXT_TYPE_TEXT,
  INPUT_CONTEXT_TYPE_SEARCH,
  INPUT_CONTEXT_TYPE_TEL,
  INPUT_CONTEXT_TYPE_URL,
  INPUT_CONTEXT_TYPE_EMAIL,
  INPUT_CONTEXT_TYPE_NUMBER,
  INPUT_CONTEXT_TYPE_PASSWORD,
  INPUT_CONTEXT_TYPE_NULL,
  INPUT_CONTEXT_TYPE_LAST = INPUT_CONTEXT_TYPE_NULL,
};


const char* ToString(InputContextType as_enum);
InputContextType ParseInputContextType(const std::string& as_string);

// The auto-capitalize type of the text field.
enum AutoCapitalizeType {
  AUTO_CAPITALIZE_TYPE_NONE,
  AUTO_CAPITALIZE_TYPE_CHARACTERS,
  AUTO_CAPITALIZE_TYPE_WORDS,
  AUTO_CAPITALIZE_TYPE_SENTENCES,
  AUTO_CAPITALIZE_TYPE_LAST = AUTO_CAPITALIZE_TYPE_SENTENCES,
};


const char* ToString(AutoCapitalizeType as_enum);
AutoCapitalizeType ParseAutoCapitalizeType(const std::string& as_string);

// Describes an input Context
struct InputContext {
  InputContext();
  ~InputContext();
  InputContext(InputContext&& rhs);
  InputContext& operator=(InputContext&& rhs);

  // Populates a InputContext object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, InputContext* out);

  // Creates a InputContext object from a base::Value, or NULL on failure.
  static std::unique_ptr<InputContext> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this InputContext object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // This is used to specify targets of text field operations.  This ID becomes
  // invalid as soon as onBlur is called.
  int context_id;

  // Type of value this text field edits, (Text, Number, URL, etc)
  InputContextType type;

  // Whether the text field wants auto-correct.
  bool auto_correct;

  // Whether the text field wants auto-complete.
  bool auto_complete;

  // The auto-capitalize type of the text field.
  AutoCapitalizeType auto_capitalize;

  // Whether the text field wants spell-check.
  bool spell_check;

  // Whether text entered into the text field should be used to improve typing
  // suggestions for the user.
  bool should_do_learning;


 private:
  DISALLOW_COPY_AND_ASSIGN(InputContext);
};

// The type of menu item. Radio buttons between separators are considered
// grouped.
enum MenuItemStyle {
  MENU_ITEM_STYLE_NONE,
  MENU_ITEM_STYLE_CHECK,
  MENU_ITEM_STYLE_RADIO,
  MENU_ITEM_STYLE_SEPARATOR,
  MENU_ITEM_STYLE_LAST = MENU_ITEM_STYLE_SEPARATOR,
};


const char* ToString(MenuItemStyle as_enum);
MenuItemStyle ParseMenuItemStyle(const std::string& as_string);

// A menu item used by an input method to interact with the user from the
// language menu.
struct MenuItem {
  MenuItem();
  ~MenuItem();
  MenuItem(MenuItem&& rhs);
  MenuItem& operator=(MenuItem&& rhs);

  // Populates a MenuItem object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, MenuItem* out);

  // Creates a MenuItem object from a base::Value, or NULL on failure.
  static std::unique_ptr<MenuItem> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MenuItem object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // String that will be passed to callbacks referencing this MenuItem.
  std::string id;

  // Text displayed in the menu for this item.
  std::unique_ptr<std::string> label;

  // The type of menu item.
  MenuItemStyle style;

  // Indicates this item is visible.
  std::unique_ptr<bool> visible;

  // Indicates this item should be drawn with a check.
  std::unique_ptr<bool> checked;

  // Indicates this item is enabled.
  std::unique_ptr<bool> enabled;


 private:
  DISALLOW_COPY_AND_ASSIGN(MenuItem);
};

// The type of the underline to modify this segment.
enum UnderlineStyle {
  UNDERLINE_STYLE_NONE,
  UNDERLINE_STYLE_UNDERLINE,
  UNDERLINE_STYLE_DOUBLEUNDERLINE,
  UNDERLINE_STYLE_NOUNDERLINE,
  UNDERLINE_STYLE_LAST = UNDERLINE_STYLE_NOUNDERLINE,
};


const char* ToString(UnderlineStyle as_enum);
UnderlineStyle ParseUnderlineStyle(const std::string& as_string);

// Where to display the candidate window. If set to 'cursor', the window follows
// the cursor. If set to 'composition', the window is locked to the beginning of
// the composition.
enum WindowPosition {
  WINDOW_POSITION_NONE,
  WINDOW_POSITION_CURSOR,
  WINDOW_POSITION_COMPOSITION,
  WINDOW_POSITION_LAST = WINDOW_POSITION_COMPOSITION,
};


const char* ToString(WindowPosition as_enum);
WindowPosition ParseWindowPosition(const std::string& as_string);

// The screen type under which the IME is activated.
enum ScreenType {
  SCREEN_TYPE_NONE,
  SCREEN_TYPE_NORMAL,
  SCREEN_TYPE_LOGIN,
  SCREEN_TYPE_LOCK,
  SCREEN_TYPE_SECONDARY_LOGIN,
  SCREEN_TYPE_LAST = SCREEN_TYPE_SECONDARY_LOGIN,
};


const char* ToString(ScreenType as_enum);
ScreenType ParseScreenType(const std::string& as_string);

// Which mouse buttons was clicked.
enum MouseButton {
  MOUSE_BUTTON_NONE,
  MOUSE_BUTTON_LEFT,
  MOUSE_BUTTON_MIDDLE,
  MOUSE_BUTTON_RIGHT,
  MOUSE_BUTTON_LAST = MOUSE_BUTTON_RIGHT,
};


const char* ToString(MouseButton as_enum);
MouseButton ParseMouseButton(const std::string& as_string);

// Type of assistive window.
enum AssistiveWindowType {
  ASSISTIVE_WINDOW_TYPE_NONE,
  ASSISTIVE_WINDOW_TYPE_UNDO,
  ASSISTIVE_WINDOW_TYPE_LAST = ASSISTIVE_WINDOW_TYPE_UNDO,
};


const char* ToString(AssistiveWindowType as_enum);
AssistiveWindowType ParseAssistiveWindowType(const std::string& as_string);

// Properties of the assistive window.
struct AssistiveWindowProperties {
  AssistiveWindowProperties();
  ~AssistiveWindowProperties();
  AssistiveWindowProperties(AssistiveWindowProperties&& rhs);
  AssistiveWindowProperties& operator=(AssistiveWindowProperties&& rhs);

  // Populates a AssistiveWindowProperties object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, AssistiveWindowProperties* out);

  // Creates a AssistiveWindowProperties object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<AssistiveWindowProperties> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this AssistiveWindowProperties object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  AssistiveWindowType type;

  // Sets true to show AssistiveWindow, sets false to hide.
  bool visible;

  // Strings for ChromeVox to announce.
  std::unique_ptr<std::string> announce_string;


 private:
  DISALLOW_COPY_AND_ASSIGN(AssistiveWindowProperties);
};

// ID of buttons in assistive window.
enum AssistiveWindowButton {
  ASSISTIVE_WINDOW_BUTTON_NONE,
  ASSISTIVE_WINDOW_BUTTON_UNDO,
  ASSISTIVE_WINDOW_BUTTON_ADDTODICTIONARY,
  ASSISTIVE_WINDOW_BUTTON_LAST = ASSISTIVE_WINDOW_BUTTON_ADDTODICTIONARY,
};


const char* ToString(AssistiveWindowButton as_enum);
AssistiveWindowButton ParseAssistiveWindowButton(const std::string& as_string);


//
// Functions
//

namespace SetComposition {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    struct SegmentsType {
      SegmentsType();
      ~SegmentsType();
      SegmentsType(SegmentsType&& rhs);
      SegmentsType& operator=(SegmentsType&& rhs);

      // Populates a SegmentsType object from a base::Value. Returns whether |out|
      // was successfully populated.
      static bool Populate(const base::Value& value, SegmentsType* out);

      // Index of the character to start this segment at
      int start;

      // Index of the character to end this segment after.
      int end;

      // The type of the underline to modify this segment.
      UnderlineStyle style;


     private:
      DISALLOW_COPY_AND_ASSIGN(SegmentsType);
    };



    // ID of the context where the composition text will be set
    int context_id;

    // Text to set
    std::string text;

    // Position in the text that the selection starts at.
    std::unique_ptr<int> selection_start;

    // Position in the text that the selection ends at.
    std::unique_ptr<int> selection_end;

    // Position in the text of the cursor.
    int cursor;

    // List of segments and their associated types.
    std::unique_ptr<std::vector<SegmentsType>> segments;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetComposition

namespace ClearComposition {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the context where the composition will be cleared
    int context_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace ClearComposition

namespace CommitText {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the context where the text will be committed
    int context_id;

    // The text to commit
    std::string text;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace CommitText

namespace SendKeyEvents {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the context where the key events will be sent, or zero to send key
    // events to non-input field.
    int context_id;

    // Data on the key event.
    std::vector<KeyboardEvent> key_data;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SendKeyEvents

namespace HideInputView {

}  // namespace HideInputView

namespace SetCandidateWindowProperties {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    struct Properties {
      Properties();
      ~Properties();
      Properties(Properties&& rhs);
      Properties& operator=(Properties&& rhs);

      // Populates a Properties object from a base::Value. Returns whether |out| was
      // successfully populated.
      static bool Populate(const base::Value& value, Properties* out);

      // True to show the Candidate window, false to hide it.
      std::unique_ptr<bool> visible;

      // True to show the cursor, false to hide it.
      std::unique_ptr<bool> cursor_visible;

      // True if the candidate window should be rendered vertical, false to make it
      // horizontal.
      std::unique_ptr<bool> vertical;

      // The number of candidates to display per page.
      std::unique_ptr<int> page_size;

      // Text that is shown at the bottom of the candidate window.
      std::unique_ptr<std::string> auxiliary_text;

      // True to display the auxiliary text, false to hide it.
      std::unique_ptr<bool> auxiliary_text_visible;

      // The total number of candidates for the candidate window.
      std::unique_ptr<int> total_candidates;

      // The index of the current chosen candidate out of total candidates.
      std::unique_ptr<int> current_candidate_index;

      // Where to display the candidate window.
      WindowPosition window_position;


     private:
      DISALLOW_COPY_AND_ASSIGN(Properties);
    };


    // ID of the engine to set properties on.
    std::string engine_id;

    Properties properties;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetCandidateWindowProperties

namespace SetCandidates {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    struct CandidatesType {
      CandidatesType();
      ~CandidatesType();
      CandidatesType(CandidatesType&& rhs);
      CandidatesType& operator=(CandidatesType&& rhs);

      // Populates a CandidatesType object from a base::Value. Returns whether |out|
      // was successfully populated.
      static bool Populate(const base::Value& value, CandidatesType* out);

      // The usage or detail description of word.
      struct Usage {
        Usage();
        ~Usage();
        Usage(Usage&& rhs);
        Usage& operator=(Usage&& rhs);

        // Populates a Usage object from a base::Value. Returns whether |out| was
        // successfully populated.
        static bool Populate(const base::Value& value, Usage* out);

        // The title string of details description.
        std::string title;

        // The body string of detail description.
        std::string body;


       private:
        DISALLOW_COPY_AND_ASSIGN(Usage);
      };


      // The candidate
      std::string candidate;

      // The candidate's id
      int id;

      // The id to add these candidates under
      std::unique_ptr<int> parent_id;

      // Short string displayed to next to the candidate, often the shortcut key or
      // index
      std::unique_ptr<std::string> label;

      // Additional text describing the candidate
      std::unique_ptr<std::string> annotation;

      // The usage or detail description of word.
      std::unique_ptr<Usage> usage;


     private:
      DISALLOW_COPY_AND_ASSIGN(CandidatesType);
    };



    // ID of the context that owns the candidate window.
    int context_id;

    // List of candidates to show in the candidate window
    std::vector<CandidatesType> candidates;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetCandidates

namespace SetCursorPosition {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the context that owns the candidate window.
    int context_id;

    // ID of the candidate to select.
    int candidate_id;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetCursorPosition

namespace SetAssistiveWindowProperties {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the context owning the assistive window.
    int context_id;

    // Properties of the assistive window.
    AssistiveWindowProperties properties;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(bool success);
}  // namespace Results

}  // namespace SetAssistiveWindowProperties

namespace SetMenuItems {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the engine to use
    std::string engine_id;

    // MenuItems to add. They will be added in the order they exist in the array.
    std::vector<MenuItem> items;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace SetMenuItems

namespace UpdateMenuItems {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the engine to use
    std::string engine_id;

    // Array of MenuItems to update
    std::vector<MenuItem> items;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace UpdateMenuItems

namespace DeleteSurroundingText {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  struct Parameters {
    Parameters();
    ~Parameters();
    Parameters(Parameters&& rhs);
    Parameters& operator=(Parameters&& rhs);

    // Populates a Parameters object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Parameters* out);

    // ID of the engine receiving the event.
    std::string engine_id;

    // ID of the context where the surrounding text will be deleted.
    int context_id;

    // The offset from the caret position where deletion will start. This value can
    // be negative.
    int offset;

    // The number of characters to be deleted
    int length;


   private:
    DISALLOW_COPY_AND_ASSIGN(Parameters);
  };


  Parameters parameters;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace DeleteSurroundingText

namespace KeyEventHandled {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Request id of the event that was handled.  This should come from
  // keyEvent.requestId
  std::string request_id;

  // True if the keystroke was handled, false if not
  bool response;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace KeyEventHandled

//
// Events
//

namespace OnActivate {

extern const char kEventName[];  // "input.ime.onActivate"

// ID of the engine receiving the event
// The screen type under which the IME is activated.
std::unique_ptr<base::ListValue> Create(const std::string& engine_id, const ScreenType& screen);
}  // namespace OnActivate

namespace OnDeactivated {

extern const char kEventName[];  // "input.ime.onDeactivated"

// ID of the engine receiving the event
std::unique_ptr<base::ListValue> Create(const std::string& engine_id);
}  // namespace OnDeactivated

namespace OnFocus {

extern const char kEventName[];  // "input.ime.onFocus"

// Describes the text field that has acquired focus.
std::unique_ptr<base::ListValue> Create(const InputContext& context);
}  // namespace OnFocus

namespace OnBlur {

extern const char kEventName[];  // "input.ime.onBlur"

// The ID of the text field that has lost focus. The ID is invalid after this
// call
std::unique_ptr<base::ListValue> Create(int context_id);
}  // namespace OnBlur

namespace OnInputContextUpdate {

extern const char kEventName[];  // "input.ime.onInputContextUpdate"

// An InputContext object describing the text field that has changed.
std::unique_ptr<base::ListValue> Create(const InputContext& context);
}  // namespace OnInputContextUpdate

namespace OnKeyEvent {

extern const char kEventName[];  // "input.ime.onKeyEvent"

// ID of the engine receiving the event
// Data on the key event
// ID of the request. If the event listener returns undefined, then
// <code>keyEventHandled</code> must be called later with this
// <code>requestId</code>.
std::unique_ptr<base::ListValue> Create(const std::string& engine_id, const KeyboardEvent& key_data, const std::string& request_id);
}  // namespace OnKeyEvent

namespace OnCandidateClicked {

extern const char kEventName[];  // "input.ime.onCandidateClicked"

// ID of the engine receiving the event
// ID of the candidate that was clicked.
// Which mouse buttons was clicked.
std::unique_ptr<base::ListValue> Create(const std::string& engine_id, int candidate_id, const MouseButton& button);
}  // namespace OnCandidateClicked

namespace OnMenuItemActivated {

extern const char kEventName[];  // "input.ime.onMenuItemActivated"

// ID of the engine receiving the event
// Name of the MenuItem which was activated
std::unique_ptr<base::ListValue> Create(const std::string& engine_id, const std::string& name);
}  // namespace OnMenuItemActivated

namespace OnSurroundingTextChanged {

extern const char kEventName[];  // "input.ime.onSurroundingTextChanged"

// The surrounding information.
struct SurroundingInfo {
  SurroundingInfo();
  ~SurroundingInfo();
  SurroundingInfo(SurroundingInfo&& rhs);
  SurroundingInfo& operator=(SurroundingInfo&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this SurroundingInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The text around the cursor. This is only a subset of all text in the input
  // field.
  std::string text;

  // The ending position of the selection. This value indicates caret position if
  // there is no selection.
  int focus;

  // The beginning position of the selection. This value indicates caret position
  // if there is no selection.
  int anchor;

  // The offset position of <code>text</code>. Since <code>text</code> only
  // includes a subset of text around the cursor, offset indicates the absolute
  // position of the first character of <code>text</code>.
  int offset;


 private:
  DISALLOW_COPY_AND_ASSIGN(SurroundingInfo);
};


// ID of the engine receiving the event
// The surrounding information.
std::unique_ptr<base::ListValue> Create(const std::string& engine_id, const SurroundingInfo& surrounding_info);
}  // namespace OnSurroundingTextChanged

namespace OnReset {

extern const char kEventName[];  // "input.ime.onReset"

// ID of the engine receiving the event
std::unique_ptr<base::ListValue> Create(const std::string& engine_id);
}  // namespace OnReset

namespace OnAssistiveWindowButtonClicked {

extern const char kEventName[];  // "input.ime.onAssistiveWindowButtonClicked"

struct Details {
  Details();
  ~Details();
  Details(Details&& rhs);
  Details& operator=(Details&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Details object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The ID of the button clicked.
  AssistiveWindowButton button_id;

  // The type of the assistive window.
  AssistiveWindowType window_type;


 private:
  DISALLOW_COPY_AND_ASSIGN(Details);
};


std::unique_ptr<base::ListValue> Create(const Details& details);
}  // namespace OnAssistiveWindowButtonClicked

}  // namespace input_ime
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_INPUT_IME_H__
