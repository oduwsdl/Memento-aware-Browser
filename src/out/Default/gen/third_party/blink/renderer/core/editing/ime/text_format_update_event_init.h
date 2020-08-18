// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_TEXT_FORMAT_UPDATE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_TEXT_FORMAT_UPDATE_EVENT_INIT_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT TextFormatUpdateEventInit : public IDLDictionaryBase {
 public:
  static TextFormatUpdateEventInit* Create() { return MakeGarbageCollected<TextFormatUpdateEventInit>(); }
  static TextFormatUpdateEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<TextFormatUpdateEventInit>();
  }

  TextFormatUpdateEventInit();
  virtual ~TextFormatUpdateEventInit();

  bool hasBackgroundColor() const { return !background_color_.IsNull(); }
  const String& backgroundColor() const {
    return background_color_;
  }
  inline void setBackgroundColor(const String&);

  bool hasFormatRangeEnd() const { return has_format_range_end_; }
  uint32_t formatRangeEnd() const {
    DCHECK(has_format_range_end_);
    return format_range_end_;
  }
  inline void setFormatRangeEnd(uint32_t);

  bool hasFormatRangeStart() const { return has_format_range_start_; }
  uint32_t formatRangeStart() const {
    DCHECK(has_format_range_start_);
    return format_range_start_;
  }
  inline void setFormatRangeStart(uint32_t);

  bool hasTextDecorationColor() const { return !text_decoration_color_.IsNull(); }
  const String& textDecorationColor() const {
    return text_decoration_color_;
  }
  inline void setTextDecorationColor(const String&);

  bool hasTextUnderlineStyle() const { return !text_underline_style_.IsNull(); }
  const String& textUnderlineStyle() const {
    return text_underline_style_;
  }
  inline void setTextUnderlineStyle(const String&);

  bool hasUnderlineColor() const { return !underline_color_.IsNull(); }
  const String& underlineColor() const {
    return underline_color_;
  }
  inline void setUnderlineColor(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_format_range_end_ = false;
  bool has_format_range_start_ = false;

  String background_color_;
  uint32_t format_range_end_;
  uint32_t format_range_start_;
  String text_decoration_color_;
  String text_underline_style_;
  String underline_color_;

  friend class V8TextFormatUpdateEventInit;
};

void TextFormatUpdateEventInit::setBackgroundColor(const String& value) {
  background_color_ = value;
}

void TextFormatUpdateEventInit::setFormatRangeEnd(uint32_t value) {
  format_range_end_ = value;
  has_format_range_end_ = true;
}

void TextFormatUpdateEventInit::setFormatRangeStart(uint32_t value) {
  format_range_start_ = value;
  has_format_range_start_ = true;
}

void TextFormatUpdateEventInit::setTextDecorationColor(const String& value) {
  text_decoration_color_ = value;
}

void TextFormatUpdateEventInit::setTextUnderlineStyle(const String& value) {
  text_underline_style_ = value;
}

void TextFormatUpdateEventInit::setUnderlineColor(const String& value) {
  underline_color_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EDITING_IME_TEXT_FORMAT_UPDATE_EVENT_INIT_H_
