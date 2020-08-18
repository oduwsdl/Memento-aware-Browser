// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/manifest_types.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/manifest_types.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace manifest_types {
//
// Types
//

ChromeSettingsOverrides::Search_provider::Search_provider()
: is_default(false) {}

ChromeSettingsOverrides::Search_provider::~Search_provider() {}
ChromeSettingsOverrides::Search_provider::Search_provider(Search_provider&& rhs)
: name(std::move(rhs.name)),
keyword(std::move(rhs.keyword)),
favicon_url(std::move(rhs.favicon_url)),
search_url(std::move(rhs.search_url)),
encoding(std::move(rhs.encoding)),
suggest_url(std::move(rhs.suggest_url)),
image_url(std::move(rhs.image_url)),
search_url_post_params(std::move(rhs.search_url_post_params)),
suggest_url_post_params(std::move(rhs.suggest_url_post_params)),
image_url_post_params(std::move(rhs.image_url_post_params)),
alternate_urls(std::move(rhs.alternate_urls)),
prepopulated_id(std::move(rhs.prepopulated_id)),
is_default(rhs.is_default){
}

ChromeSettingsOverrides::Search_provider& ChromeSettingsOverrides::Search_provider::operator=(Search_provider&& rhs)
{
name = std::move(rhs.name);
keyword = std::move(rhs.keyword);
favicon_url = std::move(rhs.favicon_url);
search_url = std::move(rhs.search_url);
encoding = std::move(rhs.encoding);
suggest_url = std::move(rhs.suggest_url);
image_url = std::move(rhs.image_url);
search_url_post_params = std::move(rhs.search_url_post_params);
suggest_url_post_params = std::move(rhs.suggest_url_post_params);
image_url_post_params = std::move(rhs.image_url_post_params);
alternate_urls = std::move(rhs.alternate_urls);
prepopulated_id = std::move(rhs.prepopulated_id);
is_default = rhs.is_default;
return *this;
}

