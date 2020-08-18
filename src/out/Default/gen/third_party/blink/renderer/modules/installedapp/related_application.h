// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_INSTALLEDAPP_RELATED_APPLICATION_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_INSTALLEDAPP_RELATED_APPLICATION_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT RelatedApplication : public IDLDictionaryBase {
 public:
  static RelatedApplication* Create() { return MakeGarbageCollected<RelatedApplication>(); }
  static RelatedApplication* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RelatedApplication>();
  }

  RelatedApplication();
  virtual ~RelatedApplication();

  bool hasId() const { return !id_.IsNull(); }
  const String& id() const {
    return id_;
  }
  inline void setId(const String&);

  bool hasPlatform() const { return !platform_.IsNull(); }
  const String& platform() const {
    return platform_;
  }
  inline void setPlatform(const String&);

  bool hasUrl() const { return !url_.IsNull(); }
  const String& url() const {
    return url_;
  }
  inline void setUrl(const String&);

  bool hasVersion() const { return !version_.IsNull(); }
  const String& version() const {
    return version_;
  }
  inline void setVersion(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String id_;
  String platform_;
  String url_;
  String version_;

  friend class V8RelatedApplication;
};

void RelatedApplication::setId(const String& value) {
  id_ = value;
}

void RelatedApplication::setPlatform(const String& value) {
  platform_ = value;
}

void RelatedApplication::setUrl(const String& value) {
  url_ = value;
}

void RelatedApplication::setVersion(const String& value) {
  version_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_INSTALLEDAPP_RELATED_APPLICATION_H_
