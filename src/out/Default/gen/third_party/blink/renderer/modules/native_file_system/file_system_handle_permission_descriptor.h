// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_FILE_SYSTEM_HANDLE_PERMISSION_DESCRIPTOR_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_FILE_SYSTEM_HANDLE_PERMISSION_DESCRIPTOR_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT FileSystemHandlePermissionDescriptor : public IDLDictionaryBase {
 public:
  static FileSystemHandlePermissionDescriptor* Create() { return MakeGarbageCollected<FileSystemHandlePermissionDescriptor>(); }
  static FileSystemHandlePermissionDescriptor* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<FileSystemHandlePermissionDescriptor>();
  }

  FileSystemHandlePermissionDescriptor();
  virtual ~FileSystemHandlePermissionDescriptor();

  bool hasWritable() const { return has_writable_; }
  bool writable() const {
    DCHECK(has_writable_);
    return writable_;
  }
  inline void setWritable(bool);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_writable_ = false;

  bool writable_;

  friend class V8FileSystemHandlePermissionDescriptor;
};

void FileSystemHandlePermissionDescriptor::setWritable(bool value) {
  writable_ = value;
  has_writable_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_NATIVE_FILE_SYSTEM_FILE_SYSTEM_HANDLE_PERMISSION_DESCRIPTOR_H_
