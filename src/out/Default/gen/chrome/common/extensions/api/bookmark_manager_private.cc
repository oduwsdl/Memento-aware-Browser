// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/bookmark_manager_private.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/bookmark_manager_private.h"
#include <set>
#include <utility>
#include "chrome/common/extensions/api/bookmarks.h"


using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace bookmark_manager_private {
//
// Types
//

BookmarkNodeDataElement::BookmarkNodeDataElement()
 {}

BookmarkNodeDataElement::~BookmarkNodeDataElement() {}
BookmarkNodeDataElement::BookmarkNodeDataElement(BookmarkNodeDataElement&& rhs)
: id(std::move(rhs.id)),
parent_id(std::move(rhs.parent_id)),
title(std::move(rhs.title)),
url(std::move(rhs.url)),
children(std::move(rhs.children)){
}

BookmarkNodeDataElement& BookmarkNodeDataElement::operator=(BookmarkNodeDataElement&& rhs)
{
id = std::move(rhs.id);
parent_id = std::move(rhs.parent_id);
title = std::move(rhs.title);
url = std::move(rhs.url);
children = std::move(rhs.children);
return *this;
}

// static
bool BookmarkNodeDataElement::Populate(
    const base::Value& value, BookmarkNodeDataElement* out) {
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

  const base::Value* title_value = NULL;
  if (!dict->GetWithoutPathExpansion("title", &title_value)) {
    return false;
  }
  {
    if (!title_value->GetAsString(&out->title)) {
      return false;
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

  const base::Value* children_value = NULL;
  if (!dict->GetWithoutPathExpansion("children", &children_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!children_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->children)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<BookmarkNodeDataElement> BookmarkNodeDataElement::FromValue(const base::Value& value) {
  std::unique_ptr<BookmarkNodeDataElement> out(new BookmarkNodeDataElement());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> BookmarkNodeDataElement::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->id.get()) {
    to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(*this->id));

  }
  if (this->parent_id.get()) {
    to_value_result->SetWithoutPathExpansion("parentId", std::make_unique<base::Value>(*this->parent_id));

  }
  to_value_result->SetWithoutPathExpansion("title", std::make_unique<base::Value>(this->title));

  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  to_value_result->SetWithoutPathExpansion("children", json_schema_compiler::util::CreateValueFromArray(this->children));


  return to_value_result;
}


BookmarkNodeData::BookmarkNodeData()
: same_profile(false) {}

BookmarkNodeData::~BookmarkNodeData() {}
BookmarkNodeData::BookmarkNodeData(BookmarkNodeData&& rhs)
: same_profile(rhs.same_profile),
elements(std::move(rhs.elements)){
}

BookmarkNodeData& BookmarkNodeData::operator=(BookmarkNodeData&& rhs)
{
same_profile = rhs.same_profile;
elements = std::move(rhs.elements);
return *this;
}

// static
bool BookmarkNodeData::Populate(
    const base::Value& value, BookmarkNodeData* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* same_profile_value = NULL;
  if (!dict->GetWithoutPathExpansion("sameProfile", &same_profile_value)) {
    return false;
  }
  {
    if (!same_profile_value->GetAsBoolean(&out->same_profile)) {
      return false;
    }
  }

  const base::Value* elements_value = NULL;
  if (!dict->GetWithoutPathExpansion("elements", &elements_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!elements_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->elements)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<BookmarkNodeData> BookmarkNodeData::FromValue(const base::Value& value) {
  std::unique_ptr<BookmarkNodeData> out(new BookmarkNodeData());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> BookmarkNodeData::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("sameProfile", std::make_unique<base::Value>(this->same_profile));

  to_value_result->SetWithoutPathExpansion("elements", json_schema_compiler::util::CreateValueFromArray(this->elements));


  return to_value_result;
}



//
// Functions
//

namespace Copy {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_list_value = NULL;
  if (args.Get(0, &id_list_value) &&
      !id_list_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!id_list_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->id_list)) {
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
}  // namespace Copy

namespace Cut {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_list_value = NULL;
  if (args.Get(0, &id_list_value) &&
      !id_list_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!id_list_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->id_list)) {
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
}  // namespace Cut

namespace Paste {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* parent_id_value = NULL;
  if (args.Get(0, &parent_id_value) &&
      !parent_id_value->is_none()) {
    {
      if (!parent_id_value->GetAsString(&params->parent_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* selected_id_list_value = NULL;
  if (args.Get(1, &selected_id_list_value) &&
      !selected_id_list_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!selected_id_list_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &params->selected_id_list)) {
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
}  // namespace Paste

namespace CanPaste {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* parent_id_value = NULL;
  if (args.Get(0, &parent_id_value) &&
      !parent_id_value->is_none()) {
    {
      if (!parent_id_value->GetAsString(&params->parent_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(bool result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(result));

  return create_results;
}
}  // namespace CanPaste

namespace SortChildren {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* parent_id_value = NULL;
  if (args.Get(0, &parent_id_value) &&
      !parent_id_value->is_none()) {
    {
      if (!parent_id_value->GetAsString(&params->parent_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SortChildren

namespace StartDrag {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 5) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_list_value = NULL;
  if (args.Get(0, &id_list_value) &&
      !id_list_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!id_list_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->id_list)) {
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* drag_node_index_value = NULL;
  if (args.Get(1, &drag_node_index_value) &&
      !drag_node_index_value->is_none()) {
    {
      if (!drag_node_index_value->GetAsInteger(&params->drag_node_index)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* is_from_touch_value = NULL;
  if (args.Get(2, &is_from_touch_value) &&
      !is_from_touch_value->is_none()) {
    {
      if (!is_from_touch_value->GetAsBoolean(&params->is_from_touch)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* x_value = NULL;
  if (args.Get(3, &x_value) &&
      !x_value->is_none()) {
    {
      if (!x_value->GetAsInteger(&params->x)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* y_value = NULL;
  if (args.Get(4, &y_value) &&
      !y_value->is_none()) {
    {
      if (!y_value->GetAsInteger(&params->y)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace StartDrag

namespace Drop {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 1 || args.GetSize() > 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* parent_id_value = NULL;
  if (args.Get(0, &parent_id_value) &&
      !parent_id_value->is_none()) {
    {
      if (!parent_id_value->GetAsString(&params->parent_id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* index_value = NULL;
  if (args.Get(1, &index_value) &&
      !index_value->is_none()) {
    {
      int temp;
      if (!index_value->GetAsInteger(&temp)) {
        params->index.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->index.reset(new int(temp));
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace Drop

namespace GetSubtree {

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

  const base::Value* folders_only_value = NULL;
  if (args.Get(1, &folders_only_value) &&
      !folders_only_value->is_none()) {
    {
      if (!folders_only_value->GetAsBoolean(&params->folders_only)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<extensions::api::bookmarks::BookmarkTreeNode>& results) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(results));

  return create_results;
}
}  // namespace GetSubtree

namespace RemoveTrees {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_list_value = NULL;
  if (args.Get(0, &id_list_value) &&
      !id_list_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!id_list_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->id_list)) {
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
}  // namespace RemoveTrees

namespace Undo {

}  // namespace Undo

namespace Redo {

}  // namespace Redo

//
// Events
//

namespace OnDragEnter {

const char kEventName[] = "bookmarkManagerPrivate.onDragEnter";

std::unique_ptr<base::ListValue> Create(const BookmarkNodeData& bookmark_node_data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((bookmark_node_data).ToValue());

  return create_results;
}

}  // namespace OnDragEnter

namespace OnDragLeave {

const char kEventName[] = "bookmarkManagerPrivate.onDragLeave";

std::unique_ptr<base::ListValue> Create(const BookmarkNodeData& bookmark_node_data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((bookmark_node_data).ToValue());

  return create_results;
}

}  // namespace OnDragLeave

namespace OnDrop {

const char kEventName[] = "bookmarkManagerPrivate.onDrop";

std::unique_ptr<base::ListValue> Create(const BookmarkNodeData& bookmark_node_data) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((bookmark_node_data).ToValue());

  return create_results;
}

}  // namespace OnDrop

}  // namespace bookmark_manager_private
}  // namespace api
}  // namespace extensions

