// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_RUNTIME_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_RUNTIME_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace runtime {

// Mirror object referencing original JavaScript object.
class HEADLESS_EXPORT RemoteObject {
 public:
  static std::unique_ptr<RemoteObject> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoteObject() { }

  // Object type.
  ::headless::runtime::RemoteObjectType GetType() const { return type_; }
  void SetType(::headless::runtime::RemoteObjectType value) { type_ = value; }

  // Object subtype hint. Specified for `object` or `wasm` type values only.
  bool HasSubtype() const { return !!subtype_; }
  ::headless::runtime::RemoteObjectSubtype GetSubtype() const { DCHECK(HasSubtype()); return subtype_.value(); }
  void SetSubtype(::headless::runtime::RemoteObjectSubtype value) { subtype_ = value; }

  // Object class (constructor) name. Specified for `object` type values only.
  bool HasClassName() const { return !!class_name_; }
  std::string GetClassName() const { DCHECK(HasClassName()); return class_name_.value(); }
  void SetClassName(const std::string& value) { class_name_ = value; }

  // Remote object value in case of primitive values or JSON values (if it was requested).
  bool HasValue() const { return !!value_; }
  const base::Value* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<base::Value> value) { value_ = std::move(value); }

  // Primitive value which can not be JSON-stringified does not have `value`, but gets this
  // property.
  bool HasUnserializableValue() const { return !!unserializable_value_; }
  std::string GetUnserializableValue() const { DCHECK(HasUnserializableValue()); return unserializable_value_.value(); }
  void SetUnserializableValue(const std::string& value) { unserializable_value_ = value; }

  // String representation of the object.
  bool HasDescription() const { return !!description_; }
  std::string GetDescription() const { DCHECK(HasDescription()); return description_.value(); }
  void SetDescription(const std::string& value) { description_ = value; }

  // Unique object identifier (for non-primitive values).
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  // Preview containing abbreviated property values. Specified for `object` type values only.
  bool HasPreview() const { return !!preview_; }
  const ::headless::runtime::ObjectPreview* GetPreview() const { DCHECK(HasPreview()); return preview_.value().get(); }
  void SetPreview(std::unique_ptr<::headless::runtime::ObjectPreview> value) { preview_ = std::move(value); }

  bool HasCustomPreview() const { return !!custom_preview_; }
  const ::headless::runtime::CustomPreview* GetCustomPreview() const { DCHECK(HasCustomPreview()); return custom_preview_.value().get(); }
  void SetCustomPreview(std::unique_ptr<::headless::runtime::CustomPreview> value) { custom_preview_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoteObject> Clone() const;

  template<int STATE>
  class RemoteObjectBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    RemoteObjectBuilder<STATE | kTypeSet>& SetType(::headless::runtime::RemoteObjectType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    RemoteObjectBuilder<STATE>& SetSubtype(::headless::runtime::RemoteObjectSubtype value) {
      result_->SetSubtype(value);
      return *this;
    }

    RemoteObjectBuilder<STATE>& SetClassName(const std::string& value) {
      result_->SetClassName(value);
      return *this;
    }

    RemoteObjectBuilder<STATE>& SetValue(std::unique_ptr<base::Value> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    RemoteObjectBuilder<STATE>& SetUnserializableValue(const std::string& value) {
      result_->SetUnserializableValue(value);
      return *this;
    }

    RemoteObjectBuilder<STATE>& SetDescription(const std::string& value) {
      result_->SetDescription(value);
      return *this;
    }

    RemoteObjectBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    RemoteObjectBuilder<STATE>& SetPreview(std::unique_ptr<::headless::runtime::ObjectPreview> value) {
      result_->SetPreview(std::move(value));
      return *this;
    }

    RemoteObjectBuilder<STATE>& SetCustomPreview(std::unique_ptr<::headless::runtime::CustomPreview> value) {
      result_->SetCustomPreview(std::move(value));
      return *this;
    }

    std::unique_ptr<RemoteObject> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoteObject;
    RemoteObjectBuilder() : result_(new RemoteObject()) { }

    template<int STEP> RemoteObjectBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoteObjectBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoteObject> result_;
  };

  static RemoteObjectBuilder<0> Builder() {
    return RemoteObjectBuilder<0>();
  }

 private:
  RemoteObject() { }

  ::headless::runtime::RemoteObjectType type_;
  base::Optional<::headless::runtime::RemoteObjectSubtype> subtype_;
  base::Optional<std::string> class_name_;
  base::Optional<std::unique_ptr<base::Value>> value_;
  base::Optional<std::string> unserializable_value_;
  base::Optional<std::string> description_;
  base::Optional<std::string> object_id_;
  base::Optional<std::unique_ptr<::headless::runtime::ObjectPreview>> preview_;
  base::Optional<std::unique_ptr<::headless::runtime::CustomPreview>> custom_preview_;

  DISALLOW_COPY_AND_ASSIGN(RemoteObject);
};


class HEADLESS_EXPORT CustomPreview {
 public:
  static std::unique_ptr<CustomPreview> Parse(const base::Value& value, ErrorReporter* errors);
  ~CustomPreview() { }

  // The JSON-stringified result of formatter.header(object, config) call.
  // It contains json ML array that represents RemoteObject.
  std::string GetHeader() const { return header_; }
  void SetHeader(const std::string& value) { header_ = value; }

  // If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
  // contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
  // The result value is json ML array.
  bool HasBodyGetterId() const { return !!body_getter_id_; }
  std::string GetBodyGetterId() const { DCHECK(HasBodyGetterId()); return body_getter_id_.value(); }
  void SetBodyGetterId(const std::string& value) { body_getter_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CustomPreview> Clone() const;

  template<int STATE>
  class CustomPreviewBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kHeaderSet = 1 << 1,
      kAllRequiredFieldsSet = (kHeaderSet | 0)
    };

    CustomPreviewBuilder<STATE | kHeaderSet>& SetHeader(const std::string& value) {
      static_assert(!(STATE & kHeaderSet), "property header should not have already been set");
      result_->SetHeader(value);
      return CastState<kHeaderSet>();
    }

    CustomPreviewBuilder<STATE>& SetBodyGetterId(const std::string& value) {
      result_->SetBodyGetterId(value);
      return *this;
    }

    std::unique_ptr<CustomPreview> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CustomPreview;
    CustomPreviewBuilder() : result_(new CustomPreview()) { }

    template<int STEP> CustomPreviewBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CustomPreviewBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CustomPreview> result_;
  };

  static CustomPreviewBuilder<0> Builder() {
    return CustomPreviewBuilder<0>();
  }

 private:
  CustomPreview() { }

  std::string header_;
  base::Optional<std::string> body_getter_id_;

  DISALLOW_COPY_AND_ASSIGN(CustomPreview);
};


// Object containing abbreviated remote object value.
class HEADLESS_EXPORT ObjectPreview {
 public:
  static std::unique_ptr<ObjectPreview> Parse(const base::Value& value, ErrorReporter* errors);
  ~ObjectPreview() { }

  // Object type.
  ::headless::runtime::ObjectPreviewType GetType() const { return type_; }
  void SetType(::headless::runtime::ObjectPreviewType value) { type_ = value; }

  // Object subtype hint. Specified for `object` type values only.
  bool HasSubtype() const { return !!subtype_; }
  ::headless::runtime::ObjectPreviewSubtype GetSubtype() const { DCHECK(HasSubtype()); return subtype_.value(); }
  void SetSubtype(::headless::runtime::ObjectPreviewSubtype value) { subtype_ = value; }

  // String representation of the object.
  bool HasDescription() const { return !!description_; }
  std::string GetDescription() const { DCHECK(HasDescription()); return description_.value(); }
  void SetDescription(const std::string& value) { description_ = value; }

  // True iff some of the properties or entries of the original object did not fit.
  bool GetOverflow() const { return overflow_; }
  void SetOverflow(bool value) { overflow_ = value; }

  // List of the properties.
  const std::vector<std::unique_ptr<::headless::runtime::PropertyPreview>>* GetProperties() const { return &properties_; }
  void SetProperties(std::vector<std::unique_ptr<::headless::runtime::PropertyPreview>> value) { properties_ = std::move(value); }

  // List of the entries. Specified for `map` and `set` subtype values only.
  bool HasEntries() const { return !!entries_; }
  const std::vector<std::unique_ptr<::headless::runtime::EntryPreview>>* GetEntries() const { DCHECK(HasEntries()); return &entries_.value(); }
  void SetEntries(std::vector<std::unique_ptr<::headless::runtime::EntryPreview>> value) { entries_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ObjectPreview> Clone() const;

  template<int STATE>
  class ObjectPreviewBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kOverflowSet = 1 << 2,
    kPropertiesSet = 1 << 3,
      kAllRequiredFieldsSet = (kTypeSet | kOverflowSet | kPropertiesSet | 0)
    };

    ObjectPreviewBuilder<STATE | kTypeSet>& SetType(::headless::runtime::ObjectPreviewType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    ObjectPreviewBuilder<STATE>& SetSubtype(::headless::runtime::ObjectPreviewSubtype value) {
      result_->SetSubtype(value);
      return *this;
    }

    ObjectPreviewBuilder<STATE>& SetDescription(const std::string& value) {
      result_->SetDescription(value);
      return *this;
    }

    ObjectPreviewBuilder<STATE | kOverflowSet>& SetOverflow(bool value) {
      static_assert(!(STATE & kOverflowSet), "property overflow should not have already been set");
      result_->SetOverflow(value);
      return CastState<kOverflowSet>();
    }

    ObjectPreviewBuilder<STATE | kPropertiesSet>& SetProperties(std::vector<std::unique_ptr<::headless::runtime::PropertyPreview>> value) {
      static_assert(!(STATE & kPropertiesSet), "property properties should not have already been set");
      result_->SetProperties(std::move(value));
      return CastState<kPropertiesSet>();
    }

    ObjectPreviewBuilder<STATE>& SetEntries(std::vector<std::unique_ptr<::headless::runtime::EntryPreview>> value) {
      result_->SetEntries(std::move(value));
      return *this;
    }

    std::unique_ptr<ObjectPreview> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ObjectPreview;
    ObjectPreviewBuilder() : result_(new ObjectPreview()) { }

    template<int STEP> ObjectPreviewBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ObjectPreviewBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ObjectPreview> result_;
  };

  static ObjectPreviewBuilder<0> Builder() {
    return ObjectPreviewBuilder<0>();
  }

 private:
  ObjectPreview() { }

  ::headless::runtime::ObjectPreviewType type_;
  base::Optional<::headless::runtime::ObjectPreviewSubtype> subtype_;
  base::Optional<std::string> description_;
  bool overflow_;
  std::vector<std::unique_ptr<::headless::runtime::PropertyPreview>> properties_;
  base::Optional<std::vector<std::unique_ptr<::headless::runtime::EntryPreview>>> entries_;

  DISALLOW_COPY_AND_ASSIGN(ObjectPreview);
};


class HEADLESS_EXPORT PropertyPreview {
 public:
  static std::unique_ptr<PropertyPreview> Parse(const base::Value& value, ErrorReporter* errors);
  ~PropertyPreview() { }

  // Property name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Object type. Accessor means that the property itself is an accessor property.
  ::headless::runtime::PropertyPreviewType GetType() const { return type_; }
  void SetType(::headless::runtime::PropertyPreviewType value) { type_ = value; }

  // User-friendly property value string.
  bool HasValue() const { return !!value_; }
  std::string GetValue() const { DCHECK(HasValue()); return value_.value(); }
  void SetValue(const std::string& value) { value_ = value; }

  // Nested value preview.
  bool HasValuePreview() const { return !!value_preview_; }
  const ::headless::runtime::ObjectPreview* GetValuePreview() const { DCHECK(HasValuePreview()); return value_preview_.value().get(); }
  void SetValuePreview(std::unique_ptr<::headless::runtime::ObjectPreview> value) { value_preview_ = std::move(value); }

  // Object subtype hint. Specified for `object` type values only.
  bool HasSubtype() const { return !!subtype_; }
  ::headless::runtime::PropertyPreviewSubtype GetSubtype() const { DCHECK(HasSubtype()); return subtype_.value(); }
  void SetSubtype(::headless::runtime::PropertyPreviewSubtype value) { subtype_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PropertyPreview> Clone() const;

  template<int STATE>
  class PropertyPreviewBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kTypeSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kTypeSet | 0)
    };

    PropertyPreviewBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    PropertyPreviewBuilder<STATE | kTypeSet>& SetType(::headless::runtime::PropertyPreviewType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    PropertyPreviewBuilder<STATE>& SetValue(const std::string& value) {
      result_->SetValue(value);
      return *this;
    }

    PropertyPreviewBuilder<STATE>& SetValuePreview(std::unique_ptr<::headless::runtime::ObjectPreview> value) {
      result_->SetValuePreview(std::move(value));
      return *this;
    }

    PropertyPreviewBuilder<STATE>& SetSubtype(::headless::runtime::PropertyPreviewSubtype value) {
      result_->SetSubtype(value);
      return *this;
    }

    std::unique_ptr<PropertyPreview> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PropertyPreview;
    PropertyPreviewBuilder() : result_(new PropertyPreview()) { }

    template<int STEP> PropertyPreviewBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PropertyPreviewBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PropertyPreview> result_;
  };

  static PropertyPreviewBuilder<0> Builder() {
    return PropertyPreviewBuilder<0>();
  }

 private:
  PropertyPreview() { }

  std::string name_;
  ::headless::runtime::PropertyPreviewType type_;
  base::Optional<std::string> value_;
  base::Optional<std::unique_ptr<::headless::runtime::ObjectPreview>> value_preview_;
  base::Optional<::headless::runtime::PropertyPreviewSubtype> subtype_;

  DISALLOW_COPY_AND_ASSIGN(PropertyPreview);
};


class HEADLESS_EXPORT EntryPreview {
 public:
  static std::unique_ptr<EntryPreview> Parse(const base::Value& value, ErrorReporter* errors);
  ~EntryPreview() { }

  // Preview of the key. Specified for map-like collection entries.
  bool HasKey() const { return !!key_; }
  const ::headless::runtime::ObjectPreview* GetKey() const { DCHECK(HasKey()); return key_.value().get(); }
  void SetKey(std::unique_ptr<::headless::runtime::ObjectPreview> value) { key_ = std::move(value); }

  // Preview of the value.
  const ::headless::runtime::ObjectPreview* GetValue() const { return value_.get(); }
  void SetValue(std::unique_ptr<::headless::runtime::ObjectPreview> value) { value_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EntryPreview> Clone() const;

  template<int STATE>
  class EntryPreviewBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kValueSet = 1 << 1,
      kAllRequiredFieldsSet = (kValueSet | 0)
    };

    EntryPreviewBuilder<STATE>& SetKey(std::unique_ptr<::headless::runtime::ObjectPreview> value) {
      result_->SetKey(std::move(value));
      return *this;
    }

    EntryPreviewBuilder<STATE | kValueSet>& SetValue(std::unique_ptr<::headless::runtime::ObjectPreview> value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(std::move(value));
      return CastState<kValueSet>();
    }

    std::unique_ptr<EntryPreview> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EntryPreview;
    EntryPreviewBuilder() : result_(new EntryPreview()) { }

    template<int STEP> EntryPreviewBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EntryPreviewBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EntryPreview> result_;
  };

  static EntryPreviewBuilder<0> Builder() {
    return EntryPreviewBuilder<0>();
  }

 private:
  EntryPreview() { }

  base::Optional<std::unique_ptr<::headless::runtime::ObjectPreview>> key_;
  std::unique_ptr<::headless::runtime::ObjectPreview> value_;

  DISALLOW_COPY_AND_ASSIGN(EntryPreview);
};


