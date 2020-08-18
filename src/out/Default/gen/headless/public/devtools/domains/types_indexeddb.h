// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_INDEXEDDB_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_INDEXEDDB_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_indexeddb.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace indexeddb {

// Database with an array of object stores.
class HEADLESS_EXPORT DatabaseWithObjectStores {
 public:
  static std::unique_ptr<DatabaseWithObjectStores> Parse(const base::Value& value, ErrorReporter* errors);
  ~DatabaseWithObjectStores() { }

  // Database name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Database version (type is not 'integer', as the standard
  // requires the version number to be 'unsigned long long')
  double GetVersion() const { return version_; }
  void SetVersion(double value) { version_ = value; }

  // Object stores in this database.
  const std::vector<std::unique_ptr<::headless::indexeddb::ObjectStore>>* GetObjectStores() const { return &object_stores_; }
  void SetObjectStores(std::vector<std::unique_ptr<::headless::indexeddb::ObjectStore>> value) { object_stores_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DatabaseWithObjectStores> Clone() const;

  template<int STATE>
  class DatabaseWithObjectStoresBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kVersionSet = 1 << 2,
    kObjectStoresSet = 1 << 3,
      kAllRequiredFieldsSet = (kNameSet | kVersionSet | kObjectStoresSet | 0)
    };

    DatabaseWithObjectStoresBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    DatabaseWithObjectStoresBuilder<STATE | kVersionSet>& SetVersion(double value) {
      static_assert(!(STATE & kVersionSet), "property version should not have already been set");
      result_->SetVersion(value);
      return CastState<kVersionSet>();
    }

    DatabaseWithObjectStoresBuilder<STATE | kObjectStoresSet>& SetObjectStores(std::vector<std::unique_ptr<::headless::indexeddb::ObjectStore>> value) {
      static_assert(!(STATE & kObjectStoresSet), "property objectStores should not have already been set");
      result_->SetObjectStores(std::move(value));
      return CastState<kObjectStoresSet>();
    }

    std::unique_ptr<DatabaseWithObjectStores> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DatabaseWithObjectStores;
    DatabaseWithObjectStoresBuilder() : result_(new DatabaseWithObjectStores()) { }

    template<int STEP> DatabaseWithObjectStoresBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DatabaseWithObjectStoresBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DatabaseWithObjectStores> result_;
  };

  static DatabaseWithObjectStoresBuilder<0> Builder() {
    return DatabaseWithObjectStoresBuilder<0>();
  }

 private:
  DatabaseWithObjectStores() { }

  std::string name_;
  double version_;
  std::vector<std::unique_ptr<::headless::indexeddb::ObjectStore>> object_stores_;

  DISALLOW_COPY_AND_ASSIGN(DatabaseWithObjectStores);
};


// Object store.
class HEADLESS_EXPORT ObjectStore {
 public:
  static std::unique_ptr<ObjectStore> Parse(const base::Value& value, ErrorReporter* errors);
  ~ObjectStore() { }

  // Object store name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Object store key path.
  const ::headless::indexeddb::KeyPath* GetKeyPath() const { return key_path_.get(); }
  void SetKeyPath(std::unique_ptr<::headless::indexeddb::KeyPath> value) { key_path_ = std::move(value); }

  // If true, object store has auto increment flag set.
  bool GetAutoIncrement() const { return auto_increment_; }
  void SetAutoIncrement(bool value) { auto_increment_ = value; }

  // Indexes in this object store.
  const std::vector<std::unique_ptr<::headless::indexeddb::ObjectStoreIndex>>* GetIndexes() const { return &indexes_; }
  void SetIndexes(std::vector<std::unique_ptr<::headless::indexeddb::ObjectStoreIndex>> value) { indexes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ObjectStore> Clone() const;

  template<int STATE>
  class ObjectStoreBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kKeyPathSet = 1 << 2,
    kAutoIncrementSet = 1 << 3,
    kIndexesSet = 1 << 4,
      kAllRequiredFieldsSet = (kNameSet | kKeyPathSet | kAutoIncrementSet | kIndexesSet | 0)
    };

    ObjectStoreBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    ObjectStoreBuilder<STATE | kKeyPathSet>& SetKeyPath(std::unique_ptr<::headless::indexeddb::KeyPath> value) {
      static_assert(!(STATE & kKeyPathSet), "property keyPath should not have already been set");
      result_->SetKeyPath(std::move(value));
      return CastState<kKeyPathSet>();
    }

    ObjectStoreBuilder<STATE | kAutoIncrementSet>& SetAutoIncrement(bool value) {
      static_assert(!(STATE & kAutoIncrementSet), "property autoIncrement should not have already been set");
      result_->SetAutoIncrement(value);
      return CastState<kAutoIncrementSet>();
    }

    ObjectStoreBuilder<STATE | kIndexesSet>& SetIndexes(std::vector<std::unique_ptr<::headless::indexeddb::ObjectStoreIndex>> value) {
      static_assert(!(STATE & kIndexesSet), "property indexes should not have already been set");
      result_->SetIndexes(std::move(value));
      return CastState<kIndexesSet>();
    }

    std::unique_ptr<ObjectStore> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ObjectStore;
    ObjectStoreBuilder() : result_(new ObjectStore()) { }

    template<int STEP> ObjectStoreBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ObjectStoreBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ObjectStore> result_;
  };

  static ObjectStoreBuilder<0> Builder() {
    return ObjectStoreBuilder<0>();
  }

 private:
  ObjectStore() { }

  std::string name_;
  std::unique_ptr<::headless::indexeddb::KeyPath> key_path_;
  bool auto_increment_;
  std::vector<std::unique_ptr<::headless::indexeddb::ObjectStoreIndex>> indexes_;

  DISALLOW_COPY_AND_ASSIGN(ObjectStore);
};


