// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/omnibox.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/omnibox.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace omnibox {
//
// Types
//

const char* ToString(DescriptionStyleType enum_param) {
  switch (enum_param) {
    case DESCRIPTION_STYLE_TYPE_URL:
      return "url";
    case DESCRIPTION_STYLE_TYPE_MATCH:
      return "match";
    case DESCRIPTION_STYLE_TYPE_DIM:
      return "dim";
    case DESCRIPTION_STYLE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DescriptionStyleType ParseDescriptionStyleType(const std::string& enum_string) {
  if (enum_string == "url")
    return DESCRIPTION_STYLE_TYPE_URL;
  if (enum_string == "match")
    return DESCRIPTION_STYLE_TYPE_MATCH;
  if (enum_string == "dim")
    return DESCRIPTION_STYLE_TYPE_DIM;
  return DESCRIPTION_STYLE_TYPE_NONE;
}


const char* ToString(OnInputEnteredDisposition enum_param) {
  switch (enum_param) {
    case ON_INPUT_ENTERED_DISPOSITION_CURRENTTAB:
      return "currentTab";
    case ON_INPUT_ENTERED_DISPOSITION_NEWFOREGROUNDTAB:
      return "newForegroundTab";
    case ON_INPUT_ENTERED_DISPOSITION_NEWBACKGROUNDTAB:
      return "newBackgroundTab";
    case ON_INPUT_ENTERED_DISPOSITION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnInputEnteredDisposition ParseOnInputEnteredDisposition(const std::string& enum_string) {
  if (enum_string == "currentTab")
    return ON_INPUT_ENTERED_DISPOSITION_CURRENTTAB;
  if (enum_string == "newForegroundTab")
    return ON_INPUT_ENTERED_DISPOSITION_NEWFOREGROUNDTAB;
  if (enum_string == "newBackgroundTab")
    return ON_INPUT_ENTERED_DISPOSITION_NEWBACKGROUNDTAB;
  return ON_INPUT_ENTERED_DISPOSITION_NONE;
}


SuggestResult::DescriptionStylesType::DescriptionStylesType()
: offset(0),
type(DESCRIPTION_STYLE_TYPE_NONE) {}

SuggestResult::DescriptionStylesType::~DescriptionStylesType() {}
SuggestResult::DescriptionStylesType::DescriptionStylesType(DescriptionStylesType&& rhs)
: offset(rhs.offset),
type(rhs.type),
length(std::move(rhs.length)){
}

SuggestResult::DescriptionStylesType& SuggestResult::DescriptionStylesType::operator=(DescriptionStylesType&& rhs)
{
offset = rhs.offset;
type = rhs.type;
length = std::move(rhs.length);
return *this;
}

// static
bool SuggestResult::DescriptionStylesType::Populate(
    const base::Value& value, DescriptionStylesType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("offset", &offset_value)) {
    return false;
  }
  {
    if (!offset_value->GetAsInteger(&out->offset)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string description_style_type_as_string;
    if (!type_value->GetAsString(&description_style_type_as_string)) {
      return false;
    }
    out->type = ParseDescriptionStyleType(description_style_type_as_string);
    if (out->type == DESCRIPTION_STYLE_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* length_value = NULL;
  if (dict->GetWithoutPathExpansion("length", &length_value)) {
    {
      int temp;
      if (!length_value->GetAsInteger(&temp)) {
        out->length.reset();
        return false;
      }
      else
        out->length.reset(new int(temp));
    }
  }

  return true;
}

std::unique_ptr<base::DictionaryValue> SuggestResult::DescriptionStylesType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("offset", std::make_unique<base::Value>(this->offset));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(omnibox::ToString(this->type)));

  if (this->length.get()) {
    to_value_result->SetWithoutPathExpansion("length", std::make_unique<base::Value>(*this->length));

  }

  return to_value_result;
}



SuggestResult::DescriptionStylesRawType::DescriptionStylesRawType()
: offset(0),
type(0) {}

SuggestResult::DescriptionStylesRawType::~DescriptionStylesRawType() {}
SuggestResult::DescriptionStylesRawType::DescriptionStylesRawType(DescriptionStylesRawType&& rhs)
: offset(rhs.offset),
type(rhs.type){
}

SuggestResult::DescriptionStylesRawType& SuggestResult::DescriptionStylesRawType::operator=(DescriptionStylesRawType&& rhs)
{
offset = rhs.offset;
type = rhs.type;
return *this;
}

// static
bool SuggestResult::DescriptionStylesRawType::Populate(
    const base::Value& value, DescriptionStylesRawType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("offset", &offset_value)) {
    return false;
  }
  {
    if (!offset_value->GetAsInteger(&out->offset)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    if (!type_value->GetAsInteger(&out->type)) {
      return false;
    }
  }

  return true;
}

std::unique_ptr<base::DictionaryValue> SuggestResult::DescriptionStylesRawType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("offset", std::make_unique<base::Value>(this->offset));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(this->type));


  return to_value_result;
}




SuggestResult::SuggestResult()
 {}

SuggestResult::~SuggestResult() {}
SuggestResult::SuggestResult(SuggestResult&& rhs)
: content(std::move(rhs.content)),
description(std::move(rhs.description)),
deletable(std::move(rhs.deletable)),
description_styles(std::move(rhs.description_styles)),
description_styles_raw(std::move(rhs.description_styles_raw)){
}

SuggestResult& SuggestResult::operator=(SuggestResult&& rhs)
{
content = std::move(rhs.content);
description = std::move(rhs.description);
deletable = std::move(rhs.deletable);
description_styles = std::move(rhs.description_styles);
description_styles_raw = std::move(rhs.description_styles_raw);
return *this;
}

// static
bool SuggestResult::Populate(
    const base::Value& value, SuggestResult* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* content_value = NULL;
  if (!dict->GetWithoutPathExpansion("content", &content_value)) {
    return false;
  }
  {
    if (!content_value->GetAsString(&out->content)) {
      return false;
    }
  }

  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* deletable_value = NULL;
  if (dict->GetWithoutPathExpansion("deletable", &deletable_value)) {
    {
      bool temp;
      if (!deletable_value->GetAsBoolean(&temp)) {
        out->deletable.reset();
        return false;
      }
      else
        out->deletable.reset(new bool(temp));
    }
  }

  const base::Value* description_styles_value = NULL;
  if (dict->GetWithoutPathExpansion("descriptionStyles", &description_styles_value)) {
    {
      const base::ListValue* list = NULL;
      if (!description_styles_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->description_styles)) {
          return false;
        }
      }
    }
  }

  const base::Value* description_styles_raw_value = NULL;
  if (dict->GetWithoutPathExpansion("descriptionStylesRaw", &description_styles_raw_value)) {
    {
      const base::ListValue* list = NULL;
      if (!description_styles_raw_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->description_styles_raw)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<SuggestResult> SuggestResult::FromValue(const base::Value& value) {
  std::unique_ptr<SuggestResult> out(new SuggestResult());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SuggestResult::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("content", std::make_unique<base::Value>(this->content));

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  if (this->deletable.get()) {
    to_value_result->SetWithoutPathExpansion("deletable", std::make_unique<base::Value>(*this->deletable));

  }
  if (this->description_styles.get()) {
    to_value_result->SetWithoutPathExpansion("descriptionStyles", json_schema_compiler::util::CreateValueFromOptionalArray(this->description_styles));

  }
  if (this->description_styles_raw.get()) {
    to_value_result->SetWithoutPathExpansion("descriptionStylesRaw", json_schema_compiler::util::CreateValueFromOptionalArray(this->description_styles_raw));

  }

  return to_value_result;
}


DefaultSuggestResult::DescriptionStylesType::DescriptionStylesType()
: offset(0),
type(DESCRIPTION_STYLE_TYPE_NONE) {}

DefaultSuggestResult::DescriptionStylesType::~DescriptionStylesType() {}
DefaultSuggestResult::DescriptionStylesType::DescriptionStylesType(DescriptionStylesType&& rhs)
: offset(rhs.offset),
type(rhs.type),
length(std::move(rhs.length)){
}

DefaultSuggestResult::DescriptionStylesType& DefaultSuggestResult::DescriptionStylesType::operator=(DescriptionStylesType&& rhs)
{
offset = rhs.offset;
type = rhs.type;
length = std::move(rhs.length);
return *this;
}

// static
bool DefaultSuggestResult::DescriptionStylesType::Populate(
    const base::Value& value, DescriptionStylesType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("offset", &offset_value)) {
    return false;
  }
  {
    if (!offset_value->GetAsInteger(&out->offset)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string description_style_type_as_string;
    if (!type_value->GetAsString(&description_style_type_as_string)) {
      return false;
    }
    out->type = ParseDescriptionStyleType(description_style_type_as_string);
    if (out->type == DESCRIPTION_STYLE_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* length_value = NULL;
  if (dict->GetWithoutPathExpansion("length", &length_value)) {
    {
      int temp;
      if (!length_value->GetAsInteger(&temp)) {
        out->length.reset();
        return false;
      }
      else
        out->length.reset(new int(temp));
    }
  }

  return true;
}

std::unique_ptr<base::DictionaryValue> DefaultSuggestResult::DescriptionStylesType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("offset", std::make_unique<base::Value>(this->offset));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(omnibox::ToString(this->type)));

  if (this->length.get()) {
    to_value_result->SetWithoutPathExpansion("length", std::make_unique<base::Value>(*this->length));

  }

  return to_value_result;
}



DefaultSuggestResult::DescriptionStylesRawType::DescriptionStylesRawType()
: offset(0),
type(0) {}

DefaultSuggestResult::DescriptionStylesRawType::~DescriptionStylesRawType() {}
DefaultSuggestResult::DescriptionStylesRawType::DescriptionStylesRawType(DescriptionStylesRawType&& rhs)
: offset(rhs.offset),
type(rhs.type){
}

DefaultSuggestResult::DescriptionStylesRawType& DefaultSuggestResult::DescriptionStylesRawType::operator=(DescriptionStylesRawType&& rhs)
{
offset = rhs.offset;
type = rhs.type;
return *this;
}

// static
bool DefaultSuggestResult::DescriptionStylesRawType::Populate(
    const base::Value& value, DescriptionStylesRawType* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* offset_value = NULL;
  if (!dict->GetWithoutPathExpansion("offset", &offset_value)) {
    return false;
  }
  {
    if (!offset_value->GetAsInteger(&out->offset)) {
      return false;
    }
  }

  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    if (!type_value->GetAsInteger(&out->type)) {
      return false;
    }
  }

  return true;
}

std::unique_ptr<base::DictionaryValue> DefaultSuggestResult::DescriptionStylesRawType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("offset", std::make_unique<base::Value>(this->offset));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(this->type));


  return to_value_result;
}