// Object property descriptor.
class HEADLESS_EXPORT PropertyDescriptor {
 public:
  static std::unique_ptr<PropertyDescriptor> Parse(const base::Value& value, ErrorReporter* errors);
  ~PropertyDescriptor() { }

  // Property name or symbol description.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // The value associated with the property.
  bool HasValue() const { return !!value_; }
  const ::headless::runtime::RemoteObject* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) { value_ = std::move(value); }

  // True if the value associated with the property may be changed (data descriptors only).
  bool HasWritable() const { return !!writable_; }
  bool GetWritable() const { DCHECK(HasWritable()); return writable_.value(); }
  void SetWritable(bool value) { writable_ = value; }

  // A function which serves as a getter for the property, or `undefined` if there is no getter
  // (accessor descriptors only).
  bool HasGet() const { return !!get_; }
  const ::headless::runtime::RemoteObject* GetGet() const { DCHECK(HasGet()); return get_.value().get(); }
  void SetGet(std::unique_ptr<::headless::runtime::RemoteObject> value) { get_ = std::move(value); }

  // A function which serves as a setter for the property, or `undefined` if there is no setter
  // (accessor descriptors only).
  bool HasSet() const { return !!set_; }
  const ::headless::runtime::RemoteObject* GetSet() const { DCHECK(HasSet()); return set_.value().get(); }
  void SetSet(std::unique_ptr<::headless::runtime::RemoteObject> value) { set_ = std::move(value); }

  // True if the type of this property descriptor may be changed and if the property may be
  // deleted from the corresponding object.
  bool GetConfigurable() const { return configurable_; }
  void SetConfigurable(bool value) { configurable_ = value; }

  // True if this property shows up during enumeration of the properties on the corresponding
  // object.
  bool GetEnumerable() const { return enumerable_; }
  void SetEnumerable(bool value) { enumerable_ = value; }

  // True if the result was thrown during the evaluation.
  bool HasWasThrown() const { return !!was_thrown_; }
  bool GetWasThrown() const { DCHECK(HasWasThrown()); return was_thrown_.value(); }
  void SetWasThrown(bool value) { was_thrown_ = value; }

  // True if the property is owned for the object.
  bool HasIsOwn() const { return !!is_own_; }
  bool GetIsOwn() const { DCHECK(HasIsOwn()); return is_own_.value(); }
  void SetIsOwn(bool value) { is_own_ = value; }

  // Property symbol object, if the property is of the `symbol` type.
  bool HasSymbol() const { return !!symbol_; }
  const ::headless::runtime::RemoteObject* GetSymbol() const { DCHECK(HasSymbol()); return symbol_.value().get(); }
  void SetSymbol(std::unique_ptr<::headless::runtime::RemoteObject> value) { symbol_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PropertyDescriptor> Clone() const;

  template<int STATE>
  class PropertyDescriptorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kConfigurableSet = 1 << 2,
    kEnumerableSet = 1 << 3,
      kAllRequiredFieldsSet = (kNameSet | kConfigurableSet | kEnumerableSet | 0)
    };

    PropertyDescriptorBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    PropertyDescriptorBuilder<STATE>& SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    PropertyDescriptorBuilder<STATE>& SetWritable(bool value) {
      result_->SetWritable(value);
      return *this;
    }

    PropertyDescriptorBuilder<STATE>& SetGet(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetGet(std::move(value));
      return *this;
    }

    PropertyDescriptorBuilder<STATE>& SetSet(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetSet(std::move(value));
      return *this;
    }

    PropertyDescriptorBuilder<STATE | kConfigurableSet>& SetConfigurable(bool value) {
      static_assert(!(STATE & kConfigurableSet), "property configurable should not have already been set");
      result_->SetConfigurable(value);
      return CastState<kConfigurableSet>();
    }

    PropertyDescriptorBuilder<STATE | kEnumerableSet>& SetEnumerable(bool value) {
      static_assert(!(STATE & kEnumerableSet), "property enumerable should not have already been set");
      result_->SetEnumerable(value);
      return CastState<kEnumerableSet>();
    }

    PropertyDescriptorBuilder<STATE>& SetWasThrown(bool value) {
      result_->SetWasThrown(value);
      return *this;
    }

    PropertyDescriptorBuilder<STATE>& SetIsOwn(bool value) {
      result_->SetIsOwn(value);
      return *this;
    }

    PropertyDescriptorBuilder<STATE>& SetSymbol(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetSymbol(std::move(value));
      return *this;
    }

    std::unique_ptr<PropertyDescriptor> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PropertyDescriptor;
    PropertyDescriptorBuilder() : result_(new PropertyDescriptor()) { }

    template<int STEP> PropertyDescriptorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PropertyDescriptorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PropertyDescriptor> result_;
  };

  static PropertyDescriptorBuilder<0> Builder() {
    return PropertyDescriptorBuilder<0>();
  }

 private:
  PropertyDescriptor() { }

  std::string name_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> value_;
  base::Optional<bool> writable_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> get_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> set_;
  bool configurable_;
  bool enumerable_;
  base::Optional<bool> was_thrown_;
  base::Optional<bool> is_own_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> symbol_;

  DISALLOW_COPY_AND_ASSIGN(PropertyDescriptor);
};


// Object internal property descriptor. This property isn't normally visible in JavaScript code.
class HEADLESS_EXPORT InternalPropertyDescriptor {
 public:
  static std::unique_ptr<InternalPropertyDescriptor> Parse(const base::Value& value, ErrorReporter* errors);
  ~InternalPropertyDescriptor() { }

  // Conventional property name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // The value associated with the property.
  bool HasValue() const { return !!value_; }
  const ::headless::runtime::RemoteObject* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) { value_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InternalPropertyDescriptor> Clone() const;

  template<int STATE>
  class InternalPropertyDescriptorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
      kAllRequiredFieldsSet = (kNameSet | 0)
    };

    InternalPropertyDescriptorBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    InternalPropertyDescriptorBuilder<STATE>& SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    std::unique_ptr<InternalPropertyDescriptor> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InternalPropertyDescriptor;
    InternalPropertyDescriptorBuilder() : result_(new InternalPropertyDescriptor()) { }

    template<int STEP> InternalPropertyDescriptorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InternalPropertyDescriptorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InternalPropertyDescriptor> result_;
  };

  static InternalPropertyDescriptorBuilder<0> Builder() {
    return InternalPropertyDescriptorBuilder<0>();
  }

 private:
  InternalPropertyDescriptor() { }

  std::string name_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> value_;

  DISALLOW_COPY_AND_ASSIGN(InternalPropertyDescriptor);
};


// Object private field descriptor.
class HEADLESS_EXPORT PrivatePropertyDescriptor {
 public:
  static std::unique_ptr<PrivatePropertyDescriptor> Parse(const base::Value& value, ErrorReporter* errors);
  ~PrivatePropertyDescriptor() { }

  // Private property name.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // The value associated with the private property.
  bool HasValue() const { return !!value_; }
  const ::headless::runtime::RemoteObject* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) { value_ = std::move(value); }

  // A function which serves as a getter for the private property,
  // or `undefined` if there is no getter (accessor descriptors only).
  bool HasGet() const { return !!get_; }
  const ::headless::runtime::RemoteObject* GetGet() const { DCHECK(HasGet()); return get_.value().get(); }
  void SetGet(std::unique_ptr<::headless::runtime::RemoteObject> value) { get_ = std::move(value); }

  // A function which serves as a setter for the private property,
  // or `undefined` if there is no setter (accessor descriptors only).
  bool HasSet() const { return !!set_; }
  const ::headless::runtime::RemoteObject* GetSet() const { DCHECK(HasSet()); return set_.value().get(); }
  void SetSet(std::unique_ptr<::headless::runtime::RemoteObject> value) { set_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PrivatePropertyDescriptor> Clone() const;

  template<int STATE>
  class PrivatePropertyDescriptorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
      kAllRequiredFieldsSet = (kNameSet | 0)
    };

    PrivatePropertyDescriptorBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    PrivatePropertyDescriptorBuilder<STATE>& SetValue(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    PrivatePropertyDescriptorBuilder<STATE>& SetGet(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetGet(std::move(value));
      return *this;
    }

    PrivatePropertyDescriptorBuilder<STATE>& SetSet(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetSet(std::move(value));
      return *this;
    }

    std::unique_ptr<PrivatePropertyDescriptor> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PrivatePropertyDescriptor;
    PrivatePropertyDescriptorBuilder() : result_(new PrivatePropertyDescriptor()) { }

    template<int STEP> PrivatePropertyDescriptorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PrivatePropertyDescriptorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PrivatePropertyDescriptor> result_;
  };

  static PrivatePropertyDescriptorBuilder<0> Builder() {
    return PrivatePropertyDescriptorBuilder<0>();
  }

 private:
  PrivatePropertyDescriptor() { }

  std::string name_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> value_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> get_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> set_;

  DISALLOW_COPY_AND_ASSIGN(PrivatePropertyDescriptor);
};


// Represents function call argument. Either remote object id `objectId`, primitive `value`,
// unserializable primitive value or neither of (for undefined) them should be specified.
class HEADLESS_EXPORT CallArgument {
 public:
  static std::unique_ptr<CallArgument> Parse(const base::Value& value, ErrorReporter* errors);
  ~CallArgument() { }

  // Primitive value or serializable javascript object.
  bool HasValue() const { return !!value_; }
  const base::Value* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<base::Value> value) { value_ = std::move(value); }

  // Primitive value which can not be JSON-stringified.
  bool HasUnserializableValue() const { return !!unserializable_value_; }
  std::string GetUnserializableValue() const { DCHECK(HasUnserializableValue()); return unserializable_value_.value(); }
  void SetUnserializableValue(const std::string& value) { unserializable_value_ = value; }

  // Remote object handle.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CallArgument> Clone() const;

  template<int STATE>
  class CallArgumentBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    CallArgumentBuilder<STATE>& SetValue(std::unique_ptr<base::Value> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    CallArgumentBuilder<STATE>& SetUnserializableValue(const std::string& value) {
      result_->SetUnserializableValue(value);
      return *this;
    }

    CallArgumentBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    std::unique_ptr<CallArgument> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CallArgument;
    CallArgumentBuilder() : result_(new CallArgument()) { }

    template<int STEP> CallArgumentBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CallArgumentBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CallArgument> result_;
  };

  static CallArgumentBuilder<0> Builder() {
    return CallArgumentBuilder<0>();
  }

 private:
  CallArgument() { }

  base::Optional<std::unique_ptr<base::Value>> value_;
  base::Optional<std::string> unserializable_value_;
  base::Optional<std::string> object_id_;

  DISALLOW_COPY_AND_ASSIGN(CallArgument);
};


// Description of an isolated world.
class HEADLESS_EXPORT ExecutionContextDescription {
 public:
  static std::unique_ptr<ExecutionContextDescription> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExecutionContextDescription() { }

  // Unique id of the execution context. It can be used to specify in which execution context
  // script evaluation should be performed.
  int GetId() const { return id_; }
  void SetId(int value) { id_ = value; }

  // Execution context origin.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  // Human readable name describing given context.
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Embedder-specific auxiliary data.
  bool HasAuxData() const { return !!aux_data_; }
  const base::Value* GetAuxData() const { DCHECK(HasAuxData()); return aux_data_.value().get(); }
  void SetAuxData(std::unique_ptr<base::Value> value) { aux_data_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExecutionContextDescription> Clone() const;

  template<int STATE>
  class ExecutionContextDescriptionBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kOriginSet = 1 << 2,
    kNameSet = 1 << 3,
      kAllRequiredFieldsSet = (kIdSet | kOriginSet | kNameSet | 0)
    };

    ExecutionContextDescriptionBuilder<STATE | kIdSet>& SetId(int value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    ExecutionContextDescriptionBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    ExecutionContextDescriptionBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    ExecutionContextDescriptionBuilder<STATE>& SetAuxData(std::unique_ptr<base::Value> value) {
      result_->SetAuxData(std::move(value));
      return *this;
    }

    std::unique_ptr<ExecutionContextDescription> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExecutionContextDescription;
    ExecutionContextDescriptionBuilder() : result_(new ExecutionContextDescription()) { }

    template<int STEP> ExecutionContextDescriptionBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExecutionContextDescriptionBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExecutionContextDescription> result_;
  };

  static ExecutionContextDescriptionBuilder<0> Builder() {
    return ExecutionContextDescriptionBuilder<0>();
  }

 private:
  ExecutionContextDescription() { }

  int id_;
  std::string origin_;
  std::string name_;
  base::Optional<std::unique_ptr<base::Value>> aux_data_;

  DISALLOW_COPY_AND_ASSIGN(ExecutionContextDescription);
};


// Detailed information about exception (or error) that was thrown during script compilation or
// execution.
class HEADLESS_EXPORT ExceptionDetails {
 public:
  static std::unique_ptr<ExceptionDetails> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExceptionDetails() { }

  // Exception id.
  int GetExceptionId() const { return exception_id_; }
  void SetExceptionId(int value) { exception_id_ = value; }

  // Exception text, which should be used together with exception object when available.
  std::string GetText() const { return text_; }
  void SetText(const std::string& value) { text_ = value; }

  // Line number of the exception location (0-based).
  int GetLineNumber() const { return line_number_; }
  void SetLineNumber(int value) { line_number_ = value; }

  // Column number of the exception location (0-based).
  int GetColumnNumber() const { return column_number_; }
  void SetColumnNumber(int value) { column_number_ = value; }

  // Script ID of the exception location.
  bool HasScriptId() const { return !!script_id_; }
  std::string GetScriptId() const { DCHECK(HasScriptId()); return script_id_.value(); }
  void SetScriptId(const std::string& value) { script_id_ = value; }

  // URL of the exception location, to be used when the script was not reported.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // JavaScript stack trace if available.
  bool HasStackTrace() const { return !!stack_trace_; }
  const ::headless::runtime::StackTrace* GetStackTrace() const { DCHECK(HasStackTrace()); return stack_trace_.value().get(); }
  void SetStackTrace(std::unique_ptr<::headless::runtime::StackTrace> value) { stack_trace_ = std::move(value); }

  // Exception object if available.
  bool HasException() const { return !!exception_; }
  const ::headless::runtime::RemoteObject* GetException() const { DCHECK(HasException()); return exception_.value().get(); }
  void SetException(std::unique_ptr<::headless::runtime::RemoteObject> value) { exception_ = std::move(value); }

  // Identifier of the context where exception happened.
  bool HasExecutionContextId() const { return !!execution_context_id_; }
  int GetExecutionContextId() const { DCHECK(HasExecutionContextId()); return execution_context_id_.value(); }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExceptionDetails> Clone() const;

