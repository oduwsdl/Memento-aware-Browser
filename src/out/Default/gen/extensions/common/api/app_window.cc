// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/app_window.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/app_window.h"
#include <set>
#include <utility>
#include "extensions/common/api/app_runtime.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace app_window {
//
// Types
//

ContentBounds::ContentBounds()
 {}

ContentBounds::~ContentBounds() {}
ContentBounds::ContentBounds(ContentBounds&& rhs)
: left(std::move(rhs.left)),
top(std::move(rhs.top)),
width(std::move(rhs.width)),
height(std::move(rhs.height)){
}

ContentBounds& ContentBounds::operator=(ContentBounds&& rhs)
{
left = std::move(rhs.left);
top = std::move(rhs.top);
width = std::move(rhs.width);
height = std::move(rhs.height);
return *this;
}

// static
bool ContentBounds::Populate(
    const base::Value& value, ContentBounds* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  return true;
}

// static
std::unique_ptr<ContentBounds> ContentBounds::FromValue(const base::Value& value) {
  std::unique_ptr<ContentBounds> out(new ContentBounds());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ContentBounds::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->left.get()) {
    to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(*this->left));

  }
  if (this->top.get()) {
    to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(*this->top));

  }
  if (this->width.get()) {
    to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(*this->width));

  }
  if (this->height.get()) {
    to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(*this->height));

  }

  return to_value_result;
}


BoundsSpecification::BoundsSpecification()
 {}

BoundsSpecification::~BoundsSpecification() {}
BoundsSpecification::BoundsSpecification(BoundsSpecification&& rhs)
: left(std::move(rhs.left)),
top(std::move(rhs.top)),
width(std::move(rhs.width)),
height(std::move(rhs.height)),
min_width(std::move(rhs.min_width)),
min_height(std::move(rhs.min_height)),
max_width(std::move(rhs.max_width)),
max_height(std::move(rhs.max_height)){
}

BoundsSpecification& BoundsSpecification::operator=(BoundsSpecification&& rhs)
{
left = std::move(rhs.left);
top = std::move(rhs.top);
width = std::move(rhs.width);
height = std::move(rhs.height);
min_width = std::move(rhs.min_width);
min_height = std::move(rhs.min_height);
max_width = std::move(rhs.max_width);
max_height = std::move(rhs.max_height);
return *this;
}

// static
bool BoundsSpecification::Populate(
    const base::Value& value, BoundsSpecification* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* min_width_value = NULL;
  if (dict->GetWithoutPathExpansion("minWidth", &min_width_value)) {
    {
      int temp;
      if (!min_width_value->GetAsInteger(&temp)) {
        out->min_width.reset();
        return false;
      }
      else
        out->min_width.reset(new int(temp));
    }
  }

  const base::Value* min_height_value = NULL;
  if (dict->GetWithoutPathExpansion("minHeight", &min_height_value)) {
    {
      int temp;
      if (!min_height_value->GetAsInteger(&temp)) {
        out->min_height.reset();
        return false;
      }
      else
        out->min_height.reset(new int(temp));
    }
  }

  const base::Value* max_width_value = NULL;
  if (dict->GetWithoutPathExpansion("maxWidth", &max_width_value)) {
    {
      int temp;
      if (!max_width_value->GetAsInteger(&temp)) {
        out->max_width.reset();
        return false;
      }
      else
        out->max_width.reset(new int(temp));
    }
  }

  const base::Value* max_height_value = NULL;
  if (dict->GetWithoutPathExpansion("maxHeight", &max_height_value)) {
    {
      int temp;
      if (!max_height_value->GetAsInteger(&temp)) {
        out->max_height.reset();
        return false;
      }
      else
        out->max_height.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<BoundsSpecification> BoundsSpecification::FromValue(const base::Value& value) {
  std::unique_ptr<BoundsSpecification> out(new BoundsSpecification());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> BoundsSpecification::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->left.get()) {
    to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(*this->left));

  }
  if (this->top.get()) {
    to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(*this->top));

  }
  if (this->width.get()) {
    to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(*this->width));

  }
  if (this->height.get()) {
    to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(*this->height));

  }
  if (this->min_width.get()) {
    to_value_result->SetWithoutPathExpansion("minWidth", std::make_unique<base::Value>(*this->min_width));

  }
  if (this->min_height.get()) {
    to_value_result->SetWithoutPathExpansion("minHeight", std::make_unique<base::Value>(*this->min_height));

  }
  if (this->max_width.get()) {
    to_value_result->SetWithoutPathExpansion("maxWidth", std::make_unique<base::Value>(*this->max_width));

  }
  if (this->max_height.get()) {
    to_value_result->SetWithoutPathExpansion("maxHeight", std::make_unique<base::Value>(*this->max_height));

  }

  return to_value_result;
}


Bounds::Bounds()
: left(0),
top(0),
width(0),
height(0) {}

