// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INDEXEDDB_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INDEXEDDB_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_indexeddb.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<indexeddb::DatabaseWithObjectStores> {
  static std::unique_ptr<indexeddb::DatabaseWithObjectStores> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DatabaseWithObjectStores::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DatabaseWithObjectStores& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::ObjectStore> {
  static std::unique_ptr<indexeddb::ObjectStore> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::ObjectStore::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::ObjectStore& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::ObjectStoreIndex> {
  static std::unique_ptr<indexeddb::ObjectStoreIndex> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::ObjectStoreIndex::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::ObjectStoreIndex& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::Key> {
  static std::unique_ptr<indexeddb::Key> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::Key::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::Key& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::KeyRange> {
  static std::unique_ptr<indexeddb::KeyRange> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::KeyRange::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::KeyRange& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::DataEntry> {
  static std::unique_ptr<indexeddb::DataEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DataEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DataEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::KeyPath> {
  static std::unique_ptr<indexeddb::KeyPath> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::KeyPath::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::KeyPath& value) {
  return value.Serialize();
}

template <>
struct FromValue<indexeddb::KeyType> {
  static indexeddb::KeyType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return indexeddb::KeyType::NUMBER;
    }
    if (value.GetString() == "number")
      return indexeddb::KeyType::NUMBER;
    if (value.GetString() == "string")
      return indexeddb::KeyType::STRING;
    if (value.GetString() == "date")
      return indexeddb::KeyType::DATE;
    if (value.GetString() == "array")
      return indexeddb::KeyType::ARRAY;
    errors->AddError("invalid enum value");
    return indexeddb::KeyType::NUMBER;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::KeyType& value) {
  switch (value) {
    case indexeddb::KeyType::NUMBER:
      return std::make_unique<base::Value>("number");
    case indexeddb::KeyType::STRING:
      return std::make_unique<base::Value>("string");
    case indexeddb::KeyType::DATE:
      return std::make_unique<base::Value>("date");
    case indexeddb::KeyType::ARRAY:
      return std::make_unique<base::Value>("array");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<indexeddb::KeyPathType> {
  static indexeddb::KeyPathType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return indexeddb::KeyPathType::NONE;
    }
    if (value.GetString() == "null")
      return indexeddb::KeyPathType::NONE;
    if (value.GetString() == "string")
      return indexeddb::KeyPathType::STRING;
    if (value.GetString() == "array")
      return indexeddb::KeyPathType::ARRAY;
    errors->AddError("invalid enum value");
    return indexeddb::KeyPathType::NONE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::KeyPathType& value) {
  switch (value) {
    case indexeddb::KeyPathType::NONE:
      return std::make_unique<base::Value>("null");
    case indexeddb::KeyPathType::STRING:
      return std::make_unique<base::Value>("string");
    case indexeddb::KeyPathType::ARRAY:
      return std::make_unique<base::Value>("array");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<indexeddb::ClearObjectStoreParams> {
  static std::unique_ptr<indexeddb::ClearObjectStoreParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::ClearObjectStoreParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::ClearObjectStoreParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::ClearObjectStoreResult> {
  static std::unique_ptr<indexeddb::ClearObjectStoreResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::ClearObjectStoreResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::ClearObjectStoreResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::DeleteDatabaseParams> {
  static std::unique_ptr<indexeddb::DeleteDatabaseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DeleteDatabaseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DeleteDatabaseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::DeleteDatabaseResult> {
  static std::unique_ptr<indexeddb::DeleteDatabaseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DeleteDatabaseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DeleteDatabaseResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::DeleteObjectStoreEntriesParams> {
  static std::unique_ptr<indexeddb::DeleteObjectStoreEntriesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DeleteObjectStoreEntriesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DeleteObjectStoreEntriesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::DeleteObjectStoreEntriesResult> {
  static std::unique_ptr<indexeddb::DeleteObjectStoreEntriesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DeleteObjectStoreEntriesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DeleteObjectStoreEntriesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::DisableParams> {
  static std::unique_ptr<indexeddb::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::DisableResult> {
  static std::unique_ptr<indexeddb::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::EnableParams> {
  static std::unique_ptr<indexeddb::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::EnableResult> {
  static std::unique_ptr<indexeddb::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::RequestDataParams> {
  static std::unique_ptr<indexeddb::RequestDataParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::RequestDataParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::RequestDataParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::RequestDataResult> {
  static std::unique_ptr<indexeddb::RequestDataResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::RequestDataResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::RequestDataResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::GetMetadataParams> {
  static std::unique_ptr<indexeddb::GetMetadataParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::GetMetadataParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::GetMetadataParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::GetMetadataResult> {
  static std::unique_ptr<indexeddb::GetMetadataResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::GetMetadataResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::GetMetadataResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::RequestDatabaseParams> {
  static std::unique_ptr<indexeddb::RequestDatabaseParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::RequestDatabaseParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::RequestDatabaseParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::RequestDatabaseResult> {
  static std::unique_ptr<indexeddb::RequestDatabaseResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::RequestDatabaseResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::RequestDatabaseResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::RequestDatabaseNamesParams> {
  static std::unique_ptr<indexeddb::RequestDatabaseNamesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::RequestDatabaseNamesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::RequestDatabaseNamesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<indexeddb::RequestDatabaseNamesResult> {
  static std::unique_ptr<indexeddb::RequestDatabaseNamesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return indexeddb::RequestDatabaseNamesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const indexeddb::RequestDatabaseNamesResult& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_INDEXEDDB_H_
