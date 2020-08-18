// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/clipboard.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/clipboard.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace clipboard {
//
// Types
//

const char* ToString(ImageType enum_param) {
  switch (enum_param) {
    case IMAGE_TYPE_PNG:
      return "png";
    case IMAGE_TYPE_JPEG:
      return "jpeg";
    case IMAGE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ImageType ParseImageType(const std::string& enum_string) {
  if (enum_string == "png")
    return IMAGE_TYPE_PNG;
  if (enum_string == "jpeg")
    return IMAGE_TYPE_JPEG;
  return IMAGE_TYPE_NONE;
}


const char* ToString(DataItemType enum_param) {
  switch (enum_param) {
    case DATA_ITEM_TYPE_TEXTPLAIN:
      return "textPlain";
    case DATA_ITEM_TYPE_TEXTHTML:
      return "textHtml";
    case DATA_ITEM_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DataItemType ParseDataItemType(const std::string& enum_string) {
  if (enum_string == "textPlain")
    return DATA_ITEM_TYPE_TEXTPLAIN;
  if (enum_string == "textHtml")
    return DATA_ITEM_TYPE_TEXTHTML;
  return DATA_ITEM_TYPE_NONE;
}


AdditionalDataItem::AdditionalDataItem()
: type(DATA_ITEM_TYPE_NONE) {}

AdditionalDataItem::~AdditionalDataItem() {}
AdditionalDataItem::AdditionalDataItem(AdditionalDataItem&& rhs)
: type(rhs.type),
data(std::move(rhs.data)){
}

AdditionalDataItem& AdditionalDataItem::operator=(AdditionalDataItem&& rhs)
{
type = rhs.type;
data = std::move(rhs.data);
return *this;
}

// static
bool AdditionalDataItem::Populate(
    const base::Value& value, AdditionalDataItem* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    return false;
  }
  {
    std::string data_item_type_as_string;
    if (!type_value->GetAsString(&data_item_type_as_string)) {
      return false;
    }
    out->type = ParseDataItemType(data_item_type_as_string);
    if (out->type == DATA_ITEM_TYPE_NONE) {
      return false;
    }
  }

  const base::Value* data_value = NULL;
  if (!dict->GetWithoutPathExpansion("data", &data_value)) {
    return false;
  }
  {
    if (!data_value->GetAsString(&out->data)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<AdditionalDataItem> AdditionalDataItem::FromValue(const base::Value& value) {
  std::unique_ptr<AdditionalDataItem> out(new AdditionalDataItem());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AdditionalDataItem::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(clipboard::ToString(this->type)));

  to_value_result->SetWithoutPathExpansion("data", std::make_unique<base::Value>(this->data));


  return to_value_result;
}



//
// Functions
//

namespace SetImageData {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* image_data_value = NULL;
  if (args.Get(0, &image_data_value) &&
      !image_data_value->is_none()) {
    {
      if (!image_data_value->is_blob()) {
        return std::unique_ptr<Params>();
      }
      else {
        params->image_data = image_data_value->GetBlob();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* type_value = NULL;
  if (args.Get(1, &type_value) &&
      !type_value->is_none()) {
    {
      std::string image_type_as_string;
      if (!type_value->GetAsString(&image_type_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->type = ParseImageType(image_type_as_string);
      if (params->type == IMAGE_TYPE_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* additional_items_value = NULL;
  if (args.Get(2, &additional_items_value) &&
      !additional_items_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!additional_items_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &params->additional_items)) {
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
}  // namespace SetImageData

//
// Events
//

namespace OnClipboardDataChanged {

const char kEventName[] = "clipboard.onClipboardDataChanged";

std::unique_ptr<base::ListValue> Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}

}  // namespace OnClipboardDataChanged

}  // namespace clipboard
}  // namespace api
}  // namespace extensions

