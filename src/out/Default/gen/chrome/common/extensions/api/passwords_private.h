// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/passwords_private.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_PASSWORDS_PRIVATE_H__
#define CHROME_COMMON_EXTENSIONS_API_PASSWORDS_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace passwords_private {

//
// Types
//

// Possible reasons why a plaintext password was requested.
enum PlaintextReason {
  PLAINTEXT_REASON_NONE,
  PLAINTEXT_REASON_VIEW,
  PLAINTEXT_REASON_COPY,
  PLAINTEXT_REASON_EDIT,
  PLAINTEXT_REASON_LAST = PLAINTEXT_REASON_EDIT,
};


const char* ToString(PlaintextReason as_enum);
PlaintextReason ParsePlaintextReason(const std::string& as_string);

enum ExportProgressStatus {
  EXPORT_PROGRESS_STATUS_NONE,
  EXPORT_PROGRESS_STATUS_NOT_STARTED,
  EXPORT_PROGRESS_STATUS_IN_PROGRESS,
  EXPORT_PROGRESS_STATUS_SUCCEEDED,
  EXPORT_PROGRESS_STATUS_FAILED_CANCELLED,
  EXPORT_PROGRESS_STATUS_FAILED_WRITE_FAILED,
  EXPORT_PROGRESS_STATUS_LAST = EXPORT_PROGRESS_STATUS_FAILED_WRITE_FAILED,
};


const char* ToString(ExportProgressStatus as_enum);
ExportProgressStatus ParseExportProgressStatus(const std::string& as_string);

enum CompromiseType {
  COMPROMISE_TYPE_NONE,
  COMPROMISE_TYPE_LEAKED,
  COMPROMISE_TYPE_PHISHED,
  COMPROMISE_TYPE_PHISHED_AND_LEAKED,
  COMPROMISE_TYPE_LAST = COMPROMISE_TYPE_PHISHED_AND_LEAKED,
};


const char* ToString(CompromiseType as_enum);
CompromiseType ParseCompromiseType(const std::string& as_string);

enum PasswordCheckState {
  PASSWORD_CHECK_STATE_NONE,
  PASSWORD_CHECK_STATE_IDLE,
  PASSWORD_CHECK_STATE_RUNNING,
  PASSWORD_CHECK_STATE_CANCELED,
  PASSWORD_CHECK_STATE_OFFLINE,
  PASSWORD_CHECK_STATE_SIGNED_OUT,
  PASSWORD_CHECK_STATE_NO_PASSWORDS,
  PASSWORD_CHECK_STATE_QUOTA_LIMIT,
  PASSWORD_CHECK_STATE_OTHER_ERROR,
  PASSWORD_CHECK_STATE_LAST = PASSWORD_CHECK_STATE_OTHER_ERROR,
};


const char* ToString(PasswordCheckState as_enum);
PasswordCheckState ParsePasswordCheckState(const std::string& as_string);

struct UrlCollection {
  UrlCollection();
  ~UrlCollection();
  UrlCollection(UrlCollection&& rhs);
  UrlCollection& operator=(UrlCollection&& rhs);

  // Populates a UrlCollection object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, UrlCollection* out);

  // Creates a UrlCollection object from a base::Value, or NULL on failure.
  static std::unique_ptr<UrlCollection> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this UrlCollection object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The fully specified URL of the credential's origin.
  std::string origin;

  // A human readable version of the URL of the credential's origin.
  std::string shown;

  // The URL that will be linked to when an entry is clicked.
  std::string link;


 private:
  DISALLOW_COPY_AND_ASSIGN(UrlCollection);
};

struct PasswordUiEntry {
  PasswordUiEntry();
  ~PasswordUiEntry();
  PasswordUiEntry(PasswordUiEntry&& rhs);
  PasswordUiEntry& operator=(PasswordUiEntry&& rhs);

  // Populates a PasswordUiEntry object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, PasswordUiEntry* out);

  // Creates a PasswordUiEntry object from a base::Value, or NULL on failure.
  static std::unique_ptr<PasswordUiEntry> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PasswordUiEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The URL collection corresponding to this saved password entry.
  UrlCollection urls;

  // The username used in conjunction with the saved password.
  std::string username;

  // Text shown if the password was obtained via a federated identity.
  std::unique_ptr<std::string> federation_text;

  // An index to refer back to a unique password entry record.
  int id;

  // An index to refer to an entry displayed by the UI. May correspond to multiple
  // entries in the backend.
  int frontend_id;

  // If true, the entry came from the Gaia-account-scoped password store rather
  // than from the profile-scoped one.
  bool from_account_store;


 private:
  DISALLOW_COPY_AND_ASSIGN(PasswordUiEntry);
};

struct ExceptionEntry {
  ExceptionEntry();
  ~ExceptionEntry();
  ExceptionEntry(ExceptionEntry&& rhs);
  ExceptionEntry& operator=(ExceptionEntry&& rhs);

