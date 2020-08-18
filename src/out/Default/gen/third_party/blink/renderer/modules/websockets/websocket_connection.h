// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBSOCKETS_WEBSOCKET_CONNECTION_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBSOCKETS_WEBSOCKET_CONNECTION_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class ReadableStream;
class WritableStream;

class MODULES_EXPORT WebSocketConnection : public IDLDictionaryBase {
 public:
  static WebSocketConnection* Create() { return MakeGarbageCollected<WebSocketConnection>(); }
  static WebSocketConnection* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<WebSocketConnection>();
  }

  WebSocketConnection();
  virtual ~WebSocketConnection();

  bool hasExtensions() const { return !extensions_.IsNull(); }
  const String& extensions() const {
    return extensions_;
  }
  inline void setExtensions(const String&);

  bool hasProtocol() const { return !protocol_.IsNull(); }
  const String& protocol() const {
    return protocol_;
  }
  inline void setProtocol(const String&);

  bool hasReadable() const { return !!readable_; }
  ReadableStream* readable() const {
    return readable_;
  }
  inline void setReadable(ReadableStream*);

  bool hasWritable() const { return !!writable_; }
  WritableStream* writable() const {
    return writable_;
  }
  inline void setWritable(WritableStream*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String extensions_;
  String protocol_;
  Member<ReadableStream> readable_;
  Member<WritableStream> writable_;

  friend class V8WebSocketConnection;
};

void WebSocketConnection::setExtensions(const String& value) {
  extensions_ = value;
}

void WebSocketConnection::setProtocol(const String& value) {
  protocol_ = value;
}

void WebSocketConnection::setReadable(ReadableStream* value) {
  readable_ = value;
}

void WebSocketConnection::setWritable(WritableStream* value) {
  writable_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBSOCKETS_WEBSOCKET_CONNECTION_H_
