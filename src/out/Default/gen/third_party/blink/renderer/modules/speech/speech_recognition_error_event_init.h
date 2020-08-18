// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SPEECH_SPEECH_RECOGNITION_ERROR_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SPEECH_SPEECH_RECOGNITION_ERROR_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT SpeechRecognitionErrorEventInit : public EventInit {
 public:
  static SpeechRecognitionErrorEventInit* Create() { return MakeGarbageCollected<SpeechRecognitionErrorEventInit>(); }
  static SpeechRecognitionErrorEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<SpeechRecognitionErrorEventInit>();
  }

  SpeechRecognitionErrorEventInit();
  virtual ~SpeechRecognitionErrorEventInit();

  bool hasError() const { return !error_.IsNull(); }
  const String& error() const {
    return error_;
  }
  inline void setError(const String&);

  bool hasMessage() const { return !message_.IsNull(); }
  const String& message() const {
    return message_;
  }
  inline void setMessage(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String error_;
  String message_;

  friend class V8SpeechRecognitionErrorEventInit;
};

void SpeechRecognitionErrorEventInit::setError(const String& value) {
  error_ = value;
}

void SpeechRecognitionErrorEventInit::setMessage(const String& value) {
  message_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SPEECH_SPEECH_RECOGNITION_ERROR_EVENT_INIT_H_
