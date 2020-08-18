// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/properties/templates/css_properties.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/properties/css_property_methods.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5



#include "third_party/blink/renderer/core/css/properties/longhands.h"

#include "third_party/blink/renderer/core/css/css_custom_ident_value.h"
#include "third_party/blink/renderer/core/css/css_identifier_value.h"
#include "third_party/blink/renderer/core/css/css_primitive_value.h"
#include "third_party/blink/renderer/core/css/css_primitive_value_mappings.h"
#include "third_party/blink/renderer/core/css/css_value_list.h"
#include "third_party/blink/renderer/core/css/css_value_pair.h"
#include "third_party/blink/renderer/core/css/properties/css_direction_aware_resolver.h"
#include "third_party/blink/renderer/core/css/properties/style_building_utils.h"
#include "third_party/blink/renderer/core/css/resolver/font_builder.h"
#include "third_party/blink/renderer/core/css/resolver/style_builder_converter.h"
#include "third_party/blink/renderer/core/css/resolver/style_resolver_state.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/style/computed_style.h"
#include "third_party/blink/renderer/core/style/style_svg_resource.h"
#include "third_party/blink/renderer/core/style/svg_computed_style.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {
namespace css_longhand {

// animation-delay



const char* AnimationDelay::GetPropertyName() const {
  return "animation-delay";
}

const WTF::AtomicString& AnimationDelay::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-delay"));
  return name;
}

const char* AnimationDelay::GetJSPropertyName() const {
  return "animationDelay";
}


void AnimationDelay::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.DelayList().clear();
  data.DelayList().push_back(CSSAnimationData::InitialDelay());
}

void AnimationDelay::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().DelayList() = parent_data->DelayList();
}

void AnimationDelay::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.DelayList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.DelayList().push_back(CSSToStyleMap::MapAnimationDelay(*listValue));
}

 // animation-direction



const char* AnimationDirection::GetPropertyName() const {
  return "animation-direction";
}

const WTF::AtomicString& AnimationDirection::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-direction"));
  return name;
}

const char* AnimationDirection::GetJSPropertyName() const {
  return "animationDirection";
}


void AnimationDirection::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.DirectionList().clear();
  data.DirectionList().push_back(CSSAnimationData::InitialDirection());
}

void AnimationDirection::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().DirectionList() = parent_data->DirectionList();
}

void AnimationDirection::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.DirectionList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.DirectionList().push_back(CSSToStyleMap::MapAnimationDirection(*listValue));
}

 // animation-duration



const char* AnimationDuration::GetPropertyName() const {
  return "animation-duration";
}

const WTF::AtomicString& AnimationDuration::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-duration"));
  return name;
}

const char* AnimationDuration::GetJSPropertyName() const {
  return "animationDuration";
}


void AnimationDuration::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.DurationList().clear();
  data.DurationList().push_back(CSSAnimationData::InitialDuration());
}

void AnimationDuration::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().DurationList() = parent_data->DurationList();
}

void AnimationDuration::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.DurationList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.DurationList().push_back(CSSToStyleMap::MapAnimationDuration(*listValue));
}

 // animation-fill-mode



const char* AnimationFillMode::GetPropertyName() const {
  return "animation-fill-mode";
}

const WTF::AtomicString& AnimationFillMode::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-fill-mode"));
  return name;
}

const char* AnimationFillMode::GetJSPropertyName() const {
  return "animationFillMode";
}


void AnimationFillMode::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.FillModeList().clear();
  data.FillModeList().push_back(CSSAnimationData::InitialFillMode());
}

void AnimationFillMode::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().FillModeList() = parent_data->FillModeList();
}

void AnimationFillMode::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.FillModeList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.FillModeList().push_back(CSSToStyleMap::MapAnimationFillMode(*listValue));
}

 // animation-iteration-count



const char* AnimationIterationCount::GetPropertyName() const {
  return "animation-iteration-count";
}

const WTF::AtomicString& AnimationIterationCount::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-iteration-count"));
  return name;
}

const char* AnimationIterationCount::GetJSPropertyName() const {
  return "animationIterationCount";
}


void AnimationIterationCount::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.IterationCountList().clear();
  data.IterationCountList().push_back(CSSAnimationData::InitialIterationCount());
}

void AnimationIterationCount::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().IterationCountList() = parent_data->IterationCountList();
}

void AnimationIterationCount::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.IterationCountList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.IterationCountList().push_back(CSSToStyleMap::MapAnimationIterationCount(*listValue));
}

 // animation-name



const char* AnimationName::GetPropertyName() const {
  return "animation-name";
}

const WTF::AtomicString& AnimationName::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-name"));
  return name;
}

const char* AnimationName::GetJSPropertyName() const {
  return "animationName";
}


void AnimationName::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.NameList().clear();
  data.NameList().push_back(CSSAnimationData::InitialName());
}

void AnimationName::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().NameList() = parent_data->NameList();
}

void AnimationName::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.NameList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.NameList().push_back(CSSToStyleMap::MapAnimationName(*listValue));
}

 // animation-play-state



const char* AnimationPlayState::GetPropertyName() const {
  return "animation-play-state";
}

const WTF::AtomicString& AnimationPlayState::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-play-state"));
  return name;
}

const char* AnimationPlayState::GetJSPropertyName() const {
  return "animationPlayState";
}


void AnimationPlayState::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.PlayStateList().clear();
  data.PlayStateList().push_back(CSSAnimationData::InitialPlayState());
}

void AnimationPlayState::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().PlayStateList() = parent_data->PlayStateList();
}

void AnimationPlayState::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.PlayStateList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.PlayStateList().push_back(CSSToStyleMap::MapAnimationPlayState(*listValue));
}

 // animation-timeline

CSSExposure AnimationTimeline::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSScrollTimelineEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* AnimationTimeline::GetPropertyName() const {
  return "animation-timeline";
}

const WTF::AtomicString& AnimationTimeline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-timeline"));
  return name;
}

const char* AnimationTimeline::GetJSPropertyName() const {
  return "animationTimeline";
}


void AnimationTimeline::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.TimelineList().clear();
  data.TimelineList().push_back(CSSAnimationData::InitialTimeline());
}

void AnimationTimeline::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().TimelineList() = parent_data->TimelineList();
}

void AnimationTimeline::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.TimelineList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.TimelineList().push_back(CSSToStyleMap::MapAnimationTimeline(*listValue));
}

 // animation-timing-function



const char* AnimationTimingFunction::GetPropertyName() const {
  return "animation-timing-function";
}

const WTF::AtomicString& AnimationTimingFunction::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-timing-function"));
  return name;
}

const char* AnimationTimingFunction::GetJSPropertyName() const {
  return "animationTimingFunction";
}


void AnimationTimingFunction::ApplyInitial(StyleResolverState& state) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.TimingFunctionList().clear();
  data.TimingFunctionList().push_back(CSSAnimationData::InitialTimingFunction());
}

void AnimationTimingFunction::ApplyInherit(StyleResolverState& state) const {
  const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessAnimations().TimingFunctionList() = parent_data->TimingFunctionList();
}

void AnimationTimingFunction::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSAnimationData& data = state.Style()->AccessAnimations();
  data.TimingFunctionList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.TimingFunctionList().push_back(CSSToStyleMap::MapAnimationTimingFunction(*listValue));
}

 // transition-delay



const char* TransitionDelay::GetPropertyName() const {
  return "transition-delay";
}

const WTF::AtomicString& TransitionDelay::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-delay"));
  return name;
}

const char* TransitionDelay::GetJSPropertyName() const {
  return "transitionDelay";
}


void TransitionDelay::ApplyInitial(StyleResolverState& state) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.DelayList().clear();
  data.DelayList().push_back(CSSTransitionData::InitialDelay());
}

void TransitionDelay::ApplyInherit(StyleResolverState& state) const {
  const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessTransitions().DelayList() = parent_data->DelayList();
}

void TransitionDelay::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.DelayList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.DelayList().push_back(CSSToStyleMap::MapAnimationDelay(*listValue));
}

 // transition-duration



const char* TransitionDuration::GetPropertyName() const {
  return "transition-duration";
}

const WTF::AtomicString& TransitionDuration::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-duration"));
  return name;
}

const char* TransitionDuration::GetJSPropertyName() const {
  return "transitionDuration";
}


void TransitionDuration::ApplyInitial(StyleResolverState& state) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.DurationList().clear();
  data.DurationList().push_back(CSSTransitionData::InitialDuration());
}

void TransitionDuration::ApplyInherit(StyleResolverState& state) const {
  const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessTransitions().DurationList() = parent_data->DurationList();
}

void TransitionDuration::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.DurationList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.DurationList().push_back(CSSToStyleMap::MapAnimationDuration(*listValue));
}

 // transition-property



const char* TransitionProperty::GetPropertyName() const {
  return "transition-property";
}

const WTF::AtomicString& TransitionProperty::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-property"));
  return name;
}

const char* TransitionProperty::GetJSPropertyName() const {
  return "transitionProperty";
}


void TransitionProperty::ApplyInitial(StyleResolverState& state) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.PropertyList().clear();
  data.PropertyList().push_back(CSSTransitionData::InitialProperty());
}

void TransitionProperty::ApplyInherit(StyleResolverState& state) const {
  const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessTransitions().PropertyList() = parent_data->PropertyList();
}

void TransitionProperty::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.PropertyList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.PropertyList().push_back(CSSToStyleMap::MapAnimationProperty(*listValue));
}

 // transition-timing-function



const char* TransitionTimingFunction::GetPropertyName() const {
  return "transition-timing-function";
}

const WTF::AtomicString& TransitionTimingFunction::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-timing-function"));
  return name;
}

const char* TransitionTimingFunction::GetJSPropertyName() const {
  return "transitionTimingFunction";
}


void TransitionTimingFunction::ApplyInitial(StyleResolverState& state) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.TimingFunctionList().clear();
  data.TimingFunctionList().push_back(CSSTransitionData::InitialTimingFunction());
}

void TransitionTimingFunction::ApplyInherit(StyleResolverState& state) const {
  const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
  if (!parent_data)
    ApplyInitial(state);
  else
    state.Style()->AccessTransitions().TimingFunctionList() = parent_data->TimingFunctionList();
}

void TransitionTimingFunction::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  CSSTransitionData& data = state.Style()->AccessTransitions();
  data.TimingFunctionList().clear();
  for (auto& listValue : To<CSSValueList>(value))
    data.TimingFunctionList().push_back(CSSToStyleMap::MapAnimationTimingFunction(*listValue));
}

 // color



const char* Color::GetPropertyName() const {
  return "color";
}

const WTF::AtomicString& Color::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("color"));
  return name;
}

const char* Color::GetJSPropertyName() const {
  return "color";
}
const CSSProperty* Color::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedColor();
}



 // color-scheme

CSSExposure ColorScheme::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSColorSchemeEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* ColorScheme::GetPropertyName() const {
  return "color-scheme";
}

const WTF::AtomicString& ColorScheme::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-scheme"));
  return name;
}

const char* ColorScheme::GetJSPropertyName() const {
  return "colorScheme";
}



 // direction



const char* Direction::GetPropertyName() const {
  return "direction";
}

const WTF::AtomicString& Direction::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("direction"));
  return name;
}

const char* Direction::GetJSPropertyName() const {
  return "direction";
}

bool Direction::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.Direction() == b.Direction();
}

void Direction::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetDirection(ComputedStyleInitialValues::InitialDirection());
}
void Direction::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetDirection(state.ParentStyle()->Direction());
}

 // font-family



const char* FontFamily::GetPropertyName() const {
  return "font-family";
}

const WTF::AtomicString& FontFamily::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-family"));
  return name;
}

const char* FontFamily::GetJSPropertyName() const {
  return "fontFamily";
}


void FontFamily::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetFamilyDescription(FontBuilder::InitialFamilyDescription());
}
void FontFamily::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetFamilyDescription(state.ParentFontDescription().GetFamilyDescription());
}
void FontFamily::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetFamilyDescription(StyleBuilderConverter::ConvertFontFamily(state, value));
}

 // font-feature-settings



const char* FontFeatureSettings::GetPropertyName() const {
  return "font-feature-settings";
}

const WTF::AtomicString& FontFeatureSettings::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-feature-settings"));
  return name;
}

const char* FontFeatureSettings::GetJSPropertyName() const {
  return "fontFeatureSettings";
}


void FontFeatureSettings::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetFeatureSettings(FontBuilder::InitialFeatureSettings());
}
void FontFeatureSettings::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetFeatureSettings(state.ParentFontDescription().FeatureSettings());
}
void FontFeatureSettings::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetFeatureSettings(StyleBuilderConverter::ConvertFontFeatureSettings(state, value));
}

 // font-kerning



const char* FontKerning::GetPropertyName() const {
  return "font-kerning";
}

const WTF::AtomicString& FontKerning::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-kerning"));
  return name;
}

const char* FontKerning::GetJSPropertyName() const {
  return "fontKerning";
}


void FontKerning::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetKerning(FontBuilder::InitialKerning());
}
void FontKerning::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetKerning(state.ParentFontDescription().GetKerning());
}
void FontKerning::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetKerning(To<CSSIdentifierValue>(value).ConvertTo<blink::FontDescription::Kerning>());
}

 // font-optical-sizing



const char* FontOpticalSizing::GetPropertyName() const {
  return "font-optical-sizing";
}

const WTF::AtomicString& FontOpticalSizing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-optical-sizing"));
  return name;
}

const char* FontOpticalSizing::GetJSPropertyName() const {
  return "fontOpticalSizing";
}


void FontOpticalSizing::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetFontOpticalSizing(FontBuilder::InitialFontOpticalSizing());
}
void FontOpticalSizing::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetFontOpticalSizing(state.ParentFontDescription().FontOpticalSizing());
}
void FontOpticalSizing::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetFontOpticalSizing(To<CSSIdentifierValue>(value).ConvertTo<blink::OpticalSizing>());
}

 // font-size



const char* FontSize::GetPropertyName() const {
  return "font-size";
}

const WTF::AtomicString& FontSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-size"));
  return name;
}

const char* FontSize::GetJSPropertyName() const {
  return "fontSize";
}


void FontSize::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetSize(FontBuilder::InitialSize());
}
void FontSize::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetSize(state.ParentFontDescription().GetSize());
}
void FontSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetSize(StyleBuilderConverter::ConvertFontSize(state, value));
}

 // font-size-adjust

CSSExposure FontSizeAdjust::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* FontSizeAdjust::GetPropertyName() const {
  return "font-size-adjust";
}

const WTF::AtomicString& FontSizeAdjust::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-size-adjust"));
  return name;
}

const char* FontSizeAdjust::GetJSPropertyName() const {
  return "fontSizeAdjust";
}


void FontSizeAdjust::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetSizeAdjust(FontBuilder::InitialSizeAdjust());
}
void FontSizeAdjust::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetSizeAdjust(state.ParentFontDescription().SizeAdjust());
}
void FontSizeAdjust::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetSizeAdjust(StyleBuilderConverter::ConvertFontSizeAdjust(state, value));
}

 // font-stretch



const char* FontStretch::GetPropertyName() const {
  return "font-stretch";
}

const WTF::AtomicString& FontStretch::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-stretch"));
  return name;
}

const char* FontStretch::GetJSPropertyName() const {
  return "fontStretch";
}


void FontStretch::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetStretch(FontBuilder::InitialStretch());
}
void FontStretch::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetStretch(state.ParentFontDescription().Stretch());
}
void FontStretch::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetStretch(StyleBuilderConverter::ConvertFontStretch(state, value));
}

 // font-style



const char* FontStyle::GetPropertyName() const {
  return "font-style";
}

const WTF::AtomicString& FontStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-style"));
  return name;
}

const char* FontStyle::GetJSPropertyName() const {
  return "fontStyle";
}


void FontStyle::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetStyle(FontBuilder::InitialStyle());
}
void FontStyle::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetStyle(state.ParentFontDescription().Style());
}
void FontStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetStyle(StyleBuilderConverter::ConvertFontStyle(state, value));
}

 // font-variant-caps



const char* FontVariantCaps::GetPropertyName() const {
  return "font-variant-caps";
}

const WTF::AtomicString& FontVariantCaps::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-caps"));
  return name;
}

const char* FontVariantCaps::GetJSPropertyName() const {
  return "fontVariantCaps";
}


void FontVariantCaps::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantCaps(FontBuilder::InitialVariantCaps());
}
void FontVariantCaps::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantCaps(state.ParentFontDescription().VariantCaps());
}
void FontVariantCaps::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetVariantCaps(StyleBuilderConverter::ConvertFontVariantCaps(state, value));
}

 // font-variant-east-asian



const char* FontVariantEastAsian::GetPropertyName() const {
  return "font-variant-east-asian";
}

const WTF::AtomicString& FontVariantEastAsian::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-east-asian"));
  return name;
}

const char* FontVariantEastAsian::GetJSPropertyName() const {
  return "fontVariantEastAsian";
}


void FontVariantEastAsian::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantEastAsian(FontBuilder::InitialVariantEastAsian());
}
void FontVariantEastAsian::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantEastAsian(state.ParentFontDescription().VariantEastAsian());
}
void FontVariantEastAsian::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetVariantEastAsian(StyleBuilderConverter::ConvertFontVariantEastAsian(state, value));
}

 // font-variant-ligatures



const char* FontVariantLigatures::GetPropertyName() const {
  return "font-variant-ligatures";
}

const WTF::AtomicString& FontVariantLigatures::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-ligatures"));
  return name;
}

const char* FontVariantLigatures::GetJSPropertyName() const {
  return "fontVariantLigatures";
}


void FontVariantLigatures::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantLigatures(FontBuilder::InitialVariantLigatures());
}
void FontVariantLigatures::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantLigatures(state.ParentFontDescription().GetVariantLigatures());
}
void FontVariantLigatures::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetVariantLigatures(StyleBuilderConverter::ConvertFontVariantLigatures(state, value));
}

 // font-variant-numeric



const char* FontVariantNumeric::GetPropertyName() const {
  return "font-variant-numeric";
}

const WTF::AtomicString& FontVariantNumeric::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-numeric"));
  return name;
}

const char* FontVariantNumeric::GetJSPropertyName() const {
  return "fontVariantNumeric";
}


void FontVariantNumeric::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantNumeric(FontBuilder::InitialVariantNumeric());
}
void FontVariantNumeric::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariantNumeric(state.ParentFontDescription().VariantNumeric());
}
void FontVariantNumeric::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetVariantNumeric(StyleBuilderConverter::ConvertFontVariantNumeric(state, value));
}

 // font-variation-settings



const char* FontVariationSettings::GetPropertyName() const {
  return "font-variation-settings";
}

const WTF::AtomicString& FontVariationSettings::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variation-settings"));
  return name;
}

const char* FontVariationSettings::GetJSPropertyName() const {
  return "fontVariationSettings";
}


void FontVariationSettings::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariationSettings(FontBuilder::InitialVariationSettings());
}
void FontVariationSettings::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetVariationSettings(state.ParentFontDescription().VariationSettings());
}
void FontVariationSettings::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetVariationSettings(StyleBuilderConverter::ConvertFontVariationSettings(state, value));
}

 // font-weight



const char* FontWeight::GetPropertyName() const {
  return "font-weight";
}

const WTF::AtomicString& FontWeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-weight"));
  return name;
}

const char* FontWeight::GetJSPropertyName() const {
  return "fontWeight";
}


void FontWeight::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetWeight(FontBuilder::InitialWeight());
}
void FontWeight::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetWeight(state.ParentFontDescription().Weight());
}
void FontWeight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetWeight(StyleBuilderConverter::ConvertFontWeight(state, value));
}

 // forced-color-adjust

CSSExposure ForcedColorAdjust::Exposure() const {
  if (!RuntimeEnabledFeatures::ForcedColorsEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* ForcedColorAdjust::GetPropertyName() const {
  return "forced-color-adjust";
}

const WTF::AtomicString& ForcedColorAdjust::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("forced-color-adjust"));
  return name;
}

const char* ForcedColorAdjust::GetJSPropertyName() const {
  return "forcedColorAdjust";
}


void ForcedColorAdjust::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetForcedColorAdjust(ComputedStyleInitialValues::InitialForcedColorAdjust());
}
void ForcedColorAdjust::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetForcedColorAdjust(state.ParentStyle()->ForcedColorAdjust());
}
void ForcedColorAdjust::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetForcedColorAdjust(To<CSSIdentifierValue>(value).ConvertTo<blink::EForcedColorAdjust>());
}

 // -internal-visited-color

CSSExposure InternalVisitedColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedColor::GetPropertyName() const {
  return "-internal-visited-color";
}

const WTF::AtomicString& InternalVisitedColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-color"));
  return name;
}

const char* InternalVisitedColor::GetJSPropertyName() const {
  return "internalVisitedColor";
}
const CSSProperty* InternalVisitedColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyColor();
}



 // text-orientation



const char* TextOrientation::GetPropertyName() const {
  return "text-orientation";
}

const WTF::AtomicString& TextOrientation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-orientation"));
  return name;
}

const char* TextOrientation::GetJSPropertyName() const {
  return "textOrientation";
}



 // text-rendering



const char* TextRendering::GetPropertyName() const {
  return "text-rendering";
}

const WTF::AtomicString& TextRendering::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-rendering"));
  return name;
}

const char* TextRendering::GetJSPropertyName() const {
  return "textRendering";
}


void TextRendering::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetTextRendering(FontBuilder::InitialTextRendering());
}
void TextRendering::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetTextRendering(state.ParentFontDescription().TextRendering());
}
void TextRendering::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetTextRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::TextRenderingMode>());
}

 // -webkit-font-smoothing



const char* WebkitFontSmoothing::GetPropertyName() const {
  return "-webkit-font-smoothing";
}

const WTF::AtomicString& WebkitFontSmoothing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-font-smoothing"));
  return name;
}

const char* WebkitFontSmoothing::GetJSPropertyName() const {
  return "webkitFontSmoothing";
}


void WebkitFontSmoothing::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetFontSmoothing(FontBuilder::InitialFontSmoothing());
}
void WebkitFontSmoothing::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetFontSmoothing(state.ParentFontDescription().FontSmoothing());
}
void WebkitFontSmoothing::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.GetFontBuilder().SetFontSmoothing(To<CSSIdentifierValue>(value).ConvertTo<blink::FontSmoothingMode>());
}

 // -webkit-locale



const char* WebkitLocale::GetPropertyName() const {
  return "-webkit-locale";
}

const WTF::AtomicString& WebkitLocale::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-locale"));
  return name;
}

const char* WebkitLocale::GetJSPropertyName() const {
  return "webkitLocale";
}


void WebkitLocale::ApplyInitial(StyleResolverState& state) const {
  state.GetFontBuilder().SetLocale(FontBuilder::InitialLocale());
}
void WebkitLocale::ApplyInherit(StyleResolverState& state) const {
  state.GetFontBuilder().SetLocale(state.ParentFontDescription().Locale());
}

 // -webkit-text-orientation



const char* WebkitTextOrientation::GetPropertyName() const {
  return "-webkit-text-orientation";
}

const WTF::AtomicString& WebkitTextOrientation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-orientation"));
  return name;
}

const char* WebkitTextOrientation::GetJSPropertyName() const {
  return "webkitTextOrientation";
}

const CSSProperty* WebkitTextOrientation::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &GetCSSPropertyTextOrientation();
}


 // -webkit-writing-mode



const char* WebkitWritingMode::GetPropertyName() const {
  return "-webkit-writing-mode";
}

const WTF::AtomicString& WebkitWritingMode::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-writing-mode"));
  return name;
}

const char* WebkitWritingMode::GetJSPropertyName() const {
  return "webkitWritingMode";
}

const CSSProperty* WebkitWritingMode::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &GetCSSPropertyWritingMode();
}
bool WebkitWritingMode::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.GetWritingMode() == b.GetWritingMode();
}


 // writing-mode



const char* WritingMode::GetPropertyName() const {
  return "writing-mode";
}

const WTF::AtomicString& WritingMode::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("writing-mode"));
  return name;
}

const char* WritingMode::GetJSPropertyName() const {
  return "writingMode";
}

bool WritingMode::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.GetWritingMode() == b.GetWritingMode();
}


 // zoom



const char* Zoom::GetPropertyName() const {
  return "zoom";
}

const WTF::AtomicString& Zoom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("zoom"));
  return name;
}

const char* Zoom::GetJSPropertyName() const {
  return "zoom";
}



 // align-content



const char* AlignContent::GetPropertyName() const {
  return "align-content";
}

const WTF::AtomicString& AlignContent::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("align-content"));
  return name;
}

const char* AlignContent::GetJSPropertyName() const {
  return "alignContent";
}

bool AlignContent::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.AlignContent() == b.AlignContent();
}

void AlignContent::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetAlignContent(ComputedStyleInitialValues::InitialAlignContent());
}
void AlignContent::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetAlignContent(state.ParentStyle()->AlignContent());
}
void AlignContent::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetAlignContent(StyleBuilderConverter::ConvertContentAlignmentData(state, value));
}

 // align-items



const char* AlignItems::GetPropertyName() const {
  return "align-items";
}

const WTF::AtomicString& AlignItems::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("align-items"));
  return name;
}

const char* AlignItems::GetJSPropertyName() const {
  return "alignItems";
}

bool AlignItems::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.AlignItems() == b.AlignItems();
}

void AlignItems::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetAlignItems(ComputedStyleInitialValues::InitialAlignItems());
}
void AlignItems::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetAlignItems(state.ParentStyle()->AlignItems());
}
void AlignItems::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetAlignItems(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

 // align-self



const char* AlignSelf::GetPropertyName() const {
  return "align-self";
}

const WTF::AtomicString& AlignSelf::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("align-self"));
  return name;
}

const char* AlignSelf::GetJSPropertyName() const {
  return "alignSelf";
}

bool AlignSelf::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.AlignSelf() == b.AlignSelf();
}

void AlignSelf::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetAlignSelf(ComputedStyleInitialValues::InitialAlignSelf());
}
void AlignSelf::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetAlignSelf(state.ParentStyle()->AlignSelf());
}
void AlignSelf::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetAlignSelf(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

 // alignment-baseline



const char* AlignmentBaseline::GetPropertyName() const {
  return "alignment-baseline";
}

const WTF::AtomicString& AlignmentBaseline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("alignment-baseline"));
  return name;
}

const char* AlignmentBaseline::GetJSPropertyName() const {
  return "alignmentBaseline";
}


void AlignmentBaseline::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetAlignmentBaseline(SVGComputedStyle::InitialAlignmentBaseline());
}
void AlignmentBaseline::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetAlignmentBaseline(state.ParentStyle()->SvgStyle().AlignmentBaseline());
}
void AlignmentBaseline::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetAlignmentBaseline(To<CSSIdentifierValue>(value).ConvertTo<blink::EAlignmentBaseline>());
}

 // all



const char* All::GetPropertyName() const {
  return "all";
}

const WTF::AtomicString& All::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("all"));
  return name;
}

const char* All::GetJSPropertyName() const {
  return "all";
}


void All::ApplyInitial(StyleResolverState& state) const {
  // Intentionally empty.
}
void All::ApplyInherit(StyleResolverState& state) const {
  // Intentionally empty.
}
void All::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  // Intentionally empty.
}

 // appearance



const char* Appearance::GetPropertyName() const {
  return "appearance";
}

const WTF::AtomicString& Appearance::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("appearance"));
  return name;
}

const char* Appearance::GetJSPropertyName() const {
  return "appearance";
}


void Appearance::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetAppearance(ComputedStyleInitialValues::InitialAppearance());
}
void Appearance::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetAppearance(state.ParentStyle()->Appearance());
}
void Appearance::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetAppearance(To<CSSIdentifierValue>(value).ConvertTo<blink::ControlPart>());
}

 // aspect-ratio

CSSExposure AspectRatio::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSAspectRatioPropertyEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* AspectRatio::GetPropertyName() const {
  return "aspect-ratio";
}

const WTF::AtomicString& AspectRatio::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("aspect-ratio"));
  return name;
}

const char* AspectRatio::GetJSPropertyName() const {
  return "aspectRatio";
}


void AspectRatio::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetAspectRatio(ComputedStyleInitialValues::InitialAspectRatio());
}
void AspectRatio::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetAspectRatio(state.ParentStyle()->AspectRatio());
}
void AspectRatio::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetAspectRatio(StyleBuilderConverter::ConvertAspectRatio(state, value));
}

 // backdrop-filter



const char* BackdropFilter::GetPropertyName() const {
  return "backdrop-filter";
}

const WTF::AtomicString& BackdropFilter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("backdrop-filter"));
  return name;
}

const char* BackdropFilter::GetJSPropertyName() const {
  return "backdropFilter";
}


void BackdropFilter::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBackdropFilter(ComputedStyleInitialValues::InitialBackdropFilter());
}
void BackdropFilter::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBackdropFilter(state.ParentStyle()->BackdropFilter());
}
void BackdropFilter::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBackdropFilter(StyleBuilderConverter::ConvertFilterOperations(state, value));
}

 // backface-visibility



const char* BackfaceVisibility::GetPropertyName() const {
  return "backface-visibility";
}

const WTF::AtomicString& BackfaceVisibility::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("backface-visibility"));
  return name;
}

const char* BackfaceVisibility::GetJSPropertyName() const {
  return "backfaceVisibility";
}


void BackfaceVisibility::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBackfaceVisibility(ComputedStyleInitialValues::InitialBackfaceVisibility());
}
void BackfaceVisibility::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBackfaceVisibility(state.ParentStyle()->BackfaceVisibility());
}
void BackfaceVisibility::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBackfaceVisibility(To<CSSIdentifierValue>(value).ConvertTo<blink::EBackfaceVisibility>());
}

 // background-attachment



const char* BackgroundAttachment::GetPropertyName() const {
  return "background-attachment";
}

const WTF::AtomicString& BackgroundAttachment::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-attachment"));
  return name;
}

const char* BackgroundAttachment::GetJSPropertyName() const {
  return "backgroundAttachment";
}


void BackgroundAttachment::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetAttachment(FillLayer::InitialFillAttachment(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearAttachment();
}

void BackgroundAttachment::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsAttachmentSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetAttachment(curr_parent->Attachment());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearAttachment();
    curr_child = curr_child->Next();
  }
}

void BackgroundAttachment::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillAttachment(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillAttachment(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearAttachment();
    curr_child = curr_child->Next();
  }
}

 // background-blend-mode



const char* BackgroundBlendMode::GetPropertyName() const {
  return "background-blend-mode";
}

const WTF::AtomicString& BackgroundBlendMode::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-blend-mode"));
  return name;
}

const char* BackgroundBlendMode::GetJSPropertyName() const {
  return "backgroundBlendMode";
}


void BackgroundBlendMode::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetBlendMode(FillLayer::InitialFillBlendMode(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearBlendMode();
}

void BackgroundBlendMode::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsBlendModeSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetBlendMode(curr_parent->GetBlendMode());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearBlendMode();
    curr_child = curr_child->Next();
  }
}

void BackgroundBlendMode::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillBlendMode(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillBlendMode(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearBlendMode();
    curr_child = curr_child->Next();
  }
}

 // background-clip



const char* BackgroundClip::GetPropertyName() const {
  return "background-clip";
}

const WTF::AtomicString& BackgroundClip::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-clip"));
  return name;
}

const char* BackgroundClip::GetJSPropertyName() const {
  return "backgroundClip";
}


void BackgroundClip::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetClip(FillLayer::InitialFillClip(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearClip();
}

void BackgroundClip::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsClipSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetClip(curr_parent->Clip());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearClip();
    curr_child = curr_child->Next();
  }
}

void BackgroundClip::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillClip(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillClip(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearClip();
    curr_child = curr_child->Next();
  }
}

 // background-color



const char* BackgroundColor::GetPropertyName() const {
  return "background-color";
}

const WTF::AtomicString& BackgroundColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-color"));
  return name;
}

const char* BackgroundColor::GetJSPropertyName() const {
  return "backgroundColor";
}
const CSSProperty* BackgroundColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBackgroundColor();
}


void BackgroundColor::ApplyInitial(StyleResolverState& state) const {
  auto color = ComputedStyleInitialValues::InitialBackgroundColor();
  state.Style()->SetBackgroundColor(color);
}

void BackgroundColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BackgroundColor();
  state.Style()->SetBackgroundColor(color);
}

void BackgroundColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBackgroundColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // background-image



const char* BackgroundImage::GetPropertyName() const {
  return "background-image";
}

const WTF::AtomicString& BackgroundImage::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-image"));
  return name;
}

const char* BackgroundImage::GetJSPropertyName() const {
  return "backgroundImage";
}


void BackgroundImage::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetImage(FillLayer::InitialFillImage(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearImage();
}

void BackgroundImage::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsImageSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetImage(curr_parent->GetImage());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearImage();
    curr_child = curr_child->Next();
  }
}

void BackgroundImage::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillImage(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillImage(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearImage();
    curr_child = curr_child->Next();
  }
}

 // background-origin



const char* BackgroundOrigin::GetPropertyName() const {
  return "background-origin";
}

const WTF::AtomicString& BackgroundOrigin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-origin"));
  return name;
}

const char* BackgroundOrigin::GetJSPropertyName() const {
  return "backgroundOrigin";
}


void BackgroundOrigin::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetOrigin(FillLayer::InitialFillOrigin(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearOrigin();
}

void BackgroundOrigin::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsOriginSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetOrigin(curr_parent->Origin());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearOrigin();
    curr_child = curr_child->Next();
  }
}

void BackgroundOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillOrigin(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillOrigin(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearOrigin();
    curr_child = curr_child->Next();
  }
}

 // background-position-x



const char* BackgroundPositionX::GetPropertyName() const {
  return "background-position-x";
}

const WTF::AtomicString& BackgroundPositionX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-position-x"));
  return name;
}

const char* BackgroundPositionX::GetJSPropertyName() const {
  return "backgroundPositionX";
}


void BackgroundPositionX::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetPositionX(FillLayer::InitialFillPositionX(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearPositionX();
}

void BackgroundPositionX::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsPositionXSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetPositionX(curr_parent->PositionX());
    if (curr_parent->IsBackgroundXOriginSet())
      curr_child->SetBackgroundXOrigin(curr_parent->BackgroundXOrigin());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearPositionX();
    curr_child = curr_child->Next();
  }
}

void BackgroundPositionX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillPositionX(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillPositionX(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearPositionX();
    curr_child = curr_child->Next();
  }
}

 // background-position-y



const char* BackgroundPositionY::GetPropertyName() const {
  return "background-position-y";
}

const WTF::AtomicString& BackgroundPositionY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-position-y"));
  return name;
}

const char* BackgroundPositionY::GetJSPropertyName() const {
  return "backgroundPositionY";
}


void BackgroundPositionY::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetPositionY(FillLayer::InitialFillPositionY(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearPositionY();
}

void BackgroundPositionY::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsPositionYSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetPositionY(curr_parent->PositionY());
    if (curr_parent->IsBackgroundYOriginSet())
      curr_child->SetBackgroundYOrigin(curr_parent->BackgroundYOrigin());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearPositionY();
    curr_child = curr_child->Next();
  }
}

void BackgroundPositionY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillPositionY(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillPositionY(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearPositionY();
    curr_child = curr_child->Next();
  }
}

 // background-repeat-x



const char* BackgroundRepeatX::GetPropertyName() const {
  return "background-repeat-x";
}

const WTF::AtomicString& BackgroundRepeatX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-repeat-x"));
  return name;
}

const char* BackgroundRepeatX::GetJSPropertyName() const {
  return "backgroundRepeatX";
}


void BackgroundRepeatX::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetRepeatX(FillLayer::InitialFillRepeatX(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearRepeatX();
}

void BackgroundRepeatX::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsRepeatXSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetRepeatX(curr_parent->RepeatX());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearRepeatX();
    curr_child = curr_child->Next();
  }
}

void BackgroundRepeatX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillRepeatX(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillRepeatX(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearRepeatX();
    curr_child = curr_child->Next();
  }
}

 // background-repeat-y



const char* BackgroundRepeatY::GetPropertyName() const {
  return "background-repeat-y";
}

const WTF::AtomicString& BackgroundRepeatY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-repeat-y"));
  return name;
}

const char* BackgroundRepeatY::GetJSPropertyName() const {
  return "backgroundRepeatY";
}


