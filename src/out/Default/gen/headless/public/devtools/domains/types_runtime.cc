// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_runtime.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"

namespace headless {

namespace runtime {

std::unique_ptr<RemoteObject> RemoteObject::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoteObject");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoteObject> result(new RemoteObject());
  errors->Push();
  errors->SetName("RemoteObject");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::runtime::RemoteObjectType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* subtype_value = value.FindKey("subtype");
  if (subtype_value) {
    errors->SetName("subtype");
    result->subtype_ = internal::FromValue<::headless::runtime::RemoteObjectSubtype>::Parse(*subtype_value, errors);
  }
  const base::Value* class_name_value = value.FindKey("className");
  if (class_name_value) {
    errors->SetName("className");
    result->class_name_ = internal::FromValue<std::string>::Parse(*class_name_value, errors);
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<base::Value>::Parse(*value_value, errors);
  }
  const base::Value* unserializable_value_value = value.FindKey("unserializableValue");
  if (unserializable_value_value) {
    errors->SetName("unserializableValue");
    result->unserializable_value_ = internal::FromValue<std::string>::Parse(*unserializable_value_value, errors);
  }
  const base::Value* description_value = value.FindKey("description");
  if (description_value) {
    errors->SetName("description");
    result->description_ = internal::FromValue<std::string>::Parse(*description_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  const base::Value* preview_value = value.FindKey("preview");
  if (preview_value) {
    errors->SetName("preview");
    result->preview_ = internal::FromValue<::headless::runtime::ObjectPreview>::Parse(*preview_value, errors);
  }
  const base::Value* custom_preview_value = value.FindKey("customPreview");
  if (custom_preview_value) {
    errors->SetName("customPreview");
    result->custom_preview_ = internal::FromValue<::headless::runtime::CustomPreview>::Parse(*custom_preview_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoteObject::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  if (subtype_)
    result->Set("subtype", internal::ToValue(subtype_.value()));
  if (class_name_)
    result->Set("className", internal::ToValue(class_name_.value()));
  if (value_)
    result->Set("value", internal::ToValue(*value_.value()));
  if (unserializable_value_)
    result->Set("unserializableValue", internal::ToValue(unserializable_value_.value()));
  if (description_)
    result->Set("description", internal::ToValue(description_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  if (preview_)
    result->Set("preview", internal::ToValue(*preview_.value()));
  if (custom_preview_)
    result->Set("customPreview", internal::ToValue(*custom_preview_.value()));
  return std::move(result);
}

std::unique_ptr<RemoteObject> RemoteObject::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoteObject> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CustomPreview> CustomPreview::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CustomPreview");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CustomPreview> result(new CustomPreview());
  errors->Push();
  errors->SetName("CustomPreview");
  const base::Value* header_value = value.FindKey("header");
  if (header_value) {
    errors->SetName("header");
    result->header_ = internal::FromValue<std::string>::Parse(*header_value, errors);
  } else {
    errors->AddError("required property missing: header");
  }
  const base::Value* body_getter_id_value = value.FindKey("bodyGetterId");
  if (body_getter_id_value) {
    errors->SetName("bodyGetterId");
    result->body_getter_id_ = internal::FromValue<std::string>::Parse(*body_getter_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CustomPreview::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("header", internal::ToValue(header_));
  if (body_getter_id_)
    result->Set("bodyGetterId", internal::ToValue(body_getter_id_.value()));
  return std::move(result);
}

std::unique_ptr<CustomPreview> CustomPreview::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CustomPreview> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ObjectPreview> ObjectPreview::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ObjectPreview");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ObjectPreview> result(new ObjectPreview());
  errors->Push();
  errors->SetName("ObjectPreview");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::runtime::ObjectPreviewType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* subtype_value = value.FindKey("subtype");
  if (subtype_value) {
    errors->SetName("subtype");
    result->subtype_ = internal::FromValue<::headless::runtime::ObjectPreviewSubtype>::Parse(*subtype_value, errors);
  }
  const base::Value* description_value = value.FindKey("description");
  if (description_value) {
    errors->SetName("description");
    result->description_ = internal::FromValue<std::string>::Parse(*description_value, errors);
  }
  const base::Value* overflow_value = value.FindKey("overflow");
  if (overflow_value) {
    errors->SetName("overflow");
    result->overflow_ = internal::FromValue<bool>::Parse(*overflow_value, errors);
  } else {
    errors->AddError("required property missing: overflow");
  }
  const base::Value* properties_value = value.FindKey("properties");
  if (properties_value) {
    errors->SetName("properties");
    result->properties_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::PropertyPreview>>>::Parse(*properties_value, errors);
  } else {
    errors->AddError("required property missing: properties");
  }
  const base::Value* entries_value = value.FindKey("entries");
  if (entries_value) {
    errors->SetName("entries");
    result->entries_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::EntryPreview>>>::Parse(*entries_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ObjectPreview::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  if (subtype_)
    result->Set("subtype", internal::ToValue(subtype_.value()));
  if (description_)
    result->Set("description", internal::ToValue(description_.value()));
  result->Set("overflow", internal::ToValue(overflow_));
  result->Set("properties", internal::ToValue(properties_));
  if (entries_)
    result->Set("entries", internal::ToValue(entries_.value()));
  return std::move(result);
}

std::unique_ptr<ObjectPreview> ObjectPreview::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ObjectPreview> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PropertyPreview> PropertyPreview::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PropertyPreview");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PropertyPreview> result(new PropertyPreview());
  errors->Push();
  errors->SetName("PropertyPreview");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::runtime::PropertyPreviewType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  }
  const base::Value* value_preview_value = value.FindKey("valuePreview");
  if (value_preview_value) {
    errors->SetName("valuePreview");
    result->value_preview_ = internal::FromValue<::headless::runtime::ObjectPreview>::Parse(*value_preview_value, errors);
  }
  const base::Value* subtype_value = value.FindKey("subtype");
  if (subtype_value) {
    errors->SetName("subtype");
    result->subtype_ = internal::FromValue<::headless::runtime::PropertyPreviewSubtype>::Parse(*subtype_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PropertyPreview::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("type", internal::ToValue(type_));
  if (value_)
    result->Set("value", internal::ToValue(value_.value()));
  if (value_preview_)
    result->Set("valuePreview", internal::ToValue(*value_preview_.value()));
  if (subtype_)
    result->Set("subtype", internal::ToValue(subtype_.value()));
  return std::move(result);
}

std::unique_ptr<PropertyPreview> PropertyPreview::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PropertyPreview> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EntryPreview> EntryPreview::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EntryPreview");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EntryPreview> result(new EntryPreview());
  errors->Push();
  errors->SetName("EntryPreview");
  const base::Value* key_value = value.FindKey("key");
  if (key_value) {
    errors->SetName("key");
    result->key_ = internal::FromValue<::headless::runtime::ObjectPreview>::Parse(*key_value, errors);
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<::headless::runtime::ObjectPreview>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EntryPreview::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (key_)
    result->Set("key", internal::ToValue(*key_.value()));
  result->Set("value", internal::ToValue(*value_));
  return std::move(result);
}

std::unique_ptr<EntryPreview> EntryPreview::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EntryPreview> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PropertyDescriptor> PropertyDescriptor::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PropertyDescriptor");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PropertyDescriptor> result(new PropertyDescriptor());
  errors->Push();
  errors->SetName("PropertyDescriptor");
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
    result->value_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*value_value, errors);
  }
  const base::Value* writable_value = value.FindKey("writable");
  if (writable_value) {
    errors->SetName("writable");
    result->writable_ = internal::FromValue<bool>::Parse(*writable_value, errors);
  }
  const base::Value* get_value = value.FindKey("get");
  if (get_value) {
    errors->SetName("get");
    result->get_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*get_value, errors);
  }
  const base::Value* set_value = value.FindKey("set");
  if (set_value) {
    errors->SetName("set");
    result->set_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*set_value, errors);
  }
  const base::Value* configurable_value = value.FindKey("configurable");
  if (configurable_value) {
    errors->SetName("configurable");
    result->configurable_ = internal::FromValue<bool>::Parse(*configurable_value, errors);
  } else {
    errors->AddError("required property missing: configurable");
  }
  const base::Value* enumerable_value = value.FindKey("enumerable");
  if (enumerable_value) {
    errors->SetName("enumerable");
    result->enumerable_ = internal::FromValue<bool>::Parse(*enumerable_value, errors);
  } else {
    errors->AddError("required property missing: enumerable");
  }
  const base::Value* was_thrown_value = value.FindKey("wasThrown");
  if (was_thrown_value) {
    errors->SetName("wasThrown");
    result->was_thrown_ = internal::FromValue<bool>::Parse(*was_thrown_value, errors);
  }
  const base::Value* is_own_value = value.FindKey("isOwn");
  if (is_own_value) {
    errors->SetName("isOwn");
    result->is_own_ = internal::FromValue<bool>::Parse(*is_own_value, errors);
  }
  const base::Value* symbol_value = value.FindKey("symbol");
  if (symbol_value) {
    errors->SetName("symbol");
    result->symbol_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*symbol_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PropertyDescriptor::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  if (value_)
    result->Set("value", internal::ToValue(*value_.value()));
  if (writable_)
    result->Set("writable", internal::ToValue(writable_.value()));
  if (get_)
    result->Set("get", internal::ToValue(*get_.value()));
  if (set_)
    result->Set("set", internal::ToValue(*set_.value()));
  result->Set("configurable", internal::ToValue(configurable_));
  result->Set("enumerable", internal::ToValue(enumerable_));
  if (was_thrown_)
    result->Set("wasThrown", internal::ToValue(was_thrown_.value()));
  if (is_own_)
    result->Set("isOwn", internal::ToValue(is_own_.value()));
  if (symbol_)
    result->Set("symbol", internal::ToValue(*symbol_.value()));
  return std::move(result);
}

std::unique_ptr<PropertyDescriptor> PropertyDescriptor::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PropertyDescriptor> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InternalPropertyDescriptor> InternalPropertyDescriptor::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InternalPropertyDescriptor");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InternalPropertyDescriptor> result(new InternalPropertyDescriptor());
  errors->Push();
  errors->SetName("InternalPropertyDescriptor");
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
    result->value_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*value_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InternalPropertyDescriptor::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  if (value_)
    result->Set("value", internal::ToValue(*value_.value()));
  return std::move(result);
}

std::unique_ptr<InternalPropertyDescriptor> InternalPropertyDescriptor::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InternalPropertyDescriptor> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PrivatePropertyDescriptor> PrivatePropertyDescriptor::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PrivatePropertyDescriptor");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PrivatePropertyDescriptor> result(new PrivatePropertyDescriptor());
  errors->Push();
  errors->SetName("PrivatePropertyDescriptor");
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
    result->value_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*value_value, errors);
  }
  const base::Value* get_value = value.FindKey("get");
  if (get_value) {
    errors->SetName("get");
    result->get_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*get_value, errors);
  }
  const base::Value* set_value = value.FindKey("set");
  if (set_value) {
    errors->SetName("set");
    result->set_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*set_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PrivatePropertyDescriptor::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  if (value_)
    result->Set("value", internal::ToValue(*value_.value()));
  if (get_)
    result->Set("get", internal::ToValue(*get_.value()));
  if (set_)
    result->Set("set", internal::ToValue(*set_.value()));
  return std::move(result);
}

std::unique_ptr<PrivatePropertyDescriptor> PrivatePropertyDescriptor::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PrivatePropertyDescriptor> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CallArgument> CallArgument::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CallArgument");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CallArgument> result(new CallArgument());
  errors->Push();
  errors->SetName("CallArgument");
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<base::Value>::Parse(*value_value, errors);
  }
  const base::Value* unserializable_value_value = value.FindKey("unserializableValue");
  if (unserializable_value_value) {
    errors->SetName("unserializableValue");
    result->unserializable_value_ = internal::FromValue<std::string>::Parse(*unserializable_value_value, errors);
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CallArgument::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (value_)
    result->Set("value", internal::ToValue(*value_.value()));
  if (unserializable_value_)
    result->Set("unserializableValue", internal::ToValue(unserializable_value_.value()));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  return std::move(result);
}

