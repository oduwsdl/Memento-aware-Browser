// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_ACCESSIBILITY_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_ACCESSIBILITY_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_accessibility.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace accessibility {

// A single source for a computed AX property.
class HEADLESS_EXPORT AXValueSource {
 public:
  static std::unique_ptr<AXValueSource> Parse(const base::Value& value, ErrorReporter* errors);
  ~AXValueSource() { }

  // What type of source this is.
  ::headless::accessibility::AXValueSourceType GetType() const { return type_; }
  void SetType(::headless::accessibility::AXValueSourceType value) { type_ = value; }

  // The value of this property source.
  bool HasValue() const { return !!value_; }
  const ::headless::accessibility::AXValue* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<::headless::accessibility::AXValue> value) { value_ = std::move(value); }

  // The name of the relevant attribute, if any.
  bool HasAttribute() const { return !!attribute_; }
  std::string GetAttribute() const { DCHECK(HasAttribute()); return attribute_.value(); }
  void SetAttribute(const std::string& value) { attribute_ = value; }

  // The value of the relevant attribute, if any.
  bool HasAttributeValue() const { return !!attribute_value_; }
  const ::headless::accessibility::AXValue* GetAttributeValue() const { DCHECK(HasAttributeValue()); return attribute_value_.value().get(); }
  void SetAttributeValue(std::unique_ptr<::headless::accessibility::AXValue> value) { attribute_value_ = std::move(value); }

  // Whether this source is superseded by a higher priority source.
  bool HasSuperseded() const { return !!superseded_; }
  bool GetSuperseded() const { DCHECK(HasSuperseded()); return superseded_.value(); }
  void SetSuperseded(bool value) { superseded_ = value; }

  // The native markup source for this value, e.g. a <label> element.
  bool HasNativeSource() const { return !!native_source_; }
  ::headless::accessibility::AXValueNativeSourceType GetNativeSource() const { DCHECK(HasNativeSource()); return native_source_.value(); }
  void SetNativeSource(::headless::accessibility::AXValueNativeSourceType value) { native_source_ = value; }

  // The value, such as a node or node list, of the native source.
  bool HasNativeSourceValue() const { return !!native_source_value_; }
  const ::headless::accessibility::AXValue* GetNativeSourceValue() const { DCHECK(HasNativeSourceValue()); return native_source_value_.value().get(); }
  void SetNativeSourceValue(std::unique_ptr<::headless::accessibility::AXValue> value) { native_source_value_ = std::move(value); }

  // Whether the value for this property is invalid.
  bool HasInvalid() const { return !!invalid_; }
  bool GetInvalid() const { DCHECK(HasInvalid()); return invalid_.value(); }
  void SetInvalid(bool value) { invalid_ = value; }

  // Reason for the value being invalid, if it is.
  bool HasInvalidReason() const { return !!invalid_reason_; }
  std::string GetInvalidReason() const { DCHECK(HasInvalidReason()); return invalid_reason_.value(); }
  void SetInvalidReason(const std::string& value) { invalid_reason_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AXValueSource> Clone() const;

  template<int STATE>
  class AXValueSourceBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    AXValueSourceBuilder<STATE | kTypeSet>& SetType(::headless::accessibility::AXValueSourceType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    AXValueSourceBuilder<STATE>& SetValue(std::unique_ptr<::headless::accessibility::AXValue> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    AXValueSourceBuilder<STATE>& SetAttribute(const std::string& value) {
      result_->SetAttribute(value);
      return *this;
    }

    AXValueSourceBuilder<STATE>& SetAttributeValue(std::unique_ptr<::headless::accessibility::AXValue> value) {
      result_->SetAttributeValue(std::move(value));
      return *this;
    }

    AXValueSourceBuilder<STATE>& SetSuperseded(bool value) {
      result_->SetSuperseded(value);
      return *this;
    }

    AXValueSourceBuilder<STATE>& SetNativeSource(::headless::accessibility::AXValueNativeSourceType value) {
      result_->SetNativeSource(value);
      return *this;
    }

    AXValueSourceBuilder<STATE>& SetNativeSourceValue(std::unique_ptr<::headless::accessibility::AXValue> value) {
      result_->SetNativeSourceValue(std::move(value));
      return *this;
    }

    AXValueSourceBuilder<STATE>& SetInvalid(bool value) {
      result_->SetInvalid(value);
      return *this;
    }

    AXValueSourceBuilder<STATE>& SetInvalidReason(const std::string& value) {
      result_->SetInvalidReason(value);
      return *this;
    }

    std::unique_ptr<AXValueSource> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AXValueSource;
    AXValueSourceBuilder() : result_(new AXValueSource()) { }

    template<int STEP> AXValueSourceBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AXValueSourceBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AXValueSource> result_;
  };

  static AXValueSourceBuilder<0> Builder() {
    return AXValueSourceBuilder<0>();
  }

 private:
  AXValueSource() { }

  ::headless::accessibility::AXValueSourceType type_;
  base::Optional<std::unique_ptr<::headless::accessibility::AXValue>> value_;
  base::Optional<std::string> attribute_;
  base::Optional<std::unique_ptr<::headless::accessibility::AXValue>> attribute_value_;
  base::Optional<bool> superseded_;
  base::Optional<::headless::accessibility::AXValueNativeSourceType> native_source_;
  base::Optional<std::unique_ptr<::headless::accessibility::AXValue>> native_source_value_;
  base::Optional<bool> invalid_;
  base::Optional<std::string> invalid_reason_;

  DISALLOW_COPY_AND_ASSIGN(AXValueSource);
};


class HEADLESS_EXPORT AXRelatedNode {
 public:
  static std::unique_ptr<AXRelatedNode> Parse(const base::Value& value, ErrorReporter* errors);
  ~AXRelatedNode() { }

  // The BackendNodeId of the related DOM node.
  int GetBackendDOMNodeId() const { return backenddom_node_id_; }
  void SetBackendDOMNodeId(int value) { backenddom_node_id_ = value; }

  // The IDRef value provided, if any.
  bool HasIdref() const { return !!idref_; }
  std::string GetIdref() const { DCHECK(HasIdref()); return idref_.value(); }
  void SetIdref(const std::string& value) { idref_ = value; }

  // The text alternative of this node in the current context.
  bool HasText() const { return !!text_; }
  std::string GetText() const { DCHECK(HasText()); return text_.value(); }
  void SetText(const std::string& value) { text_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AXRelatedNode> Clone() const;

  template<int STATE>
  class AXRelatedNodeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBackendDOMNodeIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kBackendDOMNodeIdSet | 0)
    };

    AXRelatedNodeBuilder<STATE | kBackendDOMNodeIdSet>& SetBackendDOMNodeId(int value) {
      static_assert(!(STATE & kBackendDOMNodeIdSet), "property backendDOMNodeId should not have already been set");
      result_->SetBackendDOMNodeId(value);
      return CastState<kBackendDOMNodeIdSet>();
    }

    AXRelatedNodeBuilder<STATE>& SetIdref(const std::string& value) {
      result_->SetIdref(value);
      return *this;
    }

    AXRelatedNodeBuilder<STATE>& SetText(const std::string& value) {
      result_->SetText(value);
      return *this;
    }

    std::unique_ptr<AXRelatedNode> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AXRelatedNode;
    AXRelatedNodeBuilder() : result_(new AXRelatedNode()) { }

    template<int STEP> AXRelatedNodeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AXRelatedNodeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AXRelatedNode> result_;
  };

  static AXRelatedNodeBuilder<0> Builder() {
    return AXRelatedNodeBuilder<0>();
  }

 private:
  AXRelatedNode() { }

  int backenddom_node_id_;
  base::Optional<std::string> idref_;
  base::Optional<std::string> text_;

  DISALLOW_COPY_AND_ASSIGN(AXRelatedNode);
};


