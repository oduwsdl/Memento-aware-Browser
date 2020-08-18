// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_NAVIGATOR_UA_BRAND_VERSION_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_NAVIGATOR_UA_BRAND_VERSION_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT NavigatorUABrandVersion : public IDLDictionaryBase {
 public:
  static NavigatorUABrandVersion* Create() { return MakeGarbageCollected<NavigatorUABrandVersion>(); }
  static NavigatorUABrandVersion* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<NavigatorUABrandVersion>();
  }

  NavigatorUABrandVersion();
  virtual ~NavigatorUABrandVersion();

  bool hasBrand() const { return !brand_.IsNull(); }
  const String& brand() const {
    return brand_;
  }
  inline void setBrand(const String&);

  bool hasVersion() const { return !version_.IsNull(); }
  const String& version() const {
    return version_;
  }
  inline void setVersion(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String brand_;
  String version_;

  friend class V8NavigatorUABrandVersion;
};

void NavigatorUABrandVersion::setBrand(const String& value) {
  brand_ = value;
}

void NavigatorUABrandVersion::setVersion(const String& value) {
  version_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_NAVIGATOR_UA_BRAND_VERSION_H_
