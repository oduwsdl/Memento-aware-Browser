// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/braille_display_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/braille_display_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace braille_display_private {
//
// Types
//

const char* ToString(KeyCommand enum_param) {
  switch (enum_param) {
    case KEY_COMMAND_LINE_UP:
      return "line_up";
    case KEY_COMMAND_LINE_DOWN:
      return "line_down";
    case KEY_COMMAND_PAN_LEFT:
      return "pan_left";
    case KEY_COMMAND_PAN_RIGHT:
      return "pan_right";
    case KEY_COMMAND_TOP:
      return "top";
    case KEY_COMMAND_BOTTOM:
      return "bottom";
    case KEY_COMMAND_ROUTING:
      return "routing";
    case KEY_COMMAND_SECONDARY_ROUTING:
      return "secondary_routing";
    case KEY_COMMAND_DOTS:
      return "dots";
    case KEY_COMMAND_CHORD:
      return "chord";
    case KEY_COMMAND_STANDARD_KEY:
      return "standard_key";
    case KEY_COMMAND_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

KeyCommand ParseKeyCommand(const std::string& enum_string) {
  if (enum_string == "line_up")
    return KEY_COMMAND_LINE_UP;
  if (enum_string == "line_down")
    return KEY_COMMAND_LINE_DOWN;
  if (enum_string == "pan_left")
    return KEY_COMMAND_PAN_LEFT;
  if (enum_string == "pan_right")
    return KEY_COMMAND_PAN_RIGHT;
  if (enum_string == "top")
    return KEY_COMMAND_TOP;
  if (enum_string == "bottom")
    return KEY_COMMAND_BOTTOM;
  if (enum_string == "routing")
    return KEY_COMMAND_ROUTING;
  if (enum_string == "secondary_routing")
    return KEY_COMMAND_SECONDARY_ROUTING;
  if (enum_string == "dots")
    return KEY_COMMAND_DOTS;
  if (enum_string == "chord")
    return KEY_COMMAND_CHORD;
  if (enum_string == "standard_key")
    return KEY_COMMAND_STANDARD_KEY;
  return KEY_COMMAND_NONE;
}


KeyEvent::KeyEvent()
: command(KEY_COMMAND_NONE) {}

KeyEvent::~KeyEvent() {}
KeyEvent::KeyEvent(KeyEvent&& rhs)
: command(rhs.command),
display_position(std::move(rhs.display_position)),
braille_dots(std::move(rhs.braille_dots)),
standard_key_code(std::move(rhs.standard_key_code)),
standard_key_char(std::move(rhs.standard_key_char)),
space_key(std::move(rhs.space_key)),
alt_key(std::move(rhs.alt_key)),
shift_key(std::move(rhs.shift_key)),
ctrl_key(std::move(rhs.ctrl_key)){
}

KeyEvent& KeyEvent::operator=(KeyEvent&& rhs)
{
command = rhs.command;
display_position = std::move(rhs.display_position);
braille_dots = std::move(rhs.braille_dots);
standard_key_code = std::move(rhs.standard_key_code);
standard_key_char = std::move(rhs.standard_key_char);
space_key = std::move(rhs.space_key);
alt_key = std::move(rhs.alt_key);
shift_key = std::move(rhs.shift_key);
ctrl_key = std::move(rhs.ctrl_key);
return *this;
}

// static
bool KeyEvent::Populate(
    const base::Value& value, KeyEvent* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* command_value = NULL;
  if (!dict->GetWithoutPathExpansion("command", &command_value)) {
    return false;
  }
  {
    std::string key_command_as_string;
    if (!command_value->GetAsString(&key_command_as_string)) {
      return false;
    }
    out->command = ParseKeyCommand(key_command_as_string);
    if (out->command == KEY_COMMAND_NONE) {
      return false;
    }
  }

  const base::Value* display_position_value = NULL;
  if (dict->GetWithoutPathExpansion("displayPosition", &display_position_value)) {
    {
      int temp;
      if (!display_position_value->GetAsInteger(&temp)) {
        out->display_position.reset();
        return false;
      }
      else
        out->display_position.reset(new int(temp));
    }
  }

  const base::Value* braille_dots_value = NULL;
  if (dict->GetWithoutPathExpansion("brailleDots", &braille_dots_value)) {
    {
      int temp;
      if (!braille_dots_value->GetAsInteger(&temp)) {
        out->braille_dots.reset();
        return false;
      }
      else
        out->braille_dots.reset(new int(temp));
    }
  }

  const base::Value* standard_key_code_value = NULL;
  if (dict->GetWithoutPathExpansion("standardKeyCode", &standard_key_code_value)) {
    {
      std::string temp;
      if (!standard_key_code_value->GetAsString(&temp)) {
        out->standard_key_code.reset();
        return false;
      }
      else
        out->standard_key_code.reset(new std::string(temp));
    }
  }

  const base::Value* standard_key_char_value = NULL;
  if (dict->GetWithoutPathExpansion("standardKeyChar", &standard_key_char_value)) {
    {
      std::string temp;
      if (!standard_key_char_value->GetAsString(&temp)) {
        out->standard_key_char.reset();
        return false;
      }
      else
        out->standard_key_char.reset(new std::string(temp));
    }
  }

  const base::Value* space_key_value = NULL;
  if (dict->GetWithoutPathExpansion("spaceKey", &space_key_value)) {
    {
      bool temp;
      if (!space_key_value->GetAsBoolean(&temp)) {
        out->space_key.reset();
        return false;
      }
      else
        out->space_key.reset(new bool(temp));
    }
  }

  const base::Value* alt_key_value = NULL;
  if (dict->GetWithoutPathExpansion("altKey", &alt_key_value)) {
    {
      bool temp;
      if (!alt_key_value->GetAsBoolean(&temp)) {
        out->alt_key.reset();
        return false;
      }
      else
        out->alt_key.reset(new bool(temp));
    }
  }

  const base::Value* shift_key_value = NULL;
  if (dict->GetWithoutPathExpansion("shiftKey", &shift_key_value)) {
    {
      bool temp;
      if (!shift_key_value->GetAsBoolean(&temp)) {
        out->shift_key.reset();
        return false;
      }
      else
        out->shift_key.reset(new bool(temp));
    }
  }

  const base::Value* ctrl_key_value = NULL;
  if (dict->GetWithoutPathExpansion("ctrlKey", &ctrl_key_value)) {
    {
      bool temp;
      if (!ctrl_key_value->GetAsBoolean(&temp)) {
        out->ctrl_key.reset();
        return false;
      }
      else
        out->ctrl_key.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<KeyEvent> KeyEvent::FromValue(const base::Value& value) {
  std::unique_ptr<KeyEvent> out(new KeyEvent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> KeyEvent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("command", std::make_unique<base::Value>(braille_display_private::ToString(this->command)));

  if (this->display_position.get()) {
    to_value_result->SetWithoutPathExpansion("displayPosition", std::make_unique<base::Value>(*this->display_position));

  }
  if (this->braille_dots.get()) {
    to_value_result->SetWithoutPathExpansion("brailleDots", std::make_unique<base::Value>(*this->braille_dots));

  }
  if (this->standard_key_code.get()) {
    to_value_result->SetWithoutPathExpansion("standardKeyCode", std::make_unique<base::Value>(*this->standard_key_code));

  }
  if (this->standard_key_char.get()) {
    to_value_result->SetWithoutPathExpansion("standardKeyChar", std::make_unique<base::Value>(*this->standard_key_char));

  }
  if (this->space_key.get()) {
    to_value_result->SetWithoutPathExpansion("spaceKey", std::make_unique<base::Value>(*this->space_key));

  }
  if (this->alt_key.get()) {
    to_value_result->SetWithoutPathExpansion("altKey", std::make_unique<base::Value>(*this->alt_key));

  }
  if (this->shift_key.get()) {
    to_value_result->SetWithoutPathExpansion("shiftKey", std::make_unique<base::Value>(*this->shift_key));

  }
  if (this->ctrl_key.get()) {
    to_value_result->SetWithoutPathExpansion("ctrlKey", std::make_unique<base::Value>(*this->ctrl_key));

  }

  return to_value_result;
}


DisplayState::DisplayState()
: available(false) {}

DisplayState::~DisplayState() {}
DisplayState::DisplayState(DisplayState&& rhs)
: available(rhs.available),
text_row_count(std::move(rhs.text_row_count)),
text_column_count(std::move(rhs.text_column_count)),
cell_size(std::move(rhs.cell_size)){
}

DisplayState& DisplayState::operator=(DisplayState&& rhs)
{
available = rhs.available;
text_row_count = std::move(rhs.text_row_count);
text_column_count = std::move(rhs.text_column_count);
cell_size = std::move(rhs.cell_size);
return *this;
}

// static
bool DisplayState::Populate(
    const base::Value& value, DisplayState* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* available_value = NULL;
  if (!dict->GetWithoutPathExpansion("available", &available_value)) {
    return false;
  }
  {
    if (!available_value->GetAsBoolean(&out->available)) {
      return false;
    }
  }

  const base::Value* text_row_count_value = NULL;
  if (dict->GetWithoutPathExpansion("textRowCount", &text_row_count_value)) {
    {
      int temp;
      if (!text_row_count_value->GetAsInteger(&temp)) {
        out->text_row_count.reset();
        return false;
      }
      else
        out->text_row_count.reset(new int(temp));
    }
  }

  const base::Value* text_column_count_value = NULL;
  if (dict->GetWithoutPathExpansion("textColumnCount", &text_column_count_value)) {
    {
      int temp;
      if (!text_column_count_value->GetAsInteger(&temp)) {
        out->text_column_count.reset();
        return false;
      }
      else
        out->text_column_count.reset(new int(temp));
    }
  }

  const base::Value* cell_size_value = NULL;
  if (dict->GetWithoutPathExpansion("cellSize", &cell_size_value)) {
    {
      int temp;
      if (!cell_size_value->GetAsInteger(&temp)) {
        out->cell_size.reset();
        return false;
      }
      else
        out->cell_size.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DisplayState> DisplayState::FromValue(const base::Value& value) {
  std::unique_ptr<DisplayState> out(new DisplayState());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DisplayState::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("available", std::make_unique<base::Value>(this->available));

  if (this->text_row_count.get()) {
    to_value_result->SetWithoutPathExpansion("textRowCount", std::make_unique<base::Value>(*this->text_row_count));

  }
  if (this->text_column_count.get()) {
    to_value_result->SetWithoutPathExpansion("textColumnCount", std::make_unique<base::Value>(*this->text_column_count));

  }
  if (this->cell_size.get()) {
    to_value_result->SetWithoutPathExpansion("cellSize", std::make_unique<base::Value>(*this->cell_size));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetDisplayState {

std::unique_ptr<base::ListValue> Results::Create(const DisplayState& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace GetDisplayState

namespace WriteDots {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* cells_value = NULL;
  if (args.Get(0, &cells_value) &&
      !cells_value->is_none()) {
    {
      if (!cells_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->cells = cells_value->GetBlob();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* columns_value = NULL;
  if (args.Get(1, &columns_value) &&
      !columns_value->is_none()) {
    {
      if (!columns_value->GetAsInteger(&params->columns)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* rows_value = NULL;
  if (args.Get(2, &rows_value) &&
      !rows_value->is_none()) {
    {
      if (!rows_value->GetAsInteger(&params->rows)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace WriteDots

namespace UpdateBluetoothBrailleDisplayAddress {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* address_value = NULL;
  if (args.Get(0, &address_value) &&
      !address_value->is_none()) {
    {
      if (!address_value->GetAsString(&params->address)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace UpdateBluetoothBrailleDisplayAddress

//
// Events
//

namespace OnDisplayStateChanged {

const char kEventName[] = "brailleDisplayPrivate.onDisplayStateChanged";

std::unique_ptr<base::ListValue> Create(const DisplayState& state) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((state).ToValue());

  return create_results;
}

}  // namespace OnDisplayStateChanged

namespace OnKeyEvent {

const char kEventName[] = "brailleDisplayPrivate.onKeyEvent";

std::unique_ptr<base::ListValue> Create(const KeyEvent& event) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((event).ToValue());

  return create_results;
}

}  // namespace OnKeyEvent

}  // namespace braille_display_private
}  // namespace api
}  // namespace extensions