  template<int STATE>
  class ExceptionDetailsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kExceptionIdSet = 1 << 1,
    kTextSet = 1 << 2,
    kLineNumberSet = 1 << 3,
    kColumnNumberSet = 1 << 4,
      kAllRequiredFieldsSet = (kExceptionIdSet | kTextSet | kLineNumberSet | kColumnNumberSet | 0)
    };

    ExceptionDetailsBuilder<STATE | kExceptionIdSet>& SetExceptionId(int value) {
      static_assert(!(STATE & kExceptionIdSet), "property exceptionId should not have already been set");
      result_->SetExceptionId(value);
      return CastState<kExceptionIdSet>();
    }

    ExceptionDetailsBuilder<STATE | kTextSet>& SetText(const std::string& value) {
      static_assert(!(STATE & kTextSet), "property text should not have already been set");
      result_->SetText(value);
      return CastState<kTextSet>();
    }

    ExceptionDetailsBuilder<STATE | kLineNumberSet>& SetLineNumber(int value) {
      static_assert(!(STATE & kLineNumberSet), "property lineNumber should not have already been set");
      result_->SetLineNumber(value);
      return CastState<kLineNumberSet>();
    }

    ExceptionDetailsBuilder<STATE | kColumnNumberSet>& SetColumnNumber(int value) {
      static_assert(!(STATE & kColumnNumberSet), "property columnNumber should not have already been set");
      result_->SetColumnNumber(value);
      return CastState<kColumnNumberSet>();
    }

    ExceptionDetailsBuilder<STATE>& SetScriptId(const std::string& value) {
      result_->SetScriptId(value);
      return *this;
    }

    ExceptionDetailsBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    ExceptionDetailsBuilder<STATE>& SetStackTrace(std::unique_ptr<::headless::runtime::StackTrace> value) {
      result_->SetStackTrace(std::move(value));
      return *this;
    }

    ExceptionDetailsBuilder<STATE>& SetException(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      result_->SetException(std::move(value));
      return *this;
    }

    ExceptionDetailsBuilder<STATE>& SetExecutionContextId(int value) {
      result_->SetExecutionContextId(value);
      return *this;
    }

    std::unique_ptr<ExceptionDetails> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExceptionDetails;
    ExceptionDetailsBuilder() : result_(new ExceptionDetails()) { }

    template<int STEP> ExceptionDetailsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExceptionDetailsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExceptionDetails> result_;
  };

  static ExceptionDetailsBuilder<0> Builder() {
    return ExceptionDetailsBuilder<0>();
  }

 private:
  ExceptionDetails() { }

  int exception_id_;
  std::string text_;
  int line_number_;
  int column_number_;
  base::Optional<std::string> script_id_;
  base::Optional<std::string> url_;
  base::Optional<std::unique_ptr<::headless::runtime::StackTrace>> stack_trace_;
  base::Optional<std::unique_ptr<::headless::runtime::RemoteObject>> exception_;
  base::Optional<int> execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(ExceptionDetails);
};


// Stack entry for runtime errors and assertions.
class HEADLESS_EXPORT CallFrame {
 public:
  static std::unique_ptr<CallFrame> Parse(const base::Value& value, ErrorReporter* errors);
  ~CallFrame() { }

  // JavaScript function name.
  std::string GetFunctionName() const { return function_name_; }
  void SetFunctionName(const std::string& value) { function_name_ = value; }

  // JavaScript script id.
  std::string GetScriptId() const { return script_id_; }
  void SetScriptId(const std::string& value) { script_id_ = value; }

  // JavaScript script name or url.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // JavaScript script line number (0-based).
  int GetLineNumber() const { return line_number_; }
  void SetLineNumber(int value) { line_number_ = value; }

  // JavaScript script column number (0-based).
  int GetColumnNumber() const { return column_number_; }
  void SetColumnNumber(int value) { column_number_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CallFrame> Clone() const;

  template<int STATE>
  class CallFrameBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFunctionNameSet = 1 << 1,
    kScriptIdSet = 1 << 2,
    kUrlSet = 1 << 3,
    kLineNumberSet = 1 << 4,
    kColumnNumberSet = 1 << 5,
      kAllRequiredFieldsSet = (kFunctionNameSet | kScriptIdSet | kUrlSet | kLineNumberSet | kColumnNumberSet | 0)
    };

    CallFrameBuilder<STATE | kFunctionNameSet>& SetFunctionName(const std::string& value) {
      static_assert(!(STATE & kFunctionNameSet), "property functionName should not have already been set");
      result_->SetFunctionName(value);
      return CastState<kFunctionNameSet>();
    }

    CallFrameBuilder<STATE | kScriptIdSet>& SetScriptId(const std::string& value) {
      static_assert(!(STATE & kScriptIdSet), "property scriptId should not have already been set");
      result_->SetScriptId(value);
      return CastState<kScriptIdSet>();
    }

    CallFrameBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    CallFrameBuilder<STATE | kLineNumberSet>& SetLineNumber(int value) {
      static_assert(!(STATE & kLineNumberSet), "property lineNumber should not have already been set");
      result_->SetLineNumber(value);
      return CastState<kLineNumberSet>();
    }

    CallFrameBuilder<STATE | kColumnNumberSet>& SetColumnNumber(int value) {
      static_assert(!(STATE & kColumnNumberSet), "property columnNumber should not have already been set");
      result_->SetColumnNumber(value);
      return CastState<kColumnNumberSet>();
    }

    std::unique_ptr<CallFrame> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CallFrame;
    CallFrameBuilder() : result_(new CallFrame()) { }

    template<int STEP> CallFrameBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CallFrameBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CallFrame> result_;
  };

  static CallFrameBuilder<0> Builder() {
    return CallFrameBuilder<0>();
  }

 private:
  CallFrame() { }

  std::string function_name_;
  std::string script_id_;
  std::string url_;
  int line_number_;
  int column_number_;

  DISALLOW_COPY_AND_ASSIGN(CallFrame);
};


// Call frames for assertions or error messages.
class HEADLESS_EXPORT StackTrace {
 public:
  static std::unique_ptr<StackTrace> Parse(const base::Value& value, ErrorReporter* errors);
  ~StackTrace() { }

  // String label of this stack trace. For async traces this may be a name of the function that
  // initiated the async call.
  bool HasDescription() const { return !!description_; }
  std::string GetDescription() const { DCHECK(HasDescription()); return description_.value(); }
  void SetDescription(const std::string& value) { description_ = value; }

  // JavaScript function name.
  const std::vector<std::unique_ptr<::headless::runtime::CallFrame>>* GetCallFrames() const { return &call_frames_; }
  void SetCallFrames(std::vector<std::unique_ptr<::headless::runtime::CallFrame>> value) { call_frames_ = std::move(value); }

  // Asynchronous JavaScript stack trace that preceded this stack, if available.
  bool HasParent() const { return !!parent_; }
  const ::headless::runtime::StackTrace* GetParent() const { DCHECK(HasParent()); return parent_.value().get(); }
  void SetParent(std::unique_ptr<::headless::runtime::StackTrace> value) { parent_ = std::move(value); }

  // Asynchronous JavaScript stack trace that preceded this stack, if available.
  bool HasParentId() const { return !!parent_id_; }
  const ::headless::runtime::StackTraceId* GetParentId() const { DCHECK(HasParentId()); return parent_id_.value().get(); }
  void SetParentId(std::unique_ptr<::headless::runtime::StackTraceId> value) { parent_id_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StackTrace> Clone() const;

  template<int STATE>
  class StackTraceBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCallFramesSet = 1 << 1,
      kAllRequiredFieldsSet = (kCallFramesSet | 0)
    };

    StackTraceBuilder<STATE>& SetDescription(const std::string& value) {
      result_->SetDescription(value);
      return *this;
    }

    StackTraceBuilder<STATE | kCallFramesSet>& SetCallFrames(std::vector<std::unique_ptr<::headless::runtime::CallFrame>> value) {
      static_assert(!(STATE & kCallFramesSet), "property callFrames should not have already been set");
      result_->SetCallFrames(std::move(value));
      return CastState<kCallFramesSet>();
    }

    StackTraceBuilder<STATE>& SetParent(std::unique_ptr<::headless::runtime::StackTrace> value) {
      result_->SetParent(std::move(value));
      return *this;
    }

    StackTraceBuilder<STATE>& SetParentId(std::unique_ptr<::headless::runtime::StackTraceId> value) {
      result_->SetParentId(std::move(value));
      return *this;
    }

    std::unique_ptr<StackTrace> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StackTrace;
    StackTraceBuilder() : result_(new StackTrace()) { }

    template<int STEP> StackTraceBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StackTraceBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StackTrace> result_;
  };

  static StackTraceBuilder<0> Builder() {
    return StackTraceBuilder<0>();
  }

 private:
  StackTrace() { }

  base::Optional<std::string> description_;
  std::vector<std::unique_ptr<::headless::runtime::CallFrame>> call_frames_;
  base::Optional<std::unique_ptr<::headless::runtime::StackTrace>> parent_;
  base::Optional<std::unique_ptr<::headless::runtime::StackTraceId>> parent_id_;

  DISALLOW_COPY_AND_ASSIGN(StackTrace);
};


// If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
// allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages.
class HEADLESS_EXPORT StackTraceId {
 public:
  static std::unique_ptr<StackTraceId> Parse(const base::Value& value, ErrorReporter* errors);
  ~StackTraceId() { }

  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  bool HasDebuggerId() const { return !!debugger_id_; }
  std::string GetDebuggerId() const { DCHECK(HasDebuggerId()); return debugger_id_.value(); }
  void SetDebuggerId(const std::string& value) { debugger_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StackTraceId> Clone() const;

  template<int STATE>
  class StackTraceIdBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdSet | 0)
    };

    StackTraceIdBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    StackTraceIdBuilder<STATE>& SetDebuggerId(const std::string& value) {
      result_->SetDebuggerId(value);
      return *this;
    }

    std::unique_ptr<StackTraceId> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StackTraceId;
    StackTraceIdBuilder() : result_(new StackTraceId()) { }

    template<int STEP> StackTraceIdBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StackTraceIdBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StackTraceId> result_;
  };

  static StackTraceIdBuilder<0> Builder() {
    return StackTraceIdBuilder<0>();
  }

 private:
  StackTraceId() { }

  std::string id_;
  base::Optional<std::string> debugger_id_;

  DISALLOW_COPY_AND_ASSIGN(StackTraceId);
};


// Parameters for the AwaitPromise command.
class HEADLESS_EXPORT AwaitPromiseParams {
 public:
  static std::unique_ptr<AwaitPromiseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AwaitPromiseParams() { }

  // Identifier of the promise.
  std::string GetPromiseObjectId() const { return promise_object_id_; }
  void SetPromiseObjectId(const std::string& value) { promise_object_id_ = value; }

  // Whether the result is expected to be a JSON object that should be sent by value.
  bool HasReturnByValue() const { return !!return_by_value_; }
  bool GetReturnByValue() const { DCHECK(HasReturnByValue()); return return_by_value_.value(); }
  void SetReturnByValue(bool value) { return_by_value_ = value; }

  // Whether preview should be generated for the result.
  bool HasGeneratePreview() const { return !!generate_preview_; }
  bool GetGeneratePreview() const { DCHECK(HasGeneratePreview()); return generate_preview_.value(); }
  void SetGeneratePreview(bool value) { generate_preview_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AwaitPromiseParams> Clone() const;

  template<int STATE>
  class AwaitPromiseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPromiseObjectIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kPromiseObjectIdSet | 0)
    };

    AwaitPromiseParamsBuilder<STATE | kPromiseObjectIdSet>& SetPromiseObjectId(const std::string& value) {
      static_assert(!(STATE & kPromiseObjectIdSet), "property promiseObjectId should not have already been set");
      result_->SetPromiseObjectId(value);
      return CastState<kPromiseObjectIdSet>();
    }

    AwaitPromiseParamsBuilder<STATE>& SetReturnByValue(bool value) {
      result_->SetReturnByValue(value);
      return *this;
    }

    AwaitPromiseParamsBuilder<STATE>& SetGeneratePreview(bool value) {
      result_->SetGeneratePreview(value);
      return *this;
    }

    std::unique_ptr<AwaitPromiseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AwaitPromiseParams;
    AwaitPromiseParamsBuilder() : result_(new AwaitPromiseParams()) { }

    template<int STEP> AwaitPromiseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AwaitPromiseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AwaitPromiseParams> result_;
  };

  static AwaitPromiseParamsBuilder<0> Builder() {
    return AwaitPromiseParamsBuilder<0>();
  }

 private:
  AwaitPromiseParams() { }

  std::string promise_object_id_;
  base::Optional<bool> return_by_value_;
  base::Optional<bool> generate_preview_;

  DISALLOW_COPY_AND_ASSIGN(AwaitPromiseParams);
};


// Result for the AwaitPromise command.
class HEADLESS_EXPORT AwaitPromiseResult {
 public:
  static std::unique_ptr<AwaitPromiseResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AwaitPromiseResult() { }

  // Promise result. Will contain rejected value if promise was rejected.
  const ::headless::runtime::RemoteObject* GetResult() const { return result_.get(); }
  void SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) { result_ = std::move(value); }

  // Exception details if stack strace is available.
  bool HasExceptionDetails() const { return !!exception_details_; }
  const ::headless::runtime::ExceptionDetails* GetExceptionDetails() const { DCHECK(HasExceptionDetails()); return exception_details_.value().get(); }
  void SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) { exception_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AwaitPromiseResult> Clone() const;

  template<int STATE>
  class AwaitPromiseResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    AwaitPromiseResultBuilder<STATE | kResultSet>& SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    AwaitPromiseResultBuilder<STATE>& SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) {
      result_->SetExceptionDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<AwaitPromiseResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AwaitPromiseResult;
    AwaitPromiseResultBuilder() : result_(new AwaitPromiseResult()) { }

    template<int STEP> AwaitPromiseResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AwaitPromiseResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AwaitPromiseResult> result_;
  };

  static AwaitPromiseResultBuilder<0> Builder() {
    return AwaitPromiseResultBuilder<0>();
  }

 private:
  AwaitPromiseResult() { }

  std::unique_ptr<::headless::runtime::RemoteObject> result_;
  base::Optional<std::unique_ptr<::headless::runtime::ExceptionDetails>> exception_details_;

  DISALLOW_COPY_AND_ASSIGN(AwaitPromiseResult);
};


// Parameters for the CallFunctionOn command.
class HEADLESS_EXPORT CallFunctionOnParams {
 public:
  static std::unique_ptr<CallFunctionOnParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CallFunctionOnParams() { }

  // Declaration of the function to call.
  std::string GetFunctionDeclaration() const { return function_declaration_; }
  void SetFunctionDeclaration(const std::string& value) { function_declaration_ = value; }

  // Identifier of the object to call function on. Either objectId or executionContextId should
  // be specified.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  // Call arguments. All call arguments must belong to the same JavaScript world as the target
  // object.
  bool HasArguments() const { return !!arguments_; }
  const std::vector<std::unique_ptr<::headless::runtime::CallArgument>>* GetArguments() const { DCHECK(HasArguments()); return &arguments_.value(); }
  void SetArguments(std::vector<std::unique_ptr<::headless::runtime::CallArgument>> value) { arguments_ = std::move(value); }

  // In silent mode exceptions thrown during evaluation are not reported and do not pause
  // execution. Overrides `setPauseOnException` state.
  bool HasSilent() const { return !!silent_; }
  bool GetSilent() const { DCHECK(HasSilent()); return silent_.value(); }
  void SetSilent(bool value) { silent_ = value; }

  // Whether the result is expected to be a JSON object which should be sent by value.
  bool HasReturnByValue() const { return !!return_by_value_; }
  bool GetReturnByValue() const { DCHECK(HasReturnByValue()); return return_by_value_.value(); }
  void SetReturnByValue(bool value) { return_by_value_ = value; }

  // Whether preview should be generated for the result.
  bool HasGeneratePreview() const { return !!generate_preview_; }
  bool GetGeneratePreview() const { DCHECK(HasGeneratePreview()); return generate_preview_.value(); }
  void SetGeneratePreview(bool value) { generate_preview_ = value; }