// static
bool ChromeSettingsOverrides::Search_provider::Populate(
    const base::Value& value, Search_provider* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("name");
  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'name': expected name, got " + std::string(base::Value::GetTypeName(name_value->type()))));
        out->name.reset();
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  keys.insert("keyword");
  const base::Value* keyword_value = NULL;
  if (dict->GetWithoutPathExpansion("keyword", &keyword_value)) {
    {
      std::string temp;
      if (!keyword_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'keyword': expected keyword, got " + std::string(base::Value::GetTypeName(keyword_value->type()))));
        out->keyword.reset();
      }
      else
        out->keyword.reset(new std::string(temp));
    }
  }

  keys.insert("favicon_url");
  const base::Value* favicon_url_value = NULL;
  if (dict->GetWithoutPathExpansion("favicon_url", &favicon_url_value)) {
    {
      std::string temp;
      if (!favicon_url_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'favicon_url': expected favicon_url, got " + std::string(base::Value::GetTypeName(favicon_url_value->type()))));
        out->favicon_url.reset();
      }
      else
        out->favicon_url.reset(new std::string(temp));
    }
  }

  keys.insert("search_url");
  const base::Value* search_url_value = NULL;
  if (!dict->GetWithoutPathExpansion("search_url", &search_url_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'search_url' is required"));
    return false;
  }
  {
    if (!search_url_value->GetAsString(&out->search_url)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'search_url': expected search_url, got " + std::string(base::Value::GetTypeName(search_url_value->type()))));
      return false;
    }
  }

  keys.insert("encoding");
  const base::Value* encoding_value = NULL;
  if (dict->GetWithoutPathExpansion("encoding", &encoding_value)) {
    {
      std::string temp;
      if (!encoding_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'encoding': expected encoding, got " + std::string(base::Value::GetTypeName(encoding_value->type()))));
        out->encoding.reset();
      }
      else
        out->encoding.reset(new std::string(temp));
    }
  }

  keys.insert("suggest_url");
  const base::Value* suggest_url_value = NULL;
  if (dict->GetWithoutPathExpansion("suggest_url", &suggest_url_value)) {
    {
      std::string temp;
      if (!suggest_url_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'suggest_url': expected suggest_url, got " + std::string(base::Value::GetTypeName(suggest_url_value->type()))));
        out->suggest_url.reset();
      }
      else
        out->suggest_url.reset(new std::string(temp));
    }
  }

  keys.insert("image_url");
  const base::Value* image_url_value = NULL;
  if (dict->GetWithoutPathExpansion("image_url", &image_url_value)) {
    {
      std::string temp;
      if (!image_url_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'image_url': expected image_url, got " + std::string(base::Value::GetTypeName(image_url_value->type()))));
        out->image_url.reset();
      }
      else
        out->image_url.reset(new std::string(temp));
    }
  }

  keys.insert("search_url_post_params");
  const base::Value* search_url_post_params_value = NULL;
  if (dict->GetWithoutPathExpansion("search_url_post_params", &search_url_post_params_value)) {
    {
      std::string temp;
      if (!search_url_post_params_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'search_url_post_params': expected search_url_post_params, got " + std::string(base::Value::GetTypeName(search_url_post_params_value->type()))));
        out->search_url_post_params.reset();
      }
      else
        out->search_url_post_params.reset(new std::string(temp));
    }
  }

  keys.insert("suggest_url_post_params");
  const base::Value* suggest_url_post_params_value = NULL;
  if (dict->GetWithoutPathExpansion("suggest_url_post_params", &suggest_url_post_params_value)) {
    {
      std::string temp;
      if (!suggest_url_post_params_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'suggest_url_post_params': expected suggest_url_post_params, got " + std::string(base::Value::GetTypeName(suggest_url_post_params_value->type()))));
        out->suggest_url_post_params.reset();
      }
      else
        out->suggest_url_post_params.reset(new std::string(temp));
    }
  }

  keys.insert("image_url_post_params");
  const base::Value* image_url_post_params_value = NULL;
  if (dict->GetWithoutPathExpansion("image_url_post_params", &image_url_post_params_value)) {
    {
      std::string temp;
      if (!image_url_post_params_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'image_url_post_params': expected image_url_post_params, got " + std::string(base::Value::GetTypeName(image_url_post_params_value->type()))));
        out->image_url_post_params.reset();
      }
      else
        out->image_url_post_params.reset(new std::string(temp));
    }
  }

  keys.insert("alternate_urls");
  const base::Value* alternate_urls_value = NULL;
  if (dict->GetWithoutPathExpansion("alternate_urls", &alternate_urls_value)) {
    {
      const base::ListValue* list = NULL;
      if (!alternate_urls_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'alternate_urls': expected list, got " + std::string(base::Value::GetTypeName(alternate_urls_value->type()))));
        out->alternate_urls.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->alternate_urls, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'search_provider'"));
          out->alternate_urls.reset();
        }
      }
    }
  }

  keys.insert("prepopulated_id");
  const base::Value* prepopulated_id_value = NULL;
  if (dict->GetWithoutPathExpansion("prepopulated_id", &prepopulated_id_value)) {
    {
      int temp;
      if (!prepopulated_id_value->GetAsInteger(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'prepopulated_id': expected prepopulated_id, got " + std::string(base::Value::GetTypeName(prepopulated_id_value->type()))));
        out->prepopulated_id.reset();
      }
      else
        out->prepopulated_id.reset(new int(temp));
    }
  }

  keys.insert("is_default");
  const base::Value* is_default_value = NULL;
  if (!dict->GetWithoutPathExpansion("is_default", &is_default_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'is_default' is required"));
    return false;
  }
  {
    if (!is_default_value->GetAsBoolean(&out->is_default)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'is_default': expected is_default, got " + std::string(base::Value::GetTypeName(is_default_value->type()))));
      return false;
    }
  }

  for (base::DictionaryValue::Iterator it(*dict); !it.IsAtEnd(); it.Advance()) {
    if (!keys.count(it.key())) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("found unexpected key '" + it.key() + "'"));
    }
  }
  return true;
}

std::unique_ptr<base::DictionaryValue> ChromeSettingsOverrides::Search_provider::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->name.get()) {
    to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(*this->name));

  }
  if (this->keyword.get()) {
    to_value_result->SetWithoutPathExpansion("keyword", std::make_unique<base::Value>(*this->keyword));

  }
  if (this->favicon_url.get()) {
    to_value_result->SetWithoutPathExpansion("favicon_url", std::make_unique<base::Value>(*this->favicon_url));

  }
  to_value_result->SetWithoutPathExpansion("search_url", std::make_unique<base::Value>(this->search_url));

  if (this->encoding.get()) {
    to_value_result->SetWithoutPathExpansion("encoding", std::make_unique<base::Value>(*this->encoding));

  }
  if (this->suggest_url.get()) {
    to_value_result->SetWithoutPathExpansion("suggest_url", std::make_unique<base::Value>(*this->suggest_url));

  }
  if (this->image_url.get()) {
    to_value_result->SetWithoutPathExpansion("image_url", std::make_unique<base::Value>(*this->image_url));

  }
  if (this->search_url_post_params.get()) {
    to_value_result->SetWithoutPathExpansion("search_url_post_params", std::make_unique<base::Value>(*this->search_url_post_params));

  }
  if (this->suggest_url_post_params.get()) {
    to_value_result->SetWithoutPathExpansion("suggest_url_post_params", std::make_unique<base::Value>(*this->suggest_url_post_params));

  }
  if (this->image_url_post_params.get()) {
    to_value_result->SetWithoutPathExpansion("image_url_post_params", std::make_unique<base::Value>(*this->image_url_post_params));

  }
  if (this->alternate_urls.get()) {
    to_value_result->SetWithoutPathExpansion("alternate_urls", json_schema_compiler::util::CreateValueFromOptionalArray(this->alternate_urls));

  }
  if (this->prepopulated_id.get()) {
    to_value_result->SetWithoutPathExpansion("prepopulated_id", std::make_unique<base::Value>(*this->prepopulated_id));

  }
  to_value_result->SetWithoutPathExpansion("is_default", std::make_unique<base::Value>(this->is_default));


  return to_value_result;
}



