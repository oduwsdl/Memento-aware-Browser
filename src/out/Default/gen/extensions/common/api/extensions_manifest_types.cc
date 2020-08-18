// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/extensions_manifest_types.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/extensions_manifest_types.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace extensions_manifest_types {
//
// Types
//

Automation::Object::Object()
 {}

Automation::Object::~Object() {}
Automation::Object::Object(Object&& rhs)
: desktop(std::move(rhs.desktop)),
matches(std::move(rhs.matches)),
interact(std::move(rhs.interact)){
}

Automation::Object& Automation::Object::operator=(Object&& rhs)
{
desktop = std::move(rhs.desktop);
matches = std::move(rhs.matches);
interact = std::move(rhs.interact);
return *this;
}

// static
bool Automation::Object::Populate(
    const base::Value& value, Object* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("desktop");
  const base::Value* desktop_value = NULL;
  if (dict->GetWithoutPathExpansion("desktop", &desktop_value)) {
    {
      bool temp;
      if (!desktop_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'desktop': expected desktop, got " + std::string(base::Value::GetTypeName(desktop_value->type()))));
        out->desktop.reset();
      }
      else
        out->desktop.reset(new bool(temp));
    }
  }

  keys.insert("matches");
  const base::Value* matches_value = NULL;
  if (dict->GetWithoutPathExpansion("matches", &matches_value)) {
    {
      const base::ListValue* list = NULL;
      if (!matches_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'matches': expected list, got " + std::string(base::Value::GetTypeName(matches_value->type()))));
        out->matches.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->matches, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'object'"));
          out->matches.reset();
        }
      }
    }
  }

  keys.insert("interact");
  const base::Value* interact_value = NULL;
  if (dict->GetWithoutPathExpansion("interact", &interact_value)) {
    {
      bool temp;
      if (!interact_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'interact': expected interact, got " + std::string(base::Value::GetTypeName(interact_value->type()))));
        out->interact.reset();
      }
      else
        out->interact.reset(new bool(temp));
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

std::unique_ptr<base::DictionaryValue> Automation::Object::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->desktop.get()) {
    to_value_result->SetWithoutPathExpansion("desktop", std::make_unique<base::Value>(*this->desktop));

  }
  if (this->matches.get()) {
    to_value_result->SetWithoutPathExpansion("matches", json_schema_compiler::util::CreateValueFromOptionalArray(this->matches));

  }
  if (this->interact.get()) {
    to_value_result->SetWithoutPathExpansion("interact", std::make_unique<base::Value>(*this->interact));

  }

  return to_value_result;
}



Automation::Automation()
 {}

Automation::~Automation() {}
Automation::Automation(Automation&& rhs)
: as_boolean(std::move(rhs.as_boolean)),
as_object(std::move(rhs.as_object)){
}

Automation& Automation::operator=(Automation&& rhs)
{
as_boolean = std::move(rhs.as_boolean);
as_object = std::move(rhs.as_object);
return *this;
}

// static
bool Automation::Populate(
    const base::Value& value, Automation* out, base::string16* error) {
  DCHECK(error);
  if (value.type() == base::Value::Type::BOOLEAN) {
    {
      bool temp;
      if (!(&value)->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'boolean': expected boolean, got " + std::string(base::Value::GetTypeName((&value)->type()))));
        out->as_boolean.reset();
      }
      else
        out->as_boolean.reset(new bool(temp));
    }
    return true;
  }
  if (value.type() == base::Value::Type::DICTIONARY) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!(&value)->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'object': expected dictionary, got " + std::string(base::Value::GetTypeName((&value)->type()))));
      }
      else {
        std::unique_ptr<Object> temp(new Object());
        if (!Object::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->as_object = std::move(temp);
      }
    }
    return true;
  }
  if (error->length())
    error->append(UTF8ToUTF16("; "));
  error->append(UTF8ToUTF16("expected boolean or object, got " +  std::string(base::Value::GetTypeName(value.type()))));
  return false;
}