// Object store index.
class HEADLESS_EXPORT ObjectStoreIndex {
 public:
  static std::unique_ptr<ObjectStoreIndex> Parse(const base::Value& value, ErrorReporter* errors);
  ~ObjectStoreIndex() { }

  // Index name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Index key path.
  const ::headless::indexeddb::KeyPath* GetKeyPath() const { return key_path_.get(); }
  void SetKeyPath(std::unique_ptr<::headless::indexeddb::KeyPath> value) { key_path_ = std::move(value); }

  // If true, index is unique.
  bool GetUnique() const { return unique_; }
  void SetUnique(bool value) { unique_ = value; }

  // If true, index allows multiple entries for a key.
  bool GetMultiEntry() const { return multi_entry_; }
  void SetMultiEntry(bool value) { multi_entry_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ObjectStoreIndex> Clone() const;

  template<int STATE>
  class ObjectStoreIndexBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kKeyPathSet = 1 << 2,
    kUniqueSet = 1 << 3,
    kMultiEntrySet = 1 << 4,
      kAllRequiredFieldsSet = (kNameSet | kKeyPathSet | kUniqueSet | kMultiEntrySet | 0)
    };

    ObjectStoreIndexBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    ObjectStoreIndexBuilder<STATE | kKeyPathSet>& SetKeyPath(std::unique_ptr<::headless::indexeddb::KeyPath> value) {
      static_assert(!(STATE & kKeyPathSet), "property keyPath should not have already been set");
      result_->SetKeyPath(std::move(value));
      return CastState<kKeyPathSet>();
    }

    ObjectStoreIndexBuilder<STATE | kUniqueSet>& SetUnique(bool value) {
      static_assert(!(STATE & kUniqueSet), "property unique should not have already been set");
      result_->SetUnique(value);
      return CastState<kUniqueSet>();
    }

    ObjectStoreIndexBuilder<STATE | kMultiEntrySet>& SetMultiEntry(bool value) {
      static_assert(!(STATE & kMultiEntrySet), "property multiEntry should not have already been set");
      result_->SetMultiEntry(value);
      return CastState<kMultiEntrySet>();
    }

    std::unique_ptr<ObjectStoreIndex> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ObjectStoreIndex;
    ObjectStoreIndexBuilder() : result_(new ObjectStoreIndex()) { }

    template<int STEP> ObjectStoreIndexBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ObjectStoreIndexBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ObjectStoreIndex> result_;
  };

  static ObjectStoreIndexBuilder<0> Builder() {
    return ObjectStoreIndexBuilder<0>();
  }

 private:
  ObjectStoreIndex() { }

  std::string name_;
  std::unique_ptr<::headless::indexeddb::KeyPath> key_path_;
  bool unique_;
  bool multi_entry_;

  DISALLOW_COPY_AND_ASSIGN(ObjectStoreIndex);
};


// Key.
class HEADLESS_EXPORT Key {
 public:
  static std::unique_ptr<Key> Parse(const base::Value& value, ErrorReporter* errors);
  ~Key() { }

  // Key type.
  ::headless::indexeddb::KeyType GetType() const { return type_; }
  void SetType(::headless::indexeddb::KeyType value) { type_ = value; }

  // Number value.
  bool HasNumber() const { return !!number_; }
  double GetNumber() const { DCHECK(HasNumber()); return number_.value(); }
  void SetNumber(double value) { number_ = value; }

  // String value.
  bool HasString() const { return !!string_; }
  std::string GetString() const { DCHECK(HasString()); return string_.value(); }
  void SetString(const std::string& value) { string_ = value; }

  // Date value.
  bool HasDate() const { return !!date_; }
  double GetDate() const { DCHECK(HasDate()); return date_.value(); }
  void SetDate(double value) { date_ = value; }

  // Array value.
  bool HasArray() const { return !!array_; }
  const std::vector<std::unique_ptr<::headless::indexeddb::Key>>* GetArray() const { DCHECK(HasArray()); return &array_.value(); }
  void SetArray(std::vector<std::unique_ptr<::headless::indexeddb::Key>> value) { array_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Key> Clone() const;

  template<int STATE>
  class KeyBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    KeyBuilder<STATE | kTypeSet>& SetType(::headless::indexeddb::KeyType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    KeyBuilder<STATE>& SetNumber(double value) {
      result_->SetNumber(value);
      return *this;
    }

    KeyBuilder<STATE>& SetString(const std::string& value) {
      result_->SetString(value);
      return *this;
    }

    KeyBuilder<STATE>& SetDate(double value) {
      result_->SetDate(value);
      return *this;
    }

    KeyBuilder<STATE>& SetArray(std::vector<std::unique_ptr<::headless::indexeddb::Key>> value) {
      result_->SetArray(std::move(value));
      return *this;
    }

    std::unique_ptr<Key> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Key;
    KeyBuilder() : result_(new Key()) { }

    template<int STEP> KeyBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<KeyBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Key> result_;
  };

  static KeyBuilder<0> Builder() {
    return KeyBuilder<0>();
  }

 private:
  Key() { }

  ::headless::indexeddb::KeyType type_;
  base::Optional<double> number_;
  base::Optional<std::string> string_;
  base::Optional<double> date_;
  base::Optional<std::vector<std::unique_ptr<::headless::indexeddb::Key>>> array_;

  DISALLOW_COPY_AND_ASSIGN(Key);
};


// Key range.
class HEADLESS_EXPORT KeyRange {
 public:
  static std::unique_ptr<KeyRange> Parse(const base::Value& value, ErrorReporter* errors);
  ~KeyRange() { }