ChromeSettingsOverrides::ChromeSettingsOverrides()
 {}

ChromeSettingsOverrides::~ChromeSettingsOverrides() {}
ChromeSettingsOverrides::ChromeSettingsOverrides(ChromeSettingsOverrides&& rhs)
: homepage(std::move(rhs.homepage)),
search_provider(std::move(rhs.search_provider)),
startup_pages(std::move(rhs.startup_pages)){
}

ChromeSettingsOverrides& ChromeSettingsOverrides::operator=(ChromeSettingsOverrides&& rhs)
{
homepage = std::move(rhs.homepage);
search_provider = std::move(rhs.search_provider);
startup_pages = std::move(rhs.startup_pages);
return *this;
}

// static
bool ChromeSettingsOverrides::Populate(
    const base::Value& value, ChromeSettingsOverrides* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("homepage");
  const base::Value* homepage_value = NULL;
  if (dict->GetWithoutPathExpansion("homepage", &homepage_value)) {
    {
      std::string temp;
      if (!homepage_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'homepage': expected homepage, got " + std::string(base::Value::GetTypeName(homepage_value->type()))));
        out->homepage.reset();
      }
      else
        out->homepage.reset(new std::string(temp));
    }
  }

  keys.insert("search_provider");
  const base::Value* search_provider_value = NULL;
  if (dict->GetWithoutPathExpansion("search_provider", &search_provider_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!search_provider_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'search_provider': expected dictionary, got " + std::string(base::Value::GetTypeName(search_provider_value->type()))));
      }
      else {
        std::unique_ptr<Search_provider> temp(new Search_provider());
        if (!Search_provider::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->search_provider = std::move(temp);
      }
    }
  }

  keys.insert("startup_pages");
  const base::Value* startup_pages_value = NULL;
  if (dict->GetWithoutPathExpansion("startup_pages", &startup_pages_value)) {
    {
      const base::ListValue* list = NULL;
      if (!startup_pages_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'startup_pages': expected list, got " + std::string(base::Value::GetTypeName(startup_pages_value->type()))));
        out->startup_pages.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->startup_pages, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'ChromeSettingsOverrides'"));
          out->startup_pages.reset();
        }
      }
    }
  }

  for (base::DictionaryValue::Iterator it(*dict); !it.IsAtEnd(); it.Advance()) {
    if (!keys.count(it.key())) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("found unexpected key '" + it.key() + "'"));
    }
  }
  return true;
}

// static
std::unique_ptr<ChromeSettingsOverrides> ChromeSettingsOverrides::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<ChromeSettingsOverrides> out(new ChromeSettingsOverrides());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ChromeSettingsOverrides::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->homepage.get()) {
    to_value_result->SetWithoutPathExpansion("homepage", std::make_unique<base::Value>(*this->homepage));

  }
  if (this->search_provider.get()) {
    to_value_result->SetWithoutPathExpansion("search_provider", (this->search_provider)->ToValue());

  }
  if (this->startup_pages.get()) {
    to_value_result->SetWithoutPathExpansion("startup_pages", json_schema_compiler::util::CreateValueFromOptionalArray(this->startup_pages));

  }

  return to_value_result;
}


