// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_browser.h"
#include "headless/public/devtools/domains/types_target.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_browser.h"
#include "headless/public/devtools/internal/type_conversions_target.h"

namespace headless {

namespace browser {

std::unique_ptr<Bounds> Bounds::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Bounds");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Bounds> result(new Bounds());
  errors->Push();
  errors->SetName("Bounds");
  const base::Value* left_value = value.FindKey("left");
  if (left_value) {
    errors->SetName("left");
    result->left_ = internal::FromValue<int>::Parse(*left_value, errors);
  }
  const base::Value* top_value = value.FindKey("top");
  if (top_value) {
    errors->SetName("top");
    result->top_ = internal::FromValue<int>::Parse(*top_value, errors);
  }
  const base::Value* width_value = value.FindKey("width");
  if (width_value) {
    errors->SetName("width");
    result->width_ = internal::FromValue<int>::Parse(*width_value, errors);
  }
  const base::Value* height_value = value.FindKey("height");
  if (height_value) {
    errors->SetName("height");
    result->height_ = internal::FromValue<int>::Parse(*height_value, errors);
  }
  const base::Value* window_state_value = value.FindKey("windowState");
  if (window_state_value) {
    errors->SetName("windowState");
    result->window_state_ = internal::FromValue<::headless::browser::WindowState>::Parse(*window_state_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Bounds::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (left_)
    result->Set("left", internal::ToValue(left_.value()));
  if (top_)
    result->Set("top", internal::ToValue(top_.value()));
  if (width_)
    result->Set("width", internal::ToValue(width_.value()));
  if (height_)
    result->Set("height", internal::ToValue(height_.value()));
  if (window_state_)
    result->Set("windowState", internal::ToValue(window_state_.value()));
  return std::move(result);
}

std::unique_ptr<Bounds> Bounds::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Bounds> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PermissionDescriptor> PermissionDescriptor::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PermissionDescriptor");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PermissionDescriptor> result(new PermissionDescriptor());
  errors->Push();
  errors->SetName("PermissionDescriptor");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* sysex_value = value.FindKey("sysex");
  if (sysex_value) {
    errors->SetName("sysex");
    result->sysex_ = internal::FromValue<bool>::Parse(*sysex_value, errors);
  }
  const base::Value* user_visible_only_value = value.FindKey("userVisibleOnly");
  if (user_visible_only_value) {
    errors->SetName("userVisibleOnly");
    result->user_visible_only_ = internal::FromValue<bool>::Parse(*user_visible_only_value, errors);
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<std::string>::Parse(*type_value, errors);
  }
  const base::Value* allow_without_sanitization_value = value.FindKey("allowWithoutSanitization");
  if (allow_without_sanitization_value) {
    errors->SetName("allowWithoutSanitization");
    result->allow_without_sanitization_ = internal::FromValue<bool>::Parse(*allow_without_sanitization_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PermissionDescriptor::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  if (sysex_)
    result->Set("sysex", internal::ToValue(sysex_.value()));
  if (user_visible_only_)
    result->Set("userVisibleOnly", internal::ToValue(user_visible_only_.value()));
  if (type_)
    result->Set("type", internal::ToValue(type_.value()));
  if (allow_without_sanitization_)
    result->Set("allowWithoutSanitization", internal::ToValue(allow_without_sanitization_.value()));
  return std::move(result);
}

std::unique_ptr<PermissionDescriptor> PermissionDescriptor::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PermissionDescriptor> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Bucket> Bucket::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Bucket");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Bucket> result(new Bucket());
  errors->Push();
  errors->SetName("Bucket");
  const base::Value* low_value = value.FindKey("low");
  if (low_value) {
    errors->SetName("low");
    result->low_ = internal::FromValue<int>::Parse(*low_value, errors);
  } else {
    errors->AddError("required property missing: low");
  }
  const base::Value* high_value = value.FindKey("high");
  if (high_value) {
    errors->SetName("high");
    result->high_ = internal::FromValue<int>::Parse(*high_value, errors);
  } else {
    errors->AddError("required property missing: high");
  }
  const base::Value* count_value = value.FindKey("count");
  if (count_value) {
    errors->SetName("count");
    result->count_ = internal::FromValue<int>::Parse(*count_value, errors);
  } else {
    errors->AddError("required property missing: count");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Bucket::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("low", internal::ToValue(low_));
  result->Set("high", internal::ToValue(high_));
  result->Set("count", internal::ToValue(count_));
  return std::move(result);
}

std::unique_ptr<Bucket> Bucket::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Bucket> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Histogram> Histogram::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Histogram");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Histogram> result(new Histogram());
  errors->Push();
  errors->SetName("Histogram");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* sum_value = value.FindKey("sum");
  if (sum_value) {
    errors->SetName("sum");
    result->sum_ = internal::FromValue<int>::Parse(*sum_value, errors);
  } else {
    errors->AddError("required property missing: sum");
  }
  const base::Value* count_value = value.FindKey("count");
  if (count_value) {
    errors->SetName("count");
    result->count_ = internal::FromValue<int>::Parse(*count_value, errors);
  } else {
    errors->AddError("required property missing: count");
  }
  const base::Value* buckets_value = value.FindKey("buckets");
  if (buckets_value) {
    errors->SetName("buckets");
    result->buckets_ = internal::FromValue<std::vector<std::unique_ptr<::headless::browser::Bucket>>>::Parse(*buckets_value, errors);
  } else {
    errors->AddError("required property missing: buckets");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Histogram::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("sum", internal::ToValue(sum_));
  result->Set("count", internal::ToValue(count_));
  result->Set("buckets", internal::ToValue(buckets_));
  return std::move(result);
}

std::unique_ptr<Histogram> Histogram::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Histogram> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPermissionParams> SetPermissionParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPermissionParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPermissionParams> result(new SetPermissionParams());
  errors->Push();
  errors->SetName("SetPermissionParams");
  const base::Value* permission_value = value.FindKey("permission");
  if (permission_value) {
    errors->SetName("permission");
    result->permission_ = internal::FromValue<::headless::browser::PermissionDescriptor>::Parse(*permission_value, errors);
  } else {
    errors->AddError("required property missing: permission");
  }
  const base::Value* setting_value = value.FindKey("setting");
  if (setting_value) {
    errors->SetName("setting");
    result->setting_ = internal::FromValue<::headless::browser::PermissionSetting>::Parse(*setting_value, errors);
  } else {
    errors->AddError("required property missing: setting");
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
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

std::unique_ptr<base::Value> SetPermissionParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("permission", internal::ToValue(*permission_));
  result->Set("setting", internal::ToValue(setting_));
  if (origin_)
    result->Set("origin", internal::ToValue(origin_.value()));
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<SetPermissionParams> SetPermissionParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPermissionParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetPermissionResult> SetPermissionResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetPermissionResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetPermissionResult> result(new SetPermissionResult());
  errors->Push();
  errors->SetName("SetPermissionResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetPermissionResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetPermissionResult> SetPermissionResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetPermissionResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GrantPermissionsParams> GrantPermissionsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GrantPermissionsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GrantPermissionsParams> result(new GrantPermissionsParams());
  errors->Push();
  errors->SetName("GrantPermissionsParams");
  const base::Value* permissions_value = value.FindKey("permissions");
  if (permissions_value) {
    errors->SetName("permissions");
    result->permissions_ = internal::FromValue<std::vector<::headless::browser::PermissionType>>::Parse(*permissions_value, errors);
  } else {
    errors->AddError("required property missing: permissions");
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
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

std::unique_ptr<base::Value> GrantPermissionsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("permissions", internal::ToValue(permissions_));
  if (origin_)
    result->Set("origin", internal::ToValue(origin_.value()));
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<GrantPermissionsParams> GrantPermissionsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GrantPermissionsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GrantPermissionsResult> GrantPermissionsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GrantPermissionsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GrantPermissionsResult> result(new GrantPermissionsResult());
  errors->Push();
  errors->SetName("GrantPermissionsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GrantPermissionsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GrantPermissionsResult> GrantPermissionsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GrantPermissionsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResetPermissionsParams> ResetPermissionsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResetPermissionsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResetPermissionsParams> result(new ResetPermissionsParams());
  errors->Push();
  errors->SetName("ResetPermissionsParams");
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

std::unique_ptr<base::Value> ResetPermissionsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<ResetPermissionsParams> ResetPermissionsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResetPermissionsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ResetPermissionsResult> ResetPermissionsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ResetPermissionsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ResetPermissionsResult> result(new ResetPermissionsResult());
  errors->Push();
  errors->SetName("ResetPermissionsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ResetPermissionsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ResetPermissionsResult> ResetPermissionsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ResetPermissionsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDownloadBehaviorParams> SetDownloadBehaviorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDownloadBehaviorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDownloadBehaviorParams> result(new SetDownloadBehaviorParams());
  errors->Push();
  errors->SetName("SetDownloadBehaviorParams");
  const base::Value* behavior_value = value.FindKey("behavior");
  if (behavior_value) {
    errors->SetName("behavior");
    result->behavior_ = internal::FromValue<::headless::browser::SetDownloadBehaviorBehavior>::Parse(*behavior_value, errors);
  } else {
    errors->AddError("required property missing: behavior");
  }
  const base::Value* browser_context_id_value = value.FindKey("browserContextId");
  if (browser_context_id_value) {
    errors->SetName("browserContextId");
    result->browser_context_id_ = internal::FromValue<std::string>::Parse(*browser_context_id_value, errors);
  }
  const base::Value* download_path_value = value.FindKey("downloadPath");
  if (download_path_value) {
    errors->SetName("downloadPath");
    result->download_path_ = internal::FromValue<std::string>::Parse(*download_path_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDownloadBehaviorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("behavior", internal::ToValue(behavior_));
  if (browser_context_id_)
    result->Set("browserContextId", internal::ToValue(browser_context_id_.value()));
  if (download_path_)
    result->Set("downloadPath", internal::ToValue(download_path_.value()));
  return std::move(result);
}

std::unique_ptr<SetDownloadBehaviorParams> SetDownloadBehaviorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDownloadBehaviorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDownloadBehaviorResult> SetDownloadBehaviorResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDownloadBehaviorResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDownloadBehaviorResult> result(new SetDownloadBehaviorResult());
  errors->Push();
  errors->SetName("SetDownloadBehaviorResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDownloadBehaviorResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDownloadBehaviorResult> SetDownloadBehaviorResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDownloadBehaviorResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CloseParams> CloseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CloseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CloseParams> result(new CloseParams());
  errors->Push();
  errors->SetName("CloseParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CloseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CloseParams> CloseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CloseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CloseResult> CloseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CloseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CloseResult> result(new CloseResult());
  errors->Push();
  errors->SetName("CloseResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CloseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CloseResult> CloseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CloseResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CrashParams> CrashParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CrashParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CrashParams> result(new CrashParams());
  errors->Push();
  errors->SetName("CrashParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CrashParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CrashParams> CrashParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CrashParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CrashResult> CrashResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CrashResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CrashResult> result(new CrashResult());
  errors->Push();
  errors->SetName("CrashResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CrashResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CrashResult> CrashResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CrashResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CrashGpuProcessParams> CrashGpuProcessParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CrashGpuProcessParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CrashGpuProcessParams> result(new CrashGpuProcessParams());
  errors->Push();
  errors->SetName("CrashGpuProcessParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CrashGpuProcessParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CrashGpuProcessParams> CrashGpuProcessParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CrashGpuProcessParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CrashGpuProcessResult> CrashGpuProcessResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CrashGpuProcessResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CrashGpuProcessResult> result(new CrashGpuProcessResult());
  errors->Push();
  errors->SetName("CrashGpuProcessResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CrashGpuProcessResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<CrashGpuProcessResult> CrashGpuProcessResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CrashGpuProcessResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetVersionParams> GetVersionParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetVersionParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetVersionParams> result(new GetVersionParams());
  errors->Push();
  errors->SetName("GetVersionParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetVersionParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetVersionParams> GetVersionParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetVersionParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetVersionResult> GetVersionResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetVersionResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetVersionResult> result(new GetVersionResult());
  errors->Push();
  errors->SetName("GetVersionResult");
  const base::Value* protocol_version_value = value.FindKey("protocolVersion");
  if (protocol_version_value) {
    errors->SetName("protocolVersion");
    result->protocol_version_ = internal::FromValue<std::string>::Parse(*protocol_version_value, errors);
  } else {
    errors->AddError("required property missing: protocolVersion");
  }
  const base::Value* product_value = value.FindKey("product");
  if (product_value) {
    errors->SetName("product");
    result->product_ = internal::FromValue<std::string>::Parse(*product_value, errors);
  } else {
    errors->AddError("required property missing: product");
  }
  const base::Value* revision_value = value.FindKey("revision");
  if (revision_value) {
    errors->SetName("revision");
    result->revision_ = internal::FromValue<std::string>::Parse(*revision_value, errors);
  } else {
    errors->AddError("required property missing: revision");
  }
  const base::Value* user_agent_value = value.FindKey("userAgent");
  if (user_agent_value) {
    errors->SetName("userAgent");
    result->user_agent_ = internal::FromValue<std::string>::Parse(*user_agent_value, errors);
  } else {
    errors->AddError("required property missing: userAgent");
  }
  const base::Value* js_version_value = value.FindKey("jsVersion");
  if (js_version_value) {
    errors->SetName("jsVersion");
    result->js_version_ = internal::FromValue<std::string>::Parse(*js_version_value, errors);
  } else {
    errors->AddError("required property missing: jsVersion");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetVersionResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("protocolVersion", internal::ToValue(protocol_version_));
  result->Set("product", internal::ToValue(product_));
  result->Set("revision", internal::ToValue(revision_));
  result->Set("userAgent", internal::ToValue(user_agent_));
  result->Set("jsVersion", internal::ToValue(js_version_));
  return std::move(result);
}

std::unique_ptr<GetVersionResult> GetVersionResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetVersionResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBrowserCommandLineParams> GetBrowserCommandLineParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBrowserCommandLineParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBrowserCommandLineParams> result(new GetBrowserCommandLineParams());
  errors->Push();
  errors->SetName("GetBrowserCommandLineParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBrowserCommandLineParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetBrowserCommandLineParams> GetBrowserCommandLineParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBrowserCommandLineParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBrowserCommandLineResult> GetBrowserCommandLineResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBrowserCommandLineResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBrowserCommandLineResult> result(new GetBrowserCommandLineResult());
  errors->Push();
  errors->SetName("GetBrowserCommandLineResult");
  const base::Value* arguments_value = value.FindKey("arguments");
  if (arguments_value) {
    errors->SetName("arguments");
    result->arguments_ = internal::FromValue<std::vector<std::string>>::Parse(*arguments_value, errors);
  } else {
    errors->AddError("required property missing: arguments");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBrowserCommandLineResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("arguments", internal::ToValue(arguments_));
  return std::move(result);
}

std::unique_ptr<GetBrowserCommandLineResult> GetBrowserCommandLineResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBrowserCommandLineResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetHistogramsParams> GetHistogramsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHistogramsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHistogramsParams> result(new GetHistogramsParams());
  errors->Push();
  errors->SetName("GetHistogramsParams");
  const base::Value* query_value = value.FindKey("query");
  if (query_value) {
    errors->SetName("query");
    result->query_ = internal::FromValue<std::string>::Parse(*query_value, errors);
  }
  const base::Value* delta_value = value.FindKey("delta");
  if (delta_value) {
    errors->SetName("delta");
    result->delta_ = internal::FromValue<bool>::Parse(*delta_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHistogramsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (query_)
    result->Set("query", internal::ToValue(query_.value()));
  if (delta_)
    result->Set("delta", internal::ToValue(delta_.value()));
  return std::move(result);
}

std::unique_ptr<GetHistogramsParams> GetHistogramsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHistogramsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetHistogramsResult> GetHistogramsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHistogramsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHistogramsResult> result(new GetHistogramsResult());
  errors->Push();
  errors->SetName("GetHistogramsResult");
  const base::Value* histograms_value = value.FindKey("histograms");
  if (histograms_value) {
    errors->SetName("histograms");
    result->histograms_ = internal::FromValue<std::vector<std::unique_ptr<::headless::browser::Histogram>>>::Parse(*histograms_value, errors);
  } else {
    errors->AddError("required property missing: histograms");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHistogramsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("histograms", internal::ToValue(histograms_));
  return std::move(result);
}

std::unique_ptr<GetHistogramsResult> GetHistogramsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHistogramsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetHistogramParams> GetHistogramParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHistogramParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHistogramParams> result(new GetHistogramParams());
  errors->Push();
  errors->SetName("GetHistogramParams");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* delta_value = value.FindKey("delta");
  if (delta_value) {
    errors->SetName("delta");
    result->delta_ = internal::FromValue<bool>::Parse(*delta_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHistogramParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  if (delta_)
    result->Set("delta", internal::ToValue(delta_.value()));
  return std::move(result);
}

std::unique_ptr<GetHistogramParams> GetHistogramParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHistogramParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetHistogramResult> GetHistogramResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHistogramResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHistogramResult> result(new GetHistogramResult());
  errors->Push();
  errors->SetName("GetHistogramResult");
  const base::Value* histogram_value = value.FindKey("histogram");
  if (histogram_value) {
    errors->SetName("histogram");
    result->histogram_ = internal::FromValue<::headless::browser::Histogram>::Parse(*histogram_value, errors);
  } else {
    errors->AddError("required property missing: histogram");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHistogramResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("histogram", internal::ToValue(*histogram_));
  return std::move(result);
}

std::unique_ptr<GetHistogramResult> GetHistogramResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHistogramResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetWindowBoundsParams> GetWindowBoundsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetWindowBoundsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetWindowBoundsParams> result(new GetWindowBoundsParams());
  errors->Push();
  errors->SetName("GetWindowBoundsParams");
  const base::Value* window_id_value = value.FindKey("windowId");
  if (window_id_value) {
    errors->SetName("windowId");
    result->window_id_ = internal::FromValue<int>::Parse(*window_id_value, errors);
  } else {
    errors->AddError("required property missing: windowId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetWindowBoundsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("windowId", internal::ToValue(window_id_));
  return std::move(result);
}

std::unique_ptr<GetWindowBoundsParams> GetWindowBoundsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetWindowBoundsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetWindowBoundsResult> GetWindowBoundsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetWindowBoundsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetWindowBoundsResult> result(new GetWindowBoundsResult());
  errors->Push();
  errors->SetName("GetWindowBoundsResult");
  const base::Value* bounds_value = value.FindKey("bounds");
  if (bounds_value) {
    errors->SetName("bounds");
    result->bounds_ = internal::FromValue<::headless::browser::Bounds>::Parse(*bounds_value, errors);
  } else {
    errors->AddError("required property missing: bounds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetWindowBoundsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("bounds", internal::ToValue(*bounds_));
  return std::move(result);
}

std::unique_ptr<GetWindowBoundsResult> GetWindowBoundsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetWindowBoundsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetWindowForTargetParams> GetWindowForTargetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetWindowForTargetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetWindowForTargetParams> result(new GetWindowForTargetParams());
  errors->Push();
  errors->SetName("GetWindowForTargetParams");
  const base::Value* target_id_value = value.FindKey("targetId");
  if (target_id_value) {
    errors->SetName("targetId");
    result->target_id_ = internal::FromValue<std::string>::Parse(*target_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetWindowForTargetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (target_id_)
    result->Set("targetId", internal::ToValue(target_id_.value()));
  return std::move(result);
}

std::unique_ptr<GetWindowForTargetParams> GetWindowForTargetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetWindowForTargetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetWindowForTargetResult> GetWindowForTargetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetWindowForTargetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetWindowForTargetResult> result(new GetWindowForTargetResult());
  errors->Push();
  errors->SetName("GetWindowForTargetResult");
  const base::Value* window_id_value = value.FindKey("windowId");
  if (window_id_value) {
    errors->SetName("windowId");
    result->window_id_ = internal::FromValue<int>::Parse(*window_id_value, errors);
  } else {
    errors->AddError("required property missing: windowId");
  }
  const base::Value* bounds_value = value.FindKey("bounds");
  if (bounds_value) {
    errors->SetName("bounds");
    result->bounds_ = internal::FromValue<::headless::browser::Bounds>::Parse(*bounds_value, errors);
  } else {
    errors->AddError("required property missing: bounds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetWindowForTargetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("windowId", internal::ToValue(window_id_));
  result->Set("bounds", internal::ToValue(*bounds_));
  return std::move(result);
}

std::unique_ptr<GetWindowForTargetResult> GetWindowForTargetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetWindowForTargetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetWindowBoundsParams> SetWindowBoundsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetWindowBoundsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetWindowBoundsParams> result(new SetWindowBoundsParams());
  errors->Push();
  errors->SetName("SetWindowBoundsParams");
  const base::Value* window_id_value = value.FindKey("windowId");
  if (window_id_value) {
    errors->SetName("windowId");
    result->window_id_ = internal::FromValue<int>::Parse(*window_id_value, errors);
  } else {
    errors->AddError("required property missing: windowId");
  }
  const base::Value* bounds_value = value.FindKey("bounds");
  if (bounds_value) {
    errors->SetName("bounds");
    result->bounds_ = internal::FromValue<::headless::browser::Bounds>::Parse(*bounds_value, errors);
  } else {
    errors->AddError("required property missing: bounds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetWindowBoundsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("windowId", internal::ToValue(window_id_));
  result->Set("bounds", internal::ToValue(*bounds_));
  return std::move(result);
}

std::unique_ptr<SetWindowBoundsParams> SetWindowBoundsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetWindowBoundsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetWindowBoundsResult> SetWindowBoundsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetWindowBoundsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetWindowBoundsResult> result(new SetWindowBoundsResult());
  errors->Push();
  errors->SetName("SetWindowBoundsResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetWindowBoundsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetWindowBoundsResult> SetWindowBoundsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetWindowBoundsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDockTileParams> SetDockTileParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDockTileParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDockTileParams> result(new SetDockTileParams());
  errors->Push();
  errors->SetName("SetDockTileParams");
  const base::Value* badge_label_value = value.FindKey("badgeLabel");
  if (badge_label_value) {
    errors->SetName("badgeLabel");
    result->badge_label_ = internal::FromValue<std::string>::Parse(*badge_label_value, errors);
  }
  const base::Value* image_value = value.FindKey("image");
  if (image_value) {
    errors->SetName("image");
    result->image_ = internal::FromValue<protocol::Binary>::Parse(*image_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDockTileParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (badge_label_)
    result->Set("badgeLabel", internal::ToValue(badge_label_.value()));
  if (image_)
    result->Set("image", internal::ToValue(image_.value()));
  return std::move(result);
}

std::unique_ptr<SetDockTileParams> SetDockTileParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDockTileParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDockTileResult> SetDockTileResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDockTileResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDockTileResult> result(new SetDockTileResult());
  errors->Push();
  errors->SetName("SetDockTileResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDockTileResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDockTileResult> SetDockTileResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDockTileResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace browser
}  // namespace headless