class HEADLESS_EXPORT AXProperty {
 public:
  static std::unique_ptr<AXProperty> Parse(const base::Value& value, ErrorReporter* errors);
  ~AXProperty() { }

  // The name of this property.
  ::headless::accessibility::AXPropertyName GetName() const { return name_; }
  void SetName(::headless::accessibility::AXPropertyName value) { name_ = value; }

  // The value of this property.
  const ::headless::accessibility::AXValue* GetValue() const { return value_.get(); }
  void SetValue(std::unique_ptr<::headless::accessibility::AXValue> value) { value_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AXProperty> Clone() const;

  template<int STATE>
  class AXPropertyBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    AXPropertyBuilder<STATE | kNameSet>& SetName(::headless::accessibility::AXPropertyName value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    AXPropertyBuilder<STATE | kValueSet>& SetValue(std::unique_ptr<::headless::accessibility::AXValue> value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(std::move(value));
      return CastState<kValueSet>();
    }

    std::unique_ptr<AXProperty> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AXProperty;
    AXPropertyBuilder() : result_(new AXProperty()) { }

    template<int STEP> AXPropertyBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AXPropertyBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AXProperty> result_;
  };

  static AXPropertyBuilder<0> Builder() {
    return AXPropertyBuilder<0>();
  }

 private:
  AXProperty() { }

  ::headless::accessibility::AXPropertyName name_;
  std::unique_ptr<::headless::accessibility::AXValue> value_;

  DISALLOW_COPY_AND_ASSIGN(AXProperty);
};


// A single computed AX property.
class HEADLESS_EXPORT AXValue {
 public:
  static std::unique_ptr<AXValue> Parse(const base::Value& value, ErrorReporter* errors);
  ~AXValue() { }