  // Populates a ExceptionEntry object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, ExceptionEntry* out);

  // Creates a ExceptionEntry object from a base::Value, or NULL on failure.
  static std::unique_ptr<ExceptionEntry> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExceptionEntry object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The URL collection corresponding to this exception entry.
  UrlCollection urls;

  // An id to refer back to a unique exception entry record.
  int id;

  // An index to refer to an exception entry displayed by the UI. May correspond
  // to multiple entries in the backend.
  int frontend_id;

  // If true, the entry came from the Gaia-account-scoped password store rather
  // than from the profile-scoped one.
  bool from_account_store;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExceptionEntry);
};

struct PasswordExportProgress {
  PasswordExportProgress();
  ~PasswordExportProgress();
  PasswordExportProgress(PasswordExportProgress&& rhs);
  PasswordExportProgress& operator=(PasswordExportProgress&& rhs);

  // Populates a PasswordExportProgress object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, PasswordExportProgress* out);

  // Creates a PasswordExportProgress object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<PasswordExportProgress> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PasswordExportProgress object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The current status of the export task.
  ExportProgressStatus status;

  // If |status| is $ref(ExportProgressStatus.FAILED_WRITE_FAILED), this will be
  // the name of the selected folder to export to.
  std::unique_ptr<std::string> folder_name;


 private:
  DISALLOW_COPY_AND_ASSIGN(PasswordExportProgress);
};

struct CompromisedCredential {
  CompromisedCredential();
  ~CompromisedCredential();
  CompromisedCredential(CompromisedCredential&& rhs);
  CompromisedCredential& operator=(CompromisedCredential&& rhs);

  // Populates a CompromisedCredential object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, CompromisedCredential* out);

  // Creates a CompromisedCredential object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<CompromisedCredential> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this CompromisedCredential object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // An id serving as a mapping to a given compromised credential. This identifier
  // will remain stable for a single browser session.
  int id;

  // The formatted origin of the compromised credential. Can be the origin of a
  // website (excluding scheme) or the name of an app.
  std::string formatted_origin;

  // The detailed origin of the compromised credential. As opposed to
  // formattedOrigin this also includes the scheme and trivial subdomains like
  // www. For an app this is either the app name or the name of the package, if
  // the former could not be retrieved.
  std::string detailed_origin;

  // Indicates whether this credential belongs to an Android app.
  bool is_android_credential;

  // The URL where the compromised password can be changed. Might be not set for
  // Android apps.
  std::unique_ptr<std::string> change_password_url;

  // The signon realm of the credential.
  std::string signon_realm;

  // The username of the credential.
  std::string username;

  // The password of the credential. Initially empty, only set if explicitly
  // requested.
  std::unique_ptr<std::string> password;

  // The timestamp of when this credential was determined to be compromised.
  // Specified in milliseconds since the UNIX epoch. Intended to be passed to the
  // JavaScript Date() constructor.
  double compromise_time;

  // The elapsed time since this credential was determined to be compromised. This
  // is passed as an already formatted string, since JavaScript lacks the required
  // formatting APIs. Example: "5 minutes ago"
  std::string elapsed_time_since_compromise;

  // The type of the credentials that was compromised.
  CompromiseType compromise_type;


 private:
  DISALLOW_COPY_AND_ASSIGN(CompromisedCredential);
};

struct PasswordCheckStatus {
  PasswordCheckStatus();
  ~PasswordCheckStatus();
  PasswordCheckStatus(PasswordCheckStatus&& rhs);
  PasswordCheckStatus& operator=(PasswordCheckStatus&& rhs);

  // Populates a PasswordCheckStatus object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, PasswordCheckStatus* out);

  // Creates a PasswordCheckStatus object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<PasswordCheckStatus> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this PasswordCheckStatus object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The state of the password check.
  PasswordCheckState state;

  // How many passwords have already been processed. Populated if and only if the
  // password check is currently running.
  std::unique_ptr<int> already_processed;

  // How many passwords are remaining in the queue. Populated if and only if the
  // password check is currently running.
  std::unique_ptr<int> remaining_in_queue;

  // The elapsed time since the last full password check was performed. This is
  // passed as a string, since JavaScript lacks the required formatting APIs. If
  // no check has been performed yet this is not set.
  std::unique_ptr<std::string> elapsed_time_since_last_check;


 private:
  DISALLOW_COPY_AND_ASSIGN(PasswordCheckStatus);
};


//
// Functions
//

namespace RecordPasswordsPageAccessInSettings {

}  // namespace RecordPasswordsPageAccessInSettings

namespace ChangeSavedPassword {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id for the password entry being updated.
  int id;

  // The new username.
  std::string new_username;

