// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"
#include "headless/public/devtools/domains/types_storage.h"
#include "headless/public/devtools/domains/types_target.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_browser.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"
#include "headless/public/devtools/internal/type_conversions_storage.h"
#include "headless/public/devtools/internal/type_conversions_target.h"

namespace headless {

namespace storage {

std::unique_ptr<UsageForType> UsageForType::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UsageForType");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UsageForType> result(new UsageForType());
  errors->Push();
  errors->SetName("UsageForType");
  const base::Value* storage_type_value = value.FindKey("storageType");
  if (storage_type_value) {
    errors->SetName("storageType");
    result->storage_type_ = internal::FromValue<::headless::storage::StorageType>::Parse(*storage_type_value, errors);
  } else {
    errors->AddError("required property missing: storageType");
  }
  const base::Value* usage_value = value.FindKey("usage");
  if (usage_value) {
    errors->SetName("usage");
    result->usage_ = internal::FromValue<double>::Parse(*usage_value, errors);
  } else {
    errors->AddError("required property missing: usage");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UsageForType::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageType", internal::ToValue(storage_type_));
  result->Set("usage", internal::ToValue(usage_));
  return std::move(result);
}

std::unique_ptr<UsageForType> UsageForType::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UsageForType> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearDataForOriginParams> ClearDataForOriginParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDataForOriginParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDataForOriginParams> result(new ClearDataForOriginParams());
  errors->Push();
  errors->SetName("ClearDataForOriginParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* storage_types_value = value.FindKey("storageTypes");
  if (storage_types_value) {
    errors->SetName("storageTypes");
    result->storage_types_ = internal::FromValue<std::string>::Parse(*storage_types_value, errors);
  } else {
    errors->AddError("required property missing: storageTypes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDataForOriginParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  result->Set("storageTypes", internal::ToValue(storage_types_));
  return std::move(result);
}

std::unique_ptr<ClearDataForOriginParams> ClearDataForOriginParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDataForOriginParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearDataForOriginResult> ClearDataForOriginResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearDataForOriginResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearDataForOriginResult> result(new ClearDataForOriginResult());
  errors->Push();
  errors->SetName("ClearDataForOriginResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearDataForOriginResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearDataForOriginResult> ClearDataForOriginResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearDataForOriginResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCookiesParams> GetCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCookiesParams> result(new GetCookiesParams());
  errors->Push();
  errors->SetName("GetCookiesParams");
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetCookiesParams> GetCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetCookiesResult> GetCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetCookiesResult> result(new GetCookiesResult());
  errors->Push();
  errors->SetName("GetCookiesResult");
  const base::Value* cookies_value = value.FindKey("cookies");
  if (cookies_value) {
    errors->SetName("cookies");
    result->cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::Cookie>>>::Parse(*cookies_value, errors);
  } else {
    errors->AddError("required property missing: cookies");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookies", internal::ToValue(cookies_));
  return std::move(result);
}

std::unique_ptr<GetCookiesResult> GetCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCookiesParams> SetCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCookiesParams> result(new SetCookiesParams());
  errors->Push();
  errors->SetName("SetCookiesParams");
  const base::Value* cookies_value = value.FindKey("cookies");
  if (cookies_value) {
    errors->SetName("cookies");
    result->cookies_ = internal::FromValue<std::vector<std::unique_ptr<::headless::network::CookieParam>>>::Parse(*cookies_value, errors);
  } else {
    errors->AddError("required property missing: cookies");
  }
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cookies", internal::ToValue(cookies_));
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<SetCookiesParams> SetCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCookiesResult> SetCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCookiesResult> result(new SetCookiesResult());
  errors->Push();
  errors->SetName("SetCookiesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetCookiesResult> SetCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearCookiesParams> ClearCookiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearCookiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearCookiesParams> result(new ClearCookiesParams());
  errors->Push();
  errors->SetName("ClearCookiesParams");
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearCookiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<ClearCookiesParams> ClearCookiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearCookiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearCookiesResult> ClearCookiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearCookiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearCookiesResult> result(new ClearCookiesResult());
  errors->Push();
  errors->SetName("ClearCookiesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearCookiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearCookiesResult> ClearCookiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearCookiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetUsageAndQuotaParams> GetUsageAndQuotaParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetUsageAndQuotaParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetUsageAndQuotaParams> result(new GetUsageAndQuotaParams());
  errors->Push();
  errors->SetName("GetUsageAndQuotaParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetUsageAndQuotaParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<GetUsageAndQuotaParams> GetUsageAndQuotaParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetUsageAndQuotaParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetUsageAndQuotaResult> GetUsageAndQuotaResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetUsageAndQuotaResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetUsageAndQuotaResult> result(new GetUsageAndQuotaResult());
  errors->Push();
  errors->SetName("GetUsageAndQuotaResult");
  const base::Value* usage_value = value.FindKey("usage");
  if (usage_value) {
    errors->SetName("usage");
    result->usage_ = internal::FromValue<double>::Parse(*usage_value, errors);
  } else {
    errors->AddError("required property missing: usage");
  }
  const base::Value* quota_value = value.FindKey("quota");
  if (quota_value) {
    errors->SetName("quota");
    result->quota_ = internal::FromValue<double>::Parse(*quota_value, errors);
  } else {
    errors->AddError("required property missing: quota");
  }
  const base::Value* usage_breakdown_value = value.FindKey("usageBreakdown");
  if (usage_breakdown_value) {
    errors->SetName("usageBreakdown");
    result->usage_breakdown_ = internal::FromValue<std::vector<std::unique_ptr<::headless::storage::UsageForType>>>::Parse(*usage_breakdown_value, errors);
  } else {
    errors->AddError("required property missing: usageBreakdown");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetUsageAndQuotaResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("usage", internal::ToValue(usage_));
  result->Set("quota", internal::ToValue(quota_));
  result->Set("usageBreakdown", internal::ToValue(usage_breakdown_));
  return std::move(result);
}

std::unique_ptr<GetUsageAndQuotaResult> GetUsageAndQuotaResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetUsageAndQuotaResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TrackCacheStorageForOriginParams> TrackCacheStorageForOriginParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TrackCacheStorageForOriginParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TrackCacheStorageForOriginParams> result(new TrackCacheStorageForOriginParams());
  errors->Push();
  errors->SetName("TrackCacheStorageForOriginParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TrackCacheStorageForOriginParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<TrackCacheStorageForOriginParams> TrackCacheStorageForOriginParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TrackCacheStorageForOriginParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TrackCacheStorageForOriginResult> TrackCacheStorageForOriginResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TrackCacheStorageForOriginResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TrackCacheStorageForOriginResult> result(new TrackCacheStorageForOriginResult());
  errors->Push();
  errors->SetName("TrackCacheStorageForOriginResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TrackCacheStorageForOriginResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TrackCacheStorageForOriginResult> TrackCacheStorageForOriginResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TrackCacheStorageForOriginResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TrackIndexedDBForOriginParams> TrackIndexedDBForOriginParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TrackIndexedDBForOriginParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TrackIndexedDBForOriginParams> result(new TrackIndexedDBForOriginParams());
  errors->Push();
  errors->SetName("TrackIndexedDBForOriginParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TrackIndexedDBForOriginParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<TrackIndexedDBForOriginParams> TrackIndexedDBForOriginParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TrackIndexedDBForOriginParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TrackIndexedDBForOriginResult> TrackIndexedDBForOriginResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TrackIndexedDBForOriginResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TrackIndexedDBForOriginResult> result(new TrackIndexedDBForOriginResult());
  errors->Push();
  errors->SetName("TrackIndexedDBForOriginResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TrackIndexedDBForOriginResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TrackIndexedDBForOriginResult> TrackIndexedDBForOriginResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TrackIndexedDBForOriginResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UntrackCacheStorageForOriginParams> UntrackCacheStorageForOriginParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UntrackCacheStorageForOriginParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UntrackCacheStorageForOriginParams> result(new UntrackCacheStorageForOriginParams());
  errors->Push();
  errors->SetName("UntrackCacheStorageForOriginParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UntrackCacheStorageForOriginParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<UntrackCacheStorageForOriginParams> UntrackCacheStorageForOriginParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UntrackCacheStorageForOriginParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UntrackCacheStorageForOriginResult> UntrackCacheStorageForOriginResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UntrackCacheStorageForOriginResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UntrackCacheStorageForOriginResult> result(new UntrackCacheStorageForOriginResult());
  errors->Push();
  errors->SetName("UntrackCacheStorageForOriginResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UntrackCacheStorageForOriginResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<UntrackCacheStorageForOriginResult> UntrackCacheStorageForOriginResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UntrackCacheStorageForOriginResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UntrackIndexedDBForOriginParams> UntrackIndexedDBForOriginParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UntrackIndexedDBForOriginParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UntrackIndexedDBForOriginParams> result(new UntrackIndexedDBForOriginParams());
  errors->Push();
  errors->SetName("UntrackIndexedDBForOriginParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UntrackIndexedDBForOriginParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<UntrackIndexedDBForOriginParams> UntrackIndexedDBForOriginParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UntrackIndexedDBForOriginParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<UntrackIndexedDBForOriginResult> UntrackIndexedDBForOriginResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("UntrackIndexedDBForOriginResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<UntrackIndexedDBForOriginResult> result(new UntrackIndexedDBForOriginResult());
  errors->Push();
  errors->SetName("UntrackIndexedDBForOriginResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> UntrackIndexedDBForOriginResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<UntrackIndexedDBForOriginResult> UntrackIndexedDBForOriginResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<UntrackIndexedDBForOriginResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CacheStorageContentUpdatedParams> CacheStorageContentUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CacheStorageContentUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CacheStorageContentUpdatedParams> result(new CacheStorageContentUpdatedParams());
  errors->Push();
  errors->SetName("CacheStorageContentUpdatedParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* cache_name_value = value.FindKey("cacheName");
  if (cache_name_value) {
    errors->SetName("cacheName");
    result->cache_name_ = internal::FromValue<std::string>::Parse(*cache_name_value, errors);
  } else {
    errors->AddError("required property missing: cacheName");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CacheStorageContentUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  result->Set("cacheName", internal::ToValue(cache_name_));
  return std::move(result);
}

std::unique_ptr<CacheStorageContentUpdatedParams> CacheStorageContentUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CacheStorageContentUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CacheStorageListUpdatedParams> CacheStorageListUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CacheStorageListUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CacheStorageListUpdatedParams> result(new CacheStorageListUpdatedParams());
  errors->Push();
  errors->SetName("CacheStorageListUpdatedParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CacheStorageListUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<CacheStorageListUpdatedParams> CacheStorageListUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CacheStorageListUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<IndexedDBContentUpdatedParams> IndexedDBContentUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("IndexedDBContentUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<IndexedDBContentUpdatedParams> result(new IndexedDBContentUpdatedParams());
  errors->Push();
  errors->SetName("IndexedDBContentUpdatedParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
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

std::unique_ptr<base::Value> IndexedDBContentUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  result->Set("databaseName", internal::ToValue(database_name_));
  result->Set("objectStoreName", internal::ToValue(object_store_name_));
  return std::move(result);
}

std::unique_ptr<IndexedDBContentUpdatedParams> IndexedDBContentUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<IndexedDBContentUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<IndexedDBListUpdatedParams> IndexedDBListUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("IndexedDBListUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<IndexedDBListUpdatedParams> result(new IndexedDBListUpdatedParams());
  errors->Push();
  errors->SetName("IndexedDBListUpdatedParams");
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> IndexedDBListUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("origin", internal::ToValue(origin_));
  return std::move(result);
}

std::unique_ptr<IndexedDBListUpdatedParams> IndexedDBListUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<IndexedDBListUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace storage
}  // namespace headless
