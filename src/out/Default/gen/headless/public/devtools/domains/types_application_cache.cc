// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_application_cache.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_application_cache.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace application_cache {

std::unique_ptr<ApplicationCacheResource> ApplicationCacheResource::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ApplicationCacheResource");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ApplicationCacheResource> result(new ApplicationCacheResource());
  errors->Push();
  errors->SetName("ApplicationCacheResource");
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* size_value = value.FindKey("size");
  if (size_value) {
    errors->SetName("size");
    result->size_ = internal::FromValue<int>::Parse(*size_value, errors);
  } else {
    errors->AddError("required property missing: size");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<std::string>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ApplicationCacheResource::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("url", internal::ToValue(url_));
  result->Set("size", internal::ToValue(size_));
  result->Set("type", internal::ToValue(type_));
  return std::move(result);
}

std::unique_ptr<ApplicationCacheResource> ApplicationCacheResource::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ApplicationCacheResource> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ApplicationCache> ApplicationCache::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ApplicationCache");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ApplicationCache> result(new ApplicationCache());
  errors->Push();
  errors->SetName("ApplicationCache");
  const base::Value* manifesturl_value = value.FindKey("manifestURL");
  if (manifesturl_value) {
    errors->SetName("manifestURL");
    result->manifesturl_ = internal::FromValue<std::string>::Parse(*manifesturl_value, errors);
  } else {
    errors->AddError("required property missing: manifestURL");
  }
  const base::Value* size_value = value.FindKey("size");
  if (size_value) {
    errors->SetName("size");
    result->size_ = internal::FromValue<double>::Parse(*size_value, errors);
  } else {
    errors->AddError("required property missing: size");
  }
  const base::Value* creation_time_value = value.FindKey("creationTime");
  if (creation_time_value) {
    errors->SetName("creationTime");
    result->creation_time_ = internal::FromValue<double>::Parse(*creation_time_value, errors);
  } else {
    errors->AddError("required property missing: creationTime");
  }
  const base::Value* update_time_value = value.FindKey("updateTime");
  if (update_time_value) {
    errors->SetName("updateTime");
    result->update_time_ = internal::FromValue<double>::Parse(*update_time_value, errors);
  } else {
    errors->AddError("required property missing: updateTime");
  }
  const base::Value* resources_value = value.FindKey("resources");
  if (resources_value) {
    errors->SetName("resources");
    result->resources_ = internal::FromValue<std::vector<std::unique_ptr<::headless::application_cache::ApplicationCacheResource>>>::Parse(*resources_value, errors);
  } else {
    errors->AddError("required property missing: resources");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ApplicationCache::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("manifestURL", internal::ToValue(manifesturl_));
  result->Set("size", internal::ToValue(size_));
  result->Set("creationTime", internal::ToValue(creation_time_));
  result->Set("updateTime", internal::ToValue(update_time_));
  result->Set("resources", internal::ToValue(resources_));
  return std::move(result);
}

std::unique_ptr<ApplicationCache> ApplicationCache::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ApplicationCache> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FrameWithManifest> FrameWithManifest::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FrameWithManifest");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FrameWithManifest> result(new FrameWithManifest());
  errors->Push();
  errors->SetName("FrameWithManifest");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* manifesturl_value = value.FindKey("manifestURL");
  if (manifesturl_value) {
    errors->SetName("manifestURL");
    result->manifesturl_ = internal::FromValue<std::string>::Parse(*manifesturl_value, errors);
  } else {
    errors->AddError("required property missing: manifestURL");
  }
  const base::Value* status_value = value.FindKey("status");
  if (status_value) {
    errors->SetName("status");
    result->status_ = internal::FromValue<int>::Parse(*status_value, errors);
  } else {
    errors->AddError("required property missing: status");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FrameWithManifest::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("manifestURL", internal::ToValue(manifesturl_));
  result->Set("status", internal::ToValue(status_));
  return std::move(result);
}

