// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_BACKGROUND_FETCH_BACKGROUND_FETCH_UI_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_BACKGROUND_FETCH_BACKGROUND_FETCH_UI_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class ManifestImageResource;

class MODULES_EXPORT BackgroundFetchUIOptions : public IDLDictionaryBase {
 public:
  static BackgroundFetchUIOptions* Create() { return MakeGarbageCollected<BackgroundFetchUIOptions>(); }
  static BackgroundFetchUIOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<BackgroundFetchUIOptions>();
  }

  BackgroundFetchUIOptions();
  virtual ~BackgroundFetchUIOptions();

  bool hasIcons() const { return has_icons_; }
  const HeapVector<Member<ManifestImageResource>>& icons() const {
    DCHECK(has_icons_);
    return icons_;
  }
  void setIcons(const HeapVector<Member<ManifestImageResource>>&);

  bool hasTitle() const { return !title_.IsNull(); }
  const String& title() const {
    return title_;
  }
  inline void setTitle(const String&);
  inline void setTitleToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasTitleNonNull() const { return !title_.IsNull(); }
  // Returns the value if this member has a non-null value.  Call
  // |hasTitleNonNull| in advance to check the condition.
  const String& titleNonNull() const {
    DCHECK(hasTitleNonNull());
    return title_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_icons_ = false;

  HeapVector<Member<ManifestImageResource>> icons_;
  String title_;

  friend class V8BackgroundFetchUIOptions;
};

void BackgroundFetchUIOptions::setTitle(const String& value) {
  title_ = value;
}

void BackgroundFetchUIOptions::setTitleToNull() {
  title_ = String();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_BACKGROUND_FETCH_BACKGROUND_FETCH_UI_OPTIONS_H_