  // Lower bound.
  bool HasLower() const { return !!lower_; }
  const ::headless::indexeddb::Key* GetLower() const { DCHECK(HasLower()); return lower_.value().get(); }
  void SetLower(std::unique_ptr<::headless::indexeddb::Key> value) { lower_ = std::move(value); }

  // Upper bound.
  bool HasUpper() const { return !!upper_; }
  const ::headless::indexeddb::Key* GetUpper() const { DCHECK(HasUpper()); return upper_.value().get(); }
  void SetUpper(std::unique_ptr<::headless::indexeddb::Key> value) { upper_ = std::move(value); }

  // If true lower bound is open.
  bool GetLowerOpen() const { return lower_open_; }
  void SetLowerOpen(bool value) { lower_open_ = value; }

  // If true upper bound is open.
  bool GetUpperOpen() const { return upper_open_; }
  void SetUpperOpen(bool value) { upper_open_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<KeyRange> Clone() const;

  template<int STATE>
  class KeyRangeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLowerOpenSet = 1 << 1,
    kUpperOpenSet = 1 << 2,
      kAllRequiredFieldsSet = (kLowerOpenSet | kUpperOpenSet | 0)
    };

    KeyRangeBuilder<STATE>& SetLower(std::unique_ptr<::headless::indexeddb::Key> value) {
      result_->SetLower(std::move(value));
      return *this;
    }

    KeyRangeBuilder<STATE>& SetUpper(std::unique_ptr<::headless::indexeddb::Key> value) {
      result_->SetUpper(std::move(value));
      return *this;
    }

    KeyRangeBuilder<STATE | kLowerOpenSet>& SetLowerOpen(bool value) {
      static_assert(!(STATE & kLowerOpenSet), "property lowerOpen should not have already been set");
      result_->SetLowerOpen(value);
      return CastState<kLowerOpenSet>();
    }

    KeyRangeBuilder<STATE | kUpperOpenSet>& SetUpperOpen(bool value) {
      static_assert(!(STATE & kUpperOpenSet), "property upperOpen should not have already been set");
      result_->SetUpperOpen(value);
      return CastState<kUpperOpenSet>();
    }

    std::unique_ptr<KeyRange> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class KeyRange;
    KeyRangeBuilder() : result_(new KeyRange()) { }

    template<int STEP> KeyRangeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<KeyRangeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<KeyRange> result_;
  };

  static KeyRangeBuilder<0> Builder() {
    return KeyRangeBuilder<0>();
  }

 private:
  KeyRange() { }

  base::Optional<std::unique_ptr<::headless::indexeddb::Key>> lower_;
  base::Optional<std::unique_ptr<::headless::indexeddb::Key>> upper_;
  bool lower_open_;
  bool upper_open_;

  DISALLOW_COPY_AND_ASSIGN(KeyRange);
};


// Data entry.
class HEADLESS_EXPORT DataEntry {
 public:
  static std::unique_ptr<DataEntry> Parse(const base::Value& value, ErrorReporter* errors);
  ~DataEntry() { }

  // Key object.
  const ::headless::runtime::RemoteObject* GetKey() const { return key_.get(); }
  void SetKey(std::unique_ptr<::headless::runtime::RemoteObject> value) { key_ = std::move(value); }

  // Primary key object.
  const ::headless::runtime::RemoteObject* GetPrimaryKey() const { return primary_key_.get(); }
  void SetPrimaryKey(std::unique_ptr<::headless::runtime::RemoteObject> value) { primary_key_ = std::move(value); }

  // Value object.
  const ::headless::runtime::RemoteObject* GetValue() const { return value_.get(); }
  void SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) { value_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DataEntry> Clone() const;

  template<int STATE>
  class DataEntryBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kKeySet = 1 << 1,
    kPrimaryKeySet = 1 << 2,
    kValueSet = 1 << 3,
      kAllRequiredFieldsSet = (kKeySet | kPrimaryKeySet | kValueSet | 0)
    };

    DataEntryBuilder<STATE | kKeySet>& SetKey(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kKeySet), "property key should not have already been set");
      result_->SetKey(std::move(value));
      return CastState<kKeySet>();
    }

    DataEntryBuilder<STATE | kPrimaryKeySet>& SetPrimaryKey(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kPrimaryKeySet), "property primaryKey should not have already been set");
      result_->SetPrimaryKey(std::move(value));
      return CastState<kPrimaryKeySet>();
    }

    DataEntryBuilder<STATE | kValueSet>& SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(std::move(value));
      return CastState<kValueSet>();
    }

    std::unique_ptr<DataEntry> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DataEntry;
    DataEntryBuilder() : result_(new DataEntry()) { }

    template<int STEP> DataEntryBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DataEntryBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DataEntry> result_;
  };

  static DataEntryBuilder<0> Builder() {
    return DataEntryBuilder<0>();
  }

 private:
  DataEntry() { }

  std::unique_ptr<::headless::runtime::RemoteObject> key_;
  std::unique_ptr<::headless::runtime::RemoteObject> primary_key_;
  std::unique_ptr<::headless::runtime::RemoteObject> value_;

  DISALLOW_COPY_AND_ASSIGN(DataEntry);
};


// Key path.
class HEADLESS_EXPORT KeyPath {
 public:
  static std::unique_ptr<KeyPath> Parse(const base::Value& value, ErrorReporter* errors);
  ~KeyPath() { }

  // Key path type.
  ::headless::indexeddb::KeyPathType GetType() const { return type_; }
  void SetType(::headless::indexeddb::KeyPathType value) { type_ = value; }

