// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/peerconnection/rtc_insertable_streams.h"

#include "third_party/blink/renderer/core/streams/readable_stream.h"
#include "third_party/blink/renderer/core/streams/writable_stream.h"

namespace blink {

RTCInsertableStreams::RTCInsertableStreams() {
}

RTCInsertableStreams::~RTCInsertableStreams() = default;

void RTCInsertableStreams::Trace(Visitor* visitor) const {
  visitor->Trace(readable_stream_);
  visitor->Trace(writable_stream_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
