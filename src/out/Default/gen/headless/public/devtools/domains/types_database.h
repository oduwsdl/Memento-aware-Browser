// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DATABASE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DATABASE_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_database.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace database {

// Database object.
class HEADLESS_EXPORT Database {
 public:
  static std::unique_ptr<Database> Parse(const base::Value& value, ErrorReporter* errors);
  ~Database() { }

  // Database ID.
  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  // Database domain.
  std::string GetDomain() const { return domain_; }
  void SetDomain(const std::string& value) { domain_ = value; }

  // Database name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Database version.
  std::string GetVersion() const { return version_; }
  void SetVersion(const std::string& value) { version_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Database> Clone() const;

  template<int STATE>
  class DatabaseBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kDomainSet = 1 << 2,
    kNameSet = 1 << 3,
    kVersionSet = 1 << 4,
      kAllRequiredFieldsSet = (kIdSet | kDomainSet | kNameSet | kVersionSet | 0)
    };

    DatabaseBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    DatabaseBuilder<STATE | kDomainSet>& SetDomain(const std::string& value) {
      static_assert(!(STATE & kDomainSet), "property domain should not have already been set");
      result_->SetDomain(value);
      return CastState<kDomainSet>();
    }

    DatabaseBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    DatabaseBuilder<STATE | kVersionSet>& SetVersion(const std::string& value) {
      static_assert(!(STATE & kVersionSet), "property version should not have already been set");
      result_->SetVersion(value);
      return CastState<kVersionSet>();
    }

    std::unique_ptr<Database> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Database;
    DatabaseBuilder() : result_(new Database()) { }

    template<int STEP> DatabaseBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DatabaseBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Database> result_;
  };

  static DatabaseBuilder<0> Builder() {
    return DatabaseBuilder<0>();
  }

 private:
  Database() { }

  std::string id_;
  std::string domain_;
  std::string name_;
  std::string version_;

  DISALLOW_COPY_AND_ASSIGN(Database);
};


// Database error.
class HEADLESS_EXPORT Error {
 public:
  static std::unique_ptr<Error> Parse(const base::Value& value, ErrorReporter* errors);
  ~Error() { }

  // Error message.
  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  // Error code.
  int GetCode() const { return code_; }
  void SetCode(int value) { code_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Error> Clone() const;

  template<int STATE>
  class ErrorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMessageSet = 1 << 1,
    kCodeSet = 1 << 2,
      kAllRequiredFieldsSet = (kMessageSet | kCodeSet | 0)
    };

    ErrorBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    ErrorBuilder<STATE | kCodeSet>& SetCode(int value) {
      static_assert(!(STATE & kCodeSet), "property code should not have already been set");
      result_->SetCode(value);
      return CastState<kCodeSet>();
    }

    std::unique_ptr<Error> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Error;
    ErrorBuilder() : result_(new Error()) { }

    template<int STEP> ErrorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ErrorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Error> result_;
  };

  static ErrorBuilder<0> Builder() {
    return ErrorBuilder<0>();
  }

 private:
  Error() { }

  std::string message_;
  int code_;

  DISALLOW_COPY_AND_ASSIGN(Error);
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


// Parameters for the ExecuteSQL command.
class HEADLESS_EXPORT ExecuteSQLParams {
 public:
  static std::unique_ptr<ExecuteSQLParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExecuteSQLParams() { }

  std::string GetDatabaseId() const { return database_id_; }
  void SetDatabaseId(const std::string& value) { database_id_ = value; }

  std::string GetQuery() const { return query_; }
  void SetQuery(const std::string& value) { query_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExecuteSQLParams> Clone() const;

  template<int STATE>
  class ExecuteSQLParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDatabaseIdSet = 1 << 1,
    kQuerySet = 1 << 2,
      kAllRequiredFieldsSet = (kDatabaseIdSet | kQuerySet | 0)
    };

    ExecuteSQLParamsBuilder<STATE | kDatabaseIdSet>& SetDatabaseId(const std::string& value) {
      static_assert(!(STATE & kDatabaseIdSet), "property databaseId should not have already been set");
      result_->SetDatabaseId(value);
      return CastState<kDatabaseIdSet>();
    }

