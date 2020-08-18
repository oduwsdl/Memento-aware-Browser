// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_INSERTABLE_STREAMS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_INSERTABLE_STREAMS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class ReadableStream;
class WritableStream;

class MODULES_EXPORT RTCInsertableStreams : public IDLDictionaryBase {
 public:
  static RTCInsertableStreams* Create() { return MakeGarbageCollected<RTCInsertableStreams>(); }
  static RTCInsertableStreams* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RTCInsertableStreams>();
  }

  RTCInsertableStreams();
  virtual ~RTCInsertableStreams();

  bool hasReadableStream() const { return !!readable_stream_; }
  ReadableStream* readableStream() const {
    return readable_stream_;
  }
  inline void setReadableStream(ReadableStream*);

  bool hasWritableStream() const { return !!writable_stream_; }
  WritableStream* writableStream() const {
    return writable_stream_;
  }
  inline void setWritableStream(WritableStream*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  Member<ReadableStream> readable_stream_;
  Member<WritableStream> writable_stream_;

  friend class V8RTCInsertableStreams;
};

void RTCInsertableStreams::setReadableStream(ReadableStream* value) {
  readable_stream_ = value;
}

void RTCInsertableStreams::setWritableStream(WritableStream* value) {
  writable_stream_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PEERCONNECTION_RTC_INSERTABLE_STREAMS_H_