  // Whether execution should be treated as initiated by user in the UI.
  bool HasUserGesture() const { return !!user_gesture_; }
  bool GetUserGesture() const { DCHECK(HasUserGesture()); return user_gesture_.value(); }
  void SetUserGesture(bool value) { user_gesture_ = value; }

  // Whether execution should `await` for resulting value and return once awaited promise is
  // resolved.
  bool HasAwaitPromise() const { return !!await_promise_; }
  bool GetAwaitPromise() const { DCHECK(HasAwaitPromise()); return await_promise_.value(); }
  void SetAwaitPromise(bool value) { await_promise_ = value; }

  // Specifies execution context which global object will be used to call function on. Either
  // executionContextId or objectId should be specified.
  bool HasExecutionContextId() const { return !!execution_context_id_; }
  int GetExecutionContextId() const { DCHECK(HasExecutionContextId()); return execution_context_id_.value(); }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  // Symbolic group name that can be used to release multiple objects. If objectGroup is not
  // specified and objectId is, objectGroup will be inherited from object.
  bool HasObjectGroup() const { return !!object_group_; }
  std::string GetObjectGroup() const { DCHECK(HasObjectGroup()); return object_group_.value(); }
  void SetObjectGroup(const std::string& value) { object_group_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CallFunctionOnParams> Clone() const;

  template<int STATE>
  class CallFunctionOnParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFunctionDeclarationSet = 1 << 1,
      kAllRequiredFieldsSet = (kFunctionDeclarationSet | 0)
    };

    CallFunctionOnParamsBuilder<STATE | kFunctionDeclarationSet>& SetFunctionDeclaration(const std::string& value) {
      static_assert(!(STATE & kFunctionDeclarationSet), "property functionDeclaration should not have already been set");
      result_->SetFunctionDeclaration(value);
      return CastState<kFunctionDeclarationSet>();
    }

    CallFunctionOnParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetArguments(std::vector<std::unique_ptr<::headless::runtime::CallArgument>> value) {
      result_->SetArguments(std::move(value));
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetSilent(bool value) {
      result_->SetSilent(value);
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetReturnByValue(bool value) {
      result_->SetReturnByValue(value);
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetGeneratePreview(bool value) {
      result_->SetGeneratePreview(value);
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetUserGesture(bool value) {
      result_->SetUserGesture(value);
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetAwaitPromise(bool value) {
      result_->SetAwaitPromise(value);
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetExecutionContextId(int value) {
      result_->SetExecutionContextId(value);
      return *this;
    }

    CallFunctionOnParamsBuilder<STATE>& SetObjectGroup(const std::string& value) {
      result_->SetObjectGroup(value);
      return *this;
    }

    std::unique_ptr<CallFunctionOnParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CallFunctionOnParams;
    CallFunctionOnParamsBuilder() : result_(new CallFunctionOnParams()) { }

    template<int STEP> CallFunctionOnParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CallFunctionOnParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CallFunctionOnParams> result_;
  };

  static CallFunctionOnParamsBuilder<0> Builder() {
    return CallFunctionOnParamsBuilder<0>();
  }

 private:
  CallFunctionOnParams() { }

  std::string function_declaration_;
  base::Optional<std::string> object_id_;
  base::Optional<std::vector<std::unique_ptr<::headless::runtime::CallArgument>>> arguments_;
  base::Optional<bool> silent_;
  base::Optional<bool> return_by_value_;
  base::Optional<bool> generate_preview_;
  base::Optional<bool> user_gesture_;
  base::Optional<bool> await_promise_;
  base::Optional<int> execution_context_id_;
  base::Optional<std::string> object_group_;

  DISALLOW_COPY_AND_ASSIGN(CallFunctionOnParams);
};


// Result for the CallFunctionOn command.
class HEADLESS_EXPORT CallFunctionOnResult {
 public:
  static std::unique_ptr<CallFunctionOnResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CallFunctionOnResult() { }

  // Call result.
  const ::headless::runtime::RemoteObject* GetResult() const { return result_.get(); }
  void SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) { result_ = std::move(value); }

  // Exception details.
  bool HasExceptionDetails() const { return !!exception_details_; }
  const ::headless::runtime::ExceptionDetails* GetExceptionDetails() const { DCHECK(HasExceptionDetails()); return exception_details_.value().get(); }
  void SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) { exception_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CallFunctionOnResult> Clone() const;

  template<int STATE>
  class CallFunctionOnResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    CallFunctionOnResultBuilder<STATE | kResultSet>& SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    CallFunctionOnResultBuilder<STATE>& SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) {
      result_->SetExceptionDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<CallFunctionOnResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CallFunctionOnResult;
    CallFunctionOnResultBuilder() : result_(new CallFunctionOnResult()) { }

    template<int STEP> CallFunctionOnResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CallFunctionOnResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CallFunctionOnResult> result_;
  };

  static CallFunctionOnResultBuilder<0> Builder() {
    return CallFunctionOnResultBuilder<0>();
  }

 private:
  CallFunctionOnResult() { }

  std::unique_ptr<::headless::runtime::RemoteObject> result_;
  base::Optional<std::unique_ptr<::headless::runtime::ExceptionDetails>> exception_details_;

  DISALLOW_COPY_AND_ASSIGN(CallFunctionOnResult);
};


// Parameters for the CompileScript command.
class HEADLESS_EXPORT CompileScriptParams {
 public:
  static std::unique_ptr<CompileScriptParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CompileScriptParams() { }

  // Expression to compile.
  std::string GetExpression() const { return expression_; }
  void SetExpression(const std::string& value) { expression_ = value; }

  // Source url to be set for the script.
  std::string GetSourceURL() const { return sourceurl_; }
  void SetSourceURL(const std::string& value) { sourceurl_ = value; }

  // Specifies whether the compiled script should be persisted.
  bool GetPersistScript() const { return persist_script_; }
  void SetPersistScript(bool value) { persist_script_ = value; }

  // Specifies in which execution context to perform script run. If the parameter is omitted the
  // evaluation will be performed in the context of the inspected page.
  bool HasExecutionContextId() const { return !!execution_context_id_; }
  int GetExecutionContextId() const { DCHECK(HasExecutionContextId()); return execution_context_id_.value(); }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CompileScriptParams> Clone() const;

  template<int STATE>
  class CompileScriptParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kExpressionSet = 1 << 1,
    kSourceURLSet = 1 << 2,
    kPersistScriptSet = 1 << 3,
      kAllRequiredFieldsSet = (kExpressionSet | kSourceURLSet | kPersistScriptSet | 0)
    };

    CompileScriptParamsBuilder<STATE | kExpressionSet>& SetExpression(const std::string& value) {
      static_assert(!(STATE & kExpressionSet), "property expression should not have already been set");
      result_->SetExpression(value);
      return CastState<kExpressionSet>();
    }

    CompileScriptParamsBuilder<STATE | kSourceURLSet>& SetSourceURL(const std::string& value) {
      static_assert(!(STATE & kSourceURLSet), "property sourceURL should not have already been set");
      result_->SetSourceURL(value);
      return CastState<kSourceURLSet>();
    }

    CompileScriptParamsBuilder<STATE | kPersistScriptSet>& SetPersistScript(bool value) {
      static_assert(!(STATE & kPersistScriptSet), "property persistScript should not have already been set");
      result_->SetPersistScript(value);
      return CastState<kPersistScriptSet>();
    }

    CompileScriptParamsBuilder<STATE>& SetExecutionContextId(int value) {
      result_->SetExecutionContextId(value);
      return *this;
    }

    std::unique_ptr<CompileScriptParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CompileScriptParams;
    CompileScriptParamsBuilder() : result_(new CompileScriptParams()) { }

    template<int STEP> CompileScriptParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CompileScriptParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CompileScriptParams> result_;
  };

  static CompileScriptParamsBuilder<0> Builder() {
    return CompileScriptParamsBuilder<0>();
  }

 private:
  CompileScriptParams() { }

  std::string expression_;
  std::string sourceurl_;
  bool persist_script_;
  base::Optional<int> execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(CompileScriptParams);
};


// Result for the CompileScript command.
class HEADLESS_EXPORT CompileScriptResult {
 public:
  static std::unique_ptr<CompileScriptResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CompileScriptResult() { }

  // Id of the script.
  bool HasScriptId() const { return !!script_id_; }
  std::string GetScriptId() const { DCHECK(HasScriptId()); return script_id_.value(); }
  void SetScriptId(const std::string& value) { script_id_ = value; }

  // Exception details.
  bool HasExceptionDetails() const { return !!exception_details_; }
  const ::headless::runtime::ExceptionDetails* GetExceptionDetails() const { DCHECK(HasExceptionDetails()); return exception_details_.value().get(); }
  void SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) { exception_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CompileScriptResult> Clone() const;

  template<int STATE>
  class CompileScriptResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    CompileScriptResultBuilder<STATE>& SetScriptId(const std::string& value) {
      result_->SetScriptId(value);
      return *this;
    }

    CompileScriptResultBuilder<STATE>& SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) {
      result_->SetExceptionDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<CompileScriptResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CompileScriptResult;
    CompileScriptResultBuilder() : result_(new CompileScriptResult()) { }

    template<int STEP> CompileScriptResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CompileScriptResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CompileScriptResult> result_;
  };

  static CompileScriptResultBuilder<0> Builder() {
    return CompileScriptResultBuilder<0>();
  }

 private:
  CompileScriptResult() { }

  base::Optional<std::string> script_id_;
  base::Optional<std::unique_ptr<::headless::runtime::ExceptionDetails>> exception_details_;

  DISALLOW_COPY_AND_ASSIGN(CompileScriptResult);
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


// Parameters for the DiscardConsoleEntries command.
class HEADLESS_EXPORT DiscardConsoleEntriesParams {
 public:
  static std::unique_ptr<DiscardConsoleEntriesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DiscardConsoleEntriesParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DiscardConsoleEntriesParams> Clone() const;

  template<int STATE>
  class DiscardConsoleEntriesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DiscardConsoleEntriesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DiscardConsoleEntriesParams;
    DiscardConsoleEntriesParamsBuilder() : result_(new DiscardConsoleEntriesParams()) { }

    template<int STEP> DiscardConsoleEntriesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DiscardConsoleEntriesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DiscardConsoleEntriesParams> result_;
  };

  static DiscardConsoleEntriesParamsBuilder<0> Builder() {
    return DiscardConsoleEntriesParamsBuilder<0>();
  }

 private:
  DiscardConsoleEntriesParams() { }


  DISALLOW_COPY_AND_ASSIGN(DiscardConsoleEntriesParams);
};


// Result for the DiscardConsoleEntries command.
class HEADLESS_EXPORT DiscardConsoleEntriesResult {
 public:
  static std::unique_ptr<DiscardConsoleEntriesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DiscardConsoleEntriesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DiscardConsoleEntriesResult> Clone() const;

  template<int STATE>
  class DiscardConsoleEntriesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DiscardConsoleEntriesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DiscardConsoleEntriesResult;
    DiscardConsoleEntriesResultBuilder() : result_(new DiscardConsoleEntriesResult()) { }

    template<int STEP> DiscardConsoleEntriesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DiscardConsoleEntriesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DiscardConsoleEntriesResult> result_;
  };

  static DiscardConsoleEntriesResultBuilder<0> Builder() {
    return DiscardConsoleEntriesResultBuilder<0>();
  }

 private:
  DiscardConsoleEntriesResult() { }


  DISALLOW_COPY_AND_ASSIGN(DiscardConsoleEntriesResult);
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


// Parameters for the Evaluate command.
class HEADLESS_EXPORT EvaluateParams {
 public:
  static std::unique_ptr<EvaluateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EvaluateParams() { }

  // Expression to evaluate.
  std::string GetExpression() const { return expression_; }
  void SetExpression(const std::string& value) { expression_ = value; }

  // Symbolic group name that can be used to release multiple objects.
  bool HasObjectGroup() const { return !!object_group_; }
  std::string GetObjectGroup() const { DCHECK(HasObjectGroup()); return object_group_.value(); }
  void SetObjectGroup(const std::string& value) { object_group_ = value; }

  // Determines whether Command Line API should be available during the evaluation.
  bool HasIncludeCommandLineAPI() const { return !!include_command_lineapi_; }
  bool GetIncludeCommandLineAPI() const { DCHECK(HasIncludeCommandLineAPI()); return include_command_lineapi_.value(); }
  void SetIncludeCommandLineAPI(bool value) { include_command_lineapi_ = value; }

  // In silent mode exceptions thrown during evaluation are not reported and do not pause
  // execution. Overrides `setPauseOnException` state.
  bool HasSilent() const { return !!silent_; }
  bool GetSilent() const { DCHECK(HasSilent()); return silent_.value(); }
  void SetSilent(bool value) { silent_ = value; }

  // Specifies in which execution context to perform evaluation. If the parameter is omitted the
  // evaluation will be performed in the context of the inspected page.
  bool HasContextId() const { return !!context_id_; }
  int GetContextId() const { DCHECK(HasContextId()); return context_id_.value(); }
  void SetContextId(int value) { context_id_ = value; }

  // Whether the result is expected to be a JSON object that should be sent by value.
  bool HasReturnByValue() const { return !!return_by_value_; }
  bool GetReturnByValue() const { DCHECK(HasReturnByValue()); return return_by_value_.value(); }
  void SetReturnByValue(bool value) { return_by_value_ = value; }

  // Whether preview should be generated for the result.
  bool HasGeneratePreview() const { return !!generate_preview_; }
  bool GetGeneratePreview() const { DCHECK(HasGeneratePreview()); return generate_preview_.value(); }
  void SetGeneratePreview(bool value) { generate_preview_ = value; }

  // Whether execution should be treated as initiated by user in the UI.
  bool HasUserGesture() const { return !!user_gesture_; }
  bool GetUserGesture() const { DCHECK(HasUserGesture()); return user_gesture_.value(); }
  void SetUserGesture(bool value) { user_gesture_ = value; }

  // Whether execution should `await` for resulting value and return once awaited promise is
  // resolved.
  bool HasAwaitPromise() const { return !!await_promise_; }
  bool GetAwaitPromise() const { DCHECK(HasAwaitPromise()); return await_promise_.value(); }
  void SetAwaitPromise(bool value) { await_promise_ = value; }

  // Whether to throw an exception if side effect cannot be ruled out during evaluation.
  // This implies `disableBreaks` below.
  bool HasThrowOnSideEffect() const { return !!throw_on_side_effect_; }
  bool GetThrowOnSideEffect() const { DCHECK(HasThrowOnSideEffect()); return throw_on_side_effect_.value(); }
  void SetThrowOnSideEffect(bool value) { throw_on_side_effect_ = value; }

  // Terminate execution after timing out (number of milliseconds).
  bool HasTimeout() const { return !!timeout_; }
  double GetTimeout() const { DCHECK(HasTimeout()); return timeout_.value(); }
  void SetTimeout(double value) { timeout_ = value; }

  // Disable breakpoints during execution.
  bool HasDisableBreaks() const { return !!disable_breaks_; }
  bool GetDisableBreaks() const { DCHECK(HasDisableBreaks()); return disable_breaks_.value(); }
  void SetDisableBreaks(bool value) { disable_breaks_ = value; }

  // Setting this flag to true enables `let` re-declaration and top-level `await`.
  // Note that `let` variables can only be re-declared if they originate from
  // `replMode` themselves.
  bool HasReplMode() const { return !!repl_mode_; }
  bool GetReplMode() const { DCHECK(HasReplMode()); return repl_mode_.value(); }
  void SetReplMode(bool value) { repl_mode_ = value; }