void BackgroundRepeatY::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetRepeatY(FillLayer::InitialFillRepeatY(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearRepeatY();
}

void BackgroundRepeatY::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsRepeatYSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetRepeatY(curr_parent->RepeatY());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearRepeatY();
    curr_child = curr_child->Next();
  }
}

void BackgroundRepeatY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillRepeatY(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillRepeatY(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearRepeatY();
    curr_child = curr_child->Next();
  }
}

 // background-size



const char* BackgroundSize::GetPropertyName() const {
  return "background-size";
}

const WTF::AtomicString& BackgroundSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-size"));
  return name;
}

const char* BackgroundSize::GetJSPropertyName() const {
  return "backgroundSize";
}


void BackgroundSize::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  curr_child->SetSize(FillLayer::InitialFillSize(EFillLayerType::kBackground));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearSize();
}

void BackgroundSize::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
  while (curr_parent && curr_parent->IsSizeSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetSize(curr_parent->Size());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearSize();
    curr_child = curr_child->Next();
  }
}

void BackgroundSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessBackgroundLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillSize(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillSize(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearSize();
    curr_child = curr_child->Next();
  }
}

 // baseline-shift



const char* BaselineShift::GetPropertyName() const {
  return "baseline-shift";
}

const WTF::AtomicString& BaselineShift::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("baseline-shift"));
  return name;
}

const char* BaselineShift::GetJSPropertyName() const {
  return "baselineShift";
}


void BaselineShift::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetBaselineShift(SVGComputedStyle::InitialBaselineShift());
}

 // block-size



const char* BlockSize::GetPropertyName() const {
  return "block-size";
}

const WTF::AtomicString& BlockSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("block-size"));
  return name;
}

const char* BlockSize::GetJSPropertyName() const {
  return "blockSize";
}

const CSSProperty* BlockSize::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BlockSize::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlock(direction, writing_mode,
      CSSDirectionAwareResolver::SizeGroup());
}

void BlockSize::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BlockSize::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BlockSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-block-end-color



const char* BorderBlockEndColor::GetPropertyName() const {
  return "border-block-end-color";
}

const WTF::AtomicString& BorderBlockEndColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-end-color"));
  return name;
}

const char* BorderBlockEndColor::GetJSPropertyName() const {
  return "borderBlockEndColor";
}
const CSSProperty* BorderBlockEndColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderBlockEndColor();
}

const CSSProperty* BorderBlockEndColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderBlockEndColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderColorGroup());
}

void BorderBlockEndColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderBlockEndColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderBlockEndColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-block-end-style



const char* BorderBlockEndStyle::GetPropertyName() const {
  return "border-block-end-style";
}

const WTF::AtomicString& BorderBlockEndStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-end-style"));
  return name;
}

const char* BorderBlockEndStyle::GetJSPropertyName() const {
  return "borderBlockEndStyle";
}

const CSSProperty* BorderBlockEndStyle::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderBlockEndStyle::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderStyleGroup());
}

void BorderBlockEndStyle::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderBlockEndStyle::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderBlockEndStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-block-end-width



const char* BorderBlockEndWidth::GetPropertyName() const {
  return "border-block-end-width";
}

const WTF::AtomicString& BorderBlockEndWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-end-width"));
  return name;
}

const char* BorderBlockEndWidth::GetJSPropertyName() const {
  return "borderBlockEndWidth";
}

const CSSProperty* BorderBlockEndWidth::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderBlockEndWidth::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderWidthGroup());
}

void BorderBlockEndWidth::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderBlockEndWidth::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderBlockEndWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-block-start-color



const char* BorderBlockStartColor::GetPropertyName() const {
  return "border-block-start-color";
}

const WTF::AtomicString& BorderBlockStartColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-start-color"));
  return name;
}

const char* BorderBlockStartColor::GetJSPropertyName() const {
  return "borderBlockStartColor";
}
const CSSProperty* BorderBlockStartColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderBlockStartColor();
}

const CSSProperty* BorderBlockStartColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderBlockStartColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderColorGroup());
}

void BorderBlockStartColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderBlockStartColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderBlockStartColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-block-start-style



const char* BorderBlockStartStyle::GetPropertyName() const {
  return "border-block-start-style";
}

const WTF::AtomicString& BorderBlockStartStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-start-style"));
  return name;
}

const char* BorderBlockStartStyle::GetJSPropertyName() const {
  return "borderBlockStartStyle";
}

const CSSProperty* BorderBlockStartStyle::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderBlockStartStyle::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderStyleGroup());
}

void BorderBlockStartStyle::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderBlockStartStyle::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderBlockStartStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-block-start-width



const char* BorderBlockStartWidth::GetPropertyName() const {
  return "border-block-start-width";
}

const WTF::AtomicString& BorderBlockStartWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-start-width"));
  return name;
}

const char* BorderBlockStartWidth::GetJSPropertyName() const {
  return "borderBlockStartWidth";
}

const CSSProperty* BorderBlockStartWidth::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderBlockStartWidth::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderWidthGroup());
}

void BorderBlockStartWidth::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderBlockStartWidth::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderBlockStartWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-bottom-color



const char* BorderBottomColor::GetPropertyName() const {
  return "border-bottom-color";
}

const WTF::AtomicString& BorderBottomColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-color"));
  return name;
}

const char* BorderBottomColor::GetJSPropertyName() const {
  return "borderBottomColor";
}
const CSSProperty* BorderBottomColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderBottomColor();
}

bool BorderBottomColor::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderBottomColor() == b.BorderBottomColor();
}

void BorderBottomColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetBorderBottomColor(color);
}

void BorderBottomColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderBottomColor();
  state.Style()->SetBorderBottomColor(color);
}

void BorderBottomColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderBottomColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // border-bottom-left-radius



const char* BorderBottomLeftRadius::GetPropertyName() const {
  return "border-bottom-left-radius";
}

const WTF::AtomicString& BorderBottomLeftRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-left-radius"));
  return name;
}

const char* BorderBottomLeftRadius::GetJSPropertyName() const {
  return "borderBottomLeftRadius";
}

bool BorderBottomLeftRadius::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderBottomLeftRadius() == b.BorderBottomLeftRadius();
}

void BorderBottomLeftRadius::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderBottomLeftRadius(ComputedStyleInitialValues::InitialBorderBottomLeftRadius());
}
void BorderBottomLeftRadius::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderBottomLeftRadius(state.ParentStyle()->BorderBottomLeftRadius());
}
void BorderBottomLeftRadius::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderBottomLeftRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

 // border-bottom-right-radius



const char* BorderBottomRightRadius::GetPropertyName() const {
  return "border-bottom-right-radius";
}

const WTF::AtomicString& BorderBottomRightRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-right-radius"));
  return name;
}

const char* BorderBottomRightRadius::GetJSPropertyName() const {
  return "borderBottomRightRadius";
}

bool BorderBottomRightRadius::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderBottomRightRadius() == b.BorderBottomRightRadius();
}

void BorderBottomRightRadius::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderBottomRightRadius(ComputedStyleInitialValues::InitialBorderBottomRightRadius());
}
void BorderBottomRightRadius::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderBottomRightRadius(state.ParentStyle()->BorderBottomRightRadius());
}
void BorderBottomRightRadius::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderBottomRightRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

 // border-bottom-style



const char* BorderBottomStyle::GetPropertyName() const {
  return "border-bottom-style";
}

const WTF::AtomicString& BorderBottomStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-style"));
  return name;
}

const char* BorderBottomStyle::GetJSPropertyName() const {
  return "borderBottomStyle";
}

bool BorderBottomStyle::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderBottomStyle() == b.BorderBottomStyle();
}

void BorderBottomStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderBottomStyle(ComputedStyleInitialValues::InitialBorderBottomStyle());
}
void BorderBottomStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderBottomStyle(state.ParentStyle()->BorderBottomStyle());
}
void BorderBottomStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderBottomStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

 // border-bottom-width



const char* BorderBottomWidth::GetPropertyName() const {
  return "border-bottom-width";
}

const WTF::AtomicString& BorderBottomWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-width"));
  return name;
}

const char* BorderBottomWidth::GetJSPropertyName() const {
  return "borderBottomWidth";
}

bool BorderBottomWidth::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderBottomWidth() == b.BorderBottomWidth();
}

void BorderBottomWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderBottomWidth(ComputedStyleInitialValues::InitialBorderBottomWidth());
}
void BorderBottomWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderBottomWidth(state.ParentStyle()->BorderBottomWidth());
}
void BorderBottomWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderBottomWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

 // border-collapse



const char* BorderCollapse::GetPropertyName() const {
  return "border-collapse";
}

const WTF::AtomicString& BorderCollapse::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-collapse"));
  return name;
}

const char* BorderCollapse::GetJSPropertyName() const {
  return "borderCollapse";
}


void BorderCollapse::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderCollapse(ComputedStyleInitialValues::InitialBorderCollapse());
  state.Style()->SetBorderCollapseIsInherited(false);
}
void BorderCollapse::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderCollapse(state.ParentStyle()->BorderCollapse());
  state.Style()->SetBorderCollapseIsInherited(true);
}
void BorderCollapse::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderCollapse(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderCollapse>());
  state.Style()->SetBorderCollapseIsInherited(false);
}

 // border-image-outset



const char* BorderImageOutset::GetPropertyName() const {
  return "border-image-outset";
}

const WTF::AtomicString& BorderImageOutset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-outset"));
  return name;
}

const char* BorderImageOutset::GetJSPropertyName() const {
  return "borderImageOutset";
}


void BorderImageOutset::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->BorderImage();
  if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.Outset(),
                                       BorderImageLength(0)))
    return;
  NinePieceImage image(current_image);
  image.SetOutset(0);
  state.Style()->SetBorderImage(image);
}
void BorderImageOutset::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->BorderImage());
  image.CopyOutsetFrom(state.ParentStyle()->BorderImage());
  state.Style()->SetBorderImage(image);
}
void BorderImageOutset::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->BorderImage());
  image.SetOutset(CSSToStyleMap::MapNinePieceImageQuad(state, value));
  state.Style()->SetBorderImage(image);
}

 // border-image-repeat



const char* BorderImageRepeat::GetPropertyName() const {
  return "border-image-repeat";
}

const WTF::AtomicString& BorderImageRepeat::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-repeat"));
  return name;
}

const char* BorderImageRepeat::GetJSPropertyName() const {
  return "borderImageRepeat";
}


void BorderImageRepeat::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->BorderImage();
  if (current_image.HorizontalRule() == kStretchImageRule &&
      current_image.VerticalRule() == kStretchImageRule)
    return;
  NinePieceImage image(current_image);
  image.SetHorizontalRule(kStretchImageRule);
  image.SetVerticalRule(kStretchImageRule);
  state.Style()->SetBorderImage(image);
}
void BorderImageRepeat::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->BorderImage());
  image.CopyRepeatFrom(state.ParentStyle()->BorderImage());
  state.Style()->SetBorderImage(image);
}
void BorderImageRepeat::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->BorderImage());
  CSSToStyleMap::MapNinePieceImageRepeat(state, value, image);
  state.Style()->SetBorderImage(image);
}

 // border-image-slice



const char* BorderImageSlice::GetPropertyName() const {
  return "border-image-slice";
}

const WTF::AtomicString& BorderImageSlice::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-slice"));
  return name;
}

const char* BorderImageSlice::GetJSPropertyName() const {
  return "borderImageSlice";
}


void BorderImageSlice::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->BorderImage();
  if (current_image.Fill() == false &&
      style_building_utils::LengthMatchesAllSides(current_image.ImageSlices(), Length::Percent(100)))
    return;
  NinePieceImage image(current_image);
  image.SetImageSlices(LengthBox(Length::Percent(100), Length::Percent(100), Length::Percent(100), Length::Percent(100)));
  image.SetFill(false);
  state.Style()->SetBorderImage(image);
}
void BorderImageSlice::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->BorderImage());
  image.CopyImageSlicesFrom(state.ParentStyle()->BorderImage());
  state.Style()->SetBorderImage(image);
}
void BorderImageSlice::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->BorderImage());
  CSSToStyleMap::MapNinePieceImageSlice(state, value, image);
  state.Style()->SetBorderImage(image);
}

 // border-image-source



const char* BorderImageSource::GetPropertyName() const {
  return "border-image-source";
}

const WTF::AtomicString& BorderImageSource::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-source"));
  return name;
}

const char* BorderImageSource::GetJSPropertyName() const {
  return "borderImageSource";
}


void BorderImageSource::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderImageSource(ComputedStyleInitialValues::InitialBorderImageSource());
}
void BorderImageSource::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderImageSource(state.ParentStyle()->BorderImageSource());
}

 // border-image-width



const char* BorderImageWidth::GetPropertyName() const {
  return "border-image-width";
}

const WTF::AtomicString& BorderImageWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-width"));
  return name;
}

const char* BorderImageWidth::GetJSPropertyName() const {
  return "borderImageWidth";
}


void BorderImageWidth::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->BorderImage();
  if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.BorderSlices(),
                                       BorderImageLength(1.0)))
    return;
  NinePieceImage image(current_image);
  image.SetBorderSlices(1.0);
  state.Style()->SetBorderImage(image);
}
void BorderImageWidth::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->BorderImage());
  image.CopyBorderSlicesFrom(state.ParentStyle()->BorderImage());
  state.Style()->SetBorderImage(image);
}
void BorderImageWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->BorderImage());
  image.SetBorderSlices(CSSToStyleMap::MapNinePieceImageQuad(state, value));
  state.Style()->SetBorderImage(image);
}

 // border-inline-end-color



const char* BorderInlineEndColor::GetPropertyName() const {
  return "border-inline-end-color";
}

const WTF::AtomicString& BorderInlineEndColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-end-color"));
  return name;
}

const char* BorderInlineEndColor::GetJSPropertyName() const {
  return "borderInlineEndColor";
}
const CSSProperty* BorderInlineEndColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderInlineEndColor();
}

const CSSProperty* BorderInlineEndColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderInlineEndColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderColorGroup());
}

void BorderInlineEndColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderInlineEndColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderInlineEndColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-inline-end-style



const char* BorderInlineEndStyle::GetPropertyName() const {
  return "border-inline-end-style";
}

const WTF::AtomicString& BorderInlineEndStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-end-style"));
  return name;
}

const char* BorderInlineEndStyle::GetJSPropertyName() const {
  return "borderInlineEndStyle";
}

const CSSProperty* BorderInlineEndStyle::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderInlineEndStyle::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderStyleGroup());
}

void BorderInlineEndStyle::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderInlineEndStyle::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderInlineEndStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-inline-end-width



const char* BorderInlineEndWidth::GetPropertyName() const {
  return "border-inline-end-width";
}

const WTF::AtomicString& BorderInlineEndWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-end-width"));
  return name;
}

const char* BorderInlineEndWidth::GetJSPropertyName() const {
  return "borderInlineEndWidth";
}

const CSSProperty* BorderInlineEndWidth::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderInlineEndWidth::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::BorderWidthGroup());
}

void BorderInlineEndWidth::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderInlineEndWidth::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderInlineEndWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-inline-start-color



const char* BorderInlineStartColor::GetPropertyName() const {
  return "border-inline-start-color";
}

const WTF::AtomicString& BorderInlineStartColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-start-color"));
  return name;
}

const char* BorderInlineStartColor::GetJSPropertyName() const {
  return "borderInlineStartColor";
}
const CSSProperty* BorderInlineStartColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderInlineStartColor();
}

const CSSProperty* BorderInlineStartColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderInlineStartColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderColorGroup());
}

void BorderInlineStartColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderInlineStartColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderInlineStartColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-inline-start-style



const char* BorderInlineStartStyle::GetPropertyName() const {
  return "border-inline-start-style";
}

const WTF::AtomicString& BorderInlineStartStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-start-style"));
  return name;
}

const char* BorderInlineStartStyle::GetJSPropertyName() const {
  return "borderInlineStartStyle";
}

const CSSProperty* BorderInlineStartStyle::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderInlineStartStyle::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderStyleGroup());
}

void BorderInlineStartStyle::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderInlineStartStyle::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderInlineStartStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-inline-start-width



const char* BorderInlineStartWidth::GetPropertyName() const {
  return "border-inline-start-width";
}

const WTF::AtomicString& BorderInlineStartWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-start-width"));
  return name;
}

const char* BorderInlineStartWidth::GetJSPropertyName() const {
  return "borderInlineStartWidth";
}

const CSSProperty* BorderInlineStartWidth::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& BorderInlineStartWidth::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::BorderWidthGroup());
}

void BorderInlineStartWidth::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void BorderInlineStartWidth::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void BorderInlineStartWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // border-left-color



const char* BorderLeftColor::GetPropertyName() const {
  return "border-left-color";
}

const WTF::AtomicString& BorderLeftColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-left-color"));
  return name;
}

const char* BorderLeftColor::GetJSPropertyName() const {
  return "borderLeftColor";
}
const CSSProperty* BorderLeftColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderLeftColor();
}

bool BorderLeftColor::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderLeftColor() == b.BorderLeftColor();
}

void BorderLeftColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetBorderLeftColor(color);
}

void BorderLeftColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderLeftColor();
  state.Style()->SetBorderLeftColor(color);
}

void BorderLeftColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderLeftColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // border-left-style



const char* BorderLeftStyle::GetPropertyName() const {
  return "border-left-style";
}

const WTF::AtomicString& BorderLeftStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-left-style"));
  return name;
}

const char* BorderLeftStyle::GetJSPropertyName() const {
  return "borderLeftStyle";
}

bool BorderLeftStyle::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderLeftStyle() == b.BorderLeftStyle();
}

void BorderLeftStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderLeftStyle(ComputedStyleInitialValues::InitialBorderLeftStyle());
}
void BorderLeftStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderLeftStyle(state.ParentStyle()->BorderLeftStyle());
}
void BorderLeftStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderLeftStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

 // border-left-width



const char* BorderLeftWidth::GetPropertyName() const {
  return "border-left-width";
}

const WTF::AtomicString& BorderLeftWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-left-width"));
  return name;
}

const char* BorderLeftWidth::GetJSPropertyName() const {
  return "borderLeftWidth";
}

bool BorderLeftWidth::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderLeftWidth() == b.BorderLeftWidth();
}

void BorderLeftWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderLeftWidth(ComputedStyleInitialValues::InitialBorderLeftWidth());
}
void BorderLeftWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderLeftWidth(state.ParentStyle()->BorderLeftWidth());
}
void BorderLeftWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderLeftWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

 // border-right-color



const char* BorderRightColor::GetPropertyName() const {
  return "border-right-color";
}

const WTF::AtomicString& BorderRightColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-right-color"));
  return name;
}

const char* BorderRightColor::GetJSPropertyName() const {
  return "borderRightColor";
}
const CSSProperty* BorderRightColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderRightColor();
}

bool BorderRightColor::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderRightColor() == b.BorderRightColor();
}

void BorderRightColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetBorderRightColor(color);
}

void BorderRightColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderRightColor();
  state.Style()->SetBorderRightColor(color);
}

void BorderRightColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderRightColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // border-right-style



const char* BorderRightStyle::GetPropertyName() const {
  return "border-right-style";
}

const WTF::AtomicString& BorderRightStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-right-style"));
  return name;
}

const char* BorderRightStyle::GetJSPropertyName() const {
  return "borderRightStyle";
}

bool BorderRightStyle::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderRightStyle() == b.BorderRightStyle();
}

void BorderRightStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderRightStyle(ComputedStyleInitialValues::InitialBorderRightStyle());
}
void BorderRightStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderRightStyle(state.ParentStyle()->BorderRightStyle());
}
void BorderRightStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderRightStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

 // border-right-width



const char* BorderRightWidth::GetPropertyName() const {
  return "border-right-width";
}

const WTF::AtomicString& BorderRightWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-right-width"));
  return name;
}

const char* BorderRightWidth::GetJSPropertyName() const {
  return "borderRightWidth";
}

bool BorderRightWidth::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderRightWidth() == b.BorderRightWidth();
}

void BorderRightWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderRightWidth(ComputedStyleInitialValues::InitialBorderRightWidth());
}
void BorderRightWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderRightWidth(state.ParentStyle()->BorderRightWidth());
}
void BorderRightWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderRightWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

 // border-top-color



const char* BorderTopColor::GetPropertyName() const {
  return "border-top-color";
}

const WTF::AtomicString& BorderTopColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-color"));
  return name;
}

const char* BorderTopColor::GetJSPropertyName() const {
  return "borderTopColor";
}
const CSSProperty* BorderTopColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedBorderTopColor();
}

bool BorderTopColor::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderTopColor() == b.BorderTopColor();
}

void BorderTopColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetBorderTopColor(color);
}

void BorderTopColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderTopColor();
  state.Style()->SetBorderTopColor(color);
}

void BorderTopColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderTopColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // border-top-left-radius



const char* BorderTopLeftRadius::GetPropertyName() const {
  return "border-top-left-radius";
}

const WTF::AtomicString& BorderTopLeftRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-left-radius"));
  return name;
}

const char* BorderTopLeftRadius::GetJSPropertyName() const {
  return "borderTopLeftRadius";
}

bool BorderTopLeftRadius::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderTopLeftRadius() == b.BorderTopLeftRadius();
}

void BorderTopLeftRadius::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderTopLeftRadius(ComputedStyleInitialValues::InitialBorderTopLeftRadius());
}
void BorderTopLeftRadius::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderTopLeftRadius(state.ParentStyle()->BorderTopLeftRadius());
}
void BorderTopLeftRadius::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderTopLeftRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

 // border-top-right-radius



const char* BorderTopRightRadius::GetPropertyName() const {
  return "border-top-right-radius";
}

const WTF::AtomicString& BorderTopRightRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-right-radius"));
  return name;
}

const char* BorderTopRightRadius::GetJSPropertyName() const {
  return "borderTopRightRadius";
}

bool BorderTopRightRadius::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderTopRightRadius() == b.BorderTopRightRadius();
}

void BorderTopRightRadius::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderTopRightRadius(ComputedStyleInitialValues::InitialBorderTopRightRadius());
}
void BorderTopRightRadius::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderTopRightRadius(state.ParentStyle()->BorderTopRightRadius());
}
void BorderTopRightRadius::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderTopRightRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

 // border-top-style



const char* BorderTopStyle::GetPropertyName() const {
  return "border-top-style";
}

const WTF::AtomicString& BorderTopStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-style"));
  return name;
}

const char* BorderTopStyle::GetJSPropertyName() const {
  return "borderTopStyle";
}

bool BorderTopStyle::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderTopStyle() == b.BorderTopStyle();
}

void BorderTopStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderTopStyle(ComputedStyleInitialValues::InitialBorderTopStyle());
}
void BorderTopStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderTopStyle(state.ParentStyle()->BorderTopStyle());
}
void BorderTopStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderTopStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

 // border-top-width



const char* BorderTopWidth::GetPropertyName() const {
  return "border-top-width";
}

const WTF::AtomicString& BorderTopWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-width"));
  return name;
}

const char* BorderTopWidth::GetJSPropertyName() const {
  return "borderTopWidth";
}

bool BorderTopWidth::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.BorderTopWidth() == b.BorderTopWidth();
}

void BorderTopWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderTopWidth(ComputedStyleInitialValues::InitialBorderTopWidth());
}
void BorderTopWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderTopWidth(state.ParentStyle()->BorderTopWidth());
}
void BorderTopWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBorderTopWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

 // bottom



const char* Bottom::GetPropertyName() const {
  return "bottom";
}

const WTF::AtomicString& Bottom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("bottom"));
  return name;
}

const char* Bottom::GetJSPropertyName() const {
  return "bottom";
}

bool Bottom::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.Bottom() == b.Bottom();
}

void Bottom::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBottom(ComputedStyleInitialValues::InitialBottom());
}
void Bottom::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBottom(state.ParentStyle()->Bottom());
}
void Bottom::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBottom(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // box-shadow



const char* BoxShadow::GetPropertyName() const {
  return "box-shadow";
}

const WTF::AtomicString& BoxShadow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("box-shadow"));
  return name;
}

const char* BoxShadow::GetJSPropertyName() const {
  return "boxShadow";
}


void BoxShadow::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxShadow(ComputedStyleInitialValues::InitialBoxShadow());
}
void BoxShadow::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxShadow(state.ParentStyle()->BoxShadow());
}
void BoxShadow::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxShadow(StyleBuilderConverter::ConvertShadowList(state, value));
}

 // box-sizing



const char* BoxSizing::GetPropertyName() const {
  return "box-sizing";
}

const WTF::AtomicString& BoxSizing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("box-sizing"));
  return name;
}

const char* BoxSizing::GetJSPropertyName() const {
  return "boxSizing";
}


void BoxSizing::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxSizing(ComputedStyleInitialValues::InitialBoxSizing());
}
void BoxSizing::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxSizing(state.ParentStyle()->BoxSizing());
}
void BoxSizing::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxSizing(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxSizing>());
}

 // break-after



const char* BreakAfter::GetPropertyName() const {
  return "break-after";
}

const WTF::AtomicString& BreakAfter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("break-after"));
  return name;
}

const char* BreakAfter::GetJSPropertyName() const {
  return "breakAfter";
}


void BreakAfter::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBreakAfter(ComputedStyleInitialValues::InitialBreakAfter());
}
void BreakAfter::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBreakAfter(state.ParentStyle()->BreakAfter());
}
void BreakAfter::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBreakAfter(To<CSSIdentifierValue>(value).ConvertTo<blink::EBreakBetween>());
}

 // break-before



const char* BreakBefore::GetPropertyName() const {
  return "break-before";
}

const WTF::AtomicString& BreakBefore::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("break-before"));
  return name;
}

const char* BreakBefore::GetJSPropertyName() const {
  return "breakBefore";
}


void BreakBefore::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBreakBefore(ComputedStyleInitialValues::InitialBreakBefore());
}
void BreakBefore::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBreakBefore(state.ParentStyle()->BreakBefore());
}
void BreakBefore::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBreakBefore(To<CSSIdentifierValue>(value).ConvertTo<blink::EBreakBetween>());
}

 // break-inside



const char* BreakInside::GetPropertyName() const {
  return "break-inside";
}

const WTF::AtomicString& BreakInside::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("break-inside"));
  return name;
}

const char* BreakInside::GetJSPropertyName() const {
  return "breakInside";
}


void BreakInside::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBreakInside(ComputedStyleInitialValues::InitialBreakInside());
}
void BreakInside::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBreakInside(state.ParentStyle()->BreakInside());
}
void BreakInside::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBreakInside(To<CSSIdentifierValue>(value).ConvertTo<blink::EBreakInside>());
}

 // buffered-rendering



const char* BufferedRendering::GetPropertyName() const {
  return "buffered-rendering";
}

const WTF::AtomicString& BufferedRendering::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("buffered-rendering"));
  return name;
}

const char* BufferedRendering::GetJSPropertyName() const {
  return "bufferedRendering";
}


void BufferedRendering::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetBufferedRendering(SVGComputedStyle::InitialBufferedRendering());
}
void BufferedRendering::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetBufferedRendering(state.ParentStyle()->SvgStyle().BufferedRendering());
}
void BufferedRendering::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetBufferedRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EBufferedRendering>());
}

 // caption-side



const char* CaptionSide::GetPropertyName() const {
  return "caption-side";
}

const WTF::AtomicString& CaptionSide::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("caption-side"));
  return name;
}

const char* CaptionSide::GetJSPropertyName() const {
  return "captionSide";
}


void CaptionSide::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetCaptionSide(ComputedStyleInitialValues::InitialCaptionSide());
  state.Style()->SetCaptionSideIsInherited(false);
}
void CaptionSide::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetCaptionSide(state.ParentStyle()->CaptionSide());
  state.Style()->SetCaptionSideIsInherited(true);
}
void CaptionSide::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetCaptionSide(To<CSSIdentifierValue>(value).ConvertTo<blink::ECaptionSide>());
  state.Style()->SetCaptionSideIsInherited(false);
}

 // caret-color



const char* CaretColor::GetPropertyName() const {
  return "caret-color";
}

const WTF::AtomicString& CaretColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("caret-color"));
  return name;
}

const char* CaretColor::GetJSPropertyName() const {
  return "caretColor";
}
const CSSProperty* CaretColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedCaretColor();
}



 // clear



const char* Clear::GetPropertyName() const {
  return "clear";
}

const WTF::AtomicString& Clear::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("clear"));
  return name;
}

const char* Clear::GetJSPropertyName() const {
  return "clear";
}


void Clear::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetClear(ComputedStyleInitialValues::InitialClear());
}
void Clear::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetClear(state.ParentStyle()->Clear());
}
void Clear::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetClear(To<CSSIdentifierValue>(value).ConvertTo<blink::EClear>());
}

 // clip



const char* Clip::GetPropertyName() const {
  return "clip";
}

const WTF::AtomicString& Clip::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("clip"));
  return name;
}

const char* Clip::GetJSPropertyName() const {
  return "clip";
}


void Clip::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHasAutoClip();
}
void Clip::ApplyInherit(StyleResolverState& state) const {
  if (state.ParentStyle()->HasAutoClip())
    state.Style()->SetHasAutoClip();
  else
    state.Style()->SetClip(state.ParentStyle()->Clip());
}
void Clip::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
  if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
    state.Style()->SetHasAutoClip();
  else
    state.Style()->SetClip(StyleBuilderConverter::ConvertClip(state, value));
}

 // clip-path



const char* ClipPath::GetPropertyName() const {
  return "clip-path";
}

const WTF::AtomicString& ClipPath::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("clip-path"));
  return name;
}

const char* ClipPath::GetJSPropertyName() const {
  return "clipPath";
}


void ClipPath::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetClipPath(ComputedStyleInitialValues::InitialClipPath());
}
void ClipPath::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetClipPath(state.ParentStyle()->ClipPath());
}
void ClipPath::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetClipPath(StyleBuilderConverter::ConvertClipPath(state, value));
}

 // clip-rule



const char* ClipRule::GetPropertyName() const {
  return "clip-rule";
}

const WTF::AtomicString& ClipRule::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("clip-rule"));
  return name;
}

const char* ClipRule::GetJSPropertyName() const {
  return "clipRule";
}


void ClipRule::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetClipRule(SVGComputedStyle::InitialClipRule());
}
void ClipRule::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetClipRule(state.ParentStyle()->SvgStyle().ClipRule());
}
void ClipRule::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetClipRule(To<CSSIdentifierValue>(value).ConvertTo<blink::WindRule>());
}

 // color-interpolation



const char* ColorInterpolation::GetPropertyName() const {
  return "color-interpolation";
}

const WTF::AtomicString& ColorInterpolation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-interpolation"));
  return name;
}

const char* ColorInterpolation::GetJSPropertyName() const {
  return "colorInterpolation";
}


void ColorInterpolation::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetColorInterpolation(SVGComputedStyle::InitialColorInterpolation());
}
void ColorInterpolation::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetColorInterpolation(state.ParentStyle()->SvgStyle().ColorInterpolation());
}
void ColorInterpolation::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetColorInterpolation(To<CSSIdentifierValue>(value).ConvertTo<blink::EColorInterpolation>());
}

 // color-interpolation-filters



const char* ColorInterpolationFilters::GetPropertyName() const {
  return "color-interpolation-filters";
}

const WTF::AtomicString& ColorInterpolationFilters::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-interpolation-filters"));
  return name;
}

const char* ColorInterpolationFilters::GetJSPropertyName() const {
  return "colorInterpolationFilters";
}


void ColorInterpolationFilters::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetColorInterpolationFilters(SVGComputedStyle::InitialColorInterpolationFilters());
}
void ColorInterpolationFilters::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetColorInterpolationFilters(state.ParentStyle()->SvgStyle().ColorInterpolationFilters());
}
void ColorInterpolationFilters::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetColorInterpolationFilters(To<CSSIdentifierValue>(value).ConvertTo<blink::EColorInterpolation>());
}

 // color-rendering



const char* ColorRendering::GetPropertyName() const {
  return "color-rendering";
}

const WTF::AtomicString& ColorRendering::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-rendering"));
  return name;
}

const char* ColorRendering::GetJSPropertyName() const {
  return "colorRendering";
}


void ColorRendering::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetColorRendering(SVGComputedStyle::InitialColorRendering());
}
void ColorRendering::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetColorRendering(state.ParentStyle()->SvgStyle().ColorRendering());
}
void ColorRendering::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetColorRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EColorRendering>());
}

 // column-count



const char* ColumnCount::GetPropertyName() const {
  return "column-count";
}

const WTF::AtomicString& ColumnCount::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-count"));
  return name;
}

const char* ColumnCount::GetJSPropertyName() const {
  return "columnCount";
}


void ColumnCount::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHasAutoColumnCount();
}
void ColumnCount::ApplyInherit(StyleResolverState& state) const {
  if (state.ParentStyle()->HasAutoColumnCount())
    state.Style()->SetHasAutoColumnCount();
  else
    state.Style()->SetColumnCount(state.ParentStyle()->ColumnCount());
}
void ColumnCount::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
  if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
    state.Style()->SetHasAutoColumnCount();
  else
    state.Style()->SetColumnCount(To<CSSPrimitiveValue>(value).ConvertTo<unsigned short>());
}

 // column-fill



const char* ColumnFill::GetPropertyName() const {
  return "column-fill";
}

const WTF::AtomicString& ColumnFill::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-fill"));
  return name;
}

const char* ColumnFill::GetJSPropertyName() const {
  return "columnFill";
}


void ColumnFill::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetColumnFill(ComputedStyleInitialValues::InitialColumnFill());
}
void ColumnFill::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetColumnFill(state.ParentStyle()->GetColumnFill());
}
void ColumnFill::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetColumnFill(To<CSSIdentifierValue>(value).ConvertTo<blink::EColumnFill>());
}

 // column-gap



const char* ColumnGap::GetPropertyName() const {
  return "column-gap";
}

const WTF::AtomicString& ColumnGap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-gap"));
  return name;
}

const char* ColumnGap::GetJSPropertyName() const {
  return "columnGap";
}


void ColumnGap::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetColumnGap(ComputedStyleInitialValues::InitialColumnGap());
}
void ColumnGap::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetColumnGap(state.ParentStyle()->ColumnGap());
}
void ColumnGap::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetColumnGap(StyleBuilderConverter::ConvertGapLength(state, value));
}

 // column-rule-color



const char* ColumnRuleColor::GetPropertyName() const {
  return "column-rule-color";
}

const WTF::AtomicString& ColumnRuleColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-rule-color"));
  return name;
}

const char* ColumnRuleColor::GetJSPropertyName() const {
  return "columnRuleColor";
}
const CSSProperty* ColumnRuleColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedColumnRuleColor();
}


void ColumnRuleColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetColumnRuleColor(color);
}

void ColumnRuleColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->ColumnRuleColor();
  state.Style()->SetColumnRuleColor(color);
}

void ColumnRuleColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetColumnRuleColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // column-rule-style



const char* ColumnRuleStyle::GetPropertyName() const {
  return "column-rule-style";
}

const WTF::AtomicString& ColumnRuleStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-rule-style"));
  return name;
}

const char* ColumnRuleStyle::GetJSPropertyName() const {
  return "columnRuleStyle";
}


void ColumnRuleStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetColumnRuleStyle(ComputedStyleInitialValues::InitialColumnRuleStyle());
}
void ColumnRuleStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetColumnRuleStyle(state.ParentStyle()->ColumnRuleStyle());
}
void ColumnRuleStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetColumnRuleStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

 // column-rule-width



const char* ColumnRuleWidth::GetPropertyName() const {
  return "column-rule-width";
}

const WTF::AtomicString& ColumnRuleWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-rule-width"));
  return name;
}

const char* ColumnRuleWidth::GetJSPropertyName() const {
  return "columnRuleWidth";
}


void ColumnRuleWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetColumnRuleWidth(ComputedStyleInitialValues::InitialColumnRuleWidth());
}
void ColumnRuleWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetColumnRuleWidth(state.ParentStyle()->ColumnRuleWidth());
}
void ColumnRuleWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetColumnRuleWidth(StyleBuilderConverter::ConvertLineWidth<unsigned short>(state, value));
}

 // column-span



const char* ColumnSpan::GetPropertyName() const {
  return "column-span";
}

