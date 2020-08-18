// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/origin_trial_features_for_core.cc.tmpl
// by the script generate_origin_trial_features.py.
// DO NOT MODIFY!

// clang-format off

#include "third_party/blink/renderer/bindings/core/v8/origin_trial_features_for_core.h"

#include "third_party/blink/renderer/bindings/core/v8/v8_dedicated_worker_global_scope.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_document.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_anchor_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_body_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_frame_set_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_iframe_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_image_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_link_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_html_script_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_location.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mathml_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_navigator.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_performance.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_scheduling.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_shared_worker_global_scope.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_svg_element.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_text.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_window.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_xml_http_request.h"
#include "third_party/blink/renderer/core/context_features/context_feature_settings.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/frame.h"
#include "third_party/blink/renderer/core/origin_trials/origin_trials.h"
#include "third_party/blink/renderer/platform/bindings/origin_trial_features.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

namespace {
InstallOriginTrialFeaturesFunction g_old_install_origin_trial_features_function =
    nullptr;
InstallPendingOriginTrialFeatureFunction
    g_old_install_pending_origin_trial_feature_function = nullptr;

void InstallOriginTrialFeaturesForCore(
    const WrapperTypeInfo* wrapper_type_info,
    const ScriptState* script_state,
    v8::Local<v8::Object> prototype_object,
    v8::Local<v8::Function> interface_object) {
  (*g_old_install_origin_trial_features_function)(
      wrapper_type_info, script_state, prototype_object, interface_object);

  ExecutionContext* execution_context = ExecutionContext::From(script_state);
  if (!execution_context)
    return;
  v8::Isolate* isolate = script_state->GetIsolate();
  const DOMWrapperWorld& world = script_state->World();
  // TODO(iclelland): Unify ContextFeatureSettings with the rest of the
  // conditional features.
  if (wrapper_type_info == V8Window::GetWrapperTypeInfo()) {
    auto* settings = ContextFeatureSettings::From(
        execution_context,
        ContextFeatureSettings::CreationMode::kDontCreateIfNotExists);
    if (settings && settings->isMojoJSEnabled()) {
      v8::Local<v8::Object> instance_object =
          script_state->GetContext()->Global();
      V8Window::InstallMojoJS(isolate, world, instance_object, prototype_object,
                              interface_object);
    }
  }
  // TODO(iclelland): Extract this common code out of OriginTrialFeaturesForCore
  // and OriginTrialFeaturesForModules into a block.
  if (wrapper_type_info == V8DedicatedWorkerGlobalScope::GetWrapperTypeInfo()) {
    v8::Local<v8::Object> instance_object =
        script_state->GetContext()->Global();
    if (RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(execution_context)) {
      V8DedicatedWorkerGlobalScope::InstallExperimentalJSProfiler(
          isolate, world, instance_object, prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Document::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::CustomElementsV0Enabled(execution_context)) {
      V8Document::InstallCustomElementsV0(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(execution_context)) {
      V8Document::InstallTouchEventFeatureDetection(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::TrustTokensEnabled(execution_context)) {
      V8Document::InstallTrustTokens(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Element::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::ShadowDOMV0Enabled(execution_context)) {
      V8Element::InstallShadowDOMV0(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLAnchorElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::HrefTranslateEnabled(execution_context)) {
      V8HTMLAnchorElement::InstallHrefTranslate(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLBodyElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::PortalsEnabled(execution_context)) {
      V8HTMLBodyElement::InstallPortals(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(execution_context)) {
      V8HTMLElement::InstallTouchEventFeatureDetection(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLFrameSetElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::PortalsEnabled(execution_context)) {
      V8HTMLFrameSetElement::InstallPortals(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLIFrameElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::DocumentPolicyEnabled(execution_context)) {
      V8HTMLIFrameElement::InstallDocumentPolicy(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::TrustTokensEnabled(execution_context)) {
      V8HTMLIFrameElement::InstallTrustTokens(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLImageElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::PriorityHintsEnabled(execution_context)) {
      V8HTMLImageElement::InstallPriorityHints(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLLinkElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::HTMLImportsEnabled(execution_context)) {
      V8HTMLLinkElement::InstallHTMLImports(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::PriorityHintsEnabled(execution_context)) {
      V8HTMLLinkElement::InstallPriorityHints(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8HTMLScriptElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::PriorityHintsEnabled(execution_context)) {
      V8HTMLScriptElement::InstallPriorityHints(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Location::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(execution_context)) {
      V8Location::InstallTextFragmentIdentifiers(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8MathMLElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(execution_context)) {
      V8MathMLElement::InstallTouchEventFeatureDetection(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Navigator::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabled(execution_context)) {
      V8Navigator::InstallExperimentalIsInputPending(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Performance::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(execution_context)) {
      V8Performance::InstallExperimentalJSProfiler(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::MeasureMemoryEnabled(execution_context)) {
      V8Performance::InstallMeasureMemory(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8SVGElement::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(execution_context)) {
      V8SVGElement::InstallTouchEventFeatureDetection(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Scheduling::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabled(execution_context)) {
      V8Scheduling::InstallExperimentalIsInputPending(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8SharedWorkerGlobalScope::GetWrapperTypeInfo()) {
    v8::Local<v8::Object> instance_object =
        script_state->GetContext()->Global();
    if (RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(execution_context)) {
      V8SharedWorkerGlobalScope::InstallExperimentalJSProfiler(
          isolate, world, instance_object, prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Text::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::ShadowDOMV0Enabled(execution_context)) {
      V8Text::InstallShadowDOMV0(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8Window::GetWrapperTypeInfo()) {
    v8::Local<v8::Object> instance_object =
        script_state->GetContext()->Global();
    if (RuntimeEnabledFeatures::ExperimentalIsInputPendingEnabled(execution_context)) {
      V8Window::InstallExperimentalIsInputPending(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::PortalsEnabled(execution_context)) {
      V8Window::InstallPortals(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(execution_context)) {
      V8Window::InstallTouchEventFeatureDetection(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(execution_context)) {
      V8Window::InstallTextFragmentIdentifiers(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::AppCacheEnabled(execution_context)) {
      V8Window::InstallAppCache(
          isolate, world, instance_object, prototype_object, interface_object);
    }
    if (RuntimeEnabledFeatures::ExperimentalJSProfilerEnabled(execution_context)) {
      V8Window::InstallExperimentalJSProfiler(
          isolate, world, instance_object, prototype_object, interface_object);
    }
  }
  if (wrapper_type_info == V8XMLHttpRequest::GetWrapperTypeInfo()) {
    if (RuntimeEnabledFeatures::TrustTokensEnabled(execution_context)) {
      V8XMLHttpRequest::InstallTrustTokens(
          isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
    }
  }
}

void InstallPendingOriginTrialFeatureForCore(OriginTrialFeature feature,
                                             const ScriptState* script_state) {
  (*g_old_install_pending_origin_trial_feature_function)(feature, script_state);

  // TODO(iclelland): Extract this common code out of OriginTrialFeaturesForCore
  // and OriginTrialFeaturesForModules into a block.
  v8::Local<v8::Object> prototype_object;
  v8::Local<v8::Function> interface_object;
  v8::Isolate* isolate = script_state->GetIsolate();
  const DOMWrapperWorld& world = script_state->World();
  V8PerContextData* context_data = script_state->PerContextData();
  switch (feature) {
    case OriginTrialFeature::kAppCache: {
      V8Window::InstallAppCache(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kCustomElementsV0: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Document::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Document::InstallCustomElementsV0(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kDocumentPolicy: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLIFrameElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLIFrameElement::InstallDocumentPolicy(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kExperimentalIsInputPending: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Scheduling::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Scheduling::InstallExperimentalIsInputPending(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      V8Window::InstallExperimentalIsInputPending(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Navigator::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Navigator::InstallExperimentalIsInputPending(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kExperimentalJSProfiler: {
      V8DedicatedWorkerGlobalScope::InstallExperimentalJSProfiler(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8Window::InstallExperimentalJSProfiler(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      V8SharedWorkerGlobalScope::InstallExperimentalJSProfiler(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Performance::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Performance::InstallExperimentalJSProfiler(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kHTMLImports: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLLinkElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLLinkElement::InstallHTMLImports(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kHrefTranslate: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLAnchorElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLAnchorElement::InstallHrefTranslate(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kMeasureMemory: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Performance::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Performance::InstallMeasureMemory(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kPortals: {
      V8Window::InstallPortals(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLFrameSetElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLFrameSetElement::InstallPortals(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLBodyElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLBodyElement::InstallPortals(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kPriorityHints: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLImageElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLImageElement::InstallPriorityHints(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLScriptElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLScriptElement::InstallPriorityHints(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLLinkElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLLinkElement::InstallPriorityHints(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kShadowDOMV0: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Element::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Element::InstallShadowDOMV0(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Text::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Text::InstallShadowDOMV0(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kTextFragmentIdentifiers: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Location::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Location::InstallTextFragmentIdentifiers(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      V8Window::InstallTextFragmentIdentifiers(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      break;
    }
    case OriginTrialFeature::kTouchEventFeatureDetection: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8MathMLElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8MathMLElement::InstallTouchEventFeatureDetection(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8SVGElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8SVGElement::InstallTouchEventFeatureDetection(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      V8Window::InstallTouchEventFeatureDetection(
          isolate, world, script_state->GetContext()->Global(),
          v8::Local<v8::Object>(), v8::Local<v8::Function>());
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Document::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Document::InstallTouchEventFeatureDetection(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLElement::InstallTouchEventFeatureDetection(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    case OriginTrialFeature::kTrustTokens: {
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8HTMLIFrameElement::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8HTMLIFrameElement::InstallTrustTokens(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8Document::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8Document::InstallTrustTokens(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      if (context_data->GetExistingConstructorAndPrototypeForType(
              V8XMLHttpRequest::GetWrapperTypeInfo(), &prototype_object, &interface_object)) {
        V8XMLHttpRequest::InstallTrustTokens(
            isolate, world, v8::Local<v8::Object>(), prototype_object, interface_object);
      }
      break;
    }
    default:
      break;
  }
}

}  // namespace

void RegisterInstallOriginTrialFeaturesForCore() {
  g_old_install_origin_trial_features_function =
      SetInstallOriginTrialFeaturesFunction(&InstallOriginTrialFeaturesForCore);
  g_old_install_pending_origin_trial_feature_function =
      SetInstallPendingOriginTrialFeatureFunction(
          &InstallPendingOriginTrialFeatureForCore);
}

}  // namespace blink