  // The Content Security Policy (CSP) for the target might block 'unsafe-eval'
  // which includes eval(), Function(), setTimeout() and setInterval()
  // when called with non-callable arguments. This flag bypasses CSP for this
  // evaluation and allows unsafe-eval. Defaults to true.
  bool HasAllowUnsafeEvalBlockedByCSP() const { return !!allow_unsafe_eval_blocked_bycsp_; }
  bool GetAllowUnsafeEvalBlockedByCSP() const { DCHECK(HasAllowUnsafeEvalBlockedByCSP()); return allow_unsafe_eval_blocked_bycsp_.value(); }
  void SetAllowUnsafeEvalBlockedByCSP(bool value) { allow_unsafe_eval_blocked_bycsp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EvaluateParams> Clone() const;

  template<int STATE>
  class EvaluateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kExpressionSet = 1 << 1,
      kAllRequiredFieldsSet = (kExpressionSet | 0)
    };

    EvaluateParamsBuilder<STATE | kExpressionSet>& SetExpression(const std::string& value) {
      static_assert(!(STATE & kExpressionSet), "property expression should not have already been set");
      result_->SetExpression(value);
      return CastState<kExpressionSet>();
    }

    EvaluateParamsBuilder<STATE>& SetObjectGroup(const std::string& value) {
      result_->SetObjectGroup(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetIncludeCommandLineAPI(bool value) {
      result_->SetIncludeCommandLineAPI(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetSilent(bool value) {
      result_->SetSilent(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetContextId(int value) {
      result_->SetContextId(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetReturnByValue(bool value) {
      result_->SetReturnByValue(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetGeneratePreview(bool value) {
      result_->SetGeneratePreview(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetUserGesture(bool value) {
      result_->SetUserGesture(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetAwaitPromise(bool value) {
      result_->SetAwaitPromise(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetThrowOnSideEffect(bool value) {
      result_->SetThrowOnSideEffect(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetTimeout(double value) {
      result_->SetTimeout(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetDisableBreaks(bool value) {
      result_->SetDisableBreaks(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetReplMode(bool value) {
      result_->SetReplMode(value);
      return *this;
    }

    EvaluateParamsBuilder<STATE>& SetAllowUnsafeEvalBlockedByCSP(bool value) {
      result_->SetAllowUnsafeEvalBlockedByCSP(value);
      return *this;
    }

    std::unique_ptr<EvaluateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EvaluateParams;
    EvaluateParamsBuilder() : result_(new EvaluateParams()) { }

    template<int STEP> EvaluateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EvaluateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EvaluateParams> result_;
  };

  static EvaluateParamsBuilder<0> Builder() {
    return EvaluateParamsBuilder<0>();
  }

 private:
  EvaluateParams() { }

  std::string expression_;
  base::Optional<std::string> object_group_;
  base::Optional<bool> include_command_lineapi_;
  base::Optional<bool> silent_;
  base::Optional<int> context_id_;
  base::Optional<bool> return_by_value_;
  base::Optional<bool> generate_preview_;
  base::Optional<bool> user_gesture_;
  base::Optional<bool> await_promise_;
  base::Optional<bool> throw_on_side_effect_;
  base::Optional<double> timeout_;
  base::Optional<bool> disable_breaks_;
  base::Optional<bool> repl_mode_;
  base::Optional<bool> allow_unsafe_eval_blocked_bycsp_;

  DISALLOW_COPY_AND_ASSIGN(EvaluateParams);
};


// Result for the Evaluate command.
class HEADLESS_EXPORT EvaluateResult {
 public:
  static std::unique_ptr<EvaluateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EvaluateResult() { }

  // Evaluation result.
  const ::headless::runtime::RemoteObject* GetResult() const { return result_.get(); }
  void SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) { result_ = std::move(value); }

  // Exception details.
  bool HasExceptionDetails() const { return !!exception_details_; }
  const ::headless::runtime::ExceptionDetails* GetExceptionDetails() const { DCHECK(HasExceptionDetails()); return exception_details_.value().get(); }
  void SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) { exception_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EvaluateResult> Clone() const;

  template<int STATE>
  class EvaluateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    EvaluateResultBuilder<STATE | kResultSet>& SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    EvaluateResultBuilder<STATE>& SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) {
      result_->SetExceptionDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<EvaluateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EvaluateResult;
    EvaluateResultBuilder() : result_(new EvaluateResult()) { }

    template<int STEP> EvaluateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EvaluateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EvaluateResult> result_;
  };

  static EvaluateResultBuilder<0> Builder() {
    return EvaluateResultBuilder<0>();
  }

 private:
  EvaluateResult() { }

  std::unique_ptr<::headless::runtime::RemoteObject> result_;
  base::Optional<std::unique_ptr<::headless::runtime::ExceptionDetails>> exception_details_;

  DISALLOW_COPY_AND_ASSIGN(EvaluateResult);
};


// Parameters for the GetIsolateId command.
class HEADLESS_EXPORT GetIsolateIdParams {
 public:
  static std::unique_ptr<GetIsolateIdParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetIsolateIdParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetIsolateIdParams> Clone() const;

  template<int STATE>
  class GetIsolateIdParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetIsolateIdParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetIsolateIdParams;
    GetIsolateIdParamsBuilder() : result_(new GetIsolateIdParams()) { }

    template<int STEP> GetIsolateIdParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetIsolateIdParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetIsolateIdParams> result_;
  };

  static GetIsolateIdParamsBuilder<0> Builder() {
    return GetIsolateIdParamsBuilder<0>();
  }

 private:
  GetIsolateIdParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetIsolateIdParams);
};


// Result for the GetIsolateId command.
class HEADLESS_EXPORT GetIsolateIdResult {
 public:
  static std::unique_ptr<GetIsolateIdResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetIsolateIdResult() { }

  // The isolate id.
  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetIsolateIdResult> Clone() const;

  template<int STATE>
  class GetIsolateIdResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdSet | 0)
    };

    GetIsolateIdResultBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    std::unique_ptr<GetIsolateIdResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetIsolateIdResult;
    GetIsolateIdResultBuilder() : result_(new GetIsolateIdResult()) { }

    template<int STEP> GetIsolateIdResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetIsolateIdResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetIsolateIdResult> result_;
  };

  static GetIsolateIdResultBuilder<0> Builder() {
    return GetIsolateIdResultBuilder<0>();
  }

 private:
  GetIsolateIdResult() { }

  std::string id_;

  DISALLOW_COPY_AND_ASSIGN(GetIsolateIdResult);
};


// Parameters for the GetHeapUsage command.
class HEADLESS_EXPORT GetHeapUsageParams {
 public:
  static std::unique_ptr<GetHeapUsageParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetHeapUsageParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetHeapUsageParams> Clone() const;

  template<int STATE>
  class GetHeapUsageParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetHeapUsageParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetHeapUsageParams;
    GetHeapUsageParamsBuilder() : result_(new GetHeapUsageParams()) { }

    template<int STEP> GetHeapUsageParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetHeapUsageParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetHeapUsageParams> result_;
  };

  static GetHeapUsageParamsBuilder<0> Builder() {
    return GetHeapUsageParamsBuilder<0>();
  }

 private:
  GetHeapUsageParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetHeapUsageParams);
};


// Result for the GetHeapUsage command.
class HEADLESS_EXPORT GetHeapUsageResult {
 public:
  static std::unique_ptr<GetHeapUsageResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetHeapUsageResult() { }

  // Used heap size in bytes.
  double GetUsedSize() const { return used_size_; }
  void SetUsedSize(double value) { used_size_ = value; }

  // Allocated heap size in bytes.
  double GetTotalSize() const { return total_size_; }
  void SetTotalSize(double value) { total_size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetHeapUsageResult> Clone() const;

  template<int STATE>
  class GetHeapUsageResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUsedSizeSet = 1 << 1,
    kTotalSizeSet = 1 << 2,
      kAllRequiredFieldsSet = (kUsedSizeSet | kTotalSizeSet | 0)
    };

    GetHeapUsageResultBuilder<STATE | kUsedSizeSet>& SetUsedSize(double value) {
      static_assert(!(STATE & kUsedSizeSet), "property usedSize should not have already been set");
      result_->SetUsedSize(value);
      return CastState<kUsedSizeSet>();
    }

    GetHeapUsageResultBuilder<STATE | kTotalSizeSet>& SetTotalSize(double value) {
      static_assert(!(STATE & kTotalSizeSet), "property totalSize should not have already been set");
      result_->SetTotalSize(value);
      return CastState<kTotalSizeSet>();
    }

    std::unique_ptr<GetHeapUsageResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetHeapUsageResult;
    GetHeapUsageResultBuilder() : result_(new GetHeapUsageResult()) { }

    template<int STEP> GetHeapUsageResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetHeapUsageResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetHeapUsageResult> result_;
  };

  static GetHeapUsageResultBuilder<0> Builder() {
    return GetHeapUsageResultBuilder<0>();
  }

 private:
  GetHeapUsageResult() { }

  double used_size_;
  double total_size_;

  DISALLOW_COPY_AND_ASSIGN(GetHeapUsageResult);
};


// Parameters for the GetProperties command.
class HEADLESS_EXPORT GetPropertiesParams {
 public:
  static std::unique_ptr<GetPropertiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetPropertiesParams() { }

  // Identifier of the object to return properties for.
  std::string GetObjectId() const { return object_id_; }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  // If true, returns properties belonging only to the element itself, not to its prototype
  // chain.
  bool HasOwnProperties() const { return !!own_properties_; }
  bool GetOwnProperties() const { DCHECK(HasOwnProperties()); return own_properties_.value(); }
  void SetOwnProperties(bool value) { own_properties_ = value; }

  // If true, returns accessor properties (with getter/setter) only; internal properties are not
  // returned either.
  bool HasAccessorPropertiesOnly() const { return !!accessor_properties_only_; }
  bool GetAccessorPropertiesOnly() const { DCHECK(HasAccessorPropertiesOnly()); return accessor_properties_only_.value(); }
  void SetAccessorPropertiesOnly(bool value) { accessor_properties_only_ = value; }

  // Whether preview should be generated for the results.
  bool HasGeneratePreview() const { return !!generate_preview_; }
  bool GetGeneratePreview() const { DCHECK(HasGeneratePreview()); return generate_preview_.value(); }
  void SetGeneratePreview(bool value) { generate_preview_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetPropertiesParams> Clone() const;

  template<int STATE>
  class GetPropertiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectIdSet | 0)
    };

    GetPropertiesParamsBuilder<STATE | kObjectIdSet>& SetObjectId(const std::string& value) {
      static_assert(!(STATE & kObjectIdSet), "property objectId should not have already been set");
      result_->SetObjectId(value);
      return CastState<kObjectIdSet>();
    }

    GetPropertiesParamsBuilder<STATE>& SetOwnProperties(bool value) {
      result_->SetOwnProperties(value);
      return *this;
    }

    GetPropertiesParamsBuilder<STATE>& SetAccessorPropertiesOnly(bool value) {
      result_->SetAccessorPropertiesOnly(value);
      return *this;
    }

    GetPropertiesParamsBuilder<STATE>& SetGeneratePreview(bool value) {
      result_->SetGeneratePreview(value);
      return *this;
    }

    std::unique_ptr<GetPropertiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetPropertiesParams;
    GetPropertiesParamsBuilder() : result_(new GetPropertiesParams()) { }

    template<int STEP> GetPropertiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetPropertiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetPropertiesParams> result_;
  };

  static GetPropertiesParamsBuilder<0> Builder() {
    return GetPropertiesParamsBuilder<0>();
  }

 private:
  GetPropertiesParams() { }

  std::string object_id_;
  base::Optional<bool> own_properties_;
  base::Optional<bool> accessor_properties_only_;
  base::Optional<bool> generate_preview_;

  DISALLOW_COPY_AND_ASSIGN(GetPropertiesParams);
};


// Result for the GetProperties command.
class HEADLESS_EXPORT GetPropertiesResult {
 public:
  static std::unique_ptr<GetPropertiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetPropertiesResult() { }

  // Object properties.
  const std::vector<std::unique_ptr<::headless::runtime::PropertyDescriptor>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::runtime::PropertyDescriptor>> value) { result_ = std::move(value); }

  // Internal object properties (only of the element itself).
  bool HasInternalProperties() const { return !!internal_properties_; }
  const std::vector<std::unique_ptr<::headless::runtime::InternalPropertyDescriptor>>* GetInternalProperties() const { DCHECK(HasInternalProperties()); return &internal_properties_.value(); }
  void SetInternalProperties(std::vector<std::unique_ptr<::headless::runtime::InternalPropertyDescriptor>> value) { internal_properties_ = std::move(value); }

  // Object private properties.
  bool HasPrivateProperties() const { return !!private_properties_; }
  const std::vector<std::unique_ptr<::headless::runtime::PrivatePropertyDescriptor>>* GetPrivateProperties() const { DCHECK(HasPrivateProperties()); return &private_properties_.value(); }
  void SetPrivateProperties(std::vector<std::unique_ptr<::headless::runtime::PrivatePropertyDescriptor>> value) { private_properties_ = std::move(value); }

  // Exception details.
  bool HasExceptionDetails() const { return !!exception_details_; }
  const ::headless::runtime::ExceptionDetails* GetExceptionDetails() const { DCHECK(HasExceptionDetails()); return exception_details_.value().get(); }
  void SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) { exception_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetPropertiesResult> Clone() const;

  template<int STATE>
  class GetPropertiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    GetPropertiesResultBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::runtime::PropertyDescriptor>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    GetPropertiesResultBuilder<STATE>& SetInternalProperties(std::vector<std::unique_ptr<::headless::runtime::InternalPropertyDescriptor>> value) {
      result_->SetInternalProperties(std::move(value));
      return *this;
    }

    GetPropertiesResultBuilder<STATE>& SetPrivateProperties(std::vector<std::unique_ptr<::headless::runtime::PrivatePropertyDescriptor>> value) {
      result_->SetPrivateProperties(std::move(value));
      return *this;
    }

    GetPropertiesResultBuilder<STATE>& SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) {
      result_->SetExceptionDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<GetPropertiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetPropertiesResult;
    GetPropertiesResultBuilder() : result_(new GetPropertiesResult()) { }

    template<int STEP> GetPropertiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetPropertiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetPropertiesResult> result_;
  };

  static GetPropertiesResultBuilder<0> Builder() {
    return GetPropertiesResultBuilder<0>();
  }

 private:
  GetPropertiesResult() { }

  std::vector<std::unique_ptr<::headless::runtime::PropertyDescriptor>> result_;
  base::Optional<std::vector<std::unique_ptr<::headless::runtime::InternalPropertyDescriptor>>> internal_properties_;
  base::Optional<std::vector<std::unique_ptr<::headless::runtime::PrivatePropertyDescriptor>>> private_properties_;
  base::Optional<std::unique_ptr<::headless::runtime::ExceptionDetails>> exception_details_;

  DISALLOW_COPY_AND_ASSIGN(GetPropertiesResult);
};


// Parameters for the GlobalLexicalScopeNames command.
class HEADLESS_EXPORT GlobalLexicalScopeNamesParams {
 public:
  static std::unique_ptr<GlobalLexicalScopeNamesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GlobalLexicalScopeNamesParams() { }

  // Specifies in which execution context to lookup global scope variables.
  bool HasExecutionContextId() const { return !!execution_context_id_; }
  int GetExecutionContextId() const { DCHECK(HasExecutionContextId()); return execution_context_id_.value(); }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GlobalLexicalScopeNamesParams> Clone() const;

  template<int STATE>
  class GlobalLexicalScopeNamesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GlobalLexicalScopeNamesParamsBuilder<STATE>& SetExecutionContextId(int value) {
      result_->SetExecutionContextId(value);
      return *this;
    }

    std::unique_ptr<GlobalLexicalScopeNamesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GlobalLexicalScopeNamesParams;
    GlobalLexicalScopeNamesParamsBuilder() : result_(new GlobalLexicalScopeNamesParams()) { }

    template<int STEP> GlobalLexicalScopeNamesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GlobalLexicalScopeNamesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GlobalLexicalScopeNamesParams> result_;
  };

  static GlobalLexicalScopeNamesParamsBuilder<0> Builder() {
    return GlobalLexicalScopeNamesParamsBuilder<0>();
  }

 private:
  GlobalLexicalScopeNamesParams() { }

  base::Optional<int> execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(GlobalLexicalScopeNamesParams);
};


// Result for the GlobalLexicalScopeNames command.
class HEADLESS_EXPORT GlobalLexicalScopeNamesResult {
 public:
  static std::unique_ptr<GlobalLexicalScopeNamesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GlobalLexicalScopeNamesResult() { }

  const std::vector<std::string>* GetNames() const { return &names_; }
  void SetNames(std::vector<std::string> value) { names_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GlobalLexicalScopeNamesResult> Clone() const;

  template<int STATE>
  class GlobalLexicalScopeNamesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNamesSet = 1 << 1,
      kAllRequiredFieldsSet = (kNamesSet | 0)
    };

    GlobalLexicalScopeNamesResultBuilder<STATE | kNamesSet>& SetNames(std::vector<std::string> value) {
      static_assert(!(STATE & kNamesSet), "property names should not have already been set");
      result_->SetNames(std::move(value));
      return CastState<kNamesSet>();
    }

    std::unique_ptr<GlobalLexicalScopeNamesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GlobalLexicalScopeNamesResult;
    GlobalLexicalScopeNamesResultBuilder() : result_(new GlobalLexicalScopeNamesResult()) { }

    template<int STEP> GlobalLexicalScopeNamesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GlobalLexicalScopeNamesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GlobalLexicalScopeNamesResult> result_;
  };

  static GlobalLexicalScopeNamesResultBuilder<0> Builder() {
    return GlobalLexicalScopeNamesResultBuilder<0>();
  }

 private:
  GlobalLexicalScopeNamesResult() { }

  std::vector<std::string> names_;

  DISALLOW_COPY_AND_ASSIGN(GlobalLexicalScopeNamesResult);
};


// Parameters for the QueryObjects command.
class HEADLESS_EXPORT QueryObjectsParams {
 public:
  static std::unique_ptr<QueryObjectsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~QueryObjectsParams() { }

  // Identifier of the prototype to return objects for.
  std::string GetPrototypeObjectId() const { return prototype_object_id_; }
  void SetPrototypeObjectId(const std::string& value) { prototype_object_id_ = value; }

  // Symbolic group name that can be used to release the results.
  bool HasObjectGroup() const { return !!object_group_; }
  std::string GetObjectGroup() const { DCHECK(HasObjectGroup()); return object_group_.value(); }
  void SetObjectGroup(const std::string& value) { object_group_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<QueryObjectsParams> Clone() const;

  template<int STATE>
  class QueryObjectsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPrototypeObjectIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kPrototypeObjectIdSet | 0)
    };

    QueryObjectsParamsBuilder<STATE | kPrototypeObjectIdSet>& SetPrototypeObjectId(const std::string& value) {
      static_assert(!(STATE & kPrototypeObjectIdSet), "property prototypeObjectId should not have already been set");
      result_->SetPrototypeObjectId(value);
      return CastState<kPrototypeObjectIdSet>();
    }

    QueryObjectsParamsBuilder<STATE>& SetObjectGroup(const std::string& value) {
      result_->SetObjectGroup(value);
      return *this;
    }

    std::unique_ptr<QueryObjectsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class QueryObjectsParams;
    QueryObjectsParamsBuilder() : result_(new QueryObjectsParams()) { }

    template<int STEP> QueryObjectsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<QueryObjectsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<QueryObjectsParams> result_;
  };

  static QueryObjectsParamsBuilder<0> Builder() {
    return QueryObjectsParamsBuilder<0>();
  }

 private:
  QueryObjectsParams() { }

  std::string prototype_object_id_;
  base::Optional<std::string> object_group_;

  DISALLOW_COPY_AND_ASSIGN(QueryObjectsParams);
};


// Result for the QueryObjects command.
class HEADLESS_EXPORT QueryObjectsResult {
 public:
  static std::unique_ptr<QueryObjectsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~QueryObjectsResult() { }

  // Array with objects.
  const ::headless::runtime::RemoteObject* GetObjects() const { return objects_.get(); }
  void SetObjects(std::unique_ptr<::headless::runtime::RemoteObject> value) { objects_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<QueryObjectsResult> Clone() const;

  template<int STATE>
  class QueryObjectsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectsSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectsSet | 0)
    };

    QueryObjectsResultBuilder<STATE | kObjectsSet>& SetObjects(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kObjectsSet), "property objects should not have already been set");
      result_->SetObjects(std::move(value));
      return CastState<kObjectsSet>();
    }

