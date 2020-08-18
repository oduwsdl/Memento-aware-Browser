// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/windows.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/windows.h"
#include <set>
#include <utility>
#include "chrome/common/extensions/api/tabs.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace windows {
//
// Properties
//

const int WINDOW_ID_NONE = -1;

const int WINDOW_ID_CURRENT = -2;

//
// Types
//

const char* ToString(WindowType enum_param) {
  switch (enum_param) {
    case WINDOW_TYPE_NORMAL:
      return "normal";
    case WINDOW_TYPE_POPUP:
      return "popup";
    case WINDOW_TYPE_PANEL:
      return "panel";
    case WINDOW_TYPE_APP:
      return "app";
    case WINDOW_TYPE_DEVTOOLS:
      return "devtools";
    case WINDOW_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

WindowType ParseWindowType(const std::string& enum_string) {
  if (enum_string == "normal")
    return WINDOW_TYPE_NORMAL;
  if (enum_string == "popup")
    return WINDOW_TYPE_POPUP;
  if (enum_string == "panel")
    return WINDOW_TYPE_PANEL;
  if (enum_string == "app")
    return WINDOW_TYPE_APP;
  if (enum_string == "devtools")
    return WINDOW_TYPE_DEVTOOLS;
  return WINDOW_TYPE_NONE;
}


const char* ToString(WindowState enum_param) {
  switch (enum_param) {
    case WINDOW_STATE_NORMAL:
      return "normal";
    case WINDOW_STATE_MINIMIZED:
      return "minimized";
    case WINDOW_STATE_MAXIMIZED:
      return "maximized";
    case WINDOW_STATE_FULLSCREEN:
      return "fullscreen";
    case WINDOW_STATE_LOCKED_FULLSCREEN:
      return "locked-fullscreen";
    case WINDOW_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

WindowState ParseWindowState(const std::string& enum_string) {
  if (enum_string == "normal")
    return WINDOW_STATE_NORMAL;
  if (enum_string == "minimized")
    return WINDOW_STATE_MINIMIZED;
  if (enum_string == "maximized")
    return WINDOW_STATE_MAXIMIZED;
  if (enum_string == "fullscreen")
    return WINDOW_STATE_FULLSCREEN;
  if (enum_string == "locked-fullscreen")
    return WINDOW_STATE_LOCKED_FULLSCREEN;
  return WINDOW_STATE_NONE;
}


Window::Window()
: focused(false),
incognito(false),
type(WINDOW_TYPE_NONE),
state(WINDOW_STATE_NONE),
always_on_top(false) {}

Window::~Window() {}
Window::Window(Window&& rhs)
: id(std::move(rhs.id)),
focused(rhs.focused),
top(std::move(rhs.top)),
left(std::move(rhs.left)),
width(std::move(rhs.width)),
height(std::move(rhs.height)),
tabs(std::move(rhs.tabs)),
incognito(rhs.incognito),
type(rhs.type),
state(rhs.state),
always_on_top(rhs.always_on_top),
session_id(std::move(rhs.session_id)){
}

Window& Window::operator=(Window&& rhs)
{
id = std::move(rhs.id);
focused = rhs.focused;
top = std::move(rhs.top);
left = std::move(rhs.left);
width = std::move(rhs.width);
height = std::move(rhs.height);
tabs = std::move(rhs.tabs);
incognito = rhs.incognito;
type = rhs.type;
state = rhs.state;
always_on_top = rhs.always_on_top;
session_id = std::move(rhs.session_id);
return *this;
}

// static
bool Window::Populate(
    const base::Value& value, Window* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = WINDOW_TYPE_NONE;
  out->state = WINDOW_STATE_NONE;
  const base::Value* id_value = NULL;
  if (dict->GetWithoutPathExpansion("id", &id_value)) {
    {
      int temp;
      if (!id_value->GetAsInteger(&temp)) {
        out->id.reset();
        return false;
      }
      else
        out->id.reset(new int(temp));
    }
  }

  const base::Value* focused_value = NULL;
  if (!dict->GetWithoutPathExpansion("focused", &focused_value)) {
    return false;
  }
  {
    if (!focused_value->GetAsBoolean(&out->focused)) {
      return false;
    }
  }

  const base::Value* top_value = NULL;
  if (dict->GetWithoutPathExpansion("top", &top_value)) {
    {
      int temp;
      if (!top_value->GetAsInteger(&temp)) {
        out->top.reset();
        return false;
      }
      else
        out->top.reset(new int(temp));
    }
  }

  const base::Value* left_value = NULL;
  if (dict->GetWithoutPathExpansion("left", &left_value)) {
    {
      int temp;
      if (!left_value->GetAsInteger(&temp)) {
        out->left.reset();
        return false;
      }
      else
        out->left.reset(new int(temp));
    }
  }

  const base::Value* width_value = NULL;
  if (dict->GetWithoutPathExpansion("width", &width_value)) {
    {
      int temp;
      if (!width_value->GetAsInteger(&temp)) {
        out->width.reset();
        return false;
      }
      else
        out->width.reset(new int(temp));
    }
  }

  const base::Value* height_value = NULL;
  if (dict->GetWithoutPathExpansion("height", &height_value)) {
    {
      int temp;
      if (!height_value->GetAsInteger(&temp)) {
        out->height.reset();
        return false;
      }
      else
        out->height.reset(new int(temp));
    }
  }

  const base::Value* tabs_value = NULL;
  if (dict->GetWithoutPathExpansion("tabs", &tabs_value)) {
    {
      const base::ListValue* list = NULL;
      if (!tabs_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->tabs)) {
          return false;
        }
      }
    }
  }

  const base::Value* incognito_value = NULL;
  if (!dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    return false;
  }
  {
    if (!incognito_value->GetAsBoolean(&out->incognito)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string window_type_as_string;
      if (!type_value->GetAsString(&window_type_as_string)) {
        return false;
      }
      out->type = ParseWindowType(window_type_as_string);
      if (out->type == WINDOW_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = WINDOW_TYPE_NONE;
  }

  const base::Value* state_value = NULL;
  if (dict->GetWithoutPathExpansion("state", &state_value)) {
    {
      std::string window_state_as_string;
      if (!state_value->GetAsString(&window_state_as_string)) {
        return false;
      }
      out->state = ParseWindowState(window_state_as_string);
      if (out->state == WINDOW_STATE_NONE) {
        return false;
      }
    }
    } else {
    out->state = WINDOW_STATE_NONE;
  }

  const base::Value* always_on_top_value = NULL;
  if (!dict->GetWithoutPathExpansion("alwaysOnTop", &always_on_top_value)) {
    return false;
  }
  {
    if (!always_on_top_value->GetAsBoolean(&out->always_on_top)) {
      return false;
    }
  }

  const base::Value* session_id_value = NULL;
  if (dict->GetWithoutPathExpansion("sessionId", &session_id_value)) {
    {
      std::string temp;
      if (!session_id_value->GetAsString(&temp)) {
        out->session_id.reset();
        return false;
      }
      else
        out->session_id.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Window> Window::FromValue(const base::Value& value) {
  std::unique_ptr<Window> out(new Window());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Window::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }
  to_value_result->SetWithoutPathExpansion("focused", std::make_unique<base::Value>(this->focused));

  if (this->top.get()) {
    to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(*this->top));

  }
  if (this->left.get()) {
    to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(*this->left));

  }
  if (this->width.get()) {
    to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(*this->width));

  }
  if (this->height.get()) {
    to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(*this->height));

  }
  if (this->tabs.get()) {
    to_value_result->SetWithoutPathExpansion("tabs", json_schema_compiler::util::CreateValueFromOptionalArray(this->tabs));

  }
  to_value_result->SetWithoutPathExpansion("incognito", std::make_unique<base::Value>(this->incognito));

  if (this->type != WINDOW_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(windows::ToString(this->type)));

  }
  if (this->state != WINDOW_STATE_NONE) {
    to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(windows::ToString(this->state)));

  }
  to_value_result->SetWithoutPathExpansion("alwaysOnTop", std::make_unique<base::Value>(this->always_on_top));

  if (this->session_id.get()) {
    to_value_result->SetWithoutPathExpansion("sessionId", std::make_unique<base::Value>(*this->session_id));

  }

  return to_value_result;
}