  // The type of this value.
  ::headless::accessibility::AXValueType GetType() const { return type_; }
  void SetType(::headless::accessibility::AXValueType value) { type_ = value; }

  // The computed value of this property.
  bool HasValue() const { return !!value_; }
  const base::Value* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<base::Value> value) { value_ = std::move(value); }

  // One or more related nodes, if applicable.
  bool HasRelatedNodes() const { return !!related_nodes_; }
  const std::vector<std::unique_ptr<::headless::accessibility::AXRelatedNode>>* GetRelatedNodes() const { DCHECK(HasRelatedNodes()); return &related_nodes_.value(); }
  void SetRelatedNodes(std::vector<std::unique_ptr<::headless::accessibility::AXRelatedNode>> value) { related_nodes_ = std::move(value); }

  // The sources which contributed to the computation of this property.
  bool HasSources() const { return !!sources_; }
  const std::vector<std::unique_ptr<::headless::accessibility::AXValueSource>>* GetSources() const { DCHECK(HasSources()); return &sources_.value(); }
  void SetSources(std::vector<std::unique_ptr<::headless::accessibility::AXValueSource>> value) { sources_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AXValue> Clone() const;

  template<int STATE>
  class AXValueBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
      kAllRequiredFieldsSet = (kTypeSet | 0)
    };

    AXValueBuilder<STATE | kTypeSet>& SetType(::headless::accessibility::AXValueType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    AXValueBuilder<STATE>& SetValue(std::unique_ptr<base::Value> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    AXValueBuilder<STATE>& SetRelatedNodes(std::vector<std::unique_ptr<::headless::accessibility::AXRelatedNode>> value) {
      result_->SetRelatedNodes(std::move(value));
      return *this;
    }

    AXValueBuilder<STATE>& SetSources(std::vector<std::unique_ptr<::headless::accessibility::AXValueSource>> value) {
      result_->SetSources(std::move(value));
      return *this;
    }

    std::unique_ptr<AXValue> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AXValue;
    AXValueBuilder() : result_(new AXValue()) { }

    template<int STEP> AXValueBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AXValueBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AXValue> result_;
  };

  static AXValueBuilder<0> Builder() {
    return AXValueBuilder<0>();
  }

 private:
  AXValue() { }

  ::headless::accessibility::AXValueType type_;
  base::Optional<std::unique_ptr<base::Value>> value_;
  base::Optional<std::vector<std::unique_ptr<::headless::accessibility::AXRelatedNode>>> related_nodes_;
  base::Optional<std::vector<std::unique_ptr<::headless::accessibility::AXValueSource>>> sources_;

  DISALLOW_COPY_AND_ASSIGN(AXValue);
};


// A node in the accessibility tree.
class HEADLESS_EXPORT AXNode {
 public:
  static std::unique_ptr<AXNode> Parse(const base::Value& value, ErrorReporter* errors);
  ~AXNode() { }

  // Unique identifier for this node.
  std::string GetNodeId() const { return node_id_; }
  void SetNodeId(const std::string& value) { node_id_ = value; }

  // Whether this node is ignored for accessibility
  bool GetIgnored() const { return ignored_; }
  void SetIgnored(bool value) { ignored_ = value; }