const WTF::AtomicString& ColumnSpan::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-span"));
  return name;
}

const char* ColumnSpan::GetJSPropertyName() const {
  return "columnSpan";
}


void ColumnSpan::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetColumnSpan(ComputedStyleInitialValues::InitialColumnSpan());
}
void ColumnSpan::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetColumnSpan(state.ParentStyle()->GetColumnSpan());
}
void ColumnSpan::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetColumnSpan(To<CSSIdentifierValue>(value).ConvertTo<blink::EColumnSpan>());
}

 // column-width



const char* ColumnWidth::GetPropertyName() const {
  return "column-width";
}

const WTF::AtomicString& ColumnWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-width"));
  return name;
}

const char* ColumnWidth::GetJSPropertyName() const {
  return "columnWidth";
}


void ColumnWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHasAutoColumnWidth();
}
void ColumnWidth::ApplyInherit(StyleResolverState& state) const {
  if (state.ParentStyle()->HasAutoColumnWidth())
    state.Style()->SetHasAutoColumnWidth();
  else
    state.Style()->SetColumnWidth(state.ParentStyle()->ColumnWidth());
}
void ColumnWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
  if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
    state.Style()->SetHasAutoColumnWidth();
  else
    state.Style()->SetColumnWidth(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

 // contain



const char* Contain::GetPropertyName() const {
  return "contain";
}

const WTF::AtomicString& Contain::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain"));
  return name;
}

const char* Contain::GetJSPropertyName() const {
  return "contain";
}


void Contain::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetContain(ComputedStyleInitialValues::InitialContain());
}
void Contain::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetContain(state.ParentStyle()->Contain());
}
void Contain::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetContain(StyleBuilderConverter::ConvertFlags<Containment>(state, value));
}

 // contain-intrinsic-size



const char* ContainIntrinsicSize::GetPropertyName() const {
  return "contain-intrinsic-size";
}

const WTF::AtomicString& ContainIntrinsicSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain-intrinsic-size"));
  return name;
}

const char* ContainIntrinsicSize::GetJSPropertyName() const {
  return "containIntrinsicSize";
}


void ContainIntrinsicSize::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetContainIntrinsicSize(ComputedStyleInitialValues::InitialContainIntrinsicSize());
}
void ContainIntrinsicSize::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetContainIntrinsicSize(state.ParentStyle()->ContainIntrinsicSize());
}
void ContainIntrinsicSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetContainIntrinsicSize(StyleBuilderConverter::ConvertIntrinsicSize(state, value));
}

 // content



const char* Content::GetPropertyName() const {
  return "content";
}

const WTF::AtomicString& Content::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("content"));
  return name;
}

const char* Content::GetJSPropertyName() const {
  return "content";
}



 // content-visibility

CSSExposure ContentVisibility::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSContentVisibilityEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* ContentVisibility::GetPropertyName() const {
  return "content-visibility";
}

const WTF::AtomicString& ContentVisibility::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("content-visibility"));
  return name;
}

const char* ContentVisibility::GetJSPropertyName() const {
  return "contentVisibility";
}


void ContentVisibility::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetContentVisibility(ComputedStyleInitialValues::InitialContentVisibility());
}
void ContentVisibility::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetContentVisibility(state.ParentStyle()->ContentVisibility());
}
void ContentVisibility::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetContentVisibility(To<CSSIdentifierValue>(value).ConvertTo<blink::EContentVisibility>());
}

 // counter-increment



const char* CounterIncrement::GetPropertyName() const {
  return "counter-increment";
}

const WTF::AtomicString& CounterIncrement::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("counter-increment"));
  return name;
}

const char* CounterIncrement::GetJSPropertyName() const {
  return "counterIncrement";
}


void CounterIncrement::ApplyInitial(StyleResolverState& state) const {
  state.Style()->ClearIncrementDirectives();
}

void CounterIncrement::ApplyInherit(StyleResolverState& state) const {
  state.Style()->ClearIncrementDirectives();
  const CounterDirectiveMap* parent_map = state.ParentStyle()->GetCounterDirectives();
  if (!parent_map)
    return;

  CounterDirectiveMap& map = state.Style()->AccessCounterDirectives();
  DCHECK(!parent_map->IsEmpty());

  typedef CounterDirectiveMap::const_iterator Iterator;
  Iterator end = parent_map->end();
  for (Iterator it = parent_map->begin(); it != end; ++it) {
    CounterDirectives& directives = map.insert(it->key, CounterDirectives()).stored_value->value;
    directives.InheritIncrement(it->value);
  }
}

void CounterIncrement::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->ClearIncrementDirectives();

  const auto* list = DynamicTo<CSSValueList>(value);
  if (!list) {
    DCHECK_EQ(To<CSSIdentifierValue>(value).GetValueID(), CSSValueID::kNone);
    return;
  }

  CounterDirectiveMap& map = state.Style()->AccessCounterDirectives();

  for (const CSSValue* item : *list) {
    const auto& pair = To<CSSValuePair>(*item);
    AtomicString identifier(To<CSSCustomIdentValue>(pair.First()).Value());
    int counter_value = To<CSSPrimitiveValue>(pair.Second()).GetIntValue();
    CounterDirectives& directives =
    map.insert(identifier, CounterDirectives()).stored_value->value;
    directives.AddIncrementValue(counter_value);
  }
  DCHECK(!map.IsEmpty());
}

 // counter-reset



const char* CounterReset::GetPropertyName() const {
  return "counter-reset";
}

const WTF::AtomicString& CounterReset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("counter-reset"));
  return name;
}

const char* CounterReset::GetJSPropertyName() const {
  return "counterReset";
}


void CounterReset::ApplyInitial(StyleResolverState& state) const {
  state.Style()->ClearResetDirectives();
}

void CounterReset::ApplyInherit(StyleResolverState& state) const {
  state.Style()->ClearResetDirectives();
  const CounterDirectiveMap* parent_map = state.ParentStyle()->GetCounterDirectives();
  if (!parent_map)
    return;

  CounterDirectiveMap& map = state.Style()->AccessCounterDirectives();
  DCHECK(!parent_map->IsEmpty());

  typedef CounterDirectiveMap::const_iterator Iterator;
  Iterator end = parent_map->end();
  for (Iterator it = parent_map->begin(); it != end; ++it) {
    CounterDirectives& directives = map.insert(it->key, CounterDirectives()).stored_value->value;
    directives.InheritReset(it->value);
  }
}

void CounterReset::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->ClearResetDirectives();

  const auto* list = DynamicTo<CSSValueList>(value);
  if (!list) {
    DCHECK_EQ(To<CSSIdentifierValue>(value).GetValueID(), CSSValueID::kNone);
    return;
  }

  CounterDirectiveMap& map = state.Style()->AccessCounterDirectives();

  for (const CSSValue* item : *list) {
    const auto& pair = To<CSSValuePair>(*item);
    AtomicString identifier(To<CSSCustomIdentValue>(pair.First()).Value());
    int counter_value = To<CSSPrimitiveValue>(pair.Second()).GetIntValue();
    CounterDirectives& directives =
    map.insert(identifier, CounterDirectives()).stored_value->value;
    directives.SetResetValue(counter_value);
  }
  DCHECK(!map.IsEmpty());
}

 // counter-set



const char* CounterSet::GetPropertyName() const {
  return "counter-set";
}

const WTF::AtomicString& CounterSet::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("counter-set"));
  return name;
}

const char* CounterSet::GetJSPropertyName() const {
  return "counterSet";
}


void CounterSet::ApplyInitial(StyleResolverState& state) const {
  state.Style()->ClearSetDirectives();
}

void CounterSet::ApplyInherit(StyleResolverState& state) const {
  state.Style()->ClearSetDirectives();
  const CounterDirectiveMap* parent_map = state.ParentStyle()->GetCounterDirectives();
  if (!parent_map)
    return;

  CounterDirectiveMap& map = state.Style()->AccessCounterDirectives();
  DCHECK(!parent_map->IsEmpty());

  typedef CounterDirectiveMap::const_iterator Iterator;
  Iterator end = parent_map->end();
  for (Iterator it = parent_map->begin(); it != end; ++it) {
    CounterDirectives& directives = map.insert(it->key, CounterDirectives()).stored_value->value;
    directives.InheritSet(it->value);
  }
}

void CounterSet::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->ClearSetDirectives();

  const auto* list = DynamicTo<CSSValueList>(value);
  if (!list) {
    DCHECK_EQ(To<CSSIdentifierValue>(value).GetValueID(), CSSValueID::kNone);
    return;
  }

  CounterDirectiveMap& map = state.Style()->AccessCounterDirectives();

  for (const CSSValue* item : *list) {
    const auto& pair = To<CSSValuePair>(*item);
    AtomicString identifier(To<CSSCustomIdentValue>(pair.First()).Value());
    int counter_value = To<CSSPrimitiveValue>(pair.Second()).GetIntValue();
    CounterDirectives& directives =
    map.insert(identifier, CounterDirectives()).stored_value->value;
    directives.SetSetValue(counter_value);
  }
  DCHECK(!map.IsEmpty());
}

 // cursor



const char* Cursor::GetPropertyName() const {
  return "cursor";
}

const WTF::AtomicString& Cursor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("cursor"));
  return name;
}

const char* Cursor::GetJSPropertyName() const {
  return "cursor";
}



 // cx



const char* Cx::GetPropertyName() const {
  return "cx";
}

const WTF::AtomicString& Cx::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("cx"));
  return name;
}

const char* Cx::GetJSPropertyName() const {
  return "cx";
}


void Cx::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetCx(SVGComputedStyle::InitialCx());
}
void Cx::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetCx(state.ParentStyle()->SvgStyle().Cx());
}
void Cx::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetCx(StyleBuilderConverter::ConvertLength(state, value));
}

 // cy



const char* Cy::GetPropertyName() const {
  return "cy";
}

const WTF::AtomicString& Cy::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("cy"));
  return name;
}

const char* Cy::GetJSPropertyName() const {
  return "cy";
}


void Cy::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetCy(SVGComputedStyle::InitialCy());
}
void Cy::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetCy(state.ParentStyle()->SvgStyle().Cy());
}
void Cy::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetCy(StyleBuilderConverter::ConvertLength(state, value));
}

 // d



const char* D::GetPropertyName() const {
  return "d";
}

const WTF::AtomicString& D::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("d"));
  return name;
}

const char* D::GetJSPropertyName() const {
  return "d";
}


void D::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetD(SVGComputedStyle::InitialD());
}
void D::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetD(state.ParentStyle()->SvgStyle().D());
}
void D::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetD(StyleBuilderConverter::ConvertPathOrNone(state, value));
}

 // display



const char* Display::GetPropertyName() const {
  return "display";
}

const WTF::AtomicString& Display::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("display"));
  return name;
}

const char* Display::GetJSPropertyName() const {
  return "display";
}



 // dominant-baseline



const char* DominantBaseline::GetPropertyName() const {
  return "dominant-baseline";
}

const WTF::AtomicString& DominantBaseline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("dominant-baseline"));
  return name;
}

const char* DominantBaseline::GetJSPropertyName() const {
  return "dominantBaseline";
}


void DominantBaseline::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetDominantBaseline(SVGComputedStyle::InitialDominantBaseline());
}
void DominantBaseline::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetDominantBaseline(state.ParentStyle()->SvgStyle().DominantBaseline());
}
void DominantBaseline::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetDominantBaseline(To<CSSIdentifierValue>(value).ConvertTo<blink::EDominantBaseline>());
}

 // empty-cells



const char* EmptyCells::GetPropertyName() const {
  return "empty-cells";
}

const WTF::AtomicString& EmptyCells::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("empty-cells"));
  return name;
}

const char* EmptyCells::GetJSPropertyName() const {
  return "emptyCells";
}


void EmptyCells::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetEmptyCells(ComputedStyleInitialValues::InitialEmptyCells());
  state.Style()->SetEmptyCellsIsInherited(false);
}
void EmptyCells::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetEmptyCells(state.ParentStyle()->EmptyCells());
  state.Style()->SetEmptyCellsIsInherited(true);
}
void EmptyCells::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetEmptyCells(To<CSSIdentifierValue>(value).ConvertTo<blink::EEmptyCells>());
  state.Style()->SetEmptyCellsIsInherited(false);
}

 // end

CSSExposure End::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSScrollTimelineEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* End::GetPropertyName() const {
  return "end";
}

const WTF::AtomicString& End::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("end"));
  return name;
}

const char* End::GetJSPropertyName() const {
  return "end";
}



 // fill



const char* Fill::GetPropertyName() const {
  return "fill";
}

const WTF::AtomicString& Fill::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("fill"));
  return name;
}

const char* Fill::GetJSPropertyName() const {
  return "fill";
}
const CSSProperty* Fill::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedFill();
}


void Fill::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFillPaint(SVGComputedStyle::InitialFillPaint());
}
void Fill::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFillPaint(state.ParentStyle()->SvgStyle().FillPaint());
}
void Fill::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetFillPaint(StyleBuilderConverter::ConvertSVGPaint(state, value));
}

 // fill-opacity



const char* FillOpacity::GetPropertyName() const {
  return "fill-opacity";
}

const WTF::AtomicString& FillOpacity::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("fill-opacity"));
  return name;
}

const char* FillOpacity::GetJSPropertyName() const {
  return "fillOpacity";
}


void FillOpacity::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFillOpacity(SVGComputedStyle::InitialFillOpacity());
}
void FillOpacity::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFillOpacity(state.ParentStyle()->SvgStyle().FillOpacity());
}
void FillOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetFillOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

 // fill-rule



const char* FillRule::GetPropertyName() const {
  return "fill-rule";
}

const WTF::AtomicString& FillRule::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("fill-rule"));
  return name;
}

const char* FillRule::GetJSPropertyName() const {
  return "fillRule";
}


void FillRule::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFillRule(SVGComputedStyle::InitialFillRule());
}
void FillRule::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFillRule(state.ParentStyle()->SvgStyle().FillRule());
}
void FillRule::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetFillRule(To<CSSIdentifierValue>(value).ConvertTo<blink::WindRule>());
}

 // filter



const char* Filter::GetPropertyName() const {
  return "filter";
}

const WTF::AtomicString& Filter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("filter"));
  return name;
}

const char* Filter::GetJSPropertyName() const {
  return "filter";
}


void Filter::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetFilter(ComputedStyleInitialValues::InitialFilter());
}
void Filter::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetFilter(state.ParentStyle()->Filter());
}
void Filter::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetFilter(StyleBuilderConverter::ConvertFilterOperations(state, value));
}

 // flex-basis



const char* FlexBasis::GetPropertyName() const {
  return "flex-basis";
}

const WTF::AtomicString& FlexBasis::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-basis"));
  return name;
}

const char* FlexBasis::GetJSPropertyName() const {
  return "flexBasis";
}

bool FlexBasis::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.FlexBasis() == b.FlexBasis();
}

void FlexBasis::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetFlexBasis(ComputedStyleInitialValues::InitialFlexBasis());
}
void FlexBasis::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetFlexBasis(state.ParentStyle()->FlexBasis());
}
void FlexBasis::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetFlexBasis(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // flex-direction



const char* FlexDirection::GetPropertyName() const {
  return "flex-direction";
}

const WTF::AtomicString& FlexDirection::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-direction"));
  return name;
}

const char* FlexDirection::GetJSPropertyName() const {
  return "flexDirection";
}

bool FlexDirection::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.FlexDirection() == b.FlexDirection();
}

void FlexDirection::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetFlexDirection(ComputedStyleInitialValues::InitialFlexDirection());
}
void FlexDirection::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetFlexDirection(state.ParentStyle()->FlexDirection());
}
void FlexDirection::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetFlexDirection(To<CSSIdentifierValue>(value).ConvertTo<blink::EFlexDirection>());
}

 // flex-grow



const char* FlexGrow::GetPropertyName() const {
  return "flex-grow";
}

const WTF::AtomicString& FlexGrow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-grow"));
  return name;
}

const char* FlexGrow::GetJSPropertyName() const {
  return "flexGrow";
}

bool FlexGrow::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.FlexGrow() == b.FlexGrow();
}

void FlexGrow::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetFlexGrow(ComputedStyleInitialValues::InitialFlexGrow());
}
void FlexGrow::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetFlexGrow(state.ParentStyle()->FlexGrow());
}
void FlexGrow::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetFlexGrow(To<CSSPrimitiveValue>(value).ConvertTo<float>());
}

 // flex-shrink



const char* FlexShrink::GetPropertyName() const {
  return "flex-shrink";
}

const WTF::AtomicString& FlexShrink::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-shrink"));
  return name;
}

const char* FlexShrink::GetJSPropertyName() const {
  return "flexShrink";
}

bool FlexShrink::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.FlexShrink() == b.FlexShrink();
}

void FlexShrink::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetFlexShrink(ComputedStyleInitialValues::InitialFlexShrink());
}
void FlexShrink::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetFlexShrink(state.ParentStyle()->FlexShrink());
}
void FlexShrink::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetFlexShrink(To<CSSPrimitiveValue>(value).ConvertTo<float>());
}

 // flex-wrap



const char* FlexWrap::GetPropertyName() const {
  return "flex-wrap";
}

const WTF::AtomicString& FlexWrap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-wrap"));
  return name;
}

const char* FlexWrap::GetJSPropertyName() const {
  return "flexWrap";
}

bool FlexWrap::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.FlexWrap() == b.FlexWrap();
}

void FlexWrap::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetFlexWrap(ComputedStyleInitialValues::InitialFlexWrap());
}
void FlexWrap::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetFlexWrap(state.ParentStyle()->FlexWrap());
}
void FlexWrap::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetFlexWrap(To<CSSIdentifierValue>(value).ConvertTo<blink::EFlexWrap>());
}

 // float



const char* Float::GetPropertyName() const {
  return "float";
}

const WTF::AtomicString& Float::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("float"));
  return name;
}

const char* Float::GetJSPropertyName() const {
  return "float";
}


void Float::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetFloating(ComputedStyleInitialValues::InitialFloating());
}
void Float::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetFloating(state.ParentStyle()->Floating());
}
void Float::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetFloating(To<CSSIdentifierValue>(value).ConvertTo<blink::EFloat>());
}

 // flood-color



const char* FloodColor::GetPropertyName() const {
  return "flood-color";
}

const WTF::AtomicString& FloodColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flood-color"));
  return name;
}

const char* FloodColor::GetJSPropertyName() const {
  return "floodColor";
}


void FloodColor::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFloodColor(SVGComputedStyle::InitialFloodColor());
}
void FloodColor::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFloodColor(state.ParentStyle()->SvgStyle().FloodColor());
}
void FloodColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetFloodColor(StyleBuilderConverter::ConvertStyleColor(state, value));
}

 // flood-opacity



const char* FloodOpacity::GetPropertyName() const {
  return "flood-opacity";
}

const WTF::AtomicString& FloodOpacity::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("flood-opacity"));
  return name;
}

const char* FloodOpacity::GetJSPropertyName() const {
  return "floodOpacity";
}


void FloodOpacity::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFloodOpacity(SVGComputedStyle::InitialFloodOpacity());
}
void FloodOpacity::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetFloodOpacity(state.ParentStyle()->SvgStyle().FloodOpacity());
}
void FloodOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetFloodOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

 // font-display



const char* FontDisplay::GetPropertyName() const {
  return "font-display";
}

const WTF::AtomicString& FontDisplay::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-display"));
  return name;
}

const char* FontDisplay::GetJSPropertyName() const {
  return "fontDisplay";
}



 // grid-auto-columns



const char* GridAutoColumns::GetPropertyName() const {
  return "grid-auto-columns";
}

const WTF::AtomicString& GridAutoColumns::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-auto-columns"));
  return name;
}

const char* GridAutoColumns::GetJSPropertyName() const {
  return "gridAutoColumns";
}


void GridAutoColumns::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridAutoColumns(ComputedStyleInitialValues::InitialGridAutoColumns());
}
void GridAutoColumns::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridAutoColumns(state.ParentStyle()->GridAutoColumns());
}
void GridAutoColumns::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetGridAutoColumns(StyleBuilderConverter::ConvertGridTrackSizeList(state, value));
}

 // grid-auto-flow



const char* GridAutoFlow::GetPropertyName() const {
  return "grid-auto-flow";
}

const WTF::AtomicString& GridAutoFlow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-auto-flow"));
  return name;
}

const char* GridAutoFlow::GetJSPropertyName() const {
  return "gridAutoFlow";
}


void GridAutoFlow::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridAutoFlow(ComputedStyleInitialValues::InitialGridAutoFlow());
}
void GridAutoFlow::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridAutoFlow(state.ParentStyle()->GetGridAutoFlow());
}
void GridAutoFlow::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetGridAutoFlow(StyleBuilderConverter::ConvertGridAutoFlow(state, value));
}

 // grid-auto-rows



const char* GridAutoRows::GetPropertyName() const {
  return "grid-auto-rows";
}

const WTF::AtomicString& GridAutoRows::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-auto-rows"));
  return name;
}

const char* GridAutoRows::GetJSPropertyName() const {
  return "gridAutoRows";
}


void GridAutoRows::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridAutoRows(ComputedStyleInitialValues::InitialGridAutoRows());
}
void GridAutoRows::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridAutoRows(state.ParentStyle()->GridAutoRows());
}
void GridAutoRows::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetGridAutoRows(StyleBuilderConverter::ConvertGridTrackSizeList(state, value));
}

 // grid-column-end



const char* GridColumnEnd::GetPropertyName() const {
  return "grid-column-end";
}

const WTF::AtomicString& GridColumnEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-column-end"));
  return name;
}

const char* GridColumnEnd::GetJSPropertyName() const {
  return "gridColumnEnd";
}


void GridColumnEnd::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridColumnEnd(ComputedStyleInitialValues::InitialGridColumnEnd());
}
void GridColumnEnd::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridColumnEnd(state.ParentStyle()->GridColumnEnd());
}
void GridColumnEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetGridColumnEnd(StyleBuilderConverter::ConvertGridPosition(state, value));
}

 // grid-column-start



const char* GridColumnStart::GetPropertyName() const {
  return "grid-column-start";
}

const WTF::AtomicString& GridColumnStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-column-start"));
  return name;
}

const char* GridColumnStart::GetJSPropertyName() const {
  return "gridColumnStart";
}


void GridColumnStart::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridColumnStart(ComputedStyleInitialValues::InitialGridColumnStart());
}
void GridColumnStart::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridColumnStart(state.ParentStyle()->GridColumnStart());
}
void GridColumnStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetGridColumnStart(StyleBuilderConverter::ConvertGridPosition(state, value));
}

 // grid-row-end



const char* GridRowEnd::GetPropertyName() const {
  return "grid-row-end";
}

const WTF::AtomicString& GridRowEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-row-end"));
  return name;
}

const char* GridRowEnd::GetJSPropertyName() const {
  return "gridRowEnd";
}


void GridRowEnd::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridRowEnd(ComputedStyleInitialValues::InitialGridRowEnd());
}
void GridRowEnd::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridRowEnd(state.ParentStyle()->GridRowEnd());
}
void GridRowEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetGridRowEnd(StyleBuilderConverter::ConvertGridPosition(state, value));
}

 // grid-row-start



const char* GridRowStart::GetPropertyName() const {
  return "grid-row-start";
}

const WTF::AtomicString& GridRowStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-row-start"));
  return name;
}

const char* GridRowStart::GetJSPropertyName() const {
  return "gridRowStart";
}


void GridRowStart::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridRowStart(ComputedStyleInitialValues::InitialGridRowStart());
}
void GridRowStart::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridRowStart(state.ParentStyle()->GridRowStart());
}
void GridRowStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetGridRowStart(StyleBuilderConverter::ConvertGridPosition(state, value));
}

 // grid-template-areas



const char* GridTemplateAreas::GetPropertyName() const {
  return "grid-template-areas";
}

const WTF::AtomicString& GridTemplateAreas::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-template-areas"));
  return name;
}

const char* GridTemplateAreas::GetJSPropertyName() const {
  return "gridTemplateAreas";
}



 // grid-template-columns



const char* GridTemplateColumns::GetPropertyName() const {
  return "grid-template-columns";
}

const WTF::AtomicString& GridTemplateColumns::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-template-columns"));
  return name;
}

const char* GridTemplateColumns::GetJSPropertyName() const {
  return "gridTemplateColumns";
}


void GridTemplateColumns::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridTemplateColumns(ComputedStyleInitialValues::InitialGridTemplateColumns());
  state.Style()->SetNamedGridColumnLines(ComputedStyleInitialValues::InitialNamedGridColumnLines());
  state.Style()->SetOrderedNamedGridColumnLines(ComputedStyleInitialValues::InitialOrderedNamedGridColumnLines());
  state.Style()->SetGridAutoRepeatColumns(ComputedStyleInitialValues::InitialGridAutoRepeatColumns());
  state.Style()->SetGridAutoRepeatColumnsInsertionPoint(ComputedStyleInitialValues::InitialGridAutoRepeatColumnsInsertionPoint());
  state.Style()->SetAutoRepeatNamedGridColumnLines(ComputedStyleInitialValues::InitialNamedGridColumnLines());
  state.Style()->SetAutoRepeatOrderedNamedGridColumnLines(ComputedStyleInitialValues::InitialOrderedNamedGridColumnLines());
  state.Style()->SetGridAutoRepeatColumnsType(ComputedStyleInitialValues::InitialGridAutoRepeatColumnsType());
}

void GridTemplateColumns::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridTemplateColumns(state.ParentStyle()->GridTemplateColumns());
  state.Style()->SetNamedGridColumnLines(state.ParentStyle()->NamedGridColumnLines());
  state.Style()->SetOrderedNamedGridColumnLines(state.ParentStyle()->OrderedNamedGridColumnLines());
  state.Style()->SetGridAutoRepeatColumns(state.ParentStyle()->GridAutoRepeatColumns());
  state.Style()->SetGridAutoRepeatColumnsInsertionPoint(state.ParentStyle()->GridAutoRepeatColumnsInsertionPoint());
  state.Style()->SetAutoRepeatNamedGridColumnLines(state.ParentStyle()->AutoRepeatNamedGridColumnLines());
  state.Style()->SetAutoRepeatOrderedNamedGridColumnLines(state.ParentStyle()->AutoRepeatOrderedNamedGridColumnLines());
  state.Style()->SetGridAutoRepeatColumnsType(state.ParentStyle()->GridAutoRepeatColumnsType());
}

void GridTemplateColumns::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  Vector<GridTrackSize> track_sizes;
  Vector<GridTrackSize> auto_repeat_track_sizes;
  NamedGridLinesMap named_grid_lines;
  OrderedNamedGridLines ordered_named_grid_lines;
  NamedGridLinesMap auto_repeat_named_grid_lines;
  OrderedNamedGridLines auto_repeat_ordered_named_grid_lines;
  AutoRepeatType autoRepeatType = ComputedStyleInitialValues::InitialGridAutoRepeatType();
  size_t auto_repeat_insertion_point =
      ComputedStyleInitialValues::InitialGridAutoRepeatInsertionPoint();
  StyleBuilderConverter::ConvertGridTrackList(
      value, track_sizes, named_grid_lines, ordered_named_grid_lines,
      auto_repeat_track_sizes, auto_repeat_named_grid_lines,
      auto_repeat_ordered_named_grid_lines, auto_repeat_insertion_point,
      autoRepeatType, state);
  const NamedGridAreaMap& named_grid_areas = state.Style()->NamedGridArea();
  if (!named_grid_areas.IsEmpty()) {
    StyleBuilderConverter::CreateImplicitNamedGridLinesFromGridArea(
        named_grid_areas, named_grid_lines, kForColumns);
  }
  state.Style()->SetGridTemplateColumns(track_sizes);
  state.Style()->SetNamedGridColumnLines(named_grid_lines);
  state.Style()->SetOrderedNamedGridColumnLines(ordered_named_grid_lines);
  state.Style()->SetGridAutoRepeatColumns(auto_repeat_track_sizes);
  state.Style()->SetGridAutoRepeatColumnsInsertionPoint(
      auto_repeat_insertion_point);
  state.Style()->SetAutoRepeatNamedGridColumnLines(auto_repeat_named_grid_lines);
  state.Style()->SetAutoRepeatOrderedNamedGridColumnLines(
      auto_repeat_ordered_named_grid_lines);
  state.Style()->SetGridAutoRepeatColumnsType(autoRepeatType);
}

 // grid-template-rows



const char* GridTemplateRows::GetPropertyName() const {
  return "grid-template-rows";
}

const WTF::AtomicString& GridTemplateRows::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-template-rows"));
  return name;
}

const char* GridTemplateRows::GetJSPropertyName() const {
  return "gridTemplateRows";
}


void GridTemplateRows::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetGridTemplateRows(ComputedStyleInitialValues::InitialGridTemplateRows());
  state.Style()->SetNamedGridRowLines(ComputedStyleInitialValues::InitialNamedGridRowLines());
  state.Style()->SetOrderedNamedGridRowLines(ComputedStyleInitialValues::InitialOrderedNamedGridRowLines());
  state.Style()->SetGridAutoRepeatRows(ComputedStyleInitialValues::InitialGridAutoRepeatRows());
  state.Style()->SetGridAutoRepeatRowsInsertionPoint(ComputedStyleInitialValues::InitialGridAutoRepeatRowsInsertionPoint());
  state.Style()->SetAutoRepeatNamedGridRowLines(ComputedStyleInitialValues::InitialNamedGridRowLines());
  state.Style()->SetAutoRepeatOrderedNamedGridRowLines(ComputedStyleInitialValues::InitialOrderedNamedGridRowLines());
  state.Style()->SetGridAutoRepeatRowsType(ComputedStyleInitialValues::InitialGridAutoRepeatRowsType());
}

void GridTemplateRows::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetGridTemplateRows(state.ParentStyle()->GridTemplateRows());
  state.Style()->SetNamedGridRowLines(state.ParentStyle()->NamedGridRowLines());
  state.Style()->SetOrderedNamedGridRowLines(state.ParentStyle()->OrderedNamedGridRowLines());
  state.Style()->SetGridAutoRepeatRows(state.ParentStyle()->GridAutoRepeatRows());
  state.Style()->SetGridAutoRepeatRowsInsertionPoint(state.ParentStyle()->GridAutoRepeatRowsInsertionPoint());
  state.Style()->SetAutoRepeatNamedGridRowLines(state.ParentStyle()->AutoRepeatNamedGridRowLines());
  state.Style()->SetAutoRepeatOrderedNamedGridRowLines(state.ParentStyle()->AutoRepeatOrderedNamedGridRowLines());
  state.Style()->SetGridAutoRepeatRowsType(state.ParentStyle()->GridAutoRepeatRowsType());
}

void GridTemplateRows::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  Vector<GridTrackSize> track_sizes;
  Vector<GridTrackSize> auto_repeat_track_sizes;
  NamedGridLinesMap named_grid_lines;
  OrderedNamedGridLines ordered_named_grid_lines;
  NamedGridLinesMap auto_repeat_named_grid_lines;
  OrderedNamedGridLines auto_repeat_ordered_named_grid_lines;
  AutoRepeatType autoRepeatType = ComputedStyleInitialValues::InitialGridAutoRepeatType();
  size_t auto_repeat_insertion_point =
      ComputedStyleInitialValues::InitialGridAutoRepeatInsertionPoint();
  StyleBuilderConverter::ConvertGridTrackList(
      value, track_sizes, named_grid_lines, ordered_named_grid_lines,
      auto_repeat_track_sizes, auto_repeat_named_grid_lines,
      auto_repeat_ordered_named_grid_lines, auto_repeat_insertion_point,
      autoRepeatType, state);
  const NamedGridAreaMap& named_grid_areas = state.Style()->NamedGridArea();
  if (!named_grid_areas.IsEmpty()) {
    StyleBuilderConverter::CreateImplicitNamedGridLinesFromGridArea(
        named_grid_areas, named_grid_lines, kForRows);
  }
  state.Style()->SetGridTemplateRows(track_sizes);
  state.Style()->SetNamedGridRowLines(named_grid_lines);
  state.Style()->SetOrderedNamedGridRowLines(ordered_named_grid_lines);
  state.Style()->SetGridAutoRepeatRows(auto_repeat_track_sizes);
  state.Style()->SetGridAutoRepeatRowsInsertionPoint(
      auto_repeat_insertion_point);
  state.Style()->SetAutoRepeatNamedGridRowLines(auto_repeat_named_grid_lines);
  state.Style()->SetAutoRepeatOrderedNamedGridRowLines(
      auto_repeat_ordered_named_grid_lines);
  state.Style()->SetGridAutoRepeatRowsType(autoRepeatType);
}

 // height



const char* Height::GetPropertyName() const {
  return "height";
}

const WTF::AtomicString& Height::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("height"));
  return name;
}

const char* Height::GetJSPropertyName() const {
  return "height";
}

bool Height::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.Height() == b.Height();
}

void Height::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHeight(ComputedStyleInitialValues::InitialHeight());
}
void Height::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetHeight(state.ParentStyle()->Height());
}
void Height::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetHeight(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

 // hyphens



const char* Hyphens::GetPropertyName() const {
  return "hyphens";
}

const WTF::AtomicString& Hyphens::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("hyphens"));
  return name;
}

const char* Hyphens::GetJSPropertyName() const {
  return "hyphens";
}


void Hyphens::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHyphens(ComputedStyleInitialValues::InitialHyphens());
}
void Hyphens::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetHyphens(state.ParentStyle()->GetHyphens());
}
void Hyphens::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetHyphens(To<CSSIdentifierValue>(value).ConvertTo<blink::Hyphens>());
}

 // image-orientation

CSSExposure ImageOrientation::Exposure() const {
  if (!RuntimeEnabledFeatures::ImageOrientationEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* ImageOrientation::GetPropertyName() const {
  return "image-orientation";
}

const WTF::AtomicString& ImageOrientation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("image-orientation"));
  return name;
}

const char* ImageOrientation::GetJSPropertyName() const {
  return "imageOrientation";
}


void ImageOrientation::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetRespectImageOrientation(ComputedStyleInitialValues::InitialRespectImageOrientation());
}
void ImageOrientation::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetRespectImageOrientation(state.ParentStyle()->RespectImageOrientation());
}
void ImageOrientation::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetRespectImageOrientation(StyleBuilderConverter::ConvertImageOrientation(state, value));
}

 // image-rendering



const char* ImageRendering::GetPropertyName() const {
  return "image-rendering";
}

const WTF::AtomicString& ImageRendering::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("image-rendering"));
  return name;
}

const char* ImageRendering::GetJSPropertyName() const {
  return "imageRendering";
}


void ImageRendering::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetImageRendering(ComputedStyleInitialValues::InitialImageRendering());
}
void ImageRendering::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetImageRendering(state.ParentStyle()->ImageRendering());
}
void ImageRendering::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetImageRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EImageRendering>());
}

 // inherits

CSSExposure Inherits::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSVariables2AtPropertyEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Inherits::GetPropertyName() const {
  return "inherits";
}

const WTF::AtomicString& Inherits::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inherits"));
  return name;
}

const char* Inherits::GetJSPropertyName() const {
  return "inherits";
}



 // initial-value

CSSExposure InitialValue::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSVariables2AtPropertyEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* InitialValue::GetPropertyName() const {
  return "initial-value";
}

const WTF::AtomicString& InitialValue::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("initial-value"));
  return name;
}

const char* InitialValue::GetJSPropertyName() const {
  return "initialValue";
}



 // inline-size



const char* InlineSize::GetPropertyName() const {
  return "inline-size";
}

const WTF::AtomicString& InlineSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inline-size"));
  return name;
}

const char* InlineSize::GetJSPropertyName() const {
  return "inlineSize";
}

const CSSProperty* InlineSize::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InlineSize::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInline(direction, writing_mode,
      CSSDirectionAwareResolver::SizeGroup());
}

void InlineSize::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InlineSize::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InlineSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // inset-block-end

CSSExposure InsetBlockEnd::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* InsetBlockEnd::GetPropertyName() const {
  return "inset-block-end";
}

const WTF::AtomicString& InsetBlockEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-block-end"));
  return name;
}

const char* InsetBlockEnd::GetJSPropertyName() const {
  return "insetBlockEnd";
}

const CSSProperty* InsetBlockEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InsetBlockEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::InsetGroup());
}

void InsetBlockEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InsetBlockEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InsetBlockEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // inset-block-start

