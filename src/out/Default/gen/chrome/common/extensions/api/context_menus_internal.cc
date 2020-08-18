// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/context_menus_internal.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/context_menus_internal.h"
#include <set>
#include <utility>
#include "chrome/common/extensions/api/tabs.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace context_menus_internal {
//
// Types
//

OnClickData::MenuItemId::MenuItemId()
 {}

OnClickData::MenuItemId::~MenuItemId() {}
OnClickData::MenuItemId::MenuItemId(MenuItemId&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_string(std::move(rhs.as_string)){
}

OnClickData::MenuItemId& OnClickData::MenuItemId::operator=(MenuItemId&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_string = std::move(rhs.as_string);
return *this;
}

// static
bool OnClickData::MenuItemId::Populate(
    const base::Value& value, MenuItemId* out) {
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
    }
    return true;
  }
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
  return false;
}

std::unique_ptr<base::Value> OnClickData::MenuItemId::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_integer) {
    DCHECK(!result) << "Cannot set multiple choices for menu_item_id";
    result = std::make_unique<base::Value>(*as_integer);

  }
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for menu_item_id";
    result = std::make_unique<base::Value>(*as_string);

  }
  DCHECK(result) << "Must set at least one choice for menu_item_id";
  return result;
}


OnClickData::ParentMenuItemId::ParentMenuItemId()
 {}

OnClickData::ParentMenuItemId::~ParentMenuItemId() {}
OnClickData::ParentMenuItemId::ParentMenuItemId(ParentMenuItemId&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_string(std::move(rhs.as_string)){
}

OnClickData::ParentMenuItemId& OnClickData::ParentMenuItemId::operator=(ParentMenuItemId&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_string = std::move(rhs.as_string);
return *this;
}

// static
bool OnClickData::ParentMenuItemId::Populate(
    const base::Value& value, ParentMenuItemId* out) {
  if (value.type() == base::Value::Type::INTEGER) {
    {
      int temp;
      if (!(&value)->GetAsInteger(&temp)) {
        out->as_integer.reset();
        return false;
      }
      else
        out->as_integer.reset(new int(temp));
    }
    return true;
  }
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
  return false;
}

std::unique_ptr<base::Value> OnClickData::ParentMenuItemId::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_integer) {
    DCHECK(!result) << "Cannot set multiple choices for parent_menu_item_id";
    result = std::make_unique<base::Value>(*as_integer);

  }
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for parent_menu_item_id";
    result = std::make_unique<base::Value>(*as_string);

  }
  DCHECK(result) << "Must set at least one choice for parent_menu_item_id";
  return result;
}



OnClickData::OnClickData()
: editable(false) {}

OnClickData::~OnClickData() {}
OnClickData::OnClickData(OnClickData&& rhs)
: menu_item_id(std::move(rhs.menu_item_id)),
parent_menu_item_id(std::move(rhs.parent_menu_item_id)),
media_type(std::move(rhs.media_type)),
link_url(std::move(rhs.link_url)),
src_url(std::move(rhs.src_url)),
page_url(std::move(rhs.page_url)),
frame_url(std::move(rhs.frame_url)),
frame_id(std::move(rhs.frame_id)),
selection_text(std::move(rhs.selection_text)),
editable(rhs.editable),
was_checked(std::move(rhs.was_checked)),
checked(std::move(rhs.checked)){
}

OnClickData& OnClickData::operator=(OnClickData&& rhs)
{
menu_item_id = std::move(rhs.menu_item_id);
parent_menu_item_id = std::move(rhs.parent_menu_item_id);
media_type = std::move(rhs.media_type);
link_url = std::move(rhs.link_url);
src_url = std::move(rhs.src_url);
page_url = std::move(rhs.page_url);
frame_url = std::move(rhs.frame_url);
frame_id = std::move(rhs.frame_id);
selection_text = std::move(rhs.selection_text);
editable = rhs.editable;
was_checked = std::move(rhs.was_checked);
checked = std::move(rhs.checked);
return *this;
}

