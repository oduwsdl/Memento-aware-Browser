// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_EDIT_CONTEXT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_EDIT_CONTEXT_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT EditContextInit : public IDLDictionaryBase {
 public:
  static EditContextInit* Create() { return MakeGarbageCollected<EditContextInit>(); }
  static EditContextInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<EditContextInit>();
  }

  EditContextInit();
  virtual ~EditContextInit();

  bool hasEnterKeyHint() const { return !enter_key_hint_.IsNull(); }
  const String& enterKeyHint() const {
    return enter_key_hint_;
  }
  inline void setEnterKeyHint(const String&);

  bool hasInputMode() const { return !input_mode_.IsNull(); }
  const String& inputMode() const {
    return input_mode_;
  }
  inline void setInputMode(const String&);

  bool hasInputPanelPolicy() const { return !input_panel_policy_.IsNull(); }
  const String& inputPanelPolicy() const {
    return input_panel_policy_;
  }
  inline void setInputPanelPolicy(const String&);

  bool hasSelectionEnd() const { return has_selection_end_; }
  uint32_t selectionEnd() const {
    DCHECK(has_selection_end_);
    return selection_end_;
  }
  inline void setSelectionEnd(uint32_t);

  bool hasSelectionStart() const { return has_selection_start_; }
  uint32_t selectionStart() const {
    DCHECK(has_selection_start_);
    return selection_start_;
  }
  inline void setSelectionStart(uint32_t);

  bool hasText() const { return !text_.IsNull(); }
  const String& text() const {
    return text_;
  }
  inline void setText(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_selection_end_ = false;
  bool has_selection_start_ = false;

  String enter_key_hint_;
  String input_mode_;
  String input_panel_policy_;
  uint32_t selection_end_;
  uint32_t selection_start_;
  String text_;

  friend class V8EditContextInit;
};

void EditContextInit::setEnterKeyHint(const String& value) {
  enter_key_hint_ = value;
}

void EditContextInit::setInputMode(const String& value) {
  input_mode_ = value;
}

void EditContextInit::setInputPanelPolicy(const String& value) {
  input_panel_policy_ = value;
}

void EditContextInit::setSelectionEnd(uint32_t value) {
  selection_end_ = value;
  has_selection_end_ = true;
}

void EditContextInit::setSelectionStart(uint32_t value) {
  selection_start_ = value;
  has_selection_start_ = true;
}

void EditContextInit::setText(const String& value) {
  text_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_EDIT_CONTEXT_INIT_H_