const char* ToString(CreateType enum_param) {
  switch (enum_param) {
    case CREATE_TYPE_NORMAL:
      return "normal";
    case CREATE_TYPE_POPUP:
      return "popup";
    case CREATE_TYPE_PANEL:
      return "panel";
    case CREATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CreateType ParseCreateType(const std::string& enum_string) {
  if (enum_string == "normal")
    return CREATE_TYPE_NORMAL;
  if (enum_string == "popup")
    return CREATE_TYPE_POPUP;
  if (enum_string == "panel")
    return CREATE_TYPE_PANEL;
  return CREATE_TYPE_NONE;
}



//
// Functions
//

namespace Get {

Params::GetInfo::GetInfo()
 {}

Params::GetInfo::~GetInfo() {}
Params::GetInfo::GetInfo(GetInfo&& rhs)
: populate(std::move(rhs.populate)),
window_types(std::move(rhs.window_types)){
}

Params::GetInfo& Params::GetInfo::operator=(GetInfo&& rhs)
{
populate = std::move(rhs.populate);
window_types = std::move(rhs.window_types);
return *this;
}

// static
bool Params::GetInfo::Populate(
    const base::Value& value, GetInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* populate_value = NULL;
  if (dict->GetWithoutPathExpansion("populate", &populate_value)) {
    {
      bool temp;
      if (!populate_value->GetAsBoolean(&temp)) {
        out->populate.reset();
        return false;
      }
      else
        out->populate.reset(new bool(temp));
    }
  }

  const base::Value* window_types_value = NULL;
  if (dict->GetWithoutPathExpansion("windowTypes", &window_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!window_types_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->window_types.reset(new std::vector<WindowType>);
        for (const auto& it : *(list)) {
          WindowType tmp;
          std::string window_type_as_string;
          if (!(it).GetAsString(&window_type_as_string)) {
            return false;
          }
          tmp = ParseWindowType(window_type_as_string);
          if (tmp == WINDOW_TYPE_NONE) {
            return false;
          }
          out->window_types->push_back(tmp);
        }
      }
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* window_id_value = NULL;
  if (args.Get(0, &window_id_value) &&
      !window_id_value->is_none()) {
    {
      if (!window_id_value->GetAsInteger(&params->window_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* get_info_value = NULL;
  if (args.Get(1, &get_info_value) &&
      !get_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!get_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<GetInfo> temp(new GetInfo());
        if (!GetInfo::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->get_info = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Window& window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((window).ToValue());

  return create_results;
}
}  // namespace Get

namespace GetCurrent {

Params::GetInfo::GetInfo()
 {}

Params::GetInfo::~GetInfo() {}
Params::GetInfo::GetInfo(GetInfo&& rhs)
: populate(std::move(rhs.populate)),
window_types(std::move(rhs.window_types)){
}

Params::GetInfo& Params::GetInfo::operator=(GetInfo&& rhs)
{
populate = std::move(rhs.populate);
window_types = std::move(rhs.window_types);
return *this;
}

// static
bool Params::GetInfo::Populate(
    const base::Value& value, GetInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* populate_value = NULL;
  if (dict->GetWithoutPathExpansion("populate", &populate_value)) {
    {
      bool temp;
      if (!populate_value->GetAsBoolean(&temp)) {
        out->populate.reset();
        return false;
      }
      else
        out->populate.reset(new bool(temp));
    }
  }

  const base::Value* window_types_value = NULL;
  if (dict->GetWithoutPathExpansion("windowTypes", &window_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!window_types_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->window_types.reset(new std::vector<WindowType>);
        for (const auto& it : *(list)) {
          WindowType tmp;
          std::string window_type_as_string;
          if (!(it).GetAsString(&window_type_as_string)) {
            return false;
          }
          tmp = ParseWindowType(window_type_as_string);
          if (tmp == WINDOW_TYPE_NONE) {
            return false;
          }
          out->window_types->push_back(tmp);
        }
      }
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* get_info_value = NULL;
  if (args.Get(0, &get_info_value) &&
      !get_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!get_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<GetInfo> temp(new GetInfo());
        if (!GetInfo::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->get_info = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Window& window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((window).ToValue());

  return create_results;
}
}  // namespace GetCurrent

namespace GetLastFocused {

Params::GetInfo::GetInfo()
 {}

Params::GetInfo::~GetInfo() {}
Params::GetInfo::GetInfo(GetInfo&& rhs)
: populate(std::move(rhs.populate)),
window_types(std::move(rhs.window_types)){
}

Params::GetInfo& Params::GetInfo::operator=(GetInfo&& rhs)
{
populate = std::move(rhs.populate);
window_types = std::move(rhs.window_types);
return *this;
}

// static
bool Params::GetInfo::Populate(
    const base::Value& value, GetInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* populate_value = NULL;
  if (dict->GetWithoutPathExpansion("populate", &populate_value)) {
    {
      bool temp;
      if (!populate_value->GetAsBoolean(&temp)) {
        out->populate.reset();
        return false;
      }
      else
        out->populate.reset(new bool(temp));
    }
  }

  const base::Value* window_types_value = NULL;
  if (dict->GetWithoutPathExpansion("windowTypes", &window_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!window_types_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->window_types.reset(new std::vector<WindowType>);
        for (const auto& it : *(list)) {
          WindowType tmp;
          std::string window_type_as_string;
          if (!(it).GetAsString(&window_type_as_string)) {
            return false;
          }
          tmp = ParseWindowType(window_type_as_string);
          if (tmp == WINDOW_TYPE_NONE) {
            return false;
          }
          out->window_types->push_back(tmp);
        }
      }
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* get_info_value = NULL;
  if (args.Get(0, &get_info_value) &&
      !get_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!get_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<GetInfo> temp(new GetInfo());
        if (!GetInfo::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->get_info = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Window& window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((window).ToValue());

  return create_results;
}
}  // namespace GetLastFocused

namespace GetAll {

Params::GetInfo::GetInfo()
 {}

Params::GetInfo::~GetInfo() {}
Params::GetInfo::GetInfo(GetInfo&& rhs)
: populate(std::move(rhs.populate)),
window_types(std::move(rhs.window_types)){
}

Params::GetInfo& Params::GetInfo::operator=(GetInfo&& rhs)
{
populate = std::move(rhs.populate);
window_types = std::move(rhs.window_types);
return *this;
}

// static
bool Params::GetInfo::Populate(
    const base::Value& value, GetInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* populate_value = NULL;
  if (dict->GetWithoutPathExpansion("populate", &populate_value)) {
    {
      bool temp;
      if (!populate_value->GetAsBoolean(&temp)) {
        out->populate.reset();
        return false;
      }
      else
        out->populate.reset(new bool(temp));
    }
  }

  const base::Value* window_types_value = NULL;
  if (dict->GetWithoutPathExpansion("windowTypes", &window_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!window_types_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->window_types.reset(new std::vector<WindowType>);
        for (const auto& it : *(list)) {
          WindowType tmp;
          std::string window_type_as_string;
          if (!(it).GetAsString(&window_type_as_string)) {
            return false;
          }
          tmp = ParseWindowType(window_type_as_string);
          if (tmp == WINDOW_TYPE_NONE) {
            return false;
          }
          out->window_types->push_back(tmp);
        }
      }
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* get_info_value = NULL;
  if (args.Get(0, &get_info_value) &&
      !get_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!get_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<GetInfo> temp(new GetInfo());
        if (!GetInfo::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->get_info = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Window>& windows) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(windows));

  return create_results;
}
}  // namespace GetAll

namespace Create {

Params::CreateData::Url::Url()
 {}

Params::CreateData::Url::~Url() {}
Params::CreateData::Url::Url(Url&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)){
}

Params::CreateData::Url& Params::CreateData::Url::operator=(Url&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool Params::CreateData::Url::Populate(
    const base::Value& value, Url* out) {
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        out->as_string.reset();
        return false;
      }
      else
        out->as_string.reset(new std::string(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::LIST) {
    {
      const base::ListValue* list = NULL;
      if (!(&value)->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_strings)) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}



Params::CreateData::CreateData()
: type(CREATE_TYPE_NONE),
state(WINDOW_STATE_NONE) {}

Params::CreateData::~CreateData() {}
Params::CreateData::CreateData(CreateData&& rhs)
: url(std::move(rhs.url)),
tab_id(std::move(rhs.tab_id)),
left(std::move(rhs.left)),
top(std::move(rhs.top)),
width(std::move(rhs.width)),
height(std::move(rhs.height)),
focused(std::move(rhs.focused)),
incognito(std::move(rhs.incognito)),
type(rhs.type),
state(rhs.state),
set_self_as_opener(std::move(rhs.set_self_as_opener)){
}

Params::CreateData& Params::CreateData::operator=(CreateData&& rhs)
{
url = std::move(rhs.url);
tab_id = std::move(rhs.tab_id);
left = std::move(rhs.left);
top = std::move(rhs.top);
width = std::move(rhs.width);
height = std::move(rhs.height);
focused = std::move(rhs.focused);
incognito = std::move(rhs.incognito);
type = rhs.type;
state = rhs.state;
set_self_as_opener = std::move(rhs.set_self_as_opener);
return *this;
}

// static
bool Params::CreateData::Populate(
    const base::Value& value, CreateData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = CREATE_TYPE_NONE;
  out->state = WINDOW_STATE_NONE;
  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::unique_ptr<Url> temp(new Url());
      if (!Url::Populate(*url_value, temp.get()))
        return false;
      out->url = std::move(temp);
    }
  }

  const base::Value* tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        out->tab_id.reset();
        return false;
      }
      else
        out->tab_id.reset(new int(temp));
    }
  }

  const base::Value* left_value = NULL;
  if (dict->GetWithoutPathExpansion("left", &left_value)) {
    {
      int temp;
      if (!left_value->GetAsInteger(&temp)) {
        out->left.reset();
        return false;
      }
      else
        out->left.reset(new int(temp));
    }
  }

  const base::Value* top_value = NULL;
  if (dict->GetWithoutPathExpansion("top", &top_value)) {
    {
      int temp;
      if (!top_value->GetAsInteger(&temp)) {
        out->top.reset();
        return false;
      }
      else
        out->top.reset(new int(temp));
    }
  }

  const base::Value* width_value = NULL;
  if (dict->GetWithoutPathExpansion("width", &width_value)) {
    {
      int temp;
      if (!width_value->GetAsInteger(&temp)) {
        out->width.reset();
        return false;
      }
      else
        out->width.reset(new int(temp));
    }
  }

  const base::Value* height_value = NULL;
  if (dict->GetWithoutPathExpansion("height", &height_value)) {
    {
      int temp;
      if (!height_value->GetAsInteger(&temp)) {
        out->height.reset();
        return false;
      }
      else
        out->height.reset(new int(temp));
    }
  }

  const base::Value* focused_value = NULL;
  if (dict->GetWithoutPathExpansion("focused", &focused_value)) {
    {
      bool temp;
      if (!focused_value->GetAsBoolean(&temp)) {
        out->focused.reset();
        return false;
      }
      else
        out->focused.reset(new bool(temp));
    }
  }

  const base::Value* incognito_value = NULL;
  if (dict->GetWithoutPathExpansion("incognito", &incognito_value)) {
    {
      bool temp;
      if (!incognito_value->GetAsBoolean(&temp)) {
        out->incognito.reset();
        return false;
      }
      else
        out->incognito.reset(new bool(temp));
    }
  }

  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string create_type_as_string;
      if (!type_value->GetAsString(&create_type_as_string)) {
        return false;
      }
      out->type = ParseCreateType(create_type_as_string);
      if (out->type == CREATE_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = CREATE_TYPE_NONE;
  }

  const base::Value* state_value = NULL;
  if (dict->GetWithoutPathExpansion("state", &state_value)) {
    {
      std::string window_state_as_string;
      if (!state_value->GetAsString(&window_state_as_string)) {
        return false;
      }
      out->state = ParseWindowState(window_state_as_string);
      if (out->state == WINDOW_STATE_NONE) {
        return false;
      }
    }
    } else {
    out->state = WINDOW_STATE_NONE;
  }

  const base::Value* set_self_as_opener_value = NULL;
  if (dict->GetWithoutPathExpansion("setSelfAsOpener", &set_self_as_opener_value)) {
    {
      bool temp;
      if (!set_self_as_opener_value->GetAsBoolean(&temp)) {
        out->set_self_as_opener.reset();
        return false;
      }
      else
        out->set_self_as_opener.reset(new bool(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* create_data_value = NULL;
  if (args.Get(0, &create_data_value) &&
      !create_data_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!create_data_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<CreateData> temp(new CreateData());
        if (!CreateData::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->create_data = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Window& window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((window).ToValue());

  return create_results;
}
}  // namespace Create

namespace Update {

Params::UpdateInfo::UpdateInfo()
: state(WINDOW_STATE_NONE) {}

Params::UpdateInfo::~UpdateInfo() {}
Params::UpdateInfo::UpdateInfo(UpdateInfo&& rhs)
: left(std::move(rhs.left)),
top(std::move(rhs.top)),
width(std::move(rhs.width)),
height(std::move(rhs.height)),
focused(std::move(rhs.focused)),
draw_attention(std::move(rhs.draw_attention)),
state(rhs.state){
}

Params::UpdateInfo& Params::UpdateInfo::operator=(UpdateInfo&& rhs)
{
left = std::move(rhs.left);
top = std::move(rhs.top);
width = std::move(rhs.width);
height = std::move(rhs.height);
focused = std::move(rhs.focused);
draw_attention = std::move(rhs.draw_attention);
state = rhs.state;
return *this;
}

// static
bool Params::UpdateInfo::Populate(
    const base::Value& value, UpdateInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->state = WINDOW_STATE_NONE;
  const base::Value* left_value = NULL;
  if (dict->GetWithoutPathExpansion("left", &left_value)) {
    {
      int temp;
      if (!left_value->GetAsInteger(&temp)) {
        out->left.reset();
        return false;
      }
      else
        out->left.reset(new int(temp));
    }
  }

  const base::Value* top_value = NULL;
  if (dict->GetWithoutPathExpansion("top", &top_value)) {
    {
      int temp;
      if (!top_value->GetAsInteger(&temp)) {
        out->top.reset();
        return false;
      }
      else
        out->top.reset(new int(temp));
    }
  }

  const base::Value* width_value = NULL;
  if (dict->GetWithoutPathExpansion("width", &width_value)) {
    {
      int temp;
      if (!width_value->GetAsInteger(&temp)) {
        out->width.reset();
        return false;
      }
      else
        out->width.reset(new int(temp));
    }
  }

  const base::Value* height_value = NULL;
  if (dict->GetWithoutPathExpansion("height", &height_value)) {
    {
      int temp;
      if (!height_value->GetAsInteger(&temp)) {
        out->height.reset();
        return false;
      }
      else
        out->height.reset(new int(temp));
    }
  }

  const base::Value* focused_value = NULL;
  if (dict->GetWithoutPathExpansion("focused", &focused_value)) {
    {
      bool temp;
      if (!focused_value->GetAsBoolean(&temp)) {
        out->focused.reset();
        return false;
      }
      else
        out->focused.reset(new bool(temp));
    }
  }

  const base::Value* draw_attention_value = NULL;
  if (dict->GetWithoutPathExpansion("drawAttention", &draw_attention_value)) {
    {
      bool temp;
      if (!draw_attention_value->GetAsBoolean(&temp)) {
        out->draw_attention.reset();
        return false;
      }
      else
        out->draw_attention.reset(new bool(temp));
    }
  }

  const base::Value* state_value = NULL;
  if (dict->GetWithoutPathExpansion("state", &state_value)) {
    {
      std::string window_state_as_string;
      if (!state_value->GetAsString(&window_state_as_string)) {
        return false;
      }
      out->state = ParseWindowState(window_state_as_string);
      if (out->state == WINDOW_STATE_NONE) {
        return false;
      }
    }
    } else {
    out->state = WINDOW_STATE_NONE;
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* window_id_value = NULL;
  if (args.Get(0, &window_id_value) &&
      !window_id_value->is_none()) {
    {
      if (!window_id_value->GetAsInteger(&params->window_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* update_info_value = NULL;
  if (args.Get(1, &update_info_value) &&
      !update_info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!update_info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!UpdateInfo::Populate(*dictionary, &params->update_info)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Window& window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((window).ToValue());

  return create_results;
}
}  // namespace Update

namespace Remove {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* window_id_value = NULL;
  if (args.Get(0, &window_id_value) &&
      !window_id_value->is_none()) {
    {
      if (!window_id_value->GetAsInteger(&params->window_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Remove

//
// Events
//

namespace OnCreated {

const char kEventName[] = "windows.onCreated";

std::unique_ptr<base::ListValue> Create(const Window& window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((window).ToValue());

  return create_results;
}

}  // namespace OnCreated

namespace OnRemoved {

const char kEventName[] = "windows.onRemoved";

std::unique_ptr<base::ListValue> Create(int window_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(window_id));

  return create_results;
}

}  // namespace OnRemoved

namespace OnFocusChanged {

const char kEventName[] = "windows.onFocusChanged";

std::unique_ptr<base::ListValue> Create(int window_id) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(window_id));

  return create_results;
}

}  // namespace OnFocusChanged

}  // namespace windows
}  // namespace api
}  // namespace extensions