    ExecuteSQLParamsBuilder<STATE | kQuerySet>& SetQuery(const std::string& value) {
      static_assert(!(STATE & kQuerySet), "property query should not have already been set");
      result_->SetQuery(value);
      return CastState<kQuerySet>();
    }

    std::unique_ptr<ExecuteSQLParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExecuteSQLParams;
    ExecuteSQLParamsBuilder() : result_(new ExecuteSQLParams()) { }

    template<int STEP> ExecuteSQLParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExecuteSQLParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExecuteSQLParams> result_;
  };

  static ExecuteSQLParamsBuilder<0> Builder() {
    return ExecuteSQLParamsBuilder<0>();
  }

 private:
  ExecuteSQLParams() { }

  std::string database_id_;
  std::string query_;

  DISALLOW_COPY_AND_ASSIGN(ExecuteSQLParams);
};


// Result for the ExecuteSQL command.
class HEADLESS_EXPORT ExecuteSQLResult {
 public:
  static std::unique_ptr<ExecuteSQLResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExecuteSQLResult() { }

  bool HasColumnNames() const { return !!column_names_; }
  const std::vector<std::string>* GetColumnNames() const { DCHECK(HasColumnNames()); return &column_names_.value(); }
  void SetColumnNames(std::vector<std::string> value) { column_names_ = std::move(value); }

  bool HasValues() const { return !!values_; }
  const std::vector<std::unique_ptr<base::Value>>* GetValues() const { DCHECK(HasValues()); return &values_.value(); }
  void SetValues(std::vector<std::unique_ptr<base::Value>> value) { values_ = std::move(value); }

  bool HasSqlError() const { return !!sql_error_; }
  const ::headless::database::Error* GetSqlError() const { DCHECK(HasSqlError()); return sql_error_.value().get(); }
  void SetSqlError(std::unique_ptr<::headless::database::Error> value) { sql_error_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExecuteSQLResult> Clone() const;

  template<int STATE>
  class ExecuteSQLResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    ExecuteSQLResultBuilder<STATE>& SetColumnNames(std::vector<std::string> value) {
      result_->SetColumnNames(std::move(value));
      return *this;
    }

    ExecuteSQLResultBuilder<STATE>& SetValues(std::vector<std::unique_ptr<base::Value>> value) {
      result_->SetValues(std::move(value));
      return *this;
    }

    ExecuteSQLResultBuilder<STATE>& SetSqlError(std::unique_ptr<::headless::database::Error> value) {
      result_->SetSqlError(std::move(value));
      return *this;
    }

    std::unique_ptr<ExecuteSQLResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExecuteSQLResult;
    ExecuteSQLResultBuilder() : result_(new ExecuteSQLResult()) { }

    template<int STEP> ExecuteSQLResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExecuteSQLResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExecuteSQLResult> result_;
  };

  static ExecuteSQLResultBuilder<0> Builder() {
    return ExecuteSQLResultBuilder<0>();
  }

 private:
  ExecuteSQLResult() { }

  base::Optional<std::vector<std::string>> column_names_;
  base::Optional<std::vector<std::unique_ptr<base::Value>>> values_;
  base::Optional<std::unique_ptr<::headless::database::Error>> sql_error_;

  DISALLOW_COPY_AND_ASSIGN(ExecuteSQLResult);
};


// Parameters for the GetDatabaseTableNames command.
class HEADLESS_EXPORT GetDatabaseTableNamesParams {
 public:
  static std::unique_ptr<GetDatabaseTableNamesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetDatabaseTableNamesParams() { }

  std::string GetDatabaseId() const { return database_id_; }
  void SetDatabaseId(const std::string& value) { database_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetDatabaseTableNamesParams> Clone() const;

  template<int STATE>
  class GetDatabaseTableNamesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDatabaseIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kDatabaseIdSet | 0)
    };

    GetDatabaseTableNamesParamsBuilder<STATE | kDatabaseIdSet>& SetDatabaseId(const std::string& value) {
      static_assert(!(STATE & kDatabaseIdSet), "property databaseId should not have already been set");
      result_->SetDatabaseId(value);
      return CastState<kDatabaseIdSet>();
    }

    std::unique_ptr<GetDatabaseTableNamesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetDatabaseTableNamesParams;
    GetDatabaseTableNamesParamsBuilder() : result_(new GetDatabaseTableNamesParams()) { }

    template<int STEP> GetDatabaseTableNamesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetDatabaseTableNamesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetDatabaseTableNamesParams> result_;
  };

  static GetDatabaseTableNamesParamsBuilder<0> Builder() {
    return GetDatabaseTableNamesParamsBuilder<0>();
  }

 private:
  GetDatabaseTableNamesParams() { }

  std::string database_id_;

  DISALLOW_COPY_AND_ASSIGN(GetDatabaseTableNamesParams);
};


// Result for the GetDatabaseTableNames command.
class HEADLESS_EXPORT GetDatabaseTableNamesResult {
 public:
  static std::unique_ptr<GetDatabaseTableNamesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetDatabaseTableNamesResult() { }

  const std::vector<std::string>* GetTableNames() const { return &table_names_; }
  void SetTableNames(std::vector<std::string> value) { table_names_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetDatabaseTableNamesResult> Clone() const;

  template<int STATE>
  class GetDatabaseTableNamesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTableNamesSet = 1 << 1,
      kAllRequiredFieldsSet = (kTableNamesSet | 0)
    };

    GetDatabaseTableNamesResultBuilder<STATE | kTableNamesSet>& SetTableNames(std::vector<std::string> value) {
      static_assert(!(STATE & kTableNamesSet), "property tableNames should not have already been set");
      result_->SetTableNames(std::move(value));
      return CastState<kTableNamesSet>();
    }

    std::unique_ptr<GetDatabaseTableNamesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetDatabaseTableNamesResult;
    GetDatabaseTableNamesResultBuilder() : result_(new GetDatabaseTableNamesResult()) { }

    template<int STEP> GetDatabaseTableNamesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetDatabaseTableNamesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetDatabaseTableNamesResult> result_;
  };

  static GetDatabaseTableNamesResultBuilder<0> Builder() {
    return GetDatabaseTableNamesResultBuilder<0>();
  }

 private:
  GetDatabaseTableNamesResult() { }

  std::vector<std::string> table_names_;

  DISALLOW_COPY_AND_ASSIGN(GetDatabaseTableNamesResult);
};


// Parameters for the AddDatabase event.
class HEADLESS_EXPORT AddDatabaseParams {
 public:
  static std::unique_ptr<AddDatabaseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddDatabaseParams() { }

  const ::headless::database::Database* GetDatabase() const { return database_.get(); }
  void SetDatabase(std::unique_ptr<::headless::database::Database> value) { database_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddDatabaseParams> Clone() const;

  template<int STATE>
  class AddDatabaseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDatabaseSet = 1 << 1,
      kAllRequiredFieldsSet = (kDatabaseSet | 0)
    };

    AddDatabaseParamsBuilder<STATE | kDatabaseSet>& SetDatabase(std::unique_ptr<::headless::database::Database> value) {
      static_assert(!(STATE & kDatabaseSet), "property database should not have already been set");
      result_->SetDatabase(std::move(value));
      return CastState<kDatabaseSet>();
    }

    std::unique_ptr<AddDatabaseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddDatabaseParams;
    AddDatabaseParamsBuilder() : result_(new AddDatabaseParams()) { }

    template<int STEP> AddDatabaseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddDatabaseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddDatabaseParams> result_;
  };

  static AddDatabaseParamsBuilder<0> Builder() {
    return AddDatabaseParamsBuilder<0>();
  }

 private:
  AddDatabaseParams() { }

  std::unique_ptr<::headless::database::Database> database_;

  DISALLOW_COPY_AND_ASSIGN(AddDatabaseParams);
};


}  // namespace database

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_DATABASE_H_
