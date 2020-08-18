// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/interface.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_frame.h"

#include <algorithm>

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/bindings/core/v8/idl_types.h"
#include "third_party/blink/renderer/bindings/core/v8/native_value_traits_impl.h"
#include "third_party/blink/renderer/bindings/core/v8/script_promise.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_dom_configuration.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_anchor_set.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_hit_test_result.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_hit_test_source.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_light_estimate.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_light_probe.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_pose.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_reference_space.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_rigid_transform.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_session.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_space.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_transient_input_hit_test_result.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_transient_input_hit_test_source.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_viewer_pose.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_xr_world_information.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/web_feature.h"
#include "third_party/blink/renderer/platform/bindings/exception_messages.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/runtime_call_stats.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_object_constructor.h"
#include "third_party/blink/renderer/platform/bindings/v8_private_property.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/scheduler/public/cooperative_scheduling_manager.h"
#include "third_party/blink/renderer/platform/wtf/get_ptr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo v8_xr_frame_wrapper_type_info = {
    gin::kEmbedderBlink,
    V8XRFrame::DomTemplate,
    V8XRFrame::InstallConditionalFeatures,
    "XRFrame",
    nullptr,
    WrapperTypeInfo::kWrapperTypeObjectPrototype,
    WrapperTypeInfo::kObjectClassId,
    WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
};
#if defined(COMPONENT_BUILD) && defined(WIN32) && defined(__clang__)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in XRFrame.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// platform/bindings/ScriptWrappable.h.
const WrapperTypeInfo& XRFrame::wrapper_type_info_ = v8_xr_frame_wrapper_type_info;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, XRFrame>::value,
    "XRFrame inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&XRFrame::HasPendingActivity),
                 decltype(&ScriptWrappable::HasPendingActivity)>::value,
    "XRFrame is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace xr_frame_v8_internal {

static void SessionAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  XRFrame* impl = V8XRFrame::ToImpl(holder);

  XRSession* cpp_value(WTF::GetPtr(impl->session()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void WorldInformationAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  XRFrame* impl = V8XRFrame::ToImpl(holder);

  XRWorldInformation* cpp_value(WTF::GetPtr(impl->worldInformation()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void TrackedAnchorsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  XRFrame* impl = V8XRFrame::ToImpl(holder);

  XRAnchorSet* cpp_value(WTF::GetPtr(impl->trackedAnchors()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cpp_value && DOMDataStore::SetReturnValue(info.GetReturnValue(), cpp_value))
    return;
  v8::Local<v8::Value> v8_value(ToV8(cpp_value, holder, info.GetIsolate()));
  static const V8PrivateProperty::SymbolKey kKeepAliveKey;
  V8PrivateProperty::GetSymbol(info.GetIsolate(), kKeepAliveKey)
      .Set(holder, v8_value);

  V8SetReturnValue(info, v8_value);
}

static void CreateAnchorMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "XRFrame", "createAnchor");
  ExceptionToRejectPromiseScope reject_promise_scope(info, exception_state);

  // V8DOMConfiguration::kDoNotCheckHolder
  // Make sure that info.Holder() really points to an instance of the type.
  if (!V8XRFrame::HasInstance(info.Holder(), info.GetIsolate())) {
    exception_state.ThrowTypeError("Illegal invocation");
    return;
  }
  XRFrame* impl = V8XRFrame::ToImpl(info.Holder());

  ScriptState* script_state = ScriptState::ForRelevantRealm(info);

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  XRRigidTransform* initial_pose;
  XRSpace* space;
  initial_pose = V8XRRigidTransform::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!initial_pose) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "XRRigidTransform"));
    return;
  }

  space = V8XRSpace::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!space) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "XRSpace"));
    return;
  }

  ScriptPromise result = impl->createAnchor(script_state, initial_pose, space, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result.V8Value());
}

