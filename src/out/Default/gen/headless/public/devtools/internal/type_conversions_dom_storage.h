// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_STORAGE_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_dom_storage.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<dom_storage::StorageId> {
  static std::unique_ptr<dom_storage::StorageId> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::StorageId::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::StorageId& value) {
  return value.Serialize();
}



template <>
struct FromValue<dom_storage::ClearParams> {
  static std::unique_ptr<dom_storage::ClearParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::ClearParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::ClearParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::ClearResult> {
  static std::unique_ptr<dom_storage::ClearResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::ClearResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::ClearResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::DisableParams> {
  static std::unique_ptr<dom_storage::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::DisableResult> {
  static std::unique_ptr<dom_storage::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::EnableParams> {
  static std::unique_ptr<dom_storage::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::EnableResult> {
  static std::unique_ptr<dom_storage::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::GetDOMStorageItemsParams> {
  static std::unique_ptr<dom_storage::GetDOMStorageItemsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::GetDOMStorageItemsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::GetDOMStorageItemsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::GetDOMStorageItemsResult> {
  static std::unique_ptr<dom_storage::GetDOMStorageItemsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::GetDOMStorageItemsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::GetDOMStorageItemsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::RemoveDOMStorageItemParams> {
  static std::unique_ptr<dom_storage::RemoveDOMStorageItemParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::RemoveDOMStorageItemParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::RemoveDOMStorageItemParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::RemoveDOMStorageItemResult> {
  static std::unique_ptr<dom_storage::RemoveDOMStorageItemResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::RemoveDOMStorageItemResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::RemoveDOMStorageItemResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::SetDOMStorageItemParams> {
  static std::unique_ptr<dom_storage::SetDOMStorageItemParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::SetDOMStorageItemParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::SetDOMStorageItemParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::SetDOMStorageItemResult> {
  static std::unique_ptr<dom_storage::SetDOMStorageItemResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::SetDOMStorageItemResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::SetDOMStorageItemResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::DomStorageItemAddedParams> {
  static std::unique_ptr<dom_storage::DomStorageItemAddedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::DomStorageItemAddedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::DomStorageItemAddedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::DomStorageItemRemovedParams> {
  static std::unique_ptr<dom_storage::DomStorageItemRemovedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::DomStorageItemRemovedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::DomStorageItemRemovedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::DomStorageItemUpdatedParams> {
  static std::unique_ptr<dom_storage::DomStorageItemUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::DomStorageItemUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::DomStorageItemUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom_storage::DomStorageItemsClearedParams> {
  static std::unique_ptr<dom_storage::DomStorageItemsClearedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom_storage::DomStorageItemsClearedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom_storage::DomStorageItemsClearedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_STORAGE_H_