  // String value.
  bool HasString() const { return !!string_; }
  std::string GetString() const { DCHECK(HasString()); return string_.value(); }
  void SetString(const std::string& value) { string_ = value; }

  // Array value.
  bool HasArray() const { return !!array_; }
  const std::vector<std::string>* GetArray() const { DCHECK(HasArray()); return &array_.value(); }
  void SetArray(std::vector<std::string> value) { array_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<KeyPath> Clone() const;

  template<int STATE>
  class KeyPathBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    KeyPathBuilder<STATE | kTypeSet>& SetType(::headless::indexeddb::KeyPathType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    KeyPathBuilder<STATE>& SetString(const std::string& value) {
      result_->SetString(value);
      return *this;
    }

    KeyPathBuilder<STATE>& SetArray(std::vector<std::string> value) {
      result_->SetArray(std::move(value));
      return *this;
    }

    std::unique_ptr<KeyPath> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class KeyPath;
    KeyPathBuilder() : result_(new KeyPath()) { }

    template<int STEP> KeyPathBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<KeyPathBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<KeyPath> result_;
  };

  static KeyPathBuilder<0> Builder() {
    return KeyPathBuilder<0>();
  }

 private:
  KeyPath() { }

  ::headless::indexeddb::KeyPathType type_;
  base::Optional<std::string> string_;
  base::Optional<std::vector<std::string>> array_;

  DISALLOW_COPY_AND_ASSIGN(KeyPath);
};


// Parameters for the ClearObjectStore command.
class HEADLESS_EXPORT ClearObjectStoreParams {
 public:
  static std::unique_ptr<ClearObjectStoreParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearObjectStoreParams() { }

  // Security origin.
  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  // Database name.
  std::string GetDatabaseName() const { return database_name_; }
  void SetDatabaseName(const std::string& value) { database_name_ = value; }

  // Object store name.
  std::string GetObjectStoreName() const { return object_store_name_; }
  void SetObjectStoreName(const std::string& value) { object_store_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearObjectStoreParams> Clone() const;

  template<int STATE>
  class ClearObjectStoreParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityOriginSet = 1 << 1,
    kDatabaseNameSet = 1 << 2,
    kObjectStoreNameSet = 1 << 3,
      kAllRequiredFieldsSet = (kSecurityOriginSet | kDatabaseNameSet | kObjectStoreNameSet | 0)
    };

    ClearObjectStoreParamsBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    ClearObjectStoreParamsBuilder<STATE | kDatabaseNameSet>& SetDatabaseName(const std::string& value) {
      static_assert(!(STATE & kDatabaseNameSet), "property databaseName should not have already been set");
      result_->SetDatabaseName(value);
      return CastState<kDatabaseNameSet>();
    }

    ClearObjectStoreParamsBuilder<STATE | kObjectStoreNameSet>& SetObjectStoreName(const std::string& value) {
      static_assert(!(STATE & kObjectStoreNameSet), "property objectStoreName should not have already been set");
      result_->SetObjectStoreName(value);
      return CastState<kObjectStoreNameSet>();
    }

    std::unique_ptr<ClearObjectStoreParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearObjectStoreParams;
    ClearObjectStoreParamsBuilder() : result_(new ClearObjectStoreParams()) { }

    template<int STEP> ClearObjectStoreParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearObjectStoreParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearObjectStoreParams> result_;
  };

  static ClearObjectStoreParamsBuilder<0> Builder() {
    return ClearObjectStoreParamsBuilder<0>();
  }

 private:
  ClearObjectStoreParams() { }

  std::string security_origin_;
  std::string database_name_;
  std::string object_store_name_;

  DISALLOW_COPY_AND_ASSIGN(ClearObjectStoreParams);
};


// Result for the ClearObjectStore command.
class HEADLESS_EXPORT ClearObjectStoreResult {
 public:
  static std::unique_ptr<ClearObjectStoreResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearObjectStoreResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearObjectStoreResult> Clone() const;

  template<int STATE>
  class ClearObjectStoreResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearObjectStoreResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearObjectStoreResult;
    ClearObjectStoreResultBuilder() : result_(new ClearObjectStoreResult()) { }

    template<int STEP> ClearObjectStoreResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearObjectStoreResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearObjectStoreResult> result_;
  };

  static ClearObjectStoreResultBuilder<0> Builder() {
    return ClearObjectStoreResultBuilder<0>();
  }

 private:
  ClearObjectStoreResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearObjectStoreResult);
};


// Parameters for the DeleteDatabase command.
class HEADLESS_EXPORT DeleteDatabaseParams {
 public:
  static std::unique_ptr<DeleteDatabaseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteDatabaseParams() { }

  // Security origin.
  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  // Database name.
  std::string GetDatabaseName() const { return database_name_; }
  void SetDatabaseName(const std::string& value) { database_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteDatabaseParams> Clone() const;

  template<int STATE>
  class DeleteDatabaseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityOriginSet = 1 << 1,
    kDatabaseNameSet = 1 << 2,
      kAllRequiredFieldsSet = (kSecurityOriginSet | kDatabaseNameSet | 0)
    };

    DeleteDatabaseParamsBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    DeleteDatabaseParamsBuilder<STATE | kDatabaseNameSet>& SetDatabaseName(const std::string& value) {
      static_assert(!(STATE & kDatabaseNameSet), "property databaseName should not have already been set");
      result_->SetDatabaseName(value);
      return CastState<kDatabaseNameSet>();
    }

    std::unique_ptr<DeleteDatabaseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteDatabaseParams;
    DeleteDatabaseParamsBuilder() : result_(new DeleteDatabaseParams()) { }

