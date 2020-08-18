// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_database.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_database.h"

namespace headless {

namespace database {

std::unique_ptr<Database> Database::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Database");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Database> result(new Database());
  errors->Push();
  errors->SetName("Database");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* domain_value = value.FindKey("domain");
  if (domain_value) {
    errors->SetName("domain");
    result->domain_ = internal::FromValue<std::string>::Parse(*domain_value, errors);
  } else {
    errors->AddError("required property missing: domain");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* version_value = value.FindKey("version");
  if (version_value) {
    errors->SetName("version");
    result->version_ = internal::FromValue<std::string>::Parse(*version_value, errors);
  } else {
    errors->AddError("required property missing: version");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Database::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  result->Set("domain", internal::ToValue(domain_));
  result->Set("name", internal::ToValue(name_));
  result->Set("version", internal::ToValue(version_));
  return std::move(result);
}

std::unique_ptr<Database> Database::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Database> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Error> Error::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Error");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Error> result(new Error());
  errors->Push();
  errors->SetName("Error");
  const base::Value* message_value = value.FindKey("message");
  if (message_value) {
    errors->SetName("message");
    result->message_ = internal::FromValue<std::string>::Parse(*message_value, errors);
  } else {
    errors->AddError("required property missing: message");
  }
  const base::Value* code_value = value.FindKey("code");
  if (code_value) {
    errors->SetName("code");
    result->code_ = internal::FromValue<int>::Parse(*code_value, errors);
  } else {
    errors->AddError("required property missing: code");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Error::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("message", internal::ToValue(message_));
  result->Set("code", internal::ToValue(code_));
  return std::move(result);
}

std::unique_ptr<Error> Error::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Error> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExecuteSQLParams> ExecuteSQLParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExecuteSQLParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExecuteSQLParams> result(new ExecuteSQLParams());
  errors->Push();
  errors->SetName("ExecuteSQLParams");
  const base::Value* database_id_value = value.FindKey("databaseId");
  if (database_id_value) {
    errors->SetName("databaseId");
    result->database_id_ = internal::FromValue<std::string>::Parse(*database_id_value, errors);
  } else {
    errors->AddError("required property missing: databaseId");
  }
  const base::Value* query_value = value.FindKey("query");
  if (query_value) {
    errors->SetName("query");
    result->query_ = internal::FromValue<std::string>::Parse(*query_value, errors);
  } else {
    errors->AddError("required property missing: query");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExecuteSQLParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("databaseId", internal::ToValue(database_id_));
  result->Set("query", internal::ToValue(query_));
  return std::move(result);
}

std::unique_ptr<ExecuteSQLParams> ExecuteSQLParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExecuteSQLParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExecuteSQLResult> ExecuteSQLResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExecuteSQLResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExecuteSQLResult> result(new ExecuteSQLResult());
  errors->Push();
  errors->SetName("ExecuteSQLResult");
  const base::Value* column_names_value = value.FindKey("columnNames");
  if (column_names_value) {
    errors->SetName("columnNames");
    result->column_names_ = internal::FromValue<std::vector<std::string>>::Parse(*column_names_value, errors);
  }
  const base::Value* values_value = value.FindKey("values");
  if (values_value) {
    errors->SetName("values");
    result->values_ = internal::FromValue<std::vector<std::unique_ptr<base::Value>>>::Parse(*values_value, errors);
  }
  const base::Value* sql_error_value = value.FindKey("sqlError");
  if (sql_error_value) {
    errors->SetName("sqlError");
    result->sql_error_ = internal::FromValue<::headless::database::Error>::Parse(*sql_error_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExecuteSQLResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (column_names_)
    result->Set("columnNames", internal::ToValue(column_names_.value()));
  if (values_)
    result->Set("values", internal::ToValue(values_.value()));
  if (sql_error_)
    result->Set("sqlError", internal::ToValue(*sql_error_.value()));
  return std::move(result);
}

std::unique_ptr<ExecuteSQLResult> ExecuteSQLResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExecuteSQLResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDatabaseTableNamesParams> GetDatabaseTableNamesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDatabaseTableNamesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDatabaseTableNamesParams> result(new GetDatabaseTableNamesParams());
  errors->Push();
  errors->SetName("GetDatabaseTableNamesParams");
  const base::Value* database_id_value = value.FindKey("databaseId");
  if (database_id_value) {
    errors->SetName("databaseId");
    result->database_id_ = internal::FromValue<std::string>::Parse(*database_id_value, errors);
  } else {
    errors->AddError("required property missing: databaseId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDatabaseTableNamesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("databaseId", internal::ToValue(database_id_));
  return std::move(result);
}

std::unique_ptr<GetDatabaseTableNamesParams> GetDatabaseTableNamesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDatabaseTableNamesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDatabaseTableNamesResult> GetDatabaseTableNamesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDatabaseTableNamesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDatabaseTableNamesResult> result(new GetDatabaseTableNamesResult());
  errors->Push();
  errors->SetName("GetDatabaseTableNamesResult");
  const base::Value* table_names_value = value.FindKey("tableNames");
  if (table_names_value) {
    errors->SetName("tableNames");
    result->table_names_ = internal::FromValue<std::vector<std::string>>::Parse(*table_names_value, errors);
  } else {
    errors->AddError("required property missing: tableNames");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDatabaseTableNamesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("tableNames", internal::ToValue(table_names_));
  return std::move(result);
}

std::unique_ptr<GetDatabaseTableNamesResult> GetDatabaseTableNamesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDatabaseTableNamesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddDatabaseParams> AddDatabaseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddDatabaseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddDatabaseParams> result(new AddDatabaseParams());
  errors->Push();
  errors->SetName("AddDatabaseParams");
  const base::Value* database_value = value.FindKey("database");
  if (database_value) {
    errors->SetName("database");
    result->database_ = internal::FromValue<::headless::database::Database>::Parse(*database_value, errors);
  } else {
    errors->AddError("required property missing: database");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddDatabaseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("database", internal::ToValue(*database_));
  return std::move(result);
}

std::unique_ptr<AddDatabaseParams> AddDatabaseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddDatabaseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace database
}  // namespace headless
