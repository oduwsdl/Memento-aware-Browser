// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.h.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_PORT_FILTER_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_PORT_FILTER_H_

#include "third_party/blink/renderer/bindings/core/v8/idl_dictionary_base.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/heap/handle.h"

namespace blink {

class MODULES_EXPORT SerialPortFilter : public IDLDictionaryBase {
 public:
  static SerialPortFilter* Create() { return MakeGarbageCollected<SerialPortFilter>(); }
  static SerialPortFilter* Create(v8::Isolate* isolate) {
    return MakeGarbageCollected<SerialPortFilter>();
  }

  SerialPortFilter();
  virtual ~SerialPortFilter();

  bool hasUsbProductId() const { return has_usb_product_id_; }
  uint16_t usbProductId() const {
    DCHECK(has_usb_product_id_);
    return usb_product_id_;
  }
  inline void setUsbProductId(uint16_t);

  bool hasUsbVendorId() const { return has_usb_vendor_id_; }
  uint16_t usbVendorId() const {
    DCHECK(has_usb_vendor_id_);
    return usb_vendor_id_;
  }
  inline void setUsbVendorId(uint16_t);

  v8::Local<v8::Value> ToV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  void Trace(Visitor*) const override;

 private:
  bool has_usb_product_id_ = false;
  bool has_usb_vendor_id_ = false;

  uint16_t usb_product_id_;
  uint16_t usb_vendor_id_;

  friend class V8SerialPortFilter;
};

void SerialPortFilter::setUsbProductId(uint16_t value) {
  usb_product_id_ = value;
  has_usb_product_id_ = true;
}

void SerialPortFilter::setUsbVendorId(uint16_t value) {
  usb_vendor_id_ = value;
  has_usb_vendor_id_ = true;
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SERIAL_SERIAL_PORT_FILTER_H_