    template<int STEP> DeleteDatabaseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteDatabaseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteDatabaseParams> result_;
  };

  static DeleteDatabaseParamsBuilder<0> Builder() {
    return DeleteDatabaseParamsBuilder<0>();
  }

 private:
  DeleteDatabaseParams() { }

  std::string security_origin_;
  std::string database_name_;

  DISALLOW_COPY_AND_ASSIGN(DeleteDatabaseParams);
};


// Result for the DeleteDatabase command.
class HEADLESS_EXPORT DeleteDatabaseResult {
 public:
  static std::unique_ptr<DeleteDatabaseResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteDatabaseResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteDatabaseResult> Clone() const;

  template<int STATE>
  class DeleteDatabaseResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DeleteDatabaseResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteDatabaseResult;
    DeleteDatabaseResultBuilder() : result_(new DeleteDatabaseResult()) { }

    template<int STEP> DeleteDatabaseResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteDatabaseResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteDatabaseResult> result_;
  };

  static DeleteDatabaseResultBuilder<0> Builder() {
    return DeleteDatabaseResultBuilder<0>();
  }

 private:
  DeleteDatabaseResult() { }


  DISALLOW_COPY_AND_ASSIGN(DeleteDatabaseResult);
};


// Parameters for the DeleteObjectStoreEntries command.
class HEADLESS_EXPORT DeleteObjectStoreEntriesParams {
 public:
  static std::unique_ptr<DeleteObjectStoreEntriesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteObjectStoreEntriesParams() { }

  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  std::string GetDatabaseName() const { return database_name_; }
  void SetDatabaseName(const std::string& value) { database_name_ = value; }

  std::string GetObjectStoreName() const { return object_store_name_; }
  void SetObjectStoreName(const std::string& value) { object_store_name_ = value; }

  // Range of entry keys to delete
  const ::headless::indexeddb::KeyRange* GetKeyRange() const { return key_range_.get(); }
  void SetKeyRange(std::unique_ptr<::headless::indexeddb::KeyRange> value) { key_range_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteObjectStoreEntriesParams> Clone() const;

  template<int STATE>
  class DeleteObjectStoreEntriesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityOriginSet = 1 << 1,
    kDatabaseNameSet = 1 << 2,
    kObjectStoreNameSet = 1 << 3,
    kKeyRangeSet = 1 << 4,
      kAllRequiredFieldsSet = (kSecurityOriginSet | kDatabaseNameSet | kObjectStoreNameSet | kKeyRangeSet | 0)
    };

    DeleteObjectStoreEntriesParamsBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    DeleteObjectStoreEntriesParamsBuilder<STATE | kDatabaseNameSet>& SetDatabaseName(const std::string& value) {
      static_assert(!(STATE & kDatabaseNameSet), "property databaseName should not have already been set");
      result_->SetDatabaseName(value);
      return CastState<kDatabaseNameSet>();
    }

    DeleteObjectStoreEntriesParamsBuilder<STATE | kObjectStoreNameSet>& SetObjectStoreName(const std::string& value) {
      static_assert(!(STATE & kObjectStoreNameSet), "property objectStoreName should not have already been set");
      result_->SetObjectStoreName(value);
      return CastState<kObjectStoreNameSet>();
    }

    DeleteObjectStoreEntriesParamsBuilder<STATE | kKeyRangeSet>& SetKeyRange(std::unique_ptr<::headless::indexeddb::KeyRange> value) {
      static_assert(!(STATE & kKeyRangeSet), "property keyRange should not have already been set");
      result_->SetKeyRange(std::move(value));
      return CastState<kKeyRangeSet>();
    }

    std::unique_ptr<DeleteObjectStoreEntriesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteObjectStoreEntriesParams;
    DeleteObjectStoreEntriesParamsBuilder() : result_(new DeleteObjectStoreEntriesParams()) { }

    template<int STEP> DeleteObjectStoreEntriesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteObjectStoreEntriesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteObjectStoreEntriesParams> result_;
  };

  static DeleteObjectStoreEntriesParamsBuilder<0> Builder() {
    return DeleteObjectStoreEntriesParamsBuilder<0>();
  }

 private:
  DeleteObjectStoreEntriesParams() { }

  std::string security_origin_;
  std::string database_name_;
  std::string object_store_name_;
  std::unique_ptr<::headless::indexeddb::KeyRange> key_range_;

  DISALLOW_COPY_AND_ASSIGN(DeleteObjectStoreEntriesParams);
};


// Result for the DeleteObjectStoreEntries command.
class HEADLESS_EXPORT DeleteObjectStoreEntriesResult {
 public:
  static std::unique_ptr<DeleteObjectStoreEntriesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteObjectStoreEntriesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteObjectStoreEntriesResult> Clone() const;

  template<int STATE>
  class DeleteObjectStoreEntriesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DeleteObjectStoreEntriesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteObjectStoreEntriesResult;
    DeleteObjectStoreEntriesResultBuilder() : result_(new DeleteObjectStoreEntriesResult()) { }

    template<int STEP> DeleteObjectStoreEntriesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteObjectStoreEntriesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteObjectStoreEntriesResult> result_;
  };

  static DeleteObjectStoreEntriesResultBuilder<0> Builder() {
    return DeleteObjectStoreEntriesResultBuilder<0>();
  }

 private:
  DeleteObjectStoreEntriesResult() { }


  DISALLOW_COPY_AND_ASSIGN(DeleteObjectStoreEntriesResult);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the RequestData command.
class HEADLESS_EXPORT RequestDataParams {
 public:
  static std::unique_ptr<RequestDataParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestDataParams() { }

