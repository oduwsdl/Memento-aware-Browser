// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_indexeddb.h"
#include "headless/public/devtools/domains/types_runtime.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_indexeddb.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"

namespace headless {

namespace indexeddb {

std::unique_ptr<DatabaseWithObjectStores> DatabaseWithObjectStores::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DatabaseWithObjectStores");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DatabaseWithObjectStores> result(new DatabaseWithObjectStores());
  errors->Push();
  errors->SetName("DatabaseWithObjectStores");
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
    result->version_ = internal::FromValue<double>::Parse(*version_value, errors);
  } else {
    errors->AddError("required property missing: version");
  }
  const base::Value* object_stores_value = value.FindKey("objectStores");
  if (object_stores_value) {
    errors->SetName("objectStores");
    result->object_stores_ = internal::FromValue<std::vector<std::unique_ptr<::headless::indexeddb::ObjectStore>>>::Parse(*object_stores_value, errors);
  } else {
    errors->AddError("required property missing: objectStores");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DatabaseWithObjectStores::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("version", internal::ToValue(version_));
  result->Set("objectStores", internal::ToValue(object_stores_));
  return std::move(result);
}

std::unique_ptr<DatabaseWithObjectStores> DatabaseWithObjectStores::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DatabaseWithObjectStores> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ObjectStore> ObjectStore::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ObjectStore");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ObjectStore> result(new ObjectStore());
  errors->Push();
  errors->SetName("ObjectStore");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* key_path_value = value.FindKey("keyPath");
  if (key_path_value) {
    errors->SetName("keyPath");
    result->key_path_ = internal::FromValue<::headless::indexeddb::KeyPath>::Parse(*key_path_value, errors);
  } else {
    errors->AddError("required property missing: keyPath");
  }
  const base::Value* auto_increment_value = value.FindKey("autoIncrement");
  if (auto_increment_value) {
    errors->SetName("autoIncrement");
    result->auto_increment_ = internal::FromValue<bool>::Parse(*auto_increment_value, errors);
  } else {
    errors->AddError("required property missing: autoIncrement");
  }
  const base::Value* indexes_value = value.FindKey("indexes");
  if (indexes_value) {
    errors->SetName("indexes");
    result->indexes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::indexeddb::ObjectStoreIndex>>>::Parse(*indexes_value, errors);
  } else {
    errors->AddError("required property missing: indexes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ObjectStore::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("keyPath", internal::ToValue(*key_path_));
  result->Set("autoIncrement", internal::ToValue(auto_increment_));
  result->Set("indexes", internal::ToValue(indexes_));
  return std::move(result);
}

std::unique_ptr<ObjectStore> ObjectStore::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ObjectStore> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ObjectStoreIndex> ObjectStoreIndex::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ObjectStoreIndex");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ObjectStoreIndex> result(new ObjectStoreIndex());
  errors->Push();
  errors->SetName("ObjectStoreIndex");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* key_path_value = value.FindKey("keyPath");
  if (key_path_value) {
    errors->SetName("keyPath");
    result->key_path_ = internal::FromValue<::headless::indexeddb::KeyPath>::Parse(*key_path_value, errors);
  } else {
    errors->AddError("required property missing: keyPath");
  }
  const base::Value* unique_value = value.FindKey("unique");
  if (unique_value) {
    errors->SetName("unique");
    result->unique_ = internal::FromValue<bool>::Parse(*unique_value, errors);
  } else {
    errors->AddError("required property missing: unique");
  }
  const base::Value* multi_entry_value = value.FindKey("multiEntry");
  if (multi_entry_value) {
    errors->SetName("multiEntry");
    result->multi_entry_ = internal::FromValue<bool>::Parse(*multi_entry_value, errors);
  } else {
    errors->AddError("required property missing: multiEntry");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ObjectStoreIndex::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("keyPath", internal::ToValue(*key_path_));
  result->Set("unique", internal::ToValue(unique_));
  result->Set("multiEntry", internal::ToValue(multi_entry_));
  return std::move(result);
}

std::unique_ptr<ObjectStoreIndex> ObjectStoreIndex::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ObjectStoreIndex> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Key> Key::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Key");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Key> result(new Key());
  errors->Push();
  errors->SetName("Key");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::indexeddb::KeyType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* number_value = value.FindKey("number");
  if (number_value) {
    errors->SetName("number");
    result->number_ = internal::FromValue<double>::Parse(*number_value, errors);
  }
  const base::Value* string_value = value.FindKey("string");
  if (string_value) {
    errors->SetName("string");
    result->string_ = internal::FromValue<std::string>::Parse(*string_value, errors);
  }
  const base::Value* date_value = value.FindKey("date");
  if (date_value) {
    errors->SetName("date");
    result->date_ = internal::FromValue<double>::Parse(*date_value, errors);
  }
  const base::Value* array_value = value.FindKey("array");
  if (array_value) {
    errors->SetName("array");
    result->array_ = internal::FromValue<std::vector<std::unique_ptr<::headless::indexeddb::Key>>>::Parse(*array_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Key::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  if (number_)
    result->Set("number", internal::ToValue(number_.value()));
  if (string_)
    result->Set("string", internal::ToValue(string_.value()));
  if (date_)
    result->Set("date", internal::ToValue(date_.value()));
  if (array_)
    result->Set("array", internal::ToValue(array_.value()));
  return std::move(result);
}

std::unique_ptr<Key> Key::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Key> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<KeyRange> KeyRange::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("KeyRange");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<KeyRange> result(new KeyRange());
  errors->Push();
  errors->SetName("KeyRange");
  const base::Value* lower_value = value.FindKey("lower");
  if (lower_value) {
    errors->SetName("lower");
    result->lower_ = internal::FromValue<::headless::indexeddb::Key>::Parse(*lower_value, errors);
  }
  const base::Value* upper_value = value.FindKey("upper");
  if (upper_value) {
    errors->SetName("upper");
    result->upper_ = internal::FromValue<::headless::indexeddb::Key>::Parse(*upper_value, errors);
  }
  const base::Value* lower_open_value = value.FindKey("lowerOpen");
  if (lower_open_value) {
    errors->SetName("lowerOpen");
    result->lower_open_ = internal::FromValue<bool>::Parse(*lower_open_value, errors);
  } else {
    errors->AddError("required property missing: lowerOpen");
  }
  const base::Value* upper_open_value = value.FindKey("upperOpen");
  if (upper_open_value) {
    errors->SetName("upperOpen");
    result->upper_open_ = internal::FromValue<bool>::Parse(*upper_open_value, errors);
  } else {
    errors->AddError("required property missing: upperOpen");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> KeyRange::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (lower_)
    result->Set("lower", internal::ToValue(*lower_.value()));
  if (upper_)
    result->Set("upper", internal::ToValue(*upper_.value()));
  result->Set("lowerOpen", internal::ToValue(lower_open_));
  result->Set("upperOpen", internal::ToValue(upper_open_));
  return std::move(result);
}

std::unique_ptr<KeyRange> KeyRange::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<KeyRange> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DataEntry> DataEntry::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DataEntry");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DataEntry> result(new DataEntry());
  errors->Push();
  errors->SetName("DataEntry");
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*key_value, errors);
  } else {
    errors->AddError("required property missing: key");
  }
  const base::Value* primary_key_value = value.FindKey("primaryKey");
  if (primary_key_value) {
    errors->SetName("primaryKey");
    result->primary_key_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*primary_key_value, errors);
  } else {
    errors->AddError("required property missing: primaryKey");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DataEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("key", internal::ToValue(*key_));
  result->Set("primaryKey", internal::ToValue(*primary_key_));
  result->Set("value", internal::ToValue(*value_));
  return std::move(result);
}