static void GetViewerPoseMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "XRFrame", "getViewerPose");

  XRFrame* impl = V8XRFrame::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  XRReferenceSpace* reference_space;
  reference_space = V8XRReferenceSpace::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!reference_space) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "XRReferenceSpace"));
    return;
  }

  XRViewerPose* result = impl->getViewerPose(reference_space, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result);
}

static void GetPoseMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "XRFrame", "getPose");

  XRFrame* impl = V8XRFrame::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(2, info.Length()));
    return;
  }

  XRSpace* space;
  XRSpace* relative_to;
  space = V8XRSpace::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!space) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "XRSpace"));
    return;
  }

  relative_to = V8XRSpace::ToImplWithTypeCheck(info.GetIsolate(), info[1]);
  if (!relative_to) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(1, "XRSpace"));
    return;
  }

  XRPose* result = impl->getPose(space, relative_to, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result);
}

static void GetHitTestResultsMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "XRFrame", "getHitTestResults");

  XRFrame* impl = V8XRFrame::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  XRHitTestSource* hit_test_source;
  hit_test_source = V8XRHitTestSource::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!hit_test_source) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "XRHitTestSource"));
    return;
  }

  HeapVector<Member<XRHitTestResult>> result = impl->getHitTestResults(hit_test_source, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, FreezeV8Object(ToV8(result, info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void GetHitTestResultsForTransientInputMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "XRFrame", "getHitTestResultsForTransientInput");

  XRFrame* impl = V8XRFrame::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  XRTransientInputHitTestSource* hit_test_source;
  hit_test_source = V8XRTransientInputHitTestSource::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!hit_test_source) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "XRTransientInputHitTestSource"));
    return;
  }

  HeapVector<Member<XRTransientInputHitTestResult>> result = impl->getHitTestResultsForTransientInput(hit_test_source, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, FreezeV8Object(ToV8(result, info.Holder(), info.GetIsolate()), info.GetIsolate()));
}

static void GetLightEstimateMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exception_state(info.GetIsolate(), ExceptionState::kExecutionContext, "XRFrame", "getLightEstimate");

  XRFrame* impl = V8XRFrame::ToImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    exception_state.ThrowTypeError(ExceptionMessages::NotEnoughArguments(1, info.Length()));
    return;
  }

  XRLightProbe* light_probe;
  light_probe = V8XRLightProbe::ToImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!light_probe) {
    exception_state.ThrowTypeError(ExceptionMessages::ArgumentNotOfType(0, "XRLightProbe"));
    return;
  }

  XRLightEstimate* result = impl->getLightEstimate(light_probe, exception_state);
  if (exception_state.HadException()) {
    return;
  }
  V8SetReturnValue(info, result);
}

}  // namespace xr_frame_v8_internal

void V8XRFrame::SessionAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_session_Getter");

  xr_frame_v8_internal::SessionAttributeGetter(info);
}

void V8XRFrame::WorldInformationAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_worldInformation_Getter");

  xr_frame_v8_internal::WorldInformationAttributeGetter(info);
}

void V8XRFrame::TrackedAnchorsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_trackedAnchors_Getter");

  xr_frame_v8_internal::TrackedAnchorsAttributeGetter(info);
}

void V8XRFrame::CreateAnchorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("XRFrame.createAnchor");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_createAnchor");

  ExecutionContext* execution_context_for_measurement = CurrentExecutionContext(info.GetIsolate());
  UseCounter::Count(execution_context_for_measurement, WebFeature::kXRFrameCreateAnchor);
  xr_frame_v8_internal::CreateAnchorMethod(info);
}

void V8XRFrame::GetViewerPoseMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("XRFrame.getViewerPose");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_getViewerPose");

  xr_frame_v8_internal::GetViewerPoseMethod(info);
}

void V8XRFrame::GetPoseMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("XRFrame.getPose");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_getPose");

  xr_frame_v8_internal::GetPoseMethod(info);
}

void V8XRFrame::GetHitTestResultsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("XRFrame.getHitTestResults");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_getHitTestResults");

  xr_frame_v8_internal::GetHitTestResultsMethod(info);
}