Bounds::~Bounds() {}
Bounds::Bounds(Bounds&& rhs)
: left(rhs.left),
top(rhs.top),
width(rhs.width),
height(rhs.height),
min_width(std::move(rhs.min_width)),
min_height(std::move(rhs.min_height)),
max_width(std::move(rhs.max_width)),
max_height(std::move(rhs.max_height)){
set_position.Swap(&rhs.set_position);
set_size.Swap(&rhs.set_size);
set_minimum_size.Swap(&rhs.set_minimum_size);
set_maximum_size.Swap(&rhs.set_maximum_size);
}

Bounds& Bounds::operator=(Bounds&& rhs)
{
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
min_width = std::move(rhs.min_width);
min_height = std::move(rhs.min_height);
max_width = std::move(rhs.max_width);
max_height = std::move(rhs.max_height);set_position.Swap(&rhs.set_position);set_size.Swap(&rhs.set_size);set_minimum_size.Swap(&rhs.set_minimum_size);set_maximum_size.Swap(&rhs.set_maximum_size);
return *this;
}

// static
bool Bounds::Populate(
    const base::Value& value, Bounds* out) {
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

  const base::Value* min_width_value = NULL;
  if (dict->GetWithoutPathExpansion("minWidth", &min_width_value)) {
    {
      int temp;
      if (!min_width_value->GetAsInteger(&temp)) {
        out->min_width.reset();
        return false;
      }
      else
        out->min_width.reset(new int(temp));
    }
  }

  const base::Value* min_height_value = NULL;
  if (dict->GetWithoutPathExpansion("minHeight", &min_height_value)) {
    {
      int temp;
      if (!min_height_value->GetAsInteger(&temp)) {
        out->min_height.reset();
        return false;
      }
      else
        out->min_height.reset(new int(temp));
    }
  }

  const base::Value* max_width_value = NULL;
  if (dict->GetWithoutPathExpansion("maxWidth", &max_width_value)) {
    {
      int temp;
      if (!max_width_value->GetAsInteger(&temp)) {
        out->max_width.reset();
        return false;
      }
      else
        out->max_width.reset(new int(temp));
    }
  }

  const base::Value* max_height_value = NULL;
  if (dict->GetWithoutPathExpansion("maxHeight", &max_height_value)) {
    {
      int temp;
      if (!max_height_value->GetAsInteger(&temp)) {
        out->max_height.reset();
        return false;
      }
      else
        out->max_height.reset(new int(temp));
    }
  }

  const base::Value* set_position_value = NULL;
  if (!dict->GetWithoutPathExpansion("setPosition", &set_position_value)) {
    return false;
  }

  const base::Value* set_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("setSize", &set_size_value)) {
    return false;
  }

  const base::Value* set_minimum_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("setMinimumSize", &set_minimum_size_value)) {
    return false;
  }

  const base::Value* set_maximum_size_value = NULL;
  if (!dict->GetWithoutPathExpansion("setMaximumSize", &set_maximum_size_value)) {
    return false;
  }

  return true;
}

