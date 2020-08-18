// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_STORAGE_STORAGE_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_STORAGE_STORAGE_EVENT_INIT_H_

#include "third_party/blink/renderer/core/dom/events/event_init.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class StorageArea;

class MODULES_EXPORT StorageEventInit : public EventInit {
 public:
  static StorageEventInit* Create() { return MakeGarbageCollected<StorageEventInit>(); }
  static StorageEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<StorageEventInit>();
  }

  StorageEventInit();
  virtual ~StorageEventInit();

  bool hasKey() const { return !key_.IsNull(); }
  const String& key() const {
    return key_;
  }
  inline void setKey(const String&);
  inline void setKeyToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasKeyNonNull() const { return !key_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasKeyNonNull| in advance to check the condition.
  const String& keyNonNull() const {
    DCHECK(hasKeyNonNull());
    return key_;
  }

  bool hasNewValue() const { return !new_value_.IsNull(); }
  const String& newValue() const {
    return new_value_;
  }
  inline void setNewValue(const String&);
  inline void setNewValueToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasNewValueNonNull() const { return !new_value_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasNewValueNonNull| in advance to check the condition.
  const String& newValueNonNull() const {
    DCHECK(hasNewValueNonNull());
    return new_value_;
  }

  bool hasOldValue() const { return !old_value_.IsNull(); }
  const String& oldValue() const {
    return old_value_;
  }
  inline void setOldValue(const String&);
  inline void setOldValueToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasOldValueNonNull() const { return !old_value_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasOldValueNonNull| in advance to check the condition.
  const String& oldValueNonNull() const {
    DCHECK(hasOldValueNonNull());
    return old_value_;
  }

  bool hasStorageArea() const { return has_storage_area_; }
  StorageArea* storageArea() const {
    return storage_area_;
  }
  inline void setStorageArea(StorageArea*);
  inline void setStorageAreaToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasStorageAreaNonNull() const { return has_storage_area_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasStorageAreaNonNull| in advance to check the condition.
  StorageArea* storageAreaNonNull() const {
    DCHECK(hasStorageAreaNonNull());
    return storage_area_;
  }

  bool hasUrl() const { return !url_.IsNull(); }
  const String& url() const {
    return url_;
  }
  inline void setUrl(const String&);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_storage_area_ = false;

  String key_;
  String new_value_;
  String old_value_;
  Member<StorageArea> storage_area_;
  String url_;

  friend class V8StorageEventInit;
};

void StorageEventInit::setKey(const String& value) {
  key_ = value;
}

void StorageEventInit::setKeyToNull() {
  key_ = String();
}

void StorageEventInit::setNewValue(const String& value) {
  new_value_ = value;
}

void StorageEventInit::setNewValueToNull() {
  new_value_ = String();
}

void StorageEventInit::setOldValue(const String& value) {
  old_value_ = value;
}

void StorageEventInit::setOldValueToNull() {
  old_value_ = String();
}

void StorageEventInit::setStorageArea(StorageArea* value) {
  storage_area_ = value;
  has_storage_area_ = true;
}

void StorageEventInit::setStorageAreaToNull() {
  storage_area_ = Member<StorageArea>();
  has_storage_area_ = true;
}

void StorageEventInit::setUrl(const String& value) {
  url_ = value;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_STORAGE_STORAGE_EVENT_INIT_H_