// static
std::unique_ptr<Automation> Automation::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<Automation> out(new Automation());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::Value> Automation::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_boolean) {
    DCHECK(!result) << "Cannot set multiple choices for automation";
    result = std::make_unique<base::Value>(*as_boolean);

  }
  if (as_object) {
    DCHECK(!result) << "Cannot set multiple choices for automation";
    result = (as_object)->ToValue();

  }
  DCHECK(result) << "Must set at least one choice for automation";
  return result;
}


ContentCapabilities::ContentCapabilities()
 {}

ContentCapabilities::~ContentCapabilities() {}
ContentCapabilities::ContentCapabilities(ContentCapabilities&& rhs)
: matches(std::move(rhs.matches)),
permissions(std::move(rhs.permissions)){
}

ContentCapabilities& ContentCapabilities::operator=(ContentCapabilities&& rhs)
{
matches = std::move(rhs.matches);
permissions = std::move(rhs.permissions);
return *this;
}

// static
bool ContentCapabilities::Populate(
    const base::Value& value, ContentCapabilities* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("matches");
  const base::Value* matches_value = NULL;
  if (!dict->GetWithoutPathExpansion("matches", &matches_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'matches' is required"));
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!matches_value->GetAsList(&list)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'matches': expected list, got " + std::string(base::Value::GetTypeName(matches_value->type()))));
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->matches, error)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("unable to populate array 'ContentCapabilities'"));
        return false;
      }
    }
  }

  keys.insert("permissions");
  const base::Value* permissions_value = NULL;
  if (!dict->GetWithoutPathExpansion("permissions", &permissions_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'permissions' is required"));
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!permissions_value->GetAsList(&list)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'permissions': expected list, got " + std::string(base::Value::GetTypeName(permissions_value->type()))));
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->permissions, error)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("unable to populate array 'ContentCapabilities'"));
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
std::unique_ptr<ContentCapabilities> ContentCapabilities::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<ContentCapabilities> out(new ContentCapabilities());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ContentCapabilities::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("matches", json_schema_compiler::util::CreateValueFromArray(this->matches));

  to_value_result->SetWithoutPathExpansion("permissions", json_schema_compiler::util::CreateValueFromArray(this->permissions));


  return to_value_result;
}


ExternallyConnectable::ExternallyConnectable()
 {}

ExternallyConnectable::~ExternallyConnectable() {}
ExternallyConnectable::ExternallyConnectable(ExternallyConnectable&& rhs)
: ids(std::move(rhs.ids)),
matches(std::move(rhs.matches)),
accepts_tls_channel_id(std::move(rhs.accepts_tls_channel_id)){
}

ExternallyConnectable& ExternallyConnectable::operator=(ExternallyConnectable&& rhs)
{
ids = std::move(rhs.ids);
matches = std::move(rhs.matches);
accepts_tls_channel_id = std::move(rhs.accepts_tls_channel_id);
return *this;
}