CSSExposure InsetBlockStart::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* InsetBlockStart::GetPropertyName() const {
  return "inset-block-start";
}

const WTF::AtomicString& InsetBlockStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-block-start"));
  return name;
}

const char* InsetBlockStart::GetJSPropertyName() const {
  return "insetBlockStart";
}

const CSSProperty* InsetBlockStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InsetBlockStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::InsetGroup());
}

void InsetBlockStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InsetBlockStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InsetBlockStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // inset-inline-end

CSSExposure InsetInlineEnd::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* InsetInlineEnd::GetPropertyName() const {
  return "inset-inline-end";
}

const WTF::AtomicString& InsetInlineEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-inline-end"));
  return name;
}

const char* InsetInlineEnd::GetJSPropertyName() const {
  return "insetInlineEnd";
}

const CSSProperty* InsetInlineEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InsetInlineEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::InsetGroup());
}

void InsetInlineEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InsetInlineEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InsetInlineEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // inset-inline-start

CSSExposure InsetInlineStart::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* InsetInlineStart::GetPropertyName() const {
  return "inset-inline-start";
}

const WTF::AtomicString& InsetInlineStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-inline-start"));
  return name;
}

const char* InsetInlineStart::GetJSPropertyName() const {
  return "insetInlineStart";
}

const CSSProperty* InsetInlineStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InsetInlineStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::InsetGroup());
}

void InsetInlineStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InsetInlineStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InsetInlineStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // -internal-empty-line-height

CSSExposure InternalEmptyLineHeight::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalEmptyLineHeight::GetPropertyName() const {
  return "-internal-empty-line-height";
}

const WTF::AtomicString& InternalEmptyLineHeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-empty-line-height"));
  return name;
}

const char* InternalEmptyLineHeight::GetJSPropertyName() const {
  return "internalEmptyLineHeight";
}


void InternalEmptyLineHeight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHasLineIfEmpty(ComputedStyleInitialValues::InitialHasLineIfEmpty());
}
void InternalEmptyLineHeight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetHasLineIfEmpty(state.ParentStyle()->HasLineIfEmpty());
}
void InternalEmptyLineHeight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetHasLineIfEmpty(StyleBuilderConverter::ConvertInternalEmptyLineHeight(state, value));
}

 // -internal-forced-background-color-rgb

CSSExposure InternalForcedBackgroundColorRgb::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalForcedBackgroundColorRgb::GetPropertyName() const {
  return "-internal-forced-background-color-rgb";
}

const WTF::AtomicString& InternalForcedBackgroundColorRgb::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-forced-background-color-rgb"));
  return name;
}

const char* InternalForcedBackgroundColorRgb::GetJSPropertyName() const {
  return "internalForcedBackgroundColorRgb";
}


void InternalForcedBackgroundColorRgb::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetInternalForcedBackgroundColorRgb(ComputedStyleInitialValues::InitialInternalForcedBackgroundColorRgb());
}
void InternalForcedBackgroundColorRgb::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetInternalForcedBackgroundColorRgb(state.ParentStyle()->InternalForcedBackgroundColorRgb());
}
void InternalForcedBackgroundColorRgb::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalForcedBackgroundColorRgb(StyleBuilderConverter::ConvertCSSValueID(state, value));
}

 // -internal-visited-background-color

CSSExposure InternalVisitedBackgroundColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBackgroundColor::GetPropertyName() const {
  return "-internal-visited-background-color";
}

const WTF::AtomicString& InternalVisitedBackgroundColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-background-color"));
  return name;
}

const char* InternalVisitedBackgroundColor::GetJSPropertyName() const {
  return "internalVisitedBackgroundColor";
}
const CSSProperty* InternalVisitedBackgroundColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBackgroundColor();
}


void InternalVisitedBackgroundColor::ApplyInitial(StyleResolverState& state) const {
  auto color = ComputedStyleInitialValues::InitialBackgroundColor();
  state.Style()->SetInternalVisitedBackgroundColor(color);
}

void InternalVisitedBackgroundColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BackgroundColor();
  state.Style()->SetInternalVisitedBackgroundColor(color);
}

void InternalVisitedBackgroundColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedBackgroundColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-border-block-end-color

CSSExposure InternalVisitedBorderBlockEndColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderBlockEndColor::GetPropertyName() const {
  return "-internal-visited-border-block-end-color";
}

const WTF::AtomicString& InternalVisitedBorderBlockEndColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-block-end-color"));
  return name;
}

const char* InternalVisitedBorderBlockEndColor::GetJSPropertyName() const {
  return "internalVisitedBorderBlockEndColor";
}
const CSSProperty* InternalVisitedBorderBlockEndColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderBlockEndColor();
}

const CSSProperty* InternalVisitedBorderBlockEndColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InternalVisitedBorderBlockEndColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::VisitedBorderColorGroup());
}

void InternalVisitedBorderBlockEndColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InternalVisitedBorderBlockEndColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InternalVisitedBorderBlockEndColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // -internal-visited-border-block-start-color

CSSExposure InternalVisitedBorderBlockStartColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderBlockStartColor::GetPropertyName() const {
  return "-internal-visited-border-block-start-color";
}

const WTF::AtomicString& InternalVisitedBorderBlockStartColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-block-start-color"));
  return name;
}

const char* InternalVisitedBorderBlockStartColor::GetJSPropertyName() const {
  return "internalVisitedBorderBlockStartColor";
}
const CSSProperty* InternalVisitedBorderBlockStartColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderBlockStartColor();
}

const CSSProperty* InternalVisitedBorderBlockStartColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InternalVisitedBorderBlockStartColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::VisitedBorderColorGroup());
}

void InternalVisitedBorderBlockStartColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InternalVisitedBorderBlockStartColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InternalVisitedBorderBlockStartColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // -internal-visited-border-bottom-color

CSSExposure InternalVisitedBorderBottomColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderBottomColor::GetPropertyName() const {
  return "-internal-visited-border-bottom-color";
}

const WTF::AtomicString& InternalVisitedBorderBottomColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-bottom-color"));
  return name;
}

const char* InternalVisitedBorderBottomColor::GetJSPropertyName() const {
  return "internalVisitedBorderBottomColor";
}
const CSSProperty* InternalVisitedBorderBottomColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderBottomColor();
}


void InternalVisitedBorderBottomColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedBorderBottomColor(color);
}

void InternalVisitedBorderBottomColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderBottomColor();
  state.Style()->SetInternalVisitedBorderBottomColor(color);
}

void InternalVisitedBorderBottomColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedBorderBottomColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-border-inline-end-color

CSSExposure InternalVisitedBorderInlineEndColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderInlineEndColor::GetPropertyName() const {
  return "-internal-visited-border-inline-end-color";
}

const WTF::AtomicString& InternalVisitedBorderInlineEndColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-inline-end-color"));
  return name;
}

const char* InternalVisitedBorderInlineEndColor::GetJSPropertyName() const {
  return "internalVisitedBorderInlineEndColor";
}
const CSSProperty* InternalVisitedBorderInlineEndColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderInlineEndColor();
}

const CSSProperty* InternalVisitedBorderInlineEndColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InternalVisitedBorderInlineEndColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::VisitedBorderColorGroup());
}

void InternalVisitedBorderInlineEndColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InternalVisitedBorderInlineEndColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InternalVisitedBorderInlineEndColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // -internal-visited-border-inline-start-color

CSSExposure InternalVisitedBorderInlineStartColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderInlineStartColor::GetPropertyName() const {
  return "-internal-visited-border-inline-start-color";
}

const WTF::AtomicString& InternalVisitedBorderInlineStartColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-inline-start-color"));
  return name;
}

const char* InternalVisitedBorderInlineStartColor::GetJSPropertyName() const {
  return "internalVisitedBorderInlineStartColor";
}
const CSSProperty* InternalVisitedBorderInlineStartColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderInlineStartColor();
}

const CSSProperty* InternalVisitedBorderInlineStartColor::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& InternalVisitedBorderInlineStartColor::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::VisitedBorderColorGroup());
}

void InternalVisitedBorderInlineStartColor::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void InternalVisitedBorderInlineStartColor::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void InternalVisitedBorderInlineStartColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // -internal-visited-border-left-color

CSSExposure InternalVisitedBorderLeftColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderLeftColor::GetPropertyName() const {
  return "-internal-visited-border-left-color";
}

const WTF::AtomicString& InternalVisitedBorderLeftColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-left-color"));
  return name;
}

const char* InternalVisitedBorderLeftColor::GetJSPropertyName() const {
  return "internalVisitedBorderLeftColor";
}
const CSSProperty* InternalVisitedBorderLeftColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderLeftColor();
}


void InternalVisitedBorderLeftColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedBorderLeftColor(color);
}

void InternalVisitedBorderLeftColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderLeftColor();
  state.Style()->SetInternalVisitedBorderLeftColor(color);
}

void InternalVisitedBorderLeftColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedBorderLeftColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-border-right-color

CSSExposure InternalVisitedBorderRightColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderRightColor::GetPropertyName() const {
  return "-internal-visited-border-right-color";
}

const WTF::AtomicString& InternalVisitedBorderRightColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-right-color"));
  return name;
}

const char* InternalVisitedBorderRightColor::GetJSPropertyName() const {
  return "internalVisitedBorderRightColor";
}
const CSSProperty* InternalVisitedBorderRightColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderRightColor();
}


void InternalVisitedBorderRightColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedBorderRightColor(color);
}

void InternalVisitedBorderRightColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderRightColor();
  state.Style()->SetInternalVisitedBorderRightColor(color);
}

void InternalVisitedBorderRightColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedBorderRightColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-border-top-color

CSSExposure InternalVisitedBorderTopColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedBorderTopColor::GetPropertyName() const {
  return "-internal-visited-border-top-color";
}

const WTF::AtomicString& InternalVisitedBorderTopColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-top-color"));
  return name;
}

const char* InternalVisitedBorderTopColor::GetJSPropertyName() const {
  return "internalVisitedBorderTopColor";
}
const CSSProperty* InternalVisitedBorderTopColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyBorderTopColor();
}


void InternalVisitedBorderTopColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedBorderTopColor(color);
}

void InternalVisitedBorderTopColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->BorderTopColor();
  state.Style()->SetInternalVisitedBorderTopColor(color);
}

void InternalVisitedBorderTopColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedBorderTopColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-caret-color

CSSExposure InternalVisitedCaretColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedCaretColor::GetPropertyName() const {
  return "-internal-visited-caret-color";
}

const WTF::AtomicString& InternalVisitedCaretColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-caret-color"));
  return name;
}

const char* InternalVisitedCaretColor::GetJSPropertyName() const {
  return "internalVisitedCaretColor";
}
const CSSProperty* InternalVisitedCaretColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyCaretColor();
}


void InternalVisitedCaretColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleAutoColor::AutoColor();
  state.Style()->SetInternalVisitedCaretColor(color);
}

void InternalVisitedCaretColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->CaretColor();
  state.Style()->SetInternalVisitedCaretColor(color);
}

void InternalVisitedCaretColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedCaretColor(StyleBuilderConverter::ConvertStyleAutoColor(state, value, true));
}

 // -internal-visited-column-rule-color

CSSExposure InternalVisitedColumnRuleColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedColumnRuleColor::GetPropertyName() const {
  return "-internal-visited-column-rule-color";
}

const WTF::AtomicString& InternalVisitedColumnRuleColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-column-rule-color"));
  return name;
}

const char* InternalVisitedColumnRuleColor::GetJSPropertyName() const {
  return "internalVisitedColumnRuleColor";
}
const CSSProperty* InternalVisitedColumnRuleColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyColumnRuleColor();
}


void InternalVisitedColumnRuleColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedColumnRuleColor(color);
}

void InternalVisitedColumnRuleColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->ColumnRuleColor();
  state.Style()->SetInternalVisitedColumnRuleColor(color);
}

void InternalVisitedColumnRuleColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedColumnRuleColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-fill

CSSExposure InternalVisitedFill::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedFill::GetPropertyName() const {
  return "-internal-visited-fill";
}

const WTF::AtomicString& InternalVisitedFill::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-fill"));
  return name;
}

const char* InternalVisitedFill::GetJSPropertyName() const {
  return "internalVisitedFill";
}
const CSSProperty* InternalVisitedFill::GetUnvisitedProperty() const {
  return &GetCSSPropertyFill();
}


void InternalVisitedFill::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetInternalVisitedFillPaint(SVGComputedStyle::InitialFillPaint());
}
void InternalVisitedFill::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetInternalVisitedFillPaint(state.ParentStyle()->SvgStyle().FillPaint());
}
void InternalVisitedFill::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetInternalVisitedFillPaint(StyleBuilderConverter::ConvertSVGPaint(state, value));
}

 // -internal-visited-outline-color

CSSExposure InternalVisitedOutlineColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedOutlineColor::GetPropertyName() const {
  return "-internal-visited-outline-color";
}

const WTF::AtomicString& InternalVisitedOutlineColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-outline-color"));
  return name;
}

const char* InternalVisitedOutlineColor::GetJSPropertyName() const {
  return "internalVisitedOutlineColor";
}
const CSSProperty* InternalVisitedOutlineColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyOutlineColor();
}


void InternalVisitedOutlineColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedOutlineColor(color);
}

void InternalVisitedOutlineColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->OutlineColor();
  state.Style()->SetInternalVisitedOutlineColor(color);
}

void InternalVisitedOutlineColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedOutlineColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-stroke

CSSExposure InternalVisitedStroke::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedStroke::GetPropertyName() const {
  return "-internal-visited-stroke";
}

const WTF::AtomicString& InternalVisitedStroke::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-stroke"));
  return name;
}

const char* InternalVisitedStroke::GetJSPropertyName() const {
  return "internalVisitedStroke";
}
const CSSProperty* InternalVisitedStroke::GetUnvisitedProperty() const {
  return &GetCSSPropertyStroke();
}


void InternalVisitedStroke::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetInternalVisitedStrokePaint(SVGComputedStyle::InitialStrokePaint());
}
void InternalVisitedStroke::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetInternalVisitedStrokePaint(state.ParentStyle()->SvgStyle().StrokePaint());
}
void InternalVisitedStroke::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetInternalVisitedStrokePaint(StyleBuilderConverter::ConvertSVGPaint(state, value));
}

 // -internal-visited-text-decoration-color

CSSExposure InternalVisitedTextDecorationColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedTextDecorationColor::GetPropertyName() const {
  return "-internal-visited-text-decoration-color";
}

const WTF::AtomicString& InternalVisitedTextDecorationColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-decoration-color"));
  return name;
}

const char* InternalVisitedTextDecorationColor::GetJSPropertyName() const {
  return "internalVisitedTextDecorationColor";
}
const CSSProperty* InternalVisitedTextDecorationColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyTextDecorationColor();
}


void InternalVisitedTextDecorationColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedTextDecorationColor(color);
}

void InternalVisitedTextDecorationColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextDecorationColor();
  state.Style()->SetInternalVisitedTextDecorationColor(color);
}

void InternalVisitedTextDecorationColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedTextDecorationColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-text-emphasis-color

CSSExposure InternalVisitedTextEmphasisColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedTextEmphasisColor::GetPropertyName() const {
  return "-internal-visited-text-emphasis-color";
}

const WTF::AtomicString& InternalVisitedTextEmphasisColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-emphasis-color"));
  return name;
}

const char* InternalVisitedTextEmphasisColor::GetJSPropertyName() const {
  return "internalVisitedTextEmphasisColor";
}
const CSSProperty* InternalVisitedTextEmphasisColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyWebkitTextEmphasisColor();
}


void InternalVisitedTextEmphasisColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedTextEmphasisColor(color);
}

void InternalVisitedTextEmphasisColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextEmphasisColor();
  state.Style()->SetInternalVisitedTextEmphasisColor(color);
}

void InternalVisitedTextEmphasisColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedTextEmphasisColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-text-fill-color

CSSExposure InternalVisitedTextFillColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedTextFillColor::GetPropertyName() const {
  return "-internal-visited-text-fill-color";
}

const WTF::AtomicString& InternalVisitedTextFillColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-fill-color"));
  return name;
}

const char* InternalVisitedTextFillColor::GetJSPropertyName() const {
  return "internalVisitedTextFillColor";
}
const CSSProperty* InternalVisitedTextFillColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyWebkitTextFillColor();
}


void InternalVisitedTextFillColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedTextFillColor(color);
}

void InternalVisitedTextFillColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextFillColor();
  state.Style()->SetInternalVisitedTextFillColor(color);
}

void InternalVisitedTextFillColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedTextFillColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // -internal-visited-text-stroke-color

CSSExposure InternalVisitedTextStrokeColor::Exposure() const {
  return CSSExposure::kUA;
}


const char* InternalVisitedTextStrokeColor::GetPropertyName() const {
  return "-internal-visited-text-stroke-color";
}

const WTF::AtomicString& InternalVisitedTextStrokeColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-stroke-color"));
  return name;
}

const char* InternalVisitedTextStrokeColor::GetJSPropertyName() const {
  return "internalVisitedTextStrokeColor";
}
const CSSProperty* InternalVisitedTextStrokeColor::GetUnvisitedProperty() const {
  return &GetCSSPropertyWebkitTextStrokeColor();
}


void InternalVisitedTextStrokeColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetInternalVisitedTextStrokeColor(color);
}

void InternalVisitedTextStrokeColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextStrokeColor();
  state.Style()->SetInternalVisitedTextStrokeColor(color);
}

void InternalVisitedTextStrokeColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetInternalVisitedTextStrokeColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

 // isolation



const char* Isolation::GetPropertyName() const {
  return "isolation";
}

const WTF::AtomicString& Isolation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("isolation"));
  return name;
}

const char* Isolation::GetJSPropertyName() const {
  return "isolation";
}


void Isolation::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetIsolation(ComputedStyleInitialValues::InitialIsolation());
}
void Isolation::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetIsolation(state.ParentStyle()->Isolation());
}
void Isolation::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetIsolation(To<CSSIdentifierValue>(value).ConvertTo<blink::EIsolation>());
}

 // justify-content



const char* JustifyContent::GetPropertyName() const {
  return "justify-content";
}

const WTF::AtomicString& JustifyContent::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("justify-content"));
  return name;
}

const char* JustifyContent::GetJSPropertyName() const {
  return "justifyContent";
}

bool JustifyContent::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.JustifyContent() == b.JustifyContent();
}

void JustifyContent::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetJustifyContent(ComputedStyleInitialValues::InitialJustifyContent());
}
void JustifyContent::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetJustifyContent(state.ParentStyle()->JustifyContent());
}
void JustifyContent::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetJustifyContent(StyleBuilderConverter::ConvertContentAlignmentData(state, value));
}

 // justify-items



const char* JustifyItems::GetPropertyName() const {
  return "justify-items";
}

const WTF::AtomicString& JustifyItems::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("justify-items"));
  return name;
}

const char* JustifyItems::GetJSPropertyName() const {
  return "justifyItems";
}

bool JustifyItems::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.JustifyItems() == b.JustifyItems();
}

void JustifyItems::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetJustifyItems(ComputedStyleInitialValues::InitialJustifyItems());
}
void JustifyItems::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetJustifyItems(state.ParentStyle()->JustifyItems());
}
void JustifyItems::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetJustifyItems(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

 // justify-self



const char* JustifySelf::GetPropertyName() const {
  return "justify-self";
}

const WTF::AtomicString& JustifySelf::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("justify-self"));
  return name;
}

const char* JustifySelf::GetJSPropertyName() const {
  return "justifySelf";
}

bool JustifySelf::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.JustifySelf() == b.JustifySelf();
}

void JustifySelf::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetJustifySelf(ComputedStyleInitialValues::InitialJustifySelf());
}
void JustifySelf::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetJustifySelf(state.ParentStyle()->JustifySelf());
}
void JustifySelf::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetJustifySelf(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

 // left



const char* Left::GetPropertyName() const {
  return "left";
}

const WTF::AtomicString& Left::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("left"));
  return name;
}

const char* Left::GetJSPropertyName() const {
  return "left";
}

bool Left::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.Left() == b.Left();
}

void Left::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetLeft(ComputedStyleInitialValues::InitialLeft());
}
void Left::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetLeft(state.ParentStyle()->Left());
}
void Left::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetLeft(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // letter-spacing



const char* LetterSpacing::GetPropertyName() const {
  return "letter-spacing";
}

const WTF::AtomicString& LetterSpacing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("letter-spacing"));
  return name;
}

const char* LetterSpacing::GetJSPropertyName() const {
  return "letterSpacing";
}


void LetterSpacing::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetLetterSpacing(ComputedStyleInitialValues::InitialLetterSpacing());
}
void LetterSpacing::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetLetterSpacing(state.ParentStyle()->LetterSpacing());
}
void LetterSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetLetterSpacing(StyleBuilderConverter::ConvertSpacing(state, value));
}

 // lighting-color



const char* LightingColor::GetPropertyName() const {
  return "lighting-color";
}

const WTF::AtomicString& LightingColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("lighting-color"));
  return name;
}

const char* LightingColor::GetJSPropertyName() const {
  return "lightingColor";
}


void LightingColor::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetLightingColor(SVGComputedStyle::InitialLightingColor());
}
void LightingColor::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetLightingColor(state.ParentStyle()->SvgStyle().LightingColor());
}
void LightingColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetLightingColor(StyleBuilderConverter::ConvertStyleColor(state, value));
}

 // line-break



const char* LineBreak::GetPropertyName() const {
  return "line-break";
}

const WTF::AtomicString& LineBreak::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("line-break"));
  return name;
}

const char* LineBreak::GetJSPropertyName() const {
  return "lineBreak";
}


void LineBreak::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetLineBreak(ComputedStyleInitialValues::InitialLineBreak());
}
void LineBreak::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetLineBreak(state.ParentStyle()->GetLineBreak());
}
void LineBreak::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetLineBreak(To<CSSIdentifierValue>(value).ConvertTo<blink::LineBreak>());
}

 // line-height



const char* LineHeight::GetPropertyName() const {
  return "line-height";
}

const WTF::AtomicString& LineHeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("line-height"));
  return name;
}

const char* LineHeight::GetJSPropertyName() const {
  return "lineHeight";
}


void LineHeight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetLineHeight(ComputedStyleInitialValues::InitialLineHeight());
}
void LineHeight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetLineHeight(state.ParentStyle()->SpecifiedLineHeight());
}
void LineHeight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetLineHeight(StyleBuilderConverter::ConvertLineHeight(state, value));
}

 // line-height-step

CSSExposure LineHeightStep::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSSnapSizeEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* LineHeightStep::GetPropertyName() const {
  return "line-height-step";
}

const WTF::AtomicString& LineHeightStep::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("line-height-step"));
  return name;
}

const char* LineHeightStep::GetJSPropertyName() const {
  return "lineHeightStep";
}


void LineHeightStep::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetLineHeightStep(ComputedStyleInitialValues::InitialLineHeightStep());
}
void LineHeightStep::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetLineHeightStep(state.ParentStyle()->LineHeightStep());
}
void LineHeightStep::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetLineHeightStep(StyleBuilderConverter::ConvertComputedLength<uint8_t>(state, value));
}

 // list-style-image



const char* ListStyleImage::GetPropertyName() const {
  return "list-style-image";
}

const WTF::AtomicString& ListStyleImage::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("list-style-image"));
  return name;
}

const char* ListStyleImage::GetJSPropertyName() const {
  return "listStyleImage";
}


void ListStyleImage::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetListStyleImage(ComputedStyleInitialValues::InitialListStyleImage());
}
void ListStyleImage::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetListStyleImage(state.ParentStyle()->ListStyleImage());
}

 // list-style-position



const char* ListStylePosition::GetPropertyName() const {
  return "list-style-position";
}

const WTF::AtomicString& ListStylePosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("list-style-position"));
  return name;
}

const char* ListStylePosition::GetJSPropertyName() const {
  return "listStylePosition";
}


void ListStylePosition::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetListStylePosition(ComputedStyleInitialValues::InitialListStylePosition());
  state.Style()->SetListStylePositionIsInherited(false);
}
void ListStylePosition::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetListStylePosition(state.ParentStyle()->ListStylePosition());
  state.Style()->SetListStylePositionIsInherited(true);
}
void ListStylePosition::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetListStylePosition(To<CSSIdentifierValue>(value).ConvertTo<blink::EListStylePosition>());
  state.Style()->SetListStylePositionIsInherited(false);
}

 // list-style-type



const char* ListStyleType::GetPropertyName() const {
  return "list-style-type";
}

const WTF::AtomicString& ListStyleType::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("list-style-type"));
  return name;
}

const char* ListStyleType::GetJSPropertyName() const {
  return "listStyleType";
}



 // margin-block-end



const char* MarginBlockEnd::GetPropertyName() const {
  return "margin-block-end";
}

const WTF::AtomicString& MarginBlockEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-block-end"));
  return name;
}

const char* MarginBlockEnd::GetJSPropertyName() const {
  return "marginBlockEnd";
}

const CSSProperty* MarginBlockEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MarginBlockEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::MarginGroup());
}

void MarginBlockEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MarginBlockEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MarginBlockEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // margin-block-start



const char* MarginBlockStart::GetPropertyName() const {
  return "margin-block-start";
}

const WTF::AtomicString& MarginBlockStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-block-start"));
  return name;
}

const char* MarginBlockStart::GetJSPropertyName() const {
  return "marginBlockStart";
}

const CSSProperty* MarginBlockStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MarginBlockStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::MarginGroup());
}

void MarginBlockStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MarginBlockStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MarginBlockStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // margin-bottom



const char* MarginBottom::GetPropertyName() const {
  return "margin-bottom";
}

const WTF::AtomicString& MarginBottom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-bottom"));
  return name;
}

const char* MarginBottom::GetJSPropertyName() const {
  return "marginBottom";
}

bool MarginBottom::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MarginBottom() == b.MarginBottom();
}

void MarginBottom::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMarginBottom(ComputedStyleInitialValues::InitialMarginBottom());
}
void MarginBottom::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMarginBottom(state.ParentStyle()->MarginBottom());
}
void MarginBottom::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMarginBottom(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

 // margin-inline-end



const char* MarginInlineEnd::GetPropertyName() const {
  return "margin-inline-end";
}

const WTF::AtomicString& MarginInlineEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-inline-end"));
  return name;
}

const char* MarginInlineEnd::GetJSPropertyName() const {
  return "marginInlineEnd";
}

const CSSProperty* MarginInlineEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MarginInlineEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::MarginGroup());
}

void MarginInlineEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MarginInlineEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MarginInlineEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // margin-inline-start



const char* MarginInlineStart::GetPropertyName() const {
  return "margin-inline-start";
}

const WTF::AtomicString& MarginInlineStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-inline-start"));
  return name;
}

const char* MarginInlineStart::GetJSPropertyName() const {
  return "marginInlineStart";
}

const CSSProperty* MarginInlineStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MarginInlineStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::MarginGroup());
}

void MarginInlineStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MarginInlineStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MarginInlineStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // margin-left



const char* MarginLeft::GetPropertyName() const {
  return "margin-left";
}

const WTF::AtomicString& MarginLeft::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-left"));
  return name;
}

const char* MarginLeft::GetJSPropertyName() const {
  return "marginLeft";
}

bool MarginLeft::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MarginLeft() == b.MarginLeft();
}

void MarginLeft::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMarginLeft(ComputedStyleInitialValues::InitialMarginLeft());
}
void MarginLeft::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMarginLeft(state.ParentStyle()->MarginLeft());
}
void MarginLeft::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMarginLeft(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

 // margin-right



const char* MarginRight::GetPropertyName() const {
  return "margin-right";
}

const WTF::AtomicString& MarginRight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-right"));
  return name;
}

const char* MarginRight::GetJSPropertyName() const {
  return "marginRight";
}

bool MarginRight::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MarginRight() == b.MarginRight();
}

void MarginRight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMarginRight(ComputedStyleInitialValues::InitialMarginRight());
}
void MarginRight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMarginRight(state.ParentStyle()->MarginRight());
}
void MarginRight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMarginRight(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

 // margin-top



const char* MarginTop::GetPropertyName() const {
  return "margin-top";
}

const WTF::AtomicString& MarginTop::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-top"));
  return name;
}

const char* MarginTop::GetJSPropertyName() const {
  return "marginTop";
}

bool MarginTop::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MarginTop() == b.MarginTop();
}

void MarginTop::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMarginTop(ComputedStyleInitialValues::InitialMarginTop());
}
void MarginTop::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMarginTop(state.ParentStyle()->MarginTop());
}
void MarginTop::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMarginTop(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

 // marker-end



const char* MarkerEnd::GetPropertyName() const {
  return "marker-end";
}

const WTF::AtomicString& MarkerEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("marker-end"));
  return name;
}

const char* MarkerEnd::GetJSPropertyName() const {
  return "markerEnd";
}


void MarkerEnd::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMarkerEndResource(SVGComputedStyle::InitialMarkerEndResource());
}
void MarkerEnd::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMarkerEndResource(state.ParentStyle()->SvgStyle().MarkerEndResource());
}
void MarkerEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetMarkerEndResource(StyleBuilderConverter::ConvertElementReference(state, value));
}

 // marker-mid



const char* MarkerMid::GetPropertyName() const {
  return "marker-mid";
}

const WTF::AtomicString& MarkerMid::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("marker-mid"));
  return name;
}

const char* MarkerMid::GetJSPropertyName() const {
  return "markerMid";
}


void MarkerMid::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMarkerMidResource(SVGComputedStyle::InitialMarkerMidResource());
}
void MarkerMid::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMarkerMidResource(state.ParentStyle()->SvgStyle().MarkerMidResource());
}
void MarkerMid::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetMarkerMidResource(StyleBuilderConverter::ConvertElementReference(state, value));
}

 // marker-start



const char* MarkerStart::GetPropertyName() const {
  return "marker-start";
}

const WTF::AtomicString& MarkerStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("marker-start"));
  return name;
}

const char* MarkerStart::GetJSPropertyName() const {
  return "markerStart";
}


void MarkerStart::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMarkerStartResource(SVGComputedStyle::InitialMarkerStartResource());
}
void MarkerStart::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMarkerStartResource(state.ParentStyle()->SvgStyle().MarkerStartResource());
}
void MarkerStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetMarkerStartResource(StyleBuilderConverter::ConvertElementReference(state, value));
}

 // mask



const char* Mask::GetPropertyName() const {
  return "mask";
}

const WTF::AtomicString& Mask::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask"));
  return name;
}

const char* Mask::GetJSPropertyName() const {
  return "mask";
}


void Mask::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMaskerResource(SVGComputedStyle::InitialMaskerResource());
}
void Mask::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMaskerResource(state.ParentStyle()->SvgStyle().MaskerResource());
}
void Mask::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetMaskerResource(StyleBuilderConverter::ConvertElementReference(state, value));
}

 // mask-type



const char* MaskType::GetPropertyName() const {
  return "mask-type";
}

const WTF::AtomicString& MaskType::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-type"));
  return name;
}

const char* MaskType::GetJSPropertyName() const {
  return "maskType";
}


void MaskType::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMaskType(SVGComputedStyle::InitialMaskType());
}
void MaskType::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetMaskType(state.ParentStyle()->SvgStyle().MaskType());
}
void MaskType::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetMaskType(To<CSSIdentifierValue>(value).ConvertTo<blink::EMaskType>());
}

 // math-style

CSSExposure MathStyle::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSMathStyleEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* MathStyle::GetPropertyName() const {
  return "math-style";
}

const WTF::AtomicString& MathStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("math-style"));
  return name;
}

const char* MathStyle::GetJSPropertyName() const {
  return "mathStyle";
}


void MathStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMathStyle(ComputedStyleInitialValues::InitialMathStyle());
}
void MathStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMathStyle(state.ParentStyle()->MathStyle());
}
void MathStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMathStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EMathStyle>());
}

 // math-superscript-shift-style

CSSExposure MathSuperscriptShiftStyle::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSMathSuperscriptShiftStyleEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* MathSuperscriptShiftStyle::GetPropertyName() const {
  return "math-superscript-shift-style";
}

const WTF::AtomicString& MathSuperscriptShiftStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("math-superscript-shift-style"));
  return name;
}

const char* MathSuperscriptShiftStyle::GetJSPropertyName() const {
  return "mathSuperscriptShiftStyle";
}


void MathSuperscriptShiftStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMathSuperscriptShiftStyle(ComputedStyleInitialValues::InitialMathSuperscriptShiftStyle());
}
void MathSuperscriptShiftStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMathSuperscriptShiftStyle(state.ParentStyle()->MathSuperscriptShiftStyle());
}
void MathSuperscriptShiftStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMathSuperscriptShiftStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EMathSuperscriptShiftStyle>());
}

 // max-block-size



const char* MaxBlockSize::GetPropertyName() const {
  return "max-block-size";
}

const WTF::AtomicString& MaxBlockSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-block-size"));
  return name;
}

const char* MaxBlockSize::GetJSPropertyName() const {
  return "maxBlockSize";
}

const CSSProperty* MaxBlockSize::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MaxBlockSize::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlock(direction, writing_mode,
      CSSDirectionAwareResolver::MaxSizeGroup());
}

void MaxBlockSize::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MaxBlockSize::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MaxBlockSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // max-height



const char* MaxHeight::GetPropertyName() const {
  return "max-height";
}

const WTF::AtomicString& MaxHeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-height"));
  return name;
}

const char* MaxHeight::GetJSPropertyName() const {
  return "maxHeight";
}

bool MaxHeight::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MaxHeight() == b.MaxHeight();
}

void MaxHeight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMaxHeight(ComputedStyleInitialValues::InitialMaxHeight());
}
void MaxHeight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMaxHeight(state.ParentStyle()->MaxHeight());
}
void MaxHeight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMaxHeight(StyleBuilderConverter::ConvertLengthMaxSizing(state, value));
}

 // max-inline-size



const char* MaxInlineSize::GetPropertyName() const {
  return "max-inline-size";
}

const WTF::AtomicString& MaxInlineSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-inline-size"));
  return name;
}

const char* MaxInlineSize::GetJSPropertyName() const {
  return "maxInlineSize";
}

const CSSProperty* MaxInlineSize::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MaxInlineSize::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInline(direction, writing_mode,
      CSSDirectionAwareResolver::MaxSizeGroup());
}

void MaxInlineSize::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MaxInlineSize::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MaxInlineSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // max-width



const char* MaxWidth::GetPropertyName() const {
  return "max-width";
}

const WTF::AtomicString& MaxWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-width"));
  return name;
}

const char* MaxWidth::GetJSPropertyName() const {
  return "maxWidth";
}

bool MaxWidth::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MaxWidth() == b.MaxWidth();
}

void MaxWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMaxWidth(ComputedStyleInitialValues::InitialMaxWidth());
}
void MaxWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMaxWidth(state.ParentStyle()->MaxWidth());
}
void MaxWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMaxWidth(StyleBuilderConverter::ConvertLengthMaxSizing(state, value));
}

 // max-zoom



const char* MaxZoom::GetPropertyName() const {
  return "max-zoom";
}

const WTF::AtomicString& MaxZoom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-zoom"));
  return name;
}

const char* MaxZoom::GetJSPropertyName() const {
  return "maxZoom";
}



 // min-block-size



const char* MinBlockSize::GetPropertyName() const {
  return "min-block-size";
}

const WTF::AtomicString& MinBlockSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-block-size"));
  return name;
}

const char* MinBlockSize::GetJSPropertyName() const {
  return "minBlockSize";
}

const CSSProperty* MinBlockSize::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MinBlockSize::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlock(direction, writing_mode,
      CSSDirectionAwareResolver::MinSizeGroup());
}

void MinBlockSize::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MinBlockSize::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MinBlockSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // min-height



const char* MinHeight::GetPropertyName() const {
  return "min-height";
}

const WTF::AtomicString& MinHeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-height"));
  return name;
}

const char* MinHeight::GetJSPropertyName() const {
  return "minHeight";
}

bool MinHeight::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MinHeight() == b.MinHeight();
}