    std::unique_ptr<QueryObjectsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class QueryObjectsResult;
    QueryObjectsResultBuilder() : result_(new QueryObjectsResult()) { }

    template<int STEP> QueryObjectsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<QueryObjectsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<QueryObjectsResult> result_;
  };

  static QueryObjectsResultBuilder<0> Builder() {
    return QueryObjectsResultBuilder<0>();
  }

 private:
  QueryObjectsResult() { }

  std::unique_ptr<::headless::runtime::RemoteObject> objects_;

  DISALLOW_COPY_AND_ASSIGN(QueryObjectsResult);
};


// Parameters for the ReleaseObject command.
class HEADLESS_EXPORT ReleaseObjectParams {
 public:
  static std::unique_ptr<ReleaseObjectParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseObjectParams() { }

  // Identifier of the object to release.
  std::string GetObjectId() const { return object_id_; }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseObjectParams> Clone() const;

  template<int STATE>
  class ReleaseObjectParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectIdSet | 0)
    };

    ReleaseObjectParamsBuilder<STATE | kObjectIdSet>& SetObjectId(const std::string& value) {
      static_assert(!(STATE & kObjectIdSet), "property objectId should not have already been set");
      result_->SetObjectId(value);
      return CastState<kObjectIdSet>();
    }

    std::unique_ptr<ReleaseObjectParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseObjectParams;
    ReleaseObjectParamsBuilder() : result_(new ReleaseObjectParams()) { }

    template<int STEP> ReleaseObjectParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseObjectParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseObjectParams> result_;
  };

  static ReleaseObjectParamsBuilder<0> Builder() {
    return ReleaseObjectParamsBuilder<0>();
  }

 private:
  ReleaseObjectParams() { }

  std::string object_id_;

  DISALLOW_COPY_AND_ASSIGN(ReleaseObjectParams);
};


// Result for the ReleaseObject command.
class HEADLESS_EXPORT ReleaseObjectResult {
 public:
  static std::unique_ptr<ReleaseObjectResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseObjectResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseObjectResult> Clone() const;

  template<int STATE>
  class ReleaseObjectResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ReleaseObjectResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseObjectResult;
    ReleaseObjectResultBuilder() : result_(new ReleaseObjectResult()) { }

    template<int STEP> ReleaseObjectResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseObjectResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseObjectResult> result_;
  };

  static ReleaseObjectResultBuilder<0> Builder() {
    return ReleaseObjectResultBuilder<0>();
  }

 private:
  ReleaseObjectResult() { }


  DISALLOW_COPY_AND_ASSIGN(ReleaseObjectResult);
};


// Parameters for the ReleaseObjectGroup command.
class HEADLESS_EXPORT ReleaseObjectGroupParams {
 public:
  static std::unique_ptr<ReleaseObjectGroupParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseObjectGroupParams() { }

  // Symbolic object group name.
  std::string GetObjectGroup() const { return object_group_; }
  void SetObjectGroup(const std::string& value) { object_group_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseObjectGroupParams> Clone() const;

  template<int STATE>
  class ReleaseObjectGroupParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectGroupSet = 1 << 1,
      kAllRequiredFieldsSet = (kObjectGroupSet | 0)
    };

    ReleaseObjectGroupParamsBuilder<STATE | kObjectGroupSet>& SetObjectGroup(const std::string& value) {
      static_assert(!(STATE & kObjectGroupSet), "property objectGroup should not have already been set");
      result_->SetObjectGroup(value);
      return CastState<kObjectGroupSet>();
    }

    std::unique_ptr<ReleaseObjectGroupParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseObjectGroupParams;
    ReleaseObjectGroupParamsBuilder() : result_(new ReleaseObjectGroupParams()) { }

    template<int STEP> ReleaseObjectGroupParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseObjectGroupParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseObjectGroupParams> result_;
  };

  static ReleaseObjectGroupParamsBuilder<0> Builder() {
    return ReleaseObjectGroupParamsBuilder<0>();
  }

 private:
  ReleaseObjectGroupParams() { }

  std::string object_group_;

  DISALLOW_COPY_AND_ASSIGN(ReleaseObjectGroupParams);
};


// Result for the ReleaseObjectGroup command.
class HEADLESS_EXPORT ReleaseObjectGroupResult {
 public:
  static std::unique_ptr<ReleaseObjectGroupResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseObjectGroupResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseObjectGroupResult> Clone() const;

  template<int STATE>
  class ReleaseObjectGroupResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ReleaseObjectGroupResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseObjectGroupResult;
    ReleaseObjectGroupResultBuilder() : result_(new ReleaseObjectGroupResult()) { }

    template<int STEP> ReleaseObjectGroupResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseObjectGroupResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseObjectGroupResult> result_;
  };

  static ReleaseObjectGroupResultBuilder<0> Builder() {
    return ReleaseObjectGroupResultBuilder<0>();
  }

 private:
  ReleaseObjectGroupResult() { }


  DISALLOW_COPY_AND_ASSIGN(ReleaseObjectGroupResult);
};


// Parameters for the RunIfWaitingForDebugger command.
class HEADLESS_EXPORT RunIfWaitingForDebuggerParams {
 public:
  static std::unique_ptr<RunIfWaitingForDebuggerParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RunIfWaitingForDebuggerParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RunIfWaitingForDebuggerParams> Clone() const;

  template<int STATE>
  class RunIfWaitingForDebuggerParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RunIfWaitingForDebuggerParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RunIfWaitingForDebuggerParams;
    RunIfWaitingForDebuggerParamsBuilder() : result_(new RunIfWaitingForDebuggerParams()) { }

    template<int STEP> RunIfWaitingForDebuggerParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RunIfWaitingForDebuggerParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RunIfWaitingForDebuggerParams> result_;
  };

  static RunIfWaitingForDebuggerParamsBuilder<0> Builder() {
    return RunIfWaitingForDebuggerParamsBuilder<0>();
  }

 private:
  RunIfWaitingForDebuggerParams() { }


  DISALLOW_COPY_AND_ASSIGN(RunIfWaitingForDebuggerParams);
};


// Result for the RunIfWaitingForDebugger command.
class HEADLESS_EXPORT RunIfWaitingForDebuggerResult {
 public:
  static std::unique_ptr<RunIfWaitingForDebuggerResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RunIfWaitingForDebuggerResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RunIfWaitingForDebuggerResult> Clone() const;

  template<int STATE>
  class RunIfWaitingForDebuggerResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RunIfWaitingForDebuggerResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RunIfWaitingForDebuggerResult;
    RunIfWaitingForDebuggerResultBuilder() : result_(new RunIfWaitingForDebuggerResult()) { }

    template<int STEP> RunIfWaitingForDebuggerResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RunIfWaitingForDebuggerResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RunIfWaitingForDebuggerResult> result_;
  };

  static RunIfWaitingForDebuggerResultBuilder<0> Builder() {
    return RunIfWaitingForDebuggerResultBuilder<0>();
  }

 private:
  RunIfWaitingForDebuggerResult() { }


  DISALLOW_COPY_AND_ASSIGN(RunIfWaitingForDebuggerResult);
};


// Parameters for the RunScript command.
class HEADLESS_EXPORT RunScriptParams {
 public:
  static std::unique_ptr<RunScriptParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RunScriptParams() { }

  // Id of the script to run.
  std::string GetScriptId() const { return script_id_; }
  void SetScriptId(const std::string& value) { script_id_ = value; }

  // Specifies in which execution context to perform script run. If the parameter is omitted the
  // evaluation will be performed in the context of the inspected page.
  bool HasExecutionContextId() const { return !!execution_context_id_; }
  int GetExecutionContextId() const { DCHECK(HasExecutionContextId()); return execution_context_id_.value(); }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  // Symbolic group name that can be used to release multiple objects.
  bool HasObjectGroup() const { return !!object_group_; }
  std::string GetObjectGroup() const { DCHECK(HasObjectGroup()); return object_group_.value(); }
  void SetObjectGroup(const std::string& value) { object_group_ = value; }

  // In silent mode exceptions thrown during evaluation are not reported and do not pause
  // execution. Overrides `setPauseOnException` state.
  bool HasSilent() const { return !!silent_; }
  bool GetSilent() const { DCHECK(HasSilent()); return silent_.value(); }
  void SetSilent(bool value) { silent_ = value; }

  // Determines whether Command Line API should be available during the evaluation.
  bool HasIncludeCommandLineAPI() const { return !!include_command_lineapi_; }
  bool GetIncludeCommandLineAPI() const { DCHECK(HasIncludeCommandLineAPI()); return include_command_lineapi_.value(); }
  void SetIncludeCommandLineAPI(bool value) { include_command_lineapi_ = value; }

  // Whether the result is expected to be a JSON object which should be sent by value.
  bool HasReturnByValue() const { return !!return_by_value_; }
  bool GetReturnByValue() const { DCHECK(HasReturnByValue()); return return_by_value_.value(); }
  void SetReturnByValue(bool value) { return_by_value_ = value; }

  // Whether preview should be generated for the result.
  bool HasGeneratePreview() const { return !!generate_preview_; }
  bool GetGeneratePreview() const { DCHECK(HasGeneratePreview()); return generate_preview_.value(); }
  void SetGeneratePreview(bool value) { generate_preview_ = value; }

