// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_CRYPTO_JSON_WEB_KEY_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_CRYPTO_JSON_WEB_KEY_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class RsaOtherPrimesInfo;

class MODULES_EXPORT JsonWebKey : public IDLDictionaryBase {
 public:
  static JsonWebKey* Create() { return MakeGarbageCollected<JsonWebKey>(); }
  static JsonWebKey* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<JsonWebKey>();
  }

  JsonWebKey();
  virtual ~JsonWebKey();

  bool hasAlg() const { return !alg_.IsNull(); }
  const String& alg() const {
    return alg_;
  }
  inline void setAlg(const String&);

  bool hasCrv() const { return !crv_.IsNull(); }
  const String& crv() const {
    return crv_;
  }
  inline void setCrv(const String&);

  bool hasD() const { return !d_.IsNull(); }
  const String& d() const {
    return d_;
  }
  inline void setD(const String&);

  bool hasDp() const { return !dp_.IsNull(); }
  const String& dp() const {
    return dp_;
  }
  inline void setDp(const String&);

  bool hasDq() const { return !dq_.IsNull(); }
  const String& dq() const {
    return dq_;
  }
  inline void setDq(const String&);

  bool hasE() const { return !e_.IsNull(); }
  const String& e() const {
    return e_;
  }
  inline void setE(const String&);

  bool hasExt() const { return has_ext_; }
  bool ext() const {
    DCHECK(has_ext_);
    return ext_;
  }
  inline void setExt(bool);

  bool hasK() const { return !k_.IsNull(); }
  const String& k() const {
    return k_;
  }
  inline void setK(const String&);

  bool hasKeyOps() const { return has_key_ops_; }
  const Vector<String>& keyOps() const {
    DCHECK(has_key_ops_);
    return key_ops_;
  }
  void setKeyOps(const Vector<String>&);

  bool hasKty() const { return !kty_.IsNull(); }
  const String& kty() const {
    return kty_;
  }
  inline void setKty(const String&);

  bool hasN() const { return !n_.IsNull(); }
  const String& n() const {
    return n_;
  }
  inline void setN(const String&);

  bool hasOth() const { return has_oth_; }
  const HeapVector<Member<RsaOtherPrimesInfo>>& oth() const {
    DCHECK(has_oth_);
    return oth_;
  }
  void setOth(const HeapVector<Member<RsaOtherPrimesInfo>>&);

  bool hasP() const { return !p_.IsNull(); }
  const String& p() const {
    return p_;
  }
  inline void setP(const String&);

  bool hasQ() const { return !q_.IsNull(); }
  const String& q() const {
    return q_;
  }
  inline void setQ(const String&);

  bool hasQi() const { return !qi_.IsNull(); }
  const String& qi() const {
    return qi_;
  }
  inline void setQi(const String&);

  bool hasUse() const { return !use_.IsNull(); }
  const String& use() const {
    return use_;
  }
  inline void setUse(const String&);

  bool hasX() const { return !x_.IsNull(); }
  const String& x() const {
    return x_;
  }
  inline void setX(const String&);

  bool hasY() const { return !y_.IsNull(); }
  const String& y() const {
    return y_;
  }
  inline void setY(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_ext_ = false;
  bool has_key_ops_ = false;
  bool has_oth_ = false;

  String alg_;
  String crv_;
  String d_;
  String dp_;
  String dq_;
  String e_;
  bool ext_;
  String k_;
  Vector<String> key_ops_;
  String kty_;
  String n_;
  HeapVector<Member<RsaOtherPrimesInfo>> oth_;
  String p_;
  String q_;
  String qi_;
  String use_;
  String x_;
  String y_;

  friend class V8JsonWebKey;
};

void JsonWebKey::setAlg(const String& value) {
  alg_ = value;
}

void JsonWebKey::setCrv(const String& value) {
  crv_ = value;
}

void JsonWebKey::setD(const String& value) {
  d_ = value;
}

void JsonWebKey::setDp(const String& value) {
  dp_ = value;
}

void JsonWebKey::setDq(const String& value) {
  dq_ = value;
}

void JsonWebKey::setE(const String& value) {
  e_ = value;
}

void JsonWebKey::setExt(bool value) {
  ext_ = value;
  has_ext_ = true;
}

void JsonWebKey::setK(const String& value) {
  k_ = value;
}

void JsonWebKey::setKty(const String& value) {
  kty_ = value;
}

void JsonWebKey::setN(const String& value) {
  n_ = value;
}

void JsonWebKey::setP(const String& value) {
  p_ = value;
}

void JsonWebKey::setQ(const String& value) {
  q_ = value;
}

void JsonWebKey::setQi(const String& value) {
  qi_ = value;
}

void JsonWebKey::setUse(const String& value) {
  use_ = value;
}

void JsonWebKey::setX(const String& value) {
  x_ = value;
}

void JsonWebKey::setY(const String& value) {
  y_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_CRYPTO_JSON_WEB_KEY_H_
