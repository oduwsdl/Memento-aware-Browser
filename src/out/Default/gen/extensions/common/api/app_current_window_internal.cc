// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/app_current_window_internal.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/app_current_window_internal.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace app_current_window_internal {
//
// Types
//

Bounds::Bounds()
 {}

Bounds::~Bounds() {}
Bounds::Bounds(Bounds&& rhs)
: left(std::move(rhs.left)),
top(std::move(rhs.top)),
width(std::move(rhs.width)),
height(std::move(rhs.height)){
}

Bounds& Bounds::operator=(Bounds&& rhs)
{
left = std::move(rhs.left);
top = std::move(rhs.top);
width = std::move(rhs.width);
height = std::move(rhs.height);
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
std::unique_ptr<Bounds> Bounds::FromValue(const base::Value& value) {
  std::unique_ptr<Bounds> out(new Bounds());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Bounds::ToValue() const {
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


SizeConstraints::SizeConstraints()
 {}

SizeConstraints::~SizeConstraints() {}
SizeConstraints::SizeConstraints(SizeConstraints&& rhs)
: min_width(std::move(rhs.min_width)),
min_height(std::move(rhs.min_height)),
max_width(std::move(rhs.max_width)),
max_height(std::move(rhs.max_height)){
}

SizeConstraints& SizeConstraints::operator=(SizeConstraints&& rhs)
{
min_width = std::move(rhs.min_width);
min_height = std::move(rhs.min_height);
max_width = std::move(rhs.max_width);
max_height = std::move(rhs.max_height);
return *this;
}

// static
bool SizeConstraints::Populate(
    const base::Value& value, SizeConstraints* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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
std::unique_ptr<SizeConstraints> SizeConstraints::FromValue(const base::Value& value) {
  std::unique_ptr<SizeConstraints> out(new SizeConstraints());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SizeConstraints::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

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


RegionRect::RegionRect()
: left(0),
top(0),
width(0),
height(0) {}

RegionRect::~RegionRect() {}
RegionRect::RegionRect(RegionRect&& rhs)
: left(rhs.left),
top(rhs.top),
width(rhs.width),
height(rhs.height){
}

RegionRect& RegionRect::operator=(RegionRect&& rhs)
{
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
return *this;
}

// static
bool RegionRect::Populate(
    const base::Value& value, RegionRect* out) {
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
std::unique_ptr<RegionRect> RegionRect::FromValue(const base::Value& value) {
  std::unique_ptr<RegionRect> out(new RegionRect());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RegionRect::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));


  return to_value_result;
}


Region::Region()
 {}

Region::~Region() {}
Region::Region(Region&& rhs)
: rects(std::move(rhs.rects)){
}

Region& Region::operator=(Region&& rhs)
{
rects = std::move(rhs.rects);
return *this;
}

// static
bool Region::Populate(
    const base::Value& value, Region* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* rects_value = NULL;
  if (dict->GetWithoutPathExpansion("rects", &rects_value)) {
    {
      const base::ListValue* list = NULL;
      if (!rects_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->rects)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<Region> Region::FromValue(const base::Value& value) {
  std::unique_ptr<Region> out(new Region());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Region::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->rects.get()) {
    to_value_result->SetWithoutPathExpansion("rects", json_schema_compiler::util::CreateValueFromOptionalArray(this->rects));

  }

  return to_value_result;
}



//
// Functions
//

namespace Focus {

}  // namespace Focus

namespace Fullscreen {

}  // namespace Fullscreen

namespace Minimize {

}  // namespace Minimize

namespace Maximize {

}  // namespace Maximize

namespace Restore {

}  // namespace Restore

namespace DrawAttention {

}  // namespace DrawAttention

namespace ClearAttention {

}  // namespace ClearAttention

namespace Show {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() > 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* focused_value = NULL;
  if (args.Get(0, &focused_value) &&
      !focused_value->is_none()) {
    {
      bool temp;
      if (!focused_value->GetAsBoolean(&temp)) {
        params->focused.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->focused.reset(new bool(temp));
    }
  }

  return params;
}


}  // namespace Show

namespace Hide {

}  // namespace Hide

namespace SetBounds {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* bounds_type_value = NULL;
  if (args.Get(0, &bounds_type_value) &&
      !bounds_type_value->is_none()) {
    {
      if (!bounds_type_value->GetAsString(&params->bounds_type)) {
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


}  // namespace SetBounds

namespace SetSizeConstraints {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* bounds_type_value = NULL;
  if (args.Get(0, &bounds_type_value) &&
      !bounds_type_value->is_none()) {
    {
      if (!bounds_type_value->GetAsString(&params->bounds_type)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* constraints_value = NULL;
  if (args.Get(1, &constraints_value) &&
      !constraints_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!constraints_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!SizeConstraints::Populate(*dictionary, &params->constraints)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetSizeConstraints

namespace SetIcon {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* icon_url_value = NULL;
  if (args.Get(0, &icon_url_value) &&
      !icon_url_value->is_none()) {
    {
      if (!icon_url_value->GetAsString(&params->icon_url)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetIcon

namespace SetShape {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* region_value = NULL;
  if (args.Get(0, &region_value) &&
      !region_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!region_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Region::Populate(*dictionary, &params->region)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetShape

namespace SetAlwaysOnTop {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* always_on_top_value = NULL;
  if (args.Get(0, &always_on_top_value) &&
      !always_on_top_value->is_none()) {
    {
      if (!always_on_top_value->GetAsBoolean(&params->always_on_top)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetAlwaysOnTop

namespace SetVisibleOnAllWorkspaces {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* always_visible_value = NULL;
  if (args.Get(0, &always_visible_value) &&
      !always_visible_value->is_none()) {
    {
      if (!always_visible_value->GetAsBoolean(&params->always_visible)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetVisibleOnAllWorkspaces

namespace SetActivateOnPointer {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* activate_on_pointer_value = NULL;
  if (args.Get(0, &activate_on_pointer_value) &&
      !activate_on_pointer_value->is_none()) {
    {
      if (!activate_on_pointer_value->GetAsBoolean(&params->activate_on_pointer)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetActivateOnPointer

//
// Events
//

namespace OnClosed {

const char kEventName[] = "app.currentWindowInternal.onClosed";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnClosed

namespace OnBoundsChanged {

const char kEventName[] = "app.currentWindowInternal.onBoundsChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnBoundsChanged

namespace OnFullscreened {

const char kEventName[] = "app.currentWindowInternal.onFullscreened";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnFullscreened

namespace OnMinimized {

const char kEventName[] = "app.currentWindowInternal.onMinimized";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnMinimized

namespace OnMaximized {

const char kEventName[] = "app.currentWindowInternal.onMaximized";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnMaximized

namespace OnRestored {

const char kEventName[] = "app.currentWindowInternal.onRestored";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnRestored

namespace OnAlphaEnabledChanged {

const char kEventName[] = "app.currentWindowInternal.onAlphaEnabledChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnAlphaEnabledChanged

}  // namespace app_current_window_internal
}  // namespace api
}  // namespace extensions