  // Collection of reasons why this node is hidden.
  bool HasIgnoredReasons() const { return !!ignored_reasons_; }
  const std::vector<std::unique_ptr<::headless::accessibility::AXProperty>>* GetIgnoredReasons() const { DCHECK(HasIgnoredReasons()); return &ignored_reasons_.value(); }
  void SetIgnoredReasons(std::vector<std::unique_ptr<::headless::accessibility::AXProperty>> value) { ignored_reasons_ = std::move(value); }

  // This `Node`'s role, whether explicit or implicit.
  bool HasRole() const { return !!role_; }
  const ::headless::accessibility::AXValue* GetRole() const { DCHECK(HasRole()); return role_.value().get(); }
  void SetRole(std::unique_ptr<::headless::accessibility::AXValue> value) { role_ = std::move(value); }

  // The accessible name for this `Node`.
  bool HasName() const { return !!name_; }
  const ::headless::accessibility::AXValue* GetName() const { DCHECK(HasName()); return name_.value().get(); }
  void SetName(std::unique_ptr<::headless::accessibility::AXValue> value) { name_ = std::move(value); }

  // The accessible description for this `Node`.
  bool HasDescription() const { return !!description_; }
  const ::headless::accessibility::AXValue* GetDescription() const { DCHECK(HasDescription()); return description_.value().get(); }
  void SetDescription(std::unique_ptr<::headless::accessibility::AXValue> value) { description_ = std::move(value); }

  // The value for this `Node`.
  bool HasValue() const { return !!value_; }
  const ::headless::accessibility::AXValue* GetValue() const { DCHECK(HasValue()); return value_.value().get(); }
  void SetValue(std::unique_ptr<::headless::accessibility::AXValue> value) { value_ = std::move(value); }

  // All other properties
  bool HasProperties() const { return !!properties_; }
  const std::vector<std::unique_ptr<::headless::accessibility::AXProperty>>* GetProperties() const { DCHECK(HasProperties()); return &properties_.value(); }
  void SetProperties(std::vector<std::unique_ptr<::headless::accessibility::AXProperty>> value) { properties_ = std::move(value); }

  // IDs for each of this node's child nodes.
  bool HasChildIds() const { return !!child_ids_; }
  const std::vector<std::string>* GetChildIds() const { DCHECK(HasChildIds()); return &child_ids_.value(); }
  void SetChildIds(std::vector<std::string> value) { child_ids_ = std::move(value); }

  // The backend ID for the associated DOM node, if any.
  bool HasBackendDOMNodeId() const { return !!backenddom_node_id_; }
  int GetBackendDOMNodeId() const { DCHECK(HasBackendDOMNodeId()); return backenddom_node_id_.value(); }
  void SetBackendDOMNodeId(int value) { backenddom_node_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AXNode> Clone() const;

  template<int STATE>
  class AXNodeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodeIdSet = 1 << 1,
    kIgnoredSet = 1 << 2,
      kAllRequiredFieldsSet = (kNodeIdSet | kIgnoredSet | 0)
    };

    AXNodeBuilder<STATE | kNodeIdSet>& SetNodeId(const std::string& value) {
      static_assert(!(STATE & kNodeIdSet), "property nodeId should not have already been set");
      result_->SetNodeId(value);
      return CastState<kNodeIdSet>();
    }

    AXNodeBuilder<STATE | kIgnoredSet>& SetIgnored(bool value) {
      static_assert(!(STATE & kIgnoredSet), "property ignored should not have already been set");
      result_->SetIgnored(value);
      return CastState<kIgnoredSet>();
    }

    AXNodeBuilder<STATE>& SetIgnoredReasons(std::vector<std::unique_ptr<::headless::accessibility::AXProperty>> value) {
      result_->SetIgnoredReasons(std::move(value));
      return *this;
    }

    AXNodeBuilder<STATE>& SetRole(std::unique_ptr<::headless::accessibility::AXValue> value) {
      result_->SetRole(std::move(value));
      return *this;
    }

    AXNodeBuilder<STATE>& SetName(std::unique_ptr<::headless::accessibility::AXValue> value) {
      result_->SetName(std::move(value));
      return *this;
    }

    AXNodeBuilder<STATE>& SetDescription(std::unique_ptr<::headless::accessibility::AXValue> value) {
      result_->SetDescription(std::move(value));
      return *this;
    }

