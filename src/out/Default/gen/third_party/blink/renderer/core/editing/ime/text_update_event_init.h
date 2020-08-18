// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_TEXT_UPDATE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_TEXT_UPDATE_EVENT_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT TextUpdateEventInit : public IDLDictionaryBase {
 public:
  static TextUpdateEventInit* Create() { return MakeGarbageCollected<TextUpdateEventInit>(); }
  static TextUpdateEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<TextUpdateEventInit>();
  }

  TextUpdateEventInit();
  virtual ~TextUpdateEventInit();

  bool hasNewSelectionEnd() const { return has_new_selection_end_; }
  uint32_t newSelectionEnd() const {
    DCHECK(has_new_selection_end_);
    return new_selection_end_;
  }
  inline void setNewSelectionEnd(uint32_t);

  bool hasNewSelectionStart() const { return has_new_selection_start_; }
  uint32_t newSelectionStart() const {
    DCHECK(has_new_selection_start_);
    return new_selection_start_;
  }
  inline void setNewSelectionStart(uint32_t);

  bool hasUpdateRangeEnd() const { return has_update_range_end_; }
  uint32_t updateRangeEnd() const {
    DCHECK(has_update_range_end_);
    return update_range_end_;
  }
  inline void setUpdateRangeEnd(uint32_t);

  bool hasUpdateRangeStart() const { return has_update_range_start_; }
  uint32_t updateRangeStart() const {
    DCHECK(has_update_range_start_);
    return update_range_start_;
  }
  inline void setUpdateRangeStart(uint32_t);

  bool hasUpdateText() const { return !update_text_.IsNull(); }
  const String& updateText() const {
    return update_text_;
  }
  inline void setUpdateText(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_new_selection_end_ = false;
  bool has_new_selection_start_ = false;
  bool has_update_range_end_ = false;
  bool has_update_range_start_ = false;

  uint32_t new_selection_end_;
  uint32_t new_selection_start_;
  uint32_t update_range_end_;
  uint32_t update_range_start_;
  String update_text_;

  friend class V8TextUpdateEventInit;
};

void TextUpdateEventInit::setNewSelectionEnd(uint32_t value) {
  new_selection_end_ = value;
  has_new_selection_end_ = true;
}

void TextUpdateEventInit::setNewSelectionStart(uint32_t value) {
  new_selection_start_ = value;
  has_new_selection_start_ = true;
}

void TextUpdateEventInit::setUpdateRangeEnd(uint32_t value) {
  update_range_end_ = value;
  has_update_range_end_ = true;
}

void TextUpdateEventInit::setUpdateRangeStart(uint32_t value) {
  update_range_start_ = value;
  has_update_range_start_ = true;
}

void TextUpdateEventInit::setUpdateText(const String& value) {
  update_text_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_TEXT_UPDATE_EVENT_INIT_H_
