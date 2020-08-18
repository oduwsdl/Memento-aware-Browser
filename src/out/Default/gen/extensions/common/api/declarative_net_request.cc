// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/declarative_net_request.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/declarative_net_request.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace declarative_net_request {
//
// Properties
//

const int MAX_NUMBER_OF_RULES = 30000;

const int MAX_NUMBER_OF_DYNAMIC_RULES = 5000;

const int GETMATCHEDRULES_QUOTA_INTERVAL = 10;

const int MAX_GETMATCHEDRULES_CALLS_PER_INTERVAL = 20;

const int MAX_NUMBER_OF_REGEX_RULES = 1000;

const int MAX_NUMBER_OF_STATIC_RULESETS = 10;

const char DYNAMIC_RULESET_ID[] = "_dynamic";

//
// Types
//

const char* ToString(ResourceType enum_param) {
  switch (enum_param) {
    case RESOURCE_TYPE_MAIN_FRAME:
      return "main_frame";
    case RESOURCE_TYPE_SUB_FRAME:
      return "sub_frame";
    case RESOURCE_TYPE_STYLESHEET:
      return "stylesheet";
    case RESOURCE_TYPE_SCRIPT:
      return "script";
    case RESOURCE_TYPE_IMAGE:
      return "image";
    case RESOURCE_TYPE_FONT:
      return "font";
    case RESOURCE_TYPE_OBJECT:
      return "object";
    case RESOURCE_TYPE_XMLHTTPREQUEST:
      return "xmlhttprequest";
    case RESOURCE_TYPE_PING:
      return "ping";
    case RESOURCE_TYPE_CSP_REPORT:
      return "csp_report";
    case RESOURCE_TYPE_MEDIA:
      return "media";
    case RESOURCE_TYPE_WEBSOCKET:
      return "websocket";
    case RESOURCE_TYPE_OTHER:
      return "other";
    case RESOURCE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ResourceType ParseResourceType(const std::string& enum_string) {
  if (enum_string == "main_frame")
    return RESOURCE_TYPE_MAIN_FRAME;
  if (enum_string == "sub_frame")
    return RESOURCE_TYPE_SUB_FRAME;
  if (enum_string == "stylesheet")
    return RESOURCE_TYPE_STYLESHEET;
  if (enum_string == "script")
    return RESOURCE_TYPE_SCRIPT;
  if (enum_string == "image")
    return RESOURCE_TYPE_IMAGE;
  if (enum_string == "font")
    return RESOURCE_TYPE_FONT;
  if (enum_string == "object")
    return RESOURCE_TYPE_OBJECT;
  if (enum_string == "xmlhttprequest")
    return RESOURCE_TYPE_XMLHTTPREQUEST;
  if (enum_string == "ping")
    return RESOURCE_TYPE_PING;
  if (enum_string == "csp_report")
    return RESOURCE_TYPE_CSP_REPORT;
  if (enum_string == "media")
    return RESOURCE_TYPE_MEDIA;
  if (enum_string == "websocket")
    return RESOURCE_TYPE_WEBSOCKET;
  if (enum_string == "other")
    return RESOURCE_TYPE_OTHER;
  return RESOURCE_TYPE_NONE;
}


const char* ToString(DomainType enum_param) {
  switch (enum_param) {
    case DOMAIN_TYPE_FIRSTPARTY:
      return "firstParty";
    case DOMAIN_TYPE_THIRDPARTY:
      return "thirdParty";
    case DOMAIN_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DomainType ParseDomainType(const std::string& enum_string) {
  if (enum_string == "firstParty")
    return DOMAIN_TYPE_FIRSTPARTY;
  if (enum_string == "thirdParty")
    return DOMAIN_TYPE_THIRDPARTY;
  return DOMAIN_TYPE_NONE;
}


const char* ToString(HeaderOperation enum_param) {
  switch (enum_param) {
    case HEADER_OPERATION_APPEND:
      return "append";
    case HEADER_OPERATION_SET:
      return "set";
    case HEADER_OPERATION_REMOVE:
      return "remove";
    case HEADER_OPERATION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

HeaderOperation ParseHeaderOperation(const std::string& enum_string) {
  if (enum_string == "append")
    return HEADER_OPERATION_APPEND;
  if (enum_string == "set")
    return HEADER_OPERATION_SET;
  if (enum_string == "remove")
    return HEADER_OPERATION_REMOVE;
  return HEADER_OPERATION_NONE;
}


const char* ToString(RuleActionType enum_param) {
  switch (enum_param) {
    case RULE_ACTION_TYPE_BLOCK:
      return "block";
    case RULE_ACTION_TYPE_REDIRECT:
      return "redirect";
    case RULE_ACTION_TYPE_ALLOW:
      return "allow";
    case RULE_ACTION_TYPE_UPGRADESCHEME:
      return "upgradeScheme";
    case RULE_ACTION_TYPE_MODIFYHEADERS:
      return "modifyHeaders";
    case RULE_ACTION_TYPE_ALLOWALLREQUESTS:
      return "allowAllRequests";
    case RULE_ACTION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

RuleActionType ParseRuleActionType(const std::string& enum_string) {
  if (enum_string == "block")
    return RULE_ACTION_TYPE_BLOCK;
  if (enum_string == "redirect")
    return RULE_ACTION_TYPE_REDIRECT;
  if (enum_string == "allow")
    return RULE_ACTION_TYPE_ALLOW;
  if (enum_string == "upgradeScheme")
    return RULE_ACTION_TYPE_UPGRADESCHEME;
  if (enum_string == "modifyHeaders")
    return RULE_ACTION_TYPE_MODIFYHEADERS;
  if (enum_string == "allowAllRequests")
    return RULE_ACTION_TYPE_ALLOWALLREQUESTS;
  return RULE_ACTION_TYPE_NONE;
}


Ruleset::Ruleset()
: enabled(false) {}

Ruleset::~Ruleset() {}
Ruleset::Ruleset(Ruleset&& rhs)
: id(std::move(rhs.id)),
path(std::move(rhs.path)),
enabled(rhs.enabled){
}

Ruleset& Ruleset::operator=(Ruleset&& rhs)
{
id = std::move(rhs.id);
path = std::move(rhs.path);
enabled = rhs.enabled;
return *this;
}

// static
bool Ruleset::Populate(
    const base::Value& value, Ruleset* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("id");
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'id' is required"));
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'id': expected id, got " + std::string(base::Value::GetTypeName(id_value->type()))));
      return false;
    }
  }

  keys.insert("path");
  const base::Value* path_value = NULL;
  if (!dict->GetWithoutPathExpansion("path", &path_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'path' is required"));
    return false;
  }
  {
    if (!path_value->GetAsString(&out->path)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'path': expected path, got " + std::string(base::Value::GetTypeName(path_value->type()))));
      return false;
    }
  }

  keys.insert("enabled");
  const base::Value* enabled_value = NULL;
  if (!dict->GetWithoutPathExpansion("enabled", &enabled_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'enabled' is required"));
    return false;
  }
  {
    if (!enabled_value->GetAsBoolean(&out->enabled)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'enabled': expected enabled, got " + std::string(base::Value::GetTypeName(enabled_value->type()))));
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
std::unique_ptr<Ruleset> Ruleset::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<Ruleset> out(new Ruleset());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Ruleset::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(this->path));

  to_value_result->SetWithoutPathExpansion("enabled", std::make_unique<base::Value>(this->enabled));


  return to_value_result;
}


QueryKeyValue::QueryKeyValue()
 {}

QueryKeyValue::~QueryKeyValue() {}
QueryKeyValue::QueryKeyValue(QueryKeyValue&& rhs)
: key(std::move(rhs.key)),
value(std::move(rhs.value)){
}

QueryKeyValue& QueryKeyValue::operator=(QueryKeyValue&& rhs)
{
key = std::move(rhs.key);
value = std::move(rhs.value);
return *this;
}

// static
bool QueryKeyValue::Populate(
    const base::Value& value, QueryKeyValue* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("key");
  const base::Value* key_value = NULL;
  if (!dict->GetWithoutPathExpansion("key", &key_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'key' is required"));
    return false;
  }
  {
    if (!key_value->GetAsString(&out->key)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'key': expected key, got " + std::string(base::Value::GetTypeName(key_value->type()))));
      return false;
    }
  }

  keys.insert("value");
  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'value' is required"));
    return false;
  }
  {
    if (!value_value->GetAsString(&out->value)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'value': expected value, got " + std::string(base::Value::GetTypeName(value_value->type()))));
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
std::unique_ptr<QueryKeyValue> QueryKeyValue::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<QueryKeyValue> out(new QueryKeyValue());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> QueryKeyValue::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("key", std::make_unique<base::Value>(this->key));

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));


  return to_value_result;
}


QueryTransform::QueryTransform()
 {}

QueryTransform::~QueryTransform() {}
QueryTransform::QueryTransform(QueryTransform&& rhs)
: remove_params(std::move(rhs.remove_params)),
add_or_replace_params(std::move(rhs.add_or_replace_params)){
}

QueryTransform& QueryTransform::operator=(QueryTransform&& rhs)
{
remove_params = std::move(rhs.remove_params);
add_or_replace_params = std::move(rhs.add_or_replace_params);
return *this;
}

// static
bool QueryTransform::Populate(
    const base::Value& value, QueryTransform* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("removeParams");
  const base::Value* remove_params_value = NULL;
  if (dict->GetWithoutPathExpansion("removeParams", &remove_params_value)) {
    {
      const base::ListValue* list = NULL;
      if (!remove_params_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'removeParams': expected list, got " + std::string(base::Value::GetTypeName(remove_params_value->type()))));
        out->remove_params.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->remove_params, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'QueryTransform'"));
          out->remove_params.reset();
        }
      }
    }
  }

  keys.insert("addOrReplaceParams");
  const base::Value* add_or_replace_params_value = NULL;
  if (dict->GetWithoutPathExpansion("addOrReplaceParams", &add_or_replace_params_value)) {
    {
      const base::ListValue* list = NULL;
      if (!add_or_replace_params_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'addOrReplaceParams': expected list, got " + std::string(base::Value::GetTypeName(add_or_replace_params_value->type()))));
        out->add_or_replace_params.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->add_or_replace_params, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'QueryTransform'"));
          out->add_or_replace_params.reset();
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
std::unique_ptr<QueryTransform> QueryTransform::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<QueryTransform> out(new QueryTransform());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> QueryTransform::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->remove_params.get()) {
    to_value_result->SetWithoutPathExpansion("removeParams", json_schema_compiler::util::CreateValueFromOptionalArray(this->remove_params));

  }
  if (this->add_or_replace_params.get()) {
    to_value_result->SetWithoutPathExpansion("addOrReplaceParams", json_schema_compiler::util::CreateValueFromOptionalArray(this->add_or_replace_params));

  }

  return to_value_result;
}


URLTransform::URLTransform()
 {}

URLTransform::~URLTransform() {}
URLTransform::URLTransform(URLTransform&& rhs)
: scheme(std::move(rhs.scheme)),
host(std::move(rhs.host)),
port(std::move(rhs.port)),
path(std::move(rhs.path)),
query(std::move(rhs.query)),
query_transform(std::move(rhs.query_transform)),
fragment(std::move(rhs.fragment)),
username(std::move(rhs.username)),
password(std::move(rhs.password)){
}

URLTransform& URLTransform::operator=(URLTransform&& rhs)
{
scheme = std::move(rhs.scheme);
host = std::move(rhs.host);
port = std::move(rhs.port);
path = std::move(rhs.path);
query = std::move(rhs.query);
query_transform = std::move(rhs.query_transform);
fragment = std::move(rhs.fragment);
username = std::move(rhs.username);
password = std::move(rhs.password);
return *this;
}

// static
bool URLTransform::Populate(
    const base::Value& value, URLTransform* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("scheme");
  const base::Value* scheme_value = NULL;
  if (dict->GetWithoutPathExpansion("scheme", &scheme_value)) {
    {
      std::string temp;
      if (!scheme_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'scheme': expected scheme, got " + std::string(base::Value::GetTypeName(scheme_value->type()))));
        out->scheme.reset();
      }
      else
        out->scheme.reset(new std::string(temp));
    }
  }

  keys.insert("host");
  const base::Value* host_value = NULL;
  if (dict->GetWithoutPathExpansion("host", &host_value)) {
    {
      std::string temp;
      if (!host_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'host': expected host, got " + std::string(base::Value::GetTypeName(host_value->type()))));
        out->host.reset();
      }
      else
        out->host.reset(new std::string(temp));
    }
  }

  keys.insert("port");
  const base::Value* port_value = NULL;
  if (dict->GetWithoutPathExpansion("port", &port_value)) {
    {
      std::string temp;
      if (!port_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'port': expected port, got " + std::string(base::Value::GetTypeName(port_value->type()))));
        out->port.reset();
      }
      else
        out->port.reset(new std::string(temp));
    }
  }

  keys.insert("path");
  const base::Value* path_value = NULL;
  if (dict->GetWithoutPathExpansion("path", &path_value)) {
    {
      std::string temp;
      if (!path_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'path': expected path, got " + std::string(base::Value::GetTypeName(path_value->type()))));
        out->path.reset();
      }
      else
        out->path.reset(new std::string(temp));
    }
  }

  keys.insert("query");
  const base::Value* query_value = NULL;
  if (dict->GetWithoutPathExpansion("query", &query_value)) {
    {
      std::string temp;
      if (!query_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'query': expected query, got " + std::string(base::Value::GetTypeName(query_value->type()))));
        out->query.reset();
      }
      else
        out->query.reset(new std::string(temp));
    }
  }

  keys.insert("queryTransform");
  const base::Value* query_transform_value = NULL;
  if (dict->GetWithoutPathExpansion("queryTransform", &query_transform_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!query_transform_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'queryTransform': expected dictionary, got " + std::string(base::Value::GetTypeName(query_transform_value->type()))));
      }
      else {
        std::unique_ptr<QueryTransform> temp(new QueryTransform());
        if (!QueryTransform::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->query_transform = std::move(temp);
      }
    }
  }

  keys.insert("fragment");
  const base::Value* fragment_value = NULL;
  if (dict->GetWithoutPathExpansion("fragment", &fragment_value)) {
    {
      std::string temp;
      if (!fragment_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'fragment': expected fragment, got " + std::string(base::Value::GetTypeName(fragment_value->type()))));
        out->fragment.reset();
      }
      else
        out->fragment.reset(new std::string(temp));
    }
  }

  keys.insert("username");
  const base::Value* username_value = NULL;
  if (dict->GetWithoutPathExpansion("username", &username_value)) {
    {
      std::string temp;
      if (!username_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'username': expected username, got " + std::string(base::Value::GetTypeName(username_value->type()))));
        out->username.reset();
      }
      else
        out->username.reset(new std::string(temp));
    }
  }

  keys.insert("password");
  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("password", &password_value)) {
    {
      std::string temp;
      if (!password_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'password': expected password, got " + std::string(base::Value::GetTypeName(password_value->type()))));
        out->password.reset();
      }
      else
        out->password.reset(new std::string(temp));
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
std::unique_ptr<URLTransform> URLTransform::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<URLTransform> out(new URLTransform());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> URLTransform::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->scheme.get()) {
    to_value_result->SetWithoutPathExpansion("scheme", std::make_unique<base::Value>(*this->scheme));

  }
  if (this->host.get()) {
    to_value_result->SetWithoutPathExpansion("host", std::make_unique<base::Value>(*this->host));

  }
  if (this->port.get()) {
    to_value_result->SetWithoutPathExpansion("port", std::make_unique<base::Value>(*this->port));

  }
  if (this->path.get()) {
    to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(*this->path));

  }
  if (this->query.get()) {
    to_value_result->SetWithoutPathExpansion("query", std::make_unique<base::Value>(*this->query));

  }
  if (this->query_transform.get()) {
    to_value_result->SetWithoutPathExpansion("queryTransform", (this->query_transform)->ToValue());

  }
  if (this->fragment.get()) {
    to_value_result->SetWithoutPathExpansion("fragment", std::make_unique<base::Value>(*this->fragment));

  }
  if (this->username.get()) {
    to_value_result->SetWithoutPathExpansion("username", std::make_unique<base::Value>(*this->username));

  }
  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("password", std::make_unique<base::Value>(*this->password));

  }

  return to_value_result;
}


Redirect::Redirect()
 {}

Redirect::~Redirect() {}
Redirect::Redirect(Redirect&& rhs)
: extension_path(std::move(rhs.extension_path)),
transform(std::move(rhs.transform)),
url(std::move(rhs.url)),
regex_substitution(std::move(rhs.regex_substitution)){
}

Redirect& Redirect::operator=(Redirect&& rhs)
{
extension_path = std::move(rhs.extension_path);
transform = std::move(rhs.transform);
url = std::move(rhs.url);
regex_substitution = std::move(rhs.regex_substitution);
return *this;
}

// static
bool Redirect::Populate(
    const base::Value& value, Redirect* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("extensionPath");
  const base::Value* extension_path_value = NULL;
  if (dict->GetWithoutPathExpansion("extensionPath", &extension_path_value)) {
    {
      std::string temp;
      if (!extension_path_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'extensionPath': expected extensionPath, got " + std::string(base::Value::GetTypeName(extension_path_value->type()))));
        out->extension_path.reset();
      }
      else
        out->extension_path.reset(new std::string(temp));
    }
  }

  keys.insert("transform");
  const base::Value* transform_value = NULL;
  if (dict->GetWithoutPathExpansion("transform", &transform_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!transform_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'transform': expected dictionary, got " + std::string(base::Value::GetTypeName(transform_value->type()))));
      }
      else {
        std::unique_ptr<URLTransform> temp(new URLTransform());
        if (!URLTransform::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->transform = std::move(temp);
      }
    }
  }

  keys.insert("url");
  const base::Value* url_value = NULL;
  if (dict->GetWithoutPathExpansion("url", &url_value)) {
    {
      std::string temp;
      if (!url_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'url': expected url, got " + std::string(base::Value::GetTypeName(url_value->type()))));
        out->url.reset();
      }
      else
        out->url.reset(new std::string(temp));
    }
  }

  keys.insert("regexSubstitution");
  const base::Value* regex_substitution_value = NULL;
  if (dict->GetWithoutPathExpansion("regexSubstitution", &regex_substitution_value)) {
    {
      std::string temp;
      if (!regex_substitution_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'regexSubstitution': expected regexSubstitution, got " + std::string(base::Value::GetTypeName(regex_substitution_value->type()))));
        out->regex_substitution.reset();
      }
      else
        out->regex_substitution.reset(new std::string(temp));
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
std::unique_ptr<Redirect> Redirect::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<Redirect> out(new Redirect());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Redirect::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->extension_path.get()) {
    to_value_result->SetWithoutPathExpansion("extensionPath", std::make_unique<base::Value>(*this->extension_path));

  }
  if (this->transform.get()) {
    to_value_result->SetWithoutPathExpansion("transform", (this->transform)->ToValue());

  }
  if (this->url.get()) {
    to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(*this->url));

  }
  if (this->regex_substitution.get()) {
    to_value_result->SetWithoutPathExpansion("regexSubstitution", std::make_unique<base::Value>(*this->regex_substitution));

  }

  return to_value_result;
}


RuleCondition::RuleCondition()
: domain_type(DOMAIN_TYPE_NONE) {}

RuleCondition::~RuleCondition() {}
RuleCondition::RuleCondition(RuleCondition&& rhs)
: url_filter(std::move(rhs.url_filter)),
regex_filter(std::move(rhs.regex_filter)),
is_url_filter_case_sensitive(std::move(rhs.is_url_filter_case_sensitive)),
domains(std::move(rhs.domains)),
excluded_domains(std::move(rhs.excluded_domains)),
resource_types(std::move(rhs.resource_types)),
excluded_resource_types(std::move(rhs.excluded_resource_types)),
domain_type(rhs.domain_type){
}

RuleCondition& RuleCondition::operator=(RuleCondition&& rhs)
{
url_filter = std::move(rhs.url_filter);
regex_filter = std::move(rhs.regex_filter);
is_url_filter_case_sensitive = std::move(rhs.is_url_filter_case_sensitive);
domains = std::move(rhs.domains);
excluded_domains = std::move(rhs.excluded_domains);
resource_types = std::move(rhs.resource_types);
excluded_resource_types = std::move(rhs.excluded_resource_types);
domain_type = rhs.domain_type;
return *this;
}

// static
bool RuleCondition::Populate(
    const base::Value& value, RuleCondition* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  out->domain_type = DOMAIN_TYPE_NONE;
  keys.insert("urlFilter");
  const base::Value* url_filter_value = NULL;
  if (dict->GetWithoutPathExpansion("urlFilter", &url_filter_value)) {
    {
      std::string temp;
      if (!url_filter_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'urlFilter': expected urlFilter, got " + std::string(base::Value::GetTypeName(url_filter_value->type()))));
        out->url_filter.reset();
      }
      else
        out->url_filter.reset(new std::string(temp));
    }
  }

  keys.insert("regexFilter");
  const base::Value* regex_filter_value = NULL;
  if (dict->GetWithoutPathExpansion("regexFilter", &regex_filter_value)) {
    {
      std::string temp;
      if (!regex_filter_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'regexFilter': expected regexFilter, got " + std::string(base::Value::GetTypeName(regex_filter_value->type()))));
        out->regex_filter.reset();
      }
      else
        out->regex_filter.reset(new std::string(temp));
    }
  }

  keys.insert("isUrlFilterCaseSensitive");
  const base::Value* is_url_filter_case_sensitive_value = NULL;
  if (dict->GetWithoutPathExpansion("isUrlFilterCaseSensitive", &is_url_filter_case_sensitive_value)) {
    {
      bool temp;
      if (!is_url_filter_case_sensitive_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'isUrlFilterCaseSensitive': expected isUrlFilterCaseSensitive, got " + std::string(base::Value::GetTypeName(is_url_filter_case_sensitive_value->type()))));
        out->is_url_filter_case_sensitive.reset();
      }
      else
        out->is_url_filter_case_sensitive.reset(new bool(temp));
    }
  }

  keys.insert("domains");
  const base::Value* domains_value = NULL;
  if (dict->GetWithoutPathExpansion("domains", &domains_value)) {
    {
      const base::ListValue* list = NULL;
      if (!domains_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'domains': expected list, got " + std::string(base::Value::GetTypeName(domains_value->type()))));
        out->domains.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->domains, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'RuleCondition'"));
          out->domains.reset();
        }
      }
    }
  }

  keys.insert("excludedDomains");
  const base::Value* excluded_domains_value = NULL;
  if (dict->GetWithoutPathExpansion("excludedDomains", &excluded_domains_value)) {
    {
      const base::ListValue* list = NULL;
      if (!excluded_domains_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'excludedDomains': expected list, got " + std::string(base::Value::GetTypeName(excluded_domains_value->type()))));
        out->excluded_domains.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->excluded_domains, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'RuleCondition'"));
          out->excluded_domains.reset();
        }
      }
    }
  }

  keys.insert("resourceTypes");
  const base::Value* resource_types_value = NULL;
  if (dict->GetWithoutPathExpansion("resourceTypes", &resource_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!resource_types_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'resourceTypes': expected list, got " + std::string(base::Value::GetTypeName(resource_types_value->type()))));
        out->resource_types.reset();
      }
      else {
        out->resource_types.reset(new std::vector<ResourceType>);
        for (const auto& it : *(list)) {
          ResourceType tmp;
          std::string resource_type_as_string;
          if (!(it).GetAsString(&resource_type_as_string)) {
            if (error->length())
              error->append(UTF8ToUTF16("; "));
            error->append(UTF8ToUTF16("'ResourceType': expected string, got " + std::string(base::Value::GetTypeName((it).type()))));
            return false;
          }
          tmp = ParseResourceType(resource_type_as_string);
          if (tmp == RESOURCE_TYPE_NONE) {
            if (error->length())
              error->append(UTF8ToUTF16("; "));
            error->append(UTF8ToUTF16("'ResourceType': expected \"main_frame\" or \"sub_frame\" or \"stylesheet\" or \"script\" or \"image\" or \"font\" or \"object\" or \"xmlhttprequest\" or \"ping\" or \"csp_report\" or \"media\" or \"websocket\" or \"other\", got \"" + resource_type_as_string + "\""));
            return false;
          }
          out->resource_types->push_back(tmp);
        }
      }
    }
  }

  keys.insert("excludedResourceTypes");
  const base::Value* excluded_resource_types_value = NULL;
  if (dict->GetWithoutPathExpansion("excludedResourceTypes", &excluded_resource_types_value)) {
    {
      const base::ListValue* list = NULL;
      if (!excluded_resource_types_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'excludedResourceTypes': expected list, got " + std::string(base::Value::GetTypeName(excluded_resource_types_value->type()))));
        out->excluded_resource_types.reset();
      }
      else {
        out->excluded_resource_types.reset(new std::vector<ResourceType>);
        for (const auto& it : *(list)) {
          ResourceType tmp;
          std::string resource_type_as_string;
          if (!(it).GetAsString(&resource_type_as_string)) {
            if (error->length())
              error->append(UTF8ToUTF16("; "));
            error->append(UTF8ToUTF16("'ResourceType': expected string, got " + std::string(base::Value::GetTypeName((it).type()))));
            return false;
          }
          tmp = ParseResourceType(resource_type_as_string);
          if (tmp == RESOURCE_TYPE_NONE) {
            if (error->length())
              error->append(UTF8ToUTF16("; "));
            error->append(UTF8ToUTF16("'ResourceType': expected \"main_frame\" or \"sub_frame\" or \"stylesheet\" or \"script\" or \"image\" or \"font\" or \"object\" or \"xmlhttprequest\" or \"ping\" or \"csp_report\" or \"media\" or \"websocket\" or \"other\", got \"" + resource_type_as_string + "\""));
            return false;
          }
          out->excluded_resource_types->push_back(tmp);
        }
      }
    }
  }

  keys.insert("domainType");
  const base::Value* domain_type_value = NULL;
  if (dict->GetWithoutPathExpansion("domainType", &domain_type_value)) {
    {
      std::string domain_type_as_string;
      if (!domain_type_value->GetAsString(&domain_type_as_string)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'DomainType': expected string, got " + std::string(base::Value::GetTypeName(domain_type_value->type()))));
        return false;
      }
      out->domain_type = ParseDomainType(domain_type_as_string);
      if (out->domain_type == DOMAIN_TYPE_NONE) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'DomainType': expected \"firstParty\" or \"thirdParty\", got \"" + domain_type_as_string + "\""));
        return false;
      }
    }
    } else {
    out->domain_type = DOMAIN_TYPE_NONE;
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
std::unique_ptr<RuleCondition> RuleCondition::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<RuleCondition> out(new RuleCondition());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RuleCondition::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->url_filter.get()) {
    to_value_result->SetWithoutPathExpansion("urlFilter", std::make_unique<base::Value>(*this->url_filter));

  }
  if (this->regex_filter.get()) {
    to_value_result->SetWithoutPathExpansion("regexFilter", std::make_unique<base::Value>(*this->regex_filter));

  }
  if (this->is_url_filter_case_sensitive.get()) {
    to_value_result->SetWithoutPathExpansion("isUrlFilterCaseSensitive", std::make_unique<base::Value>(*this->is_url_filter_case_sensitive));

  }
  if (this->domains.get()) {
    to_value_result->SetWithoutPathExpansion("domains", json_schema_compiler::util::CreateValueFromOptionalArray(this->domains));

  }
  if (this->excluded_domains.get()) {
    to_value_result->SetWithoutPathExpansion("excludedDomains", json_schema_compiler::util::CreateValueFromOptionalArray(this->excluded_domains));

  }
  if (this->resource_types.get()) {
    {
      std::vector<std::string> resourceTypes_list;
      for (const auto& it : *(this->resource_types)) {
      resourceTypes_list.push_back(declarative_net_request::ToString(it));
    }
    to_value_result->SetWithoutPathExpansion("resourceTypes", json_schema_compiler::util::CreateValueFromArray(resourceTypes_list));
    }

  }
  if (this->excluded_resource_types.get()) {
    {
      std::vector<std::string> excludedResourceTypes_list;
      for (const auto& it : *(this->excluded_resource_types)) {
      excludedResourceTypes_list.push_back(declarative_net_request::ToString(it));
    }
    to_value_result->SetWithoutPathExpansion("excludedResourceTypes", json_schema_compiler::util::CreateValueFromArray(excludedResourceTypes_list));
    }

  }
  if (this->domain_type != DOMAIN_TYPE_NONE) {
    to_value_result->SetWithoutPathExpansion("domainType", std::make_unique<base::Value>(declarative_net_request::ToString(this->domain_type)));

  }

  return to_value_result;
}


ModifyHeaderInfo::ModifyHeaderInfo()
: operation(HEADER_OPERATION_NONE) {}

ModifyHeaderInfo::~ModifyHeaderInfo() {}
ModifyHeaderInfo::ModifyHeaderInfo(ModifyHeaderInfo&& rhs)
: header(std::move(rhs.header)),
operation(rhs.operation),
value(std::move(rhs.value)){
}

ModifyHeaderInfo& ModifyHeaderInfo::operator=(ModifyHeaderInfo&& rhs)
{
header = std::move(rhs.header);
operation = rhs.operation;
value = std::move(rhs.value);
return *this;
}

// static
bool ModifyHeaderInfo::Populate(
    const base::Value& value, ModifyHeaderInfo* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("header");
  const base::Value* header_value = NULL;
  if (!dict->GetWithoutPathExpansion("header", &header_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'header' is required"));
    return false;
  }
  {
    if (!header_value->GetAsString(&out->header)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'header': expected header, got " + std::string(base::Value::GetTypeName(header_value->type()))));
      return false;
    }
  }

  keys.insert("operation");
  const base::Value* operation_value = NULL;
  if (!dict->GetWithoutPathExpansion("operation", &operation_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'operation' is required"));
    return false;
  }
  {
    std::string header_operation_as_string;
    if (!operation_value->GetAsString(&header_operation_as_string)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'HeaderOperation': expected string, got " + std::string(base::Value::GetTypeName(operation_value->type()))));
      return false;
    }
    out->operation = ParseHeaderOperation(header_operation_as_string);
    if (out->operation == HEADER_OPERATION_NONE) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'HeaderOperation': expected \"append\" or \"set\" or \"remove\", got \"" + header_operation_as_string + "\""));
      return false;
    }
  }

  keys.insert("value");
  const base::Value* value_value = NULL;
  if (dict->GetWithoutPathExpansion("value", &value_value)) {
    {
      std::string temp;
      if (!value_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'value': expected value, got " + std::string(base::Value::GetTypeName(value_value->type()))));
        out->value.reset();
      }
      else
        out->value.reset(new std::string(temp));
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
std::unique_ptr<ModifyHeaderInfo> ModifyHeaderInfo::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<ModifyHeaderInfo> out(new ModifyHeaderInfo());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ModifyHeaderInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("header", std::make_unique<base::Value>(this->header));

  to_value_result->SetWithoutPathExpansion("operation", std::make_unique<base::Value>(declarative_net_request::ToString(this->operation)));

  if (this->value.get()) {
    to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(*this->value));

  }

  return to_value_result;
}


RuleAction::RuleAction()
: type(RULE_ACTION_TYPE_NONE) {}

RuleAction::~RuleAction() {}
RuleAction::RuleAction(RuleAction&& rhs)
: type(rhs.type),
redirect(std::move(rhs.redirect)),
request_headers(std::move(rhs.request_headers)),
response_headers(std::move(rhs.response_headers)){
}

RuleAction& RuleAction::operator=(RuleAction&& rhs)
{
type = rhs.type;
redirect = std::move(rhs.redirect);
request_headers = std::move(rhs.request_headers);
response_headers = std::move(rhs.response_headers);
return *this;
}

// static
bool RuleAction::Populate(
    const base::Value& value, RuleAction* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("type");
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'type' is required"));
    return false;
  }
  {
    std::string rule_action_type_as_string;
    if (!type_value->GetAsString(&rule_action_type_as_string)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'RuleActionType': expected string, got " + std::string(base::Value::GetTypeName(type_value->type()))));
      return false;
    }
    out->type = ParseRuleActionType(rule_action_type_as_string);
    if (out->type == RULE_ACTION_TYPE_NONE) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'RuleActionType': expected \"block\" or \"redirect\" or \"allow\" or \"upgradeScheme\" or \"modifyHeaders\" or \"allowAllRequests\", got \"" + rule_action_type_as_string + "\""));
      return false;
    }
  }

  keys.insert("redirect");
  const base::Value* redirect_value = NULL;
  if (dict->GetWithoutPathExpansion("redirect", &redirect_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!redirect_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'redirect': expected dictionary, got " + std::string(base::Value::GetTypeName(redirect_value->type()))));
      }
      else {
        std::unique_ptr<Redirect> temp(new Redirect());
        if (!Redirect::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->redirect = std::move(temp);
      }
    }
  }

  keys.insert("requestHeaders");
  const base::Value* request_headers_value = NULL;
  if (dict->GetWithoutPathExpansion("requestHeaders", &request_headers_value)) {
    {
      const base::ListValue* list = NULL;
      if (!request_headers_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'requestHeaders': expected list, got " + std::string(base::Value::GetTypeName(request_headers_value->type()))));
        out->request_headers.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->request_headers, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'RuleAction'"));
          out->request_headers.reset();
        }
      }
    }
  }

  keys.insert("responseHeaders");
  const base::Value* response_headers_value = NULL;
  if (dict->GetWithoutPathExpansion("responseHeaders", &response_headers_value)) {
    {
      const base::ListValue* list = NULL;
      if (!response_headers_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'responseHeaders': expected list, got " + std::string(base::Value::GetTypeName(response_headers_value->type()))));
        out->response_headers.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->response_headers, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'RuleAction'"));
          out->response_headers.reset();
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
std::unique_ptr<RuleAction> RuleAction::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<RuleAction> out(new RuleAction());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RuleAction::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(declarative_net_request::ToString(this->type)));

  if (this->redirect.get()) {
    to_value_result->SetWithoutPathExpansion("redirect", (this->redirect)->ToValue());

  }
  if (this->request_headers.get()) {
    to_value_result->SetWithoutPathExpansion("requestHeaders", json_schema_compiler::util::CreateValueFromOptionalArray(this->request_headers));

  }
  if (this->response_headers.get()) {
    to_value_result->SetWithoutPathExpansion("responseHeaders", json_schema_compiler::util::CreateValueFromOptionalArray(this->response_headers));

  }

  return to_value_result;
}


Rule::Rule()
: id(0) {}

Rule::~Rule() {}
Rule::Rule(Rule&& rhs)
: id(rhs.id),
priority(std::move(rhs.priority)),
condition(std::move(rhs.condition)),
action(std::move(rhs.action)){
}

Rule& Rule::operator=(Rule&& rhs)
{
id = rhs.id;
priority = std::move(rhs.priority);
condition = std::move(rhs.condition);
action = std::move(rhs.action);
return *this;
}

// static
bool Rule::Populate(
    const base::Value& value, Rule* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("id");
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'id' is required"));
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'id': expected id, got " + std::string(base::Value::GetTypeName(id_value->type()))));
      return false;
    }
  }

  keys.insert("priority");
  const base::Value* priority_value = NULL;
  if (dict->GetWithoutPathExpansion("priority", &priority_value)) {
    {
      int temp;
      if (!priority_value->GetAsInteger(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'priority': expected priority, got " + std::string(base::Value::GetTypeName(priority_value->type()))));
        out->priority.reset();
      }
      else
        out->priority.reset(new int(temp));
    }
  }

  keys.insert("condition");
  const base::Value* condition_value = NULL;
  if (!dict->GetWithoutPathExpansion("condition", &condition_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'condition' is required"));
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!condition_value->GetAsDictionary(&dictionary)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'condition': expected dictionary, got " + std::string(base::Value::GetTypeName(condition_value->type()))));
      return false;
    }
    if (!RuleCondition::Populate(*dictionary, &out->condition, error)) {
      return false;
    }
  }

  keys.insert("action");
  const base::Value* action_value = NULL;
  if (!dict->GetWithoutPathExpansion("action", &action_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'action' is required"));
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!action_value->GetAsDictionary(&dictionary)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'action': expected dictionary, got " + std::string(base::Value::GetTypeName(action_value->type()))));
      return false;
    }
    if (!RuleAction::Populate(*dictionary, &out->action, error)) {
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
std::unique_ptr<Rule> Rule::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<Rule> out(new Rule());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Rule::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  if (this->priority.get()) {
    to_value_result->SetWithoutPathExpansion("priority", std::make_unique<base::Value>(*this->priority));

  }
  to_value_result->SetWithoutPathExpansion("condition", (this->condition).ToValue());

  to_value_result->SetWithoutPathExpansion("action", (this->action).ToValue());


  return to_value_result;
}


MatchedRule::MatchedRule()
: rule_id(0) {}

MatchedRule::~MatchedRule() {}
MatchedRule::MatchedRule(MatchedRule&& rhs)
: rule_id(rhs.rule_id),
ruleset_id(std::move(rhs.ruleset_id)){
}

MatchedRule& MatchedRule::operator=(MatchedRule&& rhs)
{
rule_id = rhs.rule_id;
ruleset_id = std::move(rhs.ruleset_id);
return *this;
}

// static
bool MatchedRule::Populate(
    const base::Value& value, MatchedRule* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("ruleId");
  const base::Value* rule_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("ruleId", &rule_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'ruleId' is required"));
    return false;
  }
  {
    if (!rule_id_value->GetAsInteger(&out->rule_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'ruleId': expected ruleId, got " + std::string(base::Value::GetTypeName(rule_id_value->type()))));
      return false;
    }
  }

  keys.insert("rulesetId");
  const base::Value* ruleset_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("rulesetId", &ruleset_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'rulesetId' is required"));
    return false;
  }
  {
    if (!ruleset_id_value->GetAsString(&out->ruleset_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'rulesetId': expected rulesetId, got " + std::string(base::Value::GetTypeName(ruleset_id_value->type()))));
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
std::unique_ptr<MatchedRule> MatchedRule::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<MatchedRule> out(new MatchedRule());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MatchedRule::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("ruleId", std::make_unique<base::Value>(this->rule_id));

  to_value_result->SetWithoutPathExpansion("rulesetId", std::make_unique<base::Value>(this->ruleset_id));


  return to_value_result;
}


MatchedRuleInfo::MatchedRuleInfo()
: time_stamp(0.0),
tab_id(0) {}

MatchedRuleInfo::~MatchedRuleInfo() {}
MatchedRuleInfo::MatchedRuleInfo(MatchedRuleInfo&& rhs)
: rule(std::move(rhs.rule)),
time_stamp(rhs.time_stamp),
tab_id(rhs.tab_id){
}

MatchedRuleInfo& MatchedRuleInfo::operator=(MatchedRuleInfo&& rhs)
{
rule = std::move(rhs.rule);
time_stamp = rhs.time_stamp;
tab_id = rhs.tab_id;
return *this;
}

// static
bool MatchedRuleInfo::Populate(
    const base::Value& value, MatchedRuleInfo* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("rule");
  const base::Value* rule_value = NULL;
  if (!dict->GetWithoutPathExpansion("rule", &rule_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'rule' is required"));
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!rule_value->GetAsDictionary(&dictionary)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'rule': expected dictionary, got " + std::string(base::Value::GetTypeName(rule_value->type()))));
      return false;
    }
    if (!MatchedRule::Populate(*dictionary, &out->rule, error)) {
      return false;
    }
  }

  keys.insert("timeStamp");
  const base::Value* time_stamp_value = NULL;
  if (!dict->GetWithoutPathExpansion("timeStamp", &time_stamp_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'timeStamp' is required"));
    return false;
  }
  {
    if (!time_stamp_value->GetAsDouble(&out->time_stamp)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'timeStamp': expected timeStamp, got " + std::string(base::Value::GetTypeName(time_stamp_value->type()))));
      return false;
    }
  }

  keys.insert("tabId");
  const base::Value* tab_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'tabId' is required"));
    return false;
  }
  {
    if (!tab_id_value->GetAsInteger(&out->tab_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'tabId': expected tabId, got " + std::string(base::Value::GetTypeName(tab_id_value->type()))));
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
std::unique_ptr<MatchedRuleInfo> MatchedRuleInfo::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<MatchedRuleInfo> out(new MatchedRuleInfo());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MatchedRuleInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("rule", (this->rule).ToValue());

  to_value_result->SetWithoutPathExpansion("timeStamp", std::make_unique<base::Value>(this->time_stamp));

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));


  return to_value_result;
}


MatchedRulesFilter::MatchedRulesFilter()
 {}

MatchedRulesFilter::~MatchedRulesFilter() {}
MatchedRulesFilter::MatchedRulesFilter(MatchedRulesFilter&& rhs)
: tab_id(std::move(rhs.tab_id)),
min_time_stamp(std::move(rhs.min_time_stamp)){
}

MatchedRulesFilter& MatchedRulesFilter::operator=(MatchedRulesFilter&& rhs)
{
tab_id = std::move(rhs.tab_id);
min_time_stamp = std::move(rhs.min_time_stamp);
return *this;
}

// static
bool MatchedRulesFilter::Populate(
    const base::Value& value, MatchedRulesFilter* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("tabId");
  const base::Value* tab_id_value = NULL;
  if (dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    {
      int temp;
      if (!tab_id_value->GetAsInteger(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'tabId': expected tabId, got " + std::string(base::Value::GetTypeName(tab_id_value->type()))));
        out->tab_id.reset();
      }
      else
        out->tab_id.reset(new int(temp));
    }
  }

  keys.insert("minTimeStamp");
  const base::Value* min_time_stamp_value = NULL;
  if (dict->GetWithoutPathExpansion("minTimeStamp", &min_time_stamp_value)) {
    {
      double temp;
      if (!min_time_stamp_value->GetAsDouble(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'minTimeStamp': expected minTimeStamp, got " + std::string(base::Value::GetTypeName(min_time_stamp_value->type()))));
        out->min_time_stamp.reset();
      }
      else
        out->min_time_stamp.reset(new double(temp));
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
std::unique_ptr<MatchedRulesFilter> MatchedRulesFilter::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<MatchedRulesFilter> out(new MatchedRulesFilter());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MatchedRulesFilter::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->tab_id.get()) {
    to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(*this->tab_id));

  }
  if (this->min_time_stamp.get()) {
    to_value_result->SetWithoutPathExpansion("minTimeStamp", std::make_unique<base::Value>(*this->min_time_stamp));

  }

  return to_value_result;
}


RulesMatchedDetails::RulesMatchedDetails()
 {}

RulesMatchedDetails::~RulesMatchedDetails() {}
RulesMatchedDetails::RulesMatchedDetails(RulesMatchedDetails&& rhs)
: rules_matched_info(std::move(rhs.rules_matched_info)){
}

RulesMatchedDetails& RulesMatchedDetails::operator=(RulesMatchedDetails&& rhs)
{
rules_matched_info = std::move(rhs.rules_matched_info);
return *this;
}

// static
bool RulesMatchedDetails::Populate(
    const base::Value& value, RulesMatchedDetails* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("rulesMatchedInfo");
  const base::Value* rules_matched_info_value = NULL;
  if (!dict->GetWithoutPathExpansion("rulesMatchedInfo", &rules_matched_info_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'rulesMatchedInfo' is required"));
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!rules_matched_info_value->GetAsList(&list)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'rulesMatchedInfo': expected list, got " + std::string(base::Value::GetTypeName(rules_matched_info_value->type()))));
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->rules_matched_info, error)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("unable to populate array 'RulesMatchedDetails'"));
        return false;
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
std::unique_ptr<RulesMatchedDetails> RulesMatchedDetails::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<RulesMatchedDetails> out(new RulesMatchedDetails());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RulesMatchedDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("rulesMatchedInfo", json_schema_compiler::util::CreateValueFromArray(this->rules_matched_info));


  return to_value_result;
}


RequestDetails::RequestDetails()
: frame_id(0),
parent_frame_id(0),
tab_id(0),
type(RESOURCE_TYPE_NONE) {}

RequestDetails::~RequestDetails() {}
RequestDetails::RequestDetails(RequestDetails&& rhs)
: request_id(std::move(rhs.request_id)),
url(std::move(rhs.url)),
initiator(std::move(rhs.initiator)),
method(std::move(rhs.method)),
frame_id(rhs.frame_id),
parent_frame_id(rhs.parent_frame_id),
tab_id(rhs.tab_id),
type(rhs.type){
}

RequestDetails& RequestDetails::operator=(RequestDetails&& rhs)
{
request_id = std::move(rhs.request_id);
url = std::move(rhs.url);
initiator = std::move(rhs.initiator);
method = std::move(rhs.method);
frame_id = rhs.frame_id;
parent_frame_id = rhs.parent_frame_id;
tab_id = rhs.tab_id;
type = rhs.type;
return *this;
}

// static
bool RequestDetails::Populate(
    const base::Value& value, RequestDetails* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("requestId");
  const base::Value* request_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("requestId", &request_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'requestId' is required"));
    return false;
  }
  {
    if (!request_id_value->GetAsString(&out->request_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'requestId': expected requestId, got " + std::string(base::Value::GetTypeName(request_id_value->type()))));
      return false;
    }
  }

  keys.insert("url");
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'url' is required"));
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'url': expected url, got " + std::string(base::Value::GetTypeName(url_value->type()))));
      return false;
    }
  }

  keys.insert("initiator");
  const base::Value* initiator_value = NULL;
  if (dict->GetWithoutPathExpansion("initiator", &initiator_value)) {
    {
      std::string temp;
      if (!initiator_value->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'initiator': expected initiator, got " + std::string(base::Value::GetTypeName(initiator_value->type()))));
        out->initiator.reset();
      }
      else
        out->initiator.reset(new std::string(temp));
    }
  }

  keys.insert("method");
  const base::Value* method_value = NULL;
  if (!dict->GetWithoutPathExpansion("method", &method_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'method' is required"));
    return false;
  }
  {
    if (!method_value->GetAsString(&out->method)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'method': expected method, got " + std::string(base::Value::GetTypeName(method_value->type()))));
      return false;
    }
  }

  keys.insert("frameId");
  const base::Value* frame_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("frameId", &frame_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'frameId' is required"));
    return false;
  }
  {
    if (!frame_id_value->GetAsInteger(&out->frame_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'frameId': expected frameId, got " + std::string(base::Value::GetTypeName(frame_id_value->type()))));
      return false;
    }
  }

  keys.insert("parentFrameId");
  const base::Value* parent_frame_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("parentFrameId", &parent_frame_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'parentFrameId' is required"));
    return false;
  }
  {
    if (!parent_frame_id_value->GetAsInteger(&out->parent_frame_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'parentFrameId': expected parentFrameId, got " + std::string(base::Value::GetTypeName(parent_frame_id_value->type()))));
      return false;
    }
  }

  keys.insert("tabId");
  const base::Value* tab_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabId", &tab_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'tabId' is required"));
    return false;
  }
  {
    if (!tab_id_value->GetAsInteger(&out->tab_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'tabId': expected tabId, got " + std::string(base::Value::GetTypeName(tab_id_value->type()))));
      return false;
    }
  }

  keys.insert("type");
  const base::Value* type_value = NULL;
  if (!dict->GetWithoutPathExpansion("type", &type_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'type' is required"));
    return false;
  }
  {
    std::string resource_type_as_string;
    if (!type_value->GetAsString(&resource_type_as_string)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'ResourceType': expected string, got " + std::string(base::Value::GetTypeName(type_value->type()))));
      return false;
    }
    out->type = ParseResourceType(resource_type_as_string);
    if (out->type == RESOURCE_TYPE_NONE) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'ResourceType': expected \"main_frame\" or \"sub_frame\" or \"stylesheet\" or \"script\" or \"image\" or \"font\" or \"object\" or \"xmlhttprequest\" or \"ping\" or \"csp_report\" or \"media\" or \"websocket\" or \"other\", got \"" + resource_type_as_string + "\""));
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
std::unique_ptr<RequestDetails> RequestDetails::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<RequestDetails> out(new RequestDetails());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> RequestDetails::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("requestId", std::make_unique<base::Value>(this->request_id));

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  if (this->initiator.get()) {
    to_value_result->SetWithoutPathExpansion("initiator", std::make_unique<base::Value>(*this->initiator));

  }
  to_value_result->SetWithoutPathExpansion("method", std::make_unique<base::Value>(this->method));

  to_value_result->SetWithoutPathExpansion("frameId", std::make_unique<base::Value>(this->frame_id));

  to_value_result->SetWithoutPathExpansion("parentFrameId", std::make_unique<base::Value>(this->parent_frame_id));

  to_value_result->SetWithoutPathExpansion("tabId", std::make_unique<base::Value>(this->tab_id));

  to_value_result->SetWithoutPathExpansion("type", std::make_unique<base::Value>(declarative_net_request::ToString(this->type)));


  return to_value_result;
}


MatchedRuleInfoDebug::MatchedRuleInfoDebug()
 {}

MatchedRuleInfoDebug::~MatchedRuleInfoDebug() {}
MatchedRuleInfoDebug::MatchedRuleInfoDebug(MatchedRuleInfoDebug&& rhs)
: rule(std::move(rhs.rule)),
request(std::move(rhs.request)){
}

MatchedRuleInfoDebug& MatchedRuleInfoDebug::operator=(MatchedRuleInfoDebug&& rhs)
{
rule = std::move(rhs.rule);
request = std::move(rhs.request);
return *this;
}

// static
bool MatchedRuleInfoDebug::Populate(
    const base::Value& value, MatchedRuleInfoDebug* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("rule");
  const base::Value* rule_value = NULL;
  if (!dict->GetWithoutPathExpansion("rule", &rule_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'rule' is required"));
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!rule_value->GetAsDictionary(&dictionary)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'rule': expected dictionary, got " + std::string(base::Value::GetTypeName(rule_value->type()))));
      return false;
    }
    if (!MatchedRule::Populate(*dictionary, &out->rule, error)) {
      return false;
    }
  }

  keys.insert("request");
  const base::Value* request_value = NULL;
  if (!dict->GetWithoutPathExpansion("request", &request_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'request' is required"));
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!request_value->GetAsDictionary(&dictionary)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'request': expected dictionary, got " + std::string(base::Value::GetTypeName(request_value->type()))));
      return false;
    }
    if (!RequestDetails::Populate(*dictionary, &out->request, error)) {
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
std::unique_ptr<MatchedRuleInfoDebug> MatchedRuleInfoDebug::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<MatchedRuleInfoDebug> out(new MatchedRuleInfoDebug());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> MatchedRuleInfoDebug::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("rule", (this->rule).ToValue());

  to_value_result->SetWithoutPathExpansion("request", (this->request).ToValue());


  return to_value_result;
}



//
// Functions
//

namespace UpdateDynamicRules {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args, base::string16* error) {
  DCHECK(error);
  if (args.GetSize() != 2) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected 2 arguments, got " + base::NumberToString(args.GetSize())));
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* rule_ids_to_remove_value = NULL;
  if (args.Get(0, &rule_ids_to_remove_value) &&
      !rule_ids_to_remove_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!rule_ids_to_remove_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'ruleIdsToRemove': expected list, got " + std::string(base::Value::GetTypeName(rule_ids_to_remove_value->type()))));
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->rule_ids_to_remove, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'updateDynamicRules'"));
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'ruleIdsToRemove' is required"));
    return std::unique_ptr<Params>();
  }

  const base::Value* rules_to_add_value = NULL;
  if (args.Get(1, &rules_to_add_value) &&
      !rules_to_add_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!rules_to_add_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'rulesToAdd': expected list, got " + std::string(base::Value::GetTypeName(rules_to_add_value->type()))));
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->rules_to_add, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'updateDynamicRules'"));
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'rulesToAdd' is required"));
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace UpdateDynamicRules

namespace GetDynamicRules {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<Rule>& rules) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(rules));

  return create_results;
}
}  // namespace GetDynamicRules

namespace UpdateEnabledRulesets {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args, base::string16* error) {
  DCHECK(error);
  if (args.GetSize() != 2) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected 2 arguments, got " + base::NumberToString(args.GetSize())));
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* ruleset_ids_to_disable_value = NULL;
  if (args.Get(0, &ruleset_ids_to_disable_value) &&
      !ruleset_ids_to_disable_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!ruleset_ids_to_disable_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'rulesetIdsToDisable': expected list, got " + std::string(base::Value::GetTypeName(ruleset_ids_to_disable_value->type()))));
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->ruleset_ids_to_disable, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'updateEnabledRulesets'"));
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'rulesetIdsToDisable' is required"));
    return std::unique_ptr<Params>();
  }

  const base::Value* ruleset_ids_to_enable_value = NULL;
  if (args.Get(1, &ruleset_ids_to_enable_value) &&
      !ruleset_ids_to_enable_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!ruleset_ids_to_enable_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'rulesetIdsToEnable': expected list, got " + std::string(base::Value::GetTypeName(ruleset_ids_to_enable_value->type()))));
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->ruleset_ids_to_enable, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'updateEnabledRulesets'"));
          return std::unique_ptr<Params>();
        }
      }
    }
  }
  else {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'rulesetIdsToEnable' is required"));
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace UpdateEnabledRulesets

namespace GetEnabledRulesets {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<std::string>& ruleset_ids) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(ruleset_ids));

  return create_results;
}
}  // namespace GetEnabledRulesets

namespace GetMatchedRules {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args, base::string16* error) {
  DCHECK(error);
  if (args.GetSize() > 1) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected 1 arguments, got " + base::NumberToString(args.GetSize())));
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* filter_value = NULL;
  if (args.Get(0, &filter_value) &&
      !filter_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!filter_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'filter': expected dictionary, got " + std::string(base::Value::GetTypeName(filter_value->type()))));
      }
      else {
        std::unique_ptr<MatchedRulesFilter> temp(new MatchedRulesFilter());
        if (!MatchedRulesFilter::Populate(*dictionary, temp.get(), error)) {
          return std::unique_ptr<Params>();
        }
        else
          params->filter = std::move(temp);
      }
    }
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const RulesMatchedDetails& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}
}  // namespace GetMatchedRules

namespace SetActionCountAsBadgeText {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args, base::string16* error) {
  DCHECK(error);
  if (args.GetSize() != 1) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected 1 arguments, got " + base::NumberToString(args.GetSize())));
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* enable_value = NULL;
  if (args.Get(0, &enable_value) &&
      !enable_value->is_none()) {
    {
      if (!enable_value->GetAsBoolean(&params->enable)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'enable': expected enable, got " + std::string(base::Value::GetTypeName(enable_value->type()))));
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'enable' is required"));
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace SetActionCountAsBadgeText

//
// Events
//

namespace OnRuleMatchedDebug {

const char kEventName[] = "declarativeNetRequest.onRuleMatchedDebug";

std::unique_ptr<base::ListValue> Create(const MatchedRuleInfoDebug& info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((info).ToValue());

  return create_results;
}

}  // namespace OnRuleMatchedDebug

}  // namespace declarative_net_request
}  // namespace api
}  // namespace extensions

