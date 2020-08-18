// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_VERTEX_FORMAT_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_VERTEX_FORMAT_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8GPUVertexFormat final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kUchar,
    kUchar2,
    kUchar3,
    kUchar4,
    kChar,
    kChar2,
    kChar3,
    kChar4,
    kUcharnorm,
    kUchar2Norm,
    kUchar3Norm,
    kUchar4Norm,
    kUchar4NormBgra,
    kCharnorm,
    kChar2Norm,
    kChar3Norm,
    kChar4Norm,
    kUshort,
    kUshort2,
    kUshort3,
    kUshort4,
    kShort,
    kShort2,
    kShort3,
    kShort4,
    kUshortnorm,
    kUshort2Norm,
    kUshort3Norm,
    kUshort4Norm,
    kShortnorm,
    kShort2Norm,
    kShort3Norm,
    kShort4Norm,
    kHalf,
    kHalf2,
    kHalf3,
    kHalf4,
    kFloat,
    kFloat2,
    kFloat3,
    kFloat4,
    kUint,
    kUint2,
    kUint3,
    kUint4,
    kInt,
    kInt2,
    kInt3,
    kInt4
  };

  static V8GPUVertexFormat Create(v8::Isolate* isolate,
                                  v8::Local<v8::Value> value,
                                  ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "GPUVertexFormat", exception_state);
    return result.has_value()
               ? V8GPUVertexFormat(static_cast<Enum>(result.value()))
               : V8GPUVertexFormat();
  }
  static base::Optional<V8GPUVertexFormat> Create(const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8GPUVertexFormat(static_cast<Enum>(result.value()));
  }

  constexpr V8GPUVertexFormat() = default;
  explicit constexpr V8GPUVertexFormat(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8GPUVertexFormat(const V8GPUVertexFormat&) = default;
  constexpr V8GPUVertexFormat(V8GPUVertexFormat&&) = default;
  ~V8GPUVertexFormat() = default;

  V8GPUVertexFormat& operator=(const V8GPUVertexFormat&) = default;
  V8GPUVertexFormat& operator=(V8GPUVertexFormat&&) = default;
  V8GPUVertexFormat& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {"uchar",
                                                        "uchar2",
                                                        "uchar3",
                                                        "uchar4",
                                                        "char",
                                                        "char2",
                                                        "char3",
                                                        "char4",
                                                        "ucharnorm",
                                                        "uchar2norm",
                                                        "uchar3norm",
                                                        "uchar4norm",
                                                        "uchar4norm-bgra",
                                                        "charnorm",
                                                        "char2norm",
                                                        "char3norm",
                                                        "char4norm",
                                                        "ushort",
                                                        "ushort2",
                                                        "ushort3",
                                                        "ushort4",
                                                        "short",
                                                        "short2",
                                                        "short3",
                                                        "short4",
                                                        "ushortnorm",
                                                        "ushort2norm",
                                                        "ushort3norm",
                                                        "ushort4norm",
                                                        "shortnorm",
                                                        "short2norm",
                                                        "short3norm",
                                                        "short4norm",
                                                        "half",
                                                        "half2",
                                                        "half3",
                                                        "half4",
                                                        "float",
                                                        "float2",
                                                        "float3",
                                                        "float4",
                                                        "uint",
                                                        "uint2",
                                                        "uint3",
                                                        "uint4",
                                                        "int",
                                                        "int2",
                                                        "int3",
                                                        "int4"};
};

inline bool operator==(const V8GPUVertexFormat& lhs,
                       V8GPUVertexFormat::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8GPUVertexFormat::Enum lhs,
                       const V8GPUVertexFormat& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_GPU_VERTEX_FORMAT_H_