// static
bool ExternallyConnectable::Populate(
    const base::Value& value, ExternallyConnectable* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("ids");
  const base::Value* ids_value = NULL;
  if (dict->GetWithoutPathExpansion("ids", &ids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!ids_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'ids': expected list, got " + std::string(base::Value::GetTypeName(ids_value->type()))));
        out->ids.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->ids, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'ExternallyConnectable'"));
          out->ids.reset();
        }
      }
    }
  }

  keys.insert("matches");
  const base::Value* matches_value = NULL;
  if (dict->GetWithoutPathExpansion("matches", &matches_value)) {
    {
      const base::ListValue* list = NULL;
      if (!matches_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'matches': expected list, got " + std::string(base::Value::GetTypeName(matches_value->type()))));
        out->matches.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->matches, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'ExternallyConnectable'"));
          out->matches.reset();
        }
      }
    }
  }

  keys.insert("accepts_tls_channel_id");
  const base::Value* accepts_tls_channel_id_value = NULL;
  if (dict->GetWithoutPathExpansion("accepts_tls_channel_id", &accepts_tls_channel_id_value)) {
    {
      bool temp;
      if (!accepts_tls_channel_id_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'accepts_tls_channel_id': expected accepts_tls_channel_id, got " + std::string(base::Value::GetTypeName(accepts_tls_channel_id_value->type()))));
        out->accepts_tls_channel_id.reset();
      }
      else
        out->accepts_tls_channel_id.reset(new bool(temp));
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
std::unique_ptr<ExternallyConnectable> ExternallyConnectable::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<ExternallyConnectable> out(new ExternallyConnectable());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExternallyConnectable::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->ids.get()) {
    to_value_result->SetWithoutPathExpansion("ids", json_schema_compiler::util::CreateValueFromOptionalArray(this->ids));

  }
  if (this->matches.get()) {
    to_value_result->SetWithoutPathExpansion("matches", json_schema_compiler::util::CreateValueFromOptionalArray(this->matches));

  }
  if (this->accepts_tls_channel_id.get()) {
    to_value_result->SetWithoutPathExpansion("accepts_tls_channel_id", std::make_unique<base::Value>(*this->accepts_tls_channel_id));

  }

  return to_value_result;
}


OptionsUI::OptionsUI()
 {}

OptionsUI::~OptionsUI() {}
OptionsUI::OptionsUI(OptionsUI&& rhs)
: page(std::move(rhs.page)),
chrome_style(std::move(rhs.chrome_style)),
open_in_tab(std::move(rhs.open_in_tab)){
}

OptionsUI& OptionsUI::operator=(OptionsUI&& rhs)
{
page = std::move(rhs.page);
chrome_style = std::move(rhs.chrome_style);
open_in_tab = std::move(rhs.open_in_tab);
return *this;
}

