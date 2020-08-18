// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_DRAG_EVENT_INIT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_DRAG_EVENT_INIT_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/events/mouse_event_init.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class DataTransfer;

class CORE_EXPORT DragEventInit : public MouseEventInit {
 public:
  static DragEventInit* Create() { return MakeGarbageCollected<DragEventInit>(); }
  static DragEventInit* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<DragEventInit>();
  }

  DragEventInit();
  virtual ~DragEventInit();

  bool hasGetDataTransfer() const { return has_get_data_transfer_; }
  DataTransfer* getDataTransfer() const {
    return get_data_transfer_;
  }
  inline void setGetDataTransfer(DataTransfer*);
  inline void setGetDataTransferToNull();
  // Migration adapters
  // Returns true iff this member has a non-null value.  Returns false if the
  // value is missing or a null value.
  bool hasGetDataTransferNonNull() const { return has_get_data_transfer_; }
  // Returns the value if this member has a non-null value.  Call
  // |hasGetDataTransferNonNull| in advance to check the condition.
  DataTransfer* getDataTransferNonNull() const {
    DCHECK(hasGetDataTransferNonNull());
    return get_data_transfer_;
  }

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_get_data_transfer_ = false;

  Member<DataTransfer> get_data_transfer_;

  friend class V8DragEventInit;
};

void DragEventInit::setGetDataTransfer(DataTransfer* value) {
  get_data_transfer_ = value;
  has_get_data_transfer_ = true;
}

void DragEventInit::setGetDataTransferToNull() {
  get_data_transfer_ = Member<DataTransfer>();
  has_get_data_transfer_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_DRAG_EVENT_INIT_H_