    AXNodeBuilder<STATE>& SetValue(std::unique_ptr<::headless::accessibility::AXValue> value) {
      result_->SetValue(std::move(value));
      return *this;
    }

    AXNodeBuilder<STATE>& SetProperties(std::vector<std::unique_ptr<::headless::accessibility::AXProperty>> value) {
      result_->SetProperties(std::move(value));
      return *this;
    }

    AXNodeBuilder<STATE>& SetChildIds(std::vector<std::string> value) {
      result_->SetChildIds(std::move(value));
      return *this;
    }

    AXNodeBuilder<STATE>& SetBackendDOMNodeId(int value) {
      result_->SetBackendDOMNodeId(value);
      return *this;
    }

    std::unique_ptr<AXNode> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AXNode;
    AXNodeBuilder() : result_(new AXNode()) { }

    template<int STEP> AXNodeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AXNodeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AXNode> result_;
  };

  static AXNodeBuilder<0> Builder() {
    return AXNodeBuilder<0>();
  }

 private:
  AXNode() { }

  std::string node_id_;
  bool ignored_;
  base::Optional<std::vector<std::unique_ptr<::headless::accessibility::AXProperty>>> ignored_reasons_;
  base::Optional<std::unique_ptr<::headless::accessibility::AXValue>> role_;
  base::Optional<std::unique_ptr<::headless::accessibility::AXValue>> name_;
  base::Optional<std::unique_ptr<::headless::accessibility::AXValue>> description_;
  base::Optional<std::unique_ptr<::headless::accessibility::AXValue>> value_;
  base::Optional<std::vector<std::unique_ptr<::headless::accessibility::AXProperty>>> properties_;
  base::Optional<std::vector<std::string>> child_ids_;
  base::Optional<int> backenddom_node_id_;

  DISALLOW_COPY_AND_ASSIGN(AXNode);
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


// Parameters for the GetPartialAXTree command.
class HEADLESS_EXPORT GetPartialAXTreeParams {
 public:
  static std::unique_ptr<GetPartialAXTreeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetPartialAXTreeParams() { }

  // Identifier of the node to get the partial accessibility tree for.
  bool HasNodeId() const { return !!node_id_; }
  int GetNodeId() const { DCHECK(HasNodeId()); return node_id_.value(); }
  void SetNodeId(int value) { node_id_ = value; }

  // Identifier of the backend node to get the partial accessibility tree for.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // JavaScript object id of the node wrapper to get the partial accessibility tree for.
  bool HasObjectId() const { return !!object_id_; }
  std::string GetObjectId() const { DCHECK(HasObjectId()); return object_id_.value(); }
  void SetObjectId(const std::string& value) { object_id_ = value; }

  // Whether to fetch this nodes ancestors, siblings and children. Defaults to true.
  bool HasFetchRelatives() const { return !!fetch_relatives_; }
  bool GetFetchRelatives() const { DCHECK(HasFetchRelatives()); return fetch_relatives_.value(); }
  void SetFetchRelatives(bool value) { fetch_relatives_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetPartialAXTreeParams> Clone() const;

  template<int STATE>
  class GetPartialAXTreeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetPartialAXTreeParamsBuilder<STATE>& SetNodeId(int value) {
      result_->SetNodeId(value);
      return *this;
    }

    GetPartialAXTreeParamsBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    GetPartialAXTreeParamsBuilder<STATE>& SetObjectId(const std::string& value) {
      result_->SetObjectId(value);
      return *this;
    }

    GetPartialAXTreeParamsBuilder<STATE>& SetFetchRelatives(bool value) {
      result_->SetFetchRelatives(value);
      return *this;
    }

    std::unique_ptr<GetPartialAXTreeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetPartialAXTreeParams;
    GetPartialAXTreeParamsBuilder() : result_(new GetPartialAXTreeParams()) { }

    template<int STEP> GetPartialAXTreeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetPartialAXTreeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetPartialAXTreeParams> result_;
  };

  static GetPartialAXTreeParamsBuilder<0> Builder() {
    return GetPartialAXTreeParamsBuilder<0>();
  }

 private:
  GetPartialAXTreeParams() { }

  base::Optional<int> node_id_;
  base::Optional<int> backend_node_id_;
  base::Optional<std::string> object_id_;
  base::Optional<bool> fetch_relatives_;