// static
std::unique_ptr<Bounds> Bounds::FromValue(const base::Value& value) {
  std::unique_ptr<Bounds> out(new Bounds());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Bounds::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));

  if (this->min_width.get()) {
    to_value_result->SetWithoutPathExpansion("minWidth", std::make_unique<base::Value>(*this->min_width));

  }
  if (this->min_height.get()) {
    to_value_result->SetWithoutPathExpansion("minHeight", std::make_unique<base::Value>(*this->min_height));

  }
  if (this->max_width.get()) {
    to_value_result->SetWithoutPathExpansion("maxWidth", std::make_unique<base::Value>(*this->max_width));

  }
  if (this->max_height.get()) {
    to_value_result->SetWithoutPathExpansion("maxHeight", std::make_unique<base::Value>(*this->max_height));

  }
  to_value_result->SetWithoutPathExpansion("setPosition", (this->set_position).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("setSize", (this->set_size).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("setMinimumSize", (this->set_minimum_size).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("setMaximumSize", (this->set_maximum_size).CreateDeepCopy());


  return to_value_result;
}


FrameOptions::FrameOptions()
 {}

FrameOptions::~FrameOptions() {}
FrameOptions::FrameOptions(FrameOptions&& rhs)
: type(std::move(rhs.type)),
color(std::move(rhs.color)),
active_color(std::move(rhs.active_color)),
inactive_color(std::move(rhs.inactive_color)){
}

FrameOptions& FrameOptions::operator=(FrameOptions&& rhs)
{
type = std::move(rhs.type);
color = std::move(rhs.color);
active_color = std::move(rhs.active_color);
inactive_color = std::move(rhs.inactive_color);
return *this;
}

// static
bool FrameOptions::Populate(
    const base::Value& value, FrameOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string temp;
      if (!type_value->GetAsString(&temp)) {
        out->type.reset();
        return false;
      }
      else
        out->type.reset(new std::string(temp));
    }
  }

  const base::Value* color_value = NULL;
  if (dict->GetWithoutPathExpansion("color", &color_value)) {
    {
      std::string temp;
      if (!color_value->GetAsString(&temp)) {
        out->color.reset();
        return false;
      }
      else
        out->color.reset(new std::string(temp));
    }
  }

  const base::Value* active_color_value = NULL;
  if (dict->GetWithoutPathExpansion("activeColor", &active_color_value)) {
    {
      std::string temp;
      if (!active_color_value->GetAsString(&temp)) {
        out->active_color.reset();
        return false;
      }
      else
        out->active_color.reset(new std::string(temp));
    }
  }

  const base::Value* inactive_color_value = NULL;
  if (dict->GetWithoutPathExpansion("inactiveColor", &inactive_color_value)) {
    {
      std::string temp;
      if (!inactive_color_value->GetAsString(&temp)) {
        out->inactive_color.reset();
        return false;
      }
      else
        out->inactive_color.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<FrameOptions> FrameOptions::FromValue(const base::Value& value) {
  std::unique_ptr<FrameOptions> out(new FrameOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FrameOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->type.get()) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(*this->type));

  }
  if (this->color.get()) {
    to_value_result->SetWithoutPathExpansion("color", std::make_unique<base::Value>(*this->color));

  }
  if (this->active_color.get()) {
    to_value_result->SetWithoutPathExpansion("activeColor", std::make_unique<base::Value>(*this->active_color));

  }
  if (this->inactive_color.get()) {
    to_value_result->SetWithoutPathExpansion("inactiveColor", std::make_unique<base::Value>(*this->inactive_color));

  }

  return to_value_result;
}


const char* ToString(State enum_param) {
  switch (enum_param) {
    case STATE_NORMAL:
      return "normal";
    case STATE_FULLSCREEN:
      return "fullscreen";
    case STATE_MAXIMIZED:
      return "maximized";
    case STATE_MINIMIZED:
      return "minimized";
    case STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

State ParseState(const std::string& enum_string) {
  if (enum_string == "normal")
    return STATE_NORMAL;
  if (enum_string == "fullscreen")
    return STATE_FULLSCREEN;
  if (enum_string == "maximized")
    return STATE_MAXIMIZED;
  if (enum_string == "minimized")
    return STATE_MINIMIZED;
  return STATE_NONE;
}


const char* ToString(WindowType enum_param) {
  switch (enum_param) {
    case WINDOW_TYPE_SHELL:
      return "shell";
    case WINDOW_TYPE_PANEL:
      return "panel";
    case WINDOW_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

WindowType ParseWindowType(const std::string& enum_string) {
  if (enum_string == "shell")
    return WINDOW_TYPE_SHELL;
  if (enum_string == "panel")
    return WINDOW_TYPE_PANEL;
  return WINDOW_TYPE_NONE;
}


CreateWindowOptions::Frame::Frame()
 {}

CreateWindowOptions::Frame::~Frame() {}
CreateWindowOptions::Frame::Frame(Frame&& rhs)
: as_string(std::move(rhs.as_string)),
as_frame_options(std::move(rhs.as_frame_options)){
}

CreateWindowOptions::Frame& CreateWindowOptions::Frame::operator=(Frame&& rhs)
{
as_string = std::move(rhs.as_string);
as_frame_options = std::move(rhs.as_frame_options);
return *this;
}

// static
bool CreateWindowOptions::Frame::Populate(
    const base::Value& value, Frame* out) {
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
  if (value.type() == base::Value::Type::DICTIONARY) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!(&value)->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<FrameOptions> temp(new FrameOptions());
        if (!FrameOptions::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->as_frame_options = std::move(temp);
      }
    }
    return true;
  }
  return false;
}

std::unique_ptr<base::Value> CreateWindowOptions::Frame::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for frame";
    result = std::make_unique<base::Value>(*as_string);

  }
  if (as_frame_options) {
    DCHECK(!result) << "Cannot set multiple choices for frame";
    result = (as_frame_options)->ToValue();

  }
  DCHECK(result) << "Must set at least one choice for frame";
  return result;
}



CreateWindowOptions::CreateWindowOptions()
: type(WINDOW_TYPE_NONE),
state(STATE_NONE),
lock_screen_action(app_runtime::ACTION_TYPE_NONE) {}

CreateWindowOptions::~CreateWindowOptions() {}
CreateWindowOptions::CreateWindowOptions(CreateWindowOptions&& rhs)
: id(std::move(rhs.id)),
inner_bounds(std::move(rhs.inner_bounds)),
outer_bounds(std::move(rhs.outer_bounds)),
default_width(std::move(rhs.default_width)),
default_height(std::move(rhs.default_height)),
default_left(std::move(rhs.default_left)),
default_top(std::move(rhs.default_top)),
width(std::move(rhs.width)),
height(std::move(rhs.height)),
left(std::move(rhs.left)),
top(std::move(rhs.top)),
min_width(std::move(rhs.min_width)),
min_height(std::move(rhs.min_height)),
max_width(std::move(rhs.max_width)),
max_height(std::move(rhs.max_height)),
type(rhs.type),
ime(std::move(rhs.ime)),
show_in_shelf(std::move(rhs.show_in_shelf)),
icon(std::move(rhs.icon)),
frame(std::move(rhs.frame)),
bounds(std::move(rhs.bounds)),
alpha_enabled(std::move(rhs.alpha_enabled)),
state(rhs.state),
hidden(std::move(rhs.hidden)),
resizable(std::move(rhs.resizable)),
singleton(std::move(rhs.singleton)),
always_on_top(std::move(rhs.always_on_top)),
focused(std::move(rhs.focused)),
visible_on_all_workspaces(std::move(rhs.visible_on_all_workspaces)),
lock_screen_action(rhs.lock_screen_action){
}

CreateWindowOptions& CreateWindowOptions::operator=(CreateWindowOptions&& rhs)
{
id = std::move(rhs.id);
inner_bounds = std::move(rhs.inner_bounds);
outer_bounds = std::move(rhs.outer_bounds);
default_width = std::move(rhs.default_width);
default_height = std::move(rhs.default_height);
default_left = std::move(rhs.default_left);
default_top = std::move(rhs.default_top);
width = std::move(rhs.width);
height = std::move(rhs.height);
left = std::move(rhs.left);
top = std::move(rhs.top);
min_width = std::move(rhs.min_width);
min_height = std::move(rhs.min_height);
max_width = std::move(rhs.max_width);
max_height = std::move(rhs.max_height);
type = rhs.type;
ime = std::move(rhs.ime);
show_in_shelf = std::move(rhs.show_in_shelf);
icon = std::move(rhs.icon);
frame = std::move(rhs.frame);
bounds = std::move(rhs.bounds);
alpha_enabled = std::move(rhs.alpha_enabled);
state = rhs.state;
hidden = std::move(rhs.hidden);
resizable = std::move(rhs.resizable);
singleton = std::move(rhs.singleton);
always_on_top = std::move(rhs.always_on_top);
focused = std::move(rhs.focused);
visible_on_all_workspaces = std::move(rhs.visible_on_all_workspaces);
lock_screen_action = rhs.lock_screen_action;
return *this;
}

// static
bool CreateWindowOptions::Populate(
    const base::Value& value, CreateWindowOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = WINDOW_TYPE_NONE;
  out->state = STATE_NONE;
  out->lock_screen_action = app_runtime::ACTION_TYPE_NONE;
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

  const base::Value* inner_bounds_value = NULL;
  if (dict->GetWithoutPathExpansion("innerBounds", &inner_bounds_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!inner_bounds_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<BoundsSpecification> temp(new BoundsSpecification());
        if (!BoundsSpecification::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->inner_bounds = std::move(temp);
      }
    }
  }

  const base::Value* outer_bounds_value = NULL;
  if (dict->GetWithoutPathExpansion("outerBounds", &outer_bounds_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!outer_bounds_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<BoundsSpecification> temp(new BoundsSpecification());
        if (!BoundsSpecification::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->outer_bounds = std::move(temp);
      }
    }
  }

  const base::Value* default_width_value = NULL;
  if (dict->GetWithoutPathExpansion("defaultWidth", &default_width_value)) {
    {
      int temp;
      if (!default_width_value->GetAsInteger(&temp)) {
        out->default_width.reset();
        return false;
      }
      else
        out->default_width.reset(new int(temp));
    }
  }

  const base::Value* default_height_value = NULL;
  if (dict->GetWithoutPathExpansion("defaultHeight", &default_height_value)) {
    {
      int temp;
      if (!default_height_value->GetAsInteger(&temp)) {
        out->default_height.reset();
        return false;
      }
      else
        out->default_height.reset(new int(temp));
    }
  }

  const base::Value* default_left_value = NULL;
  if (dict->GetWithoutPathExpansion("defaultLeft", &default_left_value)) {
    {
      int temp;
      if (!default_left_value->GetAsInteger(&temp)) {
        out->default_left.reset();
        return false;
      }
      else
        out->default_left.reset(new int(temp));
    }
  }

  const base::Value* default_top_value = NULL;
  if (dict->GetWithoutPathExpansion("defaultTop", &default_top_value)) {
    {
      int temp;
      if (!default_top_value->GetAsInteger(&temp)) {
        out->default_top.reset();
        return false;
      }
      else
        out->default_top.reset(new int(temp));
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

  const base::Value* min_width_value = NULL;
  if (dict->GetWithoutPathExpansion("minWidth", &min_width_value)) {
    {
      int temp;
      if (!min_width_value->GetAsInteger(&temp)) {
        out->min_width.reset();
        return false;
      }
      else
        out->min_width.reset(new int(temp));
    }
  }

  const base::Value* min_height_value = NULL;
  if (dict->GetWithoutPathExpansion("minHeight", &min_height_value)) {
    {
      int temp;
      if (!min_height_value->GetAsInteger(&temp)) {
        out->min_height.reset();
        return false;
      }
      else
        out->min_height.reset(new int(temp));
    }
  }

  const base::Value* max_width_value = NULL;
  if (dict->GetWithoutPathExpansion("maxWidth", &max_width_value)) {
    {
      int temp;
      if (!max_width_value->GetAsInteger(&temp)) {
        out->max_width.reset();
        return false;
      }
      else
        out->max_width.reset(new int(temp));
    }
  }

  const base::Value* max_height_value = NULL;
  if (dict->GetWithoutPathExpansion("maxHeight", &max_height_value)) {
    {
      int temp;
      if (!max_height_value->GetAsInteger(&temp)) {
        out->max_height.reset();
        return false;
      }
      else
        out->max_height.reset(new int(temp));
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

  const base::Value* ime_value = NULL;
  if (dict->GetWithoutPathExpansion("ime", &ime_value)) {
    {
      bool temp;
      if (!ime_value->GetAsBoolean(&temp)) {
        out->ime.reset();
        return false;
      }
      else
        out->ime.reset(new bool(temp));
    }
  }

  const base::Value* show_in_shelf_value = NULL;
  if (dict->GetWithoutPathExpansion("showInShelf", &show_in_shelf_value)) {
    {
      bool temp;
      if (!show_in_shelf_value->GetAsBoolean(&temp)) {
        out->show_in_shelf.reset();
        return false;
      }
      else
        out->show_in_shelf.reset(new bool(temp));
    }
  }

  const base::Value* icon_value = NULL;
  if (dict->GetWithoutPathExpansion("icon", &icon_value)) {
    {
      std::string temp;
      if (!icon_value->GetAsString(&temp)) {
        out->icon.reset();
        return false;
      }
      else
        out->icon.reset(new std::string(temp));
    }
  }

  const base::Value* frame_value = NULL;
  if (dict->GetWithoutPathExpansion("frame", &frame_value)) {
    {
      std::unique_ptr<Frame> temp(new Frame());
      if (!Frame::Populate(*frame_value, temp.get()))
        return false;
      out->frame = std::move(temp);
    }
  }

  const base::Value* bounds_value = NULL;
  if (dict->GetWithoutPathExpansion("bounds", &bounds_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!bounds_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<ContentBounds> temp(new ContentBounds());
        if (!ContentBounds::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->bounds = std::move(temp);
      }
    }
  }

  const base::Value* alpha_enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("alphaEnabled", &alpha_enabled_value)) {
    {
      bool temp;
      if (!alpha_enabled_value->GetAsBoolean(&temp)) {
        out->alpha_enabled.reset();
        return false;
      }
      else
        out->alpha_enabled.reset(new bool(temp));
    }
  }

  const base::Value* state_value = NULL;
  if (dict->GetWithoutPathExpansion("state", &state_value)) {
    {
      std::string state_as_string;
      if (!state_value->GetAsString(&state_as_string)) {
        return false;
      }
      out->state = ParseState(state_as_string);
      if (out->state == STATE_NONE) {
        return false;
      }
    }
    } else {
    out->state = STATE_NONE;
  }

  const base::Value* hidden_value = NULL;
  if (dict->GetWithoutPathExpansion("hidden", &hidden_value)) {
    {
      bool temp;
      if (!hidden_value->GetAsBoolean(&temp)) {
        out->hidden.reset();
        return false;
      }
      else
        out->hidden.reset(new bool(temp));
    }
  }

  const base::Value* resizable_value = NULL;
  if (dict->GetWithoutPathExpansion("resizable", &resizable_value)) {
    {
      bool temp;
      if (!resizable_value->GetAsBoolean(&temp)) {
        out->resizable.reset();
        return false;
      }
      else
        out->resizable.reset(new bool(temp));
    }
  }

  const base::Value* singleton_value = NULL;
  if (dict->GetWithoutPathExpansion("singleton", &singleton_value)) {
    {
      bool temp;
      if (!singleton_value->GetAsBoolean(&temp)) {
        out->singleton.reset();
        return false;
      }
      else
        out->singleton.reset(new bool(temp));
    }
  }

  const base::Value* always_on_top_value = NULL;
  if (dict->GetWithoutPathExpansion("alwaysOnTop", &always_on_top_value)) {
    {
      bool temp;
      if (!always_on_top_value->GetAsBoolean(&temp)) {
        out->always_on_top.reset();
        return false;
      }
      else
        out->always_on_top.reset(new bool(temp));
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

  const base::Value* visible_on_all_workspaces_value = NULL;
  if (dict->GetWithoutPathExpansion("visibleOnAllWorkspaces", &visible_on_all_workspaces_value)) {
    {
      bool temp;
      if (!visible_on_all_workspaces_value->GetAsBoolean(&temp)) {
        out->visible_on_all_workspaces.reset();
        return false;
      }
      else
        out->visible_on_all_workspaces.reset(new bool(temp));
    }
  }

  const base::Value* lock_screen_action_value = NULL;
  if (dict->GetWithoutPathExpansion("lockScreenAction", &lock_screen_action_value)) {
    {
      std::string action_type_as_string;
      if (!lock_screen_action_value->GetAsString(&action_type_as_string)) {
        return false;
      }
      out->lock_screen_action = app_runtime::ParseActionType(action_type_as_string);
      if (out->lock_screen_action == app_runtime::ACTION_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->lock_screen_action = app_runtime::ACTION_TYPE_NONE;
  }

  return true;
}

// static
std::unique_ptr<CreateWindowOptions> CreateWindowOptions::FromValue(const base::Value& value) {
  std::unique_ptr<CreateWindowOptions> out(new CreateWindowOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CreateWindowOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }
  if (this->inner_bounds.get()) {
    to_value_result->SetWithoutPathExpansion("innerBounds", (this->inner_bounds)->ToValue());

  }
  if (this->outer_bounds.get()) {
    to_value_result->SetWithoutPathExpansion("outerBounds", (this->outer_bounds)->ToValue());

  }
  if (this->default_width.get()) {
    to_value_result->SetWithoutPathExpansion("defaultWidth", std::make_unique<base::Value>(*this->default_width));

  }
  if (this->default_height.get()) {
    to_value_result->SetWithoutPathExpansion("defaultHeight", std::make_unique<base::Value>(*this->default_height));

  }
  if (this->default_left.get()) {
    to_value_result->SetWithoutPathExpansion("defaultLeft", std::make_unique<base::Value>(*this->default_left));

  }
  if (this->default_top.get()) {
    to_value_result->SetWithoutPathExpansion("defaultTop", std::make_unique<base::Value>(*this->default_top));

  }
  if (this->width.get()) {
    to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(*this->width));

  }
  if (this->height.get()) {
    to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(*this->height));

  }
  if (this->left.get()) {
    to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(*this->left));

  }
  if (this->top.get()) {
    to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(*this->top));

  }
  if (this->min_width.get()) {
    to_value_result->SetWithoutPathExpansion("minWidth", std::make_unique<base::Value>(*this->min_width));

  }
  if (this->min_height.get()) {
    to_value_result->SetWithoutPathExpansion("minHeight", std::make_unique<base::Value>(*this->min_height));

  }
  if (this->max_width.get()) {
    to_value_result->SetWithoutPathExpansion("maxWidth", std::make_unique<base::Value>(*this->max_width));

  }
  if (this->max_height.get()) {
    to_value_result->SetWithoutPathExpansion("maxHeight", std::make_unique<base::Value>(*this->max_height));

  }
  if (this->type != WINDOW_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(app_window::ToString(this->type)));

  }
  if (this->ime.get()) {
    to_value_result->SetWithoutPathExpansion("ime", std::make_unique<base::Value>(*this->ime));

  }
  if (this->show_in_shelf.get()) {
    to_value_result->SetWithoutPathExpansion("showInShelf", std::make_unique<base::Value>(*this->show_in_shelf));

  }
  if (this->icon.get()) {
    to_value_result->SetWithoutPathExpansion("icon", std::make_unique<base::Value>(*this->icon));

  }
  if (this->frame.get()) {
    to_value_result->SetWithoutPathExpansion("frame", (this->frame)->ToValue());

  }
  if (this->bounds.get()) {
    to_value_result->SetWithoutPathExpansion("bounds", (this->bounds)->ToValue());

  }
  if (this->alpha_enabled.get()) {
    to_value_result->SetWithoutPathExpansion("alphaEnabled", std::make_unique<base::Value>(*this->alpha_enabled));

  }
  if (this->state != STATE_NONE) {
    to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(app_window::ToString(this->state)));

  }
  if (this->hidden.get()) {
    to_value_result->SetWithoutPathExpansion("hidden", std::make_unique<base::Value>(*this->hidden));

  }
  if (this->resizable.get()) {
    to_value_result->SetWithoutPathExpansion("resizable", std::make_unique<base::Value>(*this->resizable));

  }
  if (this->singleton.get()) {
    to_value_result->SetWithoutPathExpansion("singleton", std::make_unique<base::Value>(*this->singleton));

  }
  if (this->always_on_top.get()) {
    to_value_result->SetWithoutPathExpansion("alwaysOnTop", std::make_unique<base::Value>(*this->always_on_top));

  }
  if (this->focused.get()) {
    to_value_result->SetWithoutPathExpansion("focused", std::make_unique<base::Value>(*this->focused));

  }
  if (this->visible_on_all_workspaces.get()) {
    to_value_result->SetWithoutPathExpansion("visibleOnAllWorkspaces", std::make_unique<base::Value>(*this->visible_on_all_workspaces));

  }
  if (this->lock_screen_action != app_runtime::ACTION_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("lockScreenAction", std::make_unique<base::Value>(app_runtime::ToString(this->lock_screen_action)));

  }

  return to_value_result;
}


AppWindow::ContentWindow::ContentWindow()
 {}

AppWindow::ContentWindow::~ContentWindow() {}
AppWindow::ContentWindow::ContentWindow(ContentWindow&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

AppWindow::ContentWindow& AppWindow::ContentWindow::operator=(ContentWindow&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

// static
bool AppWindow::ContentWindow::Populate(
    const base::Value& value, ContentWindow* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->additional_properties.MergeDictionary(dict);
  return true;
}

std::unique_ptr<base::DictionaryValue> AppWindow::ContentWindow::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}



AppWindow::AppWindow()
: has_frame_color(false),
active_frame_color(0),
inactive_frame_color(0) {}

AppWindow::~AppWindow() {}
AppWindow::AppWindow(AppWindow&& rhs)
: has_frame_color(rhs.has_frame_color),
active_frame_color(rhs.active_frame_color),
inactive_frame_color(rhs.inactive_frame_color),
content_window(std::move(rhs.content_window)),
id(std::move(rhs.id)),
inner_bounds(std::move(rhs.inner_bounds)),
outer_bounds(std::move(rhs.outer_bounds)){
focus.Swap(&rhs.focus);
fullscreen.Swap(&rhs.fullscreen);
is_fullscreen.Swap(&rhs.is_fullscreen);
minimize.Swap(&rhs.minimize);
is_minimized.Swap(&rhs.is_minimized);
maximize.Swap(&rhs.maximize);
is_maximized.Swap(&rhs.is_maximized);
restore.Swap(&rhs.restore);
move_to.Swap(&rhs.move_to);
resize_to.Swap(&rhs.resize_to);
draw_attention.Swap(&rhs.draw_attention);
clear_attention.Swap(&rhs.clear_attention);
close.Swap(&rhs.close);
show.Swap(&rhs.show);
hide.Swap(&rhs.hide);
set_icon.Swap(&rhs.set_icon);
is_always_on_top.Swap(&rhs.is_always_on_top);
set_always_on_top.Swap(&rhs.set_always_on_top);
alpha_enabled.Swap(&rhs.alpha_enabled);
set_visible_on_all_workspaces.Swap(&rhs.set_visible_on_all_workspaces);
}

AppWindow& AppWindow::operator=(AppWindow&& rhs)
{
has_frame_color = rhs.has_frame_color;
active_frame_color = rhs.active_frame_color;
inactive_frame_color = rhs.inactive_frame_color;
content_window = std::move(rhs.content_window);
id = std::move(rhs.id);
inner_bounds = std::move(rhs.inner_bounds);
outer_bounds = std::move(rhs.outer_bounds);focus.Swap(&rhs.focus);fullscreen.Swap(&rhs.fullscreen);is_fullscreen.Swap(&rhs.is_fullscreen);minimize.Swap(&rhs.minimize);is_minimized.Swap(&rhs.is_minimized);maximize.Swap(&rhs.maximize);is_maximized.Swap(&rhs.is_maximized);restore.Swap(&rhs.restore);move_to.Swap(&rhs.move_to);resize_to.Swap(&rhs.resize_to);draw_attention.Swap(&rhs.draw_attention);clear_attention.Swap(&rhs.clear_attention);close.Swap(&rhs.close);show.Swap(&rhs.show);hide.Swap(&rhs.hide);set_icon.Swap(&rhs.set_icon);is_always_on_top.Swap(&rhs.is_always_on_top);set_always_on_top.Swap(&rhs.set_always_on_top);alpha_enabled.Swap(&rhs.alpha_enabled);set_visible_on_all_workspaces.Swap(&rhs.set_visible_on_all_workspaces);
return *this;
}

// static
bool AppWindow::Populate(
    const base::Value& value, AppWindow* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* focus_value = NULL;
  if (!dict->GetWithoutPathExpansion("focus", &focus_value)) {
    return false;
  }

  const base::Value* fullscreen_value = NULL;
  if (!dict->GetWithoutPathExpansion("fullscreen", &fullscreen_value)) {
    return false;
  }

  const base::Value* is_fullscreen_value = NULL;
  if (!dict->GetWithoutPathExpansion("isFullscreen", &is_fullscreen_value)) {
    return false;
  }

  const base::Value* minimize_value = NULL;
  if (!dict->GetWithoutPathExpansion("minimize", &minimize_value)) {
    return false;
  }

  const base::Value* is_minimized_value = NULL;
  if (!dict->GetWithoutPathExpansion("isMinimized", &is_minimized_value)) {
    return false;
  }

  const base::Value* maximize_value = NULL;
  if (!dict->GetWithoutPathExpansion("maximize", &maximize_value)) {
    return false;
  }

  const base::Value* is_maximized_value = NULL;
  if (!dict->GetWithoutPathExpansion("isMaximized", &is_maximized_value)) {
    return false;
  }

  const base::Value* restore_value = NULL;
  if (!dict->GetWithoutPathExpansion("restore", &restore_value)) {
    return false;
  }

  const base::Value* move_to_value = NULL;
  if (!dict->GetWithoutPathExpansion("moveTo", &move_to_value)) {
    return false;
  }

  const base::Value* resize_to_value = NULL;
  if (!dict->GetWithoutPathExpansion("resizeTo", &resize_to_value)) {
    return false;
  }

  const base::Value* draw_attention_value = NULL;
  if (!dict->GetWithoutPathExpansion("drawAttention", &draw_attention_value)) {
    return false;
  }

  const base::Value* clear_attention_value = NULL;
  if (!dict->GetWithoutPathExpansion("clearAttention", &clear_attention_value)) {
    return false;
  }

  const base::Value* close_value = NULL;
  if (!dict->GetWithoutPathExpansion("close", &close_value)) {
    return false;
  }

  const base::Value* show_value = NULL;
  if (!dict->GetWithoutPathExpansion("show", &show_value)) {
    return false;
  }

  const base::Value* hide_value = NULL;
  if (!dict->GetWithoutPathExpansion("hide", &hide_value)) {
    return false;
  }

  const base::Value* set_icon_value = NULL;
  if (!dict->GetWithoutPathExpansion("setIcon", &set_icon_value)) {
    return false;
  }

  const base::Value* is_always_on_top_value = NULL;
  if (!dict->GetWithoutPathExpansion("isAlwaysOnTop", &is_always_on_top_value)) {
    return false;
  }

  const base::Value* has_frame_color_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasFrameColor", &has_frame_color_value)) {
    return false;
  }
  {
    if (!has_frame_color_value->GetAsBoolean(&out->has_frame_color)) {
      return false;
    }
  }

  const base::Value* active_frame_color_value = NULL;
  if (!dict->GetWithoutPathExpansion("activeFrameColor", &active_frame_color_value)) {
    return false;
  }
  {
    if (!active_frame_color_value->GetAsInteger(&out->active_frame_color)) {
      return false;
    }
  }

  const base::Value* inactive_frame_color_value = NULL;
  if (!dict->GetWithoutPathExpansion("inactiveFrameColor", &inactive_frame_color_value)) {
    return false;
  }
  {
    if (!inactive_frame_color_value->GetAsInteger(&out->inactive_frame_color)) {
      return false;
    }
  }

  const base::Value* set_always_on_top_value = NULL;
  if (!dict->GetWithoutPathExpansion("setAlwaysOnTop", &set_always_on_top_value)) {
    return false;
  }

  const base::Value* alpha_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("alphaEnabled", &alpha_enabled_value)) {
    return false;
  }

  const base::Value* set_visible_on_all_workspaces_value = NULL;
  if (!dict->GetWithoutPathExpansion("setVisibleOnAllWorkspaces", &set_visible_on_all_workspaces_value)) {
    return false;
  }

  const base::Value* content_window_value = NULL;
  if (!dict->GetWithoutPathExpansion("contentWindow", &content_window_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!content_window_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!ContentWindow::Populate(*dictionary, &out->content_window)) {
      return false;
    }
  }

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* inner_bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("innerBounds", &inner_bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!inner_bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->inner_bounds)) {
      return false;
    }
  }

  const base::Value* outer_bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("outerBounds", &outer_bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!outer_bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->outer_bounds)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AppWindow> AppWindow::FromValue(const base::Value& value) {
  std::unique_ptr<AppWindow> out(new AppWindow());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AppWindow::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("focus", (this->focus).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("fullscreen", (this->fullscreen).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("isFullscreen", (this->is_fullscreen).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("minimize", (this->minimize).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("isMinimized", (this->is_minimized).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("maximize", (this->maximize).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("isMaximized", (this->is_maximized).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("restore", (this->restore).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("moveTo", (this->move_to).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("resizeTo", (this->resize_to).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("drawAttention", (this->draw_attention).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("clearAttention", (this->clear_attention).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("close", (this->close).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("show", (this->show).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("hide", (this->hide).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("setIcon", (this->set_icon).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("isAlwaysOnTop", (this->is_always_on_top).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("hasFrameColor", std::make_unique<base::Value>(this->has_frame_color));

  to_value_result->SetWithoutPathExpansion("activeFrameColor", std::make_unique<base::Value>(this->active_frame_color));

  to_value_result->SetWithoutPathExpansion("inactiveFrameColor", std::make_unique<base::Value>(this->inactive_frame_color));

  to_value_result->SetWithoutPathExpansion("setAlwaysOnTop", (this->set_always_on_top).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("alphaEnabled", (this->alpha_enabled).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("setVisibleOnAllWorkspaces", (this->set_visible_on_all_workspaces).CreateDeepCopy());

  to_value_result->SetWithoutPathExpansion("contentWindow", (this->content_window).ToValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("innerBounds", (this->inner_bounds).ToValue());

  to_value_result->SetWithoutPathExpansion("outerBounds", (this->outer_bounds).ToValue());


  return to_value_result;
}



//
// Functions
//

namespace Create {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* url_value = NULL;
  if (args.Get(0, &url_value) &&
      !url_value->is_none()) {
    {
      if (!url_value->GetAsString(&params->url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* options_value = NULL;
  if (args.Get(1, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<CreateWindowOptions> temp(new CreateWindowOptions());
        if (!CreateWindowOptions::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->options = std::move(temp);
      }
    }
  }

  return params;
}


Results::CreatedWindow::CreatedWindow()
 {}

Results::CreatedWindow::~CreatedWindow() {}
Results::CreatedWindow::CreatedWindow(CreatedWindow&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
}

Results::CreatedWindow& Results::CreatedWindow::operator=(CreatedWindow&& rhs)
{
additional_properties.Swap(&rhs.additional_properties);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::CreatedWindow::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->MergeDictionary(&additional_properties);

  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const CreatedWindow& created_window) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((created_window).ToValue());

  return create_results;
}
}  // namespace Create

}  // namespace app_window
}  // namespace api
}  // namespace extensions

