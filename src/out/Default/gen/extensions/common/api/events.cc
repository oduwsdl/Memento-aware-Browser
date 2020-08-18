// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/events.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/events.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace events {
//
// Types
//

Rule::Rule()
 {}

Rule::~Rule() {}
Rule::Rule(Rule&& rhs)
: id(std::move(rhs.id)),
tags(std::move(rhs.tags)),
conditions(std::move(rhs.conditions)),
actions(std::move(rhs.actions)),
priority(std::move(rhs.priority)){
}

Rule& Rule::operator=(Rule&& rhs)
{
id = std::move(rhs.id);
tags = std::move(rhs.tags);
conditions = std::move(rhs.conditions);
actions = std::move(rhs.actions);
priority = std::move(rhs.priority);
return *this;
}

// static
bool Rule::Populate(
    const base::Value& value, Rule* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* tags_value = NULL;
  if (dict->GetWithoutPathExpansion("tags", &tags_value)) {
    {
      const base::ListValue* list = NULL;
      if (!tags_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->tags)) {
          return false;
        }
      }
    }
  }

  const base::Value* conditions_value = NULL;
  if (!dict->GetWithoutPathExpansion("conditions", &conditions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!conditions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->conditions)) {
        return false;
      }
    }
  }

  const base::Value* actions_value = NULL;
  if (!dict->GetWithoutPathExpansion("actions", &actions_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!actions_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->actions)) {
        return false;
      }
    }
  }

  const base::Value* priority_value = NULL;
  if (dict->GetWithoutPathExpansion("priority", &priority_value)) {
    {
      int temp;
      if (!priority_value->GetAsInteger(&temp)) {
        out->priority.reset();
        return false;
      }
      else
        out->priority.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<Rule> Rule::FromValue(const base::Value& value) {
  std::unique_ptr<Rule> out(new Rule());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Rule::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }
  if (this->tags.get()) {
    to_value_result->SetWithoutPathExpansion("tags", json_schema_compiler::util::CreateValueFromOptionalArray(this->tags));

  }
  to_value_result->SetWithoutPathExpansion("conditions", json_schema_compiler::util::CreateValueFromArray(this->conditions));

  to_value_result->SetWithoutPathExpansion("actions", json_schema_compiler::util::CreateValueFromArray(this->actions));

  if (this->priority.get()) {
    to_value_result->SetWithoutPathExpansion("priority", std::make_unique<base::Value>(*this->priority));

  }

  return to_value_result;
}


namespace Event {

namespace AddRules {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* event_name_value = NULL;
  if (args.Get(0, &event_name_value) &&
      !event_name_value->is_none()) {
    {
      if (!event_name_value->GetAsString(&params->event_name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* web_view_instance_id_value = NULL;
  if (args.Get(1, &web_view_instance_id_value) &&
      !web_view_instance_id_value->is_none()) {
    {
      if (!web_view_instance_id_value->GetAsInteger(&params->web_view_instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* rules_value = NULL;
  if (args.Get(2, &rules_value) &&
      !rules_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!rules_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->rules)) {
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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Rule>& rules) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(rules));

  return create_results;
}
}  // namespace AddRules

namespace GetRules {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* event_name_value = NULL;
  if (args.Get(0, &event_name_value) &&
      !event_name_value->is_none()) {
    {
      if (!event_name_value->GetAsString(&params->event_name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* web_view_instance_id_value = NULL;
  if (args.Get(1, &web_view_instance_id_value) &&
      !web_view_instance_id_value->is_none()) {
    {
      if (!web_view_instance_id_value->GetAsInteger(&params->web_view_instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* rule_identifiers_value = NULL;
  if (args.Get(2, &rule_identifiers_value) &&
      !rule_identifiers_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!rule_identifiers_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &params->rule_identifiers)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Rule>& rules) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(rules));

  return create_results;
}
}  // namespace GetRules

namespace RemoveRules {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* event_name_value = NULL;
  if (args.Get(0, &event_name_value) &&
      !event_name_value->is_none()) {
    {
      if (!event_name_value->GetAsString(&params->event_name)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* web_view_instance_id_value = NULL;
  if (args.Get(1, &web_view_instance_id_value) &&
      !web_view_instance_id_value->is_none()) {
    {
      if (!web_view_instance_id_value->GetAsInteger(&params->web_view_instance_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* rule_identifiers_value = NULL;
  if (args.Get(2, &rule_identifiers_value) &&
      !rule_identifiers_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!rule_identifiers_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &params->rule_identifiers)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RemoveRules

}  // namespace Event


}  // namespace events
}  // namespace api
}  // namespace extensions

