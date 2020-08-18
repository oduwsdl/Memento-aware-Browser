// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/passwords_private.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "chrome/common/extensions/api/passwords_private.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace passwords_private {
//
// Types
//

const char* ToString(PlaintextReason enum_param) {
  switch (enum_param) {
    case PLAINTEXT_REASON_VIEW:
      return "VIEW";
    case PLAINTEXT_REASON_COPY:
      return "COPY";
    case PLAINTEXT_REASON_EDIT:
      return "EDIT";
    case PLAINTEXT_REASON_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PlaintextReason ParsePlaintextReason(const std::string& enum_string) {
  if (enum_string == "VIEW")
    return PLAINTEXT_REASON_VIEW;
  if (enum_string == "COPY")
    return PLAINTEXT_REASON_COPY;
  if (enum_string == "EDIT")
    return PLAINTEXT_REASON_EDIT;
  return PLAINTEXT_REASON_NONE;
}


const char* ToString(ExportProgressStatus enum_param) {
  switch (enum_param) {
    case EXPORT_PROGRESS_STATUS_NOT_STARTED:
      return "NOT_STARTED";
    case EXPORT_PROGRESS_STATUS_IN_PROGRESS:
      return "IN_PROGRESS";
    case EXPORT_PROGRESS_STATUS_SUCCEEDED:
      return "SUCCEEDED";
    case EXPORT_PROGRESS_STATUS_FAILED_CANCELLED:
      return "FAILED_CANCELLED";
    case EXPORT_PROGRESS_STATUS_FAILED_WRITE_FAILED:
      return "FAILED_WRITE_FAILED";
    case EXPORT_PROGRESS_STATUS_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ExportProgressStatus ParseExportProgressStatus(const std::string& enum_string) {
  if (enum_string == "NOT_STARTED")
    return EXPORT_PROGRESS_STATUS_NOT_STARTED;
  if (enum_string == "IN_PROGRESS")
    return EXPORT_PROGRESS_STATUS_IN_PROGRESS;
  if (enum_string == "SUCCEEDED")
    return EXPORT_PROGRESS_STATUS_SUCCEEDED;
  if (enum_string == "FAILED_CANCELLED")
    return EXPORT_PROGRESS_STATUS_FAILED_CANCELLED;
  if (enum_string == "FAILED_WRITE_FAILED")
    return EXPORT_PROGRESS_STATUS_FAILED_WRITE_FAILED;
  return EXPORT_PROGRESS_STATUS_NONE;
}


const char* ToString(CompromiseType enum_param) {
  switch (enum_param) {
    case COMPROMISE_TYPE_LEAKED:
      return "LEAKED";
    case COMPROMISE_TYPE_PHISHED:
      return "PHISHED";
    case COMPROMISE_TYPE_PHISHED_AND_LEAKED:
      return "PHISHED_AND_LEAKED";
    case COMPROMISE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

CompromiseType ParseCompromiseType(const std::string& enum_string) {
  if (enum_string == "LEAKED")
    return COMPROMISE_TYPE_LEAKED;
  if (enum_string == "PHISHED")
    return COMPROMISE_TYPE_PHISHED;
  if (enum_string == "PHISHED_AND_LEAKED")
    return COMPROMISE_TYPE_PHISHED_AND_LEAKED;
  return COMPROMISE_TYPE_NONE;
}


const char* ToString(PasswordCheckState enum_param) {
  switch (enum_param) {
    case PASSWORD_CHECK_STATE_IDLE:
      return "IDLE";
    case PASSWORD_CHECK_STATE_RUNNING:
      return "RUNNING";
    case PASSWORD_CHECK_STATE_CANCELED:
      return "CANCELED";
    case PASSWORD_CHECK_STATE_OFFLINE:
      return "OFFLINE";
    case PASSWORD_CHECK_STATE_SIGNED_OUT:
      return "SIGNED_OUT";
    case PASSWORD_CHECK_STATE_NO_PASSWORDS:
      return "NO_PASSWORDS";
    case PASSWORD_CHECK_STATE_QUOTA_LIMIT:
      return "QUOTA_LIMIT";
    case PASSWORD_CHECK_STATE_OTHER_ERROR:
      return "OTHER_ERROR";
    case PASSWORD_CHECK_STATE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

PasswordCheckState ParsePasswordCheckState(const std::string& enum_string) {
  if (enum_string == "IDLE")
    return PASSWORD_CHECK_STATE_IDLE;
  if (enum_string == "RUNNING")
    return PASSWORD_CHECK_STATE_RUNNING;
  if (enum_string == "CANCELED")
    return PASSWORD_CHECK_STATE_CANCELED;
  if (enum_string == "OFFLINE")
    return PASSWORD_CHECK_STATE_OFFLINE;
  if (enum_string == "SIGNED_OUT")
    return PASSWORD_CHECK_STATE_SIGNED_OUT;
  if (enum_string == "NO_PASSWORDS")
    return PASSWORD_CHECK_STATE_NO_PASSWORDS;
  if (enum_string == "QUOTA_LIMIT")
    return PASSWORD_CHECK_STATE_QUOTA_LIMIT;
  if (enum_string == "OTHER_ERROR")
    return PASSWORD_CHECK_STATE_OTHER_ERROR;
  return PASSWORD_CHECK_STATE_NONE;
}


UrlCollection::UrlCollection()
 {}

UrlCollection::~UrlCollection() {}
UrlCollection::UrlCollection(UrlCollection&& rhs)
: origin(std::move(rhs.origin)),
shown(std::move(rhs.shown)),
link(std::move(rhs.link)){
}

UrlCollection& UrlCollection::operator=(UrlCollection&& rhs)
{
origin = std::move(rhs.origin);
shown = std::move(rhs.shown);
link = std::move(rhs.link);
return *this;
}

// static
bool UrlCollection::Populate(
    const base::Value& value, UrlCollection* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* origin_value = NULL;
  if (!dict->GetWithoutPathExpansion("origin", &origin_value)) {
    return false;
  }
  {
    if (!origin_value->GetAsString(&out->origin)) {
      return false;
    }
  }

  const base::Value* shown_value = NULL;
  if (!dict->GetWithoutPathExpansion("shown", &shown_value)) {
    return false;
  }
  {
    if (!shown_value->GetAsString(&out->shown)) {
      return false;
    }
  }

  const base::Value* link_value = NULL;
  if (!dict->GetWithoutPathExpansion("link", &link_value)) {
    return false;
  }
  {
    if (!link_value->GetAsString(&out->link)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<UrlCollection> UrlCollection::FromValue(const base::Value& value) {
  std::unique_ptr<UrlCollection> out(new UrlCollection());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> UrlCollection::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("origin", std::make_unique<base::Value>(this->origin));

  to_value_result->SetWithoutPathExpansion("shown", std::make_unique<base::Value>(this->shown));

  to_value_result->SetWithoutPathExpansion("link", std::make_unique<base::Value>(this->link));


  return to_value_result;
}


PasswordUiEntry::PasswordUiEntry()
: id(0),
frontend_id(0),
from_account_store(false) {}

PasswordUiEntry::~PasswordUiEntry() {}
PasswordUiEntry::PasswordUiEntry(PasswordUiEntry&& rhs)
: urls(std::move(rhs.urls)),
username(std::move(rhs.username)),
federation_text(std::move(rhs.federation_text)),
id(rhs.id),
frontend_id(rhs.frontend_id),
from_account_store(rhs.from_account_store){
}

PasswordUiEntry& PasswordUiEntry::operator=(PasswordUiEntry&& rhs)
{
urls = std::move(rhs.urls);
username = std::move(rhs.username);
federation_text = std::move(rhs.federation_text);
id = rhs.id;
frontend_id = rhs.frontend_id;
from_account_store = rhs.from_account_store;
return *this;
}

// static
bool PasswordUiEntry::Populate(
    const base::Value& value, PasswordUiEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* urls_value = NULL;
  if (!dict->GetWithoutPathExpansion("urls", &urls_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!urls_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!UrlCollection::Populate(*dictionary, &out->urls)) {
      return false;
    }
  }

  const base::Value* username_value = NULL;
  if (!dict->GetWithoutPathExpansion("username", &username_value)) {
    return false;
  }
  {
    if (!username_value->GetAsString(&out->username)) {
      return false;
    }
  }

  const base::Value* federation_text_value = NULL;
  if (dict->GetWithoutPathExpansion("federationText", &federation_text_value)) {
    {
      std::string temp;
      if (!federation_text_value->GetAsString(&temp)) {
        out->federation_text.reset();
        return false;
      }
      else
        out->federation_text.reset(new std::string(temp));
    }
  }

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* frontend_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("frontendId", &frontend_id_value)) {
    return false;
  }
  {
    if (!frontend_id_value->GetAsInteger(&out->frontend_id)) {
      return false;
    }
  }

  const base::Value* from_account_store_value = NULL;
  if (!dict->GetWithoutPathExpansion("fromAccountStore", &from_account_store_value)) {
    return false;
  }
  {
    if (!from_account_store_value->GetAsBoolean(&out->from_account_store)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<PasswordUiEntry> PasswordUiEntry::FromValue(const base::Value& value) {
  std::unique_ptr<PasswordUiEntry> out(new PasswordUiEntry());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PasswordUiEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("urls", (this->urls).ToValue());

  to_value_result->SetWithoutPathExpansion("username", std::make_unique<base::Value>(this->username));

  if (this->federation_text.get()) {
    to_value_result->SetWithoutPathExpansion("federationText", std::make_unique<base::Value>(*this->federation_text));

  }
  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("frontendId", std::make_unique<base::Value>(this->frontend_id));

  to_value_result->SetWithoutPathExpansion("fromAccountStore", std::make_unique<base::Value>(this->from_account_store));


  return to_value_result;
}


ExceptionEntry::ExceptionEntry()
: id(0),
frontend_id(0),
from_account_store(false) {}

ExceptionEntry::~ExceptionEntry() {}
ExceptionEntry::ExceptionEntry(ExceptionEntry&& rhs)
: urls(std::move(rhs.urls)),
id(rhs.id),
frontend_id(rhs.frontend_id),
from_account_store(rhs.from_account_store){
}

ExceptionEntry& ExceptionEntry::operator=(ExceptionEntry&& rhs)
{
urls = std::move(rhs.urls);
id = rhs.id;
frontend_id = rhs.frontend_id;
from_account_store = rhs.from_account_store;
return *this;
}

// static
bool ExceptionEntry::Populate(
    const base::Value& value, ExceptionEntry* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* urls_value = NULL;
  if (!dict->GetWithoutPathExpansion("urls", &urls_value)) {
    return false;
  }
  {
    const base::DictionaryValue* dictionary = NULL;
    if (!urls_value->GetAsDictionary(&dictionary)) {
      return false;
    }
    if (!UrlCollection::Populate(*dictionary, &out->urls)) {
      return false;
    }
  }

  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* frontend_id_value = NULL;
  if (!dict->GetWithoutPathExpansion("frontendId", &frontend_id_value)) {
    return false;
  }
  {
    if (!frontend_id_value->GetAsInteger(&out->frontend_id)) {
      return false;
    }
  }

  const base::Value* from_account_store_value = NULL;
  if (!dict->GetWithoutPathExpansion("fromAccountStore", &from_account_store_value)) {
    return false;
  }
  {
    if (!from_account_store_value->GetAsBoolean(&out->from_account_store)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<ExceptionEntry> ExceptionEntry::FromValue(const base::Value& value) {
  std::unique_ptr<ExceptionEntry> out(new ExceptionEntry());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> ExceptionEntry::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("urls", (this->urls).ToValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("frontendId", std::make_unique<base::Value>(this->frontend_id));

  to_value_result->SetWithoutPathExpansion("fromAccountStore", std::make_unique<base::Value>(this->from_account_store));


  return to_value_result;
}


PasswordExportProgress::PasswordExportProgress()
: status(EXPORT_PROGRESS_STATUS_NONE) {}

PasswordExportProgress::~PasswordExportProgress() {}
PasswordExportProgress::PasswordExportProgress(PasswordExportProgress&& rhs)
: status(rhs.status),
folder_name(std::move(rhs.folder_name)){
}

PasswordExportProgress& PasswordExportProgress::operator=(PasswordExportProgress&& rhs)
{
status = rhs.status;
folder_name = std::move(rhs.folder_name);
return *this;
}

// static
bool PasswordExportProgress::Populate(
    const base::Value& value, PasswordExportProgress* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* status_value = NULL;
  if (!dict->GetWithoutPathExpansion("status", &status_value)) {
    return false;
  }
  {
    std::string export_progress_status_as_string;
    if (!status_value->GetAsString(&export_progress_status_as_string)) {
      return false;
    }
    out->status = ParseExportProgressStatus(export_progress_status_as_string);
    if (out->status == EXPORT_PROGRESS_STATUS_NONE) {
      return false;
    }
  }

  const base::Value* folder_name_value = NULL;
  if (dict->GetWithoutPathExpansion("folderName", &folder_name_value)) {
    {
      std::string temp;
      if (!folder_name_value->GetAsString(&temp)) {
        out->folder_name.reset();
        return false;
      }
      else
        out->folder_name.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<PasswordExportProgress> PasswordExportProgress::FromValue(const base::Value& value) {
  std::unique_ptr<PasswordExportProgress> out(new PasswordExportProgress());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PasswordExportProgress::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("status", std::make_unique<base::Value>(passwords_private::ToString(this->status)));

  if (this->folder_name.get()) {
    to_value_result->SetWithoutPathExpansion("folderName", std::make_unique<base::Value>(*this->folder_name));

  }

  return to_value_result;
}


CompromisedCredential::CompromisedCredential()
: id(0),
is_android_credential(false),
compromise_time(0.0),
compromise_type(COMPROMISE_TYPE_NONE) {}

CompromisedCredential::~CompromisedCredential() {}
CompromisedCredential::CompromisedCredential(CompromisedCredential&& rhs)
: id(rhs.id),
formatted_origin(std::move(rhs.formatted_origin)),
detailed_origin(std::move(rhs.detailed_origin)),
is_android_credential(rhs.is_android_credential),
change_password_url(std::move(rhs.change_password_url)),
signon_realm(std::move(rhs.signon_realm)),
username(std::move(rhs.username)),
password(std::move(rhs.password)),
compromise_time(rhs.compromise_time),
elapsed_time_since_compromise(std::move(rhs.elapsed_time_since_compromise)),
compromise_type(rhs.compromise_type){
}

CompromisedCredential& CompromisedCredential::operator=(CompromisedCredential&& rhs)
{
id = rhs.id;
formatted_origin = std::move(rhs.formatted_origin);
detailed_origin = std::move(rhs.detailed_origin);
is_android_credential = rhs.is_android_credential;
change_password_url = std::move(rhs.change_password_url);
signon_realm = std::move(rhs.signon_realm);
username = std::move(rhs.username);
password = std::move(rhs.password);
compromise_time = rhs.compromise_time;
elapsed_time_since_compromise = std::move(rhs.elapsed_time_since_compromise);
compromise_type = rhs.compromise_type;
return *this;
}

// static
bool CompromisedCredential::Populate(
    const base::Value& value, CompromisedCredential* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* id_value = NULL;
  if (!dict->GetWithoutPathExpansion("id", &id_value)) {
    return false;
  }
  {
    if (!id_value->GetAsInteger(&out->id)) {
      return false;
    }
  }

  const base::Value* formatted_origin_value = NULL;
  if (!dict->GetWithoutPathExpansion("formattedOrigin", &formatted_origin_value)) {
    return false;
  }
  {
    if (!formatted_origin_value->GetAsString(&out->formatted_origin)) {
      return false;
    }
  }

  const base::Value* detailed_origin_value = NULL;
  if (!dict->GetWithoutPathExpansion("detailedOrigin", &detailed_origin_value)) {
    return false;
  }
  {
    if (!detailed_origin_value->GetAsString(&out->detailed_origin)) {
      return false;
    }
  }

  const base::Value* is_android_credential_value = NULL;
  if (!dict->GetWithoutPathExpansion("isAndroidCredential", &is_android_credential_value)) {
    return false;
  }
  {
    if (!is_android_credential_value->GetAsBoolean(&out->is_android_credential)) {
      return false;
    }
  }

  const base::Value* change_password_url_value = NULL;
  if (dict->GetWithoutPathExpansion("changePasswordUrl", &change_password_url_value)) {
    {
      std::string temp;
      if (!change_password_url_value->GetAsString(&temp)) {
        out->change_password_url.reset();
        return false;
      }
      else
        out->change_password_url.reset(new std::string(temp));
    }
  }

  const base::Value* signon_realm_value = NULL;
  if (!dict->GetWithoutPathExpansion("signonRealm", &signon_realm_value)) {
    return false;
  }
  {
    if (!signon_realm_value->GetAsString(&out->signon_realm)) {
      return false;
    }
  }

  const base::Value* username_value = NULL;
  if (!dict->GetWithoutPathExpansion("username", &username_value)) {
    return false;
  }
  {
    if (!username_value->GetAsString(&out->username)) {
      return false;
    }
  }

  const base::Value* password_value = NULL;
  if (dict->GetWithoutPathExpansion("password", &password_value)) {
    {
      std::string temp;
      if (!password_value->GetAsString(&temp)) {
        out->password.reset();
        return false;
      }
      else
        out->password.reset(new std::string(temp));
    }
  }

  const base::Value* compromise_time_value = NULL;
  if (!dict->GetWithoutPathExpansion("compromiseTime", &compromise_time_value)) {
    return false;
  }
  {
    if (!compromise_time_value->GetAsDouble(&out->compromise_time)) {
      return false;
    }
  }

  const base::Value* elapsed_time_since_compromise_value = NULL;
  if (!dict->GetWithoutPathExpansion("elapsedTimeSinceCompromise", &elapsed_time_since_compromise_value)) {
    return false;
  }
  {
    if (!elapsed_time_since_compromise_value->GetAsString(&out->elapsed_time_since_compromise)) {
      return false;
    }
  }

  const base::Value* compromise_type_value = NULL;
  if (!dict->GetWithoutPathExpansion("compromiseType", &compromise_type_value)) {
    return false;
  }
  {
    std::string compromise_type_as_string;
    if (!compromise_type_value->GetAsString(&compromise_type_as_string)) {
      return false;
    }
    out->compromise_type = ParseCompromiseType(compromise_type_as_string);
    if (out->compromise_type == COMPROMISE_TYPE_NONE) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<CompromisedCredential> CompromisedCredential::FromValue(const base::Value& value) {
  std::unique_ptr<CompromisedCredential> out(new CompromisedCredential());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CompromisedCredential::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("id", std::make_unique<base::Value>(this->id));

  to_value_result->SetWithoutPathExpansion("formattedOrigin", std::make_unique<base::Value>(this->formatted_origin));

  to_value_result->SetWithoutPathExpansion("detailedOrigin", std::make_unique<base::Value>(this->detailed_origin));

  to_value_result->SetWithoutPathExpansion("isAndroidCredential", std::make_unique<base::Value>(this->is_android_credential));

  if (this->change_password_url.get()) {
    to_value_result->SetWithoutPathExpansion("changePasswordUrl", std::make_unique<base::Value>(*this->change_password_url));

  }
  to_value_result->SetWithoutPathExpansion("signonRealm", std::make_unique<base::Value>(this->signon_realm));

  to_value_result->SetWithoutPathExpansion("username", std::make_unique<base::Value>(this->username));

  if (this->password.get()) {
    to_value_result->SetWithoutPathExpansion("password", std::make_unique<base::Value>(*this->password));

  }
  to_value_result->SetWithoutPathExpansion("compromiseTime", std::make_unique<base::Value>(this->compromise_time));

  to_value_result->SetWithoutPathExpansion("elapsedTimeSinceCompromise", std::make_unique<base::Value>(this->elapsed_time_since_compromise));

  to_value_result->SetWithoutPathExpansion("compromiseType", std::make_unique<base::Value>(passwords_private::ToString(this->compromise_type)));


  return to_value_result;
}


PasswordCheckStatus::PasswordCheckStatus()
: state(PASSWORD_CHECK_STATE_NONE) {}

PasswordCheckStatus::~PasswordCheckStatus() {}
PasswordCheckStatus::PasswordCheckStatus(PasswordCheckStatus&& rhs)
: state(rhs.state),
already_processed(std::move(rhs.already_processed)),
remaining_in_queue(std::move(rhs.remaining_in_queue)),
elapsed_time_since_last_check(std::move(rhs.elapsed_time_since_last_check)){
}

PasswordCheckStatus& PasswordCheckStatus::operator=(PasswordCheckStatus&& rhs)
{
state = rhs.state;
already_processed = std::move(rhs.already_processed);
remaining_in_queue = std::move(rhs.remaining_in_queue);
elapsed_time_since_last_check = std::move(rhs.elapsed_time_since_last_check);
return *this;
}

// static
bool PasswordCheckStatus::Populate(
    const base::Value& value, PasswordCheckStatus* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* state_value = NULL;
  if (!dict->GetWithoutPathExpansion("state", &state_value)) {
    return false;
  }
  {
    std::string password_check_state_as_string;
    if (!state_value->GetAsString(&password_check_state_as_string)) {
      return false;
    }
    out->state = ParsePasswordCheckState(password_check_state_as_string);
    if (out->state == PASSWORD_CHECK_STATE_NONE) {
      return false;
    }
  }

  const base::Value* already_processed_value = NULL;
  if (dict->GetWithoutPathExpansion("alreadyProcessed", &already_processed_value)) {
    {
      int temp;
      if (!already_processed_value->GetAsInteger(&temp)) {
        out->already_processed.reset();
        return false;
      }
      else
        out->already_processed.reset(new int(temp));
    }
  }

  const base::Value* remaining_in_queue_value = NULL;
  if (dict->GetWithoutPathExpansion("remainingInQueue", &remaining_in_queue_value)) {
    {
      int temp;
      if (!remaining_in_queue_value->GetAsInteger(&temp)) {
        out->remaining_in_queue.reset();
        return false;
      }
      else
        out->remaining_in_queue.reset(new int(temp));
    }
  }

  const base::Value* elapsed_time_since_last_check_value = NULL;
  if (dict->GetWithoutPathExpansion("elapsedTimeSinceLastCheck", &elapsed_time_since_last_check_value)) {
    {
      std::string temp;
      if (!elapsed_time_since_last_check_value->GetAsString(&temp)) {
        out->elapsed_time_since_last_check.reset();
        return false;
      }
      else
        out->elapsed_time_since_last_check.reset(new std::string(temp));
    }
  }

  return true;
}

// static
std::unique_ptr<PasswordCheckStatus> PasswordCheckStatus::FromValue(const base::Value& value) {
  std::unique_ptr<PasswordCheckStatus> out(new PasswordCheckStatus());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> PasswordCheckStatus::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("state", std::make_unique<base::Value>(passwords_private::ToString(this->state)));

  if (this->already_processed.get()) {
    to_value_result->SetWithoutPathExpansion("alreadyProcessed", std::make_unique<base::Value>(*this->already_processed));

  }
  if (this->remaining_in_queue.get()) {
    to_value_result->SetWithoutPathExpansion("remainingInQueue", std::make_unique<base::Value>(*this->remaining_in_queue));

  }
  if (this->elapsed_time_since_last_check.get()) {
    to_value_result->SetWithoutPathExpansion("elapsedTimeSinceLastCheck", std::make_unique<base::Value>(*this->elapsed_time_since_last_check));

  }

  return to_value_result;
}



//
// Functions
//

namespace RecordPasswordsPageAccessInSettings {

}  // namespace RecordPasswordsPageAccessInSettings

namespace ChangeSavedPassword {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() < 2 || args.GetSize() > 3) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* id_value = NULL;
  if (args.Get(0, &id_value) &&
      !id_value->is_none()) {
    {
      if (!id_value->GetAsInteger(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* new_username_value = NULL;
  if (args.Get(1, &new_username_value) &&
      !new_username_value->is_none()) {
    {
      if (!new_username_value->GetAsString(&params->new_username)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* new_password_value = NULL;
  if (args.Get(2, &new_password_value) &&
      !new_password_value->is_none()) {
    {
      std::string temp;
      if (!new_password_value->GetAsString(&temp)) {
        params->new_password.reset();
        return std::unique_ptr<Params>();
      }
      else
        params->new_password.reset(new std::string(temp));
    }
  }

  return params;
}


}  // namespace ChangeSavedPassword

namespace RemoveSavedPassword {

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
      if (!id_value->GetAsInteger(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RemoveSavedPassword

namespace RemoveSavedPasswords {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* ids_value = NULL;
  if (args.Get(0, &ids_value) &&
      !ids_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!ids_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->ids)) {
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


}  // namespace RemoveSavedPasswords

namespace RemovePasswordException {

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
      if (!id_value->GetAsInteger(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace RemovePasswordException

namespace RemovePasswordExceptions {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* ids_value = NULL;
  if (args.Get(0, &ids_value) &&
      !ids_value->is_none()) {
    {
      const base::ListValue* list = NULL;
      if (!ids_value->GetAsList(&list)) {
        return std::unique_ptr<Params>();
      }
      else {
        if (!json_schema_compiler::util::PopulateArrayFromList(*list, &params->ids)) {
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


}  // namespace RemovePasswordExceptions

namespace UndoRemoveSavedPasswordOrException {

}  // namespace UndoRemoveSavedPasswordOrException

namespace RequestPlaintextPassword {

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
      if (!id_value->GetAsInteger(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* reason_value = NULL;
  if (args.Get(1, &reason_value) &&
      !reason_value->is_none()) {
    {
      std::string plaintext_reason_as_string;
      if (!reason_value->GetAsString(&plaintext_reason_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->reason = ParsePlaintextReason(plaintext_reason_as_string);
      if (params->reason == PLAINTEXT_REASON_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const std::string& password) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(password));

  return create_results;
}
}  // namespace RequestPlaintextPassword

namespace GetSavedPasswordList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<PasswordUiEntry>& entries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(entries));

  return create_results;
}
}  // namespace GetSavedPasswordList

namespace GetPasswordExceptionList {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<ExceptionEntry>& exceptions) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(exceptions));

  return create_results;
}
}  // namespace GetPasswordExceptionList

namespace MovePasswordToAccount {

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
      if (!id_value->GetAsInteger(&params->id)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace MovePasswordToAccount

namespace ImportPasswords {

}  // namespace ImportPasswords

namespace ExportPasswords {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace ExportPasswords

namespace RequestExportProgressStatus {

std::unique_ptr<base::ListValue> Results::Create(const ExportProgressStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(passwords_private::ToString(status)));

  return create_results;
}
}  // namespace RequestExportProgressStatus

namespace CancelExportPasswords {

}  // namespace CancelExportPasswords

namespace IsOptedInForAccountStorage {

std::unique_ptr<base::ListValue> Results::Create(bool opted_in) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(opted_in));

  return create_results;
}
}  // namespace IsOptedInForAccountStorage

namespace OptInForAccountStorage {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* opt_in_value = NULL;
  if (args.Get(0, &opt_in_value) &&
      !opt_in_value->is_none()) {
    {
      if (!opt_in_value->GetAsBoolean(&params->opt_in)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


}  // namespace OptInForAccountStorage

namespace GetCompromisedCredentials {

std::unique_ptr<base::ListValue> Results::Create(const std::vector<CompromisedCredential>& compromised_credential) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(compromised_credential));

  return create_results;
}
}  // namespace GetCompromisedCredentials

namespace GetPlaintextCompromisedPassword {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* credential_value = NULL;
  if (args.Get(0, &credential_value) &&
      !credential_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!credential_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CompromisedCredential::Populate(*dictionary, &params->credential)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* reason_value = NULL;
  if (args.Get(1, &reason_value) &&
      !reason_value->is_none()) {
    {
      std::string plaintext_reason_as_string;
      if (!reason_value->GetAsString(&plaintext_reason_as_string)) {
        return std::unique_ptr<Params>();
      }
      params->reason = ParsePlaintextReason(plaintext_reason_as_string);
      if (params->reason == PLAINTEXT_REASON_NONE) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  return params;
}


std::unique_ptr<base::ListValue> Results::Create(const CompromisedCredential& credential) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((credential).ToValue());

  return create_results;
}
}  // namespace GetPlaintextCompromisedPassword

namespace ChangeCompromisedCredential {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 2) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* credential_value = NULL;
  if (args.Get(0, &credential_value) &&
      !credential_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!credential_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CompromisedCredential::Populate(*dictionary, &params->credential)) {
        return std::unique_ptr<Params>();
      }
    }
  }
  else {
    return std::unique_ptr<Params>();
  }

  const base::Value* new_password_value = NULL;
  if (args.Get(1, &new_password_value) &&
      !new_password_value->is_none()) {
    {
      if (!new_password_value->GetAsString(&params->new_password)) {
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
}  // namespace ChangeCompromisedCredential

namespace RemoveCompromisedCredential {

Params::Params() {}
Params::~Params() {}

// static
std::unique_ptr<Params> Params::Create(const base::ListValue& args) {
  if (args.GetSize() != 1) {
    return nullptr;
  }
  std::unique_ptr<Params> params(new Params());

  const base::Value* credential_value = NULL;
  if (args.Get(0, &credential_value) &&
      !credential_value->is_none()) {
    {
      const base::DictionaryValue* dictionary = NULL;
      if (!credential_value->GetAsDictionary(&dictionary)) {
        return std::unique_ptr<Params>();
      }
      if (!CompromisedCredential::Populate(*dictionary, &params->credential)) {
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
}  // namespace RemoveCompromisedCredential

namespace StartPasswordCheck {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace StartPasswordCheck

namespace StopPasswordCheck {

std::unique_ptr<base::ListValue> Results::Create() {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  return create_results;
}
}  // namespace StopPasswordCheck

namespace GetPasswordCheckStatus {

std::unique_ptr<base::ListValue> Results::Create(const PasswordCheckStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((status).ToValue());

  return create_results;
}
}  // namespace GetPasswordCheckStatus

//
// Events
//

namespace OnSavedPasswordsListChanged {

const char kEventName[] = "passwordsPrivate.onSavedPasswordsListChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<PasswordUiEntry>& entries) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(entries));

  return create_results;
}

}  // namespace OnSavedPasswordsListChanged

namespace OnPasswordExceptionsListChanged {

const char kEventName[] = "passwordsPrivate.onPasswordExceptionsListChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<ExceptionEntry>& exceptions) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(exceptions));

  return create_results;
}

}  // namespace OnPasswordExceptionsListChanged

namespace OnPasswordsFileExportProgress {

const char kEventName[] = "passwordsPrivate.onPasswordsFileExportProgress";

std::unique_ptr<base::ListValue> Create(const PasswordExportProgress& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((status).ToValue());

  return create_results;
}

}  // namespace OnPasswordsFileExportProgress

namespace OnAccountStorageOptInStateChanged {

const char kEventName[] = "passwordsPrivate.onAccountStorageOptInStateChanged";

std::unique_ptr<base::ListValue> Create(bool opted_in) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(std::make_unique<base::Value>(opted_in));

  return create_results;
}

}  // namespace OnAccountStorageOptInStateChanged

namespace OnCompromisedCredentialsChanged {

const char kEventName[] = "passwordsPrivate.onCompromisedCredentialsChanged";

std::unique_ptr<base::ListValue> Create(const std::vector<CompromisedCredential>& compromised_credentials) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append(json_schema_compiler::util::CreateValueFromArray(compromised_credentials));

  return create_results;
}

}  // namespace OnCompromisedCredentialsChanged

namespace OnPasswordCheckStatusChanged {

const char kEventName[] = "passwordsPrivate.onPasswordCheckStatusChanged";

std::unique_ptr<base::ListValue> Create(const PasswordCheckStatus& status) {
  std::unique_ptr<base::ListValue> create_results(new base::ListValue());
  create_results->Append((status).ToValue());

  return create_results;
}

}  // namespace OnPasswordCheckStatusChanged

}  // namespace passwords_private
}  // namespace api
}  // namespace extensions

