// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SPEECH_SYNTHESIS_ERROR_CODE_H_
#define THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SPEECH_SYNTHESIS_ERROR_CODE_H_

#include "third_party/blink/renderer/bindings/core/v8/generated_code_helper.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/enumeration_base.h"

namespace blink {

class MODULES_EXPORT V8SpeechSynthesisErrorCode final
    : public bindings::EnumerationBase {
 public:
  enum class Enum : enum_int_t {
    kCanceled,
    kInterrupted,
    kAudioBusy,
    kAudioHardware,
    kNetwork,
    kSynthesisUnavailable,
    kSynthesisFailed,
    kLanguageUnavailable,
    kVoiceUnavailable,
    kTextTooLong,
    kInvalidArgument,
    kNotAllowed
  };

  static V8SpeechSynthesisErrorCode Create(v8::Isolate* isolate,
                                           v8::Local<v8::Value> value,
                                           ExceptionState& exception_state) {
    const auto& result = bindings::FindIndexInEnumStringTable(
        isolate, value, string_table_, "SpeechSynthesisErrorCode",
        exception_state);
    return result.has_value()
               ? V8SpeechSynthesisErrorCode(static_cast<Enum>(result.value()))
               : V8SpeechSynthesisErrorCode();
  }
  static base::Optional<V8SpeechSynthesisErrorCode> Create(
      const String& value) {
    const auto& result =
        bindings::FindIndexInEnumStringTable(value, string_table_);
    if (!result)
      return base::nullopt;
    return V8SpeechSynthesisErrorCode(static_cast<Enum>(result.value()));
  }

  constexpr V8SpeechSynthesisErrorCode() = default;
  explicit constexpr V8SpeechSynthesisErrorCode(Enum value)
      : bindings::EnumerationBase(
            static_cast<enum_int_t>(value),
            string_table_[static_cast<enum_int_t>(value)]) {}
  constexpr V8SpeechSynthesisErrorCode(const V8SpeechSynthesisErrorCode&) =
      default;
  constexpr V8SpeechSynthesisErrorCode(V8SpeechSynthesisErrorCode&&) = default;
  ~V8SpeechSynthesisErrorCode() = default;

  V8SpeechSynthesisErrorCode& operator=(const V8SpeechSynthesisErrorCode&) =
      default;
  V8SpeechSynthesisErrorCode& operator=(V8SpeechSynthesisErrorCode&&) = default;
  V8SpeechSynthesisErrorCode& operator=(const String&);

  Enum AsEnum() const { return static_cast<Enum>(GetEnumValue()); }

 private:
  static constexpr const char* const string_table_[] = {
      "canceled",          "interrupted",
      "audio-busy",        "audio-hardware",
      "network",           "synthesis-unavailable",
      "synthesis-failed",  "language-unavailable",
      "voice-unavailable", "text-too-long",
      "invalid-argument",  "not-allowed"};
};

inline bool operator==(const V8SpeechSynthesisErrorCode& lhs,
                       V8SpeechSynthesisErrorCode::Enum rhs) {
  return lhs.AsEnum() == rhs;
}

inline bool operator==(V8SpeechSynthesisErrorCode::Enum lhs,
                       const V8SpeechSynthesisErrorCode& rhs) {
  return lhs == rhs.AsEnum();
}

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_BINDINGS_MODULES_V8_V8_SPEECH_SYNTHESIS_ERROR_CODE_H_