  // The new password.
  std::unique_ptr<std::string> new_password;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace ChangeSavedPassword

namespace RemoveSavedPassword {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id for the password entry being removed.
  int id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemoveSavedPassword

namespace RemoveSavedPasswords {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::vector<int> ids;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemoveSavedPasswords

namespace RemovePasswordException {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id for the exception url entry being removed.
  int id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemovePasswordException

namespace RemovePasswordExceptions {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::vector<int> ids;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RemovePasswordExceptions

namespace UndoRemoveSavedPasswordOrException {

}  // namespace UndoRemoveSavedPasswordOrException

namespace RequestPlaintextPassword {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id for the password entry being being retrieved.
  int id;

  // The reason why the plaintext password is requested.
  PlaintextReason reason;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& password);
}  // namespace Results

}  // namespace RequestPlaintextPassword

namespace GetSavedPasswordList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<PasswordUiEntry>& entries);
}  // namespace Results

}  // namespace GetSavedPasswordList

namespace GetPasswordExceptionList {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<ExceptionEntry>& exceptions);
}  // namespace Results

}  // namespace GetPasswordExceptionList

namespace MovePasswordToAccount {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The id for the password entry being moved.
  int id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace MovePasswordToAccount

namespace ImportPasswords {

}  // namespace ImportPasswords

namespace ExportPasswords {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ExportPasswords

namespace RequestExportProgressStatus {

namespace Results {

std::unique_ptr<base::ListValue> Create(const ExportProgressStatus& status);
}  // namespace Results

}  // namespace RequestExportProgressStatus

namespace CancelExportPasswords {

}  // namespace CancelExportPasswords

namespace IsOptedInForAccountStorage {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool opted_in);
}  // namespace Results

}  // namespace IsOptedInForAccountStorage

namespace OptInForAccountStorage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  bool opt_in;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace OptInForAccountStorage

namespace GetCompromisedCredentials {

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::vector<CompromisedCredential>& compromised_credential);
}  // namespace Results

}  // namespace GetCompromisedCredentials

namespace GetPlaintextCompromisedPassword {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The compromised credential whose password is being retrieved.
  CompromisedCredential credential;

  // The reason why the plaintext password is requested.
  PlaintextReason reason;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const CompromisedCredential& credential);
}  // namespace Results

}  // namespace GetPlaintextCompromisedPassword

namespace ChangeCompromisedCredential {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The credential whose password should be changed.
  CompromisedCredential credential;

  // The new password.
  std::string new_password;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace ChangeCompromisedCredential

namespace RemoveCompromisedCredential {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  CompromisedCredential credential;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace RemoveCompromisedCredential

namespace StartPasswordCheck {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StartPasswordCheck

namespace StopPasswordCheck {

namespace Results {

std::unique_ptr<base::ListValue> Create();
}  // namespace Results

}  // namespace StopPasswordCheck

namespace GetPasswordCheckStatus {

namespace Results {

std::unique_ptr<base::ListValue> Create(const PasswordCheckStatus& status);
}  // namespace Results

}  // namespace GetPasswordCheckStatus

//
// Events
//

namespace OnSavedPasswordsListChanged {

extern const char kEventName[];  // "passwordsPrivate.onSavedPasswordsListChanged"

// The updated list of password entries.
std::unique_ptr<base::ListValue> Create(const std::vector<PasswordUiEntry>& entries);
}  // namespace OnSavedPasswordsListChanged

namespace OnPasswordExceptionsListChanged {

extern const char kEventName[];  // "passwordsPrivate.onPasswordExceptionsListChanged"

// The updated list of password exceptions.
std::unique_ptr<base::ListValue> Create(const std::vector<ExceptionEntry>& exceptions);
}  // namespace OnPasswordExceptionsListChanged

namespace OnPasswordsFileExportProgress {

extern const char kEventName[];  // "passwordsPrivate.onPasswordsFileExportProgress"

// The progress status and an optional UI message.
std::unique_ptr<base::ListValue> Create(const PasswordExportProgress& status);
}  // namespace OnPasswordsFileExportProgress

namespace OnAccountStorageOptInStateChanged {

extern const char kEventName[];  // "passwordsPrivate.onAccountStorageOptInStateChanged"

// The new opt-in state.
std::unique_ptr<base::ListValue> Create(bool opted_in);
}  // namespace OnAccountStorageOptInStateChanged

namespace OnCompromisedCredentialsChanged {

extern const char kEventName[];  // "passwordsPrivate.onCompromisedCredentialsChanged"

// The updated compromised credentials.
std::unique_ptr<base::ListValue> Create(const std::vector<CompromisedCredential>& compromised_credentials);
}  // namespace OnCompromisedCredentialsChanged

namespace OnPasswordCheckStatusChanged {

extern const char kEventName[];  // "passwordsPrivate.onPasswordCheckStatusChanged"

// The updated status of the password check.
std::unique_ptr<base::ListValue> Create(const PasswordCheckStatus& status);
}  // namespace OnPasswordCheckStatusChanged

}  // namespace passwords_private
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_PASSWORDS_PRIVATE_H__