  // Whether execution should `await` for resulting value and return once awaited promise is
  // resolved.
  bool HasAwaitPromise() const { return !!await_promise_; }
  bool GetAwaitPromise() const { DCHECK(HasAwaitPromise()); return await_promise_.value(); }
  void SetAwaitPromise(bool value) { await_promise_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RunScriptParams> Clone() const;

  template<int STATE>
  class RunScriptParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kScriptIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kScriptIdSet | 0)
    };

    RunScriptParamsBuilder<STATE | kScriptIdSet>& SetScriptId(const std::string& value) {
      static_assert(!(STATE & kScriptIdSet), "property scriptId should not have already been set");
      result_->SetScriptId(value);
      return CastState<kScriptIdSet>();
    }

    RunScriptParamsBuilder<STATE>& SetExecutionContextId(int value) {
      result_->SetExecutionContextId(value);
      return *this;
    }

    RunScriptParamsBuilder<STATE>& SetObjectGroup(const std::string& value) {
      result_->SetObjectGroup(value);
      return *this;
    }

    RunScriptParamsBuilder<STATE>& SetSilent(bool value) {
      result_->SetSilent(value);
      return *this;
    }

    RunScriptParamsBuilder<STATE>& SetIncludeCommandLineAPI(bool value) {
      result_->SetIncludeCommandLineAPI(value);
      return *this;
    }

    RunScriptParamsBuilder<STATE>& SetReturnByValue(bool value) {
      result_->SetReturnByValue(value);
      return *this;
    }

    RunScriptParamsBuilder<STATE>& SetGeneratePreview(bool value) {
      result_->SetGeneratePreview(value);
      return *this;
    }

    RunScriptParamsBuilder<STATE>& SetAwaitPromise(bool value) {
      result_->SetAwaitPromise(value);
      return *this;
    }

    std::unique_ptr<RunScriptParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RunScriptParams;
    RunScriptParamsBuilder() : result_(new RunScriptParams()) { }

    template<int STEP> RunScriptParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RunScriptParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RunScriptParams> result_;
  };

  static RunScriptParamsBuilder<0> Builder() {
    return RunScriptParamsBuilder<0>();
  }

 private:
  RunScriptParams() { }

  std::string script_id_;
  base::Optional<int> execution_context_id_;
  base::Optional<std::string> object_group_;
  base::Optional<bool> silent_;
  base::Optional<bool> include_command_lineapi_;
  base::Optional<bool> return_by_value_;
  base::Optional<bool> generate_preview_;
  base::Optional<bool> await_promise_;

  DISALLOW_COPY_AND_ASSIGN(RunScriptParams);
};


// Result for the RunScript command.
class HEADLESS_EXPORT RunScriptResult {
 public:
  static std::unique_ptr<RunScriptResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RunScriptResult() { }

  // Run result.
  const ::headless::runtime::RemoteObject* GetResult() const { return result_.get(); }
  void SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) { result_ = std::move(value); }

  // Exception details.
  bool HasExceptionDetails() const { return !!exception_details_; }
  const ::headless::runtime::ExceptionDetails* GetExceptionDetails() const { DCHECK(HasExceptionDetails()); return exception_details_.value().get(); }
  void SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) { exception_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RunScriptResult> Clone() const;

  template<int STATE>
  class RunScriptResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    RunScriptResultBuilder<STATE | kResultSet>& SetResult(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    RunScriptResultBuilder<STATE>& SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) {
      result_->SetExceptionDetails(std::move(value));
      return *this;
    }

    std::unique_ptr<RunScriptResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RunScriptResult;
    RunScriptResultBuilder() : result_(new RunScriptResult()) { }

    template<int STEP> RunScriptResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RunScriptResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RunScriptResult> result_;
  };

  static RunScriptResultBuilder<0> Builder() {
    return RunScriptResultBuilder<0>();
  }

 private:
  RunScriptResult() { }

  std::unique_ptr<::headless::runtime::RemoteObject> result_;
  base::Optional<std::unique_ptr<::headless::runtime::ExceptionDetails>> exception_details_;

  DISALLOW_COPY_AND_ASSIGN(RunScriptResult);
};


// Parameters for the SetAsyncCallStackDepth command.
class HEADLESS_EXPORT SetAsyncCallStackDepthParams {
 public:
  static std::unique_ptr<SetAsyncCallStackDepthParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAsyncCallStackDepthParams() { }

  // Maximum depth of async call stacks. Setting to `0` will effectively disable collecting async
  // call stacks (default).
  int GetMaxDepth() const { return max_depth_; }
  void SetMaxDepth(int value) { max_depth_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAsyncCallStackDepthParams> Clone() const;

  template<int STATE>
  class SetAsyncCallStackDepthParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMaxDepthSet = 1 << 1,
      kAllRequiredFieldsSet = (kMaxDepthSet | 0)
    };

    SetAsyncCallStackDepthParamsBuilder<STATE | kMaxDepthSet>& SetMaxDepth(int value) {
      static_assert(!(STATE & kMaxDepthSet), "property maxDepth should not have already been set");
      result_->SetMaxDepth(value);
      return CastState<kMaxDepthSet>();
    }

    std::unique_ptr<SetAsyncCallStackDepthParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAsyncCallStackDepthParams;
    SetAsyncCallStackDepthParamsBuilder() : result_(new SetAsyncCallStackDepthParams()) { }

    template<int STEP> SetAsyncCallStackDepthParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAsyncCallStackDepthParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAsyncCallStackDepthParams> result_;
  };

  static SetAsyncCallStackDepthParamsBuilder<0> Builder() {
    return SetAsyncCallStackDepthParamsBuilder<0>();
  }

 private:
  SetAsyncCallStackDepthParams() { }

  int max_depth_;

  DISALLOW_COPY_AND_ASSIGN(SetAsyncCallStackDepthParams);
};


// Result for the SetAsyncCallStackDepth command.
class HEADLESS_EXPORT SetAsyncCallStackDepthResult {
 public:
  static std::unique_ptr<SetAsyncCallStackDepthResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAsyncCallStackDepthResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAsyncCallStackDepthResult> Clone() const;

  template<int STATE>
  class SetAsyncCallStackDepthResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetAsyncCallStackDepthResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAsyncCallStackDepthResult;
    SetAsyncCallStackDepthResultBuilder() : result_(new SetAsyncCallStackDepthResult()) { }

    template<int STEP> SetAsyncCallStackDepthResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAsyncCallStackDepthResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAsyncCallStackDepthResult> result_;
  };

  static SetAsyncCallStackDepthResultBuilder<0> Builder() {
    return SetAsyncCallStackDepthResultBuilder<0>();
  }

 private:
  SetAsyncCallStackDepthResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetAsyncCallStackDepthResult);
};


// Parameters for the SetCustomObjectFormatterEnabled command.
class HEADLESS_EXPORT SetCustomObjectFormatterEnabledParams {
 public:
  static std::unique_ptr<SetCustomObjectFormatterEnabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCustomObjectFormatterEnabledParams() { }

  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCustomObjectFormatterEnabledParams> Clone() const;

  template<int STATE>
  class SetCustomObjectFormatterEnabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetCustomObjectFormatterEnabledParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    std::unique_ptr<SetCustomObjectFormatterEnabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCustomObjectFormatterEnabledParams;
    SetCustomObjectFormatterEnabledParamsBuilder() : result_(new SetCustomObjectFormatterEnabledParams()) { }

    template<int STEP> SetCustomObjectFormatterEnabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCustomObjectFormatterEnabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCustomObjectFormatterEnabledParams> result_;
  };

  static SetCustomObjectFormatterEnabledParamsBuilder<0> Builder() {
    return SetCustomObjectFormatterEnabledParamsBuilder<0>();
  }

 private:
  SetCustomObjectFormatterEnabledParams() { }

  bool enabled_;

  DISALLOW_COPY_AND_ASSIGN(SetCustomObjectFormatterEnabledParams);
};


// Result for the SetCustomObjectFormatterEnabled command.
class HEADLESS_EXPORT SetCustomObjectFormatterEnabledResult {
 public:
  static std::unique_ptr<SetCustomObjectFormatterEnabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetCustomObjectFormatterEnabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetCustomObjectFormatterEnabledResult> Clone() const;

  template<int STATE>
  class SetCustomObjectFormatterEnabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetCustomObjectFormatterEnabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetCustomObjectFormatterEnabledResult;
    SetCustomObjectFormatterEnabledResultBuilder() : result_(new SetCustomObjectFormatterEnabledResult()) { }

    template<int STEP> SetCustomObjectFormatterEnabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetCustomObjectFormatterEnabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetCustomObjectFormatterEnabledResult> result_;
  };

  static SetCustomObjectFormatterEnabledResultBuilder<0> Builder() {
    return SetCustomObjectFormatterEnabledResultBuilder<0>();
  }

 private:
  SetCustomObjectFormatterEnabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetCustomObjectFormatterEnabledResult);
};


// Parameters for the SetMaxCallStackSizeToCapture command.
class HEADLESS_EXPORT SetMaxCallStackSizeToCaptureParams {
 public:
  static std::unique_ptr<SetMaxCallStackSizeToCaptureParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetMaxCallStackSizeToCaptureParams() { }

  int GetSize() const { return size_; }
  void SetSize(int value) { size_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetMaxCallStackSizeToCaptureParams> Clone() const;

  template<int STATE>
  class SetMaxCallStackSizeToCaptureParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSizeSet = 1 << 1,
      kAllRequiredFieldsSet = (kSizeSet | 0)
    };

    SetMaxCallStackSizeToCaptureParamsBuilder<STATE | kSizeSet>& SetSize(int value) {
      static_assert(!(STATE & kSizeSet), "property size should not have already been set");
      result_->SetSize(value);
      return CastState<kSizeSet>();
    }

    std::unique_ptr<SetMaxCallStackSizeToCaptureParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetMaxCallStackSizeToCaptureParams;
    SetMaxCallStackSizeToCaptureParamsBuilder() : result_(new SetMaxCallStackSizeToCaptureParams()) { }

    template<int STEP> SetMaxCallStackSizeToCaptureParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetMaxCallStackSizeToCaptureParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetMaxCallStackSizeToCaptureParams> result_;
  };

  static SetMaxCallStackSizeToCaptureParamsBuilder<0> Builder() {
    return SetMaxCallStackSizeToCaptureParamsBuilder<0>();
  }

 private:
  SetMaxCallStackSizeToCaptureParams() { }

  int size_;

  DISALLOW_COPY_AND_ASSIGN(SetMaxCallStackSizeToCaptureParams);
};


// Result for the SetMaxCallStackSizeToCapture command.
class HEADLESS_EXPORT SetMaxCallStackSizeToCaptureResult {
 public:
  static std::unique_ptr<SetMaxCallStackSizeToCaptureResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetMaxCallStackSizeToCaptureResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetMaxCallStackSizeToCaptureResult> Clone() const;

  template<int STATE>
  class SetMaxCallStackSizeToCaptureResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetMaxCallStackSizeToCaptureResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetMaxCallStackSizeToCaptureResult;
    SetMaxCallStackSizeToCaptureResultBuilder() : result_(new SetMaxCallStackSizeToCaptureResult()) { }

    template<int STEP> SetMaxCallStackSizeToCaptureResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetMaxCallStackSizeToCaptureResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetMaxCallStackSizeToCaptureResult> result_;
  };

  static SetMaxCallStackSizeToCaptureResultBuilder<0> Builder() {
    return SetMaxCallStackSizeToCaptureResultBuilder<0>();
  }

 private:
  SetMaxCallStackSizeToCaptureResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetMaxCallStackSizeToCaptureResult);
};


// Parameters for the TerminateExecution command.
class HEADLESS_EXPORT TerminateExecutionParams {
 public:
  static std::unique_ptr<TerminateExecutionParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TerminateExecutionParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TerminateExecutionParams> Clone() const;

  template<int STATE>
  class TerminateExecutionParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<TerminateExecutionParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TerminateExecutionParams;
    TerminateExecutionParamsBuilder() : result_(new TerminateExecutionParams()) { }

    template<int STEP> TerminateExecutionParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TerminateExecutionParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TerminateExecutionParams> result_;
  };

  static TerminateExecutionParamsBuilder<0> Builder() {
    return TerminateExecutionParamsBuilder<0>();
  }

 private:
  TerminateExecutionParams() { }


  DISALLOW_COPY_AND_ASSIGN(TerminateExecutionParams);
};


// Result for the TerminateExecution command.
class HEADLESS_EXPORT TerminateExecutionResult {
 public:
  static std::unique_ptr<TerminateExecutionResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~TerminateExecutionResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TerminateExecutionResult> Clone() const;

  template<int STATE>
  class TerminateExecutionResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<TerminateExecutionResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TerminateExecutionResult;
    TerminateExecutionResultBuilder() : result_(new TerminateExecutionResult()) { }

    template<int STEP> TerminateExecutionResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TerminateExecutionResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TerminateExecutionResult> result_;
  };

  static TerminateExecutionResultBuilder<0> Builder() {
    return TerminateExecutionResultBuilder<0>();
  }

 private:
  TerminateExecutionResult() { }


  DISALLOW_COPY_AND_ASSIGN(TerminateExecutionResult);
};


// Parameters for the AddBinding command.
class HEADLESS_EXPORT AddBindingParams {
 public:
  static std::unique_ptr<AddBindingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddBindingParams() { }

  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  bool HasExecutionContextId() const { return !!execution_context_id_; }
  int GetExecutionContextId() const { DCHECK(HasExecutionContextId()); return execution_context_id_.value(); }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddBindingParams> Clone() const;

  template<int STATE>
  class AddBindingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
      kAllRequiredFieldsSet = (kNameSet | 0)
    };

    AddBindingParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    AddBindingParamsBuilder<STATE>& SetExecutionContextId(int value) {
      result_->SetExecutionContextId(value);
      return *this;
    }

    std::unique_ptr<AddBindingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddBindingParams;
    AddBindingParamsBuilder() : result_(new AddBindingParams()) { }

    template<int STEP> AddBindingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddBindingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddBindingParams> result_;
  };

  static AddBindingParamsBuilder<0> Builder() {
    return AddBindingParamsBuilder<0>();
  }

 private:
  AddBindingParams() { }

  std::string name_;
  base::Optional<int> execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(AddBindingParams);
};


// Result for the AddBinding command.
class HEADLESS_EXPORT AddBindingResult {
 public:
  static std::unique_ptr<AddBindingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddBindingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddBindingResult> Clone() const;

  template<int STATE>
  class AddBindingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<AddBindingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddBindingResult;
    AddBindingResultBuilder() : result_(new AddBindingResult()) { }

    template<int STEP> AddBindingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddBindingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddBindingResult> result_;
  };

  static AddBindingResultBuilder<0> Builder() {
    return AddBindingResultBuilder<0>();
  }

 private:
  AddBindingResult() { }


  DISALLOW_COPY_AND_ASSIGN(AddBindingResult);
};


// Parameters for the RemoveBinding command.
class HEADLESS_EXPORT RemoveBindingParams {
 public:
  static std::unique_ptr<RemoveBindingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveBindingParams() { }

  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveBindingParams> Clone() const;

  template<int STATE>
  class RemoveBindingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
      kAllRequiredFieldsSet = (kNameSet | 0)
    };

    RemoveBindingParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    std::unique_ptr<RemoveBindingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveBindingParams;
    RemoveBindingParamsBuilder() : result_(new RemoveBindingParams()) { }

    template<int STEP> RemoveBindingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveBindingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveBindingParams> result_;
  };

  static RemoveBindingParamsBuilder<0> Builder() {
    return RemoveBindingParamsBuilder<0>();
  }

 private:
  RemoveBindingParams() { }

  std::string name_;

  DISALLOW_COPY_AND_ASSIGN(RemoveBindingParams);
};


// Result for the RemoveBinding command.
class HEADLESS_EXPORT RemoveBindingResult {
 public:
  static std::unique_ptr<RemoveBindingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveBindingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveBindingResult> Clone() const;

  template<int STATE>
  class RemoveBindingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RemoveBindingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveBindingResult;
    RemoveBindingResultBuilder() : result_(new RemoveBindingResult()) { }

    template<int STEP> RemoveBindingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveBindingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveBindingResult> result_;
  };

  static RemoveBindingResultBuilder<0> Builder() {
    return RemoveBindingResultBuilder<0>();
  }

 private:
  RemoveBindingResult() { }


  DISALLOW_COPY_AND_ASSIGN(RemoveBindingResult);
};


