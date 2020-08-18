// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/chrome_web_view_internal.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/chrome_web_view_internal.h"
#include <set>
#include <utility>
#include "chrome/common/extensions/api/context_menus.h"
#include "chrome/common/extensions/api/context_menus.h"
#include "chrome/common/extensions/api/context_menus.h"
#include "chrome/common/extensions/api/context_menus.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace chrome_web_view_internal {
//
// Types
//

ContextMenuItem::ContextMenuItem()
: command_id(0) {}

ContextMenuItem::~ContextMenuItem() {}
ContextMenuItem::ContextMenuItem(ContextMenuItem&& rhs)
: label(std::move(rhs.label)),
command_id(rhs.command_id){
}

ContextMenuItem& ContextMenuItem::operator=(ContextMenuItem&& rhs)
{
label = std::move(rhs.label);
command_id = rhs.command_id;
return *this;
}

// static
bool ContextMenuItem::Populate(
    const base::Value& value, ContextMenuItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* label_value = NULL;
  if (dict->GetWithoutPathExpansion("label", &label_value)) {
    {
      std::string temp;
      if (!label_value->GetAsString(&temp)) {
        out->label.reset();
        return false;
      }
      else
        out->label.reset(new std::string(temp));
    }
  }

  const base::Value* command_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("commandId", &command_id_value)) {
    return false;
  }
  {
    if (!command_id_value->GetAsInteger(&out->command_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ContextMenuItem> ContextMenuItem::FromValue(const base::Value& value) {
  std::unique_ptr<ContextMenuItem> out(new ContextMenuItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ContextMenuItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->label.get()) {
    to_value_result->SetWithoutPathExpansion("label", std::make_unique<base::Value>(*this->label));

  }
  to_value_result->SetWithoutPathExpansion("commandId", std::make_unique<base::Value>(this->command_id));


  return to_value_result;
}



//
// Functions
//

namespace ContextMenusCreate {

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
: type(context_menus::ITEM_TYPE_NONE) {}

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
  out->type = context_menus::ITEM_TYPE_NONE;
  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string item_type_as_string;
      if (!type_value->GetAsString(&item_type_as_string)) {
        return false;
      }
      out->type = context_menus::ParseItemType(item_type_as_string);
      if (out->type == context_menus::ITEM_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = context_menus::ITEM_TYPE_NONE;
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
        out->contexts.reset(new std::vector<extensions::api::context_menus::ContextType>);
        for (const auto& it : *(list)) {
          extensions::api::context_menus::ContextType tmp;
          std::string context_type_as_string;
          if (!(it).GetAsString(&context_type_as_string)) {
            return false;
          }
          tmp = context_menus::ParseContextType(context_type_as_string);
          if (tmp == context_menus::CONTEXT_TYPE_NONE) {
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

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* create_properties_value = NULL;
  if (args.Get(1, &create_properties_value) &&
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
}  // namespace ContextMenusCreate

namespace ContextMenusUpdate {

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
: type(context_menus::ITEM_TYPE_NONE) {}

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
  out->type = context_menus::ITEM_TYPE_NONE;
  const base::Value* type_value = NULL;
  if (dict->GetWithoutPathExpansion("type", &type_value)) {
    {
      std::string item_type_as_string;
      if (!type_value->GetAsString(&item_type_as_string)) {
        return false;
      }
      out->type = context_menus::ParseItemType(item_type_as_string);
      if (out->type == context_menus::ITEM_TYPE_NONE) {
        return false;
      }
    }
    } else {
    out->type = context_menus::ITEM_TYPE_NONE;
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
        out->contexts.reset(new std::vector<extensions::api::context_menus::ContextType>);
        for (const auto& it : *(list)) {
          extensions::api::context_menus::ContextType tmp;
          std::string context_type_as_string;
          if (!(it).GetAsString(&context_type_as_string)) {
            return false;
          }
          tmp = context_menus::ParseContextType(context_type_as_string);
          if (tmp == context_menus::CONTEXT_TYPE_NONE) {
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
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* id_value = NULL;
  if (args.Get(1, &id_value) &&
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
  if (args.Get(2, &update_properties_value) &&
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
}  // namespace ContextMenusUpdate

namespace ContextMenusRemove {

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
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* menu_item_id_value = NULL;
  if (args.Get(1, &menu_item_id_value) &&
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
}  // namespace ContextMenusRemove

namespace ContextMenusRemoveAll {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
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
}  // namespace ContextMenusRemoveAll

namespace ShowContextMenu {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* instance_id_value = NULL;
  if (args.Get(0, &instance_id_value) &&
      !instance_id_value->is_none()) {
    {
      if (!instance_id_value->GetAsInteger(&params->instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* request_id_value = NULL;
  if (args.Get(1, &request_id_value) &&
      !request_id_value->is_none()) {
    {
      if (!request_id_value->GetAsInteger(&params->request_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* items_to_show_value = NULL;
  if (args.Get(2, &items_to_show_value) &&
      !items_to_show_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!items_to_show_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &params->items_to_show)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }

  return params;
}


}  // namespace ShowContextMenu

//
// Events
//

namespace OnClicked {

const char kEventName[] = "chromeWebViewInternal.onClicked";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnClicked

namespace OnShow {

const char kEventName[] = "chromeWebViewInternal.onShow";

Event::Event()
 {}

Event::~Event() {}
Event::Event(Event&& rhs)
{
prevent_default.Swap(&rhs.prevent_default);
}

Event& Event::operator=(Event&& rhs)
{
prevent_default.Swap(&rhs.prevent_default);
return *this;
}

std::unique_ptr<base::DictionaryValue> Event::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("preventDefault", (this->prevent_default).CreateDeepCopy());


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const Event& event) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((event).ToValue());

  return create_results;
}

}  // namespace OnShow

}  // namespace chrome_web_view_internal
}  // namespace api
}  // namespace extensions

