// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/union_container.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/core/v8/node_or_string_or_trusted_script.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/to_v8_for_core.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_node.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_trusted_script.h"

namespace blink {

NodeOrStringOrTrustedScript::NodeOrStringOrTrustedScript() : type_(SpecificType::kNone) {}

Node* NodeOrStringOrTrustedScript::GetAsNode() const {
  DCHECK(IsNode());
  return node_;
}

void NodeOrStringOrTrustedScript::SetNode(Node* value) {
  DCHECK(IsNull());
  node_ = value;
  type_ = SpecificType::kNode;
}

NodeOrStringOrTrustedScript NodeOrStringOrTrustedScript::FromNode(Node* value) {
  NodeOrStringOrTrustedScript container;
  container.SetNode(value);
  return container;
}

const String& NodeOrStringOrTrustedScript::GetAsString() const {
  DCHECK(IsString());
  return string_;
}

void NodeOrStringOrTrustedScript::SetString(const String& value) {
  DCHECK(IsNull());
  string_ = value;
  type_ = SpecificType::kString;
}

NodeOrStringOrTrustedScript NodeOrStringOrTrustedScript::FromString(const String& value) {
  NodeOrStringOrTrustedScript container;
  container.SetString(value);
  return container;
}

TrustedScript* NodeOrStringOrTrustedScript::GetAsTrustedScript() const {
  DCHECK(IsTrustedScript());
  return trusted_script_;
}

void NodeOrStringOrTrustedScript::SetTrustedScript(TrustedScript* value) {
  DCHECK(IsNull());
  trusted_script_ = value;
  type_ = SpecificType::kTrustedScript;
}

NodeOrStringOrTrustedScript NodeOrStringOrTrustedScript::FromTrustedScript(TrustedScript* value) {
  NodeOrStringOrTrustedScript container;
  container.SetTrustedScript(value);
  return container;
}

NodeOrStringOrTrustedScript::NodeOrStringOrTrustedScript(const NodeOrStringOrTrustedScript&) = default;
NodeOrStringOrTrustedScript::~NodeOrStringOrTrustedScript() = default;
NodeOrStringOrTrustedScript& NodeOrStringOrTrustedScript::operator=(const NodeOrStringOrTrustedScript&) = default;

void NodeOrStringOrTrustedScript::Trace(Visitor* visitor) const {
  visitor->Trace(node_);
  visitor->Trace(trusted_script_);
}

void V8NodeOrStringOrTrustedScript::ToImpl(
    v8::Isolate* isolate,
    v8::Local<v8::Value> v8_value,
    NodeOrStringOrTrustedScript& impl,
    UnionTypeConversionMode conversion_mode,
    ExceptionState& exception_state) {
  if (v8_value.IsEmpty())
    return;

  if (conversion_mode == UnionTypeConversionMode::kNullable && IsUndefinedOrNull(v8_value))
    return;

  if (V8Node::HasInstance(v8_value, isolate)) {
    Node* cpp_value = V8Node::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetNode(cpp_value);
    return;
  }

  if (V8TrustedScript::HasInstance(v8_value, isolate)) {
    TrustedScript* cpp_value = V8TrustedScript::ToImpl(v8::Local<v8::Object>::Cast(v8_value));
    impl.SetTrustedScript(cpp_value);
    return;
  }

  {
    V8StringResource<> cpp_value = v8_value;
    if (!cpp_value.Prepare(exception_state))
      return;
    impl.SetString(cpp_value);
    return;
  }
}

v8::Local<v8::Value> ToV8(const NodeOrStringOrTrustedScript& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.type_) {
    case NodeOrStringOrTrustedScript::SpecificType::kNone:
      return v8::Null(isolate);
    case NodeOrStringOrTrustedScript::SpecificType::kNode:
      return ToV8(impl.GetAsNode(), creationContext, isolate);
    case NodeOrStringOrTrustedScript::SpecificType::kString:
      return V8String(isolate, impl.GetAsString());
    case NodeOrStringOrTrustedScript::SpecificType::kTrustedScript:
      return ToV8(impl.GetAsTrustedScript(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

NodeOrStringOrTrustedScript NativeValueTraits<NodeOrStringOrTrustedScript>::NativeValue(
    v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  NodeOrStringOrTrustedScript impl;
  V8NodeOrStringOrTrustedScript::ToImpl(isolate, value, impl, UnionTypeConversionMode::kNotNullable, exception_state);
  return impl;
}

}  // namespace blink

