// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/context_menus.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/context_menus.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace context_menus {
//
// Properties
//

const int ACTION_MENU_TOP_LEVEL_LIMIT = 6;

//
// Types
//

const char* ToString(ContextType enum_param) {
  switch (enum_param) {
    case CONTEXT_TYPE_ALL:
      return "all";
    case CONTEXT_TYPE_PAGE:
      return "page";
    case CONTEXT_TYPE_FRAME:
      return "frame";
    case CONTEXT_TYPE_SELECTION:
      return "selection";
    case CONTEXT_TYPE_LINK:
      return "link";
    case CONTEXT_TYPE_EDITABLE:
      return "editable";
    case CONTEXT_TYPE_IMAGE:
      return "image";
    case CONTEXT_TYPE_VIDEO:
      return "video";
    case CONTEXT_TYPE_AUDIO:
      return "audio";
    case CONTEXT_TYPE_LAUNCHER:
      return "launcher";
    case CONTEXT_TYPE_BROWSER_ACTION:
      return "browser_action";
    case CONTEXT_TYPE_PAGE_ACTION:
      return "page_action";
    case CONTEXT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ContextType ParseContextType(const std::string& enum_string) {
  if (enum_string == "all")
    return CONTEXT_TYPE_ALL;
  if (enum_string == "page")
    return CONTEXT_TYPE_PAGE;
  if (enum_string == "frame")
    return CONTEXT_TYPE_FRAME;
  if (enum_string == "selection")
    return CONTEXT_TYPE_SELECTION;
  if (enum_string == "link")
    return CONTEXT_TYPE_LINK;
  if (enum_string == "editable")
    return CONTEXT_TYPE_EDITABLE;
  if (enum_string == "image")
    return CONTEXT_TYPE_IMAGE;
  if (enum_string == "video")
    return CONTEXT_TYPE_VIDEO;
  if (enum_string == "audio")
    return CONTEXT_TYPE_AUDIO;
  if (enum_string == "launcher")
    return CONTEXT_TYPE_LAUNCHER;
  if (enum_string == "browser_action")
    return CONTEXT_TYPE_BROWSER_ACTION;
  if (enum_string == "page_action")
    return CONTEXT_TYPE_PAGE_ACTION;
  return CONTEXT_TYPE_NONE;
}


const char* ToString(ItemType enum_param) {
  switch (enum_param) {
    case ITEM_TYPE_NORMAL:
      return "normal";
    case ITEM_TYPE_CHECKBOX:
      return "checkbox";
    case ITEM_TYPE_RADIO:
      return "radio";
    case ITEM_TYPE_SEPARATOR:
      return "separator";
    case ITEM_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ItemType ParseItemType(const std::string& enum_string) {
  if (enum_string == "normal")
    return ITEM_TYPE_NORMAL;
  if (enum_string == "checkbox")
    return ITEM_TYPE_CHECKBOX;
  if (enum_string == "radio")
    return ITEM_TYPE_RADIO;
  if (enum_string == "separator")
    return ITEM_TYPE_SEPARATOR;
  return ITEM_TYPE_NONE;
}



//
// Functions
//

namespace Create {

Params::CreateProperties::ParentId::ParentId()
 {}

Params::CreateProperties::ParentId::~ParentId() {}
Params::CreateProperties::ParentId::ParentId(ParentId&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_string(std::move(rhs.as_string)){
}

Params::CreateProperties::ParentId& Params::CreateProperties::ParentId::operator=(ParentId&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_string = std::move(rhs.as_string);
return *this;
}

// static
bool Params::CreateProperties::ParentId::Populate(
    const base::Value& value, ParentId* out) {
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



Params::CreateProperties::CreateProperties()
: type(ITEM_TYPE_NONE) {}

Params::CreateProperties::~CreateProperties() {}
Params::CreateProperties::CreateProperties(CreateProperties&& rhs)
: type(rhs.type),
id(std::move(rhs.id)),
title(std::move(rhs.title)),
checked(std::move(rhs.checked)),
contexts(std::move(rhs.contexts)),
visible(std::move(rhs.visible)),
onclick(std::move(rhs.onclick)),
parent_id(std::move(rhs.parent_id)),
document_url_patterns(std::move(rhs.document_url_patterns)),
target_url_patterns(std::move(rhs.target_url_patterns)),
enabled(std::move(rhs.enabled)){
}

Params::CreateProperties& Params::CreateProperties::operator=(CreateProperties&& rhs)
{
type = rhs.type;
id = std::move(rhs.id);
title = std::move(rhs.title);
checked = std::move(rhs.checked);
contexts = std::move(rhs.contexts);
visible = std::move(rhs.visible);
onclick = std::move(rhs.onclick);
parent_id = std::move(rhs.parent_id);
document_url_patterns = std::move(rhs.document_url_patterns);
target_url_patterns = std::move(rhs.target_url_patterns);
enabled = std::move(rhs.enabled);
return *this;
}

// static
bool Params::CreateProperties::Populate(
    const base::Value& value, CreateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = ITEM_TYPE_NONE;
  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string item_type_as_string;
      if (!type_value->GetAsString(&item_type_as_string)) {
        return false;
      }
      out->type = ParseItemType(item_type_as_string);
      if (out->type == ITEM_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = ITEM_TYPE_NONE;
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

  const base::Value* title_value = NULL;
  if (dict->GetWithoutPathExpansion("title", &title_value)) {
    {
      std::string temp;
      if (!title_value->GetAsString(&temp)) {
        out->title.reset();
        return false;
      }
      else
        out->title.reset(new std::string(temp));
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

  const base::Value* contexts_value = NULL;
  if (dict->GetWithoutPathExpansion("contexts", &contexts_value)) {
    {
      const base::ListValue* list = NULL;
      if (!contexts_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->contexts.reset(new std::vector<ContextType>);
        for (const auto& it : *(list)) {
          ContextType tmp;
          std::string context_type_as_string;
          if (!(it).GetAsString(&context_type_as_string)) {
            return false;
          }
          tmp = ParseContextType(context_type_as_string);
          if (tmp == CONTEXT_TYPE_NONE) {
            return false;
          }
          out->contexts->push_back(tmp);
        }
      }
    }
  }

  const base::Value* visible_value = NULL;
  if (dict->GetWithoutPathExpansion("visible", &visible_value)) {
    {
      bool temp;
      if (!visible_value->GetAsBoolean(&temp)) {
        out->visible.reset();
        return false;
      }
      else
        out->visible.reset(new bool(temp));
    }
  }

  const base::Value* onclick_value = NULL;
  if (dict->GetWithoutPathExpansion("onclick", &onclick_value)) {
    {
      out->onclick.reset(new base::DictionaryValue());
    }
  }

  const base::Value* parent_id_value = NULL;
  if (dict->GetWithoutPathExpansion("parentId", &parent_id_value)) {
    {
      std::unique_ptr<ParentId> temp(new ParentId());
      if (!ParentId::Populate(*parent_id_value, temp.get()))
        return false;
      out->parent_id = std::move(temp);
    }
  }

  const base::Value* document_url_patterns_value = NULL;
  if (dict->GetWithoutPathExpansion("documentUrlPatterns", &document_url_patterns_value)) {
    {
      const base::ListValue* list = NULL;
      if (!document_url_patterns_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->document_url_patterns)) {
          return false;
        }
      }
    }
  }

  const base::Value* target_url_patterns_value = NULL;
  if (dict->GetWithoutPathExpansion("targetUrlPatterns", &target_url_patterns_value)) {
    {
      const base::ListValue* list = NULL;
      if (!target_url_patterns_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->target_url_patterns)) {
          return false;
        }
      }
    }
  }

  const base::Value* enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("enabled", &enabled_value)) {
    {
      bool temp;
      if (!enabled_value->GetAsBoolean(&temp)) {
        out->enabled.reset();
        return false;
      }
      else
        out->enabled.reset(new bool(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* create_properties_value = NULL;
  if (args.Get(0, &create_properties_value) &&
      !create_properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!create_properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CreateProperties::Populate(*dictionary, &params->create_properties)) {
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
}  // namespace Create

namespace Update {

Params::Id::Id()
 {}

Params::Id::~Id() {}
Params::Id::Id(Id&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_string(std::move(rhs.as_string)){
}

Params::Id& Params::Id::operator=(Id&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_string = std::move(rhs.as_string);
return *this;
}

// static
bool Params::Id::Populate(
    const base::Value& value, Id* out) {
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


Params::UpdateProperties::ParentId::ParentId()
 {}

Params::UpdateProperties::ParentId::~ParentId() {}
Params::UpdateProperties::ParentId::ParentId(ParentId&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_string(std::move(rhs.as_string)){
}

Params::UpdateProperties::ParentId& Params::UpdateProperties::ParentId::operator=(ParentId&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_string = std::move(rhs.as_string);
return *this;
}

// static
bool Params::UpdateProperties::ParentId::Populate(
    const base::Value& value, ParentId* out) {
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



Params::UpdateProperties::UpdateProperties()
: type(ITEM_TYPE_NONE) {}

Params::UpdateProperties::~UpdateProperties() {}
Params::UpdateProperties::UpdateProperties(UpdateProperties&& rhs)
: type(rhs.type),
title(std::move(rhs.title)),
checked(std::move(rhs.checked)),
contexts(std::move(rhs.contexts)),
visible(std::move(rhs.visible)),
onclick(std::move(rhs.onclick)),
parent_id(std::move(rhs.parent_id)),
document_url_patterns(std::move(rhs.document_url_patterns)),
target_url_patterns(std::move(rhs.target_url_patterns)),
enabled(std::move(rhs.enabled)){
}

Params::UpdateProperties& Params::UpdateProperties::operator=(UpdateProperties&& rhs)
{
type = rhs.type;
title = std::move(rhs.title);
checked = std::move(rhs.checked);
contexts = std::move(rhs.contexts);
visible = std::move(rhs.visible);
onclick = std::move(rhs.onclick);
parent_id = std::move(rhs.parent_id);
document_url_patterns = std::move(rhs.document_url_patterns);
target_url_patterns = std::move(rhs.target_url_patterns);
enabled = std::move(rhs.enabled);
return *this;
}

// static
bool Params::UpdateProperties::Populate(
    const base::Value& value, UpdateProperties* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->type = ITEM_TYPE_NONE;
  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string item_type_as_string;
      if (!type_value->GetAsString(&item_type_as_string)) {
        return false;
      }
      out->type = ParseItemType(item_type_as_string);
      if (out->type == ITEM_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = ITEM_TYPE_NONE;
  }

  const base::Value* title_value = NULL;
  if (dict->GetWithoutPathExpansion("title", &title_value)) {
    {
      std::string temp;
      if (!title_value->GetAsString(&temp)) {
        out->title.reset();
        return false;
      }
      else
        out->title.reset(new std::string(temp));
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

  const base::Value* contexts_value = NULL;
  if (dict->GetWithoutPathExpansion("contexts", &contexts_value)) {
    {
      const base::ListValue* list = NULL;
      if (!contexts_value->GetAsList(&list)) {
        return false;
      }
      else {
        out->contexts.reset(new std::vector<ContextType>);
        for (const auto& it : *(list)) {
          ContextType tmp;
          std::string context_type_as_string;
          if (!(it).GetAsString(&context_type_as_string)) {
            return false;
          }
          tmp = ParseContextType(context_type_as_string);
          if (tmp == CONTEXT_TYPE_NONE) {
            return false;
          }
          out->contexts->push_back(tmp);
        }
      }
    }
  }

  const base::Value* visible_value = NULL;
  if (dict->GetWithoutPathExpansion("visible", &visible_value)) {
    {
      bool temp;
      if (!visible_value->GetAsBoolean(&temp)) {
        out->visible.reset();
        return false;
      }
      else
        out->visible.reset(new bool(temp));
    }
  }

  const base::Value* onclick_value = NULL;
  if (dict->GetWithoutPathExpansion("onclick", &onclick_value)) {
    {
      out->onclick.reset(new base::DictionaryValue());
    }
  }

  const base::Value* parent_id_value = NULL;
  if (dict->GetWithoutPathExpansion("parentId", &parent_id_value)) {
    {
      std::unique_ptr<ParentId> temp(new ParentId());
      if (!ParentId::Populate(*parent_id_value, temp.get()))
        return false;
      out->parent_id = std::move(temp);
    }
  }

  const base::Value* document_url_patterns_value = NULL;
  if (dict->GetWithoutPathExpansion("documentUrlPatterns", &document_url_patterns_value)) {
    {
      const base::ListValue* list = NULL;
      if (!document_url_patterns_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->document_url_patterns)) {
          return false;
        }
      }
    }
  }

  const base::Value* target_url_patterns_value = NULL;
  if (dict->GetWithoutPathExpansion("targetUrlPatterns", &target_url_patterns_value)) {
    {
      const base::ListValue* list = NULL;
      if (!target_url_patterns_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->target_url_patterns)) {
          return false;
        }
      }
    }
  }

  const base::Value* enabled_value = NULL;
  if (dict->GetWithoutPathExpansion("enabled", &enabled_value)) {
    {
      bool temp;
      if (!enabled_value->GetAsBoolean(&temp)) {
        out->enabled.reset();
        return false;
      }
      else
        out->enabled.reset(new bool(temp));
    }
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

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!Id::Populate(*id_value, &params->id))
        return std::unique_ptr<Params>();
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* update_properties_value = NULL;
  if (args.Get(1, &update_properties_value) &&
      !update_properties_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!update_properties_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!UpdateProperties::Populate(*dictionary, &params->update_properties)) {
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
}  // namespace Update

namespace Remove {

Params::MenuItemId::MenuItemId()
 {}

Params::MenuItemId::~MenuItemId() {}
Params::MenuItemId::MenuItemId(MenuItemId&& rhs)
: as_integer(std::move(rhs.as_integer)),
as_string(std::move(rhs.as_string)){
}

Params::MenuItemId& Params::MenuItemId::operator=(MenuItemId&& rhs)
{
as_integer = std::move(rhs.as_integer);
as_string = std::move(rhs.as_string);
return *this;
}

// static
bool Params::MenuItemId::Populate(
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


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* menu_item_id_value = NULL;
  if (args.Get(0, &menu_item_id_value) &&
      !menu_item_id_value->is_none()) {
    {
      if (!MenuItemId::Populate(*menu_item_id_value, &params->menu_item_id))
        return std::unique_ptr<Params>();
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

namespace RemoveAll {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RemoveAll

//
// Events
//

namespace OnClicked {

const char kEventName[] = "contextMenus.onClicked";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnClicked

}  // namespace context_menus
}  // namespace api
}  // namespace extensions

