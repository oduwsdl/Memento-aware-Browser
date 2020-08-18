// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/system_display.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/system_display.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace system_display {
//
// Types
//

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
height(rhs.height){
}

Bounds& Bounds::operator=(Bounds&& rhs)
{
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
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


  return to_value_result;
}


Insets::Insets()
: left(0),
top(0),
right(0),
bottom(0) {}

Insets::~Insets() {}
Insets::Insets(Insets&& rhs)
: left(rhs.left),
top(rhs.top),
right(rhs.right),
bottom(rhs.bottom){
}

Insets& Insets::operator=(Insets&& rhs)
{
left = rhs.left;
top = rhs.top;
right = rhs.right;
bottom = rhs.bottom;
return *this;
}

// static
bool Insets::Populate(
    const base::Value& value, Insets* out) {
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

  const base::Value* right_value = NULL;
  if (!dict->GetWithoutPathExpansion("right", &right_value)) {
    return false;
  }
  {
    if (!right_value->GetAsInteger(&out->right)) {
      return false;
    }
  }

  const base::Value* bottom_value = NULL;
  if (!dict->GetWithoutPathExpansion("bottom", &bottom_value)) {
    return false;
  }
  {
    if (!bottom_value->GetAsInteger(&out->bottom)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Insets> Insets::FromValue(const base::Value& value) {
  std::unique_ptr<Insets> out(new Insets());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Insets::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("right", std::make_unique<base::Value>(this->right));

  to_value_result->SetWithoutPathExpansion("bottom", std::make_unique<base::Value>(this->bottom));


  return to_value_result;
}


Point::Point()
: x(0),
y(0) {}

Point::~Point() {}
Point::Point(Point&& rhs)
: x(rhs.x),
y(rhs.y){
}

Point& Point::operator=(Point&& rhs)
{
x = rhs.x;
y = rhs.y;
return *this;
}

// static
bool Point::Populate(
    const base::Value& value, Point* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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
std::unique_ptr<Point> Point::FromValue(const base::Value& value) {
  std::unique_ptr<Point> out(new Point());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Point::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("x", std::make_unique<base::Value>(this->x));

  to_value_result->SetWithoutPathExpansion("y", std::make_unique<base::Value>(this->y));


  return to_value_result;
}


TouchCalibrationPair::TouchCalibrationPair()
 {}

TouchCalibrationPair::~TouchCalibrationPair() {}
TouchCalibrationPair::TouchCalibrationPair(TouchCalibrationPair&& rhs)
: display_point(std::move(rhs.display_point)),
touch_point(std::move(rhs.touch_point)){
}

TouchCalibrationPair& TouchCalibrationPair::operator=(TouchCalibrationPair&& rhs)
{
display_point = std::move(rhs.display_point);
touch_point = std::move(rhs.touch_point);
return *this;
}

// static
bool TouchCalibrationPair::Populate(
    const base::Value& value, TouchCalibrationPair* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* display_point_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayPoint", &display_point_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!display_point_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Point::Populate(*dictionary, &out->display_point)) {
      return false;
    }
  }

  const base::Value* touch_point_value = NULL;
  if (!dict->GetWithoutPathExpansion("touchPoint", &touch_point_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!touch_point_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Point::Populate(*dictionary, &out->touch_point)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<TouchCalibrationPair> TouchCalibrationPair::FromValue(const base::Value& value) {
  std::unique_ptr<TouchCalibrationPair> out(new TouchCalibrationPair());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TouchCalibrationPair::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("displayPoint", (this->display_point).ToValue());

  to_value_result->SetWithoutPathExpansion("touchPoint", (this->touch_point).ToValue());


  return to_value_result;
}


TouchCalibrationPairQuad::TouchCalibrationPairQuad()
 {}

TouchCalibrationPairQuad::~TouchCalibrationPairQuad() {}
TouchCalibrationPairQuad::TouchCalibrationPairQuad(TouchCalibrationPairQuad&& rhs)
: pair1(std::move(rhs.pair1)),
pair2(std::move(rhs.pair2)),
pair3(std::move(rhs.pair3)),
pair4(std::move(rhs.pair4)){
}

TouchCalibrationPairQuad& TouchCalibrationPairQuad::operator=(TouchCalibrationPairQuad&& rhs)
{
pair1 = std::move(rhs.pair1);
pair2 = std::move(rhs.pair2);
pair3 = std::move(rhs.pair3);
pair4 = std::move(rhs.pair4);
return *this;
}

// static
bool TouchCalibrationPairQuad::Populate(
    const base::Value& value, TouchCalibrationPairQuad* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* pair1_value = NULL;
  if (!dict->GetWithoutPathExpansion("pair1", &pair1_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!pair1_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!TouchCalibrationPair::Populate(*dictionary, &out->pair1)) {
      return false;
    }
  }

  const base::Value* pair2_value = NULL;
  if (!dict->GetWithoutPathExpansion("pair2", &pair2_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!pair2_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!TouchCalibrationPair::Populate(*dictionary, &out->pair2)) {
      return false;
    }
  }

  const base::Value* pair3_value = NULL;
  if (!dict->GetWithoutPathExpansion("pair3", &pair3_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!pair3_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!TouchCalibrationPair::Populate(*dictionary, &out->pair3)) {
      return false;
    }
  }

  const base::Value* pair4_value = NULL;
  if (!dict->GetWithoutPathExpansion("pair4", &pair4_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!pair4_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!TouchCalibrationPair::Populate(*dictionary, &out->pair4)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<TouchCalibrationPairQuad> TouchCalibrationPairQuad::FromValue(const base::Value& value) {
  std::unique_ptr<TouchCalibrationPairQuad> out(new TouchCalibrationPairQuad());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TouchCalibrationPairQuad::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("pair1", (this->pair1).ToValue());

  to_value_result->SetWithoutPathExpansion("pair2", (this->pair2).ToValue());

  to_value_result->SetWithoutPathExpansion("pair3", (this->pair3).ToValue());

  to_value_result->SetWithoutPathExpansion("pair4", (this->pair4).ToValue());


  return to_value_result;
}


DisplayMode::DisplayMode()
: width(0),
height(0),
width_in_native_pixels(0),
height_in_native_pixels(0),
device_scale_factor(0.0),
refresh_rate(0.0),
is_native(false),
is_selected(false) {}

DisplayMode::~DisplayMode() {}
DisplayMode::DisplayMode(DisplayMode&& rhs)
: width(rhs.width),
height(rhs.height),
width_in_native_pixels(rhs.width_in_native_pixels),
height_in_native_pixels(rhs.height_in_native_pixels),
ui_scale(std::move(rhs.ui_scale)),
device_scale_factor(rhs.device_scale_factor),
refresh_rate(rhs.refresh_rate),
is_native(rhs.is_native),
is_selected(rhs.is_selected),
is_interlaced(std::move(rhs.is_interlaced)){
}

DisplayMode& DisplayMode::operator=(DisplayMode&& rhs)
{
width = rhs.width;
height = rhs.height;
width_in_native_pixels = rhs.width_in_native_pixels;
height_in_native_pixels = rhs.height_in_native_pixels;
ui_scale = std::move(rhs.ui_scale);
device_scale_factor = rhs.device_scale_factor;
refresh_rate = rhs.refresh_rate;
is_native = rhs.is_native;
is_selected = rhs.is_selected;
is_interlaced = std::move(rhs.is_interlaced);
return *this;
}

// static
bool DisplayMode::Populate(
    const base::Value& value, DisplayMode* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* width_in_native_pixels_value = NULL;
  if (!dict->GetWithoutPathExpansion("widthInNativePixels", &width_in_native_pixels_value)) {
    return false;
  }
  {
    if (!width_in_native_pixels_value->GetAsInteger(&out->width_in_native_pixels)) {
      return false;
    }
  }

  const base::Value* height_in_native_pixels_value = NULL;
  if (!dict->GetWithoutPathExpansion("heightInNativePixels", &height_in_native_pixels_value)) {
    return false;
  }
  {
    if (!height_in_native_pixels_value->GetAsInteger(&out->height_in_native_pixels)) {
      return false;
    }
  }

  const base::Value* ui_scale_value = NULL;
  if (dict->GetWithoutPathExpansion("uiScale", &ui_scale_value)) {
    {
      double temp;
      if (!ui_scale_value->GetAsDouble(&temp)) {
        out->ui_scale.reset();
        return false;
      }
      else
        out->ui_scale.reset(new double(temp));
    }
  }

  const base::Value* device_scale_factor_value = NULL;
  if (!dict->GetWithoutPathExpansion("deviceScaleFactor", &device_scale_factor_value)) {
    return false;
  }
  {
    if (!device_scale_factor_value->GetAsDouble(&out->device_scale_factor)) {
      return false;
    }
  }

  const base::Value* refresh_rate_value = NULL;
  if (!dict->GetWithoutPathExpansion("refreshRate", &refresh_rate_value)) {
    return false;
  }
  {
    if (!refresh_rate_value->GetAsDouble(&out->refresh_rate)) {
      return false;
    }
  }

  const base::Value* is_native_value = NULL;
  if (!dict->GetWithoutPathExpansion("isNative", &is_native_value)) {
    return false;
  }
  {
    if (!is_native_value->GetAsBoolean(&out->is_native)) {
      return false;
    }
  }

  const base::Value* is_selected_value = NULL;
  if (!dict->GetWithoutPathExpansion("isSelected", &is_selected_value)) {
    return false;
  }
  {
    if (!is_selected_value->GetAsBoolean(&out->is_selected)) {
      return false;
    }
  }

  const base::Value* is_interlaced_value = NULL;
  if (dict->GetWithoutPathExpansion("isInterlaced", &is_interlaced_value)) {
    {
      bool temp;
      if (!is_interlaced_value->GetAsBoolean(&temp)) {
        out->is_interlaced.reset();
        return false;
      }
      else
        out->is_interlaced.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DisplayMode> DisplayMode::FromValue(const base::Value& value) {
  std::unique_ptr<DisplayMode> out(new DisplayMode());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DisplayMode::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));

  to_value_result->SetWithoutPathExpansion("widthInNativePixels", std::make_unique<base::Value>(this->width_in_native_pixels));

  to_value_result->SetWithoutPathExpansion("heightInNativePixels", std::make_unique<base::Value>(this->height_in_native_pixels));

  if (this->ui_scale.get()) {
    to_value_result->SetWithoutPathExpansion("uiScale", std::make_unique<base::Value>(*this->ui_scale));

  }
  to_value_result->SetWithoutPathExpansion("deviceScaleFactor", std::make_unique<base::Value>(this->device_scale_factor));

  to_value_result->SetWithoutPathExpansion("refreshRate", std::make_unique<base::Value>(this->refresh_rate));

  to_value_result->SetWithoutPathExpansion("isNative", std::make_unique<base::Value>(this->is_native));

  to_value_result->SetWithoutPathExpansion("isSelected", std::make_unique<base::Value>(this->is_selected));

  if (this->is_interlaced.get()) {
    to_value_result->SetWithoutPathExpansion("isInterlaced", std::make_unique<base::Value>(*this->is_interlaced));

  }

  return to_value_result;
}


const char* ToString(LayoutPosition enum_param) {
  switch (enum_param) {
    case LAYOUT_POSITION_TOP:
      return "top";
    case LAYOUT_POSITION_RIGHT:
      return "right";
    case LAYOUT_POSITION_BOTTOM:
      return "bottom";
    case LAYOUT_POSITION_LEFT:
      return "left";
    case LAYOUT_POSITION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

LayoutPosition ParseLayoutPosition(const std::string& enum_string) {
  if (enum_string == "top")
    return LAYOUT_POSITION_TOP;
  if (enum_string == "right")
    return LAYOUT_POSITION_RIGHT;
  if (enum_string == "bottom")
    return LAYOUT_POSITION_BOTTOM;
  if (enum_string == "left")
    return LAYOUT_POSITION_LEFT;
  return LAYOUT_POSITION_NONE;
}


DisplayLayout::DisplayLayout()
: position(LAYOUT_POSITION_NONE),
offset(0) {}

DisplayLayout::~DisplayLayout() {}
DisplayLayout::DisplayLayout(DisplayLayout&& rhs)
: id(std::move(rhs.id)),
parent_id(std::move(rhs.parent_id)),
position(rhs.position),
offset(rhs.offset){
}

DisplayLayout& DisplayLayout::operator=(DisplayLayout&& rhs)
{
id = std::move(rhs.id);
parent_id = std::move(rhs.parent_id);
position = rhs.position;
offset = rhs.offset;
return *this;
}

// static
bool DisplayLayout::Populate(
    const base::Value& value, DisplayLayout* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* parent_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("parentId", &parent_id_value)) {
    return false;
  }
  {
    if (!parent_id_value->GetAsString(&out->parent_id)) {
      return false;
    }
  }

  const base::Value* position_value = NULL;
  if (!dict->GetWithoutPathExpansion("position", &position_value)) {
    return false;
  }
  {
    std::string layout_position_as_string;
    if (!position_value->GetAsString(&layout_position_as_string)) {
      return false;
    }
    out->position = ParseLayoutPosition(layout_position_as_string);
    if (out->position == LAYOUT_POSITION_NONE) {
      return false;
    }
  }

  const base::Value* offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("offset", &offset_value)) {
    return false;
  }
  {
    if (!offset_value->GetAsInteger(&out->offset)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<DisplayLayout> DisplayLayout::FromValue(const base::Value& value) {
  std::unique_ptr<DisplayLayout> out(new DisplayLayout());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DisplayLayout::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("parentId", std::make_unique<base::Value>(this->parent_id));

  to_value_result->SetWithoutPathExpansion("position", std::make_unique<base::Value>(system_display::ToString(this->position)));

  to_value_result->SetWithoutPathExpansion("offset", std::make_unique<base::Value>(this->offset));


  return to_value_result;
}


Edid::Edid()
: year_of_manufacture(0) {}

Edid::~Edid() {}
Edid::Edid(Edid&& rhs)
: manufacturer_id(std::move(rhs.manufacturer_id)),
product_id(std::move(rhs.product_id)),
year_of_manufacture(rhs.year_of_manufacture){
}

Edid& Edid::operator=(Edid&& rhs)
{
manufacturer_id = std::move(rhs.manufacturer_id);
product_id = std::move(rhs.product_id);
year_of_manufacture = rhs.year_of_manufacture;
return *this;
}

// static
bool Edid::Populate(
    const base::Value& value, Edid* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* manufacturer_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("manufacturerId", &manufacturer_id_value)) {
    return false;
  }
  {
    if (!manufacturer_id_value->GetAsString(&out->manufacturer_id)) {
      return false;
    }
  }

  const base::Value* product_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    return false;
  }
  {
    if (!product_id_value->GetAsString(&out->product_id)) {
      return false;
    }
  }

  const base::Value* year_of_manufacture_value = NULL;
  if (!dict->GetWithoutPathExpansion("yearOfManufacture", &year_of_manufacture_value)) {
    return false;
  }
  {
    if (!year_of_manufacture_value->GetAsInteger(&out->year_of_manufacture)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Edid> Edid::FromValue(const base::Value& value) {
  std::unique_ptr<Edid> out(new Edid());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Edid::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("manufacturerId", std::make_unique<base::Value>(this->manufacturer_id));

  to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(this->product_id));

  to_value_result->SetWithoutPathExpansion("yearOfManufacture", std::make_unique<base::Value>(this->year_of_manufacture));


  return to_value_result;
}


DisplayUnitInfo::DisplayUnitInfo()
: is_primary(false),
is_internal(false),
is_enabled(false),
is_unified(false),
dpi_x(0.0),
dpi_y(0.0),
rotation(0),
has_touch_support(false),
has_accelerometer_support(false),
display_zoom_factor(0.0) {}

DisplayUnitInfo::~DisplayUnitInfo() {}
DisplayUnitInfo::DisplayUnitInfo(DisplayUnitInfo&& rhs)
: id(std::move(rhs.id)),
name(std::move(rhs.name)),
edid(std::move(rhs.edid)),
mirroring_source_id(std::move(rhs.mirroring_source_id)),
mirroring_destination_ids(std::move(rhs.mirroring_destination_ids)),
is_primary(rhs.is_primary),
is_internal(rhs.is_internal),
is_enabled(rhs.is_enabled),
is_unified(rhs.is_unified),
is_in_tablet_physical_state(std::move(rhs.is_in_tablet_physical_state)),
dpi_x(rhs.dpi_x),
dpi_y(rhs.dpi_y),
rotation(rhs.rotation),
bounds(std::move(rhs.bounds)),
overscan(std::move(rhs.overscan)),
work_area(std::move(rhs.work_area)),
modes(std::move(rhs.modes)),
has_touch_support(rhs.has_touch_support),
has_accelerometer_support(rhs.has_accelerometer_support),
available_display_zoom_factors(std::move(rhs.available_display_zoom_factors)),
display_zoom_factor(rhs.display_zoom_factor){
}

DisplayUnitInfo& DisplayUnitInfo::operator=(DisplayUnitInfo&& rhs)
{
id = std::move(rhs.id);
name = std::move(rhs.name);
edid = std::move(rhs.edid);
mirroring_source_id = std::move(rhs.mirroring_source_id);
mirroring_destination_ids = std::move(rhs.mirroring_destination_ids);
is_primary = rhs.is_primary;
is_internal = rhs.is_internal;
is_enabled = rhs.is_enabled;
is_unified = rhs.is_unified;
is_in_tablet_physical_state = std::move(rhs.is_in_tablet_physical_state);
dpi_x = rhs.dpi_x;
dpi_y = rhs.dpi_y;
rotation = rhs.rotation;
bounds = std::move(rhs.bounds);
overscan = std::move(rhs.overscan);
work_area = std::move(rhs.work_area);
modes = std::move(rhs.modes);
has_touch_support = rhs.has_touch_support;
has_accelerometer_support = rhs.has_accelerometer_support;
available_display_zoom_factors = std::move(rhs.available_display_zoom_factors);
display_zoom_factor = rhs.display_zoom_factor;
return *this;
}

// static
bool DisplayUnitInfo::Populate(
    const base::Value& value, DisplayUnitInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* edid_value = NULL;
  if (dict->GetWithoutPathExpansion("edid", &edid_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!edid_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Edid> temp(new Edid());
        if (!Edid::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->edid = std::move(temp);
      }
    }
  }

  const base::Value* mirroring_source_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("mirroringSourceId", &mirroring_source_id_value)) {
    return false;
  }
  {
    if (!mirroring_source_id_value->GetAsString(&out->mirroring_source_id)) {
      return false;
    }
  }

  const base::Value* mirroring_destination_ids_value = NULL;
  if (!dict->GetWithoutPathExpansion("mirroringDestinationIds", &mirroring_destination_ids_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!mirroring_destination_ids_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->mirroring_destination_ids)) {
        return false;
      }
    }
  }

  const base::Value* is_primary_value = NULL;
  if (!dict->GetWithoutPathExpansion("isPrimary", &is_primary_value)) {
    return false;
  }
  {
    if (!is_primary_value->GetAsBoolean(&out->is_primary)) {
      return false;
    }
  }

  const base::Value* is_internal_value = NULL;
  if (!dict->GetWithoutPathExpansion("isInternal", &is_internal_value)) {
    return false;
  }
  {
    if (!is_internal_value->GetAsBoolean(&out->is_internal)) {
      return false;
    }
  }

  const base::Value* is_enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("isEnabled", &is_enabled_value)) {
    return false;
  }
  {
    if (!is_enabled_value->GetAsBoolean(&out->is_enabled)) {
      return false;
    }
  }

  const base::Value* is_unified_value = NULL;
  if (!dict->GetWithoutPathExpansion("isUnified", &is_unified_value)) {
    return false;
  }
  {
    if (!is_unified_value->GetAsBoolean(&out->is_unified)) {
      return false;
    }
  }

  const base::Value* is_in_tablet_physical_state_value = NULL;
  if (dict->GetWithoutPathExpansion("isInTabletPhysicalState", &is_in_tablet_physical_state_value)) {
    {
      bool temp;
      if (!is_in_tablet_physical_state_value->GetAsBoolean(&temp)) {
        out->is_in_tablet_physical_state.reset();
        return false;
      }
      else
        out->is_in_tablet_physical_state.reset(new bool(temp));
    }
  }

  const base::Value* dpi_x_value = NULL;
  if (!dict->GetWithoutPathExpansion("dpiX", &dpi_x_value)) {
    return false;
  }
  {
    if (!dpi_x_value->GetAsDouble(&out->dpi_x)) {
      return false;
    }
  }

  const base::Value* dpi_y_value = NULL;
  if (!dict->GetWithoutPathExpansion("dpiY", &dpi_y_value)) {
    return false;
  }
  {
    if (!dpi_y_value->GetAsDouble(&out->dpi_y)) {
      return false;
    }
  }

  const base::Value* rotation_value = NULL;
  if (!dict->GetWithoutPathExpansion("rotation", &rotation_value)) {
    return false;
  }
  {
    if (!rotation_value->GetAsInteger(&out->rotation)) {
      return false;
    }
  }

  const base::Value* bounds_value = NULL;
  if (!dict->GetWithoutPathExpansion("bounds", &bounds_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!bounds_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->bounds)) {
      return false;
    }
  }

  const base::Value* overscan_value = NULL;
  if (!dict->GetWithoutPathExpansion("overscan", &overscan_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!overscan_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Insets::Populate(*dictionary, &out->overscan)) {
      return false;
    }
  }

  const base::Value* work_area_value = NULL;
  if (!dict->GetWithoutPathExpansion("workArea", &work_area_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!work_area_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!Bounds::Populate(*dictionary, &out->work_area)) {
      return false;
    }
  }

  const base::Value* modes_value = NULL;
  if (!dict->GetWithoutPathExpansion("modes", &modes_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!modes_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->modes)) {
        return false;
      }
    }
  }

  const base::Value* has_touch_support_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasTouchSupport", &has_touch_support_value)) {
    return false;
  }
  {
    if (!has_touch_support_value->GetAsBoolean(&out->has_touch_support)) {
      return false;
    }
  }

  const base::Value* has_accelerometer_support_value = NULL;
  if (!dict->GetWithoutPathExpansion("hasAccelerometerSupport", &has_accelerometer_support_value)) {
    return false;
  }
  {
    if (!has_accelerometer_support_value->GetAsBoolean(&out->has_accelerometer_support)) {
      return false;
    }
  }

  const base::Value* available_display_zoom_factors_value = NULL;
  if (!dict->GetWithoutPathExpansion("availableDisplayZoomFactors", &available_display_zoom_factors_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!available_display_zoom_factors_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->available_display_zoom_factors)) {
        return false;
      }
    }
  }

  const base::Value* display_zoom_factor_value = NULL;
  if (!dict->GetWithoutPathExpansion("displayZoomFactor", &display_zoom_factor_value)) {
    return false;
  }
  {
    if (!display_zoom_factor_value->GetAsDouble(&out->display_zoom_factor)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<DisplayUnitInfo> DisplayUnitInfo::FromValue(const base::Value& value) {
  std::unique_ptr<DisplayUnitInfo> out(new DisplayUnitInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DisplayUnitInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  if (this->edid.get()) {
    to_value_result->SetWithoutPathExpansion("edid", (this->edid)->ToValue());

  }
  to_value_result->SetWithoutPathExpansion("mirroringSourceId", std::make_unique<base::Value>(this->mirroring_source_id));

  to_value_result->SetWithoutPathExpansion("mirroringDestinationIds", json_schema_compiler::util::CreateValueFromArray(this->mirroring_destination_ids));

  to_value_result->SetWithoutPathExpansion("isPrimary", std::make_unique<base::Value>(this->is_primary));

  to_value_result->SetWithoutPathExpansion("isInternal", std::make_unique<base::Value>(this->is_internal));

  to_value_result->SetWithoutPathExpansion("isEnabled", std::make_unique<base::Value>(this->is_enabled));

  to_value_result->SetWithoutPathExpansion("isUnified", std::make_unique<base::Value>(this->is_unified));

  if (this->is_in_tablet_physical_state.get()) {
    to_value_result->SetWithoutPathExpansion("isInTabletPhysicalState", std::make_unique<base::Value>(*this->is_in_tablet_physical_state));

  }
  to_value_result->SetWithoutPathExpansion("dpiX", std::make_unique<base::Value>(this->dpi_x));

  to_value_result->SetWithoutPathExpansion("dpiY", std::make_unique<base::Value>(this->dpi_y));

  to_value_result->SetWithoutPathExpansion("rotation", std::make_unique<base::Value>(this->rotation));

  to_value_result->SetWithoutPathExpansion("bounds", (this->bounds).ToValue());

  to_value_result->SetWithoutPathExpansion("overscan", (this->overscan).ToValue());

  to_value_result->SetWithoutPathExpansion("workArea", (this->work_area).ToValue());

  to_value_result->SetWithoutPathExpansion("modes", json_schema_compiler::util::CreateValueFromArray(this->modes));

  to_value_result->SetWithoutPathExpansion("hasTouchSupport", std::make_unique<base::Value>(this->has_touch_support));

  to_value_result->SetWithoutPathExpansion("hasAccelerometerSupport", std::make_unique<base::Value>(this->has_accelerometer_support));

  to_value_result->SetWithoutPathExpansion("availableDisplayZoomFactors", json_schema_compiler::util::CreateValueFromArray(this->available_display_zoom_factors));

  to_value_result->SetWithoutPathExpansion("displayZoomFactor", std::make_unique<base::Value>(this->display_zoom_factor));


  return to_value_result;
}


DisplayProperties::DisplayProperties()
 {}

DisplayProperties::~DisplayProperties() {}
DisplayProperties::DisplayProperties(DisplayProperties&& rhs)
: is_unified(std::move(rhs.is_unified)),
mirroring_source_id(std::move(rhs.mirroring_source_id)),
is_primary(std::move(rhs.is_primary)),
overscan(std::move(rhs.overscan)),
rotation(std::move(rhs.rotation)),
bounds_origin_x(std::move(rhs.bounds_origin_x)),
bounds_origin_y(std::move(rhs.bounds_origin_y)),
display_mode(std::move(rhs.display_mode)),
display_zoom_factor(std::move(rhs.display_zoom_factor)){
}

DisplayProperties& DisplayProperties::operator=(DisplayProperties&& rhs)
{
is_unified = std::move(rhs.is_unified);
mirroring_source_id = std::move(rhs.mirroring_source_id);
is_primary = std::move(rhs.is_primary);
overscan = std::move(rhs.overscan);
rotation = std::move(rhs.rotation);
bounds_origin_x = std::move(rhs.bounds_origin_x);
bounds_origin_y = std::move(rhs.bounds_origin_y);
display_mode = std::move(rhs.display_mode);
display_zoom_factor = std::move(rhs.display_zoom_factor);
return *this;
}

// static
bool DisplayProperties::Populate(
    const base::Value& value, DisplayProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* is_unified_value = NULL;
  if (dict->GetWithoutPathExpansion("isUnified", &is_unified_value)) {
    {
      bool temp;
      if (!is_unified_value->GetAsBoolean(&temp)) {
        out->is_unified.reset();
        return false;
      }
      else
        out->is_unified.reset(new bool(temp));
    }
  }

  const base::Value* mirroring_source_id_value = NULL;
  if (dict->GetWithoutPathExpansion("mirroringSourceId", &mirroring_source_id_value)) {
    {
      std::string temp;
      if (!mirroring_source_id_value->GetAsString(&temp)) {
        out->mirroring_source_id.reset();
        return false;
      }
      else
        out->mirroring_source_id.reset(new std::string(temp));
    }
  }

  const base::Value* is_primary_value = NULL;
  if (dict->GetWithoutPathExpansion("isPrimary", &is_primary_value)) {
    {
      bool temp;
      if (!is_primary_value->GetAsBoolean(&temp)) {
        out->is_primary.reset();
        return false;
      }
      else
        out->is_primary.reset(new bool(temp));
    }
  }

  const base::Value* overscan_value = NULL;
  if (dict->GetWithoutPathExpansion("overscan", &overscan_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!overscan_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<Insets> temp(new Insets());
        if (!Insets::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->overscan = std::move(temp);
      }
    }
  }

  const base::Value* rotation_value = NULL;
  if (dict->GetWithoutPathExpansion("rotation", &rotation_value)) {
    {
      int temp;
      if (!rotation_value->GetAsInteger(&temp)) {
        out->rotation.reset();
        return false;
      }
      else
        out->rotation.reset(new int(temp));
    }
  }

  const base::Value* bounds_origin_x_value = NULL;
  if (dict->GetWithoutPathExpansion("boundsOriginX", &bounds_origin_x_value)) {
    {
      int temp;
      if (!bounds_origin_x_value->GetAsInteger(&temp)) {
        out->bounds_origin_x.reset();
        return false;
      }
      else
        out->bounds_origin_x.reset(new int(temp));
    }
  }

  const base::Value* bounds_origin_y_value = NULL;
  if (dict->GetWithoutPathExpansion("boundsOriginY", &bounds_origin_y_value)) {
    {
      int temp;
      if (!bounds_origin_y_value->GetAsInteger(&temp)) {
        out->bounds_origin_y.reset();
        return false;
      }
      else
        out->bounds_origin_y.reset(new int(temp));
    }
  }

  const base::Value* display_mode_value = NULL;
  if (dict->GetWithoutPathExpansion("displayMode", &display_mode_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!display_mode_value->GetAsDictionary(&dictionary)) {
        return false;
      }
      else {
        std::unique_ptr<DisplayMode> temp(new DisplayMode());
        if (!DisplayMode::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->display_mode = std::move(temp);
      }
    }
  }

  const base::Value* display_zoom_factor_value = NULL;
  if (dict->GetWithoutPathExpansion("displayZoomFactor", &display_zoom_factor_value)) {
    {
      double temp;
      if (!display_zoom_factor_value->GetAsDouble(&temp)) {
        out->display_zoom_factor.reset();
        return false;
      }
      else
        out->display_zoom_factor.reset(new double(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<DisplayProperties> DisplayProperties::FromValue(const base::Value& value) {
  std::unique_ptr<DisplayProperties> out(new DisplayProperties());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DisplayProperties::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->is_unified.get()) {
    to_value_result->SetWithoutPathExpansion("isUnified", std::make_unique<base::Value>(*this->is_unified));

  }
  if (this->mirroring_source_id.get()) {
    to_value_result->SetWithoutPathExpansion("mirroringSourceId", std::make_unique<base::Value>(*this->mirroring_source_id));

  }
  if (this->is_primary.get()) {
    to_value_result->SetWithoutPathExpansion("isPrimary", std::make_unique<base::Value>(*this->is_primary));

  }
  if (this->overscan.get()) {
    to_value_result->SetWithoutPathExpansion("overscan", (this->overscan)->ToValue());

  }
  if (this->rotation.get()) {
    to_value_result->SetWithoutPathExpansion("rotation", std::make_unique<base::Value>(*this->rotation));

  }
  if (this->bounds_origin_x.get()) {
    to_value_result->SetWithoutPathExpansion("boundsOriginX", std::make_unique<base::Value>(*this->bounds_origin_x));

  }
  if (this->bounds_origin_y.get()) {
    to_value_result->SetWithoutPathExpansion("boundsOriginY", std::make_unique<base::Value>(*this->bounds_origin_y));

  }
  if (this->display_mode.get()) {
    to_value_result->SetWithoutPathExpansion("displayMode", (this->display_mode)->ToValue());

  }
  if (this->display_zoom_factor.get()) {
    to_value_result->SetWithoutPathExpansion("displayZoomFactor", std::make_unique<base::Value>(*this->display_zoom_factor));

  }

  return to_value_result;
}


GetInfoFlags::GetInfoFlags()
 {}

GetInfoFlags::~GetInfoFlags() {}
GetInfoFlags::GetInfoFlags(GetInfoFlags&& rhs)
: single_unified(std::move(rhs.single_unified)){
}

GetInfoFlags& GetInfoFlags::operator=(GetInfoFlags&& rhs)
{
single_unified = std::move(rhs.single_unified);
return *this;
}

// static
bool GetInfoFlags::Populate(
    const base::Value& value, GetInfoFlags* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* single_unified_value = NULL;
  if (dict->GetWithoutPathExpansion("singleUnified", &single_unified_value)) {
    {
      bool temp;
      if (!single_unified_value->GetAsBoolean(&temp)) {
        out->single_unified.reset();
        return false;
      }
      else
        out->single_unified.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<GetInfoFlags> GetInfoFlags::FromValue(const base::Value& value) {
  std::unique_ptr<GetInfoFlags> out(new GetInfoFlags());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> GetInfoFlags::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->single_unified.get()) {
    to_value_result->SetWithoutPathExpansion("singleUnified", std::make_unique<base::Value>(*this->single_unified));

  }

  return to_value_result;
}


const char* ToString(MirrorMode enum_param) {
  switch (enum_param) {
    case MIRROR_MODE_OFF:
      return "off";
    case MIRROR_MODE_NORMAL:
      return "normal";
    case MIRROR_MODE_MIXED:
      return "mixed";
    case MIRROR_MODE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MirrorMode ParseMirrorMode(const std::string& enum_string) {
  if (enum_string == "off")
    return MIRROR_MODE_OFF;
  if (enum_string == "normal")
    return MIRROR_MODE_NORMAL;
  if (enum_string == "mixed")
    return MIRROR_MODE_MIXED;
  return MIRROR_MODE_NONE;
}


MirrorModeInfo::MirrorModeInfo()
: mode(MIRROR_MODE_NONE) {}

MirrorModeInfo::~MirrorModeInfo() {}
MirrorModeInfo::MirrorModeInfo(MirrorModeInfo&& rhs)
: mode(rhs.mode),
mirroring_source_id(std::move(rhs.mirroring_source_id)),
mirroring_destination_ids(std::move(rhs.mirroring_destination_ids)){
}

MirrorModeInfo& MirrorModeInfo::operator=(MirrorModeInfo&& rhs)
{
mode = rhs.mode;
mirroring_source_id = std::move(rhs.mirroring_source_id);
mirroring_destination_ids = std::move(rhs.mirroring_destination_ids);
return *this;
}

// static
bool MirrorModeInfo::Populate(
    const base::Value& value, MirrorModeInfo* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* mode_value = NULL;
  if (!dict->GetWithoutPathExpansion("mode", &mode_value)) {
    return false;
  }
  {
    std::string mirror_mode_as_string;
    if (!mode_value->GetAsString(&mirror_mode_as_string)) {
      return false;
    }
    out->mode = ParseMirrorMode(mirror_mode_as_string);
    if (out->mode == MIRROR_MODE_NONE) {
      return false;
    }
  }

  const base::Value* mirroring_source_id_value = NULL;
  if (dict->GetWithoutPathExpansion("mirroringSourceId", &mirroring_source_id_value)) {
    {
      std::string temp;
      if (!mirroring_source_id_value->GetAsString(&temp)) {
        out->mirroring_source_id.reset();
        return false;
      }
      else
        out->mirroring_source_id.reset(new std::string(temp));
    }
  }

  const base::Value* mirroring_destination_ids_value = NULL;
  if (dict->GetWithoutPathExpansion("mirroringDestinationIds", &mirroring_destination_ids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!mirroring_destination_ids_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->mirroring_destination_ids)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<MirrorModeInfo> MirrorModeInfo::FromValue(const base::Value& value) {
  std::unique_ptr<MirrorModeInfo> out(new MirrorModeInfo());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MirrorModeInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("mode", std::make_unique<base::Value>(system_display::ToString(this->mode)));

  if (this->mirroring_source_id.get()) {
    to_value_result->SetWithoutPathExpansion("mirroringSourceId", std::make_unique<base::Value>(*this->mirroring_source_id));

  }
  if (this->mirroring_destination_ids.get()) {
    to_value_result->SetWithoutPathExpansion("mirroringDestinationIds", json_schema_compiler::util::CreateValueFromOptionalArray(this->mirroring_destination_ids));

  }

  return to_value_result;
}



//
// Functions
//

namespace GetInfo {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* flags_value = NULL;
  if (args.Get(0, &flags_value) &&
      !flags_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!flags_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      else {
        std::unique_ptr<GetInfoFlags> temp(new GetInfoFlags());
        if (!GetInfoFlags::Populate(*dictionary, temp.get())) {
          return std::unique_ptr<Params>();
        }
        else
          params->flags = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<DisplayUnitInfo>& display_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(display_info));

  return create_results;
}
}  // namespace GetInfo

namespace GetDisplayLayout {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<DisplayLayout>& layouts) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(layouts));

  return create_results;
}
}  // namespace GetDisplayLayout

namespace SetDisplayProperties {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* info_value = NULL;
  if (args.Get(1, &info_value) &&
      !info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DisplayProperties::Populate(*dictionary, &params->info)) {
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
}  // namespace SetDisplayProperties

namespace SetDisplayLayout {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* layouts_value = NULL;
  if (args.Get(0, &layouts_value) &&
      !layouts_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!layouts_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->layouts)) {
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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace SetDisplayLayout

namespace EnableUnifiedDesktop {

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


}  // namespace EnableUnifiedDesktop

namespace OverscanCalibrationStart {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OverscanCalibrationStart

namespace OverscanCalibrationAdjust {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* delta_value = NULL;
  if (args.Get(1, &delta_value) &&
      !delta_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!delta_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Insets::Populate(*dictionary, &params->delta)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OverscanCalibrationAdjust

namespace OverscanCalibrationReset {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OverscanCalibrationReset

namespace OverscanCalibrationComplete {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OverscanCalibrationComplete

namespace ShowNativeTouchCalibration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool success) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(success));

  return create_results;
}
}  // namespace ShowNativeTouchCalibration

namespace StartCustomTouchCalibration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace StartCustomTouchCalibration

namespace CompleteCustomTouchCalibration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* pairs_value = NULL;
  if (args.Get(0, &pairs_value) &&
      !pairs_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!pairs_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!TouchCalibrationPairQuad::Populate(*dictionary, &params->pairs)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* bounds_value = NULL;
  if (args.Get(1, &bounds_value) &&
      !bounds_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!bounds_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Bounds::Populate(*dictionary, &params->bounds)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace CompleteCustomTouchCalibration

namespace ClearTouchCalibration {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace ClearTouchCalibration

namespace SetMirrorMode {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* info_value = NULL;
  if (args.Get(0, &info_value) &&
      !info_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!info_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!MirrorModeInfo::Populate(*dictionary, &params->info)) {
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
}  // namespace SetMirrorMode

//
// Events
//

namespace OnDisplayChanged {

const char kEventName[] = "system.display.onDisplayChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnDisplayChanged

}  // namespace system_display
}  // namespace api
}  // namespace extensions

