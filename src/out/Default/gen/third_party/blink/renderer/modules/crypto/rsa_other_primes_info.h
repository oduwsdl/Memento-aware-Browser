// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_CRYPTO_RSA_OTHER_PRIMES_INFO_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_CRYPTO_RSA_OTHER_PRIMES_INFO_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class MODULES_EXPORT RsaOtherPrimesInfo : public IDLDictionaryBase {
 public:
  static RsaOtherPrimesInfo* Create() { return MakeGarbageCollected<RsaOtherPrimesInfo>(); }
  static RsaOtherPrimesInfo* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<RsaOtherPrimesInfo>();
  }

  RsaOtherPrimesInfo();
  virtual ~RsaOtherPrimesInfo();

  bool hasD() const { return !d_.IsNull(); }
  const String& d() const {
    return d_;
  }
  inline void setD(const String&);

  bool hasR() const { return !r_.IsNull(); }
  const String& r() const {
    return r_;
  }
  inline void setR(const String&);

  bool hasT() const { return !t_.IsNull(); }
  const String& t() const {
    return t_;
  }
  inline void setT(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:

  String d_;
  String r_;
  String t_;

  friend class V8RsaOtherPrimesInfo;
};

void RsaOtherPrimesInfo::setD(const String& value) {
  d_ = value;
}

void RsaOtherPrimesInfo::setR(const String& value) {
  r_ = value;
}

void RsaOtherPrimesInfo::setT(const String& value) {
  t_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_CRYPTO_RSA_OTHER_PRIMES_INFO_H_