void MinHeight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMinHeight(ComputedStyleInitialValues::InitialMinHeight());
}
void MinHeight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMinHeight(state.ParentStyle()->MinHeight());
}
void MinHeight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMinHeight(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

 // min-inline-size



const char* MinInlineSize::GetPropertyName() const {
  return "min-inline-size";
}

const WTF::AtomicString& MinInlineSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-inline-size"));
  return name;
}

const char* MinInlineSize::GetJSPropertyName() const {
  return "minInlineSize";
}

const CSSProperty* MinInlineSize::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& MinInlineSize::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInline(direction, writing_mode,
      CSSDirectionAwareResolver::MinSizeGroup());
}

void MinInlineSize::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void MinInlineSize::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void MinInlineSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // min-width



const char* MinWidth::GetPropertyName() const {
  return "min-width";
}

const WTF::AtomicString& MinWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-width"));
  return name;
}

const char* MinWidth::GetJSPropertyName() const {
  return "minWidth";
}

bool MinWidth::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.MinWidth() == b.MinWidth();
}

void MinWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMinWidth(ComputedStyleInitialValues::InitialMinWidth());
}
void MinWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMinWidth(state.ParentStyle()->MinWidth());
}
void MinWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetMinWidth(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

 // min-zoom



const char* MinZoom::GetPropertyName() const {
  return "min-zoom";
}

const WTF::AtomicString& MinZoom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-zoom"));
  return name;
}

const char* MinZoom::GetJSPropertyName() const {
  return "minZoom";
}



 // mix-blend-mode



const char* MixBlendMode::GetPropertyName() const {
  return "mix-blend-mode";
}

const WTF::AtomicString& MixBlendMode::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("mix-blend-mode"));
  return name;
}

const char* MixBlendMode::GetJSPropertyName() const {
  return "mixBlendMode";
}


void MixBlendMode::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBlendMode(ComputedStyleInitialValues::InitialBlendMode());
}
void MixBlendMode::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBlendMode(state.ParentStyle()->GetBlendMode());
}
void MixBlendMode::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBlendMode(To<CSSIdentifierValue>(value).ConvertTo<blink::BlendMode>());
}

 // object-fit



const char* ObjectFit::GetPropertyName() const {
  return "object-fit";
}

const WTF::AtomicString& ObjectFit::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("object-fit"));
  return name;
}

const char* ObjectFit::GetJSPropertyName() const {
  return "objectFit";
}


void ObjectFit::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetObjectFit(ComputedStyleInitialValues::InitialObjectFit());
}
void ObjectFit::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetObjectFit(state.ParentStyle()->GetObjectFit());
}
void ObjectFit::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetObjectFit(To<CSSIdentifierValue>(value).ConvertTo<blink::EObjectFit>());
}

 // object-position



const char* ObjectPosition::GetPropertyName() const {
  return "object-position";
}

const WTF::AtomicString& ObjectPosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("object-position"));
  return name;
}

const char* ObjectPosition::GetJSPropertyName() const {
  return "objectPosition";
}


void ObjectPosition::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetObjectPosition(ComputedStyleInitialValues::InitialObjectPosition());
}
void ObjectPosition::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetObjectPosition(state.ParentStyle()->ObjectPosition());
}
void ObjectPosition::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetObjectPosition(StyleBuilderConverter::ConvertPosition(state, value));
}

 // offset-anchor

CSSExposure OffsetAnchor::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSOffsetPositionAnchorEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* OffsetAnchor::GetPropertyName() const {
  return "offset-anchor";
}

const WTF::AtomicString& OffsetAnchor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-anchor"));
  return name;
}

const char* OffsetAnchor::GetJSPropertyName() const {
  return "offsetAnchor";
}


void OffsetAnchor::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOffsetAnchor(ComputedStyleInitialValues::InitialOffsetAnchor());
}
void OffsetAnchor::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOffsetAnchor(state.ParentStyle()->OffsetAnchor());
}
void OffsetAnchor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOffsetAnchor(StyleBuilderConverter::ConvertPositionOrAuto(state, value));
}

 // offset-distance



const char* OffsetDistance::GetPropertyName() const {
  return "offset-distance";
}

const WTF::AtomicString& OffsetDistance::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-distance"));
  return name;
}

const char* OffsetDistance::GetJSPropertyName() const {
  return "offsetDistance";
}


void OffsetDistance::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOffsetDistance(ComputedStyleInitialValues::InitialOffsetDistance());
}
void OffsetDistance::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOffsetDistance(state.ParentStyle()->OffsetDistance());
}
void OffsetDistance::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOffsetDistance(StyleBuilderConverter::ConvertLength(state, value));
}

 // offset-path



const char* OffsetPath::GetPropertyName() const {
  return "offset-path";
}

const WTF::AtomicString& OffsetPath::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-path"));
  return name;
}

const char* OffsetPath::GetJSPropertyName() const {
  return "offsetPath";
}


void OffsetPath::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOffsetPath(ComputedStyleInitialValues::InitialOffsetPath());
}
void OffsetPath::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOffsetPath(state.ParentStyle()->OffsetPath());
}
void OffsetPath::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOffsetPath(StyleBuilderConverter::ConvertOffsetPath(state, value));
}

 // offset-position

CSSExposure OffsetPosition::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSOffsetPositionAnchorEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* OffsetPosition::GetPropertyName() const {
  return "offset-position";
}

const WTF::AtomicString& OffsetPosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-position"));
  return name;
}

const char* OffsetPosition::GetJSPropertyName() const {
  return "offsetPosition";
}


void OffsetPosition::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOffsetPosition(ComputedStyleInitialValues::InitialOffsetPosition());
}
void OffsetPosition::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOffsetPosition(state.ParentStyle()->OffsetPosition());
}
void OffsetPosition::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOffsetPosition(StyleBuilderConverter::ConvertPositionOrAuto(state, value));
}

 // offset-rotate



const char* OffsetRotate::GetPropertyName() const {
  return "offset-rotate";
}

const WTF::AtomicString& OffsetRotate::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-rotate"));
  return name;
}

const char* OffsetRotate::GetJSPropertyName() const {
  return "offsetRotate";
}


void OffsetRotate::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOffsetRotate(ComputedStyleInitialValues::InitialOffsetRotate());
}
void OffsetRotate::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOffsetRotate(state.ParentStyle()->OffsetRotate());
}
void OffsetRotate::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOffsetRotate(StyleBuilderConverter::ConvertOffsetRotate(state, value));
}

 // opacity



const char* Opacity::GetPropertyName() const {
  return "opacity";
}

const WTF::AtomicString& Opacity::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("opacity"));
  return name;
}

const char* Opacity::GetJSPropertyName() const {
  return "opacity";
}


void Opacity::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOpacity(ComputedStyleInitialValues::InitialOpacity());
}
void Opacity::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOpacity(state.ParentStyle()->Opacity());
}
void Opacity::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOpacity(To<CSSPrimitiveValue>(value).ConvertTo<float>());
}

 // order



const char* Order::GetPropertyName() const {
  return "order";
}

const WTF::AtomicString& Order::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("order"));
  return name;
}

const char* Order::GetJSPropertyName() const {
  return "order";
}


void Order::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOrder(ComputedStyleInitialValues::InitialOrder());
}
void Order::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOrder(state.ParentStyle()->Order());
}
void Order::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOrder(To<CSSPrimitiveValue>(value).ConvertTo<int>());
}

 // orientation



const char* Orientation::GetPropertyName() const {
  return "orientation";
}

const WTF::AtomicString& Orientation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("orientation"));
  return name;
}

const char* Orientation::GetJSPropertyName() const {
  return "orientation";
}



 // origin-trial-test-property


CSSExposure OriginTrialTestProperty::Exposure(const ExecutionContext* execution_context) const {
  if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(execution_context))
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}

const char* OriginTrialTestProperty::GetPropertyName() const {
  return "origin-trial-test-property";
}

const WTF::AtomicString& OriginTrialTestProperty::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("origin-trial-test-property"));
  return name;
}

const char* OriginTrialTestProperty::GetJSPropertyName() const {
  return "originTrialTestProperty";
}


void OriginTrialTestProperty::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOriginTrialTestProperty(ComputedStyleInitialValues::InitialOriginTrialTestProperty());
}
void OriginTrialTestProperty::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOriginTrialTestProperty(state.ParentStyle()->OriginTrialTestProperty());
}
void OriginTrialTestProperty::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOriginTrialTestProperty(To<CSSIdentifierValue>(value).ConvertTo<blink::EOriginTrialTestProperty>());
}

 // orphans



const char* Orphans::GetPropertyName() const {
  return "orphans";
}

const WTF::AtomicString& Orphans::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("orphans"));
  return name;
}

const char* Orphans::GetJSPropertyName() const {
  return "orphans";
}


void Orphans::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOrphans(ComputedStyleInitialValues::InitialOrphans());
}
void Orphans::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOrphans(state.ParentStyle()->Orphans());
}
void Orphans::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOrphans(To<CSSPrimitiveValue>(value).ConvertTo<short>());
}

 // outline-color



const char* OutlineColor::GetPropertyName() const {
  return "outline-color";
}

const WTF::AtomicString& OutlineColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-color"));
  return name;
}

const char* OutlineColor::GetJSPropertyName() const {
  return "outlineColor";
}
const CSSProperty* OutlineColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedOutlineColor();
}


void OutlineColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetOutlineColor(color);
}

void OutlineColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->OutlineColor();
  state.Style()->SetOutlineColor(color);
}

void OutlineColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOutlineColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // outline-offset



const char* OutlineOffset::GetPropertyName() const {
  return "outline-offset";
}

const WTF::AtomicString& OutlineOffset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-offset"));
  return name;
}

const char* OutlineOffset::GetJSPropertyName() const {
  return "outlineOffset";
}


void OutlineOffset::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOutlineOffset(ComputedStyleInitialValues::InitialOutlineOffset());
}
void OutlineOffset::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOutlineOffset(state.ParentStyle()->OutlineOffset());
}
void OutlineOffset::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOutlineOffset(StyleBuilderConverter::ConvertLayoutUnit(state, value));
}

 // outline-style



const char* OutlineStyle::GetPropertyName() const {
  return "outline-style";
}

const WTF::AtomicString& OutlineStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-style"));
  return name;
}

const char* OutlineStyle::GetJSPropertyName() const {
  return "outlineStyle";
}



 // outline-width



const char* OutlineWidth::GetPropertyName() const {
  return "outline-width";
}

const WTF::AtomicString& OutlineWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-width"));
  return name;
}

const char* OutlineWidth::GetJSPropertyName() const {
  return "outlineWidth";
}


void OutlineWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOutlineWidth(ComputedStyleInitialValues::InitialOutlineWidth());
}
void OutlineWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOutlineWidth(state.ParentStyle()->OutlineWidth());
}
void OutlineWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOutlineWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

 // overflow-anchor



const char* OverflowAnchor::GetPropertyName() const {
  return "overflow-anchor";
}

const WTF::AtomicString& OverflowAnchor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-anchor"));
  return name;
}

const char* OverflowAnchor::GetJSPropertyName() const {
  return "overflowAnchor";
}


void OverflowAnchor::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOverflowAnchor(ComputedStyleInitialValues::InitialOverflowAnchor());
}
void OverflowAnchor::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOverflowAnchor(state.ParentStyle()->OverflowAnchor());
}
void OverflowAnchor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOverflowAnchor(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverflowAnchor>());
}

 // overflow-block

CSSExposure OverflowBlock::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalOverflowEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* OverflowBlock::GetPropertyName() const {
  return "overflow-block";
}

const WTF::AtomicString& OverflowBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-block"));
  return name;
}

const char* OverflowBlock::GetJSPropertyName() const {
  return "overflowBlock";
}

const CSSProperty* OverflowBlock::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& OverflowBlock::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlock(direction, writing_mode,
      CSSDirectionAwareResolver::OverflowGroup());
}

void OverflowBlock::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void OverflowBlock::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void OverflowBlock::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // overflow-inline

CSSExposure OverflowInline::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSLogicalOverflowEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* OverflowInline::GetPropertyName() const {
  return "overflow-inline";
}

const WTF::AtomicString& OverflowInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-inline"));
  return name;
}

const char* OverflowInline::GetJSPropertyName() const {
  return "overflowInline";
}

const CSSProperty* OverflowInline::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& OverflowInline::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInline(direction, writing_mode,
      CSSDirectionAwareResolver::OverflowGroup());
}

void OverflowInline::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void OverflowInline::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void OverflowInline::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // overflow-wrap



const char* OverflowWrap::GetPropertyName() const {
  return "overflow-wrap";
}

const WTF::AtomicString& OverflowWrap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-wrap"));
  return name;
}

const char* OverflowWrap::GetJSPropertyName() const {
  return "overflowWrap";
}


void OverflowWrap::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOverflowWrap(ComputedStyleInitialValues::InitialOverflowWrap());
}
void OverflowWrap::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOverflowWrap(state.ParentStyle()->OverflowWrap());
}
void OverflowWrap::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOverflowWrap(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverflowWrap>());
}

 // overflow-x



const char* OverflowX::GetPropertyName() const {
  return "overflow-x";
}

const WTF::AtomicString& OverflowX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-x"));
  return name;
}

const char* OverflowX::GetJSPropertyName() const {
  return "overflowX";
}


void OverflowX::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOverflowX(ComputedStyleInitialValues::InitialOverflowX());
}
void OverflowX::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOverflowX(state.ParentStyle()->OverflowX());
}
void OverflowX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOverflowX(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverflow>());
}

 // overflow-y



const char* OverflowY::GetPropertyName() const {
  return "overflow-y";
}

const WTF::AtomicString& OverflowY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-y"));
  return name;
}

const char* OverflowY::GetJSPropertyName() const {
  return "overflowY";
}


void OverflowY::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOverflowY(ComputedStyleInitialValues::InitialOverflowY());
}
void OverflowY::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOverflowY(state.ParentStyle()->OverflowY());
}
void OverflowY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOverflowY(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverflow>());
}

 // overscroll-behavior-block



const char* OverscrollBehaviorBlock::GetPropertyName() const {
  return "overscroll-behavior-block";
}

const WTF::AtomicString& OverscrollBehaviorBlock::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-block"));
  return name;
}

const char* OverscrollBehaviorBlock::GetJSPropertyName() const {
  return "overscrollBehaviorBlock";
}

const CSSProperty* OverscrollBehaviorBlock::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& OverscrollBehaviorBlock::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlock(direction, writing_mode,
      CSSDirectionAwareResolver::OverscrollBehaviorGroup());
}

void OverscrollBehaviorBlock::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void OverscrollBehaviorBlock::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void OverscrollBehaviorBlock::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // overscroll-behavior-inline



const char* OverscrollBehaviorInline::GetPropertyName() const {
  return "overscroll-behavior-inline";
}

const WTF::AtomicString& OverscrollBehaviorInline::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-inline"));
  return name;
}

const char* OverscrollBehaviorInline::GetJSPropertyName() const {
  return "overscrollBehaviorInline";
}

const CSSProperty* OverscrollBehaviorInline::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& OverscrollBehaviorInline::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInline(direction, writing_mode,
      CSSDirectionAwareResolver::OverscrollBehaviorGroup());
}

void OverscrollBehaviorInline::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void OverscrollBehaviorInline::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void OverscrollBehaviorInline::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // overscroll-behavior-x



const char* OverscrollBehaviorX::GetPropertyName() const {
  return "overscroll-behavior-x";
}

const WTF::AtomicString& OverscrollBehaviorX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-x"));
  return name;
}

const char* OverscrollBehaviorX::GetJSPropertyName() const {
  return "overscrollBehaviorX";
}


void OverscrollBehaviorX::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOverscrollBehaviorX(ComputedStyleInitialValues::InitialOverscrollBehaviorX());
}
void OverscrollBehaviorX::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOverscrollBehaviorX(state.ParentStyle()->OverscrollBehaviorX());
}
void OverscrollBehaviorX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOverscrollBehaviorX(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverscrollBehavior>());
}

 // overscroll-behavior-y



const char* OverscrollBehaviorY::GetPropertyName() const {
  return "overscroll-behavior-y";
}

const WTF::AtomicString& OverscrollBehaviorY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-y"));
  return name;
}

const char* OverscrollBehaviorY::GetJSPropertyName() const {
  return "overscrollBehaviorY";
}


void OverscrollBehaviorY::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetOverscrollBehaviorY(ComputedStyleInitialValues::InitialOverscrollBehaviorY());
}
void OverscrollBehaviorY::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetOverscrollBehaviorY(state.ParentStyle()->OverscrollBehaviorY());
}
void OverscrollBehaviorY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetOverscrollBehaviorY(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverscrollBehavior>());
}

 // padding-block-end



const char* PaddingBlockEnd::GetPropertyName() const {
  return "padding-block-end";
}

const WTF::AtomicString& PaddingBlockEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-block-end"));
  return name;
}

const char* PaddingBlockEnd::GetJSPropertyName() const {
  return "paddingBlockEnd";
}

const CSSProperty* PaddingBlockEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& PaddingBlockEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::PaddingGroup());
}

void PaddingBlockEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void PaddingBlockEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void PaddingBlockEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // padding-block-start



const char* PaddingBlockStart::GetPropertyName() const {
  return "padding-block-start";
}

const WTF::AtomicString& PaddingBlockStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-block-start"));
  return name;
}

const char* PaddingBlockStart::GetJSPropertyName() const {
  return "paddingBlockStart";
}

const CSSProperty* PaddingBlockStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& PaddingBlockStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::PaddingGroup());
}

void PaddingBlockStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void PaddingBlockStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void PaddingBlockStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // padding-bottom



const char* PaddingBottom::GetPropertyName() const {
  return "padding-bottom";
}

const WTF::AtomicString& PaddingBottom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-bottom"));
  return name;
}

const char* PaddingBottom::GetJSPropertyName() const {
  return "paddingBottom";
}

bool PaddingBottom::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.PaddingBottom() == b.PaddingBottom();
}

void PaddingBottom::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPaddingBottom(ComputedStyleInitialValues::InitialPaddingBottom());
}
void PaddingBottom::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPaddingBottom(state.ParentStyle()->PaddingBottom());
}
void PaddingBottom::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPaddingBottom(StyleBuilderConverter::ConvertLength(state, value));
}

 // padding-inline-end



const char* PaddingInlineEnd::GetPropertyName() const {
  return "padding-inline-end";
}

const WTF::AtomicString& PaddingInlineEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-inline-end"));
  return name;
}

const char* PaddingInlineEnd::GetJSPropertyName() const {
  return "paddingInlineEnd";
}

const CSSProperty* PaddingInlineEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& PaddingInlineEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::PaddingGroup());
}

void PaddingInlineEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void PaddingInlineEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void PaddingInlineEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // padding-inline-start



const char* PaddingInlineStart::GetPropertyName() const {
  return "padding-inline-start";
}

const WTF::AtomicString& PaddingInlineStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-inline-start"));
  return name;
}

const char* PaddingInlineStart::GetJSPropertyName() const {
  return "paddingInlineStart";
}

const CSSProperty* PaddingInlineStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& PaddingInlineStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::PaddingGroup());
}

void PaddingInlineStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void PaddingInlineStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void PaddingInlineStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // padding-left



const char* PaddingLeft::GetPropertyName() const {
  return "padding-left";
}

const WTF::AtomicString& PaddingLeft::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-left"));
  return name;
}

const char* PaddingLeft::GetJSPropertyName() const {
  return "paddingLeft";
}

bool PaddingLeft::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.PaddingLeft() == b.PaddingLeft();
}

void PaddingLeft::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPaddingLeft(ComputedStyleInitialValues::InitialPaddingLeft());
}
void PaddingLeft::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPaddingLeft(state.ParentStyle()->PaddingLeft());
}
void PaddingLeft::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPaddingLeft(StyleBuilderConverter::ConvertLength(state, value));
}

 // padding-right



const char* PaddingRight::GetPropertyName() const {
  return "padding-right";
}

const WTF::AtomicString& PaddingRight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-right"));
  return name;
}

const char* PaddingRight::GetJSPropertyName() const {
  return "paddingRight";
}

bool PaddingRight::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.PaddingRight() == b.PaddingRight();
}

void PaddingRight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPaddingRight(ComputedStyleInitialValues::InitialPaddingRight());
}
void PaddingRight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPaddingRight(state.ParentStyle()->PaddingRight());
}
void PaddingRight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPaddingRight(StyleBuilderConverter::ConvertLength(state, value));
}

 // padding-top



const char* PaddingTop::GetPropertyName() const {
  return "padding-top";
}

const WTF::AtomicString& PaddingTop::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-top"));
  return name;
}

const char* PaddingTop::GetJSPropertyName() const {
  return "paddingTop";
}

bool PaddingTop::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.PaddingTop() == b.PaddingTop();
}

void PaddingTop::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPaddingTop(ComputedStyleInitialValues::InitialPaddingTop());
}
void PaddingTop::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPaddingTop(state.ParentStyle()->PaddingTop());
}
void PaddingTop::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPaddingTop(StyleBuilderConverter::ConvertLength(state, value));
}

 // page

CSSExposure Page::Exposure() const {
  if (!RuntimeEnabledFeatures::NamedPagesEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Page::GetPropertyName() const {
  return "page";
}

const WTF::AtomicString& Page::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("page"));
  return name;
}

const char* Page::GetJSPropertyName() const {
  return "page";
}


void Page::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPage(ComputedStyleInitialValues::InitialPage());
}
void Page::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPage(state.ParentStyle()->Page());
}
void Page::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPage(StyleBuilderConverter::ConvertPage(state, value));
}

 // page-orientation

CSSExposure PageOrientation::Exposure() const {
  if (!RuntimeEnabledFeatures::NamedPagesEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* PageOrientation::GetPropertyName() const {
  return "page-orientation";
}

const WTF::AtomicString& PageOrientation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("page-orientation"));
  return name;
}

const char* PageOrientation::GetJSPropertyName() const {
  return "pageOrientation";
}


void PageOrientation::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPageOrientation(ComputedStyleInitialValues::InitialPageOrientation());
}
void PageOrientation::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPageOrientation(state.ParentStyle()->GetPageOrientation());
}
void PageOrientation::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPageOrientation(To<CSSIdentifierValue>(value).ConvertTo<blink::PageOrientation>());
}

 // paint-order



const char* PaintOrder::GetPropertyName() const {
  return "paint-order";
}

const WTF::AtomicString& PaintOrder::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("paint-order"));
  return name;
}

const char* PaintOrder::GetJSPropertyName() const {
  return "paintOrder";
}


void PaintOrder::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetPaintOrder(SVGComputedStyle::InitialPaintOrder());
}
void PaintOrder::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetPaintOrder(state.ParentStyle()->SvgStyle().PaintOrder());
}
void PaintOrder::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetPaintOrder(StyleBuilderConverter::ConvertPaintOrder(state, value));
}

 // perspective



const char* Perspective::GetPropertyName() const {
  return "perspective";
}

const WTF::AtomicString& Perspective::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("perspective"));
  return name;
}

const char* Perspective::GetJSPropertyName() const {
  return "perspective";
}


void Perspective::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPerspective(ComputedStyleInitialValues::InitialPerspective());
}
void Perspective::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPerspective(state.ParentStyle()->Perspective());
}
void Perspective::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPerspective(StyleBuilderConverter::ConvertPerspective(state, value));
}

 // perspective-origin



const char* PerspectiveOrigin::GetPropertyName() const {
  return "perspective-origin";
}

const WTF::AtomicString& PerspectiveOrigin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("perspective-origin"));
  return name;
}

const char* PerspectiveOrigin::GetJSPropertyName() const {
  return "perspectiveOrigin";
}


void PerspectiveOrigin::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPerspectiveOrigin(ComputedStyleInitialValues::InitialPerspectiveOrigin());
}
void PerspectiveOrigin::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPerspectiveOrigin(state.ParentStyle()->PerspectiveOrigin());
}
void PerspectiveOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPerspectiveOrigin(StyleBuilderConverter::ConvertPosition(state, value));
}

 // pointer-events



const char* PointerEvents::GetPropertyName() const {
  return "pointer-events";
}

const WTF::AtomicString& PointerEvents::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("pointer-events"));
  return name;
}

const char* PointerEvents::GetJSPropertyName() const {
  return "pointerEvents";
}


void PointerEvents::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPointerEvents(ComputedStyleInitialValues::InitialPointerEvents());
  state.Style()->SetPointerEventsIsInherited(false);
}
void PointerEvents::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPointerEvents(state.ParentStyle()->PointerEvents());
  state.Style()->SetPointerEventsIsInherited(true);
}
void PointerEvents::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPointerEvents(To<CSSIdentifierValue>(value).ConvertTo<blink::EPointerEvents>());
  state.Style()->SetPointerEventsIsInherited(false);
}

 // position



const char* Position::GetPropertyName() const {
  return "position";
}

const WTF::AtomicString& Position::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("position"));
  return name;
}

const char* Position::GetJSPropertyName() const {
  return "position";
}


void Position::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPosition(ComputedStyleInitialValues::InitialPosition());
}
void Position::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPosition(To<CSSIdentifierValue>(value).ConvertTo<blink::EPosition>());
}

 // quotes



const char* Quotes::GetPropertyName() const {
  return "quotes";
}

const WTF::AtomicString& Quotes::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("quotes"));
  return name;
}

const char* Quotes::GetJSPropertyName() const {
  return "quotes";
}


void Quotes::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetQuotes(ComputedStyleInitialValues::InitialQuotes());
}
void Quotes::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetQuotes(state.ParentStyle()->Quotes());
}
void Quotes::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetQuotes(StyleBuilderConverter::ConvertQuotes(state, value));
}

 // r



const char* R::GetPropertyName() const {
  return "r";
}

const WTF::AtomicString& R::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("r"));
  return name;
}

const char* R::GetJSPropertyName() const {
  return "r";
}


void R::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetR(SVGComputedStyle::InitialR());
}
void R::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetR(state.ParentStyle()->SvgStyle().R());
}
void R::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetR(StyleBuilderConverter::ConvertLength(state, value));
}

 // resize



const char* Resize::GetPropertyName() const {
  return "resize";
}

const WTF::AtomicString& Resize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("resize"));
  return name;
}

const char* Resize::GetJSPropertyName() const {
  return "resize";
}


void Resize::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetResize(ComputedStyleInitialValues::InitialResize());
}
void Resize::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetResize(state.ParentStyle()->Resize());
}

 // right



const char* Right::GetPropertyName() const {
  return "right";
}

const WTF::AtomicString& Right::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("right"));
  return name;
}

const char* Right::GetJSPropertyName() const {
  return "right";
}

bool Right::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.Right() == b.Right();
}

void Right::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetRight(ComputedStyleInitialValues::InitialRight());
}
void Right::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetRight(state.ParentStyle()->Right());
}
void Right::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetRight(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // rotate

CSSExposure Rotate::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSIndependentTransformPropertiesEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Rotate::GetPropertyName() const {
  return "rotate";
}

const WTF::AtomicString& Rotate::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("rotate"));
  return name;
}

const char* Rotate::GetJSPropertyName() const {
  return "rotate";
}


void Rotate::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetRotate(ComputedStyleInitialValues::InitialRotate());
}
void Rotate::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetRotate(state.ParentStyle()->Rotate());
}
void Rotate::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetRotate(StyleBuilderConverter::ConvertRotate(state, value));
}

 // row-gap



const char* RowGap::GetPropertyName() const {
  return "row-gap";
}

const WTF::AtomicString& RowGap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("row-gap"));
  return name;
}

const char* RowGap::GetJSPropertyName() const {
  return "rowGap";
}


void RowGap::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetRowGap(ComputedStyleInitialValues::InitialRowGap());
}
void RowGap::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetRowGap(state.ParentStyle()->RowGap());
}
void RowGap::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetRowGap(StyleBuilderConverter::ConvertGapLength(state, value));
}

 // ruby-position



const char* RubyPosition::GetPropertyName() const {
  return "ruby-position";
}

const WTF::AtomicString& RubyPosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("ruby-position"));
  return name;
}

const char* RubyPosition::GetJSPropertyName() const {
  return "rubyPosition";
}

const CSSProperty* RubyPosition::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &GetCSSPropertyWebkitRubyPosition();
}

void RubyPosition::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetRubyPosition(ComputedStyleInitialValues::InitialRubyPosition());
}
void RubyPosition::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetRubyPosition(state.ParentStyle()->GetRubyPosition());
}
void RubyPosition::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetRubyPosition(StyleBuilderConverter::ConvertRubyPosition(state, value));
}

 // rx



const char* Rx::GetPropertyName() const {
  return "rx";
}

const WTF::AtomicString& Rx::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("rx"));
  return name;
}

const char* Rx::GetJSPropertyName() const {
  return "rx";
}


void Rx::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetRx(SVGComputedStyle::InitialRx());
}
void Rx::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetRx(state.ParentStyle()->SvgStyle().Rx());
}
void Rx::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetRx(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // ry



const char* Ry::GetPropertyName() const {
  return "ry";
}

const WTF::AtomicString& Ry::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("ry"));
  return name;
}

const char* Ry::GetJSPropertyName() const {
  return "ry";
}


void Ry::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetRy(SVGComputedStyle::InitialRy());
}
void Ry::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetRy(state.ParentStyle()->SvgStyle().Ry());
}
void Ry::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetRy(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // scale

CSSExposure Scale::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSIndependentTransformPropertiesEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Scale::GetPropertyName() const {
  return "scale";
}

const WTF::AtomicString& Scale::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scale"));
  return name;
}

const char* Scale::GetJSPropertyName() const {
  return "scale";
}


void Scale::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScale(ComputedStyleInitialValues::InitialScale());
}
void Scale::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScale(state.ParentStyle()->Scale());
}
void Scale::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScale(StyleBuilderConverter::ConvertScale(state, value));
}

 // scroll-behavior



const char* ScrollBehavior::GetPropertyName() const {
  return "scroll-behavior";
}

const WTF::AtomicString& ScrollBehavior::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-behavior"));
  return name;
}

const char* ScrollBehavior::GetJSPropertyName() const {
  return "scrollBehavior";
}


void ScrollBehavior::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollBehavior(ComputedStyleInitialValues::InitialScrollBehavior());
}
void ScrollBehavior::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollBehavior(state.ParentStyle()->GetScrollBehavior());
}
void ScrollBehavior::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollBehavior(To<CSSIdentifierValue>(value).ConvertTo<blink::mojom::blink::ScrollBehavior>());
}

 // scroll-customization

CSSExposure ScrollCustomization::Exposure() const {
  if (!RuntimeEnabledFeatures::ScrollCustomizationEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* ScrollCustomization::GetPropertyName() const {
  return "scroll-customization";
}

const WTF::AtomicString& ScrollCustomization::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-customization"));
  return name;
}

const char* ScrollCustomization::GetJSPropertyName() const {
  return "scrollCustomization";
}


void ScrollCustomization::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollCustomization(ComputedStyleInitialValues::InitialScrollCustomization());
}
void ScrollCustomization::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollCustomization(state.ParentStyle()->ScrollCustomization());
}
void ScrollCustomization::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollCustomization(StyleBuilderConverter::ConvertFlags<blink::scroll_customization::ScrollDirection>(state, value));
}

 // scroll-margin-block-end



const char* ScrollMarginBlockEnd::GetPropertyName() const {
  return "scroll-margin-block-end";
}

const WTF::AtomicString& ScrollMarginBlockEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-block-end"));
  return name;
}

const char* ScrollMarginBlockEnd::GetJSPropertyName() const {
  return "scrollMarginBlockEnd";
}

const CSSProperty* ScrollMarginBlockEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollMarginBlockEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollMarginGroup());
}

void ScrollMarginBlockEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollMarginBlockEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollMarginBlockEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-margin-block-start



const char* ScrollMarginBlockStart::GetPropertyName() const {
  return "scroll-margin-block-start";
}

const WTF::AtomicString& ScrollMarginBlockStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-block-start"));
  return name;
}

const char* ScrollMarginBlockStart::GetJSPropertyName() const {
  return "scrollMarginBlockStart";
}

const CSSProperty* ScrollMarginBlockStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollMarginBlockStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollMarginGroup());
}

void ScrollMarginBlockStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollMarginBlockStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollMarginBlockStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-margin-bottom



const char* ScrollMarginBottom::GetPropertyName() const {
  return "scroll-margin-bottom";
}

const WTF::AtomicString& ScrollMarginBottom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-bottom"));
  return name;
}

const char* ScrollMarginBottom::GetJSPropertyName() const {
  return "scrollMarginBottom";
}


void ScrollMarginBottom::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollMarginBottom(ComputedStyleInitialValues::InitialScrollMarginBottom());
}
void ScrollMarginBottom::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollMarginBottom(state.ParentStyle()->ScrollMarginBottom());
}
void ScrollMarginBottom::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollMarginBottom(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

 // scroll-margin-inline-end



const char* ScrollMarginInlineEnd::GetPropertyName() const {
  return "scroll-margin-inline-end";
}

const WTF::AtomicString& ScrollMarginInlineEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-inline-end"));
  return name;
}

const char* ScrollMarginInlineEnd::GetJSPropertyName() const {
  return "scrollMarginInlineEnd";
}

const CSSProperty* ScrollMarginInlineEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollMarginInlineEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollMarginGroup());
}

void ScrollMarginInlineEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollMarginInlineEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollMarginInlineEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-margin-inline-start



const char* ScrollMarginInlineStart::GetPropertyName() const {
  return "scroll-margin-inline-start";
}

const WTF::AtomicString& ScrollMarginInlineStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-inline-start"));
  return name;
}

const char* ScrollMarginInlineStart::GetJSPropertyName() const {
  return "scrollMarginInlineStart";
}

const CSSProperty* ScrollMarginInlineStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollMarginInlineStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollMarginGroup());
}

void ScrollMarginInlineStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollMarginInlineStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollMarginInlineStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-margin-left



const char* ScrollMarginLeft::GetPropertyName() const {
  return "scroll-margin-left";
}

const WTF::AtomicString& ScrollMarginLeft::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-left"));
  return name;
}

const char* ScrollMarginLeft::GetJSPropertyName() const {
  return "scrollMarginLeft";
}


void ScrollMarginLeft::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollMarginLeft(ComputedStyleInitialValues::InitialScrollMarginLeft());
}
void ScrollMarginLeft::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollMarginLeft(state.ParentStyle()->ScrollMarginLeft());
}
void ScrollMarginLeft::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollMarginLeft(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

 // scroll-margin-right



const char* ScrollMarginRight::GetPropertyName() const {
  return "scroll-margin-right";
}

const WTF::AtomicString& ScrollMarginRight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-right"));
  return name;
}

const char* ScrollMarginRight::GetJSPropertyName() const {
  return "scrollMarginRight";
}


void ScrollMarginRight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollMarginRight(ComputedStyleInitialValues::InitialScrollMarginRight());
}
void ScrollMarginRight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollMarginRight(state.ParentStyle()->ScrollMarginRight());
}
void ScrollMarginRight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollMarginRight(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

 // scroll-margin-top



const char* ScrollMarginTop::GetPropertyName() const {
  return "scroll-margin-top";
}

const WTF::AtomicString& ScrollMarginTop::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-top"));
  return name;
}

const char* ScrollMarginTop::GetJSPropertyName() const {
  return "scrollMarginTop";
}


void ScrollMarginTop::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollMarginTop(ComputedStyleInitialValues::InitialScrollMarginTop());
}
void ScrollMarginTop::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollMarginTop(state.ParentStyle()->ScrollMarginTop());
}
void ScrollMarginTop::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollMarginTop(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

 // scroll-padding-block-end



const char* ScrollPaddingBlockEnd::GetPropertyName() const {
  return "scroll-padding-block-end";
}

const WTF::AtomicString& ScrollPaddingBlockEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-block-end"));
  return name;
}

const char* ScrollPaddingBlockEnd::GetJSPropertyName() const {
  return "scrollPaddingBlockEnd";
}

const CSSProperty* ScrollPaddingBlockEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollPaddingBlockEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockEnd(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollPaddingGroup());
}

void ScrollPaddingBlockEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollPaddingBlockEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollPaddingBlockEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-padding-block-start



const char* ScrollPaddingBlockStart::GetPropertyName() const {
  return "scroll-padding-block-start";
}

