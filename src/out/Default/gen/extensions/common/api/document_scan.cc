// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/document_scan.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/document_scan.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace document_scan {
//
// Types
//

ScanOptions::ScanOptions()
 {}

ScanOptions::~ScanOptions() {}
ScanOptions::ScanOptions(ScanOptions&& rhs)
: mime_types(std::move(rhs.mime_types)),
max_images(std::move(rhs.max_images)){
}

ScanOptions& ScanOptions::operator=(ScanOptions&& rhs)
{
mime_types = std::move(rhs.mime_types);
max_images = std::move(rhs.max_images);
return *this;
}

// static
bool ScanOptions::Populate(
    const base::Value& value, ScanOptions* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* mime_types_value = NULL;
  if (dict->GetWithoutPathExpansion("mimeTypes", &mime_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!mime_types_value->GetAsList(&list)) {
        return false;
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->mime_types)) {
          return false;
        }
      }
    }
  }

  const base::Value* max_images_value = NULL;
  if (dict->GetWithoutPathExpansion("maxImages", &max_images_value)) {
    {
      int temp;
      if (!max_images_value->GetAsInteger(&temp)) {
        out->max_images.reset();
        return false;
      }
      else
        out->max_images.reset(new int(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<ScanOptions> ScanOptions::FromValue(const base::Value& value) {
  std::unique_ptr<ScanOptions> out(new ScanOptions());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ScanOptions::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->mime_types.get()) {
    to_value_result->SetWithoutPathExpansion("mimeTypes", json_schema_compiler::util::CreateValueFromOptionalArray(this->mime_types));

  }
  if (this->max_images.get()) {
    to_value_result->SetWithoutPathExpansion("maxImages", std::make_unique<base::Value>(*this->max_images));

  }

  return to_value_result;
}


ScanResults::ScanResults()
 {}

ScanResults::~ScanResults() {}
ScanResults::ScanResults(ScanResults&& rhs)
: data_urls(std::move(rhs.data_urls)),
mime_type(std::move(rhs.mime_type)){
}

ScanResults& ScanResults::operator=(ScanResults&& rhs)
{
data_urls = std::move(rhs.data_urls);
mime_type = std::move(rhs.mime_type);
return *this;
}

// static
bool ScanResults::Populate(
    const base::Value& value, ScanResults* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* data_urls_value = NULL;
  if (!dict->GetWithoutPathExpansion("dataUrls", &data_urls_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!data_urls_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->data_urls)) {
        return false;
      }
    }
  }

  const base::Value* mime_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("mimeType", &mime_type_value)) {
    return false;
  }
  {
    if (!mime_type_value->GetAsString(&out->mime_type)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ScanResults> ScanResults::FromValue(const base::Value& value) {
  std::unique_ptr<ScanResults> out(new ScanResults());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ScanResults::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("dataUrls", json_schema_compiler::util::CreateValueFromArray(this->data_urls));

  to_value_result->SetWithoutPathExpansion("mimeType", std::make_unique<base::Value>(this->mime_type));


  return to_value_result;
}



//
// Functions
//

namespace Scan {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* options_value = NULL;
  if (args.Get(0, &options_value) &&
      !options_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!options_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!ScanOptions::Populate(*dictionary, &params->options)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const ScanResults& result) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((result).ToValue());

  return create_results;
}
}  // namespace Scan

}  // namespace document_scan
}  // namespace api
}  // namespace extensions

