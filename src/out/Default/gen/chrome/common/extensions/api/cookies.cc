// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/cookies.json
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/cookies.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace cookies {
//
// Types
//

const char* ToString(SameSiteStatus enum_param) {
  switch (enum_param) {
    case SAME_SITE_STATUS_NO_RESTRICTION:
      return "no_restriction";
    case SAME_SITE_STATUS_LAX:
      return "lax";
    case SAME_SITE_STATUS_STRICT:
      return "strict";
    case SAME_SITE_STATUS_UNSPECIFIED:
      return "unspecified";
    case SAME_SITE_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

SameSiteStatus ParseSameSiteStatus(const std::string& enum_string) {
  if (enum_string == "no_restriction")
    return SAME_SITE_STATUS_NO_RESTRICTION;
  if (enum_string == "lax")
    return SAME_SITE_STATUS_LAX;
  if (enum_string == "strict")
    return SAME_SITE_STATUS_STRICT;
  if (enum_string == "unspecified")
    return SAME_SITE_STATUS_UNSPECIFIED;
  return SAME_SITE_STATUS_NONE;
}


Cookie::Cookie()
: host_only(false),
secure(false),
http_only(false),
same_site(SAME_SITE_STATUS_NONE),
session(false) {}

Cookie::~Cookie() {}
Cookie::Cookie(Cookie&& rhs)
: name(std::move(rhs.name)),
value(std::move(rhs.value)),
domain(std::move(rhs.domain)),
host_only(rhs.host_only),
path(std::move(rhs.path)),
secure(rhs.secure),
http_only(rhs.http_only),
same_site(rhs.same_site),
session(rhs.session),
expiration_date(std::move(rhs.expiration_date)),
store_id(std::move(rhs.store_id)){
}

Cookie& Cookie::operator=(Cookie&& rhs)
{
name = std::move(rhs.name);
value = std::move(rhs.value);
domain = std::move(rhs.domain);
host_only = rhs.host_only;
path = std::move(rhs.path);
secure = rhs.secure;
http_only = rhs.http_only;
same_site = rhs.same_site;
session = rhs.session;
expiration_date = std::move(rhs.expiration_date);
store_id = std::move(rhs.store_id);
return *this;
}

// static
bool Cookie::Populate(
    const base::Value& value, Cookie* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* value_value = NULL;
  if (!dict->GetWithoutPathExpansion("value", &value_value)) {
    return false;
  }
  {
    if (!value_value->GetAsString(&out->value)) {
      return false;
    }
  }

  const base::Value* domain_value = NULL;
  if (!dict->GetWithoutPathExpansion("domain", &domain_value)) {
    return false;
  }
  {
    if (!domain_value->GetAsString(&out->domain)) {
      return false;
    }
  }

  const base::Value* host_only_value = NULL;
  if (!dict->GetWithoutPathExpansion("hostOnly", &host_only_value)) {
    return false;
  }
  {
    if (!host_only_value->GetAsBoolean(&out->host_only)) {
      return false;
    }
  }

  const base::Value* path_value = NULL;
  if (!dict->GetWithoutPathExpansion("path", &path_value)) {
    return false;
  }
  {
    if (!path_value->GetAsString(&out->path)) {
      return false;
    }
  }

  const base::Value* secure_value = NULL;
  if (!dict->GetWithoutPathExpansion("secure", &secure_value)) {
    return false;
  }
  {
    if (!secure_value->GetAsBoolean(&out->secure)) {
      return false;
    }
  }

  const base::Value* http_only_value = NULL;
  if (!dict->GetWithoutPathExpansion("httpOnly", &http_only_value)) {
    return false;
  }
  {
    if (!http_only_value->GetAsBoolean(&out->http_only)) {
      return false;
    }
  }

  const base::Value* same_site_value = NULL;
  if (!dict->GetWithoutPathExpansion("sameSite", &same_site_value)) {
    return false;
  }
  {
    std::string same_site_status_as_string;
    if (!same_site_value->GetAsString(&same_site_status_as_string)) {
      return false;
    }
    out->same_site = ParseSameSiteStatus(same_site_status_as_string);
    if (out->same_site == SAME_SITE_STATUS_NONE) {
      return false;
    }
  }

  const base::Value* session_value = NULL;
  if (!dict->GetWithoutPathExpansion("session", &session_value)) {
    return false;
  }
  {
    if (!session_value->GetAsBoolean(&out->session)) {
      return false;
    }
  }

  const base::Value* expiration_date_value = NULL;
  if (dict->GetWithoutPathExpansion("expirationDate", &expiration_date_value)) {
    {
      double temp;
      if (!expiration_date_value->GetAsDouble(&temp)) {
        out->expiration_date.reset();
        return false;
      }
      else
        out->expiration_date.reset(new double(temp));
    }
  }

  const base::Value* store_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("storeId", &store_id_value)) {
    return false;
  }
  {
    if (!store_id_value->GetAsString(&out->store_id)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Cookie> Cookie::FromValue(const base::Value& value) {
  std::unique_ptr<Cookie> out(new Cookie());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Cookie::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("value", std::make_unique<base::Value>(this->value));

  to_value_result->SetWithoutPathExpansion("domain", std::make_unique<base::Value>(this->domain));

  to_value_result->SetWithoutPathExpansion("hostOnly", std::make_unique<base::Value>(this->host_only));

  to_value_result->SetWithoutPathExpansion("path", std::make_unique<base::Value>(this->path));

  to_value_result->SetWithoutPathExpansion("secure", std::make_unique<base::Value>(this->secure));

  to_value_result->SetWithoutPathExpansion("httpOnly", std::make_unique<base::Value>(this->http_only));

  to_value_result->SetWithoutPathExpansion("sameSite", std::make_unique<base::Value>(cookies::ToString(this->same_site)));

  to_value_result->SetWithoutPathExpansion("session", std::make_unique<base::Value>(this->session));

  if (this->expiration_date.get()) {
    to_value_result->SetWithoutPathExpansion("expirationDate", std::make_unique<base::Value>(*this->expiration_date));

  }
  to_value_result->SetWithoutPathExpansion("storeId", std::make_unique<base::Value>(this->store_id));


  return to_value_result;
}


CookieStore::CookieStore()
 {}

CookieStore::~CookieStore() {}
CookieStore::CookieStore(CookieStore&& rhs)
: id(std::move(rhs.id)),
tab_ids(std::move(rhs.tab_ids)){
}

CookieStore& CookieStore::operator=(CookieStore&& rhs)
{
id = std::move(rhs.id);
tab_ids = std::move(rhs.tab_ids);
return *this;
}

// static
bool CookieStore::Populate(
    const base::Value& value, CookieStore* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsString(&out->id)) {
      return false;
    }
  }

  const base::Value* tab_ids_value = NULL;
  if (!dict->GetWithoutPathExpansion("tabIds", &tab_ids_value)) {
    return false;
  }
  {
    const base::ListValue* list = NULL;
    if (!tab_ids_value->GetAsList(&list)) {
      return false;
    }
    else {
      if (!json_schema_compiler::util::PopulateArrayFromList(*list, &out->tab_ids)) {
        return false;
      }
    }
  }

  return true;
}

// static
std::unique_ptr<CookieStore> CookieStore::FromValue(const base::Value& value) {
  std::unique_ptr<CookieStore> out(new CookieStore());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CookieStore::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("tabIds", json_schema_compiler::util::CreateValueFromArray(this->tab_ids));


  return to_value_result;
}


const char* ToString(OnChangedCause enum_param) {
  switch (enum_param) {
    case ON_CHANGED_CAUSE_EVICTED:
      return "evicted";
    case ON_CHANGED_CAUSE_EXPIRED:
      return "expired";
    case ON_CHANGED_CAUSE_EXPLICIT:
      return "explicit";
    case ON_CHANGED_CAUSE_EXPIRED_OVERWRITE:
      return "expired_overwrite";
    case ON_CHANGED_CAUSE_OVERWRITE:
      return "overwrite";
    case ON_CHANGED_CAUSE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

OnChangedCause ParseOnChangedCause(const std::string& enum_string) {
  if (enum_string == "evicted")
    return ON_CHANGED_CAUSE_EVICTED;
  if (enum_string == "expired")
    return ON_CHANGED_CAUSE_EXPIRED;
  if (enum_string == "explicit")
    return ON_CHANGED_CAUSE_EXPLICIT;
  if (enum_string == "expired_overwrite")
    return ON_CHANGED_CAUSE_EXPIRED_OVERWRITE;
  if (enum_string == "overwrite")
    return ON_CHANGED_CAUSE_OVERWRITE;
  return ON_CHANGED_CAUSE_NONE;
}



//
// Functions
//

namespace Get {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: url(std::move(rhs.url)),
name(std::move(rhs.name)),
store_id(std::move(rhs.store_id)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
name = std::move(rhs.name);
store_id = std::move(rhs.store_id);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* store_id_value = NULL;
  if (dict->GetWithoutPathExpansion("storeId", &store_id_value)) {
    {
      std::string temp;
      if (!store_id_value->GetAsString(&temp)) {
        out->store_id.reset();
        return false;
      }
      else
        out->store_id.reset(new std::string(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Details::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Cookie& cookie) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((cookie).ToValue());

  return create_results;
}
}  // namespace Get

namespace GetAll {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: url(std::move(rhs.url)),
name(std::move(rhs.name)),
domain(std::move(rhs.domain)),
path(std::move(rhs.path)),
secure(std::move(rhs.secure)),
session(std::move(rhs.session)),
store_id(std::move(rhs.store_id)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
name = std::move(rhs.name);
domain = std::move(rhs.domain);
path = std::move(rhs.path);
secure = std::move(rhs.secure);
session = std::move(rhs.session);
store_id = std::move(rhs.store_id);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
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

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* domain_value = NULL;
  if (dict->GetWithoutPathExpansion("domain", &domain_value)) {
    {
      std::string temp;
      if (!domain_value->GetAsString(&temp)) {
        out->domain.reset();
        return false;
      }
      else
        out->domain.reset(new std::string(temp));
    }
  }

  const base::Value* path_value = NULL;
  if (dict->GetWithoutPathExpansion("path", &path_value)) {
    {
      std::string temp;
      if (!path_value->GetAsString(&temp)) {
        out->path.reset();
        return false;
      }
      else
        out->path.reset(new std::string(temp));
    }
  }

  const base::Value* secure_value = NULL;
  if (dict->GetWithoutPathExpansion("secure", &secure_value)) {
    {
      bool temp;
      if (!secure_value->GetAsBoolean(&temp)) {
        out->secure.reset();
        return false;
      }
      else
        out->secure.reset(new bool(temp));
    }
  }

  const base::Value* session_value = NULL;
  if (dict->GetWithoutPathExpansion("session", &session_value)) {
    {
      bool temp;
      if (!session_value->GetAsBoolean(&temp)) {
        out->session.reset();
        return false;
      }
      else
        out->session.reset(new bool(temp));
    }
  }

  const base::Value* store_id_value = NULL;
  if (dict->GetWithoutPathExpansion("storeId", &store_id_value)) {
    {
      std::string temp;
      if (!store_id_value->GetAsString(&temp)) {
        out->store_id.reset();
        return false;
      }
      else
        out->store_id.reset(new std::string(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Details::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::vector<Cookie>& cookies) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(cookies));

  return create_results;
}
}  // namespace GetAll

namespace Set {

Params::Details::Details()
: same_site(SAME_SITE_STATUS_NONE) {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: url(std::move(rhs.url)),
name(std::move(rhs.name)),
value(std::move(rhs.value)),
domain(std::move(rhs.domain)),
path(std::move(rhs.path)),
secure(std::move(rhs.secure)),
http_only(std::move(rhs.http_only)),
same_site(rhs.same_site),
expiration_date(std::move(rhs.expiration_date)),
store_id(std::move(rhs.store_id)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
name = std::move(rhs.name);
value = std::move(rhs.value);
domain = std::move(rhs.domain);
path = std::move(rhs.path);
secure = std::move(rhs.secure);
http_only = std::move(rhs.http_only);
same_site = rhs.same_site;
expiration_date = std::move(rhs.expiration_date);
store_id = std::move(rhs.store_id);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  out->same_site = SAME_SITE_STATUS_NONE;
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (dict->GetWithoutPathExpansion("name", &name_value)) {
    {
      std::string temp;
      if (!name_value->GetAsString(&temp)) {
        out->name.reset();
        return false;
      }
      else
        out->name.reset(new std::string(temp));
    }
  }

  const base::Value* value_value = NULL;
  if (dict->GetWithoutPathExpansion("value", &value_value)) {
    {
      std::string temp;
      if (!value_value->GetAsString(&temp)) {
        out->value.reset();
        return false;
      }
      else
        out->value.reset(new std::string(temp));
    }
  }

  const base::Value* domain_value = NULL;
  if (dict->GetWithoutPathExpansion("domain", &domain_value)) {
    {
      std::string temp;
      if (!domain_value->GetAsString(&temp)) {
        out->domain.reset();
        return false;
      }
      else
        out->domain.reset(new std::string(temp));
    }
  }

  const base::Value* path_value = NULL;
  if (dict->GetWithoutPathExpansion("path", &path_value)) {
    {
      std::string temp;
      if (!path_value->GetAsString(&temp)) {
        out->path.reset();
        return false;
      }
      else
        out->path.reset(new std::string(temp));
    }
  }

  const base::Value* secure_value = NULL;
  if (dict->GetWithoutPathExpansion("secure", &secure_value)) {
    {
      bool temp;
      if (!secure_value->GetAsBoolean(&temp)) {
        out->secure.reset();
        return false;
      }
      else
        out->secure.reset(new bool(temp));
    }
  }

  const base::Value* http_only_value = NULL;
  if (dict->GetWithoutPathExpansion("httpOnly", &http_only_value)) {
    {
      bool temp;
      if (!http_only_value->GetAsBoolean(&temp)) {
        out->http_only.reset();
        return false;
      }
      else
        out->http_only.reset(new bool(temp));
    }
  }

  const base::Value* same_site_value = NULL;
  if (dict->GetWithoutPathExpansion("sameSite", &same_site_value)) {
    {
      std::string same_site_status_as_string;
      if (!same_site_value->GetAsString(&same_site_status_as_string)) {
        return false;
      }
      out->same_site = ParseSameSiteStatus(same_site_status_as_string);
      if (out->same_site == SAME_SITE_STATUS_NONE) {
        return false;
      }
    }
    } else {
    out->same_site = SAME_SITE_STATUS_NONE;
  }

  const base::Value* expiration_date_value = NULL;
  if (dict->GetWithoutPathExpansion("expirationDate", &expiration_date_value)) {
    {
      double temp;
      if (!expiration_date_value->GetAsDouble(&temp)) {
        out->expiration_date.reset();
        return false;
      }
      else
        out->expiration_date.reset(new double(temp));
    }
  }

  const base::Value* store_id_value = NULL;
  if (dict->GetWithoutPathExpansion("storeId", &store_id_value)) {
    {
      std::string temp;
      if (!store_id_value->GetAsString(&temp)) {
        out->store_id.reset();
        return false;
      }
      else
        out->store_id.reset(new std::string(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Details::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const Cookie& cookie) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((cookie).ToValue());

  return create_results;
}
}  // namespace Set

namespace Remove {

Params::Details::Details()
 {}

Params::Details::~Details() {}
Params::Details::Details(Details&& rhs)
: url(std::move(rhs.url)),
name(std::move(rhs.name)),
store_id(std::move(rhs.store_id)){
}

Params::Details& Params::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
name = std::move(rhs.name);
store_id = std::move(rhs.store_id);
return *this;
}

// static
bool Params::Details::Populate(
    const base::Value& value, Details* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* url_value = NULL;
  if (!dict->GetWithoutPathExpansion("url", &url_value)) {
    return false;
  }
  {
    if (!url_value->GetAsString(&out->url)) {
      return false;
    }
  }

  const base::Value* name_value = NULL;
  if (!dict->GetWithoutPathExpansion("name", &name_value)) {
    return false;
  }
  {
    if (!name_value->GetAsString(&out->name)) {
      return false;
    }
  }

  const base::Value* store_id_value = NULL;
  if (dict->GetWithoutPathExpansion("storeId", &store_id_value)) {
    {
      std::string temp;
      if (!store_id_value->GetAsString(&temp)) {
        out->store_id.reset();
        return false;
      }
      else
        out->store_id.reset(new std::string(temp));
    }
  }

  return true;
}


Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* details_value = NULL;
  if (args.Get(0, &details_value) &&
      !details_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!details_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!Details::Populate(*dictionary, &params->details)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


Results::Details::Details()
 {}

Results::Details::~Details() {}
Results::Details::Details(Details&& rhs)
: url(std::move(rhs.url)),
name(std::move(rhs.name)),
store_id(std::move(rhs.store_id)){
}

Results::Details& Results::Details::operator=(Details&& rhs)
{
url = std::move(rhs.url);
name = std::move(rhs.name);
store_id = std::move(rhs.store_id);
return *this;
}

std::unique_ptr<base::DictionaryValue> Results::Details::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("url", std::make_unique<base::Value>(this->url));

  to_value_result->SetWithoutPathExpansion("name", std::make_unique<base::Value>(this->name));

  to_value_result->SetWithoutPathExpansion("storeId", std::make_unique<base::Value>(this->store_id));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Results::Create(const Details& details) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((details).ToValue());

  return create_results;
}
}  // namespace Remove

namespace GetAllCookieStores {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<CookieStore>& cookie_stores) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(cookie_stores));

  return create_results;
}
}  // namespace GetAllCookieStores

//
// Events
//

namespace OnChanged {

const char kEventName[] = "cookies.onChanged";

ChangeInfo::ChangeInfo()
: removed(false),
cause(ON_CHANGED_CAUSE_NONE) {}

ChangeInfo::~ChangeInfo() {}
ChangeInfo::ChangeInfo(ChangeInfo&& rhs)
: removed(rhs.removed),
cookie(std::move(rhs.cookie)),
cause(rhs.cause){
}

ChangeInfo& ChangeInfo::operator=(ChangeInfo&& rhs)
{
removed = rhs.removed;
cookie = std::move(rhs.cookie);
cause = rhs.cause;
return *this;
}

std::unique_ptr<base::DictionaryValue> ChangeInfo::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("removed", std::make_unique<base::Value>(this->removed));

  to_value_result->SetWithoutPathExpansion("cookie", (this->cookie).ToValue());

  to_value_result->SetWithoutPathExpansion("cause", std::make_unique<base::Value>(cookies::ToString(this->cause)));


  return to_value_result;
}


std::unique_ptr<base::ListValue> Create(const ChangeInfo& change_info) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((change_info).ToValue());

  return create_results;
}

}  // namespace OnChanged

}  // namespace cookies
}  // namespace api
}  // namespace extensions