const WTF::AtomicString& ScrollPaddingBlockStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-block-start"));
  return name;
}

const char* ScrollPaddingBlockStart::GetJSPropertyName() const {
  return "scrollPaddingBlockStart";
}

const CSSProperty* ScrollPaddingBlockStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollPaddingBlockStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveBlockStart(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollPaddingGroup());
}

void ScrollPaddingBlockStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollPaddingBlockStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollPaddingBlockStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-padding-bottom



const char* ScrollPaddingBottom::GetPropertyName() const {
  return "scroll-padding-bottom";
}

const WTF::AtomicString& ScrollPaddingBottom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-bottom"));
  return name;
}

const char* ScrollPaddingBottom::GetJSPropertyName() const {
  return "scrollPaddingBottom";
}


void ScrollPaddingBottom::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingBottom(ComputedStyleInitialValues::InitialScrollPaddingBottom());
}
void ScrollPaddingBottom::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingBottom(state.ParentStyle()->ScrollPaddingBottom());
}
void ScrollPaddingBottom::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollPaddingBottom(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // scroll-padding-inline-end



const char* ScrollPaddingInlineEnd::GetPropertyName() const {
  return "scroll-padding-inline-end";
}

const WTF::AtomicString& ScrollPaddingInlineEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-inline-end"));
  return name;
}

const char* ScrollPaddingInlineEnd::GetJSPropertyName() const {
  return "scrollPaddingInlineEnd";
}

const CSSProperty* ScrollPaddingInlineEnd::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollPaddingInlineEnd::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineEnd(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollPaddingGroup());
}

void ScrollPaddingInlineEnd::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollPaddingInlineEnd::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollPaddingInlineEnd::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-padding-inline-start



const char* ScrollPaddingInlineStart::GetPropertyName() const {
  return "scroll-padding-inline-start";
}

const WTF::AtomicString& ScrollPaddingInlineStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-inline-start"));
  return name;
}

const char* ScrollPaddingInlineStart::GetJSPropertyName() const {
  return "scrollPaddingInlineStart";
}

const CSSProperty* ScrollPaddingInlineStart::SurrogateFor(TextDirection direction,
    blink::WritingMode writing_mode) const {
  return &ResolveDirectionAwareProperty(direction, writing_mode);
}

const CSSProperty& ScrollPaddingInlineStart::ResolveDirectionAwareProperty(
    TextDirection direction,
    blink::WritingMode writing_mode) const {
  return CSSDirectionAwareResolver::ResolveInlineStart(direction, writing_mode,
      CSSDirectionAwareResolver::ScrollPaddingGroup());
}

void ScrollPaddingInlineStart::ApplyInitial(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInitial(state);
}
void ScrollPaddingInlineStart::ApplyInherit(StyleResolverState& state) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyInherit(state);
}
void ScrollPaddingInlineStart::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  const CSSProperty& resolved_property =
      ResolveDirectionAwareProperty(state.Style()->Direction(),
                                    state.Style()->GetWritingMode());
  DCHECK(!resolved_property.IDEquals(PropertyID()));
  To<Longhand>(resolved_property).ApplyValue(state, value);
}

 // scroll-padding-left



const char* ScrollPaddingLeft::GetPropertyName() const {
  return "scroll-padding-left";
}

const WTF::AtomicString& ScrollPaddingLeft::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-left"));
  return name;
}

const char* ScrollPaddingLeft::GetJSPropertyName() const {
  return "scrollPaddingLeft";
}


void ScrollPaddingLeft::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingLeft(ComputedStyleInitialValues::InitialScrollPaddingLeft());
}
void ScrollPaddingLeft::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingLeft(state.ParentStyle()->ScrollPaddingLeft());
}
void ScrollPaddingLeft::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollPaddingLeft(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // scroll-padding-right



const char* ScrollPaddingRight::GetPropertyName() const {
  return "scroll-padding-right";
}

const WTF::AtomicString& ScrollPaddingRight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-right"));
  return name;
}

const char* ScrollPaddingRight::GetJSPropertyName() const {
  return "scrollPaddingRight";
}


void ScrollPaddingRight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingRight(ComputedStyleInitialValues::InitialScrollPaddingRight());
}
void ScrollPaddingRight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingRight(state.ParentStyle()->ScrollPaddingRight());
}
void ScrollPaddingRight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollPaddingRight(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // scroll-padding-top



const char* ScrollPaddingTop::GetPropertyName() const {
  return "scroll-padding-top";
}

const WTF::AtomicString& ScrollPaddingTop::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-top"));
  return name;
}

const char* ScrollPaddingTop::GetJSPropertyName() const {
  return "scrollPaddingTop";
}


void ScrollPaddingTop::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingTop(ComputedStyleInitialValues::InitialScrollPaddingTop());
}
void ScrollPaddingTop::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollPaddingTop(state.ParentStyle()->ScrollPaddingTop());
}
void ScrollPaddingTop::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollPaddingTop(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // scroll-snap-align



const char* ScrollSnapAlign::GetPropertyName() const {
  return "scroll-snap-align";
}

const WTF::AtomicString& ScrollSnapAlign::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-snap-align"));
  return name;
}

const char* ScrollSnapAlign::GetJSPropertyName() const {
  return "scrollSnapAlign";
}


void ScrollSnapAlign::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollSnapAlign(ComputedStyleInitialValues::InitialScrollSnapAlign());
}
void ScrollSnapAlign::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollSnapAlign(state.ParentStyle()->GetScrollSnapAlign());
}
void ScrollSnapAlign::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollSnapAlign(StyleBuilderConverter::ConvertSnapAlign(state, value));
}

 // scroll-snap-stop



const char* ScrollSnapStop::GetPropertyName() const {
  return "scroll-snap-stop";
}

const WTF::AtomicString& ScrollSnapStop::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-snap-stop"));
  return name;
}

const char* ScrollSnapStop::GetJSPropertyName() const {
  return "scrollSnapStop";
}


void ScrollSnapStop::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollSnapStop(ComputedStyleInitialValues::InitialScrollSnapStop());
}
void ScrollSnapStop::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollSnapStop(state.ParentStyle()->ScrollSnapStop());
}
void ScrollSnapStop::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollSnapStop(To<CSSIdentifierValue>(value).ConvertTo<blink::EScrollSnapStop>());
}

 // scroll-snap-type



const char* ScrollSnapType::GetPropertyName() const {
  return "scroll-snap-type";
}

const WTF::AtomicString& ScrollSnapType::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-snap-type"));
  return name;
}

const char* ScrollSnapType::GetJSPropertyName() const {
  return "scrollSnapType";
}


void ScrollSnapType::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetScrollSnapType(ComputedStyleInitialValues::InitialScrollSnapType());
}
void ScrollSnapType::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetScrollSnapType(state.ParentStyle()->GetScrollSnapType());
}
void ScrollSnapType::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetScrollSnapType(StyleBuilderConverter::ConvertSnapType(state, value));
}

 // shape-image-threshold



const char* ShapeImageThreshold::GetPropertyName() const {
  return "shape-image-threshold";
}

const WTF::AtomicString& ShapeImageThreshold::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-image-threshold"));
  return name;
}

const char* ShapeImageThreshold::GetJSPropertyName() const {
  return "shapeImageThreshold";
}


void ShapeImageThreshold::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetShapeImageThreshold(ComputedStyleInitialValues::InitialShapeImageThreshold());
}
void ShapeImageThreshold::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetShapeImageThreshold(state.ParentStyle()->ShapeImageThreshold());
}
void ShapeImageThreshold::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetShapeImageThreshold(To<CSSPrimitiveValue>(value).ConvertTo<float>());
}

 // shape-margin



const char* ShapeMargin::GetPropertyName() const {
  return "shape-margin";
}

const WTF::AtomicString& ShapeMargin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-margin"));
  return name;
}

const char* ShapeMargin::GetJSPropertyName() const {
  return "shapeMargin";
}


void ShapeMargin::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetShapeMargin(ComputedStyleInitialValues::InitialShapeMargin());
}
void ShapeMargin::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetShapeMargin(state.ParentStyle()->ShapeMargin());
}
void ShapeMargin::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetShapeMargin(StyleBuilderConverter::ConvertLength(state, value));
}

 // shape-outside



const char* ShapeOutside::GetPropertyName() const {
  return "shape-outside";
}

const WTF::AtomicString& ShapeOutside::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-outside"));
  return name;
}

const char* ShapeOutside::GetJSPropertyName() const {
  return "shapeOutside";
}


void ShapeOutside::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetShapeOutside(ComputedStyleInitialValues::InitialShapeOutside());
}
void ShapeOutside::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetShapeOutside(state.ParentStyle()->ShapeOutside());
}
void ShapeOutside::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetShapeOutside(StyleBuilderConverter::ConvertShapeValue(state, value));
}

 // shape-rendering



const char* ShapeRendering::GetPropertyName() const {
  return "shape-rendering";
}

const WTF::AtomicString& ShapeRendering::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-rendering"));
  return name;
}

const char* ShapeRendering::GetJSPropertyName() const {
  return "shapeRendering";
}


void ShapeRendering::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetShapeRendering(SVGComputedStyle::InitialShapeRendering());
}
void ShapeRendering::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetShapeRendering(state.ParentStyle()->SvgStyle().ShapeRendering());
}
void ShapeRendering::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetShapeRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EShapeRendering>());
}

 // size



const char* Size::GetPropertyName() const {
  return "size";
}

const WTF::AtomicString& Size::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("size"));
  return name;
}

const char* Size::GetJSPropertyName() const {
  return "size";
}



 // source

CSSExposure Source::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSScrollTimelineEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Source::GetPropertyName() const {
  return "source";
}

const WTF::AtomicString& Source::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("source"));
  return name;
}

const char* Source::GetJSPropertyName() const {
  return "source";
}



 // speak



const char* Speak::GetPropertyName() const {
  return "speak";
}

const WTF::AtomicString& Speak::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("speak"));
  return name;
}

const char* Speak::GetJSPropertyName() const {
  return "speak";
}


void Speak::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetSpeak(ComputedStyleInitialValues::InitialSpeak());
}
void Speak::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetSpeak(state.ParentStyle()->Speak());
}
void Speak::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetSpeak(To<CSSIdentifierValue>(value).ConvertTo<blink::ESpeak>());
}

 // src



const char* Src::GetPropertyName() const {
  return "src";
}

const WTF::AtomicString& Src::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("src"));
  return name;
}

const char* Src::GetJSPropertyName() const {
  return "src";
}



 // start

CSSExposure Start::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSScrollTimelineEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Start::GetPropertyName() const {
  return "start";
}

const WTF::AtomicString& Start::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("start"));
  return name;
}

const char* Start::GetJSPropertyName() const {
  return "start";
}



 // stop-color



const char* StopColor::GetPropertyName() const {
  return "stop-color";
}

const WTF::AtomicString& StopColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stop-color"));
  return name;
}

const char* StopColor::GetJSPropertyName() const {
  return "stopColor";
}


void StopColor::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStopColor(SVGComputedStyle::InitialStopColor());
}
void StopColor::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStopColor(state.ParentStyle()->SvgStyle().StopColor());
}
void StopColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStopColor(StyleBuilderConverter::ConvertStyleColor(state, value));
}

 // stop-opacity



const char* StopOpacity::GetPropertyName() const {
  return "stop-opacity";
}

const WTF::AtomicString& StopOpacity::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stop-opacity"));
  return name;
}

const char* StopOpacity::GetJSPropertyName() const {
  return "stopOpacity";
}


void StopOpacity::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStopOpacity(SVGComputedStyle::InitialStopOpacity());
}
void StopOpacity::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStopOpacity(state.ParentStyle()->SvgStyle().StopOpacity());
}
void StopOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStopOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

 // stroke



const char* Stroke::GetPropertyName() const {
  return "stroke";
}

const WTF::AtomicString& Stroke::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke"));
  return name;
}

const char* Stroke::GetJSPropertyName() const {
  return "stroke";
}
const CSSProperty* Stroke::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedStroke();
}


void Stroke::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokePaint(SVGComputedStyle::InitialStrokePaint());
}
void Stroke::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokePaint(state.ParentStyle()->SvgStyle().StrokePaint());
}
void Stroke::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStrokePaint(StyleBuilderConverter::ConvertSVGPaint(state, value));
}

 // stroke-dasharray



const char* StrokeDasharray::GetPropertyName() const {
  return "stroke-dasharray";
}

const WTF::AtomicString& StrokeDasharray::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-dasharray"));
  return name;
}

const char* StrokeDasharray::GetJSPropertyName() const {
  return "strokeDasharray";
}


void StrokeDasharray::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeDashArray(SVGComputedStyle::InitialStrokeDashArray());
}
void StrokeDasharray::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeDashArray(state.ParentStyle()->SvgStyle().StrokeDashArray());
}
void StrokeDasharray::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStrokeDashArray(StyleBuilderConverter::ConvertStrokeDasharray(state, value));
}

 // stroke-dashoffset



const char* StrokeDashoffset::GetPropertyName() const {
  return "stroke-dashoffset";
}

const WTF::AtomicString& StrokeDashoffset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-dashoffset"));
  return name;
}

const char* StrokeDashoffset::GetJSPropertyName() const {
  return "strokeDashoffset";
}


void StrokeDashoffset::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeDashOffset(SVGComputedStyle::InitialStrokeDashOffset());
}
void StrokeDashoffset::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeDashOffset(state.ParentStyle()->SvgStyle().StrokeDashOffset());
}
void StrokeDashoffset::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStrokeDashOffset(StyleBuilderConverter::ConvertLength(state, value));
}

 // stroke-linecap



const char* StrokeLinecap::GetPropertyName() const {
  return "stroke-linecap";
}

const WTF::AtomicString& StrokeLinecap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-linecap"));
  return name;
}

const char* StrokeLinecap::GetJSPropertyName() const {
  return "strokeLinecap";
}


void StrokeLinecap::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetCapStyle(SVGComputedStyle::InitialCapStyle());
}
void StrokeLinecap::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetCapStyle(state.ParentStyle()->SvgStyle().CapStyle());
}
void StrokeLinecap::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetCapStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::LineCap>());
}

 // stroke-linejoin



const char* StrokeLinejoin::GetPropertyName() const {
  return "stroke-linejoin";
}

const WTF::AtomicString& StrokeLinejoin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-linejoin"));
  return name;
}

const char* StrokeLinejoin::GetJSPropertyName() const {
  return "strokeLinejoin";
}


void StrokeLinejoin::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetJoinStyle(SVGComputedStyle::InitialJoinStyle());
}
void StrokeLinejoin::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetJoinStyle(state.ParentStyle()->SvgStyle().JoinStyle());
}
void StrokeLinejoin::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetJoinStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::LineJoin>());
}

 // stroke-miterlimit



const char* StrokeMiterlimit::GetPropertyName() const {
  return "stroke-miterlimit";
}

const WTF::AtomicString& StrokeMiterlimit::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-miterlimit"));
  return name;
}

const char* StrokeMiterlimit::GetJSPropertyName() const {
  return "strokeMiterlimit";
}


void StrokeMiterlimit::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeMiterLimit(SVGComputedStyle::InitialStrokeMiterLimit());
}
void StrokeMiterlimit::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeMiterLimit(state.ParentStyle()->SvgStyle().StrokeMiterLimit());
}
void StrokeMiterlimit::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStrokeMiterLimit(To<CSSPrimitiveValue>(value).ConvertTo<float>());
}

 // stroke-opacity



const char* StrokeOpacity::GetPropertyName() const {
  return "stroke-opacity";
}

const WTF::AtomicString& StrokeOpacity::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-opacity"));
  return name;
}

const char* StrokeOpacity::GetJSPropertyName() const {
  return "strokeOpacity";
}


void StrokeOpacity::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeOpacity(SVGComputedStyle::InitialStrokeOpacity());
}
void StrokeOpacity::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeOpacity(state.ParentStyle()->SvgStyle().StrokeOpacity());
}
void StrokeOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStrokeOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

 // stroke-width



const char* StrokeWidth::GetPropertyName() const {
  return "stroke-width";
}

const WTF::AtomicString& StrokeWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-width"));
  return name;
}

const char* StrokeWidth::GetJSPropertyName() const {
  return "strokeWidth";
}


void StrokeWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeWidth(SVGComputedStyle::InitialStrokeWidth());
}
void StrokeWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetStrokeWidth(state.ParentStyle()->SvgStyle().StrokeWidth());
}
void StrokeWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetStrokeWidth(StyleBuilderConverter::ConvertUnzoomedLength(state, value));
}

 // syntax

CSSExposure Syntax::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSVariables2AtPropertyEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Syntax::GetPropertyName() const {
  return "syntax";
}

const WTF::AtomicString& Syntax::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("syntax"));
  return name;
}

const char* Syntax::GetJSPropertyName() const {
  return "syntax";
}



 // tab-size



const char* TabSize::GetPropertyName() const {
  return "tab-size";
}

const WTF::AtomicString& TabSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("tab-size"));
  return name;
}

const char* TabSize::GetJSPropertyName() const {
  return "tabSize";
}


void TabSize::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTabSize(ComputedStyleInitialValues::InitialTabSize());
}
void TabSize::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTabSize(state.ParentStyle()->GetTabSize());
}
void TabSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTabSize(StyleBuilderConverter::ConvertLengthOrTabSpaces(state, value));
}

 // table-layout



const char* TableLayout::GetPropertyName() const {
  return "table-layout";
}

const WTF::AtomicString& TableLayout::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("table-layout"));
  return name;
}

const char* TableLayout::GetJSPropertyName() const {
  return "tableLayout";
}


void TableLayout::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTableLayout(ComputedStyleInitialValues::InitialTableLayout());
}
void TableLayout::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTableLayout(state.ParentStyle()->TableLayout());
}
void TableLayout::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTableLayout(To<CSSIdentifierValue>(value).ConvertTo<blink::ETableLayout>());
}

 // text-align



const char* TextAlign::GetPropertyName() const {
  return "text-align";
}

const WTF::AtomicString& TextAlign::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-align"));
  return name;
}

const char* TextAlign::GetJSPropertyName() const {
  return "textAlign";
}


void TextAlign::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextAlign(ComputedStyleInitialValues::InitialTextAlign());
}
void TextAlign::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextAlign(state.ParentStyle()->GetTextAlign());
}

 // text-align-last



const char* TextAlignLast::GetPropertyName() const {
  return "text-align-last";
}

const WTF::AtomicString& TextAlignLast::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-align-last"));
  return name;
}

const char* TextAlignLast::GetJSPropertyName() const {
  return "textAlignLast";
}


void TextAlignLast::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextAlignLast(ComputedStyleInitialValues::InitialTextAlignLast());
}
void TextAlignLast::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextAlignLast(state.ParentStyle()->TextAlignLast());
}
void TextAlignLast::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextAlignLast(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextAlignLast>());
}

 // text-anchor



const char* TextAnchor::GetPropertyName() const {
  return "text-anchor";
}

const WTF::AtomicString& TextAnchor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-anchor"));
  return name;
}

const char* TextAnchor::GetJSPropertyName() const {
  return "textAnchor";
}


void TextAnchor::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetTextAnchor(SVGComputedStyle::InitialTextAnchor());
}
void TextAnchor::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetTextAnchor(state.ParentStyle()->SvgStyle().TextAnchor());
}
void TextAnchor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetTextAnchor(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextAnchor>());
}

 // text-combine-upright



const char* TextCombineUpright::GetPropertyName() const {
  return "text-combine-upright";
}

const WTF::AtomicString& TextCombineUpright::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-combine-upright"));
  return name;
}

const char* TextCombineUpright::GetJSPropertyName() const {
  return "textCombineUpright";
}


void TextCombineUpright::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextCombine(ComputedStyleInitialValues::InitialTextCombine());
}
void TextCombineUpright::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextCombine(state.ParentStyle()->TextCombine());
}
void TextCombineUpright::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextCombine(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextCombine>());
}

 // text-decoration-color



const char* TextDecorationColor::GetPropertyName() const {
  return "text-decoration-color";
}

const WTF::AtomicString& TextDecorationColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-color"));
  return name;
}

const char* TextDecorationColor::GetJSPropertyName() const {
  return "textDecorationColor";
}
const CSSProperty* TextDecorationColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedTextDecorationColor();
}

bool TextDecorationColor::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.TextDecorationColor() == b.TextDecorationColor();
}

void TextDecorationColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetTextDecorationColor(color);
}

void TextDecorationColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextDecorationColor();
  state.Style()->SetTextDecorationColor(color);
}

void TextDecorationColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextDecorationColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // text-decoration-line



const char* TextDecorationLine::GetPropertyName() const {
  return "text-decoration-line";
}

const WTF::AtomicString& TextDecorationLine::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-line"));
  return name;
}

const char* TextDecorationLine::GetJSPropertyName() const {
  return "textDecorationLine";
}

bool TextDecorationLine::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.GetTextDecoration() == b.GetTextDecoration();
}

void TextDecorationLine::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextDecoration(ComputedStyleInitialValues::InitialTextDecoration());
}
void TextDecorationLine::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextDecoration(state.ParentStyle()->GetTextDecoration());
}
void TextDecorationLine::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextDecoration(StyleBuilderConverter::ConvertFlags<TextDecoration>(state, value));
}

 // text-decoration-skip-ink



const char* TextDecorationSkipInk::GetPropertyName() const {
  return "text-decoration-skip-ink";
}

const WTF::AtomicString& TextDecorationSkipInk::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-skip-ink"));
  return name;
}

const char* TextDecorationSkipInk::GetJSPropertyName() const {
  return "textDecorationSkipInk";
}

bool TextDecorationSkipInk::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.TextDecorationSkipInk() == b.TextDecorationSkipInk();
}

void TextDecorationSkipInk::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextDecorationSkipInk(ComputedStyleInitialValues::InitialTextDecorationSkipInk());
}
void TextDecorationSkipInk::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextDecorationSkipInk(state.ParentStyle()->TextDecorationSkipInk());
}
void TextDecorationSkipInk::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextDecorationSkipInk(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextDecorationSkipInk>());
}

 // text-decoration-style



const char* TextDecorationStyle::GetPropertyName() const {
  return "text-decoration-style";
}

const WTF::AtomicString& TextDecorationStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-style"));
  return name;
}

const char* TextDecorationStyle::GetJSPropertyName() const {
  return "textDecorationStyle";
}

bool TextDecorationStyle::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.TextDecorationStyle() == b.TextDecorationStyle();
}

void TextDecorationStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextDecorationStyle(ComputedStyleInitialValues::InitialTextDecorationStyle());
}
void TextDecorationStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextDecorationStyle(state.ParentStyle()->TextDecorationStyle());
}
void TextDecorationStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextDecorationStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextDecorationStyle>());
}

 // text-decoration-thickness

CSSExposure TextDecorationThickness::Exposure() const {
  if (!RuntimeEnabledFeatures::UnderlineOffsetThicknessEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* TextDecorationThickness::GetPropertyName() const {
  return "text-decoration-thickness";
}

const WTF::AtomicString& TextDecorationThickness::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-thickness"));
  return name;
}

const char* TextDecorationThickness::GetJSPropertyName() const {
  return "textDecorationThickness";
}

bool TextDecorationThickness::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.GetTextDecorationThickness() == b.GetTextDecorationThickness();
}

void TextDecorationThickness::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextDecorationThickness(ComputedStyleInitialValues::InitialTextDecorationThickness());
}
void TextDecorationThickness::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextDecorationThickness(state.ParentStyle()->GetTextDecorationThickness());
}
void TextDecorationThickness::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextDecorationThickness(StyleBuilderConverter::ConvertTextDecorationThickness(state, value));
}

 // text-indent



const char* TextIndent::GetPropertyName() const {
  return "text-indent";
}

const WTF::AtomicString& TextIndent::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-indent"));
  return name;
}

const char* TextIndent::GetJSPropertyName() const {
  return "textIndent";
}



 // text-justify

CSSExposure TextJustify::Exposure() const {
  if (!RuntimeEnabledFeatures::CSS3TextEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* TextJustify::GetPropertyName() const {
  return "text-justify";
}

const WTF::AtomicString& TextJustify::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-justify"));
  return name;
}

const char* TextJustify::GetJSPropertyName() const {
  return "textJustify";
}


void TextJustify::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextJustify(ComputedStyleInitialValues::InitialTextJustify());
}
void TextJustify::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextJustify(state.ParentStyle()->GetTextJustify());
}
void TextJustify::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextJustify(To<CSSIdentifierValue>(value).ConvertTo<blink::TextJustify>());
}

 // text-overflow



const char* TextOverflow::GetPropertyName() const {
  return "text-overflow";
}

const WTF::AtomicString& TextOverflow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-overflow"));
  return name;
}

const char* TextOverflow::GetJSPropertyName() const {
  return "textOverflow";
}


void TextOverflow::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextOverflow(ComputedStyleInitialValues::InitialTextOverflow());
}
void TextOverflow::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextOverflow(state.ParentStyle()->TextOverflow());
}
void TextOverflow::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextOverflow(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextOverflow>());
}

 // text-shadow



const char* TextShadow::GetPropertyName() const {
  return "text-shadow";
}

const WTF::AtomicString& TextShadow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-shadow"));
  return name;
}

const char* TextShadow::GetJSPropertyName() const {
  return "textShadow";
}


void TextShadow::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextShadow(ComputedStyleInitialValues::InitialTextShadow());
}
void TextShadow::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextShadow(state.ParentStyle()->TextShadow());
}
void TextShadow::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextShadow(StyleBuilderConverter::ConvertShadowList(state, value));
}

 // text-size-adjust



const char* TextSizeAdjust::GetPropertyName() const {
  return "text-size-adjust";
}

const WTF::AtomicString& TextSizeAdjust::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-size-adjust"));
  return name;
}

const char* TextSizeAdjust::GetJSPropertyName() const {
  return "textSizeAdjust";
}


void TextSizeAdjust::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextSizeAdjust(ComputedStyleInitialValues::InitialTextSizeAdjust());
}
void TextSizeAdjust::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextSizeAdjust(state.ParentStyle()->GetTextSizeAdjust());
}
void TextSizeAdjust::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextSizeAdjust(StyleBuilderConverter::ConvertTextSizeAdjust(state, value));
}

 // text-transform



const char* TextTransform::GetPropertyName() const {
  return "text-transform";
}

const WTF::AtomicString& TextTransform::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-transform"));
  return name;
}

const char* TextTransform::GetJSPropertyName() const {
  return "textTransform";
}


void TextTransform::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextTransform(ComputedStyleInitialValues::InitialTextTransform());
  state.Style()->SetTextTransformIsInherited(false);
}
void TextTransform::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextTransform(state.ParentStyle()->TextTransform());
  state.Style()->SetTextTransformIsInherited(true);
}
void TextTransform::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextTransform(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextTransform>());
  state.Style()->SetTextTransformIsInherited(false);
}

 // text-underline-offset

CSSExposure TextUnderlineOffset::Exposure() const {
  if (!RuntimeEnabledFeatures::UnderlineOffsetThicknessEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* TextUnderlineOffset::GetPropertyName() const {
  return "text-underline-offset";
}

const WTF::AtomicString& TextUnderlineOffset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-underline-offset"));
  return name;
}

const char* TextUnderlineOffset::GetJSPropertyName() const {
  return "textUnderlineOffset";
}


void TextUnderlineOffset::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextUnderlineOffset(ComputedStyleInitialValues::InitialTextUnderlineOffset());
}
void TextUnderlineOffset::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextUnderlineOffset(state.ParentStyle()->TextUnderlineOffset());
}
void TextUnderlineOffset::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextUnderlineOffset(StyleBuilderConverter::ConvertTextUnderlineOffset(state, value));
}

 // text-underline-position



const char* TextUnderlinePosition::GetPropertyName() const {
  return "text-underline-position";
}

const WTF::AtomicString& TextUnderlinePosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-underline-position"));
  return name;
}

const char* TextUnderlinePosition::GetJSPropertyName() const {
  return "textUnderlinePosition";
}


void TextUnderlinePosition::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextUnderlinePosition(ComputedStyleInitialValues::InitialTextUnderlinePosition());
}
void TextUnderlinePosition::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextUnderlinePosition(state.ParentStyle()->TextUnderlinePosition());
}
void TextUnderlinePosition::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextUnderlinePosition(StyleBuilderConverter::ConvertTextUnderlinePosition(state, value));
}

 // time-range

CSSExposure TimeRange::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSScrollTimelineEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* TimeRange::GetPropertyName() const {
  return "time-range";
}

const WTF::AtomicString& TimeRange::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("time-range"));
  return name;
}

const char* TimeRange::GetJSPropertyName() const {
  return "timeRange";
}



 // top



const char* Top::GetPropertyName() const {
  return "top";
}

const WTF::AtomicString& Top::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("top"));
  return name;
}

const char* Top::GetJSPropertyName() const {
  return "top";
}

bool Top::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.Top() == b.Top();
}

void Top::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTop(ComputedStyleInitialValues::InitialTop());
}
void Top::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTop(state.ParentStyle()->Top());
}
void Top::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTop(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

 // touch-action



const char* TouchAction::GetPropertyName() const {
  return "touch-action";
}

const WTF::AtomicString& TouchAction::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("touch-action"));
  return name;
}

const char* TouchAction::GetJSPropertyName() const {
  return "touchAction";
}


void TouchAction::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTouchAction(ComputedStyleInitialValues::InitialTouchAction());
}
void TouchAction::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTouchAction(state.ParentStyle()->GetTouchAction());
}
void TouchAction::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTouchAction(StyleBuilderConverter::ConvertFlags<blink::TouchAction>(state, value));
}

 // transform



const char* Transform::GetPropertyName() const {
  return "transform";
}

const WTF::AtomicString& Transform::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform"));
  return name;
}

const char* Transform::GetJSPropertyName() const {
  return "transform";
}


void Transform::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTransform(ComputedStyleInitialValues::InitialTransform());
}
void Transform::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTransform(state.ParentStyle()->Transform());
}
void Transform::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTransform(StyleBuilderConverter::ConvertTransformOperations(state, value));
}

 // transform-box



const char* TransformBox::GetPropertyName() const {
  return "transform-box";
}

const WTF::AtomicString& TransformBox::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform-box"));
  return name;
}

const char* TransformBox::GetJSPropertyName() const {
  return "transformBox";
}


void TransformBox::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTransformBox(ComputedStyleInitialValues::InitialTransformBox());
}
void TransformBox::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTransformBox(state.ParentStyle()->TransformBox());
}
void TransformBox::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTransformBox(To<CSSIdentifierValue>(value).ConvertTo<blink::ETransformBox>());
}

 // transform-origin



const char* TransformOrigin::GetPropertyName() const {
  return "transform-origin";
}

const WTF::AtomicString& TransformOrigin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform-origin"));
  return name;
}

const char* TransformOrigin::GetJSPropertyName() const {
  return "transformOrigin";
}


void TransformOrigin::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTransformOrigin(ComputedStyleInitialValues::InitialTransformOrigin());
}
void TransformOrigin::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTransformOrigin(state.ParentStyle()->GetTransformOrigin());
}
void TransformOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTransformOrigin(StyleBuilderConverter::ConvertTransformOrigin(state, value));
}

 // transform-style



const char* TransformStyle::GetPropertyName() const {
  return "transform-style";
}

const WTF::AtomicString& TransformStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform-style"));
  return name;
}

const char* TransformStyle::GetJSPropertyName() const {
  return "transformStyle";
}


void TransformStyle::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTransformStyle3D(ComputedStyleInitialValues::InitialTransformStyle3D());
}
void TransformStyle::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTransformStyle3D(state.ParentStyle()->TransformStyle3D());
}
void TransformStyle::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTransformStyle3D(To<CSSIdentifierValue>(value).ConvertTo<blink::ETransformStyle3D>());
}

 // translate

CSSExposure Translate::Exposure() const {
  if (!RuntimeEnabledFeatures::CSSIndependentTransformPropertiesEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* Translate::GetPropertyName() const {
  return "translate";
}

const WTF::AtomicString& Translate::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("translate"));
  return name;
}

const char* Translate::GetJSPropertyName() const {
  return "translate";
}


void Translate::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTranslate(ComputedStyleInitialValues::InitialTranslate());
}
void Translate::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTranslate(state.ParentStyle()->Translate());
}
void Translate::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTranslate(StyleBuilderConverter::ConvertTranslate(state, value));
}

 // unicode-bidi



const char* UnicodeBidi::GetPropertyName() const {
  return "unicode-bidi";
}

const WTF::AtomicString& UnicodeBidi::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("unicode-bidi"));
  return name;
}

const char* UnicodeBidi::GetJSPropertyName() const {
  return "unicodeBidi";
}


void UnicodeBidi::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetUnicodeBidi(ComputedStyleInitialValues::InitialUnicodeBidi());
}
void UnicodeBidi::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetUnicodeBidi(state.ParentStyle()->GetUnicodeBidi());
}
void UnicodeBidi::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetUnicodeBidi(To<CSSIdentifierValue>(value).ConvertTo<blink::UnicodeBidi>());
}

 // unicode-range



const char* UnicodeRange::GetPropertyName() const {
  return "unicode-range";
}

const WTF::AtomicString& UnicodeRange::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("unicode-range"));
  return name;
}

const char* UnicodeRange::GetJSPropertyName() const {
  return "unicodeRange";
}



 // user-select



const char* UserSelect::GetPropertyName() const {
  return "user-select";
}

const WTF::AtomicString& UserSelect::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("user-select"));
  return name;
}

const char* UserSelect::GetJSPropertyName() const {
  return "userSelect";
}


void UserSelect::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetUserSelect(ComputedStyleInitialValues::InitialUserSelect());
}
void UserSelect::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetUserSelect(state.ParentStyle()->UserSelect());
}
void UserSelect::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetUserSelect(To<CSSIdentifierValue>(value).ConvertTo<blink::EUserSelect>());
}

 // user-zoom



const char* UserZoom::GetPropertyName() const {
  return "user-zoom";
}

const WTF::AtomicString& UserZoom::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("user-zoom"));
  return name;
}

const char* UserZoom::GetJSPropertyName() const {
  return "userZoom";
}



 // vector-effect



const char* VectorEffect::GetPropertyName() const {
  return "vector-effect";
}

const WTF::AtomicString& VectorEffect::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("vector-effect"));
  return name;
}

const char* VectorEffect::GetJSPropertyName() const {
  return "vectorEffect";
}


void VectorEffect::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetVectorEffect(SVGComputedStyle::InitialVectorEffect());
}
void VectorEffect::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetVectorEffect(state.ParentStyle()->SvgStyle().VectorEffect());
}
void VectorEffect::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetVectorEffect(To<CSSIdentifierValue>(value).ConvertTo<blink::EVectorEffect>());
}

 // vertical-align



const char* VerticalAlign::GetPropertyName() const {
  return "vertical-align";
}

const WTF::AtomicString& VerticalAlign::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("vertical-align"));
  return name;
}

const char* VerticalAlign::GetJSPropertyName() const {
  return "verticalAlign";
}

bool VerticalAlign::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  if (!(a.VerticalAlign() == b.VerticalAlign()))
    return false;
  if (!(a.GetVerticalAlignLength() == b.GetVerticalAlignLength()))
    return false;
  return true;
}

void VerticalAlign::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetVerticalAlign(ComputedStyleInitialValues::InitialVerticalAlign());
}

 // viewport-fit

CSSExposure ViewportFit::Exposure() const {
  if (!RuntimeEnabledFeatures::DisplayCutoutAPIEnabled())
    return CSSExposure::kNone;
  return CSSExposure::kWeb;
}


const char* ViewportFit::GetPropertyName() const {
  return "viewport-fit";
}

const WTF::AtomicString& ViewportFit::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("viewport-fit"));
  return name;
}

const char* ViewportFit::GetJSPropertyName() const {
  return "viewportFit";
}



 // visibility



const char* Visibility::GetPropertyName() const {
  return "visibility";
}

const WTF::AtomicString& Visibility::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("visibility"));
  return name;
}

const char* Visibility::GetJSPropertyName() const {
  return "visibility";
}


