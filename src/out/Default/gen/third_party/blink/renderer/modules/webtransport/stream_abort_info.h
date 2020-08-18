// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBTRANSPORT_STREAM_ABORT_INFO_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBTRANSPORT_STREAM_ABORT_INFO_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT StreamAbortInfo : public IDLDictionaryBase {
 public:
  static StreamAbortInfo* Create() { return MakeGarbageCollected<StreamAbortInfo>(); }
  static StreamAbortInfo* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<StreamAbortInfo>();
  }

  StreamAbortInfo();
  virtual ~StreamAbortInfo();

  bool hasErrorCode() const { return has_error_code_; }
  uint16_t errorCode() const {
    DCHECK(has_error_code_);
    return error_code_;
  }
  inline void setErrorCode(uint16_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_error_code_ = false;

  uint16_t error_code_;

  friend class V8StreamAbortInfo;
};

void StreamAbortInfo::setErrorCode(uint16_t value) {
  error_code_ = value;
  has_error_code_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBTRANSPORT_STREAM_ABORT_INFO_H_