std::unique_ptr<CallArgument> CallArgument::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CallArgument> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExecutionContextDescription> ExecutionContextDescription::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExecutionContextDescription");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExecutionContextDescription> result(new ExecutionContextDescription());
  errors->Push();
  errors->SetName("ExecutionContextDescription");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<int>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<std::string>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* aux_data_value = value.FindKey("auxData");
  if (aux_data_value) {
    errors->SetName("auxData");
    result->aux_data_ = internal::FromValue<base::Value>::Parse(*aux_data_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExecutionContextDescription::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  result->Set("origin", internal::ToValue(origin_));
  result->Set("name", internal::ToValue(name_));
  if (aux_data_)
    result->Set("auxData", internal::ToValue(*aux_data_.value()));
  return std::move(result);
}

std::unique_ptr<ExecutionContextDescription> ExecutionContextDescription::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExecutionContextDescription> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExceptionDetails> ExceptionDetails::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExceptionDetails");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExceptionDetails> result(new ExceptionDetails());
  errors->Push();
  errors->SetName("ExceptionDetails");
  const base::Value* exception_id_value = value.FindKey("exceptionId");
  if (exception_id_value) {
    errors->SetName("exceptionId");
    result->exception_id_ = internal::FromValue<int>::Parse(*exception_id_value, errors);
  } else {
    errors->AddError("required property missing: exceptionId");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  const base::Value* line_number_value = value.FindKey("lineNumber");
  if (line_number_value) {
    errors->SetName("lineNumber");
    result->line_number_ = internal::FromValue<int>::Parse(*line_number_value, errors);
  } else {
    errors->AddError("required property missing: lineNumber");
  }
  const base::Value* column_number_value = value.FindKey("columnNumber");
  if (column_number_value) {
    errors->SetName("columnNumber");
    result->column_number_ = internal::FromValue<int>::Parse(*column_number_value, errors);
  } else {
    errors->AddError("required property missing: columnNumber");
  }
  const base::Value* script_id_value = value.FindKey("scriptId");
  if (script_id_value) {
    errors->SetName("scriptId");
    result->script_id_ = internal::FromValue<std::string>::Parse(*script_id_value, errors);
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  }
  const base::Value* stack_trace_value = value.FindKey("stackTrace");
  if (stack_trace_value) {
    errors->SetName("stackTrace");
    result->stack_trace_ = internal::FromValue<::headless::runtime::StackTrace>::Parse(*stack_trace_value, errors);
  }
  const base::Value* exception_value = value.FindKey("exception");
  if (exception_value) {
    errors->SetName("exception");
    result->exception_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*exception_value, errors);
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExceptionDetails::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("exceptionId", internal::ToValue(exception_id_));
  result->Set("text", internal::ToValue(text_));
  result->Set("lineNumber", internal::ToValue(line_number_));
  result->Set("columnNumber", internal::ToValue(column_number_));
  if (script_id_)
    result->Set("scriptId", internal::ToValue(script_id_.value()));
  if (url_)
    result->Set("url", internal::ToValue(url_.value()));
  if (stack_trace_)
    result->Set("stackTrace", internal::ToValue(*stack_trace_.value()));
  if (exception_)
    result->Set("exception", internal::ToValue(*exception_.value()));
  if (execution_context_id_)
    result->Set("executionContextId", internal::ToValue(execution_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<ExceptionDetails> ExceptionDetails::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExceptionDetails> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CallFrame> CallFrame::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CallFrame");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CallFrame> result(new CallFrame());
  errors->Push();
  errors->SetName("CallFrame");
  const base::Value* function_name_value = value.FindKey("functionName");
  if (function_name_value) {
    errors->SetName("functionName");
    result->function_name_ = internal::FromValue<std::string>::Parse(*function_name_value, errors);
  } else {
    errors->AddError("required property missing: functionName");
  }
  const base::Value* script_id_value = value.FindKey("scriptId");
  if (script_id_value) {
    errors->SetName("scriptId");
    result->script_id_ = internal::FromValue<std::string>::Parse(*script_id_value, errors);
  } else {
    errors->AddError("required property missing: scriptId");
  }
  const base::Value* url_value = value.FindKey("url");
  if (url_value) {
    errors->SetName("url");
    result->url_ = internal::FromValue<std::string>::Parse(*url_value, errors);
  } else {
    errors->AddError("required property missing: url");
  }
  const base::Value* line_number_value = value.FindKey("lineNumber");
  if (line_number_value) {
    errors->SetName("lineNumber");
    result->line_number_ = internal::FromValue<int>::Parse(*line_number_value, errors);
  } else {
    errors->AddError("required property missing: lineNumber");
  }
  const base::Value* column_number_value = value.FindKey("columnNumber");
  if (column_number_value) {
    errors->SetName("columnNumber");
    result->column_number_ = internal::FromValue<int>::Parse(*column_number_value, errors);
  } else {
    errors->AddError("required property missing: columnNumber");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CallFrame::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("functionName", internal::ToValue(function_name_));
  result->Set("scriptId", internal::ToValue(script_id_));
  result->Set("url", internal::ToValue(url_));
  result->Set("lineNumber", internal::ToValue(line_number_));
  result->Set("columnNumber", internal::ToValue(column_number_));
  return std::move(result);
}

std::unique_ptr<CallFrame> CallFrame::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CallFrame> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StackTrace> StackTrace::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StackTrace");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StackTrace> result(new StackTrace());
  errors->Push();
  errors->SetName("StackTrace");
  const base::Value* description_value = value.FindKey("description");
  if (description_value) {
    errors->SetName("description");
    result->description_ = internal::FromValue<std::string>::Parse(*description_value, errors);
  }
  const base::Value* call_frames_value = value.FindKey("callFrames");
  if (call_frames_value) {
    errors->SetName("callFrames");
    result->call_frames_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::CallFrame>>>::Parse(*call_frames_value, errors);
  } else {
    errors->AddError("required property missing: callFrames");
  }
  const base::Value* parent_value = value.FindKey("parent");
  if (parent_value) {
    errors->SetName("parent");
    result->parent_ = internal::FromValue<::headless::runtime::StackTrace>::Parse(*parent_value, errors);
  }
  const base::Value* parent_id_value = value.FindKey("parentId");
  if (parent_id_value) {
    errors->SetName("parentId");
    result->parent_id_ = internal::FromValue<::headless::runtime::StackTraceId>::Parse(*parent_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StackTrace::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (description_)
    result->Set("description", internal::ToValue(description_.value()));
  result->Set("callFrames", internal::ToValue(call_frames_));
  if (parent_)
    result->Set("parent", internal::ToValue(*parent_.value()));
  if (parent_id_)
    result->Set("parentId", internal::ToValue(*parent_id_.value()));
  return std::move(result);
}

std::unique_ptr<StackTrace> StackTrace::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StackTrace> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StackTraceId> StackTraceId::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StackTraceId");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StackTraceId> result(new StackTraceId());
  errors->Push();
  errors->SetName("StackTraceId");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  const base::Value* debugger_id_value = value.FindKey("debuggerId");
  if (debugger_id_value) {
    errors->SetName("debuggerId");
    result->debugger_id_ = internal::FromValue<std::string>::Parse(*debugger_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StackTraceId::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  if (debugger_id_)
    result->Set("debuggerId", internal::ToValue(debugger_id_.value()));
  return std::move(result);
}

std::unique_ptr<StackTraceId> StackTraceId::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StackTraceId> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AwaitPromiseParams> AwaitPromiseParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AwaitPromiseParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AwaitPromiseParams> result(new AwaitPromiseParams());
  errors->Push();
  errors->SetName("AwaitPromiseParams");
  const base::Value* promise_object_id_value = value.FindKey("promiseObjectId");
  if (promise_object_id_value) {
    errors->SetName("promiseObjectId");
    result->promise_object_id_ = internal::FromValue<std::string>::Parse(*promise_object_id_value, errors);
  } else {
    errors->AddError("required property missing: promiseObjectId");
  }
  const base::Value* return_by_value_value = value.FindKey("returnByValue");
  if (return_by_value_value) {
    errors->SetName("returnByValue");
    result->return_by_value_ = internal::FromValue<bool>::Parse(*return_by_value_value, errors);
  }
  const base::Value* generate_preview_value = value.FindKey("generatePreview");
  if (generate_preview_value) {
    errors->SetName("generatePreview");
    result->generate_preview_ = internal::FromValue<bool>::Parse(*generate_preview_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AwaitPromiseParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("promiseObjectId", internal::ToValue(promise_object_id_));
  if (return_by_value_)
    result->Set("returnByValue", internal::ToValue(return_by_value_.value()));
  if (generate_preview_)
    result->Set("generatePreview", internal::ToValue(generate_preview_.value()));
  return std::move(result);
}

std::unique_ptr<AwaitPromiseParams> AwaitPromiseParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AwaitPromiseParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AwaitPromiseResult> AwaitPromiseResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AwaitPromiseResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AwaitPromiseResult> result(new AwaitPromiseResult());
  errors->Push();
  errors->SetName("AwaitPromiseResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  const base::Value* exception_details_value = value.FindKey("exceptionDetails");
  if (exception_details_value) {
    errors->SetName("exceptionDetails");
    result->exception_details_ = internal::FromValue<::headless::runtime::ExceptionDetails>::Parse(*exception_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AwaitPromiseResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(*result_));
  if (exception_details_)
    result->Set("exceptionDetails", internal::ToValue(*exception_details_.value()));
  return std::move(result);
}

std::unique_ptr<AwaitPromiseResult> AwaitPromiseResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AwaitPromiseResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CallFunctionOnParams> CallFunctionOnParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CallFunctionOnParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CallFunctionOnParams> result(new CallFunctionOnParams());
  errors->Push();
  errors->SetName("CallFunctionOnParams");
  const base::Value* function_declaration_value = value.FindKey("functionDeclaration");
  if (function_declaration_value) {
    errors->SetName("functionDeclaration");
    result->function_declaration_ = internal::FromValue<std::string>::Parse(*function_declaration_value, errors);
  } else {
    errors->AddError("required property missing: functionDeclaration");
  }
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  }
  const base::Value* arguments_value = value.FindKey("arguments");
  if (arguments_value) {
    errors->SetName("arguments");
    result->arguments_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::CallArgument>>>::Parse(*arguments_value, errors);
  }
  const base::Value* silent_value = value.FindKey("silent");
  if (silent_value) {
    errors->SetName("silent");
    result->silent_ = internal::FromValue<bool>::Parse(*silent_value, errors);
  }
  const base::Value* return_by_value_value = value.FindKey("returnByValue");
  if (return_by_value_value) {
    errors->SetName("returnByValue");
    result->return_by_value_ = internal::FromValue<bool>::Parse(*return_by_value_value, errors);
  }
  const base::Value* generate_preview_value = value.FindKey("generatePreview");
  if (generate_preview_value) {
    errors->SetName("generatePreview");
    result->generate_preview_ = internal::FromValue<bool>::Parse(*generate_preview_value, errors);
  }
  const base::Value* user_gesture_value = value.FindKey("userGesture");
  if (user_gesture_value) {
    errors->SetName("userGesture");
    result->user_gesture_ = internal::FromValue<bool>::Parse(*user_gesture_value, errors);
  }
  const base::Value* await_promise_value = value.FindKey("awaitPromise");
  if (await_promise_value) {
    errors->SetName("awaitPromise");
    result->await_promise_ = internal::FromValue<bool>::Parse(*await_promise_value, errors);
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  }
  const base::Value* object_group_value = value.FindKey("objectGroup");
  if (object_group_value) {
    errors->SetName("objectGroup");
    result->object_group_ = internal::FromValue<std::string>::Parse(*object_group_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CallFunctionOnParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("functionDeclaration", internal::ToValue(function_declaration_));
  if (object_id_)
    result->Set("objectId", internal::ToValue(object_id_.value()));
  if (arguments_)
    result->Set("arguments", internal::ToValue(arguments_.value()));
  if (silent_)
    result->Set("silent", internal::ToValue(silent_.value()));
  if (return_by_value_)
    result->Set("returnByValue", internal::ToValue(return_by_value_.value()));
  if (generate_preview_)
    result->Set("generatePreview", internal::ToValue(generate_preview_.value()));
  if (user_gesture_)
    result->Set("userGesture", internal::ToValue(user_gesture_.value()));
  if (await_promise_)
    result->Set("awaitPromise", internal::ToValue(await_promise_.value()));
  if (execution_context_id_)
    result->Set("executionContextId", internal::ToValue(execution_context_id_.value()));
  if (object_group_)
    result->Set("objectGroup", internal::ToValue(object_group_.value()));
  return std::move(result);
}

std::unique_ptr<CallFunctionOnParams> CallFunctionOnParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CallFunctionOnParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CallFunctionOnResult> CallFunctionOnResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CallFunctionOnResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CallFunctionOnResult> result(new CallFunctionOnResult());
  errors->Push();
  errors->SetName("CallFunctionOnResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  const base::Value* exception_details_value = value.FindKey("exceptionDetails");
  if (exception_details_value) {
    errors->SetName("exceptionDetails");
    result->exception_details_ = internal::FromValue<::headless::runtime::ExceptionDetails>::Parse(*exception_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CallFunctionOnResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(*result_));
  if (exception_details_)
    result->Set("exceptionDetails", internal::ToValue(*exception_details_.value()));
  return std::move(result);
}

std::unique_ptr<CallFunctionOnResult> CallFunctionOnResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CallFunctionOnResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CompileScriptParams> CompileScriptParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CompileScriptParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CompileScriptParams> result(new CompileScriptParams());
  errors->Push();
  errors->SetName("CompileScriptParams");
  const base::Value* expression_value = value.FindKey("expression");
  if (expression_value) {
    errors->SetName("expression");
    result->expression_ = internal::FromValue<std::string>::Parse(*expression_value, errors);
  } else {
    errors->AddError("required property missing: expression");
  }
  const base::Value* sourceurl_value = value.FindKey("sourceURL");
  if (sourceurl_value) {
    errors->SetName("sourceURL");
    result->sourceurl_ = internal::FromValue<std::string>::Parse(*sourceurl_value, errors);
  } else {
    errors->AddError("required property missing: sourceURL");
  }
  const base::Value* persist_script_value = value.FindKey("persistScript");
  if (persist_script_value) {
    errors->SetName("persistScript");
    result->persist_script_ = internal::FromValue<bool>::Parse(*persist_script_value, errors);
  } else {
    errors->AddError("required property missing: persistScript");
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CompileScriptParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("expression", internal::ToValue(expression_));
  result->Set("sourceURL", internal::ToValue(sourceurl_));
  result->Set("persistScript", internal::ToValue(persist_script_));
  if (execution_context_id_)
    result->Set("executionContextId", internal::ToValue(execution_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<CompileScriptParams> CompileScriptParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CompileScriptParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CompileScriptResult> CompileScriptResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CompileScriptResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CompileScriptResult> result(new CompileScriptResult());
  errors->Push();
  errors->SetName("CompileScriptResult");
  const base::Value* script_id_value = value.FindKey("scriptId");
  if (script_id_value) {
    errors->SetName("scriptId");
    result->script_id_ = internal::FromValue<std::string>::Parse(*script_id_value, errors);
  }
  const base::Value* exception_details_value = value.FindKey("exceptionDetails");
  if (exception_details_value) {
    errors->SetName("exceptionDetails");
    result->exception_details_ = internal::FromValue<::headless::runtime::ExceptionDetails>::Parse(*exception_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CompileScriptResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (script_id_)
    result->Set("scriptId", internal::ToValue(script_id_.value()));
  if (exception_details_)
    result->Set("exceptionDetails", internal::ToValue(*exception_details_.value()));
  return std::move(result);
}

std::unique_ptr<CompileScriptResult> CompileScriptResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CompileScriptResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<DiscardConsoleEntriesParams> DiscardConsoleEntriesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DiscardConsoleEntriesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DiscardConsoleEntriesParams> result(new DiscardConsoleEntriesParams());
  errors->Push();
  errors->SetName("DiscardConsoleEntriesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DiscardConsoleEntriesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DiscardConsoleEntriesParams> DiscardConsoleEntriesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DiscardConsoleEntriesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DiscardConsoleEntriesResult> DiscardConsoleEntriesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DiscardConsoleEntriesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DiscardConsoleEntriesResult> result(new DiscardConsoleEntriesResult());
  errors->Push();
  errors->SetName("DiscardConsoleEntriesResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DiscardConsoleEntriesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DiscardConsoleEntriesResult> DiscardConsoleEntriesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DiscardConsoleEntriesResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<EvaluateParams> EvaluateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EvaluateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EvaluateParams> result(new EvaluateParams());
  errors->Push();
  errors->SetName("EvaluateParams");
  const base::Value* expression_value = value.FindKey("expression");
  if (expression_value) {
    errors->SetName("expression");
    result->expression_ = internal::FromValue<std::string>::Parse(*expression_value, errors);
  } else {
    errors->AddError("required property missing: expression");
  }
  const base::Value* object_group_value = value.FindKey("objectGroup");
  if (object_group_value) {
    errors->SetName("objectGroup");
    result->object_group_ = internal::FromValue<std::string>::Parse(*object_group_value, errors);
  }
  const base::Value* include_command_lineapi_value = value.FindKey("includeCommandLineAPI");
  if (include_command_lineapi_value) {
    errors->SetName("includeCommandLineAPI");
    result->include_command_lineapi_ = internal::FromValue<bool>::Parse(*include_command_lineapi_value, errors);
  }
  const base::Value* silent_value = value.FindKey("silent");
  if (silent_value) {
    errors->SetName("silent");
    result->silent_ = internal::FromValue<bool>::Parse(*silent_value, errors);
  }
  const base::Value* context_id_value = value.FindKey("contextId");
  if (context_id_value) {
    errors->SetName("contextId");
    result->context_id_ = internal::FromValue<int>::Parse(*context_id_value, errors);
  }
  const base::Value* return_by_value_value = value.FindKey("returnByValue");
  if (return_by_value_value) {
    errors->SetName("returnByValue");
    result->return_by_value_ = internal::FromValue<bool>::Parse(*return_by_value_value, errors);
  }
  const base::Value* generate_preview_value = value.FindKey("generatePreview");
  if (generate_preview_value) {
    errors->SetName("generatePreview");
    result->generate_preview_ = internal::FromValue<bool>::Parse(*generate_preview_value, errors);
  }
  const base::Value* user_gesture_value = value.FindKey("userGesture");
  if (user_gesture_value) {
    errors->SetName("userGesture");
    result->user_gesture_ = internal::FromValue<bool>::Parse(*user_gesture_value, errors);
  }
  const base::Value* await_promise_value = value.FindKey("awaitPromise");
  if (await_promise_value) {
    errors->SetName("awaitPromise");
    result->await_promise_ = internal::FromValue<bool>::Parse(*await_promise_value, errors);
  }
  const base::Value* throw_on_side_effect_value = value.FindKey("throwOnSideEffect");
  if (throw_on_side_effect_value) {
    errors->SetName("throwOnSideEffect");
    result->throw_on_side_effect_ = internal::FromValue<bool>::Parse(*throw_on_side_effect_value, errors);
  }
  const base::Value* timeout_value = value.FindKey("timeout");
  if (timeout_value) {
    errors->SetName("timeout");
    result->timeout_ = internal::FromValue<double>::Parse(*timeout_value, errors);
  }
  const base::Value* disable_breaks_value = value.FindKey("disableBreaks");
  if (disable_breaks_value) {
    errors->SetName("disableBreaks");
    result->disable_breaks_ = internal::FromValue<bool>::Parse(*disable_breaks_value, errors);
  }
  const base::Value* repl_mode_value = value.FindKey("replMode");
  if (repl_mode_value) {
    errors->SetName("replMode");
    result->repl_mode_ = internal::FromValue<bool>::Parse(*repl_mode_value, errors);
  }
  const base::Value* allow_unsafe_eval_blocked_bycsp_value = value.FindKey("allowUnsafeEvalBlockedByCSP");
  if (allow_unsafe_eval_blocked_bycsp_value) {
    errors->SetName("allowUnsafeEvalBlockedByCSP");
    result->allow_unsafe_eval_blocked_bycsp_ = internal::FromValue<bool>::Parse(*allow_unsafe_eval_blocked_bycsp_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EvaluateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("expression", internal::ToValue(expression_));
  if (object_group_)
    result->Set("objectGroup", internal::ToValue(object_group_.value()));
  if (include_command_lineapi_)
    result->Set("includeCommandLineAPI", internal::ToValue(include_command_lineapi_.value()));
  if (silent_)
    result->Set("silent", internal::ToValue(silent_.value()));
  if (context_id_)
    result->Set("contextId", internal::ToValue(context_id_.value()));
  if (return_by_value_)
    result->Set("returnByValue", internal::ToValue(return_by_value_.value()));
  if (generate_preview_)
    result->Set("generatePreview", internal::ToValue(generate_preview_.value()));
  if (user_gesture_)
    result->Set("userGesture", internal::ToValue(user_gesture_.value()));
  if (await_promise_)
    result->Set("awaitPromise", internal::ToValue(await_promise_.value()));
  if (throw_on_side_effect_)
    result->Set("throwOnSideEffect", internal::ToValue(throw_on_side_effect_.value()));
  if (timeout_)
    result->Set("timeout", internal::ToValue(timeout_.value()));
  if (disable_breaks_)
    result->Set("disableBreaks", internal::ToValue(disable_breaks_.value()));
  if (repl_mode_)
    result->Set("replMode", internal::ToValue(repl_mode_.value()));
  if (allow_unsafe_eval_blocked_bycsp_)
    result->Set("allowUnsafeEvalBlockedByCSP", internal::ToValue(allow_unsafe_eval_blocked_bycsp_.value()));
  return std::move(result);
}

std::unique_ptr<EvaluateParams> EvaluateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EvaluateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EvaluateResult> EvaluateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EvaluateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EvaluateResult> result(new EvaluateResult());
  errors->Push();
  errors->SetName("EvaluateResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  const base::Value* exception_details_value = value.FindKey("exceptionDetails");
  if (exception_details_value) {
    errors->SetName("exceptionDetails");
    result->exception_details_ = internal::FromValue<::headless::runtime::ExceptionDetails>::Parse(*exception_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EvaluateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(*result_));
  if (exception_details_)
    result->Set("exceptionDetails", internal::ToValue(*exception_details_.value()));
  return std::move(result);
}

std::unique_ptr<EvaluateResult> EvaluateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EvaluateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetIsolateIdParams> GetIsolateIdParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetIsolateIdParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetIsolateIdParams> result(new GetIsolateIdParams());
  errors->Push();
  errors->SetName("GetIsolateIdParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetIsolateIdParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetIsolateIdParams> GetIsolateIdParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetIsolateIdParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetIsolateIdResult> GetIsolateIdResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetIsolateIdResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetIsolateIdResult> result(new GetIsolateIdResult());
  errors->Push();
  errors->SetName("GetIsolateIdResult");
  const base::Value* id_value = value.FindKey("id");
  if (id_value) {
    errors->SetName("id");
    result->id_ = internal::FromValue<std::string>::Parse(*id_value, errors);
  } else {
    errors->AddError("required property missing: id");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetIsolateIdResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("id", internal::ToValue(id_));
  return std::move(result);
}

std::unique_ptr<GetIsolateIdResult> GetIsolateIdResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetIsolateIdResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetHeapUsageParams> GetHeapUsageParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHeapUsageParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHeapUsageParams> result(new GetHeapUsageParams());
  errors->Push();
  errors->SetName("GetHeapUsageParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHeapUsageParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetHeapUsageParams> GetHeapUsageParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHeapUsageParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetHeapUsageResult> GetHeapUsageResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetHeapUsageResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetHeapUsageResult> result(new GetHeapUsageResult());
  errors->Push();
  errors->SetName("GetHeapUsageResult");
  const base::Value* used_size_value = value.FindKey("usedSize");
  if (used_size_value) {
    errors->SetName("usedSize");
    result->used_size_ = internal::FromValue<double>::Parse(*used_size_value, errors);
  } else {
    errors->AddError("required property missing: usedSize");
  }
  const base::Value* total_size_value = value.FindKey("totalSize");
  if (total_size_value) {
    errors->SetName("totalSize");
    result->total_size_ = internal::FromValue<double>::Parse(*total_size_value, errors);
  } else {
    errors->AddError("required property missing: totalSize");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetHeapUsageResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("usedSize", internal::ToValue(used_size_));
  result->Set("totalSize", internal::ToValue(total_size_));
  return std::move(result);
}

std::unique_ptr<GetHeapUsageResult> GetHeapUsageResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetHeapUsageResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetPropertiesParams> GetPropertiesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetPropertiesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetPropertiesParams> result(new GetPropertiesParams());
  errors->Push();
  errors->SetName("GetPropertiesParams");
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  } else {
    errors->AddError("required property missing: objectId");
  }
  const base::Value* own_properties_value = value.FindKey("ownProperties");
  if (own_properties_value) {
    errors->SetName("ownProperties");
    result->own_properties_ = internal::FromValue<bool>::Parse(*own_properties_value, errors);
  }
  const base::Value* accessor_properties_only_value = value.FindKey("accessorPropertiesOnly");
  if (accessor_properties_only_value) {
    errors->SetName("accessorPropertiesOnly");
    result->accessor_properties_only_ = internal::FromValue<bool>::Parse(*accessor_properties_only_value, errors);
  }
  const base::Value* generate_preview_value = value.FindKey("generatePreview");
  if (generate_preview_value) {
    errors->SetName("generatePreview");
    result->generate_preview_ = internal::FromValue<bool>::Parse(*generate_preview_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetPropertiesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectId", internal::ToValue(object_id_));
  if (own_properties_)
    result->Set("ownProperties", internal::ToValue(own_properties_.value()));
  if (accessor_properties_only_)
    result->Set("accessorPropertiesOnly", internal::ToValue(accessor_properties_only_.value()));
  if (generate_preview_)
    result->Set("generatePreview", internal::ToValue(generate_preview_.value()));
  return std::move(result);
}

std::unique_ptr<GetPropertiesParams> GetPropertiesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetPropertiesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetPropertiesResult> GetPropertiesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetPropertiesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetPropertiesResult> result(new GetPropertiesResult());
  errors->Push();
  errors->SetName("GetPropertiesResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::PropertyDescriptor>>>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  const base::Value* internal_properties_value = value.FindKey("internalProperties");
  if (internal_properties_value) {
    errors->SetName("internalProperties");
    result->internal_properties_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::InternalPropertyDescriptor>>>::Parse(*internal_properties_value, errors);
  }
  const base::Value* private_properties_value = value.FindKey("privateProperties");
  if (private_properties_value) {
    errors->SetName("privateProperties");
    result->private_properties_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::PrivatePropertyDescriptor>>>::Parse(*private_properties_value, errors);
  }
  const base::Value* exception_details_value = value.FindKey("exceptionDetails");
  if (exception_details_value) {
    errors->SetName("exceptionDetails");
    result->exception_details_ = internal::FromValue<::headless::runtime::ExceptionDetails>::Parse(*exception_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetPropertiesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(result_));
  if (internal_properties_)
    result->Set("internalProperties", internal::ToValue(internal_properties_.value()));
  if (private_properties_)
    result->Set("privateProperties", internal::ToValue(private_properties_.value()));
  if (exception_details_)
    result->Set("exceptionDetails", internal::ToValue(*exception_details_.value()));
  return std::move(result);
}

std::unique_ptr<GetPropertiesResult> GetPropertiesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetPropertiesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GlobalLexicalScopeNamesParams> GlobalLexicalScopeNamesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GlobalLexicalScopeNamesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GlobalLexicalScopeNamesParams> result(new GlobalLexicalScopeNamesParams());
  errors->Push();
  errors->SetName("GlobalLexicalScopeNamesParams");
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GlobalLexicalScopeNamesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (execution_context_id_)
    result->Set("executionContextId", internal::ToValue(execution_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<GlobalLexicalScopeNamesParams> GlobalLexicalScopeNamesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GlobalLexicalScopeNamesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GlobalLexicalScopeNamesResult> GlobalLexicalScopeNamesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GlobalLexicalScopeNamesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GlobalLexicalScopeNamesResult> result(new GlobalLexicalScopeNamesResult());
  errors->Push();
  errors->SetName("GlobalLexicalScopeNamesResult");
  const base::Value* names_value = value.FindKey("names");
  if (names_value) {
    errors->SetName("names");
    result->names_ = internal::FromValue<std::vector<std::string>>::Parse(*names_value, errors);
  } else {
    errors->AddError("required property missing: names");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GlobalLexicalScopeNamesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("names", internal::ToValue(names_));
  return std::move(result);
}

std::unique_ptr<GlobalLexicalScopeNamesResult> GlobalLexicalScopeNamesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GlobalLexicalScopeNamesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<QueryObjectsParams> QueryObjectsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("QueryObjectsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<QueryObjectsParams> result(new QueryObjectsParams());
  errors->Push();
  errors->SetName("QueryObjectsParams");
  const base::Value* prototype_object_id_value = value.FindKey("prototypeObjectId");
  if (prototype_object_id_value) {
    errors->SetName("prototypeObjectId");
    result->prototype_object_id_ = internal::FromValue<std::string>::Parse(*prototype_object_id_value, errors);
  } else {
    errors->AddError("required property missing: prototypeObjectId");
  }
  const base::Value* object_group_value = value.FindKey("objectGroup");
  if (object_group_value) {
    errors->SetName("objectGroup");
    result->object_group_ = internal::FromValue<std::string>::Parse(*object_group_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> QueryObjectsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("prototypeObjectId", internal::ToValue(prototype_object_id_));
  if (object_group_)
    result->Set("objectGroup", internal::ToValue(object_group_.value()));
  return std::move(result);
}

std::unique_ptr<QueryObjectsParams> QueryObjectsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<QueryObjectsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<QueryObjectsResult> QueryObjectsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("QueryObjectsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<QueryObjectsResult> result(new QueryObjectsResult());
  errors->Push();
  errors->SetName("QueryObjectsResult");
  const base::Value* objects_value = value.FindKey("objects");
  if (objects_value) {
    errors->SetName("objects");
    result->objects_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*objects_value, errors);
  } else {
    errors->AddError("required property missing: objects");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> QueryObjectsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objects", internal::ToValue(*objects_));
  return std::move(result);
}

std::unique_ptr<QueryObjectsResult> QueryObjectsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<QueryObjectsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseObjectParams> ReleaseObjectParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseObjectParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseObjectParams> result(new ReleaseObjectParams());
  errors->Push();
  errors->SetName("ReleaseObjectParams");
  const base::Value* object_id_value = value.FindKey("objectId");
  if (object_id_value) {
    errors->SetName("objectId");
    result->object_id_ = internal::FromValue<std::string>::Parse(*object_id_value, errors);
  } else {
    errors->AddError("required property missing: objectId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseObjectParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectId", internal::ToValue(object_id_));
  return std::move(result);
}

std::unique_ptr<ReleaseObjectParams> ReleaseObjectParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseObjectParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseObjectResult> ReleaseObjectResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseObjectResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseObjectResult> result(new ReleaseObjectResult());
  errors->Push();
  errors->SetName("ReleaseObjectResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseObjectResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ReleaseObjectResult> ReleaseObjectResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseObjectResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseObjectGroupParams> ReleaseObjectGroupParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseObjectGroupParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseObjectGroupParams> result(new ReleaseObjectGroupParams());
  errors->Push();
  errors->SetName("ReleaseObjectGroupParams");
  const base::Value* object_group_value = value.FindKey("objectGroup");
  if (object_group_value) {
    errors->SetName("objectGroup");
    result->object_group_ = internal::FromValue<std::string>::Parse(*object_group_value, errors);
  } else {
    errors->AddError("required property missing: objectGroup");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseObjectGroupParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("objectGroup", internal::ToValue(object_group_));
  return std::move(result);
}

std::unique_ptr<ReleaseObjectGroupParams> ReleaseObjectGroupParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseObjectGroupParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseObjectGroupResult> ReleaseObjectGroupResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseObjectGroupResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseObjectGroupResult> result(new ReleaseObjectGroupResult());
  errors->Push();
  errors->SetName("ReleaseObjectGroupResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseObjectGroupResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ReleaseObjectGroupResult> ReleaseObjectGroupResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseObjectGroupResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RunIfWaitingForDebuggerParams> RunIfWaitingForDebuggerParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RunIfWaitingForDebuggerParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RunIfWaitingForDebuggerParams> result(new RunIfWaitingForDebuggerParams());
  errors->Push();
  errors->SetName("RunIfWaitingForDebuggerParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RunIfWaitingForDebuggerParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RunIfWaitingForDebuggerParams> RunIfWaitingForDebuggerParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RunIfWaitingForDebuggerParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RunIfWaitingForDebuggerResult> RunIfWaitingForDebuggerResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RunIfWaitingForDebuggerResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RunIfWaitingForDebuggerResult> result(new RunIfWaitingForDebuggerResult());
  errors->Push();
  errors->SetName("RunIfWaitingForDebuggerResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RunIfWaitingForDebuggerResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RunIfWaitingForDebuggerResult> RunIfWaitingForDebuggerResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RunIfWaitingForDebuggerResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RunScriptParams> RunScriptParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RunScriptParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RunScriptParams> result(new RunScriptParams());
  errors->Push();
  errors->SetName("RunScriptParams");
  const base::Value* script_id_value = value.FindKey("scriptId");
  if (script_id_value) {
    errors->SetName("scriptId");
    result->script_id_ = internal::FromValue<std::string>::Parse(*script_id_value, errors);
  } else {
    errors->AddError("required property missing: scriptId");
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  }
  const base::Value* object_group_value = value.FindKey("objectGroup");
  if (object_group_value) {
    errors->SetName("objectGroup");
    result->object_group_ = internal::FromValue<std::string>::Parse(*object_group_value, errors);
  }
  const base::Value* silent_value = value.FindKey("silent");
  if (silent_value) {
    errors->SetName("silent");
    result->silent_ = internal::FromValue<bool>::Parse(*silent_value, errors);
  }
  const base::Value* include_command_lineapi_value = value.FindKey("includeCommandLineAPI");
  if (include_command_lineapi_value) {
    errors->SetName("includeCommandLineAPI");
    result->include_command_lineapi_ = internal::FromValue<bool>::Parse(*include_command_lineapi_value, errors);
  }
  const base::Value* return_by_value_value = value.FindKey("returnByValue");
  if (return_by_value_value) {
    errors->SetName("returnByValue");
    result->return_by_value_ = internal::FromValue<bool>::Parse(*return_by_value_value, errors);
  }
  const base::Value* generate_preview_value = value.FindKey("generatePreview");
  if (generate_preview_value) {
    errors->SetName("generatePreview");
    result->generate_preview_ = internal::FromValue<bool>::Parse(*generate_preview_value, errors);
  }
  const base::Value* await_promise_value = value.FindKey("awaitPromise");
  if (await_promise_value) {
    errors->SetName("awaitPromise");
    result->await_promise_ = internal::FromValue<bool>::Parse(*await_promise_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RunScriptParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("scriptId", internal::ToValue(script_id_));
  if (execution_context_id_)
    result->Set("executionContextId", internal::ToValue(execution_context_id_.value()));
  if (object_group_)
    result->Set("objectGroup", internal::ToValue(object_group_.value()));
  if (silent_)
    result->Set("silent", internal::ToValue(silent_.value()));
  if (include_command_lineapi_)
    result->Set("includeCommandLineAPI", internal::ToValue(include_command_lineapi_.value()));
  if (return_by_value_)
    result->Set("returnByValue", internal::ToValue(return_by_value_.value()));
  if (generate_preview_)
    result->Set("generatePreview", internal::ToValue(generate_preview_.value()));
  if (await_promise_)
    result->Set("awaitPromise", internal::ToValue(await_promise_.value()));
  return std::move(result);
}

std::unique_ptr<RunScriptParams> RunScriptParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RunScriptParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RunScriptResult> RunScriptResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RunScriptResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RunScriptResult> result(new RunScriptResult());
  errors->Push();
  errors->SetName("RunScriptResult");
  const base::Value* result_value = value.FindKey("result");
  if (result_value) {
    errors->SetName("result");
    result->result_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*result_value, errors);
  } else {
    errors->AddError("required property missing: result");
  }
  const base::Value* exception_details_value = value.FindKey("exceptionDetails");
  if (exception_details_value) {
    errors->SetName("exceptionDetails");
    result->exception_details_ = internal::FromValue<::headless::runtime::ExceptionDetails>::Parse(*exception_details_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RunScriptResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("result", internal::ToValue(*result_));
  if (exception_details_)
    result->Set("exceptionDetails", internal::ToValue(*exception_details_.value()));
  return std::move(result);
}

std::unique_ptr<RunScriptResult> RunScriptResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RunScriptResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAsyncCallStackDepthParams> SetAsyncCallStackDepthParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAsyncCallStackDepthParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAsyncCallStackDepthParams> result(new SetAsyncCallStackDepthParams());
  errors->Push();
  errors->SetName("SetAsyncCallStackDepthParams");
  const base::Value* max_depth_value = value.FindKey("maxDepth");
  if (max_depth_value) {
    errors->SetName("maxDepth");
    result->max_depth_ = internal::FromValue<int>::Parse(*max_depth_value, errors);
  } else {
    errors->AddError("required property missing: maxDepth");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAsyncCallStackDepthParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("maxDepth", internal::ToValue(max_depth_));
  return std::move(result);
}

std::unique_ptr<SetAsyncCallStackDepthParams> SetAsyncCallStackDepthParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAsyncCallStackDepthParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetAsyncCallStackDepthResult> SetAsyncCallStackDepthResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetAsyncCallStackDepthResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetAsyncCallStackDepthResult> result(new SetAsyncCallStackDepthResult());
  errors->Push();
  errors->SetName("SetAsyncCallStackDepthResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetAsyncCallStackDepthResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetAsyncCallStackDepthResult> SetAsyncCallStackDepthResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetAsyncCallStackDepthResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCustomObjectFormatterEnabledParams> SetCustomObjectFormatterEnabledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCustomObjectFormatterEnabledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCustomObjectFormatterEnabledParams> result(new SetCustomObjectFormatterEnabledParams());
  errors->Push();
  errors->SetName("SetCustomObjectFormatterEnabledParams");
  const base::Value* enabled_value = value.FindKey("enabled");
  if (enabled_value) {
    errors->SetName("enabled");
    result->enabled_ = internal::FromValue<bool>::Parse(*enabled_value, errors);
  } else {
    errors->AddError("required property missing: enabled");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCustomObjectFormatterEnabledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("enabled", internal::ToValue(enabled_));
  return std::move(result);
}

std::unique_ptr<SetCustomObjectFormatterEnabledParams> SetCustomObjectFormatterEnabledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCustomObjectFormatterEnabledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetCustomObjectFormatterEnabledResult> SetCustomObjectFormatterEnabledResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetCustomObjectFormatterEnabledResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetCustomObjectFormatterEnabledResult> result(new SetCustomObjectFormatterEnabledResult());
  errors->Push();
  errors->SetName("SetCustomObjectFormatterEnabledResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetCustomObjectFormatterEnabledResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetCustomObjectFormatterEnabledResult> SetCustomObjectFormatterEnabledResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetCustomObjectFormatterEnabledResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetMaxCallStackSizeToCaptureParams> SetMaxCallStackSizeToCaptureParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetMaxCallStackSizeToCaptureParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetMaxCallStackSizeToCaptureParams> result(new SetMaxCallStackSizeToCaptureParams());
  errors->Push();
  errors->SetName("SetMaxCallStackSizeToCaptureParams");
  const base::Value* size_value = value.FindKey("size");
  if (size_value) {
    errors->SetName("size");
    result->size_ = internal::FromValue<int>::Parse(*size_value, errors);
  } else {
    errors->AddError("required property missing: size");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetMaxCallStackSizeToCaptureParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("size", internal::ToValue(size_));
  return std::move(result);
}

std::unique_ptr<SetMaxCallStackSizeToCaptureParams> SetMaxCallStackSizeToCaptureParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetMaxCallStackSizeToCaptureParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetMaxCallStackSizeToCaptureResult> SetMaxCallStackSizeToCaptureResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetMaxCallStackSizeToCaptureResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetMaxCallStackSizeToCaptureResult> result(new SetMaxCallStackSizeToCaptureResult());
  errors->Push();
  errors->SetName("SetMaxCallStackSizeToCaptureResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetMaxCallStackSizeToCaptureResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetMaxCallStackSizeToCaptureResult> SetMaxCallStackSizeToCaptureResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetMaxCallStackSizeToCaptureResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TerminateExecutionParams> TerminateExecutionParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TerminateExecutionParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TerminateExecutionParams> result(new TerminateExecutionParams());
  errors->Push();
  errors->SetName("TerminateExecutionParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TerminateExecutionParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TerminateExecutionParams> TerminateExecutionParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TerminateExecutionParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TerminateExecutionResult> TerminateExecutionResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TerminateExecutionResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TerminateExecutionResult> result(new TerminateExecutionResult());
  errors->Push();
  errors->SetName("TerminateExecutionResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TerminateExecutionResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TerminateExecutionResult> TerminateExecutionResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TerminateExecutionResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddBindingParams> AddBindingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddBindingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddBindingParams> result(new AddBindingParams());
  errors->Push();
  errors->SetName("AddBindingParams");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddBindingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  if (execution_context_id_)
    result->Set("executionContextId", internal::ToValue(execution_context_id_.value()));
  return std::move(result);
}

std::unique_ptr<AddBindingParams> AddBindingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddBindingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddBindingResult> AddBindingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddBindingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddBindingResult> result(new AddBindingResult());
  errors->Push();
  errors->SetName("AddBindingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddBindingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<AddBindingResult> AddBindingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddBindingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveBindingParams> RemoveBindingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveBindingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveBindingParams> result(new RemoveBindingParams());
  errors->Push();
  errors->SetName("RemoveBindingParams");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveBindingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  return std::move(result);
}

std::unique_ptr<RemoveBindingParams> RemoveBindingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveBindingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RemoveBindingResult> RemoveBindingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RemoveBindingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RemoveBindingResult> result(new RemoveBindingResult());
  errors->Push();
  errors->SetName("RemoveBindingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RemoveBindingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<RemoveBindingResult> RemoveBindingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RemoveBindingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<BindingCalledParams> BindingCalledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("BindingCalledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<BindingCalledParams> result(new BindingCalledParams());
  errors->Push();
  errors->SetName("BindingCalledParams");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* payload_value = value.FindKey("payload");
  if (payload_value) {
    errors->SetName("payload");
    result->payload_ = internal::FromValue<std::string>::Parse(*payload_value, errors);
  } else {
    errors->AddError("required property missing: payload");
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  } else {
    errors->AddError("required property missing: executionContextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> BindingCalledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("payload", internal::ToValue(payload_));
  result->Set("executionContextId", internal::ToValue(execution_context_id_));
  return std::move(result);
}

std::unique_ptr<BindingCalledParams> BindingCalledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<BindingCalledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ConsoleAPICalledParams> ConsoleAPICalledParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ConsoleAPICalledParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ConsoleAPICalledParams> result(new ConsoleAPICalledParams());
  errors->Push();
  errors->SetName("ConsoleAPICalledParams");
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::runtime::ConsoleAPICalledType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  const base::Value* args_value = value.FindKey("args");
  if (args_value) {
    errors->SetName("args");
    result->args_ = internal::FromValue<std::vector<std::unique_ptr<::headless::runtime::RemoteObject>>>::Parse(*args_value, errors);
  } else {
    errors->AddError("required property missing: args");
  }
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  } else {
    errors->AddError("required property missing: executionContextId");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* stack_trace_value = value.FindKey("stackTrace");
  if (stack_trace_value) {
    errors->SetName("stackTrace");
    result->stack_trace_ = internal::FromValue<::headless::runtime::StackTrace>::Parse(*stack_trace_value, errors);
  }
  const base::Value* context_value = value.FindKey("context");
  if (context_value) {
    errors->SetName("context");
    result->context_ = internal::FromValue<std::string>::Parse(*context_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ConsoleAPICalledParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("type", internal::ToValue(type_));
  result->Set("args", internal::ToValue(args_));
  result->Set("executionContextId", internal::ToValue(execution_context_id_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  if (stack_trace_)
    result->Set("stackTrace", internal::ToValue(*stack_trace_.value()));
  if (context_)
    result->Set("context", internal::ToValue(context_.value()));
  return std::move(result);
}

std::unique_ptr<ConsoleAPICalledParams> ConsoleAPICalledParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ConsoleAPICalledParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExceptionRevokedParams> ExceptionRevokedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExceptionRevokedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExceptionRevokedParams> result(new ExceptionRevokedParams());
  errors->Push();
  errors->SetName("ExceptionRevokedParams");
  const base::Value* reason_value = value.FindKey("reason");
  if (reason_value) {
    errors->SetName("reason");
    result->reason_ = internal::FromValue<std::string>::Parse(*reason_value, errors);
  } else {
    errors->AddError("required property missing: reason");
  }
  const base::Value* exception_id_value = value.FindKey("exceptionId");
  if (exception_id_value) {
    errors->SetName("exceptionId");
    result->exception_id_ = internal::FromValue<int>::Parse(*exception_id_value, errors);
  } else {
    errors->AddError("required property missing: exceptionId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExceptionRevokedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("reason", internal::ToValue(reason_));
  result->Set("exceptionId", internal::ToValue(exception_id_));
  return std::move(result);
}

std::unique_ptr<ExceptionRevokedParams> ExceptionRevokedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExceptionRevokedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExceptionThrownParams> ExceptionThrownParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExceptionThrownParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExceptionThrownParams> result(new ExceptionThrownParams());
  errors->Push();
  errors->SetName("ExceptionThrownParams");
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  const base::Value* exception_details_value = value.FindKey("exceptionDetails");
  if (exception_details_value) {
    errors->SetName("exceptionDetails");
    result->exception_details_ = internal::FromValue<::headless::runtime::ExceptionDetails>::Parse(*exception_details_value, errors);
  } else {
    errors->AddError("required property missing: exceptionDetails");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExceptionThrownParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timestamp", internal::ToValue(timestamp_));
  result->Set("exceptionDetails", internal::ToValue(*exception_details_));
  return std::move(result);
}

std::unique_ptr<ExceptionThrownParams> ExceptionThrownParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExceptionThrownParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExecutionContextCreatedParams> ExecutionContextCreatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExecutionContextCreatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExecutionContextCreatedParams> result(new ExecutionContextCreatedParams());
  errors->Push();
  errors->SetName("ExecutionContextCreatedParams");
  const base::Value* context_value = value.FindKey("context");
  if (context_value) {
    errors->SetName("context");
    result->context_ = internal::FromValue<::headless::runtime::ExecutionContextDescription>::Parse(*context_value, errors);
  } else {
    errors->AddError("required property missing: context");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExecutionContextCreatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("context", internal::ToValue(*context_));
  return std::move(result);
}

std::unique_ptr<ExecutionContextCreatedParams> ExecutionContextCreatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExecutionContextCreatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExecutionContextDestroyedParams> ExecutionContextDestroyedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExecutionContextDestroyedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExecutionContextDestroyedParams> result(new ExecutionContextDestroyedParams());
  errors->Push();
  errors->SetName("ExecutionContextDestroyedParams");
  const base::Value* execution_context_id_value = value.FindKey("executionContextId");
  if (execution_context_id_value) {
    errors->SetName("executionContextId");
    result->execution_context_id_ = internal::FromValue<int>::Parse(*execution_context_id_value, errors);
  } else {
    errors->AddError("required property missing: executionContextId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExecutionContextDestroyedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("executionContextId", internal::ToValue(execution_context_id_));
  return std::move(result);
}

std::unique_ptr<ExecutionContextDestroyedParams> ExecutionContextDestroyedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExecutionContextDestroyedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ExecutionContextsClearedParams> ExecutionContextsClearedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ExecutionContextsClearedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ExecutionContextsClearedParams> result(new ExecutionContextsClearedParams());
  errors->Push();
  errors->SetName("ExecutionContextsClearedParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ExecutionContextsClearedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ExecutionContextsClearedParams> ExecutionContextsClearedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ExecutionContextsClearedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InspectRequestedParams> InspectRequestedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InspectRequestedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InspectRequestedParams> result(new InspectRequestedParams());
  errors->Push();
  errors->SetName("InspectRequestedParams");
  const base::Value* object_value = value.FindKey("object");
  if (object_value) {
    errors->SetName("object");
    result->object_ = internal::FromValue<::headless::runtime::RemoteObject>::Parse(*object_value, errors);
  } else {
    errors->AddError("required property missing: object");
  }
  const base::Value* hints_value = value.FindKey("hints");
  if (hints_value) {
    errors->SetName("hints");
    result->hints_ = internal::FromValue<base::Value>::Parse(*hints_value, errors);
  } else {
    errors->AddError("required property missing: hints");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InspectRequestedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("object", internal::ToValue(*object_));
  result->Set("hints", internal::ToValue(*hints_));
  return std::move(result);
}

std::unique_ptr<InspectRequestedParams> InspectRequestedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InspectRequestedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace runtime
}  // namespace headless