void V8XRFrame::GetHitTestResultsForTransientInputMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("XRFrame.getHitTestResultsForTransientInput");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_getHitTestResultsForTransientInput");

  xr_frame_v8_internal::GetHitTestResultsForTransientInputMethod(info);
}

void V8XRFrame::GetLightEstimateMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  BLINK_BINDINGS_TRACE_EVENT("XRFrame.getLightEstimate");
  RUNTIME_CALL_TIMER_SCOPE_DISABLED_BY_DEFAULT(info.GetIsolate(), "Blink_XRFrame_getLightEstimate");

  xr_frame_v8_internal::GetLightEstimateMethod(info);
}

static void InstallV8XRFrameTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  // Initialize the interface object's template.
  V8DOMConfiguration::InitializeDOMInterfaceTemplate(isolate, interface_template, V8XRFrame::GetWrapperTypeInfo()->interface_name, v8::Local<v8::FunctionTemplate>(), V8XRFrame::kInternalFieldCount);

  if (!RuntimeEnabledFeatures::WebXREnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  // Custom signature

  V8XRFrame::InstallRuntimeEnabledFeaturesOnTemplate(
      isolate, world, interface_template);
}

void V8XRFrame::InstallRuntimeEnabledFeaturesOnTemplate(
    v8::Isolate* isolate,
    const DOMWrapperWorld& world,
    v8::Local<v8::FunctionTemplate> interface_template) {
  if (!RuntimeEnabledFeatures::WebXREnabled()) {
    return;
  }

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instance_template = interface_template->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instance_template);
  v8::Local<v8::ObjectTemplate> prototype_template = interface_template->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototype_template);

  // Register IDL constants, attributes and operations.

  // Custom signature
}

v8::Local<v8::FunctionTemplate> V8XRFrame::DomTemplate(
    v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::DomClassTemplate(
      isolate, world, const_cast<WrapperTypeInfo*>(V8XRFrame::GetWrapperTypeInfo()),
      InstallV8XRFrameTemplate);
}

bool V8XRFrame::HasInstance(v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->HasInstance(V8XRFrame::GetWrapperTypeInfo(), v8_value);
}

v8::Local<v8::Object> V8XRFrame::FindInstanceInPrototypeChain(
    v8::Local<v8::Value> v8_value, v8::Isolate* isolate) {
  return V8PerIsolateData::From(isolate)->FindInstanceInPrototypeChain(
      V8XRFrame::GetWrapperTypeInfo(), v8_value);
}