// static
bool OnClickData::Populate(
    const base::Value& value, OnClickData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* menu_item_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("menuItemId", &menu_item_id_value)) {
    return false;
  }
  {
    if (!MenuItemId::Populate(*menu_item_id_value, &out->menu_item_id))
      return false;
  }

  const base::Value* parent_menu_item_id_value = NULL;
  if (dict->GetWithoutPathExpansion("parentMenuItemId", &parent_menu_item_id_value)) {
    {
      std::unique_ptr<ParentMenuItemId> temp(new ParentMenuItemId());
      if (!ParentMenuItemId::Populate(*parent_menu_item_id_value, temp.get()))
        return false;
      out->parent_menu_item_id = std::move(temp);
    }
  }

  const base::Value* media_type_value = NULL;
  if (dict->GetWithoutPathExpansion("mediaType", &media_type_value)) {
    {
      std::string temp;
      if (!media_type_value->GetAsString(&temp)) {
        out->media_type.reset();
        return false;
      }
      else
        out->media_type.reset(new std::string(temp));
    }
  }

  const base::Value* link_url_value = NULL;
  if (dict->GetWithoutPathExpansion("linkUrl", &link_url_value)) {
    {
      std::string temp;
      if (!link_url_value->GetAsString(&temp)) {
        out->link_url.reset();
        return false;
      }
      else
        out->link_url.reset(new std::string(temp));
    }
  }

  const base::Value* src_url_value = NULL;
  if (dict->GetWithoutPathExpansion("srcUrl", &src_url_value)) {
    {
      std::string temp;
      if (!src_url_value->GetAsString(&temp)) {
        out->src_url.reset();
        return false;
      }
      else
        out->src_url.reset(new std::string(temp));
    }
  }

  const base::Value* page_url_value = NULL;
  if (dict->GetWithoutPathExpansion("pageUrl", &page_url_value)) {
    {
      std::string temp;
      if (!page_url_value->GetAsString(&temp)) {
        out->page_url.reset();
        return false;
      }
      else
        out->page_url.reset(new std::string(temp));
    }
  }

  const base::Value* frame_url_value = NULL;
  if (dict->GetWithoutPathExpansion("frameUrl", &frame_url_value)) {
    {
      std::string temp;
      if (!frame_url_value->GetAsString(&temp)) {
        out->frame_url.reset();
        return false;
      }
      else
        out->frame_url.reset(new std::string(temp));
    }
  }

  const base::Value* frame_id_value = NULL;
  if (dict->GetWithoutPathExpansion("frameId", &frame_id_value)) {
    {
      int temp;
      if (!frame_id_value->GetAsInteger(&temp)) {
        out->frame_id.reset();
        return false;
      }
      else
        out->frame_id.reset(new int(temp));
    }
  }

  const base::Value* selection_text_value = NULL;
  if (dict->GetWithoutPathExpansion("selectionText", &selection_text_value)) {
    {
      std::string temp;
      if (!selection_text_value->GetAsString(&temp)) {
        out->selection_text.reset();
        return false;
      }
      else
        out->selection_text.reset(new std::string(temp));
    }
  }

  const base::Value* editable_value = NULL;
  if (!dict->GetWithoutPathExpansion("editable", &editable_value)) {
    return false;
  }
  {
    if (!editable_value->GetAsBoolean(&out->editable)) {
      return false;
    }
  }

  const base::Value* was_checked_value = NULL;
  if (dict->GetWithoutPathExpansion("wasChecked", &was_checked_value)) {
    {
      bool temp;
      if (!was_checked_value->GetAsBoolean(&temp)) {
        out->was_checked.reset();
        return false;
      }
      else
        out->was_checked.reset(new bool(temp));
    }
  }

  const base::Value* checked_value = NULL;
  if (dict->GetWithoutPathExpansion("checked", &checked_value)) {
    {
      bool temp;
      if (!checked_value->GetAsBoolean(&temp)) {
        out->checked.reset();
        return false;
      }
      else
        out->checked.reset(new bool(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<OnClickData> OnClickData::FromValue(const base::Value& value) {
  std::unique_ptr<OnClickData> out(new OnClickData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OnClickData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("menuItemId", (this->menu_item_id).ToValue());

  if (this->parent_menu_item_id.get()) {
    to_value_result->SetWithoutPathExpansion("parentMenuItemId", (this->parent_menu_item_id)->ToValue());

  }
  if (this->media_type.get()) {
    to_value_result->SetWithoutPathExpansion("mediaType", std::make_unique<base::Value>(*this->media_type));

  }
  if (this->link_url.get()) {
    to_value_result->SetWithoutPathExpansion("linkUrl", std::make_unique<base::Value>(*this->link_url));

  }
  if (this->src_url.get()) {
    to_value_result->SetWithoutPathExpansion("srcUrl", std::make_unique<base::Value>(*this->src_url));

  }
  if (this->page_url.get()) {
    to_value_result->SetWithoutPathExpansion("pageUrl", std::make_unique<base::Value>(*this->page_url));

  }
  if (this->frame_url.get()) {
    to_value_result->SetWithoutPathExpansion("frameUrl", std::make_unique<base::Value>(*this->frame_url));

  }
  if (this->frame_id.get()) {
    to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(*this->frame_id));

  }
  if (this->selection_text.get()) {
    to_value_result->SetWithoutPathExpansion("selectionText", std::make_unique<base::Value>(*this->selection_text));

  }
  to_value_result->SetWithoutPathExpansion("editable", std::make_unique<base::Value>(this->editable));

  if (this->was_checked.get()) {
    to_value_result->SetWithoutPathExpansion("wasChecked", std::make_unique<base::Value>(*this->was_checked));

  }
  if (this->checked.get()) {
    to_value_result->SetWithoutPathExpansion("checked", std::make_unique<base::Value>(*this->checked));

  }

  return to_value_result;
}



//
// Events
//

namespace OnClicked {

const char kEventName[] = "contextMenusInternal.onClicked";

std::unique_ptr<base::ListValue> Create(const OnClickData& info, const extensions::api::tabs::Tab& tab) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  create_results->Append((tab).ToValue());

  return create_results;
}

}  // namespace OnClicked

}  // namespace context_menus_internal
}  // namespace api
}  // namespace extensions