  DISALLOW_COPY_AND_ASSIGN(GetPartialAXTreeParams);
};


// Result for the GetPartialAXTree command.
class HEADLESS_EXPORT GetPartialAXTreeResult {
 public:
  static std::unique_ptr<GetPartialAXTreeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetPartialAXTreeResult() { }

  // The `Accessibility.AXNode` for this DOM node, if it exists, plus its ancestors, siblings and
  // children, if requested.
  const std::vector<std::unique_ptr<::headless::accessibility::AXNode>>* GetNodes() const { return &nodes_; }
  void SetNodes(std::vector<std::unique_ptr<::headless::accessibility::AXNode>> value) { nodes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetPartialAXTreeResult> Clone() const;

  template<int STATE>
  class GetPartialAXTreeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodesSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodesSet | 0)
    };

    GetPartialAXTreeResultBuilder<STATE | kNodesSet>& SetNodes(std::vector<std::unique_ptr<::headless::accessibility::AXNode>> value) {
      static_assert(!(STATE & kNodesSet), "property nodes should not have already been set");
      result_->SetNodes(std::move(value));
      return CastState<kNodesSet>();
    }

    std::unique_ptr<GetPartialAXTreeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetPartialAXTreeResult;
    GetPartialAXTreeResultBuilder() : result_(new GetPartialAXTreeResult()) { }

    template<int STEP> GetPartialAXTreeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetPartialAXTreeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetPartialAXTreeResult> result_;
  };

  static GetPartialAXTreeResultBuilder<0> Builder() {
    return GetPartialAXTreeResultBuilder<0>();
  }

 private:
  GetPartialAXTreeResult() { }

  std::vector<std::unique_ptr<::headless::accessibility::AXNode>> nodes_;

  DISALLOW_COPY_AND_ASSIGN(GetPartialAXTreeResult);
};


// Parameters for the GetFullAXTree command.
class HEADLESS_EXPORT GetFullAXTreeParams {
 public:
  static std::unique_ptr<GetFullAXTreeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFullAXTreeParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFullAXTreeParams> Clone() const;

  template<int STATE>
  class GetFullAXTreeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetFullAXTreeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFullAXTreeParams;
    GetFullAXTreeParamsBuilder() : result_(new GetFullAXTreeParams()) { }

    template<int STEP> GetFullAXTreeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFullAXTreeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFullAXTreeParams> result_;
  };

  static GetFullAXTreeParamsBuilder<0> Builder() {
    return GetFullAXTreeParamsBuilder<0>();
  }

 private:
  GetFullAXTreeParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetFullAXTreeParams);
};


// Result for the GetFullAXTree command.
class HEADLESS_EXPORT GetFullAXTreeResult {
 public:
  static std::unique_ptr<GetFullAXTreeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFullAXTreeResult() { }

  const std::vector<std::unique_ptr<::headless::accessibility::AXNode>>* GetNodes() const { return &nodes_; }
  void SetNodes(std::vector<std::unique_ptr<::headless::accessibility::AXNode>> value) { nodes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFullAXTreeResult> Clone() const;

  template<int STATE>
  class GetFullAXTreeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNodesSet = 1 << 1,
      kAllRequiredFieldsSet = (kNodesSet | 0)
    };

    GetFullAXTreeResultBuilder<STATE | kNodesSet>& SetNodes(std::vector<std::unique_ptr<::headless::accessibility::AXNode>> value) {
      static_assert(!(STATE & kNodesSet), "property nodes should not have already been set");
      result_->SetNodes(std::move(value));
      return CastState<kNodesSet>();
    }

    std::unique_ptr<GetFullAXTreeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFullAXTreeResult;
    GetFullAXTreeResultBuilder() : result_(new GetFullAXTreeResult()) { }

    template<int STEP> GetFullAXTreeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFullAXTreeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFullAXTreeResult> result_;
  };

  static GetFullAXTreeResultBuilder<0> Builder() {
    return GetFullAXTreeResultBuilder<0>();
  }

 private:
  GetFullAXTreeResult() { }

  std::vector<std::unique_ptr<::headless::accessibility::AXNode>> nodes_;

  DISALLOW_COPY_AND_ASSIGN(GetFullAXTreeResult);
};


}  // namespace accessibility

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_ACCESSIBILITY_H_