  // Security origin.
  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  // Database name.
  std::string GetDatabaseName() const { return database_name_; }
  void SetDatabaseName(const std::string& value) { database_name_ = value; }

  // Object store name.
  std::string GetObjectStoreName() const { return object_store_name_; }
  void SetObjectStoreName(const std::string& value) { object_store_name_ = value; }

  // Index name, empty string for object store data requests.
  std::string GetIndexName() const { return index_name_; }
  void SetIndexName(const std::string& value) { index_name_ = value; }

  // Number of records to skip.
  int GetSkipCount() const { return skip_count_; }
  void SetSkipCount(int value) { skip_count_ = value; }

  // Number of records to fetch.
  int GetPageSize() const { return page_size_; }
  void SetPageSize(int value) { page_size_ = value; }

  // Key range.
  bool HasKeyRange() const { return !!key_range_; }
  const ::headless::indexeddb::KeyRange* GetKeyRange() const { DCHECK(HasKeyRange()); return key_range_.value().get(); }
  void SetKeyRange(std::unique_ptr<::headless::indexeddb::KeyRange> value) { key_range_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestDataParams> Clone() const;

  template<int STATE>
  class RequestDataParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityOriginSet = 1 << 1,
    kDatabaseNameSet = 1 << 2,
    kObjectStoreNameSet = 1 << 3,
    kIndexNameSet = 1 << 4,
    kSkipCountSet = 1 << 5,
    kPageSizeSet = 1 << 6,
      kAllRequiredFieldsSet = (kSecurityOriginSet | kDatabaseNameSet | kObjectStoreNameSet | kIndexNameSet | kSkipCountSet | kPageSizeSet | 0)
    };

    RequestDataParamsBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    RequestDataParamsBuilder<STATE | kDatabaseNameSet>& SetDatabaseName(const std::string& value) {
      static_assert(!(STATE & kDatabaseNameSet), "property databaseName should not have already been set");
      result_->SetDatabaseName(value);
      return CastState<kDatabaseNameSet>();
    }

    RequestDataParamsBuilder<STATE | kObjectStoreNameSet>& SetObjectStoreName(const std::string& value) {
      static_assert(!(STATE & kObjectStoreNameSet), "property objectStoreName should not have already been set");
      result_->SetObjectStoreName(value);
      return CastState<kObjectStoreNameSet>();
    }

    RequestDataParamsBuilder<STATE | kIndexNameSet>& SetIndexName(const std::string& value) {
      static_assert(!(STATE & kIndexNameSet), "property indexName should not have already been set");
      result_->SetIndexName(value);
      return CastState<kIndexNameSet>();
    }

    RequestDataParamsBuilder<STATE | kSkipCountSet>& SetSkipCount(int value) {
      static_assert(!(STATE & kSkipCountSet), "property skipCount should not have already been set");
      result_->SetSkipCount(value);
      return CastState<kSkipCountSet>();
    }

    RequestDataParamsBuilder<STATE | kPageSizeSet>& SetPageSize(int value) {
      static_assert(!(STATE & kPageSizeSet), "property pageSize should not have already been set");
      result_->SetPageSize(value);
      return CastState<kPageSizeSet>();
    }

    RequestDataParamsBuilder<STATE>& SetKeyRange(std::unique_ptr<::headless::indexeddb::KeyRange> value) {
      result_->SetKeyRange(std::move(value));
      return *this;
    }

    std::unique_ptr<RequestDataParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestDataParams;
    RequestDataParamsBuilder() : result_(new RequestDataParams()) { }

    template<int STEP> RequestDataParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestDataParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestDataParams> result_;
  };

  static RequestDataParamsBuilder<0> Builder() {
    return RequestDataParamsBuilder<0>();
  }

 private:
  RequestDataParams() { }

  std::string security_origin_;
  std::string database_name_;
  std::string object_store_name_;
  std::string index_name_;
  int skip_count_;
  int page_size_;
  base::Optional<std::unique_ptr<::headless::indexeddb::KeyRange>> key_range_;

  DISALLOW_COPY_AND_ASSIGN(RequestDataParams);
};


// Result for the RequestData command.
class HEADLESS_EXPORT RequestDataResult {
 public:
  static std::unique_ptr<RequestDataResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestDataResult() { }

  // Array of object store data entries.
  const std::vector<std::unique_ptr<::headless::indexeddb::DataEntry>>* GetObjectStoreDataEntries() const { return &object_store_data_entries_; }
  void SetObjectStoreDataEntries(std::vector<std::unique_ptr<::headless::indexeddb::DataEntry>> value) { object_store_data_entries_ = std::move(value); }

  // If true, there are more entries to fetch in the given range.
  bool GetHasMore() const { return has_more_; }
  void SetHasMore(bool value) { has_more_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestDataResult> Clone() const;

  template<int STATE>
  class RequestDataResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectStoreDataEntriesSet = 1 << 1,
    kHasMoreSet = 1 << 2,
      kAllRequiredFieldsSet = (kObjectStoreDataEntriesSet | kHasMoreSet | 0)
    };

    RequestDataResultBuilder<STATE | kObjectStoreDataEntriesSet>& SetObjectStoreDataEntries(std::vector<std::unique_ptr<::headless::indexeddb::DataEntry>> value) {
      static_assert(!(STATE & kObjectStoreDataEntriesSet), "property objectStoreDataEntries should not have already been set");
      result_->SetObjectStoreDataEntries(std::move(value));
      return CastState<kObjectStoreDataEntriesSet>();
    }

