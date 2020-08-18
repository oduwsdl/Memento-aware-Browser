// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_FILE_SYSTEM_REMOVE_OPTIONS_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_FILE_SYSTEM_REMOVE_OPTIONS_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT FileSystemRemoveOptions : public IDLDictionaryBase {
 public:
  static FileSystemRemoveOptions* Create() { return MakeGarbageCollected<FileSystemRemoveOptions>(); }
  static FileSystemRemoveOptions* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<FileSystemRemoveOptions>();
  }

  FileSystemRemoveOptions();
  virtual ~FileSystemRemoveOptions();

  bool hasRecursive() const { return has_recursive_; }
  bool recursive() const {
    DCHECK(has_recursive_);
    return recursive_;
  }
  inline void setRecursive(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_recursive_ = false;

  bool recursive_;

  friend class V8FileSystemRemoveOptions;
};

void FileSystemRemoveOptions::setRecursive(bool value) {
  recursive_ = value;
  has_recursive_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_FILE_SYSTEM_REMOVE_OPTIONS_H_