std::unique_ptr<FrameWithManifest> FrameWithManifest::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FrameWithManifest> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<GetApplicationCacheForFrameParams> GetApplicationCacheForFrameParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetApplicationCacheForFrameParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetApplicationCacheForFrameParams> result(new GetApplicationCacheForFrameParams());
  errors->Push();
  errors->SetName("GetApplicationCacheForFrameParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetApplicationCacheForFrameParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<GetApplicationCacheForFrameParams> GetApplicationCacheForFrameParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetApplicationCacheForFrameParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetApplicationCacheForFrameResult> GetApplicationCacheForFrameResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetApplicationCacheForFrameResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetApplicationCacheForFrameResult> result(new GetApplicationCacheForFrameResult());
  errors->Push();
  errors->SetName("GetApplicationCacheForFrameResult");
  const base::Value* application_cache_value = value.FindKey("applicationCache");
  if (application_cache_value) {
    errors->SetName("applicationCache");
    result->application_cache_ = internal::FromValue<::headless::application_cache::ApplicationCache>::Parse(*application_cache_value, errors);
  } else {
    errors->AddError("required property missing: applicationCache");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetApplicationCacheForFrameResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("applicationCache", internal::ToValue(*application_cache_));
  return std::move(result);
}

std::unique_ptr<GetApplicationCacheForFrameResult> GetApplicationCacheForFrameResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetApplicationCacheForFrameResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFramesWithManifestsParams> GetFramesWithManifestsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFramesWithManifestsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFramesWithManifestsParams> result(new GetFramesWithManifestsParams());
  errors->Push();
  errors->SetName("GetFramesWithManifestsParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFramesWithManifestsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetFramesWithManifestsParams> GetFramesWithManifestsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFramesWithManifestsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetFramesWithManifestsResult> GetFramesWithManifestsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetFramesWithManifestsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetFramesWithManifestsResult> result(new GetFramesWithManifestsResult());
  errors->Push();
  errors->SetName("GetFramesWithManifestsResult");
  const base::Value* frame_ids_value = value.FindKey("frameIds");
  if (frame_ids_value) {
    errors->SetName("frameIds");
    result->frame_ids_ = internal::FromValue<std::vector<std::unique_ptr<::headless::application_cache::FrameWithManifest>>>::Parse(*frame_ids_value, errors);
  } else {
    errors->AddError("required property missing: frameIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetFramesWithManifestsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameIds", internal::ToValue(frame_ids_));
  return std::move(result);
}

std::unique_ptr<GetFramesWithManifestsResult> GetFramesWithManifestsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetFramesWithManifestsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetManifestForFrameParams> GetManifestForFrameParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetManifestForFrameParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetManifestForFrameParams> result(new GetManifestForFrameParams());
  errors->Push();
  errors->SetName("GetManifestForFrameParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetManifestForFrameParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<GetManifestForFrameParams> GetManifestForFrameParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetManifestForFrameParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetManifestForFrameResult> GetManifestForFrameResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetManifestForFrameResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetManifestForFrameResult> result(new GetManifestForFrameResult());
  errors->Push();
  errors->SetName("GetManifestForFrameResult");
  const base::Value* manifesturl_value = value.FindKey("manifestURL");
  if (manifesturl_value) {
    errors->SetName("manifestURL");
    result->manifesturl_ = internal::FromValue<std::string>::Parse(*manifesturl_value, errors);
  } else {
    errors->AddError("required property missing: manifestURL");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetManifestForFrameResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("manifestURL", internal::ToValue(manifesturl_));
  return std::move(result);
}

std::unique_ptr<GetManifestForFrameResult> GetManifestForFrameResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetManifestForFrameResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ApplicationCacheStatusUpdatedParams> ApplicationCacheStatusUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ApplicationCacheStatusUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ApplicationCacheStatusUpdatedParams> result(new ApplicationCacheStatusUpdatedParams());
  errors->Push();
  errors->SetName("ApplicationCacheStatusUpdatedParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* manifesturl_value = value.FindKey("manifestURL");
  if (manifesturl_value) {
    errors->SetName("manifestURL");
    result->manifesturl_ = internal::FromValue<std::string>::Parse(*manifesturl_value, errors);
  } else {
    errors->AddError("required property missing: manifestURL");
  }
  const base::Value* status_value = value.FindKey("status");
  if (status_value) {
    errors->SetName("status");
    result->status_ = internal::FromValue<int>::Parse(*status_value, errors);
  } else {
    errors->AddError("required property missing: status");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ApplicationCacheStatusUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("manifestURL", internal::ToValue(manifesturl_));
  result->Set("status", internal::ToValue(status_));
  return std::move(result);
}

std::unique_ptr<ApplicationCacheStatusUpdatedParams> ApplicationCacheStatusUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ApplicationCacheStatusUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<NetworkStateUpdatedParams> NetworkStateUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("NetworkStateUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<NetworkStateUpdatedParams> result(new NetworkStateUpdatedParams());
  errors->Push();
  errors->SetName("NetworkStateUpdatedParams");
  const base::Value* is_now_online_value = value.FindKey("isNowOnline");
  if (is_now_online_value) {
    errors->SetName("isNowOnline");
    result->is_now_online_ = internal::FromValue<bool>::Parse(*is_now_online_value, errors);
  } else {
    errors->AddError("required property missing: isNowOnline");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> NetworkStateUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("isNowOnline", internal::ToValue(is_now_online_));
  return std::move(result);
}

std::unique_ptr<NetworkStateUpdatedParams> NetworkStateUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<NetworkStateUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace application_cache
}  // namespace headless