    RequestDataResultBuilder<STATE | kHasMoreSet>& SetHasMore(bool value) {
      static_assert(!(STATE & kHasMoreSet), "property hasMore should not have already been set");
      result_->SetHasMore(value);
      return CastState<kHasMoreSet>();
    }

    std::unique_ptr<RequestDataResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestDataResult;
    RequestDataResultBuilder() : result_(new RequestDataResult()) { }

    template<int STEP> RequestDataResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestDataResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestDataResult> result_;
  };

  static RequestDataResultBuilder<0> Builder() {
    return RequestDataResultBuilder<0>();
  }

 private:
  RequestDataResult() { }

  std::vector<std::unique_ptr<::headless::indexeddb::DataEntry>> object_store_data_entries_;
  bool has_more_;

  DISALLOW_COPY_AND_ASSIGN(RequestDataResult);
};


// Parameters for the GetMetadata command.
class HEADLESS_EXPORT GetMetadataParams {
 public:
  static std::unique_ptr<GetMetadataParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetMetadataParams() { }

  // Security origin.
  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  // Database name.
  std::string GetDatabaseName() const { return database_name_; }
  void SetDatabaseName(const std::string& value) { database_name_ = value; }

  // Object store name.
  std::string GetObjectStoreName() const { return object_store_name_; }
  void SetObjectStoreName(const std::string& value) { object_store_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetMetadataParams> Clone() const;

  template<int STATE>
  class GetMetadataParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityOriginSet = 1 << 1,
    kDatabaseNameSet = 1 << 2,
    kObjectStoreNameSet = 1 << 3,
      kAllRequiredFieldsSet = (kSecurityOriginSet | kDatabaseNameSet | kObjectStoreNameSet | 0)
    };

    GetMetadataParamsBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    GetMetadataParamsBuilder<STATE | kDatabaseNameSet>& SetDatabaseName(const std::string& value) {
      static_assert(!(STATE & kDatabaseNameSet), "property databaseName should not have already been set");
      result_->SetDatabaseName(value);
      return CastState<kDatabaseNameSet>();
    }

    GetMetadataParamsBuilder<STATE | kObjectStoreNameSet>& SetObjectStoreName(const std::string& value) {
      static_assert(!(STATE & kObjectStoreNameSet), "property objectStoreName should not have already been set");
      result_->SetObjectStoreName(value);
      return CastState<kObjectStoreNameSet>();
    }

    std::unique_ptr<GetMetadataParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetMetadataParams;
    GetMetadataParamsBuilder() : result_(new GetMetadataParams()) { }

    template<int STEP> GetMetadataParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetMetadataParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetMetadataParams> result_;
  };

  static GetMetadataParamsBuilder<0> Builder() {
    return GetMetadataParamsBuilder<0>();
  }

 private:
  GetMetadataParams() { }

  std::string security_origin_;
  std::string database_name_;
  std::string object_store_name_;

  DISALLOW_COPY_AND_ASSIGN(GetMetadataParams);
};


// Result for the GetMetadata command.
class HEADLESS_EXPORT GetMetadataResult {
 public:
  static std::unique_ptr<GetMetadataResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetMetadataResult() { }

  // the entries count
  double GetEntriesCount() const { return entries_count_; }
  void SetEntriesCount(double value) { entries_count_ = value; }

  // the current value of key generator, to become the next inserted
  // key into the object store. Valid if objectStore.autoIncrement
  // is true.
  double GetKeyGeneratorValue() const { return key_generator_value_; }
  void SetKeyGeneratorValue(double value) { key_generator_value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetMetadataResult> Clone() const;

  template<int STATE>
  class GetMetadataResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEntriesCountSet = 1 << 1,
    kKeyGeneratorValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kEntriesCountSet | kKeyGeneratorValueSet | 0)
    };

    GetMetadataResultBuilder<STATE | kEntriesCountSet>& SetEntriesCount(double value) {
      static_assert(!(STATE & kEntriesCountSet), "property entriesCount should not have already been set");
      result_->SetEntriesCount(value);
      return CastState<kEntriesCountSet>();
    }

    GetMetadataResultBuilder<STATE | kKeyGeneratorValueSet>& SetKeyGeneratorValue(double value) {
      static_assert(!(STATE & kKeyGeneratorValueSet), "property keyGeneratorValue should not have already been set");
      result_->SetKeyGeneratorValue(value);
      return CastState<kKeyGeneratorValueSet>();
    }

    std::unique_ptr<GetMetadataResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetMetadataResult;
    GetMetadataResultBuilder() : result_(new GetMetadataResult()) { }

    template<int STEP> GetMetadataResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetMetadataResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetMetadataResult> result_;
  };

  static GetMetadataResultBuilder<0> Builder() {
    return GetMetadataResultBuilder<0>();
  }

 private:
  GetMetadataResult() { }

  double entries_count_;
  double key_generator_value_;

  DISALLOW_COPY_AND_ASSIGN(GetMetadataResult);
};


// Parameters for the RequestDatabase command.
class HEADLESS_EXPORT RequestDatabaseParams {
 public:
  static std::unique_ptr<RequestDatabaseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestDatabaseParams() { }

  // Security origin.
  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  // Database name.
  std::string GetDatabaseName() const { return database_name_; }
  void SetDatabaseName(const std::string& value) { database_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestDatabaseParams> Clone() const;

  template<int STATE>
  class RequestDatabaseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityOriginSet = 1 << 1,
    kDatabaseNameSet = 1 << 2,
      kAllRequiredFieldsSet = (kSecurityOriginSet | kDatabaseNameSet | 0)
    };

    RequestDatabaseParamsBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    RequestDatabaseParamsBuilder<STATE | kDatabaseNameSet>& SetDatabaseName(const std::string& value) {
      static_assert(!(STATE & kDatabaseNameSet), "property databaseName should not have already been set");
      result_->SetDatabaseName(value);
      return CastState<kDatabaseNameSet>();
    }

    std::unique_ptr<RequestDatabaseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestDatabaseParams;
    RequestDatabaseParamsBuilder() : result_(new RequestDatabaseParams()) { }

    template<int STEP> RequestDatabaseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestDatabaseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestDatabaseParams> result_;
  };

  static RequestDatabaseParamsBuilder<0> Builder() {
    return RequestDatabaseParamsBuilder<0>();
  }

 private:
  RequestDatabaseParams() { }

  std::string security_origin_;
  std::string database_name_;

  DISALLOW_COPY_AND_ASSIGN(RequestDatabaseParams);
};


// Result for the RequestDatabase command.
class HEADLESS_EXPORT RequestDatabaseResult {
 public:
  static std::unique_ptr<RequestDatabaseResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestDatabaseResult() { }

  // Database with an array of object stores.
  const ::headless::indexeddb::DatabaseWithObjectStores* GetDatabaseWithObjectStores() const { return database_with_object_stores_.get(); }
  void SetDatabaseWithObjectStores(std::unique_ptr<::headless::indexeddb::DatabaseWithObjectStores> value) { database_with_object_stores_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestDatabaseResult> Clone() const;

  template<int STATE>
  class RequestDatabaseResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDatabaseWithObjectStoresSet = 1 << 1,
      kAllRequiredFieldsSet = (kDatabaseWithObjectStoresSet | 0)
    };

    RequestDatabaseResultBuilder<STATE | kDatabaseWithObjectStoresSet>& SetDatabaseWithObjectStores(std::unique_ptr<::headless::indexeddb::DatabaseWithObjectStores> value) {
      static_assert(!(STATE & kDatabaseWithObjectStoresSet), "property databaseWithObjectStores should not have already been set");
      result_->SetDatabaseWithObjectStores(std::move(value));
      return CastState<kDatabaseWithObjectStoresSet>();
    }

    std::unique_ptr<RequestDatabaseResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestDatabaseResult;
    RequestDatabaseResultBuilder() : result_(new RequestDatabaseResult()) { }

    template<int STEP> RequestDatabaseResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestDatabaseResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestDatabaseResult> result_;
  };

  static RequestDatabaseResultBuilder<0> Builder() {
    return RequestDatabaseResultBuilder<0>();
  }

 private:
  RequestDatabaseResult() { }

  std::unique_ptr<::headless::indexeddb::DatabaseWithObjectStores> database_with_object_stores_;

  DISALLOW_COPY_AND_ASSIGN(RequestDatabaseResult);
};


// Parameters for the RequestDatabaseNames command.
class HEADLESS_EXPORT RequestDatabaseNamesParams {
 public:
  static std::unique_ptr<RequestDatabaseNamesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestDatabaseNamesParams() { }

  // Security origin.
  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestDatabaseNamesParams> Clone() const;

  template<int STATE>
  class RequestDatabaseNamesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSecurityOriginSet = 1 << 1,
      kAllRequiredFieldsSet = (kSecurityOriginSet | 0)
    };

    RequestDatabaseNamesParamsBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    std::unique_ptr<RequestDatabaseNamesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestDatabaseNamesParams;
    RequestDatabaseNamesParamsBuilder() : result_(new RequestDatabaseNamesParams()) { }

    template<int STEP> RequestDatabaseNamesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestDatabaseNamesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestDatabaseNamesParams> result_;
  };

  static RequestDatabaseNamesParamsBuilder<0> Builder() {
    return RequestDatabaseNamesParamsBuilder<0>();
  }

 private:
  RequestDatabaseNamesParams() { }

  std::string security_origin_;

  DISALLOW_COPY_AND_ASSIGN(RequestDatabaseNamesParams);
};


// Result for the RequestDatabaseNames command.
class HEADLESS_EXPORT RequestDatabaseNamesResult {
 public:
  static std::unique_ptr<RequestDatabaseNamesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestDatabaseNamesResult() { }

  // Database names for origin.
  const std::vector<std::string>* GetDatabaseNames() const { return &database_names_; }
  void SetDatabaseNames(std::vector<std::string> value) { database_names_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestDatabaseNamesResult> Clone() const;

  template<int STATE>
  class RequestDatabaseNamesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDatabaseNamesSet = 1 << 1,
      kAllRequiredFieldsSet = (kDatabaseNamesSet | 0)
    };

    RequestDatabaseNamesResultBuilder<STATE | kDatabaseNamesSet>& SetDatabaseNames(std::vector<std::string> value) {
      static_assert(!(STATE & kDatabaseNamesSet), "property databaseNames should not have already been set");
      result_->SetDatabaseNames(std::move(value));
      return CastState<kDatabaseNamesSet>();
    }

    std::unique_ptr<RequestDatabaseNamesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestDatabaseNamesResult;
    RequestDatabaseNamesResultBuilder() : result_(new RequestDatabaseNamesResult()) { }

    template<int STEP> RequestDatabaseNamesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestDatabaseNamesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestDatabaseNamesResult> result_;
  };

  static RequestDatabaseNamesResultBuilder<0> Builder() {
    return RequestDatabaseNamesResultBuilder<0>();
  }

 private:
  RequestDatabaseNamesResult() { }

  std::vector<std::string> database_names_;

  DISALLOW_COPY_AND_ASSIGN(RequestDatabaseNamesResult);
};


}  // namespace indexeddb

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_INDEXEDDB_H_