DefaultSuggestResult::DefaultSuggestResult()
 {}

DefaultSuggestResult::~DefaultSuggestResult() {}
DefaultSuggestResult::DefaultSuggestResult(DefaultSuggestResult&& rhs)
: description(std::move(rhs.description)),
description_styles(std::move(rhs.description_styles)),
description_styles_raw(std::move(rhs.description_styles_raw)){
}

DefaultSuggestResult& DefaultSuggestResult::operator=(DefaultSuggestResult&& rhs)
{
description = std::move(rhs.description);
description_styles = std::move(rhs.description_styles);
description_styles_raw = std::move(rhs.description_styles_raw);
return *this;
}

// static
bool DefaultSuggestResult::Populate(
    const base::Value& value, DefaultSuggestResult* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* description_value = NULL;
  if (!dict->GetWithoutPathExpansion("description", &description_value)) {
    return false;
  }
  {
    if (!description_value->GetAsString(&out->description)) {
      return false;
    }
  }

  const base::Value* description_styles_value = NULL;
  if (dict->GetWithoutPathExpansion("descriptionStyles", &description_styles_value)) {
    {
      const base::ListValue* list = NULL;
      if (!description_styles_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->description_styles)) {
          return false;
        }
      }
    }
  }

  const base::Value* description_styles_raw_value = NULL;
  if (dict->GetWithoutPathExpansion("descriptionStylesRaw", &description_styles_raw_value)) {
    {
      const base::ListValue* list = NULL;
      if (!description_styles_raw_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->description_styles_raw)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<DefaultSuggestResult> DefaultSuggestResult::FromValue(const base::Value& value) {
  std::unique_ptr<DefaultSuggestResult> out(new DefaultSuggestResult());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> DefaultSuggestResult::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("description", std::make_unique<base::Value>(this->description));

  if (this->description_styles.get()) {
    to_value_result->SetWithoutPathExpansion("descriptionStyles", json_schema_compiler::util::CreateValueFromOptionalArray(this->description_styles));

  }
  if (this->description_styles_raw.get()) {
    to_value_result->SetWithoutPathExpansion("descriptionStylesRaw", json_schema_compiler::util::CreateValueFromOptionalArray(this->description_styles_raw));

  }

  return to_value_result;
}



//
// Functions
//

namespace SendSuggestions {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* request_id_value = NULL;
  if (args.Get(0, &request_id_value) &&
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

  const base::Value* suggest_results_value = NULL;
  if (args.Get(1, &suggest_results_value) &&
      !suggest_results_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!suggest_results_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->suggest_results)) {
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


}  // namespace SendSuggestions

namespace SetDefaultSuggestion {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* suggestion_value = NULL;
  if (args.Get(0, &suggestion_value) &&
      !suggestion_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!suggestion_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!DefaultSuggestResult::Populate(*dictionary, &params->suggestion)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetDefaultSuggestion

//
// Events
//

namespace OnInputStarted {

const char kEventName[] = "omnibox.onInputStarted";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnInputStarted

namespace OnInputChanged {

const char kEventName[] = "omnibox.onInputChanged";

std::unique_ptr<base::ListValue> Create(const std::string& text) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(text));

  return create_results;
}

}  // namespace OnInputChanged

namespace OnInputEntered {

const char kEventName[] = "omnibox.onInputEntered";

std::unique_ptr<base::ListValue> Create(const std::string& text, const OnInputEnteredDisposition& disposition) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(text));

  create_results->Append(std::make_unique<base::Value>(omnibox::ToString(disposition)));

  return create_results;
}

}  // namespace OnInputEntered

namespace OnInputCancelled {

const char kEventName[] = "omnibox.onInputCancelled";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnInputCancelled

namespace OnDeleteSuggestion {

const char kEventName[] = "omnibox.onDeleteSuggestion";

std::unique_ptr<base::ListValue> Create(const std::string& text) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(text));

  return create_results;
}

}  // namespace OnDeleteSuggestion

}  // namespace omnibox
}  // namespace api
}  // namespace extensions

