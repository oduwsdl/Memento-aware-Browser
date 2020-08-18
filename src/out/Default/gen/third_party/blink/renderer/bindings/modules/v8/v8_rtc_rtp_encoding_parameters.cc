// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_v8.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_rtp_encoding_parameters.h"

#include "base/stl_util.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_rtc_rtp_coding_parameters.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

static const base::span<const v8::Eternal<v8::Name>>
eternalV8RTCRtpEncodingParametersKeys(v8::Isolate* isolate) {
  static const char* const kKeys[] = {
    "active",
    "maxBitrate",
    "maxFramerate",
    "networkPriority",
    "priority",
    "scalabilityMode",
    "scaleResolutionDownBy",
  };
  return V8PerIsolateData::From(isolate)->FindOrCreateEternalNameCache(kKeys, kKeys);
}

void V8RTCRtpEncodingParameters::ToImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8_value, RTCRtpEncodingParameters* impl, ExceptionState& exception_state) {
  if (IsUndefinedOrNull(v8_value)) {
    return;
  }
  if (!v8_value->IsObject()) {
    exception_state.ThrowTypeError("cannot convert to dictionary.");
    return;
  }
  v8::Local<v8::Object> v8Object = v8_value.As<v8::Object>();
  ALLOW_UNUSED_LOCAL(v8Object);

  V8RTCRtpCodingParameters::ToImpl(isolate, v8_value, impl, exception_state);
  if (exception_state.HadException())
    return;

  const auto* keys = eternalV8RTCRtpEncodingParametersKeys(isolate).data();
  v8::TryCatch block(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Value> active_value;
  if (!v8Object->Get(context, keys[0].Get(isolate)).ToLocal(&active_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (active_value.IsEmpty() || active_value->IsUndefined()) {
    // Do nothing.
  } else {
    bool active_cpp_value = NativeValueTraits<IDLBoolean>::NativeValue(isolate, active_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setActive(active_cpp_value);
  }

  v8::Local<v8::Value> max_bitrate_value;
  if (!v8Object->Get(context, keys[1].Get(isolate)).ToLocal(&max_bitrate_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (max_bitrate_value.IsEmpty() || max_bitrate_value->IsUndefined()) {
    // Do nothing.
  } else {
    uint32_t max_bitrate_cpp_value = NativeValueTraits<IDLUnsignedLong>::NativeValue(isolate, max_bitrate_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setMaxBitrate(max_bitrate_cpp_value);
  }

  v8::Local<v8::Value> max_framerate_value;
  if (!v8Object->Get(context, keys[2].Get(isolate)).ToLocal(&max_framerate_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (max_framerate_value.IsEmpty() || max_framerate_value->IsUndefined()) {
    // Do nothing.
  } else {
    double max_framerate_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, max_framerate_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setMaxFramerate(max_framerate_cpp_value);
  }

  v8::Local<v8::Value> network_priority_value;
  if (!v8Object->Get(context, keys[3].Get(isolate)).ToLocal(&network_priority_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (network_priority_value.IsEmpty() || network_priority_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> network_priority_cpp_value = network_priority_value;
    if (!network_priority_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "very-low",
        "low",
        "medium",
        "high",
    };
    if (!IsValidEnum(network_priority_cpp_value, kValidValues, base::size(kValidValues), "RTCPriorityType", exception_state))
      return;
    impl->setNetworkPriority(network_priority_cpp_value);
  }

  v8::Local<v8::Value> priority_value;
  if (!v8Object->Get(context, keys[4].Get(isolate)).ToLocal(&priority_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (priority_value.IsEmpty() || priority_value->IsUndefined()) {
    // Do nothing.
  } else {
    V8StringResource<> priority_cpp_value = priority_value;
    if (!priority_cpp_value.Prepare(exception_state))
      return;
    const char* const kValidValues[] = {
        "very-low",
        "low",
        "medium",
        "high",
    };
    if (!IsValidEnum(priority_cpp_value, kValidValues, base::size(kValidValues), "RTCPriorityType", exception_state))
      return;
    impl->setPriority(priority_cpp_value);
  }

  v8::Local<v8::Value> scale_resolution_down_by_value;
  if (!v8Object->Get(context, keys[6].Get(isolate)).ToLocal(&scale_resolution_down_by_value)) {
    exception_state.RethrowV8Exception(block.Exception());
    return;
  }
  if (scale_resolution_down_by_value.IsEmpty() || scale_resolution_down_by_value->IsUndefined()) {
    // Do nothing.
  } else {
    double scale_resolution_down_by_cpp_value = NativeValueTraits<IDLDouble>::NativeValue(isolate, scale_resolution_down_by_value, exception_state);
    if (exception_state.HadException())
      return;
    impl->setScaleResolutionDownBy(scale_resolution_down_by_cpp_value);
  }

  if (RuntimeEnabledFeatures::RTCSvcScalabilityModeEnabled()) {
    v8::Local<v8::Value> scalability_mode_value;
    if (!v8Object->Get(context, keys[5].Get(isolate)).ToLocal(&scalability_mode_value)) {
      exception_state.RethrowV8Exception(block.Exception());
      return;
    }
    if (scalability_mode_value.IsEmpty() || scalability_mode_value->IsUndefined()) {
      // Do nothing.
    } else {
      V8StringResource<> scalability_mode_cpp_value = scalability_mode_value;
      if (!scalability_mode_cpp_value.Prepare(exception_state))
        return;
      impl->setScalabilityMode(scalability_mode_cpp_value);
    }
  }
}

v8::Local<v8::Value> RTCRtpEncodingParameters::ToV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const {
  v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
  if (!toV8RTCRtpEncodingParameters(this, v8Object, creationContext, isolate))
    return v8::Undefined(isolate);
  return v8Object;
}

bool toV8RTCRtpEncodingParameters(const RTCRtpEncodingParameters* impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  if (!toV8RTCRtpCodingParameters(impl, dictionary, creationContext, isolate))
    return false;

  const auto* keys = eternalV8RTCRtpEncodingParametersKeys(isolate).data();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  auto create_property = [dictionary, context, keys, isolate](
                             size_t key_index, v8::Local<v8::Value> value) {
    bool added_property;
    v8::Local<v8::Name> key = keys[key_index].Get(isolate);
    if (!dictionary->CreateDataProperty(context, key, value)
             .To(&added_property)) {
      return false;
    }
    return added_property;
  };

  v8::Local<v8::Value> active_value;
  bool active_has_value_or_default = false;
  if (impl->hasActive()) {
    active_value = v8::Boolean::New(isolate, impl->active());
    active_has_value_or_default = true;
  } else {
    active_value = v8::Boolean::New(isolate, true);
    active_has_value_or_default = true;
  }
  if (active_has_value_or_default &&
      !create_property(0, active_value)) {
    return false;
  }

  v8::Local<v8::Value> max_bitrate_value;
  bool max_bitrate_has_value_or_default = false;
  if (impl->hasMaxBitrate()) {
    max_bitrate_value = v8::Integer::NewFromUnsigned(isolate, impl->maxBitrate());
    max_bitrate_has_value_or_default = true;
  }
  if (max_bitrate_has_value_or_default &&
      !create_property(1, max_bitrate_value)) {
    return false;
  }

  v8::Local<v8::Value> max_framerate_value;
  bool max_framerate_has_value_or_default = false;
  if (impl->hasMaxFramerate()) {
    max_framerate_value = v8::Number::New(isolate, impl->maxFramerate());
    max_framerate_has_value_or_default = true;
  }
  if (max_framerate_has_value_or_default &&
      !create_property(2, max_framerate_value)) {
    return false;
  }

  v8::Local<v8::Value> network_priority_value;
  bool network_priority_has_value_or_default = false;
  if (impl->hasNetworkPriority()) {
    network_priority_value = V8String(isolate, impl->networkPriority());
    network_priority_has_value_or_default = true;
  } else {
    network_priority_value = V8String(isolate, "low");
    network_priority_has_value_or_default = true;
  }
  if (network_priority_has_value_or_default &&
      !create_property(3, network_priority_value)) {
    return false;
  }

  v8::Local<v8::Value> priority_value;
  bool priority_has_value_or_default = false;
  if (impl->hasPriority()) {
    priority_value = V8String(isolate, impl->priority());
    priority_has_value_or_default = true;
  } else {
    priority_value = V8String(isolate, "low");
    priority_has_value_or_default = true;
  }
  if (priority_has_value_or_default &&
      !create_property(4, priority_value)) {
    return false;
  }

  v8::Local<v8::Value> scale_resolution_down_by_value;
  bool scale_resolution_down_by_has_value_or_default = false;
  if (impl->hasScaleResolutionDownBy()) {
    scale_resolution_down_by_value = v8::Number::New(isolate, impl->scaleResolutionDownBy());
    scale_resolution_down_by_has_value_or_default = true;
  }
  if (scale_resolution_down_by_has_value_or_default &&
      !create_property(6, scale_resolution_down_by_value)) {
    return false;
  }

  if (RuntimeEnabledFeatures::RTCSvcScalabilityModeEnabled()) {
    v8::Local<v8::Value> scalability_mode_value;
    bool scalability_mode_has_value_or_default = false;
    if (impl->hasScalabilityMode()) {
      scalability_mode_value = V8String(isolate, impl->scalabilityMode());
      scalability_mode_has_value_or_default = true;
    }
    if (scalability_mode_has_value_or_default &&
        !create_property(5, scalability_mode_value)) {
      return false;
    }
  }

  return true;
}

RTCRtpEncodingParameters* NativeValueTraits<RTCRtpEncodingParameters>::NativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exception_state) {
  RTCRtpEncodingParameters* impl = MakeGarbageCollected<RTCRtpEncodingParameters>();
  V8RTCRtpEncodingParameters::ToImpl(isolate, value, impl, exception_state);
  return impl;
}

}  // namespace blink
