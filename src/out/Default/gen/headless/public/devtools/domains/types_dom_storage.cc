// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom_storage.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom_storage.h"

namespace headless {

namespace dom_storage {

std::unique_ptr<StorageId> StorageId::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StorageId");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StorageId> result(new StorageId());
  errors->Push();
  errors->SetName("StorageId");
  const base::Value* security_origin_value = value.FindKey("securityOrigin");
  if (security_origin_value) {
    errors->SetName("securityOrigin");
    result->security_origin_ = internal::FromValue<std::string>::Parse(*security_origin_value, errors);
  } else {
    errors->AddError("required property missing: securityOrigin");
  }
  const base::Value* is_local_storage_value = value.FindKey("isLocalStorage");
  if (is_local_storage_value) {
    errors->SetName("isLocalStorage");
    result->is_local_storage_ = internal::FromValue<bool>::Parse(*is_local_storage_value, errors);
  } else {
    errors->AddError("required property missing: isLocalStorage");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StorageId::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("securityOrigin", internal::ToValue(security_origin_));
  result->Set("isLocalStorage", internal::ToValue(is_local_storage_));
  return std::move(result);
}

std::unique_ptr<StorageId> StorageId::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StorageId> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearParams> ClearParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearParams> result(new ClearParams());
  errors->Push();
  errors->SetName("ClearParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  return std::move(result);
}

std::unique_ptr<ClearParams> ClearParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ClearResult> ClearResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ClearResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ClearResult> result(new ClearResult());
  errors->Push();
  errors->SetName("ClearResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ClearResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ClearResult> ClearResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ClearResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<GetDOMStorageItemsParams> GetDOMStorageItemsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDOMStorageItemsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDOMStorageItemsParams> result(new GetDOMStorageItemsParams());
  errors->Push();
  errors->SetName("GetDOMStorageItemsParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDOMStorageItemsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  return std::move(result);
}

std::unique_ptr<GetDOMStorageItemsParams> GetDOMStorageItemsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDOMStorageItemsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetDOMStorageItemsResult> GetDOMStorageItemsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetDOMStorageItemsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetDOMStorageItemsResult> result(new GetDOMStorageItemsResult());
  errors->Push();
  errors->SetName("GetDOMStorageItemsResult");
  const base::Value* entries_value = value.FindKey("entries");
  if (entries_value) {
    errors->SetName("entries");
    result->entries_ = internal::FromValue<std::vector<std::vector<std::string>>>::Parse(*entries_value, errors);
  } else {
    errors->AddError("required property missing: entries");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetDOMStorageItemsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("entries", internal::ToValue(entries_));
  return std::move(result);
}

std::unique_ptr<GetDOMStorageItemsResult> GetDOMStorageItemsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetDOMStorageItemsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveDOMStorageItemParams> RemoveDOMStorageItemParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveDOMStorageItemParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveDOMStorageItemParams> result(new RemoveDOMStorageItemParams());
  errors->Push();
  errors->SetName("RemoveDOMStorageItemParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<std::string>::Parse(*key_value, errors);
  } else {
    errors->AddError("required property missing: key");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveDOMStorageItemParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  result->Set("key", internal::ToValue(key_));
  return std::move(result);
}

std::unique_ptr<RemoveDOMStorageItemParams> RemoveDOMStorageItemParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveDOMStorageItemParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveDOMStorageItemResult> RemoveDOMStorageItemResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveDOMStorageItemResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveDOMStorageItemResult> result(new RemoveDOMStorageItemResult());
  errors->Push();
  errors->SetName("RemoveDOMStorageItemResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveDOMStorageItemResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveDOMStorageItemResult> RemoveDOMStorageItemResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveDOMStorageItemResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDOMStorageItemParams> SetDOMStorageItemParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDOMStorageItemParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDOMStorageItemParams> result(new SetDOMStorageItemParams());
  errors->Push();
  errors->SetName("SetDOMStorageItemParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<std::string>::Parse(*key_value, errors);
  } else {
    errors->AddError("required property missing: key");
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

std::unique_ptr<base::Value> SetDOMStorageItemParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  result->Set("key", internal::ToValue(key_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<SetDOMStorageItemParams> SetDOMStorageItemParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDOMStorageItemParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetDOMStorageItemResult> SetDOMStorageItemResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetDOMStorageItemResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetDOMStorageItemResult> result(new SetDOMStorageItemResult());
  errors->Push();
  errors->SetName("SetDOMStorageItemResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetDOMStorageItemResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetDOMStorageItemResult> SetDOMStorageItemResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetDOMStorageItemResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DomStorageItemAddedParams> DomStorageItemAddedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DomStorageItemAddedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DomStorageItemAddedParams> result(new DomStorageItemAddedParams());
  errors->Push();
  errors->SetName("DomStorageItemAddedParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<std::string>::Parse(*key_value, errors);
  } else {
    errors->AddError("required property missing: key");
  }
  const base::Value* new_value_value = value.FindKey("newValue");
  if (new_value_value) {
    errors->SetName("newValue");
    result->new_value_ = internal::FromValue<std::string>::Parse(*new_value_value, errors);
  } else {
    errors->AddError("required property missing: newValue");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DomStorageItemAddedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  result->Set("key", internal::ToValue(key_));
  result->Set("newValue", internal::ToValue(new_value_));
  return std::move(result);
}

std::unique_ptr<DomStorageItemAddedParams> DomStorageItemAddedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemAddedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DomStorageItemRemovedParams> DomStorageItemRemovedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DomStorageItemRemovedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DomStorageItemRemovedParams> result(new DomStorageItemRemovedParams());
  errors->Push();
  errors->SetName("DomStorageItemRemovedParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<std::string>::Parse(*key_value, errors);
  } else {
    errors->AddError("required property missing: key");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DomStorageItemRemovedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  result->Set("key", internal::ToValue(key_));
  return std::move(result);
}

std::unique_ptr<DomStorageItemRemovedParams> DomStorageItemRemovedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemRemovedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DomStorageItemUpdatedParams> DomStorageItemUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DomStorageItemUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DomStorageItemUpdatedParams> result(new DomStorageItemUpdatedParams());
  errors->Push();
  errors->SetName("DomStorageItemUpdatedParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<std::string>::Parse(*key_value, errors);
  } else {
    errors->AddError("required property missing: key");
  }
  const base::Value* old_value_value = value.FindKey("oldValue");
  if (old_value_value) {
    errors->SetName("oldValue");
    result->old_value_ = internal::FromValue<std::string>::Parse(*old_value_value, errors);
  } else {
    errors->AddError("required property missing: oldValue");
  }
  const base::Value* new_value_value = value.FindKey("newValue");
  if (new_value_value) {
    errors->SetName("newValue");
    result->new_value_ = internal::FromValue<std::string>::Parse(*new_value_value, errors);
  } else {
    errors->AddError("required property missing: newValue");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DomStorageItemUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  result->Set("key", internal::ToValue(key_));
  result->Set("oldValue", internal::ToValue(old_value_));
  result->Set("newValue", internal::ToValue(new_value_));
  return std::move(result);
}

std::unique_ptr<DomStorageItemUpdatedParams> DomStorageItemUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DomStorageItemsClearedParams> DomStorageItemsClearedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DomStorageItemsClearedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DomStorageItemsClearedParams> result(new DomStorageItemsClearedParams());
  errors->Push();
  errors->SetName("DomStorageItemsClearedParams");
  const base::Value* storage_id_value = value.FindKey("storageId");
  if (storage_id_value) {
    errors->SetName("storageId");
    result->storage_id_ = internal::FromValue<::headless::dom_storage::StorageId>::Parse(*storage_id_value, errors);
  } else {
    errors->AddError("required property missing: storageId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DomStorageItemsClearedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("storageId", internal::ToValue(*storage_id_));
  return std::move(result);
}

std::unique_ptr<DomStorageItemsClearedParams> DomStorageItemsClearedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DomStorageItemsClearedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace dom_storage
}  // namespace headless