void Visibility::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetVisibility(ComputedStyleInitialValues::InitialVisibility());
  state.Style()->SetVisibilityIsInherited(false);
}
void Visibility::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetVisibility(state.ParentStyle()->Visibility());
  state.Style()->SetVisibilityIsInherited(true);
}
void Visibility::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetVisibility(To<CSSIdentifierValue>(value).ConvertTo<blink::EVisibility>());
  state.Style()->SetVisibilityIsInherited(false);
}

 // -webkit-app-region



const char* WebkitAppRegion::GetPropertyName() const {
  return "-webkit-app-region";
}

const WTF::AtomicString& WebkitAppRegion::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-app-region"));
  return name;
}

const char* WebkitAppRegion::GetJSPropertyName() const {
  return "webkitAppRegion";
}



 // -webkit-border-horizontal-spacing



const char* WebkitBorderHorizontalSpacing::GetPropertyName() const {
  return "-webkit-border-horizontal-spacing";
}

const WTF::AtomicString& WebkitBorderHorizontalSpacing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-horizontal-spacing"));
  return name;
}

const char* WebkitBorderHorizontalSpacing::GetJSPropertyName() const {
  return "webkitBorderHorizontalSpacing";
}


void WebkitBorderHorizontalSpacing::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHorizontalBorderSpacing(ComputedStyleInitialValues::InitialHorizontalBorderSpacing());
}
void WebkitBorderHorizontalSpacing::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetHorizontalBorderSpacing(state.ParentStyle()->HorizontalBorderSpacing());
}
void WebkitBorderHorizontalSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetHorizontalBorderSpacing(StyleBuilderConverter::ConvertComputedLength<short>(state, value));
}

 // -webkit-border-image



const char* WebkitBorderImage::GetPropertyName() const {
  return "-webkit-border-image";
}

const WTF::AtomicString& WebkitBorderImage::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-image"));
  return name;
}

const char* WebkitBorderImage::GetJSPropertyName() const {
  return "webkitBorderImage";
}


void WebkitBorderImage::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBorderImage(ComputedStyleInitialValues::InitialBorderImage());
}
void WebkitBorderImage::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBorderImage(state.ParentStyle()->BorderImage());
}

 // -webkit-border-vertical-spacing



const char* WebkitBorderVerticalSpacing::GetPropertyName() const {
  return "-webkit-border-vertical-spacing";
}

const WTF::AtomicString& WebkitBorderVerticalSpacing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-vertical-spacing"));
  return name;
}

const char* WebkitBorderVerticalSpacing::GetJSPropertyName() const {
  return "webkitBorderVerticalSpacing";
}


void WebkitBorderVerticalSpacing::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetVerticalBorderSpacing(ComputedStyleInitialValues::InitialVerticalBorderSpacing());
}
void WebkitBorderVerticalSpacing::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetVerticalBorderSpacing(state.ParentStyle()->VerticalBorderSpacing());
}
void WebkitBorderVerticalSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetVerticalBorderSpacing(StyleBuilderConverter::ConvertComputedLength<short>(state, value));
}

 // -webkit-box-align



const char* WebkitBoxAlign::GetPropertyName() const {
  return "-webkit-box-align";
}

const WTF::AtomicString& WebkitBoxAlign::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-align"));
  return name;
}

const char* WebkitBoxAlign::GetJSPropertyName() const {
  return "webkitBoxAlign";
}


void WebkitBoxAlign::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxAlign(ComputedStyleInitialValues::InitialBoxAlign());
}
void WebkitBoxAlign::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxAlign(state.ParentStyle()->BoxAlign());
}
void WebkitBoxAlign::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxAlign(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxAlignment>());
}

 // -webkit-box-decoration-break



const char* WebkitBoxDecorationBreak::GetPropertyName() const {
  return "-webkit-box-decoration-break";
}

const WTF::AtomicString& WebkitBoxDecorationBreak::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-decoration-break"));
  return name;
}

const char* WebkitBoxDecorationBreak::GetJSPropertyName() const {
  return "webkitBoxDecorationBreak";
}


void WebkitBoxDecorationBreak::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxDecorationBreak(ComputedStyleInitialValues::InitialBoxDecorationBreak());
}
void WebkitBoxDecorationBreak::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxDecorationBreak(state.ParentStyle()->BoxDecorationBreak());
}
void WebkitBoxDecorationBreak::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxDecorationBreak(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxDecorationBreak>());
}

 // -webkit-box-direction



const char* WebkitBoxDirection::GetPropertyName() const {
  return "-webkit-box-direction";
}

const WTF::AtomicString& WebkitBoxDirection::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-direction"));
  return name;
}

const char* WebkitBoxDirection::GetJSPropertyName() const {
  return "webkitBoxDirection";
}


void WebkitBoxDirection::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxDirection(ComputedStyleInitialValues::InitialBoxDirection());
  state.Style()->SetBoxDirectionIsInherited(false);
}
void WebkitBoxDirection::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxDirection(state.ParentStyle()->BoxDirection());
  state.Style()->SetBoxDirectionIsInherited(true);
}
void WebkitBoxDirection::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxDirection(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxDirection>());
  state.Style()->SetBoxDirectionIsInherited(false);
}

 // -webkit-box-flex



const char* WebkitBoxFlex::GetPropertyName() const {
  return "-webkit-box-flex";
}

const WTF::AtomicString& WebkitBoxFlex::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-flex"));
  return name;
}

const char* WebkitBoxFlex::GetJSPropertyName() const {
  return "webkitBoxFlex";
}


void WebkitBoxFlex::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxFlex(ComputedStyleInitialValues::InitialBoxFlex());
}
void WebkitBoxFlex::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxFlex(state.ParentStyle()->BoxFlex());
}
void WebkitBoxFlex::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxFlex(To<CSSPrimitiveValue>(value).ConvertTo<float>());
}

 // -webkit-box-ordinal-group



const char* WebkitBoxOrdinalGroup::GetPropertyName() const {
  return "-webkit-box-ordinal-group";
}

const WTF::AtomicString& WebkitBoxOrdinalGroup::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-ordinal-group"));
  return name;
}

const char* WebkitBoxOrdinalGroup::GetJSPropertyName() const {
  return "webkitBoxOrdinalGroup";
}


void WebkitBoxOrdinalGroup::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxOrdinalGroup(ComputedStyleInitialValues::InitialBoxOrdinalGroup());
}
void WebkitBoxOrdinalGroup::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxOrdinalGroup(state.ParentStyle()->BoxOrdinalGroup());
}
void WebkitBoxOrdinalGroup::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxOrdinalGroup(To<CSSPrimitiveValue>(value).ConvertTo<unsigned>());
}

 // -webkit-box-orient



const char* WebkitBoxOrient::GetPropertyName() const {
  return "-webkit-box-orient";
}

const WTF::AtomicString& WebkitBoxOrient::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-orient"));
  return name;
}

const char* WebkitBoxOrient::GetJSPropertyName() const {
  return "webkitBoxOrient";
}


void WebkitBoxOrient::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxOrient(ComputedStyleInitialValues::InitialBoxOrient());
}
void WebkitBoxOrient::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxOrient(state.ParentStyle()->BoxOrient());
}
void WebkitBoxOrient::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxOrient(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxOrient>());
}

 // -webkit-box-pack



const char* WebkitBoxPack::GetPropertyName() const {
  return "-webkit-box-pack";
}

const WTF::AtomicString& WebkitBoxPack::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-pack"));
  return name;
}

const char* WebkitBoxPack::GetJSPropertyName() const {
  return "webkitBoxPack";
}


void WebkitBoxPack::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxPack(ComputedStyleInitialValues::InitialBoxPack());
}
void WebkitBoxPack::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxPack(state.ParentStyle()->BoxPack());
}
void WebkitBoxPack::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxPack(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxPack>());
}

 // -webkit-box-reflect



const char* WebkitBoxReflect::GetPropertyName() const {
  return "-webkit-box-reflect";
}

const WTF::AtomicString& WebkitBoxReflect::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-reflect"));
  return name;
}

const char* WebkitBoxReflect::GetJSPropertyName() const {
  return "webkitBoxReflect";
}


void WebkitBoxReflect::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetBoxReflect(ComputedStyleInitialValues::InitialBoxReflect());
}
void WebkitBoxReflect::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetBoxReflect(state.ParentStyle()->BoxReflect());
}
void WebkitBoxReflect::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetBoxReflect(StyleBuilderConverter::ConvertBoxReflect(state, value));
}

 // -webkit-font-size-delta



const char* WebkitFontSizeDelta::GetPropertyName() const {
  return "-webkit-font-size-delta";
}

const WTF::AtomicString& WebkitFontSizeDelta::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-font-size-delta"));
  return name;
}

const char* WebkitFontSizeDelta::GetJSPropertyName() const {
  return "webkitFontSizeDelta";
}


void WebkitFontSizeDelta::ApplyInitial(StyleResolverState& state) const {
  // Intentionally empty.
}
void WebkitFontSizeDelta::ApplyInherit(StyleResolverState& state) const {
  // Intentionally empty.
}
void WebkitFontSizeDelta::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  // Intentionally empty.
}

 // -webkit-highlight



const char* WebkitHighlight::GetPropertyName() const {
  return "-webkit-highlight";
}

const WTF::AtomicString& WebkitHighlight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-highlight"));
  return name;
}

const char* WebkitHighlight::GetJSPropertyName() const {
  return "webkitHighlight";
}


void WebkitHighlight::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHighlight(ComputedStyleInitialValues::InitialHighlight());
}
void WebkitHighlight::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetHighlight(state.ParentStyle()->Highlight());
}
void WebkitHighlight::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetHighlight(StyleBuilderConverter::ConvertString<CSSValueID::kNone>(state, value));
}

 // -webkit-hyphenate-character



const char* WebkitHyphenateCharacter::GetPropertyName() const {
  return "-webkit-hyphenate-character";
}

const WTF::AtomicString& WebkitHyphenateCharacter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-hyphenate-character"));
  return name;
}

const char* WebkitHyphenateCharacter::GetJSPropertyName() const {
  return "webkitHyphenateCharacter";
}


void WebkitHyphenateCharacter::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHyphenationString(ComputedStyleInitialValues::InitialHyphenationString());
}
void WebkitHyphenateCharacter::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetHyphenationString(state.ParentStyle()->HyphenationString());
}
void WebkitHyphenateCharacter::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetHyphenationString(StyleBuilderConverter::ConvertString<CSSValueID::kAuto>(state, value));
}

 // -webkit-line-break



const char* WebkitLineBreak::GetPropertyName() const {
  return "-webkit-line-break";
}

const WTF::AtomicString& WebkitLineBreak::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-line-break"));
  return name;
}

const char* WebkitLineBreak::GetJSPropertyName() const {
  return "webkitLineBreak";
}


void WebkitLineBreak::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetLineBreak(ComputedStyleInitialValues::InitialLineBreak());
}
void WebkitLineBreak::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetLineBreak(state.ParentStyle()->GetLineBreak());
}
void WebkitLineBreak::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetLineBreak(To<CSSIdentifierValue>(value).ConvertTo<blink::LineBreak>());
}

 // -webkit-line-clamp



const char* WebkitLineClamp::GetPropertyName() const {
  return "-webkit-line-clamp";
}

const WTF::AtomicString& WebkitLineClamp::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-line-clamp"));
  return name;
}

const char* WebkitLineClamp::GetJSPropertyName() const {
  return "webkitLineClamp";
}


void WebkitLineClamp::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetLineClamp(ComputedStyleInitialValues::InitialLineClamp());
}
void WebkitLineClamp::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetLineClamp(state.ParentStyle()->LineClamp());
}
void WebkitLineClamp::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetLineClamp(To<CSSPrimitiveValue>(value).ConvertTo<int>());
}

 // -webkit-mask-box-image-outset



const char* WebkitMaskBoxImageOutset::GetPropertyName() const {
  return "-webkit-mask-box-image-outset";
}

const WTF::AtomicString& WebkitMaskBoxImageOutset::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-outset"));
  return name;
}

const char* WebkitMaskBoxImageOutset::GetJSPropertyName() const {
  return "webkitMaskBoxImageOutset";
}


void WebkitMaskBoxImageOutset::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->MaskBoxImage();
  if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.Outset(),
                                       BorderImageLength(0)))
    return;
  NinePieceImage image(current_image);
  image.SetOutset(0);
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageOutset::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  image.CopyOutsetFrom(state.ParentStyle()->MaskBoxImage());
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageOutset::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  image.SetOutset(CSSToStyleMap::MapNinePieceImageQuad(state, value));
  state.Style()->SetMaskBoxImage(image);
}

 // -webkit-mask-box-image-repeat



const char* WebkitMaskBoxImageRepeat::GetPropertyName() const {
  return "-webkit-mask-box-image-repeat";
}

const WTF::AtomicString& WebkitMaskBoxImageRepeat::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-repeat"));
  return name;
}

const char* WebkitMaskBoxImageRepeat::GetJSPropertyName() const {
  return "webkitMaskBoxImageRepeat";
}


void WebkitMaskBoxImageRepeat::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->MaskBoxImage();
  if (current_image.HorizontalRule() == kStretchImageRule &&
      current_image.VerticalRule() == kStretchImageRule)
    return;
  NinePieceImage image(current_image);
  image.SetHorizontalRule(kStretchImageRule);
  image.SetVerticalRule(kStretchImageRule);
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageRepeat::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  image.CopyRepeatFrom(state.ParentStyle()->MaskBoxImage());
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageRepeat::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  CSSToStyleMap::MapNinePieceImageRepeat(state, value, image);
  state.Style()->SetMaskBoxImage(image);
}

 // -webkit-mask-box-image-slice



const char* WebkitMaskBoxImageSlice::GetPropertyName() const {
  return "-webkit-mask-box-image-slice";
}

const WTF::AtomicString& WebkitMaskBoxImageSlice::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-slice"));
  return name;
}

const char* WebkitMaskBoxImageSlice::GetJSPropertyName() const {
  return "webkitMaskBoxImageSlice";
}


void WebkitMaskBoxImageSlice::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->MaskBoxImage();
  // Masks have a different initial value for slices. Preserve the value of 0
  // for backwards compatibility.
  if (current_image.Fill() == true &&
      style_building_utils::LengthMatchesAllSides(current_image.ImageSlices(), Length::Fixed(0)))
    return;
  NinePieceImage image(current_image);
  image.SetImageSlices(LengthBox(Length::Fixed(0), Length::Fixed(0), Length::Fixed(0), Length::Fixed(0)));
  image.SetFill(true);
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageSlice::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  image.CopyImageSlicesFrom(state.ParentStyle()->MaskBoxImage());
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageSlice::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  CSSToStyleMap::MapNinePieceImageSlice(state, value, image);
  state.Style()->SetMaskBoxImage(image);
}

 // -webkit-mask-box-image-source



const char* WebkitMaskBoxImageSource::GetPropertyName() const {
  return "-webkit-mask-box-image-source";
}

const WTF::AtomicString& WebkitMaskBoxImageSource::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-source"));
  return name;
}

const char* WebkitMaskBoxImageSource::GetJSPropertyName() const {
  return "webkitMaskBoxImageSource";
}


void WebkitMaskBoxImageSource::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetMaskBoxImageSource(ComputedStyleInitialValues::InitialMaskBoxImageSource());
}
void WebkitMaskBoxImageSource::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetMaskBoxImageSource(state.ParentStyle()->MaskBoxImageSource());
}

 // -webkit-mask-box-image-width



const char* WebkitMaskBoxImageWidth::GetPropertyName() const {
  return "-webkit-mask-box-image-width";
}

const WTF::AtomicString& WebkitMaskBoxImageWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-width"));
  return name;
}

const char* WebkitMaskBoxImageWidth::GetJSPropertyName() const {
  return "webkitMaskBoxImageWidth";
}


void WebkitMaskBoxImageWidth::ApplyInitial(StyleResolverState& state) const {
  const NinePieceImage& current_image = state.Style()->MaskBoxImage();
  // Masks have a different initial value for widths. Preserve the value of
  // 'auto' for backwards compatibility.
  if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.BorderSlices(),
                                       BorderImageLength(Length::Auto())))
    return;
  NinePieceImage image(current_image);
  image.SetBorderSlices(Length::Auto());
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageWidth::ApplyInherit(StyleResolverState& state) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  image.CopyBorderSlicesFrom(state.ParentStyle()->MaskBoxImage());
  state.Style()->SetMaskBoxImage(image);
}
void WebkitMaskBoxImageWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  NinePieceImage image(state.Style()->MaskBoxImage());
  image.SetBorderSlices(CSSToStyleMap::MapNinePieceImageQuad(state, value));
  state.Style()->SetMaskBoxImage(image);
}

 // -webkit-mask-clip



const char* WebkitMaskClip::GetPropertyName() const {
  return "-webkit-mask-clip";
}

const WTF::AtomicString& WebkitMaskClip::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-clip"));
  return name;
}

const char* WebkitMaskClip::GetJSPropertyName() const {
  return "webkitMaskClip";
}


void WebkitMaskClip::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetClip(FillLayer::InitialFillClip(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearClip();
}

void WebkitMaskClip::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsClipSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetClip(curr_parent->Clip());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearClip();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskClip::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillClip(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillClip(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearClip();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-composite



const char* WebkitMaskComposite::GetPropertyName() const {
  return "-webkit-mask-composite";
}

const WTF::AtomicString& WebkitMaskComposite::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-composite"));
  return name;
}

const char* WebkitMaskComposite::GetJSPropertyName() const {
  return "webkitMaskComposite";
}


void WebkitMaskComposite::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetComposite(FillLayer::InitialFillComposite(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearComposite();
}

void WebkitMaskComposite::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsCompositeSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetComposite(curr_parent->Composite());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearComposite();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskComposite::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillComposite(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillComposite(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearComposite();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-image



const char* WebkitMaskImage::GetPropertyName() const {
  return "-webkit-mask-image";
}

const WTF::AtomicString& WebkitMaskImage::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-image"));
  return name;
}

const char* WebkitMaskImage::GetJSPropertyName() const {
  return "webkitMaskImage";
}


void WebkitMaskImage::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetImage(FillLayer::InitialFillImage(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearImage();
}

void WebkitMaskImage::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsImageSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetImage(curr_parent->GetImage());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearImage();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskImage::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillImage(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillImage(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearImage();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-origin



const char* WebkitMaskOrigin::GetPropertyName() const {
  return "-webkit-mask-origin";
}

const WTF::AtomicString& WebkitMaskOrigin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-origin"));
  return name;
}

const char* WebkitMaskOrigin::GetJSPropertyName() const {
  return "webkitMaskOrigin";
}


void WebkitMaskOrigin::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetOrigin(FillLayer::InitialFillOrigin(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearOrigin();
}

void WebkitMaskOrigin::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsOriginSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetOrigin(curr_parent->Origin());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearOrigin();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillOrigin(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillOrigin(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearOrigin();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-position-x



const char* WebkitMaskPositionX::GetPropertyName() const {
  return "-webkit-mask-position-x";
}

const WTF::AtomicString& WebkitMaskPositionX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-position-x"));
  return name;
}

const char* WebkitMaskPositionX::GetJSPropertyName() const {
  return "webkitMaskPositionX";
}


void WebkitMaskPositionX::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetPositionX(FillLayer::InitialFillPositionX(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearPositionX();
}

void WebkitMaskPositionX::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsPositionXSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetPositionX(curr_parent->PositionX());
    if (curr_parent->IsBackgroundXOriginSet())
      curr_child->SetBackgroundXOrigin(curr_parent->BackgroundXOrigin());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearPositionX();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskPositionX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillPositionX(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillPositionX(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearPositionX();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-position-y



const char* WebkitMaskPositionY::GetPropertyName() const {
  return "-webkit-mask-position-y";
}

const WTF::AtomicString& WebkitMaskPositionY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-position-y"));
  return name;
}

const char* WebkitMaskPositionY::GetJSPropertyName() const {
  return "webkitMaskPositionY";
}


void WebkitMaskPositionY::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetPositionY(FillLayer::InitialFillPositionY(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearPositionY();
}

void WebkitMaskPositionY::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsPositionYSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetPositionY(curr_parent->PositionY());
    if (curr_parent->IsBackgroundYOriginSet())
      curr_child->SetBackgroundYOrigin(curr_parent->BackgroundYOrigin());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearPositionY();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskPositionY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillPositionY(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillPositionY(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearPositionY();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-repeat-x



const char* WebkitMaskRepeatX::GetPropertyName() const {
  return "-webkit-mask-repeat-x";
}

const WTF::AtomicString& WebkitMaskRepeatX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-repeat-x"));
  return name;
}

const char* WebkitMaskRepeatX::GetJSPropertyName() const {
  return "webkitMaskRepeatX";
}


void WebkitMaskRepeatX::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetRepeatX(FillLayer::InitialFillRepeatX(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearRepeatX();
}

void WebkitMaskRepeatX::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsRepeatXSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetRepeatX(curr_parent->RepeatX());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearRepeatX();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskRepeatX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillRepeatX(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillRepeatX(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearRepeatX();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-repeat-y



const char* WebkitMaskRepeatY::GetPropertyName() const {
  return "-webkit-mask-repeat-y";
}

const WTF::AtomicString& WebkitMaskRepeatY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-repeat-y"));
  return name;
}

const char* WebkitMaskRepeatY::GetJSPropertyName() const {
  return "webkitMaskRepeatY";
}


void WebkitMaskRepeatY::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetRepeatY(FillLayer::InitialFillRepeatY(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearRepeatY();
}

void WebkitMaskRepeatY::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsRepeatYSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetRepeatY(curr_parent->RepeatY());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearRepeatY();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskRepeatY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillRepeatY(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillRepeatY(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearRepeatY();
    curr_child = curr_child->Next();
  }
}

 // -webkit-mask-size



const char* WebkitMaskSize::GetPropertyName() const {
  return "-webkit-mask-size";
}

const WTF::AtomicString& WebkitMaskSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-size"));
  return name;
}

const char* WebkitMaskSize::GetJSPropertyName() const {
  return "webkitMaskSize";
}


void WebkitMaskSize::ApplyInitial(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  curr_child->SetSize(FillLayer::InitialFillSize(EFillLayerType::kMask));
  for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
    curr_child->ClearSize();
}

void WebkitMaskSize::ApplyInherit(StyleResolverState& state) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
  while (curr_parent && curr_parent->IsSizeSet()) {
    if (!curr_child)
      curr_child = prev_child->EnsureNext();
    curr_child->SetSize(curr_parent->Size());
    prev_child = curr_child;
    curr_child = prev_child->Next();
    curr_parent = curr_parent->Next();
  }

  while (curr_child) {
    // Reset any remaining layers to not have the property set.
    curr_child->ClearSize();
    curr_child = curr_child->Next();
  }
}

void WebkitMaskSize::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  FillLayer* curr_child = &state.Style()->AccessMaskLayers();
  FillLayer* prev_child = 0;
  const auto* value_list = DynamicTo<CSSValueList>(value);
  if (value_list && !value.IsImageSetValue()) {
    // Walk each value and put it into a layer, creating new layers as needed.
    for (unsigned int i = 0; i < value_list->length(); i++) {
      if (!curr_child)
        curr_child = prev_child->EnsureNext();
      CSSToStyleMap::MapFillSize(state, curr_child, value_list->Item(i));
      prev_child = curr_child;
      curr_child = curr_child->Next();
    }
  } else {
    CSSToStyleMap::MapFillSize(state, curr_child, value);
    curr_child = curr_child->Next();
  }
  while (curr_child) {
    // Reset all remaining layers to not have the property set.
    curr_child->ClearSize();
    curr_child = curr_child->Next();
  }
}

 // -webkit-perspective-origin-x



const char* WebkitPerspectiveOriginX::GetPropertyName() const {
  return "-webkit-perspective-origin-x";
}

const WTF::AtomicString& WebkitPerspectiveOriginX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective-origin-x"));
  return name;
}

const char* WebkitPerspectiveOriginX::GetJSPropertyName() const {
  return "webkitPerspectiveOriginX";
}


void WebkitPerspectiveOriginX::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPerspectiveOriginX(ComputedStyleInitialValues::InitialPerspectiveOriginX());
}
void WebkitPerspectiveOriginX::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPerspectiveOriginX(state.ParentStyle()->PerspectiveOriginX());
}
void WebkitPerspectiveOriginX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPerspectiveOriginX(StyleBuilderConverter::ConvertLength(state, value));
}

 // -webkit-perspective-origin-y



const char* WebkitPerspectiveOriginY::GetPropertyName() const {
  return "-webkit-perspective-origin-y";
}

const WTF::AtomicString& WebkitPerspectiveOriginY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective-origin-y"));
  return name;
}

const char* WebkitPerspectiveOriginY::GetJSPropertyName() const {
  return "webkitPerspectiveOriginY";
}


void WebkitPerspectiveOriginY::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPerspectiveOriginY(ComputedStyleInitialValues::InitialPerspectiveOriginY());
}
void WebkitPerspectiveOriginY::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPerspectiveOriginY(state.ParentStyle()->PerspectiveOriginY());
}
void WebkitPerspectiveOriginY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPerspectiveOriginY(StyleBuilderConverter::ConvertLength(state, value));
}

 // -webkit-print-color-adjust



const char* WebkitPrintColorAdjust::GetPropertyName() const {
  return "-webkit-print-color-adjust";
}

const WTF::AtomicString& WebkitPrintColorAdjust::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-print-color-adjust"));
  return name;
}

const char* WebkitPrintColorAdjust::GetJSPropertyName() const {
  return "webkitPrintColorAdjust";
}


void WebkitPrintColorAdjust::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetPrintColorAdjust(ComputedStyleInitialValues::InitialPrintColorAdjust());
  state.Style()->SetPrintColorAdjustIsInherited(false);
}
void WebkitPrintColorAdjust::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetPrintColorAdjust(state.ParentStyle()->PrintColorAdjust());
  state.Style()->SetPrintColorAdjustIsInherited(true);
}
void WebkitPrintColorAdjust::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetPrintColorAdjust(To<CSSIdentifierValue>(value).ConvertTo<blink::EPrintColorAdjust>());
  state.Style()->SetPrintColorAdjustIsInherited(false);
}

 // -webkit-rtl-ordering



const char* WebkitRtlOrdering::GetPropertyName() const {
  return "-webkit-rtl-ordering";
}

const WTF::AtomicString& WebkitRtlOrdering::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-rtl-ordering"));
  return name;
}

const char* WebkitRtlOrdering::GetJSPropertyName() const {
  return "webkitRtlOrdering";
}


void WebkitRtlOrdering::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetRtlOrdering(ComputedStyleInitialValues::InitialRtlOrdering());
  state.Style()->SetRtlOrderingIsInherited(false);
}
void WebkitRtlOrdering::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetRtlOrdering(state.ParentStyle()->RtlOrdering());
  state.Style()->SetRtlOrderingIsInherited(true);
}
void WebkitRtlOrdering::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetRtlOrdering(To<CSSIdentifierValue>(value).ConvertTo<blink::EOrder>());
  state.Style()->SetRtlOrderingIsInherited(false);
}

 // -webkit-ruby-position



const char* WebkitRubyPosition::GetPropertyName() const {
  return "-webkit-ruby-position";
}

const WTF::AtomicString& WebkitRubyPosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-ruby-position"));
  return name;
}

const char* WebkitRubyPosition::GetJSPropertyName() const {
  return "webkitRubyPosition";
}


void WebkitRubyPosition::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetRubyPosition(ComputedStyleInitialValues::InitialRubyPosition());
}
void WebkitRubyPosition::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetRubyPosition(state.ParentStyle()->GetRubyPosition());
}
void WebkitRubyPosition::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetRubyPosition(StyleBuilderConverter::ConvertRubyPosition(state, value));
}

 // -webkit-tap-highlight-color



const char* WebkitTapHighlightColor::GetPropertyName() const {
  return "-webkit-tap-highlight-color";
}

const WTF::AtomicString& WebkitTapHighlightColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-tap-highlight-color"));
  return name;
}

const char* WebkitTapHighlightColor::GetJSPropertyName() const {
  return "webkitTapHighlightColor";
}


void WebkitTapHighlightColor::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTapHighlightColor(ComputedStyleInitialValues::InitialTapHighlightColor());
}
void WebkitTapHighlightColor::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTapHighlightColor(state.ParentStyle()->TapHighlightColor());
}
void WebkitTapHighlightColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTapHighlightColor(StyleBuilderConverter::ConvertColor(state, value));
}

 // -webkit-text-combine



const char* WebkitTextCombine::GetPropertyName() const {
  return "-webkit-text-combine";
}

const WTF::AtomicString& WebkitTextCombine::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-combine"));
  return name;
}

const char* WebkitTextCombine::GetJSPropertyName() const {
  return "webkitTextCombine";
}


void WebkitTextCombine::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextCombine(ComputedStyleInitialValues::InitialTextCombine());
}
void WebkitTextCombine::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextCombine(state.ParentStyle()->TextCombine());
}
void WebkitTextCombine::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextCombine(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextCombine>());
}

 // -webkit-text-decorations-in-effect



const char* WebkitTextDecorationsInEffect::GetPropertyName() const {
  return "-webkit-text-decorations-in-effect";
}

const WTF::AtomicString& WebkitTextDecorationsInEffect::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-decorations-in-effect"));
  return name;
}

const char* WebkitTextDecorationsInEffect::GetJSPropertyName() const {
  return "webkitTextDecorationsInEffect";
}


void WebkitTextDecorationsInEffect::ApplyInitial(StyleResolverState& state) const {
  // Intentionally empty.
}
void WebkitTextDecorationsInEffect::ApplyInherit(StyleResolverState& state) const {
  // Intentionally empty.
}
void WebkitTextDecorationsInEffect::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  // Intentionally empty.
}

 // -webkit-text-emphasis-color



const char* WebkitTextEmphasisColor::GetPropertyName() const {
  return "-webkit-text-emphasis-color";
}

const WTF::AtomicString& WebkitTextEmphasisColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-emphasis-color"));
  return name;
}

const char* WebkitTextEmphasisColor::GetJSPropertyName() const {
  return "webkitTextEmphasisColor";
}
const CSSProperty* WebkitTextEmphasisColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedTextEmphasisColor();
}


void WebkitTextEmphasisColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetTextEmphasisColor(color);
}

void WebkitTextEmphasisColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextEmphasisColor();
  state.Style()->SetTextEmphasisColor(color);
}

void WebkitTextEmphasisColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextEmphasisColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // -webkit-text-emphasis-position



const char* WebkitTextEmphasisPosition::GetPropertyName() const {
  return "-webkit-text-emphasis-position";
}

const WTF::AtomicString& WebkitTextEmphasisPosition::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-emphasis-position"));
  return name;
}

const char* WebkitTextEmphasisPosition::GetJSPropertyName() const {
  return "webkitTextEmphasisPosition";
}


void WebkitTextEmphasisPosition::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextEmphasisPosition(ComputedStyleInitialValues::InitialTextEmphasisPosition());
}
void WebkitTextEmphasisPosition::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextEmphasisPosition(state.ParentStyle()->GetTextEmphasisPosition());
}
void WebkitTextEmphasisPosition::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextEmphasisPosition(StyleBuilderConverter::ConvertTextTextEmphasisPosition(state, value));
}

 // -webkit-text-emphasis-style



const char* WebkitTextEmphasisStyle::GetPropertyName() const {
  return "-webkit-text-emphasis-style";
}

const WTF::AtomicString& WebkitTextEmphasisStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-emphasis-style"));
  return name;
}

const char* WebkitTextEmphasisStyle::GetJSPropertyName() const {
  return "webkitTextEmphasisStyle";
}



 // -webkit-text-fill-color



const char* WebkitTextFillColor::GetPropertyName() const {
  return "-webkit-text-fill-color";
}

const WTF::AtomicString& WebkitTextFillColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-fill-color"));
  return name;
}

const char* WebkitTextFillColor::GetJSPropertyName() const {
  return "webkitTextFillColor";
}
const CSSProperty* WebkitTextFillColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedTextFillColor();
}


void WebkitTextFillColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetTextFillColor(color);
}

void WebkitTextFillColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextFillColor();
  state.Style()->SetTextFillColor(color);
}

void WebkitTextFillColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextFillColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // -webkit-text-security



const char* WebkitTextSecurity::GetPropertyName() const {
  return "-webkit-text-security";
}

const WTF::AtomicString& WebkitTextSecurity::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-security"));
  return name;
}

const char* WebkitTextSecurity::GetJSPropertyName() const {
  return "webkitTextSecurity";
}


void WebkitTextSecurity::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextSecurity(ComputedStyleInitialValues::InitialTextSecurity());
}
void WebkitTextSecurity::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextSecurity(state.ParentStyle()->TextSecurity());
}
void WebkitTextSecurity::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextSecurity(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextSecurity>());
}

 // -webkit-text-stroke-color



const char* WebkitTextStrokeColor::GetPropertyName() const {
  return "-webkit-text-stroke-color";
}

const WTF::AtomicString& WebkitTextStrokeColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-stroke-color"));
  return name;
}

const char* WebkitTextStrokeColor::GetJSPropertyName() const {
  return "webkitTextStrokeColor";
}
const CSSProperty* WebkitTextStrokeColor::GetVisitedProperty() const {
  return &GetCSSPropertyInternalVisitedTextStrokeColor();
}


void WebkitTextStrokeColor::ApplyInitial(StyleResolverState& state) const {
  auto color = StyleColor::CurrentColor();
  state.Style()->SetTextStrokeColor(color);
}

void WebkitTextStrokeColor::ApplyInherit(StyleResolverState& state) const {
  auto color = state.ParentStyle()->TextStrokeColor();
  state.Style()->SetTextStrokeColor(color);
}

void WebkitTextStrokeColor::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextStrokeColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

 // -webkit-text-stroke-width



const char* WebkitTextStrokeWidth::GetPropertyName() const {
  return "-webkit-text-stroke-width";
}

const WTF::AtomicString& WebkitTextStrokeWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-stroke-width"));
  return name;
}

const char* WebkitTextStrokeWidth::GetJSPropertyName() const {
  return "webkitTextStrokeWidth";
}


void WebkitTextStrokeWidth::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTextStrokeWidth(ComputedStyleInitialValues::InitialTextStrokeWidth());
}
void WebkitTextStrokeWidth::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTextStrokeWidth(state.ParentStyle()->TextStrokeWidth());
}
void WebkitTextStrokeWidth::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTextStrokeWidth(StyleBuilderConverter::ConvertTextStrokeWidth(state, value));
}

 // -webkit-transform-origin-x



const char* WebkitTransformOriginX::GetPropertyName() const {
  return "-webkit-transform-origin-x";
}

const WTF::AtomicString& WebkitTransformOriginX::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin-x"));
  return name;
}

const char* WebkitTransformOriginX::GetJSPropertyName() const {
  return "webkitTransformOriginX";
}


void WebkitTransformOriginX::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTransformOriginX(ComputedStyleInitialValues::InitialTransformOriginX());
}
void WebkitTransformOriginX::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTransformOriginX(state.ParentStyle()->TransformOriginX());
}
void WebkitTransformOriginX::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTransformOriginX(StyleBuilderConverter::ConvertLength(state, value));
}

 // -webkit-transform-origin-y



const char* WebkitTransformOriginY::GetPropertyName() const {
  return "-webkit-transform-origin-y";
}

const WTF::AtomicString& WebkitTransformOriginY::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin-y"));
  return name;
}

const char* WebkitTransformOriginY::GetJSPropertyName() const {
  return "webkitTransformOriginY";
}


void WebkitTransformOriginY::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTransformOriginY(ComputedStyleInitialValues::InitialTransformOriginY());
}
void WebkitTransformOriginY::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTransformOriginY(state.ParentStyle()->TransformOriginY());
}
void WebkitTransformOriginY::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTransformOriginY(StyleBuilderConverter::ConvertLength(state, value));
}

 // -webkit-transform-origin-z



const char* WebkitTransformOriginZ::GetPropertyName() const {
  return "-webkit-transform-origin-z";
}

const WTF::AtomicString& WebkitTransformOriginZ::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin-z"));
  return name;
}

const char* WebkitTransformOriginZ::GetJSPropertyName() const {
  return "webkitTransformOriginZ";
}


