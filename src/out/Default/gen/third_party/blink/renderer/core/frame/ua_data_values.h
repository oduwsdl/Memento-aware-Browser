// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_UA_DATA_VALUES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_UA_DATA_VALUES_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class CORE_EXPORT UADataValues : public IDLDictionaryBase {
 public:
  static UADataValues* Create() { return MakeGarbageCollected<UADataValues>(); }
  static UADataValues* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<UADataValues>();
  }

  UADataValues();
  virtual ~UADataValues();

  bool hasArchitecture() const { return !architecture_.IsNull(); }
  const String& architecture() const {
    return architecture_;
  }
  inline void setArchitecture(const String&);

  bool hasModel() const { return !model_.IsNull(); }
  const String& model() const {
    return model_;
  }
  inline void setModel(const String&);

  bool hasPlatform() const { return !platform_.IsNull(); }
  const String& platform() const {
    return platform_;
  }
  inline void setPlatform(const String&);

  bool hasPlatformVersion() const { return !platform_version_.IsNull(); }
  const String& platformVersion() const {
    return platform_version_;
  }
  inline void setPlatformVersion(const String&);

  bool hasUaFullVersion() const { return !ua_full_version_.IsNull(); }
  const String& uaFullVersion() const {
    return ua_full_version_;
  }
  inline void setUaFullVersion(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String architecture_;
  String model_;
  String platform_;
  String platform_version_;
  String ua_full_version_;

  friend class V8UADataValues;
};

void UADataValues::setArchitecture(const String& value) {
  architecture_ = value;
}

void UADataValues::setModel(const String& value) {
  model_ = value;
}

void UADataValues::setPlatform(const String& value) {
  platform_ = value;
}

void UADataValues::setPlatformVersion(const String& value) {
  platform_version_ = value;
}

void UADataValues::setUaFullVersion(const String& value) {
  ua_full_version_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_UA_DATA_VALUES_H_
