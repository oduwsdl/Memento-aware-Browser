// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/callback_interface.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NODE_FILTER_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NODE_FILTER_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/bindings/callback_interface_base.h"
#include "third_party/blink/renderer/platform/bindings/dom_wrapper_world.h"
#include "third_party/blink/renderer/platform/bindings/v8_value_or_script_wrappable_adapter.h"
#include "third_party/blink/renderer/platform/bindings/wrapper_type_info.h"

namespace blink {

class Node;

CORE_EXPORT extern const WrapperTypeInfo _wrapper_type_info;

class CORE_EXPORT V8NodeFilter final : public CallbackInterfaceBase {
 public:
  // Support of "legacy callback interface"
  static v8::Local<v8::FunctionTemplate> DomTemplate(v8::Isolate*, const DOMWrapperWorld&);
  static constexpr const WrapperTypeInfo* GetWrapperTypeInfo() {
    return &_wrapper_type_info;
  }

  // Constants
  static constexpr uint16_t FILTER_ACCEPT = 1;
  static constexpr uint16_t FILTER_REJECT = 2;
  static constexpr uint16_t FILTER_SKIP = 3;
  static constexpr uint32_t SHOW_ALL = 0xFFFFFFFF;
  static constexpr uint32_t SHOW_ELEMENT = 0x1;
  static constexpr uint32_t SHOW_ATTRIBUTE = 0x2;
  static constexpr uint32_t SHOW_TEXT = 0x4;
  static constexpr uint32_t SHOW_CDATA_SECTION = 0x8;
  static constexpr uint32_t SHOW_ENTITY_REFERENCE = 0x10;
  static constexpr uint32_t SHOW_ENTITY = 0x20;
  static constexpr uint32_t SHOW_PROCESSING_INSTRUCTION = 0x40;
  static constexpr uint32_t SHOW_COMMENT = 0x80;
  static constexpr uint32_t SHOW_DOCUMENT = 0x100;
  static constexpr uint32_t SHOW_DOCUMENT_TYPE = 0x200;
  static constexpr uint32_t SHOW_DOCUMENT_FRAGMENT = 0x400;
  static constexpr uint32_t SHOW_NOTATION = 0x800;

  static V8NodeFilter* Create(v8::Local<v8::Object> callback_object) {
    return MakeGarbageCollected<V8NodeFilter>(callback_object);
  }

  explicit V8NodeFilter(v8::Local<v8::Object> callback_object)
      : CallbackInterfaceBase(callback_object,
                              kSingleOperation) {}
  ~V8NodeFilter() override = default;

  // NameClient overrides:
  const char* NameInHeapSnapshot() const override;

  // Performs "call a user object's operation".
  // https://heycam.github.io/webidl/#call-a-user-objects-operation
  v8::Maybe<uint16_t> acceptNode(bindings::V8ValueOrScriptWrappableAdapter callback_this_value, Node* node) WARN_UNUSED_RESULT;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_CORE_V8_V8_NODE_FILTER_H_