// Parameters for the BindingCalled event.
class HEADLESS_EXPORT BindingCalledParams {
 public:
  static std::unique_ptr<BindingCalledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~BindingCalledParams() { }

  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  std::string GetPayload() const { return payload_; }
  void SetPayload(const std::string& value) { payload_ = value; }

  // Identifier of the context where the call was made.
  int GetExecutionContextId() const { return execution_context_id_; }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BindingCalledParams> Clone() const;

  template<int STATE>
  class BindingCalledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kPayloadSet = 1 << 2,
    kExecutionContextIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kNameSet | kPayloadSet | kExecutionContextIdSet | 0)
    };

    BindingCalledParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    BindingCalledParamsBuilder<STATE | kPayloadSet>& SetPayload(const std::string& value) {
      static_assert(!(STATE & kPayloadSet), "property payload should not have already been set");
      result_->SetPayload(value);
      return CastState<kPayloadSet>();
    }

    BindingCalledParamsBuilder<STATE | kExecutionContextIdSet>& SetExecutionContextId(int value) {
      static_assert(!(STATE & kExecutionContextIdSet), "property executionContextId should not have already been set");
      result_->SetExecutionContextId(value);
      return CastState<kExecutionContextIdSet>();
    }

    std::unique_ptr<BindingCalledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BindingCalledParams;
    BindingCalledParamsBuilder() : result_(new BindingCalledParams()) { }

    template<int STEP> BindingCalledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BindingCalledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BindingCalledParams> result_;
  };

  static BindingCalledParamsBuilder<0> Builder() {
    return BindingCalledParamsBuilder<0>();
  }

 private:
  BindingCalledParams() { }

  std::string name_;
  std::string payload_;
  int execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(BindingCalledParams);
};


// Parameters for the ConsoleAPICalled event.
class HEADLESS_EXPORT ConsoleAPICalledParams {
 public:
  static std::unique_ptr<ConsoleAPICalledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ConsoleAPICalledParams() { }

  // Type of the call.
  ::headless::runtime::ConsoleAPICalledType GetType() const { return type_; }
  void SetType(::headless::runtime::ConsoleAPICalledType value) { type_ = value; }

  // Call arguments.
  const std::vector<std::unique_ptr<::headless::runtime::RemoteObject>>* GetArgs() const { return &args_; }
  void SetArgs(std::vector<std::unique_ptr<::headless::runtime::RemoteObject>> value) { args_ = std::move(value); }

  // Identifier of the context where the call was made.
  int GetExecutionContextId() const { return execution_context_id_; }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  // Call timestamp.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // Stack trace captured when the call was made. The async stack chain is automatically reported for
  // the following call types: `assert`, `error`, `trace`, `warning`. For other types the async call
  // chain can be retrieved using `Debugger.getStackTrace` and `stackTrace.parentId` field.
  bool HasStackTrace() const { return !!stack_trace_; }
  const ::headless::runtime::StackTrace* GetStackTrace() const { DCHECK(HasStackTrace()); return stack_trace_.value().get(); }
  void SetStackTrace(std::unique_ptr<::headless::runtime::StackTrace> value) { stack_trace_ = std::move(value); }

  // Console context descriptor for calls on non-default console context (not console.*):
  // 'anonymous#unique-logger-id' for call on unnamed context, 'name#unique-logger-id' for call
  // on named context.
  bool HasContext() const { return !!context_; }
  std::string GetContext() const { DCHECK(HasContext()); return context_.value(); }
  void SetContext(const std::string& value) { context_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ConsoleAPICalledParams> Clone() const;

  template<int STATE>
  class ConsoleAPICalledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kArgsSet = 1 << 2,
    kExecutionContextIdSet = 1 << 3,
    kTimestampSet = 1 << 4,
      kAllRequiredFieldsSet = (kTypeSet | kArgsSet | kExecutionContextIdSet | kTimestampSet | 0)
    };

    ConsoleAPICalledParamsBuilder<STATE | kTypeSet>& SetType(::headless::runtime::ConsoleAPICalledType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    ConsoleAPICalledParamsBuilder<STATE | kArgsSet>& SetArgs(std::vector<std::unique_ptr<::headless::runtime::RemoteObject>> value) {
      static_assert(!(STATE & kArgsSet), "property args should not have already been set");
      result_->SetArgs(std::move(value));
      return CastState<kArgsSet>();
    }

    ConsoleAPICalledParamsBuilder<STATE | kExecutionContextIdSet>& SetExecutionContextId(int value) {
      static_assert(!(STATE & kExecutionContextIdSet), "property executionContextId should not have already been set");
      result_->SetExecutionContextId(value);
      return CastState<kExecutionContextIdSet>();
    }

    ConsoleAPICalledParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    ConsoleAPICalledParamsBuilder<STATE>& SetStackTrace(std::unique_ptr<::headless::runtime::StackTrace> value) {
      result_->SetStackTrace(std::move(value));
      return *this;
    }

    ConsoleAPICalledParamsBuilder<STATE>& SetContext(const std::string& value) {
      result_->SetContext(value);
      return *this;
    }

    std::unique_ptr<ConsoleAPICalledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ConsoleAPICalledParams;
    ConsoleAPICalledParamsBuilder() : result_(new ConsoleAPICalledParams()) { }

    template<int STEP> ConsoleAPICalledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ConsoleAPICalledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ConsoleAPICalledParams> result_;
  };

  static ConsoleAPICalledParamsBuilder<0> Builder() {
    return ConsoleAPICalledParamsBuilder<0>();
  }

 private:
  ConsoleAPICalledParams() { }

  ::headless::runtime::ConsoleAPICalledType type_;
  std::vector<std::unique_ptr<::headless::runtime::RemoteObject>> args_;
  int execution_context_id_;
  double timestamp_;
  base::Optional<std::unique_ptr<::headless::runtime::StackTrace>> stack_trace_;
  base::Optional<std::string> context_;

  DISALLOW_COPY_AND_ASSIGN(ConsoleAPICalledParams);
};


// Parameters for the ExceptionRevoked event.
class HEADLESS_EXPORT ExceptionRevokedParams {
 public:
  static std::unique_ptr<ExceptionRevokedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExceptionRevokedParams() { }

  // Reason describing why exception was revoked.
  std::string GetReason() const { return reason_; }
  void SetReason(const std::string& value) { reason_ = value; }

  // The id of revoked exception, as reported in `exceptionThrown`.
  int GetExceptionId() const { return exception_id_; }
  void SetExceptionId(int value) { exception_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExceptionRevokedParams> Clone() const;

  template<int STATE>
  class ExceptionRevokedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kReasonSet = 1 << 1,
    kExceptionIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kReasonSet | kExceptionIdSet | 0)
    };

    ExceptionRevokedParamsBuilder<STATE | kReasonSet>& SetReason(const std::string& value) {
      static_assert(!(STATE & kReasonSet), "property reason should not have already been set");
      result_->SetReason(value);
      return CastState<kReasonSet>();
    }

    ExceptionRevokedParamsBuilder<STATE | kExceptionIdSet>& SetExceptionId(int value) {
      static_assert(!(STATE & kExceptionIdSet), "property exceptionId should not have already been set");
      result_->SetExceptionId(value);
      return CastState<kExceptionIdSet>();
    }

    std::unique_ptr<ExceptionRevokedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExceptionRevokedParams;
    ExceptionRevokedParamsBuilder() : result_(new ExceptionRevokedParams()) { }

    template<int STEP> ExceptionRevokedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExceptionRevokedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExceptionRevokedParams> result_;
  };

  static ExceptionRevokedParamsBuilder<0> Builder() {
    return ExceptionRevokedParamsBuilder<0>();
  }

 private:
  ExceptionRevokedParams() { }

  std::string reason_;
  int exception_id_;

  DISALLOW_COPY_AND_ASSIGN(ExceptionRevokedParams);
};


// Parameters for the ExceptionThrown event.
class HEADLESS_EXPORT ExceptionThrownParams {
 public:
  static std::unique_ptr<ExceptionThrownParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExceptionThrownParams() { }

  // Timestamp of the exception.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  const ::headless::runtime::ExceptionDetails* GetExceptionDetails() const { return exception_details_.get(); }
  void SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) { exception_details_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExceptionThrownParams> Clone() const;

  template<int STATE>
  class ExceptionThrownParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimestampSet = 1 << 1,
    kExceptionDetailsSet = 1 << 2,
      kAllRequiredFieldsSet = (kTimestampSet | kExceptionDetailsSet | 0)
    };

    ExceptionThrownParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    ExceptionThrownParamsBuilder<STATE | kExceptionDetailsSet>& SetExceptionDetails(std::unique_ptr<::headless::runtime::ExceptionDetails> value) {
      static_assert(!(STATE & kExceptionDetailsSet), "property exceptionDetails should not have already been set");
      result_->SetExceptionDetails(std::move(value));
      return CastState<kExceptionDetailsSet>();
    }

    std::unique_ptr<ExceptionThrownParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExceptionThrownParams;
    ExceptionThrownParamsBuilder() : result_(new ExceptionThrownParams()) { }

    template<int STEP> ExceptionThrownParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExceptionThrownParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExceptionThrownParams> result_;
  };

  static ExceptionThrownParamsBuilder<0> Builder() {
    return ExceptionThrownParamsBuilder<0>();
  }

 private:
  ExceptionThrownParams() { }

  double timestamp_;
  std::unique_ptr<::headless::runtime::ExceptionDetails> exception_details_;

  DISALLOW_COPY_AND_ASSIGN(ExceptionThrownParams);
};


// Parameters for the ExecutionContextCreated event.
class HEADLESS_EXPORT ExecutionContextCreatedParams {
 public:
  static std::unique_ptr<ExecutionContextCreatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExecutionContextCreatedParams() { }

  // A newly created execution context.
  const ::headless::runtime::ExecutionContextDescription* GetContext() const { return context_.get(); }
  void SetContext(std::unique_ptr<::headless::runtime::ExecutionContextDescription> value) { context_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExecutionContextCreatedParams> Clone() const;

  template<int STATE>
  class ExecutionContextCreatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContextSet = 1 << 1,
      kAllRequiredFieldsSet = (kContextSet | 0)
    };

    ExecutionContextCreatedParamsBuilder<STATE | kContextSet>& SetContext(std::unique_ptr<::headless::runtime::ExecutionContextDescription> value) {
      static_assert(!(STATE & kContextSet), "property context should not have already been set");
      result_->SetContext(std::move(value));
      return CastState<kContextSet>();
    }

    std::unique_ptr<ExecutionContextCreatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExecutionContextCreatedParams;
    ExecutionContextCreatedParamsBuilder() : result_(new ExecutionContextCreatedParams()) { }

    template<int STEP> ExecutionContextCreatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExecutionContextCreatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExecutionContextCreatedParams> result_;
  };

  static ExecutionContextCreatedParamsBuilder<0> Builder() {
    return ExecutionContextCreatedParamsBuilder<0>();
  }

 private:
  ExecutionContextCreatedParams() { }

  std::unique_ptr<::headless::runtime::ExecutionContextDescription> context_;

  DISALLOW_COPY_AND_ASSIGN(ExecutionContextCreatedParams);
};


// Parameters for the ExecutionContextDestroyed event.
class HEADLESS_EXPORT ExecutionContextDestroyedParams {
 public:
  static std::unique_ptr<ExecutionContextDestroyedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExecutionContextDestroyedParams() { }

  // Id of the destroyed context
  int GetExecutionContextId() const { return execution_context_id_; }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExecutionContextDestroyedParams> Clone() const;

  template<int STATE>
  class ExecutionContextDestroyedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kExecutionContextIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kExecutionContextIdSet | 0)
    };

    ExecutionContextDestroyedParamsBuilder<STATE | kExecutionContextIdSet>& SetExecutionContextId(int value) {
      static_assert(!(STATE & kExecutionContextIdSet), "property executionContextId should not have already been set");
      result_->SetExecutionContextId(value);
      return CastState<kExecutionContextIdSet>();
    }

    std::unique_ptr<ExecutionContextDestroyedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExecutionContextDestroyedParams;
    ExecutionContextDestroyedParamsBuilder() : result_(new ExecutionContextDestroyedParams()) { }

    template<int STEP> ExecutionContextDestroyedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExecutionContextDestroyedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExecutionContextDestroyedParams> result_;
  };

  static ExecutionContextDestroyedParamsBuilder<0> Builder() {
    return ExecutionContextDestroyedParamsBuilder<0>();
  }

 private:
  ExecutionContextDestroyedParams() { }

  int execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(ExecutionContextDestroyedParams);
};


// Parameters for the ExecutionContextsCleared event.
class HEADLESS_EXPORT ExecutionContextsClearedParams {
 public:
  static std::unique_ptr<ExecutionContextsClearedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ExecutionContextsClearedParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ExecutionContextsClearedParams> Clone() const;

  template<int STATE>
  class ExecutionContextsClearedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ExecutionContextsClearedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ExecutionContextsClearedParams;
    ExecutionContextsClearedParamsBuilder() : result_(new ExecutionContextsClearedParams()) { }

    template<int STEP> ExecutionContextsClearedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ExecutionContextsClearedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ExecutionContextsClearedParams> result_;
  };

  static ExecutionContextsClearedParamsBuilder<0> Builder() {
    return ExecutionContextsClearedParamsBuilder<0>();
  }

 private:
  ExecutionContextsClearedParams() { }


  DISALLOW_COPY_AND_ASSIGN(ExecutionContextsClearedParams);
};


// Parameters for the InspectRequested event.
class HEADLESS_EXPORT InspectRequestedParams {
 public:
  static std::unique_ptr<InspectRequestedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~InspectRequestedParams() { }

  const ::headless::runtime::RemoteObject* GetObject() const { return object_.get(); }
  void SetObject(std::unique_ptr<::headless::runtime::RemoteObject> value) { object_ = std::move(value); }

  const base::Value* GetHints() const { return hints_.get(); }
  void SetHints(std::unique_ptr<base::Value> value) { hints_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InspectRequestedParams> Clone() const;

  template<int STATE>
  class InspectRequestedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kObjectSet = 1 << 1,
    kHintsSet = 1 << 2,
      kAllRequiredFieldsSet = (kObjectSet | kHintsSet | 0)
    };

    InspectRequestedParamsBuilder<STATE | kObjectSet>& SetObject(std::unique_ptr<::headless::runtime::RemoteObject> value) {
      static_assert(!(STATE & kObjectSet), "property object should not have already been set");
      result_->SetObject(std::move(value));
      return CastState<kObjectSet>();
    }

    InspectRequestedParamsBuilder<STATE | kHintsSet>& SetHints(std::unique_ptr<base::Value> value) {
      static_assert(!(STATE & kHintsSet), "property hints should not have already been set");
      result_->SetHints(std::move(value));
      return CastState<kHintsSet>();
    }

    std::unique_ptr<InspectRequestedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InspectRequestedParams;
    InspectRequestedParamsBuilder() : result_(new InspectRequestedParams()) { }

    template<int STEP> InspectRequestedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InspectRequestedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InspectRequestedParams> result_;
  };

  static InspectRequestedParamsBuilder<0> Builder() {
    return InspectRequestedParamsBuilder<0>();
  }

 private:
  InspectRequestedParams() { }

  std::unique_ptr<::headless::runtime::RemoteObject> object_;
  std::unique_ptr<base::Value> hints_;

  DISALLOW_COPY_AND_ASSIGN(InspectRequestedParams);
};


}  // namespace runtime

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_RUNTIME_H_