const char* ToString(FileSystemProviderSource enum_param) {
  switch (enum_param) {
    case FILE_SYSTEM_PROVIDER_SOURCE_FILE:
      return "file";
    case FILE_SYSTEM_PROVIDER_SOURCE_DEVICE:
      return "device";
    case FILE_SYSTEM_PROVIDER_SOURCE_NETWORK:
      return "network";
    case FILE_SYSTEM_PROVIDER_SOURCE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

FileSystemProviderSource ParseFileSystemProviderSource(const std::string& enum_string) {
  if (enum_string == "file")
    return FILE_SYSTEM_PROVIDER_SOURCE_FILE;
  if (enum_string == "device")
    return FILE_SYSTEM_PROVIDER_SOURCE_DEVICE;
  if (enum_string == "network")
    return FILE_SYSTEM_PROVIDER_SOURCE_NETWORK;
  return FILE_SYSTEM_PROVIDER_SOURCE_NONE;
}


FileSystemProviderCapabilities::FileSystemProviderCapabilities()
: source(FILE_SYSTEM_PROVIDER_SOURCE_NONE) {}

FileSystemProviderCapabilities::~FileSystemProviderCapabilities() {}
FileSystemProviderCapabilities::FileSystemProviderCapabilities(FileSystemProviderCapabilities&& rhs)
: configurable(std::move(rhs.configurable)),
multiple_mounts(std::move(rhs.multiple_mounts)),
watchable(std::move(rhs.watchable)),
source(rhs.source){
}

FileSystemProviderCapabilities& FileSystemProviderCapabilities::operator=(FileSystemProviderCapabilities&& rhs)
{
configurable = std::move(rhs.configurable);
multiple_mounts = std::move(rhs.multiple_mounts);
watchable = std::move(rhs.watchable);
source = rhs.source;
return *this;
}

// static
bool FileSystemProviderCapabilities::Populate(
    const base::Value& value, FileSystemProviderCapabilities* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("configurable");
  const base::Value* configurable_value = NULL;
  if (dict->GetWithoutPathExpansion("configurable", &configurable_value)) {
    {
      bool temp;
      if (!configurable_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'configurable': expected configurable, got " + std::string(base::Value::GetTypeName(configurable_value->type()))));
        out->configurable.reset();
      }
      else
        out->configurable.reset(new bool(temp));
    }
  }

  keys.insert("multiple_mounts");
  const base::Value* multiple_mounts_value = NULL;
  if (dict->GetWithoutPathExpansion("multiple_mounts", &multiple_mounts_value)) {
    {
      bool temp;
      if (!multiple_mounts_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'multiple_mounts': expected multiple_mounts, got " + std::string(base::Value::GetTypeName(multiple_mounts_value->type()))));
        out->multiple_mounts.reset();
      }
      else
        out->multiple_mounts.reset(new bool(temp));
    }
  }

  keys.insert("watchable");
  const base::Value* watchable_value = NULL;
  if (dict->GetWithoutPathExpansion("watchable", &watchable_value)) {
    {
      bool temp;
      if (!watchable_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'watchable': expected watchable, got " + std::string(base::Value::GetTypeName(watchable_value->type()))));
        out->watchable.reset();
      }
      else
        out->watchable.reset(new bool(temp));
    }
  }

  keys.insert("source");
  const base::Value* source_value = NULL;
  if (!dict->GetWithoutPathExpansion("source", &source_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'source' is required"));
    return false;
  }
  {
    std::string file_system_provider_source_as_string;
    if (!source_value->GetAsString(&file_system_provider_source_as_string)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'FileSystemProviderSource': expected string, got " + std::string(base::Value::GetTypeName(source_value->type()))));
      return false;
    }
    out->source = ParseFileSystemProviderSource(file_system_provider_source_as_string);
    if (out->source == FILE_SYSTEM_PROVIDER_SOURCE_NONE) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'FileSystemProviderSource': expected \"file\" or \"device\" or \"network\", got \"" + file_system_provider_source_as_string + "\""));
      return false;
    }
  }

  for (base::DictionaryValue::Iterator it(*dict); !it.IsAtEnd(); it.Advance()) {
    if (!keys.count(it.key())) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("found unexpected key '" + it.key() + "'"));
    }
  }
  return true;
}

// static
std::unique_ptr<FileSystemProviderCapabilities> FileSystemProviderCapabilities::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<FileSystemProviderCapabilities> out(new FileSystemProviderCapabilities());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FileSystemProviderCapabilities::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->configurable.get()) {
    to_value_result->SetWithoutPathExpansion("configurable", std::make_unique<base::Value>(*this->configurable));

  }
  if (this->multiple_mounts.get()) {
    to_value_result->SetWithoutPathExpansion("multiple_mounts", std::make_unique<base::Value>(*this->multiple_mounts));

  }
  if (this->watchable.get()) {
    to_value_result->SetWithoutPathExpansion("watchable", std::make_unique<base::Value>(*this->watchable));

  }
  to_value_result->SetWithoutPathExpansion("source", std::make_unique<base::Value>(manifest_types::ToString(this->source)));


  return to_value_result;
}



}  // namespace manifest_types
}  // namespace api
}  // namespace extensions

