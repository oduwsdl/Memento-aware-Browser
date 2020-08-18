// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BARCODE_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BARCODE_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8BarcodeFormat final : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kAztec,
    kCode128,
    kCode39,
    kCode93,
    kCodabar,
    kDataMatrix,
    kEan13,
    kEan8,
    kItf,
    kPdf417,
    kQrCode,
    kUnknown,
    kUpcA,
    kUpcE
  };

  static V8BarcodeFormat Create(v8::Isolate* isolate,
                                v8::Local<v8::Value> value,
                                ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "BarcodeFormat", exception_state);
    return result.has_value()
               ? V8BarcodeFormat(static_cast<Enum>(result.value()))
               : V8BarcodeFormat();
  }
  static base::Optional<V8BarcodeFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8BarcodeFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8BarcodeFormat() = default;
  explicit constexpr V8BarcodeFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8BarcodeFormat(const V8BarcodeFormat&) = default;
  constexpr V8BarcodeFormat(V8BarcodeFormat&&) = default;
  ~V8BarcodeFormat() = default;

  V8BarcodeFormat& operator=(const V8BarcodeFormat&) = default;
  V8BarcodeFormat& operator=(V8BarcodeFormat&&) = default;
  V8BarcodeFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "aztec",       "code_128", "code_39", "code_93", "codabar",
      "data_matrix", "ean_13",   "ean_8",   "itf",     "pdf417",
      "qr_code",     "unknown",  "upc_a",   "upc_e"};
};

inline bool operator==(const V8BarcodeFormat& lhs, V8BarcodeFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8BarcodeFormat::Enum lhs, const V8BarcodeFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_BARCODE_FORMAT_H_
