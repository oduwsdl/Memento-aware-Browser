// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/bookmarks.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/bookmarks.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace bookmarks {
//
// Properties
//

const int MAX_WRITE_OPERATIONS_PER_HOUR = 1000000;

const int MAX_SUSTAINED_WRITE_OPERATIONS_PER_MINUTE = 1000000;

//
// Types
//

const char* ToString(BookmarkTreeNodeUnmodifiable enum_param) {
  switch (enum_param) {
    case BOOKMARK_TREE_NODE_UNMODIFIABLE_MANAGED:
      return "managed";
    case BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

BookmarkTreeNodeUnmodifiable ParseBookmarkTreeNodeUnmodifiable(const std::string& enum_string) {
  if (enum_string == "managed")
    return BOOKMARK_TREE_NODE_UNMODIFIABLE_MANAGED;
  return BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE;
}


BookmarkTreeNode::BookmarkTreeNode()
: unmodifiable(BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE) {}

BookmarkTreeNode::~BookmarkTreeNode() {}
BookmarkTreeNode::BookmarkTreeNode(BookmarkTreeNode&& rhs)
: id(std::move(rhs.id)),
parent_id(std::move(rhs.parent_id)),
index(std::move(rhs.index)),
url(std::move(rhs.url)),
title(std::move(rhs.title)),
date_added(std::move(rhs.date_added)),
date_group_modified(std::move(rhs.date_group_modified)),
unmodifiable(rhs.unmodifiable),
children(std::move(rhs.children)){
}

BookmarkTreeNode& BookmarkTreeNode::operator=(BookmarkTreeNode&& rhs)
{
id = std::move(rhs.id);
parent_id = std::move(rhs.parent_id);
index = std::move(rhs.index);
url = std::move(rhs.url);
title = std::move(rhs.title);
date_added = std::move(rhs.date_added);
date_group_modified = std::move(rhs.date_group_modified);
unmodifiable = rhs.unmodifiable;
children = std::move(rhs.children);
return *this;
}

// static
bool BookmarkTreeNode::Populate(
    const base::Value& value, BookmarkTreeNode* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->unmodifiable = BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE;
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
  if (dict->GetWithoutPathExpansion("parentId", &parent_id_value)) {
    {
      std::string temp;
      if (!parent_id_value->GetAsString(&temp)) {
        out->parent_id.reset();
        return false;
      }
      else
        out->parent_id.reset(new std::string(temp));
    }
  }

  const base::Value* index_value = NULL;
  if (dict->GetWithoutPathExpansion("index", &index_value)) {
    {
      int temp;
      if (!index_value->GetAsInteger(&temp)) {
        out->index.reset();
        return false;
      }
      else
        out->index.reset(new int(temp));
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
    }
  }

  const base::Value* title_value = NULL;
  if (!dict->GetWithoutPathExpansion("title", &title_value)) {
    return false;
  }
  {
    if (!title_value->GetAsString(&out->title)) {
      return false;
    }
  }

  const base::Value* date_added_value = NULL;
  if (dict->GetWithoutPathExpansion("dateAdded", &date_added_value)) {
    {
      double temp;
      if (!date_added_value->GetAsDouble(&temp)) {
        out->date_added.reset();
        return false;
      }
      else
        out->date_added.reset(new double(temp));
    }
  }

  const base::Value* date_group_modified_value = NULL;
  if (dict->GetWithoutPathExpansion("dateGroupModified", &date_group_modified_value)) {
    {
      double temp;
      if (!date_group_modified_value->GetAsDouble(&temp)) {
        out->date_group_modified.reset();
        return false;
      }
      else
        out->date_group_modified.reset(new double(temp));
    }
  }

  const base::Value* unmodifiable_value = NULL;
  if (dict->GetWithoutPathExpansion("unmodifiable", &unmodifiable_value)) {
    {
      std::string bookmark_tree_node_unmodifiable_as_string;
      if (!unmodifiable_value->GetAsString(&bookmark_tree_node_unmodifiable_as_string)) {
        return false;
      }
      out->unmodifiable = ParseBookmarkTreeNodeUnmodifiable(bookmark_tree_node_unmodifiable_as_string);
      if (out->unmodifiable == BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE) {
        return false;
      }
    }
    } else {
    out->unmodifiable = BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE;
  }

  const base::Value* children_value = NULL;
  if (dict->GetWithoutPathExpansion("children", &children_value)) {
    {
      const base::ListValue* list = NULL;
      if (!children_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->children)) {
          return false;
        }
      }
    }
  }

  return true;
}

