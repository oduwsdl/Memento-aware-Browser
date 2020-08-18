// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/accessibility_private.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/accessibility_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace accessibility_private {
//
// Types
//

AlertInfo::AlertInfo()
 {}

AlertInfo::~AlertInfo() {}
AlertInfo::AlertInfo(AlertInfo&& rhs)
: message(std::move(rhs.message)){
}

AlertInfo& AlertInfo::operator=(AlertInfo&& rhs)
{
message = std::move(rhs.message);
return *this;
}

// static
bool AlertInfo::Populate(
    const base::Value& value, AlertInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* message_value = NULL;
  if (!dict->GetWithoutPathExpansion("message", &message_value)) {
    return false;
  }
  {
    if (!message_value->GetAsString(&out->message)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AlertInfo> AlertInfo::FromValue(const base::Value& value) {
  std::unique_ptr<AlertInfo> out(new AlertInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AlertInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("message", std::make_unique<base::Value>(this->message));


  return to_value_result;
}


ScreenRect::ScreenRect()
: left(0),
top(0),
width(0),
height(0) {}

ScreenRect::~ScreenRect() {}
ScreenRect::ScreenRect(ScreenRect&& rhs)
: left(rhs.left),
top(rhs.top),
width(rhs.width),
height(rhs.height){
}

ScreenRect& ScreenRect::operator=(ScreenRect&& rhs)
{
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
return *this;
}

// static
bool ScreenRect::Populate(
    const base::Value& value, ScreenRect* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* left_value = NULL;
  if (!dict->GetWithoutPathExpansion("left", &left_value)) {
    return false;
  }
  {
    if (!left_value->GetAsInteger(&out->left)) {
      return false;
    }
  }

  const base::Value* top_value = NULL;
  if (!dict->GetWithoutPathExpansion("top", &top_value)) {
    return false;
  }
  {
    if (!top_value->GetAsInteger(&out->top)) {
      return false;
    }
  }

  const base::Value* width_value = NULL;
  if (!dict->GetWithoutPathExpansion("width", &width_value)) {
    return false;
  }
  {
    if (!width_value->GetAsInteger(&out->width)) {
      return false;
    }
  }

  const base::Value* height_value = NULL;
  if (!dict->GetWithoutPathExpansion("height", &height_value)) {
    return false;
  }
  {
    if (!height_value->GetAsInteger(&out->height)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ScreenRect> ScreenRect::FromValue(const base::Value& value) {
  std::unique_ptr<ScreenRect> out(new ScreenRect());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ScreenRect::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));


  return to_value_result;
}


const char* ToString(Gesture enum_param) {
  switch (enum_param) {
    case GESTURE_CLICK:
      return "click";
    case GESTURE_SWIPELEFT1:
      return "swipeLeft1";
    case GESTURE_SWIPEUP1:
      return "swipeUp1";
    case GESTURE_SWIPERIGHT1:
      return "swipeRight1";
    case GESTURE_SWIPEDOWN1:
      return "swipeDown1";
    case GESTURE_SWIPELEFT2:
      return "swipeLeft2";
    case GESTURE_SWIPEUP2:
      return "swipeUp2";
    case GESTURE_SWIPERIGHT2:
      return "swipeRight2";
    case GESTURE_SWIPEDOWN2:
      return "swipeDown2";
    case GESTURE_SWIPELEFT3:
      return "swipeLeft3";
    case GESTURE_SWIPEUP3:
      return "swipeUp3";
    case GESTURE_SWIPERIGHT3:
      return "swipeRight3";
    case GESTURE_SWIPEDOWN3:
      return "swipeDown3";
    case GESTURE_SWIPELEFT4:
      return "swipeLeft4";
    case GESTURE_SWIPEUP4:
      return "swipeUp4";
    case GESTURE_SWIPERIGHT4:
      return "swipeRight4";
    case GESTURE_SWIPEDOWN4:
      return "swipeDown4";
    case GESTURE_TAP2:
      return "tap2";
    case GESTURE_TAP3:
      return "tap3";
    case GESTURE_TAP4:
      return "tap4";
    case GESTURE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Gesture ParseGesture(const std::string& enum_string) {
  if (enum_string == "click")
    return GESTURE_CLICK;
  if (enum_string == "swipeLeft1")
    return GESTURE_SWIPELEFT1;
  if (enum_string == "swipeUp1")
    return GESTURE_SWIPEUP1;
  if (enum_string == "swipeRight1")
    return GESTURE_SWIPERIGHT1;
  if (enum_string == "swipeDown1")
    return GESTURE_SWIPEDOWN1;
  if (enum_string == "swipeLeft2")
    return GESTURE_SWIPELEFT2;
  if (enum_string == "swipeUp2")
    return GESTURE_SWIPEUP2;
  if (enum_string == "swipeRight2")
    return GESTURE_SWIPERIGHT2;
  if (enum_string == "swipeDown2")
    return GESTURE_SWIPEDOWN2;
  if (enum_string == "swipeLeft3")
    return GESTURE_SWIPELEFT3;
  if (enum_string == "swipeUp3")
    return GESTURE_SWIPEUP3;
  if (enum_string == "swipeRight3")
    return GESTURE_SWIPERIGHT3;
  if (enum_string == "swipeDown3")
    return GESTURE_SWIPEDOWN3;
  if (enum_string == "swipeLeft4")
    return GESTURE_SWIPELEFT4;
  if (enum_string == "swipeUp4")
    return GESTURE_SWIPEUP4;
  if (enum_string == "swipeRight4")
    return GESTURE_SWIPERIGHT4;
  if (enum_string == "swipeDown4")
    return GESTURE_SWIPEDOWN4;
  if (enum_string == "tap2")
    return GESTURE_TAP2;
  if (enum_string == "tap3")
    return GESTURE_TAP3;
  if (enum_string == "tap4")
    return GESTURE_TAP4;
  return GESTURE_NONE;
}


const char* ToString(SwitchAccessCommand enum_param) {
  switch (enum_param) {
    case SWITCH_ACCESS_COMMAND_SELECT:
      return "select";
    case SWITCH_ACCESS_COMMAND_NEXT:
      return "next";
    case SWITCH_ACCESS_COMMAND_PREVIOUS:
      return "previous";
    case SWITCH_ACCESS_COMMAND_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SwitchAccessCommand ParseSwitchAccessCommand(const std::string& enum_string) {
  if (enum_string == "select")
    return SWITCH_ACCESS_COMMAND_SELECT;
  if (enum_string == "next")
    return SWITCH_ACCESS_COMMAND_NEXT;
  if (enum_string == "previous")
    return SWITCH_ACCESS_COMMAND_PREVIOUS;
  return SWITCH_ACCESS_COMMAND_NONE;
}


const char* ToString(SwitchAccessBubble enum_param) {
  switch (enum_param) {
    case SWITCH_ACCESS_BUBBLE_BACKBUTTON:
      return "backButton";
    case SWITCH_ACCESS_BUBBLE_MENU:
      return "menu";
    case SWITCH_ACCESS_BUBBLE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SwitchAccessBubble ParseSwitchAccessBubble(const std::string& enum_string) {
  if (enum_string == "backButton")
    return SWITCH_ACCESS_BUBBLE_BACKBUTTON;
  if (enum_string == "menu")
    return SWITCH_ACCESS_BUBBLE_MENU;
  return SWITCH_ACCESS_BUBBLE_NONE;
}


const char* ToString(SwitchAccessMenuAction enum_param) {
  switch (enum_param) {
    case SWITCH_ACCESS_MENU_ACTION_COPY:
      return "copy";
    case SWITCH_ACCESS_MENU_ACTION_CUT:
      return "cut";
    case SWITCH_ACCESS_MENU_ACTION_DECREMENT:
      return "decrement";
    case SWITCH_ACCESS_MENU_ACTION_DICTATION:
      return "dictation";
    case SWITCH_ACCESS_MENU_ACTION_ENDTEXTSELECTION:
      return "endTextSelection";
    case SWITCH_ACCESS_MENU_ACTION_INCREMENT:
      return "increment";
    case SWITCH_ACCESS_MENU_ACTION_JUMPTOBEGINNINGOFTEXT:
      return "jumpToBeginningOfText";
    case SWITCH_ACCESS_MENU_ACTION_JUMPTOENDOFTEXT:
      return "jumpToEndOfText";
    case SWITCH_ACCESS_MENU_ACTION_KEYBOARD:
      return "keyboard";
    case SWITCH_ACCESS_MENU_ACTION_MOVEBACKWARDONECHAROFTEXT:
      return "moveBackwardOneCharOfText";
    case SWITCH_ACCESS_MENU_ACTION_MOVEBACKWARDONEWORDOFTEXT:
      return "moveBackwardOneWordOfText";
    case SWITCH_ACCESS_MENU_ACTION_MOVECURSOR:
      return "moveCursor";
    case SWITCH_ACCESS_MENU_ACTION_MOVEDOWNONELINEOFTEXT:
      return "moveDownOneLineOfText";
    case SWITCH_ACCESS_MENU_ACTION_MOVEFORWARDONECHAROFTEXT:
      return "moveForwardOneCharOfText";
    case SWITCH_ACCESS_MENU_ACTION_MOVEFORWARDONEWORDOFTEXT:
      return "moveForwardOneWordOfText";
    case SWITCH_ACCESS_MENU_ACTION_MOVEUPONELINEOFTEXT:
      return "moveUpOneLineOfText";
    case SWITCH_ACCESS_MENU_ACTION_PASTE:
      return "paste";
    case SWITCH_ACCESS_MENU_ACTION_SCROLLDOWN:
      return "scrollDown";
    case SWITCH_ACCESS_MENU_ACTION_SCROLLLEFT:
      return "scrollLeft";
    case SWITCH_ACCESS_MENU_ACTION_SCROLLRIGHT:
      return "scrollRight";
    case SWITCH_ACCESS_MENU_ACTION_SCROLLUP:
      return "scrollUp";
    case SWITCH_ACCESS_MENU_ACTION_SELECT:
      return "select";
    case SWITCH_ACCESS_MENU_ACTION_SETTINGS:
      return "settings";
    case SWITCH_ACCESS_MENU_ACTION_STARTTEXTSELECTION:
      return "startTextSelection";
    case SWITCH_ACCESS_MENU_ACTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SwitchAccessMenuAction ParseSwitchAccessMenuAction(const std::string& enum_string) {
  if (enum_string == "copy")
    return SWITCH_ACCESS_MENU_ACTION_COPY;
  if (enum_string == "cut")
    return SWITCH_ACCESS_MENU_ACTION_CUT;
  if (enum_string == "decrement")
    return SWITCH_ACCESS_MENU_ACTION_DECREMENT;
  if (enum_string == "dictation")
    return SWITCH_ACCESS_MENU_ACTION_DICTATION;
  if (enum_string == "endTextSelection")
    return SWITCH_ACCESS_MENU_ACTION_ENDTEXTSELECTION;
  if (enum_string == "increment")
    return SWITCH_ACCESS_MENU_ACTION_INCREMENT;
  if (enum_string == "jumpToBeginningOfText")
    return SWITCH_ACCESS_MENU_ACTION_JUMPTOBEGINNINGOFTEXT;
  if (enum_string == "jumpToEndOfText")
    return SWITCH_ACCESS_MENU_ACTION_JUMPTOENDOFTEXT;
  if (enum_string == "keyboard")
    return SWITCH_ACCESS_MENU_ACTION_KEYBOARD;
  if (enum_string == "moveBackwardOneCharOfText")
    return SWITCH_ACCESS_MENU_ACTION_MOVEBACKWARDONECHAROFTEXT;
  if (enum_string == "moveBackwardOneWordOfText")
    return SWITCH_ACCESS_MENU_ACTION_MOVEBACKWARDONEWORDOFTEXT;
  if (enum_string == "moveCursor")
    return SWITCH_ACCESS_MENU_ACTION_MOVECURSOR;
  if (enum_string == "moveDownOneLineOfText")
    return SWITCH_ACCESS_MENU_ACTION_MOVEDOWNONELINEOFTEXT;
  if (enum_string == "moveForwardOneCharOfText")
    return SWITCH_ACCESS_MENU_ACTION_MOVEFORWARDONECHAROFTEXT;
  if (enum_string == "moveForwardOneWordOfText")
    return SWITCH_ACCESS_MENU_ACTION_MOVEFORWARDONEWORDOFTEXT;
  if (enum_string == "moveUpOneLineOfText")
    return SWITCH_ACCESS_MENU_ACTION_MOVEUPONELINEOFTEXT;
  if (enum_string == "paste")
    return SWITCH_ACCESS_MENU_ACTION_PASTE;
  if (enum_string == "scrollDown")
    return SWITCH_ACCESS_MENU_ACTION_SCROLLDOWN;
  if (enum_string == "scrollLeft")
    return SWITCH_ACCESS_MENU_ACTION_SCROLLLEFT;
  if (enum_string == "scrollRight")
    return SWITCH_ACCESS_MENU_ACTION_SCROLLRIGHT;
  if (enum_string == "scrollUp")
    return SWITCH_ACCESS_MENU_ACTION_SCROLLUP;
  if (enum_string == "select")
    return SWITCH_ACCESS_MENU_ACTION_SELECT;
  if (enum_string == "settings")
    return SWITCH_ACCESS_MENU_ACTION_SETTINGS;
  if (enum_string == "startTextSelection")
    return SWITCH_ACCESS_MENU_ACTION_STARTTEXTSELECTION;
  return SWITCH_ACCESS_MENU_ACTION_NONE;
}


const char* ToString(SyntheticKeyboardEventType enum_param) {
  switch (enum_param) {
    case SYNTHETIC_KEYBOARD_EVENT_TYPE_KEYUP:
      return "keyup";
    case SYNTHETIC_KEYBOARD_EVENT_TYPE_KEYDOWN:
      return "keydown";
    case SYNTHETIC_KEYBOARD_EVENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SyntheticKeyboardEventType ParseSyntheticKeyboardEventType(const std::string& enum_string) {
  if (enum_string == "keyup")
    return SYNTHETIC_KEYBOARD_EVENT_TYPE_KEYUP;
  if (enum_string == "keydown")
    return SYNTHETIC_KEYBOARD_EVENT_TYPE_KEYDOWN;
  return SYNTHETIC_KEYBOARD_EVENT_TYPE_NONE;
}


SyntheticKeyboardModifiers::SyntheticKeyboardModifiers()
 {}

SyntheticKeyboardModifiers::~SyntheticKeyboardModifiers() {}
SyntheticKeyboardModifiers::SyntheticKeyboardModifiers(SyntheticKeyboardModifiers&& rhs)
: ctrl(std::move(rhs.ctrl)),
alt(std::move(rhs.alt)),
search(std::move(rhs.search)),
shift(std::move(rhs.shift)){
}

SyntheticKeyboardModifiers& SyntheticKeyboardModifiers::operator=(SyntheticKeyboardModifiers&& rhs)
{
ctrl = std::move(rhs.ctrl);
alt = std::move(rhs.alt);
search = std::move(rhs.search);
shift = std::move(rhs.shift);
return *this;
}

// static
bool SyntheticKeyboardModifiers::Populate(
    const base::Value& value, SyntheticKeyboardModifiers* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* ctrl_value = NULL;
  if (dict->GetWithoutPathExpansion("ctrl", &ctrl_value)) {
    {
      bool temp;
      if (!ctrl_value->GetAsBoolean(&temp)) {
        out->ctrl.reset();
        return false;
      }
      else
        out->ctrl.reset(new bool(temp));
    }
  }

  const base::Value* alt_value = NULL;
  if (dict->GetWithoutPathExpansion("alt", &alt_value)) {
    {
      bool temp;
      if (!alt_value->GetAsBoolean(&temp)) {
        out->alt.reset();
        return false;
      }
      else
        out->alt.reset(new bool(temp));
    }
  }

  const base::Value* search_value = NULL;
  if (dict->GetWithoutPathExpansion("search", &search_value)) {
    {
      bool temp;
      if (!search_value->GetAsBoolean(&temp)) {
        out->search.reset();
        return false;
      }
      else
        out->search.reset(new bool(temp));
    }
  }

  const base::Value* shift_value = NULL;
  if (dict->GetWithoutPathExpansion("shift", &shift_value)) {
    {
      bool temp;
      if (!shift_value->GetAsBoolean(&temp)) {
        out->shift.reset();
        return false;
      }
      else
        out->shift.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<SyntheticKeyboardModifiers> SyntheticKeyboardModifiers::FromValue(const base::Value& value) {
  std::unique_ptr<SyntheticKeyboardModifiers> out(new SyntheticKeyboardModifiers());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SyntheticKeyboardModifiers::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->ctrl.get()) {
    to_value_result->SetWithoutPathExpansion("ctrl", std::make_unique<base::Value>(*this->ctrl));

  }
  if (this->alt.get()) {
    to_value_result->SetWithoutPathExpansion("alt", std::make_unique<base::Value>(*this->alt));

  }
  if (this->search.get()) {
    to_value_result->SetWithoutPathExpansion("search", std::make_unique<base::Value>(*this->search));

  }
  if (this->shift.get()) {
    to_value_result->SetWithoutPathExpansion("shift", std::make_unique<base::Value>(*this->shift));

  }

  return to_value_result;
}


SyntheticKeyboardEvent::SyntheticKeyboardEvent()
: type(SYNTHETIC_KEYBOARD_EVENT_TYPE_NONE),
key_code(0) {}

SyntheticKeyboardEvent::~SyntheticKeyboardEvent() {}
SyntheticKeyboardEvent::SyntheticKeyboardEvent(SyntheticKeyboardEvent&& rhs)
: type(rhs.type),
key_code(rhs.key_code),
modifiers(std::move(rhs.modifiers)){
}

SyntheticKeyboardEvent& SyntheticKeyboardEvent::operator=(SyntheticKeyboardEvent&& rhs)
{
type = rhs.type;
key_code = rhs.key_code;
modifiers = std::move(rhs.modifiers);
return *this;
}

// static
bool SyntheticKeyboardEvent::Populate(
    const base::Value& value, SyntheticKeyboardEvent* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string synthetic_keyboard_event_type_as_string;
    if (!type_value->GetAsString(&synthetic_keyboard_event_type_as_string)) {
      return false;
    }
    out->type = ParseSyntheticKeyboardEventType(synthetic_keyboard_event_type_as_string);
    if (out->type == SYNTHETIC_KEYBOARD_EVENT_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* key_code_value = NULL;
  if (!dict->GetWithoutPathExpansion("keyCode", &key_code_value)) {
    return false;
  }
  {
    if (!key_code_value->GetAsInteger(&out->key_code)) {
      return false;
    }
  }

  const base::Value* modifiers_value = NULL;
  if (dict->GetWithoutPathExpansion("modifiers", &modifiers_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!modifiers_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<SyntheticKeyboardModifiers> temp(new SyntheticKeyboardModifiers());
        if (!SyntheticKeyboardModifiers::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->modifiers = std::move(temp);
      }
    }
  }

  return true;
}

// static
std::unique_ptr<SyntheticKeyboardEvent> SyntheticKeyboardEvent::FromValue(const base::Value& value) {
  std::unique_ptr<SyntheticKeyboardEvent> out(new SyntheticKeyboardEvent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SyntheticKeyboardEvent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(accessibility_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("keyCode", std::make_unique<base::Value>(this->key_code));

  if (this->modifiers.get()) {
    to_value_result->SetWithoutPathExpansion("modifiers", (this->modifiers)->ToValue());

  }

  return to_value_result;
}


const char* ToString(SyntheticMouseEventType enum_param) {
  switch (enum_param) {
    case SYNTHETIC_MOUSE_EVENT_TYPE_PRESS:
      return "press";
    case SYNTHETIC_MOUSE_EVENT_TYPE_RELEASE:
      return "release";
    case SYNTHETIC_MOUSE_EVENT_TYPE_DRAG:
      return "drag";
    case SYNTHETIC_MOUSE_EVENT_TYPE_MOVE:
      return "move";
    case SYNTHETIC_MOUSE_EVENT_TYPE_ENTER:
      return "enter";
    case SYNTHETIC_MOUSE_EVENT_TYPE_EXIT:
      return "exit";
    case SYNTHETIC_MOUSE_EVENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SyntheticMouseEventType ParseSyntheticMouseEventType(const std::string& enum_string) {
  if (enum_string == "press")
    return SYNTHETIC_MOUSE_EVENT_TYPE_PRESS;
  if (enum_string == "release")
    return SYNTHETIC_MOUSE_EVENT_TYPE_RELEASE;
  if (enum_string == "drag")
    return SYNTHETIC_MOUSE_EVENT_TYPE_DRAG;
  if (enum_string == "move")
    return SYNTHETIC_MOUSE_EVENT_TYPE_MOVE;
  if (enum_string == "enter")
    return SYNTHETIC_MOUSE_EVENT_TYPE_ENTER;
  if (enum_string == "exit")
    return SYNTHETIC_MOUSE_EVENT_TYPE_EXIT;
  return SYNTHETIC_MOUSE_EVENT_TYPE_NONE;
}


SyntheticMouseEvent::SyntheticMouseEvent()
: type(SYNTHETIC_MOUSE_EVENT_TYPE_NONE),
x(0),
y(0) {}

SyntheticMouseEvent::~SyntheticMouseEvent() {}
SyntheticMouseEvent::SyntheticMouseEvent(SyntheticMouseEvent&& rhs)
: type(rhs.type),
x(rhs.x),
y(rhs.y){
}

SyntheticMouseEvent& SyntheticMouseEvent::operator=(SyntheticMouseEvent&& rhs)
{
type = rhs.type;
x = rhs.x;
y = rhs.y;
return *this;
}

// static
bool SyntheticMouseEvent::Populate(
    const base::Value& value, SyntheticMouseEvent* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string synthetic_mouse_event_type_as_string;
    if (!type_value->GetAsString(&synthetic_mouse_event_type_as_string)) {
      return false;
    }
    out->type = ParseSyntheticMouseEventType(synthetic_mouse_event_type_as_string);
    if (out->type == SYNTHETIC_MOUSE_EVENT_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* x_value = NULL;
  if (!dict->GetWithoutPathExpansion("x", &x_value)) {
    return false;
  }
  {
    if (!x_value->GetAsInteger(&out->x)) {
      return false;
    }
  }

  const base::Value* y_value = NULL;
  if (!dict->GetWithoutPathExpansion("y", &y_value)) {
    return false;
  }
  {
    if (!y_value->GetAsInteger(&out->y)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<SyntheticMouseEvent> SyntheticMouseEvent::FromValue(const base::Value& value) {
  std::unique_ptr<SyntheticMouseEvent> out(new SyntheticMouseEvent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SyntheticMouseEvent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(accessibility_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("x", std::make_unique<base::Value>(this->x));

  to_value_result->SetWithoutPathExpansion("y", std::make_unique<base::Value>(this->y));


  return to_value_result;
}


const char* ToString(SelectToSpeakState enum_param) {
  switch (enum_param) {
    case SELECT_TO_SPEAK_STATE_SELECTING:
      return "selecting";
    case SELECT_TO_SPEAK_STATE_SPEAKING:
      return "speaking";
    case SELECT_TO_SPEAK_STATE_INACTIVE:
      return "inactive";
    case SELECT_TO_SPEAK_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SelectToSpeakState ParseSelectToSpeakState(const std::string& enum_string) {
  if (enum_string == "selecting")
    return SELECT_TO_SPEAK_STATE_SELECTING;
  if (enum_string == "speaking")
    return SELECT_TO_SPEAK_STATE_SPEAKING;
  if (enum_string == "inactive")
    return SELECT_TO_SPEAK_STATE_INACTIVE;
  return SELECT_TO_SPEAK_STATE_NONE;
}


const char* ToString(FocusType enum_param) {
  switch (enum_param) {
    case FOCUS_TYPE_GLOW:
      return "glow";
    case FOCUS_TYPE_SOLID:
      return "solid";
    case FOCUS_TYPE_DASHED:
      return "dashed";
    case FOCUS_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FocusType ParseFocusType(const std::string& enum_string) {
  if (enum_string == "glow")
    return FOCUS_TYPE_GLOW;
  if (enum_string == "solid")
    return FOCUS_TYPE_SOLID;
  if (enum_string == "dashed")
    return FOCUS_TYPE_DASHED;
  return FOCUS_TYPE_NONE;
}


FocusRingInfo::FocusRingInfo()
: type(FOCUS_TYPE_NONE) {}

FocusRingInfo::~FocusRingInfo() {}
FocusRingInfo::FocusRingInfo(FocusRingInfo&& rhs)
: rects(std::move(rhs.rects)),
type(rhs.type),
color(std::move(rhs.color)),
secondary_color(std::move(rhs.secondary_color)),
background_color(std::move(rhs.background_color)),
id(std::move(rhs.id)){
}

FocusRingInfo& FocusRingInfo::operator=(FocusRingInfo&& rhs)
{
rects = std::move(rhs.rects);
type = rhs.type;
color = std::move(rhs.color);
secondary_color = std::move(rhs.secondary_color);
background_color = std::move(rhs.background_color);
id = std::move(rhs.id);
return *this;
}

// static
bool FocusRingInfo::Populate(
    const base::Value& value, FocusRingInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* rects_value = NULL;
  if (!dict->GetWithoutPathExpansion("rects", &rects_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!rects_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->rects)) {
        return false;
      }
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string focus_type_as_string;
    if (!type_value->GetAsString(&focus_type_as_string)) {
      return false;
    }
    out->type = ParseFocusType(focus_type_as_string);
    if (out->type == FOCUS_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* color_value = NULL;
  if (!dict->GetWithoutPathExpansion("color", &color_value)) {
    return false;
  }
  {
    if (!color_value->GetAsString(&out->color)) {
      return false;
    }
  }

  const base::Value* secondary_color_value = NULL;
  if (dict->GetWithoutPathExpansion("secondaryColor", &secondary_color_value)) {
    {
      std::string temp;
      if (!secondary_color_value->GetAsString(&temp)) {
        out->secondary_color.reset();
        return false;
      }
      else
        out->secondary_color.reset(new std::string(temp));
    }
  }

  const base::Value* background_color_value = NULL;
  if (dict->GetWithoutPathExpansion("backgroundColor", &background_color_value)) {
    {
      std::string temp;
      if (!background_color_value->GetAsString(&temp)) {
        out->background_color.reset();
        return false;
      }
      else
        out->background_color.reset(new std::string(temp));
    }
  }

  const base::Value* id_value = NULL;
  if (dict->GetWithoutPathExpansion("id", &id_value)) {
    {
      std::string temp;
      if (!id_value->GetAsString(&temp)) {
        out->id.reset();
        return false;
      }
      else
        out->id.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<FocusRingInfo> FocusRingInfo::FromValue(const base::Value& value) {
  std::unique_ptr<FocusRingInfo> out(new FocusRingInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FocusRingInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("rects", json_schema_compiler::util::CreateValueFromArray(this->rects));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(accessibility_private::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("color", std::make_unique<base::Value>(this->color));

  if (this->secondary_color.get()) {
    to_value_result->SetWithoutPathExpansion("secondaryColor", std::make_unique<base::Value>(*this->secondary_color));

  }
  if (this->background_color.get()) {
    to_value_result->SetWithoutPathExpansion("backgroundColor", std::make_unique<base::Value>(*this->background_color));

  }
  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetBatteryDescription {

std::unique_ptr<base::ListValue> Results::Create(const std::string& battery_description) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(battery_description));

  return create_results;
}
}  // namespace GetBatteryDescription

namespace SetNativeAccessibilityEnabled {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetNativeAccessibilityEnabled

namespace SetFocusRings {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* focus_rings_value = NULL;
  if (args.Get(0, &focus_rings_value) &&
      !focus_rings_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!focus_rings_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->focus_rings)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetFocusRings

namespace SetHighlights {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* rects_value = NULL;
  if (args.Get(0, &rects_value) &&
      !rects_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!rects_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->rects)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* color_value = NULL;
  if (args.Get(1, &color_value) &&
      !color_value->is_none()) {
    {
      if (!color_value->GetAsString(&params->color)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetHighlights

namespace SetKeyboardListener {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* capture_value = NULL;
  if (args.Get(1, &capture_value) &&
      !capture_value->is_none()) {
    {
      if (!capture_value->GetAsBoolean(&params->capture)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetKeyboardListener

namespace DarkenScreen {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace DarkenScreen

namespace ForwardKeyEventsToSwitchAccess {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* should_forward_value = NULL;
  if (args.Get(0, &should_forward_value) &&
      !should_forward_value->is_none()) {
    {
      if (!should_forward_value->GetAsBoolean(&params->should_forward)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace ForwardKeyEventsToSwitchAccess

namespace UpdateSwitchAccessBubble {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 4) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* bubble_value = NULL;
  if (args.Get(0, &bubble_value) &&
      !bubble_value->is_none()) {
    {
      std::string switch_access_bubble_as_string;
      if (!bubble_value->GetAsString(&switch_access_bubble_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->bubble = ParseSwitchAccessBubble(switch_access_bubble_as_string);
      if (params->bubble == SWITCH_ACCESS_BUBBLE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* show_value = NULL;
  if (args.Get(1, &show_value) &&
      !show_value->is_none()) {
    {
      if (!show_value->GetAsBoolean(&params->show)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* anchor_value = NULL;
  if (args.Get(2, &anchor_value) &&
      !anchor_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!anchor_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<ScreenRect> temp(new ScreenRect());
        if (!ScreenRect::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->anchor = std::move(temp);
      }
    }
  }

  const base::Value* actions_value = NULL;
  if (args.Get(3, &actions_value) &&
      !actions_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!actions_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        params->actions.reset(new std::vector<SwitchAccessMenuAction>);
        for (const auto& it : *(list)) {
          SwitchAccessMenuAction tmp;
          std::string switch_access_menu_action_as_string;
          if (!(it).GetAsString(&switch_access_menu_action_as_string)) {
            return std::unique_ptr<Params>();
          }
          tmp = ParseSwitchAccessMenuAction(switch_access_menu_action_as_string);
          if (tmp == SWITCH_ACCESS_MENU_ACTION_NONE) {
            return std::unique_ptr<Params>();
          }
          params->actions->push_back(tmp);
        }
      }
    }
  }

  return params;
}


}  // namespace UpdateSwitchAccessBubble

namespace SetNativeChromeVoxArcSupportForCurrentApp {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetNativeChromeVoxArcSupportForCurrentApp

namespace SendSyntheticKeyEvent {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* key_event_value = NULL;
  if (args.Get(0, &key_event_value) &&
      !key_event_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!key_event_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!SyntheticKeyboardEvent::Populate(*dictionary, &params->key_event)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SendSyntheticKeyEvent

namespace EnableChromeVoxMouseEvents {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enabled_value = NULL;
  if (args.Get(0, &enabled_value) &&
      !enabled_value->is_none()) {
    {
      if (!enabled_value->GetAsBoolean(&params->enabled)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace EnableChromeVoxMouseEvents

namespace SendSyntheticMouseEvent {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* mouse_event_value = NULL;
  if (args.Get(0, &mouse_event_value) &&
      !mouse_event_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!mouse_event_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!SyntheticMouseEvent::Populate(*dictionary, &params->mouse_event)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SendSyntheticMouseEvent

namespace OnSelectToSpeakStateChanged {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* state_value = NULL;
  if (args.Get(0, &state_value) &&
      !state_value->is_none()) {
    {
      std::string select_to_speak_state_as_string;
      if (!state_value->GetAsString(&select_to_speak_state_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->state = ParseSelectToSpeakState(select_to_speak_state_as_string);
      if (params->state == SELECT_TO_SPEAK_STATE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OnSelectToSpeakStateChanged

namespace OnScrollableBoundsForPointFound {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* rect_value = NULL;
  if (args.Get(0, &rect_value) &&
      !rect_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!rect_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ScreenRect::Populate(*dictionary, &params->rect)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OnScrollableBoundsForPointFound

namespace ToggleDictation {

}  // namespace ToggleDictation

namespace SetVirtualKeyboardVisible {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* is_visible_value = NULL;
  if (args.Get(0, &is_visible_value) &&
      !is_visible_value->is_none()) {
    {
      if (!is_visible_value->GetAsBoolean(&params->is_visible)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetVirtualKeyboardVisible

namespace OpenSettingsSubpage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* subpage_value = NULL;
  if (args.Get(0, &subpage_value) &&
      !subpage_value->is_none()) {
    {
      if (!subpage_value->GetAsString(&params->subpage)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OpenSettingsSubpage

//
// Events
//

namespace OnIntroduceChromeVox {

const char kEventName[] = "accessibilityPrivate.onIntroduceChromeVox";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnIntroduceChromeVox

namespace OnAccessibilityGesture {

const char kEventName[] = "accessibilityPrivate.onAccessibilityGesture";

std::unique_ptr<base::ListValue> Create(const Gesture& gesture) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(accessibility_private::ToString(gesture)));

  return create_results;
}

}  // namespace OnAccessibilityGesture

namespace OnTwoFingerTouchStart {

const char kEventName[] = "accessibilityPrivate.onTwoFingerTouchStart";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnTwoFingerTouchStart

namespace OnTwoFingerTouchStop {

const char kEventName[] = "accessibilityPrivate.onTwoFingerTouchStop";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnTwoFingerTouchStop

namespace OnSelectToSpeakStateChangeRequested {

const char kEventName[] = "accessibilityPrivate.onSelectToSpeakStateChangeRequested";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnSelectToSpeakStateChangeRequested

namespace OnSwitchAccessCommand {

const char kEventName[] = "accessibilityPrivate.onSwitchAccessCommand";

std::unique_ptr<base::ListValue> Create(const SwitchAccessCommand& command) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(accessibility_private::ToString(command)));

  return create_results;
}

}  // namespace OnSwitchAccessCommand

namespace OnAnnounceForAccessibility {

const char kEventName[] = "accessibilityPrivate.onAnnounceForAccessibility";

std::unique_ptr<base::ListValue> Create(const std::vector<std::string>& announce_text) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(announce_text));

  return create_results;
}

}  // namespace OnAnnounceForAccessibility

namespace FindScrollableBoundsForPoint {

const char kEventName[] = "accessibilityPrivate.findScrollableBoundsForPoint";

std::unique_ptr<base::ListValue> Create(double x, double y) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(x));

  create_results->Append(std::make_unique<base::Value>(y));

  return create_results;
}

}  // namespace FindScrollableBoundsForPoint

namespace OnCustomSpokenFeedbackToggled {

const char kEventName[] = "accessibilityPrivate.onCustomSpokenFeedbackToggled";

std::unique_ptr<base::ListValue> Create(bool enabled) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(enabled));

  return create_results;
}

}  // namespace OnCustomSpokenFeedbackToggled

}  // namespace accessibility_private
}  // namespace api
}  // namespace extensions

