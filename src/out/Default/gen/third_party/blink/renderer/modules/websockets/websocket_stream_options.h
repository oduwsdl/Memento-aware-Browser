// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_WEBSOCKETS_WEBSOCKET_STREAM_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_WEBSOCKETS_WEBSOCKET_STREAM_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class AbortSignal;

class MODULES_EXPORT WebSocketStreamOptions : public IDLDictionaryBase {
 public:
  static WebSocketStreamOptions* Create() { return MakeGarbageCollected<WebSocketStreamOptions>(); }
  static WebSocketStreamOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<WebSocketStreamOptions>();
  }

  WebSocketStreamOptions();
  virtual ~WebSocketStreamOptions();

  bool hasProtocols() const { return has_protocols_; }
  const Vector<String>& protocols() const {
    DCHECK(has_protocols_);
    return protocols_;
  }
  void setProtocols(const Vector<String>&);

  bool hasSignal() const { return !!signal_; }
  AbortSignal* signal() const {
    return signal_;
  }
  inline void setSignal(AbortSignal*);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_protocols_ = false;

  Vector<String> protocols_;
  Member<AbortSignal> signal_;

  friend class V8WebSocketStreamOptions;
};

void WebSocketStreamOptions::setSignal(AbortSignal* value) {
  signal_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_WEBSOCKETS_WEBSOCKET_STREAM_OPTIONS_H_