void WebkitTransformOriginZ::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetTransformOriginZ(ComputedStyleInitialValues::InitialTransformOriginZ());
}
void WebkitTransformOriginZ::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetTransformOriginZ(state.ParentStyle()->TransformOriginZ());
}
void WebkitTransformOriginZ::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetTransformOriginZ(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

 // -webkit-user-drag



const char* WebkitUserDrag::GetPropertyName() const {
  return "-webkit-user-drag";
}

const WTF::AtomicString& WebkitUserDrag::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-user-drag"));
  return name;
}

const char* WebkitUserDrag::GetJSPropertyName() const {
  return "webkitUserDrag";
}


void WebkitUserDrag::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetUserDrag(ComputedStyleInitialValues::InitialUserDrag());
}
void WebkitUserDrag::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetUserDrag(state.ParentStyle()->UserDrag());
}
void WebkitUserDrag::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetUserDrag(To<CSSIdentifierValue>(value).ConvertTo<blink::EUserDrag>());
}

 // -webkit-user-modify



const char* WebkitUserModify::GetPropertyName() const {
  return "-webkit-user-modify";
}

const WTF::AtomicString& WebkitUserModify::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-user-modify"));
  return name;
}

const char* WebkitUserModify::GetJSPropertyName() const {
  return "webkitUserModify";
}


void WebkitUserModify::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetUserModify(ComputedStyleInitialValues::InitialUserModify());
}
void WebkitUserModify::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetUserModify(state.ParentStyle()->UserModify());
}
void WebkitUserModify::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetUserModify(To<CSSIdentifierValue>(value).ConvertTo<blink::EUserModify>());
}

 // white-space



const char* WhiteSpace::GetPropertyName() const {
  return "white-space";
}

const WTF::AtomicString& WhiteSpace::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("white-space"));
  return name;
}

const char* WhiteSpace::GetJSPropertyName() const {
  return "whiteSpace";
}


void WhiteSpace::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetWhiteSpace(ComputedStyleInitialValues::InitialWhiteSpace());
  state.Style()->SetWhiteSpaceIsInherited(false);
}
void WhiteSpace::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetWhiteSpace(state.ParentStyle()->WhiteSpace());
  state.Style()->SetWhiteSpaceIsInherited(true);
}
void WhiteSpace::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetWhiteSpace(To<CSSIdentifierValue>(value).ConvertTo<blink::EWhiteSpace>());
  state.Style()->SetWhiteSpaceIsInherited(false);
}

 // widows



const char* Widows::GetPropertyName() const {
  return "widows";
}

const WTF::AtomicString& Widows::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("widows"));
  return name;
}

const char* Widows::GetJSPropertyName() const {
  return "widows";
}


void Widows::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetWidows(ComputedStyleInitialValues::InitialWidows());
}
void Widows::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetWidows(state.ParentStyle()->Widows());
}
void Widows::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetWidows(To<CSSPrimitiveValue>(value).ConvertTo<short>());
}

 // width



const char* Width::GetPropertyName() const {
  return "width";
}

const WTF::AtomicString& Width::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("width"));
  return name;
}

const char* Width::GetJSPropertyName() const {
  return "width";
}

bool Width::ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const {
  return a.Width() == b.Width();
}

void Width::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetWidth(ComputedStyleInitialValues::InitialWidth());
}
void Width::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetWidth(state.ParentStyle()->Width());
}
void Width::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetWidth(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

 // will-change



const char* WillChange::GetPropertyName() const {
  return "will-change";
}

const WTF::AtomicString& WillChange::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("will-change"));
  return name;
}

const char* WillChange::GetJSPropertyName() const {
  return "willChange";
}



 // word-break



const char* WordBreak::GetPropertyName() const {
  return "word-break";
}

const WTF::AtomicString& WordBreak::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("word-break"));
  return name;
}

const char* WordBreak::GetJSPropertyName() const {
  return "wordBreak";
}


void WordBreak::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetWordBreak(ComputedStyleInitialValues::InitialWordBreak());
}
void WordBreak::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetWordBreak(state.ParentStyle()->WordBreak());
}
void WordBreak::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetWordBreak(To<CSSIdentifierValue>(value).ConvertTo<blink::EWordBreak>());
}

 // word-spacing



const char* WordSpacing::GetPropertyName() const {
  return "word-spacing";
}

const WTF::AtomicString& WordSpacing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("word-spacing"));
  return name;
}

const char* WordSpacing::GetJSPropertyName() const {
  return "wordSpacing";
}


void WordSpacing::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetWordSpacing(ComputedStyleInitialValues::InitialWordSpacing());
}
void WordSpacing::ApplyInherit(StyleResolverState& state) const {
  state.Style()->SetWordSpacing(state.ParentStyle()->WordSpacing());
}
void WordSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->SetWordSpacing(StyleBuilderConverter::ConvertSpacing(state, value));
}

 // x



const char* X::GetPropertyName() const {
  return "x";
}

const WTF::AtomicString& X::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("x"));
  return name;
}

const char* X::GetJSPropertyName() const {
  return "x";
}


void X::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetX(SVGComputedStyle::InitialX());
}
void X::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetX(state.ParentStyle()->SvgStyle().X());
}
void X::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetX(StyleBuilderConverter::ConvertLength(state, value));
}

 // y



const char* Y::GetPropertyName() const {
  return "y";
}

const WTF::AtomicString& Y::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("y"));
  return name;
}

const char* Y::GetJSPropertyName() const {
  return "y";
}


void Y::ApplyInitial(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetY(SVGComputedStyle::InitialY());
}
void Y::ApplyInherit(StyleResolverState& state) const {
  state.Style()->AccessSVGStyle().SetY(state.ParentStyle()->SvgStyle().Y());
}
void Y::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  state.Style()->AccessSVGStyle().SetY(StyleBuilderConverter::ConvertLength(state, value));
}

 // z-index



const char* ZIndex::GetPropertyName() const {
  return "z-index";
}

const WTF::AtomicString& ZIndex::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("z-index"));
  return name;
}

const char* ZIndex::GetJSPropertyName() const {
  return "zIndex";
}


void ZIndex::ApplyInitial(StyleResolverState& state) const {
  state.Style()->SetHasAutoZIndex();
}
void ZIndex::ApplyInherit(StyleResolverState& state) const {
  if (state.ParentStyle()->HasAutoZIndex())
    state.Style()->SetHasAutoZIndex();
  else
    state.Style()->SetZIndex(state.ParentStyle()->ZIndex());
}
void ZIndex::ApplyValue(StyleResolverState& state, const CSSValue& value) const {
  auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
  if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
    state.Style()->SetHasAutoZIndex();
  else
    state.Style()->SetZIndex(To<CSSPrimitiveValue>(value).ConvertTo<int>());
}

 // -webkit-appearance



const char* WebkitAppearance::GetPropertyName() const {
  return "-webkit-appearance";
}

const WTF::AtomicString& WebkitAppearance::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-appearance"));
  return name;
}

const char* WebkitAppearance::GetJSPropertyName() const {
  return "webkitAppearance";
}
 // -webkit-border-end-color



const char* WebkitBorderEndColor::GetPropertyName() const {
  return "-webkit-border-end-color";
}

const WTF::AtomicString& WebkitBorderEndColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-end-color"));
  return name;
}

const char* WebkitBorderEndColor::GetJSPropertyName() const {
  return "webkitBorderEndColor";
}
 // -webkit-border-end-style



const char* WebkitBorderEndStyle::GetPropertyName() const {
  return "-webkit-border-end-style";
}

const WTF::AtomicString& WebkitBorderEndStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-end-style"));
  return name;
}

const char* WebkitBorderEndStyle::GetJSPropertyName() const {
  return "webkitBorderEndStyle";
}
 // -webkit-border-end-width



const char* WebkitBorderEndWidth::GetPropertyName() const {
  return "-webkit-border-end-width";
}

const WTF::AtomicString& WebkitBorderEndWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-end-width"));
  return name;
}

const char* WebkitBorderEndWidth::GetJSPropertyName() const {
  return "webkitBorderEndWidth";
}
 // -webkit-border-start-color



const char* WebkitBorderStartColor::GetPropertyName() const {
  return "-webkit-border-start-color";
}

const WTF::AtomicString& WebkitBorderStartColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-start-color"));
  return name;
}

const char* WebkitBorderStartColor::GetJSPropertyName() const {
  return "webkitBorderStartColor";
}
 // -webkit-border-start-style



const char* WebkitBorderStartStyle::GetPropertyName() const {
  return "-webkit-border-start-style";
}

const WTF::AtomicString& WebkitBorderStartStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-start-style"));
  return name;
}

const char* WebkitBorderStartStyle::GetJSPropertyName() const {
  return "webkitBorderStartStyle";
}
 // -webkit-border-start-width



const char* WebkitBorderStartWidth::GetPropertyName() const {
  return "-webkit-border-start-width";
}

const WTF::AtomicString& WebkitBorderStartWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-start-width"));
  return name;
}

const char* WebkitBorderStartWidth::GetJSPropertyName() const {
  return "webkitBorderStartWidth";
}
 // -webkit-border-before-color



const char* WebkitBorderBeforeColor::GetPropertyName() const {
  return "-webkit-border-before-color";
}

const WTF::AtomicString& WebkitBorderBeforeColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-before-color"));
  return name;
}

const char* WebkitBorderBeforeColor::GetJSPropertyName() const {
  return "webkitBorderBeforeColor";
}
 // -webkit-border-before-style



const char* WebkitBorderBeforeStyle::GetPropertyName() const {
  return "-webkit-border-before-style";
}

const WTF::AtomicString& WebkitBorderBeforeStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-before-style"));
  return name;
}

const char* WebkitBorderBeforeStyle::GetJSPropertyName() const {
  return "webkitBorderBeforeStyle";
}
 // -webkit-border-before-width



const char* WebkitBorderBeforeWidth::GetPropertyName() const {
  return "-webkit-border-before-width";
}

const WTF::AtomicString& WebkitBorderBeforeWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-before-width"));
  return name;
}

const char* WebkitBorderBeforeWidth::GetJSPropertyName() const {
  return "webkitBorderBeforeWidth";
}
 // -webkit-border-after-color



const char* WebkitBorderAfterColor::GetPropertyName() const {
  return "-webkit-border-after-color";
}

const WTF::AtomicString& WebkitBorderAfterColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-after-color"));
  return name;
}

const char* WebkitBorderAfterColor::GetJSPropertyName() const {
  return "webkitBorderAfterColor";
}
 // -webkit-border-after-style



const char* WebkitBorderAfterStyle::GetPropertyName() const {
  return "-webkit-border-after-style";
}

const WTF::AtomicString& WebkitBorderAfterStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-after-style"));
  return name;
}

const char* WebkitBorderAfterStyle::GetJSPropertyName() const {
  return "webkitBorderAfterStyle";
}
 // -webkit-border-after-width



const char* WebkitBorderAfterWidth::GetPropertyName() const {
  return "-webkit-border-after-width";
}

const WTF::AtomicString& WebkitBorderAfterWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-after-width"));
  return name;
}

const char* WebkitBorderAfterWidth::GetJSPropertyName() const {
  return "webkitBorderAfterWidth";
}
 // -webkit-margin-end



const char* WebkitMarginEnd::GetPropertyName() const {
  return "-webkit-margin-end";
}

const WTF::AtomicString& WebkitMarginEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-end"));
  return name;
}

const char* WebkitMarginEnd::GetJSPropertyName() const {
  return "webkitMarginEnd";
}
 // -webkit-margin-start



const char* WebkitMarginStart::GetPropertyName() const {
  return "-webkit-margin-start";
}

const WTF::AtomicString& WebkitMarginStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-start"));
  return name;
}

const char* WebkitMarginStart::GetJSPropertyName() const {
  return "webkitMarginStart";
}
 // -webkit-margin-before



const char* WebkitMarginBefore::GetPropertyName() const {
  return "-webkit-margin-before";
}

const WTF::AtomicString& WebkitMarginBefore::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-before"));
  return name;
}

const char* WebkitMarginBefore::GetJSPropertyName() const {
  return "webkitMarginBefore";
}
 // -webkit-margin-after



const char* WebkitMarginAfter::GetPropertyName() const {
  return "-webkit-margin-after";
}

const WTF::AtomicString& WebkitMarginAfter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-after"));
  return name;
}

const char* WebkitMarginAfter::GetJSPropertyName() const {
  return "webkitMarginAfter";
}
 // -webkit-padding-end



const char* WebkitPaddingEnd::GetPropertyName() const {
  return "-webkit-padding-end";
}

const WTF::AtomicString& WebkitPaddingEnd::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-end"));
  return name;
}

const char* WebkitPaddingEnd::GetJSPropertyName() const {
  return "webkitPaddingEnd";
}
 // -webkit-padding-start



const char* WebkitPaddingStart::GetPropertyName() const {
  return "-webkit-padding-start";
}

const WTF::AtomicString& WebkitPaddingStart::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-start"));
  return name;
}

const char* WebkitPaddingStart::GetJSPropertyName() const {
  return "webkitPaddingStart";
}
 // -webkit-padding-before



const char* WebkitPaddingBefore::GetPropertyName() const {
  return "-webkit-padding-before";
}

const WTF::AtomicString& WebkitPaddingBefore::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-before"));
  return name;
}

const char* WebkitPaddingBefore::GetJSPropertyName() const {
  return "webkitPaddingBefore";
}
 // -webkit-padding-after



const char* WebkitPaddingAfter::GetPropertyName() const {
  return "-webkit-padding-after";
}

const WTF::AtomicString& WebkitPaddingAfter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-after"));
  return name;
}

const char* WebkitPaddingAfter::GetJSPropertyName() const {
  return "webkitPaddingAfter";
}
 // -webkit-logical-width



const char* WebkitLogicalWidth::GetPropertyName() const {
  return "-webkit-logical-width";
}

const WTF::AtomicString& WebkitLogicalWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-logical-width"));
  return name;
}

const char* WebkitLogicalWidth::GetJSPropertyName() const {
  return "webkitLogicalWidth";
}
 // -webkit-logical-height



const char* WebkitLogicalHeight::GetPropertyName() const {
  return "-webkit-logical-height";
}

const WTF::AtomicString& WebkitLogicalHeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-logical-height"));
  return name;
}

const char* WebkitLogicalHeight::GetJSPropertyName() const {
  return "webkitLogicalHeight";
}
 // -webkit-min-logical-width



const char* WebkitMinLogicalWidth::GetPropertyName() const {
  return "-webkit-min-logical-width";
}

const WTF::AtomicString& WebkitMinLogicalWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-min-logical-width"));
  return name;
}

const char* WebkitMinLogicalWidth::GetJSPropertyName() const {
  return "webkitMinLogicalWidth";
}
 // -webkit-min-logical-height



const char* WebkitMinLogicalHeight::GetPropertyName() const {
  return "-webkit-min-logical-height";
}

const WTF::AtomicString& WebkitMinLogicalHeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-min-logical-height"));
  return name;
}

const char* WebkitMinLogicalHeight::GetJSPropertyName() const {
  return "webkitMinLogicalHeight";
}
 // -webkit-max-logical-width



const char* WebkitMaxLogicalWidth::GetPropertyName() const {
  return "-webkit-max-logical-width";
}

const WTF::AtomicString& WebkitMaxLogicalWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-max-logical-width"));
  return name;
}

const char* WebkitMaxLogicalWidth::GetJSPropertyName() const {
  return "webkitMaxLogicalWidth";
}
 // -webkit-max-logical-height



const char* WebkitMaxLogicalHeight::GetPropertyName() const {
  return "-webkit-max-logical-height";
}

const WTF::AtomicString& WebkitMaxLogicalHeight::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-max-logical-height"));
  return name;
}

const char* WebkitMaxLogicalHeight::GetJSPropertyName() const {
  return "webkitMaxLogicalHeight";
}
 // -epub-caption-side



const char* EpubCaptionSide::GetPropertyName() const {
  return "-epub-caption-side";
}

const WTF::AtomicString& EpubCaptionSide::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-caption-side"));
  return name;
}

const char* EpubCaptionSide::GetJSPropertyName() const {
  return "epubCaptionSide";
}
 // -epub-text-combine



const char* EpubTextCombine::GetPropertyName() const {
  return "-epub-text-combine";
}

const WTF::AtomicString& EpubTextCombine::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-combine"));
  return name;
}

const char* EpubTextCombine::GetJSPropertyName() const {
  return "epubTextCombine";
}
 // -epub-text-emphasis-color



const char* EpubTextEmphasisColor::GetPropertyName() const {
  return "-epub-text-emphasis-color";
}

const WTF::AtomicString& EpubTextEmphasisColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-emphasis-color"));
  return name;
}

const char* EpubTextEmphasisColor::GetJSPropertyName() const {
  return "epubTextEmphasisColor";
}
 // -epub-text-emphasis-style



const char* EpubTextEmphasisStyle::GetPropertyName() const {
  return "-epub-text-emphasis-style";
}

const WTF::AtomicString& EpubTextEmphasisStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-emphasis-style"));
  return name;
}

const char* EpubTextEmphasisStyle::GetJSPropertyName() const {
  return "epubTextEmphasisStyle";
}
 // -epub-text-orientation



const char* EpubTextOrientation::GetPropertyName() const {
  return "-epub-text-orientation";
}

const WTF::AtomicString& EpubTextOrientation::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-orientation"));
  return name;
}

const char* EpubTextOrientation::GetJSPropertyName() const {
  return "epubTextOrientation";
}
 // -epub-text-transform



const char* EpubTextTransform::GetPropertyName() const {
  return "-epub-text-transform";
}

const WTF::AtomicString& EpubTextTransform::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-transform"));
  return name;
}

const char* EpubTextTransform::GetJSPropertyName() const {
  return "epubTextTransform";
}
 // -epub-word-break



const char* EpubWordBreak::GetPropertyName() const {
  return "-epub-word-break";
}

const WTF::AtomicString& EpubWordBreak::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-word-break"));
  return name;
}

const char* EpubWordBreak::GetJSPropertyName() const {
  return "epubWordBreak";
}
 // -epub-writing-mode



const char* EpubWritingMode::GetPropertyName() const {
  return "-epub-writing-mode";
}

const WTF::AtomicString& EpubWritingMode::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-writing-mode"));
  return name;
}

const char* EpubWritingMode::GetJSPropertyName() const {
  return "epubWritingMode";
}
 // -webkit-align-content



const char* WebkitAlignContent::GetPropertyName() const {
  return "-webkit-align-content";
}

const WTF::AtomicString& WebkitAlignContent::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-align-content"));
  return name;
}

const char* WebkitAlignContent::GetJSPropertyName() const {
  return "webkitAlignContent";
}
 // -webkit-align-items



const char* WebkitAlignItems::GetPropertyName() const {
  return "-webkit-align-items";
}

const WTF::AtomicString& WebkitAlignItems::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-align-items"));
  return name;
}

const char* WebkitAlignItems::GetJSPropertyName() const {
  return "webkitAlignItems";
}
 // -webkit-align-self



const char* WebkitAlignSelf::GetPropertyName() const {
  return "-webkit-align-self";
}

const WTF::AtomicString& WebkitAlignSelf::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-align-self"));
  return name;
}

const char* WebkitAlignSelf::GetJSPropertyName() const {
  return "webkitAlignSelf";
}
 // -webkit-animation-delay



const char* WebkitAnimationDelay::GetPropertyName() const {
  return "-webkit-animation-delay";
}

const WTF::AtomicString& WebkitAnimationDelay::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-delay"));
  return name;
}

const char* WebkitAnimationDelay::GetJSPropertyName() const {
  return "webkitAnimationDelay";
}
 // -webkit-animation-direction



const char* WebkitAnimationDirection::GetPropertyName() const {
  return "-webkit-animation-direction";
}

const WTF::AtomicString& WebkitAnimationDirection::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-direction"));
  return name;
}

const char* WebkitAnimationDirection::GetJSPropertyName() const {
  return "webkitAnimationDirection";
}
 // -webkit-animation-duration



const char* WebkitAnimationDuration::GetPropertyName() const {
  return "-webkit-animation-duration";
}

const WTF::AtomicString& WebkitAnimationDuration::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-duration"));
  return name;
}

const char* WebkitAnimationDuration::GetJSPropertyName() const {
  return "webkitAnimationDuration";
}
 // -webkit-animation-fill-mode



const char* WebkitAnimationFillMode::GetPropertyName() const {
  return "-webkit-animation-fill-mode";
}

const WTF::AtomicString& WebkitAnimationFillMode::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-fill-mode"));
  return name;
}

const char* WebkitAnimationFillMode::GetJSPropertyName() const {
  return "webkitAnimationFillMode";
}
 // -webkit-animation-iteration-count



const char* WebkitAnimationIterationCount::GetPropertyName() const {
  return "-webkit-animation-iteration-count";
}

const WTF::AtomicString& WebkitAnimationIterationCount::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-iteration-count"));
  return name;
}

const char* WebkitAnimationIterationCount::GetJSPropertyName() const {
  return "webkitAnimationIterationCount";
}
 // -webkit-animation-name



const char* WebkitAnimationName::GetPropertyName() const {
  return "-webkit-animation-name";
}

const WTF::AtomicString& WebkitAnimationName::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-name"));
  return name;
}

const char* WebkitAnimationName::GetJSPropertyName() const {
  return "webkitAnimationName";
}
 // -webkit-animation-play-state



const char* WebkitAnimationPlayState::GetPropertyName() const {
  return "-webkit-animation-play-state";
}

const WTF::AtomicString& WebkitAnimationPlayState::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-play-state"));
  return name;
}

const char* WebkitAnimationPlayState::GetJSPropertyName() const {
  return "webkitAnimationPlayState";
}
 // -webkit-animation-timing-function



const char* WebkitAnimationTimingFunction::GetPropertyName() const {
  return "-webkit-animation-timing-function";
}

const WTF::AtomicString& WebkitAnimationTimingFunction::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-timing-function"));
  return name;
}

const char* WebkitAnimationTimingFunction::GetJSPropertyName() const {
  return "webkitAnimationTimingFunction";
}
 // -webkit-backface-visibility



const char* WebkitBackfaceVisibility::GetPropertyName() const {
  return "-webkit-backface-visibility";
}

const WTF::AtomicString& WebkitBackfaceVisibility::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-backface-visibility"));
  return name;
}

const char* WebkitBackfaceVisibility::GetJSPropertyName() const {
  return "webkitBackfaceVisibility";
}
 // -webkit-background-clip



const char* WebkitBackgroundClip::GetPropertyName() const {
  return "-webkit-background-clip";
}

const WTF::AtomicString& WebkitBackgroundClip::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-background-clip"));
  return name;
}

const char* WebkitBackgroundClip::GetJSPropertyName() const {
  return "webkitBackgroundClip";
}
 // -webkit-background-origin



const char* WebkitBackgroundOrigin::GetPropertyName() const {
  return "-webkit-background-origin";
}

const WTF::AtomicString& WebkitBackgroundOrigin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-background-origin"));
  return name;
}

const char* WebkitBackgroundOrigin::GetJSPropertyName() const {
  return "webkitBackgroundOrigin";
}
 // -webkit-background-size



const char* WebkitBackgroundSize::GetPropertyName() const {
  return "-webkit-background-size";
}

const WTF::AtomicString& WebkitBackgroundSize::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-background-size"));
  return name;
}

const char* WebkitBackgroundSize::GetJSPropertyName() const {
  return "webkitBackgroundSize";
}
 // -webkit-border-bottom-left-radius



const char* WebkitBorderBottomLeftRadius::GetPropertyName() const {
  return "-webkit-border-bottom-left-radius";
}

const WTF::AtomicString& WebkitBorderBottomLeftRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-bottom-left-radius"));
  return name;
}

const char* WebkitBorderBottomLeftRadius::GetJSPropertyName() const {
  return "webkitBorderBottomLeftRadius";
}
 // -webkit-border-bottom-right-radius



const char* WebkitBorderBottomRightRadius::GetPropertyName() const {
  return "-webkit-border-bottom-right-radius";
}

const WTF::AtomicString& WebkitBorderBottomRightRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-bottom-right-radius"));
  return name;
}

const char* WebkitBorderBottomRightRadius::GetJSPropertyName() const {
  return "webkitBorderBottomRightRadius";
}
 // -webkit-border-top-left-radius



const char* WebkitBorderTopLeftRadius::GetPropertyName() const {
  return "-webkit-border-top-left-radius";
}

const WTF::AtomicString& WebkitBorderTopLeftRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-top-left-radius"));
  return name;
}

const char* WebkitBorderTopLeftRadius::GetJSPropertyName() const {
  return "webkitBorderTopLeftRadius";
}
 // -webkit-border-top-right-radius



const char* WebkitBorderTopRightRadius::GetPropertyName() const {
  return "-webkit-border-top-right-radius";
}

const WTF::AtomicString& WebkitBorderTopRightRadius::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-top-right-radius"));
  return name;
}

const char* WebkitBorderTopRightRadius::GetJSPropertyName() const {
  return "webkitBorderTopRightRadius";
}
 // -webkit-box-shadow



const char* WebkitBoxShadow::GetPropertyName() const {
  return "-webkit-box-shadow";
}

const WTF::AtomicString& WebkitBoxShadow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-shadow"));
  return name;
}

const char* WebkitBoxShadow::GetJSPropertyName() const {
  return "webkitBoxShadow";
}
 // -webkit-box-sizing



const char* WebkitBoxSizing::GetPropertyName() const {
  return "-webkit-box-sizing";
}

const WTF::AtomicString& WebkitBoxSizing::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-sizing"));
  return name;
}

const char* WebkitBoxSizing::GetJSPropertyName() const {
  return "webkitBoxSizing";
}
 // -webkit-clip-path



const char* WebkitClipPath::GetPropertyName() const {
  return "-webkit-clip-path";
}

const WTF::AtomicString& WebkitClipPath::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-clip-path"));
  return name;
}

const char* WebkitClipPath::GetJSPropertyName() const {
  return "webkitClipPath";
}
 // -webkit-column-count



const char* WebkitColumnCount::GetPropertyName() const {
  return "-webkit-column-count";
}

const WTF::AtomicString& WebkitColumnCount::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-count"));
  return name;
}

const char* WebkitColumnCount::GetJSPropertyName() const {
  return "webkitColumnCount";
}
 // -webkit-column-gap



const char* WebkitColumnGap::GetPropertyName() const {
  return "-webkit-column-gap";
}

const WTF::AtomicString& WebkitColumnGap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-gap"));
  return name;
}

const char* WebkitColumnGap::GetJSPropertyName() const {
  return "webkitColumnGap";
}
 // -webkit-column-rule-color



const char* WebkitColumnRuleColor::GetPropertyName() const {
  return "-webkit-column-rule-color";
}

const WTF::AtomicString& WebkitColumnRuleColor::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-rule-color"));
  return name;
}

const char* WebkitColumnRuleColor::GetJSPropertyName() const {
  return "webkitColumnRuleColor";
}
 // -webkit-column-rule-style



const char* WebkitColumnRuleStyle::GetPropertyName() const {
  return "-webkit-column-rule-style";
}

const WTF::AtomicString& WebkitColumnRuleStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-rule-style"));
  return name;
}

const char* WebkitColumnRuleStyle::GetJSPropertyName() const {
  return "webkitColumnRuleStyle";
}
 // -webkit-column-rule-width



const char* WebkitColumnRuleWidth::GetPropertyName() const {
  return "-webkit-column-rule-width";
}

const WTF::AtomicString& WebkitColumnRuleWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-rule-width"));
  return name;
}

const char* WebkitColumnRuleWidth::GetJSPropertyName() const {
  return "webkitColumnRuleWidth";
}
 // -webkit-column-span



const char* WebkitColumnSpan::GetPropertyName() const {
  return "-webkit-column-span";
}

const WTF::AtomicString& WebkitColumnSpan::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-span"));
  return name;
}

const char* WebkitColumnSpan::GetJSPropertyName() const {
  return "webkitColumnSpan";
}
 // -webkit-column-width



const char* WebkitColumnWidth::GetPropertyName() const {
  return "-webkit-column-width";
}

const WTF::AtomicString& WebkitColumnWidth::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-width"));
  return name;
}

const char* WebkitColumnWidth::GetJSPropertyName() const {
  return "webkitColumnWidth";
}
 // -webkit-filter



const char* WebkitFilter::GetPropertyName() const {
  return "-webkit-filter";
}

const WTF::AtomicString& WebkitFilter::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-filter"));
  return name;
}

const char* WebkitFilter::GetJSPropertyName() const {
  return "webkitFilter";
}
 // -webkit-flex-basis



const char* WebkitFlexBasis::GetPropertyName() const {
  return "-webkit-flex-basis";
}

const WTF::AtomicString& WebkitFlexBasis::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-basis"));
  return name;
}

const char* WebkitFlexBasis::GetJSPropertyName() const {
  return "webkitFlexBasis";
}
 // -webkit-flex-direction



const char* WebkitFlexDirection::GetPropertyName() const {
  return "-webkit-flex-direction";
}

const WTF::AtomicString& WebkitFlexDirection::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-direction"));
  return name;
}

const char* WebkitFlexDirection::GetJSPropertyName() const {
  return "webkitFlexDirection";
}
 // -webkit-flex-grow



const char* WebkitFlexGrow::GetPropertyName() const {
  return "-webkit-flex-grow";
}

const WTF::AtomicString& WebkitFlexGrow::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-grow"));
  return name;
}

const char* WebkitFlexGrow::GetJSPropertyName() const {
  return "webkitFlexGrow";
}
 // -webkit-flex-shrink



const char* WebkitFlexShrink::GetPropertyName() const {
  return "-webkit-flex-shrink";
}

const WTF::AtomicString& WebkitFlexShrink::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-shrink"));
  return name;
}

const char* WebkitFlexShrink::GetJSPropertyName() const {
  return "webkitFlexShrink";
}
 // -webkit-flex-wrap



const char* WebkitFlexWrap::GetPropertyName() const {
  return "-webkit-flex-wrap";
}

const WTF::AtomicString& WebkitFlexWrap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-wrap"));
  return name;
}

const char* WebkitFlexWrap::GetJSPropertyName() const {
  return "webkitFlexWrap";
}
 // -webkit-font-feature-settings



const char* WebkitFontFeatureSettings::GetPropertyName() const {
  return "-webkit-font-feature-settings";
}

const WTF::AtomicString& WebkitFontFeatureSettings::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-font-feature-settings"));
  return name;
}

const char* WebkitFontFeatureSettings::GetJSPropertyName() const {
  return "webkitFontFeatureSettings";
}
 // -webkit-justify-content



const char* WebkitJustifyContent::GetPropertyName() const {
  return "-webkit-justify-content";
}

const WTF::AtomicString& WebkitJustifyContent::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-justify-content"));
  return name;
}

const char* WebkitJustifyContent::GetJSPropertyName() const {
  return "webkitJustifyContent";
}
 // -webkit-opacity



const char* WebkitOpacity::GetPropertyName() const {
  return "-webkit-opacity";
}

const WTF::AtomicString& WebkitOpacity::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-opacity"));
  return name;
}

const char* WebkitOpacity::GetJSPropertyName() const {
  return "webkitOpacity";
}
 // -webkit-order



const char* WebkitOrder::GetPropertyName() const {
  return "-webkit-order";
}

const WTF::AtomicString& WebkitOrder::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-order"));
  return name;
}

const char* WebkitOrder::GetJSPropertyName() const {
  return "webkitOrder";
}
 // -webkit-perspective



const char* WebkitPerspective::GetPropertyName() const {
  return "-webkit-perspective";
}

const WTF::AtomicString& WebkitPerspective::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective"));
  return name;
}

const char* WebkitPerspective::GetJSPropertyName() const {
  return "webkitPerspective";
}
 // -webkit-perspective-origin



const char* WebkitPerspectiveOrigin::GetPropertyName() const {
  return "-webkit-perspective-origin";
}

const WTF::AtomicString& WebkitPerspectiveOrigin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective-origin"));
  return name;
}

const char* WebkitPerspectiveOrigin::GetJSPropertyName() const {
  return "webkitPerspectiveOrigin";
}
 // -webkit-shape-image-threshold



const char* WebkitShapeImageThreshold::GetPropertyName() const {
  return "-webkit-shape-image-threshold";
}

const WTF::AtomicString& WebkitShapeImageThreshold::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-shape-image-threshold"));
  return name;
}

const char* WebkitShapeImageThreshold::GetJSPropertyName() const {
  return "webkitShapeImageThreshold";
}
 // -webkit-shape-margin



const char* WebkitShapeMargin::GetPropertyName() const {
  return "-webkit-shape-margin";
}

const WTF::AtomicString& WebkitShapeMargin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-shape-margin"));
  return name;
}

const char* WebkitShapeMargin::GetJSPropertyName() const {
  return "webkitShapeMargin";
}
 // -webkit-shape-outside



const char* WebkitShapeOutside::GetPropertyName() const {
  return "-webkit-shape-outside";
}

const WTF::AtomicString& WebkitShapeOutside::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-shape-outside"));
  return name;
}

const char* WebkitShapeOutside::GetJSPropertyName() const {
  return "webkitShapeOutside";
}
 // -webkit-text-size-adjust



const char* WebkitTextSizeAdjust::GetPropertyName() const {
  return "-webkit-text-size-adjust";
}

const WTF::AtomicString& WebkitTextSizeAdjust::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-size-adjust"));
  return name;
}

const char* WebkitTextSizeAdjust::GetJSPropertyName() const {
  return "webkitTextSizeAdjust";
}
 // -webkit-transform



const char* WebkitTransform::GetPropertyName() const {
  return "-webkit-transform";
}

const WTF::AtomicString& WebkitTransform::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform"));
  return name;
}

const char* WebkitTransform::GetJSPropertyName() const {
  return "webkitTransform";
}
 // -webkit-transform-origin



const char* WebkitTransformOrigin::GetPropertyName() const {
  return "-webkit-transform-origin";
}

const WTF::AtomicString& WebkitTransformOrigin::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin"));
  return name;
}

const char* WebkitTransformOrigin::GetJSPropertyName() const {
  return "webkitTransformOrigin";
}
 // -webkit-transform-style



const char* WebkitTransformStyle::GetPropertyName() const {
  return "-webkit-transform-style";
}

const WTF::AtomicString& WebkitTransformStyle::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-style"));
  return name;
}

const char* WebkitTransformStyle::GetJSPropertyName() const {
  return "webkitTransformStyle";
}
 // -webkit-transition-delay



const char* WebkitTransitionDelay::GetPropertyName() const {
  return "-webkit-transition-delay";
}

const WTF::AtomicString& WebkitTransitionDelay::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-delay"));
  return name;
}

const char* WebkitTransitionDelay::GetJSPropertyName() const {
  return "webkitTransitionDelay";
}
 // -webkit-transition-duration



const char* WebkitTransitionDuration::GetPropertyName() const {
  return "-webkit-transition-duration";
}

const WTF::AtomicString& WebkitTransitionDuration::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-duration"));
  return name;
}

const char* WebkitTransitionDuration::GetJSPropertyName() const {
  return "webkitTransitionDuration";
}
 // -webkit-transition-property



const char* WebkitTransitionProperty::GetPropertyName() const {
  return "-webkit-transition-property";
}

const WTF::AtomicString& WebkitTransitionProperty::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-property"));
  return name;
}

const char* WebkitTransitionProperty::GetJSPropertyName() const {
  return "webkitTransitionProperty";
}
 // -webkit-transition-timing-function



const char* WebkitTransitionTimingFunction::GetPropertyName() const {
  return "-webkit-transition-timing-function";
}

const WTF::AtomicString& WebkitTransitionTimingFunction::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-timing-function"));
  return name;
}

const char* WebkitTransitionTimingFunction::GetJSPropertyName() const {
  return "webkitTransitionTimingFunction";
}
 // -webkit-user-select



const char* WebkitUserSelect::GetPropertyName() const {
  return "-webkit-user-select";
}

const WTF::AtomicString& WebkitUserSelect::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-user-select"));
  return name;
}

const char* WebkitUserSelect::GetJSPropertyName() const {
  return "webkitUserSelect";
}
 // word-wrap



const char* WordWrap::GetPropertyName() const {
  return "word-wrap";
}

const WTF::AtomicString& WordWrap::GetPropertyNameAtomicString() const {
  DEFINE_STATIC_LOCAL(const AtomicString, name, ("word-wrap"));
  return name;
}

const char* WordWrap::GetJSPropertyName() const {
  return "wordWrap";
}
  
}  // namespace css_longhand
}  // namespace blink