std::unique_ptr<DataEntry> DataEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DataEntry> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<KeyPath> KeyPath::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("KeyPath");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<KeyPath> result(new KeyPath());
  errors->Push();
  errors->SetName("KeyPath");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::indexeddb::KeyPathType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* string_value = value.FindKey("string");
  if (string_value) {
    errors->SetName("string");
    result->string_ = internal::FromValue<std::string>::Parse(*string_value, errors);
  }
  const base::Value* array_value = value.FindKey("array");
  if (array_value) {
    errors->SetName("array");
    result->array_ = internal::FromValue<std::vector<std::string>>::Parse(*array_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> KeyPath::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  if (string_)
    result->Set("string", internal::ToValue(string_.value()));
  if (array_)
    result->Set("array", internal::ToValue(array_.value()));
  return std::move(result);
}

std::unique_ptr<KeyPath> KeyPath::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<KeyPath> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearObjectStoreParams> ClearObjectStoreParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearObjectStoreParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearObjectStoreParams> result(new ClearObjectStoreParams());
  errors->Push();
  errors->SetName("ClearObjectStoreParams");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* database_name_value = value.FindKey("databaseName");
  if (database_name_value) {
    errors->SetName("databaseName");
    result->database_name_ = internal::FromValue<std::string>::Parse(*database_name_value, errors);
  } else {
    errors->AddError("required property missing: databaseName");
  }
  const base::Value* object_store_name_value = value.FindKey("objectStoreName");
  if (object_store_name_value) {
    errors->SetName("objectStoreName");
    result->object_store_name_ = internal::FromValue<std::string>::Parse(*object_store_name_value, errors);
  } else {
    errors->AddError("required property missing: objectStoreName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearObjectStoreParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("databaseName", internal::ToValue(database_name_));
  result->Set("objectStoreName", internal::ToValue(object_store_name_));
  return std::move(result);
}

std::unique_ptr<ClearObjectStoreParams> ClearObjectStoreParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearObjectStoreParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearObjectStoreResult> ClearObjectStoreResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearObjectStoreResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearObjectStoreResult> result(new ClearObjectStoreResult());
  errors->Push();
  errors->SetName("ClearObjectStoreResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearObjectStoreResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearObjectStoreResult> ClearObjectStoreResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearObjectStoreResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteDatabaseParams> DeleteDatabaseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteDatabaseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteDatabaseParams> result(new DeleteDatabaseParams());
  errors->Push();
  errors->SetName("DeleteDatabaseParams");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* database_name_value = value.FindKey("databaseName");
  if (database_name_value) {
    errors->SetName("databaseName");
    result->database_name_ = internal::FromValue<std::string>::Parse(*database_name_value, errors);
  } else {
    errors->AddError("required property missing: databaseName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteDatabaseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("databaseName", internal::ToValue(database_name_));
  return std::move(result);
}

std::unique_ptr<DeleteDatabaseParams> DeleteDatabaseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteDatabaseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteDatabaseResult> DeleteDatabaseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteDatabaseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteDatabaseResult> result(new DeleteDatabaseResult());
  errors->Push();
  errors->SetName("DeleteDatabaseResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteDatabaseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DeleteDatabaseResult> DeleteDatabaseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteDatabaseResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteObjectStoreEntriesParams> DeleteObjectStoreEntriesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteObjectStoreEntriesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteObjectStoreEntriesParams> result(new DeleteObjectStoreEntriesParams());
  errors->Push();
  errors->SetName("DeleteObjectStoreEntriesParams");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* database_name_value = value.FindKey("databaseName");
  if (database_name_value) {
    errors->SetName("databaseName");
    result->database_name_ = internal::FromValue<std::string>::Parse(*database_name_value, errors);
  } else {
    errors->AddError("required property missing: databaseName");
  }
  const base::Value* object_store_name_value = value.FindKey("objectStoreName");
  if (object_store_name_value) {
    errors->SetName("objectStoreName");
    result->object_store_name_ = internal::FromValue<std::string>::Parse(*object_store_name_value, errors);
  } else {
    errors->AddError("required property missing: objectStoreName");
  }
  const base::Value* key_range_value = value.FindKey("keyRange");
  if (key_range_value) {
    errors->SetName("keyRange");
    result->key_range_ = internal::FromValue<::headless::indexeddb::KeyRange>::Parse(*key_range_value, errors);
  } else {
    errors->AddError("required property missing: keyRange");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteObjectStoreEntriesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("databaseName", internal::ToValue(database_name_));
  result->Set("objectStoreName", internal::ToValue(object_store_name_));
  result->Set("keyRange", internal::ToValue(*key_range_));
  return std::move(result);
}

std::unique_ptr<DeleteObjectStoreEntriesParams> DeleteObjectStoreEntriesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteObjectStoreEntriesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteObjectStoreEntriesResult> DeleteObjectStoreEntriesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteObjectStoreEntriesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteObjectStoreEntriesResult> result(new DeleteObjectStoreEntriesResult());
  errors->Push();
  errors->SetName("DeleteObjectStoreEntriesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteObjectStoreEntriesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DeleteObjectStoreEntriesResult> DeleteObjectStoreEntriesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteObjectStoreEntriesResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<RequestDataParams> RequestDataParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestDataParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestDataParams> result(new RequestDataParams());
  errors->Push();
  errors->SetName("RequestDataParams");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* database_name_value = value.FindKey("databaseName");
  if (database_name_value) {
    errors->SetName("databaseName");
    result->database_name_ = internal::FromValue<std::string>::Parse(*database_name_value, errors);
  } else {
    errors->AddError("required property missing: databaseName");
  }
  const base::Value* object_store_name_value = value.FindKey("objectStoreName");
  if (object_store_name_value) {
    errors->SetName("objectStoreName");
    result->object_store_name_ = internal::FromValue<std::string>::Parse(*object_store_name_value, errors);
  } else {
    errors->AddError("required property missing: objectStoreName");
  }
  const base::Value* index_name_value = value.FindKey("indexName");
  if (index_name_value) {
    errors->SetName("indexName");
    result->index_name_ = internal::FromValue<std::string>::Parse(*index_name_value, errors);
  } else {
    errors->AddError("required property missing: indexName");
  }
  const base::Value* skip_count_value = value.FindKey("skipCount");
  if (skip_count_value) {
    errors->SetName("skipCount");
    result->skip_count_ = internal::FromValue<int>::Parse(*skip_count_value, errors);
  } else {
    errors->AddError("required property missing: skipCount");
  }
  const base::Value* page_size_value = value.FindKey("pageSize");
  if (page_size_value) {
    errors->SetName("pageSize");
    result->page_size_ = internal::FromValue<int>::Parse(*page_size_value, errors);
  } else {
    errors->AddError("required property missing: pageSize");
  }
  const base::Value* key_range_value = value.FindKey("keyRange");
  if (key_range_value) {
    errors->SetName("keyRange");
    result->key_range_ = internal::FromValue<::headless::indexeddb::KeyRange>::Parse(*key_range_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestDataParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("databaseName", internal::ToValue(database_name_));
  result->Set("objectStoreName", internal::ToValue(object_store_name_));
  result->Set("indexName", internal::ToValue(index_name_));
  result->Set("skipCount", internal::ToValue(skip_count_));
  result->Set("pageSize", internal::ToValue(page_size_));
  if (key_range_)
    result->Set("keyRange", internal::ToValue(*key_range_.value()));
  return std::move(result);
}

std::unique_ptr<RequestDataParams> RequestDataParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestDataParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestDataResult> RequestDataResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestDataResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestDataResult> result(new RequestDataResult());
  errors->Push();
  errors->SetName("RequestDataResult");
  const base::Value* object_store_data_entries_value = value.FindKey("objectStoreDataEntries");
  if (object_store_data_entries_value) {
    errors->SetName("objectStoreDataEntries");
    result->object_store_data_entries_ = internal::FromValue<std::vector<std::unique_ptr<::headless::indexeddb::DataEntry>>>::Parse(*object_store_data_entries_value, errors);
  } else {
    errors->AddError("required property missing: objectStoreDataEntries");
  }
  const base::Value* has_more_value = value.FindKey("hasMore");
  if (has_more_value) {
    errors->SetName("hasMore");
    result->has_more_ = internal::FromValue<bool>::Parse(*has_more_value, errors);
  } else {
    errors->AddError("required property missing: hasMore");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestDataResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectStoreDataEntries", internal::ToValue(object_store_data_entries_));
  result->Set("hasMore", internal::ToValue(has_more_));
  return std::move(result);
}

std::unique_ptr<RequestDataResult> RequestDataResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestDataResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetMetadataParams> GetMetadataParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetMetadataParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetMetadataParams> result(new GetMetadataParams());
  errors->Push();
  errors->SetName("GetMetadataParams");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* database_name_value = value.FindKey("databaseName");
  if (database_name_value) {
    errors->SetName("databaseName");
    result->database_name_ = internal::FromValue<std::string>::Parse(*database_name_value, errors);
  } else {
    errors->AddError("required property missing: databaseName");
  }
  const base::Value* object_store_name_value = value.FindKey("objectStoreName");
  if (object_store_name_value) {
    errors->SetName("objectStoreName");
    result->object_store_name_ = internal::FromValue<std::string>::Parse(*object_store_name_value, errors);
  } else {
    errors->AddError("required property missing: objectStoreName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetMetadataParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("databaseName", internal::ToValue(database_name_));
  result->Set("objectStoreName", internal::ToValue(object_store_name_));
  return std::move(result);
}

std::unique_ptr<GetMetadataParams> GetMetadataParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetMetadataParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetMetadataResult> GetMetadataResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetMetadataResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetMetadataResult> result(new GetMetadataResult());
  errors->Push();
  errors->SetName("GetMetadataResult");
  const base::Value* entries_count_value = value.FindKey("entriesCount");
  if (entries_count_value) {
    errors->SetName("entriesCount");
    result->entries_count_ = internal::FromValue<double>::Parse(*entries_count_value, errors);
  } else {
    errors->AddError("required property missing: entriesCount");
  }
  const base::Value* key_generator_value_value = value.FindKey("keyGeneratorValue");
  if (key_generator_value_value) {
    errors->SetName("keyGeneratorValue");
    result->key_generator_value_ = internal::FromValue<double>::Parse(*key_generator_value_value, errors);
  } else {
    errors->AddError("required property missing: keyGeneratorValue");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetMetadataResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("entriesCount", internal::ToValue(entries_count_));
  result->Set("keyGeneratorValue", internal::ToValue(key_generator_value_));
  return std::move(result);
}

std::unique_ptr<GetMetadataResult> GetMetadataResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetMetadataResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestDatabaseParams> RequestDatabaseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestDatabaseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestDatabaseParams> result(new RequestDatabaseParams());
  errors->Push();
  errors->SetName("RequestDatabaseParams");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* database_name_value = value.FindKey("databaseName");
  if (database_name_value) {
    errors->SetName("databaseName");
    result->database_name_ = internal::FromValue<std::string>::Parse(*database_name_value, errors);
  } else {
    errors->AddError("required property missing: databaseName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestDatabaseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("databaseName", internal::ToValue(database_name_));
  return std::move(result);
}

std::unique_ptr<RequestDatabaseParams> RequestDatabaseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestDatabaseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestDatabaseResult> RequestDatabaseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestDatabaseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestDatabaseResult> result(new RequestDatabaseResult());
  errors->Push();
  errors->SetName("RequestDatabaseResult");
  const base::Value* database_with_object_stores_value = value.FindKey("databaseWithObjectStores");
  if (database_with_object_stores_value) {
    errors->SetName("databaseWithObjectStores");
    result->database_with_object_stores_ = internal::FromValue<::headless::indexeddb::DatabaseWithObjectStores>::Parse(*database_with_object_stores_value, errors);
  } else {
    errors->AddError("required property missing: databaseWithObjectStores");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestDatabaseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("databaseWithObjectStores", internal::ToValue(*database_with_object_stores_));
  return std::move(result);
}

std::unique_ptr<RequestDatabaseResult> RequestDatabaseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestDatabaseResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestDatabaseNamesParams> RequestDatabaseNamesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestDatabaseNamesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestDatabaseNamesParams> result(new RequestDatabaseNamesParams());
  errors->Push();
  errors->SetName("RequestDatabaseNamesParams");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestDatabaseNamesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  return std::move(result);
}

std::unique_ptr<RequestDatabaseNamesParams> RequestDatabaseNamesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestDatabaseNamesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestDatabaseNamesResult> RequestDatabaseNamesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestDatabaseNamesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestDatabaseNamesResult> result(new RequestDatabaseNamesResult());
  errors->Push();
  errors->SetName("RequestDatabaseNamesResult");
  const base::Value* database_names_value = value.FindKey("databaseNames");
  if (database_names_value) {
    errors->SetName("databaseNames");
    result->database_names_ = internal::FromValue<std::vector<std::string>>::Parse(*database_names_value, errors);
  } else {
    errors->AddError("required property missing: databaseNames");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestDatabaseNamesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("databaseNames", internal::ToValue(database_names_));
  return std::move(result);
}

std::unique_ptr<RequestDatabaseNamesResult> RequestDatabaseNamesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestDatabaseNamesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace indexeddb
}  // namespace headless