// static
bool OptionsUI::Populate(
    const base::Value& value, OptionsUI* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("page");
  const base::Value* page_value = NULL;
  if (!dict->GetWithoutPathExpansion("page", &page_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'page' is required"));
    return false;
  }
  {
    if (!page_value->GetAsString(&out->page)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'page': expected page, got " + std::string(base::Value::GetTypeName(page_value->type()))));
      return false;
    }
  }

  keys.insert("chrome_style");
  const base::Value* chrome_style_value = NULL;
  if (dict->GetWithoutPathExpansion("chrome_style", &chrome_style_value)) {
    {
      bool temp;
      if (!chrome_style_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'chrome_style': expected chrome_style, got " + std::string(base::Value::GetTypeName(chrome_style_value->type()))));
        out->chrome_style.reset();
      }
      else
        out->chrome_style.reset(new bool(temp));
    }
  }

  keys.insert("open_in_tab");
  const base::Value* open_in_tab_value = NULL;
  if (dict->GetWithoutPathExpansion("open_in_tab", &open_in_tab_value)) {
    {
      bool temp;
      if (!open_in_tab_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'open_in_tab': expected open_in_tab, got " + std::string(base::Value::GetTypeName(open_in_tab_value->type()))));
        out->open_in_tab.reset();
      }
      else
        out->open_in_tab.reset(new bool(temp));
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
std::unique_ptr<OptionsUI> OptionsUI::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<OptionsUI> out(new OptionsUI());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> OptionsUI::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("page", std::make_unique<base::Value>(this->page));

  if (this->chrome_style.get()) {
    to_value_result->SetWithoutPathExpansion("chrome_style", std::make_unique<base::Value>(*this->chrome_style));

  }
  if (this->open_in_tab.get()) {
    to_value_result->SetWithoutPathExpansion("open_in_tab", std::make_unique<base::Value>(*this->open_in_tab));

  }

  return to_value_result;
}


SocketHostPatterns::SocketHostPatterns()
 {}

SocketHostPatterns::~SocketHostPatterns() {}
SocketHostPatterns::SocketHostPatterns(SocketHostPatterns&& rhs)
: as_string(std::move(rhs.as_string)),
as_strings(std::move(rhs.as_strings)){
}

SocketHostPatterns& SocketHostPatterns::operator=(SocketHostPatterns&& rhs)
{
as_string = std::move(rhs.as_string);
as_strings = std::move(rhs.as_strings);
return *this;
}

// static
bool SocketHostPatterns::Populate(
    const base::Value& value, SocketHostPatterns* out, base::string16* error) {
  DCHECK(error);
  if (value.type() == base::Value::Type::STRING) {
    {
      std::string temp;
      if (!(&value)->GetAsString(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'string': expected string, got " + std::string(base::Value::GetTypeName((&value)->type()))));
        out->as_string.reset();
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
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'strings': expected list, got " + std::string(base::Value::GetTypeName((&value)->type()))));
        out->as_strings.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->as_strings, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'SocketHostPatterns'"));
          out->as_strings.reset();
        }
      }
    }
    return true;
  }
  if (error->length())
    error->append(UTF8ToUTF16("; "));
  error->append(UTF8ToUTF16("expected string or strings, got " +  std::string(base::Value::GetTypeName(value.type()))));
  return false;
}

// static
std::unique_ptr<SocketHostPatterns> SocketHostPatterns::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<SocketHostPatterns> out(new SocketHostPatterns());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::Value> SocketHostPatterns::ToValue() const {
  std::unique_ptr<base::Value> result;
  if (as_string) {
    DCHECK(!result) << "Cannot set multiple choices for socket_host_patterns";
    result = std::make_unique<base::Value>(*as_string);

  }
  if (as_strings) {
    DCHECK(!result) << "Cannot set multiple choices for socket_host_patterns";
    result = json_schema_compiler::util::CreateValueFromOptionalArray(as_strings);

  }
  DCHECK(result) << "Must set at least one choice for socket_host_patterns";
  return result;
}


Sockets::Udp::Udp()
 {}

Sockets::Udp::~Udp() {}
Sockets::Udp::Udp(Udp&& rhs)
: bind(std::move(rhs.bind)),
send(std::move(rhs.send)),
multicast_membership(std::move(rhs.multicast_membership)){
}

Sockets::Udp& Sockets::Udp::operator=(Udp&& rhs)
{
bind = std::move(rhs.bind);
send = std::move(rhs.send);
multicast_membership = std::move(rhs.multicast_membership);
return *this;
}

// static
bool Sockets::Udp::Populate(
    const base::Value& value, Udp* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("bind");
  const base::Value* bind_value = NULL;
  if (dict->GetWithoutPathExpansion("bind", &bind_value)) {
    {
      std::unique_ptr<SocketHostPatterns> temp(new SocketHostPatterns());
      if (!SocketHostPatterns::Populate(*bind_value, temp.get(), error))
        return false;
      out->bind = std::move(temp);
    }
  }

  keys.insert("send");
  const base::Value* send_value = NULL;
  if (dict->GetWithoutPathExpansion("send", &send_value)) {
    {
      std::unique_ptr<SocketHostPatterns> temp(new SocketHostPatterns());
      if (!SocketHostPatterns::Populate(*send_value, temp.get(), error))
        return false;
      out->send = std::move(temp);
    }
  }

  keys.insert("multicastMembership");
  const base::Value* multicast_membership_value = NULL;
  if (dict->GetWithoutPathExpansion("multicastMembership", &multicast_membership_value)) {
    {
      std::unique_ptr<SocketHostPatterns> temp(new SocketHostPatterns());
      if (!SocketHostPatterns::Populate(*multicast_membership_value, temp.get(), error))
        return false;
      out->multicast_membership = std::move(temp);
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

std::unique_ptr<base::DictionaryValue> Sockets::Udp::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->bind.get()) {
    to_value_result->SetWithoutPathExpansion("bind", (this->bind)->ToValue());

  }
  if (this->send.get()) {
    to_value_result->SetWithoutPathExpansion("send", (this->send)->ToValue());

  }
  if (this->multicast_membership.get()) {
    to_value_result->SetWithoutPathExpansion("multicastMembership", (this->multicast_membership)->ToValue());

  }

  return to_value_result;
}


Sockets::Tcp::Tcp()
 {}

Sockets::Tcp::~Tcp() {}
Sockets::Tcp::Tcp(Tcp&& rhs)
: connect(std::move(rhs.connect)){
}

Sockets::Tcp& Sockets::Tcp::operator=(Tcp&& rhs)
{
connect = std::move(rhs.connect);
return *this;
}

// static
bool Sockets::Tcp::Populate(
    const base::Value& value, Tcp* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("connect");
  const base::Value* connect_value = NULL;
  if (dict->GetWithoutPathExpansion("connect", &connect_value)) {
    {
      std::unique_ptr<SocketHostPatterns> temp(new SocketHostPatterns());
      if (!SocketHostPatterns::Populate(*connect_value, temp.get(), error))
        return false;
      out->connect = std::move(temp);
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

std::unique_ptr<base::DictionaryValue> Sockets::Tcp::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->connect.get()) {
    to_value_result->SetWithoutPathExpansion("connect", (this->connect)->ToValue());

  }

  return to_value_result;
}


Sockets::TcpServer::TcpServer()
 {}

Sockets::TcpServer::~TcpServer() {}
Sockets::TcpServer::TcpServer(TcpServer&& rhs)
: listen(std::move(rhs.listen)){
}

Sockets::TcpServer& Sockets::TcpServer::operator=(TcpServer&& rhs)
{
listen = std::move(rhs.listen);
return *this;
}

// static
bool Sockets::TcpServer::Populate(
    const base::Value& value, TcpServer* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("listen");
  const base::Value* listen_value = NULL;
  if (dict->GetWithoutPathExpansion("listen", &listen_value)) {
    {
      std::unique_ptr<SocketHostPatterns> temp(new SocketHostPatterns());
      if (!SocketHostPatterns::Populate(*listen_value, temp.get(), error))
        return false;
      out->listen = std::move(temp);
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

std::unique_ptr<base::DictionaryValue> Sockets::TcpServer::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->listen.get()) {
    to_value_result->SetWithoutPathExpansion("listen", (this->listen)->ToValue());

  }

  return to_value_result;
}



Sockets::Sockets()
 {}

Sockets::~Sockets() {}
Sockets::Sockets(Sockets&& rhs)
: udp(std::move(rhs.udp)),
tcp(std::move(rhs.tcp)),
tcp_server(std::move(rhs.tcp_server)){
}

Sockets& Sockets::operator=(Sockets&& rhs)
{
udp = std::move(rhs.udp);
tcp = std::move(rhs.tcp);
tcp_server = std::move(rhs.tcp_server);
return *this;
}

// static
bool Sockets::Populate(
    const base::Value& value, Sockets* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("udp");
  const base::Value* udp_value = NULL;
  if (dict->GetWithoutPathExpansion("udp", &udp_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!udp_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'udp': expected dictionary, got " + std::string(base::Value::GetTypeName(udp_value->type()))));
      }
      else {
        std::unique_ptr<Udp> temp(new Udp());
        if (!Udp::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->udp = std::move(temp);
      }
    }
  }

  keys.insert("tcp");
  const base::Value* tcp_value = NULL;
  if (dict->GetWithoutPathExpansion("tcp", &tcp_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tcp_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'tcp': expected dictionary, got " + std::string(base::Value::GetTypeName(tcp_value->type()))));
      }
      else {
        std::unique_ptr<Tcp> temp(new Tcp());
        if (!Tcp::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->tcp = std::move(temp);
      }
    }
  }

  keys.insert("tcpServer");
  const base::Value* tcp_server_value = NULL;
  if (dict->GetWithoutPathExpansion("tcpServer", &tcp_server_value)) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!tcp_server_value->GetAsDictionary(&dictionary)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'tcpServer': expected dictionary, got " + std::string(base::Value::GetTypeName(tcp_server_value->type()))));
      }
      else {
        std::unique_ptr<TcpServer> temp(new TcpServer());
        if (!TcpServer::Populate(*dictionary, temp.get(), error)) {
          return false;
        }
        else
          out->tcp_server = std::move(temp);
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
std::unique_ptr<Sockets> Sockets::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<Sockets> out(new Sockets());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Sockets::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->udp.get()) {
    to_value_result->SetWithoutPathExpansion("udp", (this->udp)->ToValue());

  }
  if (this->tcp.get()) {
    to_value_result->SetWithoutPathExpansion("tcp", (this->tcp)->ToValue());

  }
  if (this->tcp_server.get()) {
    to_value_result->SetWithoutPathExpansion("tcpServer", (this->tcp_server)->ToValue());

  }

  return to_value_result;
}


Bluetooth::Bluetooth()
 {}

Bluetooth::~Bluetooth() {}
Bluetooth::Bluetooth(Bluetooth&& rhs)
: uuids(std::move(rhs.uuids)),
socket(std::move(rhs.socket)),
low_energy(std::move(rhs.low_energy)),
peripheral(std::move(rhs.peripheral)){
}

Bluetooth& Bluetooth::operator=(Bluetooth&& rhs)
{
uuids = std::move(rhs.uuids);
socket = std::move(rhs.socket);
low_energy = std::move(rhs.low_energy);
peripheral = std::move(rhs.peripheral);
return *this;
}

// static
bool Bluetooth::Populate(
    const base::Value& value, Bluetooth* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("uuids");
  const base::Value* uuids_value = NULL;
  if (dict->GetWithoutPathExpansion("uuids", &uuids_value)) {
    {
      const base::ListValue* list = NULL;
      if (!uuids_value->GetAsList(&list)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'uuids': expected list, got " + std::string(base::Value::GetTypeName(uuids_value->type()))));
        out->uuids.reset();
      }
      else {
        if (!json_schema_compiler::util::PopulateOptionalArrayFromList(*list, &out->uuids, error)) {
          if (error->length())
            error->append(UTF8ToUTF16("; "));
          error->append(UTF8ToUTF16("unable to populate array 'bluetooth'"));
          out->uuids.reset();
        }
      }
    }
  }

  keys.insert("socket");
  const base::Value* socket_value = NULL;
  if (dict->GetWithoutPathExpansion("socket", &socket_value)) {
    {
      bool temp;
      if (!socket_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'socket': expected socket, got " + std::string(base::Value::GetTypeName(socket_value->type()))));
        out->socket.reset();
      }
      else
        out->socket.reset(new bool(temp));
    }
  }

  keys.insert("low_energy");
  const base::Value* low_energy_value = NULL;
  if (dict->GetWithoutPathExpansion("low_energy", &low_energy_value)) {
    {
      bool temp;
      if (!low_energy_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'low_energy': expected low_energy, got " + std::string(base::Value::GetTypeName(low_energy_value->type()))));
        out->low_energy.reset();
      }
      else
        out->low_energy.reset(new bool(temp));
    }
  }

  keys.insert("peripheral");
  const base::Value* peripheral_value = NULL;
  if (dict->GetWithoutPathExpansion("peripheral", &peripheral_value)) {
    {
      bool temp;
      if (!peripheral_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'peripheral': expected peripheral, got " + std::string(base::Value::GetTypeName(peripheral_value->type()))));
        out->peripheral.reset();
      }
      else
        out->peripheral.reset(new bool(temp));
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
std::unique_ptr<Bluetooth> Bluetooth::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<Bluetooth> out(new Bluetooth());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Bluetooth::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  if (this->uuids.get()) {
    to_value_result->SetWithoutPathExpansion("uuids", json_schema_compiler::util::CreateValueFromOptionalArray(this->uuids));

  }
  if (this->socket.get()) {
    to_value_result->SetWithoutPathExpansion("socket", std::make_unique<base::Value>(*this->socket));

  }
  if (this->low_energy.get()) {
    to_value_result->SetWithoutPathExpansion("low_energy", std::make_unique<base::Value>(*this->low_energy));

  }
  if (this->peripheral.get()) {
    to_value_result->SetWithoutPathExpansion("peripheral", std::make_unique<base::Value>(*this->peripheral));

  }

  return to_value_result;
}


UsbPrinters::FiltersType::FiltersType()
: vendor_id(0) {}

UsbPrinters::FiltersType::~FiltersType() {}
UsbPrinters::FiltersType::FiltersType(FiltersType&& rhs)
: vendor_id(rhs.vendor_id),
product_id(std::move(rhs.product_id)),
interface_class(std::move(rhs.interface_class)),
interface_subclass(std::move(rhs.interface_subclass)),
interface_protocol(std::move(rhs.interface_protocol)){
}

UsbPrinters::FiltersType& UsbPrinters::FiltersType::operator=(FiltersType&& rhs)
{
vendor_id = rhs.vendor_id;
product_id = std::move(rhs.product_id);
interface_class = std::move(rhs.interface_class);
interface_subclass = std::move(rhs.interface_subclass);
interface_protocol = std::move(rhs.interface_protocol);
return *this;
}

// static
bool UsbPrinters::FiltersType::Populate(
    const base::Value& value, FiltersType* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("vendorId");
  const base::Value* vendor_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("vendorId", &vendor_id_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'vendorId' is required"));
    return false;
  }
  {
    if (!vendor_id_value->GetAsInteger(&out->vendor_id)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'vendorId': expected vendorId, got " + std::string(base::Value::GetTypeName(vendor_id_value->type()))));
      return false;
    }
  }

  keys.insert("productId");
  const base::Value* product_id_value = NULL;
  if (dict->GetWithoutPathExpansion("productId", &product_id_value)) {
    {
      int temp;
      if (!product_id_value->GetAsInteger(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'productId': expected productId, got " + std::string(base::Value::GetTypeName(product_id_value->type()))));
        out->product_id.reset();
      }
      else
        out->product_id.reset(new int(temp));
    }
  }

  keys.insert("interfaceClass");
  const base::Value* interface_class_value = NULL;
  if (dict->GetWithoutPathExpansion("interfaceClass", &interface_class_value)) {
    {
      int temp;
      if (!interface_class_value->GetAsInteger(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'interfaceClass': expected interfaceClass, got " + std::string(base::Value::GetTypeName(interface_class_value->type()))));
        out->interface_class.reset();
      }
      else
        out->interface_class.reset(new int(temp));
    }
  }

  keys.insert("interfaceSubclass");
  const base::Value* interface_subclass_value = NULL;
  if (dict->GetWithoutPathExpansion("interfaceSubclass", &interface_subclass_value)) {
    {
      int temp;
      if (!interface_subclass_value->GetAsInteger(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'interfaceSubclass': expected interfaceSubclass, got " + std::string(base::Value::GetTypeName(interface_subclass_value->type()))));
        out->interface_subclass.reset();
      }
      else
        out->interface_subclass.reset(new int(temp));
    }
  }

  keys.insert("interfaceProtocol");
  const base::Value* interface_protocol_value = NULL;
  if (dict->GetWithoutPathExpansion("interfaceProtocol", &interface_protocol_value)) {
    {
      int temp;
      if (!interface_protocol_value->GetAsInteger(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'interfaceProtocol': expected interfaceProtocol, got " + std::string(base::Value::GetTypeName(interface_protocol_value->type()))));
        out->interface_protocol.reset();
      }
      else
        out->interface_protocol.reset(new int(temp));
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

std::unique_ptr<base::DictionaryValue> UsbPrinters::FiltersType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("vendorId", std::make_unique<base::Value>(this->vendor_id));

  if (this->product_id.get()) {
    to_value_result->SetWithoutPathExpansion("productId", std::make_unique<base::Value>(*this->product_id));

  }
  if (this->interface_class.get()) {
    to_value_result->SetWithoutPathExpansion("interfaceClass", std::make_unique<base::Value>(*this->interface_class));

  }
  if (this->interface_subclass.get()) {
    to_value_result->SetWithoutPathExpansion("interfaceSubclass", std::make_unique<base::Value>(*this->interface_subclass));

  }
  if (this->interface_protocol.get()) {
    to_value_result->SetWithoutPathExpansion("interfaceProtocol", std::make_unique<base::Value>(*this->interface_protocol));

  }

  return to_value_result;
}




UsbPrinters::UsbPrinters()
 {}

UsbPrinters::~UsbPrinters() {}
UsbPrinters::UsbPrinters(UsbPrinters&& rhs)
: filters(std::move(rhs.filters)){
}

UsbPrinters& UsbPrinters::operator=(UsbPrinters&& rhs)
{
filters = std::move(rhs.filters);
return *this;
}

// static
bool UsbPrinters::Populate(
    const base::Value& value, UsbPrinters* out, base::string16* error) {
  DCHECK(error);
  if (!value.is_dict()) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("expected dictionary, got " + std::string(base::Value::GetTypeName(value.type()))));
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  std::set<std::string> keys;
  keys.insert("filters");
  const base::Value* filters_value = NULL;
  if (!dict->GetWithoutPathExpansion("filters", &filters_value)) {
    if (error->length())
      error->append(UTF8ToUTF16("; "));
    error->append(UTF8ToUTF16("'filters' is required"));
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!filters_value->GetAsList(&list)) {
      if (error->length())
        error->append(UTF8ToUTF16("; "));
      error->append(UTF8ToUTF16("'filters': expected list, got " + std::string(base::Value::GetTypeName(filters_value->type()))));
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->filters, error)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("unable to populate array 'UsbPrinters'"));
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
std::unique_ptr<UsbPrinters> UsbPrinters::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<UsbPrinters> out(new UsbPrinters());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> UsbPrinters::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("filters", json_schema_compiler::util::CreateValueFromArray(this->filters));


  return to_value_result;
}


KioskSecondaryAppsType::KioskSecondaryAppsType()
 {}

KioskSecondaryAppsType::~KioskSecondaryAppsType() {}
KioskSecondaryAppsType::KioskSecondaryAppsType(KioskSecondaryAppsType&& rhs)
: id(std::move(rhs.id)),
enabled_on_launch(std::move(rhs.enabled_on_launch)){
}

KioskSecondaryAppsType& KioskSecondaryAppsType::operator=(KioskSecondaryAppsType&& rhs)
{
id = std::move(rhs.id);
enabled_on_launch = std::move(rhs.enabled_on_launch);
return *this;
}

// static
bool KioskSecondaryAppsType::Populate(
    const base::Value& value, KioskSecondaryAppsType* out, base::string16* error) {
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

  keys.insert("enabled_on_launch");
  const base::Value* enabled_on_launch_value = NULL;
  if (dict->GetWithoutPathExpansion("enabled_on_launch", &enabled_on_launch_value)) {
    {
      bool temp;
      if (!enabled_on_launch_value->GetAsBoolean(&temp)) {
        if (error->length())
          error->append(UTF8ToUTF16("; "));
        error->append(UTF8ToUTF16("'enabled_on_launch': expected enabled_on_launch, got " + std::string(base::Value::GetTypeName(enabled_on_launch_value->type()))));
        out->enabled_on_launch.reset();
      }
      else
        out->enabled_on_launch.reset(new bool(temp));
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
std::unique_ptr<KioskSecondaryAppsType> KioskSecondaryAppsType::FromValue(const base::Value& value, base::string16* error) {
DCHECK(error);
  std::unique_ptr<KioskSecondaryAppsType> out(new KioskSecondaryAppsType());
  if (!Populate(value, out.get(), error))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> KioskSecondaryAppsType::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  if (this->enabled_on_launch.get()) {
    to_value_result->SetWithoutPathExpansion("enabled_on_launch", std::make_unique<base::Value>(*this->enabled_on_launch));

  }

  return to_value_result;
}




}  // namespace extensions_manifest_types
}  // namespace api
}  // namespace extensions