XRFrame* V8XRFrame::ToImplWithTypeCheck(
    v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return HasInstance(value, isolate) ? ToImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

void V8XRFrame::InstallConditionalFeatures(
    v8::Local<v8::Context> context,
    const DOMWrapperWorld& world,
    v8::Local<v8::Object> instance_object,
    v8::Local<v8::Object> prototype_object,
    v8::Local<v8::Function> interface_object,
    v8::Local<v8::FunctionTemplate> interface_template) {
  CHECK(!interface_template.IsEmpty());
  DCHECK((!prototype_object.IsEmpty() && !interface_object.IsEmpty()) ||
         !instance_object.IsEmpty());

  v8::Isolate* isolate = context->GetIsolate();

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interface_template);
  ExecutionContext* execution_context = ToExecutionContext(context);
  DCHECK(execution_context);
  bool is_secure_context = (execution_context && execution_context->IsSecureContext());

  if (!prototype_object.IsEmpty() || !interface_object.IsEmpty()) {
    if (is_secure_context) {
      static constexpr V8DOMConfiguration::AccessorConfiguration
      kAccessorConfigurations[] = {
          { "session", V8XRFrame::SessionAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
      };
      V8DOMConfiguration::InstallAccessors(
          isolate, world, instance_object, prototype_object, interface_object,
          signature, kAccessorConfigurations,
          base::size(kAccessorConfigurations));

      if (RuntimeEnabledFeatures::WebXRAnchorsEnabled()) {
        static constexpr V8DOMConfiguration::AccessorConfiguration
        kAccessorConfigurations[] = {
            { "trackedAnchors", V8XRFrame::TrackedAnchorsAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        };
        V8DOMConfiguration::InstallAccessors(
            isolate, world, instance_object, prototype_object, interface_object,
            signature, kAccessorConfigurations,
            base::size(kAccessorConfigurations));
      }
      if (RuntimeEnabledFeatures::WebXRPlaneDetectionEnabled()) {
        static constexpr V8DOMConfiguration::AccessorConfiguration
        kAccessorConfigurations[] = {
            { "worldInformation", V8XRFrame::WorldInformationAttributeGetterCallback, nullptr, static_cast<unsigned>(V8PrivateProperty::CachedAccessor::kNone), static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds },
        };
        V8DOMConfiguration::InstallAccessors(
            isolate, world, instance_object, prototype_object, interface_object,
            signature, kAccessorConfigurations,
            base::size(kAccessorConfigurations));
      }
    }
    if (is_secure_context) {
      if (RuntimeEnabledFeatures::WebXRAnchorsEnabled()) {
        {
          // Install createAnchor configuration
          const V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
              {"createAnchor", V8XRFrame::CreateAnchorMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kDoNotCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
          };
          for (const auto& config : kConfigurations) {
            V8DOMConfiguration::InstallMethod(
                isolate, world, instance_object, prototype_object,
                interface_object, signature, config);
          }
        }
      }
    }
    if (is_secure_context) {
      {
        // Install getViewerPose configuration
        const V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
            {"getViewerPose", V8XRFrame::GetViewerPoseMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
        };
        for (const auto& config : kConfigurations) {
          V8DOMConfiguration::InstallMethod(
              isolate, world, instance_object, prototype_object,
              interface_object, signature, config);
        }
      }
    }
    if (is_secure_context) {
      {
        // Install getPose configuration
        const V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
            {"getPose", V8XRFrame::GetPoseMethodCallback, 2, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
        };
        for (const auto& config : kConfigurations) {
          V8DOMConfiguration::InstallMethod(
              isolate, world, instance_object, prototype_object,
              interface_object, signature, config);
        }
      }
    }
    if (is_secure_context) {
      if (RuntimeEnabledFeatures::WebXRHitTestEnabled()) {
        {
          // Install getHitTestResults configuration
          const V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
              {"getHitTestResults", V8XRFrame::GetHitTestResultsMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
          };
          for (const auto& config : kConfigurations) {
            V8DOMConfiguration::InstallMethod(
                isolate, world, instance_object, prototype_object,
                interface_object, signature, config);
          }
        }
      }
    }
    if (is_secure_context) {
      if (RuntimeEnabledFeatures::WebXRHitTestEnabled()) {
        {
          // Install getHitTestResultsForTransientInput configuration
          const V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
              {"getHitTestResultsForTransientInput", V8XRFrame::GetHitTestResultsForTransientInputMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
          };
          for (const auto& config : kConfigurations) {
            V8DOMConfiguration::InstallMethod(
                isolate, world, instance_object, prototype_object,
                interface_object, signature, config);
          }
        }
      }
    }
    if (is_secure_context) {
      if (RuntimeEnabledFeatures::WebXRLightEstimationEnabled()) {
        {
          // Install getLightEstimate configuration
          const V8DOMConfiguration::MethodConfiguration kConfigurations[] = {
              {"getLightEstimate", V8XRFrame::GetLightEstimateMethodCallback, 1, v8::None, V8DOMConfiguration::kOnPrototype, V8DOMConfiguration::kCheckHolder, V8DOMConfiguration::kDoNotCheckAccess, V8DOMConfiguration::kHasSideEffect, V8DOMConfiguration::kAllWorlds}
          };
          for (const auto& config : kConfigurations) {
            V8DOMConfiguration::InstallMethod(
                isolate, world, instance_object, prototype_object,
                interface_object, signature, config);
          }
        }
      }
    }
  }
}

}  // namespace blink