// static
std::unique_ptr<BookmarkTreeNode> BookmarkTreeNode::FromValue(const base::Value& value) {
  std::unique_ptr<BookmarkTreeNode> out(new BookmarkTreeNode());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> BookmarkTreeNode::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  if (this->parent_id.get()) {
    to_value_result->SetWithoutPathExpansion("parentId", std::make_unique<base::Value>(*this->parent_id));

  }
  if (this->index.get()) {
    to_value_result->SetWithoutPathExpansion("index", std::make_unique<base::Value>(*this->index));

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  if (this->date_added.get()) {
    to_value_result->SetWithoutPathExpansion("dateAdded", std::make_unique<base::Value>(*this->date_added));

  }
  if (this->date_group_modified.get()) {
    to_value_result->SetWithoutPathExpansion("dateGroupModified", std::make_unique<base::Value>(*this->date_group_modified));

  }
  if (this->unmodifiable != BOOKMARK_TREE_NODE_UNMODIFIABLE_NONE) {
    to_value_result->SetWithoutPathExpansion("unmodifiable", std::make_unique<base::Value>(bookmarks::ToString(this->unmodifiable)));

  }
  if (this->children.get()) {
    to_value_result->SetWithoutPathExpansion("children", json_schema_compiler::util::CreateValueFromOptionalArray(this->children));

  }

  return to_value_result;
}


CreateDetails::CreateDetails()
 {}

CreateDetails::~CreateDetails() {}
CreateDetails::CreateDetails(CreateDetails&& rhs)
: parent_id(std::move(rhs.parent_id)),
index(std::move(rhs.index)),
title(std::move(rhs.title)),
url(std::move(rhs.url)){
}

CreateDetails& CreateDetails::operator=(CreateDetails&& rhs)
{
parent_id = std::move(rhs.parent_id);
index = std::move(rhs.index);
title = std::move(rhs.title);
url = std::move(rhs.url);
return *this;
}

// static
bool CreateDetails::Populate(
    const base::Value& value, CreateDetails* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* parent_id_value = NULL;
  if (dict->GetWithoutPathExpansion("parentId", &parent_id_value)) {
    {
      std::string temp;
      if (!parent_id_value->GetAsString(&temp)) {
        out->parent_id.reset();
        return false;
      }
      else
        out->parent_id.reset(new std::string(temp));
    }
  }

  const base::Value* index_value = NULL;
  if (dict->GetWithoutPathExpansion("index", &index_value)) {
    {
      int temp;
      if (!index_value->GetAsInteger(&temp)) {
        out->index.reset();
        return false;
      }
      else
        out->index.reset(new int(temp));
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

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<CreateDetails> CreateDetails::FromValue(const base::Value& value) {
  std::unique_ptr<CreateDetails> out(new CreateDetails());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CreateDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->parent_id.get()) {
    to_value_result->SetWithoutPathExpansion("parentId", std::make_unique<base::Value>(*this->parent_id));

  }
  if (this->index.get()) {
    to_value_result->SetWithoutPathExpansion("index", std::make_unique<base::Value>(*this->index));

  }
  if (this->title.get()) {
    to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(*this->title));

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }

  return to_value_result;
}



//
// Functions
//

namespace Get {

Params::IdOrIdList::IdOrIdList()
 {}

Params::IdOrIdList::~IdOrIdList() {}
Params::IdOrIdList::IdOrIdList(IdOrIdList&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)){
}

Params::IdOrIdList& Params::IdOrIdList::operator=(IdOrIdList&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool Params::IdOrIdList::Populate(
    const base::Value& value, IdOrIdList* out) {
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


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_or_id_list_value = NULL;
  if (args.Get(0, &id_or_id_list_value) &&
      !id_or_id_list_value->is_none()) {
    {
      if (!IdOrIdList::Populate(*id_or_id_list_value, &params->id_or_id_list))
        return std::unique_ptr<Params>();
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<BookmarkTreeNode>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace Get

namespace GetChildren {

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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<BookmarkTreeNode>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace GetChildren

namespace GetRecent {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* number_of_items_value = NULL;
  if (args.Get(0, &number_of_items_value) &&
      !number_of_items_value->is_none()) {
    {
      if (!number_of_items_value->GetAsInteger(&params->number_of_items)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<BookmarkTreeNode>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace GetRecent

namespace GetTree {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<BookmarkTreeNode>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace GetTree

namespace GetSubTree {

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


std::unique_ptr<base::ListValue> Results::Create(const std::vector<BookmarkTreeNode>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace GetSubTree

namespace Search {

Params::Query::Object::Object()
 {}

Params::Query::Object::~Object() {}
Params::Query::Object::Object(Object&& rhs)
: query(std::move(rhs.query)),
url(std::move(rhs.url)),
title(std::move(rhs.title)){
}

Params::Query::Object& Params::Query::Object::operator=(Object&& rhs)
{
query = std::move(rhs.query);
url = std::move(rhs.url);
title = std::move(rhs.title);
return *this;
}

// static
bool Params::Query::Object::Populate(
    const base::Value& value, Object* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* query_value = NULL;
  if (dict->GetWithoutPathExpansion("query", &query_value)) {
    {
      std::string temp;
      if (!query_value->GetAsString(&temp)) {
        out->query.reset();
        return false;
      }
      else
        out->query.reset(new std::string(temp));
    }
  }

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
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

  return true;
}



Params::Query::Query()
 {}

Params::Query::~Query() {}
Params::Query::Query(Query&& rhs)
: as_string(std::move(rhs.as_string)),
as_object(std::move(rhs.as_object)){
}

Params::Query& Params::Query::operator=(Query&& rhs)
{
as_string = std::move(rhs.as_string);
as_object = std::move(rhs.as_object);
return *this;
}

// static
bool Params::Query::Populate(
    const base::Value& value, Query* out) {
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
        std::unique_ptr<Object> temp(new Object());
        if (!Object::Populate(*dictionary, temp.get())) {
          return false;
        }
        else
          out->as_object = std::move(temp);
      }
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

  const base::Value* query_value = NULL;
  if (args.Get(0, &query_value) &&
      !query_value->is_none()) {
    {
      if (!Query::Populate(*query_value, &params->query))
        return std::unique_ptr<Params>();
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<BookmarkTreeNode>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace Search

namespace Create {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* bookmark_value = NULL;
  if (args.Get(0, &bookmark_value) &&
      !bookmark_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!bookmark_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CreateDetails::Populate(*dictionary, &params->bookmark)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const BookmarkTreeNode& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace Create

namespace Move {

Params::Destination::Destination()
 {}

Params::Destination::~Destination() {}
Params::Destination::Destination(Destination&& rhs)
: parent_id(std::move(rhs.parent_id)),
index(std::move(rhs.index)){
}

Params::Destination& Params::Destination::operator=(Destination&& rhs)
{
parent_id = std::move(rhs.parent_id);
index = std::move(rhs.index);
return *this;
}

// static
bool Params::Destination::Populate(
    const base::Value& value, Destination* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* parent_id_value = NULL;
  if (dict->GetWithoutPathExpansion("parentId", &parent_id_value)) {
    {
      std::string temp;
      if (!parent_id_value->GetAsString(&temp)) {
        out->parent_id.reset();
        return false;
      }
      else
        out->parent_id.reset(new std::string(temp));
    }
  }

  const base::Value* index_value = NULL;
  if (dict->GetWithoutPathExpansion("index", &index_value)) {
    {
      int temp;
      if (!index_value->GetAsInteger(&temp)) {
        out->index.reset();
        return false;
      }
      else
        out->index.reset(new int(temp));
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
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* destination_value = NULL;
  if (args.Get(1, &destination_value) &&
      !destination_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!destination_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Destination::Populate(*dictionary, &params->destination)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const BookmarkTreeNode& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace Move

namespace Update {

Params::Changes::Changes()
 {}

Params::Changes::~Changes() {}
Params::Changes::Changes(Changes&& rhs)
: title(std::move(rhs.title)),
url(std::move(rhs.url)){
}

Params::Changes& Params::Changes::operator=(Changes&& rhs)
{
title = std::move(rhs.title);
url = std::move(rhs.url);
return *this;
}

// static
bool Params::Changes::Populate(
    const base::Value& value, Changes* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        out->url.reset();
        return false;
      }
      else
        out->url.reset(new std::string(temp));
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
      if (!id_value->GetAsString(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* changes_value = NULL;
  if (args.Get(1, &changes_value) &&
      !changes_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!changes_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Changes::Populate(*dictionary, &params->changes)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const BookmarkTreeNode& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Remove

namespace RemoveTree {

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


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace RemoveTree

namespace Import {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Import

namespace Export {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Export

//
// Events
//

namespace OnCreated {

const char kEventName[] = "bookmarks.onCreated";

std::unique_ptr<base::ListValue> Create(const std::string& id, const BookmarkTreeNode& bookmark) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(id));

  create_results->Append((bookmark).ToValue());

  return create_results;
}

}  // namespace OnCreated

namespace OnRemoved {

const char kEventName[] = "bookmarks.onRemoved";

RemoveInfo::RemoveInfo()
: index(0) {}

RemoveInfo::~RemoveInfo() {}
RemoveInfo::RemoveInfo(RemoveInfo&& rhs)
: parent_id(std::move(rhs.parent_id)),
index(rhs.index),
node(std::move(rhs.node)){
}

RemoveInfo& RemoveInfo::operator=(RemoveInfo&& rhs)
{
parent_id = std::move(rhs.parent_id);
index = rhs.index;
node = std::move(rhs.node);
return *this;
}

std::unique_ptr<base::DictionaryValue> RemoveInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("parentId", std::make_unique<base::Value>(this->parent_id));

  to_value_result->SetWithoutPathExpansion("index", std::make_unique<base::Value>(this->index));

  to_value_result->SetWithoutPathExpansion("node", (this->node).ToValue());


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const std::string& id, const RemoveInfo& remove_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(id));

  create_results->Append((remove_info).ToValue());

  return create_results;
}

}  // namespace OnRemoved

namespace OnChanged {

const char kEventName[] = "bookmarks.onChanged";

ChangeInfo::ChangeInfo()
 {}

ChangeInfo::~ChangeInfo() {}
ChangeInfo::ChangeInfo(ChangeInfo&& rhs)
: title(std::move(rhs.title)),
url(std::move(rhs.url)){
}

ChangeInfo& ChangeInfo::operator=(ChangeInfo&& rhs)
{
title = std::move(rhs.title);
url = std::move(rhs.url);
return *this;
}

std::unique_ptr<base::DictionaryValue> ChangeInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }

  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const std::string& id, const ChangeInfo& change_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(id));

  create_results->Append((change_info).ToValue());

  return create_results;
}

}  // namespace OnChanged

namespace OnMoved {

const char kEventName[] = "bookmarks.onMoved";

MoveInfo::MoveInfo()
: index(0),
old_index(0) {}

MoveInfo::~MoveInfo() {}
MoveInfo::MoveInfo(MoveInfo&& rhs)
: parent_id(std::move(rhs.parent_id)),
index(rhs.index),
old_parent_id(std::move(rhs.old_parent_id)),
old_index(rhs.old_index){
}

MoveInfo& MoveInfo::operator=(MoveInfo&& rhs)
{
parent_id = std::move(rhs.parent_id);
index = rhs.index;
old_parent_id = std::move(rhs.old_parent_id);
old_index = rhs.old_index;
return *this;
}

std::unique_ptr<base::DictionaryValue> MoveInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("parentId", std::make_unique<base::Value>(this->parent_id));

  to_value_result->SetWithoutPathExpansion("index", std::make_unique<base::Value>(this->index));

  to_value_result->SetWithoutPathExpansion("oldParentId", std::make_unique<base::Value>(this->old_parent_id));

  to_value_result->SetWithoutPathExpansion("oldIndex", std::make_unique<base::Value>(this->old_index));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const std::string& id, const MoveInfo& move_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(id));

  create_results->Append((move_info).ToValue());

  return create_results;
}

}  // namespace OnMoved

namespace OnChildrenReordered {

const char kEventName[] = "bookmarks.onChildrenReordered";

ReorderInfo::ReorderInfo()
 {}

ReorderInfo::~ReorderInfo() {}
ReorderInfo::ReorderInfo(ReorderInfo&& rhs)
: child_ids(std::move(rhs.child_ids)){
}

ReorderInfo& ReorderInfo::operator=(ReorderInfo&& rhs)
{
child_ids = std::move(rhs.child_ids);
return *this;
}

std::unique_ptr<base::DictionaryValue> ReorderInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("childIds", json_schema_compiler::util::CreateValueFromArray(this->child_ids));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const std::string& id, const ReorderInfo& reorder_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(id));

  create_results->Append((reorder_info).ToValue());

  return create_results;
}

}  // namespace OnChildrenReordered

namespace OnImportBegan {

const char kEventName[] = "bookmarks.onImportBegan";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnImportBegan

namespace OnImportEnded {

const char kEventName[] = "bookmarks.onImportEnded";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnImportEnded

}  // namespace bookmarks
}  // namespace api
}  // namespace extensions

