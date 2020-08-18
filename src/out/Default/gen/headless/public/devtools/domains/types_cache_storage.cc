// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_cache_storage.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_cache_storage.h"

namespace headless {

namespace cache_storage {

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
  const base::Value* requesturl_value = value.FindKey("requestURL");
  if (requesturl_value) {
    errors->SetName("requestURL");
    result->requesturl_ = internal::FromValue<std::string>::Parse(*requesturl_value, errors);
  } else {
    errors->AddError("required property missing: requestURL");
  }
  const base::Value* request_method_value = value.FindKey("requestMethod");
  if (request_method_value) {
    errors->SetName("requestMethod");
    result->request_method_ = internal::FromValue<std::string>::Parse(*request_method_value, errors);
  } else {
    errors->AddError("required property missing: requestMethod");
  }
  const base::Value* request_headers_value = value.FindKey("requestHeaders");
  if (request_headers_value) {
    errors->SetName("requestHeaders");
    result->request_headers_ = internal::FromValue<std::vector<std::unique_ptr<::headless::cache_storage::Header>>>::Parse(*request_headers_value, errors);
  } else {
    errors->AddError("required property missing: requestHeaders");
  }
  const base::Value* response_time_value = value.FindKey("responseTime");
  if (response_time_value) {
    errors->SetName("responseTime");
    result->response_time_ = internal::FromValue<double>::Parse(*response_time_value, errors);
  } else {
    errors->AddError("required property missing: responseTime");
  }
  const base::Value* response_status_value = value.FindKey("responseStatus");
  if (response_status_value) {
    errors->SetName("responseStatus");
    result->response_status_ = internal::FromValue<int>::Parse(*response_status_value, errors);
  } else {
    errors->AddError("required property missing: responseStatus");
  }
  const base::Value* response_status_text_value = value.FindKey("responseStatusText");
  if (response_status_text_value) {
    errors->SetName("responseStatusText");
    result->response_status_text_ = internal::FromValue<std::string>::Parse(*response_status_text_value, errors);
  } else {
    errors->AddError("required property missing: responseStatusText");
  }
  const base::Value* response_type_value = value.FindKey("responseType");
  if (response_type_value) {
    errors->SetName("responseType");
    result->response_type_ = internal::FromValue<::headless::cache_storage::CachedResponseType>::Parse(*response_type_value, errors);
  } else {
    errors->AddError("required property missing: responseType");
  }
  const base::Value* response_headers_value = value.FindKey("responseHeaders");
  if (response_headers_value) {
    errors->SetName("responseHeaders");
    result->response_headers_ = internal::FromValue<std::vector<std::unique_ptr<::headless::cache_storage::Header>>>::Parse(*response_headers_value, errors);
  } else {
    errors->AddError("required property missing: responseHeaders");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DataEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("requestURL", internal::ToValue(requesturl_));
  result->Set("requestMethod", internal::ToValue(request_method_));
  result->Set("requestHeaders", internal::ToValue(request_headers_));
  result->Set("responseTime", internal::ToValue(response_time_));
  result->Set("responseStatus", internal::ToValue(response_status_));
  result->Set("responseStatusText", internal::ToValue(response_status_text_));
  result->Set("responseType", internal::ToValue(response_type_));
  result->Set("responseHeaders", internal::ToValue(response_headers_));
  return std::move(result);
}

std::unique_ptr<DataEntry> DataEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DataEntry> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Cache> Cache::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Cache");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Cache> result(new Cache());
  errors->Push();
  errors->SetName("Cache");
  const base::Value* cache_id_value = value.FindKey("cacheId");
  if (cache_id_value) {
    errors->SetName("cacheId");
    result->cache_id_ = internal::FromValue<std::string>::Parse(*cache_id_value, errors);
  } else {
    errors->AddError("required property missing: cacheId");
  }
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
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

std::unique_ptr<base::Value> Cache::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cacheId", internal::ToValue(cache_id_));
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("cacheName", internal::ToValue(cache_name_));
  return std::move(result);
}

std::unique_ptr<Cache> Cache::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Cache> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Header> Header::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Header");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Header> result(new Header());
  errors->Push();
  errors->SetName("Header");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Header::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<Header> Header::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Header> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CachedResponse> CachedResponse::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CachedResponse");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CachedResponse> result(new CachedResponse());
  errors->Push();
  errors->SetName("CachedResponse");
  const base::Value* body_value = value.FindKey("body");
  if (body_value) {
    errors->SetName("body");
    result->body_ = internal::FromValue<protocol::Binary>::Parse(*body_value, errors);
  } else {
    errors->AddError("required property missing: body");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CachedResponse::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("body", internal::ToValue(body_));
  return std::move(result);
}

std::unique_ptr<CachedResponse> CachedResponse::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CachedResponse> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteCacheParams> DeleteCacheParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteCacheParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteCacheParams> result(new DeleteCacheParams());
  errors->Push();
  errors->SetName("DeleteCacheParams");
  const base::Value* cache_id_value = value.FindKey("cacheId");
  if (cache_id_value) {
    errors->SetName("cacheId");
    result->cache_id_ = internal::FromValue<std::string>::Parse(*cache_id_value, errors);
  } else {
    errors->AddError("required property missing: cacheId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteCacheParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cacheId", internal::ToValue(cache_id_));
  return std::move(result);
}

std::unique_ptr<DeleteCacheParams> DeleteCacheParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteCacheParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteCacheResult> DeleteCacheResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteCacheResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteCacheResult> result(new DeleteCacheResult());
  errors->Push();
  errors->SetName("DeleteCacheResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteCacheResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DeleteCacheResult> DeleteCacheResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteCacheResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteEntryParams> DeleteEntryParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteEntryParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteEntryParams> result(new DeleteEntryParams());
  errors->Push();
  errors->SetName("DeleteEntryParams");
  const base::Value* cache_id_value = value.FindKey("cacheId");
  if (cache_id_value) {
    errors->SetName("cacheId");
    result->cache_id_ = internal::FromValue<std::string>::Parse(*cache_id_value, errors);
  } else {
    errors->AddError("required property missing: cacheId");
  }
  const base::Value* request_value = value.FindKey("request");
  if (request_value) {
    errors->SetName("request");
    result->request_ = internal::FromValue<std::string>::Parse(*request_value, errors);
  } else {
    errors->AddError("required property missing: request");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteEntryParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cacheId", internal::ToValue(cache_id_));
  result->Set("request", internal::ToValue(request_));
  return std::move(result);
}

std::unique_ptr<DeleteEntryParams> DeleteEntryParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteEntryParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DeleteEntryResult> DeleteEntryResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DeleteEntryResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DeleteEntryResult> result(new DeleteEntryResult());
  errors->Push();
  errors->SetName("DeleteEntryResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DeleteEntryResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DeleteEntryResult> DeleteEntryResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DeleteEntryResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestCacheNamesParams> RequestCacheNamesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestCacheNamesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestCacheNamesParams> result(new RequestCacheNamesParams());
  errors->Push();
  errors->SetName("RequestCacheNamesParams");
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

std::unique_ptr<base::Value> RequestCacheNamesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  return std::move(result);
}

std::unique_ptr<RequestCacheNamesParams> RequestCacheNamesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestCacheNamesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestCacheNamesResult> RequestCacheNamesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestCacheNamesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestCacheNamesResult> result(new RequestCacheNamesResult());
  errors->Push();
  errors->SetName("RequestCacheNamesResult");
  const base::Value* caches_value = value.FindKey("caches");
  if (caches_value) {
    errors->SetName("caches");
    result->caches_ = internal::FromValue<std::vector<std::unique_ptr<::headless::cache_storage::Cache>>>::Parse(*caches_value, errors);
  } else {
    errors->AddError("required property missing: caches");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestCacheNamesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("caches", internal::ToValue(caches_));
  return std::move(result);
}

std::unique_ptr<RequestCacheNamesResult> RequestCacheNamesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestCacheNamesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestCachedResponseParams> RequestCachedResponseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestCachedResponseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestCachedResponseParams> result(new RequestCachedResponseParams());
  errors->Push();
  errors->SetName("RequestCachedResponseParams");
  const base::Value* cache_id_value = value.FindKey("cacheId");
  if (cache_id_value) {
    errors->SetName("cacheId");
    result->cache_id_ = internal::FromValue<std::string>::Parse(*cache_id_value, errors);
  } else {
    errors->AddError("required property missing: cacheId");
  }
  const base::Value* requesturl_value = value.FindKey("requestURL");
  if (requesturl_value) {
    errors->SetName("requestURL");
    result->requesturl_ = internal::FromValue<std::string>::Parse(*requesturl_value, errors);
  } else {
    errors->AddError("required property missing: requestURL");
  }
  const base::Value* request_headers_value = value.FindKey("requestHeaders");
  if (request_headers_value) {
    errors->SetName("requestHeaders");
    result->request_headers_ = internal::FromValue<std::vector<std::unique_ptr<::headless::cache_storage::Header>>>::Parse(*request_headers_value, errors);
  } else {
    errors->AddError("required property missing: requestHeaders");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestCachedResponseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cacheId", internal::ToValue(cache_id_));
  result->Set("requestURL", internal::ToValue(requesturl_));
  result->Set("requestHeaders", internal::ToValue(request_headers_));
  return std::move(result);
}

std::unique_ptr<RequestCachedResponseParams> RequestCachedResponseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestCachedResponseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestCachedResponseResult> RequestCachedResponseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestCachedResponseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestCachedResponseResult> result(new RequestCachedResponseResult());
  errors->Push();
  errors->SetName("RequestCachedResponseResult");
  const base::Value* response_value = value.FindKey("response");
  if (response_value) {
    errors->SetName("response");
    result->response_ = internal::FromValue<::headless::cache_storage::CachedResponse>::Parse(*response_value, errors);
  } else {
    errors->AddError("required property missing: response");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestCachedResponseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("response", internal::ToValue(*response_));
  return std::move(result);
}

std::unique_ptr<RequestCachedResponseResult> RequestCachedResponseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestCachedResponseResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestEntriesParams> RequestEntriesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestEntriesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestEntriesParams> result(new RequestEntriesParams());
  errors->Push();
  errors->SetName("RequestEntriesParams");
  const base::Value* cache_id_value = value.FindKey("cacheId");
  if (cache_id_value) {
    errors->SetName("cacheId");
    result->cache_id_ = internal::FromValue<std::string>::Parse(*cache_id_value, errors);
  } else {
    errors->AddError("required property missing: cacheId");
  }
  const base::Value* skip_count_value = value.FindKey("skipCount");
  if (skip_count_value) {
    errors->SetName("skipCount");
    result->skip_count_ = internal::FromValue<int>::Parse(*skip_count_value, errors);
  }
  const base::Value* page_size_value = value.FindKey("pageSize");
  if (page_size_value) {
    errors->SetName("pageSize");
    result->page_size_ = internal::FromValue<int>::Parse(*page_size_value, errors);
  }
  const base::Value* path_filter_value = value.FindKey("pathFilter");
  if (path_filter_value) {
    errors->SetName("pathFilter");
    result->path_filter_ = internal::FromValue<std::string>::Parse(*path_filter_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestEntriesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cacheId", internal::ToValue(cache_id_));
  if (skip_count_)
    result->Set("skipCount", internal::ToValue(skip_count_.value()));
  if (page_size_)
    result->Set("pageSize", internal::ToValue(page_size_.value()));
  if (path_filter_)
    result->Set("pathFilter", internal::ToValue(path_filter_.value()));
  return std::move(result);
}

std::unique_ptr<RequestEntriesParams> RequestEntriesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestEntriesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RequestEntriesResult> RequestEntriesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RequestEntriesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RequestEntriesResult> result(new RequestEntriesResult());
  errors->Push();
  errors->SetName("RequestEntriesResult");
  const base::Value* cache_data_entries_value = value.FindKey("cacheDataEntries");
  if (cache_data_entries_value) {
    errors->SetName("cacheDataEntries");
    result->cache_data_entries_ = internal::FromValue<std::vector<std::unique_ptr<::headless::cache_storage::DataEntry>>>::Parse(*cache_data_entries_value, errors);
  } else {
    errors->AddError("required property missing: cacheDataEntries");
  }
  const base::Value* return_count_value = value.FindKey("returnCount");
  if (return_count_value) {
    errors->SetName("returnCount");
    result->return_count_ = internal::FromValue<double>::Parse(*return_count_value, errors);
  } else {
    errors->AddError("required property missing: returnCount");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RequestEntriesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("cacheDataEntries", internal::ToValue(cache_data_entries_));
  result->Set("returnCount", internal::ToValue(return_count_));
  return std::move(result);
}

std::unique_ptr<RequestEntriesResult> RequestEntriesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RequestEntriesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace cache_storage
}  // namespace headless
