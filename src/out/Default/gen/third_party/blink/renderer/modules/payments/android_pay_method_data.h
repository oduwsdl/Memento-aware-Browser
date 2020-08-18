// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_ANDROID_PAY_METHOD_DATA_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_ANDROID_PAY_METHOD_DATA_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT AndroidPayMethodData : public IDLDictionaryBase {
 public:
  static AndroidPayMethodData* Create() { return MakeGarbageCollected<AndroidPayMethodData>(); }
  static AndroidPayMethodData* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<AndroidPayMethodData>();
  }

  AndroidPayMethodData();
  virtual ~AndroidPayMethodData();

  bool hasApiVersion() const { return has_api_version_; }
  int32_t apiVersion() const {
    DCHECK(has_api_version_);
    return api_version_;
  }
  inline void setApiVersion(int32_t);

  bool hasEnvironment() const { return !environment_.IsNull(); }
  const String& environment() const {
    return environment_;
  }
  inline void setEnvironment(const String&);

  bool hasMinGooglePlayServicesVersion() const { return !min_google_play_services_version_.IsNull(); }
  const String& minGooglePlayServicesVersion() const {
    return min_google_play_services_version_;
  }
  inline void setMinGooglePlayServicesVersion(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_api_version_ = false;

  int32_t api_version_;
  String environment_;
  String min_google_play_services_version_;

  friend class V8AndroidPayMethodData;
};

void AndroidPayMethodData::setApiVersion(int32_t value) {
  api_version_ = value;
  has_api_version_ = true;
}

void AndroidPayMethodData::setEnvironment(const String& value) {
  environment_ = value;
}

void AndroidPayMethodData::setMinGooglePlayServicesVersion(const String& value) {
  min_google_play_services_version_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_PAYMENTS_ANDROID_PAY_METHOD_DATA_H_
